#include <new>
#include <windows.h>
#include <stdio.h>
// src/f3staging/f3blk_00460000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004690a0 (community match, verified in this file)
class Owner_004690a0 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
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
    float unk90;
    float unk94;
    float unk98;
    float unk9C;
    void FUN_004690a0(const float* src);
};

extern float DAT_01092a50;
extern float DAT_01092a54;
extern float DAT_01092a58;
extern float DAT_01092a5c;

void Owner_004690a0::FUN_004690a0(const float* src)
{
    unk90 = DAT_01092a50;
    unk94 = DAT_01092a54;
    unk98 = DAT_01092a58;
    unk9C = DAT_01092a5c;
    unk10 = src[0];
    unk14 = src[1];
    unk18 = src[2];
    unk1C = src[3];
}

// @f3 0x0047deb0 (community match, verified in this file)
struct FUN_00417620_obj {
    void FUN_00417620(int a, int b, int c, void* d);
};

struct FUN_0047deb0_node {
    FUN_00417620_obj* unk00;
    FUN_0047deb0_node* unk04;
};

struct FUN_0047deb0_owner {
    FUN_0047deb0_node* unk00;
    int unk04;
    void* unk08;
    void FUN_0047deb0();
};

// pdb: ItemChange::InitLoadGame | InventoryChanges.obj | fnv360_0721_retail, call_seq, medium
void FUN_0047deb0_owner::FUN_0047deb0() {
    FUN_0047deb0_node* n = unk00;
    while (n) {
        if (n->unk04 == 0) {
            if (n->unk00 == 0) {
                break;
            }
        }
        FUN_00417620_obj* o = n->unk00;
        if (o) {
            o->FUN_00417620(0, 0, 0, unk08);
        }
        n = n->unk04;
    }
}

// @f3 0x004651a0 (community match, verified in this file)
struct FUN_004651a0_Class {
    int unk00;

    FUN_004651a0_Class* __thiscall FUN_004651a0(unsigned char flag);
};

extern void FUN_00dbe6cc();
void __cdecl FUN_00824ed0();
void __cdecl FUN_0089ec10(FUN_004651a0_Class* obj, int value);

// pdb: NiStencilProperty::`scalar deleting destructor' | BGSAutoWater.obj | fnv360_0822_retail, vtable, medium
FUN_004651a0_Class* __thiscall FUN_004651a0_Class::FUN_004651a0(unsigned char flag) {
    unk00 = (int)(void*)&FUN_00dbe6cc;
    FUN_00824ed0();

    if (flag & 1) {
        FUN_0089ec10(this, 0x24);
    }

    return this;
}

// @f3 0x0047af50 (community match, verified in this file)
struct FUN_0047af50_Obj {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14(int, int);

    int unk04;
    int unk08;

    bool __thiscall GridArray_SetCenter(int param2, int param3);
};

void FUN_0047af50_Obj::vf00() {}
void FUN_0047af50_Obj::vf04() {}
void FUN_0047af50_Obj::vf08() {}
void FUN_0047af50_Obj::vf0C() {}
void FUN_0047af50_Obj::vf10() {}
void FUN_0047af50_Obj::vf14(int, int) {}

// pdb: GridArray::SetCenter | GridArray.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
bool __thiscall FUN_0047af50_Obj::GridArray_SetCenter(int param2, int param3) {
    int deltaX = param2 - unk04;
    int deltaY = param3 - unk08;

    vf14(deltaX, deltaY);

    if (deltaX == 0 && deltaY == 0) {
        return false;
    }
    return true;
}

// @f3 0x00477a30 (community match, verified in this file)
struct TypeInfo47 {
    const char* name;
    const TypeInfo47* base;
};
extern const TypeInfo47 DAT_010f31d0;
extern const char DAT_010f2c30[];
class ClassifiedObject47 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual const TypeInfo47* getType() const;
};
struct LookupResult47 {
    ClassifiedObject47* item;
    unsigned int unk04;
};
struct LookupOwner47 {
    LookupResult47* FUN_00477900(LookupResult47* out, const void* key);
};
__forceinline bool IsRequestedType47(const TypeInfo47* type)
{
    if (type) do {
        if (type == &DAT_010f31d0) return true;
        type = type->base;
    } while (type);
    return false;
}
__forceinline ClassifiedObject47* FindObject47(LookupOwner47* owner)
{
    if (!owner) return 0;
    LookupResult47 result;
    return owner->FUN_00477900(&result, DAT_010f2c30)->item;
}
// pdb: bhkPCollisionObject::Getbhk | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apPhantom
ClassifiedObject47* __cdecl FUN_00477a30(LookupOwner47* owner)
{
    ClassifiedObject47* object = FindObject47(owner);
    if (!object) return 0;
    return IsRequestedType47(object->getType()) ? object : 0;
}

// @f3 0x004776e0 (community match, verified in this file)
class FUN_004776e0_Owner
{
  public:
    virtual void vf00();
    virtual int vf04(int value);
    unsigned int unk04;
    int* unk08;

    void FUN_004776e0(int** result, int* value, int* values);
};

void FUN_004776e0_Owner::vf00()
{
}

int FUN_004776e0_Owner::vf04(int value)
{
    return value;
}

// pdb: NiTMapBase<DFALL<NiTMapItem<unsigned int,VertexDist> >,unsigned int,VertexDist>::GetNext | GlobalFunc.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: pos, key, val
void __thiscall FUN_004776e0_Owner::FUN_004776e0(int** result, int* value, int* values)
{
    int* table = *result;

    *value = table[1];
    *values = table[2];
    values[1] = table[3];
    values[2] = table[4];

    int found = table[0];
    if (found != 0) {
        *result = (int*)found;
        return;
    }

    unsigned int index = (unsigned int)vf04(table[1]) + 1;
    if (index < unk04) {
        int* current = unk08 + index;
        do {
            found = *current;
            if (found != 0) {
                *result = (int*)found;
                return;
            }
            ++index;
            ++current;
        } while (index < unk04);
    }

    *result = 0;
}

// @f3 0x004651d0 (community match, verified in this file)
struct Vec3_4651 {
    float x, y, z;
};

struct Vec2_4651 {
    float x, y;
    Vec2_4651(float ax, float ay) : x(ax), y(ay) {}
};

struct Area_4651 {
    bool ContainsPoint(Vec2_4651 pt);
};

struct PointData_4651 {
    int unk00;
    Vec3_4651* unk04;
};

struct PointOwner_4651 {
    PointData_4651* unk00;
    int unk04[8];
    int unk24;
};

// pdb: BGSAutoWater::IsPolyonInsidePolygon | BGSAutoWater.obj | fnv360_0822_retail, call_gap, low
// pdb params: apPoly1, apPoly2
bool FUN_004651d0(PointOwner_4651* owner, Area_4651* area)
{
    for (int i = 0; i < owner->unk24; i++) {
        Vec3_4651 pt = owner->unk00->unk04[i];
        if (area->ContainsPoint(Vec2_4651(pt.x, pt.y)))
            return true;
    }
    return false;
}

// @f3 0x0047f300 (community match, verified in this file)
struct Entry_47f3 {
    int GetKey();
};

struct InnerNode_47f3 {
    Entry_47f3* data;
    InnerNode_47f3* next;
};

struct Group_47f3 {
    InnerNode_47f3* head;
};

struct OuterNode_47f3 {
    Group_47f3* data;
    OuterNode_47f3* next;
};

struct GroupList_47f3 {
    OuterNode_47f3* head;

    bool FUN_0047f300(int key);
};

// pdb: InventoryChanges::IsLevelItemInited | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiIndex
bool GroupList_47f3::FUN_0047f300(int key)
{
    bool found = false;
    OuterNode_47f3* node = head;
    if (node) {
        do {
            Group_47f3* group = node->data;
            if (!group || found)
                break;
            for (InnerNode_47f3* inner = group->head; inner; inner = inner->next) {
                Entry_47f3* entry = inner->data;
                if (!entry)
                    break;
                if (entry->GetKey() == key)
                    found = true;
            }
            node = node->next;
        } while (node);
    }
    return found;
}

// @f3 0x0047cec0 (community match, verified in this file)
class CountedEntry_47cec0
{
public:
    bool IsCounted_40ac70();
    short GetCount_40ac80();
};

struct EntryNode_47cec0
{
    CountedEntry_47cec0* item;
    EntryNode_47cec0* next;
};

class EntryList_47cec0
{
public:
    EntryNode_47cec0* head;

    int FUN_0047cec0();
};

// pdb: ItemChange::NumberLeveledExtra | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
int EntryList_47cec0::FUN_0047cec0()
{
    int total = 0;
    EntryNode_47cec0* node = head;
    if (node)
    {
        do
        {
            CountedEntry_47cec0* entry = node->item;
            if (!entry)
                break;
            if (entry->IsCounted_40ac70())
                total += entry->GetCount_40ac80();
            node = node->next;
        } while (node);
    }
    return total;
}

// @f3 0x0046f720 (community match, verified in this file)
extern unsigned int g_uiTotalMemory_46f7;
unsigned int GetTotalMemory_46f7();
int FormatString_46f7(char* buffer, const char* format, ...);

// pdb: BGSSceneInfo::BuildMNumberString | BGSSceneInfo.obj | fnv360_0822_retail, ustr, medium
// pdb params: afMnumber, aOutText, abForActor
void FUN_0046f720(float used, char* buffer, bool useCached)
{
    float total;
    if (useCached)
        total = (float)g_uiTotalMemory_46f7;
    else
        total = (float)GetTotalMemory_46f7();
    float percent = used * 100.0 / total;
    total = total / 1048576.0;
    if (used > 1048576.0f) {
        float usedMB = used / 1048576.0;
        FormatString_46f7(buffer, "%.2f%% (%.2f MB / %.2f MB)", percent, usedMB, total);
    } else if (used > 1024.0f) {
        float usedKB = used / 1024.0;
        FormatString_46f7(buffer, "%.2f%% (%.2f KB / %.2f MB)", percent, usedKB, total);
    } else {
        FormatString_46f7(buffer, "%.2f%% (%.0f bytes / %.2f MB)", percent, used, total);
    }
}

// @f3 0x0047d2a0 (community match, verified in this file)
class FUN_0047d2a0_Object {
public:
    int FUN_0040ace0();
};

class FUN_0047d2a0_Node {
public:
    FUN_0047d2a0_Object* unk00;
    FUN_0047d2a0_Node* unk04;
};

class FUN_0047d2a0_Owner {
public:
    FUN_0047d2a0_Node* unk00;

    int FUN_0047d2a0();
};

// pdb: ItemChange::GetScript | InventoryChanges.obj | fnv360_0822_retail, call_gap, medium
int FUN_0047d2a0_Owner::FUN_0047d2a0() {
    FUN_0047d2a0_Node* node = unk00;

    while (node != 0) {
        FUN_0047d2a0_Object* object = node->unk00;
        if (object == 0)
            break;

        if (object->FUN_0040ace0() != 0)
            return object->FUN_0040ace0();

        node = node->unk04;
    }

    return 0;
}

// @f3 0x0047acf0 (community match, verified in this file)
#include <new>
void* __cdecl FUN_0089eb90(unsigned int bytes);
void __cdecl FUN_0089ec10(void* memory);
struct FUN_00af2240
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
    FUN_00af2240();
    static void* operator new(size_t bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
};
class TraversalNode;
class TraversalObject
{
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual TraversalNode* AsNode();
    virtual void Slot10();
    virtual void Slot14();
    virtual void* AsGeometry();
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
    int unk9C;
    void* FUN_00826590(unsigned int kind);
    void FUN_004236f0(FUN_00af2240* data);
};
class TraversalNode : public TraversalObject
{
public:
    TraversalObject** children;
    unsigned short capacity;
    unsigned short count;
};
// pdb: AddNoLightingPropertyRecurse | GlobalFunc.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apObject
void FUN_0047acf0(TraversalObject* object)
{
    if (object->AsGeometry() && !object->FUN_00826590(3))
        object->FUN_004236f0(new FUN_00af2240);
    TraversalNode* node = object->AsNode();
    if (node)
    {
        for (unsigned int index = 0; index < node->count; ++index)
        {
            TraversalObject* child = node->children[index];
            if (child)
                FUN_0047acf0(child);
        }
    }
}

// @f3 0x0047d050 (community match, verified in this file)
class TESBoundObject {
public:
    virtual ~TESBoundObject();
};

class TESUsesForm {
public:
    virtual ~TESUsesForm();
    unsigned char usesType;
};

struct UsesState7d {
    bool IsSet();
};

struct UsesRef7d {
    UsesState7d** state;
    int unk04;
    TESBoundObject* object;

    int FUN_0047d050();
};

int UsesRef7d::FUN_0047d050()
{
    TESUsesForm* uses = dynamic_cast<TESUsesForm*>(object);
    if (uses) {
        UsesState7d* s;
        if (state && (s = *state) != 0) {
            if (s->IsSet())
                return s->IsSet();
        } else {
            return uses->usesType;
        }
    }
    return -1;
}

// @f3 0x0047f9c0 (community match, verified in this file)
struct ItemNodeM
{
    void* item;
    ItemNodeM* next;
};

struct GroupM
{
    ItemNodeM* items00;
    int unk04;
    int key08;
};

struct GroupNodeM
{
    GroupM* group;
    GroupNodeM* next;
};

struct GroupListM
{
    GroupNodeM* head00;
    int FUN_0047f9c0(int key, void* item);
};

// pdb: InventoryChanges::GetExtraDataListIndexForItem | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject, apExtra
int GroupListM::FUN_0047f9c0(int key, void* item)
{
    if (key && item && head00)
    {
        GroupNodeM* node = head00;
        do
        {
            GroupM* group = node->group;
            node = node->next;
            if (group && group->key08 == key)
            {
                int index = 0;
                for (ItemNodeM* it = group->items00; it; it = it->next)
                {
                    if (it->item && it->item == item)
                        return index;
                    index++;
                }
                return -1;
            }
        } while (node);
        return -1;
    }
    return -1;
}

// @f3 0x00475080 (community match, verified in this file)
struct ShortPair475080 {
	short unk00;
	short unk02;

	ShortPair475080* FUN_00475080(const ShortPair475080* other);
};

// pdb: Date::Date | Date.obj | fnv360_0822_retail, call_gap, low
// pdb params: aDate
ShortPair475080* ShortPair475080::FUN_00475080(const ShortPair475080* other)
{
	unk00 = other->unk00;
	unk02 = other->unk02;
	return this;
}

// @f3 0x004750e0 (community match, verified in this file)
extern unsigned short g_daysInMonth50e0[12];
// pdb: Date::CalculateDate | Date.obj | fnv360_0822_retail, call_seq, medium
// pdb params: asDay, asMonth
unsigned short FUN_004750e0(unsigned short day, unsigned short month) {
    unsigned short d = day;
    unsigned short m = month;
    if (month > 12)
        m = 11;
    if (day >= g_daysInMonth50e0[m])
        d = g_daysInMonth50e0[m] - 1;
    day = d;
    for (int i = 0; i < m; i++)
        day += g_daysInMonth50e0[i];
    return day;
}

// @f3 0x0047e910 (community match, verified in this file)
namespace f3m_0047e910 {
class TESBoundObject {
public:
    virtual ~TESBoundObject();
};

class TESLeveledList {
public:
    virtual ~TESLeveledList();
};

class TESLevItem : public TESBoundObject, public TESLeveledList {
public:
    virtual ~TESLevItem();
};

struct ContainerEntry910 {
    int count;
    TESBoundObject* form;
};

struct ContainerNode910 {
    ContainerEntry910* item;
    ContainerNode910* next;
};

struct Container910 {
    int unk00;
    ContainerNode910 list;
};

struct BaseForm910 {
    Container910* FUN_004e66c0();
};

struct ExtraList910 {
    int FUN_0040c2a0();
};

struct ExtraNode910 {
    ExtraList910* item;
    ExtraNode910* next;
};

struct InventoryEntry910 {
    ExtraNode910* extraLists;
    int countDelta;
    void* form;
};

struct InventoryNode910 {
    InventoryEntry910* item;
    InventoryNode910* next;
};

struct InventoryOwner910 {
    InventoryNode910* entries;
    BaseForm910* baseForm;
    void* FUN_0047e910(TESLevItem* levItem);
};

// pdb: InventoryChanges::GetLeveledCalculatedBaseObject | InventoryChanges.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apLevelItem
void* InventoryOwner910::FUN_0047e910(TESLevItem* levItem) {
    void* result = 0;
    if (levItem) {
        Container910* container = baseForm ? baseForm->FUN_004e66c0() : 0;
        int index = 0;
        for (ContainerNode910* node = &container->list; node; node = node->next) {
            if (!node->next && !node->item)
                break;
            TESLevItem* entryItem = dynamic_cast<TESLevItem*>(node->item->form);
            if (entryItem) {
                if (entryItem == levItem)
                    break;
                index++;
            }
        }
        for (InventoryNode910* entryNode = entries; entryNode; entryNode = entryNode->next) {
            InventoryEntry910* entry = entryNode->item;
            if (!entry)
                break;
            for (ExtraNode910* extraNode = entry->extraLists; extraNode; extraNode = extraNode->next) {
                ExtraList910* extra = extraNode->item;
                if (!extra)
                    break;
                if (extra->FUN_0040c2a0() == index) {
                    result = entry->form;
                    break;
                }
            }
        }
    }
    return result;
}
}   // namespace f3m_0047e910

// @f3 0x00475850 (community match, verified in this file)
// pdb: IsAnInteger | GlobalFunc.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: ActorValue::GetActorValueIndex)
// pdb params: str
int FUN_00475850(const char* text)
{
    char first = *text++;
    if ((first >= '0' && first <= '9') || first == '-') {
        char c = *text;
        if (c != 0 || first != '-') {
            for (text++; c != 0; c = *text++) {
                if ((unsigned char)(c - '0') > 9)
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}

// @f3 0x0046c090 (community match, verified in this file)
struct FNV_0046c090_Obj {
    float unk00;
    float unk04;
    float unk08;

    float FUN_0046c090();
};

// pdb: BGSSaveLoadManager::LoadMostRecentSaveGame | BGSSaveLoadManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
float FNV_0046c090_Obj::FUN_0046c090() {
    return unk04 * unk04 + unk00 * unk00 + unk08 * unk08;
}

// @f3 0x0047d200 (community match, verified in this file)
struct FUN_0047d200_Object {
    int unk00;
    int FUN_0040acc0();
    void FUN_0040b3d0(int value);
};

struct FUN_0047d200_Holder {
    FUN_0047d200_Object** unk00;
    void FUN_0047d200(int value);
};

// pdb: ItemChange::SetPoison | InventoryChanges.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apPoison
void __thiscall FUN_0047d200_Holder::FUN_0047d200(int value) {
    FUN_0047d200_Object** objects = unk00;
    if (objects != 0) {
        FUN_0047d200_Object* object = *objects;
        if (object != 0 && object->FUN_0040acc0() == 0) {
            object->FUN_0040b3d0(value);
        }
    }
}

// @f3 0x00475740 (community match, verified in this file)
float __cdecl FUN_00475740(float param_1, float param_2, float param_3,
                           float param_4, float param_5)
{
    return (param_2 - param_1) *
           ((param_5 - param_3) / (param_4 - param_3)) +
           param_1;
}

// @f3 0x00475970 (community match, verified in this file)
#include <math.h>

// pdb: GetUnclampedZAngleFromVector | GlobalFunc.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: NiPoint3::GetUnclampedZAngleFromVector)
// pdb params: aDirection
float FUN_00475970(const float* vec)
{
    float angle;
    if (vec[1] != 0.0f) {
        angle = atan(vec[0] / vec[1]);
        if (vec[1] < 0.0f)
            angle = angle + 3.1415927410125732;
    } else if (vec[0] > 0.0f) {
        angle = 1.5707964f;
    } else {
        angle = 4.712389f;
    }
    return angle;
}

// @f3 0x0047d120 (community match, verified in this file)
int FUN_0045bd90(void* form);
float FUN_005844d0(float a, float b);
float FUN_0047ca30(float value, float step);

struct Owner_d120 {
    int unk00;
    int unk04;
    void* form;
    float FUN_0047cf30(int mode);
    float FUN_0047d120();
};

float Owner_d120::FUN_0047d120()
{
    return FUN_0047ca30(FUN_005844d0((float)FUN_0045bd90(form), FUN_0047cf30(1)), 0.1f);
}

// @f3 0x004751a0 (community match, verified in this file)
short FUN_004750e0(int first, int second);

struct Pair4751
{
    short unk00;
    short unk02;
    Pair4751* FUN_004751a0(int first, int second, short extra);
};

// pdb: Date::Date | Date.obj | fnv360_0822_retail, call_seq, medium
// pdb params: asDay, asMonth, asYear
Pair4751* Pair4751::FUN_004751a0(int first, int second, short extra)
{
    unk00 = FUN_004750e0(first, second);
    unk02 = extra;
    return this;
}

// @f3 0x00477790 (community match, verified in this file)
class NiPoint3
{
public:
    float x, y, z;

    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
    NiPoint3 operator-() const { return NiPoint3(-x, -y, -z); }
    NiPoint3 operator*(float fScalar) const { return NiPoint3(fScalar * x, fScalar * y, fScalar * z); }
};

inline NiPoint3 operator*(float fScalar, const NiPoint3& kPt)
{
    return NiPoint3(fScalar * kPt.x, fScalar * kPt.y, fScalar * kPt.z);
}

class NiMatrix3
{
public:
    float m_pEntry[3][3];

    NiMatrix3 FUN_0044af40() const;

    NiPoint3 operator*(const NiPoint3& kPt) const
    {
        return NiPoint3(
            m_pEntry[0][0] * kPt.x + m_pEntry[0][1] * kPt.y + m_pEntry[0][2] * kPt.z,
            m_pEntry[1][0] * kPt.x + m_pEntry[1][1] * kPt.y + m_pEntry[1][2] * kPt.z,
            m_pEntry[2][0] * kPt.x + m_pEntry[2][1] * kPt.y + m_pEntry[2][2] * kPt.z);
    }
};

class NiTransform
{
public:
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;

    void FUN_00477790(NiTransform& kDest) const;
};

void NiTransform::FUN_00477790(NiTransform& kDest) const
{
    kDest.m_Rotate = m_Rotate.FUN_0044af40();
    kDest.m_fScale = 1.0f / m_fScale;
    kDest.m_Translate = kDest.m_fScale * (kDest.m_Rotate * -m_Translate);
}

// @f3 0x00464600 (community match, verified in this file)
#include <stdio.h>

struct NameNode464600
{
    const char* name;
    NameNode464600* next;
};

struct AnimLookup464600
{
    void* Find(const char* path);
};
extern AnimLookup464600* g_animLookup464600;

struct AnimHolder464600
{
    bool GetFlag45cc40();
    void AddAnim461a70(void* anim, bool flag);
    void FUN_00464600(NameNode464600* list, const char* folder);
};

// pdb: Animation::AddSpecialAnimations | Animation.obj | fnv360_0822_retail, call_gap, low
// pdb params: apFileList, apPath
void AnimHolder464600::FUN_00464600(NameNode464600* list, const char* folder)
{
    for (NameNode464600* node = list; node; node = node->next)
    {
        char path[260];
        sprintf_s(path, 260, "%s\\%s\\%s", folder, "SpecialAnims", node->name);
        void* anim = g_animLookup464600->Find(path);
        bool flag = GetFlag45cc40();
        if (anim)
            AddAnim461a70(anim, flag);
    }
}

// @f3 0x00479b00 (community match, verified in this file)
class Heap479b00 {
public:
    void* FUN_0086b930(unsigned int size);  // allocate
};
extern Heap479b00 DAT_01090a78;  // game heap

// pdb: NiTMap<unsigned int,VertexDist>::NewItem | GlobalFunc.obj | fnv360_0822_retail, vtable, medium
void* FUN_00479b00()
{
    return DAT_01090a78.FUN_0086b930(0x14);
}

// @f3 0x0047ce90 (community match, verified in this file)
class Item47ce90 {
public:
    bool ExtraDataList_HasLeveledItem();
};

struct Node47ce90 {
    Item47ce90* item;   // 00
    Node47ce90* next;   // 04
};

class List47ce90 {
public:
    Node47ce90* first;  // 00

    bool FUN_0047ce90();
};

// pdb: BSSimpleList<ContainerObject *>::`scalar deleting destructor' | TESContainer.obj | fnv360_0822_debug, call_gap_sim, low
bool List47ce90::FUN_0047ce90()
{
    for (Node47ce90* node = first; node; node = node->next) {
        if (!node->item)
            break;
        if (node->item->ExtraDataList_HasLeveledItem())
            return true;
    }
    return false;
}

// @f3 0x00477880 (community match, verified in this file)
struct Vec3_477880
{
    float x;
    float y;
    float z;
};

struct Row_477880
{
    float x;
    float y;
    float z;
    float w;
};

struct Matrix_477880
{
    Row_477880 r0;
    Row_477880 r1;
    Row_477880 r2;
};

struct Vec4_477880
{
    float x;
    float y;
    float z;
    float w;

    void FUN_00477880(const Matrix_477880& m, const Vec3_477880& v);
};

// pdb: hkpBoxBoxCollisionDetection::debugCheckManifold | hkpBoxBoxCollisionDetection.obj | fnv360_0822_debug, objrun_prop, low
// pdb params: manifold, result
void Vec4_477880::FUN_00477880(const Matrix_477880& m, const Vec3_477880& v)
{
    float px = v.x;
    float py = v.y;
    float pz = v.z;
    x = m.r0.x * px + m.r0.y * py + m.r0.z * pz;
    y = m.r1.x * px + m.r1.y * py + m.r1.z * pz;
    z = m.r2.x * px + m.r2.y * py + m.r2.z * pz;
    w = 0.0f;
}

// @f3 0x0046c350 (community match, verified in this file)
struct Quad46c350
{
    float a;
    float b;
    float c;
    float d;

    void FUN_0046c350();
};

// pdb: BSOcclusionShape::QAdjustedViewPlanes | BSOcclusionPlane.obj | tesv_win, objrun_open, low
void Quad46c350::FUN_0046c350()
{
    d = c = b = a = 0.0f;
}

// @f3 0x00468fb0 (community match, verified in this file)
class StartMenu
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
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
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned int flags1a0;
};

extern StartMenu* DAT_010770ac;

int __cdecl FUN_00468fb0()
{
    if (DAT_010770ac && (DAT_010770ac->flags1a0 & 1))
        return 1;
    return 0;
}

// @f3 0x0046ffe0 (community match, verified in this file)
class RefObject {
public:
    virtual void Unk00();
    virtual void DeleteThis();
    long references;
    void IncRefCount() { InterlockedIncrement(&references); }
    void DecRefCount() {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
};
class OwnedList {
public:
    void* item;
    OwnedList* next;
    void FUN_006c8220();
    ~OwnedList() { FUN_006c8220(); }
};
class FUN_0046ffe0 {
public:
    NiPointer<RefObject> object;
    unsigned int unk04;
    OwnedList list;
    ~FUN_0046ffe0();
};
// pdb: BSSimpleList<TESForm *>::RemoveAll | BGSTextureUseMap.obj | fnv360_0721_beta, call_dedup, low
FUN_0046ffe0::~FUN_0046ffe0() {
    list.FUN_006c8220();
}

// @f3 0x004781c0 (community match, verified in this file)
class SceneNode;
class SceneObject {
public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual SceneNode* AsNode();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01c();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02c();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03c();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04c();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05c();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06c();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07c();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08c();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09c();
    virtual void Unk0a0();
    virtual void Unk0a4();
    virtual void Unk0a8();
    virtual void Unk0ac();
    virtual void Unk0b0();
    virtual void Unk0b4();
    virtual void Unk0b8();
    virtual void Unk0bc();
    virtual void Unk0c0();
    virtual void Unk0c4();
    virtual void Unk0c8();
    virtual void Unk0cc();
    virtual void Unk0d0();
    virtual void Unk0d4();
    virtual void Unk0d8();
    virtual void Unk0dc();
    virtual void Unk0e0();
    virtual void Unk0e4();
    virtual void Unk0e8();
    virtual void Unk0ec();
    unsigned int references;
    const char* name;
};
class SceneNode : public SceneObject {
public:
    virtual void RemoveChild(unsigned int index);
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
    SceneObject** children;
    unsigned short capacity, count;
};
extern const char DAT_00dbfdb4[];
extern const char DAT_00dc0a8c[];
int FUN_00c009eb(const char* first, const char* second);
int FUN_00c020cb(const char* first, const char* second, unsigned int length);
// pdb: RemoveScabard | GlobalFunc.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: RemoveScabbard)
// pdb params: apNode
bool FUN_004781c0(SceneNode* node) {
    if (node) {
        for (unsigned int i = 0; i < node->count; ++i) {
            SceneObject* child = node->children[i];
            const char* name = child ? child->name : 0;
            if (name) {
                if (FUN_00c009eb(name, DAT_00dbfdb4) == 0) {
                    node->RemoveChild(i);
                    return true;
                }
                if (FUN_00c020cb(name, DAT_00dc0a8c, 9) == 0)
                    return FUN_004781c0(child->AsNode());
            }
        }
    }
    return false;
}

// @f3 0x0047b2f0 (community match, verified in this file)
struct GameStateB47b2f0 {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    char unk5A8;
    bool flag5A9;
};

extern GameStateB47b2f0* DAT_0106cdcc;

void TESObjectCELL_KillStatics();

class Updater47b2f0 {
public:
    void FUN_007f97f0();
    void GridCellArray_KillAll();
};

// pdb: GridCellArray::KillAll | GridCell.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
void Updater47b2f0::GridCellArray_KillAll()
{
    FUN_007f97f0();
    if (DAT_0106cdcc->flag5A9)
        TESObjectCELL_KillStatics();
}

// @f3 0x0047b3c0 (community match, verified in this file)
class Matrix47b3c0
{
public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int size0C;
    int* data10;
    int unk14;
    int unk18;
    int unk1C;
    bool valid20;

    int* GetCell(unsigned int row, unsigned int col)
    {
        if (row < size0C && col < size0C)
            return &data10[row * size0C + col];
        return 0;
    }
    void GridCellArray_ClearItem(unsigned int row, unsigned int col);
};

// pdb: GridCellArray::ClearItem | GridCell.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
void Matrix47b3c0::GridCellArray_ClearItem(unsigned int row, unsigned int col)
{
    *GetCell(row, col) = 0;
    valid20 = false;
}

// @f3 0x004788d0 (community match, verified in this file)
struct RTTI4788d0
{
    const char* name;
    const RTTI4788d0* baseRTTI;
};

extern const RTTI4788d0 DAT_0116fd98;

class Object4788d0
{
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual const RTTI4788d0* GetRTTI() const;
};

inline bool IsKindOf4788d0(const RTTI4788d0* rtti, const Object4788d0* object)
{
    for (const RTTI4788d0* current = object->GetRTTI(); current; current = current->baseRTTI)
    {
        if (current == rtti)
            return true;
    }
    return false;
}

class Property4788d0 : public Object4788d0
{
public:
    void FUN_00aea960(int value);
};

class Node4788d0;

class AVObject4788d0
{
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual Node4788d0* AsNode();
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
    int unk9C;
    Object4788d0* FUN_00826590(unsigned int kind);
};

class Node4788d0 : public AVObject4788d0
{
public:
    AVObject4788d0** children;   // A0
    unsigned short capacity;     // A4
    unsigned short count;        // A6
};

// pdb: UnTintScenegraph | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRoot
void FUN_004788d0(AVObject4788d0* object)
{
    Object4788d0* prop = object->FUN_00826590(3);
    if (prop)
    {
        Property4788d0* typed = IsKindOf4788d0(&DAT_0116fd98, prop) ? (Property4788d0*)prop : 0;
        if (typed)
            typed->FUN_00aea960(0);
    }
    Node4788d0* node = object->AsNode();
    if (node)
    {
        for (unsigned int index = 0; index < node->count; ++index)
        {
            AVObject4788d0* child = node->children[index];
            if (child)
                FUN_004788d0(child);
        }
    }
}

// @f3 0x0047e210 (community match, verified in this file)
struct ExtraList47e210
{
    bool ExtraDataList_GetWorn(int flag);
};

struct InnerNode47e210
{
    ExtraList47e210* item;
    InnerNode47e210* next;
};

struct Form47e210
{
    int unk00;
    unsigned char typeID;   // 04
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    unsigned char unk178;
    unsigned char unk179;
    unsigned char flags17A;  // 17A
};

struct Entry47e210
{
    InnerNode47e210* extras;   // 00
    int unk04;
    Form47e210* form;          // 08
};

struct OuterNode47e210
{
    Entry47e210* item;
    OuterNode47e210* next;
};

class Container47e210
{
public:
    OuterNode47e210* entries;   // 00

    bool FUN_0047e210();
};

// pdb: InventoryChanges::WearingVoiceModulateItem | InventoryChanges.obj | fnv360_0822_retail, caller_sim, low
bool Container47e210::FUN_0047e210()
{
    bool found = false;
    for (OuterNode47e210* node = entries; node && node->item; node = node->next)
    {
        Entry47e210* entry = node->item;
        Form47e210* form = entry->form;
        if (form->typeID == 0x18 && !found)
        {
            for (InnerNode47e210* inner = entry->extras; inner && inner->item && !found; inner = inner->next)
            {
                if (inner->item->ExtraDataList_GetWorn(0) && (form->flags17A & 1))
                    found = true;
            }
        }
    }
    return found;
}

// @f3 0x0047cf00 (community match, verified in this file)
struct Extra47cf00
{
    bool FUN_0040bfc0();
};

struct Node47cf00
{
    Extra47cf00* item;
    Node47cf00* next;
};

class List47cf00
{
public:
    Node47cf00* head;   // 00

    bool FUN_0047cf00();
};

bool List47cf00::FUN_0047cf00()
{
    for (Node47cf00* node = head; node && node->item; node = node->next)
    {
        if (node->item->FUN_0040bfc0())
            return true;
    }
    return false;
}

// @f3 0x004700e0 (community match, verified in this file)
namespace f3m_004700e0 {
struct AeHeap
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern AeHeap DAT_01090a78;

struct AFLinkKey;
struct AFLinkTarget;

struct AFTargetNode {
    AFLinkTarget* item;
    AFTargetNode* next;
    AFTargetNode() : item(0), next(0) {}
    void FUN_0049fac0(AFLinkTarget* const& data);
};

struct AFLinkEntry {
    AFLinkKey* key;
    int value;
    AFTargetNode targets;

    AFLinkEntry() : key(0) {}
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    void FUN_008e9650(AFLinkKey* linkKey);
    AFTargetNode* Head() { return &targets; }
};

struct AFLinkMap {
    bool FUN_00bea7b0(AFLinkKey* key, AFLinkEntry*& entry);
    void FUN_00880f70(AFLinkKey* key, AFLinkEntry* entry);
};

struct AFLinkRegistry {
    int unk00;
    AFLinkMap map;
    void FUN_004700e0(AFLinkKey* key, int value, AFLinkTarget* target);
};

// pdb: BGSTextureUseMap::AddTexUse | BGSTextureUseMap.obj | fnv360_0721_beta, objrun, medium
// pdb params: apTex, aulMemorySize, apForm
void AFLinkRegistry::FUN_004700e0(AFLinkKey* key, int value, AFLinkTarget* target)
{
    if (!key || !target)
        return;
    AFLinkEntry* found = 0;
    AFLinkEntry* entry;
    if (map.FUN_00bea7b0(key, found) && found) {
        entry = found;
    } else {
        entry = new AFLinkEntry;
        map.FUN_00880f70(key, entry);
        entry->FUN_008e9650(key);
        entry->value = value;
    }
    for (AFTargetNode* node = entry->Head(); node; node = node->next) {
        if (node->item == *(AFLinkTarget* volatile*)&target)
            return;
    }
    entry->targets.FUN_0049fac0(target);
}
}   // namespace f3m_004700e0

// @f3 0x0046d790 (community match, verified in this file)
struct ColorWords { unsigned int red, green, blue, alpha; };
class ColorBuffer {
public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    ColorWords* pixels;
    void FUN_008313b0(unsigned int flags);
};
struct ColorSurface {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    ColorBuffer* buffer;
};
class ColorOwner {
public:
    unsigned int unk00, unk04;
    ColorWords color;
    unsigned int unk18, unk1C, unk20;
    ColorSurface* surface;
    void FUN_0046d790(const ColorWords* source);
};
// pdb: BGSPrimitiveSphere::SetColor | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: aColor
void ColorOwner::FUN_0046d790(const ColorWords* source) {
    color = *source;
    if (surface) {
        ColorBuffer* buffer = surface->buffer;
        ColorWords* pixels = buffer->pixels;
        for (unsigned int i = 0; i < 112; ++i)
            pixels[i] = color;
        buffer->FUN_008313b0(4);
    }
}

// @f3 0x0046c1d0 (community match, verified in this file)
// pdb: BSOcclusionPlane::QDebugGeomShapeSize | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
int __cdecl FUN_0046c1d0()
{
    return 0x1e;
}

// @f3 0x0046c650 (community match, verified in this file)
// pdb: bhkLiquidAction::QCinfoSize | Explosion.obj | fnv360_0822_retail, vtable, medium
int __cdecl FUN_0046c650()
{
    return 0x18;
}

// @f3 0x0046c660 (community match, verified in this file)
// pdb: BSMultiBoundAABB::QDebugGeomShapeSize | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
int __cdecl FUN_0046c660()
{
    return 0x24;
}

// @f3 0x00476720 (community match, verified in this file)
struct RadiusVector3 {
    float x, y, z;
    float SquaredLength() const { return x*x + y*y + z*z; }
};
// pdb: LengthCheck | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aVector, afCompLength
int FUN_00476720(const RadiusVector3* vector, float radius) {
    float length = vector->SquaredLength();
    radius *= radius;
    if (length < radius)
        return -1;
    if (length > radius)
        return 1;
    return 0;
}

// @f3 0x0047af00 (community match, verified in this file)
// pdb: GridArray::Init | GridArray.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __fastcall GridArray_Init(int* ecx)
{
    ecx[2] = 0xffffd8f0;
    ecx[1] = 0xffffd8f0;
}

// @f3 0x00468d00 (community match, verified in this file)
#include <math.h>

inline float FUN_00468d00_NiSqrt(float fValue)
{
    return float(sqrt(fValue));
}

struct FUN_00468d00_Vec {
    float x;
    float y;
    float z;
    float Length() const { return FUN_00468d00_NiSqrt(x * x + y * y + z * z); }
    void FUN_00468d00();
};

// pdb: NiSinCos | TESObjectWEAP.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: NiPoint3::Unitize)
// pdb params: fRadians, fSin, fCos
// The body is Gamebryo's NiPoint3::Unitize (the Skyrim link).
void FUN_00468d00_Vec::FUN_00468d00() {
    float fLength = Length();
    if (fLength > 1e-06f) {
        float fRecip = 1.0f / fLength;
        x *= fRecip;
        y *= fRecip;
        z *= fRecip;
    } else {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}

// @f3 0x0047ce40 (community match, verified in this file)
struct Entry_0047ce40 {
    bool __thiscall FUN_0040c080(int value);
    bool __thiscall ExtraDataList_GetWorn(int value);
    short __thiscall FUN_0040ac80();
};

struct Node_0047ce40 {
    Entry_0047ce40* item;
    Node_0047ce40* next;
};

struct Owner_0047ce40 {
    Node_0047ce40* node;

    int __thiscall FUN_0047ce40(char flag);
};

// pdb: ItemChange::GetExtraTotalCount | InventoryChanges.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: ItemChange::GetExtraTotalDefaultCount)
// pdb params: abWornIgnore
int __thiscall Owner_0047ce40::FUN_0047ce40(char flag) {
    int total = 0;
    Node_0047ce40* current = node;

    while (current != 0 && current->item != 0) {
        Entry_0047ce40* entry = current->item;

        if (!entry->FUN_0040c080(0)) {
            if (flag != 0 || !entry->ExtraDataList_GetWorn(0)) {
                total += entry->FUN_0040ac80();
            }
        }

        current = current->next;
    }

    return total;
}

// @f3 0x0047b940 (community match, verified in this file)
struct Elem47 {
    unsigned char pad[0x26];
    unsigned char kind;
    void FUN_004e0100(bool flag);
};
struct G47 {
    unsigned char pad[0x1e];
    unsigned char flag;
};
struct Owner47 {
    unsigned char pad[0x0c];
    unsigned int count;
    Elem47** ptr;
    void FUN_0047b940();
};
extern void* DAT_01071564;

// pdb: GridCellArray::ToggleCollisionGeometry | GridCell.obj | fnv360_0822_retail, caller_sim, low
void Owner47::FUN_0047b940() {
    G47* g = (G47*)DAT_01071564;
    if (!g) return;
    bool b = (g->flag == 0);
    for (unsigned int row = 0; row < count; row++) {
        for (unsigned int col = 0; col < count; col++) {
            Elem47* e = *((row < count && col < count) ? &ptr[row * count + col] : (Elem47**)0);
            if (e && e->kind == 6)
                e->FUN_004e0100(b);
        }
    }
}

// @f3 0x004752c0 (community match, verified in this file)
struct Vec3_4752c0 { float x, y, z; };
struct Mat_4752c0 {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vec3_4752c0 FUN_004752c0(const Vec3_4752c0& in);
};
// pdb: NiMatrix3::operator* | InventoryChanges.obj | tesv_win, call_seq, medium
Vec3_4752c0 Mat_4752c0::FUN_004752c0(const Vec3_4752c0& in) {
    Vec3_4752c0 out;
    out.x = m00 * in.x + m01 * in.y + m02 * in.z;
    out.y = m10 * in.x + m11 * in.y + m12 * in.z;
    out.z = m20 * in.x + m21 * in.y + m22 * in.z;
    return out;
}

// @f3 0x004768c0 (community match, verified in this file)
struct S768 {
    int a;
    int b;
    int c;
    float f;
};
bool __cdecl FUN_00476780(S768* s, void* p);
// pdb: PointInFrustum | GlobalFunc.obj | fnv360_0822_retail, caller, medium
// pdb params: aTestLocation, apCamera, afDistance
bool __cdecl FUN_004768c0(int a1, int a2, int a3, void* p4, float a5) {
    if (!p4) return false;
    S768 s;
    s.a = a1;
    s.b = a2;
    s.c = a3;
    s.f = a5;
    return FUN_00476780(&s, p4);
}

// @f3 0x004782c0 (community match, verified in this file)
struct FUN_004782c0_Node {
    int unk00;
    int unk04;
};

struct FUN_004782c0_Children {
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
    int unk9C;
    int** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

class FUN_004782c0_Obj {
public:
    virtual void vf00() {}
    virtual void vf04() {}
    virtual FUN_004782c0_Node* vf08() { return 0; }
    virtual FUN_004782c0_Children* vf0c() { return 0; }
};

extern int DAT_0116ebd8;

bool __cdecl FUN_004782c0(int* param_1);

// pdb: HasParticleSystem | GlobalFunc.obj | fnv360_0822_retail, callee_sim, low
// pdb params: apObj
bool __cdecl FUN_004782c0(int* param_1) {
    if (param_1 == 0) {
        return false;
    }

    FUN_004782c0_Node* node =
        reinterpret_cast<FUN_004782c0_Obj*>(param_1)->vf08();

    while (node != 0) {
        if (node == reinterpret_cast<FUN_004782c0_Node*>(&DAT_0116ebd8)) {
            return true;
        }
        node = reinterpret_cast<FUN_004782c0_Node*>(node->unk04);
    }

    FUN_004782c0_Children* children =
        reinterpret_cast<FUN_004782c0_Obj*>(param_1)->vf0c();

    if (children != 0) {
        for (unsigned int index = 0; index < children->unkA6; ++index) {
            int* child = children->unkA0[index];
            if (FUN_004782c0(child)) {
                return true;
            }
        }
    }

    return false;
}

// @f3 0x00478960 (community match, verified in this file)
struct TypeInfo {
    const char *name;
    const TypeInfo *base;
};

extern const TypeInfo DAT_010f31e4;
extern const TypeInfo DAT_0116eeec;

int __cdecl FUN_00404050(const char *s1, const char *s2);

// pdb: GetCollisionObjectCount | GlobalFunc.obj | fnv360_0822_retail, objrun, medium
void FUN_00478960(void *a1, void *a2)
{
    if ((*(unsigned char *)((char *)a2 + 0x18) & 1) && a1)
    {
        for (const TypeInfo *t = (const TypeInfo *)((int (__thiscall *)(void *))(*(void ***)a1)[2])(a1); t; t = t->base)
        {
            if (t == &DAT_010f31e4)
                return;
        }
    }
    if (*(unsigned char *)((char *)a2 + 0x18) & 2)
    {
        void *p = *(void **)((char *)a1 + 8);
        if (p)
        {
            for (const TypeInfo *t = (const TypeInfo *)((int (__thiscall *)(void *))(*(void ***)p)[2])(p); t; t = t->base)
            {
                if (t == &DAT_0116eeec)
                    return;
            }
        }
        if (*(unsigned char *)((char *)a2 + 0x18) & 2)
        {
            void *p2 = *(void **)((char *)a1 + 8);
            if (p2)
            {
                const char *s = *(const char **)((char *)p2 + 8);
                if (s && FUN_00404050(s, "Arrow") == 0)
                    return;
            }
        }
    }
    (*(int *)((char *)a2 + 0xc))++;
}

// @f3 0x0047f880 (community match, verified in this file)
struct FUN_0047deb0_owner;
struct Node_47f880 {
    FUN_0047deb0_owner* unk00;
    Node_47f880* unk04;
};
struct Owner_47f880 {
    Node_47f880* unk00;
    void FUN_0047f880();
};
void Owner_47f880::FUN_0047f880() {
    Node_47f880* n = unk00;
    while (n) {
        if (n->unk04 == 0) {
            if (n->unk00 == 0) {
                break;
            }
        }
        FUN_0047deb0_owner* o = n->unk00;
        if (o) {
            o->FUN_0047deb0();
        }
        n = n->unk04;
    }
}

// @f3 0x0046c300 (community match, verified in this file)
class Obj46c300
{
public:
    char pad_00[0x18];
    float m_18;
};
struct Pt46c300 { float x, y, z; float SqrLength() const { return x * x + y * y + z * z; } };
// pdb: BGSPrimitiveSphere::IsInside | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: aPoint
bool __fastcall FUN_0046c300(const Obj46c300* self, int, const Pt46c300* p)
{
    return self->m_18 * self->m_18 > p->SqrLength();
}

// @f3 0x00474b30 (community match, verified in this file)
struct FUN_00474b30_Node {
    int* value;
    FUN_00474b30_Node* next;

    int* __thiscall BSClonePools_RequestClone(int key);
};

// pdb: BSClonePools::RequestClone | BSClonePool.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
int* __thiscall FUN_00474b30_Node::BSClonePools_RequestClone(int key) {
    int* found = 0;

    for (FUN_00474b30_Node* current = this; current; current = current->next) {
        if (found)
            break;

        FUN_00474b30_Node* next = current->next;
        if (!next && !current->value)
            break;

        int* value = current->value;
        if (value && *value == key)
            found = value;
    }

    int* result = 0;
    if (found) {
        int* currentEntry = found + 1;

        do {
            if (!currentEntry)
                break;

            FUN_00474b30_Node* next =
                reinterpret_cast<FUN_00474b30_Node*>(currentEntry[1]);
            if (!next && !currentEntry[0])
                break;

            int* value = reinterpret_cast<int*>(currentEntry[0]);
            if (value && value[1] == 1)
                result = value;

            currentEntry = reinterpret_cast<int*>(next);
        } while (!result);
    }

    return result;
}

// @f3 0x0047cbf0 (community match, verified in this file)
namespace f3m_0047cbf0 {
struct Singleton47cbf0 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void DeleteThis(bool free);
};
extern Singleton47cbf0* DAT_0106ea24;
// pdb: InventoryChanges::KillTempRef | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
void FUN_0047cbf0()
{
    if (DAT_0106ea24)
        DAT_0106ea24->DeleteThis(true);
    DAT_0106ea24 = 0;
}
}

// @f3 0x004751d0 (community match, verified in this file)
namespace f3m_004751d0 {
struct Pair4751d0 {
    int first;
    int second;
};
struct Key4751d0 {
    unsigned short id;
};
Pair4751d0 __cdecl FUN_00475140(unsigned int id);
// pdb: Date::GetDay | Date.obj | fnv360_0822_retail, objrun_prop, low
int __fastcall FUN_004751d0(Key4751d0* key)
{
    Pair4751d0 pair = FUN_00475140(key->id);
    return pair.second;
}
}

// @f3 0x00475070 (community match, verified in this file)
struct Owner588{unsigned short first,second;Owner588* FUN_00475070();};
// pdb: Date::Date | Date.obj | fnv360_0822_retail, call_seq, high
Owner588* Owner588::FUN_00475070(){first=0;second=0;return this;}

// @f3 0x0047cbe0 (community match, verified in this file)
struct Target591{int FUN_004e66c0();};
struct Owner591{int unk00;Target591* target;int FUN_0047cbe0();};
// pdb: InventoryChanges::GetOriginalContainer | InventoryChanges.obj | fnv360_0822_retail, caller_sim, low
int Owner591::FUN_0047cbe0(){return target?target->FUN_004e66c0():0;}

// @f3 0x0046dd40 (community match, verified in this file)
namespace f3m_0046dd40 {
struct Owner631{void FUN_0046d800(float);void FUN_0046dd40(const float*);};
// pdb: BGSPrimitiveSphere::SetRadii | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: aRadii
void Owner631::FUN_0046dd40(const float* value){FUN_0046d800(*value);}
}   // namespace f3m_0046dd40

// @f3 0x00472200 (community match, verified in this file)
namespace f3m_00472200 {
struct Entry646{int unk00,unk04,unk08,unk0c;};
struct Owner646{
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
    int unk28;    Entry646 entries[16];
    void FUN_00471570(Entry646*);void FUN_00472200(unsigned int);
};
// pdb: BipedAnim::RemovePart | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: aeObj, abClear, aiClearValue
void Owner646::FUN_00472200(unsigned int index){FUN_00471570(&entries[index]);}
}   // namespace f3m_00472200

// @f3 0x004751f0 (community match, verified in this file)
namespace f3m_004751f0 {
struct Result647 {
    unsigned int index;
    unsigned int remainder;
};
Result647 __cdecl FUN_00475140(unsigned short value);
struct Owner647 {
    unsigned short value;
    unsigned int FUN_004751f0();
};
// pdb: Date::GetMonth | Date.obj | fnv360_0822_retail, objrun_prop, low
unsigned int Owner647::FUN_004751f0()
{
    return FUN_00475140(value).index;
}
}   // namespace f3m_004751f0

// @f3 0x00475660 (community match, verified in this file)
namespace f3m_00475660 {
struct RelativeValue648 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char offset;
    int unk14;
    unsigned char tag;
};
// pdb: bhkUnaryAction::GetRTTI | bhkCartTether.obj | tesv_win, objrun_open, low
char* FUN_00475660(RelativeValue648* value)
{
    if (value->tag == 2)
        return reinterpret_cast<char*>(value) + value->offset;
    return 0;
}
}   // namespace f3m_00475660

// @f3 0x00478a50 (community match, verified in this file)
namespace f3m_00478a50 {

class C
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class D
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C* unk10;
};

// pdb: GetHavokWorldObjectCount | GlobalFunc.obj | fnv360_0822_retail, objrun, medium
void FUN_00478a50(D* a1, C* a2)
{
    C* eax = a1->unk10;
    if (eax && eax->unk08)
    {
        a2->unk0C++;
    }
}
}   // namespace f3m_00478a50

// @f3 0x004756c0 (community match, verified in this file)
namespace f3m_004756c0 {
struct Vec4_4756c0
{
    float x;
    float y;
    float z;
    float w;

    Vec4_4756c0* FUN_004756c0(const float* src);
};

Vec4_4756c0* Vec4_4756c0::FUN_004756c0(const float* src)
{
    x = src[0] * 0.1428767293691635;
    y = src[1] * 0.1428767293691635;
    z = src[2] * 0.1428767293691635;
    w = 0.0f;
    return this;
}
}   // namespace f3m_004756c0

// @f3 0x00470740 (community match, verified in this file)
namespace f3m_00470740 {
namespace f3m_00470740 {
struct Slot470740 {
    void* key;
    int unk04;
    int unk08;
    int unk0C;
};
struct FUN_00470740_Obj {
    char unk00[0x2c];
    Slot470740 slots[20];
    Slot470740* FUN_00470740(void* key);
};
// pdb: BipedAnim::FindBipObject | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObj
Slot470740* FUN_00470740_Obj::FUN_00470740(void* key)
{
    if (!key)
        return 0;
    for (int i = 0; i < 20; i++) {
        if (slots[i].key == key)
            return &slots[i];
    }
    return 0;
}
}
}   // namespace f3m_00470740

// @f3 0x00468ec0 (community match, verified in this file)
namespace f3m_00468ec0 {
class FlagSet_468ec0 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20[8];
    bool FUN_00468ec0(unsigned int index);
};

// pdb: BSShaderProperty::GetFlag | BGSDecalManager.obj | fnv360_0721_beta, call_gap, low, conflict (bridge: NiObject::IsExactKindOf)
// pdb params: aiFlag
bool FlagSet_468ec0::FUN_00468ec0(unsigned int index)
{
    return (unk20[index >> 5] & (1u << (index & 0x1F))) > 0;
}
}   // namespace f3m_00468ec0

// @f3 0x0047b740 (community match, verified in this file)
namespace f3m_0047b740 {
namespace f3m_0047b740 {
struct Target {
    void FUN_004cea70(int arg);
};
struct Form {
    char unk00[0x26];
    unsigned char typeID;
    Target* TESObjectCELL_GetLand();
};
struct Grid {
    int unk00;
    int unk04;
    int unk08;
    unsigned int dim;
    Form** cells;
    Form** GetAt(unsigned int x, unsigned int y) {
        if (x < dim && y < dim)
            return &cells[x * dim + y];
        return 0;
    }
    void FUN_0047b740(int arg);
};
// pdb: GridCellArray::ShowLandBorders | GridCell.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: GridCellArray::RunAnimations)
// pdb params: abShow
void Grid::FUN_0047b740(int arg) {
    for (unsigned int x = 0; x < dim; x++) {
        for (unsigned int y = 0; y < dim; y++) {
            Form* form = *GetAt(x, y);
            if (form && form->typeID == 6) {
                Target* t = form->TESObjectCELL_GetLand();
                if (t)
                    t->FUN_004cea70(arg);
            }
        }
    }
}
}
}   // namespace f3m_0047b740

// @f3 0x0046c560 (community match, verified in this file)
namespace f3m_0046c560 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
namespace f3m_0046c560 {
struct RefObj {
    virtual void vf00();
    virtual void DeleteThis();
    volatile long refCount;
};
struct RefPtr {
    RefObj* obj;
    ~RefPtr()
    {
        RefObj* p = obj;
        if (p && InterlockedDecrement(&p->refCount) == 0)
            p->DeleteThis();
    }
};
struct Base {
    char unk000[0x104];
    ~Base();
};
}
using namespace f3m_0046c560;
struct FUN_0046c560 : Base {
    RefPtr unk104;
    ~FUN_0046c560();
};
// pdb: BSPortal::~BSPortal | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
FUN_0046c560::~FUN_0046c560()
{
}
}   // namespace f3m_0046c560

// @f3 0x0046b690 (community match, verified in this file)
struct Mem_46b690 {
    void* Allocate(unsigned int size);
    void Free(void* p);
};
extern Mem_46b690 g_mem_46b690;
void Deallocate(void* p);

class Tab_46b690 {
public:
    static void* operator new(unsigned int size) { return g_mem_46b690.Allocate(size); }
    static void operator delete(void* p) { Deallocate(p); }
    Tab_46b690();
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
    static Tab_46b690* ms_pStringTable;
};

// pdb: BGSDecalManager::GetInstance | BGSDecalManager.obj | fnv360_0822_retail, call_gap, low
Tab_46b690* FUN_0046b690()
{
    if (!Tab_46b690::ms_pStringTable)
        Tab_46b690::ms_pStringTable = new Tab_46b690;
    return Tab_46b690::ms_pStringTable;
}

// @f3 0x0046bff0 (community match, verified in this file)
namespace f3m_0046bff0 {
struct Item {
    int unk00;
    bool done;
    void FUN_0046b830();
    void FUN_00469a50();
};
struct Node { Node* next; Node* prev; Item* data; };
struct List {
    Node* head;
    Node* tail;
    unsigned int count;
    void FUN_005878f0();
    void FUN_00469b60();
    void FUN_00ade560(Node* n);
    static Item*& GetNext(Node*& pos) { Item*& r = pos->data; pos = pos->next; return r; }
    void Remove(Node* n) {
        if (n == head)
            FUN_005878f0();
        else if (n == tail)
            FUN_00469b60();
        else {
            Node* prev = n->prev;
            Node* next = n->next;
            if (prev)
                prev->next = next;
            if (next)
                next->prev = prev;
            FUN_00ade560(n);
            count--;
        }
    }
};
struct Pool { void FUN_0086ba60(Item* p); };
extern Pool DAT_01090a78;
struct Owner {
    char unk00[0x14];
    List list;
    void FUN_0046bff0();
};
// pdb: BGSDecalManager::UpdateDecalEmitters | BGSDecalManager.obj | fnv360_0822_retail, call_seq, medium
void Owner::FUN_0046bff0() {
    Node* n = list.head;
    while (n) {
        Node* cur = n;
        Item* item = List::GetNext(n);
        if (item) {
            item->FUN_0046b830();
            if (item->done) {
                list.Remove(cur);
                item->FUN_00469a50();
                DAT_01090a78.FUN_0086ba60(item);
            }
        }
    }
}
}

// @f3 0x0047b2a0 (community match, verified in this file)
namespace f3m_0047b2a0 {
namespace f3m_0047b2a0 {
struct Cell {
    char unk00[0x26];
    unsigned char type;
};
struct Grid {
    void* vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int size;
    Cell** cells;
    Cell** GetAt(unsigned int x, unsigned int y)
    {
        if (x < size && y < size)
            return &cells[x * size + y];
        return 0;
    }
    bool GridCellArray_GetAttached(unsigned int x, unsigned int y);
};
// pdb: GridCellArray::GetAttached | GridCell.obj | fnv360_0822_retail, call_gap + bridge(call_gap_sim|call_gap) + skyrim(call_gap_sim), high
bool Grid::GridCellArray_GetAttached(unsigned int x, unsigned int y)
{
    Cell* c = *GetAt(x, y);
    if (c)
        return c->type == 6;
    return false;
}
}
}   // namespace f3m_0047b2a0

// @f3 0x0047cda0 (community match, verified in this file)
namespace f3m_0047cda0 {
class Owner_0047cda0 {
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
    unsigned short unk178;
    float FUN_0047cda0();
};

// pdb: TESObjectARMO::GetArmorRating | InventoryChanges.obj | fnv360_0822_debug, call_gap, low
float Owner_0047cda0::FUN_0047cda0()
{
    return (float)(unk178 / 100.0);
}
}   // namespace f3m_0047cda0

// @f3 0x00468ef0 (community match, verified in this file)
namespace f3m_00468ef0 {
namespace f3m_00468ef0 {
struct Obj468ef0 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int type;
};
// pdb: NiPointer<BSTempEffectGeometryDecal>::~NiPointer<BSTempEffectGeometryDecal> | BGSDecalManager.obj | fnv360_0822_debug, call_gap_sim, low
int FUN_00468ef0(Obj468ef0* obj)
{
    if (!obj)
        return 0;
    switch (obj->type) {
    case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11:
        return 1;
    }
    return 0;
}
}
}   // namespace f3m_00468ef0

// @f3 0x004784d0 (community match, verified in this file)
struct NiBound
{
    float x;
    float y;
    float z;
    float radius;
};

extern NiBound g_defaultBound;

bool FUN_00476780(NiBound* bound);

struct BoundOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBound* bound;
};

// pdb: NodeInFrustum | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject, apCamera
bool FUN_004784d0(BoundOwner* owner)
{
    if (owner) {
        NiBound* bound = owner->bound;
        if (!bound)
            bound = &g_defaultBound;
        return FUN_00476780(bound);
    }
    return false;
}

// @f3 0x0047b7b0 (community match, verified in this file)
namespace f3m_0047b7b0 {
class RefObject_0047b7b0
{
public:
    virtual void Unk00();
    virtual void DeleteThis();
    virtual void Unk08();

    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct PtrHolder_0047b7b0
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

    NiPointer<RefObject_0047b7b0> m_kEntries[4];

    RefObject_0047b7b0* __thiscall FUN_0047b7b0(int index);
};

// pdb: BSSimpleArray<NiPoint2,1024>::operator[] | ImageSpaceEffectWaterDisplacement.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: NiScreenElements::SetRectangle)
// pdb params: aiIndex
RefObject_0047b7b0* PtrHolder_0047b7b0::FUN_0047b7b0(int index)
{
    return this ? m_kEntries[index] : NiPointer<RefObject_0047b7b0>();
}
}   // namespace f3m_0047b7b0

// @f3 0x00478a70 (community match, verified in this file)
namespace f3m_00478a70 {

struct WalkOpts47 {
    void* unk00;
    unsigned char unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct Walker47;

void __cdecl FUN_00478a50(void* elem, WalkOpts47* opts);
void __cdecl FUN_008d5790(Walker47* node, WalkOpts47* opts, void (__cdecl* cb)(void*, WalkOpts47*));

// pdb: GetHavokWorldObjectCountInSceneGraph | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRoot
int __cdecl FUN_00478a70(Walker47* node)
{
    WalkOpts47 opts;
    opts.unk08 = 18;
    opts.unk04 = 1;
    opts.unk0C = 0;
    FUN_008d5790(node, &opts, FUN_00478a50);
    return opts.unk0C;
}
}   // namespace f3m_00478a70

// @f3 0x004708a0 (community match, verified in this file)
namespace f3m_004708a0 {
// FUN_004708a0 @ 0x004708a0
// __thiscall, this in ecx, one dword stack parameter, callee pops 4.

struct Entry_004708a0_target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char unk14;
};

struct Entry_004708a0
{
    Entry_004708a0_target* unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class Owner_004708a0
{
public:
    Entry_004708a0 entries[64];

    int FUN_004708a0(int index);
};

// pdb: BipedAnim::IsFaceGenObject | BipedAnim.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeBipedObject
int Owner_004708a0::FUN_004708a0(int index)
{
    Entry_004708a0_target* p = entries[index + 3].unk00;
    if (p != 0 && (p->unk14 & 1) != 0)
        return 1;
    return 0;
}
}   // namespace f3m_004708a0

// @f3 0x00468dd0 (community match, verified in this file)
namespace f3m_00468dd0 {

class NiPoint3 {
public:
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
struct Pt3i { int x, y, z; };
extern NiPoint3 NiPoint3_ZERO;     /* 0x0108ec68 */
extern const float DAT_00dbe7b8;   /* 15.0f at 0x00dbe7b8 */
extern const float DAT_00dbe7b4;   /* 16.0f at 0x00dbe7b4 */

struct Obj_468dd0 {
    NiPoint3 p0, p1;                /* 0x00, 0x0C */
    Pt3i p2;                        /* 0x18 */
    int unk24, unk28, unk2C, unk30, unk34;
    float unk38, unk3C, unk40, unk44;
    int unk48;
    float unk4C;
    int unk50;
    float unk54, unk58, unk5C;
    NiPoint3 p60;                   /* 0x60 */
    int unk6C;
    unsigned char unk70, unk71, unk72, unk73, unk74, unk75, unk76, unk77, unk78, unk79;

    Obj_468dd0* FUN_00468dd0();
};

// pdb: BGSDecalManager::GetInstance | BGSDecalManager.obj | fnv360_0721_retail, caller, medium
Obj_468dd0* Obj_468dd0::FUN_00468dd0()
{
    p60.x = 0.0f;
    p60.y = 0.0f;
    p60.z = 0.0f;
    p0 = NiPoint3_ZERO;
    p1 = NiPoint3_ZERO;
    p2.x = *(const int*)&NiPoint3_ZERO.x;
    p2.y = *(const int*)&NiPoint3_ZERO.y;
    int z2 = *(const int*)&NiPoint3_ZERO.z;
    unk38 = 0.0f;
    unk3C = 0.0f;
    unk72 = 1;
    unk40 = 0.0f;
    unk44 = 0.0f;
    unk74 = 1;
    unk4C = 0.0f;
    *(volatile int*)&p2.z = z2;
    unk54 = 4.0f;
    unk24 = 0;
    unk58 = DAT_00dbe7b8;
    unk28 = 0;
    unk2C = 0;
    unk5C = DAT_00dbe7b4;
    unk30 = 0;
    unk34 = -1;
    unk70 = 0;
    unk71 = 0;
    NiPoint3 one(1.0f, 1.0f, 1.0f);
    unk48 = 0;
    unk73 = 0;
    unk76 = 0;
    unk50 = 0;
    unk75 = 0;
    p60 = one;
    unk77 = 0;
    unk78 = 0;
    unk79 = 0;
    unk6C = 0;
    return this;
}
}   // namespace f3m_00468dd0

// @f3 0x004756f0 (community match, verified in this file)
namespace f3m_004756f0 {
struct RelativeValue649 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char offset;
    int unk14;
    unsigned char tag;
};
char* FUN_004756f0(RelativeValue649* value)
{
    if (value->tag == 1)
        return reinterpret_cast<char*>(value) + value->offset;
    return 0;
}
}   // namespace f3m_004756f0

// @f3 0x0046e6b0 (community match, verified in this file)
namespace f3m_0046e6b0 {
struct Target670 {
    virtual void slot00(); virtual void slot04(); virtual void slot08();
    virtual void slot0c(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1c(); virtual void slot20();
    virtual void slot24(); virtual void slot28(); virtual void slot2c();
    virtual void slot30(); virtual void slot34(); virtual int slot38();
};
struct Owner670 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18;
    Target670* target;
};
int FUN_0046e6b0(Owner670* owner)
{
    Target670* target = owner->target;
    if (target)
        return target->slot38();
    return 0;
}
}   // namespace f3m_0046e6b0

// @f3 0x004750c0 (community match, verified in this file)
extern const unsigned short DAT_00f4c6d4[12];
namespace f3m_004750c0 {
// pdb: Date::GetDaysInMonth | Date.obj | fnv360_0822_retail, udata + bridge(call_gap_sim|udata), high
unsigned short Date_GetDaysInMonth(int month)
{
    if (month >= 12)
        return 0;
    return DAT_00f4c6d4[month];
}
}   // namespace f3m_004750c0

// @f3 0x0046c630 (community match, verified in this file)
namespace f3m_0046c630 {
struct Point705 { float x, y, z; };
struct Owner705 {
    int unk00; int unk04; int unk08;
    Point705 position;
    void FUN_0046c630(const Point705* supplied);
};
// pdb: BSMultiBoundSphere::SetCenter | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCenter
void Owner705::FUN_0046c630(const Point705* supplied)
{
    position = *supplied;
}
}   // namespace f3m_0046c630

// @f3 0x00470600 (community match, verified in this file)
namespace f3m_00470600 {
struct Owner706 {
    int value;
    void FUN_004704a0(int first, int third);
    void FUN_00470600(int first, int second, int third);
};
// pdb: BGSTextureUseMap::CollectTexUseData | BGSTextureUseMap.obj | fnv360_0721_beta, call_seq, medium
// pdb params: apNode, apDefaultUser, abCheckActors
void Owner706::FUN_00470600(int first, int second, int third)
{
    value = second;
    FUN_004704a0(first, third);
}
}   // namespace f3m_00470600

// @f3 0x004706c0 (community match, verified in this file)
extern bool DAT_01073a30;
extern bool DAT_01073a60;
namespace f3m_004706c0 {
// pdb: BSFaceGenManager::GetUseMultiThreading | BipedAnim.obj | fnv360_0822_retail, call_gap, low
int FUN_004706c0()
{
    if (DAT_01073a30 && DAT_01073a60) return 1;
    return 0;
}
}   // namespace f3m_004706c0

// @f3 0x00477b00 (community match, verified in this file)
extern bool DAT_01075b28;
extern bool DAT_01075cac;
namespace f3m_00477b00 {
// pdb: Interface::Has360Controller | Interface.obj | fnv360_0822_debug, call_seq, medium
int FUN_00477b00()
{
    if (DAT_01075b28 && !DAT_01075cac) return 1;
    return 0;
}
}   // namespace f3m_00477b00

// @f3 0x0046eab0 (community match, verified in this file)
namespace Match752 {
struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;
// pdb: BSSimpleArray<PathSmootherPOVLink,1024>::_Allocate | PathSmootherPOV.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiSizeInItem
void* __stdcall FUN_0046eab0(unsigned int count)
{
    return DAT_01090a78.FUN_0086b930(count << 6);
}
}

// @f3 0x0046c070 (community match, verified in this file)
extern int DAT_0106def4;
extern int DAT_0106def8;
namespace f3m_0046c070 {
namespace Match759 {
struct Owner {
    void FUN_0046ab00();
    void FUN_0046bff0();
    void FUN_0046c070();
};
// pdb: BGSDecalManager::ClearDecalsThisFrame | BGSDecalManager.obj | fnv360_0822_debug, udata, medium
void Owner::FUN_0046c070()
{
    DAT_0106def4 = 0;
    DAT_0106def8 = 0;
    FUN_0046ab00();
    FUN_0046bff0();
}
}
}   // namespace f3m_0046c070

// @f3 0x00475530 (community match, verified in this file)
namespace f3m_00475530 {
struct Data760 { int unk00; int unk04; int unk08; float value; };
struct Owner760 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Data760* data;
    int FUN_00475530();
};
int Owner760::FUN_00475530()
{
    if (data && data->value != 0.0f) return 1;
    return 0;
}
}   // namespace f3m_00475530

// @f3 0x0046ead0 (community match, verified in this file)
namespace Match777 {
struct Heap { void* FUN_0086bae0(void* memory, unsigned int bytes); };
extern Heap DAT_01090a78;
// pdb: BSSimpleArray<PathSmootherPOVLink,1024>::_Reallocate | PathSmootherPOV.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* __stdcall FUN_0046ead0(void* memory, unsigned int count)
{
    return DAT_01090a78.FUN_0086bae0(memory, count << 6);
}
}

// @f3 0x004706e0 (community match, verified in this file)
namespace f3m_004706e0 {
struct Value789 { int unk00; int unk04; int value; };
struct Block789 { Value789* item; };
struct Data789 { int unk00; int unk04; int unk08; int unk0c; Block789 block; };
struct Owner789 {
    int unk00; int unk04;
    Data789* data;
    int FUN_004706e0();
};
// pdb: ImpactMixer::PlayHitSound | ImpactMixer.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: apAttacker, afDamage, afDefDamage, apTarget, aiWeaponType, aiArmorType, aiShieldType, abFakeHit, abEnchantedWeapon
int Owner789::FUN_004706e0()
{
    if (this && data) {
        Block789* block = &data->block;
        if (block && block->item) return block->item->value;
    }
    return 0;
}
}   // namespace f3m_004706e0

// @f3 0x0047cb20 (community match, verified in this file)
namespace f3m_0047cb20 {
struct Data798 { bool FUN_00403450(); };
struct Owner798 {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    Data798 data;
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
    unsigned int flags;
    int FUN_0047cb20();
};
int Owner798::FUN_0047cb20()
{
    if ((flags & 2) && !data.FUN_00403450()) return 1;
    return 0;
}
}   // namespace f3m_0047cb20

// @f3 0x0047cb00 (community match, verified in this file)
namespace f3m_0047cb00 {
inline bool InWideRange805(unsigned char value) {
    return value >= 3 && value <= 12;
}
inline bool InNarrowRange805(unsigned char value) {
    value -= 3;
    return value <= 6;
}
struct Owner805 {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
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
    unsigned char state;
    int TESObjectWEAP_IsThrownWeapon();
};
// pdb: TESObjectWEAP::IsThrownWeapon | InventoryChanges.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
int Owner805::TESObjectWEAP_IsThrownWeapon()
{
    unsigned char value = state;
    if (InWideRange805(value) && !InNarrowRange805(value)) return 1;
    return 0;
}
}   // namespace f3m_0047cb00

// @f3 0x00470870 (community match, verified in this file)
namespace f3m_00470870 {
struct Item840 { virtual ~Item840(); };
struct Owner840 { Item840* first; Item840* second; void FUN_00470870(); };
// pdb: NiCloningProcess::~NiCloningProcess | BipedAnim.obj | fnv360_0822_retail, call_seq, high
void Owner840::FUN_00470870() {
    delete first;
    delete second;
}
}   // namespace f3m_00470870

// @f3 0x0047cb40 (community match, verified in this file)
extern double DAT_00dc0ac8;
extern float DAT_00dbe8fc;
namespace f3m_0047cb40 {

class FUN_0047cb40_Owner {
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    float unk110;

    void FUN_0047cb40(float value);
};

// pdb: TESObjectWEAP::GetAttackSpeed | CombatFormulas.obj | fnv360_0822_retail, call_gap, low
// pdb params: bModValue
void FUN_0047cb40_Owner::FUN_0047cb40(float value)
{
    if (!(value < DAT_00dc0ac8)) {
        unk110 = value;
    } else {
        unk110 = DAT_00dbe8fc;
    }
}
}   // namespace f3m_0047cb40

// @f3 0x0047d230 (community match, verified in this file)
namespace f3m_0047d230 {
struct Item842 { int FUN_0040acc0(); void FUN_0040b920(); };
struct Owner842 { Item842** items; void FUN_0047d230(); };
// pdb: ItemChange::RemovePoison | InventoryChanges.obj | fnv360_0822_retail, caller, medium
void Owner842::FUN_0047d230() {
    Item842** list = items;
    if (list) {
        Item842* item = *list;
        if (item && item->FUN_0040acc0()) item->FUN_0040b920();
    }
}
}   // namespace f3m_0047d230

// @f3 0x00475250 (community match, verified in this file)
namespace f3m_00475250 {
struct Vec849 { float x, y, z; float FUN_00475250(const Vec849* other); };
// pdb: NiPoint3::operator* | GlobalFunc.obj | tesv_win, call_dedup, low
float Vec849::FUN_00475250(const Vec849* other) {
    return other->y * y + other->x * x + other->z * z;
}
}   // namespace f3m_00475250

// @f3 0x00477760 (community match, verified in this file)
namespace f3m_00477760 {
struct Payload850 { int x, y, z; };
struct Node850 { int unk00, key04; Payload850 values08; };
// pdb: NiTMapBase<DFALL<NiTMapItem<unsigned int,VertexDist> >,unsigned int,VertexDist>::SetValue | GlobalFunc.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkItem, key, val
Node850* __stdcall FUN_00477760(Node850* node, int key, Payload850 values) {
    node->key04 = key;
    node->values08 = values;
    return node;
}
}   // namespace f3m_00477760

// @f3 0x00468cd0 (community match, verified in this file)
namespace f3m_00468cd0 {
struct Vec865 { float x, y, z; };
// pdb: operator* | ExtraDataObjects.obj | tesv_win, call_seq, medium
Vec865* __cdecl FUN_00468cd0(Vec865* output, float scale, const Vec865* source) {
    output->x = source->x * scale;
    output->y = source->y * scale;
    output->z = source->z * scale;
    return output;
}
}   // namespace f3m_00468cd0

// @f3 0x00468f10 (community match, verified in this file)
namespace f3m_00468f10 {
struct Vec866 { float x,y,z; };
Vec866* __cdecl FUN_00468f10(Vec866* output, const Vec866* source) {
    output->x = source->x * 0.1428767293691635;
    output->y = source->y * 0.1428767293691635;
    output->z = source->z * 0.1428767293691635;
    return output;
}
}   // namespace f3m_00468f10

// @f3 0x00465160 (community match, verified in this file)
extern int DAT_00dbe6cc;
namespace f3m_00465160 {
struct Owner887 {
    void* vtable00;
    int unk04, unk08, unk0C, unk10, unk14;
    unsigned short flags18, unk1A;
    int value1C, value20;
    void FUN_00824e90();
    Owner887* FUN_00465160();
};
// pdb: NiStencilProperty::NiStencilProperty | BGSAutoWater.obj | fnv360_0822_retail, call_gap, low
Owner887* Owner887::FUN_00465160() {
    FUN_00824e90();
    vtable00 = &DAT_00dbe6cc;
    value1C = 0;
    value20 = -1;
    flags18 = 0x4180;
    return this;
}
}   // namespace f3m_00465160

// @f3 0x004779a0 (community match, verified in this file)
namespace f3m_004779a0 {
ClassifiedObject47* __cdecl FUN_004779a0(LookupOwner47* owner) {
    if (owner) {
        LookupResult47 result;
        return owner->FUN_00477900(&result, DAT_010f2c30)->item;
    }
    return 0;
}
}   // namespace f3m_004779a0

// @f3 0x0047caa0 (community match, verified in this file)
extern const char DAT_00f46078[], DAT_00f46a4c[];
namespace f3m_0047caa0 {
struct Value889 { int unk00; unsigned int value04; };
Value889* __cdecl FUN_00c0050a(void* object, int unused, const void* baseType, const void* targetType, int flags);
// pdb: TESEnchantableForm::GetFormEnchanting | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
// pdb params: apForm
unsigned int __cdecl FUN_0047caa0(void* object) {
    Value889* value = FUN_00c0050a(object, 0, DAT_00f46078, DAT_00f46a4c, 0);
    if (value) return value->value04;
    return 0;
}
}   // namespace f3m_0047caa0

// @f3 0x0046c0c0 (community match, verified in this file)
namespace f3m_0046c0c0 {
struct FUN_0046c0c0_Obj {
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};

struct FUN_0046c0c0_Class {
    int unk00;
    int unk04;
    int unk08;
    float unk0C;

    FUN_0046c0c0_Class* __thiscall FUN_0046c0c0(FUN_0046c0c0_Obj* source);
};

// pdb: BSOcclusionPlane::GetFrustumPlanes | BSOcclusionPlane.obj | tesv_win, objrun_open, low
FUN_0046c0c0_Class* __thiscall FUN_0046c0c0_Class::FUN_0046c0c0(FUN_0046c0c0_Obj* source) {
    float value = source->unk0C;

    unk00 = source->unk00;
    unk04 = source->unk04;
    unk08 = source->unk08;
    unk0C = value;
    return this;
}
}   // namespace f3m_0046c0c0

// @f3 0x00470a30 (community match, verified in this file)
#include <string.h>
#include <stdio.h>

namespace f3m_00470a30 {
class ModelSource {
public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual const char* GetModelPath();
};

class FileFinder {
public:
    void* FUN_00bc7d50(const char* path, int unused, int location, int flags);
};
extern FileFinder* DAT_011785d0;

// pdb: BipedAnim::Get1stPersonModelFileName | BipedAnim.obj | fnv360_0822_retail, ustr, medium
// pdb params: apModel, ap1stPersonFileName
bool __stdcall FUN_00470a30(ModelSource* source, char* path)
{
    char fullPath[0x104];
    strcpy_s(path, 0x104, source->GetModelPath());
    char* extension = strrchr(path, '.');
    if (extension) {
        *extension = 0;
        strcat_s(extension, 0x104 - (extension - path), "1st.nif");
        sprintf_s(fullPath, 0x104, "Data\\%s\\%s", "Meshes", path);
        if (DAT_011785d0 && DAT_011785d0->FUN_00bc7d50(fullPath, 0, 6, 1))
            return true;
    }
    return false;
}
}

// @f3 0x0047d170 (community match, verified in this file)
namespace f3m_0047d170 {
namespace f3m_0047d170 {
struct ExtraList
{
    int FUN_0040abc0();
};
struct Holder
{
    ExtraList* list;
};
struct Owner
{
    Holder* holder;

    int FUN_0047d170();
};

// pdb: ItemChange::GetItemOwnership | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
int Owner::FUN_0047d170()
{
    if (holder) {
        ExtraList* list = holder->list;
        if (list && list->FUN_0040abc0())
            return list->FUN_0040abc0();
    }
    return 0;
}
}
}   // namespace f3m_0047d170

// @f3 0x004710f0 (community match, verified in this file)
namespace f3m_004710f0 {
struct Slot
{
    int handle;
    int unk04;
    int unk08;
    int unk0C;
};

struct SlotOwner;
struct Manager
{
    void FUN_0042cd20(SlotOwner* owner, int* out, int a, int b, int index);
};
extern Manager* DAT_0106ca70;

struct SlotOwner
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
    Slot slots[8];

    void FUN_004710f0(int a, int b, int* out, int index);
};

void SlotOwner::FUN_004710f0(int a, int b, int* out, int index)
{
    if (*out == 0) {
        int handle = slots[index].handle;
        if (handle != 0 && handle != -1)
            DAT_0106ca70->FUN_0042cd20(this, out, a, b, index);
    }
}
}

// @f3 0x0047f930 (community match, verified in this file)
namespace f3m_0047f930 {
namespace f3m_0047f930 {

class Stream;

class Item {
public:
    void FUN_00419d30(Stream* s, int value);
};

struct ItemNode {
    Item* data;
    ItemNode* next;
};

struct Group {
    ItemNode* items;
    int unk04;
    int value;
};

struct GroupNode {
    Group* data;
    GroupNode* next;
};

class Stream {
public:
    virtual void VFunc00();
    virtual int VFunc04();
};

class GroupList {
public:
    GroupNode* head;
    void InventoryChanges_InitLoadGame(Stream* s);
};

}

using namespace f3m_0047f930;

// pdb: InventoryChanges::InitLoadGame | InventoryChanges.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void GroupList::InventoryChanges_InitLoadGame(Stream* s)
{
    int saved24 = s->VFunc04();
    unsigned int saved17 = *(unsigned int*)((char*)s + 0x17);
    int saved2c = *(int*)((char*)s + 0x2c);
    *(int*)((char*)s + 0x24) = 0;
    *(unsigned int*)((char*)s + 0x17) = 0x400;
    *(int*)((char*)s + 0x2c) = 0;
    for (GroupNode* g = head; g; g = g->next)
    {
        Group* group = g->data;
        if (group)
        {
            for (ItemNode* n = group->items; n; n = n->next)
            {
                if (n->data)
                    n->data->FUN_00419d30(s, group->value);
            }
        }
    }
    *(int*)((char*)s + 0x24) = saved24;
    *(unsigned int*)((char*)s + 0x17) = saved17;
    *(int*)((char*)s + 0x2c) = saved2c;
}
}   // namespace f3m_0047f930

// @f3 0x00478250 (community match, verified in this file)
namespace f3m_00478250 {
struct NiRTTI
{
    const char* name;
    NiRTTI* base;
};
extern NiRTTI DAT_01091f78;

class NiNode;

class NiAVObject {
public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual NiNode* GetAsNiNode();

    void* FUN_00825200(NiRTTI* rtti);
};

class NiNode : public NiAVObject {
public:
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
    int unk9C;
    NiAVObject** children;
    unsigned short capacity;
    unsigned short count;

    NiAVObject* GetAt(unsigned int index) const { return children[index]; }
};

// pdb: HasMorpherController | GlobalFunc.obj | fnv360_0822_debug, caller, medium
// pdb params: apObj
bool __cdecl FUN_00478250(NiAVObject* object)
{
    if (!object)
        return false;
    if (object->FUN_00825200(&DAT_01091f78))
        return true;
    NiNode* node = object->GetAsNiNode();
    if (node) {
        for (unsigned int i = 0; i < node->count; i++) {
            if (FUN_00478250(node->GetAt(i)))
                return true;
        }
    }
    return false;
}
}

// @f3 0x0047cad0 (community match, verified in this file)
extern const char DAT_00f46078[], DAT_00f46a4c[];
namespace f3m_0047cad0 {
struct Value903 { int unk00, unk04; unsigned short value08; };
Value903* __cdecl FUN_00c0050a(void* object, int unused, const void* baseType, const void* targetType, int flags);
unsigned int __cdecl FUN_0047cad0(void* object) {
    Value903* value = FUN_00c0050a(object, 0, DAT_00f46078, DAT_00f46a4c, 0);
    if (value) return value->value08;
    return 0;
}
}   // namespace f3m_0047cad0

// @f3 0x004691c0 (community match, verified in this file)
namespace f3m_004691c0 {
namespace f3m_004691c0 {

class RefObject {
public:
    virtual ~RefObject();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

class Owner {
public:
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0;
    NiPointer<RefObject> unkC4;

    void FUN_004691c0(RefObject* object);
};

}

using namespace f3m_004691c0;

// pdb: BSCullingProcess::SetAccumulator | BGSDecalManager.obj | fnv360_0822_debug, objrun, low
// pdb params: apAccumulator
void Owner::FUN_004691c0(RefObject* object)
{
    unkC4 = object;
}
}   // namespace f3m_004691c0

// @f3 0x0047af10 (community match, verified in this file)
namespace f3m_0047af10 {
struct FUN_0047af10_Obj {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18(unsigned int row, unsigned int col);

    int unk04;
    int unk08;
    unsigned int count;

    void __thiscall GridArray_DetachAll();
};
void FUN_0047af10_Obj::vf00() {}
void FUN_0047af10_Obj::vf04() {}
void FUN_0047af10_Obj::vf08() {}
void FUN_0047af10_Obj::vf0C() {}
void FUN_0047af10_Obj::vf10() {}
void FUN_0047af10_Obj::vf14() {}
void FUN_0047af10_Obj::vf18(unsigned int, unsigned int) {}
// pdb: GridArray::DetachAll | GridArray.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __thiscall FUN_0047af10_Obj::GridArray_DetachAll() {
    for (unsigned int row = 0; row < count; ++row) {
        for (unsigned int col = 0; col < count; ++col) {
            vf18(row, col);
        }
    }
}
}   // namespace f3m_0047af10

// @f3 0x0047b1c0 (community match, verified in this file)
namespace f3m_0047b1c0 {
struct Vec915 { float x, y, z; };
struct Owner915 {
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
    int unk9C;
    int unkA0;
    int unkA4;
    int countA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    Vec915 position;
    void FUN_0047b1c0(const Vec915* value);
};
void Owner915::FUN_0047b1c0(const Vec915* value) {
    position = *value;
    countA8 += 1;
}
}   // namespace f3m_0047b1c0

// @f3 0x0047b1f0 (community match, verified in this file)
namespace f3m_0047b1f0 {
struct Vec916 { float x, y, z; };
struct Owner916 {
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
    int unk9C;
    int unkA0;
    int unkA4;
    int countA8;
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
    Vec916 position;
    void FUN_0047b1f0(const Vec916* value);
};
void Owner916::FUN_0047b1f0(const Vec916* value) {
    position = *value;
    countA8 += 1;
}
}   // namespace f3m_0047b1f0

// @f3 0x0046e700 (community match, verified in this file)
struct FUN_0046e700_Table {
    bool __thiscall FUN_0040e820(int key, bool* found);
    void __thiscall FUN_00493c20(int key, int value);
};
extern FUN_0046e700_Table DAT_00f4bf68;

// pdb: BGSSceneInfo::TexUseCB | BGSSceneInfo.obj | fnv360_0721_beta, objrun, low
// pdb params: apTexture, aulMemorySize, apParam
void __cdecl FUN_0046e700(int key, int amount, int** counter)
{
    bool found = false;
    if (DAT_00f4bf68.FUN_0040e820(key, &found) && found)
        return;
    **counter += amount;
    DAT_00f4bf68.FUN_00493c20(key, 1);
}

// @f3 0x00475710 (community match, verified in this file)
namespace f3m_00475710 {
struct Component925 { float FUN_008f8410(); };
struct Child925 {
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
    Component925 componentD0;
};
struct Owner925 {
    int unk00, unk04;
    Child925* child08;
    float FUN_00475710();
};
// pdb: hkpRigidBody::applyLinearImpulse | MagicCaster.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkRigidBody::GetDynamicMass)
// pdb params: imp
float Owner925::FUN_00475710() {
    return this && child08 ? child08->componentD0.FUN_008f8410() : 0.0f;
}
}   // namespace f3m_00475710

// @f3 0x0047b220 (community match, verified in this file)
namespace f3m_0047b220 {
struct Owner926 {
    int unk00, unk04, unk08;
    unsigned int size0C;
    int* data10;
    int* FUN_0047b220(unsigned int row, unsigned int column);
};
// pdb: GridCellArray::Get | GridCell.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: Actor::RequestDetectionState)
// pdb params: aiX, aiY
int* Owner926::FUN_0047b220(unsigned int row, unsigned int column) {
    if (row < size0C && column < size0C) return &data10[size0C * row + column];
    return 0;
}
}   // namespace f3m_0047b220

// @f3 0x00470770 (community match, verified in this file)
namespace f3m_00470770 {
struct Form470770;
struct Owner470770 {
    virtual void vf000(); virtual void vf004(); virtual void vf008(); virtual void vf00C();
    virtual void vf010(); virtual void vf014(); virtual void vf018(); virtual void vf01C();
    virtual void vf020(); virtual void vf024(); virtual void vf028(); virtual void vf02C();
    virtual void vf030(); virtual void vf034(); virtual void vf038(); virtual void vf03C();
    virtual void vf040(); virtual void vf044(); virtual void vf048(); virtual void vf04C();
    virtual void vf050(); virtual void vf054(); virtual void vf058(); virtual void vf05C();
    virtual void vf060(); virtual void vf064(); virtual void vf068(); virtual void vf06C();
    virtual void vf070(); virtual void vf074(); virtual void vf078(); virtual void vf07C();
    virtual void vf080(); virtual void vf084(); virtual void vf088(); virtual void vf08C();
    virtual void vf090(); virtual void vf094(); virtual void vf098(); virtual void vf09C();
    virtual void vf0A0(); virtual void vf0A4(); virtual void vf0A8(); virtual void vf0AC();
    virtual void vf0B0(); virtual void vf0B4(); virtual void vf0B8(); virtual void vf0BC();
    virtual void vf0C0(); virtual void vf0C4(); virtual void vf0C8(); virtual void vf0CC();
    virtual void vf0D0(); virtual void vf0D4(); virtual void vf0D8(); virtual void vf0DC();
    virtual void vf0E0(); virtual void vf0E4();
    virtual void OnChanged_0E8(Form470770* form);
};
struct Form470770 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    Owner470770* owner18;
};
struct Manager470770 {
    void FUN_00ae1a30(Form470770* form);
};
extern Manager470770* DAT_0116efb8;
void __cdecl FUN_00478bb0(Form470770* form);
void __cdecl FUN_008d7720(Form470770* form, int a, int b);

// pdb: BipedAnim::RunBiped3DDetach | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: ap3D
void __cdecl FUN_00470770(Form470770* form)
{
    if (form) {
        FUN_00478bb0(form);
        DAT_0116efb8->FUN_00ae1a30(form);
        if (form->owner18) {
            FUN_008d7720(form, 1, 0);
            form->owner18->OnChanged_0E8(form);
        }
    }
}
}

// @f3 0x00477b20 (community match, verified in this file)
namespace f3m_00477b20 {
float FUN_00475910(float angle);
// pdb: GetZAngleFromVector | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium, conflict (skyrim: NiPoint3::GetZAngleFromVector)
// pdb params: aDirection
float FUN_00477b20(const float* vec)
{
    float angle;
    if (vec[1] != 0.0f) {
        angle = atan(vec[0] / vec[1]);
        if (vec[1] < 0.0f)
            angle = angle + 3.1415927410125732;
    } else if (vec[0] > 0.0f) {
        angle = 1.5707964f;
    } else {
        angle = 4.712389f;
    }
    return FUN_00475910(angle);
}
}   // namespace f3m_00477b20

// @f3 0x0047d1d0 (community match, verified in this file)
namespace f3m_0047d1d0 {
class FUN_0047d1d0_Leaf {
public:
    int FUN_0040acc0();
};

struct FUN_0047d1d0_Node {
    FUN_0047d1d0_Leaf* unk00;
};

class FUN_0047d1d0_Holder {
public:
    FUN_0047d1d0_Node* unk00;
    int FUN_0047d1d0();
};

// pdb: ItemChange::GetPoison | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
int FUN_0047d1d0_Holder::FUN_0047d1d0() {
    int result = 0;
    do {
        FUN_0047d1d0_Node* node = unk00;
        if (!node) break;
        FUN_0047d1d0_Leaf* leaf = node->unk00;
        if (!leaf || !leaf->FUN_0040acc0()) break;
        result = leaf->FUN_0040acc0();
    } while (0);
    return result;
}
}   // namespace f3m_0047d1d0

// @f3 0x00464e20 (community match, verified in this file)
namespace f3m_00464e20 {
namespace f3m_00464e20 {
struct Entry464e20 {
    int unk00;
    float value;
};
}
// pdb: SortY | BGSAutoWater.obj | fnv360_0822_retail, objrun, medium
// pdb params: pV1, pV2
int __cdecl FUN_00464e20(const f3m_00464e20::Entry464e20* a, const f3m_00464e20::Entry464e20* b)
{
    if (a->value > b->value)
        return 1;
    if (b->value > a->value)
        return -1;
    return 0;
}
}   // namespace f3m_00464e20

// @f3 0x00470b70 (community match, verified in this file)
namespace f3m_00470b70 {

namespace f3m_00470b70 {
class RefObject {
public:
    virtual void vf00();
    virtual void DeleteThis();
    long refCount;
};
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8;
    RefObject* objectBC;

    void FUN_00470b70(RefObject* object);
};
void Owner::FUN_00470b70(RefObject* object)
{
    RefObject* old = objectBC;
    if (old != object) {
        if (old && InterlockedDecrement(&old->refCount) == 0)
            old->DeleteThis();
        objectBC = object;
        if (object)
            InterlockedIncrement(&object->refCount);
    }
}
}
}   // namespace f3m_00470b70

// @f3 0x004708d0 (community match, verified in this file)
extern void* DAT_01202ddc;
namespace f3m_004708d0 {

struct FUN_004708d0_Extra {
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
};

struct FUN_004708d0_Obj {
    FUN_004708d0_Extra* FUN_00824a50(void* name);
};

void __cdecl TESObjectREFR_AddAddonNodes(void* value);

// pdb: BipedAnim::AddAddonNodes | BipedAnim.obj | fnv360_0822_retail, objrun + bridge(call_gap|call_gap_sim), high
void __cdecl BipedAnim_AddAddonNodes(FUN_004708d0_Obj* obj, void* value) {
    FUN_004708d0_Extra* extra = obj->FUN_00824a50(DAT_01202ddc);
    if (extra != 0) {
        unsigned int flags = *(volatile unsigned int*)&extra->unk0C;
        flags >>= 4;
        if ((unsigned char)flags & 1) {
            TESObjectREFR_AddAddonNodes(value);
        }
    }
}
}   // namespace f3m_004708d0

// @f3 0x00475490 (community match, verified in this file)
namespace f3m_00475490 {
struct Mat33 { float m[3][3]; };
bool __stdcall NiMatrix3_Inverse(Mat33* m);

// pdb: NiMatrix3::Inverse | GlobalFunc.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
Mat33* __stdcall FUN_00475490(Mat33* m)
{
    if (!NiMatrix3_Inverse(m))
    {
        m->m[0][0] = 0.0f;
        m->m[1][0] = 0.0f;
        m->m[2][0] = 0.0f;
        m->m[0][1] = 0.0f;
        m->m[1][1] = 0.0f;
        m->m[2][1] = 0.0f;
        m->m[0][2] = 0.0f;
        m->m[1][2] = 0.0f;
        m->m[2][2] = 0.0f;
    }
    return m;
}
}   // namespace f3m_00475490

// @f3 0x00465120 (community match, verified in this file)
namespace f3m_00465120 {
struct Vec3_465120 { float x, y, z; };
int FUN_00465120(const Vec3_465120* a, const Vec3_465120* b)
{
    if (a->x == b->x && a->y == b->y && a->z == b->z)
        return 1;
    return 0;
}
}   // namespace f3m_00465120

// @f3 0x00468fd0 (community match, verified in this file)
namespace f3m_00468fd0 {
struct Random964 { unsigned int FUN_0086c4b0(unsigned int maximum); };
Random964* __cdecl FUN_0044a2d0();
// pdb: RandomFloatTwoPi | BGSDecalManager.obj | fnv360_0822_retail, call_seq + skyrim(call_gap), high
float __cdecl RandomFloatTwoPi() {
    Random964* random = FUN_0044a2d0();
    unsigned int value = random->FUN_0086c4b0(0xffffffffu);
    return (float)value * 1.462918119976564e-09;
}
}   // namespace f3m_00468fd0

// @f3 0x0046c670 (community match, verified in this file)
#include <math.h>
namespace f3m_0046c670 {
struct Owner965 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float x18, y1C, z20;
    float FUN_0046c670();
};
// pdb: BSMultiBoundAABB::QMultiBoundRadius | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
float Owner965::FUN_0046c670() { return sqrt(y1C * y1C + x18 * x18 + z20 * z20); }
}   // namespace f3m_0046c670

// @f3 0x00470fd0 (community match, verified in this file)
#include <string.h>
namespace f3m_00470fd0 {

namespace f3m_00470fd0 {
struct Obj {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
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
    struct Block {
        int unk000;
        int unk004;
        int unk008;
        int unk00c;
        int unk010;
        int unk014;
        int unk018;
        int unk01c;
        int unk020;
        int unk024;
        int unk028;
        int unk02c;
        int unk030;
        int unk034;
        int unk038;
        int unk03c;
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
    } block16c;
    int unk2ac;
    int unk2b0;
    Obj* FUN_00470fd0(int a, int b);
    void FUN_00470c20(int b);
};
}
using namespace f3m_00470fd0;

// pdb: BipedAnim::BipedAnim | BipedAnim.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRef, apNode
Obj* Obj::FUN_00470fd0(int a, int b)
{
    memset(this, 0, sizeof(Obj));
    memset(&block16c, 0, sizeof(block16c));
    unk2b0 = a;
    if (b)
        FUN_00470c20(b);
    return this;
}
}   // namespace f3m_00470fd0

// @f3 0x004652c0 (community match, verified in this file)
extern char DAT_00dbe764;
typedef void (__stdcall *Free972)(void* memory);
extern Free972 DAT_00dbe76c;
struct Owner972 {
    void* vtable00;
    void* data04;
    int size08, capacity0C;
    void FUN_004652c0();
};
void Owner972::FUN_004652c0() {
    vtable00 = &DAT_00dbe764;
    void* memory = data04;
    if (memory) {
        DAT_00dbe76c(memory);
        data04 = 0;
        capacity0C = 0;
        size08 = 0;
    }
}

// @f3 0x0047d2d0 (community match, verified in this file)
namespace f3m_0047d2d0 {
struct Object973 { int FUN_0040ad00(); };
struct Node973 { Object973* object00; Node973* next04; };
struct Owner973 { Node973* head00; int FUN_0047d2d0(); };
// pdb: ItemChange::GetScriptLocals | InventoryChanges.obj | fnv360_0822_retail, call_gap, medium
int Owner973::FUN_0047d2d0() {
    Node973* node = head00;
    while (node) {
        Object973* object = node->object00;
        if (!object) break;
        if (object->FUN_0040ad00()) return object->FUN_0040ad00();
        node = node->next04;
    }
    return 0;
}
}   // namespace f3m_0047d2d0

// @f3 0x0047e280 (community match, verified in this file)
namespace f3m_0047e280 {
namespace f3m_0047e280 {

struct EntryM
{
    bool ExtraDataList_GetWorn(int a);
    bool ExtraDataList_GetCanNotWear();
    void FUN_0040b5e0(int a, int b);
};

struct InnerNodeM
{
    EntryM* data;
    InnerNodeM* next;
};

struct GroupM
{
    InnerNodeM* head;
    int unk04;
    int key;
};

struct OuterNodeM
{
    GroupM* data;
    OuterNodeM* next;
};

struct ListM
{
    OuterNodeM* head;
    EntryM* InventoryChanges_WearingObject(int key, bool flag);
};

// pdb: InventoryChanges::WearingObject | InventoryChanges.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
EntryM* ListM::InventoryChanges_WearingObject(int key, bool flag)
{
    OuterNodeM* node = head;
    bool searching = true;
    while (node && searching)
    {
        GroupM* g = node->data;
        if (g && g->key == key)
            searching = false;
        else
            node = node->next;
    }
    if (node && node->data)
    {
        for (InnerNodeM* in = node->data->head; in; in = in->next)
        {
            EntryM* e = in->data;
            if (!e)
                break;
            if (e->ExtraDataList_GetWorn(0))
                return e;
            if (e->ExtraDataList_GetCanNotWear() && flag)
            {
                e->FUN_0040b5e0(1, 0);
                return e;
            }
        }
    }
    return 0;
}
}
}   // namespace f3m_0047e280

// @f3 0x0047e400 (community match, verified in this file)
namespace f3m_0047e400 {

namespace f3m_0047e400 {
struct Form {
    int unk00;
    unsigned char type;
};
struct ContainerEntry {
    int count;
    Form* form;
};
struct ContainerNode {
    ContainerEntry* item;
    ContainerNode* next;
};
struct Container {
    int unk00;
    ContainerNode list;
    bool FUN_004528c0(Form* form);
};
struct BaseForm {
    Container* FUN_004e66c0();
};
struct InvEntry {
    void* extraLists;
    int countDelta;
    Form* form;
};
struct InvNode {
    InvEntry* item;
    InvNode* next;
};
struct Owner {
    InvNode* entries;
    BaseForm* baseForm;
    Form* FUN_0047e400(int type, int* count);
};
}
using namespace f3m_0047e400;

// pdb: InventoryChanges::GetObjectbyType | InventoryChanges.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aeFormID, ainumb
Form* Owner::FUN_0047e400(int type, int* count)
{
    Container* container = baseForm ? baseForm->FUN_004e66c0() : 0;
    Form* result = 0;
    for (ContainerNode* node = &container->list; node && !result; node = node->next) {
        ContainerEntry* entry = node->item;
        if (!entry)
            break;
        result = entry->form;
        if (result && result->type == type) {
            InvNode* n = entries;
            bool searching = true;
            while (n && searching) {
                if (n->item && n->item->form == result)
                    searching = false;
                else
                    n = n->next;
            }
            if (n && n->item) {
                InvEntry* ie = n->item;
                if (ie->countDelta + entry->count)
                    *count = ie->countDelta + entry->count;
            } else {
                *count = entry->count;
            }
        } else {
            result = 0;
        }
    }
    for (InvNode* n = entries; n && !result; n = n->next) {
        InvEntry* ie = n->item;
        if (!ie)
            break;
        result = ie->form;
        if (result && result->type == type) {
            Container* c = baseForm ? baseForm->FUN_004e66c0() : 0;
            if (!c->FUN_004528c0(result)) {
                int cnt = n->item->countDelta;
                if (cnt > 0)
                    *count = cnt;
            }
        } else {
            result = 0;
        }
    }
    return result;
}
}   // namespace f3m_0047e400

// @f3 0x00464df0 (community match, verified in this file)
namespace f3m_00464df0 {
// pdb: SortX | BGSAutoWater.obj | fnv360_0822_retail, objrun, medium
// pdb params: pV1, pV2
int __cdecl FUN_00464df0(const float* left, const float* right) {
    if (*left > *right) return 1;
    if (*right > *left) return -1;
    return 0;
}
}   // namespace f3m_00464df0

// @f3 0x0046c360 (community match, verified in this file)
#include <new>
extern int DAT_00dbed9c;
namespace f3m_0046c360 {
void* __cdecl FUN_0089eb90(unsigned int bytes);
void __cdecl FUN_0089ec10(void* memory);

struct Vec3_46c
{
    float x;
    float y;
    float z;
};

class Base46c
{
public:
    virtual void Slot00();
    int unk04;
    int unk08;
    Base46c();
};

class Derived46c : public Base46c
{
public:
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    Derived46c(const volatile Vec3_46c& v, float f)
    {
        unk18 = f;
        *(unsigned int*)&unk0C = *(const volatile unsigned int*)&v.x;
        *(unsigned int*)&unk10 = *(const volatile unsigned int*)&v.y;
        *(int*)this = (int)&DAT_00dbed9c;
        *(unsigned int*)&unk14 = *(const volatile unsigned int*)&v.z;
    }
    static void* operator new(size_t bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
};

static const volatile Vec3_46c& Zero46c(volatile Vec3_46c& v)
{
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    return v;
}

class Owner46c
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float unk18;
    Derived46c* FUN_0046c360(int unused);
};

// pdb: BGSPrimitiveSphere::MakeMultiBoundShape | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: akAngle
Derived46c* Owner46c::FUN_0046c360(int unused)
{
    Vec3_46c v;
    return new Derived46c(Zero46c(v), unk18);
}
}   // namespace f3m_0046c360

// @f3 0x00475320 (community match, verified in this file)
namespace f3m_00475320 {
namespace f3m_00475320 {
struct Vec3
{
    float x, y, z;
    Vec3(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
};
struct Mat3 { float m[3][3]; };
}
using namespace f3m_00475320;
// pdb: operator* | LocalMap.obj | tesv_win, call_gap, low
Vec3 FUN_00475320(const Vec3& v, const Mat3& mat)
{
    return Vec3(mat.m[0][0] * v.x + mat.m[1][0] * v.y + mat.m[2][0] * v.z,
                mat.m[0][1] * v.x + mat.m[1][1] * v.y + mat.m[2][1] * v.z,
                mat.m[0][2] * v.x + mat.m[1][2] * v.y + mat.m[2][2] * v.z);
}
}   // namespace f3m_00475320

// @f3 0x0047fa20 (community match, verified in this file)
namespace f3m_0047fa20 {
struct Item47fa20;

struct Inner47fa20 {
    Item47fa20* item;
    Inner47fa20* next;
};

struct Group47fa20 {
    Inner47fa20* head;
    int unk04;
    int key;
};

struct Outer47fa20 {
    Group47fa20* group;
    Outer47fa20* next;
};

struct Owner47fa20 {
    Outer47fa20* head;

    Item47fa20* FUN_0047fa20(int key, int index);
};

// pdb: InventoryChanges::GetExtraDataListFromIndexForItem | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject, aiExtraIndex
Item47fa20* Owner47fa20::FUN_0047fa20(int key, int index)
{
    if (key == 0 || index == -1)
        return 0;
    Outer47fa20* node = head;
    if (node) {
        do {
            Group47fa20* group = node->group;
            Outer47fa20* next = node->next;
            if (group && group->key == key) {
                Inner47fa20* inner = group->head;
                int i = 0;
                if (inner) {
                    do {
                        Item47fa20* item = inner->item;
                        if (i == index)
                            return item;
                        inner = inner->next;
                        i++;
                    } while (inner);
                }
                return 0;
            }
            node = next;
        } while (node);
    }
    return 0;
}
}   // namespace f3m_0047fa20

// @f3 0x00477680 (community match, verified in this file)
namespace f3m_00477680 {
struct FUN_00477680_node {
    FUN_00477680_node* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FUN_00477680_out {
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00477680_cls {
    virtual void vf00();
    virtual int vf04(int key);
    virtual bool vf08(int key, int nodeKey);
    int unk04;
    FUN_00477680_node** unk08;
    bool FUN_00477680(int key, FUN_00477680_out* out);
};

void FUN_00477680_cls::vf00() {}
int FUN_00477680_cls::vf04(int key) { return key; }
bool FUN_00477680_cls::vf08(int key, int nodeKey) { return nodeKey == key; }

// pdb: NiTMapBase<DFALL<NiTMapItem<unsigned int,VertexDist> >,unsigned int,VertexDist>::GetAt | GlobalFunc.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: key, val
bool FUN_00477680_cls::FUN_00477680(int key, FUN_00477680_out* out)
{
    FUN_00477680_node* n = unk08[vf04(key)];
    while (n != 0) {
        if (vf08(key, n->unk04)) {
            out->unk00 = n->unk08;
            out->unk04 = n->unk0C;
            out->unk08 = n->unk10;
            return true;
        }
        n = n->unk00;
    }
    return false;
}
}   // namespace f3m_00477680

// @f3 0x004779d0 (community match, verified in this file)
namespace f3m_004779d0 {
struct TypeInfo
{
    const char* name;
    const TypeInfo* base;
};
extern const TypeInfo DAT_01092a48;
extern const char DAT_010f2c30[];
class ClassifiedObject
{
public:
    virtual void slot0();
    virtual void slot1();
    virtual const TypeInfo* getType() const;
};
struct LookupResult
{
    ClassifiedObject* item;
    unsigned int unk04;
};
struct LookupOwner
{
    LookupResult* FUN_00477900(LookupResult* out, const void* key);
};
__forceinline bool IsRequestedType(const TypeInfo* type)
{
    if (type) do {
        if (type == &DAT_01092a48) return true;
        type = type->base;
    } while (type);
    return false;
}
__forceinline ClassifiedObject* FindObject(LookupOwner* owner)
{
    if (!owner) return 0;
    LookupResult result;
    return owner->FUN_00477900(&result, DAT_010f2c30)->item;
}
}
using namespace f3m_004779d0;
// pdb: bhkCollisionObject::Getbhk | GlobalFunc.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: TESObjectREFR::GetHandle)
// pdb params: apBody
ClassifiedObject* __cdecl FUN_004779d0(LookupOwner* owner)
{
    ClassifiedObject* object = FindObject(owner);
    if (!object) return 0;
    return IsRequestedType(object->getType()) ? object : 0;
}

// @f3 0x00475680 (community match, verified in this file)
namespace f3m_00475680 {
// FUN_00475680: thiscall, one stack param (float* dst). Copies the 4 floats at this to dst.
struct NiVec4_475680 {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    void FUN_00475680(float* dst);
};

void NiVec4_475680::FUN_00475680(float* dst)
{
    float a = unk04;
    float b = unk08;
    float c = unk0C;
    dst[0] = unk00;
    dst[1] = a;
    dst[2] = b;
    dst[3] = c;
}
}   // namespace f3m_00475680

// @f3 0x00478b70 (community match, verified in this file)
namespace f3m_00478b70 {
struct Local_478b70 {
    int unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

typedef void (__cdecl *Callback_478b70)();
void __cdecl FUN_00478b30();
void __cdecl FUN_008d5790(int, void*, Callback_478b70);

// pdb: GetHavokWorldObjectByIndexInSceneGraph | GlobalFunc.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRoot, aiIndex
int __cdecl FUN_00478b70(int param_1, int param_2)
{
    Local_478b70 local;

    local.unk0C = 0;
    local.unk10 = 0;
    local.unk08 = 0x12;
    local.unk04 = 1;
    local.unk14 = param_2;

    FUN_008d5790(param_1, &local, FUN_00478b30);

    return local.unk10;
}
}   // namespace f3m_00478b70

// @f3 0x0047b310 (community match, verified in this file)
namespace f3m_0047b310 {
namespace f3m_0047b310 {
struct Point47b3
{
    float x, y, z;
};
void __cdecl FUN_004d72b0(Point47b3* pos);
struct Cell47b3
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Point47b3 pos;
    bool unk20;
    bool GridArray_SetCenter(int x, int y);
    bool GridCellArray_SetCenter(int x, int y);
};
}
using namespace f3m_0047b310;

static __forceinline void Move47b3(Cell47b3* c, int x, int y, bool& result)
{
    if (c->GridArray_SetCenter(x, y))
    {
        c->pos.x = (float)(x << 12);
        c->pos.y = (float)(y << 12);
        c->pos.z = 0.0f;
        FUN_004d72b0(&c->pos);
        c->unk20 = result;
        result = true;
    }
}

// pdb: GridCellArray::SetCenter | GridCell.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
bool Cell47b3::GridCellArray_SetCenter(int x, int y)
{
    bool r = false;
    Move47b3(this, x, y, r);
    return r;
}
}   // namespace f3m_0047b310

// @f3 0x0046e540 (community match, verified in this file)
namespace f3m_0046e540 {
struct Item {
    int unk00; int unk04; int unk08;
    int type;
    Item* FUN_005011d0(int flag);
};
struct Manager {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30;
    int unk34;
    Item* FUN_00b35640();
};
}
extern f3m_0046e540::Manager* DAT_0107a0d8;
extern int DAT_0106e1b8;
extern int DAT_0106e17c;
extern int DAT_0106e284;
// pdb: BGSSceneInfo::GetLoadedAreaNonActorMemoryBudgetCap | BGSSceneInfo.obj | fnv360_0822_retail, call_seq, medium
int __cdecl FUN_0046e540()
{
    int result = DAT_0106e1b8;
    if (DAT_0107a0d8->unk34 == 0) {
        f3m_0046e540::Item* item = DAT_0107a0d8->FUN_00b35640();
        while (item && item->FUN_005011d0(1))
            item = item->FUN_005011d0(1);
        if (item)
            result -= (item->type == 0x3c) ? DAT_0106e17c : DAT_0106e284;
    }
    return result;
}

// @f3 0x004652f0 (community match, verified in this file)
namespace f3m_004652f0 {
namespace f3m_004652f0 {
struct Elem {
    int a;
    int b;
    int c;
};
}
using namespace f3m_004652f0;

struct FUN_004652f0_cls {
    Elem* data;
    unsigned int size;
    unsigned int capacity;
    virtual void v00();
    virtual Elem* Allocate(unsigned int count);
    virtual void Free(Elem* p);
    unsigned int FUN_007a1650();
    void FUN_0079e680(Elem* dst, Elem* src, unsigned int count);
    void FUN_004652f0(unsigned int index, const Elem& item);
};

void FUN_004652f0_cls::FUN_004652f0(unsigned int index, const Elem& item)
{
    if (index == size) {
        data[FUN_007a1650()] = item;
        return;
    }
    if (size == capacity) {
        unsigned int newCap;
        if (capacity > 0x400)
            newCap = capacity + 0x400;
        else
            newCap = capacity * 2;
        Elem* newData = Allocate(newCap);
        FUN_0079e680(newData, data, index);
        FUN_0079e680(newData + index + 1, data + index, size - index);
        Free(data);
        data = newData;
        capacity = newCap;
    } else {
        FUN_0079e680(data + index + 1, data + index, size - index);
    }
    size++;
    data[index] = item;
}
}   // namespace f3m_004652f0

// @f3 0x0046e470 (community match, verified in this file)
namespace f3m_0046e470 {
namespace f3m_0046e470 {
struct Pt3_46e { float x, y, z; };
struct Pt2_46e
{
    float x, y;
    Pt2_46e() {}
    Pt2_46e(float ax, float ay) : x(ax), y(ay) {}
};
int FUN_0046dd60(const Pt2_46e* p, void* arg);
int FUN_0046deb0(float v, void* arg);
int FUN_0046de00(const Pt3_46e* p, void* arg);
}
using namespace f3m_0046e470;
// pdb: BGSPrimitive::CreateAbstract | BGSPrimitive.obj | fnv360_0822_retail, call_gap, low
// pdb params: eType, aRadii, aColor
int FUN_0046e470(int type, const Pt3_46e* v, void* arg)
{
    switch (type)
    {
    case 1:
    {
        Pt3_46e p;
        p.x = (float)(v->x * 2.0);
        p.y = (float)(v->y * 2.0);
        p.z = (float)(v->z * 2.0);
        return FUN_0046de00(&p, arg);
    }
    case 2:
        return FUN_0046deb0(v->x, arg);
    case 3:
    {
        Pt2_46e a(v->x, v->z);
        Pt2_46e b = a;
        b.x = (float)(b.x * 2.0);
        b.y = (float)(b.y * 2.0);
        return FUN_0046dd60(&b, arg);
    }
    }
    return 0;
}
}   // namespace f3m_0046e470

// @f3 0x0047d1a0 (community match, verified in this file)
namespace f3m_0047d1a0 {
struct Object999 { signed char FUN_0040e260(); };
struct Node999 { Object999* object00; Node999* next04; };
struct Owner999 { Node999* head00; int FUN_0047d1a0(); };
// pdb: ItemChange::GetHotKey | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
int Owner999::FUN_0047d1a0() {
    Node999* node = head00;
    int result = -1;
    do {
        if (!node) break;
        if (!node->object00) break;
        if (node->object00->FUN_0040e260() >= 0) result = node->object00->FUN_0040e260();
        node = node->next04;
    } while (result < 0);
    return result;
}
}   // namespace f3m_0047d1a0

// @f3 0x0046c490 (community match, verified in this file)
namespace f3m_0046c490 {
namespace f3m_0046c490 {
struct RefObj {
    virtual void v00();
    virtual void DeleteThis();
    volatile long refCount;
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (!InterlockedDecrement(&refCount)) DeleteThis(); }
};
class Base46 {
public:
    Base46(int a, int b, int c);
    virtual ~Base46();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int m040;
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
    unsigned char m0e4;
    unsigned char m0e5;
    unsigned short unk0e6;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int m0fc;
    int m100;
};
}
using namespace f3m_0046c490;

class FUN_0046c490 : public Base46 {
public:
    NiPointer<RefObj> m104;
    FUN_0046c490(int a, int b, int c);
    virtual ~FUN_0046c490();
};

// pdb: BSPortal::BSPortal | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arCenter, arHalfExtents, arRotation
FUN_0046c490::FUN_0046c490(int a, int b, int c) : Base46(a, b, c)
{
    m0e4 = 1;
    m0e5 = 1;
    m040 = 0;
    m100 = 0;
    m0fc = 0;
    m104 = 0;
}
}   // namespace f3m_0046c490

// @f3 0x004650c0 (community match, verified in this file)
namespace f3m_004650c0 {
namespace f3m_004650c0 {
struct Elem {
    int a;
    int b;
    int c;
};
typedef bool (__cdecl *ElemPred)(Elem* item, void* key);
}
using namespace f3m_004650c0;

struct FUN_004650c0_cls {
    void* vtable;
    Elem* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int FUN_004650c0(void* key, unsigned int start, ElemPred pred);
};

// pdb: BSSimpleArray<NavMeshEdgeHandle,1024>::Find<NavMeshEdgeHandle> | NavMeshObstacleCutter.obj | fnv360_0822_retail, call_gap, low
// pdb params: aValue, aiStartIndex, apFunc
unsigned int FUN_004650c0_cls::FUN_004650c0(void* key, unsigned int start, ElemPred pred)
{
    for (unsigned int i = start; i < size; i++) {
        if (data && pred(&data[i], key))
            return i;
    }
    return 0xffffffff;
}
}   // namespace f3m_004650c0

// @f3 0x00472c60 (community match, verified in this file)
namespace f3m_00472c60 {
struct Model {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual const char* GetPath();
};
struct Scene;
struct Entry {
    void* key;
    Model* model;
    Scene* scene;
    int unk0C;
};
struct Mgr { void FUN_006f2440(Scene* s); };
struct Loader { void FUN_00429640(const char* path, bool a, bool b); };
}
using namespace f3m_00472c60;
extern Mgr* DAT_0107a79c;
extern Loader* DAT_0106ca70;
bool __cdecl FUN_00724400();
void __cdecl FUN_00470770(Scene* s);
struct Biped_00472c60 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28;
    Entry entries[20];
    void FUN_00471020(Scene* s);
    void FUN_00472c60(void* key);
};
// pdb: BipedAnim::RemovePart | BipedAnim.obj | fnv360_0721_beta, objrun, low, conflict (skyrim: BipedAnim::QueueHelmetLoad)
// pdb params: apObj
void Biped_00472c60::FUN_00472c60(void* key)
{
    if (!key)
        return;
    for (int i = 0; i < 20; ++i) {
        Entry* e = &entries[i];
        if (e->key == key) {
            if (e->scene) {
                FUN_00471020(e->scene);
                if (!FUN_00724400())
                    FUN_00470770(e->scene);
                else
                    DAT_0107a79c->FUN_006f2440(e->scene);
                const char* path = e->model->GetPath();
                DAT_0106ca70->FUN_00429640(path, true, true);
                e->scene = 0;
            }
            e->key = 0;
            e->model = 0;
        }
    }
}

// @f3 0x00469000 (community match, verified in this file)
namespace f3m_00469000 {
namespace f3m_00469000 {
struct Form_469000 { int unk00; unsigned char typeID; };
struct Obj_469000 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    Form_469000* unk1C;
};
}
using namespace f3m_00469000;
// pdb: BGSDecalManager::IsValidDecalImpact | BGSDecalManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apCollidee, aeDecalType
bool __cdecl FUN_00469000(Obj_469000* obj)
{
    switch (obj->unk1C->typeID)
    {
    case 0x23:
    case 0x2a:
    case 0x2b:
    case 0x33:
        return false;
    default:
        return true;
    }
}
}   // namespace f3m_00469000

// @f3 0x0047ca30 (community match, verified in this file)
namespace f3m_0047ca30 {
// pdb: BSRoundToNearest | InventoryChanges.obj | fnv360_0822_debug, call_seq, medium
// pdb params: afVal, afNearest
float FUN_0047ca30(float value, float step)
{
    value = value / step;
    int add = (value - (int)value < 0.5) ? 0 : 1;
    return ((int)value + add) * step;
}
}   // namespace f3m_0047ca30

// @f3 0x004721c0 (community match, verified in this file)
namespace f3m_004721c0 {
struct Owner1020 {
    int unk00;
    void** items04;
    unsigned short capacity08, size0A, unk0C, growth0E;
    void FUN_005574c0(unsigned int capacity);
    void FUN_00470f10(unsigned int index, void* value);
    unsigned int FUN_004721c0(void* value);
};
// pdb: NiTArray<NiPointer<NiAVObject>,NiTNewInterface<NiPointer<NiAVObject> > >::Add | BipedAnim.obj | fnv360_0822_retail, caller_sim, low
// pdb params: element
unsigned int Owner1020::FUN_004721c0(void* value) {
    unsigned int capacity = capacity08;
    unsigned int index = size0A;
    if (index >= capacity) FUN_005574c0(index + growth0E);
    FUN_00470f10(index, value);
    return index;
}
}   // namespace f3m_004721c0

// @f3 0x004690f0 (community match, verified in this file)
extern char DAT_00dbe7e4;
namespace f3m_004690f0 {
struct Owner1027 {
    void* vtable000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int value090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int value0BC, value0C0;
    volatile int value0C4;
    void FUN_00833810(int value);
    Owner1027* FUN_004690f0(int value);
};
// pdb: BSCullingProcess::BSCullingProcess | BGSDecalManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apVisibleSet
Owner1027* Owner1027::FUN_004690f0(int value) {
    FUN_00833810(value);
    value090 = 0;
    value0BC = 0;
    value0C0 = 0;
    vtable000 = &DAT_00dbe7e4;
    value0C4 = 0;
    return this;
}
}   // namespace f3m_004690f0

// @f3 0x0047b560 (community match, verified in this file)
namespace f3m_0047b560 {
namespace f3m_0047b560 {
struct Cell {
    void* __thiscall FUN_004e4e60(int arg);
};
struct Grid {
    int unk00; int unk04; int unk08;
    unsigned int size;
    Cell** cells;
    Cell** GetCellPtr(unsigned int x, unsigned int y) {
        return (x < size && y < size) ? &cells[x * size + y] : 0;
    }
    void __thiscall GridCellArray_AttachToWorld(int arg, unsigned int x, unsigned int y);
};
}
using namespace f3m_0047b560;
// pdb: GridCellArray::AttachToWorld | GridCell.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap_sim), high
void __thiscall Grid::GridCellArray_AttachToWorld(int arg, unsigned int x, unsigned int y)
{
    Cell* cell = *GetCellPtr(x, y);
    if (cell)
        cell->FUN_004e4e60(arg);
}
}   // namespace f3m_0047b560

// @f3 0x00477a90 (community match, verified in this file)
extern float DAT_00dbe1e0;
extern float DAT_00db8b4c;
extern float DAT_00dc0a88;
extern float DAT_00dc0a84;
namespace f3m_00477a90 {
struct Cls_477a90 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    volatile float unk10;
    volatile float unk14;
    volatile float unk18;
    volatile float unk1C;
    volatile float unk20;
    volatile float unk24;
    volatile float unk28;
    volatile float unk2C;
    volatile float unk30;
    volatile float unk34;
    volatile float unk38;
    volatile float unk3C;
    Cls_477a90* FUN_00477a90();
};


// pdb: hkMouseSpringActionCinfo::hkMouseSpringActionCinfo | GlobalFunc.obj | fnv360_0822_debug, call_gap, low
Cls_477a90* Cls_477a90::FUN_00477a90() {
    unk00 = 0;
    unk04 = 0;
    unk10 = 0.0f;
    unk14 = 0.0f;
    unk18 = 0.0f;
    unk1C = 0.0f;
    unk20 = 0.0f;
    unk24 = 0.0f;
    unk28 = 0.0f;
    unk2C = 0.0f;
    unk10 = 0.0f;
    unk14 = 0.0f;
    unk18 = 0.0f;
    unk1C = 0.0f;
    unk20 = 0.0f;
    unk24 = 0.0f;
    unk28 = 0.0f;
    unk2C = 0.0f;
    unk30 = DAT_00dbe1e0;
    unk34 = DAT_00db8b4c;
    unk38 = DAT_00dc0a88;
    unk3C = DAT_00dc0a84;
    return this;
}
}   // namespace f3m_00477a90

// @f3 0x004754d0 (community match, verified in this file)
namespace f3m_004754d0 {
namespace f3m_004754d0 {
struct Plane_4754d0 {
    float x;
    float y;
    float z;
    float d;
};
struct Sphere_4754d0 {
    float x;
    float y;
    float z;
    float radius;
    int FUN_004754d0(const Plane_4754d0& s);
};
// pdb: NiBound::WhichSide | GlobalFunc.obj | tesv_win, objopen_prop, low
int Sphere_4754d0::FUN_004754d0(const Plane_4754d0& s)
{
    float dist = s.x * x + s.y * y + s.z * z;
    dist = dist - s.d;
    if (dist <= -radius)
        return 2;
    if (dist >= radius)
        return 1;
    return 0;
}
}
}   // namespace f3m_004754d0

// @f3 0x0047e4f0 (community match, verified in this file)
namespace f3m_0047e4f0 {
namespace f3m_0047e4f0 {
struct Counter { int __thiscall FUN_00452c40(int key); };
struct Source { Counter* __thiscall FUN_004e66c0(); };
struct Item { int unk00; int extra; int key; };
struct Node { Item* item; Node* next; };
struct List {
    Node* head;
    Node* Find(int key) {
        Node* node = head;
        bool searching = true;
        while (node && searching) {
            if (node->item && node->item->key == key)
                searching = false;
            else
                node = node->next;
        }
        return node;
    }
};
struct Owner {
    List list;
    Source* source;
    int __thiscall InventoryChanges_GetObjectCount(int key);
};
}
using namespace f3m_0047e4f0;
// pdb: InventoryChanges::GetObjectCount | InventoryChanges.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(objrun_prop), high
int __thiscall Owner::InventoryChanges_GetObjectCount(int key)
{
    Counter* c = source ? source->FUN_004e66c0() : 0;
    int count;
    if (c)
        count = c->FUN_00452c40(key);
    else
        count = 0;
    if (count < 0)
        count = -count;
    Node* node = list.Find(key);
    if (node) {
        Item* it = node->item;
        if (it) {
            if (!count && !it->extra)
                return 1;
            count += it->extra;
        }
    }
    return count;
}
}   // namespace f3m_0047e4f0

// @f3 0x0046d150 (community match, verified in this file)
namespace f3m_0046d150 {
namespace f3m_0046d150 {
struct Color46d150 {
    float r, g, b, a;
};
struct GeomData46d150 {
    int unk00; int unk04;
    unsigned short vertexCount;
    unsigned short unk0A;
    int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24;
    Color46d150* colors;
    void FUN_008313b0(unsigned int flags);
};
struct Geom46d150 {
    char unk00[0x30];
    unsigned int flags;
    char unk34[0xb8 - 0x34];
    GeomData46d150* data;
    void SetAppCulled(bool culled)
    {
        if (culled)
            flags |= 1;
        else
            flags &= ~1;
    }
};
struct Obj46d150 {
    int unk00; int unk04;
    Color46d150 color;
    int unk18; int unk1C; int unk20;
    Geom46d150* geom24;
    Geom46d150* geom28;
    void FUN_0046d150(const Color46d150* c);
};

// pdb: BGSPrimitiveBox::SetColor | BGSPrimitive.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BGSPrimitiveBox::SetRadii)
// pdb params: aColor
void Obj46d150::FUN_0046d150(const Color46d150* c)
{
    color = *c;
    if (geom24)
    {
        GeomData46d150* data = geom24->data;
        Color46d150* p = data->colors;
        for (int i = 0; i < data->vertexCount; i++)
        {
            *p = color;
            p++;
        }
        data->FUN_008313b0(4);
        data = geom28->data;
        p = data->colors;
        for (int i = 0; i < data->vertexCount; i++)
        {
            *p = color;
            p++;
        }
        data->FUN_008313b0(4);
        geom28->SetAppCulled(c->a < 0.001);
    }
}
}
}   // namespace f3m_0046d150

// @f3 0x00469ae0 (community match, verified in this file)
struct MemMgr {
    void Deallocate(void* memory);
};
extern MemMgr g_memMgr;

struct CritSect_169ae0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct ManagerStub {
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
    CritSect_169ae0 unk80;
};
extern ManagerStub* g_manager;

extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(CritSect_169ae0* section);
extern "C" __declspec(dllimport) void __stdcall fnv_LeaveCriticalSection(CritSect_169ae0* section);

struct RenderQuery {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    RenderQuery* unk1C;

    unsigned char FUN_00c4edf0(unsigned int* value, int flag);
    void FUN_00c4ed40();
};

struct Node_169ae0 {
    Node_169ae0* unk00;
    int unk04;
    RenderQuery* unk08;
};

struct Owner_00469ae0 {
    int unk00;
    int unk04;
    Node_169ae0* unk08;
    int unk0C;
    unsigned int unk10;

    void FUN_00469ae0();
};

// pdb: BSPerformanceTimerManager::BeginFrame | BSPerformanceTimer.obj | fnv360_0822_debug, call_gap_sim, low
void Owner_00469ae0::FUN_00469ae0()
{
    if (unk10 > 0) {
        fnv_EnterCriticalSection(&g_manager->unk80);

        Node_169ae0* node = unk08;
        while (node) {
            RenderQuery** slot = &node->unk08;
            node = node->unk00;
            if (*slot != 0) {
                RenderQuery* query = *slot;
                RenderQuery* obj = query->unk1C;
                if (obj != 0) {
                    unsigned int value = 0;
                    obj->FUN_00c4edf0(&value, 1);
                    RenderQuery* released = query->unk1C;
                    if (released != 0) {
                        released->FUN_00c4ed40();
                        g_memMgr.Deallocate(released);
                    }
                    query->unk1C = 0;
                }
            }
        }

        fnv_LeaveCriticalSection(&g_manager->unk80);
    }
}

// @f3 0x00470bc0 (community match, verified in this file)
namespace f3m_00470bc0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

struct RefObj {
    virtual void vf00();
    virtual void DeleteThis();
    volatile long refCount;
};

struct RefPtr {
    RefObj* p;
    RefPtr() : p(0) {}
    ~RefPtr() { if (p && InterlockedDecrement(&p->refCount) == 0) p->DeleteThis(); }
};

struct Owner {
    char unk00[0xdb8];
    RefPtr sp;
};

extern Owner* DAT_01073a08;
}
using namespace f3m_00470bc0;

RefObj* __cdecl FUN_00470bc0() {
    return (DAT_01073a08 ? DAT_01073a08->sp : RefPtr()).p;
}

// @f3 0x00470480 (community match, verified in this file)
namespace f3m_00470480 {
namespace f3m_00470480 {
class Target
{
public:
    void FUN_004700e0(int a, int b, int c);
};
struct Pair
{
    Target* target;
    int value;
};
// pdb: BGSTextureUseMap::TexUseCB | BGSTextureUseMap.obj | fnv360_0721_beta, objrun, medium
// pdb params: apTexture, aulMemorySize, apParam
void __cdecl FUN_00470480(int a, int b, Pair* p)
{
    if (p->target)
        p->target->FUN_004700e0(a, b, p->value);
}
}
}   // namespace f3m_00470480

// @f3 0x004758a0 (community match, verified in this file)
namespace f3m_004758a0 {
namespace f3m_004758a0 {
// pdb: IsAFloat | GlobalFunc.obj | fnv360_0822_retail, call_gap, medium
// pdb params: str
int FUN_004758a0(const char* s)
{
    bool dot = false;
    char c = *s++;
    if (c == 0)
        return 0;
    if (!((c >= '0' && c <= '9') || c == '-' || c == '.'))
        return 0;
    if (*s == 0 && (c == '-' || c == '.'))
        return 0;
    if (c == '.')
        dot = true;
    for (char ch = *s++; ch; ch = *s++) {
        if ((ch < '0' || ch > '9') && (ch != '.' || dot))
            return 0;
        if (ch == '.')
            dot = true;
    }
    return 1;
}
}
}   // namespace f3m_004758a0

// @f3 0x00474ba0 (community match, verified in this file)
// FUN_00474ba0 - singleton getter with lazy creation
// 00474ae0 constructs the 8-byte object; 0086b930 is MemoryManager::Allocate.

class MemoryManager {
public:
    void* Allocate(unsigned int bytes);
};

extern MemoryManager DAT_011f6238;

class Holder_474ba0 {
public:
    int unk00;
    int unk04;
    Holder_474ba0();
    static void* operator new(unsigned int bytes) { return DAT_011f6238.Allocate(bytes); }
};

extern Holder_474ba0* DAT_0106e578;

// pdb: BSClonePools::GetInstance | BSClonePool.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abCreate
Holder_474ba0* __cdecl FUN_00474ba0(char create)
{
    if (!DAT_0106e578 && create)
        DAT_0106e578 = new Holder_474ba0;
    return DAT_0106e578;
}

// @f3 0x00477f60 (community match, verified in this file)
namespace f3m_00477f60 {
struct Vec3_477f60 {
    float x;
    float y;
    float z;
};

int __cdecl FUN_00476720(const Vec3_477f60* v, float r);

// pdb: LengthCheck | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aPt1, aPt2, afCompLength
int __cdecl FUN_00477f60(const Vec3_477f60* a, const Vec3_477f60* b, float r)
{
    Vec3_477f60 d;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    return FUN_00476720(&d, r);
}
}   // namespace f3m_00477f60

// @f3 0x00477d30 (community match, verified in this file)
namespace f3m_00477d30 {
struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;
struct Vert {
    float x, y, z;
    Vert() {}
    static void* operator new[](unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};
struct Data {
    int unk00; int unk04;
    unsigned short count;
    unsigned short unk0A;
    int unk0C; int unk10; int unk14; int unk18; int unk1C;
    unsigned int src;
};
struct Obj {
    char pad[0x68];
    char transform[0x50];
    Data* data;
};
}
extern void (__cdecl* g_011aa050)(unsigned short count, unsigned int src, void* out, void* xf);
using namespace f3m_00477d30;
// pdb: CreateWorldVertices | GlobalFunc.obj | fnv360_0822_retail, objrun, medium
// pdb params: apGeom
Vert* __cdecl FUN_00477d30(Obj* obj)
{
    if (!obj || !obj->data->count)
        return 0;
    Vert* out = new Vert[obj->data->count];
    g_011aa050(obj->data->count, obj->data->src, out, obj->transform);
    return out;
}

// @f3 0x0047d260 (community match, verified in this file)
namespace f3m_0047d260 {
struct Object1045 { bool ExtraDataList_GetWorn(bool highOnly); };
struct Node1045 { Object1045* object00; Node1045* next04; };
struct Owner1045 { Node1045* head00; bool ItemChange_GetWorn(bool highOnly); };
// pdb: ItemChange::GetWorn | InventoryChanges.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
bool Owner1045::ItemChange_GetWorn(bool highOnly) {
    Node1045* node = head00;
    while (node) {
        Object1045* object = node->object00;
        if (!object) break;
        if (object->ExtraDataList_GetWorn(highOnly)) return true;
        node = node->next04;
    }
    return false;
}
}   // namespace f3m_0047d260

// @f3 0x00478ae0 (community match, verified in this file)
namespace f3m_00478ae0 {
namespace f3m_00478ae0 {
struct Search_478ae0
{
    int unk00;
    bool flag;
    int type;
    int unk0C;
    int key;
    int result;
    int unk18;
};
}
using namespace f3m_00478ae0;
void FUN_008d5790(void* root, Search_478ae0* search, void (*cb)(void*, Search_478ae0*));
void FUN_00478ab0(void* node, Search_478ae0* search);
// pdb: GetHavokWorldObjectIndexInSceneGraph | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRoot, apWorldObject
int FUN_00478ae0(void* root, int key)
{
    Search_478ae0 s;
    s.type = 0x12;
    s.flag = true;
    s.unk0C = 0;
    s.key = key;
    s.result = -1;
    FUN_008d5790(root, &s, FUN_00478ab0);
    int r = s.result;
    if (r == -1)
        r = -1;
    return r;
}
}   // namespace f3m_00478ae0

// @f3 0x00474fe0 (community match, verified in this file)
namespace f3m_00474fe0 {
struct Manager1068 { void FUN_00474c70(int first, int second); };
Manager1068* __cdecl FUN_00474ba0(bool create);
struct Owner1068 { int first00, second04, result08; Owner1068* FUN_00474fe0(int first, int second); };
// pdb: BSCloneReserver::BSCloneReserver | BSClonePool.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apLoadedObject, aiCloneCount
Owner1068* Owner1068::FUN_00474fe0(int first, int second) {
    first00 = first;
    second04 = second;
    result08 = 0;
    if (first && second) FUN_00474ba0(true)->FUN_00474c70(first, second);
    return this;
}
}   // namespace f3m_00474fe0

// @f3 0x0046c5e0 (community match, verified in this file)
extern char DAT_00dbeef4;
namespace f3m_0046c5e0 {
struct Vector1106 { float x, y, z; };
struct Owner1106 {
    void* vtable00;
    int unk04, unk08;
    Vector1106 first0C, second18;
    void FUN_00aad5f0();
    Owner1106* FUN_0046c5e0(const Vector1106* first, const Vector1106* second);
};
// pdb: BSMultiBoundAABB::BSMultiBoundAABB | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arCenter, arHalfExtents
Owner1106* Owner1106::FUN_0046c5e0(const Vector1106* first, const Vector1106* second) {
    FUN_00aad5f0();
    vtable00 = &DAT_00dbeef4;
    first0C = *first;
    second18 = *second;
    return this;
}
}   // namespace f3m_0046c5e0

// @f3 0x0047fe70 (community match, verified in this file)
namespace f3m_0047fe70 {
struct FUN_0047fe70_Elem {
    virtual void unk00(int flags);
    int unk04;
    unsigned char FUN_0040c080(int mode);
    short FUN_0040ac80();
};

struct FUN_0047fe70_Node {
    FUN_0047fe70_Elem* unk00;
    FUN_0047fe70_Node* unk04;
    void FUN_00421610(FUN_0047fe70_Elem** elem);
};

struct FUN_0047fe70_cls {
    FUN_0047fe70_Node* unk00;
    int FUN_0047fe70();
};

int FUN_0047fe70_cls::FUN_0047fe70()
{
    int total = 0;
    FUN_0047fe70_Node* node = unk00;
    FUN_0047fe70_Elem* tmp;
    FUN_0047fe70_Elem* elem;
    while (node != 0 && (elem = node->unk00) != 0) {
        tmp = elem;
        if (elem->FUN_0040c080(0))
            total += elem->FUN_0040ac80();
        node = node->unk04;
        if (elem->unk04 == 0) {
            unk00->FUN_00421610(&tmp);
            elem->unk00(1);
            node = unk00;
            total = 0;
        }
    }
    return total;
}
}   // namespace f3m_0047fe70

// @f3 0x0047b6e0 (community match, verified in this file)
namespace f3m_0047b6e0 {
class Elem_0047b6e0 {
public:
    void FUN_004d70f0();
};

class Owner_0047b6e0 {
public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
    Elem_0047b6e0** unk10;
    void FUN_0047b6e0();
};

// pdb: GridCellArray::RunAnimations | GridCell.obj | fnv360_0822_retail, call_seq, medium
void Owner_0047b6e0::FUN_0047b6e0()
{
    unsigned int i = 0;
    while (i < unk0C) {
        unsigned int j = 0;
        while (j < unk0C) {
            Elem_0047b6e0* e = *((i < unk0C && j < unk0C) ? &unk10[i * unk0C + j] : 0);
            if (e) {
                e->FUN_004d70f0();
            }
            ++j;
        }
        ++i;
    }
}
}   // namespace f3m_0047b6e0

// @f3 0x00477d90 (community match, verified in this file)
namespace f3m_00477d90 {
struct Owner477;

struct Node477 {
    virtual void v00() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual Owner477* v0C();
};

struct Owner477 {
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
    int unk9C;
    Node477** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

int __cdecl FUN_00424fe0(Node477* node);

// pdb: FindFirstCollisionObject | GlobalFunc.obj | fnv360_0822_debug, caller, medium
// pdb params: ap3D
int __cdecl FUN_00477d90(Node477* node)
{
    int result = 0;
    if (node != 0) {
        result = FUN_00424fe0(node);
        if (result == 0) {
            Owner477* owner = node->v0C();
            if (owner != 0) {
                unsigned int count = owner->unkA6;
                for (unsigned int i = 0; i < count; i++) {
                    Node477* child = owner->unkA0[i];
                    result = FUN_00477d90(child);
                    if (result != 0)
                        break;
                }
            }
        }
    }
    return result;
}
}   // namespace f3m_00477d90

// @f3 0x0047ba30 (community match, verified in this file)
struct FUN_0047ba30_res {
    virtual void unk00();
    virtual void Release();
    int unk04;
};
struct FUN_00af0de0_owner {
    void FUN_00af0de0(int v);
};
extern FUN_0047ba30_res* DAT_0116f3d8;
extern FUN_00af0de0_owner* DAT_0116ef98;
extern unsigned char FUN_00f4c96c;
extern int (__stdcall* FUN_00d9b064)(void*);

struct FUN_0047ba30_owner {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_0047ba30_res* unk24;
    void FUN_0047ba30();
};

// pdb: GridCellArray::ClearCanopyShadowMaskTexture | GridCell.obj | fnv360_0822_debug, caller, medium
void FUN_0047ba30_owner::FUN_0047ba30() {
    if (unk24 == 0) return;
    int (__stdcall* fn)(void*) = FUN_00d9b064;
    if (DAT_0116f3d8 != 0) {
        FUN_0047ba30_res* s = DAT_0116f3d8;
        if (fn((char*)DAT_0116f3d8 + 4) == 0) s->Release();
        DAT_0116f3d8 = 0;
    }
    DAT_0116ef98->FUN_00af0de0((int)unk24);
    FUN_0047ba30_res* q = unk24;
    if (q != 0) {
        if (fn((char*)q + 4) == 0) q->Release();
        unk24 = 0;
    }
    FUN_00f4c96c = 1;
}

// @f3 0x0046cfd0 (community match, verified in this file)
extern char DAT_0108ec68;
namespace f3m_0046cfd0 {
void FUN_00f72574();

struct Vec2 {
    float x;
    float y;
    Vec2(float a, float b) { x = a; y = b; }
};

struct Obj {
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
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
    Obj(void* a, Vec2 const& v, void* b);
};

struct Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;

    Obj* FUN_0046cfd0();
};

// pdb: BGSPrimitivePlane::MakePortal | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
Obj* Owner::FUN_0046cfd0() {
    return new Obj(&DAT_0108ec68, Vec2(unk18, unk20), (void*)FUN_00f72574);
}
}   // namespace f3m_0046cfd0

// @f3 0x004759f0 (community match, verified in this file)
extern double DAT_00dc0778;
extern double DAT_00dc0770;
extern double DAT_00dc0760;
extern float DAT_00db38b8;
namespace f3m_004759f0 {

// pdb: GetAngleDelta | GlobalFunc.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
float GetAngleDelta(float from, float to, float* out)
{
    float d = to - from;
    *out = 0.0f;
    if (d != 0.0f) {
        *out = 1.0f;
        if (d < 0.0f) {
            if (d > DAT_00dc0778) {
                *out = DAT_00db38b8;
                return d;
            }
            return (float)(d + DAT_00dc0760);
        }
        if (d > DAT_00dc0770) {
            *out = DAT_00db38b8;
            return (float)(DAT_00dc0760 - d);
        }
    }
    return d;
}
}   // namespace f3m_004759f0

// @f3 0x0046c290 (community match, verified in this file)
namespace f3m_0046c290 {
struct Owner_0046c290 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float unk18;
    float unk1C;
    float unk20;
    unsigned char FUN_0046c290(const float* v) const;
};

// pdb: BGSPrimitivePlane::IsInside | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: aPoint
unsigned char Owner_0046c290::FUN_0046c290(const float* v) const
{
    return !(v[0] < -unk18) && !(v[1] < -unk1C) && !(v[2] < -unk20) && !(v[0] > unk18) && !(v[1] > unk1C) && !(v[2] > unk20);
}
}   // namespace f3m_0046c290

// @f3 0x0047d5b0 (community match, verified in this file)
#include <string.h>
extern const char* DAT_00f62e14;
extern const char DAT_00db3438[];
namespace f3m_0047d5b0 {


class TESBoundObject {
public:
    virtual void unkVirt() {}
};

class TESFullName {
public:
    virtual void unkVirt() {}
    const char* unk04;
    unsigned short unk08;
};

struct Owner_0047d5b0 {
    int unk00;
    int unk04;
    TESBoundObject* unk08;
    const char* FUN_0047d5b0();
};

// pdb: ItemChange::GetFullName | InventoryChanges.obj | fnv360_0822_retail, call_dedup, medium
const char* Owner_0047d5b0::FUN_0047d5b0()
{
    TESBoundObject* obj = unk08;
    TESFullName* n = dynamic_cast<TESFullName*>(obj);
    if (n != 0) {
        unsigned int len;
        if (n->unk08 == 0xffff) {
            len = strlen(n->unk04);
        } else {
            len = n->unk08;
        }
        if (len != 0) {
            if (n->unk04 != 0) {
                return n->unk04;
            }
            return DAT_00db3438;
        }
    }
    return DAT_00f62e14;
}
}   // namespace f3m_0047d5b0

// @f3 0x00474ae0 (community match, verified in this file)
namespace f3m_00474ae0 {
void __cdecl FUN_006c8220();
struct Pair1187 { void* first; void* second; Pair1187():first(0),second(0){} ~Pair1187(); };
struct FUN_00474ae0 { Pair1187 pair; FUN_00474ae0(); };
// pdb: BSSimpleList<BSClonePools::ClonePool *>::RemoveAll | BSClonePool.obj | fnv360_0721_beta, call_seq, medium
FUN_00474ae0::FUN_00474ae0() { FUN_006c8220(); }
}   // namespace f3m_00474ae0

// @f3 0x00471020 (community match, verified in this file)
extern void* DAT_0106e804;
namespace f3m_00471020 {
struct Obj471;
struct Entry471;
struct Node471 {
    Node471* next;
    int unk04;
    Obj471* key;
};
struct Mgr471 {
    Entry471* FUN_00824a50(void* arg);
    void FUN_00824b10(void* arg);
};
struct Entry471 {
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
    Node471* unk34;
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
    Obj471** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};
struct Obj471 {
    virtual void vf00() {}
    virtual void vf04() {}
    virtual void vf08() {}
    virtual Entry471* vf0C() { return 0; }
    virtual void vf10() {}
    virtual void vf14() {}
    virtual void vf18() {}
    virtual int vf1C() { return 0; }
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
};
struct Owner471 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Mgr471* unk10;
    void FUN_00471020(Obj471* obj);
};
// pdb: BipedAnim::RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRoot
void Owner471::FUN_00471020(Obj471* obj)
{
    if (!obj) return;
    Mgr471* mgr = unk10;
    Entry471* table = mgr->FUN_00824a50(DAT_0106e804);
    if (!table) return;
    if (obj->vf1C() != 0) {
        if (obj->unkBC == 0) return;
        Node471* n = table->unk34;
        if (!n) return;
        do {
            Obj471*& key = n->key;
            Node471* found = n;
            n = n->next;
            if (obj == key) {
                if (found) mgr->FUN_00824b10(DAT_0106e804);
                return;
            }
        } while (n);
        return;
    }
    Entry471* e = obj->vf0C();
    if (!e) return;
    int i = 0;
    if ((unsigned short)e->unkA6 <= (unsigned short)i) return;
    do {
        FUN_00471020(e->unkA0[i]);
        ++i;
    } while ((unsigned int)i < e->unkA6);
}
}   // namespace f3m_00471020

// @f3 0x00474c20 (community match, verified in this file)
namespace f3m_00474c20 {
struct Pair1208 { int first,second;Pair1208():first(0),second(0){}~Pair1208();void FUN_005e3010(); };
struct FUN_00474c20 { int unk00;Pair1208 member04;FUN_00474c20(); };
// pdb: BSSimpleList<NiPointer<NiAVObject> >::RemoveAll | BSClonePool.obj | fnv360_0721_beta, call_gap, low
FUN_00474c20::FUN_00474c20() { unk00=0;member04.FUN_005e3010(); }
}   // namespace f3m_00474c20

// @f3 0x004789f0 (community match, verified in this file)
namespace f3m_004789f0 {
struct FUN_004789f0_Opts {
    int unk00;
    unsigned char unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

int __cdecl FUN_008d5790(int a, FUN_004789f0_Opts* opts, void* callback);
void __cdecl FUN_00478960();

// pdb: GetCollisionObjectCountInSceneGraph | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRoot, abIgnoreWeaponBone, abIgnoreFadeNodes, abIgnoreArrows
int __cdecl FUN_004789f0(int a, unsigned char b, unsigned char c, unsigned char d)
{
    FUN_004789f0_Opts o;
    o.unk08 = 0x12;
    o.unk04 = 1;
    o.unk0C = 0;
    o.unk18 = 0;
    if (b) {
        o.unk18 = 1;
    }
    if (c) {
        o.unk18 |= 2;
    }
    if (d) {
        o.unk18 |= 4;
    }
    FUN_008d5790(a, &o, (void*)&FUN_00478960);
    return o.unk0C;
}
}   // namespace f3m_004789f0

// @f3 0x0047b500 (community match, verified in this file)
namespace f3m_0047b500 {
struct Next1223 {void TESObjectLAND_InitDistantTextureBlending();};
struct Item1223 {Next1223* TESObjectCELL_GetLand();};
struct Owner1223 {
 int unk00,unk04,unk08;unsigned int dimension;Item1223** items;
 __forceinline Item1223** At(unsigned int x,unsigned int y){if(x>=dimension||y>=dimension)return 0;return &items[dimension*x+y];}
 void FUN_0047b500();
};
// pdb: GridCellArray::UpdateDistantLandBlending | GridCell.obj | fnv360_0822_retail, call_gap_sim, low
void Owner1223::FUN_0047b500(){
 unsigned int count=dimension;
 for(unsigned int x=0;x<count;++x)for(unsigned int y=0;y<count;++y){Item1223** slot=At(x,y);if(slot&&*slot)(*slot)->TESObjectCELL_GetLand()->TESObjectLAND_InitDistantTextureBlending();}
}
}   // namespace f3m_0047b500

// @f3 0x00475210 (community match, verified in this file)
#include <math.h>
extern double FUN_00dc0438;
extern float DAT_00f4c824;
namespace f3m_00475210 {
// pdb: NiASin | GlobalFunc.obj | fnv360_0822_retail, call_dedup, low
// pdb params: fValue
float __cdecl FUN_00475210(float value) {
    if (value > FUN_00dc0438) {
        if (value < 1.0f) return (float)asin(value); return DAT_00f4c824;
    }
    return -DAT_00f4c824;
}
}   // namespace f3m_00475210

// @f3 0x0046fa90 (community match, verified in this file)
#include <string.h>

namespace f3m_0046fa90 {
struct GlobalTimer
{
    void FUN_006bd950();
};
extern GlobalTimer DAT_00f4bf88;
extern GlobalTimer DAT_00f4bfa8;
extern GlobalTimer DAT_00f4bf68;
extern bool DAT_00f4be1c;
extern bool DAT_00f4be1d;
extern int DAT_00f4bf80;

struct Block40
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
};

struct Loader
{
    int unk00;
    Block40 block;

    void FUN_0046f930();
    void FUN_0046ef10(int a, Block40* block, int b, int c);
    void FUN_0046fa90(int a, bool flag, int b);
};

// pdb: BGSSceneInfo::CollectSceneDataFromNode | BGSSceneInfo.obj | fnv360_0721_beta, call_seq, medium
// pdb params: apNode, abIncludeAddonNodes, abTrackActors
void Loader::FUN_0046fa90(int a, bool flag, int b)
{
    DAT_00f4bf88.FUN_006bd950();
    DAT_00f4bfa8.FUN_006bd950();
    if (flag && DAT_00f4be1d && !DAT_00f4bf80)
        FUN_0046f930();
    memset(&block, 0, sizeof(block));
    FUN_0046ef10(a, &block, b, 0);
    if (DAT_00f4be1c)
        DAT_00f4bf68.FUN_006bd950();
}
}

// @f3 0x00478ce0 (community match, verified in this file)
struct FUN_00478ce0_Node {
    int unk00;
    FUN_00478ce0_Node* unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    FUN_00478ce0_Node* unk30;
};

struct FUN_00478ce0_Obj {
    virtual void vf00();
    virtual void vf04();
    virtual FUN_00478ce0_Node* vf08();

    int unk04;
    int unk08;
    FUN_00478ce0_Node* unk0C;
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
    FUN_00478ce0_Obj** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

extern FUN_00478ce0_Node DAT_0108f200;

inline void FUN_00478ce0_Obj::vf00() {
}

inline void FUN_00478ce0_Obj::vf04() {
}

inline FUN_00478ce0_Node* FUN_00478ce0_Obj::vf08() {
    return unk0C;
}

// pdb: SetPhase | GlobalFunc.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: GetCollisionObjectIndexInSceneGraph)
// pdb params: apNode, afPhase
void __cdecl FUN_00478ce0(FUN_00478ce0_Obj* object, float value) {
    if (object == 0) {
        return;
    }

    FUN_00478ce0_Node* node = object->unk0C;
    while (node != 0) {
        node->unk10 = value;
        node = node->unk30;
    }

    for (unsigned int index = 0; index < object->unkA6; ++index) {
        FUN_00478ce0_Obj* child = object->unkA0[index];
        if (child != 0) {
            FUN_00478ce0_Node* current = child->vf08();
            while (current != 0) {
                if (current == &DAT_0108f200) {
                    FUN_00478ce0(child, value);
                    break;
                }
                current = current->unk04;
            }
        }
    }
}

// @f3 0x0047d0a0 (community match, verified in this file)
extern float FUN_00db38b8;
namespace f3m_0047d0a0 {
struct FUN_0040aca0_Obj {
    float FUN_0040aca0();
};

struct FUN_0047d0a0_Result {
    int unk00;
    int unk04;
    unsigned short unk08;
};

struct FUN_0047d0a0_Mid {
    FUN_0040aca0_Obj* unk00;
};

struct FUN_0047d0a0_Obj {
    FUN_0047d0a0_Mid* unk00;
    int unk04;
    int unk08;

    float FUN_0047d0a0();
};

extern FUN_0047d0a0_Result* __cdecl FUN_00c0050a(int, int, int, int, int);

// pdb: ItemChange::GetItemCharge | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
float FUN_0047d0a0_Obj::FUN_0047d0a0() {
    FUN_0047d0a0_Result* result = FUN_00c0050a(unk08, 0, 0xF460FC, 0xF46A4C, 0);
    if (result != 0) {
        FUN_0040aca0_Obj* p = 0;
        if (unk00 != 0)
            p = unk00->unk00;
        if (p != 0) {
            if (p->FUN_0040aca0() != -1.0f)
                return p->FUN_0040aca0();
            return (float)result->unk08;
        }
        return (float)result->unk08;
    }
    return -1.0f;
}
}   // namespace f3m_0047d0a0

// @f3 0x00475910 (community match, verified in this file)
#include <math.h>
namespace f3m_00475910 {
// pdb: ClampAngle | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afAngle
float __cdecl FUN_00475910(float value){
 if(value < 0.0f) {value=(float)(value+6.2831854820251465);value=(float)fmod((double)value,6.2831854820251465);*(volatile float*)&value=value;return value;}
 else if(value >= 6.2831854820251465) {value=(float)fmod((double)value,6.2831854820251465);*(volatile float*)&value=value;return value;}
 return value;
}
}   // namespace f3m_00475910

// @f3 0x00470e10 (community match, verified in this file)
namespace f3m_00470e10 {
struct NiAVObject
{
    void IncRefCount();
    void DecRefCount();
};

struct Pn4afe
{
    int unk00;
    NiPointer<NiAVObject>* unk04;
    unsigned short unk08;
    unsigned short unk0A;
    void FUN_00470e10();
};

// Decrements unk0A while the last entry of the unk04 pointer array is null, stopping at the first non-null entry or zero.
// @fnv 0x004afe50
// pdb: NiTArray<NiPointer<NiAVObject>,NiTNewInterface<NiPointer<NiAVObject> > >::UpdateSize | BipedAnim.obj | fnv360_0822_retail, call_seq, medium
void Pn4afe::FUN_00470e10()
{
    while (unk0A > 0)
    {
        if (unk04[unk0A - 1] != NiPointer<NiAVObject>(0))
        {
            break;
        }
        unk0A--;
    }
}
}   // namespace f3m_00470e10

// @f3 0x0047e310 (community match, verified in this file)
namespace f3m_0047e310 {
// FUN_0047e310: thiscall (this = owner: entries at +0, baseForm at +4), 2 stack params,
// returns the form whose key matched (or 0).

struct ContainerEntry47e310 {
    int count;
    void* form;
};

struct ContainerNode47e310 {
    ContainerEntry47e310* item;
    ContainerNode47e310* next;
};

struct Container47e310 {
    int unk00;
    ContainerNode47e310 list;

    bool FUN_004528c0(void* form);
};

struct BaseForm47e310 {
    Container47e310* FUN_004e66c0();
};

struct InventoryEntry47e310 {
    void* extraLists;
    int countDelta;
    void* form;
};

struct InventoryNode47e310 {
    InventoryEntry47e310* item;
    InventoryNode47e310* next;
};

int __cdecl FUN_005a7160(void* form);

struct Owner47e310 {
    InventoryNode47e310* entries;
    BaseForm47e310* baseForm;

    void* FUN_0047e310(int key, int* out);
};

// pdb: InventoryChanges::GetObjectbyPackObjType | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
// pdb params: aeObjectType, ainumb
void* Owner47e310::FUN_0047e310(int key, int* out)
{
    Container47e310* container = baseForm ? baseForm->FUN_004e66c0() : 0;
    void* form = 0;

    for (ContainerNode47e310* node = &container->list; node && !form; node = node->next) {
        form = node->item->form;
        if (form && FUN_005a7160(form) == key) {
            InventoryNode47e310* n = entries;
            bool searching = true;
            while (n && searching) {
                InventoryEntry47e310* e = n->item;
                if (e && e->form == form)
                    searching = false;
                else
                    n = n->next;
            }
            if (n && n->item) {
                if (n->item->countDelta + node->item->count)
                    *out = n->item->countDelta + node->item->count;
            } else {
                *out = node->item->count;
            }
        } else {
            form = 0;
        }
    }

    for (InventoryNode47e310* n = entries; n && !form; n = n->next) {
        form = n->item->form;
        if (form && FUN_005a7160(form) == key) {
            Container47e310* c = baseForm ? baseForm->FUN_004e66c0() : 0;
            if (!c->FUN_004528c0(form)) {
                int d = n->item->countDelta;
                if (d > 0)
                    *out = d;
            }
        } else {
            form = 0;
        }
    }

    return form;
}
}   // namespace f3m_0047e310

// @f3 0x0046e5c0 (community match, verified in this file)
namespace f3m_0046e5c0 {
void* __cdecl FUN_00c01530(void*, const void*, unsigned int);

struct Element46e5c0 {
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
};

// pdb: BSSimpleArray<PathSmootherPOVLink,1024>::_MoveItems | PathSmootherPOV.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apDestAddr, apSrcAddr, aiCount
void __stdcall FUN_0046e5c0(Element46e5c0* dest, Element46e5c0* source, unsigned int count)
{
    if (count > 0) {
        if (dest < source) {
            for (unsigned int i = 0; i < count; i++)
                FUN_00c01530(&dest[i], &source[i], sizeof(Element46e5c0));
        } else if (dest > source) {
            for (int i = count - 1; i >= 0; i--)
                FUN_00c01530(&dest[i], &source[i], sizeof(Element46e5c0));
        }
    }
}
}   // namespace f3m_0046e5c0

// @f3 0x00475280 (community match, verified in this file)
namespace f3m_00475280 {
struct Point475280 {
    float x, y, z;
    Point475280(float px, float py, float pz) : x(px), y(py), z(pz) {}
    float X() const { return x; }
    Point475280 FUN_00475280(const Point475280& p) const;
};

// pdb: NiPoint3::Cross | BGSGrassManager.obj | tesv_win, call_gap, low
Point475280 Point475280::FUN_00475280(const Point475280& p) const
{
    Point475280 r(y * p.z - z * p.y, z * p.X() - x * p.z, x * p.y - y * p.X());
    return r;
}
}   // namespace f3m_00475280

// @f3 0x0047f6a0 (community match, verified in this file)
struct Item47f6a0 { short FUN_0047dca0(); };
struct Obj47f6a0 { virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65();virtual void v66();virtual void v67();virtual void v68();virtual void v69();virtual void v70();virtual void v71();virtual void v72();virtual void v73();virtual void v74();virtual void v75(); virtual int GetId(); };
struct Ent47f6a0 { int form; char kind; char idb[4]; };
struct Data47f6a0 { char pad[0x88]; Ent47f6a0* ent; bool TESSaveLoadGame_UseSaveGameBlocks(); };
struct Node47f6a0 { Item47f6a0* item; Node47f6a0* next; bool Empty() const { return next == 0 && item == 0; } Item47f6a0* Get() const { return item; } };
struct List47f6a0 { Node47f6a0* head; unsigned short FUN_0047f6a0(); };
extern Data47f6a0* DAT_01079ca4;
extern bool DAT_01079d20;
Obj47f6a0* __cdecl TESForm_GetFormByNumericID(int form);
void __cdecl FUN_00c24b70(const char* fmt, ...);
// pdb: InventoryChanges::GetSaveSize | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
unsigned short List47f6a0::FUN_0047f6a0()
{
    unsigned short size = 0;
    if (DAT_01079ca4->TESSaveLoadGame_UseSaveGameBlocks()) size = 6;
    size += 2;
    for (Node47f6a0* n = head; n; n = n->next) {
        if (n->Empty()) break;
        Item47f6a0* it = n->Get();
        if (it) size += it->FUN_0047dca0();
    }
    if (DAT_01079d20) {
        Ent47f6a0* e = DAT_01079ca4->ent;
        if (e) {
            Obj47f6a0* o = TESForm_GetFormByNumericID(e->form);
            FUN_00c24b70("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", size, e->form, o->GetId(), *(int*)e->idb, 0x236a, "c:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp");
        }
    }
    return size;
}

// @f3 0x00464e60 (community match, verified in this file)
namespace f3m_00464e60 {
struct GridOrigin_464e60
{
    float x;
    float y;
    float z;
};
struct GridCorners_464e60
{
    float x0;
    float y0;
    float x1;
    float y0again;
    float x0again;
    float y1;
    float x1again;
    float y1again;
};
struct GridState_464e60
{
    GridCorners_464e60 corners;
    GridOrigin_464e60 origin;
};
struct GridCoords_464e60
{
    void FUN_004c8ff0();
};
struct GridOwner_464e60
{
    GridCoords_464e60* TESObjectCELL_GetLand(GridOrigin_464e60* out, int mode);
    int TESObjectCELL_GetDataX();
    int TESObjectCELL_GetDataY();
};

// pdb: BGSAutoWater::WhichCellEdge | BGSAutoWater.obj | fnv360_0721_beta, objrun, medium
// pdb params: apCell, arVert
int __cdecl FUN_00464e60(GridOwner_464e60* object, float x, float y)
{
    int result = 0;
    GridState_464e60 state;
    object->TESObjectCELL_GetLand(&state.origin, 0)->FUN_004c8ff0();
    x += state.origin.x;
    y += state.origin.y;

    state.corners.x0 = (float)(object->TESObjectCELL_GetDataX() << 12);
    state.corners.y0 = (float)(object->TESObjectCELL_GetDataY() << 12);
    state.corners.x1 = (float)((object->TESObjectCELL_GetDataX() + 1) << 12);
    state.corners.y0again = (float)(object->TESObjectCELL_GetDataY() << 12);
    state.corners.x0again = (float)(object->TESObjectCELL_GetDataX() << 12);
    state.corners.y1 = (float)((object->TESObjectCELL_GetDataY() + 1) << 12);
    state.corners.x1again = (float)((object->TESObjectCELL_GetDataX() + 1) << 12);
    state.corners.y1again = (float)((object->TESObjectCELL_GetDataY() + 1) << 12);

    if (x == state.corners.x0 && y == state.corners.y0)
        result = 9;
    else if (x == state.corners.x1 && y == state.corners.y0again)
        result = 10;
    else if (x == state.corners.x0again && y == state.corners.y1)
        result = 5;
    else if (x == state.corners.x1again && y == state.corners.y1again)
        result = 6;
    else if (x == state.corners.x0)
        result = 1;
    else if (x == state.corners.x1)
        result = 2;
    else if (y == state.corners.y0)
        result = 8;
    else if (y == state.corners.y1again)
        result = 4;
    return result;
}
}   // namespace f3m_00464e60

// @f3 0x00466a70 (community match, verified in this file)
namespace f3m_00466a70 {
namespace f3m_00466a70 {
class Element {
public:
    virtual void Slot00();
    unsigned value04;
    unsigned value08;
    unsigned value0c;
    Element& operator=(const Element& other)
    {
        value04 = other.value04;
        value08 = other.value08;
        value0c = other.value0c;
        return *this;
    }
};
class ElementArray {
public:
    virtual void Slot00();
    virtual Element* Allocate(unsigned count);
    virtual void Release(Element* data);
    Element* data;
    unsigned size;
    unsigned capacity;
    unsigned GrowthCapacity() const
    {
        return capacity > 0x400 ? capacity + 0x400 : capacity * 2;
    }
    unsigned FUN_005b90b0();
    void FUN_00465250(Element* first, unsigned count);
    void FUN_005b8560(Element* destination, const Element* source, unsigned count);
    void FUN_00466a70(unsigned index, const Element& value);
};
// pdb: BSSimpleArray<BSSimpleArray<NiPoint3,1024>,1024>::Insert | BGSAutoWater.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiIndex, aValue
void ElementArray::FUN_00466a70(unsigned index, const Element& value)
{
    unsigned destination;
    if (index == size) {
        destination = FUN_005b90b0();
        FUN_00465250(data + destination, 1);
    } else {
        if (size == capacity) {
            unsigned newCapacity = GrowthCapacity();
            Element* newData = Allocate(newCapacity);
            FUN_005b8560(newData, data, index);
            destination = index;
            Element* inserted = newData + destination;
            FUN_00465250(inserted, 1);
            FUN_005b8560(inserted + 1, data + destination, size - index);
            Release(data);
            data = newData;
            capacity = newCapacity;
        } else {
            destination = index;
            FUN_005b8560(data + destination + 1, data + destination, size - index);
            FUN_00465250(data + destination, 1);
        }
        ++size;
    }
    data[destination] = value;
}
}

}   // namespace f3m_00466a70

// @f3 0x00472f70 (community match, verified in this file)
#include <string.h>
extern int DAT_00f4c370[3];
extern int DAT_00f4c3d0[];
namespace f3m_00472f70 {
namespace f3_0585 {
struct Node;
struct Model;
struct Form {};
enum SEX { SEX_MALE, SEX_FEMALE };
enum BIPED_OBJECT { SLOT_ZERO };
struct Race : Form { Model* FUN_0055f7b0(SEX, BIPED_OBJECT); };
struct Actor {
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13c();
    virtual void slot_140();
    virtual void slot_144();
    virtual void slot_148();
    virtual void slot_14c();
    virtual void slot_150();
    virtual void slot_154();
    virtual void slot_158();
    virtual void slot_15c();
    virtual void slot_160();
    virtual void slot_164();
    virtual void slot_168();
    virtual void slot_16c();
    virtual void slot_170();
    virtual void slot_174();
    virtual void slot_178();
    virtual void slot_17c();
    virtual void slot_180();
    virtual void slot_184();
    virtual void slot_188();
    virtual void slot_18c();
    virtual void slot_190();
    virtual void slot_194();
    virtual void slot_198();
    virtual void slot_19c();
    virtual void slot_1a0();
    virtual void slot_1a4();
    virtual void slot_1a8();
    virtual void slot_1ac();
    virtual void slot_1b0();
    virtual void slot_1b4();
    virtual void slot_1b8();
    virtual void slot_1bc();
    virtual void slot_1c0();
    virtual void slot_1c4();
    virtual void slot_1c8();
    virtual void slot_1cc();
    virtual Node* GetNiNode_v();
};
struct BipedBone { unsigned char cFlags; Node* pParent; };
struct BipedObject { Form* pParent; Model* m_pModel; void* m_pSceneObject; bool bHasAnimation; };
struct BipedAnim {
    Node* root;
    BipedBone bone[5];
    BipedObject object[20];
    BipedObject m_kPreviousObjects[20];
    float m_fFadeAlpha;
    Actor* m_pActor;
    void FUN_00472ce0(Form*, Model*, BIPED_OBJECT);
    void FUN_00472f70(Race*, SEX);
};
// @fnv 0x004ab250
// pdb: BipedAnim::InitNaked | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRace, aeSex
void BipedAnim::FUN_00472f70(Race* race, SEX sex)
{
    if (!race)
        return;
    bool empty = true;
    int i;
    for (i = 0; i < 20; ++i)
        if (m_kPreviousObjects[i].pParent)
            empty = false;
    if (m_pActor && m_pActor->GetNiNode_v())
    {
        for (i = 0; i < 20; ++i)
        {
            if (empty)
                m_kPreviousObjects[i] = object[i];
            memset(&object[i], 0, 16);
        }
    }
    else
    {
        if (empty)
            memset(m_kPreviousObjects, 0, 320);
        memset(object, 0, 320);
    }
    for (i = 0; i < 3; ++i)
        if (DAT_00f4c3d0[DAT_00f4c370[i]] == -1 || (bone[DAT_00f4c3d0[DAT_00f4c370[i]]].cFlags & 1))
            FUN_00472ce0(race, race->FUN_0055f7b0(sex, (BIPED_OBJECT)DAT_00f4c370[i]),
                           (BIPED_OBJECT)DAT_00f4c370[i]);
}

}
}   // namespace f3m_00472f70

// @f3 0x00476920 (community match, verified in this file)
#include <new>

extern char* FUN_008242a0(const char*);

class FixedStringInitializer1546
{
public:
    const char* value00;
    FixedStringInitializer1546(const char* value) : value00(FUN_008242a0(value)) {}
    static void* operator new(size_t bytes)
    { return ::DAT_01090a78.FUN_0086b930(bytes); }
};

extern FixedStringInitializer1546* DAT_0106e7c4;
extern FixedStringInitializer1546* DAT_0106e7c8;
extern FixedStringInitializer1546* DAT_0106e7cc;
extern FixedStringInitializer1546* DAT_0106e7d0;
extern FixedStringInitializer1546* DAT_0106e7d4;
extern FixedStringInitializer1546* DAT_0106e7d8;
extern FixedStringInitializer1546* DAT_0106e7dc;
extern FixedStringInitializer1546* DAT_0106e7e0;
extern FixedStringInitializer1546* DAT_0106e7e4;
extern FixedStringInitializer1546* DAT_0106e7e8;
extern FixedStringInitializer1546* DAT_0106e7ec;
extern FixedStringInitializer1546* DAT_0106e7f0;
extern FixedStringInitializer1546* DAT_0106e7f4;
extern FixedStringInitializer1546* DAT_0106e7f8;
extern FixedStringInitializer1546* DAT_0106e7fc;
extern FixedStringInitializer1546* DAT_0106e800;
extern FixedStringInitializer1546* DAT_0106e808;
extern FixedStringInitializer1546* DAT_0106e80c;
extern FixedStringInitializer1546* DAT_0106e810;
extern FixedStringInitializer1546* DAT_0106e814;
extern FixedStringInitializer1546* DAT_0106e818;
extern FixedStringInitializer1546* DAT_0106e81c;
extern FixedStringInitializer1546* DAT_0106e820;
extern FixedStringInitializer1546* DAT_0106e824;
extern FixedStringInitializer1546* DAT_0106e828;
extern FixedStringInitializer1546* DAT_0106e82c;
extern FixedStringInitializer1546* DAT_0106e830;
extern FixedStringInitializer1546* DAT_0106e834;
extern FixedStringInitializer1546* DAT_0106e838;
extern FixedStringInitializer1546* DAT_0106e83c;
extern FixedStringInitializer1546* DAT_0106e840;
extern FixedStringInitializer1546* DAT_0106e844;
extern FixedStringInitializer1546* DAT_0106e848;
extern FixedStringInitializer1546* DAT_0106e84c;
extern FixedStringInitializer1546* DAT_0106e850;
extern FixedStringInitializer1546* DAT_0106e854;
extern FixedStringInitializer1546* DAT_0106e858;
extern FixedStringInitializer1546* DAT_0106e85c;
extern FixedStringInitializer1546* DAT_0106e860;
extern FixedStringInitializer1546* DAT_0106e864;
extern FixedStringInitializer1546* DAT_0106e868;
extern FixedStringInitializer1546* DAT_0106e86c;
extern FixedStringInitializer1546* DAT_0106e870;
extern FixedStringInitializer1546* DAT_0106e874;
extern FixedStringInitializer1546* DAT_0106e878;
extern FixedStringInitializer1546* DAT_0106e87c;
extern FixedStringInitializer1546* DAT_0106e880;
extern FixedStringInitializer1546* DAT_0106e884;
extern FixedStringInitializer1546* DAT_0106e888;
extern FixedStringInitializer1546* DAT_0106e88c;
extern FixedStringInitializer1546* DAT_0106e890;
extern FixedStringInitializer1546* DAT_0106e894;
extern FixedStringInitializer1546* DAT_0106e898;

// pdb: FixedStrings::InitSDM | GlobalFunc.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: FixedStrings::FixedStrings)
void FUN_00476920()
{
    DAT_0106e7c4 = new FixedStringInitializer1546("Bip01");
    DAT_0106e7c8 = new FixedStringInitializer1546("Bip");
    DAT_0106e7cc = new FixedStringInitializer1546("Bip01 Head");
    DAT_0106e7d0 = new FixedStringInitializer1546("Bip01 Neck");
    DAT_0106e7d4 = new FixedStringInitializer1546("Bip01 Spine");
    DAT_0106e7d8 = new FixedStringInitializer1546("Bip01 Spine1");
    DAT_0106e7dc = new FixedStringInitializer1546("magicNode");
    DAT_0106e7e0 = new FixedStringInitializer1546("SpecialIdle_Cast");
    DAT_0106e7e4 = new FixedStringInitializer1546("SpecialIdle_AreaEffect");
    DAT_0106e7e8 = new FixedStringInitializer1546("AttachSound");
    DAT_0106e7ec = new FixedStringInitializer1546("Sound Marker");
    DAT_0106e7f0 = new FixedStringInitializer1546("Skinned Decal Node");
    DAT_0106e7f4 = new FixedStringInitializer1546("Decal Node");
    DAT_0106e7f8 = new FixedStringInitializer1546("ModelSwapNode");
    DAT_0106e7fc = new FixedStringInitializer1546("Open");
    DAT_0106e800 = new FixedStringInitializer1546("Close");
    DAT_0106e804 = new FixedStringInitializer1546("DVPG");
    DAT_0106e808 = new FixedStringInitializer1546("Prn");
    DAT_0106e80c = new FixedStringInitializer1546("Weapon");
    DAT_0106e810 = new FixedStringInitializer1546("EditorMarker");
    DAT_0106e814 = new FixedStringInitializer1546("EditorMarker:0");
    DAT_0106e818 = new FixedStringInitializer1546("EditorMarker:1");
    DAT_0106e81c = new FixedStringInitializer1546("EditorMarker:2");
    DAT_0106e820 = new FixedStringInitializer1546("ArrowQuiver");
    DAT_0106e824 = new FixedStringInitializer1546("MarkerSource");
    DAT_0106e828 = new FixedStringInitializer1546("MarkerTarget");
    DAT_0106e82c = new FixedStringInitializer1546("AttachLight");
    DAT_0106e830 = new FixedStringInitializer1546("skin");
    DAT_0106e834 = new FixedStringInitializer1546("FaceGenEars");
    DAT_0106e838 = new FixedStringInitializer1546("Unequip");
    DAT_0106e83c = new FixedStringInitializer1546("LaserSight");
    DAT_0106e840 = new FixedStringInitializer1546("AimSight");
    DAT_0106e844 = new FixedStringInitializer1546("Grass");
    DAT_0106e848 = new FixedStringInitializer1546("Decal");
    DAT_0106e84c = new FixedStringInitializer1546("Permanent Decal");
    DAT_0106e850 = new FixedStringInitializer1546("grabLeft");
    DAT_0106e854 = new FixedStringInitializer1546("grabRight");
    DAT_0106e858 = new FixedStringInitializer1546("Arrow:0");
    DAT_0106e85c = new FixedStringInitializer1546("ArrowBone");
    DAT_0106e860 = new FixedStringInitializer1546("BSFaceGenNiNodeBiped");
    DAT_0106e864 = new FixedStringInitializer1546("BSFaceGenNiNodeSkinned");
    DAT_0106e868 = new FixedStringInitializer1546("HeadAnims:0");
    DAT_0106e86c = new FixedStringInitializer1546("EntryPoint");
    DAT_0106e870 = new FixedStringInitializer1546("Bip01 L UpperArm");
    DAT_0106e874 = new FixedStringInitializer1546("Bip01 L Forearm");
    DAT_0106e878 = new FixedStringInitializer1546("Bip01 R UpperArm");
    DAT_0106e87c = new FixedStringInitializer1546("Bip01 Yaw");
    DAT_0106e880 = new FixedStringInitializer1546("Bip01 Pitch");
    DAT_0106e884 = new FixedStringInitializer1546("Bip01 Looking");
    DAT_0106e888 = new FixedStringInitializer1546("Talking");
    DAT_0106e88c = new FixedStringInitializer1546("Camera1st");
    DAT_0106e890 = new FixedStringInitializer1546("Camera3rd");
    DAT_0106e894 = new FixedStringInitializer1546("HeadMeshForExport_FaceGenAndMorphs:0");
    DAT_0106e898 = new FixedStringInitializer1546("PinnedLimb");
}

// @f3 0x00475550 (community match, verified in this file)
namespace f3m_00475550 {
extern int __cdecl FUN_00c00b52(int value);

// pdb: BSstristr | GlobalFunc.obj | fnv360_0822_debug, caller, medium
// pdb params: apString1, apString2
char* __cdecl FUN_00475550(char* text, char* pattern)
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    for (int i = 0; i < textLength - patternLength + 1; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (FUN_00c00b52(text[i + j]) != FUN_00c00b52(pattern[j]))
                break;
        }
        if (j == patternLength)
            return text + i;
    }
    return 0;
}
}   // namespace f3m_00475550

// @f3 0x00478620 (community match, verified in this file)
namespace f3m_00478620 {
namespace f3m_00478620 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
struct Color478620
{
    float r;
    float g;
    float b;
};
struct ColorA478620
{
    float r;
    float g;
    float b;
    float a;
    ColorA478620(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA) {}
};
class Material478620
{
public:
    virtual void Slot00();
    virtual void DeleteThis();
    long m_uiRefCount;
    int unk08;
    ColorA478620 m_kColor0C;
    ColorA478620 m_kColor1C;
    ColorA478620 m_kColor2C;
    ColorA478620 m_kColor3C;
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

    static void* operator new(unsigned int bytes) { return ::FUN_0089eb90(bytes); }
    static void operator delete(void*) {}
    Material478620();
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class Property478620 : public Object4788d0
{
public:
    void FUN_00aea960(Material478620* material);
};
class Node478620;
class AVObject478620
{
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual Node478620* AsNode();
    Object4788d0* FUN_00826590(unsigned int kind);
};
class Node478620 : public AVObject478620
{
public:
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
    int unk9C;
    AVObject478620** children;
    unsigned short capacity;
    unsigned short count;
};
// pdb: TintScenegraph | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRoot, aColor, apTextureEffectData
void FUN_00478620(AVObject478620* object, const Color478620* color, Material478620* material)
{
    NiPointer<Material478620> spMaterial = material;
    if (!spMaterial)
    {
        spMaterial = new Material478620;
        material = spMaterial;
        material->m_kColor2C = ColorA478620(color->r, color->g, color->b, 0.5f);
        material->m_kColor3C = ColorA478620(color->r, color->g, color->b, 0.5f);
        material->m_kColor0C = ColorA478620(color->r, color->g, color->b, 0.5f);
        material->m_kColor1C = ColorA478620(color->r, color->g, color->b, 0.5f);
        material->unk5C = 9;
        material->unk60 = 10;
        material->unk64 = 1;
        material->unk68 = 4;
    }
    Object4788d0* prop = object->FUN_00826590(3);
    if (prop)
    {
        Property478620* typed = IsKindOf4788d0(&DAT_0116fd98, prop) ? (Property478620*)prop : 0;
        if (typed)
            typed->FUN_00aea960(spMaterial);
    }
    Node478620* node = object->AsNode();
    if (node)
    {
        for (unsigned int index = 0; index < node->count; ++index)
        {
            AVObject478620* child = node->children[index];
            if (child)
                FUN_00478620(child, color, material);
        }
    }
}
}
}   // namespace f3m_00478620

// @f3 0x0046d230 (community match, verified in this file)
#include <math.h>
namespace f3m_0046d230 {

class NiPoint3 {
public:
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

extern NiPoint3 DAT_0108ec68;

struct NiBound {
    NiPoint3 center;
    float radius;
    void Set(NiPoint3 c, float r) { radius = r; center = c; }
};

struct GeomData {
    int unk00; int unk04;
    unsigned short vertexCount;
    unsigned short unk0A;
    int unk0C;
    NiBound bound;
    NiPoint3* vertices;
    void FUN_008313b0(unsigned int flags);
};

struct Geom {
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
    virtual void vb4();
    virtual void vb8();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4;
    GeomData* data;
    virtual void vbc();
    void FUN_008264c0(void* p);
    void FUN_008268a0();
};

struct Flags5 {
    float f;
    bool b0, b1, b2, b3, b4;
};

struct BoxObj {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    NiPoint3 extents;
    Geom* geom24;
    Geom* geom28;
    Geom* geom2c;
    void FUN_0046d230(NiPoint3* ext);
};

// pdb: BGSPrimitiveBox::SetRadii | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: aRadii
void BoxObj::FUN_0046d230(NiPoint3* ext)
{
    ext->x = fabs(ext->x);
    ext->y = fabs(ext->y);
    ext->z = fabs(ext->z);
    extents = *ext;
    if (geom24) {
        GeomData* data = geom24->data;
        NiPoint3* v = data->vertices;
        v[0] = NiPoint3(-extents.x, extents.y, extents.z);
        v[1] = NiPoint3(extents.x, extents.y, extents.z);
        v[2] = NiPoint3(extents.x, -extents.y, extents.z);
        v[3] = NiPoint3(-extents.x, -extents.y, extents.z);
        v[4] = NiPoint3(-extents.x, extents.y, -extents.z);
        v[5] = NiPoint3(extents.x, extents.y, -extents.z);
        v[6] = NiPoint3(extents.x, -extents.y, -extents.z);
        v[7] = NiPoint3(-extents.x, -extents.y, -extents.z);
        data->FUN_008313b0(1);
    }
    if (geom28) {
        GeomData* data = geom28->data;
        NiPoint3* v = data->vertices;
        NiPoint3 e = *ext;
        if (fabs(e.x) < 0.01f) e.x = 0.01f;
        if (fabs(e.y) < 0.01f) e.y = 0.01f;
        if (fabs(e.z) < 0.01f) e.z = 0.01f;
        for (int i = 0; i < data->vertexCount; i++) {
            v[i].x = (v[i].x < 0.0f) ? -1.0f : 1.0f;
            v[i].y = (v[i].y < 0.0f) ? -1.0f : 1.0f;
            v[i].z = (v[i].z < 0.0f) ? -1.0f : 1.0f;
            v[i].x = v[i].x * e.x;
            v[i].y = v[i].y * e.y;
            v[i].z = v[i].z * e.z;
            data->FUN_008313b0(1);
        }
    }
    Flags5 fl;
    fl.f = 0.0f;
    fl.b0 = false; fl.b1 = false; fl.b2 = false; fl.b3 = false; fl.b4 = false;
    if (geom2c) {
        float m = ext->x;
        if (ext->y > ext->x && ext->y > ext->z) m = ext->y;
        if (ext->z > ext->y && ext->z > ext->x) m = ext->z;
        GeomData* d = geom24->data;
        d->bound.Set(DAT_0108ec68, m);
        geom2c->FUN_008264c0(&fl);
        geom24->FUN_008268a0();
        geom2c->vbc();
    }
}

}

// @f3 0x00470d10 (community match, verified in this file)
class TESNPC : public TESBoundObject {
public:
    virtual ~TESNPC();
};

namespace q470d10 {

struct QHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TESBoundObject* unk1C;
};

class QMgr {
public:
    void FUN_0055f490(TESNPC* npc, char* name);
    bool FUN_0055f580(TESNPC* npc, char* name, char* path);
};

class QLoader {
public:
    void FUN_0042c500(char* path, int a2, int a3);
};

extern QLoader* DAT_0106ca70;

static inline QMgr* MgrOf(TESNPC* npc) { return *(QMgr**)((char*)npc + 0x110); }

class QOwner {
public:
    void FUN_004707c0(TESNPC* npc, int kind, int a2, int a3);
    void FUN_00470d10(int flags, int a2, int a3);
};

// pdb: BipedAnim::QueueSkinTextures | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiModelSkinFlags, aePriority, apParent
void QOwner::FUN_00470d10(int flags, int a2, int a3)
{
    char name[0x104];
    char path[0x104];
    int c = *(volatile int*)&a3;
    if (flags) {
        QHolder* holder = *(QHolder**)((char*)this + 0x2b0);
        TESNPC* npc = dynamic_cast<TESNPC*>(holder->unk1C);
        if (npc) {
            if (flags & 2)
                FUN_004707c0(npc, 2, a2, c);
            if (flags & 4)
                FUN_004707c0(npc, 4, a2, c);
            if (flags & 8)
                FUN_004707c0(npc, 3, a2, c);
            MgrOf(npc)->FUN_0055f490(npc, name);
            if (MgrOf(npc)->FUN_0055f580(npc, name, path))
                DAT_0106ca70->FUN_0042c500(path, a2, c);
        }
    }
}

}

// @f3 0x00472310 (community match, verified in this file)
namespace f3m_00472310 {
struct Scene;
struct SceneOwner {
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4C();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5C();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6C();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7C();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8C();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9C();
    virtual void VA0();
    virtual void VA4();
    virtual void VA8();
    virtual void VAC();
    virtual void VB0();
    virtual void VB4();
    virtual void VB8();
    virtual void VBC();
    virtual void VC0();
    virtual void VC4();
    virtual void VC8();
    virtual void VCC();
    virtual void VD0();
    virtual void VD4();
    virtual void VD8();
    virtual void VDC();
    virtual void VE0();
    virtual void VE4();
    virtual void OnChanged_0E8(Scene* s);
};
struct Scene {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    SceneOwner* owner18;
};
struct Model {
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual const char* GetPath();
};
struct Entry {
    void* key;
    Model* model;
    Scene* scene;
    int unk0C;
};
struct Mgr { void FUN_006f2440(Scene* s); };
struct Loader { void FUN_00429640(const char* path, bool a, bool b); };
struct Manager { void FUN_00ae1a30(Scene* s); };
struct GameState { char pad[0x5a9]; char flag5A9; };
struct Lookup { void* FUN_0076cd20(int a); };
struct KeyForm { char pad[0x100]; unsigned char flags100; };
struct Holder { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; unsigned int unk30; };
struct Process {
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4C();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5C();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6C();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7C();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8C();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9C();
    virtual void VA0();
    virtual void VA4();
    virtual void VA8();
    virtual void VAC();
    virtual void VB0();
    virtual void VB4();
    virtual void VB8();
    virtual void VBC();
    virtual void VC0();
    virtual void VC4();
    virtual void VC8();
    virtual void VCC();
    virtual void VD0();
    virtual void VD4();
    virtual void VD8();
    virtual void VDC();
    virtual void VE0();
    virtual void VE4();
    virtual void VE8();
    virtual void VEC();
    virtual void VF0();
    virtual void VF4();
    virtual void VF8();
    virtual void VFC();
    virtual bool V100();
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
    void FUN_00701ab0(int a);
};
extern Mgr* DAT_0107a79c;
extern Loader* DAT_0106ca70;
extern Manager* DAT_0116efb8;
extern GameState* DAT_0106cdcc;
extern Lookup* DAT_0107a104;
bool __cdecl FUN_00724400();
void __cdecl FUN_00470770(Scene* s);
void __cdecl FUN_00478bb0(Scene* s);
void __cdecl FUN_008d7720(Scene* s, int a, int b);
Scene* __cdecl FUN_00aab350(void* root, const char* name, int a);

struct Actor472310 {
    void* unk00;
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
    KeyForm* unk7C;
    Model* unk80;
    Scene* unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    Holder* unkA4;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    Entry entries[20];
    int unk2AC;
    Process* unk2B0;
    void FUN_00471020(Scene* s);
    void FUN_00472310();
};

// pdb: BipedAnim::RemoveBipedWeapon | BipedAnim.obj | fnv360_0822_retail, call_gap, low
void Actor472310::FUN_00472310()
{
    if (unk7C && (unk7C->flags100 & 0x10) && unkA4)
        unkA4->unk30 &= ~1;
    void* key = entries[5].key;
    if (key) {
        for (int i = 0; i < 20; ++i) {
            Entry* e = &entries[i];
            if (e->key == key) {
                if (e->scene) {
                    FUN_00471020(e->scene);
                    if (!FUN_00724400())
                        FUN_00470770(e->scene);
                    else
                        DAT_0107a79c->FUN_006f2440(e->scene);
                    const char* path = e->model->GetPath();
                    DAT_0106ca70->FUN_00429640(path, true, true);
                    e->scene = 0;
                }
                e->key = 0;
                e->model = 0;
            }
        }
    }
    if (unk84) {
        FUN_00471020(unk84);
        if (!FUN_00724400()) {
            Scene* s = unk84;
            if (s) {
                FUN_00478bb0(s);
                DAT_0116efb8->FUN_00ae1a30(s);
                if (s->owner18) {
                    FUN_008d7720(s, 1, 0);
                    s->owner18->OnChanged_0E8(s);
                }
            }
        } else
            DAT_0107a79c->FUN_006f2440(unk84);
        const char* path = unk80->GetPath();
        DAT_0106ca70->FUN_00429640(path, true, true);
        unk84 = 0;
    }
    Entry* e = (Entry*)&unk7C;
    e->key = 0;
    e->model = 0;
    if (unk2B0->V100()) {
        Process* p = unk2B0;
        if (p->unk60 && !DAT_0106cdcc->flag5A9 && this != DAT_0107a104->FUN_0076cd20(1))
            p->FUN_00701ab0(0);
        void* root = unk00;
        Scene* bp = FUN_00aab350(root, "Backpack", 1);
        if (bp)
            bp->owner18->OnChanged_0E8(bp);
    }
}
}

// @f3 0x0047b650 (community match, verified in this file)
extern bool DAT_0106ea1d;
namespace f3m_0047b650 {
class GridCell { public: void FUN_004dc860(); };
class CellGrid
{
public:
    int unk00; int unk04; int unk08;
    unsigned int width;
    GridCell** cells;
    GridCell** At(unsigned int x, unsigned int y)
    {
        if (x < width && y < width)
            return &cells[x * width + y];
        return 0;
    }
    void FUN_0047b650();
};
// pdb: GridCellArray::UpdateManagedNodeTransforms | GridCell.obj | fnv360_0822_retail, call_seq, medium
void CellGrid::FUN_0047b650()
{
    unsigned int size = width;
    DAT_0106ea1d = !DAT_0106ea1d;
    for (unsigned int x = 0; x < size; ++x)
    {
        for (unsigned int y = 0; y < size; ++y)
        {
            bool update = true;
            unsigned int last = size - 1;
            if (!x || !y || x == last || y == last)
            {
                if ((x ^ y) & 1)
                    update = false;
                if (DAT_0106ea1d)
                    update = !update;
            }
            if (update)
            {
                GridCell* cell = *At(x, y);
                if (cell)
                    cell->FUN_004dc860();
            }
        }
    }
}

}   // namespace f3m_0047b650

// @f3 0x0047e810 (community match, verified in this file)
namespace f3m_0047e810 {
namespace f3m_0047e810 {
struct Form {
    int unk00;
    unsigned char type;
};
struct ContainerEntry {
    int count;
    Form* form;
};
struct ContainerNode {
    ContainerEntry* item;
    ContainerNode* next;
};
struct Container {
    int unk00;
    ContainerNode list;
    bool FUN_004528c0(Form* form);
};
struct BaseForm {
    Container* FUN_004e66c0();
};
struct InvEntry {
    void* extraLists;
    int countDelta;
    Form* form;
};
struct InvNode {
    InvEntry* item;
    InvNode* next;
};
bool __cdecl TESContainer_IsGold(Form* form);
struct Owner {
    InvNode* entries;
    BaseForm* baseForm;
    int FUN_0047e810();
};

// pdb: InventoryChanges::GetGoldAmount | InventoryChanges.obj | fnv360_0822_retail, call_gap, medium
int Owner::FUN_0047e810()
{
    int total = 0;
    Container* container = baseForm ? baseForm->FUN_004e66c0() : 0;
    if (container) {
        for (ContainerNode* node = &container->list; node; node = node->next) {
            if (!node->next && !node->item)
                break;
            Form* form = node->item->form;
            if (form && TESContainer_IsGold(form)) {
                InvNode* n = entries;
                bool searching = true;
                while (n && searching) {
                    if (n->item && n->item->form == form)
                        searching = false;
                    else
                        n = n->next;
                }
                if (n && n->item) {
                    total += n->item->countDelta + node->item->count;
                } else {
                    total += node->item->count;
                    if (total < 0)
                        total = -total;
                }
            }
        }
    }
    for (InvNode* n = entries; n; n = n->next) {
        if (!n->next && !n->item)
            break;
        Form* form = n->item->form;
        if (form && TESContainer_IsGold(form)) {
            if (!container || (!container->FUN_004528c0(form) && n->item->countDelta > 0))
                total += n->item->countDelta;
        }
    }
    return total;
}
}
}   // namespace f3m_0047e810

// @f3 0x0046cae0 (community match, verified in this file)
#include <math.h>
extern char DAT_0108ec68;
namespace f3m_0046cae0 {

struct DebugPoint1564
{
    float x;
    float y;
    float z;
    DebugPoint1564() {}
    DebugPoint1564(float newX, float newY, float newZ) : x(newX), y(newY), z(newZ) {}
};

struct DebugBound1564
{
    DebugPoint1564 center;
    float radius;
    void SetCenterAndRadius(DebugPoint1564 value, float newRadius) { radius=newRadius; center=value; }
};

struct DebugUpdate1564
{
    float time00;
    bool update04;
    bool update05;
    bool update06;
    bool update07;
    bool update08;
    DebugUpdate1564() : time00(0.0f), update04(false), update05(false), update06(false), update07(false), update08(false) {}
};

struct DebugGeometryData1564
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    DebugBound1564 bound10;
    DebugPoint1564* vertices20;
    void FUN_008313b0(unsigned int flags);
};

class DebugNode1564
{
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
    virtual void UpdateDownward(DebugUpdate1564* update);
    virtual void UpdateUpward();
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
    DebugGeometryData1564* dataB8;
    void FUN_008264c0(DebugUpdate1564* update);
    void FUN_008268a0();
};


class DebugBox1564
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    DebugPoint1564 extents18;
    DebugNode1564* mesh24;
    DebugNode1564* mesh28;
    DebugNode1564* root2c;
    void FUN_0046cae0(DebugPoint1564* dimensions);
};

// pdb: BGSPrimitivePlane::SetRadii | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: aRadii
void DebugBox1564::FUN_0046cae0(DebugPoint1564* dimensions)
{
    dimensions->x = (float)fabs(dimensions->x);
    dimensions->y = 0.0f;
    dimensions->z = (float)fabs(dimensions->z);
    extents18 = *dimensions;
    if (mesh24)
    {
        DebugGeometryData1564* data = mesh24->dataB8;
        DebugPoint1564* vertices = data->vertices20;
        vertices[0] = DebugPoint1564(-extents18.x, extents18.y, extents18.z);
        vertices[1] = DebugPoint1564(extents18.x, extents18.y, extents18.z);
        vertices[2] = DebugPoint1564(extents18.x, -extents18.y, extents18.z);
        vertices[3] = DebugPoint1564(-extents18.x, -extents18.y, extents18.z);
        vertices[4] = DebugPoint1564(-extents18.x, extents18.y, -extents18.z);
        vertices[5] = DebugPoint1564(extents18.x, extents18.y, -extents18.z);
        vertices[6] = DebugPoint1564(extents18.x, -extents18.y, -extents18.z);
        vertices[7] = DebugPoint1564(-extents18.x, -extents18.y, -extents18.z);
        data->FUN_008313b0(1);
    }
    if (mesh28)
    {
        DebugGeometryData1564* data = mesh28->dataB8;
        DebugPoint1564* vertices = data->vertices20;
        DebugPoint1564 corner0(-extents18.x, extents18.y, extents18.z);
        vertices[0] = corner0;
        DebugPoint1564 corner1(extents18.x, extents18.y, extents18.z);
        vertices[1] = corner1;
        DebugPoint1564 corner2(extents18.x, -extents18.y, extents18.z);
        vertices[2] = corner2;
        DebugPoint1564 corner3(-extents18.x, -extents18.y, extents18.z);
        vertices[3] = corner3;
        vertices[4] = corner0;
        DebugPoint1564 corner4(-extents18.x, extents18.y, -extents18.z);
        vertices[5] = corner4;
        DebugPoint1564 corner5(-extents18.x, -extents18.y, -extents18.z);
        vertices[6] = corner5;
        DebugPoint1564 corner6(extents18.x, -extents18.y, -extents18.z);
        vertices[7] = corner6;
        DebugPoint1564 corner7(extents18.x, extents18.y, -extents18.z);
        vertices[8] = corner7;
        vertices[9] = corner4;
        vertices[10] = corner3;
        vertices[11] = corner5;
        vertices[12] = corner1;
        vertices[13] = corner7;
        vertices[14] = corner2;
        vertices[15] = corner6;
        data->FUN_008313b0(1);
    }
    DebugUpdate1564 update;
    if (root2c)
    {
        float radius = dimensions->x;
        if (dimensions->y > dimensions->x && dimensions->y > dimensions->z)
            radius = dimensions->y;
        if (dimensions->z > dimensions->y && dimensions->z > dimensions->x)
            radius = dimensions->z;
        DebugBound1564& bound=mesh24->dataB8->bound10;
        bound.SetCenterAndRadius(*reinterpret_cast<const DebugPoint1564*>(&::DAT_0108ec68), radius);
        root2c->FUN_008264c0(&update);
        root2c->UpdateDownward(&update);
        mesh24->FUN_008268a0();
        root2c->UpdateUpward();
    }
}
}   // namespace f3m_0046cae0

// @f3 0x00470c20 (community match, verified in this file)
extern const char DAT_00dbe948[];
extern const char DAT_00dbfc84[];
extern const char* DAT_00f4c35c[5];
namespace f3m_00470c20 {
namespace f3m_00470c20 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
class NamedObject
{
public:
    virtual void Slot00();
    virtual void DeleteThis();
    virtual void Slot08();
    virtual void* AsNode();
    volatile long references;
    const char* name;
    const char* GetName() const { return name; }
    __forceinline void IncRef() { volatile long* p = &references; InterlockedIncrement(p); }
    __forceinline void DecRef()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
};
struct NamedReference
{
    NamedObject* object;
    NamedReference(NamedObject* value) : object(value)
    {
        if (object)
            object->IncRef();
    }
    ~NamedReference()
    {
        if (object)
            object->DecRef();
    }
};
struct NamedSlot { unsigned char flags; NamedObject* object; };
NamedObject* __cdecl FUN_00aab350(NamedObject* root, const char* name, bool recursive);
void __cdecl FUN_00887da0(const char* format, ...);

class NamedObjectSet
{
public:
    NamedObject* root;
    NamedSlot slots[5];
    void FUN_00470c20(NamedObject* input);
};
// pdb: BipedAnim::InitRoot | BipedAnim.obj | fnv360_0822_retail, ustr, medium
// pdb params: apNode
void NamedObjectSet::FUN_00470c20(NamedObject* input)
{
    root = FUN_00aab350(input, DAT_00dbe948, true);
    for (int index = 0; index < 5; ++index)
    {
        NamedReference reference(FUN_00aab350(input, DAT_00f4c35c[index], true));
        if (reference.object && reference.object->AsNode())
        {
            slots[index].flags |= 1;
            slots[index].object = reference.object;
        }
        else
            FUN_00887da0(DAT_00dbfc84, DAT_00f4c35c[index], input->GetName());
    }
}

}
}   // namespace f3m_00470c20

// @f3 0x00460af0 (community match, verified in this file)
struct Entry460af0
{
    int kind00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
extern Entry460af0 DAT_00f5aca8[];

int TESAnimGroup_GetType(unsigned char id);

class Item460af0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual bool v03();
    virtual void* v04(int index);

    void* FUN_0045ca00(void* context, int kind);
};

class Map460af0
{
public:
    bool FUN_0045c6e0(unsigned short key, Item460af0** value);
};

class Owner460af0
{
public:
    void* FUN_0045f400(void* data, unsigned short id, int kind);
    void* FUN_00460af0(unsigned short id, int kind);

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
    Map460af0* mapDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    void* contextF0;
};

__declspec(noinline) bool Map460af0::FUN_0045c6e0(unsigned short key, Item460af0** value)
{
    if (key == 0) return false;
    *value = 0;
    return true;
}

// pdb: Animation::StartGroup | Animation.obj | fnv360_0822_retail, call_gap, low
// pdb params: asNewGroup, aeSection
void* Owner460af0::FUN_00460af0(unsigned short id, int kind)
{
    Item460af0* res;
    if (id == 0xFF || !mapDC->FUN_0045c6e0(id, &res))
        return 0;
    long obj;
    obj = kind;
    if (-1 == obj)
        obj = DAT_00f5aca8[TESAnimGroup_GetType((unsigned char)id)].kind00;
    void* x;
    switch (obj)
    {
    case 5:
    case 6:
        if (!res->v03())
        {
            x = res->FUN_0045ca00(contextF0, obj);
            break;
        }
    default:
        x = res->v04(-1);
        break;
    }
    return FUN_0045f400(x, id, kind);
}

// @f3 0x0046d620 (community match, verified in this file)
#include <math.h>
void* __cdecl FUN_0089eb90(unsigned int bytes);
void __cdecl FUN_0089ec10(void* memory);
namespace f3m_0046d620 {
struct QPt { float x, y, z; };
struct QMat {
    float m[3][3];
    void FUN_00823810(float x, float y, float z);
};
extern QPt DAT_0108ec68;
extern const QMat FUN_00f72574;
}
using f3m_0046d620::QPt;
using f3m_0046d620::QMat;

class QShapeBase {
public:
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
};
class FUN_0046c6c0 : public QShapeBase {
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    QMat rot;
    FUN_0046c6c0(const QPt* a, const QPt* b, const QMat* m);
};
class FUN_0046c5e0 : public QShapeBase {
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    FUN_0046c5e0(const QPt* a, const QPt* b);
};

inline float QAbs(float f) { return (float)fabs(f); }

class QOwner620 {
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    QPt pos;
    QShapeBase* FUN_0046d620(const QPt& r);
};

// pdb: BGSPrimitiveBox::MakeMultiBoundShape | BGSPrimitive.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BGSPrimitiveBox::MakeOcclusionBox)
// pdb params: akAngle
QShapeBase* QOwner620::FUN_0046d620(const QPt& r)
{
    bool rotated = false;
    if (QAbs(r.x) > 0.01f) rotated = true;
    if (QAbs(r.y) > 0.01f) rotated = true;
    if (QAbs(r.z) > 0.01f) rotated = true;
    if (rotated) {
        FUN_0046c6c0* b = new FUN_0046c6c0(&f3m_0046d620::DAT_0108ec68, &pos, &f3m_0046d620::FUN_00f72574);
        QMat m;
        m.FUN_00823810(r.x, r.y, r.z);
        b->rot = m;
        return b;
    }
    return new FUN_0046c5e0(&f3m_0046d620::DAT_0108ec68, &pos);
}

// @f3 0x00465250 (community match, verified in this file)
#include <new>
namespace f3m_00465250 {
namespace f3m_00465250 {
struct QArr {
    void* vtable00; void* data04; int size08, capacity0C;
    void Alloc(unsigned int n);
    QArr(unsigned int n = 0) { vtable00 = &DAT_00dbe764; data04 = 0; size08 = 0; capacity0C = 0; if (n) Alloc(n); }
};
// pdb: BSSimpleArray<BSSimpleArray<NiPoint3,1024>,1024>::Add | BGSAutoWater.obj | fnv360_0822_retail, call_gap, low
// pdb params: aValue
void __stdcall FUN_00465250(QArr* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
        new (&items[i]) QArr;
}
}
}   // namespace f3m_00465250

// @f3 0x0047e180 (community match, verified in this file)
namespace f3m_0047e180 {
namespace f3m_0047e180 {
struct QForm;
struct QBase { int unk00, unk04, unk08, unk0C; };
struct QForm { QBase* FUN_0040bd70(); };
struct QFormNode { QForm* data; QFormNode* next; };
struct QItem { QFormNode* list; int unk04; int key08; };
struct QNode { QItem* data; QNode* next; };
struct QOwner {
    QNode* head;
    QItem* FUN_0047e180(int key, int unused, int formKey);
};
// pdb: InventoryChanges::GetObjectInList | InventoryChanges.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: apObj, ableveled, aId
QItem* QOwner::FUN_0047e180(int key, int unused, int formKey)
{
    QNode* n = head;
    bool searching = true;
    while (n && searching) {
        QItem* it = n->data;
        if (it && it->key08 == key)
            searching = false;
        else
            n = n->next;
    }
    if (n) {
        QItem* it = n->data;
        if (it && formKey) {
            for (QFormNode* m = it->list; m; m = m->next) {
                QForm* f = m->data;
                if (f && f->FUN_0040bd70() && f->FUN_0040bd70()->unk0C == formKey)
                    return it;
            }
            return 0;
        }
        return it;
    }
    return 0;
}
}
}   // namespace f3m_0047e180

// @f3 0x0047fd60 (community match, verified in this file)
namespace f3m_0047fd60 {

struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;

class FUN_0040eda0;

struct Node {
    FUN_0040eda0* item;
    Node* next;
    Node() : item(0), next(0) {}
    Node(FUN_0040eda0* i) : item(i), next(0) {}
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

class FUN_0040eda0 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    short unk18;
    FUN_0040eda0();
    void ExtraDataList_DuplicateExtraListForContainer(FUN_0040eda0* item);
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

struct FUN_0047fd60 {
    Node* unk00;
    int unk04;
    int unk08;
    FUN_0047fd60(const FUN_0047fd60& src);
};

// pdb: ItemChange::ItemChange | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apCopy
FUN_0047fd60::FUN_0047fd60(const FUN_0047fd60& src)
{
    unk08 = src.unk08;
    unk00 = new Node();
    for (Node* n = src.unk00; n && n->item; n = n->next) {
        FUN_0040eda0* obj = new FUN_0040eda0();
        obj->ExtraDataList_DuplicateExtraListForContainer(n->item);
        if (obj) {
            Node* tail = unk00;
            while (tail->next)
                tail = tail->next;
            if (tail->item)
                tail->next = new Node(obj);
            else
                tail->item = obj;
        }
    }
    unk04 = src.unk04;
}

}

// @f3 0x0046dd60 (community match, verified in this file)
namespace task1142 {
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
struct Object {
 virtual ~Object(); virtual void slot4(); virtual void Configure(unsigned);
 unsigned type;
 int unk08,unk0c,unk10,unk14;
 float fValue,fMult,fAdd;
 int unk24,unk28,unk2c,unk30;
 Object();
 static void* operator new(unsigned size) {return DAT_01090a78.FUN_0086b930(size);}
};
// pdb: BGSPrimitive::CreatePlane | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aSize, aColor
Object* FUN_0046dd60(const float* values,unsigned ui) {
 Object* p=new Object;
 p->Configure(ui);
 p->fValue=values[0]*0.5;
 p->fMult=1.0;
 p->fAdd=values[1]*0.5;
 p->type=3;
 return p;
}
}

// @f3 0x0047af80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0047af80 {
struct Grid1253 {
 virtual ~Grid1253();
 virtual void Init();
 virtual void DetachAllCells();
 virtual void AttachAllCells();
 virtual bool SetGridPosition(int,int);
 virtual void Shift(int,int);
 virtual void Detach(unsigned int,unsigned int);
 virtual void ClearTileExtraPair(unsigned int,unsigned int);
 virtual void MoveItem(unsigned int,unsigned int,unsigned int,unsigned int);
 int iHorizontalPixelCenterObj,iCenterPixelY;
 unsigned int uiDimension;
 void GridArray_Shift(int,int);
};
// @fnv 0x004b9f70
// pdb: GridArray::Shift | GridArray.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Grid1253::GridArray_Shift(int aiShiftX, int aiShiftY)
{
    unsigned int j = 0;
    unsigned int i = 0;
    iHorizontalPixelCenterObj += aiShiftX;
    iCenterPixelY += aiShiftY;
    if ((unsigned int)abs(aiShiftX) >= uiDimension || (unsigned int)abs(aiShiftY) >= uiDimension)
    {
        DetachAllCells();
        return;
    }
    while (aiShiftX != 0)
    {
        if (aiShiftX < 0)
        {
            for (i = 0; i < uiDimension; ++i)
            {
                j = uiDimension - 1;
                Detach(j, i);
                for (; j > 0; --j)
                    MoveItem(j - 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiShiftX;
        }
        else
        {
            for (i = 0; i < uiDimension; ++i)
            {
                j = 0;
                Detach(j, i);
                for (; j < uiDimension - 1; ++j)
                    MoveItem(j + 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiShiftX;
        }
    }
    while (aiShiftY != 0)
    {
        if (aiShiftY < 0)
        {
            for (j = 0; j < uiDimension; ++j)
            {
                i = uiDimension - 1;
                Detach(j, i);
                for (; i > 0; --i)
                    MoveItem(j, i - 1, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiShiftY;
        }
        else
        {
            for (j = 0; j < uiDimension; ++j)
            {
                i = 0;
                Detach(j, i);
                for (; i < uiDimension - 1; ++i)
                    MoveItem(j, i + 1, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiShiftY;
        }
    }
}
}   // namespace f3m_0047af80

// @f3 0x004749a0 (community match, verified in this file)
struct F3HeapStandIn {
    void Free(void* p) throw();
};
extern F3HeapStandIn g_f3Heap;

void NiFree(void* p);

class IBSAnimNoteReceiver {
public:
    virtual ~IBSAnimNoteReceiver() {}
    virtual void HandleNote() = 0;
};

class BSAnimNoteReceiver : public IBSAnimNoteReceiver {
public:
    struct BSAnimNoteReceiverType {
        int unk0;
        int unk4;
    };
    typedef NiTArray<BSAnimNoteReceiverType*, NiTMallocInterface<BSAnimNoteReceiverType*> > ReceiverArray;

    void* unk04;
    ReceiverArray m_kReceivers;

    virtual ~BSAnimNoteReceiver();
    virtual void HandleNote();
};

template <>
inline BSAnimNoteReceiver::ReceiverArray::~NiTArray()
{
    NiFree(m_pBase);
}

static inline BSAnimNoteReceiver::BSAnimNoteReceiverType* RemoveEnd(BSAnimNoteReceiver::ReceiverArray& array)
{
    if (array.m_usSize == 0)
        return 0;
    array.m_usSize--;
    BSAnimNoteReceiver::BSAnimNoteReceiverType* element = array.m_pBase[array.m_usSize];
    array.m_pBase[array.m_usSize] = 0;
    if (element != 0)
        array.m_usESize--;
    return element;
}

// pdb: BSAnimNoteReceiver::~BSAnimNoteReceiver | BSAnimNoteReceiver.obj | fnv360_0822_retail, call_seq, high
BSAnimNoteReceiver::~BSAnimNoteReceiver()
{
    unsigned int count = m_kReceivers.m_usSize;
    for (unsigned int i = 0; i < count; i++)
        g_f3Heap.Free(RemoveEnd(m_kReceivers));
}

// @f3 0x0046a920 (community match, verified in this file)
extern unsigned long hkThreadMemoryTlsIndex;
namespace f3m_0046a920 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);


class hkThreadMemory {
public:
    void deallocateChunk(void* p, int nbytes, int cls);
    static hkThreadMemory& getInstance()
    {
        return *static_cast<hkThreadMemory*>(TlsGetValue(hkThreadMemoryTlsIndex));
    }
};

struct hkpWorldRayCastOutput {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
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
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
};

template <typename T>
inline void hkDeallocateChunk(T* p, int n, int cls)
{
    hkThreadMemory::getInstance().deallocateChunk(p, n * sizeof(T), cls);
}

template <typename T>
class hkArray {
public:
    enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
    ~hkArray()
    {
        releaseMemory();
    }
    int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            int n = getCapacity();
            hkThreadMemory& mem = hkThreadMemory::getInstance();
            mem.deallocateChunk(m_data, n * sizeof(T), 0x17);
        }
    }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

class hkpRayHitCollector {
public:
    virtual void addRayHit(const void* cdBody, const void* hitInfo) = 0;
    virtual ~hkpRayHitCollector() {}
    float m_earlyOutHitFraction;
};

class hkpAllRayHitCollector : public hkpRayHitCollector {
public:
    virtual void addRayHit(const void* cdBody, const void* hitInfo);
    virtual ~hkpAllRayHitCollector();
    int unk08;
    int unk0C;
    hkArray<hkpWorldRayCastOutput> m_hits;
};

// pdb: hkpAllRayHitCollector::~hkpAllRayHitCollector | BGSDecalManager.obj | fnv360_0822_retail, call_seq, medium
hkpAllRayHitCollector::~hkpAllRayHitCollector()
{
}
}   // namespace f3m_0046a920

// @f3 0x004766a0 (community match, verified in this file)
extern char DAT_0106e5c0[260];
namespace f3m_004766a0 {



extern "C" void FUN_00a29680(const char* format, ...);

// pdb: XSetFileCacheSize | filemisc.obj | fnv360_0721_retail, objrun_prop, low, conflict (skyrim: FillUserNameGlobal)
// pdb params: dwCacheSize
void __cdecl FUN_004766a0(const char* arg)
{
    DWORD size = 260;
    char text[260];
    if (GetUserNameA(DAT_0106e5c0, &size))
    {
        FUN_00a29680("%s", arg);
        sprintf(text, "Computer Name: %s", DAT_0106e5c0);
        FUN_00a29680(text);
    }
}
}   // namespace f3m_004766a0

// @f3 0x00470420 (community match, verified in this file)
namespace f3m_00470420 {
struct Member0420 {
    int unk00;
    ~Member0420();
};
struct Owner0420 {
    int unk00;
    Member0420 member;
    void FUN_00470060();
    ~Owner0420();
};
// pdb: BGSTextureUseMap::~BGSTextureUseMap | BGSTextureUseMap.obj | fnv360_0721_beta, call_seq, medium
Owner0420::~Owner0420()
{
    FUN_00470060();
}
}   // namespace f3m_00470420

// @f3 0x0047fd30 (community match, verified in this file)
namespace f3m_0047fd30 {
struct Node1000 { void FUN_006c8220(); };
struct Heap1000 { void FUN_0086ba60(void* object); };
extern Heap1000 DAT_01090a78;
struct Owner1000 { Node1000* head00; void FUN_0047fd30(); };
// pdb: ItemChange::~ItemChange | InventoryChanges.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSTArray<struct TESRegionSound *,class BSTArrayHeapAllocator>::operator[])
void Owner1000::FUN_0047fd30() {
    if (head00) head00->FUN_006c8220();
    Node1000* node = head00;
    if (node) {
        node->FUN_006c8220();
        DAT_01090a78.FUN_0086ba60(node);
    }
    head00 = 0;
}
}   // namespace f3m_0047fd30

// @f3 0x00465540 (community match, verified in this file)
namespace f3m_00465540 {
// FUN_00465540: scalar deleting destructor of a class with a vtable at +0,
// handle at +4 (closed if non-null), two zeroed fields at +8/+C, and a
// flag-gated free through a global pool object.

struct PoolAllocator {
    void FUN_0086ba60(void* p);
};
extern PoolAllocator DAT_01090a78;

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* h);

struct FUN_00465540 {
    virtual ~FUN_00465540();
    void* unk04;
    int unk08;
    int unk0C;
    // pdb: BSSimpleArray<NiPoint3,1024>::`scalar deleting destructor' | BGSAutoWater.obj | fnv360_0822_retail, vtable, medium
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

FUN_00465540::~FUN_00465540()
{
    if (unk04 != 0) {
        FreeLibrary(unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }
}
}   // namespace f3m_00465540

// @f3 0x0046f420 (community match, verified in this file)
namespace f3m_0046f420 {
struct FUN_0046f420_Class {
    int unk00;
    void* unk04;
    int unk08;
    int unk0C;

    FUN_0046f420_Class* FUN_0046f420(unsigned char flag);
};

class a43840_Mem {
public:
    void _DeallocateAlias(void* p);
};

extern void FUN_00dbf320();
extern void (__stdcall* DAT_00dbf328)(void*);
extern a43840_Mem DAT_01090a78;

// pdb: BSSimpleArray<SCENE_INFO_DATA_STRUCT,1024>::`scalar deleting destructor' | BGSSceneInfo.obj | fnv360_0822_retail, vtable, medium
FUN_0046f420_Class* FUN_0046f420_Class::FUN_0046f420(unsigned char flag) {
    unk00 = (int)(void*)&FUN_00dbf320;

    if (unk04) {
        DAT_00dbf328(unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }

    if (flag & 1) {
        DAT_01090a78._DeallocateAlias(this);
    }

    return this;
}
}   // namespace f3m_0046f420

// @f3 0x00470620 (community match, verified in this file)
namespace f3m_00470620 {
namespace f3m_00470620 {
class Cell_470620
{
public:
    void* FUN_004d5230();
};
class Lookup_470620
{
public:
    Cell_470620** FUN_0047b220(unsigned int x, unsigned int y);
};
struct World_470620
{
    int unk00; int unk04;
    Lookup_470620* lookup;
    int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30;
    Cell_470620* cached;
};
}
using namespace f3m_00470620;
extern World_470620* DAT_0107a0d8;
extern unsigned int DAT_0106e9cc;
class Visitor_470620
{
public:
    Cell_470620* cell;
    void FUN_004704a0(void* data, int arg);
    void BGSTextureUseMap_CollectTextureUseDataForLoadedArea(int arg);
};
// pdb: BGSTextureUseMap::CollectTextureUseDataForLoadedArea | BGSTextureUseMap.obj | fnv360_0822_retail, call_gap + skyrim(call_gap_sim), high
void Visitor_470620::BGSTextureUseMap_CollectTextureUseDataForLoadedArea(int arg)
{
    Cell_470620* c = DAT_0107a0d8->cached;
    if (c)
    {
        void* d = c->FUN_004d5230();
        cell = c;
        FUN_004704a0(d, arg);
        return;
    }
    unsigned int center = DAT_0106e9cc >> 1;
    unsigned int lo = center - 2;
    unsigned int hi = center + 2;
    for (unsigned int x = lo; x <= hi; x++)
    {
        for (unsigned int y = lo; y <= hi; y++)
        {
            c = *DAT_0107a0d8->lookup->FUN_0047b220(x, y);
            if (c)
            {
                void* d = c->FUN_004d5230();
                cell = c;
                FUN_004704a0(d, arg);
            }
        }
    }
}
}   // namespace f3m_00470620

// @f3 0x00474a70 (community match, verified in this file)
namespace f3m_00474a70 {
namespace f3m_00474a70 {
struct Heap { void* FUN_0086b930(unsigned int bytes); };
struct Pair { int a; int b; };
struct Array
{
    unsigned int unk00;
    Pair** data;
    unsigned short capacity, count, unk0C, growth;
    void FUN_00555790(unsigned int count);
    void FUN_005b3880(unsigned int index, Pair* const* value);
    __forceinline void Append(Pair* value)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_00555790(growth + index);
        FUN_005b3880(index, &value);
    }
};
struct Owner
{
    int unk00;
    int unk04;
    Array pairs;
    int FUN_004748f0(int a, int b);
    bool FUN_00474a70(int a, int b);
};
}
extern f3m_00474a70::Heap DAT_01090a78;
namespace f3m_00474a70 {
// pdb: BSAnimNoteReceiver::Register | BSAnimNoteReceiver.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeType, apCallbackFunc
bool Owner::FUN_00474a70(int a, int b)
{
    if (FUN_004748f0(a, b) == -1)
    {
        Pair* p = (Pair*)DAT_01090a78.FUN_0086b930(8);
        if (p)
        {
            p->a = a;
            p->b = b;
        }
        else
            p = 0;
        pairs.Append(p);
    }
    return false;
}
}
}   // namespace f3m_00474a70

// @f3 0x0046deb0 (community match, verified in this file)
namespace f3m_0046deb0 {
struct Alloc_01090a78 {
    void* FUN_0086b930(unsigned int size);
};
extern Alloc_01090a78 DAT_01090a78;

struct Obj34 {
    virtual void v0();
    virtual void v1();
    virtual void v2(int a);
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
    Obj34();
    void FUN_0046d800(float f);
    static void* operator new(unsigned int n) throw() { return DAT_01090a78.FUN_0086b930(n); }
};

// pdb: BGSPrimitive::CreateSphere | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afRadius, aColor
Obj34* FUN_0046deb0(float f, int n)
{
    Obj34* p = new Obj34();
    p->v2(n);
    p->FUN_0046d800(f);
    p->unk04 = 2;
    return p;
}
}   // namespace f3m_0046deb0

// @f3 0x0047cdc0 (community match, verified in this file)
namespace f3m_0047cdc0 {
struct Node_0047cdc0 {
    int unk00;
    int unk04;
};

struct Pool_0086b930 {
    void* FUN_0086b930(unsigned int size);
};
extern Pool_0086b930 DAT_01090a78;

struct FUN_0047cdc0_cls {
    Node_0047cdc0* unk00;
    int unk04;
    void* unk08;
    FUN_0047cdc0_cls* FUN_0047cdc0(void* a, int b);
};

// pdb: ItemChange::ItemChange | InventoryChanges.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: apObject, aiNumber
FUN_0047cdc0_cls* FUN_0047cdc0_cls::FUN_0047cdc0(void* a, int b)
{
    unk08 = a;
    Node_0047cdc0* n = (Node_0047cdc0*)DAT_01090a78.FUN_0086b930(8);
    if (n != 0) {
        n->unk00 = 0;
        n->unk04 = 0;
    } else {
        n = 0;
    }
    unk00 = n;
    unk04 = b;
    return this;
}
}   // namespace f3m_0047cdc0

// @f3 0x004654e0 (community match, verified in this file)
namespace f3m_004654e0 {
// Array-owner destructor: vptr store, element dtors (16-byte elements), free buffer via vslot 2, zero fields.
struct Elem4654 {
    virtual ~Elem4654() {}
    int unk04;
    int unk08;
    int unk0C;
};

class Arr4654 {
public:
    virtual ~Arr4654();
    virtual void Slot1();
    virtual void Free(void* p);
    Elem4654* unk04;
    unsigned int unk08;
    int unk0C;
};

// pdb: BSSimpleArray<BSSimpleArray<NiPoint3,1024>,1024>::~BSSimpleArray<BSSimpleArray<NiPoint3,1024>,1024> | BGSAutoWater.obj | fnv360_0822_retail, call_seq, medium
Arr4654::~Arr4654()
{
    if (unk04 != 0) {
        unsigned int n = unk08;
        if (n > 0) {
            Elem4654* p = unk04;
            do {
                p->~Elem4654();
                p++;
            } while (--n != 0);
        }
        Arr4654* self = this;
        self->Free(unk04);
        unk04 = 0;
        unk0C = 0;
        unk08 = 0;
    }
}
}   // namespace f3m_004654e0

// @f3 0x00464240 (community match, verified in this file)
namespace f3m_00464240 {
struct FUN_00464240_Obj {
    virtual ~FUN_00464240_Obj();
    virtual void Slot1();
    int unk04;
    int unk08;
};

struct FUN_00464240_Node {
    FUN_00464240_Node* unk00;
    int unk04;
    FUN_00464240_Obj* unk08;
};

struct FUN_00464240_Holder {
    FUN_00464240_Node* unk00;
    void FUN_00bf5110();
};

struct FUN_00464240_Mgr {
    void FUN_00427160(char* buf, int flag);
};

struct FUN_00464240_Set {
    void FUN_0086ba60(FUN_00464240_Holder* h);
};

struct FUN_00464240_Buf {
    char data[0x104];
    FUN_00464240_Buf() {}
    ~FUN_00464240_Buf() {}
};

typedef int (__stdcall* FUN_00464240_Pred)(int*);
extern FUN_00464240_Pred DAT_00d9b064;
extern FUN_00464240_Mgr* DAT_0106ca70;
extern FUN_00464240_Set DAT_01090a78;
int __cdecl FUN_00c007fc(char* buf, unsigned int size, int value);

struct FUN_00464240_Base {
    virtual ~FUN_00464240_Base() {}
};

struct FUN_00464240 : FUN_00464240_Base {
    FUN_00464240_Holder* unk04;
    virtual ~FUN_00464240();
};

// pdb: AnimSequenceMultiple::~AnimSequenceMultiple | Animation.obj | fnv360_0822_retail, call_seq, medium
FUN_00464240::~FUN_00464240()
{
    FUN_00464240_Buf buf;
    if (unk04 != 0) {
        FUN_00464240_Node* node = unk04->unk00;
        if (node != 0) {
            FUN_00464240_Pred pred = DAT_00d9b064;
            do {
                FUN_00464240_Obj* obj = node->unk08;
                FUN_00c007fc(buf.data, 0x104, obj->unk08);
                if (pred(&obj->unk04) == 0) {
                    obj->Slot1();
                }
                DAT_0106ca70->FUN_00427160(buf.data, 1);
                node = node->unk00;
            } while (node != 0);
        }
        FUN_00464240_Holder* h = unk04;
        if (h != 0) {
            h->FUN_00bf5110();
            DAT_01090a78.FUN_0086ba60(h);
        }
    }
}
}   // namespace f3m_00464240

// @f3 0x00471e50 (community match, verified in this file)
namespace f3m_00471e50 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

struct FUN_00471e50_obj {
    virtual void FUN_00471e50_release(int flags);
    int unk04;
    long unk08;
};

struct FUN_00471e50_ref {
    FUN_00471e50_obj* unk00;
    FUN_00471e50_ref() : unk00(0) {}
    ~FUN_00471e50_ref() {
        if (unk00 != 0) {
            FUN_00471e50_obj* p = unk00;
            if (InterlockedDecrement(&p->unk08) == 0 && p != 0) p->FUN_00471e50_release(1);
        }
    }
};

struct FUN_00471e50_cls {
    int unk00;
    void FUN_00471e50(int a1, int a2, int a3);
};

struct FUN_0042cd20_owner {
    void FUN_0042cd20(FUN_00471e50_cls* self, FUN_00471e50_ref* out, int a, int b, int c);
};

extern FUN_0042cd20_owner* DAT_0106ca70;

// pdb: BipedAnim::QueueHelmetLoad | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: aePriority, apParent, aeBipedObject
void FUN_00471e50_cls::FUN_00471e50(int a1, int a2, int a3)
{
    FUN_00471e50_ref tmp;
    int entry = *(int*)((char*)this + ((a3 + 3) << 4));
    if (entry != 0 && entry != -1) {
        DAT_0106ca70->FUN_0042cd20(this, &tmp, a1, a2, a3);
    }
}
}   // namespace f3m_00471e50

// @f3 0x00479b50 (community match, verified in this file)
namespace f3m_00479b50 {
struct NiPoint3 { };

extern "C" NiPoint3 _NiPoint3_ZERO;

struct NiPick {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    volatile long* unk14;
    bool PerformPick(const NiPoint3&, const NiPoint3&, bool);
};

struct RefCounted {
    virtual void vf0();
    virtual void release();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

extern "C" char __cdecl FUN_00477BC0(int a1, int a2, int a3, float a4, int a5);

// pdb: PickDistance | GlobalFunc.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apPick, aOrigin, aDir, afDistance, apTarget, abClearResults
char __cdecl FUN_00479b50(NiPick* a1, int a2, int a3, float a4, int a5, char a6)
{
    char result = 0;
    if (a1 != 0 && a5 != 0 && a4 != 0.0f)
    {
        if (a6 != result)
        {
            volatile long* v6 = a1->unk14;
            if (v6 != 0)
            {
                if (InterlockedDecrement(v6 + 1) == 0)
                    ((RefCounted*)v6)->release();
                a1->unk14 = 0;
            }
            a1->PerformPick(_NiPoint3_ZERO, _NiPoint3_ZERO, false);
        }
        result = FUN_00477BC0((int)a1, a2, a3, a4, a5);
    }
    return result;
}
}   // namespace f3m_00479b50

// @f3 0x00466b80 (community match, verified in this file)
namespace f3m_00466b80 {


struct WaterPoint {
    float x, y, z;
    WaterPoint() {}
    WaterPoint(float a, float b, float c) : x(a), y(b), z(c) {}
    __forceinline bool operator==(const WaterPoint& p) const { return x == p.x && y == p.y && z == p.z; }
};
struct WaterHeap { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern WaterHeap DAT_01090a78;
struct WaterPoints;
struct WaterPointVtable {
    void (__thiscall* destroy)(WaterPoints*, unsigned int);
    WaterPoint* (__thiscall* allocate)(WaterPoints*, unsigned int);
    void (__thiscall* release)(WaterPoints*, WaterPoint*);
    WaterPoint* (__thiscall* reallocate)(WaterPoints*,WaterPoint*,unsigned int);
};
extern const WaterPointVtable DAT_00dbe764;
struct WaterPoints {
    const WaterPointVtable* vtable;
    WaterPoint* buffer;
    unsigned int size, capacity;
    __forceinline void constructItems(WaterPoint* p,unsigned int n) {
        for(unsigned int i=0;i<n;i++) new (p+i) WaterPoint;
    }
    __forceinline void destructItems(WaterPoint* p,unsigned int n) {
        for(unsigned int i=0;i<n;i++) p[i].~WaterPoint();
    }
    __forceinline void setup(unsigned int reserve,unsigned int count) {
        buffer=0; size=0; capacity=0;
        if(count>reserve) reserve=count;
        if(reserve>0) { buffer=vtable->allocate(this,reserve); capacity=reserve; }
        if(count>0) { constructItems(buffer,count); size=count; }
    }
    WaterPoints() : vtable(&DAT_00dbe764) { setup(0,0); }
    ~WaterPoints() {
        vtable = &DAT_00dbe764;
        if (buffer) {
            vtable->release(this,buffer);
            buffer = 0;
            capacity = 0;
            size = 0;
        }
    }
    static void* operator new(size_t n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    __forceinline void deallocateBuffer() { vtable->release(this,buffer); buffer=0; }
    __forceinline void clear(bool freeMemory=true) {
        if (buffer) {
            destructItems(buffer,size);
            if(freeMemory) {
                deallocateBuffer();
                buffer=0;
                capacity=0;
            }
            size=0;
        }
    }
    void FUN_0079ecc0(unsigned int newCapacity, unsigned int count);
    unsigned int FUN_007a1650();
    __forceinline unsigned int addNew() {
        if (size == capacity) {
            if (capacity == 0) {
                buffer = vtable->allocate(this,4);
                capacity = 4;
            } else {
                unsigned int n;
                if (capacity > 1024) n = capacity + 1024;
                else n = capacity * 2;
                FUN_0079ecc0(n,size);
                capacity = n;
            }
        }
        size++;
        return size-1;
    }
    __forceinline unsigned int appendInline(const WaterPoint& point) {
        unsigned int i=addNew();
        constructItems(buffer+i,1);
        buffer[i]=point;
        return i;
    }
    __forceinline unsigned int append(const WaterPoint& point) {
        unsigned int i=FUN_007a1650();
        constructItems(buffer+i,1);
        buffer[i]=point;
        return i;
    }
    __forceinline void removeLast() { if (size) --size; }
    __forceinline WaterPoint* at(unsigned int i) { return buffer ? buffer+i : 0; }
    static __forceinline bool equal(const WaterPoint& a,const WaterPoint& b) { return a==b; }
    __forceinline unsigned int find(const WaterPoint& point,unsigned int start,bool (__cdecl* eq)(const WaterPoint&,const WaterPoint&)) const {
        for(unsigned int i=start;i<size;i++) {
            if(buffer && eq(buffer[i],point)) return i;
        }
        return -1;
    }
    __forceinline bool contains(const WaterPoint& p) const { return find(p,0,equal)!=(unsigned int)-1; }
    __forceinline void uniqueInline(const WaterPoint& point) { if (!contains(point)) appendInline(point); }
    __forceinline void unique(const WaterPoint& point) { if (!contains(point)) append(point); }
    unsigned int FUN_004650c0(const WaterPoint&, unsigned int, bool (__cdecl*)(const WaterPoint&, const WaterPoint&)) const;
};
bool __cdecl FUN_00465120(const WaterPoint&,const WaterPoint&);
struct FUN_004654e0;
struct WaterGroupVtable {
    void (__thiscall* destroy)(FUN_004654e0*,unsigned int);
    WaterPoints* (__thiscall* allocate)(FUN_004654e0*,unsigned int);
    void (__thiscall* release)(FUN_004654e0*,WaterPoints*);
};
extern const WaterGroupVtable DAT_00dbe778;
struct FUN_004654e0 {
    const WaterGroupVtable* vtable;
    WaterPoints* buffer;
    unsigned int size, capacity;
    FUN_004654e0() : vtable(&DAT_00dbe778), buffer(0), size(0), capacity(0) {}
    ~FUN_004654e0();
    void FUN_00466a70(int index,const WaterPoints& point);
    __forceinline WaterPoints& operator[](unsigned int i) { return buffer[i]; }
};
struct FUN_00832f70 {
    WaterPoint normal;
    float constant;
    FUN_00832f70(const WaterPoint& n, const WaterPoint& p);
    int FUN_00464cf0(const WaterPoint& p);
    __forceinline float distance(const WaterPoint& p) const {
        return normal.x*p.x + normal.y*p.y + normal.z*p.z - constant;
    }
    __forceinline int classify(const WaterPoint& p) const {
        float d=distance(p);
        if (d<0.0f) return 2;
        if (d>0.0f) return 1;
        return 0;
    }
};
struct WaterTerrainData {
    int unk00;
    WaterPoint** vertices;
    int unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    float heightOffset;
};
struct WaterTerrain {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
    WaterTerrainData* data;
    void FUN_004d1680(int);
    void FUN_004cfbe0();
};
struct WaterWorld { bool FUN_00501180(); };
struct WaterCell {
    WaterTerrain* TESObjectCELL_GetLand();
    float FUN_004d5350();
    WaterWorld* FUN_004d3780();
};
extern WaterPoints* DAT_0106dedc;
extern unsigned short DAT_00f4f228[];
int __cdecl FUN_00464e60(WaterCell*,WaterPoint);
int __cdecl FUN_005dccb0(const WaterPoint*,const WaterPoint*,const WaterPoint*,const WaterPoint*,WaterPoint*);
int __cdecl FUN_00464df0(const void*,const void*);
int __cdecl FUN_00464e20(const void*,const void*);
void __cdecl FUN_00c011c0(void*,unsigned int,unsigned int,int (__cdecl*)(const void*,const void*));

__forceinline void addBoundary(FUN_004654e0& boundaryGroups,int a,int b,const WaterPoint& point) {
    if ((a&1) && (b&1)) boundaryGroups[0].append(point);
    else if ((a&2) && (b&2)) boundaryGroups[1].append(point);
    else if ((a&4) && (b&4)) boundaryGroups[2].append(point);
    else if ((a&8) && (b&8)) boundaryGroups[3].append(point);
}

// pdb: BGSAutoWater::GatherLineSegments | BGSAutoWater.obj | fnv360_0721_beta, udata, high
void __cdecl BGSAutoWater_GatherLineSegments(WaterCell* cell) {
    WaterTerrain* terrain=cell->TESObjectCELL_GetLand();
    float water=cell->FUN_004d5350();
    if (!DAT_0106dedc) DAT_0106dedc=new WaterPoints;
    else DAT_0106dedc->clear();
    if (!terrain) return;
    bool hadData;
    if (terrain->data && terrain->data->vertices) hadData=true;
    else {
        hadData=false;
        terrain->FUN_004d1680(0);
    }
    FUN_004654e0 boundaryGroups;
    for (int i=0;i<4;i++) {
        WaterPoints empty;
        boundaryGroups.FUN_00466a70(i,empty);
    }
    float heightOffset=0.0f;
    bool offset=false;
    if (cell->FUN_004d3780() && cell->FUN_004d3780()->FUN_00501180()) {
        heightOffset=terrain->data ? terrain->data->heightOffset : 0.0f;
        offset=true;
    }
    WaterPoint** vertices=terrain->data ? terrain->data->vertices : 0;
    for (int group=0;group<4;group++) {
        for (int index=0;index<1019;index++) {
            unsigned short a=DAT_00f4f228[index];
            unsigned short b=DAT_00f4f228[index+1];
            unsigned short c=DAT_00f4f228[index+2];
            WaterPoint p1=vertices[group][a];
            WaterPoint p2=vertices[group][b];
            WaterPoint p3=vertices[group][c];
            if (offset) {
                p1.z+=heightOffset;
                p2.z+=heightOffset;
                p3.z+=heightOffset;
            }
            if (p1==p2 || p1==p3 || p2==p3) continue;
            WaterPoint planePosition(0.0f,0.0f,water);
            WaterPoint planeNormal(0.0f,0.0f,1.0f);
            FUN_00832f70 plane(planeNormal,planePosition);
            unsigned short count=0;
            bool endpoint=false;
            bool coplanar=false;
            int flag1=FUN_00464e60(cell,p1);
            int flag2=FUN_00464e60(cell,p2);
            int flag3=FUN_00464e60(cell,p3);
            WaterPoint intersection;
            int result=FUN_005dccb0(&p1,&p2,&planePosition,&planeNormal,&intersection);
            if (result==1) {
                if (p1==intersection || p2==intersection) endpoint=true;
                DAT_0106dedc->appendInline(intersection);
                count=1;
                addBoundary(boundaryGroups,flag1,flag2,intersection);
            } else if (result==-1) {
                coplanar=true;
                DAT_0106dedc->append(p1);
                DAT_0106dedc->append(p2);
                count=2;
            }
            result=FUN_005dccb0(&p1,&p3,&planePosition,&planeNormal,&intersection);
            if (result==1) {
                bool add=true;
                if (p1==intersection || p3==intersection) {
                    if (endpoint || coplanar) add=false;
                    else endpoint=true;
                }
                if (add) {
                    DAT_0106dedc->append(intersection);
                    count++;
                    addBoundary(boundaryGroups,flag1,flag3,intersection);
                }
            } else if (result==-1) {
                coplanar=true;
                for (int i=0;i<count;i++) DAT_0106dedc->removeLast();
                DAT_0106dedc->appendInline(p1);
                DAT_0106dedc->appendInline(p3);
                count=2;
            }
            result=FUN_005dccb0(&p2,&p3,&planePosition,&planeNormal,&intersection);
            if (result==1) {
                bool add=true;
                if (p2==intersection || (p3==intersection && (endpoint || coplanar))) add=false;
                if (add) {
                    DAT_0106dedc->appendInline(intersection);
                    count++;
                    addBoundary(boundaryGroups,flag2,flag3,intersection);
                }
            } else if (result==-1) {
                for (int i=0;i<count;i++) DAT_0106dedc->removeLast();
                DAT_0106dedc->appendInline(p2);
                DAT_0106dedc->appendInline(p3);
                count=2;
            }
            if (count!=2) {
                for (int i=0;i<count;i++) DAT_0106dedc->removeLast();
            }
            if (flag1==9) {
                if (plane.classify(p1)==2) {
                    p1.z=water;
                    if (!boundaryGroups[0].contains(p1)) boundaryGroups[0].appendInline(p1);
                    if (!boundaryGroups[3].contains(p1)) boundaryGroups[3].appendInline(p1);
                }
            } else if (flag1==10) {
                if (plane.classify(p1)==2) {
                    p1.z=water;
                    if (!boundaryGroups[1].contains(p1)) boundaryGroups[1].appendInline(p1);
                    if (!boundaryGroups[3].contains(p1)) boundaryGroups[3].appendInline(p1);
                }
            } else if (flag1==5) {
                if (plane.classify(p1)==2) {
                    p1.z=water;
                    if (!boundaryGroups[0].contains(p1)) boundaryGroups[0].appendInline(p1);
                    if (!boundaryGroups[2].contains(p1)) boundaryGroups[2].appendInline(p1);
                }
            } else if (flag1==6) {
                if (plane.classify(p1)==2) {
                    p1.z=water;
                    if (!boundaryGroups[1].contains(p1)) boundaryGroups[1].append(p1);
                    if (!boundaryGroups[2].contains(p1)) boundaryGroups[2].append(p1);
                }
            }
            if (flag2==9) {
                if (plane.classify(p2)==2) {
                    p2.z=water;
                    if (!boundaryGroups[0].contains(p2)) boundaryGroups[0].appendInline(p2);
                    if (!boundaryGroups[3].contains(p2)) boundaryGroups[3].appendInline(p2);
                }
            } else if (flag2==10) {
                if (plane.classify(p2)==2) {
                    p2.z=water;
                    if (!boundaryGroups[1].contains(p2)) boundaryGroups[1].appendInline(p2);
                    if (!boundaryGroups[3].contains(p2)) boundaryGroups[3].appendInline(p2);
                }
            } else if (flag2==5) {
                if (plane.classify(p2)==2) {
                    p2.z=water;
                    if (!boundaryGroups[0].contains(p2)) boundaryGroups[0].appendInline(p2);
                    if (!boundaryGroups[2].contains(p2)) boundaryGroups[2].appendInline(p2);
                }
            } else if (flag2==6) {
                if (plane.classify(p2)==2) {
                    p2.z=water;
                    if (!boundaryGroups[1].contains(p2)) boundaryGroups[1].append(p2);
                    if (!boundaryGroups[2].contains(p2)) boundaryGroups[2].append(p2);
                }
            }
            if (flag3==9) {
                if (plane.classify(p3)==2) {
                    p3.z=water;
                    if (!boundaryGroups[0].contains(p3)) boundaryGroups[0].appendInline(p3);
                    if (!boundaryGroups[3].contains(p3)) boundaryGroups[3].appendInline(p3);
                }
            } else if (flag3==10) {
                if (plane.classify(p3)==2) {
                    p3.z=water;
                    if (!boundaryGroups[1].contains(p3)) boundaryGroups[1].appendInline(p3);
                    if (!boundaryGroups[3].contains(p3)) boundaryGroups[3].appendInline(p3);
                }
            } else if (flag3==5) {
                if (plane.classify(p3)==2) {
                    p3.z=water;
                    if (!boundaryGroups[0].contains(p3)) boundaryGroups[0].appendInline(p3);
                    if (!boundaryGroups[2].contains(p3)) boundaryGroups[2].appendInline(p3);
                }
            } else if (flag3==6) {
                if (plane.FUN_00464cf0(p3)==2) {
                    p3.z=water;
                    if (boundaryGroups[1].FUN_004650c0(p3,0,FUN_00465120)==-1) boundaryGroups[1].append(p3);
                    if (boundaryGroups[2].FUN_004650c0(p3,0,FUN_00465120)==-1) boundaryGroups[2].append(p3);
                }
            }
        }
    }
    if (!hadData) terrain->FUN_004cfbe0();
    for (int side=0;side<4;side++) {
        if (side==0 || side==1)
            FUN_00c011c0(boundaryGroups[side].buffer,boundaryGroups[side].size,12,FUN_00464e20);
        else
            FUN_00c011c0(boundaryGroups[side].buffer,boundaryGroups[side].size,12,FUN_00464df0);
        for (int i=0;i<(int)boundaryGroups[side].size;i+=2) {
            int n=boundaryGroups[side].size;
            if (n>i+1) {
                DAT_0106dedc->append(boundaryGroups[side].buffer[i]);
                DAT_0106dedc->append(boundaryGroups[side].buffer[i+1]);
            }
        }
    }
}

// pdb: NiPlane::WhichSide | BSTempEffectSimpleDecal.obj | tesv_win, call_seq, medium
inline int FUN_00832f70::FUN_00464cf0(const WaterPoint& p) {
    float d=normal.x*p.x+normal.y*p.y+normal.z*p.z-constant;
    if(d<0.0f) return 2;
    if(d>0.0f) return 1;
    return 0;
}
}   // namespace f3m_00466b80

// @f3 0x0047b9c0 (community match, verified in this file)
namespace f3m_0047b9c0 {
struct Cell47b9c0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char type;
    void FUN_004d7460(int arg);
};

extern int DAT_01071564;

class Owner47b9c0 {
public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int size;
    Cell47b9c0** cells;
    Cell47b9c0** GetAt(unsigned int row, unsigned int col)
    {
        if (row < size && col < size)
            return &cells[row * size + col];
        return 0;
    }
    void FUN_0047b9c0(int arg);
};

// pdb: GridCellArray::ShowPrimitives | GridCell.obj | fnv360_0822_retail, objrun, low
// pdb params: abShow
void Owner47b9c0::FUN_0047b9c0(int arg)
{
    if (!DAT_01071564)
        return;
    for (unsigned int row = 0; row < size; row++) {
        for (unsigned int col = 0; col < size; col++) {
            Cell47b9c0* cell = *GetAt(row, col);
            if (cell && cell->type == 6)
                cell->FUN_004d7460(arg);
        }
    }
}
}   // namespace f3m_0047b9c0

// @f3 0x00464b10 (community match, verified in this file)
#include <windows.h>
namespace Assign464b10 {
extern __declspec(thread) unsigned allocationTag;
struct TagScope {
 unsigned old;
 TagScope(unsigned tag) { old=allocationTag; allocationTag=tag; }
 ~TagScope(){allocationTag=old;}
};
struct Mode { unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c; unsigned unk140; unsigned unk144; unsigned unk148; unsigned unk14c; unsigned unk150; unsigned unk154; unsigned unk158; unsigned unk15c; unsigned unk160; unsigned unk164; unsigned unk168; unsigned unk16c; unsigned unk170; unsigned unk174; unsigned unk178; unsigned unk17c; unsigned unk180; unsigned unk184; unsigned unk188; unsigned unk18c; unsigned unk190; unsigned unk194; unsigned unk198; unsigned unk19c; unsigned unk1a0; unsigned unk1a4; unsigned unk1a8; unsigned unk1ac; unsigned unk1b0; unsigned unk1b4; unsigned unk1b8; unsigned unk1bc; unsigned unk1c0; unsigned unk1c4; unsigned unk1c8; unsigned unk1cc; unsigned unk1d0; unsigned unk1d4; unsigned unk1d8; unsigned unk1dc; unsigned unk1e0; unsigned unk1e4; unsigned unk1e8; unsigned unk1ec; unsigned unk1f0; unsigned unk1f4; unsigned unk1f8; unsigned unk1fc; unsigned unk200; unsigned unk204; unsigned unk208; unsigned unk20c; unsigned unk210; unsigned unk214; unsigned unk218; unsigned unk21c; unsigned unk220; unsigned unk224; unsigned unk228; unsigned unk22c; unsigned unk230; unsigned unk234; unsigned unk238; unsigned unk23c; unsigned unk240;unsigned flags; bool Alternate(){return (flags>>1)&1;} };
extern Mode* DAT_01079858;
void* __cdecl FUN_0089eb90(unsigned); void __cdecl FUN_0089ec10(void*);
struct Owner;
struct FUN_00460ba0 {
 virtual void v0(); virtual void Destroy();
 long refs; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034;
 FUN_00460ba0(unsigned,unsigned,unsigned,unsigned,unsigned,Owner*);
 static void* operator new(unsigned n) throw() {return FUN_0089eb90(n);}
 static void operator delete(void* p) {FUN_0089ec10(p);}
};
struct Smart {
 FUN_00460ba0* ptr;
 void operator=(FUN_00460ba0* value) {
  if(ptr!=value) {
   FUN_00460ba0* old=ptr;
   if(old && !::InterlockedDecrement(&old->refs)) old->Destroy();
   ptr=value;
   if(value) ::InterlockedIncrement(&value->refs);
  }
 }
};
struct Owner {
 unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118;Smart current;
 void FUN_004635f0(); void Animation_SpecialIdleReplace(unsigned,unsigned,unsigned);
};
// pdb: Animation::SpecialIdleReplace | Animation.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Owner::Animation_SpecialIdleReplace(unsigned first,unsigned second,unsigned third) {
 TagScope tag(0x33);
 if(!DAT_01079858->Alternate()) current=new FUN_00460ba0(first,third,0,second,0,this);
 else current=new FUN_00460ba0(first,third,0,second,1,0);
 FUN_004635f0();
}
}

// @f3 0x0047a4e0 (community match, verified in this file)
namespace task1545 {
struct Heap { void* FUN_0086b930(unsigned); }; extern Heap DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned);
struct FUN_006815c0 { float x,y,z; };

struct FUN_0046c350
{
    float red, green, blue, alpha;
    FUN_0046c350();
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void*, unsigned int);
};
struct FUN_00af2240 : NiMemObject
{
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
    FUN_00af2240();
};
struct FUN_0083f750 : NiMemObject
{
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
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    FUN_0083f750(unsigned short, FUN_006815c0*, FUN_0046c350*, void*, unsigned int, unsigned int, bool*);
    void FUN_004236f0(FUN_00af2240*);
};
void FUN_00ade300(FUN_0083f750*, unsigned int, unsigned int);

}
__forceinline void* __cdecl operator new[](unsigned n) { return task1545::DAT_01090a78.FUN_0086b930(n); }
namespace task1545 {
// @fnv 0x004b3890
// pdb: MakeLine | GlobalFunc.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: TES::AddTempDebugObject)
// pdb params: aStart, aStartColor, aEnd, aEndColor, abWithNoLightingProp
FUN_0083f750* __cdecl FUN_0047a4e0(const FUN_006815c0& aStartVertex, const FUN_0046c350& startColor,
                                   const FUN_006815c0& aEndVertex, const FUN_0046c350& endColor, bool addShader)
{
    FUN_006815c0* vertices = new FUN_006815c0[2];
    vertices[0] = aStartVertex;
    vertices[1] = aEndVertex;
    FUN_0046c350* colors = new FUN_0046c350[2];
    colors[0] = startColor;
    colors[1] = endColor;
    // Each flag enables the outgoing segment from the corresponding vertex.
    bool* lines = new bool[2];
    lines[0] = true;
    lines[1] = false;
    // The geometry owns the vertex, color and segment buffers.
    FUN_0083f750* connections = new FUN_0083f750(2, vertices, colors, 0, 0, 0, lines);
    if (addShader)
    {
        FUN_00af2240* shader = new FUN_00af2240;
        connections->FUN_004236f0(shader);
        FUN_00ade300(connections, 0, 0);
    }
    return connections;
}
}

// @f3 0x00475140 (community match, verified in this file)
extern unsigned int DAT_00f4c704;
extern unsigned short DAT_00f4c6ec[12];
namespace f3m_00475140 {

struct Calendar1232 {
    unsigned int month;
    unsigned short day;
};

// pdb: Date::CalculateFullDate | Date.obj | fnv360_0822_retail, objrun, medium
// pdb params: asDate
Calendar1232 __cdecl FUN_00475140(unsigned short value) {
    unsigned short day = value;
    unsigned short month = 1;

    if (day > (unsigned short)DAT_00f4c704)
        day = (unsigned short)(DAT_00f4c704 - 1);

    for (; month < 12; ++month) {
        if (day < DAT_00f4c6ec[month])
            break;
    }

    month = (unsigned short)(month - 1);

    Calendar1232 result;
    result.month = month;
    result.day = (unsigned short)(day - DAT_00f4c6ec[month]);
    return result;
}
}   // namespace f3m_00475140

// @f3 0x0046dc90 (community match, verified in this file)
namespace f3m_0046dc90 {
namespace task1631 {
struct Ref {virtual void Slot0();virtual void Destroy();long refs; void Release(){if(!::InterlockedDecrement(static_cast<volatile long*>(&refs)))Destroy();}};
struct RefPointer { Ref* object; void Reset(){if(object){object->Release();object=0;}} };
struct FUN_0046c770 {
 virtual ~FUN_0046c770();
 int kind,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
 RefPointer first;int unk28;RefPointer second;
 FUN_0046c770();
};
struct FUN_0046dc90: FUN_0046c770 {
 virtual ~FUN_0046dc90();
 FUN_0046dc90();
};
// pdb: BGSPrimitiveSphere::BGSPrimitiveSphere | BGSPrimitive.obj | fnv360_0822_retail, uvref, medium
FUN_0046dc90::FUN_0046dc90(){
 first.Reset();
 second.Reset();
 kind=2;
}
}



}   // namespace f3m_0046dc90

// @f3 0x0046c0f0 (community match, verified in this file)
namespace f3m_0046c0f0 {
namespace Task1644 {
struct FUN_00825800 {FUN_00825800();virtual ~FUN_00825800();int unk04;};
struct Point {float x,y,z;};
struct Pair {unsigned x,y;};
struct Matrix {float elements[9];};
struct FUN_00832f20 {FUN_00832f20();float x,y,z,d;};
struct Planes {FUN_00832f20 planes[6];unsigned mask;Planes():mask(0x3f){}};
struct FUN_0046c0f0:FUN_00825800 {
 Point center;Pair pair;Matrix matrix;unsigned value40;Planes planes;
 Point indexed[4];Point point;
 unsigned char flagE4,flagE5,unkE6,unkE7,unkE8,unkE9,flagEA;
 FUN_0046c0f0(Point&,Pair&,Matrix&);virtual ~FUN_0046c0f0();
};
// pdb: BSOcclusionPlane::BSOcclusionPlane | BGSPrimitive.obj | fnv360_0822_retail, call_seq, high
// pdb params: arCenter, arHalfExtents, arRotation
FUN_0046c0f0::FUN_0046c0f0(Point&a,Pair&b,Matrix&c):center(a),pair(b),matrix(c){flagE4=1;flagE5=1;value40=0;flagEA=1;}
}
}   // namespace f3m_0046c0f0

// @f3 0x0047a320 (community match, verified in this file)
namespace n47a320 {
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
struct ArrayAlloc { static void* operator new[](unsigned size) {return DAT_01090a78.FUN_0086b930(size);} };
void* __cdecl FUN_0089eb90(unsigned);
void __cdecl FUN_0089ec10(void*);
void* __cdecl FUN_0089e810(unsigned int);

struct NiPoint3V : ArrayAlloc
{
    float x;
    float y;
    float z;
    NiPoint3V() {}
};

struct FUN_0046c350 : ArrayAlloc
{
    float r;
    float g;
    float b;
    float a;
    FUN_0046c350();
};

struct NiPoint2
{
    float x;
    float y;
};

struct NiObject
{
    static void* operator new(unsigned int size) {return FUN_0089eb90(size);}
    static void operator delete(void* p, unsigned int) {FUN_0089ec10(p);}
};

struct NiAVObject : NiObject
{
    void FUN_004236f0(NiObject* apProperty);
};

struct FUN_0083f490 : NiAVObject
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
    FUN_0083f490(unsigned short usVertices, NiPoint3V* pkVertex, NiPoint3V* pkNormal, FUN_0046c350* pkColor,
               NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned int eNBTMethod,
               unsigned short usTriangles, unsigned short* pusTriList);
};

struct FUN_00af2240 : NiObject
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
    FUN_00af2240();
};

void __cdecl FUN_00ade300(NiAVObject* apObject, int a, int b);

// Builds a three-vertex FUN_0083f490 from three points and a color, optionally attaching a lighting property and initializing the geometry shader.
// @fnv 0x004b3570
// pdb: MakeTriangle | GlobalFunc.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aPt1, aPt2, aPt3, aColor, abWithNoLightingProp
FUN_0083f490* __cdecl FUN_0047a320(NiPoint3V kP0, NiPoint3V kP1, NiPoint3V kP2, const FUN_0046c350& kColor,
                                 bool bEnableLighting)
{
    NiPoint3V* aPVerts = new NiPoint3V[3];
    aPVerts[0] = kP0;
    aPVerts[1] = kP1;
    aPVerts[2] = kP2;
    FUN_0046c350* pColors2 = new FUN_0046c350[3];
    pColors2[0] = kColor;
    pColors2[1] = kColor;
    pColors2[2] = kColor;
    unsigned short* pTris = (unsigned short*)FUN_0089e810(12);
    pTris[0] = 0;
    pTris[1] = 2;
    pTris[2] = 1;
    pTris[3] = 0;
    pTris[4] = 1;
    pTris[5] = 2;
    FUN_0083f490* pShape_ = new FUN_0083f490(3, aPVerts, 0, pColors2, 0, 0, 0, 2, pTris);
    if (bEnableLighting)
    {
        FUN_00af2240* pProp2 = new FUN_00af2240;
        pShape_->FUN_004236f0(pProp2);
        FUN_00ade300(pShape_, 0, 0);
    }
    return pShape_;
}
}  // namespace fnv_004b3570

// @f3 0x00472af0 (community match, verified in this file)
namespace Reset47 {
extern int DAT_0106e334;
extern void (__stdcall* DAT_00d9b09c)(void*);
extern void (__stdcall* DAT_00d9b0a0)(void*);
struct Parent { void** table; };
struct Object {
    int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;
    Parent* parent;
};
struct Interface { void** table; };
struct Slot { int key; Interface* handle; Object* object; int unk0C; };
struct Manager {void FUN_00ae1a30(Object*);};
struct Queue {void FUN_006f2440(Object*);};
struct Registry {void FUN_00429640(void*,int,int);};
extern Manager* DAT_0116efb8;
extern Queue* DAT_0107a79c;
extern Registry* DAT_0106ca70;
void __cdecl FUN_00478bb0(Object*);
void __cdecl FUN_008d7720(Object*,int,int);
bool __cdecl FUN_00724400();
struct Owner {
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
    Slot slots[2][20];
    void FUN_00471020(Object*);
    void FUN_00472af0();
    __forceinline void ResetSlot(Slot& slot)
    {
        if (slot.object)
        {
            FUN_00471020(slot.object);
            if (!FUN_00724400())
            {
                Object* object=slot.object;
                if (object)
                {
                    FUN_00478bb0(object);
                    DAT_0116efb8->FUN_00ae1a30(object);
                    if (object->parent)
                    {
                        FUN_008d7720(object,1,0);
                        ((void (__thiscall*)(Parent*,Object*))object->parent->table[58])(object->parent,object);
                    }
                }
            }
            else
                DAT_0107a79c->FUN_006f2440(slot.object);
            void* handle=((void* (__thiscall*)(Interface*))slot.handle->table[5])(slot.handle);
            DAT_0106ca70->FUN_00429640(handle,1,1);
            slot.object=0;
        }
        slot.key=0;
        slot.handle=0;
    }
};
// pdb: BipedAnim::RemoveAllParts | BipedAnim.obj | fnv360_0721_beta, call_seq, medium
void Owner::FUN_00472af0()
{
    DAT_00d9b09c(&DAT_0106e334);
    for (int i=0;i<20;++i)
    {
        ResetSlot(slots[0][i]);
        ResetSlot(slots[1][i]);
    }
    DAT_00d9b0a0(&DAT_0106e334);
}
}

// @f3 0x0047f350 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0047f350 {
namespace Slot1Inventory47 {
struct Owner;
struct Temporary {
    int unk00,unk04,unk08;
    Temporary();~Temporary();
    void FUN_00452920(float);
    void FUN_004529e0(unsigned,Owner*);
};
struct Details {void FUN_00456ba0(unsigned,int,Temporary*,int);};
struct Form {
    int unk00;
    unsigned char type;
    unsigned char unk05,unk06,unk07;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    Details details;
};
struct Extra {int unk00,unk04;float health;__forceinline double Health()const{return health;}};
struct Item {int count;Form* form;Extra* extra;};
struct Node {Item* item;Node* next;};
struct Inventory {int unk00;Node head;__forceinline Node* Head(){return &head;}};
struct Reference;
struct Table {
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00C;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01C;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02C;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03C;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04C;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05C;
    void* unk060;
    void* unk064;
    void* unk068;
    void* unk06C;
    void* unk070;
    void* unk074;
    void* unk078;
    void* unk07C;
    void* unk080;
    void* unk084;
    void* unk088;
    void* unk08C;
    void* unk090;
    void* unk094;
    void* unk098;
    void* unk09C;
    void* unk0A0;
    void* unk0A4;
    void* unk0A8;
    void* unk0AC;
    void* unk0B0;
    void* unk0B4;
    void* unk0B8;
    void* unk0BC;
    void* unk0C0;
    void* unk0C4;
    void* unk0C8;
    void* unk0CC;
    void* unk0D0;
    void* unk0D4;
    void* unk0D8;
    void* unk0DC;
    void* unk0E0;
    void* unk0E4;
    void* unk0E8;
    void* unk0EC;
    void* unk0F0;
    void* unk0F4;
    void* unk0F8;
    void* unk0FC;
    bool(__thiscall* isSpecial)(Reference*);
};
struct Reference {
    Table* table;
    Inventory* FUN_004e66c0();
    unsigned short Actor_GetLevel();
    unsigned FUN_004ec070(int);
    __forceinline bool IsSpecial(){return table->isSpecial(this);}
};
struct Owner {
    int unk00;Reference* reference;
    bool FUN_0047f300(unsigned);
    void FUN_0047f350();
};
// pdb: InventoryChanges::InitLeveledItems | InventoryChanges.obj | fnv360_0822_retail, call_gap, medium
void Owner::FUN_0047f350() {
    Inventory* inventory=reference?reference->FUN_004e66c0():0;
    Node* node=inventory->Head();
    unsigned index=0;
    unsigned level;
    if(reference->IsSpecial()) level=reference->Actor_GetLevel();
    else level=reference->FUN_004ec070(1);
    for(;node;node=node->next) {
        if(!node->next && !node->item) break;
        Item* item=node->item;
        Form* form=item->form;
        if(form && form->type==0x34) {
            if(!FUN_0047f300(index)) {
                Temporary temporary;
                form->details.FUN_00456ba0(level,abs(item->count),&temporary,0);
                Extra* extra=item->extra;
                if(extra) {
                    double health=extra->Health();
                    float amount=(float)health;
                    if(amount!=1.0f) {
                        double scale=extra->Health();
                        temporary.FUN_00452920((float)scale);
                    }
                }
                temporary.FUN_004529e0(index,this);
            }
            ++index;
        }
    }
}
}
}   // namespace f3m_0047f350

// @f3 0x0047adc0 (community match, verified in this file)
namespace f3m_0047adc0 {
namespace task1848 {
void* __cdecl FUN_0089eb90(unsigned);
struct FUN_00af2240 { FUN_00af2240(); static void* operator new(unsigned n){return FUN_0089eb90(n);} static void operator delete(void*,unsigned);
unsigned unk00;unsigned unk04;unsigned unk08;unsigned unk0c;unsigned unk10;unsigned unk14;unsigned unk18;unsigned unk1c;unsigned unk20;unsigned unk24;unsigned unk28;unsigned unk2c;unsigned unk30;unsigned unk34;unsigned unk38;unsigned unk3c;unsigned unk40;unsigned unk44;unsigned unk48;unsigned unk4c;unsigned unk50;unsigned unk54;unsigned unk58;unsigned unk5c;unsigned unk60;unsigned unk64;unsigned unk68;unsigned unk6c;unsigned unk70;unsigned unk74;unsigned unk78;unsigned unk7c;
void SetFlag(unsigned flag,bool enabled){unsigned mask=1u<<(flag&31);unsigned* field=flag<32?&unk20:&unk24;bool current=(*field&mask)!=0;if(current!=enabled)unk38=0;if(enabled)*field|=mask;else *field&=~mask;}
};
struct Visual {unsigned unk00,unk04,unk08;float value;};
struct Node;
struct AV {virtual void v0();virtual void v4();virtual void v8();virtual Node* GetNode();virtual void v10();virtual void v14();virtual AV* GetGeometry();
void* FUN_00826590(int);void FUN_004236f0(FUN_00af2240*);void FUN_008268a0();};
struct Node : AV {unsigned unk04;unsigned unk08;unsigned unk0c;unsigned unk10;unsigned unk14;unsigned unk18;unsigned unk1c;Visual* visual;unsigned unk24;unsigned unk28;unsigned unk2c;unsigned unk30;unsigned unk34;unsigned unk38;unsigned unk3c;unsigned unk40;unsigned unk44;unsigned unk48;unsigned unk4c;unsigned unk50;unsigned unk54;unsigned unk58;unsigned unk5c;unsigned unk60;unsigned unk64;unsigned unk68;unsigned unk6c;unsigned unk70;unsigned unk74;unsigned unk78;unsigned unk7c;unsigned unk80;unsigned unk84;unsigned unk88;unsigned unk8c;unsigned unk90;unsigned unk94;unsigned unk98;unsigned unk9c;AV** children;unsigned short capacity,count;
bool IsVisual(){return visual && visual->value!=0.0f;} unsigned Size(){return count;} AV* At(unsigned i){return children[i];}
};
void __cdecl FUN_00ade300(AV*,int,int);
// pdb: PrepareObjectWithNoLightingRecurse | GlobalFunc.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void __cdecl PrepareObjectWithNoLightingRecurse(AV* object){
if(object->GetGeometry() && !object->FUN_00826590(3)) {
FUN_00af2240* prop=new FUN_00af2240;
prop->SetFlag(0x30,true);object->FUN_004236f0(prop);object->FUN_008268a0();FUN_00ade300(object,0,0);
}else{Node* node=object->GetNode();if(node && node->IsVisual())for(unsigned i=0;i<node->Size();i++){AV* child=node->At(i);if(child)PrepareObjectWithNoLightingRecurse(child);}}
}
}
}   // namespace f3m_0047adc0

// @f3 0x00479f20 (community match, verified in this file)
namespace n479f20 {
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
struct ArrayAlloc { static void* operator new[](unsigned size) {return DAT_01090a78.FUN_0086b930(size);} };
void* __cdecl FUN_0089eb90(unsigned);
void __cdecl FUN_0089ec10(void*);
void* __cdecl FUN_0089e810(unsigned int);

struct NiPoint3V : ArrayAlloc
{
    float x;
    float y;
    float z;
    NiPoint3V() {}
};

struct FUN_0046c350 : ArrayAlloc
{
    float r;
    float g;
    float b;
    float a;
    FUN_0046c350();
};

struct NiPoint2
{
    float x;
    float y;
};

struct NiObject
{
    static void* operator new(unsigned int size) {return FUN_0089eb90(size);}
    static void operator delete(void* p, unsigned int) {FUN_0089ec10(p);}
};

struct NiAVObject : NiObject
{
    void FUN_004236f0(NiObject* apProperty);
};

struct FUN_0083f490 : NiAVObject
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
    FUN_0083f490(unsigned short usVertices, NiPoint3V* pkVertex, NiPoint3V* pkNormal, FUN_0046c350* pkColor,
               NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned int eNBTMethod,
               unsigned short usTriangles, unsigned short* pusTriList);
};

struct FUN_00af2240 : NiObject
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
    FUN_00af2240();
};

void __cdecl FUN_00ade300(NiAVObject* apObject, int a, int b);

// @fnv 0x004b2eb0
// pdb: MakeQuadBox | GlobalFunc.obj | fnv360_0822_retail, objrun, medium
// pdb params: aPoint1, aPoint2, aPoint3, aPoint4, aPoint5, aPoint6, aPoint7, aPoint8, aColor, abWithNoLightingProp
FUN_0083f490* FUN_00479f20(const NiPoint3V& aCorner0, const NiPoint3V& aCorner1, const NiPoint3V& aCorner2, const NiPoint3V& aCorner3,
                      const NiPoint3V& aCorner4, const NiPoint3V& aCorner5, const NiPoint3V& aCorner6, const NiPoint3V& aCorner7,
                      const FUN_0046c350& color, bool extra)
{
    NiPoint3V* vertices2 = new NiPoint3V[8];
    vertices2[0] = aCorner0;
    vertices2[1] = aCorner1;
    vertices2[2] = aCorner2;
    vertices2[3] = aCorner3;
    vertices2[4] = aCorner4;
    vertices2[5] = aCorner5;
    vertices2[6] = aCorner6;
    vertices2[7] = aCorner7;
    FUN_0046c350* colors73 = new FUN_0046c350[8];
    colors73[0] = color;
    colors73[1] = color;
    colors73[2] = color;
    colors73[3] = color;
    colors73[4] = color;
    colors73[5] = color;
    colors73[6] = color;
    colors73[7] = color;
    unsigned short* indices21 = (unsigned short*)FUN_0089e810(144);
    indices21[0] = 0;
    indices21[1] = 2;
    indices21[2] = 1;
    indices21[3] = 0;
    indices21[4] = 3;
    indices21[5] = 2;
    indices21[6] = 0;
    indices21[7] = 7;
    indices21[8] = 3;
    indices21[9] = 0;
    indices21[10] = 4;
    indices21[11] = 7;
    indices21[12] = 1;
    indices21[13] = 4;
    indices21[14] = 0;
    indices21[15] = 1;
    indices21[16] = 5;
    indices21[17] = 4;
    indices21[18] = 2;
    indices21[19] = 5;
    indices21[20] = 1;
    indices21[21] = 2;
    indices21[22] = 6;
    indices21[23] = 5;
    indices21[24] = 3;
    indices21[25] = 6;
    indices21[26] = 2;
    indices21[27] = 3;
    indices21[28] = 7;
    indices21[29] = 6;
    indices21[30] = 4;
    indices21[31] = 7;
    indices21[32] = 6;
    indices21[33] = 4;
    indices21[34] = 6;
    indices21[35] = 5;
    indices21[36] = 0;
    indices21[37] = 1;
    indices21[38] = 2;
    indices21[39] = 0;
    indices21[40] = 2;
    indices21[41] = 3;
    indices21[42] = 0;
    indices21[43] = 3;
    indices21[44] = 7;
    indices21[45] = 0;
    indices21[46] = 7;
    indices21[47] = 4;
    indices21[48] = 1;
    indices21[49] = 0;
    indices21[50] = 4;
    indices21[51] = 1;
    indices21[52] = 4;
    indices21[53] = 5;
    indices21[54] = 2;
    indices21[55] = 1;
    indices21[56] = 5;
    indices21[57] = 2;
    indices21[58] = 5;
    indices21[59] = 6;
    indices21[60] = 3;
    indices21[61] = 2;
    indices21[62] = 6;
    indices21[63] = 3;
    indices21[64] = 6;
    indices21[65] = 7;
    indices21[66] = 4;
    indices21[67] = 6;
    indices21[68] = 7;
    indices21[69] = 4;
    indices21[70] = 5;
    indices21[71] = 6;
    FUN_0083f490* mesh1 = new FUN_0083f490(8, vertices2, 0, colors73, 0, 0, 0, 24, indices21);
    if (extra)
    {
        FUN_00af2240* data = new FUN_00af2240;
        mesh1->FUN_004236f0(data);
        FUN_00ade300(mesh1, 0, 0);
    }
    return mesh1;
}

}

// @f3 0x00470060 (community match, verified in this file)
namespace f3m_00470060 {
struct Heap
{
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;

struct Item
{
    ~Item();
    void FUN_0046ffe0();
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Node;

struct Map
{
    int vtbl;
    unsigned int count;
    Node** buckets;

    Node* GetFirstPos() const
    {
        for (unsigned int i = 0; i < count; i++) {
            if (buckets[i])
                return buckets[i];
        }
        return 0;
    }
    void FUN_0089a5d0(Node*& pos, int& key, Item*& value);
    Item* GetNextValue(Node*& pos)
    {
        int key;
        Item* value = 0;
        FUN_0089a5d0(pos, key, value);
        return value;
    }
    void FUN_006bd950();
};

struct Owner
{
    int unk00;
    Map map;
    void FUN_00470060();
};

__forceinline void DeleteAll(Map& map)
{
    Node* pos = map.GetFirstPos();
    while (pos) {
        int key;
        Item* value = 0;
        map.FUN_0089a5d0(pos, key, value);
        Item* item = *(Item* volatile*)&value;
        if (item) {
            item->FUN_0046ffe0();
            DAT_01090a78.FUN_0086ba60(item);
        }
    }
}

// pdb: BGSTextureUseMap::ClearAllTexUseData | BGSTextureUseMap.obj | fnv360_0721_beta, callee_sim, low
void Owner::FUN_00470060()
{
    DeleteAll(map);
    map.FUN_006bd950();
}
}

// @f3 0x0047fee0 (community match, verified in this file)
namespace f3m_0047fee0 {
namespace f3m_0047fee0 {
class ExtraDataList {
public:
    virtual ~ExtraDataList();

    bool FUN_0040c080(int flag);
    short FUN_0040ac80();
    int BaseExtraList_ItemsInList();
    void ExtraDataList_RemoveCount();
};

struct ListNode
{
    ExtraDataList* data;
    ListNode* next;

    void FUN_00421610(ExtraDataList* const* item);
};

struct EntryData
{
    ListNode* extendData;

    int FUN_0047fee0();
};

// pdb: ItemChange::GetAmountNonDefaultExtra | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
int EntryData::FUN_0047fee0()
{
    ListNode* node = extendData;
    int count = 0;
    while (node && node->data) {
        ExtraDataList* item = node->data;
        ExtraDataList* key = item;
        if (!item->FUN_0040c080(0) && item->FUN_0040ac80() > 0)
            count++;
        node = node->next;
        if (item->BaseExtraList_ItemsInList() == 1 && item->FUN_0040ac80() > 1) {
            item->ExtraDataList_RemoveCount();
            extendData->FUN_00421610(&key);
            delete item;
            node = extendData;
            count = 0;
        }
    }
    return count;
}
}
}   // namespace f3m_0047fee0

// @f3 0x0046ff60 (community match, verified in this file)
namespace f3m_0046ff60 {
struct Node46ff60 {
    int unk00;
    int unk04;
};

struct List46ff60 {
    int unk00;
    unsigned int count;
    Node46ff60** items;
    void* First() { for (unsigned int i = 0; i < count; ++i) if (items[i]) return items[i]; return 0; }
    void FUN_0089a5d0(Node46ff60** cur, int* tmp, Node46ff60** out);
};

struct Owner46ff60 {
    int unk00;
    List46ff60 list;
    int FUN_0046ff60();
};

// pdb: BGSTextureUseMap::GetTotalTextureSize | BGSTextureUseMap.obj | fnv360_0822_retail, call_gap, low
int Owner46ff60::FUN_0046ff60()
{
    int sum = 0;
    Node46ff60* cur = (Node46ff60*)list.First();
    while (cur) {
        Node46ff60* out = 0;
        int tmp;
        list.FUN_0089a5d0(&cur, &tmp, &out);
        if (out) sum += out->unk04;
    }
    return sum;
}
}   // namespace f3m_0046ff60

// @f3 0x00460e20 (community match, verified in this file)
extern long DAT_0108ed80;
namespace f3m_00460e20 {
namespace idle20 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Base {
    int refcount;
    virtual ~Base() { InterlockedDecrement(static_cast<volatile long*>(&DAT_0108ed80)); }
};
struct RefA { int unk00; int unk04; int unk08; long count; };
struct PtrA { RefA* p; ~PtrA() { if (p) InterlockedDecrement(static_cast<volatile long*>(&p->count)); } };
struct RefB;
struct TableB { void* unk00; void (__thiscall *destroy)(RefB*); };
struct RefB { TableB* table; long count; };
struct PtrB { RefB* p; ~PtrB() { RefB* v = p; if (v && !InterlockedDecrement(static_cast<volatile long*>(&v->count))) v->table->destroy(v); } };
struct FUN_00424aa0 { int value; ~FUN_00424aa0(); };
void __cdecl FUN_0045fd30(void*);
struct FUN_00460e20 : Base {
    int unk08; int unk0c; PtrA first; int unk14; PtrB second; int unk1c; int unk20;
    FUN_00424aa0 entries[2];
    virtual ~FUN_00460e20();
};
// pdb: AnimIdle::~AnimIdle | Animation.obj | fnv360_0822_retail, call_seq, medium
FUN_00460e20::~FUN_00460e20() { FUN_0045fd30(this); }
}
}   // namespace f3m_00460e20

// @f3 0x0047e090 (community match, verified in this file)
extern __declspec(thread) int DAT_0117c298;
namespace f3m_0047e090 {
struct Heap47e0 {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Heap47e0 DAT_01090a78;
struct Obj47e0;
}
struct FUN_0047df80 {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    static void* operator new(unsigned int size) { return f3m_0047e090::DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { f3m_0047e090::DAT_01090a78.FUN_0086ba60(p); }
    FUN_0047df80(f3m_0047e090::Obj47e0* obj);
};
namespace f3m_0047e090 {
struct ScopedMemoryContext {
    int oldVal;
    ScopedMemoryContext(int newVal) { oldVal = DAT_0117c298; DAT_0117c298 = newVal; }
    ~ScopedMemoryContext() { DAT_0117c298 = oldVal; }
};
struct Link47e0 {
    FUN_0047df80* FUN_0040ab00();
    void FUN_0040b0c0(FUN_0047df80* node);
};
struct Obj47e0 {
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual bool vfc();
    virtual bool v100();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    Link47e0 link;
};
// pdb: InventoryChanges::GetInventoryChanges | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRef
FUN_0047df80* __cdecl FUN_0047e090(Obj47e0* obj)
{
    FUN_0047df80* result = 0;
    if (!obj->vfc() || obj->v100()) {
        result = obj->link.FUN_0040ab00();
        if (!result) {
            ScopedMemoryContext scope(0x36);
            result = new FUN_0047df80(obj);
            obj->link.FUN_0040b0c0(result);
        }
    }
    return result;
}
}

// @f3 0x00461a10 (community match, verified in this file)
namespace f3m_461a10 {
struct Ref461 {
    virtual void vf00();
    virtual void vf04();
    long refCount;
};

struct Global461 {
    void FUN_0086ba60(void* c);
};
extern Global461 DAT_01090a78;

struct Child461 {
    int unk00;
    int unk04;
    int unk08;
    void FUN_004618e0(Ref461** out);
    void FUN_00bf5110();
    ~Child461() { FUN_00bf5110(); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Owner461 {
    int unk00;
    Child461* unk04;
    bool FUN_00461a10(Ref461* p, int unused);
};

// pdb: AnimSequenceMultiple::RemoveSequence | Animation.obj | fnv360_0822_retail, vtable, medium
// pdb params: apSeq, abReleaseModelLoader
bool Owner461::FUN_00461a10(Ref461* p, int unused)
{
    Ref461* q = *(Ref461* volatile*)&p;
    if (::InterlockedDecrement(&q->refCount) == 0) {
        q->vf04();
    }
    unk04->FUN_004618e0(&p);
    if (unk04->unk08 == 0) {
        delete unk04;
        unk04 = 0;
        return true;
    }
    return false;
}
}

// @f3 0x0047bab0 (community match, verified in this file)
#include <windows.h>
#include <string.h>
extern unsigned int DAT_0106e9cc;extern bool DAT_00f4c96c;
namespace f3m_0047bab0 {
namespace Grid2086 {
struct Heap {void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;
struct Cell;
struct Slot {Cell* cell;static void* operator new[](unsigned int n){return DAT_01090a78.FUN_0086b930(n);}};
struct GridBase {virtual void v0();int centerX,centerY;unsigned int dimension;Slot* cells;GridBase();~GridBase();};
struct Point {float x,y,z;Point(){}Point(float a,float b,float c):x(a),y(b),z(c){}};
struct Object;
struct ObjectTable {void* slot00;void (__thiscall* destroy)(Object*);};
struct Object {ObjectTable* vtable;volatile long references;};
struct Ref {
    Object* object;Ref():object(0){}~Ref();
    Ref& operator=(Object* next){
        if(object!=next){
            if(next)::InterlockedIncrement(&next->references);
            Object* old=object;
            if(old && ::InterlockedDecrement(&old->references)==0)old->vtable->destroy(old);
            object=next;
        }
        return *this;
    }
};
struct Grid:GridBase {Point position;bool loaded;unsigned char unk21,unk22,unk23;Ref world;
    virtual void v0();Grid();
};
// pdb: GridCellArray::GridCellArray | GridCell.obj | fnv360_0822_retail, call_gap, low
Grid::Grid(){
    if(DAT_0106e9cc<5)DAT_0106e9cc=5;else if(!(DAT_0106e9cc&1))++DAT_0106e9cc;
    dimension=DAT_0106e9cc;
    cells=new Slot[dimension*dimension];
    memset(cells,0,dimension*dimension*sizeof(Slot));
    position=Point(0.0f,0.0f,0.0f);
    DAT_00f4c96c=true;world=0;loaded=false;
}
}
}   // namespace f3m_0047bab0

// @f3 0x0046a820 (community match, verified in this file)
namespace f3m_0046a820 {
namespace Collector2089 {
struct __declspec(align(16)) Normal {float x,y,z,w;};
struct Entry {
    Normal normal;
    float fraction;int extraInfo;unsigned int unk18,unk1C;
    unsigned int shapeKey0,shapeKey1,shapeKey2,shapeKey3,shapeKey4,shapeKey5,shapeKey6,shapeKey7;
    int keyIndex;unsigned int unk44,unk48,unk4C;
    void* collidable;unsigned int unk54,unk58,unk5C;
    Entry():fraction(1.0f),extraInfo(-1),shapeKey0(0xffffffffu),keyIndex(0),collidable(0){}
};
struct RayBase {virtual ~RayBase(){};virtual void AddRayHit();float earlyOut;RayBase():earlyOut(1.0f){}};
struct InplaceHits {Entry* data;unsigned int count,capacity,unk0C;Entry entries[8];
    __forceinline InplaceHits():data(entries),count(0),capacity(0x80000008u){}
};
struct Collector:RayBase {InplaceHits hits;virtual void AddRayHit();Collector();};
typedef char EntrySize[(sizeof(Entry)==0x60)?1:-1];
// pdb: hkpAllRayHitCollector::hkpAllRayHitCollector | BGSDecalManager.obj | fnv360_0822_retail, call_gap, medium
Collector::Collector(){earlyOut=1.0f;hits.count=0;}
}
}   // namespace f3m_0046a820

// @f3 0x0047ce10 (community match, verified in this file)
namespace f3m_0047ce10 {
struct Object984 {
    virtual ~Object984();
    void BaseExtraList_RemoveAll(bool enabled);
};
struct Node984 { Object984* object00; Node984* next04; };
struct Owner984 { Node984* head00; void FUN_0047ce10(); };
// pdb: BSSimpleList<CasinoData *>::`scalar deleting destructor' | PlayerCharacter.obj | fnv360_0822_debug, call_seq, low, conflict (bridge: TeleportPath::Clear)
void Owner984::FUN_0047ce10() {
    Node984* node = head00;
    while (node && node->object00) {
        Object984* object = node->object00;
        node = node->next04;
        object->BaseExtraList_RemoveAll(true);
        delete object;
    }
}
}   // namespace f3m_0047ce10

// @f3 0x0046d060 (community match, verified in this file)
extern char* FUN_00e207a8;
namespace f3m_0046d060 {
void* __cdecl FUN_0089eb90(unsigned int bytes);
void __cdecl FUN_0089ec10(void* memory);
char* __cdecl FUN_008242a0(const char* str);

namespace f3m_0046d060 {

struct FixedStr {
    char* p;
    FixedStr(const char* s) : p(FUN_008242a0(s)) {}
    ~FixedStr() {
        if (p != FUN_00e207a8) ::InterlockedDecrement((volatile long*)(p - 8));
    }
};

struct FUN_00ad2a40 {
    virtual void unk00();
    virtual void Destroy();
    volatile long refs;
    int u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c, u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88, u8c, u90, u94, u98, u9c, ua0, ua4, ua8, uac, ub0, ub4, ub8, ubc;
    int uc0, uc4, uc8, ucc, ud0, ud4, ud8, udc, ue0;
    FUN_00ad2a40();
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
    void FUN_008245d0(const FixedStr& name);
    void FUN_008268a0();
};

struct SmartPtr {
    FUN_00ad2a40* ptr;
    operator FUN_00ad2a40*() const { return ptr; }
    FUN_00ad2a40* operator->() const { return ptr; }
    void operator=(FUN_00ad2a40* val) {
        FUN_00ad2a40* old = ptr;
        if (old != val) {
            if (old && ::InterlockedDecrement(&old->refs) == 0) {
                old->Destroy();
            }
            ptr = val;
            if (val) {
                ::InterlockedIncrement(&val->refs);
            }
        }
    }
};

struct Owner_0046d060 {
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
    SmartPtr m_obj;
    void FUN_0046d060();
};

// pdb: BGSPrimitiveBox::Build | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
void Owner_0046d060::FUN_0046d060()
{
    if (m_obj == 0) {
        m_obj = new FUN_00ad2a40();
        m_obj->FUN_008245d0(FixedStr((const char*)0xdbf0a0));
        m_obj->FUN_008268a0();
    }
}

}
}   // namespace f3m_0046d060

// @f3 0x0046a9a0 (community match, verified in this file)
extern "C" void _ReadWriteBarrier(void);

namespace intr46a9 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
}

struct RefObj46a9 {
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long refCount;
};

struct RefPtr46a9 {
    RefObj46a9* obj;
    void Reset()
    {
        RefObj46a9* p = obj;
        if (p) {
            if (intr46a9::InterlockedDecrement(&p->refCount) == 0)
                p->DeleteThis();
            obj = 0;
        }
    }
    ~RefPtr46a9()
    {
        RefObj46a9* p = obj;
        if (p && intr46a9::InterlockedDecrement(&p->refCount) == 0)
            p->DeleteThis();
    }
};

extern RefObj46a9* DAT_0106dfbc;

__forceinline void ReleaseVal46a9(RefObj46a9* p)
{
    if (p) {
        if (intr46a9::InterlockedDecrement(&p->refCount) == 0)
            p->DeleteThis();
    }
}

extern "C" void DecalCaster_ClearInstance();

struct FUN_00abb340 { char pad[12]; ~FUN_00abb340(); };
struct FUN_00bd12d0 { char pad[12]; __declspec(nothrow) ~FUN_00bd12d0(); };

struct FUN_0046a9a0 {
    RefPtr46a9 a0;
    int unk04;
    FUN_00abb340 a8;
    FUN_00bd12d0 a14;
    RefPtr46a9 a20;
    RefPtr46a9 a24;
    ~FUN_0046a9a0();
};

// pdb: BGSDecalManager::~BGSDecalManager | BGSDecalManager.obj | fnv360_0822_retail, call_seq, medium
FUN_0046a9a0::~FUN_0046a9a0()
{
    DecalCaster_ClearInstance();
    if (DAT_0106dfbc) {
        ReleaseVal46a9(DAT_0106dfbc);
        DAT_0106dfbc = 0;
    }
    _ReadWriteBarrier();
    a8.~FUN_00abb340();
    a14.~FUN_00bd12d0();
    a20.Reset();
    a24.Reset();
}

// @f3 0x0046fb10 (community match, verified in this file)
namespace f3m_0046fb10 {
struct Heap_fb10 { void* FUN_0086b930(unsigned int size) throw(); };
extern Heap_fb10 DAT_01090a78;
extern void* const DAT_00db84ec[];
struct Entry_fb10 { int a; int b; int unk08, unk0c, unk10; };
extern Entry_fb10 DAT_00f4be24[16];
struct Sing_fb10 {
    const void* vptr;
    char m_buffer[0x104];
    int unk108;
    int unk10C;
    int unk110;
    Sing_fb10* Init() throw() { unk108 = 0; m_buffer[0] = 0; unk10C = 0; unk110 = 0; vptr = DAT_00db84ec; return this; }
    static void* operator new(unsigned int size) throw() { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void*) throw() {}
};
struct Iface_fb10 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(int value);
};
extern Iface_fb10* DAT_0116d6f4;
inline Iface_fb10* Get_fb10()
{
    Iface_fb10*& l = DAT_0116d6f4;
    if (l == 0) {
        void* mem = DAT_01090a78.FUN_0086b930(0x114);
        Sing_fb10* p = mem ? ((Sing_fb10*)mem)->Init() : 0;
        l = (Iface_fb10*)p;
        DAT_0116d6f4 = l;
    }
    return l;
}
// pdb: BGSSceneInfo::ReloadBudgetCaps | BGSSceneInfo.obj | fnv360_0721_beta, call_seq, medium
void __cdecl FUN_0046fb10()
{
    for (int* p = &DAT_00f4be24[0].b; (int)p < (int)&DAT_00f4be24[16].b; p += 5) {
        Get_fb10()->v14(p[-1]);
        Get_fb10()->v14(p[0]);
    }
}
}

// @f3 0x004724d0 (community match, verified in this file)
#include <windows.h>
namespace task2064 {
struct Owner;struct Actor;struct Animation {void FUN_0045e4c0(int,bool);};
struct Process {
virtual void slot000();
virtual void slot004();
virtual void slot008();
virtual void slot00c();
virtual void slot010();
virtual void slot014();
virtual void slot018();
virtual void slot01c();
virtual void slot020();
virtual void slot024();
virtual void slot028();
virtual void slot02c();
virtual void slot030();
virtual void slot034();
virtual void slot038();
virtual void slot03c();
virtual void slot040();
virtual void slot044();
virtual void slot048();
virtual void slot04c();
virtual void slot050();
virtual void slot054();
virtual void slot058();
virtual void slot05c();
virtual void slot060();
virtual void slot064();
virtual void slot068();
virtual void slot06c();
virtual void slot070();
virtual void slot074();
virtual void slot078();
virtual void slot07c();
virtual void slot080();
virtual void slot084();
virtual void slot088();
virtual void slot08c();
virtual void slot090();
virtual void slot094();
virtual void slot098();
virtual void slot09c();
virtual void slot0a0();
virtual void slot0a4();
virtual void slot0a8();
virtual void slot0ac();
virtual void slot0b0();
virtual void slot0b4();
virtual void slot0b8();
virtual void slot0bc();
virtual void slot0c0();
virtual void slot0c4();
virtual void slot0c8();
virtual void slot0cc();
virtual void slot0d0();
virtual void slot0d4();
virtual void slot0d8();
virtual void slot0dc();
virtual void slot0e0();
virtual void slot0e4();
virtual void slot0e8();
virtual void slot0ec();
virtual void slot0f0();
virtual void slot0f4();
virtual void slot0f8();
virtual void slot0fc();
virtual void slot100();
virtual void slot104();
virtual void slot108();
virtual void slot10c();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11c();
virtual void slot120();
virtual void slot124();
virtual void slot128();
virtual void slot12c();
virtual void slot130();
virtual void slot134();
virtual void slot138();
virtual void slot13c();
virtual void slot140();
virtual void slot144();
virtual void slot148();
virtual void slot14c();
virtual void slot150();
virtual void slot154();
virtual void slot158();
virtual void slot15c();
virtual void slot160();
virtual void slot164();
virtual void slot168();
virtual void slot16c();
virtual void slot170();
virtual void slot174();
virtual void slot178();
virtual void slot17c();
virtual void slot180();
virtual void slot184();
virtual void slot188();
virtual void slot18c();
virtual void slot190();
virtual void slot194();
virtual void slot198();
virtual void slot19c();
virtual void slot1a0();
virtual void slot1a4();
virtual void slot1a8();
virtual void slot1ac();
virtual void slot1b0();
virtual void slot1b4();
virtual void slot1b8();
virtual void slot1bc();
virtual void slot1c0();
virtual void slot1c4();
virtual void UpdateWeaponDrawn(bool,Owner*,Animation*,Actor*);
};
struct Form {
virtual void slot000();
virtual void slot004();
virtual void slot008();
virtual void slot00c();
virtual void slot010();
virtual void slot014();
virtual void slot018();
virtual void slot01c();
virtual void slot020();
virtual void slot024();
virtual void slot028();
virtual void slot02c();
virtual void slot030();
virtual void slot034();
virtual void slot038();
virtual void slot03c();
virtual void slot040();
virtual void slot044();
virtual void slot048();
virtual void slot04c();
virtual void slot050();
virtual void slot054();
virtual void slot058();
virtual void slot05c();
virtual void slot060();
virtual void slot064();
virtual void slot068();
virtual void slot06c();
virtual void slot070();
virtual void slot074();
virtual void slot078();
virtual void slot07c();
virtual void slot080();
virtual void slot084();
virtual void slot088();
virtual void slot08c();
virtual void slot090();
virtual void slot094();
virtual void slot098();
virtual void slot09c();
virtual void slot0a0();
virtual void slot0a4();
virtual void slot0a8();
virtual void slot0ac();
virtual void slot0b0();
virtual void slot0b4();
virtual void slot0b8();
virtual void slot0bc();
virtual void slot0c0();
virtual void slot0c4();
virtual void slot0c8();
virtual void slot0cc();
virtual void slot0d0();
virtual void slot0d4();
virtual void slot0d8();
virtual void slot0dc();
virtual void slot0e0();
virtual void slot0e4();
virtual void slot0e8();
virtual void slot0ec();
virtual void slot0f0();
virtual void slot0f4();
virtual void slot0f8();
virtual void slot0fc();
virtual void slot100();
virtual void slot104();
virtual void slot108();
virtual void slot10c();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11c();
virtual void slot120();
virtual void slot124();
virtual void slot128();
virtual void slot12c();
virtual const char* GetEditorID();
unsigned char type;unsigned char unk05;unsigned short unk06;unsigned int unk08;unsigned int id;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned char flags;
unsigned char GetFormType(){return type;}unsigned int GetFormID(){return id;}bool IsFlagSet(){return flags&0x10;}
};
struct String {char* text;unsigned short length,capacity;String():text(0),length(0),capacity(0){}void FUN_00401b10();~String(){FUN_00401b10();}operator const char*(){return text;}};
extern char* DAT_00e207a8;
struct FUN_00422920 {char* text;FUN_00422920(const char*);~FUN_00422920(){if(text!=DAT_00e207a8)::InterlockedDecrement((volatile long*)(text-8));}};
struct Node {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int flags;void FUN_008245d0(const FUN_00422920&);void SetCulled(bool b){if(b)flags|=1;else flags&=~1;}
};
struct Actor {
virtual void slot000();
virtual void slot004();
virtual void slot008();
virtual void slot00c();
virtual void slot010();
virtual void slot014();
virtual void slot018();
virtual void slot01c();
virtual void slot020();
virtual void slot024();
virtual void slot028();
virtual void slot02c();
virtual void slot030();
virtual void slot034();
virtual void slot038();
virtual void slot03c();
virtual void slot040();
virtual void slot044();
virtual void slot048();
virtual void slot04c();
virtual void slot050();
virtual void slot054();
virtual void slot058();
virtual void slot05c();
virtual void slot060();
virtual void slot064();
virtual void slot068();
virtual void slot06c();
virtual void slot070();
virtual void slot074();
virtual void slot078();
virtual void slot07c();
virtual void slot080();
virtual void slot084();
virtual void slot088();
virtual void slot08c();
virtual void slot090();
virtual void slot094();
virtual void slot098();
virtual void slot09c();
virtual void slot0a0();
virtual void slot0a4();
virtual void slot0a8();
virtual void slot0ac();
virtual void slot0b0();
virtual void slot0b4();
virtual void slot0b8();
virtual void slot0bc();
virtual void slot0c0();
virtual void slot0c4();
virtual void slot0c8();
virtual void slot0cc();
virtual void slot0d0();
virtual void slot0d4();
virtual void slot0d8();
virtual void slot0dc();
virtual void slot0e0();
virtual void slot0e4();
virtual void slot0e8();
virtual void slot0ec();
virtual void slot0f0();
virtual void slot0f4();
virtual void slot0f8();
virtual void slot0fc();
virtual bool IsActor();unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
Process* process;Process* GetProcess(){return process;}void FUN_00701ab0(bool);Animation* Actor_GetAnimation();bool FUN_006f6c70();
bool FUN_0076cd40(Owner*);Node* FUN_0076ff40(bool);Owner* FUN_0076cd20(bool);Animation* FUN_0076cce0(bool);
};
struct LoadState {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
unsigned int unk164;
unsigned int unk168;
unsigned int unk16c;
unsigned int unk170;
unsigned int unk174;
unsigned int unk178;
unsigned int unk17c;
unsigned int unk180;
unsigned int unk184;
unsigned int unk188;
unsigned int unk18c;
unsigned int unk190;
unsigned int unk194;
unsigned int unk198;
unsigned int unk19c;
unsigned int unk1a0;
unsigned int unk1a4;
unsigned int unk1a8;
unsigned int unk1ac;
unsigned int unk1b0;
unsigned int unk1b4;
unsigned int unk1b8;
unsigned int unk1bc;
unsigned int unk1c0;
unsigned int unk1c4;
unsigned int unk1c8;
unsigned int unk1cc;
unsigned int unk1d0;
unsigned int unk1d4;
unsigned int unk1d8;
unsigned int unk1dc;
unsigned int unk1e0;
unsigned int unk1e4;
unsigned int unk1e8;
unsigned int unk1ec;
unsigned int unk1f0;
unsigned int unk1f4;
unsigned int unk1f8;
unsigned int unk1fc;
unsigned int unk200;
unsigned int unk204;
unsigned int unk208;
unsigned int unk20c;
unsigned int unk210;
unsigned int unk214;
unsigned int unk218;
unsigned int unk21c;
unsigned int unk220;
unsigned int unk224;
unsigned int unk228;
unsigned int unk22c;
unsigned int unk230;
unsigned int unk234;
unsigned int unk238;
unsigned int unk23c;
unsigned int unk240;
unsigned int unk244;
unsigned int unk248;
unsigned int unk24c;
unsigned int unk250;
unsigned int unk254;
unsigned int unk258;
unsigned int unk25c;
unsigned int unk260;
unsigned int unk264;
unsigned int unk268;
unsigned int unk26c;
unsigned int unk270;
unsigned int unk274;
unsigned int unk278;
unsigned int unk27c;
unsigned int unk280;
unsigned int unk284;
unsigned int unk288;
unsigned int unk28c;
unsigned int unk290;
unsigned int unk294;
unsigned int unk298;
unsigned int unk29c;
unsigned int unk2a0;
unsigned int unk2a4;
unsigned int unk2a8;
unsigned int unk2ac;
unsigned int unk2b0;
unsigned int unk2b4;
unsigned int unk2b8;
unsigned int unk2bc;
unsigned int unk2c0;
unsigned int unk2c4;
unsigned int unk2c8;
unsigned int unk2cc;
unsigned int unk2d0;
unsigned int unk2d4;
unsigned int unk2d8;
unsigned int unk2dc;
unsigned int unk2e0;
unsigned int unk2e4;
unsigned int unk2e8;
unsigned int unk2ec;
unsigned int unk2f0;
unsigned int unk2f4;
unsigned int unk2f8;
unsigned int unk2fc;
unsigned int unk300;
unsigned int unk304;
unsigned int unk308;
unsigned int unk30c;
unsigned int unk310;
unsigned int unk314;
unsigned int unk318;
unsigned int unk31c;
unsigned int unk320;
unsigned int unk324;
unsigned int unk328;
unsigned int unk32c;
unsigned int unk330;
unsigned int unk334;
unsigned int unk338;
unsigned int unk33c;
unsigned int unk340;
unsigned int unk344;
unsigned int unk348;
unsigned int unk34c;
unsigned int unk350;
unsigned int unk354;
unsigned int unk358;
unsigned int unk35c;
unsigned int unk360;
unsigned int unk364;
unsigned int unk368;
unsigned int unk36c;
unsigned int unk370;
unsigned int unk374;
unsigned int unk378;
unsigned int unk37c;
unsigned int unk380;
unsigned int unk384;
unsigned int unk388;
unsigned int unk38c;
unsigned int unk390;
unsigned int unk394;
unsigned int unk398;
unsigned int unk39c;
unsigned int unk3a0;
unsigned int unk3a4;
unsigned int unk3a8;
unsigned int unk3ac;
unsigned int unk3b0;
unsigned int unk3b4;
unsigned int unk3b8;
unsigned int unk3bc;
unsigned int unk3c0;
unsigned int unk3c4;
unsigned int unk3c8;
unsigned int unk3cc;
unsigned int unk3d0;
unsigned int unk3d4;
unsigned int unk3d8;
unsigned int unk3dc;
unsigned int unk3e0;
unsigned int unk3e4;
unsigned int unk3e8;
unsigned int unk3ec;
unsigned int unk3f0;
unsigned int unk3f4;
unsigned int unk3f8;
unsigned int unk3fc;
unsigned int unk400;
unsigned int unk404;
unsigned int unk408;
unsigned int unk40c;
unsigned int unk410;
unsigned int unk414;
unsigned int unk418;
unsigned int unk41c;
unsigned int unk420;
unsigned int unk424;
unsigned int unk428;
unsigned int unk42c;
unsigned int unk430;
unsigned int unk434;
unsigned int unk438;
unsigned int unk43c;
unsigned int unk440;
unsigned int unk444;
unsigned int unk448;
unsigned int unk44c;
unsigned int unk450;
unsigned int unk454;
unsigned int unk458;
unsigned int unk45c;
unsigned int unk460;
unsigned int unk464;
unsigned int unk468;
unsigned int unk46c;
unsigned int unk470;
unsigned int unk474;
unsigned int unk478;
unsigned int unk47c;
unsigned int unk480;
unsigned int unk484;
unsigned int unk488;
unsigned int unk48c;
unsigned int unk490;
unsigned int unk494;
unsigned int unk498;
unsigned int unk49c;
unsigned int unk4a0;
unsigned int unk4a4;
unsigned int unk4a8;
unsigned int unk4ac;
unsigned int unk4b0;
unsigned int unk4b4;
unsigned int unk4b8;
unsigned int unk4bc;
unsigned int unk4c0;
unsigned int unk4c4;
unsigned int unk4c8;
unsigned int unk4cc;
unsigned int unk4d0;
unsigned int unk4d4;
unsigned int unk4d8;
unsigned int unk4dc;
unsigned int unk4e0;
unsigned int unk4e4;
unsigned int unk4e8;
unsigned int unk4ec;
unsigned int unk4f0;
unsigned int unk4f4;
unsigned int unk4f8;
unsigned int unk4fc;
unsigned int unk500;
unsigned int unk504;
unsigned int unk508;
unsigned int unk50c;
unsigned int unk510;
unsigned int unk514;
unsigned int unk518;
unsigned int unk51c;
unsigned int unk520;
unsigned int unk524;
unsigned int unk528;
unsigned int unk52c;
unsigned int unk530;
unsigned int unk534;
unsigned int unk538;
unsigned int unk53c;
unsigned int unk540;
unsigned int unk544;
unsigned int unk548;
unsigned int unk54c;
unsigned int unk550;
unsigned int unk554;
unsigned int unk558;
unsigned int unk55c;
unsigned int unk560;
unsigned int unk564;
unsigned int unk568;
unsigned int unk56c;
unsigned int unk570;
unsigned int unk574;
unsigned int unk578;
unsigned int unk57c;
unsigned int unk580;
unsigned int unk584;
unsigned int unk588;
unsigned int unk58c;
unsigned int unk590;
unsigned int unk594;
unsigned int unk598;
unsigned int unk59c;
unsigned int unk5a0;
unsigned int unk5a4;
unsigned char unk5a8;bool loading;};
struct State {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
unsigned int unk164;
unsigned int unk168;
unsigned int unk16c;
unsigned int unk170;
unsigned int unk174;
unsigned int unk178;
unsigned int unk17c;
unsigned int unk180;
unsigned int unk184;
unsigned int unk188;
unsigned int unk18c;
unsigned int unk190;
unsigned int unk194;
unsigned int unk198;
unsigned int unk19c;
unsigned int unk1a0;
unsigned int unk1a4;
unsigned int unk1a8;
unsigned int unk1ac;
unsigned int unk1b0;
unsigned int unk1b4;
unsigned int unk1b8;
unsigned int unk1bc;
unsigned int unk1c0;
unsigned int unk1c4;
unsigned int unk1c8;
unsigned int unk1cc;
unsigned int unk1d0;
unsigned int unk1d4;
unsigned int unk1d8;
unsigned int unk1dc;
unsigned int unk1e0;
unsigned int unk1e4;
unsigned int unk1e8;
unsigned int unk1ec;
unsigned int unk1f0;
unsigned int unk1f4;
unsigned int unk1f8;
unsigned int unk1fc;
unsigned int unk200;
unsigned int unk204;
unsigned int unk208;
unsigned int unk20c;
unsigned int unk210;
unsigned int unk214;
unsigned int unk218;
unsigned int unk21c;
unsigned int unk220;
unsigned int unk224;
unsigned int unk228;
unsigned int unk22c;
unsigned int unk230;
unsigned int unk234;
unsigned int unk238;
unsigned int unk23c;
unsigned int unk240;
unsigned int flags;bool Blocked(){return (flags>>1)&1;}};
extern LoadState* DAT_0106cdcc;extern State* DAT_01079858;extern Actor* DAT_0107a104;extern const char* DAT_00f4c394;
extern const char DAT_00dbfeb4[];
void FUN_00403a00(String*,const char*,...);
Node* FUN_00471ef0(Form*,void*,int,Actor*,Node*);
struct Owner {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
Form* parent;void* model;Node* scene;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
Node* other;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
unsigned int unk164;
unsigned int unk168;
unsigned int unk16c;
unsigned int unk170;
unsigned int unk174;
unsigned int unk178;
unsigned int unk17c;
unsigned int unk180;
unsigned int unk184;
unsigned int unk188;
unsigned int unk18c;
unsigned int unk190;
unsigned int unk194;
unsigned int unk198;
unsigned int unk19c;
unsigned int unk1a0;
unsigned int unk1a4;
unsigned int unk1a8;
unsigned int unk1ac;
unsigned int unk1b0;
unsigned int unk1b4;
unsigned int unk1b8;
unsigned int unk1bc;
unsigned int unk1c0;
unsigned int unk1c4;
unsigned int unk1c8;
unsigned int unk1cc;
unsigned int unk1d0;
unsigned int unk1d4;
unsigned int unk1d8;
unsigned int unk1dc;
unsigned int unk1e0;
unsigned int unk1e4;
unsigned int unk1e8;
unsigned int unk1ec;
unsigned int unk1f0;
unsigned int unk1f4;
unsigned int unk1f8;
unsigned int unk1fc;
unsigned int unk200;
unsigned int unk204;
unsigned int unk208;
unsigned int unk20c;
unsigned int unk210;
unsigned int unk214;
unsigned int unk218;
unsigned int unk21c;
unsigned int unk220;
unsigned int unk224;
unsigned int unk228;
unsigned int unk22c;
unsigned int unk230;
unsigned int unk234;
unsigned int unk238;
unsigned int unk23c;
unsigned int unk240;
unsigned int unk244;
unsigned int unk248;
unsigned int unk24c;
unsigned int unk250;
unsigned int unk254;
unsigned int unk258;
unsigned int unk25c;
unsigned int unk260;
unsigned int unk264;
unsigned int unk268;
unsigned int unk26c;
unsigned int unk270;
unsigned int unk274;
unsigned int unk278;
unsigned int unk27c;
unsigned int unk280;
unsigned int unk284;
unsigned int unk288;
unsigned int unk28c;
unsigned int unk290;
unsigned int unk294;
unsigned int unk298;
unsigned int unk29c;
unsigned int unk2a0;
unsigned int unk2a4;
unsigned int unk2a8;
unsigned int unk2ac;
Actor* actor;void FUN_00472220(Form*);void FUN_004724d0(Form*);
};
// pdb: BipedAnim::AttachBipedWeapon | BipedAnim.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apWeapon, iModSlots
void Owner::FUN_004724d0(Form* weapon){
if(!weapon || (int)weapon->GetFormType()!=0x28 || (weapon==parent && scene))return;
FUN_00472220(weapon);
int slot=5;
if(actor==DAT_0107a104)scene=FUN_00471ef0(parent,model,slot,actor,DAT_0107a104->FUN_0076ff40(DAT_0107a104->FUN_0076cd40(this)));
else scene=FUN_00471ef0(parent,model,slot,actor,0);
if(!scene)return;
String str;
FUN_00403a00(&str,DAT_00dbfeb4,DAT_00f4c394,parent->GetEditorID(),parent->GetFormID());
scene->FUN_008245d0(FUN_00422920((const char*)str));
if(weapon->IsFlagSet() && other)other->SetCulled(true);
if(actor->IsActor()){
Actor* a=actor;Process* proc=a->GetProcess();
if(proc && !DAT_0106cdcc->loading && this!=DAT_0107a104->FUN_0076cd20(true))a->FUN_00701ab0(true);
if(proc && !DAT_01079858->Blocked()){
Animation* anim=0;
if(actor==DAT_0107a104 && this==DAT_0107a104->FUN_0076cd20(true))anim=DAT_0107a104->FUN_0076cce0(true);
else anim=a->Actor_GetAnimation();
if(anim)anim->FUN_0045e4c0(4,false);
if(actor==DAT_0107a104 && this==DAT_0107a104->FUN_0076cd20(true))a->GetProcess()->UpdateWeaponDrawn(a->FUN_006f6c70(),this,DAT_0107a104->FUN_0076cce0(true),a);
else a->GetProcess()->UpdateWeaponDrawn(a->FUN_006f6c70(),this,a->Actor_GetAnimation(),a);
}}
}
}

// @f3 0x004609a0 (community match, verified in this file)
namespace f3m_004609a0 {
namespace n4609a0 {
class Obj {
public:
    virtual ~Obj();
    virtual void DeleteThis();
    long refs;
    int pad08[3];
    int type;
    void* item;
    void IncRefCount() { ::InterlockedIncrement((volatile long*)&refs); }
    void DecRefCount() { if (::InterlockedDecrement((volatile long*)&refs) == 0) DeleteThis(); }
    int Slot() const
    {
        int s = type;
        switch (s)
        {
        case 0x14: s = 1; break;
        case 0x15: s = 4; break;
        }
        return s;
    }
};
struct Ptr {
    Obj* m_pObject;
    operator Obj*() const { return m_pObject; }
    Obj* operator->() const { return m_pObject; }
    Ptr& operator=(Obj* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    Ptr& operator=(const Ptr& p)
    {
        if (m_pObject != p.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct Holder {
    char pad00[0xcd];
    bool fcd;
    char padce[0xe0 - 0xce];
    void* slots[14];
    Ptr cur;
    Ptr next;
    Ptr extra[2];
    void FUN_0045feb0(Ptr* p);
    __forceinline void Clear(Obj* o)
    {
        int s = o->Slot();
        void* it = o->item;
        if (it && slots[s] == it)
            slots[s] = 0;
    }
    void FUN_004609a0();
};
// pdb: Animation::ShutdownAllAnimIdles | Animation.obj | fnv360_0822_retail, call_gap, low
void Holder::FUN_004609a0()
{
    fcd = true;
    if (cur)
    {
        Clear(cur);
        FUN_0045feb0(&cur);
    }
    if (next)
    {
        Clear(next);
        FUN_0045feb0(&next);
    }
    else
    {
        cur = next;
        next = 0;
    }
    for (int i = 0; i < 2; i++)
    {
        if (extra[i])
        {
            FUN_0045feb0(&extra[i]);
            extra[i] = 0;
        }
    }
}
}
}   // namespace f3m_004609a0

// @f3 0x00472220 (community match, verified in this file)
namespace f3m_00472220 {

struct Scene;
struct Model {
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual const char* GetPath();
};
struct Entry {
    void* key;
    Model* model;
    Scene* scene;
    int unk0C;
};
struct Mgr { void FUN_006f2440(Scene* s); };
struct Loader { void FUN_00429640(const char* path, bool a, bool b); };
struct Lookup { void* FUN_0076cd20(int a); };

struct Form472220 {
    int unk00;
    unsigned char type04;
    char pad05[0x1f7];
    void* unk1FC;
};

extern Mgr* DAT_0107a79c;
extern Loader* DAT_0106ca70;
extern Lookup* DAT_0107a104;
bool __cdecl FUN_00724400();
void __cdecl FUN_00470770(Scene* s);

struct Actor472220 {
    char pad00[0x7c];
    Form472220* unk7C;
    Model* unk80;
    Scene* unk84;
    void FUN_00471020(Scene* s);
    void FUN_00472220(Form472220* form);
};

// pdb: BipedAnim::SetBipedWeapon | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: apWeapon, iModSlots
void Actor472220::FUN_00472220(Form472220* form)
{
    if (!form || form->type04 != 0x28)
        return;
    if (form == unk7C && unk84)
        return;
    if (unk84) {
        FUN_00471020(unk84);
        if (!FUN_00724400())
            FUN_00470770(unk84);
        else
            DAT_0107a79c->FUN_006f2440(unk84);
        const char* path = unk80->GetPath();
        DAT_0106ca70->FUN_00429640(path, true, true);
        unk84 = 0;
    }
    Entry* e = (Entry*)&unk7C;
    e->key = 0;
    e->model = 0;
    Model* model = (Model*)((char*)form + 0x3c);
    if ((this == (Actor472220*)DAT_0107a104->FUN_0076cd20(1) ||
         this == (Actor472220*)DAT_0107a104->FUN_0076cd20(0)) &&
        form->unk1FC)
        model = (Model*)((char*)form->unk1FC + 0x30);
    unk80 = model;
    unk7C = form;
}

}

// @f3 0x0047b860 (community match, verified in this file)
extern __declspec(thread) unsigned allocationTag;
namespace f3m_0047b860 {
namespace f3m_0047b860 {
struct TagScope {
    unsigned old;
    TagScope(unsigned tag) { old = allocationTag; allocationTag = tag; }
    ~TagScope() { allocationTag = old; }
};

struct Obj47b860B { void FUN_004cfe50(); };
struct Cell47b860 {
    Obj47b860B* TESObjectCELL_GetLand();
    void FUN_004dc950();
};

struct Grid47b860 {
    int unk00;
    int unk04;
    int unk08;
    unsigned int dim;
    Cell47b860** cells;
    int unk14;
    int unk18;
    int unk1c;
    bool done;
    Cell47b860** GetAt(unsigned int x, unsigned int y)
    {
        if (x < dim && y < dim)
            return &cells[dim * x + y];
        return 0;
    }
    void FUN_0047b860();
};

// pdb: GridCellArray::AttachAllLand3D | GridCell.obj | fnv360_0822_retail, call_gap, low
void Grid47b860::FUN_0047b860()
{
    if (done)
        return;
    TagScope scope(0x1b);
    unsigned int n = dim;
    for (unsigned int x = 0; x < n; ++x) {
        for (unsigned int y = 0; y < n; ++y) {
            Cell47b860** p = GetAt(x, y);
            if (p && *p) {
                (*p)->TESObjectCELL_GetLand()->FUN_004cfe50();
                (*p)->FUN_004dc950();
            }
        }
    }
    done = true;
}
}
}   // namespace f3m_0047b860

// @f3 0x0047dd50 (community match, verified in this file)
namespace n47dd50 {
struct Rec { int m0; char m4; char m5[4]; };
struct Form {
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
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* V130();
};
struct Buf {
    char pad[0x14];
    char* m14;
    char pad18[0x70];
    Rec* m88;
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void FUN_006db460(const void* p, unsigned int n);
    void FUN_006defa0(const void* p, unsigned int n);
};
extern Buf* DAT_01079ca4;
extern bool DAT_01079d20;
extern char DAT_00dc0bd0[];
extern char DAT_00db5d40[];
Form* __cdecl TESForm_GetFormByNumericID(int id);
void __cdecl FUN_00c24b70(const char* fmt, ...);
struct Item { void FUN_00412920(int a, int b); };
struct Node { Item* m0; Node* m4; };
struct Owner { char pad[0xc]; int mc; };
struct Self {
    Node* m0;
    int m4;
    Owner* m8;
    void FUN_0047dd50();
};
// pdb: ItemChange::SaveGame | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
void Self::FUN_0047dd50()
{
    short size = 0;
    char* start = DAT_01079ca4->m14;
    char* sizePos = 0;
    if (DAT_01079ca4->TESSaveLoadGame_UseSaveGameBlocks())
    {
        int tag = 0x424c4f4b;
        DAT_01079ca4->FUN_006db460(&tag, 4);
        sizePos = DAT_01079ca4->m14;
        DAT_01079ca4->FUN_006db460(&size, 2);
    }
    int id = m8->mc;
    DAT_01079ca4->FUN_006defa0(&id, 4);
    DAT_01079ca4->FUN_006db460(&m4, 4);
    int count = 0;
    int* countPos = (int*)DAT_01079ca4->m14;
    DAT_01079ca4->FUN_006db460(&count, 4);
    for (Node* n = m0; n && (n->m4 || n->m0); n = n->m4)
    {
        n->m0->FUN_00412920(0, 0);
        count++;
    }
    *countPos = count;
    if (DAT_01079d20)
    {
        Rec* r = DAT_01079ca4->m88;
        char* cur = DAT_01079ca4->m14;
        if (r)
        {
            Form* f = TESForm_GetFormByNumericID(r->m0);
            FUN_00c24b70(DAT_00db5d40, cur - start, r->m0, f->V130(), *(int*)r->m5, 0x54f, DAT_00dc0bd0);
        }
    }
    if (DAT_01079ca4->TESSaveLoadGame_UseSaveGameBlocks())
        *(short*)sizePos = (short)(DAT_01079ca4->m14 - sizePos);
}
}

// @f3 0x00460090 (community match, verified in this file)
namespace f3m_00460090 {
extern "C" void FUN_00e7cd40(const char* format, ...);

namespace N460090 {

struct NiControllerSequence460090
{
    int unk00;
    int unk04;
    const char* m_kName; // +0x08
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
    int m_eState; // +0x44
    const char* GetName() { return m_kName; }
    int GetState() { return m_eState; }
};

} // namespace N460090

class AnimIdle
{
  public:
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount; // +0x04
    int unk08;
    int unk0c;
    int unk10;
    int section; // +0x14
    N460090::NiControllerSequence460090* sequence; // +0x18

    void IncRefCount() { ::InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!::InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
    int GetSection() { return section; }
    N460090::NiControllerSequence460090* GetControllerSequence() { return sequence; }
};

namespace N460090 {

struct Animation
{
    int unk000[0x38];
    NiControllerSequence460090* m_pChildTile[8]; // +0xE0
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    NiPointer<AnimIdle> LocalInput;      // +0x118
    NiPointer<AnimIdle> LocalStateValue; // +0x11C
    NiPointer<AnimIdle> LocalOutput[2];  // +0x120

    void BlendOut(int section, bool immediate);
    void AssignControllerManager(NiPointer<AnimIdle>& idle);
    void FUN_00460090(bool abFreeQueued, bool abForceDelete);
};

// pdb: Animation::SpecialIdleFree | Animation.obj | fnv360_0822_retail, ustr, medium
// pdb params: abFreeQueued, abForceDelete
void Animation::FUN_00460090(bool abFreeQueued, bool abForceDelete)
{
    if (LocalInput)
    {
        int esection = LocalInput->GetSection();
        switch (esection)
        {
        case 0x15:
            esection = 4;
            break;
        case 0x14:
            esection = 1;
            break;
        }
        if (LocalInput->GetControllerSequence() && m_pChildTile[esection] == LocalInput->GetControllerSequence())
        {
            if (abForceDelete)
            {
                m_pChildTile[esection] = 0;
            }
            else
            {
                switch (LocalInput->GetControllerSequence()->GetState())
                {
                case 2:
                case 5:
                    FUN_00e7cd40("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                                 LocalInput->GetControllerSequence()->GetName());
                    return;
                }
                BlendOut(LocalInput->GetSection(), false);
            }
        }
        if (!abForceDelete && !LocalOutput[0])
        {
            LocalOutput[0] = LocalInput;
            LocalInput = 0;
        }
        else if (!abForceDelete && !LocalOutput[1])
        {
            LocalOutput[1] = LocalInput;
            LocalInput = 0;
        }
        else
        {
            AssignControllerManager(LocalInput);
        }
    }
    if (abFreeQueued && LocalStateValue)
    {
        int esection = LocalStateValue->GetSection();
        switch (esection)
        {
        case 0x15:
            esection = 4;
            break;
        case 0x14:
            esection = 1;
            break;
        }
        if (LocalStateValue->GetControllerSequence() &&
            m_pChildTile[esection] == LocalStateValue->GetControllerSequence())
        {
            if (abForceDelete)
            {
                m_pChildTile[esection] = 0;
            }
            else
            {
                switch (LocalStateValue->GetControllerSequence()->GetState())
                {
                case 2:
                case 5:
                    FUN_00e7cd40("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                                 LocalStateValue->GetControllerSequence()->GetName());
                    return;
                }
                BlendOut(esection, false);
            }
        }
        if (!abForceDelete && !LocalOutput[0])
        {
            LocalOutput[0] = LocalStateValue;
            LocalStateValue = 0;
        }
        else if (!abForceDelete && !LocalOutput[1])
        {
            LocalOutput[1] = LocalStateValue;
            LocalStateValue = 0;
        }
        else
        {
            AssignControllerManager(LocalStateValue);
        }
    }
    else
    {
        LocalInput = LocalStateValue;
        LocalStateValue = 0;
    }
}

} // namespace N460090
}   // namespace f3m_00460090

// @f3 0x00479030 (community match, verified in this file)
extern char* EmptyFS;
namespace n479030 {
struct NiRTTI479 { const char* name; const NiRTTI479* base; };
struct FixedStr479 {
    char* h;
    FixedStr479(const FixedStr479& o) { if (o.h != EmptyFS) ::InterlockedIncrement((long volatile*)(o.h - 8)); h = o.h; }
    ~FixedStr479() { if (h != EmptyFS) ::InterlockedDecrement((long volatile*)(h - 8)); }
    operator const char*() const { return h; }
};
struct Tex479 {
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI479* GetRTTI();
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual const FixedStr479& GetFileName();
    long m_uiRefCount;
    void DecRefCount() { if (::InterlockedDecrement(&m_uiRefCount) == 0) v1(); }
};
extern const NiRTTI479 ms_kRTTI_SourceTexture;
template <class T> struct Ptr479 {
    T* p;
    Ptr479() : p(0) {}
    ~Ptr479() { if (p) p->DecRefCount(); }
    operator T*() const { return p; }
};
struct Prop479 {
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
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual unsigned short GetMapCount();
    virtual void v59();
    virtual void SetTexture(int slot, unsigned int index, Tex479* tex);
    virtual Tex479* GetTexture(int slot, unsigned int index);
    char pad[0x18];
    int type;
};
struct Node479;
struct AV479 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node479* AsNode();
    Prop479* GetProperty(unsigned int kind);
};
struct Node479 : AV479 {
    char pad[0x9c];
    AV479** children;
    unsigned short capacity;
    unsigned short count;
};
struct Loader479 { void FUN_004353f0(const char* path, Ptr479<Tex479>* out, int a, int b); };
extern Loader479* DAT_0107a0d8;
bool __cdecl FUN_00478d70(const char* in, char* out, unsigned int size);
inline bool IsKindOf(const NiRTTI479* target, Tex479* o)
{
    if (!o) return false;
    for (const NiRTTI479* r = o->GetRTTI(); r; r = r->base)
        if (r == target) return true;
    return false;
}
inline int IsTexturing(Prop479* p)
{
    return p && p->type >= 7 && p->type <= 11;
}
inline Prop479* GetTexturing(AV479* o)
{
    Prop479* p = o->GetProperty(3);
    return IsTexturing(p) ? p : 0;
}
}
using namespace n479030;
// pdb: SwapPlatformLanguageTextures | GlobalFunc.obj | fnv360_0822_debug, caller, medium
// pdb params: ap3D
bool __cdecl FUN_00479030(AV479* object)
{
    bool changed = false;
    if (object) {
    Prop479* prop = GetTexturing(object);
    if (prop) {
        unsigned int count = prop->GetMapCount();
        for (unsigned int i = 0; i < count; ++i) {
            for (int slot = 0; slot < 6; ++slot) {
                Tex479* tex = prop->GetTexture(slot, i);
                if (!n479030::IsKindOf(&n479030::ms_kRTTI_SourceTexture, tex))
                    continue;
                FixedStr479 name = tex->GetFileName();
                char path[260];
                path[0] = 0;
                if (FUN_00478d70(name, path, sizeof(path)) && path[0]) {
                    Ptr479<Tex479> loaded;
                    n479030::DAT_0107a0d8->FUN_004353f0(path, &loaded, 0, 0);
                    if (loaded) {
                        prop->SetTexture(slot, i, loaded);
                        changed = true;
                    }
                }
            }
        }
    }
    Node479* node = object->AsNode();
    if (node) {
        unsigned int n = node->count;
        for (unsigned int i = 0; i < n; ++i)
        {
            AV479* child = node->children[i];
            if (FUN_00479030(child))
                changed = true;
        }
    }
    }
    return changed;
}

// @f3 0x00478d70 (community match, verified in this file)
#include <string.h>
extern bool DAT_01075b28;
extern bool DAT_01075cac;
extern const char* DAT_00f4c814[4];
extern const char* DAT_00f4c794[5];
namespace f3m_00478d70 {

namespace f3m_00478d70 {


char* __cdecl FUN_00475550(const char* text, const char* pattern);
int __cdecl FUN_00be8c70();

inline int GetPlatform()
{
    if (DAT_01075b28 && !DAT_01075cac) return 1;
    return 0;
}

// pdb: SwapPlatformLanguageTexturePath | GlobalFunc.obj | fnv360_0822_retail, call_gap, low
// pdb params: apInPath, apOutPath, aiOutPathSize
bool __cdecl FUN_00478d70(const char* path, char* out, unsigned int outSize)
{
    if (!path || !out || !outSize)
        return false;

    out[0] = 0;
    bool changed = false;
    int written = 0;
    int platform = 0;
    if (DAT_01075b28 && !DAT_01075cac)
        platform = 1;
    int language = FUN_00be8c70();
    const char* cursor = path;

    for (int i = 0; i < 4; i++) {
        char* found = FUN_00475550(path, DAT_00f4c814[i]);
        int len;
        char sep;
        while (found) {
            len = strlen(DAT_00f4c814[i]);
            if (found[len] == '\\' || found[len] == '/') {
                sep = found[len];
                break;
            }
            found = FUN_00475550(found + len, DAT_00f4c814[i]);
        }
        if (found) {
            int n = found - path;
            if (n) {
                memmove_s(out, outSize, path, n);
                written = n;
                out[written] = 0;
            }
            strcat_s(out, outSize, DAT_00f4c814[platform]);
            written += strlen(DAT_00f4c814[platform]);
            out[written] = sep;
            written++;
            out[written] = 0;
            cursor = found + strlen(DAT_00f4c814[i]) + 1;
            changed = true;
            break;
        }
    }

    for (int j = 0; j < 5; j++) {
        char* found = FUN_00475550(cursor, DAT_00f4c794[j]);
        int len;
        char sep;
        while (found) {
            len = strlen(DAT_00f4c794[j]);
            if (found[len] == '\\' || found[len] == '/') {
                sep = found[len];
                break;
            }
            found = FUN_00475550(found + len, DAT_00f4c794[j]);
        }
        if (found) {
            int n = found - cursor;
            if (n) {
                memmove_s(out + written, outSize - written, cursor, n);
                written += n;
                out[written] = 0;
            }
            strcat_s(out, outSize, DAT_00f4c794[language]);
            written += strlen(DAT_00f4c794[language]);
            out[written] = sep;
            written++;
            out[written] = 0;
            cursor = found + strlen(DAT_00f4c794[j]) + 1;
            changed = true;
            break;
        }
    }

    strcat_s(out, outSize, cursor);
    return changed;
}

}
}   // namespace f3m_00478d70

// @f3 0x0046e340 (community match, verified in this file)
namespace f3m_0046e340 {
namespace F3ModifierDispatch {
struct Point {
    float x,y,z;
};
struct Parameters {
    float a,b,c,d;
};
struct Request {
    unsigned unk00;
    int type;
    Parameters params;
    Point values;
};
int __cdecl FUN_0046dd60(const Point*,Parameters*);
int __cdecl FUN_0046de00(const Point*,Parameters*);
int __cdecl FUN_0046deb0(float,Parameters*);

// pdb: BGSPrimitive::Copy | BGSPrimitive.obj | fnv360_0822_retail, call_gap, low
// pdb params: apCopy
int __cdecl FUN_0046e340(const Request* request)
{
    int result=0;
    if (request->type==3) {
        const Point original=request->values;
        Point values=original;
        values.x=static_cast<float>(values.x*2.0);
        values.y=static_cast<float>(original.z*2.0);
        Parameters params=request->params;
        result=FUN_0046dd60(&values,&params);
    }
    if (request->type==1) {
        Point original=request->values;
        Point values;
        values.x=static_cast<float>(original.x*2.0);
        values.y=static_cast<float>(original.y*2.0);
        values.z=static_cast<float>(original.z*2.0);
        Parameters params=request->params;
        result=FUN_0046de00(&values,&params);
    }
    if (request->type==2) {
        Parameters params=request->params;
        const float x=request->values.x;
        result=FUN_0046deb0(x,&params);
    }
    return result;
}
}
}   // namespace f3m_0046e340

// @f3 0x0046de00 (community match, verified in this file)
namespace f3m_0046de00 {
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
extern double DAT_00db7de8;
struct Vec3 { float x, y, z; };
struct Obj {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(int value);
    virtual void vf0c(Vec3* v);
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
    Obj();
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
// pdb: BGSPrimitive::CreateBox | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aSize, aColor
Obj* __cdecl FUN_0046de00(Vec3* pos, int value) {
    Obj* obj = new Obj;
    obj->vf08(value);
    Vec3 half;
    half.x = (float)(pos->x * DAT_00db7de8);
    half.y = (float)(pos->y * DAT_00db7de8);
    half.z = (float)(pos->z * DAT_00db7de8);
    obj->vf0c(&half);
    obj->unk04 = 1;
    return obj;
}
}

// @f3 0x00475a70 (community match, verified in this file)
namespace f3m_00475a70 {
int __cdecl FUN_00475a70(unsigned char code)
{
    switch (code)
    {
    case 21:
        return 0;
    case 24:
        return 1;
    case 25:
        return 2;
    case 27:
        return 3;
    case 28:
        return 4;
    case 29:
        return 5;
    case 30:
        return 6;
    case 31:
        return 7;
    case 50:
        return 66;
    case 46:
        return 20;
    case 32:
        return 8;
    case 33:
        return 72;
    case 34:
        return 43;
    case 35:
        return 45;
    case 36:
        return 9;
    case 37:
        return 10;
    case 40:
        return 11;
    case 41:
        return 21;
    case 42:
        return 12;
    case 43:
        return 13;
    case 44:
        return 14;
    case 45:
        return 15;
    case 20:
        return 16;
    case 19:
        return 17;
    case 47:
        return 18;
    case 52:
        return 19;
    case 18:
        return 25;
    case 91:
        return 46;
    case 13:
        return 24;
    case 39:
        return 23;
    case 38:
        return 22;
    case 74:
        return 26;
    case 75:
        return 27;
    case 76:
        return 28;
    case 77:
        return 29;
    case 78:
        return 30;
    case 48:
        return 31;
    case 79:
        return 32;
    case 51:
        return 33;
    case 81:
        return 35;
    case 22:
        return 34;
    case 23:
        return 44;
    case 4:
        return 36;
    case 82:
        return 37;
    case 5:
        return 38;
    case 85:
        return 39;
    case 86:
        return 40;
    case 87:
        return 41;
    case 97:
        return 64;
    case 88:
        return 42;
    case 94:
        return 47;
    case 95:
        return 48;
    case 71:
        return 49;
    case 73:
        return 50;
    case 93:
        return 51;
    case 7:
        return 52;
    case 12:
        return 53;
    case 11:
        return 54;
    case 9:
        return 55;
    case 8:
        return 56;
    case 49:
        return 57;
    case 53:
        return 58;
    case 54:
        return 59;
    case 14:
        return 67;
    case 102:
        return 71;
    case 16:
        return 70;
    default:
        return -1;
    }
}
}   // namespace f3m_00475a70

// @f3 0x00464330 (community match, verified in this file)
namespace f3m_00464330 {

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

struct TlsBlock
{
    char unk000[0x298];
    int allocTag;
};
__declspec(thread) TlsBlock g_tls;

struct AutoMemContext
{
    int saved;
    AutoMemContext(int tag) { saved = g_tls.allocTag; g_tls.allocTag = tag; }
    ~AutoMemContext() { g_tls.allocTag = saved; }
};

struct MemoryManager
{
    void FUN_0086ba60(void* p);
};
extern MemoryManager DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned int bytes);

struct NiMatrix3 { float m[3][3]; };
extern const NiMatrix3 FUN_00f72574;

struct NiUpdateData
{
    float fTime;
    bool bUpdateControllers;
    bool bIsMultiThreaded;
    bool bReserved;
    bool bUpdateGeomorphs;
    bool bUpdateShadowScene;
    NiUpdateData(float t, bool controllers)
        : fTime(t), bUpdateControllers(controllers), bIsMultiThreaded(false), bReserved(false),
          bUpdateGeomorphs(false), bUpdateShadowScene(false) {}
};

struct NiNode
{
    char unk00[0x30];
    unsigned int flags;
    NiMatrix3 localRotate;
    void FUN_008264c0(NiUpdateData& data);
};

struct NiNodePtr
{
    NiNode* object;
    NiNodePtr& FUN_008e9650(NiNode* value);
    operator NiNode*() const { return object; }
    NiNode* operator->() const { return object; }
};

struct NiControllerManager
{
    virtual void v00();
    virtual void DeleteThis();
    long references;
    char unk08[0x7c - 0x08];
    NiControllerManager(NiNode* root, bool cumulative);
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct NiControllerManagerPtr
{
    NiControllerManager* object;
    NiControllerManagerPtr& operator=(NiControllerManager* value)
    {
        if (object != value)
        {
            NiControllerManager* old = object;
            if (old && !InterlockedDecrement(&old->references))
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->references);
        }
        return *this;
    }
};

struct BSAnimGroupSequence
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual bool Deactivate(float easeOut, bool transition);
    bool FUN_008aecd0(int priority, int startOver, float weight, float easeIn, int timeSync, int destFrame);
};

struct AnimSequenceBase
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual BSAnimGroupSequence* GetSequence(int index);
};

struct AnimSequenceMap
{
    bool FUN_0045c6e0(unsigned short key, AnimSequenceBase*& value);
};

struct KFModel
{
    int unk00;
    int unk04;
    void* controllerSequence;
};

struct ModelLoader
{
    KFModel* FUN_0042cff0(const char* path);
};
extern ModelLoader* DAT_0106ca70;

struct FileList
{
    const char* item;
    FileList* next;
    bool FUN_00645c20();
    void FUN_006c8220();
    ~FileList() { FUN_006c8220(); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    void RemoveHead()
    {
        FileList* node = next;
        if (node)
        {
            next = node->next;
            item = node->item;
            node->next = 0;
            delete node;
        }
        else
            item = 0;
    }
};

extern const char* DAT_00f5c78c[8];

NiNode* __cdecl FUN_00aab350(NiNode* root, const char* name, bool recursive);

struct TESObjectREFR;

class Animation
{
public:
    int unk00;
    TESObjectREFR* attachedReference;
    NiNodePtr root;
    NiNode* objectNode;
    int unk10, unk14, unk18, unk1C, unk20, unk24;
    NiNode* nodes[8];
    char unk48[0xd8 - 0x48];
    NiControllerManagerPtr controllerManager;
    AnimSequenceMap* sequences;

    bool Animation_ShouldQueueSequenceCloning();
    void FUN_00461a70(KFModel* model, bool queue);
    bool FUN_00464330(FileList* files, NiNode* rootNode, TESObjectREFR* actor, bool activate);
};

// pdb: Animation::Init | Animation.obj | fnv360_0822_retail, call_gap, low
// pdb params: apFileList, apRoot, apRef, abUpdate3D
bool Animation::FUN_00464330(FileList* files, NiNode* rootNode, TESObjectREFR* actor, bool activate)
{
    AutoMemContext context(0x33);
    if (!files || !rootNode || !actor)
        return false;
    attachedReference = actor;
    AnimSequenceBase* sequence;
    if (sequences && sequences->FUN_0045c6e0(0, sequence))
        return false;
    root.FUN_008e9650(rootNode);
    for (int i = 0; i <= 7; ++i)
        if (DAT_00f5c78c[i])
            nodes[i] = FUN_00aab350(rootNode, DAT_00f5c78c[i], true);
    root->flags &= ~2;
    controllerManager = new NiControllerManager(root, true);
    bool queue = Animation_ShouldQueueSequenceCloning();
    while (!files->FUN_00645c20())
    {
        const char* file = files->item;
        KFModel* model = DAT_0106ca70->FUN_0042cff0(file);
        if (model && model->controllerSequence)
            FUN_00461a70(model, queue);
        DAT_01090a78.FUN_0086ba60((void*)file);
        files->RemoveHead();
    }
    if (objectNode)
        objectNode->localRotate = FUN_00f72574;
    delete files;
    bool result = sequences->FUN_0045c6e0(0, sequence);
    if (result && activate)
    {
        BSAnimGroupSequence* anim = sequence->GetSequence(-1);
        if (anim)
        {
            anim->FUN_008aecd0(100, 1, 1.0f, 0.0f, 0, 0);
            NiUpdateData update(0.0f, true);
            root->FUN_008264c0(update);
            anim->Deactivate(0.0f, false);
        }
    }
    return result;
}

}

// @f3 0x0046b560 (community match, verified in this file)
namespace f3m_0046b560 {
namespace f3m_0046b560 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
void* __cdecl FUN_0089eb90(unsigned int bytes);

struct RefObject {
    virtual void vf00();
    virtual void DeleteThis();
    volatile long refCount;
    void IncRef() { InterlockedIncrement(&refCount); }
    void DecRef() { if (!InterlockedDecrement(&refCount)) DeleteThis(); }
};
template <class T> struct NiPointer {
    T* m_pObject;
    NiPointer() : m_pObject(0) {}
    ~NiPointer() { if (m_pObject) m_pObject->DecRef(); }
    NiPointer& operator=(T* p)
    {
        if (m_pObject != p) {
            if (m_pObject)
                m_pObject->DecRef();
            m_pObject = p;
            if (p)
                p->IncRef();
        }
        return *this;
    }
};
struct FUN_00ae9090 : RefObject {
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    FUN_00ae9090(int a, int b, int c);
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    int unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94;
    int unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4;
    int unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124;
    int unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154;
    int unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184;
    int unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4;
    int unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0, unk1E4;
    int unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C, unk210, unk214;
    int unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C, unk240, unk244;
    int unk248, unk24C, unk250, unk254, unk258, unk25C, unk260, unk264, unk268, unk26C, unk270, unk274;
    int unk278, unk27C;
};
struct FUN_0083b6d0 : RefObject {
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    FUN_0083b6d0();
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    int unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94;
    int unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4;
    int unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110;
};
struct Head {
    void* unk00;
    Head() : unk00(0) {}
    ~Head();
};
struct Table {
    void* unk00;
    void* unk04;
    unsigned int unk08;
    Table() { unk08 = 0; unk00 = 0; unk04 = 0; }
    ~Table();
};
struct FUN_0046b560 {
    Head unk00;
    int unk04;
    Table unk08;
    Table unk14;
    NiPointer<FUN_00ae9090> unk20;
    NiPointer<FUN_0083b6d0> unk24;
    FUN_0046b560();
};
// pdb: BGSDecalManager::BGSDecalManager | BGSDecalManager.obj | fnv360_0822_retail, call_seq, medium
FUN_0046b560::FUN_0046b560()
{
    unk20 = new FUN_00ae9090(0x63, 1, 0x2f7);
    unk24 = new FUN_0083b6d0;
}
}


}   // namespace f3m_0046b560

// @f3 0x0047f750 (community match, verified in this file)
namespace f3m_0047f750 {
struct Item47f750 { void FUN_0047dd50(); };
struct Obj47f750 { virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65();virtual void v66();virtual void v67();virtual void v68();virtual void v69();virtual void v70();virtual void v71();virtual void v72();virtual void v73();virtual void v74();virtual void v75(); virtual int GetId(); };
struct Ent47f750 { int form; char kind; char idb[4]; };
struct Data47f750 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char* pos;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    Ent47f750* ent;
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void FUN_006db460(const void* data, int size);
};
struct Node47f750 { Item47f750* item; Node47f750* next; bool Empty() const { return next == 0 && item == 0; } Item47f750* Get() const { return item; } };
struct List47f750 { Node47f750* head; void FUN_0047f750(); };
extern Data47f750* DAT_01079ca4;
extern bool DAT_01079d20;
Obj47f750* __cdecl TESForm_GetFormByNumericID(int form);
void __cdecl FUN_00c24b70(const char* fmt, ...);
// pdb: InventoryChanges::SaveGame | InventoryChanges.obj | fnv360_0822_retail, call_gap, medium
void List47f750::FUN_0047f750()
{
    short blockSize = 0;
    char* start = DAT_01079ca4->pos;
    char* sizePos = 0;
    if (DAT_01079ca4->TESSaveLoadGame_UseSaveGameBlocks()) {
        int tag = 'BLOK';
        DAT_01079ca4->FUN_006db460(&tag, 4);
        sizePos = DAT_01079ca4->pos;
        DAT_01079ca4->FUN_006db460(&blockSize, 2);
    }
    short count = 0;
    char* countPos = DAT_01079ca4->pos;
    DAT_01079ca4->FUN_006db460(&count, 2);
    for (Node47f750* n = head; n; n = n->next) {
        if (n->Empty()) break;
        Item47f750* it = n->Get();
        if (it) {
            it->FUN_0047dd50();
            count++;
        }
    }
    *(short*)countPos = count;
    if (DAT_01079d20) {
        Ent47f750* e = DAT_01079ca4->ent;
        char* end = DAT_01079ca4->pos;
        if (e) {
            Obj47f750* o = TESForm_GetFormByNumericID(e->form);
            FUN_00c24b70("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", end - start, e->form, o->GetId(), *(int*)e->idb, 0x2386, "c:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp");
        }
    }
    if (DAT_01079ca4->TESSaveLoadGame_UseSaveGameBlocks())
        *(short*)sizePos = (short)DAT_01079ca4->pos - (short)sizePos;
}
}

// @f3 0x00471ca0 (community match, verified in this file)
namespace F3ModelVariant {
struct SceneObject;
struct LoadOptions {
    unsigned unk00,unk04,unk08,unk0c;
    float scaleX,scaleY,scaleZ;
    explicit LoadOptions(unsigned mode) { FUN_00471430(mode); scaleX=scaleY=scaleZ=1.0f; }
    ~LoadOptions() { FUN_00470870(); }
    void FUN_00470870();
    void FUN_00471430(unsigned mode);
};
struct RetainedObject {
    SceneObject* object;
    RetainedObject():object(0) {}
    ~RetainedObject() { FUN_00424aa0(); }
    void FUN_00424aa0();
    void FUN_008e9650(SceneObject*);
};
struct Point { unsigned x,y,z; };
struct Rotation { float m[3][3]; };
struct SceneObject {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    Rotation rotation;
    Point translation;
    void FUN_00ad2840(unsigned);
};
struct ModelForm {
    SceneObject* FUN_008257a0(LoadOptions*);
};
struct SceneRoot {
    void TESModelTextureSwap_SwapTextures(SceneObject*);
};
struct AttachProvider {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual SceneRoot* GetRoot();
};
struct UpdateOwner {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3c();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4c();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5c();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6c();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7c();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8c();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9c();
    virtual void Slota0();
    virtual void Slota4();
    virtual void Slota8();
    virtual bool CheckUpdate();
};
struct Entry {
    UpdateOwner* updateOwner;
    AttachProvider* attachment;
    SceneObject* existing;
    unsigned unk0c;
};
struct World {
    SceneObject* FUN_00435e70(ModelForm*,LoadOptions*);
};
extern World* DAT_0107a0d8;
extern const Point DAT_0108ec68;
extern const Rotation DAT_00f72574;
extern const unsigned char DAT_0116eeec[];
bool __cdecl FUN_00478250(ModelForm*);
bool __cdecl FUN_00424d20(const void*,SceneObject*);
void __cdecl FUN_00479030(SceneObject*);
struct Owner {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    Entry entries[4];
    SceneObject* FUN_00471ca0(const void* enabled,ModelForm* model,unsigned index);
};
// pdb: BipedAnim::CloneHelmet | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: apfgModel, apNode, aeBipedObject
SceneObject* Owner::FUN_00471ca0(const void* enabled,ModelForm* model,unsigned index)
{
    if (entries[index].existing || !enabled || !model)
        return 0;

    LoadOptions options(0x101);
    RetainedObject retained;
    SceneObject* scene;
    if (FUN_00478250(model)) {
        retained.FUN_008e9650(DAT_0107a0d8->FUN_00435e70(model,&options));
        scene=retained.object;
    } else {
        scene=model->FUN_008257a0(&options);
    }
    if (scene) {
        if (FUN_00424d20(DAT_0116eeec,scene))
            scene->FUN_00ad2840(7);
        scene->translation=DAT_0108ec68;
        scene->rotation=DAT_00f72574;
        if (entries[index].attachment) {
            SceneRoot* root=entries[index].attachment->GetRoot();
            if (root)
                root->TESModelTextureSwap_SwapTextures(scene);
        }
        if (entries[index].updateOwner && entries[index].updateOwner->CheckUpdate())
            FUN_00479030(scene);
        return scene;
    }
    return 0;
}
}

// @f3 0x0046f820 (community match, verified in this file)
#include <new>
namespace f3m_0046f820 {
namespace f3m_0046f820 {
struct Element {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};
class ElementArray {
public:
    virtual void Slot00();
    virtual Element* Allocate(unsigned count);
    virtual void Release(Element* data);
    Element* data;
    unsigned size;
    unsigned capacity;
    unsigned GrowthCapacity() const
    {
        return capacity > 0x400 ? capacity + 0x400 : capacity * 2;
    }
    unsigned FUN_0046eeb0();
    void FUN_0046e5c0(Element* destination, Element* source, unsigned count);
    void FUN_0046f820(unsigned index, const Element& value);
};
// pdb: BSSimpleArray<SCENE_INFO_DATA_STRUCT,1024>::Insert | BGSSceneInfo.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiIndex, aValue
void ElementArray::FUN_0046f820(unsigned index, const Element& value)
{
    unsigned destination;
    if (index == size) {
        destination = FUN_0046eeb0();
        new (data + destination) Element();
    } else {
        if (size == capacity) {
            unsigned newCapacity = GrowthCapacity();
            Element* newData = Allocate(newCapacity);
            FUN_0046e5c0(newData, data, index);
            destination = index;
            Element* inserted = newData + destination;
            new (inserted) Element();
            FUN_0046e5c0(inserted + 1, data + destination, size - index);
            Release(data);
            data = newData;
            capacity = newCapacity;
        } else {
            destination = index;
            FUN_0046e5c0(data + destination + 1, data + destination, size - index);
            new (data + destination) Element();
        }
        ++size;
    }
    data[destination] = value;
}
}
}   // namespace f3m_0046f820

// @f3 0x004649f0 (community match, verified in this file)
#include <windows.h>
extern __declspec(thread) int g_tlsMemContext;
namespace f3m_004649f0 {
namespace f3m_004649f0 {
struct TagScope {
    int old;
    TagScope(int tag) { old = g_tlsMemContext; g_tlsMemContext = tag; }
    ~TagScope() { g_tlsMemContext = old; }
};
void* __cdecl FUN_0089eb90(unsigned); void __cdecl FUN_0089ec10(void*);
struct Owner;
struct FUN_00460ba0 {
    virtual void v0(); virtual void Destroy();
    long refs; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034;
    FUN_00460ba0(unsigned, unsigned, unsigned, unsigned, unsigned, Owner*);
    static void* operator new(unsigned n) throw() { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ec10(p); }
};
struct Smart {
    FUN_00460ba0* ptr;
    void operator=(FUN_00460ba0* value) {
        if (ptr != value) {
            FUN_00460ba0* old = ptr;
            if (old && !::InterlockedDecrement(&old->refs)) old->Destroy();
            ptr = value;
            if (value) ::InterlockedIncrement(&value->refs);
        }
    }
};
struct Proc {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void V38C(unsigned);
};
struct Actor {
    void* vtbl;
    unsigned unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    Proc* unk60;
};
struct Owner {
    unsigned unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    unsigned unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    unsigned unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    unsigned unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    unsigned unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    unsigned unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118;
    Smart current;
    void FUN_00463650();
    void FUN_004649f0(unsigned first, Actor* actor, int type, unsigned mode);
};
// pdb: Animation::SpecialIdleAuto | Animation.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apIdleForm, apActor, aeSection, aeType
void Owner::FUN_004649f0(unsigned first, Actor* actor, int type, unsigned mode)
{
    TagScope tag(0x33);
    unsigned m = mode;
    switch (type) {
    case 0: case 1: case 20:
        m = 3;
        break;
    }
    current = new FUN_00460ba0(first, type, m, (unsigned)actor, 0, this);
    actor->unk60->V38C(first);
    FUN_00463650();
}
}
}   // namespace f3m_004649f0

// @f3 0x0047e9d0 (community match, verified in this file)
namespace f3m_0047e9d0 {
namespace z47e9d0 {
struct Form { char pad[0xc]; unsigned refID; };
struct ContainerEntry { int count; Form* form; };
struct ContainerNode { ContainerEntry* item; ContainerNode* next; };
struct Container { int unk00; ContainerNode list; };
struct BaseForm { Container* FUN_004e66c0(); };
struct ExtraList { Form* FUN_0040bd70(); };
struct ExtraNode { ExtraList* item; ExtraNode* next; };
struct InvEntry { ExtraNode* extraLists; int countDelta; Form* form; };
struct InvNode { InvEntry* item; InvNode* next; };
struct Owner {
 InvNode* entries;
 BaseForm* baseForm;
 bool FUN_0047e9d0(unsigned refID);
};
// pdb: InventoryChanges::HasObjectId | InventoryChanges.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aId
bool Owner::FUN_0047e9d0(unsigned refID) {
 int count = 0;
 Container* container = baseForm ? baseForm->FUN_004e66c0() : 0;
 for (ContainerNode* node = &container->list; node; node = node->next) {
  if (!node->next && !node->item) break;
  ContainerEntry* ce = node->item;
  Form* form = ce->form;
  if (form && form->refID == refID) {
   InvNode* in = entries;
   bool searching = true;
   while (in && searching) {
    InvEntry* e = in->item;
    if (e && e->form == form) searching = false;
    else in = in->next;
   }
   InvEntry* entry = in ? in->item : 0;
   int base = ce->count;
   if (base < 0) return true;
   if (entry && entry->countDelta + base) count += entry->countDelta + base;
   else count += base;
   if (count > 0) return true;
  }
 }
 for (InvNode* node = entries; node; node = node->next) {
  if (!node->next && !node->item) break;
  for (ExtraNode* xn = node->item->extraLists; xn; xn = xn->next) {
   ExtraList* x = xn->item;
   if (!x) break;
   if (x->FUN_0040bd70() && x->FUN_0040bd70()->refID == refID) return true;
  }
 }
 return false;
}
}
}   // namespace f3m_0047e9d0

// @f3 0x0047db40 (community match, verified in this file)
namespace f3m_0047db40 {
class TESHealthForm {
public:
    virtual ~TESHealthForm();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual unsigned int GetHealth();
};
namespace f3m_47db40w {
struct ExtraList {
    float FUN_0040ac20();
};
struct Entry {
    ExtraList** extra;
    int count;
    TESBoundObject* object;
    float FUN_0047db40(bool usesCount, int unused1, int unused2, int unused3);
};
}
TESHealthForm* FUN_004566c0(TESBoundObject* object);
namespace f3m_47db40w {
float Entry::FUN_0047db40(bool usesCount, int unused1, int unused2, int unused3)
{
    float result = -1.0f;
    TESHealthForm* health = dynamic_cast<TESHealthForm*>(object);
    TESUsesForm* uses = dynamic_cast<TESUsesForm*>(object);
    if (health) {
        TESHealthForm* base = FUN_004566c0(object);
        float current;
        if (base) {
            ExtraList* list;
            if (extra && (list = *extra) != 0) {
                if (list->FUN_0040ac20() != -1.0f)
                    current = list->FUN_0040ac20();
                else
                    current = base->GetHealth();
            } else {
                current = base->GetHealth();
            }
        } else {
            current = -1.0f;
        }
        result = (double)current / (float)health->GetHealth() * 100.0;
    } else if (uses) {
        if (usesCount) {
            UsesRef7d* ref = reinterpret_cast<UsesRef7d*>(this);
            if (ref->FUN_0047d050())
            {
                result = ref->FUN_0047d050();
            }
        } else {
            result = uses->usesType;
        }
    }
    return result;
}
}
}   // namespace f3m_0047db40

// @f3 0x0047f050 (community match, verified in this file)
namespace f3m_0047f050 {
namespace f3m_47f050w {
class Form {
public:
    virtual ~Form();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0A();
    virtual void Unk0B();
    virtual void Unk0C();
    virtual void Unk0D();
    virtual void Unk0E();
    virtual void Unk0F();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1A();
    virtual void Unk1B();
    virtual void Unk1C();
    virtual void Unk1D();
    virtual void Unk1E();
    virtual void Unk1F();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual bool IsQuestItem();
    int unk04;
    int unk08;
    unsigned int refID;
};
int FUN_0045bd90(Form* form);
struct ContainerEntry { int count; Form* form; };
struct ContainerNode { ContainerEntry* item; ContainerNode* next; };
struct Container {
    int unk00;
    ContainerNode list;
    bool FUN_004528c0(Form* form);
};
struct BaseForm { Container* FUN_004e66c0(); };
struct InvEntry { void* extraLists; int countDelta; Form* form; };
struct InvNode { InvEntry* item; InvNode* next; };
struct Owner {
    InvNode* entries;
    BaseForm* baseForm;
    __forceinline InvEntry* Find(Form* form) {
        InvNode* in = entries;
        bool searching = true;
        while (in && searching) {
            InvEntry* e = in->item;
            if (e && e->form == form)
                searching = false;
            else
                in = in->next;
        }
        return in ? in->item : 0;
    }
    int FUN_0047f050(bool includeQuestItems, bool includeCaps);
};
// pdb: InventoryChanges::GetInventoryValue | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abCountQuest, abCountGold
int Owner::FUN_0047f050(bool includeQuestItems, bool includeCaps)
{
    int total = 0;
    Container* container = baseForm ? baseForm->FUN_004e66c0() : 0;
    for (ContainerNode* node = &container->list; node; node = node->next) {
        if (!node->next && !node->item)
            break;
        Form* form = node->item->form;
        if (!includeQuestItems && form->IsQuestItem())
            continue;
        if (!includeCaps && form->refID == 15)
            continue;
        int value = FUN_0045bd90(form);
        if (value == -1 || value == 0)
            continue;
        InvNode* in = entries;
        bool searching = true;
        while (in && searching) {
            InvEntry* e = in->item;
            if (e && e->form == form)
                searching = false;
            else
                in = in->next;
        }
        InvEntry* entry = in ? in->item : 0;
        if (!entry) {
            total += node->item->count * value;
        } else {
            if (entry->countDelta + node->item->count)
                total += (entry->countDelta + node->item->count) * value;
        }
    }
    for (InvNode* n = entries; n; n = n->next) {
        InvEntry* entry = n->item;
        if (!entry)
            break;
        Form* form = entry->form;
        if (!form)
            continue;
        if (baseForm && baseForm->FUN_004e66c0()) {
            Container* c = baseForm ? baseForm->FUN_004e66c0() : 0;
            if (c->FUN_004528c0(form))
                continue;
        }
        if (!includeQuestItems && form->IsQuestItem())
            continue;
        if (!includeCaps && form->refID == 15)
            continue;
        int value = FUN_0045bd90(form);
        if (value == -1 || value == 0)
            continue;
        if (entry->countDelta)
            total += entry->countDelta * value;
    }
    return total;
}
}
}   // namespace f3m_0047f050

// @f3 0x0047df80 (community match, verified in this file)
namespace n47df80 {
struct TlsBlock { char unk000[0x298]; int allocTag; };
extern __declspec(thread) TlsBlock g_tls;
struct TlsTagGuard {
    int saved;
    TlsTagGuard(int tag) { saved = g_tls.allocTag; g_tls.allocTag = tag; }
    ~TlsTagGuard() { g_tls.allocTag = saved; }
};
struct Heap {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
struct Pair {
    int first;
    int second;
    Pair() { first = 0; second = 0; }
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct FUN_004f9970 {
    char unk00[0x60];
    FUN_004f9970();
    void FUN_004553b0();
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern FUN_004f9970* DAT_0106ea24;
struct Ref {
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
    virtual bool v100();
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c(float value);
};
struct Obj {
    Pair* pair;
    Ref* ref;
    float f08;
    float f0c;
    bool b10;
    Obj* FUN_0047df80(Ref* r);
};
// pdb: InventoryChanges::InventoryChanges | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRef
Obj* Obj::FUN_0047df80(Ref* r)
{
    TlsTagGuard guard(0x36);
    ref = r;
    pair = new Pair;
    if (!DAT_0106ea24) {
        DAT_0106ea24 = new FUN_004f9970;
        DAT_0106ea24->FUN_004553b0();
    }
    f08 = f0c = -1.0f;
    if (ref && ref->v100())
        ref->v30c(-1.0f);
    b10 = false;
    return this;
}
}

// @f3 0x0047a660 (community match, verified in this file)
namespace n47a660 {
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
struct ArrayAlloc { static void* operator new[](unsigned size) { return DAT_01090a78.FUN_0086b930(size); } };
void* __cdecl FUN_0089eb90(unsigned);
void __cdecl FUN_0089ec10(void*);

struct Pt3_47a660 : ArrayAlloc
{
    float x, y, z;
    Pt3_47a660() {}
    Pt3_47a660(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

struct FUN_0046c350 : ArrayAlloc
{
    float r, g, b, a;
    FUN_0046c350();
};

struct NiObject
{
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p, unsigned int) { FUN_0089ec10(p); }
};

struct NiAVObject : NiObject
{
    void FUN_004236f0(NiObject* apProperty);
};

struct FUN_0083f750 : NiAVObject
{
    int unk[0xc4 / 4];
    FUN_0083f750(unsigned short usVertices, Pt3_47a660* pkVertex, FUN_0046c350* pkColor, void* pkTexture,
                 unsigned short usNumTextureSets, unsigned int eNBTMethod, unsigned char* pkFlags);
};

struct FUN_00af2240 : NiObject
{
    int unk[0x80 / 4];
    FUN_00af2240();
};

void __cdecl FUN_00ade300(NiAVObject* apObject, int a, int b);
}
using namespace n47a660;

// pdb: MakeRectangle | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afDrawSize, aColor, abWithNoLightingProp
FUN_0083f750* FUN_0047a660(float size, const FUN_0046c350& color, bool lighting)
{
    Pt3_47a660* verts = new Pt3_47a660[4];
    FUN_0046c350* colors = new FUN_0046c350[4];
    unsigned char* flags = (unsigned char*)n47a660::DAT_01090a78.FUN_0086b930(4);
    float neg = -size;
    verts[0] = Pt3_47a660(neg, neg, 0.0f);
    verts[1] = Pt3_47a660(neg, size, 0.0f);
    verts[2] = Pt3_47a660(size, size, 0.0f);
    verts[3] = Pt3_47a660(size, neg, 0.0f);
    for (int i = 0; i < 4; i++)
    {
        colors[i] = color;
        flags[i] = 1;
    }
    FUN_0083f750* lines = new FUN_0083f750(4, verts, colors, 0, 0, 0, flags);
    if (lighting)
    {
        lines->FUN_004236f0(new n47a660::FUN_00af2240);
        FUN_00ade300(lines, 0, 0);
    }
    return lines;
}

// @f3 0x0047cc10 (community match, verified in this file)
class Matrix161 { public: float m[9]; void FUN_00a59540(float x, float y, float z); };
namespace n47cc10 {
struct NiPt { float x, y, z;
    NiPt() {}
    NiPt(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
inline NiPt operator*(const Matrix161& m, const NiPt& v)
{
    return NiPt(m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z,
                m.m[3] * v.x + m.m[4] * v.y + m.m[5] * v.z,
                m.m[6] * v.x + m.m[7] * v.y + m.m[8] * v.z);
}
struct Model;
struct Ref {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
    virtual NiPt* GetPos();
    char pad04[0x20 - 4];
    NiPt rot;
    char pad2c[0x3c - 0x2c];
    void* unk3c;
    Model* FUN_004e8880();
};
struct Counter { void ExtraDataList_SetCount(int n); };
struct Result {
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15(); virtual void w16(); virtual void w17();
    virtual void SetFlags(int f);
    char pad04[0x40 - 4];
    Counter counter;
};
struct Manager {
    Result* FUN_0043def0(int a2, NiPt* pos, NiPt* rot, void* unk3c, Model* model, int a4, int a7, int a8);
};
extern Manager* DAT_0106cdcc;
extern NiPt DAT_0108ec68;
}
using namespace n47cc10;

// pdb: InventoryChanges::DropItemIntoWorld | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
// pdb params: apRef, apObject, ainumber, apCreatedRef, apPoint, apRotate
Result* __stdcall FUN_0047cc10(Ref* ref, int a2, int count, int a4, NiPt* pos, NiPt* rot)
{
    NiPt p;
    if (pos) {
        p.x = pos->x; p.y = pos->y; p.z = pos->z;
    } else {
        p = *ref->GetPos();
        NiPt angle = ref->rot;
        Matrix161 m;
        m.FUN_00a59540(angle.x, angle.y, angle.z);
        NiPt off = m * NiPt(0.0f, 50.0f, 30.0f);
        p.x = p.x + off.x;
        p.y = p.y + off.y;
        p.z = p.z + off.z;
    }
    if (!rot) rot = ref ? &ref->rot : &n47cc10::DAT_0108ec68;
    void* u = ref->unk3c; NiPt r = *rot;
    Result* result = n47cc10::DAT_0106cdcc->FUN_0043def0(a2, &p, &r, u, ref->FUN_004e8880(), a4, 0, 0);
    if (count > 1) result->counter.ExtraDataList_SetCount(count);
    result->SetFlags(0x400);
    return result;
}

// @f3 0x00461190 (community match, verified in this file)
namespace f3m_00461190 {
namespace f3m_00461190 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObject {
    virtual void v00();
    virtual void DeleteThis();
    volatile long refCount;
};
template <class T> struct RefPtr {
    T* m_pObject;
    void Release()
    {
        T* p = m_pObject;
        if (p) {
            if (!InterlockedDecrement(&p->refCount))
                p->DeleteThis();
            m_pObject = 0;
        }
    }
    operator T*() const { return m_pObject; }
};
struct Sound;
struct Controller {
    void FUN_0044db80(Sound* sound, float time);
    void NiControllerManager_DeactivateAll(float time);
};
struct Sound {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
    Sound* unk58;
};
struct Anim {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void Stop(float time, int flags);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40;
    int unk44;
    int unk48, unk4C, unk50, unk54;
    Sound* unk58;
};
int __cdecl FUN_006191f0();
void __cdecl FUN_0045e290(int a);
struct IntTriple {
    int unk00, unk04, unk08;
};
struct AnimSlot {
    Anim* anim;
    int unk04;
    int unk08;
};
class Process {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    short unk54[6];
    int unk60, unk64, unk68;
    IntTriple unk6C[2];
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    short unkA4[6];
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4;
    Controller* unkD8;
    int unkDC, unkE0, unkE4, unkE8, unkEC;
    union {
        AnimSlot anims[2];
        struct {
            Anim* unkF0;
            int unkF4, unkF8;
            Anim* unkFC;
            int unk100, unk104;
        };
    };
    int unk108, unk10C, unk110;
    bool unk114;
    RefPtr<RefObject> unk118;
    RefPtr<RefObject> unk11C;
    void Animation_ClearGroup(int slot, float time);
    void FUN_0045dca0();
    void FUN_0045feb0(RefPtr<RefObject>* ptr);
    void Animation_ClearBlendInterps();
    void FUN_0045e360(int a);
    void FUN_00461190(int unused);
    __forceinline void StopAnim(int i)
    {
        if (unkD8 && anims[i].anim && anims[i].anim->unk44) {
            if (anims[i].anim->unk58)
                unkD8->FUN_0044db80(anims[i].anim->unk58, 0.0f);
            anims[i].anim->Stop(0.0f, 0);
        }
        anims[i].anim = 0;
        unk54[i * 3] = 0xff;
        unkA4[i * 3] = 0xff;
        unk6C[i].unk00 = -1;
    }
};
// pdb: Animation::Revert | Animation.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRef
void Process::FUN_00461190(int unused)
{
    if (FUN_006191f0() != 1) {
        Animation_ClearGroup(7, 0.0f);
        if (!unk114)
            Animation_ClearGroup(0, 0.0f);
    }
    Animation_ClearGroup(1, 0.0f);
    if (FUN_006191f0() != 1)
        Animation_ClearGroup(2, 0.0f);
    Animation_ClearGroup(3, 0.0f);
    Animation_ClearGroup(5, 0.0f);
    Animation_ClearGroup(6, 0.0f);
    StopAnim(0);
    FUN_0045dca0();
    if (unk118)
        FUN_0045feb0(&unk118);
    unk118.Release();
    if (unk11C)
        FUN_0045feb0(&unk11C);
    unk11C.Release();
    unkFC = 0;
    StopAnim(1);
    if (unkD8)
        unkD8->NiControllerManager_DeactivateAll(0.0f);
    FUN_0045e290(unk08);
    Animation_ClearBlendInterps();
    FUN_0045e360(1);
}
}
}   // namespace f3m_00461190

// @f3 0x00476780 (community match, verified in this file)
extern unsigned int DAT_01090bb0;
namespace f3m_00476780 {
namespace f3m_00476780 {
struct NiPoint3 {
    float x, y, z;
    float Dot(const NiPoint3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct NiPlane {
    NiPoint3 m_kNormal;
    float m_fConstant;
    float Distance(const NiPoint3& p) const { return m_kNormal.Dot(p) - m_fConstant; }
};
struct NiBound {
    NiPoint3 m_kCenter;
    float m_fRadius;
};
struct NiCamera;
struct NiFrustumPlanes {
    NiPlane m_akCullingPlanes[6];
    unsigned int m_uiActivePlanes;
    NiFrustumPlanes();
    void FUN_0083f470(NiCamera* cam);
    NiPlane GetPlane(unsigned int i) const { return m_akCullingPlanes[i]; }
};
// pdb: BoundInFrustum | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aBound, apCamera
bool FUN_00476780(const NiBound* bound, NiCamera* cam)
{
    if (!cam)
        return false;
    static NiFrustumPlanes planes;
    static NiCamera* lastCam;
    static unsigned int lastFrame = 0xFFFFFFFF;
    if (lastCam != cam || lastFrame != DAT_01090bb0) {
        planes.FUN_0083f470(cam);
        lastFrame = DAT_01090bb0;
        lastCam = cam;
    }
    float negRadius = -bound->m_fRadius;
    unsigned int i = 0;
    do {
        NiPlane plane = planes.GetPlane(i);
        float d = plane.Distance(bound->m_kCenter);
        if (d <= negRadius)
            return false;
        i++;
    } while (i < 6);
    return true;
}
}
}   // namespace f3m_00476780

// @f3 0x004715f0 (community match, verified in this file)
namespace f3m_004715f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct Model {
    virtual ~Model();
    int unk04;
    volatile long refCount;
    void IncRef() { InterlockedIncrement(&refCount); }
    void DecRef()
    {
        if (!InterlockedDecrement(&refCount) && this)
            delete this;
    }
};
struct ModelPtr {
    Model* m_pObject;
    ModelPtr() : m_pObject(0) {}
    ~ModelPtr()
    {
        if (m_pObject)
            m_pObject->DecRef();
    }
    ModelPtr& operator=(const ModelPtr& p)
    {
        if (m_pObject != p.m_pObject) {
            if (m_pObject)
                m_pObject->DecRef();
            m_pObject = p.m_pObject;
            if (m_pObject)
                m_pObject->IncRef();
        }
        return *this;
    }
};
struct Part {
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned char flags;
};
struct NameHolder {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual const char* GetName();
};
struct Form {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0;
    NameHolder unkC4;
};
struct QHolder {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    TESBoundObject* unk1C;
};
struct Loader {
    void ModelLoader_QueueModel(Part* part, int a, int b, int c, bool d, int e, int f);
    void FUN_0042cac0(const char* name, int a, int b, int c, bool d, int e, int f);
};
extern Loader* DAT_0106ca70;
extern bool DAT_0106e534;
extern bool DAT_01073a60;
extern QHolder* DAT_0107a104;
Form* __cdecl FUN_00451da0(int id);
struct Slot {
    int formId;
    Part* part;
    int unk08;
    int unk0C;
};
bool __cdecl FUN_004706c0();
inline bool IsQueued(Part* part)
{
    return part && (part->flags & 1) && DAT_0106e534 && DAT_01073a60 && FUN_004706c0();
}
class Owner {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    Slot slots[20];
    int unk16C, unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198;
    int unk19C, unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8;
    int unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8;
    int unk1FC, unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C, unk220, unk224, unk228;
    int unk22C, unk230, unk234, unk238, unk23C, unk240, unk244, unk248, unk24C, unk250, unk254, unk258;
    int unk25C, unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C, unk280, unk284, unk288;
    int unk28C, unk290, unk294, unk298, unk29C, unk2A0, unk2A4, unk2A8, unk2AC;
    QHolder* unk2B0;
    void FUN_004710f0(int a, int b, ModelPtr* out, int index);
    Part* FUN_00470b00(int index, Part* part);
    void FUN_00470d10(int flags, int a, int b);
    void FUN_004715f0(int a, ModelPtr* out, int b);
};
// pdb: BipedAnim::QueueBipedParts | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: aePriority, aspQueuedHelmet, apParent
void Owner::FUN_004715f0(int a, ModelPtr* out, int b)
{
    ModelPtr spModel;
    int flags = 0;
    TESBoundObject* object = unk2B0->unk1C;
    TESNPC* npc = dynamic_cast<TESNPC*>(object);
    if (npc) {
        for (int i = 0; i < 20; i++) {
            Part* part = slots[i].part;
            if (part && part != (Part*)-1) {
                flags |= slots[i].part->flags & 0xe;
                if (IsQueued(slots[i].part)) {
                    FUN_004710f0(a, b, &spModel, i);
                } else {
                    if (unk2B0 == DAT_0107a104) {
                        Part* other = FUN_00470b00(i, part);
                        if (other != slots[i].part)
                            DAT_0106ca70->ModelLoader_QueueModel(other, a, b, 3, true, 0, 0);
                    }
                    DAT_0106ca70->ModelLoader_QueueModel(slots[i].part, a, b, 3, true, 0, 0);
                    Form* form = FUN_00451da0(slots[i].formId);
                    if (form) {
                        const char* name = form->unkC4.GetName();
                        if (*name)
                            DAT_0106ca70->FUN_0042cac0(name, a, b, 3, true, 0, 0);
                    }
                }
            }
        }
    }
    *out = spModel;
    FUN_00470d10(flags, a, b);
}
}

// @f3 0x004635f0 (community match, verified in this file)
namespace f3m_004635f0 {
namespace f3m_004635f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct Task1236 {
    virtual void v00();
    virtual void Destroy();
    volatile long count;
    int state;
    int unk0C;
    void* data;
    __forceinline void IncRef() { InterlockedIncrement(&count); }
    __forceinline void DecRef() { if (!InterlockedDecrement(&count)) Destroy(); }
};
template <class T> struct Ptr {
    T* m_pObject;
    operator T*() const { return m_pObject; }
    T* operator->() const { return m_pObject; }
    Ptr& operator=(T* o) {
        if (m_pObject != o) { if (m_pObject) m_pObject->DecRef(); m_pObject = o; if (m_pObject) m_pObject->IncRef(); }
        return *this;
    }
};
}
using namespace f3m_004635f0;
struct Owner1236 {int unk000,unk004,unk008,unk00C,unk010,unk014,unk018,unk01C,unk020,unk024,unk028,unk02C,unk030,unk034,unk038,unk03C,unk040,unk044,unk048,unk04C,unk050,unk054,unk058,unk05C,unk060,unk064,unk068,unk06C,unk070,unk074,unk078,unk07C,unk080,unk084,unk088,unk08C,unk090,unk094,unk098,unk09C,unk0A0,unk0A4,unk0A8,unk0AC,unk0B0,unk0B4,unk0B8,unk0BC,unk0C0,unk0C4,unk0C8,unk0CC,unk0D0,unk0D4,unk0D8,unk0DC,unk0E0,unk0E4,unk0E8,unk0EC,unk0F0,unk0F4,unk0F8,unk0FC,unk100,unk104,unk108,unk10C,unk110,unk114,unk118;
 Ptr<Task1236> task; bool FUN_00461a70(void*,int); bool FUN_004635f0();};
// pdb: Animation::SpecialIdleReplace | Animation.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: BSTempEffectSimpleDecal::CheckOcclusionQueryResults)
bool Owner1236::FUN_004635f0()
{
    Task1236* current = task.m_pObject;
    if (current && current->state == 1) {
        void* data = current->data;
        if (FUN_00461a70(data, 0)) {
            Task1236* old = task.m_pObject;
            if (old) {
                old->DecRef();
                task.m_pObject = 0;
            }
            return true;
        }
    }
    return false;
}
}   // namespace f3m_004635f0

// @f3 0x00472ce0 (community match, verified in this file)
namespace f3m_00472ce0 {

enum BIPED_OBJECT {
    BIPED_OBJECT_NONE = -1
};

struct Form {};
struct ArmorAddon {};
struct BipedModelList {};

struct BipedModelForm {
    bool FUN_00451f80(BIPED_OBJECT slot, bool bCheck, BipedModelList* pList);
};

struct Model {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual const char* GetPath();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void FUN_00459610(const char* path);
};

struct Scene;
struct Node;

struct BipedObject {
    Form* pParent;
    Model* m_pModel;
    Scene* m_pSceneObject;
    unsigned char bHasAnimation;
};

struct BipedAnim;

struct Player {
    bool FUN_0076cd40(BipedAnim* pBiped);
};

struct TaskQueue {
    void FUN_006f2440(Scene* pScene);
};

struct ModelLoader {
    void FUN_00429640(const char* path, bool a, bool b);
};

extern const char DAT_00f46078[];
extern const char DAT_00f494b8[];
extern Player* DAT_0107a104;
extern TaskQueue* DAT_0107a79c;
extern ModelLoader* DAT_0106ca70;
extern Model DAT_0106e350[20];

BipedModelForm* __cdecl FUN_00451da0(Form* pForm);
ArmorAddon* __cdecl FUN_00c0050a(Form* pObj, int unused, const void* fromType, const void* toType, int isRef);
bool __cdecl FUN_00724400();
void __cdecl FUN_00470770(Scene* pScene);

struct BipedAnim {
    Node* root;
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
    BipedObject object[20];

    bool FUN_00470a30(Model* pModel, char* pBuffer);
    void FUN_00471020(Scene* pScene);
    void FUN_00472c60(Form* pForm);

    __forceinline void RemovePart(BipedObject* pBipObject, bool bClear, Model* pModel) {
        if (pBipObject->m_pSceneObject) {
            FUN_00471020(pBipObject->m_pSceneObject);
            if (!FUN_00724400()) {
                FUN_00470770(pBipObject->m_pSceneObject);
            } else {
                DAT_0107a79c->FUN_006f2440(pBipObject->m_pSceneObject);
            }
            const char* path = pBipObject->m_pModel->GetPath();
            DAT_0106ca70->FUN_00429640(path, true, true);
            pBipObject->m_pSceneObject = 0;
        }
        if (bClear) {
            pBipObject->pParent = 0;
            pBipObject->m_pModel = pModel;
        }
    }

    __forceinline void RemovePart(BIPED_OBJECT eBipedObject, bool bClear, Model* pModel) {
        RemovePart(&object[eBipedObject], bClear, pModel);
    }

    __forceinline Model* Store1stPersonModel(BIPED_OBJECT eBipedObject, char* pModelFileName) {
        DAT_0106e350[eBipedObject].FUN_00459610(pModelFileName);
        return &DAT_0106e350[eBipedObject];
    }

    void FUN_00472ce0(Form* pForm, Model* pModel, BIPED_OBJECT eBipedObject);
};

// pdb: BipedAnim::SetBipedPart | BipedAnim.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apParent, apModel, aeObjectSlot
void BipedAnim::FUN_00472ce0(Form* pForm, Model* pModel, BIPED_OBJECT eBipedObject) {
    BipedModelForm* pBipedModel = FUN_00451da0(pForm);
    ArmorAddon* pArmorAddon = FUN_00c0050a(pForm, 0, DAT_00f46078, DAT_00f494b8, 0);
    char c1stPersonModelFileName[0x104];
    bool bHas1stPersonModel = false;
    if (pModel && DAT_0107a104->FUN_0076cd40(this)) {
        bHas1stPersonModel = FUN_00470a30(pModel, c1stPersonModelFileName);
    }
    if (pBipedModel) {
        for (unsigned int i = 0; i < 20; ++i) {
            if (pBipedModel->FUN_00451f80((BIPED_OBJECT)i, false, 0) && object[i].pParent != pForm) {
                if (object[i].pParent && FUN_00c0050a(object[i].pParent, 0, DAT_00f46078, DAT_00f494b8, 0)) {
                    RemovePart((BIPED_OBJECT)i, true, 0);
                } else {
                    FUN_00472c60(object[i].pParent);
                }
            }
        }
        for (unsigned int i = 0; i < 20; ++i) {
            if (pBipedModel->FUN_00451f80((BIPED_OBJECT)i, true, 0)) {
                if (bHas1stPersonModel) {
                    pModel = Store1stPersonModel((BIPED_OBJECT)i, c1stPersonModelFileName);
                }
                object[i].pParent = pForm;
                object[i].m_pModel = pModel;
                break;
            }
        }
    } else if (pArmorAddon) {
        RemovePart(eBipedObject, true, 0);
        if (bHas1stPersonModel) {
            pModel = Store1stPersonModel(eBipedObject, c1stPersonModelFileName);
        }
        object[eBipedObject].pParent = pForm;
        object[eBipedObject].m_pModel = pModel;
    }
}

}

// @f3 0x00478350 (community match, verified in this file)
namespace n478350 {
struct Extra_478 { int unk00, unk04, unk08; unsigned int flags; };
struct Controller_478 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void SetHidden(void* name, int value);
};
struct Data_478 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; Controller_478* controller; };
struct Node_478;
struct Parent_478;
struct Object_478 {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual Node_478* GetAsNiNode();
    int unk04;
    const char* name;
    int unk0C, unk10, unk14;
    Parent_478* parent;
    Extra_478* FUN_00824a50(void* key);
    void* FUN_00825200(void* rtti);
};
struct Node_478 : Object_478 {
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
    void* childrenVtbl;
    Object_478** children;
    unsigned short capacity;
    unsigned short count;
};
struct Parent_478 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc();
    virtual void ve0(); virtual void ve4();
    virtual void Update(Object_478* child);
};
extern Node_478* DAT_0106e99c;
extern Controller_478* DAT_0106e998;
extern void* DAT_0116d6e0;
extern char DAT_01091f04;
extern void* DAT_0106e810;
extern void* DAT_0106e814;
extern void* DAT_0106e818;
extern void* DAT_0106e81c;
extern const char DAT_00dc09a4[];
// pdb: RemoveEditorMarkers | GlobalFunc.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel), high
bool __cdecl RemoveEditorMarkers(Node_478* node)
{
    bool result = false;
    if (!node)
        return false;
    if (!DAT_0106e99c) {
        Extra_478* extra = node->FUN_00824a50(DAT_0116d6e0);
        if (extra && ((char)(extra->flags >> 5) & 1)) {
            DAT_0106e99c = node;
            Data_478* data = (Data_478*)node->FUN_00825200(&DAT_01091f04);
            if (data)
                DAT_0106e998 = data->controller;
        }
        if (!DAT_0106e99c)
            return false;
    }
    if (node->name && FUN_00c009eb(node->name, DAT_00dc09a4) == 0) {
        if (DAT_0106e998) {
            DAT_0106e998->SetHidden(DAT_0106e810, 0);
            DAT_0106e998->SetHidden(DAT_0106e814, 0);
            DAT_0106e998->SetHidden(DAT_0106e818, 0);
            DAT_0106e998->SetHidden(DAT_0106e81c, 0);
        }
        Parent_478* parent = node->parent;
        if (parent)
            parent->Update(node);
        if (DAT_0106e99c == node) {
            DAT_0106e99c = 0;
            DAT_0106e998 = 0;
        }
        return true;
    }
    for (unsigned int i = 0; i < node->count; i++) {
        Object_478* child = node->children[i];
        if (child) {
            Node_478* sub = child->GetAsNiNode();
            if (sub) {
                result = RemoveEditorMarkers(sub);
                if (result) {
                    if (DAT_0106e99c == node) {
                        DAT_0106e99c = 0;
                        DAT_0106e998 = 0;
                    }
                    return result;
                }
            }
        }
    }
    if (DAT_0106e99c == node) {
        DAT_0106e99c = 0;
        DAT_0106e998 = 0;
    }
    return result;
}
}

// @f3 0x00469bd0 (community match, verified in this file)
namespace f3m_00469bd0 {
struct AFPoint3 {
    float x;
    float y;
    float z;
};

struct AFVector4 {
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
    AFVector4& operator=(const AFVector4& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
        return *this;
    }
};

extern AFVector4 DAT_01092a50;

struct AFHavokBody {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AFVector4 position;
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
    AFVector4 velocity;
    void FUN_00469bd0(const AFPoint3& point);
};

// pdb: TESObjectCELL::Pick | TESObjectCELL.obj | fnv360_0721_beta, call_gap, low
// pdb params: arResult
void AFHavokBody::FUN_00469bd0(const AFPoint3& point)
{
    AFVector4 scaled;
    scaled.x = point.x * 0.1428767293691635;
    scaled.y = point.y * 0.1428767293691635;
    scaled.z = point.z * 0.1428767293691635;
    velocity = DAT_01092a50;
    position = scaled;
}
}   // namespace f3m_00469bd0

// @f3 0x00469050 (community match, verified in this file)
namespace f3m_00469050 {
struct Input1186 { float x,y,z; };
struct __declspec(align(16)) Vector1186 {
 float x,y,z,w;
 Vector1186(const Input1186& input):x(input.x*0.1428767293691635),y(input.y*0.1428767293691635),z(input.z*0.1428767293691635){}
};
struct Output1186 { float x,y,z,w; void FUN_00469050(const Input1186*); };
void Output1186::FUN_00469050(const Input1186* input) {
 Vector1186 value(*input);
 x=value.x; y=value.y; z=value.z; w=value.w;
}
}   // namespace f3m_00469050

// @f3 0x0046e750 (community match, verified in this file)
namespace f3m_0046e750 {
struct __declspec(align(16)) ChildBuffer
{
    char name[512];
};

struct Node;

struct TileWorkList
{
    virtual void vf00();
    virtual void vf04();
    virtual int GetFirst();
    virtual int GetNext(int index);
    virtual void vf10();
    virtual Node* GetAt(int index, ChildBuffer* buffer);
};

struct Node
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual TileWorkList* GetChildren();

    unsigned unk04,unk08;int kind;int FUN_0043b230(){return kind;}
};

// @fnv 0x004a9240
// pdb: BGSSceneInfo::GetHavokFaceCount | BGSSceneInfo.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apShape
int __cdecl FUN_0046e750(Node* node)
{
    if (node == 0)
        return 0;
    int count = 0;
    switch (node->FUN_0043b230())
    {
    case 4:
        return 1;
        break;
    case 11: {
        Node* obj = node;
        TileWorkList* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += FUN_0046e750(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    case 10: {
        Node* obj = node;
        TileWorkList* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += FUN_0046e750(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    case 21: {
        Node* obj = node;
        TileWorkList* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += FUN_0046e750(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    case 22: {
        Node* obj = node;
        TileWorkList* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += FUN_0046e750(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    default:
        return 10;
    }
}
}   // namespace f3m_0046e750

// @f3 0x0046b830 (community match, verified in this file)
// FO3 0x0046b830: decal spray task update (FNV ImpactTask::FUN_004a2d50, BGSDecalManager.cpp).
#include <math.h>
void SetSelectionMask(unsigned int uiIndexA, unsigned int uiIndexB, bool bSelected);
extern float DAT_01018f5c;

namespace N46b830 {

struct NiPoint3
{
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    NiPoint3 operator+(const NiPoint3& o) const { return NiPoint3(x + o.x, y + o.y, z + o.z); }
    NiPoint3 operator-(const NiPoint3& o) const { return NiPoint3(x - o.x, y - o.y, z - o.z); }
    NiPoint3 ApplyScaled(float s) const { return NiPoint3(x * s, y * s, z * s); }
    float Length() const { return (float)sqrt(x * x + y * y + z * z); }
    void Unitize();
};

// 0x468d00: NiPoint3::Unitize, same file.
__declspec(noinline) void NiPoint3::Unitize()
{
    float len = Length();
    if (len > 1e-06f)
    {
        float inv = 1.0f / len;
        x *= inv;
        y *= inv;
        z *= inv;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}

// 0x468cd0: scalar times point, same file.
__declspec(noinline) inline NiPoint3 __cdecl ScalePoint(float s, const NiPoint3& p)
{
    return NiPoint3(p.x * s, p.y * s, p.z * s);
}

struct NiMatrix3
{
    float m_pEntry[3][3];
    void GetRow(int i, NiPoint3& r) const
    {
        r.x = m_pEntry[i][0];
        r.y = m_pEntry[i][1];
        r.z = m_pEntry[i][2];
    }
};

struct Node3D
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
    NiMatrix3 m_kRotate;
    NiPoint3 m_kTranslate;
    NiMatrix3* GetRotate() { return &m_kRotate; }
    NiPoint3& GetTranslate() { return m_kTranslate; }
};

struct World
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
    virtual void v048();
    virtual void v049();
    virtual bool PickObject(void* apPick);
};

struct Cell
{
    World* GetWorld();
};

struct TempEffect
{
    int unk00;
    int unk04;
    float fLifetime;
    Cell* pCell;
    float fAge;
    int unk14;
    Node3D* p3D;
    Cell* GetParentCell() { return pCell; }
    Node3D* Get3D() { return p3D; }
    float GetAge() { return fAge; }
    float GetLifetime() { return fLifetime; }
};

struct EffectHandle
{
    TempEffect* pObject;
    TempEffect* Get() { return pObject; }
};

struct ImpactData
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
    float fShininess;
    float fScale;
    int unk40;
    int unk44;
    void* pTexture;
    int unk4c;
    int unk50;
    float fMinWidth;
    float fMaxWidth;
    int unk5c;
    int unk60;
    int unk64;
    float fParallax;
    float fRadius;
    bool bFlag70;
    unsigned char cFlags;
    unsigned char unk72;
    unsigned char unk73;
    unsigned int uiColor;
    float GetMinWidth() { return fMinWidth; }
    float GetMaxWidth() { return fMaxWidth; }
    void* GetTexture() { return pTexture; }
    bool GetFlag0() { return cFlags & 1; }
    float GetRadius() { return fRadius; }
    bool GetFlag70() { return bFlag70; }
    bool GetFlag2() { return (cFlags >> 2) & 1; }
    bool GetFlag1() { return (cFlags >> 1) & 1; }
    float GetParallax() { return fParallax; }
    float GetShininess() { return fShininess; }
    float GetScale() { return fScale; }
    unsigned int GetColor() { return uiColor; }
};

struct ConsoleManager
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
    signed char cVisible;
    static ConsoleManager* __cdecl Instance(bool abCreate);
    bool IsVisible() { return cVisible > 0; }
};

struct StartMenu
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
    unsigned int uiFlags;
};
extern StartMenu* DAT_010770ac;
inline bool IsStartMenuFlag1Set()
{
    StartMenu* m = DAT_010770ac;
    return m && (m->uiFlags & 1);
}

struct Splatter
{
    void SetUnk(int);
    void SetWorld(World* apWorld);
    void SetLayerMask(int aiLayer, unsigned char abValue) { SetSelectionMask(0x27, aiLayer, abValue != 0); }
};
Splatter* __cdecl CreateSplatter(float afRadius, bool abFlag);

struct FloatSetting
{
    float* Get();
};
struct IntSetting
{
    int* Get();
};
extern FloatSetting DAT_00f4b198;
extern FloatSetting DAT_00f4b1a4;
extern IntSetting DAT_00f4b1b0;

struct Color
{
    float r, g, b, a;
    Color(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};
void* __cdecl DebugLine(const NiPoint3& a, const Color& ca, const NiPoint3& b, const Color& cb, bool abFlag);

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
};

struct Shape
{
    unsigned int GetMaterial(unsigned int auiKey);
};
struct ShapeRef
{
    int unk00;
    int unk04;
    Shape* pShape;
    Shape* GetShape() { return pShape; }
};
inline Shape* GetShapeOf(ShapeRef* apRef)
{
    if (apRef)
        return apRef->GetShape();
    return 0;
}

struct HitBody
{
    ShapeRef* pRef;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int uiFilter;
    ShapeRef* GetRef() { return pRef; }
    unsigned int GetFilter() { return uiFilter; }
};

struct CFilter
{
    unsigned int iFilter;
    CFilter(unsigned int f) : iFilter(f) {}
    void SetLayer(int aeLayer)
    {
        iFilter &= ~0x7f;
        iFilter |= (aeLayer & 0x7f);
    }
    unsigned int GetGroup() { return (iFilter >> 16) & 0xFFFF; }
};

struct RayHit
{
    hkVector4 normal;
    float fraction;
    int extraInfo;
    int unk18;
    int unk1c;
    unsigned int keys[8];
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    HitBody* body;
    int unk54;
    int unk58;
    int unk5c;
};

struct HitArray
{
    RayHit* data;
    int size;
    int capacity;
    RayHit* GetEntryAt(int i) { return &data[i]; }
    int GetSize() { return size; }
};

struct AllCollector
{
    void* vtbl;
    float earlyOut;
    int unk08;
    int unk0c;
    HitArray hits;
    int unk1c;
    RayHit storage[8];
    AllCollector();
    ~AllCollector();
    HitArray* GetHits() { return &hits; }
};

struct PickData
{
    hkVector4 from;
    hkVector4 to;
    bool bEnableShapeCollectionFilter;
    unsigned int uiFilterInfo;
    int unk28;
    int unk2c;
    RayHit output;
    hkVector4 collisionFilter;
    char* pAabbCache;
    void* pClosestCollector;
    AllCollector* pAllCollector;
    bool bPickFailed;
    PickData();
    void SetFrom(const NiPoint3& arFrom);
    void SetTo(const NiPoint3& arTo);
    void SetFilter(unsigned int f) { uiFilterInfo = f; }
    void SetAllCollector(AllCollector* apCollector)
    {
        pAllCollector = apCollector;
        pClosestCollector = 0;
    }
    AllCollector* GetAllCollector() { return pAllCollector; }
};

struct Ref
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Ref* pParent;
    Ref* GetParent() { return pParent; }
};
Ref* __cdecl BodyToRef(HitBody* apBody);
void* __cdecl RefToObject(Ref* apRef);
bool __cdecl IsAcousticSpaceFormTypeAllowed(void* apObject, bool abFlag);
float __cdecl RandomFloat(float lo, float hi);
float __cdecl DecalLifetime();
float __cdecl FloorF(float v);

struct DecalData
{
    NiPoint3 position;
    NiPoint3 normal;
    NiPoint3 tangent;
    int unk24;
    Ref* reference;
    int unk2c;
    void* texture;
    int unk34;
    float width;
    float height;
    float depth;
    float lifetime;
    void* owner;
    float radius;
    int unk50;
    float parallax;
    float shininess;
    float scale;
    NiPoint3 color;
    int unk6c;
    unsigned char rotation;
    unsigned char unk71;
    unsigned char unk72;
    unsigned char flag73;
    unsigned char flag74;
    unsigned char flag75;
    unsigned char flag76;
    unsigned char unk77;
    int unk78;
    int unk7c;
    DecalData();
};

struct DecalOwner
{
    void AddDecal(DecalData* apData, int aiType, char acFlag);
};

struct TES
{
    void AddDebugObject(void* apObject, float afTime);
    Ref* GetLandRef(const NiPoint3& arPos);
    DecalOwner* GetDecalOwner(NiPoint3 kPos);
};
extern TES* DAT_0107a0d8;

struct ImpactTask
{
    int remaining;
    bool finished;
    ImpactData* impact;
    EffectHandle reference;
    void FUN_0046b830();
};

// pdb: BGSDecalEmitter::Update | BGSDecalManager.obj | fnv360_0822_retail, call_gap, low
void ImpactTask::FUN_0046b830()
{
    if (ConsoleManager::Instance(true)->IsVisible() || IsStartMenuFlag1Set())
        return;
    if (!reference.Get()->GetParentCell() || !reference.Get()->Get3D())
    {
        finished = true;
        return;
    }
    if (remaining > 0 && impact && reference.Get()->GetAge() <= reference.Get()->GetLifetime())
    {
        NiPoint3 direction;
        reference.Get()->Get3D()->GetRotate()->GetRow(2, direction);
        direction.Unitize();
        NiPoint3 origin = reference.Get()->Get3D()->GetTranslate();
        float radius = RandomFloat(impact->GetMinWidth(), impact->GetMaxWidth());
        Splatter* splatter = CreateSplatter(radius, true);
        splatter->SetUnk(0);
        splatter->SetLayerMask(8, 0);
        splatter->SetLayerMask(29, 0);
        Cell* cell = reference.Get()->GetParentCell();
        World* world = cell ? cell->GetWorld() : 0;
        PickData ray;
        if (world)
        {
            splatter->SetWorld(world);
            float distance = *DAT_00f4b198.Get();
            NiPoint3 end = origin + direction.ApplyScaled(distance);
            end.x += RandomFloat(-20.0f, 20.0f);
            end.y += RandomFloat(-20.0f, 20.0f);
            end.z += RandomFloat(-20.0f, 20.0f);
            float drop = -*DAT_00f4b1a4.Get() * (reference.Get()->GetAge() / reference.Get()->GetLifetime());
            end.z += drop;
            if (*DAT_00f4b1b0.Get() > 0)
            {
                void* line = DebugLine(origin, Color(0, 1, 0, 1), end, Color(0, 1, 1, 1), true);
                DAT_0107a0d8->AddDebugObject(line, DAT_01018f5c);
            }
            CFilter filter(0);
            filter.SetLayer(39);
            ray.SetFilter(filter.iFilter);
            ray.SetFrom(origin);
            ray.SetTo(end);
            AllCollector collector;
            ray.SetAllCollector(&collector);
            bool rayHit = world->PickObject(&ray);
            int count = ray.GetAllCollector()->GetHits()->GetSize();
            bool placed = false;
            for (int hit = 0; !placed && hit < count; ++hit)
            {
                HitBody* body = ray.GetAllCollector()->GetHits()->GetEntryAt(hit)->body;
                if (body)
                {
                    unsigned int key = -1;
                    for (int keyIndex = 0;
                         keyIndex < 8 && ray.GetAllCollector()->GetHits()->GetEntryAt(hit)->keys[keyIndex] != -1;
                         ++keyIndex)
                    {
                        key = ray.GetAllCollector()->GetHits()->GetEntryAt(hit)->keys[keyIndex];
                    }
                    Shape* shape = GetShapeOf(body->GetRef());
                    if (!shape)
                        continue;
                    unsigned int material = shape->GetMaterial(key);
                    void* texture = impact ? impact->GetTexture() : 0;
                    if (!texture)
                        continue;
                    NiPoint3 position =
                        origin + ScalePoint(ray.GetAllCollector()->GetHits()->GetEntryAt(hit)->fraction, end - origin);
                    NiPoint3 normal;
                    {
                        const hkVector4& v = ray.GetAllCollector()->GetHits()->GetEntryAt(hit)->normal;
                        normal.x = v.x;
                        normal.y = v.y;
                        normal.z = v.z;
                    }
                    bool landscape = CFilter(body->GetFilter()).GetGroup() == 1;
                    Ref* target = 0;
                    if (landscape)
                    {
                        target = DAT_0107a0d8->GetLandRef(position);
                        if (target && target->GetParent())
                            target = target->GetParent();
                    }
                    else
                        target = BodyToRef(body);
                    void* object = RefToObject(target);
                    if (!landscape && (!object || !IsAcousticSpaceFormTypeAllowed(object, true)))
                        continue;
                    DecalOwner* owner = DAT_0107a0d8->GetDecalOwner(position);
                    DecalData decal;
                    decal.position = position;
                    decal.normal = normal;
                    decal.width = radius;
                    decal.height = radius;
                    decal.depth = 48.0f;
                    decal.lifetime = DecalLifetime();
                    decal.rotation = (unsigned char)FloorF(RandomFloat(0, 4.0f));
                    decal.reference = target;
                    decal.texture = texture;
                    decal.flag73 = impact->GetFlag0();
                    decal.radius = impact->GetRadius();
                    decal.flag76 = impact->GetFlag70();
                    decal.flag74 = impact->GetFlag2();
                    decal.flag75 = impact->GetFlag1();
                    decal.parallax = impact->GetParallax();
                    decal.shininess = impact->GetShininess();
                    decal.scale = impact->GetScale();
                    decal.color = NiPoint3((unsigned char)(impact->GetColor() & 255) / 255.0,
                                           (unsigned char)(((unsigned short)impact->GetColor() >> 8) & 255) / 255.0,
                                           (unsigned char)((impact->GetColor() >> 16) & 255) / 255.0);
                    owner->AddDecal(&decal, 1, 0);
                    placed = true;
                }
            }
            if (placed)
                --remaining;
        }
    }
    else
        finished = true;
}

}  // namespace N46b830

// @f3 0x00474e90 (community match, verified in this file)
namespace f3m_00474e90 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
namespace w5_00474e90
{
struct RefObject
{
    virtual ~RefObject();
    virtual void DeleteThis();
    long volatile refCount;
};
struct RefPtr
{
    RefObject* object;
    RefPtr(RefObject* p = 0) : object(p) {}
    ~RefPtr()
    {
        if (object && !::InterlockedDecrement(&object->refCount))
            object->DeleteThis();
    }
    bool operator==(const RefPtr& other) const { return object == other.object; }
    bool operator!=(const RefPtr& other) const { return object != other.object; }
};
struct RefList
{
    RefPtr item;
    RefList* next;
    void FUN_008fa360();
    void FUN_005e4e20();
    ~RefList() { FUN_005e4e20(); }
    __forceinline bool IsEmpty() const
    {
        RefPtr none;
        if (!next && item == none)
            return true;
        return false;
    }
    __forceinline void RemoveAll()
    {
        while (!IsEmpty())
            FUN_008fa360();
    }
};
struct FUN_00474e90
{
    void* header;
    RefList list;
    ~FUN_00474e90();
};
// pdb: BSClonePools::ClonePool::~ClonePool | BSClonePool.obj | fnv360_0721_beta, objrun, medium
FUN_00474e90::~FUN_00474e90()
{
    header = 0;
    list.RemoveAll();
}
}
}   // namespace f3m_00474e90

// @f3 0x00475f70 (community match, verified in this file)
namespace f3m_00475f70 {
namespace task2267 {
struct Rect { long left,top,right,bottom; };
struct Pt {
 float x,y,z;
 Pt() {}
 Pt(float a,float b,float c):x(a),y(b),z(c) {}
 Pt operator-(const Pt& b) const { return Pt(x-b.x,y-b.y,z-b.z); }
 Pt operator+(const Pt& b) const { return Pt(x+b.x,y+b.y,z+b.z); }
 Pt FUN_004229a0(const Pt&) const;
 void FUN_00468d00();
 float FUN_00432bd0() const;
};
// @fnv 0x004b1e80
bool FUN_00475f70(const Rect* aTestRect, const Pt* aStartPt, const Pt* aEndPt,
                  Pt* aOutputIntersectPt)
{
    bool bIntersect = false;

    if (aTestRect->left >= aTestRect->right)
        return false;
    if (aTestRect->bottom >= aTestRect->top)
        return false;
    if (aStartPt->x < aTestRect->left && aEndPt->x < aTestRect->left)
        return false;
    if (aStartPt->y < aTestRect->bottom && aEndPt->y < aTestRect->bottom)
        return false;
    if (aStartPt->x > aTestRect->right && aEndPt->x > aTestRect->right)
        return false;
    if (aStartPt->y > aTestRect->top && aEndPt->y > aTestRect->top)
        return false;
    if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right && aStartPt->y > aTestRect->bottom &&
        aStartPt->y < aTestRect->top && aEndPt->x > aTestRect->left && aEndPt->x < aTestRect->right &&
        aEndPt->y > aTestRect->bottom && aEndPt->y < aTestRect->top)
        return false;

    if (aEndPt->x == aStartPt->x || aEndPt->y == aStartPt->y)
    {
        if (aEndPt->x == aStartPt->x && aEndPt->y == aStartPt->y)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left && aStartPt->y <= aTestRect->top &&
                aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                *aOutputIntersectPt = *aStartPt;
            }
        }
        else if (aEndPt->x == aStartPt->x)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left)
            {
                bIntersect = true;
                if (aStartPt->y > aEndPt->y)
                    *aOutputIntersectPt = Pt(aStartPt->x, aTestRect->top, 0.0f);
                else
                    *aOutputIntersectPt = Pt(aStartPt->x, aTestRect->bottom, 0.0f);
            }
        }
        else if (aEndPt->y == aStartPt->y)
        {
            if (aStartPt->y <= aTestRect->top && aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                if (aStartPt->x > aEndPt->x)
                    *aOutputIntersectPt = Pt(aTestRect->right, aStartPt->y, 0.0f);
                else
                    *aOutputIntersectPt = Pt(aTestRect->left, aStartPt->y, 0.0f);
            }
        }
    }
    else
    {
        int intersectsFound = 0;
        Pt intersect1(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        Pt intersect2(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        float slope = (aEndPt->y - aStartPt->y) / (aEndPt->x - aStartPt->x);
        float intercept = aEndPt->y - aEndPt->x * slope;

        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->left * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = Pt(aTestRect->left, YatBorder, 0.0f);
                else
                    intersect2 = Pt(aTestRect->left, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->top - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = Pt(XatBorder, aTestRect->top, 0.0f);
                else
                    intersect2 = Pt(XatBorder, aTestRect->top, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->right * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = Pt(aTestRect->right, YatBorder, 0.0f);
                else
                    intersect2 = Pt(aTestRect->right, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->bottom - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = Pt(XatBorder, aTestRect->bottom, 0.0f);
                else
                    intersect2 = Pt(XatBorder, aTestRect->bottom, 0.0f);
                intersectsFound++;
            }
        }

        if (intersectsFound)
        {
            bIntersect = true;
            if (intersectsFound == 2)
            {
                if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right &&
                    aStartPt->y > aTestRect->bottom && aStartPt->y < aTestRect->top)
                {
                    Pt linevect = aEndPt->FUN_004229a0(*aStartPt);
                    Pt intersect1vect = intersect1 - *aStartPt;
                    linevect.z = 0.0f;
                    intersect1vect.z = 0.0f;
                    linevect.FUN_00468d00();
                    intersect1vect.FUN_00468d00();
                    if ((linevect + intersect1vect).FUN_00432bd0() > 1.0)
                        *aOutputIntersectPt = intersect1;
                    else
                        *aOutputIntersectPt = intersect2;
                }
                else
                {
                    Pt delta1=intersect1-*aStartPt;
                    Pt delta2=intersect2-*aStartPt;
                    float distance1=delta1.FUN_00432bd0();
                    if(delta2.FUN_00432bd0()>distance1) *aOutputIntersectPt=intersect1;
                    else *aOutputIntersectPt=intersect2;
                }
            }
            else
            {
                *aOutputIntersectPt = intersect1;
            }
        }
    }
    return bIntersect;
}

}
}   // namespace f3m_00475f70

// @f3 0x00469ce0 (community match, verified in this file)
#include <string.h>

namespace f3m_00469ce0 {

void __cdecl FUN_00887da0(const char* format, ...);
void* __cdecl FUN_0089eb90(unsigned int bytes);

extern int DAT_0106def4;
extern int DAT_0106df74;
extern bool DAT_0106dfe0;
extern bool DAT_0106df8c;
extern char DAT_0108f414[];
extern char DAT_0107000c[];

struct DecalNode;
bool __cdecl FUN_00424d20(const void* apRTTI, DecalNode* apObject);
bool __cdecl FUN_004343e0(const void* apRTTI, DecalNode* apObject);

struct DecalSetting
{
    float FUN_00432b20();
};
extern DecalSetting DAT_0106df58;

struct DecalFlags
{
    bool FUN_00468ec0(unsigned int index);
};

struct DecalData
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
    virtual unsigned short GetVertexCount();
};

struct DecalTarget
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
    NiPoint3 kWorldPos;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    float fRadius;
};

struct DecalTargetList
{
    DecalTarget* pItem;
    DecalTargetList* pNext;
    bool IsEmpty() const { return !pNext && !pItem; }
};

struct DecalNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual DecalNode* IsNode();
    int unk04;
    const char* pName;
    int unk0C;
    int unk10;
    int unk14;
    DecalNode* pParent;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int uiFlags;
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
    DecalNode** ppChildren;
    unsigned short usMaxSize;
    unsigned short usSize;
    DecalFlags* pFlags;
    DecalTargetList* pTargets;
    int unkB0;
    int unkB4;
    DecalData* pData;
    unsigned short GetVertexCount() { return pData->GetVertexCount(); }
    bool IsCulled() const { return (uiFlags & 1) != 0; }
    unsigned int GetArrayCount() const { return usSize; }
    DecalNode* GetAt(unsigned int i) const { return ppChildren[i]; }
};

inline NiPoint3 Sub(const NiPoint3& a, const NiPoint3& b)
{
    return NiPoint3(a.x - b.x, a.y - b.y, a.z - b.z);
}
inline NiPoint3 MultiplyComponents(const NiPoint3& a, const NiPoint3& b)
{
    return NiPoint3(a.x * b.x, a.y * b.y, a.z * b.z);
}

struct DecalRequest
{
    NiPoint3 kPos;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    DecalNode* pNode;
    int unk2C;
    int unk30;
    int unk34;
    float fWidth;
    float fHeight;
    int unk40;
    int unk44;
    void* pAddToList;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    float fDistScale;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    unsigned short unk70;
    unsigned char bLOD;
};

struct SimpleDecal
{
    SimpleDecal(DecalNode* apTarget, float afLifetime, DecalRequest* apRequest);
    static void* operator new(unsigned int auiSize) { return FUN_0089eb90(auiSize); }
    static void operator delete(void* apMem);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short unk18;
    unsigned char bFlag1a;
    unsigned char bFlag1b;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
};

struct DecalPtr
{
    DecalPtr(SimpleDecal* apDecal);
    ~DecalPtr();
    SimpleDecal* p;
};

struct DecalList
{
    void FUN_00827100(const DecalPtr& arPtr);
};

struct DecalManager
{
    int unk00;
    unsigned char ucFlag;
    unsigned char unk05;
    unsigned short unk06;
    DecalList kList;
    bool FUN_00469ce0(DecalRequest* apRequest);
};

// pdb: BGSDecalManager::AddGeometryDecalRecurse | BGSDecalManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: arDecalData
bool DecalManager::FUN_00469ce0(DecalRequest* apRequest)
{
    if (DAT_0106def4 >= DAT_0106df74)
    {
        if (DAT_0106dfe0)
            FUN_00887da0("DECAL: Reached max non-skinned decals per frame. Ignoring decal.");
        return false;
    }
    if (apRequest->pNode)
    {
        const char* pName = apRequest->pNode->pName;
        if (pName != 0 && (strncmp(pName, "Decal Node", 10) == 0 || strncmp(pName, "Decal", 5) == 0 ||
                           strncmp(pName, "FaceGen", 7) == 0 || strncmp(pName, "Bip01", 5) == 0 ||
                           strncmp(pName, "Debug Decal Box", 15) == 0))
            return true;
        if (FUN_00424d20(DAT_0108f414, apRequest->pNode) && !apRequest->pNode->IsCulled())
        {
            DecalNode* pGeom = apRequest->pNode;
            if (pGeom != 0)
            {
                DecalFlags* pFlags = pGeom->pFlags;
                if (pFlags != 0 && pFlags->FUN_00468ec0(0x1a))
                    return true;
            }
            DecalNode* pParent = pGeom->pParent;
            DecalNode* pHit = 0;
            bool bFound = false;
            if (pParent != 0)
            {
                for (unsigned int i = 0; i < pParent->GetArrayCount(); i++)
                {
                    DecalNode* pChild = pParent->GetAt(i);
                    if (pChild != 0)
                    {
                        if (FUN_004343e0(DAT_0107000c, pChild))
                        {
                            bFound = true;
                            pHit = pChild;
                            break;
                        }
                    }
                }
            }
            else
            {
                return false;
            }
            if (bFound && apRequest->fDistScale > 0.0f)
            {
                DecalTargetList* pList = pHit->pTargets;
                while (pList != 0 && !pList->IsEmpty())
                {
                    DecalTarget* pTarget = pList->pItem;
                    pList = pList->pNext;
                    NiPoint3 kPos = pTarget->kWorldPos;
                    float fRadius = pTarget->fRadius;
                    NiPoint3 kDelta = Sub(apRequest->kPos, kPos);
                    kDelta = MultiplyComponents(kDelta, kDelta);
                    float fSize;
                    if (apRequest->fWidth > apRequest->fHeight)
                        fSize = apRequest->fWidth;
                    else
                        fSize = apRequest->fHeight;
                    double fReach = fSize + fRadius;
                    fReach = fReach * fReach;
                    if (kDelta.x + kDelta.y + kDelta.z <= fReach / apRequest->fDistScale)
                        return false;
                }
            }
            DAT_0106def4++;
            if (DAT_0106dfe0)
                FUN_00887da0("DECAL: Non-Skinned decal count this frame: #%d", DAT_0106def4);
            SimpleDecal* pDecal = new SimpleDecal(pHit, DAT_0106df58.FUN_00432b20(), apRequest);
            DecalNode* p4 = apRequest->pNode;
            if (p4->GetVertexCount() > 0x3e8 && DAT_0106df8c && apRequest->bLOD)
            {
                pDecal->bFlag1a = 1;
                pDecal->bFlag1b = ucFlag;
                ucFlag = 0;
            }
            if (apRequest->pAddToList)
                kList.FUN_00827100(pDecal);
        }
        else if (apRequest->pNode->IsNode())
        {
            DecalNode* pNode = apRequest->pNode;
            if (pNode != 0 && pNode->IsCulled())
                return true;
            for (unsigned int i = 0; i < pNode->GetArrayCount(); i++)
            {
                DecalNode* pChild = pNode->GetAt(i);
                if (pChild != 0)
                {
                    apRequest->pNode = pChild;
                    FUN_00469ce0(apRequest);
                }
            }
        }
    }
    return true;
}

}  // namespace f3m_00469ce0

// @f3 0x0047b5a0 (community match, verified in this file)
extern bool DAT_0106ea1c;
namespace f3m_0047b5a0 {
namespace f3m_0047b5a0 {
void __cdecl FUN_004d7360(float t);
class GridCell { public: void TESObjectCELL_UpdateManagedNodes(float t, bool off); };
class CellGrid
{
public:
    int unk00; int unk04; int unk08;
    unsigned int width;
    GridCell** cells;
    GridCell** At(unsigned int x, unsigned int y)
    {
        if (x < width && y < width)
            return &cells[x * width + y];
        return 0;
    }
    void FUN_0047b5a0(float t);
};
// pdb: GridCellArray::UpdateManagedNodes | GridCell.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: GridCellArray::UpdateManagedNodeTransforms)
// pdb params: afTime
void CellGrid::FUN_0047b5a0(float t)
{
    FUN_004d7360(t);
    unsigned int size = width;
    DAT_0106ea1c = !DAT_0106ea1c;
    for (unsigned int x = 0; x < size; ++x)
    {
        for (unsigned int y = 0; y < size; ++y)
        {
            bool update = true;
            unsigned int last = size - 1;
            if (!x || !y || x == last || y == last)
            {
                if ((x ^ y) & 1)
                    update = false;
                if (DAT_0106ea1c)
                    update = !update;
            }
            GridCell* cell = *At(x, y);
            if (cell)
                cell->TESObjectCELL_UpdateManagedNodes(t, !update);
        }
    }
}
}
}   // namespace f3m_0047b5a0

// @f3 0x004780d0 (community match, verified in this file)
namespace f3m_004780d0 {
struct WorldObject
{
    void* vtable;
    unsigned int memSizeAndFlags;
    void* world;
    struct UserObject* userData;
};
struct UserObject
{
    void* FUN_008f9c90(int value);
};
struct Entity
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C;
    float x;
    float y;
    float z;
};
struct Collidable
{
    void* shape;
    unsigned int shapeKey;
    void* motion;
    const Collidable* parent;
    signed char ownerOffset;
    signed char forceCollideOntoPpu;
    unsigned short shapeSizeOnSpu;
    unsigned int broadPhaseId;
    signed char type;
    signed char broadPhaseOwnerOffset;
    unsigned short objectQualityType;
    unsigned int collisionFilterInfo;
};
struct NiRef
{
    void* vtable;
    unsigned int refCount;
    void* object;
};
struct Box
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* object;
};
struct Manager
{
    Box* TES_GetLandGeometry(float* position);
};
extern Manager* DAT_0107a0d8;
extern const double DAT_00db88e8;
inline Entity* GetRigidBody(const Collidable* c)
{
    if (c->type == 1)
        return (Entity*)((char*)c + c->ownerOffset);
    return 0;
}
inline WorldObject* GetPhantom(const Collidable* c)
{
    if (c->type == 2)
        return (WorldObject*)((char*)c + c->ownerOffset);
    return 0;
}
}
using namespace f3m_004780d0;
NiRef* __cdecl FUN_004779d0(Entity* body);
NiRef* __cdecl FUN_00477a30(WorldObject* phantom);
// pdb: GetAVObjectForCollidable | GlobalFunc.obj | fnv360_0822_retail, call_gap, low
// pdb params: aphkCol
void* __cdecl FUN_004780d0(Collidable* collidable)
{
    void* result = 0;
    if (collidable) {
        Entity* body = GetRigidBody(collidable);
        WorldObject* phantom = body ? 0 : GetPhantom(collidable);
        if (body) {
            NiRef* ref = FUN_004779d0(body);
            if (ref)
                result = ref->object;
            else if ((collidable->collisionFilterInfo & 0xffff0000) == 0x10000) {
                float pos[3];
                pos[0] = (float)(body->x * DAT_00db88e8);
                pos[1] = (float)(body->y * DAT_00db88e8);
                // scale first: the original multiplies z the other way round
                pos[2] = (float)(DAT_00db88e8 * body->z);
                Box* box = f3m_004780d0::DAT_0107a0d8->TES_GetLandGeometry(pos);
                if (box && box->object)
                    result = box->object;
            }
        } else {
            NiRef* ref = FUN_00477a30(phantom);
            if (ref)
                result = ref->object;
            if (!result && phantom && phantom->userData)
                result = phantom->userData->FUN_008f9c90(0);
        }
    }
    return result;
}

// @f3 0x00471ef0 (community match, verified in this file)
#include <windows.h>
namespace ModelAttach471ef0 {
extern long (__stdcall* DAT_00d9b064)(long*);
extern long (__stdcall* DAT_00d9b068)(long*);
struct Scene;
struct TextureSwap { void TESModelTextureSwap_SwapTextures(Scene*); };
struct Model {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual const char* GetModelFilePath();
    virtual void Slot18();
    virtual TextureSwap* GetAsModelTextureSwap();
};
struct Form {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0c();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1c();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2c();
    virtual void Slot30(); virtual void Slot34(); virtual void Slot38(); virtual void Slot3c();
    virtual void Slot40(); virtual void Slot44(); virtual void Slot48(); virtual void Slot4c();
    virtual void Slot50(); virtual void Slot54(); virtual void Slot58(); virtual void Slot5c();
    virtual void Slot60(); virtual void Slot64(); virtual void Slot68(); virtual void Slot6c();
    virtual void Slot70(); virtual void Slot74(); virtual void Slot78(); virtual void Slot7c();
    virtual void Slot80(); virtual void Slot84(); virtual void Slot88(); virtual void Slot8c();
    virtual void Slot90(); virtual void Slot94(); virtual void Slot98(); virtual void Slot9c();
    virtual void Slota0(); virtual void Slota4(); virtual void Slota8(); virtual bool CheckUpdate();
};
struct Actor { Scene* FUN_00424eb0(); };
struct CloneContext {
    unsigned unk00, unk04, unk08, unk0c;
    float x,y,z;
    CloneContext(float scale) { FUN_00471550(scale); }
    ~CloneContext() { FUN_00470870(); }
    void FUN_00471550(float);
    void FUN_00470870();
};
struct Point { unsigned x,y,z; };
struct Matrix { float m[3][3]; };
struct Scene {
    virtual void Slot00(); virtual void Delete(); virtual void Slot08(); virtual Scene* IsSceneNode();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1c();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2c();
    virtual void Slot30(); virtual void Slot34(); virtual void Slot38(); virtual void Slot3c();
    virtual void Slot40(); virtual void Slot44(); virtual void Slot48(); virtual void Slot4c();
    virtual void Slot50(); virtual void Slot54(); virtual void Slot58(); virtual void Slot5c();
    virtual void Slot60(); virtual void Slot64(); virtual void Slot68(); virtual void Slot6c();
    virtual void Slot70(); virtual void Slot74(); virtual void Slot78(); virtual void Slot7c();
    virtual void Slot80(); virtual void Slot84(); virtual void Slot88(); virtual void Slot8c();
    virtual void Slot90(); virtual void Slot94(); virtual void Slot98(); virtual void Slot9c();
    virtual void Slota0(); virtual void Slota4(); virtual void Slota8(); virtual void Slotac();
    virtual void Slotb0(); virtual void Slotb4(); virtual void Slotb8(); virtual void Slotbc();
    virtual void Slotc0(); virtual void Slotc4(); virtual void Slotc8(); virtual void Slotcc();
    virtual void Slotd0(); virtual void Slotd4(); virtual void Slotd8(); virtual void AddObject(Scene*,bool);
    long refs;
    const char* name;
    unsigned unk0c,unk10,unk14;
    Scene* parent;
    unsigned unk1c,unk20,unk24,unk28,unk2c,unk30;
    Matrix rotation;
    Point translation;
    Scene* FUN_008257a0(CloneContext*);
    Scene* FUN_00824a50(const void*);
    void FUN_00824c30();
    void FUN_008248c0(const void*,Scene*);
    void FUN_00ad2840(int);
    void FUN_008268a0();
    const char* GetName() const { return name; }
};
struct Retained {
    Scene* object;
    Retained():object(0) {}
    explicit Retained(Scene* p) { FUN_0045c640(p); }
    ~Retained() { FUN_00424aa0(); }
    __declspec(noinline) Retained* FUN_0045c640(Scene* p) {
        object=p;
        if(p) DAT_00d9b068(&p->refs);
        return this;
    }
    void FUN_00424aa0();
    void FUN_008e9650(Scene*);
    Scene* const& Get() const { return object; }
    __forceinline void Clear() {
        if(object) {
            if(!DAT_00d9b064(&object->refs)) object->Delete();
            object=0;
        }
    }
};
struct Loader { Scene* FUN_00429eb0(const char*,int,bool,bool,bool,bool); };
struct World { Scene* FUN_00435e70(Scene*,CloneContext*); };
extern Loader* DAT_0106ca70;
extern World* DAT_0107a0d8;
extern const void* DAT_0106e804;
extern const unsigned char DAT_0116eeec[];
extern const Point DAT_0108ec68;
extern const Matrix DAT_00f72574;
extern const char DAT_00dbfe70[];
extern int DAT_00f4c3d0[];
extern const void* DAT_00f4c35c[];
bool FUN_00478250(Scene*);
void FUN_00479030(Scene*);
void BipedAnim_AddAddonNodes(Scene*,Scene*,int,Actor*);
void FUN_004ef0a0(Scene*);
bool FUN_00424d20(const void*,Scene*);
bool FUN_0045cd20(Scene*);
void FUN_00887da0(const char*,...);
void FUN_00471830(Scene*,Scene*,Scene*,int,int,int);
Scene* FUN_00470720(Scene*,const void*);
// pdb: BipedAnim::LoadAndAttachAddOn | BipedAnim.obj | fnv360_0822_retail, ustr, medium
// pdb params: apObject, apModel, aeAttachmentType, apRequester, apObj3D
Scene* __cdecl FUN_00471ef0(Form* form,Model* model,int slot,Actor* actor,Scene* root)
{
    if(!model || !actor) return 0;
    const char* path=model->GetModelFilePath();
    if(!path || !*path) return 0;
    Scene* target=root;
    if(!target) target=actor->FUN_00424eb0();
    if(!target) return 0;
    Scene* loaded=DAT_0106ca70->FUN_00429eb0(path,3,true,false,false,false);
    CloneContext context(1.0f);
    Retained copy;
    Scene* result;
    if(FUN_00478250(loaded)) {
        copy.FUN_008e9650(DAT_0107a0d8->FUN_00435e70(loaded,&context));
        result=copy.object;
    } else result=loaded->FUN_008257a0(&context);
    TextureSwap* swap=model->GetAsModelTextureSwap();
    if(swap) swap->TESModelTextureSwap_SwapTextures(result);
    if(form && form->CheckUpdate()) FUN_00479030(result);
    BipedAnim_AddAddonNodes(loaded,result,slot,actor);
    FUN_004ef0a0(result);
    Retained extra(result->FUN_00824a50(DAT_0106e804));
    result->FUN_00824c30();
    Scene* extraObject=*(Scene* volatile*)&extra.object;
    if(extraObject) {
        result->FUN_008248c0(DAT_0106e804,extraObject);
        if(!DAT_00d9b064(&extraObject->refs)) extraObject->Delete();
        extra.object=0;
    }
    if(result) {
        if(FUN_00424d20(DAT_0116eeec,result)) result->FUN_00ad2840(7);
        result->translation=DAT_0108ec68;
        result->rotation=DAT_00f72574;
        if(FUN_0045cd20(result)) FUN_00887da0(DAT_00dbfe70,result->GetName());
        else {
            FUN_00471830(target,result,loaded,0,slot,0);
            if(result->IsSceneNode() && !result->parent) {
                Scene* attach=0;
                if(slot!=-1 && DAT_00f4c3d0[slot]!=-1)
                    attach=FUN_00470720(target,DAT_00f4c35c[DAT_00f4c3d0[slot]]);
                if(attach) attach->AddObject(result,true);
                else target->AddObject(result,true);
            }
        }
        result->FUN_008268a0();
    }
    return result;
}
}

// @f3 0x0046f930 (community match, verified in this file)
#include <string.h>
namespace n46f930 {
struct Entry {unsigned u00;unsigned u04;unsigned u08;unsigned u0c;unsigned u10;unsigned u14;unsigned u18;unsigned u1c;unsigned u20;unsigned u24;unsigned u28;unsigned u2c;unsigned u30;unsigned u34;unsigned u38;unsigned u3c;void Clear(){memset(this,0,sizeof(*this));}};
struct Table {
    int m0;
    Entry* m4;
    Entry* At(unsigned i){return &m4[i];}
    void FUN_0046f820(unsigned int i, Entry* out);
};
extern Table DAT_00f4bf78;
struct Model {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* V14();
};
struct Form {
    unsigned u00;unsigned u04;unsigned u08;unsigned u0c;unsigned u10;unsigned u14;unsigned u18;unsigned u1c;unsigned u20;unsigned u24;unsigned u28;unsigned u2c;
    Model m30;
    const char* m34;
    unsigned short m38;
    unsigned int Length() const {
        if (m38 == 0xffff) return (unsigned int)strlen(m34);
        return m38;
    }
};
struct Data {
    unsigned u000;unsigned u004;unsigned u008;unsigned u00c;unsigned u010;unsigned u014;unsigned u018;unsigned u01c;unsigned u020;unsigned u024;unsigned u028;unsigned u02c;unsigned u030;unsigned u034;unsigned u038;unsigned u03c;unsigned u040;unsigned u044;unsigned u048;unsigned u04c;unsigned u050;unsigned u054;unsigned u058;unsigned u05c;unsigned u060;unsigned u064;unsigned u068;unsigned u06c;unsigned u070;unsigned u074;unsigned u078;unsigned u07c;unsigned u080;unsigned u084;unsigned u088;unsigned u08c;unsigned u090;unsigned u094;unsigned u098;unsigned u09c;unsigned u0a0;unsigned u0a4;unsigned u0a8;unsigned u0ac;unsigned u0b0;unsigned u0b4;unsigned u0b8;unsigned u0bc;unsigned u0c0;unsigned u0c4;unsigned u0c8;unsigned u0cc;unsigned u0d0;unsigned u0d4;unsigned u0d8;unsigned u0dc;unsigned u0e0;unsigned u0e4;unsigned u0e8;unsigned u0ec;unsigned u0f0;unsigned u0f4;unsigned u0f8;unsigned u0fc;unsigned u100;unsigned u104;unsigned u108;unsigned u10c;unsigned u110;unsigned u114;unsigned u118;unsigned u11c;unsigned u120;unsigned u124;unsigned u128;unsigned u12c;unsigned u130;unsigned u134;unsigned u138;unsigned u13c;unsigned u140;unsigned u144;unsigned u148;unsigned u14c;unsigned u150;unsigned u154;unsigned u158;unsigned u15c;unsigned u160;unsigned u164;unsigned u168;unsigned u16c;unsigned u170;unsigned u174;unsigned u178;unsigned u17c;unsigned short u180;
    unsigned short m182;
    unsigned Count() const {return m182;}
    Form* FUN_0043c570(unsigned int i);
};
extern Data* DAT_0106cdcc;
struct NiObject;
struct Loader {
    NiObject* FUN_00429eb0(const char* path, int a, int b, int c, int d, int e);
    void FUN_00429640(const char* path, int a, int b);
};
extern Loader* DAT_0106ca70;
struct NiRTTI;
extern NiRTTI DAT_0108f200;
void* __cdecl FUN_00424d50(NiRTTI* t, NiObject* o);
bool __cdecl FUN_00aae920(NiObject* o);
struct Self {
    void FUN_0046ef10(void* node, Entry* e, int a, int b);
    void FUN_0046f930();
};
// pdb: BGSSceneInfo::CollectSceneDataFromAddonNodes | BGSSceneInfo.obj | fnv360_0822_retail, call_seq, medium
void Self::FUN_0046f930()
{
    unsigned int n = DAT_0106cdcc->Count();
    for (unsigned int i = 0; i < n; i++) {
        Entry info;
        info.Clear();
        DAT_00f4bf78.FUN_0046f820(i, &info);
        Form* f = DAT_0106cdcc->FUN_0043c570(i);
        if (f && f->Length()) {
            char path[260];
            strcpy_s(path, 260, "Meshes\\");
            strcat_s(path, 260, f->m30.V14());
            NiObject* o = DAT_0106ca70->FUN_00429eb0(path, 0, 1, 0, 0, 0);
            if (o) {
                if (!FUN_00aae920(o))
                    FUN_0046ef10(FUN_00424d50(&DAT_0108f200, o), DAT_00f4bf78.At(i), 0, 0);
                DAT_0106ca70->FUN_00429640(path, 1, 1);
            }
        }
    }
}
}

// @f3 0x00477bc0 (community match, verified in this file)
#include <math.h>
namespace f3m_00477bc0 {

struct W2Pt { float x, y, z;
  W2Pt operator-(const W2Pt& o) const { W2Pt r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; } };
struct W2Bound { W2Pt c; float r; };
struct W2Node;
struct W2Obj {
  virtual void v0(); virtual void v1(); virtual void v2();
  virtual W2Node* GetNode();
  unsigned u04;unsigned u08;unsigned u0c;unsigned u10;unsigned u14;unsigned u18;unsigned u1c;
  W2Bound* bound;
  unsigned u24,u28,u2c;
  unsigned char flags;
 int IsVisualObject() { return bound && bound->r != 0.0; }
};
struct W2Node : W2Obj {
  unsigned u34;unsigned u38;unsigned u3c;unsigned u40;unsigned u44;unsigned u48;unsigned u4c;unsigned u50;unsigned u54;unsigned u58;unsigned u5c;unsigned u60;unsigned u64;unsigned u68;unsigned u6c;unsigned u70;unsigned u74;unsigned u78;unsigned u7c;unsigned u80;unsigned u84;unsigned u88;unsigned u8c;unsigned u90;unsigned u94;unsigned u98;unsigned u9c;
  W2Obj** children;
  unsigned short cap;
  unsigned short count;
};
struct W2A {
  unsigned u00,u04,u08,u0c;char u10;
  bool unk11;
  void FUN_004345e0(W2Obj*);
  bool FUN_007fba00(W2Pt*, void*, bool);
};
// pdb: PickDistanceRecursive | GlobalFunc.obj | fnv360_0822_retail, call_gap + skyrim(call_gap), high
bool __cdecl PickDistanceRecursive(W2A* a, W2Pt* origin, void* arg2, float radius, W2Obj* obj)
{
  bool result = false;
  if (a && obj && (!a->unk11 || !(obj->flags & 1))) {
    if (!obj->IsVisualObject())
      return false;
    W2Bound s = *obj->bound;
    W2Pt d = s.c - *origin;
    float len = sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
    if (len < s.r + radius) {
      W2Node* n = obj->GetNode();
      if (n) {
        int cnt = n->count;
        for (int i = 0; i < cnt; i++) {
          W2Obj* child = n->children[i];
          if (PickDistanceRecursive(a, origin, arg2, radius, child))
            result = true;
        }
      } else {
        a->FUN_004345e0(obj);
        if (a->FUN_007fba00(origin, arg2, true))
          result = true;
      }
    }
  }
  return result;
}
}   // namespace f3m_00477bc0

// @f3 0x00471830 (community match, verified in this file)
#include <windows.h>
#include <math.h>

namespace Attach3058 {
extern const char DAT_00dbfe30[];
extern const char DAT_00dbfdf0[];
extern const char DAT_00dbfdb8[];
extern const char DAT_00dbfd74[];
extern const char DAT_00dbfd30[];
extern const char DAT_00dbfcf8[];
extern const char DAT_00dbfdb4[];
extern const char DAT_00dbfb64[];
extern const char DAT_00dbfdb0[];

struct Node;
struct Str { const char* p; const char* Text() const {return p;} };
struct Upd { float t; unsigned char b0; unsigned char b1; unsigned char b2; unsigned char b3; unsigned char b4; };
struct Sub { void FUN_004712a0(); void FUN_00470e10(); };
struct Extra { int unk00; int unk04; int unk08; Str unk0c; Str& Name(){return unk0c;} };
struct Y { int unk00; unsigned char unk04; };
struct X { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; Y* unk1c; };
struct P2 { int unk00; int unk04; int unk08; };
struct R { int unk00; int unk04; int unk08; int unk0c; P2* unk10; };
struct Q { int unk00; int unk04; R* unk08; int* FUN_00424270(int* o); };
struct T { int unk00; int unk04; int unk08; int unk0c; Q* unk10; };
struct Root { int unk00; };
struct Singleton { int unk00; void* FUN_0076ff40(int a); void* FUN_0076cd20(int a); void FUN_00ae5eb0(Node* n); };
struct Node {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4(Upd* u, int a);
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC(Node* n, int a);
    int unk04;
    const char* unk08;
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
    float unk64;
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
    Sub unk9c;
    void* FUN_00824a50(const Str* k);
    void* FUN_00824a50(Str& k);
    void FUN_008268a0();
    const Str& Name() const {return *(const Str*)&unk08;}
};

extern int DAT_0108f42c;
extern Str* DAT_0106e808;
extern unsigned int DAT_01090bb0;
extern Singleton* DAT_0107a104;
extern Singleton* DAT_0116efb8;
extern const char* DAT_00e207a8;

Extra* __cdecl FUN_00424d50(int* type, void* obj);
Node* __cdecl FUN_00aab440(Root* r, Str* s, int a);
Node* __cdecl FUN_00aab350(Node* n, const char* name, int a);
X* __cdecl FUN_004e7b90(Root* r);
void __cdecl FUN_004781c0(Node* n);
void __cdecl FUN_00887da0(const char* fmt, ...);
void __cdecl FUN_008da420(Node* n, int a);
const char* __cdecl FUN_008242a0(const char* s);
void __cdecl bhkWorld_KillHavok(Node* n, int a, int b);
T* __cdecl FUN_00424fe0(Node* n);
void __cdecl FUN_008d7b90(Node* n, int a, int b, int c, int d);

struct FStr {
    Str s;
    FStr(const char* c) { s.p = FUN_008242a0(c); }
    ~FStr() { if (s.p != DAT_00e207a8) ::InterlockedDecrement((LONG*)s.p - 2); }
};

// pdb: BipedAnim::AttachToParent | BipedAnim.obj | fnv360_0822_retail, ustr, medium
// pdb params: apSkeleton, apNode, apClonedFromNode, apBipedAnim, aeBipedObject, apfgModel
void __cdecl FUN_00471830(Root* a0, Node* obj, Node* flag, void* a3, int a4)
{
    Node* parent = 0;
    void* r;
    if (!flag || !(r = flag->FUN_00824a50(DAT_0106e808)))
        r = obj->FUN_00824a50(DAT_0106e808);
    if (r) {
        Extra* ex = FUN_00424d50(&DAT_0108f42c, r);
        if (ex) {
            parent = FUN_00aab440(a0, &ex->Name(), 1);
            if (!parent) {
                X* x = FUN_004e7b90(a0);
                if (x && x->unk1c && x->unk1c->unk04 == 0x2b)
                    FUN_004781c0(obj);
                else
                    FUN_00887da0(DAT_00dbfe30, ex->Name().Text(), obj->Name().Text());
            }
        } else
            FUN_00887da0(DAT_00dbfdf0, obj->Name().Text());
    } else
        FUN_00887da0(DAT_00dbfdb8, obj->Name().Text());

    float scale = 1.0f;
    if (parent) {
        scale = parent->unk64;
        parent->vDC(obj, 1);
        Upd u;
        u.t = (float)DAT_01090bb0;
        u.b0 = 0; u.b1 = 0; u.b2 = 0; u.b3 = 0; u.b4 = 0;
        obj->vA4(&u, 0);
        DAT_0116efb8->FUN_00ae5eb0(obj);
        Node* scb = FUN_00aab350(obj, DAT_00dbfdb4, 1);
        if (scb) {
            parent->vDC(scb, 1);
            FUN_008da420(parent, 1);
            scb->FUN_008268a0();
            Sub* s = &obj->unk9c;
            s->FUN_004712a0();
            s->FUN_00470e10();
        }
    }

    Node* bp = FUN_00aab350(obj, DAT_00dbfb64, 1);
    if (bp) {
        if (a0 == DAT_0107a104->FUN_0076ff40(1)) {
            bp->unk30 |= 1;
        } else {
            bp->unk64 = fabs(scale);
            void* e;
            {
                FStr upb(DAT_00dbfdb0);
                e = bp->FUN_00824a50(upb.s);
            }
            if (e) {
                Extra* ex = FUN_00424d50(&DAT_0108f42c, e);
                if (ex) {
                    Node* q = FUN_00aab440(a0, &ex->Name(), 1);
                    if (q) q->vDC(bp, 1);
                }
            }
        }
    }

    if (a3) {
        if (a3 == DAT_0107a104->FUN_0076cd20(1)) {
            bhkWorld_KillHavok(obj, 1, 1);
            return;
        }
    }
    if (a4 == 5) {
        T* t = FUN_00424fe0(obj);
        if (t) {
            Q* q = t->unk10;
            if (!q || !q->unk08 || !&q->unk08->unk10 || !q->unk08->unk10 || !q->unk08->unk10->unk08)
                FUN_00887da0(DAT_00dbfd74, obj->Name().Text());
            if (q) {
                int tmp;
                if ((*q->FUN_00424270(&tmp) & 0x7f) != 5)
                    FUN_00887da0(DAT_00dbfd30, obj->Name().Text());
            }
        } else
            FUN_00887da0(DAT_00dbfcf8, obj->Name().Text());
    }
    FUN_008d7b90(obj, 6, 1, 1, 1);
}

}

// @f3 0x0047eae0 (community match, verified in this file)
namespace f3m_0047eae0 {
namespace Inventory47EAE0 {
struct Form;
struct Container;
struct Process;
template<class T> struct Node {T* item;Node* next;};
struct Entry {void* extra;int count;Form* form; __forceinline Form* GetForm() const {return form;} __forceinline int Category() const;};
struct BaseEntry {int count;Form* form;};
struct Container {unsigned int unk00;Node<BaseEntry> head;};
struct Reference {
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
    virtual bool IsActor();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    Container* FUN_004e66c0();
};
struct Actor:Reference {Process* process; __forceinline Process* GetProcess() const {return process;}};
struct Process {
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
    virtual void NotifyItem(Form* form);
};
__forceinline Process* ActorProcess(Actor* actor) {if(actor) return actor->GetProcess(); return 0;}
bool __cdecl FUN_005a72a0(Form* form,int category);
int __cdecl FUN_005a7160(Form* form);
__forceinline int Entry::Category() const {return FUN_005a7160(GetForm());}
__forceinline bool AcceptForm(Form* form,Form* exactForm,int category)
{
    if (exactForm)
    {
        if (form==exactForm) return true;
        return false;
    }
    if (!category) return false;
    if (!FUN_005a72a0(form,category)) return false;
    return true;
}
struct Data {
    Node<Entry>* entries;
    Reference* owner;
    Entry* FUN_0047e180(Form* form,int unused,unsigned int formID);
    bool FUN_0047e9d0(unsigned int formID);
    bool FUN_0047eae0(Form* exactForm,int category,int required,int* outValue,unsigned int formID,Reference* candidate);
};

// pdb: InventoryChanges::ContainerHasObjects | InventoryChanges.obj | fnv360_0721_beta, call_seq, medium
// pdb params: apObj, aeObjectType, ainumber, aeMatchId, aId, apRef
bool Data::FUN_0047eae0(Form* exactForm,int category,int required,int* outValue,unsigned int formID,Reference* candidate)
{
    int total=0;
    if (formID)
        return FUN_0047e9d0(formID);

    Actor* actor=0;
    if (candidate && candidate->IsActor())
        actor=static_cast<Actor*>(candidate);

    Container* container=owner ? owner->FUN_004e66c0() : 0;
    for (Node<BaseEntry>* node=&container->head;node;node=node->next)
    {
        if (!node->next && !node->item)
            break;
        Form* form=node->item->form;
        if (!form)
            continue;
        if (!AcceptForm(form,exactForm,category))
            continue;

        Entry* entry=FUN_0047e180(form,1,0);
        if (!entry)
        {
            if (Process* notify=ActorProcess(actor))
                notify->NotifyItem(form);
            *outValue=FUN_005a7160(form);
            return true;
        }
        int baseCount=node->item->count;
        if (baseCount<0)
            return true;
        total+=baseCount+entry->count;
        if (Process* notify=ActorProcess(actor))
            notify->NotifyItem(entry->form);
        *outValue=entry->Category();
    }

    if (total>=required)
        return true;

    if (exactForm)
    {
        Entry* entry=FUN_0047e180(exactForm,1,0);
        if (entry && entry->count>=required)
        {
            if (Process* notify=ActorProcess(actor))
                notify->NotifyItem(entry->form);
            *outValue=entry->Category();
            return true;
        }
    }
    else
    {
        for (Node<Entry>* node=entries;node;node=node->next)
        {
            if (!node->item)
                break;
            Form* form=node->item->form;
            if (form && category && FUN_005a72a0(form,category) && node->item->count>=required)
            {
                if (Process* notify=ActorProcess(actor))
                    notify->NotifyItem(node->item->form);
                *outValue=node->item->Category();
                return true;
            }
        }
    }
    return false;
}
}
}   // namespace f3m_0047eae0

// @f3 0x00460340 (community match, verified in this file)
struct FUN_00460340_res {
    virtual void v0();
    virtual void Release();
    int unk04;
};
struct FUN_00460340_anim {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    int unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    int unk58;
    void FUN_0044db80(int p, float f);
    void NiControllerManager_DeactivateAll(float f);
};
struct FUN_00460340_act {
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void Stop(float f, int n);
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    int unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    int unk58;
};
struct FUN_00460340_node {
    void* unk00;
    FUN_00460340_node* unk04;
};
struct FUN_00460340_heap { void FUN_0086ba60(void* p); };
extern FUN_00460340_heap g_heap460340;
extern int (__stdcall* FUN_00d9b064)(void*);
int __cdecl FUN_006191f0();
struct FUN_00460340_list { void FUN_006c8220(); };

struct FUN_00460340_cls {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    unsigned short unk54;
    unsigned char unk56;
    unsigned char unk57;
    unsigned char unk58;
    unsigned char unk59;
    unsigned short unk5a;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    int unk6c;
    void* unk70;
    void* unk74;
    int unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    unsigned short unka4;
    unsigned char unkA6;
    unsigned char unkA7;
    unsigned char unkA8;
    unsigned char unkA9;
    unsigned short unkaa;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    FUN_00460340_anim* unkd8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    FUN_00460340_act* unkf0;
    void* unkF4;
    int unkf8;
    FUN_00460340_act* unkfc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    unsigned char unk114;
    unsigned char unk115;
    unsigned char unk116;
    unsigned char unk117;
    FUN_00460340_res* unk118;
    FUN_00460340_res* unk11c;
    void* unk120;
    void* unk124;
    FUN_00460340_node unk128;
    void Animation_ClearGroup(int i, float f);
    void FUN_0045dca0();
    void FUN_0045feb0(FUN_00460340_res** p);
    void FUN_00460340(int a);
};

// pdb: Animation::Revert | Animation.obj | fnv360_0822_retail, call_gap, low
// pdb params: apLoadGameBuffer
void FUN_00460340_cls::FUN_00460340(int a)
{
    unk114 = 0;
    if (FUN_006191f0() != 1) {
        Animation_ClearGroup(7, 0.0f);
        if (unk114 == 0)
            Animation_ClearGroup(0, 0.0f);
    }
    Animation_ClearGroup(1, 0.0f);
    if (FUN_006191f0() != 1)
        Animation_ClearGroup(2, 0.0f);
    Animation_ClearGroup(3, 0.0f);
    Animation_ClearGroup(5, 0.0f);
    Animation_ClearGroup(6, 0.0f);
    if (unkd8 && unkf0 && unkf0->unk44) {
        if (unkf0->unk58)
            unkd8->FUN_0044db80(unkf0->unk58, 0.0f);
        unkf0->Stop(0.0f, 0);
    }
    unkf0 = 0;
    unk54 = 0xff;
    unka4 = 0xff;
    *(volatile int*)&unk6c = -1;
    FUN_0045dca0();
    if (unk118) FUN_0045feb0(&unk118);
    int (__stdcall* fn)(void*) = FUN_00d9b064;
    if (unk118) { FUN_00460340_res* t = unk118; if (fn((char*)t + 4) == 0) t->Release(); unk118 = 0; }
    if (unk11c) FUN_0045feb0(&unk11c);
    if (unk11c) { FUN_00460340_res* t = unk11c; if (fn((char*)t + 4) == 0) t->Release(); unk11c = 0; }
    *(FUN_00460340_act* volatile*)&unkfc = 0;
    if (unkd8 && unkfc && unkfc->unk44) {
        if (unkfc->unk58)
            unkd8->FUN_0044db80(unkfc->unk58, 0.0f);
        unkfc->Stop(0.0f, 0);
    }
    unkfc = 0;
    *(volatile unsigned short*)&unk5a = 0xff;
    *(volatile unsigned short*)&unkaa = 0xff;
    *(volatile int*)&unk78 = -1;
    FUN_00460340_anim* an = *(FUN_00460340_anim* volatile*)&unkd8;
    if (an) an->NiControllerManager_DeactivateAll(0.0f);
    for (FUN_00460340_node* n = &unk128; n; n = n->unk04)
        g_heap460340.FUN_0086ba60(n->unk00);
    ((FUN_00460340_list*)&unk128)->FUN_006c8220();
}

// @f3 0x00475380 (community match, verified in this file)
#include <math.h>
namespace f3m_00475380 {

namespace MatrixInverse2233 {
struct Mat33 { float m[3][3]; };

struct Mat33_This {
    float m[3][3];
    bool __thiscall NiMatrix3_Inverse(Mat33* d);
};

// pdb: NiMatrix3::Inverse | GlobalFunc.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(caller), high
bool __thiscall Mat33_This::NiMatrix3_Inverse(Mat33* d)
{
    d->m[0][0] = m[2][2] * m[1][1] - m[2][1] * m[1][2];
    d->m[0][1] = m[2][1] * m[0][2] - m[0][1] * m[2][2];
    d->m[0][2] = m[0][1] * m[1][2] - m[0][2] * m[1][1];
    d->m[1][0] = m[2][0] * m[1][2] - m[1][0] * m[2][2];
    d->m[1][1] = m[0][0] * m[2][2] - m[2][0] * m[0][2];
    d->m[1][2] = m[1][0] * m[0][2] - m[1][2] * m[0][0];
    d->m[2][0] = m[1][0] * m[2][1] - m[2][0] * m[1][1];
    d->m[2][1] = m[0][1] * m[2][0] - m[2][1] * m[0][0];
    d->m[2][2] = m[0][0] * m[1][1] - m[1][0] * m[0][1];

    float det = m[0][0] * d->m[0][0] + m[0][1] * d->m[1][0] + m[0][2] * d->m[2][0];


    if (fabsf(det) <= 1.0e-6f)
        return 0;

    float invDet = 1.0f / det;
    float (*row)[3]=d->m;
    int count=0;
    do {
        float a = (*row)[0];
        float b = (*row)[1];
        float c = (*row)[2];
        (*row)[0] = a * invDet;
        (*row)[1] = b * invDet;
        (*row)[2] = c * invDet;
        ++row;
    } while (++count != 3);

    return 1;
}

}



}   // namespace f3m_00475380

// @f3 0x0047d610 (community match, verified in this file)
namespace f3m_0047d610 {
class TESForm {
public:
    virtual ~TESForm();
    unsigned char typeID;
};

class TESBoundObject : public TESForm {
public:
    virtual ~TESBoundObject();
};

class TESValueForm {
public:
    virtual ~TESValueForm();
    int value;
};

struct EffectSetting {
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
    unsigned int flags;
    bool IsFlag8() const { return (flags >> 8) & 1; }
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
    float cost;
};

struct EffectItem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    EffectSetting* setting;
    int EffectItem_GetMagnitude();
};

struct EffectNode {
    EffectItem* item;
    EffectNode* next;
};

class EffectItemList {
public:
    virtual void v00();
    virtual float v04(int mode);
    EffectNode head;
};

class MagicItem {
public:
    virtual ~MagicItem();
    int unk04;
    int unk08;
    EffectItemList effects;
};

struct EnchantmentItem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    EffectItemList effects;
    int unk30;
    int type;
};

class TESEnchantableForm {
public:
    virtual ~TESEnchantableForm();
    EnchantmentItem* enchantment;
};

struct GameSettingF {
    float* FUN_00401eb0();
};
extern GameSettingF g_settingF;

class Actor {
public:
    unsigned int FUN_006f57f0();
};

class PlayerCharacter {
public:
    float FUN_006f7710(Actor* a);
    float FUN_006f76d0(Actor* a);
};
extern PlayerCharacter* g_thePlayer;

unsigned short FUN_0047cad0(TESForm* form);
float FUN_00585020(float a, float b, float c);
void FUN_00543420(int id, void* actor, TESForm* form, float* value);
float FUN_0044a250(float v);

inline EnchantmentItem* GetEnchantment(TESForm* form)
{
    TESEnchantableForm* e = dynamic_cast<TESEnchantableForm*>(form);
    return e ? e->enchantment : 0;
}

inline float MaxF(float a, float b) { return a > b ? a : b; }
inline float H1(float a, float b) { return a > b ? a : b; }
inline float H2(float a, float b) { return a >= b ? a : b; }
inline float H3(float a, float b) { return a < b ? b : a; }
inline float H4(float a, float b) { return a <= b ? b : a; }
inline float L1(float a, float b) { return a < b ? a : b; }
inline float L2(float a, float b) { return a <= b ? a : b; }
inline float L3(float a, float b) { return a > b ? b : a; }
inline float L4(float a, float b) { return a >= b ? b : a; }
inline float MinF(float a, float b) { return a < b ? a : b; }

struct CostOwner {
    int unk00;
    int unk04;
    TESBoundObject* form;
    float FUN_0047cf30(int mode);
    float FUN_0047d610(bool applyPerks, Actor* actor, bool isPlayer);
};

float CostOwner::FUN_0047d610(bool applyPerks, Actor* actor, bool isPlayer)
{
    float result = -1.0f;
    TESValueForm* valueForm = dynamic_cast<TESValueForm*>(form);
    MagicItem* magic = dynamic_cast<MagicItem*>(form);
    TESEnchantableForm* enchantable = dynamic_cast<TESEnchantableForm*>(form);
    EnchantmentItem* ench = GetEnchantment(form);
    if (valueForm || magic) {
        result = 0.0f;
        if (valueForm) {
            if (enchantable && ench) {
                if (ench->type == 3) {
                    result = (float)valueForm->value;
                    if (result != 0.0f) {
                        EffectItemList* p = &ench->effects;
                        while (p) {
                            EffectItem* item = p->head.item;
                            if (!item)
                                break;
                            EffectSetting* setting = item->setting;
                            int mag;
                            if (setting->IsFlag8())
                                mag = (int)*g_settingF.FUN_00401eb0();
                            else
                                mag = item->EffectItem_GetMagnitude();
                            result += setting->cost * mag;
                            EffectNode* n = p->head.next;
                            p = n ? (EffectItemList*)((char*)n - 4) : 0;
                        }
                    }
                } else {
                    float skill = (float)FUN_0047cad0(form);
                    float base = ench->effects.v04(0);
                    if (form->typeID == 0x19) {
                        result += valueForm->value;
                    } else {
                        int value = valueForm->value;
                        result = FUN_00585020((float)value, skill, base);
                    }
                }
            } else {
                result = (float)valueForm->value;
            }
        } else {
            result = magic->effects.v04(0);
        }
        float orig = result;
        if (applyPerks) {
            if (isPlayer) {
                float mult = g_thePlayer->FUN_006f7710(actor);
                result = mult * result;
                FUN_00543420(0x11, g_thePlayer, form, &result);
                result = FUN_0044a250(result);
                result = H3(result, orig);
            } else {
                float mult = g_thePlayer->FUN_006f76d0(actor);
                result = mult * result;
                result = FUN_005844d0(result, FUN_0047cf30(1));
                FUN_00543420(0x11, actor, form, &result);
                result = FUN_0044a250(result);
                result = L3(result, orig);
                result = L3(result, (float)actor->FUN_006f57f0());
            }
        } else {
            result = FUN_005844d0(result, FUN_0047cf30(1));
        }
    }
    return MaxF(result, 0.0f);
}
}   // namespace f3m_0047d610

// @f3 0x004647c0 (community match, verified in this file)
#include <windows.h>
extern __declspec(thread) int g_tlsMemContext;
namespace f3m_004647c0 {
namespace f3m_004647c0 {

struct TagScope {
    int old;
    TagScope(int tag) { old = g_tlsMemContext; g_tlsMemContext = tag; }
    ~TagScope() { g_tlsMemContext = old; }
};

struct RefObject {
    virtual void v0();
    virtual void DeleteThis();
    long refs;
};

struct Scene : RefObject {};

template <class T> struct RefPtr {
    T* ptr;
    void operator=(T* value) {
        if (ptr != value) {
            T* old = ptr;
            if (old && !::InterlockedDecrement(&old->refs)) old->DeleteThis();
            ptr = value;
            if (value) ::InterlockedIncrement(&value->refs);
        }
    }
    operator T*() const { return ptr; }
};

struct AnimData {
    unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074;
    unsigned unk78;
};

struct Anim {
    unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4;
    AnimData* unkd8;
    bool FUN_00463650();
    bool FUN_004635f0();
    void FUN_00460090(bool abFreeQueued, bool abForceDelete);
};

struct Form {
    unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014;
    unsigned unk18;
};

struct Actor {
    virtual void v000(); virtual void v001(); virtual void v002(); virtual void v003();
    virtual void v004(); virtual void v005(); virtual void v006(); virtual void v007();
    virtual void v008(); virtual void v009(); virtual void v010(); virtual void v011();
    virtual void v012(); virtual void v013(); virtual void v014(); virtual void v015();
    virtual void v016(); virtual void v017(); virtual void v018(); virtual void v019();
    virtual void v020(); virtual void v021(); virtual void v022(); virtual void v023();
    virtual void v024(); virtual void v025(); virtual void v026(); virtual void v027();
    virtual void v028(); virtual void v029(); virtual void v030(); virtual void v031();
    virtual void v032(); virtual void v033(); virtual void v034(); virtual void v035();
    virtual void v036(); virtual void v037(); virtual void v038(); virtual void v039();
    virtual void v040(); virtual void v041(); virtual void v042(); virtual void v043();
    virtual void v044(); virtual void v045(); virtual void v046(); virtual void v047();
    virtual void v048(); virtual void v049(); virtual void v050(); virtual void v051();
    virtual void v052(); virtual void v053(); virtual void v054(); virtual void v055();
    virtual void v056(); virtual void v057(); virtual void v058(); virtual void v059();
    virtual void v060(); virtual void v061(); virtual void v062(); virtual void v063();
    virtual void v064(); virtual void v065(); virtual void v066(); virtual void v067();
    virtual void v068(); virtual void v069(); virtual void v070(); virtual void v071();
    virtual void v072(); virtual void v073(); virtual void v074(); virtual void v075();
    virtual void v076(); virtual void v077(); virtual void v078(); virtual void v079();
    virtual void v080(); virtual void v081(); virtual void v082(); virtual void v083();
    virtual void v084(); virtual void v085(); virtual void v086(); virtual void v087();
    virtual void v088(); virtual void v089(); virtual void v090(); virtual void v091();
    virtual void v092(); virtual void v093(); virtual void v094(); virtual void v095();
    virtual void v096(); virtual void v097(); virtual void v098(); virtual void v099();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120();
    virtual Anim* GetAnim();
    void FUN_006ff040(int type, unsigned value);
    unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c;
    unsigned char unk140;
    unsigned char unk141;
    bool unk142;
};

struct Idle {
    unsigned unk000; unsigned unk004; unsigned unk008;
    long refs;
    long unk10;
};

Scene* __cdecl FUN_00471ef0(Form* form, void* model, int slot, Actor* actor, Scene* root);
void __cdecl FUN_00838830(Scene* scene, unsigned data);

struct Owner {
    virtual ~Owner();
    unsigned unk04;
    int unk08;
    int unk0c;
    Idle* unk10;
    unsigned unk14;
    unsigned unk18;
    Form* forms[2];
    RefPtr<Scene> scenes[2];
    unsigned unk2c;
    Anim* unk30;
    Actor* unk34;
    void FUN_004647c0(Idle* idle);
};


// pdb: AnimIdle::Loaded | Animation.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apKFModel
void Owner::FUN_004647c0(Idle* idle)
{
    TagScope tag(0x33);
    if (unk10 != idle) {
        if (unk10) ::InterlockedDecrement(&unk10->refs);
        unk10 = idle;
        if (idle) ::InterlockedIncrement(&idle->refs);
    }
    if (idle) {
    for (int i = 0; i < 2; i++) {
        Form* form = forms[i];
        if (form && unk34) {
            scenes[i] = FUN_00471ef0(form, &form->unk18, -1, unk34, 0);
            FUN_00838830(scenes[i].ptr, unk34->GetAnim()->unkd8->unk78);
            unk34->unk142 = true;
        }
    }
    ::InterlockedIncrement(&idle->unk10);
    unk08 = 1;
    if (unk34 && (unk0c == 2 || unk0c == 3)) {
        Anim* anim = unk30;
        if (!anim) {
            anim = unk34->GetAnim();
            if (!anim) {
                delete this;
                return;
            }
        }
        if (anim->FUN_00463650()) {
            if (unk0c == 3) unk34->FUN_006ff040(0xd, unk18);
        } else {
            anim->FUN_00460090(true, false);
        }
    } else if (unk34 && unk0c == 0) {
        Anim* anim = unk30;
        if (!anim) {
            anim = unk34->GetAnim();
            if (!anim) {
                delete this;
                return;
            }
        }
        if (anim->FUN_004635f0()) return;
    }
    } else {
        unk08 = 0;
    }
}

}
}   // namespace f3m_004647c0

// @f3 0x004712a0 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace task2969 {
struct CmpPtr;
CmpPtr* FUN_006e3090(unsigned int);
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct CmpRefObject
{
    virtual ~CmpRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        ::InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (::InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct CmpPtr
{
    CmpRefObject* m_pObject;
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
    CmpPtr(CmpRefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~CmpPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    CmpPtr& operator=(const CmpPtr& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const CmpPtr& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

struct CmpPtrArray
{
    virtual ~CmpPtrArray();
    CmpPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    static CmpPtr* Allocate(unsigned int auiCount)
    {
        return FUN_006e3090(auiCount);
    }
    void FUN_004712a0();
};

// @fnv 0x00c63030
// pdb: NiTArray<NiPointer<NiAVObject>,NiTNewInterface<NiPointer<NiAVObject> > >::Compact | BipedAnim.obj | fnv360_0822_retail, call_seq, high
void CmpPtrArray::FUN_004712a0()
{
    if (m_usESize == m_usSize)
        return;

    if (m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < m_usSize; i++)
        {
            if (m_pBase[i] != CmpPtr(0))
            {
                if (m_pBase[j] != m_pBase[i])
                    m_pBase[j] = m_pBase[i];
                j++;
            }
        }
    }

    CmpPtr* pSaveBase = m_pBase;
    m_usMaxSize = m_usSize = m_usESize;
    if (m_usMaxSize > 0)
    {
        m_pBase = FUN_006e3090(m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
    }
    else
    {
        m_pBase = 0;
    }
    delete[] pSaveBase;
}


}

// @f3 0x00473c50 (community match, verified in this file)
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace task2295 {
struct Node;struct Actor;struct Holder;struct Face;
struct Heap{void FUN_0086ba60(void*);void*Allocate(unsigned);};extern Heap DAT_01090a78;
struct String{char*data;unsigned short length,capacity;String():data(0),length(0),capacity(0){}~String(){if(data)DAT_01090a78.FUN_0086ba60(data);}operator const char*()const{return data;}int __cdecl Sprintf(const char*fmt,...){char buf[0x200];va_list args;va_start(args,fmt);int n=_vsnprintf(buf,sizeof(buf)-1,fmt,args);va_end(args);buf[sizeof(buf)-1]=0;if(n<0)n=sizeof(buf)-1;if(data)DAT_01090a78.FUN_0086ba60(data);data=(char*)DAT_01090a78.Allocate(n+1);memcpy(data,buf,n+1);length=(unsigned short)n;capacity=(unsigned short)n;return n;}};
extern const char*DAT_00e207a8;
const char*__cdecl FUN_008242a0(const char*);
struct Fixed{const char*data;Fixed(const char*s){if(!s)data=DAT_00e207a8;else data=FUN_008242a0(s);}~Fixed(){if(data!=DAT_00e207a8)::InterlockedDecrement((volatile long*)(data-8));}};
struct Extra{unsigned unk00,unk04,unk08,flags;bool Test(){return (flags>>4)&1;}};
extern Fixed*DAT_0116d6e0;
struct Node{
virtual void v00();
virtual void v01();
virtual void v02();
virtual Node*IsSceneNode();
virtual void v04();
virtual void v05();
virtual void v06();
virtual void v07();
virtual void v08();
virtual void v09();
virtual void v0a();
virtual void v0b();
virtual void v0c();
virtual void v0d();
virtual void v0e();
virtual void v0f();
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
virtual void v1a();
virtual void v1b();
virtual void v1c();
virtual void v1d();
virtual void v1e();
virtual void v1f();
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
virtual void v2a();
virtual void v2b();
virtual void v2c();
virtual void v2d();
virtual void v2e();
virtual void v2f();
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual void v34();
virtual void v35();
virtual void v36();
virtual void AddObject(Node*,bool);
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
Node*parent;Node*GetParent(){return parent;}void FUN_008245d0(const Fixed&);Extra*FUN_00824a50(Fixed*);void FUN_008268a0();};
struct Form{
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
virtual void v0a();
virtual void v0b();
virtual void v0c();
virtual void v0d();
virtual void v0e();
virtual void v0f();
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
virtual void v1a();
virtual void v1b();
virtual void v1c();
virtual void v1d();
virtual void v1e();
virtual void v1f();
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
virtual void v2a();
virtual void v2b();
virtual void v2c();
virtual void v2d();
virtual void v2e();
virtual void v2f();
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
virtual void v3a();
virtual void v3b();
virtual void v3c();
virtual void v3d();
virtual void v3e();
virtual void v3f();
virtual void v40();
virtual void v41();
virtual void v42();
virtual void v43();
virtual void v44();
virtual void v45();
virtual void v46();
virtual void v47();
virtual void v48();
virtual void v49();
virtual void v4a();
virtual void v4b();
virtual const char*GetEditorID();
unsigned unk04,unk08,id;unsigned GetFormID(){return id;}};
struct Scene{unsigned unk000;
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
Node*node;};
struct TLS{unsigned unk000;
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
unsigned unk1e4;
unsigned unk1e8;
unsigned unk1ec;
unsigned unk1f0;
unsigned unk1f4;
unsigned unk1f8;
unsigned unk1fc;
unsigned unk200;
unsigned unk204;
unsigned unk208;
unsigned unk20c;
unsigned unk210;
unsigned unk214;
unsigned unk218;
unsigned unk21c;
unsigned unk220;
unsigned unk224;
unsigned unk228;
unsigned unk22c;
unsigned unk230;
unsigned unk234;
unsigned unk238;
unsigned unk23c;
unsigned unk240;
unsigned unk244;
Node*node;Actor*actor;};extern unsigned DAT_01179af4;extern __declspec(thread) TLS DAT_0117c000;
struct Actor{unsigned unk000;
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
Scene*scene;bool FUN_0076cd40(Holder*);Node*GetRefNode(){Node*r;if(scene)r=scene->node;else r=0;return r;}Node*Get3DSimple(){if(this==DAT_0117c000.actor)return DAT_0117c000.node;return GetRefNode();}};extern Actor*DAT_0107a104;
struct Bone{unsigned char flags;Node*pParent;};struct Object{Form*pParent;void*model;Node*m_pSceneObject;bool bHasAnimation;};
extern unsigned DAT_00f4c3d0[];extern const char*DAT_00f4c380[];extern const char DAT_00dbfeb4[];
void __cdecl FUN_00471830(Node*,Node*,Node*,Holder*,int,Face*);void __cdecl TESObjectREFR_AddAddonNodes(Node*);
struct Holder{Node*root;Bone bone[5];Object object[20];Object previous[20];float fade;Actor*m_pActor;
Node*FUN_00473ab0(Node*,int,bool,bool,Face*);
void ApplyReferenceExtraData(Node*model,Node*clone,int,Actor*){Extra*e=model->FUN_00824a50(DAT_0116d6e0);if(e&&e->Test())TESObjectREFR_AddAddonNodes(clone);}
void FUN_00473c50(Face*,Node*,int);
};
// pdb: BipedAnim::AttachHelmet | BipedAnim.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apfgModel, apNode, aeBipedObject
void Holder::FUN_00473c50(Face* apFaceGenModel, Node* apNode, int aeBipedObject)
{
    Node* pcloneNode = 0;
    if (apFaceGenModel && apNode)
    {
        unsigned boneIndex = (unsigned)DAT_00f4c3d0[aeBipedObject];
        bool b1st = false;
        if (m_pActor == DAT_0107a104 && DAT_0107a104->FUN_0076cd40(this))
            b1st = true;
        pcloneNode = apNode;
        Node* ppartClone;
        bool bfirstPerson = false;
        bool bpipboy = object[6].pParent;
        if (m_pActor == DAT_0107a104 && DAT_0107a104->FUN_0076cd40(this))
            bfirstPerson = true;
        ppartClone = FUN_00473ab0(pcloneNode, aeBipedObject, bfirstPerson, bpipboy, apFaceGenModel);
        if (!ppartClone)
        {
            ppartClone = pcloneNode;
            FUN_00471830(root, pcloneNode, 0, this, aeBipedObject, apFaceGenModel);
        }
        if (ppartClone)
        {
            String newName;
            newName.Sprintf(DAT_00dbfeb4, DAT_00f4c380[aeBipedObject], object[aeBipedObject].pParent->GetEditorID(),
                            object[aeBipedObject].pParent->GetFormID());
            ppartClone->FUN_008245d0(Fixed(newName));
            ApplyReferenceExtraData(apNode, pcloneNode, aeBipedObject, m_pActor);
            if (!object[aeBipedObject].bHasAnimation && ppartClone->IsSceneNode())
            {
                Node* pparent = ppartClone->GetParent();
                if (bone[boneIndex].pParent)
                    bone[boneIndex].pParent->AddObject(ppartClone, true);
                else if (ppartClone->GetParent())
                    root->AddObject(ppartClone, true);
            }
            object[aeBipedObject].m_pSceneObject = ppartClone;
        }
    }
    if(m_pActor && m_pActor->Get3DSimple()) m_pActor->Get3DSimple()->FUN_008268a0();
}

}

// @f3 0x00463650 (community match, verified in this file)
namespace n463650 {
struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;
struct Form {
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
    unsigned short f3c;
    bool FUN_00552ad0();
};
struct Inner { int FUN_0054bef0(); };
struct Target { int f0, f4; Inner* f8; };
struct Entry {
    Form* form;
    float value;
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void*) {}
};
struct EntryList { void FUN_0061c430(Entry* const& e); };
struct Step {
    int f0, f4;
    int f8;
    int fc;
    Target* f10;
    int f14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    Form* f2c;
    void FUN_0045ddd0(void* r);
};
struct Proc {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    Step* f118;
    Step* f11c;
    void* unk120;
    void* unk124;
    EntryList f128;
    void FUN_00460090(int a, int b);
    bool FUN_00461a70(Target* t, int a);
    void* Animation_PlayGroup(int a, int b, int c, int d);
    bool FUN_00463650();
};
// pdb: Animation::SpecialIdlePlay | Animation.obj | fnv360_0721_beta, call_seq, medium
bool Proc::FUN_00463650()
{
    if (f11c)
    {
        if (f11c->f8 == 1)
            FUN_00460090(0, 0);
        else
            return false;
    }
    if (f118 && f118->f8 == 1)
    {
        Target* t = f118->f10;
        if (t && FUN_00461a70(t, 0) && t->f8)
        {
            void* r;
            if (f118->f14 == 0 && f118->f10->f8->FUN_0054bef0() == 1)
            {
                int a4 = f118->f14;
                Inner* o = t->f8;
                r = Animation_PlayGroup(o->FUN_0054bef0(), 1, -1, a4);
            }
            else
            {
                int a4 = f118->f14;
                Form* f = f118->f2c;
                Inner* o = t->f8;
                r = Animation_PlayGroup(o->FUN_0054bef0(), 1, f->FUN_00552ad0(), a4);
            }
            if (r)
            {
                if (f118->f2c->f3c > 0.0)
                {
                    Entry* const& arg = new Entry;
                    arg->form = f118->f2c;
                    arg->value = (float)f118->f2c->f3c;
                    f128.FUN_0061c430(arg);
                }
                f118->FUN_0045ddd0(r);
                return true;
            }
            f118->f8 = 3;
            if (f118->fc == 2 || f118->fc == 3)
                FUN_00460090(1, 0);
        }
        else
        {
            f118->f8 = 3;
            if (f118->fc == 2 || f118->fc == 3)
                FUN_00460090(1, 0);
        }
    }
    return false;
}
}

// @f3 0x004730a0 (community match, verified in this file)
namespace f3m_004730a0 {
// BipedAnim::AdjustSkinComplexion: give a skin shape the race's skin textures (and its normal map) for the NPC.

namespace f3c_004730a0 {

class NiTexture {
public:
    virtual void v00();
    virtual void DeleteThis();                        // vtbl+4
    volatile long m_uiRefCount;                       // +4
    void DecRefCount()
    {
        if (!::InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

template <class T> class NiPtr {
public:
    T* m_pObject;
    NiPtr() : m_pObject(0) {}
    __forceinline ~NiPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const { return m_pObject; }
};

struct NiRTTI;
extern NiRTTI g_NiSourceTextureRTTI;                  // DAT_0108f20c
class NiSourceTexture : public NiTexture {
public:
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
    const char* m_kFilename;                          // +0x34
};
NiSourceTexture* NiDynamicCast(NiRTTI* rtti, NiTexture* obj); // FUN_00424d50

class BSShaderPPLightingProperty {
public:
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void SetTexture(int slot, NiTexture* tex);       // vtbl+0xfc
    virtual void SetNormalTexture(int slot, NiTexture* tex); // vtbl+0x100
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned long ulFlags[2];                         // +0x20
    float fAlpha;
    float fFadeAlpha;
    float fEnvmapScale;
    float fCameraDistance;
    int iLastRenderPassState;                         // +0x38
    bool GetFlag(unsigned int bit) const
    {
        if (ulFlags[bit >> 5] & (1 << (bit & 31)))
            return true;
        return false;
    }
    void SetFlag(unsigned int bit, bool on)
    {
        if (on) {
            if (!GetFlag(bit))
                iLastRenderPassState = 0;
            ulFlags[bit >> 5] |= (1 << (bit & 31));
        } else {
            if (GetFlag(bit))
                iLastRenderPassState = 0;
            ulFlags[bit >> 5] &= ~(1 << (bit & 31));
        }
    }
};

class NiAVObject;
enum BIPED_OBJECT { BIPED_NONE = -1, BIPED_HEAD = 0 };

struct FR2MatrixVTC {
    float m00; float m04; float m08; float m0c; float m10; float m14;
    FR2MatrixVTC();                                   // FUN_004320f0
    ~FR2MatrixVTC();                                  // FUN_0042f0d0
};


struct TESFullNameData {
    const char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
};

class TESRace;
class NPCData {
public:
    virtual void vf00();
    void GetFaceCoord(FR2MatrixVTC (*coords)[2]);     // FUN_00554d10
    int GetSex();                                     // FUN_0054a930
    TESRace* GetRace() { return pRace; }
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
    TESRace* pRace;                                   // +0x110
};

class TESRace {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    TESFullNameData fullName;                         // +0x1c
    const char* GetFullName() { return fullName.pString ? fullName.pString : ""; }
    bool GetSkinTextures(NiPtr<NiTexture>& baseMod, NiPtr<NiTexture>& texture, NPCData* npc, BIPED_OBJECT slot,
                         bool force);                 // FUN_005619e0
};

struct TESObjectREFR {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ::TESBoundObject* pObjectReference;               // +0x1c
    ::TESBoundObject* GetObjectReference() { return pObjectReference; }
};

extern const char* g_BipedObjectNames[];              // DAT_00f4c380
inline const char* GetBipedName(int slot) { return g_BipedObjectNames[slot]; }
extern const char* g_SexNames[];                      // DAT_00f5cab8
inline const char* GetSexName(int sex) { return g_SexNames[sex]; }
void Warning(const char* format, ...);                // FUN_00887da0
void MakeFilenameWithSuffix(char* out, const char* in, const char* suffix, bool keepExt); // FUN_00ad5a70
void LoadTexture(const char* name, bool a, NiPtr<NiTexture>& out, bool b, bool c);      // FUN_00adbc30
NiTexture* GetDefaultDetailModulationTexture();       // FUN_00470bc0

class BipedAnim {
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
    TESObjectREFR* m_pRequester;                      // +0x2b0
    static BSShaderPPLightingProperty* FindLightingShaderProperty(NiAVObject* obj);             // BipedAnim_GetLightingProperty
    static BIPED_OBJECT GetSkinBipedObject(NiAVObject* obj, BSShaderPPLightingProperty* prop); // FUN_00470960
    void FUN_004730a0(NiAVObject* apObj, bool abForceReadjust);
};

// pdb: BipedAnim::AdjustSkinComplexion | BipedAnim.obj | fnv360_0822_retail, ustr, medium
// pdb params: apObj, abForceReadjust
void BipedAnim::FUN_004730a0(NiAVObject* apObj, bool abForceReadjust)
{
    BSShaderPPLightingProperty* plightprop = FindLightingShaderProperty(apObj);
    if (!plightprop)
        return;
    BIPED_OBJECT ebipedObject = GetSkinBipedObject(apObj, plightprop);
    if (ebipedObject == BIPED_NONE)
        return;
    FR2MatrixVTC facecoord[2][2];
    NPCData* pnpc = reinterpret_cast<NPCData*>(dynamic_cast< ::TESNPC*>(m_pRequester->GetObjectReference()));
    NiPtr<NiTexture> spraceTextureBaseMod;
    NiPtr<NiTexture> spraceTexture;
    if (pnpc)
        pnpc->GetFaceCoord(facecoord);
    bool bfoundtex;
    if (abForceReadjust)
        bfoundtex = pnpc->GetRace()->GetSkinTextures(spraceTextureBaseMod, spraceTexture, pnpc, ebipedObject, true);
    else
        bfoundtex = pnpc->GetRace()->GetSkinTextures(spraceTextureBaseMod, spraceTexture, pnpc, ebipedObject, false);
    if (!bfoundtex) {
        Warning("TEXTURES: Missing '%s' race texture for '%s' in race '%s'.", GetSexName(pnpc->GetSex()),
                GetBipedName(ebipedObject), pnpc->GetRace()->GetFullName());
    } else {
        plightprop->SetTexture(0, spraceTextureBaseMod);
        NiSourceTexture* psrctexture = NiDynamicCast(&g_NiSourceTextureRTTI, spraceTextureBaseMod);
        const char* pdecalfilename = 0;
        if (psrctexture)
            pdecalfilename = psrctexture->m_kFilename;
        char pfilename[260];
        MakeFilenameWithSuffix(pfilename, pdecalfilename, "_n", true);
        if (pfilename[0]) {
            NiPtr<NiTexture> pnormalTex;
            LoadTexture(pfilename, true, pnormalTex, true, false);
            if (pnormalTex)
                plightprop->SetNormalTexture(0, pnormalTex);
        }
        plightprop->SetTexture(1, spraceTexture);
        plightprop->SetNormalTexture(1, GetDefaultDetailModulationTexture());
        plightprop->SetFlag(10, true);
    }
}

}  // namespace f3c_004730a0
}   // namespace f3m_004730a0

// @f3 0x00471b70 (community match, verified in this file)
namespace resource471 {
struct Model {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08();
    virtual void Slot0c(); virtual void Slot10();
    virtual const char* GetPath();
};
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct String {
    char* data;
    unsigned short length,capacity;
    String():data(0),length(0),capacity(0) {}
    ~String() { if(data) DAT_01090a78.FUN_0086ba60(data); }
};
extern int DAT_0106e334;
extern void (__stdcall* DAT_00d9b09c)(void*);
extern void (__stdcall* DAT_00d9b0a0)(void*);
extern const char DAT_00db84e0;
void __cdecl FUN_00c007fc(char*,unsigned int,const char*);
void __cdecl FUN_00c00fcc(char*,unsigned int,const char*);
String* __cdecl FUN_0058c320(String* output,const char* path,int index);
int __cdecl FUN_0058ef70(String* name,int,int,int,int,int,int);
struct Loader {
    int FUN_00471b70(int index);
};
// pdb: BipedAnim::LoadFaceGenModel | BipedAnim.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeBipedObject
int Loader::FUN_00471b70(int index) {
    DAT_00d9b09c(&DAT_0106e334);
    Model* model=*reinterpret_cast<Model**>(reinterpret_cast<char*>(this)+(index+3)*16);
    int result=0;
    if(model) {
        String name;
        char path[260];
        FUN_00c007fc(path,260,&DAT_00db84e0);
        FUN_00c00fcc(path,260,model->GetPath());
        result=FUN_0058ef70(FUN_0058c320(&name,path,-1),0,0,0,1,-1,0);
    }
    DAT_00d9b0a0(&DAT_0106e334);
    return result;
}
}

// @f3 0x004613b0 (community match, verified in this file)
namespace f3m_004613b0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

struct ZObj {
    virtual void v00();
    virtual void DeleteThis();
    virtual void v08();
    virtual int v0C();
    volatile long refCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* FUN_00825200(void* rtti);
    void FUN_00825110(void* o);
    void FUN_008a8d50();
    void NiControllerManager_DeactivateAll(float t);
    ZObj* unk2C;
};

struct ZPtr {
    ZObj* p;
    operator ZObj*() const { return p; }
    ZObj* operator->() const { return p; }
    ~ZPtr()
    {
        ZObj* v = p;
        if (v && !InterlockedDecrement(&v->refCount))
            v->DeleteThis();
    }
};

struct ZList {
    void* item;
    ZList* next;
    void FUN_006c8220();
    ~ZList() { FUN_006c8220(); }
};

struct ZNode {
    void FUN_00424390();
};
struct ZItem {
    ZNode* item;
    ZItem* next;
    void FUN_006c8220();
    ~ZItem() { FUN_006c8220(); }
};

struct ZPool { void FUN_0086ba60(void* p); };
extern ZPool DAT_01090a78;

struct FUN_00424aa0 { int value; ~FUN_00424aa0(); };

struct ZKill {
    virtual void Kill(int f);
};
struct ZMap {
    virtual ~ZMap();
    unsigned int count;
    ZKill** buckets;
    void FUN_006bd950();
    ZKill* First()
    {
        for (unsigned int i = 0; i < count; i++) {
            if (buckets[i])
                return buckets[i];
        }
        return 0;
    }
    void FUN_0045c740(void** pos, short* key, ZKill** val);
};

struct ZMgr { void FUN_004296b0(void* p); };
extern ZMgr* DAT_0106ca70;

extern int DAT_01091f0c;
extern int DAT_01091f6c;

struct FUN_004613b0 {
    int unk00;
    int unk04;
    ZPtr unk08;
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
    ZPtr unkD8;
    ZMap* unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    ZItem unk104;
    int unk10C;
    int unk110;
    int unk114;
    ZPtr unk118;
    ZPtr unk11C;
    FUN_00424aa0 unk120[2];
    ZList unk128;
    void FUN_004609a0();
    ~FUN_004613b0();
};

}

using namespace f3m_004613b0;

// pdb: Animation::~Animation | Animation.obj | fnv360_0822_retail, call_seq, medium
FUN_004613b0::~FUN_004613b0()
{
    FUN_004609a0();
    DAT_0106ca70->FUN_004296b0(this);
    if (unkD8) {
        ZObj* a = unk08.p ? (ZObj*)unk08.p->FUN_00825200(&DAT_01091f0c) : 0;
        ZObj* b = unk08.p ? (ZObj*)unk08.p->FUN_00825200(&DAT_01091f6c) : 0;
        if (a)
            unk08.p->FUN_00825110(a);
        if (b)
            unk08.p->FUN_00825110(b);
        unkD8->NiControllerManager_DeactivateAll(0.0f);
        unkD8->FUN_008a8d50();
        ZObj* o = unkD8->unk2C;
        if (o && o->v0C())
            o->FUN_00825110(unkD8);
        ZObj* d = unkD8.p;
        if (d) {
            if (!InterlockedDecrement(&d->refCount))
                d->DeleteThis();
            unkD8.p = 0;
        }
    }
    void* pos = unkDC->First();
    while (pos) {
        short key;
        ZKill* val = 0;
        unkDC->FUN_0045c740(&pos, &key, &val);
        if (val)
            val->Kill(1);
    }
    for (ZItem* it = &unk104; it; it = it->next) {
        if (!it->next && !it->item)
            break;
        it->item->FUN_00424390();
    }
    unk104.FUN_006c8220();
    unkDC->FUN_006bd950();
    if (unkDC)
        delete unkDC;
    unkDC = 0;
    unk0C = 0;
    ZList* l = &unk128;
    if (l->next || l->item) {
        for (ZList* it = &unk128; it; it = it->next) {
            void* item = it->item;
            DAT_01090a78.FUN_0086ba60(item);
        }
        l->FUN_006c8220();
    }
}

// @f3 0x0047f4b0 (community match, verified in this file)
// ===== stand-ins for FUN_0047f4b0 @ 0x0047f4b0 =====
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* dest, long exch, long comp);

struct S47f4b0_Form {
    int unk00;
    unsigned char type;               // 0x04
    unsigned int flags;               // 0x08
    bool Script_Run(void* a, int b);
    bool IsFlag3() const { return (flags >> 3) & 1; }
};

struct S47f4b0_Elem {
    S47f4b0_Form* FUN_0040ace0();
    int FUN_0040ad00(void* a, int b);
};

struct S47f4b0_ElemNode {
    S47f4b0_Elem* unk00;
    S47f4b0_ElemNode* unk04;
};

struct S47f4b0_Item {
    S47f4b0_ElemNode* unk00;
    int unk04;
    int unk08;
};

struct S47f4b0_ItemNode {
    S47f4b0_Item* unk00;
    S47f4b0_ItemNode* unk04;
};

struct S47f4b0_Sub {
    void FUN_0040b510(int);
    void ExtraDataList_RemoveAllCopyableExtra(int);
};

struct S47f4b0_Triple { int a, b, c; };

struct S47f4b0_Glob {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    S47f4b0_Triple unk2c;             // 0x2c
    int unk38;
    int unk3c;                        // 0x3c
    S47f4b0_Sub unk40;                // 0x40
    void FUN_004e72f0(void* p);
    void TESObjectREFR_SetObjectReference(int v);
};
namespace S47f4b0_g { extern S47f4b0_Glob* DAT_0106ea24; }
using S47f4b0_g::DAT_0106ea24;

struct S47f4b0_Lock {
    long owner;
    long count;
    void FUN_00409a80(int);
    void Unlock() {
        if (--count == 0)
            InterlockedCompareExchange(&owner, 0, owner);
    }
};
extern S47f4b0_Lock DAT_0106ea80;


struct S47f4b0_Param {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    S47f4b0_Triple unk2c;             // 0x2c
    int unk38;
    int unk3c;                        // 0x3c
};

struct S47f4b0_Owner {
    S47f4b0_ItemNode* unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool unk10;                       // 0x10
    bool FUN_0047f4b0(S47f4b0_Param* param);
};

// pdb: InventoryChanges::RunScripts | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
// pdb params: pOwner
bool S47f4b0_Owner::FUN_0047f4b0(S47f4b0_Param* param)
{
    unk10 = false;
    if (!param)
        return false;
    int p3c = param->unk3c;
    if (!p3c)
        return false;
    DAT_0106ea80.FUN_00409a80(0);
    S47f4b0_ItemNode* node = unk00;
    bool result = false;
    {
        n47df80::TlsTagGuard guard(0x15);
        DAT_0106ea24->unk3c = p3c;
        DAT_0106ea24->unk2c = param->unk2c;
        while (node) {
            S47f4b0_Item* item = node->unk00;
            if (!item)
                break;
            for (S47f4b0_ElemNode* m = item->unk00; m; m = m->unk04) {
                S47f4b0_Elem* e = m->unk00;
                if (!e)
                    break;
                S47f4b0_Form* form = e->FUN_0040ace0();
                if (form && form->IsFlag3()) {
                    if (form->type == 0x11) {
                        DAT_0106ea24->FUN_004e72f0(e);
                        DAT_0106ea24->TESObjectREFR_SetObjectReference(item->unk08);
                        if (form->Script_Run(DAT_0106ea24, e->FUN_0040ad00(param, 0)))
                            result = true;
                        DAT_0106ea24->unk40.FUN_0040b510(0);
                        DAT_0106ea24->unk40.ExtraDataList_RemoveAllCopyableExtra(1);
                    }
                    if (unk10)
                        break;
                }
            }
            if (unk10) {
                node = unk00;
                unk10 = false;
            }
            node = node->unk04;
        }
        DAT_0106ea24->unk3c = 0;
        DAT_0106ea24->TESObjectREFR_SetObjectReference(0);
    }
    DAT_0106ea80.Unlock();
    return result;
}

// @f3 0x0047cf30 (community match, verified in this file)
extern float DAT_00db38b8;
extern float DAT_00dc0bc8;
namespace f3m_0047cf30 {
namespace S0047cf30_ {
class TESBoundObject;
class TESHealthForm {
public:
    virtual ~TESHealthForm();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual unsigned int GetHealth();
};
struct ExtraList {
    float FUN_0040ac20();
};
TESHealthForm* FUN_004566c0(TESBoundObject* object);
float FUN_0090d870(float upper, float value);
struct Entry {
    ExtraList** extra;
    int count;
    TESBoundObject* object;
    float FUN_0047cf30(bool percent);
};
}


namespace S0047cf30_ {
// pdb: ItemChange::GetItemHealth | InventoryChanges.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: BGSBipedModelList::GetFormAsBipedModelList)
// pdb params: abPercentage
float Entry::FUN_0047cf30(bool percent)
{
    TESHealthForm* base = FUN_004566c0(object);
    if (base) {
        if (extra) {
            ExtraList* list = *extra;
            if (list) {
                if (list->FUN_0040ac20() != -1.0f) {
                    if (!percent) {
                        return list->FUN_0040ac20();
                    }
                    double health = list->FUN_0040ac20();
                    return FUN_0090d870(DAT_00dc0bc8, health / (float)base->GetHealth()) * 100.0;
                }
                if (!percent) {
                    return (float)base->GetHealth();
                }
                return DAT_00dc0bc8;
            }
        }
        if (!percent) {
            return (float)base->GetHealth();
        }
        return DAT_00dc0bc8;
    }
    return -1.0f;
}
}
}   // namespace f3m_0047cf30

// @f3 0x0046d800 (community match, verified in this file)
#include <math.h>
extern const double DAT_00f4b250[112][3];
namespace f3m_0046d800 {

struct PointD {
    float x;
    float y;
    float z;
    PointD() {}
    PointD(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    PointD& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

struct BoundD {
    PointD center;
    float radius;
};

struct UpdateDataD {
    float time;
    bool b0;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
    UpdateDataD() : time(0.0f), b0(false), b1(false), b2(false), b3(false), b4(false) {}
};

struct GeomDataD {
    int unk00; int unk04; int unk08; int unk0c;
    BoundD bound;
    PointD* vertices;
    void FUN_008313b0(bool changed);
};

struct GeomD {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4;
    GeomDataD* data;
    void FUN_008268a0();
};

struct NodeD {
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void UpdateD();
    void FUN_008264c0(UpdateDataD* data);
};


struct ScaledShapeD {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    float unk18;
    float unk1c;
    float unk20;
    GeomD* unk24;
    int unk28;
    NodeD* unk2c;
    void FUN_0046d800(float scale);
};

// pdb: BGSPrimitiveSphere::SetRadius | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: fRadius
void ScaledShapeD::FUN_0046d800(float scale)
{
    scale = fabs(scale);
    if (unk24) {
        PointD* v = unk24->data->vertices;
        GeomDataD* data = unk24->data;
        for (int i = 0; i < 112; i++) {
            v[i].x = (float)DAT_00f4b250[i][0];
            v[i].y = (float)DAT_00f4b250[i][1];
            v[i].z = (float)DAT_00f4b250[i][2];
            v[i] *= scale;
        }
        data->FUN_008313b0(true);
    }
    unk18 = unk1c = unk20 = scale;
    UpdateDataD ud;
    if (unk2c) {
        PointD center(0.0f, 0.0f, 0.0f);
        BoundD& bound = unk24->data->bound;
        bound.center = center;
        bound.radius = scale;
        unk2c->FUN_008264c0(&ud);
        unk24->FUN_008268a0();
        unk2c->UpdateD();
    }
}
}   // namespace f3m_0046d800

// @f3 0x00479c00 (community match, verified in this file)
#include <stddef.h>
namespace n479c00 {
void* __cdecl FUN_0089eb90(unsigned int bytes);
void __cdecl FUN_0089ec10(void* memory);
void* __cdecl FUN_0089e810(unsigned int bytes);

class S479c00_Heap
{
public:
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};
extern S479c00_Heap DAT_01090a78;

class NiPoint3
{
public:
    float x, y, z;

    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

struct FUN_0046c350
{
    float r;
    float g;
    float b;
    float a;
    FUN_0046c350();
    static void* operator new[](size_t bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete[](void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
};

struct FUN_00af2240
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
    FUN_00af2240();
    static void* operator new(size_t bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
};

struct FUN_0083f490
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
    FUN_0083f490(unsigned short vertexCount, NiPoint3* vertices, NiPoint3* normals,
        FUN_0046c350* colors, void* textures, int textureSets, int dataFlags,
        unsigned short triangleCount, unsigned short* triangles);
    void FUN_004236f0(FUN_00af2240* property);
    static void* operator new(size_t bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
};

void __cdecl FUN_00ade300(FUN_0083f490* shape, int a, int b);

// pdb: MakeTriPoint | GlobalFunc.obj | fnv360_0822_retail, call_gap, low
// pdb params: afDrawSize, aColor, abWithNoLightingProp
FUN_0083f490* FUN_00479c00(float radius, const FUN_0046c350* color, bool addProperty)
{
    NiPoint3* vertices = (NiPoint3*)DAT_01090a78.FUN_0086b930(6 * sizeof(NiPoint3));
    vertices[0] = NiPoint3(0.0f, 0.0f, radius * 1.4142135f);
    float negRadius = -radius;
    vertices[1] = NiPoint3(negRadius, radius, 0.0f);
    vertices[2] = NiPoint3(radius, radius, 0.0f);
    vertices[3] = NiPoint3(radius, negRadius, 0.0f);
    vertices[4] = NiPoint3(negRadius, negRadius, 0.0f);
    vertices[5] = NiPoint3(0.0f, 0.0f, negRadius * 1.4142135f);

    FUN_0046c350* colors = new FUN_0046c350[6];
    for (int i = 0; i < 6; i++)
        colors[i] = *color;

    unsigned short* triangles = (unsigned short*)FUN_0089e810(24 * sizeof(unsigned short));
    triangles[0] = 0;  triangles[1] = 2;  triangles[2] = 1;
    triangles[3] = 0;  triangles[4] = 3;  triangles[5] = 2;
    triangles[6] = 0;  triangles[7] = 4;  triangles[8] = 3;
    triangles[9] = 0;  triangles[10] = 1; triangles[11] = 4;
    triangles[12] = 1; triangles[13] = 2; triangles[14] = 5;
    triangles[15] = 2; triangles[16] = 3; triangles[17] = 5;
    triangles[18] = 3; triangles[19] = 4; triangles[20] = 5;
    triangles[21] = 4; triangles[22] = 1; triangles[23] = 5;

    FUN_0083f490* shape = new FUN_0083f490(6, vertices, 0, colors, 0, 0, 0, 8, triangles);
    if (addProperty)
    {
        shape->FUN_004236f0(new FUN_00af2240);
        FUN_00ade300(shape, 0, 0);
    }
    return shape;
}
}

// @f3 0x004617a0 (community match, verified in this file)
namespace f3m_004617a0 {
namespace f3m_004617a0 {

struct Anim {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void Deactivate(float time, bool b);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    float unk2C;
    float unk30;
    int unk34, unk38, unk3C, unk40;
    int unk44;
    int unk48, unk4C, unk50, unk54;
    void* unk58;
    void FUN_008ae930(float time, bool b);
    float Length() const { return unk30 - unk2C; }
    void FUN_008ac830(float time, bool b);
};

struct Controller {
    void FUN_0044db80(void* seq, float time);
};

struct IntTriple {
    int unk00, unk04, unk08;
};

struct AnimSlot {
    Anim* anim;
    int unk04;
    int unk08;
};

struct Owner {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    short unk50;
    short animId52[6];
    short unk5E;
    int unk60, unk64;
    IntTriple unk68[2];
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    short unkA0;
    short animIdA2[6];
    short unkAE;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    float unkD0;
    float unkD4;
    Controller* unkD8;
    int unkDC, unkE0, unkE4, unkE8;
    AnimSlot anims[2];

    __forceinline void StopAnim(int i)
    {
        if (unkD8 && anims[i].anim && anims[i].anim->unk44) {
            if (anims[i].anim->unk58)
                unkD8->FUN_0044db80(anims[i].anim->unk58, 0.0f);
            anims[i].anim->Deactivate(0.0f, false);
        }
        anims[i].anim = 0;
        animId52[i * 3] = 0xff;
        animIdA2[i * 3] = 0xff;
        unk68[i].unk00 = -1;
    }
    void Animation_PlayGroup(int id, int a, int b, int c);
    void FUN_004617a0(float t);
};

// pdb: Animation::SetLipTime | Animation.obj | fnv360_0721_beta, call_seq, medium
// pdb params: afPercent
void Owner::FUN_004617a0(float t)
{
    if (t == 0.0f) {
        if (anims[0].anim) {
            anims[0].anim->FUN_008ae930(0.0f, true);
            StopAnim(0);
        }
        return;
    }
    if (!anims[0].anim) {
        Animation_PlayGroup(0xa6, 1, -1, -1);
        if (anims[0].anim)
            anims[0].anim->FUN_008ae930(anims[0].anim->unk2C + unkD0, true);
    }
    if (anims[0].anim && anims[0].anim->unk44 == 1) {
        float v = anims[0].anim->Length() * t + anims[0].anim->unk2C;
        unkD4 = v;
        anims[0].anim->FUN_008ac830(v - unkD0, true);
    }
}

}
}   // namespace f3m_004617a0

// @f3 0x00460660 (community match, verified in this file)
namespace S460660 {

struct S460660_Pt3 { float x, y, z; };

struct S460660_Ref {
    virtual void v00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount() { if (::InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T> struct S460660_Ptr {
    T* m_pObject;
    S460660_Ptr() : m_pObject(0) {}
    ~S460660_Ptr() { if (m_pObject) m_pObject->DecRefCount(); }
    S460660_Ptr& operator=(T* o)
    {
        if (m_pObject != o) {
            if (m_pObject) m_pObject->DecRefCount();
            m_pObject = o;
        }
        return *this;
    }
};

struct S460660_Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern S460660_Heap DAT_01090a78;
extern S460660_Pt3 DAT_0108ec68;
void* __cdecl FUN_0089e810(unsigned int size);
struct S460660_MapBase {
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    S460660_MapBase(unsigned int hashSize)
    {
        m_uiHashSize = hashSize;
        m_uiCount = 0;
        m_ppkHashTable = (void**)FUN_0089e810(sizeof(void*) * hashSize);
        memset(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
    }
    virtual ~S460660_MapBase();
};
struct S460660_Map : S460660_MapBase {
    S460660_Map(unsigned int hashSize) : S460660_MapBase(hashSize) {}
    virtual ~S460660_Map();
};
}

struct FUN_00460660 {
    char unk00;
    int unk04;
    S460660::S460660_Ptr<S460660::S460660_Ref> unk08;
    int unk0c;
    S460660::S460660_Pt3 unk10;
    S460660::S460660_Pt3 unk1c;
    int unk28[8];
    float unk48;
    int unk4c[4];
    int unk5c[8];
    int unk7c[8];
    int unk9c[4];
    int unkac[8];
    char unkcc;
    bool unkcd;
    float unkd0;
    int unkd4;
    S460660::S460660_Ptr<S460660::S460660_Ref> unkd8;
    S460660::S460660_Map* unkdc;
    int unke0[8];
    int unk100;
    S460660::S460660_Ptr<S460660::S460660_Ref> unk104;
    int unk108;
    float unk10c;
    float unk110;
    char unk114;
    short unk116;
    S460660::S460660_Ptr<S460660::S460660_Ref> unk118;
    S460660::S460660_Ptr<S460660::S460660_Ref> unk11c;
    S460660::S460660_Ptr<S460660::S460660_Ref> unk120[2];
    S460660::S460660_Ptr<S460660::S460660_Ref> unk128;
    int unk12c;
    FUN_00460660();
};

// pdb: Animation::Animation | Animation.obj | fnv360_0822_retail, call_gap, medium
FUN_00460660::FUN_00460660() : unk108(0), unk12c(0)
{
    unk08 = 0;
    unk0c = 0;
    unk10 = S460660::DAT_0108ec68;
    unk1c = S460660::DAT_0108ec68;
    unk48 = 0.0f;
    unkd0 = 0.0f;
    unkcc = (char)0xff;
    unk114 = 0;
    unk00 = 0;
    unk04 = 0;
    unk100 = 0;
    unkd8 = 0;
    unk118 = 0;
    unk11c = 0;
    unk120[0] = 0;
    unk120[1] = 0;
    unkdc = new S460660::S460660_Map(101);
    memset(unk28, 0, sizeof(unk28));
    memset(unke0, 0, sizeof(unke0));
    memset(unk4c, 0xff, sizeof(unk4c));
    memset(unk9c, 0xff, sizeof(unk9c));
    memset(unk5c, 0xff, sizeof(unk5c));
    memset(unk7c, 0xff, sizeof(unk7c));
    memset(unkac, 0xff, sizeof(unkac));
    unk10c = 1.0f;
    unk110 = 1.0f;
    unk116 = 0xff;
    unkcd = false;
}

// @f3 0x00477e00 (community match, verified in this file)
namespace f3m_00477e00 {
struct TypeInfo { const char* name; TypeInfo* base; };
extern TypeInfo DAT_01092a48;
struct Comp7e00 { float FUN_008f8410(); };
struct T7e00;
struct U7e00 {
    virtual void vf000();
    virtual void vf004();
    virtual TypeInfo* vf008();
    int unk04;
    int unk08;
    int unk0C;
    T7e00* ptr10;
};
struct T7e00 {
    virtual void vf000();
    virtual void vf004();
    virtual TypeInfo* vf008();
    virtual T7e00* vf00C();
    int unk04;
    T7e00* child08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    U7e00* unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    T7e00** itemsA0;
    unsigned short capA4;
    unsigned short countA6;
    int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    Comp7e00 compD0;
};
inline bool IsKindOf7e00(U7e00* o, const TypeInfo* type)
{
    for (TypeInfo* t = o->vf008(); t; t = t->base)
        if (t == type)
            return true;
    return false;
}

// pdb: FindHeaviestRigidBody | GlobalFunc.obj | fnv360_0822_retail, objrun, medium
// pdb params: ap3D
T7e00* __cdecl FUN_00477e00(T7e00* obj)
{
    if (obj)
    {
    T7e00* best = 0;
    T7e00* node = obj->vf00C();
    if (node) {
        unsigned int count = node->countA6;
        for (unsigned int i = 0; i < count; i++) {
            T7e00* item = node->itemsA0[i];
            T7e00* r = FUN_00477e00(item);
            if (r) {
                if (!best ||
                    (best->child08 ? best->child08->compD0.FUN_008f8410() : 0.0f) <
                    (r->child08 ? r->child08->compD0.FUN_008f8410() : 0.0f))
                    best = r;
            }
        }
    }
    U7e00* u = obj->unk1C;
    T7e00* extra;
    if (u) {
        U7e00* p = IsKindOf7e00(u, &DAT_01092a48) ? u : 0;
        extra = p ? p->ptr10 : 0;
    } else
        extra = 0;
    if (best && (!extra || (extra->child08 ? extra->child08->compD0.FUN_008f8410() : 0.0f) < (best->child08 ? best->child08->compD0.FUN_008f8410() : 0.0f)))
        return best;
    return extra;
    }
    return 0;
}
}

// @f3 0x0047d970 (community match, verified in this file)
extern float DAT_00db38b8;
extern double DAT_00dba730;
extern const char DAT_00f460fc[], DAT_00f49edc[];

struct S47d970_Component {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
};

struct S47d970_Form {
    void* vtbl;
    unsigned char typeID;
};

struct S47d970_Cast {
    void* vtbl;
    unsigned char unk04;
};

struct S47d970_Player;
extern S47d970_Player* DAT_0107a104;

S47d970_Cast* __cdecl FUN_00c0050a(void* object, int unused, const void* fromType, const void* toType, int isRef);
unsigned int FUN_00456720(S47d970_Form* form);
float FUN_00583a40(S47d970_Component* target, S47d970_Form* form, float value, float mult, int a, int b);
float FUN_0047ca30(float value, float step);
float FUN_00582720(unsigned short level, float value);
float FUN_0044a250(float v);

struct S47d970_Owner {
    int unk00;
    int unk04;
    S47d970_Form* form;
    float FUN_0047cf30(int mode);
    float FUN_0047d970(int a, int b, int c);
};

float S47d970_Owner::FUN_0047d970(int a, int b, int c)
{
    float result = DAT_00db38b8;
    int kind;
    switch (form->typeID) {
    case 0x18:
    case 0x1A:
        kind = 4;
        break;
    case 0x28:
        kind = 3;
        break;
    default:
        kind = 5;
        break;
    }
    S47d970_Cast* cast = FUN_00c0050a(form, 0, DAT_00f460fc, DAT_00f49edc, 0);
    if (!cast) {
      if (kind == 1) {
        S47d970_Form* f = form;
        if (f->typeID == 0x28) {
            ((S47d970_Component*)((char*)f + 0x9c))->v10();
            double cost = FUN_0047cf30(0);
            float perUnit = cost / (float)FUN_00456720(f);
            S47d970_Component* target = DAT_0107a104 ? (S47d970_Component*)((char*)DAT_0107a104 + 0x9c) : 0;
            result = FUN_00583a40(target, f, perUnit, 1.0f, 1, 0);
        }
        result = FUN_0047ca30(result, 1.0f);
    } else {
        S47d970_Form* f = form;
        if (f->typeID == 0x18) {
            double cost = FUN_0047cf30(0);
            float perUnit = cost / (float)FUN_00456720(f);
            float level = *(unsigned short*)((char*)f + 0x178) / DAT_00dba730;
            result = FUN_0044a250(FUN_00582720((unsigned short)level, perUnit));
        }
      }
    } else {
        result = (float)cast->unk04;
    }
    return result;
}

// @f3 0x004704a0 (community match, verified in this file)
namespace f3w_4704a0 {

struct Owner;

struct Pair
{
    Owner* target;
    void* value;
};

void __cdecl FUN_00470480(int a, int b, Pair* p);

struct Extra
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
    virtual void vb4();
    virtual void vb8();
    virtual void Visit(void (__cdecl* visitor)(int, int, Pair*), Pair* pair);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int index;
};

struct Geometry
{
    Extra* FUN_00826590(unsigned int kind);
};

struct Kind
{
    int unk00;
    unsigned char type;
};

struct Ref
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Kind* kind;
    bool FUN_00424ee0();
};

struct Lookup
{
    bool FUN_0040e820(Ref* ref, bool* found);
};

struct Node;

struct Object
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node* AsNode();
    virtual void v10();
    virtual void v14();
    virtual Geometry* AsGeometry();
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
    unsigned char flags;
};

struct Node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Test();
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
    int unk9C;
    Object** children;
    unsigned short capacity;
    unsigned short count;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    Ref* ref;
};

}

extern f3w_4704a0::Lookup* DAT_0106e018;
extern void* DAT_0106e304;

namespace f3w_4704a0 {

struct Owner
{
    void* value;
    void FUN_004704a0(Object* object, bool force);
};

// pdb: BGSTextureUseMap::CollectTexUseDataRecursive | BGSTextureUseMap.obj | fnv360_0822_retail, call_gap, low
// pdb params: ap3D, abCheckActors
void Owner::FUN_004704a0(Object* object, bool force)
{
    Pair pair;
    pair.target = this;
    if (!object || (object->flags & 1))
        return;
    Node* node = object->AsNode();
    if (node) {
        bool hit = false;
        bool found = false;
        bool restore = false;
        if (node->Test()) {
            Ref* ref = node->ref;
            if (DAT_0106e018) {
                DAT_0106e018->FUN_0040e820(ref, &found);
                hit = found;
            }
            if (ref) {
                if (hit)
                    return;
                unsigned int type = ref->kind->type;
                if (type >= 0x2a && type <= 0x2d && !force)
                    return;
                if (ref->FUN_00424ee0())
                    return;
                restore = true;
                DAT_0106e304 = ref;
            } else if (hit) {
                return;
            }
        }
        unsigned int count = node->count;
        for (unsigned int i = 0; i < count; i++)
            pair.target->FUN_004704a0(node->children[i], force);
        if (restore)
            DAT_0106e304 = 0;
        return;
    }
    Geometry* geom = object->AsGeometry();
    if (!geom)
        return;
    Extra* extra = geom->FUN_00826590(3);
    if (!extra)
        return;
    Extra* typed = extra->index != -1 ? extra : 0;
    if (!typed)
        return;
    pair.target = this;
    pair.value = DAT_0106e304 ? DAT_0106e304 : value;
    typed->Visit(FUN_00470480, &pair);
}

}

// @f3 0x0046b800 (community match, verified in this file)
namespace f3m_0046b800 {
// Records the owning object on a registry entry when it has none, then runs it.

struct F3Entry_46b800
{
    char pad[0x48];
    void* pOwner;
};

class F3Owner_46b800
{
};

class F3Result_46b800
{
  public:
    void FUN_0046ad40();
};

void* __stdcall FUN_0046b690(void* pEntry, int iArg2, int iArg3);

void __fastcall FUN_0046b800(F3Owner_46b800* pThis, int iUnused, F3Entry_46b800* pEntry,
                   int iArg2, int iArg3)
{
    if (!pEntry->pOwner)
        pEntry->pOwner = pThis;
    ((F3Result_46b800*)FUN_0046b690(pEntry, iArg2, iArg3))->FUN_0046ad40();
}
}   // namespace f3m_0046b800

// @f3 0x00478ab0 (community match, verified in this file)
namespace f3m_00478ab0 {
// Tracks the most recently seen entry of a list.

struct F3Node_478ab0
{
    char pad00[8];
    int iValue8;
};

struct F3List_478ab0
{
    char pad00[0xc];
    int iSeen0c;
    int iKey10;
    int iSaved14;
};

// pdb: GetHavokWorldObjectIndex | GlobalFunc.obj | fnv360_0822_retail, objrun, low
void __cdecl FUN_00478ab0(void* pHolder, F3List_478ab0* pList)
{
    F3Node_478ab0* pNode = *(F3Node_478ab0**)((char*)pHolder + 0x10);
    if (!pNode)
        return;
    int iValue = pNode->iValue8;
    if (!iValue)
        return;
    if (iValue == pList->iKey10)
        pList->iSaved14 = pList->iSeen0c;
    pList->iSeen0c++;
}
}   // namespace f3m_00478ab0

// @f3 0x00474930 (community match, verified in this file)
namespace f3m_00474930 {
namespace f3m_00474930 {
struct Arg {
    int unk00;
    int unk04;
    int id;
};

struct Entry {
    int id;
    void (__cdecl *fn)(void*, Arg*);
};

struct Manager {
    int unk00;
    void* ctx;
    int unk08;
    Entry** entries;
    unsigned short unk10;
    unsigned short count;

    void BSAnimNoteReceiver_Update(Arg* arg);
};

// pdb: BSAnimNoteReceiver::Update | BSAnimNoteReceiver.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Manager::BSAnimNoteReceiver_Update(Arg* arg)
{
    for (unsigned int i = 0; i < count; ++i) {
        Entry* entry = entries[i];
        if (entry->id == arg->id)
            entry->fn(ctx, arg);
    }
}
}
}   // namespace f3m_00474930

// @f3 0x0047dca0 (community match, verified in this file)
namespace f3m_0047dca0 {
struct SubItem {
    unsigned short FUN_004125c0(int a, int b);
};

struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual int GetId();
};

struct Ent {
    int form;
    char kind;
    char b5;
};

struct Data {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84;
    Ent* ent;
    bool TESSaveLoadGame_UseSaveGameBlocks();
};

struct Node {
    SubItem* item;
    Node* next;
    bool Empty() const { return next == 0 && item == 0; }
    SubItem* Get() const { return item; }
};

struct Item {
    Node* head;
    unsigned short FUN_0047dca0();
};

extern Data* DAT_01079ca4;
extern bool DAT_01079d20;
extern const char DAT_00dc0bd0[];
extern const char DAT_00db4360[];
Obj* __cdecl TESForm_GetFormByNumericID(int form);
void __cdecl FUN_00c24b70(const char* fmt, ...);

// pdb: ItemChange::GetSaveSize | InventoryChanges.obj | fnv360_0721_retail, call_seq, medium
unsigned short Item::FUN_0047dca0()
{
    unsigned short size = 0;
    if (DAT_01079ca4->TESSaveLoadGame_UseSaveGameBlocks())
        size = 6;
    size += 12;
    for (Node* n = head; n; n = n->next) {
        if (n->Empty())
            break;
        size += n->Get()->FUN_004125c0(0, 0);
    }
    if (DAT_01079d20) {
        Ent* e = DAT_01079ca4->ent;
        if (e) {
            Obj* o = TESForm_GetFormByNumericID(e->form);
            FUN_00c24b70(DAT_00db4360, size, e->form, o->GetId(), *(int*)&e->b5, 0x530, DAT_00dc0bd0);
        }
    }
    return size;
}
}

// @f3 0x0047df50 (community match, verified in this file)
namespace f3m_0047df50 {
namespace Visit47df50 {
struct Item {void FUN_00419d30(void*,void*);};
struct Node {Item* item;Node* next;};
struct List {Node* head;int unk04;void* context;void FUN_0047df50(void*);};
// pdb: ItemChange::InitLoadGame | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apLoadGameBuffer
void List::FUN_0047df50(void* arg){for(Node* node=head;node;node=node->next){if(node->item)node->item->FUN_00419d30(arg,context);}}
}
}   // namespace f3m_0047df50

// @f3 0x0047b180 (community match, verified in this file)
namespace f3m_0047b180 {
namespace Set47b180 {
struct Object {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
 int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54;
 unsigned x,y,z;
 void FUN_0047b180(float a,float b,float c);
};
inline unsigned bits(float f) { return *reinterpret_cast<unsigned*>(&f); }
// pdb: Actor::ModHeading | Actor.obj | tesv_win, objrun_open, low
void Object::FUN_0047b180(float a,float b,float c) {
 struct Triple {float x,y,z;}; volatile Triple local;
 local.x=a; x=*reinterpret_cast<volatile unsigned*>(&local.x);
 local.y=b; y=*reinterpret_cast<volatile unsigned*>(&local.y);
 local.z=c; z=*reinterpret_cast<volatile unsigned*>(&local.z);
}
}

}   // namespace f3m_0047b180

// @f3 0x00478b30 (community match, verified in this file)
namespace f3m_00478b30 {
namespace Visit478b30 {
struct Item {int unk00,unk04;void* value;};
struct Input {int unk00,unk04,unk08,unk0c;Item* item;};
struct Output {int unk00,unk04,unk08;int count;void* selected;int target;};
// pdb: GetHavokWorldObjectByIndex | GlobalFunc.obj | fnv360_0822_retail, objrun, low
void FUN_00478b30(Input* input,Output* output) {
 Item* item=input->item;
 if(item) {
  void* value=item->value;
  if(value) {
   if(output->count==output->target) output->selected=value;
   ++output->count;
  }
 }
 ++output->count;
}
}
}   // namespace f3m_00478b30

// @f3 0x004748f0 (community match, verified in this file)
namespace f3m_004748f0 {
namespace Find4748f0 {
struct Entry {unsigned first,second;};
struct Object {int unk00,unk04,unk08;Entry** data;unsigned short capacity,count;
 int FUN_004748f0(unsigned first,unsigned second);
};
// pdb: BSAnimNoteReceiver::Registered | BSAnimNoteReceiver.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aeType, apCallbackFunc
int Object::FUN_004748f0(unsigned first,unsigned second) {
 int result=-1;
 for(unsigned i=0;i<count;++i)if(data[i]->first==first && data[i]->second==second)result=i;
 return result;
}
}
}   // namespace f3m_004748f0

// @f3 0x0047b370 (community match, verified in this file)
namespace f3m_0047b370 {
namespace Remove47b370 {
struct Item {void FUN_004e50d0(int);};
struct Object {
 virtual void v00();virtual void v04();virtual void v08();virtual void v0c();
 virtual void v10();virtual void v14();virtual void v18();virtual void remove(unsigned,unsigned);
 int unk04,unk08;unsigned dimension;Item** data;
 Item** at(unsigned row,unsigned col){if(row<dimension && col<dimension)return data+row*dimension+col;return 0;}
 void GridCellArray_Detach(unsigned,unsigned);
};
// pdb: GridCellArray::Detach | GridCell.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
void Object::GridCellArray_Detach(unsigned row,unsigned col) {
 Item* item=*at(row,col);
 if(item){item->FUN_004e50d0(1);remove(row,col);}
}
}
}   // namespace f3m_0047b370

// @f3 0x0047b810 (community match, verified in this file)
namespace f3m_0047b810 {
namespace Set47b810 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Ref {virtual void v00();virtual void destroy();volatile long refs;};
struct Object {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
 int unk30,unk34,status,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 Ref* ref;void FUN_0047b810(Ref*);
};
void Object::FUN_0047b810(Ref* value) {
 Ref* old=ref;
 if(old!=value){
  if(old && InterlockedDecrement(&old->refs)==0)old->destroy();
  ref=value;
  if(value)InterlockedIncrement(&value->refs);
 }
 status=0;
}
}

}   // namespace f3m_0047b810

// @f3 0x0047cb80 (community match, verified in this file)
namespace Scalar47cb80 {
struct Base {virtual void slot0();
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
virtual bool predicate();};struct CastResult {int unk00;float value;};
extern char DAT_00f4621c[],DAT_00f460fc[];extern float DAT_00db38b8;
CastResult* FUN_00c0050a(Base*,int,void*,void*,int);
struct Object {int unk00,unk04;Base* object;float FUN_0047cb80(void*,void*,void*);};
// pdb: InventoryChanges::ResetCachedWeights | InventoryChanges.obj | fnv360_1110_retail, objrun, medium
float Object::FUN_0047cb80(void*,void*,void*){float result=DAT_00db38b8;CastResult* cast=FUN_00c0050a(object,0,DAT_00f460fc,DAT_00f4621c,0);if(cast){result=cast->value;if(object->predicate())result=0;}return result;}
}

// @f3 0x00468d80 (community match, verified in this file)
namespace f3m_00468d80 {

namespace n468d80 {
struct Matrix3 {
    float m[3][3];
    void NiMatrix3_MakeZRotation(float angle);
};
}

// pdb: NiMatrix3::MakeZRotation | BGSDecalManager.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_gap) + skyrim(call_gap), high
void n468d80::Matrix3::NiMatrix3_MakeZRotation(float angle)
{
    float s,c;
    fnv_SinCos(angle,s,c);
    m[0][0] = c;
    m[0][1] = s;
    m[0][2] = 0.0f;
    m[1][0] = -s;
    m[1][1] = c;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
}
}   // namespace f3m_00468d80

// @f3 0x004646a0 (community match, verified in this file)
namespace f3m_004646a0 {
extern __declspec(thread) int allocationTag;
struct TagScope {int old; TagScope(int tag):old(allocationTag){allocationTag=tag;} ~TagScope(){allocationTag=old;}};
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct Item;
struct Lookup { int FUN_0042cff0(Item* item); };
extern Lookup* DAT_0106ca70;
struct Node {
    Item* item;
    Node* next;
    void FUN_006c8220();
    ~Node() { FUN_006c8220(); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    bool FUN_00645c20();
    void RemoveHead()
    {
        Node* n = next;
        if (n) {
            next = n->next;
            item = n->item;
            n->next = 0;
            delete n;
        } else {
            item = 0;
        }
    }
};
struct Owner {
    int unk00;
    bool Animation_ShouldQueueSequenceCloning();
    void FUN_00461a70(int value, bool flag);
    void FUN_004646a0(Node* list);
};
// pdb: Animation::AddAnimationsFromList | Animation.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apFileList
void Owner::FUN_004646a0(Node* list)
{
    if (!list)
        return;
    TagScope scope(0x33);
    bool flag = Animation_ShouldQueueSequenceCloning();
    while (!list->FUN_00645c20()) {
        Item* item = list->item;
        int value=DAT_0106ca70->FUN_0042cff0(item);
        FUN_00461a70(value,flag);
        DAT_01090a78.FUN_0086ba60(item);
        list->RemoveHead();
    }
    delete list;
}
}

// @f3 0x00460600 (community match, verified in this file)
namespace c460600 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;

struct Item {
    int unk00;
    long refCount04;
    void IncRef() { InterlockedIncrement(&refCount04); }
};

struct Node {
    Node* next;
    Node* prev;
    Item* item;
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
};

struct List {
    Node* head;
    Node* tail;
    int count;
    void AddTail(Item* item)
    {
        Node* node = new Node;
        node->item = item;
        node->next = 0;
        node->prev = tail;
        if (tail)
            tail->next = node;
        else
            head = node;
        tail = node;
        ++count;
    }
};

struct Owner {
    int unk00;
    List* list04;
    void FUN_00460600(Item* item, int unused);
};

// pdb: AnimSequenceMultiple::SetSequence | Animation.obj | fnv360_0822_retail, vtable, medium
// pdb params: apSeq, abReleaseModelLoader
void Owner::FUN_00460600(Item* item, int unused)
{
    item->IncRef();
    list04->AddTail(item);
}
}

// @f3 0x0047def0 (community match, verified in this file)
namespace f3m_0047def0 {
namespace c47def0 {
struct Stream {
    void FUN_006e17e0(int value, int flags);
    void FUN_006e1830(void* data, int size, int flags);
    int BGSSaveGameBuffer_StartVariableSizedValue();
    void FUN_006e16e0(int count, int position);
};
struct Item { void FUN_00415080(Stream* stream); };
struct Node {
    Item* item;
    Node* next;
};
struct Owner {
    Node* head;
    int unk04;
    int unk08;
    void FUN_0047def0(Stream* stream);
};

// pdb: ItemChange::SaveGame | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apSaveGameBuffer
void Owner::FUN_0047def0(Stream* stream)
{
    stream->FUN_006e17e0(unk08, 0);
    stream->FUN_006e1830(&unk04, 4, 0);
    int count = 0;
    int position = stream->BGSSaveGameBuffer_StartVariableSizedValue();
    for (Node* node = head; node; node = node->next) {
        if (node->item) {
            node->item->FUN_00415080(stream);
            count++;
        }
    }
    stream->FUN_006e16e0(count, position);
}
}
}   // namespace f3m_0047def0

// @f3 0x00468f40 (community match, verified in this file)
extern float DAT_01092a50;
extern float DAT_01092a54;
extern float DAT_01092a58;
extern float DAT_01092a5c;
namespace f3m_00468f40 {
namespace Small468f40 {
struct Point3; struct hkpAllRayHitCollector;
struct __declspec(align(16)) Query {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned char flag20, unk21, unk22, unk23;
    unsigned filter;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    volatile float fraction40;
    int unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    int unk78, unk7c, unk80, unk84, unk88, unk8c;
    float direction90, direction94, direction98, direction9c;
    int unkA0;
    unsigned resultCount;
    hkpAllRayHitCollector* collector;
    unsigned char flagAC, unkAD, unkAE, unkAF;
    Query* FUN_00468f40();
};

__declspec(noinline) Query* Query::FUN_00468f40()
{
    flag20 = 0;
    filter = 0;
    fraction40 = 1.0f;
    unk70 = 0;
    unk80 = 0;
    unk44 = -1;
    unk50 = -1;
    unkA0 = 0;
    resultCount = 0;
    collector = 0;
    flagAC = 0;
    direction90 = DAT_01092a50;
    direction94 = DAT_01092a54;
    direction98 = DAT_01092a58;
    direction9c = DAT_01092a5c;
    return this;
}

}
}   // namespace f3m_00468f40

// @f3 0x0046c200 (community match, verified in this file)
#include <new>
namespace f3m_0046c200 {
namespace New281 {
void* FUN_0089eb90(unsigned);void FUN_0089e850(void*);extern char DAT_00f72574,DAT_0108ec68;
struct Pair {float x,y;Pair(float a,float b):x(a),y(b){}};
struct FUN_0046c0f0 {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8;FUN_0046c0f0(void*,const Pair&,void*);static void* operator new(unsigned n){return FUN_0089eb90(n);}static void operator delete(void*p){FUN_0089e850(p);}};
struct Object {int unk00,unk04,unk08,unk0c,unk10,unk14;float x;int unk1c;float y;FUN_0046c0f0* FUN_0046c200();};
// pdb: BGSPrimitivePlane::MakeOcclusionPlane | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
FUN_0046c0f0* Object::FUN_0046c200(){return new FUN_0046c0f0(&DAT_0108ec68,Pair(x,y),&DAT_00f72574);}
}
}   // namespace f3m_0046c200

// @f3 0x00477fa0 (community match, verified in this file)
namespace f3m_00477fa0 {
namespace Find331 {
struct Controller {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;int type;};struct Object{virtual void v0();virtual void v4();virtual void v8();virtual Object* node();virtual void v10();virtual void v14();virtual void* leaf();int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; Object** children;unsigned short capacity,count;Controller* FUN_00826590(int);};
int valid(Controller* c){return c->type>=7&&c->type<=11;}
// pdb: FindPerPixelLighting_Recurse | GlobalFunc.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apNode
Controller* FUN_00477fa0(Object* object){unsigned short count=object->count;Controller* result=0;if(!count)return 0;for(unsigned i=0;i<count&&!result;++i){Object* child=object->children[i];if(child){if(child->node())result=FUN_00477fa0(child);else if(child->leaf()){Controller* c=child->FUN_00826590(3);if(c){c=valid(c)?c:0;if(c)return c;}}}}return result;}
}
}   // namespace f3m_00477fa0

// @f3 0x004775e0 (community match, verified in this file)
namespace f3m_004775e0 {
namespace Insert340 {
// pdb: NiTMapBase<DFALL<NiTMapItem<unsigned int,VertexDist> >,unsigned int,VertexDist>::SetAt | GlobalFunc.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: key, val
struct Vec3{float x,y,z;};struct Node{Node* next;int key;Vec3 value;};struct Map{virtual void v0();virtual unsigned hash(int);virtual bool equal(int,int);virtual void initialize(Node*,int,Vec3);virtual void v10();virtual Node* create();unsigned capacity;Node** table;unsigned size;void FUN_004775e0(int,Vec3);};void Map::FUN_004775e0(int key,Vec3 value){unsigned index=hash(key);Node* node=table[index];while(node){if(equal(key,node->key)){node->value=value;return;}node=node->next;}node=create();initialize(node,key,value);node->next=table[index];table[index]=node;++size;}
}
}   // namespace f3m_004775e0

// @f3 0x0047b460 (community match, verified in this file)
namespace f3m_0047b460 {
namespace Swap345 {
// pdb: GridCellArray::SwapItem | GridCell.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
struct Matrix{virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual void v14();virtual void v18();virtual void clear(unsigned,unsigned);int unk04,unk08;unsigned size;int* data;int* get(unsigned r,unsigned c){return r<size&&c<size?data+r*size+c:0;}void set(unsigned r,unsigned c,const int* value){if(r<size&&c<size){if(value)data[r*size+c]=*value;else clear(r,c);}}void GridCellArray_SwapItem(unsigned,unsigned,unsigned,unsigned);};void Matrix::GridCellArray_SwapItem(unsigned r,unsigned c,unsigned r2,unsigned c2){int temp=*get(r,c);set(r,c,get(r2,c2));set(r2,c2,&temp);}
}
}   // namespace f3m_0047b460

// @f3 0x0046db30 (community match, verified in this file)
namespace f3m_0046db30 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace Construct358 {
struct Ref{virtual void v0();virtual void destroy();volatile long refs;void release(){if(!::InterlockedDecrement(&refs))destroy();}};
struct Ptr{Ref* p;void clear(){Ref* old=p;if(old){old->release();p=0;}}};
struct Base{Base();virtual ~Base();int kind,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;Ptr a;int unk28;Ptr b;};
struct FUN_0046db30:Base{FUN_0046db30();virtual ~FUN_0046db30();};
// pdb: BGSPrimitivePlane::BGSPrimitivePlane | BGSPrimitive.obj | fnv360_0822_retail, uvref, medium
FUN_0046db30::FUN_0046db30(){a.clear();b.clear();kind=3;}
}

}   // namespace f3m_0046db30

// @f3 0x0047d500 (community match, verified in this file)
extern const char DAT_00f460fc[], DAT_00f469f4[], DAT_00f46078[], DAT_00f46b24[];
extern const char* DAT_00f62e20;
namespace f3m_0047d500 {
namespace f3m_0047d500 {
struct ExtraList
{
    int FUN_0040abc0();
};
struct Holder
{
    ExtraList* list;
};
struct NPC
{
    int FUN_0054a930();
};
struct BipedModelForm
{
    const char* FUN_00452290(int sex);
};

void* __cdecl FUN_00c0050a(void* object, int unused, const void* baseType, const void* targetType, int isReference);
const char* __cdecl FUN_0045ba50(void* object, int arg);

struct Owner
{
    Holder* holder;
    int unk04;
    void* object;

    int FUN_0047d170()
    {
        if (holder)
        {
            ExtraList* list = holder->list;
            if (list && list->FUN_0040abc0())
                return list->FUN_0040abc0();
        }
        return 0;
    }

    __forceinline const char* GetModelPath(int arg)
    {
        int item = FUN_0047d170();
        BipedModelForm* biped = (BipedModelForm*)FUN_00c0050a(object, 0, DAT_00f460fc, DAT_00f469f4, 0);
        if (item && biped)
        {
            NPC* npc = (NPC*)FUN_00c0050a((void*)item, 0, DAT_00f46078, DAT_00f46b24, 0);
            if (npc)
            {
                const char* path = biped->FUN_00452290(npc->FUN_0054a930());
                if (path && *path)
                    return path;
            }
        }
        return FUN_0045ba50(object, arg);
    }

    const char* ItemChange_GetIconOne(int arg);
};

// pdb: ItemChange::GetIconOne | InventoryChanges.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
const char* Owner::ItemChange_GetIconOne(int arg)
{
    const char* path = GetModelPath(arg);
    if (path && *path)
        return path;
    return DAT_00f62e20;
}
}
}   // namespace f3m_0047d500

// @f3 0x0047b250 (community match, verified in this file)
namespace f3m_0047b250 {
// Model of FUN_0047B250 (77 bytes) - claim clm_2d999fec014049238d87, THIRD revision ✓ v2 reached 73 vs 77 with thirty differing lines and its diff named three concrete corrections: their build tests that value parameter the
// OTHER way round (a positive condition with the virtual call as the fall-through ✗✓ my polarity rule again ✓ ), it LOADS the array base from a pointer field at +0x10 before indexing ('mov ecx,[ecx+0x10]' ✗ ) where I had folded an
// inline member into one displacement, and its dispatch is two loads through the objects OWN table while my cast form collapsed to one ✓ 
class Grid47b { public:                                   // ORIG: thiscall member taking three stack parameters cleaned by the callee ('retn 0Ch' at every exit ✗✓ ) returning
                                     //     nothing ✓ The object is polymorphic: their build reads its leading dword as a table on the third path ('mov edx,[ecx] ; mov edx,[edx+1Ch]' ✗✓ ) so there IS an implicit four-byte table slot at
                                     //     +0x00 ✗ which my filler summation below accounts for ✓ (the sizing rule measured on a constructor match: include that implicit pointer in the sums or every field shifts by four ✗ ) 
                      virtual void fillerVirtual0() = 0;   virtual void fillerVirtual1() = 0;                      // table slots at +0x00 through
                      virtual void fillerVirtual2() = 0;   virtual void fillerVirtual3() = 0;                      //     +0x18 ✓✗→✓ SEVEN preceding entries because the dispatch their build performs sits at
                      virtual void fillerVirtual4() = 0;   virtual void fillerVirtual5() = 0;                      //     displacement TWENTY-EIGHT = entry index seven ✗ (my measured rule that table displacement equals entry count ✓ )
                      virtual void fillerVirtual6() = 0;   // the seventh filler, landing the live slot on +0x1C exactly ✓✗→✓ I let this compiler generate the dispatch by calling a real virtual member instead of
                                     //     hand-declaring a function pointer through a cast: my second pass wrote that cast form and produced ONE load plus 'call eax' ✗ while their build performs TWO loads ('mov edx,[ecx]' then
                                     //     'mov edx,[edx+1Ch]') and calls through EDX ✓ - which is what an actual virtual call looks like ✓ (the pointed-to-table filler form stays the right tool for LARGE displacements where counting
                                     //     members would be absurd; at +0x1C the honest class shape is available and matches better ✗✓ measured difference, worth recording against that standing rule ✓ ) 
                      virtual void queryWithTwoIndices(unsigned long first, unsigned long second);   // +0x1C: the slot their build calls with the receiver in ECX and TWO pushed
                                     //     parameters ✓ Their pushes are the value read from arg_4 FIRST then the one read from arg_0 SECOND ✗✓ so leftmost is that arg_4 value - I keep that odd-looking order exactly as measured rather
                                     //     than normalising it, because swapping it would change which argument their routine receives ✓ 
                      char padTo0C[0x08];            // +0x04..+0x0B untouched in this body ✓✗→✓ sized by summation INCLUDING that implicit table slot above so the stride field lands on
                                     //     +0x0C exactly ✗ (bracketed scalar filler member, my measured rule when live bytes are not adjacent ✓ ) 
                      unsigned long stride0C;        // +0x0C: read ONCE into EAX and then used THREE times - two above-or-equal compares and the multiplicand of that multiply ('cmp
                                     //     esi,eax' , 'cmp edx,eax' , 'imul eax,esi' ✗✓ ) - one cached value playing three roles ✓ (fetch-once rule with direct evidence ✓ ) 
                      void** dataAt10;               // +0x10: a POINTER FIELD that their build LOADS before indexing ('mov ecx,dword ptr [ecx+10h]' ✗✓ then 'lea eax,[ecx+eax*4]' off
                                     //     that loaded base ✓ ) - my second pass had this as an inline array member and so emitted no load at all, costing two bytes of extent ✗✓ It is a pointer to the row-major cell run, not the cells
                                     //     themselves ✓ (that extra indirection is also why their index math adds four-times-the-combined-index to a REGISTER rather than to the receiver with a displacement ✓ ) 
                      void GridCellArray_Set(unsigned long row, unsigned long column, void* value); };   // ORIG: three stack parameters, callee cleans twelve bytes ✗✓ all of them full
                                                  //     32-bit values here - no movzx anywhere on those operands ✓ 
// pdb: GridCellArray::Set | GridCell.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap_sim), high
void Grid47b::GridCellArray_Set(unsigned long row, unsigned long column, void* value) {   // ORIG: 'push edi ; mov edi,[esp+4+arg_8] ; test edi,edi' ✓✗→✓ the
                                     //     third parameter fetched into a saved register FIRST and tested against null before anything else in the function ✗ 
    if (value != 0) {                               // v3 POLARITY FIX ✓✗→✓✓ their build is 'test edi,edi ; je L_0038' - the virtual path being a block placed at the END of
                                       //     the function that the null case JUMPS TO ✓ while the storing path is the fall-through ✗ My second pass wrote the inverse condition and this compiler put the store in a jumped-over middle
                                       //     block instead ✗ So their source tests for NON-NULL and lets the polymorphic fallback be what follows ✓ (the positive-nested-condition polarity my notes keep confirming on other entries:
                                       //     refusals fall through, nested conditions are written positively ✗✓ ) 
        unsigned long stride = this->stride0C;      // ORIG: 'mov eax,[ecx+0Ch]' once before both range tests ✓✗→✓✓ then that same register is the multiplicand of
                                           //     'imul eax,esi' ✗ so one load serves two compares and one multiply - a plain local reproduces all three uses ✓ 
        void** cell;                                // ORIG: their build ends with an ADDRESS in EAX and performs ONE store shape reached from TWO blocks ✗✓ which proves an
                                           //     address variable exists in their source rather than two separate subscript writes ✓ 
        if (row >= stride || column >= stride) cell = 0;   // ORIG: 'cmp esi,eax ; jae badBlock' and 'cmp edx,eax ; jae SAME badBlock' where that
                                           //     block is 'xor eax,eax' ✗✓ both comparisons ABOVE-OR-EQUAL against the one cached field ✓ fixing them as unsigned greater-or-equal - a signed source form would have emitted jl/jge, and a
                                           //     strict-less-than form would not give two jae tests ✓ (mnemonic-to-operator rule again ✓ ) Their bad path then stores through that ZERO address ✗ genuine undefined behaviour in their own
                                           //     code, which I reproduce instead of adding the guard they do NOT have ✓ 
        else cell = &this->dataAt10[stride * row + column];   // ORIG: 'imul eax,esi ; add eax,edx ; mov ecx,[ecx+10h] ; lea
                                              //     eax,[ecx+eax*4]' ✓✗→✓✓ row-major two-dimensional indexing - stride times ROW plus COLUMN, scaled by four from the LOADED base ✗ which is what an array of arrays declaration
                                              //     produces ✓ (their build put that scale inside the LEA; my notes already record three spellings of such chained effective addresses coming out byte-identical on another entry, so I write
                                              //     the natural subscript and stop there ✓ ) 
        *cell = value;                              // ORIG: 'mov dword ptr [eax],edi' once in each block ✗✓ one statement whose address is either that computed cell or null -
                                           //     declare the pointer once, assign on both paths, store after the branch ✓ (their build has one write shape from two places, not two different writes ✓ ) 
        return;                                     // ORIG: 'pop esi ; mov [eax],edi ; pop edi ; retn 0Ch' ✗✓ that path ends with its own
                                          //     twelve-byte cleanup rather than merging into the other exit ✓ so two separate epilogues exist in their build, which my early return likewise produces ✓ 
    }                                               
    this->queryWithTwoIndices(row, column);         // ORIG: fall-through after that null test: 'mov eax,[esp+4+arg_4] ; mov edx,[ecx] ; mov
                                       //     edx,[edx+1Ch] ; push eax ; mov eax,[esp+8+arg_0] ; push eax ; call edx' ✓✗→✓✓ a genuine virtual dispatch through the objects OWN table at displacement twenty-eight, both index values
                                       //     re-read from their stack slots on this path rather than kept in registers ✗ (their ESI/EDX held those same values and their build still went back to the stack ✗✓ evidence of separate uses in
                                       //     source - which my expression likewise leaves unshared ✓ ) That is the whole point of this member: with no value to store, ask the objects own polymorphic routine to handle the request ✓ 
}                                                                          // closes the member: three exits each 'retn 0Ch' cleaning twelve bytes ✓✗→✓ EDI saved at entry holding that value across either path ✗ and
                                             //     ESI/EDX saved only INSIDE the storing branch ('push esi' after that null test at +5C ✓ ) - which my structure likewise does by declaring nothing until past that guard ✓ 
                                             //     entries can ✓ The two real risks were that null-address store on the out-of-range path (done with one pointer variable assigned zero ✗ ) and getting a genuine virtual dispatch rather than
                                             //     a hand-made function-pointer cast, which is what this revision changes ✓ 

}   // namespace f3m_0047b250

// @f3 0x0046c840 (community match, verified in this file)
namespace f3m_0046c840 {
namespace f3m_0046c840 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObj {
    virtual void vf00();
    virtual void DeleteThis();
    volatile long refCount;
};
struct Holder {
    char pad[0x24];
    RefObj* a;
    RefObj* b;
    RefObj* c;
    void FUN_0046c840();
};
// pdb: BGSPrimitive::ClearGeometryData | BGSPrimitive.obj | fnv360_0822_retail, call_gap, low
void Holder::FUN_0046c840()
{
    if (a) { RefObj* p = a; if (InterlockedDecrement(&p->refCount) == 0) p->DeleteThis(); a = 0; }
    if (b) { RefObj* p = b; if (InterlockedDecrement(&p->refCount) == 0) p->DeleteThis(); b = 0; }
    if (c) { RefObj* p = c; if (InterlockedDecrement(&p->refCount) == 0) p->DeleteThis(); c = 0; }
}
}
}   // namespace f3m_0046c840

// @f3 0x00470900 (community match, verified in this file)
namespace f3m_00470900 {
namespace f3m_00470900 {
struct Child470 {                                    
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
    int type1C;                                      
};
class Object470 {                                    
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();   
    virtual void* vf18();                            
    struct Child470* FUN_00826590(unsigned int kind);   
};
// pdb: BipedAnim::GetLightingProperty | BipedAnim.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void* BipedAnim_GetLightingProperty(Object470* object) {
 if(object && object->vf18()) {
  object->FUN_00826590(2);
  object->FUN_00826590(5);
  Child470* found=object->FUN_00826590(3);
  int valid=found && found->type1C>=7 && found->type1C<=11;
  return valid ? found : 0;
 }
 return 0;
}
}
}   // namespace f3m_00470900

// @f3 0x004707c0 (community match, verified in this file)
namespace f3m_004707c0 {
extern const char DAT_00dbfbf8[];

struct Loader_4707c0 { void FUN_0042c500(char* path, int a2, int a3); };
extern Loader_4707c0* DAT_0106ca70;

void FUN_00ad5a70(char* out, const char* in, const char* suffix, bool flag);

struct Finder_4707c0;
struct Owner_4707c0 {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c;
    Finder_4707c0* unk110;
};
struct Finder_4707c0 { bool FUN_0055f640(Owner_4707c0* owner, int key, char* out); };

// pdb: BipedAnim::QueueSkinTexture | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: apNpc, aeBipedObject, aePriority, apParent
void __stdcall FUN_004707c0(Owner_4707c0* owner, int key, int a3, int a4)
{
    char path[0x104];
    char normalPath[0x104];
    Finder_4707c0* finder = owner->unk110;
    int flags = *(volatile int*)&a4;
    if (finder->FUN_0055f640(owner, key, path)) {
        DAT_0106ca70->FUN_0042c500(path, a3, flags);
        FUN_00ad5a70(normalPath, path, DAT_00dbfbf8, true);
        if (normalPath[0])
            DAT_0106ca70->FUN_0042c500(normalPath, a3, flags);
    }
}
}

// @f3 0x004610b0 (community match, verified in this file)
namespace Small4610b0 {
struct TypeInfo { const char* name; const TypeInfo* parent; };
extern const TypeInfo DAT_01070040;
struct Object {
    virtual ~Object();
    virtual void vf04();
    virtual const TypeInfo* GetRTTI() const;

};
struct TargetObject : Object { void FUN_0049cb60(); };
__forceinline bool IsRequestedType(const TypeInfo* type) {
    if (type) do {
        if (type == &DAT_01070040)
            return true;
        type = type->parent;
    } while (type);
    return false;
}
inline TargetObject* CastTarget(Object* object) {
    if (!object)
        return 0;
    return IsRequestedType(object->GetRTTI()) ? static_cast<TargetObject*>(object) : 0;
}

struct Graph {
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
    Object** entries;
    unsigned short capacity;
    unsigned short size;
};
struct Pending { void FUN_00424390(); };
struct Heap { void FUN_0086ba60(void* memory); };
extern Heap DAT_01090a78;
struct FUN_006c8220 {
    Pending* item;
    FUN_006c8220* next;
    __declspec(nothrow) ~FUN_006c8220();
    static void operator delete(void* memory) throw() { DAT_01090a78.FUN_0086ba60(memory); }
    void RemoveHead() {
        FUN_006c8220* node = next;
        if (node) {
            next = node->next;
            item = node->item;
            node->next = 0;
            delete node;
        } else {
            item = 0;
        }
    }
};
struct Owner {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    Graph* graph;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    FUN_006c8220 pending;
    bool FUN_0045c980();
    void Animation_ClearBlendInterps();
};
// pdb: Animation::ClearBlendInterps | Animation.obj | fnv360_0822_retail, udata + bridge(call_gap|call_gap), high
void Owner::Animation_ClearBlendInterps() {
    if (graph) {
        unsigned int count = graph->size;
        for (int i = 0; i < count; ++i) {
            TargetObject* object = CastTarget(graph->entries[i]);
            if (object)
                object->FUN_0049cb60();
        }
        while (FUN_0045c980()) {
            Pending* item = pending.item;
            item->FUN_00424390();
            item->FUN_00424390();
            pending.RemoveHead();
        }
    }
}
}

// @f3 0x0047d400 (community match, verified in this file)
namespace f3m_0047d400 {
namespace Small47d400 {
struct Form {
    unsigned int unk00;
    unsigned char type;
    unsigned char unk05, unk06, unk07;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned short percentage;
};
unsigned int __cdecl FUN_00456720(Form* form);
float __cdecl FUN_00582720(unsigned short percentage, float value);
__forceinline float FUN_0044a250(float value) {
    float whole = static_cast<float>(static_cast<int>(value));
    return whole - value >= 0.0 ? whole : whole + 1.0;
}
struct Owner {
    unsigned int unk00, unk04;
    Form* form;
    float FUN_0047cf30(int mode);
    float FUN_0047d400(int unused);
};
// pdb: ItemChange::GetModifiedArmorRating | InventoryChanges.obj | fnv360_0721_retail, call_seq, medium
// pdb params: apActor
float Owner::FUN_0047d400(int unused) {
    float result = -1.0f;
    Form* item = form;
    if (item->type == 0x18) {
        float count = static_cast<float>(FUN_00456720(item));
        double perUnit;
        if (count == 0.0f)
            perUnit = 0.0f;
        else
            perUnit = static_cast<double>(FUN_0047cf30(0)) / count;
        float percentage = item->percentage / 100.0f;
        result = FUN_00582720(static_cast<unsigned short>(percentage), perUnit);
    }
    return FUN_0044a250(result);
}
}
}   // namespace f3m_0047d400

// @f3 0x0047ed10 (community match, verified in this file)
namespace f3m_0047ed10 {
namespace Small47ed10 {
struct Form {
    virtual ~Form();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual bool IsRelevant();
};
struct BaseEntry { int count; Form* form; Form* GetForm() const { return form; } };
struct BaseNode { BaseEntry* item; BaseNode* next; };
struct BaseData { unsigned int unk00; BaseNode head; };
struct Source { BaseData* FUN_004e66c0(); };
struct Change { unsigned int unk00; int count; Form* form; Form* GetForm() const { return form; } };
struct FormMatches {
    Form* const form;
    FormMatches(Form* value) : form(value) {}
    bool operator()(const Change* entry) const { return entry && entry->GetForm() == form; }
};
struct ChangeNode {
    Change* item;
    ChangeNode* next;
    bool IsEmpty() const { return next == 0 && item == 0; }
    __forceinline Change* Find(const FormMatches& matches) {
        ChangeNode* position = this;
        bool searching = true;
        while (position && searching) {
            Change* entry = position->item;
            if (matches(entry))
                searching = false;
            else
                position = position->next;
        }
        return position ? position->item : 0;
    }
};
struct Owner {
    ChangeNode* changes;
    Source* source;
    bool FUN_0047ed10();
};
// pdb: InventoryChanges::HasQuestObject | InventoryChanges.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: InventoryChanges::RemoveDefaultLeveledItems)
bool Owner::FUN_0047ed10() {
    bool found = false;
    BaseData* data = source ? source->FUN_004e66c0() : 0;
    for (BaseNode* node = &data->head; node; node = node->next) {
        BaseEntry* entry = node->item;
        if (!entry)
            break;
        {
            if (found)
                break;
            if (entry->GetForm()->IsRelevant()) {
                found = true;
                Change* change = changes->Find(FormMatches(entry->GetForm()));
                if (change && change->count + entry->count == 0)
                    found = false;
            }
        }
    }
    if (!found) {
        for (ChangeNode* node = changes; node; node = node->next) {
            if (node->IsEmpty())
                break;
            if (found)
                break;
            Change* change = node->item;
            if (change && change->form && change->form->IsRelevant() && change->count > 0)
                found = true;
        }
    }
    return found;
}
}
}   // namespace f3m_0047ed10

// @f3 0x00461930 (community match, verified in this file)
namespace c4_00461930 {

struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;

struct Node
{
    Node* next;
    Node* prev;
    void* data;
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
};

struct List
{
    Node* head;
    Node* tail;
    int count;
    List() { count = 0; head = 0; tail = 0; }
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    void AddTail(void* data)
    {
        Node* node = new Node;
        node->data = data;
        node->next = 0;
        node->prev = tail;
        if (tail)
            tail->next = node;
        else
            head = node;
        count++;
        tail = node;
    }
};

struct RefObject
{
    void* vtable;
    long refs;
};

struct Source
{
    virtual void vf0(int);
    virtual void vf1(int, int);
    virtual void vf2();
    virtual void vf3();
    virtual RefObject* vf4(int);
};

extern void* DAT_00dbe448[];

struct Base
{
    virtual ~Base();
};

struct FUN_00461930 : Base
{
    List* list;
    FUN_00461930(Source* source);
};

// pdb: AnimSequenceMultiple::AnimSequenceMultiple | Animation.obj | fnv360_0822_retail, call_gap, low
// pdb params: apSingleSeq
FUN_00461930::FUN_00461930(Source* source)
{
    *(void***)this = DAT_00dbe448;
    list = new List;
    RefObject* ref = source->vf4(-1);
    ::InterlockedIncrement(&ref->refs);
    list->AddTail(ref);
    source->vf1(0, 0);
    source->vf0(1);
}

}

// @f3 0x0046ef10 (community match, verified in this file)
// These compiler-only ordering boundaries preserve the native traversal
// evaluation order; they do not provide hardware thread synchronization.
extern "C" void _ReadWriteBarrier();
namespace Statistics46EF10 {
struct SceneObject; struct Node; struct Geometry; struct TriGeometry; struct Reference;
struct NiRTTI { const char* name; const NiRTTI* base; };
struct Counters { int values[16]; };
extern const NiRTTI DAT_0116d6ec, DAT_0107000c, DAT_0108f41c, DAT_0116ebd8;
extern const char DAT_00dbf3b0[];
struct SceneObject {
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    virtual Node* AsNode();
    virtual Node* AsReferenceNode();
    virtual void v14();
    virtual Geometry* AsGeometry();
    virtual TriGeometry* AsTriGeometry();
    unsigned int unk04;
    const char* name;
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
    bool IsKindOf(const NiRTTI* type) const { for(const NiRTTI* current=GetRTTI(); current; current=current->base) if(current==type) return true; return false; }
};
struct Children { unsigned int table; SceneObject** data; unsigned short capacity, span, size, growth; };
struct Node : SceneObject { Children children; };
struct ValueNode : Node { unsigned int unkac; int cacheIndex; int Index() const { return cacheIndex; } };
struct ReferenceNode : Node {
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    Reference* reference;
};
struct Form {
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
    virtual bool SuppressStatistics();
    unsigned char type, unk05; unsigned short unk06; unsigned int unk08, id;
};
struct ExtraNode { void* item; ExtraNode* next; };
struct ExtraData { unsigned int unk00; ExtraNode* FUN_0040cc40(); };
struct Reference {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    Form* baseForm;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    ExtraData extra;
};
struct Shape; struct ShapeSlot { Shape* shape; };
struct CollisionWrapper { ShapeSlot* FUN_00424250(); };
struct CollisionResult { unsigned int unk00,unk04,unk08,unk0c; CollisionWrapper* wrapper; __forceinline Shape* Root() { if(wrapper) { ShapeSlot* slot=wrapper->FUN_00424250(); if(slot) return slot->shape; } return 0; } };
struct SeenForms { bool FUN_00544690(const unsigned int& id); void FUN_0061c430(const unsigned int& id); };
extern SeenForms DAT_0106e1c4;
struct ModelRegistry {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned short unk180, count;
};
extern ModelRegistry* DAT_0106cdcc; extern int* DAT_00f4bf7c; extern int DAT_00f4bf80;
typedef void (__cdecl* CountCallback)(int key,int amount,int** counter);
struct Texture;
struct Property {
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
    virtual void vb4();
    virtual void vb8();
    virtual void Visit(CountCallback callback, int** counter);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int kind; bool FUN_00468ec0(unsigned int flag);
    unsigned int FUN_00af3450(); Texture* FUN_00af3280(void** iterator); Texture* FUN_00af3360(void** iterator);
};
static __forceinline Property* UsableProperty(Property* property) { return property && property->kind != -1 ? property : 0; }
struct TextureUses { bool FUN_00bea7b0(Texture* texture,unsigned int* count); void FUN_00880f70(Texture* texture,unsigned int count); };
extern TextureUses DAT_00f4bfa8; extern unsigned int DAT_0106e14c;
struct AdditionalData { unsigned int FUN_0083cb50(); unsigned int FUN_0083c8f0(unsigned int index,unsigned int* bytes); __forceinline bool ReadBytes(unsigned int i,unsigned int& bytes) {if(i>=FUN_0083cb50())return false;bytes=0;FUN_0083c8f0(i,&bytes);return true;} };
struct GeometryData {
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
    virtual unsigned short VertexCount();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual unsigned short TriangleCount();
    unsigned int unk04; unsigned short vertices,unk0a; unsigned int unk0c,unk10,unk14,unk18,unk1c;
    void* positions; void* normals; void* colors; void* uv; AdditionalData* additional;
};
struct Geometry : SceneObject {
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    GeometryData* data; Property* FUN_00826590(int type);
};
struct TriGeometry : Geometry { __forceinline unsigned int Triangles() const { return data->TriangleCount(); } };
struct LightManager { void* FUN_00ae1d30(SceneObject* light); };
struct World { void FUN_00437b20(); };
extern LightManager* DAT_0116efb8; extern World* DAT_0107a0d8;
int __cdecl FUN_00c020cb(const char* left,const char* right,unsigned int count);
SceneObject* __cdecl FUN_00424d50(const NiRTTI* type,SceneObject* object); bool __cdecl FUN_00424d20(const NiRTTI* type,SceneObject* object);
bool __cdecl FUN_004eb950(SceneObject* object); CollisionResult* __cdecl FUN_0046e6b0(SceneObject* object); int __cdecl FUN_0046e750(Shape* shape);
void __cdecl FUN_0046e700(int key,int amount,int** counter);
struct Statistics { unsigned int unk00; Counters counters; void FUN_0046ef10(SceneObject* object,Counters* supplied,bool descendActors,Node* parent); };
static __forceinline int TextureKindValue(Property* property) { if(!property || property->kind < 7 || property->kind > 11) return 0; return 1; }
// pdb: BGSSceneInfo::CollectSceneDataRecursive | BGSSceneInfo.obj | fnv360_0822_retail, ustr, medium
// pdb params: ap3D, pStructToFill, abTrackActors, apParent
void Statistics::FUN_0046ef10(SceneObject* object, Counters* supplied, bool descendActors, Node* parent)
{
    Counters* stats = supplied ? supplied : &counters;
    if (object) {
        Node* node = object->AsNode();
        if (node) {
            if (node->name && FUN_00c020cb(node->name, DAT_00dbf3b0, 15) == 0)
                return;
            if (node->IsKindOf(&DAT_0116d6ec)) {
                int index = static_cast<ValueNode*>(FUN_00424d50(&DAT_0116d6ec, node))->Index();
                if (index >= 0 && index < DAT_0106cdcc->count && index < DAT_00f4bf80) {
                    for (int counter = 0; counter < 16; counter += 1) {
                        if (counter < 0 || counter > 3)
                            stats->values[counter] += DAT_00f4bf7c[index * 16 + counter];
                        _ReadWriteBarrier();
                    }
                }
            }
            bool actorType = false;
            int increment = 1;
            if (node->AsReferenceNode()) {
                Reference* reference = static_cast<ReferenceNode*>(node)->reference;
                if (reference) {
                    Form* base = reference->baseForm;
                    if (!base || !base->SuppressStatistics()) {
                    stats->values[0] += increment;
                    if (FUN_004eb950(object)) {
                        stats->values[2] += increment;
                        unsigned int id = reference->baseForm->id;
                        if (!DAT_0106e1c4.FUN_00544690(id)) {
                            stats->values[3] += increment;
                            id = reference->baseForm->id;
                            DAT_0106e1c4.FUN_0061c430(id);
                        }
                    }
                    ExtraNode* extra = reference->extra.FUN_0040cc40();
                    while (extra && extra->item) {
                        stats->values[14] += increment;
                        extra = extra->next;
                    }
                    unsigned int type = reference->baseForm->type;
                    if (type >= 42 && type <= 45) {
                        stats->values[1] += increment;
                        actorType = true;
                    }
                    CollisionResult* collision = FUN_0046e6b0(object);
                    if (collision) {
                        Shape* shape = collision->Root();
                        _ReadWriteBarrier();
                        if (shape)
                            stats->values[15] += FUN_0046e750(shape);
                    }
                    if (actorType && !descendActors)
                        return;
                    }
                }
            }
            unsigned int childCount = node->children.span;
            for (unsigned int i = 0; i < childCount; i += increment)
                FUN_0046ef10(node->children.data[i], supplied, false, node);
        } else {
            Geometry* geometry = object->AsGeometry();
            if (geometry) {
                int increment = 1;
                stats->values[6] += increment;
                Property* property = geometry->FUN_00826590(3);
                if (property) {
                    Property* usable = UsableProperty(property);
                    _ReadWriteBarrier();
                    if (usable) {
                    int* count = &stats->values[10];
                    usable->Visit(FUN_0046e700, &count);
                    if ((parent && FUN_00424d20(&DAT_0107000c, parent)) ||
                        usable->FUN_00468ec0(26) || usable->FUN_00468ec0(27))
                        stats->values[14] += increment;
                    }
                }
                Property* textured = TextureKindValue(property) ? property : 0;
                _ReadWriteBarrier();
                if (textured) {
                    textured->FUN_00af3450();
                    void* iterator;
                    Texture* texture = textured->FUN_00af3280(&iterator);
                    while (texture) {
                        unsigned int count = 0;
                        DAT_00f4bfa8.FUN_00bea7b0(texture, &count);
                        unsigned int newCount = count + 1;
                        DAT_00f4bfa8.FUN_00880f70(texture, newCount);
                        if (newCount == DAT_0106e14c)
                            stats->values[13] += 1;
                        texture = textured->FUN_00af3360(&iterator);
                    }
                }
                TriGeometry* triangles = geometry->AsTriGeometry();
                if (triangles) {
                    stats->values[7] += static_cast<unsigned short>(triangles->Triangles());
                    int bytes = 0;
                    int vertices = triangles->data->VertexCount();
                    GeometryData* data = triangles->data;
                    if (data->positions)
                        bytes = vertices * 12;
                    if (data->colors)
                        bytes += vertices * 16;
                    if (data->normals)
                        bytes += vertices * 12;
                    if (data->uv)
                        bytes += vertices * 8;
                    stats->values[9] += bytes;
                }
                GeometryData* data = geometry->data;
                if (data) {
                    AdditionalData* additional = data->additional;
                    unsigned int i = 0;
                    if (additional) {
                        unsigned int bytes;
                        while(additional->ReadBytes(i,bytes)) {
                            stats->values[9] += bytes;
                            i += 1;
                        }
                    }
                }
            } else {
                SceneObject* light = FUN_00424d50(&DAT_0108f41c, object);
                if (light && DAT_0116efb8 && DAT_0116efb8->FUN_00ae1d30(light))
                    stats->values[12] += 1;
            }
            Geometry* particles = static_cast<Geometry*>(FUN_00424d50(&DAT_0116ebd8, object));
            if (particles) {
                stats->values[5] += 1;
                stats->values[4] += particles->data->vertices;
            }
        }
    }
    DAT_0107a0d8->FUN_00437b20();
}



}

// @f3 0x0047f8b0 (community match, verified in this file)
#pragma pack(push,1)
#pragma pack(pop)
namespace f3m_0047f8b0 {
namespace Small528 {
struct Writer {virtual unsigned Position();unsigned unk04,unk08,unk0c,unk10;unsigned char unk14,unk15,unk16;unsigned char flags17[4];unsigned char unk1b,unk1c,unk1d,unk1e,unk1f;unsigned position20;unsigned& Flags(){return *reinterpret_cast<unsigned*>(flags17);}unsigned BGSSaveGameBuffer_StartVariableSizedValue();void FUN_006e16e0(unsigned,unsigned);};
struct Item {void FUN_0047def0(Writer*);};
struct Node {Item* item;Node* next;};
struct Owner {Node* head;void FUN_0047f8b0(Writer*);};
// pdb: InventoryChanges::SaveGame | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apSaveGameBuffer
void Owner::FUN_0047f8b0(Writer* writer){unsigned oldPosition=writer->Position();unsigned oldFlags=writer->Flags();unsigned count=0;writer->position20=0;writer->Flags()=0x400;unsigned marker=writer->BGSSaveGameBuffer_StartVariableSizedValue();for(Node* node=head;node;node=node->next){if(node->item){node->item->FUN_0047def0(writer);++count;}}writer->FUN_006e16e0(count,marker);writer->position20=oldPosition;writer->Flags()=oldFlags;}
}

}   // namespace f3m_0047f8b0

// @f3 0x00464d70 (community match, verified in this file)
#include <math.h>
namespace f3m_00464d70 {
namespace Small533 {
struct Point {float x,y,z;};
// pdb: CloseTo | BGSAutoWater.obj | fnv360_0822_retail, call_gap, low
// pdb params: arP1, arP2, afEpsilon
int __cdecl FUN_00464d70(const Point* a,const Point* b,float tolerance){float x=a->x-b->x;x=(float)fabs(x);if(x<=tolerance){float y=a->y-b->y;y=(float)fabs(y);if(y<=tolerance){float z=a->z-b->z;z=(float)fabs(z);if(z<=tolerance)return 1;}}return 0;}
}
}   // namespace f3m_00464d70

// @f3 0x0046b790 (community match, verified in this file)
namespace Small46b790 {
struct Item { void FUN_00469a50(); };
struct Pool { void FUN_0086ba60(Item* item); };
extern Pool DAT_01090a78;
struct Node { Node* next; Node* previous; Item* data; };
struct FUN_00bd12d0 {
    Node* head;
    Node* tail;
    unsigned int count;
    __declspec(nothrow) ~FUN_00bd12d0();
    Item*& GetNext(Node*& position) {
        Item*& data = position->data;
        position = position->next;
        return data;
    }
};
struct StringTable {
    int unk00, unk04, unk08;
    void FUN_00abb340();
};
struct Table {
    int unk00, unk04;
    StringTable strings;
    FUN_00bd12d0 items;
    StringTable& Strings() { return strings; }
};
Table* FUN_0046b690();
extern int DAT_0106def4, DAT_0106def8, DAT_0106defc, DAT_0106df00;
// pdb: BGSDecalManager::RemoveAllDecals | BGSDecalManager.obj | fnv360_0822_retail, udata, high
void BGSDecalManager_RemoveAllDecals() {
    DAT_0106def4 = 0;
    DAT_0106def8 = 0;
    DAT_0106defc = 0;
    DAT_0106df00 = 0;
    FUN_0046b690()->strings.FUN_00abb340();
    FUN_00bd12d0* list = &FUN_0046b690()->items;
    Node* position = list->head;
    while (position) {
        Item* item = list->GetNext(position);
        if (item) {
            item->FUN_00469a50();
            DAT_01090a78.FUN_0086ba60(item);
        }
    }
    list->~FUN_00bd12d0();
}
}

// @f3 0x00466330 (community match, verified in this file)
#include <math.h>
namespace BuildWater {
struct Vec {float x,y,z;Vec(){} Vec(float a,float b,float c){x=a;y=b;z=c;} };
void* __cdecl FUN_0089eb90(unsigned); void __cdecl FUN_0089ec10(void*);
struct Heap {void* FUN_0086b930(unsigned); void FUN_0086ba60(void*);}; extern Heap DAT_01090a78;
struct Alloc {static void* operator new(unsigned n) throw(){return FUN_0089eb90(n);} static void operator delete(void*p){FUN_0089ec10(p);}};
struct Ref {virtual void v0(); virtual void Destroy();long refs;};
template<class T> struct Smart {T* ptr; void operator=(T* p){if(ptr!=p){T* old=ptr;if(old&&!::InterlockedDecrement((volatile long*)&old->refs))old->Destroy();ptr=p;if(p)::InterlockedIncrement((volatile long*)&p->refs);}}};
struct String {char* ptr;String(const char* s);~String();};
extern char* DAT_00e207a8;
extern const char DAT_00dbe794[],DAT_00dbe788[];
char* FUN_008242a0(const char*);
String::String(const char*s):ptr(FUN_008242a0(s)){}
String::~String(){if(ptr!=DAT_00e207a8)::InterlockedDecrement((volatile long*)(ptr-8));}
struct Property:Alloc {unsigned unk00;};
struct FUN_00aedf60:Alloc {
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
FUN_00aedf60();
};
struct FUN_00824e90:Alloc {unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014;FUN_00824e90();};
extern unsigned DAT_00dbe6cc;
struct Material:FUN_00824e90 {unsigned short flags;unsigned short unk01a;unsigned unk01c;int unk020;Material(){unk000=(unsigned)&DAT_00dbe6cc;unk01c=0;unk020=-1;flags=0x4180;}};
struct Object:Alloc {
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
virtual void Attach(Object*,int);
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
Vec unk058;
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
void FUN_008245d0(const String&); void FUN_004236f0(void*);void FUN_008264c0(void*);
};
struct Data; struct Geometry:Object {unsigned unk0b4;void* data;unsigned short GetCount();unsigned short GetCount2();Vec* GetVertices();Data* GetData(){return (Data*)data;} };
struct Data {unsigned short GetCount(){return count;} Vec* GetVertices(){return vertices;} unsigned unk000,unk004;unsigned short count;unsigned short unk00a;unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
Vec* vertices;};
inline unsigned short Geometry::GetCount(){return ((Data*)data)->count;}
inline unsigned short Geometry::GetCount2(){return GetData()->GetCount();}
inline Vec* Geometry::GetVertices(){return GetData()->GetVertices();}
struct FUN_00ad2a40:Object { unsigned unk0b4;unsigned unk0b8;
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
FUN_00ad2a40();};
struct FUN_00aa0b10:Ref,Alloc {
virtual void w008();
virtual void w00c();
virtual void w010();
virtual void w014();
virtual void w018();
virtual void w01c();
virtual void w020();
virtual void w024();
virtual void w028();
virtual void w02c();
virtual void w030();
virtual void w034();
virtual void w038();
virtual void w03c();
virtual void w040();
virtual void w044();
virtual void w048();
virtual void w04c();
virtual void w050();
virtual void w054();
virtual void w058();
virtual void w05c();
virtual void w060();
virtual void w064();
virtual void w068();
virtual void w06c();
virtual void w070();
virtual void w074();
virtual void w078();
virtual void w07c();
virtual void w080();
virtual void w084();
virtual void w088();
virtual void w08c();
virtual void w090();
virtual void w094();
virtual void w098();
virtual void w09c();
virtual void w0a0();
virtual void w0a4();
virtual void w0a8();
virtual void w0ac();
virtual void w0b0();
virtual void w0b4();
virtual void SetPosition(const Vec&);
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
Vec unk018;
FUN_00aa0b10();};
struct FUN_00a9f1e0:Ref,Alloc {unsigned unk008;Smart<FUN_00aa0b10> shape;FUN_00a9f1e0();};
struct FUN_00aaa070:Object {Smart<FUN_00a9f1e0>& Shape(){return *(Smart<FUN_00a9f1e0>*)&unk0ac;} FUN_00aaa070();};
struct World {void* FUN_004fe240();};
struct FUN_004f9970;
struct RefTable {
void* r000;
void* r004;
void* r008;
void* r00c;
void* r010;
void* r014;
void* r018;
void* r01c;
void* r020;
void* r024;
void* r028;
void* r02c;
void* r030;
void* r034;
void* r038;
void* r03c;
void* r040;
void* r044;
void* r048;
void* r04c;
void* r050;
void* r054;
void* r058;
void* r05c;
void* r060;
void* r064;
void* r068;
void* r06c;
void* r070;
void* r074;
void* r078;
void* r07c;
void* r080;
void* r084;
void* r088;
void* r08c;
void* r090;
void* r094;
void* r098;
void* r09c;
void* r0a0;
void* r0a4;
void* r0a8;
void* r0ac;
void* r0b0;
void* r0b4;
void* r0b8;
void* r0bc;
void* r0c0;
void* r0c4;
void* r0c8;
void* r0cc;
void* r0d0;
void* r0d4;
void* r0d8;
void* r0dc;
void* r0e0;
void* r0e4;
void* r0e8;
void* r0ec;
void* r0f0;
void* r0f4;
void* r0f8;
void* r0fc;
void* r100;
void* r104;
void* r108;
void* r10c;
void* r110;
void* r114;
void* r118;
void* r11c;
void* r120;
void* r124;
void* r128;
void* r12c;
void* r130;
void* r134;
void* r138;
void* r13c;
void* r140;
void* r144;
void* r148;
void* r14c;
void* r150;
void* r154;
void* r158;
void* r15c;
void* r160;
void* r164;
void* r168;
void* r16c;
void* r170;
void* r174;
void* r178;
void* r17c;
void* r180;
void* r184;
void* r188;
void* r18c;
void* r190;
void* r194;
void* r198;
void* r19c;
void* r1a0;
void* r1a4;
void* r1a8;
void* r1ac;
void* r1b0;
void* r1b4;
void* r1b8;
void* r1bc;
void* r1c0;
void* r1c4;
void* r1c8;
void (__thiscall* SetRoot)(FUN_004f9970*,Object*,int);
};
struct FUN_004f9970 {
RefTable* table;
void SetRoot(Object* o,int f){RefTable* t=table;t->SetRoot(this,o,f);}
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
Vec unk02c;
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
FUN_004f9970();static void* operator new(unsigned n) throw(){return DAT_01090a78.FUN_0086b930(n);} static void operator delete(void*p){DAT_01090a78.FUN_0086ba60(p);}void TESObjectREFR_SetObjectReference(void*);void FUN_004553b0();void FUN_004fa540();};
struct Terrain {Vec* FUN_004c8ff0(Vec*,int);};
struct Cell {Terrain* TESObjectCELL_GetLand();float FUN_004d5350();World* TESObjectCELL_GetWaterType();void TESObjectCELL_AddReference(FUN_004f9970*,int);};
struct Work {unsigned unk000,unk004,unk008,unk00c,unk010,unk014,unk018,unk01c,unk020,unk024,unk028;Object* first;Geometry* second;Object* GetFirst(){return first;} Geometry* GetSecond(){return second;} void FUN_00aabf90();};
struct Node {Node* next;Node* prev;Work* data;};
struct List {Node* first;Node* last;unsigned count;void FUN_005878f0();void FUN_00469b60();void FUN_00ade560(Node*);
__forceinline void Remove(Node* node){if(node==first)FUN_005878f0();else if(node==last)FUN_00469b60();else{Node* prev=node->prev;Node* after=node->next;if(prev)prev->next=after;if(after)after->prev=prev;FUN_00ade560(node);--count;}}
};extern List* DAT_0106dee0;
extern bool DAT_01072a48;
void FUN_00ade300(Object*,int,int);
// pdb: BGSAutoWater::GeneratePlaceableWater | BGSAutoWater.obj | fnv360_0822_retail, ustr, medium
// pdb params: apCell
void FUN_00466330(Cell* cell){
 Assign464b10::TagScope tag(0x1d);
 if(DAT_0106dee0){
 float x,y;{Vec b1;x=cell->TESObjectCELL_GetLand()->FUN_004c8ff0(&b1,0)->x;Vec b2;y=cell->TESObjectCELL_GetLand()->FUN_004c8ff0(&b2,0)->y;}
 float z=cell->FUN_004d5350();
 Vec position(x,y,z);bool updated=false;
 Node* node=DAT_0106dee0->first;if(node)do {
  Node* next=node?node->next:0; if(node){Work* work=node->data;
  if(work->first&&work->second){
   work->first->FUN_008245d0(String(DAT_00dbe794));
   work->GetSecond()->FUN_008245d0(String(DAT_00dbe788));
   FUN_004f9970* reference=new FUN_004f9970;
   work->second->FUN_004236f0(new FUN_00aedf60);
   FUN_00ade300(work->first,0,0);
   Material* material=new Material;material->flags|=0xc00;work->second->FUN_004236f0(material);
   reference->TESObjectREFR_SetObjectReference(cell->TESObjectCELL_GetWaterType()->FUN_004fe240());
   FUN_00ad2a40* root=new FUN_00ad2a40;root->unk030|=0x8000;reference->SetRoot(root,1);
   root->unk058=position;reference->unk02c=position;
   FUN_00aa0b10* shape=new FUN_00aa0b10;
   Geometry* geom=work->second;
   Vec* vertices=geom->GetVertices();
   float minx=0,miny=0,minz=0,maxx=0,maxy=0,maxz=0;
   for(int i=0;i<geom->GetCount2();++i){Vec v=vertices[i];
    if(i>0){minx=minx<v.x?minx:v.x;miny=miny<v.y?miny:v.y;minz=minz<v.z?minz:v.z;if(!(v.x<maxx))maxx=v.x;if(!(v.y<maxy))maxy=v.y;if(!(v.z<maxz))maxz=v.z;}else{minx=maxx=v.x;miny=maxy=v.y;minz=maxz=v.z;}
}
   float hz=(maxz-minz)*0.5;hz=fabs(hz);float hy=(maxy-miny)*0.5;hy=fabs(hy);float hx=(maxx-minx)*0.5;hx=fabs(hx);
   Vec half;half.x=hx;half.y=hy;half.z=hz;float cx=maxx-half.x;float cy=maxy-half.y;float cz=maxz-half.z;Vec center(cx+x,cy+y,cz+z);
   shape->SetPosition(center);shape->unk018=half;
   FUN_00a9f1e0* holder=new FUN_00a9f1e0;holder->shape=shape;
   FUN_00aaa070* object=new FUN_00aaa070;object->Shape()=holder;
   root->Attach(object,1);object->Attach(work->first,1);
   struct Update {float time;bool b0,b1,b2,b3,b4;} update={0,false,false,false,false,false};root->FUN_008264c0(&update);
   cell->TESObjectCELL_AddReference(reference,0);reference->FUN_004553b0();
   if(DAT_01072a48&&!updated){reference->FUN_004fa540();updated=true;}
   work->FUN_00aabf90();DAT_01090a78.FUN_0086ba60(work);
   DAT_0106dee0->Remove(node);
  }
  }
  node=next;
 }while(node);
}
}
}

// @f3 0x0047d300 (community match, verified in this file)
namespace f3m_0047d300 {
namespace Health720 {
struct Form { void* vtable; unsigned char type; };
struct Health { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual unsigned GetHealth(); };
struct Extra { float FUN_0040ac20(); };
Health* FUN_004566c0(Form*);
unsigned FUN_00456720(Form*);
float FUN_00583a40(void*,Form*,float,float,int,int);
struct Entry {
 Extra** extra; int count; Form* object;
 __forceinline float Current() {
  Health* base=FUN_004566c0(object);
  if(base) {
   if(extra) {
    Extra* list=*extra;
    if(list) {
     if(list->FUN_0040ac20()!=-1.0f) return list->FUN_0040ac20();
     else return (float)base->GetHealth();
    }
   }
   return (float)base->GetHealth();
  }
  return -1.0f;
 }
 float FUN_0047d300(void*,float,int);
};
// pdb: ItemChange::GetModifiedAttackDamage | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
// pdb params: apActor, afDamageMultiplier, abIgnoreExplosion
float Entry::FUN_0047d300(void* target,float mult,int flags) {
 if(object->type==40) {
  Form* form=object;
  double current=Current();
  float ratio=(float)(current/(float)FUN_00456720(form));
  return FUN_00583a40(target,form,ratio,mult,0,flags);
 }
 return 0.0f;
}
}


}   // namespace f3m_0047d300

// @f3 0x00470b00 (community match, verified in this file)
namespace match648 {
struct Model {virtual void v00(); unsigned u04,u08,u0c,u10,u14;void FUN_00459610(const char*);};
extern Model DAT_0106e350[20];
bool __stdcall FUN_00470a30(Model*,char*);
inline Model* GetModel(int index){return &DAT_0106e350[index];}
// pdb: BipedAnim::Get1stPersonModel | BipedAnim.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aeBipedObject, apModel
Model* __stdcall FUN_00470b00(int index,Model* source){
 char path[260];
 if(source!=&DAT_0106e350[index] && FUN_00470a30(source,path)) {DAT_0106e350[index].FUN_00459610(path);return &DAT_0106e350[index];}
 return source;
}
}

// @f3 0x0047bbc0 (community match, verified in this file)
namespace f3m_0047bbc0 {
struct GameState47bbc0 {
    int u000;
    int u004;
    int u008;
    int u00c;
    int u010;
    int u014;
    int u018;
    int u01c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    int u048;
    int u04c;
    int u050;
    int u054;
    int u058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    int u0e8;
    int u0ec;
    int u0f0;
    int u0f4;
    int u0f8;
    int u0fc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int u114;
    int u118;
    int u11c;
    int u120;
    int u124;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    int u140;
    int u144;
    int u148;
    int u14c;
    int u150;
    int u154;
    int u158;
    int u15c;
    int u160;
    int u164;
    int u168;
    int u16c;
    int u170;
    int u174;
    int u178;
    int u17c;
    int u180;
    int u184;
    int u188;
    int u18c;
    int u190;
    int u194;
    int u198;
    int u19c;
    int u1a0;
    int u1a4;
    int u1a8;
    int u1ac;
    int u1b0;
    int u1b4;
    int u1b8;
    int u1bc;
    int u1c0;
    int u1c4;
    int u1c8;
    int u1cc;
    int u1d0;
    int u1d4;
    int u1d8;
    int u1dc;
    int u1e0;
    int u1e4;
    int u1e8;
    int u1ec;
    int u1f0;
    int u1f4;
    int u1f8;
    int u1fc;
    int u200;
    int u204;
    int u208;
    int u20c;
    int u210;
    int u214;
    int u218;
    int u21c;
    int u220;
    int u224;
    int u228;
    int u22c;
    int u230;
    int u234;
    int u238;
    int u23c;
    int u240;
    int u244;
    int u248;
    int u24c;
    int u250;
    int u254;
    int u258;
    int u25c;
    int u260;
    int u264;
    int u268;
    int u26c;
    int u270;
    int u274;
    int u278;
    int u27c;
    int u280;
    int u284;
    int u288;
    int u28c;
    int u290;
    int u294;
    int u298;
    int u29c;
    int u2a0;
    int u2a4;
    int u2a8;
    int u2ac;
    int u2b0;
    int u2b4;
    int u2b8;
    int u2bc;
    int u2c0;
    int u2c4;
    int u2c8;
    int u2cc;
    int u2d0;
    int u2d4;
    int u2d8;
    int u2dc;
    int u2e0;
    int u2e4;
    int u2e8;
    int u2ec;
    int u2f0;
    int u2f4;
    int u2f8;
    int u2fc;
    int u300;
    int u304;
    int u308;
    int u30c;
    int u310;
    int u314;
    int u318;
    int u31c;
    int u320;
    int u324;
    int u328;
    int u32c;
    int u330;
    int u334;
    int u338;
    int u33c;
    int u340;
    int u344;
    int u348;
    int u34c;
    int u350;
    int u354;
    int u358;
    int u35c;
    int u360;
    int u364;
    int u368;
    int u36c;
    int u370;
    int u374;
    int u378;
    int u37c;
    int u380;
    int u384;
    int u388;
    int u38c;
    int u390;
    int u394;
    int u398;
    int u39c;
    int u3a0;
    int u3a4;
    int u3a8;
    int u3ac;
    int u3b0;
    int u3b4;
    int u3b8;
    int u3bc;
    int u3c0;
    int u3c4;
    int u3c8;
    int u3cc;
    int u3d0;
    int u3d4;
    int u3d8;
    int u3dc;
    int u3e0;
    int u3e4;
    int u3e8;
    int u3ec;
    int u3f0;
    int u3f4;
    int u3f8;
    int u3fc;
    int u400;
    int u404;
    int u408;
    int u40c;
    int u410;
    int u414;
    int u418;
    int u41c;
    int u420;
    int u424;
    int u428;
    int u42c;
    int u430;
    int u434;
    int u438;
    int u43c;
    int u440;
    int u444;
    int u448;
    int u44c;
    int u450;
    int u454;
    int u458;
    int u45c;
    int u460;
    int u464;
    int u468;
    int u46c;
    int u470;
    int u474;
    int u478;
    int u47c;
    int u480;
    int u484;
    int u488;
    int u48c;
    int u490;
    int u494;
    int u498;
    int u49c;
    int u4a0;
    int u4a4;
    int u4a8;
    int u4ac;
    int u4b0;
    int u4b4;
    int u4b8;
    int u4bc;
    int u4c0;
    int u4c4;
    int u4c8;
    int u4cc;
    int u4d0;
    int u4d4;
    int u4d8;
    int u4dc;
    int u4e0;
    int u4e4;
    int u4e8;
    int u4ec;
    int u4f0;
    int u4f4;
    int u4f8;
    int u4fc;
    int u500;
    int u504;
    int u508;
    int u50c;
    int u510;
    int u514;
    int u518;
    int u51c;
    int u520;
    int u524;
    int u528;
    int u52c;
    int u530;
    int u534;
    int u538;
    int u53c;
    int u540;
    int u544;
    int u548;
    int u54c;
    int u550;
    int u554;
    int u558;
    int u55c;
    int u560;
    int u564;
    int u568;
    int u56c;
    int u570;
    int u574;
    int u578;
    int u57c;
    int u580;
    int u584;
    int u588;
    int u58c;
    int u590;
    int u594;
    int u598;
    int u59c;
    int u5a0;
    int u5a4;
    unsigned char u5a8;
    bool flag5A9;
    static GameState47bbc0* Get() { return DAT_0106cdcc; }
    bool IsFlag5A9() const { return flag5A9; }
} *DAT_0106cdcc;
struct Heap47bbc0 {
    void FUN_0086ba60(void* p);
};
extern Heap47bbc0 DAT_01090a78;
void __cdecl FUN_007f97f0();
void __cdecl TESObjectCELL_KillStatics();

struct __declspec(novtable) Base47aef0 {
    virtual void v00();
    int unk04, unk08, unk0c;
    void* data10;
    int unk14, unk18, unk1c, unk20;
    ~Base47aef0() { FUN_0047aef0(); }
    void FUN_0047aef0();
};

struct Ptr24 {
    FUN_0047ba30_res* p;
    ~Ptr24() {
        FUN_0047ba30_res* q = p;
        if (q) {
            if (FUN_00d9b064(&q->unk04) == 0)
                q->Release();
        }
    }
};

struct FUN_0047bbc0 : Base47aef0 {
    Ptr24 unk24;
    void FUN_0047ba30();
    void GridCellArray_KillAll() {
        FUN_007f97f0();
        if (GameState47bbc0::Get()->IsFlag5A9())
            TESObjectCELL_KillStatics();
    }
    ~FUN_0047bbc0();
};

// pdb: GridCellArray::~GridCellArray | GridCell.obj | fnv360_0822_retail, call_seq, high
FUN_0047bbc0::~FUN_0047bbc0() {
    GridCellArray_KillAll();
    FUN_0047ba30();
    void* data = data10;
    DAT_01090a78.FUN_0086ba60(data);
}
}

// @f3 0x00478c40 (community match, verified in this file)
namespace f3m_00478c40 {
namespace Assign313 {
struct Object;struct Children {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;Object** data;unsigned short capacity,count;};
struct Controller {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;unsigned kind;int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c;int value;};
struct Object {virtual void v000(); virtual void v004(); virtual void v008();virtual Children* children();virtual void v010(); virtual void v014();virtual int isLeaf();Controller* FUN_00826590(int);};
__forceinline int valid(Controller* c){if(!c)return 0;switch(c->kind){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:return 1;default:return 0;}}__forceinline Controller* cast(Controller* c){return valid(c)?c:0;}
// pdb: SetReferenceIDOnScenegraph | GlobalFunc.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apObject, auiID
void FUN_00478c40(Object* object,int value){if(object){if(object->isLeaf()){Controller* c=cast(object->FUN_00826590(3));if(c)c->value=value;}else{Children* c=object->children();if(c){for(unsigned i=0;i<c->count;++i)FUN_00478c40(c->data[i],value);}}}}
}

}   // namespace f3m_00478c40

// @f3 0x004757a0 (community match, verified in this file)
struct NiMemObject {};
struct NiRefObject : ::NiMemObject { virtual ~NiRefObject();unsigned references; };
struct NiObject : ::NiRefObject { virtual ~NiObject(); };
struct bhkRefObject : ::NiObject {
    void* referencedObject;
    bhkRefObject();
    virtual ~bhkRefObject();
    void FUN_008f9170(void*);
};
struct bhkSerializable : ::bhkRefObject {
    unsigned unk0c;
    bhkSerializable():unk0c(0){}
    virtual ~bhkSerializable();
};
extern int DAT_010f31ac,DAT_010f31b8,DAT_010f31c4;
struct bhkAction : ::bhkSerializable {
    bhkAction(){++DAT_010f31ac;}
    virtual ~bhkAction();
};
struct bhkUnaryAction : ::bhkAction {
    bhkUnaryAction(){++DAT_010f31b8;}
    virtual ~bhkUnaryAction();
};
struct bhkMouseSpringAction : ::bhkUnaryAction {
    bhkMouseSpringAction(void*);
    virtual ~bhkMouseSpringAction();
};
// pdb: bhkMouseSpringAction::bhkMouseSpringAction | GlobalFunc.obj | fnv360_0822_retail, call_gap, medium
// pdb params: arInfo
bhkMouseSpringAction::bhkMouseSpringAction(void* p){FUN_008f9170(p);++DAT_010f31c4;}

// @f3 0x004784f0 (community match, verified in this file)
#include <string.h>
extern char DAT_01091f04;
extern char* DAT_00e207a8;
namespace f3m_004784f0 {


namespace f3m_004784f0 {
struct Object {
    int unk00, unk04, unk08;
    void* data;
};
struct Entry {
    float value;
    const char* name;
};
struct Entries {
    int unk00, unk04, unk08;
    unsigned count;
    Entry* items;
};
struct Result {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Entries* list;
};
struct Map {
    bool FUN_00bea7b0(const char*, Result*&);
};
struct Registry {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    Map map;
};
extern Registry* FUN_00424d50(void*, void*);
extern char* FUN_008242a0(const char*);
extern "C" __declspec(nothrow) int __cdecl FUN_00c020cb(const char*, const char*, size_t);

struct StringKey {
    char* text;
    char* get() { return text; }
    StringKey(const char* value) {
        if (!value)
            text = DAT_00e207a8;
        else
            text = FUN_008242a0(value);
    }
    ~StringKey() throw() {
        if (text != DAT_00e207a8)
            ::InterlockedDecrement(reinterpret_cast<volatile long*>(text - 8));
    }
};

// pdb: FindTimeForNoteKey | GlobalFunc.obj | fnv360_0822_retail, call_gap, low
// pdb params: pObject, pcSequenceName, pcKeyName
float FUN_004784f0(Object* object, const char* key, const char* prefix)
{
    if (!object)
        return 0.0f;
    void* data = object->data;
    Registry* registry = FUN_00424d50(&DAT_01091f04, data);
    if (!registry)
        return 0.0f;
    Result* result;
    {
        StringKey name(key);
        Result* found;
        result = registry->map.FUN_00bea7b0(name.text, found) ? found : 0;
    }
    if (!result)
        return 0.0f;

    Entry* entries = result->list->items;
    unsigned count = result->list->count;
    unsigned length = strlen(prefix);
    if (length) {
        Entry* entry = entries;
        for (unsigned i = 0; i < count; ++i, ++entry) {
            if (entry->name && FUN_00c020cb(entry->name, prefix, length) == 0)
                return entries[i].value;
        }
    }
    return 0.0f;
}
}
}   // namespace f3m_004784f0

// @f3 0x00471430 (community match, verified in this file)
#include <stddef.h>
#include <string.h>
namespace Clone2077 {
struct Heap { void* __thiscall FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
void* __cdecl FUN_0089e810(unsigned int);
struct Object;
template<class T> struct Entry { Entry* next; Object* key; T value; };
extern char DAT_00dbfc48[], DAT_00dbfcb4[], DAT_00dbfc68[], DAT_00dbfcd4[];
template<class T> struct MapTables;
template<> struct MapTables<Object*> { static void* Base() { return DAT_00dbfc48; } static void* Derived() { return DAT_00dbfcb4; } };
template<> struct MapTables<bool> { static void* Base() { return DAT_00dbfc68; } static void* Derived() { return DAT_00dbfcd4; } };
template<class T> struct MapBase {
    void* vtable; ~MapBase();
    unsigned int capacity; Entry<T>** buckets; unsigned int count;
    MapBase(unsigned int n) : vtable(MapTables<T>::Base()) {
        capacity = n;
        count = 0;
        unsigned int size = sizeof(Entry<T>*) * capacity;
        buckets = static_cast<Entry<T>**>(FUN_0089e810(size));
        unsigned int clearSize = capacity * sizeof(Entry<T>*);
        memset(buckets, 0, clearSize);
    }
};
template<class T> struct PointerMap : MapBase<T> {
    PointerMap(unsigned int n) : MapBase<T>(n) { this->vtable = MapTables<T>::Derived(); }
    ~PointerMap();
    static void* operator new(size_t n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void*);
};
extern unsigned int DAT_0108ec80; extern unsigned char DAT_00f725d4;
struct Process {
    PointerMap<Object*>* clones; PointerMap<bool>* states; unsigned int copyType; unsigned char append;
    Process* FUN_00471430(unsigned int n);
};
// pdb: NiCloningProcess::NiCloningProcess | BipedAnim.obj | fnv360_0721_beta, call_seq, medium
// pdb params: uiHashSize
Process* Process::FUN_00471430(unsigned int n) {
    clones = new PointerMap<Object*>(n);
    states = new PointerMap<bool>(n);
    copyType = DAT_0108ec80;
    append = DAT_00f725d4;
    return this;
}
}

// @f3 0x0047fa70 (community match, verified in this file)
namespace f3m_0047fa70 {
struct F7Form {
    virtual void V00(); virtual void V04(); virtual void V08(); virtual void V0C();
    virtual void V10(); virtual void V14(); virtual void V18(); virtual void V1C();
    virtual void V20(); virtual void V24(); virtual void V28(); virtual void V2C();
    virtual void V30(); virtual void V34(); virtual void V38(); virtual void V3C();
    virtual void V40(); virtual void V44(); virtual void V48(); virtual void V4C();
    virtual void V50(); virtual void V54(); virtual void V58(); virtual void V5C();
    virtual void V60(); virtual void V64(); virtual void V68(); virtual void V6C();
    virtual void V70(); virtual void V74(); virtual void V78(); virtual void V7C();
    virtual void V80(); virtual void V84(); virtual void V88(); virtual void V8C();
    virtual void V90();
    virtual bool V94();
    unsigned char type;       // +4
    int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20;
    int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58;
    int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74;
    int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90;
    int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC;
    int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8;
    int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4;
    int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC;
    unsigned char flags100;   // +0x100
};

struct F7Extra { bool FUN_00451d90(); };
F7Extra* FUN_00451da0(F7Form* form);

struct F7CEntry { int count; F7Form* form; };
struct F7CNode { F7CEntry* item; F7CNode* next; };
struct F7Container { int unk00; F7CNode list; int FUN_00452c40(F7Form* form); };
struct F7Source { F7Container* FUN_004e66c0(); };

struct F7Entry { int unk00; int count; F7Form* form; };
struct F7ENode { F7Entry* item; F7ENode* next; };

struct F7Iter {
    int unk00; int count; F7Form* form;
    F7CNode* cur; F7ENode* other; bool done;
};

struct F7Owner {
    F7ENode* unk00;
    F7Source* unk04;
    bool FUN_0047fa70(F7Iter* s, void** out, unsigned int flags);
};

// pdb: InventoryChanges::GetNextItem | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
// pdb params: arIterator, arpItemChange, aiIterateFlags
bool F7Owner::FUN_0047fa70(F7Iter* s, void** out, unsigned int flags)
{
    if (s->done)
        return false;

    if (!s->cur && !s->other) {
        F7Container* c = unk04 ? unk04->FUN_004e66c0() : 0;
        s->cur = &c->list;
    }

    if (s->cur) {
    do {
        F7CNode* node = *(F7CNode* volatile*)&s->cur;
        F7Form* form;
        F7CEntry* item = node->item;
        if (!(s->cur = node->next)) {
            if (unk00)
                s->other = unk00;
            else
                s->done = true;
        }
        if (!item)
            continue;

        form = item->form;
        F7ENode* found = unk00;
        bool searching = true;
        while (found && searching) {
            if (found->item && found->item->form == form)
                searching = false;
            else
                found = found->next;
        }
        if (found && found->item)
            continue;

        if (flags & 1) {
            if (item->form->V94())
                continue;
            F7Extra* extra = FUN_00451da0(item->form);
            if (extra && !extra->FUN_00451d90())
                continue;
            if (item->form->type == 0x28 && (item->form->flags100 & 0x20))
                continue;
        }

        s->unk00 = 0;
        s->count = item->count;
        s->form = item->form;
        *out = s;
        return true;
    } while (s->cur);
    }

    if (s->other) {
    do {
        F7ENode* node = *(F7ENode* volatile*)&s->other;
        F7Form* form;
        F7Entry* entry = node->item;
        if (!(s->other = node->next))
            s->done = true;
        if (!entry)
            continue;

        form = entry->form;
        if (flags & 1) {
            if (form->V94())
                continue;
            F7Extra* extra = FUN_00451da0(form);
            if (extra && !extra->FUN_00451d90())
                continue;
            if (form->type == 0x28 && (form->flags100 & 0x20))
                continue;
        }

        int count = entry->count;
        int total = count + (unk04 ? unk04->FUN_004e66c0() : 0)->FUN_00452c40(form);
        if (total > 0) {
            *out = entry;
            s->unk00 = entry->unk00;
            s->form = form;
            s->count = total;
            *out = s;
            return true;
        }
    } while (s->other);
    }
    return false;
}
}   // namespace f3m_0047fa70

// @f3 0x0047b2e0 (community match, verified in this file)
namespace f3m_0047b2e0 {
namespace Forward47 {
void GridArray_Init();
void FUN_004e2320();
// pdb: GridCellArray::Init | GridCell.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void FUN_0047b2e0() { GridArray_Init(); FUN_004e2320(); }
}
}   // namespace f3m_0047b2e0

// @f3 0x00473ab0 (community match, verified in this file)
extern const char DAT_00dc01d0[];
namespace f3m_00473ab0 {
namespace f3m_00473ab0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiNode;
class NiAVObject {
public:
    virtual void Slot00();
    virtual void DeleteThis();
    virtual const ::TypeInfo* GetRTTI() const;
    volatile long references;
    void IncRef() { InterlockedIncrement(&references); }
    void DecRef()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
    bool IsKindOf(const ::TypeInfo* rtti) const
    {
        for (const ::TypeInfo* t = GetRTTI(); t; t = t->base) {
            if (t == rtti)
                return true;
        }
        return false;
    }
};
struct NiAVObjectPtr {
    NiAVObject* m_pObject;
    NiAVObjectPtr() : m_pObject(0) {}
    NiAVObjectPtr(NiAVObject* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRef();
    }
    ~NiAVObjectPtr()
    {
        if (m_pObject)
            m_pObject->DecRef();
    }
    __declspec(noalias) NiAVObjectPtr& FUN_008e9650(NiAVObject* p);
    NiAVObjectPtr& operator=(NiAVObject* p) { return FUN_008e9650(p); }
    operator NiAVObject*() const { return m_pObject; }
};
struct NiNode : NiAVObject {
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    int unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94;
    int unk98, unk9C;
    NiAVObjectPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short GetChildCount() const { return m_usSize; }
    NiAVObject* GetAt(unsigned int i) const { return m_pBase[i]; }
};
__forceinline bool IsKindOf(const ::TypeInfo* rtti, const NiAVObject* obj)
{
    return obj && obj->IsKindOf(rtti);
}
__forceinline NiAVObject* DynamicCast(const ::TypeInfo* rtti, NiAVObject* obj)
{
    if (!obj) return 0;
    return obj->IsKindOf(rtti) ? obj : 0;
}
struct Root {
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    NiAVObject* unk18;
};
struct FaceModel;
struct BipedBone {
    unsigned char flags;
    NiAVObject* parent;
};
struct BipedPart {
    void* parentForm;
    void* model;
    NiAVObject* scene;
    bool hasAnimation;
};
NiAVObject* __cdecl FUN_00aab350(Root* root, const char* name, bool recursive);
bool __cdecl FUN_0045cd20(NiAVObject* obj);
class Attacher {
public:
    Root* unk00;
    BipedBone bones[5];
    BipedPart parts[20];
    NiAVObject* FUN_00473360(NiAVObject* obj, NiAVObject* parent, int index, bool a3, bool a4, FaceModel* a5);
    NiAVObject* FUN_00473ab0(NiAVObject* obj, int index, bool a3, bool a4, FaceModel* a5);
};
// pdb: BipedAnim::ApplySkinnedObjects | BipedAnim.obj | fnv360_0822_retail, call_gap, low
// pdb params: apClone, aeBipedObject, abFirstPerson, abPipboy, apfgModel
NiAVObject* Attacher::FUN_00473ab0(NiAVObject* obj, int index, bool a3, bool a4, FaceModel* a5)
{
    NiAVObject* result = obj;
    NiNode* node = (NiNode*)DynamicCast(&DAT_0116eeec, obj);
    NiAVObjectPtr temp(0);
    if (!result)
        return result;
    parts[index].hasAnimation = FUN_0045cd20(obj);
    if (!unk00)
        return result;
    if (parts[index].hasAnimation) {
        NiAVObjectPtr spAttach(0);
        NiAVObject* found = FUN_00aab350(unk00, DAT_00dc01d0, true);
        if (found)
            spAttach = found;
        else
            spAttach = unk00->unk18;
        NiAVObject* skinned = 0;
        if (node) {
            for (unsigned int j = 0; j < node->m_usSize; ++j)
                skinned = FUN_00473360(node->GetAt(j), 0, index, a3, a4, a5);
        } else {
            skinned = FUN_00473360(obj, spAttach, index, a3, a4, a5);
        }
        result = skinned;
        if (result != obj) {
            NiAVObjectPtr release(obj);
        }
    } else {
        result = 0;
    }
    return result;
}
}
}   // namespace f3m_00473ab0

// @f3 0x0047aee0 (community match, verified in this file)
extern int DAT_00dc0b1c;
namespace f3m_0047aee0 {
namespace f3m_0047aee0 {
struct FUN_0047aee0 {
    void* vftable;
    FUN_0047aee0();
};
// pdb: GridArray::GridArray | GridArray.obj | fnv360_0721_beta, callee_sim, low
FUN_0047aee0::FUN_0047aee0()
{
    vftable = &DAT_00dc0b1c;
}
}
}   // namespace f3m_0047aee0

// @f3 0x0047e570 (community match, verified in this file)
extern "C" void _ReadWriteBarrier(void);
extern __declspec(thread) int DAT_0117c298;

struct S47e570_Data { bool FUN_00403450(); };

class IngredientItem : public TESBoundObject {
public:
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    unsigned int flags;
};

class AlchemyItem : public TESBoundObject {
public:
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38;
    S47e570_Data data;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8;
    unsigned int flags;
};

namespace S47e570 {

struct S47e570_Heap {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern S47e570_Heap DAT_01090a78;

struct S47e570_MemContext {
    int oldVal;
    S47e570_MemContext(int newVal) { oldVal = DAT_0117c298; DAT_0117c298 = newVal; }
    ~S47e570_MemContext() { DAT_0117c298 = oldVal; }
};

typedef ::TESBoundObject TESForm;
typedef ::IngredientItem S47e570_ItemA;
typedef ::AlchemyItem S47e570_ItemB;

struct ContainerEntry {
    int count;
    TESForm* form;
};
struct ContainerNode {
    ContainerEntry* item;
    ContainerNode* next;
};
struct Container {
    int unk00;
    ContainerNode list;
    bool FUN_004528c0(TESForm* form);
};
struct BaseForm {
    Container* FUN_004e66c0();
};
struct InvEntry {
    void* extraLists;
    int countDelta;
    TESForm* form;
    InvEntry(TESForm* form, int count);
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct InvNode {
    InvEntry* item;
    InvNode* next;
};
struct Owner {
    InvNode* entries;
    BaseForm* baseForm;
    InvEntry* FUN_0047e570();
};

// pdb: InventoryChanges::GetBestFood | InventoryChanges.obj | fnv360_0822_retail, caller_sim, low
InvEntry* Owner::FUN_0047e570()
{
    S47e570_MemContext context(0x36);
    InvEntry* result;
    Container* container = baseForm ? baseForm->FUN_004e66c0() : 0;
    S47e570_ItemB* b = 0;
    for (ContainerNode* node = &container->list; node; node = node->next) {
        if (!node->next && !node->item)
            break;
        TESForm* form;
        S47e570_ItemA* a = dynamic_cast<S47e570_ItemA*>(node->item->form);
        if (!a) {
            b = dynamic_cast<S47e570_ItemB*>(node->item->form);
            form = b;
        } else {
            form = a;
        }
        if ((b && (b->flags & 2) && !b->data.FUN_00403450()) || (a && (a->flags & 2))) {
            InvNode* n = entries;
            bool searching = true;
            while (n && searching) {
                if (n->item && n->item->form == form)
                    searching = false;
                else
                    n = n->next;
            }
            if (n && n->item) {
                InvEntry* e = n->item;
                ContainerEntry* ce = node->item; int d = e->countDelta; int c = ce->count; _ReadWriteBarrier(); if (c + d)
                {result = e; goto done;}
            } else {
                result = new InvEntry(form, 0); goto done;
            }
        }
    }
    for (InvNode* n = entries; n; n = n->next) {
        if (!n->next && !n->item)
            break;
        TESForm* form;
        S47e570_ItemA* a = dynamic_cast<S47e570_ItemA*>(n->item->form);
        if (!a) {
            b = dynamic_cast<S47e570_ItemB*>(n->item->form);
            form = b;
        } else {
            form = a;
        }
        if ((a && (a->flags & 2)) || (b && (b->flags & 2) && !b->data.FUN_00403450())) {
            Container* c = baseForm ? baseForm->FUN_004e66c0() : 0;
            if (!c->FUN_004528c0(form)) {
                if (n->item->countDelta > 0)
                    return n->item;
            }
        }
    }
    return 0;
done:
    return result;
}

}

// @f3 0x0046c9b0 (community match, verified in this file)
namespace f3m_0046c9b0 {
namespace DebugColor2245 {
struct Color {float r,g,b,a;};
struct Geometry {
    unsigned unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24;
    Color* colors;
    void FUN_008313b0(unsigned);
};
struct Mesh {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0C;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1C;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2C;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3C;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4C;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5C;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6C;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7C;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8C;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9C;
    unsigned unkA0;
    unsigned unkA4;
    unsigned unkA8;
    unsigned unkAC;
    unsigned unkB0;
    unsigned unkB4;
    Geometry* data;
};
struct Flags {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0C;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1C;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2C;
    unsigned flags; void SetAppCulled(bool culled) {if (culled) flags |= 1; else flags &= ~1;}
};
struct Owner {
    unsigned unk00,unk04;
    Color color;
    unsigned unk18,unk1C,unk20;
    Mesh* primary;
    Flags* secondary;
    void FUN_0046c9b0(const Color&);
};
// pdb: BGSPrimitivePlane::SetColor | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
// pdb params: aColor
void Owner::FUN_0046c9b0(const Color& value) {
    color=value;
    Mesh* mesh=primary;
    if(mesh) {
        Geometry* data=mesh->data;
        Color* colors=data->colors;
        colors[7]=value;
        colors[6]=value;
        colors[5]=value;
        colors[4]=value;
        colors[3]=value;
        colors[2]=value;
        colors[1]=value;
        colors[0]=colors[1];
        data->FUN_008313b0(4);
    }
    Flags* flags=secondary;
    if(secondary)
        secondary->SetAppCulled(value.a < 0.001);
}
}


}   // namespace f3m_0046c9b0

// @f3 0x0047ffd0 (community match, verified in this file)
namespace f3m_0047ffd0 {

struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;

class FUN_0040eda0;

struct Node {
    FUN_0040eda0* unk00;
    Node* unk04;
    Node() : unk00(0), unk04(0) {}
    void FUN_0049fac0(FUN_0040eda0* const& data);
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

struct List21610 {
    void FUN_00421610(FUN_0040eda0** elem);
};

struct QItem {
    List21610* unk00;
    int unk04;
    int unk08;
};

struct Poly {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48(int value);
};

struct QOwner {
    Node* unk00;
    Poly* unk04;
    QItem* FUN_0047e180(int key, int unused, int formKey);
};

struct Res {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};

class FUN_0040eda0 {
public:
    virtual void vf00(int flags);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    short unk18;
    FUN_0040eda0();
    float FUN_0040ac20();
    void FUN_0040b900();
    void FUN_0040b330(float value);
    void FUN_0040b160(float value);
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

extern void* __cdecl FUN_00c0050a(int form, int unused, int baseType, int targetType, int flags);
extern int __cdecl FUN_00456720(int form);
extern Res* __cdecl FUN_004566c0(int form);

struct Obj {
    Node* unk00;
    int unk04;
    int unk08;
    void FUN_0047ffd0(float value, QOwner* owner, FUN_0040eda0* target, bool flag);
};

// pdb: ItemChange::SetItemHealth | InventoryChanges.obj | fnv360_0822_retail, call_gap, low
// pdb params: afHealth, pchange, apextra, abdelete
void Obj::FUN_0047ffd0(float value, QOwner* owner, FUN_0040eda0* target, bool flag)
{

    void* form = FUN_00c0050a(unk08, 0, 0xF460FC, 0xF49F3C, 0);
    int key = FUN_00456720(unk08);
    Res* list = FUN_004566c0(unk08);

    float result;
    if (list != 0) {
        FUN_0040eda0* p = 0;
        if (unk00 != 0)
            p = unk00->unk00;
        if (p != 0) {
            if (p->FUN_0040ac20() != -1.0f)
                result = p->FUN_0040ac20();
            else
                result = (float)(unsigned int)list->vf10();
        } else {
            result = (float)(unsigned int)list->vf10();
        }
    } else {
        result = -1.0f;
    }

    int count = (int)result;
    Poly* poly = owner->unk04;
    if (poly != 0)
        poly->vf48(0x20);
    if (form == 0)
        return;

    if (value < (float)key || count > key) {
        if (unk00 == 0) {
            FUN_0040eda0* item = new FUN_0040eda0();
            {
                FUN_0040eda0* ref = item;
                Node* node = new Node();
                item->FUN_0040b330(value);
                node->FUN_0049fac0(ref);
                unk00 = node;
            }
        } else {
            Node* node = unk00;
            while (node != 0) {
                if (node->unk00 == 0)
                    break;
                if (node->unk00 == target) {
                    node->unk00->FUN_0040b160(value);
                    return;
                }
                node = node->unk04;
            }
            FUN_0040eda0* item = new FUN_0040eda0();
            {
                FUN_0040eda0* ref = item;
                item->FUN_0040b160(value);
                unk00->FUN_0049fac0(ref);
            }
        }
    } else {
        FUN_0040eda0* tmp;
        FUN_0040eda0* item = 0;
        for (Node* node = unk00; node != 0 && (item = node->unk00) != 0; node = node->unk04) {
            tmp = item;
            if (item == target) {
                item->FUN_0040b900();
                if (item->unk04 != 0)
                    return;
                if (!flag)
                    return;
                QItem* q = owner->FUN_0047e180(unk08, 1, 0);
                q->unk00->FUN_00421610(&tmp);
                item->vf00(1);
                return;
            }
        }
    }
}

}

// @f3 0x004750b0 (community match, verified in this file)
namespace f3m_004750b0 {
struct S_004750b0 {
    char pad[2];
    short m;
    short FUN_004750b0();
};
// pdb: Date::GetYear | Date.obj | fnv360_0822_retail, call_gap, low
short S_004750b0::FUN_004750b0()
{
    return m;
}
}   // namespace f3m_004750b0

// @f3 0x004750a0 (community match, verified in this file)
namespace f3m_004750a0 {
struct S_004750a0 {
    short m;
    short FUN_004750a0();
};
// pdb: Date::GetDate | Date.obj | fnv360_0822_retail, call_gap, low
short S_004750a0::FUN_004750a0()
{
    return m;
}
}   // namespace f3m_004750a0

// @f3 0x004653e0 (community match, verified in this file)
namespace f3m_004653e0 {
namespace Small4653e0 {
struct Element { unsigned int first, second, third; };
struct Array {
    virtual void v00();
    virtual Element* Allocate(unsigned int count);
    virtual void Free(Element* p);
    Element* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_0079e680(Element* destination, const Element* source, unsigned int count);
    void FUN_004653e0(unsigned int index, unsigned int count, bool shrink);
};
void Array::FUN_004653e0(unsigned int index, unsigned int count, bool shrink) {
    if (count >= size) {
        if (data) {
            if (shrink) {
                Free(data);
                data = 0;
                capacity = 0;
            }
            size = 0;
        }
        return;
    }
    if (shrink) {
        if (capacity > 0x400) {
            if (size <= capacity - 0x800)
                goto reallocate;
        } else if (size <= capacity / 4) {
            goto reallocate;
        }
    }
    FUN_0079e680(data + index, data + index + count, size - index - count);
    goto dec;

reallocate:
    unsigned int newCapacity = capacity > 0x800 ? capacity - 0x400 : capacity / 2;
    Element* replacement = Allocate(newCapacity);
    FUN_0079e680(replacement, data, index);
    FUN_0079e680(replacement + index, data + index + count, size - count);
    Free(data);
    data = replacement;
    capacity = newCapacity;
dec:
    size -= count;
}
}
}   // namespace f3m_004653e0

// @f3 0x00468bd0 (community match, verified in this file)
namespace f3m_00468bd0 {
struct WaterCell468bd0 {
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    void* fullNameVtable;
    unsigned int nameData, nameLength;
    unsigned char cellFlags;
    bool HasWater() { return (cellFlags & 2) != 0; }
};
struct PointList468bd0 { void FUN_00bd12d0(); };
extern f3m_00466b80::WaterPoints* DAT_0106dedc;
extern PointList468bd0* DAT_0106dee0;
void __cdecl BGSAutoWater_GatherLineSegments(WaterCell468bd0* cell);
void __cdecl FUN_004655b0(WaterCell468bd0* cell);
void __cdecl FUN_00466330(WaterCell468bd0* cell);
}
// pdb: BGSAutoWater::GeneratePlaceableWaterForCell | BGSAutoWater.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apCell
void __cdecl FUN_00468bd0(f3m_00468bd0::WaterCell468bd0* cell)
{
    using namespace f3m_00468bd0;
    f3m_00464330::AutoMemContext context(0x1d);
    if (!cell || !cell->HasWater())
        return;
    if (DAT_0106dedc)
        DAT_0106dedc->clear();
    if (DAT_0106dee0)
        DAT_0106dee0->FUN_00bd12d0();
    BGSAutoWater_GatherLineSegments(cell);
    FUN_004655b0(cell);
    FUN_00466330(cell);
}

// @f3 0x00460ed0 (community match, verified in this file)
#include <windows.h>
extern __declspec(thread) int DAT_0117c298;
extern const char DAT_00dbe3f8[];
namespace f3m_00460ed0 {


namespace S460ed0 {

struct AutoMemContext {
    int saved;
    AutoMemContext(int context) { saved = DAT_0117c298; DAT_0117c298 = context; }
    ~AutoMemContext() { DAT_0117c298 = saved; }
};

void* __cdecl FUN_0089eb90(unsigned);
void __cdecl FUN_0089ec10(void*);
void __cdecl FUN_00887da0(const char* format, ...);

struct RefObject {
    virtual void v0();
    virtual void DeleteThis();
    long refCount;
    void IncRefCount() { ::InterlockedIncrement(&refCount); }
    void DecRefCount() { if (!::InterlockedDecrement(&refCount)) DeleteThis(); }
};

template <class T> struct Pointer {
    T* object;
    Pointer& operator=(T* value) {
        if (object != value) {
            if (object) object->DecRefCount();
            object = value;
            if (value) value->IncRefCount();
        }
        return *this;
    }
    Pointer& operator=(const Pointer& other);
    T* operator->() const { return object; }
    operator T*() const { return object; }
};

struct FixedString {
    const char* text;
    operator const char*() const { return text; }
};

struct Sequence {
    int unk00;
    int unk04;
    FixedString name;
    int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
    int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    int state;
    const FixedString& GetName() const { return name; }
    int GetState() const { return state; }
};

struct Owner;
struct FUN_00460ba0 : RefObject {
    unsigned unk008; unsigned unk00c; unsigned unk010;
    int section;
    Sequence* sequence;
    unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034;
    FUN_00460ba0(unsigned, unsigned, unsigned, unsigned, unsigned, Owner*);
    static void* operator new(unsigned n) throw() { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ec10(p); }
    int GetSection() const { return section; }
    Sequence* GetSequence() const { return sequence; }
};

typedef Pointer<FUN_00460ba0> EntryPtr;

struct Owner {
    unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c;
    unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c;
    unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c;
    unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c;
    unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c;
    unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc;
    unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc;
    Sequence* sectionSequences[14];
    EntryPtr input;
    unsigned unk11c;
    EntryPtr output[2];
    void FUN_0045e4c0(int section, bool flag);
    void FUN_0045feb0(EntryPtr& entry);
    void FUN_00460ed0(unsigned idle, unsigned section);
};

// pdb: Animation::SpecialIdleQueue | Animation.obj | fnv360_0822_retail, ustr, medium
// pdb params: apIdleForm, aeSection
void Owner::FUN_00460ed0(unsigned idle, unsigned section)
{
    AutoMemContext context(0x33);
    if (input) {
        int index = input->GetSection();
        switch (index) {
        case 21:
            index = 4;
            break;
        case 20:
            index = 1;
            break;
        }
        if (input->GetSequence()) {
            if (sectionSequences[index] == input->GetSequence()) {
                switch (input->GetSequence()->GetState()) {
                case 2:
                case 5:
                    FUN_00887da0(DAT_00dbe3f8, (const char*)input->GetSequence()->GetName());
                    return;
                default:
                    break;
                }
                FUN_0045e4c0(input->GetSection(), false);
            }
        }
        if (!output[0]) {
            output[0] = input;
            input = 0;
        } else if (!output[1]) {
            output[1] = input;
            input = 0;
        } else {
            FUN_0045feb0(input);
        }
    }
    input = new FUN_00460ba0(idle, section, 1, unk004, 0, 0);
}

}
}   // namespace f3m_00460ed0

// @f3 0x00460ba0 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern long DAT_0108ed80;

// Reference-counted base: the constructor counts live objects.
struct ObRefObject {
    virtual ~ObRefObject();
    virtual void DeleteThis();
    long refCount;
    ObRefObject() : refCount(0) { ::InterlockedIncrement(&DAT_0108ed80); }
    void IncRefCount() { ::InterlockedIncrement(&refCount); }
    void DecRefCount() { if (!::InterlockedDecrement(&refCount)) DeleteThis(); }
};

namespace n460ba0 {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;

// Loaded KF model: its own reference count at +0xc and a user count at +0x10 (released without delete).
struct KFModel { int unk00, unk04, unk08; long refCount; long users; };
struct KFModelPtr {
    KFModel* p;
    KFModelPtr() : p(0) {}
    ~KFModelPtr() { if (p) ::InterlockedDecrement(&p->refCount); }
    KFModelPtr& operator=(KFModel* x)
    {
        if (p != x) {
            if (p) ::InterlockedDecrement(&p->refCount);
            p = x;
            if (p) ::InterlockedIncrement(&p->refCount);
        }
        return *this;
    }
};

// String with a heap buffer: pointer, length, capacity.
struct String {
    char* p; unsigned short len; unsigned short cap;
    String() : p(0), len(0), cap(0) {}
    ~String() { if (p) DAT_01090a78.FUN_0086ba60(p); }
};

struct FormBase { virtual void f0(); int unk04, unk08, unk0c, unk10, unk14; };
struct ModelBase { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual const char* GetModel(); };
struct IdleForm : FormBase, ModelBase { };
struct Sequence : ::ObRefObject {};
struct Palette;
struct ControllerManager { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; Palette* objectPalette;
    Palette* GetObjectPalette() { return objectPalette; }
};
struct AnimData { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; ControllerManager* controllerManager;
    ControllerManager* GetControllerManager() { return controllerManager; }
};
struct Actor {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120();
    virtual AnimData* GetAnimData();
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; unsigned short unk140; bool m142;
};
struct IdleManager { IdleForm* FUN_0043ea90(IdleForm* idle, int index); };
struct ModelLoader { KFModel* FUN_00429510(const char* path, void* owner, int priority, Actor* actor); KFModel* FUN_0042cff0(const char* path); };
extern IdleManager* DAT_0106cdcc;
extern ModelLoader* DAT_0106ca70;
extern char DAT_00dbe3dc[];
extern char DAT_00dbe3e4[];
void __cdecl FUN_00403a00(String* out, const char* format, ...);
Sequence* __cdecl FUN_00471ef0(IdleForm* idle, ModelBase* model, int index, Actor* actor, Sequence* root);
void __cdecl FUN_00838830(Sequence* object, Palette* palette);
}

// Idle animation: an idle form, its two sub-idles and their sequences, and the KF model they come from.
struct FUN_00460ba0 : ::ObRefObject {
    int ready;
    int type;
    n460ba0::KFModelPtr model;
    int section;
    ::NiPointer<n460ba0::Sequence> sequence;
    n460ba0::IdleForm* idles[2];
    ::NiPointer<n460ba0::Sequence> sequences[2];
    n460ba0::IdleForm* idleForm;
    int animation;
    n460ba0::Actor* actor;
    FUN_00460ba0(n460ba0::IdleForm* idle, int sectionArg, int typeArg, n460ba0::Actor* actorArg, bool forceLoad, int animationArg);
    ~FUN_00460ba0();
};

// pdb: AnimIdle::AnimIdle | Animation.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apIdleForm, aeSection, aeType, apActor, abForceLoad, apAnimation
FUN_00460ba0::FUN_00460ba0(n460ba0::IdleForm* idle, int sectionArg, int typeArg, n460ba0::Actor* actorArg, bool forceLoad, int animationArg)
{
    sequence = 0;
    section = sectionArg;
    type = typeArg;
    idleForm = idle;
    for (int i = 0; i < 2; i++) {
        idles[i] = n460ba0::DAT_0106cdcc->FUN_0043ea90(idle, i);
        sequences[i] = 0;
    }
    animation = animationArg;
    actor = actorArg;
    n460ba0::String filename;
    n460ba0::FUN_00403a00(&filename, n460ba0::DAT_00dbe3dc, n460ba0::DAT_00dbe3e4, idle->GetModel());
    if (!forceLoad)
        model = n460ba0::DAT_0106ca70->FUN_00429510(filename.p, this, 0, actorArg);
    else
        model = n460ba0::DAT_0106ca70->FUN_0042cff0(filename.p);
    if (model.p) {
        for (int i = 0; i < 2; i++) {
            n460ba0::IdleForm* sub = idles[i];
            if (sub && actorArg) {
                sequences[i] = n460ba0::FUN_00471ef0(sub, sub, -1, actorArg, 0);
                n460ba0::FUN_00838830(sequences[i], actorArg->GetAnimData()->GetControllerManager()->GetObjectPalette());
                actorArg->m142 = true;
            }
        }
        if (!forceLoad)
            ::InterlockedIncrement(&model.p->users);
        ready = 1;
    } else
        ready = 0;
}

// @f3 0x0047a850 (community match, verified in this file)
#include <string.h>
namespace f3m_0047a850 {
namespace match3069 {
struct Heap{void FUN_0086ba60(void*);}; extern Heap DAT_01090a78;
void* FUN_0089e810(unsigned);
inline void ZeroBuckets(void* p,unsigned bytes){memset(p,0,bytes);}
struct Point{float x,y,z; Point(){} Point FUN_004229a0(const Point&)const;float FUN_00432bd0()const;void FUN_00468d00();Point& FUN_00432b70(const Point&);static void operator delete(void*p){DAT_01090a78.FUN_0086ba60(p);}};
struct Matrix{float m00,m01,m02,m10,m11,m12,m20,m21,m22;Matrix(){} Matrix FUN_00475490()const;Matrix operator*(const Matrix&)const;Point FUN_004752c0(const Point*);};
struct Transform:Matrix{Point translation;float scale;Transform(){}void FUN_00477790(Transform&);};
struct GeometryData{unsigned f0,f4;unsigned short count,padA;unsigned fC,f10,f14,f18,f1c;Point* vertices;Point* normals;void FUN_008313b0(unsigned);};
struct Geometry{
unsigned f0;
unsigned f4;
unsigned f8;
unsigned fc;
unsigned f10;
unsigned f14;
unsigned f18;
unsigned f1c;
unsigned f20;
unsigned f24;
unsigned f28;
unsigned f2c;
unsigned f30;
unsigned f34;
unsigned f38;
unsigned f3c;
unsigned f40;
unsigned f44;
unsigned f48;
unsigned f4c;
unsigned f50;
unsigned f54;
unsigned f58;
unsigned f5c;
unsigned f60;
unsigned f64;
 Transform transform;
 unsigned f9c,fa0,fa4,fa8,fac,fb0,fb4;
 GeometryData* data;
 Point* Vertices(){return data->vertices;} Point* Normals(){return data->normals;} unsigned short Count(){return data->count;}
 Transform& World(){return transform;} GeometryData* Data(){return data;}
};
struct Entry{unsigned first,second;float bestDistance10;unsigned First()const{return first;}unsigned Second()const{return second;}};
struct MapBase{virtual ~MapBase();unsigned count;void** buckets;unsigned size;
 MapBase(unsigned n):count(n),size(0){buckets=(void**)FUN_0089e810(n*4);ZeroBuckets(buckets,count*sizeof(void*));}
};
struct PairMap:MapBase{PairMap(unsigned n):MapBase(n){}virtual ~PairMap();
 bool FUN_00477680(unsigned,Entry&);void FUN_004775e0(unsigned,Entry);void* FUN_004d4210();void FUN_004776e0(void*&,unsigned&,Entry&);
};
Point* FUN_00477d30(Geometry*); bool FUN_00408df0(float,float,float);Point FUN_00468cd0(float,const Point&);extern Geometry* DAT_0106e9a0;
}
// @fnv 0x004b3e60
// pdb: FixNormals | GlobalFunc.obj | fnv360_0822_retail, call_gap, low
// pdb params: apSource, apDest, afTolerance, abDisplayMatches, abExtrudeMatches
bool __cdecl FUN_0047a850(match3069::Geometry* source, match3069::Geometry* target, float threshold, float unused, bool adjust)
{
    match3069::PairMap map30(37);
    match3069::Matrix rotation4;
    bool bChangedB = false;
    if (!source || !target || source == target)
        return false;
    match3069::Point* sourceVertices7 = source->Vertices();
    match3069::Point* sourceNormals2 = source->Normals();
    unsigned int uiCountX = source->Count();
    if (!sourceVertices7 || !sourceNormals2 || !uiCountX)
        return false;
    match3069::Point* targetVertices5 = target->Vertices();
    match3069::Point* targetNormals2 = target->Normals();
    unsigned int uiCountVal = target->Count();
    if (!targetVertices5 || !targetNormals2 || !uiCountVal)
        return false;
    match3069::Point* sourcePositions = match3069::FUN_00477d30(source);
    if (!sourcePositions)
        return false;
    match3069::Point* targetVertices = match3069::FUN_00477d30(target);
    if (!targetVertices)
    {
        delete sourcePositions;
        return false;
    }
    { match3069::Transform aTransform; target->World().FUN_00477790(aTransform); }
    rotation4 = target->World().FUN_00475490() * source->World();
    unsigned int best4;
    float bestDist3;
    float bestDistance10;
    float minimumVal = 3.402823466e+38F;
    for (unsigned int outer = 0; outer < uiCountVal; outer++)
    {
        best4 = uiCountX;
        bestDist3 = threshold >= 0.0 ? threshold : 3.402823466e+38F;
        for (unsigned int inner = 0; inner < uiCountX; inner++)
        {
            bestDistance10 = targetVertices[outer].FUN_004229a0(sourcePositions[inner]).FUN_00432bd0();
            if (bestDistance10 < bestDist3)
            {
                best4 = inner;
                bestDist3 = bestDistance10;
            }
            if (bestDistance10 < minimumVal)
                minimumVal = bestDistance10;
        }
        if (best4 < uiCountX)
        {
            match3069::Entry entry20;
            entry20.first = outer;
            entry20.second = uiCountVal;
            entry20.bestDistance10 = bestDist3;
            match3069::Entry existing;
            if (((f3m_00477680::FUN_00477680_cls*)&map30)->FUN_00477680(best4, (f3m_00477680::FUN_00477680_out*)&existing))
            {
                if (match3069::FUN_00408df0(entry20.bestDistance10, existing.bestDistance10, 0.001F))
                {
                    entry20.second = existing.first;
                    map30.FUN_004775e0(best4, entry20);
                }
                else if (entry20.bestDistance10 < existing.bestDistance10)
                    map30.FUN_004775e0(best4, entry20);
            }
            else
                map30.FUN_004775e0(best4, entry20);
        }
    }
    {
        void* position = map30.FUN_004d4210();
        unsigned int iCount = 0;
        unsigned int aHKey;
        match3069::Entry existing;
        while (position)
        {
            iCount++;
            ((FUN_004776e0_Owner*)&map30)->FUN_004776e0((int**)&position, (int*)&aHKey, (int*)&existing);
            targetNormals2[existing.first] = rotation4.FUN_004752c0(&sourceNormals2[aHKey]);
            targetNormals2[existing.first].FUN_00468d00();
            if (existing.second < uiCountVal)
            {
                targetNormals2[existing.second] = targetNormals2[existing.first];
                iCount++;
            }
            if (adjust)
            {
                if (match3069::DAT_0106e9a0 != source)
                    sourceVertices7[aHKey].FUN_00432b70(match3069::FUN_00468cd0(10.0F, sourceNormals2[aHKey]));
                targetVertices5[existing.first].FUN_00432b70(match3069::FUN_00468cd0(10.0F, targetNormals2[existing.first]));
                if (existing.second < uiCountVal)
                    targetVertices5[existing.second] = targetVertices5[existing.first];
            }
            bChangedB = true;
        }
    }
    if (bChangedB)
    {
        if (adjust)
            source->Data()->FUN_008313b0(3);
        target->Data()->FUN_008313b0(3);
    }
    if (sourcePositions)
        delete sourcePositions;
    if (targetVertices)
        delete targetVertices;
    match3069::DAT_0106e9a0 = source;
    return bChangedB;
}
}   // namespace f3m_0047a850

// @f3 0x00470190 (community match, verified in this file)
namespace NativeTextureReport470190 {
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;

struct __declspec(align(8)) Text {
    char* data;
    unsigned short length;
    unsigned short capacity;
    Text() : data(0), length(0), capacity(0) {}
    ~Text()
    {
        if (data)
            DAT_01090a78.FUN_0086ba60(data);
        data = 0;
        capacity = 0;
        length = 0;
    }
};
void __cdecl FUN_00403a00(Text*, const char*, ...);

struct BSFile {
    void** vtable;
    unsigned streamFlags;
    void* readFunction;
    void* writeFunction;
    char* buffer;
    unsigned bufferSize;
    unsigned bufferReadSize;
    unsigned bufferPosition;
    int mode;
    void* file;
    bool good;
    unsigned unk2c;
    unsigned fileSize;
    unsigned filePosition;
    bool useAuxBuffer;
    unsigned auxBufferSize;
    unsigned auxPosition;
    char path[0x104];
    void* fileBuffer;
    unsigned trueFilePosition;
    unsigned unk150;

    __forceinline BSFile(const char* name, int mode, unsigned size, bool open)
    {
        FUN_00bcd300(name, mode, size, open);
    }
    __forceinline ~BSFile() { FUN_00bcd9b0(); }
    void FUN_00bcd300(const char*, int, unsigned, bool);
    bool FUN_00bcde70(bool, bool);
    void FUN_00bcdcd0(Text*, int);
    void FUN_00bcd770();
    void FUN_00bcd9b0();
};

struct RTTI {
    const char* name;
    const RTTI* base;
    __forceinline bool IsKindOf(const RTTI* required) const {
        const RTTI* type = this;
        for (; type; type = type->base)
            if (type == required) return true;
        return false;
    }
};
extern RTTI DAT_0108f20c;
struct Usage;
struct TextureName { const char* value; };
struct Texture {
    virtual void Slot000();
    virtual void Slot004();
    virtual const RTTI* GetRTTI();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual TextureName* GetName();
    const char* Name() { return GetName()->value; }
    void WriteUsage(BSFile&, Usage*);
    __forceinline bool HasUsageName() {
        const RTTI* type = GetRTTI();
        return type && type->IsKindOf(&DAT_0108f20c);
    }
};
struct Form {
    virtual void Slot000();
    virtual void Slot004();
    virtual void Slot008();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual void Slot09c();
    virtual void Slot0a0();
    virtual void Slot0a4();
    virtual void Slot0a8();
    virtual void Slot0ac();
    virtual void Slot0b0();
    virtual void Slot0b4();
    virtual void Slot0b8();
    virtual void Slot0bc();
    virtual void Slot0c0();
    virtual void Slot0c4();
    virtual void Slot0c8();
    virtual void Slot0cc();
    virtual void Slot0d0();
    virtual void Slot0d4();
    virtual void Slot0d8();
    virtual void Slot0dc();
    virtual void Slot0e0();
    virtual void Slot0e4();
    virtual void Slot0e8();
    virtual void Slot0ec();
    virtual void Slot0f0();
    virtual void Slot0f4();
    virtual void Slot0f8();
    virtual void Slot0fc();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10c();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11c();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12c();
    virtual const char* EditorName();
    unsigned char formType;
    unsigned unk08;
    unsigned id;
};
struct FormType { const char* name; unsigned unk04; unsigned unk08; };
extern FormType DAT_00f4a74c[];
struct UserNode { Form* form; UserNode* next;
    __forceinline unsigned Count() const {
        unsigned n=0;
        const UserNode* node=this;
        while (node) {
            if(node->form) ++n;
            node=node->next;
        }
        return n;
    }
};
struct Usage { unsigned unk00; unsigned bytes; UserNode users; __forceinline unsigned CountUsers() const { return users.Count(); } };

struct UsageEntry {
    UsageEntry* next;
    Texture* texture;
    Usage* usage;
};
struct UsageMap {
    virtual void Destroy();
    virtual unsigned BucketOf(Texture*) const;
    unsigned bucketCount;
    UsageEntry** buckets;
    __forceinline UsageEntry* First()
    {
        unsigned i = 0;
        unsigned count = bucketCount;
        if (i < count) {
            UsageEntry** base = buckets;
            UsageEntry** cursor = base;
            do {
                if (*cursor)
                    return base[i];
                ++i;
                ++cursor;
            } while (i < count);
        }
        return 0;
    }
    __declspec(noinline) void FUN_0089a5d0(UsageEntry*&, Texture*&, Usage*&);
};

void UsageMap::FUN_0089a5d0(UsageEntry*& position, Texture*& texture, Usage*& usage)
{
    UsageEntry* entry=position;
    texture=entry->texture;
    usage=entry->usage;
    if (entry->next) {
        position=entry->next;
        return;
    }
    for (unsigned index=BucketOf(entry->texture)+1; index<bucketCount; ++index) {
        if (buckets[index]) {
            position=buckets[index];
            return;
        }
    }
    position=0;
}

extern const char DAT_00dbfacc[];
extern const char DAT_00dbfabc[];
extern const char DAT_00dbfab8[];
static __forceinline bool IsKindOfT(const RTTI* req, Texture* obj)
{
    if (!obj)
        return false;
    for (const RTTI* t = obj->GetRTTI(); t; t = t->base)
        if (t == req)
            return true;
    return false;
}
static __forceinline Texture* DynCastT(Texture* obj)
{
    return IsKindOfT(&DAT_0108f20c, obj) ? obj : 0;
}
__forceinline void Texture::WriteUsage(BSFile& file, Usage* result)
{
    Text line;
    UserNode* users=&result->users;
    unsigned count=result->CountUsers();
    FUN_00403a00(&line, DAT_00dbfacc, Name(), result->bytes, count);
    file.FUN_00bcdcd0(&line, 1);
    while (users && (users->next || users->form)) {
        Form* form = users->form;
        users = users->next;
        const unsigned id = form->id;
        const char* name = DAT_00f4a74c[form->formType].name;
        FUN_00403a00(&line, DAT_00dbfabc, name, form->EditorName(), id);
        file.FUN_00bcdcd0(&line, 1);
    }
    FUN_00403a00(&line, DAT_00dbfab8);
    file.FUN_00bcdcd0(&line, 1);
}
struct TextureUseMap {
    unsigned unk00;
    UsageMap map;
    bool BGSTextureUseMap_WriteToFile(const char* path);
};

// pdb: BGSTextureUseMap::WriteToFile | BGSTextureUseMap.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
bool TextureUseMap::BGSTextureUseMap_WriteToFile(const char* path)
{
    bool success=false;
    {
      BSFile file(path, 1, 0x400, true);
      if (file.FUN_00bcde70(false,false)) {
        success=true;
        UsageMap* const reports = &map;
        UsageEntry* position = reports->First();
        while (position) {
            Texture* entry = 0;
            Usage* usage = 0;
            reports->FUN_0089a5d0(position, entry, usage);
            Texture* texture = 0;
            if (entry) texture = DynCastT(entry);
            if (texture && usage)
                texture->WriteUsage(file, usage);
        }
        file.FUN_00bcd770();
      }
    }
    return success;
}
}

// @f3 0x00461a70 (community match, verified in this file)
namespace b1788 {

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

extern __declspec(thread) int DAT_0117c298;

struct AutoMemContext
{
    int saved;
    AutoMemContext(int tag) { saved = DAT_0117c298; DAT_0117c298 = tag; }
    ~AutoMemContext() { DAT_0117c298 = saved; }
};

struct Heap
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned int bytes);
void __cdecl FUN_00887da0(const char* format, ...);
bool __cdecl FUN_0061ac60(int id, int unk);

extern const char DAT_00dbe530[];
extern const char DAT_00dbe4a0[];
extern const char DAT_00dbe464[];
extern const char DAT_0108f3fc[];
extern long DAT_0116d6bc;

struct NiRTTI
{
    const char* name;
    const NiRTTI* parent;
};
extern const NiRTTI DAT_01070040;

struct NiRefObject
{
    virtual void DeleteThis(int flags);
    virtual void Destroy();
    long refs;
};

struct NiObject : NiRefObject
{
    virtual const NiRTTI* GetRTTI();
};

struct AnimGroup : NiObject
{
    int unk08;
    int unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24;
    const char* GetName() const { return (const char*)unk08; }
};

struct NiControllerSequence
{
    virtual void v00();
    virtual void Destroy();
    long refs;
    int unk08;
    unsigned int unk0C;
    int FUN_0054bef0();
    unsigned short FUN_0054b770();
    void FUN_008aa770(unsigned int index, int unk);
    const char* GetName() const { return (const char*)unk08; }
    unsigned int GetCount() const { return unk0C; }
};

struct BSAnimGroupSequence : NiControllerSequence
{
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74;
    BSAnimGroupSequence(NiControllerSequence* source, AnimGroup* group);
    int GetAnimGroup() const { return unk74; }
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct ActiveSequence
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    BSAnimGroupSequence* unk18;
    BSAnimGroupSequence* GetSequence() { return unk18; }
};

template <class T> struct NiPointer
{
    T* object;
    NiPointer(T* o) : object(o) { if (object) InterlockedIncrement(&object->refs); }
    NiPointer(const NiPointer& o) : object(o.object) { if (object) InterlockedIncrement(&object->refs); }
    operator T*() const { return object; }
    ~NiPointer() { if (object && !InterlockedDecrement(&object->refs)) object->Destroy(); }
};

struct KFModel
{
    int unk00;
    int unk04;
    NiPointer<NiControllerSequence> controllerSequence;
    int unk0C;
    long refs;
    AnimGroup* FUN_007270f0();
    NiControllerSequence* GetAnimGroup() const { return controllerSequence; }
    operator const char*() const { return (const char*)unk00; }
};

struct AnimSequenceBase
{
    virtual void DeleteThis(int flags);
    virtual void Add(BSAnimGroupSequence* seq, bool unk);
    virtual bool Remove(BSAnimGroupSequence* seq, bool unk);
    virtual bool IsSingle();
    virtual BSAnimGroupSequence* GetSequence(int index);
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct AnimSequenceSingle : AnimSequenceBase
{
    BSAnimGroupSequence* sequence;
    AnimSequenceSingle() : sequence(0) {}
    virtual void DeleteThis(int flags);
    virtual void Add(BSAnimGroupSequence* seq, bool unk);
    virtual bool Remove(BSAnimGroupSequence* seq, bool unk);
    virtual bool IsSingle();
    virtual BSAnimGroupSequence* GetSequence(int index);
};

struct AnimSequenceMultiple : AnimSequenceBase
{
    void* sequences;
    AnimSequenceMultiple(AnimSequenceBase* single);
};

struct AnimMapItem
{
    AnimMapItem* next;
    unsigned short key;
    AnimSequenceBase* value;
};

struct AnimSequenceMap
{
    virtual void v00();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short a, unsigned short b);
    unsigned int hashSize;
    AnimMapItem** table;
    __declspec(noinline) bool FUN_0045c6e0(unsigned short key, AnimSequenceBase*& value)
    {
        unsigned int index = KeyToHashIndex(key);
        AnimMapItem* item = table[index];
        while (item)
        {
            if (IsKeysEqual(key, item->key))
            {
                value = item->value;
                return true;
            }
            item = item->next;
        }
        return false;
    }
    void FUN_0045c660(unsigned short key, AnimSequenceBase* value);
    void FUN_005df1f0(unsigned short key);
};

struct NiControllerManager;
struct ManagerPtr
{
    NiControllerManager* object;
    operator NiControllerManager*() const { return object; }
    NiControllerManager* operator->() const { return object; }
};
struct NiControllerManager
{
    void FUN_008a9050(BSAnimGroupSequence* seq);
    bool FUN_008a9420(BSAnimGroupSequence* seq, const char* name, bool unk);
    int FUN_0045c830();
};

struct NiFixedString
{
    char* str;
};
extern NiFixedString FUN_00e207a8;

struct NiFixedStringTemp
{
    char* str;
    NiFixedStringTemp() : str(FUN_00e207a8.str) {}
    NiFixedStringTemp(const char* s) { if (s) str = AddString(s); else str = FUN_00e207a8.str; }
    static char* AddString(const char* s);
    ~NiFixedStringTemp() { if (str != FUN_00e207a8.str) InterlockedDecrement((long*)(str - 8)); }
};

struct NiNode
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38();
    virtual void* GetObjectByName(const NiFixedStringTemp& name);
    int unk04;
    int unk08;
    const char* GetName() const { return (const char*)unk08; }
};
struct NodePtr
{
    NiNode* object;
    operator NiNode*() const { return object; }
    NiNode* operator->() const { return object; }
};

struct ModelQueueNode
{
    KFModel* item;
    ModelQueueNode* next;
    ModelQueueNode(KFModel* d) : item(d), next(0) {}
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
};

struct ModelQueue
{
    KFModel* item;
    ModelQueueNode* next;
    __declspec(noinline) void FUN_0061c430(KFModel* const& data)
    {
        if (!data)
            return;
        ModelQueueNode* node = (ModelQueueNode*)this;
        while (node->next)
            node = node->next;
        if (node->item)
        {
            node->next = new ModelQueueNode(data);
        }
        else
            node->item = data;
    }
};

struct GroupInfo
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned short unk02;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
};
extern GroupInfo FUN_00f5aca4[];

enum GroupEnum { GROUP_NONE = 0xff };

struct Animation
{
    int unk00;
    int unk04;
    NodePtr root;
    int unk0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24;
    int nodes[8];
    int unk48;
    short unk4C[8];
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
int unkB8;
int unkBC;
int unkC0;
int unkC4;
int unkC8;
int unkCC;
int unkD0;
int unkD4;
    ManagerPtr controllerManager;
    AnimSequenceMap* sequences;
    BSAnimGroupSequence* unkE0[8];
    BSAnimGroupSequence* unk100;
    ModelQueue unk104;
    int unk10C, unk110, unk114, unk118, unk11C;
    ActiveSequence* unk120;
    ActiveSequence* unk124;

    void FUN_0045d630(NiControllerSequence* seq);
    bool FUN_00461a70(KFModel* model, bool queue);
    __forceinline AnimSequenceBase* GetOrCreate(unsigned short groupID)
    {
        AnimSequenceBase* found = 0;
        if (!sequences->FUN_0045c6e0(groupID, found))
        {
            AnimSequenceBase* created = new AnimSequenceSingle();
            sequences->FUN_0045c660(groupID, created);
            return created;
        }
        return found;
    }
};

inline bool IsKindOf(const NiRTTI* target, NiObject* obj)
{
    if (obj)
    {
        for (const NiRTTI* r = obj->GetRTTI(); r; r = r->parent)
            if (r == target)
                return true;
    }
    return false;
}

// pdb: Animation::AddAnimation | Animation.obj | fnv360_0822_retail, ustr, medium
// pdb params: apKFModel, abDelaySequenceClone
bool Animation::FUN_00461a70(KFModel* model, bool queue)
{
    NiPointer<NiControllerSequence> group(model->controllerSequence);
    if (!(NiControllerSequence*)group)
        return false;
    int groupType = ((NiControllerSequence*)group)->FUN_0054bef0();
    unsigned short code = ((NiControllerSequence*)group)->FUN_0054b770();
    if (groupType == 0xff)
    {
        if (model->FUN_007270f0())
            FUN_00887da0(DAT_00dbe530, model->FUN_007270f0()->GetName(), (const char*)*model);
        return false;
    }
    AutoMemContext context(0x33);
    AnimSequenceBase* base = 0;
    if (!sequences->FUN_0045c6e0(code, base))
    {
        base = new AnimSequenceSingle;
        sequences->FUN_0045c660(code, base);
    }
    if (base->IsSingle() && base->GetSequence(-1))
    {
        if (FUN_00f5aca4[groupType].unk00)
        {
            sequences->FUN_005df1f0(code);
            AnimSequenceBase* single = base;
            base = new AnimSequenceMultiple(single);
            sequences->FUN_0045c660(code, base);
        }
        else
        {
            if (base->GetSequence(-1)->GetAnimGroup() == (int)model->GetAnimGroup())
                return true;
            bool remove = true;
            if (unk120 && unk120->GetSequence() == base->GetSequence(-1))
                remove = false;
            else if (unk124 && unk124->GetSequence() == base->GetSequence(-1))
                remove = false;
            if (remove)
            {
                if (base->GetSequence(-1) == unk100)
                    unk100 = 0;
                controllerManager->FUN_008a9050(base->GetSequence(-1));
            }
            BSAnimGroupSequence* old = base->GetSequence(-1);
            if (old)
            {
                for (int index = 0; index < 8; index++)
                {
                    if (unkE0[index] == old)
                    {
                        unkE0[index] = 0;
                        unk4C[index] = 0;
                    }
                }
            }
            if (unk100 && base->GetSequence(-1) == unk100)
                unk100 = 0;
            base->Add(0, true);
        }
    }
    if (queue && !FUN_0061ac60(0x40c, 0) && groupType != 0x17 && groupType != 0 && groupType != 0xa5)
    {
        InterlockedIncrement(&model->refs);
        unk104.FUN_0061c430(model);
    }
    else
    {
        AnimGroup* original = model->FUN_007270f0();
        if (groupType >= 3 && groupType <= 16 && original->unk24 == 2)
        {
            sequences->FUN_005df1f0(code);
            if (base)
                base->DeleteThis(1);
            return false;
        }
        BSAnimGroupSequence* seq = 0;
        bool compatible = IsKindOf(&DAT_01070040, original);
        if (compatible && original->refs == 1)
            seq = (BSAnimGroupSequence*)original;
        else
            seq = new BSAnimGroupSequence(model->controllerSequence, original);
        base->Add(seq, true);
        bool added = controllerManager->FUN_008a9420(seq, DAT_0108f3fc, true);
        if (!added)
        {
            FUN_00887da0(DAT_00dbe4a0, seq->GetName(), root->GetName());
            InterlockedIncrement(&DAT_0116d6bc);
            if (DAT_0116d6bc < 0)
                DAT_0116d6bc = 0;
            for (unsigned int target = 0; target < seq->unk0C; target++)
            {
                char* name = 0;
                seq->FUN_008aa770(target, (int)name);
                if (!root->GetObjectByName(NiFixedStringTemp(name)))
                    FUN_00887da0(DAT_00dbe464, name);
                DAT_01090a78.FUN_0086ba60(name);
            }
            InterlockedDecrement(&DAT_0116d6bc);
            if (DAT_0116d6bc < 0)
                DAT_0116d6bc = 0;
            if (seq == unk100)
                unk100 = 0;
            controllerManager->FUN_008a9050(seq);
            if (base->Remove(seq, true))
            {
                sequences->FUN_005df1f0(code);
                base->DeleteThis(1);
            }
            return false;
        }
        if (!unk0C)
            unk0C = controllerManager->FUN_0045c830();
        FUN_0045d630(model->controllerSequence);
    }
    return true;
}

}

// @f3 0x0047ff70 (community match, verified in this file)
namespace f3m_0047ff70 {
struct ExtraLev;
struct ExtraList {
    int unk00;
    int unk04;
    ExtraLev* FUN_0040ac60();
    void BaseExtraList_RemoveExtra(ExtraLev* extra, int flag);
    bool IsEmpty() { return unk04 == 0; }
};
struct Heap { void FUN_0086ba60(void* memory); };
extern Heap DAT_01090a78;

struct SimpleList {
    ExtraList* item;
    SimpleList* next;
    void FUN_006c8220();
    void FUN_00421610(ExtraList* const& key);
    ExtraList*& GetItem() { return item; }
    SimpleList* GetNext() { return next; }
};
__declspec(noinline) void SimpleList::FUN_00421610(ExtraList* const& key)
{
    ExtraList* value = key;
    if (!value || (!next && !item))
        return;
    SimpleList* current = this;
    SimpleList* previous = this;
    while (current && current->item != value) {
        previous = current;
        current = current->next;
    }
    if (!current)
        return;
    if (current == this) {
        SimpleList* following = next;
        if (following) {
            next = following->next;
            item = following->item;
            following->next = 0;
            following->FUN_006c8220();
            DAT_01090a78.FUN_0086ba60(following);
        } else {
            item = 0;
        }
    } else {
        previous->next = current->next;
        current->next = 0;
        current->FUN_006c8220();
        DAT_01090a78.FUN_0086ba60(current);
    }
}
}
using namespace f3m_0047ff70;

struct FUN_0047ff70_cls {
    SimpleList* lists;
    ExtraLev* FUN_0047ff70();
};

ExtraLev* FUN_0047ff70_cls::FUN_0047ff70()
{
    ExtraLev* result = 0;
    SimpleList* node = lists;
    while (node && node->GetItem()) {
        ExtraList* extra = node->GetItem();
        if (extra && extra->FUN_0040ac60()) {
            result = extra->FUN_0040ac60();
            extra->BaseExtraList_RemoveExtra(result, 0);
            if (extra->IsEmpty())
                lists->FUN_00421610(extra);
            node = lists;
        }
        node = node->GetNext();
    }
    return result;
}

// @f3 0x00478040 (community match, verified in this file)
namespace f3m_00478040 {
namespace f3m_00478040 {
struct Property {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    int type;
    int GetType() const { return type; }
};
struct Node;
struct Object;
template <class T> struct ObjectArray {
    T* base;
    unsigned short capacity;
    unsigned short size;
    unsigned short GetSize() const { return size; }
    T& GetAt(unsigned int i) const { return base[i]; }
};
struct Object {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node* IsNode();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    Property* FUN_00826590(int type);
};
struct Node : Object {
    ObjectArray<Object*> children;
    unsigned int GetChildCount() const { return children.GetSize(); }
    Object* GetAt(unsigned int i) const { return children.GetAt(i); }
    Object* GetAtChecked(unsigned int i) const { return children.GetSize() > i ? children.GetAt(i) : 0; }
};
Property* __cdecl FUN_00477fa0(Node* node);
}
using namespace f3m_00478040;

// pdb: FindPerPixelLighting | GlobalFunc.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apNode
Property* __cdecl FUN_00478040(Node* node)
{
    if (!node->GetChildCount())
        return 0;
    unsigned int n = node->GetChildCount() - 1;
    while (true)
    {
        Object* object = node->GetAt(n);
        if (object) {
            Node* child = object->IsNode();
            if (child) {
                Object* first = child->GetAtChecked(0);
                if (first) {
                    Property* property = first->FUN_00826590(3);
                    if (property) {
                        Property* lighting = (property == 0 ? 0 : (property->GetType() >= 7 && property->GetType() <= 11)) ? property : 0;
                        if (lighting)
                            return lighting;
                    }
                }
            }
        }
        if (n == 0)
            break;
        n--;
    }
    return FUN_00477fa0(node);
}
}   // namespace f3m_00478040

// @f3 0x0047ee00 (community match, verified in this file)
extern float FUN_00db38b8;
namespace f3m_0047ee00 {
namespace f3m_0047ee00 {
struct TESForm {
    virtual void V000(); virtual void V004(); virtual void V008(); virtual void V00C(); virtual void V010(); virtual void V014(); virtual void V018(); virtual void V01C(); virtual void V020(); virtual void V024(); virtual void V028(); virtual void V02C(); virtual void V030(); virtual void V034(); virtual void V038(); virtual void V03C(); virtual void V040(); virtual void V044(); virtual void V048(); virtual void V04C(); virtual void V050(); virtual void V054(); virtual void V058(); virtual void V05C(); virtual void V060(); virtual void V064(); virtual void V068(); virtual void V06C(); virtual void V070(); virtual void V074(); virtual void V078(); virtual void V07C(); virtual void V080(); virtual void V084(); virtual void V088(); virtual void V08C(); virtual void V090();
    virtual bool IsQuestItem();
    unsigned char type04;
};
float __cdecl FUN_0045c010(TESForm* form);
struct ContainerEntry { int count; TESForm* form; };
struct ContainerNode { ContainerEntry* item; ContainerNode* next; };
struct Container { int unk00; ContainerNode list; bool FUN_004528c0(TESForm* form); };
struct InventoryEntry { void* extraLists; int countDelta; TESForm* form; bool ItemChange_GetWorn(bool highOnly); };
struct InventoryNode { InventoryEntry* item; InventoryNode* next; };
struct ActorValueOwner { int unk00; };
void __cdecl FUN_006f9560(ActorValueOwner* owner, int index, float oldValue, float delta, int unk);
struct Ref {
    virtual void V000(); virtual void V004(); virtual void V008(); virtual void V00C(); virtual void V010(); virtual void V014(); virtual void V018(); virtual void V01C(); virtual void V020(); virtual void V024(); virtual void V028(); virtual void V02C(); virtual void V030(); virtual void V034(); virtual void V038(); virtual void V03C(); virtual void V040(); virtual void V044(); virtual void V048(); virtual void V04C(); virtual void V050(); virtual void V054(); virtual void V058(); virtual void V05C(); virtual void V060(); virtual void V064(); virtual void V068(); virtual void V06C(); virtual void V070(); virtual void V074(); virtual void V078(); virtual void V07C(); virtual void V080(); virtual void V084(); virtual void V088(); virtual void V08C(); virtual void V090(); virtual void V094(); virtual void V098(); virtual void V09C(); virtual void V0A0(); virtual void V0A4(); virtual void V0A8(); virtual void V0AC(); virtual void V0B0(); virtual void V0B4(); virtual void V0B8(); virtual void V0BC(); virtual void V0C0(); virtual void V0C4(); virtual void V0C8(); virtual void V0CC(); virtual void V0D0(); virtual void V0D4(); virtual void V0D8(); virtual void V0DC(); virtual void V0E0(); virtual void V0E4(); virtual void V0E8(); virtual void V0EC(); virtual void V0F0(); virtual void V0F4(); virtual void V0F8(); virtual void V0FC();
    virtual bool IsActor();
    Container* FUN_004e66c0();
};
struct Actor : Ref {
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098;
    ActorValueOwner avOwner9C;
};
struct InventoryChanges {
    InventoryNode* entries;
    Ref* ref;
    float totalWeight;
    float armorWeight;
    // Fake match: force the search helper inline to retain its search/join structure.
    __forceinline InventoryEntry* Find(TESForm* form) {
        InventoryNode* n = entries;
        bool searching = true;
        while (n && searching) {
            InventoryEntry* e = n->item;
            if (e && e->form == form) searching = false;
            else n = n->next;
        }
        return n ? n->item : 0;
    }
    float FUN_0047ee00();
};
// pdb: InventoryChanges::GetInventoryWeight | InventoryChanges.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abIsHardcore
float InventoryChanges::FUN_0047ee00()
{
    Actor* actor = 0;
    if (ref->IsActor())
        actor = (Actor*)ref;
    if (totalWeight == -1.0)
    {
        float total = 0.0f;
        Container* container = ref ? ref->FUN_004e66c0() : 0;
        for (ContainerNode* node = &container->list; node; node = node->next)
        {
            if (!node->next && !node->item)
                break;
            TESForm* form = node->item->form;
            if (form->IsQuestItem())
                continue;
            float weight = FUN_0045c010(form);
            if (weight == -1.0)
                weight = 0.0f;
            InventoryEntry* e = Find(form);
            if (!e) {
                total += node->item->count * weight;
            // Fake match: preserve the redundant nonnull check and repeated sum for branch/codegen shape.
            } else if (e && e->countDelta + node->item->count) {
                total += (e->countDelta + node->item->count) * weight;
            }
        }
        for (InventoryNode* n = entries; n; n = n->next)
        {
            InventoryEntry* e = n->item;
            if (!e)
                break;
            TESForm* form = e->form;
            if (!form)
                continue;
            if ((ref ? ref->FUN_004e66c0() : 0) && (ref ? ref->FUN_004e66c0() : 0)->FUN_004528c0(form))
                continue;
            if (form->IsQuestItem())
                continue;
            float weight = FUN_0045c010(form);
            if (weight > 0.0f)
            {
                TESForm* armor = 0;
                // Fake match: retain this redundant null guard to preserve the pointer-select branch.
                if (form && form->type04 == 0x18)
                    armor = form;
                int count = e->countDelta;
                if (actor && armor && e->ItemChange_GetWorn(false)) {
                    // Fake match: keep the copy and nested count guard rather than flattening the condition.
                    float worn = weight;
                    if (count > 0) {
                        total += worn;
                        count = count - 1;
                    }
                }
                if (count > 0)
                    total += count * weight;
            }
        }
        totalWeight = total;
        if (actor)
            FUN_006f9560(&actor->avOwner9C, 0x2e, armorWeight, total - armorWeight, 0);
    }
    return totalWeight;
}
}
}   // namespace f3m_0047ee00

// @f3 0x00474c70 (community match, verified in this file)
// w52 candidate for FUN_00474c70 (0x00474c70, 544 bytes)
namespace w52 {

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

struct TagGuard {
    int saved;
    TagGuard(int tag)
    {
        saved = f3m_00464330::g_tls.allocTag;
        f3m_00464330::g_tls.allocTag = tag;
    }
    ~TagGuard() { f3m_00464330::g_tls.allocTag = saved; }
};

struct Pool {
    void* Allocate(unsigned int bytes);
    void Free(void* p);
};
extern Pool g_linkNodePool;

struct RefObj {
    virtual ~RefObj();
    virtual void Destroy();
    volatile long refs;
};

struct MapObj {
    virtual ~MapObj();
};

struct LinkNode {
    void* data;
    LinkNode* next;
};

struct RefPtr {
    RefObj* m_pObject;
    RefPtr(RefObj* p)
    {
        m_pObject = p;
        if (p)
            InterlockedIncrement(&p->refs);
    }
    ~RefPtr()
    {
        if (m_pObject && !InterlockedDecrement(&m_pObject->refs))
            m_pObject->Destroy();
    }
};

struct CopyInfo {
    MapObj* cloneMap;
    MapObj* processMap;
    int unk08;
    int unk0c;
    float x, y, z;
    void Init(unsigned int bucketCount);
    explicit CopyInfo(unsigned int bucketCount)
    {
        Init(bucketCount);
        x = y = z = 1.0f;
    }
    ~CopyInfo() { delete cloneMap; delete processMap; }
};

struct Holder {
    RefObj* object;
    LinkNode* chain;
};

struct Form;

struct Entry {
    Form* key;
    Holder holder;
    Entry();
    static void* operator new(unsigned int bytes) { return g_linkNodePool.Allocate(bytes); }
    static void operator delete(void* p);
};

struct Manager {
    Entry* item;
    LinkNode* next;
    void Set(void* const& entry);
    // Fake match: inline helper sequences pointer conversion before the key store.
    void Insert(void* const& value, Form* key, Entry* entry) { entry->key = key; Set(value); }

    void FUN_00474c70(Form* form, unsigned int count);
};

struct Form {
    RefObj* FUN_008257a0(CopyInfo& info);
};

}

// pdb: BSClonePools::MakeClones | BSClonePool.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apLoadedObject, aiCloneCount
void w52::Manager::FUN_00474c70(Form* form, unsigned int count)
{
    if (!form)
        return;
    TagGuard guard(0x31);

    Entry* found = 0;
    for (Manager* node = this; node != 0; node = (Manager*)node->next) {
        if (found)
            break;
        if (node->next == 0 && node->item == 0)
            break;
        Entry* item = node->item;
        if (item && item->key == form)
            found = item;
    }
    if (!found) {
        Entry* entry = new Entry;
        // Fake match: identical branches probe compiler copy propagation.
        if (entry) found = entry; else found = entry;
        Insert(found, form, entry);
    }
    if (count > 0) {
        unsigned int i = count;
        do {
        CopyInfo info(0x101);
        RefObj* clone = form->FUN_008257a0(info);
        RefPtr hold(clone);
        if (clone) {
            if (found->holder.object != 0) {
                LinkNode* link = (LinkNode*)g_linkNodePool.Allocate(8);
                if (link) {
                    link->data = found->holder.object;
                    if (link->data)
                        InterlockedIncrement(&((RefObj*)link->data)->refs);
                    link->next = 0;
                } else {
                    link = 0;
                }
                link->next = found->holder.chain;
                found->holder.chain = link;
                if (found->holder.object != clone) {
                    RefObj* old = found->holder.object;
                    if (old && !InterlockedDecrement(&old->refs))
                        old->Destroy();
                    found->holder.object = clone;
                    InterlockedIncrement(&clone->refs);
                }
            } else {
                found->holder.object = clone;
                InterlockedIncrement(&clone->refs);
            }
        }
        } while (--i);
    }
}

// @f3 0x00478bb0 (community match, verified in this file)
namespace ns_00478bb0 {
struct Object;
struct Children {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    Object** data;
    unsigned short capacity;
    unsigned short count;
};
struct Controller {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18;
    int kind;
};
struct Object {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual Children* children();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual int isLeaf();
    Controller* FUN_00826590(int);
};
struct Mgr478bb0 {
    void FUN_0078c030(Controller*);
};
extern Mgr478bb0 DAT_0107c0a0;

inline int valid(int kind)
{
    return kind >= 1 && kind <= 11;
}
}

// pdb: RecursivelyRemoveAllDecals | GlobalFunc.obj | fnv360_0721_beta, objrun, medium
// pdb params: apRoot
void __cdecl FUN_00478bb0(ns_00478bb0::Object* object)
{
    if (object) {
        if (object->isLeaf()) {
            ns_00478bb0::Controller* c = object->FUN_00826590(3);
            if (c) {
                ns_00478bb0::Controller* sel = ns_00478bb0::valid(c->kind) ? c : 0;
                if (sel) {
                    // The kind is read a second time here, and both outcomes
                    // register the controller.
                    if (c->kind == 10)
                        ns_00478bb0::DAT_0107c0a0.FUN_0078c030(sel);
                    else
                        ns_00478bb0::DAT_0107c0a0.FUN_0078c030(sel);
                }
            }
        } else {
            ns_00478bb0::Children* n = object->children();
            if (n) {
                for (unsigned i = 0; i < n->count; ++i)
                    FUN_00478bb0(n->data[i]);
            }
        }
    }
}

// @f3 0x00474f10 (community match, verified in this file)
namespace f3m_00474f10 {
struct Heap_4f10 {
    void FUN_0086ba60(void* p);
};
extern Heap_4f10 DAT_01090a78;

// List of reference-counted pointers held by one entry: item at +0, next at +4.
struct RefList_4f10 {
    void* item;
    RefList_4f10* next;
    void FUN_008fa360();                    // remove the head item
    bool IsEmpty() const { return !next && !item; }
};

struct Entry_4f10 {
    void* key;
    RefList_4f10 list;
    ~Entry_4f10();
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

// Simple list of entries: item at +0, next at +4.
struct EntryList_4f10 {
    Entry_4f10* item;
    EntryList_4f10* next;
    void FUN_006c8220();
    void FUN_00421610(Entry_4f10* const& value);
    void FUN_00474f10(void* key, unsigned int count);
    bool IsEmpty() const { return !next && !item; }
};

// Remove the node that holds value (the list template's Remove, defined in the same source file).
__declspec(noinline) void EntryList_4f10::FUN_00421610(Entry_4f10* const& value)
{
    if (!value)
        return;
    if (IsEmpty())
        return;
    EntryList_4f10* previous = this;
    EntryList_4f10* node = this;
    while (node->item != value) {
        previous = node;
        node = node->next;
        if (!node)
            return;
    }
    if (node == this) {
        EntryList_4f10* following = next;
        if (following) {
            next = following->next;
            item = following->item;
            following->next = 0;
            following->FUN_006c8220();
            DAT_01090a78.FUN_0086ba60(following);
        } else {
            item = 0;
        }
    } else {
        previous->next = node->next;
        node->next = 0;
        node->FUN_006c8220();
        DAT_01090a78.FUN_0086ba60(node);
    }
}

// Drop up to count references from the entry of key; an entry left empty is removed from the list and deleted.
// pdb: BSClonePools::KillClones | BSClonePool.obj | fnv360_0822_retail, call_gap, low
// pdb params: apLoadedObject, aiCloneCount
void EntryList_4f10::FUN_00474f10(void* key, unsigned int count)
{
    if (!key)
        return;
    Entry_4f10* found = 0;
    for (EntryList_4f10* node = this; node && !found && !node->IsEmpty(); node = node->next) {
        Entry_4f10* entry = node->item;
        if (entry && entry->key == key)
            found = entry;
    }
    if (!found)
        return;
    for (unsigned int i = 0; i < count; i++) {
        if (found->list.IsEmpty())
            break;
        found->list.FUN_008fa360();
    }
    if (found->list.IsEmpty()) {
        FUN_00421610(found);
        delete found;
    }
}
}

// @f3 0x0047f1e0 (community match, verified in this file)
extern const char DAT_00f4611c[], DAT_00f46b3c[];
namespace f3m_0047f1e0 {
namespace f3m_0047f1e0 {
struct Form {
    int unk00;
    unsigned char typeID;
    unsigned char GetType() { return typeID; }
};
struct Extra { bool ExtraDataList_GetWorn(bool flag); };
struct ExtraNode { Extra* item; ExtraNode* next; Extra* GetItem() { return item; } ExtraNode* GetNext() { return next; } };
struct Entry {
    ExtraNode* extras;
    int unk04;
    Form* form;
    bool IsWorn(bool flag) {
        ExtraNode* cur = extras;
        while (cur && cur->GetItem()) {
            Extra* pextra = cur->GetItem();
            if (pextra && pextra->ExtraDataList_GetWorn(flag))
                return true;
            cur = cur->GetNext();
        }
        return false;
    }
    Form* GetObject() { return form; }
};
struct Node { Entry* item; Node* next;
    bool IsEmpty() { return item == 0; }
    Entry* GetItem() { return item; }
    Node* GetNext() { return next; }
};
inline Form* FormOf(Entry* e) { return e->form; }
struct Proc {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual Entry* V148();
    virtual Entry* V14C();
};
struct Actor {
    void* vtbl;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    Proc* unk60;
};
float __cdecl FUN_0045c010(Form* form);
void* __cdecl FUN_00c0050a(void* object, int unused, const void* baseType, const void* targetType, int flags);
struct List {
    Node* head;
    int InventoryChanges_GetObjectCount(Form* form);
    float FUN_0047f1e0(Actor* actor);
};

// pdb: InventoryChanges::GetEquippedWeight | InventoryChanges.obj | fnv360_0822_debug, call_seq, medium
// pdb params: apOwner
float List::FUN_0047f1e0(Actor* actor)
{
    float total = 0.0f;
    float weight;
    Node* node = head;
    while (node && node->GetItem()) {
        Entry* item = node->GetItem();
        Form* form = item->GetObject();
        if (item->IsWorn(false) && form->GetType() != 0x29) {
            weight = FUN_0045c010(form);
            // The count is read in both arms of a test on the form type. The two arms compile to the
            // same code and are merged, and the test disappears, but the entry is used twice when the
            // registers are handed out, which is what puts the entry in edi and the form in ebp as in
            // the original. The tested condition is a guess: it leaves no instruction.
            int count;
            if (form->GetType() == 0x18)
                count = InventoryChanges_GetObjectCount(item->GetObject());
            else
                count = InventoryChanges_GetObjectCount(item->GetObject());
            if (form->GetType() == 0x18) {
                FUN_00c0050a(form, 0, DAT_00f4611c, DAT_00f46b3c, 0);
            } else if (form->GetType() == 0x28) {
                Proc* proc = actor->unk60;
                if (proc) {
                    Entry* a = proc->V148();
                    Entry* b = proc->V14C();
                    if (a && b && a->form == b->form)
                        count = 1;
                }
            }
            total += (float)count * weight;
        }
        node = node->GetNext();
    }
    return total;
}

}
}   // namespace f3m_0047f1e0

// @f3 0x00473360 (community match, verified in this file)
#include <string.h>
#include <windows.h>
namespace z473360 {
extern const char str_00dc01c4[];
extern const char str_00dc01b8[];
extern const char str_00dc0140[];
extern const char str_00dc00d0[];
extern const char str_00dc0080[];

struct S473_FixedString { const char* str; operator const char*() const { return str; } };
struct Object; struct Node; struct Skin; struct Form;
struct Heap { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
void* FUN_0089eb90(unsigned);
void FUN_0089ec10(void*);
extern const char* DAT_0106e804;
extern const char* DAT_00f4c388;
extern bool DAT_01073a60;
struct Vec { float x,y,z; };
extern Vec DAT_0108ec68;
struct Ptr {
 Object* p;
 Ptr():p(0){}
 Ptr(Object* q);
 ~Ptr();
 static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
 void FUN_008e9650(Object*);
};
struct Object {
 virtual void v00();
 virtual void v04();
 virtual void v08();
 virtual void v0c();
 virtual void v10();
 virtual void v14();
 virtual Object* v18();
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
 virtual void vb4();
 virtual void vb8();
 virtual void vbc();
 virtual void vc0();
 virtual void vc4();
 virtual void vc8();
 virtual void vcc();
 virtual void vd0();
 virtual void vd4();
 virtual void vd8();
 virtual void vdc(Object*, int);
 virtual void ve0();
 virtual void ve4(Object*);
 virtual void ve8(Object*);
 volatile long refs; S473_FixedString name; const S473_FixedString& GetName() const { return name; } Object* GetParent() const { return (Object*)unk18; }
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
 Object* unkB8; Skin* skin;
 void DecRef(){ if(!::InterlockedDecrement(&refs)) v04(); }
 Object* FUN_00824a50(const char*);
 void FUN_00824b10(const char*);
 void FUN_008248c0(const char*,Object*);
 void FUN_00825970(Ptr*);
 int FUN_00825a70();
 void FUN_00824c90(Object*);
 void FUN_00470b70(int);
};
Ptr::Ptr(Object* q):p(q) { if(p) ::InterlockedIncrement(&p->refs); }
Ptr::~Ptr() { if(p) p->DecRef(); }
struct OwnedPtr { Object* p; OwnedPtr():p(0){} __declspec(noinline) OwnedPtr(Object*); __declspec(noinline) void FUN_008e9650(Object*); __declspec(noinline) void FUN_00424aa0(); ~OwnedPtr(){ FUN_00424aa0(); } };
__declspec(noinline) OwnedPtr::OwnedPtr(Object* q):p(q) { if(p) ::InterlockedIncrement(&p->refs); }
__declspec(noinline) void OwnedPtr::FUN_00424aa0() { Object* obj=p; if(obj && !::InterlockedDecrement(&obj->refs)) obj->v04(); }
__declspec(noinline) void OwnedPtr::FUN_008e9650(Object* value) {
 if(p!=value) { Object* old=p; if(old && !::InterlockedDecrement(&old->refs)) old->v04(); p=value; if(value) ::InterlockedIncrement(&value->refs); }
}
struct FUN_0045c640 : OwnedPtr { FUN_0045c640(Object*); };
struct Bone { int unk00,unk04; S473_FixedString name; const S473_FixedString& GetName() const { return name; } };
struct BoneData { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40; unsigned count; };
struct Skin { int unk00,unk04; BoneData* data; Object* unk0C; Node* root; Bone** bones; void SetRoot(Node* r){ root=r; } unsigned GetCount() const { return data->count; } void SetBone(unsigned i,Object* b){ bones[i]=(Bone*)b; } };
struct ListNode { ListNode* prev; ListNode* next; Object* value; };
struct Extra { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30; ListNode* head; ListNode* tail; int count; };
struct ArrayStorage {
 virtual ~ArrayStorage() { if(data) delete[] data; }
 Ptr* data; unsigned short capacity,size,count,grow;
 ArrayStorage() { capacity=0; grow=1; size=0; count=0; data=0; }
};
}
struct BC21890ObjectArray : z473360::ArrayStorage {
 void FUN_004712a0(); void FUN_00470e10();
 __declspec(noinline) void FUN_005574c0(unsigned);
 __declspec(noinline) void FUN_00470f10(unsigned,z473360::Object* const*);
 void Add(z473360::Object* const* p) { unsigned i=size; if(i>=capacity) FUN_005574c0(i+grow); FUN_00470f10(i,p); }
};
__declspec(noinline) void BC21890ObjectArray::FUN_00470f10(unsigned i,z473360::Object* const* value) {
 static const z473360::Ptr empty;
 if(i>=size) { size=(unsigned short)(i+1); if(*value!=empty.p) ++count; }
 else if(*value!=empty.p) { if(data[i].p==empty.p) ++count; }
 else if(data[i].p!=empty.p) --count;
 if(data[i].p!=*value) {
  z473360::Object* old=data[i].p;
  if(old && !::InterlockedDecrement(&old->refs)) old->v04();
  data[i].p=*value;
  if(data[i].p) ::InterlockedIncrement(&data[i].p->refs);
 }
}
z473360::Ptr* FUN_006e3090(unsigned);
static inline void AssignPtr(z473360::Ptr& dst,z473360::Object* value) {
 if(dst.p!=value) {
  z473360::Object* old=dst.p;
  if(old && !::InterlockedDecrement(&old->refs)) old->v04();
  dst.p=value;
  if(value) ::InterlockedIncrement(&value->refs);
 }
}
__declspec(noinline) void BC21890ObjectArray::FUN_005574c0(unsigned n) {
 if(n==capacity) return;
 if(n<size) {
  for(unsigned short i=(unsigned short)n;i<size;++i) {
   if(data[i].p) { AssignPtr(data[i],0); --count; }
  }
  size=(unsigned short)n;
 }
 z473360::Ptr* old=data;
 capacity=(unsigned short)n;
 if(n>0) {
  data=FUN_006e3090((unsigned short)n);
  for(unsigned short i=0;i<size;++i) AssignPtr(data[i],old[i].p);
  for(unsigned short i=size;i<capacity;++i) AssignPtr(data[i],0);
 } else data=0;
 if(old) delete[] old;
}
namespace z473360 {
extern const char str_00dc01c4[];
extern const char str_00dc01b8[];
extern const char str_00dc0140[];
extern const char str_00dc00d0[];
extern const char str_00dc0080[];

typedef ::BC21890ObjectArray Array;
struct Node : Object {
 void Remove(Object* p) { ve8(p); }
};
struct FUN_0082ea60 {
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
 FUN_0082ea60(unsigned short);
 static void* operator new(unsigned n) { return FUN_0089eb90(n); }
 static void operator delete(void* p) { FUN_0089ec10(p); }
};
struct Map { int unk00,unk04,unk08,unk0C,unk10,unk14; Map(); ~Map(); };
struct Form { int unk00; unsigned char type; void FUN_00554d10(Map*); };
struct Ref { int unk00,unk04,unk08,unk0C,unk10,unk14,unk18; Form* form; const char* FUN_004e9a10(); };
struct Slot { int id; void* part; int unk08,unk0c; };
struct Part { int unk00,unk04,unk08,unk0c,unk10; unsigned char flags; };
struct Owner { Node* root; int unk04,unk08,unk0c; Object* unk10;
 int unk014;
 int unk018;
 int unk01c;
 int unk020;
 int unk024;
 int unk028;
 int unk02c;
 int unk030;
 int unk034;
 int unk038;
 int unk03c;
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
 Ref* ref;
 void* FUN_00471b70(int);
 void FUN_004730a0(Object*,int);
 Object* FUN_00473360(Node*,Node*,int,bool,bool,void*);
};
Object* FUN_00aab440(Node*,const S473_FixedString*,int);
void FUN_00887da0(const char*,...);
struct Processor { void FUN_00596070(Map*,Object*,int); };
// pdb: BipedAnim::AttachSkinnedObject | BipedAnim.obj | fnv360_0822_retail, ustr, medium
// pdb params: apNode, apParentNode, aeBipedObject, abFirstPerson, abPipboy, apfgModel
Object* Owner::FUN_00473360(Node* model,Node* dest,int slot,bool upper,bool off,void* processor)
{
 Object* result=0; Node* destination=dest; Ptr retained;
 Array* children=(Array*)((char*)model+0x9c);
 children->FUN_004712a0(); children->FUN_00470e10();
 void* process=processor;
 if(!process) {
  Part* part=(Part*)((Slot*)((char*)this+0x2c))[slot].part;
  if(part && (part->flags&1)) process=FUN_00471b70(slot);
 }
 *(Vec*)((char*)model+0x58)=DAT_0108ec68;
 Object* second=0;
 if(destination && ((Array*)((char*)model+0x9c))->size>=2 && (second=((Array*)((char*)model+0x9c))->data[1].p) && second->v18()) {
  destination=(Node*)new FUN_0082ea60(0); dest->vdc(destination,1); result=destination;
 }
 Extra* extra=(Extra*)model->FUN_00824a50(DAT_0106e804);
 if(extra) {
  Object* target=unk10;
  if(target) target->FUN_00824b10(DAT_0106e804);
  target->FUN_008248c0(DAT_0106e804,(Object*)extra);
  for(unsigned i=0;i<((Array*)((char*)model+0x9c))->size;i++) {
   Object* child=((Array*)((char*)model+0x9c))->data[i].p;
   if(child->v18() && child->v18()->skin) {
    Object* value=((Array*)((char*)model+0x9c))->data[i].p;
    ListNode* n=(ListNode*)DAT_01090a78.FUN_0086b930(12);
    n->value=value; n->next=0; n->prev=extra->head;
    if(extra->head) extra->head->next=n; else extra->tail=n;
    ++extra->count; extra->head=n;
   }
  }
 }
 Array removed;
 for(unsigned i=0;i<((Array*)((char*)model+0x9c))->size;i++) {
  Object* child=((Array*)((char*)model+0x9c))->data[i].p;
  if(child && !child->v18()) {
   { Ptr temp(child); removed.Add(&temp.p); } model->ve8(child); continue;
  }
  if(upper && child->name && !_strnicmp(child->name,DAT_00f4c388,strlen(DAT_00f4c388))) {
   { Ptr temp(child); removed.Add(&temp.p); } model->ve8(child); continue;
  }
  if(off) {
   if(child->name && !_stricmp(child->name,str_00dc01c4)) { { Ptr temp(child); removed.Add(&temp.p); } model->ve8(child); continue; }
  } else if(child->name && !_stricmp(child->name,str_00dc01b8)) { { Ptr temp(child); removed.Add(&temp.p); } model->ve8(child); continue; }
  if(child->unkB8 && child->skin && process && ref && ref->form && ref->form->type==0x2a) {
   Form* form=ref->form; Map maps[4]; OwnedPtr hold;
   child->unkB8->FUN_00825970(&retained); hold.FUN_008e9650(retained.p); child->ve4(hold.p);
   if(child->skin && child->skin->unk0C) {
    Object* src=child->skin->unk0C; src->FUN_00825970(&retained); FUN_0045c640 p(retained.p);
    child->FUN_00470b70(((Object*)child->skin)->FUN_00825a70());
    ((Object*)child->skin)->FUN_00824c90(p.p);
   }
   form->FUN_00554d10(maps);
   if(DAT_01073a60) ((Processor*)process)->FUN_00596070(maps,child,0);
  }
  FUN_004730a0(child,0);
  Skin* skin=child->skin;
  if(skin) {
   if(!result) result=child;
   BoneData* data=skin->data; unsigned n=data->count; Bone** bones=skin->bones;
   for(unsigned j=0;j<n;j++) {
    if(!bones[j]->name.str) { FUN_00887da0(str_00dc0140,j,model->GetParent() ? (const char*)model->GetParent()->GetName() : "NULL",(const char*)model->GetName()); continue; }
    Node* searchRoot=root; Object* bone=FUN_00aab440(searchRoot,&bones[j]->name,1);
    if(bone) { skin->bones[j]=(Bone*)bone; continue; }
    if(!_strnicmp(child->name,bones[j]->name.str,strlen(bones[j]->name))) { FUN_00887da0(str_00dc00d0,(const char*)bones[j]->GetName(),model->GetParent() ? (const char*)model->GetParent()->GetName() : "NULL",(const char*)model->GetName()); continue; }
    FUN_00887da0(str_00dc0080,(const char*)bones[j]->GetName(),(const char*)model->GetName(),ref->FUN_004e9a10(),root->GetParent() ? (const char*)root->GetParent()->GetName() : "NULL");
   }
   if(destination) { skin->root=dest; destination->vdc(child,1); }
  }
 }
/*@END@*/ children->FUN_004712a0();
 while(children->size>0) {
  bool live=children->data[children->size-1].p != 0;
  if(live) break;
  --children->size;
 }
 return result;
}
}

// @f3 0x004637f0 (community match, verified in this file)
extern unsigned int DAT_00dbe044;
namespace f3m_004637f0 {
class AnimState;
class ActorLoad;
class LoadStream;
class TESForm { public: virtual void formSlot(); };
class TESIdleForm : public TESForm {};
struct VectorLoad { float x,y,z; };
class NiControllerSequence {
public:
    virtual void slot000();
    virtual void DeleteThis();
    virtual void slot008();
    virtual void slot00C();
    virtual NiControllerSequence* Get(int index);
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void Stop(float blend, int flags);
    volatile long references;
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
    float frequency;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int active;
    float clock;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    NiControllerSequence* child;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    NiControllerSequence();
    void FUN_00424390();
    void NiControllerManager_DeactivateAll(float value);
    void FUN_008aecd0(int,int,float,float,int,int);
    void FUN_0049cd70(LoadStream*,float);
};
class BSAnimGroupSequence : public NiControllerSequence {
public:
    BSAnimGroupSequence() { *(void**)this = &DAT_00dbe044; unk74 = 0; }
    ~BSAnimGroupSequence();
};
struct PendingNode {
    NiControllerSequence* data;
    PendingNode* next;
    void FUN_006c8220();
};
class LoadHeap { public: void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };

struct IdleEntry { TESIdleForm* form; unsigned int value; };
struct IdleNode {
    IdleEntry* data; IdleNode* next;
    IdleNode(IdleEntry* old) : data(old),next(0) {}
    static void* operator new(unsigned n) throw() { return ((LoadHeap*)&f3m_00477d30::DAT_01090a78)->FUN_0086b930(n); }
};
class LookupLoad {
public:
    struct Item { Item* next; unsigned short key; NiControllerSequence* value; };
    virtual void v00();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short a, unsigned short b);
    unsigned int hashSize;
    Item** table;
    unsigned int count;
    __declspec(noinline) bool FUN_0045c6e0(unsigned short key, NiControllerSequence*& value)
    {
        for (Item* item = table[KeyToHashIndex(key)]; item; item = item->next) {
            if (IsKeysEqual(item->key, key)) {
                value = item->value;
                return true;
            }
        }
        return false;
    }
};
class BlendLoad { public: void FUN_0044db80(NiControllerSequence*,float); void NiControllerManager_DeactivateAll(float); };
namespace IdleTaskLoad {
class FUN_00460ba0 {
public:
    virtual void slot0();
    virtual void DeleteThis();
    volatile long references;
    unsigned int state;
    unsigned int unk0C;
    NiControllerSequence* pending;
    unsigned int unk14;
    NiControllerSequence* sequence;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    FUN_00460ba0(TESIdleForm*,int,int,ActorLoad*,int,int);
    static void* operator new(unsigned n) { return ::FUN_0089eb90(n); }
    static void operator delete(void* p) { ::FUN_0089ec10(p); }
};
}
class ProcessLoad {
public:
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09C();
    virtual void slot0A0();
    virtual void slot0A4();
    virtual void slot0A8();
    virtual void slot0AC();
    virtual void slot0B0();
    virtual void slot0B4();
    virtual void slot0B8();
    virtual void slot0BC();
    virtual void slot0C0();
    virtual void slot0C4();
    virtual void slot0C8();
    virtual void slot0CC();
    virtual void slot0D0();
    virtual void slot0D4();
    virtual void slot0D8();
    virtual void slot0DC();
    virtual void slot0E0();
    virtual void slot0E4();
    virtual void slot0E8();
    virtual void slot0EC();
    virtual void slot0F0();
    virtual void slot0F4();
    virtual void slot0F8();
    virtual void slot0FC();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10C();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11C();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12C();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13C();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14C();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15C();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16C();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17C();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18C();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19C();
    virtual void slot1A0();
    virtual void slot1A4();
    virtual void slot1A8();
    virtual void slot1AC();
    virtual void slot1B0();
    virtual void slot1B4();
    virtual void slot1B8();
    virtual void slot1BC();
    virtual void slot1C0();
    virtual void slot1C4();
    virtual void SetState(bool,void*,AnimState*,ActorLoad*);
    virtual void slot1CC();
    virtual void slot1D0();
    virtual void FUN_0049dd70(ActorLoad*);
    virtual void slot1D8();
    virtual void slot1DC();
    virtual void slot1E0();
    virtual void slot1E4();
    virtual void slot1E8();
    virtual void slot1EC();
    virtual void slot1F0();
    virtual void slot1F4();
    virtual void slot1F8();
    virtual void slot1FC();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20C();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21C();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22C();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23C();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24C();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25C();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26C();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27C();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28C();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29C();
    virtual void slot2A0();
    virtual void slot2A4();
    virtual void slot2A8();
    virtual void slot2AC();
    virtual void slot2B0();
    virtual void slot2B4();
    virtual void slot2B8();
    virtual void slot2BC();
    virtual void slot2C0();
    virtual void slot2C4();
    virtual void slot2C8();
    virtual void slot2CC();
    virtual void slot2D0();
    virtual void slot2D4();
    virtual void slot2D8();
    virtual void slot2DC();
    virtual void slot2E0();
    virtual void slot2E4();
    virtual void slot2E8();
    virtual void slot2EC();
    virtual void slot2F0();
    virtual void slot2F4();
    virtual void slot2F8();
    virtual void slot2FC();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30C();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31C();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32C();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33C();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34C();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35C();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36C();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37C();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38C();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39C();
    virtual void slot3A0();
    virtual void slot3A4();
    virtual void slot3A8();
    virtual void slot3AC();
    virtual void slot3B0();
    virtual void slot3B4();
    virtual void slot3B8();
    virtual void slot3BC();
    virtual void slot3C0();
    virtual void slot3C4();
    virtual void slot3C8();
    virtual void slot3CC();
    virtual void slot3D0();
    virtual void slot3D4();
    virtual void slot3D8();
    virtual void slot3DC();
    virtual void slot3E0();
    virtual void slot3E4();
    virtual void Select(int,NiControllerSequence*);
    virtual void slot3EC();
    virtual void slot3F0();
    virtual void slot3F4();
    virtual void slot3F8();
    virtual void slot3FC();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40C();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41C();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42C();
    virtual void slot430();
    virtual void slot434();
    virtual void slot438();
    virtual void slot43C();
    virtual void slot440();
    virtual void slot444();
    virtual void slot448();
    virtual void slot44C();
    virtual bool GetState();
    virtual void slot454();
    virtual void slot458();
    virtual void slot45C();
    virtual void slot460();
    virtual void slot464();
    virtual void slot468();
    virtual void slot46C();
    virtual void slot470();
    virtual void slot474();
    virtual void slot478();
    virtual void slot47C();
    virtual void slot480();
    virtual void slot484();
    virtual void slot488();
    virtual void slot48C();
    virtual void slot490();
    virtual void slot494();
    virtual void slot498();
    virtual void slot49C();
    virtual void slot4A0();
    virtual void slot4A4();
    virtual void slot4A8();
    virtual void slot4AC();
    virtual void slot4B0();
    virtual void slot4B4();
    virtual void slot4B8();
    virtual void slot4BC();
    virtual void slot4C0();
    virtual void slot4C4();
    virtual void slot4C8();
    virtual void slot4CC();
    virtual void slot4D0();
    virtual void Attach(ActorLoad*,AnimState*);
    virtual void slot4D8();
    virtual void slot4DC();
    virtual void slot4E0();
    virtual void slot4E4();
    virtual void slot4E8();
    virtual void slot4EC();
    virtual void slot4F0();
    virtual void slot4F4();
    virtual void slot4F8();
    virtual void slot4FC();
    virtual void slot500();
    virtual void slot504();
    virtual void slot508();
    virtual void slot50C();
    virtual void slot510();
    virtual void slot514();
    virtual void slot518();
    virtual void slot51C();
    virtual void slot520();
    virtual void slot524();
    virtual void slot528();
    virtual void slot52C();
    virtual void slot530();
    virtual void slot534();
    virtual void slot538();
    virtual void slot53C();
    virtual void slot540();
    virtual void slot544();
    virtual void slot548();
    virtual void slot54C();
    virtual void slot550();
    virtual void slot554();
    virtual void slot558();
    virtual void slot55C();
    virtual void slot560();
    virtual void slot564();
    virtual void slot568();
    virtual void slot56C();
    virtual void slot570();
    virtual void slot574();
    virtual void slot578();
    virtual void slot57C();
    virtual void slot580();
    virtual void slot584();
    virtual void slot588();
    virtual void slot58C();
    virtual void slot590();
    virtual void slot594();
    virtual void slot598();
    virtual void slot59C();
    virtual void slot5A0();
    virtual void slot5A4();
    virtual void slot5A8();
    virtual void slot5AC();
    virtual void slot5B0();
    virtual void slot5B4();
    virtual void slot5B8();
    virtual void slot5BC();
    virtual void slot5C0();
    virtual void slot5C4();
    virtual void slot5C8();
    virtual void slot5CC();
    virtual void slot5D0();
    virtual void slot5D4();
    virtual void slot5D8();
    virtual void slot5DC();
    virtual void slot5E0();
    virtual void slot5E4();
    virtual void slot5E8();
    virtual void slot5EC();
    virtual void slot5F0();
    virtual void slot5F4();
    virtual void slot5F8();
    virtual void slot5FC();
    virtual void slot600();
    virtual void slot604();
    virtual void slot608();
    virtual void slot60C();
    virtual void slot610();
    virtual void FUN_0045ce90();
};
class ActorLoad {
public:
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04C();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05C();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06C();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07C();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08C();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09C();
    virtual void slot0A0();
    virtual void slot0A4();
    virtual void slot0A8();
    virtual void slot0AC();
    virtual void slot0B0();
    virtual void slot0B4();
    virtual void slot0B8();
    virtual void slot0BC();
    virtual void slot0C0();
    virtual void slot0C4();
    virtual void slot0C8();
    virtual void slot0CC();
    virtual void slot0D0();
    virtual void slot0D4();
    virtual void slot0D8();
    virtual void slot0DC();
    virtual void slot0E0();
    virtual void slot0E4();
    virtual void slot0E8();
    virtual void slot0EC();
    virtual void slot0F0();
    virtual void slot0F4();
    virtual void slot0F8();
    virtual void slot0FC();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10C();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11C();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12C();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13C();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14C();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15C();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16C();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17C();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18C();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19C();
    virtual void slot1A0();
    virtual void slot1A4();
    virtual void slot1A8();
    virtual void slot1AC();
    virtual void slot1B0();
    virtual void slot1B4();
    virtual void slot1B8();
    virtual void slot1BC();
    virtual void slot1C0();
    virtual void slot1C4();
    virtual void slot1C8();
    virtual void slot1CC();
    virtual void slot1D0();
    virtual void slot1D4();
    virtual void slot1D8();
    virtual void slot1DC();
    virtual void slot1E0();
    virtual void slot1E4();
    virtual void* GetAnimation();
    virtual void slot1EC();
    virtual void slot1F0();
    virtual void slot1F4();
    virtual void slot1F8();
    virtual void slot1FC();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20C();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21C();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual bool IsSpecial(int);
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23C();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24C();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25C();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26C();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27C();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28C();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29C();
    virtual void slot2A0();
    virtual void slot2A4();
    virtual void slot2A8();
    virtual void slot2AC();
    virtual void slot2B0();
    virtual void slot2B4();
    virtual void slot2B8();
    virtual void slot2BC();
    virtual void slot2C0();
    virtual void slot2C4();
    virtual void slot2C8();
    virtual void slot2CC();
    virtual void slot2D0();
    virtual void slot2D4();
    virtual void slot2D8();
    virtual void slot2DC();
    virtual void slot2E0();
    virtual void slot2E4();
    virtual bool IsOther();
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
    ProcessLoad* process;
    AnimState* FUN_0076cce0(int);
    void* FUN_0076cd20(int);
};
namespace PlayerLoad { extern ActorLoad* DAT_0107a104; }
class LoadStream {
public:
    virtual void s0(); virtual void s4(); virtual void s8(); virtual ActorLoad* GetActor();
    unsigned int unk04,unk08,position;
    void FUN_006e0750(void*,unsigned);
    unsigned int BGSLoadGameBuffer_LoadVariableSizedValue();
    unsigned int FUN_006e0670();
    bool FUN_006e06d0(unsigned int*);
};
class NodeLoad { public:
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
    VectorLoad position;
};
struct FlagLoad { unsigned int unk00,unk04,unk08; unsigned short flags;
    __forceinline bool Has20() const { return (flags&0x20)==0x20; }
    __forceinline bool Has40() const { return ((flags>>6)&1)!=0; }
};
extern FlagLoad* __cdecl FUN_008f1d20(void*);
extern void __cdecl FUN_008f1d80(bool,void*);
extern TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
extern int __cdecl FUN_006191f0();

class ModelLoad { public: void FUN_0049de40(float); void FUN_0049dd70(float,NodeLoad*); };
class AnimState {
public:
    unsigned int unk00;
    unsigned int unk04;
    ModelLoad* model;
    NodeLoad* node;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float posX;
    float posY;
    float posZ;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned short ids[8];
    unsigned int channelData[8];
    float channelTimes[8];
    unsigned short otherIds[8];
    float otherTimes[8];
    unsigned char enabled;
    float time;
    unsigned int unkD4;
    BlendLoad* blender;
    LookupLoad* lookup;
    NiControllerSequence* sequences[8];
    unsigned int unk100;
    NiControllerSequence* pending;
    PendingNode* pendingNext;
    unsigned int unk10C,unk110;
    bool initialized;
    unsigned char unk115;
    unsigned short unk116;
    IdleTaskLoad::FUN_00460ba0* task;
    unsigned int unk11C,unk120,unk124;
    IdleEntry* idleHead;
    IdleNode* idleNext;
    void FUN_00461a70(NiControllerSequence*,int);
    void Animation_ClearGroup(int,float);
    void FUN_0045f220(float,VectorLoad*,int);
    void FUN_0045ce90();
    void FUN_0045dca0();
    void FUN_0045fba0(unsigned int,unsigned short,unsigned int,float,unsigned char);
    void FUN_00463650();
    __forceinline ModelLoad* GetModel() const { return model; }
    __forceinline void StopAnim(unsigned char i)
    {
        if (blender && sequences[i] && sequences[i]->active) {
            if (sequences[i]->child) blender->FUN_0044db80(sequences[i]->child, 0.0f);
            sequences[i]->Stop(0.0f, 0);
        }
        sequences[i] = 0;
        ids[i] = 0xff;
        otherIds[i] = 0xff;
        channelData[i] = -1;
    }
    __forceinline void StopAnim2(unsigned char i)
    {
        if (blender && sequences[i] && sequences[i]->active) {
            NiControllerSequence* child = sequences[i]->child;
            if (child) child->Stop(0.0f, 0);
            sequences[i]->Stop(0.0f, 0);
        }
        sequences[i] = 0;
        ids[i] = 0xff;
        otherIds[i] = 0xff;
        channelData[i] = -1;
    }
    void Animation_LoadGame(LoadStream* stream);
};
static __forceinline bool QueryModelFlag(ModelLoad* model)
{
    FlagLoad* flags=FUN_008f1d20(model);
    return flags && flags->Has20() && !flags->Has40();
}
// pdb: Animation::LoadGame | Animation.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void AnimState::Animation_LoadGame(LoadStream* stream)
{
    if (!GetModel()) return;
    ActorLoad* actor = stream->GetActor();
    while (pendingNext || pending) {
        NiControllerSequence* p = pending;
        FUN_00461a70(p,0);
        p->FUN_00424390();
        PendingNode* n = pendingNext;
        if(n) {
            pendingNext=n->next;
            pending=n->data;
            n->next=0;
            n->FUN_006c8220();
            ((LoadHeap*)&f3m_00477d30::DAT_01090a78)->FUN_0086ba60(n);
        } else pending=0;
    }
    actor->process->Attach(actor,this);
    if(actor->IsSpecial(0) || actor->IsOther()) {
        if(FUN_006191f0()!=1) {
            Animation_ClearGroup(7,0.0f);
            if(!initialized) Animation_ClearGroup(0,0.0f);
        }
        Animation_ClearGroup(1,0.0f);
        if(FUN_006191f0()!=1) Animation_ClearGroup(2,0.0f);
        Animation_ClearGroup(3,0.0f); Animation_ClearGroup(5,0.0f); Animation_ClearGroup(6,0.0f);
        StopAnim(4);
        NiControllerSequence* p;
        if(lookup->FUN_0045c6e0(0xa5,p) && p->Get(-1)) {
            sequences[1]=p->Get(-1);
            sequences[1]->FUN_008aecd0(0,0,1.0f,0.0f,0,0);
        }
        ids[1]=0xa5; time=0.0f;
    }
    bool state=actor->process->GetState();
    initialized=true;
    if(actor==PlayerLoad::DAT_0107a104) {
        if(this==PlayerLoad::DAT_0107a104->FUN_0076cce0(1)) {
            ProcessLoad* process=actor->process;
            process->SetState(state,PlayerLoad::DAT_0107a104->FUN_0076cd20(1),this,PlayerLoad::DAT_0107a104);
        } else {
            ProcessLoad* process=PlayerLoad::DAT_0107a104->process;
            process->SetState(state,PlayerLoad::DAT_0107a104->FUN_0076cd20(0),this,PlayerLoad::DAT_0107a104);
        }
    } else {
        ProcessLoad* process=actor->process;
        process->SetState(state,actor->GetAnimation(),this,actor);
    }
    actor->process->FUN_0049dd70(actor); actor->process->FUN_0045ce90(); actor->process->Select(-1,0);
    int i = 0;
    do {
        if (sequences[i]) {
            float a = sequences[i]->clock;
            float b = sequences[i]->frequency;
            sequences[i]->clock = b + a;
        }
    } while (++i < 8);
    FUN_0045f220(time,(VectorLoad*)&posX,1);
    GetModel()->FUN_0049de40(time);
FlagLoad* flags = FUN_008f1d20(GetModel());
    bool oldFlag = flags ? (flags->Has20() && !flags->Has40()) : false;
    if(oldFlag) FUN_008f1d80(false,GetModel());
    FUN_0045ce90();
    if(oldFlag) FUN_008f1d80(oldFlag,GetModel());
    if(FUN_006191f0()!=1) { Animation_ClearGroup(7,0.0f); if(!initialized) Animation_ClearGroup(0,0.0f); }
    Animation_ClearGroup(1,0.0f);
    if(FUN_006191f0()!=1) Animation_ClearGroup(2,0.0f);
    Animation_ClearGroup(3,0.0f); Animation_ClearGroup(5,0.0f); Animation_ClearGroup(6,0.0f);
    StopAnim2(4);
    FUN_0045dca0();
    if(blender) blender->NiControllerManager_DeactivateAll(0.0f);
    stream->FUN_006e0750(&unk10C,4); stream->FUN_006e0750(&unk110,4); stream->FUN_006e0750(&unk10,12);
    stream->FUN_006e0750(&unk48,4); stream->FUN_006e0750(&enabled,1); stream->FUN_006e0750(&unkD4,4); stream->FUN_006e0750(&unk116,2);
    unsigned count=stream->BGSLoadGameBuffer_LoadVariableSizedValue();
    for(unsigned i=0;i<count;++i) {
        IdleEntry* e=(IdleEntry*)((LoadHeap*)&f3m_00477d30::DAT_01090a78)->FUN_0086b930(8);
        e->form=dynamic_cast<TESIdleForm*>(TESForm_GetFormByNumericID(stream->FUN_006e0670()));
        stream->FUN_006e0750(&e->value,4);
        if(idleHead) {
            IdleNode* n=new IdleNode(idleHead);
            n->next=idleNext; idleNext=n;
        }
        idleHead=e;
    }
    TESIdleForm* idle=0;
    if(stream->FUN_006e06d0((unsigned int*)&idle)) stream->position+=stream->BGSLoadGameBuffer_LoadVariableSizedValue();
    else if(idle) {
        idle=dynamic_cast<TESIdleForm*>(TESForm_GetFormByNumericID((unsigned int)idle));
        if(!idle) stream->position+=stream->BGSLoadGameBuffer_LoadVariableSizedValue();
        else {
            stream->BGSLoadGameBuffer_LoadVariableSizedValue();
            IdleTaskLoad::FUN_00460ba0* fresh=new IdleTaskLoad::FUN_00460ba0(idle,7,1,actor,1,0);
            IdleTaskLoad::FUN_00460ba0* old=task;
            if(old!=fresh) {
                if(old && !::InterlockedDecrement(&old->references)) old->DeleteThis();
                task=fresh;
                if(fresh) InterlockedIncrement(&fresh->references);
            }
            IdleTaskLoad::FUN_00460ba0* t=task;
            stream->FUN_006e0750(&t->state,4); stream->FUN_006e0750(&t->unk0C,4); stream->FUN_006e0750(&t->unk14,4);
            if(t->state==0) t->state=1;
            if(t->state==2 && t->pending) FUN_00461a70(t->pending,0);
        }
    }
    signed char mask=0;
    stream->FUN_006e0750(&mask,1);
    for(unsigned index=0;index<8;++index) {
        if(mask & (1<<index)) {
            stream->FUN_006e0750(&ids[index],2); stream->FUN_006e0750(&channelData[index],4);
            stream->FUN_006e0750(&otherIds[index],2); stream->FUN_006e0750(&channelTimes[index],4); stream->FUN_006e0750(&otherTimes[index],4);
            sequences[index]=0;
            unsigned char tag=0xff;
            stream->FUN_006e0750(&tag,1);
            if(tag!=0xfe) {
                initialized=true;
                FUN_0045fba0(index,ids[index],channelData[index],time,tag);
                if(sequences[index]) sequences[index]->FUN_0049cd70(stream,time);
                else {
                    BSAnimGroupSequence temporary;
                    temporary.FUN_0049cd70(stream,time);
                    Animation_ClearGroup(index,0.0f);
                }
            }
        }
    }
    stream->FUN_006e0750(&initialized,1);
    int sequenceId=-1;
    signed char sequenceIndex=-1;
    stream->FUN_006e0750(&sequenceId,2); stream->FUN_006e0750(&sequenceIndex,1);
    if(sequenceIndex!=-1 && sequences[sequenceIndex]) actor->process->Select((short)sequenceId,sequences[sequenceIndex]);
    signed char taskIndex=-1;
    stream->FUN_006e0750(&taskIndex,1);
    IdleTaskLoad::FUN_00460ba0* t=task;
    if(t) {
        if(taskIndex!=-1) {
            NiControllerSequence* old=t->sequence;
            NiControllerSequence* fresh=sequences[taskIndex];
            if(old!=fresh) {
                if(old && !::InterlockedDecrement(&old->references)) old->DeleteThis();
                t->sequence=fresh;
                if(fresh) InterlockedIncrement(&fresh->references);
            }
        }
        if(task->state==1) { initialized=true; FUN_00463650(); }
    }
    float savedTime=time;
    if(node) node->position=*(VectorLoad*)&posX;
    model->FUN_0049dd70(savedTime,node);
    if(node) {
        VectorLoad* position=(VectorLoad*)&posX;
        if(position) *position=node->position;
        node->position=*(VectorLoad*)&::DAT_0108ec68;
    }
    GetModel()->FUN_0049de40(time);
}

}   // namespace f3m_004637f0

// @f3 0x0046a080 (community match, verified in this file)
#include <string.h>
#include <windows.h>
namespace fnv_004a2070 {
void* __cdecl FUN_0089eb90(unsigned);void __cdecl FUN_0089ec10(void*);
extern const char DAT_00dbea00[],DAT_00dbe9d4[],DAT_00dbe9b4[],DAT_00dbe950[];
struct DObj;
struct DArg;
struct FUN_0045c640;
struct DProp;
struct DArray;
struct CStringProvider;
struct DVec
{
    float x, y, z;
    DVec& Set(float a,float b,float c) {x=a;y=b;z=c;return *this;}
    DVec FUN_004a0bd0() const { DVec v; v.Set(-x,-y,-z); return v; }
};
struct DUpdate
{
    float time;
    bool updateControllers, multithreaded, flagA, flagB, flagC;
    DUpdate(float t,bool a,bool b):time(t),updateControllers(a),multithreaded(b),flagA(false),flagB(false),flagC(false) {}
};
struct DObjectFields {
    unsigned unk0;
    long refs;
    const char* name;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    DArray* parent;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned flags;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    void* skin;
    void* prop;
};
struct DObj
{
    virtual void Unk0();
    virtual void DeleteThis();
    virtual void Unk2();
    virtual DObj* IsSceneNode();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual DObj* IsGeometry();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Virtual8c();
    virtual void Unk24();
    virtual void Unk25();
    virtual DObj* Virtual98(bool);
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2a();
    virtual void Unk2b();
    virtual void Unk2c();
    virtual void Unk2d();
    virtual void Unk2e();
    virtual void Unk2f();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Virtualdc(DObj*, bool);
    CStringProvider* FUN_00413f40(){return (CStringProvider*)&((DObjectFields*)this)->name;}
    bool FUN_00456610(){return (((DObjectFields*)this)->flags&1)!=0;}
    DProp* FUN_00826590(unsigned);
    void* FUN_004030b0(){return ((DObjectFields*)this)->prop;}
    void* FUN_0043fad0(){return ((DObjectFields*)this)->skin;}
    DArray* FUN_009611e0(){return ((DObjectFields*)this)->parent;}
    unsigned FUN_00453470(){return *(unsigned short*)((char*)this+0xa8);}
    int FUN_0059e300(){return (int)((DObjectFields*)this)->unk5c;}
    void FUN_00886600(DObj*);
    void FUN_008245d0(CStringProvider*);
    void FUN_008264c0(DUpdate&);
};
struct CStringProvider
{
    const char* handle;
    const char* FUN_0043b1b0(){return handle;}
};
struct FUN_0045c640
{
    DObj* ptr;
    FUN_0045c640():ptr(0){}
    FUN_0045c640(DObj* p):ptr(p){if(p) ::InterlockedIncrement(&((DObjectFields*)p)->refs);}
    ~FUN_0045c640(){if(ptr){DObj* old=ptr;if(::InterlockedDecrement(&((DObjectFields*)old)->refs)==0)old->DeleteThis();}}
    DObj* FUN_00559450(){return ptr;}
    FUN_0045c640& FUN_008e9650(DObj*);
};
struct DArray : DObj {
unsigned unk4;
unsigned unk8;
unsigned unkc;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
unsigned unk60;
unsigned unk64;
unsigned unk68;
unsigned unk6c;
unsigned unk70;
unsigned unk74;
unsigned unk78;
unsigned unk7c;
unsigned unk80;
unsigned unk84;
unsigned unk88;
unsigned unk8c;
unsigned unk90;
unsigned unk94;
unsigned unk98;
unsigned unk9c;
DObj** entries;unsigned short capacity,size;
unsigned FUN_0043b480(){return size;}
DObj* FUN_0043b4a0(unsigned i){return entries[i];}
};
struct DProp
{
};
struct DList
{
    void FUN_008f2610(const FUN_0045c640&);
};
struct FUN_0049c870 : DArray
{
    unsigned short activeCount, unkAA;
    DList* effects;
    unsigned unkb0;
    static void* operator new(unsigned n){return FUN_0089eb90(n);}
    static void operator delete(void* p){FUN_0089ec10(p);}
    FUN_0049c870(DArray*, bool);
};
struct DOneArg
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Virtualdc(DObj*);
    void FUN_008245d0(CStringProvider*);
};
struct FUN_0082ea60 : DOneArg
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    static void* operator new(unsigned n){return FUN_0089eb90(n);}
    static void operator delete(void* p){FUN_0089ec10(p);}
    FUN_0082ea60(unsigned);
};
struct FUN_005b05f0 : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    static void* operator new(unsigned n){return FUN_0089eb90(n);}
    static void operator delete(void* p){FUN_0089ec10(p);}
    FUN_005b05f0(unsigned, float, DArg*, DObj*, DVec, DVec, float, float, unsigned);
};
struct DParentInterface
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Get(unsigned, FUN_0045c640&);
};
struct DParent
{
    unsigned unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    DParentInterface interface30;
};
struct DArg
{
    DVec origin, normal;
    unsigned unk18, unk1c, unk20, unk24;
    DObj* object;
    DArray* children;
    DParent* parent;
    int tries;
    float scale;
    unsigned unk3c, unk40;
    float rotation;
    unsigned flags, unk4c;
    DOneArg* skin;
    unsigned unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
struct DSetting
{
    unsigned tag; float value;
    float* FUN_00403e20(){return &value;}
    int* FUN_004241e0();
    bool* FUN_00408d60();
    float FUN_00432b20();
};
extern DSetting DAT_0106df58, DAT_0106df48, DAT_0106df7c;
struct BoolSetting { unsigned tag; bool flag; bool* GetLifeStateControlFlag(){return FUN_00405070();} bool* FUN_00405070();};extern BoolSetting DAT_0106dfdc;
extern int DAT_0106def8, DAT_0106df00;
extern unsigned DAT_0108f20c, DAT_0107000c;
struct DManager
{
    void FUN_00793f90(DObj*);
};
extern DManager DAT_0107c0a0;
bool FUN_00424d20(const void*, DObj*);
bool FUN_004343e0(const void*, DObj*);
void FUN_00887da0(const char*, ...);
extern CStringProvider* DAT_0106e7f0;
int FUN_00468ef0(DProp*);
__forceinline bool IsExactKind(const void* rtti, DObj* p)
{
    return p && FUN_004343e0(rtti, p);
}
__forceinline bool IsDecalNode(DObj* p)
{
    if (!p)
        return false;
    return FUN_004343e0(&DAT_0107000c, p);
}
struct DWork
{
    bool FUN_0046a080(DArg*);
};
// Checks limits and object conditions, may create decal effects, and returns a status.
// @fnv 0x004a2070
// pdb: BGSDecalManager::AddProjectedDecalRecurse | BGSDecalManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: arDecalData
bool DWork::FUN_0046a080(DArg* arg)
{
    if (*DAT_0106df58.FUN_00403e20() <= 0.0)
        return false;
    if (DAT_0106def8 >= *(int*)&DAT_0106df48.value)
    {
        if (DAT_0106dfdc.flag)
            FUN_00887da0(DAT_00dbea00);
        return false;
    }
    FUN_0045c640 original;
    if (arg->parent)
    {
        FUN_0045c640 p;
        arg->parent->interface30.Get(0, p);
        DObj* parent = p.FUN_00559450();
        if (FUN_00424d20(&DAT_0108f20c, parent))
            original.FUN_008e9650(parent);
    }
    if (!original.FUN_00559450())
        return false;
    if (arg->object)
    {
        const char* name = arg->object->FUN_00413f40()->FUN_0043b1b0();
        if (name)
        {
            if (!strncmp(name, "Decal", 5) || !strncmp(name, DAT_00dbe950, 7) || !strncmp(name, "Bip01", 5))
                return true;
        }
        if (arg->object->FUN_00456610())
            return true;
        if (arg->object->IsGeometry())
        {
            DObj* geometry = arg->object;
            if (arg->tries <= 0)
            {
                DProp* data = geometry->FUN_00826590(3);
                void* prop = geometry->FUN_004030b0();
                if (data && prop)
                {
                    FUN_0045c640 effect;
                    if (geometry->FUN_0043fad0())
                    {
                        DArray* array = arg->object->FUN_009611e0();
                        FUN_0049c870* selected = 0;
                        for (unsigned i = 0; i < array->FUN_0043b480(); ++i)
                        {
                            DObj* child = array->FUN_0043b4a0(i);
                            if (IsDecalNode(child))
                            {
                                selected = (FUN_0049c870*)child;
                                break;
                            }
                        }
                        if (!selected)
                            selected = new FUN_0049c870(array, true);
                        else
                        {
                            if (selected->FUN_00453470() >= (unsigned)*DAT_0106df7c.FUN_004241e0())
                                return true;
                        }
                        ++DAT_0106def8;
                        if (*DAT_0106dfdc.GetLifeStateControlFlag())
                            FUN_00887da0(DAT_00dbe9d4, DAT_0106def8);
                        FUN_0045c640 decal(new FUN_005b05f0(arg->flags, DAT_0106df58.FUN_00432b20(), arg, geometry, arg->origin,
                                               arg->normal, arg->scale, arg->rotation, arg->unk6c));
                        DObj* decalObject = decal.FUN_00559450();
                        decalObject->Virtual8c();
                        if (decalObject->FUN_0059e300() > 0)
                        {
                            if (!arg->skin)
                            {
                                arg->skin = new FUN_0082ea60(0);
                                arg->skin->FUN_008245d0(DAT_0106e7f0);
                                selected->Virtualdc((DObj*)arg->skin, true);
                                ++DAT_0106df00;
                                if (*DAT_0106dfdc.GetLifeStateControlFlag())
                                    FUN_00887da0(DAT_00dbe9b4, DAT_0106df00);
                            }
                            arg->skin->Virtualdc(decalObject->Virtual98(true));
                            decalObject->FUN_00886600((DObj*)arg->skin);
                            selected->effects->FUN_008f2610(decalObject);
                            DUpdate update(0.0f, false, false);
                            selected->FUN_008264c0(update);
                            DAT_0107c0a0.FUN_00793f90(decalObject);
                            effect.FUN_008e9650(decalObject);
                        }
                        else
                            return true;
                    }
                    if (arg->children)
                    {
                        DObj* a = 0;
                        unsigned found = 0;
                        while (found < arg->children->FUN_0043b480() && !a)
                        {
                            DObj* child = arg->children->FUN_0043b4a0(found);
                            if (child)
                            {
                                if (child->IsGeometry())
                                    a = child;
                                else if (child->IsSceneNode())
                                {
                                    DArray* uiIndex = (DArray*)child;
                                    unsigned pArray = 0;
                                    while (pArray < uiIndex->FUN_0043b480() && !a)
                                    {
                                        DObj* candidate = uiIndex->FUN_0043b4a0(pArray);
                                        if (candidate && candidate->IsGeometry())
                                            a = candidate;
                                        ++pArray;
                                    }
                                }
                            }
                            ++found;
                        }
                        if (a)
                        {
                            DProp* data2 = a->FUN_00826590(3);
                            void* prop2 = a->FUN_004030b0();
                            if (data2 && prop2)
                            {
                                DProp* shader = FUN_00468ef0(data2) ? data2 : 0;
                                if (shader)
                                {
                                    FUN_0045c640 additional;
                                    if (geometry->FUN_0043fad0())
                                    {
                                        FUN_005b05f0* pRawEffect =
                                            new FUN_005b05f0(arg->flags, DAT_0106df58.FUN_00432b20(), arg, a, arg->origin,
                                                        arg->normal.FUN_004a0bd0(), 1.0f, arg->rotation, arg->unk6c);
                                        additional.FUN_008e9650(pRawEffect);
                                        pRawEffect->Virtual8c();
                                    }
                                    if (additional.FUN_00559450())
                                        DAT_0107c0a0.FUN_00793f90(additional.FUN_00559450());
                                }
                            }
                        }
                    }
                }
                if (arg->tries >= 0)
                    return false;
                else
                    return true;
            }
            else
            {
                --arg->tries;
                return true;
            }
        }
        else if (arg->object->IsSceneNode())
        {
            DArray* pArray = (DArray*)arg->object;
            unsigned uiIndex = 0;
            while (uiIndex < pArray->FUN_0043b480())
            {
                DObj* child = pArray->FUN_0043b4a0(uiIndex);
                if (child)
                {
                    arg->object = child;
                    bool result = FUN_0046a080(arg);
                    if (!result)
                    {
                        if (arg->skin)
                        {
                            DArray* array = arg->object->FUN_009611e0();
                            FUN_0049c870* selected = 0;
                            for (unsigned d = 0; d < array->FUN_0043b480(); ++d)
                            {
                                DObj* entry = array->FUN_0043b4a0(d);
                                if (IsExactKind(&DAT_0107000c, entry))
                                {
                                    selected = (FUN_0049c870*)entry;
                                    break;
                                }
                            }
                            if (selected)
                                selected->Virtualdc((DObj*)arg->skin, true);
                        }
                        return false;
                    }
                }
                ++uiIndex;
            }
        }
    }
    return true;
}
}  // namespace fnv_004a2070

// @f3 0x0046ad40 (community match, verified in this file)
#include <windows.h>
namespace f3m_0046ad40 {

void __cdecl FUN_00887da0(const char* format, ...);
void __cdecl FUN_00403230(char* buf, int size, const char* format, ...);

extern __declspec(thread) int DAT_0117c298;
struct S46ad40_MemContext {
    int saved;
    S46ad40_MemContext(int tag) { saved = DAT_0117c298; DAT_0117c298 = tag; }
    ~S46ad40_MemContext() { DAT_0117c298 = saved; }
};

struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
    NiPoint3 operator+(const NiPoint3& o) const { return NiPoint3(x + o.x, y + o.y, z + o.z); }
    NiPoint3 operator-(const NiPoint3& o) const { return NiPoint3(x - o.x, y - o.y, z - o.z); }
    NiPoint3 operator*(const double& s) const { return NiPoint3((float)(x * s), y * s, z * s); }
    NiPoint3 operator-() const { return NiPoint3(-x, -y, -z); }
    float FUN_00432bd0() const;
    void FUN_00468d00();
};

struct NiBound {
    NiPoint3 m_kCenter;
    float m_fRadius;
};
extern NiBound DAT_0108edc8;
extern const NiPoint3 DAT_00f725b0;

struct S46ad40_Obj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual S46ad40_Obj* IsGeometry();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBound* m_pWorldBound;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int m_uiFlags;
    bool IsAppCulled() const { return ((m_uiFlags >> 10) & 1) != 0; }
    const NiBound& GetWorldBound() const { return m_pWorldBound ? *m_pWorldBound : DAT_0108edc8; }
};

struct S46ad40_Ref {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0(); virtual void v0c4(); virtual void v0c8(); virtual void v0cc();
    virtual void v0d0(); virtual void v0d4(); virtual void v0d8(); virtual void v0dc();
    virtual void v0e0(); virtual void v0e4(); virtual void v0e8(); virtual void v0ec();
    virtual void v0f0(); virtual void v0f4(); virtual void v0f8(); virtual void v0fc();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13c();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14c();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15c();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16c();
    virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17c();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18c();
    virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19c();
    virtual void v1a0(); virtual void v1a4(); virtual void v1a8(); virtual void v1ac();
    virtual void v1b0(); virtual void v1b4(); virtual void v1b8(); virtual void v1bc();
    virtual void v1c0(); virtual void v1c4(); virtual void v1c8(); virtual void v1cc();
    virtual S46ad40_Obj* Get3D();
};

struct S46ad40_Camera {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0(); virtual void v0c4(); virtual void v0c8(); virtual void v0cc();
    virtual void v0d0(); virtual void v0d4(); virtual void v0d8(); virtual void v0dc();
    virtual void v0e0(); virtual void v0e4(); virtual void v0e8(); virtual void v0ec();
    virtual void v0f0(); virtual void v0f4(); virtual void v0f8(); virtual void v0fc();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13c();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14c();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15c();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16c();
    virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17c();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18c();
    virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19c();
    virtual void v1a0(); virtual void v1a4(); virtual void v1a8(); virtual void v1ac();
    virtual void v1b0(); virtual void v1b4(); virtual void v1b8(); virtual void v1bc();
    virtual void v1c0(); virtual void v1c4(); virtual void v1c8(); virtual void v1cc();
    virtual void v1d0(); virtual void v1d4(); virtual void v1d8(); virtual void v1dc();
    virtual void v1e0(); virtual void v1e4(); virtual void v1e8(); virtual void v1ec();
    virtual void v1f0();
    virtual const NiPoint3* GetCameraPos();
};
extern S46ad40_Camera* DAT_0107a104;

struct S46ad40_Texture { int FUN_00410f00(); };
struct S46ad40_Material {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    unsigned char ucFlags24;
    unsigned char unk25;
    unsigned short unk26;
    S46ad40_Texture kTex;
};

struct S46ad40_Request {
    NiPoint3 kPos;
    NiPoint3 kDir;
    int unk18;
    int unk1C;
    int unk20;
    S46ad40_Ref* pRef;
    S46ad40_Obj* pGeom;
    int unk2C;
    int unk30;
    int unk34;
    float fWidth;
    float fHeight;
    int unk40;
    int unk44;
    S46ad40_Material* pMaterial;
    int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c;
    unsigned char unk70;
    bool bFlag71;
    unsigned char unk72; unsigned char unk73; unsigned char unk74; unsigned char unk75; unsigned char unk76;
    bool bForce77;
};

struct S46ad40_Pick {
    S46ad40_Obj* FUN_00569cc0(int i);
    void FUN_00569d10(int i, NiPoint3* pPos, NiPoint3* pNormal);
    int FUN_00569d60(const NiPoint3* pStart, const NiPoint3& kEnd, float fRadius);
    void FUN_00569e40(int iMat);
};
extern S46ad40_Pick* DAT_0106def0;
S46ad40_Pick* __cdecl FUN_0056a180(float f, int i);
float __cdecl FUN_00401e20(float a, float b);
void __cdecl FUN_008f4400(int a, int b, int c);
void* __cdecl FUN_004e7b90(S46ad40_Obj* p);
bool __cdecl FUN_00469000(void* p, int i);
extern int DAT_01071564;

struct S46ad40_SettingU { unsigned int& FUN_004241e0(); };
struct S46ad40_SettingB { bool& FUN_00405070(); };
extern S46ad40_SettingU DAT_0106dfc0;
extern S46ad40_SettingB DAT_0106dfdc;
extern S46ad40_SettingB DAT_0106df64;
extern bool DAT_0106df34;
extern bool DAT_0106df9c;
extern unsigned int DAT_0106df00;
extern float DAT_0106faa8;
extern float DAT_0106fcb8;

struct S46ad40_Node {
    S46ad40_Node* m_pkNext;
    S46ad40_Node* m_pkPrev;
    S46ad40_Obj* m_element;
};
struct S46ad40_Count {
    unsigned int m_uiCount;
    S46ad40_Count() : m_uiCount(0) {}
};
struct FUN_00bd12d0 {
    S46ad40_Node* m_pkHead;
    S46ad40_Node* m_pkTail;
    S46ad40_Count m_kAllocator;
    FUN_00bd12d0() { m_pkHead = 0; m_pkTail = 0; }
    __declspec(nothrow) ~FUN_00bd12d0();
    void FUN_00883a70(S46ad40_Obj* const& element);
    S46ad40_Obj*& GetNext(S46ad40_Node*& kPos) const
    {
        S46ad40_Obj*& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
    __forceinline S46ad40_Node* FindPos(S46ad40_Obj* const element) const
    {
        S46ad40_Node* kPos = m_pkHead;
        while (kPos) {
            S46ad40_Node* kLastPos = kPos;
            if (element == GetNext(kPos))
                return kLastPos;
        }
        return 0;
    }
};

struct S46ad40_DecalManager {
    int unk00;
    unsigned char ucFlag04;
    bool FUN_00469ce0(S46ad40_Request* apRequest);
    void FUN_0046a080(S46ad40_Request* apRequest);
    void FUN_0046ad40(S46ad40_Request* apRequest, int aiType, bool abForce);
};

// pdb: BGSDecalManager::AddDecal | BGSDecalManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: arDecalData, aeDecalType, abForceAdd
void S46ad40_DecalManager::FUN_0046ad40(S46ad40_Request* apRequest, int aiType, bool abForce)
{
    S46ad40_MemContext kContext(7);
    ucFlag04 = 1;
    switch (aiType) {
    case 1:
        if (DAT_0106df34 && apRequest->pGeom && !apRequest->pGeom->IsAppCulled()) {
            double dFreq;
            LARGE_INTEGER kFreq;
            LARGE_INTEGER kStart;
            LARGE_INTEGER kEnd;
            float fDistance;
            {
            NiPoint3 kCameraIn = *DAT_0107a104->GetCameraPos();
            NiPoint3 kDelta = apRequest->kPos - kCameraIn;
            fDistance = kDelta.FUN_00432bd0();
            }
            dFreq = 1000.0;
            kStart.LowPart = 0;
            if (DAT_0106df64.FUN_00405070()) {
                QueryPerformanceFrequency(&kFreq);
                dFreq = kFreq.QuadPart * 1e-6;
                QueryPerformanceCounter(&kStart);
            }
            if (fDistance <= DAT_0106fcb8 || apRequest->bForce77 || abForce) {
                if (DAT_0106dfdc.FUN_00405070())
                    FUN_00887da0("DECAL: Simple Decal Instantiated");
                FUN_00469ce0(apRequest);
            }
            if (DAT_0106df64.FUN_00405070()) {
                QueryPerformanceCounter(&kEnd);
                __int64 iTicks = kEnd.QuadPart - kStart.QuadPart;
                char acBuf[256];
                FUN_00403230(acBuf, 255, "AddGeometryDecalRecurse: Ticks: %I64d, Microseconds: %f", iTicks,
                             iTicks / dFreq);
            }
        }
        break;
    case 4:
        if (DAT_0106df34 && apRequest->pGeom && !apRequest->pGeom->IsAppCulled()) {
            apRequest->bFlag71 = 1;
            FUN_00469ce0(apRequest);
        }
        break;
    case 2:
        if (DAT_0106df9c && apRequest->pGeom && !apRequest->pGeom->IsAppCulled()) {
            NiPoint3 kCamPos = *DAT_0107a104->GetCameraPos();
            NiBound kBound = apRequest->pGeom->GetWorldBound();
            NiPoint3 kDelta = kBound.m_kCenter - kCamPos;
            float fDist = kDelta.FUN_00432bd0() - kBound.m_fRadius;
            unsigned int uiCount = DAT_0106df00;
            if ((fDist <= DAT_0106faa8 && uiCount < DAT_0106dfc0.FUN_004241e0()) || abForce)
                FUN_0046a080(apRequest);
            else if (uiCount >= DAT_0106dfc0.FUN_004241e0() && DAT_0106dfdc.FUN_00405070())
                FUN_00887da0("DECAL: Reached Max Skin Decal Limit! : %d", DAT_0106dfc0.FUN_004241e0());
        } else if (DAT_0106df9c && apRequest->pRef) {
            NiPoint3 kCamPos = *DAT_0107a104->GetCameraPos();
            NiBound kBound = apRequest->pRef->Get3D()->GetWorldBound();
            NiPoint3 kDelta = kBound.m_kCenter - kCamPos;
            float fDist = kDelta.FUN_00432bd0() - kBound.m_fRadius;
            S46ad40_Obj* p3D = apRequest->pRef->Get3D();
            if (p3D) {
                S46ad40_Obj* pGeom = p3D->IsGeometry();
                if (pGeom && !p3D->IsAppCulled()) {
                    apRequest->pGeom = pGeom;
                    unsigned int uiCount = DAT_0106df00;
                    if ((fDist <= DAT_0106faa8 && uiCount < DAT_0106dfc0.FUN_004241e0()) || abForce)
                        FUN_0046a080(apRequest);
                    else if (uiCount >= DAT_0106dfc0.FUN_004241e0() && DAT_0106dfdc.FUN_00405070())
                        FUN_00887da0("DECAL: Reached Max Skin Decal Limit! : %d", DAT_0106dfc0.FUN_004241e0());
                }
            }
        } else if (DAT_0106df34) {
            apRequest->kDir.FUN_00468d00();
            if (!DAT_0106def0)
                DAT_0106def0 = FUN_0056a180(FUN_00401e20(apRequest->fHeight, apRequest->fWidth), 1);
            FUN_008f4400(0x27, 8, 0);
            FUN_008f4400(0x27, 0x1d, 0);
            S46ad40_Material* pMat = apRequest->pMaterial;
            DAT_0106def0->FUN_00569e40((pMat->ucFlags24 & 1) ? pMat->kTex.FUN_00410f00() : DAT_01071564);
            int iCount = DAT_0106def0->FUN_00569d60(&apRequest->kPos, apRequest->kPos + apRequest->kDir * 80.0, 32.0f);
            if (iCount == 0) {
                NiPoint3 kDir = apRequest->kDir + -DAT_00f725b0 * 2.0;
                kDir.FUN_00468d00();
                apRequest->kDir = kDir;
                iCount = DAT_0106def0->FUN_00569d60(&apRequest->kPos, apRequest->kPos + kDir * 80.0, 32.0f);
            }
            {
            FUN_00bd12d0 kHit;
            for (int i = 0; i < iCount; i++) {
                NiPoint3 kPos;
                NiPoint3 kNormal;
                S46ad40_Obj* pObj = DAT_0106def0->FUN_00569cc0(i);
                S46ad40_Obj* pHitTmp = pObj;
                if (pObj) {
                    DAT_0106def0->FUN_00569d10(i, &kPos, &kNormal);
                    kNormal.FUN_00468d00();
                    void* pOwner = FUN_004e7b90(pObj);
                    if (pObj->IsAppCulled() || !pOwner || !FUN_00469000(pOwner, 1))
                        continue;
                    if (!kHit.FindPos(pObj)) {
                        apRequest->kPos = kPos;
                        apRequest->kDir = kNormal;
                        apRequest->pGeom = pObj;
                        FUN_00469ce0(apRequest);
                        kHit.FUN_00883a70(pHitTmp);
                    }
                }
            }
            kHit.~FUN_00bd12d0();
            }
        }
        break;
    }
}

}

// @f3 0x0046f470 (community match, verified in this file)
#include <string.h>

namespace s46f470 {

void* __cdecl FUN_0089e810(unsigned int);

template <class K>
struct S46f470_MapItem {
    S46f470_MapItem* m_pkNext;
    K m_key;
    bool m_val;
};

template <class K>
struct S46f470_MapBase {
    typedef S46f470_MapItem<K> Item;
    unsigned int m_uiHashSize;
    Item** m_ppkHashTable;
    unsigned int m_uiCount;

    S46f470_MapBase(unsigned int uiHashSize)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        m_ppkHashTable = (Item**)FUN_0089e810(sizeof(Item*) * uiHashSize);
        unsigned int b = m_uiHashSize; b *= 4; memset(m_ppkHashTable, 0, b);
    }
    virtual ~S46f470_MapBase();
    virtual unsigned int KeyToHashIndex(K key) const;
    virtual bool IsKeyEqual(K key1, K key2) const;

    bool GetAt(K key, bool& val) const
    {
        unsigned int index = KeyToHashIndex(key);
        Item* item = m_ppkHashTable[index];
        while (item) {
            if (IsKeyEqual(key, item->m_key)) {
                val = item->m_val;
                return true;
            }
            item = item->m_pkNext;
        }
        return false;
    }
    void FUN_00493c20(K key, bool val);
    bool FUN_0040e820(K key, bool* val);
    void FUN_006bd950();
};

struct S46f470_Ref;

struct S46f470_Item {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    S46f470_Ref* unk3C;
    S46f470_Ref* const& GetRef() const { return unk3C; }
};

struct S46f470_Node {
    S46f470_Node* next;
    int unk04;
    S46f470_Item* data;
};

struct S46f470_Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20;
    S46f470_Node* unk24;
};

struct S46f470_OuterNode {
    S46f470_OuterNode* next;
    int unk04;
    S46f470_Data* data;
};


struct S46f470_Cell {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    S46f470_OuterNode* unk3C;
};

struct S46f470_Game {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60;
    S46f470_Cell* unk64;
};
extern void* DAT_0107a0d8;

struct S46f470_GeomData {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual unsigned short GetVertexCount();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
};

struct S46f470_Shape {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4;
    S46f470_GeomData* unkB8;
    unsigned short GetVertexCount() { return unkB8->GetVertexCount(); }
    int GetVertices() { return unkB8->unk20; }
    int GetNormals() { return unkB8->unk24; }
    int GetColors() { return unkB8->unk28; }
    int GetTextures() { return unkB8->unk2C; }
};

struct S46f470_Geom {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual S46f470_Shape* GetShape();
};

struct S46f470_Obj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual int IsValid();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    S46f470_Geom** unkA0;
    S46f470_Geom* GetAt(unsigned int i) { return unkA0[i]; }
};

struct S46f470_Listed {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC(); virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void vE0(); virtual void vE4(); virtual void vE8(); virtual void vEC(); virtual void vF0(); virtual void vF4(); virtual void vF8(); virtual void vFC(); virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C(); virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C(); virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12C(); virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13C(); virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14C(); virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15C(); virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16C(); virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17C(); virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18C(); virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19C(); virtual void v1A0(); virtual void v1A4(); virtual void v1A8(); virtual void v1AC(); virtual void v1B0(); virtual void v1B4(); virtual void v1B8(); virtual void v1BC(); virtual void v1C0(); virtual void v1C4(); virtual void v1C8(); virtual void v1CC();
    virtual S46f470_Obj* GetObj();
};

struct S46f470_ListNode {
    S46f470_Listed* data;
    S46f470_ListNode* next;
};

struct S46f470_Ref {
    S46f470_ListNode* FUN_004d3490();
};

struct S46f470_Map1 : S46f470_MapBase<S46f470_Ref*> {
    S46f470_Map1() : S46f470_MapBase<S46f470_Ref*>(37) {}
    ~S46f470_Map1();
};

}
struct FUN_00b60360 : s46f470::S46f470_MapBase<s46f470::S46f470_Item*> {
    FUN_00b60360() : s46f470::S46f470_MapBase<s46f470::S46f470_Item*>(37) {}
    virtual ~FUN_00b60360();
};
namespace s46f470 {
typedef ::FUN_00b60360 S46f470_Map2;

struct S46f470_Owner {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20;
    int unk24;
    int unk28; int unk2C;
    int unk30;
    void FUN_0046f470(S46f470_Ref* ref);
};

}

namespace s46f470 {

// pdb: BGSSceneInfo::CollectWaterSceneDataFromCell | BGSSceneInfo.obj | fnv360_0721_beta, call_seq, medium
// pdb params: apCell
void S46f470_Owner::FUN_0046f470(S46f470_Ref* ref)
{
    S46f470_Cell* tmp = ((S46f470_Game*)s46f470::DAT_0107a0d8)->unk64;
    S46f470_Map1 s;
    S46f470_Map2 data;
    S46f470_OuterNode* node = tmp->unk3C;
    while (node) {
        S46f470_OuterNode* next = node ? node->next : 0;
        S46f470_Data* items = node->data;
        if (items) {
            S46f470_Node* pos = items->unk24;
            while (pos) {
                S46f470_Node* next = pos ? pos->next : 0;
                S46f470_Item* item = pos->data;
                bool val;
                s.GetAt(item->GetRef(), val);
                if (!data.GetAt(item, val) && item->GetRef() == ref) {
                    ++unk24;
                    data.FUN_00493c20(item, true);
                }
                S46f470_Ref* parent = item->GetRef();
                s.FUN_00493c20(parent, true);
                pos = next;
            }
            bool i;
            s.FUN_0040e820(ref, &i);
        }
        s.FUN_006bd950();
        node = next;
    }
    // placeable waters of the cell: vertex data bytes of each reference's first child geometry
    S46f470_ListNode* waterNode = ref->FUN_004d3490();
    while (waterNode && waterNode->data) {
        S46f470_Listed* waterRef = waterNode->data;
        S46f470_Obj* root = waterRef->GetObj();
        if (root && root->IsValid()) {
            S46f470_Geom* child = root->GetAt(0);
            S46f470_Shape* geom = child->GetShape();
            if (geom) {
                int size = 0;
                unsigned int vertexCount = geom->GetVertexCount();
                if (geom->GetVertices())
                    size += vertexCount * 12;
                if (geom->GetColors())
                    size += vertexCount * 16;
                if (geom->GetNormals())
                    size += vertexCount * 12;
                if (geom->GetTextures())
                    size += vertexCount * 8;
                unk30 += size;
            }
        }
        waterNode = waterNode->next;
    }
    data.FUN_006bd950();
}

}

// @f3 0x0047bc90 (community match, verified in this file)
namespace Grid47bc90 {

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ec10(void* p, unsigned int size);
void* __cdecl FUN_0089e810(unsigned int size);

struct Heap47 { void* FUN_0086b930(unsigned int size); };
extern Heap47 DAT_01090a78;

struct Point47 {
    float x, y, z;
    Point47() {}
    Point47(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    static void* operator new[](unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
};
struct Point2_47 {
    float x, y;
    Point2_47() {}
    Point2_47(float ax, float ay) : x(ax), y(ay) {}
    static void* operator new[](unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
};
struct Color47 { float r, g, b; };
struct ColorA47 {
    float r, g, b, a;
    ColorA47(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};
struct UpdateData47 {
    float fTime;
    bool bUpdateControllers;
    bool bIsMultiThreaded;
    bool bReserved;
    bool bUpdateGeomorphs;
    bool bUpdateShadowScene;
    UpdateData47(float t, bool controllers, bool threaded)
        : fTime(t), bUpdateControllers(controllers), bIsMultiThreaded(threaded), bReserved(false),
          bUpdateGeomorphs(false), bUpdateShadowScene(false) {}
};

struct RefObject47 {
    virtual void v00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (!InterlockedDecrement(&m_uiRefCount)) DeleteThis(); }
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p, unsigned int size) { FUN_0089ec10(p, size); }
};

// vtable slots 2..55 of the scene-graph objects (0xdc is the node's child attach)
struct Object47 : RefObject47 {
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68();
    virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void* v9c(); virtual void va0(); virtual void va4();
    virtual void va8(); virtual void vac(); virtual void vb0(); virtual void vb4(); virtual void vb8();
    virtual void vbc(); virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(int value); virtual void vd4(); virtual void vd8();
    virtual void vdc(Object47* child, bool firstAvailable);
};

struct Spatial47 : Object47 {
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    Point47 translate;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    void MoveTo(const Point47& point) { translate = point; }
    void MoveTo(float x, float y, float z) { translate = Point47(x, y, z); }
    void FUN_004236f0(RefObject47* property);
    void FUN_008264c0(UpdateData47& data);
    void FUN_008268a0();
};

struct FUN_0082ea60 : Spatial47 {
    int unk9c, unka0, unka4, unka8;
    FUN_0082ea60(unsigned int size);
};

struct FUN_0083b6d0 : Spatial47 {
    int unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100;
    int unk104, unk108, unk10c, unk110;
    FUN_0083b6d0();
    bool FUN_0083a590(const Point47& target, const Point47& up);
    void FUN_00839f90(const struct FUN_0083bf50& frustum);
};

struct FUN_008403a0 : RefObject47 {
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c;
    FUN_008403a0(unsigned short vertices, Point47* positions, Point47* normals, ColorA47* colors,
                 Point2_47* uvs, unsigned short uvSets, int tangents, unsigned short triangles,
                 unsigned short strips, unsigned short* stripLengths, unsigned short* stripLists);
};

struct FUN_0083c0a0 : Spatial47 {
    int unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    FUN_0083c0a0(FUN_008403a0* data);
};

struct Texture47;
struct FUN_00af2240 : Object47 {
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    int unk68, unk6c, unk70, unk74, unk78, unk7c;
    FUN_00af2240();
    void FUN_0047b810(Texture47* texture);
};

struct FUN_00840230 : RefObject47 {
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;
    int unk98, unk9c, unka0, unka4;
    unsigned int revision;
    int unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    Color47 ambient;
    Color47 diffuse;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8;
    FUN_00840230();
    void Bump() { revision++; }
    void SetColorC8(const Color47& color) { ambient = color; Bump(); }
    void SetColorD4(const Color47& color) { diffuse = color; Bump(); }
    void FUN_0078c030(FUN_0082ea60* node);
};

struct FUN_0083fc40 : RefObject47 {
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Color47 emittance;
    int unk34, unk38, unk3c, unk40;
    unsigned int revision;
    int unk48;
    FUN_0083fc40();
    void SetColor28(const Color47& color) { emittance = color; revision++; }
};

struct FUN_00465160 : RefObject47 {
    int unk08, unk0c, unk10, unk14;
    unsigned short flags;
    unsigned short unk1a;
    int unk1c, unk20;
    FUN_00465160();
    void SetFlagField(unsigned short mode) { flags = (unsigned short)((flags & ~0xc00) | (mode << 10)); }
};

struct FUN_00ae9090 : RefObject47 {
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    bool unk84;
    char unk85, unk86, unk87;
    int unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    int unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4;
    int unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c, unk110, unk114;
    int unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144;
    int unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174;
    int unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4;
    int unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4;
    int unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204;
    int unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234;
    int unk238, unk23c, unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264;
    int unk268, unk26c, unk270, unk274, unk278, unk27c;
    FUN_00ae9090(int groups, int a, int b);
    void SetFlag84(bool value) { unk84 = value; }
};
FUN_00ae9090* __cdecl FUN_00ad5a50();

struct FUN_00833810 {
    virtual ~FUN_00833810();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    FUN_00833810(int visible);
};
struct Cull47 : FUN_00833810 {
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    NiPointer<FUN_00ae9090> accumulator;
    Cull47(int visible) : FUN_00833810(visible), unk90(0), unkbc(0), unkc0(0) {}
    ~Cull47();
    void FUN_004691c0(FUN_00ae9090* value) { accumulator = value; }
};

struct FUN_0083bf50 {
    float left, right, top, bottom, nearDistance, farDistance;
    bool parallel;
    FUN_0083bf50(bool parallelProjection);
};

struct Device47 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual long __stdcall v50(unsigned int level);
};
struct RendererData47 : Object47 {
};
struct Texture47 : RefObject47 {
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    RendererData47* rendererData;
};
struct TextureInfo47 {
    int unk00;
    int dirty;
};
struct Cell47 {
    int FUN_004d36d0(Texture47** texture, TextureInfo47** info);
};
struct Slot47 {
    Cell47* cell;
};

struct RenderTarget47;
struct RenderedTexture47 : RefObject47 {
    RenderTarget47* FUN_00aee520();
    Texture47* FUN_0047b7b0(int index);
};
struct TextureManager47 {
    RenderedTexture47* FUN_00af1470(void* renderer, int format, int a, int b, int c);
};
struct Renderer47 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88();
    virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8();
    virtual void vac(const ColorA47& color);
    virtual void vb0();
    virtual void vb4(ColorA47& color);
};

struct ListEntry47 { int unk00, unk04; Texture47* texture; };
struct List47 { ListEntry47* first; };
struct Singleton47 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    List47* list;
    Texture47* FirstTexture() { ListEntry47* entry = list->first; return entry ? entry->texture : 0; }
};
Singleton47* __cdecl FUN_0049f1b0();

extern bool DAT_0106fac4;
extern bool DAT_00f4c96c;
extern unsigned int DAT_0116efc8;
extern float DAT_011735f4;
extern float DAT_011735f8;
extern float DAT_01173600;
extern Renderer47* DAT_0106f8d8;
extern NiPointer<Texture47> DAT_0116f3d8;
extern Point47 DAT_00f725b0;
extern Point47 DAT_0108ec68;
extern Point47 DAT_00f725a4;
extern Color47 DAT_00f731bc;
extern void* DAT_0108f048;
extern TextureManager47* DAT_0116ef98;
extern ColorA47 DAT_00f73210;

void __cdecl FUN_00ade300(Spatial47* object, int a, int b);
void __cdecl FUN_00aeec60(int mode, RenderTarget47* target);
void __cdecl FUN_00aef280(FUN_0083b6d0* camera, FUN_0082ea60* scene, Cull47* cull);
void __cdecl FUN_00aef470(FUN_0083b6d0* camera, FUN_00ae9090* accumulator, int flags);
void __cdecl FUN_00aeeb20();

inline unsigned int GlobalFlags() { return DAT_0116efc8; }
inline void SetGlobalFlags(unsigned int passes) { DAT_0116efc8 = passes; }
inline void SetCorner(float x, float y) { DAT_011735f4 = x; DAT_011735f8 = y; }
inline void SetWidth(float width) { DAT_01173600 = width; }
inline void __cdecl FUN_00434540(Texture47* texture) { DAT_0116f3d8 = texture; }
inline Renderer47* CurrentRenderer() { return DAT_0106f8d8; }

struct MemContext47 {
    int old;
    MemContext47(int tag) { old = g_tlsMemContext; g_tlsMemContext = tag; }
    ~MemContext47() { g_tlsMemContext = old; }
};

struct Grid47 {
    int unk00, unk04, unk08;
    unsigned int dimension;
    Slot47* cells;
    float x, y;
    int unk1c, unk20;
    NiPointer<RenderedTexture47> texture;
    unsigned int Dimension() { return dimension; }
    Slot47* CellAt(unsigned int gx, unsigned int gy)
    {
        unsigned int dim = Dimension();
        if (gx >= dim || gy >= dim)
            return 0;
        return &cells[Dimension() * gx + gy];
    }
    void FUN_0047bc90();
};

// pdb: GridCellArray::RecreateCanopyShadowMaskTexture | GridCell.obj | fnv360_0822_retail, call_gap, low
void Grid47::FUN_0047bc90()
{
    MemContext47 context(0x20);
    FUN_00af2240* property = 0;
    NiPointer<FUN_0082ea60> root(0);
    unsigned int i;
    unsigned int j;
    NiPointer<FUN_0082ea60> cameraRoot(0);
    NiPointer<FUN_0083c0a0> strips(0);
    float half;
    NiPointer<FUN_008403a0> stripData(0);
    NiPointer<FUN_0083b6d0> camera(0);
    float extent;
    FUN_0083bf50 frustum(false);
    bool noTextures;
    NiPointer<FUN_00840230> light(0);
    Texture47* cellTexture;
    TextureInfo47* cellInfo;
    Point47 position;
    ColorA47 background(0.0f, 0.0f, 0.0f, 0.0f);
    Cell47* cell;
    unsigned int dim = Dimension();
    bool noCells = true;
    noTextures = true;
    DAT_00f4c96c = false;
    if (!DAT_0106fac4)
        return;
    extent = (float)(Dimension() << 12);
    float corner = 2048.0 - extent / 2.0;
    SetCorner(x + corner, y + corner);
    SetWidth(extent);
    SetGlobalFlags(GlobalFlags() | 0x20);
    if (dim == 0 || CurrentRenderer() == 0)
    {
        SetGlobalFlags(GlobalFlags() & ~0x20);
        FUN_00434540(0);
        return;
    }
    half = dim / 2.0f;
    position.y = half * -1.0;
    position.x = position.y;
    position.z = 0.0f;
    root = new FUN_0082ea60(0);

    Point47* positions = new Point47[4];
    positions[0] = Point47(0.0f, 0.0f, 0.0f);
    positions[1] = Point47(1.0f, 0.0f, 0.0f);
    positions[2] = Point47(1.0f, 1.0f, 0.0f);
    positions[3] = Point47(0.0f, 1.0f, 0.0f);

    Point47* normals = new Point47[4];
    normals[0] = normals[1] = normals[2] = normals[3] = DAT_00f725b0;

    Point2_47* uvs = new Point2_47[4];
    uvs[0] = Point2_47(0.0f, 0.0f);
    uvs[1] = Point2_47(1.0f, 0.0f);
    uvs[2] = Point2_47(1.0f, 1.0f);
    uvs[3] = Point2_47(0.0f, 1.0f);

    unsigned short* stripList = (unsigned short*)FUN_0089e810(8);
    stripList[0] = 1;
    stripList[1] = 0;
    stripList[2] = 2;
    stripList[3] = 3;
    unsigned short* stripLengths = (unsigned short*)FUN_0089e810(2);
    stripLengths[0] = 4;

    stripData = new FUN_008403a0(4, positions, normals, 0, uvs, 1, 0, 2, 1, stripLengths, stripList);

    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            property = 0;
            cell = CellAt(i, j)->cell;
            if (cell)
            {
                int result = cell->FUN_004d36d0(&cellTexture, &cellInfo);
                if (cellTexture && cellInfo && cellInfo->dirty)
                {
                    RendererData47* data = cellTexture->rendererData;
                    Device47* device = (Device47*)data->v9c();
                    device->v50(0);
                    cellInfo->dirty = 0;
                }
                if (result == 1 && cellTexture)
                {
                    property = new FUN_00af2240();
                    property->FUN_0047b810(cellTexture);
                    property->vd0(0);
                    noCells = noTextures = false;
                }
                else if (result == 2)
                {
                    noTextures = false;
                }
            }
            if (!property)
            {
                position.y += 1.0;
                noCells = false;
                continue;
            }
            strips = new FUN_0083c0a0(stripData);
            strips->MoveTo(position);
            strips->FUN_004236f0(property);
            FUN_00ade300(strips, 0, 0);
            root->vdc(strips, true);
            position.y += 1.0;
        }
        position.x += 1.0;
        position.y = half * -1.0;
    }

    if (noCells)
    {
        FUN_00434540(FUN_0049f1b0()->FirstTexture());
        return;
    }
    else if (noTextures)
    {
        SetGlobalFlags(GlobalFlags() & ~0x20);
        FUN_00434540(0);
        return;
    }

    cameraRoot = new FUN_0082ea60(0);
    camera = new FUN_0083b6d0();
    cameraRoot->vdc(camera, true);
    cameraRoot->MoveTo(0.0f, 0.0f, 1.0f);
    UpdateData47 update1(0.0f, false, false);
    cameraRoot->FUN_008264c0(update1);
    camera->FUN_0083a590(DAT_0108ec68, DAT_00f725a4);
    UpdateData47 update2(0.0f, false, false);
    camera->FUN_008264c0(update2);
    UpdateData47 update3(0.0f, false, false);
    cameraRoot->FUN_008264c0(update3);

    frustum.parallel = true;
    frustum.bottom = frustum.left = half * -1.0;
    frustum.top = frustum.right = half;
    frustum.nearDistance = 1.0f;
    frustum.farDistance = 2.0f;
    camera->FUN_00839f90(frustum);

    light = new FUN_00840230();
    light->SetColorC8(DAT_00f731bc);
    light->SetColorD4(DAT_00f731bc);
    light->FUN_0078c030(root);

    FUN_0083fc40* material = new FUN_0083fc40();
    material->SetColor28(DAT_00f731bc);
    root->FUN_004236f0(material);

    FUN_00465160* stencil = new FUN_00465160();
    stencil->SetFlagField(3);
    root->FUN_004236f0(stencil);

    if (texture == 0)
        texture = DAT_0116ef98->FUN_00af1470(DAT_0108f048, 0x16, 0, 0, 0);
    CurrentRenderer()->vb4(background);
    CurrentRenderer()->vac(DAT_00f73210);
    root->FUN_008268a0();
    UpdateData47 update4(0.0f, false, false);
    root->FUN_008264c0(update4);
    UpdateData47 update5(0.0f, false, false);
    cameraRoot->FUN_008264c0(update5);
    UpdateData47 update6(0.0f, false, false);
    camera->FUN_008264c0(update6);

    Cull47 cull(0);
    NiPointer<FUN_00ae9090> accumulator(new FUN_00ae9090(0x63, 1, 0x2f7));
    cull.FUN_004691c0(accumulator);
    accumulator->SetFlag84(false);
    FUN_00aeec60(7, texture->FUN_00aee520());
    FUN_00aef280(camera, root, &cull);
    FUN_00aef470(camera, accumulator, 0);
    FUN_00aeeb20();
    cull.FUN_004691c0(0);
    accumulator = 0;
    FUN_00434540(texture->FUN_0047b7b0(0));
    FUN_00ad5a50()->SetFlag84(true);
    CurrentRenderer()->vac(background);
}

}

// @f3 0x00473ea0 (community match, verified in this file)
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

namespace f3m_00473ea0 {

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

struct Obj;
struct Ctrl;
struct Mat3 {
    float m[3][3];
    void FUN_00423fd0(float angle);
    Mat3 FUN_00424020(const Mat3& rhs) const;
};
struct Point { unsigned x, y, z; };
struct Element24 {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    Element24();
    ~Element24();
};
struct Retained {
    Obj* object;
    Retained() : object(0) {}
    explicit Retained(Obj* p) { FUN_0045c640(p); }
    ~Retained() { FUN_00424aa0(); }
    Retained* FUN_0045c640(Obj* p);
    void FUN_00424aa0();
    void FUN_008e9650(Obj* p);
};
struct Obj3 { void FUN_00ad2840(unsigned); };
struct Root { void TESModelTextureSwap_SwapTextures(Obj*); };
struct Obj {
    virtual ~Obj();
    virtual void DeleteThis();
    virtual void v08();
    virtual Obj* GetAsNode();
    virtual Obj3* V10();
    virtual void v14(); virtual void v18();
    virtual Obj* V1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac(); virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc(); virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc(); virtual void vd0(); virtual void vd4(); virtual void vd8();
    virtual void AttachChild(Obj* child, bool b);
    virtual void ve0();
    virtual void VE4(Obj* p);
    virtual void DetachChild(Obj* child);
    volatile long refCount;
    unsigned unk08, unk0c, unk10, unk14;
    Obj* parent;
    unsigned unk1c, unk20, unk24, unk28, unk2c;
    unsigned flags;
    Mat3 rotation;
    Point translation;
    unsigned unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    Obj** children;
    unsigned short unka4;
    unsigned short childCount;
    unsigned unka8, unkac, unkb0, unkb4;
    Ctrl* unkb8;
};
struct Ctrl { void FUN_00825970(Retained* out); };
struct SmartPtr {
    Obj* object;
    SmartPtr() : object(0) {}
    ~SmartPtr() { Obj* p = object; if (p && InterlockedDecrement(&p->refCount) == 0) p->DeleteThis(); }
    void FUN_008e9650(Obj* p);
};
struct LoadOptions {
    Obj* unk00;
    Obj* unk04;
    unsigned unk08, unk0c;
    float scaleX, scaleY, scaleZ;
    explicit LoadOptions(unsigned mode) { FUN_00471430(mode); scaleX = scaleY = scaleZ = 1.0f; }
    ~LoadOptions() { delete unk00; delete unk04; }
    void FUN_00471430(unsigned mode);
};
struct Extra { unsigned unk00, unk04, unk08; unsigned unk0c; bool IsFlag4() const { return (unk0c >> 4) & 1; } };
struct ModelForm {
    Obj* FUN_008257a0(LoadOptions*);
    Extra* FUN_00824a50(void* key);
};
struct Model {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual const char* GetPath();
    virtual void v18();
    virtual Root* GetRoot();
    char* name;
    unsigned short length;
    unsigned short unk0a;
    unsigned unk0c, unk10;
    unsigned char flags;
    unsigned GetLength() const { unsigned short n = length; return n == 0xffff ? strlen(name) : n; }
};
struct Form0 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0(); virtual void va4(); virtual void va8();
    virtual bool CheckUpdate();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc(); virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc(); virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc(); virtual void ve0(); virtual void ve4(); virtual void ve8(); virtual void vec(); virtual void vf0(); virtual void vf4(); virtual void vf8(); virtual void vfc(); virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c(); virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c(); virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c();
    virtual const char* GetEditorID();
    unsigned unk04, unk08;
    unsigned formID;
    unsigned GetFormID() { return formID; }
    unsigned unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    unsigned unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    unsigned flags100;
};
struct Npc {
    unsigned unk00;
    unsigned char type;
    void FUN_00554d10(Element24* out);
};
struct Extra5c { unsigned unk00, unk04, unk08, unk0c, unk10; struct Geom* unk14; };
struct Geom { void FUN_008268a0(); };
struct SlotList { bool FUN_0041cb90(int k); };
struct SlotHolder { SlotList* FUN_0040e570(); };
struct Owner;
struct Picker;
struct Animation;
struct Actor;
struct Process {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac(); virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc(); virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc(); virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc(); virtual void ve0(); virtual void ve4(); virtual void ve8(); virtual void vec(); virtual void vf0(); virtual void vf4(); virtual void vf8(); virtual void vfc(); virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c(); virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c(); virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c(); virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13c(); virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14c(); virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15c(); virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16c(); virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17c(); virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18c(); virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19c(); virtual void v1a0(); virtual void v1a4(); virtual void v1a8(); virtual void v1ac(); virtual void v1b0(); virtual void v1b4(); virtual void v1b8(); virtual void v1bc(); virtual void v1c0(); virtual void v1c4();
    virtual void UpdateWeaponDrawn(bool drawn, Owner* owner, Animation* anim, Actor* actor);
};
struct Actor {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    Npc* unk1c;
    Npc* GetObjectReference() { return unk1c; }
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    SlotHolder unk40;
    unsigned unk44, unk48, unk4c, unk50, unk54, unk58;
    Extra5c* unk5c;
    Process* process;
    Geom* GetRefNode();
    Geom* Get3DSimple();
    bool FUN_0076cd40(Owner* o);
    Owner* FUN_0076cd20(bool b);
    Animation* FUN_0076cce0(bool b);
    Animation* Actor_GetAnimation();
    bool FUN_006f6c70();
    void FUN_004f5750(Form0* w);
    const char* FUN_004e9a10();
};
struct Entry {
    Form0* owner;
    Model* form;
    Obj* scene;
    unsigned char hidden;
    unsigned char unk0d;
    unsigned short unk0e;
};
struct Pair { unsigned unk00; Obj* node; };
struct Owner {
    Obj* root;
    Pair pairs[5];
    Entry entries[20];
    Entry pending[20];
    unsigned unk2ac;
    Actor* actor;
    void FUN_00473ea0(bool deferred);
    __forceinline void ReleasePending(Entry& pend);
    void FUN_004730a0(Obj* child, int b);
    void FUN_00471020(Obj* scene);
    void FUN_004724d0(Form0* w);
    void FUN_00471e50(int a, int b, int slot);
    Obj* FUN_00473ab0(Obj* node, int slot, bool a, bool b, int c);
    bool FUN_004708a0(int slot);
    Picker* FUN_00471b70(int slot);
};
struct Loader {
    void FUN_00429640(const char* path, bool a, bool b);
    ModelForm* FUN_00429eb0(const char* path, int a, int b, int c, int d, int e);
};
struct World { Obj* FUN_00435e70(ModelForm*, LoadOptions*); };
struct Mgr { void FUN_006f2440(Obj* s); };
struct Remover { void FUN_00ae1a30(Obj* s); };
struct SaveMgr { bool FUN_008257f0(); };
struct Picker { bool FUN_00596070(Element24* a, Obj* o, int c); };
struct MemoryManager { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern MemoryManager DAT_01090a78;
struct String {
    char* ptr;
    unsigned short len;
    unsigned short cap;
    String() : ptr(0), len(0), cap(0) {}
    ~String() { if (ptr) DAT_01090a78.FUN_0086ba60(ptr); ptr = 0; cap = 0; len = 0; }
    bool FUN_004019c0(const char* text, unsigned int length);
    int FormatArgs(const char* format, va_list args);
};
extern char* DAT_00e207a8;
char* FUN_008242a0(const char* s);
struct FixedStr {
    char* p;
    FixedStr(const char* s) { if (s == 0) p = DAT_00e207a8; else p = FUN_008242a0(s); }
    ~FixedStr() { if (p != DAT_00e207a8) InterlockedDecrement((volatile long*)(p - 8)); }
};
struct NameTarget { void FUN_008245d0(const FixedStr& name); };

extern Actor* DAT_0107a104;
extern bool DAT_0106e30c;
extern bool DAT_0106e534;
extern bool DAT_01073a60;
extern Loader* DAT_0106ca70;
extern World* DAT_0107a0d8;
extern Mgr* DAT_0107a79c;
extern Remover* DAT_0116efb8;
extern SaveMgr* DAT_01079ca4;
extern void* DAT_0116d6e0;
extern const Point DAT_0108ec68;
extern const Mat3 DAT_00f72574;
extern const float DAT_00db8850;
extern const int DAT_00f4c3d0[];
extern const char* DAT_00f4c380[];
extern const char DAT_00dc0218[];
extern const char DAT_00dc01e0[];
extern const char DAT_00dbfeb4[];
struct TlsData {
    unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c; unsigned unk140; unsigned unk144; unsigned unk148; unsigned unk14c; unsigned unk150; unsigned unk154; unsigned unk158; unsigned unk15c; unsigned unk160; unsigned unk164; unsigned unk168; unsigned unk16c; unsigned unk170; unsigned unk174; unsigned unk178; unsigned unk17c; unsigned unk180; unsigned unk184; unsigned unk188; unsigned unk18c; unsigned unk190; unsigned unk194; unsigned unk198; unsigned unk19c; unsigned unk1a0; unsigned unk1a4; unsigned unk1a8; unsigned unk1ac; unsigned unk1b0; unsigned unk1b4; unsigned unk1b8; unsigned unk1bc; unsigned unk1c0; unsigned unk1c4; unsigned unk1c8; unsigned unk1cc; unsigned unk1d0; unsigned unk1d4; unsigned unk1d8; unsigned unk1dc; unsigned unk1e0; unsigned unk1e4; unsigned unk1e8; unsigned unk1ec; unsigned unk1f0; unsigned unk1f4; unsigned unk1f8; unsigned unk1fc; unsigned unk200; unsigned unk204; unsigned unk208; unsigned unk20c; unsigned unk210; unsigned unk214; unsigned unk218; unsigned unk21c; unsigned unk220; unsigned unk224; unsigned unk228; unsigned unk22c; unsigned unk230; unsigned unk234; unsigned unk238; unsigned unk23c; unsigned unk240; unsigned unk244;
    Geom* unk248;
    Actor* unk24c;
};
extern __declspec(thread) TlsData DAT_0117c000;
inline Geom* Actor::GetRefNode() { Geom* r; if (unk5c) r = unk5c->unk14; else r = 0; return r; }
inline Geom* Actor::Get3DSimple() { if (this == DAT_0117c000.unk24c) return DAT_0117c000.unk248; return GetRefNode(); }

void __cdecl FUN_0058aa00(Npc* n);
bool __cdecl FUN_00724400();
void __cdecl FUN_00478bb0(Obj* s);
void __cdecl FUN_008d7720(Obj* s, int a, int b);
void __cdecl FUN_0061aaf0(void* p);
bool __cdecl FUN_004706c0();
bool __cdecl FUN_00478250(ModelForm* m);
void __cdecl FUN_00479030(Obj* n);
void __cdecl FUN_00887da0(const char* fmt, ...);
void __cdecl FUN_00471830(Obj* root, Obj* node, Obj* c, Owner* owner, int slot, int e);
// Stand-in bodies for the string class's members, written from the image (set text 0x004019c0, format from a
// va_list 0x00403870, varargs format 0x00403a00): header code the original file could see.
__declspec(noinline) bool String::FUN_004019c0(const char* text, unsigned int length)
{
    unsigned int textLength = text ? (unsigned int)strlen(text) : 0;
    if (textLength > length)
        length = textLength;
    if (length > cap)
    {
        char* old = ptr;
        ptr = (char*)DAT_01090a78.FUN_0086b930(length + 1);
        if (text)
            memmove(ptr, text, textLength + 1);
        else
            *ptr = 0;
        if (old)
            DAT_01090a78.FUN_0086ba60(old);
        cap = (unsigned short)(length > 0xffff ? 0xffff : length);
    }
    else if (!length)
    {
        if (ptr)
            DAT_01090a78.FUN_0086ba60(ptr);
        ptr = 0;
        cap = 0;
    }
    else if (text)
        memmove(ptr, text, textLength + 1);
    else
        *ptr = 0;
    len = (unsigned short)(textLength > 0xffff ? 0xffff : textLength);
    return textLength != 0;
}

__declspec(noinline) int String::FormatArgs(const char* format, va_list args)
{
    char buffer[1024];
    int length = vsprintf(buffer, format, args);
    FUN_004019c0(buffer, 0);
    return length;
}

__declspec(noinline) int __cdecl FUN_00403a00(String* out, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    return out->FormatArgs(fmt, args);
}
void __cdecl TESObjectREFR_AddAddonNodes(Obj* n);
void __cdecl FUN_00542160(int k, Obj* n);

// NiPointer<T>::operator= (0x8e9650) is header template code, so its body was visible in the original file.
// Without it the loaded clone's smart pointer counts as escaped and this/pForm get ebx/ebp exchanged.
__declspec(noinline) void SmartPtr::FUN_008e9650(Obj* p)
{
    Obj* old = object;
    if (old != p) {
        if (old && InterlockedDecrement(&old->refCount) == 0)
            old->DeleteThis();
        object = p;
        if (p)
            InterlockedIncrement(&p->refCount);
    }
}

// Same source file, compiled before FUN_00473ea0: with the body visible the compiler knows it only clobbers eax,
// so ecx still holds this for the FUN_00471b70 call (target +0x4ff).
__declspec(noinline) bool Owner::FUN_004708a0(int slot)
{
    Model* m = entries[slot].form;
    return m && (m->flags & 1);
}

static __forceinline void RemoveScene(Obj* s)
{
    if (s) {
        FUN_00478bb0(s);
        DAT_0116efb8->FUN_00ae1a30(s);
        if (s->parent) {
            FUN_008d7720(s, 1, 0);
            s->parent->DetachChild(s);
        }
    }
}

void Owner::ReleasePending(Entry& pend)
{
    if (pend.scene) {
        FUN_00471020(pend.scene);
        if (!FUN_00724400())
            RemoveScene(pend.scene);
        else
            DAT_0107a79c->FUN_006f2440(pend.scene);
        const char* path = pend.form->GetPath();
        DAT_0106ca70->FUN_00429640(path, true, true);
        pend.scene = 0;
    }
    pend.owner = 0;
    pend.form = 0;
}

// pdb: BipedAnim::LoadBipedParts | BipedAnim.obj | fnv360_0822_retail, ustr, medium
// pdb params: abForceLoadImmediate
void Owner::FUN_00473ea0(bool deferred)
{
    bool isPlayerX = false;
    bool hasC = entries[6].owner != 0;
    if (actor == DAT_0107a104 && DAT_0107a104->FUN_0076cd40(this))
        isPlayerX = true;
    if (DAT_0106e30c)
        FUN_0058aa00(actor->GetObjectReference());
    for (int i = 0; i < 20; i++) {
        if (entries[i].form && entries[i].form == pending[i].form && entries[i].owner == pending[i].owner && pending[i].scene) {
            entries[i] = pending[i];
            memset(&pending[i], 0, sizeof(Entry));
            if (DAT_0106e30c && entries[i].scene) {
                Obj* n = entries[i].scene->GetAsNode();
                if (n) {
                    for (unsigned j = 0; j < n->childCount; j++) {
                        Obj* child = n->children[j];
                        // Guess at the source: an identical-arms select (both arms are the child). The arms merge after
                        // register allocation and leave no code; it gives the child its own register (eax) as in the
                        // target, where a plain argument takes the next scratch register (edx).
                        FUN_004730a0(deferred ? child : child, 0);
                    }
                }
            }
            if (i == 7 && entries[5].owner && (entries[5].owner->flags100 & 0x10) && entries[i].scene)
                entries[i].scene->flags |= 1;
        } else {
        Entry& cur = entries[i];
        if (pending[i].scene)
            ReleasePending(pending[i]);
        else
            memset(&pending[i], 0, sizeof(Entry));
        if (i == 5 && entries[5].owner) {
            Form0* w = entries[5].owner;
            if (actor == DAT_0107a104) {
                FUN_004724d0(w);
                if ((w->flags100 & 4) && this == DAT_0107a104->FUN_0076cd20(false))
                    FUN_0061aaf0((char*)w + 0x1a4);
            } else {
                actor->FUN_004f5750(w);
            }
            continue;
        }
        Model* form = entries[i].form;
        if (!form || form == (Model*)-1)
            continue;
        if (isPlayerX && (i < 2 || i > 6))
            continue;
        if (!deferred && (form->flags & 1) && actor != DAT_0107a104 && DAT_0106e534 && DAT_01073a60 && FUN_004706c0()) {
            FUN_00471e50(0, 0, i);
            continue;
        }
        if (form->GetLength() == 0)
            continue;
        int slotIdx = DAT_00f4c3d0[i];
        unsigned char flags = form->flags;   // guess: a named copy supplies the one scratch turn the original has here
        ModelForm* model = DAT_0106ca70->FUN_00429eb0(form->GetPath(), 3, 1, 0, flags & 1, 0);
        LoadOptions options(0x101);
        SmartPtr retained;
        Obj* scene;
        if (FUN_00478250(model)) {
            retained.FUN_008e9650(DAT_0107a0d8->FUN_00435e70(model, &options));
            scene = retained.object;
        } else {
            scene = model->FUN_008257a0(&options);
        }
        Obj* node = scene->GetAsNode();
        if (node) {
        if (entries[i].form) {
            Root* root2 = (entries[i].form)->GetRoot();
            if (root2)
                root2->TESModelTextureSwap_SwapTextures(node);
        }
        if (cur.owner && cur.owner->CheckUpdate())
            FUN_00479030(node);
        Obj3* x = node->V10();
        if (x)
            x->FUN_00ad2840(7);
        node->translation = DAT_0108ec68;
        node->rotation = DAT_00f72574;
        Obj* attached = FUN_00473ab0(node, i, isPlayerX, hasC, 0);
        if (!attached) {
            attached = node;
            if (FUN_004708a0(i)) {
                Picker* picker = FUN_00471b70(i);
                if (picker) {
                    for (unsigned j = 0; j < node->childCount; j++) {
                        Obj* o = node->children[j]->V1c();
                        if (!o) {
                            FUN_00887da0(DAT_00dc0218, (entries[i].form)->GetPath());
                            continue;
                        }
                        if (o->unkb8 && actor && actor->unk1c && actor->unk1c->type == 0x2a) {
                            Npc* npc = actor->unk1c;
                            Element24 arr[4];
                            Retained a;
                            Retained b;
                            o->unkb8->FUN_00825970(&a);
                            b.FUN_008e9650(a.object);
                            o->VE4(b.object);
                            npc->FUN_00554d10(arr);
                            if (!DAT_01073a60 || picker->FUN_00596070(arr, o, 0)) {
                                Mat3 rot;
                                rot.FUN_00423fd0(DAT_00db8850);
                                o->rotation = o->rotation.FUN_00424020(rot);
                            }
                        }
                    }
                }
            }
            FUN_00471830(root, node, 0, this, i, 0);
            if (!DAT_01079ca4->FUN_008257f0() && i == 5) {
                Actor* a = actor;
                if (a->process) {
                    if (a == DAT_0107a104 && this == DAT_0107a104->FUN_0076cd20(true)) {
                        Process* proc = a->process;
                        proc->UpdateWeaponDrawn(a->FUN_006f6c70(), this, DAT_0107a104->FUN_0076cce0(true), a);
                    } else {
                        Process* proc = a->process;
                        proc->UpdateWeaponDrawn(a->FUN_006f6c70(), this, a->Actor_GetAnimation(), a);
                    }
                }
            }
        }
        String str;
        FUN_00403a00(&str, DAT_00dbfeb4, DAT_00f4c380[i], cur.owner->GetEditorID(), cur.owner->GetFormID());
        ((NameTarget*)attached)->FUN_008245d0(FixedStr(str.ptr));
        Extra* extra = model->FUN_00824a50(DAT_0116d6e0);
        if (extra && extra->IsFlag4())
            TESObjectREFR_AddAddonNodes(node);
        if (!cur.hidden && attached->GetAsNode()) {
            Obj* parent = attached->parent;
            if (slotIdx == -1) {
                FUN_00887da0(DAT_00dc01e0, (entries[i].form)->GetPath(), actor->FUN_004e9a10());
                if (parent) {
                    parent->DetachChild(attached);
                } else {
                    Retained tmp(attached);
                }
                attached = 0;
            } else {
                if (pairs[slotIdx].node)
                    pairs[slotIdx].node->AttachChild(attached, true);
                else if (parent)
                    root->AttachChild(attached, true);
            }
        }
        SlotList* list = actor->unk40.FUN_0040e570();
        if (list) {
            for (int k = 0; k < 15; k++) {
                if (list->FUN_0041cb90(k))
                    FUN_00542160(k, attached);
            }
        }
        if (i == 7 && entries[5].owner && (entries[5].owner->flags100 & 0x10) && attached)
            attached->flags |= 1;
        cur.scene = attached;
        }
        }
    }
    actor->Get3DSimple()->FUN_008268a0();
}

}

// @f3 0x00469230 (community match, verified in this file)
#include <math.h>
// Decal projection camera update. Structure from fnv_decomp src\fallout_shared\bgsdecalmanager.cpp
// CameraPass::Camera::UpdateCamera (New Vegas 0x004a04c0). Vec3::Unitize is FUN_00468d00 of the same unit.
namespace D469230 {

struct Vec3
{
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    void Unitize();
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
};

void Vec3::Unitize()
{
    float length = sqrtf(x * x + y * y + z * z);
    if (length > 1e-06f)
    {
        float inv = 1.0f / length;
        x *= inv;
        y *= inv;
        z *= inv;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}

struct Mat3
{
    float m[3][3];
    Mat3() {}
    void MakeZRotation(float angle)
    {
        float sn, cs;
        fnv_SinCos(angle, sn, cs);
        m[0][0] = cs;
        m[0][1] = sn;
        m[0][2] = 0.0f;
        m[1][0] = -sn;
        m[1][1] = cs;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
    }
    Mat3 Multiply(const Mat3& o) const;
    void GetRow(int i, Vec3& v) const
    {
        v.x = m[i][0];
        v.y = m[i][1];
        v.z = m[i][2];
    }
    void GetCol(int i, Vec3& v) const
    {
        v.x = m[0][i];
        v.y = m[1][i];
        v.z = m[2][i];
    }
    void SetCol(int i, const Vec3& v)
    {
        m[0][i] = v.x;
        m[1][i] = v.y;
        m[2][i] = v.z;
    }
};

void FUN_00aab4a0(Mat3* out, Vec3 dir);

struct Color
{
    float r, g, b, a;
    Color(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};

struct RefObject
{
    virtual ~RefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { ::InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (::InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiFrustum
{
    float m_fLeft, m_fRight, m_fTop, m_fBottom, m_fNear, m_fFar;
    bool m_bOrtho;
    NiFrustum(bool ortho);
};

struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdateControllers;
    bool m_bIsMultiThreaded;
    bool m_bUpdateGeomorphs;
    bool m_bUpdateShadowSceneNode;
    bool m_bUpdateNodeOnly;
    NiUpdateData(float t, bool a, bool b)
        : m_fTime(t), m_bUpdateControllers(a), m_bIsMultiThreaded(b), m_bUpdateGeomorphs(false),
          m_bUpdateShadowSceneNode(false), m_bUpdateNodeOnly(false)
    {
    }
};

struct NiAVObject : RefObject
{
    const char* m_kName;
    int unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030;
    Mat3 m_localRotate;
    Vec3 m_localTranslate;
    float m_localScale;
    Mat3 m_worldRotate;
    Vec3 m_worldTranslate;
    float m_worldScale;
    void Update(NiUpdateData& data);
    void SetTranslate(const Vec3& t) { m_localTranslate = t; }
    void SetRotate(const Mat3& r) { m_localRotate = r; }
    const char* GetName() const { return m_kName; }
    float GetWorldScale() const { return m_worldScale; }
};

struct NiCamera : NiAVObject
{
    int unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc;
    int unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int m_kPort;
    void UpdateViewFrustum(const NiFrustum& frustum);
    Vec3 GetWorldDirection() const
    {
        Vec3 dir;
        m_worldRotate.GetCol(0, dir);
        return dir;
    }
};

struct ShadowSceneNode;
extern ShadowSceneNode* DAT_0116efb8;

struct ShaderAccum : RefObject
{
    int unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038;
    int unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0;
    int unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4;
    int unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108;
    int unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170;
    int unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190;
    ShadowSceneNode* m_pkShadowSceneNode;
    int unk198;
    int m_iRenderMode;
    void SetShadowSceneNode(ShadowSceneNode* node) { m_pkShadowSceneNode = node; }
    void SetRenderMode(int mode) { m_iRenderMode = mode; }
};

struct NiRenderTargetGroup;
struct BSRenderedTexture : RefObject
{
    NiRenderTargetGroup* GetGroup();
};

struct Renderer;
struct RenderTargetManager
{
    BSRenderedTexture* GetRenderTarget(Renderer* renderer, int type, int a, int b, int c);
};
extern RenderTargetManager* DAT_0116ef98;
extern Renderer* DAT_0116f2f8;

bool FUN_00aeec60(int target, NiRenderTargetGroup* group);

struct MemoryManager
{
    void* RawAllocate(unsigned int size);
    void Deallocate(void* p);
};
extern MemoryManager DAT_01090a78;

struct Query
{
    unsigned int unk0;
    Query();
    void Begin();
    void End();
    void* operator new(unsigned int size) { return DAT_01090a78.RawAllocate(size); }
    void operator delete(void* p) { DAT_01090a78.Deallocate(p); }
};

struct ShaderManager
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0a(); virtual void v0b(); virtual void v0c(); virtual void v0d(); virtual void v0e();
    virtual void v0f(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v1a(); virtual void v1b(); virtual void v1c(); virtual void v1d();
    virtual void v1e(); virtual void v1f(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2a(); virtual void v2b(); virtual void v2c();
    virtual void v2d(); virtual void v2e(); virtual void v2f(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3a(); virtual void v3b();
    virtual void v3c(); virtual void v3d(); virtual void v3e(); virtual void v3f(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v4a();
    virtual void v4b(); virtual void v4c(); virtual void v4d(); virtual void v4e(); virtual void v4f();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5a(); virtual void v5b(); virtual void v5c(); virtual void v5d(); virtual void v5e();
    virtual void v5f(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void SetViewport(int* port);
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034;
    int unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068;
    int unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0;
    int unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104;
    int unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138;
    int unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c;
    int unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0;
    int unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4;
    int unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int m_iMode;
    int unk204;
    char m_cEnabled;
    void ApplyViewport(int* port)
    {
        if ((m_iMode == 1 || m_iMode == 2) && m_cEnabled == 1)
            SetViewport(port);
    }
};
extern ShaderManager* DAT_0108f048;

struct CullingProcess
{
    virtual ~CullingProcess();
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034;
    int unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068;
    int unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    CullingProcess(void* visibleSet);
};

struct DecalCullingProcess : CullingProcess
{
    int unk090;
    int unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8;
    int unk0bc;
    int unk0c0;
    NiPointer<ShaderAccum> m_spAccumulator;
    DecalCullingProcess() : CullingProcess(0), unk090(0), unk0bc(0), unk0c0(0) {}
    virtual ~DecalCullingProcess();
    void SetAccumulator(ShaderAccum* accum) { m_spAccumulator = accum; }
};

void FUN_00aef280(NiCamera* camera, NiAVObject* root, DecalCullingProcess* cull);
struct BSShaderRenderUtility
{
    static void SetRenderCamera(NiCamera* camera, ShaderAccum* accum, bool flag);
};
void FUN_00aeeb20();

void* FUN_0047a4e0(const Vec3& start, const Color& c0, const Vec3& end, const Color& c1, int flag);
struct World
{
    void FUN_00433df0(void* line, float time);
};
extern World* DAT_0107a0d8;
extern float DAT_00db99c8;
extern unsigned int DAT_0106df04;

struct SettingB
{
    void* vtbl;
    bool value;
    bool* Get() { return &value; }
};
extern SettingB DAT_0106dfdc;

void FUN_00887da0(const char* fmt, ...);

struct DecalInput
{
    int unk000, unk004, unk008, unk00c, unk010, unk014;
    char unk018, unk019, unk01a;
    bool m_bAlternate;
    Query* m_pQuery;
    int unk020, unk024, unk028, unk02c, unk030;
    Vec3 m_kPosition;
    Vec3 m_kDirection;
    int unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0;
    int unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4;
    int unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108;
    NiAVObject* m_pkRoot;
    int unk110;
    float m_fAngle;
    float m_fWidth;
    float m_fHeight;
    float m_fDepth;
    Vec3 GetDirection() const { return m_kDirection; }
    Vec3 GetPosition() const { return m_kPosition; }
    float GetAngle() const { return m_fAngle; }
    float GetWidth() const { return m_fWidth; }
    float GetHeight() const { return m_fHeight; }
    float GetDepth() const { return m_fDepth; }
    NiAVObject* GetRoot() const { return m_pkRoot; }
};

struct DecalCamera
{
    NiPointer<BSRenderedTexture> m_spTexture;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    NiPointer<ShaderAccum> m_spAccumulator;
    NiPointer<NiCamera> m_spCamera;
    void FUN_00469230(DecalInput* input);
};

}

using namespace D469230;

// pdb: BGSDecalManager::IssueDecalOcclusionQuery | BGSDecalManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: apDecal
void DecalCamera::FUN_00469230(DecalInput* input)
{
    Vec3 direction = input->GetDirection();
    direction.Unitize();
    direction.x = direction.x * 50.0;
    direction.y = direction.y * 50.0;
    direction.z = direction.z * 50.0;
    Vec3 origin = input->GetPosition() + direction;
    Mat3 rotation;
    FUN_00aab4a0(&rotation, -direction);
    {
        Mat3 scale;
        scale.MakeZRotation(input->GetAngle());
        rotation = scale.Multiply(rotation);
    }
    Vec3 column0;
    Vec3 column1;
    rotation.GetRow(0, column0);
    rotation.GetRow(1, column1);
    rotation.GetRow(2, direction);
    Mat3 basis;
    basis.SetCol(0, direction);
    basis.SetCol(1, column0);
    basis.SetCol(2, column1);
    Vec3 start;
    Vec3 end;
    float width = (input->GetWidth() / 2.0) * (1.0f / input->GetRoot()->GetWorldScale());
    float height = (input->GetHeight() / 2.0) * (1.0f / input->GetRoot()->GetWorldScale());
    float farPlane = input->GetDepth() + 50.0;
    NiFrustum frustum(false);
    frustum.m_bOrtho = true;
    frustum.m_fNear = 0.1f;
    frustum.m_fLeft = -width;
    frustum.m_fRight = width;
    frustum.m_fTop = height;
    frustum.m_fBottom = -height;
    frustum.m_fFar = farPlane;
    m_spCamera->SetTranslate(origin);
    m_spCamera->SetRotate(basis);
    m_spCamera->UpdateViewFrustum(frustum);
    NiUpdateData update(0.0f, false, false);
    m_spCamera->Update(update);
    void* line;
    if (DAT_0106df04 & 4)
    {
        start = origin;
        end = origin + m_spCamera->GetWorldDirection() * farPlane;
        line = FUN_0047a4e0(start, Color(0.0f, 0.0f, 1.0f, 1.0f), end, Color(1.0f, 0.0f, 0.0f, 1.0f), 1);
        DAT_0107a0d8->FUN_00433df0(line, DAT_00db99c8);
    }
    if (*DAT_0106dfdc.Get())
    {
        Vec3 look = m_spCamera->GetWorldDirection();
        FUN_00887da0("DECAL: Issuing Occlusion Query: %s", input->GetRoot()->GetName());
        FUN_00887da0("DECAL: Origin: (%.2f, %.2f, %.2f)", origin.x, origin.y, origin.z);
        FUN_00887da0("DECAL: Direction: (%.2f, %.2f, %.2f)", look.x, look.y, look.z);
        FUN_00887da0("DECAL: Frustum: Near=0.1f, Far=%.2f, Left=%.2f, Right=%.2f, Top=%.2f, Bottom=%.2f )", farPlane,
                     -width, width, height, -height);
    }
    if (!m_spTexture)
        m_spTexture = DAT_0116ef98->GetRenderTarget(DAT_0116f2f8, 0x32, 0, 0, 0);
    if (input->m_bAlternate)
        FUN_00aeec60(7, m_spTexture->GetGroup());
    else
        FUN_00aeec60(0, m_spTexture->GetGroup());
    input->m_pQuery = new Query;
    input->m_pQuery->Begin();
    DAT_0108f048->ApplyViewport(&m_spCamera->m_kPort);
    DecalCullingProcess cull;
    cull.SetAccumulator(m_spAccumulator);
    m_spAccumulator->SetShadowSceneNode(DAT_0116efb8);
    m_spAccumulator->SetRenderMode(15);
    FUN_00aef280(m_spCamera, input->GetRoot(), &cull);
    BSShaderRenderUtility::SetRenderCamera(m_spCamera, m_spAccumulator, false);
    cull.SetAccumulator(0);
    input->m_pQuery->End();
    FUN_00aeeb20();
}

// @f3 0x004655b0 (community match, verified in this file)
#include <cmath>
#include <windows.h>

namespace h_4655b0 {

struct NiPoint3 {
    union {
        struct {
            float x, y, z;
        };
        float components[3];
    };
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

using f3m_00466b80::DAT_01090a78;

// BSSimpleArray<NiPoint3,1024>
struct PointArray;
struct PointArray {
    virtual ~PointArray();
    virtual NiPoint3* allocate(unsigned int n);
    virtual void release(NiPoint3* p);
    NiPoint3* buffer;
    unsigned int size;
    unsigned int capacity;
    PointArray() { _InitialSetup(0, 0); }
    static void* operator new(size_t n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    void _InitialSetup(unsigned int aiReserveSize, unsigned int aiInitialSize)
    {
        buffer = 0;
        size = 0;
        capacity = 0;
        if (aiInitialSize > aiReserveSize)
            aiReserveSize = aiInitialSize;
        if (aiReserveSize > 0) {
            buffer = allocate(aiReserveSize);
            capacity = aiReserveSize;
        }
        if (aiInitialSize > 0)
            size = aiInitialSize;
    }
    void FUN_0079ecc0(unsigned int aiNewSize, unsigned int aiCount);                       // _Reallocate
    unsigned int FUN_007a1650();                                                           // AddUninitialized
    void FUN_004652f0(unsigned int aiIndex, const NiPoint3& aValue);                    // Insert
    void FUN_004653e0(unsigned int aiIndex, unsigned int aiCount, bool abShrink);         // RemoveRange
    void FUN_0079e680(NiPoint3* apDst, const NiPoint3* apSrc, unsigned int aiCount);  // _CopyItems
    unsigned int GetSize() { return size; }
    NiPoint3& GetAt(int i) { return buffer[i]; }
    NiPoint3& GetFirst() { return buffer[0]; }
    NiPoint3& GetLast() { return buffer[size - 1]; }
    __forceinline unsigned int AddItem(const NiPoint3& aItem)
    {
        if (size == capacity) {
            if (capacity == 0) {
                buffer = allocate(4);
                capacity = 4;
            } else {
                unsigned int iNewSize;
                if (capacity > 1024)
                    iNewSize = capacity + 1024;
                else
                    iNewSize = capacity * 2;
                FUN_0079ecc0(iNewSize, size);
                capacity = iNewSize;
            }
        }
        size++;
        unsigned int i = size - 1;
        buffer[i] = aItem;
        return i;
    }
};
extern PointArray* DAT_0106dedc;

void PointArray::FUN_004652f0(unsigned int aiIndex, const NiPoint3& aValue)
{
    if (aiIndex == size) {
        buffer[FUN_007a1650()] = aValue;
        return;
    }
    if (size == capacity) {
        unsigned int iNewSize;
        if (capacity > 0x400)
            iNewSize = capacity + 0x400;
        else
            iNewSize = capacity * 2;
        NiPoint3* pNewBuffer = allocate(iNewSize);
        FUN_0079e680(pNewBuffer, buffer, aiIndex);
        FUN_0079e680(pNewBuffer + aiIndex + 1, buffer + aiIndex, size - aiIndex);
        release(buffer);
        buffer = pNewBuffer;
        capacity = iNewSize;
    } else {
        FUN_0079e680(buffer + aiIndex + 1, buffer + aiIndex, size - aiIndex);
    }
    size++;
    buffer[aiIndex] = aValue;
}


const float DAT_00db75c8 = 0.01f;

bool IsApproximatelyEqual(float afA, float afB, float afEpsilon)
{
    return std::abs(afA - afB) <= afEpsilon;
}

bool CloseTo(const NiPoint3& arP1, const NiPoint3& arP2, float afEpsilon)
{
    return IsApproximatelyEqual(arP1.x, arP2.x, afEpsilon) && IsApproximatelyEqual(arP1.y, arP2.y, afEpsilon) &&
           IsApproximatelyEqual(arP1.z, arP2.z, afEpsilon);
}

struct TESObjectLAND {
    NiPoint3 FUN_004c8ff0(int aiBlock);  // GetWorldOffsetForBlock
};
struct TESObjectCELL {
    TESObjectLAND* TESObjectCELL_GetLand();  // GetLand
    float FUN_004d5350();           // GetWaterHeight
};

// BSPolygon2D (0x40 bytes)
struct FUN_00aad1b0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int iNumVertices;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    FUN_00aad1b0(PointArray* apOutline);
    void FUN_00aac030();  // RemoveZ
    void FUN_00aac8e0();  // Triangulate
    ~FUN_00aad1b0();  // ~BSPolygon2D
    int GetNumVertices() { return iNumVertices; }
    static void* operator new(size_t n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

bool __cdecl FUN_004651d0(FUN_00aad1b0* apPoly1, FUN_00aad1b0* apPoly2);

// NiTPointerList<BSPolygon2D*> and its pool (NiTPointerAllocator<unsigned int>)
struct ListItem {
    ListItem* m_pkNext;
    ListItem* m_pkPrev;
    FUN_00aad1b0* m_element;
};
// the pool's lock (layout as the New Vegas tree's RecursiveSpinLock.h; Fallout 3 releases it with an interlocked exchange)
struct RecursiveSpinLock {
    volatile LONG m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    void FUN_00409a80(int);  // Lock
    void Unlock()
    {
        if (--m_uiRecursionCount == 0)
        {
            LONG owner = m_uiOwningThreadID;
            InterlockedCompareExchange(&m_uiOwningThreadID, 0, owner);
        }
    }
};
extern RecursiveSpinLock DAT_0106e5a0;
extern ListItem* DAT_0106e588;
void __cdecl FUN_00422ab0();  // CreateFreeMem

__forceinline ListItem* Allocate()
{
    DAT_0106e5a0.FUN_00409a80(0);
    if (!DAT_0106e588)
        FUN_00422ab0();
    ListItem* pTmp = DAT_0106e588;
    DAT_0106e588 = DAT_0106e588->m_pkNext;
    pTmp->m_element = 0;
    pTmp->m_pkNext = 0;
    pTmp->m_pkPrev = 0;
    DAT_0106e5a0.Unlock();
    return pTmp;
}

struct PolyList {
    ListItem* m_pkHead;
    ListItem* m_pkTail;
    unsigned int m_uiCount;
    PolyList() { m_uiCount = 0; m_pkHead = 0; m_pkTail = 0; }
    static void* operator new(size_t n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    __forceinline void AddHead(FUN_00aad1b0* const& element)
    {
        ListItem* pkNode = Allocate();
        pkNode->m_element = element;
        pkNode->m_pkPrev = 0;
        pkNode->m_pkNext = m_pkHead;
        if (m_pkHead)
            m_pkHead->m_pkPrev = pkNode;
        else
            m_pkTail = pkNode;
        m_pkHead = pkNode;
        m_uiCount++;
    }
    FUN_00aad1b0* FUN_005878f0();             // RemoveHead
    FUN_00aad1b0* FUN_00469b60();             // RemoveTail
    void FUN_00ade560(ListItem* pkNode);      // DeleteItem
    FUN_00aad1b0* FUN_00496910(ListItem*& pos);  // RemovePos
};
extern PolyList* DAT_0106dee0;

FUN_00aad1b0* PolyList::FUN_00496910(ListItem*& pos)
{
    ListItem* pkNode = pos;
    if (pkNode == m_pkHead) {
        pos = pkNode->m_pkNext;
        return FUN_005878f0();
    }
    if (pkNode == m_pkTail) {
        pos = 0;
        return FUN_00469b60();
    }
    ListItem* pkPrev = pkNode->m_pkPrev;
    ListItem* pkNext = pkNode->m_pkNext;
    pos = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    FUN_00aad1b0* element = pkNode->m_element;
    FUN_00ade560(pkNode);
    m_uiCount--;
    return element;
}

struct MemContext {
    int saved;
    MemContext(int tag) { saved = f3m_00464330::g_tls.allocTag; f3m_00464330::g_tls.allocTag = tag; }
    ~MemContext() { f3m_00464330::g_tls.allocTag = saved; }
};

// pdb: BGSAutoWater::GeneratePolygons | BGSAutoWater.obj | fnv360_0822_retail, call_gap, low
// pdb params: apCell
void __cdecl FUN_004655b0(TESObjectCELL* apCell)
{
    MemContext tempMemContext(0x1d);
    while (DAT_0106dedc->GetSize() > 0) {
        PointArray* poutline = new PointArray;
        poutline->AddItem(DAT_0106dedc->GetAt(0));
        poutline->AddItem(DAT_0106dedc->GetAt(1));
        DAT_0106dedc->FUN_004653e0(0, 2, true);
        bool bfound = true;
        bool bclosed = false;
        while (bfound) {
            bfound = false;
            int i = 0;
            while (i < (int)DAT_0106dedc->GetSize()) {
                NiPoint3 v0 = DAT_0106dedc->GetAt(i);
                NiPoint3 v1 = DAT_0106dedc->GetAt(i + 1);
                if (CloseTo(v0, poutline->GetLast(), DAT_00db75c8) && !CloseTo(v1, poutline->GetFirst(), DAT_00db75c8) &&
                    !CloseTo(v1, poutline->GetAt(poutline->GetSize() - 2), DAT_00db75c8)) {
                    poutline->AddItem(v1);
                    DAT_0106dedc->FUN_004653e0(i, 2, true);
                    bfound = true;
                    break;
                } else if (CloseTo(v1, poutline->GetLast(), DAT_00db75c8) &&
                           !CloseTo(v0, poutline->GetFirst(), DAT_00db75c8) &&
                           !CloseTo(v0, poutline->GetAt(poutline->GetSize() - 2), DAT_00db75c8)) {
                    poutline->AddItem(v0);
                    DAT_0106dedc->FUN_004653e0(i, 2, true);
                    bfound = true;
                    break;
                } else if (CloseTo(v0, poutline->GetFirst(), DAT_00db75c8) &&
                           !CloseTo(v1, poutline->GetLast(), DAT_00db75c8) &&
                           !CloseTo(v1, poutline->GetAt(1), DAT_00db75c8)) {
                    poutline->FUN_004652f0(0, v1);
                    DAT_0106dedc->FUN_004653e0(i, 2, true);
                    bfound = true;
                    break;
                } else if (CloseTo(v1, poutline->GetFirst(), DAT_00db75c8) &&
                           !CloseTo(v0, poutline->GetLast(), DAT_00db75c8) &&
                           !CloseTo(v0, poutline->GetAt(1), DAT_00db75c8)) {
                    poutline->FUN_004652f0(0, v0);
                    DAT_0106dedc->FUN_004653e0(i, 2, true);
                    bfound = true;
                    break;
                } else if ((CloseTo(v0, poutline->GetLast(), DAT_00db75c8) &&
                            CloseTo(v1, poutline->GetFirst(), DAT_00db75c8)) ||
                           (CloseTo(v0, poutline->GetFirst(), DAT_00db75c8) &&
                            CloseTo(v1, poutline->GetLast(), DAT_00db75c8))) {
                    bclosed = true;
                    i += 2;
                } else {
                    i += 2;
                }
            }
        }
        NiPoint3 worldtranslate(apCell->TESObjectCELL_GetLand()->FUN_004c8ff0(0).x, apCell->TESObjectCELL_GetLand()->FUN_004c8ff0(0).y, apCell->FUN_004d5350());
        if (bclosed) {
            FUN_00aad1b0* pnewPoly = new FUN_00aad1b0(poutline);
            if (pnewPoly->GetNumVertices() > 2) {
                pnewPoly->FUN_00aac030();
                pnewPoly->FUN_00aac8e0();
                if (!DAT_0106dee0)
                    DAT_0106dee0 = new PolyList;
                DAT_0106dee0->AddHead(pnewPoly);
            } else {
                delete pnewPoly;
            }
        } else {
            delete poutline;
        }
    }
    if (DAT_0106dee0) {
        ListItem* iter = DAT_0106dee0->m_pkHead;
        while (iter) {
            ListItem* next = iter ? iter->m_pkNext : 0;
            if (iter) {
                FUN_00aad1b0* ppoly1 = iter->m_element;
                ListItem* polyiter = DAT_0106dee0->m_pkHead;
                while (polyiter) {
                    ListItem* polynext = polyiter ? polyiter->m_pkNext : 0;
                    if (polyiter) {
                        FUN_00aad1b0* ppoly2 = polyiter->m_element;
                        if (ppoly1 != ppoly2 && FUN_004651d0(ppoly1, ppoly2)) {
                            DAT_0106dee0->FUN_00496910(iter);
                            break;
                        }
                    }
                    polyiter = polynext;
                }
            }
            iter = next;
        }
    }
}

}

// @f3 0x0046fbd0 (community match, verified in this file)
#include <string.h>

// BGSSceneInfo::CollectSceneDataForLoadedArea (New Vegas twin: fnv_decomp
// src\fallout_shared\bgssceneinfo.cpp, @fnv 0x004a8bb0).

namespace f3w_0046fbd0 {

struct MemoryManager
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};
extern MemoryManager DAT_01090a78;
void* __cdecl FUN_0089e810(unsigned int size);

struct NiNode;
struct TESObjectCELL
{
    NiNode* FUN_004d5230();
};

struct GridCellArray
{
    TESObjectCELL** FUN_0047b220(unsigned int x, unsigned int y);
};

struct TES
{
    int unk00;
    int unk04;
    GridCellArray* pGridCellArray;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    TESObjectCELL* pInteriorCell;

    TESObjectCELL* GetInteriorCell() { return pInteriorCell; }
    TESObjectCELL** GetGridCell(unsigned int x, unsigned int y) { return pGridCellArray->FUN_0047b220(x, y); }
};
extern TES* DAT_0107a0d8;

extern float gEmptySettingValue;

struct Setting
{
    void* vtbl;
    float fValue;

};
extern unsigned int DAT_0106e9cc;

inline float& __fastcall SettingFloat(Setting* setting)
{
    return setting ? setting->fValue : (gEmptySettingValue = 0.0f);
}

struct BudgetSlot
{
    Setting* pMultiplier;
    bool bDisabled;
    int unk08, unk0C, unk10;
};
extern BudgetSlot DAT_00f4be2c[16];

struct NiTMapGlobal
{
    void FUN_006bd950();
};
extern NiTMapGlobal DAT_00f4bf68;

void __cdecl FUN_0046fb10();

inline int MinInt(int iA, int iB)
{
    int result;
    if (iA < iB)
        result = iA;
    else
        result = iB;
    return result;
}

struct SceneInfo
{
    unsigned int counts[16];
    SceneInfo() { ClearToZero(); }
    void ClearToZero() { memset(this, 0, sizeof(SceneInfo)); }
};

class BGSSceneInfo;
struct BGSSceneInfoVtbl
{
    void (__thiscall* DeletingDtor)(BGSSceneInfo* apThis, unsigned int auiFlags);
};
extern const BGSSceneInfoVtbl DAT_00dbf218;

class BGSSceneInfo
{
public:
    const BGSSceneInfoVtbl* vtbl;
    SceneInfo info;
    TESObjectCELL* pCell;

    BGSSceneInfo() : vtbl(&DAT_00dbf218)
    {
        memset(&info, 0, sizeof(info));
        pCell = 0;
    }

    void SetCell(TESObjectCELL* apCell) { pCell = apCell; }
    void FUN_0046fa90(NiNode* apNode, bool abIncludeAddonNodes, bool abTrackActors);
    void FUN_0046f470(TESObjectCELL* apCell);
    unsigned int GetValueAt(int index)
    {
        if (index >= 0 && index < 16)
            return info.counts[index];
        return 0;
    }
    float GetScaledSlotValue(int iSlot)
    {
        if (iSlot >= 0 && iSlot < 16 && DAT_00f4be2c[iSlot].pMultiplier)
            return ((float)GetValueAt(iSlot) * SettingFloat(DAT_00f4be2c[iSlot].pMultiplier));
        return 0.0f;
    }

    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
};

struct NiTexture;
struct TEX_USER_DATA;
template <class TKEY, class TVAL> struct NiTMapItem;

extern int DAT_00dbf2a0;
extern int DAT_00dbf374;

template <class TKEY, class TVAL> class NiTMapBase
{
public:
    NiTMapBase(unsigned int uiHashSize = 37)
    {
        vtbl = &DAT_00dbf2a0;
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        m_ppkHashTable = (NiTMapItem<TKEY, TVAL>**)FUN_0089e810(sizeof(NiTMapItem<TKEY, TVAL>*) * uiHashSize);
        unsigned int uiSize = m_uiHashSize * sizeof(NiTMapItem<TKEY, TVAL>*);
        memset(m_ppkHashTable, 0, uiSize);
    }
    void* vtbl;
    unsigned int m_uiHashSize;
    NiTMapItem<TKEY, TVAL>** m_ppkHashTable;
    unsigned int m_uiCount;
};

template <class TKEY, class TVAL> class NiTMap : public NiTMapBase<TKEY, TVAL>
{
public:
    NiTMap(unsigned int uiHashSize = 37) : NiTMapBase<TKEY, TVAL>(uiHashSize) { this->vtbl = &DAT_00dbf374; }
};

class BGSTextureUseMap
{
public:
    TESObjectCELL* pCell;
    NiTMap<NiTexture*, TEX_USER_DATA*> kMap;

    BGSTextureUseMap() : kMap(37) {}
    ~BGSTextureUseMap();
    void FUN_00470600(NiNode* apNode, TESObjectCELL* apCell, int aiUnused);
    unsigned int FUN_0046ff60();
};

template <class T> class BSSimpleList
{
public:
    T m_item;
    BSSimpleList<T>* m_pkNext;

    BSSimpleList() : m_item(0), m_pkNext(0) {}
    BSSimpleList(T& item) : m_item(item), m_pkNext(0) {}
    ~BSSimpleList() { FUN_006c8220(); }
    void FUN_006c8220()
    {
        while (m_pkNext)
        {
            BSSimpleList<T>* next = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = next;
        }
        m_item = 0;
    }
    T& GetItem() { return m_item; }
    bool IsEmpty() { return !m_pkNext && !m_item; }
    void FUN_0049fac0(T& item)
    {
        if (!item)
            return;
        if (m_item)
        {
            BSSimpleList<T>* node = new BSSimpleList<T>(m_item);
            node->m_pkNext = m_pkNext;
            m_pkNext = node;
            m_item = item;
        }
        else
            m_item = item;
    }
    void RemoveHead()
    {
        if (m_pkNext)
        {
            BSSimpleList<T>* node = m_pkNext;
            m_pkNext = node->m_pkNext;
            m_item = node->m_item;
            node->m_pkNext = 0;
            delete node;
        }
        else
            m_item = 0;
    }

    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
};

// pdb: BGSSceneInfo::CollectSceneDataForLoadedArea | BGSSceneInfo.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afOutTNumber, afOutMNumber, abCollectTextures, abIncludeAddonNodes
void __cdecl FUN_0046fbd0(float* afOutTNumber, float* afOutMNumber, bool abCollectTextures, bool abIncludeAddonNodes)
{
    *afOutTNumber = 0.0f;
    *afOutMNumber = 0.0f;
    FUN_0046fb10();
    BGSTextureUseMap textureusemap;
    BSSimpleList<BGSSceneInfo*> cellinfolist;
    if (DAT_0107a0d8->GetInteriorCell())
    {
        TESObjectCELL* pcell = DAT_0107a0d8->GetInteriorCell();
        BGSSceneInfo* pinfo = new BGSSceneInfo;
        pinfo->SetCell(pcell);
        pinfo->FUN_0046fa90(pcell->FUN_004d5230(), abIncludeAddonNodes, false);
        pinfo->FUN_0046f470(pcell);
        textureusemap.FUN_00470600(pcell->FUN_004d5230(), pcell, 0);
        cellinfolist.FUN_0049fac0(pinfo);
    }
    else
    {
        unsigned int icenter = DAT_0106e9cc >> 1;
        unsigned int imin = icenter - MinInt(icenter, 2);
        unsigned int imax = icenter + MinInt(icenter, 2);
        for (unsigned int ix = imin; ix <= imax; ix++)
        {
            for (unsigned int iy = imin; iy <= imax; iy++)
            {
                TESObjectCELL* pgridcell = *DAT_0107a0d8->GetGridCell(ix, iy);
                if (pgridcell)
                {
                    BGSSceneInfo* pinfo = new BGSSceneInfo;
                    pinfo->SetCell(pgridcell);
                    pinfo->FUN_0046fa90(pgridcell->FUN_004d5230(), abIncludeAddonNodes, false);
                    textureusemap.FUN_00470600(pgridcell->FUN_004d5230(), pgridcell, 0);
                    pinfo->FUN_0046f470(pgridcell);
                    cellinfolist.FUN_0049fac0(pinfo);
                }
            }
        }
    }
    while (!cellinfolist.IsEmpty())
    {
        BGSSceneInfo* pinfo = cellinfolist.GetItem();
        cellinfolist.RemoveHead();
        *afOutMNumber += pinfo->GetValueAt(9);
        for (int i = 0; i < 16; i++)
        {
            if (!DAT_00f4be2c[i].bDisabled)
                *afOutTNumber += pinfo->GetScaledSlotValue(i);
        }
        pinfo->vtbl->DeletingDtor(pinfo, 1);
    }
    if (abCollectTextures)
        *afOutMNumber += textureusemap.FUN_0046ff60();
    DAT_00f4bf68.FUN_006bd950();
}
}

// @f3 0x00471570 (community match, verified in this file)
namespace f3m_00471570 {
namespace n471570 {
struct Scene;

struct Model {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual const char* GetPath();
};

struct BipedObject {
    void* parent;
    Model* model;
    Scene* scene;
    unsigned char hasAnimation;
};

struct TaskQueue {
    void FUN_006f2440(Scene* scene);
};

struct ModelLoader {
    void FUN_00429640(const char* path, bool a, bool b);
};
}

bool __cdecl FUN_00724400();
void __cdecl FUN_00470770(n471570::Scene* scene);

struct BipedAnim_471570 {
    void FUN_00471020(n471570::Scene* scene);
    void FUN_00471570(n471570::BipedObject* part, bool clear, n471570::Model* replacement);
};

// pdb: BipedAnim::RemovePart | BipedAnim.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObj, abClear, aiClearValue
void BipedAnim_471570::FUN_00471570(n471570::BipedObject* part, bool clear, n471570::Model* replacement)
{
    if (part->scene) {
        FUN_00471020(part->scene);
        if (!FUN_00724400()) {
            FUN_00470770(part->scene);
        } else {
            reinterpret_cast<n471570::TaskQueue*&>(::DAT_0107a79c)->FUN_006f2440(part->scene);
        }
        const char* path = part->model->GetPath();
        reinterpret_cast<n471570::ModelLoader*&>(::DAT_0106ca70)->FUN_00429640(path, true, true);
        part->scene = 0;
    }
    if (clear) {
        part->parent = 0;
        part->model = replacement;
    }
}
}   // namespace f3m_00471570

// @f3 0x00471550 (community match, verified in this file)
namespace f3m_00471550 {
namespace f3m_00471550 {
struct Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
    float unk14;
    float unk18;
    void FUN_00471430(int flags);
    Obj* FUN_00471550(float value);
};
// pdb: BSCloningProcess::BSCloningProcess | BipedAnim.obj | fnv360_0822_retail, call_seq, high
// pdb params: afScale
Obj* Obj::FUN_00471550(float value) {
    FUN_00471430(0x101);
    unk10 = unk14 = unk18 = value;
    return this;
}
}
}   // namespace f3m_00471550

// @f3 0x0046ab00 (community match, verified in this file)
extern void* DAT_0108f048;
extern bool DAT_0106dfe0;
extern unsigned char DAT_0106df04;
extern int DAT_0106defc;
extern float DAT_00dbea4c;
extern char DAT_00dbea50[];
extern char DAT_00dbea78[];
extern char DAT_00dbeaa4[];
namespace f3m_0046ab00 {
namespace f3m_0046ab00 {

struct Color46ab00 {
    float r, g, b, a;
    Color46ab00(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};

struct NameHolder46ab00 {
    int unk00, unk04;
    const char* name;
};

struct Obj46ab00 {
    virtual void v00();
    virtual void DeleteThis();
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84();
    virtual void v88();
    virtual void v8c();

    volatile long m_uiRefCount;
    int unk08, unk0c, unk10, unk14;
    unsigned char unk18, unk19, unk1a, unk1b;
    int unk1c, unk20;
    unsigned int unk24;
    unsigned char unk28, unk29, unk2a, unk2b, unk2c, flag2d, unk2e, unk2f;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108;
    NameHolder46ab00* extra;

    bool FUN_005b5b10();
    void BSTempEffectSimpleDecal_FinalizeGeometry();
    void FUN_005b6bd0(const Color46ab00& color, int mode);
    void IncRefCount() {
        ::InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() {
        if (::InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct SmartPtr46ab00 {
    Obj46ab00* m_pObject;
    SmartPtr46ab00() : m_pObject(0) {}
    SmartPtr46ab00(const SmartPtr46ab00& other) : m_pObject(other.m_pObject) {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    operator Obj46ab00*() const { return m_pObject; }
    ~SmartPtr46ab00() {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct ListNode46ab00 {
    ListNode46ab00* m_pkNext;
    ListNode46ab00* m_pkPrev;
    SmartPtr46ab00 m_element;
};

struct List46ab00 {
    ListNode46ab00* m_pkHead;
    ListNode46ab00* m_pkTail;
    unsigned int m_uiCount;
    SmartPtr46ab00 FUN_00469c50();
    SmartPtr46ab00 FUN_0058b9a0();
    void FUN_00ad3d80(ListNode46ab00* node);
    SmartPtr46ab00 FUN_00ab43e0(void*& pos) {
        ListNode46ab00* node = (ListNode46ab00*)pos;
        if (node == m_pkHead) {
            pos = node->m_pkNext;
            return FUN_00469c50();
        }
        if (node == m_pkTail) {
            pos = 0;
            return FUN_0058b9a0();
        }
        ListNode46ab00* prev = node->m_pkPrev;
        ListNode46ab00* next = node->m_pkNext;
        pos = next;
        if (prev)
            prev->m_pkNext = next;
        if (next)
            next->m_pkPrev = prev;
        SmartPtr46ab00 element = node->m_element;
        FUN_00ad3d80(node);
        m_uiCount--;
        return element;
    }
    const SmartPtr46ab00& GetNext(void*& pos) const {
        const SmartPtr46ab00& element = ((ListNode46ab00*)pos)->m_element;
        pos = ((ListNode46ab00*)pos)->m_pkNext;
        return element;
    }
};

struct Manager46ab00 {
    int unk00, unk04;
    List46ab00 m_list;
    void FUN_00469230(Obj46ab00* obj);
    void FUN_0046ab00();
};

} // namespace f3m_0046ab00

extern void __cdecl FUN_00887da0(const char*, ...);

// pdb: BGSDecalManager::UpdateSimpleDecals | BGSDecalManager.obj | fnv360_0822_retail, ustr, medium
void f3m_0046ab00::Manager46ab00::FUN_0046ab00()
{
    if (m_list.m_uiCount <= 0)
        return;

    ::fnv_EnterCriticalSection((CritSect_169ae0*)((char*)::DAT_0108f048 + 0x80));

    void* pos = m_list.m_pkHead;
    while (pos)
    {
        void* cur = pos;
        Obj46ab00* obj = m_list.GetNext(pos);
        if (obj)
        {
            if (obj->unk1a)
            {
                this->FUN_00469230(obj);
                obj->unk1a = 0;
            }
            if (obj->unk1c)
            {
                if (obj->FUN_005b5b10())
                {
                    if (obj->unk24 > 0)
                    {
                        if (DAT_0106dfe0)
                            ::FUN_00887da0(DAT_00dbeaa4, obj->extra->name);
                        obj->v8c();
                    }
                    else
                    {
                        if (DAT_0106dfe0)
                            ::FUN_00887da0(DAT_00dbea78, obj->extra->name);
                        obj->unk18 = 1;
                    }
                }
            }
            else
            {
                obj->v8c();
            }

            if (obj->unk19 && !obj->unk18)
                obj->BSTempEffectSimpleDecal_FinalizeGeometry();

            if (obj->unk18)
            {
                if (obj->flag2d)
                {
                    DAT_0106defc++;
                    if (DAT_0106dfe0)
                        ::FUN_00887da0(DAT_00dbea50, DAT_0106defc, obj->extra->name);
                    if (::DAT_0106df04 & 1)
                        obj->FUN_005b6bd0(Color46ab00(0.0f, 1.0f, 0.0f, 1.0f), 1);
                    if (::DAT_0106df04 & 2)
                        obj->FUN_005b6bd0(Color46ab00(0.0f, 1.0f, 0.0f, DAT_00dbea4c), 0);
                }
                else if (::DAT_0106df04 & 0x10)
                {
                    if (::DAT_0106df04 & 1)
                        obj->FUN_005b6bd0(Color46ab00(1.0f, 0.0f, 0.0f, 1.0f), 1);
                    if (::DAT_0106df04 & 2)
                        obj->FUN_005b6bd0(Color46ab00(1.0f, 0.0f, 0.0f, DAT_00dbea4c), 0);
                }
                m_list.FUN_00ab43e0(cur);
            }
        }
    }

    ::fnv_LeaveCriticalSection((CritSect_169ae0*)((char*)::DAT_0108f048 + 0x80));
}
}   // namespace f3m_0046ab00
