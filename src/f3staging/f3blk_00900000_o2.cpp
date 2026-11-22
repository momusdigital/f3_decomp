#include <math.h>
#include <string.h>
#include <windows.h>
// src/f3staging/f3blk_00900000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00903da0 (community match, verified in this file)
struct RawArray { void** data; int count; int capacity; };
struct Link { RawArray* data; int unk04; Link* next; int unk0c; };
struct Writer { virtual void v0(); virtual void Begin(const char*,int,void*); virtual void Blob(const char*,int,void*,int,int); virtual void Value(const char*,int,void*); virtual void Open(const char*); virtual void Close(); virtual void End(); void* reference; };
extern char DAT_00e220d8;
extern char DAT_00e32744;
extern char DAT_00e3480c;
extern char DAT_00e34bc0;
extern char DAT_00e34bcc;
extern char DAT_00e34bdc;
extern char DAT_00e34bec;
extern char DAT_00e34bfc;
extern char DAT_00e34c0c;
extern char DAT_00e34c1c;
extern char DAT_00e34c2c;
extern char DAT_00e34c38;
extern char DAT_00e34c44;
extern char DAT_00e34c50;
extern char DAT_00e34c5c;
extern char DAT_00e34c70;
extern char DAT_00e34c78;
extern char DAT_00e34c90;
extern char DAT_00e34c9c;
extern char DAT_00e34ca8;
extern char DAT_00e34cb4;
extern char DAT_00e34cbc;
extern char DAT_00e34cd0;
extern char DAT_00e34cdc;
extern char DAT_00e34ce4;
extern char DAT_00e34cf0;
extern char DAT_00e34cfc;
extern char DAT_00e34d08;
extern char DAT_00e34d14;
extern char DAT_00e34d30;
extern char DAT_00e34d48;
extern char DAT_00e34d68;
extern char DAT_00e34d7c;
extern char DAT_00e34d9c;
extern char DAT_00e34da8;
extern char DAT_00e34dc8;
extern char DAT_00e34dd4;
extern char DAT_00e34de0;
extern char DAT_00e34df0;
extern char DAT_00e34e00;
struct World {
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
RawArray unk28;
RawArray unk34;
RawArray unk40;
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
RawArray* unk7c;
void* unk80;
void* unk84;
void* unk88;
void* unk8c;
Link* unk90;
void* unk94;
void* unk98;
void* unk9c;
void* unka0;
void* unka4;
void* unka8;
void* unkac;
void* unkb0;
void* unkb4;
void* unkb8;
void* unkbc;
void* unkc0;
void* unkc4;
void* unkc8;
void* unkcc;
void* unkd0;
void* unkd4;
void* unkd8;
void* unkdc;
void* unke0;
RawArray unke4;
void* unkf0;
void* unkf4;
void* unkf8;
RawArray unkfc;
RawArray unk108;
RawArray unk114;
RawArray unk120;
RawArray unk12c;
RawArray unk138;
RawArray unk144;
RawArray unk150;
RawArray unk15c;
void* unk168;
void* unk16c;
void* unk170;
RawArray unk174;
void* unk180;
void* unk184;
void* unk188;
void* unk18c;
void hkpWorld_calcContentStatistics(Writer* w);
};
inline void SaveArray(Writer* w, RawArray& a, const char* name, int kind, int size) { if (!(a.capacity & 0x80000000)) w->Blob(name,kind,a.data,a.count*size,(a.capacity&0x3fffffff)*size); }
// pdb: hkpWorld::calcContentStatistics | hkpWorld.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void World::hkpWorld_calcContentStatistics(Writer* w) {
w->reference=unk6c; w->Begin(&DAT_00e34e00,2,this);
SaveArray(w,unk28,&DAT_00e34df0,2,4);
for(int i=unk28.count-1;i>=0;--i) w->Value(&DAT_00e220d8,8,unk28.data[i]);
SaveArray(w,unk34,&DAT_00e34de0,2,4);
for(int i=unk34.count-1;i>=0;--i) w->Value(&DAT_00e34dd4,8,unk34.data[i]);
w->Value(&DAT_00e3480c,8,unk20);
SaveArray(w,unke4,&DAT_00e34dc8,4,4);
for(int i=0;i<unke4.count;++i) w->Value(&DAT_00e32744,2,unke4.data[i]);
w->Blob(&DAT_00e34da8,4,unka8,48,0);
w->Blob(&DAT_00e34d9c,4,unkac,48,0);
w->Blob(&DAT_00e34d7c,4,unkb0,48,0);
w->Blob(&DAT_00e34d68,4,unkb4,48,0);
w->Blob(&DAT_00e34d48,4,unk68,20,0);
if(unk90) { Link* p=unk90; do {
w->Blob(&DAT_00e34d30,4,unk90,16,0);
if(unk90->data) SaveArray(w,*unk90->data,&DAT_00e34d14,4,20); p=p->next; } while(p); }
w->Open(&DAT_00e34d08);
w->Value(&DAT_00e34cfc,4,unk08);
SaveArray(w,unk40,&DAT_00e34cf0,8,4);
w->Value(&DAT_00e34ce4,4,unk4c);
w->Blob(&DAT_00e34cdc,4,unk7c,80,0);
w->Open(&DAT_00e34cdc); SaveArray(w,*unk7c,&DAT_00e34cd0,8,20); w->Close();
w->Value(&DAT_00e34cbc,4,unk18c);
w->Open(&DAT_00e34cb4);
w->Value(&DAT_00e34ca8,4,unk54);
w->Blob(&DAT_00e34c9c,4,unk58,268,0);
w->Blob(&DAT_00e34c9c,4,unk60,16,0);
w->Blob(&DAT_00e34c9c,4,unk5c,12,0);
w->Blob(&DAT_00e34c9c,4,unk64,12,0);
w->Blob(&DAT_00e34c90,4,unk6c,112,0);
if(unk6c) w->Blob(&DAT_00e34c78,4,*reinterpret_cast<void**>(static_cast<char*>(unk6c)+0x6c),16,0);
w->Value(&DAT_00e34c70,1,unk70);
w->Value(&DAT_00e34c5c,4,unk78);
w->Value(&DAT_00e34c50,4,unk74);
w->Close(); w->Close(); w->Open(&DAT_00e34c44);
SaveArray(w,unkfc,&DAT_00e34c38,4,4);
SaveArray(w,unk108,&DAT_00e34c2c,4,4);
SaveArray(w,unk114,&DAT_00e34c1c,4,4);
SaveArray(w,unk120,&DAT_00e34c0c,4,4);
SaveArray(w,unk12c,&DAT_00e34bfc,4,4);
SaveArray(w,unk138,&DAT_00e34bec,4,4);
SaveArray(w,unk144,&DAT_00e34bdc,4,4);
SaveArray(w,unk150,&DAT_00e34bcc,4,4);
SaveArray(w,unk15c,&DAT_00e34bdc,4,4);
SaveArray(w,unk174,&DAT_00e34bc0,4,4);
w->Close(); w->End(); w->reference=0; }

// @f3 0x00908400 (community match, verified in this file)
struct WorldObjectP3 {
    void* vtbl00;
    int unk04;
    void* world;
};

struct WorldOpP3 {
    unsigned char type;
    void* item;
};

struct WorldResultP3 {
    bool done;
    WorldResultP3(bool b) : done(b) {}
};

struct WorldP3;

struct ActionP3 {
    virtual ~ActionP3();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual int GetRefCountP3();

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
    WorldObjectP3* owner38;

    void DetachFromWorldP3(WorldP3* world);
};

void UpdateActionInWorldP3(WorldP3* world, ActionP3* action, int flag);

struct WorldP3 {
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
    int pendingOperationsCount;
    int criticalOperationsLockCount;
    int unk88;
    bool blockExecutingPendingOperations;

    void QueueOperationP3(WorldOpP3* op);
    void RemoveOwnerP3(WorldObjectP3* owner);
    void ExecutePendingOperationsP3();
    WorldResultP3 hkpWorld_removeConstraint(ActionP3* action);
};

// pdb: hkpWorld::removeConstraint | hkpWorld.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq) + skyrim(call_gap), high
WorldResultP3 WorldP3::hkpWorld_removeConstraint(ActionP3* action)
{
    if (criticalOperationsLockCount) {
        WorldOpP3 op;
        op.type = 9;
        op.item = action;
        QueueOperationP3(&op);
        return WorldResultP3(false);
    }
    criticalOperationsLockCount = 1;
    if (action->GetRefCountP3() == 1 && action->owner38->world == this)
        RemoveOwnerP3(action->owner38);
    UpdateActionInWorldP3(this, action, 1);
    action->DetachFromWorldP3(this);
    if (--criticalOperationsLockCount == 0 && !blockExecutingPendingOperations && pendingOperationsCount)
        ExecutePendingOperationsP3();
    return WorldResultP3(true);
}

// @f3 0x00911090 (community match, verified in this file)
struct Array444 {
    unsigned int unk00;
    unsigned int* data;
    unsigned short capacity, count, unk0C, growth;
    void FUN_00555790(unsigned int count);
    void FUN_005b3880(unsigned int index, const unsigned int* value);
    __forceinline void Append(unsigned int value) {
        unsigned int index = count;
        if (index >= capacity)
            FUN_00555790(growth + index);
        FUN_005b3880(index,&value);
    }
};
struct Visitor444 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void OnArray(Array444* array);
};
struct Header444 { unsigned int unk00, unk04; Visitor444* visitor; unsigned int unk0C; };
struct Node444 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void* GetData();
};
extern unsigned int DAT_010f32c4;
unsigned int __cdecl FUN_00847b50(unsigned int value);
union Parameter444 { Array444* array; unsigned int value; };
struct Owner444 {
    unsigned int unk00, unk04;
    Node444* node;
    void FUN_008f7a20(Array444* array);
    void FUN_00911090(Array444* array);
};
// pdb: bhkBvTreeShape::GetViewerStrings | bhkBvTreeShape.obj | fnv360_0822_retail, call_gap, low
// pdb params: apStrings
void Owner444::FUN_00911090(Array444* array) {
    FUN_008f7a20(array);
    array->Append(FUN_00847b50(DAT_010f32c4));
    if (this) {
        Node444* current = node;
        if (current) {
            void* data = current->GetData();
            if (data) {
                Header444* header = static_cast<Header444*>(data) - 1;
                if (header) {
                    Visitor444* visitor = header->visitor;
                    if (visitor)
                        visitor->OnArray(array);
                }
            }
        }
    }
}

// @f3 0x009017a0 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
namespace Memory480 {
void* __cdecl FUN_0089eb90(unsigned int);
extern void (__stdcall* DAT_00d9b09c)(void*);
extern void (__stdcall* DAT_00d9b0a0)(void*);
extern int DAT_010f3194;
extern int DAT_00dcdc8c,DAT_00dcdd5c,DAT_00dce6ec;
extern int DAT_010f31d8,DAT_010f3240,DAT_010f321c;
}
struct Node480 {
    void* table; unsigned int unk04,unk08,unk0c,unk10,unk14,unk18;
    static void* operator new(unsigned int n) throw() { return Memory480::FUN_0089eb90(n); }
    void FUN_008f7c10();
    Node480() {
        FUN_008f7c10();
        table=&Memory480::DAT_00dcdc8c;unk0c=0;unk10=0;_ReadWriteBarrier();++Memory480::DAT_010f31d8;
        table=&Memory480::DAT_00dcdd5c;++Memory480::DAT_010f3240;
        table=&Memory480::DAT_00dce6ec;unk14=0;unk18=0;++Memory480::DAT_010f321c;
    }
};
struct Owner480 { void FUN_00900e00(Node480*,void*); Node480* FUN_009017a0(void*); };
// pdb: bhkRigidBody::CreateClone | bhkRigidBody.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
Node480* Owner480::FUN_009017a0(void* argument) {
    Memory480::DAT_00d9b09c(&Memory480::DAT_010f3194);
    Node480* node=new Node480;
    FUN_00900e00(node,argument);
    Memory480::DAT_00d9b0a0(&Memory480::DAT_010f3194);
    return node;
}

// @f3 0x0091ef40 (community match, verified in this file)
namespace f3m_0091ef40 {

struct hkStatisticsCollector
{
    virtual ~hkStatisticsCollector();
    virtual void Unk01();
    virtual void AddChunk(const char* name, int category, void* data, int usedSize, int allocatedSize);
};

struct hkArrayEntry64
{
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct hkArrayEntry4
{
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct HavokObject91ef40
{
    char pad[0x74];
    hkArrayEntry64 m_manifold;
    hkArrayEntry4 m_listeners;
    hkArrayEntry4 m_overlaps;
    hkArrayEntry4 m_manifold2;

    void __thiscall hkpCharacterProxy_calcContentStatistics(hkStatisticsCollector* apCollector);
};

// pdb: hkpCharacterProxy::calcContentStatistics | hkpCharacterProxy.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void HavokObject91ef40::hkpCharacterProxy_calcContentStatistics(hkStatisticsCollector* apCollector)
{
    if ((m_manifold.m_capacityAndFlags & 0x80000000) == 0)
    {
        apCollector->AddChunk("Manifold", 8, m_manifold.m_data, m_manifold.m_size * 64, (m_manifold.m_capacityAndFlags & 0x3fffffff) * 64);
    }
    if ((m_overlaps.m_capacityAndFlags & 0x80000000) == 0)
    {
        apCollector->AddChunk("OverlapsPntr", 8, m_overlaps.m_data, m_overlaps.m_size * 4, (m_overlaps.m_capacityAndFlags & 0x3fffffff) * 4);
    }
    if ((m_manifold2.m_capacityAndFlags & 0x80000000) == 0)
    {
        apCollector->AddChunk("Manifold", 8, m_manifold2.m_data, m_manifold2.m_size * 4, (m_manifold2.m_capacityAndFlags & 0x3fffffff) * 4);
    }
    if ((m_listeners.m_capacityAndFlags & 0x80000000) == 0)
    {
        apCollector->AddChunk("ListnrPntr", 8, m_listeners.m_data, m_listeners.m_size * 4, (m_listeners.m_capacityAndFlags & 0x3fffffff) * 4);
    }
}
}   // namespace f3m_0091ef40

// @f3 0x009156c0 (community match, verified in this file)
struct Scene915;
struct Node915;
struct Controller915;
struct ControllerType915;
struct Filter915 { unsigned int value; };
struct FilterData915 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    Filter915 filter;
};
struct Shape915 {
    unsigned int unk00, unk04, unk08, unk0c;
    FilterData915 data;
};
struct Entity915 {
    virtual void slot00();
    unsigned int unk04;
    Shape915* shape;
    Filter915 FUN_00424270();
};
struct PrimaryEntity915 : Entity915 {
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void RefreshFilter();
};
struct FallbackEntity915 : Entity915 {
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void SetMode(int);
};
struct PrimaryCollision915 {
    unsigned int unk00, unk04, unk08, unk0c;
    PrimaryEntity915* entity;
};
struct FallbackCollision915 {
    unsigned int unk00, unk04, unk08, unk0c;
    FallbackEntity915* entity;
};
struct Point915 {
    float x, y, z;
    Point915();
};
struct PointArray915 {
    void FUN_009147c0(unsigned int);
};
struct Controller915 {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void Apply(float);
    unsigned int unk04;
    unsigned short flags, unk0a;
    float weight, phase, time, scale;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    PointArray915 points;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int pointData;
    unsigned int unk4c, unk50, unk54;
    int pointCount;
    void FUN_00914c00();
    void FUN_00915470(Point915*);
};
struct Scene915 {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual Node915* AsNode();
    Controller915* FUN_00825200(const ControllerType915*);
};
struct Node915 : Scene915 {
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
    Scene915** children;
    unsigned short unkA4, count;
};
struct Pair915 { float first, second; };
extern PrimaryCollision915* FUN_007235f0(Scene915*);
extern FallbackCollision915* FUN_00424fe0(Scene915*);
extern ControllerType915 DAT_010f32f8;
extern float DAT_00f7ab78[];
extern Pair915 DAT_00f79d30[];
extern float DAT_00db7260;

// pdb: bhkBlendController::DoGetUpRecursive | bhkBlendController.obj | fnv360_0822_retail, objrun, medium
// pdb params: apObject, afTime
void FUN_009156c0(Scene915* object, float time)
{
    if (!object)
        return;

    PrimaryCollision915* collision = FUN_007235f0(object);
    if (collision) {
        unsigned int filter = 0;
        PrimaryEntity915* entity = collision->entity;
        if (entity) {
            Shape915* shape = entity->shape;
            FilterData915* readData = shape ? &shape->data : 0;
            if (readData)
                filter = readData->filter.value;
            else
                filter = 0;
            filter = (filter & ~0x77u) | 8;
            if (shape) {
                FilterData915* data = &shape->data;
                if (data)
                    data->filter.value = filter;
            }
            entity->RefreshFilter();
        }

        unsigned int layer = (filter >> 8) & 31;
        float scale = DAT_00f7ab78[layer];
        Controller915* controller = object->FUN_00825200(&DAT_010f32f8);
        if (controller && scale >= 0.0f) {
            float first = DAT_00f79d30[layer].first;
            float second = DAT_00f79d30[layer].second;
            controller->FUN_00914c00();
            controller->pointCount = 2;
            if (!controller->pointData) {
                Point915 points[2];
                points[0].x = points[0].z = points[0].y = 0.0f;
                points[1].y = first;
                points[1].z = second;
                points[1].x = scale;
                controller->points.FUN_009147c0(2);
                for (unsigned int i = 0; i != 2; ++i)
                    controller->FUN_00915470(&points[i]);
                controller->flags &= 0xfef5;
                controller->flags |= 0xc5;
                controller->time = time;
                controller->scale = scale;
                controller->phase = 0.0f;
                controller->weight = 1.0f;
                controller->Apply(DAT_00db7260);
            }
        }
    } else {
        FallbackCollision915* fallback = FUN_00424fe0(object);
        if (fallback && fallback->entity) {
            FallbackEntity915* entity = fallback->entity;
            unsigned int filter = entity->FUN_00424270().value;
            unsigned int layer = filter & 0x7f;
            if ((layer != 8 && layer != 29) || (filter & 0x1f00) == 0x1400)
                entity->SetMode(6);
        }
    }

    Node915* node = object->AsNode();
    if (node) {
        for (unsigned int i = 0; i < node->count; ++i)
            FUN_009156c0(node->children[i], time);
    }
}

// @f3 0x0091b9a0 (community match, verified in this file)
namespace Memory480 {
extern int DAT_010f31f8;
extern int DAT_010f3334;
void __cdecl FUN_0089ebd0(void*);
}

class bhkRefObject
{
public:
    static void* operator new(unsigned int n) { return Memory480::FUN_0089eb90(n); }
    static void operator delete(void* p) { Memory480::FUN_0089ebd0(p); }
    bhkRefObject();
    virtual ~bhkRefObject();
    int refCount;
    void* phkObject;
};

class bhkConstraint : public bhkRefObject
{
public:
    bhkConstraint() { unk0c = 0; ++Memory480::DAT_010f31f8; }
    virtual ~bhkConstraint();
    int unk0c;
};

class bhkMalleableConstraint : public bhkConstraint
{
public:
    bhkMalleableConstraint() { ++Memory480::DAT_010f3334; }
    virtual ~bhkMalleableConstraint();
};

struct Owner91b9a0
{
    void FUN_008fbc00(bhkRefObject* obj, void* arg);
    bhkMalleableConstraint* FUN_0091b9a0(void* arg);
};

// pdb: bhkMalleableConstraint::CreateClone | bhkMalleableConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
bhkMalleableConstraint* Owner91b9a0::FUN_0091b9a0(void* arg)
{
    Memory480::DAT_00d9b09c(&Memory480::DAT_010f3194);
    bhkMalleableConstraint* obj = new bhkMalleableConstraint;
    FUN_008fbc00(obj, arg);
    Memory480::DAT_00d9b0a0(&Memory480::DAT_010f3194);
    return obj;
}

// @f3 0x00914b20 (community match, verified in this file)
extern const float DAT_01012054;
extern const double DAT_01017a40;
namespace f3m_00914b20 {
namespace f3m_00914b20 {
struct Vec3Elem {
    float x, y, z;
    bool FUN_00914770(const Vec3Elem& other) const;
    bool FUN_00914730(const Vec3Elem& other) const;
};
}
using namespace f3m_00914b20;

struct Vec3Range914b20 {
    int unk00;
    Vec3Elem* m_pBase;
    int unk08;
    unsigned int m_uiSize;
    int m_iCount;
    void FUN_00914b20(unsigned int index, Vec3Elem* apElem);
};

// pdb: NiTLargeArray<BLENDKEY,NiTMallocInterface<BLENDKEY> >::SetAt | bhkBlendController.obj | fnv360_0822_retail, call_seq, medium
// pdb params: uiIndex, element
void Vec3Range914b20::FUN_00914b20(unsigned int index, Vec3Elem* apElem)
{
    Vec3Elem dir;
    dir.x = DAT_01012054;
    double rest = 0.0 / DAT_01017a40;
    if (index >= m_uiSize) {
        dir.z = (float)rest;
        dir.y = dir.z;
        m_uiSize = index + 1;
        if (apElem->FUN_00914770(dir))
            m_iCount++;
    } else {
        dir.z = (float)rest;
        dir.y = dir.z;
        bool ok = apElem->FUN_00914770(dir);
        dir.x = DAT_01012054;
        dir.z = (float)rest;
        dir.y = dir.z;
        if (ok) {
            if (m_pBase[index].FUN_00914730(dir))
                m_iCount++;
        } else {
            if (m_pBase[index].FUN_00914770(dir))
                m_iCount--;
        }
    }
    Vec3Elem* dst = &m_pBase[index];
    *dst = *apElem;
}
}   // namespace f3m_00914b20

// @f3 0x009113b0 (community match, verified in this file)
struct Heap7 { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern Heap7 DAT_01090a78;
struct Stream7 { unsigned int unk00; unsigned int consumed; unsigned int (__cdecl *read)(Stream7*, void*, unsigned int, int, int); };
struct Input7 {
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
    Stream7* stream;
};
struct Owner7 {
    virtual void unknown000();
    virtual void unknown004();
    virtual void unknown008();
    virtual void unknown00c();
    virtual void unknown010();
    virtual void unknown014();
    virtual void unknown018();
    virtual void unknown01c();
    virtual void unknown020();
    virtual void unknown024();
    virtual void unknown028();
    virtual void unknown02c();
    virtual void unknown030();
    virtual void unknown034();
    virtual void unknown038();
    virtual void unknown03c();
    virtual void unknown040();
    virtual void unknown044();
    virtual void unknown048();
    virtual void unknown04c();
    virtual void unknown050();
    virtual void unknown054();
    virtual void unknown058();
    virtual void unknown05c();
    virtual void unknown060();
    virtual void unknown064();
    virtual void unknown068();
    virtual void unknown06c();
    virtual void unknown070();
    virtual void unknown074();
    virtual void unknown078();
    virtual void unknown07c();
    virtual void unknown080();
    virtual void unknown084();
    virtual void unknown088();
    virtual void unknown08c();
    virtual void unknown090();
    virtual void unknown094();
    virtual void unknown098();
    virtual void unknown09c();
    virtual void unknown0a0();
    virtual void unknown0a4();
    virtual unsigned int Size();
    unsigned int FUN_009113b0(Input7* input);
};
unsigned int Owner7::FUN_009113b0(Input7* input) {
    unsigned int size = Size();
    void* data = DAT_01090a78.FUN_0086b930(size);
    Stream7* stream = input->stream;
    stream->consumed += stream->read(stream, data, size, 0, 0);
    DAT_01090a78.FUN_0086ba60(data);
    return size;
}

// @f3 0x00912610 (community match, verified in this file)
namespace f3m_00912610 {
struct Heap29 { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
struct FUN_00910b00 {
    virtual ~FUN_00910b00();
    unsigned short flags;
    short references;
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
    FUN_00910b00(void*);
    static void* operator new(unsigned int size) {
        char* p=(char*)DAT_01090a78.FUN_0086b930(size+16);
        unsigned char delta=(unsigned char)(16-(unsigned char)((unsigned int)p&15));
        p+=delta; p[-1]=delta; return p;
    }
    static void operator delete(void* object) {
        char* p=(char*)object; unsigned char delta=(unsigned char)p[-1];
    }
    void Release() { if(flags) { --references; if(!references) delete this; } }
};
struct Owner29 {
    virtual void unknown000();
    virtual void unknown004();
    virtual void unknown008();
    virtual void unknown00c();
    virtual void unknown010();
    virtual void unknown014();
    virtual void unknown018();
    virtual void unknown01c();
    virtual void unknown020();
    virtual void unknown024();
    virtual void unknown028();
    virtual void unknown02c();
    virtual void unknown030();
    virtual void unknown034();
    virtual void unknown038();
    virtual void unknown03c();
    virtual void unknown040();
    virtual void unknown044();
    virtual void unknown048();
    virtual void unknown04c();
    virtual void unknown050();
    virtual void unknown054();
    virtual void unknown058();
    virtual void unknown05c();
    virtual void unknown060();
    virtual void unknown064();
    virtual void unknown068();
    virtual void unknown06c();
    virtual void unknown070();
    virtual void unknown074();
    virtual void unknown078();
    virtual void unknown07c();
    virtual void unknown080();
    virtual void unknown084();
    virtual void unknown088();
    virtual void Take(FUN_00910b00*);
    virtual void unknown090();
    virtual void unknown094();
    virtual void unknown098();
    virtual void unknown09c();
    virtual void unknown0a0();
    virtual void unknown0a4();
    virtual void unknown0a8();
    virtual void unknown0ac();
    virtual void unknown0b0();
    virtual void unknown0b4();
    virtual void unknown0b8();
    virtual void Complete(void*);
    void FUN_00912610(void*);
};
// pdb: bhkNiTriStripsShape::Init | bhkNiTriStripsShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void Owner29::FUN_00912610(void* input) {
    if(input) {
        FUN_00910b00* item=new FUN_00910b00(input);
        Take(item);
        item->Release();
        Complete(input);
    }
}
}   // namespace f3m_00912610

// @f3 0x00903020 (community match, verified in this file)
namespace f3m_00903020 {
namespace SnapshotF3
{
struct Mode
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    unsigned int unk1C, unk20, unk24, unk28;
    unsigned int field2C;
};
struct NestedSetting
{
    float field00;
    unsigned int field04;
};
struct Settings
{
    unsigned int unk00;
    float field04;
    unsigned int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    unsigned int unk5C, unk60, unk64;
    unsigned char field68;
    unsigned char unk69;
    unsigned char unk6A;
    unsigned char unk6B;
    NestedSetting* nested;
};
struct Definition
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    unsigned int unk1C, unk20;
    float field24;
};

struct EnvironmentScalars
{
    float field1E40;
    float field1E44;
};

struct Environment
{
    const EnvironmentScalars& GetScalars() const
    {
        const char* bytes = reinterpret_cast<const char*>(this);
        return *reinterpret_cast<const EnvironmentScalars*>(bytes + 0x1e40);
    }
};

struct SnapshotVector
{
    float x, y, z, w;

    __forceinline SnapshotVector& operator=(const SnapshotVector& source)
    {
        x = source.x;
        y = source.y;
        z = source.z;
        w = source.w;
        return *this;
    }
};

struct Snapshot
{
    unsigned int unk00, unk04, unk08, unk0C;
    SnapshotVector vector10;
    unsigned int field20;
    float field24;
    unsigned char field28;
    unsigned char unk29;
    unsigned char unk2A;
    unsigned char unk2B;
    unsigned int unk2C;
    float field30;
    float field34;
    float field38;
    float field3C;
    float field40;
    float field44;
    float field48;
    float field4C;
    float field50;
    void* field54;
    void* field58;
    float field5C;
    unsigned int field60;
    float field64;
    void* field68;
    unsigned int field6C;
    unsigned char field70;
    unsigned char unk71;
    unsigned char unk72;
    unsigned char unk73;
    float field74;
    float field78;
    unsigned int field7C;
    unsigned int field80;
    unsigned char field84;
    unsigned char unk85;
    unsigned char unk86;
    unsigned char unk87;
    float field88;
    unsigned int unk8C;
    unsigned char field90;
    unsigned char field91;
    unsigned char unk92;
    unsigned char unk93;
    float field94;
    unsigned int field98;
    unsigned int unk9C, unkA0;
    unsigned char fieldA4;
    unsigned char fieldA5;
    unsigned char fieldA6;
    unsigned char fieldA7;
    float fieldA8;
    float fieldAC;
    unsigned int fieldB0;
    unsigned char fieldB4;
    unsigned char unkB5;
    unsigned char unkB6;
    unsigned char unkB7;
    unsigned int fieldB8;
    unsigned char fieldBC;
    unsigned char fieldBD;
    unsigned char fieldBE;
    unsigned char unkBF;
    unsigned int fieldC0;
    unsigned char fieldC4;
    unsigned char unkC5;
    unsigned char unkC6;
    unsigned char unkC7;
    float fieldC8;
};

struct SnapshotSource
{
    unsigned int unk00, unk04;
    Definition* definition;
    unsigned int unk0C;
    SnapshotVector vector10;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
    unsigned int unk3C, unk40, unk44, unk48, unk4C;
    void* field50;
    unsigned int unk54, unk58, unk5C, unk60, unk64, unk68;
    Settings* settings;
    void* field70;
    Environment* environment;
    void* field78;
    unsigned int unk7C, unk80, unk84, unk88, unk8C, unk90, unk94;
    unsigned int unk98, unk9C;
    unsigned char fieldA0;
    unsigned char unkA1;
    unsigned char unkA2;
    unsigned char unkA3;
    unsigned int fieldA4;
    unsigned int unkA8, unkAC, unkB0, unkB4;
    unsigned char fieldB8;
    unsigned char unkB9;
    unsigned char unkBA;
    unsigned char unkBB;
    float fieldBC;
    float fieldC0;
    unsigned char fieldC4;
    unsigned char fieldC5;
    unsigned char fieldC6;
    unsigned char unkC7;
    float fieldC8;
    float fieldCC;
    unsigned char fieldD0;
    unsigned char unkD1;
    unsigned char unkD2;
    unsigned char unkD3;
    unsigned int fieldD4;
    unsigned int fieldD8;
    unsigned char fieldDC;
    unsigned char unkDD;
    unsigned char unkDE;
    unsigned char unkDF;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8;
    unsigned int unkFC, unk100, unk104, unk108, unk10C, unk110, unk114;
    unsigned int unk118, unk11C, unk120, unk124, unk128, unk12C, unk130;
    unsigned int unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    unsigned int unk150, unk154, unk158, unk15C, unk160, unk164, unk168;
    unsigned int unk16C, unk170, unk174, unk178, unk17C, unk180, unk184;
    unsigned int unk188;
    Mode* mode;
    unsigned int unk190, unk194, unk198, unk19C, unk1A0;
    float field1A4;
    float field1A8;
    unsigned int unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4;
    unsigned int unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0;
    unsigned int unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    float field200;
    unsigned int unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    unsigned int unk220, unk224, unk228, unk22C, unk230, unk234, unk238;
    unsigned int unk23C, unk240, unk244, unk248, unk24C, unk250, unk254;
    unsigned int unk258, unk25C, unk260, unk264, unk268, unk26C, unk270;
    unsigned int unk274, unk278, unk27C, unk280, unk284, unk288, unk28C;
    unsigned int unk290, unk294, unk298, unk29C, unk2A0, unk2A4, unk2A8;
    unsigned int unk2AC, unk2B0;
    unsigned int field2B4;
    unsigned int field2B8;
    unsigned int unk2BC, unk2C0;
    unsigned char field2C4;
    unsigned char field2C5;
    unsigned char field2C6;
    unsigned char field2C7;
    unsigned int unk2C8, unk2CC;
    float field2D0;
    float field2D4;
    float field2D8;
    float field2DC;
    float field2E0;
    float field2E4;
    float field2E8;
    float field2EC;
    unsigned int field2F0;
    unsigned int field2F4;
    unsigned int field2F8;
    unsigned int unk2FC;
    unsigned char field300;
    void FUN_00903020(Snapshot* output);
};

// pdb: hkpWorld::getCinfo | hkpWorld.obj | fnv360_0822_retail, call_dedup, low
// pdb params: info
void SnapshotSource::FUN_00903020(Snapshot* output)
{
    output->vector10 = vector10;
    output->field20 = field2F8;
    output->field30 = field2D0;
    output->field34 = field2D4;
    output->field38 = field2D8;
    output->field3C = field2DC;
    output->field40 = field2E0;
    output->field44 = field2E4;
    output->field48 = field2E8;
    output->field4C = field2EC;
    output->field50 = settings->field04;
    output->field54 = field70;
    output->field58 = field78;
    unsigned int modeValue;
    if (mode)
        modeValue = mode->field2C;
    else
        modeValue = 3;
    output->field28 = static_cast<unsigned char>(modeValue);
    output->field5C = environment->GetScalars().field1E40;
    output->field64 = environment->GetScalars().field1E44;
    output->field88 = fieldBC;
    output->field88 = fieldC0;
    output->field90 = fieldC4;
    output->field68 = field50;
    output->field6C = field2F0;
    output->field60 = field2F4;
    output->field70 = field300;
    output->field24 = field200;
    output->field74 = field1A4;
    output->field78 = field1A8;
    output->field7C = field2B4;
    output->field80 = field2B8;
    output->field84 = field2C4;
    output->fieldA4 = field2C5;
    output->fieldA5 = field2C6;
    output->fieldA6 = field2C7;
    output->field94 = settings->nested->field00;
    output->field98 = settings->nested->field04;
    output->field91 = settings->field68;
    output->fieldA7 = fieldC6;
    output->fieldAC = fieldCC;
    output->fieldB4 = fieldD0;
    output->fieldB0 = fieldD4;
    output->fieldB8 = fieldD8;
    output->fieldA8 = fieldC8;
    output->fieldBC = fieldC5;
    output->fieldBD = fieldDC;
    output->fieldC8 = definition->field24;
    output->fieldBE = fieldB8;
    output->fieldC4 = fieldA0;
    output->fieldC0 = fieldA4;
}
}
}   // namespace f3m_00903020

// @f3 0x0091d270 (community match, verified in this file)
namespace f3m_0091d270 {
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct Arg91d270 {
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
    unsigned char unk1e4, endian;
};
struct Data91d270 { unsigned long unk00,unk04,unk08,unk0c,v10,v14,v18,v1c,v20,v24,v28,v2c; };
struct Owner91d270 {
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
    virtual Data91d270* GetData(Arg91d270**);
    void FUN_0090c4f0(Arg91d270*);
    void FUN_0091d270(Arg91d270* argument);
};
// pdb: bhkCapsuleShape::LoadBinary | bhkCapsuleShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Owner91d270::FUN_0091d270(Arg91d270* argument) {
    Arg91d270* volatile* parameter = &argument;
    Arg91d270* original = *parameter;
    FUN_0090c4f0(original);
    if (original->endian == 1) return;
    Data91d270* data = GetData(&argument);
    if (!data) return;
    data->v10 = _byteswap_ulong(data->v10); _ReadWriteBarrier();
    data->v14 = _byteswap_ulong(data->v14); _ReadWriteBarrier();
    data->v18 = _byteswap_ulong(data->v18); _ReadWriteBarrier();
    data->v1c = _byteswap_ulong(data->v1c); _ReadWriteBarrier();
    data->v20 = _byteswap_ulong(data->v20); _ReadWriteBarrier();
    data->v24 = _byteswap_ulong(data->v24); _ReadWriteBarrier();
    data->v28 = _byteswap_ulong(data->v28); _ReadWriteBarrier();
    data->v2c = _byteswap_ulong(data->v2c); _ReadWriteBarrier();
}
}   // namespace f3m_0091d270

// @f3 0x0090baf0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0090baf0 {
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Manager90 {
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
void* unk48;
int unk4c;
void FUN_008f6d90(void*,int,int); void FUN_008f6890(int,void*,int);
};
struct Elem48_90 {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;};
struct Elem8_90 { int unk00,unk04; };
template<class T> struct Wide90 {
 T* data; int count; int capacity;
 __forceinline void clear() {
 if(!(capacity&0x80000000)) {
 int allocated=capacity&0x3fffffff;
 Manager90* m=(Manager90*)TlsGetValue(DAT_010f3170);
 m->FUN_008f6d90(data,allocated*sizeof(T),23);
 }
 data=0; count=0; capacity=(capacity&0xc0000000)|0x80000000;
 }
};
template<class T> struct Small90 {
 T* data; unsigned short count,capacity;
 __forceinline void release() {
 if(!(capacity&0x8000)) {
 int allocated=capacity&0x3fff;
 Manager90* m=(Manager90*)TlsGetValue(DAT_010f3170);
 m->FUN_008f6d90(data,allocated*sizeof(T),23);
 }
 }
 __forceinline void clear() {
 release(); data=0; count=0; capacity=(capacity&0xc000)|0x8000;
 }
 __forceinline bool any() {
 int i=0;
 if((unsigned int)count>0) { T* p=data; do { if(*p) return true; _ReadWriteBarrier(); ++i; ++p; } while(i<count); }
 return false;
 }
};
struct Group90 { Small90<void*> first,second;
 __forceinline void release() {
 second.release(); first.release();
 Manager90* m=(Manager90*)TlsGetValue(DAT_010f3170);
 if(m->unk4c>=m->unk34) m->FUN_008f6890(2,this,4);
 else { _ReadWriteBarrier(); void* next=m->unk48; m->unk4c++; *(void**)this=next; m->unk48=this; }
 }
};
struct Cleanup90 {
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
Wide90<Elem8_90> unk5c;
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
Small90<Elem48_90> unk98;
Wide90<void*> unka0;
Wide90<char> unkac;
int unkb8;
int unkbc;
int unkc0;
int unkc4;
int unkc8;
Group90* unkcc;
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
Small90<void*> unk1f0;
Small90<void*> unk1f8;
void hkpEntity_deallocateInternalArrays();
};
// pdb: hkpEntity::deallocateInternalArrays | hkpEntity.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun), high
void Cleanup90::hkpEntity_deallocateInternalArrays() {
 if(!unk5c.count) unk5c.clear();
 if(!unk98.count) unk98.clear();
 if(!unka0.count) unka0.clear();
 if(!unkac.count) unkac.clear();
 if(!unk1f0.any()) unk1f0.clear();
 bool firstNonempty=false;
 Group90* group=unkcc;
 if(group) { if(group->first.any()) firstNonempty=true; else group->first.clear(); }
 bool secondNonempty=false;
 group=unkcc;
 if(group) { if(group->second.any()) secondNonempty=true; else group->second.clear(); }
 if(!firstNonempty && !secondNonempty) {
 if(unkcc) unkcc->release();
 unkcc=0;
 }
 if(!unk1f8.count) unk1f8.clear();
}
}   // namespace f3m_0090baf0

// @f3 0x0091c320 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0091c320 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
struct Copy91 { int u0; void FUN_008fda60(const Copy91*); };
struct Child91 { virtual void v0(int); virtual void v4(); virtual void v8(); virtual Child91* v0c(); };
struct Alloc91 { void* FUN_008f6d30(int size,int kind); };
struct Source91 {
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
struct Child91* m_child;
int u0b4;
int u0b8;
float fbc;
int u0c0;
float fc4;
float fc8;
int u0cc;
__declspec(noinline) Source91();
~Source91();
void FUN_0092b710();
static void* operator new(unsigned int size) { Alloc91* alloc=(Alloc91*)DAT_00d9b080(DAT_010f3170); Source91* mem=(Source91*)alloc->FUN_008f6d30(0xe0,0x2c); *(short*)((char*)mem+4)=0xe0; return mem; }
void FUN_0092b2e0(Child91*);
};
__declspec(noinline) Source91::Source91() { FUN_0092b710(); }
struct Owner91 {
 int u0;
 Source91* source;
 void FUN_008fc3f0(Source91*,void*);
 void FUN_0091c320(Source91*,void*);
};
extern void __cdecl FUN_00930d80(float,Source91*);
// pdb: hkLimitedHingeConstraintCinfo::CloneData | bhkLimitedHingeConstraint.obj | fnv360_0721_beta, caller_sim, medium
// pdb params: apData, arCloneData
void Owner91::FUN_0091c320(Source91* result,void* settings)
{
    Source91* src=source;
    if(!result)
    {
        result=new Source91();
    }
    ((Copy91*)((char*)result+0x20))->FUN_008fda60((Copy91*)((char*)src+0x20));
    ((Copy91*)((char*)result+0x60))->FUN_008fda60((Copy91*)((char*)src+0x60));
    result->fbc=src->fbc;
    result->fc4=src->fc4;
    result->fc8=src->fc8;
    float factor=*(float*)((char*)settings+0x10);
    if (factor != 1.0f) FUN_00930d80(factor,result);
    Child91* child=src->m_child;
    if(child)
    {
        Child91* other=child->v0c();
        result->FUN_0092b2e0(other);
        if(*(short*)((char*)other+4))
        {
            short& refs=*(short*)((char*)other+6);
            --refs;
            if(refs==0) other->v0(1);
        }
        *(unsigned char*)((char*)result+0xa2)=*(unsigned char*)((char*)src+0xa2);
    }
    FUN_008fc3f0(result,settings);
}
}   // namespace f3m_0091c320

// @f3 0x0090f7a0 (community match, verified in this file)
extern char  DAT_00e35fc8;
extern char  DAT_00e35fa4;
namespace f3m_0090f7a0 {

// ---- FUN_0090f7a0 target -------------------------------------------------
// __thiscall, this in ecx, pops 4 bytes (one pointer parameter).
// Structure: constructor-like: helper call with 0x1f, two pointer-initialiser
// stores at [this] and [this+0x10], a reference-counted pointer member at
// 0x84, float field copies, and three float constant groups.

struct RefObj90 {
    virtual void r0();
    virtual void r1();
    int refcount;
};

struct Src90 {
    int       unk00;
    RefObj90* ptr04;
    float     f08;
    int       unk0c;
    float     f10;
    float     f14;
    float     f18;
    float     f1c;
};

extern void* (__stdcall* DAT_00d9b064)(void*);
extern void* (__stdcall* DAT_00d9b068)(void*);
const float DAT_00de6e60 = 3.40282001837565596e38f;
const float DAT_00de731c = -3.40282001837565596e38f;

struct Base90 {
    Base90(int);
    ~Base90();
};

struct Ptr90 {
    RefObj90* m_ptr;
    Ptr90() : m_ptr(0) {}
    ~Ptr90();
};

inline void AssignRef90(RefObj90*& dst, const Src90& s) {
    if (dst != s.ptr04) {
        RefObj90* old = dst;
        if (old) {
            if (DAT_00d9b064(&old->refcount) == 0)
                old->r1();
        }
        dst = s.ptr04;
        if (dst)
            DAT_00d9b068(&dst->refcount);
    }
}

inline void SetFields90(float* p, float v) {
    p[0] = v;
    p[1] = v;
    p[2] = v;
}

struct FUN_0090f7a0 : Base90 {
    void*  field0;
    int    unk04;
    int    unk08;
    int    unk0c;
    void*  ptr10;
    char   pad0[0x4c];
    float  f60, f64, f68, f6c, f70, f74, f78, f7c;
    void*  unk80;
    Ptr90  unk84;
    char   pad2[8];
    float  f90, f94, f98, f9c;
    float  fA0;

    FUN_0090f7a0(const Src90& s);
};

FUN_0090f7a0::FUN_0090f7a0(const Src90& s)
    : Base90(0x1f), field0(&DAT_00e35fc8), ptr10(&DAT_00e35fa4) {
    AssignRef90(unk84.m_ptr, s);
    fA0 = s.f08;
    f90 = s.f10;
    f94 = s.f14;
    f98 = s.f18;
    f9c = s.f1c;
    float v = DAT_00de6e60;
    f60 = v;
    f64 = v;
    f68 = v;
    f6c = 0.0f;
    v = DAT_00de731c;
    f70 = v;
    f74 = v;
    f78 = v;
    f7c = 0.0f;
}
}   // namespace f3m_0090f7a0

// @f3 0x00907450 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00907450 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
struct Entity38; struct Action38;
struct Heap38 { void FUN_008f6d90(void*,int,int); };
struct Array38 {
    Entity38** data; int count; int capacity; Entity38* local[4];
    Array38():data(local),count(0),capacity(0x80000004) {}
    ~Array38() { if(!(capacity&0x80000000u)) { int size=capacity&0x3fffffff; Heap38* heap=(Heap38*)DAT_00d9b080(DAT_010f3170); heap->FUN_008f6d90(data,size*4,0x17); } }
};
struct Island38 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short index;
    unsigned short unk22;
    unsigned char unk24, flags;
    void FUN_0098ae20(Action38*);
    void hkpSimulationIsland_addAction(Action38*);
};
struct Action38 {
    virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void GetEntities(Array38&) throw();
    int unk04,unk08;
    Island38* island;
};
struct ActionArray38 {
    Action38** data;
    unsigned short count,capacity;
    int IndexOf(Action38* action) const { int limit=count; for(int i=0;i<limit;++i) if(data[i]==action) return i; return -1; }
    void RemoveAt(int index) { --count; data[index]=data[(unsigned short)count]; }
};
struct Entity38 {
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
    Island38* island;
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
    ActionArray38 actions;
};
// pdb: hkpWorld::detachActionFromEntity | hkpWorld.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
void __stdcall hkpWorld_detachActionFromEntity(Action38* action,Entity38* entity) throw() {
    entity->actions.RemoveAt(entity->actions.IndexOf(action));
    Island38* island=entity->island;
    island->flags=(island->flags&~2)|1;
    Array38 entities;
    action->GetEntities(entities);
    Island38* destination=0;
    for(int i=0;i<entities.count;++i) {
        if(entities.data[i]!=entity) {
            destination=entities.data[i]->island;
            if(destination->index!=0xffff) break;
        }
    }
    if(destination!=action->island) {
        action->island->FUN_0098ae20(action);
        destination->hkpSimulationIsland_addAction(action);
    }
}
}   // namespace f3m_00907450

// @f3 0x00915c10 (community match, verified in this file)
#include <stdlib.h>
extern const double DAT_00dba730;
extern float DAT_00db38b8;
namespace f3m_00915c10 {

struct SerializedPoint {
    float first;
    float second;
    float third;
    SerializedPoint(float a=-1.0f,float b=0.0f) { first=a; third=(float)(b/100.0); second=third; }
};

typedef int (*ReadFn)(void* self, void* dest, unsigned int size, unsigned int* length, int mode);

struct StreamReader {
    void* unk00;
    int unk04;
    ReadFn fn08;
    __forceinline void ReadCount(unsigned int& count) {
        unsigned int length=4;
        unk04+=fn08(this,&count,4,&length,1);
    }
};

struct LoadStream {
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
    unsigned char unk1e4,nativeEndian;
    unsigned short unk1e6;
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
    StreamReader* reader;
};


struct PointArray {
    int unk00;
    int unk04;
    int capacity;
    int count;
    int unk10;
    int growth;
    void FUN_009147c0(unsigned int newSize);
    void FUN_00914b20(unsigned int index, const SerializedPoint* value);
    __forceinline void Append(const SerializedPoint& value) {
        unsigned int index = count;
        if (index >= (unsigned int)capacity)
            FUN_009147c0(growth + index);
        FUN_00914b20(index, &value);
    }
};

struct Loader {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c,
        unk20, unk24, unk28, unk2c, unk30, unk34;
    PointArray points;

    void FUN_008381d0(LoadStream* stream);
    void FUN_00915000();
    void FUN_00915c10(LoadStream* stream);
};

// pdb: bhkBlendController::LoadBinary | bhkBlendController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arStream
void Loader::FUN_00915c10(LoadStream* stream)
{
    FUN_008381d0(stream);
    unsigned int count;
    {
        StreamReader* reader = stream->reader;
        reader->ReadCount(count);
    }
    points.FUN_009147c0(count);
    for (unsigned int i=0;i<count;++i) {
        SerializedPoint point;
        StreamReader* ireader = stream->reader;
        ireader->unk04 += ireader->fn08(ireader, &point, 0xc, 0, 0);
        if (stream->nativeEndian != 1)
        {
            *reinterpret_cast<unsigned long*>(&point.second) = _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.second));
            *reinterpret_cast<unsigned long*>(&point.first) = _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.first));
            *reinterpret_cast<unsigned long*>(&point.third) = _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.third));
        }
        points.Append(point);
        unk34 = 0;
        FUN_00915000();
    }
}
}   // namespace f3m_00915c10

// @f3 0x009150b0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_009150b0 {

extern "C" void _ReadWriteBarrier();

// FUN_009150b0 -- __thiscall, this in ecx, callee pops 4 bytes (one pointer arg).
// Reads a count through the host's stream reader, then walks the record array at
// this+0x3c converting each 12-byte record to/from little-endian around the
// stream access, guarded by the host's native-endian byte at 0x1e4.

typedef unsigned int(__cdecl* StreamReadFn9150)(void* self, void* dest, unsigned int size, void* extra, int mode);

struct Stream9150
{
    void* vtbl;
    unsigned int consumed;
    unsigned int unk08;
    StreamReadFn9150 read;
};

struct Record9150
{
    unsigned int first;
    unsigned int second;
    unsigned int third;
};

struct Host9150
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0;
    unsigned char unk1e4;
    unsigned char unk1e5;
    unsigned char unk1e6;
    unsigned char unk1e7;
    unsigned int unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c;
    Stream9150* stream;
};

struct Owner9150
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    Record9150* records;
    unsigned int unk40, unk44;
    unsigned int recordCount;
    void FUN_00838320(Host9150* host);
    void FUN_009150b0(Host9150* host);
};

__forceinline unsigned int ReadChunk9150(Stream9150* reader, void* dest, unsigned int size)
{
    unsigned int length = size;
    return reader->read(reader, dest, size, &length, 1);
}

// pdb: bhkBlendController::SaveBinary | bhkBlendController.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: NiControllerManager::SaveBinary)
// pdb params: arStream
void Owner9150::FUN_009150b0(Host9150* host)
{
    FUN_00838320(host);
    unsigned int count = recordCount;
    {
        Stream9150* reader = host->stream;
        reader->consumed += ReadChunk9150(reader, &count, 4);
    }
    for (unsigned int i = 0; i < count; ++i)
    {
        if (host->unk1e4 != 1)
        {
            records[i].second = _byteswap_ulong(records[i].second); _ReadWriteBarrier();
            records[i].first = _byteswap_ulong(records[i].first); _ReadWriteBarrier();
            records[i].third = _byteswap_ulong(records[i].third); _ReadWriteBarrier();
        }
        {
            Stream9150* reader = host->stream;
            reader->consumed += ReadChunk9150(reader, &records[i], 0xc);
        }
        if (host->unk1e4 != 1)
        {
            records[i].second = _byteswap_ulong(records[i].second); _ReadWriteBarrier();
            records[i].first = _byteswap_ulong(records[i].first); _ReadWriteBarrier();
            records[i].third = _byteswap_ulong(records[i].third); _ReadWriteBarrier();
        }
    }
}
}   // namespace f3m_009150b0

// @f3 0x00904560 (community match, verified in this file)
extern const char DAT_00e34e10[];
namespace f3m_00904560 {
namespace f3m_00904560 {

struct ArrayDescriptor {
    void* data;
    int size;
    unsigned int capacityAndFlags;

    void Init() {
        data = 0;
        size = 0;
        capacityAndFlags = 0x80000000u;
    }
};

struct FUN_00904560 {
    const void* vtable;
    unsigned short unk04;
    unsigned short referenceCount;
    void* unk8;
    void* unkc;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    ArrayDescriptor unk28, unk34, unk40;
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
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    int unk98;
    unsigned short unk9c, unk9e;
    void* unka0;
    void* unka4;
    void* unka8;
    void* unkac;
    void* unkb0;
    void* unkb4;
    void* unkb8;
    void* unkbc;
    void* unkc0;
    void* unkc4;
    void* unkc8;
    void* unkcc;
    void* unkd0;
    void* unkd4;
    void* unkd8;
    void* unkdc;
    void* unke0;
    void* unke4;
    void* unke8;
    void* unkec;
    ArrayDescriptor unkf0;
    ArrayDescriptor unkfc;
    ArrayDescriptor unk108;
    ArrayDescriptor unk114;
    ArrayDescriptor unk120;
    ArrayDescriptor unk12c;
    ArrayDescriptor unk138;
    ArrayDescriptor unk144;
    ArrayDescriptor unk150;
    ArrayDescriptor unk15c;
    ArrayDescriptor unk168;
    ArrayDescriptor unk174;
    ArrayDescriptor unk180;

    FUN_00904560(int finishFlag);
};

FUN_00904560::FUN_00904560(int) {
    referenceCount = 1;
    vtable = DAT_00e34e10;
    unk28.Init();
    unk34.Init();
    unk40.Init();
    unk98 = -47;
    unk9c = 0;
    unkf0.Init();
    unkfc.Init();
    unk108.Init();
    unk114.Init();
    unk120.Init();
    unk12c.Init();
    unk138.Init();
    unk144.Init();
    unk150.Init();
    unk15c.Init();
    unk168.Init();
    unk174.Init();
    unk180.Init();
}
}
}   // namespace f3m_00904560

// @f3 0x0091bd20 (community match, verified in this file)
extern const float DAT_00db75c8;
namespace f3m_0091bd20 {


struct RefObj91bd20 {
    virtual void v0(int flag);
    short refFlag;
    short refCount;
};

struct Counted91bd20;
typedef int (__cdecl *Fn91bd20)(Counted91bd20* self, void* data, int num, int* counter, int flag);
struct Counted91bd20 {
    int unk00;
    int count;
    Fn91bd20 fn;
};

struct Arg91bd20 {
    unsigned char pad00[0xd8];
    unsigned int version;
    unsigned char pad2[0x24c - 0xd8 - 4];
    Counted91bd20* counted;
};

struct Sub91bd20 {
    void* unk00;
    void* unk04;
    void* unk08;
    void hkpBridgeConstraintAtom_init(void* arg);
};

struct Link91bd20 {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Sub91bd20 sub10;
    void* data1c;
};

struct Owner91bd20 {
    void* unk00;
    Link91bd20* link;
    void FUN_008fc680(void* arg0, void* local);
    void FUN_0091bd20(Arg91bd20* arg0, int arg1);
};

void* __cdecl FUN_0097a9e0(void* arg0);

struct Local91bd20 {
    int i0;
    int i1;
    int i2;
    int i3;
    float f;
    int i4;
};

__forceinline int ReadChunk91(Counted91bd20* reader, void* dest, int size)
{
    int length = size;
    return reader->fn(reader, dest, size, &length, 1);
}

void Owner91bd20::FUN_0091bd20(Arg91bd20* arg0, int arg1)
{
    Arg91bd20* a = arg0;
    Local91bd20 local;
    local.f = DAT_00db75c8;
    int n = 0;
    local.i2 = n;
    local.i3 = n;
    local.i4 = n;
    if (arg1 == n)
        FUN_008fc680(a, &local);

    Link91bd20* link = this->link;
    RefObj91bd20* obj = (RefObj91bd20*)FUN_0097a9e0(a);
    if (obj != (RefObj91bd20*)n && obj->refFlag != (short)n)
        ++obj->refCount;
    RefObj91bd20* old = (RefObj91bd20*)link->unk0c;
    if (old != (RefObj91bd20*)n && old->refFlag != (short)n) {
        if (--old->refCount == (short)n)
            old->v0(1);
    }
    link->unk0c = obj;
    link->sub10.hkpBridgeConstraintAtom_init(link);
    if (obj->refFlag != (short)n) {
        if (--obj->refCount == (short)n)
            obj->v0(1);
    }

    Counted91bd20* counted = a->counted;
    counted->count += ReadChunk91(counted, &link->data1c, 4);
    if (a->version < 0x14020005u) {
        Counted91bd20* counted2 = a->counted;
        counted2->count += ReadChunk91(counted2, &arg0, 4);
    }
}
}   // namespace f3m_0091bd20

// @f3 0x0091bec0 (community match, verified in this file)
extern int DAT_0108ffb4;
namespace f3m_0091bec0 {
namespace f3m_0091bec0 {
struct QStream {
    int unk00; unsigned int unk04;
    void* FUN_00a63430();
    unsigned int NiStream_GetNumberOfLinkIDs();
};
struct QArr {
    int* vt; int data; int unk08; int unk0c; int unk10;
    QArr() { vt = &DAT_0108ffb4; data = 0; unk0c = 0; unk10 = 0; unk08 = 1; }
    ~QArr() { vt = &DAT_0108ffb4; FUN_008fbbb0(0); }
    void FUN_008fbbb0(int);
};
struct QObj { void FUN_008fc420(QArr*); };
struct QBaseA { int unk00; };
struct QBaseB { int unk04; int unk08; };
struct QD : QBaseA, QBaseB {
    int unk0c; int unk10;
    void FUN_0091b8c0(int);
};
struct QThis {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual QBaseB* v45(char*);
    void FUN_008fbe70(QStream*);
    void FUN_00c87670(QStream*);
    void FUN_0091bec0(QStream* s);
};
void QThis::FUN_0091bec0(QStream* s)
{
    char buf;
    QD* d = static_cast<QD*>(v45(&buf));
    if (s->unk04 < 6) {
        if (!d) return;
        QObj* o = (QObj*)s->FUN_00a63430();
        if (o) {
            QArr a;
            o->FUN_008fc420(&a);
            d->FUN_0091b8c0(a.data);
            d->unk0c = a.unk0c;
            d->unk10 = a.unk10;
        }
        FUN_00c87670(s);
    } else {
        FUN_008fbe70(s);
        s->NiStream_GetNumberOfLinkIDs();
        s->FUN_00a63430();
        s->FUN_00a63430();
    }
}
}
}   // namespace f3m_0091bec0

// @f3 0x009020b0 (community match, verified in this file)
namespace f3m_009020b0 {
// pdb: hkpNullContactMgr::addContactPointImpl | hkpWorld.obj | fnv360_0721_beta, vtable + skyrim(vtable), high
unsigned short __stdcall hkpNullContactMgr_addContactPointImpl(int a, int b, int c, int d, int e, int f) { return 0; }
}   // namespace f3m_009020b0

// @f3 0x0090efc0 (community match, verified in this file)
namespace f3m_0090efc0 {
int __cdecl FUN_0090efc0() { return 0x16; }
}   // namespace f3m_0090efc0

// @f3 0x00902500 (community match, verified in this file)
namespace f3m_00902500 {
struct Obj902500 { char pad[0x18c]; int value; int FUN_00902500(); };
// pdb: hkpWorld::getBroadPhaseBorder | hkpWorld.obj | tesv_win, call_seq, medium
int Obj902500::FUN_00902500() { return value; }
}   // namespace f3m_00902500

// @f3 0x0090afa0 (community match, verified in this file)
namespace f3m_0090afa0 {
struct Obj90afa0 { char pad[0x98]; int field; int* FUN_0090afa0(); };
int* Obj90afa0::FUN_0090afa0() { return &field; }
}   // namespace f3m_0090afa0

// @f3 0x0090afb0 (community match, verified in this file)
namespace f3m_0090afb0 {
struct O0090afb0 { char pad[0x98]; int field; int* FUN_0090afb0(); };
int* O0090afb0::FUN_0090afb0() { return &field; }
}   // namespace f3m_0090afb0

// @f3 0x0090afc0 (community match, verified in this file)
namespace f3m_0090afc0 {
struct O0090afc0 { char pad[0xa0]; int field; int* FUN_0090afc0(); };
int* O0090afc0::FUN_0090afc0() { return &field; }
}   // namespace f3m_0090afc0

// @f3 0x0090cbe0 (community match, verified in this file)
namespace f3m_0090cbe0 {
struct O0090cbe0 { char pad[0xe0]; int field; int* FUN_0090cbe0(); };
// pdb: hkpRigidBody::getMotionState | hkpRigidBody.obj | fnv360_0822_retail, vtable, medium
int* O0090cbe0::FUN_0090cbe0() { return &field; }
}   // namespace f3m_0090cbe0

// @f3 0x0090dc30 (community match, verified in this file)
namespace f3m_0090dc30 {
struct O0090dc30 { char pad[0xa0]; int field; int* hkpShapePhantom_getMotionState(); };
// pdb: hkpShapePhantom::getMotionState | hkpShapePhantom.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(objrun_open), high
int* O0090dc30::hkpShapePhantom_getMotionState() { return &field; }
}   // namespace f3m_0090dc30

// @f3 0x00902570 (community match, verified in this file)
namespace f3m_00902570 {
struct Inner902570 { void FUN_009830d0(); };
struct O902570 { char pad[0x7c]; Inner902570* inner; void FUN_00902570(); };
// pdb: hkpWorld::queueOperation | hkpWorld.obj | tesv_win, call_seq, medium
void O902570::FUN_00902570() { inner->FUN_009830d0(); }
}   // namespace f3m_00902570

// @f3 0x009023b0 (community match, verified in this file)
namespace f3m_009023b0 {
struct Inner9023b0 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void Target(); };
struct O9023b0 { int unk0; int unk4; Inner9023b0* inner; void FUN_009023b0(); };
// pdb: hkpWorld::getMultithreadConfig | hkpWorld.obj | fnv360_0822_retail, objrun_open, low
// pdb params: config
void O9023b0::FUN_009023b0() { inner->Target(); }
}   // namespace f3m_009023b0

// @f3 0x009037a0 (community match, verified in this file)
namespace f3m_009037a0 {
struct Inner9037a0 { void FUN_00908a00(); };
struct O9037a0 { char pad[0xac]; Inner9037a0* inner; void FUN_009037a0(); };
// pdb: hkpWorld::unlock | hkpWorld.obj | fnv360_0822_debug, objrun_open, low
void O9037a0::FUN_009037a0() { inner->FUN_00908a00(); }
}   // namespace f3m_009037a0

// @f3 0x0090c750 (community match, verified in this file)
namespace f3m_0090c750 {
struct O90c750 { char pad[0x84]; float value; void FUN_0090c750(float v); };
// pdb: hkpRigidBody::isDeactivationEnabled | hkpRigidBody.obj | fnv360_0822_retail, objrun_open, low
void O90c750::FUN_0090c750(float v) { value = v; }
}   // namespace f3m_0090c750

// @f3 0x0090c760 (community match, verified in this file)
namespace f3m_0090c760 {
struct O90c760 { char pad[0x88]; float value; void FUN_0090c760(float v); };
// pdb: hkpRigidBody::getInertiaLocal | hkpRigidBody.obj | fnv360_0822_debug, objrun_open, low
// pdb params: inertia
void O90c760::FUN_0090c760(float v) { value = v; }
}   // namespace f3m_0090c760

// @f3 0x0090b210 (community match, verified in this file)
namespace f3m_0090b210 {
struct O90b210 { char pad[0x9c]; unsigned short lo; char pad2[6]; int hi; int hkpEntity_getNumConstraints(); };
// pdb: hkpEntity::getNumConstraints | hkpEntity.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int O90b210::hkpEntity_getNumConstraints() { return lo + hi; }
}   // namespace f3m_0090b210

// @f3 0x0090c700 (community match, verified in this file)
namespace f3m_0090c700 {
struct O90c700 { char pad[0xd9]; unsigned char tag; int FUN_0090c700(); };
// pdb: hkpRigidBody::isDeactivationEnabled | hkpRigidBody.obj | tesv_win, call_seq, medium
int O90c700::FUN_0090c700() { return (tag != 0xff) + 1; }
}   // namespace f3m_0090c700

// @f3 0x00902550 (community match, verified in this file)
namespace f3m_00902550 {
struct I902550 { void FUN_00983680(); };
struct O902550 { char pad[0x7c]; I902550* inner; int unk80; void FUN_00902550(); };
// pdb: hkpWorld::internal_executePendingBodyOperations | hkpWorld.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpWorld::internal_executePendingOperations)
void O902550::FUN_00902550() { unk80 = 0; inner->FUN_00983680(); }
}   // namespace f3m_00902550

// @f3 0x009037d0 (community match, verified in this file)
namespace f3m_009037d0 {
struct I9037d0 { void FUN_00908a00(); };
struct O9037d0 { char pad[0xa8]; I9037d0* inner; void hkpWorld_lockForIslandSplit(int u); };
// pdb: hkpWorld::lockForIslandSplit | hkpWorld.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void O9037d0::hkpWorld_lockForIslandSplit(int u) { if (inner) inner->FUN_00908a00(); }
}   // namespace f3m_009037d0

// @f3 0x009037b0 (community match, verified in this file)
namespace f3m_009037b0 {
struct FUN_00908a00_Obj {
    void __thiscall FUN_00908a00();
};

struct FUN_009037b0_Obj {
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
    FUN_00908a00_Obj* unkA8;

    void __thiscall hkpWorld_lockIslandForConstraintUpdate(int parameter);
};

// pdb: hkpWorld::lockIslandForConstraintUpdate | hkpWorld.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __thiscall FUN_009037b0_Obj::hkpWorld_lockIslandForConstraintUpdate(int parameter) {
    if (unkA8 != 0) {
        unkA8->FUN_00908a00();
    }
}
}   // namespace f3m_009037b0

// @f3 0x00916370 (community match, verified in this file)
namespace f3m_00916370 {
struct V916370 { float x, y, z, w; };
// pdb: hkpBoxShape::getCentreImpl | hkpBoxShape.obj | tesv_win, objrun, medium
void __stdcall FUN_00916370(V916370* v) { v->x = v->y = v->z = v->w = 0.0f; }
}   // namespace f3m_00916370

// @f3 0x0090a700 (community match, verified in this file)
namespace n90a700 {
struct NiRTTI { const char* name; const NiRTTI* base; };
extern const NiRTTI DAT_010f3220;
struct NiObject {
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI* GetRTTI() const;
    char pad[0xc];
    unsigned int mask;
};
struct Holder { char pad[0xc]; NiObject* obj; };
inline bool IsKind(const NiObject* o)
{
    for (const NiRTTI* r = o->GetRTTI(); r; r = r->base)
        if (r == &DAT_010f3220)
            return true;
    return false;
}
struct Filter {
    int unk00;
    unsigned int flags;
    NiObject* FUN_0090a700(Holder* h);
};
NiObject* Filter::FUN_0090a700(Holder* h)
{
    if (h) {
        NiObject* o = h->obj;
        if (o) {
            NiObject* p = IsKind(o) ? o : 0;
            if (p && (p->mask & flags))
                return p;
        }
    }
    return 0;
}
}

// @f3 0x00908f90 (community match, verified in this file)
namespace f3m_00908f90 {
namespace batch14_19 {
struct Array {unsigned table;void* data;unsigned short capacity,count,u0c,grow;unsigned Count()const{return count;}unsigned Capacity()const{return capacity;}unsigned Grow()const{return grow;}void FUN_00555790(unsigned);void FUN_005b3880(unsigned,void**);void Append(void* value){unsigned n=Count();if(n>=Capacity())FUN_00555790(n+Grow());FUN_005b3880(n,&value);}};
extern const double DAT_00db88e8;extern unsigned DAT_00e3512c,DAT_00e35120;extern void* DAT_010f3234;void* FUN_00847b50(void*);
struct Vector {float x,y,z;void* FUN_00823dc0(unsigned*);Vector Scaled()const{Vector v;v.x=(float)(x*DAT_00db88e8);v.y=(float)(y*DAT_00db88e8);v.z=(float)(z*DAT_00db88e8);return v;}};
struct Owner {unsigned unk000;unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;unsigned unk02c;unsigned unk030;unsigned unk034;unsigned unk038;unsigned unk03c;unsigned unk040;unsigned unk044;unsigned unk048;unsigned unk04c;unsigned unk050;unsigned unk054;unsigned unk058;unsigned unk05c;unsigned unk060;unsigned unk064;unsigned unk068;unsigned unk06c;unsigned unk070;unsigned unk074;unsigned unk078;unsigned unk07c;unsigned unk080;unsigned unk084;unsigned unk088;unsigned unk08c;unsigned unk090;unsigned unk094;unsigned unk098;unsigned unk09c;Vector first;unsigned uac;Vector second;void FUN_008d6710(Array*);void FUN_00908f90(Array*);};
// pdb: bhkWorldM::GetViewerStrings | bhkWorldM.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Owner::FUN_00908f90(Array* array){FUN_008d6710(array);array->Append(FUN_00847b50(DAT_010f3234));array->Append(first.Scaled().FUN_00823dc0(&DAT_00e3512c));array->Append(second.Scaled().FUN_00823dc0(&DAT_00e35120));}
}
}   // namespace f3m_00908f90

// @f3 0x009022f0 (community match, verified in this file)
namespace f3m_009022f0 {
struct I9022f0 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void Set(float v); };
struct O9022f0 { int unk0; int unk4; I9022f0* inner; void FUN_009022f0(float v); };
void O9022f0::FUN_009022f0(float v) { inner->Set(v); }
}   // namespace f3m_009022f0

// @f3 0x0090cdf0 (community match, verified in this file)
namespace f3m_0090cdf0 {
struct O90cdf0 { char pad[0xd8]; unsigned char type; char pad2[0x10f]; int val; int hkpRigidBody_getStoredDynamicMotion(); };
// pdb: hkpRigidBody::getStoredDynamicMotion | hkpRigidBody.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int O90cdf0::hkpRigidBody_getStoredDynamicMotion() { unsigned char t = type; if (t == 6 || t == 7) return val; return 0; }
}   // namespace f3m_0090cdf0

// @f3 0x0090ce10 (community match, verified in this file)
namespace f3m_0090ce10 {
struct O90ce10 { char pad[0xd8]; unsigned char type; char pad2[0x10f]; int val; int FUN_0090ce10(); };
// pdb: hkpRigidBody::getStoredDynamicMotion | hkpRigidBody.obj | fnv360_0822_retail, objrun_open, low
int O90ce10::FUN_0090ce10() { unsigned char t = type; if (t == 6 || t == 7) return val; return 0; }
}   // namespace f3m_0090ce10

// @f3 0x00902580 (community match, verified in this file)
namespace f3m_00902580 {
namespace f3m_00902580 { extern void (__stdcall* DAT_00d9b0a0)(void* p); struct H { char pad[0x18]; int a; int b; }; struct O { char pad[0xac]; H* inner; void FUN_00902580(); }; void O::FUN_00902580() { H* h = inner; h->a = -1; h->b = -1; DAT_00d9b0a0(h); } }
}   // namespace f3m_00902580

// @f3 0x0091bea0 (community match, verified in this file)
namespace f3m_0091bea0 {
namespace f3m_0091bea0 { extern char DAT_00e36824; }
struct O0091bea0 { void* vt; int a4, a8, ac, a10; O0091bea0* FUN_0091bea0(); };
// pdb: hkMalleableConstraintCinfo::SetStrength | bhkMalleableConstraint.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkEnum<enum hkpConstraintAtom::AtomType,unsigned short>::hkEnum<enum hkpConstraintAtom::AtomType,unsigned short>)
// pdb params: afStrength
O0091bea0* O0091bea0::FUN_0091bea0() { a4 = 0; ac = 0; a10 = 0; a8 = 1; vt = &f3m_0091bea0::DAT_00e36824; return this; }
}   // namespace f3m_0091bea0

// @f3 0x0090c730 (community match, verified in this file)
namespace f3m_0090c730 {
struct S90c730 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void Set(float v); };
struct O90c730 { char pad[0xd0]; void FUN_0090c730(float v); };
void O90c730::FUN_0090c730(float v) { ((S90c730*)((char*)this + 0xd0))->Set(v); }
}   // namespace f3m_0090c730

// @f3 0x0090a890 (community match, verified in this file)
namespace f3m_0090a890 {
struct O90a890 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual int Get(int a); void FUN_0090a800(int v); void FUN_0090a890(int a); };
// pdb: bhkEntityListener::entityAddedCallback | bhkEntityListener.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apEntity
void O90a890::FUN_0090a890(int a) { FUN_0090a800(Get(a)); }
}   // namespace f3m_0090a890

// @f3 0x009022b0 (community match, verified in this file)
namespace f3m_009022b0 {
struct V009022b0 { float x, y, z, w; };
struct O009022b0 { char pad[0x10]; float x, y, z, w; void FUN_009022b0(const V009022b0* p); };
// pdb: hkpWorld::setGravity | hkpWorld.obj | tesv_win, objrun, medium
void O009022b0::FUN_009022b0(const V009022b0* p) { x = p->x; y = p->y; z = p->z; w = p->w; }
}   // namespace f3m_009022b0

// @f3 0x0091ddb0 (community match, verified in this file)
namespace f3m_0091ddb0 {
struct V0091ddb0 { float x, y, z, w; };
struct O0091ddb0 { char pad[0x10]; float x, y, z, w; void hkpCharacterProxy_setLinearVelocity(const V0091ddb0* p); };
// pdb: hkpCharacterProxy::setLinearVelocity | hkpCharacterProxy.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void O0091ddb0::hkpCharacterProxy_setLinearVelocity(const V0091ddb0* p) { x = p->x; y = p->y; z = p->z; w = p->w; }
}   // namespace f3m_0091ddb0

// @f3 0x00916240 (community match, verified in this file)
namespace f3m_00916240 {
struct V00916240 { float x, y, z, w; };
struct O00916240 { char pad[0x20]; float x, y, z, w; void FUN_00916240(V00916240* out); };
// pdb: hkpBoxShape::getFirstVertex | hkpBoxShape.obj | tesv_win, objrun, medium
void O00916240::FUN_00916240(V00916240* out) { out->x = x; out->y = y; out->z = z; out->w = w; }
}   // namespace f3m_00916240

// @f3 0x00912cb0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00912cb0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Memory912 { void FUN_008f6d90(void*,int,int); };
template<class T> struct Array912 {
    T* data00;
    int size04;
    int capacityAndFlags08;
    __forceinline ~Array912() {
        if((capacityAndFlags08&0x80000000u)==0) {
            int capacity=capacityAndFlags08&0x3fffffff;
            Memory912* memory=static_cast<Memory912*>(TlsGetValue(DAT_010f3170));
            memory->FUN_008f6d90(data00,capacity*sizeof(T),23);
        }
    }
};
struct FUN_00912cb0 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Array912<unsigned int> array24;
    Array912<unsigned int> array30;
    Array912<unsigned int> array3c;
    Array912<unsigned int> array48;
    Array912<unsigned char> array54;
    Array912<unsigned int> array60;
    Array912<unsigned int> array6c;
    Array912<unsigned int> array78;
    Array912<unsigned int> array84;
    Array912<unsigned int> array90;
    Array912<unsigned int> array9c;
    Array912<unsigned int> arraya8;
    ~FUN_00912cb0();
};
// pdb: hkpMeshShapeCinfo::~hkpMeshShapeCinfo | bhkNiTriStripsShape.obj | fnv360_0822_retail, call_gap_sim, medium
FUN_00912cb0::~FUN_00912cb0() {}

}   // namespace f3m_00912cb0

// @f3 0x0091b5a0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace AvoidSetupFast
{
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
struct Vector4
{
    float x, y, z, w;
    __forceinline void Copy(const Vector4& source)
    { x=source.x; y=source.y; z=source.z; w=source.w; }
};
extern Vector4 DAT_01092a50;
struct Source
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Vector4 first, second;
};
struct Heap
{
    void* FUN_008f6d30(int bytes, int kind);
};
extern void __cdecl FUN_0090df10(void* memory);
class hkAvoidBox
{
public:
    virtual ~hkAvoidBox();
    unsigned short memorySizeAndFlags;
    short referenceCount;
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
    hkAvoidBox(Source* source);
    void FUN_009316f0();
    static void* operator new(unsigned int size)
    {
        Heap* heap=static_cast<Heap*>(DAT_00d9b080(DAT_010f3170));
        hkAvoidBox* memory=static_cast<hkAvoidBox*>(heap->FUN_008f6d30(size, 0x31));
        memory->memorySizeAndFlags=static_cast<unsigned short>(size);
        return memory;
    }
    static void operator delete(void* memory)
    { FUN_0090df10(memory); }
};
class Owner
{
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void SetAvoidBox(hkAvoidBox* box);
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void SetSource(Source* source);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Vector4 first, second, currentFirst, currentSecond;
    float value60, value64;
    unsigned char flag68, flag69;
    void FUN_0091b5a0(Source* source);
};
}

void AvoidSetupFast::Owner::FUN_0091b5a0(Source* source)
{
    value64 = 0.0f;
    currentFirst.Copy(DAT_01092a50);
    currentSecond.Copy(DAT_01092a50);
    flag68 = 0;
    flag69 = 0;
    value60 = 0.0f;
    if (source)
    {
        first.Copy(source->first);
        second.Copy(source->second);
        hkAvoidBox* box = new hkAvoidBox(source);
        SetAvoidBox(box);
        box->FUN_009316f0();
        SetSource(source);
    }
}

// @f3 0x0090df10 (community match, verified in this file)
namespace f3m_0090df10 {
namespace f3m_0090df10 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
// pdb: hkpPhantom::operator delete | hkpShapePhantom.obj | fnv360_0822_debug, objrun_open, low
// pdb params: p
void __cdecl FUN_0090df10(f3m_0090df10::P* p) { f3m_0090df10::T* t = (f3m_0090df10::T*)f3m_0090df10::DAT_00d9b080(f3m_0090df10::DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x31); }
}   // namespace f3m_0090df10

// @f3 0x0091d3d0 (community match, verified in this file)
namespace f3m_0091d3d0 {
namespace f3m_0091d3d0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
void __cdecl FUN_0091d3d0(f3m_0091d3d0::P* p) { f3m_0091d3d0::T* t = (f3m_0091d3d0::T*)f3m_0091d3d0::DAT_00d9b080(f3m_0091d3d0::DAT_010f3170); t->FUN_008f6d90(p, p->w, 8); }
}   // namespace f3m_0091d3d0

// @f3 0x009025e0 (community match, verified in this file)
namespace f3m_009025e0 {
// pdb: hkpWorld::unlockIslandForConstraintUpdate | hkpWorld.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
namespace f3m_009025e0 { extern void (__stdcall* DAT_00d9b0a0)(void* p); struct H { char pad[0x18]; int a; int b; }; struct O { char pad[0xa8]; H* inner; void hkpWorld_unlockIslandForConstraintUpdate(int u); }; void O::hkpWorld_unlockIslandForConstraintUpdate(int u) { H* h = inner; if (h) { h->a = -1; h->b = -1; DAT_00d9b0a0(h); } } }
}   // namespace f3m_009025e0

// @f3 0x00902600 (community match, verified in this file)
namespace f3m_00902600 {
// pdb: hkpWorld::unlockForIslandSplit | hkpWorld.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
namespace f3m_00902600 { extern void (__stdcall* DAT_00d9b0a0)(void* p); struct H { char pad[0x18]; int a; int b; }; struct O { char pad[0xa8]; H* inner; void hkpWorld_unlockForIslandSplit(int u); }; void O::hkpWorld_unlockForIslandSplit(int u) { H* h = inner; if (h) { h->a = -1; h->b = -1; DAT_00d9b0a0(h); } } }
}   // namespace f3m_00902600

// @f3 0x0090e980 (community match, verified in this file)
namespace f3m_0090e980 {
struct V { float x, y, z, w; };
struct B0e980 { V a; V b; };
void __stdcall FUN_0090e980(int p, int q, B0e980* v) { v->a.x = v->a.y = v->a.z = v->a.w = 0.0f; v->b.x = v->b.y = v->b.z = v->b.w = 0.0f; }
}   // namespace f3m_0090e980

// @f3 0x0090a6a0 (community match, verified in this file)
namespace f3m_0090a6a0 {
namespace f3m_0090a6a0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct R { char pad[4]; unsigned short w; void FUN_0090a580(); }; struct T { R* FUN_008f6d30(int a, int b); }; }
// pdb: hkDebugDisplaycreate | hkDebugDisplay.obj | fnv360_0822_retail, objrun, medium
void __cdecl FUN_0090a6a0() { f3m_0090a6a0::T* t = (f3m_0090a6a0::T*)f3m_0090a6a0::DAT_00d9b080(f3m_0090a6a0::DAT_010f3170); f3m_0090a6a0::R* r = t->FUN_008f6d30(0x18, 0x35); r->w = 0x18; r->FUN_0090a580(); }
}   // namespace f3m_0090a6a0

// @f3 0x0090d680 (community match, verified in this file)
namespace f3m_0090d680 {
struct S90d680 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void Slot15(int a); };
void __cdecl FUN_0090d520(void* o);
struct O90d680 { char pad[0xd0]; void hkpRigidBody_setTransform(int a); };
// pdb: hkpRigidBody::setTransform | hkpRigidBody.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_gap_sim), high
void O90d680::hkpRigidBody_setTransform(int a) { ((S90d680*)((char*)this + 0xd0))->Slot15(a); FUN_0090d520(this); }
}   // namespace f3m_0090d680

// @f3 0x0090d8d0 (community match, verified in this file)
namespace f3m_0090d8d0 {
struct Base90d8d0 { virtual ~Base90d8d0(); int x4; Base90d8d0(int a, int b, int c); };
struct FUN_0090d8d0 : Base90d8d0 { unsigned char kind; virtual ~FUN_0090d8d0(); FUN_0090d8d0(int a, int b); };
// pdb: hkAllocateChunk<hkVector4> | hkpRigidBody.obj | fnv360_0822_debug, objrun_open, low
// pdb params: numberOfObjects, cl
FUN_0090d8d0::FUN_0090d8d0(int a, int b) : Base90d8d0(a, b, 0) { kind = 3; }
}   // namespace f3m_0090d8d0

// @f3 0x0090d900 (community match, verified in this file)
namespace f3m_0090d900 {
struct Base90d900 { virtual ~Base90d900(); int x4; Base90d900(int a, int b, int c); };
struct FUN_0090d900 : Base90d900 { unsigned char kind; virtual ~FUN_0090d900(); FUN_0090d900(int a, int b); };
// pdb: hkpCharacterMotion::hkpCharacterMotion | hkpRigidBody.obj | tesv_win, call_gap_sim, low
FUN_0090d900::FUN_0090d900(int a, int b) : Base90d900(a, b, 0) { kind = 9; }
}   // namespace f3m_0090d900

// @f3 0x00909120 (community match, verified in this file)
namespace f3m_00909120 {
namespace f3m_00909120 { extern void (__stdcall* DAT_00d9b0a0)(void* p); struct H { char pad[0x18]; int a; int b; void FUN_00908a00(); }; }
struct O909120 { char pad[0xc]; int a0c; int a10; f3m_00909120::H* inner; void FUN_00909120(); };
// pdb: hkDebugDisplay::operator delete | hkDebugDisplay.obj | fnv360_0822_debug, objrun_sim, low
// pdb params: p
void O909120::FUN_00909120() { using namespace f3m_00909120; inner->FUN_00908a00(); a0c = 0; H* h = inner; h->a = -1; h->b = -1; DAT_00d9b0a0(h); }
}   // namespace f3m_00909120

// @f3 0x00912bb0 (community match, verified in this file)
namespace n912bb0 {
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* memory); };
extern Heap DAT_01090a78;
void __cdecl FUN_0089e890(void* p);
struct Arr {
    void* m_pBase;
    virtual ~Arr() { FUN_0089e890(m_pBase); }
};
struct Data {
    int unk00;
    int unk04;
    Arr arr;
};
inline void AlignedFree(void* p)
{
    unsigned char* q = (unsigned char*)p;
    DAT_01090a78.FUN_0086ba60(q - q[-1]);
}
struct Obj {
    char pad[0xc];
    Data* data;
    void FUN_00912bb0(bool release);
};
// pdb: bhkNiTriStripsShape::KillCinfo | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: abCreated
void Obj::FUN_00912bb0(bool release)
{
    if (release) {
        Data* d = data;
        if (d) {
            d->~Data();
            AlignedFree(d);
        }
        data = 0;
    }
}
}

// @f3 0x0091dd70 (community match, verified in this file)
namespace f3m_0091dd70 {
struct S91dd70 { void FUN_0090dda0(int a, float v); };
struct O91dd70 { char pad[0x30]; S91dd70* sub; char pad2[0x24]; float f58, f5c; void hkpCharacterProxy_setPosition(int a); };
// pdb: hkpCharacterProxy::setPosition | hkpCharacterProxy.obj | fnv360_0721_beta, call_seq + skyrim(objrun), high
void O91dd70::hkpCharacterProxy_setPosition(int a) { if (sub) sub->FUN_0090dda0(a, f5c + f58); }
}   // namespace f3m_0091dd70

// @f3 0x0091b760 (community match, verified in this file)
namespace f3m_0091b760 {
struct P91b760 { int u0; unsigned int u4; void FUN_0082b560(); };
void __stdcall FUN_008fbce0(P91b760* p);
struct O91b760 { void FUN_008f7ea0(P91b760* p); void FUN_0091b760(P91b760* p); };
// pdb: bhkCharacterProxy::LoadBinary | bhkCharacterProxy.obj | fnv360_0822_debug, caller_sim, low
// pdb params: arStream
void O91b760::FUN_0091b760(P91b760* p) { if (p->u4 < 6) { p->FUN_0082b560(); FUN_008f7ea0(p); } else FUN_008fbce0(p); }
}   // namespace f3m_0091b760

// @f3 0x0090b250 (community match, verified in this file)
namespace f3m_0090b250 {
struct E90b250 { int first; char pad[0x2c]; };
struct O90b250 { char pad[0x98]; E90b250* arrA; unsigned short n; char pad2[2]; int* arrB; int hkpEntity_getConstraint(int i); };
// pdb: hkpEntity::getConstraint | hkpEntity.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int O90b250::hkpEntity_getConstraint(int i) { if (i < n) return arrA[i].first; return arrB[i - n]; }
}   // namespace f3m_0090b250

// @f3 0x00908960 (community match, verified in this file)
namespace f3m_00908960 {
namespace f3m_00908960 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00908960 { char pad[4]; unsigned short w; void FUN_00984160(); O00908960* FUN_00908960(unsigned int flags); };
// pdb: hkpNullCollisionFilter::`scalar deleting destructor' | hkpWorld.obj | fnv360_0822_retail, vtable, high
O00908960* O00908960::FUN_00908960(unsigned int flags) { FUN_00984160(); if (flags & 1) { f3m_00908960::T* t = (f3m_00908960::T*)f3m_00908960::DAT_00d9b080(f3m_00908960::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_00908960

// @f3 0x00908b40 (community match, verified in this file)
namespace f3m_00908b40 {
namespace f3m_00908b40 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00908b40 { char pad[4]; unsigned short w; void FUN_00904690(); O00908b40* FUN_00908b40(unsigned int flags); };
// pdb: hkpWorld::`scalar deleting destructor' | hkpWorld.obj | fnv360_0822_retail, vtable, high
O00908b40* O00908b40::FUN_00908b40(unsigned int flags) { FUN_00904690(); if (flags & 1) { f3m_00908b40::T* t = (f3m_00908b40::T*)f3m_00908b40::DAT_00d9b080(f3m_00908b40::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2f); } return this; }
}   // namespace f3m_00908b40

// @f3 0x0090a6d0 (community match, verified in this file)
namespace f3m_0090a6d0 {
namespace f3m_0090a6d0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090a6d0 { char pad[4]; unsigned short w; void FUN_0090a650(); O0090a6d0* FUN_0090a6d0(unsigned int flags); };
// pdb: hkDebugDisplay::`scalar deleting destructor' | hkDebugDisplay.obj | fnv360_0822_retail, vtable, medium
O0090a6d0* O0090a6d0::FUN_0090a6d0(unsigned int flags) { FUN_0090a650(); if (flags & 1) { f3m_0090a6d0::T* t = (f3m_0090a6d0::T*)f3m_0090a6d0::DAT_00d9b080(f3m_0090a6d0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x35); } return this; }
}   // namespace f3m_0090a6d0

// @f3 0x0090c070 (community match, verified in this file)
namespace f3m_0090c070 {
namespace f3m_0090c070 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090c070 { char pad[4]; unsigned short w; void FUN_0099d300(); O0090c070* FUN_0090c070(unsigned int flags); };
// pdb: hkpKeyframedRigidMotion::`scalar deleting destructor' | hkpEntity.obj | fnv360_0822_retail, vtable_prefix, high
O0090c070* O0090c070::FUN_0090c070(unsigned int flags) { FUN_0099d300(); if (flags & 1) { f3m_0090c070::T* t = (f3m_0090c070::T*)f3m_0090c070::DAT_00d9b080(f3m_0090c070::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2e); } return this; }
}   // namespace f3m_0090c070

// @f3 0x0090c180 (community match, verified in this file)
namespace f3m_0090c180 {
namespace f3m_0090c180 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090c180 { char pad[4]; unsigned short w; void FUN_0090c0a0(); O0090c180* FUN_0090c180(unsigned int flags); };
// pdb: hkpWorldObject::`scalar deleting destructor' | hkpEntity.obj | fnv360_0822_retail, vtable, high
O0090c180* O0090c180::FUN_0090c180(unsigned int flags) { FUN_0090c0a0(); if (flags & 1) { f3m_0090c180::T* t = (f3m_0090c180::T*)f3m_0090c180::DAT_00d9b080(f3m_0090c180::DAT_010f3170); t->FUN_008f6d90(this, w, 0x15); } return this; }
}   // namespace f3m_0090c180

// @f3 0x0090c220 (community match, verified in this file)
namespace f3m_0090c220 {
namespace f3m_0090c220 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090c220 { char pad[4]; unsigned short w; void FUN_0090bf00(); O0090c220* FUN_0090c220(unsigned int flags); };
// pdb: hkpEntity::`scalar deleting destructor' | hkpEntity.obj | fnv360_0822_retail, vtable, high
O0090c220* O0090c220::FUN_0090c220(unsigned int flags) { FUN_0090bf00(); if (flags & 1) { f3m_0090c220::T* t = (f3m_0090c220::T*)f3m_0090c220::DAT_00d9b080(f3m_0090c220::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2d); } return this; }
}   // namespace f3m_0090c220

// @f3 0x0090d930 (community match, verified in this file)
namespace f3m_0090d930 {
namespace f3m_0090d930 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090d930 { char pad[4]; unsigned short w; void FUN_0090c660(); O0090d930* FUN_0090d930(unsigned int flags); };
// pdb: hkpRigidBody::`scalar deleting destructor' | hkpRigidBody.obj | fnv360_0822_retail, vtable, high
O0090d930* O0090d930::FUN_0090d930(unsigned int flags) { FUN_0090c660(); if (flags & 1) { f3m_0090d930::T* t = (f3m_0090d930::T*)f3m_0090d930::DAT_00d9b080(f3m_0090d930::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2d); } return this; }
}   // namespace f3m_0090d930

// @f3 0x0090df30 (community match, verified in this file)
namespace f3m_0090df30 {
namespace f3m_0090df30 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090df30 { char pad[4]; unsigned short w; void FUN_00989aa0(); O0090df30* FUN_0090df30(unsigned int flags); };
// pdb: hkpPhantom::`scalar deleting destructor' | hkpShapePhantom.obj | fnv360_0822_retail, vtable_prefix, high
O0090df30* O0090df30::FUN_0090df30(unsigned int flags) { FUN_00989aa0(); if (flags & 1) { f3m_0090df30::T* t = (f3m_0090df30::T*)f3m_0090df30::DAT_00d9b080(f3m_0090df30::DAT_010f3170); t->FUN_008f6d90(this, w, 0x31); } return this; }
}   // namespace f3m_0090df30

// @f3 0x0090f8a0 (community match, verified in this file)
namespace f3m_0090f8a0 {
namespace f3m_0090f8a0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090f8a0 { char pad[4]; unsigned short w; void FUN_0090f130(); O0090f8a0* FUN_0090f8a0(unsigned int flags); };
// pdb: hkPackedNiTriStripsShape::`scalar deleting destructor' | hkPackedNiTriStripsShape.obj | fnv360_1110_retail, objopen_prop, low, conflict (skyrim: hkpTriangleShape::`scalar deleting destructor')
O0090f8a0* O0090f8a0::FUN_0090f8a0(unsigned int flags) { FUN_0090f130(); if (flags & 1) { f3m_0090f8a0::T* t = (f3m_0090f8a0::T*)f3m_0090f8a0::DAT_00d9b080(f3m_0090f8a0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_0090f8a0

// @f3 0x00916160 (community match, verified in this file)
namespace f3m_00916160 {
namespace f3m_00916160 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00916160 { char pad[4]; unsigned short w; void FUN_00915f00(); O00916160* FUN_00916160(unsigned int flags); };
// pdb: hkpBvShape::`scalar deleting destructor' | hkpBvShape.obj | fnv360_0822_retail, vtable_prefix, high
O00916160* O00916160::FUN_00916160(unsigned int flags) { FUN_00915f00(); if (flags & 1) { f3m_00916160::T* t = (f3m_00916160::T*)f3m_00916160::DAT_00d9b080(f3m_00916160::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_00916160

// @f3 0x00916f20 (community match, verified in this file)
namespace f3m_00916f20 {
namespace f3m_00916f20 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00916f20 { char pad[4]; unsigned short w; void FUN_009161d0(); O00916f20* FUN_00916f20(unsigned int flags); };
// pdb: hkpBoxShape::`scalar deleting destructor' | hkpBoxShape.obj | fnv360_0721_beta, vtable_prefix, medium
O00916f20* O00916f20::FUN_00916f20(unsigned int flags) { FUN_009161d0(); if (flags & 1) { f3m_00916f20::T* t = (f3m_00916f20::T*)f3m_00916f20::DAT_00d9b080(f3m_00916f20::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_00916f20

// @f3 0x0091a240 (community match, verified in this file)
namespace f3m_0091a240 {
namespace f3m_0091a240 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0091a240 { char pad[4]; unsigned short w; void FUN_00919eb0(); O0091a240* FUN_0091a240(unsigned int flags); };
// pdb: hkpCharacterContext::`scalar deleting destructor' | hkpCharacterContext.obj | fnv360_0822_retail, vtable, high
O0091a240* O0091a240::FUN_0091a240(unsigned int flags) { FUN_00919eb0(); if (flags & 1) { f3m_0091a240::T* t = (f3m_0091a240::T*)f3m_0091a240::DAT_00d9b080(f3m_0091a240::DAT_010f3170); t->FUN_008f6d90(this, w, 0x34); } return this; }
}   // namespace f3m_0091a240

// @f3 0x0091b570 (community match, verified in this file)
namespace f3m_0091b570 {
namespace f3m_0091b570 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0091b570 { char pad[4]; unsigned short w; void FUN_0091b4c0(); O0091b570* FUN_0091b570(unsigned int flags); };
// pdb: hkArray<hkpCollidable *,hkContainerHeapAllocator>::pushBack | bhkAvoidBox.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpConstraintData::`vector deleting destructor')
// pdb params: e
O0091b570* O0091b570::FUN_0091b570(unsigned int flags) { FUN_0091b4c0(); if (flags & 1) { f3m_0091b570::T* t = (f3m_0091b570::T*)f3m_0091b570::DAT_00d9b080(f3m_0091b570::DAT_010f3170); t->FUN_008f6d90(this, w, 0x31); } return this; }
}   // namespace f3m_0091b570

// @f3 0x00900710 (community match, verified in this file)
namespace f3m_00900710 {
namespace Memory480 { extern int DAT_010f321c; }
class FUN_0090ac60 { public: virtual ~FUN_0090ac60(); char pad04[0x10]; };
class FUN_005e4e20 { public: ~FUN_005e4e20(); void FUN_005e3010(); int unk00, unk04; };
class FUN_00900710 : public FUN_0090ac60 {
public:
    FUN_005e4e20 member;
    void FUN_008f7ef0();
    virtual ~FUN_00900710();
};
// pdb: bhkRigidBody::~bhkRigidBody | bhkRigidBody.obj | fnv360_0822_retail, call_seq, high
FUN_00900710::~FUN_00900710()
{
    member.FUN_005e3010();
    FUN_008f7ef0();
    --Memory480::DAT_010f321c;
}
}   // namespace f3m_00900710

// @f3 0x0091bad0 (community match, verified in this file)
namespace f3m_0091bad0 {
namespace f3m_0091bad0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0091bad0 { char pad[4]; unsigned short w; void FUN_0095b1e0(); O0091bad0* FUN_0091bad0(unsigned int flags); };
// pdb: hkpMalleableConstraintData::`scalar deleting destructor' | bhkMalleableConstraint.obj | fnv360_0822_retail, vtable_prefix, high
O0091bad0* O0091bad0::FUN_0091bad0(unsigned int flags) { FUN_0095b1e0(); if (flags & 1) { f3m_0091bad0::T* t = (f3m_0091bad0::T*)f3m_0091bad0::DAT_00d9b080(f3m_0091bad0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2c); } return this; }
}   // namespace f3m_0091bad0

// @f3 0x0091ec90 (community match, verified in this file)
namespace f3m_0091ec90 {
struct S91ec90 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void Slot3(int a); };
struct O91ec90 { char pad[0x80]; S91ec90** items; int count; void FUN_0091ec90(int a); };
// pdb: hkpCharacterProxy::fireContactRemoved | hkpCharacterProxy.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: point
void O91ec90::FUN_0091ec90(int a) { for (int i = count - 1; i >= 0; i--) items[i]->Slot3(a); }
}   // namespace f3m_0091ec90

// @f3 0x00902c40 (community match, verified in this file)
namespace f3m_00902c40 {
struct Obj902c40 {
    char pad00[0x168];
    void** data;
    int count;
    int Find(void* p) { for (int i = 0; i < count; ++i) if (data[i] == p) return i; return -1; }
    void FUN_00902c40(void* p);
};
// pdb: hkpWorld::removeIslandPostCollideListener | hkpWorld.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpWorld::removeEntityListener)
// pdb params: islandListener
void Obj902c40::FUN_00902c40(void* p)
{
    data[Find(p)] = 0;
}
}   // namespace f3m_00902c40

// @f3 0x0090c140 (community match, verified in this file)
namespace f3m_0090c140 {
namespace f3m_0090c140 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090c140 { void* vt; unsigned short w; O0090c140* FUN_0090c140(unsigned int flags); };
O0090c140* O0090c140::FUN_0090c140(unsigned int flags) { vt = &f3m_0090c140::DAT_00dcc494; if (flags & 1) { f3m_0090c140::T* t = (f3m_0090c140::T*)f3m_0090c140::DAT_00d9b080(f3m_0090c140::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2e); } return this; }
}   // namespace f3m_0090c140

// @f3 0x0090f740 (community match, verified in this file)
namespace f3m_0090f740 {
namespace f3m_0090f740 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0090f740 { void* vt; unsigned short w; O0090f740* FUN_0090f740(unsigned int flags); };
// pdb: hkpDefaultConvexListFilter::`scalar deleting destructor' | hkpWorld.obj | fnv360_0721_beta, vtable, medium
O0090f740* O0090f740::FUN_0090f740(unsigned int flags) { vt = &f3m_0090f740::DAT_00dcc494; if (flags & 1) { f3m_0090f740::T* t = (f3m_0090f740::T*)f3m_0090f740::DAT_00d9b080(f3m_0090f740::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_0090f740

// @f3 0x00901fb0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00901fb0 {
namespace n901fb0 {
struct Alloc { void* FUN_008f6d30(int size, int tag); void FUN_008f6d90(void* p, int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long);
}
void __cdecl FUN_009234e0(void* dst, const void* src, int n);
struct Arr901fb0 { void* data; int size; int capFlags; };
// pdb: hkArrayUtil::_reduce | hkArrayUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkArrayUtil__reduce(Arr901fb0* arr, int elemSize, void* buf, int cap)
{
    int flag = 0;
    void* p;
    if (buf && arr->size < cap) {
        flag = 0x80000000;
        p = buf;
    } else {
        n901fb0::Alloc* a = n901fb0::FUN_00d9b080(DAT_010f3170);
        p = a->FUN_008f6d30(elemSize * cap, 0x17);
    }
    FUN_009234e0(p, arr->data, arr->size * elemSize);
    int n = arr->capFlags & 0x3fffffff;
    n901fb0::Alloc* a = n901fb0::FUN_00d9b080(DAT_010f3170);
    a->FUN_008f6d90(arr->data, n * elemSize, 0x17);
    arr->data = p;
    arr->capFlags = (arr->capFlags & 0x40000000) | flag | cap;
}
}   // namespace f3m_00901fb0

// @f3 0x00903ae0 (community match, verified in this file)
namespace f3m_00903ae0 {
namespace member_append_1626 {
template<class T> struct Array;
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    Array<unsigned int> values;
    void FUN_00903ae0(unsigned int value);
};
// pdb: hkpWorld::addEntityListener | hkpWorld.obj | fnv360_0822_retail, call_dedup, low
// pdb params: worldListener
void Owner::FUN_00903ae0(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903ae0

// @f3 0x00903b20 (community match, verified in this file)
namespace f3m_00903b20 {
namespace member_append_1627 {
template<class T> struct Array;
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    Array<unsigned int> values;
    void hkpWorld_addPhantomListener(unsigned int value);
};
// pdb: hkpWorld::addPhantomListener | hkpWorld.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(objrun_open), high
void Owner::hkpWorld_addPhantomListener(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903b20

// @f3 0x0091ecc0 (community match, verified in this file)
namespace f3m_0091ecc0 {
namespace append_0091ecc0 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    Array<unsigned int> values;
    void FUN_0091ecc0(unsigned int value);
};
// pdb: hkpCharacterProxy::addCharacterProxyListener | hkpCharacterProxy.obj | fnv360_0721_beta, call_gap, low
// pdb params: cpl
void Owner::FUN_0091ecc0(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_0091ecc0

// @f3 0x00903d20 (community match, verified in this file)
namespace f3m_00903d20 {
namespace append_00903d20 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    Array<unsigned int> values;
    void FUN_00903d20(unsigned int value);
};
// pdb: hkpWorld::addWorldDeletionListener | hkpWorld.obj | fnv360_0721_beta, call_gap, low
// pdb params: worldListener
void Owner::FUN_00903d20(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903d20

// @f3 0x00903ca0 (community match, verified in this file)
namespace f3m_00903ca0 {
namespace append_00903ca0 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void hkpWorld_addIslandPostIntegrateListener(unsigned int value);
};
// pdb: hkpWorld::addIslandPostIntegrateListener | hkpWorld.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
void Owner::hkpWorld_addIslandPostIntegrateListener(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903ca0

// @f3 0x00903d60 (community match, verified in this file)
namespace f3m_00903d60 {
namespace append_00903d60 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00903d60(unsigned int value);
};
// pdb: hkpWorld::addContactImpulseLimitBreachedListener | hkpWorld.obj | tesv_win, objrun_open, low
void Owner::FUN_00903d60(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903d60

// @f3 0x00903ce0 (community match, verified in this file)
namespace f3m_00903ce0 {
namespace append_00903ce0 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00903ce0(unsigned int value);
};
// pdb: hkpWorld::addContactListener | hkpWorld.obj | fnv360_0822_retail, call_dedup, low
// pdb params: collisionListener
void Owner::FUN_00903ce0(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903ce0

// @f3 0x00903c60 (community match, verified in this file)
namespace f3m_00903c60 {
namespace append_00903c60 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void hkpWorld_addIslandPostCollideListener(unsigned int value);
};
// pdb: hkpWorld::addIslandPostCollideListener | hkpWorld.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
void Owner::hkpWorld_addIslandPostCollideListener(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903c60

// @f3 0x00903be0 (community match, verified in this file)
namespace f3m_00903be0 {
namespace append_00903be0 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00903be0(unsigned int value);
};
// pdb: hkpWorld::addWorldPostSimulationListener | hkpWorld.obj | fnv360_0822_retail, call_dedup, low
// pdb params: worldListener
void Owner::FUN_00903be0(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903be0

// @f3 0x00903ba0 (community match, verified in this file)
namespace f3m_00903ba0 {
namespace append_00903ba0 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void hkpWorld_addWorldPostCollideListener(unsigned int value);
};
// pdb: hkpWorld::addWorldPostCollideListener | hkpWorld.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
void Owner::hkpWorld_addWorldPostCollideListener(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903ba0

// @f3 0x00903a60 (community match, verified in this file)
namespace f3m_00903a60 {
namespace f3m_00903a60 { struct Arr { int* data; unsigned int size; unsigned int cap; }; void __cdecl FUN_00901f10(Arr* a, int n); }
struct O00903a60 { char pad[0xf0]; f3m_00903a60::Arr arr; void FUN_00903a60(int v); };
// pdb: hkpWorld::addActionListener | hkpWorld.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkpWorld::addConstraintListener)
// pdb params: worldListener
void O00903a60::FUN_00903a60(int v) { using namespace f3m_00903a60; Arr* a = &arr; unsigned int c = a->cap & 0x3fffffff; if (a->size == c) FUN_00901f10(a, 4); a->data[a->size] = v; a->size++; }
}   // namespace f3m_00903a60

// @f3 0x00903aa0 (community match, verified in this file)
namespace f3m_00903aa0 {
namespace f3m_00903aa0 { struct Arr { int* data; unsigned int size; unsigned int cap; }; void __cdecl FUN_00901f10(Arr* a, int n); }
struct O00903aa0 { char pad[0x114]; f3m_00903aa0::Arr arr; void FUN_00903aa0(int v); };
// pdb: hkpWorld::addConstraintListener | hkpWorld.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpWorld::addEntityListener)
// pdb params: worldListener
void O00903aa0::FUN_00903aa0(int v) { using namespace f3m_00903aa0; Arr* a = &arr; unsigned int c = a->cap & 0x3fffffff; if (a->size == c) FUN_00901f10(a, 4); a->data[a->size] = v; a->size++; }
}   // namespace f3m_00903aa0

// @f3 0x00903b60 (community match, verified in this file)
namespace f3m_00903b60 {
namespace f3m_00903b60 { struct Arr { int* data; unsigned int size; unsigned int cap; }; void __cdecl FUN_00901f10(Arr* a, int n); }
struct O00903b60 { char pad[0x12c]; f3m_00903b60::Arr arr; void FUN_00903b60(int v); };
// pdb: hkpWorld::addIslandActivationListener | hkpWorld.obj | fnv360_0822_retail, call_dedup, low
// pdb params: worldListener
void O00903b60::FUN_00903b60(int v) { using namespace f3m_00903b60; Arr* a = &arr; unsigned int c = a->cap & 0x3fffffff; if (a->size == c) FUN_00901f10(a, 4); a->data[a->size] = v; a->size++; }
}   // namespace f3m_00903b60

// @f3 0x00903c20 (community match, verified in this file)
namespace f3m_00903c20 {
namespace append_00903c20 {
void FUN_00901f10(void*,unsigned int);
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline void Append(T value) {
        if(count==(capacityAndFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[count]=value;
        ++count;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void hkpWorld_addWorldPostIntegrateListener(unsigned int value);
};
// pdb: hkpWorld::addWorldPostIntegrateListener | hkpWorld.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
void Owner::hkpWorld_addWorldPostIntegrateListener(unsigned int value) { values.Append(value); }
}
}   // namespace f3m_00903c20

// @f3 0x0091db80 (community match, verified in this file)
extern const char* DAT_010f3350;
namespace f3m_0091db80 {
namespace register_name_0091db80 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0090c5a0(NameArray*);
    void FUN_0091db80(NameArray*);
};
// pdb: bhkCapsuleShape::GetViewerStrings | bhkCapsuleShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apStrings
void Object::FUN_0091db80(NameArray* names) {
    FUN_0090c5a0(names);
    void* value=FUN_00847b50(DAT_010f3350);
    names->Append(value);
}
}

}   // namespace f3m_0091db80

// @f3 0x0091b180 (community match, verified in this file)
extern const char* DAT_010f332c;
namespace f3m_0091b180 {
namespace register_name_0091b180 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0090e440(NameArray*);
    void FUN_0091b180(NameArray*);
};
void Object::FUN_0091b180(NameArray* names) {
    FUN_0090e440(names);
    void* value=FUN_00847b50(DAT_010f332c);
    names->Append(value);
}
}

}   // namespace f3m_0091b180

// @f3 0x0090e750 (community match, verified in this file)
extern const char* DAT_010f32a4;
namespace f3m_0090e750 {
namespace register_name_0090e750 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0090db50(NameArray*);
    void FUN_0090e750(NameArray*);
};
// pdb: bhkSimpleShapePhantom::GetViewerStrings | bhkSimpleShapePhantom.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apStrings
void Object::FUN_0090e750(NameArray* names) {
    FUN_0090db50(names);
    void* value=FUN_00847b50(DAT_010f32a4);
    names->Append(value);
}
}

}   // namespace f3m_0090e750

// @f3 0x0090e2f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0090e2f0 {
namespace n90e2f0 {
struct Alloc { void* FUN_008f6d30(int size, int tag); void FUN_008f6d90(void* p, int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long);
}
struct Src90e2f0 { int unk00; char pad04[0x1c]; char unk20[4]; };
class Obj90e2f0 {
public:
    Obj90e2f0(void* a, int b);
    void FUN_009316f0();
    static void* operator new(unsigned int)
    {
        n90e2f0::Alloc* a = n90e2f0::FUN_00d9b080(DAT_010f3170);
        Obj90e2f0* o = (Obj90e2f0*)a->FUN_008f6d30(0xd0, 0x31);
        o->memSize = 0xd0;
        return o;
    }
    static void operator delete(void* p);
    int vtbl;
    unsigned short memSize;
};
struct World90e2f0 {
    virtual void v000(); virtual void v001(); virtual void v002(); virtual void v003(); virtual void v004(); virtual void v005(); virtual void v006(); virtual void v007(); virtual void v008(); virtual void v009(); virtual void v010(); virtual void v011(); virtual void v012(); virtual void v013(); virtual void v014(); virtual void v015(); virtual void v016(); virtual void v017(); virtual void v018(); virtual void v019(); virtual void v020(); virtual void v021(); virtual void v022(); virtual void v023(); virtual void v024(); virtual void v025(); virtual void v026(); virtual void v027(); virtual void v028(); virtual void v029(); virtual void v030(); virtual void v031(); virtual void v032(); virtual void v033(); virtual void v034(); 
    virtual void Add(Obj90e2f0* o);
    virtual void v036(); virtual void v037(); virtual void v038(); virtual void v039(); virtual void v040(); virtual void v041(); virtual void v042(); virtual void v043(); virtual void v044(); virtual void v045(); virtual void v046(); 
    virtual void Remove(Src90e2f0* s);
    void FUN_0090e2f0(Src90e2f0* s);
};
// pdb: bhkAabbPhantom::Init | bhkAabbPhantom.obj | fnv360_0721_beta, call_seq, medium
// pdb params: arInfo
void World90e2f0::FUN_0090e2f0(Src90e2f0* s)
{
    if (s) {
        Obj90e2f0* o = new Obj90e2f0(s->unk20, s->unk00);
        Add(o);
        o->FUN_009316f0();
        Remove(s);
    }
}
}   // namespace f3m_0090e2f0

// @f3 0x0090ed60 (community match, verified in this file)
extern const char* DAT_010f32b0;
namespace f3m_0090ed60 {
namespace register_name_0090ed60 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0090c5a0(NameArray*);
    void FUN_0090ed60(NameArray*);
};
// pdb: bhkSphereShape::GetViewerStrings | bhkSphereShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apStrings
void Object::FUN_0090ed60(NameArray* names) {
    FUN_0090c5a0(names);
    void* value=FUN_00847b50(DAT_010f32b0);
    names->Append(value);
}
}

}   // namespace f3m_0090ed60

// @f3 0x0090c3e0 (community match, verified in this file)
extern const char* DAT_010f325c;
namespace f3m_0090c3e0 {
namespace register_name_0090c3e0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_008f7a20(NameArray*);
    void FUN_0090c3e0(NameArray*);
};
// pdb: bhkSphereRepShape::GetViewerStrings | bhkSphereRepShape.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apStrings
void Object::FUN_0090c3e0(NameArray* names) {
    FUN_008f7a20(names);
    void* value=FUN_00847b50(DAT_010f325c);
    names->Append(value);
}
}

}   // namespace f3m_0090c3e0

// @f3 0x00902d80 (community match, verified in this file)
namespace f3m_00902d80 {
namespace remove_value_1672 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00902d80(unsigned int);
};
// pdb: hkpWorld::removeContactImpulseLimitBreachedListener | hkpWorld.obj | tesv_win, objrun_open, low
void Owner::FUN_00902d80(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902d80

// @f3 0x0090a0e0 (community match, verified in this file)
namespace f3m_0090a0e0 {
struct CriticalSection90 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void FUN_00908a00();
};

struct Object90 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34(int a, int b, int c, int d);
};

struct Manager90 {
    int unk00;
    int unk04;
    void** unk08;
    int unk0c;
    int unk10;
    CriticalSection90* unk14;

    void __thiscall FUN_0090a0e0(int a, int b, int c, int d);
};

void __thiscall Manager90::FUN_0090a0e0(int a, int b, int c, int d) {
    CriticalSection90* section = unk14;
    section->FUN_00908a00();

    int index = 0;
    if (unk0c > 0) {
        do {
            Object90* object = static_cast<Object90*>(unk08[index]);
            object->vf34(a, b, c, d);
            ++index;
        } while (index < unk0c);
    }

    section = unk14;
    section->unk18 = -1;
    section->unk1c = -1;
    Memory480::DAT_00d9b0a0(section);
}
}   // namespace f3m_0090a0e0

// @f3 0x009088a0 (community match, verified in this file)
namespace f3m_009088a0 {
namespace f3m_009088a0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O9088a0 { void* vt0; unsigned short w; char pad[2]; void* vt8; O9088a0* FUN_009088a0(unsigned int flags); };
// pdb: hkpNullContactMgrFactory::`scalar deleting destructor' | hkpWorld.obj | fnv360_0822_retail, vtable, high
O9088a0* O9088a0::FUN_009088a0(unsigned int flags) { vt8 = &f3m_009088a0::DAT_00dcc494; vt0 = &f3m_009088a0::DAT_00dcc494; if (flags & 1) { f3m_009088a0::T* t = (f3m_009088a0::T*)f3m_009088a0::DAT_00d9b080(f3m_009088a0::DAT_010f3170); t->FUN_008f6d90(this, w, 4); } return this; }
}   // namespace f3m_009088a0

// @f3 0x00901d60 (community match, verified in this file)
extern const char* DAT_010f3228;
extern const char DAT_00e34a24[];
namespace f3m_00901d60 {
namespace extended_names_00901d60 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct String { char* data; unsigned short length,capacity; void* FUN_00823bc0(const char*); };
struct Object {
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
    String value;
    void FUN_008f4230(NameArray*);
    void FUN_00901d60(NameArray*);
};
// pdb: bhkBlendCollisionObjectAddRotation::AddViewerStrings | bhkBlendCollisionObjectAddRotation.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Object::FUN_00901d60(NameArray* names) {
    FUN_008f4230(names);
    void* handle=FUN_00847b50(DAT_010f3228);
    names->Append(handle);
    handle=value.FUN_00823bc0(DAT_00e34a24);
    names->Append(handle);
}
}
}   // namespace f3m_00901d60

// @f3 0x00902d30 (community match, verified in this file)
namespace f3m_00902d30 {
namespace remove_00902d30 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    Array<unsigned int> values;
    void hkpWorld_removeWorldDeletionListener(unsigned int);
};
// pdb: hkpWorld::removeWorldDeletionListener | hkpWorld.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(objopen_prop), high
void Owner::hkpWorld_removeWorldDeletionListener(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902d30

// @f3 0x00902ce0 (community match, verified in this file)
namespace f3m_00902ce0 {
namespace remove_00902ce0 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00902ce0(unsigned int);
};
// pdb: hkpWorld::removeContactListener | hkpWorld.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkpWorld::removeIslandActivationListener)
// pdb params: collisionListener
void Owner::FUN_00902ce0(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902ce0

// @f3 0x00902bf0 (community match, verified in this file)
namespace f3m_00902bf0 {
namespace remove_00902bf0 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00902bf0(unsigned int);
};
// pdb: hkpWorld::removeWorldPostIntegrateListener | hkpWorld.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpWorld::removeActionListener)
// pdb params: worldListener
void Owner::FUN_00902bf0(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902bf0

// @f3 0x00902ba0 (community match, verified in this file)
namespace f3m_00902ba0 {
namespace remove_00902ba0 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00902ba0(unsigned int);
};
// pdb: hkpWorld::removeWorldPostSimulationListener | hkpWorld.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: NiPointer<class ImageSpaceModifierInstance>::`scalar deleting destructor')
// pdb params: worldListener
void Owner::FUN_00902ba0(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902ba0

// @f3 0x00902c90 (community match, verified in this file)
namespace f3m_00902c90 {
namespace remove_00902c90 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00902c90(unsigned int);
};
// pdb: hkpWorld::removeIslandPostIntegrateListener | hkpWorld.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpWorld::removePhantomListener)
// pdb params: islandListener
void Owner::FUN_00902c90(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902c90

// @f3 0x00902b50 (community match, verified in this file)
namespace f3m_00902b50 {
namespace remove_00902b50 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00902b50(unsigned int);
};
// pdb: hkpWorld::removeWorldPostCollideListener | hkpWorld.obj | fnv360_0822_retail, objrun, medium
// pdb params: worldListener
void Owner::FUN_00902b50(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902b50

// @f3 0x00902b00 (community match, verified in this file)
namespace f3m_00902b00 {
namespace remove_00902b00 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Array<unsigned int> values;
    void FUN_00902b00(unsigned int);
};
// pdb: hkpWorld::removeIslandActivationListener | hkpWorld.obj | fnv360_0822_retail, call_dedup, low
// pdb params: worldListener
void Owner::FUN_00902b00(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902b00

// @f3 0x00902a60 (community match, verified in this file)
namespace f3m_00902a60 {
namespace remove_00902a60 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    Array<unsigned int> values;
    void FUN_00902a60(unsigned int);
};
// pdb: hkpWorld::removeEntityListener | hkpWorld.obj | fnv360_0822_retail, call_gap, low
// pdb params: worldListener
void Owner::FUN_00902a60(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902a60

// @f3 0x00902a10 (community match, verified in this file)
namespace f3m_00902a10 {
namespace remove_00902a10 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    Array<unsigned int> values;
    void FUN_00902a10(unsigned int);
};
// pdb: hkpWorld::removeConstraintListener | hkpWorld.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: worldListener
void Owner::FUN_00902a10(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902a10

// @f3 0x00902ab0 (community match, verified in this file)
namespace f3m_00902ab0 {
namespace remove_00902ab0 {
template<class T> struct Array {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int Find(T value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Owner {
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    Array<unsigned int> values;
    void FUN_00902ab0(unsigned int);
};
// pdb: hkpWorld::removePhantomListener | hkpWorld.obj | fnv360_0822_retail, call_gap, medium
// pdb params: worldListener
void Owner::FUN_00902ab0(unsigned int value) { values.data[values.Find(value)]=0; }
}
}   // namespace f3m_00902ab0

// @f3 0x00900930 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00900930 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace release_pair_array_1695 {
struct Heap { void FUN_008f6d90(void*,int,int); };
struct Entry { unsigned int first,second; };
struct Owner {
    unsigned int unk00,unk04,unk08;
    Entry* data;
    int count;
    int capacityAndFlags;
    void FUN_00900930();
};
// pdb: NI2HK | TESObjectREFR.obj | fnv360_0822_debug, call_gap, low
// pdb params: arhkQ, arNiQ
void Owner::FUN_00900930() {
    if((capacityAndFlags&0x80000000u)==0) {
        int capacity=capacityAndFlags&0x3fffffff;
        Heap* heap=static_cast<Heap*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(data,capacity*sizeof(Entry),0x17);
    }
}
}
}   // namespace f3m_00900930

// @f3 0x009132f0 (community match, verified in this file)
namespace list_parts_viewer_1696 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity,count,liveCount,growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int index,void* const& value) {
        if(index>=count) {
            count=static_cast<unsigned short>(index+1);
            if(value) ++liveCount;
        } else if(value) {
            if(!data[index]) ++liveCount;
        } else if(data[index]) --liveCount;
        data[index]=value;
    }
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
struct ShapeInfo {
    void* vtable;
    unsigned int unk04,unk08;
    unsigned short unknownLow:5;
    unsigned short platform:1;
    unsigned short material:5;
    unsigned short stairs:1;
    unsigned short unknownHigh:4;
    unsigned short unk0e;
};
struct Part { ShapeInfo* shape; unsigned int filterInfo; };
extern const Part DAT_010f32e4;
struct MaterialName { const char* text; __forceinline operator const char*() const { return text; } };
extern const MaterialName DAT_00f79fb0[32];
extern const char* DAT_010f32dc;
extern const char DAT_00e361ac[],DAT_00e361a4[],DAT_00e34128[],DAT_00e34120[],DAT_00e34114[];
void* FUN_00847b50(const char*);
void* FUN_00847d80(const char*,unsigned int);
void* FUN_00847e70(const char*,const char*);
void* FUN_00847b90(const char*,bool);
struct FilterValue {
    unsigned int value;
    void FUN_008f6540(NameArray*);
};
struct ShapeData {
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
    Part* parts;
    unsigned int unk9c;
    unsigned int count;
};
struct ListObject {
    void* vtable;
    unsigned int unk04;
    ShapeData* shapeData;
    void FUN_0096ad10(NameArray*);
    void FUN_009132f0(NameArray*);
};
__forceinline unsigned int GetPartCount(const ListObject* object) {
    if(object && object->shapeData) return object->shapeData->count;
    return 0;
}
__forceinline const Part& GetPart(const ListObject* object,unsigned int index) {
    if(object && object->shapeData) return object->shapeData->parts[index];
    return DAT_010f32e4;
}
__forceinline void DescribePart(const ListObject* object,NameArray* names,unsigned int index) {
    names->Append(FUN_00847d80(DAT_00e361a4,index));
    const Part& part=GetPart(object,index);
    unsigned int material=part.shape ? part.shape->material : 0;
    names->Append(FUN_00847e70(DAT_00e34128,DAT_00f79fb0[material]));
    FilterValue filter={part.filterInfo};
    filter.FUN_008f6540(names);
    bool stairs=false;
    if(part.shape) stairs=part.shape->stairs;
    bool platform=false;
    if(part.shape) platform=part.shape->platform;
    names->Append(FUN_00847b90(DAT_00e34120,stairs));
    names->Append(FUN_00847b90(DAT_00e34114,platform));
}
// pdb: bhkPackedNiTriStripsShape::GetViewerStrings | bhkPackedNiTriStripsShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: apStrings
void ListObject::FUN_009132f0(NameArray* names) {
    FUN_0096ad10(names);
    void* handle=FUN_00847b50(DAT_010f32dc);
    names->Append(handle);
    unsigned int front=GetPartCount(this);
    unsigned int total=front;
    handle=FUN_00847d80(DAT_00e361ac,front);
    names->Append(handle);
    unsigned int tail=0;
    if(front>5) {
        front=5;
        tail=total-5;
        if(tail>3) tail=3;
    }
    for(unsigned int i=0;i<front;++i) DescribePart(this,names,i);
    for(unsigned int i=0;i<tail;++i) DescribePart(this,names,total-i-1);
}
}

// @f3 0x00915eb0 (community match, verified in this file)
namespace f3m_00915eb0 {
namespace f3m_00915eb0 { extern char DAT_00e36408; extern char DAT_00e36400; }
struct O00915eb0 { virtual void v0(); virtual void Slot1(void* a, int b, void* c); virtual void v2(); virtual void Slot3(void* a, int b, int c); virtual void v4(); virtual void v5(); virtual void Slot6(); };
struct H00915eb0 { char pad[0x18]; int field; void FUN_00915eb0(O00915eb0* o); };
void H00915eb0::FUN_00915eb0(O00915eb0* o) { o->Slot1(&f3m_00915eb0::DAT_00e36408, 1, this); o->Slot3(&f3m_00915eb0::DAT_00e36400, 1, field); o->Slot6(); }
}   // namespace f3m_00915eb0

// @f3 0x0090f130 (community match, verified in this file)
namespace f3m_0090f130 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiRefObjectCA3
{
  public:
    virtual ~NiRefObjectCA3();
    virtual void DeleteThis();

    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerCA3
{
  public:
    ~NiPointerCA3()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerCA3& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }

    T* m_pObject;
};
class PrimaryCA3
{
  public:
    virtual ~PrimaryCA3()
    {}

    int unk04, unk08, unk0C;
};
class SecondaryCA3
{
  public:
    virtual ~SecondaryCA3()
    {}
};
class BaseCA3 : public PrimaryCA3, public SecondaryCA3
{
  public:


    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    int unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80;
};
class FUN_0090f130 : public BaseCA3
{
  public:
    virtual ~FUN_0090f130();

    NiPointerCA3<NiRefObjectCA3> m_pReferencedObject;
};
// Destructor that releases the held reference by assigning null to the NiPointer, decrementing the object's ref count.
// @fnv 0x00ca3b90
// pdb: hkPackedNiTriStripsShape::~hkPackedNiTriStripsShape | hkPackedNiTriStripsShape.obj | fnv360_1110_retail, objrun_open, low
FUN_0090f130::~FUN_0090f130()
{
    m_pReferencedObject = 0;
}
}   // namespace f3m_0090f130

// @f3 0x0090db50 (community match, verified in this file)
extern const char* DAT_010f3274;
extern const char DAT_00e347d8[],DAT_00e347dc[];
namespace f3m_0090db50 {
namespace viewer_0090db50 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Matrix3 { float m00,m01,m02,m10,m11,m12,m20,m21,m22; void* FUN_00823bc0(const char*); };
struct Point3 { float x,y,z; void* FUN_00823dc0(const char*); };
struct Transform { Matrix3 rotation; Point3 translation; float scale; };
struct Object {
    void* vtable;
    void FUN_0090da80(Transform*);
    void FUN_0090c320(NameArray*);
    void FUN_0090db50(NameArray*);
};
// pdb: bhkShapePhantom::GetViewerStrings | bhkShapePhantom.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Object::FUN_0090db50(NameArray* names) {
    FUN_0090c320(names);
    void* handle=FUN_00847b50(DAT_010f3274);
    names->Append(handle);
    Transform transform;
    FUN_0090da80(&transform);
    handle=transform.rotation.FUN_00823bc0(DAT_00e347d8); names->Append(handle);
    handle=transform.translation.FUN_00823dc0(DAT_00e347dc); names->Append(handle);
}
}
}   // namespace f3m_0090db50

// @f3 0x0090a140 (community match, verified in this file)
namespace f3m_0090a140 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace forward_0090a140 {
struct Listener {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Notify(unsigned int,unsigned int,unsigned int);
};
struct StateLock {
    unsigned int debugInfo;
    long lockCount,recursionCount;
    void* ownerThread;
    void* semaphore;
    unsigned int spinCount;
    int current18,current1c;
    void FUN_00908a00();
    __forceinline void Finish() { current18=-1; current1c=-1; LeaveCriticalSection(this); }
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Listener** entries;
    int count;
    int capacity;
    StateLock* state;
    void FUN_0090a140(unsigned int,unsigned int,unsigned int);
};
void Owner::FUN_0090a140(unsigned int first,unsigned int second,unsigned int third) {
    state->FUN_00908a00();
    for(int i=0;i<count;++i) entries[i]->Notify(first,second,third);
    state->Finish();
}
}
}   // namespace f3m_0090a140

// @f3 0x0090a020 (community match, verified in this file)
namespace f3m_0090a020 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace forward_0090a020 {
struct Listener {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Notify(unsigned int,unsigned int,unsigned int);
};
struct StateLock {
    unsigned int debugInfo;
    long lockCount,recursionCount;
    void* ownerThread;
    void* semaphore;
    unsigned int spinCount;
    int current18,current1c;
    void FUN_00908a00();
    __forceinline void Finish() { current18=-1; current1c=-1; LeaveCriticalSection(this); }
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Listener** entries;
    int count;
    int capacity;
    StateLock* state;
    void FUN_0090a020(unsigned int,unsigned int,unsigned int);
};
void Owner::FUN_0090a020(unsigned int first,unsigned int second,unsigned int third) {
    state->FUN_00908a00();
    for(int i=0;i<count;++i) entries[i]->Notify(first,second,third);
    state->Finish();
}
}
}   // namespace f3m_0090a020

// @f3 0x009093b0 (community match, verified in this file)
namespace f3m_009093b0 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace forward_009093b0 {
struct Listener {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Notify(unsigned int,unsigned int,unsigned int);
};
struct StateLock {
    unsigned int debugInfo;
    long lockCount,recursionCount;
    void* ownerThread;
    void* semaphore;
    unsigned int spinCount;
    int current18,current1c;
    void FUN_00908a00();
    __forceinline void Finish() { current18=-1; current1c=-1; LeaveCriticalSection(this); }
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Listener** entries;
    int count;
    int capacity;
    StateLock* state;
    void FUN_009093b0(unsigned int,unsigned int,unsigned int);
};
void Owner::FUN_009093b0(unsigned int first,unsigned int second,unsigned int third) {
    state->FUN_00908a00();
    for(int i=0;i<count;++i) entries[i]->Notify(first,second,third);
    state->Finish();
}
}
}   // namespace f3m_009093b0

// @f3 0x009092d0 (community match, verified in this file)
namespace f3m_009092d0 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace forward_009092d0 {
struct Listener {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Notify(unsigned int,unsigned int,unsigned int);
};
struct StateLock {
    unsigned int debugInfo;
    long lockCount,recursionCount;
    void* ownerThread;
    void* semaphore;
    unsigned int spinCount;
    int current18,current1c;
    void FUN_00908a00();
    __forceinline void Finish() { current18=-1; current1c=-1; LeaveCriticalSection(this); }
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Listener** entries;
    int count;
    int capacity;
    StateLock* state;
    void FUN_009092d0(unsigned int,unsigned int,unsigned int);
};
void Owner::FUN_009092d0(unsigned int first,unsigned int second,unsigned int third) {
    state->FUN_00908a00();
    for(int i=0;i<count;++i) entries[i]->Notify(first,second,third);
    state->Finish();
}
}
}   // namespace f3m_009092d0

// @f3 0x00909270 (community match, verified in this file)
namespace f3m_00909270 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace forward_00909270 {
struct Listener {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Notify(unsigned int,unsigned int,unsigned int);
};
struct StateLock {
    unsigned int debugInfo;
    long lockCount,recursionCount;
    void* ownerThread;
    void* semaphore;
    unsigned int spinCount;
    int current18,current1c;
    void FUN_00908a00();
    __forceinline void Finish() { current18=-1; current1c=-1; LeaveCriticalSection(this); }
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Listener** entries;
    int count;
    int capacity;
    StateLock* state;
    void FUN_00909270(unsigned int,unsigned int,unsigned int);
};
void Owner::FUN_00909270(unsigned int first,unsigned int second,unsigned int third) {
    state->FUN_00908a00();
    for(int i=0;i<count;++i) entries[i]->Notify(first,second,third);
    state->Finish();
}
}
}   // namespace f3m_00909270

// @f3 0x00914060 (community match, verified in this file)
extern int DAT_010f32ec;
namespace f3m_00914060 {
namespace dtor_00914060 {
struct FUN_0090c430 {
    virtual ~FUN_0090c430();
};
struct FUN_00914060 : FUN_0090c430 {
    ~FUN_00914060();
    void FUN_008f7ef0();
};
// pdb: bhkBoxShape::~bhkBoxShape | bhkBoxShape.obj | fnv360_0822_retail, call_seq, high
FUN_00914060::~FUN_00914060() {
    FUN_008f7ef0();
    --DAT_010f32ec;
}
}
}   // namespace f3m_00914060

// @f3 0x0090df60 (community match, verified in this file)
extern int DAT_010f3294;
namespace f3m_0090df60 {
namespace dtor_0090df60 {
struct FUN_0090c250 { virtual ~FUN_0090c250(); };
struct FUN_0090df60 : FUN_0090c250 {
    ~FUN_0090df60();
    void FUN_008f7ef0();
};
// pdb: bhkAabbPhantom::~bhkAabbPhantom | bhkAabbPhantom.obj | fnv360_0822_retail, call_seq, high
FUN_0090df60::~FUN_0090df60() {
    FUN_008f7ef0();
    --DAT_010f3294;
}
}
}   // namespace f3m_0090df60

// @f3 0x0090da10 (community match, verified in this file)
extern int DAT_010f3270;
namespace f3m_0090da10 {
namespace dtor_0090da10 {
struct FUN_0090c250 { virtual ~FUN_0090c250(); };
struct FUN_0090da10 : FUN_0090c250 {
    ~FUN_0090da10();
    void FUN_008f7ef0();
};
// pdb: bhkShapePhantom::~bhkShapePhantom | bhkShapePhantom.obj | fnv360_0822_retail, call_seq, high
FUN_0090da10::~FUN_0090da10() {
    FUN_008f7ef0();
    --DAT_010f3270;
}
}
}   // namespace f3m_0090da10

// @f3 0x0090c370 (community match, verified in this file)
extern int DAT_010f3258;
namespace f3m_0090c370 {
namespace dtor_0090c370 {
struct FUN_008f73e0 { virtual ~FUN_008f73e0(); };
struct FUN_0090c370 : FUN_008f73e0 {
    ~FUN_0090c370();
    void FUN_008f7ef0();
};
// pdb: bhkSphereRepShape::~bhkSphereRepShape | bhkSphereRepShape.obj | fnv360_0822_retail, call_seq, high
FUN_0090c370::~FUN_0090c370() {
    FUN_008f7ef0();
    --DAT_010f3258;
}
}
}   // namespace f3m_0090c370

// @f3 0x0090c250 (community match, verified in this file)
extern int DAT_010f324c;
namespace f3m_0090c250 {
namespace dtor_0090c250 {
struct FUN_008f98d0 { virtual ~FUN_008f98d0(); };
struct FUN_0090c250 : FUN_008f98d0 {
    ~FUN_0090c250();
    void FUN_008f7ef0();
};
// pdb: bhkPhantom::~bhkPhantom | bhkPhantom.obj | fnv360_0822_retail, call_seq, high
FUN_0090c250::~FUN_0090c250() {
    FUN_008f7ef0();
    --DAT_010f324c;
}
}
}   // namespace f3m_0090c250

// @f3 0x009089b0 (community match, verified in this file)
namespace f3m_009089b0 {
namespace f3m_009089b0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00e34ac8; extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O9089b0 { void* vt0; unsigned short w; char pad[2]; void* vt8; O9089b0* FUN_009089b0(unsigned int flags); };
// pdb: hkpEntityEntityBroadPhaseListener::`scalar deleting destructor' | hkpEntityEntityBroadPhaseListener.obj | fnv360_0822_retail, vtable, high
O9089b0* O9089b0::FUN_009089b0(unsigned int flags) { void** pb = this ? &vt8 : 0; *pb = &f3m_009089b0::DAT_00e34ac8; vt0 = &f3m_009089b0::DAT_00dcc494; if (flags & 1) { f3m_009089b0::T* t = (f3m_009089b0::T*)f3m_009089b0::DAT_00d9b080(f3m_009089b0::DAT_010f3170); t->FUN_008f6d90(this, w, 4); } return this; }
}   // namespace f3m_009089b0

// @f3 0x0090cf10 (community match, verified in this file)
namespace f3m_0090cf10 {
namespace n90cf10 {
struct Pt { float x, y, z; };
struct Cmd { unsigned char type; void* obj; Pt pos; };
struct World { char pad[0x84]; void* active; void FUN_00902570(Cmd* c); };
struct Sub {
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
    virtual void SetPos(const Pt* p);
};
}
struct Obj90cf10 {
    int f0, f4;
    n90cf10::World* world;
    char pad[0xd0 - 0xc];
    n90cf10::Sub sub;
    void FUN_0090b500();
    void FUN_0090cf10(const n90cf10::Pt* p);
};
// pdb: hkpRigidBody::applyLinearImpulseAsCriticalOperation | hkpRigidBody.obj | tesv_win, objrun_open, low
void Obj90cf10::FUN_0090cf10(const n90cf10::Pt* p)
{
    if (world && world->active) {
        n90cf10::Cmd c;
        c.type = 0x1a;
        c.obj = this;
        c.pos.x = p->x; c.pos.y = p->y; c.pos.z = p->z;
        world->FUN_00902570(&c);
        return;
    }
    FUN_0090b500();
    sub.SetPos(p);
}
}   // namespace f3m_0090cf10

// @f3 0x0090ac60 (community match, verified in this file)
extern int DAT_010f3240;
namespace f3m_0090ac60 {
namespace dtor_0090ac60 {
struct FUN_008f98d0 { virtual ~FUN_008f98d0(); };
struct FUN_0090ac60 : FUN_008f98d0 {
    ~FUN_0090ac60();
    void FUN_008f7ef0();
};
// pdb: bhkEntity::~bhkEntity | bhkEntity.obj | fnv360_0822_retail, call_seq, high
FUN_0090ac60::~FUN_0090ac60() {
    FUN_008f7ef0();
    --DAT_010f3240;
}
}
}   // namespace f3m_0090ac60

// @f3 0x0091d130 (community match, verified in this file)
namespace locked_factory_0091d130 {
extern void (__stdcall* const DAT_00d9b09c)(void*);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
struct CriticalSection {
    void* debugInfo;
    long lockCount,recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned int spinCount;
};
extern CriticalSection DAT_010f3194;
void* FUN_0089eb90(unsigned int);
void FUN_0089e890(void*);
struct FUN_0091d000 {
    unsigned int unk00,unk04,unk08,unk0c,unk10;
    FUN_0091d000();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* object) { FUN_0089e890(object); }
};
struct Owner {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8c();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Attach(FUN_0091d000*,unsigned int);
    FUN_0091d000* FUN_0091d130(unsigned int);
};
// pdb: bhkCapsuleShape::CreateObject | bhkCapsuleShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkCapsuleShape::CreateClone)
FUN_0091d000* Owner::FUN_0091d130(unsigned int argument) {
    DAT_00d9b09c(&DAT_010f3194);
    FUN_0091d000* object=new FUN_0091d000;
    Attach(object,argument);
    DAT_00d9b0a0(&DAT_010f3194);
    return object;
}
}

// @f3 0x009112e0 (community match, verified in this file)
namespace shape_factory_009112e0 {
extern void (__stdcall* const DAT_00d9b09c)(void*);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
struct CriticalSection { void* debugInfo; long lockCount,recursionCount; void* owningThread; void* semaphore; unsigned int spinCount; };
extern CriticalSection DAT_010f3194;
void* FUN_0089eb90(unsigned int);
void FUN_0089e890(void*);
extern int DAT_010f3174,DAT_011692b0,DAT_010f32cc;
struct bhkRefObject {
    virtual ~bhkRefObject();
    virtual void DeleteThis();
    unsigned int references;
    void* referencedObject;
    bhkRefObject();
};
struct bhkShape : bhkRefObject {
    unsigned int unk0c,unk10;
    __forceinline bhkShape() : unk0c(0),unk10(0) { ++DAT_010f3174; }
};
struct bhkShapeCollection : bhkShape {
    __forceinline bhkShapeCollection() { ++DAT_011692b0; }
};
struct bhkPackedNiTriStripsShape : bhkShapeCollection {
    __forceinline bhkPackedNiTriStripsShape() { ++DAT_010f32cc; }
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* object) { FUN_0089e890(object); }
};
struct Owner {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8c();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Attach(bhkPackedNiTriStripsShape*,unsigned int);
    bhkPackedNiTriStripsShape* FUN_009112e0(unsigned int);
};
bhkPackedNiTriStripsShape* Owner::FUN_009112e0(unsigned int argument) {
    DAT_00d9b09c(&DAT_010f3194);
    bhkPackedNiTriStripsShape* object=new bhkPackedNiTriStripsShape;
    Attach(object,argument);
    DAT_00d9b0a0(&DAT_010f3194);
    return object;
}
}

// @f3 0x0090bf00 (community match, verified in this file)
extern const char DAT_00e35ddc[];
namespace f3m_0090bf00 {

namespace f3m_0090bf00 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier();
extern "C" void hkpEntityCallbackUtil_fireEntityDeleted(void*);

struct Mgr90 {
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
void* unk48;
int unk4c;
void FUN_008f6d90(void*,int,int); void FUN_008f6890(int,void*,int);
};

struct Elem48 { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; };

template<class T> struct Wide90 {
 T* data; int count; unsigned int capacity;
 __forceinline void release() {
 if(!(capacity&0x80000000u)) {
 int allocated=capacity&0x3fffffffu;
 Mgr90* m=(Mgr90*)TlsGetValue(DAT_010f3170);
 m->FUN_008f6d90(data,allocated*sizeof(T),23);
 }
 }
};

template<class T> struct Small90 {
 T* data; unsigned short count,capacity;
 __forceinline void release() {
 if(!(capacity&0x8000)) {
 int allocated=capacity&0x3fff;
 Mgr90* m=(Mgr90*)TlsGetValue(DAT_010f3170);
 m->FUN_008f6d90(data,allocated*sizeof(T),23);
 }
 }
};

struct TailTarget90 { void Run(); };

__forceinline void PoolFree90(void* p) {
 Mgr90* m=(Mgr90*)TlsGetValue(DAT_010f3170);
 if(m->unk4c>=m->unk34) m->FUN_008f6890(2,p,4);
 else { _ReadWriteBarrier(); void* next=m->unk48; m->unk4c++; *(void**)p=next; m->unk48=p; }
}

struct Sub90 {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    void FUN_0099d300();
};

struct Dtor90 {
const void* vtbl;
int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;
Small90<Elem48> unk98;
Wide90<void*> unka0;
Wide90<char> unkac;
int unkb8, unkbc, unkc0, unkc4, unkc8;
TailTarget90* unkcc;
Sub90 unkd0;
Small90<void*> unk1f0;
Small90<void*> unk1f8;
void FUN_0090bf00();
void FUN_0090c0a0();
};

// pdb: hkpEntity::~hkpEntity | hkpEntity.obj | tesv_win, callee_sim, low
void Dtor90::FUN_0090bf00() {
 vtbl = DAT_00e35ddc;
 hkpEntityCallbackUtil_fireEntityDeleted(this);
 TailTarget90* t = unkcc;
 if(t) { t->Run(); PoolFree90(t); }
 unk1f8.release();
 unk1f0.release();
 unkd0.FUN_0099d300();
 unkac.release();
 unka0.release();
 unk98.release();
 FUN_0090c0a0();
}
}
}   // namespace f3m_0090bf00

// @f3 0x0091b8c0 (community match, verified in this file)
namespace f3m_0091b8c0 {
namespace n91b8c0 {
class RefObj {
public:
    virtual ~RefObj();
    unsigned short memSizeAndFlags;
    short refCount;
    void AddReference() { if (memSizeAndFlags != 0) ++refCount; }
    void RemoveReference() {
        if (memSizeAndFlags != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
struct Inner { char pad[0xc]; RefObj* obj; };
}
struct Obj91b8c0 {
    int x0;
    n91b8c0::Inner* inner;
    void FUN_0091b8c0(n91b8c0::RefObj* o);
};
void Obj91b8c0::FUN_0091b8c0(n91b8c0::RefObj* o)
{
    n91b8c0::Inner* in = inner;
    if (in) {
        if (o) o->AddReference();
        if (in->obj) in->obj->RemoveReference();
        in->obj = o;
    }
}
}   // namespace f3m_0091b8c0

// @f3 0x0090e570 (community match, verified in this file)
namespace locked_factory_0090e570 {
extern void (__stdcall* const DAT_00d9b09c)(void*);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
struct CriticalSection {
    void* debugInfo;
    long lockCount,recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned int spinCount;
};
extern CriticalSection DAT_010f3194;
void* FUN_0089eb90(unsigned int);
void FUN_0089e890(void*);
struct FUN_008e8e40 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;
    FUN_008e8e40();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* object) { FUN_0089e890(object); }
};
struct Owner {
    void FUN_008f9990(FUN_008e8e40*,unsigned int);
    FUN_008e8e40* FUN_0090e570(unsigned int);
};
// pdb: bhkSimpleShapePhantom::CreateClone | bhkSimpleShapePhantom.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
FUN_008e8e40* Owner::FUN_0090e570(unsigned int argument) {
    DAT_00d9b09c(&DAT_010f3194);
    FUN_008e8e40* object=new FUN_008e8e40;
    FUN_008f9990(object,argument);
    DAT_00d9b0a0(&DAT_010f3194);
    return object;
}
}

// @f3 0x009124e0 (community match, verified in this file)
namespace shape_factory_009124e0 {
extern void (__stdcall* const DAT_00d9b09c)(void*);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
struct CriticalSection { void* debugInfo; long lockCount,recursionCount; void* owningThread; void* semaphore; unsigned int spinCount; };
extern CriticalSection DAT_010f3194;
void* FUN_0089eb90(unsigned int);
void FUN_0089e890(void*);
extern int DAT_010f3174,DAT_011692b0,DAT_010f32d8;
struct bhkRefObject {
    virtual ~bhkRefObject();
    virtual void DeleteThis();
    unsigned int references;
    void* referencedObject;
    bhkRefObject();
};
struct bhkShape : bhkRefObject {
    unsigned int unk0c,unk10;
    __forceinline bhkShape() : unk0c(0),unk10(0) { ++DAT_010f3174; }
};
struct bhkShapeCollection : bhkShape {
    __forceinline bhkShapeCollection() { ++DAT_011692b0; }
};
struct bhkNiTriStripsShape : bhkShapeCollection {
    __forceinline bhkNiTriStripsShape() { ++DAT_010f32d8; }
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* object) { FUN_0089e890(object); }
};
struct Owner {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8c();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Attach(bhkNiTriStripsShape*,unsigned int);
    bhkNiTriStripsShape* FUN_009124e0(unsigned int);
};
// pdb: bhkNiTriStripsShape::CreateObject | bhkNiTriStripsShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkNiTriStripsShape::CreateClone)
bhkNiTriStripsShape* Owner::FUN_009124e0(unsigned int argument) {
    DAT_00d9b09c(&DAT_010f3194);
    bhkNiTriStripsShape* object=new bhkNiTriStripsShape;
    Attach(object,argument);
    DAT_00d9b0a0(&DAT_010f3194);
    return object;
}
}

// @f3 0x0090cf80 (community match, verified in this file)
namespace f3m_0090cf80 {
namespace vector_event_0090cf80 {
struct Owner;
struct Point3 {
    float x,y,z;
    __forceinline Point3(const Point3& source) : x(source.x),y(source.y),z(source.z) {}
};
struct Event {
    unsigned char type;
    Owner* source;
    Point3 value;
    __forceinline Event(Owner* owner,const Point3& point) : type(0x1c),source(owner),value(point) {}
};
struct Manager {
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
    unsigned int active;
    void FUN_00902570(const Event*);
};
struct EmbeddedInterface {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Notify(const Point3&);
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Manager* manager;
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
    EmbeddedInterface fallback;
    void FUN_0090b500();
    void FUN_0090cf80(const Point3&);
};
// pdb: hkpRigidBody::applyAngularImpulseAsCriticalOperation | hkpRigidBody.obj | tesv_win, objrun_open, low
void Owner::FUN_0090cf80(const Point3& point) {
    if(manager && manager->active) {
        Event event(this,point);
        manager->FUN_00902570(&event);
    } else {
        FUN_0090b500();
        fallback.Notify(point);
    }
}
}
}   // namespace f3m_0090cf80

// @f3 0x0090cea0 (community match, verified in this file)
namespace f3m_0090cea0 {
namespace vector_event_0090cea0 {
struct Owner;
struct Point3 {
    float x,y,z;
    __forceinline Point3(const Point3& source) : x(source.x),y(source.y),z(source.z) {}
};
struct Event {
    unsigned char type;
    Owner* source;
    Point3 value;
    __forceinline Event(Owner* owner,const Point3& point) : type(0x19),source(owner),value(point) {}
};
struct Manager {
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
    unsigned int active;
    void FUN_00902570(const Event*);
};
struct EmbeddedInterface {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Notify(const Point3&);
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Manager* manager;
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
    EmbeddedInterface fallback;
    void FUN_0090b500();
    void FUN_0090cea0(const Point3&);
};
// pdb: hkpRigidBody::setAngularVelocityAsCriticalOperation | hkpRigidBody.obj | tesv_win, objrun_open, low
void Owner::FUN_0090cea0(const Point3& point) {
    if(manager && manager->active) {
        Event event(this,point);
        manager->FUN_00902570(&event);
    } else {
        FUN_0090b500();
        fallback.Notify(point);
    }
}
}
}   // namespace f3m_0090cea0

// @f3 0x0091be20 (community match, verified in this file)
extern unsigned long DAT_010f3170;extern int DAT_00e367f0;
namespace f3m_0091be20 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Build350 {
struct Heap{void* FUN_008f6d30(unsigned int,int);};
struct Base{void*vtable;unsigned short memory,refs;unsigned int unk08,unk0c,unk10,unk14,unk18,unk1c;Base();~Base();void FUN_0091ba60();};
Base::Base(){FUN_0091ba60();}
struct Object:Base{Object(){vtable=&DAT_00e367f0;}static void*operator new(unsigned int size){Heap*heap=(Heap*)TlsGetValue(DAT_010f3170);Base*memory=(Base*)heap->FUN_008f6d30(size,44);memory->memory=(unsigned short)size;return memory;}static void operator delete(void*);};
struct Owner{unsigned int unk00;Object*object;unsigned int FUN_0091be20();};
// pdb: hkMalleableConstraintCinfo::CreateData | bhkMalleableConstraint.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: bhkMalleableConstraint::`vector deleting destructor')
unsigned int Owner::FUN_0091be20(){if(!object)object=new Object;return 32;}
}
}   // namespace f3m_0091be20

// @f3 0x0091ebd0 (community match, verified in this file)
namespace f3m_0091ebd0 {
namespace unordered_remove {
template<class T> struct Array { T* data; int count; int capacityAndFlags; __forceinline int Find(T value) const { for(int i=0;i<count;++i)if(data[i]==value)return i;return -1;} };
struct Owner {
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
    Array<unsigned int> values;
    void FUN_0091ebd0(unsigned int value);
};
// pdb: hkpCharacterProxy::fireConstraintsProcessed | hkpCharacterProxy.obj | fnv360_0721_beta, objrun, low
// pdb params: manifold, input
void Owner::FUN_0091ebd0(unsigned int value) { int index=values.Find(value); --values.count; values.data[index]=values.data[values.count]; }
}
}   // namespace f3m_0091ebd0

// @f3 0x0090afd0 (community match, verified in this file)
namespace f3m_0090afd0 {
namespace clear_indirect_value {
template<class T> struct Array { T* data; unsigned short count; unsigned short capacity; __forceinline int Find(T value) const { for(int i=0;i<count;++i)if(data[i]==value)return i;return -1;} };
struct Owner {
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
    Array<unsigned int>* values;
    void hkpEntity_removeEntityActivationListener(unsigned int value);
};
// pdb: hkpEntity::removeEntityActivationListener | hkpEntity.obj | fnv360_0822_retail, call_seq + bridge(call_gap|caller), high
void Owner::hkpEntity_removeEntityActivationListener(unsigned int value) { values->data[values->Find(value)]=0; }
}
}   // namespace f3m_0090afd0

// @f3 0x009024a0 (community match, verified in this file)
namespace f3m_009024a0 {
namespace Bind360{struct Ref{virtual ~Ref();virtual void v4();virtual void v8();virtual void vc();virtual void Detach();unsigned short memory;short refs;unsigned int Count()const{return refs;}void Release(){if(memory){--refs;if((unsigned short)Count()==0)delete this;}}void AddRef(){if(memory)++refs;}};struct Owner{
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
Ref*object;void FUN_009024a0(Ref*);};
// pdb: hkpWorld::setBroadPhaseBorder | hkpWorld.obj | tesv_win, objrun, medium
void Owner::FUN_009024a0(Ref*value){if(object){object->Detach();object->Release();}object=value;if(value)value->AddRef();}
}
}   // namespace f3m_009024a0

// @f3 0x0090cbf0 (community match, verified in this file)
namespace f3m_0090cbf0 {
namespace n90cbf0 {
struct Cmd { char type; void* owner; bool a, b, c; };
struct Queue { char pad[0x84]; int active; void FUN_00902570(Cmd* cmd); };
}
struct FUN_0090cbf0_c {
    int pad0[2];
    n90cbf0::Queue* queue;
    void hkpRigidBody_setMotionType(bool a, bool b, bool c);
};
void __cdecl FUN_00929670(FUN_0090cbf0_c* self, bool a, bool b, bool c);
// pdb: hkpRigidBody::setMotionType | hkpRigidBody.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void FUN_0090cbf0_c::hkpRigidBody_setMotionType(bool a, bool b, bool c)
{
    n90cbf0::Cmd cmd;
    if (queue && queue->active) {
        cmd.owner = this;
        cmd.a = a;
        cmd.b = b;
        cmd.c = c;
        cmd.type = 4;
        queue->FUN_00902570(&cmd);
    } else {
        FUN_00929670(this, a, b, c);
    }
}
}   // namespace f3m_0090cbf0

// @f3 0x009117d0 (community match, verified in this file)
namespace f3m_009117d0 {
namespace collision_filter_lookup {
struct Entry { unsigned int unk00,unk04,filterInfo; };
struct EntryList { 
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned short count,unk12;
    unsigned int unk14,unk18,unk1c,unk20;
    Entry* data;
};
struct ShapeData {
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
    EntryList* entries;
};
struct Filter {
    unsigned int unk00,unk04;
    ShapeData* shapeData;
    unsigned int unk0c,filterInfo;
    ShapeData* GetData() { return this?shapeData:0; }
    unsigned char FUN_009117d0(unsigned int,unsigned int);
};
unsigned char Filter::FUN_009117d0(unsigned int key,unsigned int mask) {
    ShapeData* data=GetData();
    int index=key>>24;
    if(key==0xffffffffu || index>=data->entries->count) return (filterInfo&mask)!=0;
    return (data->entries->data[index].filterInfo&mask)!=0;
}
}
}   // namespace f3m_009117d0

// @f3 0x0090a1a0 (community match, verified in this file)
namespace f3m_0090a1a0 {
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace locked_append_0090a1a0 {
void FUN_00901f10(void*,int);
struct StateLock {
    unsigned int debugInfo;
    long lockCount,recursionCount;
    void* ownerThread;
    void* semaphore;
    unsigned int spinCount;
    int current18,current1c;
    void FUN_00908a00();
    __forceinline void Finish() { current18=-1; current1c=-1; LeaveCriticalSection(this); }
};
template<class T> struct Array {
 T* data;int count;unsigned int capacity;
 void Append(const T& value) { if(count==int(capacity&0x3fffffffu))FUN_00901f10(this,sizeof(T));data[count]=value;++count; }
};
struct Owner {
    void* vtable;
    unsigned int unk04;
    Array<unsigned int> values;
    StateLock* state;
    void FUN_0090a1a0(unsigned int);
};
// pdb: hkDebugDisplay::addDebugDisplayHandler | hkDebugDisplay.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: debugDisplay
void Owner::FUN_0090a1a0(unsigned int value) {
    state->FUN_00908a00();
    values.Append(value);
    state->Finish();
}
}
}   // namespace f3m_0090a1a0

// @f3 0x00917320 (community match, verified in this file)
namespace task0953 {
struct Object;
struct Table {void* slot00;void* slot04;void (__thiscall *Free)(Object*,void*);};
extern Table DAT_00e3655c;
struct MemoryManager {void FUN_0086ba60(void*);};
extern MemoryManager DAT_01090a78;
struct Object {Table* table;void* data;int size,capacity;Object* FUN_00917320(unsigned char);};
// pdb: BSSimpleArray<NiPointer<QueuedFile>,1024>::Clear | QueuedFiles.obj | fnv360_0822_debug, objrun_open, low
// pdb params: abFreeMemory
Object* Object::FUN_00917320(unsigned char flags) {
 void* old=data;
 table=&DAT_00e3655c;
 if(old) {DAT_00e3655c.Free(this,old);data=0;capacity=0;size=0;}
 if(flags&1) DAT_01090a78.FUN_0086ba60(this);
 return this;
}
}

// @f3 0x00908850 (community match, verified in this file)
namespace f3m_00908850 {
struct StepInfo {float start,end,delta,inverse;StepInfo* FUN_00908850(float,float);};
StepInfo* StepInfo::FUN_00908850(float a,float b){start=a;end=b;delta=b-a;inverse=delta==0.0f?0.0f:1.0f/delta;return this;}
}   // namespace f3m_00908850

// @f3 0x0090ad80 (community match, verified in this file)
namespace f3m_0090ad80 {
namespace task0983 {
struct PhysicsAction
{
    bool __thiscall FUN_008d5fe0(void* owner);
};
struct LinkedObject
{
    PhysicsAction* GetAction() const
    {
        return *reinterpret_cast<PhysicsAction* const*>(reinterpret_cast<const char*>(this) + 0x310);
    }
};
struct FUN_0090ad80_Class
{
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
    virtual LinkedObject* ResolveLinkedObject();
    int unk4;
    void* handle;
    bool FUN_0090ad80();
};
// @fnv 0x00c9f420
// pdb: bhkEntity::Remove | bhkEntity.obj | fnv360_0822_retail, objrun, medium
bool FUN_0090ad80_Class::FUN_0090ad80()
{
    bool result = false;
    LinkedObject* linked = ResolveLinkedObject();
    PhysicsAction* action = linked ? linked->GetAction() : 0;
    if (action)
        result = action->FUN_008d5fe0(handle);
    return result;
}


}
}   // namespace f3m_0090ad80

// @f3 0x0090c2c0 (community match, verified in this file)
namespace f3m_0090c2c0 {
namespace collider_query_1621 {

struct Collider { bool FUN_008d60a0(void*); };

struct Body {

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

    unsigned int unkd0;

    unsigned int unkd4;

    unsigned int unkd8;

    unsigned int unkdc;

    unsigned int unke0;

    unsigned int unke4;

    unsigned int unke8;

    unsigned int unkec;

    unsigned int unkf0;

    unsigned int unkf4;

    unsigned int unkf8;

    unsigned int unkfc;

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

    Collider* collider310;
    Collider* GetAction() const {return *reinterpret_cast<Collider* const*>(reinterpret_cast<const char*>(this)+0x310);}

};

struct Query {

    virtual void Unknown00();

    virtual void Unknown04();

    virtual void Unknown08();

    virtual void Unknown0c();

    virtual void Unknown10();

    virtual void Unknown14();

    virtual void Unknown18();

    virtual void Unknown1c();

    virtual void Unknown20();

    virtual void Unknown24();

    virtual void Unknown28();

    virtual void Unknown2c();

    virtual void Unknown30();

    virtual void Unknown34();

    virtual void Unknown38();

    virtual void Unknown3c();

    virtual void Unknown40();

    virtual void Unknown44();

    virtual void Unknown48();

    virtual void Unknown4c();

    virtual void Unknown50();

    virtual void Unknown54();

    virtual void Unknown58();

    virtual void Unknown5c();

    virtual void Unknown60();

    virtual void Unknown64();

    virtual void Unknown68();

    virtual void Unknown6c();

    virtual void Unknown70();

    virtual void Unknown74();

    virtual void Unknown78();

    virtual void Unknown7c();

    virtual void Unknown80();

    virtual void Unknown84();

    virtual void Unknown88();

    virtual void Unknown8c();

    virtual void Unknown90();

    virtual void Unknown94();

    virtual Body* GetBody();

    unsigned int unk04;

    void* token08;

    bool FUN_0090c2c0();

};

// pdb: bhkPhantom::Remove | bhkPhantom.obj | fnv360_0822_retail, call_gap, low
bool Query::FUN_0090c2c0() {

    bool result=false;

    Body* body=GetBody();

    Collider* collider=body ? body->GetAction() : 0;

    if(collider) result=collider->FUN_008d60a0(token08);

    return result;

}

}

}   // namespace f3m_0090c2c0

// @f3 0x0090b570 (community match, verified in this file)
namespace f3m_0090b570 {
namespace Task0990 {
struct Entity;
struct OperationBase {unsigned char type;};
struct Operation:OperationBase {Entity* entity;Operation(){type=0x20;}};
struct World {
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
 int lockCount;
 bool Locked() const {return lockCount!=0;}
 void FUN_00902570(const OperationBase&) throw();
};
struct Entity {
 int unk00,unk04;World* world;
 void FUN_0090b500();void FUN_0090b570();
};
// pdb: hkpEntity::activateAsCriticalOperation | hkpEntity.obj | tesv_win, caller_sim, low
void Entity::FUN_0090b570(){
 if(world && world->Locked()){
  Operation op;op.entity=this;
  world->FUN_00902570(op);return;
 }
 FUN_0090b500();
}
}
}   // namespace f3m_0090b570

// @f3 0x0090c790 (community match, verified in this file)
namespace f3m_0090c790 {
namespace task1089{
struct Member{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void Dispatch(void*);};
struct Object{
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
Member member;void FUN_0090c790(void*);};
void Object::FUN_0090c790(void* p){member.Dispatch(p);}
}
}   // namespace f3m_0090c790

// @f3 0x0090f000 (community match, verified in this file)
namespace f3m_0090f000 {
namespace task1079 {
struct Base {
 virtual ~Base() {}
 virtual void UnknownBase() {}
 unsigned unk04,unk08,unk0c;
};
struct Secondary {
 virtual ~Secondary() {}
 virtual void UnknownSecondary() {}
 unsigned unk04,unk08;
};
struct Derived : Base, Secondary {
 void FUN_0090f000();
 virtual void UnknownBase() {}
 virtual void UnknownSecondary() {}
};
void Derived::FUN_0090f000() { this->Derived::~Derived(); }
}
}   // namespace f3m_0090f000

// @f3 0x0090c770 (community match, verified in this file)
namespace f3m_0090c770 {
namespace task1088 {
struct Interface {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void target(void*);
};
struct Owner {
 void FUN_0090c770(void*);
};
void Owner::FUN_0090c770(void* p) {
 reinterpret_cast<Interface*>(reinterpret_cast<char*>(this)+0xd0)->target(p);
}
}
}   // namespace f3m_0090c770

// @f3 0x009103b0 (community match, verified in this file)
namespace f3m_009103b0 {
namespace task1165 {
void __cdecl FUN_0089e890(void*);
struct PrimaryPart
{
    virtual ~PrimaryPart()
    {}
    unsigned int unknown_04, unknown_08, unknown_0c;
};
struct SecondaryPart
{
    virtual ~SecondaryPart()
    {}
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
};
struct CombinedBase : PrimaryPart, SecondaryPart
{

};
struct ResourceMember
{
    virtual ~ResourceMember()
    {
        FUN_0089e890(data);
    }
    void* data;
};
struct FUN_009103b0 : CombinedBase
{
    ResourceMember resource;
    virtual ~FUN_009103b0();
};
// @fnv 0x00ca4490
FUN_009103b0::~FUN_009103b0()
{}


}
}   // namespace f3m_009103b0

// @f3 0x00901e20 (community match, verified in this file)
namespace f3m_00901e20 {
struct Owner901e20;

struct Obj901e20 {
    virtual void vf00();
    virtual void vf04(int a, int b, Owner901e20* owner);
    virtual void vf08(); virtual void vf0c(); virtual void vf10(); virtual void vf14();
    virtual void vf18();
};

void* __cdecl FUN_0097ee70(Owner901e20* owner, Obj901e20* object, int flags);

struct Owner901e20 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(Obj901e20* object, void* data);
    void FUN_00901e20(Obj901e20* object);
};

void Owner901e20::FUN_00901e20(Obj901e20* object) {
    void* data = FUN_0097ee70(this, object, 0);
    if (data) {
        vf08(object, data);
        object->vf18();
    } else {
        object->vf04(0, 4, this);
        vf08(object, 0);
        object->vf18();
    }
}
}   // namespace f3m_00901e20

// @f3 0x00902400 (community match, verified in this file)
namespace f3m_00902400 {
struct RefObj00902400 {
    virtual ~RefObj00902400();
    unsigned short memSizeAndFlags;
    short referenceCount;
    void addReference() { if (memSizeAndFlags != 0) referenceCount++; }
    void removeReference() {
        if (memSizeAndFlags != 0) {
            referenceCount--;
            if (referenceCount == 0) delete this;
        }
    }
};

struct Owner00902400 {
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
    RefObj00902400* unk50;
    void FUN_00902400(RefObj00902400* object);
};

void Owner00902400::FUN_00902400(RefObj00902400* object) {
    if (object) object->addReference();
    if (unk50) unk50->removeReference();
    unk50 = object;
}
}   // namespace f3m_00902400

// @f3 0x0091b7c0 (community match, verified in this file)
namespace f3m_0091b7c0 {
struct RefObj0091b7c0 {
    virtual ~RefObj0091b7c0();
    unsigned short memSizeAndFlags;
    short referenceCount;
    void addReference() { if (memSizeAndFlags != 0) referenceCount++; }
    void removeReference() {
        if (memSizeAndFlags != 0) {
            referenceCount--;
            if (referenceCount == 0) delete this;
        }
    }
};

struct Owner0091b7c0 {
    int unk00;
    int unk04;
    int unk08;
    RefObj0091b7c0* unk0c;
    void FUN_0091b7c0(RefObj0091b7c0* object);
};

// pdb: ahkpMalleableConstraintData::SetChild | bhkMalleableConstraint.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apData
void Owner0091b7c0::FUN_0091b7c0(RefObj0091b7c0* object) {
    if (object) object->addReference();
    if (unk0c) unk0c->removeReference();
    unk0c = object;
}
}   // namespace f3m_0091b7c0

// @f3 0x0090a650 (community match, verified in this file)
extern unsigned int DAT_00e35154;
extern unsigned int DAT_00dcc494;
extern unsigned long DAT_010f3170;
namespace f3m_0090a650 {
// FUN_0090a650: a "release/destroy" member. It repoints the object's own
// vtable field at 0x00 to the derived vtable, releases the object at 0x14
// (deleting-destructor-style call with flag 1) and then frees the buffer of an
// hkArray-like member (data 0x08, count 0x0c, capacityAndFlags 0x10) through the
// thread-local heap manager, finally repointing the vtable field at the base
// class's vtable.

extern void* (__stdcall *DAT_00d9b080)(unsigned long);

struct RefObj90 {
    void FUN_00908ab0(int);
};

struct Heap90 {
    void FUN_008f6d90(void*, int, int);
};

struct Obj90a650 {
    unsigned int m_vft;     // 0x00
    int          unk04;     // 0x04
    void*        m_data;    // 0x08
    int          m_count;   // 0x0c
    int          m_capacity;// 0x10
    RefObj90*    m_ptr14;   // 0x14

    void FUN_0090a650();
};

// pdb: hkDebugDisplay::~hkDebugDisplay | hkDebugDisplay.obj | fnv360_0822_retail, call_seq, medium
void Obj90a650::FUN_0090a650() {
    m_vft = (unsigned int)&DAT_00e35154;
    if (m_ptr14) m_ptr14->FUN_00908ab0(1);
    if (!(m_capacity & 0x80000000u)) {
        int allocated = m_capacity & 0x3fffffff;
        Heap90* heap = (Heap90*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(m_data, allocated * 4, 0x17);
    }
    m_vft = (unsigned int)&DAT_00dcc494;
}
}   // namespace f3m_0090a650

// @f3 0x00901870 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00901870 {

struct Heap90 { void FUN_008f6d90(void*, int, int); };
struct Arr90 {
    int unk00;
    int unk04;
    int unk08;
    void* data;
    int count;
    int capacity;
};
struct Owner90 {
    int unk00;
    int unk04;
    int unk08;
    Arr90* unk0c;
    void FUN_00901870(bool);
};

void Owner90::FUN_00901870(bool b) {
    if (b) {
        Arr90* p = unk0c;
        if (p) {
            if (!(p->capacity & 0x80000000)) {
                int size = p->capacity & 0x3fffffff;
                Heap90* heap = (Heap90*)f3m_0090baf0::TlsGetValue(DAT_010f3170);
                heap->FUN_008f6d90(p->data, size * 8, 0x17);
            }
            unsigned char n = *((unsigned char*)p - 1);
            DAT_01090a78.FUN_0086ba60((char*)p - n);
        }
        unk0c = 0;
    }
}
}   // namespace f3m_00901870

// @f3 0x00901e70 (community match, verified in this file)
namespace f3m_00901e70 {
struct Obj901e70;
void __cdecl FUN_0097edb0(Obj901e70* self, int a2, int a1, int flag);

struct Obj901e70 {
    void hkReferencedObject_calcContentStatistics(int a1, int a2);
};

// pdb: hkReferencedObject::calcContentStatistics | hkReferencedObject.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(vtable), high
void Obj901e70::hkReferencedObject_calcContentStatistics(int a1, int a2) {
    if (a2 != 0) {
        FUN_0097edb0(this, a2, a1, 0);
    }
}
}   // namespace f3m_00901e70

// @f3 0x0091bbf0 (community match, verified in this file)
namespace f3m_0091bd20 {

struct This91bbf0 {
    void* unk00;
    Link91bd20* link;
    void FUN_008fc580(Arg91bd20* arg0);
    void FUN_0091bbf0(Arg91bd20* arg0);
};

// pdb: hkMalleableConstraintCinfo::LoadBinary | bhkMalleableConstraint.obj | fnv360_0822_retail, objrun, medium
// pdb params: arStream
void This91bbf0::FUN_0091bbf0(Arg91bd20* arg0)
{
    FUN_008fc580(arg0);

    Link91bd20* link = this->link;
    RefObj91bd20* obj = (RefObj91bd20*)FUN_0097a9e0(arg0);
    if (obj != 0 && obj->refFlag != 0)
        ++obj->refCount;
    RefObj91bd20* old = (RefObj91bd20*)link->unk0c;
    if (old != 0 && old->refFlag != 0) {
        if (--old->refCount == 0)
            old->v0(1);
    }
    link->unk0c = obj;
    link->sub10.hkpBridgeConstraintAtom_init(link);
    if (obj->refFlag != 0) {
        if (--obj->refCount == 0)
            obj->v0(1);
    }

    Counted91bd20* counted = arg0->counted;
    counted->count += ReadChunk91(counted, &link->data1c, 4);
    if (arg0->version < 0x14020005u) {
        int unk;
        Counted91bd20* counted2 = arg0->counted;
        counted2->count += ReadChunk91(counted2, &unk, 4);
    }
}

}

// @f3 0x0090a080 (community match, verified in this file)
namespace f3m_0090a080 {
struct CriticalSection90a080 { int unk00, unk04, unk08, unk0c, unk10, unk14; };
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection90a080* section);

struct Lock90a080 {
    CriticalSection90a080 section;
    int unk18;
    int unk1c;
    void FUN_00908a00();
    void Unlock() {
        unk18 = -1;
        unk1c = -1;
        LeaveCriticalSection(&section);
    }
};

struct Item90a080 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c(int a, int b, int c, int d);
};

struct Owner90a080 {
    int unk00;
    int unk04;
    Item90a080** unk08;
    int unk0c;
    int unk10;
    Lock90a080* unk14;
    void FUN_0090a080(int a, int b, int c, int d);
};

void Owner90a080::FUN_0090a080(int a, int b, int c, int d) {
    unk14->FUN_00908a00();
    for (int i = 0; i < unk0c; i++) {
        unk08[i]->vf2c(a, b, c, d);
    }
    unk14->Unlock();
}
}   // namespace f3m_0090a080

// @f3 0x00915f00 (community match, verified in this file)
extern const int FUN_00e36438;
extern const int FUN_00e36414;
extern const int DAT_00e35eec;
extern const int FUN_00dcc494;
namespace f3m_00915f00 {
struct RefObj915f00 {
    virtual ~RefObj915f00();
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference() {
        if (memSizeAndFlags != 0) {
            referenceCount--;
            if (referenceCount == 0) delete this;
        }
    }
};


struct Member915f00 {
    const void* table;
    RefObj915f00* object;
};

struct Owner915f00 {
    const void* table;
    int unk04, unk08, unk0c;
    RefObj915f00* unk10;
    Member915f00 unk14;
    void FUN_00915f00();
};

// pdb: hkpBvShape::~hkpBvShape | hkpBvShape.obj | fnv360_0822_retail, call_seq, high
void Owner915f00::FUN_00915f00() {
    table = &FUN_00e36438;
    unk10->removeReference();
    unk14.table = &FUN_00e36414;
    unk14.object->removeReference();
    unk14.table = &DAT_00e35eec;
    table = &FUN_00dcc494;
}
}   // namespace f3m_00915f00

// @f3 0x00914260 (community match, verified in this file)
namespace f3m_00914260 {
struct Vec914260 {
    float x, y, z, w;
    void mul(float s) { x *= s; y *= s; z *= s; w *= s; }
};

struct Target914260 {
    int unk00, unk04, unk08, unk0c;
    Vec914260 unk10;
};

struct Param914260 {
    int unk00, unk04, unk08, unk0c;
    float unk10;
};

struct Owner914260 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual Target914260* vfb4(bool* flag);
    void FUN_008f7580(int a, Param914260* b);
    void FUN_00914260(int a, Param914260* b);
};

// pdb: bhkBoxShape::CopyMembers | bhkBoxShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apDest, arCloneData
void Owner914260::FUN_00914260(int a, Param914260* b) {
    bool flag;
    Target914260* t = vfb4(&flag);
    if (t) {
        float s = b->unk10;
        t->unk10.mul(s);
    }
    FUN_008f7580(a, b);
}
}   // namespace f3m_00914260

// @f3 0x0090c530 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0090c530 {

struct Target90c530 {
    int unk00;
    unsigned long unk04;
};

struct Param90c530 {
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
    unsigned char unk1e4;
};

struct Owner90c530 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual Target90c530* vfb4(bool* flag);
    void FUN_008f74e0(Param90c530* p);
    void SwapIfNeeded(Param90c530* p) {
        if (p->unk1e4 != 1) {
            bool flag;
            Target90c530* t = vfb4(&flag);
            if (t) t->unk04 = _byteswap_ulong(t->unk04);
        }
    }
    void bhkConvexShape_SaveBinary(Param90c530* p);
};

// pdb: bhkConvexShape::SaveBinary | bhkConvexShape.obj | fnv360_0822_retail, call_seq + bridge(vtable_prefix|vtable) + skyrim(objrun_prop), high
void Owner90c530::bhkConvexShape_SaveBinary(Param90c530* p) {
    SwapIfNeeded(p);
    FUN_008f74e0(p);
    SwapIfNeeded(p);
}
}   // namespace f3m_0090c530

// @f3 0x0090d800 (community match, verified in this file)
namespace f3m_0090d800 {
struct Inner90d800 {
    virtual void vf00();
    virtual void vf04();
};

struct Source90d800 {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10();
    virtual Inner90d800* vf14();
    int unk04, unk08;
    int unk0c;
    Inner90d800 unk10;
};

struct Owner90d800 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Source90d800* unk10;
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
    unsigned char unkd8;
    void FUN_0090d800();
};

void Owner90d800::FUN_0090d800() {
    Source90d800* source = unk10;
    if (source) {
        unsigned char type = unkd8;
        int kind = source->unk0c;
        if (type != 7 && type != 6 && (kind == 0xb || kind == 9)) {
            source->vf14()->vf04();
        }
        if (kind == 8) {
            unk10->unk10.vf04();
        } else if (kind == 0xa) {
            source->unk10.vf04();
        }
    }
}
}   // namespace f3m_0090d800

// @f3 0x0090c0a0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern int DAT_00e35ae4;
namespace f3m_0090c0a0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern void FUN_00dcc494();

struct Node90c0a0 {
    virtual void release(int);
    unsigned short flag;
    unsigned short refs;
};

struct Heap90c0a0 {
    void FUN_008f6d90(void*, int, int);
};

struct Wide8_90c0a0 {
    void* data;
    int count;
    int capacity;
};

struct Wide16_90c0a0 {
    void* data;
    int count;
    int capacity;
};

struct Gap18_90c0a0 {
    int f14, f18, f1c, f20, f24, f28, f2c, f30;
    int f34, f38, f3c, f40, f44, f48, f4c, f50, f54, f58;
};

struct FUN_0090c0a0 {
    void* vptr;
    int unk04;
    int unk08;
    int unk0c;
    Node90c0a0* node;
    Gap18_90c0a0 gap;
    Wide8_90c0a0 w8;
    int unk68;
    int unk6c;
    int unk70;
    Wide16_90c0a0 w16;
    ~FUN_0090c0a0();
};

// pdb: hkpWorldObject::~hkpWorldObject | hkpEntity.obj | fnv360_0822_retail, call_seq, high
FUN_0090c0a0::~FUN_0090c0a0()
{
    vptr = (void*)&DAT_00e35ae4;
    Node90c0a0* p = node;
    if (p && *(short*)((char*)p + 4)) {
        short& refs = *(short*)((char*)p + 6);
        --refs;
        if (refs == 0)
            p->release(1);
    }
    if (!(w16.capacity & 0x80000000u)) {
        int n = w16.capacity & 0x3fffffff;
        Heap90c0a0* heap = (Heap90c0a0*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(w16.data, n * 16, 0x17);
    }
    if (!(w8.capacity & 0x80000000u)) {
        int n = w8.capacity & 0x3fffffff;
        Heap90c0a0* heap = (Heap90c0a0*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(w8.data, n * 8, 0x17);
    }
    vptr = (void*)&FUN_00dcc494;
}
}   // namespace f3m_0090c0a0

// @f3 0x00911480 (community match, verified in this file)
namespace f3m_00911480 {

struct RefObj_911480 {
    virtual void v0();
    virtual void Delete();
    int m_refCount;
};

struct Ptr_911480 {
    RefObj_911480* m_ptr;

    Ptr_911480() : m_ptr(0) {}
    ~Ptr_911480() {
        Reset();
    }
    void Reset() {
        RefObj_911480* old = m_ptr;
        if (old) {
            if (InterlockedDecrement((volatile long*)&old->m_refCount) == 0) {
                old->Delete();
            }
            m_ptr = 0;
        }
    }
};

struct Class_00911480 {
    int m_0;
    Ptr_911480 m_ptr;
    float m_8;
    char pad[4];
    float m_r;
    float m_g;
    float m_b;
    float m_a;

    Class_00911480();
};

Class_00911480::Class_00911480() : m_0(0), m_ptr(), m_8(0.0f)
{
    m_ptr.Reset();
    m_r = 1.0f;
    m_g = 1.0f;
    m_b = 1.0f;
    m_a = 1.0f;
}
}   // namespace f3m_00911480

// @f3 0x0090a800 (community match, verified in this file)
namespace task0788 {
struct Obj_b5d270
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual void v39(void* apOwner);
    long m_lRefCount;
    unsigned int unkValue;
    unsigned int m_uiKey;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};

struct ObjPtr_b5d270
{
    Obj_b5d270* m_pObject;
    ObjPtr_b5d270(Obj_b5d270* pObject)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ObjPtr_b5d270()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ObjPtr_b5d270& operator=(const ObjPtr_b5d270& kPtr)
    {
        if (m_pObject != kPtr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = kPtr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    Obj_b5d270* operator->() const
    {
        return m_pObject;
    }
};

struct Allocator { void* FUN_0086b930(unsigned int); };
extern Allocator DAT_01090a78;
struct List {
    ObjPtr_b5d270 head;
    List* next;
    static void* operator new(unsigned int n) {return DAT_01090a78.FUN_0086b930(n);}
    List(Obj_b5d270* obj) : head(obj), next(0) {}
    __declspec(noinline) ObjPtr_b5d270& FUN_008e9600(const ObjPtr_b5d270& item) {return head=item;}
    __declspec(noinline) void FUN_008f2610(const ObjPtr_b5d270& item) {
        if (item.m_pObject) {
            if (head.m_pObject) {
                List* node=new List(head.m_pObject);
                node->next=next;
                next=node;
            }
            FUN_008e9600(item);
        }
    }
};
struct Shell {
    int unk00, unk04, unk08;
    List list;
    void FUN_0090a800(Obj_b5d270* obj);
};
// pdb: bhkEntityListener::AddEntity | bhkEntityListener.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apEntity
void Shell::FUN_0090a800(Obj_b5d270* obj) {
    if (obj) list.FUN_008f2610(obj);
}
}

// @f3 0x00915f80 (community match, verified in this file)
namespace f3m_00915f80 {
namespace bounding_volume_ctor {
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
struct hkpBvShape : hkpShape {
    hkpShape* boundingVolume;
    hkpSingleShapeContainer child;
    hkpBvShape(hkpShape*,hkpShape*);
};
// pdb: hkpBvShape::hkpBvShape | hkpBvShape.obj | fnv360_0822_retail, call_seq, high
// pdb params: boundingVolumeShape, childShape
hkpBvShape::hkpBvShape(hkpShape* bound,hkpShape* shape) : hkpShape(26),boundingVolume(bound),child(shape) { boundingVolume->addReference(); }
}
}   // namespace f3m_00915f80

// @f3 0x0091a5e0 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
namespace f3m_0091a5e0 {


struct ThreadMemory91a5e0 {
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
    void* unk50;
    int unk54;
    void FUN_008f6890(int row, void* p, int memClass);
};

struct FUN_0091a5e0 {
    virtual ~FUN_0091a5e0();
    static void operator delete(void* p) {
        ThreadMemory91a5e0* m = (ThreadMemory91a5e0*)TlsGetValue(DAT_010f3170);
        if (m->unk54 >= m->maxNumElemsOnFreeList) m->FUN_008f6890(3, p, 0x1f);
        else { _ReadWriteBarrier(); void* next = m->unk50; m->unk54++; *(void**)p = next; m->unk50 = p; }
    }
};

FUN_0091a5e0::~FUN_0091a5e0() {
}
}   // namespace f3m_0091a5e0

// @f3 0x0091f020 (community match, verified in this file)
namespace f3m_0091f020 {
// hkpCharacterProxy constructor (Havok character proxy, 0x0091f020)

struct hkBaseObject
{
    virtual void unk00();
};

struct hkReferencedObject : hkBaseObject
{
    short unk04;
    short m_referenceCount;
    hkReferencedObject() : m_referenceCount(1) {}
};

struct hkpEntityListener
{
    virtual void unk00();
};

struct hkpPhantomListener
{
    virtual void unk00();
};

struct ProxyArray
{
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    ProxyArray() : m_data(0), m_size(0), m_capacityAndFlags((int)0x80000000) {}
};

struct hkpCharacterProxy : hkReferencedObject, hkpEntityListener, hkpPhantomListener
{
    float unk10, unk14, unk18, unk1c;
    float unk20, unk24, unk28, unk2c;
    void* unk30;
    float unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    float unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70;
    ProxyArray m_manifold;
    ProxyArray m_listeners;
    ProxyArray m_overlaps;
    ProxyArray m_manifold2;
    float unkA4;
    float unkA8;
    int unkAC;
    char unkB0;

    hkpCharacterProxy(void* info);
    void FUN_0091df10(void* info);
};

// pdb: hkpCharacterProxy::hkpCharacterProxy | hkpCharacterProxy.obj | fnv360_0721_beta, call_seq, medium
// pdb params: info
hkpCharacterProxy::hkpCharacterProxy(void* info) : unk30(0)
{
    FUN_0091df10(info);
}
}   // namespace f3m_0091f020

// @f3 0x0090ea20 (community match, verified in this file)
namespace f3m_0090ea20 {
namespace scalea20 {struct Object;struct Value {int unk00;float scale;};struct Params {int unk00;int unk04;int unk08;int unk0c;float scale;};struct Table {
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
void* unk40;
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
void* unk80;
void* unk84;
void* unk88;
void* unk8c;
void* unk90;
void* unk94;
void* unk98;
void* unk9c;
void* unka0;
void* unka4;
void* unka8;
void* unkac;
void* unkb0;
// pdb: bhkSphereShape::CopyMembers | bhkSphereShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apDest, arCloneData
Value* (__thiscall *get)(Object*,unsigned char*);};struct Object {Table* table;void FUN_008f7580(void*,Params*);void FUN_0090ea20(void*,Params*);};void Object::FUN_0090ea20(void* first,Params* second){unsigned char local;Value* v=table->get(this,&local);if(v)v->scale*=second->scale;FUN_008f7580(first,second);}}
}   // namespace f3m_0090ea20

// @f3 0x00911640 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00911640 {
namespace workerA9116 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Heap { void* FUN_008f6d30(unsigned int,int); };
extern "C" void FUN_00951b90(void*);
struct FUN_0090f7a0 {
 void** vtable; unsigned short allocated; short refs;
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
 FUN_0090f7a0(void*);
 static void* operator new(unsigned int n) {
  Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);
  FUN_0090f7a0* p=(FUN_0090f7a0*)heap->FUN_008f6d30(n,0x27);
  p->allocated=(unsigned short)n;
  return p;
 }
 static void operator delete(void*p) { FUN_00951b90(p); }
};
struct Owner { void** vtable; void FUN_00911640(void*); };
void Owner::FUN_00911640(void* source) {
 if(source) {
  FUN_0090f7a0* p=new FUN_0090f7a0(source);
  typedef void (__thiscall* Add)(Owner*,FUN_0090f7a0*);
  ((Add)vtable[0x8c/4])(this,p);
  if(p->allocated) {
   --p->refs;
   if(!p->refs) {
    typedef void (__thiscall* Destroy)(FUN_0090f7a0*,int);
    ((Destroy)p->vtable[0])(p,1);
   }
  }
  typedef void (__thiscall* Notify)(Owner*,void*);
  ((Notify)vtable[0xbc/4])(this,source);
 }
}
}
}   // namespace f3m_00911640

// @f3 0x00919eb0 (community match, verified in this file)
namespace workerB919eb0 {
extern void* DAT_00e36654[];extern void* DAT_00dcc494[];
struct Ref {virtual ~Ref();unsigned short size;short refs;};
struct Context {void** vtable;unsigned short size;short refs;int unk08;Ref* state;void FUN_00919eb0();};
// pdb: hkpCharacterContext::~hkpCharacterContext | hkpCharacterContext.obj | fnv360_0822_retail, call_gap, low
void Context::FUN_00919eb0(){Ref* old=state;vtable=DAT_00e36654;if(old->size&&--old->refs==0)delete old;vtable=DAT_00dcc494;}
}

// @f3 0x0090d960 (community match, verified in this file)
namespace f3m_0090d960 {
namespace copy90 {
extern unsigned long DAT_010f3170;extern void* (__stdcall *DAT_00d9b080)(unsigned long);
struct Memory {void FUN_008f6d90(void*,int,int);void* FUN_008f6d30(int,int);};
struct Vector {int x,y,z,w;};
struct Owner {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; Vector* data;int size;int capacity;void FUN_0090d960(const Owner*);};
// pdb: hkStringPtr::operator= | hkStringPtr.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: hkpWorldObject::copyProperties)
// pdb params: string
void Owner::FUN_0090d960(const Owner* source){int cap=capacity&0x3fffffff;if(cap<source->size){void* (__stdcall *tls)(unsigned long)=DAT_00d9b080;if(!(capacity&0x80000000)){Memory* memory=(Memory*)tls(DAT_010f3170);memory->FUN_008f6d90(data,cap*16,0x17);}Memory* memory=(Memory*)tls(DAT_010f3170);data=(Vector*)memory->FUN_008f6d30(source->size*16,0x17);capacity=(capacity&0x40000000)|source->size;}
 int remaining=source->size;size=remaining;Vector* out=data;const Vector* in=source->data;for(int i=0;i<remaining;++i)out[i]=in[i];
}
}
}   // namespace f3m_0090d960

// @f3 0x0090ab20 (community match, verified in this file)
namespace f3m_0090ab20 {
namespace workerB90ab20 {extern const double DAT_00db36a8,DAT_00db7de8;struct Owner{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;float a,b,c,d,e,f,g,h;void FUN_0090ab20(float);};
// pdb: hkpWorldCinfo::setBroadPhaseWorldSize | hkpWorldCinfo.obj | fnv360_0822_retail, call_gap, low
// pdb params: sideLength
void Owner::FUN_0090ab20(float v){float x=(float)(v*DAT_00db36a8);a=x;b=x;c=x;d=x;float y=(float)(v*DAT_00db7de8);e=y;f=y;g=y;h=y;}
}

}   // namespace f3m_0090ab20

// @f3 0x00915b70 (community match, verified in this file)
namespace f3m_00915b70 {
struct C915Entry {int a,b,c;};
struct C915Array {
    void* table;C915Entry* data;unsigned capacity;unsigned current;unsigned size;unsigned growth;
    void FUN_009147c0(unsigned);void FUN_00914b20(unsigned,const C915Entry*);
    __forceinline void Append(const C915Entry* entry) {unsigned index=current;if(index>=capacity)FUN_009147c0(index+growth);FUN_00914b20(index,entry);}
};
struct C915Owner {
    int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;
    unsigned marker;C915Array entries;
    void FUN_00837bc0(C915Owner*,void*);void FUN_00915000();void FUN_00915b70(C915Owner*,void*);
};
// pdb: bhkBlendController::CopyMembers | bhkBlendController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: pDest, arCloneData
void C915Owner::FUN_00915b70(C915Owner* dest,void* map) {
    FUN_00837bc0(dest,map);
    dest->marker=marker;
    C915Array* array=&dest->entries;
    array->FUN_009147c0(entries.size);
    for(unsigned i=0;i<entries.size;++i) {
        array->Append(&entries.data[i]);
        dest->marker=0;
        dest->FUN_00915000();
    }
}
}   // namespace f3m_00915b70

// @f3 0x00902f70 (community match, verified in this file)
namespace f3m_00902f70 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace monitorf70 {struct Owner;struct Event {const char* name;unsigned ticks;int unk08;};struct Stream {int unk00;Event* current;int unk08;Event* end;};extern unsigned long DAT_0116913c;extern char DAT_00e34ba0[];extern char DAT_00e32798[];__forceinline void Record(const char* name){Stream* stream=(Stream*)TlsGetValue(DAT_0116913c);Event* e=stream->current;if(e<stream->end){e->name=name;unsigned ticks;
__asm {
rdtsc
mov dword ptr[ticks],eax
}
e->ticks=ticks;stream->current=e+1;}}struct Callback;struct CallbackTable {void* unk00;void* unk04;void* unk08;void (__thiscall *run)(Callback*,Owner*);};struct Callback {CallbackTable* table;int unk04;int id;};struct Manager;struct ManagerTable {
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
void* unk40;
void* unk44;
void* unk48;
void* unk4c;
void* unk50;
void* unk54;
void* unk58;
void* unk5c;
unsigned char* (__thiscall *get)(Manager*,unsigned char*,int);};struct Manager {ManagerTable* table;};extern Manager* DAT_010f3400;struct Sub {void hkpMultiThreadedSimulation_finishMtStep();};struct Owner {int unk00;int unk04;Sub* sub;
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
Callback* callback;void FUN_00902f70();};void Owner::FUN_00902f70(){sub->hkpMultiThreadedSimulation_finishMtStep();Callback* cb=callback;if(cb){unsigned char out;if(!*DAT_010f3400->table->get(DAT_010f3400,&out,cb->id)){Record(DAT_00e34ba0);cb->table->run(cb,this);Record(DAT_00e32798);}}}}
}   // namespace f3m_00902f70

// @f3 0x00901f10 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00901f10 {
extern "C" void*(__stdcall* const DAT_00fdf044)(unsigned long);
namespace workerB901f10 {
struct Heap{void* FUN_008f6d30(int,int);void FUN_008f6d90(void*,int,int);};
void* __cdecl FUN_00bffa60(void*,const void*,unsigned);
struct Array{void* data;int count;int capacity;};
inline void FreeStorage(Array* a,unsigned capacity,int elementSize){Heap* h=(Heap*)DAT_00fdf044(DAT_010f3170);h->FUN_008f6d90(a->data,capacity*elementSize,23);}
// pdb: hkArrayUtil::_reserveMore | hkArrayUtil.obj | fnv360_0822_retail, objrun, medium
// pdb params: mem, array, sizeElem
void __cdecl FUN_00901f10(Array* a,int elementSize){int capacity=a->count?2*a->count:1;Heap* h=(Heap*)DAT_00fdf044(DAT_010f3170);void* data=h->FUN_008f6d30(capacity*elementSize,23);FUN_00bffa60(data,a->data,a->count*elementSize);if((a->capacity&0x80000000)==0){unsigned allocated=a->capacity&0x3fffffff;Heap* oldHeap=(Heap*)DAT_00fdf044(DAT_010f3170);oldHeap->FUN_008f6d90(a->data,allocated*elementSize,23);}a->data=data;a->capacity=(a->capacity&0x40000000)|capacity;}
}


}   // namespace f3m_00901f10

// @f3 0x0091b4c0 (community match, verified in this file)
namespace f3m_0091b4c0 {
namespace dtor4c0 {extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);extern unsigned long DAT_010f3170;struct Alloc {void FUN_008f6d90(void*,int,int);};struct Ref;struct RefTable {void* unk00;void (__thiscall *destroy)(Ref*);};struct Ref {RefTable* table;long count;};struct Ptr {Ref* p;~Ptr(){Ref* old=p;if(old&&!InterlockedDecrement(&old->count))old->table->destroy(old);}};struct Array {void* data;int size;unsigned capacity;~Array(){if(!(capacity&0x80000000u)){unsigned n=capacity&0x3fffffffu;Alloc* allocator=(Alloc*)TlsGetValue(DAT_010f3170);allocator->FUN_008f6d90(data,n*4,0x17);}}};struct Base {
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
void FUN_00979010();~Base(){FUN_00979010();}};struct FUN_0091b4c0 {Base base;Array array;int unkdc;Ptr ref;~FUN_0091b4c0();};FUN_0091b4c0::~FUN_0091b4c0(){}}
}   // namespace f3m_0091b4c0

// @f3 0x00916120 (community match, verified in this file)
namespace workerA9161 {
extern int DAT_00e36414,DAT_00e35eec;
struct Ref {void**vtable;unsigned short active;short refs;};
struct Owner {void*vtable;Ref*object;Owner* FUN_00916120(unsigned int);};
// pdb: hkpSingleShapeContainer::`scalar deleting destructor' | hkpBvShape.obj | tesv_win, objrun_sim, low
Owner* Owner::FUN_00916120(unsigned int) {
 Ref*ref=object;
 vtable=&DAT_00e36414;
 if(ref->active) {
  --ref->refs;
  if(!ref->refs) {
   typedef void (__thiscall* Destroy)(Ref*,int);
   ((Destroy)ref->vtable[0])(ref,1);
  }
 }
 vtable=&DAT_00e35eec;
 return this;
}
}

// @f3 0x009111f0 (community match, verified in this file)
namespace f3m_009111f0 {
struct C911Output {int unk00;int unk04;float value;int unk0c;float x,y,z,w;};
struct C911Data {void FUN_0090f8d0(C911Output*);};
struct C911CopyOwner {int unk00;int unk04;C911Data* data;void FUN_0096ab80(C911Output*);void FUN_009111f0(C911Output*);};
// pdb: bhkBvTreeShape::SethkpShapeCollection | bhkBvTreeShape.obj | fnv360_0822_debug, objrun_open, medium, conflict (bridge: bhkNiTriStripsShape::CopyCinfo)
// pdb params: apCollection
void C911CopyOwner::FUN_009111f0(C911Output* dest) {
    FUN_0096ab80(dest);
    if(this && data) data->FUN_0090f8d0(dest);
    else {dest->x=1.0f;dest->y=1.0f;dest->z=1.0f;dest->w=1.0f;dest->value=0.0f;}
}
}   // namespace f3m_009111f0

// @f3 0x00917f50 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00917f50 {
namespace workerA917f {
extern void*(__stdcall*DAT_00d9b080)(unsigned long);
struct Heap {void FUN_008f6d90(void*,unsigned int,int);};
struct Owner {void*data;int count;unsigned int capacity;void FUN_00917f50();};
void Owner::FUN_00917f50() {
 if(!(capacity&0x80000000u)) {
  unsigned int c=capacity&0x3fffffff;
  Heap*heap=(Heap*)DAT_00d9b080(DAT_010f3170);
  heap->FUN_008f6d90(data,c*48,0x17);
 }
}
}
}   // namespace f3m_00917f50

// @f3 0x0091aa60 (community match, verified in this file)
namespace f3m_0091aa60 {
struct Arrayaa60 {void** data;int size;void Remove(int index){--size;data[index]=data[size];}};
struct Flagaa60 {unsigned char value;Flagaa60(bool v):value(v){}Flagaa60(const Flagaa60& v):value(v.value){}};
struct Owneraa60;extern bool (__cdecl* DAT_010f3328)(Owneraa60*,void*,int);
struct Owneraa60 {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; Arrayaa60 first;int unkC8;int unkCC;Arrayaa60 second;
int Find(void* item){int limit=first.size;for(int i=0;i<limit;++i)if(first.data[i]==item)return i;return -1;}
void FUN_0091a580(void*,Flagaa60);void FUN_0091aa60(void*);};
// pdb: hkAvoidBox::removeOverlappingCollidable | bhkAvoidBox.obj | tesv_win, objopen_prop, low
void Owneraa60::FUN_0091aa60(void* item){int index=Find(item);bool found=index>=0;FUN_0091a580(item,Flagaa60(found));if(found){if(DAT_010f3328 && !DAT_010f3328(this,item,1))return;first.Remove(index);if(second.size>index){second.Remove(index);}}}
}   // namespace f3m_0091aa60

// @f3 0x00902450 (community match, verified in this file)
namespace f3m_00902450 {
struct C902Vector {float x,y,z,w;};
struct C902Payload {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;C902Vector first,second;};
struct C902Target {
    void** table;
    void Set(void* a,void* b,void* c) {((void (__thiscall*)(C902Target*,void*,void*,void*))table[19])(this,a,b,c);}
    void Get(C902Vector* a,C902Vector* b) {((void (__thiscall*)(C902Target*,C902Vector*,C902Vector*))table[20])(this,a,b);}
};
struct C902Owner {
    int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;
    C902Target* target;int unk58;int unk5c;int unk60;int unk64;int unk68;C902Payload* payload;
    void FUN_00902450(void*,void*,void*);
};
void C902Owner::FUN_00902450(void* a,void* b,void* c) {
    target->Set(a,b,c);
    target->Get(&payload->first,&payload->second);
}
}   // namespace f3m_00902450

// @f3 0x00902060 (community match, verified in this file)
extern char DAT_00e34a74[],DAT_00e34a6c[];
namespace f3m_00902060 {
namespace workerA9020 {
struct Writer {void**vtable;};
struct Owner {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 void*data;int count;unsigned capacity;
 void FUN_00902060(Writer*);
};
void Owner::FUN_00902060(Writer*writer) {
 typedef void (__thiscall* Begin)(Writer*,const char*,int,Owner*);
 typedef void (__thiscall* Blob)(Writer*,const char*,int,void*,int,unsigned int);
 typedef void (__thiscall* End)(Writer*);
 Begin begin=(Begin)writer->vtable[1];
 begin(writer,DAT_00e34a74,1,this);
 if(!(capacity&0x80000000u))
  ((Blob)writer->vtable[2])(writer,DAT_00e34a6c,1,data,count,capacity&0x3fffffff);
 ((End)writer->vtable[6])(writer);
}
}
}   // namespace f3m_00902060

// @f3 0x0091b420 (community match, verified in this file)
namespace f3m_0091b420 {
namespace workerB91b420 {extern void* DAT_00e3668c;struct Source{int value;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int bounds;};
struct Base{void* vtable;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;int unka0;int unka4;int unka8;int unkac;int unkb0;int unkb4;int unkb8;int unkbc;int unkc0;int unkc4;int unkc8;int unkcc;void FUN_00978f10(void*,int);Base(Source* s){FUN_00978f10(&s->bounds,s->value);}~Base();};
struct Array{void* data;int count;unsigned capacity;Array(void* d,int n,unsigned c):data(d),count(n),capacity(c){}~Array();};
struct Pointer{void* value;Pointer():value(0){}~Pointer();}; struct Reference{int count;Pointer pointer;Reference(){}};
struct Owner:Base{Array array;Reference reference;int unk0e4;int unk0e8;int unk0ec;int unk0f0;int unk0f4;int unk0f8;int unk0fc;int unk100;int unk104;int unk108;int unk10c;int unk110;int unk114;int unk118;int unk11c;int unk120;int unk124;int unk128;bool first,second;void FUN_0091b1d0();Owner(Source*);};
Owner::Owner(Source* s):Base(s),array((vtable=&DAT_00e3668c,(void*)0),0,0x80000000),reference(){reference.count=0;first=false;second=true;FUN_0091b1d0();}
}


}   // namespace f3m_0091b420

// @f3 0x00903760 (community match, verified in this file)
namespace f3m_00903760 {
struct C903Entry {
    int unk00;int unk04;int unk08;int base;int unk10;int units;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int blocks;
};
struct C903Owner {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;C903Entry** entries;int count;int FUN_00903760();};
int C903Owner::FUN_00903760() {
    int maximum=0;
    for(int i=count-1;i>=0;--i) {
        C903Entry* entry=entries[i];
        int value=entry->base+(entry->units+entry->blocks*32)*4+0xa8;
        if(maximum<=value) maximum=value;
    }
    return maximum;
}
}   // namespace f3m_00903760

// @f3 0x00908780 (community match, verified in this file)
namespace f3m_00908780 {
namespace Context908 {extern unsigned long DAT_010f3170;extern void* (__stdcall* DAT_00d9b080)(unsigned long);struct Memory{void* FUN_008f6d30(unsigned,unsigned);};struct Object;struct ObjectMethods{void (__thiscall* destroy)(Object*,unsigned);};extern ObjectMethods DAT_00e34b64;extern int DAT_00e34b58,DAT_00e34b44,DAT_00e34b38,DAT_00e34b2c;struct ReferencedFilterBase{ObjectMethods* table;unsigned short size;short refs;};
struct hkpCollidableCollidableFilter{void* table;};struct hkpShapeCollectionFilter{void* table;};struct hkpRayShapeCollectionFilter{void* table;};struct hkpRayCollidableFilter{void* table;};
struct Object:ReferencedFilterBase,hkpCollidableCollidableFilter,hkpShapeCollectionFilter,hkpRayShapeCollectionFilter,hkpRayCollidableFilter{int unk18,unk1C,mode,unk24,unk28,unk2C;void FUN_00943410();void* Context(){return static_cast<hkpShapeCollectionFilter*>(this);}void Add(){if(size)++refs;}void Release(){if(size){--refs;if(refs==0)ReferencedFilterBase::table->destroy(this,1);}}};
struct State{int unk00,unk04;void* context;};struct Owner {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; State* state;Object* object;void FUN_00907f30(int,int);void FUN_00908780(Object*,bool,int,int);};
__forceinline Object* CreateDefaultFilter(){Object* value;Memory* memory=(Memory*)DAT_00d9b080(DAT_010f3170);value=(Object*)memory->FUN_008f6d30(0x30,0x27);value->size=0x30;value->FUN_00943410();value->ReferencedFilterBase::table=&DAT_00e34b64;value->hkpCollidableCollidableFilter::table=&DAT_00e34b58;value->hkpShapeCollectionFilter::table=&DAT_00e34b44;value->hkpRayShapeCollectionFilter::table=&DAT_00e34b38;value->hkpRayCollidableFilter::table=&DAT_00e34b2c;value->mode=1;return value;}
void Owner::FUN_00908780(Object* value,bool notify,int a,int b){if(!value)value=CreateDefaultFilter();else value->Add();object->Release();object=value;state->context=value->Context();if(notify)FUN_00907f30(a,b);}
}
}   // namespace f3m_00908780

// @f3 0x009115a0 (community match, verified in this file)
namespace f3m_009115a0 {
namespace workerB9115a0 {
struct Heap{void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct Object{Object* FUN_00911480();};
inline unsigned char* Allocate(){unsigned char* raw=(unsigned char*)DAT_01090a78.FUN_0086b930(0x30);unsigned char low=(unsigned)raw&15;unsigned char offset=16-low;raw+=offset;raw[-1]=offset;return raw;}
struct Allocation{unsigned char* p;Allocation():p(Allocate()){}~Allocation(){if(p)DAT_01090a78.FUN_0086ba60(p-p[-1]);}};
struct Owner{int unk00,unk04;int attached;Object* object;void FUN_009111f0(Object*);Object* FUN_009115a0(bool*);};
// pdb: bhkNiTriStripsShape::CreateCinfo | bhkNiTriStripsShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCreated
Object* Owner::FUN_009115a0(bool* created){if(!object){Object* result;{Allocation allocation;result=((Object*)allocation.p)->FUN_00911480();allocation.p=0;}object=result;if(attached)FUN_009111f0(result);*created=true;}else *created=false;return object;}
}
}   // namespace f3m_009115a0

// @f3 0x0091cf00 (community match, verified in this file)
namespace w91cf00 {
struct Heap { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
extern void* DAT_00e3451c;
struct Data { int unk00,unk04,unk08,unk0c; };
struct Impl {
 void* table; Data data;
 static void* operator new(unsigned n) { return DAT_01090a78.FUN_0086b930(n); }
 static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
 Impl() { data.unk00=0; data.unk08=0; data.unk0c=0; data.unk04=1; table=&DAT_00e3451c; }
};
struct Owner {
 int unk00,unk04,unk08; Data* unk0c;
 void FUN_008fc420(Impl*);
 Data* FUN_0091cf00(bool*);
};
// pdb: bhkLimitedHingeConstraint::KillCinfo | bhkLimitedHingeConstraint.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: bhkLimitedHingeConstraint::CreateCinfo)
// pdb params: abCreated
Data* Owner::FUN_0091cf00(bool* created) {
 if (!unk0c) {
  Impl* p=new Impl;
  unk0c=p ? &p->data : 0;
  if (unk08) FUN_008fc420(unk0c ? reinterpret_cast<Impl*>(reinterpret_cast<char*>(unk0c)-4) : 0);
  *created=true;
 } else *created=false;
 return unk0c;
}
}

// @f3 0x0091a980 (community match, verified in this file)
namespace f3m_0091a980 {
namespace queue980 {struct Array;void __cdecl FUN_00901f10(Array*,int);struct Array {void** data;int size;unsigned capacity;int Find(void* value){for(int i=0;i<size;++i)if(data[i]==value)return i;return -1;}__forceinline void Push(void* value){if(size==(capacity&0x3fffffffu))FUN_00901f10(this,4);data[size++]=value;}};struct Item {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
unsigned flags;unsigned Type(){return flags&0x7f;}};struct Owner;extern bool (__cdecl *DAT_010f3328)(Owner*,Item*,int);struct Owner {
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
Array pending;int unkcc;Array results;
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
// pdb: hkAvoidBox::addOverlappingCollidable | bhkAvoidBox.obj | tesv_win, objopen_prop, low
bool active;int FUN_0091a520(Item*);void FUN_0091a980(Item*);};void Owner::FUN_0091a980(Item* item){bool found=pending.Find(item)>=0;if(active && item->Type()==30)return;if(FUN_0091a520(item) || found)return;if(DAT_010f3328 && !DAT_010f3328(this,item,0))return;pending.Push(item);results.Push(0);}}
}   // namespace f3m_0091a980

// @f3 0x0091d2f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0091d2f0 {
namespace workerA91d2 {
struct Input {
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
 unsigned char nativeEndian;
 bool NeedsSwap() const { return nativeEndian!=1; }
};
struct Data {int unk00,unk04,unk08,unk0c;unsigned long f10,f14,f18,f1c,f20,f24,f28,f2c;};
static __forceinline void SwapWord(void*address) { unsigned long*p=(unsigned long*)address;*p=_byteswap_ulong(*p); }
static __forceinline void Swap(Data*data) {
 if(data) {
  SwapWord(&data->f10);
  SwapWord(&data->f14);
  SwapWord(&data->f18);
  SwapWord(&data->f1c);
  SwapWord(&data->f20);
  SwapWord(&data->f24);
  SwapWord(&data->f28);
  SwapWord(&data->f2c);
 }
}
struct Owner {
 void**vtable;
 void bhkConvexShape_SaveBinary(Input*);
 void FUN_0091d2f0(Input*);
};
// pdb: bhkCapsuleShape::SaveBinary | bhkCapsuleShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Owner::FUN_0091d2f0(Input*input) {
 Input*original=input;
 unsigned int ignored;
 typedef Data*(__thiscall* Query)(Owner*,unsigned int*);
 if(original->NeedsSwap()) Swap(((Query)vtable[0xb4/4])(this,&ignored));
 bhkConvexShape_SaveBinary(original);
 if(original->NeedsSwap()) Swap(((Query)vtable[0xb4/4])(this,&ignored));
}
}
}   // namespace f3m_0091d2f0

// @f3 0x00919250 (community match, verified in this file)
namespace f3m_00919250 {
namespace workerB919250 {
struct Root{int unk00,unk04,unk08,unk0c;void* value;};Root* __cdecl FUN_007235f0(void*);void* __cdecl FUN_00424d50(const void*,void*);extern char DAT_010f3220[],DAT_0108f200[];
struct Converted{virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1c();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2c();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3c();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4c();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5c();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6c();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7c();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8c();virtual void slot90();virtual void slot94();virtual void* Get();bool Valid(){return Get()!=0;}};
struct Children{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;void** children;unsigned short maximum,count;unsigned Count(){return count;}void* Get(unsigned i){return children[i];}};
inline Converted* CastConverted(void* p){return (Converted*)FUN_00424d50(DAT_010f3220,p);}inline Children* CastChildren(void* p){return (Children*)FUN_00424d50(DAT_0108f200,p);}
struct Owner{void FUN_00918270(Converted*,unsigned,unsigned);void FUN_00919250(void*,unsigned,unsigned);};
// pdb: bhkRagdollPenetrationUtil::FindBones | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apObject, arRigidBodies, arConstraints
void Owner::FUN_00919250(void* object,unsigned second,unsigned third){if(object){Root* root=FUN_007235f0(object);if(root){Converted* c=CastConverted(root->value);if(c&&c->Valid())FUN_00918270(c,second,third);}Children* node=CastChildren(object);if(node){for(unsigned i=0;i<node->Count();++i)FUN_00919250(node->Get(i),second,third);}}}
}

}   // namespace f3m_00919250

// @f3 0x0091c080 (community match, verified in this file)
namespace workerA91c080 {
struct Heap { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
extern void* DAT_00e36824;
struct Data { int unk00,unk04,unk08,unk0c; };
struct Impl {
 void* table; Data data;
 static void* operator new(unsigned n) { return DAT_01090a78.FUN_0086b930(n); }
 static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
 Impl() { data.unk00=0; data.unk08=0; data.unk0c=0; data.unk04=1; table=&DAT_00e36824; }
};
struct Owner {
 int unk00,unk04,unk08; Data* unk0c;
 void FUN_008fc420(Impl*);
 Data* FUN_0091c080(bool*);
};
// pdb: bhkMalleableConstraint::KillCinfo | bhkMalleableConstraint.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: bhkMalleableConstraint::CreateCinfo)
// pdb params: abCreated
Data* Owner::FUN_0091c080(bool* created) {
 if (!unk0c) {
  Impl* p=new Impl;
  unk0c=p ? &p->data : 0;
  if (unk08) FUN_008fc420(unk0c ? reinterpret_cast<Impl*>(reinterpret_cast<char*>(unk0c)-4) : 0);
  *created=true;
 } else *created=false;
 return unk0c;
}
}

// @f3 0x00900fd0 (community match, verified in this file)
namespace f3m_00900fd0 {
namespace workerA900f {
struct Array {void*data;int size;unsigned capacity;Array():capacity(0x80000000u),data(0),size(0){}};
struct Header {
 int unk00,unk04;unsigned char enabled,unk09;unsigned short unk0a;
 Array array;
 unsigned char active,unk19;short index;int unk1c;
 Header() {unk00=0;unk04=0;index=-1;enabled=true;active=true;}
};
struct Vector {float x,y,z,w;Vector():x(0),y(0),z(0),w(0){}};
struct FUN_00900fd0 {
 Header header;
 Vector vectors[8];
 FUN_00900fd0();
};
FUN_00900fd0::FUN_00900fd0() {}
}
}   // namespace f3m_00900fd0

// @f3 0x009025c0 (community match, verified in this file)
namespace f3m_009025c0 {
namespace Batch5State{struct Data{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;unsigned __int64 state;};struct Owner{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;int unka0;int unka4;int unka8;Data*data;int FUN_009025c0();};int Owner::FUN_009025c0(){if(data->state!=~(unsigned __int64)0)return 1;return 0;}}
}   // namespace f3m_009025c0

// @f3 0x0090e3a0 (community match, verified in this file)
namespace f3m_0090e3a0 {
namespace Lazy90Batch {struct Heap{void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;struct Quad{float x,y,z,w;void Zero(){x=y=z=w=0.0f;}};struct Data{int unk00,unk04;unsigned char type,unk09;unsigned short unk0A;void* buffer;int count;unsigned capacity;int unk18,unk1C;Quad a,b;void Init(){buffer=0;count=0;capacity=0x80000000;unk00=0;unk04=0;type=2;a.Zero();b.Zero();}};
__forceinline Data* Allocate(){unsigned char* raw=(unsigned char*)DAT_01090a78.FUN_0086b930(sizeof(Data)+16);unsigned char offset=16;unsigned char low=(unsigned char)(unsigned)raw&15;offset-=low;raw+=offset;raw[-1]=offset;return (Data*)raw;}
struct Owner{int unk00,unk04;void* active;Data* data;void FUN_0090e280(Data*);Data* FUN_0090e3a0(unsigned char*);};
// pdb: bhkAabbPhantom::CreateCinfo | bhkAabbPhantom.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arCreated
Data* Owner::FUN_0090e3a0(unsigned char* made){if(!data){Data* value=Allocate();value->Init();data=value;if(active)FUN_0090e280(value);*made=1;return data;}*made=0;return data;}
}
}   // namespace f3m_0090e3a0

// @f3 0x0091a460 (community match, verified in this file)
#include <math.h>
extern const double DAT_00dc0760,DAT_00dfb608,DAT_00dd8f60;
namespace f3m_0091a460 {
inline float RoundedValue91(float value){return value;}
inline double NormalizeRemainder91(float value){return (float)fmod((double)value,DAT_00dc0760);}
struct Angle91a4{int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8;unsigned int direction;void FUN_0091a460(float);};
// pdb: hkAvoidBox::SetOctant | bhkAvoidBox.obj | fnv360_0822_debug, caller_sim, low
// pdb params: afAngle
void Angle91a4::FUN_0091a460(float angle){if(angle>DAT_00dc0760)angle=RoundedValue91((float)NormalizeRemainder91(angle));else if(angle<0.0)angle=NormalizeRemainder91(angle)+DAT_00dc0760;angle=(float)(angle+DAT_00dfb608);angle=(float)(angle/DAT_00dd8f60);direction=(unsigned int)angle;if(direction>7)direction=0;}
}   // namespace f3m_0091a460

// @f3 0x00902dd0 (community match, verified in this file)
#include "havok/hkMonitorStream.h"
namespace f3m_00902dd0 {
namespace Timer902d {
struct Owner;struct Child;struct ChildTable{void* unk00;void* unk04;void* unk08;int (__thiscall* update)(Child*,float);};struct Child{ChildTable* table;};struct Listener;struct ListenerTable{void* unk00;void* unk04;void* unk08;void (__thiscall* notify)(Listener*,Owner*);};struct Listener{ListenerTable* table;int unk04;int value;};struct hkBool{char m_bool;hkBool(){}operator bool()const{return m_bool!=0;}};struct Manager{virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3c(); virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4c(); virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5c(); virtual hkBool check(int);};extern Manager* DAT_010f3400;
struct Owner{int unk00;int unk04;Child* child;int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c;Listener* listener;int FUN_00902dd0(float);};
int Owner::FUN_00902dd0(float value){
int result=child->table->update(child,value);
if(!result){Listener* notify=listener;if(notify){
if(!DAT_010f3400->check(notify->value)){
HK_TIMER_BEGIN("WatchDog:FreeMem", HK_NULL);
notify->table->notify(notify,this);
HK_TIMER_END();
}}}return result;}
}
}   // namespace f3m_00902dd0

// @f3 0x00911400 (community match, verified in this file)
namespace f3m_00911400 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

struct NiRefObject911400 {
    virtual void vf00();
    virtual void DeleteThis();
    volatile long refCount;
};

struct NiPointer911400 {
    NiRefObject911400* object;
    NiPointer911400& operator=(NiRefObject911400* p) {
        NiRefObject911400* old = object;
        if (old != p) {
            if (old && InterlockedDecrement(&old->refCount) == 0) old->DeleteThis();
            object = p;
            if (p) InterlockedIncrement(&p->refCount);
        }
        return *this;
    }
};

struct Target911400 {
    int unk00;
    NiPointer911400 unk04;
};

struct Param911400 {
    NiRefObject911400* FUN_0082a280();
};

struct Owner911400 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual Target911400* vfb4(bool* flag);
    void FUN_008f7450(Param911400* p);
    void FUN_00911400(Param911400* p);
};

// pdb: bhkListShape::CopyMembers | bhkListShape.obj | fnv360_0822_debug, caller_sim, low
// pdb params: apDest, arCloneData
void Owner911400::FUN_00911400(Param911400* p) {
    bool flag;
    Target911400* t = vfb4(&flag);
    if (t) t->unk04 = p->FUN_0082a280();
    FUN_008f7450(p);
}
}   // namespace f3m_00911400

// @f3 0x009020d0 (community match, verified in this file)
namespace f3m_009020d0 {
namespace f3m_009020d0 { extern char DAT_00e34aac; }
struct O009020d0 { virtual void v0(); virtual void Slot1(void* a, int b, int c); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void Slot6(); };
// pdb: hkpContactMgrFactory::calcContentStatistics | hkpWorld.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
struct PacketObject { O009020d0* object; }; void __fastcall hkpContactMgrFactory_calcContentStatistics(int context, PacketObject input) { O009020d0* o = input.object; o->Slot1(&f3m_009020d0::DAT_00e34aac, 2, context); o->Slot6(); }

}   // namespace f3m_009020d0

// @f3 0x0090e950 (community match, verified in this file)
namespace f3m_0090e950 {
namespace f3m_0090e950 { extern char DAT_00e35edc; }
struct O0090e950 { virtual void v0(); virtual void Slot1(void* a, int b, int c); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void Slot6(); };
struct PacketObject { O0090e950* object; }; void __fastcall FUN_0090e950(int context, PacketObject input) { O0090e950* o = input.object; o->Slot1(&f3m_0090e950::DAT_00e35edc, 1, context); o->Slot6(); }

}   // namespace f3m_0090e950

// @f3 0x00916190 (community match, verified in this file)
namespace f3m_00916190 {
namespace f3m_00916190 { extern char DAT_00e364f0; }
struct O00916190 { virtual void v0(); virtual void Slot1(void* a, int b, int c); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void Slot6(); };
struct PacketObject { O00916190* object; }; void __fastcall FUN_00916190(int context, PacketObject input) { O00916190* o = input.object; o->Slot1(&f3m_00916190::DAT_00e364f0, 1, context); o->Slot6(); }

}   // namespace f3m_00916190

// @f3 0x0090b080 (community match, verified in this file)
namespace f3m_0090b080 {
struct LookupKey {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int identity;
};
struct LookupValue {
    unsigned int unk00, unk04;
    void* payload;
};
struct LookupEntry {
    LookupValue* value;
    const unsigned int* identity;
};
struct LookupTable {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    LookupEntry* entries;
    int count;
    void* FUN_0090b080(const LookupKey*);
};
// pdb: hkpEntity::findContactMgrTo | hkpEntity.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpEntity::removeEntityActivationListener)
// pdb params: entity
void* LookupTable::FUN_0090b080(const LookupKey* key)
{
    for (int i = 0; i < count; ++i) {
        if (entries[i].identity == &key->identity)
            return entries[i].value->payload;
    }
    return 0;
}
}   // namespace f3m_0090b080

// @f3 0x00914120 (community match, verified in this file)
struct Quaternion914120 { float x, y, z, w; };
struct Holder914120 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Quaternion914120 rotation;
};
struct Output914120 {
    unsigned int unk00, unk04, unk08, unk0c;
    Quaternion914120 rotation;
};
extern Quaternion914120 DAT_01092a50;
struct Owner914120 {
    unsigned int unk00, unk04;
    Holder914120* holder;
    void FUN_0090c4a0(Output914120*);
    void FUN_00914120(Output914120*);
};
void Owner914120::FUN_00914120(Output914120* out)
{
    FUN_0090c4a0(out);
    const Quaternion914120* src = this && holder ? &holder->rotation : &DAT_01092a50;
    out->rotation.x = src->x;
    out->rotation.y = src->y;
    out->rotation.z = src->z;
    out->rotation.w = src->w;
}

// @f3 0x00915470 (community match, verified in this file)
namespace f3m_00915470 {
struct Entries915470 {
    unsigned int unk00, unk04;
    unsigned int capacity;
    unsigned int count;
    unsigned int unk10;
    unsigned int growBy;
    void FUN_009147c0(unsigned int);
    void FUN_00914b20(unsigned int, void*);
    __forceinline void Append(void* value) {
        unsigned int index = count;
        if (index >= capacity)
            FUN_009147c0(growBy + index);
        FUN_00914b20(index, value);
    }
};
struct Owner915470 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30;
    unsigned int flag;
    Entries915470 entries;
    void FUN_00915000();
    void FUN_00915470(void*);
};
// pdb: bhkBlendController::AddKey | bhkBlendController.obj | fnv360_0822_retail, call_gap, medium
// pdb params: arKey
void Owner915470::FUN_00915470(void* value)
{
    entries.Append(value);
    flag = 0;
    FUN_00915000();
}
}   // namespace f3m_00915470

// @f3 0x00910e70 (community match, verified in this file)
namespace f3m_00910e70 {
struct Q910Owner;
struct Q910Result { int unk00; int unk04; };
struct Q910Arg { void FUN_0082b560(); };
struct Q910Owner { 
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual Q910Result* Lookup(Q910Arg**);
 void FUN_008f7490(void*); void FUN_00910e70(Q910Arg*); };
// pdb: bhkBvTreeShape::LoadBinary | bhkBvTreeShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Q910Owner::FUN_00910e70(Q910Arg* arg) { Q910Arg* saved=*reinterpret_cast<Q910Arg* volatile*>(&arg); saved->FUN_0082b560(); FUN_008f7490(saved); Q910Result* result=Lookup(&arg); if(result) result->unk04=0; }
}   // namespace f3m_00910e70

// @f3 0x00914a50 (community match, verified in this file)
extern char DAT_010f33dc;
namespace f3m_00914a50 {
struct Entry914a50 {
    void* FUN_00825200(const void*);
    void FUN_00825110(void*);
};
struct Owner914a50 {
    unsigned int unk00, unk04;
    unsigned char flags;
    unsigned char unk09, unk0a, unk0b;
    unsigned int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Entry914a50* entries;
    bool FUN_00914a50();
};
// pdb: bhkBlendController::ClearForceController | bhkBlendController.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: BShkbUtils::RemoveControllersFunctor::operator())
bool Owner914a50::FUN_00914a50()
{
    unsigned char high = *reinterpret_cast<volatile unsigned char*>(&flags) >> 7;
    bool result = false;
    if (high & 1) {
        Entry914a50* list = entries;
        void* entry = list->FUN_00825200(&DAT_010f33dc);
        if (entry) {
            list->FUN_00825110(entry);
            result = true;
        }
    }
    return result;
}
}   // namespace f3m_00914a50

// @f3 0x00914950 (community match, verified in this file)
extern float DAT_00db38b8;
extern const double DAT_00dba730;
namespace f3m_00914950 {

struct Key914950 {
    float time;
    float value;
    float extra;
};

struct KeyArray914950 {
    int unk00;
    Key914950* m_keys;
    int unk08;
    unsigned int m_count;
    unsigned int m_used;
    void FUN_00914950();
};

// pdb: NiTLargeArray<BLENDKEY,NiTMallocInterface<BLENDKEY> >::RemoveAll | bhkBlendController.obj | fnv360_0822_retail, call_seq, medium
void KeyArray914950::FUN_00914950()
{
    unsigned int i = 0;
    if (i < m_count) {
        Key914950 key;
        key.time = DAT_00db38b8;
        key.value = key.extra = (float)(0.0 / DAT_00dba730);
        do {
            m_keys[i] = key;
            i++;
        } while (i < m_count);
    }
    m_count = 0;
    m_used = 0;
}
}   // namespace f3m_00914950

// @f3 0x0091c870 (community match, verified in this file)
namespace f3m_0091c320 {
struct SourceOwner {
    int u0;
    Source91* source;
    int FUN_0091c870();
};

// pdb: hkLimitedHingeConstraintCinfo::CreateData | bhkLimitedHingeConstraint.obj | fnv360_0822_retail, caller_sim, low
int SourceOwner::FUN_0091c870()
{
    if (!source)
        source = new Source91();
    return 0xe0;
}
}

// @f3 0x009144f0 (community match, verified in this file)
extern float DAT_00f7a690;
namespace f3m_009144f0 {
namespace f3_009144f0 {

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
    Vec4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
};

struct Light {
    int unk00;
    float unk04;
    int unk08;
    int unk0C;
    Vec4 color;
    Light() : unk00(0), unk04(DAT_00f7a690)
    {
        color.x = 1.0f;
        color.y = 1.0f;
        color.z = 1.0f;
    }
    static void* operator new(unsigned int size) {
        char* p=(char*)DAT_01090a78.FUN_0086b930(size+16);
        unsigned char delta=(unsigned char)(16-(unsigned char)((unsigned int)p&15));
        p+=delta; p[-1]=delta; return p;
    }
};

struct LightOwner {
    int unk00;
    int unk04;
    int unk08;
    Light* m_light;
    void FUN_00914120(Light* light);
    Light* FUN_009144f0(bool* created);
};

Light* LightOwner::FUN_009144f0(bool* created)
{
    if (!m_light) {
        m_light = new Light;
        if (unk08)
            FUN_00914120(m_light);
        *created = true;
        return m_light;
    }
    *created = false;
    return m_light;
}
}
}   // namespace f3m_009144f0

// @f3 0x00910f80 (community match, verified in this file)
namespace f3m_00910f80 {
class NiRefObject {
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct Iface910 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct HolderBase910 {
    int unk00;
    int unk04;
    NiRefObject* m_ref;
    int unk0C;
};

struct Holder910 : HolderBase910, Iface910 {
};

struct Provider910 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual Iface910* GetInterface();
};

struct BaseThing910 {
    int unk00;
    int unk04;
    Provider910* m_provider;
    void FUN_008f75e0(bool active);
};

struct Thing910 : BaseThing910 {
    void FUN_00910f80(bool active);
};

static inline Holder910* GetHolder910(Thing910* thing)
{
    if (!thing)
        return 0;
    Provider910* provider = thing->m_provider;
    if (provider) {
        Iface910* iface = provider->GetInterface();
        if (iface)
            return static_cast<Holder910*>(iface);
    }
    return 0;
}

// pdb: bhkBvTreeShape::Link | bhkBvTreeShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: abAttach
void Thing910::FUN_00910f80(bool active)
{
    if (active) {
        Holder910* holder = GetHolder910(this);
        if (holder && holder->m_ref)
            holder->m_ref->IncRefCount();
    } else {
        Holder910* holder = GetHolder910(this);
        if (holder && holder->m_ref)
            holder->m_ref->DecRefCount();
    }
    BaseThing910::FUN_008f75e0(active);
}
}   // namespace f3m_00910f80

// @f3 0x00918490 (community match, verified in this file)
namespace f3m_00918490 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Heap918 {
    void FUN_008f6d90(void* memory, int size, int tag);
};

struct Elem918 {
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
    ~Elem918();
};

struct ArrayBase918 {
    enum { CAPACITY_MASK = int(0x3FFFFFFF), DONT_DEALLOCATE_FLAG = int(0x80000000) };
    Elem918* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~ArrayBase918()
    {
        if (!(m_capacityAndFlags & 0x80000000)) {
            int allocated = m_capacityAndFlags & 0x3fffffff;
            Heap918* heap = (Heap918*)DAT_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(m_data, allocated * sizeof(Elem918), 23);
        }
    }
};

struct Array918 : ArrayBase918 {
    ~Array918();
};

// pdb: hkaDetectRagdollPenetration::Output::~Output | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
Array918::~Array918()
{
    int count = m_size;
    for (int i = 0; i < count; i++)
        m_data[i].~Elem918();
}
}   // namespace f3m_00918490

// @f3 0x0091a2c0 (community match, verified in this file)
namespace f3m_0091a2c0 {

struct Slot91a {
    int m_value;
    float m_weight;
};

struct Table91a {
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
    void** m_data;
    unsigned int m_count;
    int unkD8;
    int unkDC;
    int unkE0;
    Slot91a m_slots[9];
    void FUN_0091a2c0();
};

void Table91a::FUN_0091a2c0()
{
    unsigned int count = m_count;
    for (unsigned int i = 0; i < count; i++)
        m_data[i] = 0;
    m_slots[0].m_value = 0;
    m_slots[0].m_weight = -2147483648.0f;
    m_slots[1].m_value = 0;
    m_slots[1].m_weight = -2147483648.0f;
    m_slots[2].m_value = 0;
    m_slots[2].m_weight = -2147483648.0f;
    m_slots[3].m_value = 0;
    m_slots[3].m_weight = -2147483648.0f;
    m_slots[4].m_value = 0;
    m_slots[4].m_weight = -2147483648.0f;
    m_slots[5].m_value = 0;
    m_slots[5].m_weight = -2147483648.0f;
    m_slots[6].m_value = 0;
    m_slots[6].m_weight = -2147483648.0f;
    m_slots[7].m_value = 0;
    m_slots[7].m_weight = -2147483648.0f;
    m_slots[8].m_value = 0;
    m_slots[8].m_weight = -2147483648.0f;
}
}   // namespace f3m_0091a2c0

// @f3 0x00908b80 (community match, verified in this file)
namespace f3m_00908b80 {
namespace W908 {
struct Quad { float x, y, z, w; Quad& operator=(const Quad& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; } };
struct P3 { float x, y, z; P3() {} P3(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Info { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; Quad minimum; };
struct bhkWorld { bhkWorld(Info* info); virtual ~bhkWorld(); int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; };
struct bhkWorldM : bhkWorld {
  P3 border; int unkAC; float originX, originY, originZ; int unkBC; Quad minimum;
  bhkWorldM(Info* info);
};
// pdb: bhkWorldM::bhkWorldM | bhkWorldM.obj | fnv360_0822_retail, call_gap, low
// pdb params: arInfo, arWorldSize, arBorderSize
bhkWorldM::bhkWorldM(Info* info) : bhkWorld(info), border(37454.277f, 37454.277f, 37454.277f) {
  minimum = info->minimum;
  if (info) {
    originX = (float)(info->minimum.x - 585.2230834960938);
    originY = (float)(info->minimum.y - 585.2230834960938);
    originZ = (float)(info->minimum.z - 585.2230834960938);
  }
}
}
}   // namespace f3m_00908b80

// @f3 0x009141d0 (community match, verified in this file)
namespace f3m_009141d0 {
extern void (__stdcall* const DAT_00d9b09c)(void*);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
struct CriticalSection {
    void* debugInfo;
    long lockCount,recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned int spinCount;
};
extern CriticalSection DAT_010f3194;
void* FUN_0089eb90(unsigned int);
void FUN_0089e890(void*);
struct FUN_0091d000 {
    unsigned int unk00,unk04,unk08,unk0c,unk10;
    FUN_0091d000();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* object) { FUN_0089e890(object); }
};
struct Owner {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8c();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Attach(FUN_0091d000*,unsigned int);
    FUN_0091d000* FUN_009141d0(unsigned int argument);
};
// pdb: bhkBoxShape::CreateClone | bhkBoxShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
FUN_0091d000* Owner::FUN_009141d0(unsigned int argument) {
    DAT_00d9b09c(&DAT_010f3194);
    FUN_0091d000* object = new FUN_0091d000;
    Attach(object, argument);
    DAT_00d9b0a0(&DAT_010f3194);
    return object;
}
}

// @f3 0x0090ead0 (community match, verified in this file)
namespace f3m_0090ead0 {
extern void (__stdcall* const DAT_00d9b09c)(void*);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
struct CriticalSection {
    void* debugInfo;
    long lockCount,recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned int spinCount;
};
extern CriticalSection DAT_010f3194;
void* FUN_0089eb90(unsigned int);
void FUN_0089e890(void*);
struct FUN_0091d000 {
    unsigned int unk00,unk04,unk08,unk0c,unk10;
    FUN_0091d000();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* object) { FUN_0089e890(object); }
};
struct Owner {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8c();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Attach(FUN_0091d000*,unsigned int);
    FUN_0091d000* FUN_0090ead0(unsigned int argument);
};
// pdb: bhkSphereShape::CreateCinfo | bhkSphereShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkSphereShape::CreateClone)
// pdb params: arCreated
FUN_0091d000* Owner::FUN_0090ead0(unsigned int argument) {
    DAT_00d9b09c(&DAT_010f3194);
    FUN_0091d000* object = new FUN_0091d000;
    Attach(object, argument);
    DAT_00d9b0a0(&DAT_010f3194);
    return object;
}
}

// @f3 0x0090a9b0 (community match, verified in this file)
extern void* DAT_00e35170[];
namespace f3m_0090a9b0 {
struct hkBaseObject {void** table;};

struct NativeBool {char value;NativeBool& operator=(bool b){value=(char)b;return *this;}};
class hkReferencedObject:public hkBaseObject
{
public:
    unsigned short memSizeAndFlags;
    short referenceCount;
    __forceinline hkReferencedObject() : referenceCount(1) {}
};
struct __declspec(align(16)) WorldVector4
{
    float x,y,z,w;
    __forceinline void Set(float newX,float newY,float newZ,float newW)
    { x=newX;y=newY;z=newZ;w=newW; }
};
class hkpWorldCinfo : public hkReferencedObject
{
public:
    hkpWorldCinfo();
    WorldVector4 gravity;
    int broadPhaseQuerySize;
    float maximumConstraintViolation;
    unsigned char broadPhaseBorderBehaviour;
    unsigned char unk29, unk2A, unk2B;
    int unk2C;
    WorldVector4 minimum, maximum;
    float collisionTolerance;
    void* collisionFilter;
    void* convexListFilter;
    float expectedMaximumLinearVelocity;
    int sizeOfToiEventQueue;
    float expectedMinimumPsiDeltaTime;
    void* memoryWatchDog;
    int broadPhaseMarkers;
    unsigned char contactPointGeneration;
    unsigned char unk71, unk72, unk73;
    float solverTau;
    float solverDamp;
    int solverIterations;
    int solverMicrosteps;
    NativeBool coherentConstraintOrdering;
    unsigned char unk85, unk86, unk87;
    float snapToConvexEdgeThreshold;
    float snapToConcaveEdgeThreshold;
    NativeBool enableToiWeldRejection;
    NativeBool enableDeprecatedWelding;
    unsigned char unk92, unk93;
    float deactivationReferenceDistance;
    int solverDeactivationClass;
    int unk9C, unkA0;
    unsigned char deactivationFlag0, deactivationFlag1;
    unsigned char deactivationIntegrateCounter, activateOnTransformChange;
    float toiPenetrationThreshold;
    float toiCollisionResponseRotateNormal;
    int maximumSectorsPerMidphaseTask;
    NativeBool processToisMultithreaded;
    unsigned char unkB5, unkB6, unkB7;
    int maximumEntriesPerMidphaseToiTask;
    unsigned char rigidBodyFlag, maximumEntriesPerNarrowphaseToiTask;
    unsigned char enableSimulationIslands, unkBF;
    int minimumDesiredIslandSize;
    NativeBool processActionsInSingleThread;
    unsigned char unkC5, unkC6, unkC7;
    float frameMarkerPsiSnap;
};
// pdb: hkpWorldCinfo::hkpWorldCinfo | hkpWorldCinfo.obj | fnv360_0822_retail, uconst, high
hkpWorldCinfo::hkpWorldCinfo()
{
    table=DAT_00e35170;
    gravity.Set(0.0f,(-9.8f),0.0f,0.0f);
    enableSimulationIslands = 1;
    broadPhaseQuerySize = 0x400;
    minimum.Set((-500.0f),(-500.0f),(-500.0f),0.0f);
    maximum.Set((500.0f),(500.0f),(500.0f),0.0f);
    collisionFilter = 0;
    convexListFilter = 0;
    solverTau = 0.6f;
    broadPhaseMarkers = 0;
    sizeOfToiEventQueue = 250;
    solverDamp = 1.0f;
    solverIterations = 4;
    maximumConstraintViolation = (3.40282e38f);
    solverMicrosteps = 1;
    coherentConstraintOrdering = 0;
    snapToConvexEdgeThreshold = (0.524f);
    snapToConcaveEdgeThreshold = (0.698f);
    enableToiWeldRejection = 0;
    collisionTolerance = 0.1f;
    broadPhaseBorderBehaviour = 0;
    toiCollisionResponseRotateNormal = 0.2f;
    processToisMultithreaded = 1;
    toiPenetrationThreshold = 0.02f;
    maximumSectorsPerMidphaseTask = 4;
    expectedMaximumLinearVelocity = (200.0f);
    maximumEntriesPerMidphaseToiTask = 1;
    expectedMinimumPsiDeltaTime = (0.033333335f);
    deactivationReferenceDistance = 0.01f;
    enableDeprecatedWelding = 0;
    solverDeactivationClass = 20;
    rigidBodyFlag = 1;
    activateOnTransformChange = 1;
    *static_cast<volatile float*>(&frameMarkerPsiSnap)=(0.0001f);
    minimumDesiredIslandSize = 64;
    deactivationFlag0 = 0;
    deactivationFlag1 = 0;
    deactivationIntegrateCounter = 0;
    contactPointGeneration = 2;
    maximumEntriesPerNarrowphaseToiTask = 2;
    memoryWatchDog = 0;
    processActionsInSingleThread = 1;
}

}   // namespace f3m_0090a9b0

// @f3 0x00916390 (community match, verified in this file)
extern const float DAT_00e36470[];
namespace f3m_00916390 {
namespace f3m_00916390 {
struct Vec4 { float x, y, z, w; };
struct Decoder {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec4 scale;
    void FUN_00916390(const unsigned short* codes, int count, Vec4* output);
};
void Decoder::FUN_00916390(const unsigned short* codes, int count, Vec4* output)
{
    for (int left = count - 1; left >= 0; --left) {
        float firstScale = scale.x;
        unsigned int code = *codes++;
        const float* entry = &DAT_00e36470[code * 2];
        output->x = firstScale * entry[0];
        output->y = entry[1] * scale.y;
        output->z = entry[2] * scale.z;
        output->w = entry[3] * scale.w;
        reinterpret_cast<unsigned int*>(output)[3] = code | 0x3f000000;
        ++output;
    }
}
}



}   // namespace f3m_00916390

// @f3 0x0091ee20 (community match, verified in this file)
namespace f3m_0091ee20 {
namespace f3w_91ee20 {

struct __declspec(align(16)) hkVector4 {
    float m[4];
    hkVector4& operator=(const hkVector4& v) {
        for (int k = 0; k < 4; k++)
            m[k] = v.m[k];
        return *this;
    }
};

struct hkpPhantomListener;

struct hkpPhantom {
    void hkpPhantom_removePhantomListener(hkpPhantomListener* listener);
};

struct hkpCollidable {
    int unk00[4];
    signed char m_ownerOffset;
    char pad11[7];
    unsigned char m_type;
    void* GetOwner() const { return (void*)((char*)this + m_ownerOffset); }
};

static inline hkpPhantom* hkGetPhantom(const hkpCollidable* c) {
    if (c->m_type == 2)
        return (hkpPhantom*)c->GetOwner();
    return 0;
}

struct hkpRootCdPoint {
    hkVector4 m_position;
    hkVector4 m_normal;
    void* m_rootCollidableA;
    int m_shapeKeyA;
    hkpCollidable* m_rootCollidableB;
    int m_shapeKeyB;
    int unk30;
    int unk34;
    int unk38;
};

template <class T> struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    void removeAt(int index) { m_data[index] = m_data[--m_size]; }
    int indexOf(const T& t) const {
        for (int i = 0; i < m_size; i++) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

struct hkBaseObject { virtual void v00(); };
struct hkReferencedObject : hkBaseObject { short m_memSize; short m_referenceCount; };
struct hkpEntityListener { virtual void v00(); };
struct hkpPhantomListener { virtual void hkpCharacterProxy_phantomRemovedCallback(hkpPhantom* phantom); };

struct hkpCharacterProxy : hkReferencedObject, hkpEntityListener, hkpPhantomListener {
    float unk10[0x19];
    hkArray<hkpRootCdPoint> m_manifold;
    hkArray<void*> m_bodies;
    hkArray<void*> m_overlaps;
    hkArray<hkpPhantom*> m_phantoms;
    virtual void hkpCharacterProxy_phantomRemovedCallback(hkpPhantom* phantom);
};

// pdb: hkpCharacterProxy::phantomRemovedCallback | hkpCharacterProxy.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpCharacterProxy::hkpCharacterProxy_phantomRemovedCallback(hkpPhantom* phantom) {
    phantom->hkpPhantom_removePhantomListener(this);
    for (int i = m_manifold.m_size - 1; i >= 0; i--) {
        if (hkGetPhantom(m_manifold.m_data[i].m_rootCollidableB) == phantom)
            m_manifold.removeAt(i);
    }
    m_phantoms.removeAt(m_phantoms.indexOf(phantom));
}

}
}   // namespace f3m_0091ee20

// @f3 0x0090b6c0 (community match, verified in this file)
#include <new>
namespace f3m_0090b6c0 {
struct hkFinishLoadedObjectFlag { int m_finishing; };
class hkBaseObject { public: virtual ~hkBaseObject() {} };
class hkReferencedObject : public hkBaseObject {
public:
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    hkReferencedObject(hkFinishLoadedObjectFlag) { m_referenceCount = 1; }
    virtual ~hkReferencedObject() {}
};
class hkpMotion : public hkReferencedObject {
public:
    void* operator new(size_t, void* p) { return p; }
public:
    unsigned char m_type;
    char m_body[0x120 - 9];
    hkpMotion(hkFinishLoadedObjectFlag f) : hkReferencedObject(f) {}
    virtual ~hkpMotion() {}
};
class hkpKeyframedRigidMotion : public hkpMotion { public: hkpKeyframedRigidMotion(hkFinishLoadedObjectFlag f) : hkpMotion(f) {} virtual ~hkpKeyframedRigidMotion() {} };
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion { public: hkpMaxSizeMotion(hkFinishLoadedObjectFlag f) : hkpKeyframedRigidMotion(f) {} virtual ~hkpMaxSizeMotion() {} };
class hkpFixedRigidMotion : public hkpKeyframedRigidMotion { public: hkpFixedRigidMotion(hkFinishLoadedObjectFlag f) : hkpKeyframedRigidMotion(f) {} virtual ~hkpFixedRigidMotion() {} };
class hkpSphereMotion : public hkpMotion { public: hkpSphereMotion(hkFinishLoadedObjectFlag f) : hkpMotion(f) {} virtual ~hkpSphereMotion() {} };
class hkpStabilizedSphereMotion : public hkpSphereMotion { public: hkpStabilizedSphereMotion(hkFinishLoadedObjectFlag f) : hkpSphereMotion(f) {} virtual ~hkpStabilizedSphereMotion() {} };
class hkpBoxMotion : public hkpMotion { public: hkpBoxMotion(hkFinishLoadedObjectFlag f) : hkpMotion(f) {} virtual ~hkpBoxMotion() {} };
class hkpStabilizedBoxMotion : public hkpBoxMotion { public: hkpStabilizedBoxMotion(hkFinishLoadedObjectFlag f) : hkpBoxMotion(f) {} virtual ~hkpStabilizedBoxMotion() {} };
class hkpThinBoxMotion : public hkpBoxMotion { public: hkpThinBoxMotion(hkFinishLoadedObjectFlag f) : hkpBoxMotion(f) {} virtual ~hkpThinBoxMotion() {} };
class hkpCharacterMotion : public hkpMotion { public: hkpCharacterMotion(hkFinishLoadedObjectFlag f) : hkpMotion(f) {} virtual ~hkpCharacterMotion() {} };

namespace w90b6c0 {
struct SmallArr {
    void* m_data; unsigned short m_size; unsigned short m_cap;
    SmallArr() : m_data(0), m_size(0), m_cap(0x8000) {}
};
struct Arr {
    void* m_data; int m_size; int m_cap;
    Arr() : m_data(0), m_size(0), m_cap(0x80000000) {}
};
}
class FUN_009319e0 {
public:
    FUN_009319e0(hkFinishLoadedObjectFlag f);
    virtual ~FUN_009319e0();
    int m_world[0x94 / 4];
};
class hkpEntity : public FUN_009319e0 {
public:
    w90b6c0::SmallArr m_constraintsMaster;
    w90b6c0::Arr m_constraintsSlave;
    w90b6c0::Arr m_constraintRuntime;
    void* m_simulationIsland;
    int m_unkbc;
    int m_unkc0;
    int m_unkc4;
    unsigned short m_unkc8;
    unsigned char m_unkca;
    unsigned char m_unkcb;
    int m_unkcc;
    hkpMaxSizeMotion m_motion;
    w90b6c0::SmallArr m_contactListeners;
    w90b6c0::SmallArr m_actions;
    hkpEntity(hkFinishLoadedObjectFlag flag);
    virtual ~hkpEntity() {}
};
// pdb: hkpEntity::hkpEntity | hkpEntity.obj | tesv_win, objrun, medium
hkpEntity::hkpEntity(hkFinishLoadedObjectFlag flag)
    : FUN_009319e0(flag), m_unkc4(0), m_unkc8(0), m_unkca(3), m_unkcb(1), m_motion(flag)
{
    if (flag.m_finishing) {
        hkpMotion* motion = &m_motion;
        switch (m_motion.m_type) {
        case 2: new (motion) hkpSphereMotion(flag); break;
        case 3: new (motion) hkpStabilizedSphereMotion(flag); break;
        case 4: new (motion) hkpBoxMotion(flag); break;
        case 5: new (motion) hkpStabilizedBoxMotion(flag); break;
        case 6: new (motion) hkpKeyframedRigidMotion(flag); break;
        case 7: new (motion) hkpFixedRigidMotion(flag); break;
        case 8: new (motion) hkpThinBoxMotion(flag); break;
        case 9: new (motion) hkpCharacterMotion(flag); break;
        }
    }
}
}   // namespace f3m_0090b6c0

// @f3 0x0090a580 (community match, verified in this file)
namespace f3m_0090a580 {
extern "C" void _ReadWriteBarrier(void);
namespace workerB90a580 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern void (__stdcall* DAT_00d9b0a0)(void*);
extern int(__stdcall* DAT_00d9b1ac)(void*,unsigned);extern unsigned long DAT_010f3170;extern void* DAT_00e35154;
struct Mutex{Mutex* freeNext;int unk04,unk08,unk0c,unk10,unk14;int owner,recursion;unsigned spin;Mutex* previous;Mutex* next;void FUN_00908a00();};extern Mutex DAT_011692e8;struct Bucket{Mutex* head;int count;};
struct Heap{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int limit;Bucket buckets[5];void* FUN_008f6800(int,int);};
inline Mutex* Allocate(){Heap* h=(Heap*)DAT_00d9b080(DAT_010f3170);Mutex* p=h->buckets[4].head;if(p){--h->buckets[4].count;h->buckets[4].head=p->freeNext;}else p=(Mutex*)h->FUN_008f6800(4,0x15);return p;}
struct RefHeader{void* vtable;unsigned short size;short refs;RefHeader(){refs=1;}};struct FUN_0090a580:RefHeader{void* data;int count;unsigned capacity;Mutex* mutex;FUN_0090a580();};
// pdb: hkDebugDisplay::hkDebugDisplay | hkDebugDisplay.obj | fnv360_0822_retail, objrun_prop, low
FUN_0090a580::FUN_0090a580():RefHeader(){vtable=&DAT_00e35154;_ReadWriteBarrier();data=0;count=0;capacity=0x80000000;Mutex* p=Allocate();if(p){p->spin=1000;p->previous=0;p->next=0;DAT_011692e8.FUN_00908a00();p->next=DAT_011692e8.next;if(p->next)p->next->previous=p;p->previous=&DAT_011692e8;DAT_011692e8.next=p;DAT_011692e8.owner=-1;DAT_011692e8.recursion=-1;DAT_00d9b0a0(&DAT_011692e8);DAT_00d9b1ac(p,1000);p->owner=-1;p->recursion=-1;mutex=p;}else mutex=0;}
}






}   // namespace f3m_0090a580

// @f3 0x00912820 (community match, verified in this file)
#include <math.h>

namespace f3m_00912820 {

struct NiRTTI { const char* name; NiRTTI* parent; };
extern NiRTTI DAT_0108f470;

struct NiObject {
    virtual void v00();
    virtual void v04();
    virtual NiRTTI* GetRTTI();
    unsigned int unk04;
    unsigned int unk08;
    unsigned short unk0C;
};

struct Entry { NiObject* obj; int unk04; };
extern Entry DAT_010f32e4;


struct NiPoint3 { float x, y, z; };

struct Extra {
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
    NiPoint3 unk28;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
};


void* FUN_0089eb90(unsigned int size);
const char* FUN_008242a0(const char* s);
extern const char* FUN_00e207a8;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
void FUN_008f7460(int layer, NiPoint3* out);
extern void (*DAT_010f2c24)(void*);
extern const char FUN_00e3256c[];

struct Strips {
    static void* operator new(unsigned int) { return FUN_0089eb90(0xc4); }
    static void operator delete(void* p);
    Strips(NiObject* data);
    void FUN_008245d0(const char** name);
    int* FUN_00826590(int kind);
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
    float unk64;
};

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
    virtual void vA4();
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
    virtual void Attach(Strips* s, bool b);
};


struct Shape {
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
    virtual void vA4();
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
    virtual void Setup(Strips* s);
    struct Inner {
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
        Entry* unk98;
        int unk9C;
        int unkA0;
    };
    int unk04;
    Inner* unk08;
    float FUN_009123e0();
    void FUN_00912820(Node* parent);
};

static inline bool IsKind(NiObject* o)
{
    for (NiRTTI* r = o->GetRTTI(); r; r = r->parent)
        if (r == &DAT_0108f470) return true;
    return false;
}

struct FixedString {
    const char* h;
    FixedString(const char* s) { h = FUN_008242a0(s); }
    ~FixedString() { if (h != FUN_00e207a8) InterlockedDecrement((long*)(h - 8)); }
};

// pdb: bhkNiTriStripsShape::BuildDisplayGeometry | bhkNiTriStripsShape.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: apNode, arDefColor
void Shape::FUN_00912820(Node* parent)
{
    int count = (this && unk08) ? unk08->unkA0 : 0;
    for (int i = 0; i < count; i++) {
        Entry* e = (this && unk08) ? &unk08->unk98[i] : &DAT_010f32e4;
        NiObject* obj = e->obj;
        if (!obj) continue;
        NiObject* data = IsKind(obj) ? obj : 0;
        if (!data) continue;
        Strips* s = new Strips(data);
        {
            FixedString name(FUN_00e3256c);
            s->FUN_008245d0(&name.h);
        }
        s->unk64 = (float)fabs(FUN_009123e0());
        Setup(s);
        Extra* x = (Extra*)s->FUN_00826590(2);
        if (x) {
            int layer = e->obj ? (e->obj->unk0C >> 6) & 0x1f : 0;
            NiPoint3 p;
            p.x = 0.0f; p.y = 0.0f; p.z = 0.0f;
            FUN_008f7460(layer, &p);
            x->unk28 = p;
            x->unk44++;
        }
        if (DAT_010f2c24) DAT_010f2c24(s);
        parent->Attach(s, true);
    }
}

}

// @f3 0x00917120 (community match, verified in this file)
namespace f3m_00917120 {

namespace f3m_00917120 {

struct Pt3_917 { float x; float y; float z; };

__declspec(align(16)) struct Vec4_917 {
    float x; float y; float z; float w;
    void setCross(const Vec4_917& a, const Vec4_917& b)
    {
        float nx = a.y * b.z - a.z * b.y;
        float ny = a.z * b.x - a.x * b.z;
        float nz = a.x * b.y - a.y * b.x;
        x = nx; y = ny; z = nz; w = 0.0f;
    }
    void add4(const Vec4_917& a)
    {
        x += a.x; y += a.y; z += a.z; w += a.w;
    }
};

class Holder917
{
public:
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
    Pt3_917 pos;
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
    Vec4_917 offset;
    Vec4_917 axis;
    void FUN_00917120(const Pt3_917* in, Vec4_917* out);
};

}
using namespace f3m_00917120;

// pdb: hkpRigidBody::getPointVelocity | bhkRagdollPenetrationUtil.obj | fnv360_0822_debug, call_gap, low
// pdb params: p, vecOut
void Holder917::FUN_00917120(const Pt3_917* in, Vec4_917* out)
{
    Vec4_917 d;
    d.x = in->x - pos.x;
    d.y = in->y - pos.y;
    d.z = in->z - pos.z;
    out->setCross(axis, d);
    out->add4(offset);
}
}   // namespace f3m_00917120

// @f3 0x00916fc0 (community match, verified in this file)
extern int DAT_01268798;
namespace f3m_00916fc0 {

namespace f3m_00916fc0 {
struct __declspec(align(16)) Vec916fc0 {
    float x, y, z, w;
};
struct Aabb916fc0 {
    Vec916fc0 min;
    Vec916fc0 max;
};
class Shape916fc0 {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void GetAabb(const int* space, float tolerance, Aabb916fc0* out);
    void FUN_00916fc0(Vec916fc0* center);
};
void Shape916fc0::FUN_00916fc0(Vec916fc0* center)
{
    Aabb916fc0 aabb;
    GetAabb(&DAT_01268798, 0.0f, &aabb);
    center->x = (float)(aabb.max.x + aabb.min.x) * 0.5;
    center->y = (float)(aabb.min.y + aabb.max.y) * 0.5;
    center->z = (float)(aabb.max.z + aabb.min.z) * 0.5;
    center->w = (float)(aabb.max.w + aabb.min.w) * 0.5;
}
}
}   // namespace f3m_00916fc0

// @f3 0x0091b0d0 (community match, verified in this file)
namespace f3m_0091b0d0 {
namespace f3m_0091b0d0 {

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
    float pad[4];
};

class Owner
{
public:
    char pad00[0xc0];
    void** items;      // 0xc0
    char padc4[0x0c];
    int* results;      // 0xd0
    int count;         // 0xd4

    bool FUN_0091afd0(void* p, Vec4* out, unsigned int i, unsigned int j);
    int FUN_0091b0d0(int index);
};

int Owner::FUN_0091b0d0(int index)
{
    int result = 0;
    if (index < count)
    {
        void* p = items[index];
        if (p)
        {
            int mask = 1;
            for (unsigned int i = 0; i < 3; i++)
            {
                bool found = false;
                for (unsigned int j = 0; j < 3; j++)
                {
                    if (!found || j == 1)
                    {
                        Vec4 tmp;
                        if (FUN_0091afd0(p, &tmp, i, j))
                            found = true;
                    }
                    if (found)
                        result |= mask;
                    mask <<= 1;
                }
            }
            results[index] = result;
        }
    }
    return result;
}

}
}   // namespace f3m_0091b0d0

// @f3 0x0091d510 (community match, verified in this file)
namespace F3ConstraintFactory {
struct RawVector { float x, y, z, w; };
struct __declspec(align(16)) AlignedVector {
    float x, y, z, w;
    explicit AlignedVector(const RawVector& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
};
struct Configuration {
    unsigned flags;
    float radius;
    unsigned unk08, unk0c;
    RawVector basisA, basisB;
};
struct Heap { void* FUN_008f6d30(unsigned, unsigned); };
extern unsigned DAT_010f3170;
extern Heap* (__stdcall* DAT_00d9b080)(unsigned);
extern const float DAT_00f7a690;
extern char DAT_00e324cc;
void __cdecl FUN_0091d3d0(void*);
struct FUN_009a30a0;
struct ShapeTable {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void (__thiscall* Initialize)(FUN_009a30a0*);
};
struct FUN_009a30a0 {
    ShapeTable* table;
    unsigned short size, refs;
    void* child;
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
    FUN_009a30a0(const AlignedVector&,const AlignedVector&,float,int,int);
    static void* operator new(unsigned bytes) {
        Heap* heap=DAT_00d9b080(DAT_010f3170);
        FUN_009a30a0* p=static_cast<FUN_009a30a0*>(heap->FUN_008f6d30(bytes,8));
        p->size=static_cast<unsigned short>(bytes);
        return p;
    }
    static void operator delete(void* p) { FUN_0091d3d0(p); }
};
struct Owner;
struct OwnerTable {
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
    void* unk40;
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
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unka0;
    void* unka4;
    void* unka8;
    void* unkac;
    void* unkb0;
    void* unkb4;
    void* unkb8;
    void* unkbc;
    void* unkc0;
    void* unkc4;
    void* unkc8;
    void* unkcc;
    void* unkd0;
    void (__thiscall* AttachChild)(Owner*, int, void*, const void*);
};
struct Owner {
    OwnerTable* table;
    void FUN_0091d050(Configuration*);
    void FUN_0091d510(int);
};
// pdb: bhkCapsuleShape::BuildDisplayGeometry | bhkCapsuleShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apNode, arDefColor
void Owner::FUN_0091d510(int input)
{
    Configuration config;
    config.radius=DAT_00f7a690;
    config.flags=0;
    config.basisA.x=0.0f;
    config.basisA.y=0.0f;
    config.basisA.z=0.0f;
    config.basisA.w=0.0f;
    config.basisB.x=1.0f;
    config.basisB.y=0.0f;
    config.basisB.z=0.0f;
    config.basisB.w=0.0f;
    FUN_0091d050(&config);
    FUN_009a30a0* shape=new FUN_009a30a0(
        AlignedVector(config.basisA),AlignedVector(config.basisB),config.radius,6,1);
    shape->table->Initialize(shape);
    void* child=shape->child;
    if (child)
        table->AttachChild(this,input,child,&DAT_00e324cc);
}
}

// @f3 0x0091fdb0 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
extern char DAT_00de6e78[];
namespace f3m_0091fdb0 {


struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
};

struct hkpCollisionInput
{
    int unk00;
    float m_tolerance;
    int unk08;
    int unk0c;
    int unk10;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    hkpCollisionInput(const hkpCollisionInput& other);
};

struct hkpWorld
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
    hkpCollisionInput* m_collisionInput;
};

struct hkThreadMemory
{
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    static hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};

struct hkpRootCdPoint
{
    hkVector4 m_position;
    hkVector4 m_normal;
    void* m_rootCollidableA;
    int m_shapeKeyA;
    void* m_rootCollidableB;
    int m_shapeKeyB;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

struct hkpAllCdPointCollector
{
    void* m_vtable;
    float m_earlyOutDistance;
    int unk08;
    int unk0c;
    hkpRootCdPoint* m_hits;
    int m_size;
    int m_capacityAndFlags;
    int unk1c;
    hkpRootCdPoint m_storage[8];

    hkpAllCdPointCollector() throw()
    {
        m_vtable = DAT_00de6e78;
        m_earlyOutDistance = 3.40282e38f;
        m_hits = m_storage;
        m_capacityAndFlags = 0x80000008;
        m_size = 0;
    }
    void reset() throw()
    {
        m_earlyOutDistance = 3.40282e38f;
        m_size = 0;
    }
    void release() throw()
    {
        m_vtable = DAT_00de6e78;
        if ((m_capacityAndFlags & 0x80000000) == 0)
            hkThreadMemory::getInstance().FUN_008f6d90(m_hits, getCapacity() * sizeof(hkpRootCdPoint), 0x17);
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
};

struct hkpShapePhantom
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
    virtual void getClosestPoints(hkpAllCdPointCollector& collector, const hkpCollisionInput* input) throw();
    int m_memSizeAndRefCount;
    hkpWorld* m_world;
};

struct hkpCharacterProxy
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void updateManifold(hkpAllCdPointCollector& startPointCollector, hkpAllCdPointCollector& castCollector) throw();
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
    hkpShapePhantom* m_shapePhantom;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float m_keepDistance;
    float m_keepContactTolerance;

    void FUN_0091fdb0(hkpAllCdPointCollector& startPointCollector);
};

// pdb: hkpCharacterProxy::refreshManifold | hkpCharacterProxy.obj | fnv360_0822_retail, objrun, medium
// pdb params: startPointCollector
void hkpCharacterProxy::FUN_0091fdb0(hkpAllCdPointCollector& startPointCollector)
{
    startPointCollector.reset();
    hkpCollisionInput input = *m_shapePhantom->m_world->m_collisionInput;
    input.m_tolerance = (m_keepContactTolerance + m_keepDistance) + input.m_tolerance;
    m_shapePhantom->getClosestPoints(startPointCollector, &input);

    hkpAllCdPointCollector castCollector;
    updateManifold(startPointCollector, castCollector);
    castCollector.release();
}
}   // namespace f3m_0091fdb0

// @f3 0x0091e390 (community match, verified in this file)
namespace f3m_0091e390 {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef const hkSimdReal& hkSimdRealParameter;

struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void mul4(hkSimdRealParameter s) { hkReal f = s; x *= f; y *= f; z *= f; w *= f; }
    __forceinline void setMul4(hkSimdRealParameter s, const hkVector4& v)
    {
        x = s * v.x;
        y = s * v.y;
        z = s * v.z;
        w = s * v.w;
    }
    __forceinline void add4(const hkVector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    __forceinline void addMul4(hkSimdRealParameter s, const hkVector4& v)
    {
        x += s * v.x;
        y += s * v.y;
        z += s * v.z;
        w += s * v.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline hkSimdReal dot3(const hkVector4& v) const { return x * v.x + y * v.y + z * v.z; }
};

struct hkSweptTransform
{
    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkVector4 m_rotation0;
    hkVector4 m_rotation1;
    hkVector4 m_centerOfMassLocal;
    __forceinline hkReal getInvDeltaTime() const { return m_centerOfMass1(3); }
};

struct hkMotionState
{
    hkVector4 m_transform0;
    hkVector4 m_transform1;
    hkVector4 m_transform2;
    hkVector4 m_transform3;
    hkSweptTransform m_sweptTransform;
    hkVector4 m_deltaAngle;
    __forceinline const hkSweptTransform& getSweptTransform() const { return m_sweptTransform; }
};

enum hkpMotionType
{
    MOTION_KEYFRAMED = 6,
    MOTION_FIXED = 7
};

struct hkpMotion
{
    void* m_vtable;
    int m_memSizeAndFlags;
    signed char m_type;
    int unk0c;
    hkMotionState m_motionState;
    __forceinline hkpMotionType getType() const { return (hkpMotionType)m_type; }
    __forceinline const hkMotionState* getMotionState() const { return &m_motionState; }
};

struct hkpCollidable
{
    void* m_shape;
    int m_shapeKey;
    void* m_motion;
    void* m_parent;
    signed char m_ownerOffset;
    int m_broadPhaseId;
    signed char m_type;
    __forceinline int getType() const { return m_type; }
    __forceinline void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_ownerOffset); }
};

struct hkpRigidBody
{
    hkpCollidable m_collidable;
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
    hkpMotion m_motion;

    __forceinline const hkpMotion* getRigidMotion() const { return &m_motion; }
    __forceinline hkpMotionType getMotionType() const { return getRigidMotion()->getType(); }
    __forceinline bool isFixedOrKeyframed() const { return m_motion.m_type == MOTION_FIXED || m_motion.m_type == MOTION_KEYFRAMED; }
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return getRigidMotion()->getMotionState()->getSweptTransform().m_centerOfMass1; }
    void FUN_00917120(const hkVector4& p, hkVector4& vel) const;
};

__forceinline hkpRigidBody* hkGetRigidBody(const hkpCollidable* c)
{
    if (c->getType() == 1)
    {
        return static_cast<hkpRigidBody*>(c->getOwner());
    }
    return 0;
}

__forceinline void hkSweptTransformUtil_getVelocity(const hkMotionState& ms, hkVector4& linearVelOut, hkVector4& angularVelOut)
{
    linearVelOut.setSub4(ms.getSweptTransform().m_centerOfMass1, ms.getSweptTransform().m_centerOfMass0);
    linearVelOut.mul4(ms.getSweptTransform().getInvDeltaTime());
    angularVelOut.setMul4(ms.getSweptTransform().getInvDeltaTime(), ms.m_deltaAngle);
}

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
    __forceinline const hkVector4& getPosition() const { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline const hkVector4& getSeparatingNormal() const { return m_separatingNormal; }
};

struct hkpRootCdPoint
{
    hkContactPoint m_contact;
    const hkpCollidable* m_rootCollidableA;
    int m_shapeKeyA;
    const hkpCollidable* m_rootCollidableB;
    int m_shapeKeyB;
};

struct hkpSurfaceConstraintInfo
{
    hkVector4 m_plane;
    hkVector4 m_velocity;
    hkReal m_staticFriction;
    hkReal m_extraUpStaticFriction;
    hkReal m_extraDownStaticFriction;
    hkReal m_dynamicFriction;
    int m_priority;
};

class hkpCharacterProxy
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
    hkReal m_dynamicFriction;
    hkReal m_staticFriction;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    hkReal m_extraUpStaticFriction;
    hkReal m_extraDownStaticFriction;
    hkReal m_keepDistance;
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
    hkReal m_penetrationRecoverySpeed;

    void hkpCharacterProxy_extractSurfaceConstraintInfo(const hkpRootCdPoint& hit, hkpSurfaceConstraintInfo& surface, hkReal timeTravelled) const;
};

// pdb: hkpCharacterProxy::extractSurfaceConstraintInfo | hkpCharacterProxy.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpCharacterProxy::hkpCharacterProxy_extractSurfaceConstraintInfo(const hkpRootCdPoint& hit, hkpSurfaceConstraintInfo& surface, hkReal timeTravelled) const
{
    surface.m_plane = hit.m_contact.getSeparatingNormal();
    surface.m_plane(3) -= m_keepDistance;
    surface.m_staticFriction = m_staticFriction;
    surface.m_dynamicFriction = m_dynamicFriction;
    surface.m_extraUpStaticFriction = m_extraUpStaticFriction;
    surface.m_extraDownStaticFriction = m_extraDownStaticFriction;
    surface.m_velocity.setZero4();
    surface.m_priority = 0;

    hkpRigidBody* body = hkGetRigidBody(hit.m_rootCollidableB);
    if (body)
    {
        if (body->isFixedOrKeyframed())
        {
            body->FUN_00917120(hit.m_contact.getPosition(), surface.m_velocity);
        }
        else
        {
            hkVector4 linear;
            hkVector4 angular;
            hkSweptTransformUtil_getVelocity(*body->getRigidMotion()->getMotionState(), linear, angular);
            hkVector4 r;
            r.setSub4(hit.m_contact.getPosition(), body->getCenterOfMassInWorld());
            surface.m_velocity.setCross(angular, r);
            surface.m_velocity.add4(linear);
        }
        surface.m_plane(3) -= surface.m_plane.dot3(surface.m_velocity) * timeTravelled;
        if (body->getMotionType() == MOTION_FIXED)
        {
            surface.m_priority = 2;
        }
        if (body->getMotionType() == MOTION_KEYFRAMED)
        {
            surface.m_priority = 1;
        }
    }
    if (surface.m_plane(3) < -1.1920928955078125e-07f)
    {
        surface.m_velocity.addMul4(-surface.m_plane(3) * m_penetrationRecoverySpeed, hit.m_contact.getNormal());
        surface.m_plane(3) = 0.0f;
    }
}
}   // namespace f3m_0091e390

// @f3 0x0090e7c0 (community match, verified in this file)
namespace f3m_0090e7c0 {
struct __declspec(align(16)) V7c0
{
    float x, y, z, w;
};
struct Aabb7c0
{
    V7c0 m_min;
    V7c0 m_max;
};
struct Transform7c0
{
    V7c0 m_col0;
    V7c0 m_col1;
    V7c0 m_col2;
    V7c0 m_trans;
};
struct Shape7c0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const Transform7c0& t, float tolerance, Aabb7c0& out);
    float FUN_0090e7c0(const V7c0& dir);
};
float Shape7c0::FUN_0090e7c0(const V7c0& dir)
{
    Transform7c0 t;
    t.m_col0.x = 0.0f; t.m_col0.y = 0.0f; t.m_col0.z = 0.0f; t.m_col0.w = 0.0f;
    t.m_col1.x = 0.0f; t.m_col1.y = 0.0f; t.m_col1.z = 0.0f; t.m_col1.w = 0.0f;
    t.m_col2.x = 0.0f; t.m_col2.y = 0.0f; t.m_col2.z = 0.0f; t.m_col2.w = 0.0f;
    t.m_col0.x = 1.0f;
    t.m_col1.y = 1.0f;
    t.m_col2.z = 1.0f;
    t.m_trans.w = 0.0f; t.m_trans.z = 0.0f; t.m_trans.y = 0.0f; t.m_trans.x = 0.0f;
    Aabb7c0 aabb;
    getAabb(t, 0.0f, aabb);
    V7c0 h;
    h.x = aabb.m_max.x - aabb.m_min.x;
    h.y = aabb.m_max.y - aabb.m_min.y;
    h.z = aabb.m_max.z - aabb.m_min.z;
    h.x = h.x * 0.5;
    h.y = h.y * 0.5;
    h.z = h.z * 0.5;
    V7c0 c;
    c.x = aabb.m_max.x + aabb.m_min.x;
    c.y = aabb.m_max.y + aabb.m_min.y;
    c.z = aabb.m_max.z + aabb.m_min.z;
    c.x = c.x * 0.5;
    c.y = c.y * 0.5;
    c.z = c.z * 0.5;
    *(unsigned int*)&h.x ^= *(const unsigned int*)&dir.x & 0x80000000;
    *(unsigned int*)&h.y ^= *(const unsigned int*)&dir.y & 0x80000000;
    *(unsigned int*)&h.z ^= *(const unsigned int*)&dir.z & 0x80000000;
    h.x = c.x + h.x;
    h.y = c.y + h.y;
    h.z = c.z + h.z;
    return dir.x * h.x + dir.y * h.y + dir.z * h.z;
}
}   // namespace f3m_0090e7c0

// @f3 0x009099a0 (community match, verified in this file)
#include <math.h>
namespace f3m_009099a0 {

template <typename T>
FNV_FORCEINLINE void Swap_99a0(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}

class Vec4_99a0
{
public:
    FNV_FORCEINLINE Vec4_99a0() {}

    FNV_FORCEINLINE float& operator()(int i)
    {
        return (&x)[i];
    }

    FNV_FORCEINLINE const float& operator()(int i) const
    {
        return (&x)[i];
    }

    FNV_FORCEINLINE void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    FNV_FORCEINLINE void setMul4(float rs, const Vec4_99a0& a)
    {
        float r = float(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }

    FNV_FORCEINLINE void setCross(const Vec4_99a0& v1, const Vec4_99a0& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    FNV_FORCEINLINE void setZero4()
    {
        w = 0.0f;
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }

    FNV_FORCEINLINE void setAdd4(const Vec4_99a0& a, const Vec4_99a0& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }

    FNV_FORCEINLINE void setSub4(const Vec4_99a0& a, const Vec4_99a0& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }

    FNV_FORCEINLINE float dot3(const Vec4_99a0& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

private:
    FNV_ALIGN(16) float x;
    float y;
    float z;
    float w;
};

struct Obj_99a0
{
    void FUN_00909410(const Vec4_99a0& a, const Vec4_99a0& b, int c, int d);
    void FUN_009099a0(const Vec4_99a0& center, float r, int c, int d);
};
// pdb: hkDebugDisplay::displayStar | hkDebugDisplay.obj | fnv360_0822_retail, call_seq, medium
// pdb params: position, scale, color, id, tag
void Obj_99a0::FUN_009099a0(const Vec4_99a0& center, float r, int c, int d)
{
    for (int i = 0; i < 3; i++)
    {
        Vec4_99a0 off;
        off.setZero4();
        off(i) = r;
        Vec4_99a0 p;
        p.setAdd4(center, off);
        Vec4_99a0 m;
        m.setSub4(center, off);
        FUN_00909410(p, m, c, d);
    }
}
}   // namespace f3m_009099a0

// @f3 0x0090a1f0 (community match, verified in this file)
namespace f3m_0090a1f0 {
namespace f3m_0090a1f0 {
struct __declspec(align(16)) V4 {
    float x, y, z, w;
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
    void setMul4(float r, const V4& a) { x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    float dot3(const V4& a) const { return x * a(0) + y * a(1) + z * a(2); }
    void addMul4(float r, const V4& a) { x += r * a(0); y += r * a(1); z += r * a(2); w += r * a(3); }
    void setCross(const V4& a, const V4& b)
    {
        x = a(1) * b(2) - a(2) * b(1);
        y = a(2) * b(0) - a(0) * b(2);
        z = a(0) * b(1) - a(1) * b(0);
        w = 0.0f;
    }
    void setAdd4(const V4& a, const V4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    void setRotatedDir(const struct Quat& quat, const V4& direction);
};
struct Quat { V4 m_vec; const V4& getImag() const { return m_vec; } float getReal() const { return m_vec.w; } };
__forceinline void V4::setRotatedDir(const Quat& quat, const V4& direction)
{
    float qreal = quat.getReal();
    float q2minus1 = qreal * qreal - 0.5;
    V4 ret;
    ret.setMul4(q2minus1, direction);
    float imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());
    setCross(quat.getImag(), direction);
    ret.addMul4(qreal, *this);
    setAdd4(ret, ret);
}
struct QsTransform { V4 m_translation; Quat m_rotation; };
struct __declspec(align(16)) Tr {
    float m[4];
    void FUN_008d2b00(const QsTransform* q, const float* s) throw();
};
struct Owner {
    void FUN_00909560(Tr* tr, V4* dir, void* a4, void* a5) throw();
    void FUN_0090a1f0(const QsTransform* q, const float* s, const V4* dir, void* a4, void* a5) throw();
};

void Owner::FUN_0090a1f0(const QsTransform* q, const float* s, const V4* dir, void* a4, void* a5) throw()
{
    Tr tr;
    tr.FUN_008d2b00(q, s);
    V4 rotated;
    rotated.setRotatedDir(q->m_rotation, *dir);
    FUN_00909560(&tr, &rotated, a4, a5);
}
}
}   // namespace f3m_0090a1f0

// @f3 0x0091e260 (community match, verified in this file)
#include <math.h>
namespace f3m_0091e260 {
namespace batch14_20 {
struct Vec3 { float x, y, z;
    float Dot(const Vec3& o) const { return o.x * x + o.y * y + o.z * z; }
    float Length() const { return (float)sqrt(x * x + y * y + z * z); } };
struct Input { Vec3 v; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; float weight; };
struct Plane { float u00, u04, u08, d; Vec3 n; };
struct Context { unsigned u00, u04, u08, u0c; Plane* plane; };
struct Color { float x, y, z, w; };
inline float Minimum(float x, float y) { return x < y ? x : y; }
inline float Maximum(float x, float y) { return x > y ? x : y; }
struct Owner {
    unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014;
    unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c;
    unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044;
    unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054;
    float threshold;
    float FUN_0091e260(Input*, Context*, Color*, Color*);
};
// pdb: hkpCharacterProxy::moveToLinearCastHitPosition | hkpCharacterProxy.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: output, castCollector, castInput, position
float Owner::FUN_0091e260(Input* input, Context* context, Color* color, Color* out)
{
    float length = input->v.Length();
    Plane* plane = context->plane;
    double d = plane->d;
    double limit = threshold;
    float dot = plane->n.Dot(input->v);
    float factor = dot / length;
    factor = (float)(limit / -factor);
    factor = (float)(d - factor / length);
    factor = Maximum(0.0f, Minimum(factor, 1.0f));
    float inverse = 1.0f - factor;
    float* o = &out->x;
    const float* c = &color->x;
    for (int i = 0; i < 4; i++, o++, c++)
        *o = *c * factor + *o * inverse;
    return factor * input->weight;
}
}
}   // namespace f3m_0091e260

// @f3 0x00904410 (community match, verified in this file)
extern float FUN_00de6e70;
namespace f3m_00904410 {

struct __declspec(align(16)) Loc {
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
    float unk80;
    void FUN_0098ab20(int a, int b, int c, int d, int e, int f, int g, int h, int i);
};

struct Sub {
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
};

struct Stub {
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
    Sub* unk6c;
    int unk70;
    void FUN_00904410(int a1, int a2, int a3, int a4);
};

// pdb: hkpWorld::linearCast | hkpWorld.obj | tesv_win, uvref, medium
void Stub::FUN_00904410(int a1, int a2, int a3, int a4)
{
    Loc loc;
    int t = this->unk70;
    loc.unk00 = 0xe34bb8;
    loc.unk80 = FUN_00de6e70;
    int p = t ? t + 8 : 0;
    Sub* s = this->unk6c;
    loc.FUN_0098ab20(this->unk54, a1, a2, p, (int)s, s->unk6c, 0, a3, a4);
}
}   // namespace f3m_00904410

// @f3 0x0090a540 (community match, verified in this file)
namespace f3m_0090a540 {
struct __declspec(align(16)) Local0090a540
{
    int m_data[12];
    void FUN_009649c0(int value);
};

struct Obj0090a540
{
    void FUN_0090a3a0(float* valuePointer, float value, int count);
    void FUN_0090a540(int first, float value, int count);
};

void Obj0090a540::FUN_0090a540(int first, float value, int count)
{
    Local0090a540 local;
    local.FUN_009649c0(first);
    FUN_0090a3a0((float*)local.m_data, value, count);
}
}   // namespace f3m_0090a540

// @f3 0x0090a360 (community match, verified in this file)
namespace f3m_0090a360 {
struct Math360Local
{
    __declspec(align(16)) int unk00;
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
    void FUN_009649c0(int a);
};

struct Outer360
{
    void FUN_0090a1f0(Math360Local& r, int b, int c, int d, int e);
    void FUN_0090a360(int a, int b, int c, int d, int e);
};

void Outer360::FUN_0090a360(int a, int b, int c, int d, int e)
{
    Math360Local local;
    local.FUN_009649c0(a);
    FUN_0090a1f0(local, b, c, d, e);
}
}   // namespace f3m_0090a360

// @f3 0x0090ef10 (community match, verified in this file)
namespace f3m_0090ef10 {
namespace workerB90ef10 {

struct Source;

struct Context{
__declspec(align(16)) int unk00;
int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
int value;
int unk24;
Source* source;
int unk2c;
int unk30,unk34,unk38,unk3c;

}
;

struct Object{
virtual void s0();
virtual void s1();
virtual void s2();
virtual void s3();
virtual void s4();
virtual void s5();
virtual int Act(Context*);

}
;

struct Inner{
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
Object* object;

}
;

struct Node{
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
Inner* inner;

}
;

struct Source{
int unk00,unk04;
Node* data;
int unk0c;
signed char index;

}
;

int __stdcall FUN_0090ef10(int value,Source* src,int unused){
Context c;
c.value=value;
c.source=src;
Node* node=*(Node**)((char*)src+8+src->index);
Inner* inner=node?node->inner:0;
return inner->object->Act(&c);

}


}


}   // namespace f3m_0090ef10

// @f3 0x0091da10 (community match, verified in this file)
extern double DAT_00dbe7c0;
extern int DAT_010f3174, DAT_010f3258, DAT_010f3264;
namespace f3m_0091da10 {
namespace trial_0091da10 {
struct Vec {float x,y,z;};
struct __declspec(align(16)) align16 { float x,y,z,w; };
struct Base { Base(); virtual ~Base(); int a,b,c,d; };
struct L1:Base { L1():Base(){c=0; d=0; ++DAT_010f3174;} virtual ~L1(); };
struct L2:L1 { L2():L1(){++DAT_010f3258;} virtual ~L2(); };
struct L3:L2 { L3():L2(){++DAT_010f3264;} virtual ~L3(); };
struct Obj:L3 { Obj(const Vec&,const Vec&,float); virtual ~Obj(); void FUN_0091d450(align16*,align16*,float); };
// pdb: bhkCapsuleShape::bhkCapsuleShape | bhkCapsuleShape.obj | fnv360_0721_beta, objrun, medium
// pdb params: arVA, arVB, afRad
Obj::Obj(const Vec& a,const Vec& b,float r) { align16 aa,bb; aa.x=a.x*DAT_00dbe7c0;aa.y=a.y*DAT_00dbe7c0;aa.z=a.z*DAT_00dbe7c0;bb.x=b.x*DAT_00dbe7c0;bb.y=b.y*DAT_00dbe7c0;bb.z=b.z*DAT_00dbe7c0;FUN_0091d450(&aa,&bb,r*DAT_00dbe7c0); }
}
}   // namespace f3m_0091da10

// @f3 0x00909aa0 (community match, verified in this file)
namespace f3m_00909aa0 {
struct FUN_00909aa0_LocalData {
    int unk00;
    int unk04;
    float unk08;

    void __thiscall hkVector4_setTransformedPos(int arg1, int arg2);
};

struct FUN_00909aa0_Object {
    void __thiscall FUN_009099a0(FUN_00909aa0_LocalData* localData,
                                 float arg3,
                                 int arg4,
                                 int arg5);

    void __thiscall FUN_00909aa0(int arg1, int arg2, float arg3, int arg4, int arg5);
};

// pdb: hkDebugDisplay::displayStarModelSpace | hkDebugDisplay.obj | fnv360_0822_retail, caller_sim, low
// pdb params: worldFromModel, position, scale, color, id, tag
void __thiscall FUN_00909aa0_Object::FUN_00909aa0(int arg1,
                                                  int arg2,
                                                  float arg3,
                                                  int arg4,
                                                  int arg5) {
    __declspec(align(16)) FUN_00909aa0_LocalData localData;

    localData.hkVector4_setTransformedPos(arg1, arg2);

    FUN_009099a0(&localData, arg3, arg4, arg5);
}
}   // namespace f3m_00909aa0

// @f3 0x00902510 (community match, verified in this file)
namespace f3m_00902510 {
struct C902510 {
    int pad00[0x15];
    void* unk54;
    int pad58[0x6];
    void* unk70;
    void FUN_00902510(void* a, void* b);
};

__declspec(align(16)) struct hkpWorldRayCaster {
    void* vt;
    int p04, p08, p0c, p10, p14, p18, p1c, p20, p24, p28, p2c;
    int p30, p34, p38, p3c;
    int unk40;
    int unk44;
    int p48;
    int p4c;
    void ctor(void* a1, void* a2, void* a3, int a4, void* a5);
};

void C902510::FUN_00902510(void* a, void* b)
{
    hkpWorldRayCaster rc;
    rc.unk40 = 0;
    rc.unk44 = 0;
    rc.vt = (void*)0xe320fc;
    rc.ctor(unk54, a, unk70, 0, b);
}
}   // namespace f3m_00902510

// @f3 0x00909560 (community match, verified in this file)
namespace f3m_00909560 {
struct FUN_00909560_ArrayObject
{
    virtual void vslot0();
    virtual void vslot1();
    virtual void vslot2();
    virtual void vslot3();
    virtual void vslot4();
    virtual void vslot5();
    virtual void vslot6();
    virtual void vslot7();
    virtual void vslot8(void* first, float* sum, void* third, void* fourth);
};

struct FUN_00909560_Class
{
    char pad00[8];
    FUN_00909560_ArrayObject** m_08;
    int m_0c;
    void FUN_00909560(void* first, void* second, void* third, void* fourth);
};

void FUN_00909560_Class::FUN_00909560(void* first, void* second, void* third, void* fourth)
{
    float* a = (float*)first;
    float* b = (float*)second;
    __declspec(align(16)) float sum[4];
    sum[0] = a[0] + b[0];
    sum[1] = a[1] + b[1];
    sum[2] = a[2] + b[2];
    sum[3] = a[3] + b[3];

    for (int index = 0; index < m_0c; ++index)
    {
        FUN_00909560_ArrayObject* object = m_08[index];
        object->vslot8(first, sum, third, fourth);
    }
}
}   // namespace f3m_00909560

// @f3 0x0091e120 (community match, verified in this file)
#include <math.h>
namespace f3m_0091e120 {
struct Vec4E { float x, y, z, w;
    float Dot(const Vec4E& o) const { return y * o.y + o.x * x + z * o.z; }
};
struct ElemE {
    Vec4E v;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    void FUN_008e9460(ElemE* src);
};
struct ArrayE { ElemE* data; int count; int capFlags; };
struct W4 { ArrayE* p; };
void __cdecl FUN_00901f10(ArrayE* arr, int size);
// pdb: addMaxSlopePlane | hkpCharacterProxy.obj | fnv360_0822_retail, call_gap, low
static __declspec(noinline) bool FUN_0091e120(int index, Vec4E* vec, float value, W4 arr)
{
    ArrayE* a = arr.p;
    float dot = a->data[index].v.Dot(*vec);
    if (!(dot > 0.01f) || !(value > dot)) return false;
    if (a->count == (a->capFlags & 0x3fffffff)) FUN_00901f10(a, 64);
    ElemE& e = a->data[a->count];
    a->count = a->count + 1;
    e.FUN_008e9460(&a->data[index]);
    ElemE* dst = &e;
    dot = -dot;
    dst->v.x += dot * vec->x; dst->v.y += dot * vec->y; dst->v.z += dot * vec->z; dst->v.w += dot * vec->w;
    float lenSq = dst->v.x*dst->v.x + dst->v.y*dst->v.y + dst->v.z*dst->v.z;
    float inv;
    if (lenSq) inv = 1.0f / sqrtf(lenSq); else inv = 0.0f;
    e.v.x *= inv; e.v.y *= inv; e.v.z *= inv; e.v.w *= inv;
    return true;
}
volatile int g_in; volatile int g_out;
void caller_stub() { g_out = FUN_0091e120(g_in, (Vec4E*)g_in, (float)g_in, *(W4*)g_in) ? 1 : 0; }
}   // namespace f3m_0091e120

// @f3 0x009107f0 (community match, verified in this file)
#include <new>
extern const double FUN_00dbe7c0;
namespace f3m_009107f0 {

void FUN_00e35ff4();

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
    Vec4& operator=(float f) { x = y = z = w = f; return *this; }
    void mul4(const Vec4& o) { x = o.x * x; y = o.y * y; z = o.z * z; w = o.w * w; }
};

struct Chunk
{
    int      unk00[8];               // 0x00
    float*   m_verts;                // 0x20
    int      unk24[8];               // 0x24
    unsigned short m_numStrips;      // 0x44
    unsigned short unk46;            // 0x46
    unsigned short* m_pStripIndices; // 0x48
    unsigned short* FUN_008404e0();
};

struct Slot
{
    Chunk* m_pCurrentMemoryChunk;    // 0x00
    int    unk04;                    // 0x04
};

struct Tri
{
    void (*unk00)();        // 0x00
    unsigned short unk04;   // 0x04
    unsigned short unk06;   // 0x06
    int            unk08;   // 0x08
    int            unk0c;   // 0x0c
    float          unk10;   // 0x10
    unsigned short unk14;   // 0x14
    unsigned char  unk16;   // 0x16
    unsigned char  unk17;   // 0x17
    int            unk18;   // 0x18
    int            unk1c;   // 0x1c
    Vec4           m_v0;    // 0x20
    Vec4           m_v1;    // 0x30
    Vec4           m_v2;    // 0x40
    Vec4           m_v3;    // 0x50
    Tri(float radius);
};

Tri::Tri(float radius)
    : unk06(1), unk08(0), unk0c(4), unk10(radius)
{
    unk00 = FUN_00e35ff4;
    unk14 = 0;
    unk16 = 6;
    m_v3 = 0.0f;
    unk17 = 0;
}

struct Shape
{
    int  unk00[0x1c];        // 0x00
    Vec4 m_vScale;           // 0x70
    float m_fSphereRadius;   // 0x80
    int  unk84;              // 0x84
    Slot* m_pSlots;          // 0x88
    Tri* FUN_009107f0(unsigned int key, Tri* out);
};

Tri* Shape::FUN_009107f0(unsigned int key, Tri* out)
{
    Chunk* chunk = m_pSlots[key >> 20].m_pCurrentMemoryChunk;
    unsigned short numStrips = chunk->m_numStrips;
    unsigned short* idx = chunk->FUN_008404e0();
    unsigned short* lengths = chunk->m_pStripIndices;
    float* verts = chunk->m_verts;
    unsigned short s = 0;
    unsigned int t = key & 0xfffff;
    for (; s < numStrips; s++)
    {
        if (t < (unsigned int)(lengths[s] - 2))
            break;
        t -= lengths[s] - 2;
        idx += lengths[s];
    }
    unsigned short* p = &idx[t];
    unsigned short i0 = *p;
    unsigned short i1 = *++p;
    unsigned short i2 = *++p;
    if (i0 == i1 || i0 == i2 || i1 == i2)
        return 0;
    const float* a = &verts[i0 * 3];
    const float* b = &verts[i1 * 3];
    const float* c = &verts[i2 * 3];
    Tri* tri = out ? new (out) Tri(m_fSphereRadius) : 0;
    Vec4 v;
    v.x = a[0] * FUN_00dbe7c0;
    const double k = FUN_00dbe7c0;
    v.y = a[1] * k;
    v.z = a[2] * k;
    v.mul4(m_vScale);
    tri->m_v0 = v;
    v.x = b[0] * k;
    v.y = b[1] * k;
    v.z = b[2] * k;
    v.mul4(m_vScale);
    tri->m_v1 = v;
    v.x = c[0] * k;
    v.y = c[1] * k;
    v.z = c[2] * k;
    v.mul4(m_vScale);
    tri->m_v2 = v;
    return tri;
}
}   // namespace f3m_009107f0

// @f3 0x00918520 (community match, verified in this file)
#include <windows.h>
extern unsigned long DAT_010f3170;
namespace f3m_00918520 {
namespace f3m_00918520 {
struct FreeList {
    void* head;
    int numElem;
    __forceinline void put(void* p) {
        numElem++;
        *(void**)p = head;
        head = p;
    }
};
struct Manager {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34;
    FreeList freeList[5];
    void FUN_008f6f90(void* p);
    void FUN_008f6890(int kind, void* p, int tag);
};
__forceinline Manager* Mgr() { return (Manager*)TlsGetValue(DAT_010f3170); }
__forceinline void Free(void* p) { Manager* m = Mgr(); m->FUN_008f6f90(p); }
__forceinline void PutRow(int row, void* p) {
    Manager* m = Mgr();
    if (m->freeList[row].numElem >= m->unk34)
        m->FUN_008f6890(row, p, 0x3b);
    else
        m->freeList[row].put(p);
}
struct Entry { void* unk00; };
struct Data {
    void* unk00;
    void* unk04;
    int unk08;
    Entry** unk0c;
    int unk10;
    void* unk14;
};
struct RefObj {
    virtual ~RefObj();
    unsigned short unk04;
    short unk06;
    __forceinline void Release() {
        if (unk04 != 0) {
            if ((unsigned short)--unk06 == 0)
                delete this;
        }
    }
};
struct Obj0c { virtual ~Obj0c(); };
struct Member14 { int unk00; ~Member14(); };
struct FUN_00918520 {
    int unk00;
    RefObj* unk04;
    Data* unk08;
    Obj0c* unk0c;
    RefObj* unk10;
    Member14 unk14;
    ~FUN_00918520();
};
// pdb: bhkRagdollPenetrationUtil::ConstrainedSystem::~ConstrainedSystem | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00918520::~FUN_00918520()
{
    if (unk08) {
        int n = unk08->unk10;
        void* p = unk08->unk04;
        Free(p);
        for (int i = 0; i < n; i++) {
            Entry* e = unk08->unk0c[i];
            void* q = e->unk00;
            if (q)
                Free(q);
            PutRow(1, e);
        }
        void* a = unk08->unk0c;
        Free(a);
        void* b = unk08->unk14;
        Free(b);
        Data* d = unk08;
        if (d) {
            PutRow(4, d);
        }
    }
    if (unk04)
        unk04->Release();
    if (unk10)
        unk10->Release();
    if (unk0c)
        delete unk0c;
}
}
}   // namespace f3m_00918520

// @f3 0x00910080 (community match, verified in this file)
namespace f3m_00910080 {
namespace f3m_00910080 {

struct Matrix;
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void hkVector4_setTransformedPos(const Matrix& m, const Vec4& v);
};
struct __declspec(align(16)) Matrix { float m[16]; };
struct Bounds { Vec4 min; Vec4 max; };
struct Vtx { float x, y, z; };

struct Flag {
    char set;
};

struct Sub {
    Flag FUN_00924fe0(const Matrix& m, float f);
    Vec4 unk00;
    Vec4 unk10;
    Vec4 unk20;
    Vec4 unk30;
};

struct Strip {
    int unk00;
    int unk04;
    unsigned short count;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vtx* verts;
};

struct StripRef {
    Strip* strip;
    int unk04;
};

struct Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Sub sub;
    Bounds cached;
    Vec4 scale;
    float radius;
    int unk94;
    StripRef* strips;
    int unk9c;
    unsigned int stripCount;
    void FUN_00910080(const Matrix& m, float extra, Bounds* out);
};

void Shape::FUN_00910080(const Matrix& m, float extra, Bounds* box)
{
    Bounds* out = box;
    if (cached.min.x != (double)3.40282002e38f && sub.FUN_00924fe0(m, 0.001f).set != 0) {
        out->min.x = cached.min.x;
        out->min.y = cached.min.y;
        out->min.z = cached.min.z;
        out->min.w = cached.min.w;
        out->max.x = cached.max.x;
        out->max.y = cached.max.y;
        out->max.z = cached.max.z;
        out->max.w = cached.max.w;
    } else {
        out->min.z = out->min.y = out->min.x = 3.40282002e38f;
        out->min.w = 0.0f;
        out->max.z = out->max.y = out->max.x = -3.40282002e38f;
        out->max.w = 0.0f;
        unsigned int n = stripCount;
        for (unsigned int i = 0; i < n; i++) {
            Strip* s = strips[i].strip;
            Vtx* p = s->verts;
            unsigned int cnt = s->count;
            for (unsigned int j = 0; j < cnt; j++) {
                Vec4 v;
                Vec4 r;
                v.x = p[j].x * (double)0.142876729f;
                v.y = p[j].y * (double)0.142876729f;
                v.z = p[j].z * (double)0.142876729f;
                v.x = v.x * scale.x;
                v.y = v.y * scale.y;
                v.z = v.z * scale.z;
                v.w = v.w * scale.w;
                r.hkVector4_setTransformedPos(m, v);
                out->min.x = out->min.x < r.x ? out->min.x : r.x;
                out->min.y = out->min.y < r.y ? out->min.y : r.y;
                out->min.z = out->min.z < r.z ? out->min.z : r.z;
                out->min.w = out->min.w < r.w ? out->min.w : r.w;
                out->max.x = out->max.x > r.x ? out->max.x : r.x;
                out->max.y = out->max.y > r.y ? out->max.y : r.y;
                out->max.z = out->max.z > r.z ? out->max.z : r.z;
                out->max.w = out->max.w > r.w ? out->max.w : r.w;
            }
        }
    }
    float t = radius + extra;
    out->min.x = out->min.x - t;
    out->min.y = out->min.y - t;
    out->min.z = out->min.z - t;
    out->min.w = out->min.w - t;
    out->max.x = out->max.x + t;
    out->max.y = out->max.y + t;
    out->max.z = out->max.z + t;
    out->max.w = out->max.w + t;
}

}
}   // namespace f3m_00910080

// @f3 0x009167d0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e36544[], DAT_00e32798[];
extern const float FUN_00e36470;
extern const float FUN_00e36488;
namespace f3m_009167d0 {
namespace S009167d0_box {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

struct TimerCommand { const char* name; unsigned int ticks; unsigned int extra; };
struct MonitorStream { unsigned int unk00; TimerCommand* end; unsigned int unk08; TimerCommand* capacity; };

__forceinline void TimerMark(const char* name)
{
    MonitorStream* stream = static_cast<MonitorStream*>(FUN_00d9b080(DAT_0116913c));
    TimerCommand* h = stream->end;
    if (h < stream->capacity) {
        h->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->ticks = ticks;
        stream->end = h + 1;
    }
}

struct S009167d0_Bool {
    char m_bool;
    S009167d0_Bool() {}
    S009167d0_Bool(bool b) { m_bool = (char)b; }
};

struct __declspec(align(16)) S009167d0_Vec4 {
    float x, y, z, w;
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
    void setAll(float a) { x = a; y = a; z = a; w = a; }
    void add4(const S009167d0_Vec4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    void setNeg4(const S009167d0_Vec4& a) { x = -a.x; y = -a.y; z = -a.z; w = -a.w; }
    void setZero4() { x = y = z = w = 0.0f; }
};

struct S009167d0_Input { S009167d0_Vec4 from; S009167d0_Vec4 to; };
struct S009167d0_Output {
    S009167d0_Vec4 normal;
    float hitFraction;
    int extraInfo;
    int unk18;
    int unk1c;
    int shapeKeys[8];
    int shapeKeyIndex;
};

struct S009167d0_BoxShape {
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    float radius;
    int unk14;
    int unk18;
    int unk1c;
    S009167d0_Vec4 halfExtents;
    S009167d0_Bool hkpBoxShape_castRayImpl(const S009167d0_Input& input, S009167d0_Output& results) const;
};

// pdb: hkpBoxShape::castRayImpl | hkpBoxShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
S009167d0_Bool S009167d0_BoxShape::hkpBoxShape_castRayImpl(const S009167d0_Input& input, S009167d0_Output& results) const
{
    TimerMark(DAT_00e36544);

    S009167d0_Vec4 maxExt;
    maxExt.setAll(radius);
    maxExt.add4(halfExtents);
    S009167d0_Vec4 minExt;
    minExt.setNeg4(maxExt);

    int hiA = ((input.from.x >= maxExt.x ? 8 : 0) | (input.from.y >= maxExt.y ? 4 : 0) | (input.from.z >= maxExt.z ? 2 : 0) | (input.from.w >= maxExt.w ? 1 : 0)) & 0xe;
    int loA = ((input.from.x <= minExt.x ? 8 : 0) | (input.from.y <= minExt.y ? 4 : 0) | (input.from.z <= minExt.z ? 2 : 0) | (input.from.w <= minExt.w ? 1 : 0)) & 0xe;
    int hiB = ((input.to.x >= maxExt.x ? 8 : 0) | (input.to.y >= maxExt.y ? 4 : 0) | (input.to.z >= maxExt.z ? 2 : 0) | (input.to.w >= maxExt.w ? 1 : 0)) & 0xe;
    int loB = ((input.to.x <= minExt.x ? 8 : 0) | (input.to.y <= minExt.y ? 4 : 0) | (input.to.z <= minExt.z ? 2 : 0) | (input.to.w <= minExt.w ? 1 : 0)) & 0xe;

    if ((hiA & hiB) || (loA & loB) || !(loA | hiA)) {
        TimerMark(DAT_00e32798);
        return false;
    }

    float tEnter = 0.0f;
    float tExit = results.hitFraction;
    int masks[3] = { 8, 4, 2 };
    S009167d0_Vec4 normal;

    int both = hiA | hiB;
    int outside = hiA;
    float sign = FUN_00e36470;
    for (int pass = 1; pass >= 0; pass--) {
        for (int i = 2; i >= 0; i--) {
            int m = masks[i];
            if (both & m) {
                float d = minExt(i);
                float distA = sign * input.from(i) + d;
                float distB = d + sign * input.to(i);
                float t = distA / (distA - distB);
                if (outside & m) {
                    if (t >= tEnter) {
                        tEnter = t;
                        normal.setZero4();
                        normal(i) = sign;
                    }
                } else {
                    if (!(t > tExit)) {
                        tExit = t;
                    }
                }
                if (tExit < tEnter) {
                    TimerMark(DAT_00e32798);
                    return false;
                }
            }
        }
        both = loA | loB;
        outside = loA;
        sign = FUN_00e36488;
    }

    results.normal.x = normal.x;
    results.normal.y = normal.y;
    results.normal.z = normal.z;
    results.normal.w = normal.w;
    results.hitFraction = tEnter;
    results.shapeKeys[results.shapeKeyIndex] = -1;
    TimerMark(DAT_00e32798);
    return true;
}
}
}   // namespace f3m_009167d0

// @f3 0x0090c830 (community match, verified in this file)
#include <math.h>
extern const char DAT_010f3370[];
namespace f3m_0090c830 {
namespace f3m_0090c830 {
struct __declspec(align(16)) V4c {
    float x, y, z, w;
};
struct AabbC { V4c m_min; V4c m_max; };
struct ShapeC {
    virtual void s00() throw(); virtual void s04() throw(); virtual void s08() throw(); virtual void s0c() throw();
    virtual void s10() throw(); virtual void s14() throw(); virtual void s18() throw();
    virtual void getAabb(const void* transform, float tolerance, AabbC& out) const throw();
};

struct BodyC {
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
    V4c m_center;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    float m_radius;
    void hkpRigidBody_updateCachedShapeInfo(const ShapeC* shape, V4c& extents) throw();
};

// pdb: hkpRigidBody::updateCachedShapeInfo | hkpRigidBody.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap) + skyrim(call_seq), high
void BodyC::hkpRigidBody_updateCachedShapeInfo(const ShapeC* shape, V4c& extents) throw()
{
    AabbC aabb;
    shape->getAabb(DAT_010f3370, 0.0f, aabb);
    float ex = aabb.m_max.x - aabb.m_min.x;
    extents.x = ex;
    float ey = aabb.m_max.y - aabb.m_min.y;
    extents.y = ey;
    float ez = aabb.m_max.z - aabb.m_min.z;
    extents.z = ez;
    extents.w = aabb.m_max.w - aabb.m_min.w;
    V4c c;
    c.x = aabb.m_min.x + aabb.m_max.x;
    c.y = aabb.m_min.y + aabb.m_max.y;
    c.z = aabb.m_min.z + aabb.m_max.z;
    c.x = c.x * 0.5;
    c.y = c.y * 0.5;
    c.z = c.z * 0.5;
    V4c d;
    d.x = c.x - m_center.x;
    d.y = c.y - m_center.y;
    d.z = c.z - m_center.z;
    float r = sqrtf(ex * ex + ey * ey + ez * ez);
    float half = r * 0.5;
    float l = sqrtf((double)d.x * d.x + (double)d.y * d.y + (double)d.z * d.z);
    m_radius = l + half;
}
}
}   // namespace f3m_0090c830

// @f3 0x009118d0 (community match, verified in this file)
namespace f3m_009118d0 {


void* NiMemAlloc(unsigned int);
void NiFree(void*);
char* FUN_00a5b690(const char*);
extern char* EmptyFS;
extern "C" int DAT_00e2085c;
extern const char g_01202558_arg0[];
struct MemoryManager_t { void* FUN_0086b930(unsigned); };
extern "C" MemoryManager_t DAT_01090a78;
struct LocalFixed {
 char* p;
 LocalFixed(const char* s):p(FUN_00a5b690(s)){}
 ~LocalFixed(){if(p!=EmptyFS) InterlockedDecrement((volatile long*)(p-8));}
};
struct S00ca5da0_Pt
{
    float x, y, z;
    S00ca5da0_Pt() {}
    S00ca5da0_Pt(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
class FUN_00a7b630;
void FUN_00c84cd0(int, void*);
struct FUN_00a74480;
extern "C" void (__cdecl* DAT_010f2c24)(FUN_00a74480*);
struct S00ca5da0_ArrayAllocation
{
    static __forceinline void* operator new[](unsigned int size)
    {
        return ((MemoryManager_t*)&DAT_01090a78)->FUN_0086b930(size);
    }
    static __forceinline void operator delete[](void*)
    {}
};

struct S00ca5da0_Vec3 : S00ca5da0_ArrayAllocation
{
    float x, y, z;
    S00ca5da0_Vec3() {}
    S00ca5da0_Vec3(const S00ca5da0_Vec3& o) : x(o.x), y(o.y), z(o.z) {}
};
struct __declspec(align(16)) S00ca5da0_V4
{
    float x, y, z, w;
    S00ca5da0_V4(const S00ca5da0_Vec3& o) : x(o.x), y(o.y), z(o.z) {}
};
struct S00ca5da0_Index : S00ca5da0_ArrayAllocation
{
    unsigned short value;
};

struct S00ca5da0_Entry
{
    unsigned short f0;
    unsigned short f1;
    unsigned short f2;
    unsigned short f6;
};

struct S00ca5da0_Part
{
    int unk00;
    unsigned int count;
    int unk08;
};

struct S00ca5da0_Geom
{
    int unk00;
    int unk04;
    unsigned int m_08;
    int unk0c;
    unsigned short m_10;
    unsigned short unk12;
    S00ca5da0_Entry* m_14;
    S00ca5da0_Vec3* m_18;
    int unk1c;
    int unk20;
    S00ca5da0_Part* m_24;
};

struct S00ca5da0_Data
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
    struct S00ca5da0_Geom* m_84;
};

struct S00ca5da0_Arr
{
    void* m_vtbl;
    unsigned short* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __declspec(noalias) void FUN_008243d0(unsigned int size);
    __forceinline S00ca5da0_Arr(unsigned int maxSize = 0, unsigned int growBy = 1)
    {

        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_vtbl = &DAT_00e2085c;
    }
    __forceinline ~S00ca5da0_Arr()
    {
        NiFree(m_pBase);
    }
    __forceinline void SetAt(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usSize)
        {
            m_usSize = (unsigned short)(idx + 1);
            if (v != 0)
                m_usESize++;
        }
        else
        {
            if (v != 0)
            {
                if (m_pBase[idx] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[idx] != 0)
                    m_usESize--;
            }
        }
        m_pBase[idx] = v;
    }
    __forceinline unsigned int SetAtGrow(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usMaxSize)
            FUN_008243d0(idx + m_usGrowBy);
        SetAt(idx, v);
        return idx;
    }
    __forceinline unsigned int Add(const unsigned short& v)
    {
        return SetAtGrow(m_usSize, v);
    }
    __forceinline void RemoveAll()
    {
        for (unsigned short q = 0; q < m_usSize; q++)
            m_pBase[q] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

struct FUN_00a7b690
{
    static void* operator new(unsigned int size)
    {
        return NiMemAlloc(size);
    }
    static void operator delete(void* p)
    {
        NiFree(p);
    }
    FUN_00a7b690();
    void FUN_00830e70(unsigned short count, S00ca5da0_Vec3* verts, int a, int b, int c, int d, int e);
    void FUN_00845e00(unsigned short count, unsigned short* tris);
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
};

struct S00ca5da0_Prop
{
    static void* operator new(unsigned int size)
    {
        return NiMemAlloc(size);
    }
    static void operator delete(void* p)
    {
        NiFree(p);
    }
    S00ca5da0_Prop();
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

    S00ca5da0_Pt m_28;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;

    int m_44;
    int unk48;
};

struct FUN_00a74480
{
    static void* operator new(unsigned int size)
    {
        return NiMemAlloc(size);
    }
    static void operator delete(void* p)
    {
        NiFree(p);
    }
    FUN_00a74480(FUN_00a7b630* mesh);
    void FUN_008245d0(const LocalFixed& name);
    S00ca5da0_Prop* FUN_00826590(unsigned);
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

    float m_64;
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
};


struct S00ca5da0_Node
{
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
    virtual void AttachChildInAvailableSlot(FUN_00a74480* child, int one);
};

struct S00ca5da0_Builder
{
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
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void Apply(FUN_00a74480*);
    int unk04;
    S00ca5da0_Data* m_08;
    float FUN_009111a0();
    void FUN_009118d0(S00ca5da0_Node* parent);
};
// pdb: bhkPackedNiTriStripsShape::BuildDisplayGeometry | bhkPackedNiTriStripsShape.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: apNode, arDefColor
void S00ca5da0_Builder::FUN_009118d0(S00ca5da0_Node* parent)
{
    S00ca5da0_Geom* geom = (this ? m_08 : 0)->m_84;
    S00ca5da0_Arr arr;
    unsigned short base = 0;
    unsigned short flag;
    unsigned short c;
    unsigned short prevJ = 0;
    unsigned short a;
    unsigned short j = 0;
    unsigned short b;
    for (int i = 0; i < geom->m_10; i++)
    {
        a = 0;
        b = 0;
        c = 0;
        flag = 0;
        do
        {
            S00ca5da0_Entry* e = &geom->m_14[j];
            if (flag == 0)
            {
                a = e->f0;
                b = e->f1;
                c = e->f2;
                if (a >= base + geom->m_24[i].count)
                    break;
                arr.Add((unsigned short)(a - base));
                arr.Add((unsigned short)(b - base));
                arr.Add((unsigned short)(c - base));
                j++;
                flag = 1;
            }
            else if (b == e->f0 && c == e->f1)
            {
                a = b;
                b = c;
                c = e->f2;
                arr.Add((unsigned short)(a - base));
                arr.Add((unsigned short)(b - base));
                arr.Add((unsigned short)(c - base));
                flag++;
                j++;
            }
            else
            {
                flag = 0;
            }
        } while (a < base + geom->m_24[i].count && j < geom->m_08);

        FUN_00a7b690* mesh = new FUN_00a7b690;
        unsigned short cnt = (unsigned short)geom->m_24[i].count;
        S00ca5da0_Vec3* verts = new S00ca5da0_Vec3[cnt];
        for (unsigned short k = base; k < base + cnt; k++)
        {
            S00ca5da0_V4 v(geom->m_18[k]);
            S00ca5da0_Vec3* d = &verts[k - base];
            d->x = (float)(v.x * 6.999040126800537);
            d->y = (float)(v.y * 6.999040126800537);
            d->z = (float)(v.z * 6.999040126800537);
        }
        mesh->FUN_00830e70(cnt, verts, 0, 0, 0, 0, 0);
        unsigned short nTri = (unsigned short)(j - prevJ);
        unsigned short* tris = (unsigned short*)new S00ca5da0_Index[nTri * 3];
        unsigned int bytes = arr.m_usSize * sizeof(unsigned short);
        memcpy(tris, arr.m_pBase, bytes);
        mesh->FUN_00845e00(nTri, tris);

        FUN_00a74480* shape = new FUN_00a74480((FUN_00a7b630*)mesh);
        shape->FUN_008245d0(LocalFixed(g_01202558_arg0));
        float f = (float)FUN_009111a0();
        shape->m_64 = (float)fabs(f);
        Apply(shape);
        S00ca5da0_Prop* prop = shape->FUN_00826590(2);
        if(prop) {
            S00ca5da0_Pt point(0.0f, 0.0f, 0.0f);
            FUN_00c84cd0(geom->m_24[i].unk08, &point);
            prop->m_28 = point;
            prop->m_44++;
        }
        arr.RemoveAll();
        parent->AttachChildInAvailableSlot(shape, 1);
        if(DAT_010f2c24) DAT_010f2c24(shape);
        base += cnt;
        prevJ = j;
    }
}
}   // namespace f3m_009118d0

// @f3 0x00907b70 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
namespace f3m_00907b70 {
namespace f3m_00907b70 {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
struct Monitor { int r0; char* cur; int r8; char* end; };
// hkMonitorStream::TimerCommand and TimerBeginListCommand (class and member names: FNV360_PDB)
struct TimerCommand {
    const char* m_commandAndMonitor;
    unsigned int m_time0;
    unsigned int m_time1;
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov ticks, eax } m_time0 = ticks; }
};
struct TimerBeginListCommand : TimerCommand { const char* m_nameOfFirstSplit; };
struct Heap { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };

struct Pair { void* a; char* b; };
struct InplacePairs {
    Pair* data;
    int size;
    int capFlags;
    Pair storage[128];
    __forceinline InplacePairs() throw() { data = storage; size = 0; capFlags = (int)0x80000080; }
    __forceinline ~InplacePairs() throw() {
        if (!(capFlags & 0x80000000)) {
            int cap = capFlags & 0x3fffffff;
            Heap* heap = (Heap*)FUN_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, cap * (int)sizeof(Pair), 0x17);
        }
    }
};
struct __declspec(align(16)) Aabb { float v[8]; };
struct Shape {
    virtual void s00() throw(); virtual void s04() throw(); virtual void s08() throw(); virtual void s0c() throw();
    virtual void s10() throw(); virtual void s14() throw(); virtual void s18() throw();
    virtual void getAabb(const void* transform, float tolerance, Aabb& out) const throw();
    int r04, r08;
    int type;
};
struct Collidable { Shape* shape; int r04; const void* transform; };
struct Input;
struct Collector;
typedef void (__cdecl* ClosestFunc)(const Collidable* a, const Collidable* b, const Input* in, Collector* c);
struct AgentFuncs { ClosestFunc getClosestPoints; void* f1; void* f2; void* f3; void* f4; };
struct Dispatcher {
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
    unsigned char agent2Types[32][32];
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    AgentFuncs agent2Func[1];
};
struct Input { Dispatcher* dispatcher; float tolerance; };
struct HkBool { char v; };
struct FilterBase0 { virtual void b00() throw(); int r04; };
struct FilterCC {
    virtual void s00() throw();
    virtual HkBool isCollisionEnabled(const Collidable* a, const Collidable* b) const throw();
};
struct Filter : FilterBase0, FilterCC {};
struct BroadPhase {
    virtual void s00() throw(); virtual void s04() throw(); virtual void s08() throw(); virtual void s0c() throw();
    virtual void s10() throw(); virtual void s14() throw(); virtual void s18() throw(); virtual void s1c() throw();
    virtual void s20() throw(); virtual void s24() throw(); virtual void s28() throw(); virtual void s2c() throw();
    virtual void s30() throw(); virtual void s34() throw(); virtual void s38() throw(); virtual void s3c() throw();
    virtual void querySingleAabb(const Aabb& aabb, InplacePairs& out) const throw();
};
struct CInput { int r0; float tolerance; };
struct World {
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
    BroadPhase* broadPhase;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    CInput* collisionInput;
    Filter* filter;
    void FUN_00907b70(const Collidable* collA, const Input* input, Collector* collector) throw();
};

// pdb: hkpWorld::shiftBroadPhase | hkpWorld.obj | tesv_win, objrun, medium
void World::FUN_00907b70(const Collidable* collA, const Input* input, Collector* collector) throw()
{
    {
        Monitor* m = (Monitor*)FUN_00d9b080(DAT_0116913c);
        char* p = m->cur;
        if (p < m->end) {
            TimerBeginListCommand* h = (TimerBeginListCommand*)p;
            h->m_commandAndMonitor = "LthkpWorld::getClosestPoints";
            h->m_nameOfFirstSplit = "Stbroadphase";
            h->setTime();
            m->cur = (char*)(h + 1);
        }
    }
    Aabb aabb;
    collA->shape->getAabb(collA->transform, input->tolerance - collisionInput->tolerance * 0.5, aabb);
    InplacePairs hits;
    broadPhase->querySingleAabb(aabb, hits);
    Pair* pairs = hits.data;
    int typeA = collA->shape->type;
    {
        Monitor* m = (Monitor*)FUN_00d9b080(DAT_0116913c);
        char* p = m->cur;
        if (p < m->end) {
            TimerCommand* h = (TimerCommand*)p;
            h->m_commandAndMonitor = "Stnarrowphase";
            h->setTime();
            m->cur = (char*)(h + 1);
        }
    }
    for (int i = hits.size - 1; i >= 0; pairs++, i--) {
        char* h = pairs->b;
        const Collidable* collB = (const Collidable*)(h + h[5]);
        if (collA == collB)
            continue;
        if (!filter->isCollisionEnabled(collA, collB).v)
            continue;
        const Shape* shapeB = collB->shape;
        if (!shapeB)
            continue;
        Dispatcher* d = input->dispatcher;
        d->agent2Func[d->agent2Types[typeA][shapeB->type]].getClosestPoints(collA, collB, input, collector);
    }
    {
        Monitor* m = (Monitor*)FUN_00d9b080(DAT_0116913c);
        char* p = m->cur;
        if (p < m->end) {
            TimerCommand* h = (TimerCommand*)p;
            h->m_commandAndMonitor = "lt";
            h->setTime();
            m->cur = (char*)(h + 1);
        }
    }
}
}
}   // namespace f3m_00907b70

// @f3 0x0091d3f0 (community match, verified in this file)
namespace f3m_0091d3f0 {
// Model of FUN_0091d3f0 (81 bytes), second revision: v1 already hit EQUAL extents (81 vs 81) with 30 differing lines, and every one of them came from a single structural choice - I wrote the
// memo hit as an early return, so VC8 emitted the fast path INLINE ('je' over it into the main work), while their build tests the same field with 'jne L_0043', jumping FORWARD to a tail block
// that holds only '*out = 0' plus its own epilogue copy ✓✓ That is what an if/else whose cold arm is the ELSE produces, with one shared return at the end ✓✓ Everything else - the heap call on
// the pack's own 'extern Heap7 DAT_01090a78;' declaration (an instance, hence 'mov ecx, offset ...'), the allocate-48-bytes / getter-or-zero if/else with 'jmp' over the 'xor eax,eax', the
// store into +0x0C before the branch on +0x08, the member call FUN_0091D050, and returning this->cache0C read back from memory - matched modulo label numbering ✓✓

namespace f3m_0091d3f0b {

struct ValueHolder91 {                               // the freshly allocated 48-byte block; only its value getter is used ✓✓
    unsigned int FUN_0059fd90();                     // ORIG: mov ecx,eax ; call sub_59FD90 with no stack cleanup afterwards - a true member call ✓✓
};

struct Owner91 {                                     // 'this' (ESI) ✓✓
    char pad08[0x08];
    unsigned long field08;                           // +0x08: decides whether the value is also pushed through FUN_0091D050 ✓✓
    unsigned long cache0C;                           // +0x0C: memoised value, tested on entry, written once, read back for both return paths ✓✓

    void FUN_0091d050(unsigned long value);          // ORIG: push eax ; mov ecx,esi ; call sub_91D050 ✓✓

    unsigned int FUN_0091d3f0(unsigned char* outFlag);   // thiscall with one stack parameter (retn 4) ✓✓
};

// pdb: bhkCapsuleShape::CreateCinfo | bhkCapsuleShape.obj | fnv360_0822_retail, objrun, low
// pdb params: arCreated
unsigned int Owner91::FUN_0091d3f0(unsigned char* outFlag) {
    if (this->cache0C == 0) {                        // ORIG: cmp dword ptr [esi+0Ch],0 ; jne L_0043 - the cold arm is the ELSE and lives in a tail block ✓✓
        void* block = DAT_01090a78.FUN_0086b930(0x30);   // ORIG: push 30h ; mov ecx, offset unk_1090A78 ; call sub_86B930 - the pack's heap declaration supplies the receiver ✓✓

        unsigned int value;
        if (block != 0)                              // ORIG: test eax,eax ; je +5 ; call ; jmp over the else arm holding 'xor eax,eax' ✓✓
            value = ((ValueHolder91*)block)->FUN_0059fd90();   // ORIG: mov ecx,eax ; call sub_59FD90 ✓✓
        else
            value = 0;                               // ORIG: xor eax,eax ✓✓

        this->cache0C = value;                       // ORIG: mov [esi+0Ch],eax - memoised before the second field is used ✓✓
        if (this->field08 != 0)                      // ORIG: cmp dword ptr [esi+8],0 ; jz 0x91D425, scheduled just before that store ✓✓
            this->FUN_0091d050(value);               // ORIG: push eax ; mov ecx,esi ; call sub_91D050 ✓✓

        *outFlag = 1;                                // ORIG: mov byte ptr [eax],1 - a byte store through the out parameter ✓✓
    } else {
        *outFlag = 0;                                // ORIG 0x91D433 block: mov ecx,[esp+arg_0] ; mov byte ptr [ecx],0 ✓✓
    }

    return this->cache0C;                            // ORIG: mov eax,[esi+0Ch] ; pop esi ; retn 4 - read back from memory on both paths ✓✓
}

}
}   // namespace f3m_0091d3f0

// @f3 0x0090eb60 (community match, verified in this file)
extern Heap7 DAT_01090a78;
extern float DAT_00f7a690;
namespace f3m_0090eb60 {
struct Heap7 { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };

struct Fn90eb60Item {
    int unk00;
    float unk04;
};

struct Fn90eb60Owner {
    int unk00;
    int unk04;
    int unk08;
    Fn90eb60Item* unk0C;
    void FUN_0090c4a0(Fn90eb60Item* item);
    Fn90eb60Item* FUN_0090eb60(bool* created);
};

// pdb: bhkSphereShape::Init | bhkSphereShape.obj | fnv360_0822_retail, objrun, low
// pdb params: arInfo
Fn90eb60Item* Fn90eb60Owner::FUN_0090eb60(bool* created) {
    if (unk0C == 0) {
        Fn90eb60Item* item = (Fn90eb60Item*)DAT_01090a78.FUN_0086b930(8);
        if (item) {
            item->unk00 = 0;
            item->unk04 = DAT_00f7a690;
        } else {
            item = 0;
        }
        unk0C = item;
        if (unk08 != 0) {
            FUN_0090c4a0(item);
        }
        *created = true;
    } else {
        *created = false;
    }
    return unk0C;
}
}   // namespace f3m_0090eb60

// @f3 0x0090d620 (community match, verified in this file)
namespace f3m_0090d620 {
// Forwards the caller's argument to the writer interface embedded at +0xd0, then refreshes it.

struct F3Writer_90d620
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
    virtual void v34(void* pArg);
};

struct F3Object_90d620
{
    char pad00[0xd0];
    F3Writer_90d620 writer;
};

extern void FUN_0090d520(void* pObject);

// pdb: hkpRigidBody::setRotation | hkpRigidBody.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
void __fastcall hkpRigidBody_setRotation(F3Object_90d620* pThis, int iUnused, void* pArg)
{
    pThis->writer.v34(pArg);
    FUN_0090d520(pThis);
}
}   // namespace f3m_0090d620

// @f3 0x0091d050 (community match, verified in this file)
namespace f3m_0091d050 {
namespace Export91d050 {
struct Vec4 {float x,y,z,w;};extern Vec4 DAT_01092a50;
struct Data {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;Vec4 first,second;};
struct Output {int unk00,unk04,unk08,unk0c;Vec4 first,second;};
inline void copy(Vec4& out,const Vec4& in){out.x=in.x;out.y=in.y;out.z=in.z;out.w=in.w;}
struct Object {int unk00,unk04;Data* data;void FUN_0090c4a0(Output*);void FUN_0091d050(Output*);};
// pdb: bhkCapsuleShape::bhkCapsuleShape | bhkCapsuleShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkCapsuleShape::CopyCinfo)
void Object::FUN_0091d050(Output* output){FUN_0090c4a0(output);const Vec4* first=this&&data?&data->first:&DAT_01092a50;copy(output->first,*first);const Vec4* second=this&&data?&data->second:&DAT_01092a50;copy(output->second,*second);}
}
}   // namespace f3m_0091d050

// @f3 0x00901e90 (community match, verified in this file)
#include <string.h>
namespace f3m_00901e90 {
namespace Resize901e90 {
struct Heap {void* FUN_008f6d30(int,int);void FUN_008f6d90(void*,int,int);};extern unsigned long DAT_010f3170;extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Array {void* data;int count;unsigned capacity;};
// pdb: hkArrayUtil::_reserve | hkArrayUtil.obj | fnv360_0822_retail, call_seq, medium
// pdb params: mem, array, numElem, sizeElem
void FUN_00901e90(Array* a,int size,int stride){Heap* h=(Heap*)DAT_00d9b080(DAT_010f3170);void* p=h->FUN_008f6d30(size*stride,23);memcpy(p,a->data,a->count*stride);if(!(a->capacity&0x80000000)){int count=a->capacity&0x3fffffff;Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(a->data,count*stride,23);}a->data=p;a->capacity=(a->capacity&0x40000000)|size;}
}

}   // namespace f3m_00901e90

// @f3 0x0090f0a0 (community match, verified in this file)
namespace f3m_0090f0a0 {
namespace c90f0a0 {
void* __cdecl FUN_0089eb90(unsigned int size);

struct FUN_00825800 {
    FUN_00825800();
    virtual ~FUN_00825800();
    int unk04;
};

struct Product : FUN_00825800 {
    int unk08;
    int unk0C;
    short unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Product()
    {
        unk08 = 0;
        unk0C = 0;
        unk10 = 0;
        unk14 = 0;
        unk18 = 0;
        unk20 = 0;
        unk24 = 0;
    }
    virtual ~Product();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};
}

c90f0a0::Product* FUN_0090f0a0()
{
    return new c90f0a0::Product;
}
}   // namespace f3m_0090f0a0

// @f3 0x00917050 (community match, verified in this file)
namespace f3m_00917050 {
namespace f3m_00917050 {

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

struct Mat3 {
    Vec4 c0, c1, c2;
};

struct P2 {
    int unk00, unk04;
    Mat3* m;
};

struct Out {
    Vec4 v;
    float t;
    int flags;
    int unk18, unk1c;
    int b;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int c;
};

struct Cb;
struct VTable {
    void (__thiscall* fn)(Cb*, P2*, Out*);
};

struct Cb {
    VTable* vt;
    float f;
};

struct FN {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(bool* result, void* p1, Out* out);
    void FUN_00917050(int p1, P2* p2, Cb* apCb);
};

void FN::FUN_00917050(int p1, P2* p2, Cb* apCb)
{
    bool ok;
    Out out;
    out.t = apCb->f;
    out.flags = -1;
    out.b = -1;
    out.c = 0;

    this->v20(&ok, (void*)(*(volatile int*)&p1), &out);
    if (ok) {
        const float v0 = out.v.x;
        const float v1 = out.v.y;
        const float v2 = out.v.z;
        Mat3* m = p2->m;
        void (__thiscall* fn)(Cb*, P2*, Out*) = apCb->vt->fn;
        out.v.x = m->c1.x * v1 + m->c0.x * v0 + m->c2.x * v2;
        out.v.y = m->c1.y * v1 + m->c0.y * v0 + m->c2.y * v2;
        out.v.z = m->c1.z * v1 + m->c0.z * v0 + m->c2.z * v2;
        out.v.w = 0.0f;
        fn(apCb, p2, &out);
    }
}

}
}   // namespace f3m_00917050

// @f3 0x0090c1b0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0090c1b0 {
namespace Small518 {
struct Manager {void FUN_008f6d90(void*,int,int);};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Array {void* data;unsigned short count,capacity;void Release(){if(!(capacity&0x8000)){int n=capacity&0x3fff;Manager* manager=(Manager*)TlsGetValue(DAT_010f3170);manager->FUN_008f6d90(data,n*4,23);}}};
struct Owner {Array first,second;void FUN_0090c1b0();};
// pdb: hkpEntity::ExtendedListeners::~ExtendedListeners | hkpEntity.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
void Owner::FUN_0090c1b0(){second.Release();first.Release();}
}
}   // namespace f3m_0090c1b0

// @f3 0x0090f8d0 (community match, verified in this file)
namespace f3m_0090f8d0 {
namespace Small532 {
struct Ref {virtual void slot00();virtual void Destroy();long refs;};
typedef long (__stdcall *Atomic)(volatile long*);extern Atomic const DAT_00d9b064,DAT_00d9b068;
struct Vector {float x,y,z,w;void Copy(const Vector& p){x=p.x;y=p.y;z=p.z;w=p.w;}}; struct Output {int unk00;Ref* ref;float value;int unk0c;Vector vector;};
struct Owner {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; Ref* ref;int unk88,unk8c;Vector vector;float value;void FUN_0090f8d0(Output*);};
// pdb: hkpSingleShapeContainer::operator= | bhkBvTreeShape.obj | fnv360_0822_debug, objopen_prop, low, conflict (bridge: hkNiTriStripsShape::CopyCinfo)
// pdb params: __that
void Owner::FUN_0090f8d0(Output* out){out->value=value;out->vector.Copy(vector);Ref* old=out->ref;if(old!=ref){if(old&&DAT_00d9b064(&old->refs)==0)old->Destroy();Ref* replacement=ref;out->ref=replacement;if(replacement)DAT_00d9b068(&replacement->refs);}}
}

}   // namespace f3m_0090f8d0

// @f3 0x00900d70 (community match, verified in this file)
extern float DAT_00dc27f8,DAT_00e34860;
namespace f3m_00900d70 {
namespace Small543 {
struct Array {void* data;unsigned size,capacity;Array():data(0),size(0),capacity(0x80000000){}~Array();};
struct Base {void* first;void* last;bool active;Array values;bool enabled;unsigned char unk19;unsigned short index;unsigned unk1c;Base(){first=0;last=0;active=true;enabled=true;index=0xffff;}~Base();};
struct FUN_0097e690 {unsigned unk00;unsigned unk04;unsigned unk08;unsigned unk0c;unsigned unk10;unsigned unk14;unsigned unk18;unsigned unk1c;unsigned unk20;unsigned unk24;unsigned unk28;unsigned unk2c;unsigned unk30;unsigned unk34;unsigned unk38;unsigned unk3c;unsigned unk40;unsigned unk44;unsigned unk48;unsigned unk4c;unsigned unk50;unsigned unk54;unsigned unk58;unsigned unk5c;unsigned unk60;unsigned unk64;unsigned unk68;unsigned unk6c;unsigned unk70;unsigned unk74;unsigned unk78;unsigned unk7c;unsigned unk80;unsigned unk84;unsigned unk88;unsigned unk8c;unsigned unk90;unsigned unk94;unsigned unk98;unsigned unk9c;unsigned unka0; FUN_0097e690();~FUN_0097e690();};
struct FUN_00900d70:Base {FUN_0097e690 part;float a,b;unsigned unkcc;unsigned char unkd0,unkd1,unkd2,flag;FUN_00900d70();};
// pdb: bhkRigidBodyCinfo::bhkRigidBodyCinfo | bhkRigidBody.obj | fnv360_0822_retail, uconst, low
FUN_00900d70::FUN_00900d70(){a=DAT_00dc27f8;flag=0;b=DAT_00e34860;}
}
}   // namespace f3m_00900d70

// @f3 0x00914680 (community match, verified in this file)
extern const char* DAT_010f32f0;
extern const char DAT_00e36308[];
namespace f3m_00914680 {
namespace f3m_00914680 {
struct Array {
 unsigned table;void** data;unsigned short capacity,count,liveCount,growBy;
 void FUN_00555790(unsigned);
 void FUN_005b3880(unsigned,void* const&);
 void Append(void* value){unsigned n=count;if(n>=capacity)FUN_00555790(n+growBy);FUN_005b3880(n,value);}
};
void* __cdecl FUN_00847b50(const char*);
struct Vector {float x,y,z;void* FUN_00823dc0();};
struct Owner {
 void FUN_0090c5a0(Array*);
 Vector FUN_00731a70(const char*);
 void FUN_00914680(Array*);
};
// pdb: bhkBoxShape::GetViewerStrings | bhkBoxShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Owner::FUN_00914680(Array* array){
 FUN_0090c5a0(array);
 array->Append(FUN_00847b50(DAT_010f32f0));
 array->Append(FUN_00731a70(DAT_00e36308).FUN_00823dc0());
}
}
}   // namespace f3m_00914680

// @f3 0x0091bfd0 (community match, verified in this file)
extern const char DAT_00dfdc14[];
namespace f3m_0091bfd0 {
struct List522 {
    unsigned int unk00,unk04;unsigned short capacity,count,unk0c,grow;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void**);
    void Append(void* text) { unsigned int index=count; if(index>=capacity) FUN_00555790(index+grow); FUN_005b3880(index,&text); }
};
struct Node522 {virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual unsigned int Type();};
struct Payload522 {unsigned int unk00,unk04,unk08;Node522* node;unsigned int unk10,unk14,unk18;float value; Node522* GetNode() { if (this) return node; return 0; }};
struct Creator522 {
    virtual ~Creator522();
    virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();virtual void slot14();virtual void Build(List522*);
    void FUN_008fbbb0(Node522*);
};
Creator522* __cdecl FUN_0097a820(unsigned int);
void* __cdecl FUN_00847dd0(const char*,float);
struct Owner522 {
    unsigned int unk00;Payload522* payload;
    void FUN_008fc920(List522*);
    void hkMalleableConstraintCinfo_GetViewerStrings(List522*);
};
// pdb: hkMalleableConstraintCinfo::GetViewerStrings | bhkMalleableConstraint.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel), high
void Owner522::hkMalleableConstraintCinfo_GetViewerStrings(List522* list) {
    FUN_008fc920(list);
    float value=payload?payload->value:0.0f;
    list->Append(FUN_00847dd0(DAT_00dfdc14,value));
    Node522* node=payload?payload->GetNode():0;
    if(node) {
        Creator522* creator=FUN_0097a820(node->Type());
        if(creator) {creator->FUN_008fbbb0(node);creator->Build(list);delete creator;}
    }
}





}   // namespace f3m_0091bfd0

// @f3 0x00908dc0 (community match, verified in this file)
#include <math.h>
namespace f3m_00908dc0 {
namespace f3m_00908dc0 {
struct __declspec(align(16)) V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    float& operator()(int i) { return (&x)[i]; }
    void sub4(const V4& o) { x = x - o.x; y = y - o.y; z = z - o.z; w = w - o.w; }
    void setSub4(const V4& a, const V4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
};
__forceinline float Fabs(float f) { return (float)fabs(f); }

struct Q8World {
    V4 unk00;
    V4 unk10;
    V4 unk20;
    V4 unk30;
    V4 unk40;
    V4 unk50;
    V4 center;
    V4 unk70;
    V4 unk80;
    V4 unk90;
    V4 unka0;
    float extent[3];
    unsigned unkbc;
    V4 wrap;
    void FUN_008d6ba0(V4* p) throw();
    __declspec(noinline) void FUN_00908c40(V4& p) throw();
    bool FUN_00908dc0(const V4& pos) throw();
};


void Q8World::FUN_00908c40(V4& p) throw() {
    { float delta=p.x; float border=wrap.x; float offset=unka0.x;
      if(delta<0.0f) { delta=delta-border; delta=delta+offset; if(delta<0.0f) p.x=p.x-delta; }
      else { delta=delta+border; delta=delta-offset; if(delta>0.0f) p.x=p.x-delta; } }
    { float delta=p.y; float border=wrap.y; float offset=unka0.y;
      if(delta<0.0f) { delta=delta-border; delta=delta+offset; if(delta<0.0f) p.y=p.y-delta; }
      else { delta=delta+border; delta=delta-offset; if(delta>0.0f) p.y=p.y-delta; } }
    { float delta=p.z; float border=wrap.z; float offset=unka0.z;
      if(delta<0.0f) { delta=delta-border; delta=delta+offset; if(delta<0.0f) p.z=p.z-delta; }
      else { delta=delta+border; delta=delta-offset; if(delta>0.0f) p.z=p.z-delta; } }
}

// pdb: bhkWorldM::CheckForMove | bhkWorldM.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arPos
bool Q8World::FUN_00908dc0(const V4& pos) throw()
{
    V4 d(pos);
    V4 c(center);
    d.sub4(c);
    bool changed = false;
    for (unsigned int i = 0; i < 3; i++) {
        if (Fabs(d(i)) >= extent[i]) {
            V4 np(pos);
            changed = true;
            FUN_00908c40(np);
            d.setSub4(np, c);
            d.x = Fabs(d.x);
            d.y = Fabs(d.y);
            d.z = Fabs(d.z);
            d.w = Fabs(d.w);
            int mask = (d.x <= 0.5f ? 8 : 0) | (d.y <= 0.5f ? 4 : 0) | (d.z <= 0.5f ? 2 : 0) | (d.w <= 0.5f ? 1 : 0);
            if ((mask & 0xe) == 0xe)
                return false;
            FUN_008d6ba0(&np);
            break;
        }
    }
    return changed;
}
}

}   // namespace f3m_00908dc0

// @f3 0x0090f290 (community match, verified in this file)
namespace f3m_0090f290 {
namespace f3m_0090f290 {

struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    void setAll3(float r)
    {
        x = r;
        y = r;
        z = r;
        w = 0.0f;
    }
    void mul4(const hkVector4& a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        w *= a.w;
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
    void hkVector4_setTransformedPos(const hkTransform& t, const hkVector4& v);
};

struct hkTransform
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_translation;

    void FUN_008fda60(const hkTransform& t);
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

struct NiPoint3
{
    float x, y, z;
};

struct VertexData
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_numVertices;
    int unk10;
    int unk14;
    NiPoint3* m_vertices;
};

struct ShapeBounds
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    hkTransform m_transform;
    hkAabb m_aabb;
    float m_radius;
    VertexData* m_data;
    int unk88;
    int unk8c;
    hkVector4 m_scale;

    void FUN_0090f290(const hkTransform& transform);
};

void ShapeBounds::FUN_0090f290(const hkTransform& transform)
{
    m_transform.FUN_008fda60(transform);
    m_radius = m_scale.x;
    m_aabb.m_min.setAll3(3.40282e38f);
    m_aabb.m_max.setAll3(-3.40282e38f);
    for (unsigned int i = 0; i < m_data->m_numVertices; i++)
    {
        const NiPoint3& vertex = m_data->m_vertices[i];
        hkVector4 local;
        local.x = vertex.x;
        local.y = vertex.y;
        local.z = vertex.z;
        local.mul4(m_scale);
        hkVector4 world;
        world.hkVector4_setTransformedPos(transform, local);
        m_aabb.m_min.setMin4(m_aabb.m_min, world);
        m_aabb.m_max.setMax4(m_aabb.m_max, world);
    }
}

}
}   // namespace f3m_0090f290

// @f3 0x00909ae0 (community match, verified in this file)
#include <math.h>
namespace f3m_00909ae0 {

__forceinline float zsqrt(float r) { return sqrtf(r); }
__forceinline float zsqrtInverse(float r) { return 1.0f / zsqrt(r); }
struct __declspec(align(16)) hkVector4
{
    float m_quad[4];

    __forceinline float& operator()(int i) { return m_quad[i]; }
    __forceinline const float& operator()(int i) const { return m_quad[i]; }
    __forceinline void set(float x, float y, float z, float w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setZero4()
    {
        m_quad[0] = m_quad[1] = m_quad[2] = m_quad[3] = 0.0f;
    }
    __forceinline void setAbs4(const hkVector4& v)
    {
        m_quad[0] = (float)fabs(v.m_quad[0]);
        m_quad[1] = (float)fabs(v.m_quad[1]);
        m_quad[2] = (float)fabs(v.m_quad[2]);
        m_quad[3] = (float)fabs(v.m_quad[3]);
    }
    __forceinline int getMajorAxis3() const
    {
        hkVector4 tmp;
        tmp.setAbs4(*this);
        return tmp(0) < tmp(1) ? (tmp(1) < tmp(2) ? 2 : 1) : (tmp(0) < tmp(2) ? 2 : 0);
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, float r)
    {
        m_quad[0] = a.m_quad[0] + r * b.m_quad[0];
        m_quad[1] = a.m_quad[1] + r * b.m_quad[1];
        m_quad[2] = a.m_quad[2] + r * b.m_quad[2];
        m_quad[3] = a.m_quad[3] + r * b.m_quad[3];
    }
    __forceinline void setMul4(float r, const hkVector4& a)
    {
        m_quad[0] = r * a.m_quad[0];
        m_quad[1] = r * a.m_quad[1];
        m_quad[2] = r * a.m_quad[2];
        m_quad[3] = r * a.m_quad[3];
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline float lengthSquared3() const
    {
        return m_quad[0] * m_quad[0] + m_quad[1] * m_quad[1] + m_quad[2] * m_quad[2];
    }
    __forceinline float lengthInverse3() const
    {
        float l2 = lengthSquared3();
        return l2 ? zsqrtInverse(l2) : 0;
    }
    __forceinline void mul4(float s)
    {
        m_quad[0] *= s;
        m_quad[1] *= s;
        m_quad[2] *= s;
        m_quad[3] *= s;
    }
    __forceinline void normalize3()
    {
        mul4(lengthInverse3());
    }
    __forceinline void add4(const hkVector4& a)
    {
        m_quad[0] += a.m_quad[0];
        m_quad[1] += a.m_quad[1];
        m_quad[2] += a.m_quad[2];
        m_quad[3] += a.m_quad[3];
    }
    __forceinline void sub4(const hkVector4& a)
    {
        m_quad[0] -= a.m_quad[0];
        m_quad[1] -= a.m_quad[1];
        m_quad[2] -= a.m_quad[2];
        m_quad[3] -= a.m_quad[3];
    }
};

struct ZDebugDisplay
{
    void FUN_00909410(const hkVector4& from, const hkVector4& to, int color, int tag);
    void FUN_009095d0(const hkVector4& from, const hkVector4& dir, int color, int tag);
    void FUN_00909ae0(const hkVector4& plane, const hkVector4& offset, float scale, int color, int tag);
};

void ZDebugDisplay::FUN_00909ae0(const hkVector4& plane, const hkVector4& offset, float scale, int color, int tag)
{
    hkVector4 pos;
    pos.setAddMul4(offset, plane, -plane(3));
    int major = plane.getMajorAxis3();
    hkVector4 binorm;
    binorm.setZero4();
    binorm((major + 1) % 3) = 1.0f;

    binorm.setCross(plane, binorm);
    binorm.normalize3();
    binorm.mul4(scale);

    {
    hkVector4 tangent;
    tangent.setCross(binorm, plane);
    tangent.normalize3();
    tangent.mul4(scale);

    int e = 0;
    // Fake match: the separate unsigned trip counter i (beside the signed index e) steers the compiler
    // into its own stack count-down whose init lands after the index register setup.
    for (unsigned i = 0; i < 4; i++)
    {
        hkVector4 pt1 = pos;
        (e & 2) ? pt1.sub4(tangent) : pt1.add4(tangent);
        (((e + 1) % 4) / 2) ? pt1.sub4(binorm) : pt1.add4(binorm);

        hkVector4 pt2 = pos;
        (((e + 1) % 4) / 2) ? pt2.sub4(tangent) : pt2.add4(tangent);
        (((e + 2) % 4) / 2) ? pt2.sub4(binorm) : pt2.add4(binorm);

        FUN_00909410(pt1, pt2, color, tag);
        e++;
    }
    }

    {
    hkVector4 scaledNormal;
    scaledNormal.setMul4(scale, plane);
    FUN_009095d0(pos, scaledNormal, color, tag);
    }
}
}   // namespace f3m_00909ae0

// @f3 0x00914570 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern float DAT_00f7a690;
namespace f3m_00914570 {
namespace BoxShapeInit {

// four floats as the cinfo stores them (no alignment)
struct Point4 {
    float x;
    float y;
    float z;
    float w;
    Point4(const Point4& other) { x = other.x; y = other.y; z = other.z; w = other.w; }
};

struct __declspec(align(16)) hkVector4 {
    float x;
    float y;
    float z;
    float w;
    hkVector4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

struct BoxCinfo {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Point4 halfExtents;
};

struct ThreadMemory {
    void* FUN_008f6d30(int size, int memoryClass);
};
extern ThreadMemory* (__stdcall* DAT_00d9b080)(unsigned long index);
void __cdecl FUN_00951b90(void* memory);

// the box shape the function creates (constructor at 0x00916750)
struct FUN_00916750 {
    virtual ~FUN_00916750();
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    int type;
    float radius;
    int unk14;
    int unk18;
    int unk1c;
    float halfExtentX;
    float halfExtentY;
    float halfExtentZ;
    float halfExtentW;

    FUN_00916750(const hkVector4& halfExtents, float radius);
    static void* operator new(unsigned int size)
    {
        ThreadMemory* threadMemory = DAT_00d9b080(DAT_010f3170);
        void* memory = threadMemory->FUN_008f6d30(size, 0x27);
        static_cast<FUN_00916750*>(memory)->memSizeAndFlags = (unsigned short)size;
        return memory;
    }
    static void operator delete(void* memory) { FUN_00951b90(memory); }
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            if (--referenceCount == 0)
                delete this;
        }
    }
};

struct ShapeOwner {
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
    virtual void SetShape(FUN_00916750* shape);
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
    virtual void Init(const BoxCinfo* cinfo);
    void FUN_00914570(const BoxCinfo* cinfo);
};

void ShapeOwner::FUN_00914570(const BoxCinfo* cinfo)
{
    if (cinfo) {
        FUN_00916750* shape = new FUN_00916750(hkVector4(cinfo->halfExtents.x, cinfo->halfExtents.y, cinfo->halfExtents.z, cinfo->halfExtents.w), DAT_00f7a690);
        SetShape(shape);
        shape->removeReference();
        Init(cinfo);
    }
}

}

}   // namespace f3m_00914570

// @f3 0x00900570 (community match, verified in this file)
struct NiRTTI {
    const char* name;
    NiRTTI* parent;
};
extern NiRTTI DAT_01092a48;

struct NiNodeX;

struct NiAVObj {
    virtual void v0();
    virtual void v1();
    virtual NiRTTI* GetRTTI();
    virtual NiNodeX* AsNode();
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    NiAVObj* unk1c;
};

struct NiNodeX : NiAVObj {
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    NiAVObj** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

struct Inner {
    float FUN_0056f860();
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
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
    virtual void v56(); virtual void v57();
    virtual void GetColor(float* out);
};

struct __declspec(align(16)) Col4 { float v0, v1, v2, v3; };

struct LightX {
    void* vtable;
    int unk04, unk08, unk0c;
    Inner* unk10;
};

static inline bool IsKind(NiAVObj* p)
{
    NiRTTI* r = p->GetRTTI();
    while (r) {
        if (r == &DAT_01092a48)
            return true;
        r = r->parent;
    }
    return false;
}

// Blends the sampled colour into the running average: colour = colour * (1 - t) + sample * t.
static __forceinline void Interp(float* col, Col4& cc, float t)
{
    float f = t;
    float u = 1.0f - f;
    // Fake match: the three aliases below add nothing to the arithmetic. Reading the average
    // through one pointer, writing it through another and reading the sample through a
    // reference decides which operand of each multiply is loaded first (the factor first for
    // the sample's components 0 and 1, the component first for 2 and 3, as in the original).
    const float* a = col;
    float* d = col;
    const Col4& b = cc;
    d[0] = a[0] * u + b.v0 * f;
    d[1] = a[1] * u + b.v1 * f;
    d[2] = a[2] * u + b.v2 * f;
    d[3] = a[3] * u + b.v3 * f;
}

// pdb: bhkRigidBody::CalculateCOMAndMassRecursive | bhkRigidBody.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apObject, aCenter, afMass
void FUN_00900570(NiAVObj* obj, float* col, float* w)
{
    if (!obj)
        return;
    NiNodeX* node = obj->AsNode();
    if (node) {
        for (unsigned int i = 0; i < node->unkA6; i++)
            FUN_00900570(node->unkA0[i], col, w);
    }
    NiAVObj* p = obj->unk1c;
    if (!p)
        return;
    LightX* l = IsKind(p) ? (LightX*)p : 0;
    if (!l)
        return;
    Inner* in = l->unk10;
    if (!in)
        return;
    float t = in->FUN_0056f860();
    Col4 cc;
    in->GetColor(&cc.v0);
    float sum = *w + t;
    *w = sum;
    Interp(col, cc, t / sum);
}

// @f3 0x0091b1d0 (community match, verified in this file)
extern const double DAT_00e36670;
extern unsigned long DAT_010f3170;
extern float DAT_00f7a690;
namespace f3m_0091b1d0 {
namespace w91b1d0 {
struct ThreadMemory;
__declspec(dllimport) ThreadMemory* __stdcall FUN_00d9b080(unsigned long index) throw();
void* FUN_00aa13e0(unsigned int size);
struct ThreadMemory {
    void* FUN_008f6d30(int size, int memClass);
    void FUN_008f6d90(void* p, int size, int memClass);
    static ThreadMemory& GetInstance() { return *FUN_00d9b080(DAT_010f3170); }
};
struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
    Vector4() {}
    Vector4(const Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void operator=(const Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void Sub4(const Vector4& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
    }
    float& operator()(int i) { return (&x)[i]; }
};
struct Aabb {
    Vector4 min;
    Vector4 max;
};
struct ReferencedObject {
    virtual void Destroy(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    static void* operator new(unsigned int n)
    {
        ReferencedObject* p = (ReferencedObject*)ThreadMemory::GetInstance().FUN_008f6d30(n, 0x27);
        p->memSizeAndFlags = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p);
    void RemoveReference()
    {
        if (memSizeAndFlags != 0)
        {
            --referenceCount;
            if (referenceCount == 0)
                Destroy(1);
        }
    }
};
struct BoxShape : ReferencedObject {
    int userData;
    int type;
    float radius;
    int unk14, unk18, unk1C;
    Vector4 halfExtents;
    BoxShape(const Vector4& halfExtents, float radius);
};
struct Property {
    int key;
    int value;
};
struct PropertyArray {
    Property* data;
    int size;
    int capacityAndFlags;
    int GetCapacity() const { return capacityAndFlags & 0x3fffffff; }
    ~PropertyArray()
    {
        if ((capacityAndFlags & 0x80000000) == 0)
        {
            int n = GetCapacity();
            ThreadMemory& mem = ThreadMemory::GetInstance();
            mem.FUN_008f6d90(data, n * sizeof(Property), 0x17);
        }
    }
};
struct __declspec(align(16)) BodyCinfo {
    unsigned int filterInfo;
    const BoxShape* shape;
    int broadPhaseType;
    PropertyArray properties;
    int unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    Vector4 position, rotation, linearVelocity, angularVelocity;
    Vector4 inertia0, inertia1, inertia2;
    Vector4 centerOfMass;
    float mass;
    float unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    unsigned char motionType;
    unsigned char unkD1, unkD2, unkD3;
    int unkD4, unkD8, unkDC;
    BodyCinfo();
    void SetMass(float m) { mass = m; }
    void SetMotionType(unsigned char t) { motionType = t; }
    void SetFilterInfo(unsigned int f) { filterInfo = f; }
    void SetShape(const BoxShape* s) { shape = s; }
};
struct Body {
    virtual void v0();
    virtual void DeleteThis();
    long refCount;
    int unk08, unk0C, unk10, unk14, unk18;
    Body(BodyCinfo& info);
    static void* operator new(unsigned int n) { return FUN_00aa13e0(n); }
    static void operator delete(void* p);
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};
struct Collidable {
    int shape, shapeKey, motion, parent;
    int ownerOffset;
    int broadPhaseId;
    int broadPhaseType;
    unsigned int filterInfo;
    unsigned int GetFilterInfo() const { return filterInfo; }
};
struct Phantom {
    virtual void v0();
    unsigned short memSizeAndFlags;
    short referenceCount;
    int world;
    int userData;
    Collidable collidable;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68,
        unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    const Collidable* GetCollidable() const { return &collidable; }
};
struct AvoidBox : Phantom {
    Aabb aabb;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    NiPointer<Body> boxBody;
    void FUN_0091b1d0();
};
struct __declspec(align(16)) BVector4 {
    float x, y, z, w;
    BVector4() {}
    void operator=(const Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    operator Vector4() const
    {
        Vector4 r;
        r.x = x;
        r.y = y;
        r.z = z;
        r.w = w;
        return r;
    }
};
struct ShapeCinfo {
    int userData;
};
struct ConvexShapeCinfo : ShapeCinfo {
    float radius;
    ConvexShapeCinfo() { radius = DAT_00f7a690; }
};
struct BoxShapeCinfo : ConvexShapeCinfo {
    BVector4 halfExtents;
};
void AvoidBox::FUN_0091b1d0()
{
    Vector4 extents = aabb.max;
    extents.Sub4(aabb.min);
    extents(0) *= DAT_00e36670;
    extents(1) *= DAT_00e36670;
    extents(3) *= DAT_00e36670;
    BoxShapeCinfo shapeInfo;
    shapeInfo.halfExtents = extents;
    BoxShape* box = new BoxShape(shapeInfo.halfExtents, shapeInfo.radius);
    BodyCinfo info;
    info.SetMass(0.0f);
    info.SetMotionType(6);
    if (GetCollidable())
        info.SetFilterInfo(GetCollidable()->GetFilterInfo());
    info.SetShape(box);
    boxBody = new Body(info);
    box->RemoveReference();
}
}
}   // namespace f3m_0091b1d0

// @f3 0x0090fe50 (community match, verified in this file)
namespace f3m_0090fe50 {
// 0x0090fe50 (550 B): strips collision shape, rebuild the cached world-space
// bounds for a transform. Stores the transform, resets the bounds, then for
// every vertex of every strip: scale to physics units, multiply by the shape's
// scale, transform, and widen the minimum and maximum.
// The pack lists /Od, but the original is optimised (aligned esp frame, this in
// esi): this source matches under /MT /O2 /GS /EHsc /Gy.
namespace f3m_0090fe50 {

struct __declspec(align(16)) Vector {
    float x, y, z, w;
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
    void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    void mul4(const Vector& a)
    {
        (*this)(0) *= a(0);
        (*this)(1) *= a(1);
        (*this)(2) *= a(2);
        (*this)(3) *= a(3);
    }
    void hkVector4_setTransformedPos(const struct Transform* t, const Vector* v);
};

struct Transform {
    float m[16];
    void FUN_008fda60(const Transform* t);
};

struct Vertex {
    float x, y, z;
};

struct Mesh {
    unsigned int unk00, unk04;
    unsigned short count, unk0a;
    unsigned int unk0c, unk10, unk14, unk18, unk1c;
    Vertex* positions;
};

struct Entry {
    Mesh* mesh;
    unsigned int unk04;
};



class Geom {
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Transform m_kTransform;
    Vector m_cachedMin, m_cachedMax, m_vScale;
    int unk90, unk94;
    Entry* entries;
    unsigned int capacity, count;

    void FUN_0090fe50(const Transform* t);
};

void Geom::FUN_0090fe50(const Transform* t)
{
    Vector pt; // w is never written; the original multiplies it as it is
    Vector r;
    m_kTransform.FUN_008fda60(t);
    m_cachedMin.set(3.40282e38f, 3.40282e38f, 3.40282e38f);
    m_cachedMax.set(-3.40282e38f, -3.40282e38f, -3.40282e38f);
    unsigned int n = count;
    for (unsigned int i = 0; i < n; ++i)
    {
        Mesh* mesh = entries[i].mesh;
        Vertex* p = mesh->positions;
        unsigned int m = mesh->count;
        for (unsigned int j = 0; j < m; ++j)
        {
            pt(0) = p[j].x * 0.1428767293691635;
            pt(1) = p[j].y * 0.1428767293691635;
            pt(2) = p[j].z * 0.1428767293691635;
            pt.mul4(m_vScale);
            r.hkVector4_setTransformedPos(t, &pt);
            m_cachedMin.x = m_cachedMin.x < r.x ? m_cachedMin.x : r.x;
            m_cachedMin.y = m_cachedMin.y < r.y ? m_cachedMin.y : r.y;
            m_cachedMin.z = m_cachedMin.z < r.z ? m_cachedMin.z : r.z;
            m_cachedMin.w = m_cachedMin.w < r.w ? m_cachedMin.w : r.w;
            m_cachedMax.x = r.x < m_cachedMax.x ? m_cachedMax.x : r.x;
            m_cachedMax.y = r.y < m_cachedMax.y ? m_cachedMax.y : r.y;
            m_cachedMax.z = r.z < m_cachedMax.z ? m_cachedMax.z : r.z;
            m_cachedMax.w = r.w < m_cachedMax.w ? m_cachedMax.w : r.w;
        }
    }
}

} // namespace f3m_0090fe50
}   // namespace f3m_0090fe50

// @f3 0x0091c460 (community match, verified in this file)
namespace f3m_0091c460 {
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
namespace n91c460 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4() {}
    void operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void setCross(const Vec4& a, const Vec4& b)
    {
        const float cx = a.y * b.z - a.z * b.y;
        const float cy = a.z * b.x - a.x * b.z;
        const float cz = a.x * b.y - a.y * b.x;
        set(cx, cy, cz, 0.0f);
    }
};
struct Reader {
    void* vtbl;
    unsigned pos;
    unsigned (__cdecl* readFn)(Reader*, void*, unsigned, unsigned*, unsigned);
    unsigned Read(void* buf, unsigned bytes)
    {
        unsigned n = readFn(this, buf, bytes, 0, 0);
        pos += n;
        return n;
    }
    unsigned BinaryRead(void* buf, unsigned bytes, unsigned* sizes, unsigned count)
    {
        unsigned n = readFn(this, buf, bytes, sizes, count);
        pos += n;
        return n;
    }
};
struct Stream {
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
    unsigned char unk1e4;
    bool unk1e5;
    unsigned char unk1e6;
    unsigned char unk1e7;
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
    unsigned unk248;
    Reader* unk24c;
    Reader* GetReader() { return unk24c; }
    bool GetFlag() const { return unk1e5; }
};
template <class T> inline void StreamLoad(Reader& r, T* v, unsigned count = 1)
{
    unsigned size = sizeof(T);
    r.BinaryRead(v, size * count, &size, 1);
}
inline void LoadFloat(Stream& s, float& v) { StreamLoad(*s.GetReader(), &v, 1); }
inline void Swap32(float& f) { unsigned long* q = (unsigned long*)&f; *q = _byteswap_ulong(*q); }
inline void SwapVec(Vec4& v) { Swap32(v.x); Swap32(v.y); Swap32(v.z); Swap32(v.w); }
struct Record {
    unsigned unk00;
    unsigned unk04;
    void* unk08;
    void* unk0c;
    Vec4 unk10;
    Vec4 unk20;
    Vec4 unk30;
    Vec4 unk40;
    Vec4 unk50;
    Vec4 unk60;
    Vec4 unk70;
    float unk80;
    float unk84;
    float unk88;
    Record() : unk08(0), unk0c(0) {}
};
struct Data {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec4 unk20;
    Vec4 unk30;
    Vec4 unk40;
    Vec4 unk50;
    Vec4 unk60;
    Vec4 unk70;
    Vec4 unk80;
    Vec4 unk90;
    float unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8;
    float unkbc;
    float unkc0, unkc4, unkc8, unkcc;
    unsigned short unkd0;
    unsigned char unkd2;
    
};
struct Loader {
    void* vtbl;
    Data* unk04;
    void FUN_008fc680(Stream* stream, Record* rec);
    void FUN_0091c460(Stream* stream, Record* rec);
};
void Loader::FUN_0091c460(Stream* stream, Record* rec)
{
    Record local;
    if (!rec) {
        rec = &local;
        FUN_008fc680(stream, rec);
    }
    Data* data = unk04;
    stream->GetReader()->Read(&rec->unk10, 16);
    stream->GetReader()->Read(&rec->unk30, 16);
    stream->GetReader()->Read(&rec->unk50, 16);
    stream->GetReader()->Read(&rec->unk60, 16);
    stream->GetReader()->Read(&rec->unk20, 16);
    stream->GetReader()->Read(&rec->unk40, 16);
    stream->GetReader()->Read(&rec->unk70, 16);
    LoadFloat(*stream, rec->unk80);
    LoadFloat(*stream, rec->unk84);
    LoadFloat(*stream, rec->unk88);
    if (stream->GetFlag() != true) {
        SwapVec(rec->unk10);
        SwapVec(rec->unk30);
        SwapVec(rec->unk50);
        SwapVec(rec->unk60);
        SwapVec(rec->unk20);
        SwapVec(rec->unk40);
        SwapVec(rec->unk70);
    }
    Vec4 cross;
    cross.setCross(rec->unk40, rec->unk70);
    data->unk50 = rec->unk10;
    data->unk20 = rec->unk30;
    data->unk30 = rec->unk50;
    data->unk40 = rec->unk60;
    data->unk90 = rec->unk20;
    data->unk60 = rec->unk40;
    data->unk70 = rec->unk70;
    data->unk80 = cross;
    data->unkd2 = 0;
    data->unkbc = rec->unk88;
}
}
}   // namespace f3m_0091c460

// @f3 0x0090c660 (community match, verified in this file)
extern int DAT_00e35e28;
namespace f3m_0090c660 {
namespace f3m_0090c660 {
struct Obj90c660 {
    void* vftable;
    void FUN_0090bf00();
    void FUN_0090c660();
};
// pdb: hkpRigidBody::~hkpRigidBody | hkpRigidBody.obj | tesv_win, callee_sim, low
void Obj90c660::FUN_0090c660()
{
    vftable = &DAT_00e35e28;
    FUN_0090bf00();
}
}
}   // namespace f3m_0090c660

// @f3 0x0091a270 (community match, verified in this file)
extern const void* DAT_00e332e4;
namespace f3m_0091a270 {
namespace f3_0091a270 {
struct Obj {
    const void* vftable;
    void FUN_0090df60();
    void FUN_0091a270();
};

void Obj::FUN_0091a270() {
    vftable = &DAT_00e332e4;
    FUN_0090df60();
}
}
}   // namespace f3m_0091a270

// @f3 0x0090d6b0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0090d6b0 {
struct xAlloc_0090d6b0 {
    void* FUN_008f6d30(int size, int kind);
};

struct xCmd_0090d6b0;

struct xWorld_0090d6b0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80;
    int active;
    void FUN_00902570(xCmd_0090d6b0* cmd);
};

struct xCmd_0090d6b0 {
    unsigned char type;
    void* owner;
    ::f3m_0091c460::n91c460::Vec4* data;
};

struct xObj_0090d6b0 {
    int unk00, unk04;
    xWorld_0090d6b0* world;
    void FUN_0090d650(const ::f3m_0091c460::n91c460::Vec4&, const ::f3m_0091c460::n91c460::Vec4&);
    void FUN_0090d6b0(const ::f3m_0091c460::n91c460::Vec4& pos, const ::f3m_0091c460::n91c460::Vec4& rot);
};

extern void* (__stdcall *DAT_00d9b080)(unsigned long);

// pdb: hkaRagdollInstance::setPoseWorldSpace | hkaRagdollInstance.obj | fnv360_0721_retail, caller_sim, low
// pdb params: poseIn
void xObj_0090d6b0::FUN_0090d6b0(const ::f3m_0091c460::n91c460::Vec4& position, const ::f3m_0091c460::n91c460::Vec4& rotation)
{
    if (!(world && world->active)) {
        FUN_0090d650(position, rotation);
    } else {
        xCmd_0090d6b0 cmd;
        cmd.type = 0x17;
        cmd.owner = this;
        xAlloc_0090d6b0* alloc = (xAlloc_0090d6b0*)DAT_00d9b080(DAT_010f3170);
        ::f3m_0091c460::n91c460::Vec4* dst = (::f3m_0091c460::n91c460::Vec4*)alloc->FUN_008f6d30(0x20, 4);
        cmd.data = dst;
        cmd.data[0] = position;
        ::f3m_0091c460::n91c460::Vec4* r = cmd.data + 1; r->x=rotation.x;r->y=rotation.y;r->z=rotation.z;float* __restrict last=&r->w; *last=rotation.w;
        world->FUN_00902570(&cmd);
    }
}
}   // namespace f3m_0090d6b0

// @f3 0x00919f90 (community match, verified in this file)
#include <math.h>
namespace f3m_00919f90 {

struct SimdReal
{
    float m_real;
    __forceinline SimdReal() {}
    __forceinline SimdReal(float r) : m_real(r) {}
    __forceinline operator float() const { return m_real; }
    __forceinline SimdReal& operator=(float r) { m_real = r; return *this; }
};

struct __declspec(align(16)) Vector
{
    float x, y, z, w;

    __forceinline void Copy(const Vector& source)
    {
        x = source.x;
        y = source.y;
        z = source.z;
        w = source.w;
    }

    __forceinline float Dot(const Vector& source) const
    {
        return x * source.x + y * source.y + z * source.z;
    }

    __forceinline float Length() const
    {
        float square = Dot(*this);
        float length = sqrtf(square);
        return length;
    }

    __forceinline void setMul4(float rs, const Vector& a)
    {
        x = rs * a.x;
        y = rs * a.y;
        z = rs * a.z;
        w = rs * a.w;
    }

    __forceinline void mul4(SimdReal rs)
    {
        x *= rs;
        y *= rs;
        z *= rs;
        w *= rs;
    }

    __forceinline void Scale(float scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        w *= scale;
    }

    __forceinline void Add(const Vector& vector, SimdReal scale)
    {
        x += vector.x * scale;
        y += vector.y * scale;
        z += vector.z * scale;
        w += vector.w * scale;
    }

    __forceinline void Difference(const Vector& first, const Vector& second)
    {
        x = first.x - second.x;
        y = first.y - second.y;
        z = first.z - second.z;
        w = first.w - second.w;
    }
};

struct Input
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    Vector normal;
    int unk50, unk54, unk58, unk5c;
    int surface;
    int unk64, unk68, unk6c, unk70, unk74;
    float time;
    float gravity;
    int unk80, unk84, unk88, unk8c;
    Vector velocity;
    Vector adjustment;
    int unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8;
};

struct State;
struct Manager;

struct Context
{
    int unk00;
    int unk04;
    int mode;
    Manager* manager;
    int state;
    int previous;
    bool filter;
    float width;
    float speed;
    float gain;
    void hkpCharacterContext_update(const Input& input, Vector& output);
};

struct State
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Change(Context*, const Input&, Vector&);
    virtual void Update(Context*, const Input&, Vector&);
};

struct Manager
{
    State* FUN_0092f420(int state);
};

// pdb: hkpCharacterContext::update | hkpCharacterContext.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void Context::hkpCharacterContext_update(const Input& input, Vector& output)
{
    output.Copy(input.velocity);

    manager->FUN_0092f420(state)->Update(this, input, output);

    if (state == previous)
        manager->FUN_0092f420(state)->Change(this, input, output);

    previous = state;

    if (mode == 1 && state == 0 && input.surface != 7 && input.surface != 6)
    {
        float correction = input.normal.Dot(input.adjustment);
        correction *= input.time;
        output.Add(input.normal, correction);
    }

    if (filter)
    {
        float length = output.Length();
        if (length > speed)
        {
            length = speed / length;
            output.Scale(length);
        }
        Vector delta;
        delta.Difference(output, input.velocity);

        SimdReal s = input.gravity;
        delta.mul4(s);

        float ratio = delta.Length() / width;

        output.Copy(input.velocity);

        if (ratio > 1.0f && state != 1)
        {
            s = input.time * gain / ratio;
            output.Add(delta, s);
        }
        else
        {
            SimdReal k = input.time * gain;
            output.Add(delta, k);
        }
    }
}
}   // namespace f3m_00919f90

// @f3 0x0090f490 (community match, verified in this file)
namespace f3m_0090f490 {
namespace S0090f490_ns {

struct Matrix;

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void mul4(const Vec4& a) { float ax=a.x; float ay=a.y; float az=a.z; float aw=a.w; x = ax * x; y = ay * y; z = az * z; w = aw * w; }
    void hkVector4_setTransformedPos(const Matrix& m, const Vec4& v);
};

struct __declspec(align(16)) Matrix { float m[16]; };

struct Bounds { Vec4 min; Vec4 max; };

struct Point3 { float x, y, z; };

struct S0090f490_Bool {
    char value;
    S0090f490_Bool() {}
    operator bool() const { return value != 0; }
};

struct S0090f490_Xform {
    float m[16];
    S0090f490_Bool FUN_00924fe0(const Matrix& other, float eps) const;
};

struct S0090f490_Verts {
    int unk00;
    int unk04;
    int unk08;
    unsigned int count;
    int unk10;
    int unk14;
    Point3* points;
};

static inline float S0090f490_min2(const float& a, const float& b) { return a < b ? a : b; }
static inline float S0090f490_max2(const float& a, const float& b) { return a > b ? a : b; }

struct S0090f490_Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S0090f490_Xform xform;
    Bounds cached;
    float cachedScale;
    S0090f490_Verts* verts;
    int unk88;
    int unk8c;
    Vec4 scale;
    float radius;
    void FUN_0090f490(const Matrix& m, float extra, Bounds* out);
};

void S0090f490_Shape::FUN_0090f490(const Matrix& m, float extra, Bounds* out)
{
    if (cached.min.x != 3.40282e38f && xform.FUN_00924fe0(m, 0.001f) && scale.x == cachedScale)
    {
        out->min.x = cached.min.x;
        out->min.y = cached.min.y;
        out->min.z = cached.min.z;
        out->min.w = cached.min.w;
        out->max.x = cached.max.x;
        out->max.y = cached.max.y;
        out->max.z = cached.max.z;
        out->max.w = cached.max.w;
    }
    else
    {
        out->min.x = 3.40282e38f;
        out->min.y = 3.40282e38f;
        out->min.z = 3.40282e38f;
        out->min.w = 0.0f;
        out->max.x = -3.40282e38f;
        out->max.y = -3.40282e38f;
        out->max.z = -3.40282e38f;
        out->max.w = 0.0f;

        for (unsigned int i = 0; i < verts->count; i++)
        {
            Vec4 v;
            const Point3& p = verts->points[i];
            v.x = p.x;
            v.y = p.y;
            v.z = p.z;
            v.mul4(scale);
            Vec4 r;
            r.hkVector4_setTransformedPos(m, v);
            out->min.x = S0090f490_min2(out->min.x, r.x);
            out->min.y = S0090f490_min2(out->min.y, r.y);
            out->min.z = S0090f490_min2(out->min.z, r.z);
            out->min.w = S0090f490_min2(out->min.w, r.w);
            out->max.x = S0090f490_max2(out->max.x, r.x);
            out->max.y = S0090f490_max2(out->max.y, r.y);
            out->max.z = S0090f490_max2(out->max.z, r.z);
            out->max.w = S0090f490_max2(out->max.w, r.w);
        }
    }

    float t = radius + extra;
    out->min.x -= t;
    out->min.y -= t;
    out->min.z -= t;
    out->min.w -= t;
    out->max.x += t;
    out->max.y += t;
    out->max.z += t;
    out->max.w += t;
}

}
}   // namespace f3m_0090f490

// @f3 0x00916c50 (community match, verified in this file)
#include <math.h>
namespace f3m_00916c50 {
// 0x00916c50: hkpAabbUtil::calcAabb(const hkTransform& localToWorld, const hkVector4& halfExtents,
// float extraRadius, hkAabb& aabbOut) of Havok 5.5.0 (an inline function of hkpCollide's headers, emitted out of
// line; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The world-space bounding box of a box given by its half extents: each half extent scales its column of the
// rotation, the absolute values of the three scaled columns and the extra radius add up to the box's extent, and
// the extent is laid around the translation.
// Class and member names follow the Havok 5.5.0 SDK headers; the body follows the SDK's inline function of this
// name and the vector helpers follow the SDK's inline maths for the x87 build.

namespace f3m_00916c50 {

typedef float hkReal;

namespace hkMath {
inline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline void setAll3(hkReal a);
    __forceinline void add4(const hkVector4& v);
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b);
    __forceinline void setNeg4(const hkVector4& v);
    __forceinline void setAbs4(const hkVector4& v);
    __forceinline void setBroadcast3clobberW(const hkVector4& v, int i);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setAll3(hkReal a)
{
    x = a;
    y = a;
    z = a;
    w = a;
}

__forceinline void hkVector4::add4(const hkVector4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x + v1.x;
    y = v0.y + v1.y;
    z = v0.z + v1.z;
    w = v0.w + v1.w;
}

__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    x = a.x * b.x;
    y = a.y * b.y;
    z = a.z * b.z;
    w = a.w * b.w;
}

__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    x = -v.x;
    y = -v.y;
    z = -v.z;
    w = -v.w;
}

__forceinline void hkVector4::setAbs4(const hkVector4& v)
{
    x = hkMath::fabs(v.x);
    y = hkMath::fabs(v.y);
    z = hkMath::fabs(v.z);
    w = hkMath::fabs(v.w);
}

__forceinline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
    hkReal r = (&v.x)[i];
    x = r;
    y = r;
    z = r;
    w = r;
}

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

void __cdecl FUN_00916c50(const hkTransform& localToWorld, const hkVector4& halfExtents, float extraRadius,
                          hkAabb& aabbOut)
{
    hkVector4 he0;
    he0.setBroadcast3clobberW(halfExtents, 0);
    hkVector4 he1;
    he1.setBroadcast3clobberW(halfExtents, 1);
    hkVector4 he2;
    he2.setBroadcast3clobberW(halfExtents, 2);

    hkVector4 transformedX;
    transformedX.setMul4(he0, localToWorld.getRotation().getColumn(0));
    hkVector4 transformedY;
    transformedY.setMul4(he1, localToWorld.getRotation().getColumn(1));
    hkVector4 transformedZ;
    transformedZ.setMul4(he2, localToWorld.getRotation().getColumn(2));

    transformedX.setAbs4(transformedX);
    transformedY.setAbs4(transformedY);
    transformedZ.setAbs4(transformedZ);

    hkVector4 max = aabbOut.m_max;
    hkVector4 min = aabbOut.m_min;

    hkVector4 extra;
    extra.setAll3(extraRadius);
    transformedZ.add4(extra);
    max.setAdd4(transformedX, transformedY);
    max.add4(transformedZ);

    min.setNeg4(max);
    max.add4(localToWorld.getTranslation());
    min.add4(localToWorld.getTranslation());

    aabbOut.m_max = max;
    aabbOut.m_min = min;
}

}  // namespace f3m_00916c50
}   // namespace f3m_00916c50

// @f3 0x009095d0 (community match, verified in this file)
#include <math.h>
namespace f3m_009095d0 {

// 0x009095d0: draws an arrow from `from` along `dir` as five lines: the shaft and four head lines that start at
// 85% of its length (hkDebugDisplay::displayArrow in Havok terms). Nothing is drawn for a zero direction.

namespace DisplayArrow9095D0 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return (hkReal)::sqrt(r); }
    __forceinline hkReal fabs(hkReal r) { return (hkReal)::fabs(r); }
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    // this = a + r * b
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
    // this = a + t * (b - a)
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, hkReal t)
    {
        hkReal s = 1.0f - t;
        x = s * a.x + t * b.x;
        y = s * a.y + t * b.y;
        z = s * a.z + t * b.z;
        w = s * a.w + t * b.w;
    }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b)
    {
        hkReal cx = a.y * b.z - a.z * b.y;
        hkReal cy = a.z * b.x - a.x * b.z;
        hkReal cz = a.x * b.y - a.y * b.x;
        x = cx;
        y = cy;
        z = cz;
        w = 0;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkReal lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
    __forceinline hkReal length3() const { return hkMath::sqrt((x * x) + (y * y) + (z * z)); }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = (x * x) + (y * y) + (z * z);
        return l2 != 0.0f ? hkMath::sqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

// a vector at right angles to vectorIn: its smallest component is dropped, the other two are swapped, one negated
__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkMath::fabs(vectorIn(0));
    hkReal a1 = hkMath::fabs(vectorIn(1));
    hkReal a2 = hkMath::fabs(vectorIn(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

class hkDebugDisplay
{
public:
    // displayLine
    void FUN_00909410(const hkVector4& start, const hkVector4& end, int color, int tag);
    void FUN_009095d0(const hkVector4& from, const hkVector4& dir, int color, int tag);
};

void hkDebugDisplay::FUN_009095d0(const hkVector4& from, const hkVector4& dir, int color, int tag)
{
    // nothing to draw without a direction
    if (dir.lengthSquared3() < 1.1920928955078125e-07f)
    {
        return;
    }

    hkVector4 to;
    to.setAdd4(from, dir);
    hkVector4 ort;
    calculatePerpendicularVector(dir, ort);
    ort.normalize3();
    hkVector4 ort2;
    ort2.setCross(dir, ort);

    ort.mul4(dir.length3());

    const hkReal c = 0.85f;
    hkVector4 p;
    p.setInterpolate4(from, to, c);
    hkVector4 p0;
    p0.setAddMul4(p, ort, 1.0f - c);
    hkVector4 p1;
    p1.setAddMul4(p, ort, -(1.0f - c));
    hkVector4 p2;
    p2.setAddMul4(p, ort2, 1.0f - c);
    hkVector4 p3;
    p3.setAddMul4(p, ort2, -(1.0f - c));

    FUN_00909410(from, to, color, tag);
    FUN_00909410(to, p0, color, tag);
    FUN_00909410(to, p1, color, tag);
    FUN_00909410(to, p2, color, tag);
    FUN_00909410(to, p3, color, tag);
}

}
}   // namespace f3m_009095d0

// @f3 0x0091d650 (community match, verified in this file)
#include <math.h>
namespace f3m_0091d650 {

// 0x0091d650: closest point between a sphere (centre in x, y, z, radius in w) and this object's capsule shape
// placed by a transform. Returns false when they are further apart than the two radii; otherwise fills the
// contact point: position on the capsule surface side, unit normal from capsule to sphere, and the distance.

namespace SphereCapsule91D650 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return (hkReal)::sqrt(r); }
    __forceinline hkReal fabs(hkReal r) { return (hkReal)::fabs(r); }
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline hkReal get(int i) const { return (&x)[i]; }

    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    // this = a + r * b
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkReal lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = (x * x) + (y * y) + (z * z);
        return l2 != 0.0f ? hkMath::sqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkTransform
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_translation;
};

// one point: rotation columns c0..c2, translation c3, w = 0. c0y is the y of c0, handed over by value by the loop
__forceinline void transformPoint(hkVector4& out, const hkVector4& c0, const hkVector4& c1, const hkVector4& c2, const hkVector4& c3, const hkVector4& b, hkReal c0y)
{
    const hkReal v0 = b(0);
    const hkReal v1 = b(1);
    const hkReal v2 = b(2);
    out(0) = c0.get(0) * v0 + c1.get(0) * v1 + c2.get(0) * v2 + c3.get(0);
    out(1) = c0y * v0 + c1.get(1) * v1 + c2.get(1) * v2 + c3.get(1);
    out(2) = c0.get(2) * v0 + c1.get(2) * v1 + c2.get(2) * v2 + c3.get(2);
    out(3) = 0;
}

// moves points by a transform, last to first, from copies of its columns
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkVector4 c0 = t.m_col0;
    hkVector4 c1 = t.m_col1;
    hkVector4 c2 = t.m_col2;
    hkVector4 c3 = t.m_translation;
    int i = numVectors - 1;
    do
    {
        transformPoint(vectorsOut[i], c0, c1, c2, c3, vectorsIn[i], c0.y);
    } while (--i >= 0);
}

// a vector at right angles to vectorIn: its smallest component is dropped, the other two are swapped, one negated
__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkMath::fabs(vectorIn(0));
    hkReal a1 = hkMath::fabs(vectorIn(1));
    hkReal a2 = hkMath::fabs(vectorIn(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;   // unit normal in x, y, z and the distance in w
};

struct hkpCapsuleShape
{
    void* vtable;
    int m_memSizeAndFlags;
    void* m_userData;
    int m_type;
    hkReal m_radius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;

    __forceinline hkReal getRadius() const { return m_radius; }
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }
};

// closest point on the segment a-b to p
void __cdecl FUN_0096fa60(const hkVector4& p, const hkVector4& a, const hkVector4& b, hkVector4& pointOnEdge);

struct CapsuleObject
{
    void* vtable;
    int m_refCount;
    const hkpCapsuleShape* m_shape;

    bool FUN_0091d650(const hkVector4& sphere, const hkTransform& transform, hkContactPoint& cpoint);
};

// pdb: bhkCapsuleShape::GetClosestPoints | bhkCapsuleShape.obj | fnv360_0721_beta, objrun, medium
// pdb params: arSphere, arTrans, arCPoint
bool CapsuleObject::FUN_0091d650(const hkVector4& sphere, const hkTransform& transform, hkContactPoint& cpoint)
{
    const hkpCapsuleShape* capsule = this ? m_shape : 0;

    hkVector4 capsB[2];
    transformPoints(transform, capsule->getVertices(), 2, capsB);

    hkVector4 pointOnEdge;
    FUN_0096fa60(sphere, capsB[0], capsB[1], pointOnEdge);

    hkVector4 aMinusB;
    aMinusB.setSub4(sphere, pointOnEdge);

    const hkReal radiusSum = sphere(3) + capsule->getRadius();
    hkReal distSquared = aMinusB.lengthSquared3();
    if (distSquared >= radiusSum * radiusSum)
    {
        return false;
    }

    hkReal dist;
    if (distSquared > 0)
    {
        // the usual case: the normal is the direction from the axis to the centre
        dist = hkMath::sqrt(distSquared);
        const hkReal ax = aMinusB.x;
        const hkReal invLen = aMinusB.lengthInverse3();
        aMinusB.x = ax * invLen;
        aMinusB.y *= invLen;
        aMinusB.z *= invLen;
        aMinusB.w *= invLen;
    }
    else
    {
        // the centre is on the axis: any direction at right angles to it will do
        dist = 0;
        hkVector4 edge;
        edge.setSub4(capsB[1], capsB[0]);
        calculatePerpendicularVector(edge, aMinusB);
        aMinusB.normalize3();
    }

    // the normal goes into x, y, z; w is the distance, set last
    cpoint.m_separatingNormal.x = aMinusB.x;
    cpoint.m_separatingNormal.y = aMinusB.y;
    cpoint.m_separatingNormal.z = aMinusB.z;
    cpoint.m_position.setAddMul4(sphere, cpoint.m_separatingNormal, capsule->getRadius() - dist);
    cpoint.m_separatingNormal.w = dist - radiusSum;
    return true;
}

}
}   // namespace f3m_0091d650

// @f3 0x00904da0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00904da0 {
// FUN_00904da0: activate every rigid body whose broad-phase handle overlaps a box.
// When critical operations are locked the request is queued with a copy of the box.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

void __cdecl FUN_009234e0(void* dst, const void* src, int size);

namespace n904da0 {

struct ThreadMemory {
    void* FUN_008f6d30(int size, int cls);
    void FUN_008f6d90(void* memory, int size, int cls);
    static ThreadMemory& getInstance() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }
};

template <class T>
inline T* allocateChunk(int count, int cls)
{
    return (T*)ThreadMemory::getInstance().FUN_008f6d30(count * sizeof(T), cls);
}

template <class T>
inline void deallocateChunk(T* p, int count, int cls)
{
    ThreadMemory::getInstance().FUN_008f6d90(p, count * sizeof(T), cls);
}

template <class T>
class Array {
public:
    enum {
        CAPACITY_MASK = int(0x3FFFFFFF),
        DONT_DEALLOCATE_FLAG = int(0x80000000)
    };
    Array() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & int(CAPACITY_MASK); }
    T& operator[](int i) { return m_data[i]; }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0) {
            ThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct Aabb {
    float min[4];
    float max[4];
};

struct RigidBody {
    void FUN_0090b500();
};

struct Handle {
    unsigned int id;
};

struct TypedHandle : Handle {
    signed char type;
    signed char ownerOffset;
    void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this)) + ownerOffset; }
};

struct Collidable {
    void* shape;
    unsigned int shapeKey;
    const void* motion;
    const Collidable* parent;
    signed char ownerOffset;
    char pad11[3];
    TypedHandle handle;
    signed char getType() const { return handle.type; }
};

inline void* getWorldObject(const Collidable* c)
{
    return const_cast<char*>(reinterpret_cast<const char*>(c)) + c->ownerOffset;
}

inline RigidBody* getRigidBody(const Collidable* c)
{
    if (c->getType() == 1) {
        return static_cast<RigidBody*>(getWorldObject(c));
    }
    return 0;
}

struct HandlePair {
    Handle* a;
    Handle* b;
};

struct BroadPhase {
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
    virtual void querySingleAabb(const Aabb& aabb, Array<HandlePair>& pairs);
};

struct Operation {
    unsigned char type;
    Operation(unsigned char t) : type(t) {}
};

struct ActivateRegionOp : Operation {
    ActivateRegionOp() : Operation(0x1f) {}
    Aabb* aabb;
};

struct World {
    unsigned int unk00[21];
    BroadPhase* broadPhase;
    unsigned int unk58[11];
    int lockCount;
    bool areCriticalOperationsLocked() const { return lockCount != 0; }
    void FUN_00902570(const Operation& op);
    void FUN_00904da0(const Aabb& aabb);
};

// pdb: hkpWorld::activateRegion | hkpWorld.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aabb
void World::FUN_00904da0(const Aabb& aabb)
{
    if (areCriticalOperationsLocked()) {
        ActivateRegionOp op;
        op.aabb = allocateChunk<Aabb>(1, 4);
        FUN_009234e0(op.aabb, &aabb, sizeof(Aabb));
        FUN_00902570(op);
        return;
    }

    Array<HandlePair> pairs;
    broadPhase->querySingleAabb(aabb, pairs);
    for (int i = 0; i < pairs.getSize(); i++) {
        Collidable* coll = static_cast<Collidable*>(static_cast<TypedHandle*>(pairs[i].b)->getOwner());
        RigidBody* body = getRigidBody(coll);
        if (body) {
            body->FUN_0090b500();
        }
    }
    // Fake match: the array is released by an explicit call instead of a destructor. With a
    // destructor the listed flags add an unwind frame the original does not have (the natural
    // destructor form matches only with exception handling off).
    pairs.releaseMemory();
}

}
}   // namespace f3m_00904da0

// @f3 0x0090d750 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0090d750 {

namespace o55_0090d750 {

struct Vec4 {
    float x, y, z, w;
    inline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
};

struct ThreadMemory {
    void* FUN_008f6d30(int nbytes, int memClass);
    static inline ThreadMemory& getInstance()
    {
        return *static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
    }
};

template <typename T>
__forceinline T* allocateChunk(int count, int memClass)
{
    return static_cast<T*>(ThreadMemory::getInstance().FUN_008f6d30(count * (int)sizeof(T), memClass));
}

struct Operation {
    Operation(unsigned char type) : type(type) {}
    unsigned char type;
};

struct Body;

struct PointImpulseOperation : public Operation {
    PointImpulseOperation() : Operation(0x1b) {}
    Body* body;
    Vec4* pointAndImpulse;
};

struct World {
    char pad00[0x84];
    int lockCount;
    inline int areOperationsLocked() const { return lockCount; }
    void FUN_00902570(const Operation& operation);
};

struct Motion {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48();
    virtual void applyPointImpulse(const Vec4& imp, const Vec4& p);
};

struct Body {
    char pad00[8];
    World* world;
    char pad0c[0xc4];
    Motion motion;
    inline World* getWorld() const { return world; }
    inline Motion* getMotion() { return &motion; }
    void FUN_0090b500();
    void FUN_0090d750(const Vec4& imp, const Vec4& p);
};

}

void o55_0090d750::Body::FUN_0090d750(const Vec4& imp, const Vec4& p)
{
    if (getWorld() && getWorld()->areOperationsLocked()) {
        PointImpulseOperation op;
        op.body = this;
        op.pointAndImpulse = allocateChunk<Vec4>(2, 4);
        op.pointAndImpulse[0] = p;
        op.pointAndImpulse[1] = imp;
        getWorld()->FUN_00902570(op);
        return;
    }
    FUN_0090b500();
    getMotion()->applyPointImpulse(imp, p);
}
}   // namespace f3m_0090d750

// @f3 0x0091a630 (community match, verified in this file)
#include <math.h>
extern float FUN_00f7ae50[];
extern bool g_bFreezeBounds;
namespace f3m_0091a630 {

namespace f3m_0091a630 {

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;

    __forceinline void Copy(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline float Dot(const Vec4& v) const { return x * v.x + y * v.y + z * v.z; }
    __forceinline float Length() const
    {
        float square = Dot(*this);
        float length = sqrtf(square);
        return length;
    }
    __forceinline Vec4 operator+(const Vec4& v) const
    {
        Vec4 r;
        r.x = x + v.x;
        r.y = y + v.y;
        r.z = z + v.z;
        r.w = w + v.w;
        return r;
    }
    void hkVector4_setTransformedPos(const struct Transform& m, const Vec4& v);
};

__forceinline float AbsF(float f) { return fabsf(f); }

struct __declspec(align(16)) Quat
{
    float x, y, z, w;
    void FUN_009240d0(const Vec4* axis, float angle);
};

struct __declspec(align(16)) Rotation
{
    float m[12];
    void hkRotation_set(const Quat* q);
};

struct __declspec(align(16)) Transform
{
    Rotation rot;
    Vec4 pos;
};

struct Bounds
{
    Vec4 min;
    Vec4 max;
};

struct Body
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
    virtual void Refresh();
    void hkpAabbPhantom_setAabb(const Bounds* box);
    void FUN_0091a460(float angle);
};


__forceinline int WithinMask(const Vec4& d, float eps)
{
    int x = d.x <= eps ? 8 : 0;
    int y = d.y <= eps ? 4 : 0;
    int z = d.z <= eps ? 2 : 0;
    int w = d.w <= eps ? 1 : 0;
    return w | z | y | x;
}

struct Placer
{
    int unk00;
    int unk04;
    Body* body;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Bounds local;
    Vec4 offset;
    Vec4 lastPos;
    float limit;
    int unk64;
    bool locked;
    bool halfLimit;
    void FUN_00c24b70();
    void FUN_0056cb70(Bounds* out);
    void FUN_0091a630(const Vec4* pos, unsigned char dir);
};

static __forceinline void SyncBody(Placer* p, Bounds& box, const Vec4* pos, float angle)
{
    if (!p)
        return;

    Body* locker = p->body;
    if (locker)
    {
        p->FUN_00c24b70();
        locker->hkpAabbPhantom_setAabb(&box);
        p->FUN_00c24b70();
    }

    Body* b = p->body;
    if (!b)
        return;

    int stamp = *(int*)((char*)b + 0xdc);
    b->FUN_0091a460(angle);
    if (stamp == *(int*)((char*)b + 0xdc))
    {
        float lim = p->limit;
        if (p->halfLimit)
            lim = (float)(lim * 0.5);
        if (lim > 0.0f)
        {
            Vec4 delta;
            delta.x = pos->x - p->lastPos.x;
            delta.y = pos->y - p->lastPos.y;
            delta.z = pos->z - p->lastPos.z;
            float dist = delta.Length();
            if (!(dist > lim))
                return;
        }
    }

    p->lastPos.Copy(*pos);
    if (p->locked)
        return;
    if (*((char*)p->body + 0x12d))
        return;
    b->Refresh();
}

void Placer::FUN_0091a630(const Vec4* pos, unsigned char dir)
{
    if (g_bFreezeBounds)
        return;

    int index = 0;
    if (dir & 1)
        index = 3;
    else if (dir & 2)
        index = 6;
    if (dir & 8)
        index += 2;
    else if (dir & 4)
        index += 1;

    float angle = FUN_00f7ae50[index] + pos->w;

    Vec4 axis;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    axis.w = 0.0f;
    Quat q;
    q.FUN_009240d0(&axis, -angle);

    Transform t;
    t.pos.Copy(*pos);
    t.rot.hkRotation_set(&q);

    Vec4 moved;
    moved.hkVector4_setTransformedPos(t, offset);

    const Bounds& loc = local;
    Bounds box;
    box.min.x = loc.min.x + moved.x;
    box.min.y = loc.min.y + moved.y;
    box.min.z = loc.min.z + moved.z;
    box.min.w = loc.min.w + moved.w;
    box.max.x = loc.max.x + moved.x;
    box.max.y = loc.max.y + moved.y;
    box.max.z = loc.max.z + moved.z;
    box.max.w = loc.max.w + moved.w;

    Bounds current;
    FUN_0056cb70(&current);

    Vec4 d;
    d.x = current.min.x - box.min.x;
    d.y = current.min.y - box.min.y;
    d.z = current.min.z - box.min.z;
    d.w = current.min.w - box.min.w;
    d.x = AbsF(d.x);
    d.y = AbsF(d.y);
    d.z = AbsF(d.z);
    d.w = AbsF(d.w);

    int within = WithinMask(d, 0.001f) & 0xe;
    if (within == 0xe)
        return;
    SyncBody(this, box, pos, angle);
}

}
}   // namespace f3m_0091a630

// @f3 0x009143c0 (community match, verified in this file)
namespace f3m_009143c0 {
struct Vec3 { float x, y, z; };

struct Src {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec3 pos;
};

struct Created;
extern const char* DAT_00e207a8;
extern char* __cdecl FUN_008242a0(const char* s);
extern void (__stdcall* DAT_00d9b064)(void* p);

struct Str {
    char* data;
    Str(const char* s) : data(FUN_008242a0(s)) {}
    ~Str() { if (data != DAT_00e207a8) DAT_00d9b064(data - 8); }
};

struct Created {
    void SetName(const Str* name);
};

struct Dest {
    virtual void d000();
    virtual void d004();
    virtual void d008();
    virtual void d00c();
    virtual void d010();
    virtual void d014();
    virtual void d018();
    virtual void d01c();
    virtual void d020();
    virtual void d024();
    virtual void d028();
    virtual void d02c();
    virtual void d030();
    virtual void d034();
    virtual void d038();
    virtual void d03c();
    virtual void d040();
    virtual void d044();
    virtual void d048();
    virtual void d04c();
    virtual void d050();
    virtual void d054();
    virtual void d058();
    virtual void d05c();
    virtual void d060();
    virtual void d064();
    virtual void d068();
    virtual void d06c();
    virtual void d070();
    virtual void d074();
    virtual void d078();
    virtual void d07c();
    virtual void d080();
    virtual void d084();
    virtual void d088();
    virtual void d08c();
    virtual void d090();
    virtual void d094();
    virtual void d098();
    virtual void d09c();
    virtual void d0a0();
    virtual void d0a4();
    virtual void d0a8();
    virtual void d0ac();
    virtual void d0b0();
    virtual void d0b4();
    virtual void d0b8();
    virtual void d0bc();
    virtual void d0c0();
    virtual void d0c4();
    virtual void d0c8();
    virtual void d0cc();
    virtual void d0d0();
    virtual void d0d4();
    virtual void d0d8();
    virtual void d0dc(Created* obj, int flag);
};

struct Owner {
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
    virtual void v0d8(Created* obj);
    int unk04;
    Src* unk08;
    void bhkBoxShape_BuildDisplayGeometry(Dest* dest);
};

extern const Vec3 DAT_01092a50;
extern const double DAT_00db88e8;
extern const double DAT_00db75d0;
extern const char DAT_00e32644[];
extern Created* __cdecl FUN_00ab10c0(const Vec3* pos, int flag);

// pdb: bhkBoxShape::BuildDisplayGeometry | bhkBoxShape.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|vtable), high
void Owner::bhkBoxShape_BuildDisplayGeometry(Dest* dest)
{
    const Vec3* pSrc;
    if (this && unk08)
        pSrc = &unk08->pos;
    else
        pSrc = &DAT_01092a50;
    __declspec(align(16)) Vec3 src;
    src.x = pSrc->x;
    src.y = pSrc->y;
    src.z = pSrc->z;
    Vec3 out;
    out.x = (float)(src.x * DAT_00db88e8);
    out.y = (float)(src.y * DAT_00db88e8);
    out.z = (float)(src.z * DAT_00db88e8);
    out.x = (float)(out.x * DAT_00db75d0);
    out.y = (float)(out.y * DAT_00db75d0);
    out.z = (float)(out.z * DAT_00db75d0);
    Created* created = FUN_00ab10c0(&out, 0);
    if (created) {
        v0d8(created);
        {
            Str name(DAT_00e32644);
            created->SetName(&name);
        }
        dest->d0dc(created, 1);
    }
}
}   // namespace f3m_009143c0

// @f3 0x00904690 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern const char DAT_00e34e10[];
extern unsigned int DAT_00dcc494;
namespace f3m_00904690 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
extern "C" void _ReadWriteBarrier(void);

struct AD90904690 { void** data; int size; unsigned int cap; };

struct FreeList90904690 { void* head; int numElem; };

struct Mgr90904690 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int maxNumElemsOnFreeList;
    FreeList90904690 freeList[12];
    void FUN_008f6890(int, void*, int);
    void FUN_008f6d90(void*, int, int);
};

struct Del90904690 {
    virtual ~Del90904690();
};

struct R90904690 {
    virtual void v0(int);
    unsigned short unk04;
    short unk06;
    void removeReference() {
        if (unk04 != 0) {
            unk06 = unk06 - 1;
            if (unk06 == 0) v0(1);
        }
    }
};

struct E90904690 {
    virtual ~E90904690();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44;
    void** unk48;
    int unk4c;
};

struct BR909037f0 {
    char b;
    BR909037f0() {}
    BR909037f0(const BR909037f0& o) { b = o.b; }
    BR909037f0(bool v) { b = v ? 1 : 0; }
    operator bool() const { return b != 0; }
};

struct O90904690 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    void* inner6c;
};
struct D90984c20 { void FUN_00984c20(); };
struct D909835d0 { void FUN_009835d0(); };
struct S90908ab0 { void FUN_00908ab0(int); };

void FUN_00926680(void*, void*);
void FUN_00988e70(void*);

__forceinline void PutRow90904690(void* (__stdcall *getTls)(unsigned long), int row, void* p, int cls)
{
    Mgr90904690* m = (Mgr90904690*)getTls(DAT_010f3170);
    if (m->freeList[row].numElem >= m->maxNumElemsOnFreeList)
        m->FUN_008f6890(row, p, cls);
    else
    {
        _ReadWriteBarrier();
        void* next = m->freeList[row].head;
        m->freeList[row].numElem++;
        *(void**)p = next;
        m->freeList[row].head = p;
    }
}
struct W90904690 {
    unsigned int vtable;
    unsigned short unk04;
    unsigned short unk06;
    void* unk8;
    void* unkc;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    E90904690* unk20;
    void* unk24;
    AD90904690 unk28;
    AD90904690 unk34;
    AD90904690 unk40;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    Del90904690* unk5c;
    Del90904690* unk60;
    Del90904690* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    int unk98;
    unsigned short unk9c, unk9e;
    void* unka0;
    void* unka4;
    void* unka8;
    void* unkac;
    void* unkb0;
    void* unkb4;
    unsigned char unkb8;
    void* unkbc;
    void* unkc0;
    void* unkc4;
    void* unkc8;
    void* unkcc;
    void* unkd0;
    void* unkd4;
    void* unkd8;
    void* unkdc;
    void* unke0;
    AD90904690 unke4;
    AD90904690 unkf0;
    AD90904690 unkfc;
    AD90904690 unk108;
    AD90904690 unk114;
    AD90904690 unk120;
    AD90904690 unk12c;
    AD90904690 unk138;
    AD90904690 unk144;
    AD90904690 unk150;
    AD90904690 unk15c;
    AD90904690 unk168;
    AD90904690 unk174;
    AD90904690 unk180;
    void* unk18c;

    void FUN_009028d0(void*);
    BR909037f0 FUN_009037f0(void*);
    void FUN_00904690();
};

// pdb: hkpWorld::~hkpWorld | hkpWorld.obj | fnv360_0822_retail, call_seq, high
void W90904690::FUN_00904690()
{
    void* (__stdcall *getTls)(unsigned long) = DAT_00d9b080;
    void* p68 = unk68;
    vtable = (unsigned int)DAT_00e34e10;

    if (p68)
        PutRow90904690(getTls, 3, p68, 0x2f);

    ((R90904690*)unk4c)->removeReference();
    unk4c = 0;

    if (unka8) { ((S90908ab0*)unka8)->FUN_00908ab0(1); unka8 = 0; }
    if (unkb4) { ((S90908ab0*)unkb4)->FUN_00908ab0(1); unkb4 = 0; }
    if (unkac) { ((S90908ab0*)unkac)->FUN_00908ab0(1); unkac = 0; }
    if (unkb0) { ((S90908ab0*)unkb0)->FUN_00908ab0(1); unkb0 = 0; }

    if (unk50) { ((R90904690*)unk50)->removeReference(); unk50 = 0; }
    while (unke4.size > 0)
        FUN_009028d0(unke4.data[0]);

    while (unk28.size > 0) {
        E90904690* e = (E90904690*)unk28.data[0];
        if (e->unk4c == 0) break;
        FUN_009037f0(*e->unk48);
    }
    while (unk34.size > 0) {
        E90904690* e = (E90904690*)unk34.data[0];
        FUN_009037f0(*e->unk48);
    }

    if (unkb8 == 0) {
        E90904690* e = (E90904690*)unk28.data[unk28.size - 1];
        FUN_00926680(this, e);
        e = (E90904690*)unk28.data[unk28.size - 1];
        delete e;
        unk28.size--;
    }

    FUN_009037f0(unk24);
    unk24 = 0;
    while (unk20->unk4c > 0)
        FUN_009037f0(*unk20->unk48);

    FUN_00926680(this, unk20);
    delete unk20;
    unk20 = 0;
    FUN_00988e70(this);

    ((R90904690*)unk54)->removeReference();
    unk54 = 0;
    ((R90904690*)unk74)->removeReference();
    unk74 = 0;

    void* p58 = unk58;
    if (p58) {
        ((D90984c20*)p58)->FUN_00984c20();
        PutRow90904690(getTls, 0xb, p58, 0x27);
    }

    if (unk18c) ((R90904690*)unk18c)->removeReference();

    delete unk5c;
    delete unk60;
    delete unk64;

    ((R90904690*)unk70)->removeReference();
    ((R90904690*)unk78)->removeReference();

    void* inner6c = ((O90904690*)unk6c)->inner6c;
    if (inner6c)
        PutRow90904690(getTls, 2, inner6c, 0x1f);
    void* p6c = unk6c;
    if (p6c)
        PutRow90904690(getTls, 7, p6c, 0x1f);

    ((R90904690*)unk8)->removeReference();

    void* p7c = unk7c;
    if (p7c) {
        ((D909835d0*)p7c)->FUN_009835d0();
        PutRow90904690(getTls, 6, p7c, 0x2f);
    }

    if (!(unk180.cap & 0x80000000u)) { int n = unk180.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk180.data, n * 4, 0x17); }
    if (!(unk174.cap & 0x80000000u)) { int n = unk174.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk174.data, n * 4, 0x17); }
    if (!(unk168.cap & 0x80000000u)) { int n = unk168.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk168.data, n * 4, 0x17); }
    if (!(unk15c.cap & 0x80000000u)) { int n = unk15c.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk15c.data, n * 4, 0x17); }
    if (!(unk150.cap & 0x80000000u)) { int n = unk150.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk150.data, n * 4, 0x17); }
    if (!(unk144.cap & 0x80000000u)) { int n = unk144.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk144.data, n * 4, 0x17); }
    if (!(unk138.cap & 0x80000000u)) { int n = unk138.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk138.data, n * 4, 0x17); }
    if (!(unk12c.cap & 0x80000000u)) { int n = unk12c.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk12c.data, n * 4, 0x17); }
    if (!(unk120.cap & 0x80000000u)) { int n = unk120.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk120.data, n * 4, 0x17); }
    if (!(unk114.cap & 0x80000000u)) { int n = unk114.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk114.data, n * 4, 0x17); }
    if (!(unk108.cap & 0x80000000u)) { int n = unk108.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk108.data, n * 4, 0x17); }
    if (!(unkfc.cap & 0x80000000u)) { int n = unkfc.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unkfc.data, n * 4, 0x17); }
    if (!(unkf0.cap & 0x80000000u)) { int n = unkf0.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unkf0.data, n * 4, 0x17); }
    if (!(unke4.cap & 0x80000000u)) { int n = unke4.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unke4.data, n * 4, 0x17); }
    if (!(unk40.cap & 0x80000000u)) { int n = unk40.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk40.data, n * 4, 0x17); }
    if (!(unk34.cap & 0x80000000u)) { int n = unk34.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk34.data, n * 4, 0x17); }
    if (!(unk28.cap & 0x80000000u)) { int n = unk28.cap & 0x3fffffff; Mgr90904690* h = (Mgr90904690*)getTls(DAT_010f3170); h->FUN_008f6d90(unk28.data, n * 4, 0x17); }

    vtable = (unsigned int)&DAT_00dcc494;
}
}   // namespace f3m_00904690

// @f3 0x00900320 (community match, verified in this file)
namespace f3m_00900320 {
namespace w900320 {
struct Descriptor { const char* name; Descriptor* parent; }; extern Descriptor DAT_010f31fc;
struct World;
struct Object { void** table; Descriptor* Type() { return ((Descriptor*(__thiscall*)(Object*))table[2])(this); }
 bool IsKindOf(Descriptor* kind) { for(Descriptor* d=Type();d;d=d->parent) if(d==kind) return true; return false; }
 Object* Cast() { return IsKindOf(&DAT_010f31fc)?this:0; }
 int FUN_008fc0f0(); void Release() { ((void(__thiscall*)(Object*))table[40])(this); } void Update(World* world) { ((void(__thiscall*)(Object*,World*))table[39])(this,world); }
};
struct Node { Object* item; Node* next; void FUN_008fa360(); };
struct World {};
struct Holder { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c; World* world; };
struct ConstraintSet {
    unsigned flags;
    Node head;
    bool IsSet() { return (flags >> 2) & 1; }
    __forceinline void Process(World* world, bool update) {
        if (world) {
            Node* n = &head;
            while (n) {
                Object* item = n->item;
                if (!item)
                    break;
                Object* target = item->Cast();
                if (target) {
                    if (target->FUN_008fc0f0()) {
                        target->Release();
                        head.FUN_008fa360();
                    } else if (update) {
                        n = n->next;
                        target->Update(world);
                    } else {
                        n = n->next;
                    }
                }
            }
            flags &= ~4;
        }
    }
};
struct Owner {
    int unk00, unk04, unk08, unk0c;
    ConstraintSet set;
    Holder* FUN_008f81f0();
    World* GetWorld() { Holder* holder = FUN_008f81f0(); return holder ? holder->world : 0; }
    void bhkRigidBody_UnFix(bool);
};
// pdb: bhkRigidBody::UnFix | bhkRigidBody.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
void Owner::bhkRigidBody_UnFix(bool update) {
    if (set.IsSet())
        set.Process(GetWorld(), update);
}
}
}   // namespace f3m_00900320

// @f3 0x00908ab0 (community match, verified in this file)
namespace f3m_00908ab0 {

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;

// One row of the thread memory's free lists.
struct FreeList908 {
    void* head;
    int numElem;
    __forceinline void put(void* p) {
        numElem++;
        *(void**)p = head;
        head = p;
    }
};

struct ThreadMemory908 {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30;
    int maxNumElemsOnFreeList;      // 0x34
    FreeList908 freeList[5];        // 0x38
    void FUN_008f6890(int row, void* p, int memClass);
    __forceinline void deallocateChunk(void* p, int row, int memClass) {
        if (freeList[row].numElem >= maxNumElemsOnFreeList)
            FUN_008f6890(row, p, memClass);
        else
            freeList[row].put(p);
    }
};

struct FUN_00908ab0;

// Membership in the global list of critical sections; leaving the list is its destructor.
struct Link908 {
    FUN_00908ab0* prev;
    FUN_00908ab0* next;
    __forceinline ~Link908();
};

// The critical section class; this file's function is its scalar deleting destructor.
struct FUN_00908ab0 {
    int DebugInfo, LockCount, RecursionCount, OwningThread, LockSemaphore, SpinCount;
    int currentThreadLow;       // 0x18
    int currentThreadHigh;      // 0x1c
    int unk20;
    Link908 link;               // 0x24
    void FUN_00908a00();
    __forceinline void leave() {
        currentThreadLow = -1;
        currentThreadHigh = -1;
        LeaveCriticalSection(this);
    }
    __forceinline ~FUN_00908ab0() { DeleteCriticalSection(this); }
    // pdb: hkpWorld::removeAll | hkpWorld.obj | tesv_win, call_gap, low
    static void operator delete(void* p) {
        if (p)
            static_cast<ThreadMemory908*>(TlsGetValue(DAT_010f3170))->deallocateChunk(p, 4, 0x15);
    }
};

extern FUN_00908ab0 DAT_011692e8;

__forceinline Link908::~Link908() {
    if (prev) {
        DAT_011692e8.FUN_00908a00();
        prev->link.next = next;
        if (next)
            next->link.prev = prev;
        DAT_011692e8.leave();
    }
}

void Release908(FUN_00908ab0* section) { delete section; }

}

// @f3 0x00906740 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_0116913c,DAT_010f3170;
extern const char DAT_00e34f78[],DAT_00e34f2c[],DAT_00e34f68[],DAT_00e34f58[],DAT_00e34f4c[],DAT_00e0811c[];
namespace f3m_00906740 {
namespace T2204 {
struct World;struct Entity;struct MotionState{};struct Shape;
struct Timer {const char*name;unsigned time,time2; __forceinline void setTime()throw(){unsigned ticks;
__asm {
rdtsc
mov dword ptr[ticks], eax
}
time=ticks;}};
struct NamedTimer:Timer{const char*first;};
struct Monitor {char*start;char*end;char*capacity;char*limit;__forceinline static Monitor& get()throw(){return *(Monitor*)TlsGetValue(DAT_0116913c);}__forceinline bool available()throw(){return end<limit;}};
struct Thread {
virtual void v00()throw();virtual void v04()throw();virtual void v08()throw();virtual void v0c()throw();virtual void v10()throw();virtual void* more(int)throw();virtual void release(void*)throw();
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
char* top;
unsigned int unk024;
void* last;
char* limit;
__forceinline static Thread& get()throw(){return *(Thread*)TlsGetValue(DAT_010f3170);}
void* FUN_008f6d30(int,int)throw();void FUN_008f6d90(void*,int,int)throw();
__forceinline void* allocStack(int bytes)throw(){int n=(bytes+16)&~15;char*p=top;if(p+n<=limit){top=p+n;return p;}return more(n);}
__forceinline void freeStack(void*p)throw(){top=(char*)p;if(p==last)release(p);}
};
void __cdecl FUN_00901e90(void*,int,int)throw();void __cdecl FUN_00901f10(void*,int)throw();
template<class T>struct Array{T*data;int count,capacity;Array()throw():data(0),count(0),capacity(0x80000000){}
__forceinline int cap()const throw(){return capacity&0x3fffffff;}T& operator[](int i)throw(){return data[i];}
__forceinline void reserve(int n)throw(){if(cap()<n){int twice=2*cap();if(n<twice)n=twice;FUN_00901e90(this,n,sizeof(T));}}
__forceinline void add(T x)throw(){if(count==cap())FUN_00901f10(this,sizeof(T));data[count++]=x;}
};
template<class T>struct OwnedArray:Array<T>{__forceinline ~OwnedArray()throw(){if((this->capacity&0x80000000)==0)Thread::get().FUN_008f6d90(this->data,this->cap()*sizeof(T),23);}};
template<class T> __forceinline void ReleaseStack(T*p)throw(){Thread::get().freeStack(p);}
template<class T>struct LocalArray:OwnedArray<T>{T*original;
__forceinline LocalArray()throw(){} __forceinline LocalArray(int n)throw(){reserveExactly(n);}
__forceinline void reserveExactly(int n)throw(){this->data=(T*)Thread::get().allocStack(n*sizeof(T));this->capacity=n|0x80000000;original=this->data;}
__forceinline ~LocalArray()throw(){ReleaseStack(original);}
__forceinline T*expand(int n)throw(){T*p=this->data+this->count;this->count+=n;return p;}
__forceinline void push(T x)throw(){this->data[this->count++]=x;}
};
struct Vec{float x,y,z,w;};struct Aabb{Vec min,max;};struct Pair{void*a;void*b;};
struct Shape{virtual void v00()throw();virtual void v04()throw();virtual void v08()throw();virtual void v0c()throw();virtual void v10()throw();virtual void v14()throw();virtual void v18()throw();virtual void getAabb(const MotionState&,float,Aabb&)const throw();};
struct Motion {
virtual ~Motion()throw();
unsigned char motionType,counter;unsigned short inactive0,inactive1,unk00a;
MotionState state;
};
struct Entity {
virtual void v00()throw();virtual void v04()throw();virtual void v08()throw();virtual void v0c()throw();virtual MotionState*getMotionState()throw();
unsigned int unk004;
World* world;
unsigned int unk00c;
Shape* shape;
unsigned int unk014;
MotionState* collidableMotion;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned volumeFlags;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned volumeSize;
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
unsigned uid;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
Motion motion;
__forceinline Motion*getMotion()throw(){return &motion;}
void FUN_009316e0()throw();void FUN_0090b280(World*,const Shape*)throw();
__forceinline void*handle()throw(){return &unk024;}
};
struct AllocHeader{void*v;unsigned short size;};
struct FUN_0098b4c0 {
virtual ~FUN_0098b4c0()throw();
unsigned short size;
unsigned short refs;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned short index;
unsigned short otherIndex;
unsigned char checkFrame;
bool sparse:2;bool flag1:2;bool flag2:2;bool flag3:2;
bool activeIndex:2;bool active:2;bool flag4:2;bool flag5:2;
unsigned char unk027;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
Array<Entity*> entities;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
FUN_0098b4c0(World*)throw();void FUN_0098aea0(Entity*)throw();
__forceinline static void*operator new(size_t n){AllocHeader*p=(AllocHeader*)Thread::get().FUN_008f6d30((int)n,50);p->size=(unsigned short)n;return p;}
static void operator delete(void*p)throw(){Thread::get().FUN_008f6d90(p,sizeof(FUN_0098b4c0),50);}
};
typedef FUN_0098b4c0 Island;
struct Broadphase {virtual void v00()throw();virtual void v04()throw();virtual void v08()throw();virtual void v0c()throw();virtual void v10()throw();virtual void v14()throw();virtual void update(Array<void*>&,Array<Aabb>&,Array<Pair>&)throw();};
struct Dispatcher{void FUN_00984c50(Pair*,int,const void*)throw();};
struct Info{unsigned unk;float tolerance;};
struct Filter{unsigned unk0,unk4;unsigned filterInterface;};
struct Op{unsigned char kind;Entity**entities;unsigned short count;unsigned char activation;Op()throw():kind(6){}};
void __cdecl FUN_00976bf0(float,float,MotionState&)throw();void __cdecl hkpWorldCallbackUtil_fireEntityAdded(World*,Entity*)throw();void __cdecl FUN_00987d30(Entity*)throw();
struct World{
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
Island* fixedIsland;
unsigned int unk024;
Array<Island*> activeIslands;
Array<Island*> inactiveIslands;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
Broadphase* broadphase;
Dispatcher* dispatcher;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
Info* info;
Filter* filter;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
int pending;
int locked;
unsigned int unk088;
bool blockPending;
unsigned char unk08d;
unsigned short unk08e;
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
bool useIslands;
unsigned char unk0b9;
unsigned short unk0ba;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned nextUid;
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
unsigned char unk2c4;
unsigned char worldFlag0;
unsigned char worldFlag1;
unsigned char worldCounter;
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
int pairCapacity;
void FUN_00902570(const Op&)throw();void FUN_00902550()throw();void hkpWorld_addEntityBatch(Entity*const*,int,int)throw();
// Synchronizes a motion's deactivation counters with the world's solver info (the select flags at 0x2c5/0x2c6
// and the integrate counter at 0x2c7). The counter is read into a local before the motion's counter, and the
// first comparison reads the member itself: written that way the masked world counter is computed first
// (edx) and the motion's second (ebx), as in the original; with the local in both comparisons the compiler
// computes the motion's mask first. A guess at the source shape.
__forceinline void syncCounters(Motion* mo)throw(){
    int c=worldCounter;
    int d=mo->counter;
    int f0=worldFlag0;
    int f1=worldFlag1;
    if(((unsigned)worldCounter%4)<((unsigned)d%4))f0=(~f0)<<14;else f0<<=14;
    if(c<d)f1=(~f1)<<14;else f1<<=14;
    mo->inactive0=(unsigned short)((mo->inactive0&0x3fff)|f0);
    mo->inactive1=(unsigned short)((mo->inactive1&0x3fff)|f1);
}
__forceinline void unlock()throw(){--locked;if(!locked&&!blockPending&&pending)FUN_00902550();}
};
// pdb: hkpWorld::addEntityBatch | hkpWorld.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void World::hkpWorld_addEntityBatch(Entity*const*entities,int count,int activation)throw(){
    if(count==0)return;
    if(locked){
        Op op;
        op.entities=const_cast<Entity**>(entities);
        op.count=(unsigned short)count;
        op.activation=(unsigned char)activation;
        FUN_00902570(op);
        return;
    }
    {Monitor&m=Monitor::get();if(m.available()){NamedTimer*h=(NamedTimer*)m.end;h->name=DAT_00e34f78;h->first=DAT_00e34f2c;h->setTime();m.end=(char*)(h+1);}}
    ++locked;
    LocalArray<void*>handles;
    handles.reserveExactly(count);
    LocalArray<Aabb>bounds;
    bounds.reserveExactly(count);
    bool used=false;
    Island*island;
    if(useIslands){
        island=new Island(this);
        island->sparse=true;
        if(activation==1){
            island->index=(unsigned short)activeIslands.count;
            island->activeIndex=true;
            island->active=true;
        }else{
            island->index=(unsigned short)inactiveIslands.count;
            island->activeIndex=false;
            island->active=false;
        }
    }
    else{
        island=activeIslands[0];
        island->entities.reserve(island->entities.count+count);
    }
    {
        float radius=(float)(0.5*info->tolerance);
        for(int i=0;i<count;++i){
            Entity*entity=entities[i];
            entity->uid=++nextUid;
            entity->FUN_009316e0();
            if(!entity->collidableMotion)entity->collidableMotion=entity->getMotionState();
            MotionState*ms=&entity->getMotion()->state;
            FUN_00976bf0(0,0,*ms);
            entity->getMotion()->inactive0=0;
            entity->getMotion()->inactive1=0;
            entity->world=this;
            syncCounters(entity->getMotion());
            if(entity->getMotion()->motionType==7)fixedIsland->FUN_0098aea0(entity);
            else{used=true;island->FUN_0098aea0(entity);}
            const Shape*shape=entity->shape;
            if(shape){
                Aabb*aabb=bounds.expand(1);
                entity->shape->getAabb(*entity->collidableMotion,radius,*aabb);
                handles.push(entity->handle());
                entity->FUN_0090b280(this,shape);
            }
            entity->volumeFlags=1;
            entity->volumeSize=0;
        }
    }
    if(useIslands){
        if(used){
            island->checkFrame=(unsigned char)island->entities[0]->uid;
            Array<Island*>&list=activation==1?activeIslands:inactiveIslands;
            list.add(island);
        }else delete island;
    }
    LocalArray<Pair>pairs(pairCapacity);
    {Monitor&m=Monitor::get();if(m.available()){Timer*h=(Timer*)m.end;h->name=DAT_00e34f68;h->setTime();m.end=(char*)(h+1);}}
    broadphase->update(handles,bounds,pairs);
    {Monitor&m=Monitor::get();if(m.available()){Timer*h=(Timer*)m.end;h->name=DAT_00e34f58;h->setTime();m.end=(char*)(h+1);}}
    dispatcher->FUN_00984c50(pairs.data,pairs.count,filter?&filter->filterInterface:0);
    {Monitor&m=Monitor::get();if(m.available()){Timer*h=(Timer*)m.end;h->name=DAT_00e34f4c;h->setTime();m.end=(char*)(h+1);}}
    for(int j=0;j<count;++j){
        Entity*entity=entities[j];
        hkpWorldCallbackUtil_fireEntityAdded(this,entity);
        FUN_00987d30(entity);
    }
    unlock();
    {Monitor&m=Monitor::get();if(m.available()){Timer*h=(Timer*)m.end;h->name=DAT_00e0811c;h->setTime();m.end=(char*)(h+1);}}
}
}

}   // namespace f3m_00906740

// @f3 0x0091dbd0 (community match, verified in this file)
namespace f3m_0091dbd0 {
namespace p91dbd0 {
struct Vec3 {
    float x, y, z;
    float Dot(const Vec3& o) const { const double px = static_cast<double>(x) * o.x; const double py = static_cast<double>(y) * o.y; const double pz = static_cast<double>(z) * o.z; return (px + py) + pz; }
};
struct Plane {
    int unk00;
    int unk04;
    int unk08;
    float saved;
    Vec3 n;
    float d;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    void __stdcall FUN_0091dbd0(int count, const Vec3* v);
};
}

void __stdcall p91dbd0::Plane::FUN_0091dbd0(int count, const p91dbd0::Vec3* v)
{
    p91dbd0::Plane* p = this;
    for (int i = count; --i >= 0; ) {
        p->saved = p->d;
        float d = p->saved;
        float dot = p->n.Dot(*v);
        p->d = d * -dot;
        ++p;
    }
}




}   // namespace f3m_0091dbd0

// @f3 0x009186d0 (community match, verified in this file)
#include <math.h>
extern const float DAT_00de6e70 = 1.1920928955078125e-7f;
extern float DAT_010f3304;
extern float DAT_010f3310;
extern const float DAT_01011d78 = 0.0f;
extern const float DAT_01012068 = 1.0f;
namespace f3m_009186d0 {
// Closest build uses /MT /O2 /GS /EHsc /Gy; the pack lists /Od /Oy-.
namespace physics3132 {
extern __int64 __cdecl FUN_0086c140();
extern void __cdecl FUN_00901e90(void*, int, int);
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline void grow(int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int doubled = 2 * cap;
            int wanted = n < doubled ? doubled : n;
            FUN_00901e90(this, wanted, sizeof(T));
        }
    }
    __forceinline void reserveExact(int n)
    {
        if (getCapacity() < n)
        {
            int doubled = 2 * getCapacity();
            int wanted = n < doubled ? doubled : n;
            FUN_00901e90(this, wanted, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        grow(n);
        size = n;
    }
    __forceinline void setSizeZero(int n)
    {
        grow(n);
        int remaining = n - size;
        T* out = data + size;
        for (int k = 0; k < remaining; ++k)
            *out++ = 0;
        size = n;
    }
};
template <class T> struct WorkArray : ArrayBase<T>
{
    ~WorkArray();
    __forceinline void reserve(int n)
    {
        reserveExact(n);
    }
    __forceinline void resize(int n)
    {
        SetSizeAndGrow(n);
    }
    __forceinline void resizeZero(int n)
    {
        setSizeZero(n);
    }
};
struct SkeletonBone;
struct Transform;
struct Skeleton {
    unsigned int unk00, unk04, unk08;
    ArrayBase<SkeletonBone> bones;
    unsigned int unk18;
    ArrayBase<char*> slots;
};
typedef float ScalarValue;
inline float rootValue(float n) { return sqrtf(n); }
inline float reciprocalRoot(float n) { return 1.0f/rootValue(n); }
struct __declspec(align(16)) VectorValue {
    float x,y,z,w;
    VectorValue() {}
    VectorValue(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
    VectorValue(const VectorValue& v):x(v.x),y(v.y),z(v.z),w(v.w) {}
    void operator=(const VectorValue& v) { x=v.x;y=v.y;z=v.z;w=v.w; }
    // Fake match: this intermediate preserves the target's x87 operand scheduling.
    __forceinline float dot(const VectorValue& v) const { double yy=y*v.y; return x*v.x+yy+z*v.z; }
    __forceinline float length() const { float n=x*x+y*y+z*z; return rootValue(n); }
    __forceinline float inverseLength() const { float n=x*x+y*y+z*z; return n ? reciprocalRoot(n) : 0; }
    __forceinline void multiply(float amount) { float n=amount; x*=n;y*=n;z*=n;w*=n; }
    __forceinline void normalize() { multiply(inverseLength()); }
    __forceinline void scale(float amount,const VectorValue& v) { float n=amount; x=n*v.x;y=n*v.y;z=n*v.z;w=n*v.w; }
};
struct Contact
{
    short bone;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    VectorValue point, direction;
};
struct Transform
{
    VectorValue position, rotation, scale;
};
struct FUN_00c7c030
{
    Skeleton* skeleton;
    WorkArray<Transform> localFUN_00c7c030, modelFUN_00c7c030;
    WorkArray<int> flags;
    bool modelSync, localSync;
    WorkArray<float> floats;
    __forceinline FUN_00c7c030(Skeleton* s) : skeleton(s), modelSync(false), localSync(false)
    {
        int n = skeleton->bones.GetLogicalSize();
        modelFUN_00c7c030.reserve(n);
        modelFUN_00c7c030.size = n;
        localFUN_00c7c030.resize(n);
        flags.resize(n);
        floats.resize(skeleton->slots.GetLogicalSize());
    }
    ~FUN_00c7c030();
    ArrayBase<Transform>& FUN_00954fc0();
};
struct BodyHeader
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
    virtual void apply(const VectorValue*, const VectorValue*);
    unsigned int unk04;
    unsigned char type;
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
};
struct Body : BodyHeader
{
    VectorValue position;
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
    VectorValue linearVelocity;
    VectorValue angularVelocity;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    float FUN_008f8410();

};
struct Properties
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct Meta
{
    unsigned int unk00, unk04, unk08, unk0c;
    Properties props;
};
struct Wrapper
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
    virtual void vbc();
    virtual void refresh();
    unsigned int unk04;
    Meta* meta;
    void FUN_00a29680();
    inline Properties* getProps()
    {
        if (!this)
            return 0;
        return meta ? &meta->props : 0;
    }
    inline unsigned int GetPropertyFlags()
    {
        Properties* p = getProps();
        return p ? p->flags : 0;
    }
    inline void setFlags(unsigned int value)
    {
        if (!this)
            return;
        Meta* m = meta;
        if (m)
        {
            Properties* props = &m->props;
            if (props)
                props->flags = value;
        }
    }
    inline void changeFlag(bool set)
    {
        unsigned int f = GetPropertyFlags();
        if (((unsigned char)(f >> 14) & 1) != set)
        {
            setFlags(set ? f | 0x4000 : f & ~0x4000);
            refresh();
        }
    }
};
struct World {
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
    void* context;
};
struct Bone
{
    unsigned int unk00;
    unsigned int unk04;
    World* world;
    Wrapper* wrapper;
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
    Body body;
    inline Wrapper* getWrapper() const { return wrapper; }
    void FUN_0090b500();
    void FUN_00917120(const VectorValue&, VectorValue&) const;
};
struct Rig
{
    unsigned int unk00;
    unsigned int unk04;
    ArrayBase<Bone*> bones;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    ArrayBase<int> boneMap;
    Skeleton* skeleton;
    void FUN_00960c70(Transform*);
    inline Skeleton* getSkeleton() const
    {
        return skeleton;
    }
    inline int getNumBones() const
    {
        return skeleton->bones.GetLogicalSize();
    }
    inline const ArrayBase<Bone*>& getBodies() const
    {
        return bones;
    }
    inline Bone* getBone(int n)
    {
        int index = boneMap[n];
        return index >= 0 ? bones[index] : 0;
    }
    inline World* getWorld()
    {
        Bone* root = bones[0];
        return root ? root->world : 0;
    }
};
struct ByteBoolean
{
    unsigned char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct Controller
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    WorkArray<int> states;
    inline const ArrayBase<int>& getStates() const
    {
        return states;
    }
    void FUN_009a0f30();
    ByteBoolean FUN_009a1000(FUN_00c7c030&, WorkArray<Contact>&);
};
struct Observer
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
    virtual World* getWorld();
    virtual void setWorld(void*);
};
struct Entry
{
    unsigned int unk00;
    Rig* rig;
    unsigned int unk08;
    Observer* observer;
    Controller* controller;
    WorkArray<Contact> contacts;
    bool active;
};
struct EntryListNode
{
    unsigned int capacity;
    Entry** data;
    unsigned int size;
    inline unsigned int GetLogicalSize() const
    {
        return size;
    }
    __forceinline Entry*& operator[](unsigned int i)
    {
        // Fake match: the index copy preserves operand and temporary ordering.
        unsigned int at=i; return data[at];
    }
};
struct UpdateManager
{
    unsigned int unk00;
    EntryListNode entries;
    unsigned int unk10, unk14, unk18, unk1c;
    __int64 startTime, duration;
    void FUN_009186d0();
};
// @fnv 0x00ca1410
// pdb: bhkRagdollPenetrationUtil::Update | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap, low
void UpdateManager::FUN_009186d0()
{
    for (unsigned int i = 0; i < entries.GetLogicalSize(); ++i)
    {
        Entry* entry = entries[i];
        Rig* rig = entry->rig;
        bool excluded = false;
        for (int k = 0; k < rig->bones.GetLogicalSize() && !excluded; ++k)
        {
            unsigned char type = rig->bones[k]->body.type;
            excluded = type == 6 || type == 7;
        }
        if (rig->getWorld() && !excluded && (entry->active || FUN_0086c140() - startTime <= duration))
        {
            if (FUN_0086c140() - startTime <= duration || entries[i]->active)
                entries[i]->controller->FUN_009a0f30();
            FUN_00c7c030 pose(entries[i]->rig->getSkeleton());
            entries[i]->rig->FUN_00960c70(pose.FUN_00954fc0().begin());
            if (entries[i]->rig->getWorld() != entries[i]->observer->getWorld())
            {
                World* w = entries[i]->rig->getWorld();
                entries[i]->observer->setWorld(w ? w->context : 0);
            }
            bool wasActive = entries[i]->active;
            entries[i]->active = entries[i]->controller->FUN_009a1000(pose, entries[i]->contacts);
            int j;
            if (entries[i]->active)
            {
                const ArrayBase<int>& states = entries[i]->controller->getStates();
                for (j = 0; j < entries[i]->rig->getNumBones(); ++j)
                {
                    Bone* bone = entries[i]->rig->getBone(j);
                    Wrapper* wrapper;
                    if (bone && (wrapper = bone->wrapper))
                    {
                        if (states[j])
                        {
                            wrapper->changeFlag(true);
                            if (states[j] == 1)
                            {
                                VectorValue position(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_01011d78);
                                VectorValue direction(DAT_01011d78, DAT_01011d78, DAT_01012068, DAT_01011d78);
                                for (int k = 0; k < entries[i]->contacts.GetLogicalSize(); ++k)
                                {
                                    if (j == entries[i]->contacts[k].bone)
                                    {
                                        position = entries[i]->contacts[k].point;
                                        direction = entries[i]->contacts[k].direction;
                                    }
                                }
                                VectorValue velocity;
                                bone->FUN_00917120(position, velocity);
                                float speed = velocity.length();
                                float projection;
                                if (speed > DAT_00de6e70)
                                {
                                    velocity.normalize();
                                    projection = direction.dot(velocity);
                                }
                                else
                                    projection = 0;
                                float mass = bone->body.FUN_008f8410();
                                float impulse = mass * (DAT_010f3304 - projection * speed);
                                impulse = impulse > DAT_010f3310 ? DAT_010f3310 : impulse;
                                impulse = impulse < -DAT_010f3310 ? -DAT_010f3310 : impulse;
                                VectorValue force;
                                force.scale(ScalarValue(impulse), direction);
                                bone->FUN_0090b500();
                                bone->body.apply(&force, &position);
                            }
                        }
                        else
                            bone->wrapper->changeFlag(false);
                    }
                }
            }
            else if (wasActive)
            {
                entries[i]->controller->FUN_009a0f30();
                for (j = 0; j < entries[i]->rig->getNumBones(); ++j)
                {
                    Bone* bone = entries[i]->rig->getBone(j);
                    if (bone && bone->wrapper)
                        bone->wrapper->changeFlag(false);
                }
            }
        }
        else
        {
            if (entries[i]->rig->getWorld())
                entries[i]->controller->FUN_009a0f30();
        }
    }
}

}  // namespace physics3132

}   // namespace f3m_009186d0

// @f3 0x0091e6a0 (community match, verified in this file)
namespace f3m_0091e6a0 {
// Havok 5.5 (x87 build of the math library) hkpCharacterProxy::applySurfaceInteractions.
// Stand-in types; unknown fields are named by offset.

typedef float hkReal;
// FPU build: the scalar of the vector operations is a one-float class passed by const reference
struct hkSimdReal
{
    hkReal m_real;
    __forceinline hkSimdReal() {}
    __forceinline hkSimdReal(hkReal x) : m_real(x) {}
    __forceinline operator hkReal() const { return m_real; }
    __forceinline hkReal getReal() const { return m_real; }
};
typedef const hkSimdReal& hkSimdRealParameter;

struct hkMatrix3;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void sub4(const hkVector4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    // this = r * a
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a)
    {
        hkReal rr = r.getReal();
        x = rr * a.x;
        y = rr * a.y;
        z = rr * a.z;
        w = rr * a.w;
    }
    // this += r * a
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a)
    {
        hkReal rr = r.getReal();
        x += rr * a.x;
        y += rr * a.y;
        z += rr * a.z;
        w += rr * a.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // The same dot product with only the x product grouped. The original computes the x product first at the
    // rc.dot3(jacAng) site and the y product first at the other two; this spelling reproduces that. Which Havok
    // spelling the original used there is a guess.
    __forceinline hkReal dot3x(const hkVector4& a) const
    {
        return (x * a.x) + y * a.y + z * a.z;
    }
    void FUN_008d2a80(const hkMatrix3& m, const hkVector4& v);   // setMul3
};

struct __declspec(align(16)) hkMatrix3
{
    hkVector4 m_col0, m_col1, m_col2;
};

struct hkStepInfo
{
    hkReal m_startTime;
    hkReal m_endTime;
    hkReal m_deltaTime;
    hkReal m_invDeltaTime;
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
    __forceinline const hkVector4& getPosition() const { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline hkReal getDistance() const { return m_separatingNormal.w; }
};

struct hkpPropertyValue
{
    unsigned int m_data;
    unsigned int m_dataHi;
    __forceinline void* getPtr() const { return (void*)m_data; }
};

struct hkpProperty
{
    unsigned int m_key;
    unsigned int m_alignmentPadding;
    hkpPropertyValue m_value;
};

struct hkpCollidable
{
    void* m_shape;
    unsigned int m_shapeKey;
    void* m_motion;
    hkpCollidable* m_parent;
    signed char m_ownerOffset;
    unsigned char m_forceCollideOntoPpu;
    unsigned short m_shapeSizeOnSpu;
    unsigned int m_broadPhaseId;
    signed char m_type;
    signed char m_broadPhaseOwnerOffset;
    unsigned short m_objectQualityType;
    unsigned int m_collisionFilterInfo;
    __forceinline void* getOwner() const { return (void*)((char*)this + m_ownerOffset); }
    __forceinline int getType() const { return m_type; }
};

struct hkBaseObject
{
    virtual ~hkBaseObject();
};

struct hkReferencedObject : hkBaseObject
{
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
};

struct hkpMotion : hkReferencedObject
{
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
    unsigned char m_type;
    unsigned char m_deactivationIntegrateCounter;
    unsigned short m_deactivationNumInactiveFrames0;
    unsigned int m_unk0c;
    hkVector4 m_transformRotation0;
    hkVector4 m_transformRotation1;
    hkVector4 m_transformRotation2;
    hkVector4 m_transformTranslation;
    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkVector4 m_rotation0;
    hkVector4 m_rotation1;
    hkVector4 m_centerOfMassLocal;
    hkVector4 m_deltaAngle;
    hkReal m_objectRadius;
    hkReal m_linearDamping;
    hkReal m_angularDamping;
    unsigned int m_unkbc;
    hkVector4 m_inertiaAndMassInv;
    hkVector4 m_linearVelocity;
    hkVector4 m_angularVelocity;
};

struct hkpRigidBody
{
    void* m_vtable;
    unsigned int m_memSizeAndFlags;
    void* m_world;
    unsigned int m_userData;
    hkpCollidable m_collidable;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3c;
    unsigned int m_unk40;
    unsigned int m_unk44;
    unsigned int m_unk48;
    unsigned int m_unk4c;
    unsigned int m_unk50;
    unsigned int m_unk54;
    unsigned int m_unk58;
    unsigned int m_unk5c;
    unsigned int m_unk60;
    unsigned int m_unk64;
    unsigned int m_unk68;
    unsigned int m_unk6c;
    unsigned int m_unk70;
    hkpProperty* m_properties;
    int m_propertiesSize;
    int m_propertiesCapacity;
    unsigned int m_unk80;
    unsigned int m_unk84;
    unsigned int m_unk88;
    unsigned int m_unk8c;
    unsigned int m_unk90;
    unsigned int m_unk94;
    unsigned int m_unk98;
    unsigned int m_unk9c;
    unsigned int m_unka0;
    unsigned int m_unka4;
    unsigned int m_unka8;
    unsigned int m_unkac;
    unsigned int m_unkb0;
    unsigned int m_unkb4;
    unsigned int m_unkb8;
    unsigned int m_unkbc;
    unsigned int m_unkc0;
    unsigned int m_unkc4;
    unsigned int m_unkc8;
    unsigned int m_unkcc;
    hkpMotion m_motion;

    __forceinline bool hasProperty(unsigned int key) const
    {
        for (int i = 0; i < m_propertiesSize; ++i)
        {
            if (m_properties[i].m_key == key)
                return true;
        }
        return false;
    }
    hkpPropertyValue FUN_00477900(unsigned int key) const;                         // getProperty
    void FUN_00917120(const hkVector4& p, hkVector4& vecOut) const;               // getPointVelocity
    void FUN_0090b500();                                                          // activate
    __forceinline bool isFixedOrKeyframed() const { return m_motion.m_type == 7 || m_motion.m_type == 6; }
    __forceinline void getInertiaInvWorld(hkMatrix3& out) const { m_motion.getInertiaInvWorld(out); }
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return m_motion.m_centerOfMass1; }
    __forceinline hkReal getMassInv() const { return m_motion.m_inertiaAndMassInv.w; }
    __forceinline void applyPointImpulse(const hkVector4& imp, const hkVector4& p)
    {
        FUN_0090b500();
        m_motion.applyPointImpulse(imp, p);
    }
};

__forceinline hkpRigidBody* hkGetRigidBody(const hkpCollidable* collidable)
{
    if (collidable->getType() == 1)
        return (hkpRigidBody*)collidable->getOwner();
    return 0;
}

struct hkpRootCdPoint
{
    hkContactPoint m_contact;
    void* m_rootCollidableA;
    unsigned int m_shapeKeyA;
    hkpCollidable* m_rootCollidableB;
    unsigned int m_shapeKeyB;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3c;
};

struct hkpCharacterProxy;

struct __declspec(align(16)) hkpCharacterObjectInteractionEvent
{
    hkVector4 m_position;
    hkVector4 m_normal;
    hkReal m_objectImpulse;
    hkReal m_timestep;
    hkReal m_projectedVelocity;
    hkReal m_objectMassInv;
    hkpRigidBody* m_body;
};

struct __declspec(align(16)) hkpCharacterObjectInteractionResult
{
    hkVector4 m_objectImpulse;
    hkVector4 m_impulsePosition;
};

struct hkpCharacterProxyListener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void characterInteractionCallback(hkpCharacterProxy* proxy, hkpCharacterProxy* otherProxy, const hkContactPoint& contact);
    virtual void objectInteractionCallback(hkpCharacterProxy* proxy, const hkpCharacterObjectInteractionEvent& input, hkpCharacterObjectInteractionResult& output);
};

template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline int getSize() const { return m_size; }
};

struct hkpCharacterProxy
{
    unsigned int m_vtable;
    unsigned int m_memSizeAndFlags;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    hkVector4 m_velocity;
    hkVector4 m_oldDisplacement;
    unsigned int m_unk30;
    hkReal m_dynamicFriction;
    hkReal m_staticFriction;
    unsigned int m_unk3c;
    hkVector4 m_up;
    hkReal m_extraUpStaticFriction;
    hkReal m_extraDownStaticFriction;
    hkReal m_keepDistance;
    hkReal m_keepContactTolerance;
    hkReal m_contactAngleSensitivity;
    int m_userPlanes;
    hkReal m_maxCharacterSpeedForSolver;
    hkReal m_characterStrength;
    hkReal m_characterMass;
    hkArray<hkpRootCdPoint> m_manifold;
    hkArray<hkpCharacterProxyListener*> m_listeners;

    void FUN_0091e6a0(const hkStepInfo& stepInfo, const hkVector4& worldGravity);
};

// pdb: hkpCharacterProxy::applySurfaceInteractions | hkpCharacterProxy.obj | fnv360_0721_beta, objrun, medium, conflict (bridge: hkSimplexSolverSolve)
// pdb params: stepInfo, worldGravity, command, maxInteractions
void hkpCharacterProxy::FUN_0091e6a0(const hkStepInfo& stepInfo, const hkVector4& worldGravity)
{
    hkpCharacterObjectInteractionEvent input;
    input.m_timestep = stepInfo.m_deltaTime;

    for (int s = 0; s < m_manifold.getSize(); s++)
    {
        // Check if we have hit another character
        {
            hkpRigidBody* object = (hkpRigidBody*)m_manifold[s].m_rootCollidableB->getOwner();
            if (object->hasProperty(0x1300))   // HK_PROPERTY_CHARACTER_PROXY
            {
                hkpPropertyValue property = object->FUN_00477900(0x1300);
                for (int i = m_listeners.getSize() - 1; i >= 0; i--)
                {
                    if (m_listeners[i] != 0)
                        m_listeners[i]->characterInteractionCallback(this, (hkpCharacterProxy*)property.getPtr(), m_manifold[s].m_contact);
                }
            }
        }

        // Check if we have hit a rigid body
        {
            hkpRigidBody* body = hkGetRigidBody(m_manifold[s].m_rootCollidableB);
            if ((body != 0) && (!body->isFixedOrKeyframed()))
            {
                const hkReal recoveryTau = 0.4f;
                const hkReal dampFactor = 0.9f;
                input.m_position = m_manifold[s].m_contact.getPosition();
                input.m_position(3) = m_manifold[s].m_contact.getDistance();
                input.m_normal = m_manifold[s].m_contact.getNormal();
                input.m_body = body;

                // Calculate required velocity change
                hkReal deltaVelocity;
                {
                    hkVector4 pointVel; body->FUN_00917120(input.m_position, pointVel);
                    pointVel.sub4(m_velocity);
                    input.m_projectedVelocity = pointVel.dot3(input.m_normal);
                    deltaVelocity = -input.m_projectedVelocity * dampFactor;
                    // Only apply an extra impulse if the collision is actually penetrating
                    if (input.m_position(3) < 0)
                        deltaVelocity += input.m_position(3) * stepInfo.m_invDeltaTime * recoveryTau;
                }

                // Initialize the output result
                hkpCharacterObjectInteractionResult output;
                output.m_impulsePosition = input.m_position;
                output.m_objectImpulse.setZero4();

                if (deltaVelocity < 0.0f)
                {
                    // Calculate the impulse required
                    {
                        hkMatrix3 inertiaInv;
                        body->getInertiaInvWorld(inertiaInv);
                        hkVector4 r; r.setSub4(input.m_position, body->getCenterOfMassInWorld());
                        hkVector4 jacAng; jacAng.setCross(r, input.m_normal);
                        hkVector4 rc; rc.FUN_008d2a80(inertiaInv, jacAng);
                        input.m_objectMassInv = rc.dot3x(jacAng);
                        input.m_objectMassInv += body->getMassInv();
                        input.m_objectImpulse = deltaVelocity / input.m_objectMassInv;
                    }
                    hkReal maxPushImpulse = -m_characterStrength * stepInfo.m_deltaTime;
                    if (input.m_objectImpulse < maxPushImpulse)
                        input.m_objectImpulse = maxPushImpulse;
                    output.m_objectImpulse.setMul4(input.m_objectImpulse, input.m_normal);
                }
                else
                {
                    input.m_objectImpulse = 0.0f;
                    input.m_objectMassInv = body->getMassInv();
                }

                // Add gravity
                {
                    hkReal deltaTime = stepInfo.m_deltaTime;
                    hkVector4 charVelDown; charVelDown.setMul4(deltaTime, worldGravity);
                    // Normal points from object to character
                    hkReal relVel = charVelDown.dot3(input.m_normal);
                    if (input.m_projectedVelocity < 0)   // if objects are separating
                        relVel -= input.m_projectedVelocity;
                    if (relVel < -1.192092896e-07f)      // -HK_REAL_EPSILON
                        output.m_objectImpulse.addMul4(relVel * m_characterMass, input.m_normal);
                }

                // Callback to allow user to change impulse + use the info / play sounds
                for (int i = m_listeners.getSize() - 1; i >= 0; i--)
                {
                    if (m_listeners[i] != 0)
                        m_listeners[i]->objectInteractionCallback(this, input, output);
                }

                // Apply impulse based on callback result
                body->applyPointImpulse(output.m_objectImpulse, output.m_impulsePosition);
            }
        }
    }
}
}   // namespace f3m_0091e6a0

// @f3 0x0091fe80 (community match, verified in this file)
#include <math.h>
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern const char DAT_00e36998[];
extern const char DAT_00e32798[];
extern const float DAT_00e32888;
namespace f3m_0091fe80 {

extern "C" {
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
}

struct hkBool
{
    char m_bool;

    __forceinline hkBool() {}
    __forceinline hkBool(bool b)
    {
        m_bool = (char)b;
    }
    __forceinline operator bool() const
    {
        return m_bool != 0;
    }
};

static __forceinline float hkFabs(float r)
{
    return (float)fabs(r);
}

static __forceinline float hkSqrt(float r)
{
    return (float)sqrt(r);
}
static __forceinline float hkSqrtInverse(float r)
{
    return 1.0f / hkSqrt(r);
}

struct hkVector4Comparison
{
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };

    int m_mask;

    __forceinline hkBool allAreSet(Mask m) const
    {
        return (m_mask & m) == m;
    }
};

struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal(float x) : m_real(x) {}
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline hkVector4() {}
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setAll3(float a) { x = a; y = a; z = a; w = a; }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline float lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
    __forceinline float lengthInverse3() const { float l2 = lengthSquared3(); return l2 ? hkSqrtInverse(l2) : 0; }
    __forceinline void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    __forceinline void mul4(hkSimdReal rs) { float s = rs; x *= s; y *= s; z *= s; w *= s; }
    __forceinline void addMul4(float r, const hkVector4& a) { x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void setAbs4(const hkVector4& v) { x = hkFabs(v.x); y = hkFabs(v.y); z = hkFabs(v.z); w = hkFabs(v.w); }
    __forceinline hkVector4Comparison compareLessThanEqual4(const hkVector4& a) const
    {
        hkVector4Comparison ret;
        ret.m_mask = ((x <= a.x) ? hkVector4Comparison::MASK_X : 0) | ((y <= a.y) ? hkVector4Comparison::MASK_Y : 0) | ((z <= a.z) ? hkVector4Comparison::MASK_Z : 0) | ((w <= a.w) ? hkVector4Comparison::MASK_W : 0);
        return ret;
    }
    __forceinline hkBool equals3(const hkVector4& v, float epsilon) const
    {
        hkVector4 t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        int mx = t.x <= epsilon ? hkVector4Comparison::MASK_X : 0;
        int my = t.y <= epsilon ? hkVector4Comparison::MASK_Y : 0;
        int mz = t.z <= epsilon ? hkVector4Comparison::MASK_Z : 0;
        int mw = t.w <= epsilon ? hkVector4Comparison::MASK_W : 0;
        hkVector4Comparison cmp;
        cmp.m_mask = mx | my | mz | mw;
        return cmp.allAreSet(hkVector4Comparison::MASK_XYZ);
    }
};
struct hkMonitorStream
{
    struct TimerCommand
    {
        const char* m_commandAndMonitor;
        unsigned int m_time0;
        unsigned int m_time1;

        __forceinline void setTime()
        {
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    static __forceinline hkMonitorStream& getInstance()
    {
        return *(hkMonitorStream*)TlsGetValue(DAT_0116913c);
    }
    __forceinline hkBool memoryAvailable()
    {
        return m_end < m_capacityMinus16;
    }
};

static __forceinline void hkTimerBegin(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (mStream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end;
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end = (char*)(h + 1);
    }
}

class hkThreadMemory
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCurrent;
    char* m_stackPrev;
    char* m_stackBase;
    char* m_stackEnd;

    void FUN_008f6d90(void* p, int nbytes, int cls);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 16) & ~15;
        char* current = m_stackCurrent;
        if (current + nbytes <= m_stackEnd)
        {
            m_stackCurrent = current + nbytes;
            return current;
        }
        return onStackOverflow(nbytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCurrent = (char*)p;
        if (p == m_stackBase)
        {
            onStackUnderflow(p);
        }
    }
};

void __cdecl FUN_00901e90(void* array, int numElem, int sizeElem);
void __cdecl FUN_00901f10(void* array, int sizeElem);

template <typename T>
class hkArray
{
  public:
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    __forceinline int getSize() const
    {
        return m_size;
    }
    __forceinline int getCapacity() const
    {
        return m_capacityAndFlags & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    __forceinline void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        m_size = n;
    }
    __forceinline T& expandOne()
    {
        if (m_size == getCapacity())
        {
            FUN_00901f10(this, sizeof(T));
        }
        return m_data[m_size++];
    }
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
static __forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

template <typename T>
class hkLocalArray : public hkArray<T>
{
  public:
    __forceinline hkLocalArray(int n)
    {
        this->m_data = (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
        this->m_capacityAndFlags = n | hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_localMemory = this->m_data;
    }
    __forceinline void destruct()
    {
        hkDeallocateStack(m_localMemory);
        this->releaseMemory();
    }

    T* m_localMemory;
};

struct hkpSurfaceConstraintInfo
{
    hkVector4 m_plane;
    hkVector4 m_velocity;
    float m_staticFriction;
    float m_extraUpStaticFriction;
    float m_extraDownStaticFriction;
    float m_dynamicFriction;
    int m_priority;

    hkpSurfaceConstraintInfo& operator=(const hkpSurfaceConstraintInfo& other);
};

struct hkSurfaceConstraintInteraction
{
    unsigned char m_touched;
    unsigned char m_stopped;
    float m_surfaceTime;
    float m_penaltyDistance;
    int m_status;
};

struct hkSimplexSolverInput
{
    __forceinline hkSimplexSolverInput()
    {
        m_position.setZero4();
    }
    hkVector4 m_position;
    hkVector4 m_velocity;
    hkVector4 m_maxSurfaceVelocity;
    hkVector4 m_upVector;
    float m_deltaTime;
    float m_minDeltaTime;
    hkpSurfaceConstraintInfo* m_constraints;
    int m_numConstraints;
};

struct hkSimplexSolverOutput
{
    hkVector4 m_position;
    hkVector4 m_velocity;
    float m_deltaTime;
    hkSurfaceConstraintInteraction* m_planeInteractions;
};

void __cdecl FUN_009a5ae0(const hkSimplexSolverInput& input, hkSimplexSolverOutput& output);

struct hkpSurfaceInfo
{
    enum SupportedState
    {
        UNSUPPORTED = 0,
        SLIDING = 1,
        SUPPORTED = 2
    };
    SupportedState m_supportedState;
    hkVector4 m_surfaceNormal;
    hkVector4 m_surfaceVelocity;
};

struct hkpRootCdPoint
{
    hkVector4 m_position;
    hkVector4 m_normal;
    void* m_rootCollidableA;
    int m_shapeKeyA;
    void* m_rootCollidableB;
    int m_shapeKeyB;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

class hkpAllCdPointCollector;
class hkpShapePhantom;

// hkpCharacterProxy::addMaxSlopePlane (static, FNV FUN_00cadca0)
static __declspec(noinline) bool addMaxSlopePlane(float maxSlopeCos, const hkVector4& up, int index, hkArray<hkpSurfaceConstraintInfo>& surfaceConstraintsInOut)
{
    const float surfaceVerticalComponent = surfaceConstraintsInOut[index].m_plane.dot3(up);
    if (surfaceVerticalComponent > 0.01f && surfaceVerticalComponent < maxSlopeCos)
    {
        hkpSurfaceConstraintInfo& newConstraint = surfaceConstraintsInOut.expandOne();
        newConstraint = surfaceConstraintsInOut[index];
        newConstraint.m_plane.addMul4(-surfaceVerticalComponent, up);
        newConstraint.m_plane.normalize3();
        return true;
    }
    return false;
}

class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject();
    int m_memSizeAndFlags;
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

class hkpCharacterProxy : public hkReferencedObject, public hkpEntityListener, public hkpPhantomListener
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void updateManifold(hkpAllCdPointCollector& startPointCollector, hkpAllCdPointCollector& castCollector);
    virtual void getSurfaceConstraintInfo(const hkpRootCdPoint& point, hkpSurfaceConstraintInfo& surface, float timeTravelled) const;

    hkVector4 m_velocity;
    hkVector4 m_oldDisplacement;
    hkpShapePhantom* m_shapePhantom;
    float m_dynamicFriction;
    float m_staticFriction;
    int unk3c;
    hkVector4 m_up;
    float m_extraUpStaticFriction;
    float m_extraDownStaticFriction;
    float m_keepDistance;
    float m_keepContactTolerance;
    float m_contactAngleSensitivity;
    int m_userPlanes;
    float m_maxCharacterSpeedForSolver;
    float m_characterStrength;
    float m_characterMass;
    hkArray<hkpRootCdPoint> m_manifold;
    hkArray<void*> m_bodies;
    hkArray<void*> m_phantoms;
    hkArray<void*> m_listeners;
    float m_maxSlopeCosine;
    float m_penetrationRecoverySpeed;
    int m_maxCastIterations;
    bool m_refreshManifoldInCheckSupport;

    void FUN_0091fdb0(hkpAllCdPointCollector& startPointCollector);
    void FUN_0091ec20(const hkArray<hkpRootCdPoint>& manifold, hkSimplexSolverInput& input);
    void FUN_0091fe80(const hkVector4& direction, hkpSurfaceInfo& ground, hkpAllCdPointCollector& startPointCollector);
};


// hkpCharacterProxy::checkSupport (FNV FUN_00cae900)
// STEERING SPELLINGS: the match depends on each of these. They only decide x87 operand order. No statement is
// dead, no local is unused and no branch is statically false, but the reference aliases and the redundant
// parentheses emit no code of their own:
//  - hkVector4::mul4 takes hkSimdReal by value; normalize3() passes lengthInverse3() straight to it
//  - single-use reference aliases: constraints, velocity, maxSurfaceVelocity
//  - the parentheses in 1.0f - (angleSin * angleSin)
//  - touching loop: the y term reads both vectors through operator()(1), the x and z terms read members
// pdb: hkpCharacterProxy::checkSupportWithCollector | hkpCharacterProxy.obj | fnv360_0822_retail, objrun, medium
// pdb params: direction, ground, startPointCollector
void hkpCharacterProxy::FUN_0091fe80(const hkVector4& direction, hkpSurfaceInfo& ground, hkpAllCdPointCollector& startPointCollector)
{
    hkTimerBegin(DAT_00e36998);
    if (m_refreshManifoldInCheckSupport)
    {
        FUN_0091fdb0(startPointCollector);
    }
    hkLocalArray<hkpSurfaceConstraintInfo> surfaceConstraints(m_manifold.getSize() + m_userPlanes + 10);
    surfaceConstraints.setSizeUnchecked(m_manifold.getSize());
    for (int i = 0; i < m_manifold.getSize(); i++)
    {
        getSurfaceConstraintInfo(m_manifold[i], surfaceConstraints[i], 0.0f);
        addMaxSlopePlane(m_maxSlopeCosine, m_up, i, surfaceConstraints);
    }
    if (surfaceConstraints.getCapacity() - surfaceConstraints.getSize() < m_userPlanes)
    {
        surfaceConstraints.reserve(surfaceConstraints.getSize() + m_userPlanes);
    }
    hkLocalArray<hkSurfaceConstraintInteraction> surfaceConstraintInteractions(surfaceConstraints.getSize() + m_userPlanes);
    hkLocalArray<hkVector4> actualSurfaceVelocities(surfaceConstraints.getSize() + m_userPlanes);

    hkSimplexSolverInput input;
    hkSimplexSolverOutput output;
    input.m_position.setZero4();
    hkLocalArray<hkpSurfaceConstraintInfo>& constraints = surfaceConstraints;
    input.m_constraints = constraints.begin();
    input.m_numConstraints = constraints.getSize();
    hkVector4& velocity = input.m_velocity;
    velocity = direction;
    input.m_deltaTime = DAT_00e32888;
    input.m_minDeltaTime = DAT_00e32888;
    input.m_upVector = m_up;
    hkVector4& maxSurfaceVelocity = input.m_maxSurfaceVelocity;
    maxSurfaceVelocity.setAll3(m_maxCharacterSpeedForSolver);
    output.m_planeInteractions = surfaceConstraintInteractions.begin();
    FUN_0091ec20(m_manifold, input);

    actualSurfaceVelocities.setSize(input.m_numConstraints);
    surfaceConstraintInteractions.setSize(input.m_numConstraints);
    surfaceConstraints.setSize(input.m_numConstraints);
    for (int j = 0; j < input.m_numConstraints; j++)
    {
        actualSurfaceVelocities[j] = surfaceConstraints[j].m_velocity;
        surfaceConstraints[j].m_velocity.setZero4();
    }
    FUN_009a5ae0(input, output);

    ground.m_surfaceVelocity.setZero4();
    ground.m_surfaceNormal.setZero4();
    if (output.m_velocity.equals3(direction, 1e-3f))
    {
        ground.m_supportedState = hkpSurfaceInfo::UNSUPPORTED;
    }
    else if (output.m_velocity.lengthSquared3() < 0.001f)
    {
        ground.m_supportedState = hkpSurfaceInfo::SUPPORTED;
    }
    else
    {
        output.m_velocity.normalize3();
        const float angleSin = output.m_velocity.dot3(direction);
        float cosSqr = 1.0f - (angleSin * angleSin);
        if (cosSqr < m_maxSlopeCosine * m_maxSlopeCosine)
        {
            ground.m_supportedState = hkpSurfaceInfo::SLIDING;
        }
        else
        {
            ground.m_supportedState = hkpSurfaceInfo::SUPPORTED;
        }
    }
    if (ground.m_supportedState != hkpSurfaceInfo::UNSUPPORTED)
    {
        int numTouching = 0;
        for (int k = 0; k < input.m_numConstraints; k++)
        {
            if (!surfaceConstraintInteractions[k].m_touched) continue;
            double t = direction(1) * surfaceConstraints[k].m_plane(1); t += surfaceConstraints[k].m_plane.x * direction.x; t += surfaceConstraints[k].m_plane.z * direction.z;
            if ((float)t < -0.08f)
            {
                numTouching++;
                ground.m_surfaceNormal.add4(surfaceConstraints[k].m_plane);
                ground.m_surfaceVelocity.add4(actualSurfaceVelocities[k]);
            }
        }
        if (numTouching > 0)
        {
            ground.m_surfaceNormal.normalize3();
            ground.m_surfaceVelocity.mul4(1.0f / numTouching);
        }
        else
        {
            ground.m_supportedState = hkpSurfaceInfo::UNSUPPORTED;
        }
    }
    hkTimerBegin(DAT_00e32798);
    actualSurfaceVelocities.destruct();
    surfaceConstraintInteractions.destruct();
    surfaceConstraints.destruct();
}


}   // namespace f3m_0091fe80

// @f3 0x009138b0 (community match, verified in this file)
namespace f3m_009138b0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern unsigned DAT_010f3170;
extern const float DAT_00f7a690;
extern const char DAT_00e346a4[],DAT_00e34698[],DAT_00e362e4[],DAT_00e3466c[],DAT_00e362a0[];

struct ReadStreamLoad {
 void* unk00;unsigned offset;
 unsigned (__cdecl *read)(ReadStreamLoad*,void*,unsigned,unsigned*,unsigned);
 unsigned Read(void* p,unsigned n){unsigned size=4;unsigned got=read(this,p,n,&size,1);offset+=got;return got;}
 unsigned ReadRaw(void* p,unsigned n){unsigned got=read(this,p,n,0,0);offset+=got;return got;}
};

struct LoadContext {
 unsigned unk00,version; char name[216];char type[260];
 unsigned char unk1e4,endian;unsigned short unk1e6;
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
 unsigned unk248;
 ReadStreamLoad* stream;
 void FUN_0082b620();
};

struct ErrorConfigLoad {char enabled;ErrorConfigLoad(bool e){enabled=(char)e;}};
class hkOstreamD734 {
public:
 unsigned unk00,unk04,unk08;
 void FUN_00943a60();
 hkOstreamD734(char* b,unsigned n,ErrorConfigLoad c);
 ~hkOstreamD734(){FUN_00943a60();}
 hkOstreamD734& FUN_00943710(const char*);
};

struct ErrorReporterLoad {
 virtual void v0();virtual void v4();virtual void v8();
 virtual void Report(int,unsigned,const char*,const char*,int);
};
extern ErrorReporterLoad* DAT_010f3364;
struct HavokHeapLoad {void FUN_008f6d90(void*,unsigned,int);};
template<class T> struct ArrayLoad {
 T* data;int size;int capacity;
 __forceinline void ReleaseBuffer(unsigned count){HavokHeapLoad* heap=(HavokHeapLoad*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(data,count*sizeof(T),23);}
 __forceinline void Clear(){
  if(!(capacity&0x80000000))ReleaseBuffer(capacity&0x3fffffff);
  capacity=(capacity&0xc0000000)|0x80000000;data=0;size=0;
 }
};

struct __declspec(align(16)) LegacyLoad {
 unsigned type;float value;unsigned unk08,unk0c;unsigned vecX,vecY,vecZ,vecW;unsigned unk20;
 ArrayLoad<void*> a0,a1,a2,a3;ArrayLoad<char> a4;ArrayLoad<void*> a5,a6,a7,a8,a9,a10,a11;
 unsigned unkb4,unkb8,unkbc;
 void FUN_00912c00();void FUN_00912cb0();
 LegacyLoad(){FUN_00912c00();}~LegacyLoad(){FUN_00912cb0();}
};
struct RefObjectLoad {virtual void v0();virtual void Release();long references;void DecRef(){if(InterlockedDecrement(&references)==0)Release();}};
struct RefLoad {
 RefObjectLoad* p;unsigned flags;
 RefLoad():p(0),flags(0){}
 ~RefLoad(){if(p)p->DecRef();}
};

struct RefArrayLoad {
 void* unk00;RefLoad* entries;unsigned capacity,size,end,grow;
 void FUN_00910490(unsigned);void FUN_00910640(unsigned,RefLoad*);
 void Add(RefLoad& value){unsigned i=size;if(i>=capacity)FUN_00910490(i+grow);FUN_00910640(i,&value);}
};

struct ResultLoad {unsigned type;float value;RefArrayLoad values;};
struct TargetLoad {
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
 virtual ResultLoad* GetResult(bool*);
 unsigned unk04,unk08,unk0c,type;
 void FUN_00825ad0(LoadContext*);void FUN_008f7490(LoadContext*);
 void FUN_009138b0(LoadContext*);
};

// FUN_009138b0: versioned loader. Matches under /MT /O2 /GS /EHsc /Gy (the listed /Od set is wrong for it).
// Built on the stored draft best1.cpp (another contributor). Spellings the match depends on:
//  - the error stream object is 12 bytes (three words) and takes its bool option as a one-byte class by value
//  - STEERING: typeName is a single-use named local declared before path. It emits no code of its own (the
//    same lea is emitted either way); its position decides evaluation order, scratch registers and stack slots.
//  - the reference's destructor releases through the object's inline DecRef()
//  - Add() copies size into a local index before the capacity test
//  - RefLoad initialises p before flags; the loop counter is a signed int
//  - both read helpers keep the callback's result in a named local and return it; path is set by assignment
//    and an if, not a conditional expression
// No statement is dead, no local is unused and no branch is statically false.
// pdb: bhkNiTriStripsShape::LoadBinary | bhkNiTriStripsShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: arStream
void TargetLoad::FUN_009138b0(LoadContext* context){
 bool flag;
 ResultLoad* result=GetResult(&flag);
 if(context->version<2){
  const char* typeName=context->type;
  const char* path=context->name;
  if(!*path)path=DAT_00e346a4;
  {
   char buffer[512];
   hkOstreamD734 error(buffer,512,true);
   error.FUN_00943710(DAT_00e3466c).FUN_00943710(typeName).FUN_00943710(DAT_00e362e4).FUN_00943710(path).FUN_00943710(DAT_00e34698);
   DAT_010f3364->Report(1,0x234f2250,buffer,DAT_00e362a0,0x112);
  }
  FUN_00825ad0(context);
  LegacyLoad legacy;
  context->stream->ReadRaw(&legacy,0xc0);
  if(result){
   legacy.a0.Clear();legacy.a1.Clear();legacy.a2.Clear();legacy.a3.Clear();legacy.a4.Clear();legacy.a5.Clear();legacy.a6.Clear();legacy.a7.Clear();legacy.a8.Clear();legacy.a9.Clear();legacy.a10.Clear();legacy.a11.Clear();
   if(context->endian!=1){legacy.type=_byteswap_ulong(legacy.type);*(unsigned*)&legacy.value=_byteswap_ulong(*(unsigned*)&legacy.value);}
   result->value=legacy.value;
   if(context->endian!=1){legacy.vecX=_byteswap_ulong(legacy.vecX);legacy.vecY=_byteswap_ulong(legacy.vecY);legacy.vecZ=_byteswap_ulong(legacy.vecZ);legacy.vecW=_byteswap_ulong(legacy.vecW);}
   if((int)legacy.type>=32)legacy.type=0;
   type=legacy.type;
   result->type=0;result->value=DAT_00f7a690;
  }
  context->FUN_0082b620();
 }else{
  FUN_008f7490(context);context->FUN_0082b620();
  int count=0;context->stream->Read(&count,4);
  if(result){
   if(context->endian!=1)*(unsigned*)&result->value=_byteswap_ulong(*(unsigned*)&result->value);
   for(int i=0;i<count;++i){
    RefLoad ref;
    context->stream->Read(&ref.flags,4);
    if(context->version<9 && (ref.flags&0x20))ref.flags=(ref.flags&~0x20)|0x8000;
    result->values.Add(ref);
   }
  }
 }
}
}   // namespace f3m_009138b0

// @f3 0x0091ab40 (community match, verified in this file)
namespace f3m_0091ab40 {

struct hkBool
{
    char m_bool;
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = (char)b; }
    __forceinline operator bool() const { return m_bool != 0; }
};

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline hkVector4() {}
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(float a, float b, float c, float d = 0.0f) { x = a; y = b; z = c; w = d; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
};

struct hkpWorldRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    hkBool m_enableShapeCollectionFilter;
    unsigned int m_filterInfo;
    __forceinline hkpWorldRayCastInput() { m_enableShapeCollectionFilter = false; m_filterInfo = 0; }
};

struct hkpWorldRayCastOutput
{
    hkVector4 m_normal;
    int unk10, unk14, unk18, unk1c;
    float m_hitFraction;
    int unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    const void* m_rootCollidable;
    int unk64, unk68, unk6c;
    hkpWorldRayCastOutput();
    ~hkpWorldRayCastOutput();
    __forceinline hkBool hasHit() const { return m_rootCollidable != 0; }
};

class hkpBroadPhase;
class hkpCollisionFilter;

class hkpBroadPhaseCastCollector
{
  public:
    virtual ~hkpBroadPhaseCastCollector() {}
    virtual float addBroadPhaseHandle(const void* broadPhaseHandle, int castIndex);
};

class hkpWorldRayCaster : public hkpBroadPhaseCastCollector
{
  public:
    __forceinline hkpWorldRayCaster() : m_shapeInput0(0), m_shapeInput1(0) {}
    __forceinline ~hkpWorldRayCaster() {}
    void hkpWorldRayCaster_castRayGroup(const hkpBroadPhase& broadphase, const hkpWorldRayCastInput* inputArray, int numInputs, const hkpCollisionFilter* filter, hkpWorldRayCastOutput* outputs, int outputStriding);

    int unk04, unk08, unk0c;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 unk30;
    int m_shapeInput0;
    int m_shapeInput1;
    int unk48, unk4c;
};

class hkpWorld
{
  public:
    int unk000;
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050;
    hkpBroadPhase* m_broadPhase;
    int unk058, unk05c, unk060, unk064, unk068, unk06c;
    hkpCollisionFilter* m_collisionFilter;

    __forceinline hkpBroadPhase* getBroadPhase() { return m_broadPhase; }
    __forceinline const hkpCollisionFilter* getCollisionFilter() const { return m_collisionFilter; }
};

class bhkWorld
{
  public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94();
    virtual hkpWorld* GetWorld();
};

struct Owner
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c;
    bhkWorld* world;
    __forceinline bhkWorld* GetWorld() const { return world; }
};

struct Hit
{
    const void* collidable;
    float height;
};

struct SamplePoint { unsigned char a, b; };
extern const SamplePoint DAT_00f7aec8[9];

class Controller
{
  public:
    int unk00, unk04;
    Owner* owner;
    int unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028;
    unsigned int flags;
    int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c;
    hkVector4 boundMin;
    hkVector4 boundMax;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0;
    Hit hits[9];

    hkVector4 FUN_0091a360(int a, int b);
    void FUN_0091ab40();
};

// FUN_0091ab40: nine downward ray casts through hkpWorldRayCaster::castRayGroup, one per sample point.
// Matches under /MT /O2 /GS /EHsc /Gy (the listed /Od /Oy- set is wrong for this function).
// STEERING SPELLINGS the match depends on. The two reference aliases emit no code of their own; they only decide
// x87 operand order in the nine unrolled result blocks. No statement is dead, no local is unused and no branch is
// statically false.
//  - 'dir' is a single-use reference alias of the local vector 'offset'
//  - 'from' in the result loop is a single-use reference alias of inputs[j].m_from
// Not steering, but needed:
//  - the first table byte goes through an unsigned char local and is widened into an int local AFTER the second
//    byte is read (decides the load order, the scratch registers and which of ebx/edi holds this)
//  - the world pointer is read through the inline accessor Owner::GetWorld() (keeps the null test on the stack slot)
//  - hi and lo are separate float locals; the ray offset is a whole hkVector4 whose z lane is the scale
//  - hasHit() returns hkBool; the ray input's constructor is inline, the output's constructor and destructor are not
//  - the clamp literal is 17.1452084f (the stored drafts had 10.596..., the same four bytes in another order)
void Controller::FUN_0091ab40()
{
    bhkWorld* world = owner ? owner->GetWorld() : 0;
    if (!world)
        return;
    unsigned int filterInfo = (flags & 0xffffffa6) | 0x26;
    float hi = boundMax.z;
    float lo = boundMin.z;
    float height = hi - lo;
    if (height < 17.1452084f)
        height = 17.1452084f;
    hkVector4 offset;
    offset.set(0.0f, 0.0f, height * -2.0, 0.0f);
    const hkVector4& dir = offset;
    hkpWorldRayCastOutput outputs[9];
    hkpWorldRayCastInput inputs[9];
    for (int i = 0; i < 9; i++)
    {
        unsigned char column = DAT_00f7aec8[i].a;
        int b = DAT_00f7aec8[i].b;
        int a = column;
        hkVector4 from = FUN_0091a360(a, b);
        inputs[i].m_filterInfo = filterInfo;
        inputs[i].m_from = from;
        inputs[i].m_to.setAdd4(from, dir);
    }
    hkpWorldRayCaster rayCaster;
    world->GetWorld();
    rayCaster.hkpWorldRayCaster_castRayGroup(*world->GetWorld()->getBroadPhase(), inputs, 9, world->GetWorld()->getCollisionFilter(), outputs, sizeof(hkpWorldRayCastOutput));
    world->GetWorld();
    for (int j = 0; j < 9; j++)
    {
        const hkVector4& from = inputs[j].m_from;
        if (outputs[j].hasHit())
        {
            hits[j].collidable = outputs[j].m_rootCollidable;
            hits[j].height = outputs[j].m_hitFraction * dir.z + from.z;
        }
        else
        {
            hits[j].collidable = 0;
            hits[j].height = -2147483648.0f;
        }
    }
}

}

// @f3 0x00917410 (community match, verified in this file)
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

namespace f3m_00917410 {

extern unsigned long DAT_010f3170;

static __forceinline float hkSqrt(float r) { return (float)sqrt(r); }
static __forceinline float hkSqrtInverse(float r) { return 1.0f / hkSqrt(r); }

struct hkQuaternion;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline hkVector4() {}
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(float a, float b, float c, float d = 0.0f) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setAll(float a) { x = a; y = a; z = a; w = a; }
    __forceinline void setXYZ0(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = 0.0f; }
    __forceinline void setNeg4(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
    __forceinline void setNeg3(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void setMul4(float r, const hkVector4& a) { x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    __forceinline void addMul4(float r, const hkVector4& a) { x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    __forceinline void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    __forceinline void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline float dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline float lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
    __forceinline float lengthInverse3() const { float l2 = lengthSquared3(); return l2 ? hkSqrtInverse(l2) : 0; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setReciprocal3(const hkVector4& v) { x = 1.0f / v.x; y = 1.0f / v.y; z = 1.0f / v.z; }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b)
    {
        const float nx = a.y * b.z - a.z * b.y;
        const float ny = a.z * b.x - a.x * b.z;
        const float nz = a.x * b.y - a.y * b.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline float getReal() const { return m_vec.w; }
    __forceinline void setIdentity() { m_vec.set(0.0f, 0.0f, 0.0f, 1.0f); }
    __forceinline void setInverse(const hkQuaternion& q) { m_vec.setNeg3(q.m_vec); }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);
};
__declspec(noinline) void hkQuaternion::FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1)
{
    const float q0real = q0.getReal();
    const float q1real = q1.getReal();
    hkVector4 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0real, q1.getImag());
    vec.addMul4(q1real, q0.getImag());
    m_vec = vec;
    m_vec.w = (q0real * q1real) - q0.getImag().dot3(q1.getImag());
}

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    float qreal = quat.m_vec.w;
    float q2minus1 = qreal * qreal - 0.5;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    // STEER 1: in place, first product only in parentheses (setRotatedInverseDir calls dot3)
    float imagDotDir = (quat.m_vec.x * direction.x) + quat.m_vec.y * direction.y + quat.m_vec.z * direction.z;
    ret.addMul4(imagDotDir, quat.getImag());
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    float qreal = quat.m_vec.w;
    float q2minus1 = qreal * qreal - 0.5;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    float imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

struct hkTransform;

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    void FUN_009643d0(const hkTransform& t);
    __forceinline void setIdentity()
    {
        m_translation.setZero4();
        m_rotation.setIdentity();
        m_scale.setAll(1.0f);
    }
    __forceinline void setInverse(const hkQsTransform& t)
    {
        m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
        m_translation.setNeg4(m_translation);
        m_rotation.setInverse(t.m_rotation);
        hkVector4 invScale;
        invScale.setReciprocal3(t.m_scale);
        m_scale.setXYZ0(invScale);
    }
    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(extraTrans, t1.m_translation);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);
        m_scale.setMul4(t2.m_scale, t1.m_scale);
    }
    __forceinline void setMulInverseMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkQsTransform h;
        h.setInverse(t1);
        setMul(h, t2);
    }
};

class hkThreadMemory
{
  public:
    struct FreeList
    {
        void* m_head;
        int m_numElem;
    };
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    FreeList m_free_list[12];

    void* FUN_008f6800(int row, int cls);
    void* FUN_008f6f60(int nbytes, int cls);
    void* FUN_008f6d30(int nbytes, int cls);
    void FUN_008f6d90(void* p, int nbytes, int cls);

    static __forceinline hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }
    __forceinline void* allocateChunkConstSize(int row, int cls)
    {
        FreeList& f = m_free_list[row];
        void* p = f.m_head;
        if (p)
        {
            f.m_numElem--;
            f.m_head = *(void**)p;
            return p;
        }
        return FUN_008f6800(row, cls);
    }
};

template <typename T>
static __forceinline T* hkAllocate(int n, int cls)
{
    return (T*)hkThreadMemory::getInstance().FUN_008f6f60(n * sizeof(T), cls);
}

template <typename T>
class hkArray
{
  public:
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    __forceinline hkArray(int n) : m_data((T*)hkThreadMemory::getInstance().FUN_008f6d30(n * sizeof(T), 0x17)), m_size(n), m_capacityAndFlags(n) {}
    __forceinline ~hkArray()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }
    __forceinline int getSize() const { return m_size; }
    __forceinline int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct hkpShape
{
    int unk00, unk04, unk08;
    int m_type;
    float m_radius;
    int unk14, unk18, unk1c;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpRigidBody
{
    int unk00, unk04, unk08, unk0c;
    hkpShape* m_shape;
    int unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    const char* m_name;
    int unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    hkQsTransform m_transform;

    __forceinline const hkTransform& getTransform() const { return *(const hkTransform*)&m_transform; }
    __forceinline const char* getName() const { return m_name; }
    __forceinline const hkpShape* getShape() const { return m_shape; }
};

struct hkpConstraintInstance
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkpRigidBody* m_entityA;
    hkpRigidBody* m_entityB;
    __forceinline hkpRigidBody* getRigidBodyB() const { return m_entityB; }
};

struct BodyArray
{
    hkpRigidBody** m_data;
    int m_size;
    __forceinline int getSize() const { return m_size; }
    __forceinline hkpRigidBody* operator[](int i) const { return m_data[i]; }
};

struct ConstraintArray
{
    hkpConstraintInstance** m_data;
    int m_size;
    __forceinline hkpConstraintInstance* operator[](int i) const { return m_data[i]; }
};

struct NubEntry
{
    int unk00, unk04;
    hkpRigidBody* m_body;
};

struct NubList
{
    int unk00;
    NubEntry** m_data;
    unsigned int m_size;
};

struct hkaBone
{
    const char* m_name;
    unsigned char m_lockTranslation;
    static __forceinline void* operator new(unsigned int) { return hkThreadMemory::getInstance().allocateChunkConstSize(1, 0x3b); }
};

struct hkaSkeleton
{
    const char* m_name;
    short* m_parentIndices;
    int m_numParentIndices;
    hkaBone** m_bones;
    int m_numBones;
    hkQsTransform* m_referencePose;
    int m_numReferencePose;
    int unk1c, unk20;
    __forceinline hkaSkeleton() : m_name(0), m_parentIndices(0), m_numParentIndices(0), m_bones(0), m_numBones(0), m_referencePose(0), m_numReferencePose(0), unk1c(0), unk20(0) {}
    static __forceinline void* operator new(unsigned int) { return hkThreadMemory::getInstance().allocateChunkConstSize(4, 0x3b); }
};

const char* __cdecl FUN_00923640(const char* s);

struct hkOstream
{
    int unk00, unk04, unk08;
    hkOstream* FUN_00923070(char* b, int n);
    void FUN_00943a60();
    void FUN_00943710(const char* s);
    __forceinline hkOstream(char* b, int n) { FUN_00923070(b, n); }
    __forceinline ~hkOstream() { FUN_00943a60(); }
};

struct hkError
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void message(int type, unsigned int id, const char* text, const char* file, int line);
};
extern hkError* DAT_010f3364;

// FUN_00917410: ragdoll skeleton construction (hkaRagdollUtils-style) with extra "Nub" bones appended.
// Byte-exact offline under /MT /O2 /GS /EHsc /Gy; the listed /Od /Oy- set is wrong for this function.
// REWORK, for the lead to rule on: the match depends on spellings that emit no code of their own and only move
// the compiler's symbol numbering, which decides the x87 operand order in the second rotation and in the
// capsule length. They are marked STEER below. No statement is dead and no local is unused.
//  STEER 1: setRotatedDir computes its dot product in place with only the first product in parentheses;
//           setRotatedInverseDir calls dot3. With dot3 in both, the second rotation keeps y instead of x.
//  STEER 2: six single-use named locals (numNubs, parentIndex, name in loop 2, diameter three times). Any six
//           to twelve more named locals than closer.cpp give the same code; five or thirteen do not.
// Spellings that change code and are needed:
//  - hkQuaternion::FUN_008d3290 has its real body, out of line (noinline): the compiler then knows the call does
//    not write the inverse transform (the scale product reads the reciprocal temporary and the constant 0.0).
//  - the capsule direction is dir.setMul4(axis.lengthInverse3(), axis).
//  - in the capsule branch the body transform is bound to a named reference before the call: that gives
//    lea eax,[ecx+0xe0] / push eax at +0x7e1 instead of add ecx,0xe0 / push ecx.

// pdb: bhkRagdollPenetrationUtil::CreateSkeletonForRagdoll | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_gap, low
// pdb params: arRigidBodies, arConstraints, arLeaves
hkaSkeleton* __stdcall FUN_00917410(const BodyArray& rigidBodies, const ConstraintArray& constraints, NubList* nubs)
{
    hkaSkeleton* skeleton = new hkaSkeleton;
    int numBones = rigidBodies.getSize();
    unsigned int numNubs = nubs->m_size; // STEER 2
    int total = numBones + numNubs;
    skeleton->m_numBones = total;
    skeleton->m_numReferencePose = total;
    skeleton->m_numParentIndices = total;
    skeleton->m_bones = hkAllocate<hkaBone*>(total, 0xd);
    skeleton->m_parentIndices = hkAllocate<short>(total, 0xd);
    skeleton->m_referencePose = hkAllocate<hkQsTransform>(total, 0xd);
    hkArray<int> nubParents(nubs->m_size);

    for (int b = 0; b < rigidBodies.getSize(); b++)
    {
        int parentId = -1;
        if (b != 0)
        {
            hkpRigidBody* parent = constraints[b - 1]->getRigidBodyB();
            for (int i = 0; i < b; i++)
            {
                if (rigidBodies[i] == parent)
                {
                    parentId = i;
                    break;
                }
            }
        }
        short parentIndex = (short)parentId; // STEER 2
        skeleton->m_parentIndices[b] = parentIndex;
        hkpRigidBody* rbody = rigidBodies[b];
        for (unsigned int n = 0; n < nubs->m_size; n++)
        {
            if (rbody == nubs->m_data[n]->m_body)
            {
                nubParents[n] = b;
            }
        }
        hkaBone* bone = new hkaBone;
        if (parentId >= 0)
        {
            hkpRigidBody* parentRb = rigidBodies[parentId];
            hkQsTransform rbTransform;
            rbTransform.FUN_009643d0(rbody->getTransform());
            hkQsTransform parentTransform;
            parentTransform.FUN_009643d0(parentRb->getTransform());
            skeleton->m_referencePose[b].setMulInverseMul(parentTransform, rbTransform);
        }
        else
        {
            skeleton->m_referencePose[b].FUN_009643d0(rbody->getTransform());
        }
        if (rbody->getName())
        {
            bone->m_name = FUN_00923640(rbody->getName());
        }
        else
        {
            char buffer[512];
            {
                hkOstream stream(buffer, 512);
                stream.FUN_00943710("Rigid Body name could not be found");
                DAT_010f3364->message(1, 0xabbacc14, buffer, "c:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkRagdollPenetrationUtil.cpp", 0x2df);
            }
            bone->m_name = 0;
        }
        bone->m_lockTranslation = (b != 0);
        skeleton->m_bones[b] = bone;
    }

    for (unsigned int i = 0; i < nubs->m_size; i++)
    {
        hkpRigidBody* rbody = nubs->m_data[i]->m_body;
        int parentId = nubParents[i];
        const hkpShape* shape = rbody->getShape();
        if (!shape)
        {
            continue;
        }
        hkVector4 offset;
        offset.setZero4();
        if (shape->m_type == 6)
        {
            const hkTransform& bodyTransform = rbody->getTransform(); // named reference: lea at +0x7e1
            hkQsTransform rbTransform;
            rbTransform.FUN_009643d0(bodyTransform);
            hkVector4 axis;
            axis.setSub4(shape->m_vertexA, shape->m_vertexB);
            hkVector4 dir;
            dir.setMul4(axis.lengthInverse3(), axis);
            dir.mul4(shape->m_radius);
            axis.add4(dir);
            offset = axis;
        }
        if (shape->m_type == 5)
        {
            float radius = shape->m_radius;
            float diameter = radius * 2.0; // STEER 2
            offset.x = diameter;
        }
        if (shape->m_type == 7)
        {
            float radius = shape->m_radius;
            float diameter = radius * 2.0; // STEER 2
            offset.x = diameter;
        }
        if (shape->m_type == 2)
        {
            float radius = shape->m_radius;
            float diameter = radius * 2.0; // STEER 2
            offset.x = diameter;
        }
        hkaBone* bone = new hkaBone;
        char buffer[45];
        const char* name = rbody->getName(); // STEER 2
        if (name)
        {
            strncpy_s(buffer, 0x29, name, 0x28);
            buffer[40] = 0;
        }
        else
        {
            strcpy_s(buffer, 0x28, "No Name");
        }
        strcat_s(buffer, 0x2d, " Nub");
        bone->m_name = FUN_00923640(buffer);
        bone->m_lockTranslation = 1;
        unsigned int slot = numBones + i;
        skeleton->m_parentIndices[slot] = (short)parentId;
        skeleton->m_bones[slot] = bone;
        skeleton->m_referencePose[slot].setIdentity();
        skeleton->m_referencePose[slot].m_translation = offset;
    }

    if (skeleton->m_numBones > 0)
    {
        skeleton->m_name = skeleton->m_bones[0]->m_name;
    }
    else
    {
        skeleton->m_name = 0;
    }
    return skeleton;
}

}

// @f3 0x0091f230 (community match, verified in this file)
#include <math.h>
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern const char DAT_00e36998[];
extern const char DAT_00e32798[];
extern const float DAT_00de6e70;
extern const float DAT_00de6e60;
extern const float DAT_00e32888;
extern const char DAT_00e36980[],DAT_00e36978[],DAT_00e36968[],DAT_00e36954[],DAT_00e36948[],DAT_00e3693c[],DAT_00e36930[],DAT_00e0811c[];
extern const double DAT_00db7de8;
extern const float DAT_00db7df0;
namespace f3m_0091f230 {

extern "C" {
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
}

struct hkBool
{
    char m_bool;

    __forceinline hkBool() {}
    __forceinline hkBool(bool b)
    {
        m_bool = (char)b;
    }
    __forceinline operator bool() const
    {
        return m_bool != 0;
    }
};

static __forceinline float hkFabs(float r)
{
    return (float)fabs(r);
}

static __forceinline float hkSqrt(float r)
{
    return (float)sqrt(r);
}
static __forceinline float hkSqrtInverse(float r)
{
    return 1.0f / hkSqrt(r);
}

struct hkVector4Comparison
{
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };

    int m_mask;

    __forceinline hkBool allAreSet(Mask m) const
    {
        return (m_mask & m) == m;
    }
};

struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal(float x) : m_real(x) {}
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& a){x=a.x;y=a.y;z=a.z;w=a.w;}
    __forceinline hkVector4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
    __forceinline void setAdd4(const hkVector4& a,const hkVector4& b){x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void setAll3(float a) { x = a; y = a; z = a; w = a; }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline float lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
    __forceinline hkSimdReal lengthInverse3() const { float l2 = lengthSquared3(); return l2 ? hkSqrtInverse(l2) : 0; }
    __forceinline void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    __forceinline void mul4(float rs) { float s = rs; x *= s; y *= s; z *= s; w *= s; }
    __forceinline void addMul4(float r, const hkVector4& a) { x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void setAbs4(const hkVector4& v) { x = hkFabs(v.x); y = hkFabs(v.y); z = hkFabs(v.z); w = hkFabs(v.w); }
    __forceinline hkVector4Comparison compareLessThanEqual4(const hkVector4& a) const
    {
        hkVector4Comparison ret;
        ret.m_mask = ((x <= a.x) ? hkVector4Comparison::MASK_X : 0) | ((y <= a.y) ? hkVector4Comparison::MASK_Y : 0) | ((z <= a.z) ? hkVector4Comparison::MASK_Z : 0) | ((w <= a.w) ? hkVector4Comparison::MASK_W : 0);
        return ret;
    }
    __forceinline hkBool equals3(const hkVector4& v, float epsilon) const
    {
        hkVector4 t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        int mx = t.x <= epsilon ? hkVector4Comparison::MASK_X : 0;
        int my = t.y <= epsilon ? hkVector4Comparison::MASK_Y : 0;
        int mz = t.z <= epsilon ? hkVector4Comparison::MASK_Z : 0;
        int mw = t.w <= epsilon ? hkVector4Comparison::MASK_W : 0;
        hkVector4Comparison cmp;
        cmp.m_mask = mx | my | mz | mw;
        return cmp.allAreSet(hkVector4Comparison::MASK_XYZ);
    }
};
struct hkMonitorStream
{
    struct TimerCommand
    {
        const char* m_commandAndMonitor;
        unsigned int m_time0;
        unsigned int m_time1;

        __forceinline void setTime()
        {
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    static __forceinline hkMonitorStream& getInstance()
    {
        return *(hkMonitorStream*)TlsGetValue(DAT_0116913c);
    }
    __forceinline hkBool memoryAvailable()
    {
        return m_end < m_capacityMinus16;
    }
};

static __forceinline void hkTimerBegin(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (mStream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end;
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end = (char*)(h + 1);
    }
}

class hkThreadMemory
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCurrent;
    char* m_stackPrev;
    char* m_stackBase;
    char* m_stackEnd;

    void FUN_008f6d90(void* p, int nbytes, int cls);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 16) & ~15;
        char* current = m_stackCurrent;
        if (current + nbytes <= m_stackEnd)
        {
            m_stackCurrent = current + nbytes;
            return current;
        }
        return onStackOverflow(nbytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_stackCurrent = (char*)p;
        if (p == m_stackBase)
        {
            onStackUnderflow(p);
        }
    }
};

void __cdecl FUN_00901e90(void* array, int numElem, int sizeElem);
void __cdecl FUN_00901f10(void* array, int sizeElem);

template <typename T>
class hkArray
{
  public:
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    __forceinline int getSize() const
    {
        return m_size;
    }
    __forceinline int getCapacity() const
    {
        return m_capacityAndFlags & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    __forceinline void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        m_size = n;
    }
    __forceinline T& expandOne()
    {
        if (m_size == getCapacity())
        {
            FUN_00901f10(this, sizeof(T));
        }
        return m_data[m_size++];
    }
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }

    __forceinline int indexOf(const T& item)const {for(int i=0;i<m_size;++i)if(m_data[i]==item)return i;return -1;}
    __forceinline void reserveExtra(int n){if(getCapacity()-m_size<n)reserve(m_size+n);}
    __forceinline void removeFirst(){--m_size;for(int i=0;i<m_size;++i)m_data[i]=m_data[i+1];}
    __forceinline void pushBack(const T& value){if(m_size==getCapacity())FUN_00901f10(this,sizeof(T));m_data[m_size]=value;++m_size;}
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
static __forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

template <typename T>
class hkLocalArray : public hkArray<T>
{
  public:
    __forceinline hkLocalArray(int n)
    {
        this->m_data = (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
        this->m_capacityAndFlags = n | hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_localMemory = this->m_data;
    }
    __forceinline void destruct()
    {
        hkDeallocateStack(m_localMemory);
        this->releaseMemory();
    }

    T* m_localMemory;
};

struct hkpSurfaceConstraintInfo
{
    hkVector4 m_plane;
    hkVector4 m_velocity;
    float m_staticFriction;
    float m_extraUpStaticFriction;
    float m_extraDownStaticFriction;
    float m_dynamicFriction;
    int m_priority;

    hkpSurfaceConstraintInfo& operator=(const hkpSurfaceConstraintInfo& other);
};

struct hkSurfaceConstraintInteraction
{
    unsigned char m_touched;
    unsigned char m_stopped;
    float m_surfaceTime;
    float m_penaltyDistance;
    int m_status;
};

struct hkSimplexSolverInput
{
    __forceinline hkSimplexSolverInput()
    {
m_upVector=hkVector4(0.0f,1.0f,0.0f,0.0f);m_maxSurfaceVelocity.setAll3(1.1920928955078125e-7f);m_position.setZero4();
    }
    hkVector4 m_position;
    hkVector4 m_velocity;
    hkVector4 m_maxSurfaceVelocity;
    hkVector4 m_upVector;
    float m_deltaTime;
    float m_minDeltaTime;
    hkpSurfaceConstraintInfo* m_constraints;
    int m_numConstraints;
};

struct hkSimplexSolverOutput
{
    hkVector4 m_position;
    hkVector4 m_velocity;
    float m_deltaTime;
    hkSurfaceConstraintInteraction* m_planeInteractions;
};

void __cdecl FUN_009a5ae0(const hkSimplexSolverInput& input, hkSimplexSolverOutput& output);

struct hkpSurfaceInfo
{
    enum SupportedState
    {
        UNSUPPORTED = 0,
        SLIDING = 1,
        SUPPORTED = 2
    };
    SupportedState m_supportedState;
    hkVector4 m_surfaceNormal;
    hkVector4 m_surfaceVelocity;
};

struct hkpRootCdPoint
{
    hkVector4 m_position;
    hkVector4 m_normal;
    void* m_rootCollidableA;
    int m_shapeKeyA;
    void* m_rootCollidableB;
    int m_shapeKeyB;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkpRootCdPoint& operator=(const hkpRootCdPoint& p){m_position=p.m_position;m_normal=p.m_normal;m_rootCollidableA=p.m_rootCollidableA;m_shapeKeyA=p.m_shapeKeyA;m_rootCollidableB=p.m_rootCollidableB;m_shapeKeyB=p.m_shapeKeyB;unk30=p.unk30;unk34=p.unk34;unk38=p.unk38;return *this;}
};

struct hkStepInfo {float startTime,endTime,deltaTime,inverseDeltaTime;};
struct hkLinearCastInput {hkVector4 m_to;float m_maxExtraPenetration;float m_startPointTolerance;};
class hkpAllCdPointCollector {
public:
 virtual ~hkpAllCdPointCollector();
 float earlyOutDistance; int unk08,unk0c; hkArray<hkpRootCdPoint> hits;
 void reset(){hits.setSizeUnchecked(0);earlyOutDistance=3.40282e38f;}
 void FUN_00921ac0();
};
class hkpShapePhantom {
public:
 virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();
 virtual void setPositionAndLinearCast(const hkVector4&,const hkLinearCastInput&,hkpAllCdPointCollector&,hkpAllCdPointCollector*);
 void FUN_0090dda0(const hkVector4&,float);
};


// hkpCharacterProxy::addMaxSlopePlane (static, FNV FUN_00cadca0)
static __declspec(noinline) bool addMaxSlopePlane(float maxSlopeCos, const hkVector4& up, int index, hkArray<hkpSurfaceConstraintInfo>& surfaceConstraintsInOut)
{
    const float surfaceVerticalComponent = surfaceConstraintsInOut[index].m_plane.dot3(up);
    if (surfaceVerticalComponent > 0.01f && surfaceVerticalComponent < maxSlopeCos)
    {
        hkpSurfaceConstraintInfo& newConstraint = surfaceConstraintsInOut.expandOne();
        newConstraint = surfaceConstraintsInOut[index];
        newConstraint.m_plane.addMul4(-surfaceVerticalComponent, up);
        newConstraint.m_plane.normalize3();
        return true;
    }
    return false;
}

class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject();
    int m_memSizeAndFlags;
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

class hkpRigidBody {public:void FUN_0090b880(hkpEntityListener*);};
class hkpPhantom {public:void FUN_009899a0(hkpPhantomListener*);};
struct ProxyCollidable {
 int unk00,unk04,unk08,unk0c;
 signed char ownerOffset;unsigned char unk11,unk12,unk13;
 int unk14;unsigned char type;
 void* getOwner(){return (char*)this+ownerOffset;}
};
class hkpCharacterProxy : public hkReferencedObject, public hkpEntityListener, public hkpPhantomListener
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void updateManifold(hkpAllCdPointCollector& startPointCollector, hkpAllCdPointCollector& castCollector);
    virtual void getSurfaceConstraintInfo(const hkpRootCdPoint& point, hkpSurfaceConstraintInfo& surface, float timeTravelled) const;

    hkVector4 m_velocity;
    hkVector4 m_oldDisplacement;
    hkpShapePhantom* m_shapePhantom;
    float m_dynamicFriction;
    float m_staticFriction;
    int unk3c;
    hkVector4 m_up;
    float m_extraUpStaticFriction;
    float m_extraDownStaticFriction;
    float m_keepDistance;
    float m_keepContactTolerance;
    float m_contactAngleSensitivity;
    int m_userPlanes;
    float m_maxCharacterSpeedForSolver;
    float m_characterStrength;
    float m_characterMass;
    hkArray<hkpRootCdPoint> m_manifold;
    hkArray<void*> m_listeners;
    hkArray<hkpRigidBody*> m_bodies;
    hkArray<hkpPhantom*> m_phantoms;
    float m_maxSlopeCosine;
    float m_penetrationRecoverySpeed;
    int m_maxCastIterations;
    bool m_refreshManifoldInCheckSupport;

    void FUN_0091fdb0(hkpAllCdPointCollector& startPointCollector);
    void FUN_0091ec20(const hkArray<hkpRootCdPoint>& manifold, hkSimplexSolverInput& input);
    hkVector4* FUN_0091dd60();
    void FUN_0091dbd0(const hkpRootCdPoint*,int,const hkVector4&);
    void FUN_0091e6a0(const hkStepInfo&,const hkVector4&);
    int FUN_0091e630(const hkpRootCdPoint&);
    void FUN_0091ec60(const hkpRootCdPoint&);
    float FUN_0091e260(hkVector4&,hkpAllCdPointCollector&,hkLinearCastInput&,hkVector4&);
    void hkpCharacterProxy_integrateImplementation(const hkStepInfo&,const hkVector4&,hkpAllCdPointCollector&,hkpAllCdPointCollector&);
};



static __forceinline void hkTimerListBegin(const char* name,const char* firstSplit){
    hkMonitorStream& stream=hkMonitorStream::getInstance();
    if(stream.memoryAvailable()){
        struct TimerListCommand:hkMonitorStream::TimerCommand {const char* firstSplit;};
        TimerListCommand* command=(TimerListCommand*)stream.m_end;
        command->m_commandAndMonitor=name;command->firstSplit=firstSplit;command->setTime();stream.m_end=(char*)(command+1);
    }
}
// pdb: hkpCharacterProxy::integrateImplementation | hkpCharacterProxy.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkpCharacterProxy::hkpCharacterProxy_integrateImplementation(const hkStepInfo& step,const hkVector4& gravity,hkpAllCdPointCollector& castCollector,hkpAllCdPointCollector& startCollector){
    hkTimerListBegin(DAT_00e36980,DAT_00e36978);
    hkVector4 position;
    position=*FUN_0091dd60();
    int iteration=0;
    float remaining=step.deltaTime;
    hkLinearCastInput castInput;
    castInput.m_startPointTolerance=m_keepDistance+m_keepContactTolerance;
    castInput.m_maxExtraPenetration=0.01f;
    hkSimplexSolverOutput output;
    while(remaining>1.1920928955078125e-7f && iteration<m_maxCastIterations){
        hkTimerBegin(DAT_00e36968);
        castInput.m_to.setAdd4(m_oldDisplacement,position);
        castCollector.reset();startCollector.reset();
        m_shapePhantom->setPositionAndLinearCast(position,castInput,castCollector,&startCollector);
        if(castCollector.hits.getSize()>0){castCollector.FUN_00921ac0();FUN_0091dbd0(castCollector.hits.begin(),castCollector.hits.getSize(),m_oldDisplacement);}
        hkTimerBegin(DAT_00e36954);
        updateManifold(startCollector,castCollector);
        hkLocalArray<hkpSurfaceConstraintInfo> surfaceConstraints(m_manifold.getSize()+m_userPlanes+10);
        surfaceConstraints.setSizeUnchecked(m_manifold.getSize());
        for(int i=0;i<m_manifold.getSize();++i){
            getSurfaceConstraintInfo(m_manifold[i],surfaceConstraints[i],step.deltaTime-remaining);
            addMaxSlopePlane(m_maxSlopeCosine,m_up,i,surfaceConstraints);
        }
        surfaceConstraints.reserveExtra(m_userPlanes);
        hkTimerBegin(DAT_00e36948);
        hkSimplexSolverInput input;
        hkLocalArray<hkSurfaceConstraintInteraction> interactions(surfaceConstraints.getSize()+m_userPlanes);
        input.m_velocity=m_velocity;
        input.m_constraints=surfaceConstraints.begin();input.m_numConstraints=surfaceConstraints.getSize();
        input.m_deltaTime=remaining;
        // Guess at the source: read through a const reference bound here, the member becomes the memory operand of the
        // product and the inverse length is loaded first, as in the original. Read directly, VC8 always loads the member first.
        const float& keepDistance=m_keepDistance;
        if(m_velocity.lengthSquared3()==0.0f) input.m_minDeltaTime=0.0f;
        else input.m_minDeltaTime=0.5f*(keepDistance*m_velocity.lengthInverse3());
        input.m_position.setZero4();input.m_upVector=m_up;
        input.m_maxSurfaceVelocity.setAll3(m_maxCharacterSpeedForSolver);
        FUN_0091ec20(m_manifold,input);
        output.m_planeInteractions=interactions.begin();
        FUN_009a5ae0(input,output);
        hkTimerBegin(DAT_00e3693c);
        FUN_0091e6a0(step,gravity);
        hkTimerBegin(DAT_00e36930);
        hkVector4 difference;difference.setSub4(m_oldDisplacement,output.m_position);difference.setAbs4(difference);
        hkVector4 tolerance;tolerance.setAll3(0.001f);
        int accepted=difference.compareLessThanEqual4(tolerance).allAreSet(hkVector4Comparison::MASK_XYZ);
        if(!accepted){
            castInput.m_to.setAdd4(position,output.m_position);
            castCollector.reset();
            m_shapePhantom->setPositionAndLinearCast(position,castInput,castCollector,0);
            // The contact block sits inside the hit test: the two accepted = true arms are then followed by different
            // code, so the no-hit arm is threaded straight to the position update (no store), as in the original.
            if(castCollector.hits.getSize()>0){
                castCollector.FUN_00921ac0();FUN_0091dbd0(castCollector.hits.begin(),castCollector.hits.getSize(),output.m_position);
                while(FUN_0091e630(castCollector.hits[0])!=-1){castCollector.hits.removeFirst();if(castCollector.hits.getSize()<=0){accepted=true;break;}}
                if(castCollector.hits.getSize()>0){
                    const hkpRootCdPoint& contact=castCollector.hits[0];
                    FUN_0091ec60(contact);
                    m_manifold.expandOne()=contact;
                    if(!m_refreshManifoldInCheckSupport){
                        ProxyCollidable* collidable=(ProxyCollidable*)contact.m_rootCollidableB;
                        if(collidable->type==1){
                            hkpRigidBody* body=(hkpRigidBody*)collidable->getOwner();
                            if(body && m_bodies.indexOf(body)==-1){body->FUN_0090b880(this);m_bodies.pushBack(body);}
                        }
                        collidable=(ProxyCollidable*)contact.m_rootCollidableB;
                        if(collidable->type==2){
                            hkpPhantom* phantom=(hkpPhantom*)collidable->getOwner();
                            if(phantom && m_phantoms.indexOf(phantom)==-1){phantom->FUN_009899a0(this);m_phantoms.pushBack(phantom);}
                        }
                    }
                }
            }else accepted=true;
        }
        if(accepted){position.add4(output.m_position);remaining-=output.m_deltaTime;}
        else remaining-=FUN_0091e260(output.m_position,castCollector,castInput,position);
        m_oldDisplacement=output.m_position;
        interactions.destruct();surfaceConstraints.destruct();
        ++iteration;
    }
    m_velocity=output.m_velocity;
    m_shapePhantom->FUN_0090dda0(position,castInput.m_startPointTolerance);
    hkTimerBegin(DAT_00e0811c);
}

}   // namespace f3m_0091f230

// @f3 0x00919380 (community match, verified in this file)
namespace f3m_00919380 {

extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

// Havok's per-thread memory (the game's 5.x build: deallocate/allocateChunk called directly)
class hkThreadMemory
{
public:
    virtual ~hkThreadMemory();
    virtual void* alignedAllocate(int alignment, int nbytes, int cl);
    virtual void alignedDeallocate(void* ptr);
    virtual void* allocateChunkV(int nbytes, int cl);
    virtual void deallocateChunkV(void* ptr, int nbytes, int cl);
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* ptr);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }

    void* FUN_008f6d30(int nbytes, int cl);
    void FUN_008f6d90(void* p, int nbytes, int cl);

    __forceinline void* allocateStack(int nbytesin)
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

    __forceinline void deallocateStack(void* p)
    {
        m_stack.m_current = static_cast<char*>(p);
        if (p == m_stack.m_base)
        {
            onStackUnderflow(p);
        }
    }

    struct Stack
    {
        char* m_current;
        Stack* m_prev;
        char* m_base;
        char* m_end;
    };

    void* m_memory;
    int m_referenceCount;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    Stack m_stack;
};

template <typename TYPE>
__forceinline TYPE* hkAllocateStack(int n)
{
    return static_cast<TYPE*>(hkThreadMemory::getInstance().allocateStack(n * sizeof(TYPE)));
}

template <typename TYPE>
__forceinline void hkDeallocateStack(TYPE* ptr)
{
    hkThreadMemory::getInstance().deallocateStack(static_cast<void*>(ptr));
}

template <typename T>
class hkArray
{
public:
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    __forceinline ~hkArray() { releaseMemory(); }
    __forceinline int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
        }
    }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
class hkLocalArray : public hkArray<T>
{
public:
    __forceinline hkLocalArray(int capacity)
    {
        this->m_data = hkAllocateStack<T>(capacity);
        this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_localMemory = this->m_data;
    }
    __forceinline ~hkLocalArray() { hkDeallocateStack<T>(m_localMemory); }
    T* m_localMemory;
};

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setAll(float a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

extern float DAT_00de731c;
extern float DAT_00de6e60;
extern float DAT_010f331c;
extern float DAT_00f75448;

// the game's simple pointer arrays: vtable, data, count, capacity; the vtables are not named, so set from their data
extern void* DAT_00e32b88[];
extern void* DAT_00e3655c[];
extern void* DAT_00de7374[];
typedef void(__thiscall* ArrayFreeFn)(void* array, void* data);

struct Node;
struct Item;

struct RootArray
{
    void** vtable;
    Node** data;
    unsigned int count;
    unsigned int capacity;
    __forceinline RootArray()
    {
        vtable = DAT_00e32b88;
        data = 0;
        count = 0;
        capacity = 0;
    }
    __forceinline ~RootArray()
    {
        vtable = DAT_00e32b88;
        if (data)
        {
            ((ArrayFreeFn)DAT_00e32b88[2])(this, data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
};

struct ItemArray
{
    void** vtable;
    Item** data;
    unsigned int count;
    unsigned int capacity;
    unsigned int FUN_005e5350();
    void FUN_00602700(ItemArray* dest) const;
};

struct RetainedArray : ItemArray
{
    __forceinline RetainedArray()
    {
        vtable = DAT_00e3655c;
        data = 0;
        count = 0;
        capacity = 0;
    }
    __forceinline ~RetainedArray()
    {
        vtable = DAT_00e3655c;
        if (data)
        {
            ((ArrayFreeFn)DAT_00e3655c[2])(this, data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
};

struct ShapeArray
{
    void** vtable;
    void** data;
    unsigned int count;
    unsigned int capacity;
    __forceinline ShapeArray()
    {
        vtable = DAT_00de7374;
        data = 0;
        count = 0;
        capacity = 0;
    }
    __forceinline ~ShapeArray()
    {
        vtable = DAT_00de7374;
        if (data)
        {
            ((ArrayFreeFn)DAT_00de7374[2])(this, data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
};

struct Renderer
{
    struct Vtbl
    {
        void* vf00; void* vf04; void* vf08; void* vf0c; void* vf10; void* vf14; void* vf18; void* vf1c; void* vf20; void* vf24; void* vf28; void* vf2c; void* vf30; void* vf34;
        void(__thiscall* bounds)(Renderer* self, void* geometry, hkAabb* out);
    };
    Vtbl* vtbl;
};

struct Context
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50;
    Renderer* renderer;
    int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c;
    void* attachment;
};

struct Inner
{
    void* unk00;
    void* unk04;
    Context* context;
};

struct SectionInfo
{
    int enabled;
    int unk04; int unk08; int unk0c; int unk10;
    int geometry;
};

struct Section
{
    int unk00; int unk04; int unk08; int unk0c;
    SectionInfo info;
};

struct StatePart
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    unsigned int state;
};

struct Flags
{
    int unk00; int unk04; int unk08; int unk0c;
    StatePart info;
};

struct Target
{
    struct Vtbl
    {
        void* vf00; void* vf04; void* vf08; void* vf0c; void* vf10; void* vf14; void* vf18; void* vf1c; void* vf20; void* vf24; void* vf28; void* vf2c; void* vf30; void* vf34; void* vf38; void* vf3c; void* vf40; void* vf44; void* vf48; void* vf4c; void* vf50; void* vf54; void* vf58; void* vf5c; void* vf60; void* vf64; void* vf68; void* vf6c; void* vf70; void* vf74; void* vf78; void* vf7c; void* vf80; void* vf84; void* vf88; void* vf8c; void* vf90; void* vf94; void* vf98; void* vf9c; void* vfa0; void* vfa4; void* vfa8; void* vfac; void* vfb0; void* vfb4; void* vfb8; void* vfbc;
        void(__thiscall* notify)(Target* self);
    };
    Vtbl* vtbl;
    void* unk04;
    Flags* flags;
};

struct BoneNode
{
    int unk00; int unk04; int unk08;
    Target* target;
};

struct Counter
{
    int unk00; int unk04; int unk08; int unk0c;
    int count;
};

struct Collection
{
    void* unk00;
    void* unk04;
    Inner** nodes;
    unsigned int count;
    int unk10; int unk14; int unk18; int unk1c;
    int* indices;
    int unk24; int unk28;
    Counter* counter;
    inline int getNumBones() const { return counter->count; }
};

struct Scene;

struct PhantomInfo
{
    unsigned int filterInfo;
    unsigned int unk04;
    unsigned char kind;
    hkArray<__int64> array;
    hkVector4 minimum;
    hkVector4 maximum;
    __forceinline PhantomInfo()
    {
        unk04 = 0;
        kind = 2;
    }
};

void* __cdecl FUN_0089eb90(unsigned int size);

// the 0x18-byte phantom wrapper built from PhantomInfo (constructor out of line)
class FUN_004e63f0
{
public:
    struct Vtbl
    {
        void* vf00; void* vf04; void* vf08; void* vf0c; void* vf10; void* vf14; void* vf18; void* vf1c; void* vf20; void* vf24; void* vf28; void* vf2c; void* vf30; void* vf34; void* vf38; void* vf3c; void* vf40; void* vf44; void* vf48; void* vf4c; void* vf50; void* vf54; void* vf58; void* vf5c; void* vf60; void* vf64; void* vf68; void* vf6c; void* vf70; void* vf74; void* vf78; void* vf7c; void* vf80; void* vf84; void* vf88; void* vf8c; void* vf90; void* vf94; void* vf98;
        void(__thiscall* attach)(FUN_004e63f0* self, void* attachment);
    };
    FUN_004e63f0(PhantomInfo* info);
    static void* operator new(unsigned int size) throw() { return FUN_0089eb90(size); }
    static void operator delete(void* p);
    Vtbl* vtbl;
    void* unk04;
    void* resource;
    void* unk0c;
    void* unk10;
    void* unk14;
};

class Manager;

struct PayloadArgs
{
    Counter* counter;
    Manager* owner;
    void* resource;
};

// Havok object (allocator class 0x3d) built from PayloadArgs (constructor out of line)
class FUN_009a0f60
{
public:
    FUN_009a0f60(PayloadArgs* args);
    void FUN_009a0f30();
    static __forceinline void* operator new(unsigned int nbytes)
    {
        FUN_009a0f60* b = static_cast<FUN_009a0f60*>(hkThreadMemory::getInstance().FUN_008f6d30(nbytes, 0x3d));
        b->m_memSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static __forceinline void operator delete(void* p)
    {
        FUN_009a0f60* b = static_cast<FUN_009a0f60*>(p);
        hkThreadMemory::getInstance().FUN_008f6d90(p, b->m_memSizeAndFlags, 0x3d);
    }
    void* vtbl;
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};

struct MemoryManager
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern MemoryManager DAT_01090a78;

struct Item
{
    Node* source;
    Collection* collection;
    Scene* scene;
    FUN_004e63f0* bounding;
    FUN_009a0f60* payload;
    hkArray<void*> array;
    bool valid;
    __forceinline Item() : source(0), collection(0), scene(0), bounding(0), payload(0), valid(true) {}
    static __forceinline void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static __forceinline void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    ~Item();
};

__int64 __cdecl FUN_0086c140();

struct Timer
{
    __int64 start;
    __int64 duration;
    __forceinline void Reset(float ms)
    {
        start = FUN_0086c140();
        duration = (__int64)(ms * DAT_00f75448);
    }
};

int __cdecl hkaRagdollUtils_reorderForRagdoll(hkLocalArray<Section*>* left, hkLocalArray<Node*>* right);
Collection* __cdecl FUN_0095f8b0(Scene* scene, hkLocalArray<Section*>* left, hkLocalArray<Node*>* right);

class Manager
{
public:
    void* unk00;
    ItemArray storage;
    unsigned int option;
    bool active;
    unsigned int idleCount;
    Timer timer;

    void FUN_00917f90(Node* root, RootArray* out);
    void FUN_00919250(Node* node, hkLocalArray<Section*>* left, hkLocalArray<Node*>* right);
    void FUN_00918100(hkLocalArray<Section*>* left, ShapeArray* shapes);
    Scene* FUN_00917410(hkLocalArray<Section*>* left, hkLocalArray<Node*>* right, ShapeArray* shapes);
    bool bhkRagdollPenetrationUtil_Initialize(Node* root, unsigned int group);
    __forceinline unsigned int storageCount()
    {
        return storage.count;
    }
};

static __forceinline void setResource(PhantomInfo& r, unsigned int opt)
{
    r.filterInfo = (opt << 16) | 0x1e;
}


struct FilterBits
{
    unsigned int bits;
    __forceinline FilterBits(unsigned int x) : bits(x) {}
    __forceinline operator unsigned int() const
    {
        return bits;
    }
    __forceinline bool test() const { return (unsigned char)(bits >> 14) & 1; }
    __forceinline void clear() { bits &= ~0x4000u; }
};

// empty bounds: high = -HK_REAL_MAX, low = HK_REAL_MAX
static __forceinline void setEmptyBounds(hkVector4& high, hkVector4& low)
{
    high.setAll(DAT_00de731c);
    low.setAll(DAT_00de6e60);
}

static __forceinline void processNode(Collection* group, int inner)
{
    int idx = group->indices[inner];
    if (idx < 0)
        return;
    Inner* node = group->nodes[idx];
    if (!node)
        return;
    Target* target = ((BoneNode*)node)->target;
    if (!target)
        return;
    Flags* base = target->flags;
    StatePart* info = base ? &base->info : 0;
    unsigned int state = info ? info->state : 0;
    FilterBits filter(state);
    if (filter.test())
    {
        filter.clear();
        if (base)
        {
            info = &base->info;
            if (info)
                info->state = filter;
        }
        target->vtbl->notify(target);
    }
}

// pdb: bhkRagdollPenetrationUtil::Initialize | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
bool Manager::bhkRagdollPenetrationUtil_Initialize(Node* root, unsigned int group)
{
    int inner;
    int work;
    option = group;
    RootArray original;
    FUN_00917f90(root, &original);
    RetainedArray retained;
    bool unavailable = false;
    for (unsigned int outer = 0; outer < original.count; ++outer)
    {
        hkLocalArray<Section*> left(64);
        hkLocalArray<Node*> right(64);
        FUN_00919250(original.data[outer], &left, &right);
        if (right.m_size == 0)
            continue;
        bool reused = false;
        for (inner = 0; (unsigned int)inner < storage.count && !reused; ++inner)
        {
            Item*& item = storage.data[inner];
            if (original.data[outer] == item->source)
            {
                if (left.m_size == (int)item->collection->count)
                {
                    unsigned int n = retained.FUN_005e5350();
                    retained.data[n] = item;
                    reused = true;
                }
            }
        }
        if (reused)
            continue;
        ShapeArray shapes;
        FUN_00918100(&left, &shapes);
        Item* entry = new Item;
        if (hkaRagdollUtils_reorderForRagdoll(&left, &right) != 1)
        {
            entry->source = original.data[outer];
            entry->scene = FUN_00917410(&left, &right, &shapes);
            if (entry->scene)
                entry->collection = FUN_0095f8b0(entry->scene, &left, &right);
            if (entry->collection)
            {
                Inner* obj = entry->collection->nodes[0];
                Context* context = obj ? obj->context : 0;
                hkVector4 maxv;
                hkVector4 minv;
                setEmptyBounds(maxv, minv);
                hkAabb box;
                for (work = 0; work < left.m_size; ++work)
                {
                    SectionInfo* section = &left.m_data[work]->info;
                    if (section->enabled)
                    {
                        Renderer* renderer = context->renderer;
                        renderer->vtbl->bounds(renderer, &section->geometry, &box);
                        maxv.setMax4(maxv, box.m_max);
                        minv.setMin4(minv, box.m_min);
                    }
                }
                box.m_min = minv;
                box.m_max = maxv;
                PhantomInfo info;
                setResource(info, option);
                info.minimum = box.m_min;
                info.maximum = box.m_max;
                entry->bounding = new FUN_004e63f0(&info);
                Inner* attachObj = entry->collection->nodes[0];
                if (attachObj && attachObj->context)
                {
                    Inner* o2 = entry->collection->nodes[0];
                    void* attachment = o2 && o2->context ? o2->context->attachment : 0;
                    FUN_004e63f0* bound = entry->bounding;
                    if (bound)
                        bound->vtbl->attach(bound, attachment);
                }
                PayloadArgs args = {entry->collection->counter, this, entry->bounding->resource};
                entry->payload = new FUN_009a0f60(&args);
                entry->payload->FUN_009a0f30();
                timer.Reset(DAT_010f331c * 1000.0);
            }
        }
        else
            unavailable = true;
        if (entry->bounding && entry->source && entry->payload && entry->collection && entry->scene)
        {
            unsigned int n = retained.FUN_005e5350();
            retained.data[n] = entry;
        }
        else
        {
            delete entry;
        }
    }
    for (inner = 0; (unsigned int)inner < storageCount(); ++inner)
    {
        Item*& previous = storage.data[inner];
        int found = -1;
        for (unsigned int j = 0; j < retained.count; ++j)
        {
            if (retained.data && retained.data[j] == previous)
            {
                found = j;
                break;
            }
        }
        if (found == -1)
            delete previous;
    }
    retained.FUN_00602700(&storage);
    bool result = storage.count > 0;
    active = (!result && !unavailable);
    if (active)
    {
        if (++idleCount > 5)
        {
            active = false;
            idleCount = 0;
        }
    }
    else
        idleCount = 0;
    for (unsigned int outer = 0; outer < storage.count; ++outer)
    {
        for (int bone = 0; bone < storage.data[outer]->collection->getNumBones(); ++bone)
        {
            processNode(storage.data[outer]->collection, bone);
        }
    }
    return result;
}

}  // namespace f3m_00919380

// @f3 0x009006b0 (community match, verified in this file)
namespace f3m_009006b0 {
namespace c_009006b0 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
void __cdecl FUN_00900570(const void* in, Vec4* v, float* f);
// pdb: bhkRigidBody::CalculateTotalCenterOfMass | bhkRigidBody.obj | fnv360_0822_retail, objrun, medium
// pdb params: apObject, aCenter, afMass
void __cdecl FUN_009006b0(const void* in, Vec4* outV, float* outF) {
    Vec4 v(0.0f, 0.0f, 0.0f, 0.0f);
    float f = 0.0f;
    FUN_00900570(in, &v, &f);
    *outV = v;
    *outF = f;
}
}
}   // namespace f3m_009006b0

// @f3 0x00903250 (community match, verified in this file)
namespace f3m_00903250 {
namespace c_00903250 {
struct __declspec(align(16)) Vec4 { float v[4]; };
struct Query {
    virtual void Dtor();
    Vec4 unk10[2];
    int unk30;
    int unk34;
    Query() { unk30 = 0; unk34 = 0; }
    void FUN_009844e0(int a, int b, int c, int d, int e);
};
struct Obj {
    int unk00[0x15];
    int unk54;
    int unk58[6];
    int unk70;
    void FUN_00903250(int a, int b);
};
// pdb: QueryPerformanceFrequency | queryperformancefrequency.obj | fnv360_0822_retail, call_dedup, low
// pdb params: lpFrequency
void Obj::FUN_00903250(int a, int b) {
    Query q;
    q.FUN_009844e0(unk54, a, unk70, 0, b);
}
}
}   // namespace f3m_00903250

// @f3 0x0090da80 (community match, verified in this file)
namespace f3m_0090da80 {
namespace c_0090da80 {
struct __declspec(align(16)) Transform { float m[16]; Transform& FUN_008fda60(const Transform& other); };
struct Body { int unk00[0x28]; Transform transform; };
struct Out { int unk00[9]; float x; float y; float z; };
void __cdecl FUN_0056ac90(Out* out, const Transform* t);
struct Obj { int unk00; int unk04; Body* body; void FUN_00c24b70(); void FUN_0090da80(Out* out); };
// pdb: bhkShapePhantom::GetTransform | bhkShapePhantom.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arTrans
void Obj::FUN_0090da80(Out* out) {
    Transform t;
    if (this) { Body* b = body; if (b) { FUN_00c24b70(); t.FUN_008fda60(b->transform); FUN_00c24b70(); } }
    FUN_0056ac90(out, &t);
    out->x = (float)(t.m[12] * 6.999040126800537);
    out->y = (float)(t.m[13] * 6.999040126800537);
    out->z = (float)(t.m[14] * 6.999040126800537);
}
}
}   // namespace f3m_0090da80

// @f3 0x0090daf0 (community match, verified in this file)
namespace f3m_0090daf0 {
namespace c_0090daf0 {

struct __declspec(align(16)) Transform
{
    float m[16];
    Transform& FUN_008fda60(const Transform& other);
};

struct Body
{
    int unk00[0x28];
    Transform transform;
};

struct Out
{
    int unk00[8];
    Transform transform;
};

struct Obj
{
    int unk00;
    int unk04;
    Body* body;
    void FUN_008f9940(Out* out);
    void FUN_00c24b70();
    void FUN_0090daf0(Out* out);
};

// pdb: bhkShapePhantom::CopyCinfo | bhkShapePhantom.obj | fnv360_0721_beta, objrun, medium
// pdb params: arInfo
void Obj::FUN_0090daf0(Out* out)
{
    FUN_008f9940(out);
    Transform t;
    if (this)
    {
        Body* b = body;
        if (b)
        {
            FUN_00c24b70();
            t.FUN_008fda60(b->transform);
            FUN_00c24b70();
        }
    }
    out->transform.FUN_008fda60(t);
}

}
}   // namespace f3m_0090daf0

// @f3 0x0090e600 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0090e600 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace n90e600 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
struct __declspec(align(16)) Vec { float v[4]; };
struct Table { Vec* FUN_008fda10(Vec* out, int key); };
struct Src {
    int key;
    int a4;
    int m_08, m_0c, m_10, m_14, m_18, m_1c;
    Table table;
};
struct NewObj {
    virtual ~NewObj();
    unsigned short memSize;
    short refCount;
    NewObj(int a, const Vec& v);
    void FUN_009316f0();
    static void* operator new(unsigned int size)
    {
        Alloc* al = (Alloc*)TlsGetValue(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x31);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        ((Alloc*)TlsGetValue(DAT_010f3170))->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x31);
    }
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
};
}
struct FUN_0090e600_t {
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
    virtual void AddThing(n90e600::NewObj* o);
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void Use(n90e600::Src* s);
    void FUN_0090e600(n90e600::Src* s);
};
// pdb: bhkSimpleShapePhantom::Init | bhkSimpleShapePhantom.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
void FUN_0090e600_t::FUN_0090e600(n90e600::Src* s)
{
    if (!s) return;
    n90e600::Vec v[4];
    n90e600::NewObj* o = new n90e600::NewObj(s->a4, *s->table.FUN_008fda10(&v[0], s->key));
    AddThing(o);
    o->FUN_009316f0();
    Use(s);
}
}   // namespace f3m_0090e600

// @f3 0x0090ee80 (community match, verified in this file)
namespace f3m_0090ee80 {
namespace c_0090ee80 {
struct __declspec(align(16)) Vec4 { float v[4]; };
struct Local {
    Vec4 unk00;
    float unk10;
    int unk14;
    int unk18[2];
    int unk20;
    int unk24[7];
    int unk40;
    bool* FUN_005740c0(bool* out);
};
struct Handler { virtual void Handle(void* a2, Local* l); };
struct Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void Query(bool* out, void* a1, Local* l);
};
struct Desc { int unk00[3]; int type; Shape* shape; };
struct Body { Desc* desc; int unk04; int unk08; };
struct A2 { int unk00[3]; Body* body; };
// pdb: hkPackedNiTriStripsShape::getNextKey | hkPackedNiTriStripsShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: aOldKey
void __stdcall FUN_0090ee80(void* a1, A2* a2, Handler* a3) {
    Body* b = a2->body;
    if (b) {
        Desc* d = b->desc;
        if (b->unk08 && d && d->type == 0x1a) {
            Shape* s = d->shape;
            if (s) {
                bool flag;
                Local local;
                local.unk10 = 1.0f;
                local.unk14 = -1;
                local.unk20 = -1;
                local.unk40 = 0;
                s->Query(&flag, a1, &local);
                if (*local.FUN_005740c0(&flag))
                    a3->Handle(a2, &local);
            }
        }
    }
}
}
}   // namespace f3m_0090ee80

// @f3 0x0090f950 (community match, verified in this file)
#include <new>
namespace f3m_0090f950 {

struct QPt3 {
    float x, y, z;
};

struct QTri {
    unsigned short v[3];
    unsigned short unk06;
};

struct QMeshData {
    int unk00;
    int unk04;
    unsigned int count;
    int unk0C;
    int unk10;
    QTri* tris;
    QPt3* verts;
};

struct __declspec(align(16)) QVec4 {
    float x, y, z, w;
    void setZero4() { x = y = z = w = 0.0f; }
    void mul4(const QVec4& s) { const float* p = &s.x; float* q = &x; for (int i = 0; i < 4; i++) q[i] *= p[i]; }
};

static __forceinline void QSetPt(QVec4& out, unsigned int i, QMeshData* d) {
    QPt3 p = d->verts[i];
    QVec4 t;
    t.x = p.x;
    t.y = p.y;
    t.z = p.z;
    out.x = t.x;
    out.y = t.y;
    out.z = t.z;
}

struct QRefObject {
    unsigned short memSize;
    short refCount;
    QRefObject() : refCount(1) {}
    virtual ~QRefObject();
};

struct QShapeBase : QRefObject {
    int userData;
    int type;
    QShapeBase(int t) { userData = 0; type = t; }
};

struct QConvexBase : QShapeBase {
    float radius;
    QConvexBase(int t, float r) : QShapeBase(t) { radius = r; }
};

struct QTriShape : QConvexBase {
    unsigned short weldingInfo;
    unsigned char weldingType;
    unsigned char isExtruded;
    int unk18;
    int unk1C;
    QVec4 a;
    QVec4 b;
    QVec4 c;
    QVec4 ext;
    __forceinline QTriShape(float r) : QConvexBase(4, r) {
        weldingInfo = 0;
        weldingType = 6;
        ext.setZero4();
        isExtruded = 0;
    }
};

struct QMeshShape {
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
    QMeshData* data;
    int unk78;
    int unk7C;
    QVec4 scale;
    float radius;
    QTriShape* FUN_0090f950(unsigned int key, void* buffer);
};

QTriShape* QMeshShape::FUN_0090f950(unsigned int key, void* buffer)
{
    key &= 0xffffff;
    if (key >= data->count)
        return 0;
    QTri* tri = &data->tris[key];
    QTriShape* shape = new (buffer) QTriShape(radius);
    QSetPt(shape->a, tri->v[0], data);
    QSetPt(shape->b, tri->v[1], data);
    QSetPt(shape->c, tri->v[2], data);
    if (scale.x != 1.0f) {
        shape->a.mul4(scale);
        shape->b.mul4(scale);
        shape->c.mul4(scale);
    }
    return shape;
}
}   // namespace f3m_0090f950

// @f3 0x00916290 (community match, verified in this file)
namespace f3m_00916290 {
namespace c_00916290 {
union __declspec(align(16)) V4 { float f[4]; unsigned int u[4]; };
struct Obj {
    int unk00[8];
    V4 extent;
    float* FUN_00916290(const V4* p, float* out);
};
// pdb: hkpBoxShape::getSupportingVertexImpl | hkpBoxShape.obj | tesv_win, objrun, medium
float* Obj::FUN_00916290(const V4* p, float* out)
{
    V4 s = extent;
    s.u[0] ^= p->u[0] & 0x80000000u;
    s.u[1] ^= p->u[1] & 0x80000000u;
    s.u[2] ^= p->u[2] & 0x80000000u;
    s.u[3] ^= p->u[3] & 0x80000000u;
    s.u[3] = (((s.f[0] < 0.0f) ? 8 : 0) | ((s.f[1] < 0.0f) ? 4 : 0) | ((s.f[2] < 0.0f) ? 2 : 0) | ((s.f[3] < 0.0f) ? 1 : 0)) & 0xe | 0x3f000000u;
    out[0] = s.f[0];
    out[1] = s.f[1];
    out[2] = s.f[2];
    out[3] = s.f[3];
    return out;
}
}
}   // namespace f3m_00916290

// @f3 0x0091a360 (community match, verified in this file)
extern const unsigned char kPattern[72];
extern const float kFrac[3];
extern const double kOneThird;
extern const double kOneSixth;
extern const double kHalf;
namespace f3m_0091a360 {

struct GridPatch {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    float from0;   // 0xa0
    float from1;   // 0xa4
    float from2;   // 0xa8
    float from3;   // 0xac
    float to0;     // 0xb0
    float to1;     // 0xb4
    float to2;     // 0xb8
    float to3;     // 0xbc
    int unkC0; int unkC4; int unkC8; int unkCC;
    int unkD0; int unkD4; int unkD8;
    int pattern;   // 0xdc

    void FUN_0091a360(float *out, int a, int b);
};

void GridPatch::FUN_0091a360(float *out, int a, int b)
{
    int idx = this->pattern;
    unsigned char v = kPattern[3 * (a + 3 * idx) + b];
    int q = v / 3;
    int r = v - q * 3;

    __declspec(align(16)) float d[4];
    d[0] = this->to0 - this->from0;
    d[1] = this->to1 - this->from1;
    d[2] = this->to2 - this->from2;
    d[3] = this->to3 - this->from3;

    d[0] = (kFrac[q] + kOneSixth) * d[0];
    d[1] = (kOneSixth + r * kOneThird) * d[1];
    d[2] = d[2] * kHalf;

    const float *from = &this->from0;
    out[0] = from[0] + d[0];
    out[1] = from[1] + d[1];
    out[2] = from[2] + d[2];
    out[3] = from[3] + d[3];
}
}   // namespace f3m_0091a360

// @f3 0x00902620 (community match, verified in this file)
// hkWorld_setupContactMgrFactories (static, hkpWorld.cpp) written from the Havok 5.5.0 SDK (hkpDynamics.lib, hkpWorld.obj,
// release and hybrid records lines 260-275: three factories made with new on lines 261-263, registered with the
// dispatcher on 268-270, released on 272-274). Bodies copied from hk550: HK_DECLARE_CLASS_ALLOCATOR's operator new and
// delete (Common\Base\Memory\hkThreadMemory.h), hkThreadMemory::getInstancePtr / getInstance (same header),
// hkThreadLocalData<T>::getData and the TlsGetValue declaration (Common\Base\Thread\Thread\hkThreadLocalData.h),
// hkReferencedObject constructor and removeReference (Common\Base\Object\hkReferencedObject.inl), hkpContactMgr,
// hkpNullContactMgr and hkpNullContactMgrFactory constructors (the hkpContactMgr.h, hkpNullContactMgr.h and
// hkpNullContactMgrFactory.h headers). throw() on the two out-of-line Factory constructors: the pack is /EHsc, the
// library was built without /EH.
extern "C" {
    __declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}

namespace f3m_00902620 {
typedef unsigned long hkUlong;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned int hk_size_t;

enum HK_MEMORY_CLASS
{
    HK_MEMORY_CLASS_DYNAMICS = 4,
    HK_MEMORY_CLASS_CONTACT = 34
};

template<typename T>
class hkThreadLocalData
{
public:
    __forceinline T getData() const
    {
        return (T)(hkUlong)TlsGetValue(m_slotID) ;
    }
    unsigned long m_slotID;
};

class hkThreadMemory
{
public:
    static inline hkThreadMemory* getInstancePtr();
    static inline hkThreadMemory& getInstance();
    void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
    void deallocateChunk( void* p, int nbytes, HK_MEMORY_CLASS cl );
};

hkThreadMemory* hkThreadMemory::getInstancePtr()
{
    // move this back to a static member when compiler bug fixed
    // TLS slot to store this threads mem instance.
    extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
    return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& hkThreadMemory::getInstance()
{
    hkThreadMemory* instance = getInstancePtr();
    return *instance;
}

class hkBaseObject
{
public:
    virtual ~hkBaseObject() {}
};

class hkReferencedObject : public hkBaseObject
{
public:
    __forceinline hkReferencedObject();
    virtual ~hkReferencedObject() { }
    __forceinline void removeReference() const;

    hkUint16 m_memSizeAndFlags;
    mutable hkInt16 m_referenceCount;
};

__forceinline hkReferencedObject::hkReferencedObject()
: m_referenceCount(1)
{
}

__forceinline void hkReferencedObject::removeReference() const
{
    if ( m_memSizeAndFlags != 0 )
    {
        --m_referenceCount;

        if ( m_referenceCount == 0 )
        {
            delete this;
        }
    }
}

class hkpWorld;

class hkpContactMgr : public hkReferencedObject
{
public:
    __forceinline void* operator new(hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONTACT)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; }
    __forceinline void operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CONTACT); }

    enum Type
    {
        TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
        TYPE_REPORT_CONTACT_MGR,
        TYPE_CONVEX_LIST_CONTACT_MGR,
        TYPE_NULL_CONTACT_MGR,
        TYPE_USER_CONTACT_MGR,
        TYPE_MAX
    };
    hkpContactMgr( Type type ): m_type(type){}

    Type m_type;
};

class hkpNullContactMgr : public hkpContactMgr
{
public:
    hkpNullContactMgr() : hkpContactMgr( hkpContactMgr::TYPE_NULL_CONTACT_MGR ){}
};

class hkpContactMgrFactory : public hkReferencedObject
{
public:
    __forceinline void* operator new(hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONTACT)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; }
    __forceinline void operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CONTACT); }
};

class hkpNullContactMgrFactory : public hkpContactMgrFactory
{
public:
    __forceinline void* operator new(hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_DYNAMICS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; }
    __forceinline void operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_DYNAMICS); }

    hkpNullContactMgrFactory()
    {
    }

    hkpNullContactMgr m_contactMgr;
};

class hkpSimpleConstraintContactMgr
{
public:
    class Factory : public hkpContactMgrFactory
    {
    public:
        Factory(hkpWorld* mgr) throw();
        hkpWorld* m_world;
    };
};

class hkpReportContactMgr
{
public:
    class Factory : public hkpContactMgrFactory
    {
    public:
        Factory(hkpWorld* world) throw();
        hkpWorld* m_world;
    };
};

class hkpMaterial
{
public:
    enum ResponseType
    {
        RESPONSE_INVALID,
        RESPONSE_SIMPLE_CONTACT,
        RESPONSE_REPORTING,
        RESPONSE_NONE,
        RESPONSE_MAX_ID
    };
};

class hkpCollisionDispatcher
{
public:
    void registerContactMgrFactoryWithAll( hkpContactMgrFactory* fac, int responseA );
};

// pdb: hkWorld_setupContactMgrFactories | hkpWorld.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
static void hkWorld_setupContactMgrFactories( hkpWorld* world, hkpCollisionDispatcher* dis )
{
    hkpContactMgrFactory* simple = new hkpSimpleConstraintContactMgr::Factory( world );
    hkpContactMgrFactory* rep    = new hkpReportContactMgr::Factory( world );
    hkpContactMgrFactory* none   = new hkpNullContactMgrFactory();

    dis->registerContactMgrFactoryWithAll( simple, hkpMaterial::RESPONSE_SIMPLE_CONTACT );
    dis->registerContactMgrFactoryWithAll( rep,    hkpMaterial::RESPONSE_REPORTING );
    dis->registerContactMgrFactoryWithAll( none,   hkpMaterial::RESPONSE_NONE );

    simple->removeReference();
    rep->removeReference();
    none->removeReference();
}

// caller: the world's constructor sets up the factories of its dispatcher
struct hkpWorldSetup
{
    hkpWorld* m_world;
    hkpCollisionDispatcher* m_collisionDispatcher;
    void setupContactMgrFactories();
};

void hkpWorldSetup::setupContactMgrFactories()
{
    hkWorld_setupContactMgrFactories( m_world, m_collisionDispatcher );
}
}

// @f3 0x009091b0 (community match, verified in this file)
namespace f3m_009091b0 {
struct F3Inner9091b0 {
    char pad_00[0x18];
    int f18;
    int f1c;
    void FUN_00908a00();
};

struct F3Item9091b0 {
    virtual void v00();
    virtual void v04();
    virtual void v08(int a, int b, int c, int d, int e);
};

struct F3O9091b0 {
    char pad_00[8];
    F3Item9091b0** items;
    int count;
    int unk10;
    F3Inner9091b0* inner;
    void FUN_009091b0(int a1, int a2, int a3, int a4, int a5);
};

void F3O9091b0::FUN_009091b0(int a1, int a2, int a3, int a4, int a5)
{
    extern void (__stdcall* DAT_00d9b0a0)(void* p);
    inner->FUN_00908a00();
    for (int i = 0; i < count; i++)
        items[i]->v08(a1, a2, a3, a4, a5);
    F3Inner9091b0* h = inner;
    h->f18 = -1;
    h->f1c = -1;
    DAT_00d9b0a0(h);
}
}   // namespace f3m_009091b0

// @f3 0x00909150 (community match, verified in this file)
namespace f3m_00909150 {
// pdb: hkDebugDisplay::displayRayModelSpace | hkDebugDisplay.obj | fnv360_0822_retail, objrun_open, low
// pdb params: worldFromModel, start, direction, color, id, tag
namespace Notify9091 {extern void (__stdcall* DAT_00d9b0a0)(void*);struct Lock{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int owner;int count;void FUN_00908a00();void Leave(){owner=-1;count=-1;DAT_00d9b0a0(this);}};struct Listener;struct Table{void* unk00;void (__thiscall* notify)(Listener*,int,int,int,int,int);};struct Listener{Table* table;};struct Dispatch{int unk00;int unk04;Listener** items;int count;int unk10;Lock* lock;void FUN_00909150(int,int,int,int,int);};void Dispatch::FUN_00909150(int a,int b,int c,int d,int e){lock->FUN_00908a00();for(int i=0;i<count;++i){Listener* item=items[i];item->table->notify(item,a,b,c,d,e);}lock->Leave();}}
}   // namespace f3m_00909150

// @f3 0x00903630 (community match, verified in this file)
namespace f3m_00903630 {
// claim clm_48e5cc7c14b14583991b -- FUN_00903630 at 0x00903630, 76 bytes
// thiscall (ret 8): two stack args, ecx = outer object.
//   arg1 (esi) = polymorphic object, arg2 = dword value
//   if (this->unk84) build a 12-byte command {byte 0x22, arg1, arg2} on the stack and
//   pass it to a member; else call arg1's virtual function at vtable +0xc with arg2.
//   both arms return arg1.

struct Cmd903630
{
    unsigned char type;
    void* obj;
    int arg;
};

struct Inner903630
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int arg);
};

struct Obj903630
{
    char pad7c[0x7c];
    Inner903630* inner;
    int unk80;
    int unk84;
    void FUN_00902570(Cmd903630* cmd);
    Inner903630* FUN_00903630(Inner903630* obj, int value);
};

// pdb: hkpWorld::queueCallback | hkpWorld.obj | fnv360_0822_retail, objrun_open, low
// pdb params: callback, userData
Inner903630* Obj903630::FUN_00903630(Inner903630* obj, int value)
{
    if (unk84 != 0)
    {
        Cmd903630 cmd;
        cmd.type = 0x22;
        cmd.obj = obj;
        cmd.arg = value;
        FUN_00902570(&cmd);
    }
    else
    {
        obj->v3(value);
    }
    return obj;
}
}   // namespace f3m_00903630

// @f3 0x009035e0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009035e0 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

namespace world_system_9035e0 {
struct Memory {
    void* FUN_008f6d30(int bytes, int memoryClass);
};
struct ObjectArray {
    void** data;
    int size;
    int capacity;
    void** end() const { return data + size; }
};
struct PhysicsSystem {
    void* vtable;
    unsigned short allocationSize;
    short references;
    ObjectArray rigidBodies, constraints, actions, phantoms;
    const char* name;
    unsigned userData;
    unsigned char active;
    PhysicsSystem* FUN_0098a090();
    void FUN_00989fb0(void* phantom);
};
struct Border {
    void* reserved[5];
    void* phantoms[6];
};
struct WorldState {
    void* fields00[10];
    ObjectArray activeIslands;
    ObjectArray inactiveIslands;
    char fields40[0xa4];
    ObjectArray phantoms;
    Border* FUN_00902500();
    PhysicsSystem* FUN_009035e0();
};
struct Flag { unsigned char value; };
extern Flag* __cdecl FUN_00903290(Flag*, WorldState*, PhysicsSystem*);
extern Flag* __cdecl FUN_00903360(Flag*, WorldState*, PhysicsSystem*);
extern void __cdecl FUN_009033f0(void* island, PhysicsSystem*);
extern void __cdecl FUN_009034c0(WorldState*, PhysicsSystem*);

static __declspec(noinline) void FUN_009033c0(WorldState* world, PhysicsSystem* system) {
    Flag result;
    FUN_00903290(&result, world, system);
    system->active = FUN_00903360(&result, world, system)->value;
}
static __declspec(noinline) void FUN_00903550(WorldState* world, PhysicsSystem* system) {
    Border* border = world->FUN_00902500();
    if (border) {
        for (int i = 0; i < world->phantoms.size; ++i) {
            void* p = world->phantoms.data[i];
            if (p != border->phantoms[0] && p != border->phantoms[1] &&
                p != border->phantoms[2] && p != border->phantoms[3] &&
                p != border->phantoms[4] && p != border->phantoms[5]) {
                system->FUN_00989fb0(p);
            }
        }
    } else {
        for (int i = 0; i < world->phantoms.size; ++i)
            system->FUN_00989fb0(world->phantoms.data[i]);
    }
}
static __declspec(noinline) void FUN_00903460(WorldState* world, PhysicsSystem* system) {
    for (void** it = world->activeIslands.data; it != world->activeIslands.end(); ++it)
        FUN_009033f0(*it, system);
    for (void** it = world->inactiveIslands.data; it != world->inactiveIslands.end(); ++it)
        FUN_009033f0(*it, system);
}
// pdb: hkpWorld::getWorldAsOneSystem | hkpWorld.obj | fnv360_0822_retail, objopen_prop, low
PhysicsSystem* WorldState::FUN_009035e0() {
    Memory* memory = static_cast<Memory*>(DAT_00d9b080(DAT_010f3170));
    PhysicsSystem* block = static_cast<PhysicsSystem*>(memory->FUN_008f6d30(sizeof(PhysicsSystem), 0x2f));
    block->allocationSize = sizeof(PhysicsSystem);
    PhysicsSystem* system = block->FUN_0098a090();
    FUN_009033c0(this, system);
    FUN_00903550(this, system);
    FUN_00903460(this, system);
    FUN_009034c0(this, system);
    return system;
}
}
}   // namespace f3m_009035e0

// @f3 0x0091afd0 (community match, verified in this file)
namespace f3m_0091afd0 {
struct __declspec(align(16)) S0091afd0_Vec4 { float x, y, z, w; };

class hkpShape
{
  public:
    void* vtbl;
    int m_referenceCount;
    unsigned int m_userData;
    int m_type;
};

class hkpCdBody
{
  public:
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

class hkBool
{
  public:
    operator bool() const { return m_bool != 0; }
    void operator=(bool b) { m_bool = (char)b; }
    char m_bool;
};

class hkpCdBodyPairCollector
{
  public:
    hkpCdBodyPairCollector() { }
    virtual ~hkpCdBodyPairCollector() { }
    virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB) = 0;
    void reset() { m_earlyOut = false; }
    hkBool m_earlyOut;
};

struct hkpRootCdBodyPair
{
    const hkpCdBody* rootA;
    unsigned int keyA;
    const hkpCdBody* rootB;
    unsigned int keyB;
};

class hkpFirstCdBodyPairCollector : public hkpCdBodyPairCollector
{
  public:
    hkpFirstCdBodyPairCollector() { reset(); }
    virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
    hkpRootCdBodyPair m_hit;
    bool hasHit() const { return m_earlyOut; }
};

struct hkpCollisionInput;
typedef void (__cdecl* S0091afd0_GetPenetrationsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector);

struct S0091afd0_AgentFuncs
{
    void* m_createFunc;
    S0091afd0_GetPenetrationsFunc m_getPenetrationsFunc;
    void* m_getClosestPointsFunc;
    void* m_linearCastFunc;
    bool m_isFlipped;
    bool m_isPredictive;
};

struct S0091afd0_Dispatcher
{
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
    unsigned char m_agent2Types[32][32];
    unsigned char m_agent2TypesPred[32][32];
    S0091afd0_AgentFuncs m_agent2Func[64];

    S0091afd0_GetPenetrationsFunc getGetPenetrationsFunc(int typeA, int typeB) const
    {
        return m_agent2Func[m_agent2Types[typeA][typeB]].m_getPenetrationsFunc;
    }
};

struct hkpCollisionInput
{
    S0091afd0_Dispatcher* m_dispatcher;
};

struct S0091afd0_World
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
    hkpCollisionInput* unk6c;
};

struct S0091afd0_RigidBody
{
    void* vtbl;
    int m_memSizeAndFlags;
    void* m_world;
    unsigned int m_userData;
    hkpCdBody m_collidable;
};

class S0091afd0_Wrapper
{
  public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
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
    virtual void v52(); virtual void SetPosition(const S0091afd0_Vec4& pos);
    int unk04;
    S0091afd0_RigidBody* unk08;
    const hkpCdBody* GetCollidable() { return unk08 ? &unk08->m_collidable : 0; }
};

class S0091afd0_Phantom
{
  public:
    int unk00;
    int unk04;
    S0091afd0_World* unk08;
    int unk0c;
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
    const hkpCdBody** queryBodies;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    int queryBodyCount;
    unsigned int unkd8;
    unsigned int unkdc;
    S0091afd0_Wrapper* unkE0;
    void FUN_0091a360(S0091afd0_Vec4* out, unsigned int column, unsigned int row);
    bool FUN_0091afd0(const hkpCdBody* body, void* scratch, unsigned int column, unsigned int row);
};

bool S0091afd0_Phantom::FUN_0091afd0(const hkpCdBody* body, void* scratch, unsigned int column, unsigned int row)
{
    S0091afd0_Vec4 pos;
    FUN_0091a360(&pos, column, row);
    unkE0->SetPosition(pos);
    const hkpCollisionInput* input = unk08->unk6c;
    S0091afd0_Dispatcher* dispatcher;
    const hkpCdBody* mine;
    if (unkE0) {
        dispatcher = input->m_dispatcher;
        mine = unkE0->GetCollidable();
    } else {
        dispatcher = input->m_dispatcher;
        mine = 0;
    }
    int typeA = mine->m_shape->m_type;
    if (body->m_shape) {
        int typeB = body->m_shape->m_type;
        S0091afd0_GetPenetrationsFunc fn = dispatcher->getGetPenetrationsFunc(typeA, typeB);
        hkpFirstCdBodyPairCollector collector;
        fn(*mine, *body, *input, collector);
        return collector.hasHit();
    }
    return false;
}
}   // namespace f3m_0091afd0

// @f3 0x009172d0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009172d0 {
namespace f3m_009172d0 {
struct Input { int unk00; unsigned short memSize; };
struct Manager { void FUN_008f6d90(Input* input, unsigned int size, int kind); };
extern Manager* (__stdcall * const DAT_00d9b080)(unsigned long index);
void __cdecl FUN_009172d0(Input* input) {
    Manager* manager = DAT_00d9b080(DAT_010f3170);
    manager->FUN_008f6d90(input, input->memSize, 0x3d);
}
}
}   // namespace f3m_009172d0

// @f3 0x009172f0 (community match, verified in this file)
extern int DAT_00e3655c;
namespace f3m_009172f0 {
namespace f3m_009172f0 {
extern void (__stdcall* DAT_00e36564)(void*);
struct SimpleArray {
    void* vtable;
    void* data;
    unsigned size;
    unsigned capacity;
    void FUN_009172f0();
};
void SimpleArray::FUN_009172f0() {
    vtable = &DAT_00e3655c;
    if (data) {
        DAT_00e36564(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
}
}
}   // namespace f3m_009172f0

// @f3 0x0090b5b0 (community match, verified in this file)
namespace f3m_0090b5b0 {
class hkpShape;
namespace f3m_0090b5b0
{
class hkBaseObject
{
public:
    virtual ~hkBaseObject() {}
};
class hkReferencedObject : public hkBaseObject
{
public:
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    hkReferencedObject() : m_referenceCount(1) {}
    virtual ~hkReferencedObject() {}
};
class hkpMotion : public hkReferencedObject
{
public:
    unsigned char m_type;
    char m_body[0x118 - 9];
    void* m_savedMotion;
    unsigned short m_savedQualityTypeIndex;
    hkpMotion() { m_savedMotion = 0; }
    virtual ~hkpMotion() {}
};
class hkpKeyframedRigidMotion : public hkpMotion
{
public:
    hkpKeyframedRigidMotion() {}
    virtual ~hkpKeyframedRigidMotion() {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
public:
    hkpMaxSizeMotion() {}
    virtual ~hkpMaxSizeMotion() {}
};
template <class T> struct hkSmallArray
{
    T* m_data;
    unsigned short m_size;
    unsigned short m_capacityAndFlags;
    hkSmallArray() : m_data(0), m_size(0), m_capacityAndFlags(0x8000) {}
};
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
};
struct hkpMaterial
{
    signed char m_responseType;
    float m_friction;
    float m_restitution;
    hkpMaterial() : m_friction(0.5f), m_restitution(0.4f) {}
};
struct SpuCollisionCallback
{
    void* m_util;
    unsigned short m_capacity;
    unsigned char m_eventFilter;
    unsigned char m_userFilter;
    SpuCollisionCallback() : m_util(0), m_capacity(0), m_eventFilter(3), m_userFilter(1) {}
};
class hkpWorldObject : public hkReferencedObject
{
public:
    hkpWorldObject(const hkpShape* shape, int type);
    virtual ~hkpWorldObject();
    char m_world[0x80 - 8];
};
}
class FUN_0090b5b0 : public f3m_0090b5b0::hkpWorldObject
{
public:
    f3m_0090b5b0::hkpMaterial m_material;
    void* m_breakOffPartsUtil;
    unsigned int m_solverData;
    unsigned short m_storageIndex;
    unsigned short m_processContactCallbackDelay;
    f3m_0090b5b0::hkSmallArray<void*> m_constraintsMaster;
    f3m_0090b5b0::hkArray<void*> m_constraintsSlave;
    f3m_0090b5b0::hkArray<unsigned char> m_constraintRuntime;
    void* m_simulationIsland;
    signed char m_autoRemoveLevel;
    unsigned char m_numUserDatasInContactPointProperties;
    unsigned int m_uid;
    f3m_0090b5b0::SpuCollisionCallback m_spuCollisionCallback;
    void* m_extendedListeners;
    f3m_0090b5b0::hkpMaxSizeMotion m_motion;
    f3m_0090b5b0::hkSmallArray<void*> m_contactListeners;
    f3m_0090b5b0::hkSmallArray<void*> m_actions;
    FUN_0090b5b0(const hkpShape* shape);
    virtual ~FUN_0090b5b0();
};
// pdb: hkpEntity::hkpEntity | hkpEntity.obj | fnv360_0822_debug, caller_sim, high
// pdb params: shape
FUN_0090b5b0::FUN_0090b5b0(const hkpShape* shape)
    : f3m_0090b5b0::hkpWorldObject(shape, 1)
{
    m_simulationIsland = 0;
    m_extendedListeners = 0;
    m_breakOffPartsUtil = 0;
    m_solverData = 0;
    m_numUserDatasInContactPointProperties = 0;
    m_storageIndex = 0xffff;
    m_uid = 0xffffffff;
}
}   // namespace f3m_0090b5b0

// @f3 0x00919e50 (community match, verified in this file)
extern void* DAT_00e36654[];
namespace f3m_00919e50 {
namespace w919e50 {
struct Manager
{
    void** m_vtable;
    unsigned short m_memSizeAndFlags;
    mutable short m_referenceCount;
    void addReference() const { if (m_memSizeAndFlags != 0) ++m_referenceCount; }
};
struct hkBool
{
    char m_bool;
    hkBool(bool b) { m_bool = static_cast<char>(b); }
};
struct RefObj
{
    void** m_vtable;
    unsigned short m_memSizeAndFlags;
    mutable short m_referenceCount;
    RefObj(void** vt) : m_referenceCount(1) { m_vtable = vt; }
};
class FUN_00919e50 : public RefObj
{
public:
    int m_characterType;
    const Manager* m_stateManager;
    int m_currentState;
    int m_previousState;
    hkBool m_filterEnable;
    float m_maxLinearAcceleration;
    float m_maxLinearVelocity;
    float m_gain;
    FUN_00919e50(const Manager* manager, int initialState);
};
// pdb: bhkCharacterPointCollector::bhkCharacterPointCollector | bhkCharacterPointCollector.obj | fnv360_0721_beta, call_seq, low
// pdb params: apStartCollector
FUN_00919e50::FUN_00919e50(const Manager* manager, int initialState)
    : RefObj(DAT_00e36654), m_characterType(0), m_stateManager(manager), m_currentState(initialState), m_previousState(initialState),
      m_filterEnable(true)
{
    m_maxLinearVelocity = 20.0f;
    m_maxLinearAcceleration = 625.0f;
    m_gain = 1.0f;
    m_stateManager->addReference();
}
}
}   // namespace f3m_00919e50

// @f3 0x00915e30 (community match, verified in this file)
namespace f3m_00915e30 {
class NiMemObject
{
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* memory, unsigned int size);
};

class NiCloningProcess;

class bhkBlendController : public NiMemObject, public ::f3m_00915b70::C915Owner
{
public:
    bhkBlendController();
    bhkBlendController* FUN_00915e30(NiCloningProcess& process);
private:
    float field50, field54;
    unsigned int field58;
};

typedef char BlendControllerSizeCheck[sizeof(bhkBlendController) == 0x5c ? 1 : -1];

bhkBlendController* bhkBlendController::FUN_00915e30(NiCloningProcess& process)
{
    bhkBlendController* clone = new bhkBlendController;
    FUN_00915b70(clone, &process);
    return clone;
}
}   // namespace f3m_00915e30
