// src/f3staging/f3blk_00920000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00935d10 (community match, verified in this file)
struct DataSpan { const void* data; int length; };
class SpanSource { public: DataSpan* FUN_0093d650(); };
struct ByteBuffer { char* data; int size; unsigned int capacityAndFlags; };
class OffsetList { public: int* FUN_0093d6b0(int value); };
void __cdecl FUN_00901e90(ByteBuffer* buffer, int capacity, int stride);
void __cdecl FUN_009234e0(void* destination, const void* source, int bytes);

int FUN_00935d10(SpanSource* source, ByteBuffer* buffer, int offset, OffsetList* offsets)
{
    DataSpan* span = source->FUN_0093d650();
    int required = buffer->size;
    int length = span->length;
    int aligned = (length + 3) & ~3;
    required += aligned;
    int capacity = buffer->capacityAndFlags & 0x3fffffff;
    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        FUN_00901e90(buffer, newCapacity, 1);
    }
    buffer->size = required;
    FUN_009234e0(buffer->data + offset, span->data, length);
    *offsets->FUN_0093d6b0(0) = offset;
    return aligned;
}

// @f3 0x009342e0 (community match, verified in this file)
struct FieldElemM {
    int unk00;
    int count04;
};

struct FieldRefM {
    void* unk00;
    int unk04;
    FieldRefM(void* obj, const char* name);
    FieldElemM* ElemAt(int index);
    int& IntAt(int index);
};

void FUN_009342e0(void* wordsOwner, void* flagsOwner)
{
    FieldRefM words(wordsOwner, "words");
    FieldRefM flags(flagsOwner, "numBitsAndFlags");
    int bits = words.ElemAt(0)->count04 << 5;
    flags.IntAt(0) = bits;
}

// @f3 0x00931940 (community match, verified in this file)
class StatsCollector1940 {
public:
    virtual ~StatsCollector1940();
    virtual void BeginObject(const char* name, int statClass, const void* object);
    virtual void AddChunk(const char* name, int statClass, const void* data, int usedSize, int allocatedSize);
    virtual void AddChildObject(const char* name, int statClass, const void* object);
};

struct AabbBlock1940 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
};

struct WorldObject1940 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* shape;
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
    unsigned short numChildShapeAabbs;
    unsigned short unk52;
    AabbBlock1940* childShapeAabbs;
    int unk58;
    void* collAgtData;
    int collAgtSize;
    int collAgtCapacityAndFlags;
    int unk68; int unk6C; int unk70;
    void* propData;
    int propSize;
    int propCapacityAndFlags;
    void hkpWorldObject_calcContentStatistics(StatsCollector1940* collector);
};

// pdb: hkpWorldObject::calcContentStatistics | hkpWorldObject.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void WorldObject1940::hkpWorldObject_calcContentStatistics(StatsCollector1940* collector)
{
    collector->AddChildObject("Shape", 1, shape);
    if ((collAgtCapacityAndFlags & 0x80000000) == 0)
        collector->AddChunk("CollAgtPtr", 8, collAgtData, collAgtSize * 8, (collAgtCapacityAndFlags & 0x3fffffff) * 8);
    if ((propCapacityAndFlags & 0x80000000) == 0)
        collector->AddChunk("Properties", 4, propData, propSize * 16, (propCapacityAndFlags & 0x3fffffff) * 16);
    if (childShapeAabbs)
        collector->AddChunk("ChildShapeAabbs", 8, childShapeAabbs, numChildShapeAabbs * sizeof(AabbBlock1940), 0);
}

// @f3 0x00931850 (community match, verified in this file)
namespace f3m_00931850 {
struct FUN_00931850_Pair {
    int m_a;
    int m_b;
};
struct FUN_00931850_Entry {
    int m_key;
    int m_unk04;
    FUN_00931850_Pair m_value;
};
struct FUN_00931850_Obj {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70;
    FUN_00931850_Entry* m_entries;
    int m_iNumberOfEntries;
    void FUN_00931850(int iKey, FUN_00931850_Pair kValue);
};
// pdb: hkpWorldObject::editProperty | hkpWorldObject.obj | tesv_win, objrun_open, low
void FUN_00931850_Obj::FUN_00931850(int iKey, FUN_00931850_Pair kValue)
{
    for (int i = 0; i < m_iNumberOfEntries; i++)
    {
        if (m_entries[i].m_key == iKey)
        {
            m_entries[i].m_value = kValue;
            return;
        }
    }
}
}   // namespace f3m_00931850

// @f3 0x0092be50 (community match, verified in this file)
struct AllocationHeap_0092be50 {
    void* FUN_0086b930(unsigned int bytes);
};
extern AllocationHeap_0092be50 DAT_01090a78;

class NiCloningProcess;

// NiTimeController: constructor FUN_00837e10, CopyMembers FUN_00837bc0
class FUN_00837e10 {
public:
    FUN_00837e10();
    virtual ~FUN_00837e10();
    void FUN_00837bc0(FUN_00837e10* dest, NiCloningProcess& process);
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
};

struct __declspec(align(16)) ForceVector_0092be50 {
    float x, y, z, w;
    ForceVector_0092be50& operator=(const ForceVector_0092be50& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
        return *this;
    }
};
extern ForceVector_0092be50 DAT_01092a50;

class bhkForceController : public FUN_00837e10 {
public:
    bhkForceController()
    {
        m_force = DAT_01092a50;
        m_strength = 0.0f;
    }
    virtual void VFunc04();

    static void* operator new(size_t bytes)
    {
        unsigned char* p = (unsigned char*)DAT_01090a78.FUN_0086b930(bytes + 0x10);
        unsigned char offset = 0x10 - ((unsigned char)(unsigned int)p & 0xf);
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void* p);

    FUN_00837e10* FUN_0092be50(NiCloningProcess& process);
    void CopyMembers(bhkForceController* dest, NiCloningProcess& process)
    {
        FUN_00837bc0(dest, process);
        dest->m_force.x = m_force.x;
        dest->m_force.y = m_force.y;
        dest->m_force.z = m_force.z;
        dest->m_force.w = m_force.w;
        dest->m_strength = m_strength;
    }

    ForceVector_0092be50 m_force;
    float m_strength;
};

// pdb: bhkForceController::CreateClone | bhkForceController.obj | fnv360_0822_retail, objrun, medium
// pdb params: kCloning
FUN_00837e10* bhkForceController::FUN_0092be50(NiCloningProcess& process)
{
    bhkForceController* clone = new bhkForceController;
    CopyMembers(clone, process);
    return clone;
}

// @f3 0x00926b70 (community match, verified in this file)
namespace f3m_00926b70 {

namespace f3m_00926b70 {
struct Obj6b70 {
    int unk00;
    unsigned short refCount;
    unsigned short unk06;
    void AddRef() { if (refCount != 0) unk06++; }
};
struct Entry6b70 {
    Obj6b70* object;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
};
struct Owner6b70 {
    int unk00;
    int unk04;
    int ctx;
    int unk0c[35];
    Entry6b70* entries;
    unsigned short entryCount;
    unsigned short unk9e;
    Obj6b70** ptrs;
    int ptrCount;
};
struct PtrArray6b70 {
    Obj6b70** data;
    int count;
    unsigned int capacityAndFlags;
};
}
using namespace f3m_00926b70;
extern "C" void __cdecl FUN_009264b0(int ctx, Obj6b70* obj, int zero);
extern "C" void __cdecl FUN_00901f10(PtrArray6b70* arr, int stride);

// pdb: hkpWorldOperationUtil::removeAttachedConstraints | hkpWorldOperationUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: entity, removedConstraints
void __cdecl FUN_00926b70(Owner6b70* owner, PtrArray6b70* out)
{
    int ctx = owner->ctx;
    for (int i = (int)owner->entryCount - 1; i >= 0; i--)
    {
        Obj6b70* obj = owner->entries[i].object;
        obj->AddRef();
        FUN_009264b0(ctx, obj, 0);
        if (out->count == (int)(out->capacityAndFlags & 0x3fffffff))
            FUN_00901f10(out, 4);
        out->data[out->count] = obj;
        out->count++;
    }
    for (int i = owner->ptrCount - 1; i >= 0; i--)
    {
        Obj6b70* obj = owner->ptrs[i];
        obj->AddRef();
        FUN_009264b0(ctx, obj, 0);
        if (out->count == (int)(out->capacityAndFlags & 0x3fffffff))
            FUN_00901f10(out, 4);
        out->data[out->count] = obj;
        out->count++;
    }
}
}   // namespace f3m_00926b70

// @f3 0x009239d0 (community match, verified in this file)
namespace f3m_009239d0 {
struct Str {
    char* data;
    int length;
    unsigned char* FUN_009239d0(unsigned char* out, const Str* other) const;
};

// pdb: hkArrayBase<char>::pushBackUnchecked | hkStringBuf.obj | fnv360_0822_debug, objrun_open, low
// pdb params: t
unsigned char* Str::FUN_009239d0(unsigned char* out, const Str* other) const
{
    int n = other->length - 1;
    int off = length - 1;
    if (off < n)
    {
        *out = 0;
        return out;
    }
    off = length - other->length;
    for (int i = 0; i < n; i++)
    {
        if (data[off + i] != other->data[i])
        {
            *out = 0;
            return out;
        }
    }
    *out = 1;
    return out;
}
}   // namespace f3m_009239d0

// @f3 0x00931a50 (community match, verified in this file)
namespace f3m_00931a50 {
namespace f3m_00931a50 {
struct hkBaseObject
{
    virtual void unusedSlot0();
};
struct hkReferencedObject : hkBaseObject
{
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    hkReferencedObject() : m_referenceCount(1) {}
    void addReference() const
    {
        if (m_memSizeAndFlags != 0)
            const_cast<hkReferencedObject*>(this)->m_referenceCount++;
    }
};
struct hkpCollidable
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const void* m_parent;
    signed char m_ownerOffset;
    char pad11[3];
    int unk14[14];
    hkpCollidable(const void* shape, const void* motion, int type);
    void setOwner(void* owner) { m_ownerOffset = (signed char)((char*)owner - (char*)this); }
};
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
};
struct hkpLinkedCollidable : hkpCollidable
{
    hkArray<int> m_collisionEntries;
    hkpLinkedCollidable(const void* shape, const void* motion, int type) : hkpCollidable(shape, motion, type) {}
};
struct hkMultiThreadCheck
{
    unsigned int m_threadId;
    unsigned short m_markCount;
    hkMultiThreadCheck() : m_threadId(0xffffffd1), m_markCount(0) {}
};
}
class FUN_00931a50 : public f3m_00931a50::hkReferencedObject
{
public:
    void* m_world;
    unsigned int m_userData;
    f3m_00931a50::hkpLinkedCollidable m_collidable;
    f3m_00931a50::hkMultiThreadCheck m_multiThreadCheck;
    const char* m_name;
    f3m_00931a50::hkArray<int> m_properties;
    FUN_00931a50(const f3m_00931a50::hkReferencedObject* shape, int type);
    virtual void unusedSlot0();
};
// pdb: hkpWorldObject::hkpWorldObject | hkpWorldObject.obj | fnv360_0822_debug, call_seq, high
// pdb params: shape, type
FUN_00931a50::FUN_00931a50(const f3m_00931a50::hkReferencedObject* shape, int type)
    : m_world(0), m_userData(0), m_collidable(shape, 0, type), m_name(0)
{
    m_collidable.setOwner(this);
    if (shape)
        shape->addReference();
}
}   // namespace f3m_00931a50

// @f3 0x009235a0 (community match, verified in this file)
#include <string.h>
namespace f3m_009235a0 {

struct IntArr {
    int* data;
    int count;
    unsigned int capAndFlags;
};

char* FUN_00923450(const char* haystack, const char* needle);
void FUN_00901f10(IntArr* arr, int n);

// pdb: hkString::findAllOccurrences | hkString.obj | tesv_win, caller_sim, low
char* FUN_009235a0(char* __restrict out, const char* haystack, const char* needle, IntArr* arr, int all)
{
    int len = strlen(needle);
    char* found = FUN_00923450(haystack, needle);
    *out = 0;
    if (found != 0) {
    for (;;) {
        int off = (int)(found - haystack);
        int full = arr->count == (int)(arr->capAndFlags & 0x3fffffff);
        *out = 1;
        if (full)
            FUN_00901f10(arr, 4);
        arr->data[arr->count] = off;
        arr->count++;
        if (!all)
            break;
        found = FUN_00923450(found + len, needle);
        if (found == 0)
            break;
    }
    }
    return out;
}
}   // namespace f3m_009235a0

// @f3 0x009262f0 (community match, verified in this file)
extern int DAT_010f33b4;
extern double DAT_00db88e8;
namespace f3m_009262f0 {
struct Arr { int unk00; int unk04; unsigned short unk08; unsigned short unk0a; unsigned short unk0c; unsigned short unk0e; };
struct Quat { float w, x, y, z; int FUN_008374b0(const char* n); };
struct Vec3 { float x, y, z; int FUN_00823dc0(const char* n); };
struct Obj { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c; float unk20, unk24, unk28, unk2c, unk30, unk34, unk38; void FUN_009262f0(Arr* a); };
struct Stream : Arr {
    void FUN_00555790(unsigned int n);
    void FUN_005b3880(unsigned int idx, int* v);
    void Add(int v) {
        unsigned int n = unk0a;
        if (n >= unk08) FUN_00555790(n + unk0e);
        FUN_005b3880(n, &v);
    }
};
struct Thing { int FUN_009010b0(Stream* s); };
int __cdecl FUN_00847b50(int);
// pdb: bhkRigidBodyT::GetViewerStrings | bhkRigidBodyT.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Obj::FUN_009262f0(Arr* a)
{
    Stream* s = (Stream*)a;
    ((Thing*)this)->FUN_009010b0(s);
    s->Add(FUN_00847b50(DAT_010f33b4));
    Quat q; q.x = unk20; q.y = unk24; q.z = unk28; q.w = unk2c;
    Vec3 v; v.x = unk30 * DAT_00db88e8; v.y = unk34 * DAT_00db88e8; v.z = unk38 * DAT_00db88e8;
    s->Add(q.FUN_008374b0("Local Rot"));
    s->Add(v.FUN_00823dc0("Local Pos"));
}
}   // namespace f3m_009262f0

// @f3 0x00936750 (community match, verified in this file)
extern short DAT_0105f548;
namespace f3m_00936750 {
namespace f3m_00936750 {
struct Target_936750 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int size);
};
short __cdecl FUN_00936710(const char* name);
}
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
};
using namespace f3m_00936750;
static __declspec(noinline) void FUN_00936750(void* obj, int value, Target_936750* target)
{
    int* pv = &value;
    if (DAT_0105f548 == -1)
        DAT_0105f548 = FUN_00936710("TYPE_BRIDGE");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f548;
    FUN_0093d600 data(obj, "constraintData");
    *data.FUN_0093d670(0) = value;
    target->Set(value, data.FUN_0093d660());
}
void* volatile g_obj_936750; Target_936750* volatile g_t_936750; volatile int g_v_936750;
void caller_of_FUN_00936750() { FUN_00936750(g_obj_936750, g_v_936750, g_t_936750); }
}   // namespace f3m_00936750

// @f3 0x0092a520 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_0092a520 {
struct Alloc { void FUN_008f6d90(void* p, unsigned int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(int);

struct ArrData {
    int* data;
    int size;
    unsigned int cap;
};
struct ArrHolder {
    int unk00;
    ArrData arr;
    ArrHolder() { unk00 = 0; arr.data = 0; arr.size = 0; arr.cap = 0x80000000u; }
    ~ArrHolder()
    {
        if ((arr.cap & 0x80000000u) == 0) {
            unsigned int n = arr.cap & 0x3fffffff;
            Alloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(arr.data, n << 4, 0x17);
        }
    }
};
struct Other { void FUN_0092a1a0(ArrHolder* h); };
bool __stdcall FUN_008f7550(Other* o);
bool FUN_00979390(ArrData* a, ArrData* b);

struct FUN_0092a520_cls : Other {
    bool FUN_0092a520(Other* o);
};

// pdb: bhkMultiSphereShape::IsEqual | bhkMultiSphereShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: apObject
bool FUN_0092a520_cls::FUN_0092a520(Other* o)
{
    bool result = FUN_008f7550(o);
    if (result) {
        ArrHolder a;
        ArrHolder b;
        FUN_0092a1a0(&a);
        o->FUN_0092a1a0(&b);
        result = FUN_00979390(&a.arr, &b.arr);
    }
    return result;
}
}   // namespace f3m_0092a520

// @f3 0x009265a0 (community match, verified in this file)
namespace f3m_009265a0 {
class Island;

struct Entry_9265a0
{
    int item;
    void* object;
};

struct List_9265a0
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
    Entry_9265a0* entries;
    int count;
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
    Island* island;
};

struct Object_9265a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char subOffset;
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
    Island* island;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned char formType;
};

extern "C" void __cdecl hkAgentNnMachine_CopyAndRelinkAgentEntry(void* records, int item);
extern "C" void __cdecl FUN_00998ba0(void* owner, int item);
Island* PickIslandByValue(unsigned int value, Island* first, Island* second);

// pdb: hkpWorldOperationUtil::removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus | hkpWorldOperationUtil.obj | fnv360_0822_retail, caller_sim, low
// pdb params: trackToScan, entity, agentsRemoved, newMotionType
void FUN_009265a0(void* owner, List_9265a0* list, void* records, int mode)
{
    int i = 0;
    if (list->count > 0)
    {
        do
        {
            Entry_9265a0* entry = &list->entries[i];
            Object_9265a0* object = (Object_9265a0*)entry->object;
            Object_9265a0* sub = (Object_9265a0*)((char*)object + object->subOffset);
            if (sub->formType == 7)
            {
                int item = entry->item;
                hkAgentNnMachine_CopyAndRelinkAgentEntry(records, item);
                FUN_00998ba0(owner, item);
            }
            else if (mode == 7)
            {
                if (PickIslandByValue(entry->item, list->island, sub->island) == list->island)
                {
                    int item = entry->item;
                    hkAgentNnMachine_CopyAndRelinkAgentEntry((char*)sub->island + 0x58, item);
                    FUN_00998ba0(owner, item);
                }
            }
            ++i;
        } while (i < list->count);
    }
}
}   // namespace f3m_009265a0

// @f3 0x00922710 (community match, verified in this file)
namespace f3m_00922710 {
struct Map922 {
    int* m_table;      // 00
    int m_flags;       // 04
    int m_mask;        // 08
    int FUN_00922d60(int newSize);
    void FUN_00922710(unsigned int key, int val);
};

// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::insert | hkMap.obj | fnv360_0822_retail, call_gap, high
// pdb params: alloc, key, val
void Map922::FUN_00922710(unsigned int key, int val)
{
    unsigned int i;
    int isNew;
    if ((m_flags & 0x7fffffff) * 2 > m_mask)
        FUN_00922d60(m_mask + m_mask + 2);

    for (i = ((key >> 4) * 2654435761U) & m_mask; m_table[i] != -1; i = (i + 1) & m_mask)
    {
        if (m_table[i] == key)
            break;
    }
    isNew = m_table[i] != key;
    m_flags += isNew;
    m_table[i] = key;
    m_table[m_mask + i + 1] = val;
}
}   // namespace f3m_00922710

// @f3 0x0092a6b0 (community match, verified in this file)
extern double DAT_00db88e8;
extern void* DAT_010f33c8;
namespace f3m_0092a6b0 {
struct Entry { float x; float y; float z; float w; };
struct Inner { int unk00; int unk04; int unk08; int unk0C; int count; int unk14; int unk18; int unk1C; Entry entries[1]; };
struct Out {
    int unk00; int unk04;
    unsigned short size; unsigned short count; unsigned short unk0C; unsigned short grow;
    void Grow(int n);
    void SetAt(int idx, void* const& v);
};
struct Vec3 { float x; float y; float z; void* FUN_00823dc0(char* s); };
void* __cdecl FUN_00847b50(void* a);
void* __cdecl FUN_00847d30(const char* s, int n);
void* __cdecl FUN_00847dd0(char* s, float f);
int __cdecl FUN_00403230(char* buf, int n, const char* fmt, int i);

struct Dump {
    int unk00; int unk04; Inner* inner;
    void FUN_0090c3e0(Out* o);
    void FUN_0092a6b0(Out* o);
};

static inline void Push(Out* o, void* v)
{
    unsigned int n = o->count;
    if (n >= o->size)
        o->Grow(n + o->grow);
    o->SetAt(n, v);
}

// pdb: bhkMultiSphereShape::GetViewerStrings | bhkMultiSphereShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Dump::FUN_0092a6b0(Out* o)
{
    FUN_0090c3e0(o);
    void* t = FUN_00847b50(DAT_010f33c8);
    Push(o, t);
    int count = (this && inner) ? inner->count : 0;
    t = FUN_00847d30("Num Spheres", count);
    Push(o, t);
    if (this && inner) {
        Entry* p = inner->entries;
        if (p) {
            for (int i = 0; i < count; i++) {
                Vec3 v;
                double sc = DAT_00db88e8;
                float w = p->w;
                char buf[32];
                v.x = p->x * sc;
                v.y = p->y * sc;
                v.z = p->z * sc;
                FUN_00403230(buf, 32, "Pos %d", i);
                t = v.FUN_00823dc0(buf);
                Push(o, t);
                FUN_00403230(buf, 32, "Radius %d", i);
                t = FUN_00847dd0(buf, w);
                Push(o, t);
                p++;
            }
        }
    }
}
}   // namespace f3m_0092a6b0

// @f3 0x0092a0b0 (community match, verified in this file)
namespace f3m_0092a0b0 {
struct Vec4 { float x; float y; float z; float w; };
struct Vec4Array { int unk00; Vec4* data; int count; };
struct ScaleSource { int unk00; int unk04; int unk08; int unk0C; float scale; };

class Owner {
public:
    virtual void unk_v00();
    virtual void unk_v01();
    virtual void unk_v02();
    virtual void unk_v03();
    virtual void unk_v04();
    virtual void unk_v05();
    virtual void unk_v06();
    virtual void unk_v07();
    virtual void unk_v08();
    virtual void unk_v09();
    virtual void unk_v10();
    virtual void unk_v11();
    virtual void unk_v12();
    virtual void unk_v13();
    virtual void unk_v14();
    virtual void unk_v15();
    virtual void unk_v16();
    virtual void unk_v17();
    virtual void unk_v18();
    virtual void unk_v19();
    virtual void unk_v20();
    virtual void unk_v21();
    virtual void unk_v22();
    virtual void unk_v23();
    virtual void unk_v24();
    virtual void unk_v25();
    virtual void unk_v26();
    virtual void unk_v27();
    virtual void unk_v28();
    virtual void unk_v29();
    virtual void unk_v30();
    virtual void unk_v31();
    virtual void unk_v32();
    virtual void unk_v33();
    virtual void unk_v34();
    virtual void unk_v35();
    virtual void unk_v36();
    virtual void unk_v37();
    virtual void unk_v38();
    virtual void unk_v39();
    virtual void unk_v40();
    virtual void unk_v41();
    virtual void unk_v42();
    virtual void unk_v43();
    virtual void unk_v44();
    virtual Vec4Array* GetScaledArray(void* flag);
    void FUN_008f7580(int a, ScaleSource* b);
    void FUN_0092a0b0(int a, ScaleSource* b);
};

// pdb: bhkMultiSphereShape::CopyMembers | bhkMultiSphereShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: apDest, arCloneData
void Owner::FUN_0092a0b0(int a, ScaleSource* b)
{
    unsigned char flag;
    Vec4Array* arr = GetScaledArray(&flag);
    if (arr != 0) {
        float s = b->scale;
        if (s != 1.0f) {
            int n = arr->count;
            int i = n;
            if (i != 0) {
                do {
                    Vec4* e = &arr->data[--i];
                    e->x *= s; e->y *= s; e->z *= s; e->w *= s;
                } while (i != 0);
            }
        }
    }
    FUN_008f7580(a, b);
}
}   // namespace f3m_0092a0b0

// @f3 0x00926830 (community match, verified in this file)
namespace f3m_00926830 {
// FUN_00926830 draft. Stand-ins: Table/Owner/Node/Item named by offsets used.
struct PtrArray { void** data; int count; unsigned int capacityAndFlags; };

struct Item {
    int unk00;
    unsigned short w04;
    unsigned short w06;
    int unk08;
    void* owner0C;
};

struct Node {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short unk20;
    unsigned short unk22;
    unsigned char unk24;
    unsigned char unk25;
    void FUN_0098ae20(Item* item);
};

struct Owner {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Node* node20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    PtrArray array40;
};

struct Table {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4;
    Item** items1f8;
    unsigned short count1fc;
};

void __cdecl FUN_00901f10(PtrArray* a, int elemSize);

// pdb: hkpWorldOperationUtil::removeAttachedActionsFromFixedIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, caller_sim, low
// pdb params: world, entity, actionsToBeMoved
void __cdecl FUN_00926830(Owner* owner, Table* table, PtrArray* out)
{
    for (int i = 0; i < (int)table->count1fc; i++)
    {
        Item* item = table->items1f8[i];
        if (item->owner0C == owner->node20)
        {
            if (out->count == (int)(out->capacityAndFlags & 0x3fffffff))
                FUN_00901f10(out, 4);
            out->data[out->count] = item;
            out->count += 1;
            if (item->w04 != 0)
                item->w06 += 1;
            owner->node20->FUN_0098ae20(item);
            Node* n = owner->node20;
            n->unk25 = (unsigned char)((n->unk25 & 0xdf) | 0x10);
            Node* node = owner->node20;
            if (node->unk22 == 0xffff)
            {
                node->unk22 = (unsigned short)owner->array40.count;
                PtrArray* a = &owner->array40;
                if (a->count == (int)(a->capacityAndFlags & 0x3fffffff))
                    FUN_00901f10(a, 4);
                a->data[a->count] = node;
                a->count += 1;
            }
        }
    }
}
}   // namespace f3m_00926830

// @f3 0x00933d90 (community match, verified in this file)
namespace f3m_00933d90 {
struct RagdollFieldRef {
    void* unk00;
    int unk04;
    RagdollFieldRef(void* obj, const char* name);
    FieldElemM* ElemAt(int index);
    ByteBuffer* Array();
};

void FUN_00933d90(void* unused, void* obj)
{
    RagdollFieldRef rigid(obj, "rigidBodies");
    int count = rigid.ElemAt(0)->count04;
    RagdollFieldRef map(obj, "boneToRigidBodyMap");
    ByteBuffer* buf = map.Array();
    int cap = buf->capacityAndFlags & 0x3fffffff;
    if (cap < count)
    {
        int newCap = cap * 2;
        if (count >= newCap)
            newCap = count;
        FUN_00901e90(buf, newCap, 4);
    }
    buf->size = count;
    for (int i = 0; i < count; i++)
        ((int*)buf->data)[i] = i;
}
}   // namespace f3m_00933d90

// @f3 0x009284c0 (community match, verified in this file)
namespace f3m_009284c0 {
template <class T> struct Arr { T** data; int size; unsigned int cap; };
struct Entity; struct Kid;
struct Edi {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20; unsigned short w22; unsigned char unk24; unsigned char fl25; unsigned char unk27;
    void FUN_0098ae20(Kid* k);
};
struct Kid {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void Gather(Arr<Entity>* o);
    unsigned short w4; unsigned short w6;
};
struct Entity {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    Edi* edi;
    int unk_BC;
    int unk_C0;
    int unk_C4;
    int unk_C8;
    int unk_CC;
    int unk_D0;
    int unk_D4;
    unsigned char kind; unsigned char unkD9; unsigned short unkDA;
    int unk_DC;
    int unk_E0;
    int unk_E4;
    int unk_E8;
    int unk_EC;
    int unk_F0;
    int unk_F4;
    int unk_F8;
    int unk_FC;
    int unk_100;
    int unk_104;
    int unk_108;
    int unk_10C;
    int unk_110;
    int unk_114;
    int unk_118;
    int unk_11C;
    int unk_120;
    int unk_124;
    int unk_128;
    int unk_12C;
    int unk_130;
    int unk_134;
    int unk_138;
    int unk_13C;
    int unk_140;
    int unk_144;
    int unk_148;
    int unk_14C;
    int unk_150;
    int unk_154;
    int unk_158;
    int unk_15C;
    int unk_160;
    int unk_164;
    int unk_168;
    int unk_16C;
    int unk_170;
    int unk_174;
    int unk_178;
    int unk_17C;
    int unk_180;
    int unk_184;
    int unk_188;
    int unk_18C;
    int unk_190;
    int unk_194;
    int unk_198;
    int unk_19C;
    int unk_1A0;
    int unk_1A4;
    int unk_1A8;
    int unk_1AC;
    int unk_1B0;
    int unk_1B4;
    int unk_1B8;
    int unk_1BC;
    int unk_1C0;
    int unk_1C4;
    int unk_1C8;
    int unk_1CC;
    int unk_1D0;
    int unk_1D4;
    int unk_1D8;
    int unk_1DC;
    int unk_1E0;
    int unk_1E4;
    int unk_1E8;
    int unk_1EC;
    int unk_1F0;
    int unk_1F4;
    Kid** kids; unsigned short nkids;
};
struct Holder {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    Arr<Edi> list;
};
struct Alloc { void Free(void* p, int bytes, int tag); };
extern "C" __declspec(dllimport) Alloc* __stdcall TlsGetValue(unsigned long);
void __cdecl FUN_00901f10(void* a, int n);
// pdb: hkpWorldOperationUtil::removeAttachedActionsFromDynamicIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, caller_sim, low
// pdb params: world, entity, actionsToBeMoved
void FUN_009284c0(Holder* h, Entity* ent, Arr<Kid>* out)
{
    struct { Entity** data; int size; unsigned int cap; Entity* buf[16]; } loc;
    Edi* edi = ent->edi;
    loc.data = loc.buf; loc.size = 0; loc.cap = 0x80000010;
    for (int i = 0; i < ent->nkids; i++) {
        Kid* k = ent->kids[i];
        k->Gather((Arr<Entity>*)&loc);
        for (int j = 0; j < loc.size; j++) {
            if (loc.data[j]->kind != 7 && loc.data[j] != ent) goto next;
        }
        if (out->size == (int)(out->cap & 0x3fffffff)) FUN_00901f10(out, 4);
        out->data[out->size++] = k;
        if (k->w4) k->w6++;
        edi->FUN_0098ae20(k);
        edi->fl25 = (edi->fl25 & 0xdf) | 0x10;
        if (edi->w22 == 0xffff) {
            edi->w22 = (unsigned short)h->list.size;
            Arr<Edi>* l = &h->list;
            if (l->size == (int)(l->cap & 0x3fffffff)) FUN_00901f10(l, 4);
            l->data[l->size++] = edi;
        }
    next:;
    }
    if ((loc.cap & 0x80000000u) == 0) {
        int n = loc.cap & 0x3fffffff;
        Alloc* a = TlsGetValue(DAT_010f3170);
        a->Free(loc.data, n * 4, 0x17);
    }
}
}   // namespace f3m_009284c0

// @f3 0x00926b10 (community match, verified in this file)
namespace f3m_00926b10 {
struct Shape
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    unsigned short m_numShapeKeys;  // +0x9c
};

struct ShapeList
{
    Shape** m_items;
    int m_uiItemCount;
};

// For each shape in list, set flags[idx] to 1 and add its m_numShapeKeys (minimum 1) to counts[idx].
// Adapted from FNV 0x00cb41e0; FO3 shape-key count is at 0x9c.
// pdb: estimateSolverSize | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun_open, low
static void FUN_00926b10(int*** indexMap, int** counts, ShapeList* list, int** flags)
{
    int**** pp = &indexMap;
    for (int i = 0; i < list->m_uiItemCount; i++)
    {
        Shape* s = list->m_items[i];
        int idx = (***pp)[i];
        (*flags)[idx] = 1;
        int n = s->m_numShapeKeys;
        (*counts)[idx] += n < 1 ? 1 : n;
    }
}
int CountShapeKeysForList(ShapeList* list, int** flags, int*** indexMap, int** counts)
{
    FUN_00926b10(indexMap, counts, list, flags);
    return 0;
}
}   // namespace f3m_00926b10

// @f3 0x009269a0 (community match, verified in this file)
namespace f3m_009269a0 {
struct B10293_Item
{
    unsigned short Field(int off) const
    {
        return *(const unsigned short*)((const char*)this + off);
    }
};
struct B10293_List
{
    B10293_Item** m_data;
    int m_uiItemCount;
};
struct B10293_Ctx
{
    unsigned char Sel(int off) const
    {
        return *((const unsigned char*)this + off);
    }
};
struct B10293_Arr
{
    int* m_aiIndexedValues;
};
struct B10293_Chain
{
    B10293_Arr* m_aiIndexedValues;
};
static inline int Dec(int w, unsigned char s)
{
    if (s == (w >> 14))
        return (w >> 7) & 0x7f;
    return w & 0x7f;
}
// Zeroes out the output array, then for each list item computes a threshold from two packed fields and sets the indexed slot to 1 when the threshold is 5 or less.
// @fnv 0x00cb4080
// pdb: findInactiveGroups | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun_open, low
static void FUN_009269a0(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx)
{
    int i;
    for (i = 0; i < count; i++)
        (*out)[i] = 0;
    int j;
    for (j = 0; j < list->m_uiItemCount; j++)
    {
        B10293_Item* item = list->m_data[j];
        int a = Dec(item->Field(0xdc), ctx->Sel(0x2c6));
        int c = Dec(item->Field(0xda), ctx->Sel(0x2c5));
        a &= 0x7f;
        c &= 0x7f;
        if (c > a)
            a = c;
        if (a <= 5)
            (*out)[chain->m_aiIndexedValues->m_aiIndexedValues[j]] = 1;
    }
}
int keep_alive_b10293(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx)
{
    FUN_009269a0(count, list, out, chain, ctx);
    return count;
}
}   // namespace f3m_009269a0

// @f3 0x00932f00 (community match, verified in this file)
class hkOstreamD734
{
public:
    void* unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(void* buf, int size);
    hkOstreamD734& FUN_00cc01c0(const char* text);
    void FUN_00cc00e0();
};

class hkErrorD734
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int severity, unsigned int id, const char* description,
                        const char* file, int line);
};

extern hkErrorD734* DAT_01268360;

void __cdecl FUN_00932f00()
{
    int assertBuf[128];
    hkOstreamD734 ostr;
    ostr.FUN_00cb1600(assertBuf, sizeof(assertBuf));
    ostr.FUN_00cc01c0("This function should never be called.");
    DAT_01268360->message(3, 0x2d9a6f3e, (const char*)assertBuf,
                          ".\\hkCompat_hk510r1_hk550b1.cpp", 0xc0);
    ostr.FUN_00cc00e0();
}

// @f3 0x00936bd0 (community match, verified in this file)
extern short DAT_0105f568;
namespace f3m_00936bd0 {
namespace n936bd0 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
    struct R1* FUN_0093d790(const char* name, short* out);
};
struct R2 { void FUN_009b2360(); };
struct R1 { R2* FUN_0093d8b0(); };
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    short id;
    FUN_0093d600 f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}
static __declspec(noinline) void FUN_00936bd0(void* obj, char axis, float lo, float hi)
{
    if (DAT_0105f568 == -1)
        DAT_0105f568 = FUN_00936710(obj, "TYPE_LIN_LIMIT");
    { FUN_0093d600 f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f568; }
    { FUN_0093d600 f(obj, "axisIndex"); *f.FUN_0093d710(0) = axis; }
    { FUN_0093d600 f(obj, "min"); *f.FUN_0093d6a0(0) = lo; }
    { FUN_0093d600 f(obj, "max"); *f.FUN_0093d6a0(0) = hi; }
}
void* volatile g_obj; volatile char g_c; volatile float g_a, g_b;
void caller_of_FUN_00936bd0() { FUN_00936bd0(g_obj, g_c, g_a, g_b); }
}
}   // namespace f3m_00936bd0

// @f3 0x00936940 (community match, verified in this file)
extern short DAT_0105f554;
namespace f3m_00936940 {
namespace n936940 {
struct Rotation { float m[12]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    Rotation* FUN_0093d750(int index);
    struct R1* FUN_0093d790(const char* name, short* out);
};
struct R2 { void FUN_009b2360(); };
struct R1 { R2* FUN_0093d8b0(); };
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    short id;
    FUN_0093d600 f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}
void FUN_00936940(void* obj, const Rotation* a, const Rotation* b)
{
    if (DAT_0105f554 == -1)
        DAT_0105f554 = FUN_00936710(obj, "TYPE_SET_LOCAL_ROTATIONS");
    { FUN_0093d600 f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f554; }
    { FUN_0093d600 f(obj, "rotationA"); *f.FUN_0093d750(0) = *a; }
    { FUN_0093d600 f(obj, "rotationB"); *f.FUN_0093d750(0) = *b; }
}
}
}   // namespace f3m_00936940

// @f3 0x00923980 (community match, verified in this file)
namespace f3m_00923980 {
namespace n923980 {
struct Buffer {
    char* data;
    int size;
    bool* FUN_00923980(bool* result, const char* prefix);
};
bool* Buffer::FUN_00923980(bool* result, const char* prefix)
{
    for (int i = 0; prefix[i]; i++) {
        if (i >= size - 1 || data[i] != prefix[i]) {
            *result = false;
            return result;
        }
    }
    *result = true;
    return result;
}
}
}   // namespace f3m_00923980

// @f3 0x00930d10 (community match, verified in this file)
namespace f3m_00930d10 {
namespace f3m_00930d10 { extern int DAT_010f3420; }
struct Base_930d10 { virtual ~Base_930d10(); };
class FUN_00930d10 : public Base_930d10 {
public:
    virtual ~FUN_00930d10();
    void FUN_008f7ef0();
};
// pdb: bhkHingeConstraint::~bhkHingeConstraint | bhkHingeConstraint.obj | fnv360_0822_retail, call_seq, high
FUN_00930d10::~FUN_00930d10() { FUN_008f7ef0(); --f3m_00930d10::DAT_010f3420; }
}   // namespace f3m_00930d10

// @f3 0x00926250 (community match, verified in this file)
namespace n926250 {
struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;
extern void (__stdcall* DAT_00d9b09c)(void*);
extern void (__stdcall* DAT_00d9b0a0)(void*);
extern int DAT_010f3194;
}
class Node926250 {
public:
    Node926250();
    static void* operator new(unsigned int bytes)
    {
        unsigned char* p = (unsigned char*)n926250::DAT_01090a78.FUN_0086b930(bytes + 0x10);
        unsigned char offset = 0x10 - ((unsigned char)(unsigned int)p & 0xf);
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void* p);
    char pad[0x40];
};
struct Owner926250 {
    void FUN_00925690(Node926250* n, void* arg);
    Node926250* FUN_00926250(void* arg);
};
// pdb: bhkRigidBodyT::CreateClone | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCloneData
Node926250* Owner926250::FUN_00926250(void* arg)
{
    n926250::DAT_00d9b09c(&n926250::DAT_010f3194);
    Node926250* n = new Node926250;
    FUN_00925690(n, arg);
    n926250::DAT_00d9b0a0(&n926250::DAT_010f3194);
    return n;
}

// @f3 0x009331e0 (community match, verified in this file)
namespace f3m_009331e0 {
namespace n9331e0 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    unsigned char* FUN_0093d6e0(int index);
    float* FUN_0093d6a0(int index);
    unsigned char* FUN_0093d700(int index);
};
struct hkUFloat8 {
    unsigned char m_value;
    void FUN_0090aba0(const float& f);
};
}
void FUN_009331e0(void* src, void* dst)
{
    {
        n9331e0::FUN_0093d600 a(src, "deactivationClass");
        n9331e0::FUN_0093d600 b(dst, "deactivationClass");
        unsigned char* p = a.FUN_0093d6e0(0);
        *b.FUN_0093d700(0) = *p;
    }
    {
        n9331e0::FUN_0093d600 a(src, "maxLinearVelocity");
        n9331e0::FUN_0093d600 b(dst, "maxLinearVelocity");
        float f = *a.FUN_0093d6a0(0);
        n9331e0::hkUFloat8 u;
        u.FUN_0090aba0(f);
        *b.FUN_0093d700(0) = u.m_value;
    }
    {
        n9331e0::FUN_0093d600 a(src, "maxAngularVelocity");
        n9331e0::FUN_0093d600 b(dst, "maxAngularVelocity");
        float f = *a.FUN_0093d6a0(0);
        n9331e0::hkUFloat8 u;
        u.FUN_0090aba0(f);
        *b.FUN_0093d700(0) = u.m_value;
    }
}
void* volatile g9331e0a; void* volatile g9331e0b;
}   // namespace f3m_009331e0

// @f3 0x00935d90 (community match, verified in this file)
namespace f3m_00935d90 {
int __cdecl FUN_00935d90(SpanSource* source, ByteBuffer* buffer, int offset, OffsetList* offsets)
{
    DataSpan* span = source->FUN_0093d650();
    int length = span->length * 4;
    int aligned = (length + 3) & ~3;
    int required = buffer->size + aligned;
    int capacity = buffer->capacityAndFlags & 0x3fffffff;

    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        FUN_00901e90(buffer, newCapacity, 1);
    }

    buffer->size = required;
    FUN_009234e0(buffer->data + offset, span->data, length);
    *offsets->FUN_0093d6b0(0) = offset;
    return aligned;
}
}   // namespace f3m_00935d90

// @f3 0x0092f3d0 (community match, verified in this file)
namespace f3m_0092f3d0 {
namespace n92f3d0 {
class RefObj {
public:
    virtual ~RefObj();
    unsigned short memSizeAndFlags;
    short referenceCount;
    void addReference() { if (memSizeAndFlags != 0) ++referenceCount; }
    void removeReference() {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0) delete this;
        }
    }
};
}
struct Owner92f3d0 {
    int f0, f4;
    n92f3d0::RefObj* entries[8];
    void hkpCharacterStateManager_registerState(n92f3d0::RefObj* obj, int index);
};
// pdb: hkpCharacterStateManager::registerState | hkpCharacterStateManager.obj | fnv360_0822_retail, objrun + skyrim(objopen_prop), high
void Owner92f3d0::hkpCharacterStateManager_registerState(n92f3d0::RefObj* obj, int index)
{
    obj->addReference();
    if (entries[index]) entries[index]->removeReference();
    entries[index] = obj;
}
}   // namespace f3m_0092f3d0

// @f3 0x00923510 (community match, verified in this file)
#include <string.h>
namespace f3m_00923510 {
// pdb: hkStringBuf::lowerCase | hkStringBuf.obj | fnv360_0822_debug, objrun_open, low
int __cdecl FUN_00923510(const char* left, const char* right, unsigned int count) {
    return memcmp(left,right,count);
}
}   // namespace f3m_00923510

// @f3 0x0093cb30 (community match, verified in this file)
namespace f3m_0093cb30 {
struct Obj_93cb30 { int FUN_0093cb20(); };
int __cdecl FUN_0093cb30(int a, Obj_93cb30* b) { return b->FUN_0093cb20(); }
}   // namespace f3m_0093cb30

// @f3 0x00929ce0 (community match, verified in this file)
extern int DAT_00dfce2c;
namespace f3m_00929ce0 {
namespace task0803 {
void* __cdecl FUN_0089eb90(unsigned int) throw();
void __cdecl FUN_0089ec10(void*, unsigned int);
struct CloningProcess;
struct FUN_008d9f90 {
 void* vtable;
 int field04, field08, field0c, field10;
 FUN_008d9f90();
};
struct CloneObject : FUN_008d9f90 {
 static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); }
 static void operator delete(void* p, unsigned int n) { FUN_0089ec10(p,n); }
 CloneObject() { vtable=&DAT_00dfce2c; }
 void FUN_008d1f10(CloneObject*, CloningProcess&);
 CloneObject* FUN_00929ce0(CloningProcess&);
};
// pdb: bhkSPCollisionObject::CreateObject | bhkSPCollisionObject.obj | fnv360_0721_beta, objrun, low, conflict (bridge: bhkSPCollisionObject::CreateClone)
CloneObject* CloneObject::FUN_00929ce0(CloningProcess& process) {
 CloneObject* clone=new CloneObject;
 FUN_008d1f10(clone,process);
 return clone;
}
}
}   // namespace f3m_00929ce0

// @f3 0x00936b20 (community match, verified in this file)
extern short DAT_0105f564;
namespace f3m_00936b20 {
namespace n936b20 {
struct Field {
    void* unk00;
    int unk04;
    Field(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
};
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    Field f(obj, "type");
    return *f.FUN_0093d6e0(0) + (short)(int)name;
}
static __declspec(noinline) void FUN_00936b20(void* obj, char axisIndex, float tau, float damping)
{
    if (DAT_0105f564 == -1)
        DAT_0105f564 = FUN_00936710(obj, "TYPE_LIN_SOFT");
    { Field f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f564; }
    { Field f(obj, "axisIndex"); *f.FUN_0093d710(0) = axisIndex; }
    { Field f(obj, "tau"); *f.FUN_0093d6a0(0) = tau; }
    { Field f(obj, "damping"); *f.FUN_0093d6a0(0) = damping; }
}
void* volatile g_obj; volatile char g_c; volatile float g_a, g_b;
void caller_936b20() { FUN_00936b20(g_obj, g_c, g_a, g_b); }
}
}   // namespace f3m_00936b20

// @f3 0x00932fc0 (community match, verified in this file)
extern const char DAT_00e3ee04[];
namespace f3m_00932fc0 {


using namespace f3m_00936750;

struct FieldAccess_0093d6f0 {
    unsigned short* FUN_0093d6f0(int index);
};

void __cdecl FUN_00932fc0(void* object)
{
    FUN_0093d600 first(object, DAT_00e3ee04);
    FUN_0093d600 second(object, DAT_00e3ee04);

    FieldAccess_0093d6f0* firstAccess =
        reinterpret_cast<FieldAccess_0093d6f0*>(&first);
    FieldAccess_0093d6f0* secondAccess =
        reinterpret_cast<FieldAccess_0093d6f0*>(&second);

    unsigned short* source = firstAccess->FUN_0093d6f0(0);
    unsigned short* destination = secondAccess->FUN_0093d6f0(0);

    *destination = *source;
}
}   // namespace f3m_00932fc0

// @f3 0x0092c7c0 (community match, verified in this file)
extern unsigned int DAT_010f31f8, DAT_011691bc;
extern const char DAT_00e1c304[], DAT_00e36fbc[];
namespace f3m_0092c7c0 {
namespace Task0809 {
struct FUN_008f7c10 {
 const char* classTable;
 unsigned int unknown04, unknown08;
 FUN_008f7c10();
};
struct MiddleObject: FUN_008f7c10 {
 unsigned int initialized0c;
 MiddleObject():initialized0c(0){classTable=DAT_00e1c304; ++DAT_010f31f8;}
 void FUN_008fbad0();
 ~MiddleObject(){FUN_008fbad0();}
};
struct FUN_0092c7c0:MiddleObject {
 FUN_0092c7c0(void*);
 void FUN_008fc4a0(void*);
};
// pdb: bhkRagdollConstraint::bhkRagdollConstraint | bhkRagdollTemplate.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
FUN_0092c7c0::FUN_0092c7c0(void* context):MiddleObject() {
 classTable=DAT_00e36fbc;
 FUN_008fc4a0(context ? (char*)context+4:0);
 ++DAT_011691bc;
}
}
}   // namespace f3m_0092c7c0

// @f3 0x0092b330 (community match, verified in this file)
namespace f3m_0092b330 {
namespace n92b330 {
void __cdecl FUN_009a1770(void* sub, int id, void* arg);
}
struct Obj92b330 {
    char pad[0x10];
    char sub[4];
    void FUN_0092b330(void* arg);
};
void Obj92b330::FUN_0092b330(void* arg)
{
    n92b330::FUN_009a1770(sub, 0xc6, arg);
}
}   // namespace f3m_0092b330

// @f3 0x00934d80 (community match, verified in this file)
extern char DAT_00e3b020;
extern char DAT_00e67038;
namespace f3m_00934d80 {
namespace f3m_00934d80 {
struct Flag {
    bool v;
    Flag() {}
};
struct Ref {
    int a, b;
    void FUN_0093d600(void* o, void* type);
    Flag FUN_0093d640();
    int* FUN_0093d6b0(int i);
};
void FUN_00934d80(void* first, void* second) {
    Ref b;
    Ref a;
    a.FUN_0093d600(second, &DAT_00e3b020);
    b.FUN_0093d600(first, &DAT_00e67038);
    if (a.FUN_0093d640().v && b.FUN_0093d640().v) {
        *b.FUN_0093d6b0(0) = 0;
        *a.FUN_0093d6b0(0) = 0;
    }
}
}
}   // namespace f3m_00934d80

// @f3 0x0092f430 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
namespace f3m_0092f430 {
extern unsigned long DAT_010f3170;
struct Pool { void FUN_008f6d90(void* p, unsigned int size, int tag); };
struct Obj {
    void FUN_0092f380();
    Obj* FUN_0092f430(unsigned int flags);
    int unk00;
    unsigned short size;
};
// pdb: hkpCharacterStateManager::`scalar deleting destructor' | hkpCharacterStateManager.obj | fnv360_0822_retail, vtable, high
Obj* Obj::FUN_0092f430(unsigned int flags) {
    FUN_0092f380();
    if (flags & 1) {
        Pool* pool = (Pool*)TlsGetValue(DAT_010f3170);
        pool->FUN_008f6d90(this, size, 0x34);
    }
    return this;
}
}

// @f3 0x009349f0 (community match, verified in this file)
namespace f3m_009349f0 {
namespace f3m_009349f0 {
struct IntArray { int* data; int size; };
struct BitArray {
    unsigned int* words;
    int unk04;
    unsigned int cap;
    void FUN_009b2130(int n, int fill);
    int Capacity() const { return cap & 0x7fffffff; }
    void Set(int bit) {
        if (bit >= Capacity()) FUN_009b2130(bit + 1, 0);
        int w = bit >> 5;
        words[w] |= 1 << (bit & 0x1f);
    }
};
struct FUN_0093d600 {
    int a, b;
    FUN_0093d600(void* obj, const char* name);
    void* FUN_0093d660();
};
void FUN_009349f0(void* a, void* b) {
    FUN_0093d600 from(a, "keyframedBones");
    FUN_0093d600 to(b, "keyframedBones");
    IntArray* src = (IntArray*)from.FUN_0093d660();
    BitArray* dst = (BitArray*)to.FUN_0093d660();
    int n = src->size;
    for (int i = 0; i < n; i++) dst->Set(src->data[i]);
}
}
}   // namespace f3m_009349f0

// @f3 0x00932b00 (community match, verified in this file)
namespace f3m_00932b00 {
namespace f3m_00932b00 {

struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
};

static __declspec(noinline) void FUN_00932b00(void* src, void* dst) {
    FUN_0093d600 a(src, "handIndex");
    FUN_0093d600 b(dst, "handIkTrackIndex");
    *b.FUN_0093d6e0(0) = *a.FUN_0093d6e0(0);
}

volatile int g_a;
volatile int g_b;
void caller_of_FUN_00932b00() { FUN_00932b00((void*)g_a, (void*)g_b); }

}
}   // namespace f3m_00932b00

// @f3 0x00933930 (community match, verified in this file)
namespace f3m_00933930 {
namespace f3m_00933930 {
struct Tag { char c; };
struct Entry { void* key; void* value; };
struct Node { Entry* entries; int unk04; int unk08; Node* next; };
struct Registry {
    void FUN_009b1110(Tag t);
    void FUN_009b0e60(void* key, void* value);
    Registry* FUN_00933930(Node* node);
};
Registry* Registry::FUN_00933930(Node* node) {
    Tag t;
    t.c = 0;
    FUN_009b1110(t);
    for (; node; node = node->next) {
        if (node->entries) {
            for (int i = 0; node->entries[i].key; ++i) {
                FUN_009b0e60(node->entries[i].key, node->entries[i].value);
            }
        }
    }
    return this;
}
}
}   // namespace f3m_00933930

// @f3 0x00934a90 (community match, verified in this file)
inline void* operator new(unsigned int, void* p) { return p; }
namespace f3m_00934a90 {
extern const char DAT_00e3c0b8[];
extern const char DAT_00e63ca0[];
extern const char DAT_00e3e8c4[];
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Member {
    void* obj; void* member;
    Member(void* o, const char* name) { FUN_0093d600(o, name); }
    void FUN_0093d600(void* o, const char* name);
    void* FUN_0093d660();
};
struct Pair { int index; float value; };
template <class T> struct Arr {
    T* data; int size; unsigned int capFlags;
    Arr() { data = 0; size = 0; capFlags = 0x80000000; }
    void PushBack(const T& t) {
        if (size == (int)(capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = t;
        size++;
    }
};
void __cdecl FUN_00934a90(void* oldObj, void* newObj)
{
    Member a(oldObj, DAT_00e3c0b8);
    Member b(oldObj, DAT_00e63ca0);
    Member c(newObj, DAT_00e3e8c4);
    Arr<float>* values = (Arr<float>*)a.FUN_0093d660();
    Arr<int>* indices = (Arr<int>*)b.FUN_0093d660();
    Arr<Pair>* out = (Arr<Pair>*)c.FUN_0093d660();
    new (out) Arr<Pair>;
    int n = values->size;
    for (int i = 0; i < n; ++i) {
        Pair p;
        p.index = indices->data[i];
        p.value = values->data[i];
        out->PushBack(p);
    }
}
}

// @f3 0x00931cf0 (community match, verified in this file)
namespace f3m_00931cf0 {
namespace Append312{
struct Array312{void*vtable;void**data;unsigned short capacity,size,unk0c,grow;void FUN_00555790(unsigned int);void FUN_005b3880(unsigned int,void*const&);};
void __stdcall FUN_0090e750(Array312*);void* __cdecl FUN_00847b50(void*);extern void* DAT_010f3430;
// pdb: bhkCollisionBox::GetViewerStrings | bhkCollisionBox.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apStrings
void __stdcall FUN_00931cf0(Array312*array){FUN_0090e750(array);void*value=FUN_00847b50(DAT_010f3430);unsigned int size=array->size;if(size>=array->capacity)array->FUN_00555790(size+array->grow);array->FUN_005b3880(size,value);}
}
}   // namespace f3m_00931cf0

// @f3 0x00926fc0 (community match, verified in this file)
namespace f3m_00926fc0 {
namespace Append315{struct Entry315{
unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned short unk20,index;unsigned char unk24,unk25,flags;};struct Array315{Entry315**data;int size;unsigned int capacityFlags;};void __cdecl FUN_00901f10(Array315*,int);struct Owner315{
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
Array315 array;};
// pdb: hkpWorldOperationUtil::markIslandActive | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpWorldOperationUtil_markIslandActive(Owner315*owner,Entry315*entry){entry->flags=(entry->flags&~8)|4;if(entry->index==0xffff){entry->index=(unsigned short)owner->array.size;Array315*array=&owner->array;if(array->size==(array->capacityFlags&0x3fffffff))FUN_00901f10(array,4);array->data[array->size]=entry;++array->size;}}
}
}   // namespace f3m_00926fc0

// @f3 0x0093e540 (community match, verified in this file)
namespace f3m_0093e540 {
struct Entry316{void*value;unsigned int FUN_0093e540();};
unsigned int Entry316::FUN_0093e540(){unsigned int count=0;Entry316*entry=this;while(entry->value){++entry;++count;}return count;}
}   // namespace f3m_0093e540

// @f3 0x0093ca20 (community match, verified in this file)
namespace f3m_0093ca20 {
namespace Rename317{
void __cdecl FUN_0093e480(void*,const char*,void*,const char*);
void __cdecl FUN_0093ca20(void*first,void*second){FUN_0093e480(first,"maxNegForce",second,"minForce");FUN_0093e480(first,"maxPosForce",second,"maxForce");}
}
}   // namespace f3m_0093ca20

// @f3 0x0093bee0 (community match, verified in this file)
namespace f3m_0093bee0 {
namespace Motion321{
struct Pair321{void*data;void*type;};struct FUN_0093d600{unsigned int unk00,unk04;FUN_0093d600(void*,const char*);void** FUN_0093d670(int);Pair321 FUN_0093d810();};
struct Manager321{void* FUN_0093c0e0(void*);};extern Manager321* DAT_01169100;
struct Visitor321{virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual void v14();virtual void Visit(void*,int,int);};
void __cdecl FUN_0093bbc0(const Pair321*,const Pair321*,Visitor321*);
void __cdecl FUN_0093bee0(void*first,void*second,Visitor321*visitor){FUN_0093d600 oldMotion(first,"motion");void*motion=*oldMotion.FUN_0093d670(0);void*type=DAT_01169100->FUN_0093c0e0(motion);if(type){FUN_0093d600 newMotion(second,"motion");Pair321 source;source.data=newMotion.FUN_0093d810().data;source.type=newMotion.FUN_0093d810().type;Pair321 mapped;mapped.data=motion;mapped.type=type;FUN_0093bbc0(&mapped,&source,visitor);visitor->Visit(motion,0,0);}}
}
}   // namespace f3m_0093bee0

// @f3 0x00936410 (community match, verified in this file)
namespace f3m_00936410 {
namespace n936410 {
struct Field {
    void* unk00;
    int unk04;
    Field(void* obj, const char* name);
    float* FUN_0093d6a0(int index);
    bool* FUN_0093d690(int index);
};
}
void __cdecl FUN_00936410(void* src, void* dst)
{
    n936410::Field out(dst, "autoComputeSecondGeneratorWeight");
    n936410::Field in(src, "autoComputeSecondGeneratorWeight");
    bool v = *in.FUN_0093d6a0(0) != 0.0f;
    *out.FUN_0093d690(0) = v;
}
}   // namespace f3m_00936410

// @f3 0x009302a0 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009302a0 {
namespace n9302a0 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(int);
struct Src { int a0; void* shape; float f8, fc, f10, f14; };
struct NewObj {
    virtual ~NewObj();
    unsigned short memSize;
    short refCount;
    NewObj(void* a, int b);
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x29);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x29);
    }
    void RemoveReference() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
    char pad[0x30 - 8];
};
struct D { char pad[0x18]; void* p18; };
struct C { char pad[8]; D* d; };
C* __cdecl FUN_004779d0(void* shape);
}
struct Obj9302a0 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void AddThing(n9302a0::NewObj* o);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Use(n9302a0::Src* s);
    char pad[0x10];
    float f14, f18, f1c, f20;
    void FUN_0092f910(void* p);
    void FUN_009302a0(n9302a0::Src* s);
};
// pdb: bhkLiquidAction::Init | bhkLiquidAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: arInfo
void Obj9302a0::FUN_009302a0(n9302a0::Src* s)
{
    if (!s) return;
    f1c = s->f8;
    f20 = s->fc;
    f14 = s->f10;
    f18 = s->f14;
    n9302a0::NewObj* o = new n9302a0::NewObj(s->shape, 0);
    AddThing(o);
    o->RemoveReference();
    n9302a0::C* c = n9302a0::FUN_004779d0(s->shape);
    if (c && c->d && c->d->p18)
        FUN_0092f910(c->d->p18);
    Use(s);
}
}   // namespace f3m_009302a0

// @f3 0x00929e70 (community match, verified in this file)
namespace f3m_00929e70 {
namespace Append334{
struct Array334{void*vtable;void**data;unsigned short capacity,size,unk0c,grow;void FUN_00555790(unsigned int);void FUN_005b3880(unsigned int,void*const&);};
void __stdcall FUN_008f9880(Array334*);void* __cdecl FUN_00847b50(void*);extern void* DAT_010f33bc;
// pdb: bhkSPCollisionObject::AddViewerStrings | bhkSPCollisionObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void __stdcall FUN_00929e70(Array334*array){FUN_008f9880(array);void*value=FUN_00847b50(DAT_010f33bc);unsigned int size=array->size;if(size>=array->capacity)array->FUN_00555790(size+array->grow);array->FUN_005b3880(size,value);}
}
}   // namespace f3m_00929e70

// @f3 0x00922e40 (community match, verified in this file)
namespace f3m_00922e40 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Free335{
extern unsigned long DAT_010f3170;struct Heap335{void FUN_008f6d90(void*,unsigned int,int);};
struct Array335{void*data;unsigned int flags,size;void FUN_00922e40();};
// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::clearAndDeallocate | hkMap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: alloc
void Array335::FUN_00922e40(){if(!(flags&0x80000000)){unsigned int entries=size+size+2;void*allocation=data;Heap335*heap=(Heap335*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(allocation,entries*8,23);}}
}
}   // namespace f3m_00922e40

// @f3 0x0092e870 (community match, verified in this file)
namespace f3m_0092e870 {
int __stdcall FUN_0092e870(int size){if(size>16)return ((size+15)&~15)+16;return size+8;}
}   // namespace f3m_0092e870

// @f3 0x00935f00 (community match, verified in this file)
namespace f3m_00935f00 {
namespace n935f00 {
struct Member { int FUN_0093dac0(); };
struct Field {
    char* data;
    int count;
    Field(void* obj, const char* name);
    Member* FUN_0093d790();
    Field* FUN_0093d660();
};
static __declspec(noinline) void FUN_00935ea0(Field* src, Field* dst)
{
    int srcStride = src->FUN_0093d790()->FUN_0093dac0();
    int dstStride = dst->FUN_0093d790()->FUN_0093dac0();
    Field* s = src->FUN_0093d660();
    Field* d = dst->FUN_0093d660();
    char* sp = s->data;
    int n = s->count;
    char* dp = d->data;
    for (; n > 0; --n) {
        *(int*)dp = *(int*)sp;
        sp += srcStride;
        dp += dstStride;
    }
}
}
void __cdecl FUN_00935f00(void* srcObj, void* dstObj)
{
    n935f00::Field src(srcObj, "transitions");
    n935f00::Field dst(dstObj, "transitions");
    n935f00::FUN_00935ea0(&src, &dst);
}
}   // namespace f3m_00935f00

// @f3 0x00923410 (community match, verified in this file)
namespace f3m_00923410 {
int __cdecl FUN_00c03188(int a, int b, int c);
// pdb: hkString::atoi | hkString.obj | fnv360_0822_retail, call_gap + skyrim(call_gap), high
int __cdecl hkString_atoi(int a) { return FUN_00c03188(a, 0, 0); }
}   // namespace f3m_00923410

// @f3 0x009330f0 (community match, verified in this file)
namespace f3m_00936750 {
struct FUN_009330f0_Wrapper : FUN_0093d600 {
    FUN_009330f0_Wrapper(void* object, const char* name) : FUN_0093d600(object, name) {}
    int* FUN_0093d6c0(int index);
    int* FUN_0093d6d0(int index);
};
extern const char DAT_00e3bd24[];
}
void __cdecl FUN_009330f0(void* source, void* destination)
{
    f3m_00936750::FUN_009330f0_Wrapper from(source, f3m_00936750::DAT_00e3bd24);
    f3m_00936750::FUN_009330f0_Wrapper to(destination, f3m_00936750::DAT_00e3bd24);
    int* sourceValue = from.FUN_0093d6c0(0);
    int* destinationValue = to.FUN_0093d6d0(0);
    *destinationValue = *sourceValue;
}

// @f3 0x0093c920 (community match, verified in this file)
extern char DAT_00e399e8,DAT_00e3e3bc;
namespace f3m_0093c920 {
namespace Transfer351{
struct FUN_0093d600{void*object;int index;FUN_0093d600(void*,const char*);bool*FUN_0093d640(bool*);float*FUN_0093d6a0(int);};
void __cdecl FUN_0093c920(void*source,void*destination){FUN_0093d600 first(destination,&DAT_00e399e8);FUN_0093d600 second(destination,&DAT_00e3e3bc);FUN_0093d600 third(source,&DAT_00e3e3bc);bool valid;if(*first.FUN_0093d640(&valid)&&*second.FUN_0093d640(&valid)&&*third.FUN_0093d640(&valid)){*first.FUN_0093d6a0(0)=-*third.FUN_0093d6a0(0);*second.FUN_0093d6a0(0)=*third.FUN_0093d6a0(0);}}
}
}   // namespace f3m_0093c920

// @f3 0x00926f50 (community match, verified in this file)
namespace f3m_00926f50 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
namespace n926f50 {
struct Lock {
    int cs[6];
    int owner;
    int depth;
    void FUN_00908a00();
    void Leave() { owner = -1; depth = -1; LeaveCriticalSection(this); }
};
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Obj;
struct Array {
    Obj** data;
    int size;
    int capAndFlags;
    void PushBack(Obj* o) {
        if (size == (capAndFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        data[size] = o;
        size++;
    }
};
struct Obj { char pad[0x22]; unsigned short index; unsigned char pad2[2]; unsigned char flags; };
struct World {
    char pad[0x40];
    Array objs;
    char pad2[0xb0 - 0x4c];
    Lock* lock;
};
}
// pdb: hkpWorldOperationUtil::markIslandInactiveMt | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_seq) + skyrim(call_gap_sim), high
void __cdecl hkpWorldOperationUtil_markIslandInactiveMt(n926f50::World* world, n926f50::Obj* obj) {
    obj->flags &= 0xf3;
    world->lock->FUN_00908a00();
    if (obj->index == 0xffff) {
        obj->index = (unsigned short)world->objs.size;
        world->objs.PushBack(obj);
    }
    world->lock->Leave();
}
}   // namespace f3m_00926f50

// @f3 0x0092e780 (community match, verified in this file)
namespace n92e780 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long) throw();
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = FUN_00d9b080(n92e780::DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
}
struct FUN_0092e780_c {
    void* vptr;
    unsigned short memSize;
    short refCount;
    char pad8[0x54 - 8];
    n92e780::Array<int> arr;
    void FUN_009ae9d0() throw();
    void* FUN_0092e780(unsigned int flags) throw();
};
// pdb: hkpMouseSpringAction::`scalar deleting destructor' | hkpMouseSpringAction.obj | fnv360_0822_retail, vtable, high
void* FUN_0092e780_c::FUN_0092e780(unsigned int flags) throw()
{
    arr.~Array();
    FUN_009ae9d0();
    if (flags & 1) {
        n92e780::Alloc* al = n92e780::FUN_00d9b080(n92e780::DAT_010f3170);
        al->FUN_008f6d90(this, memSize, 0x29);
    }
    return this;
}

// @f3 0x00938d80 (community match, verified in this file)
namespace f3m_00938d80 {
namespace n938d80 {
int __cdecl hkString_strCmp(const char* a, const char* b);
struct Enum { void FUN_009b2360(const char* name, int* out); };
struct Pair { const char* key; const char* value; };
}
char __cdecl FUN_00938d80(const char* className, n938d80::Enum* e)
{
    n938d80::Pair table[] = {
        { "hkSphereMotion", "MOTION_SPHERE_INERTIA" },
        { "hkStabilizedSphereMotion", "MOTION_STABILIZED_SPHERE_INERTIA" },
        { "hkBoxMotion", "MOTION_BOX_INERTIA" },
        { "hkStabilizedBoxMotion", "MOTION_STABILIZED_BOX_INERTIA" },
        { "hkKeyframedRigidMotion", "MOTION_KEYFRAMED" },
        { "hkFixedRigidMotion", "MOTION_FIXED" },
        { "hkThinBoxMotion", "MOTION_THIN_BOX_INERTIA" },
        { 0, 0 }
    };
    const char* name = "MOTION_INVALID";
    for (int i = 0; table[i].key; i++) {
        if (n938d80::hkString_strCmp(table[i].key, className) == 0) {
            name = table[i].value;
            break;
        }
    }
    int result = 0;
    e->FUN_009b2360(name, &result);
    return (char)result;
}
}   // namespace f3m_00938d80

// @f3 0x0092d610 (community match, verified in this file)
namespace task0894 {
extern int DAT_00e3714c;
struct MemoryManager { void FUN_0086ba60(void*); };
extern MemoryManager DAT_01090a78;
struct Object;
struct Table { void* slot00; void* slot04; void (__thiscall *Free)(Object*,void*); };
struct Object {
 Table* vtable; void* data; unsigned int size,capacity;
 void FUN_005e5240(void*,unsigned int);
 Object* FUN_0092d610(unsigned char);
};
// pdb: BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024>::`scalar deleting destructor' | bhkRagdollTemplate.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
Object* Object::FUN_0092d610(unsigned char flags) {
 void* oldData=data;
 vtable=reinterpret_cast<Table*>(&DAT_00e3714c);
 if(oldData) {
  FUN_005e5240(oldData,size);
  vtable->Free(this,data);
  data=0; capacity=0; size=0;
 }
 if(flags&1) DAT_01090a78.FUN_0086ba60(this);
 return this;
}
}

// @f3 0x009305b0 (community match, verified in this file)
namespace f3m_009305b0 {
int __cdecl FUN_009a1770(void* sub, int k, int v);
struct O_9305b0 { char pad[0x10]; char sub[8]; int FUN_009305b0(int v); };
// pdb: hkLiquidAction::SetForce | bhkLiquidAction.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpHingeConstraintData::getConstraintInfo)
// pdb params: apObject
int O_9305b0::FUN_009305b0(int v) { return FUN_009a1770(sub, 0x96, v); }
}   // namespace f3m_009305b0

// @f3 0x00931740 (community match, verified in this file)
namespace f3m_00931740 {
struct FUN_00931740_Entry {
    int key;
    int unk04;
    int value3;
    int value4;
};

struct FUN_00931740_Array {
    FUN_00931740_Entry* data;
    int count;
    unsigned int capacityAndFlags;
};

struct FUN_00931740_Object {
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
    FUN_00931740_Array entries;

    void hkpWorldObject_addProperty(int key, int value3, int value4);
};

void __cdecl FUN_00901f10(FUN_00931740_Array* array, int stride);

// pdb: hkpWorldObject::addProperty | hkpWorldObject.obj | fnv360_0822_retail, caller + bridge(call_gap|call_seq) + skyrim(objrun_prop), high
void FUN_00931740_Object::hkpWorldObject_addProperty(int key, int value3, int value4)
{
    int count = entries.count;
    int i = 0;

    if (count > 0)
    {
        FUN_00931740_Entry* entry = entries.data;
        do
        {
            if (entry->key == key)
                return;

            ++i;
            ++entry;
        }
        while (i < count);
    }

    FUN_00931740_Array* array = &entries;
    if (array->count == (int)(array->capacityAndFlags & 0x3fffffff))
        FUN_00901f10(array, 0x10);

    int index = array->count;
    FUN_00931740_Entry* entry = array->data + index;
    ++index;
    array->count = index;
    entry->value3 = value3;
    entry->value4 = value4;
    entry->key = key;
}
}   // namespace f3m_00931740

// @f3 0x00922500 (community match, verified in this file)
extern void* DAT_010f335c;
namespace f3m_00922500 {
namespace task0915 {
struct StrArr {void* field00;void* field04; unsigned short capacity,size,field0c,grow; void FUN_00555790(unsigned int); void FUN_005b3880(unsigned int,char*&);};
void __stdcall FUN_00911090(StrArr*);
char* __cdecl FUN_00847b50(void*);
// pdb: bhkTriSampledHeightFieldBvTreeShape::GetViewerStrings | bhkTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void __stdcall FUN_00922500(StrArr* a) {
 FUN_00911090(a);
 char* s=FUN_00847b50(DAT_010f335c);
 unsigned int i=a->size;
 unsigned int n=a->capacity;
 if(i>=n) a->FUN_00555790(a->grow+i);
 a->FUN_005b3880(i,s);
}
}
}   // namespace f3m_00922500

// @f3 0x0093f150 (community match, verified in this file)
namespace n93f150 {
extern unsigned long DAT_010f3170;
struct Alloc { void* FUN_008f6d30(int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long) throw();
struct Str {
    char* data;
    int size;
    int cap;
    Str() throw() {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        data = (char*)al->FUN_008f6d30(1, 0x17);
        size = 1;
        cap = 1;
        data[0] = 0;
    }
};
struct Tag { char c; };
struct Map { char pad[0x10]; void FUN_009b1110(Tag t) throw(); };
struct Registry { void* FUN_009b05d0(const char* name) throw(); };
extern Registry DAT_011693b0;
}
struct FUN_0093f150 {
    void* type;
    int m4;
    n93f150::Str s8;
    n93f150::Str s14;
    int m20;
    int m24;
    n93f150::Map map;
    FUN_0093f150(int a, int b, int c) throw();
};
// pdb: hkDataWorldNative::hkDataWorldNative | hkDataObjectNative.obj | fnv360_0822_retail, caller_sim, medium
FUN_0093f150::FUN_0093f150(int a, int b, int c) throw() : m4(a), m20(b), m24(c)
{
    n93f150::Tag t = { 0 };
    map.FUN_009b1110(t);
    type = n93f150::DAT_011693b0.FUN_009b05d0("Type");
}

// @f3 0x00933a70 (community match, verified in this file)
namespace f3m_00933a70 {
extern void __cdecl FUN_0093e480(void* object, const char* field1, void* value, const char* field2);

void __cdecl FUN_00933a70(void* object, void* value)
{
    FUN_0093e480(object, "multithreadLock", value, "multiThreadCheck");
}
}   // namespace f3m_00933a70

// @f3 0x009226f0 (community match, verified in this file)
namespace f3m_009226f0 {
// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::getSizeInBytesFor | hkMap.obj | fnv360_0822_retail, call_gap, high
// pdb params: numOfKeys
int __cdecl FUN_009226f0(int n) { int p = 4; while (p < n) p += p; return p << 5; }
}   // namespace f3m_009226f0

// @f3 0x0092f380 (community match, verified in this file)
namespace f3m_0092f380 {
namespace task92f380 {
struct Ref { virtual void Destroy(unsigned); short unk04; short unk06; };
struct Base { virtual ~Base() throw() {} int unk04; Ref* entries[11]; };
struct FUN_0092f380 : Base { virtual ~FUN_0092f380() throw(); };
// pdb: hkpCharacterStateManager::~hkpCharacterStateManager | hkpCharacterStateManager.obj | fnv360_0822_retail, call_seq, high
FUN_0092f380::~FUN_0092f380() throw() {
 for (int i=0;i<11;i++) {
  Ref* p=entries[i];
  if (p) {
   if (p->unk04 && --p->unk06 == 0) p->Destroy(1);
   entries[i]=0;
  }
 }
}
}
}   // namespace f3m_0092f380

// @f3 0x0092d590 (community match, verified in this file)
namespace f3m_0092d590 {
class Base_92d590 {
public:
    virtual ~Base_92d590() {}
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Base_92d590() { unk04 = 0; unk0C = 0; unk10 = 0; unk08 = 1; }
};
class FUN_0092d590 : public Base_92d590 {
public:
    virtual ~FUN_0092d590();
    FUN_0092d590();
};
FUN_0092d590::FUN_0092d590() {}
}   // namespace f3m_0092d590

// @f3 0x0092d5d0 (community match, verified in this file)
namespace f3m_0092d5d0 {
namespace task0959 {

struct FUN_00cbadb0_Dispatch
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
};
struct FUN_0092d5d0
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
    virtual ~FUN_0092d5d0();

    void* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void FUN_005e5240(void* items, unsigned int count);
};
// Destructor that releases the m_items array via FUN_005e5240 and releaseItem, then nulls m_items and the two counters.
// @fnv 0x00cbadb0
// pdb: BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024>::~BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> | bhkRagdollTemplate.obj | fnv360_0822_retail, objrun_open, low
FUN_0092d5d0::~FUN_0092d5d0()
{
    if (m_items)
    {
        FUN_005e5240(m_items, m_uiItemCount);
        reinterpret_cast<FUN_00cbadb0_Dispatch*>(this)->releaseItem(m_items);
        m_items = 0;
        m_pRayCursor = 0;
        m_uiItemCount = 0;
    }
}
}
}   // namespace f3m_0092d5d0

// @f3 0x0092c8d0 (community match, verified in this file)
namespace f3m_0092c8d0 {
extern void (__stdcall *DAT_00e3709c)(void*);
namespace task0954 {
struct MemoryManager { void FUN_0086ba60(void*); };
}
namespace task0954 { extern MemoryManager DAT_01090a78; }
struct SsArr0954 {
 virtual ~SsArr0954() {
  if (data) {
   DAT_00e3709c(data);
   data = 0;
   capacity = 0;
   size = 0;
  }
 }
 void* data;
 unsigned int size;
 unsigned int capacity;
};
// pdb: BSSimpleArray<hkConstraintCinfo *,1024>::`scalar deleting destructor' | bhkRagdollTemplate.obj | fnv360_0721_beta, objrun_open, low
SsArr0954* __fastcall FUN_0092c8d0(SsArr0954* object, int, unsigned int flags) {
 object->SsArr0954::~SsArr0954();
 if (flags & 1) task0954::DAT_01090a78.FUN_0086ba60(object);
 return object;
}



}   // namespace f3m_0092c8d0

// @f3 0x00931890 (community match, verified in this file)
namespace f3m_00931890 {
struct T_931890 { void FUN_00908a00(); };
struct M_931890 { char pad[0xb4]; T_931890* t; };
struct O_931890 { int u0, u4; M_931890* m; void FUN_00931890(int x); };
void O_931890::FUN_00931890(int x) { if (m) { T_931890* t = m->t; if (t) t->FUN_00908a00(); } }
}   // namespace f3m_00931890

// @f3 0x0092d5b0 (community match, verified in this file)
namespace f3m_0092d5b0 {
class B_0092d5b0 { public: virtual void v0(); int a4, a8, ac, a10; B_0092d5b0() { a4 = 0; ac = 0; a10 = 0; a8 = 1; } };
class FUN_0092d5b0 : public B_0092d5b0 { public: FUN_0092d5b0(); virtual void v0(); };
FUN_0092d5b0::FUN_0092d5b0() {}
}   // namespace f3m_0092d5b0

// @f3 0x0092c8a0 (community match, verified in this file)
namespace task1018 {
struct Object;struct Table{void* slot0;void* slot4;void (__thiscall *Free)(Object*,void*);};
extern Table DAT_00e370a8;
struct Object{Table* table;void* data;int size,capacity;void FUN_0092c8a0();};
void Object::FUN_0092c8a0(){void* old=data;table=&DAT_00e370a8;if(old){DAT_00e370a8.Free(this,old);data=0;capacity=0;size=0;}}
}

// @f3 0x00932760 (community match, verified in this file)
extern char DAT_00e14950; extern char DAT_00e3abc4;
namespace f3m_00932760 {
int __cdecl FUN_0093e480(int a, void* p1, int b, void* p2);
int __cdecl FUN_00932760(int a, int b) { return FUN_0093e480(a, &DAT_00e14950, b, &DAT_00e3abc4); }
}   // namespace f3m_00932760

// @f3 0x0093d010 (community match, verified in this file)
extern char DAT_00e73dc0; extern char DAT_00e3bb6c;
namespace f3m_0093d010 {
int __cdecl FUN_0093e480(int a, void* p1, int b, void* p2);
int __cdecl FUN_0093d010(int a, int b) { return FUN_0093e480(a, &DAT_00e73dc0, b, &DAT_00e3bb6c); }
}   // namespace f3m_0093d010

// @f3 0x0092e8a0 (community match, verified in this file)
namespace f3m_0092e8a0 {
class FUN_0092e8a0 { public: virtual void v0(); int a4, a8, ac, a10; FUN_0092e8a0(); };
FUN_0092e8a0::FUN_0092e8a0() { a10 = 1; ac = 0; a4 = 0; a8 = 0x7fffffff; }
}   // namespace f3m_0092e8a0

// @f3 0x00922f70 (community match, verified in this file)
namespace f3m_00922f70 {
struct O_922f70 { int FUN_00922d60(int n); int FUN_00922f70(int n); };
int O_922f70::FUN_00922f70(int n) { int t = n * 3; int p = 4; while (p < t) p += p; return FUN_00922d60(p); }
}   // namespace f3m_00922f70

// @f3 0x0093cdd0 (community match, verified in this file)
extern const char DAT_00e3f9fc[], DAT_00e73e18[], DAT_00e430b8[], DAT_00e73df4[], DAT_00e73e04[], DAT_00e4c974[];
namespace f3m_0093cdd0 {
namespace task93cdd0 {
extern void __cdecl FUN_0093e480(void*,const char*,void*,const char*);
struct Reader { int unk00,unk04; Reader(void*,const char*); bool* FUN_0093d640(bool*); short* FUN_0093d6e0(int); int* FUN_0093d6b0(int); };
void __cdecl FUN_0093cdd0(void* a,void* b) {
 FUN_0093e480(a,DAT_00e73e18,b,DAT_00e3f9fc);
 FUN_0093e480(a,DAT_00e73df4,b,DAT_00e430b8);
 Reader src(a,DAT_00e73e04); Reader dst(b,DAT_00e4c974); bool valid;
 if (*src.FUN_0093d640(&valid) && *dst.FUN_0093d640(&valid)) *dst.FUN_0093d6b0(0)=*src.FUN_0093d6e0(0);
}
}
}   // namespace f3m_0093cdd0

// @f3 0x00932c50 (community match, verified in this file)
namespace f3m_00932c50 {
namespace n932c50 {
struct Variant;
void __cdecl FUN_0093e480(Variant& oldObj, const char* oldName, Variant& newObj, const char* newName);
struct Accessor {
    void* member; void* object;
    Accessor(Variant& v, const char* name);
    float& FUN_0093d6a0(int index);
};
}
void __cdecl FUN_00932c50(n932c50::Variant& oldObj, n932c50::Variant& newObj)
{
    {
        n932c50::Accessor oldA(oldObj, "maxBoneLengthFraction");
        n932c50::Accessor newA(newObj, "maxElongation");
        newA.FUN_0093d6a0(0) = oldA.FUN_0093d6a0(0);
    }
    {
        n932c50::Accessor oldB(oldObj, "minBoneLengthFraction");
        n932c50::Accessor newB(newObj, "maxCompression");
        newB.FUN_0093d6a0(0) = oldB.FUN_0093d6a0(0);
    }
}
}   // namespace f3m_00932c50

// @f3 0x00933700 (community match, verified in this file)
namespace n933700 {
struct hkError {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
extern hkError* DAT_010f3364;
struct hkOstream {
    int a, b, c;
    void FUN_00923070(char* buf, int size);
    void FUN_00943a60();
    hkOstream& FUN_00943710(const char* s) throw();
};
}
void __cdecl FUN_00933700()
{
    int buf[0x80];
    n933700::hkOstream os;
    os.FUN_00923070((char*)buf, 0x200);
    os.FUN_00943710("This function should never be called.");
    n933700::DAT_010f3364->message(3, 0x29d6a3f5, (char*)buf, ".\\hkCompat_hk461r1_hk500b1.cpp", 0x100);
    os.FUN_00943a60();
}

// @f3 0x00936390 (community match, verified in this file)
namespace f3m_00936390 {
namespace n936390 {
struct Variant;
struct hkBool {
    char b;
    hkBool() {}
    hkBool(bool v) : b(v) {}
    operator bool() const { return b != 0; }
};
struct Accessor {
    void* member; void* object;
    Accessor(Variant& v, const char* name);
    hkBool FUN_0093d640();
    int& FUN_0093d670(int index);
    int& FUN_0093d6b0(int index);
};
}
void __cdecl FUN_00936390(n936390::Variant& oldObj, n936390::Variant& newObj)
{
    n936390::Accessor newData(newObj, "userData");
    n936390::Accessor oldData(oldObj, "userData");
    if (newData.FUN_0093d640() && oldData.FUN_0093d640())
        newData.FUN_0093d670(0) = oldData.FUN_0093d6b0(0);
}
}   // namespace f3m_00936390

// @f3 0x00923c20 (community match, verified in this file)
namespace n923c20 {
extern unsigned long DAT_010f3170;
struct Alloc { void* FUN_008f6d30(int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
int __cdecl FUN_009233f0(const char* s);
void __cdecl FUN_009234e0(void* dst, const void* src, int bytes);
}
struct String923c20 {
    char* data;
    int size;
    int cap;
    String923c20(char* p, int n) { size = n; cap = n; data = p; }
    String923c20 FUN_00923c20(const char* s) const;
};
String923c20 String923c20::FUN_00923c20(const char* s) const
{
    int len = size - 1;
    int slen = n923c20::FUN_009233f0(s);
    n923c20::Alloc* a = n923c20::FUN_00d9b080(n923c20::DAT_010f3170);
    int total = slen + len + 1;
    char* buf = (char*)a->FUN_008f6d30(total, 0x16);
    n923c20::FUN_009234e0(buf, data, len);
    n923c20::FUN_009234e0(buf + len, s, slen + 1);
    return String923c20(buf, total);
}

// @f3 0x00921920 (community match, verified in this file)
extern double DAT_00db38b0;
namespace f3m_00921920 {
namespace task921920 {
extern double __cdecl FUN_00954b60();
extern void __cdecl FUN_00921880(float,float,float,float);
// pdb: hkColor::rgbFromHSV | hkColor.obj | tesv_win, caller_sim, low
void __cdecl FUN_00921920() {
 double range=1.0-DAT_00db38b0;
 float a=(float)(FUN_00954b60()*range+DAT_00db38b0);
 float b=(float)(FUN_00954b60()*range+DAT_00db38b0);
 float c=(float)(FUN_00954b60()*range+DAT_00db38b0);
 FUN_00921880(a,b,c,1.0f);
}
}
}   // namespace f3m_00921920

// @f3 0x00934740 (community match, verified in this file)
extern const char DAT_00e3d120[],DAT_00e450cc[];
namespace f3m_00934740 {
namespace task934740 {
struct Reader { int unk00,unk04; Reader(void*,const char*); bool* FUN_0093d640(bool*); float* FUN_0093d6a0(int); };
void __cdecl FUN_00934740(void* unused,void* object) {
 Reader first(object,DAT_00e3d120),second(object,DAT_00e450cc); bool ok;
 if(*second.FUN_0093d640(&ok) && *first.FUN_0093d640(&ok)) *second.FUN_0093d6a0(0)=*first.FUN_0093d6a0(0);
}
}
}   // namespace f3m_00934740

// @f3 0x00930f40 (community match, verified in this file)
struct CritSec930f40 { int v[6]; };
extern CritSec930f40 DAT_010f3194;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSec930f40* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSec930f40* cs);
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ebd0(void* p);
namespace n930f40 { extern int DAT_010f31f8; extern int DAT_010f3420; }
class FUN_008f7c10 {
public:
    FUN_008f7c10();
    virtual ~FUN_008f7c10();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0089ebd0(p); }
    int m04;
    int m08;
};
class bhkConstraint : public FUN_008f7c10 {
public:
    bhkConstraint() { m0c = 0; ++n930f40::DAT_010f31f8; }
    virtual ~bhkConstraint() {}
    int m0c;
};
class bhkHingeConstraint : public bhkConstraint {
public:
    bhkHingeConstraint() { ++n930f40::DAT_010f3420; }
    virtual ~bhkHingeConstraint() {}
};
struct C930f40 {
    void FUN_008fbc00(bhkConstraint* c, int arg);
    bhkHingeConstraint* FUN_00930f40(int arg);
};
// pdb: bhkHingeConstraint::CreateClone | bhkHingeConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
bhkHingeConstraint* C930f40::FUN_00930f40(int arg)
{
    EnterCriticalSection(&DAT_010f3194);
    bhkHingeConstraint* c = new bhkHingeConstraint;
    FUN_008fbc00(c, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return c;
}

// @f3 0x0092e960 (community match, verified in this file)
namespace f3m_0092e960 {
extern unsigned long DAT_010f3170;
struct Alloc { void* FUN_008f6d30(unsigned int bytes, unsigned int tag) throw(); };
extern "C" __declspec(dllimport) Alloc* __stdcall TlsGetValue(unsigned long);
class Obj {
public:
    virtual void v0();
    unsigned short w4; unsigned short w6;
    Obj() throw() { w6 = 1; }
    static void* operator new(unsigned int n) { Alloc* a = TlsGetValue(DAT_010f3170); void* p = a->FUN_008f6d30(n, 0x15); ((Obj*)p)->w4 = (unsigned short)n; return p; }
};
class Obj2 : public Obj { public: Obj2() throw() {} virtual void v0(); };
// pdb: hkDummySingletoncreate | hkBaseSystem.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Obj* __cdecl hkDummySingletoncreate() { return new Obj2; }
}

// @f3 0x009283d0 (community match, verified in this file)
namespace n9283d0 {
extern unsigned long DAT_010f3170;
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
struct Mem {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void* allocStack(int size) throw();
    virtual void freeStack(void* p) throw();
    char pad[0x1c];
    char* cur;
    int m24;
    char* base;
    char* end;
};
__forceinline void* AllocStack(int bytes) throw()
{
    Mem* m = (Mem*)FUN_00d9b080(DAT_010f3170);
    char* p = m->cur;
    int size = (bytes + 0x10) & ~0xf;
    if (m->cur + size <= m->end) {
        m->cur += size;
        return p;
    }
    return m->allocStack(size);
}
__forceinline void FreeStack(void* p) throw()
{
    Mem* m = (Mem*)FUN_00d9b080(DAT_010f3170);
    m->cur = (char*)p;
    if ((char*)p == m->base)
        m->freeStack(p);
}
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    Array() throw() : data(0), size(0), capAndFlags(0x80000000) {}
    __forceinline void Free() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
template <class T> struct LocalArray : Array<T> {
    T* initial;
    __forceinline LocalArray(int n) throw() {
        this->data = (T*)AllocStack(n * sizeof(T));
        this->capAndFlags = n | 0x80000000;
        initial = this->data;
    }
    __forceinline void Release() throw() { FreeStack(initial); this->Free(); }
};
struct Pair { int a, b; };
struct Collector { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void Collect(void* key, Array<Pair>* out) throw(); };
struct Sink { void FUN_00984cc0(Pair* p, int n) throw(); };
struct World { char p00[0x54]; Collector* collector; Sink* sink; char p5c[0x2f8 - 0x5c]; int count; };
struct Key { char p00[0x24]; int k; };
}
// pdb: hkpWorldOperationUtil::removePhantomBP | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_removePhantomBP(n9283d0::World* w, n9283d0::Key* key)
{
    using namespace n9283d0;
    LocalArray<Pair> arr(w->count);
    w->collector->Collect(&key->k, &arr);
    if (arr.size)
        w->sink->FUN_00984cc0(arr.data, arr.size);
    arr.Release();
}

// @f3 0x00921820 (community match, verified in this file)
namespace f3m_00921820 {
namespace f3m_00921820 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00921820 { char pad[4]; unsigned short w; void FUN_0091f0b0(); O00921820* FUN_00921820(unsigned int flags); };
// pdb: ahkpCharacterProxy::`scalar deleting destructor' | bhkCharacterProxy.obj | fnv360_0822_retail, vtable, high
O00921820* O00921820::FUN_00921820(unsigned int flags) { FUN_0091f0b0(); if (flags & 1) { f3m_00921820::T* t = (f3m_00921820::T*)f3m_00921820::DAT_00d9b080(f3m_00921820::DAT_010f3170); t->FUN_008f6d90(this, w, 0x34); } return this; }
}   // namespace f3m_00921820

// @f3 0x00922200 (community match, verified in this file)
namespace f3m_00922200 {
namespace f3m_00922200 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00922200 { char pad[4]; unsigned short w; void FUN_009a5e50(); O00922200* FUN_00922200(unsigned int flags); };
// pdb: hkpSampledHeightFieldShape::`scalar deleting destructor' | hkpSampledHeightFieldShape.obj | fnv360_0721_beta, vtable_prefix, medium
O00922200* O00922200::FUN_00922200(unsigned int flags) { FUN_009a5e50(); if (flags & 1) { f3m_00922200::T* t = (f3m_00922200::T*)f3m_00922200::DAT_00d9b080(f3m_00922200::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_00922200

// @f3 0x00923200 (community match, verified in this file)
namespace f3m_00923200 {
namespace f3m_00923200 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00923200 { char pad[4]; unsigned short w; void FUN_00943a60(); O00923200* FUN_00923200(unsigned int flags); };
// pdb: hkErrStream::`scalar deleting destructor' | hkError.obj | fnv360_0822_debug, objrun_open, low
O00923200* O00923200::FUN_00923200(unsigned int flags) { FUN_00943a60(); if (flags & 1) { f3m_00923200::T* t = (f3m_00923200::T*)f3m_00923200::DAT_00d9b080(f3m_00923200::DAT_010f3170); t->FUN_008f6d90(this, w, 0x1a); } return this; }
}   // namespace f3m_00923200

// @f3 0x0092b8a0 (community match, verified in this file)
namespace f3m_0092b8a0 {
namespace f3m_0092b8a0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0092b8a0 { char pad[4]; unsigned short w; void FUN_0092b3f0(); O0092b8a0* FUN_0092b8a0(unsigned int flags); };
// pdb: hkpLimitedHingeConstraintData::`scalar deleting destructor' | hkpLimitedHingeConstraintData.obj | fnv360_0822_retail, vtable_prefix, medium
O0092b8a0* O0092b8a0::FUN_0092b8a0(unsigned int flags) { FUN_0092b3f0(); if (flags & 1) { f3m_0092b8a0::T* t = (f3m_0092b8a0::T*)f3m_0092b8a0::DAT_00d9b080(f3m_0092b8a0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2c); } return this; }
}   // namespace f3m_0092b8a0

// @f3 0x009333c0 (community match, verified in this file)
namespace f3m_009333c0 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;

    __declspec(noinline) FUN_0093d600(void* object, const char* name)
    {
        unk00 = object;
        unk04 = 0;
    }

    __declspec(noinline) int* FUN_0093d670(int index)
    {
        return &unk04;
    }

    __declspec(noinline) int* FUN_0093d6d0(int index)
    {
        return &unk04;
    }
};

void __cdecl FUN_009333c0(void* sourceObject, void* destinationObject)
{
    FUN_0093d600 source(sourceObject, "userData");
    FUN_0093d600 destination(destinationObject, "userData");

    int* sourceValue = source.FUN_0093d670(0);
    int* destinationValue = destination.FUN_0093d6d0(0);
    *destinationValue = *sourceValue;
}
}   // namespace f3m_009333c0

// @f3 0x00933c30 (community match, verified in this file)
extern const char DAT_00e3bd18[]; extern double DAT_00dd6570;
namespace f3m_00933c30 {
namespace task933c30 {
struct Convert { unsigned char value; void FUN_0090aba0(float*); };
struct Reader { int unk00,unk04; Reader(void*,const char*); short* FUN_0093d6e0(int); unsigned char* FUN_0093d700(int); };
void __cdecl FUN_00933c30(void* source,void* dest) {
 Reader a(source,DAT_00e3bd18), b(dest,DAT_00e3bd18);
 int n=*a.FUN_0093d6e0(0); float f=(float)(n*DAT_00dd6570);
 Convert c; c.FUN_0090aba0(&f); *b.FUN_0093d700(0)=c.value;
}
}
}   // namespace f3m_00933c30

// @f3 0x0093c0a0 (community match, verified in this file)
namespace f3m_0093c0a0 {
struct Node_0093c0a0 {
    const char* FUN_009b0490();
    Node_0093c0a0* FUN_009b04a0();
};

extern "C" int __cdecl hkString_strCmp(const char* text, const char* key);

unsigned char* __cdecl FUN_0093c0a0(unsigned char* out, Node_0093c0a0* node, const char* key)
{
    if (node) {
        do {
            if (hkString_strCmp(node->FUN_009b0490(), key) == 0)
                break;
            node = node->FUN_009b04a0();
        } while (node);
    }
    *out = node != 0;
    return out;
}
}   // namespace f3m_0093c0a0

// @f3 0x00936480 (community match, verified in this file)
namespace f3m_00936480 {
struct FieldElem16 {
    unsigned short unk00;
    unsigned short unk02;
};
struct FieldRef16 {
    void* unk00;
    int unk04;
    FieldRef16(void* object, const char* name);
    FieldElem16* ElemAt(int index);
};
void FUN_00936480(void* sourceOwner, void* destinationOwner)
{
    FieldRef16 destination(destinationOwner, "flags");
    FieldRef16 source(sourceOwner, "flags");
    unsigned short value = source.ElemAt(0)->unk00;
    destination.ElemAt(0)->unk00 = (unsigned short)((signed char)(value & 0x10)) >> 4;
}
}   // namespace f3m_00936480

// @f3 0x0093cd80 (community match, verified in this file)
extern float DAT_0104da48;
namespace f3m_0093cd80 {
struct Ref93cd80 {
    int unk00;
    int unk04;
    void FUN_0093d620(int first, int second, const char* name);
    bool* FUN_0093d640(bool* out);
    float* FUN_0093d6a0(int index);
};

struct Pair93cd80 {
    int first;
    int second;
};


void __cdecl FUN_0093cd80(int unused, Pair93cd80* pair)
{
    Ref93cd80 ref;
    ref.FUN_0093d620(pair->first, pair->second, "contactRestingVelocity");
    if (*ref.FUN_0093d640((bool*)&pair))
        *ref.FUN_0093d6a0(0) = DAT_0104da48;
}
}   // namespace f3m_0093cd80

// @f3 0x00934f50 (community match, verified in this file)
namespace f3m_00934f50 {
void FUN_00934e00(void* obj, int* a, int* b);
void FUN_00934d80(void* obj, int* a, int* b);

static __declspec(noinline) void FUN_00934e80(FieldRefM& a, FieldRefM& b, void* obj,
                                              void (*fn)(void*, int*, int*))
{
    FieldElemM* eb = b.ElemAt(0);
    FieldElemM* ea = a.ElemAt(0);
    int count = b.ElemAt(1)->count04;
    int* pa = (int*)a.ElemAt(1);
    for (int i = 0; i < count; ++i)
        fn(obj, pa + i, (int*)eb + i + ea->count04);
}

void __cdecl FUN_00934f50(void* a0, void* a1, void* a2)
{
    FUN_00934e80(FieldRefM(a0, "trianglesSubparts"), FieldRefM(a1, "trianglesSubparts"),
                 a2, FUN_00934e00);
    FUN_00934e80(FieldRefM(a0, "shapesSubparts"), FieldRefM(a1, "shapesSubparts"),
                 a2, FUN_00934d80);
}
}   // namespace f3m_00934f50

// @f3 0x0093ce70 (community match, verified in this file)
extern char DAT_00e73da0[];
extern char DAT_00e3f9c0[];
extern char DAT_00e3f9a8[];
namespace f3m_0093ce70 {
struct RefObj93600 {
    void* unk00;
    int unk04;
    RefObj93600(void* obj, const char* fieldName);
    short* FUN_0093d6b0(int index);
    short* FUN_0093d6e0(int index);
};

void __cdecl FUN_0093e480(void* first, const char* firstName, void* second, const char* secondName);

// pdb: hkbDetectCloseToGroundModifier::isValid | hkbDetectCloseToGroundModifier.obj | tesv_win, ustr, medium
void __cdecl FUN_0093ce70(void* first, void* second)
{
    FUN_0093e480(first, DAT_00e73da0, second, DAT_00e3f9c0);
    RefObj93600 source(first, DAT_00e3f9a8);
    RefObj93600 target(second, DAT_00e3f9a8);
    *target.FUN_0093d6e0(0) = *source.FUN_0093d6b0(0);
}
}   // namespace f3m_0093ce70

// @f3 0x0092f290 (community match, verified in this file)
namespace f3m_0092f290 {
struct PtrArray {
    void** data;
    int count;
    unsigned int capacityAndFlags;
};

void __cdecl FUN_00901f10(PtrArray* arr, int stride);

struct Owner {
    int unk00, unk04, unk08, unk0C, unk10;
    PtrArray array14;
    void hkDefaultError_sectionBegin(void* value, int unk);
};

// pdb: hkDefaultError::sectionBegin | hkDefaultError.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_open), high
void Owner::hkDefaultError_sectionBegin(void* value, int unk)
{
    PtrArray* arr = &array14;
    if (arr->count == (int)(arr->capacityAndFlags & 0x3fffffff))
        FUN_00901f10(arr, 4);
    arr->data[arr->count] = value;
    arr->count++;
}
}   // namespace f3m_0092f290

// @f3 0x009229f0 (community match, verified in this file)
namespace f3m_009229f0 {
struct Map922b {
    __int64* m_table;
    int m_flags;
    int m_mask;
    int FUN_009229f0(unsigned __int64 key);
};

// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::findKey | hkMap.obj | fnv360_0822_retail, call_gap, high
// pdb params: key
int Map922b::FUN_009229f0(unsigned __int64 key)
{
    unsigned __int64 i;
    for (i = ((key >> 4) * 2654435761U) & m_mask; m_table[i] != -1; i = (i + 1) & m_mask)
    {
        if (m_table[i] == key)
            return (int)i;
    }
    return m_mask + 1;
}
}   // namespace f3m_009229f0

// @f3 0x00922cb0 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_00922cb0 {
struct Alloc;
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(int);

struct Alloc {
    void* FUN_008f6d30(unsigned int size, int tag);
};

class Table {
public:
    void* entries;  // 00
    int size;       // 04
    int mask;       // 08
    void FUN_00922680();
    Table* FUN_00922cb0();
};

// pdb: hkMultiMap<unsigned long,unsigned long,struct hkMultiMapOperations<unsigned long>,struct hkContainerHeapAllocator>::clear | hkMultiMap.obj | tesv_win, call_gap, low
Table* Table::FUN_00922cb0()
{
    Alloc* al = FUN_00d9b080(DAT_010f3170);
    void* block = al->FUN_008f6d30(0x80, 0x17);
    entries = block;
    size = 0;
    mask = 0xf;
    FUN_00922680();
    return this;
}
}   // namespace f3m_00922cb0

// @f3 0x0092a640 (community match, verified in this file)
struct ElemArray16 {
    int unk00;
    void* data;
    int size;
    unsigned int capAndFlags;
};

class MemoryManager {
public:
    void* Allocate(unsigned int size);
};

extern MemoryManager g_memoryManager;

struct Owner16 {
    int unk00;
    int unk04;
    void* unk08;
    ElemArray16* unk0C;
    ElemArray16* FUN_0092a640(unsigned char* created);
    void FUN_0092a1a0(ElemArray16* source);
};

// pdb: bhkMultiSphereShape::KillCinfo | bhkMultiSphereShape.obj | fnv360_0822_debug, objrun_sim, low, conflict (bridge: bhkMultiSphereShape::CreateCinfo)
// pdb params: abCreated
ElemArray16* Owner16::FUN_0092a640(unsigned char* created)
{
    if (!unk0C) {
        ElemArray16* p = (ElemArray16*)g_memoryManager.Allocate(sizeof(ElemArray16));
        if (p) {
            p->unk00 = 0;
            p->data = 0;
            p->size = 0;
            p->capAndFlags = 0x80000000;
        } else
            p = 0;
        unk0C = p;
        if (unk08)
            FUN_0092a1a0(p);
        *created = 1;
    } else {
        *created = 0;
    }
    return unk0C;
}

// @f3 0x0092f2d0 (community match, verified in this file)
extern int FUN_00dcc494;
namespace f3m_0092f2d0 {
using namespace f3m_0092a520;
struct SubobjQ { int unk00; int unk04; int unk08; void FUN_00922cf0(); };
struct ZFUN {
    void* vtable;
    unsigned short count04;
    unsigned short unk06;
    SubobjQ sub08;
    int* data14;
    int size18;
    unsigned int cap1c;
    int unk20;
    ZFUN* FUN_0092f2d0(unsigned int flags);
};
// pdb: hkDefaultError::`scalar deleting destructor' | hkDefaultError.obj | fnv360_0822_retail, vtable, high
ZFUN* ZFUN::FUN_0092f2d0(unsigned int flags) {
    Alloc* (__stdcall *allocator)(int) = &f3m_0092a520::FUN_00d9b080;
    int signedCap = cap1c;
    unsigned int n;
    Alloc* al;
    if (cap1c & 0x80000000u) goto afterArray;
    n = cap1c & 0x3fffffff;
    al = allocator(DAT_010f3170);
    al->FUN_008f6d90(data14, n << 2, 0x17);
    afterArray: ;
    sub08.FUN_00922cf0();
    vtable = &FUN_00dcc494;
    if (flags & 1) {
        al = allocator(DAT_010f3170);
        al->FUN_008f6d90(this, count04, 0x15);
    }
    return this;
}
}   // namespace f3m_0092f2d0

// @f3 0x00922cf0 (community match, verified in this file)
namespace f3m_00922cf0 {
struct Heap1048 { void FUN_008f6d90(void* data, unsigned int bytes, int tag); };
typedef Heap1048* (__stdcall *GetTls1048)(unsigned long index);
extern GetTls1048 DAT_00d9b080;
extern unsigned long DAT_010f3170;
struct Owner1048 { void* data00; unsigned int flags04; int count08; void FUN_00922cf0(); };
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::clearAndDeallocate | hkMap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: alloc
void Owner1048::FUN_00922cf0() {
    if (!(flags04 & 0x80000000u)) {
        int words = count08 * 2 + 2;
        void* data = data00;
        Heap1048* heap = DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(data, words * 4, 0x17);
    }
}
}   // namespace f3m_00922cf0

// @f3 0x00926df0 (community match, verified in this file)
namespace f3m_00926df0 {
struct Sub { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
  virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
  virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
  virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
  virtual void v40(const void* a); virtual void v44(const void* a); };
struct Child { int unk00; };
struct Item {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    unsigned short unk20; unsigned short unk22; unsigned short unk24; unsigned char unk26; unsigned char unk27;
    int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    float unk44; Child** unk48; int unk4c;
};
struct PtrArr { Item** data; unsigned int count; unsigned int cap; };
struct Mgr {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24;
    Item** unk28; int unk2c; int unk30; Item** unk34; unsigned int unk38; unsigned int unk3c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    float unk190;
    void hkpWorld_checkDeterminism();
};
extern const char DAT_01092a50[];
bool FUN_009a9ba0(float* a, Child** b, int n, int sz);
void FUN_00901f10(PtrArr* a, int n);
void hkSweptTransformUtil_freezeMotionState(float f, void* p);
void hkpWorldCallbackUtil_fireIslandDeactivated(Mgr* m, Item* i);

// pdb: hkpWorldOperationUtil::internalDeactivateIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, objrun, medium
// pdb params: world, island
void FUN_00926df0(Mgr* mgr, Item* item)
{
    Child** p = item->unk48; int n = item->unk4c;
    if (!FUN_009a9ba0(&mgr->unk190, p, n, 0xd0)) {
        item->unk26 = (item->unk26 & 0xf7) | 4;
        return;
    }
    PtrArr* a = (PtrArr*)&mgr->unk34;
    if (a->count == (a->cap & 0x3fffffff))
        FUN_00901f10(a, 4);
    a->data[a->count] = item;
    a->count++;
    PtrArr* fl = (PtrArr*)&mgr->unk28;
    fl->data[item->unk20] = fl->data[fl->count - 1];
    fl->data[(unsigned short)item->unk20]->unk20 = item->unk20;
    fl->count--;
    item->unk20 = (unsigned short)mgr->unk38 - 1;
    item->unk26 &= 0xfc;
    item->unk44 = mgr->unk190;
    for (int i = 0; i < item->unk4c; i++) {
        Child* c = item->unk48[i];
        hkSweptTransformUtil_freezeMotionState(item->unk44, (char*)c + 0xe0);
        Sub* s = (Sub*)((char*)c + 0xd0);
        s->v40(DAT_01092a50);
        s->v44(DAT_01092a50);
    }
    hkpWorldCallbackUtil_fireIslandDeactivated(mgr, item);
    mgr->hkpWorld_checkDeterminism();
}
}   // namespace f3m_00926df0

// @f3 0x0092c920 (community match, verified in this file)
namespace n92c920 {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
extern void (__stdcall* const DAT_00e370b0)(void* p);
}
struct FUN_0092c920 {
    void* data;
    int size;
    int cap;
    virtual ~FUN_0092c920();
    static void* operator new(unsigned int n);
    // pdb: BSSimpleArray<enum hkpConstraintData::ConstraintType,1024>::`scalar deleting destructor' | bhkRagdollTemplate.obj | fnv360_0721_beta, objrun_open, low
    static void operator delete(void* p) { n92c920::DAT_01090a78.FUN_0086ba60(p); }
};
FUN_0092c920::~FUN_0092c920()
{
    if (data) {
        n92c920::DAT_00e370b0(data);
        data = 0;
        cap = 0;
        size = 0;
    }
}
void* Make92c920() { return new FUN_0092c920; }

// @f3 0x0092ed90 (community match, verified in this file)
namespace f3m_0092ed90 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag); };
extern "C" __declspec(dllimport) Heap* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
struct FUN_0092ed90 {
    unsigned short size;
    virtual ~FUN_0092ed90();
    // pdb: hkDefaultBuiltinTypeRegistry::`scalar deleting destructor' | hkBuiltinTypeRegistry.obj | fnv360_0721_beta, vtable_prefix, medium
    void operator delete(void* p) {
        Heap* h = TlsGetValue(DAT_010f3170);
        h->FUN_008f6d90(p, ((FUN_0092ed90*)p)->size, 0x15);
    }
};
FUN_0092ed90::~FUN_0092ed90() {}
}

// @f3 0x009226b0 (community match, verified in this file)
namespace f3m_009226b0 {
namespace f3m_009226b0 {

struct Pair {
    int key;
    int value;
};

struct Map {
    Pair* elem;
    int numElems;
    int hashMod;

    Map(void* buffer, unsigned int sizeInBytes);
};

// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > | hkMap.obj | fnv360_0822_retail, call_gap, high
// pdb params: ptr, sizeInBytes
Map::Map(void* buffer, unsigned int sizeInBytes) {
    int capacity = sizeInBytes / (2 * sizeof(Pair));
    elem = (Pair*)buffer;
    numElems = 0x80000000;
    hashMod = capacity - 1;
    for (int i = 0; i < capacity; ++i) {
        Pair* p = elem;
        p[i].key = -1;
        p[i].value = -1;
    }
}

}
}   // namespace f3m_009226b0

// @f3 0x0092e8c0 (community match, verified in this file)
namespace f3m_0092e8c0 {
namespace f3m_0092e8c0 {
extern void (__cdecl* DAT_00f7b4d0)(void* p);
class FUN_0092e8c0 {
public:
    __declspec(noinline) virtual ~FUN_0092e8c0();
    static void operator delete(void* p) { DAT_00f7b4d0(p); }
};
FUN_0092e8c0::~FUN_0092e8c0() {}
}
}   // namespace f3m_0092e8c0

// @f3 0x0092f340 (community match, verified in this file)
namespace f3m_0092f340 {
namespace character_state_manager_ctor {
struct hkBaseObject { virtual ~hkBaseObject() throw(); };
struct hkReferencedObject : hkBaseObject { unsigned short memorySizeAndFlags,referenceCount; __forceinline hkReferencedObject() throw():referenceCount(1){} };
struct hkpCharacterState;
struct hkpCharacterStateManager : hkReferencedObject {
 hkpCharacterState *unk08,*unk0C,*unk10,*unk14,*unk18,*unk1C,*unk20,*unk24,*unk28,*unk2C,*unk30;
 hkpCharacterStateManager() throw();
};
// pdb: hkpCharacterStateManager::hkpCharacterStateManager | hkpCharacterStateManager.obj | fnv360_0822_retail, callee_sim, high
hkpCharacterStateManager::hkpCharacterStateManager() throw() { unk08=0;unk0C=0;unk10=0;unk14=0;unk18=0;unk1C=0;unk20=0;unk24=0;unk28=0;unk2C=0;unk30=0; }
}
}   // namespace f3m_0092f340

// @f3 0x0092b840 (community match, verified in this file)
namespace f3m_0092b840 {
namespace constraint_atom_defaults {
struct __declspec(align(16)) Vector4 { float x,y,z,w; };
struct __declspec(align(16)) Matrix3 { Vector4 column0,column1,column2; };
struct __declspec(align(16)) Transform { Matrix3 rotation;Vector4 translation; };
struct __declspec(align(16)) LocalTransformsAtom {
 unsigned short type,unk02;unsigned int unk04,unk08,unk0C;
 Transform transformA,transformB;
 __forceinline LocalTransformsAtom() : type(2) {}
};
struct ConstraintAtom { unsigned short type;__forceinline ConstraintAtom(unsigned short value):type(value){} };
struct Enabled { bool value;__forceinline Enabled(bool initial):value(initial){} };
struct ControlAtom : ConstraintAtom {

 Enabled enabled;
 unsigned char unk03;
 unsigned short unk04;
 unsigned short unk06;
 unsigned int unk08;
 unsigned int unk0C;
 unsigned int unk10;
 __forceinline ControlAtom() : ConstraintAtom(18),enabled(true) { unk04=0;unk06=0; }
};
struct ConstraintAtoms {
 LocalTransformsAtom transforms;
 ControlAtom control;
 unsigned short unk0A4;
 unsigned char unk0A6;
 unsigned char unk0A7;
 unsigned char unk0A8;
 unsigned char unk0A9;
 unsigned short unk0AA;
 unsigned int unk0AC;
 unsigned short unk0B0;
 unsigned char unk0B2;
 unsigned char unk0B3;
 unsigned int unk0B4;
 unsigned int unk0B8;
 unsigned int unk0BC;
 unsigned short unk0C0;
 unsigned short unk0C2;
 unsigned short unk0C4;
 ConstraintAtoms();
};
// pdb: hkpLimitedHingeConstraintData::Atoms::Atoms | hkpLimitedHingeConstraintData.obj | fnv360_0822_retail, call_seq, high
ConstraintAtoms::ConstraintAtoms() {
 unk0A4=17;
 unk0A6=1;
 unk0A8=1;
 unk0B0=14;
 unk0B2=1;
 unk0C0=12;
 unk0C4=5;
}
}
}   // namespace f3m_0092b840

// @f3 0x0092f710 (community match, verified in this file)
namespace f3m_0092f710 {
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
namespace Task1285 {
struct Context {
unsigned unk000;
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
unsigned unk020;
unsigned unk024;
unsigned unk028;
unsigned unk02c;
unsigned unk030;
unsigned unk034;
unsigned unk038;
unsigned unk03c;
unsigned unk040;
unsigned unk044;
unsigned unk048;
unsigned unk04c;
unsigned unk050;
unsigned unk054;
unsigned unk058;
unsigned unk05c;
unsigned unk060;
unsigned unk064;
unsigned unk068;
unsigned unk06c;
unsigned unk070;
unsigned unk074;
unsigned unk078;
unsigned unk07c;
unsigned unk080;
unsigned unk084;
unsigned unk088;
unsigned unk08c;
unsigned unk090;
unsigned unk094;
unsigned unk098;
unsigned unk09c;
unsigned unk0a0;
unsigned unk0a4;
unsigned unk0a8;
unsigned unk0ac;
unsigned unk0b0;
unsigned unk0b4;
unsigned unk0b8;
unsigned unk0bc;
unsigned unk0c0;
unsigned unk0c4;
unsigned unk0c8;
unsigned unk0cc;
unsigned unk0d0;
unsigned unk0d4;
unsigned unk0d8;
unsigned unk0dc;
unsigned unk0e0;
unsigned unk0e4;
unsigned unk0e8;
unsigned unk0ec;
unsigned unk0f0;
unsigned unk0f4;
unsigned unk0f8;
unsigned unk0fc;
unsigned unk100;
unsigned unk104;
unsigned unk108;
unsigned unk10c;
unsigned unk110;
unsigned unk114;
unsigned unk118;
unsigned unk11c;
unsigned unk120;
unsigned unk124;
unsigned unk128;
unsigned unk12c;
unsigned unk130;
unsigned unk134;
unsigned unk138;
unsigned unk13c;
unsigned unk140;
unsigned unk144;
unsigned unk148;
unsigned unk14c;
unsigned unk150;
unsigned unk154;
unsigned unk158;
unsigned unk15c;
unsigned unk160;
unsigned unk164;
unsigned unk168;
unsigned unk16c;
unsigned unk170;
unsigned unk174;
unsigned unk178;
unsigned unk17c;
unsigned unk180;
unsigned unk184;
unsigned unk188;
unsigned unk18c;
unsigned unk190;
unsigned unk194;
unsigned unk198;
unsigned unk19c;
unsigned unk1a0;
unsigned unk1a4;
unsigned unk1a8;
unsigned unk1ac;
unsigned unk1b0;
unsigned unk1b4;
unsigned unk1b8;
unsigned unk1bc;
unsigned unk1c0;
unsigned unk1c4;
unsigned unk1c8;
unsigned unk1cc;
unsigned unk1d0;
unsigned unk1d4;
unsigned unk1d8;
unsigned unk1dc;
unsigned unk1e0;
unsigned char unk1e4,byteOrder1e5;
};
struct Data {
unsigned long value00;
unsigned long value04;
unsigned long value08;
unsigned long value0c;
unsigned long value10;
unsigned long value14;
unsigned long value18;
unsigned long value1c;
unsigned long value20;
unsigned long value24;
};
struct Reader {
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
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual Data* Get(Context**);
 void FUN_008f88e0(Context*);
 void FUN_0092f710(Context*);
};
// pdb: bhkLiquidAction::LoadBinary | bhkLiquidAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Reader::FUN_0092f710(Context* volatile context) {
 Context* original=context;
 FUN_008f88e0(original);
 if(original->byteOrder1e5!=1) {
  volatile Data* p=Get((Context**)&context);
  if(p) {
p->value08=_byteswap_ulong(p->value08);
p->value0c=_byteswap_ulong(p->value0c);
p->value10=_byteswap_ulong(p->value10);
p->value14=_byteswap_ulong(p->value14);
  }
 }
}
}
}   // namespace f3m_0092f710

// @f3 0x0092aac0 (community match, verified in this file)
namespace f3m_0092aac0 {
namespace task1291 {
struct LinkedObject
{
    int unk00, unk04;
    int m_iValue;  // +0x08
};

struct LinkStream
{
    LinkedObject* FUN_0082a280();
};

struct LandTextureParameters
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44;
    int m_iValue;  // +0x48
};

class LinkBase
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual LandTextureParameters* GetHavokData(char& rcFlag);  // +0xb4
    void FUN_008f7ec0(LinkStream& kStream);                     // base LinkObject
};

class LinkWrapper : public LinkBase
{
  public:
    void FUN_0092aac0(LinkStream& kStream);
};

// @fnv 0x00cac030
// pdb: bhkCharacterProxy::LinkObject | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void LinkWrapper::FUN_0092aac0(LinkStream& kStream)
{
    LinkedObject* pkObject = kStream.FUN_0082a280();
    char cFlag;
    LandTextureParameters* pkData = GetHavokData(cFlag);
    if (pkData && pkObject)
        pkData->m_iValue = pkObject->m_iValue;
    LinkBase::FUN_008f7ec0(kStream);
}

}
}   // namespace f3m_0092aac0

// @f3 0x00932670 (community match, verified in this file)
namespace f3m_00932670 {
extern unsigned long DAT_010f3170;
extern int DAT_011693a8; extern int DAT_011693a0; extern int DAT_011693a4;
struct Alloc { void* FUN_008f6d30(unsigned int bytes, unsigned int tag) throw(); };
extern "C" __declspec(dllimport) Alloc* __stdcall TlsGetValue(unsigned long);
class Obj {
public:
    int a0; unsigned short w4, w6;
    Obj() throw();
    static void* operator new(unsigned int n) { Alloc* a = TlsGetValue(DAT_010f3170); void* p = a->FUN_008f6d30(n, 0x15); ((Obj*)p)->w4 = (unsigned short)n; return p; }
};
// pdb: hkDataArrayImpl::`scalar deleting destructor' | hkDataObjectNative.obj | fnv360_0822_debug, objrun_open, low
Obj* __cdecl FUN_00932670() { if (DAT_011693a8 && DAT_011693a0 && DAT_011693a4) return new Obj; return 0; }
}

// @f3 0x00936300 (community match, verified in this file)
namespace f3m_00936300 {
namespace f3m_00936300 {
struct Pair_00936300 {
    int a;
    int b;
    Pair_00936300() {}
};
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    Pair_00936300 FUN_0093d810();
};
Pair_00936300 __cdecl FUN_00936250(const Pair_00936300& b, int c);
}
using namespace f3m_00936300;

void __cdecl FUN_00936300(void* objA, void* objB, int arg)
{
    FUN_0093d600 lockA(objA, "multithreadLock");
    FUN_0093d600 lockB(objB, "multithreadLock");
    lockA.FUN_0093d810();
    lockA.FUN_0093d810();
    Pair_00936300 p;
    p.a = lockB.FUN_0093d810().a;
    p.b = lockB.FUN_0093d810().b;
    FUN_00936250(p, arg);
}
}   // namespace f3m_00936300

// @f3 0x00933150 (community match, verified in this file)
namespace f3m_00933150 {
namespace f3m_00933150 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    int* FUN_0093d670(int index);
    short* FUN_0093d6b0(int index);
    short* FUN_0093d6e0(int index);
};
}
using namespace f3m_00933150;

void __cdecl FUN_00933150(void* src, void* dst)
{
    {
        FUN_0093d600 from(src, "savedMotion");
        FUN_0093d600 to(dst, "savedMotion");
        *to.FUN_0093d670(0) = *from.FUN_0093d670(0);
    }
    {
        FUN_0093d600 from(src, "savedQualityTypeIndex");
        FUN_0093d600 to(dst, "savedQualityTypeIndex");
        *to.FUN_0093d6e0(0) = *from.FUN_0093d6b0(0);
    }
}
}   // namespace f3m_00933150

// @f3 0x00935e10 (community match, verified in this file)
namespace f3m_00935e10 {
void __cdecl FUN_00923500(void* destination, int fill, int bytes);

int __cdecl FUN_00935e10(SpanSource* source, int length, unsigned char fill, ByteBuffer* buffer, int offset, OffsetList* offsets)
{
    DataSpan* span = source->FUN_0093d650();
    int aligned = (length + 3) & ~3;
    int required = buffer->size + aligned;
    int capacity = buffer->capacityAndFlags & 0x3fffffff;
    if (capacity < required) {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        FUN_00901e90(buffer, newCapacity, 1);
    }
    buffer->size = required;
    if (span->length == length)
        FUN_009234e0(buffer->data + offset, span->data, length);
    else
        FUN_00923500(buffer->data + offset, fill, length);
    *offsets->FUN_0093d6b0(0) = offset;
    return aligned;
}
}   // namespace f3m_00935e10

// @f3 0x00924ed0 (community match, verified in this file)
namespace f3m_00924ed0 {
struct Matrix924 { float row[4][4]; void FUN_00924ed0(float*); };
// pdb: hkTransform::get4x4ColumnMajor | hkTransform.obj | tesv_win, call_gap, low
void Matrix924::FUN_00924ed0(float* out) { for(int i=0;i<4;++i) { out[0]=row[i][0]; out[1]=row[i][1]; out[2]=row[i][2]; out[3]=0.0f; out+=4; } out[-1]=1.0f; }
}   // namespace f3m_00924ed0

// @f3 0x00936e40 (community match, verified in this file)
extern short DAT_0105f574;
namespace f3m_00936e40 {
namespace f3m_00936e40 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
};
}
using namespace f3m_00936e40;
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00936e40(void* obj, char value)
{
    if (DAT_0105f574 == -1)
        DAT_0105f574 = FUN_00936710(obj, "TYPE_2D_ANG");
    {
        FUN_0093d600 type(obj, "type");
        *type.FUN_0093d6e0(0) = DAT_0105f574;
    }
    {
        FUN_0093d600 axis(obj, "freeRotationAxis");
        *axis.FUN_0093d710(0) = value;
    }
}
void* volatile g_obj_936e40; volatile char g_v_936e40;
void caller_of_FUN_00936e40() { FUN_00936e40(g_obj_936e40, g_v_936e40); }
}   // namespace f3m_00936e40

// @f3 0x00926f00 (community match, verified in this file)
namespace f3m_00926f00 {
namespace f3m_00926f00 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Child { char pad[0x22]; unsigned short idx; char pad2[2]; unsigned char flags; };
struct Arr {
    Child** data; int size; unsigned int capFlags;
    void Push(Child* c) {
        if (size == (int)(capFlags & 0x3fffffff)) FUN_00901f10(this, 4);
        data[size] = c;
        size = size + 1;
    }
};
struct Owner { char pad[0x40]; Arr arr; };
// pdb: hkpWorldOperationUtil::markIslandInactive | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_markIslandInactive(Owner* o, Child* c) {
    c->flags &= 0xf3;
    if (c->idx == 0xffff) {
        c->idx = (unsigned short)o->arr.size;
        o->arr.Push(c);
    }
}
}
}   // namespace f3m_00926f00

// @f3 0x00931360 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_00931360 {
namespace f3m_00931360 {
struct Mem_1360 {
    void* FUN_008f6d30(int bytes, int tag);
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Mem_1360* __stdcall FUN_00d9b080(int);

class FUN_00930c40 {
public:
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    char pad08[0xb0 - 8];

    FUN_00930c40();
    static void* operator new(unsigned int size)
    {
        Mem_1360* mem = FUN_00d9b080(DAT_010f3170);
        FUN_00930c40* p = (FUN_00930c40*)mem->FUN_008f6d30(size, 0x2c);
        p->memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p, unsigned int size)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, size, 0x2c);
    }
};
struct Owner_1360 {
    int unk00;
    FUN_00930c40* obj;
    int FUN_00931360();
};
}
using namespace f3m_00931360;

// pdb: hkHingeConstraintCinfo::CreateData | bhkHingeConstraint.obj | fnv360_0822_retail, call_gap_sim, low
int Owner_1360::FUN_00931360()
{
    if (!obj)
        obj = new FUN_00930c40();
    return sizeof(FUN_00930c40);
}
}   // namespace f3m_00931360

// @f3 0x0092e340 (community match, verified in this file)
namespace f3m_0092e340 {
namespace f3m_0092e340 {
struct Vector4_e340 {
    float x, y, z, w;
    void setZero4() { x = y = z = w = 0.0f; }
};
struct Array_e340 {
    void* data;
    int size;
    int capacityAndFlags;
    Array_e340() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
class FUN_009ae990 {
public:
    virtual ~FUN_009ae990();
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    void* world;
    void* island;
    const char* name;
    void* entity;
    int unk1c;
    FUN_009ae990(void* entity, int userData);
};
class FUN_0092e340 : public FUN_009ae990 {
public:
    Vector4_e340 positionInRbLocal;
    Vector4_e340 mousePositionInWorld;
    float springDamping;
    float springElasticity;
    float maxRelativeForce;
    float objectDamping;
    int shapeKey;
    Array_e340 applyCallbacks;
    FUN_0092e340(void* rb);
    virtual ~FUN_0092e340();
};
}
using namespace f3m_0092e340;

// pdb: hkpMouseSpringAction::hkpMouseSpringAction | hkpMouseSpringAction.obj | fnv360_0822_retail, objrun, medium
// pdb params: rb
FUN_0092e340::FUN_0092e340(void* rb)
    : FUN_009ae990(rb, 0), springDamping(0.5f), springElasticity(0.3f), maxRelativeForce(250.0f), objectDamping(0.95f)
{
    positionInRbLocal.setZero4();
    mousePositionInWorld.setZero4();
    shapeKey = -1;
    name = "hkpMouseSpringAction";
}
}   // namespace f3m_0092e340

// @f3 0x0092b2e0 (community match, verified in this file)
namespace f3m_0092b2e0 {
struct Ref_92b2e0 { virtual void Del(int f); unsigned short w4; short w6; };
struct O_92b2e0 {
    char pad[0xb0]; Ref_92b2e0* p;
    void FUN_0092b2e0(Ref_92b2e0* r);
};
// pdb: hkpLimitedHingeConstraintData::setMotor | hkpLimitedHingeConstraintData.obj | fnv360_0721_beta, call_gap, low, conflict (skyrim: hkpLimitedHingeConstraintData::setMotorActive)
// pdb params: motor
void O_92b2e0::FUN_0092b2e0(Ref_92b2e0* r) {
    if (r && r->w4) r->w6++;
    Ref_92b2e0* old = p;
    if (old && old->w4) {
        --old->w6;
        if ((unsigned short)old->w6 == 0) old->Del(1);
    }
    p = r;
}
}   // namespace f3m_0092b2e0

// @f3 0x009316b0 (community match, verified in this file)
namespace f3m_009316b0 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct Critical931 {int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;int unk18;int unk1C;};
struct Parent931 {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; Critical931* critical;};
struct Owner931 {int unk00;int unk04;Parent931* parent;void FUN_009316b0(int);};
void Owner931::FUN_009316b0(int){if(parent){Critical931* c=parent->critical;if(c){c->unk18=-1;c->unk1C=-1;LeaveCriticalSection(c);}}}
}   // namespace f3m_009316b0

// @f3 0x0092acf0 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_0092acf0 {
namespace f3m_0092acf0 {
struct Mem_acf0 {
    void* FUN_008f6d30(int bytes, int tag);
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Mem_acf0* __stdcall FUN_00d9b080(int);
}
using namespace f3m_0092acf0;
class FUN_0092a8f0 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    char pad08[0xd0 - 8];
    FUN_0092a8f0(void* arg);
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
    static void* operator new(unsigned int size)
    {
        Mem_acf0* mem = FUN_00d9b080(DAT_010f3170);
        FUN_0092a8f0* p = (FUN_0092a8f0*)mem->FUN_008f6d30(size, 0x34);
        p->memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p, unsigned int size)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, size, 0x34);
    }
};
namespace f3m_0092acf0 {
class Owner_acf0 {
public:
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
    virtual void AddObj(class FUN_0092a8f0* obj);
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
    virtual void Finish(void* arg);
    void FUN_0092acf0(void* arg);
};
}
// pdb: bhkCharacterProxy::Init | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
void Owner_acf0::FUN_0092acf0(void* arg)
{
    FUN_0092a8f0* obj = new FUN_0092a8f0(arg);
    AddObj(obj);
    obj->removeReference();
    Finish(arg);
}
}   // namespace f3m_0092acf0

// @f3 0x00923ae0 (community match, verified in this file)
namespace f3m_00923ae0 {
namespace f3m_00923ae0 {
struct Str_3ae0 {
    char* data;
    int size;
};
struct Offsets_3ae0 {
    int* data;
    int size;
};
}
using namespace f3m_00923ae0;

void __cdecl FUN_00923ae0(char* dst, const char* src, int srcLen, Str_3ae0* from, Str_3ae0* to, Offsets_3ae0* offsets)
{
    int srcPos = 0;
    int dstPos = 0;
    int fromLen = from->size - 1;
    int toLen = to->size - 1;
    for (int i = 0; i < offsets->size; i++) {
        int len;
        if (i == 0)
            len = offsets->data[0];
        else
            len = offsets->data[i] - offsets->data[i - 1] - fromLen;
        FUN_009234e0(dst + dstPos, src + srcPos, len);
        dstPos += len;
        srcPos += len + fromLen;
        FUN_009234e0(dst + dstPos, to->data, toLen);
        dstPos += toLen;
    }
    int len = srcLen - offsets->data[offsets->size - 1] - fromLen;
    FUN_009234e0(dst + dstPos, src + srcPos, len);
}
}   // namespace f3m_00923ae0

// @f3 0x009348e0 (community match, verified in this file)
extern unsigned DAT_00e3e5a4;
namespace f3m_009348e0 {
struct C934Vector {float x,y,z,w;};
struct C934Pair { C934Vector first,second; };
struct C934Handle {void* object;void* type;void FUN_0093d600(void*,const void*);void* FUN_0093d660();};
void __cdecl FUN_009348e0(void* a,void* b) {
    C934Handle source,dest;
    source.FUN_0093d600(a,&DAT_00e3e5a4);
    dest.FUN_0093d600(b,&DAT_00e3e5a4);
    C934Vector* from=(C934Vector*)source.FUN_0093d660();
    C934Pair* to=(C934Pair*)dest.FUN_0093d660();
    to->first.x=from->x;to->first.y=from->y;to->first.z=from->z;to->first.w=from->w;
    to->second.x=from->x;to->second.y=from->y;to->second.z=from->z;to->second.w=from->w;
}
}   // namespace f3m_009348e0

// @f3 0x009377f0 (community match, verified in this file)
extern short DAT_0105f548;
extern short DAT_0105f5a0;
namespace f3m_009377f0 {
namespace f3m_009377f0 {
struct Target_77f0 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int size);
};
short __cdecl FUN_00936710(const char* name);
struct Pair_77f0 {
    int a;
    int b;
    Pair_77f0() {}
};
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600() {}
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
    FUN_0093d600 FUN_0093d7a0(const char* name);
    Pair_77f0 FUN_0093d810();
};
short __cdecl FUN_00936690(FUN_0093d600* acc);
static __declspec(noinline) short FUN_009366b0(FUN_0093d600* acc)
{
    return FUN_00936690(acc);
}
static __declspec(noinline) void FUN_00936750(void* obj, int value, Target_77f0* target)
{
    int* pv = &value;
    if (DAT_0105f548 == -1)
        DAT_0105f548 = FUN_00936710("TYPE_BRIDGE");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f548;
    FUN_0093d600 data(obj, "constraintData");
    *data.FUN_0093d670(0) = value;
    target->Set(value, data.FUN_0093d660());
}
}
using namespace f3m_009377f0;

void __cdecl FUN_009377f0(int a1, int* obj, Target_77f0* target)
{
    FUN_0093d600 atoms(obj, "atoms");
    if (DAT_0105f5a0 == -1)
        DAT_0105f5a0 = FUN_009366b0(&atoms);
    FUN_00936750(&atoms.FUN_0093d7a0("bridgeAtom").FUN_0093d810(), *obj, target);
}
}   // namespace f3m_009377f0

// @f3 0x009319e0 (community match, verified in this file)
extern int DAT_00e35ae4;
namespace f3m_009319e0 {
namespace w9319e0 {
struct Embedded { int unk00; unsigned char unk04; signed char offset; short unk06; int unk08; void SetOwner(void* p) { offset=(char*)((char*)p)-(char*)this; } };
struct Part { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; void FUN_009afea0(); };
struct Body { int unk00; int unk04; int unk08; int unk0c; signed char offset; unsigned char unk11,unk12,unk13; Embedded embedded; Part part; void* data; int count,capacity; __forceinline void Init(int setOwner) { part.FUN_009afea0(); if(setOwner) embedded.SetOwner(this); data=0; count=0; capacity=0x80000000; } void SetOwner(void* p) { offset=(char*)p-(char*)this; } };
struct Owner { void* table; short unk04,flags; int unk08,unk0c; Body body; int unk68; short unk6c; Owner* FUN_009319e0(int); };
Owner* Owner::FUN_009319e0(int setOwner) {
 flags=1; table=&DAT_00e35ae4; body.Init(setOwner); unk68=-47; unk6c=0;
 if(setOwner) body.SetOwner(this);
 return this;
}
}
}   // namespace f3m_009319e0

// @f3 0x00934440 (community match, verified in this file)
extern const char DAT_00e63c90[],DAT_00e3e8b0[],DAT_00e63c6c[],DAT_00e3e898[];
namespace f3m_00934440 {
struct FieldReference {void* object;int index;void FUN_0093d600(void*,const char*);float* FUN_0093d6a0(int);};
void FUN_00934440(void* a,void* b){{FieldReference source,dest;source.FUN_0093d600(a,DAT_00e63c90);dest.FUN_0093d600(b,DAT_00e3e8b0);float* from=source.FUN_0093d6a0(0);float* to=dest.FUN_0093d6a0(0);*to=*from;}{FieldReference dest,source;source.FUN_0093d600(a,DAT_00e63c6c);dest.FUN_0093d600(b,DAT_00e3e898);float* from=source.FUN_0093d6a0(0);float* to=dest.FUN_0093d6a0(0);*to=*from;}}
}   // namespace f3m_00934440

// @f3 0x0093cee0 (community match, verified in this file)
namespace f3m_0093cee0 {
extern const char DAT_00e3f9fc[];extern const char DAT_00e73e18[];extern const char DAT_00e3f9e4[];extern const char DAT_00e73dd4[];void __cdecl FUN_0093e480(void*,const char*,void*,const char*);void __cdecl FUN_0093cee0(void* first,void* second){FUN_0093e480(first,DAT_00e73e18,second,DAT_00e3f9fc);FUN_0093e480(first,DAT_00e73dd4,second,DAT_00e3f9e4);}
}   // namespace f3m_0093cee0

// @f3 0x0092ecb0 (community match, verified in this file)
namespace f3m_0092ecb0 {
namespace Q92Cleanup { extern unsigned char DAT_010f3408; extern unsigned char DAT_0116939d; extern void (__cdecl *DAT_01061264)(); void FUN_0092ebc0(); void FUN_0056b560(int); void FUN_0056b5b0(int); void FUN_0092e920(); void FUN_0092e830(int);
struct Mode { bool enabled; Mode(bool b):enabled(b){} Mode(const Mode& m):enabled(m.enabled){} }; struct Array { int unk00; int unk04; int count; void FUN_009aea60(); }; struct Interface; struct Ops {
void* unk00;
void* unk04;
void* unk08;
void* unk0c;
void* unk10;
void* unk14;
void* unk18;
void* unk1c;
void* unk20;
void* unk24;
void* unk28;
void* unk2c;
void* unk30;
void* unk34;
void* unk38;
void* unk3c;
bool (__thiscall *active)(Interface*);
void* unk44;
void* unk48;
void* unk4c;
void* unk50;
void* unk54;
void* unk58;
void* unk5c;
void* unk60;
void* unk64;
void* unk68;
void* unk6c;
void* unk70;
void* unk74;
void* unk78;
void* unk7c;
void (__thiscall *query)(Interface*,int,Mode,Array*) throw(); }; struct Interface { Ops* ops; }; extern Interface* DAT_010f3400;
// pdb: hkBaseSystem::quit | hkBaseSystem.obj | fnv360_0822_retail, udata + bridge(udata|udata) + skyrim(udata), high
int __cdecl hkBaseSystem_quit() { int result=0; bool ready=DAT_010f3408==1; if(ready) { FUN_0092ebc0(); if(DAT_0116939d && DAT_01061264) { DAT_01061264(); DAT_0116939d=0; } FUN_0056b560(0); FUN_0056b5b0(0); FUN_0092e920(); if(DAT_010f3400->ops->active(DAT_010f3400)) { Interface* receiver=DAT_010f3400; Array array={0,0,0}; receiver->ops->query(receiver,0,Mode(true),&array); result=array.count>0; array.FUN_009aea60(); } FUN_0092e830(0); DAT_010f3408=0; } return result; } }
}   // namespace f3m_0092ecb0

// @f3 0x00934270 (community match, verified in this file)
namespace task1335 {
struct Stream {
    int unk00, unk04, unk08;
    void FUN_00923070(char*, int);
    void FUN_00943710(const char*);
    void FUN_00943a60();
};
struct Reporter {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual int Report(int, unsigned int, char*, const char*, int);
};
extern Reporter* DAT_010f3364;
void __cdecl FUN_00934270()
{
    unsigned int buffer[128];
    Stream stream;
    stream.FUN_00923070(reinterpret_cast<char*>(buffer), sizeof(buffer));
    stream.FUN_00943710("the object being versioned should not be present in a 4.5.0 b1 file");
    DAT_010f3364->Report(3, 0x50c1bb4a, reinterpret_cast<char*>(buffer), ".\\hkCompat_hk450b1_hk450r1.cpp", 57);
    stream.FUN_00943a60();
}
}

// @f3 0x0092c060 (community match, verified in this file)
namespace f3m_0092c060 {
struct ConstraintSource {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; float unk20; float unk24; float unk28; float unk2C; float unk30; float unk34; float unk38; float unk3C; int unk40,unk44,unk48,unk4C;float unk50,unk54;};
struct ConstraintOutput {int unk00,unk04,unk08,unk0C;float unk10; float unk14; float unk18; float unk1C; float unk20; float unk24; float unk28; float unk2C; float unk30; float unk34; };
struct ConstraintOwner {int unk00,unk04;ConstraintSource* data;void FUN_008f8840(ConstraintOutput*);void FUN_0092c060(ConstraintOutput*);};
void ConstraintOwner::FUN_0092c060(ConstraintOutput* out){FUN_008f8840(out);ConstraintSource* source=this?data:0;out->unk10=source->unk20;out->unk14=source->unk24;out->unk18=source->unk28;out->unk1C=source->unk2C;out->unk20=source->unk30;out->unk24=source->unk34;out->unk28=source->unk38;out->unk2C=source->unk3C;out->unk30=source->unk50;out->unk34=source->unk54;}
}   // namespace f3m_0092c060

// @f3 0x00935fc0 (community match, verified in this file)
extern char DAT_00e786f4[];
extern char DAT_00e67090[];
extern char DAT_0105ef50[];
void __cdecl FUN_00943250(void*,const void*,void*);
void __cdecl FUN_00940060(void*,void*,const void*,void*);
struct C935Manager {void* FUN_009b20b0(const void*);};
extern C935Manager* DAT_011693ac;
void __cdecl FUN_00935fc0(void* a,void* b) {
    FUN_00943250(a,DAT_00e786f4,b);
    void* value=DAT_011693ac->FUN_009b20b0(DAT_00e67090);
    FUN_00940060(a,b,DAT_0105ef50,value);
}

// @f3 0x009237b0 (community match, verified in this file)
namespace f3m_009237b0 {
struct Buffer37b0 {char* data;int length;int FUN_009237b0(char,int,int);};
int Buffer37b0::FUN_009237b0(char value,int start,int end){int limit=length-1;for(int i=start;i<limit;++i){if(i>=end)break;if(data[i]==value)return i;}return -1;}
}   // namespace f3m_009237b0

// @f3 0x0092a9f0 (community match, verified in this file)
namespace f3m_0092a9f0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace Task1352 {
struct Lock {unsigned int debug,lockCount,recursion,owner,semaphore,spin;};
extern Lock DAT_010f3194;
void* FUN_0089eb90(unsigned int);
struct FUN_008e8c10 {
 static void* operator new(unsigned int n){return FUN_0089eb90(n);}
 static void operator delete(void*);
 FUN_008e8c10();
unsigned int u000;
unsigned int u004;
unsigned int u008;
unsigned int u00c;
unsigned int u010;
unsigned int u014;
unsigned int u018;
unsigned int u01c;
unsigned int u020;
unsigned int u024;
unsigned int u028;
unsigned int u02c;
unsigned int u030;
unsigned int u034;
unsigned int u038;
unsigned int u03c;
unsigned int u040;
unsigned int u044;
unsigned int u048;
unsigned int u04c;
unsigned int u050;
unsigned int u054;
unsigned int u058;
unsigned int u05c;
unsigned int u060;
unsigned int u064;
unsigned int u068;
unsigned int u06c;
unsigned int u070;
unsigned int u074;
unsigned int u078;
unsigned int u07c;
unsigned int u080;
unsigned int u084;
unsigned int u088;
unsigned int u08c;
unsigned int u090;
unsigned int u094;
unsigned int u098;
unsigned int u09c;
unsigned int u0a0;
unsigned int u0a4;
unsigned int u0a8;
unsigned int u0ac;
unsigned int u0b0;
unsigned int u0b4;
unsigned int u0b8;
unsigned int u0bc;
unsigned int u0c0;
unsigned int u0c4;
unsigned int u0c8;
unsigned int u0cc;
unsigned int u0d0;
unsigned int u0d4;
unsigned int u0d8;
unsigned int u0dc;
unsigned int u0e0;
unsigned int u0e4;
unsigned int u0e8;
unsigned int u0ec;
unsigned int u0f0;
unsigned int u0f4;
unsigned int u0f8;
unsigned int u0fc;
unsigned int u100;
unsigned int u104;
unsigned int u108;
unsigned int u10c;
unsigned int u110;
unsigned int u114;
unsigned int u118;
unsigned int u11c;
unsigned int u120;
unsigned int u124;
unsigned int u128;
unsigned int u12c;
unsigned int u130;
unsigned int u134;
unsigned int u138;
unsigned int u13c;
unsigned int u140;
unsigned int u144;
unsigned int u148;
unsigned int u14c;
unsigned int u150;
unsigned int u154;
unsigned int u158;
unsigned int u15c;
unsigned int u160;
unsigned int u164;
unsigned int u168;
unsigned int u16c;
unsigned int u170;
unsigned int u174;
unsigned int u178;
unsigned int u17c;
unsigned int u180;
unsigned int u184;
unsigned int u188;
unsigned int u18c;
unsigned int u190;
unsigned int u194;
unsigned int u198;
unsigned int u19c;
unsigned int u1a0;
unsigned int u1a4;
unsigned int u1a8;
unsigned int u1ac;
unsigned int u1b0;
unsigned int u1b4;
unsigned int u1b8;
unsigned int u1bc;
unsigned int u1c0;
unsigned int u1c4;
unsigned int u1c8;
unsigned int u1cc;
unsigned int u1d0;
unsigned int u1d4;
unsigned int u1d8;
unsigned int u1dc;
unsigned int u1e0;
unsigned int u1e4;
unsigned int u1e8;
unsigned int u1ec;
unsigned int u1f0;
unsigned int u1f4;
unsigned int u1f8;
unsigned int u1fc;
unsigned int u200;
unsigned int u204;
unsigned int u208;
unsigned int u20c;
unsigned int u210;
unsigned int u214;
unsigned int u218;
unsigned int u21c;
unsigned int u220;
unsigned int u224;
unsigned int u228;
unsigned int u22c;
unsigned int u230;
unsigned int u234;
unsigned int u238;
unsigned int u23c;
unsigned int u240;
unsigned int u244;
unsigned int u248;
unsigned int u24c;
unsigned int u250;
unsigned int u254;
unsigned int u258;
unsigned int u25c;
};
struct Owner1352 {
 void FUN_008f7e50(FUN_008e8c10*,void*);
 FUN_008e8c10* FUN_0092a9f0(void*);
};
// pdb: bhkCharacterProxy::CreateClone | bhkCharacterProxy.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
FUN_008e8c10* Owner1352::FUN_0092a9f0(void* arg){
 EnterCriticalSection(&DAT_010f3194);
 FUN_008e8c10* obj=0;
 obj=new FUN_008e8c10();
 FUN_008f7e50(obj,arg);
 LeaveCriticalSection(&DAT_010f3194);
 return obj;
}
}
}   // namespace f3m_0092a9f0

// @f3 0x00922c50 (community match, verified in this file)
namespace f3m_00922c50 {
namespace create922 {
extern unsigned long DAT_010f3170;extern void* (__stdcall *DAT_00d9b080)(unsigned long);struct Memory {void* FUN_008f6d30(int,int);};
struct Owner {void* data;int size;int mask;void FUN_00922680();Owner* FUN_00922c50(int);};
Owner* Owner::FUN_00922c50(int requested){int n=requested*3;int capacity=4;size=0;while(capacity<n)capacity*=2;Memory* memory=(Memory*)DAT_00d9b080(DAT_010f3170);data=memory->FUN_008f6d30(capacity*8,0x17);mask=capacity-1;FUN_00922680();return this;}
}
}   // namespace f3m_00922c50

// @f3 0x0093cb40 (community match, verified in this file)
namespace f3m_0093cb40 {
extern char DAT_00e37e58; struct Q93Lookup {int unk00;int unk04;void FUN_0093d600(void*,const char*);unsigned char* FUN_0093d640(unsigned char*);int* FUN_0093d670(int);};
// pdb: hkDataObjectNative::hasMember | hkDataObjectNative.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|vtable) + skyrim(caller_sim), high
static __declspec(noinline) void hkDataObjectNative_hasMember(void* object,const char* name){Q93Lookup lookup;lookup.FUN_0093d600(object,name);unsigned char flag;unsigned char* test=lookup.FUN_0093d640(&flag);if(*test){int* result=lookup.FUN_0093d670(0);*result=0;}}
void __cdecl FUN_0093cb40(int unused,void* object){hkDataObjectNative_hasMember(object,&DAT_00e37e58);}
}   // namespace f3m_0093cb40

// @f3 0x0093c0e0 (community match, verified in this file)
namespace f3m_0093c0e0 {
namespace packed_pair_remove {
struct Pair {unsigned int key,value;};
struct Array {Pair* data;int count,capacity;__forceinline void RemoveAt(int i){--count;data[i]=data[count];}};
struct Owner {unsigned int unk00,unk04,unk08;Array array;unsigned int FUN_0093c0e0(unsigned int key);};
unsigned int Owner::FUN_0093c0e0(unsigned int key){for(int i=0;i<array.count;++i){if(array.data[i].key==key){unsigned int value=array.data[i].value;array.RemoveAt(i);return value;}}return 0;}
}
}   // namespace f3m_0093c0e0

// @f3 0x00929fe0 (community match, verified in this file)
namespace f3m_00929fe0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace Task1376 {
struct Lock{unsigned int debug,lockCount,recursion,owner,semaphore,spin;};
extern Lock DAT_010f3194;
extern int DAT_010f3174,DAT_010f3258,DAT_010f33c4,DAT_00dcdbac,DAT_00dcdf0c,DAT_00dfcef4;
void* FUN_0089eb90(unsigned int);
struct Obj {
 void* table;unsigned int refs,value,data,extra;
 void* FUN_008f7c10();
 static void* operator new(unsigned int n){return FUN_0089eb90(n);}
 static void operator delete(void*);
 Obj(){
  FUN_008f7c10();
  table=&DAT_00dcdbac;
  int one=1;
  data=0;
  extra=0;
  DAT_010f3174+=one;
  table=&DAT_00dcdf0c;
  DAT_010f3258+=one;
  table=&DAT_00dfcef4;
  DAT_010f33c4+=one;
 }
};
struct Owner {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual void slot40();
 virtual void slot41();
 virtual void slot42();
 virtual void slot43();
 virtual void slot44();
 virtual void slot45();
 virtual void slot46();
 virtual void slot47();
 virtual void Copy(Obj*,int);
 Obj* FUN_00929fe0(int);
};
// pdb: bhkMultiSphereShape::CreateClone | bhkMultiSphereShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCloneData
Obj* Owner::FUN_00929fe0(int arg){
 EnterCriticalSection(&DAT_010f3194);
 Obj* obj=new Obj();
 Copy(obj,arg);
 LeaveCriticalSection(&DAT_010f3194);
 return obj;
}
}
}   // namespace f3m_00929fe0

// @f3 0x00921c10 (community match, verified in this file)
namespace f3m_00921c10 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern int DAT_010f3194;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern int DAT_010f3174;
extern int DAT_010f32c0;
extern int DAT_010f3358;

struct S_00cb79d0_Base
{
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
    S_00cb79d0_Base();
    virtual void v00();
    int unk04;
    int unk08;
};

struct S_00cb79d0_A : S_00cb79d0_Base
{
    int unk0C;
    int unk10;
    S_00cb79d0_A()
    {
        unk0C = 0;
        unk10 = 0;
        DAT_010f3174++;
    }
    virtual void v00();
};

struct S_00cb79d0_B : S_00cb79d0_A
{
    S_00cb79d0_B()
    {
        DAT_010f32c0++;
    }
    virtual void v00();
};

struct S_00cb79d0_C : S_00cb79d0_B
{
    S_00cb79d0_C()
    {
        DAT_010f3358++;
    }
    virtual void v00();
};

struct S_00cb79d0
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v049(S_00cb79d0_Base* obj, int arg);
    S_00cb79d0_C* FUN_00921c10(int arg);
};

// @fnv 0x00cb79d0
// pdb: bhkTriSampledHeightFieldBvTreeShape::CreateClone | bhkTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
S_00cb79d0_C* S_00cb79d0::FUN_00921c10(int arg)
{
    EnterCriticalSection(&DAT_010f3194);
    S_00cb79d0_C* obj = new S_00cb79d0_C;
    v049(obj, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return obj;
}
}   // namespace f3m_00921c10

// @f3 0x0093ec30 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_0093ec30 {
namespace f3m_0093ec30 {
struct Mem_ec30 {
    void* FUN_008f6d30(int bytes, int tag) throw();
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
__declspec(dllimport) Mem_ec30* __stdcall FUN_00d9b080(int) throw();
struct String_ec30 {
    char* data;
    int size;
    int capacityAndFlags;
    __forceinline String_ec30() throw()
    {
        Mem_ec30* mem = FUN_00d9b080(DAT_010f3170);
        data = (char*)mem->FUN_008f6d30(1, 0x17);
        size = 1;
        capacityAndFlags = 1;
        data[0] = 0;
    }
    __forceinline ~String_ec30() throw()
    {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int cap = capacityAndFlags & 0x3fffffff;
            Mem_ec30* mem = FUN_00d9b080(DAT_010f3170);
            mem->FUN_008f6d90(data, cap, 0x17);
        }
    }
};
void __cdecl FUN_009236d0(String_ec30* s, const char* format, ...) throw();
struct Writer_ec30 {
    void FUN_00923830(const String_ec30& s) throw();
    void FUN_00923890(const char* s) throw();
};
struct Item_ec30 {
    int value;
    const char* name;
};
struct Enum_ec30 {
    const char* name;
    Item_ec30* items;
    int count;
};
}
using namespace f3m_0093ec30;
static __declspec(noinline) void FUN_0093ec30(const char* name, Writer_ec30* w, Enum_ec30* e)
{
    Writer_ec30** pw = &w;
    String_ec30 s;
    FUN_009236d0(&s, "\tstatic const hkInternalClassEnumItem %sEnumItems[] =\r\n\t{\r\n", name);
    w->FUN_00923830(s);
    for (int i = 0; i < e->count; i++) {
        FUN_009236d0(&s, "\t\t{%d, \"%s\"},\r\n", e->items[i].value, e->items[i].name);
        w->FUN_00923830(s);
    }
    w->FUN_00923890("\t};\r\n");
}
Enum_ec30* volatile g_e_ec30; Writer_ec30* volatile g_w_ec30; const char* volatile g_n_ec30;
void caller_of_FUN_0093ec30() { FUN_0093ec30(g_n_ec30, g_w_ec30, g_e_ec30); }
}   // namespace f3m_0093ec30

// @f3 0x00936000 (community match, verified in this file)
namespace f3m_00936000 {
namespace f3m_00936000 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
};
}
using namespace f3m_00936000;

void __cdecl FUN_00936000(void* src, void* dst)
{
    FUN_0093d600 to(dst, "flags");
    FUN_0093d600 from(src, "flags");
    *to.FUN_0093d6e0(0) = *from.FUN_0093d6e0(0);
}
}   // namespace f3m_00936000

// @f3 0x009257b0 (community match, verified in this file)
namespace f3m_009257b0 {
namespace f3m_009257b0 {
struct Vec4_57b0 {
    float x, y, z, w;
    Vec4_57b0& operator=(const Vec4_57b0& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
};
struct Body_57b0 {
    char pad[0x30];
    Vec4_57b0 position;
    Vec4_57b0 rotation;
};
struct Cls_57b0 {
    char pad[0x20];
    Vec4_57b0 rotation;
    Vec4_57b0 position;
    void FUN_008fe990(const Vec4_57b0* pos);
    void FUN_008fe9c0(const Vec4_57b0* rot);
    void FUN_008f7f20(Body_57b0* body);
    void FUN_009257b0(Body_57b0* body);
};
}
using namespace f3m_009257b0;

// pdb: bhkRigidBodyT::PostInit | bhkRigidBodyT.obj | fnv360_0822_retail, caller_sim, low, conflict (bridge: bhkMoppBvTreeShape::PostInit)
// pdb params: arInfo
void Cls_57b0::FUN_009257b0(Body_57b0* body)
{
    if (body) {
        Vec4_57b0& pos = body->position;
        Vec4_57b0& rot = body->rotation;
        position = pos;
        rotation = rot;
        pos = *(const Vec4_57b0*)&DAT_01092a50;
        rot.z = rot.y = rot.x = 0.0f;
        rot.w = 1.0f;
        FUN_008fe990(&pos);
        FUN_008fe9c0(&rot);
    }
    FUN_008f7f20(body);
}
}   // namespace f3m_009257b0

// @f3 0x00936f40 (community match, verified in this file)
extern short DAT_0105f57c;
namespace f3m_00936f40 {
namespace f3m_00936f40 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
};
}
using namespace f3m_00936f40;
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00936f40(void* obj, char enabled, char axis, float minAngle, float maxAngle, float tau)
{
    if (DAT_0105f57c == -1)
        DAT_0105f57c = FUN_00936710(obj, "TYPE_ANG_LIMIT");
    {
        FUN_0093d600 a(obj, "type");
        *a.FUN_0093d6e0(0) = DAT_0105f57c;
    }
    {
        FUN_0093d600 a(obj, "isEnabled");
        *a.FUN_0093d710(0) = enabled;
    }
    {
        FUN_0093d600 a(obj, "limitAxis");
        *a.FUN_0093d710(0) = axis;
    }
    {
        FUN_0093d600 a(obj, "minAngle");
        *a.FUN_0093d6a0(0) = minAngle;
    }
    {
        FUN_0093d600 a(obj, "maxAngle");
        *a.FUN_0093d6a0(0) = maxAngle;
    }
    {
        FUN_0093d600 a(obj, "angularLimitsTauFactor");
        *a.FUN_0093d6a0(0) = tau;
    }
}
void* volatile g_obj_936f40; volatile char g_c_936f40; volatile float g_f_936f40;
void caller_of_FUN_00936f40() { FUN_00936f40(g_obj_936f40, g_c_936f40, g_c_936f40, g_f_936f40, g_f_936f40, g_f_936f40); }
}   // namespace f3m_00936f40

// @f3 0x0092efd0 (community match, verified in this file)
namespace f3m_0092efd0 {
namespace default_error_constructor {
struct hkBaseObject {virtual ~hkBaseObject() throw();};
struct hkReferencedObject:hkBaseObject {unsigned short memorySizeAndFlags,referenceCount;__forceinline hkReferencedObject()throw():referenceCount(1){}};
struct hkError:hkReferencedObject {};
struct MapPair {unsigned int key,value;};
struct FUN_00922cb0 {MapPair* data;int size,hashMask;FUN_00922cb0()throw();~FUN_00922cb0()throw();};
template<class T> struct hkArray {T* data;int size;unsigned int capacityAndFlags;__forceinline hkArray()throw():data(0),size(0),capacityAndFlags(0x80000000u){}~hkArray()throw();};
typedef void(__cdecl*Report)(const char*,void*);
struct hkDefaultError:hkError {FUN_00922cb0 disabled;hkArray<int> sections;Report report;void* userData;hkDefaultError(Report,void*)throw();virtual ~hkDefaultError()throw();};
// pdb: hkDefaultError::hkDefaultError | hkDefaultError.obj | fnv360_0822_retail, uvref, high
// pdb params: errorReportFunction, errorReportObject
hkDefaultError::hkDefaultError(Report fn,void* context)throw():report(fn),userData(context){}
}
}   // namespace f3m_0092efd0

// @f3 0x00936c80 (community match, verified in this file)
extern short DAT_0105f56c;
namespace f3m_00936c80 {
namespace f3m_00936c80 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
};
}
using namespace f3m_00936c80;
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00936c80(void* obj, char enabled, char axis, float maxForce)
{
    if (DAT_0105f56c == -1)
        DAT_0105f56c = FUN_00936710(obj, "TYPE_LIN_FRICTION");
    {
        FUN_0093d600 a(obj, "type");
        *a.FUN_0093d6e0(0) = DAT_0105f56c;
    }
    {
        FUN_0093d600 a(obj, "isEnabled");
        *a.FUN_0093d710(0) = enabled;
    }
    {
        FUN_0093d600 a(obj, "frictionAxis");
        *a.FUN_0093d710(0) = axis;
    }
    {
        FUN_0093d600 a(obj, "maxFrictionForce");
        *a.FUN_0093d6a0(0) = maxForce;
    }
}
void* volatile g_obj_936c80; volatile char g_c_936c80; volatile float g_f_936c80;
void caller_of_FUN_00936c80() { FUN_00936c80(g_obj_936c80, g_c_936c80, g_c_936c80, g_f_936c80); }
}   // namespace f3m_00936c80

// @f3 0x00923bb0 (community match, verified in this file)
namespace f3m_00923bb0 {
extern "C" __declspec(dllimport) void* __stdcall MyTlsGetValue(unsigned long);

struct FUN_00923bb0_Input {
    void* data;
    int length;
};

struct FUN_00923bb0_Output {
    void* data;
    int size;
    int capacity;
};

struct FUN_00923bb0_Allocator {
    void* FUN_008f6d30(int bytes, int tag);
};

struct FUN_00923bb0_Object {
    void* data;
    int length;

    void FUN_00923bb0(FUN_00923bb0_Output* output, FUN_00923bb0_Input* input);
};

void __cdecl FUN_009234e0(void* destination, const void* source, int bytes);

void FUN_00923bb0_Object::FUN_00923bb0(FUN_00923bb0_Output* output, FUN_00923bb0_Input* input)
{
    int firstLength = length - 1;
    int secondLength = input->length - 1;

    FUN_00923bb0_Allocator* allocator =
        (FUN_00923bb0_Allocator*)MyTlsGetValue((unsigned long)DAT_010f3170);

    int totalSize = firstLength + secondLength + 1;
    void* allocated = allocator->FUN_008f6d30(totalSize, 0x16);

    FUN_009234e0(allocated, data, firstLength);
    FUN_009234e0((char*)allocated + firstLength, input->data, secondLength + 1);

    output->data = allocated;
    output->size = totalSize;
    output->capacity = totalSize;
}
}   // namespace f3m_00923bb0

// @f3 0x0093c9e0 (community match, verified in this file)
namespace f3m_0093c9e0 {
namespace force_field_aliases {
void __cdecl FUN_0093e480(void*,const char*,void*,const char*);
void __cdecl FUN_0093c9e0(void* output,void* input){FUN_0093e480(output,"maxNegForce",input,"minForce");FUN_0093e480(output,"maxPosForce",input,"maxForce");}
}
}   // namespace f3m_0093c9e0

// @f3 0x0092a880 (community match, verified in this file)
namespace f3m_0092a880 {
// FUN_0092a880: __thiscall, this in ecx, one byte flag argument.
// Releases the held array block and the holder itself when asked to.

class a43840_Mem
{
public:
    void _DeallocateAlias(void* p);
};

struct ArrHolder_92a880
{
    int unk00;
    int* data;
    int size;
    unsigned int cap;
};

struct Owner_92a880
{
    int unk00;
    int unk04;
    int unk08;
    ArrHolder_92a880* m_pArr;
    void FUN_0092a880(bool bFree);
};

void Owner_92a880::FUN_0092a880(bool bFree)
{
    if (bFree)
    {
        ArrHolder_92a880* h = m_pArr;
        if (h)
        {
            if ((h->cap & 0x80000000u) == 0)
            {
                unsigned int n = h->cap & 0x3fffffff;
                f3m_0092a520::Alloc* al = f3m_0092a520::FUN_00d9b080(DAT_010f3170);
                al->FUN_008f6d90(h->data, n << 4, 0x17);
            }
            ((a43840_Mem*)(void*)&DAT_01090a78)->_DeallocateAlias(h);
        }
        m_pArr = 0;
    }
}
}   // namespace f3m_0092a880

// @f3 0x00934590 (community match, verified in this file)
namespace f3m_00934590 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
};

extern void __cdecl FUN_00934440(void* first, int second, int value);

static __declspec(noinline) void FUN_009344d0(FUN_0093d600* first, FUN_0093d600* second, int value)
{
    FUN_00934440(first->unk00, second->unk04, 0);
    FUN_00934440(second->unk00, first->unk04, value);
}

// pdb: hkDataWorldNative::`scalar deleting destructor' | hkDataObjectNative.obj | fnv360_0822_retail, objrun_open, low
void FUN_00934590(void* owner, void* source, int value)
{
    FUN_009344d0(&FUN_0093d600(owner, "gains"), &FUN_0093d600(source, "gains"), value);
}
}   // namespace f3m_00934590

// @f3 0x00934330 (community match, verified in this file)
namespace f3m_00934330 {
struct SyncFieldRef {
    void* unk00;
    int unk04;
    SyncFieldRef(void* obj, const char* name);
    char& BoolAt(int index);
    unsigned short* WordAt(int index);
};
void FUN_00934330(void* syncOwner, void* flagsOwner)
{
    SyncFieldRef flags(flagsOwner, "flags");
    SyncFieldRef sync(syncOwner, "sync");
    SyncFieldRef autoWeight(syncOwner, "autoComputeSecondGeneratorWeight");
    if (sync.BoolAt(0))
        *flags.WordAt(0) |= 1;
    if (autoWeight.BoolAt(0))
        *flags.WordAt(0) |= 2;
}
}   // namespace f3m_00934330

// @f3 0x0093c240 (community match, verified in this file)
namespace f3m_0093c240 {
struct PropElemB {
    void* unk00;
    PropElemB* m_container;
    PropElemB* Container();
};

struct PropSrcB {
    char* m_base;
    PropElemB* m_container;
};

struct PropRefB {
    int m_offset;
    PropElemB* m_elem;
    PropRefB() {}
    PropRefB(PropSrcB* obj, const char* name);
    PropRefB* Init(int offset, PropElemB* container, const char* name);
    bool* Exists(bool* out);
    int GetOffset();
    PropElemB* GetElem();
    char* At(int index);
};

void FUN_0093c240(PropSrcB* src, PropSrcB* dst)
{
    PropRefB dest(dst, "qFormat");
    PropRefB source(src, "qFormat");
    bool ok;
    if (*dest.Exists(&ok) && *source.Exists(&ok))
    {
        PropRefB width;
        PropElemB* srcContainer = source.GetElem()->Container();
        width.Init(source.GetOffset(), srcContainer, "bitWidth");
        PropRefB maxWidth;
        PropElemB* dstContainer = dest.GetElem()->Container();
        maxWidth.Init(dest.GetOffset(), dstContainer, "maxBitWidth");
        if (*width.Exists(&ok) && *maxWidth.Exists(&ok))
            *maxWidth.At(0) = *width.At(0);
    }
}
}   // namespace f3m_0093c240

// @f3 0x0093cf20 (community match, verified in this file)
namespace f3m_0093cf20 {
struct FieldSrc { void* data; void* cls; };

struct FieldRef {
    void* data;
    void* member;
    FieldRef(void* obj, const char* name);
    char& FUN_0093d640(char* found);
    int* FUN_0093d6b0(int index);
    short* FUN_0093d6e0(int index);
};

void __cdecl FUN_0093cdd0(void* a, void* b, void* c);

void FUN_0093cf20(FieldSrc* a, FieldSrc* b, void* c)
{
    char found;
    FieldRef posesA(a, "numberOfPoses");
    FieldRef posesB(b, "numberOfPoses");
    if (posesA.FUN_0093d640(&found))
    {
        if (posesB.FUN_0093d640(&found))
            *posesB.FUN_0093d6b0(0) = *posesA.FUN_0093d6e0(0);
    }
    FieldRef sizeA(a, "blockSize");
    FieldRef sizeB(b, "blockSize");
    if (sizeA.FUN_0093d640(&found))
    {
        if (sizeB.FUN_0093d640(&found))
            *sizeB.FUN_0093d6b0(0) = *sizeA.FUN_0093d6e0(0);
    }
    FUN_0093cdd0(a, b, c);
}
}   // namespace f3m_0093cf20

// @f3 0x00933fd0 (community match, verified in this file)
namespace f3m_00933fd0 {
struct FieldTypeDesc;

struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
    FieldTypeDesc* FUN_0093d790();
};

struct FieldTypeDesc {
    int FUN_0093d900();
};

void FUN_00933fd0(void* sourceObject, void* targetObject)
{
    FUN_0093d600 source(sourceObject, "transitions");
    FUN_0093d600 target(targetObject, "transitions");
    FUN_009234e0((void*)target.FUN_0093d660(), (void*)source.FUN_0093d660(),
                 source.FUN_0093d790()->FUN_0093d900());
}
}   // namespace f3m_00933fd0

// @f3 0x0093c6d0 (community match, verified in this file)
namespace f3m_0093c6d0 {
namespace f3m_0093c6d0 {
struct FldRefC {
    int offset;
    int member;
    FldRefC(void* obj, const char* name);
    int* FUN_0093d670(int index);
    int FUN_0093d650();
};
struct Target_93c6d0 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int* ptr);
};
static __declspec(noinline) void FUN_0093c6d0(void* objA, const char* nameA, void* objB, const char* nameB, Target_93c6d0* target)
{
    FldRefC a(objA, nameA);
    FldRefC b(objB, nameB);
    *b.FUN_0093d670(1) = *a.FUN_0093d670(0);
    int n = b.FUN_0093d650();
    target->Set(*b.FUN_0093d670(1), (int*)(n + 4));
}
void* volatile g_objA_93c6d0;
const char* volatile g_nameA_93c6d0;
void* volatile g_objB_93c6d0;
const char* volatile g_nameB_93c6d0;
Target_93c6d0* volatile g_target_93c6d0;
void caller_of_FUN_0093c6d0()
{
    FUN_0093c6d0(g_objA_93c6d0, g_nameA_93c6d0, g_objB_93c6d0, g_nameB_93c6d0, g_target_93c6d0);
}
}
}   // namespace f3m_0093c6d0

// @f3 0x0092dd00 (community match, verified in this file)
namespace f3m_0092dd00 {
struct Node7dd00 {
    int unk00;
    int unk04;
    int unk08;
    Node7dd00* next;
};
struct Item7dd00 {
    int unk00;
    int unk04;
    Node7dd00* link;
    int unk0c;
};
struct Owner7dd00 {
    int unk00;
    int unk04;
    Item7dd00* items;
    int count;
    void FUN_00929bf0(void* arg, Node7dd00* node);
    void FUN_0092dd00(void* arg, Node7dd00* node);
};
// pdb: bhkFilteredCdBodyCollector::addCdBodyPair | bhkFilteredCdBodyCollector.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arBodyA, arBodyB
void Owner7dd00::FUN_0092dd00(void* arg, Node7dd00* node)
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (found)
            break;
        Node7dd00* tail = node;
        while (tail->next)
            tail = tail->next;
        if (tail == items[i].link)
            found = true;
    }
    if (!found)
        FUN_00929bf0(arg, node);
}
}   // namespace f3m_0092dd00

// @f3 0x00925690 (community match, verified in this file)
namespace f3m_00925690 {
struct Res50 {
    char pad00[0x30];
    float m30; float m34; float m38; float m3c;
    float m40; float m44; float m48; float m4c;
};

struct Arg10 {
    char pad00[0x10];
    float scale;
};

class Owner {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual Res50* Find(char* flag);
    char pad04[0x1c];
    float f20; float f24; float f28; float f2c;
    float f30; float f34; float f38; float f3c;
    void FUN_00900e00(int a, Arg10* b);
    void FUN_00925690(int a, Arg10* b);
};

// pdb: bhkRigidBodyT::CopyMembers | bhkRigidBodyT.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: pDest, arCloneData
void Owner::FUN_00925690(int a, Arg10* b)
{
    char flag;
    Res50* p = Find(&flag);
    if (p)
    {
        p->m40 = f20;
        p->m44 = f24;
        p->m48 = f28;
        p->m4c = f2c;
        p->m30 = f30;
        p->m34 = f34;
        p->m38 = f38;
        p->m3c = f3c;
        float s = b->scale;
        if (s != 1.0f)
        {
            p->m30 *= s;
            p->m34 *= s;
            p->m38 *= s;
            p->m3c *= s;
        }
    }
    FUN_00900e00(a, b);
}
}   // namespace f3m_00925690

// @f3 0x0092a960 (community match, verified in this file)
namespace f3m_0092a960 {
namespace f3m_0092a960 {

struct Sub {
    void FUN_0090b960(void* owner);
    void hkpPhantom_removePhantomListener(void* owner);
};

class Owner {
public:
    int unk00;
    int unk04;
    int m_a08;
    int m_b0c;
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
    int unk80;
    int unk84;
    int unk88;
    Sub** m_arr8c;
    int m_count90;
    int unk94;
    Sub** m_arr98;
    int m_count9c;

    void FUN_0092a960();
};

// pdb: ahkpCharacterProxy::RemoveEntityListeners | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, medium
void Owner::FUN_0092a960()
{
    for (int i = 0; i < m_count90; i++)
        m_arr8c[i]->FUN_0090b960(&m_a08);
    m_count90 = 0;
    for (int i = 0; i < m_count9c; i++)
        m_arr98[i]->hkpPhantom_removePhantomListener(&m_b0c);
    m_count9c = 0;
}

}
}   // namespace f3m_0092a960

// @f3 0x00937270 (community match, verified in this file)
extern short DAT_0105f588;
namespace f3m_00937270 {

struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
};

static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    FUN_0093d600 f(obj, "type");
    short value = 0;
    if (name)
        value = *f.FUN_0093d6e0(0);
    return value;
}

static __declspec(noinline) void FUN_00937270(void* obj, char isEnabled, char firstFrictionAxis,
                                              char numFrictionAxes, float maxFrictionTorque)
{
    if (DAT_0105f588 == -1)
        DAT_0105f588 = FUN_00936710(obj, "TYPE_ANG_FRICTION");
    {
        FUN_0093d600 type(obj, "type");
        *type.FUN_0093d6e0(0) = DAT_0105f588;
    }
    {
        FUN_0093d600 enabled(obj, "isEnabled");
        *enabled.FUN_0093d710(0) = isEnabled;
    }
    {
        FUN_0093d600 axis(obj, "firstFrictionAxis");
        *axis.FUN_0093d710(0) = firstFrictionAxis;
    }
    {
        FUN_0093d600 axes(obj, "numFrictionAxes");
        *axes.FUN_0093d710(0) = numFrictionAxes;
    }
    {
        FUN_0093d600 torque(obj, "maxFrictionTorque");
        *torque.FUN_0093d6a0(0) = maxFrictionTorque;
    }
}
void* volatile g_obj_937270;
volatile char g_a_937270, g_b_937270, g_c_937270;
volatile float g_f_937270;
void caller_of_FUN_00937270() { FUN_00937270(g_obj_937270, g_a_937270, g_b_937270, g_c_937270, g_f_937270); }
}   // namespace f3m_00937270

// @f3 0x00923a20 (community match, verified in this file)
namespace f3m_00923a20 {
int FUN_009233f0(const char* s);

namespace f3m_00923a20 {
struct Str {
    char* data;
    int length;
    unsigned char* FUN_00923a20(unsigned char* out, const char* needle) const;
};

unsigned char* Str::FUN_00923a20(unsigned char* out, const char* needle) const
{
    int off = length - FUN_009233f0(needle) - 1;
    if (off < 0)
    {
        *out = 0;
        return out;
    }
    for (int k = 0; needle[k] != 0; k++)
    {
        if (data[off + k] != needle[k])
        {
            *out = 0;
            return out;
        }
    }
    *out = 1;
    return out;
}
}
}   // namespace f3m_00923a20

// @f3 0x00923d80 (community match, verified in this file)
namespace f3m_00923d80 {
extern void* (__stdcall* FUN_00d9b080)(unsigned long index);   // the TlsGetValue import slot

struct D80Heap
{
    char* FUN_008f6d30(int size, int tag);
};

struct D80Result
{
    char* data;
    int length;
    int capacity;
};

struct FUN_00923d80_Str
{
    const char* unk00;
    int unk04;
    D80Result FUN_00923d80(char from, char to, int all);
};

// A heap copy of the string with `from` replaced by `to` (the first one, or all of them).
D80Result FUN_00923d80_Str::FUN_00923d80(char from, char to, int all)
{
    int length = unk04;
    D80Heap* heap = (D80Heap*)FUN_00d9b080(DAT_010f3170);
    char* copy = heap->FUN_008f6d30(length, 0x16);
    FUN_009234e0(copy, unk00, unk04);
    for (int i = 0; i < unk04 - 1; ++i) {
        if (copy[i] == from) {
            copy[i] = to;
            if (!all)
                break;
        }
    }
    copy[unk04 - 1] = 0;
    D80Result result;
    result.data = copy;
    result.length = unk04;
    result.capacity = unk04;
    return result;
}
}   // namespace f3m_00923d80

// @f3 0x00933a90 (community match, verified in this file)
namespace f3m_00933a90 {
namespace Copy396{extern char DAT_00e44fe0;struct FUN_0093d600{void*object;unsigned int index;FUN_0093d600(void*,const char*);unsigned short*FUN_0093d6b0(int);unsigned short*FUN_0093d6e0(int);};void __cdecl FUN_00933a90(void*source,void*destination){FUN_0093d600 from(source,&DAT_00e44fe0);FUN_0093d600 to(destination,&DAT_00e44fe0);unsigned short*value=from.FUN_0093d6b0(0);unsigned short*out=to.FUN_0093d6e0(0);*out=*value;}}
}   // namespace f3m_00933a90

// @f3 0x0093ca60 (community match, verified in this file)
namespace f3m_0093ca60 {
struct FUN_0093d600
{
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
    bool& FUN_0093d640(bool& ok);
    float* FUN_0093d6a0(int index);
};

// Copies the "tau" value of one object into the "strength" value of the other when both members exist.
void __cdecl FUN_0093ca60(void* tauOwner, void* strengthOwner)
{
    FUN_0093d600 strength(strengthOwner, "strength");
    FUN_0093d600 tau(tauOwner, "tau");
    bool ok;
    if (strength.FUN_0093d640(ok) && tau.FUN_0093d640(ok))
        *strength.FUN_0093d6a0(0) = *tau.FUN_0093d6a0(0);
}
}   // namespace f3m_0093ca60

// @f3 0x00932f60 (community match, verified in this file)
namespace f3m_00932f60 {
namespace Copy401{extern char DAT_00e3ec24;struct FUN_0093d600{void*object;unsigned int index;FUN_0093d600(void*,const char*);unsigned char*FUN_0093d700(int);};void __cdecl FUN_00932f60(void*source,void*destination){FUN_0093d600 from(source,&DAT_00e3ec24);FUN_0093d600 to(destination,&DAT_00e3ec24);unsigned char*value=from.FUN_0093d700(0);unsigned char*out=to.FUN_0093d700(0);*out=*value;}}

}   // namespace f3m_00932f60

// @f3 0x00933760 (community match, verified in this file)
extern int DAT_0105edf0;
namespace f3m_00933760 {
struct FUN_0093d600
{
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
    bool& FUN_0093d640(bool& ok);
    const char** FUN_0093d680(int index);
};

struct E3760Lookup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00933930(void* table);
    void* FUN_009b10f0(const void* key, int fallback);
    void FUN_009b1160();
};

struct E3760Sink
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Add(const char* name);
};

const char* __cdecl FUN_00923640(void* entry);

// Copies the className member from one object to the other, resolved through the class registry.
void __cdecl FUN_00933760(void* from, void* to, E3760Sink* sink)
{
    FUN_0093d600 source(from, "className");
    FUN_0093d600 target(to, "className");
    bool ok;
    if (source.FUN_0093d640(ok) && target.FUN_0093d640(ok)) {
        E3760Lookup lookup;
        lookup.FUN_00933930(&DAT_0105edf0);
        const char* key = *source.FUN_0093d680(0);
        void* entry = lookup.FUN_009b10f0(key, 0);
        if (entry) {
            const char* name = FUN_00923640(entry);
            sink->Add(name);
            *target.FUN_0093d680(0) = name;
        }
        lookup.FUN_009b1160();
    }
}
}   // namespace f3m_00933760

// @f3 0x00934680 (community match, verified in this file)
namespace f3m_00934680 {
struct BoneElem {
    unsigned short boneIndex;
    unsigned short mirrorIndex;
};
struct HandElem {
    unsigned char enabled;
    unsigned char mirrored;
};
struct FieldAccess {
    void* unk00;
    int unk04;
    FieldAccess(void* obj, const char* name);
    void* Elem();
    unsigned short& ShortAt(int index);
};

void FUN_00934680(void* srcOwner, void* dstOwner)
{
    {
        FieldAccess src(srcOwner, "reachReferenceBoneIdx");
        FieldAccess dst(dstOwner, "reachReferenceBoneIdx");
        BoneElem* dstElem = (BoneElem*)dst.Elem();
        unsigned short bone = src.ShortAt(0);
        dstElem->mirrorIndex = bone;
        dstElem->boneIndex = bone;
    }
    {
        FieldAccess hand(dstOwner, "isHandEnabled");
        HandElem* handElem = (HandElem*)hand.Elem();
        handElem->mirrored = 1;
        handElem->enabled = 1;
    }
}
}   // namespace f3m_00934680

// @f3 0x00934e00 (community match, verified in this file)
namespace f3m_00934e00 {
namespace Clear416{extern char DAT_00e3b150,DAT_00e67038;struct FUN_0093d600{void*object;int index;FUN_0093d600(void*,const char*);bool*FUN_0093d640(bool*);unsigned int*FUN_0093d6b0(int);};void __cdecl FUN_00934e00(void*source,void*destination){FUN_0093d600 first(destination,&DAT_00e3b150);FUN_0093d600 second(source,&DAT_00e67038);bool valid;if(*first.FUN_0093d640(&valid)&&*second.FUN_0093d640(&valid)){*second.FUN_0093d6b0(0)=0;*first.FUN_0093d6b0(0)=0;}}}
}   // namespace f3m_00934e00

// @f3 0x00935c10 (community match, verified in this file)
namespace f3m_00935c10 {
namespace Copy420{struct DataSpan{const void*data;int length;};struct Source{DataSpan*FUN_0093d650();};struct Buffer{char*data;int size;unsigned int capacityFlags;};struct Offsets{int*FUN_0093d6b0(int);};void __cdecl FUN_00901e90(Buffer*,int,int);void __cdecl FUN_009234e0(void*,const void*,int);int __cdecl FUN_00935c10(Source*source,int length,Buffer*buffer,int offset,Offsets*offsets){DataSpan*span=source->FUN_0093d650();int required=buffer->size;int aligned=(length+3)&~3;required+=aligned;int capacity=buffer->capacityFlags&0x3fffffff;if(capacity<required){int desired=capacity*2;if(required>=desired)desired=required;FUN_00901e90(buffer,desired,1);}buffer->size=required;FUN_009234e0(buffer->data+offset,span->data,length);*offsets->FUN_0093d6b0(0)=offset;return aligned;}}
}   // namespace f3m_00935c10

// @f3 0x0093cc80 (community match, verified in this file)
namespace f3m_0093cc80 {
struct Value8 {
    int x;
    int y;
};

struct RefRow {
    void* unk00;
    int unk04;
    void* FUN_0093d890();
};

class FieldRef {
public:
    void* unk00;
    int unk04;
    FieldRef(void* obj, const char* name);
    FieldRef(void* owner, void* key, const char* name);
    char* FUN_0093d640(char* exists);
    RefRow* FUN_0093d790();
    Value8* FUN_0093d760(int index);
};

struct PhysOwner {
    void* unk00;
};

void FUN_0093cc80(PhysOwner* owner, void* target)
{
    FieldRef physics(owner, "physicsSystem");
    FieldRef rigidBodies(target, "rigidBodies");
    FieldRef constraints(target, "constraints");
    char exists;
    if (*physics.FUN_0093d640(&exists) && *rigidBodies.FUN_0093d640(&exists) && *constraints.FUN_0093d640(&exists))
    {
        void* key = physics.FUN_0093d790()->FUN_0093d890();
        FieldRef a(owner->unk00, key, "rigidBodies");
        FieldRef b(owner->unk00, key, "constraints");
        *rigidBodies.FUN_0093d760(0) = *a.FUN_0093d760(0);
        *constraints.FUN_0093d760(0) = *b.FUN_0093d760(0);
    }
}
}   // namespace f3m_0093cc80

// @f3 0x00936630 (community match, verified in this file)
namespace f3m_00936630 {
struct FieldRef936630 {
    void* unk00;
    int unk04;
    FieldRef936630(void* obj, const char* name);
    bool& FUN_0093d640(bool& out);
    float* FUN_0093d6a0(int index);
};

void FUN_00936630(void* a, void* b)
{
    FieldRef936630 contact(b, "contactAngleSensitivity");
    FieldRef936630 radius(a, "characterRadius");
    bool ok;
    if (contact.FUN_0093d640(ok) && radius.FUN_0093d640(ok))
        *contact.FUN_0093d6a0(0) = *radius.FUN_0093d6a0(0);
}
}   // namespace f3m_00936630

// @f3 0x0093d190 (community match, verified in this file)
namespace f3m_0093d190 {

using namespace f3m_00936750;

// A "property reference" for the constraint-data property bag: constructed from
// (owner, property name) and then queried / indexed.
struct PropRef : FUN_0093d600 {
    PropRef(void* obj, const char* name) : FUN_0093d600(obj, name) {}
    char* FUN_0093d640(char* out);
    void* FUN_0093d650();
    char* FUN_0093d690(int offset);
};

void FUN_0093d190(void* a, void* b)
{
    PropRef transform(a, "initialTransform");
    char ok;
    if (*transform.FUN_0093d640(&ok)) {
        float* m = (float*)transform.FUN_0093d650();
        m[3] = 0.0f; m[2] = 0.0f; m[1] = 0.0f; m[0] = 0.0f;
        m[7] = 0.0f; m[6] = 0.0f; m[5] = 0.0f; m[4] = 0.0f;
        m[11] = 0.0f; m[10] = 0.0f; m[9] = 0.0f; m[8] = 0.0f;
    }
    PropRef src(a, "lockTranslation");
    PropRef dst(b, "lockTranslation");
    if (*src.FUN_0093d640(&ok)) {
        if (*dst.FUN_0093d640(&ok)) {
            char value = *src.FUN_0093d690(0);
            *dst.FUN_0093d690(0) = value;
        }
    }
}
}   // namespace f3m_0093d190

// @f3 0x00936210 (community match, verified in this file)
extern const unsigned char DAT_00e7896c[],DAT_0105ef70[];
namespace f3m_00936210 {
namespace compatibility_step {
void __cdecl FUN_00943250(void*,const void*,void*);
struct Registry {void* FUN_009b20b0(const char*);};extern Registry* DAT_011693ac;
void __cdecl FUN_00940060(void*,void*,const void*,void*);
void __cdecl FUN_00936210(void* a,void* b){FUN_00943250(a,DAT_00e7896c,b);void* version=DAT_011693ac->FUN_009b20b0("Havok-4.0.2-r1");FUN_00940060(a,b,DAT_0105ef70,version);}
}
}   // namespace f3m_00936210

// @f3 0x00923890 (community match, verified in this file)
namespace f3m_00923890 {
struct FUN_00923890_Obj {
    char* data;
    int size;
    unsigned int capacityAndFlags;

    int* FUN_00923890(int* source);
};

int __cdecl FUN_009233f0(int* source);

int* FUN_00923890_Obj::FUN_00923890(int* source)
{
    int previousSize = this->size - 1;
    int length = FUN_009233f0(source);
    int requiredSize = previousSize + length + 1;
    int capacity = (int)(this->capacityAndFlags & 0x3fffffffu);

    if (capacity < requiredSize)
    {
        int newCapacity = capacity * 2;
        if (requiredSize >= newCapacity)
            newCapacity = requiredSize;
        FUN_00901e90((ByteBuffer*)this, newCapacity, 1);
    }

    this->size = requiredSize;
    FUN_009234e0(this->data + previousSize, source, length + 1);
    return (int*)this;
}
}   // namespace f3m_00923890

// @f3 0x00933ca0 (community match, verified in this file)
namespace f3m_00933ca0 {
namespace enabled_children_reset {
struct FUN_0093d600 {void* source;void* member;FUN_0093d600(void*,const char*);void* FUN_0093d6b0(int);};
void __cdecl FUN_00933ca0(void* unused,void* object){FUN_0093d600 access(object,"enabledChildren");unsigned int* data=(unsigned int*)access.FUN_0093d6b0(0);data[0]=~0u;data[1]=~0u;data[2]=~0u;data[3]=~0u;data[4]=~0u;data[5]=~0u;data[6]=~0u;data[7]=~0u;}
}
}   // namespace f3m_00933ca0

// @f3 0x0092ac70 (community match, verified in this file)
extern int DAT_010f33d0;
namespace f3m_0092ac70 {
namespace task1523 {
struct Other {void FUN_0091ddd0();};
struct FUN_008f7ff0 {virtual ~FUN_008f7ff0();int unk04;Other* other;int unk0c;void FUN_008f7ef0();};
struct FUN_0096a860 {int unk00;~FUN_0096a860();};
struct FUN_0092ac70:FUN_008f7ff0 {FUN_0096a860 member;virtual ~FUN_0092ac70();};
// pdb: bhkCharacterProxy::~bhkCharacterProxy | bhkCharacterProxy.obj | fnv360_0822_retail, call_gap, medium
FUN_0092ac70::~FUN_0092ac70(){if(other)other->FUN_0091ddd0();FUN_008f7ef0();--DAT_010f33d0;}
}
}   // namespace f3m_0092ac70

// @f3 0x00933460 (community match, verified in this file)
namespace f3m_00933460 {
struct FUN_00d871a0 {void* data;int count;FUN_00d871a0(void*,const char*);unsigned char* FUN_0093d700(int);};
void __cdecl FUN_00933460(void* first,void* second) {
    FUN_00d871a0 source(first,"endMode"); FUN_00d871a0 destination(second,"endMode");
    unsigned char* value=source.FUN_0093d700(0);
    unsigned char* output=destination.FUN_0093d700(0);
    *output=*value;
}
}   // namespace f3m_00933460

// @f3 0x00922680 (community match, verified in this file)
namespace f3m_00922680 {
namespace task1549 {
struct Map {int* data;unsigned count;int hashMod;void Clear(int n){for(int i=0;i<n;++i)data[i]=-1;}void FUN_00922680();};
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::clear | hkMap.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkPointerMap<int,int,struct hkContainerHeapAllocator>::clear)
void Map::FUN_00922680(){int n=hashMod+1;Clear(n*2);count&=0x80000000u;}
}
}   // namespace f3m_00922680

// @f3 0x0092f170 (community match, verified in this file)
namespace f3m_0092f170 {
struct Array {void FUN_00922d30(int);void FUN_00922710(int,int);};
struct Owner {unsigned int unk00,unk04;Array values;void FUN_0092f170(int,bool);};
// pdb: hkDefaultError::setEnabled | hkDefaultError.obj | fnv360_0822_retail, vtable, medium
// pdb params: id, enabled
void Owner::FUN_0092f170(int count,bool fast){if(fast)values.FUN_00922d30(count);else values.FUN_00922710(count,1);}
}   // namespace f3m_0092f170

// @f3 0x0092b3f0 (community match, verified in this file)
extern const void* DAT_00e36d04[];extern const void* DAT_00dcc494[];
namespace f3m_0092b3f0 {
namespace nullable_header_1952 {
struct RefObject {virtual void* Destroy(unsigned int);unsigned short allocationBytes;short references;
void Retain(){if(allocationBytes!=0)++references;}
void Release(){if(allocationBytes!=0){--references;if(references==0)Destroy(1);}}};
struct Owner {const void** vtable;unsigned short allocationBytes;short references;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2C;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3C;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4C;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5C;unsigned int unk60;unsigned int unk64;unsigned int unk68;unsigned int unk6C;unsigned int unk70;unsigned int unk74;unsigned int unk78;unsigned int unk7C;unsigned int unk80;unsigned int unk84;unsigned int unk88;unsigned int unk8C;unsigned int unk90;unsigned int unk94;unsigned int unk98;unsigned int unk9C;unsigned int unkA0;unsigned int unkA4;unsigned int unkA8;unsigned int unkAC;RefObject* child;void FUN_0092b3f0();};
// pdb: hkpLimitedHingeConstraintData::~hkpLimitedHingeConstraintData | hkpLimitedHingeConstraintData.obj | fnv360_0721_beta, objrun, medium
void Owner::FUN_0092b3f0(){RefObject* object=child;vtable=DAT_00e36d04;if(object)object->Release();vtable=DAT_00dcc494;}
}
}   // namespace f3m_0092b3f0

// @f3 0x0092aa80 (community match, verified in this file)
namespace f3m_0092aa80 {
struct NiStream {void FUN_0082b560();};

struct Result {unsigned int unk00;unsigned int unk04;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2C;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3C;unsigned int unk40;unsigned int unk44;void* value48;};

struct Object {virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void f5();virtual void f6();virtual void f7();virtual void f8();virtual void f9();virtual void f10();virtual void f11();virtual void f12();virtual void f13();virtual void f14();virtual void f15();virtual void f16();virtual void f17();virtual void f18();virtual void f19();virtual void f20();virtual void f21();virtual void f22();virtual void f23();virtual void f24();virtual void f25();virtual void f26();virtual void f27();virtual void f28();virtual void f29();virtual void f30();virtual void f31();virtual void f32();virtual void f33();virtual void f34();virtual void f35();virtual void f36();virtual void f37();virtual void f38();virtual void f39();virtual void f40();virtual void f41();virtual void f42();virtual void f43();virtual void f44();virtual Result* Resolve(int*);void FUN_008f7ea0(NiStream*);void FUN_0092aa80(NiStream*);};

// pdb: bhkCharacterProxy::LoadBinary | bhkCharacterProxy.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: arStream
void Object::FUN_0092aa80(NiStream* stream){stream->FUN_0082b560();FUN_008f7ea0(stream);int tmp;Result* result=Resolve(&tmp);if(result)result->value48=0;}

}   // namespace f3m_0092aa80

// @f3 0x00937780 (community match, verified in this file)
extern short DAT_0105f59c;
extern const char STR_00e39ef4[];
extern const char STR_00e3a750[];
namespace f3m_00937780 {

static __declspec(noinline) short FN_66b0(void* p) { return *(const short*)p; }

struct Obj7a0 {
    int a;
    int b;
    __declspec(noinline) void* FN_7a0(void* x, const char* y, void* z);
};

struct Obj810 {
    __declspec(noinline) void* FN_810();
};

void __cdecl FUN_00937780(void* a1, void* obj, void* target)
{
    f3m_00936750::FUN_0093d600 local0(obj, STR_00e39ef4);
    if (DAT_0105f59c == -1) {
        DAT_0105f59c = FN_66b0(&local0);
    }
    long long local8;
    long long local10;
    Obj7a0* p = (Obj7a0*)&local0;
    f3m_00936750::FUN_00936750(
        (void*)(((Obj810*)p->FN_7a0((void*)&local10, STR_00e3a750, (void*)&local8))->FN_810()),
        (int)*(void**)obj,
        (f3m_00936750::Target_936750*)target
    );
}
}   // namespace f3m_00937780

// @f3 0x0092ac50 (community match, verified in this file)
namespace f3m_0092ac50 {
// pdb: bhkCharacterProxy::IsEqual | bhkCharacterProxy.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: bhkCharacterProxy::CleanUp)
// pdb params: apObject
class A{public:void FUN_0092a960();};class BaseVtbl{public:virtual void FUN_0092a960_0();virtual void FUN_0092a960_1();virtual void FUN_0092a960_2();virtual void FUN_0092a960_3();};class Outer{public:int unk00;int unk04;A* unk08;int unk0c;BaseVtbl baseVtbl;void FUN_0092ac50();};void Outer::FUN_0092ac50(){Outer*esi=this;esi->unk08->FUN_0092a960();esi->baseVtbl.FUN_0092a960_3();}
}   // namespace f3m_0092ac50

// @f3 0x00935c90 (community match, verified in this file)
namespace f3m_00935c90 {
int FUN_00935c90(SpanSource* source, ByteBuffer* buffer, int offset, OffsetList* offsets)
{
    DataSpan* span = source->FUN_0093d650();
    int length = span->length * 2;
    int required = buffer->size;
    int aligned = (length + 3) & ~3;
    required += aligned;
    int capacity = buffer->capacityAndFlags & 0x3fffffff;
    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        FUN_00901e90(buffer, newCapacity, 1);
    }
    buffer->size = required;
    FUN_009234e0(buffer->data + offset, span->data, length);
    *offsets->FUN_0093d6b0(0) = offset;
    return aligned;
}
}   // namespace f3m_00935c90

// @f3 0x009343b0 (community match, verified in this file)
namespace f3m_009343b0 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    int* FUN_0093d670(int index);
    bool* FUN_0093d690(int index);
    bool* FUN_0093d700(int index);
};

void FUN_009343b0(void* obj, void* other)
{
    {
        FUN_0093d600 filename(obj, "filename");
        FUN_0093d600 animationName(other, "animationName");
        *animationName.FUN_0093d670(0) = *filename.FUN_0093d670(0);
    }
    {
        FUN_0093d600 continueMotionAtEnd(obj, "continueMotionAtEnd");
        FUN_0093d600 flags(other, "flags");
        if (*continueMotionAtEnd.FUN_0093d690(0) != 0) {
            *flags.FUN_0093d700(0) = 1;
        }
    }
}
}   // namespace f3m_009343b0

// @f3 0x0093c880 (community match, verified in this file)
namespace f3m_0093c880 {
struct HKVariantRef_93c880 {
    const char* getName() const;
};

struct HKVariantEntry_93c880 {
    int m_key;
    HKVariantRef_93c880* m_variant;
};

struct HKVariantList_93c880 {
    HKVariantEntry_93c880* m_entries;
    int m_numEntries;
};

int __cdecl HKNameCmp_93c880(const char* a, const char* b);
void __cdecl FUN_0093c7d0(int key, HKVariantList_93c880* owner);

// pdb: hkDataObject::hkDataObject | hkDataObject.obj | fnv360_1110_retail, objopen_prop, low
// pdb params: i
static __declspec(noinline) int FUN_0093c880(HKVariantList_93c880* self)
{
    for (int i = 0; i < self->m_numEntries; i++)
    {
        const HKVariantEntry_93c880* entry = &self->m_entries[i];
        if (HKNameCmp_93c880(entry->m_variant->getName(), "hkRootLevelContainer") == 0)
            FUN_0093c7d0(self->m_entries[i].m_key, self);
    }
    return 0;
}

void hkCaller_93c880(HKVariantList_93c880* list)
{
    FUN_0093c880(list);
}
}   // namespace f3m_0093c880

// @f3 0x00934950 (community match, verified in this file)
namespace f3m_00934950 {
namespace Bones307{
struct FUN_0093d600{unsigned int unk00,unk04;FUN_0093d600(void*,const char*);void* FUN_0093d660();};
struct Indices307{short*data;int count;};
struct Bits307{unsigned int*data;unsigned int unk04;int capacityFlags;void FUN_009b2130(int,int);unsigned int& Word(int index){return *((index>>5)+data);}};
void __cdecl FUN_00934950(void*first,void*second){FUN_0093d600 lower(first,"lowerBodyBones");FUN_0093d600 keyframed(second,"keyframedBones");Indices307*indices=(Indices307*)lower.FUN_0093d660();Bits307*bits=(Bits307*)keyframed.FUN_0093d660();int count=indices->count;for(int i=0;i<count;++i){int index=indices->data[i];if(index>=(bits->capacityFlags&0x7fffffff))bits->FUN_009b2130(index+1,0);int slot=index>>5;bits->data[slot]|=1<<(index&31);}}
}
}   // namespace f3m_00934950

// @f3 0x00933610 (community match, verified in this file)
extern int DAT_00e43f14;
extern int G;
namespace f3m_00933610 {

static __declspec(noinline) void FUN_00933510(int a, int l, int b, int c)
{
    G = a + l + b + c;
}

void FUN_00933610(int a, int b)
{
    FUN_00933510((int)&DAT_00e43f14, a, b, 1);
}
}   // namespace f3m_00933610

// @f3 0x00923830 (community match, verified in this file)
namespace f3m_00923830 {

class SpanBuffer923830 {
public:
    char* data;
    int size;
    unsigned int capacityAndFlags;

    SpanBuffer923830* FUN_00923830(DataSpan* span);
};

SpanBuffer923830* SpanBuffer923830::FUN_00923830(DataSpan* span)
{
    int pos = size - 1;
    int count = span->length - 1;
    int required = pos + count + 1;

    int capacity = capacityAndFlags & 0x3fffffff;
    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        FUN_00901e90((ByteBuffer*)this, newCapacity, 1);
    }

    size = required;
    FUN_009234e0(data + pos, span->data, count + 1);

    return this;
}
}   // namespace f3m_00923830

// @f3 0x00936ab0 (community match, verified in this file)
namespace f3m_00936ab0 {
struct Src { int a; int b; };
struct Rec {
    void* f0;
    void* f4;
    Rec(Src* s, const char* k);
    short* At16(int i);
    char* At8(int i);
};
static short helper(Src* s, const char* k);

volatile int g_src[2];
volatile int g_flag;
volatile int g_out;

static __declspec(noinline) void FUN_00936ab0(Src* s, char flag)
{
    static short id = -1;
    if (id == -1)
        id = helper(s, "TYPE_LIN");
    {
        Rec a(s, "type");
        *a.At16(0) = id;
    }
    {
        Rec b(s, "axisIndex");
        *b.At8(0) = flag;
    }
}

static __declspec(noinline) short helper(Src* obj, const char* name)
{
    Rec tmp(obj, "type");
    return (short)((int)name + (int)tmp.At8(0));
}

void caller_of_FUN_00936ab0()
{
    FUN_00936ab0((Src*)g_src, (char)g_flag);
}
}   // namespace f3m_00936ab0

// @f3 0x009303a0 (community match, verified in this file)
extern int DAT_010f3410;
extern float FUN_00e12730;
extern float FUN_00dbe7b8;
extern float FUN_00dfcd00;
namespace f3m_009303a0 {
struct FUN_009303a0_Stream
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;

    void FUN_00555790(unsigned int count);
    void FUN_005b3880(unsigned int index, int* value);
};

struct FUN_009303a0_Data
{
    int zero0;
    int zero1;
    float f0;
    float f1;
    float f2;
    float f3;
};


int __cdecl FUN_00847b50(int value);

class FUN_009303a0_Obj
{
public:
    void FUN_008f8bb0(FUN_009303a0_Stream* s);
    void FUN_008f8840(int* data);
    void FUN_009303a0(int param);
};

// pdb: bhkLiquidAction::GetViewerStrings | bhkLiquidAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void FUN_009303a0_Obj::FUN_009303a0(int param)
{
    FUN_009303a0_Stream* stream = (FUN_009303a0_Stream*)param;

    FUN_008f8bb0(stream);
    int value = FUN_00847b50(DAT_010f3410);

    unsigned int index = stream->unk0A;
    unsigned int count = stream->unk08;

    if (index >= count)
        stream->FUN_00555790((unsigned int)stream->unk0E + index);

    stream->FUN_005b3880(index, &value);

    FUN_009303a0_Data data;
    data.zero0 = 0;
    data.zero1 = 0;
    data.f0 = FUN_00e12730;
    data.f1 = FUN_00dbe7b8;
    data.f2 = FUN_00dfcd00;
    data.f3 = FUN_00dbe7b8;

    FUN_008f8840((int*)&data);
}
}   // namespace f3m_009303a0

// @f3 0x0093c770 (community match, verified in this file)
namespace task1734 {
struct Writer {virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void Write(void*,unsigned);};
struct View {void* data;void* info;void FUN_0093d600(void*,const char*);void** FUN_0093d670(int);unsigned FUN_0093d650();};
extern const char DAT_00e6e8f0[],DAT_00e14950[];
static __declspec(noinline) void FUN_0093c6d0(const char* firstName,void* first,Writer* writer,void* second,const char* secondName){
 View a,b;a.FUN_0093d600(first,firstName);b.FUN_0093d600(second,secondName);
 void** source=a.FUN_0093d670(0);*b.FUN_0093d670(1)=*source;
 unsigned size=b.FUN_0093d650();writer->Write(*b.FUN_0093d670(1),size+4);
}
void __cdecl FUN_0093c770(void* first,void* second,Writer* writer){FUN_0093c6d0(DAT_00e6e8f0,first,writer,second,DAT_00e14950);}
}

// @f3 0x0092c2b0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0092c2b0 {
struct Stream92c2b0 { unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14C;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15C;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16C;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17C;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18C;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19C;unsigned int unk1A0;unsigned int unk1A4;unsigned int unk1A8;unsigned int unk1AC;unsigned int unk1B0;unsigned int unk1B4;unsigned int unk1B8;unsigned int unk1BC;unsigned int unk1C0;unsigned int unk1C4;unsigned int unk1C8;unsigned int unk1CC;unsigned int unk1D0;unsigned int unk1D4;unsigned int unk1D8;unsigned int unk1DC;unsigned int unk1E0; unsigned char native; };
struct Blob92c2b0 { unsigned long unk00;unsigned long unk04;unsigned long unk08;unsigned long unk0C;unsigned long unk10;unsigned long unk14;unsigned long unk18;unsigned long unk1C;unsigned long unk20;unsigned long unk24;unsigned long unk28;unsigned long unk2C;unsigned long unk30;unsigned long unk34; };
static __forceinline void SwapWord92c2b0(unsigned long& value){value=_byteswap_ulong(value);}
static __forceinline void Swap92c2b0(Blob92c2b0* b){SwapWord92c2b0(b->unk10);SwapWord92c2b0(b->unk14);SwapWord92c2b0(b->unk18);SwapWord92c2b0(b->unk1C);SwapWord92c2b0(b->unk20);SwapWord92c2b0(b->unk24);SwapWord92c2b0(b->unk28);SwapWord92c2b0(b->unk2C);SwapWord92c2b0(b->unk30);SwapWord92c2b0(b->unk34);}
struct Obj92c2b0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); 
    virtual Blob92c2b0* GetBlob(bool* created);
    void FUN_008f8970(Stream92c2b0* s);
    void FUN_0092c2b0(Stream92c2b0* s);
    __forceinline void SwapIt(Stream92c2b0* s) {
        if (s->native != 1) {
            bool created;
            Blob92c2b0* b = GetBlob(&created);
            if (b) Swap92c2b0(b);
        }
    }
};
// pdb: bhkOrientHingedBodyAction::SaveBinary | bhkOrientHingedBodyAction.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arStream
void Obj92c2b0::FUN_0092c2b0(Stream92c2b0* s)
{
    SwapIt(s);
    FUN_008f8970(s);
    SwapIt(s);
}

}   // namespace f3m_0092c2b0

// @f3 0x0092f770 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0092f770 {
struct Stream92c2b0 { unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14C;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15C;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16C;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17C;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18C;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19C;unsigned int unk1A0;unsigned int unk1A4;unsigned int unk1A8;unsigned int unk1AC;unsigned int unk1B0;unsigned int unk1B4;unsigned int unk1B8;unsigned int unk1BC;unsigned int unk1C0;unsigned int unk1C4;unsigned int unk1C8;unsigned int unk1CC;unsigned int unk1D0;unsigned int unk1D4;unsigned int unk1D8;unsigned int unk1DC;unsigned int unk1E0; unsigned char native; };
struct Blob92c2b0 {unsigned long unk00;unsigned long unk04;unsigned long unk08;unsigned long unk0C;unsigned long unk10;unsigned long unk14;};
static __forceinline void SwapWord92c2b0(unsigned long& value){value=_byteswap_ulong(value);}
static __forceinline void Swap92c2b0(Blob92c2b0* b){SwapWord92c2b0(b->unk08);SwapWord92c2b0(b->unk0C);SwapWord92c2b0(b->unk10);SwapWord92c2b0(b->unk14);}
struct Obj92c2b0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); 
    virtual Blob92c2b0* GetBlob(bool* created);
    void FUN_008f8970(Stream92c2b0* s);
    void FUN_0092f770(Stream92c2b0* s);
    __forceinline void SwapIt(Stream92c2b0* s) {
        if (s->native != 1) {
            bool created;
            Blob92c2b0* b = GetBlob(&created);
            if (b) Swap92c2b0(b);
        }
    }
};
// pdb: bhkLiquidAction::SaveBinary | bhkLiquidAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Obj92c2b0::FUN_0092f770(Stream92c2b0* s)
{
    SwapIt(s);
    FUN_008f8970(s);
    SwapIt(s);
}

}   // namespace f3m_0092f770

// @f3 0x0093cb20 (community match, verified in this file)
extern char DAT_00e3bd24;
namespace f3m_0093cb20 {


// pdb: hkDataObjectNative::hasMember | hkDataObjectNative.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|vtable) + skyrim(caller_sim), high
static __declspec(noinline) int hkDataObjectNative_hasMember(int x, char* a)
{
    return x + (int)a;
}

static __declspec(noinline) int FUN_0093cb20(int x, int c)
{
    return hkDataObjectNative_hasMember(x, &DAT_00e3bd24);
}

void emit_0093cb20(int x, int c) { FUN_0093cb20(x, c); }
}   // namespace f3m_0093cb20

// @f3 0x009327e0 (community match, verified in this file)
extern const char DAT_00e4c974[];
extern const char DAT_00e430f0[];
namespace f3m_009327e0 {
namespace f3m_009327e0 {
struct Field {
    void* unk00;
    int unk04;
    Field(void* obj, const char* name);
    int* FUN_0093d6b0(int index);
};
}
void __cdecl FUN_009327e0(void* src, void* dst)
{
    f3m_009327e0::Field a(src, DAT_00e4c974);
    f3m_009327e0::Field b(dst, DAT_00e430f0);
    int* p = a.FUN_0093d6b0(0);
    *b.FUN_0093d6b0(0) = *p;
}
}   // namespace f3m_009327e0

// @f3 0x00922d60 (community match, verified in this file)
namespace f3m_00922d60 {
struct Alloc_922d60;
__declspec(dllimport) Alloc_922d60* __stdcall FUN_00d9b080(unsigned long);
extern unsigned long DAT_010f3170;
struct Alloc_922d60 {
    void* FUN_008f6d30(unsigned int size, int tag);
    void FUN_008f6d90(void* p, unsigned int size, int tag);
};

struct Map922 {
    int* m_table;
    int m_flags;
    int m_mask;
    void FUN_00922d60(int newSize);
    void FUN_00922710(unsigned int key, int val);
};

// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::resizeTable | hkMap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: alloc, newcap
void Map922::FUN_00922d60(int newSize)
{
    int oldFlags = m_flags & 0x80000000;
    int oldCount = m_mask + 1;
    int* oldTable = m_table;

    Alloc_922d60* alloc = FUN_00d9b080(DAT_010f3170);
    m_table = (int*)alloc->FUN_008f6d30((unsigned int)newSize * 8, 0x17);

    for (int i = 0; i < newSize; ++i)
        m_table[i] = -1;

    m_mask = newSize - 1;
    m_flags = 0;

    for (int i = 0; i < oldCount; ++i) {
        int key = oldTable[i];
        if (key != -1)
            FUN_00922710((unsigned int)key, oldTable[oldCount + i]);
    }

    if (oldFlags == 0) {
        Alloc_922d60* al = FUN_00d9b080(DAT_010f3170);
        al->FUN_008f6d90(oldTable, (unsigned int)oldCount * 8, 0x17);
    }
}
}

// @f3 0x00937c10 (community match, verified in this file)
extern short DAT_0105f548;
extern short DAT_0105f5b4;
namespace f3m_00937c10 {
namespace f3m_00937c10 {
namespace f3m_00937c10 {
struct Target_77f0 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int size);
};
short __cdecl FUN_00936710(const char* name);
struct Pair_77f0 {
    int a;
    int b;
    Pair_77f0() {}
};
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600() {}
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
    FUN_0093d600 FUN_0093d7a0(const char* name);
    Pair_77f0 FUN_0093d810();
};
struct Local_7f0 {
    int unk00;
    int unk04;
    Local_7f0(int value);
};
short __cdecl FUN_00936690(FUN_0093d600* acc);
static __declspec(noinline) short FUN_009366b0(FUN_0093d600* acc)
{
    return FUN_00936690(acc);
}
static __declspec(noinline) void FUN_00936750(void* obj, int value, Target_77f0* target)
{
    int* pv = &value;
    if (DAT_0105f548 == -1)
        DAT_0105f548 = FUN_00936710("TYPE_BRIDGE");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f548;
    FUN_0093d600 data(obj, "constraintData");
    *data.FUN_0093d670(0) = value;
    target->Set(value, data.FUN_0093d660());
}
}
using namespace f3m_00937c10;

void __cdecl FUN_00937c10(int a1, int* obj, Target_77f0* target)
{
    FUN_0093d600 atoms(obj, "atoms");
    Local_7f0 local(a1);
    if (DAT_0105f5b4 == -1)
        DAT_0105f5b4 = FUN_009366b0(&atoms);
    FUN_00936750(&atoms.FUN_0093d7a0("bridgeAtom").FUN_0093d810(), *obj, target);
}
}
}   // namespace f3m_00937c10

// @f3 0x0093c8e0 (community match, verified in this file)
namespace w93c8e0 {
struct Variant93c8e0 { const char* getName() const; };
struct Entry93c8e0 { int key; Variant93c8e0* variant; };
struct List93c8e0 { Entry93c8e0* entries; int count; };
int __cdecl Cmp93c8e0(const char* a, const char* b);
void __cdecl FUN_0093c7d0(int key, List93c8e0* owner);
static __declspec(noinline) int FUN_0093c880(List93c8e0* self)
{
    for (int i = 0; i < self->count; i++)
    {
        const Entry93c8e0* entry = &self->entries[i];
        if (Cmp93c8e0(entry->variant->getName(), "hkRootLevelContainer") == 0)
            FUN_0093c7d0(self->entries[i].key, self);
    }
    return 0;
}
struct Registry93c8e0 { void* FUN_009b20b0(const char*); };
extern Registry93c8e0* DAT_011693ac;
extern char DAT_0105f85c[];
int __cdecl FUN_00940060(void*, void*, const void*, void*);
// pdb: hkDataWorldNative::findObject | hkDataObjectNative.obj | fnv360_1110_retail, objrun_open, low
// pdb params: handle
int __cdecl FUN_0093c8e0(List93c8e0* a, void* b)
{
    void* version = DAT_011693ac->FUN_009b20b0("Havok-4.0.0-b1");
    if (!FUN_00940060(a, b, DAT_0105f85c, version)) {
        FUN_0093c880(a);
        return 0;
    }
    return 1;
}
}

// @f3 0x0093c1e0 (community match, verified in this file)
namespace f3m_0093c1e0 {
namespace w93c1e0 {
struct Pair { int first,second; };
struct Source { Pair* data; int count; Pair Get(int i) { Pair* p = data + i; return *p; } };
struct FUN_0093c1e0 { int unk00,unk04,unk08; void* data; int count,capacity; void FUN_00922cb0(); void FUN_00922710(Pair); void FUN_0093c130(Source*); FUN_0093c1e0(Source*); };
FUN_0093c1e0::FUN_0093c1e0(Source* source) {
 FUN_00922cb0(); data=0; count=0; capacity=0x80000000;
 for(int i=0;i<source->count;++i) FUN_00922710(source->Get(i));
 FUN_0093c130(source);
}
}
}   // namespace f3m_0093c1e0

// @f3 0x00933360 (community match, verified in this file)
namespace n933360 {
struct Pair { void* data; void* type; };
struct Acc {
    void* unk00;
    int unk04;
    Acc(void* obj, const char* name);
    Pair FUN_0093d810();
};
typedef void (__cdecl* Fn)(Pair*, Pair*, int);
extern const char DAT_00e393f0[];
void __cdecl FUN_009331e0(Pair* a, Pair* b, int c);
static __declspec(noinline) void FUN_009332d0(void* src, void* dst, const char* name, int arg, Fn fn)
{
    Acc a(src, name);
    Acc b(dst, name);
    Pair pa;
    pa.type = a.FUN_0093d810().type;
    pa.data = a.FUN_0093d810().data;
    Pair pb;
    pb.type = b.FUN_0093d810().type;
    pb.data = b.FUN_0093d810().data;
    fn(&pa, &pb, arg);
}
}
void __cdecl FUN_00933360(void* src, void* dst, int arg)
{
    n933360::FUN_009332d0(src, dst, n933360::DAT_00e393f0, arg, n933360::FUN_009331e0);
}

// @f3 0x00934c90 (community match, verified in this file)
namespace f3m_00934c90 {
namespace f3m_00934c90 {
struct QPair { int x; int y; };
struct QSrc { QPair FUN_0093d810() const; };
void __cdecl FUN_00934c20(QPair* a, QPair* b, int value);

static __declspec(noinline) void FUN_00934c90(const QSrc* first, const QSrc* second, int value)
{
    QPair a;
    QPair b;
    a.x = first->FUN_0093d810().x;
    a.y = first->FUN_0093d810().y;
    b.x = second->FUN_0093d810().x;
    b.y = second->FUN_0093d810().y;
    FUN_00934c20(&a, &b, value);
}

volatile int g_in_00934c90;
void caller_of_FUN_00934c90()
{
    FUN_00934c90((const QSrc*)g_in_00934c90, (const QSrc*)g_in_00934c90, g_in_00934c90);
}
}
}   // namespace f3m_00934c90

// @f3 0x00937860 (community match, verified in this file)
extern short DAT_0105f5a4;
extern short DAT_0105f548;
namespace f3m_00937860 {
namespace n937860 {
struct Target {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int size);
};
short __cdecl FUN_00936710(const char* name);
struct Pair { int a; int b; Pair() {} };
struct Acc {
    void* unk00;
    int unk04;
    Acc() {}
    Acc(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    int FUN_0093d660();
    Acc FUN_0093d7a0(const char* name);
    Pair FUN_0093d810();
};
short __cdecl FUN_00936690(Acc* acc);
static __declspec(noinline) short FUN_009366b0(Acc* acc)
{
    return FUN_00936690(acc);
}
static __declspec(noinline) void FUN_00936750(void* obj, int value, Target* target)
{
    int* pv = &value;
    if (DAT_0105f548 == -1)
        DAT_0105f548 = FUN_00936710("TYPE_BRIDGE");
    Acc type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f548;
    Acc data(obj, "constraintData");
    *data.FUN_0093d670(0) = value;
    target->Set(value, data.FUN_0093d660());
}
}
using namespace n937860;
void __cdecl FUN_00937860(int a1, int* obj, Target* target)
{
    Acc atoms(obj, "atoms");
    if (DAT_0105f5a4 == -1)
        DAT_0105f5a4 = FUN_009366b0(&atoms);
    FUN_00936750(&atoms.FUN_0093d7a0("bridgeAtom").FUN_0093d810(), *obj, target);
}
}   // namespace f3m_00937860

// @f3 0x0092e830 (community match, verified in this file)
namespace n92e830 {
struct RefObj {
    virtual void DeleteThis(int flags);
    int unk04;
    int unk08;
    int unk0c;
    int refCount;
    void IncRef() { ++refCount; }
    void DecRef() { if (--refCount == 0) DeleteThis(1); }
};
}
using namespace n92e830;
extern RefObj* DAT_010f3400;
void __cdecl FUN_0092e830(RefObj* obj)
{
    if (obj)
        obj->IncRef();
    if (DAT_010f3400)
        DAT_010f3400->DecRef();
    DAT_010f3400 = obj;
}

// @f3 0x00923940 (community match, verified in this file)
namespace f3m_00923940 {
namespace Str923 {
__declspec(noinline) char __cdecl FUN_00923250(char c)
{
    if ((unsigned char)(c - 'A') <= 25)
        c += 0x20;
    return c;
}
struct Str {
    char* data;
    int length;
    void FUN_00923940();
};
void Str::FUN_00923940()
{
    for (int i = 0; i < length - 1; ++i)
        data[i] = FUN_00923250(data[i]);
}
}
}   // namespace f3m_00923940

// @f3 0x00921790 (community match, verified in this file)
namespace f3m_00921790 {
class FUN_00921790_Obj
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
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;

    FUN_00921790_Obj& FUN_00921790(const FUN_00921790_Obj& source);
};

// pdb: hkpCollidable::hkpCollidable | hkpMouseSpringAction.obj | fnv360_0822_retail, call_gap, high
// pdb params: shape, shape, t, ms, type, type
FUN_00921790_Obj& FUN_00921790_Obj::FUN_00921790(const FUN_00921790_Obj& source)
{
    unk00 = source.unk00;
    unk04 = source.unk04;
    unk08 = source.unk08;
    unk0C = source.unk0C;
    unk10 = source.unk10;
    unk20 = source.unk20;
    unk24 = source.unk24;
    unk28 = source.unk28;
    unk2C = source.unk2C;
    unk30 = source.unk30;
    unk34 = source.unk34;
    unk38 = source.unk38;
    unk3C = source.unk3C;
    unk40 = source.unk40;
    unk44 = source.unk44;
    unk48 = source.unk48;
    unk4C = source.unk4C;
    return *this;
}
}   // namespace f3m_00921790

// @f3 0x00936890 (community match, verified in this file)
extern short DAT_0105f550;
namespace f3m_00936890 {
namespace f3m_00936890 {
namespace n936890 {
struct Translation { float v[4]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    Translation* FUN_0093d720(int index);
    struct R1* FUN_0093d790(const char* name, short* out);
};
struct R2 { void FUN_009b2360(); };
struct R1 { R2* FUN_0093d8b0(); };
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    short id;
    FUN_0093d600 f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}
static __declspec(noinline) void FUN_00936890(void* obj, const Translation* a, const Translation* b)
{
    void** po = &obj;
    if (DAT_0105f550 == -1)
        DAT_0105f550 = FUN_00936710(obj, "TYPE_SET_LOCAL_TRANSLATIONS");
    { FUN_0093d600 f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f550; }
    { FUN_0093d600 f(obj, "translationA"); *f.FUN_0093d720(0) = *a; }
    { FUN_0093d600 f(obj, "translationB"); *f.FUN_0093d720(0) = *b; }
}
void* volatile g_obj; Translation* volatile g_a; Translation* volatile g_b;
void caller_of_FUN_00936890() { FUN_00936890(g_obj, g_a, g_b); }
}
}
}   // namespace f3m_00936890

// @f3 0x0092ebc0 (community match, verified in this file)
namespace f3m_0092ebc0 {
struct RefObject {
    virtual void vf00(int value);
    short unk04;
    short unk06;
};
struct Holder { RefObject* unk00; };
struct Node {
    int unk00;
    Node* unk04;
    Holder* unk08;
};
struct Alloc { void FUN_008f6d90(void* p, unsigned int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long);
extern "C" unsigned long DAT_010f3170;
extern "C" Node* DAT_0116932c;
void __cdecl FUN_00901f10(void* arr, int stride);

// pdb: hkBaseSystem::quitSingletons | hkBaseSystem.obj | fnv360_0822_retail, objrun, medium
void __cdecl FUN_0092ebc0(void)
{
    struct { Node** data; int count; unsigned int cap; Node* buf[128]; } loc;
    loc.data = loc.buf; loc.count = 0; loc.cap = 0x80000080;
    for (Node* n = DAT_0116932c; n; n = n->unk04) {
        if (loc.count == (int)(loc.cap & 0x3fffffff)) FUN_00901f10(&loc, 4);
        loc.data[loc.count++] = n;
    }
    for (int i = loc.count - 1; i >= 0; i--) {
        RefObject* o = loc.data[i]->unk08->unk00;
        if (o->unk04) {
            if (--o->unk06 == 0) o->vf00(1);
        }
        loc.data[i]->unk08->unk00 = 0;
    }
    if ((loc.cap & 0x80000000u) == 0) {
        unsigned int n = loc.cap & 0x3fffffff;
        Alloc* a = FUN_00d9b080(DAT_010f3170);
        a->FUN_008f6d90(loc.data, n * 4, 0x17);
    }
}
}

// @f3 0x0092ae30 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_0092ae30 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier();
namespace n92ae30 {
struct Alloc {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int maxNumElemsOnFreeList;
    void* unk38; void* unk3c; void* unk40; void* unk44; void* unk48; void* unk4c; void* unk50; void* unk54; void* unk58; void* unk5c; void* unk60; void* unk64; void* unk68; void* unk6c;
    void* head7;
    int count7;
    void FUN_008f6890(int row, void* p, int tag);
};
}
struct Obj92ae30 {
    int unk00; int unk04; int unk08;
    void* block;
    void FUN_0092ae30(bool release);
};
// pdb: bhkCharacterProxy::KillCinfo | bhkCharacterProxy.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: abCreated
void Obj92ae30::FUN_0092ae30(bool release)
{
    if (!release) return;
    void* p = block;
    if (p) {
        n92ae30::Alloc* m = (n92ae30::Alloc*)TlsGetValue(DAT_010f3170);
        if (m->count7 >= m->maxNumElemsOnFreeList) m->FUN_008f6890(7, p, 0xd);
        else { _ReadWriteBarrier(); void* next = m->head7; m->count7++; *(void**)p = next; m->head7 = p; }
    }
    block = 0;
}
}   // namespace f3m_0092ae30

// @f3 0x0093c740 (community match, verified in this file)
namespace f3m_0093c740 {
struct Writer { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void Write(void*, unsigned); };
struct View { void* data; void* info; void FUN_0093d600(void*, const char*); void** FUN_0093d670(int); unsigned FUN_0093d650(); };
extern const char DAT_00e3b278[];
static __declspec(noinline) void FUN_0093c6d0(const char* firstName, void* first, Writer* writer, void* second, const char* secondName)
{
    View a, b;
    a.FUN_0093d600(first, firstName);
    b.FUN_0093d600(second, secondName);
    void** source = a.FUN_0093d670(0);
    *b.FUN_0093d670(1) = *source;
    unsigned size = b.FUN_0093d650();
    writer->Write(*b.FUN_0093d670(1), size + 4);
}
}
// pdb: hkDataObjectNative::accessByName | hkDataObjectNative.obj | fnv360_0822_retail, objrun_open, low
// pdb params: name
void __cdecl FUN_0093c740(void* first, void* second, f3m_0093c740::Writer* writer)
{
    f3m_0093c740::FUN_0093c6d0(f3m_0093c740::DAT_00e3b278, first, writer, second, f3m_0093c740::DAT_00e3b278);
}

// @f3 0x00923900 (community match, verified in this file)
namespace f3m_00923900 {
__declspec(noinline) char __cdecl FUN_00923230(char c)
{
    if ((unsigned char)(c - 'a') <= 25)
        c -= 0x20;
    return c;
}

struct FUN_00923900_cls {
    char* data;
    int count;
    void FUN_00923900();
};

// pdb: hkStringBuf::setJoin | hkStringBuf.obj | fnv360_0822_retail, objrun_open, low
// pdb params: s0, s1, s2, s3, s4, s5
void FUN_00923900_cls::FUN_00923900()
{
    for (int i = 0; i < count - 1; ++i)
        data[i] = FUN_00923230(data[i]);
}
}   // namespace f3m_00923900

// @f3 0x00932780 (community match, verified in this file)
extern const char DAT_00e49e30;
extern const char DAT_00e4005c;
namespace f3m_00932780 {
struct PairQ { int first; int second; };
struct AccessQ : f3m_00936750::FUN_0093d600 {
    AccessQ(void* object, const char* name) : f3m_00936750::FUN_0093d600(object, name) {}
    PairQ* FUN_0093d760(int index);
};
// pdb: hkDataObjectNative::accessByName | hkDataObjectNative.obj | fnv360_0822_debug, objrun_open, low
// pdb params: name
void FUN_00932780(void* firstObject, void* secondObject) {
    AccessQ first(firstObject, &DAT_00e49e30);
    AccessQ second(secondObject, &DAT_00e4005c);
    *second.FUN_0093d760(0) = *first.FUN_0093d760(0);
}
}   // namespace f3m_00932780

// @f3 0x00933a20 (community match, verified in this file)
namespace Version2068 {
struct ClassInfo {const char* FUN_009b0490()const;};
struct Variant {void* object;ClassInfo* type;};
struct VariantArray {Variant* data;int size;};
extern ClassInfo DAT_01117274,DAT_01117694,DAT_01117de4;
extern const char DAT_00e54f38[],DAT_00e55124[],DAT_00e55574[];
extern int __cdecl hkString_strCmp(const char*,const char*);
static __declspec(noinline) void FUN_009339a0(VariantArray* objects) {
    for(int i=0;i<objects->size;++i) {
        const char* name=objects->data[i].type->FUN_009b0490();
        if(hkString_strCmp(name,DAT_00e54f38)==0)objects->data[i].type=&DAT_01117274;
        else if(hkString_strCmp(name,DAT_00e55124)==0)objects->data[i].type=&DAT_01117694;
        else if(hkString_strCmp(name,DAT_00e55574)==0)objects->data[i].type=&DAT_01117de4;
    }
}
struct ClassRegistry;
struct Versions {ClassRegistry* FUN_009b20b0(const char*);};
extern Versions* DAT_011693ac;
struct Description;
extern const Description DAT_0105ee10;
extern int __cdecl FUN_00940060(VariantArray*,void*,const Description*,ClassRegistry*);
int __cdecl FUN_00933a20(VariantArray* objects,void* tracker) {
    FUN_009339a0(objects);
    ClassRegistry* registry=DAT_011693ac->FUN_009b20b0("Havok-4.6.1-r1");
    return FUN_00940060(objects,tracker,&DAT_0105ee10,registry);
}
}

// @f3 0x009367e0 (community match, verified in this file)
extern short DAT_0105f54c;
namespace f3m_009367e0 {
namespace f3m_009367e0 {
namespace n9367e0 {
struct Transform { float m[16]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    Transform* FUN_0093d740(int index);
    struct R1* FUN_0093d790(const char* name, short* out);
};
struct R2 { void FUN_009b2360(); };
struct R1 { R2* FUN_0093d8b0(); };
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    short id;
    FUN_0093d600 f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}
void FUN_009367e0(void* obj, const Transform* a, const Transform* b)
{
    if (DAT_0105f54c == -1)
        DAT_0105f54c = FUN_00936710(obj, "TYPE_SET_LOCAL_TRANSFORMS");
    { FUN_0093d600 f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f54c; }
    { FUN_0093d600 f(obj, "transformA"); *f.FUN_0093d740(0) = *a; }
    { FUN_0093d600 f(obj, "transformB"); *f.FUN_0093d740(0) = *b; }
}
}
}
}   // namespace f3m_009367e0

// @f3 0x0093d260 (community match, verified in this file)
extern const char DAT_00e3fb6c[];
extern const char DAT_00e3fb4c[];
extern int DAT_010f3170;
namespace f3m_0093d260 {
extern "C" void* (__stdcall* const DAT_00fdf044)(unsigned long);
namespace f3m_0093d260 {
struct Pair {
    void* ptr;
    int count;
};
struct Alloc {
    Pair* FUN_008f6f60(int size, int tag);
};
struct Field {
    void* unk00;
    int unk04;
    Field(void* obj, const char* name);
    unsigned char* FUN_0093d640(unsigned char* result);
    Pair* FUN_0093d760(int index);
};
struct Target {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(Pair* p);
};
}
using namespace f3m_0093d260;
void __cdecl FUN_0093d260(void* object, void* secondObject, Target* target)
{
    Field first(object, DAT_00e3fb6c);
    Field second(secondObject, DAT_00e3fb4c);
    unsigned char result;
    if (!*first.FUN_0093d640(&result))
        return;
    if (!*second.FUN_0093d640(&result))
        return;
    f3m_0093d260::Alloc* alloc = static_cast<f3m_0093d260::Alloc*>(DAT_00fdf044(DAT_010f3170));
    Pair* p = alloc->FUN_008f6f60(8, 5);
    target->v0c(p);
    *p = *first.FUN_0093d760(0);
    Pair* m = second.FUN_0093d760(0);
    m->ptr = p;
    m->count = 1;
}
}   // namespace f3m_0093d260

// @f3 0x009318b0 (community match, verified in this file)
namespace f3m_009318b0 {
namespace RefQueue2070 {
struct Object;
struct Command {unsigned char operation,unk01,unk02,unk03;Object* object;};
struct World {
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int pending;
    void FUN_00902570(Command*);
};
struct Object {
    void* table;unsigned short memorySize;short references;World* world;
    void FUN_009318b0();
};
void Object::FUN_009318b0() {
    Command command;
    World* current=world;
    if(current&&current->pending) {
        command.object=this;
        command.operation=0x1d;
        current->FUN_00902570(&command);
    } else {
        if(memorySize)++references;
    }
}
}
}   // namespace f3m_009318b0

// @f3 0x009222e0 (community match, verified in this file)
namespace f3m_009222e0 {
extern void*(__stdcall*DAT_00d9b080)(unsigned long);

namespace Free358{extern unsigned long DAT_010f3170;struct Block{Block*next;__forceinline void SetNext(Block*value){next=value;}};struct Heap{

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

int limit;

unsigned int unk38;

unsigned int unk3c;

unsigned int unk40;

unsigned int unk44;

unsigned int unk48;

unsigned int unk4c;

unsigned int unk50;

unsigned int unk54;

Block*head;

int count;

void FUN_008f6890(int,void*,int);__forceinline void Push(Block*block){++count;block->next=head;head=block;}static void Free(Block*block){if(block){Heap*heap=(Heap*)DAT_00d9b080(DAT_010f3170);if(*(volatile int*)&heap->count>=heap->limit)heap->FUN_008f6890(4,block,2);else heap->Push(block);}}};

struct Owner{unsigned int unk00,unk04,unk08;Block*data;void FUN_009222e0(bool);};

// pdb: bhkTriSampledHeightFieldBvTreeShape::KillCinfo | bhkTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: abCreated
void Owner::FUN_009222e0(bool enabled){if(enabled){Heap::Free(data);data=0;}}

}







}   // namespace f3m_009222e0

// @f3 0x0092adb0 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_0092adb0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace f3m_0092adb0 {
struct Free92adb0 { Free92adb0* next; };
struct Pool92adb0 {
    void* u00; void* u04; void* u08; void* u0c; void* u10; void* u14; void* u18; void* u1c;
    void* u20; void* u24; void* u28; void* u2c; void* u30; void* u34; void* u38; void* u3c;
    void* u40; void* u44; void* u48; void* u4c; void* u50; void* u54; void* u58; void* u5c;
    void* u60; void* u64; void* u68; void* u6c;
    Free92adb0* head;
    int count;
    void* FUN_008f6800(unsigned int a, unsigned int b);
    void* Allocate()
    {
        void* p;
        if (head) {
            --count;
            Free92adb0* n = head;
            head = n->next;
            p = n;
        } else {
            p = FUN_008f6800(7, 0xd);
        }
        return p;
    }
};
struct Obj92adb0 {
    int unk00;
    void FUN_008e8b80() throw();
    Obj92adb0() throw() { FUN_008e8b80(); }
    static void* operator new(unsigned int) throw() { return ((Pool92adb0*)TlsGetValue(DAT_010f3170))->Allocate(); }
    static void operator delete(void*) throw() {}
};
struct Link92adb0 { void FUN_0091ddf0(Obj92adb0* obj); };
struct Owner92adb0 {
    int unk00;
    int unk04;
    Link92adb0* link;
    Obj92adb0* obj;
    Obj92adb0* FUN_0092adb0(bool* created);
};
// pdb: bhkCharacterProxy::CreateCinfo | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arCreated
Obj92adb0* Owner92adb0::FUN_0092adb0(bool* created)
{
    if (!obj) {
        Obj92adb0* made = new Obj92adb0;
        obj = made;
        if (link)
            link->FUN_0091ddf0(made);
        *created = true;
        return obj;
    }
    *created = false;
    return obj;
}
}
}   // namespace f3m_0092adb0

// @f3 0x009369f0 (community match, verified in this file)
extern short DAT_0105f558;
namespace f3m_009369f0 {
namespace f3m_009369f0 {
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
};
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_009369f0(void* obj)
{
    if (DAT_0105f558 == -1)
        DAT_0105f558 = FUN_00936710(obj, "TYPE_BALL_SOCKET");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f558;
}
void* volatile g_obj_9369f0;
void caller_of_FUN_009369f0() { FUN_009369f0(g_obj_9369f0); }
}
}   // namespace f3m_009369f0

// @f3 0x00936a40 (community match, verified in this file)
extern short DAT_0105f55c;
namespace f3m_00936a40 {
namespace f3m_00936a40 {
struct Transform { float m[16]; };
struct Rotation { float m[12]; };
struct Vec4 { float v[4]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    float* FUN_0093d6a0(int index);
};
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00936a40(void* obj, float length)
{
    if (DAT_0105f55c == -1)
        DAT_0105f55c = FUN_00936710(obj, "TYPE_STIFF_SPRING");
    {
        FUN_0093d600 a(obj, "type");
        *a.FUN_0093d6e0(0) = DAT_0105f55c;
    }
    {
        FUN_0093d600 a(obj, "length");
        *a.FUN_0093d6a0(0) = length;
    }
}
void* volatile g_obj_00936a40;
volatile float g_length_00936a40;
void caller_of_FUN_00936a40() { FUN_00936a40(g_obj_00936a40, g_length_00936a40); }
}
}   // namespace f3m_00936a40

// @f3 0x00936d30 (community match, verified in this file)
extern short DAT_0105f570;
namespace f3m_00936d30 {
namespace f3m_00936d30 {
struct Transform { float m[16]; };
struct Rotation { float m[12]; };
struct Vec4 { float v[4]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    bool* FUN_0093d690(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
    int* FUN_0093d670(int index);
};
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00936d30(void* obj, bool enabled, char axis, short initOffset, short prevOffset, float target, int motor)
{
    if (DAT_0105f570 == -1)
        DAT_0105f570 = FUN_00936710(obj, "TYPE_LIN_MOTOR");
    {
        FUN_0093d600 a(obj, "type");
        *a.FUN_0093d6e0(0) = DAT_0105f570;
    }
    {
        FUN_0093d600 a(obj, "isEnabled");
        *a.FUN_0093d690(0) = enabled;
    }
    {
        FUN_0093d600 a(obj, "motorAxis");
        *a.FUN_0093d710(0) = axis;
    }
    {
        FUN_0093d600 a(obj, "initializedOffset");
        *a.FUN_0093d6e0(0) = initOffset;
    }
    {
        FUN_0093d600 a(obj, "previousTargetPositionOffset");
        *a.FUN_0093d6e0(0) = prevOffset;
    }
    {
        FUN_0093d600 a(obj, "targetPosition");
        *a.FUN_0093d6a0(0) = target;
    }
    {
        FUN_0093d600 a(obj, "motor");
        *a.FUN_0093d670(0) = motor;
    }
}
void* volatile g_obj_00936d30;
volatile bool g_enabled_00936d30;
volatile char g_axis_00936d30;
volatile short g_initOffset_00936d30;
volatile short g_prevOffset_00936d30;
volatile float g_target_00936d30;
volatile int g_motor_00936d30;
void caller_of_FUN_00936d30() { FUN_00936d30(g_obj_00936d30, g_enabled_00936d30, g_axis_00936d30, g_initOffset_00936d30, g_prevOffset_00936d30, g_target_00936d30, g_motor_00936d30); }
}
}   // namespace f3m_00936d30

// @f3 0x00937030 (community match, verified in this file)
extern short DAT_0105f580;
namespace f3m_00937030 {
namespace f3m_00937030 {
struct Transform { float m[16]; };
struct Rotation { float m[12]; };
struct Vec4 { float v[4]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
};
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00937030(void* obj, char enabled, char twistAxis, char refAxis, float minAngle, float maxAngle, float tau)
{
    if (DAT_0105f580 == -1)
        DAT_0105f580 = FUN_00936710(obj, "TYPE_TWIST_LIMIT");
    {
        FUN_0093d600 a(obj, "type");
        *a.FUN_0093d6e0(0) = DAT_0105f580;
    }
    {
        FUN_0093d600 a(obj, "isEnabled");
        *a.FUN_0093d710(0) = enabled;
    }
    {
        FUN_0093d600 a(obj, "twistAxis");
        *a.FUN_0093d710(0) = twistAxis;
    }
    {
        FUN_0093d600 a(obj, "refAxis");
        *a.FUN_0093d710(0) = refAxis;
    }
    {
        FUN_0093d600 a(obj, "minAngle");
        *a.FUN_0093d6a0(0) = minAngle;
    }
    {
        FUN_0093d600 a(obj, "maxAngle");
        *a.FUN_0093d6a0(0) = maxAngle;
    }
    {
        FUN_0093d600 a(obj, "angularLimitsTauFactor");
        *a.FUN_0093d6a0(0) = tau;
    }
}
void* volatile g_obj_00937030;
volatile char g_enabled_00937030;
volatile char g_twistAxis_00937030;
volatile char g_refAxis_00937030;
volatile float g_minAngle_00937030;
volatile float g_maxAngle_00937030;
volatile float g_tau_00937030;
void caller_of_FUN_00937030() { FUN_00937030(g_obj_00937030, g_enabled_00937030, g_twistAxis_00937030, g_refAxis_00937030, g_minAngle_00937030, g_maxAngle_00937030, g_tau_00937030); }
}
}   // namespace f3m_00937030

// @f3 0x00935040 (community match, verified in this file)
namespace f3m_00935040 {
namespace q23 {
struct QClass { const char* FUN_009b0490(); };
struct QSrc { int unk00; QClass* unk04; };
struct FUN_0093d7f0 {
    void* unk00;
    int unk04;
    FUN_0093d7f0(QSrc* src);
};
struct QStream { void FUN_009b2360(); };
struct QItem { QStream* FUN_0093d8b0(); };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    int* FUN_0093d6b0(int index);
    QItem* FUN_0093d790(const char* name, int* out);
};
int __cdecl hkString_strCmp(const char* a, const char* b);
static __declspec(noinline) int FUN_00935000(FUN_0093d7f0* obj, const char* name)
{
    int result;
    FUN_0093d600 f(obj, "type");
    f.FUN_0093d790(name, &result)->FUN_0093d8b0()->FUN_009b2360();
    return result;
}
}
using namespace q23;
// pdb: Copier::getMemberClassAndCheck | hkDataObjectUtil.obj | fnv360_0822_retail, caller_sim, low
// pdb params: member, obj
void __cdecl FUN_00935040(void* unused, QSrc* src)
{
    FUN_0093d7f0 self(src);
    FUN_0093d600 field(&self, "type");
    int* out = field.FUN_0093d6b0(0);
    if (hkString_strCmp(src->unk04->FUN_009b0490(), "hkInterleavedSkeletalAnimation") == 0) {
        FUN_0093d7f0 o(src);
        *out = FUN_00935000(&o, "HK_INTERLEAVED_ANIMATION");
    } else if (hkString_strCmp(src->unk04->FUN_009b0490(), "hkDeltaCompressedSkeletalAnimation") == 0) {
        FUN_0093d7f0 o(src);
        *out = FUN_00935000(&o, "HK_DELTA_COMPRESSED_ANIMATION");
    } else if (hkString_strCmp(src->unk04->FUN_009b0490(), "hkWaveletSkeletalAnimation") == 0) {
        FUN_0093d7f0 o(src);
        *out = FUN_00935000(&o, "HK_WAVELET_COMPRESSED_ANIMATION");
    } else {
        FUN_0093d7f0 o(src);
        *out = FUN_00935000(&o, "HK_UNKNOWN_ANIMATION");
    }
}
}   // namespace f3m_00935040

// @f3 0x0092f910 (community match, verified in this file)
struct Node92 {
    int a;
    int b;
    Node92() : a(0), b(0) {} 
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    void FUN_0049fac0(void* slot);
};

struct Map92 {
    void FUN_00bea7b0(void* key, void** out);
    void FUN_00880f70(void* key, Node92* node);
};

extern Map92 DAT_00f7b6a8;

struct Owner92 {
    int f00, f04, f08, f0c;
    void* f10;
    void FUN_0092f910(void* arg);
};

// pdb: bhkLiquidAction::SetTargetObject | bhkLiquidAction.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject
void Owner92::FUN_0092f910(void* arg)
{
    if (arg == 0) return;
    f10 = arg;
    void* key = arg;
    arg = 0;
    DAT_00f7b6a8.FUN_00bea7b0(key, &arg);
    Node92* node = (Node92*)arg;
    if (node == 0) {
        node = new Node92;
        DAT_00f7b6a8.FUN_00880f70(f10, node);
        if (node == 0) return;
    }
    arg = this;
    node->FUN_0049fac0(&arg);
}

// @f3 0x0092f680 (community match, verified in this file)
namespace f3m_0092f680 {
struct CritSec_010f3194 { int v[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSec_010f3194*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSec_010f3194*);
extern CritSec_010f3194 DAT_010f3194;
void* __cdecl FUN_0089eb90(unsigned int);
struct CloneItem {
int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
CloneItem();
static void* operator new(unsigned n) { return FUN_0089eb90(n); }
};
struct CloneOwner;
struct CloneMethods {
void* unk00; void* unk04; void* unk08; void* unk0C; void* unk10; void* unk14; void* unk18; void* unk1C; void* unk20; void* unk24; void* unk28; void* unk2C; void* unk30; void* unk34; void* unk38; void* unk3C; void* unk40; void* unk44; void* unk48; void* unk4C; void* unk50; void* unk54; void* unk58; void* unk5C; void* unk60; void* unk64; void* unk68; void* unk6C; void* unk70; void* unk74; void* unk78; void* unk7C; void* unk80; void* unk84; void* unk88; void* unk8C; void* unk90; void* unk94; void* unk98; void* unk9C; void* unkA0; void* unkA4; void* unkA8; void* unkAC; void* unkB0; void* unkB4; void* unkB8; void* unkBC; void* unkC0;
void (__thiscall* initialize)(CloneOwner*,CloneItem*,int); };
struct CloneOwner { CloneMethods* methods;CloneItem* FUN_0092f680(int); };
// pdb: bhkLiquidAction::CreateClone | bhkLiquidAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
CloneItem* CloneOwner::FUN_0092f680(int arg) {
    EnterCriticalSection(&DAT_010f3194);
    CloneItem* result = 0;
    result = new CloneItem;
    methods->initialize(this,result,arg);
    LeaveCriticalSection(&DAT_010f3194);
    return result;
}
}

// @f3 0x0093d310 (community match, verified in this file)
namespace n93d310 {
extern unsigned long DAT_010f3170;
struct Alloc { float* FUN_008f6f60(unsigned int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long idx);
void __cdecl FUN_0093e480(void* a, const char* fa, void* b, const char* fb);
struct Arr { void** data; int size; };
struct DArr { float* data; int size; };
struct Member { char pad[0x12]; unsigned short offset; };
struct Klass { Member* FUN_009b06c0(); };
struct R1 { Klass* FUN_0093d890(); };
struct Listener { virtual void v0(); virtual void v1(); virtual void v2(); virtual void Add(void* p); };
struct Acc {
    void* obj;
    int idx;
    Acc(void* o, const char* name);
    bool* FUN_0093d640(bool* out);
    void* FUN_0093d650();
    R1* FUN_0093d790(const char* name);
};
}
void __cdecl FUN_0093d310(void* from, void* to, n93d310::Listener* l)
{
    using namespace n93d310;
    FUN_0093e480(from, "hierarchy", to, "parentIndices");
    Acc a(from, "bones");
    Acc b(to, "referencePose");
    bool t;
    if (!*a.FUN_0093d640(&t) || !*b.FUN_0093d640(&t))
        return;
    Arr* src = (Arr*)a.FUN_0093d650();
    DArr* dst = (DArr*)b.FUN_0093d650();
    int n = src->size;
    dst->size = n;
    Alloc* al = FUN_00d9b080(n93d310::DAT_010f3170);
    dst->data = al->FUN_008f6f60(n * 0x30, 0x3b);
    l->Add(dst->data);
    unsigned int off = a.FUN_0093d790("initialTransform")->FUN_0093d890()->FUN_009b06c0()->offset;
    for (int i = 0; i < src->size; i++)
    {
        const float* s = (const float*)((char*)src->data[i] + off);
        float* d = dst->data + i * 12;
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        d[4] = s[4]; d[5] = s[5]; d[6] = s[6]; d[7] = s[7];
        d[8] = s[8]; d[9] = s[9]; d[10] = s[10]; d[11] = s[11];
    }
}

// @f3 0x00931450 (community match, verified in this file)
namespace f3m_00931450 {
struct Vec3_931450 { float x, y, z; int FUN_00823dc0(const char* n); };
struct Stream_931450 {
    int unk00; int unk04;
    unsigned short unk08; unsigned short unk0a; unsigned short unk0c; unsigned short unk0e;
    void FUN_00555790(unsigned int n);
    void FUN_005b3880(unsigned int idx, int* v);
    void Add(int v) {
        unsigned int n = unk0a;
        if (n >= unk08) FUN_00555790(n + unk0e);
        FUN_005b3880(n, &v);
    }
};
struct HingeData_931450 {
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
    Vec3_931450 perp1;  // 0x30
    float unk3c;
    Vec3_931450 perp2;  // 0x40
    float unk4c;
    Vec3_931450 pivotA; // 0x50
    float unk5c;
    Vec3_931450 axleB;  // 0x60
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
    float unk7c;
    float unk80;
    float unk84;
    float unk88;
    float unk8c;
    Vec3_931450 pivotB; // 0x90
};
struct Base_931450 { void FUN_008fc920(Stream_931450* s); };
struct Hinge_931450 : Base_931450 {
    int unk00;
    HingeData_931450* data;
    void FUN_00931450(Stream_931450* s);
};
// pdb: hkHingeConstraintCinfo::GetViewerStrings | bhkHingeConstraint.obj | fnv360_0822_retail, strset, low
// pdb params: apStrings
void Hinge_931450::FUN_00931450(Stream_931450* s)
{
    FUN_008fc920(s);
    HingeData_931450* d = data;
    if (d) {
        Vec3_931450 v;
        v.x = d->pivotA.x; v.y = d->pivotA.y; v.z = d->pivotA.z;
        s->Add(v.FUN_00823dc0("PivotInA"));
        v.x = d->pivotB.x; v.y = d->pivotB.y; v.z = d->pivotB.z;
        s->Add(v.FUN_00823dc0("PivotInB"));
        v.x = d->axleB.x; v.y = d->axleB.y; v.z = d->axleB.z;
        s->Add(v.FUN_00823dc0("AxleInB"));
        v.x = d->perp1.x; v.y = d->perp1.y; v.z = d->perp1.z;
        s->Add(v.FUN_00823dc0("Perp2AxleInA1"));
        v.x = d->perp2.x; v.y = d->perp2.y; v.z = d->perp2.z;
        s->Add(v.FUN_00823dc0("Perp2AxleInA2"));
    }
}
}   // namespace f3m_00931450

// @f3 0x00923ca0 (community match, verified in this file)
namespace f3m_00923ca0 {
extern void* (__stdcall* const FUN_00d9b080)(unsigned long index);

struct Alloc923ca0 { void* FUN_008f6d30(int size, int tag); };

__declspec(noinline) unsigned char __cdecl FUN_00923230(unsigned char c);

__declspec(noinline) unsigned char __cdecl FUN_00923230(unsigned char c)
{
    unsigned char d = (unsigned char)(c - 'a');
    if (d <= 25)
        c = (unsigned char)(c - 0x20);
    return c;
}

struct Str923ca0 {
    unsigned char* data;
    int size;
    int cap;
    Str923ca0 FUN_00923ca0() const;
};

Str923ca0 Str923ca0::FUN_00923ca0() const
{
    int length = size;
    Alloc923ca0* heap = (Alloc923ca0*)FUN_00d9b080(DAT_010f3170);
    unsigned char* copy = (unsigned char*)heap->FUN_008f6d30(length, 0x16);
    for (int i = 0; i < size - 1; ++i)
        copy[i] = FUN_00923230(data[i]);
    copy[size - 1] = 0;
    Str923ca0 result;
    result.data = copy;
    result.size = size;
    result.cap = size;
    return result;
}
}   // namespace f3m_00923ca0

// @f3 0x0093c520 (community match, verified in this file)
namespace f3m_0093c520 {
namespace f3m_0093c520 {

struct Flag {
    bool v;
    Flag() {}
};

struct Node_0093c520 {
    const char* FUN_009b0490();
};

struct VariantElem {
    int unk00;
    Node_0093c520* node;
};

struct Ref {
    void* unk00;
    int unk04;
    void FUN_0093d600(void* object, const char* name);
    Flag FUN_0093d640();
    VariantElem* FUN_0093d780(int index);
    const char** FUN_0093d680(int index);
};

struct Sink {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Add(const char* name);
};

const char* __cdecl FUN_00923640(const char* entry);

void __cdecl FUN_0093c520(void* variantSource, void* classSource, Sink* sink)
{
    Ref variant;
    Ref className;
    className.FUN_0093d600(classSource, "className");
    variant.FUN_0093d600(variantSource, "variant");
    if (className.FUN_0093d640().v && variant.FUN_0093d640().v) {
        const char* name = FUN_00923640(variant.FUN_0093d780(0)->node->FUN_009b0490());
        sink->Add(name);
        *className.FUN_0093d680(0) = name;
    }
}

}
}   // namespace f3m_0093c520

// @f3 0x009341d0 (community match, verified in this file)
namespace f3m_009341d0 {
namespace f3m_009341d0 {
struct Pair { void* data; void* type; };
struct FUN_0093d600 { unsigned int unk00, unk04; FUN_0093d600(void* obj, const char* name); Pair FUN_0093d810(); };
void __cdecl FUN_00934150(Pair* first, Pair* second, int value);
void __cdecl FUN_009341d0(void* first, void* second, int value)
{
    FUN_0093d600 a(first, "motion");
    FUN_0093d600 b(second, "motion");
    Pair p0;
    p0.data = a.FUN_0093d810().data;
    p0.type = a.FUN_0093d810().type;
    Pair p1;
    p1.data = b.FUN_0093d810().data;
    p1.type = b.FUN_0093d810().type;
    FUN_00934150(&p0, &p1, value);
}
}
}   // namespace f3m_009341d0

// @f3 0x00931610 (community match, verified in this file)
extern int DAT_00e1c7f0;
namespace f3m_00931610 {

struct Header { void* vtable; };
struct Array { void* data; Array() { } };

struct Object : Header, Array {
    unsigned int type, count, capacity;
    Object() { data = 0; count = 0; capacity = 0; type = 1; vtable = &DAT_00e1c7f0; }
    static void* operator new(unsigned int size) { return n926250::DAT_01090a78.FUN_0086b930(size); }
};

struct Owner {
    unsigned int unk00, unk04;
    void* source;
    Array* array;
    void FUN_008fc420(Object*);
    Array* FUN_00931610(bool* created);
};

// pdb: bhkHingeConstraint::CreateCinfo | bhkHingeConstraint.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arCreated
Array* Owner::FUN_00931610(bool* created)
{
    if (!array) {
        array = new Object;
        if (source) FUN_008fc420(static_cast<Object*>(array));
        *created = true;
    } else {
        *created = false;
    }
    return array;
}
}   // namespace f3m_00931610

// @f3 0x00923d10 (community match, verified in this file)
namespace Lower2303 {
struct Pool { void* FUN_008f6d30(unsigned,int); };
extern unsigned DAT_010f3170;
extern Pool* (__stdcall* DAT_00d9b080)(unsigned);
__declspec(noinline) unsigned char __cdecl FUN_00923250(unsigned char value)
{
    if (static_cast<unsigned char>(value-'A') <= static_cast<unsigned char>('Z'-'A'))
        return static_cast<unsigned char>(value+('a'-'A'));
    return value;
}
struct String {
    char* text;
    int size, capacity;
    String(char* value,int length) : text(value), size(length), capacity(length) {}
    String FUN_00923d10() const;
};
String String::FUN_00923d10() const
{
    int length=size;
    Pool* pool=DAT_00d9b080(DAT_010f3170);
    char* copy=static_cast<char*>(pool->FUN_008f6d30(length,0x16));
    for(int i=0;i<size-1;++i)
        copy[i]=FUN_00923250(static_cast<unsigned char>(text[i]));
    copy[size-1]='\0';
    return String(copy,size);
}
}

// @f3 0x00937b10 (community match, verified in this file)
extern short DAT_0105f5ac;
extern short DAT_0105f548;
namespace f3m_00937b10 {
// 0x00937b10 - Havok constraint field helper.
// Builds a lookup for the "atoms" member of the description, interns its 16-bit
// type id once, then builds the "bridgeAtom" sub-lookup and hands the resulting
// field reference to FUN_00936750 (which stores the atom count into the target).


struct Pair
{
    int unk00;
    int unk04;
};

struct FUN_0093d600
{
    int unk00;
    int unk04;
    FUN_0093d600() {}
    FUN_0093d600(Pair* obj, const char* name);
    FUN_0093d600(FUN_0093d600& other);
    FUN_0093d600* FUN_0093d7a0(FUN_0093d600* out, const char* name);
    Pair* FUN_0093d810(Pair* out);
    int FUN_0093d660();
    int FUN_0093d690();
    int FUN_0093d710();
    int FUN_0093d720();
    int FUN_0093d790();
    int FUN_0093d850();
    int FUN_0093d860();
    int FUN_0093d870();
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
};

struct Node_9366b0
{
    char* unk00;
    int unk04;
    int FUN_009b0630();
    Node_9366b0* FUN_009b0650(int n);
    int FUN_0093d890();
    int FUN_009b0760();
};

struct Target_936750
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int size);
};

short __cdecl FUN_00936710(void* obj, const char* name);

static __declspec(noinline) short FUN_009366b0(FUN_0093d600* p)
{
    Pair t;
    p->FUN_0093d810(&t);
    Node_9366b0* node = (Node_9366b0*)t.unk04;
    int n = node->FUN_009b0630();
    Node_9366b0* r = node->FUN_009b0650(n - 1);
    FUN_0093d600 child;
    p->FUN_0093d7a0(&child, r->unk00);
    int off = *(short*)((char*)child.FUN_0093d790() + 0x12);
    return (short)(r->FUN_0093d890() + off);
}

static __declspec(noinline) void FUN_00936750(Pair* obj, int value, Target_936750* target)
{
    int* pv = &value;
    if (DAT_0105f548 == -1)
        DAT_0105f548 = FUN_00936710(obj, "TYPE_BRIDGE");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f548;
    FUN_0093d600 data(obj, "constraintData");
    *data.FUN_0093d670(0) = value;
    target->Set(value, data.FUN_0093d660());
}

void __cdecl FUN_00937b10(FUN_0093d600* src, Pair* desc, Target_936750* target)
{
    FUN_0093d600 first(desc, "atoms");
    FUN_0093d600 second(*src);
    if (DAT_0105f5ac == -1)
        DAT_0105f5ac = FUN_009366b0(&first);
    Pair a;
    FUN_0093d600 bridge;
    FUN_00936750(first.FUN_0093d7a0(&bridge, "bridgeAtom")->FUN_0093d810(&a), desc->unk00, target);
}
}   // namespace f3m_00937b10

// @f3 0x0093df80 (community match, verified in this file)
namespace N93df80 {
int __cdecl FUN_009232f0(const char* a, const char* b, int n) throw();
const char* __cdecl FUN_00923470(const char* s, int c) throw();
const char* __cdecl FUN_00923460(const char* s, int c) throw();
int __cdecl FUN_009233f0(const char* s) throw();
void __cdecl FUN_009234e0(void* dst, const void* src, int n) throw();
int __cdecl hkString_strCmp(const char* a, const char* b) throw();
void __cdecl FUN_00901e90(void* arr, int n, int sizeElem) throw();
struct hkThreadMemory { void FUN_008f6d90(void* p, int size, int cls) throw(); };
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct TypeEntry { const char* name; int unk04; int unk08; };
extern TypeEntry DAT_0105f934[32];

struct hkArrayChar {
    char* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline hkArrayChar() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline ~hkArrayChar()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int n = getCapacity();
            hkThreadMemory* mem = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, n * sizeof(char), 0x17);
        }
    }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline void setSize(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            int newCap = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newCap, sizeof(char));
        }
        m_size = n;
    }
    __forceinline hkArrayChar& operator=(const hkArrayChar& a)
    {
        setSize(a.m_size);
        FUN_009234e0(m_data, a.m_data, m_size);
        return *this;
    }
};

struct hkString {
    hkArrayChar m_string;
    __forceinline hkString() {}
    __forceinline ~hkString() {}
    __forceinline hkString(const char* s)
    {
        if (s != 0) {
            int len = FUN_009233f0(s) + 1;
            m_string.setSize(len);
            FUN_009234e0(m_string.m_data, s, len);
        } else {
            m_string.setSize(1);
            m_string.m_data[0] = 0;
        }
    }
    __forceinline int getLength() const { return m_string.m_size - 1; }
    __forceinline hkString(const char* buf, int len)
    {
        m_string.setSize(len + 1);
        FUN_009234e0(m_string.m_data, buf, len);
        m_string.m_data[len] = 0;
    }
    __forceinline void setAsSubstr(int index, int maxChars)
    {
        if (maxChars > getLength() - index)
            maxChars = getLength() - index;
        *this = hkString(m_string.m_data + index, maxChars);
    }
    __forceinline hkString& operator=(const hkString& o) { m_string = o.m_string; return *this; }
    __forceinline bool operator==(const char* s) const { return hkString_strCmp(m_string.m_data, s) == 0; }
};
}

using namespace N93df80;

// pdb: hkClassMember::getTypeOf | hkClassMember.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
int __cdecl hkClassMember_getTypeOf(const char* typeName)
{
    if (FUN_009232f0(typeName, "enum ", 5) == 0)
        return 0x18;
    if (FUN_009232f0(typeName, "flags ", 6) == 0)
        return 0x1f;
    if (FUN_009232f0(typeName, "hkArray<", 8) == 0)
        return 0x16;
    if (FUN_009232f0(typeName, "hkSimpleArray<", 14) == 0)
        return 0x1a;
    if (FUN_009232f0(typeName, "char*", 5) == 0)
        return 0x1d;

    const char* star = FUN_00923470(typeName, '*');
    if (star != 0 && star[1] == '\0')
        return 0x14;

    hkString str(typeName);
    const char* bracket = FUN_00923460(typeName, '[');
    if (bracket != 0)
        str.setAsSubstr(0, bracket - typeName);

    for (int i = 0; i < 32; i++) {
        if (str == DAT_0105f934[i].name)
            return i;
    }
    return 0;
}

// @f3 0x00933e20 (community match, verified in this file)
namespace f3m_00933e20 {
namespace n933e20 {
struct V4 {
    float x, y, z, w;
    V4& operator=(const V4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Hand {
    V4 elbowAxis;
    V4 backHand;
    float cosMax;
    float cosMin;
    short idx;
    char pad[6];
};
void __cdecl FUN_00901e90(void* arr, int cap, int stride);
struct Arr {
    Hand* data;
    int size;
    int capAndFlags;
    Arr() { data = 0; size = 0; capAndFlags = 0x80000000; }
    void setSize(int n)
    {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int c = cap * 2;
            if (c <= n)
                c = n;
            FUN_00901e90(this, c, sizeof(Hand));
        }
        size = n;
    }
};
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    void* FUN_0093d660();
    float* FUN_0093d6a0(int i);
    V4* FUN_0093d720(int i);
};
void __cdecl FUN_00933e20(void* obj, void* out)
{
    FUN_0093d600 elbow(obj, "elbowAxisLS");
    FUN_0093d600 back(obj, "backHandNormalInHandSpace");
    FUN_0093d600 cmax(obj, "cosineMaxElbowAngle");
    FUN_0093d600 cmin(obj, "cosineMinElbowAngle");
    FUN_0093d600 hands(out, "hands");
    Arr* a = (Arr*)hands.FUN_0093d660();
    new (a) Arr;
    a->setSize(2);
    { Hand& h = a->data[0]; h.elbowAxis = *elbow.FUN_0093d720(0); }
    { Hand& h = a->data[1]; h.elbowAxis = *elbow.FUN_0093d720(1); }
    { Hand& h = a->data[0]; h.backHand = *back.FUN_0093d720(0); }
    { Hand& h = a->data[1]; h.backHand = *back.FUN_0093d720(1); }
    { Hand& h = a->data[0]; h.cosMax = *cmax.FUN_0093d6a0(0); }
    { Hand& h = a->data[1]; h.cosMax = *cmax.FUN_0093d6a0(1); }
    { Hand& h = a->data[0]; h.cosMin = *cmin.FUN_0093d6a0(0); }
    { Hand& h = a->data[1]; h.cosMin = *cmin.FUN_0093d6a0(1); }
    a->data[0].idx = 0;
    a->data[1].idx = 1;
}
}
}   // namespace f3m_00933e20

// @f3 0x009345e0 (community match, verified in this file)
namespace f3m_009345e0 {

namespace f3m_009345e0 {
struct ControlPair { void* data; void* type; };
struct FUN_0093d600 {
    unsigned int unk00, unk04;
    FUN_0093d600(void* obj, const char* name);
    ControlPair FUN_0093d810();
};
void __cdecl FUN_00934540(const ControlPair* oldData, const ControlPair* newData, void* visitor);
}
using namespace f3m_009345e0;

void __cdecl FUN_009345e0(void* first, void* second, void* visitor)
{
    FUN_0093d600 oldControl(first, "controlData");
    FUN_0093d600 newControl(second, "controlData");
    ControlPair source;
    source.data = oldControl.FUN_0093d810().data;
    source.type = oldControl.FUN_0093d810().type;
    ControlPair dest;
    dest.data = newControl.FUN_0093d810().data;
    dest.type = newControl.FUN_0093d810().type;
    FUN_00934540(&source, &dest, visitor);
}
}   // namespace f3m_009345e0

// @f3 0x00935ab0 (community match, verified in this file)
namespace n935ab0 {
struct hkClass;
struct hkVariant {
    void* m_object;
    const hkClass* m_class;
};
struct hkpShape;
struct hkpListShapeChildInfo {
    hkpShape* m_shape;
    unsigned int m_collisionFilterInfo;
};
void __cdecl FUN_00901e90(void* array, int capacity, int stride);
template <typename T>
struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    void setSize(int n)
    {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        m_size = n;
    }
    T& operator[](int i) { return m_data[i]; }
    int getSize() const { return m_size; }
};
struct Accessor {
    void* m_member;
    void* m_object;
    Accessor(hkVariant& v, const char* name);
    bool* FUN_0093d640(bool* ok);
    void* FUN_0093d650();
    float* FUN_0093d6a0(int index);
};
extern const hkClass DAT_01141a3c;
}

void __cdecl FUN_00935ab0(n935ab0::hkVariant& oldObj, n935ab0::hkVariant& newObj)
{
    using namespace n935ab0;
    Accessor newShapes(newObj, "childShapes");
    Accessor oldInfo(oldObj, "childInfo");
    bool ok;
    if (*newShapes.FUN_0093d640(&ok) && *oldInfo.FUN_0093d640(&ok)) {
        hkArray<hkpListShapeChildInfo>* oldArray = (hkArray<hkpListShapeChildInfo>*)oldInfo.FUN_0093d650();
        hkArray<hkpShape*>* newArray = new (newShapes.FUN_0093d650()) hkArray<hkpShape*>();
        newArray->setSize(oldArray->getSize());
        for (int i = 0; i < oldArray->getSize(); i++)
            (*newArray)[i] = (*oldArray)[i].m_shape;

        hkVariant child;
        child.m_class = &DAT_01141a3c;
        child.m_object = (*oldArray)[0].m_shape;
        Accessor newRadius(newObj, "radius");
        Accessor oldRadius(child, "radius");
        *newRadius.FUN_0093d6a0(0) = *oldRadius.FUN_0093d6a0(0);
    }
}

// @f3 0x0093db80 (community match, verified in this file)
namespace n93db80 {
void __cdecl FUN_00901e90(struct Buf* b, int cap, int stride);
struct Buf {
    char* data; int size; unsigned int capacityFlags;
    __forceinline void SetSize(int n)
    {
        if ((int)(capacityFlags & 0x3fffffff) < n) {
            int want = (capacityFlags & 0x3fffffff) * 2;
            FUN_00901e90(this, n < want ? want : n, 1);
        }
        size = n;
    }
    __forceinline Buf& operator=(const char* s);
};
int __cdecl FUN_009233f0(const char* s);
void __cdecl FUN_009234e0(void* d, const void* s, int n);
__forceinline Buf& Buf::operator=(const char* s)
{
    if (s && *s) {
        int len = FUN_009233f0(s);
        SetSize(len + 1);
        FUN_009234e0(data, s, len + 1);
    } else {
        SetSize(1);
        data[0] = 0;
    }
    return *this;
}
struct TypeInfo { const char* name; int a; int b; };
extern TypeInfo DAT_0105f934[];
int __cdecl FUN_009233f0(const char* s);
void __cdecl FUN_00901e90(Buf* b, int cap, int stride);
void __cdecl FUN_009234e0(void* d, const void* s, int n);
void __cdecl FUN_009236d0(Buf* b, const char* fmt, ...);

// pdb: isSimpleType | hkClassMember.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: hkStringBuf::hkStringBuf)
static __declspec(noinline) void FUN_0093db80(int type, int count, Buf* buf)
{
    if (count == 0) {
        *buf = DAT_0105f934[type].name;
    } else {
        FUN_009236d0(buf, "%s[%i]", DAT_0105f934[type].name, count);
    }
}
void Caller(int t, int c, Buf* b) { FUN_0093db80(t, c, b); }
}

// @f3 0x0093e650 (community match, verified in this file)
namespace f3m_0093e650 {
namespace f3m_0093e650 {

// hkString: an hkArray<char> (data, size including the terminator, capacity with flag bits).
struct hkString93e650
{
    char* m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
};

// The value buffer filled by the member accessor; the raw member value starts at +0x10.
struct MemberValue93e650
{
    void* m_object;
    void* m_class;
    void* m_member;
    int m_unk0c;
    float m_data[16];
};

enum MemberType93e650
{
    TYPE_VOID = 0,
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_INT8,
    TYPE_UINT8,
    TYPE_INT16,
    TYPE_UINT16,
    TYPE_INT32,
    TYPE_UINT32,
    TYPE_INT64,
    TYPE_UINT64,
    TYPE_REAL,
    TYPE_VECTOR4,
    TYPE_QUATERNION,
    TYPE_MATRIX3,
    TYPE_ROTATION,
    TYPE_QSTRANSFORM,
    TYPE_MATRIX4,
    TYPE_TRANSFORM,
    TYPE_ZERO,
    TYPE_POINTER,
    TYPE_FUNCTIONPOINTER,
    TYPE_ARRAY,
    TYPE_INPLACEARRAY,
    TYPE_ENUM,
    TYPE_STRUCT,
    TYPE_SIMPLEARRAY,
    TYPE_HOMOGENEOUSARRAY,
    TYPE_VARIANT,
    TYPE_CSTRING,
    TYPE_ULONG,
    TYPE_FLAGS
};

const void* __cdecl FUN_00a4c6e0(const void* p);
const unsigned long* __cdecl FUN_00a4c6e0(const unsigned long* p);
int __cdecl FUN_009233f0(const char* s);
void __cdecl FUN_00901e90(hkString93e650* array, int capacity, int stride);
void __cdecl FUN_009234e0(void* destination, const void* source, int bytes);
void __cdecl FUN_009236d0(hkString93e650* s, const char* format, ...);

static __forceinline void SetSize(hkString93e650& s, int n)
{
    int capacity = s.m_capacityAndFlags & 0x3fffffff;
    if (capacity < n)
    {
        int newCapacity = capacity * 2;
        if (n >= newCapacity)
            newCapacity = n;
        FUN_00901e90(&s, newCapacity, 1);
    }
    s.m_size = n;
}
static __forceinline void Assign(hkString93e650& s, const char* str)
{
    int len = FUN_009233f0(str);
    SetSize(s, len + 1);
    FUN_009234e0(s.m_data, str, len + 1);
}
static __declspec(noinline) void FUN_0093e650(int type, int subtype, const MemberValue93e650* value, hkString93e650& out)
{
    int* pType = &type;
    const void* data = value->m_data;
    switch (type)
    {
    case TYPE_BOOL:
        Assign(out, *(const char*)FUN_00a4c6e0(data) ? "true" : "false");
        break;
    case TYPE_CHAR:
        FUN_009236d0(&out, "'%c'", *(const char*)FUN_00a4c6e0(data));
        break;
    case TYPE_INT8:
        FUN_009236d0(&out, "%i", *(const signed char*)FUN_00a4c6e0(data));
        break;
    case TYPE_UINT8:
        FUN_009236d0(&out, "%u", *(const unsigned char*)FUN_00a4c6e0(data));
        break;
    case TYPE_INT16:
        FUN_009236d0(&out, "%i", *(const short*)FUN_00a4c6e0(data));
        break;
    case TYPE_UINT16:
        FUN_009236d0(&out, "%u", *(const unsigned short*)FUN_00a4c6e0(data));
        break;
    case TYPE_INT32:
        FUN_009236d0(&out, "%i", *(const int*)FUN_00a4c6e0(data));
        break;
    case TYPE_UINT32:
        FUN_009236d0(&out, "%u", *(const unsigned int*)FUN_00a4c6e0(data));
        break;
    case TYPE_INT64:
        FUN_009236d0(&out, "%I64i", *(const __int64*)FUN_00a4c6e0(data));
        break;
    case TYPE_UINT64:
        FUN_009236d0(&out, "%I64u", *(const unsigned __int64*)FUN_00a4c6e0(data));
        break;
    case TYPE_ULONG:
        FUN_009236d0(&out, "%u", *FUN_00a4c6e0((const unsigned long*)data));
        break;
    case TYPE_REAL:
        FUN_009236d0(&out, "%ff", *(const float*)FUN_00a4c6e0(data));
        break;
    case TYPE_VECTOR4:
    case TYPE_QUATERNION:
    {
        const float* f = (const float*)data;
        FUN_009236d0(&out, "{%ff, %ff, %ff, %ff}", f[0], f[1], f[2], f[3]);
        break;
    }
    case TYPE_MATRIX3:
    case TYPE_ROTATION:
    case TYPE_QSTRANSFORM:
    {
        const float* f = (const float*)data;
        FUN_009236d0(&out, "{%ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff}",
            f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11]);
        break;
    }
    case TYPE_MATRIX4:
    case TYPE_TRANSFORM:
    {
        const float* f = (const float*)data;
        FUN_009236d0(&out, "{%ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff, %ff}",
            f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11], f[12], f[13], f[14], f[15]);
        break;
    }
    case TYPE_ENUM:
    case TYPE_FLAGS:
        FUN_0093e650(subtype, TYPE_VOID, value, out);
        break;
    default:
        break;
    }
}

volatile int g_type93e650;
volatile int g_subtype93e650;
MemberValue93e650* volatile g_value93e650;
hkString93e650* volatile g_out93e650;
void caller_of_FUN_0093e650()
{
    FUN_0093e650(g_type93e650, g_subtype93e650, g_value93e650, *g_out93e650);
}

}
}   // namespace f3m_0093e650

// @f3 0x00922e80 (community match, verified in this file)
namespace w922e80 {
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Heap {
    void* FUN_008f6d30(int size, unsigned int tag);
    void FUN_008f6d90(void* p, int size, unsigned int tag);
};

struct Map {
    unsigned __int64* m_elem;
    int m_numElems;
    int m_hashMod;
    void FUN_00922910(unsigned __int64 key, unsigned __int64 val);
    void FUN_00922e80(int newCapacity);
};

// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::resizeTable | hkMap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: alloc, newcap
void Map::FUN_00922e80(int newCapacity)
{
    int dontDeallocate = m_numElems & 0x80000000;
    int oldCapacity = m_hashMod + 1;
    unsigned __int64* oldElem = m_elem;
    Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
    m_elem = (unsigned __int64*)heap->FUN_008f6d30(newCapacity * 16, 0x17);
    for (int i = 0; i < newCapacity; i++)
        m_elem[i] = (unsigned __int64)-1;
    m_hashMod = newCapacity - 1;
    m_numElems = 0;
    for (int i = 0; i < oldCapacity; i++) {
        if (oldElem[i] != (unsigned __int64)-1)
            FUN_00922910(oldElem[i], oldElem[oldCapacity + i]);
    }
    if (dontDeallocate == 0) {
        Heap* heap2 = (Heap*)TlsGetValue(DAT_010f3170);
        heap2->FUN_008f6d90(oldElem, oldCapacity * 16, 0x17);
    }
}
}

// @f3 0x0092a320 (community match, verified in this file)
namespace w92a320 {
extern int DAT_010f3170;
struct Mem {
    void* FUN_008f6d30(int bytes, int tag);
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Mem* __stdcall FUN_00d9b080(int);
struct Src { int a0; void* a4; void* a8; void* A() { return a4; } void* B() { return a8; } };
class FUN_009ad920 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    char pad08[0xa0 - 8];
    FUN_009ad920(void* a, void* b);
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
    static void* operator new(unsigned int size)
    {
        Mem* mem = FUN_00d9b080(DAT_010f3170);
        FUN_009ad920* p = (FUN_009ad920*)mem->FUN_008f6d30(size, 0x27);
        p->memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p, unsigned int size)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, size, 0x27);
    }
};
class Owner {
public:
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088();
    virtual void AddObj(FUN_009ad920* obj);
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8();
    virtual void Finish(Src* s);
    void FUN_0092a320(Src* s);
};
// pdb: bhkMultiSphereShape::Init | bhkMultiSphereShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
void Owner::FUN_0092a320(Src* s)
{
    if (!s) return;
    FUN_009ad920* obj = new FUN_009ad920(s->A(), s->B());
    AddObj(obj);
    obj->removeReference();
    Finish(s);
}
}

// @f3 0x0093d460 (community match, verified in this file)
namespace f3m_0093d460 {
namespace f3m_0093d460 {
struct Alloc { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(int);

struct hkBool9 {
    char value;
    hkBool9() {}
    hkBool9(const hkBool9& other) : value(other.value) {}
};
struct Span9 { short* data; int size; };
struct ShortArray9 {
    short* data;
    int size;
    unsigned int capacityAndFlags;
    ShortArray9() : data(0), size(0), capacityAndFlags(0x80000000u) {}
    ~ShortArray9()
    {
        if ((capacityAndFlags & 0x80000000u) == 0) {
            unsigned int n = capacityAndFlags & 0x3fffffff;
            Alloc* al = FUN_00d9b080(::DAT_010f3170);
            al->FUN_008f6d90(data, n * 2, 0x17);
        }
    }
    void PushBack(short value);
};
void __cdecl FUN_00901f10(ShortArray9* array, int elemSize) throw();
void __cdecl FUN_009234e0(void* destination, const void* source, int bytes) throw();
inline void ShortArray9::PushBack(short value)
{
    if (size == (int)(capacityAndFlags & 0x3fffffff))
        FUN_00901f10(this, 2);
    data[size] = value;
    ++size;
}

struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    hkBool9 FUN_0093d640();
    Span9* FUN_0093d650() throw();
};

void __cdecl FUN_0093d460(void* obj, void* other)
{
    FUN_0093d600 mapping(obj, "mapping");
    FUN_0093d600 tracks(other, "animationTrackToBoneIndices");
    if (!mapping.FUN_0093d640().value || !tracks.FUN_0093d640().value)
        return;
    ShortArray9 order;
    Span9* span = mapping.FUN_0093d650();
    for (int i = 0; i < span->size; ++i) {
        for (int j = 0; j < span->size; ++j) {
            if (span->data[j] == i) {
                order.PushBack((short)j);
                break;
            }
        }
    }
    FUN_009234e0(span->data, order.data, order.size * 2);
    span->size = order.size;
}
}
}   // namespace f3m_0093d460

// @f3 0x00922a80 (community match, verified in this file)
namespace f3m_00922a80 {
namespace w922a80 {
struct Map {
    unsigned __int64* m_table;
    int m_count;
    int m_mask;
    void FUN_00922a80(int index);
};

// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::remove | hkMap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: it
void Map::FUN_00922a80(int index)
{
    unsigned __int64 i = index;
    --m_count;
    m_table[i] = (unsigned __int64)-1;

    unsigned __int64 lo = (i + m_mask) & m_mask;
    while (m_table[lo] != (unsigned __int64)-1)
        lo = (lo + m_mask) & m_mask;
    lo = (lo + 1) & m_mask;

    unsigned __int64 empty = i;
    for (i = (i + 1) & m_mask; m_table[i] != (unsigned __int64)-1; i = (i + 1) & m_mask)
    {
        unsigned __int64 hash = ((m_table[i] >> 4) * 2654435761U) & m_mask;
        if (i >= lo && hash > empty)
        {
            continue;
        }
        else if (i < empty && (hash > empty || hash <= i))
        {
            continue;
        }
        else if (hash > empty && hash < lo)
        {
            continue;
        }
        m_table[empty] = m_table[i];
        m_table[m_mask + empty + 1] = m_table[m_mask + i + 1];
        m_table[i] = (unsigned __int64)-1;
        empty = i;
    }
}
}
}   // namespace f3m_00922a80

// @f3 0x0092ae90 (community match, verified in this file)
extern int DAT_010f33d4;
extern double DAT_00db88e8;
namespace f3m_0092ae90 {
struct V3 { float x, y, z; };
struct Arr { int unk00; int unk04; unsigned short unk08; unsigned short unk0a; unsigned short unk0c; unsigned short unk0e; };
struct Vec3 { float x, y, z; int FUN_00823dc0(const char* n); };
struct Stream : Arr {
    void FUN_00555790(unsigned int n);
    void FUN_005b3880(unsigned int idx, int* v);
    void Add(int v) {
        unsigned int n = unk0a;
        if (n >= unk08) FUN_00555790(n + unk0e);
        FUN_005b3880(n, &v);
    }
};
struct Inner { V3* FUN_0091dd60(); V3* FUN_0091dda0(); };
extern V3 DAT_01092a50;
struct Obj {
    int unk00, unk04; Inner* unk08;
    int FUN_008f80d0(Stream* s);
    void FUN_0092ae90(Stream* s);
};
int __cdecl FUN_00847b50(int);
// pdb: bhkCharacterProxy::GetViewerStrings | bhkCharacterProxy.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Obj::FUN_0092ae90(Stream* s)
{
    FUN_008f80d0(s);
    s->Add(FUN_00847b50(DAT_010f33d4));
    V3* p = (this && unk08) ? unk08->FUN_0091dd60() : &DAT_01092a50;
    Vec3 v;
    v.x = p->x * DAT_00db88e8; v.y = p->y * DAT_00db88e8; v.z = p->z * DAT_00db88e8;
    s->Add(v.FUN_00823dc0("Pos"));
    if (this && unk08) {
        p = unk08->FUN_0091dda0();
        v.x = p->x * DAT_00db88e8; v.y = p->y * DAT_00db88e8; v.z = p->z * DAT_00db88e8;
    }
    s->Add(v.FUN_00823dc0("Vel"));
}
}

// @f3 0x00930c40 (community match, verified in this file)
extern int DAT_00e37524;
namespace f3m_00930c40 {
struct Init930 {
void* unk00;
short unk04;
short unk06;
int unk08;
int unk0c;
short unk10;
short unk12;
int unk14;
int unk18;
int unk1c;
float unk20;
float unk24;
float unk28;
float unk2c;
float unk30;
float unk34;
float unk38;
float unk3c;
float unk40;
float unk44;
float unk48;
float unk4c;
float unk50;
float unk54;
float unk58;
float unk5c;
float unk60;
float unk64;
float unk68;
float unk6c;
float unk70;
float unk74;
float unk78;
float unk7c;
float unk80;
float unk84;
float unk88;
float unk8c;
float unk90;
float unk94;
float unk98;
float unk9c;
short unkA0;
char unkA2;
char unkA3;
short unkA4;
__forceinline void Initialize() { static_cast<volatile float&>(unk20)=0.0f;
unk24=0.0f;
unk28=0.0f;
unk2c=0.0f;
unk30=0.0f;
static_cast<volatile float&>(unk34)=0.0f;
unk38=0.0f;
unk3c=0.0f;
unk40=0.0f;
unk44=0.0f;
static_cast<volatile float&>(unk48)=0.0f;
unk4c=0.0f;
static_cast<volatile float&>(unk20)=1.0f; static_cast<volatile float&>(unk34)=1.0f; static_cast<volatile float&>(unk48)=1.0f;
unk5c=0.0f;
unk58=0.0f;
unk54=0.0f;
unk50=0.0f;
static_cast<volatile float&>(unk60)=0.0f;
unk64=0.0f;
unk68=0.0f;
unk6c=0.0f;
unk70=0.0f;
static_cast<volatile float&>(unk74)=0.0f;
unk78=0.0f;
unk7c=0.0f;
unk80=0.0f;
unk84=0.0f;
static_cast<volatile float&>(unk88)=0.0f;
unk8c=0.0f;
static_cast<volatile float&>(unk60)=1.0f; static_cast<volatile float&>(unk74)=1.0f; static_cast<volatile float&>(unk88)=1.0f; unk90=unk94=unk98=unk9c=0.0f;  }
Init930* FUN_00930c40(); };
// pdb: hkpHingeConstraintData::hkpHingeConstraintData | hkpHingeConstraintData.obj | fnv360_0822_retail, call_seq, medium
Init930* Init930::FUN_00930c40(){unk06=1; unk00=&DAT_00e37524; static_cast<volatile int&>(unk08)=0; static_cast<volatile short&>(unk10)=2; static_cast<volatile short&>(unkA0)=12; static_cast<volatile short&>(unkA4)=5;
Initialize(); static_cast<volatile char&>(unkA2)=0; return this;}




}   // namespace f3m_00930c40

// @f3 0x009347c0 (community match, verified in this file)
namespace f3m_009347c0 {
namespace n9347c0 {
struct Arr { int* data; int count; };
struct FUN_0093d600 {
  int unk00;
  int unk04;
  FUN_0093d600() {}
  FUN_0093d600(void* obj, const char* name);
  FUN_0093d600* FUN_0093d7a0(FUN_0093d600* out, const char* name);
  Arr* FUN_0093d760(int index);
};
}

void __cdecl FUN_009347c0(void* unused, void* obj)
{
  n9347c0::FUN_0093d600 scheme(obj, "scheme");
  n9347c0::FUN_0093d600 cmds;
  scheme.FUN_0093d7a0(&cmds, "commands");
  int* p = cmds.FUN_0093d760(0)->data;
  int* end = p + cmds.FUN_0093d760(0)->count;
  for (; p < end; ++p) {
    switch (*p) {
    case 0:
      return;
    case 3: case 4: case 5: case 6: case 12: case 14: case 15: case 16: case 17: case 18:
    case 20: case 21: case 24:
      p += 1;
      break;
    case 19:
      p += 2;
      break;
    case 25: {
      for (int* src = p + 2; src < end; ++src) src[-2] = *src;
      end -= 2;
      cmds.FUN_0093d760(0)->count -= 2;
      --p;
      break;
    }
    }
  }
}
}   // namespace f3m_009347c0

// @f3 0x00934b70 (community match, verified in this file)
namespace f3m_00934b70 {
namespace f3m_00934b70
{
void __cdecl FUN_00901f10(void* array, int elementSize);

struct Member
{
    void* object;
    const char* name;

    Member(void* object, const char* name);
    void* FUN_0093d660();
};

template <class T>
struct Array
{
    T* data;
    int size;
    unsigned int capacityAndFlags;

    Array()
    {
        *(T* volatile*)&data = 0;
        *(volatile int*)&size = 0;
        *(volatile unsigned int*)&capacityAndFlags = 0x80000000;
    }

    void PushBack(const T& value)
    {
        if (size == (int)(capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = value;
        size++;
    }
};

static __declspec(noinline) void FUN_00934b70(
    void* sourceObject,
    const char* memberName,
    void* destinationObject)
{
    Member source(sourceObject, memberName);
    Member destination(destinationObject, memberName);
    short* sourceValues = (short*)source.FUN_0093d660();
    Array<short>* destinationValues = (Array<short>*)destination.FUN_0093d660();

    new (destinationValues) Array<short>;
    destinationValues->PushBack(sourceValues[0]);
    destinationValues->PushBack(sourceValues[1]);
}

void* volatile g_source_934b70;
const char* volatile g_name_934b70;
void* volatile g_destination_934b70;

void caller_of_FUN_00934b70()
{
    FUN_00934b70(g_source_934b70, g_name_934b70, g_destination_934b70);
}
}
}   // namespace f3m_00934b70

// @f3 0x009282b0 (community match, verified in this file)
namespace f3m_009282b0 {
namespace n9282b0 {
using n9283d0::LocalArray;
using n9283d0::Pair;
using n9283d0::Collector;
using n9283d0::Sink;
struct hkBool { char b; hkBool(bool v) throw() { b = (char)v; } };
struct Key;
struct World;
struct Notifier { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void Notify(Key** keys, int n, World* w, hkBool b) throw(); };
struct World { char p00[8]; Notifier* notifier; char p0c[0x54 - 0xc]; Collector* collector; Sink* sink; char p5c[0x2f8 - 0x5c]; int count; };
struct Sub { int m0; char p04[0x10]; int k; };
struct Key { char p00[0x10]; Sub sub; };
}
// pdb: hkpWorldOperationUtil::removeEntityBP | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_removeEntityBP(n9282b0::World* w, n9282b0::Key* key)
{
    using namespace n9282b0;
    Sub* s = &key->sub;
    if (s->m0 == 0)
        return;
    w->notifier->Notify(&key, 1, w, true);
    LocalArray<Pair> arr(w->count);
    w->collector->Collect(&s->k, &arr);
    if (arr.size > 0)
        w->sink->FUN_00984cc0(arr.data, arr.size);
    arr.Release();
}
}   // namespace f3m_009282b0

// @f3 0x0093ba60 (community match, verified in this file)
namespace f3m_0093ba60 {
struct CopyClass;

struct CopyMember
{
    const char* m_name;
    void* m_class;
    void* m_enum;
    unsigned char m_type;
    unsigned char m_subtype;
    int FUN_0093d900();
};

struct CopyClass
{
    int FUN_009b0630();
    CopyMember* FUN_009b0650(int index);
    CopyMember* FUN_009b06c0(const char* name);
};

struct CopyObject
{
    void* m_object;
    CopyClass* m_class;
};

struct MemberAccessor
{
    void* m_address;
    CopyMember* m_member;
    void FUN_0093d5e0(void* object, CopyMember* member);
    void* FUN_0093d660();
    CopyObject* FUN_0093d810(CopyObject* out);
};

extern "C" void __cdecl FUN_009234e0(void* dst, const void* src, int count);

void FUN_0093ba60(CopyObject* dst, CopyObject* src)
{
    CopyClass* dstClass = dst->m_class;
    CopyClass* srcClass = src->m_class;
    for (int i = 0; i < dstClass->FUN_009b0630(); ++i)
    {
        CopyMember* mem = dstClass->FUN_009b0650(i);
        const char* name = mem->m_name;
        CopyMember* other = srcClass->FUN_009b06c0(name);
        if (other == 0)
            continue;
        if (mem->m_type != other->m_type)
            continue;
        if (mem->m_subtype != other->m_subtype)
            continue;
        if (mem->FUN_0093d900() != other->FUN_0093d900())
            continue;

        MemberAccessor dstAcc;
        MemberAccessor srcAcc;
        dstAcc.FUN_0093d5e0(dst->m_object, mem);
        srcAcc.FUN_0093d5e0(src->m_object, other);

        switch (mem->m_type)
        {
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
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 24:
            FUN_009234e0(dstAcc.FUN_0093d660(), srcAcc.FUN_0093d660(), mem->FUN_0093d900());
            break;
        case 25:
        {
            CopyObject nestedSrc;
            CopyObject nestedDst;
            FUN_0093ba60(dstAcc.FUN_0093d810(&nestedDst), srcAcc.FUN_0093d810(&nestedSrc));
            break;
        }
        default:
            break;
        }
    }
}
}   // namespace f3m_0093ba60

// @f3 0x00933ae0 (community match, verified in this file)
namespace f3m_00933ae0 {
struct Desc { int FUN_009b0760(); };
struct Pair { void* data; Desc* type; };
struct Elem { char* data; int count; };
struct FieldRef {
    void* unk00;
    int unk04;
    Elem* FUN_0093d760(int index);
    Pair FUN_0093d810();
};
typedef void (__cdecl *VisitFn)(Pair* a, Pair* b, void* ctx);

static __declspec(noinline) void FUN_00933ae0(FieldRef& a, FieldRef& b, void* ctx, VisitFn fn)
{
    Elem* ea = a.FUN_0093d760(0);
    Elem* eb = b.FUN_0093d760(0);
    Pair pa;
    pa.data = 0;
    pa.type = a.FUN_0093d810().type;
    Pair pb;
    pb.data = 0;
    pb.type = b.FUN_0093d810().type;
    int sa = pa.type->FUN_009b0760();
    int sb = pb.type->FUN_009b0760();
    for (int i = 0; i < ea->count; i++) {
        pa.data = ea->data + i * sa;
        pb.data = eb->data + i * sb;
        fn(&pa, &pb, ctx);
    }
}

extern FieldRef* volatile DAT_a;
extern FieldRef* volatile DAT_b;
extern void* volatile DAT_c;
extern VisitFn volatile DAT_d;
void __cdecl Caller_00933ae0()
{
    FUN_00933ae0(*DAT_a, *DAT_b, DAT_c, DAT_d);
}
}

// @f3 0x00937340 (community match, verified in this file)
extern short DAT_0105f58c;
namespace f3m_00937340 {
namespace f3m_00937340 {
struct Transform { float m[16]; };
struct Rotation { float m[12]; };
struct Vec4 { float v[4]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    bool* FUN_0093d690(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
    int* FUN_0093d670(int index);
};
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00937340(void* obj, bool enabled, char axis, short initOffset, short prevOffset, short limitOffset, float target, int motor)
{
    if (DAT_0105f58c == -1)
        DAT_0105f58c = FUN_00936710(obj, "TYPE_ANG_MOTOR");
    {
        FUN_0093d600 a(obj, "type");
        *a.FUN_0093d6e0(0) = DAT_0105f58c;
    }
    {
        FUN_0093d600 a(obj, "isEnabled");
        *a.FUN_0093d690(0) = enabled;
    }
    {
        FUN_0093d600 a(obj, "motorAxis");
        *a.FUN_0093d710(0) = axis;
    }
    {
        FUN_0093d600 a(obj, "initializedOffset");
        *a.FUN_0093d6e0(0) = initOffset;
    }
    {
        FUN_0093d600 a(obj, "previousTargetAngleOffset");
        *a.FUN_0093d6e0(0) = prevOffset;
    }
    {
        FUN_0093d600 a(obj, "correspondingAngLimitSolverResultOffset");
        *a.FUN_0093d6e0(0) = limitOffset;
    }
    {
        FUN_0093d600 a(obj, "targetAngle");
        *a.FUN_0093d6a0(0) = target;
    }
    {
        FUN_0093d600 a(obj, "motor");
        *a.FUN_0093d670(0) = motor;
    }
}
void* volatile g_obj_00937340;
volatile bool g_enabled_00937340;
volatile char g_axis_00937340;
volatile short g_initOffset_00937340;
volatile short g_prevOffset_00937340;
volatile short g_limitOffset_00937340;
volatile float g_target_00937340;
volatile int g_motor_00937340;
void caller_of_FUN_00937340() { FUN_00937340(g_obj_00937340, g_enabled_00937340, g_axis_00937340, g_initOffset_00937340, g_prevOffset_00937340, g_limitOffset_00937340, g_target_00937340, g_motor_00937340); }
}
}   // namespace f3m_00937340

// @f3 0x00937470 (community match, verified in this file)
extern short DAT_0105f590;
namespace f3m_00937470 {
namespace f3m_00937470 {
struct Rotation { float m[12]; };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    bool* FUN_0093d690(int index);
    Rotation* FUN_0093d730(int index);
    int* FUN_0093d670(int index);
};
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
void __cdecl FUN_00937470(void* obj, bool enabled, short initOffset, short prevOffset, const Rotation& frame, const int* motors)
{
    if (DAT_0105f590 == -1)
        DAT_0105f590 = FUN_00936710(obj, "TYPE_RAGDOLL_MOTOR");
    {
        FUN_0093d600 a(obj, "type");
        *a.FUN_0093d6e0(0) = DAT_0105f590;
    }
    {
        FUN_0093d600 a(obj, "isEnabled");
        *a.FUN_0093d690(0) = enabled;
    }
    {
        FUN_0093d600 a(obj, "initializedOffset");
        *a.FUN_0093d6e0(0) = initOffset;
    }
    {
        FUN_0093d600 a(obj, "previousTargetAnglesOffset");
        *a.FUN_0093d6e0(0) = prevOffset;
    }
    {
        FUN_0093d600 a(obj, "targetFrameAinB");
        *a.FUN_0093d730(0) = frame;
    }
    {
        FUN_0093d600 a(obj, "motors");
        *a.FUN_0093d670(0) = motors[0];
    }
    {
        FUN_0093d600 a(obj, "motors");
        *a.FUN_0093d670(1) = motors[1];
    }
    {
        FUN_0093d600 a(obj, "motors");
        *a.FUN_0093d670(2) = motors[2];
    }
}
}
}   // namespace f3m_00937470

// @f3 0x0093ead0 (community match, verified in this file)
namespace f3m_0093ead0 {
struct Item {
    int unk00;
    int f04;
    int unk08;
    unsigned char f0c;
    unsigned char f0d;
    short f0e;
    int FUN_0093d8c0();
    int FUN_0093d890();
};

struct Node {
    int FUN_009b0630();
    Item* FUN_009b0650(int idx);
    int FUN_009b0760();
};

struct Elem {
    void* ptr;
    int count;
};

struct StackObj {
    double unk00;
    StackObj* FUN_0093d5e0(int a, Item* item);
    void* FUN_0093d650();
    Elem* FUN_0093d760(int idx);
};

static __declspec(noinline) void FUN_0093e500(void* ptr, int count, int arg);

void FUN_0093ead0(int a, Node* b, void* c, int d) {
    if (d <= 0) return;
    int remaining = d;
    void* cc = c;
    while (remaining != 0) {
        int idx = 0;
        if (b->FUN_009b0630() > 0) {
            do {
                Item* item = b->FUN_009b0650(idx);
                StackObj s;
                s.FUN_0093d5e0(a, item);
                switch (item->f0c - 0x16) {
                case 6: {
                    int v = item->FUN_0093d8c0();
                    int val = v ? item->FUN_0093d8c0() : 1;
                    FUN_0093e500(s.FUN_0093d650(), val, (int)cc);
                    break;
                }
                case 0:
                case 4: {
                    Elem* e = s.FUN_0093d760(0);
                    if (item->f0d == 0x1c) {
                        FUN_0093e500(e->ptr, e->count, (int)cc);
                    } else if (item->f0d == 0x19) {
                        int v2 = item->FUN_0093d890();
                        FUN_0093ead0((int)e->ptr, (Node*)v2, (void*)c, e->count);
                    }
                    break;
                }
                case 3: {
                    int v = item->FUN_0093d8c0();
                    int val = v ? item->FUN_0093d8c0() : 1;
                    int v2 = item->FUN_0093d890();
                    FUN_0093ead0((int)s.FUN_0093d650(), (Node*)v2, (void*)c, val);
                    break;
                }
                default:
                    break;
                }
            } while (++idx < b->FUN_009b0630());
        }
        a += b->FUN_009b0760();
        remaining--;
    }
}
static __declspec(noinline) void FUN_0093e500(void* ptr, int count, int arg) {
    if (count > 0) {
        void* volatile y = ptr;
        int* volatile z = &arg;
        volatile int x = count;
        *z = x;
        (void)y;
    }
}
}   // namespace f3m_0093ead0

// @f3 0x00938610 (community match, verified in this file)
typedef float hkReal;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

class hkClass;
class hkClassEnum;

class hkBool
{
public:
    hkBool(bool b) { m_bool = (char)b; }
    char m_bool;
};

struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};

struct hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    inline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        x = v1.y * v2.z - v1.z * v2.y;
        y = v1.z * v2.x - v1.x * v2.z;
        z = v1.x * v2.y - v1.y * v2.x;
        w = 0.0f;
    }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4& getColumn(int i) { return (&m_col0)[i]; }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
    hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    hkRotation& getRotation() { return m_rotation; }
    hkVector4& getTranslation() { return m_translation; }
};

class hkClassEnum
{
public:
    int getValueOf(const char* name, int& val) const;
};

class hkClassMember
{
public:
    const char* m_name;
    const hkClass* m_class;
    const hkClassEnum* m_enum;
    unsigned char m_type;
    unsigned char m_subtype;
    short m_cArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_attributes;

    const char* getName() const { return m_name; }
    int getOffset() const { return m_offset; }
    const hkClass& getStructClass() const;
    const hkClassEnum& getEnumClass() const;
};

class hkClass
{
public:
    int getNumMembers() const;
    const hkClassMember& getMember(int i) const;
    int getObjectSize() const;
};

class hkClassMemberAccessor;

class hkClassAccessor
{
public:
    hkClassAccessor(void* object, const hkClass* klass);
    hkClassAccessor(hkVariant& v);
    inline hkClassMemberAccessor member(const char* name);
    const hkClass& getClass() const { return *m_variant.m_class; }

    hkVariant m_variant;
};

class hkClassMemberAccessor
{
public:
    hkClassMemberAccessor(hkVariant& v, const char* memberName);
    hkClassMemberAccessor(void* object, const hkClass* klass, const char* memberName);

    hkBool& asBool(int index = 0) const;
    hkReal& asReal(int index = 0) const;
    char*& asPointer(int index = 0) const;
    hkInt16& asInt16(int index = 0) const;
    hkUint8& asUint8(int index = 0) const;
    hkVector4& asVector4(int index = 0) const;
    hkTransform& asTransform(int index = 0) const;
    hkClassAccessor object() const;
    hkClassMemberAccessor member(const char* name) const;
    const hkClassMember& getClassMember() const;

    void* m_address;
    const hkClassMember* m_member;
};

inline hkClassMemberAccessor hkClassAccessor::member(const char* name)
{
    return hkClassMemberAccessor(m_variant, name);
}

class hkObjectUpdateTracker;

extern hkInt16 DAT_0105f5c8;
extern hkInt16 DAT_0105f54c;
extern hkInt16 DAT_0105f558;
extern hkInt16 DAT_0105f574;
extern hkInt16 DAT_0105f57c;
extern hkInt16 DAT_0105f588;
extern hkInt16 DAT_0105f58c;

static hkInt16 getAtomType(hkVariant& atom, const char* typeName)
{
    hkClassMemberAccessor type(atom, "type");
    int val;
    type.getClassMember().getEnumClass().getValueOf(typeName, val);
    return (hkInt16)val;
}

static int getAtomsSize(hkClassMemberAccessor& atoms)
{
    hkClassAccessor atomsObj = atoms.object();
    const hkClass& klass = atomsObj.getClass();
    const hkClassMember& last = klass.getMember(klass.getNumMembers() - 1);
    int offset = atoms.member(last.getName()).getClassMember().getOffset();
    return offset + last.getStructClass().getObjectSize();
}

void initSetLocalTransformsAtom(hkClassAccessor& atom, const hkTransform& transformA, const hkTransform& transformB)
{
    if (DAT_0105f54c == -1)
    {
        DAT_0105f54c = getAtomType(atom.m_variant, "TYPE_SET_LOCAL_TRANSFORMS");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f54c;
    hkClassMemberAccessor(atom.m_variant, "transformA").asTransform() = transformA;
    hkClassMemberAccessor(atom.m_variant, "transformB").asTransform() = transformB;
}

static void initAngMotorAtom(hkClassAccessor& atom, hkBool isEnabled, hkUint8 motorAxis, hkInt16 initializedOffset,
                             hkInt16 previousTargetAngleOffset, hkInt16 correspondingAngLimitSolverResultOffset,
                             hkReal targetAngle, char* motor)
{
    if (DAT_0105f58c == -1)
    {
        DAT_0105f58c = getAtomType(atom.m_variant, "TYPE_ANG_MOTOR");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f58c;
    hkClassMemberAccessor(atom.m_variant, "isEnabled").asBool() = isEnabled;
    hkClassMemberAccessor(atom.m_variant, "motorAxis").asUint8() = motorAxis;
    hkClassMemberAccessor(atom.m_variant, "initializedOffset").asInt16() = initializedOffset;
    hkClassMemberAccessor(atom.m_variant, "previousTargetAngleOffset").asInt16() = previousTargetAngleOffset;
    hkClassMemberAccessor(atom.m_variant, "correspondingAngLimitSolverResultOffset").asInt16() =
        correspondingAngLimitSolverResultOffset;
    hkClassMemberAccessor(atom.m_variant, "targetAngle").asReal() = targetAngle;
    hkClassMemberAccessor(atom.m_variant, "motor").asPointer() = motor;
}

static void initAngFrictionAtom(hkClassAccessor& atom, hkUint8 isEnabled, hkUint8 firstFrictionAxis,
                                hkUint8 numFrictionAxes, hkReal maxFrictionTorque)
{
    if (DAT_0105f588 == -1)
    {
        DAT_0105f588 = getAtomType(atom.m_variant, "TYPE_ANG_FRICTION");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f588;
    hkClassMemberAccessor(atom.m_variant, "isEnabled").asUint8() = isEnabled;
    hkClassMemberAccessor(atom.m_variant, "firstFrictionAxis").asUint8() = firstFrictionAxis;
    hkClassMemberAccessor(atom.m_variant, "numFrictionAxes").asUint8() = numFrictionAxes;
    hkClassMemberAccessor(atom.m_variant, "maxFrictionTorque").asReal() = maxFrictionTorque;
}

static void initAngLimitAtom(hkClassAccessor& atom, hkUint8 isEnabled, hkUint8 limitAxis, hkReal minAngle,
                             hkReal maxAngle, hkReal angularLimitsTauFactor)
{
    if (DAT_0105f57c == -1)
    {
        DAT_0105f57c = getAtomType(atom.m_variant, "TYPE_ANG_LIMIT");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f57c;
    hkClassMemberAccessor(atom.m_variant, "isEnabled").asUint8() = isEnabled;
    hkClassMemberAccessor(atom.m_variant, "limitAxis").asUint8() = limitAxis;
    hkClassMemberAccessor(atom.m_variant, "minAngle").asReal() = minAngle;
    hkClassMemberAccessor(atom.m_variant, "maxAngle").asReal() = maxAngle;
    hkClassMemberAccessor(atom.m_variant, "angularLimitsTauFactor").asReal() = angularLimitsTauFactor;
}

static void init2dAngAtom(hkClassAccessor& atom, hkUint8 freeRotationAxis)
{
    if (DAT_0105f574 == -1)
    {
        DAT_0105f574 = getAtomType(atom.m_variant, "TYPE_2D_ANG");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f574;
    hkClassMemberAccessor(atom.m_variant, "freeRotationAxis").asUint8() = freeRotationAxis;
}

static void initBallSocketAtom(hkClassAccessor& atom)
{
    if (DAT_0105f558 == -1)
    {
        DAT_0105f558 = getAtomType(atom.m_variant, "TYPE_BALL_SOCKET");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f558;
}

void FUN_00938610(hkVariant& oldObj, hkVariant& newObj, hkObjectUpdateTracker& tracker)
{
    hkClassMemberAccessor atoms(newObj, "atoms");
    hkClassAccessor oldAccessor(oldObj);

    if (DAT_0105f5c8 == -1)
    {
        DAT_0105f5c8 = (hkInt16)getAtomsSize(atoms);
    }

    hkTransform transformA;
    {
        hkClassAccessor basisA = oldAccessor.member("basisA").object();
        transformA.getColumn(0) = basisA.member("axle").asVector4();
        transformA.getColumn(1) = basisA.member("perpToAxle1").asVector4();
        transformA.getColumn(2) = basisA.member("perpToAxle2").asVector4();
        transformA.getTranslation() = basisA.member("pivot").asVector4();
    }

    hkTransform transformB;
    {
        hkClassAccessor basisB = oldAccessor.member("basisB").object();
        transformB.getColumn(0) = basisB.member("axle").asVector4();
        transformB.getColumn(2) = basisB.member("perp2FreeAxis").asVector4();
        transformB.getColumn(1).setCross(transformB.getColumn(2), transformB.getColumn(0));
        transformB.getTranslation() = basisB.member("pivot").asVector4();
    }

    initSetLocalTransformsAtom(atoms.member("transforms").object(), transformA, transformB);
    initAngMotorAtom(atoms.member("angMotor").object(), false, 0, 0x40, 0x44, 0x10, 0.0f, 0);
    initAngFrictionAtom(atoms.member("angFriction").object(), 1, 0, 1,
                        oldAccessor.member("maxFrictionTorque").asReal());

    {
        hkClassMemberAccessor angularLimitsTauFactor(oldAccessor.m_variant, "angularLimitsTauFactor");
        hkClassMemberAccessor maxAngle(oldAccessor.m_variant, "maxAngle");
        hkClassMemberAccessor minAngle(oldAccessor.m_variant, "minAngle");
        initAngLimitAtom(atoms.member("angLimit").object(), 1, 0, minAngle.asReal(), maxAngle.asReal(),
                         angularLimitsTauFactor.asReal());
    }
    init2dAngAtom(atoms.member("2dAng").object(), 0);
    initBallSocketAtom(atoms.member("ballSocket").object());
}

// @f3 0x00937b90 (community match, verified in this file)
extern short DAT_0105f5b0;
extern short DAT_0105f548;
namespace f3m_00937b90 {
namespace NativeBridge00937b90 {





struct Pair
{
    int unk00;
    int unk04;
};

struct FUN_0093d600
{
    int unk00;
    int unk04;
    FUN_0093d600() {}
    FUN_0093d600(Pair* obj, const char* name);
    FUN_0093d600(FUN_0093d600& other);
    FUN_0093d600* FUN_0093d7a0(FUN_0093d600* out, const char* name);
    Pair* FUN_0093d810(Pair* out);
    int FUN_0093d660();
    int FUN_0093d690();
    int FUN_0093d710();
    int FUN_0093d720();
    int FUN_0093d790();
    int FUN_0093d850();
    int FUN_0093d860();
    int FUN_0093d870();
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
};

struct Node_9366b0
{
    char* unk00;
    int unk04;
    int FUN_009b0630();
    Node_9366b0* FUN_009b0650(int n);
    Node_9366b0* FUN_0093d890();
    int FUN_009b0760();
};

struct Target_936750
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int size);
};

short __cdecl FUN_00936710(const char* name);

static __declspec(noinline) short FUN_009366b0(FUN_0093d600* p)
{
    Pair t;
    p->FUN_0093d810(&t);
    Node_9366b0* node = (Node_9366b0*)t.unk04;
    int n = node->FUN_009b0630();
    Node_9366b0* r = node->FUN_009b0650(n - 1);
    FUN_0093d600 child;
    p->FUN_0093d7a0(&child, r->unk00);
    unsigned int off = *(unsigned short*)((char*)child.FUN_0093d790() + 0x12);
    return (short)(r->FUN_0093d890()->FUN_009b0760() + off);
}

static __declspec(noinline) void FUN_00936750(Pair* obj, int value, Target_936750* target)
{
    int* pv = &value;
    if (DAT_0105f548 == -1)
        DAT_0105f548 = FUN_00936710("TYPE_BRIDGE");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f548;
    FUN_0093d600 data(obj, "constraintData");
    *data.FUN_0093d670(0) = value;
    target->Set(value, data.FUN_0093d660());
}

void __cdecl FUN_00937b90(FUN_0093d600* src, Pair* desc, Target_936750* target)
{
    FUN_0093d600 first(desc, "atoms");
    FUN_0093d600 second(*src);
    if (DAT_0105f5b0 == -1)
        DAT_0105f5b0 = FUN_009366b0(&first);
    Pair a;
    FUN_0093d600 bridge;
    FUN_00936750(first.FUN_0093d7a0(&bridge, "bridgeAtom")->FUN_0093d810(&a), desc->unk00, target);
}
}
}   // namespace f3m_00937b90

// @f3 0x009383e0 (community match, verified in this file)
extern short DAT_0105f5c0;
extern short DAT_0105f548;
namespace f3m_009383e0 {
namespace NativeBridge009383e0 {





struct Pair
{
    int unk00;
    int unk04;
};

struct FUN_0093d600
{
    int unk00;
    int unk04;
    FUN_0093d600() {}
    FUN_0093d600(Pair* obj, const char* name);
    FUN_0093d600(FUN_0093d600& other);
    FUN_0093d600* FUN_0093d7a0(FUN_0093d600* out, const char* name);
    Pair* FUN_0093d810(Pair* out);
    int FUN_0093d660();
    int FUN_0093d690();
    int FUN_0093d710();
    int FUN_0093d720();
    int FUN_0093d790();
    int FUN_0093d850();
    int FUN_0093d860();
    int FUN_0093d870();
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
};

struct Node_9366b0
{
    char* unk00;
    int unk04;
    int FUN_009b0630();
    Node_9366b0* FUN_009b0650(int n);
    Node_9366b0* FUN_0093d890();
    int FUN_009b0760();
};

struct Target_936750
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Set(int value, int size);
};

short __cdecl FUN_00936710(const char* name);

static __declspec(noinline) short FUN_009366b0(FUN_0093d600* p)
{
    Pair t;
    p->FUN_0093d810(&t);
    Node_9366b0* node = (Node_9366b0*)t.unk04;
    int n = node->FUN_009b0630();
    Node_9366b0* r = node->FUN_009b0650(n - 1);
    FUN_0093d600 child;
    p->FUN_0093d7a0(&child, r->unk00);
    unsigned int off = *(unsigned short*)((char*)child.FUN_0093d790() + 0x12);
    return (short)(r->FUN_0093d890()->FUN_009b0760() + off);
}

static __declspec(noinline) void FUN_00936750(Pair* obj, int value, Target_936750* target)
{
    int* pv = &value;
    if (DAT_0105f548 == -1)
        DAT_0105f548 = FUN_00936710("TYPE_BRIDGE");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f548;
    FUN_0093d600 data(obj, "constraintData");
    *data.FUN_0093d670(0) = value;
    target->Set(value, data.FUN_0093d660());
}

void __cdecl FUN_009383e0(FUN_0093d600* src, Pair* desc, Target_936750* target)
{
    FUN_0093d600 first(desc, "atoms");
    FUN_0093d600 second(*src);
    if (DAT_0105f5c0 == -1)
        DAT_0105f5c0 = FUN_009366b0(&first);
    Pair a;
    FUN_0093d600 bridge;
    FUN_00936750(first.FUN_0093d7a0(&bridge, "bridgeAtom")->FUN_0093d810(&a), desc->unk00, target);
}
}
}   // namespace f3m_009383e0

// @f3 0x0092b710 (community match, verified in this file)
namespace f3m_0092b710 {
namespace hinge_constraint_constructor {
struct __declspec(align(16)) Vector4 { float x,y,z,w;__forceinline void SetZero(){x=y=z=w=0.0f;} __forceinline void ClearForward(){x=0.0f;y=0.0f;z=0.0f;w=0.0f;} };
struct __declspec(align(16)) Matrix3 {
 Vector4 columns[3];
 __forceinline void SetIdentity(){
  for(unsigned int i=0;i<3;++i)columns[i].ClearForward();
  columns[0].x=1.0f;columns[1].y=1.0f;columns[2].z=1.0f;
 }
};
struct __declspec(align(16)) Transform { Matrix3 rotation;Vector4 translation;__forceinline void SetIdentity(){rotation.SetIdentity();translation.SetZero();} };
struct __declspec(align(16)) LocalTransformsAtom { unsigned short type,unk02;unsigned int unk04,unk08,unk0C;Transform a,b; };
struct hkBool { char value;__forceinline hkBool& operator=(bool v){value=v?1:0;return *this;} };

struct AngMotorAtom {
    unsigned short type;
    hkBool enabled;
    unsigned char axis;
    unsigned short initializedOffset, previousTargetOffset, limitSolverResultOffset;
    unsigned short unk0a;
    float targetAngle;
    void* motor;
};
struct AngFrictionAtom {
    unsigned short type;
    hkBool enabled;
    unsigned char firstAxis, axisCount;
    unsigned char unk05, unk06, unk07;
    float maxTorque;
};
struct AngLimitAtom {
    unsigned short type;
    hkBool enabled;
    unsigned char axis;
    float minimum, maximum, tauFactor;
};
struct TwoDimensionalAngularAtom { unsigned short type; unsigned char freeAxis, unk03; };
struct BallSocketAtom { unsigned short type; unsigned char notifyBodies, unk03; float limit; };
struct Atoms {
    LocalTransformsAtom transforms;
    AngMotorAtom motor;
    AngFrictionAtom friction;
    AngLimitAtom limit;
    TwoDimensionalAngularAtom twoDimensional;
    BallSocketAtom ballSocket;
    void FUN_0092b840();
    __forceinline Atoms() throw() { FUN_0092b840(); }
};
struct hkBaseObject { virtual ~hkBaseObject() throw(); };
struct hkReferencedObject : hkBaseObject {
    unsigned short memorySizeAndFlags, referenceCount;
    __forceinline hkReferencedObject() throw() : referenceCount(1) {}
};
struct hkpConstraintData : hkReferencedObject {
    unsigned int userData;
    __forceinline hkpConstraintData() throw() : userData(0) {}
};
struct hkpHingeConstraintData : hkpConstraintData {
    Atoms atoms;
    hkpHingeConstraintData() throw();
};
// pdb: hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData | hkpLimitedHingeConstraintData.obj | fnv360_0822_retail, call_gap_sim, high
hkpHingeConstraintData::hkpHingeConstraintData() throw()
{
    atoms.transforms.a.SetIdentity();
    atoms.transforms.b.SetIdentity();
    atoms.limit.minimum = -3.14159274f;
    atoms.twoDimensional.freeAxis = 0;
    atoms.limit.maximum = 3.14159274f;
    atoms.limit.axis = 0;
    atoms.friction.firstAxis = 0;
    atoms.friction.axisCount = 1;
    atoms.limit.tauFactor = 1.0f;
    atoms.motor.initializedOffset = 0x40;
    atoms.motor.previousTargetOffset = 0x44;
    atoms.motor.limitSolverResultOffset = 0x10;
    atoms.friction.maxTorque = 0.0f;
    atoms.motor.enabled = false;
    atoms.motor.motor = 0;
    atoms.motor.targetAngle = 0.0f;
    atoms.motor.axis = 0;
}
}

}   // namespace f3m_0092b710

// @f3 0x00934c20 (community match, verified in this file)
namespace f3m_00934c20 {
void FUN_00934c20(void* source, void* destination)
{
    using f3m_00934b70::f3m_00934b70::FUN_00934b70;
    FUN_00934b70(source, "clavicleIndex", destination);
    FUN_00934b70(source, "shoulderIndex", destination);
    FUN_00934b70(source, "elbowIndex", destination);
    FUN_00934b70(source, "wristIndex", destination);
    FUN_00934b70(source, "hipIndex", destination);
    FUN_00934b70(source, "kneeIndex", destination);
    FUN_00934b70(source, "ankleIndex", destination);
}
}   // namespace f3m_00934c20

// @f3 0x009334b0 (community match, verified in this file)
namespace f3m_009334b0 {
namespace f3m_009334b0 {
struct Member {
    void* object;
    const char* name;
    Member(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
};
static __declspec(noinline) void FUN_009334b0(void* source, void* destination, bool hidden)
{
    Member from(source, "flags");
    Member to(destination, "flags");
    *to.FUN_0093d6e0(0) = *from.FUN_0093d6e0(0);
    if (hidden)
        *to.FUN_0093d6e0(0) |= 0x800;
}
void* volatile g_source; void* volatile g_destination; volatile bool g_hidden;
void caller_of_FUN_009334b0() { FUN_009334b0(g_source, g_destination, g_hidden); }
}
}   // namespace f3m_009334b0

// @f3 0x009346f0 (community match, verified in this file)
namespace f3m_009346f0 {
namespace f3m_009346f0 {
struct Member {
    void* object;
    const char* name;
    Member(void* obj, const char* name);
    int* FUN_0093d6b0(int index);
};
}

void __cdecl FUN_009346f0(void* oldObject, void* newObject)
{
    using namespace f3m_009346f0;
    Member enter(newObject, "enterNotifyEvent");
    Member exit(newObject, "exitNotifyEvent");
    *enter.FUN_0093d6b0(0) = -1;
    *exit.FUN_0093d6b0(0) = -1;
}
}   // namespace f3m_009346f0

// @f3 0x00933390 (community match, verified in this file)
namespace f3m_00933390 {
void __cdecl FUN_00933390(void* src, void* dst, int arg)
{
    n933360::FUN_009332d0(src, dst, "motion", arg, (n933360::Fn)FUN_00933360);
}
}   // namespace f3m_00933390

// @f3 0x00933630 (community match, verified in this file)
extern int G;
namespace f3m_00933630 {
namespace f3m_00933630 {
static __declspec(noinline) void FUN_00933510(int a, int l, int b, int c)
{
    G = a + l + b + c;
}
}

void __cdecl FUN_00933630(int a, int b)
{
    f3m_00933630::FUN_00933510((int)"transitions", a, b, 0);
}
}   // namespace f3m_00933630

// @f3 0x00933410 (community match, verified in this file)
namespace f3m_00933410 {
namespace f3m_00933410 {
void __cdecl FUN_009333c0(void* src, void* dst, int arg);
}

void __cdecl FUN_00933410(void* src, void* dst, int arg)
{
    f3m_00933410::FUN_009333c0(src, dst, arg);
    n933360::FUN_009332d0(src, dst, "motionState", arg, n933360::FUN_009331e0);
}
}   // namespace f3m_00933410

// @f3 0x00933bb0 (community match, verified in this file)
extern int G;
namespace f3m_00933bb0 {
namespace f3m_00933bb0 {
struct Member {
    void* object;
    const char* name;
    Member(void* obj, const char* name);
};
typedef void (__cdecl* CopyFn)(void*, void*);
static __declspec(noinline) void FUN_00933ae0(const Member& source, const Member& destination, void* context, CopyFn fn)
{
    G = (int)&source + (int)&destination + (int)context + (int)fn;
}
}

void __cdecl FUN_00933bb0(void* source, void* destination, void* context)
{
    using namespace f3m_00933bb0;
    FUN_00933ae0(Member(source, "trianglesSubparts"), Member(destination, "trianglesSubparts"), context, f3m_00933a90::Copy396::FUN_00933a90);
    FUN_00933ae0(Member(source, "shapesSubparts"), Member(destination, "shapesSubparts"), context, f3m_00933a90::Copy396::FUN_00933a90);
}
}   // namespace f3m_00933bb0

// @f3 0x009375b0 (community match, verified in this file)
extern short DAT_0105f594;
namespace f3m_009375b0 {
namespace f3m_009375b0 {
struct Vec4 { float v[4]; };
struct Member {
    void* unk00;
    int unk04;
    Member(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    Vec4* FUN_0093d720(int index);
    float* FUN_0093d6a0(int index);
};
static __declspec(noinline) void FUN_009375b0(void* obj, const Vec4* pivotA, const Vec4* pivotB, float ropeLength, float leverage)
{
    const Vec4** pa = &pivotA;
    if (DAT_0105f594 == -1)
        DAT_0105f594 = f3m_00936890::f3m_00936890::n936890::FUN_00936710(obj, "TYPE_PULLEY");
    { Member f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f594; }
    { Member f(obj, "fixedPivotAinWorld"); *f.FUN_0093d720(0) = *pivotA; }
    { Member f(obj, "fixedPivotBinWorld"); *f.FUN_0093d720(0) = *pivotB; }
    { Member f(obj, "ropeLength"); *f.FUN_0093d6a0(0) = ropeLength; }
    { Member f(obj, "leverageOnBodyB"); *f.FUN_0093d6a0(0) = leverage; }
}
void* volatile g_obj; Vec4* volatile g_a; Vec4* volatile g_b; volatile float g_len, g_lev;
void caller_of_FUN_009375b0() { FUN_009375b0(g_obj, g_a, g_b, g_len, g_lev); }
}
}   // namespace f3m_009375b0

// @f3 0x0093bf90 (community match, verified in this file)
namespace f3m_0093bf90 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Heap { void FUN_008f6d90(void* p, unsigned int bytes, int tag) throw(); };
void __cdecl FUN_00901e90(void* arr, int n, int elemSize) throw();
struct Pair { int first; int second; };
struct Array8 {
    Pair* data;
    int size;
    int capAndFlags;
    void SetSize(int n) throw()
    {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(Pair));
        }
        size = n;
    }
    ~Array8() throw()
    {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Heap* h = (Heap*)DAT_00d9b080(DAT_010f3170);
            h->FUN_008f6d90(data, cap * sizeof(Pair), 0x17);
        }
    }
};
struct Base {
    int unk00; int unk04; int unk08;
    ~Base() throw();
};
struct Copy : Base {
    Array8 arr;
    Copy(Array8* source) throw();
};
struct Registry { void* FUN_009b20b0(const char* version) throw(); };
extern Registry* DAT_011693ac;
extern Copy* DAT_01169100;
extern char DAT_0105f538[];
int __cdecl FUN_00940060(void* list, void* b, const void* classes, void* version) throw();
}


int __cdecl FUN_0093bf90(f3m_0093bf90::Array8* list, void* b)
{
    void* version = f3m_0093bf90::DAT_011693ac->FUN_009b20b0("Havok-4.0.0-b2");
    f3m_0093bf90::Copy copy(list);
    f3m_0093bf90::DAT_01169100 = &copy;
    int result = f3m_0093bf90::FUN_00940060(list, b, f3m_0093bf90::DAT_0105f538, version);
    f3m_0093bf90::DAT_01169100 = 0;
    if (!result) {
        result = f3m_0093bf90::FUN_00940060(&copy.arr, b, f3m_0093bf90::DAT_0105f538, version);
        int old = list->size;
        list->SetSize(old + copy.arr.size);
        f3m_0093bf90::Pair* dst = list->data + old;
        for (int i = 0; i < copy.arr.size; i++)
            dst[i] = copy.arr.data[i];
    }
    return result;
}

// @f3 0x00930d80 (community match, verified in this file)
namespace f3m_00930d80 {
// pdb: hkHingeConstraintCinfo::ApplyScale | bhkHingeConstraint.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afScale, apInfo
void __cdecl FUN_00930d80(float param_1, float* param_2)
{
    if (param_2 != 0 && param_1 != 1.0f) {
        param_2[0x14] *= param_1;
        param_2[0x15] *= param_1;
        param_2[0x16] *= param_1;
        param_2[0x17] *= param_1;
        float s = param_1;
        param_2[0x24] *= s;
        param_2[0x25] *= s;
        param_2[0x26] = s * param_2[0x26];
        param_2[0x27] = s * param_2[0x27];
    }
}
}   // namespace f3m_00930d80

// @f3 0x009317a0 (community match, verified in this file)
namespace f3m_009317a0 {
struct LookupEntry9317a0;
struct Arr9317a0;
struct Value9317a0 {
    int a, b;
    Value9317a0(int x, int y) : a(x), b(y) {}
};
struct LookupEntry9317a0 {
    int key;
    int value0;
    Value9317a0 value;
};

struct Arr9317a0 {
    LookupEntry9317a0* data;
    int size;
    void RemoveAt(int index) { size--; for (int i = index; i < size; i++) data[i] = data[i + 1]; }
};
class LookupOwner9317a0 {
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
    Arr9317a0 arr;

    Value9317a0 FUN_009317a0(int key);
};

Value9317a0 LookupOwner9317a0::FUN_009317a0(int key)
{
    for (int i = 0; i < arr.size; i++) {
        if (arr.data[i].key == key) {
            LookupEntry9317a0 e = arr.data[i];
            arr.RemoveAt(i);
            return e.value;
        }
    }
    return Value9317a0(0, 0);
}
}   // namespace f3m_009317a0

// @f3 0x00938460 (community match, verified in this file)
extern short DAT_0105f5c4;
extern short DAT_0105f550;
extern short DAT_0105f55c;
namespace f3m_00938460 {
namespace f3m_00938460 {
struct Translation { float v[4]; };
struct Pair { int a; int b; Pair() {} };
struct R2 { void FUN_009b2360(); };
struct R1 { R2* FUN_0093d8b0(); };
struct Variant {
    void* object;
    const void* klass;
    Variant(void* obj);
};
struct Member {
    void* unk00;
    int unk04;
    Member() {}
    Member(void* obj, const char* name);
    Member(Variant* v, const char* name);
    short* FUN_0093d6e0(int index);
    Translation* FUN_0093d720(int index);
    float* FUN_0093d6a0(int index);
    R1* FUN_0093d790(const char* name, short* out);
    Member FUN_0093d7a0(const char* name);
    Pair FUN_0093d810();
};
short __cdecl FUN_00936690(Member* acc);
static __declspec(noinline) short FUN_009366b0(Member* acc)
{
    return FUN_00936690(acc);
}
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    short id;
    Member f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}
static __declspec(noinline) void FUN_00936890(void* obj, const Translation* a, const Translation* b)
{
    void** po = &obj;
    if (DAT_0105f550 == -1)
        DAT_0105f550 = FUN_00936710(obj, "TYPE_SET_LOCAL_TRANSLATIONS");
    { Member f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f550; }
    { Member f(obj, "translationA"); *f.FUN_0093d720(0) = *a; }
    { Member f(obj, "translationB"); *f.FUN_0093d720(0) = *b; }
}
short __cdecl FUN_00936700(const char* name, int len);
int __cdecl FUN_009366f0(void* obj);
static __declspec(noinline) short FUN_00936710b(void* obj, const char* name)
{
    int n = FUN_009366f0(obj);
    return FUN_00936700(name, n);
}
static __declspec(noinline) void FUN_00936a40(void* obj, float length)
{
    if (DAT_0105f55c == -1)
        DAT_0105f55c = FUN_00936710b(obj, "TYPE_STIFF_SPRING");
    { Member a(obj, "type"); *a.FUN_0093d6e0(0) = DAT_0105f55c; }
    { Member a(obj, "length"); *a.FUN_0093d6a0(0) = length; }
}
void* volatile g_obj; Translation* volatile g_a; Translation* volatile g_b; volatile float g_len;
void caller_of_helpers() { FUN_00936890(g_obj, g_a, g_b); FUN_00936a40(g_obj, g_len); }
}

void __cdecl FUN_00938460(void* oldObject, void* newObject)
{
    using namespace f3m_00938460;
    Member atoms(newObject, "atoms");
    Variant old(oldObject);
    if (DAT_0105f5c4 == -1)
        DAT_0105f5c4 = FUN_009366b0(&atoms);
    {
        Member pb(&old, "pivotInB");
        Member pa(&old, "pivotInA");
        Translation* b = pb.FUN_0093d720(0);
        Translation* a = pa.FUN_0093d720(0);
        FUN_00936890(&atoms.FUN_0093d7a0("pivots").FUN_0093d810(), a, b);
    }
    {
        Member len(&old, "springLength");
        FUN_00936a40(&atoms.FUN_0093d7a0("spring").FUN_0093d810(), *len.FUN_0093d6a0(0));
    }
}
}   // namespace f3m_00938460

// @f3 0x00937c90 (community match, verified in this file)
extern short DAT_0105f5b8;
extern short DAT_0105f550;
extern short DAT_0105f594;
namespace f3m_00937c90 {
namespace f3m_00937c90 {
struct Translation { float v[4]; };
struct Pair { int a; int b; Pair() {} };
struct R2 { void FUN_009b2360(); };
struct R1 { R2* FUN_0093d8b0(); };
struct Variant {
    void* object;
    const void* klass;
    Variant(void* obj);
};
struct Member {
    void* unk00;
    int unk04;
    Member() {}
    Member(void* obj, const char* name);
    Member(Variant* v, const char* name);
    short* FUN_0093d6e0(int index);
    Translation* FUN_0093d720(int index);
    float* FUN_0093d6a0(int index);
    R1* FUN_0093d790(const char* name, short* out);
    Member FUN_0093d7a0(const char* name);
    Pair FUN_0093d810();
};
short __cdecl FUN_00936690(Member* acc);
static __declspec(noinline) short FUN_009366b0(Member* acc)
{
    return FUN_00936690(acc);
}
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    short id;
    Member f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}
static __declspec(noinline) void FUN_00936890(void* obj, const Translation* a, const Translation* b)
{
    void** po = &obj;
    if (DAT_0105f550 == -1)
        DAT_0105f550 = FUN_00936710(obj, "TYPE_SET_LOCAL_TRANSLATIONS");
    { Member f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f550; }
    { Member f(obj, "translationA"); *f.FUN_0093d720(0) = *a; }
    { Member f(obj, "translationB"); *f.FUN_0093d720(0) = *b; }
}
static __declspec(noinline) void FUN_009375b0(void* obj, const Translation* pivotA, const Translation* pivotB, float ropeLength, float leverage)
{
    const Translation** pa = &pivotA;
    if (DAT_0105f594 == -1)
        DAT_0105f594 = FUN_00936710(obj, "TYPE_PULLEY");
    { Member f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f594; }
    { Member f(obj, "fixedPivotAinWorld"); *f.FUN_0093d720(0) = *pivotA; }
    { Member f(obj, "fixedPivotBinWorld"); *f.FUN_0093d720(0) = *pivotB; }
    { Member f(obj, "ropeLength"); *f.FUN_0093d6a0(0) = ropeLength; }
    { Member f(obj, "leverageOnBodyB"); *f.FUN_0093d6a0(0) = leverage; }
}
void* volatile g_obj; Translation* volatile g_a; Translation* volatile g_b; volatile float g_len;
void caller_of_helpers() { FUN_00936890(g_obj, g_a, g_b); FUN_009375b0(g_obj, g_a, g_b, g_len, g_len); }
}

void __cdecl FUN_00937c90(void* oldObject, void* newObject)
{
    using namespace f3m_00937c90;
    Member atoms(newObject, "atoms");
    Variant old(oldObject);
    if (DAT_0105f5b8 == -1)
        DAT_0105f5b8 = FUN_009366b0(&atoms);
    {
        Member pb(&old, "pivotInB");
        Member pa(&old, "pivotInA");
        Translation* b = pb.FUN_0093d720(0);
        Translation* a = pa.FUN_0093d720(0);
        FUN_00936890(&atoms.FUN_0093d7a0("translations").FUN_0093d810(), a, b);
    }
    {
        Member lev(&old, "leverageOnBodyB");
        Member rope(&old, "ropeLength");
        Member pivB(&old, "pulleyPivotBinWorld");
        Member pivA(&old, "pulleyPivotAinWorld");
        FUN_009375b0(&atoms.FUN_0093d7a0("pulley").FUN_0093d810(), pivA.FUN_0093d720(0), pivB.FUN_0093d720(0), *rope.FUN_0093d6a0(0), *lev.FUN_0093d6a0(0));
    }
}
}   // namespace f3m_00937c90

// @f3 0x00932b50 (community match, verified in this file)
namespace f3m_00932b50 {
namespace f3m_00932b50 {
struct Klass { int FUN_009b0760() const; };
struct MemberInfo { const Klass* FUN_0093d890() const; };
struct Variant { void* object; const Klass* klass; };
struct Ret { void* object; const Klass* klass; Ret(); };
struct ArrayRef { char* data; int count; };
struct Member {
    void* object;
    const char* name;
    Member(void* obj, const char* name);
    ArrayRef* FUN_0093d760(int index) const;
    Ret FUN_0093d810() const;
    const MemberInfo* FUN_0093d790() const;
    short* FUN_0093d6e0(int index);
};
static __declspec(noinline) void FUN_00932b00(void* src, void* dst)
{
    Member a(src, "handIndex");
    Member b(dst, "handIkTrackIndex");
    *b.FUN_0093d6e0(0) = *a.FUN_0093d6e0(0);
}
void* volatile g_a; void* volatile g_b;
void caller_of_FUN_00932b00() { FUN_00932b00(g_a, g_b); }
}

void __cdecl FUN_00932b50(void* oldObject, void* newObject)
{
    using namespace f3m_00932b50;
    Member src(oldObject, "hands");
    Member dst(newObject, "hands");
    int count = src.FUN_0093d760(0)->count;
    Variant a;
    a.klass = src.FUN_0093d810().klass;
    Variant b;
    b.klass = dst.FUN_0093d810().klass;
    int sizeA = src.FUN_0093d790()->FUN_0093d890()->FUN_009b0760();
    int sizeB = dst.FUN_0093d790()->FUN_0093d890()->FUN_009b0760();
    for (int i = 0; i < count; i++) {
        a.object = src.FUN_0093d760(0)->data + i * sizeA;
        b.object = dst.FUN_0093d760(0)->data + i * sizeB;
        FUN_00932b00(&a, &b);
    }
}
}   // namespace f3m_00932b50

// @f3 0x00923f00 (community match, verified in this file)
namespace n923f00 {
extern unsigned long DAT_010f3170;
struct Alloc {
    void* FUN_008f6d30(int size, int tag) throw();
    void FUN_008f6d90(void* p, int size, int tag) throw();
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
inline Alloc* FUN_00d9b080(unsigned long i) { return (Alloc*)TlsGetValue(i); }
struct hkBool {
    char b;
    hkBool() {}
    hkBool(bool v) : b(v) {}
    operator bool() const { return b != 0; }
};
struct IntArr {
    int* data;
    int count;
    int capAndFlags;
};
struct InplaceArr : IntArr {
    int storage[12];
    InplaceArr() { data = storage; count = 0; capAndFlags = 0x8000000c; }
    ~InplaceArr()
    {
        if ((capAndFlags & 0x80000000) == 0) {
            int n = capAndFlags & 0x3fffffff;
            Alloc* a = FUN_00d9b080(DAT_010f3170);
            a->FUN_008f6d90(data, n * 4, 0x17);
        }
    }
};
struct hkStr;
hkBool __cdecl FUN_009235a0(const char* haystack, const char* needle, IntArr* arr, int all) throw();
void __cdecl FUN_00923ae0(char* dst, const char* src, int srcLen, const hkStr& from, const hkStr& to, IntArr* indices) throw();
void __cdecl FUN_00901e90(void* arr, int capacity, int stride) throw();
struct hkStr {
    char* data;
    int size;
    int cap;
    const char* cString() const { return data; }
    hkBool FUN_00923f00(const hkStr& from, const hkStr& to, int rtype);
};

hkBool hkStr::FUN_00923f00(const hkStr& from, const hkStr& to, int rtype)
{
    InplaceArr indices;
    hkBool result;
    if (FUN_009235a0(cString(), from.cString(), &indices, rtype)) {
        int newLen = (to.size - from.size) * indices.count + size;
        char* buf;
        if (newLen > size) {
            Alloc* a = FUN_00d9b080(DAT_010f3170);
            buf = (char*)a->FUN_008f6d30(newLen, 0x16);
        } else
            buf = data;
        FUN_00923ae0(buf, data, size - 1, from, to, &indices);
        buf[newLen - 1] = 0;
        if (buf != data) {
            if ((cap & 0x80000000) == 0) {
                int n = cap & 0x3fffffff;
                Alloc* a = FUN_00d9b080(DAT_010f3170);
                a->FUN_008f6d90(data, n, 0x17);
            }
            cap = newLen;
            size = newLen;
            data = buf;
        } else {
            int c = cap & 0x3fffffff;
            if (c < newLen)
                FUN_00901e90(this, newLen < c * 2 ? c * 2 : newLen, 1);
            size = newLen;
        }
        result = true;
    } else {
        result = false;
    }
    return result;
}
}

// @f3 0x00931000 (community match, verified in this file)
namespace f3m_00931000 {
namespace f3m_00931000 {
struct Mem_1000 {
    void* FUN_008f6d30(int bytes, int tag);
    void FUN_008f6d90(void* p, int bytes, int tag);
};
extern Mem_1000* (__stdcall* DAT_00d9b080)(int);
struct Motion_1000 {
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    float unk30, unk34, unk38, unk3c;
    void FUN_008fda60(const Motion_1000& other);
};
class FUN_00930c40 {
public:
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    Motion_1000 first;
    Motion_1000 second;
    int unka0, unka4, unka8, unkac;
    FUN_00930c40();
    static void* operator new(unsigned int size)
    {
        Mem_1000* mem = DAT_00d9b080(::DAT_010f3170);
        FUN_00930c40* p = (FUN_00930c40*)mem->FUN_008f6d30(size, 0x2c);
        p->memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p, unsigned int size)
    {
        DAT_00d9b080(::DAT_010f3170)->FUN_008f6d90(p, size, 0x2c);
    }
};
__declspec(noinline) void __cdecl FUN_00930d80(float scale, FUN_00930c40* dst)
{
    if (dst && scale != 1.0f) {
        dst->first.unk30 *= scale;
        dst->first.unk34 *= scale;
        dst->first.unk38 *= scale;
        dst->first.unk3c *= scale;
        dst->second.unk30 *= scale;
        dst->second.unk34 *= scale;
        dst->second.unk38 *= scale;
        dst->second.unk3c *= scale;
    }
}
struct Cinfo_1000 { int unk00, unk04, unk08, unk0c; float scale; };
struct Cloner_1000 {
    int unk00;
    FUN_00930c40* source;
    FUN_00930c40* FUN_008fc3f0(FUN_00930c40* dst, Cinfo_1000* cinfo);
    FUN_00930c40* FUN_00931000(FUN_00930c40* dst, Cinfo_1000* cinfo);
};
FUN_00930c40* Cloner_1000::FUN_00931000(FUN_00930c40* dst, Cinfo_1000* cinfo)
{
    FUN_00930c40* src = source;
    if (!dst)
        dst = new FUN_00930c40;
    dst->first.FUN_008fda60(src->first);
    dst->second.FUN_008fda60(src->second);
    float scale = cinfo->scale;
    if (scale != 1.0f)
        FUN_00930d80(scale, dst);
    return FUN_008fc3f0(dst, cinfo);
}
}
}   // namespace f3m_00931000

// @f3 0x009356e0 (community match, verified in this file)
namespace f3m_009356e0 {
namespace f3m_009356e0 {

extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct N56Heap {
    void* FUN_008f6d30(int bytes, int category) throw();
    void FUN_008f6d90(void* memory, int bytes, int category) throw();
};
void* FUN_009234e0(void* dst, const void* src, unsigned int n) throw();
struct N56Buffer {
    char* data;
    int size;
    int capacityAndFlags;
    __forceinline N56Buffer() : data(0), size(0), capacityAndFlags(0x80000000) {}
    __forceinline void Free() {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            N56Heap* heap = (N56Heap*)DAT_00d9b080(::DAT_010f3170);
            heap->FUN_008f6d90(data, capacity, 0x17);
        }
    }
};
union N56Pair { __int64 packed; struct { void* data; int size; }; };
struct N56Array { void* data; int size; int capacityAndFlags; };
struct N56Raw { void* object; const void* type; };
struct FUN_0093d7f0 {
    void* object;
    const void* type;
    FUN_0093d7f0() {}
    FUN_0093d7f0(const N56Raw&) throw();
    FUN_0093d7f0(void*, const void*) throw();
};
struct FUN_0093d600 {
    void* address;
    const void* member;
    FUN_0093d600(const FUN_0093d7f0&, const char*) throw();
    FUN_0093d7f0 FUN_0093d810() throw();
    N56Array* FUN_0093d650() throw();
    int& FUN_0093d6b0(int index) throw();
    unsigned char& FUN_0093d710(int index) throw();
    N56Pair& FUN_0093d760(int index) throw();
    void* FUN_0093d660() throw();
};
struct N56Tracker {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void AddChunk10(void*, int, int) throw();
    virtual void PointedBy14(void*, void*) throw();
};
__forceinline void* N56Alloc(int size, int category)
{
    N56Heap* heap = (N56Heap*)DAT_00d9b080(::DAT_010f3170);
    return heap->FUN_008f6d30(size, category);
}
__forceinline FUN_0093d7f0 N56Member(const FUN_0093d7f0& v, const char* name)
{
    FUN_0093d600 f(v, name);
    return f.FUN_0093d810();
}
__forceinline int N56ArraySize(const FUN_0093d7f0& v, const char* name)
{
    FUN_0093d600 f(v, name);
    return f.FUN_0093d650()->size;
}
void FUN_00935040(N56Raw*, N56Raw*, N56Tracker*) throw();
int FUN_00935c10(const FUN_0093d600&, int, N56Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935d90(const FUN_0093d600&, N56Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935c90(const FUN_0093d600&, N56Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935e10(const FUN_0093d600&, int, int, N56Buffer&, int, const FUN_0093d600&) throw();
int FUN_00935d10(const FUN_0093d600&, N56Buffer&, int, const FUN_0093d600&) throw();

void FUN_009356e0(N56Raw* oldObject, N56Raw* newObject, N56Tracker* tracker)
{
    FUN_0093d7f0 newVariant(*newObject);
    FUN_0093d7f0 oldVariant(*oldObject);
    FUN_00935040(oldObject, newObject, tracker);
    FUN_0093d7f0 oldFormat = N56Member(oldVariant, "qFormat");
    FUN_0093d7f0 newFormat = N56Member(newVariant, "qFormat");
    FUN_0093d600 offsetField(oldFormat, "offset");
    int dimensions = offsetField.FUN_0093d650()->size;
    {
        FUN_0093d600 f(newFormat, "numD");
        f.FUN_0093d6b0(0) = dimensions;
    }
    N56Buffer buffer;
    int offset;
    {
        FUN_0093d600 destination(newFormat, "offsetIdx");
        FUN_0093d600 source(oldFormat, "offset");
        offset = FUN_00935c10(source, dimensions * 4, buffer, 0, destination);
    }
    {
        FUN_0093d600 destination(newFormat, "scaleIdx");
        FUN_0093d600 source(oldFormat, "scale");
        offset += FUN_00935c10(source, dimensions * 4, buffer, offset, destination);
    }
    {
        FUN_0093d600 destination(newVariant, "staticDOFsIdx");
        FUN_0093d600 source(oldVariant, "staticDOFs");
        offset += FUN_00935d90(source, buffer, offset, destination);
    }
    int blockIndexSize;
    {
        FUN_0093d600 destination(newVariant, "blockIndexIdx");
        FUN_0093d600 source(oldVariant, "blockIndex");
        blockIndexSize = FUN_00935d90(source, buffer, offset, destination);
    }
    {
        FUN_0093d600 f(newVariant, "blockIndexSize");
        f.FUN_0093d6b0(0) = (unsigned int)blockIndexSize >> 2;
    }
    offset += blockIndexSize;
    {
        FUN_0093d600 destination(newVariant, "staticMaskIdx");
        FUN_0093d600 source(oldVariant, "staticMask");
        offset += FUN_00935c90(source, buffer, offset, destination);
    }
    {
        FUN_0093d600 destination(newFormat, "bitWidthIdx");
        FUN_0093d600 maximum(newFormat, "maxBitWidth");
        FUN_0093d600 source(oldFormat, "bitWidth");
        offset += FUN_00935e10(source, dimensions, maximum.FUN_0093d710(0), buffer, offset, destination);
    }
    int quantizedSize;
    {
        FUN_0093d600 destination(newVariant, "quantizedDataIdx");
        FUN_0093d600 source(oldVariant, "quantizedData");
        quantizedSize = FUN_00935d10(source, buffer, offset, destination);
    }
    {
        FUN_0093d600 f(newVariant, "quantizedDataSize");
        f.FUN_0093d6b0(0) = quantizedSize;
    }
    N56Pair* output;
    {
        FUN_0093d600 f(newVariant, "dataBuffer");
        output = &f.FUN_0093d760(0);
    }
    output->size = buffer.size;
    output->data = N56Alloc(buffer.size, 0x38);
    FUN_009234e0(output->data, buffer.data, output->size);
    {
        FUN_0093d600 f(newVariant, "dataBuffer");
        N56Tracker& t = *tracker;
        t.PointedBy14(output->data, f.FUN_0093d660());
    }
    tracker->AddChunk10(output->data, output->size, 0x38);
    buffer.Free();
}

}
}   // namespace f3m_009356e0

// @f3 0x0093b940 (community match, verified in this file)
namespace f3m_0093b940 {
struct Variant {
    void* object;
    const void* klass;
    Variant(void* obj);
};
struct Member {
    void* object;
    const char* name;
    Member(const Variant& v, const char* name);
    int* FUN_0093d670(int index);
    char* FUN_0093d660();
};
struct Manager { void* FUN_009227d0(int key, int flag); };
extern Manager* DAT_01169100;
struct BoolRet { bool value; BoolRet(); };
BoolRet __cdecl FUN_0093c0a0(void* klass, const char* name);
struct Visitor {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void Visit(int oldEntity, void* newEntity);
};
}

// pdb: `anonymous namespace'::updateConstraintInstance300 | hkClassUpdate.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_0093b940(void* oldObject, void* newObject, f3m_0093b940::Visitor* visitor)
{
    using f3m_0093b940::Variant;
    using f3m_0093b940::Member;
    Variant vNew(newObject);
    Variant vOld(oldObject);
    int data;
    { Member m(vOld, "data"); data = *m.FUN_0093d670(0); }
    void* klass = f3m_0093b940::DAT_01169100->FUN_009227d0(data, 0);
    if (!klass)
        return;
    f3m_0093b940::BoolRet ok = f3m_0093b940::FUN_0093c0a0(klass, "hkPointToPlaneConstraintData");
    if (!ok.value)
        return;
    {
        Member n(vNew, "entities");
        Member o(vOld, "entities");
        f3m_0093b940::Visitor& t = *visitor;
        t.Visit(*o.FUN_0093d670(1), n.FUN_0093d660());
    }
    {
        Member n(vNew, "entities");
        char* q = n.FUN_0093d660();
        Member o(vOld, "entities");
        f3m_0093b940::Visitor& t = *visitor;
        t.Visit(*o.FUN_0093d670(0), q + 4);
    }
}

// @f3 0x00938a70 (community match, verified in this file)
extern short DAT_0105f588;
extern short DAT_0105f58c;
extern short DAT_0105f57c;
extern const float DAT_00e008bc;
extern const float DAT_00e78c38;
namespace f3m_00938a70 {
namespace f3m_00938a70 {
struct HgMember;
struct HgPair { int a; int b; HgPair() {} inline HgMember M(const char* name); };
struct HgVariant {
    void* object;
    void* klass;
    HgVariant(void* obj);
    inline HgMember M(const char* name);
};
struct HgMember {
    void* unk00;
    int unk04;
    HgMember() {}
    HgMember(void* obj, const char* name);
    HgMember(HgVariant* v, const char* name);
    short* FUN_0093d6e0(int index);
    int* FUN_0093d670(int index);
    char* FUN_0093d690(int index);
    char* FUN_0093d710(int index);
    float* FUN_0093d6a0(int index);
    void* FUN_0093d660();
    HgMember FUN_0093d7a0(const char* name);
    HgPair FUN_0093d810();
};
inline HgMember HgPair::M(const char* name) { return HgMember(this, name); }
inline HgMember HgVariant::M(const char* name) { return HgMember(this, name); }
struct HgTracker {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void AddChunk10(void*, int, int);
    virtual void PointedBy14(void*, void*);
};
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    HgMember f(obj, "type");
    short value = 0;
    if (name)
        value = *f.FUN_0093d6e0(0);
    return value;
}
static __declspec(noinline) void FUN_00937270(void* obj, char isEnabled, char firstFrictionAxis,
                                              char numFrictionAxes, float maxFrictionTorque)
{
    if (DAT_0105f588 == -1)
        DAT_0105f588 = FUN_00936710(obj, "TYPE_ANG_FRICTION");
    { HgMember a(obj, "type"); *a.FUN_0093d6e0(0) = DAT_0105f588; }
    { HgMember a(obj, "isEnabled"); *a.FUN_0093d710(0) = isEnabled; }
    { HgMember a(obj, "firstFrictionAxis"); *a.FUN_0093d710(0) = firstFrictionAxis; }
    { HgMember a(obj, "numFrictionAxes"); *a.FUN_0093d710(0) = numFrictionAxes; }
    { HgMember a(obj, "maxFrictionTorque"); *a.FUN_0093d6a0(0) = maxFrictionTorque; }
}
static __declspec(noinline) void FUN_00937340(void* obj, char isEnabled, char motorAxis, short initializedOffset,
                                              short previousTargetAngleOffset, short limitResultOffset, float targetAngle, int motor)
{
    if (DAT_0105f58c == -1)
        DAT_0105f58c = FUN_00936710(obj, "TYPE_ANG_MOTOR");
    { HgMember a(obj, "type"); *a.FUN_0093d6e0(0) = DAT_0105f58c; }
    { HgMember a(obj, "isEnabled"); *a.FUN_0093d690(0) = isEnabled; }
    { HgMember a(obj, "motorAxis"); *a.FUN_0093d710(0) = motorAxis; }
    { HgMember a(obj, "initializedOffset"); *a.FUN_0093d6e0(0) = initializedOffset; }
    { HgMember a(obj, "previousTargetAngleOffset"); *a.FUN_0093d6e0(0) = previousTargetAngleOffset; }
    { HgMember a(obj, "correspondingAngLimitSolverResultOffset"); *a.FUN_0093d6e0(0) = limitResultOffset; }
    { HgMember a(obj, "targetAngle"); *a.FUN_0093d6a0(0) = targetAngle; }
    { HgMember a(obj, "motor"); *a.FUN_0093d670(0) = motor; }
}
static __declspec(noinline) void FUN_00936f40(void* obj, char enabled, char axis, float minAngle, float maxAngle, float tau)
{
    if (DAT_0105f57c == -1)
        DAT_0105f57c = FUN_00936710(obj, "TYPE_ANG_LIMIT");
    { HgMember a(obj, "type"); *a.FUN_0093d6e0(0) = DAT_0105f57c; }
    { HgMember a(obj, "isEnabled"); *a.FUN_0093d710(0) = enabled; }
    { HgMember a(obj, "limitAxis"); *a.FUN_0093d710(0) = axis; }
    { HgMember a(obj, "minAngle"); *a.FUN_0093d6a0(0) = minAngle; }
    { HgMember a(obj, "maxAngle"); *a.FUN_0093d6a0(0) = maxAngle; }
    { HgMember a(obj, "angularLimitsTauFactor"); *a.FUN_0093d6a0(0) = tau; }
}
void* volatile g_obj_hg;
volatile char g_c_hg;
volatile short g_s_hg;
volatile float g_f_hg;
volatile int g_i_hg;
void caller_of_helpers_hg()
{
    FUN_00937270(g_obj_hg, g_c_hg, g_c_hg, g_c_hg, g_f_hg);
    FUN_00937340(g_obj_hg, g_c_hg, g_c_hg, g_s_hg, g_s_hg, g_s_hg, g_f_hg, g_i_hg);
    FUN_00936f40(g_obj_hg, g_c_hg, g_c_hg, g_f_hg, g_f_hg, g_f_hg);
}
inline int HgGetInt(HgVariant& v, const char* name) { HgMember m(&v, name); return *m.FUN_0093d670(0); }
inline float HgGetFloat(HgVariant& v, const char* name) { HgMember m(&v, name); return *m.FUN_0093d6a0(0); }
inline bool HgGetBool(HgVariant& v, const char* name) { HgMember m(&v, name); return *m.FUN_0093d690(0) != 0; }
inline void HgFix(HgTracker* t, const HgMember& val, const HgMember& loc)
{
    t->PointedBy14((void*)*((HgMember&)val).FUN_0093d670(0), ((HgMember&)loc).FUN_0093d660());
}
inline void HgFixR(HgTracker* t, HgMember val, HgMember loc)
{
    t->PointedBy14((void*)*val.FUN_0093d670(0), loc.FUN_0093d660());
}
void __cdecl FUN_00938610(void* oldObject, void* newObject, HgTracker* tracker);
}

void __cdecl FUN_00938a70(void* oldObject, void* newObject, f3m_00938a70::HgTracker* tracker)
{
    using namespace f3m_00938a70;
    FUN_00938610(oldObject, newObject, tracker);
    HgMember atoms(newObject, "atoms");
    HgVariant oldVariant(oldObject);
    bool active;
    {
        HgMember ma(&oldVariant, "motorActive");
        active = *ma.FUN_0093d690(0) && HgGetInt(oldVariant, "motor") != 0;
    }
    {
        HgMember motor(&oldVariant, "motor");
        HgMember target(&oldVariant, "targetAngle");
        FUN_00937340(&atoms.FUN_0093d7a0("angMotor").FUN_0093d810(), active, 0, 0x40, 0x44, 0x10,
                     *target.FUN_0093d6a0(0), *motor.FUN_0093d670(0));
    }
    {
        if (*oldVariant.M("motor").FUN_0093d670(0) != 0) {
            HgFix(tracker, atoms.FUN_0093d7a0("angMotor").FUN_0093d810().M("motor"), atoms.FUN_0093d7a0("angMotor").FUN_0093d810().M("motor"));
        }
    }
    {
        HgMember m(&oldVariant, "maxFrictionTorque");
        FUN_00937270(&atoms.FUN_0093d7a0("angFriction").FUN_0093d810(), active == 0, 0, 1, *m.FUN_0093d6a0(0));
    }
    FUN_00936f40(&atoms.FUN_0093d7a0("angLimit").FUN_0093d810(), 1, 0,
        *oldVariant.M("ignoreLimits").FUN_0093d690(0) ? DAT_00e78c38 : *oldVariant.M("minAngle").FUN_0093d6a0(0),
        *oldVariant.M("ignoreLimits").FUN_0093d690(0) ? DAT_00e008bc : *oldVariant.M("maxAngle").FUN_0093d6a0(0),
        *oldVariant.M("angularLimitsTauFactor").FUN_0093d6a0(0));
}
}   // namespace f3m_00938a70

// @f3 0x00935240 (community match, verified in this file)
namespace f3m_00935240 {
// Model of FUN_00935240 (91 bytes; cdecl with two arguments - plain retn). Their flow is one straight line:
//   sub esp,0Ch ; push esi ; mov esi,[arg_0] ; lea ecx,[var_C] ; push esi ; call sub_935BD0        - initialise a 4-byte local handle
//   mov ecx,dword_11693AC ; lea eax,[var_C] ; push "Havok-4.1.0-b1" ; mov dword_11690FC,eax ; call sub_9B20B0
//   mov ecx,[arg_4] ; push eax ; push offset off_105EF30 ; push ecx ; push esi ; call sub_940060 ; add esp,10h
//   lea ecx,[var_C] ; mov esi,eax ; mov dword_11690FC,0 ; call sub_922CF0                          - the handle is closed explicitly
//   mov eax,esi ; pop esi ; add esp,0Ch ; retn
// Declaring that local as a C++ object with a destructor made VC8 wrap the whole function in an exception frame
// (149 bytes), which is also what the previous attempt reported; their build has no such frame, so the two calls are
// written explicitly here. Sibling verified bodies f3m_00933a20 / f3m_00936210 in this unit fix the conventions used below.

namespace f3m_00935240 {

struct Handle                                    // the 4-byte local at [esp+var_C]; initialised and closed by external member calls ??
{
    void* field0;
    void* field4;
    void* field8;
    void FUN_0093bd0(void* owner);               // ORIG: lea ecx,[var_C] ; push esi ; call sub_935BD0 ??
    void FUN_0092cf0();                          // ORIG: lea ecx,[var_C] ; call sub_922CF0 after the global is cleared, before returning ??
};

extern void* DAT_011690FC;                       // ORIG: mov dword ptr [0x11690fc],eax holding &local, later set to 0 ??

struct Registry { void* FUN_009b20b0(const char* version); };   // exactly as in the verified siblings of this unit ??
extern Registry* DAT_011693AC;                   // ORIG: mov ecx,dword ptr [0x11693ac] - receiver of the version lookup ??

extern const void* DAT_0105EF30;                 // ORIG: push offset off_105EF30
extern const char DAT_00E65700[];                // ORIG: push 0xe65700 - the shared "Havok-4.1.0-b1" literal in .rdata, referenced by address rather than as a fresh copy

int __cdecl FUN_00940060(void* a, void* b, const void* description, void* registry);   // ORIG: four pushes ; call ; add esp,10h ??

void* __cdecl FUN_00935240(void* a, void* b) {
    Handle handle;                               // only this local plus the /GS canary occupies the frame: sub esp,0Ch ??
    handle.FUN_0093bd0(a);                       // ESI banks the first argument because it is pushed again after two calls ??

    DAT_011690FC = &handle;                      // ORIG: lea eax,[var_C] ; mov dword ptr [0x11690fc],eax - between the push and the call ??
    void* registry = DAT_011693AC->FUN_009b20b0(DAT_00E65700);   // ORIG: mov ecx,[0x11693ac] ; push 0xe65700 ; call sub_9B20B0 ??

    void* result = (void*)FUN_00940060(a, b, &DAT_0105EF30, registry);   // ORIG: push eax ; push offset off_105EF30 ; push ecx([arg_4]) ; push esi ??

    DAT_011690FC = 0;                            // ORIG: mov dword ptr [0x11690fc],0 ??
    handle.FUN_0092cf0();                        // ORIG: lea ecx,[var_C] ; call sub_922CF0 ??
    return result;                               // ORIG: mov eax,esi ; pop esi ; add esp,0Ch ; retn ??
}

}
}   // namespace f3m_00935240

// @f3 0x00921a80 (community match, verified in this file)
namespace f3m_00921a80 {
namespace Append921a80 {
struct Entry {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 void FUN_00568710();
};
struct Array {Entry* data;int size;unsigned capacityFlags;};
void __cdecl FUN_00901f10(Array*,unsigned);
struct Object {
 int unk00,unk04,unk08,unk0c;
 Array entries;
 void FUN_00921a80();
};
// pdb: hkpAllCdPointTempCollector::reset | ViewCaster.obj | tesv_win, vtable, medium
void Object::FUN_00921a80() {
 Array* array=&entries;
 if(array->size==(array->capacityFlags&0x3fffffff)) FUN_00901f10(array,64);
 Entry* entry=array->data+array->size;
 ++array->size;
 entry->FUN_00568710();
}
}
}   // namespace f3m_00921a80

// @f3 0x0092b8d0 (community match, verified in this file)
namespace Init92b8d0 {
extern float DAT_01092a50,DAT_01092a54,DAT_01092a58,DAT_01092a5c;
extern int DAT_00e36d3c;
struct Object {
 void* table;
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 float x,y,z,w,value;
 void FUN_00837e10();Object* FUN_0092b8d0();
};
// pdb: bhkForceController::bhkForceController | bhkForceController.obj | fnv360_0822_retail, call_gap_sim, low
Object* Object::FUN_0092b8d0() {
 FUN_00837e10();
 table=&DAT_00e36d3c;
 x=DAT_01092a50;y=DAT_01092a54;z=DAT_01092a58;w=DAT_01092a5c;value=0;
 return this;
}
}

// @f3 0x009318f0 (community match, verified in this file)
namespace f3m_009318f0 {
namespace Release9318f0 {
struct Object;
struct Event {unsigned char type;Object* object;};
struct Owner {
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
int unk80;
void* queue;void FUN_00902570(Event*);
};
struct Object {
virtual void destroy(int);
unsigned short managed;short refs;Owner* owner;
void FUN_009318f0();
};
void Object::FUN_009318f0(){
Owner* p=owner;
if(p && p->queue){Event event;event.object=this;event.type=0x1e;p->FUN_00902570(&event);}
else if(managed && --refs==0)destroy(1);
}
}

}   // namespace f3m_009318f0

// @f3 0x00936250 (community match, verified in this file)
namespace f3m_00936250 {
// Model of FUN_00936250 (165 bytes) - claim clm_81867dcc842c40248de1 ✓✓ SECOND revision, after a first pass at 159 vs 165 with fifty differing lines whose diff was structurally line-for-line identical apart from three
// modelling choices listed below ✓✗→✓✓ That is the best kind of residue: every instruction in place, only frame geometry, exit shape and string binding wrong ✗✗→? 
// PACK GIFT (why this entry looked worth claiming): prelude line 451 names a struct after its own constructor 'struct FUN_0093d600 {', line 454 declares 'FUN_0093d600(void* obj, const char* name);' - exactly my three
// constructions ✓✗→✓✓ line 455 declares 'short* FUN_0093d6e0(int index);' and the sibling at line 466 uses it as '*type.FUN_0093d6e0(0) = DAT_0105f548;' ✓✗→✓✓ prelude line 9 declares 'int* FUN_0093d6b0(int value);' used
// as '*offsets->FUN_0093d6b0(0) = offset;' ✓✗→✓✓ and a sibling body passes names as '&DAT_00e3b020' - PROOF that this corpus binds .rdata strings through address-named DAT_ externs instead of literals ✗✗→✓✓ which my
// first pass got wrong by writing plain string literals (the diff showed my pushes carrying different addresses ✓ ) 
// ONE sibling signature deliberately NOT copied: another body declares 'Flag FUN_0093d640();' returning a value type, while my body does 'call sub_93D640 ; cmp byte ptr [eax], 0' - the answer is used as an ADDRESS ✓✗→✓✓
// so it returns a byte pointer here ✗✗→✓✓ standing rule that signatures must be re-derived per entry even inside one pack ✓ 
//   sub esp,1Ch ; push esi ; mov esi,[esp+20h+arg_4]   
//     - cdecl: plain 'retn' with arguments read from ESP offsets, and the frame released explicitly by 'add esp,1Ch' at a SINGLE shared tail ✓✗→✓✓ ESI = the context object each name is resolved against; one parameter is
//     never referenced ✗✗→? 
//   three times: push offset "threadId"/"lockBitStack"/"lockCount" ; push esi ; lea ecx,[frame slot] ; call sub_93D600   
//     - slots sit at esp+0x18, +0x10 and +0x08 relative to the same frame ✓✗→✓✓ EIGHT BYTES APART ✓✗→✓✓ so each lookup object occupies eight bytes - my first pass left them one byte apart because a class with no data
//     members has size ONE ✗✗→✓✓ hence the explicit field below ✓ (and this is also why their frame needs 0x1C bytes for three objects plus a scratch byte ✓ ) 
//   lea eax,[var_19] ; push eax ; lea ecx,[slot] ; call sub_93D640 ; cmp byte ptr [eax],0 ; pop esi ; je +A1h   
//     - THREE lookups, each passed THE ADDRESS OF ONE REUSED scratch byte (var_19) ✓✗→✓✓ each answer is a pointer whose first BYTE is compared with zero by an immediate compare ✓✗→? and all three failures plus the
//     success path converge on ONE tail 'add esp,1Ch ; retn' ✗✗→✓✓ so this function has a SINGLE exit - my first pass wrote early returns and VC8 turned them into 'pop ecx ; ret' ✗✗→✓✓ corrected below ✓ 
//   push 0 ; lea ecx,[threadId slot] ; call sub_93D6B0   
//   push 0 ; lea ecx,[lockCount slot] ; mov dword ptr [eax],0FFFFFFF1h ; call sub_93D6B0   
//   push 0 ; lea ecx,[lockBitStack slot] ; mov dword ptr [eax],0 ; call sub_93D6E0 ; mov word ptr [eax],0   
//     - three setters with literal zero arguments; the returned pointers are written as MINUS FIFTEEN (dword) for threadId, ZERO (dword) for lockCount and ZERO (WORD) for lockBitStack ✓✗→✓✓ each store sits in their
//     build AFTER the next calls argument push ✗✗→? an interleaving I cannot force from source, so this remains my expected residue ✓ 

namespace f3m_00936250 {

extern const char DAT_00e3c294;                      // "threadId" at .rdata 0xE3C294 ✓✗→✓✓ bound by address-named extern because that is how this corpus references its strings - a sibling body in this very pack passes
                                                     //     '&DAT_00e3b020' where the binary pushes a string address ✗✗→✓✓ my first pass used literals and pushed MY addresses instead ✓ (measured this round ✓ ) 
extern const char DAT_00e5a49c;                      // "lockBitStack" at .rdata 0xE5A49C ✓✗→? same binding convention ✗✗→✓ 
extern const char DAT_00e5a4ac;                      // "lockCount" at .rdata 0xE5A4AC ✓✗→? 

struct Lookup936 {                                     // the packs own shape (prelude line 451) - a resolved field reference against a context object ✓✗→✓✓ 
    void* reference00;                             // v6: a SECOND data member follows, because their three slots sit EIGHT bytes apart - so the type is two dwords wide, not one ✗✗→✓✓ my previous version sized it at four and the frame reservation came out 0x10 instead of their 0x1C ✓                                  // v2: an explicit data member so this type occupies EIGHT bytes, matching their three frame slots at +8/+10h/+18h ✗✗→✓✓ a class declaring only member functions has
                                                     //     size ONE, which made my first pass pack the objects together and shift every displacement ✓ (measured this round ✓ ) 
    unsigned long nameRef04;                         // +0x04: the second dword that makes this object eight bytes wide ✓✗→? nothing in THIS body reads it directly - the constructor and members own both halves ✗✗→? declared only so the frame geometry matches their reservation of 1Ch for three objects plus one scratch byte ✓ ) 
    Lookup936(void* object, const char* name);          // prelude line 454 verbatim ✓✗→✓✓ context object plus NUL-terminated field name ✓ 
    unsigned char* FUN_0093d640(unsigned char* scratch);   // ORIG: receiver plus one pushed argument (that reused scratch byte address), answer DEREFERENCED as a byte pointer ✓✗→✓✓ re-derived here rather than copied
                                                     //     from the sibling that returns a value type ✗✗→? 
    int* FUN_0093d6b0(int value);                      // prelude line 9 ✓✗→✓✓ answer written as a DWORD: minus fifteen for one field, zero for another ✓✗→? 
    short* FUN_0093d6e0(int value);                    // prelude line 455 with sibling usage at line 466 writing through it ✓✗→✓✓ my body zeroes that answer as a WORD ('mov word ptr [eax],0' ✓ ) so the return really is
                                                     //     short-typed ✗✗→? 
};

extern "C" void FUN_00936250(void* unusedFirst, void* context);   // cdecl with caller-cleaned parameters: plain 'retn' plus an explicit frame release ✓✗→✓✓ one parameter is never read in this body ✗✗→? and no value is
                                                     //     established as a result ✓ 

void FUN_00936250(void* unusedFirst, void* context) {  // ORIG moves that second parameter into ESI right after reserving the frame ✓✗→✓✓ 
    unsigned char scratch;                             // var_19: ONE local byte whose address is passed to all three lookups ✓✗→✓✓ not three separate temporaries ✗✗→? 
    Lookup936 threadId(context, &DAT_00e3c294);        // ORIG: first construction, name bound by address ✓✗→✓✓ all three constructions precede every lookup ✗✗→✓✓ so their order is deliberate ✓ 
    Lookup936 lockBitStack(context, &DAT_00e5a49c);    // ORIG: second construction (frame slot +8) - note it is looked up SECOND but set LAST ✗✗→? the IDA slot numbers do not follow source order ✓ 
    Lookup936 lockCount(context, &DAT_00e5a4ac);       // ORIG: third construction (frame slot +0x18) ✓✗→✓✓ looked up THIRD and set SECOND ✗✗→? 

                                                     //     three conditions are written below as a single conjunction with ONE exit rather than three early returns ✗✗→✓✓ that is what keeps their 'add esp,1Ch ; retn' ✓ 

    if (*threadId.FUN_0093d640(&scratch) == 0) return;      // v5: tested IMMEDIATELY after its own lookup, as their build does (cmp byte ptr [eax],0 then je to one shared tail ✓✗→✓✓ my conjunction version deferred all three tests and forced the answers into ESI/EDI, adding a save/restore pair and two moves ✗✗→ ) 
    if (*lockBitStack.FUN_0093d640(&scratch) == 0) return;   // ORIG: second lookup then its own test against the same single tail ✓✗→✓✓ all failures converge on one exit, so three early returns in source are still ONE epilogue ✗✗→? 
    if (*lockCount.FUN_0093d640(&scratch) == 0) return;      // ORIG: third lookup then its test ✓✗→✓✓ and note they reuse EAX directly with no variable kept, which is why nothing is spilled ✗✗→? 
    {                                                        // v5: block opened to keep the setter group together under the three guards above ✓✗→? 
                                                     //     failure ✗✗→✓✓ which my early-return version destroyed ✗✗→? (measured: VC8 emitted 'pop ecx ; ret' instead of the frame release ✓ ) 
        int* threadSlot = threadId.FUN_0093d6b0(0);    // ORIG: 'push 0 ; lea ecx,[+18h slot] ; call sub_93D6B0' ✓✗→✓✓ literal zero argument, answer kept ✗✗→? 
        *threadSlot = -15;                             // ORIG: 'mov dword ptr [eax], 0FFFFFFF1h' - a signed sentinel written as a DWORD ✓✗→✓✓ their build places it after already pushing the next calls arguments ✗✗→? 
        int* countSlot = lockCount.FUN_0093d6b0(0);    // ORIG: 'push 0 ; lea ecx,[+8 slot] ; call sub_93D6B0' - same setter on the lockCount object ✓✗→✓✓ second setter executed even though it was looked up third ✗✗→? 
        *countSlot = 0;                                // ORIG: 'mov dword ptr [eax], 0' through that answer, again interleaved after the following argument setup ✗✗→? expected order residue ✓ 
        short* bitStackSlot = lockBitStack.FUN_0093d6e0(0);   // ORIG: 'push 0 ; lea ecx,[+0h slot] ; call sub_93D6E0' - a DIFFERENT setter returning a SHORT pointer, exactly as prelude line 455 declares ✓✗→✓✓ 
        *bitStackSlot = 0;                             // ORIG: 'mov word ptr [eax], 0' - TWO bytes ✗✗→✓✓ confirmed by the sibling usage at pack line 466 ✓ then both paths reach 'add esp,1Ch ; retn' ✓ 
    }                                               

}                                                    // single exit for every route, matching their one shared tail ✓✗→✓✓ (namespace terminator present - checked this time after two earlier slips ✗✗→? ) 

}                                                    // closes my namespace ✓ (verified by counting braces this time: the imbalance came from an opening brace inside one of my own comments, which is why a raw count over-reports by one ✗✗→? )

}   // namespace f3m_00936250

// @f3 0x00925740 (community match, verified in this file)
namespace f3m_00925740 {
namespace Copy925740 {
struct Vec4 {float x,y,z,w;};struct Output {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;Vec4 first,second;};
inline void copy(Vec4& out,const Vec4& in){out.x=in.x;out.y=in.y;out.z=in.z;out.w=in.w;}
struct Object {virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void release(void*);
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual Output* get(void**);
int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;Vec4 first,second;void FUN_008ff180(void*);void FUN_00925740(void*);};
// pdb: bhkRigidBodyT::SaveBinary | bhkRigidBodyT.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Object::FUN_00925740(void* value){void* handle;Output* output=get(&handle);if(output){copy(output->first,second);copy(output->second,first);}FUN_008ff180(value);release(handle);}
}
}   // namespace f3m_00925740

// @f3 0x00929bf0 (community match, verified in this file)
namespace f3m_00929bf0 {
namespace Pair929bf0 {
struct Node {int unk00;int value;int unk08;Node* parent;Node* root(){Node* p=this;while(p->parent)p=p->parent;return p;}};
struct Pair {Node* left;int a;Node* right;int b;};
struct Array {Pair* data;int size;unsigned capacity;};void FUN_00901f10(Array*,int);
struct Object {int unk00,unk04;Array array;void FUN_00929bf0(Node*,Node*);};
// pdb: hkpAllCdBodyPairCollector::addCdBodyPair | hkpAllCdBodyPairCollector.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: bodyA, bodyB
void Object::FUN_00929bf0(Node* a,Node* b){Array* v=&array;if(v->size==(v->capacity&0x3fffffff))FUN_00901f10(v,16);Pair* out=&v->data[v->size++];out->left=a->root();out->a=a->value;out->right=b->root();out->b=b->value;}
}
}   // namespace f3m_00929bf0

// @f3 0x00936eb0 (community match, verified in this file)
extern short DAT_0105f578;extern char DAT_00e3a950[],DAT_00e3ff58[],DAT_00e3a5fc[],DAT_00e3a5e8[];
namespace f3m_00936eb0 {
namespace Assign279 {
struct R2 {void FUN_009b2360();};struct R1 {R2* FUN_0093d8b0();};
struct FUN_0093d600 {void* object;int index;FUN_0093d600(void*,const char*);short* FUN_0093d6e0(int);char* FUN_0093d710(int);R1* FUN_0093d790(const char*,short*);};
static __declspec(noinline) short FUN_00936710(void* obj,const char* name){short id;FUN_0093d600 f(obj,"type");f.FUN_0093d790(name,&id)->FUN_0093d8b0()->FUN_009b2360();return id;}
static __declspec(noinline) void FUN_00936eb0(void* obj,char first,char second){if(DAT_0105f578==-1)DAT_0105f578=FUN_00936710(obj,DAT_00e3a950);{FUN_0093d600 f(obj,DAT_00e3ff58);*f.FUN_0093d6e0(0)=DAT_0105f578;}{FUN_0093d600 f(obj,DAT_00e3a5fc);*f.FUN_0093d710(0)=first;}{FUN_0093d600 f(obj,DAT_00e3a5e8);*f.FUN_0093d710(0)=second;}}
void* volatile object;volatile char a,b;void caller(){FUN_00936eb0(object,a,b);}
}
}   // namespace f3m_00936eb0

// @f3 0x00938560 (community match, verified in this file)
namespace f3m_00938560 {
namespace ns_00938560 {

struct BoolRet {
    bool value;
    BoolRet();
};

struct Src938560 {
    int unk00;
    void* klass04;
};

BoolRet __cdecl FUN_0093c0a0(void* klass, const char* name);

struct FUN_0093d7f0 {
    void* unk00;
    int unk04;
    FUN_0093d7f0(void* obj);
};

struct R2 {
    void __thiscall FUN_009b2360();
};

struct R1 {
    R2* __thiscall FUN_0093d8b0();
};

struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600(void* obj, const char* name);
    char* __thiscall FUN_0093d700(int index);
    R1* __thiscall FUN_0093d790(const char* name, short* out);
};

static __declspec(noinline) short FUN_00936710(void* obj, const char* name) {
    short id;
    FUN_0093d600 f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}

} // namespace ns_00938560

void __cdecl FUN_00938560(ns_00938560::Src938560* src, void* dst) {
    using namespace ns_00938560;
    const char* typeName;
    if (FUN_0093c0a0(src->klass04, "hkSpringDamperConstraintMotor").value) {
        typeName = "TYPE_SPRING_DAMPER";
    } else if (FUN_0093c0a0(src->klass04, "hkVelocityConstraintMotor").value) {
        typeName = "TYPE_VELOCITY";
    } else if (FUN_0093c0a0(src->klass04, "hkPositionConstraintMotor").value) {
        typeName = "TYPE_POSITION";
    } else {
        typeName = "TYPE_INVALID";
    }
    *FUN_0093d600(dst, "type").FUN_0093d700(0) = (char)FUN_00936710(&FUN_0093d7f0(dst), typeName);
}
}   // namespace f3m_00938560

// @f3 0x00935160 (community match, verified in this file)
namespace Convert462 {
struct Value {void* object;void* type;void FUN_0093d7f0(void*);void FUN_0093d7d0(void*,void*);};
struct Member {void* FUN_0093d890();};
struct Field {
 void* object;void* member;
 void FUN_0093d600(Value* value,const char* name);
 int* FUN_0093d670(int);
 void* FUN_0093d660();
 Member* FUN_0093d790();
 unsigned char* FUN_0093d710(int);
};
struct Manager {void* FUN_009227d0(int,int);};
extern Manager* DAT_011690fc;
extern const char DAT_00e51de0[],DAT_00e55c74[],DAT_00e3b4f4[],DAT_00e46148[];
void FUN_0093c0a0(unsigned char*,void*,const char*);
void FUN_00935160(void* source,void* destination) {
 Value dst;dst.FUN_0093d7f0(destination);
 Value src;src.FUN_0093d7f0(source);
 int kind;
 {Field field;field.FUN_0093d600(&src,DAT_00e51de0);kind=*field.FUN_0093d670(0);}
 if(DAT_011690fc) {
  void* type=DAT_011690fc->FUN_009227d0(kind,0);
  if(type) {
   unsigned char skip;
   FUN_0093c0a0(&skip,type,DAT_00e55c74);
   if(skip)return;
  }
  Field field;field.FUN_0093d600(&dst,DAT_00e3b4f4);
  void* object=field.FUN_0093d660();
  void* memberType=field.FUN_0093d790()->FUN_0093d890();
  Value value;value.FUN_0093d7d0(object,memberType);
  Field flag;flag.FUN_0093d600(&value,DAT_00e46148);
  *flag.FUN_0093d710(0)=255;
 }
}
}

// @f3 0x0092e920 (community match, verified in this file)
namespace Small475 {
struct Context {virtual void slot00();virtual void slot04();virtual void slot08();virtual void cleanup();};
typedef void* (__stdcall *Getter)(unsigned long);
extern Getter const DAT_00d9b080;
extern unsigned long DAT_0116913c,DAT_010f3170;
void __cdecl FUN_00944860(void*);
void __cdecl FUN_008f6f20(int);
// pdb: hkMonitorStream::quit | hkMonitorStream.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkBaseSystem::quitThread)
int __cdecl FUN_0092e920(){Getter getter=DAT_00d9b080;FUN_00944860(getter(DAT_0116913c));Context* context=(Context*)getter(DAT_010f3170);context->cleanup();FUN_008f6f20(0);return 0;}
}

// @f3 0x00936050 (community match, verified in this file)
extern char DAT_00e434c8;                             
extern char DAT_00e3ef38;                             
namespace f3m_00936050 {

















namespace f3m_00936050 {


struct NamedRef96 {                                   
    void* owner;
    char const* name;

    void FUN_0093d600(void* newOwner, char const* refName);   
    void** FUN_0093d670(int flag);                    
    void* FUN_0093d660();                             
};

struct Sink96 {                                       
    void** vtable;

    typedef void (__thiscall *BindFn)(void* self, void* generator, void* finished);   
};

void __cdecl FUN_00936050(void* generatorOwner, void* rootOwner, Sink96* sink) {   
    NamedRef96 rootReference;                          
    NamedRef96 generatorReference;                     

    rootReference.FUN_0093d600(rootOwner, &DAT_00e434c8);        
    generatorReference.FUN_0093d600(generatorOwner, &DAT_00e3ef38);   

    void* generator = *generatorReference.FUN_0093d670(0);        
    void** rootSlot = rootReference.FUN_0093d670(0);              

    *rootSlot = generator;                             

    void** table = sink->vtable; void* finished = rootReference.FUN_0093d660();     

    Sink96::BindFn bind = (Sink96::BindFn)table[5];   
    bind(sink, generator, finished);                   
}

}


}   // namespace f3m_00936050

// @f3 0x0092c3b0 (community match, verified in this file)
namespace f3m_0092c3b0 {
namespace Small551 {
struct Heap {void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;extern float DAT_00dbe1e0,DAT_00dbe8fc;
struct Vector {float x,y,z,w;};
struct Node {unsigned unk00,unk04,unk08,unk0c;Vector a,b;float scale,other;unsigned unk38,unk3c;};
struct Owner {unsigned unk00,unk04;void* source;Node* node;void FUN_0092c060(Node*);Node* FUN_0092c3b0(bool*);};
Node* Owner::FUN_0092c3b0(bool* created){if(!node){unsigned char* raw=(unsigned char*)DAT_01090a78.FUN_0086b930(sizeof(Node)+16);double scale=DAT_00dbe1e0;unsigned char low=(unsigned char)(unsigned)raw;low&=15;unsigned char padding=16;padding-=low;raw+=padding;raw[-1]=padding;Node* p=(Node*)raw;p->unk00=0;p->unk04=0;p->scale=scale;p->other=DAT_00dbe8fc;p->a.x=p->a.y=p->a.z=p->a.w=0.0f;p->b.x=p->b.y=p->b.z=p->b.w=0.0f;node=p;if(source)FUN_0092c060(p);*created=true;}else *created=false;return node;}
}

}   // namespace f3m_0092c3b0

// @f3 0x0093c130 (community match, verified in this file)
extern const char DAT_00e55c94[];
namespace f3m_0093c130 {
namespace c93c130 {
struct Node { const char* FUN_009b0490(); Node* FUN_009b04a0(); };
int __cdecl hkString_strCmp(const char* a, const char* b);
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Entry { int key; Node* node; };
struct EntryArray {
    Entry* data; int size; unsigned int capFlags;
    Entry& ExpandOne() {
        if (size == (int)(capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(Entry));
        return data[size++];
    }
    void RemoveAt(int i) { size--; data[i] = data[size]; }
};
struct World {
    int unk00; int unk04; int unk08;
    EntryArray list;
    void FUN_0093c130(EntryArray* arr);
};
void World::FUN_0093c130(EntryArray* arr)
{
    for (int i = 0; i < arr->size; ) {
        Node* n;
        for (n = arr->data[i].node; n; n = n->FUN_009b04a0()) {
            if (hkString_strCmp(n->FUN_009b0490(), DAT_00e55c94) == 0)
                break;
        }
        if (n) {
            list.ExpandOne() = arr->data[i];
            arr->RemoveAt(i);
        } else {
            i++;
        }
    }
}
}
}   // namespace f3m_0093c130

// @f3 0x00933650 (community match, verified in this file)
extern const char DAT_00e3e1c4[];
namespace f3m_00933650 {
namespace f3m_00933650 {
void __cdecl FUN_009234e0(void* destination, const void* source, int bytes);

struct Class3650 { int FUN_009b0760(); };
struct Member3650 { Class3650* FUN_0093d890(); };
struct SimpleArray3650 { char* data; int size; };
struct FUN_0093d600 {
    void* object;
    void* member;
    FUN_0093d600(void* obj, const char* name);
    SimpleArray3650* FUN_0093d660();
    Member3650* FUN_0093d790();
};

void __cdecl FUN_00933650(void* oldObj, void* newObj)
{
    FUN_0093d600 oldPalette(oldObj, DAT_00e3e1c4);
    FUN_0093d600 newPalette(newObj, DAT_00e3e1c4);
    SimpleArray3650* oldArray = oldPalette.FUN_0093d660();
    SimpleArray3650* newArray = newPalette.FUN_0093d660();
    int count = oldArray->size;
    char* source = oldArray->data;
    char* destination = newArray->data;
    int oldStride = oldPalette.FUN_0093d790()->FUN_0093d890()->FUN_009b0760();
    int newStride = newPalette.FUN_0093d790()->FUN_0093d890()->FUN_009b0760();
    for (int i = 0; i < count; i++) {
        FUN_009234e0(destination, source, newStride);
        source += oldStride;
        destination += newStride;
    }
}
}
}   // namespace f3m_00933650

// @f3 0x009376a0 (community match, verified in this file)
extern short DAT_0105f598;
extern short DAT_0105f550;
extern short DAT_0105f558;
extern const char DAT_00e39ef4[];
extern const char DAT_00e39b24[];
extern const char DAT_00e39b30[];
extern const char DAT_00e39f08[];
extern const char DAT_00e39efc[];
namespace f3m_009376a0 {
namespace f009376a0 {
struct Translation { float v[4]; };
struct Pair { int a; int b; Pair() {} };
struct QClass;
struct QSrc { int unk00; QClass* unk04; };
struct FUN_0093d7f0 {
    void* unk00;
    int unk04;
    FUN_0093d7f0(QSrc* src);
};
struct R2 { void FUN_009b2360(); };
struct R1 { R2* FUN_0093d8b0(); };
struct FUN_0093d600 {
    void* unk00;
    int unk04;
    FUN_0093d600() {}
    FUN_0093d600(void* obj, const char* name);
    short* FUN_0093d6e0(int index);
    Translation* FUN_0093d720(int index);
    R1* FUN_0093d790(const char* name, short* out);
    FUN_0093d600 FUN_0093d7a0(const char* name);
    Pair FUN_0093d810();
};
short __cdecl FUN_00936690(FUN_0093d600* acc);

static __declspec(noinline) short FUN_009366b0(FUN_0093d600* acc)
{
    return FUN_00936690(acc);
}
static __declspec(noinline) short FUN_00936710(void* obj, const char* name)
{
    short id;
    FUN_0093d600 f(obj, "type");
    f.FUN_0093d790(name, &id)->FUN_0093d8b0()->FUN_009b2360();
    return id;
}
static __declspec(noinline) void FUN_00936890(void* obj, const Translation* a, const Translation* b)
{
    void** po = &obj;
    if (DAT_0105f550 == -1)
        DAT_0105f550 = FUN_00936710(obj, "TYPE_SET_LOCAL_TRANSLATIONS");
    { FUN_0093d600 f(obj, "type"); *f.FUN_0093d6e0(0) = DAT_0105f550; }
    { FUN_0093d600 f(obj, "translationA"); *f.FUN_0093d720(0) = *a; }
    { FUN_0093d600 f(obj, "translationB"); *f.FUN_0093d720(0) = *b; }
}
static __declspec(noinline) void FUN_009369f0(void* obj)
{
    if (DAT_0105f558 == -1)
        DAT_0105f558 = FUN_00936710(obj, "TYPE_BALL_SOCKET");
    FUN_0093d600 type(obj, "type");
    *type.FUN_0093d6e0(0) = DAT_0105f558;
}

void __cdecl FUN_009376a0(QSrc* oldObj, void* newObj)
{
    FUN_0093d600 atoms(newObj, DAT_00e39ef4);
    FUN_0093d7f0 old(oldObj);
    if (DAT_0105f598 == -1)
        DAT_0105f598 = FUN_009366b0(&atoms);
    FUN_0093d600 pivotInB(&old, DAT_00e39b24);
    FUN_0093d600 pivotInA(&old, DAT_00e39b30);
    FUN_00936890(&atoms.FUN_0093d7a0(DAT_00e39f08).FUN_0093d810(), pivotInA.FUN_0093d720(0), pivotInB.FUN_0093d720(0));
    FUN_009369f0(&atoms.FUN_0093d7a0(DAT_00e39efc).FUN_0093d810());
}
}
}   // namespace f3m_009376a0

// @f3 0x00923e10 (community match, verified in this file)
namespace f3m_00923e10 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern unsigned long DAT_010f3170;
struct Mem {
    void* FUN_008f6d30(int size, int tag) throw();
    void FUN_008f6d90(void* p, int size, int tag) throw();
};

struct IntArray {
    int* data;
    int size;
    int capacityAndFlags;
    IntArray() throw() : data(0), size(0), capacityAndFlags(0x80000000) {}
    ~IntArray() throw()
    {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int n = capacityAndFlags & 0x3fffffff;
            Mem* mem = (Mem*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(data, n * 4, 0x17);
        }
    }
};

struct Pos { const char* unk00; int unk04; };
struct Str { char* data; int size; int capacity; };

void __cdecl FUN_009235a0(int* count, const char* text, const char* from, IntArray* hits, int max) throw();
void __cdecl FUN_00923ae0(char* out, const char* text, int len, const Pos* a, const Pos* b, IntArray* hits) throw();
void __cdecl FUN_009234e0(char* out, const char* text, int len) throw();

struct Text {
    const char* unk00;
    int unk04;
    Str FUN_00923e10(const Pos* a, const Pos* b, int n);
};

Str Text::FUN_00923e10(const Pos* a, const Pos* b, int n)
{
    IntArray hits;
    FUN_009235a0(&n, unk00, a->unk00, &hits, n);
    int len = (b->unk04 - a->unk04) * hits.size + unk04;
    Mem* mem = (Mem*)TlsGetValue(DAT_010f3170);
    char* buf = (char*)mem->FUN_008f6d30(len, 0x16);
    if (hits.size)
        FUN_00923ae0(buf, unk00, unk04 - 1, a, b, &hits);
    else
        FUN_009234e0(buf, unk00, unk04 - 1);
    buf[len - 1] = 0;
    Str r;
    r.data = buf;
    r.size = len;
    r.capacity = len;
    return r;
}

}

// @f3 0x0093c7d0 (community match, verified in this file)
namespace f3m_0093c7d0 {
namespace Resolve360 {
struct Resolver{void* FUN_009b0490();};
struct Variant{void* object;Resolver* klass;};
struct Entry{int unk00;void* className;Variant variant;void* getTypeName(){return variant.klass?variant.klass->FUN_009b0490():className;}};
struct Table{Variant* data;int size;Resolver* find(void* obj){for(int i=0;i<size;++i)if(data[i].object==obj)return data[i].klass;return 0;}};
struct Array{Entry* data;int size;};
void FUN_0093c7d0(Array* entries,Table* table){
    Array* list=*(Array* volatile*)&entries;
    for(int i=0;i<list->size;++i){
        Entry& e=list->data[i];
        if(e.getTypeName()==0){
            Variant v;
            v.klass=table->find(e.variant.object);
            v.object=e.variant.object;
            e.variant=v;
            e.className=v.klass?v.klass->FUN_009b0490():0;
            e.variant.klass=0;
        }
    }
}
}
}   // namespace f3m_0093c7d0

// @f3 0x00924b40 (community match, verified in this file)
namespace f3m_00924b40 {
namespace S00924b40_ns {

struct OutMat {
    float m[12];
    void hkRotation_set(const float* q);
};

// pdb: hkRotation::set | hkRotation.obj | fnv360_0822_retail, call_seq + bridge(call_dedup|call_seq) + skyrim(call_seq), high
void OutMat::hkRotation_set(const float* q)
{
    float x2 = q[0] + q[0];
    float y2 = q[1] + q[1];
    float z2 = q[2] + q[2];

    float xx = q[0] * x2;
    float xy = q[0] * y2;
    float xz = q[0] * z2;
    float yy = q[1] * y2;
    float yz = q[1] * z2;
    float zz = q[2] * z2;
    float wx = q[3] * x2;
    float wy = q[3] * y2;
    float wz = q[3] * z2;

    m[0]  = 1.0f - (yy + zz);
    m[1]  = xy + wz;
    m[2]  = xz - wy;
    m[3]  = 0.0f;
    m[4]  = xy - wz;
    m[5]  = 1.0f - (xx + zz);
    m[6]  = yz + wx;
    m[7]  = 0.0f;
    m[8]  = xz + wy;
    m[9]  = yz - wx;
    m[10] = 1.0f - (xx + yy);
    m[11] = 0.0f;
}

}
}   // namespace f3m_00924b40

// @f3 0x00922230 (community match, verified in this file)
namespace f3m_00922230 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

extern int DAT_010f3170;
extern float DAT_00db38b8;

struct ObjectState_00922230;

struct TlsState_00922230 {
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
    ObjectState_00922230* FUN_008f6800(int index,int tag);
};

struct Slot1005 { int v; Slot1005():v(0){} };
struct ObjectState_00922230 {
    Slot1005 unk00,unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    int unk20;
    int unk24;
    float unk28;
    float unk2C;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char unk34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3A;
    unsigned char unk3B;
    unsigned char unk3C;
    unsigned char unk3D;
    unsigned char unk3E;
    unsigned char unk3F;
    int unk40;
    float unk44;
    static void* operator new(unsigned int) throw();
    __forceinline ObjectState_00922230() {
            unk10 = 1.0f;
            unk14 = 1.0f;
            unk20 = 2;
            unk18 = 1.0f;
            unk24 = 2;
            unk1C = 0.0f;
            unk28 = 0.0f;
            unk2C = DAT_00db38b8;
            unk30 = 0;
            unk40 = 0;
            unk44 = 0.0f;
    }
};

void* ObjectState_00922230::operator new(unsigned int) throw() {
 TlsState_00922230* tls=(TlsState_00922230*)DAT_00d9b080((unsigned long)DAT_010f3170);
 ObjectState_00922230* state;
 if(tls->unk68) { --tls->unk6C;state=(ObjectState_00922230*)tls->unk68;tls->unk68=state->unk00.v; }
 else state=tls->FUN_008f6800(6,2);
 return state;
}

class FUN_00922230_Obj {
public:
    int unk00;
    int unk04;
    int unk08;
    ObjectState_00922230* unk0C;

    void FUN_00921ba0(ObjectState_00922230* state);

    ObjectState_00922230* FUN_00922230(unsigned char* result);
};

// pdb: bhkTriSampledHeightFieldBvTreeShape::CreateCinfo | bhkTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCreated
ObjectState_00922230* FUN_00922230_Obj::FUN_00922230(unsigned char* result)
{
    if (unk0C == 0) {
        ObjectState_00922230* state=new ObjectState_00922230;

        unk0C = state;
        if (unk08 != 0)
            FUN_00921ba0(state);
        *result = 1;
        return unk0C;
    }

    *result = 0;
    return unk0C;
}

}

// @f3 0x00931b30 (community match, verified in this file)
extern void* const DAT_00e333b4;
namespace f3m_00931b30 {

namespace f3_00931b30 {
struct Obj {
    const void* vftable;
    void FUN_0090e490();
    void FUN_00931b30();
};

// pdb: bhkCollisionBox::~bhkCollisionBox | bhkCollisionBox.obj | fnv360_0822_retail, objrun_open, low
void Obj::FUN_00931b30() {
    vftable = &DAT_00e333b4;
    FUN_0090e490();
}
}
}   // namespace f3m_00931b30

// @f3 0x0092edd0 (community match, verified in this file)
namespace f3m_0092edd0 {

extern unsigned long DAT_010f3170;

struct Alloc {
    void* FUN_008f6d30(int size, int tag) throw();
    void FUN_008f6d90(void* p, int size, int tag) throw();
};

__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long) throw();

struct hkBool {
    char m_bool;
    hkBool();
    operator bool() const { return m_bool != 0; }
};

template <class T>
struct Array {
    T* data;
    int size;
    int capAndFlags;
    Array() throw() : data(0), size(0), capAndFlags(0x80000000) {}
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};

struct StreamReader {
    virtual ~StreamReader() throw();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual hkBool isOk() const throw();
    unsigned short memSize;
    short refCount;

    static void* operator new(unsigned int n) throw() {
        Alloc* a = FUN_00d9b080(DAT_010f3170);
        void* p = a->FUN_008f6d30(n, 0x1a);
        ((StreamReader*)p)->memSize = (unsigned short)n;
        return p;
    }
    static void operator delete(void*) throw() {}

    void removeReference() throw() {
        if (memSize != 0) {
            if (--refCount == 0)
                delete this;
        }
    }
};

struct FUN_009af500 : StreamReader {
    int f08, f0c, f10;
    FUN_009af500(void* handle) throw();
};

struct FUN_009af3c0 : StreamReader {
    int f08, f0c, f10, f14, f18, f1c, f20;
    FUN_009af3c0(StreamReader* inner, int bufSize) throw();
};

extern void* (__cdecl* DAT_010611a0)(const char*, Array<char>&) throw();

// pdb: hkNativeFileSystem::openReader | hkBaseSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: name
StreamReader* __stdcall FUN_0092edd0(const char* name) throw()
{
    Array<char> buf;
    StreamReader* reader = new FUN_009af500(DAT_010611a0(name, buf));
    if (!reader->isOk()) {
        StreamReader* buffered = new FUN_009af3c0(reader, 0x1000);
        reader->removeReference();
        return buffered;
    }
    return reader;
}

} // namespace f3m_0092edd0

// @f3 0x0092dd70 (community match, verified in this file)
extern const void* DAT_00e13150;
namespace f3m_0092dd70 {
namespace f3_0092dd70 {
struct Obj {
    const void* vftable;
    void FUN_005715d0();
    void FUN_0092dd70();
};

// pdb: bhkFilteredCdBodyCollector::~bhkFilteredCdBodyCollector | bhkFilteredCdBodyCollector.obj | fnv360_0822_retail, call_gap_sim, low
void Obj::FUN_0092dd70() {
    vftable = &DAT_00e13150;
    FUN_005715d0();
}
}
}   // namespace f3m_0092dd70

// @f3 0x00932840 (community match, verified in this file)
extern const char str_00e49da8[],str_00e3cbfc[],str_00e3f18c[],str_00e49d88[],str_00e46d58[],str_00e3cbe0[],str_00e3e0f8[],str_00e3e570[],str_00e3cd00[],str_00e3e55c[],str_00e3cd90[],str_00e3cd78[],str_00e3cd64[],str_00e3ccf4[];
namespace f3m_00932840 {
namespace character_hand_event_versioning {
struct hkClass;struct hkClassMember;
struct hkVariant { void* object;const hkClass* type; };
struct FUN_0093d600 {
 void* object;const hkClassMember* member;
 FUN_0093d600(const hkVariant&,const char*);
 FUN_0093d600 FUN_0093d7a0(const char*) const;
 int* FUN_0093d6b0(int);
 short* FUN_0093d6e0(int);
 void* FUN_0093d660();
};
void FUN_00932840(const hkVariant& source,const hkVariant& destination)
{
 {
  FUN_0093d600 a(source,str_00e49da8);
  FUN_0093d600 b(destination,str_00e3cbfc);
  FUN_0093d600 c=a.FUN_0093d7a0(str_00e3f18c);
  *b.FUN_0093d6b0(0)=*c.FUN_0093d6b0(0);
 }
 {
  FUN_0093d600 b(source,str_00e49d88);
  FUN_0093d600 a(destination,str_00e46d58);
  *a.FUN_0093d6e0(0)=*b.FUN_0093d6e0(0);
 }
 {
  FUN_0093d600 b(source,str_00e3cbe0);
  FUN_0093d600 a(destination,str_00e3cbe0);
  *a.FUN_0093d6e0(0)=*b.FUN_0093d6e0(0);
 }
 {
  FUN_0093d600 b(source,str_00e3e0f8);
  FUN_0093d600 a(destination,str_00e3e0f8);
  *a.FUN_0093d6e0(0)=*b.FUN_0093d6e0(0);
 }
 {
 FUN_0093d600 indexAcc(source,str_00e3e570);
 const short* indices=static_cast<const short*>(indexAcc.FUN_0093d660());
  FUN_0093d600 lhand(destination,str_00e3cd00);
  FUN_0093d600 lindex=lhand.FUN_0093d7a0(str_00e3e570);
  FUN_0093d600 ltrack=lhand.FUN_0093d7a0(str_00e3e55c);
  FUN_0093d600 lanim=lhand.FUN_0093d7a0(str_00e3cd90);
  FUN_0093d600 lrag=lhand.FUN_0093d7a0(str_00e3cd78);
  FUN_0093d600 lankle=lhand.FUN_0093d7a0(str_00e3cd64);
  short* lvalue=ltrack.FUN_0093d6e0(0);
  *lvalue=indices[0];*lindex.FUN_0093d6e0(0)=*lvalue;
  *lankle.FUN_0093d6e0(0)=-1;*lrag.FUN_0093d6e0(0)=-1;*lanim.FUN_0093d6e0(0)=-1;
  FUN_0093d600 rhand(destination,str_00e3ccf4);
  FUN_0093d600 rindex=rhand.FUN_0093d7a0(str_00e3e570);
  FUN_0093d600 rtrack=rhand.FUN_0093d7a0(str_00e3e55c);
  FUN_0093d600 ranim=rhand.FUN_0093d7a0(str_00e3cd90);
  FUN_0093d600 rrag=rhand.FUN_0093d7a0(str_00e3cd78);
  FUN_0093d600 rankle=rhand.FUN_0093d7a0(str_00e3cd64);
  short* rvalue=rtrack.FUN_0093d6e0(0);
  *rvalue=indices[1];*rindex.FUN_0093d6e0(0)=*rvalue;
  *rankle.FUN_0093d6e0(0)=-1;*rrag.FUN_0093d6e0(0)=-1;*ranim.FUN_0093d6e0(0)=-1;
 }
}
}
}   // namespace f3m_00932840

// @f3 0x0093e980 (community match, verified in this file)
namespace f3m_0093e980 {
namespace f3m_0093e980 {

struct ByteBuffer { char* data; int size; unsigned int capacityAndFlags; };
void __cdecl FUN_00901e90(ByteBuffer* buffer, int capacity, int stride);
int __cdecl FUN_009233f0(const char* text);
void __cdecl FUN_009234e0(void* destination, const void* source, int bytes);

struct Item93e980 {
    int unk00;
    const char* name;
    int unk08;
};
Item93e980* __cdecl FUN_0093d880(int index);

struct String93e980 {
    char* data;
    int size;
    unsigned int capacityAndFlags;

    void FUN_00923890(const char* text);

    __forceinline void Reserve(int required)
    {
        int capacity = (int)(capacityAndFlags & 0x3fffffffu);
        if (capacity < required)
        {
            int newCapacity = capacity * 2;
            if (required >= newCapacity)
                newCapacity = required;
            FUN_00901e90((ByteBuffer*)this, newCapacity, 1);
        }
    }

    __forceinline void Clear()
    {
        Reserve(1);
        size = 1;
        data[0] = 0;
    }

    __forceinline void Set(const char* text)
    {
        int length = FUN_009233f0(text);
        Reserve(length + 1);
        size = length + 1;
        FUN_009234e0(data, text, length + 1);
    }
};

struct Args93e980 {
    int type;
    int arg2;
};

static __declspec(noinline) void FUN_0093e980(String93e980* self, Args93e980 args)
{
    int capacity = (int)(self->capacityAndFlags & 0x3fffffffu);
    int type = *(volatile int*)&args.type;
    if (capacity < 1)
    {
        int newCapacity = capacity * 2;
        if (1 >= newCapacity)
            newCapacity = 1;
        FUN_00901e90((ByteBuffer*)self, newCapacity, 1);
    }
    self->size = 1;
    self->data[0] = 0;

    if ((type >= 1 && type <= 0x12) || type == 0x1e)
    {
        if (type == 1 || (unsigned int)(type - 0xc) <= 6)
            self->Set("_");
        self->FUN_00923890(FUN_0093d880(type)->name);
    }
    else if (type == 0x18 || type == 0x1f)
    {
        const char* name = FUN_0093d880(args.arg2)->name;
        if (name != 0 && *name != 0)
            self->Set(name);
        else
            self->Clear();
    }
}

String93e980* volatile g_self_93e980;
Args93e980 g_args_93e980;
void caller_of_FUN_0093e980() { FUN_0093e980(g_self_93e980, g_args_93e980); }

}
}   // namespace f3m_0093e980

// @f3 0x0092e990 (community match, verified in this file)
namespace f3m_0092e990 {

struct Node;

struct Node {
    int (*m_init)();
    Node* m_next;
    int* m_status;
};

struct hkThreadMemory { void FUN_008f6d90(void* p, int size, int cls) throw(); };

extern unsigned long DAT_010f3170;
extern void* (__stdcall* const _DAT_00fdf044)(unsigned long);
void __cdecl FUN_00901f10(void* array, int elemSize) throw();

template <class T> struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline hkArray() throw() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline ~hkArray() throw()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int n = m_capacityAndFlags & 0x3fffffff;
            hkThreadMemory* mem = (hkThreadMemory*)_DAT_00fdf044(DAT_010f3170);
            mem->FUN_008f6d90(m_data, n * sizeof(T), 0x17);
        }
    }
    __forceinline void pushBack(T t)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = t;
        m_size++;
    }
};

extern Node* DAT_0116932c;

// pdb: hkBaseSystem::initSingletons | hkBaseSystem.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_gap) + skyrim(objrun), high
void __cdecl hkBaseSystem_initSingletons() throw()
{
    Node** link = &DAT_0116932c;
    hkArray<Node*> failed;
    Node* node = *link;
    while (node != 0) {
        if (*node->m_status == 0) {
            int r = node->m_init();
            if (r != 0) {
                *node->m_status = r;
            } else {
                failed.pushBack(node);
                node = node->m_next;
                (*link)->m_next = 0;
                *link = node;
                continue;
            }
        }
        link = &node->m_next;
        node = *link;
    }
    while (failed.m_size != 0) {
        for (int i = failed.m_size - 1; i >= 0; --i) {
            Node* entry = failed.m_data[i];
            int r = entry->m_init();
            if (r != 0) {
                *entry->m_status = r;
                *link = entry;
                link = &entry->m_next;
                failed.m_data[i] = failed.m_data[--failed.m_size];
            }
        }
    }
}
}

// @f3 0x0092a1a0 (community match, verified in this file)
namespace f3m_0092a1a0 {
namespace n92a1a0 {
struct Vector4
{
    float x, y, z, w;
    Vector4& operator=(const Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};
struct VectorArray
{
    Vector4* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getCapacity() const
    {
        return m_capacityAndFlags & 0x3fffffff;
    }
    void clear()
    {
        m_size = 0;
    }
    void reserve(int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90((ByteBuffer*)this, newSize, sizeof(Vector4));
        }
    }
    void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    Vector4& operator[](int i)
    {
        return m_data[i];
    }
};
struct ShapeInfo
{
    int unk00;
    VectorArray m_spheres;
};
struct SphereData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_numSpheres;
    int unk14;
    int unk18;
    int unk1c;
    Vector4 m_spheres;
    const Vector4* getSpheres() const { return &m_spheres; }
    int getNumSpheres() const { return m_numSpheres; }
};
struct MultiSphere
{
    int unk00;
    int unk04;
    SphereData* m_shape;
    void FUN_008f75b0(ShapeInfo* info);
    int getNumSpheres() const
    {
        return (this && m_shape) ? m_shape->getNumSpheres() : 0;
    }
    const Vector4* getSpheres() const
    {
        return (this && m_shape) ? m_shape->getSpheres() : 0;
    }
    void FUN_0092a1a0(ShapeInfo* info);
};
}
// pdb: bhkMultiSphereShape::CopyCinfo | bhkMultiSphereShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arInfo
void n92a1a0::MultiSphere::FUN_0092a1a0(ShapeInfo* info)
{
    FUN_008f75b0(info);
    int count = getNumSpheres();
    info->m_spheres.clear();
    info->m_spheres.setSize(count);
    const Vector4* spheres = getSpheres();
    for (int i = 0; i < count; i++)
        info->m_spheres[i] = spheres[i];
}
}   // namespace f3m_0092a1a0

// @f3 0x00927940 (community match, verified in this file)
namespace f3m_00927940 {
namespace n927940 {
void __cdecl FUN_00901e90(void* arr, int n, int elemSize);
void __cdecl FUN_00901f10(void* arr, int elemSize);

template <class T> struct hkArray {
    T* data; int size; unsigned int capFlags;
    int getCapacity() const { return capFlags & 0x3fffffff; }
    void reserve(int n) {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    void setSize(int n) { reserve(n); size = n; }
    void pushBack(const T& t) {
        if (size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        data[size] = t;
        size++;
    }
};

struct hkBool { char b; hkBool(bool v) { b = v; } operator bool() const { return b != 0; } };
struct Island;
struct Constraint { char pad[8]; Island* island; };
struct ConstraintInternal { Constraint* constraint; char pad[0x2c]; };
struct Entity {
    char pad0[0x94]; unsigned short storageIndex; char pad96[2];
    ConstraintInternal* constraints; unsigned short numConstraints; char pad9e[0x1a];
    Island* island;
};
struct Action { char pad[0xc]; Island* island; };
struct Bits25 { unsigned char a : 2; unsigned char b : 2; unsigned char c : 2; };
struct Bits26 { unsigned char act : 2; unsigned char state : 2; };
struct Island {
    virtual ~Island();
    char pad4[0x18];
    int f1c;
    unsigned short storageIndex;
    unsigned short dirtyIndex;
    char pad24;
    union { unsigned char raw25; Bits25 bits25; };
    union { unsigned char raw26; Bits26 bits26; };
    char pad27[0x11];
    hkArray<Action*> actions;
    char pad44[4];
    hkArray<Entity*> entities;
    char pad54[4];
    char f58[4];
    void hkpSimulationIsland_markForWrite();
    void FUN_0098ae70(Island* other);
};
struct World {
    char pad0[0x28];
    hkArray<Island*> active;
    hkArray<Island*> inactive;
    hkArray<Island*> dirty;
    char pad4c[0x34];
    int f80;
    int lockCount;
    char pad88[4];
    char f8c;
    void hkpWorld_lockForIslandSplit(Island* island);
    void hkpWorld_unlockForIslandSplit(Island* island);
    void FUN_00902550();
};
void __cdecl FUN_00926c70(World* world, Island* island);
void __cdecl FUN_009994c0(void* a, void* b);
void __cdecl FUN_00926680(World* world, Island* island);

// pdb: hkpWorldOperationUtil::internalMergeTwoIslands | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_gap) + skyrim(call_seq), high
Island* __cdecl hkpWorldOperationUtil_internalMergeTwoIslands(World* world, Island* a, Island* b)
{
    if (a->entities.size <= b->entities.size &&
        (a->entities.size < b->entities.size || a->storageIndex > b->storageIndex))
    {
        Island* t = a; a = b; b = t;
    }
    world->lockCount++;
    bool active = a->bits26.act || b->bits26.act;
    hkBool state = a->bits26.state || b->bits26.state;
    if (active)
    {
        if (a->bits26.act == 0)
        {
            a->raw26 = (a->raw26 & ~8) | 4;
            FUN_00926c70(world, a);
        }
        else if (b->bits26.act == 0)
        {
            b->raw26 = (b->raw26 & ~8) | 4;
            FUN_00926c70(world, b);
        }
    }
    a->raw25 |= b->raw25 & 0xc;
    world->hkpWorld_lockForIslandSplit(a);
    b->hkpSimulationIsland_markForWrite();
    FUN_009994c0(a->f58, b->f58);
    world->hkpWorld_unlockForIslandSplit(a);

    {
        int oldSize = a->entities.size;
        int newSize = b->entities.size + oldSize;
        unsigned short idx = (unsigned short)oldSize;
        a->entities.setSize(newSize);
        for (int i = 0; i < b->entities.size; i++)
        {
            a->entities.data[idx] = b->entities.data[i];
            b->entities.data[i]->island = a;
            b->entities.data[i]->storageIndex = idx;
            idx++;
        }
    }
    {
        int n = a->actions.size;
        a->actions.setSize(b->actions.size + n);
        for (int i = 0; i < b->actions.size; i++)
        {
            if (b->actions.data[i])
            {
                a->actions.data[n] = b->actions.data[i];
                a->actions.data[n]->island = a;
                n++;
            }
        }
        a->actions.setSize(n);
    }
    for (int i = 0; i < b->entities.size; i++)
    {
        Entity* e = b->entities.data[i];
        ConstraintInternal* c = e->constraints;
        int k = e->numConstraints;
        while (--k >= 0)
        {
            c->constraint->island = a;
            c++;
        }
    }
    a->FUN_0098ae70(b);
    a->f1c += b->f1c;
    b->f1c = 0;
    {
        hkArray<Island*>* arr;
        unsigned short idx;
        if (b->bits26.act) { arr=&world->active; idx=b->storageIndex; }
        else { arr=&world->inactive; idx=b->storageIndex; }
        if (idx < arr->size - 1)
        {
            arr->data[idx] = arr->data[arr->size - 1];
            arr->data[idx]->storageIndex = idx;
        }
        arr->size--;
    }
    a->bits25.a = a->bits25.a || b->bits25.a;
    a->bits25.c = a->bits25.c || b->bits25.c;
    a->bits26.state = state;
    if (b->dirtyIndex != 0xffff && a->dirtyIndex == 0xffff)
    {
        a->dirtyIndex = (unsigned short)world->dirty.size;
        world->dirty.pushBack(a);
    }
    FUN_00926680(world, b);
    delete b;
    if (a->bits26.act)
    {
        int idx = a->storageIndex;
        if (idx != 0)
        {
            Island* first = world->active.data[0];
            if (a->entities.size > first->entities.size)
            {
                a->storageIndex = 0;
                first->storageIndex = (unsigned short)idx;
                world->active.data[0] = a;
                world->active.data[idx] = first;
            }
        }
    }
    if (--world->lockCount == 0 && !world->f8c && world->f80)
        world->FUN_00902550();
    return a;
}
}
}   // namespace f3m_00927940

// @f3 0x0092e650 (community match, verified in this file)
namespace w92e650 {
extern int DAT_010f3170;
struct Mem {
    void* FUN_008f6d30(int bytes, int tag);
    void FUN_008f6d90(void* p, int bytes, int tag);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
inline Mem* FUN_00d9b080(int i){ return (Mem*)TlsGetValue(i); }
struct Key { int id; };
template <class T> struct Array {
    T* data;
    int size;
    unsigned int capFlags;
    __forceinline void Assign(const Array& o)
    {
        int cap = capFlags & 0x3fffffff;
        if (cap < o.size) {
            if (!(capFlags & 0x80000000)) {
                Mem* m = FUN_00d9b080(DAT_010f3170);
                m->FUN_008f6d90(data, cap * sizeof(T), 0x17);
            }
            Mem* m = FUN_00d9b080(DAT_010f3170);
            data = (T*)m->FUN_008f6d30(o.size * sizeof(T), 0x17);
            capFlags = (capFlags & 0x40000000) | o.size;
        }
        int n = o.size;
        size = n;
        T* d = data;
        T* s = o.data;
        for (int i = 0; i < n; i++)
            d[i] = s[i];
    }
};
struct EntityArray {
    Key** data;
    int size;
    Key*& operator[](int i) const { return data[i]; }
    int getSize() const { return size; }
};
class FUN_0092e340 {
public:
    virtual ~FUN_0092e340();
    unsigned short memSize;
    short refCount;
    int unk08, unk0c;
    int unk10;
    int unk14, unk18, unk1c;
    float f[12];
    int unk50;
    Array<int> arr;
    FUN_0092e340(Key* rb) throw();
    static void* operator new(unsigned int bytes)
    {
        Mem* m = FUN_00d9b080(DAT_010f3170);
        FUN_0092e340* p = (FUN_0092e340*)m->FUN_008f6d30(bytes, 0x29);
        p->memSize = (unsigned short)bytes;
        return p;
    }
    static void operator delete(void* p, unsigned int bytes)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, bytes, 0x29);
    }
};
class Obj : public FUN_0092e340 {
public:
    FUN_0092e340* hkpMouseSpringAction_clone(const EntityArray& a, const EntityArray& b) const;
};

// pdb: hkpMouseSpringAction::clone | hkpMouseSpringAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
FUN_0092e340* Obj::hkpMouseSpringAction_clone(const EntityArray& a, const EntityArray& b) const
{
    if (a.getSize() != 1)
        return 0;
    if (b.getSize() != 0)
        return 0;
    FUN_0092e340* n = new FUN_0092e340(a[0]);
    n->f[0] = f[0];
    n->f[1] = f[1];
    n->f[2] = f[2];
    n->f[3] = f[3];
    n->f[4] = f[4];
    n->f[5] = f[5];
    n->f[6] = f[6];
    n->f[7] = f[7];
    n->f[8] = f[8];
    n->f[9] = f[9];
    n->f[10] = f[10];
    n->f[11] = f[11];
    n->unk10 = unk10;
    n->unk50 = unk50;
    n->arr.Assign(arr);
    return n;
}
}

// @f3 0x00930430 (community match, verified in this file)
namespace f3m_00930430 {
// 0x00930430: keeps a contact point in a fixed-size buffer of the nearest ones
// (hkpFixedBufferCdPointCollector::addCdPointImplementation in Havok terms): while there is room the point is
// appended; once the buffer is full it replaces the farthest stored point if it is nearer than that one. This
// build also records the shape keys of body B and of its two enclosing bodies.

namespace f3m_00930430 {

typedef float hkReal;
typedef unsigned int hkpShapeKey;

static const hkpShapeKey HK_INVALID_SHAPE_KEY = 0xffffffff;

class __declspec(align(16)) hkVector4
{
public:
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

// position, and the separating normal with the distance in its fourth component
class hkContactPoint
{
public:
    __forceinline hkReal getDistance() const { return m_separatingNormal(3); }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

class hkpCollidable;

struct hkpCdBody
{
    __forceinline hkpShapeKey getShapeKey() const { return m_shapeKey; }
    __forceinline const hkpCdBody* getParent() const { return m_parent; }
    __forceinline const hkpCollidable* getRootCollidable() const
    {
        const hkpCdBody* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return reinterpret_cast<const hkpCollidable*>(body);
    }

    const void* m_shape;
    hkpShapeKey m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCdPoint
{
    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

// a contact point with the root collidables it lies between
struct hkpRootCdPoint
{
    hkContactPoint m_contact;
    const hkpCollidable* m_rootCollidableA;
    hkpShapeKey m_shapeKeyA;
    const hkpCollidable* m_rootCollidableB;
    hkpShapeKey m_shapeKeyB;
    hkpShapeKey m_shapeKeysB[3];        // the keys of body B and of the bodies around it, innermost first
};

class hkpFixedBufferCdPointCollector
{
public:
    static void __cdecl FUN_00930430(const hkpCdPoint& event, hkpFixedBufferCdPointCollector* collector);

    void* m_vtable;
    hkReal m_earlyOutDistance;
    hkpRootCdPoint* m_pointsArrayBase;
    hkpRootCdPoint* m_nextFreePoint;
    int m_capacity;
    int m_numPoints;
};

// pdb: hkpFixedBufferCdPointCollector::addCdPointImplementation | hkpFixedBufferCdPointCollector.obj | fnv360_0822_retail, objrun_open, low
// pdb params: event, collector
void __cdecl hkpFixedBufferCdPointCollector::FUN_00930430(const hkpCdPoint& event, hkpFixedBufferCdPointCollector* collector)
{
    hkpRootCdPoint* insertHere;

    if (collector->m_numPoints < collector->m_capacity)
    {
        insertHere = collector->m_nextFreePoint;
        collector->m_numPoints++;
        collector->m_nextFreePoint++;
    }
    else
    {
        // full: the point takes the place of the farthest one, if it is nearer
        hkpRootCdPoint* base = collector->m_pointsArrayBase;
        hkpRootCdPoint* p = base + 1;
        hkpRootCdPoint* worst = base;
        for (int i = 1; i < collector->m_numPoints; i++)
        {
            if (p->m_contact.getDistance() > worst->m_contact.getDistance())
            {
                worst = p;
            }
            p++;
        }

        if (!(event.m_contact.getDistance() < worst->m_contact.getDistance()))
        {
            return;
        }
        insertHere = worst;
    }

    insertHere->m_contact = event.m_contact;
    insertHere->m_rootCollidableA = event.m_cdBodyA.getRootCollidable();
    insertHere->m_rootCollidableB = event.m_cdBodyB.getRootCollidable();
    insertHere->m_shapeKeyA = event.m_cdBodyA.getShapeKey();
    insertHere->m_shapeKeyB = event.m_cdBodyB.getShapeKey();

    // the keys on the way up from body B
    const hkpCdBody* body = &event.m_cdBodyB;
    for (int i = 0; i < 3; i++)
    {
        insertHere->m_shapeKeysB[i] = body ? body->getShapeKey() : HK_INVALID_SHAPE_KEY;
        body = body ? body->getParent() : 0;
    }

    if (event.m_contact.getDistance() < collector->m_earlyOutDistance)
    {
        collector->m_earlyOutDistance = event.m_contact.getDistance();
    }
}

}
}   // namespace f3m_00930430

// @f3 0x00933810 (community match, verified in this file)
namespace f3m_00933810 {
namespace HavokNamedVariantCopy {

extern const char DAT_00e3b510[];   // "namedVariants"

struct hkClass {
    int FUN_009b0760() const;   // getObjectSize
};

struct hkVariant {
    void* m_object;
    const hkClass* m_class;
};

struct ClassVariant {
    void* m_object;
    const hkClass* m_class;
    ClassVariant();
};

struct ArrayView {
    char* data;
    int count;
};

// accessor for one named member of an object
struct MemberAccessor {
    void* object;
    const char* name;
    MemberAccessor(void* obj, const char* memberName);
    bool* FUN_0093d640(bool* isOk);
    ArrayView* FUN_0093d760(int index);
    ClassVariant FUN_0093d810();
};

void __cdecl FUN_00933760(hkVariant* from, hkVariant* to, void* context);

void __cdecl FUN_00933810(void* oldObject, void* newObject, void* context)
{
    MemberAccessor to(newObject, DAT_00e3b510);
    MemberAccessor from(oldObject, DAT_00e3b510);
    bool isOk;
    if (!*to.FUN_0093d640(&isOk))
        return;
    if (!*from.FUN_0093d640(&isOk))
        return;
    ArrayView* toArray = to.FUN_0093d760(0);
    ArrayView* fromArray = from.FUN_0093d760(0);
    for (int i = 0; i < toArray->count; i++) {
        const hkClass* fromClass = from.FUN_0093d810().m_class;
        char* fromItem = fromArray->data + fromClass->FUN_009b0760() * i;
        const hkClass* toClass = to.FUN_0093d810().m_class;
        char* toItem = toArray->data + toClass->FUN_009b0760() * i;
        hkVariant toVariant;
        toVariant.m_object = toItem;
        toVariant.m_class = toClass;
        hkVariant fromVariant;
        fromVariant.m_object = fromItem;
        fromVariant.m_class = fromClass;
        FUN_00933760(&fromVariant, &toVariant, context);
    }
}

}
}   // namespace f3m_00933810

// @f3 0x00937140 (community match, verified in this file)
extern short g_typeIdx_105f584;
namespace f3m_00937140 {
// candidate for FUN_00937140 (Havok XML: hkConeLimitData member block builder)
struct D871A0Array { int bitOffset; void* data; };
struct D871A0Buffer {
  int a; void* b;
  void FUN_0093d600(const D871A0Array& arr, const char* name);
  char* FUN_0093d6e0(int i);
  char* FUN_0093d710(int i);
  float* FUN_0093d6a0(int i);
};
static __declspec(noinline) short FUN_00936710(const D871A0Array& arr, const char* enumName);
static __declspec(noinline) void FUN_00937140(const D871A0Array& arr, bool isEnabled, bool twistAxisInA,
    bool refAxisInB, bool angleMeasurementMode, float minAngle, float maxAngle, float angularLimitsTauFactor) {
  if (g_typeIdx_105f584 == -1)
    g_typeIdx_105f584 = FUN_00936710(arr, "TYPE_CONE_LIMIT");
  D871A0Buffer buf;
  buf.FUN_0093d600(arr, "type");
  *(short*)buf.FUN_0093d6e0(0) = g_typeIdx_105f584;
  buf.FUN_0093d600(arr, "isEnabled");
  *(char*)buf.FUN_0093d710(0) = isEnabled;
  buf.FUN_0093d600(arr, "twistAxisInA");
  *(char*)buf.FUN_0093d710(0) = twistAxisInA;
  buf.FUN_0093d600(arr, "refAxisInB");
  *(char*)buf.FUN_0093d710(0) = refAxisInB;
  buf.FUN_0093d600(arr, "angleMeasurementMode");
  *(char*)buf.FUN_0093d710(0) = angleMeasurementMode;
  buf.FUN_0093d600(arr, "minAngle");
  *(float*)buf.FUN_0093d6a0(0) = minAngle;
  buf.FUN_0093d600(arr, "maxAngle");
  *(float*)buf.FUN_0093d6a0(0) = maxAngle;
  buf.FUN_0093d600(arr, "angularLimitsTauFactor");
  *(float*)buf.FUN_0093d6a0(0) = angularLimitsTauFactor;
}
static short FUN_00936710(const D871A0Array& arr, const char* enumName) {
  D871A0Buffer buf;
  buf.FUN_0093d600(arr, "type");
  return (short)((unsigned short)(size_t)buf.b + (unsigned short)(size_t)enumName[0]);
}
static volatile long g_hD; static volatile bool g_hB[4]; static volatile float g_hF[3]; static volatile int g_sink;
void caller_of_FUN_00937140(void) {
  g_sink = (int)(size_t)&g_hD;
  FUN_00937140(*(const D871A0Array*)g_hD, g_hB[0], g_hB[1], g_hB[2], g_hB[3], g_hF[0], g_hF[1], g_hF[2]);
  g_typeIdx_105f584 = FUN_00936710(*(const D871A0Array*)g_hD, "TYPE_CONE_LIMIT");
}
}   // namespace f3m_00937140

// @f3 0x009378d0 (community match, verified in this file)
extern short DAT_0105f5a8;
extern short DAT_0105f554;
extern short DAT_0105f574;
extern short DAT_0105f57c;
namespace f3m_009378d0 {
typedef float hkReal;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

class hkClass;
class hkClassEnum;

class hkBool
{
public:
    hkBool(bool b) { m_bool = (char)b; }
    char m_bool;
};

struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};

struct hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    inline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        x = v1.y * v2.z - v1.z * v2.y;
        y = v1.z * v2.x - v1.x * v2.z;
        z = v1.x * v2.y - v1.y * v2.x;
        w = 0.0f;
    }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4& getColumn(int i) { return (&m_col0)[i]; }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
    hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    hkRotation& getRotation() { return m_rotation; }
    hkVector4& getTranslation() { return m_translation; }
};

class hkClassEnum
{
public:
    int getValueOf(const char* name, int& val) const;
};

class hkClassMember
{
public:
    const char* m_name;
    const hkClass* m_class;
    const hkClassEnum* m_enum;
    unsigned char m_type;
    unsigned char m_subtype;
    short m_cArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_attributes;

    const char* getName() const { return m_name; }
    int getOffset() const { return m_offset; }
    const hkClass& getStructClass() const;
    const hkClassEnum& getEnumClass() const;
};

class hkClass
{
public:
    int getNumMembers() const;
    const hkClassMember& getMember(int i) const;
    int getObjectSize() const;
};

class hkClassMemberAccessor;

class hkClassAccessor
{
public:
    hkClassAccessor(void* object, const hkClass* klass);
    hkClassAccessor(hkVariant& v);
    inline hkClassMemberAccessor member(const char* name);
    const hkClass& getClass() const { return *m_variant.m_class; }

    hkVariant m_variant;
};

class hkClassMemberAccessor
{
public:
    hkClassMemberAccessor(hkVariant& v, const char* memberName);
    hkClassMemberAccessor(void* object, const hkClass* klass, const char* memberName);

    hkBool& asBool(int index = 0) const;
    hkReal& asReal(int index = 0) const;
    char*& asPointer(int index = 0) const;
    hkInt16& asInt16(int index = 0) const;
    hkUint8& asUint8(int index = 0) const;
    hkVector4& asVector4(int index = 0) const;
    hkTransform& asTransform(int index = 0) const;
    hkRotation& asRotation() const;
    hkClassAccessor object() const;
    hkClassMemberAccessor member(const char* name) const;
    const hkClassMember& getClassMember() const;

    void* m_address;
    const hkClassMember* m_member;
};

inline hkClassMemberAccessor hkClassAccessor::member(const char* name)
{
    return hkClassMemberAccessor(m_variant, name);
}

class hkObjectUpdateTracker;


static hkInt16 getAtomType(hkVariant& atom, const char* typeName)
{
    hkClassMemberAccessor type(atom, "type");
    int val;
    type.getClassMember().getEnumClass().getValueOf(typeName, val);
    return (hkInt16)val;
}

static int getAtomsSize(hkClassMemberAccessor& atoms)
{
    hkClassAccessor atomsObj = atoms.object();
    const hkClass& klass = atomsObj.getClass();
    const hkClassMember& last = klass.getMember(klass.getNumMembers() - 1);
    int offset = atoms.member(last.getName()).getClassMember().getOffset();
    return offset + last.getStructClass().getObjectSize();
}

void initSetLocalRotationsAtom(hkClassAccessor& atom, const hkRotation& rotationA, const hkRotation& rotationB)
{
    if (DAT_0105f554 == -1)
    {
        DAT_0105f554 = getAtomType(atom.m_variant, "TYPE_SET_LOCAL_ROTATIONS");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f554;
    hkClassMemberAccessor(atom.m_variant, "rotationA").asRotation() = rotationA;
    hkClassMemberAccessor(atom.m_variant, "rotationB").asRotation() = rotationB;
}

static void initAngLimitAtom(hkClassAccessor& atom, hkUint8 isEnabled, hkUint8 limitAxis, hkReal minAngle,
                             hkReal maxAngle, hkReal angularLimitsTauFactor)
{
    if (DAT_0105f57c == -1)
    {
        DAT_0105f57c = getAtomType(atom.m_variant, "TYPE_ANG_LIMIT");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f57c;
    hkClassMemberAccessor(atom.m_variant, "isEnabled").asUint8() = isEnabled;
    hkClassMemberAccessor(atom.m_variant, "limitAxis").asUint8() = limitAxis;
    hkClassMemberAccessor(atom.m_variant, "minAngle").asReal() = minAngle;
    hkClassMemberAccessor(atom.m_variant, "maxAngle").asReal() = maxAngle;
    hkClassMemberAccessor(atom.m_variant, "angularLimitsTauFactor").asReal() = angularLimitsTauFactor;
}

static void init2dAngAtom(hkClassAccessor& atom, hkUint8 freeRotationAxis)
{
    if (DAT_0105f574 == -1)
    {
        DAT_0105f574 = getAtomType(atom.m_variant, "TYPE_2D_ANG");
    }
    hkClassMemberAccessor(atom.m_variant, "type").asInt16() = DAT_0105f574;
    hkClassMemberAccessor(atom.m_variant, "freeRotationAxis").asUint8() = freeRotationAxis;
}

void FUN_009378d0(hkVariant& oldObj, hkVariant& newObj, hkObjectUpdateTracker& tracker)
{
    hkClassMemberAccessor atoms(newObj, "atoms");
    hkClassAccessor oldAccessor(oldObj);

    if (DAT_0105f5a8 == -1)
    {
        DAT_0105f5a8 = (hkInt16)getAtomsSize(atoms);
    }
    {
    hkRotation rotationB;
        hkClassAccessor basisB = oldAccessor.member("basisB").object();
        rotationB.getColumn(0) = basisB.member("axle").asVector4();
        rotationB.getColumn(2) = basisB.member("perp2FreeAxis").asVector4();
        rotationB.getColumn(1).setCross(rotationB.getColumn(2), rotationB.getColumn(0));
    initSetLocalRotationsAtom(atoms.member("rotations").object(), oldAccessor.member("basisA").asRotation(), rotationB);
    }
    {
        hkClassMemberAccessor angularLimitsTauFactor(oldAccessor.m_variant, "angularLimitsTauFactor");
        hkClassMemberAccessor maxAngle(oldAccessor.m_variant, "maxAngle");
        hkClassMemberAccessor minAngle(oldAccessor.m_variant, "minAngle");
        initAngLimitAtom(atoms.member("angLimit").object(), 1, 0, minAngle.asReal(), maxAngle.asReal(),
                         angularLimitsTauFactor.asReal());
    }
    init2dAngAtom(atoms.member("2dAng").object(), 0);
}
}   // namespace f3m_009378d0

// @f3 0x0093bbc0 (community match, verified in this file)
namespace f3m_0093bbc0 {
namespace f3m_0093bbc0 {

struct QHkClass {
    const char* FUN_009b0490() const;
};

struct QHkVariant {
    void* m_object;
    QHkClass* m_class;
};

struct QHkVector4 {
    float x, y, z, w;
};

struct QEnumHolder {
    int FUN_0093d8b0();
};

class FUN_0093d7f0 {
public:
    void* m_object;
    QHkClass* m_class;
    FUN_0093d7f0(QHkVariant& v);
};

class FUN_0093d600 {
public:
    void* m_address;
    void* m_member;
    FUN_0093d600(FUN_0093d7f0& obj, const char* name);
    FUN_0093d600 FUN_0093d7a0(const char* name);
    char& FUN_0093d710(int index);
    QEnumHolder* FUN_0093d790();
    QHkVariant FUN_0093d810();
    float& FUN_0093d6a0(int index);
    QHkVector4& FUN_0093d720(int index);
};

char __cdecl FUN_00938d80(const char* className, int value);
void __cdecl FUN_0093ba60(const QHkVariant& a, const QHkVariant& b);
int __cdecl hkString_strCmp(const char* a, const char* b);

void __cdecl FUN_0093bbc0(QHkVariant& oldObj, QHkVariant& newObj)
{
    FUN_0093d7f0 newMotion(newObj);
    FUN_0093d7f0 oldMotion(oldObj);
    QHkClass* oldClass = oldObj.m_class;

    {
        FUN_0093d600 type(newMotion, "type");
        type.FUN_0093d710(0) = FUN_00938d80(oldClass->FUN_009b0490(), type.FUN_0093d790()->FUN_0093d8b0());
    }

    {
    FUN_0093d600 oldState(oldMotion, "motionState");
    FUN_0093d600 newState(newMotion, "motionState");
    FUN_0093ba60(newState.FUN_0093d810(), oldState.FUN_0093d810());

    {
        FUN_0093d600 a(oldMotion, "linearDamping");
        float& src = a.FUN_0093d6a0(0);
        newState.FUN_0093d7a0("linearDamping").FUN_0093d6a0(0) = src;
    }
    {
        FUN_0093d600 a(oldMotion, "angularDamping");
        float& src = a.FUN_0093d6a0(0);
        newState.FUN_0093d7a0("angularDamping").FUN_0093d6a0(0) = src;
    }
    }

    if (hkString_strCmp("hkBoxMotion", oldClass->FUN_009b0490())
        && hkString_strCmp("hkStabilizedBoxMotion", oldClass->FUN_009b0490())
        && hkString_strCmp("hkThinBoxMotion", oldClass->FUN_009b0490())) {
        QHkVector4 v;
        {
            FUN_0093d600 a(oldMotion, "particleMinInertiaDiagInv");
            v.x = a.FUN_0093d6a0(0);
        }
        v.y = v.x;
        v.z = v.x;
        {
            FUN_0093d600 a(oldMotion, "massInv");
            v.w = a.FUN_0093d6a0(0);
        }
        {
            FUN_0093d600 dst(newMotion, "inertiaAndMassInv");
            dst.FUN_0093d720(0) = v;
        }
    } else {
        {
        FUN_0093d600 src(oldMotion, "inertiaAndMassInv");
        FUN_0093d600 dst(newMotion, "inertiaAndMassInv");
        dst.FUN_0093d720(0) = src.FUN_0093d720(0);
    }
    }
    {
        FUN_0093d600 src(oldMotion, "linearVelocity");
        FUN_0093d600 dst(newMotion, "linearVelocity");
        dst.FUN_0093d720(0) = src.FUN_0093d720(0);
    }
    {
        FUN_0093d600 src(oldMotion, "angularVelocity");
        FUN_0093d600 dst(newMotion, "angularVelocity");
        dst.FUN_0093d720(0) = src.FUN_0093d720(0);
    }
}

}
}   // namespace f3m_0093bbc0

// @f3 0x0093c5b0 (community match, verified in this file)
namespace f3m_0093c5b0
{
extern const char DAT_00e3b510[];

struct hkClass
{
    int FUN_009b0760() const;
};

struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};

struct ClassVariant
{
    void* m_object;
    const hkClass* m_class;
    ClassVariant();
};

struct ArrayView
{
    char* data;
    int count;
};

struct MemberAccessor
{
    void* object;
    const char* name;
    MemberAccessor(void* obj, const char* memberName);
    bool* FUN_0093d640(bool* isOk);
    ArrayView* FUN_0093d760(int index);
    ClassVariant FUN_0093d810();
};

void __cdecl FUN_0093c520(hkVariant* from, hkVariant* to, void* context);
}

void __cdecl FUN_0093c5b0(void* oldObject, void* newObject, void* context)
{
    f3m_0093c5b0::MemberAccessor to(newObject, f3m_0093c5b0::DAT_00e3b510);
    f3m_0093c5b0::MemberAccessor from(oldObject, f3m_0093c5b0::DAT_00e3b510);
    bool isOk;
    if (!*to.FUN_0093d640(&isOk))
        return;
    if (!*from.FUN_0093d640(&isOk))
        return;
    f3m_0093c5b0::ArrayView* toArray = to.FUN_0093d760(0);
    f3m_0093c5b0::ArrayView* fromArray = from.FUN_0093d760(0);
    for (int i = 0; i < toArray->count; i++)
    {
        const f3m_0093c5b0::hkClass* fromClass = from.FUN_0093d810().m_class;
        char* fromItem = fromArray->data + fromClass->FUN_009b0760() * i;
        const f3m_0093c5b0::hkClass* toClass = to.FUN_0093d810().m_class;
        char* toItem = toArray->data + toClass->FUN_009b0760() * i;
        f3m_0093c5b0::hkVariant toVariant;
        toVariant.m_object = toItem;
        toVariant.m_class = toClass;
        f3m_0093c5b0::hkVariant fromVariant;
        fromVariant.m_object = fromItem;
        fromVariant.m_class = fromClass;
        f3m_0093c5b0::FUN_0093c520(&fromVariant, &toVariant, context);
    }
}

// @f3 0x00928690 (community match, verified in this file)
namespace f3m_00928690 {
namespace f3m_00928690 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    T& operator[](int i) { return data[i]; }
};
template <class T, int N> struct InplaceArray : Array<T> {
    T storage[N];
    __forceinline InplaceArray() throw() {
        this->data = storage;
        this->size = 0;
        this->capAndFlags = N | 0x80000000;
    }
    __forceinline void Free() throw() {
        if ((this->capAndFlags & 0x80000000) == 0) {
            int cap = this->capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)::TlsGetValue(::DAT_010f3170);
            al->FUN_008f6d90(this->data, cap * sizeof(T), 0x17);
        }
    }
};
struct Entity;
struct Constraint {
    virtual void Destroy(int flags) throw();
    virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void GetEntities(Array<Entity*>& out) throw();
    unsigned short memSize;
    short refCount;
    __forceinline void RemoveReference() throw() {
        if (memSize != 0) { --refCount; if (refCount == 0) Destroy(1); }
    }
};
struct Island {
    void hkpSimulationIsland_addAction(Constraint* c) throw();
};
struct Entity {
    char p00[8];
    void* unk08;
    char p0c[0xb8 - 0xc];
    Island* island;
    char pbc[0xd8 - 0xbc];
    unsigned char motionType;
};
struct Context {
    char p00[0x20];
    Island* fixedIsland;
};
void __cdecl FUN_00928630(void* owner, Entity* a, Entity* b) throw();
__forceinline void AddPair(Entity* a, Entity* b) { if (a->motionType != 7 && b->motionType != 7 && a->island != b->island) FUN_00928630(a->unk08, a, b); }
}
// pdb: hkpWorldOperationUtil::addActionsToEntitysIsland | hkpWorldOperationUtil.obj | fnv360_0721_beta, caller_sim + bridge(call_gap|call_gap_sim) + skyrim(call_gap), high
void __cdecl hkpWorldOperationUtil_addActionsToEntitysIsland(f3m_00928690::Context* ctx, f3m_00928690::Entity* self,
                          f3m_00928690::Array<f3m_00928690::Constraint*>* list)
{
    using namespace f3m_00928690;
    Island* island = self->island;
    InplaceArray<Entity*, 16> entities;
    for (int i = 0; i < list->size; i++) {
        Constraint* c = list->data[i];
        Island* fixed = ctx->fixedIsland;
        if (island != fixed) {
            island->hkpSimulationIsland_addAction(c);
            c->RemoveReference();
            entities.size = 0;
            c->GetEntities(entities);
            for (int j = 0; j < entities.size; j++) {
                if (entities[j]->motionType != 7 && entities[j] != self)
                    AddPair(entities[j], self);
            }
        } else {
            fixed->hkpSimulationIsland_addAction(c);
            c->RemoveReference();
        }
    }
    entities.Free();
}
}   // namespace f3m_00928690

// @f3 0x00930820 (community match, verified in this file)
#include <math.h>
namespace f3m_00930820 {
namespace h930 {
typedef float hkReal;
struct hkQuadReal { hkReal v[4]; };
namespace hkMath {
    __forceinline hkReal sqrt(hkReal r) { return (hkReal)::sqrt(r); }
    __forceinline hkReal fabs(hkReal r) { return (hkReal)::fabs(r); }
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkVector4 {
public:
    hkQuadReal m_quad;
    __forceinline hkReal& operator()(int i) { return m_quad.v[i]; }
    __forceinline const hkReal& operator()(int i) const { return m_quad.v[i]; }
    __forceinline void operator=(const hkVector4& v) { m_quad.v[0] = v.m_quad.v[0]; m_quad.v[1] = v.m_quad.v[1]; m_quad.v[2] = v.m_quad.v[2]; m_quad.v[3] = v.m_quad.v[3]; }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w) { m_quad.v[0] = x; m_quad.v[1] = y; m_quad.v[2] = z; m_quad.v[3] = w; }
    __forceinline void setZero4() { m_quad.v[0] = m_quad.v[1] = m_quad.v[2] = m_quad.v[3] = 0.0f; }
    __forceinline void mul4(hkReal s) { (*this)(0) *= s; (*this)(1) *= s; (*this)(2) *= s; (*this)(3) *= s; }
    __forceinline hkReal lengthInverse3() const { hkReal l2 = (m_quad.v[0] * m_quad.v[0]) + (m_quad.v[1] * m_quad.v[1]) + (m_quad.v[2] * m_quad.v[2]); return l2 ? hkMath::sqrtInverse(l2) : 0; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b) {
        const hkReal nx = a(1) * b(2) - a(2) * b(1);
        const hkReal ny = a.m_quad.v[2] * b.m_quad.v[0] - a.m_quad.v[0] * b.m_quad.v[2];
        const hkReal nz = a(0) * b(1) - a(1) * b(0);
        m_quad.v[0] = nx; m_quad.v[1] = ny; m_quad.v[2] = nz; m_quad.v[3] = 0.0f;
    }
};
__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;
    hkReal a0 = hkMath::fabs(vectorIn.m_quad.v[0]);
    hkReal a1 = hkMath::fabs(vectorIn.m_quad.v[1]);
    hkReal a2 = hkMath::fabs(vectorIn.m_quad.v[2]);
    if (a1 < a0) { ok1 = 0; min = 1; a0 = a1; }
    if (a2 < a0) { ok2 = min; min = 2; }
    biVectorOut.setZero4();
    biVectorOut.m_quad.v[ok1] = vectorIn.m_quad.v[ok2];
    biVectorOut.m_quad.v[ok2] = -vectorIn.m_quad.v[ok1];
}
struct hkRotation { hkVector4 m_col0, m_col1, m_col2; __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; } };
struct hkTransform { hkRotation m_rotation; hkVector4 m_translation; __forceinline hkVector4& getTranslation() { return m_translation; } __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); } };
}
struct S930_HingeData {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    h930::hkTransform m_transformA;
    h930::hkTransform m_transformB;
    void FUN_00930820(const h930::hkVector4& pivotA, const h930::hkVector4& pivotB, const h930::hkVector4& axisA, const h930::hkVector4& axisB);
};
void S930_HingeData::FUN_00930820(const h930::hkVector4& pivotA, const h930::hkVector4& pivotB, const h930::hkVector4& axisA, const h930::hkVector4& axisB)
{
    m_transformA.getTranslation() = pivotA;
    m_transformB.getTranslation() = pivotB;

    h930::hkVector4* baseA = &m_transformA.getColumn(0);
    baseA[0] = axisA;
    baseA[0].normalize3();
    h930::calculatePerpendicularVector(baseA[0], baseA[1]);
    baseA[1].normalize3();
    baseA[2].setCross(baseA[0], baseA[1]);

    h930::hkVector4* baseB = &m_transformB.getColumn(0);
    baseB[0] = axisB;
    baseB[0].normalize3();
    h930::calculatePerpendicularVector(baseB[0], baseB[1]);
    baseB[1].normalize3();
    baseB[2].setCross(baseB[0], baseB[1]);
}
}   // namespace f3m_00930820

// @f3 0x0092afc0 (community match, verified in this file)
#include <math.h>
namespace f3m_0092afc0 {
namespace f3m_0092afc0 {
namespace hafc0 {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
struct hkQuadReal { hkReal v[4]; };
namespace hkMath {
    inline hkReal sqrt(hkReal r) { return sqrtf(r); }
    inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkVector4 {
public:
    hkReal x, y, z, w;
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void mul4(hkSimdRealParameter rs) { hkReal s = hkReal(rs); x *= s; y *= s; z *= s; w *= s; }
    __forceinline hkSimdReal lengthInverse3() const { hkReal l2 = (x*x) + (y*y) + (z*z); return l2 ? hkMath::sqrtInverse(l2) : 0; }
    __forceinline void normalize3() { this->mul4( this->lengthInverse3() ); }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2) {
        const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
        const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
        const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
        this->set( nx, ny, nz , 0.0f ); }
};
struct hkRotation { hkVector4 m_col0, m_col1, m_col2; __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; } };
struct hkTransform { hkRotation m_rotation; hkVector4 m_translation; __forceinline hkVector4& getTranslation() { return m_translation; } __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); } };
}
struct Safc0_LimitedHingeData {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    hafc0::hkTransform m_transformA;
    hafc0::hkTransform m_transformB;
    void FUN_0092afc0(const hafc0::hkVector4& pivotA, const hafc0::hkVector4& pivotB, const hafc0::hkVector4& axisA, const hafc0::hkVector4& axisB, const hafc0::hkVector4& axisAPerp, const hafc0::hkVector4& axisBPerp);
};
void Safc0_LimitedHingeData::FUN_0092afc0(const hafc0::hkVector4& pivotA, const hafc0::hkVector4& pivotB, const hafc0::hkVector4& axisA, const hafc0::hkVector4& axisB, const hafc0::hkVector4& axisAPerp, const hafc0::hkVector4& axisBPerp)
{
    hafc0::hkTransform& ta = m_transformA;
    ta.getColumn(0) = axisA;
    ta.getColumn(0).normalize3();
    ta.getColumn(1) = axisAPerp;
    ta.getColumn(1).normalize3();
    ta.getColumn(2).setCross(ta.getColumn(0), ta.getColumn(1));
    ta.getTranslation() = pivotA;

    hafc0::hkTransform& tb = m_transformB;
    tb.getColumn(0) = axisB;
    tb.getColumn(0).normalize3();
    tb.getColumn(1) = axisBPerp;
    tb.getColumn(1).normalize3();
    tb.getColumn(2).setCross(tb.getColumn(0), tb.getColumn(1));
    tb.getTranslation() = pivotB;
}
}
}   // namespace f3m_0092afc0

// @f3 0x00924fa0 (community match, verified in this file)
namespace f3m_00924fa0 {
struct S924fa0 {
    float m[16];
    unsigned char* FUN_00924fa0(unsigned char* out);
};

// pdb: hkTransform::get4x4ColumnMajor | hkTransform.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkTransform::isOk)
// pdb params: d
unsigned char* S924fa0::FUN_00924fa0(unsigned char* out)
{
    for (int i = 0; i < 16; i++)
    {
        union { float f; unsigned u; } t;
        t.f = m[i];
        if ((t.u & 0x7f800000) == 0x7f800000)
        {
            *out = 0;
            return out;
        }
    }
    *out = 1;
    return out;
}
}   // namespace f3m_00924fa0

// @f3 0x00924f40 (community match, verified in this file)
namespace f3m_00924f40 {
namespace native_00924f40 {
struct __declspec(align(16)) Vector4
{
    float x, y, z, w;
    __forceinline void SetXYZ(const Vector4& value)
    {
        x = value.x;
        y = value.y;
        z = value.z;
        w = 0.0f;
    }
};
struct Transform
{
    Vector4 columns[4];
};
struct Matrix4
{
    Vector4 columns[4];
    void FUN_00924f40(const Transform& transform);
};
// pdb: hkMatrix4::set4x4ColumnMajor | hkMatrix4.obj | fnv360_0822_retail, objopen_prop, low, conflict (skyrim: hkTransform::set4x4ColumnMajor)
// pdb params: p
void Matrix4::FUN_00924f40(const Transform& transform)
{
    columns[0].SetXYZ(transform.columns[0]);
    columns[1].SetXYZ(transform.columns[1]);
    columns[2].SetXYZ(transform.columns[2]);
    columns[3].SetXYZ(transform.columns[3]);
    columns[3].w = 1.0f;
}
}
}   // namespace f3m_00924f40

// @f3 0x00920d10 (community match, verified in this file)
namespace f3m_00920d10 {
// hkpCharacterProxy::updateManifold (Havok 5.5.0 hkpUtilities, hkpCharacterProxy.cpp lines 950-1139), game build.
// Statement structure and local names from the SDK's hybrid debug records; the game's hkpRootCdPoint is 64 bytes.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_920d10 {

typedef float hkReal;

class __declspec(align(16)) hkVector4
{
public:
    inline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    hkReal x, y, z, w;
};

struct hkContactPoint
{
    inline hkReal getDistance() const { return m_separatingNormal.w; }
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

class hkpRigidBody;
class hkpPhantom;
class hkpEntityListener;
class hkpPhantomListener;

struct hkpTypedBroadPhaseHandle
{
    int m_id;
    signed char m_type;
};

class hkpCollidable
{
public:
    inline const void* getOwner() const { return reinterpret_cast<const void*>(m_ownerOffset + (const char*)this); }
    inline int getType() const { return m_broadPhaseHandle.m_type; }

    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const void* m_parent;
    signed char m_ownerOffset;
    hkpTypedBroadPhaseHandle m_broadPhaseHandle;
};

// 64 bytes in the game; the SDK's is 48 with a scalar m_shapeKeyB. The game copies 0x00-0x3b member by member and the
// copy loop is compiled as for a struct with an array member there: m_shapeKeyB[4] (0x2c-0x3b) is our layout.
struct hkpRootCdPoint
{
    hkContactPoint m_contact;
    const hkpCollidable* m_rootCollidableA;
    unsigned int m_shapeKeyA;
    const hkpCollidable* m_rootCollidableB;
    unsigned int m_shapeKeysB[4];   // 0x2c-0x3b: key B then three parent-chain keys (our spelling of the layout)
};

class hkpEntity
{
public:
    void addEntityListener(hkpEntityListener* el) throw();
    void removeEntityListener(hkpEntityListener* el);
};

class hkpRigidBody : public hkpEntity
{
};

class hkpPhantom
{
public:
    void addPhantomListener(hkpPhantomListener* el) throw();
    void removePhantomListener(hkpPhantomListener* el);
};

inline hkpRigidBody* hkGetRigidBody(const hkpCollidable* collidable)
{
    if (collidable->getType() == 1)
    {
        return (hkpRigidBody*)(const_cast<void*>(collidable->getOwner()));
    }
    return 0;
}

inline hkpPhantom* hkGetPhantom(const hkpCollidable* collidable)
{
    if (collidable->getType() == 2)
    {
        return (hkpPhantom*)(const_cast<void*>(collidable->getOwner()));
    }
    return 0;
}

class hkThreadMemory
{
public:
    struct Stack
    {
        char* m_current;
        Stack* m_prev;
        char* m_base;
        char* m_end;
    };

    virtual void* alignedAllocate(int alignment, int nbytes, int cl);
    virtual void alignedDeallocate(void* ptr);
    virtual void setStackArea(void* buf, int nbytes);
    virtual void releaseCachedMemory();
    virtual ~hkThreadMemory();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);

    void deallocateChunk(void* p, int nbytes, int cl);

    inline void* allocateStack(int nbytesin)
    {
        int actualBytes = (nbytesin + 16) & (~((16) - 1));
        char* p = m_stack.m_current;
        char* end = p + actualBytes;
        if (end <= m_stack.m_end)
        {
            m_stack.m_current = end;
            return p;
        }
        else
        {
            return onStackOverflow(actualBytes);
        }
    }

    inline void deallocateStack(void* p)
    {
        m_stack.m_current = static_cast<char*>(p);
        if (p == m_stack.m_base)
        {
            onStackUnderflow(p);
        }
    }

    static inline hkThreadMemory& getInstance();

    void* m_memory;          // 0x04
    int m_referenceCount;    // 0x08
    int m_unk0c;             // 0x0c..0x1f: the game's hkThreadMemory places m_stack at 0x20
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    Stack m_stack;           // 0x20
};

template <typename T>
class hkThreadLocalData
{
public:
    T getData() const { return (T)(unsigned long)::TlsGetValue(m_slotID); }
    unsigned long m_slotID;
};

extern hkThreadLocalData<hkThreadMemory*> DAT_010f3170;   // hkThreadMemory__s_threadMemoryInstance

inline hkThreadMemory& hkThreadMemory::getInstance()
{
    hkThreadMemory* instance = DAT_010f3170.getData();
    return *instance;
}

template <typename TYPE>
inline TYPE* hkAllocateStack(int n)
{
    hkThreadMemory& mem = hkThreadMemory::getInstance();
    return static_cast<TYPE*>(mem.allocateStack(n * sizeof(TYPE)));
}

template <typename TYPE>
inline void hkDeallocateStack(TYPE* ptr)
{
    hkThreadMemory::getInstance().deallocateStack(static_cast<void*>(ptr));
}

void __cdecl FUN_00901f10(void* array, int sizeElem) throw();   // hkArrayUtil::_reserveMore

template <typename T>
class hkArray
{
public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        DONT_DEALLOCATE_FLAG = int(0x80000000)
    };

    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}

    int getCapacity() const { return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK)); }
    int getSize() const { return m_size; }
    void clear() { m_size = 0; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    void setSizeUnchecked(int n) { m_size = n; }
    void removeAt(int i)
    {
        m_size--;
        m_data[i] = m_data[m_size];
    }
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_size; ++i)
        {
            if (m_data[i] == t)
            {
                return i;
            }
        }
        return -1;
    }
    void pushBack(const T& t)
    {
        if (m_size == getCapacity())
        {
            FUN_00901f10(this, sizeof(T));
        }
        m_data[m_size++] = t;
    }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().deallocateChunk(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }

    ~hkArray() { releaseMemory(); }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
class hkLocalArray : public hkArray<T>
{
public:
    __forceinline hkLocalArray(int capacity) throw()
    {
        this->m_data = hkAllocateStack<T>(capacity);
        this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_localMemory = this->m_data;
    }
    __forceinline ~hkLocalArray() throw()
    {
        hkDeallocateStack<T>(m_localMemory);
    }
    T* m_localMemory;
};

class hkpCdPointCollector
{
public:
    void* __vfptr;
    hkReal m_earlyOutDistance;
};

class hkpAllCdPointCollector : public hkpCdPointCollector
{
public:
    int m_unk08;
    int m_unk0c;
    hkArray<hkpRootCdPoint> m_hits;   // 0x10 (inplace storage follows)
    const hkArray<hkpRootCdPoint>& getHits() const { return m_hits; }
};

class hkBool
{
public:
    hkBool() {}
    hkBool(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
    char m_bool;
};

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};

class hkpEntityListener
{
public:
    virtual ~hkpEntityListener();
};

class hkpPhantomListener
{
public:
    virtual ~hkpPhantomListener();
};

}


class hkpCharacterProxy : public f3m_920d10::hkReferencedObject, public f3m_920d10::hkpEntityListener,
                          public f3m_920d10::hkpPhantomListener
{
public:
    f3m_920d10::hkReal surfaceDistance(const f3m_920d10::hkpRootCdPoint& p1, const f3m_920d10::hkpRootCdPoint& p2) const throw();
    void fireContactRemoved(const f3m_920d10::hkpRootCdPoint& point) const throw();
    void fireContactAdded(const f3m_920d10::hkpRootCdPoint& point) const throw();
    int findSurface(const f3m_920d10::hkpRootCdPoint& info) const throw();

    void hkpCharacterProxy_updateManifold(const f3m_920d10::hkpAllCdPointCollector& startPointCollector,
                      const f3m_920d10::hkpAllCdPointCollector& castCollector);

    f3m_920d10::hkVector4 m_velocity;
    f3m_920d10::hkVector4 m_oldDisplacement;
    void* m_shapePhantom;
    float m_dynamicFriction;
    float m_staticFriction;
    f3m_920d10::hkVector4 m_up;
    float m_extraUpStaticFriction;
    float m_extraDownStaticFriction;
    float m_keepDistance;
    float m_keepContactTolerance;
    float m_contactAngleSensitivity;
    int m_userPlanes;
    float m_maxCharacterSpeedForSolver;
    float m_characterStrength;
    float m_characterMass;
    f3m_920d10::hkArray<f3m_920d10::hkpRootCdPoint> m_manifold;   // 0x74
    f3m_920d10::hkArray<void*> m_listeners;                        // 0x80
    f3m_920d10::hkArray<f3m_920d10::hkpRigidBody*> m_bodies;       // 0x8c
    f3m_920d10::hkArray<f3m_920d10::hkpPhantom*> m_phantoms;       // 0x98
};


// pdb: hkpCharacterProxy::updateManifold | hkpCharacterProxy.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpCharacterProxy::hkpCharacterProxy_updateManifold(const f3m_920d10::hkpAllCdPointCollector& startPointCollector,
                                     const f3m_920d10::hkpAllCdPointCollector& castCollector)
{
    // Remove listeners from all bodies and phantoms
    {
        for (int i = 0; i < m_bodies.getSize(); i++)
        {
            m_bodies[i]->removeEntityListener(this);
        }
        m_bodies.clear();

        for (int j = 0; j < m_phantoms.getSize(); j++)
        {
            m_phantoms[j]->removePhantomListener(this);
        }
        m_phantoms.clear();
    }

    f3m_920d10::hkReal minimumPenetration = 3.40282e+38f;   // HK_REAL_MAX

    f3m_920d10::hkLocalArray<f3m_920d10::hkpRootCdPoint> startPointHits(startPointCollector.getHits().getSize());
    startPointHits.setSizeUnchecked(startPointCollector.getHits().getSize());
    {
        for (int i = 0; i < startPointHits.getSize(); i++)
        {
            startPointHits[i] = startPointCollector.getHits()[i];
            if (startPointHits[i].m_contact.getDistance() < minimumPenetration)
            {
                minimumPenetration = startPointHits[i].m_contact.getDistance();
            }
        }
    }

    // Update the manifold: keep points that still have a close hit
    {
        for (int s = m_manifold.getSize() - 1; s >= 0; s--)
        {
            int bestIndex = -1;
            f3m_920d10::hkReal minDistance = 1.1f;
            f3m_920d10::hkpRootCdPoint& current = m_manifold[s];

            for (int h = 0; h < startPointHits.getSize(); h++)
            {
                f3m_920d10::hkpRootCdPoint& surface = startPointHits[h];

                f3m_920d10::hkReal distance = surfaceDistance(surface, current);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    bestIndex = h;
                }
            }

            if (bestIndex >= 0)
            {
                f3m_920d10::hkpRootCdPoint& surface = startPointHits[bestIndex];
                if (surface.m_rootCollidableB != current.m_rootCollidableB)
                {
                    fireContactRemoved(current);
                    fireContactAdded(surface);
                }
                current = surface;
                startPointHits.removeAt(bestIndex);
            }
            else
            {
                fireContactRemoved(m_manifold[s]);
                m_manifold.removeAt(s);
            }
        }

        for (int h = 0; h < startPointHits.getSize(); h++)
        {
            f3m_920d10::hkpRootCdPoint& surface = startPointHits[h];
            if (surface.m_contact.getDistance() == minimumPenetration)
            {
                int index = findSurface(surface);
                if (index >= 0)
                {
                    f3m_920d10::hkpRootCdPoint& current = m_manifold[index];
                    if (surface.m_rootCollidableB != current.m_rootCollidableB)
                    {
                        fireContactRemoved(current);
                        fireContactAdded(surface);
                    }
                    current = surface;
                }
                else
                {
                    fireContactAdded(surface);
                    m_manifold.pushBack(surface);
                }
            }
        }
    }

    // Add the closest cast hit
    if (castCollector.getHits().getSize() > 0)
    {
        const f3m_920d10::hkpRootCdPoint& surface = castCollector.getHits()[0];
        int index = findSurface(surface);
        if (index == -1)
        {
            fireContactAdded(surface);
            m_manifold.pushBack(surface);
        }
    }

    // Remove duplicates
    {
        for (int p1 = m_manifold.getSize() - 1; p1 > 0; p1--)
        {
            f3m_920d10::hkBool remove = false;
            for (int p2 = p1 - 1; p2 >= 0; p2--)
            {
                const f3m_920d10::hkReal minDistance = 0.1f;
                f3m_920d10::hkReal distance = surfaceDistance(m_manifold[p1], m_manifold[p2]);
                if (distance < minDistance)
                {
                    remove = true;
                    break;
                }
            }
            if (remove)
            {
                fireContactRemoved(m_manifold[p1]);
                m_manifold.removeAt(p1);
            }
        }
    }

    // Add new bodies and phantoms
    {
        for (int i = 0; i < m_manifold.getSize(); i++)
        {
            f3m_920d10::hkpRigidBody* body = f3m_920d10::hkGetRigidBody(m_manifold[i].m_rootCollidableB);
            if (body && (m_bodies.indexOf(body) == -1))
            {
                body->addEntityListener(this);
                m_bodies.pushBack(body);
            }

            f3m_920d10::hkpPhantom* phantom = f3m_920d10::hkGetPhantom(m_manifold[i].m_rootCollidableB);
            if (phantom && (m_phantoms.indexOf(phantom) == -1))
            {
                phantom->addPhantomListener(this);
                m_phantoms.pushBack(phantom);
            }
        }
    }
}
}   // namespace f3m_00920d10

// @f3 0x0092c850 (community match, verified in this file)
namespace f3m_0092c850 {
namespace f3m_0092c850 {
void __cdecl FUN_0089ec10(void*, unsigned);
struct Obj {
    void FUN_00949a30();
    Obj* FUN_0092c850(unsigned flags);
};
Obj* Obj::FUN_0092c850(unsigned flags) {
    FUN_00949a30();
    if (flags & 1) FUN_0089ec10(this, 16);
    return this;
}
}
}   // namespace f3m_0092c850

// @f3 0x0092c870 (community match, verified in this file)
extern int DAT_00e37094;
namespace f3m_0092c870 {
namespace f3m_0092c870 {
extern void (__stdcall* DAT_00e3709c)(void*);
struct SimpleArray {
    void* vtable;
    void* data;
    unsigned size;
    unsigned capacity;
    void FUN_0092c870();
};
void SimpleArray::FUN_0092c870() {
    vtable = &DAT_00e37094;
    if (data) {
        DAT_00e3709c(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
}
}
}   // namespace f3m_0092c870
