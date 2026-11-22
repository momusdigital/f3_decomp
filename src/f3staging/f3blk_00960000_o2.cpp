#include <math.h>
#include <math.h>
#include <windows.h>
// src/f3staging/f3blk_00960000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00978cb0 (community match, verified in this file)
extern const char DAT_00e7c964[];
extern const char DAT_00e7c954[];
class StatisticsCollector97 {
public:
    virtual void slot0();
    virtual void beginObject(const char* name, int type, const void* object);
    virtual void addArray(const char* name, int type, const void* data, int size, int capacity);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void endObject();
};
class StatisticsObject97 {
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
    void* overlaps;
    int overlapCount;
    int overlapCapacity;
    void hkpPhantom_calcContentStatistics(StatisticsCollector97*) const;
    void hkpAabbPhantom_calcContentStatistics(StatisticsCollector97*) const;
};
// pdb: hkpAabbPhantom::calcContentStatistics | hkpAabbPhantom.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void StatisticsObject97::hkpAabbPhantom_calcContentStatistics(StatisticsCollector97* collector) const
{
    collector->beginObject(DAT_00e7c964, 2, this);
    hkpPhantom_calcContentStatistics(collector);
    if ((static_cast<unsigned int>(overlapCapacity) & 0x80000000u) == 0)
        collector->addArray(DAT_00e7c954, 8, overlaps, overlapCount * 4, (overlapCapacity & 0x3fffffff) * 4);
    collector->endObject();
}

// @f3 0x009786b0 (community match, verified in this file)
namespace f3m_009786b0 {
namespace f3m_009786b0 {

struct Vector4 {
    float x, y, z, w;
};

class Member40 {
public:
    void hkSweptTransform_initSweptTransform(const Vector4& position, int arg);
};

class Body {
public:
    void hkRotation_set(int arg);
    void hkMotionState_initMotionState(const Vector4& position, int arg);

    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    Vector4 m_position;
    Member40 m_member40;
    int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    Vector4 m_velocity;
    float m_scale;
};

}

using namespace f3m_009786b0;

// pdb: hkMotionState::initMotionState | hkMotionState.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void Body::hkMotionState_initMotionState(const Vector4& position, int arg)
{
    m_member40.hkSweptTransform_initSweptTransform(position, arg);
    hkRotation_set(arg);
    m_position.x = position.x;
    m_position.y = position.y;
    m_position.z = position.z;
    m_position.w = position.w;
    m_velocity.x = m_velocity.y = m_velocity.z = m_velocity.w = 0.0f;
    m_scale = 1.0f;
}
}   // namespace f3m_009786b0

// @f3 0x0097e7f0 (community match, verified in this file)
namespace f3m_0097e7f0 {
class Allocator97 {
public:
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
    virtual void* allocate(int size);
};
extern Allocator97* DAT_010f3400;

class Copier97 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int copy(int value, int a, int b, int size, void* memory);
};
}

int __cdecl FUN_0097e7f0(int* value, int a, int count2, int count3, int elemSize, int b, f3m_0097e7f0::Copier97* copier)
{
    void* memory = f3m_0097e7f0::DAT_010f3400->allocate(count3 * elemSize);
    return copier->copy(*value, b, a, count2 * elemSize, memory);
}

// @f3 0x00970d40 (community match, verified in this file)
namespace f3m_00970d40 {
namespace f3m_00970d40 {
struct Arr970
{
    void* data;
    int size;
    int capacityAndFlags;
    Arr970() : data(0), size(0), capacityAndFlags(0x80000000) {}
};

struct Data970
{
    int unk00;
    float unk04;
    Arr970 arr08;
    Arr970 arr14;
    Data970() : unk00(0) {}
    ~Data970();
};

struct Src970
{
    int unk00;
    int unk04;
};

void __cdecl FUN_009e8ae0(Src970* src, Arr970* second, Arr970* first);

struct Obj970
{
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    static void* operator new(unsigned int size);
    Obj970(Data970* data);
};

// pdb: bhkCharControllerShape::CreateFromHull | bhkCharControllerShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arVerts
Obj970* __cdecl FUN_00970d40(Src970* src)
{
    Obj970* result = 0;
    Data970 data;
    data.unk04 = 0.1f;
    if (src->unk04 != 0) {
        FUN_009e8ae0(src, &data.arr14, &data.arr08);
        result = new Obj970(&data);
    }
    return result;
}
}
}   // namespace f3m_00970d40

// @f3 0x00969f20 (community match, verified in this file)
namespace f3m_00969f20 {
struct Item6 { void FUN_009316f0(); };
struct Owner6 {
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
    Item6** items;
    int count;
    unsigned int unk22c, unk230, value234, unk238, unk23c, value240;
    void FUN_00969f20();
};
// pdb: hkArrayBase<Match>::_expandOne | hkaSkeletonMapperUtils.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: hkpAllCdPointCollector::addRootCdPoint)
// pdb params: alloc
void Owner6::FUN_00969f20() {
    for (int i=0; i<count; ++i) items[i]->FUN_009316f0();
    count=0;
    value240=0;
    value234=0;
}
}   // namespace f3m_00969f20

// @f3 0x0097f4f0 (community match, verified in this file)
namespace f3m_0097f4f0 {
struct Info13 {};
struct Entity13 { virtual void a(); virtual void b(); virtual void c(); virtual void Process(Info13*); };
struct EntityArray13 { Entity13** data; int count; };
struct Island13 {
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
    EntityArray13 entities;
};
struct IslandArray13 { Island13** data; int count; };
struct World13 {
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
    IslandArray13 islands;
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
    Info13 info;
};
struct Sim13 { int unk00,unk04,unk08; World13* world; void FUN_0097f4f0(); };
// pdb: hkpWorld::getMemUsageForIntegration | hkpWorld.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkpSimulation::applyActions)
// pdb params: infoOut
void Sim13::FUN_0097f4f0() {
    IslandArray13& islands = world->islands;
    for (int i=0; i<islands.count; ++i) {
        EntityArray13& entities = islands.data[i]->entities;
        for (int j=0; j<entities.count; ++j) entities.data[j]->Process(&world->info);
    }
}
}   // namespace f3m_0097f4f0

// @f3 0x0097adb0 (community match, verified in this file)
namespace f3m_0097adb0 {
struct Shape25 { unsigned int unk00; unsigned short enabled, references; void AddReference() { if(enabled) ++references; } };
struct Child25 { Shape25* shape; int filter; int zero; int count; };
struct Array25 { Child25* data; int count; int capacity; };
void __cdecl FUN_00901e90(Array25*,int,int);
struct Owner25 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;
    Array25 children;
    void FUN_0097aae0();
    void FUN_0097adb0(Shape25**, int, int*);
};
// pdb: hkpListShape::setShapes | hkpListShape.obj | tesv_win, call_gap_sim, low
void Owner25::FUN_0097adb0(Shape25** shapes, int count, int* filters) {
    Array25& entries=children;
    int capacity=entries.capacity & 0x3fffffff;
    if(capacity<count) {
        int increased=capacity*2;
        if(count>=increased) increased=count;
        FUN_00901e90(&entries,increased,16);
    }
    entries.count=count;
    if(count>0) {
        Shape25** current=shapes;
        int offset=0;
        volatile int difference=(char*)filters-(char*)shapes;
        int remaining=count;
        do {
            Shape25* shape=*current;
            if(shape) {
                ((Child25*)((char*)entries.data+offset))->shape=shape;
                int filter=filters ? *(int*)((char*)current+difference) : 0;
                ((Child25*)((char*)entries.data+offset))->filter=filter;
                (*current)->AddReference();
                ((Child25*)((char*)children.data+offset))->count=count;
                ((Child25*)((char*)children.data+offset))->zero=0;
            }
            ++current;
            offset+=16;
        } while(--remaining);
    }
    FUN_0097aae0();
}
}   // namespace f3m_0097adb0

// @f3 0x0097a820 (community match, verified in this file)
namespace creator_factory_1589 {
struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;
struct Creator {
    unsigned int unk00,unk04,unk08,unk0C,unk10;
    Creator* FUN_0092d590();
    Creator* FUN_007c4f60();
    Creator* FUN_008fa8b0();
    Creator* FUN_0097a800();
    Creator* FUN_0094b680();
    Creator* FUN_0092d5b0();
    Creator* FUN_008f25a0();
    Creator* FUN_00948b40();
    Creator* FUN_0094bb80();
    Creator* FUN_00947ee0();
    Creator* FUN_0091bea0();
};
// pdb: hkPointToPathConstraintCinfo::`scalar deleting destructor' | bhkConstraintManager.obj | fnv360_0721_beta, objrun, low, conflict (bridge: bhkConstraintManager::GetInfo)
Creator* __cdecl FUN_0097a820(unsigned int kind) {
    switch(kind) {
    case 0: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_0092d590() : 0;
    }
    case 1: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_007c4f60() : 0;
    }
    case 2: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_008fa8b0() : 0;
    }
    case 3: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_0097a800() : 0;
    }
    case 6: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_0094b680() : 0;
    }
    case 7: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_0092d5b0() : 0;
    }
    case 8: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_008f25a0() : 0;
    }
    case 9: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_00948b40() : 0;
    }
    case 10: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_0094bb80() : 0;
    }
    case 12: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_00947ee0() : 0;
    }
    case 13: {
        Creator* creator=static_cast<Creator*>(DAT_01090a78.FUN_0086b930(sizeof(Creator)));
        return creator ? creator->FUN_0091bea0() : 0;
    }
    default: return 0;
    }
}
}

// @f3 0x0097e8d0 (community match, verified in this file)
extern void* DAT_0116bf44;
namespace f3m_0097e8d0 {
void* __cdecl FUN_0097e8d0(void* p) { if (!p) p = DAT_0116bf44; return p; }
}   // namespace f3m_0097e8d0

// @f3 0x0097e8e0 (community match, verified in this file)
struct G97e8e0 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void Target(int a); };
extern G97e8e0* DAT_011693a8;
// pdb: hkStatisticsCollector::findClassType | hkStatisticsCollector.obj | tesv_win, call_seq, medium
void __cdecl FUN_0097e8e0(int a) { DAT_011693a8->Target(a); }

// @f3 0x00970e90 (community match, verified in this file)
namespace f3m_00970e90 {
struct V970e90 { float x, y, z, w; };
// pdb: hkpSphereShape::getCollisionSpheresImpl | hkpSphereShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpSphereShape::getCentreImpl)
// pdb params: sphereBuffer
void __stdcall FUN_00970e90(V970e90* v) { v->x = v->y = v->z = v->w = 0.0f; }
}   // namespace f3m_00970e90

// @f3 0x00970eb0 (community match, verified in this file)
namespace f3m_00970eb0 {
struct V970eb0 { float x, y, z, w; };
// pdb: hkpSphereShape::getFirstVertex | hkpSphereShape.obj | tesv_win, objrun_open, low
void __stdcall FUN_00970eb0(V970eb0* v) { v->x = v->y = v->z = v->w = 0.0f; }
}   // namespace f3m_00970eb0

// @f3 0x00970e40 (community match, verified in this file)
namespace f3m_00970e40 {
struct V970e40 { float x, y, z, w; };
// pdb: hkpSphereShape::convertVertexIdsToVerticesImpl | hkpSphereShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpSphereShape::getSupportingVertexImpl)
// pdb params: ids, numIds, verticesOut
void __stdcall FUN_00970e40(int unused, V970e40* v) { v->x = v->y = v->z = v->w = 0.0f; }
}   // namespace f3m_00970e40

// @f3 0x0097a050 (community match, verified in this file)
namespace f3m_0097a050 {
struct C97a050 { char pad[0x13]; unsigned char flag; };
struct O97a050 { char pad[0x1c]; unsigned char flag; char pad2[0xb]; C97a050* child; void hkpConstraintInstance_setPriority(unsigned char v); };
// pdb: hkpConstraintInstance::setPriority | hkpConstraintInstance.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void O97a050::hkpConstraintInstance_setPriority(unsigned char v) { flag = v; if (child) child->flag = v; }
}   // namespace f3m_0097a050

// @f3 0x00970f40 (community match, verified in this file)
namespace f3m_00970f40 {
struct V970f40 { float x, y, z, w; };
struct O970f40 { char pad[0x10]; float f; void FUN_00970f40(V970f40* out); };
// pdb: hkpSphereShape::getAabbImpl | hkpSphereShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpSphereShape::getCollisionSpheresImpl)
// pdb params: localToWorld, tolerance, out
void O970f40::FUN_00970f40(V970f40* out) { out->x = out->y = out->z = out->w = 0.0f; out->w = f; }
}   // namespace f3m_00970f40

// @f3 0x0097a800 (community match, verified in this file)
namespace f3m_0097a800 {
namespace f3m_0097a800 { extern char DAT_00e7d138; }
struct O0097a800 { void* vt; int a4, a8, ac, a10; O0097a800* FUN_0097a800(); };
O0097a800* O0097a800::FUN_0097a800() { a4 = 0; ac = 0; a10 = 0; a8 = 1; vt = &f3m_0097a800::DAT_00e7d138; return this; }
}   // namespace f3m_0097a800

// @f3 0x0097dd40 (community match, verified in this file)
namespace f3m_0097dd40 {
struct A97dd40 { void FUN_008fda60(int a); };
struct B97dd40 { void FUN_00924360(A97dd40* p); };
struct O97dd40 { char pad[0x20]; B97dd40 b; char pad2[0xf]; A97dd40 a; void FUN_0097dd40(int v); };
// pdb: hkpTransformShape::setTransform | hkpTransformShape.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: transform
void O97dd40::FUN_0097dd40(int v) { a.FUN_008fda60(v); b.FUN_00924360(&a); }
}   // namespace f3m_0097dd40

// @f3 0x00972630 (community match, verified in this file)
namespace f3m_00972630 {
struct Sub972630 { void FUN_0096cd10(float v); };
struct O972630 { int a0; float f4; char pad[0x18]; Sub972630 sub; void FUN_00972630(float v); };
// pdb: hkpMassProperties::scaleToMass | hkInertiaTensorComputer.obj | tesv_win, call_seq, medium
void O972630::FUN_00972630(float v) { float r = v / f4; f4 = v; sub.FUN_0096cd10(r); }
}   // namespace f3m_00972630

// @f3 0x0097ee00 (community match, verified in this file)
namespace f3m_0097ee00 {
void* __cdecl FUN_0097e8d0(void* p);
void __cdecl FUN_0097e840(int z, void* a, void* b, void* c, void* d);
// pdb: hkStatisticsCollectorUtil::defaultCalcStatistics | hkStatisticsCollectorUtil.obj | tesv_win, caller_sim, low
void __cdecl FUN_0097ee00(void* a, void* b, void* c, void* d) { FUN_0097e840(0, a, b, c, FUN_0097e8d0(d)); }
}   // namespace f3m_0097ee00

// @f3 0x00970f60 (community match, verified in this file)
namespace f3m_00970f60 {
namespace f3m_00970f60 { extern char DAT_00e7c8d4; }
struct O970f60 { void* vt; char pad[2]; unsigned short w6; int a8; int ac; float f10; O970f60* FUN_00970f60(float v); };
// pdb: hkpSphereShape::hkpSphereShape | hkpSphereShape.obj | fnv360_0822_retail, call_seq, high
// pdb params: radius
O970f60* O970f60::FUN_00970f60(float v) { f10 = v; w6 = 1; a8 = 0; ac = 2; vt = &f3m_00970f60::DAT_00e7c8d4; return this; }
}   // namespace f3m_00970f60

// @f3 0x0097dc60 (community match, verified in this file)
namespace f3m_0097dc60 {
struct O97dc60 { char pad[0x40]; unsigned int bits[8]; unsigned int FUN_0097dc60(unsigned int i); };
unsigned int O97dc60::FUN_0097dc60(unsigned int i) { if (i >= 0x100) return 1; return (1u << (i & 31)) & bits[i >> 5]; }
}   // namespace f3m_0097dc60

// @f3 0x00970e60 (community match, verified in this file)
namespace f3m_00970e60 {
struct V970e60 { float x, y, z, w; };
// pdb: hkpSphereShape::getAabbImpl | hkpSphereShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpSphereShape::convertVertexIdsToVerticesImpl)
// pdb params: localToWorld, tolerance, out
void __stdcall FUN_00970e60(int a, int count, V970e60* p) { for (int i = count - 1; i >= 0; i--) { p->w = 0.0f; p->z = 0.0f; p->y = 0.0f; p->x = 0.0f; p++; } }
}   // namespace f3m_00970e60

// @f3 0x0097eef0 (community match, verified in this file)
namespace f3m_0097eef0 {
int __cdecl FUN_0097e8e0(int a);
void __cdecl FUN_0097eaf0(int a, int r, int b, int c);
void __cdecl FUN_0097eef0(int a, int b, int c) { int r = FUN_0097e8e0(a); if (r) FUN_0097eaf0(a, r, b, c); }
}   // namespace f3m_0097eef0

// @f3 0x0097ef20 (community match, verified in this file)
namespace f3m_0097ef20 {
int __cdecl FUN_0097e8e0(int a);
void __cdecl FUN_0097edb0(int a, int r, int b, int c);
// pdb: hkStatisticsCollectorUtil::addClassContentsAll | hkStatisticsCollectorUtil.obj | tesv_win, caller_sim, low
void __cdecl FUN_0097ef20(int a, int b, int c) { int r = FUN_0097e8e0(a); if (r) FUN_0097edb0(a, r, b, c); }
}   // namespace f3m_0097ef20

// @f3 0x0097a020 (community match, verified in this file)
namespace f3m_0097a020 {
namespace f3m_0097a020 { extern char DAT_00e7ce98; }
struct O97a020 { void* vt; unsigned short w4; unsigned short w6; int a8; int ac; int a10; int a14; int a18; unsigned char b1c, b1d; char pad[2]; int a20, a24, a28; O97a020* FUN_0097a020(unsigned char v); };
// pdb: hkpConstraintInstance::hkpConstraintInstance | hkpConstraintInstance.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: priority
O97a020* O97a020::FUN_0097a020(unsigned char v) { w6 = 1; vt = &f3m_0097a020::DAT_00e7ce98; a8 = 0; a10 = 0; b1c = v; b1d = 0; a20 = 0; a24 = 0; a28 = 0; return this; }
}   // namespace f3m_0097a020

// @f3 0x0097dcc0 (community match, verified in this file)
namespace f3m_0097dcc0 {
namespace f3m_0097dcc0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0097dcc0 { char pad[4]; unsigned short w; void FUN_0097db70(); O0097dcc0* FUN_0097dcc0(unsigned int flags); };
// pdb: hkpListShape::`scalar deleting destructor' | hkpListShape.obj | fnv360_0822_retail, vtable_prefix, high
O0097dcc0* O0097dcc0::FUN_0097dcc0(unsigned int flags) { FUN_0097db70(); if (flags & 1) { f3m_0097dcc0::T* t = (f3m_0097dcc0::T*)f3m_0097dcc0::DAT_00d9b080(f3m_0097dcc0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_0097dcc0

// @f3 0x00963b70 (community match, verified in this file)
namespace f3m_00963b70 {
namespace f3m_00963b70 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00963b70 { char pad[4]; unsigned short w; void FUN_00962a40(); O00963b70* FUN_00963b70(unsigned int flags); };
// pdb: hkaSkeletonMapper::`scalar deleting destructor' | hkaSkeletonMapper.obj | fnv360_0822_retail, vtable, high
O00963b70* O00963b70::FUN_00963b70(unsigned int flags) { FUN_00962a40(); if (flags & 1) { f3m_00963b70::T* t = (f3m_00963b70::T*)f3m_00963b70::DAT_00d9b080(f3m_00963b70::DAT_010f3170); t->FUN_008f6d90(this, w, 0x3b); } return this; }
}   // namespace f3m_00963b70

// @f3 0x00979270 (community match, verified in this file)
namespace f3m_00979270 {
namespace f3m_00979270 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00979270 { char pad[4]; unsigned short w; void FUN_00979010(); O00979270* FUN_00979270(unsigned int flags); };
// pdb: hkpAabbPhantom::`scalar deleting destructor' | hkpAabbPhantom.obj | fnv360_0822_retail, vtable_prefix, high
O00979270* O00979270::FUN_00979270(unsigned int flags) { FUN_00979010(); if (flags & 1) { f3m_00979270::T* t = (f3m_00979270::T*)f3m_00979270::DAT_00d9b080(f3m_00979270::DAT_010f3170); t->FUN_008f6d90(this, w, 0x31); } return this; }
}   // namespace f3m_00979270

// @f3 0x00979f30 (community match, verified in this file)
namespace f3m_00979f30 {
namespace f3m_00979f30 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00979f30 { char pad[4]; unsigned short w; void FUN_00979e90(); O00979f30* FUN_00979f30(unsigned int flags); };
// pdb: hkpSpringAction::`scalar deleting destructor' | hkpSpringAction.obj | fnv360_0822_retail, vtable, high
O00979f30* O00979f30::FUN_00979f30(unsigned int flags) { FUN_00979e90(); if (flags & 1) { f3m_00979f30::T* t = (f3m_00979f30::T*)f3m_00979f30::DAT_00d9b080(f3m_00979f30::DAT_010f3170); t->FUN_008f6d90(this, w, 0x29); } return this; }
}   // namespace f3m_00979f30

// @f3 0x0097a260 (community match, verified in this file)
namespace f3m_0097a260 {
namespace f3m_0097a260 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0097a260 { char pad[4]; unsigned short w; void FUN_0097a090(); O0097a260* FUN_0097a260(unsigned int flags); };
// pdb: hkpConstraintInstance::`scalar deleting destructor' | hkpConstraintInstance.obj | fnv360_0822_retail, vtable, high
O0097a260* O0097a260::FUN_0097a260(unsigned int flags) { FUN_0097a090(); if (flags & 1) { f3m_0097a260::T* t = (f3m_0097a260::T*)f3m_0097a260::DAT_00d9b080(f3m_0097a260::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2c); } return this; }
}   // namespace f3m_0097a260

// @f3 0x0097db40 (community match, verified in this file)
namespace f3m_0097db40 {
struct B1_97db40 { virtual void v0(); unsigned short w4; unsigned short w6; int a8; int ac; B1_97db40() { w6 = 1; } };
struct B2_97db40 { virtual void u0(); };
struct FUN_0097db40 : B1_97db40, B2_97db40 { FUN_0097db40(int unused); virtual void v0(); virtual void u0(); };
// pdb: hkpListShape::hkpListShape | hkpListShape.obj | tesv_win, objrun, medium
FUN_0097db40::FUN_0097db40(int unused) { ac = 10; }
}   // namespace f3m_0097db40

// @f3 0x0097a5c0 (community match, verified in this file)
extern int DAT_011692cc;
namespace f3m_0097a5c0 {
void* __cdecl FUN_00847b50(int id);
struct Arr97a5c0 {
    int vtbl;
    void** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_00555790(unsigned int newCap);
    void FUN_005b3880(unsigned int idx, void** item);
};
// pdb: bhkVelocityConstraintMotor::GetViewerStrings | bhkVelocityConstraintMotor.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void __stdcall FUN_0097a5c0(Arr97a5c0* arr)
{
    void* item = FUN_00847b50(DAT_011692cc);
    unsigned int n = arr->size;
    if (n >= arr->capacity)
        arr->FUN_00555790(arr->growBy + n);
    arr->FUN_005b3880(n, &item);
}
}   // namespace f3m_0097a5c0

// @f3 0x0096bc60 (community match, verified in this file)
namespace f3m_0096bc60 {
namespace f3m_0096bc60 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0096bc60 { void* vt; unsigned short w; O0096bc60* FUN_0096bc60(unsigned int flags); };
O0096bc60* O0096bc60::FUN_0096bc60(unsigned int flags) { vt = &f3m_0096bc60::DAT_00dcc494; if (flags & 1) { f3m_0096bc60::T* t = (f3m_0096bc60::T*)f3m_0096bc60::DAT_00d9b080(f3m_0096bc60::DAT_010f3170); t->FUN_008f6d90(this, w, 0x34); } return this; }
}   // namespace f3m_0096bc60

// @f3 0x0096a370 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0096a370 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace array_release_1622 {
struct Heap { void FUN_008f6d90(void*,int,int); };
struct Array {
    unsigned int* data;
    int count;
    int capacityAndFlags;
    void FUN_0096a370();
};
void Array::FUN_0096a370() {
    if((capacityAndFlags&0x80000000u)==0) {
        int capacity=capacityAndFlags&0x3fffffff;
        Heap* heap=static_cast<Heap*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(data,capacity*sizeof(unsigned int),0x17);
    }
}
}
}   // namespace f3m_0096a370

// @f3 0x0097ee30 (community match, verified in this file)
namespace f3m_0097ee30 {
void* __cdecl FUN_0097e8d0(void* p);
int __cdecl FUN_0097e8e0(void* a);
void __cdecl FUN_0097e840(int z, void* a, int r2, void* b, void* r1);
// pdb: hkStatisticsCollectorUtil::defaultCalcStatistics | hkStatisticsCollectorUtil.obj | tesv_win, caller_sim, low
void __cdecl FUN_0097ee30(void* a, void* b, void* c) { void* r1 = FUN_0097e8d0(c); int r2 = FUN_0097e8e0(a); if (r2) FUN_0097e840(0, a, r2, b, r1); }
}   // namespace f3m_0097ee30

// @f3 0x0097dd70 (community match, verified in this file)
namespace f3m_0097dd70 {
struct Ref97dd70 { int vtbl; short active; short refs; };
class Base97dd70 {
public:
    virtual ~Base97dd70();
    unsigned short unk04;
    unsigned short refs;
    int unk08;
    int unk0c;
    Base97dd70() { refs = 1; unk08 = 0; unk0c = 0x1c; }
};
class Holder97dd70 {
public:
    virtual void h0();
    Ref97dd70* p;
    Holder97dd70(Ref97dd70* r) { p = r; if (r->active) ++r->refs; }
};
class FUN_0097dd70 : public Base97dd70 {
public:
    virtual ~FUN_0097dd70();
    Holder97dd70 holder;
    FUN_0097dd70(Ref97dd70* r, int arg);
    void FUN_0097dd40(int arg) throw();
};
// pdb: hkpTransformShape::hkpTransformShape | hkpTransformShape.obj | fnv360_0822_retail, call_gap, low
// pdb params: childShape, transform
FUN_0097dd70::FUN_0097dd70(Ref97dd70* r, int arg) : holder(r)
{
    FUN_0097dd40(arg);
}
}   // namespace f3m_0097dd70

// @f3 0x0096ad10 (community match, verified in this file)
extern const char* DAT_011692b4;
namespace f3m_0096ad10 {
namespace register_name_1638 {
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
    void FUN_0096ad10(NameArray*);
};
// pdb: bhkShapeCollection::GetViewerStrings | bhkShapeCollection.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Object::FUN_0096ad10(NameArray* names) {
    FUN_008f7a20(names);
    void* value=FUN_00847b50(DAT_011692b4);
    names->Append(value);
}
}

}   // namespace f3m_0096ad10

// @f3 0x0097a400 (community match, verified in this file)
extern const char* DAT_011692c4;
namespace f3m_0097a400 {
namespace viewer_0097a400 {
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
    void FUN_0097a400(NameArray*);
};
// pdb: bhkPositionConstraintMotor::GetViewerStrings | bhkPositionConstraintMotor.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Object::FUN_0097a400(NameArray* names) {
    void* handle=FUN_00847b50(DAT_011692c4);
    names->Append(handle);
}
}
}   // namespace f3m_0097a400

// @f3 0x0097a720 (community match, verified in this file)
extern const char* DAT_011692d4;
namespace f3m_0097a720 {
namespace viewer_0097a720 {
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
    void FUN_0097a720(NameArray*);
};
// pdb: bhkSpringDamperConstraintMotor::GetViewerStrings | bhkSpringDamperConstraintMotor.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Object::FUN_0097a720(NameArray* names) {
    void* handle=FUN_00847b50(DAT_011692d4);
    names->Append(handle);
}
}
}   // namespace f3m_0097a720

// @f3 0x0097dcf0 (community match, verified in this file)
namespace f3m_0097dcf0 {
namespace f3m_0097dcf0 { extern char DAT_00e7d224; extern char DAT_00e7d218; }
struct O0097dcf0 { virtual void v0(); virtual void Slot1(void* a, int b, void* c); virtual void v2(); virtual void Slot3(void* a, int b, int c); virtual void v4(); virtual void v5(); virtual void Slot6(); };
struct H0097dcf0 { char pad[0x14]; int field; void hkpTransformShape_calcContentStatistics(O0097dcf0* o); };
// pdb: hkpTransformShape::calcContentStatistics | hkpTransformShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void H0097dcf0::hkpTransformShape_calcContentStatistics(O0097dcf0* o) { o->Slot1(&f3m_0097dcf0::DAT_00e7d224, 1, this); o->Slot3(&f3m_0097dcf0::DAT_00e7d218, 1, field); o->Slot6(); }
}   // namespace f3m_0097dcf0

// @f3 0x0097dc10 (community match, verified in this file)
namespace f3m_0097dc10 {
namespace f3m_0097dc10 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); extern char DAT_00e35eec; extern char DAT_00dcc494; struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O97dc10 { void* vt0; unsigned short w; char pad[10]; void* vt10; O97dc10* FUN_0097dc10(unsigned int flags); };
// pdb: hkpShapeCollection::`scalar deleting destructor' | hkpShapeCollection.obj | fnv360_0822_retail, vtable_prefix, high
O97dc10* O97dc10::FUN_0097dc10(unsigned int flags) { void** pb = this ? &vt10 : 0; *pb = &f3m_0097dc10::DAT_00e35eec; vt0 = &f3m_0097dc10::DAT_00dcc494; if (flags & 1) { f3m_0097dc10::T* t = (f3m_0097dc10::T*)f3m_0097dc10::DAT_00d9b080(f3m_0097dc10::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_0097dc10

// @f3 0x00978770 (community match, verified in this file)
namespace f3m_00978770 {
struct V978770 { float a, b, c, d, e, f, g, h; };
struct O978770 { char pad[0xa0]; V978770 v; void FUN_00989c00(V978770* p); void hkpAabbPhantom_setAabb(const V978770* p); };
// pdb: hkpAabbPhantom::setAabb | hkpAabbPhantom.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void O978770::hkpAabbPhantom_setAabb(const V978770* p) { V978770* d = &v; d->a = p->a; d->b = p->b; d->c = p->c; d->d = p->d; d->e = p->e; d->f = p->f; d->g = p->g; d->h = p->h; FUN_00989c00(d); }
}   // namespace f3m_00978770

// @f3 0x0097a090 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0097a090 {
namespace n97a090 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
__declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long);
struct Item { void FUN_009316f0() throw(); };
struct Node { unsigned short type; char pad[0xe]; unsigned short size; Node* next; };
class RefObj {
public:
    unsigned short memSizeAndFlags;
    short refCount;
    virtual ~RefObj() throw() {}
    void RemoveReference() {
        if (memSizeAndFlags != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
class Base {
public:
    virtual ~Base() throw() {}
    unsigned short memSizeAndFlags;
    short refCount;
};
}
class FUN_0097a090 : public n97a090::Base {
public:
    int pad8;
    n97a090::RefObj* ref;
    n97a090::Node* nodes;
    n97a090::Item* a;
    n97a090::Item* b;
    virtual ~FUN_0097a090() throw();
};
// pdb: hkpConstraintInstance::~hkpConstraintInstance | hkpConstraintInstance.obj | fnv360_0822_retail, call_seq, high
FUN_0097a090::~FUN_0097a090() throw()
{
    if (a) a->FUN_009316f0();
    if (b) b->FUN_009316f0();
    n97a090::Node* n = nodes;
    if (n) {
        while (n->type >= 0x17) {
            n97a090::Node* cur = n;
            n = n->next;
            n97a090::Heap* h = n97a090::FUN_00d9b080(DAT_010f3170);
            h->FUN_008f6d90(cur, cur->size, 0x2c);
        }
    }
    if (ref) ref->RemoveReference();
}
}   // namespace f3m_0097a090

// @f3 0x009715a0 (community match, verified in this file)
namespace f3m_009715a0 {
namespace n9715a0 {
struct Src {
    int x0;
    float scale;
    char pad[8];
    float t[4];
    float m[12];
};
struct Sub {
    float m[12];
    float t[4];
    float dt;
    void FUN_0096cd10(float x);
};
struct Dst { char pad[0x50]; Sub sub; };
}
// pdb: hkpInertiaTensorComputer::setAndScaleToMass | hkpInertiaTensorComputer.obj | tesv_win, call_seq, medium
void __cdecl FUN_009715a0(const n9715a0::Src* a, float dt, n9715a0::Dst* d)
{
    float q = dt / a->scale;
    n9715a0::Sub* s = &d->sub;
    s->dt = dt;
    s->t[0] = a->t[0];
    s->t[1] = a->t[1];
    s->t[2] = a->t[2];
    s->t[3] = a->t[3];
    s->m[0] = a->m[0]; s->m[1] = a->m[1]; s->m[2] = a->m[2]; s->m[3] = a->m[3];
    s->m[4] = a->m[4]; s->m[5] = a->m[5]; s->m[6] = a->m[6]; s->m[7] = a->m[7];
    s->m[8] = a->m[8]; s->m[9] = a->m[9]; s->m[10] = a->m[10]; s->m[11] = a->m[11];
    s->FUN_0096cd10(q);
}
}   // namespace f3m_009715a0

// @f3 0x0097a9e0 (community match, verified in this file)
namespace f3m_0097a9e0 {
namespace n97a9e0 {
struct Stream;
typedef int (__cdecl* ReadFn)(Stream* s, void* buf, int size, int* count, int flag);
struct Stream { int x0; int pos; ReadFn read; int Read(void* buf, int size) { int n = size; return read(this, buf, size, &n, 1); } };
struct Reader { int x0; unsigned int version; char pad[0x24c - 8]; Stream* stream; };
class RefObj {
public:
    virtual ~RefObj();
    unsigned short memSizeAndFlags;
    short refCount;
    void AddReference() { if (memSizeAndFlags != 0) ++refCount; }
};
class Loader {
public:
    virtual ~Loader();
    RefObj* result;
    virtual void v1();
    virtual void Load(Reader* r);
    virtual void v3();
    virtual void LoadOld(Reader* r, int x);
};
Loader* __cdecl FUN_0097a820(int id);
}
// pdb: bhkConstraintManager::LoadBinary | bhkConstraintManager.obj | fnv360_0721_beta, objrun, medium
// pdb params: arStream
n97a9e0::RefObj* __cdecl FUN_0097a9e0(n97a9e0::Reader* r)
{
    n97a9e0::Stream* s = r->stream;
    n97a9e0::RefObj* res = 0;
    int id;
    s->pos += s->Read(&id, 4);
    n97a9e0::Loader* l = n97a9e0::FUN_0097a820(id);
    if (l) {
        if (r->version < 0x11) l->LoadOld(r, 0);
        else l->Load(r);
        res = l->result;
        res->AddReference();
        delete l;
    }
    return res;
}
}   // namespace f3m_0097a9e0

// @f3 0x00960b80 (community match, verified in this file)
namespace f3m_00960b80 {
namespace n960b80 {
struct Vec4 { float x, y, z, w; };
struct Array { void* data; int size; int capAndFlags; Array() : data(0), size(0), capAndFlags(0x80000000) {} };
}
struct FUN_00960b80 {
    n960b80::Array arr;
    int pad0c;
    n960b80::Vec4 v;
    unsigned short a, b, c;
    FUN_00960b80(unsigned short a, unsigned short b, unsigned short c, const n960b80::Vec4& v);
};
// pdb: hkaPoseMatchingUtility::hkaPoseMatchingUtility | hkaPoseMatchingUtility.obj | fnv360_0822_retail, call_dedup, high
// pdb params: rootBoneIdx, otherBoneIdx, anotherBoneIdx, rotAxis
FUN_00960b80::FUN_00960b80(unsigned short a_, unsigned short b_, unsigned short c_, const n960b80::Vec4& v_)
    : a(a_), b(b_), c(c_)
{
    v.x = v_.x; v.y = v_.y; v.z = v_.z; v.w = v_.w;
}
}   // namespace f3m_00960b80

// @f3 0x00979df0 (community match, verified in this file)
namespace f3m_00979df0 {
namespace Task0925 {
struct Action;
struct Entity {void FUN_009316f0();void FUN_009316e0();};
struct World {void hkpWorld_detachActionFromEntity(Action*,Entity*);void FUN_009038e0(Action*,Entity*);};
struct Action {
 int unk00,unk04;World* world;int unk0c,unk10,unk14,unk18;Entity* entity;
 void FUN_00979df0(Entity*);
};
// pdb: hkpBinaryAction::setEntityB | hkpBinaryAction.obj | fnv360_0822_retail, call_seq, medium, conflict (bridge: hkpBinaryAction::setEntityA)
// pdb params: entityB
void Action::FUN_00979df0(Entity* next) {
 if(entity){
  if(World* owner=world) owner->hkpWorld_detachActionFromEntity(this,entity);
  entity->FUN_009316f0();entity=0;
 }
 entity=next;
 entity->FUN_009316e0();
 if(World* owner=world) owner->FUN_009038e0(this,entity);
}
}
}   // namespace f3m_00979df0

// @f3 0x00971350 (community match, verified in this file)
namespace f3m_00971350 {
struct Metrics{
float m00;
float m04;
float m08;
float m0c;
float m10;
float m14;
float m18;
float m1c;
float m20;
float m24;
float m28;
float m2c;
float m30;
float m34;
float m38;
float m3c;
float m40;
float m44;
float m48;
float m4c;
Metrics* FUN_00971350();};
Metrics* Metrics::FUN_00971350(){
m00=0.0f;
m04=0.0f;
m1c=0.0f;
m18=0.0f;
m14=0.0f;
m10=0.0f;
m20=0.0f;
m24=0.0f;
m28=0.0f;
m2c=0.0f;
m30=0.0f;
m34=0.0f;
m38=0.0f;
m3c=0.0f;
m40=0.0f;
m44=0.0f;
m48=0.0f;
m4c=0.0f;
return this;}
}   // namespace f3m_00971350

// @f3 0x0097e7a0 (community match, verified in this file)
struct Alloc97e7a0 {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c();
    virtual void vf30(); virtual void vf34(); virtual void vf38();
    virtual void* vf3c(unsigned int size);
};

struct Sink97e7a0 {
    virtual void vf00(); virtual void vf04();
    virtual void vf08(int key, int value, const char* text, unsigned int length, void* buffer);
};

extern Alloc97e7a0* DAT_010f3400;
unsigned int __cdecl FUN_009233f0(const char* text);

// pdb: hkStatisticsCollectorUtil::_addArrayData | hkStatisticsCollectorUtil.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkStatisticsCollectorUtil::_addCstring)
// pdb params: fieldName, data, size, capacity, objSize, collector
void __cdecl FUN_0097e7a0(int* key, const char* text, int value, Sink97e7a0* sink) {
    if (text) {
        unsigned int length = FUN_009233f0(text) + 1;
        void* buffer = DAT_010f3400->vf3c(length);
        sink->vf08(*key, value, text, length, buffer);
    }
}

// @f3 0x0097a130 (community match, verified in this file)
namespace f3m_0097a130 {
namespace task1084 {
struct Entity {
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
 int value;
 unsigned unkbc;
 unsigned unkc0;
 unsigned unkc4;
 unsigned unkc8;
 unsigned unkcc;
 unsigned unkd0;
 unsigned unkd4;
 unsigned char flag;
};
struct Pair {
 unsigned unk00,unk04,unk08,unk0c,unk10;
 Entity* first;
 Entity* second;
 int FUN_0097a130() const;
};
// pdb: hkpConstraintInstance::getSimulationIsland | hkpConstraintInstance.obj | tesv_win, objrun_open, low
int Pair::FUN_0097a130() const {
 const Entity* e=first;
 if(e->flag!=7) return e->value;
 return second->value;
}
}
}   // namespace f3m_0097a130

// @f3 0x00963ab0 (community match, verified in this file)
namespace f3m_00963ab0 {
namespace n963ab0 {
struct Vec {
    float x, y, z, w;
    Vec& operator=(const Vec& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
}
struct Rec963ab0 {
    unsigned short s0, s1, s2, s3;
    int pad08, pad0c;
    n963ab0::Vec v[6];
    Rec963ab0& FUN_00963ab0(const Rec963ab0& o);
};
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkaSkeletonMapperData::ChainMapping::ChainMapping)
// pdb params: str
Rec963ab0& Rec963ab0::FUN_00963ab0(const Rec963ab0& o)
{
    s0 = o.s0;
    s1 = o.s1;
    s2 = o.s2;
    s3 = o.s3;
    for (int i = 0; i < 6; ++i)
        v[i] = o.v[i];
    return *this;
}
}   // namespace f3m_00963ab0

// @f3 0x00962480 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long index);
namespace n962480 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };

void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();
struct RefObj {
    unsigned short memSize;
    short refCount;
    virtual ~RefObj() throw() {}
    void removeReference() throw() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
struct Entity : RefObj {
    virtual void v4() throw(); virtual void v8() throw(); virtual void vc() throw();
    virtual void v10() throw();
};
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    void setSize(int n) throw() {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        size = n;
    }
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)::FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
}
namespace n962480 { struct Part { void FUN_009316f0() throw(); }; }
struct FUN_00962480 : n962480::RefObj {
    n962480::Array<n962480::Part*> parts;
    n962480::Array<n962480::RefObj*> refs;
    n962480::Array<void*> extra;
    virtual ~FUN_00962480() throw();
};
// pdb: hkaRagdollInstance::~hkaRagdollInstance | hkaRagdollInstance.obj | fnv360_0822_retail, call_seq, high
FUN_00962480::~FUN_00962480() throw()
{
    for (int i = 0; i < parts.size; i++)
        parts.data[i]->FUN_009316f0();
    for (int i = 0; i < refs.size; i++)
        refs.data[i]->removeReference();
}

// @f3 0x0096c880 (community match, verified in this file)
namespace f3m_0096c880 {
namespace n96c880 {
struct Vec {
    float x, y, z, w;
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
}
struct Mat96c880 {
    n96c880::Vec col0, col1, col2;
    void hkMatrix3_setCrossSkewSymmetric(const n96c880::Vec& v);
};
// pdb: hkMatrix3::setCrossSkewSymmetric | hkMatrix3.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(call_seq), high
void Mat96c880::hkMatrix3_setCrossSkewSymmetric(const n96c880::Vec& v)
{
    col0.set(0.0f, v.z, -v.y, 0.0f);
    col1.set(-v.z, 0.0f, v.x, 0.0f);
    col2.set(v.y, -v.x, 0.0f, 0.0f);
}
}   // namespace f3m_0096c880

// @f3 0x00978bf0 (community match, verified in this file)
struct Array978bf0;
void __cdecl FUN_00901f10(Array978bf0* array, int elementSize);
struct Array978bf0 {
    void** data;
    int size;
    int capacityAndFlags;
    void pushBack(void* item) {
        if (size == (capacityAndFlags & 0x3fffffff)) ::FUN_00901f10(this, 4);
        data[size] = item;
        size++;
    }
};

struct Owner978bf0 {
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
    Array978bf0 unkc0;
    int FUN_0091a520(void* item);
    void FUN_00978bf0(void* item);
};

// pdb: hkpAabbPhantom::addOverlappingCollidable | hkpAabbPhantom.obj | tesv_win, objopen_prop, low
void Owner978bf0::FUN_00978bf0(void* item) {
    if (!FUN_0091a520(item)) {
        unkc0.pushBack(item);
    }
}

// @f3 0x00979e40 (community match, verified in this file)
namespace f3m_00979e40 {
struct RefObj979e40 {
    virtual void vf00();
    unsigned short memSizeAndFlags;
    short referenceCount;
    RefObj979e40() : referenceCount(1) {}
};

struct Mid979e40 : RefObj979e40 {
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Mid979e40(int c) : unk08(0), unk0c(0), unk10(c), unk14(0) {}
};

struct FUN_00979e40 : Mid979e40 {
    int unk18;
    int unk1c;
    FUN_00979e40(int a, int b, int c);
    virtual void vf04();
    void FUN_00979d60();
};

// pdb: hkpBinaryAction::hkpBinaryAction | hkpBinaryAction.obj | fnv360_0822_retail, call_seq, high
// pdb params: entityA, entityB, userData
FUN_00979e40::FUN_00979e40(int a, int b, int c) : Mid979e40(c) {
    unk18 = a;
    unk1c = b;
    if (b != 0 || a != 0) {
        FUN_00979d60();
    }
}
}   // namespace f3m_00979e40

// @f3 0x00978720 (community match, verified in this file)
namespace f3m_00978720 {
struct Vec978720 { float x, y, z, w; };

struct Owner978720 {
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
    Vec978720 unka0;
    Vec978720 unkb0;
    void FUN_00978720(Vec978720* out);
};

// pdb: hkpAabbPhantom::calcAabb | hkpAabbPhantom.obj | tesv_win, objopen_prop, low
void Owner978720::FUN_00978720(Vec978720* out) {
    out[0].x = unka0.x; out[0].y = unka0.y; out[0].z = unka0.z; out[0].w = unka0.w;
    out[1].x = unkb0.x; out[1].y = unkb0.y; out[1].z = unkb0.z; out[1].w = unkb0.w;
}
}   // namespace f3m_00978720

// @f3 0x0096a860 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0096a860 {
struct hkThreadMemory
{
    void FUN_008f6d90(void* memory, unsigned int size, int memoryClass);
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct hkReferencedObject
{
    void FUN_009316f0();
};

struct ContactRecord
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C;
};

template <class T>
struct hkCollectorArray
{
    T* data;
    int size;
    int capacityAndFlags;

    __forceinline void FreeBuffer()
    {
        if ((capacityAndFlags & 0x80000000u) == 0)
        {
            unsigned int capacity = capacityAndFlags & 0x3fffffff;
            hkThreadMemory* memory = static_cast<hkThreadMemory*>(TlsGetValue(DAT_010f3170));
            memory->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }

    __forceinline void ClearAndRelease()
    {
        FreeBuffer();
        data = 0;
        size = 0;
        capacityAndFlags = (capacityAndFlags & 0xc0000000) | 0x80000000;
    }

    __forceinline ~hkCollectorArray()
    {
        FreeBuffer();
    }
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    float earlyOutDistance;
    unsigned int unk08, unk0C;
};

struct hkpAllCdPointCollector : hkpCdPointCollector
{
    virtual ~hkpAllCdPointCollector();
    ContactRecord* data;
    int size;
    int capacityAndFlags;
    unsigned int unk1C;
    ContactRecord localContacts[8];
};

struct bhkCharacterPointCollector : hkpAllCdPointCollector
{
    virtual ~bhkCharacterPointCollector();
    unsigned int unk220;
    hkCollectorArray<hkReferencedObject*> references;
    hkCollectorArray<unsigned int> indices;
    hkCollectorArray<ContactRecord> contacts;
};

// pdb: bhkCharacterPointCollector::~bhkCharacterPointCollector | bhkCharacterPointCollector.obj | fnv360_0822_retail, call_gap, medium
bhkCharacterPointCollector::~bhkCharacterPointCollector()
{
    int count = references.size;
    int i = 0;
    if (count > 0)
    {
        do
        {
            references.data[i]->FUN_009316f0();
            ++i;
        } while (i < references.size);
    }
    references.ClearAndRelease();
    contacts.ClearAndRelease();
    indices.ClearAndRelease();
}
}   // namespace f3m_0096a860

// @f3 0x0097e690 (community match, verified in this file)
namespace f3m_0097e690 {
struct FillZ {
    __forceinline void z0(float* a) { a[3]=0.0f; a[2]=0.0f; a[1]=0.0f; a[0]=0.0f; a[4]=0.0f; a[5]=0.0f; a[6]=0.0f; }
    __forceinline void z1(float* a) { a[11]=0.0f; a[10]=0.0f; a[9]=0.0f; a[8]=0.0f; a[15]=0.0f; a[14]=0.0f; a[13]=0.0f; a[12]=0.0f; }
    __forceinline void z2(float* a) { a[16]=0.0f; a[17]=0.0f; a[18]=0.0f; a[19]=0.0f; a[20]=0.0f; a[21]=0.0f; a[22]=0.0f; a[23]=0.0f; a[24]=0.0f; a[25]=0.0f; a[26]=0.0f; a[27]=0.0f; }
    __forceinline void z3(float* a) { a[31]=0.0f; a[30]=0.0f; a[29]=0.0f; a[28]=0.0f; }
};
struct Obj97e690 {
    int unk00; int unk04; unsigned char unk08; unsigned char unk09; unsigned short unk0a; unsigned char pad0c,pad0d,pad0e,pad0f;
    float a[34];
    float f98; float f9c; float fa0; float fa4; float fa8; float fac;
    unsigned char ub0; unsigned char ub1; unsigned char ub2; unsigned char ub3; unsigned char ub4; unsigned char ub5; volatile unsigned char ub6;
    unsigned char u77pad;
    Obj97e690();
};
// pdb: hkpRigidBody::getCinfo | hkpRigidBody.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpRigidBodyCinfo::hkpRigidBodyCinfo)
// pdb params: info
Obj97e690::Obj97e690() {
    FillZ fill;
    fill.z0(a);
    a[7] = 1.0f;
    fill.z1(a);
    fill.z2(a);
    a[16] = 1.0f; a[21] = 1.0f; a[26] = 1.0f;
    fill.z3(a);
    a[32] = 1.0f;
    a[33] = 0.0f;
    ub1 = 2; ub2 = 2; ub0 = 1; ub3 = 0;
    f98 = 0.05f; unk08 = 1; unk0a = -1;
    f9c = 0.5f; unk00 = 0; unk04 = 0;
    fa0 = 0.4f; ub4 = 0; ub5 = 0;
    fa4 = 200.0f; fa8 = 200.0f;
    fac = -1.0f; ub6 = 0;
}
}   // namespace f3m_0097e690

// @f3 0x00973640 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00973640 {

struct NativeMassHeap {
    void FUN_008f6d90(void* data,int bytes,int memoryClass) throw();
    static NativeMassHeap* Get() throw() { return static_cast<NativeMassHeap*>(TlsGetValue(DAT_010f3170)); }
};
void FUN_00901e90(void* array,int capacity,int elementSize) throw();
struct __declspec(align(16)) NativeHullVector { float x,y,z,w; };
struct NativeHullTriangle { int a,b,c; };
template<class T> struct NativeHullArray {
    T* data;
    int count;
    int capacity;
    NativeHullArray() throw() : data(0),count(0),capacity(0x80000000) {}
    __forceinline ~NativeHullArray() throw() {
        if (capacity & 0x80000000u) return;
        FreeStorage(GetCapacity());
    }
    int GetCapacity() const throw() { return capacity & 0x3fffffff; }
    void FreeStorage(int elements) throw() {
        NativeMassHeap::Get()->FUN_008f6d90(data,elements*sizeof(T),23);
    }
    void Reserve(int requested) throw() {
        int growth = 2 * (capacity & 0x3fffffff);
        int expanded = requested < growth ? growth : requested;
        FUN_00901e90(this,expanded,sizeof(T));
    }
    void SetSize(int required) throw() {
        if ((capacity & 0x3fffffff) < required) Reserve(required);
        count = required;
    }
};
struct NativeHullInput {
    const NativeHullVector* data; int count; int stride;
    NativeHullInput(const NativeHullVector* vertices,int n,int bytes) throw() { data=vertices; stride=bytes; count=n; }
};
struct NativeHullGeometry { NativeHullArray<NativeHullVector> vertices; NativeHullArray<NativeHullTriangle> triangles; __forceinline ~NativeHullGeometry() throw() {} };
struct NativeMassProperties { float volume,mass; };
void FUN_009ec660(const NativeHullInput&,NativeHullGeometry&,NativeHullArray<NativeHullVector>&,int) throw();
void FUN_00973140(const NativeHullGeometry&,float,NativeMassProperties*) throw();

int __cdecl FUN_00973640(const void* input,int stride,int count,float mass,NativeMassProperties* output) throw()
{
    if (mass <= 0.0f) return 1;
    NativeHullArray<NativeHullVector> points;
    points.SetSize(count);
    const float* source = static_cast<const float*>(input);
    for (int i=0;i<count;++i) {
        points.data[i].x = source[0];
        points.data[i].y = source[1];
        points.data[i].z = source[2];
        source = reinterpret_cast<const float*>(reinterpret_cast<const char*>(source) + stride);
    }
    NativeHullInput description(points.data,count,16);
    NativeHullGeometry geometry;
    NativeHullArray<NativeHullVector> planes;
    FUN_009ec660(description,geometry,planes,1);
    FUN_00973140(geometry,mass,output);
    output->mass = mass;
    return 0;
}
}   // namespace f3m_00973640

// @f3 0x00963a00 (community match, verified in this file)
namespace f3m_00963a00 {
namespace skeleton_mapper_constructor {
struct Skeleton;
struct SimpleMapping;
struct ChainMapping;
template<class T> struct Array {
    T* data; int count; unsigned int capacityAndFlags;
    __forceinline Array() throw() : data(0),count(0),capacityAndFlags(0x80000000u) {}
};
struct MappingData {
    Skeleton* skeletonA; Skeleton* skeletonB;
    Array<SimpleMapping> simpleMappings;
    Array<ChainMapping> chainMappings;
    Array<short> unmappedBones;
    bool keepUnmappedLocal;
    __forceinline MappingData() throw() { skeletonA=0;skeletonB=0;keepUnmappedLocal=true; }
    MappingData& FUN_00963ba0(const MappingData&) throw();
};
struct hkReferencedObject {
    virtual ~hkReferencedObject() throw();
    unsigned short memorySizeAndFlags,referenceCount;
    __forceinline hkReferencedObject() throw() : referenceCount(1) {}
};
struct hkaSkeletonMapper : hkReferencedObject {
    MappingData mapping;
    hkaSkeletonMapper(const MappingData&) throw();
};
hkaSkeletonMapper::hkaSkeletonMapper(const MappingData& source) throw() { mapping.FUN_00963ba0(source); }
}
}   // namespace f3m_00963a00

// @f3 0x00979010 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
namespace f3m_00979010 {


struct ThreadMemory979010 {
    void FUN_008f6d90(void* p, int size, int memClass) throw();
};

static inline ThreadMemory979010& GetThreadMemory979010() {
    return *(ThreadMemory979010*)TlsGetValue(DAT_010f3170);
}

template <class T>
static inline void DeallocateChunk979010(T* const& p, int n, int memClass) {
    ThreadMemory979010& memory = GetThreadMemory979010();
    memory.FUN_008f6d90(p, n * sizeof(T), memClass);
}

struct Array979010 {
    void** data;
    int size;
    int capacityAndFlags;
    ~Array979010() {
        if ((capacityAndFlags & 0x80000000) == 0) {
            DeallocateChunk979010(data, capacityAndFlags & 0x3fffffff, 0x17);
        }
    }
};

struct Base979010 {
    virtual ~Base979010();
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
};

struct FUN_00979010 : Base979010 {
    Array979010 unkc0;
    virtual ~FUN_00979010();
};

// pdb: hkpAabbPhantom::~hkpAabbPhantom | hkpAabbPhantom.obj | fnv360_0822_retail, call_seq, high
FUN_00979010::~FUN_00979010() {
}
}   // namespace f3m_00979010

// @f3 0x0097e370 (community match, verified in this file)
extern const float DAT_0106089c;
extern const float DAT_010608a0;
extern const float DAT_010608a4;
extern const float DAT_010608a8;
namespace f3m_0097e370 {
struct V97 { float x, y, z, w; };

class Base97 {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    unsigned short m_ref04;
    unsigned short m_type06;
    int m_unk08;
    int m_unk0c;
    V97 m_a10;
    V97 m_b20;
    V97 m_c30;
    V97 m_d40;
    float m_e50;
    V97 m_f54;
    Base97(unsigned short t) { m_type06 = t; }
};

class C97 : public Base97 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    C97();
};

C97::C97() : Base97(1)
{
    m_e50 = -1.0f;
    m_f54.x = DAT_0106089c;
    m_f54.y = DAT_010608a0;
    m_f54.z = DAT_010608a4;
    m_f54.w = DAT_010608a8;
    m_a10.w = m_a10.z = m_a10.y = m_a10.x = 3.40282e38f;
    m_c30.w = m_c30.z = m_c30.y = m_c30.x = 3.40282e38f;
    m_b20.z = m_b20.y = m_b20.x = 0.0f;
    m_d40.w = m_b20.w = 1.0f;
    m_d40.z = m_d40.y = m_d40.x = 0.0f;
}
}   // namespace f3m_0097e370

// @f3 0x009767c0 (community match, verified in this file)
namespace f3m_009767c0 {
namespace f3m_009767c0 {
class ThreadMem_67c0 {
public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void* AllocateStackSlow(int bytes) throw();
    virtual void PopStack(void* p) throw();

    char pad04[0x1c];
    char* stackCurrent;
    int unk24;
    void* stackBase;
    char* stackEnd;

    void FUN_008f6d90(void* p, int bytes, int tag) throw();

    void* AllocateStack(int bytes) throw()
    {
        int aligned = (bytes + 0x10) & ~0xf;
        char* p = stackCurrent;
        char* next = p + aligned;
        if (next <= stackEnd) {
            stackCurrent = next;
            return p;
        }
        return AllocateStackSlow(aligned);
    }
    void DeallocateStack(void* p) throw()
    {
        stackCurrent = (char*)p;
        if (p == stackBase)
            PopStack(p);
    }
};
__declspec(dllimport) ThreadMem_67c0* __stdcall FUN_00d9b080(int) throw();

template <class T> struct Array_67c0 {
    T* data;
    int size;
    int capacityAndFlags;
    Array_67c0() throw() : data(0), size(0), capacityAndFlags(0x80000000) {}
    __forceinline ~Array_67c0() throw()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int cap = capacityAndFlags & 0x3fffffff;
            ThreadMem_67c0* a = FUN_00d9b080(DAT_010f3170);
            a->FUN_008f6d90(data, cap * 4, 0x17);
        }
    }
    void PushBackUnchecked(const T& v) throw() { data[size++] = v; }
};
template <class T> struct LocalArray_67c0 : Array_67c0<T> {
    void* localMemory;
    __forceinline LocalArray_67c0(int n) throw()
    {
        this->data = (T*)FUN_00d9b080(DAT_010f3170)->AllocateStack(n * sizeof(T));
        this->capacityAndFlags = n | 0x80000000;
        localMemory = this->data;
    }
    __forceinline ~LocalArray_67c0() throw()
    {
        FUN_00d9b080(DAT_010f3170)->DeallocateStack(localMemory);
    }
};
float __cdecl FUN_009764b0(Array_67c0<int>* items, int arg, float value) throw();
}
using namespace f3m_009767c0;

void __cdecl FUN_009767c0(const int* items, int count, int arg, float value)
{
    LocalArray_67c0<int> arr(count);
    for (int i = 0; i < count; i++)
        arr.PushBackUnchecked(items[i]);
    FUN_009764b0(&arr, arg, value);
}
}   // namespace f3m_009767c0

// @f3 0x0097a980 (community match, verified in this file)
namespace f3m_0097a980 {
namespace f3m_0097a980 {
class Ref_a980 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void addReference()
    {
        if (memSizeAndFlags != 0)
            ++referenceCount;
    }
};
class Shape_a980 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int GetType();
};
class Builder_a980 {
public:
    virtual void DeleteThis(int flag);
    virtual void Build(Ref_a980* parent, void* arg);
    Ref_a980* result;
    void FUN_008fbbb0(Shape_a980* shape);
};
Builder_a980* __cdecl FUN_0097a820(int type);
}
using namespace f3m_0097a980;

// pdb: bhkConstraintManager::Clone | bhkConstraintManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apData, arCloneData
Ref_a980* __cdecl FUN_0097a980(Shape_a980* shape, void* arg)
{
    Ref_a980* result = 0;
    Builder_a980* builder = FUN_0097a820(shape->GetType());
    if (builder) {
        builder->FUN_008fbbb0(shape);
        builder->Build(0, arg);
        result = builder->result;
        result->addReference();
        builder->DeleteThis(1);
    }
    return result;
}
}   // namespace f3m_0097a980

// @f3 0x009649f0 (community match, verified in this file)
namespace f3m_009649f0 {
namespace f3m_009649f0 {
struct Vec4_49f0 {
    float x, y, z, w;
    void setZero4() { x = y = z = w = 0.0f; }
    void set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};
struct QsTransform_49f0 {
    Vec4_49f0 translation;
    Vec4_49f0 rotation;
    Vec4_49f0 scale;
    void setIdentity()
    {
        translation.setZero4();
        rotation.set(0.0f, 0.0f, 0.0f, 1.0f);
        scale.set(1.0f, 1.0f, 1.0f, 1.0f);
    }
};
struct FUN_009649f0 {
    short unk00;
    short unk02;
    short unk04;
    short unk06;
    int pad08[2];
    QsTransform_49f0 a;
    QsTransform_49f0 b;
    FUN_009649f0();
};
}
using namespace f3m_009649f0;

// pdb: hkaSkeletonMapperData::ChainMapping::ChainMapping | hkaSkeletonMapperUtils.obj | fnv360_0822_retail, call_gap_sim, high
FUN_009649f0::FUN_009649f0() : unk00(0), unk02(0), unk04(0), unk06(0)
{
    a.setIdentity();
    b.setIdentity();
}
}   // namespace f3m_009649f0

// @f3 0x0097ea60 (community match, verified in this file)
namespace f3m_0097ea60 {
struct A97 {
    void* f0;
    unsigned char pad[9];
    unsigned char kind;
    int FUN_0093d890();
};
struct B97 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(void* p);
    virtual void v14();
};
extern "C" void FUN_0097ea00(A97* a, int* list, int n, int count, B97* obj, int p5);
extern "C" void FUN_0097e900(int zero, int elem, int n, B97* obj, int p5);
void FUN_0097ea60(A97* a, int* list, int count, B97* obj, int p5)
{
    if (count <= 0) return;
    int kind = a->kind;
    switch (kind) {
    case 0x14:
        obj->v10(a->f0);
        {
            int n = a->FUN_0093d890();
            for (int i = 0; i < count; i++)
                FUN_0097e900(0, list[i], n, obj, p5);
        }
        obj->v14();
        return;
    case 0x19:
        {
            int n2 = a->FUN_0093d890();
            FUN_0097ea00(a, list, n2, count, obj, p5);
        }
        return;
    }

}
}   // namespace f3m_0097ea60

// @f3 0x009639c0 (community match, verified in this file)
namespace f3m_009639c0 {
namespace f9639c0 {
struct A {
    int* FUN_00956280();
    int* FUN_00956270();
    int* FUN_00955ab0();
};
void __cdecl hkaSkeletonMapper_mapPose(void* a, int b, int c, int d, void* e);

void __cdecl FUN_009639c0(void* g1, A* g2, A* g3, void* g4) {
    int a = *g2->FUN_00956280();
    int b = *g3->FUN_00956270();
    int* c = g3->FUN_00955ab0();
    hkaSkeletonMapper_mapPose(g1, a, b, *c, g4);
}
}
}   // namespace f3m_009639c0

// @f3 0x0096cca0 (community match, verified in this file)
namespace f3m_0096cca0 {

class M12 {
public:
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;

    void FUN_0096cca0(const M12* other);
};

// pdb: hkMatrix3::invert | hkMatrix3.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkMatrix3::sub)
// pdb params: epsilon
void M12::FUN_0096cca0(const M12* other)
{
    f00 -= other->f00;
    f04 -= other->f04;
    f08 -= other->f08;
    f0c -= other->f0c;
    f10 -= other->f10;
    f14 -= other->f14;
    f18 -= other->f18;
    f1c -= other->f1c;
    f20 -= other->f20;
    f24 -= other->f24;
    f28 -= other->f28;
    f2c -= other->f2c;
}
}   // namespace f3m_0096cca0

// @f3 0x00963a50 (community match, verified in this file)
namespace f3m_00963a50 {
struct Obj96 {
    unsigned short unk00;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    Obj96* FUN_00963a50(const Obj96* src);
};

// pdb: hkaSkeletonMapperData::ChainMapping::ChainMapping | hkaSkeletonMapper.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: __that
Obj96* Obj96::FUN_00963a50(const Obj96* src)
{
    unk00 = src->unk00;
    unk02 = src->unk02;
    unk10 = src->unk10;
    unk14 = src->unk14;
    unk18 = src->unk18;
    unk1c = src->unk1c;
    unk20 = src->unk20;
    unk24 = src->unk24;
    unk28 = src->unk28;
    unk2c = src->unk2c;
    unk30 = src->unk30;
    unk34 = src->unk34;
    unk38 = src->unk38;
    unk3c = src->unk3c;
    return this;
}
}   // namespace f3m_00963a50

// @f3 0x00971520 (community match, verified in this file)
namespace f3m_00971520 {
namespace Transfer395{struct Input{unsigned int unk00;float amount;unsigned int unk08,unk0c;float vector[4];float matrix[12];};struct Output{
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
float matrix[12];float vector[4];float amount;};void __cdecl FUN_00971520(const Input*input,Output*output){output->amount=input->amount;
output->vector[0]=input->vector[0];
output->vector[1]=input->vector[1];
output->vector[2]=input->vector[2];
output->vector[3]=input->vector[3];
output->matrix[0]=input->matrix[0];
output->matrix[1]=input->matrix[1];
output->matrix[2]=input->matrix[2];
output->matrix[3]=input->matrix[3];
output->matrix[4]=input->matrix[4];
output->matrix[5]=input->matrix[5];
output->matrix[6]=input->matrix[6];
output->matrix[7]=input->matrix[7];
output->matrix[8]=input->matrix[8];
output->matrix[9]=input->matrix[9];
output->matrix[10]=input->matrix[10];
output->matrix[11]=input->matrix[11];
}}
}   // namespace f3m_00971520

// @f3 0x00976ae0 (community match, verified in this file)
namespace f3m_00976ae0 {
// pdb: hkpMassElement::hkpMassElement | hkInertiaTensorComputer.obj | tesv_win, call_gap, low
struct FUN_00976ae0{float first,second;unsigned int unk08,unk0c;float values[16];FUN_00976ae0(const FUN_00976ae0&);};FUN_00976ae0::FUN_00976ae0(const FUN_00976ae0&source){first=source.first;second=source.second;
values[0]=source.values[0];
values[1]=source.values[1];
values[2]=source.values[2];
values[3]=source.values[3];
values[4]=source.values[4];
values[5]=source.values[5];
values[6]=source.values[6];
values[7]=source.values[7];
values[8]=source.values[8];
values[9]=source.values[9];
values[10]=source.values[10];
values[11]=source.values[11];
values[12]=source.values[12];
values[13]=source.values[13];
values[14]=source.values[14];
values[15]=source.values[15];
}
}   // namespace f3m_00976ae0

// @f3 0x0097e840 (community match, verified in this file)
namespace f3m_0097e840 {
class Collector840 {
public:
    virtual void slot0();
    virtual void beginObject(const char* name, int type, const void* object);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void endObject();
};

class TypeQuery840 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int query(const void* object);
};

class Named840 {
public:
    void* unk00;
    char* FUN_009b0780(char* result);
    void* FUN_009b0490();
};

void __cdecl FUN_0097edb0(void* object, Named840* named, Collector840* collector, TypeQuery840* query);

// pdb: hkStatisticsCollectorUtil::_addObjectContents | hkStatisticsCollectorUtil.obj | tesv_win, call_gap, low
void __cdecl FUN_0097e840(int unused, void* object, Named840* named,
                          Collector840* collector, TypeQuery840* query)
{
    if (!object)
        return;
    int type = query->query(named);
    void* recorded = 0;
    {
        char flag;
        if (*named->FUN_009b0780(&flag)) {
            recorded = object;
            collector->beginObject((const char*)named->FUN_009b0490(), type, object);
        }
    }
    FUN_0097edb0(object, named, collector, query);
    if (recorded)
        collector->endObject();
}
}   // namespace f3m_0097e840

// @f3 0x00970e00 (community match, verified in this file)
extern const char DAT_00e7c8c0[];
namespace f3m_00970e00 {
namespace task1527 {
struct Collector {
 virtual void v0();
 virtual void BeginObject(const char*,int,const void*);
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
 virtual void EndObject();
};
struct Sphere {
 void FUN_00970e00(Collector* collector);
};
void Sphere::FUN_00970e00(Collector* collector) {
 collector->BeginObject(DAT_00e7c8c0,1,this);
 collector->EndObject();
}
}
}   // namespace f3m_00970e00

// @f3 0x0097a450 (community match, verified in this file)
extern const float DAT_00e7c190, DAT_00e19cbc, DAT_00de20b0;
extern const void* DAT_00e7cf44[];
namespace f3m_0097a450 {
namespace n97a450 {
extern "C" void _ReadWriteBarrier();
struct ByteBool { char v; };
struct FUN_0097a450 {
    const void** table;
    unsigned short memFlags, count;
    unsigned char kind;
    char unk09,unk0a,unk0b;
    float minForce,maxForce,tau,damping;
    char velocityClamp;
    FUN_0097a450();
};
// pdb: bhkVelocityConstraintMotor::bhkVelocityConstraintMotor | bhkVelocityConstraintMotor.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
FUN_0097a450::FUN_0097a450() {
    minForce=DAT_00e7c190;
    maxForce=DAT_00e19cbc;
    count=1;
    ByteBool clamp={};
    kind=2;
    damping=1.0f;
    tau=DAT_00de20b0;
    _ReadWriteBarrier();
    velocityClamp=clamp.v;
    _ReadWriteBarrier();
    table=DAT_00e7cf44;
}
}
}   // namespace f3m_0097a450

// @f3 0x00979ed0 (community match, verified in this file)
namespace f3m_00979ed0 {
struct Arr97 {
    int* pBase;
    int iSize;
    int capacity;
    void Add(const int& value);
};

void __cdecl FUN_00901f10(Arr97* arr, int elemSize);

inline void Arr97::Add(const int& value)
{
    if (iSize == (capacity & 0x3fffffff))
        FUN_00901f10(this, 4);
    pBase[iSize++] = value;
}

struct Obj97 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c;
    void hkpBinaryAction_getEntities(Arr97* arr) const;
};

// pdb: hkpBinaryAction::getEntities | hkpBinaryAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Obj97::hkpBinaryAction_getEntities(Arr97* arr) const
{
    arr->Add(unk18);
    arr->Add(unk1c);
}
}   // namespace f3m_00979ed0

// @f3 0x0097ea00 (community match, verified in this file)
namespace f3m_0097ea00 {
class Desc97 {
public:
    int FUN_009b0760();
};

class IFace97 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(void* type);
    virtual void slot5();
};

void __cdecl FUN_0097e900(int arg0, char* src, Desc97* desc, IFace97* iface, int arg4);

void __cdecl FUN_0097ea00(void** type, char* src, Desc97* desc, int count, IFace97* iface, int arg5)
{
    int stride = desc->FUN_009b0760();
    iface->slot4(*type);
    char* p = src;
    if (count > 0) {
        int i = count;
        do {
            FUN_0097e900(0, p, desc, iface, arg5);
            p += stride;
        } while (--i);
    }
    iface->slot5();
}
}   // namespace f3m_0097ea00

// @f3 0x009717b0 (community match, verified in this file)
namespace f3m_009717b0 {

struct Sub20_97 {
    void FUN_0096cd10(float scale);
};

struct Obj97 {
    int unk00;
    float unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Sub20_97 sub20;
};

// pdb: scaleMassProperties | hkInertiaTensorComputer.obj | tesv_win, call_gap, low
static __declspec(noinline) void FUN_009717b0(Obj97* obj, float scale)
{
    obj->unk04 *= scale;
    obj->sub20.FUN_0096cd10(scale);
}

Obj97 g_obj;
float g_scale;
void caller_of_FUN_009717b0() { FUN_009717b0(&g_obj, g_scale); }
}   // namespace f3m_009717b0

// @f3 0x0096aa90 (community match, verified in this file)
namespace f3m_0096aa90 {
extern "C" void _ReadWriteBarrier();
struct Pool0096aa90
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int maxCount;
    int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c,
        unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    void* head;
    int count;
    void FUN_008f6890(int, void*, int);
};

struct Obj0096aa90
{
    void FUN_0096a860();
    Obj0096aa90* FUN_0096aa90(unsigned int flags);
};

// pdb: bhkCharacterPointCollector::`scalar deleting destructor' | bhkCharacterPointCollector.obj | fnv360_0822_retail, caller_sim, low
Obj0096aa90* Obj0096aa90::FUN_0096aa90(unsigned int flags)
{
    FUN_0096a860();
    if ((flags & 1) && this)
    {
        Pool0096aa90* m = (Pool0096aa90*)TlsGetValue(DAT_010f3170);
        if (m->count >= m->maxCount)
            m->FUN_008f6890(0xd, this, 0x1f);
        else
        {
            _ReadWriteBarrier();
            void* next = m->head;
            m->count++;
            *(void**)this = next;
            m->head = this;
        }
    }
    return this;
}
}   // namespace f3m_0096aa90

// @f3 0x00976b60 (community match, verified in this file)
namespace f3m_00976b60 {
class FUN_00976b60
{
public:
    volatile float unk00;
    volatile float unk04;
    int unk08;
    int unk0c;
    volatile float unk10;
    volatile float unk14;
    volatile float unk18;
    volatile float unk1c;
    volatile float unk20;
    volatile float unk24;
    volatile float unk28;
    volatile float unk2c;
    volatile float unk30;
    volatile float unk34;
    volatile float unk38;
    volatile float unk3c;
    volatile float unk40;
    volatile float unk44;
    volatile float unk48;
    volatile float unk4c;
    volatile float unk50;
    volatile float unk54;
    volatile float unk58;
    volatile float unk5c;
    volatile float unk60;
    volatile float unk64;
    volatile float unk68;
    volatile float unk6c;
    volatile float unk70;
    volatile float unk74;
    volatile float unk78;
    volatile float unk7c;
    volatile float unk80;
    volatile float unk84;
    volatile float unk88;
    volatile float unk8c;
    FUN_00976b60();
};

FUN_00976b60::FUN_00976b60()
{
    unk00 = 0.0f;
    unk04 = 0.0f;
    unk1c = 0.0f;
    unk18 = 0.0f;
    unk14 = 0.0f;
    unk10 = 0.0f;
    unk20 = 0.0f;
    unk24 = 0.0f;
    unk28 = 0.0f;
    unk2c = 0.0f;
    unk30 = 0.0f;
    unk34 = 0.0f;
    unk38 = 0.0f;
    unk3c = 0.0f;
    unk40 = 0.0f;
    unk44 = 0.0f;
    unk48 = 0.0f;
    unk4c = 0.0f;
    unk50 = 0.0f;
    unk54 = 0.0f;
    unk58 = 0.0f;
    unk5c = 0.0f;
    unk60 = 0.0f;
    unk64 = 0.0f;
    unk68 = 0.0f;
    unk6c = 0.0f;
    unk70 = 0.0f;
    unk74 = 0.0f;
    unk78 = 0.0f;
    unk7c = 0.0f;

    unk50 = 1.0f;
    unk64 = 1.0f;
    unk78 = 1.0f;
    unk8c = 0.0f;
    unk88 = 0.0f;
    unk84 = 0.0f;
    unk80 = 0.0f;
}
}   // namespace f3m_00976b60

// @f3 0x0096cc30 (community match, verified in this file)
namespace f3m_0096cc30 {
struct V4 {
    float x, y, z, w;
    V4& operator+=(const V4& o) { x += o.x; y += o.y; z += o.z; w += o.w; return *this; }
};
struct FUN_0096cc30_owner {
    V4 a, b, c;
    void FUN_0096cc30(const FUN_0096cc30_owner& s);
};
// pdb: hkMatrix3::add | hkMatrix3.obj | fnv360_0822_debug, objrun_prop, medium
// pdb params: a
void FUN_0096cc30_owner::FUN_0096cc30(const FUN_0096cc30_owner& s) {
    a += s.a;
    b.x += s.b.x; b.y += s.b.y; b.z += s.b.z; b.w += s.b.w;
    c += s.c;
}
}   // namespace f3m_0096cc30

// @f3 0x00979fb0 (community match, verified in this file)
namespace f3m_00979fb0 {
struct hk979fb0 { void FUN_009318b0() throw(); };
struct Ni979fb0 { int vtbl; short active; short refs; };
class Base979fb0 {
public:
    unsigned short unk04;
    short refs;
    Base979fb0() { refs = 1; }
    ~Base979fb0();
};
class FUN_00979fb0 : public Base979fb0 {
public:
    virtual ~FUN_00979fb0();
    int unk08;
    struct NiPtr { Ni979fb0* p; NiPtr(Ni979fb0* q) : p(q) {} ~NiPtr(); Ni979fb0* operator->() const { return p; } } ni;
    int unk10;
    hk979fb0* a;
    hk979fb0* b;
    bool flag1c;
    bool flag1d;
    int unk20, unk24, unk28;
    FUN_00979fb0(hk979fb0* a_, hk979fb0* b_, Ni979fb0* n, bool f);
};
// pdb: hkpConstraintInstance::hkpConstraintInstance | hkpConstraintInstance.obj | fnv360_0822_retail, call_gap, medium
// pdb params: entityA, entityB, data, priority
FUN_00979fb0::FUN_00979fb0(hk979fb0* a_, hk979fb0* b_, Ni979fb0* n, bool f)
    : unk08(0), ni(n), flag1c(f), flag1d(false), unk20(0), unk24(0), unk28(0)
{
    a = a_;
    b = b_;
    unk10 = 0;
    a_->FUN_009318b0();
    if (b)
        b->FUN_009318b0();
    if (ni->active)
        ++ni->refs;
}
}   // namespace f3m_00979fb0

// @f3 0x0096ae00 (community match, verified in this file)
namespace f3m_0096ae00 {
// pdb: bhkCharacterStateClimbing::Update | bhkCharacterStateClimbing.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInput
namespace Task96ae{struct Vector{float x,y,z,w;void Set(float value){x=0.0f;y=0.0f;z=value;w=0.0f;}};struct Owner{int unk000;int unk004;int unk008;int unk00c;int unk010;int unk014;int unk018;int unk01c;int unk020;int unk024;int unk028;int unk02c;int unk030;int unk034;int unk038;int unk03c;int unk040;int unk044;int unk048;int unk04c;int unk050;int unk054;int unk058;int unk05c;int unk060;int unk064;int unk068;int unk06c;int unk070;int unk074;int unk078;int unk07c;int unk080;int unk084;int unk088;int unk08c;int unk090;int unk094;int unk098;int unk09c;int unk0a0;int unk0a4;int unk0a8;int unk0ac;int unk0b0;int unk0b4;int unk0b8;int unk0bc;int unk0c0;int unk0c4;int unk0c8;int unk0cc;int unk0d0;int unk0d4;int unk0d8;int unk0dc;int unk0e0;int unk0e4;int unk0e8;int unk0ec;int unk0f0;int unk0f4;int unk0f8;int unk0fc;int unk100;int unk104;int unk108;int unk10c;int unk110;int unk114;int unk118;int unk11c;int unk120;int unk124;int unk128;int unk12c;int unk130;int unk134;int unk138;int unk13c;int unk140;int unk144;int unk148;int unk14c;int unk150;int unk154;int unk158;int unk15c;int unk160;int unk164;int unk168;int unk16c;int unk170;int unk174;int unk178;int unk17c;int unk180;int unk184;int unk188;int unk18c;int unk190;int unk194;int unk198;int unk19c;int unk1a0;int unk1a4;int unk1a8;int unk1ac;int unk1b0;int unk1b4;int unk1b8;int unk1bc;int unk1c0;int unk1c4;int unk1c8;int unk1cc;int unk1d0;int unk1d4;int unk1d8;int unk1dc;int unk1e0;int unk1e4;int unk1e8;int unk1ec;int unk1f0;int unk1f4;int unk1f8;int unk1fc;int unk200;int unk204;int unk208;int unk20c;int unk210;int unk214;int unk218;int unk21c;int unk220;int unk224;int unk228;int unk22c;int unk230;int unk234;int unk238;int unk23c;int unk240;int unk244;int unk248;int unk24c;int unk250;int unk254;int unk258;int unk25c;int unk260;int unk264;int unk268;int unk26c;int unk270;int unk274;int unk278;int unk27c;int unk280;int unk284;int unk288;int unk28c;int unk290;volatile unsigned flags;int unk298;int unk29c;int unk2a0;int unk2a4;int unk2a8;int unk2ac;int unk2b0;int unk2b4;int unk2b8;int unk2bc;int unk2c0;int unk2c4;int unk2c8;int unk2cc;int unk2d0;int unk2d4;int unk2d8;int unk2dc;int unk2e0;int unk2e4;int unk2e8;int unk2ec;int unk2f0;int unk2f4;int unk2f8;int unk2fc;int unk300;int unk304;int unk308;int unk30c;int unk310;int unk314;int unk318;int unk31c;int unk320;int unk324;int unk328;int unk32c;int unk330;int unk334;int unk338;int unk33c;int unk340;float value;int unk348;int unk34c;int type;int unk354;int unk358;int unk35c;int unk360;int unk364;int unk368;int unk36c;int unk370;int unk374;int unk378;int unk37c;int unk380;int unk384;int unk388;int unk38c;Vector vector;float Value(){return value;}void Enable(){flags|=1024;}void FUN_008e8900();};void __stdcall FUN_0096ae00(Owner*obj){if(obj->type!=11){obj->FUN_008e8900();return;}obj->Enable();obj->vector.Set(obj->Value());}}
}   // namespace f3m_0096ae00

// @f3 0x009791f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009791f0 {
namespace f3m_009791f0 {
struct Mem91f0 { void FUN_008f6d90(void* p, int bytes, int tag); };
__declspec(dllimport) Mem91f0* __stdcall FUN_00d9b080(unsigned long);
struct Arr91f0 {
    void** m_data;
    int m_size;
    int m_capacityAndFlags;
};
struct Obj91f0 {
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
    Arr91f0 m_arr;
    void FUN_00989b30();
    void FUN_009791f0();
};
// pdb: hkpAabbPhantom::deallocateInternalArrays | hkpAabbPhantom.obj | fnv360_0822_retail, objrun_prop, low
void Obj91f0::FUN_009791f0()
{
    if (m_arr.m_size == 0) {
        if ((m_arr.m_capacityAndFlags & 0x80000000) == 0) {
            int cap = m_arr.m_capacityAndFlags & 0x3fffffff;
            Mem91f0* mem = FUN_00d9b080(DAT_010f3170);
            mem->FUN_008f6d90(m_arr.m_data, cap * 4, 0x17);
        }
        m_arr.m_data = 0;
        m_arr.m_size = 0;
        m_arr.m_capacityAndFlags = (m_arr.m_capacityAndFlags & 0xc0000000) | 0x80000000;
    }
    FUN_00989b30();
}
}
}   // namespace f3m_009791f0

// @f3 0x0096c4a0 (community match, verified in this file)
namespace f3m_0096c4a0 {
namespace Scale352{
struct Matrix{float values[12];void FUN_0096c4a0(float,const Matrix*);};
// pdb: hkMatrix3::isApproximatelyEqual | hkMatrix3.obj | fnv360_0822_debug, objrun_prop, low, conflict (skyrim: hkMatrix4::set4x4ColumnMajor)
// pdb params: m, zero
void Matrix::FUN_0096c4a0(float scale,const Matrix*source){
values[0]=source->values[0]*scale;
values[1]=source->values[1]*scale;
values[2]=source->values[2]*scale;
values[3]=source->values[3]*scale;
{const double& factor=static_cast<double>(scale);values[4]=factor*source->values[4];}
values[5]=source->values[5]*scale;
values[6]=source->values[6]*scale;
values[7]=source->values[7]*scale;
values[8]=source->values[8]*scale;
values[9]=source->values[9]*scale;
values[10]=source->values[10]*scale;
values[11]=source->values[11]*scale;
}}



}   // namespace f3m_0096c4a0

// @f3 0x0096cd10 (community match, verified in this file)
namespace f3m_0096cd10 {
struct Mat12 {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    void FUN_0096cd10(float s);
};

// pdb: hkMatrix3::mul | hkMatrix3.obj | tesv_win, call_seq, medium
void Mat12::FUN_0096cd10(float s)
{
    m00 *= s;
    m01 *= s;
    m02 = *(volatile float*)&m02 * s;
    m03 *= s;
    m10 = *(volatile float*)&m10 * s;
    m11 = *(volatile float*)&m11 * s;
    m12 = *(volatile float*)&m12 * s;
    m13 *= s;
    m20 *= s;
    {const double& factor=static_cast<double>(s);m21=factor*m21;}
    m22 = *(volatile float*)&m22 * s;
    m23 *= s;
}

}   // namespace f3m_0096cd10

// @f3 0x0096c510 (community match, verified in this file)
namespace f3m_0096c510 {
namespace f3m_96c510 {
struct Vec {
    float x, y, z, w;
    void addMul(float r, const Vec& a) { x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
};
struct Mat {
    Vec c[3];
    void FUN_0096c510(float s, const Mat& a);
};
void Mat::FUN_0096c510(float s, const Mat& a)
{
    float* d = &c[0].x;
    const float* v = &a.c[0].x;
    for (int i = 0; i < 4; i++)
        d[i] += s * v[i];
    c[1].addMul(s, a.c[1]);
    c[2].addMul(s, a.c[2]);
}
}
}   // namespace f3m_0096c510

// @f3 0x0097edb0 (community match, verified in this file)
extern void* DAT_0116bf44;
namespace f3m_0097edb0 {
namespace class_chain_walk {
struct ClassNode { ClassNode* FUN_009b04a0(); };
void* __cdecl FUN_0097e8d0(void*);
void __cdecl FUN_0097eaf0(void*, ClassNode*, int, void*);
// pdb: hkStatisticsCollectorUtil::addClassContentsAll | hkStatisticsCollectorUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: obj, cls, collector
void __cdecl FUN_0097edb0(void* object, ClassNode* type, int flags, void* registry) {
if (!object) return;
    registry = FUN_0097e8d0(registry);
    ClassNode* t = type;
    do {
        FUN_0097eaf0(object, t, flags, registry);
        t = t->FUN_009b04a0();
    } while (t);
}
}
}   // namespace f3m_0097edb0

// @f3 0x00962190 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00962190 {
namespace n962190 {
struct Alloc {
    void FUN_008f6d90(void* p, int size, int tag) throw();
    void* FUN_008f6d30(int size, int tag) throw();
};
struct RefObj {
    unsigned short memSize;
    short refCount;
    virtual ~RefObj() throw() {}
    void addReference() throw() {
        if (memSize != 0) ++refCount;
    }
};
struct Part { void FUN_009316e0() throw(); };
template <class T> __forceinline void copy(T* dst, const T* src, int n) { for (int i = 0; i < n; i++) dst[i] = src[i]; }
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    __forceinline void assign(const Array& o) throw() {
        if ((capAndFlags & 0x3fffffff) < o.size) { int cap = capAndFlags & 0x3fffffff;
            if ((capAndFlags & 0x80000000) == 0) {
                Alloc* al = (Alloc*)::FUN_00d9b080(DAT_010f3170);
                al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
            }
            Alloc* al = (Alloc*)::FUN_00d9b080(DAT_010f3170);
            data = (T*)al->FUN_008f6d30(o.size * sizeof(T), 0x17);
            capAndFlags = (capAndFlags & 0x40000000) | o.size;
        }
        size = o.size;
        copy(data, o.data, size);
    }
};
}
struct FUN_00962190_obj : n962190::RefObj {
    n962190::Array<n962190::Part*> parts;
    n962190::Array<n962190::RefObj*> refs;
    n962190::Array<void*> extra;
    void* skeleton;
    void FUN_00962190(const n962190::Array<n962190::Part*>& p, const n962190::Array<n962190::RefObj*>& r, void* s);
};
// pdb: hkaRagdollInstance::commonInit | hkaRagdollInstance.obj | tesv_win, objrun_prop, low
void FUN_00962190_obj::FUN_00962190(const n962190::Array<n962190::Part*>& p, const n962190::Array<n962190::RefObj*>& r, void* s)
{
    skeleton = s;
    parts.assign(p);
    refs.assign(r);
    for (int i = 0; i < parts.size; i++)
        if (parts.data[i])
            parts.data[i]->FUN_009316e0();
    for (int i = 0; i < refs.size; i++)
        if (refs.data[i])
            refs.data[i]->addReference();
}
}   // namespace f3m_00962190

// @f3 0x009795b0 (community match, verified in this file)
namespace f3m_009795b0 {
namespace n9795b0 {
struct Stream;
typedef int (__cdecl* ReadFn)(Stream* s, void* buf, int size, int* count, int flag);
struct Stream { int x0; int pos; ReadFn read; int Read(void* buf, int size) { int n = size; return read(this, buf, size, &n, 1); } };
struct Reader { int x0; unsigned int version; char pad[0x24c - 8]; Stream* stream; };
struct Vec4 {
    float x, y, z, w;
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
struct QsTransform { Vec4 translation; Vec4 rotation; Vec4 scale; };
}
// pdb: bhkStream::LoadBinary | bhkStream.obj | fnv360_0822_retail, caller, low, conflict (skyrim: hkbGeneratorOutputUtils::initTracks)
// pdb params: arStream, arTransf
void __cdecl FUN_009795b0(n9795b0::Reader* r, n9795b0::QsTransform* t)
{
    float x, y, z, w;
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&x, 4); }
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&y, 4); }
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&z, 4); }
    t->translation.set(x, y, z, 0.0f);
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&x, 4); }
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&y, 4); }
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&z, 4); }
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&w, 4); }
    t->rotation.set(x, y, z, w);
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&x, 4); }
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&y, 4); }
    { n9795b0::Stream* s = r->stream; s->pos += s->Read(&z, 4); }
    t->scale.set(x, y, z, 0.0f);
}
}   // namespace f3m_009795b0

// @f3 0x0096a7f0 (community match, verified in this file)
namespace f3m_0096a7f0 {
namespace n96a7f0 {
struct hkpRootCdPoint
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C;
};
struct hkReferencedObject;

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    hkArray(T* buffer, int size, int capacity) : m_data(buffer), m_size(size), m_capacityAndFlags(capacity | 0x80000000) {}
    void clear() { m_size = 0; }
};

template <class T, int N>
struct hkInplaceArray : hkArray<T>
{
    unsigned int m_pad;
    T m_storage[N];
    hkInplaceArray(int size = 0) : hkArray<T>(m_storage, size, N) {}
};

struct hkpCdPointCollector
{
    hkpCdPointCollector() { reset(); }
    virtual ~hkpCdPointCollector();
    void reset() { m_earlyOutDistance = 3.40282e38f; }
    float m_earlyOutDistance;
    unsigned int unk08, unk0C;
};

struct hkpAllCdPointCollector : hkpCdPointCollector
{
    hkpAllCdPointCollector() { reset(); }
    virtual ~hkpAllCdPointCollector();
    void reset() { m_hits.clear(); hkpCdPointCollector::reset(); }
    hkInplaceArray<hkpRootCdPoint, 8> m_hits;
};
}

struct FUN_0096a7f0 : n96a7f0::hkpAllCdPointCollector
{
    FUN_0096a7f0(unsigned int arg);
    virtual ~FUN_0096a7f0();
    unsigned int unk220;
    n96a7f0::hkArray<n96a7f0::hkReferencedObject*> references;
    n96a7f0::hkArray<unsigned int> indices;
    n96a7f0::hkArray<n96a7f0::hkpRootCdPoint> contacts;
};

// pdb: bhkCharacterPointCollector::bhkCharacterPointCollector | bhkCharacterPointCollector.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: apStartCollector
FUN_0096a7f0::FUN_0096a7f0(unsigned int arg) : unk220(arg)
{
    references.clear(); contacts.clear(); indices.clear();
}
}   // namespace f3m_0096a7f0

// @f3 0x00969ff0 (community match, verified in this file)
namespace f3m_00969ff0 {
namespace f3m_00969ff0 {
struct Vec4 {
    float x, y, z, w;
    __forceinline Vec4& operator=(const Vec4& value) {
        x=value.x; y=value.y; z=value.z; w=value.w;
        return *this;
    }
};
struct __declspec(align(16)) Record {
    Vec4 first, second;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    __forceinline Record& operator=(const Record& value) {
        first=value.first; second=value.second;
        unk20=value.unk20; unk24=value.unk24; unk28=value.unk28; unk2c=value.unk2c;
        unk30=value.unk30; unk34=value.unk34; unk38=value.unk38;
        return *this;
    }
};
struct Bool { unsigned char value; };
struct Owner {
    unsigned int unk00, unk04, unk08, unk0c;
    Record* data;
    int size;
    int capacityAndFlags;
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
    Owner* next;
    Bool* FUN_00969f70(Bool*, const Record*, const Record*);
    void FUN_00969ff0();
    __forceinline const Record* GetNextRecord(int index) const { return &(*(Record* const volatile*)&next->data)[index]; }
    __forceinline void RemoveAt(int index) { data[index] = data[--size]; }
};
// pdb: bhkCharacterPointCollector::filterOutEdgeHits | bhkCharacterPointCollector.obj | fnv360_0822_retail, call_gap, medium
void Owner::FUN_00969ff0()
{
    Bool result;
    for (int i = size - 1; i > 0; --i) {
        int j = i - 1;
        if (j != 0) {
            Record* candidate = &data[i];
            Record* earlier = &data[j];
            do {
                --earlier;
                --j;
                if (FUN_00969f70(&result, earlier, candidate)->value) {
                    RemoveAt(i);
                    break;
                }
            } while (j != 0);
        }
    }
    if (next) {
        int j = next->size;
        while (j != 0) {
            --j;
            int i = size;
            while (i != 0) {
                --i;
                const Record* other = GetNextRecord(j);
                if (FUN_00969f70(&result, other, &data[i])->value)
                    RemoveAt(i);
            }
        }
    }
}
}





}   // namespace f3m_00969ff0

// @f3 0x00979ae0 (community match, verified in this file)
#include <stdlib.h>
extern char DAT_00dcc864;
namespace f3m_00979ae0 {
extern "C" void _ReadWriteBarrier(void);
namespace n979ae0 {
struct Stream;
typedef int (__cdecl* ReadFn)(Stream* s, void* buf, int size, int* count, int flag);
struct Stream {
    int x0;
    int pos;
    ReadFn read;
    int ReadRaw(void* buf, int size) { return read(this, buf, size, 0, 0); }
    int Read(void* buf, int size, int elem) { int n = elem; return read(this, buf, size, &n, 1); }
};
struct Reader {
    int x0;
    unsigned int version;
    char pad[0x1e5 - 8];
    unsigned char sameEndian;
    char pad2[0x24c - 0x1e6];
    Stream* stream;
};
struct hkThreadMemory {
    void* FUN_008f6d30(int nbytes, int memClass);
};
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();
struct Array {
    unsigned char* data;
    int size;
    int capAndFlags;
    Array() : data(0), size(0), capAndFlags(0x80000000) {}
    void setSize(int n)
    {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, 1);
        }
        size = n;
    }
};
struct Vec4 { unsigned int x, y, z, w; };
inline void Swap4(unsigned int* p)
{
    p[0] = _byteswap_ulong(p[0]); _ReadWriteBarrier();
    p[1] = _byteswap_ulong(p[1]); _ReadWriteBarrier();
    p[2] = _byteswap_ulong(p[2]); _ReadWriteBarrier();
    p[3] = _byteswap_ulong(p[3]);
}
struct RefHeader {
    void* vt;
    unsigned short memSizeAndFlags;
    short refCount;
    RefHeader(void* table) { refCount = 1; vt = table; }
};
struct Obj : RefHeader {
    int unk08;
    int unk0c;
    float v[4];
    Array arr;
    int unk2c;
    static void* operator new(unsigned int size)
    {
        hkThreadMemory* mem = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
        Obj* b = (Obj*)mem->FUN_008f6d30(size, 0x28);
        b->memSizeAndFlags = (unsigned short)size;
        return b;
    }
    Obj() : RefHeader(&DAT_00dcc864)
    {
        v[0] = v[1] = v[2] = v[3] = 0.0f;
    }
};
}
// pdb: bhkStream::LoadBinary | bhkStream.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arStream, arMoppCode
int __cdecl FUN_00979ae0(n979ae0::Reader* r, n979ae0::Obj** out)
{
    using namespace n979ae0;
    *out = new Obj;
    int count = 0;
    { Stream* s = r->stream; s->pos += s->Read(&count, 4, 4); }
    { Stream* s = r->stream; s->pos += s->ReadRaw((*out)->v, 0x10); }
    if (r->version < 6 && count) {
        unsigned int skip[8];
        count -= 0x30;
        Stream* s = r->stream; s->pos += s->Read(skip, 0x20, 4);
    }
    if (count) {
        (*out)->arr.setSize(count);
        Stream* s = r->stream; s->pos += s->ReadRaw((*out)->arr.data, count);
    }
    if (r->sameEndian != 1)
        Swap4((unsigned int*)(*out)->v);
    return count;
}
}   // namespace f3m_00979ae0

// @f3 0x0097e900 (community match, verified in this file)
namespace f3m_0097e900 {
namespace NativeReflectWrite
{
struct Descriptor
{
    char* FUN_009b0780(char* result);
    int FUN_009b0760();
    const char* FUN_009b0490();
};
struct Collector
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void CopyObject(const char* name, int type, const void* object, int bytes, void* storage);
    virtual void WriteObject(const char* name, int type, const void* object);
};
struct Query
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual int Type(Descriptor* desc);
};
void __cdecl FUN_0097e840(const char* name, const void* object, Descriptor* desc, Collector* collector, Query* query);

void __cdecl FUN_0097e900(const char* name, const void* object, Descriptor* desc, Collector* collector, Query* query)
{
    if (!object)
        return;
    int type = query->Type(desc);
    char direct;
    if (*desc->FUN_009b0780(&direct)) {
        collector->WriteObject(name, type, object);
        return;
    }
    int bytes = desc->FUN_009b0760();
    void* memory = f3m_0097e7f0::DAT_010f3400->allocate(bytes);
    const char* label = name ? name : desc->FUN_009b0490();
    collector->CopyObject(label, type, object, bytes, memory);
    FUN_0097e840(name, object, desc, collector, query);
}
}
}   // namespace f3m_0097e900

// @f3 0x0096ab90 (community match, verified in this file)
namespace f3m_0096ab90 {
struct __declspec(align(16)) State27 { unsigned char data[512]; };
struct Action27 {
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
    virtual void unknown0a8();
    virtual void unknown0ac();
    virtual void unknown0b0();
    virtual void unknown0b4();
    virtual void unknown0b8();
    virtual void unknown0bc();
    virtual void unknown0c0();
    virtual void unknown0c4();
    virtual void unknown0c8();
    virtual void unknown0cc();
    virtual void Apply(void*);
};
struct Entry27 { int unk00,unk04; Action27* action; };
struct Cursor27 {
    virtual void unknown00();
    virtual void unknown04();
    virtual int First();
    virtual int Next(int);
    virtual void unknown10();
    virtual Entry27* Get(int, State27*);
};
struct Collection27 { int unk00,unk04,unk08,unk0c; Cursor27 cursor; };
struct Owner27 { int unk00,unk04; Collection27* collection; void FUN_0096ab90(void*);
    Action27* GetAction(int position,State27& state) {
        Collection27* source=this ? collection : 0;
        if(!source) return 0;
        Entry27* entry=source->cursor.Get(position,&state);
        return entry ? entry->action : 0;
    }
};
// pdb: hkArrayBase<hkaSkeletonMapperUtils::UserChain>::copyFromArray | hkaSkeletonMapperUtils.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: bhkShapeCollection::CanShare)
// pdb params: alloc, a, __formal
void Owner27::FUN_0096ab90(void* argument) {
    State27 state;
    void* arg=argument;
    int position=(this ? collection : 0)->cursor.First();
    bool keepGoing=true;
    while(keepGoing && position!=-1) {
        Action27* action=GetAction(position,state);
        position=(this ? collection : 0)->cursor.Next(position);
        if(action) action->Apply(arg);
        else keepGoing=false;
    }
}
}   // namespace f3m_0096ab90

// @f3 0x0096ac50 (community match, verified in this file)
namespace f3m_0096ac50 {
bool __stdcall FUN_008f7650(void* key);

struct Cd2Target
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
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual bool Accepts(void* key);
};

struct Cd2Entry
{
    int unk00;
    int unk04;
    Cd2Target* m_target;
};

struct Cd2Iterable
{
    virtual void v00();
    virtual void v04();
    virtual int GetFirst();
    virtual int GetNext(int i);
    virtual void v10();
    virtual Cd2Entry* GetEntry(int i, char* buffer);
};

struct Cd2Collection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Cd2Iterable m_items;
};

class Cd2Owner
{
  public:
    int unk00;
    int unk04;
    Cd2Collection* m_pShapeCollection;

    __forceinline Cd2Collection* GetCollection()
    {
        return this ? m_pShapeCollection : 0;
    }
    bool FUN_0096ac50(void* key);
};

// @fnv 0x00cd2f10
// pdb: bhkShapeCollection::CanShare | bhkShapeCollection.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: arCloneData
bool Cd2Owner::FUN_0096ac50(void* key)
{
    __declspec(align(16)) char buffer[512];
    bool ok = FUN_008f7650(key);
    if (ok)
    {
        for (int i = GetCollection()->m_items.GetFirst(); i != -1 && ok; i = GetCollection()->m_items.GetNext(i))
        {
            Cd2Collection* collection = GetCollection();
            if (collection)
            {
                Cd2Entry* entry = collection->m_items.GetEntry(i, buffer);
                if (entry)
                {
                    Cd2Target* target = entry->m_target;
                    if (target)
                        ok = target->Accepts(key);
                }
            }
        }
    }
    return ok;
}
}   // namespace f3m_0096ac50

// @f3 0x00977fc0 (community match, verified in this file)
namespace f3m_00977fc0 {
namespace f3m_00977fc0 {
struct __declspec(align(16)) QVec4 {
    float x, y, z, w;
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline float& operator()(int i) { return (&x)[i]; }
};
struct QRotation {
    QVec4 col0, col1, col2;
};
struct QTransform {
    QRotation rot;
    QVec4 pos;
    void FUN_008fda60(const QTransform& other);
};
struct QQuat {
    QVec4 vec;
    void FUN_00924360(const QRotation& r);
};
struct QSwept {
    QVec4 com0;
    QVec4 com1;
    QVec4 rot0;
    QVec4 rot1;
    QVec4 comLocal;
};
struct QMotionState {
    QTransform transform;
    QSwept swept;
    QVec4 deltaAngle;
};
static __forceinline void CopyQ(QVec4& d, const QVec4& s) { d.x = s.x; d.y = s.y; d.z = s.z; d.w = s.w; }
// pdb: hkSweptTransformUtil::warpTo | hkSweptTransformUtil.obj | tesv_win, objrun, medium
void FUN_00977fc0(const QTransform& transform, QMotionState& ms)
{
    QSwept& st = ms.swept;
    ms.deltaAngle.setZero4();
    QQuat rotation;
    rotation.FUN_00924360(transform.rot);
    ms.transform.FUN_008fda60(transform);
    CopyQ(st.rot0, rotation.vec);
    CopyQ(st.rot1, rotation.vec);
    QVec4 shift;
    const QRotation& r = transform.rot;
    float vx = st.comLocal.x;
    float vy = st.comLocal.y;
    float vz = st.comLocal.z;
    shift.x = r.col0.x * vx + r.col1.x * vy + r.col2.x * vz;
    shift.y = r.col0.y * vx + r.col1.y * vy + r.col2.y * vz;
    shift.z = r.col0.z * vx + r.col1.z * vy + r.col2.z * vz;
    shift.w = 0.0f;
    float baseTime = st.com0.w;
    st.com0.x = transform.pos.x + shift.x;
    st.com0.y = transform.pos.y + shift.y;
    st.com0.z = transform.pos.z + shift.z;
    st.com0.w = transform.pos.w + shift.w;
    CopyQ(st.com1, st.com0);
    st.com0.w = baseTime;
    st.com1.w = 0.0f;
}
}
}   // namespace f3m_00977fc0

// @f3 0x0097e570 (community match, verified in this file)
namespace f3m_0097e570 {
namespace f3m_0097e570 {
struct Q3Bool { char v; Q3Bool(bool b) { v = (char)b; } };
struct __declspec(align(16)) Q3Vec { float x, y, z, w; };
struct Q3Other {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; 
    Q3Vec pos;
    int unk140, unk144, unk148, unk14c;
    Q3Vec rot;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    float unk180;
};
static __declspec(noinline) float FUN_0097e3f0(const Q3Vec& a, const Q3Vec& b)
{
    Q3Vec d;
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    return d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w;
}
struct Q3Track {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; 
    Q3Vec pos;
    Q3Vec rot;
    int unk50, unk54, unk58;
    float unk5c;
    float unk60;
    Q3Bool FUN_0097e570(Q3Other* o);
};
Q3Bool Q3Track::FUN_0097e570(Q3Other* o)
{
    float f = o->unk180;
    const Q3Vec* orot = &o->rot;
    Q3Vec d;
    d.x = pos.x - o->pos.x;
    d.y = pos.y - o->pos.y;
    d.z = pos.z - o->pos.z;
    float lenSq = d.x * d.x + d.y * d.y + d.z * d.z;
    float tol = unk5c * unk5c;
    if (lenSq < tol) {
        float r = FUN_0097e3f0(rot, *orot);
        float a = r * f * f;
        float b = unk60 * unk60;
        if (a < b)
            return true;
    }
    pos.x = o->pos.x;
    pos.y = o->pos.y;
    pos.z = o->pos.z;
    pos.w = o->pos.w;
    rot.x = orot->x;
    rot.y = orot->y;
    rot.z = orot->z;
    rot.w = orot->w;
    return false;
}
}
}   // namespace f3m_0097e570

// @f3 0x009768c0 (community match, verified in this file)
namespace f3m_009768c0 {

struct __declspec(align(16)) Mat16
{
    float m[16];
};

struct Sub20
{
    void FUN_0096cd10(float v);
};

struct Obj;

struct Dst
{
    void FUN_00976ae0(const Obj* src);
};

struct Obj
{
    float unk00;   // +0x00
    float unk04;   // +0x04
    int   unk08;   // +0x08
    int   unk0c;   // +0x0c
    Mat16 mA;      // +0x10
    Mat16 mB;      // +0x50
    void FUN_00976b60();
};

extern "C" void __cdecl FUN_00975d50(void* p1, Mat16* m, Obj* o);

static __declspec(noinline) void FUN_009717b0(float v, Obj* o)
{
    o->unk04 = v * o->unk04;
    ((Sub20*)(o->mA.m + 4))->FUN_0096cd10(v);
}

// pdb: hkpInertiaTensorComputer::computeShapeVolumeMassProperties | hkpInertiaTensorComputer.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: shape, mass, result
void FUN_009768c0(void* p1, float t, int* p3)
{
    Obj a;
    a.FUN_00976b60();

    a.mA.m[0] = a.mA.m[1] = a.mA.m[2] = a.mA.m[3] = 0.0f;
    a.mA.m[4] = 0.0f;
    a.mA.m[5] = 0.0f;
    a.mA.m[6] = 0.0f;
    a.mA.m[7] = 0.0f;
    a.mA.m[8] = 0.0f;
    a.mA.m[9] = 0.0f;
    a.mA.m[10] = 0.0f;
    a.mA.m[11] = 0.0f;
    a.mA.m[12] = 0.0f;
    a.mA.m[13] = 0.0f;
    a.mA.m[14] = 0.0f;
    a.mA.m[15] = 0.0f;
    a.unk04 = 0.0f;
    a.unk00 = 0.0f;

    a.mB.m[0] = 0.0f;
    a.mB.m[1] = 0.0f;
    a.mB.m[2] = 0.0f;
    a.mB.m[3] = 0.0f;
    a.mB.m[4] = 0.0f;
    a.mB.m[5] = 0.0f;
    a.mB.m[6] = 0.0f;
    a.mB.m[7] = 0.0f;
    a.mB.m[8] = 0.0f;
    a.mB.m[9] = 0.0f;
    a.mB.m[10] = 0.0f;
    a.mB.m[11] = 0.0f;
    a.mB.m[0] = 1.0f;
    a.mB.m[5] = 1.0f;
    a.mB.m[10] = 1.0f;
    a.mB.m[12] = a.mB.m[13] = a.mB.m[14] = a.mB.m[15] = 0.0f;

    FUN_00975d50(p1, &a.mB, &a);

    if (a.unk00 != 0.0f)
    {
        FUN_009717b0(t / a.unk00, &a);
        ((Dst*)p3)->FUN_00976ae0(&a);
    }
}
}   // namespace f3m_009768c0

// @f3 0x0097aae0 (community match, verified in this file)
extern const char DAT_010f3370[];
namespace f3m_0097aae0 {
namespace CombinedShapeBounds {
struct AlignedBounds { __declspec(align(16)) float min[4];float max[4]; };
struct ShapeView;
struct ShapeVtable {
    void* unk00;void* unk04;void* unk08;void* unk0c;void* unk10;void* unk14;void* unk18;
    void (__thiscall* getBounds)(ShapeView*,const void*,float,AlignedBounds*);
};
struct ShapeView { ShapeVtable* table; };
struct ShapeEntry { ShapeView* shape;int unk04,unk08,unk0c; };
struct BoundsVector {
    float x,y,z,w;
    __forceinline void Difference(const float* a,const float* b) { x=a[0]-b[0];y=a[1]-b[1];z=a[2]-b[2];w=a[3]-b[3]; }
    __forceinline void Sum(const float* a,const float* b) { x=a[0]+b[0];y=a[1]+b[1];z=a[2]+b[2];w=a[3]+b[3]; }
    __forceinline void Scale(double f) { x=x*f;y=y*f;z=z*f;w=w*f; }
};
struct ShapeCollection {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ShapeEntry* entries;
    int count;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    BoundsVector extents,center;
    void FUN_0097aae0();
};
// pdb: hkpListShape::setShapes | hkpListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: shapeArray, numShapes, filterInfo, ref
void ShapeCollection::FUN_0097aae0()
{
    AlignedBounds combined;
    ShapeView* first=entries[0].shape;
    first->table->getBounds(first,DAT_010f3370,0.0f,&combined);
    for(int i=1;i<count;++i) {
        AlignedBounds other;
        ShapeView* shape=entries[i].shape;
        shape->table->getBounds(shape,DAT_010f3370,0.0f,&other);
        if(!(combined.min[0]<other.min[0])) combined.min[0]=other.min[0];
        if(!(combined.min[1]<other.min[1])) combined.min[1]=other.min[1];
        if(!(combined.min[2]<other.min[2])) combined.min[2]=other.min[2];
        if(!(combined.min[3]<other.min[3])) combined.min[3]=other.min[3];
        if(!(combined.max[0]>other.max[0])) combined.max[0]=other.max[0];
        if(!(combined.max[1]>other.max[1])) combined.max[1]=other.max[1];
        if(!(combined.max[2]>other.max[2])) combined.max[2]=other.max[2];
        if(!(combined.max[3]>other.max[3])) combined.max[3]=other.max[3];
    }
    extents.Difference(combined.max,combined.min);
    extents.Scale(0.5);
    center.Sum(combined.min,combined.max);
    center.Scale(0.5);
}
}
}   // namespace f3m_0097aae0

// @f3 0x00979770 (community match, verified in this file)
namespace f3m_00979770 {
namespace aligned_vector_array_save2000 {
struct ComponentSize{unsigned int size;__forceinline ComponentSize(unsigned int value):size(value){}__forceinline operator unsigned int*(){return &size;}};
struct Writer{unsigned int unk00,position,unk08;unsigned int(__cdecl* write)(Writer*,const void*,unsigned int,unsigned int*,unsigned int);};
struct Owner{unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14C;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15C;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16C;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17C;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18C;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19C;unsigned int unk1A0;unsigned int unk1A4;unsigned int unk1A8;unsigned int unk1AC;unsigned int unk1B0;unsigned int unk1B4;unsigned int unk1B8;unsigned int unk1BC;unsigned int unk1C0;unsigned int unk1C4;unsigned int unk1C8;unsigned int unk1CC;unsigned int unk1D0;unsigned int unk1D4;unsigned int unk1D8;unsigned int unk1DC;unsigned int unk1E0;unsigned int unk1E4;unsigned int unk1E8;unsigned int unk1EC;unsigned int unk1F0;unsigned int unk1F4;unsigned int unk1F8;unsigned int unk1FC;unsigned int unk200;unsigned int unk204;unsigned int unk208;unsigned int unk20C;unsigned int unk210;unsigned int unk214;unsigned int unk218;unsigned int unk21C;unsigned int unk220;unsigned int unk224;unsigned int unk228;unsigned int unk22C;unsigned int unk230;unsigned int unk234;unsigned int unk238;unsigned int unk23C;unsigned int unk240;unsigned int unk244;unsigned int unk248;unsigned int unk24C; Writer* writer;__forceinline void Write(const void* data,unsigned int bytes){Writer* w=writer;w->position+=w->write(w,data,bytes,ComponentSize(bytes),1);}};
struct __declspec(align(16)) Vector4{float x,y,z,w;__forceinline Vector4(const Vector4& source):x(source.x),y(source.y),z(source.z),w(source.w){}};
struct Array{const Vector4* data;int count;};
// pdb: bhkStream::SaveBinary | bhkStream.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream, arArray
int __cdecl FUN_00979770(Owner* owner,const Array* array){int count=array->count;owner->Write(&count,4);unsigned int bytes=(unsigned int)count*sizeof(Vector4);for(int i=0;i<count;++i){Vector4 value(array->data[i]);owner->Write(&value,sizeof(value));}return(int)bytes;}
}
}   // namespace f3m_00979770

// @f3 0x00978250 (community match, verified in this file)
#include <math.h>
#include <float.h>
namespace f3m_00978250 {

template <typename T>
class PadSpu
{
public:
    __forceinline PadSpu() {}
    __forceinline PadSpu(T e) : m_storage(e) {}
    __forceinline void operator=(T e) { m_storage = e; }
    __forceinline T val() const { return m_storage; }
    __forceinline T operator->() const { return m_storage; }
    __forceinline operator T() const { return val(); }
private:
    T m_storage;
};

class BoolWrap
{
public:
    inline BoolWrap() {}
    inline BoolWrap(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }
private:
    char m_bool;
};

struct StepInfo
{
    __declspec(align(16)) PadSpu<float> m_startTime;
    PadSpu<float> m_endTime;
    PadSpu<float> m_deltaTime;
    PadSpu<float> m_invDeltaTime;
};

class Mat3;
class RotMat;
class Quat4;

class Vec4
{
public:
    __forceinline Vec4() {}

    __forceinline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline float& operator()(int i)
    {
        return (&x)[i];
    }

    __forceinline const float& operator()(int i) const
    {
        return (&x)[i];
    }

    __forceinline void setZero4()
    {
        x = y = z = w = 0;
    }

    __forceinline void setSub4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void setMul4(float rs, const Vec4& a)
    {
        float r = float(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }

    __forceinline float length3() const
    {
        return sqrtf((x * x) + (y * y) + (z * z));
    }

    __forceinline void _setMul3(const Mat3& r, const Vec4& v);
    __forceinline void _setRotatedDir(const RotMat& r, const Vec4& v);

private:
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

class Quat4
{
public:
    inline Quat4() {}

    inline void operator=(const Quat4& q)
    {
        m_vec = q.m_vec;
    }

    void FUN_008db610(const Quat4& q0, const Quat4& q1);
    float FUN_008db810() const;
    void FUN_008db880(Vec4& axisOut) const;

    inline BoolWrap hasValidAxis() const
    {
        return m_vec.length3() > FLT_EPSILON;
    }

public:
    Vec4 m_vec;
};

class Mat3
{
public:
    __forceinline Vec4& getColumn(int x)
    {
        return (&m_col0)[x];
    }

    __forceinline const Vec4& getColumn(int x) const
    {
        return (&m_col0)[x];
    }

    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }

    __forceinline const float& operator()(int r, int c) const
    {
        return getColumn(c)(r);
    }

protected:
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
};

class __declspec(align(16)) RotMat : public Mat3
{
public:
    void hkRotation_set(const Quat4& q);
};

__forceinline void Vec4::_setMul3(const Mat3& r, const Vec4& v)
{
    float v0 = v(0);
    float v1 = v(1);
    float v2 = v(2);
    Vec4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline void Vec4::_setRotatedDir(const RotMat& r, const Vec4& v)
{
    _setMul3(r, v);
}

class Transform4
{
public:
    inline Vec4& getTranslation() { return m_translation; }
    inline const Vec4& getTranslation() const { return m_translation; }
    inline RotMat& getRotation() { return m_rotation; }
    inline const RotMat& getRotation() const { return m_rotation; }
    inline void setRotation(const Quat4& quatRotation) { m_rotation.hkRotation_set(quatRotation); }

protected:
    RotMat m_rotation;
    Vec4 m_translation;
};

class SweptTrans
{
public:
    Vec4 m_centerOfMass0;
    Vec4 m_centerOfMass1;
    Quat4 m_rotation0;
    Quat4 m_rotation1;
    Vec4 m_centerOfMassLocal;
};

class MotionState
{
public:
    inline Transform4& getTransform() { return m_transform; }
    inline const Transform4& getTransform() const { return m_transform; }
    inline const SweptTrans& getSweptTransform() const { return m_sweptTransform; }
    inline SweptTrans& getSweptTransform() { return m_sweptTransform; }

protected:
    Transform4 m_transform;
    SweptTrans m_sweptTransform;

public:
    Vec4 m_deltaAngle;
    float m_objectRadius;
    float m_linearDamping;
    float m_angularDamping;
    unsigned char m_maxLinearVelocity;
    unsigned char m_maxAngularVelocity;
    unsigned char m_deactivationClass;
};

__forceinline void calcTransAtT1(const SweptTrans& sweptTrans, Transform4& transformOut)
{
    const Quat4& qt = sweptTrans.m_rotation1;

    transformOut.setRotation(qt);

    Vec4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

void FUN_00978250(const StepInfo& stepInfo, const Vec4& pos1, const Quat4& rot1, MotionState& ms)
{
    SweptTrans& sweptTransform = ms.getSweptTransform();

    sweptTransform.m_centerOfMass0 = sweptTransform.m_centerOfMass1;
    sweptTransform.m_rotation0 = sweptTransform.m_rotation1;

    sweptTransform.m_centerOfMass1 = pos1;
    sweptTransform.m_rotation1 = rot1;

    Quat4 diff;
    diff.FUN_008db610(rot1, sweptTransform.m_rotation0);

    float angle = diff.FUN_008db810();
    Vec4 axis;
    if (diff.hasValidAxis())
    {
        diff.FUN_008db880(axis);
    }
    else
    {
        axis.setZero4();
    }

    ms.m_deltaAngle.setMul4(angle, axis);
    ms.m_deltaAngle(3) = angle;

    sweptTransform.m_centerOfMass0(3) = stepInfo.m_startTime;
    sweptTransform.m_centerOfMass1(3) = stepInfo.m_invDeltaTime;

    calcTransAtT1(sweptTransform, ms.getTransform());
}
}   // namespace f3m_00978250

// @f3 0x0096fbc0 (community match, verified in this file)
#include <math.h>
namespace f3m_0096fbc0 {

class Vec4f
{
public:
    __forceinline void set(float a, float b, float c, float d = 0.0f);
    __forceinline void setSub4(const Vec4f& a, const Vec4f& b);
    __forceinline void setCross(const Vec4f& a, const Vec4f& b);
    __forceinline float dot3(const Vec4f& a) const;
    __forceinline float length3() const;
    __forceinline float lengthSquared3() const;
    __forceinline float& operator()(int i);
    __forceinline const float& operator()(int i) const;

private:
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

inline float& Vec4f::operator()(int i)
{
    return (&x)[i];
}

inline const float& Vec4f::operator()(int i) const
{
    return (&x)[i];
}

inline void Vec4f::set(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

inline void Vec4f::setSub4(const Vec4f& v0, const Vec4f& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

inline void Vec4f::setCross(const Vec4f& v1, const Vec4f& v2)
{
    const float nx = v1(1) * v2(2) - v1(2) * v2(1);
    const float ny = v1(2) * v2(0) - v1(0) * v2(2);
    const float nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

inline float Vec4f::dot3(const Vec4f& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

inline float Vec4f::length3() const
{
    return sqrtf((x * x) + (y * y) + (z * z));
}

inline float Vec4f::lengthSquared3() const
{
    return this->dot3(*this);
}

struct TriCache
{
    float m_QQ;
    float m_RR;
    float m_QR;
    float m_invTriNormal;
};

// pdb: hkpCollideTriangleUtil::setupClosestPointTriangleCache | hkpCollideTriangleUtil.obj | fnv360_0822_debug, objrun_prop, low
// pdb params: tri, cache
void __cdecl FUN_0096fbc0(const Vec4f* tri, TriCache& cache)
{
    Vec4f Q;
    Q.setSub4(tri[0], tri[1]);
    Vec4f R;
    R.setSub4(tri[2], tri[1]);

    const float QQ = Q.lengthSquared3();
    const float RR = R.lengthSquared3();
    const float QR = R.dot3(Q);

    float QQRR = QQ * RR;
    float QRQR = QR * QR;
    float Det = (QQRR - QRQR);

    float invDet = 1.0f / Det;

    cache.m_QQ = QQ * invDet;
    cache.m_RR = RR * invDet;
    cache.m_QR = QR * invDet;

    Vec4f triNormal;
    triNormal.setCross(Q, R);
    float len = triNormal.length3();

    cache.m_invTriNormal = 1.0f / len;
}
}   // namespace f3m_0096fbc0

// @f3 0x0096e0d0 (community match, verified in this file)
#include <math.h>
namespace f3m_0096e0d0 {

__forceinline float sqrtInverse(float r)
{
    return 1.0f / sqrtf(r);
}

struct CapVec
{
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;

    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline float operator()(int i) const { return (&x)[i]; }

    __forceinline void set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    __forceinline void setZero4()
    {
        x = y = z = w = 0;
    }

    __forceinline void operator=(const CapVec& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline void setSub4(const CapVec& v0, const CapVec& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void setCross(const CapVec& v1, const CapVec& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    __forceinline void setNeg4(const CapVec& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }

    __forceinline float dot3(const CapVec& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

    __forceinline float lengthSquared3() const
    {
        return this->dot3(*this);
    }

    __forceinline void mul4(float rs)
    {
        float s = float(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }

    __forceinline float lengthInverse3() const
    {
        float l2 = (x * x) + (y * y) + (z * z);
        return l2 ? sqrtInverse(l2) : 0;
    }

    __forceinline void normalize3()
    {
        this->mul4(this->lengthInverse3());
    }

    __forceinline void setAddMul4(const CapVec& a, const CapVec& b, float r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
};

struct CapSegResult
{
    CapVec closestPointA;
    CapVec closestAminusClosestB;
    float distanceSquared;
};

struct CapContact
{
    CapVec position;
    CapVec separatingNormal;

    __forceinline CapVec& getPosition() { return position; }
    __forceinline CapVec& getSeparatingNormal() { return separatingNormal; }
    __forceinline const CapVec& getNormal() const { return separatingNormal; }
    __forceinline void setDistance(float d) { separatingNormal(3) = d; }
};

extern "C" int __cdecl FUN_0096f780(const CapVec& A, const CapVec& dA, const CapVec& B, const CapVec& dB, CapSegResult& result);

__forceinline void calcPerp(const CapVec& vectorIn, CapVec& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    float a0 = fabsf(vectorIn(0));
    float a1 = fabsf(vectorIn(1));
    float a2 = fabsf(vectorIn(2));

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

// pdb: hkCollideCapsuleUtilClostestPointCapsVsCaps | hkpCollideCapsuleUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: capsA, capsARadius, capsB, capsBRadius, collisionTolerance, cpoint
extern "C" int __cdecl FUN_0096e0d0(const CapVec* capsA, float capsARadius, const CapVec* capsB, float capsBRadius,
                                    float collisionTolerance, CapContact& cpoint)
{
    CapVec dA;
    dA.setSub4(capsA[1], capsA[0]);

    CapVec dB;
    dB.setSub4(capsB[1], capsB[0]);

    CapSegResult result;
    int pointsNotUsed = FUN_0096f780(capsA[0], dA, capsB[0], dB, result);

    float radiusSum = capsARadius + capsBRadius;
    float refDist = radiusSum + collisionTolerance;

    if (result.distanceSquared > refDist * refDist)
    {
        return 1;
    }

    float dist = sqrtf(result.distanceSquared);

    if (pointsNotUsed)
    {
        if (result.distanceSquared > 0.0f)
        {
            cpoint.getSeparatingNormal() = result.closestAminusClosestB;
            goto normalize;
        }
    }
    else
    {
        CapVec altNormal;
        altNormal.setCross(dA, dB);
        float altNormLen2 = altNormal.lengthSquared3();
        if (altNormLen2 > 1.19209290e-07f)
        {
            if (altNormal.dot3(result.closestAminusClosestB) < 0.0f)
            {
                altNormal.setNeg4(altNormal);
            }
            cpoint.getSeparatingNormal() = altNormal;
            goto normalize;
        }
    }

    calcPerp(dA, cpoint.getSeparatingNormal());

normalize:
    cpoint.getSeparatingNormal().normalize3();
    float shift = capsBRadius - dist;
    cpoint.getPosition().setAddMul4(result.closestPointA, cpoint.getNormal(), shift);
    cpoint.setDistance(dist - radiusSum);
    return 0;
}
}   // namespace f3m_0096e0d0

// @f3 0x0097f560 (community match, verified in this file)
extern double DAT_00db38b0;
namespace f3m_0097f560 {


struct FNV0097f560Vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct FNV0097f560Pt3 {
    float x;
    float y;
    float z;
};

struct FNV0097f560Xform {
    FNV0097f560Vec4 col0;
    FNV0097f560Vec4 col1;
    FNV0097f560Vec4 col2;
    FNV0097f560Vec4 trans;

    void __thiscall hkRotation_set(int value);
};

struct FNV0097f560Object {
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
    FNV0097f560Xform xform;   // 0xe0
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    FNV0097f560Vec4 pos;      // 0x130
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    FNV0097f560Pt3 pt;        // 0x160
};

// pdb: setRotationAroundCentreOfMass | hkpSimulation.obj | fnv360_0822_debug, objrun + skyrim(objrun), high
static __declspec(noinline) void setRotationAroundCentreOfMass(FNV0097f560Object* obj, int value) {
    FNV0097f560Xform* t = &obj->xform;
    t->hkRotation_set(value);
    float x = obj->pt.x;
    float y = obj->pt.y;
    float z = obj->pt.z;
    __declspec(align(16)) FNV0097f560Vec4 r;
    r.x = t->col1.x * y + t->col0.x * x + t->col2.x * z;
    r.y = t->col1.y * y + t->col0.y * x + t->col2.y * z;
    r.z = t->col1.z * y + t->col0.z * x + t->col2.z * z;
    t->trans.x = obj->pos.x - r.x;
    t->trans.y = obj->pos.y - r.y;
    t->trans.z = obj->pos.z - r.z;
    t->trans.w = obj->pos.w - DAT_00db38b0;
}

volatile int g_in0097f560;
FNV0097f560Object* volatile g_obj0097f560;
void caller_of_FUN_0097f560() { setRotationAroundCentreOfMass(g_obj0097f560, g_in0097f560); }
}   // namespace f3m_0097f560

// @f3 0x00969f70 (community match, verified in this file)
namespace f3m_00969f70 {
namespace w969f70 {
struct Vector { __declspec(align(16)) float x; float y,z,w; };
struct Item { float x,y,z,unk0c,dx,dy,dz,unk1c; int unk20,type; };
struct QBool { char v; QBool(bool b) : v(b) {} };
QBool __stdcall FUN_00969f70(const Item* a,const Item* b) {
 if(a->type==1 && b->type!=1) {
  Vector delta; delta.x=a->x-b->x; delta.y=a->y-b->y; delta.z=a->z-b->z;
  float dot=a->dy*delta.y+a->dx*delta.x+a->dz*delta.z;
  if(dot > 0.0f) return true;
 }
 return false;
}
}
}   // namespace f3m_00969f70

// @f3 0x00971fc0 (community match, verified in this file)
extern const float DAT_00de6e60, DAT_00de731c;
extern const double DAT_00db7de8;
namespace f3m_00971fc0 {
namespace Bounds463
{

struct __declspec(align(16)) Vector
{
    float x, y, z, w;
};

void __cdecl FUN_00971fc0(const Vector* points, int count, Vector* center, Vector* span)
{
    center->x = center->y = center->z = center->w = 0.0f;
    span->x = span->y = span->z = span->w = 0.0f;
    Vector low, high;
    low.x = DAT_00de6e60;
    low.y = DAT_00de6e60;
    low.z = DAT_00de6e60;
    low.w = DAT_00de6e60;
    high.x = DAT_00de731c;
    high.y = DAT_00de731c;
    high.z = DAT_00de731c;
    high.w = DAT_00de731c;
    for (int i = 0; i < count; ++i)
    {
        const Vector& point = points[i];
        if (point.x < low.x) low.x = point.x;
        if (point.y < low.y) low.y = point.y;
        if (point.z < low.z) low.z = point.z;
        if (point.w < low.w) low.w = point.w;
        if (point.x > high.x) high.x = point.x;
        if (point.y > high.y) high.y = point.y;
        if (point.z > high.z) high.z = point.z;
        if (point.w > high.w) high.w = point.w;
    }
    if (count)
    {
        const double half = 0.5;
        center->x = (float)(high.x * half + low.x * half);
        const double minY = *(volatile float*)&low.y;
        const double minYHalf = minY * half;
        center->y = (float)(minYHalf + *(volatile float*)&high.y * half);
        center->z = (float)(high.z * half + low.z * half);
        center->w = (float)(high.w * half + low.w * half);
        span->x = high.x - low.x;
        span->y = (float)(high.y - minY);
        span->z = high.z - low.z;
        span->w = high.w - low.w;
    }
}
}








}   // namespace f3m_00971fc0

// @f3 0x0096c5a0 (community match, verified in this file)
#include <math.h>
namespace f3m_0096c5a0 {

struct HBool {
    char m;
    HBool(bool b) { m = (char)b; }
};

struct V4 {
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;

    __forceinline int eq3(const V4& o, float eps) const {
        V4 t;
        t.x = x - o.x;
        t.y = y - o.y;
        t.z = z - o.z;
        t.w = w - o.w;
        t.x = fabsf(t.x);
        t.y = fabsf(t.y);
        t.z = fabsf(t.z);
        t.w = fabsf(t.w);
        V4 e;
        e.x = eps;
        e.y = eps;
        e.z = eps;
        e.w = eps;
        int mask =
            ((t.x <= e.x) ? 8 : 0) |
            ((t.y <= e.y) ? 4 : 0) |
            ((t.z <= e.z) ? 2 : 0) |
            ((t.w <= e.w) ? 1 : 0);
        return (mask & 14) == 14;
    }
};

struct M3 {
    V4 c0;
    V4 c1;
    V4 c2;
    __forceinline const V4& col(int i) const { return (&c0)[i]; }
    HBool FUN_0096c5a0(const M3& m, float eps) const;
};

HBool M3::FUN_0096c5a0(const M3& m, float eps) const {
    return HBool(c0.eq3(m.col(0), eps) && c1.eq3(m.col(1), eps) && c2.eq3(m.col(2), eps));
}
}   // namespace f3m_0096c5a0

// @f3 0x0096c8f0 (community match, verified in this file)
#include <math.h>
namespace f3m_0096c8f0 {

template <typename T>
FNV_FORCEINLINE void Swap_96c8f0(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}

class Vec4_96c8f0
{
public:
    FNV_FORCEINLINE Vec4_96c8f0() {}

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

    FNV_FORCEINLINE void setMul4(float rs, const Vec4_96c8f0& a)
    {
        float r = float(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }

    FNV_FORCEINLINE void setCross(const Vec4_96c8f0& v1, const Vec4_96c8f0& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    FNV_FORCEINLINE float dot3(const Vec4_96c8f0& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

private:
    FNV_ALIGN(16) float x;
    float y;
    float z;
    float w;
};

class Mat3_96c8f0
{
public:
    FNV_FORCEINLINE Vec4_96c8f0& getColumn(int x)
    {
        return (&m_col0)[x];
    }

    FNV_FORCEINLINE const Vec4_96c8f0& getColumn(int x) const
    {
        return (&m_col0)[x];
    }

    FNV_FORCEINLINE float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }

    int FUN_0096c8f0(float epsilon);

protected:
    Vec4_96c8f0 m_col0;
    Vec4_96c8f0 m_col1;
    Vec4_96c8f0 m_col2;
};

// pdb: hkpRigidBody::setLinearVelocity | TESObjectREFR.obj | fnv360_0822_debug, call_gap, low, conflict (skyrim: hkMatrix3::invert)
// pdb params: newVel
int Mat3_96c8f0::FUN_0096c8f0(float epsilon)
{
    Vec4_96c8f0 r0; r0.setCross(getColumn(1), getColumn(2));
    Vec4_96c8f0 r1; r1.setCross(getColumn(2), getColumn(0));
    Vec4_96c8f0 r2; r2.setCross(getColumn(0), getColumn(1));

    float determinant = getColumn(0).dot3(r0);

    if (::fabsf(determinant) > epsilon * epsilon * epsilon)
    {
        float dinv = 1.0f / determinant;
        getColumn(0).setMul4(dinv, r0);
        getColumn(1).setMul4(dinv, r1);
        getColumn(2).setMul4(dinv, r2);
        Mat3_96c8f0& m = *this;
        Swap_96c8f0(m(0, 1), m(1, 0));
        Swap_96c8f0(m(0, 2), m(2, 0));
        Swap_96c8f0(m(1, 2), m(2, 1));
        return 0;
    }
    else
    {
        return 1;
    }
}
}   // namespace f3m_0096c8f0

// @f3 0x00970aa0 (community match, verified in this file)
namespace f3m_00970aa0 {

struct __declspec(align(16)) V { float x, y, z, w; };

inline V operator+(const V& a, const V& b)
{
    V r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

inline V operator+(const V& a, float s)
{
    V r;
    r.x = a.x + s;
    r.y = a.y + s;
    r.z = a.z + s;
    r.w = a.w + s;
    return r;
}

struct P { char pad00[0x30]; V v30; };

struct C {
    char pad00[0x20];
    V v20;
    V v30;
    void FUN_00970aa0(P* p, float s, V* out);
};

// pdb: hkCharControllerShape::`scalar deleting destructor' | bhkCharControllerShape.obj | fnv360_0822_debug, objopen_prop, low
void C::FUN_00970aa0(P* p, float s, V* out)
{
    V a = this->v30 + p->v30;
    V b = this->v20 + s;

    out[0].x = a.x - b.x;
    out[0].y = a.y - b.y;
    out[0].z = a.z - b.z;
    out[0].w = a.w - b.w;

    out[1].x = a.x + b.x;
    out[1].y = a.y + b.y;
    out[1].z = a.z + b.z;
    out[1].w = a.w + b.w;
}
}   // namespace f3m_00970aa0

// @f3 0x00960c70 (community match, verified in this file)
namespace f3m_00960c70 {

__forceinline void accum(float& d, float r, float m) { d += r * m; }

struct F3Quat;

__declspec(align(16)) struct F3Vec4 {
    float x;
    float y;
    float z;
    float w;

    void setZero4() {
        x = y = z = w = 0.0f;
    }
    void setAll(float a) {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    void setAdd4(const F3Vec4& a, const F3Vec4& b) {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    void setMul4(const F3Vec4& a, const F3Vec4& b) {
        const float* p = &a.x;
        const float* q = &b.x;
        x = p[0] * q[0];
        y = p[1] * q[1];
        z = p[2] * q[2];
        w = p[3] * q[3];
    }
    void setMul4(float r, const F3Vec4& a) {
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    void addMul4(float r, const F3Vec4& a) {
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    void setCross(const F3Vec4& v1, const F3Vec4& v2) {
        float nx = v1.y * v2.z - v1.z * v2.y;
        float ny = v1.z * v2.x - v1.x * v2.z;
        float nz = v1.x * v2.y - v1.y * v2.x;
        x = nx;
        y = ny;
        z = nz;
        w = 0.0f;
    }
    float dot3(const F3Vec4& a) const {
        const float* p = &x;
        const float* q = &a.x;
        return (p[0] * q[0]) + (p[1] * q[1]) + (p[2] * q[2]);
    }
    void setRotatedDir(const F3Quat& quat, const F3Vec4& direction);
};

struct F3Quat {
    F3Vec4 v;
    void setIdentity() {
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        v.w = 1.0f;
    }
    void FUN_008d3290(const F3Quat& a, const F3Quat& b);
};

struct F3Qs {
    F3Vec4 translation;
    F3Quat rotation;
    F3Vec4 scale;
    __forceinline void setIdentity() {
        translation.setZero4();
        rotation.setIdentity();
        scale.setAll(1.0f);
    }
    __forceinline void setMul(const F3Qs& aTb, const F3Qs& bTc) {
        F3Vec4 extraTrans;
        extraTrans.setRotatedDir(aTb.rotation, bTc.translation);
        translation.setAdd4(aTb.translation, extraTrans);
        rotation.FUN_008d3290(aTb.rotation, bTc.rotation);
        scale.setMul4(aTb.scale, bTc.scale);
    }
    void FUN_009643d0(int* src);
};

__forceinline void F3Vec4::setRotatedDir(const F3Quat& quat, const F3Vec4& direction) {
    float qreal = quat.v.w;
    float q2minus1 = qreal * qreal - 0.5f;
    F3Vec4 ret;
    ret.setMul4(q2minus1, direction);
    float imagDotDir = quat.v.dot3(direction);
    ret.addMul4(imagDotDir, quat.v);
    F3Vec4 imagCrossDir;
    imagCrossDir.setCross(quat.v, direction);
    accum(ret.x, qreal, imagCrossDir.x);
    accum(ret.y, qreal, imagCrossDir.y);
    accum(ret.z, qreal, imagCrossDir.z);
    accum(ret.w, qreal, imagCrossDir.w);
    setAdd4(ret, ret);
}

struct F3Node {
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
    int atE0;
};

struct F3Skin {
    int unk00;
    short* parents;
    int unk08;
    int unk0C;
    int count;
    F3Qs* bones;
};

extern "C" void __cdecl FUN_00957fb0(F3Skin* skin, F3Qs* bones, int index, F3Vec4* scaleOut);

__forceinline void copyQs(F3Qs& dst, const F3Qs& s) {
    dst.translation.x = s.translation.x;
    dst.translation.y = s.translation.y;
    dst.translation.z = s.translation.z;
    dst.translation.w = s.translation.w;
    dst.rotation.v.x = s.rotation.v.x;
    dst.rotation.v.y = s.rotation.v.y;
    dst.rotation.v.z = s.rotation.v.z;
    dst.rotation.v.w = s.rotation.v.w;
    dst.scale.x = s.scale.x;
    dst.scale.y = s.scale.y;
    dst.scale.z = s.scale.z;
    dst.scale.w = s.scale.w;
}

FNV_STATIC_ASSERT(sizeof(F3Vec4) == 16);
FNV_STATIC_ASSERT(sizeof(F3Quat) == 16);
FNV_STATIC_ASSERT(sizeof(F3Qs) == 48);

struct F3Owner {
    int unk00;
    int unk04;
    F3Node** nodes;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* ids;
    int unk24;
    int unk28;
    F3Skin* skin;
    void FUN_00960c70(F3Qs* poses);
};

void F3Owner::FUN_00960c70(F3Qs* poses) {
    for (int i = 0; i < skin->count; ++i) {
        int id = ids[i];
        if (id >= 0) {
            F3Node* node = nodes[id];
            if (node) {
                poses[i].FUN_009643d0(&node->atE0);
                FUN_00957fb0(skin, skin->bones, i, &poses[i].scale);
                continue;
            }
        }
        F3Qs src;
        int parent = skin->parents[i];
        if (parent >= 0)
            copyQs(src, poses[parent]);
        else
            src.setIdentity();
        poses[i].setMul(src, skin->bones[i]);
    }
}
}   // namespace f3m_00960c70

// @f3 0x00972930 (community match, verified in this file)
namespace f3m_00972930 {
struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;

    hkVector4() {}
    hkVector4(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void setZero4()
    {
        x = y = z = w = 0.0f;
    }
    void addMul4(float r, const hkVector4& a)
    {
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    void setMul4(float r, const hkVector4& a)
    {
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    void mul4(float r)
    {
        x *= r;
        y *= r;
        z *= r;
        w *= r;
    }
    void sub4(const hkVector4& a)
    {
        x = x - a.x;
        y = y - a.y;
        z = z - a.z;
        w = w - a.w;
    }
    void setTransformedPos(const void* transform, const hkVector4& pos);
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    void setZero()
    {
        m_col0.x = 0.0f; m_col0.y = 0.0f; m_col0.z = 0.0f; m_col0.w = 0.0f;
        m_col1.x = 0.0f; m_col1.y = 0.0f; m_col1.z = 0.0f; m_col1.w = 0.0f;
        m_col2.x = 0.0f; m_col2.y = 0.0f; m_col2.z = 0.0f; m_col2.w = 0.0f;
    }
    void changeBasis(const void* rotation);
    void add(const hkMatrix3& a);
};

struct hkTransform
{
    hkMatrix3 m_rotation;
    hkVector4 m_translation;
};

struct hkpMassProperties
{
    float m_volume;
    float m_mass;
    int unk08;
    int unk0c;
    hkVector4 m_centerOfMass;
    hkMatrix3 m_inertiaTensor;
};

struct hkpMassElement
{
    hkpMassProperties m_properties;
    hkTransform m_transform;
};

struct hkMassElementArray
{
    hkpMassElement* m_data;
    int m_size;
};

void __cdecl AddInertiaTensor(hkVector4* shift, float mass, hkMatrix3* inertia);

// pdb: hkInertiaTensorComputer::combineMassProperties | hkInertiaTensorComputer.obj | tesv_win, call_gap_sim, low
int __cdecl FUN_00972930(hkMassElementArray* elements, hkpMassProperties* result)
{
    hkVector4 groupCenterOfMass;
    groupCenterOfMass.setZero4();
    float groupMass = 0.0f;
    float groupVolume = 0.0f;
    for (int i = 0; i < elements->m_size; i++)
    {
        hkVector4 centerOfMassWorld;
        centerOfMassWorld.setTransformedPos(&elements->m_data[i].m_transform,
                                            elements->m_data[i].m_properties.m_centerOfMass);
        groupCenterOfMass.addMul4(elements->m_data[i].m_properties.m_mass, centerOfMassWorld);
        groupMass += elements->m_data[i].m_properties.m_mass;
        float volume = elements->m_data[i].m_properties.m_volume;
        groupVolume += volume;
    }
    if (groupMass <= 0.0f)
        return 1;
    groupCenterOfMass.setMul4(1.0f / groupMass, groupCenterOfMass);
    result->m_centerOfMass = groupCenterOfMass;
    result->m_mass = groupMass;
    result->m_volume = groupVolume;
    result->m_inertiaTensor.setZero();
    for (int i = 0; i < elements->m_size; i++)
    {
        hkMatrix3 inertiaTensor = elements->m_data[i].m_properties.m_inertiaTensor;
        inertiaTensor.changeBasis(&elements->m_data[i].m_transform);
        hkVector4 shift;
        shift.setTransformedPos(&elements->m_data[i].m_transform, elements->m_data[i].m_properties.m_centerOfMass);
        shift.sub4(groupCenterOfMass);
        AddInertiaTensor(&shift, elements->m_data[i].m_properties.m_mass, &inertiaTensor);
        result->m_inertiaTensor.add(inertiaTensor);
    }
    return 0;
}
}   // namespace f3m_00972930

// @f3 0x00975d50 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00975d50 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;

    hkVector4() {}
    __forceinline hkVector4(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setZero4()
    {
        x = y = z = w = 0.0f;
    }
    void hkVector4_setTransformedPos(const void* transform, const hkVector4& pos) throw();
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline void setZero()
    {
        m_col0.x = 0.0f; m_col0.y = 0.0f; m_col0.z = 0.0f; m_col0.w = 0.0f;
        m_col1.x = 0.0f; m_col1.y = 0.0f; m_col1.z = 0.0f; m_col1.w = 0.0f;
        m_col2.x = 0.0f; m_col2.y = 0.0f; m_col2.z = 0.0f; m_col2.w = 0.0f;
    }
    __forceinline void setIdentity()
    {
        setZero();
        m_col0.x = 1.0f;
        m_col1.y = 1.0f;
        m_col2.z = 1.0f;
    }
    void FUN_0096cd10(float r) throw();
};

struct hkTransform
{
    hkMatrix3 m_rotation;
    hkVector4 m_translation;

    hkTransform() {}
    __forceinline hkTransform(const hkTransform& t) : m_rotation(t.m_rotation), m_translation(t.m_translation) {}
    hkTransform& FUN_008fda60(const hkTransform& t) throw();
    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_translation.setZero4();
    }
    void hkTransform_setMul(const hkTransform& a, const hkTransform& b) throw();
};

struct hkpMassPropertiesData
{
    float m_volume;
    float m_mass;
    hkVector4 m_centerOfMass;
    hkMatrix3 m_inertiaTensor;

    hkpMassPropertiesData& FUN_00976ae0(const hkpMassPropertiesData& o) throw();
};

struct hkpMassProperties : hkpMassPropertiesData
{
    __forceinline hkpMassProperties()
    {
        m_volume = 0.0f;
        m_mass = 0.0f;
        m_centerOfMass.setZero4();
        m_inertiaTensor.setZero();
    }
};

struct hkpMassElement
{
    hkpMassPropertiesData m_properties;
    hkTransform m_transform;

    void FUN_00976b60() throw();
    __forceinline hkpMassElement& operator=(const hkpMassElement& o)
    {
        m_properties.FUN_00976ae0(o.m_properties);
        m_transform.FUN_008fda60(o.m_transform);
        return *this;
    }
};

struct hkThreadMemory
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes) throw();
    virtual void onStackUnderflow(void* p) throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_current;
    int unk24;
    char* m_base;
    char* m_end;

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = nbytes & ~15;
        char* current = m_current;
        void* ret;
        if (current + nbytes <= m_end)
        {
            m_current = current + nbytes;
            ret = current;
        }
        else
        {
            ret = onStackOverflow(nbytes);
        }
        return ret;
    }
    __forceinline void deallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_base)
            onStackUnderflow(p);
    }
    void FUN_008f6d90(void* p, int size, int cls) throw();
};

void __cdecl FUN_00901f10(void* arr, int elemSize) throw();

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline ~hkArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int n = getCapacity();
            hkThreadMemory* mem = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, n * sizeof(T), 0x17);
        }
    }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline void pushBack(const T& e)
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_size++] = e;
    }
};

struct __declspec(align(16)) ShapeBuffer
{
    unsigned int data[128];
};

struct hkpShape;

struct hkpShapeContainer
{
    virtual void v00();
    virtual int getNumChildShapes() const throw();
    virtual unsigned int getFirstKey() const throw();
    virtual unsigned int getNextKey(unsigned int key) const throw();
    virtual unsigned int getCollisionFilterInfo(unsigned int key) const throw();
    virtual const hkpShape* getChildShape(unsigned int key, ShapeBuffer& buffer) const throw();
};

struct hkpShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const hkpShapeContainer* getContainer() const throw();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual int getNumCollisionSpheres() const throw();
    virtual const hkVector4* getCollisionSpheres(hkVector4* buffer) const throw();
    short m_memSizeAndFlags;
    short m_referenceCount;
    int m_userData;
    int m_type;
};

struct hkpBvTreeShape : hkpShape
{
};

struct hkpSingleShapeContainer
{
    void* vtbl;
    const hkpShape* m_childShape;
};

struct hkpConvexShape : hkpShape
{
    float m_radius;
};

struct hkpSphereShape
{
    void* m_vtbl;
    short m_memSizeAndFlags;
    short m_referenceCount;
    int m_userData;
    int m_type;
    float m_radius;
    int unk14;
    int unk18;
    int unk1c;
    void FUN_00970f60(float radius) throw();
};

struct hkpBoxShape : hkpConvexShape
{
    hkVector4 m_halfExtents;
};

struct hkpCapsuleShape : hkpConvexShape
{
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCylinderShape : hkpConvexShape
{
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    float FUN_009e5240() const throw();
};

struct hkpTriangleShape : hkpConvexShape
{
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpConvexTranslateShape : hkpConvexShape
{
    hkpSingleShapeContainer m_childShape;
    hkVector4 m_translation;
};

struct hkpConvexTransformShape : hkpConvexShape
{
    hkpSingleShapeContainer m_childShape;
    hkTransform m_transform;
};

struct hkpTransformShape : hkpShape
{
    hkpSingleShapeContainer m_childShape;
    hkVector4 m_rotation;
    hkTransform m_transform;
};

struct hkpMultiSphereShape : hkpShape
{
    int m_numSpheres;
    hkVector4 m_spheres[8];
};

void __cdecl FUN_00971390(float radius, float mass, hkpMassProperties& result) throw();
void __cdecl FUN_00971440(const hkVector4& halfExtents, float mass, hkpMassProperties& result) throw();
void __cdecl FUN_00973640(const hkVector4* verts, int striding, int numVerts, float mass, hkpMassProperties& result) throw();
void __cdecl FUN_00973c80(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, float mass, float radius, hkpMassProperties& result) throw();
void __cdecl FUN_00974950(const hkVector4& a, const hkVector4& b, float radius, float mass, hkpMassProperties& result) throw();
void __cdecl FUN_00975310(const hkVector4& a, const hkVector4& b, float radius, float mass, hkpMassProperties& result) throw();
int __cdecl FUN_00972930(hkArray<hkpMassElement>* elements, hkpMassProperties* result) throw();

static __declspec(noinline) void FUN_009717b0(hkpMassProperties& mp, float k)
{
    mp.m_mass *= k;
    mp.m_inertiaTensor.FUN_0096cd10(k);
}

// pdb: computeRecursiveShapeVolumeMassProperties | hkpInertiaTensorComputer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void __cdecl FUN_00975d50(const hkpShape* shape, const hkTransform& transform, hkpMassProperties& result)
{
    hkpMassProperties massProperties;
    int type = shape->m_type;
    switch (type)
    {
    case 2:
        FUN_00971390(((const hkpConvexShape*)shape)->m_radius, 1.0f, massProperties);
        break;
    case 5:
    {
        hkVector4 halfExtents = ((const hkpBoxShape*)shape)->m_halfExtents;
        FUN_00971440(halfExtents, 1.0f, massProperties);
        break;
    }
    case 7:
    {
        const hkpConvexShape* s = (const hkpConvexShape*)shape;
        int numSpheres = s->getNumCollisionSpheres();
        hkVector4* buffer = (hkVector4*)hkThreadMemory::getInstance().allocateStack((numSpheres + 1) * sizeof(hkVector4));
        const hkVector4* spheres = s->getCollisionSpheres(buffer);
        FUN_00973640(spheres, sizeof(hkVector4), numSpheres, 1.0f, massProperties);
        hkThreadMemory::getInstance().deallocateStack(buffer);
        break;
    }
    case 4:
    {
        const hkpTriangleShape* s = (const hkpTriangleShape*)shape;
        hkVector4 v0 = s->m_vertexA;
        hkVector4 v1 = s->m_vertexB;
        hkVector4 v2 = s->m_vertexC;
        FUN_00973c80(v0, v1, v2, 1.0f, s->m_radius, massProperties);
        break;
    }
    case 26:
        FUN_00975d50(((const hkpConvexTranslateShape*)shape)->m_childShape.m_childShape, transform, result);
        return;
    case 12:
    {
        const hkpConvexTranslateShape* s = (const hkpConvexTranslateShape*)shape;
        hkTransform local;
        local.m_rotation.setIdentity();
        local.m_translation = s->m_translation;
        hkTransform combined;
        combined.hkTransform_setMul(transform, local);
        FUN_00975d50(s->m_childShape.m_childShape, combined, result);
        return;
    }
    case 13:
    {
        const hkpConvexTransformShape* s = (const hkpConvexTransformShape*)shape;
        hkTransform combined;
        combined.hkTransform_setMul(transform, s->m_transform);
        FUN_00975d50(s->m_childShape.m_childShape, combined, result);
        return;
    }
    case 28:
    {
        const hkpTransformShape* s = (const hkpTransformShape*)shape;
        hkTransform combined;
        combined.hkTransform_setMul(transform, s->m_transform);
        FUN_00975d50(s->m_childShape.m_childShape, combined, result);
        return;
    }
    case 20:
    {
        const hkpMultiSphereShape* s = (const hkpMultiSphereShape*)shape;
        int i = 0;
        if (s->m_numSpheres > 0)
        {
            const hkVector4* sphereVec = s->m_spheres;
            do
            {
            hkVector4 c0 = transform.m_rotation.m_col0;
            hkVector4 c1 = transform.m_rotation.m_col1;
            hkVector4 c2 = transform.m_rotation.m_col2;
            hkVector4 tr = transform.m_translation;
            hkTransform t;
            t.m_rotation.m_col0 = c0;
            t.m_rotation.m_col1 = c1;
            t.m_rotation.m_col2 = c2;
            t.m_translation = tr;
            t.m_translation.hkVector4_setTransformedPos(&t, (*sphereVec));
            hkpSphereShape sphere;
            sphere.FUN_00970f60((*sphereVec).w);
            FUN_00975d50((const hkpShape*)&sphere, t, result);
            ++i;
            ++sphereVec;
            } while (i < s->m_numSpheres);
        }
        return;
    }
    case 8:
    case 9:
    case 10:
    case 11:
    case 15:
    case 21:
    case 22:
    {
        const hkpShapeContainer* container;
        if (type == 9 || type == 11)
            container = ((const hkpBvTreeShape*)shape)->getContainer();
        else
            container = shape->getContainer();
        ShapeBuffer buffer;
        for (unsigned int key = container->getFirstKey(); key != 0xffffffff; key = container->getNextKey(key))
        {
            const hkpShape* child = container->getChildShape(key, buffer);
            if (child)
                FUN_00975d50(child, transform, result);
        }
        return;
    }
    case 6:
    {
        const hkpCapsuleShape* s = (const hkpCapsuleShape*)shape;
        FUN_00974950(s->m_vertexA, s->m_vertexB, s->m_radius, 1.0f, massProperties);
        break;
    }
    case 3:
    {
        const hkpCylinderShape* s = (const hkpCylinderShape*)shape;
        FUN_00975310(s->m_vertexA, s->m_vertexB, s->FUN_009e5240(), 1.0f, massProperties);
        break;
    }
    case 27:
        goto done;
    default:
        return;
    }

    if (massProperties.m_volume != 0.0f)
    {
        FUN_009717b0(massProperties, massProperties.m_volume);
        hkArray<hkpMassElement> elements;
        {
            hkpMassElement massElement;
            massElement.FUN_00976b60();
            massElement.m_properties.FUN_00976ae0(result);
            elements.pushBack(massElement);
        }
        {
            hkpMassElement massElement;
            massElement.FUN_00976b60();
            massElement.m_properties.FUN_00976ae0(massProperties);
            massElement.m_transform.FUN_008fda60(transform);
            elements.pushBack(massElement);
        }
        FUN_00972930(&elements, &result);
    }
done:
    return;
}
}   // namespace f3m_00975d50

// @f3 0x0096b1c0 (community match, verified in this file)
extern float DAT_00e04660;
extern float DAT_00e09708;
namespace f3m_0096b1c0 {
namespace f3m_0096b1c0 {

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
    float dot3(const Vec4& o) const { return x * o.x + y * o.y + z * o.z; }
    void addMul4(const Vec4& a, float r) { x += a.x * r; y += a.y * r; z += a.z * r; w += a.w * r; }
    void addMul4(float r, const Vec4& a) { x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    void mul4(float r) { x = x * r; y = y * r; z = z * r; w = w * r; }
};

struct SolverInput {
    float f00;
    float unk04;
    float unk08;
    float unk0c;
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;
    Vec4 v40;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    float unk64;
    float unk68;
    float unk6c;
    Vec4 v70;
};

void __cdecl FUN_00a062a0(SolverInput* in, Vec4* out);

struct Body {
    int unk00; int unk04; int unk08; int unk0c;
    Vec4 v10;
};

struct Controller {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94();
    virtual Body* getBody();

    void FUN_008ea1f0(Vec4* out);
    void FUN_008e8900();

    char pad[0x310];
    Vec4 v320;
    int unk330; int unk334; int unk338; int unk33c;
    float f340;
    float f344;
    float f348;
    int unk34c;
    int state350;
    int unk354; int unk358; int unk35c;
    Vec4 v360;
    Vec4 v370;
    int unk380; int unk384;
    float f388;
    int unk38c;
    Vec4 v390;
    int unk3a0; int unk3a4; int unk3a8; int unk3ac;
    int unk3b0; int unk3b4; int unk3b8; int unk3bc;
    float f3c0;
    int unk3c4;
    float f3c8;
    int unk3cc; int unk3d0; int unk3d4;
    float f3d8;
};
}

// pdb: bhkCharacterStateProjectile::Update | bhkCharacterStateProjectile.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInput
void __stdcall FUN_0096b1c0(f3m_0096b1c0::Controller* c)
{
    using namespace f3m_0096b1c0;
    Vec4& v = c->v390;
    if (c->v390.x < -100000000.0f) {
        c->v390.x = 0.0f;
        SolverInput in;
        in.f00 = 1.0f;
        in.v10 = c->v370;
        in.v20 = c->v360;
        in.v30 = c->v360;
        in.v40 = v;
        in.f50 = c->f344;
        in.f54 = c->f340;
        in.f58 = c->f348;
        in.f5c = 0.0f;
        in.f60 = DAT_00e09708;
        in.v70 = c->v320;
        FUN_00a062a0(&in, &v);
    } else {
        SolverInput in;
        in.f00 = c->f3c0;
        in.v10 = c->v370;
        in.v20 = c->v360;
        in.v30 = c->v360;
        in.v40 = v;
        in.f50 = c->f344;
        in.f54 = c->f340;
        in.f58 = c->f348;
        in.f5c = 0.0f;
        in.f60 = DAT_00e09708;
        in.v70 = c->v320;
        FUN_00a062a0(&in, &v);
        float t = c->f3d8;
        if (t > 0.0f) {
            float d = c->v360.dot3(v);
            d = -d;
            v.addMul4(c->v360, d);
            float d2 = in.v40.dot3(c->v360);
            v.addMul4(c->v360, d2);
        }
        Vec4 pos;
        c->FUN_008ea1f0(&pos);
        if (pos.z > c->f3c8) {
            c->getBody();
            Vec4 vel = c->getBody()->v10;
            c->getBody();
            vel.mul4(t);
            v.addMul4(c->f388, vel);
        }
    }
    if (c->state350 != 0xb)
        c->FUN_008e8900();
}
}   // namespace f3m_0096b1c0

// @f3 0x00975790 (community match, verified in this file)
namespace f3m_00975790 {
static int clampCount(int n){if(n<0)return 0;return n;}

struct __declspec(align(16)) Vec4 { float x,y,z,w;
 Vec4() {} Vec4(const Vec4& p):x(p.x),y(p.y),z(p.z),w(p.w){} Vec4& operator=(const Vec4& p){x=p.x;y=p.y;z=p.z;w=p.w;return *this;} Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
};
struct __declspec(align(16)) V3 { float x,y,z;
 V3() {} V3(float a,float b,float c):x(a),y(b),z(c){}
 V3(const Vec4& p):x(p.x),y(p.y),z(p.z){}
 V3 operator-(const V3& b) const {V3 r;r.x=x-b.x;r.y=y-b.y;r.z=z-b.z;return r;}
 V3 cross(const V3& b)const {V3 r;r.x=y*b.z-z*b.y;r.y=z*b.x-x*b.z;r.z=x*b.y-y*b.x;return r;}
 float dot(const V3& b)const{return x*b.x+y*b.y+z*b.z;} float length()const {double a=x;double b=y;double c=z;float t=a*a+b*b+c*c;return (float)sqrt(t);}
};
struct Matrix {Vec4 r0,r1,r2;Matrix(){} Matrix(const Matrix& m):r0(m.r0),r1(m.r1),r2(m.r2){}void FUN_0096cc30(const Matrix*) throw();void clear(){r0.x=0.0f;r0.y=0.0f;r0.z=0.0f;r0.w=0.0f;r1.x=0.0f;r1.y=0.0f;r1.z=0.0f;r1.w=0.0f;r2.x=0.0f;r2.y=0.0f;r2.z=0.0f;r2.w=0.0f;}};
struct Properties {float volume,mass;Vec4 center;Matrix tensor;
 Properties(){mass=volume=0.0f;center.w=0.0f;center.z=0.0f;center.y=0.0f;center.x=0.0f;tensor.clear();}
};
struct Triangle {int a,b,c;};
struct Mesh {Vec4* vertices;int unk04,unk08;Triangle* triangles;int count;};
struct FloatArray;
extern "C" void __cdecl FUN_00901e90(FloatArray*,int,int);
struct Alloc {void FUN_008f6d90(void*,int,int);};
extern int DAT_010f3170;
extern Alloc* (__stdcall* DAT_00d9b080)(int);
struct FloatArray {float* data;int size,capacity;
 
 void resize(int n){if(n>(capacity&0x3fffffff))FUN_00901e90(this,n<0?0:n,4);size=n;}
 void release(){if(!(capacity&0x80000000)){int n=capacity&0x3fffffff;Alloc* a=DAT_00d9b080(DAT_010f3170);a->FUN_008f6d90(data,n*4,23);}}
};
extern const float DAT_00dbe0e0=1.0e-5f; extern const float DAT_00e7c950=5.0e-6f;
extern double DAT_00db7de8;
extern "C" void __cdecl FUN_00973c80(const Vec4*,const Vec4*,const Vec4*,float,float,Properties*);
extern "C" void __cdecl FUN_00971710(const Vec4*,float,Matrix*);
extern "C" void __cdecl FUN_00971660(Vec4*,float,Matrix*);
// pdb: hkpInertiaTensorComputer::computeGeometrySurfaceMassProperties | hkpInertiaTensorComputer.obj | fnv360_0822_retail, uconst, low, conflict (skyrim: hkInertiaTensorComputer::computeGeometrySurfaceMassProperties)
// pdb params: geom, surfaceThickness, distributeUniformly, mass, result
int __cdecl FUN_00975790(Mesh* mesh,float density,bool byArea,float mass,Properties* out){
 if(mass<=0.0f)return 1;
 if(density<=0.0f)return 1;
 Matrix* inertia=&out->tensor; inertia->clear(); Vec4* centerOut=&out->center; centerOut->w=0.0f;centerOut->z=0.0f;centerOut->y=0.0f;centerOut->x=0.0f;
 int count=mesh->count; FloatArray weights;weights.data=0;weights.size=0;weights.capacity=0x80000000;
 int cap=weights.capacity&0x3fffffff;
 if(cap<count){int newCap=clampCount(count);FUN_00901e90(&weights,newCap,4);} weights.size=count;
 float sum=0.0f;
 for(int i=0;i<mesh->count;++i){
 Triangle* tri=mesh->triangles+i;
 V3 a(mesh->vertices[tri->a]);V3 b(mesh->vertices[tri->b]);V3 c(mesh->vertices[tri->c]);
 V3 d=c-b;V3 e=a-b;V3 cross=d.cross(e);float length=cross.length();
 if(byArea){if(length<DAT_00dbe0e0)weights.data[i]=DAT_00e7c950;else weights.data[i]=(float)(length*DAT_00db7de8);}else weights.data[i]=1.0f;
 sum+=weights.data[i];
 }
 int j=0; if(j<mesh->count){int offset=0; do {
 const Triangle* __restrict tri=(const Triangle*)((char*)mesh->triangles+offset);
 Vec4 a;a=mesh->vertices[tri->a];Vec4 b;b=mesh->vertices[tri->b];Vec4 c;c=mesh->vertices[tri->c];
 float partMass=weights.data[j]*mass/sum;
 Properties part;FUN_00973c80(&a,&b,&c,partMass,density,&part);
 Matrix shifted=part.tensor;
 centerOut->x+=part.center.x*partMass;centerOut->y+=part.center.y*partMass;centerOut->z+=part.center.z*partMass;centerOut->w+=part.center.w*partMass;
 Vec4 center;center.x=part.center.x;center.y=part.center.y;center.z=part.center.z;center.w=part.center.w;FUN_00971710(&center,partMass,&shifted);inertia->FUN_0096cc30(&shifted);
 offset+=sizeof(Triangle); }while(++j<mesh->count); }
 out->mass=mass;float inverse=1.0f/mass;
 centerOut->x*=inverse;centerOut->y*=inverse;centerOut->z*=inverse;centerOut->w*=inverse;
 FUN_00971660(centerOut,mass,inertia);weights.release();return 0;
}
}   // namespace f3m_00975790

// @f3 0x00964800 (community match, verified in this file)
namespace f3m_00964800 {
struct Quat964800
{
    float x, y, z, w;
};
struct __declspec(align(16)) Matrix964800
{
    float r[3][4];
    void hkRotation_set(const Quat964800& q);
    void FUN_0096ce80(const Matrix964800& a, const Matrix964800& b);
};
struct __declspec(align(16)) Transform964800
{
    Matrix964800 m_rot;
    float m_t[4];
    void FUN_00924ed0(int arg);
};
struct Object964800
{
    float m_t[4];
    Quat964800 m_q;
    float m_sx;
    float m_sy;
    float m_sz;
    void FUN_00964800(int arg);
};
// pdb: hkQsTransform::get4x4ColumnMajor | hkQsTransform.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: d
void Object964800::FUN_00964800(int arg)
{
    Matrix964800 rot;
    rot.hkRotation_set(m_q);
    Matrix964800 sc;
    sc.r[0][0] = 0.0f; sc.r[0][1] = 0.0f; sc.r[0][2] = 0.0f; sc.r[0][3] = 0.0f;
    sc.r[1][0] = 0.0f; sc.r[1][1] = 0.0f; sc.r[1][2] = 0.0f; sc.r[1][3] = 0.0f;
    sc.r[2][0] = 0.0f; sc.r[2][1] = 0.0f; sc.r[2][2] = 0.0f; sc.r[2][3] = 0.0f;
    sc.r[0][0] = m_sx;
    sc.r[1][1] = m_sy;
    sc.r[2][2] = m_sz;
    Matrix964800 m;
    m.FUN_0096ce80(rot, sc);
    Transform964800 tr;
    tr.m_rot.r[0][0] = m.r[0][0]; tr.m_rot.r[0][1] = m.r[0][1]; tr.m_rot.r[0][2] = m.r[0][2]; tr.m_rot.r[0][3] = m.r[0][3];
    tr.m_rot.r[1][0] = m.r[1][0]; tr.m_rot.r[1][1] = m.r[1][1]; tr.m_rot.r[1][2] = m.r[1][2]; tr.m_rot.r[1][3] = m.r[1][3];
    tr.m_rot.r[2][0] = m.r[2][0]; tr.m_rot.r[2][1] = m.r[2][1]; tr.m_rot.r[2][2] = m.r[2][2]; tr.m_rot.r[2][3] = m.r[2][3];
    tr.m_t[0] = m_t[0]; tr.m_t[1] = m_t[1]; tr.m_t[2] = m_t[2]; tr.m_t[3] = m_t[3];
    tr.FUN_00924ed0(arg);
}
}   // namespace f3m_00964800

// @f3 0x00964930 (community match, verified in this file)
namespace f3m_00964930 {
struct hkBool964930
{
    char m_bool;
    hkBool964930(bool b)
    {
        m_bool = (char)b;
    }
};
struct Src964930;
struct __declspec(align(16)) Result964930
{
    float m[3][4];
    char unk30;
    char failed;
    char unk32;
    char unk33;
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
};
void __cdecl FUN_00a05900(const Src964930* s, Result964930* out);
struct __declspec(align(16)) Matrix964930
{
    float m[3][4];
    hkBool964930 hkQsTransform_set4x4ColumnMajor(const Src964930* s);
};
// pdb: hkQsTransform::set4x4ColumnMajor | hkQsTransform.obj | fnv360_0822_debug, objrun + skyrim(objrun), high
hkBool964930 Matrix964930::hkQsTransform_set4x4ColumnMajor(const Src964930* s)
{
    Result964930 r;
    FUN_00a05900(s, &r);
    m[0][0] = r.m[0][0];
    m[0][1] = r.m[0][1];
    m[0][2] = r.m[0][2];
    m[0][3] = r.m[0][3];
    m[1][0] = r.m[1][0];
    m[1][1] = r.m[1][1];
    m[1][2] = r.m[1][2];
    m[1][3] = r.m[1][3];
    m[2][0] = r.m[2][0];
    m[2][1] = r.m[2][1];
    m[2][2] = r.m[2][2];
    m[2][3] = r.m[2][3];
    return hkBool964930(r.failed == 0);
}
}   // namespace f3m_00964930

// @f3 0x00979060 (community match, verified in this file)
#include <new>
namespace f3m_00979060 {
namespace NativeClone979060 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
struct hkThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    static hkThreadMemory* getInstance() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};

template <class T> __forceinline void _copy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
        dst[i] = src[i];
}
template <class T> struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    __forceinline hkArray& operator=(const hkArray& a) {
        if (getCapacity() < a.size) {
            if ((capacityAndFlags & 0x80000000) == 0)
                hkThreadMemory::getInstance()->FUN_008f6d90(data, getCapacity() * sizeof(T), 0x17);
            data = (T*)hkThreadMemory::getInstance()->FUN_008f6d30(a.size * sizeof(T), 0x17);
            capacityAndFlags = (capacityAndFlags & 0x40000000) | a.size;
        }
        size = a.size;
        _copy(data, a.data, size);
        return *this;
    }
};

class FUN_00978f10 {
public:
    static void* operator new(unsigned int n) throw() {
        void* p = hkThreadMemory::getInstance()->FUN_008f6d30(n, 0x31);
        ((unsigned short*)p)[2] = (unsigned short)n;
        return p;
    }
    FUN_00978f10(void* info, int mode) throw();

    void* vtbl;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08, unk0c;
    int unk10;
    int unk14, unk18, unk1c, unk20, unk24, unk28;
    int unk2C;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    hkArray<void*> arr80;
    hkArray<void*> arr8C;
    int unk98, unk9c;
    struct ConstructionData {
        unsigned int unk00, unk04, unk08, unk0c;
        unsigned int unk10, unk14, unk18, unk1c;
        unsigned int unk20, unk24, unk28, unk2c;
    } info;

    void FUN_0090d960(FUN_00978f10* other) throw();
    FUN_00978f10* FUN_00979060();
};

// pdb: hkpAabbPhantom::clone | hkpAabbPhantom.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00978f10* FUN_00978f10::FUN_00979060()
{
    void* storage = FUN_00978f10::operator new(sizeof(FUN_00978f10));
    const int mode = unk2C;
    FUN_00978f10* copy = ::new (storage) FUN_00978f10(&info, mode);
    copy->arr80 = arr80;
    copy->arr8C = arr8C;
    copy->FUN_0090d960(this);
    return copy;
}
}

}   // namespace f3m_00979060

// @f3 0x00978440 (community match, verified in this file)
namespace f3m_00978440 {
struct Point3 { float x, y, z; };
struct Vector4Init { float x, y, z, w; };
struct SweptTransformInit {
    Vector4Init fromPosition, toPosition, fromRotation, toRotation, centerOfMass;
    void hkSweptTransform_initSweptTransform(const Point3& position, const Vector4Init& rotation);
};

// pdb: hkSweptTransform::initSweptTransform | hkSweptTransform.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void SweptTransformInit::hkSweptTransform_initSweptTransform(const Point3& position, const Vector4Init& rotation)
{
    fromPosition.x = position.x;
    fromPosition.y = position.y;
    fromPosition.z = position.z;
    fromPosition.w = 0.0f;
    toPosition.x = position.x;
    toPosition.y = position.y;
    toPosition.z = position.z;
    toPosition.w = 0.0f;
    fromRotation.x = rotation.x;
    fromRotation.y = rotation.y;
    fromRotation.z = rotation.z;
    fromRotation.w = rotation.w;
    toRotation.x = rotation.x;
    toRotation.y = rotation.y;
    toRotation.z = rotation.z;
    toRotation.w = rotation.w;
    centerOfMass.x = centerOfMass.y = centerOfMass.z = centerOfMass.w = 0.0f;
}
}   // namespace f3m_00978440

// @f3 0x00969d20 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00969d20 {
struct F3Pair {
    unsigned int first;
    unsigned int second;
};
struct F3Heap {
    void* FUN_008f6d30(unsigned int bytes, unsigned int tag);
    void FUN_008f6d90(void* block, unsigned int bytes, unsigned int tag);
};
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);
FNV_FORCEINLINE void F3CopyPairs(F3Pair* destination, unsigned int sourceOffset, int remaining) {
    do {
        *destination = *(const F3Pair*)((unsigned int)destination + sourceOffset);
        ++destination;
    } while (--remaining);
}
struct F3PairArray {
    F3Pair* data;
    int count;
    unsigned int capacityAndFlags;
    F3PairArray() : data(0), count(0), capacityAndFlags(0x80000000u) {}
    FNV_FORCEINLINE void Reset() { data = 0; count = 0; capacityAndFlags = 0x80000000u; }
    FNV_FORCEINLINE void CopyFrom(const F3PairArray& source) {
        int oldCapacity = capacityAndFlags & 0x3fffffffu;
        if (oldCapacity < source.count) {
            if (!(capacityAndFlags & 0x80000000u))
                { F3Heap* heap = static_cast<F3Heap*>(FUN_00d9b080(DAT_010f3170)); heap->FUN_008f6d90(data, oldCapacity * 8, 0x17); }
            F3Heap* heap2 = static_cast<F3Heap*>(FUN_00d9b080(DAT_010f3170));
            data = (F3Pair*)heap2->FUN_008f6d30(source.count * 8, 0x17);
            capacityAndFlags = (capacityAndFlags & 0x40000000u) | source.count;
        }
        int remaining = source.count;
        F3Pair* dst = data;
        count = remaining;
        const F3Pair* from = source.data;
        if (remaining > 0) {
            F3CopyPairs(dst, (unsigned int)from - (unsigned int)dst, remaining);
        }
    }
};
struct F3Container {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float unk0c;
    F3PairArray first;
    F3PairArray second;
    F3PairArray third;
    unsigned char unk34;
    unsigned char unk35;
    F3Container* FUN_00969d20(const F3Container* other);
};
// pdb: hkaSkeletonMapperUtils::Params::Params | hkaSkeletonMapperUtils.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: other
F3Container* F3Container::FUN_00969d20(const F3Container* other) {
    unk00 = other->unk00;
    unk04 = other->unk04;
    unk08 = other->unk08;
    unk0c = other->unk0c;
    first.Reset();
    second.Reset();
    third.Reset();
    unk34 = other->unk34;
    unk35 = other->unk35;
    first.CopyFrom(other->first);
    second.CopyFrom(other->second);
    third.CopyFrom(other->third);
    return this;
}
}   // namespace f3m_00969d20

// @f3 0x009643d0 (community match, verified in this file)
namespace f3m_009643d0 {
namespace Copy9643d0 {
struct Input {int unk00;
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
float x,y,z,w;};
struct Subobject {int unk00,unk04,unk08,unk0c;void FUN_00924360(Input*);};
struct Words {unsigned x,y,z,w;};extern Words DAT_00e375a0;
struct Object {float x,y,z,w;Subobject sub;Words defaults;void FUN_009643d0(Input*);};
// pdb: hkStringPtr::~hkStringPtr | hkStringPtr.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkQsTransform::setFromTransformNoScale)
void Object::FUN_009643d0(Input* input){sub.FUN_00924360(input);x=input->x;y=input->y;z=input->z;w=input->w;defaults=DAT_00e375a0;}
}
}   // namespace f3m_009643d0

// @f3 0x0096ad60 (community match, verified in this file)
namespace f3m_0096ad60 {
namespace Hit302 {
struct Node {int unk00,value,unk08;Node* parent;Node* root(){Node* p=this;while(p->parent)p=p->parent;return p;}};
struct Vec {float x,y,z,w;void copy(const Vec& a){x=a.x;y=a.y;z=a.z;w=a.w;}};struct Input {Vec a,b;Node* left;Node* right;};
struct Object {int unk00;float distance;int unk08,unk0c;Vec a,b;Node* left;int leftValue;Node* right;int rightValue;void FUN_0096ad60(Input*);};
void Object::FUN_0096ad60(Input* input){if(!left||input->b.w<b.w){a.copy(input->a);b.copy(input->b);left=input->left->root();leftValue=input->left->value;right=input->right->root();rightValue=input->right->value;distance=input->b.w;}}
}

}   // namespace f3m_0096ad60

// @f3 0x00970ed0 (community match, verified in this file)
namespace f3m_00970ed0 {
namespace Aabb970ed0 {
struct __declspec(align(16)) Scalar {float x,y,z,value;};struct Vec4 {float x,y,z,w;};
struct Transform {Vec4 first,second,third,position;};struct Aabb {Vec4 minimum,maximum;};
struct Object {int unk00,unk04,unk08,unk0c;float radius;void FUN_00970ed0(Transform*,float,Aabb*);};
// pdb: hkpSphereShape::getAabbImpl | hkpSphereShape.obj | tesv_win, objopen_prop, low
void Object::FUN_00970ed0(Transform* t,float tolerance,Aabb* output){Scalar r;r.x=r.y=r.z=r.value=radius+tolerance;output->minimum.x=t->position.x-r.value;output->minimum.y=t->position.y-r.value;output->minimum.z=t->position.z-r.value;output->minimum.w=t->position.w-r.value;output->maximum.x=t->position.x+r.value;output->maximum.y=t->position.y+r.value;output->maximum.z=t->position.z+r.value;output->maximum.w=t->position.w+r.value;}
}

}   // namespace f3m_00970ed0

// @f3 0x00978f10 (community match, verified in this file)
namespace f3m_00978f10 {
namespace f3m_00978f10 {

void __cdecl FUN_00901e90(void* arr, int n, int elemSize) throw();

template <class T>
struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    hkArray() throw() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    void reserve(int n) throw() {
        if ((m_capacityAndFlags & 0x3fffffff) < n) {
            FUN_00901e90(this, n, sizeof(T));
        }
    }
};

struct Collidable {
    int unk00, unk04, unk08, unk0C;
    char m_ownerOffset;
    char unk11, unk12, unk13;
    int unk14, unk18;
    unsigned int m_collisionFilterInfo;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;

    void setOwner(void* owner) throw() {
        m_ownerOffset = (char)(int)owner - (char)(int)this;
    }
};

struct Vec4 {
    float x, y, z, w;
    void operator=(const Vec4& rhs) throw() {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        w = rhs.w;
    }
};

struct Aabb {
    Vec4 m_min;
    Vec4 m_max;
    void operator=(const Aabb& rhs) throw() {
        m_min = rhs.m_min;
        m_max = rhs.m_max;
    }
};

}

struct __declspec(novtable) FUN_00931a50 {
    virtual void v0() throw();
    int unk04, unk08, unk0C;
    f3m_00978f10::Collidable m_collidable;
    FUN_00931a50(int a, int b) throw();
};

namespace f3m_00978f10 {

struct __declspec(novtable) Phantom : FUN_00931a50 {
    hkArray<void*> m_overlapListeners;
    hkArray<void*> m_phantomListeners;
    int unk98, unk9C;

    Phantom(int a) throw() : FUN_00931a50(a, 2) {
        m_collidable.setOwner(this);
    }
};

}

struct FUN_00978f10 : f3m_00978f10::Phantom {
    f3m_00978f10::Aabb m_aabb;
    f3m_00978f10::hkArray<void*> m_overlappingCollidables;

    FUN_00978f10(const f3m_00978f10::Aabb& aabb, unsigned int collisionFilterInfo) throw();
};

// pdb: hkpAabbPhantom::hkpAabbPhantom | hkpAabbPhantom.obj | fnv360_0721_beta, call_gap, low
// pdb params: aabb, collisionFilterInfo
FUN_00978f10::FUN_00978f10(const f3m_00978f10::Aabb& aabb, unsigned int collisionFilterInfo) throw()
    : f3m_00978f10::Phantom(0)
{
    m_aabb = aabb;
    m_collidable.m_collisionFilterInfo = collisionFilterInfo;
    int cap = m_overlappingCollidables.m_capacityAndFlags & 0x3fffffff;
    if (cap == 0 || ((unsigned int)m_overlappingCollidables.m_data & 0xf) != 0) {
        int n = cap + 1;
        if (n < 4) {
            n = 4;
        }
        m_overlappingCollidables.reserve(n);
    }
}
}   // namespace f3m_00978f10

// @f3 0x00970b70 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00970b70 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long index);

namespace f3m_00970b70 {

struct B16 { int a, b, c, d; };

struct ThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls);
};

struct StridedVerts {
    const void* m_vertices;
    int m_numVertices;
    int m_stride;
    StridedVerts(const void* v, int n) : m_vertices(v), m_numVertices(n), m_stride(16) {}
};

struct Arg970b70 {
    int unk00;
    float radius04;
    const void* verts08;
    int numVerts0C;
    int unk10;
    int planes14;
};

}

struct __declspec(novtable) FUN_009e8750 {
    virtual ~FUN_009e8750();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    int unk08, unk0C;
    float m_radius;
    f3m_00970b70::B16 pad14, pad24, pad34, pad44;
    int unk54, unk58, unk5C;

    FUN_009e8750(const f3m_00970b70::StridedVerts& verts, const void* planes, float radius);

    void removeReference() {
        if (m_memSizeAndFlags != 0) {
            if (--m_referenceCount == 0) {
                delete this;
            }
        }
    }
};

namespace f3m_00970b70 {

struct Shape970b70 : FUN_009e8750 {
    virtual ~Shape970b70();

    static void* operator new(unsigned int n) {
        ThreadMemory* mem = (ThreadMemory*)::FUN_00d9b080(DAT_010f3170);
        void* p = mem->FUN_008f6d30(n, 0x27);
        ((unsigned short*)p)[2] = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p);

    __forceinline Shape970b70(const StridedVerts& v, const void* planes)
        : FUN_009e8750(StridedVerts(v), planes, 0.05f)
    {
    }
};

struct Owner970b70 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void v8C(Shape970b70* shape);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void vBC(Arg970b70* arg);

    void FUN_00970b70(Arg970b70* arg);
};

// pdb: bhkCharControllerShape::Init | bhkCharControllerShape.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: arInfo
void Owner970b70::FUN_00970b70(Arg970b70* arg)
{
    if (arg) {
        StridedVerts verts(arg->verts08, arg->numVerts0C);
        Shape970b70* shape = new Shape970b70(verts, &arg->planes14);
        shape->m_radius = arg->radius04;
        v8C(shape);
        shape->removeReference();
        vBC(arg);
    }
}

}
}   // namespace f3m_00970b70

// @f3 0x00961cd0 (community match, verified in this file)
namespace f3m_00961cd0 {
struct __declspec(align(16)) V1cd0
{
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d = 0.0f) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { w = 0.0f; z = 0.0f; y = 0.0f; x = 0.0f; }
    __forceinline void setAll(float a) { x = a; y = a; z = a; w = a; }
    __forceinline void setMul4(float rs, const V1cd0& a) { float r = float(rs); x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    __forceinline void setMul4(const V1cd0& a, const V1cd0& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void addMul4(float rs, const V1cd0& a) { float r = float(rs); x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    __forceinline void setAdd4(const V1cd0& a, const V1cd0& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline double dot3(const V1cd0& a) const { const double qx=x,qy=y,qz=z; return qx * a.x + qy * a.y + qz * a.z; }
    __forceinline void setCross(const V1cd0& v1, const V1cd0& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
};
struct Q1cd0
{
    V1cd0 m_vec;
    void FUN_008d3290(const Q1cd0& a, const Q1cd0& b);
};
__forceinline void setRotatedDir(V1cd0& out, const Q1cd0& q, const V1cd0& x)
{
    float qreal = q.m_vec(3);
    float q2minus1 = qreal * qreal - 0.5;
    V1cd0 ret;
    ret.setMul4(q2minus1, x);
    float imagDotDir = q.m_vec.dot3(x);
    ret.addMul4(imagDotDir, q.m_vec);
    V1cd0 imagCrossDir;
    imagCrossDir.setCross(q.m_vec, x);
    ret.addMul4(qreal, imagCrossDir);
    out.setAdd4(ret, ret);
}
struct T1cd0
{
    V1cd0 m_translation;
    Q1cd0 m_rotation;
    V1cd0 m_scale;
    void FUN_009643d0(void* src);
    __forceinline void setIdentity()
    {
        m_translation.setZero4();
        m_rotation.m_vec.set(0.0f, 0.0f, 0.0f, 1.0f);
        m_scale.setAll(1.0f);
    }
    __forceinline void setMul(const T1cd0& a, const T1cd0& b)
    {
        V1cd0 t;
        setRotatedDir(t, a.m_rotation, b.m_translation);
        m_translation.setAdd4(t, a.m_translation);
        m_rotation.FUN_008d3290(a.m_rotation, b.m_rotation);
        m_scale.setMul4(a.m_scale, b.m_scale);
    }
};
struct Skel1cd0
{
    int unk00;
    short* m_parents;
    int unk08,unk0c,unk10;
    T1cd0* m_pose;
};
void __cdecl FUN_00957fb0(Skel1cd0* s, T1cd0* pose, int bone, V1cd0* scale);
struct Inst1cd0
{
    int unk00,unk04;
    char** m_nodes;
    int unk0c,unk10,unk14,unk18,unk1c;
    int* m_map;
    int unk24,unk28;
    Skel1cd0* m_skel;
    void FUN_00961cd0(int bone, T1cd0& out);
};
void Inst1cd0::FUN_00961cd0(int bone, T1cd0& out)
{
    int idx = m_map[bone];
    if (idx >= 0)
    {
        char* node = m_nodes[idx];
        if (node)
        {
            out.FUN_009643d0(node + 0xe0);
            Skel1cd0* s = m_skel;
            FUN_00957fb0(s, s->m_pose, bone, &out.m_scale);
            return;
        }
    }
    T1cd0 parent;
    int p = m_skel->m_parents[bone];
    if (p >= 0)
        FUN_00961cd0(p, parent);
    else
        parent.setIdentity();
    out.setMul(parent, m_skel->m_pose[bone]);
}
}   // namespace f3m_00961cd0

// @f3 0x0096d070 (community match, verified in this file)
namespace f3m_0096d070 {
namespace f3m_0096d070 {
struct __declspec(align(16)) Matrix {
 float m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23;
 void FUN_0096ce80(const Matrix*,const Matrix*);
 void FUN_0096d070(const Matrix* rhs);
};
// pdb: hkpShapePhantom::setTransform | hkpShapePhantom.obj | fnv360_0721_beta, call_gap, low, conflict (skyrim: hkMatrix3::mul)
// pdb params: transform
void Matrix::FUN_0096d070(const Matrix* rhs) {
 Matrix temporary;
 temporary.FUN_0096ce80(this,rhs);
 m00=temporary.m00; m01=temporary.m01; m02=temporary.m02; m03=temporary.m03;
 m10=temporary.m10; m11=temporary.m11; m12=temporary.m12; m13=temporary.m13;
 m20=temporary.m20; m21=temporary.m21; m22=temporary.m22; m23=temporary.m23;
}
}
}   // namespace f3m_0096d070

// @f3 0x009784b0 (community match, verified in this file)
#include <math.h>
namespace f3m_009784b0 {

namespace f3m_009784b0 {
struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;
};

struct hkTransform
{
    hkVector4 col0;
    hkVector4 col1;
    hkVector4 col2;
    hkVector4 translation;

    void hkRotation_set(const hkVector4* quaternion);
};

__forceinline void lerp4(hkVector4& r, const hkVector4& a, const hkVector4& b, float t)
{
    float s = 1.0f - t;
    r.x = a.x * s + b.x * t;
    r.y = a.y * s + b.y * t;
    r.z = a.z * s + b.z * t;
    r.w = a.w * s + b.w * t;
}
__forceinline void rot3(hkVector4& r, const hkTransform& m, const hkVector4& v)
{
    float px = v.x; float py = v.y; float pz = v.z;
    r.x = m.col0.x * px + m.col1.x * py + m.col2.x * pz;
    r.y = m.col0.y * px + m.col1.y * py + m.col2.y * pz;
    r.z = m.col0.z * px + m.col1.z * py + m.col2.z * pz;
}
struct Interpolator
{
    hkVector4 translationA;
    hkVector4 translationB;
    hkVector4 rotationA;
    hkVector4 rotationB;
    hkVector4 pivot;

    void hkSweptTransform_approxTransformAt(float time, hkTransform* out);
};

// pdb: hkSweptTransform::approxTransformAt | hkSweptTransform.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void Interpolator::hkSweptTransform_approxTransformAt(float time, hkTransform* out)
{
    int unused0 = 1;
    int unused1 = 1;
    float u = (time - translationA.w) * translationB.w;
    hkVector4 q;
    lerp4(q, rotationA, rotationB, u);
    float lenSq = q.y * q.y + q.x * q.x + q.z * q.z + q.w * q.w;
    float zero=0.0f; float inv; if (lenSq != zero) inv=1.0f/(float)sqrt(lenSq); else inv=zero;
    q.x *= inv;
    q.y *= inv;
    q.z *= inv;
    q.w *= inv;
    out->hkRotation_set(&q);
    lerp4(out->translation, translationA, translationB, u);
    hkVector4 r;
    rot3(r, *out, pivot);
    out->translation.x -= r.x;
    out->translation.y -= r.y;
    out->translation.z -= r.z;
    out->translation.w -= 0.0;
}
}
}   // namespace f3m_009784b0

// @f3 0x0097ee70 (community match, verified in this file)
namespace f3m_0097ee70 {
namespace f3m_0097ee70 {
class Collector {
public:
    virtual void slot0();
    virtual void beginObject(const char* name, int type, const void* object);
    virtual void slot2();
    virtual void slot3();
    virtual void endObject();
};

class TypeQuery {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int query(const void* object);
};

struct Flag { char value; Flag() {} Flag(bool x):value(x) {} operator bool() const { return value != 0; } };
class Named {
public:
    void* unk00;
    Flag FUN_009b0780();
    void* FUN_009b0490();
};

void* __cdecl FUN_0097e8d0(void* p);
Named* __cdecl FUN_0097e8e0(void* a);

Named* __cdecl FUN_0097ee70(void* object, Collector* collector, void* source)
{
    if (!object)
        return 0;
    TypeQuery* query = (TypeQuery*)FUN_0097e8d0(source);
    Named* named = FUN_0097e8e0(object);
    void* savedObject=object;
    if (named) {
        int type = query->query(named);
        if (named->FUN_009b0780()) {
            collector->beginObject((const char*)named->FUN_009b0490(), type, savedObject);
            return named;
        }
    }
    return 0;
}
}

}   // namespace f3m_0097ee70

// @f3 0x00976c10 (community match, verified in this file)
namespace f3m_00976c10 {
namespace c_00976c10 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void SetSub4(const Vec4& a, const Vec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
    void Add3(const Vec4& a) { x += a.x; y += a.y; z += a.z; }
    void hkVector4_setRotatedDir(const void* transform, const Vec4* v);
};
struct Aabb { Vec4 min; Vec4 max; };
struct Obj {
    int unk00[0x10];
    Aabb aabb;
    int unk60[8];
    Vec4 pos;
};
// pdb: hkpVehicleDefaultSteering::calcMainSteeringAngle | hkpVehicleDefaultSteering.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkSweptTransformUtil::setCentreOfRotationLocal)
// pdb params: deltaTime, vehicle, filteredInfoOutput, steeringOutput
void __cdecl FUN_00976c10(const Vec4* p, Obj* obj)
{
    Vec4 d;
    d.SetSub4(*p, obj->pos);
    obj->pos = *p;
    Vec4 r;
    r.hkVector4_setRotatedDir(obj, &d);
    obj->aabb.min.Add3(r);
    obj->aabb.max.Add3(r);
}
}
}   // namespace f3m_00976c10

// @f3 0x0097e450 (community match, verified in this file)
namespace f3m_0097e450 {
namespace f3m_0097e450
{
struct Q3Bool
{
    char v;
    Q3Bool(bool b) { v = (char)b; }
};

struct __declspec(align(16)) Q3Vec
{
    float x, y, z, w;
};

struct Q3Other
{
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c;
    Q3Vec pos;
    int unk140, unk144, unk148, unk14c;
    Q3Vec rot;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    float unk180;
};

static __declspec(noinline) float FUN_0097e3f0(const Q3Vec& a, const Q3Vec& b)
{
    Q3Vec d;
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    return d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w;
}

struct Q3Track
{
    int unk000; int unk004; int unk008; int unk00c;
    Q3Vec pos;
    Q3Vec rot;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    float unk54;
    float unk58;
    Q3Bool FUN_0097e450(Q3Other* o);
};
}

f3m_0097e450::Q3Bool f3m_0097e450::Q3Track::FUN_0097e450(Q3Other* o)
{
    float f = o->unk180;
    const Q3Vec* orot = &o->rot;
    Q3Vec d;
    d.x = pos.x - o->pos.x;
    d.y = pos.y - o->pos.y;
    d.z = pos.z - o->pos.z;
    float lenSq = d.x * d.x + d.y * d.y + d.z * d.z;
    float tol = unk54 * unk54;
    if (lenSq < tol) {
        float r = FUN_0097e3f0(rot, *orot);
        float a = r * f * f;
        float b = unk58 * unk58;
        if (a < b)
            return true;
    }
    pos.x = o->pos.x;
    pos.y = o->pos.y;
    pos.z = o->pos.z;
    pos.w = o->pos.w;
    rot.x = orot->x;
    rot.y = orot->y;
    rot.z = orot->z;
    rot.w = orot->w;
    return false;
}
}   // namespace f3m_0097e450

// @f3 0x00962570 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00962570 {
namespace z962570 {

struct StackMem {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* AllocBlock(int size);
    virtual void FreeBlock(void* p);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* cur;
    int unk24;
    char* base;
    char* end;
    void* FUN_008f6d30(int nbytes, int tag) throw();
    void FUN_008f6d90(void* p, unsigned int size, int tag) throw();
};

__declspec(dllimport) StackMem* __stdcall FUN_00d9b080(unsigned long index) throw();

void __cdecl FUN_00901e90(void* array, int capacity, int elementSize) throw();

static __forceinline void* StackAlloc(int bytes)
{
    StackMem* m = FUN_00d9b080(DAT_010f3170);
    int size = (bytes + 16) & ~15;
    char* p = m->cur;
    char* next = p + size;
    if (next <= m->end) {
        m->cur = next;
        return p;
    }
    return m->AllocBlock(size);
}

static __forceinline void StackFree(void* p)
{
    StackMem* m = FUN_00d9b080(DAT_010f3170);
    m->cur = (char*)p;
    if (p == m->base)
        m->FreeBlock(p);
}

template <class T> struct Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void init()
    {
        m_data = 0;
        m_size = 0;
        m_capacityAndFlags = 0x80000000;
    }
    __forceinline void release()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int n = m_capacityAndFlags & 0x3fffffff;
            StackMem* h = FUN_00d9b080(DAT_010f3170);
            h->FUN_008f6d90(m_data, n * sizeof(T), 0x17);
        }
    }
    __forceinline void setSize(int n)
    {
        int cap = m_capacityAndFlags & 0x3fffffff;
        if (cap < n) {
            int twice = cap + cap;
            FUN_00901e90(this, n < twice ? twice : n, sizeof(T));
        }
        m_size = n;
    }
};

template <class T> struct LocalArray : Array<T> {
    void* m_localMemory;

    __forceinline void initLocal(int n)
    {
        this->init();
        T* p = (T*)StackAlloc(n * sizeof(T));
        this->m_capacityAndFlags = n | 0x80000000;
        this->m_data = p;
        m_localMemory = p;
    }
    __forceinline void releaseLocal()
    {
        StackFree(m_localMemory);
        this->release();
    }
};

struct Source {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual struct Item* v18();
};

struct Item {
    void FUN_009316f0();
};

struct RefObject {
    virtual ~RefObject();
    unsigned short m_memSize;
    short m_refCount;

    __forceinline void removeReference()
    {
        if (m_memSize != 0) {
            if (--m_refCount == 0)
                delete this;
        }
    }
};

struct Link {
    RefObject* FUN_0097a150(Item* child, Item* parent, void* arg);
};

struct Skeleton {
    int unk00;
    short* parents;
};

struct Result {
    void* vtbl;
    unsigned short m_memSize;
    short m_refCount;
    Result* FUN_009623a0(Array<Item*>* items, Array<RefObject*>* links, Skeleton* skeleton, void* extra);
};

struct Builder {
    int unk00, unk04;
    Array<Source*> sources;
    Array<Link*> links;
    char unk20[0xc];
    Skeleton* skeleton;

    Result* hkaRagdollInstance_clone(void* arg);
};

// pdb: hkaRagdollInstance::clone | hkaRagdollInstance.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
Result* Builder::hkaRagdollInstance_clone(void* arg)
{
    int a = links.m_size;
    int obj = sources.m_size;
    LocalArray<Item*> items;
    items.initLocal(obj);
    items.setSize(obj);
    LocalArray<RefObject*> made;
    made.initLocal(a);
    made.setSize(a);
    for (int i = 0; i < obj; i++)
        items[i] = sources[i]->v18();
    for (int i = 0; i < a; i++)
    {
        Item* child = items[i + 1];
        Item* parentItem = items[skeleton->parents[i + 1]];
        made[i] = links[i]->FUN_0097a150(child, parentItem, arg);
    }
    StackMem* heap = FUN_00d9b080(DAT_010f3170);
    Result* n0 = (Result*)heap->FUN_008f6d30(0x30, 0xe);
    n0->m_memSize = 0x30;
    Result* result = n0->FUN_009623a0(&items, &made, skeleton, unk20);
    for (int i = 0; i < obj; i++)
        items[i]->FUN_009316f0();
    for (int i = 0; i < a; i++)
        made[i]->removeReference();
    made.releaseLocal();
    items.releaseLocal();
    return result;
}

}
}   // namespace f3m_00962570

// @f3 0x0097afd0 (community match, verified in this file)
extern float DAT_01092a50;
extern float DAT_01092a54;
extern float DAT_01092a58;
extern float DAT_01092a5c;
namespace f3m_0097afd0 {
namespace f3m_0097afd0 {


struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void SetAll(float f) { x = f; y = f; z = f; w = f; }
    __forceinline void SetNeg4(const Vec4& a) { x = -a.x; y = -a.y; z = -a.z; w = -a.w; }
    static __forceinline float Min(const float& a, const float& b) { return a < b ? a : b; }
    static __forceinline float Max(const float& a, const float& b) { return a > b ? a : b; }
    __forceinline void SetMin(const Vec4& a, const Vec4& b) { x = Min(a.x, b.x); y = Min(a.y, b.y); z = Min(a.z, b.z); w = Min(a.w, b.w); }
    __forceinline void SetMax(const Vec4& a, const Vec4& b) { x = Max(a.x, b.x); y = Max(a.y, b.y); z = Max(a.z, b.z); w = Max(a.w, b.w); }
};
struct Aabb { Vec4 low, high; };
struct Transform { Vec4 c0, c1, c2, t; };
struct Shape {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18();
    virtual void GetAabb(const Transform& t, float tolerance, Aabb& out);
};
struct ChildInfo { Shape* shape; int unk04, unk08, unk0c; };
struct ListShape {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ChildInfo* children;
    int count;
    int unk20, unk24, unk28, unk2c;
    Vec4 extent;
    void FUN_0097aae0();
    void FUN_0097afd0(const Transform& t, float tolerance, Aabb& out);
};

void ListShape::FUN_0097afd0(const Transform& t, float tolerance, Aabb& out)
{
    int m = ((extent.x <= DAT_01092a50) ? 8 : 0) | ((extent.y <= DAT_01092a54) ? 4 : 0) |
            ((extent.z <= DAT_01092a58) ? 2 : 0) | ((extent.w <= DAT_01092a5c) ? 1 : 0);
    if (m == 0xf)
        FUN_0097aae0();
    out.low.SetAll(1.70141001e+38f);
    out.high.SetNeg4(out.low);
    for (int i = 0; i < count; i++) {
        Shape* s = children[i].shape;
        Aabb a;
        s->GetAabb(t, tolerance, a);
        out.low.SetMin(out.low, a.low);
        out.high.SetMax(out.high, a.high);
    }
}

}
}   // namespace f3m_0097afd0

// @f3 0x0097e130 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d25c[];
extern const char DAT_00e32798[];
namespace f3m_0097e130 {

namespace f3m_0097e130 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Command { const char* name; unsigned int ticks; unsigned int unk08; 
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};
struct Stream { unsigned int unk00; Command* cursor; unsigned int unk08; Command* limit; };

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

struct Transform {
    Vec4 c0, c1, c2, t;
    void hkTransform_setMul(const Transform* a, const Transform* b);
};

struct RayInput {
    Vec4 from;
    Vec4 to;
    unsigned int unk20, unk24, unk28, unk2c;
};

struct CdBody {
    void* shape;
    unsigned int key;
    const Transform* motion;
    const CdBody* parent;
    CdBody() {}
    CdBody(const CdBody* p, const Transform* m) { motion = m; parent = p; }
};

struct Shape {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void CastRay(const RayInput& input, const CdBody& body, void* collector);
};

struct TransformShape {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Shape* child;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    Transform xf;
    void hkpTransformShape_castRayWithCollectorImpl(const RayInput& input, const CdBody& parent, void* collector);
};

__forceinline void InvPos(Vec4& out, const Transform& a, const Vec4& b)
{
    float dx = b.x - a.t.x;
    float dy = b.y - a.t.y;
    float dz = b.z - a.t.z;
    out.x = a.c0.x * dx + a.c0.y * dy + a.c0.z * dz;
    out.y = a.c1.x * dx + a.c1.y * dy + a.c1.z * dz;
    out.z = a.c2.x * dx + a.c2.y * dy + a.c2.z * dz;
    out.w = 0.0f;
}

__forceinline void InvPos2(Vec4& out, const Transform& a, const Vec4& b)
{
    float dy = 0.0f, dx = 0.0f, dz = 0.0f;
    dx = b.x - a.t.x;
    dy = b.y - a.t.y;
    dz = b.z - a.t.z;
    out.x = a.c0.x * dx + a.c0.y * dy + a.c0.z * dz;
    out.y = a.c1.x * dx + a.c1.y * dy + a.c1.z * dz;
    out.z = a.c2.x * dx + a.c2.y * dy + a.c2.z * dz;
    out.w = 0.0f;
}

// pdb: hkpTransformShape::castRayWithCollectorImpl | hkpTransformShape.obj | fnv360_0822_retail, objopen_prop + bridge(caller_sim|vtable) + skyrim(caller_sim), high
void TransformShape::hkpTransformShape_castRayWithCollectorImpl(const RayInput& input, const CdBody& parent, void* collector)
{
    Stream* s = (Stream*)TlsGetValue(DAT_0116913c);
    Command* c = s->cursor;
    if (c < s->limit) {
        c->name = DAT_00e7d25c;
        c->setTime();
        s->cursor = c + 1;
    }
    RayInput sub = input;
    InvPos(sub.from, xf, input.from);
    InvPos2(sub.to, xf, input.to);
    Transform world;
    world.hkTransform_setMul(parent.motion, &xf);
    CdBody body(&parent, &world);
    body.shape = child;
    body.key = 0;
    child->CastRay(sub, body, collector);
    Stream* s2 = (Stream*)TlsGetValue(DAT_0116913c);
    Command* c2 = s2->cursor;
    if (c2 < s2->limit) {
        c2->name = DAT_00e32798;
        c2->setTime();
        s2->cursor = c2 + 1;
    }
}

}
}   // namespace f3m_0097e130

// @f3 0x0096a1d0 (community match, verified in this file)
extern const float FUN_00de6e60;
namespace f3m_0096a1d0 {
namespace q96a1d0 {
struct World;
struct Owner {
    int unk00;
    int unk04;
    World* world;
};
struct Collidable {
    int unk00[4];
    signed char ownerOffset;
    char pad11[0x1b];
    unsigned int type : 7;
    void FUN_009316f0();
    Owner* GetOwner() { return (Owner*)((char*)this + ownerOffset); }
    World* GetWorld();
};
struct __declspec(align(16)) Vec4 { float x, y, z, w; Vec4& operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; } };
struct Record {
    Vec4 a;
    Vec4 b;
    int unk20;
    int unk24;
    Collidable* collidable;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};
inline World* Collidable::GetWorld() { Owner* o = GetOwner(); return o ? o->world : 0; }
struct Callback {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14();
    virtual void Added(Record* r);
    virtual void Removed(Record* r);
};
struct Listener { int unk00[10]; Callback* callback; };
struct World { int unk000[196]; Listener* listener; };
template <class T> struct Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    void removeAt(int i) { m_size--; m_data[i] = m_data[m_size]; }
};
struct Phantom {
    int unk00;
    float unk04;
    int unk08[3];
    int unk14;
    int unk18[131];
    Array<Collidable*> colls;
    Array<int> states;
    Array<Record> recs;
    void FUN_0096a1d0();
};
// pdb: bhkCharacterPointCollector::handleCollisions | bhkCharacterPointCollector.obj | fnv360_1110_retail, objrun_open, low
void Phantom::FUN_0096a1d0()
{
    unk04 = FUN_00de6e60;
    unk14 = 0;
    for (int i = 0; i < states.m_size; i++)
    {
        unsigned int type = colls.m_data[i]->type;
        World* world = recs.m_data[i].collidable->GetWorld();
        Record* r = &recs.m_data[i];
        if (world)
        {
            Listener* l = world->listener;
            if (l)
            {
                switch (type)
                {
                case 14:
                case 16:
                {
                    Callback* cb = l->callback;
                    if (cb)
                    {
                        if (states.m_data[i] == 0)
                            cb->Added(r);
                        else if (states.m_data[i] == 1)
                            cb->Removed(r);
                    }
                    break;
                }
                }
            }
        }
    }
    for (int i = states.m_size - 1; i >= 0; i--)
    {
        if (states.m_data[i] == 1)
        {
            colls.m_data[i]->FUN_009316f0();
            colls.removeAt(i);
            recs.removeAt(i);
            states.removeAt(i);
        }
        else
            states.m_data[i] = 1;
    }
}
}
}   // namespace f3m_0096a1d0

// @f3 0x009776f0 (community match, verified in this file)
#include <math.h>
namespace f3m_009776f0 {
// 0x009776f0: hkSweptTransformUtil::backStepMotionState(hkTime time, hkMotionState& motionState) of Havok 5.5.0
// (hkBase, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Moves a motion state's end point back to the given time: the end rotation becomes the rotation interpolated at
// that time, the end centre of mass the interpolated centre, the inverse time step and the angle travelled are
// rescaled, and the transform is rebuilt from the new end state.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, swept transform)
// follow the SDK's inline maths for the x87 build. The function's own body is written from the game's code.

namespace f3m_009776f0 {

typedef float hkReal;
typedef hkReal hkTime;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

const hkReal HK_REAL_EPSILON = 1.192092896e-07F;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }

template <typename T>
inline T max2(T x, T y)
{
    return x > y ? x : y;
}
}  // namespace hkMath

struct hkMatrix3;
struct hkRotation;

struct hkVector4
{
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }

    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt);
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
    __forceinline hkSimdReal dot4(const hkVector4& a) const;
    __forceinline hkSimdReal lengthSquared4() const;
    __forceinline hkSimdReal lengthInverse4() const;
    __forceinline void normalize4();

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
    // set(const hkQuaternion&)
    void hkRotation_set(const hkQuaternion& q);
};

struct hkTransform
{
    __forceinline void setRotation(const hkQuaternion& quatRotation) { m_rotation.hkRotation_set(quatRotation); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkSweptTransform
{
    __forceinline hkTime getBaseTime() const { return hkTime(m_centerOfMass0(3)); }
    __forceinline hkReal getInvDeltaTime() const { return m_centerOfMass1(3); }
    __forceinline hkReal getInterpolationValue(hkTime t) const
    {
        hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
        return dt;
    }

    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkQuaternion m_rotation0;
    hkQuaternion m_rotation1;
    hkVector4 m_centerOfMassLocal;
};

struct hkMotionState
{
    inline hkTransform& getTransform() { return m_transform; }
    inline hkSweptTransform& getSweptTransform() { return m_sweptTransform; }

    hkTransform m_transform;
    hkSweptTransform m_sweptTransform;
    hkVector4 m_deltaAngle;
    hkReal m_objectRadius;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x + v1.x;
    y = v0.y + v1.y;
    z = v0.z + v1.z;
    w = v0.w + v1.w;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
    hkReal t = hkReal(rt);
    hkReal s = 1.0f - t;
    hkVector4& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}

__forceinline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z) + (w * a.w);
}

__forceinline hkSimdReal hkVector4::lengthSquared4() const
{
    return this->dot4(*this);
}

__forceinline hkSimdReal hkVector4::lengthInverse4() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z) + (w * w);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize4()
{
    this->mul4(this->lengthInverse4());
}

namespace hkSweptTransformUtil {

// the rotation at interpolation value t: the midpoint of the two end rotations, roughly normalized, then
// interpolated with the nearer end and normalized
__forceinline void _lerp2(const hkSweptTransform& sweptTrans, hkReal t, hkQuaternion& quatOut)
{
    hkVector4 rot0 = sweptTrans.m_rotation0.m_vec;
    hkVector4 rot1 = sweptTrans.m_rotation1.m_vec;
    {
        quatOut.m_vec.setAdd4(rot0, rot1);
        hkReal len2 = quatOut.m_vec.lengthSquared4();
        hkReal r = 0.75f - 0.125f * len2;
        r = r * (1.5f - 0.5f * len2 * r * r);
        quatOut.m_vec.mul4(r);
    }

    if (t < 0.5f)
    {
        quatOut.m_vec.setInterpolate4(rot0, quatOut.m_vec, 2.0f * t);
    }
    else
    {
        quatOut.m_vec.setInterpolate4(quatOut.m_vec, rot1, 2.0f * t - 1.0f);
    }
    quatOut.m_vec.normalize4();
}

// the transform at the end of the step: the end rotation, and the end centre of mass minus the rotated local centre
__forceinline void calcTransAtT1(const hkSweptTransform& sweptTrans, hkTransform& transformOut)
{
    const hkQuaternion& qt = sweptTrans.m_rotation1;

    transformOut.setRotation(qt);

    hkVector4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

}  // namespace hkSweptTransformUtil

// pdb: hkSweptTransformUtil::backStepMotionState | hkSweptTransformUtil.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq) + skyrim(call_gap), high
void __cdecl hkSweptTransformUtil_backStepMotionState(hkTime time, hkMotionState& motionState)
{
    hkSweptTransform& st = motionState.getSweptTransform();
    hkReal t = hkMath::max2(st.getInterpolationValue(time), HK_REAL_EPSILON);

    hkSweptTransformUtil::_lerp2(st, t, st.m_rotation1);

    const hkReal newInvDeltaTime = st.getInvDeltaTime() / t;
    st.m_centerOfMass1.setInterpolate4(st.m_centerOfMass0, st.m_centerOfMass1, t);
    st.m_centerOfMass1(3) = newInvDeltaTime;
    motionState.m_deltaAngle.mul4(t);
    hkSweptTransformUtil::calcTransAtT1(st, motionState.getTransform());
}

}  // namespace f3m_009776f0
}   // namespace f3m_009776f0

// @f3 0x00970190 (community match, verified in this file)
namespace f3m_00970190 {
// 0x00970190: hkpCollideTriangleUtil::calcBarycentricCoordinates(hkVector4Parameter pos, hkVector4Parameter t0,
// hkVector4Parameter t1, hkVector4Parameter t2, hkPadSpu<hkReal> result[3]) of Havok 5.5.0 (hkpInternal, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Barycentric coordinates of the point of the triangle (t0, t1, t2) nearest to pos in the triangle's plane. For a
// degenerate triangle (zero area) the point is projected onto the triangle's longest edge instead.
// Names follow the Havok 5.5.0 SDK headers; the vector helpers follow the forms of the SDK's inline maths for the
// x87 build. The function's own body is written from the game's code.
namespace f3m_00970190 {

typedef float hkReal;
typedef hkReal hkSimdReal;

struct hkVector4
{
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline hkSimdReal dot3(const hkVector4& a) const;

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

typedef const hkVector4& hkVector4Parameter;

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

template <typename TYPE>
struct hkPadSpu
{
    __forceinline void operator=(TYPE e) { m_storage = e; }

    TYPE m_storage;
};

// pdb: hkpCollideTriangleUtil::calcBarycentricCoordinates | hkpCollideTriangleUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpCollideTriangleUtil_calcBarycentricCoordinates(hkVector4Parameter pos, hkVector4Parameter t0, hkVector4Parameter t1, hkVector4Parameter t2,
                          hkPadSpu<hkReal> result[3])
{
    hkVector4 Q;
    Q.setSub4(t0, t1);
    hkVector4 R;
    R.setSub4(t2, t1);

    const hkReal QQ = Q.dot3(Q);
    const hkReal RR = R.dot3(R);
    const hkReal QR = R.dot3(Q);

    const hkReal QQRR = QQ * RR;
    const hkReal QRQR = QR * QR;
    const hkReal Det = (QQRR - QRQR);

    if (Det > 0.0f)
    {
        // a proper triangle
        const hkReal invDet = 1.0f / Det;

        hkVector4 relPos;
        relPos.setSub4(t1, pos);

        const hkReal sq = relPos.dot3(Q);
        const hkReal sr = relPos.dot3(R);

        const hkReal q = (sr * QR - RR * sq);
        const hkReal r = (sq * QR - QQ * sr);

        result[0] = invDet * q;
        result[1] = invDet * (Det - q - r);
        result[2] = invDet * r;
        return;
    }

    // a degenerate triangle: project onto the longest edge
    hkVector4 S;
    S.setSub4(t0, t2);
    const hkReal SS = S.dot3(S);

    if (QQ >= RR)
    {
        if (SS >= QQ)
        {
            // edge t2 - t0
            result[1] = 0.0f;
            if (SS > 0.0f)
            {
                hkVector4 relPos;
                relPos.setSub4(pos, t2);
                const hkReal ss = relPos.dot3(S);
                const hkReal t = ss / SS;
                result[0] = t;
                result[2] = 1.0f - t;
            }
            else
            {
                result[0] = 0.0f;
                result[2] = 0.0f;
            }
        }
        else
        {
            // edge t1 - t0
            hkVector4 relPos;
            relPos.setSub4(pos, t1);
            const hkReal sq = relPos.dot3(Q);
            const hkReal t = sq / QQ;
            result[0] = t;
            result[1] = 1.0f - t;
            result[2] = 0.0f;
        }
    }
    else
    {
        if (SS >= RR)
        {
            // edge t2 - t0
            hkVector4 relPos;
            relPos.setSub4(pos, t2);
            const hkReal ss = relPos.dot3(S);
            const hkReal t = ss / SS;
            result[0] = t;
            result[1] = 0.0f;
            result[2] = 1.0f - t;
        }
        else
        {
            // edge t1 - t2
            hkVector4 relPos;
            relPos.setSub4(pos, t1);
            result[0] = 0.0f;
            const hkReal sr = relPos.dot3(R);
            const hkReal t = sr / RR;
            result[2] = t;
            result[1] = 1.0f - t;
        }
    }
}

}  // namespace f3m_00970190
}   // namespace f3m_00970190

// @f3 0x00971020 (community match, verified in this file)
#include <math.h>
namespace f3m_00971020 {
// 0x00971020: hkpSphereUtil::castRayUtil(hkReal radius, const hkpShapeRayCastInput& input,
// hkpShapeRayCastOutput& results) of Havok 5.5.0 (an inline function of hkpCollide's headers, emitted out of line;
// compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Casts a ray against a sphere of the given radius around the origin: solves the quadratic for the ray
// parameter, moves the start point towards the sphere first when the ray starts far outside, and on a hit nearer
// than the previous one writes the hit fraction, the normal and an invalid shape key into the results.
// Class and member names follow the Havok 5.5.0 SDK headers; the body follows the SDK's inline function of this
// name and the vector helpers follow the SDK's inline maths for the x87 build.

namespace f3m_00971020 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned int hkUint32;
typedef hkUint32 hkpShapeKey;

const hkpShapeKey HK_INVALID_SHAPE_KEY = 0xffffffff;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
}  // namespace hkMath

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }

private:
    char m_bool;
};

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt);
    __forceinline hkSimdReal dot3(const hkVector4& a) const;
    __forceinline hkSimdReal lengthSquared3() const;

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

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
    hkReal t = hkReal(rt);
    hkReal s = 1.0f - t;
    hkVector4& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}

struct hkpRayShapeCollectionFilter;

struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    hkUint32 m_filterInfo;
    const hkpRayShapeCollectionFilter* m_rayShapeCollectionFilter;
};

struct hkpShapeRayCastCollectorOutput
{
    hkVector4 m_normal;
    hkReal m_hitFraction;
    int m_extraInfo;
};

struct hkpShapeRayCastOutput : hkpShapeRayCastCollectorOutput
{
    enum { MAX_HIERARCHY_DEPTH = 8 };

    __forceinline void setKey(hkpShapeKey key) { m_shapeKeys[m_shapeKeyIndex] = key; }

    hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
    int m_shapeKeyIndex;
};

// pdb: hkpSphereUtil::castRayUtil | hkpSphereShape.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
hkBool __cdecl hkpSphereUtil_castRayUtil(hkReal radius, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results)
{
    {
        hkReal radius2 = radius * radius;

        // solve the quadratic A*x*x + 2*B*x + C = 0
        hkVector4 dir;
        dir.setSub4(input.m_to, input.m_from);

        hkReal B = hkReal(dir.dot3(input.m_from));
        if (B >= 0)
        {
            // the ray points away from the centre
            goto returnFalse;
        }

        const hkReal A = dir.lengthSquared3();

        // a long ray (start point more than ten radii outside) is shortened first
        hkReal offset;
        hkVector4 midPoint;
        if (B * B > A * radius2 * 100.0f)
        {
            // no hit if the ray is shorter than the distance of the start point to the centre
            if (A < radius2)
            {
                goto returnFalse;
            }
            offset = -B;
            midPoint.setInterpolate4(input.m_from, input.m_to, offset / A);
            B = 0.0f;
        }
        else
        {
            offset = 0.0f;
            midPoint = input.m_from;
        }

        const hkReal C = hkReal(midPoint.lengthSquared3()) - radius2;
        const hkReal det = B * B - A * C;

        if (det <= 0)
        {
            // the infinite line misses
            goto returnFalse;
        }

        const hkReal sqDet = hkMath::sqrt(det);

        const hkReal t2 = -B - sqDet;
        hkReal t = t2 + offset;

        if (t >= (A * results.m_hitFraction))
        {
            // behind the end point, or farther than the previous hit
            goto returnFalse;
        }

        if (t < 0)
        {
            // the start point is inside
            goto returnFalse;
        }

        // 0 < t < A here, so the division gives a fraction between 0 and 1
        t = t / A;

        results.m_hitFraction = t;
        results.m_normal.setInterpolate4(input.m_from, input.m_to, t);
        results.m_normal.mul4(1.0f / radius);
        results.setKey(HK_INVALID_SHAPE_KEY);
        return true;
    }

returnFalse:
    return false;
}

}  // namespace f3m_00971020
}   // namespace f3m_00971020

// @f3 0x00976cd0 (community match, verified in this file)
#include <math.h>
namespace f3m_00976cd0 {
// 0x00976cd0: hkSweptTransformUtil::lerp2(const hkSweptTransform& sweptTrans, hkTime t, hkTransform& transformOut)
// of Havok 5.5.0 (hkBase, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The transform of a swept transform at time t: the rotation interpolated in two steps (the midpoint of the two
// end rotations roughly normalized, interpolated with the nearer end, normalized), the centre of mass
// interpolated linearly, minus the rotated local centre of mass.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, swept transform)
// follow the SDK's inline maths for the x87 build. The function's own body is written from the game's code.

namespace f3m_00976cd0 {

typedef float hkReal;
typedef hkReal hkTime;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}  // namespace hkMath

struct hkMatrix3;
struct hkRotation;

struct hkVector4
{
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }

    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void sub4(const hkVector4& v);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt);
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
    __forceinline hkSimdReal dot4(const hkVector4& a) const;
    __forceinline hkSimdReal lengthSquared4() const;
    __forceinline hkSimdReal lengthInverse4() const;
    __forceinline void normalize4();

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
    // set(const hkQuaternion&)
    void hkRotation_set(const hkQuaternion& q);
};

struct hkTransform
{
    __forceinline void setRotation(const hkQuaternion& quatRotation) { m_rotation.hkRotation_set(quatRotation); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkSweptTransform
{
    __forceinline hkTime getBaseTime() const { return hkTime(m_centerOfMass0(3)); }
    __forceinline hkReal getInvDeltaTime() const { return m_centerOfMass1(3); }
    __forceinline hkReal getInterpolationValue(hkTime t) const
    {
        hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
        return dt;
    }

    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkQuaternion m_rotation0;
    hkQuaternion m_rotation1;
    hkVector4 m_centerOfMassLocal;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x + v1.x;
    y = v0.y + v1.y;
    z = v0.z + v1.z;
    w = v0.w + v1.w;
}

__forceinline void hkVector4::sub4(const hkVector4& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
    hkReal t = hkReal(rt);
    hkReal s = 1.0f - t;
    hkVector4& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}

__forceinline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z) + (w * a.w);
}

__forceinline hkSimdReal hkVector4::lengthSquared4() const
{
    return this->dot4(*this);
}

__forceinline hkSimdReal hkVector4::lengthInverse4() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z) + (w * w);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize4()
{
    this->mul4(this->lengthInverse4());
}

namespace hkSweptTransformUtil {

// the rotation at interpolation value t: the midpoint of the two end rotations, roughly normalized, then
// interpolated with the nearer end and normalized
__forceinline void _lerp2(const hkSweptTransform& sweptTrans, hkReal t, hkQuaternion& quatOut)
{
    hkVector4 rot0 = sweptTrans.m_rotation0.m_vec;
    hkVector4 rot1 = sweptTrans.m_rotation1.m_vec;
    {
        quatOut.m_vec.setAdd4(rot0, rot1);
        hkReal len2 = quatOut.m_vec.lengthSquared4();
        hkReal r = 0.75f - 0.125f * len2;
        r = r * (1.5f - 0.5f * len2 * r * r);
        quatOut.m_vec.mul4(r);
    }

    if (t < 0.5f)
    {
        quatOut.m_vec.setInterpolate4(rot0, quatOut.m_vec, 2.0f * t);
    }
    else
    {
        quatOut.m_vec.setInterpolate4(quatOut.m_vec, rot1, 2.0f * t - 1.0f);
    }
    quatOut.m_vec.normalize4();
}

// the whole transform at interpolation value t
__forceinline void _lerp2(const hkSweptTransform& sweptTrans, hkReal t, hkTransform& transformOut)
{
    hkQuaternion qt;
    _lerp2(sweptTrans, t, qt);

    transformOut.setRotation(qt);
    transformOut.getTranslation().setInterpolate4(sweptTrans.m_centerOfMass0, sweptTrans.m_centerOfMass1, t);

    hkVector4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().sub4(centerShift);
}

}  // namespace hkSweptTransformUtil

// pdb: hkSweptTransformUtil::lerp2 | hkSweptTransformUtil.obj | fnv360_0822_debug, call_gap + bridge(call_seq|caller) + skyrim(call_seq), high
void __cdecl hkSweptTransformUtil_lerp2(const hkSweptTransform& sweptTrans, hkTime t, hkTransform& transformOut)
{
    hkReal r = sweptTrans.getInterpolationValue(t);
    hkSweptTransformUtil::_lerp2(sweptTrans, r, transformOut);
}

}  // namespace f3m_00976cd0
}   // namespace f3m_00976cd0

// @f3 0x009773a0 (community match, verified in this file)
#include <math.h>
namespace f3m_009773a0 {
// 0x009773a0: hkSweptTransformUtil::lerp2Rel(const hkSweptTransform& sweptTrans, hkReal r, hkTransform& transformOut)
// of Havok 5.5.0 (hkBase, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The transform of a swept transform at the interpolation value r (0 = start, 1 = end): the rotation interpolated in two steps (the midpoint of the two
// end rotations roughly normalized, interpolated with the nearer end, normalized), the centre of mass
// interpolated linearly, minus the rotated local centre of mass.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, swept transform)
// follow the SDK's inline maths for the x87 build. The function's own body is written from the game's code.

namespace f3m_009773a0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}  // namespace hkMath

struct hkMatrix3;
struct hkRotation;

struct hkVector4
{
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }

    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void sub4(const hkVector4& v);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt);
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
    __forceinline hkSimdReal dot4(const hkVector4& a) const;
    __forceinline hkSimdReal lengthSquared4() const;
    __forceinline hkSimdReal lengthInverse4() const;
    __forceinline void normalize4();

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
    // set(const hkQuaternion&)
    void hkRotation_set(const hkQuaternion& q);
};

struct hkTransform
{
    __forceinline void setRotation(const hkQuaternion& quatRotation) { m_rotation.hkRotation_set(quatRotation); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkSweptTransform
{
    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkQuaternion m_rotation0;
    hkQuaternion m_rotation1;
    hkVector4 m_centerOfMassLocal;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x + v1.x;
    y = v0.y + v1.y;
    z = v0.z + v1.z;
    w = v0.w + v1.w;
}

__forceinline void hkVector4::sub4(const hkVector4& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
    hkReal t = hkReal(rt);
    hkReal s = 1.0f - t;
    hkVector4& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}

__forceinline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z) + (w * a.w);
}

__forceinline hkSimdReal hkVector4::lengthSquared4() const
{
    return this->dot4(*this);
}

__forceinline hkSimdReal hkVector4::lengthInverse4() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z) + (w * w);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize4()
{
    this->mul4(this->lengthInverse4());
}

namespace hkSweptTransformUtil {

// the rotation at interpolation value t: the midpoint of the two end rotations, roughly normalized, then
// interpolated with the nearer end and normalized
__forceinline void _lerp2(const hkSweptTransform& sweptTrans, hkReal t, hkQuaternion& quatOut)
{
    hkVector4 rot0 = sweptTrans.m_rotation0.m_vec;
    hkVector4 rot1 = sweptTrans.m_rotation1.m_vec;
    {
        quatOut.m_vec.setAdd4(rot0, rot1);
        hkReal len2 = quatOut.m_vec.lengthSquared4();
        hkReal r = 0.75f - 0.125f * len2;
        r = r * (1.5f - 0.5f * len2 * r * r);
        quatOut.m_vec.mul4(r);
    }

    if (t < 0.5f)
    {
        quatOut.m_vec.setInterpolate4(rot0, quatOut.m_vec, 2.0f * t);
    }
    else
    {
        quatOut.m_vec.setInterpolate4(quatOut.m_vec, rot1, 2.0f * t - 1.0f);
    }
    quatOut.m_vec.normalize4();
}

// the whole transform at interpolation value t
__forceinline void _lerp2(const hkSweptTransform& sweptTrans, hkReal t, hkTransform& transformOut)
{
    hkQuaternion qt;
    _lerp2(sweptTrans, t, qt);

    transformOut.setRotation(qt);
    transformOut.getTranslation().setInterpolate4(sweptTrans.m_centerOfMass0, sweptTrans.m_centerOfMass1, t);

    hkVector4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().sub4(centerShift);
}

}  // namespace hkSweptTransformUtil

// pdb: hkSweptTransformUtil::lerp2Rel | hkSweptTransformUtil.obj | fnv360_0822_debug, objrun + skyrim(objrun), high
void __cdecl hkSweptTransformUtil_lerp2Rel(const hkSweptTransform& sweptTrans, hkReal r, hkTransform& transformOut)
{
    hkSweptTransformUtil::_lerp2(sweptTrans, r, transformOut);
}

}  // namespace f3m_009773a0
}   // namespace f3m_009773a0

// @f3 0x00977ab0 (community match, verified in this file)
#include <math.h>
namespace f3m_00977ab0 {
// 0x00977ab0: hkSweptTransformUtil::freezeMotionState(hkTime time, hkMotionState& motionState) of Havok 5.5.0
// (hkBase, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Freezes a motion state at the given time (not before its base time): both end rotations become the rotation
// interpolated at that time, both centres of mass the interpolated centre, the base time becomes the time and
// the inverse time step zero, and the transform is rebuilt from the frozen state.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, swept transform)
// follow the SDK's inline maths for the x87 build. The function's own body is written from the game's code.

namespace f3m_00977ab0 {

typedef float hkReal;
typedef hkReal hkTime;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }

template <typename T>
inline T max2(T x, T y)
{
    return x > y ? x : y;
}
}  // namespace hkMath

struct hkMatrix3;
struct hkRotation;

struct hkVector4
{
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }

    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt);
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
    __forceinline hkSimdReal dot4(const hkVector4& a) const;
    __forceinline hkSimdReal lengthSquared4() const;
    __forceinline hkSimdReal lengthInverse4() const;
    __forceinline void normalize4();

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
    // set(const hkQuaternion&)
    void hkRotation_set(const hkQuaternion& q);
};

struct hkTransform
{
    __forceinline void setRotation(const hkQuaternion& quatRotation) { m_rotation.hkRotation_set(quatRotation); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkSweptTransform
{
    __forceinline hkTime getBaseTime() const { return hkTime(m_centerOfMass0(3)); }
    __forceinline hkReal getInvDeltaTime() const { return m_centerOfMass1(3); }
    __forceinline hkReal getInterpolationValue(hkTime t) const
    {
        hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
        return dt;
    }

    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkQuaternion m_rotation0;
    hkQuaternion m_rotation1;
    hkVector4 m_centerOfMassLocal;
};

struct hkMotionState
{
    inline hkTransform& getTransform() { return m_transform; }
    inline hkSweptTransform& getSweptTransform() { return m_sweptTransform; }

    hkTransform m_transform;
    hkSweptTransform m_sweptTransform;
    hkVector4 m_deltaAngle;
    hkReal m_objectRadius;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x + v1.x;
    y = v0.y + v1.y;
    z = v0.z + v1.z;
    w = v0.w + v1.w;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
    hkReal t = hkReal(rt);
    hkReal s = 1.0f - t;
    hkVector4& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}

__forceinline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z) + (w * a.w);
}

__forceinline hkSimdReal hkVector4::lengthSquared4() const
{
    return this->dot4(*this);
}

__forceinline hkSimdReal hkVector4::lengthInverse4() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z) + (w * w);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize4()
{
    this->mul4(this->lengthInverse4());
}

namespace hkSweptTransformUtil {

// the rotation at interpolation value t: the midpoint of the two end rotations, roughly normalized, then
// interpolated with the nearer end and normalized
__forceinline void _lerp2(const hkSweptTransform& sweptTrans, hkReal t, hkQuaternion& quatOut)
{
    hkVector4 rot0 = sweptTrans.m_rotation0.m_vec;
    hkVector4 rot1 = sweptTrans.m_rotation1.m_vec;
    {
        quatOut.m_vec.setAdd4(rot0, rot1);
        hkReal len2 = quatOut.m_vec.lengthSquared4();
        hkReal r = 0.75f - 0.125f * len2;
        r = r * (1.5f - 0.5f * len2 * r * r);
        quatOut.m_vec.mul4(r);
    }

    if (t < 0.5f)
    {
        quatOut.m_vec.setInterpolate4(rot0, quatOut.m_vec, 2.0f * t);
    }
    else
    {
        quatOut.m_vec.setInterpolate4(quatOut.m_vec, rot1, 2.0f * t - 1.0f);
    }
    quatOut.m_vec.normalize4();
}

// the transform at the end of the step: the end rotation, and the end centre of mass minus the rotated local centre
__forceinline void calcTransAtT1(const hkSweptTransform& sweptTrans, hkTransform& transformOut)
{
    const hkQuaternion& qt = sweptTrans.m_rotation1;

    transformOut.setRotation(qt);

    hkVector4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

}  // namespace hkSweptTransformUtil

// pdb: hkSweptTransformUtil::freezeMotionState | hkSweptTransformUtil.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_gap), high
void __cdecl hkSweptTransformUtil_freezeMotionState(hkTime time, hkMotionState& motionState)
{
    hkSweptTransform& st = motionState.getSweptTransform();

    // the state is frozen at the earliest moment after its base time
    time = hkMath::max2(time, st.getBaseTime());
    hkReal t = st.getInterpolationValue(time);

    hkSweptTransformUtil::_lerp2(st, t, st.m_rotation1);
    st.m_rotation0 = st.m_rotation1;

    st.m_centerOfMass1.setInterpolate4(st.m_centerOfMass0, st.m_centerOfMass1, t);
    st.m_centerOfMass0 = st.m_centerOfMass1;

    // the time information
    st.m_centerOfMass0(3) = time;
    st.m_centerOfMass1(3) = 0.0f;

    hkSweptTransformUtil::calcTransAtT1(st, motionState.getTransform());
}

}  // namespace f3m_00977ab0
}   // namespace f3m_00977ab0

// @f3 0x0096ce80 (community match, verified in this file)
namespace f3m_0096ce80 {
// 0x0096ce80: hkMatrix3::setMul(const hkMatrix3& aTb, const hkMatrix3& bTc) of Havok 5.5.0 (hkBase, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// this = aTb * bTc: each column of bTc is rotated by a copy of aTb, the last column first; the copy makes it safe
// for the result to be bTc itself.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, the rotate-points
// loop) follow the SDK's inline maths for the x87 build. The function's own body is written from the game's code.
namespace f3m_0096ce80 {

typedef float hkReal;

struct hkMatrix3;

struct hkVector4
{
    __forceinline hkVector4() {}

    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkMatrix3() {}
    __forceinline hkMatrix3(const hkMatrix3& other);

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    // setMul
    void FUN_0096ce80(const hkMatrix3& aTb, const hkMatrix3& bTc);

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline hkMatrix3::hkMatrix3(const hkMatrix3& other)
{
    m_col0 = other.m_col0;
    m_col1 = other.m_col1;
    m_col2 = other.m_col2;
}

namespace hkVector4Util {
// rotates numVectors directions, the last one first; the matrix is copied so that the output may alias it
__forceinline void rotatePoints(const hkMatrix3& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkMatrix3 unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setMul3(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

// pdb: hkMatrix3::setMul | hkMatrix3.obj | fnv360_0822_debug, objrun_prop, low, conflict (bridge: hkMatrix3::transpose)
// pdb params: aTb, bTc
void hkMatrix3::FUN_0096ce80(const hkMatrix3& aTb, const hkMatrix3& bTc)
{
    hkVector4Util::rotatePoints(aTb, &bTc.getColumn(0), 3, &getColumn(0));
}

}  // namespace f3m_0096ce80
}   // namespace f3m_0096ce80

// @f3 0x0096cf70 (community match, verified in this file)
namespace f3m_0096cf70 {
// 0x0096cf70: hkMatrix3::setMulInverse(const hkMatrix3& aTb, const hkRotation& cTb) of Havok 5.5.0 (hkBase, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// this = aTb * inverse(cTb): the rotation's inverse is its transpose bTc (hkMatrix3::setTranspose, a call), and each
// column of bTc is rotated by a copy of aTb, the last column first.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, the rotate-points
// loop) follow the SDK's inline maths for the x87 build. The local bTc and the statements are those of the SDK's
// unoptimized library object of this function (its assert compiles out in the release build).
namespace f3m_0096cf70 {

typedef float hkReal;

struct hkMatrix3;
struct hkRotation;

struct hkVector4
{
    __forceinline hkVector4() {}

    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkMatrix3() {}
    __forceinline hkMatrix3(const hkMatrix3& other);

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    // setTranspose: this = the transpose of s
    void FUN_0096c450(const hkMatrix3& s);
    // setMulInverse
    void FUN_0096cf70(const hkMatrix3& aTb, const hkRotation& cTb);

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline hkMatrix3::hkMatrix3(const hkMatrix3& other)
{
    m_col0 = other.m_col0;
    m_col1 = other.m_col1;
    m_col2 = other.m_col2;
}

namespace hkVector4Util {
// rotates numVectors directions, the last one first; the matrix is copied so that the output may alias it
__forceinline void rotatePoints(const hkMatrix3& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkMatrix3 unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setMul3(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

// pdb: hkMatrix3::setMulInverse | hkMatrix3.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: aTb, cTb
void hkMatrix3::FUN_0096cf70(const hkMatrix3& aTb, const hkRotation& cTb)
{
    hkRotation bTc;
    bTc.FUN_0096c450(cTb);
    hkVector4Util::rotatePoints(aTb, &bTc.getColumn(0), 3, &getColumn(0));
}

}  // namespace f3m_0096cf70
}   // namespace f3m_0096cf70

// @f3 0x0096fd30 (community match, verified in this file)
#include <math.h>
namespace f3m_0096fd30 {
// 0x0096fd30: hkpCollideTriangleUtil::setupPointTriangleDistanceCache(const hkVector4* tri,
// PointTriangleDistanceCache& cache) of Havok 5.5.0 (hkpInternal, a static member, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Fills the cache for point-to-triangle distances: the three edge vectors E0 = t2 - t1, E1 = t0 - t2, E2 = t1 - t0
// and the normal E0 x E1, their squared lengths in one vector, the inverse square roots of those, and from them the
// inverse edge lengths, the inverse normal length and the normal length.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (setSub4, setCross with set and the
// element access, hkVector4Util::dot3_4vs4 with dot3, setSqrtInverse4 with hkMath::sqrtInverse and hkMath::sqrt)
// follow the SDK's inline code for the x87 build. The locals, their names and the statement order are those of the
// SDK's unoptimized library object of this function.

namespace f3m_0096fd30 {

typedef float hkReal;
typedef hkReal hkSimdReal;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}  // namespace hkMath

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline hkSimdReal dot3(const hkVector4& a) const;
    __forceinline void setSqrtInverse4(const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    return (x * a.x) + (y * a.y) + (z * a.z);
}

__forceinline void hkVector4::setSqrtInverse4(const hkVector4& v)
{
    x = hkMath::sqrtInverse(v.x);
    y = hkMath::sqrtInverse(v.y);
    z = hkMath::sqrtInverse(v.z);
    w = hkMath::sqrtInverse(v.w);
}

namespace hkVector4Util {
__forceinline void dot3_4vs4(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                             const hkVector4& a2, const hkVector4& b2, const hkVector4& a3, const hkVector4& b3,
                             hkVector4& dotsOut)
{
    dotsOut(0) = a0.dot3(b0);
    dotsOut(1) = a1.dot3(b1);
    dotsOut(2) = a2.dot3(b2);
    dotsOut(3) = a3.dot3(b3);
}
}  // namespace hkVector4Util

struct hkpCollideTriangleUtil
{
    struct PointTriangleDistanceCache
    {
        hkReal m_invEdgeLen[3];
        hkReal m_invNormalLen;
        hkReal m_normalLen;
    };

    // setupPointTriangleDistanceCache
    static void __cdecl FUN_0096fd30(const hkVector4* tri, PointTriangleDistanceCache& cache);
};

// pdb: hkpCollideTriangleUtil::setupPointTriangleDistanceCache | hkpCollideTriangleUtil.obj | tesv_win, caller, medium
void __cdecl hkpCollideTriangleUtil::FUN_0096fd30(const hkVector4* tri, PointTriangleDistanceCache& cache)
{
    hkVector4 E0; E0.setSub4(tri[2], tri[1]);
    hkVector4 E1; E1.setSub4(tri[0], tri[2]);
    hkVector4 E2; E2.setSub4(tri[1], tri[0]);

    hkVector4 triNormal; triNormal.setCross(E0, E1);

    // squared lengths of the three edges and of the normal
    hkVector4 dots; hkVector4Util::dot3_4vs4(E0, E0, E1, E1, E2, E2, triNormal, triNormal, dots);

    hkVector4 invSqrtDots; invSqrtDots.setSqrtInverse4(dots);

    cache.m_invEdgeLen[0] = invSqrtDots(0);
    cache.m_invEdgeLen[1] = invSqrtDots(1);
    cache.m_invEdgeLen[2] = invSqrtDots(2);

    cache.m_invNormalLen = invSqrtDots(3);
    cache.m_normalLen = invSqrtDots(3) * dots(3);
}

}  // namespace f3m_0096fd30
}   // namespace f3m_0096fd30

// @f3 0x00961f20 (community match, verified in this file)
// 0x00961f20: hkaRagdollInstance::getApproxWorldFromBoneTransformAt(int i, hkReal time, hkQsTransform& worldFromBoneOut)
// const of Havok 5.5.0 (hkaRagdoll, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The approximate world transform of bone i at a time: from the bone's rigid body (its motion's transform at that
// time, without scale, with the skeleton's model-space scale) when it has one, else recursively from the parent
// bone's (or the identity for a root) times the bone's reference pose.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself (and its recursive
// call) carries the packet's name; its callees keep the SDK's names.
namespace f3m_00961f20 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
	public:
		__forceinline hkSmallArray();
		explicit __forceinline hkSmallArray(int size);
		__forceinline ~hkSmallArray();
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		void clearAndDeallocate();
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
	public:
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkSweptTransform() { }
	public:
		__forceinline void _approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
class hkQsTransform
{
	public:
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}
inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}
inline void hkQuaternion::setIdentity()
{
	m_vec.set(0,0,0,1);
}
void hkQsTransform::setIdentity()
{
	m_translation.setZero4();
	m_rotation.setIdentity();
	m_scale.setAll(1.0f);
}
void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);
	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
			;
		}
		__forceinline bool isMarkedForWrite( )
		{
			return true;
		}
		__forceinline bool isMarkedForReadRecursive()
		{
			return true;
		}
		__forceinline void unmarkForRead( )
		{
			;
		}
		__forceinline void unmarkForWrite()
		{
			;
		}
		void disableChecks();
		void enableChecks();
		bool isCheckingEnabled() const;
		void accessCheck( AccessType type ) const;
		static void __cdecl accessCheckWithParent( const hkMultiThreadCheck* parentLock, AccessType parentType, const hkMultiThreadCheck& lock, AccessType type );
		static void staticInit();
		static class hkCriticalSection* m_criticalSection;
};
struct hkAabbUint32;
enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
class hkpWorld;
typedef hkUint32 hkpShapeKey;
class hkpShape;
class hkMotionState;
class hkpCdBody
{
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_KEYFRAMED,
	HK_COLLIDABLE_QUALITY_DEBRIS,
	HK_COLLIDABLE_QUALITY_MOVING,
	HK_COLLIDABLE_QUALITY_CRITICAL,
	HK_COLLIDABLE_QUALITY_BULLET,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpTypedBroadPhaseHandle( int type );
		__forceinline hkpTypedBroadPhaseHandle( void* owner, int type );
		__forceinline int getType() const;
		__forceinline void setOwner(void* o);
		__forceinline void* getOwner() const;
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		hkpTypedBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ) : hkpBroadPhaseHandle(flag) {}
	protected:
		enum { OFFSET_INVALID = 127 };
		inline void setType( int type );
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline hkpCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpCollidable();
		inline const hkpShape* getShape() const;
		inline void setShape(const hkpShape* shape);
		inline void setOwner( void* owner );
		inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
		void checkPerformance();
		inline const hkpTypedBroadPhaseHandle* getBroadPhaseHandle() const;
		inline       hkpTypedBroadPhaseHandle* getBroadPhaseHandle();
		__forceinline hkpCollidableQualityType getQualityType() const;
		__forceinline void setQualityType(hkpCollidableQualityType type);
		__forceinline hkReal getAllowedPenetrationDepth() const;
		__forceinline void setAllowedPenetrationDepth( hkReal val );
	public:
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		__forceinline int getType() const;
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				BoundingVolumeData();
				__forceinline const hkAabbUint32& getAabbUint32() const { return reinterpret_cast<const hkAabbUint32&>(m_min); }
				__forceinline       hkAabbUint32& getAabbUint32()		  { return reinterpret_cast<      hkAabbUint32&>(m_min); }
				__forceinline void invalidate() { m_min[0] = 1; m_max[0] = 0; }
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpLinkedCollidable();
		inline hkpLinkedCollidable( class hkFinishLoadedObjectFlag flag ) : hkpCollidable(flag) {}
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};
struct hkpPropertyValue;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void addProperty( hkUint32 key, hkpPropertyValue value );
		hkpPropertyValue removeProperty( hkUint32 key );
		void editProperty( hkUint32 key, hkpPropertyValue value );
		inline hkpPropertyValue getProperty( hkUint32 key ) const;
		inline hkBool hasProperty( hkUint32 key ) const;
		void lockProperty( hkUint32 key );
		void unlockProperty( hkUint32 key );
		inline void unlockPropertiesFromLoadedObject();
		inline void clearAndDeallocateProperties();
		inline hkpCollidable* getCollidableRw();
		inline const hkpCollidable* getCollidable() const;
		inline hkpLinkedCollidable* getLinkedCollidable();
		inline const hkpLinkedCollidable* getLinkedCollidable() const;
		inline const hkpLinkedCollidable* getCollidableMtUnchecked() const;
		inline hkBool isAddedToWorld() const;
		inline hkpWorld* getWorld() const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline const char* getName() const;
		inline void setName( const char* name );
		void calcStatistics( hkStatisticsCollector* collector ) const;
		virtual hkWorldOperation::Result setShape( const hkpShape* shape );
		inline void markForRead( );
		inline void markForWrite( );
		void markForWriteImpl( );
		inline void unmarkForRead( );
		inline void unmarkForWrite();
		void checkReadWrite();
		void checkReadOnly() const;
		void addReference();
		void removeReference();
		void addReferenceAsCriticalOperation();
		void removeReferenceAsCriticalOperation();
	public:
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		inline void setWorld( hkpWorld* world );
		virtual class hkMotionState* getMotionState() = 0;
		hkpWorldObject( const hkpShape* shape, BroadPhaseType type );
		inline virtual ~hkpWorldObject();
	public:
		inline hkMultiThreadCheck& getMultiThreadCheck();
		inline const hkMultiThreadCheck& getMultiThreadCheck() const;
		inline void copyProperties( const hkpWorldObject* otherObj );
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
class hkpMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpMaterial();
		inline hkReal getFriction() const;
		inline hkReal getRestitution() const;
		inline void setFriction( hkReal newFriction );
		inline void setRestitution( hkReal newRestitution );
		static inline hkReal __cdecl getCombinedFriction( hkReal frictionA, hkReal frictionB);
		static inline hkReal __cdecl getCombinedRestitution( hkReal restitutionA, hkReal restitutionB);
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
		inline void setResponseType( enum hkpMaterial::ResponseType t );
		inline enum hkpMaterial::ResponseType getResponseType() const;
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
	public:
		hkpMaterial( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpConstraintData;
class hkpEntity;
class hkpRigidBody;
class hkpConstraintOwner;
class hkpSimulationIsland;
typedef void hkpConstraintRuntime;
class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
		enum AddReferences
		{
			DO_NOT_ADD_REFERENCES,
			DO_ADD_REFERENCES
		};
		enum CloningMode
		{
			CLONE_INSTANCES_ONLY,
			CLONE_DATAS_WITH_MOTORS
		};
		hkpConstraintInstance(hkpEntity* entityA, hkpEntity* entityB, hkpConstraintData* data, ConstraintPriority priority = PRIORITY_PSI);
		~hkpConstraintInstance();
		hkpConstraintInstance* clone(hkpEntity* newEntityA, hkpEntity* newEntityB, CloningMode mode = CLONE_INSTANCES_ONLY) const;
	protected:
		hkpConstraintInstance(ConstraintPriority priority);
	public:
		inline hkpEntity* getEntityA() const;
		inline hkpEntity* getEntity( int index ) const;
		inline hkpEntity* getEntityB() const;
		inline hkpRigidBody* getRigidBodyA() const;
		inline hkpRigidBody* getRigidBodyB() const;
		inline hkpEntity* getOtherEntity( const hkpEntity* entity );
		hkpSimulationIsland* getSimulationIsland();
		inline hkpConstraintData* getData() const;
		inline hkpConstraintRuntime* getRuntime() const;
		inline void setWantRuntime( hkBool b );
		inline hkBool getWantRuntime() const ;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline ConstraintPriority getPriority() const;
		void setPriority( ConstraintPriority priority );
		inline const char* getName() const;
		inline void setName( const char* name );
	public:
		inline hkpConstraintOwner* getOwner() const;
		inline hkpEntity* getMasterEntity() const;
		inline hkpEntity* getSlaveEntity() const;
		virtual void entityAddedCallback(hkpEntity* entity);
		virtual void entityRemovedCallback(hkpEntity* entity);
		virtual void entityDeletedCallback( hkpEntity* entity );
		inline void setOwner( hkpConstraintOwner* island );
		inline struct hkConstraintInternal* getInternal();
		void pointNullsToFixedRigidBody();
		void setFixedRigidBodyPointersToZero( hkpWorld* world );
		virtual InstanceType getType() const { return TYPE_NORMAL; }
	protected:
		friend class hkpSimpleContactConstraintData;
		friend class hkpSimulationIsland;
		class hkpConstraintOwner* m_owner;
		class hkpConstraintData*  m_data;
		struct hkpModifierConstraintAtom* m_constraintModifiers;
		class hkpEntity* m_entities[2];
	public:
		hkEnum<ConstraintPriority,hkUint8> m_priority;
	protected:
		hkBool				m_wantRuntime;
		const char* m_name;
	public:
		hkUlong m_userData;
		struct hkConstraintInternal* m_internal;
	public:
		hkpConstraintInstance(hkFinishLoadedObjectFlag f) { }
	private:
		friend class hkpWorldConstraintUtil;
		friend class hkpSimpleConstraintContactMgr;
		friend class hkpSaveContactPointsUtil;
		hkpConstraintInstance(){}
};
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	inline MotionType getType() const { return m_type; }
	hkpMotion(const hkVector4& position, const hkQuaternion& rotation, bool wantDeactivation = false);
	hkReal getMass() const;
	inline hkSimdReal getMassInv() const;
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	inline const hkVector4& getCenterOfMassLocal() const;
	inline const hkVector4& getCenterOfMassInWorld() const;
	inline hkMotionState* getMotionState();
	inline const hkMotionState* getMotionState() const;
	inline const hkVector4& getPosition() const;
	virtual void setPosition(const hkVector4& position);
	inline const hkQuaternion& getRotation() const;
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline const hkTransform& getTransform() const;
	void approxTransformAt( hkTime time, hkTransform& transformOut );
	virtual void setTransform(const hkTransform& transform);
	inline const hkVector4& getLinearVelocity() const;
	virtual void setLinearVelocity(const hkVector4& newVel);
	inline const hkVector4& getAngularVelocity() const;
	virtual void setAngularVelocity(const hkVector4& newVel);
	__forceinline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
	inline hkReal getLinearDamping();
	inline void setLinearDamping( hkReal d );
	inline hkReal getAngularDamping();
	inline void setAngularDamping( hkReal d );
	inline int getDeactivationClass();
	void setDeactivationClass(int deactivationClass);
	inline void enableDeactivation( bool value, int randomNumber = 0, int worldFlag0 = 0, int worldFlag1 = 0, int worldDeactivationIntegrateCounter = 0);
	inline bool isActivationEnabled() const;
public:
	virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
	inline int getNumInactiveFrames(int select);
	inline int getNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
	inline void setWorldSelectFlagsNeg(int worldFlag0, int worldFlag1, int worldDeactivationIntegrateCounter);
	inline void incrementNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
	inline void zeroNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
public:
	enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );
		virtual ~hkpKeyframedRigidMotion();
		virtual void setMass(hkReal m);
		virtual void setMassInv(hkReal mInv);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	protected:
		hkpKeyframedRigidMotion(): hkpMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = 0; }
	public:
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
	public:
		hkpKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpMaxSizeMotion() : hkpKeyframedRigidMotion( ) {}
		hkpMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkpKeyframedRigidMotion( flag ) {}
	private:
		void operator=(const hkpMaxSizeMotion& other);
		hkpMaxSizeMotion( const hkpMaxSizeMotion& other );
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkpDynamicsContactMgr;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpEntity();
		void addEntityListener( hkpEntityListener* el);
		void removeEntityListener( hkpEntityListener* el);
		void addEntityActivationListener( hkpEntityActivationListener* el);
		void removeEntityActivationListener( hkpEntityActivationListener* el);
		void addCollisionListener( hkpCollisionListener* cl );
		void removeCollisionListener( hkpCollisionListener* cl);
		inline const hkSmallArray<hkpEntityListener*>& getEntityListeners() const;
		inline const hkSmallArray<hkpEntityActivationListener*>& getEntityActivationListeners() const;
		inline const hkSmallArray<hkpCollisionListener*>& getCollisionListeners() const;
		inline bool areCollisionListenersAdded() const;
		inline hkUint16 getProcessContactCallbackDelay() const;
		inline void setProcessContactCallbackDelay( hkUint16 delay );
		inline hkpMaterial& getMaterial();
		inline const hkpMaterial& getMaterial() const;
		inline hkBool isFixed() const;
		inline hkBool isFixedOrKeyframed() const;
		inline hkUint32 getUid() const;
		hkpDynamicsContactMgr* findContactMgrTo(const hkpEntity* entity) const;
		void activate();
		void deactivate();
		void activateAsCriticalOperation();
		void deactivateAsCriticalOperation();
		hkBool isActive() const;
		inline int getNumActions() const;
		inline hkpAction* getAction(int i);
		int getNumConstraints() const;
		hkpConstraintInstance* getConstraint( int i );
		const hkpConstraintInstance* getConstraint( int i ) const;
		inline const hkSmallArray<struct hkConstraintInternal>&  getConstraintMasters() const;
		inline hkSmallArray<struct hkConstraintInternal>&  getConstraintMastersRw();
		inline const hkArray<class hkpConstraintInstance*>&  getConstraintSlaves() const;
		void calcStatistics( hkStatisticsCollector* collector) const;
		void setCachedShapeData(const hkpWorld* world, const hkpShape* shape);
		void updateCachedAabb();
	protected:
		const	hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersImpl() const;
				hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersRwImpl();
		const	hkArray<class hkpConstraintInstance*>&	getConstraintSlavesImpl() const;
		hkpEntity( const hkpShape* shape );
	public:
		hkpEntity( class hkFinishLoadedObjectFlag flag );
		inline hkpMotion* getMotion();
		inline hkpSimulationIsland* getSimulationIsland() const;
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SpuCollisionCallback():
				m_util(0),
				m_capacity(0),
				m_eventFilter(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
				m_userFilter(0x01)
			{
			}
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};
class hkpEntityDeactivator : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool shouldDeactivateHighFrequency( const hkpEntity* entity ) = 0;
		virtual hkBool shouldDeactivateLowFrequency( const hkpEntity* entity ) = 0;
	protected:
		hkpEntityDeactivator() {}
	public:
		hkpEntityDeactivator( class hkFinishLoadedObjectFlag flag ) {}
};
class hkpRigidBodyDeactivator : public hkpEntityDeactivator
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum DeactivatorType
		{
			DEACTIVATOR_INVALID,
			DEACTIVATOR_NEVER,
			DEACTIVATOR_SPATIAL,
			DEACTIVATOR_MAX_ID
		};
		virtual enum DeactivatorType getRigidBodyDeactivatorType() const = 0;
};
class hkpRigidBodyCinfo;
class hkpRigidBody : public hkpEntity
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpRigidBody( const hkpRigidBodyCinfo& info );
		virtual ~hkpRigidBody();
		void getCinfo(hkpRigidBodyCinfo& info) const;
		inline hkReal getMass() const;
		inline hkReal getMassInv() const;
		void setMass(hkReal m);
		void setMassInv(hkReal mInv);
		inline void getInertiaLocal(hkMatrix3& inertiaOut) const;
		inline void getInertiaWorld(hkMatrix3& inertiaOut) const;
		void setInertiaLocal(const hkMatrix3& inertia);
		void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		inline void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		inline void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		void setCenterOfMassLocal(const hkVector4& centerOfMass);
		inline const hkVector4& getCenterOfMassLocal() const;
		inline const hkVector4& getCenterOfMassInWorld() const;
		inline const hkVector4& getPosition() const;
		void setPosition(const hkVector4& position);
		inline const hkQuaternion& getRotation() const;
		void setRotation(const hkQuaternion& rotation);
		void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
		inline const hkTransform& getTransform() const;
		void setTransform(const hkTransform& transform);
		void setPositionAndRotationAsCriticalOperation(const hkVector4& position, const hkQuaternion& rotation);
		inline void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		inline void approxCurrentTransform( hkTransform& transformOut ) const;
		inline const hkVector4& getLinearVelocity() const;
		inline void	setLinearVelocity(const hkVector4& newVel);
		inline const hkVector4& getAngularVelocity() const;
		inline void	setAngularVelocity(const hkVector4& newVel);
		inline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
	public:
		inline hkpMotion* getRigidMotion() const;
		void checkPerformance() const;
	public:
		static void __cdecl createDynamicRigidMotion( hkpMotion::MotionType motionType,
																const hkVector4& position, const hkQuaternion& rotation,
																hkReal mass, const hkMatrix3& inertiaLocal, const hkVector4& centreOfMassLocal,
																hkReal maxLinearVelocity, hkReal maxAngularVelocity,
																hkpMaxSizeMotion* motionBufferOut );
		static void __cdecl updateBroadphaseAndResetCollisionInformationOfWarpedBody( hkpEntity* entity );
	protected:
		virtual hkMotionState* getMotionState();
	public:
		hkpRigidBody( class hkFinishLoadedObjectFlag flag ) : hkpEntity( flag ) {}
};
inline hkpMotion* hkpRigidBody::getRigidMotion() const
{
	return const_cast<hkpMaxSizeMotion*>(&m_motion);
}
void hkpRigidBody::approxTransformAt( hkTime time, hkTransform& transformOut ) const
{
	getRigidMotion()->approxTransformAt( time, transformOut );
}
class hkaBone;
class hkaSkeleton
{
	public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkaSkeleton();
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int		m_numReferencePose;
		char**	m_floatSlots;
		hkInt32 m_numFloatSlots;
	public:
		__forceinline hkaSkeleton( hkFinishLoadedObjectFlag flag ) {}
};
typedef int (__cdecl* hkStringCompareFunc)(const char*, const char*);
class hkaSkeletonUtils
{
	public:
		static void __cdecl blendPoses( hkUint32 numBones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal* weights, hkQsTransform* poseOut );
		static void __cdecl blendPoses( hkUint32 numBones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal weight, hkQsTransform* poseOut );
		static void __cdecl enforceSkeletonConstraintsLocalSpace(const hkaSkeleton& skeleton, hkQsTransform* poseLocalInOut);
		static void __cdecl enforceSkeletonConstraintsModelSpace(const hkaSkeleton& skeleton, hkQsTransform* poseModelInOut);
		static void __cdecl enforcePoseConstraintsLocalSpace (const hkaSkeleton& skeleton, const hkQsTransform* constraintsLocal, hkQsTransform* poseInOut);
		static void __cdecl enforcePoseConstraintsModelSpace (const hkaSkeleton& skeleton, const hkQsTransform* constraintsLocal, hkQsTransform* poseModelInOut);
		static hkInt16 __cdecl findBoneWithName (const hkaSkeleton& skeleton, const char* name, hkStringCompareFunc compare = 0);
		static void __cdecl lockTranslations (const hkaSkeleton& skeleton, hkBool exceptRoots = true);
		static void __cdecl unlockTranslations (const hkaSkeleton& skeleton);
		static hkBool __cdecl getBoneChain(const hkaSkeleton& skeleton, hkInt16 startBone, hkInt16 endBone, hkArray<hkInt16>& bonesOut);
		static void __cdecl getDescendants(const hkaSkeleton& skeleton, hkInt16 startBone, hkArray<hkInt16>& bonesOut);
		static void __cdecl getLeaves(const hkaSkeleton& skeleton, hkArray<hkInt16>& leavesOut);
		static hkBool __cdecl isBindingOk( const hkaSkeleton& skeleton, const class hkaAnimationBinding& binding );
		static void __cdecl getModelSpaceScale (const hkaSkeleton& skeleton, const hkQsTransform* poseLocal, int boneId, hkVector4& scaleOut);
		static void __cdecl normalizeRotations(hkQsTransform* transformsInOut, int numTransforms );
};
class hkaRagdollInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkaRagdollInstance ( const hkArray<hkpRigidBody*>& rigidBodies, const hkArray<hkpConstraintInstance*>& constraints, const hkaSkeleton* skeleton );
		virtual ~hkaRagdollInstance ();
		virtual hkaRagdollInstance* clone(hkpConstraintInstance::CloningMode mode = hkpConstraintInstance::CLONE_INSTANCES_ONLY) const;
		inline int getNumBones () const;
		inline hkpRigidBody* getRigidBodyOfBone (int i) const;
		inline int getBoneIndexOfRigidBody (hkpRigidBody* rb) const;
		inline hkpConstraintInstance* getConstraintOfBone (int i) const;
		inline const hkaSkeleton* getSkeleton () const;
		inline int getParentOfBone (int i) const;
		inline const hkArray<hkpRigidBody*>& getRigidBodyArray() const;
		inline const hkArray<hkpConstraintInstance*>& getConstraintArray() const;
		inline hkBool hasNonRigidBodyBones () const;
		void getPoseWorldSpace (hkQsTransform* poseWorldSpaceOut) const;
		void setPoseWorldSpace (const hkQsTransform* poseModelSpaceIn);
		void getPoseModelSpace (hkQsTransform* poseModelSpaceOut, const hkQsTransform& worldFromModel) const;
		void setPoseModelSpace (const hkQsTransform* poseModelSpaceIn, const hkQsTransform& worldFromModel);
		void setPoseAndVelocitiesModelSpace ( const hkQsTransform* poseModelSpaceA, const hkQsTransform& worldFromModelA,
											const hkQsTransform* poseModelSpaceB, const hkQsTransform& worldFromModelB, hkReal timestep);
		hkResult addToWorld (hkpWorld* world, hkBool updateFilter) const;
		hkResult removeFromWorld () const;
		inline hkpWorld* getWorld() const;
		void getWorldFromBoneTransform (int i, hkQsTransform& worldFromBoneOut) const;
		void FUN_00961f20 (int i, hkReal time, hkQsTransform& worldFromBoneOut) const;
	public:
		 hkArray<hkpRigidBody*> m_rigidBodies;
		 hkArray<hkpConstraintInstance*> m_constraints;
		 hkArray<int> m_boneToRigidBodyMap;
		const hkaSkeleton* m_skeleton;
	public:
		hkaRagdollInstance( hkFinishLoadedObjectFlag f ) : m_rigidBodies(f), m_constraints(f), m_boneToRigidBodyMap(f) { }
	private:
		void commonInit (const hkArray<hkpRigidBody*>& rigidBodies, const hkArray<hkpConstraintInstance*>& constraints, const hkaSkeleton* skeleton);
};
hkpRigidBody* hkaRagdollInstance::getRigidBodyOfBone (int i) const
{
	const int rbIdx = m_boneToRigidBodyMap[i];
	return (rbIdx<0) ? 0 : m_rigidBodies[rbIdx];
}
void hkaRagdollInstance::FUN_00961f20( int i, hkReal time, hkQsTransform& worldFromBoneOut ) const
{
	const hkpRigidBody* rbody = getRigidBodyOfBone(i);
	if (rbody)
	{
		hkTransform tOut; rbody->approxTransformAt( time, tOut );
		worldFromBoneOut.setFromTransformNoScale( tOut );
		hkaSkeletonUtils::getModelSpaceScale( *m_skeleton, m_skeleton->m_referencePose, i, worldFromBoneOut.m_scale );
	}
	else
	{
		const int parentIdx = m_skeleton->m_parentIndices[i];
		hkQsTransform worldFromParent;
		if (parentIdx >= 0)
		{
			FUN_00961f20( parentIdx, time, worldFromParent );
		}
		else
		{
			worldFromParent.setIdentity();
		}
		const hkQsTransform& parentFromBone = m_skeleton->m_referencePose[i];
		worldFromBoneOut.setMul( worldFromParent, parentFromBone );
	}
}

}  // namespace f3m_00961f20

// @f3 0x00960090 (community match, verified in this file)
#include <math.h>
namespace f3m_00960090 {
// 0x00960090: hkaPoseMatchingUtility::computeOrientation(const hkQsTransform* poseModelSpace, hkQuaternion& frameOut)
// const of Havok 5.5.0 (hkaRagdoll, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The orientation of a pose for pose matching: from the model-space positions of three bones, the body axis
// (root to other bone) and a second axis (root to the third bone), both normalized; up = second x body axis,
// right = up x body axis, up again = body axis x right (all normalized where they are new), and the frame is the
// rotation with the columns right, up and the body axis, as a quaternion.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (setSub4, setCross with set and the
// element access, normalize3 through mul4 and lengthInverse3 with hkMath::sqrtInverse, the matrix's setCols, the
// quaternion built from a rotation and assigned) follow the SDK's inline code for the x87 build. The locals, their
// names and the statement order are those of the SDK's unoptimized library object of this function.

namespace f3m_00960090 {

typedef float hkReal;
typedef short hkInt16;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}  // namespace hkMath

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v);
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();

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

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize3()
{
    this->mul4(this->lengthInverse3());
}

struct hkMatrix3
{
    __forceinline void setCols(const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

__forceinline void hkMatrix3::setCols(const hkVector4& r0, const hkVector4& r1, const hkVector4& r2)
{
    m_col0 = r0;
    m_col1 = r1;
    m_col2 = r2;
}

struct hkRotation : hkMatrix3
{
};

struct hkQuaternion
{
    explicit __forceinline hkQuaternion(const hkRotation& r) { FUN_00924360(r); }

    // set from a rotation
    void FUN_00924360(const hkRotation& r);

    hkVector4 m_vec;
};

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct hkaPoseMatchingUtility
{
    struct CandidatePoseInfo;

    // computeOrientation
    void FUN_00960090(const hkQsTransform* poseModelSpace, hkQuaternion& frameOut) const;

    hkArray<CandidatePoseInfo> m_candidatePoses;
    hkVector4 m_rotationAxis;
    hkInt16 m_rootBoneIdx;     // bone to match
    hkInt16 m_otherBoneIdx;    // main body axis
    hkInt16 m_anotherBoneIdx;  // another axis
};

// pdb: hkaPoseMatchingUtility::computeOrientation | hkaPoseMatchingUtility.obj | tesv_win, call_seq, medium
void hkaPoseMatchingUtility::FUN_00960090(const hkQsTransform* poseModelSpace, hkQuaternion& frameOut) const
{
    hkVector4 rootRagdoll = poseModelSpace[m_rootBoneIdx].m_translation;
    hkVector4 otherRagdoll = poseModelSpace[m_otherBoneIdx].m_translation;
    hkVector4 anotherRagdoll = poseModelSpace[m_anotherBoneIdx].m_translation;

    hkVector4 bodyAxis; bodyAxis.setSub4(otherRagdoll, rootRagdoll);
    bodyAxis.normalize3();

    hkVector4 otherAxis; otherAxis.setSub4(anotherRagdoll, rootRagdoll);
    otherAxis.normalize3();

    hkVector4 up; up.setCross(otherAxis, bodyAxis);
    up.normalize3();

    hkVector4 right; right.setCross(up, bodyAxis);
    right.normalize3();
    up.setCross(bodyAxis, right);

    hkRotation r; r.setCols(right, up, bodyAxis);
    frameOut = hkQuaternion(r);
}

}  // namespace f3m_00960090
}   // namespace f3m_00960090

// @f3 0x00961550 (community match, verified in this file)
// 0x00961550: hkaRagdollInstance::setPoseAndVelocitiesModelSpace(const hkQsTransform* poseModelSpaceA,
// const hkQsTransform& worldFromModelA, const hkQsTransform* poseModelSpaceB, const hkQsTransform& worldFromModelB,
// hkReal timestep) of Havok 5.5.0 (hkaRagdoll, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Puts the ragdoll into pose B and gives every body the velocities that move it from pose A to pose B in timestep:
// for every bone with a rigid body, the body's transform is worldFromModelB * poseModelSpaceB[bone]; its linear
// velocity is the difference of the two translations divided by timestep, its angular velocity the axis of the
// rotation from A to B times its angle divided by timestep (zero when that rotation has no valid axis).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself carries the packet's
// name; its callees keep the SDK's names.
namespace f3m_00961550 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
	public:
		__forceinline hkSmallArray();
		explicit __forceinline hkSmallArray(int size);
		__forceinline ~hkSmallArray();
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		void clearAndDeallocate();
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
	public:
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl acos(     double _X);
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float acosf(     float _X)
        {return ((float)acos((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
inline hkReal __cdecl acos(hkReal r)
	{
		;
		if( hkMath::fabs(r) >= 1.0f )
		{
			r = ( r>0 )	? 0 : 3.14159265358979f;
			return r;
		}
		return acosf(r);
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkSweptTransform() { }
	public:
		__forceinline void _approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
class hkQsTransform
{
	public:
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}
inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}
inline hkReal hkQuaternion::getAngle() const
{
	hkReal angle = hkMath::fabs( m_vec(3) );
	angle = hkMath::acos(angle);
	angle *= 2.0f;
	return(angle);
}
inline hkBool hkQuaternion::hasValidAxis() const
{
	return m_vec.length3() > 1.192092896e-07F;
}
inline void hkQuaternion::getAxis(hkVector4 &axis) const
{
	;
	axis = m_vec;
	axis.normalize3();
	if(m_vec(3) < 0.0f)
	{
		axis.setNeg4(axis);
	}
}
const hkVector4& hkQsTransform::getTranslation() const
{
	return m_translation;
}
const hkQuaternion& hkQsTransform::getRotation() const
{
	return m_rotation;
}
void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);
	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
			;
		}
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
struct hkAabbUint32;
enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
class hkpWorld;
typedef hkUint32 hkpShapeKey;
class hkpShape;
class hkMotionState;
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpCdBody(  ){}
		friend class hkpCollidable;
		__forceinline hkpCdBody( const hkpShape* shape, const hkMotionState* motionState );
		__forceinline hkpCdBody( const hkpShape* shape, const hkTransform* t );
		__forceinline hkpCdBody( const hkpCdBody& body ){}
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
		__forceinline const hkpCollidable* getRootCollidable() const;
		__forceinline hkpShapeKey getShapeKey() const ;
		__forceinline const hkpCdBody* getParent() const;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkMotionState* ms );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkTransform* t );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
		__forceinline const hkMotionState* getMotionState() const;
		__forceinline void setMotionState( const hkMotionState* state );
		__forceinline void setTransform( const hkTransform* t );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_KEYFRAMED,
	HK_COLLIDABLE_QUALITY_DEBRIS,
	HK_COLLIDABLE_QUALITY_MOVING,
	HK_COLLIDABLE_QUALITY_CRITICAL,
	HK_COLLIDABLE_QUALITY_BULLET,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpTypedBroadPhaseHandle( int type );
		__forceinline hkpTypedBroadPhaseHandle( void* owner, int type );
		__forceinline int getType() const;
		__forceinline void setOwner(void* o);
		__forceinline void* getOwner() const;
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		hkpTypedBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ) : hkpBroadPhaseHandle(flag) {}
	protected:
		enum { OFFSET_INVALID = 127 };
		inline void setType( int type );
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline hkpCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpCollidable();
		inline const hkpShape* getShape() const;
		inline void setShape(const hkpShape* shape);
		inline void setOwner( void* owner );
		inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
		void checkPerformance();
		inline const hkpTypedBroadPhaseHandle* getBroadPhaseHandle() const;
		inline       hkpTypedBroadPhaseHandle* getBroadPhaseHandle();
		__forceinline hkpCollidableQualityType getQualityType() const;
		__forceinline void setQualityType(hkpCollidableQualityType type);
		__forceinline hkReal getAllowedPenetrationDepth() const;
		__forceinline void setAllowedPenetrationDepth( hkReal val );
	public:
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		__forceinline int getType() const;
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				BoundingVolumeData();
				__forceinline const hkAabbUint32& getAabbUint32() const { return reinterpret_cast<const hkAabbUint32&>(m_min); }
				__forceinline       hkAabbUint32& getAabbUint32()		  { return reinterpret_cast<      hkAabbUint32&>(m_min); }
				__forceinline void invalidate() { m_min[0] = 1; m_max[0] = 0; }
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpLinkedCollidable();
		inline hkpLinkedCollidable( class hkFinishLoadedObjectFlag flag ) : hkpCollidable(flag) {}
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};
struct hkpPropertyValue;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
		inline const char* getName() const;
		inline void setName( const char* name );
		void calcStatistics( hkStatisticsCollector* collector ) const;
		virtual hkWorldOperation::Result setShape( const hkpShape* shape );
		inline void markForRead( );
		inline void markForWrite( );
		void markForWriteImpl( );
		inline void unmarkForRead( );
		inline void unmarkForWrite();
		void checkReadWrite();
		void checkReadOnly() const;
		void addReference();
		void removeReference();
		void addReferenceAsCriticalOperation();
		void removeReferenceAsCriticalOperation();
	public:
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		inline void setWorld( hkpWorld* world );
		virtual class hkMotionState* getMotionState() = 0;
		hkpWorldObject( const hkpShape* shape, BroadPhaseType type );
		inline virtual ~hkpWorldObject();
	public:
		inline hkMultiThreadCheck& getMultiThreadCheck();
		inline const hkMultiThreadCheck& getMultiThreadCheck() const;
		inline void copyProperties( const hkpWorldObject* otherObj );
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
class hkpMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpMaterial();
		inline hkReal getFriction() const;
		inline hkReal getRestitution() const;
		inline void setFriction( hkReal newFriction );
		inline void setRestitution( hkReal newRestitution );
		static inline hkReal __cdecl getCombinedFriction( hkReal frictionA, hkReal frictionB);
		static inline hkReal __cdecl getCombinedRestitution( hkReal restitutionA, hkReal restitutionB);
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
		inline void setResponseType( enum hkpMaterial::ResponseType t );
		inline enum hkpMaterial::ResponseType getResponseType() const;
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
	public:
		hkpMaterial( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpConstraintData;
class hkpEntity;
class hkpRigidBody;
class hkpConstraintOwner;
class hkpSimulationIsland;
typedef void hkpConstraintRuntime;
class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
		enum AddReferences
		{
			DO_NOT_ADD_REFERENCES,
			DO_ADD_REFERENCES
		};
		enum CloningMode
		{
			CLONE_INSTANCES_ONLY,
			CLONE_DATAS_WITH_MOTORS
		};
		hkpConstraintInstance(hkpEntity* entityA, hkpEntity* entityB, hkpConstraintData* data, ConstraintPriority priority = PRIORITY_PSI);
		~hkpConstraintInstance();
		hkpConstraintInstance* clone(hkpEntity* newEntityA, hkpEntity* newEntityB, CloningMode mode = CLONE_INSTANCES_ONLY) const;
	protected:
		hkpConstraintInstance(ConstraintPriority priority);
	public:
		inline hkpEntity* getEntityA() const;
		inline hkpEntity* getEntity( int index ) const;
		inline hkpEntity* getEntityB() const;
		inline hkpRigidBody* getRigidBodyA() const;
		inline hkpRigidBody* getRigidBodyB() const;
		inline hkpEntity* getOtherEntity( const hkpEntity* entity );
	private:
		friend class hkpWorldConstraintUtil;
		friend class hkpSimpleConstraintContactMgr;
		friend class hkpSaveContactPointsUtil;
		hkpConstraintInstance(){}
};
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	inline MotionType getType() const { return m_type; }
	hkpMotion(const hkVector4& position, const hkQuaternion& rotation, bool wantDeactivation = false);
	hkReal getMass() const;
	inline hkSimdReal getMassInv() const;
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	inline const hkVector4& getCenterOfMassLocal() const;
	inline const hkVector4& getCenterOfMassInWorld() const;
	inline hkMotionState* getMotionState();
	inline const hkMotionState* getMotionState() const;
	inline const hkVector4& getPosition() const;
	virtual void setPosition(const hkVector4& position);
	inline const hkQuaternion& getRotation() const;
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline const hkTransform& getTransform() const;
	void approxTransformAt( hkTime time, hkTransform& transformOut );
	virtual void setTransform(const hkTransform& transform);
	inline const hkVector4& getLinearVelocity() const;
	virtual void setLinearVelocity(const hkVector4& newVel);
	inline const hkVector4& getAngularVelocity() const;
	virtual void setAngularVelocity(const hkVector4& newVel);
	__forceinline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );
		virtual ~hkpKeyframedRigidMotion();
		virtual void setMass(hkReal m);
		virtual void setMassInv(hkReal mInv);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	protected:
		hkpKeyframedRigidMotion(): hkpMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = 0; }
	public:
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
	public:
		hkpKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpMaxSizeMotion() : hkpKeyframedRigidMotion( ) {}
		hkpMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkpKeyframedRigidMotion( flag ) {}
	private:
		void operator=(const hkpMaxSizeMotion& other);
		hkpMaxSizeMotion( const hkpMaxSizeMotion& other );
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkpDynamicsContactMgr;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpEntity();
		void addEntityListener( hkpEntityListener* el);
		void removeEntityListener( hkpEntityListener* el);
		void addEntityActivationListener( hkpEntityActivationListener* el);
		void removeEntityActivationListener( hkpEntityActivationListener* el);
		void addCollisionListener( hkpCollisionListener* cl );
		void removeCollisionListener( hkpCollisionListener* cl);
		inline const hkSmallArray<hkpEntityListener*>& getEntityListeners() const;
		inline const hkSmallArray<hkpEntityActivationListener*>& getEntityActivationListeners() const;
		inline const hkSmallArray<hkpCollisionListener*>& getCollisionListeners() const;
		inline bool areCollisionListenersAdded() const;
		inline hkUint16 getProcessContactCallbackDelay() const;
		inline void setProcessContactCallbackDelay( hkUint16 delay );
		inline hkpMaterial& getMaterial();
		inline const hkpMaterial& getMaterial() const;
		inline hkBool isFixed() const;
		inline hkBool isFixedOrKeyframed() const;
		inline hkUint32 getUid() const;
		hkpDynamicsContactMgr* findContactMgrTo(const hkpEntity* entity) const;
		void activate();
		void deactivate();
		void activateAsCriticalOperation();
		void deactivateAsCriticalOperation();
		hkBool isActive() const;
		inline int getNumActions() const;
		inline hkpAction* getAction(int i);
		int getNumConstraints() const;
		hkpConstraintInstance* getConstraint( int i );
		const hkpConstraintInstance* getConstraint( int i ) const;
		inline const hkSmallArray<struct hkConstraintInternal>&  getConstraintMasters() const;
		inline hkSmallArray<struct hkConstraintInternal>&  getConstraintMastersRw();
		inline const hkArray<class hkpConstraintInstance*>&  getConstraintSlaves() const;
		void calcStatistics( hkStatisticsCollector* collector) const;
		void setCachedShapeData(const hkpWorld* world, const hkpShape* shape);
		void updateCachedAabb();
	protected:
		const	hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersImpl() const;
				hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersRwImpl();
		const	hkArray<class hkpConstraintInstance*>&	getConstraintSlavesImpl() const;
		hkpEntity( const hkpShape* shape );
	public:
		hkpEntity( class hkFinishLoadedObjectFlag flag );
		inline hkpMotion* getMotion();
		inline hkpSimulationIsland* getSimulationIsland() const;
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SpuCollisionCallback():
				m_util(0),
				m_capacity(0),
				m_eventFilter(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
				m_userFilter(0x01)
			{
			}
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};
class hkpEntityDeactivator : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool shouldDeactivateHighFrequency( const hkpEntity* entity ) = 0;
		virtual hkBool shouldDeactivateLowFrequency( const hkpEntity* entity ) = 0;
	protected:
		hkpEntityDeactivator() {}
	public:
		hkpEntityDeactivator( class hkFinishLoadedObjectFlag flag ) {}
};
class hkpRigidBodyDeactivator : public hkpEntityDeactivator
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum DeactivatorType
		{
			DEACTIVATOR_INVALID,
			DEACTIVATOR_NEVER,
			DEACTIVATOR_SPATIAL,
			DEACTIVATOR_MAX_ID
		};
		virtual enum DeactivatorType getRigidBodyDeactivatorType() const = 0;
};
class hkpRigidBodyCinfo;
class hkpRigidBody : public hkpEntity
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpRigidBody( const hkpRigidBodyCinfo& info );
		virtual ~hkpRigidBody();
		void getCinfo(hkpRigidBodyCinfo& info) const;
		inline hkReal getMass() const;
		inline hkReal getMassInv() const;
		void setMass(hkReal m);
		void setMassInv(hkReal mInv);
		inline void getInertiaLocal(hkMatrix3& inertiaOut) const;
		inline void getInertiaWorld(hkMatrix3& inertiaOut) const;
		void setInertiaLocal(const hkMatrix3& inertia);
		void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		inline void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		inline void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		void setCenterOfMassLocal(const hkVector4& centerOfMass);
		inline const hkVector4& getCenterOfMassLocal() const;
		inline const hkVector4& getCenterOfMassInWorld() const;
		inline const hkVector4& getPosition() const;
		void setPosition(const hkVector4& position);
		inline const hkQuaternion& getRotation() const;
		void setRotation(const hkQuaternion& rotation);
		void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
		inline const hkTransform& getTransform() const;
		void setTransform(const hkTransform& transform);
		void setPositionAndRotationAsCriticalOperation(const hkVector4& position, const hkQuaternion& rotation);
		inline void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		inline void approxCurrentTransform( hkTransform& transformOut ) const;
		inline const hkVector4& getLinearVelocity() const;
		inline void	setLinearVelocity(const hkVector4& newVel);
		inline const hkVector4& getAngularVelocity() const;
		inline void	setAngularVelocity(const hkVector4& newVel);
		inline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
		void setLinearVelocityAsCriticalOperation(const hkVector4& newVel);
		void setAngularVelocityAsCriticalOperation(const hkVector4& newVel);
		inline void applyLinearImpulse(const hkVector4& imp);
		inline void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		inline void applyAngularImpulse(const hkVector4& imp);
		void applyLinearImpulseAsCriticalOperation(const hkVector4& imp);
		void applyPointImpulseAsCriticalOperation(const hkVector4& imp, const hkVector4& p);
		void applyAngularImpulseAsCriticalOperation(const hkVector4& imp);
		inline void applyForce(const hkReal deltaTime, const hkVector4& force);
		inline void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		inline void applyTorque(const hkReal deltaTime, const hkVector4& torque);
		inline hkReal getLinearDamping() const;
		inline void setLinearDamping( hkReal d );
		inline hkReal getAngularDamping() const;
		inline void setAngularDamping( hkReal d );
		inline hkReal getMaxLinearVelocity() const;
		inline void setMaxLinearVelocity( hkReal maxVel );
		inline hkReal getMaxAngularVelocity() const;
		hkWorldOperation::Result setShape(const hkpShape* shape);
		virtual hkpRigidBody* clone() const;
	public:
		inline hkpMotion* getRigidMotion() const;
		void checkPerformance() const;
	public:
		static void __cdecl createDynamicRigidMotion( hkpMotion::MotionType motionType,
																const hkVector4& position, const hkQuaternion& rotation,
																hkReal mass, const hkMatrix3& inertiaLocal, const hkVector4& centreOfMassLocal,
																hkReal maxLinearVelocity, hkReal maxAngularVelocity,
																hkpMaxSizeMotion* motionBufferOut );
		static void __cdecl updateBroadphaseAndResetCollisionInformationOfWarpedBody( hkpEntity* entity );
	protected:
		virtual hkMotionState* getMotionState();
	public:
		hkpRigidBody( class hkFinishLoadedObjectFlag flag ) : hkpEntity( flag ) {}
};
inline hkpMotion* hkpRigidBody::getRigidMotion() const
{
	return const_cast<hkpMaxSizeMotion*>(&m_motion);
}
void hkpRigidBody::setLinearVelocity(const hkVector4& newVel)
{
	;
	activate();
	getRigidMotion()->setLinearVelocity(newVel);
}
void hkpRigidBody::setAngularVelocity(const hkVector4& newVel)
{
	;
	activate();
	getRigidMotion()->setAngularVelocity(newVel);
}
class hkaBone;
class hkaSkeleton
{
	public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkaSkeleton();
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int		m_numReferencePose;
		char**	m_floatSlots;
		hkInt32 m_numFloatSlots;
	public:
		__forceinline hkaSkeleton( hkFinishLoadedObjectFlag flag ) {}
};
class hkaRagdollInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkaRagdollInstance ( const hkArray<hkpRigidBody*>& rigidBodies, const hkArray<hkpConstraintInstance*>& constraints, const hkaSkeleton* skeleton );
		virtual ~hkaRagdollInstance ();
		virtual hkaRagdollInstance* clone(hkpConstraintInstance::CloningMode mode = hkpConstraintInstance::CLONE_INSTANCES_ONLY) const;
		inline int getNumBones () const;
		inline hkpRigidBody* getRigidBodyOfBone (int i) const;
		inline int getBoneIndexOfRigidBody (hkpRigidBody* rb) const;
		inline hkpConstraintInstance* getConstraintOfBone (int i) const;
		inline const hkaSkeleton* getSkeleton () const;
		inline int getParentOfBone (int i) const;
		inline const hkArray<hkpRigidBody*>& getRigidBodyArray() const;
		inline const hkArray<hkpConstraintInstance*>& getConstraintArray() const;
		inline hkBool hasNonRigidBodyBones () const;
		void getPoseWorldSpace (hkQsTransform* poseWorldSpaceOut) const;
		void setPoseWorldSpace (const hkQsTransform* poseModelSpaceIn);
		void getPoseModelSpace (hkQsTransform* poseModelSpaceOut, const hkQsTransform& worldFromModel) const;
		void setPoseModelSpace (const hkQsTransform* poseModelSpaceIn, const hkQsTransform& worldFromModel);
		void FUN_00961550 ( const hkQsTransform* poseModelSpaceA, const hkQsTransform& worldFromModelA,
											const hkQsTransform* poseModelSpaceB, const hkQsTransform& worldFromModelB, hkReal timestep);
		hkResult addToWorld (hkpWorld* world, hkBool updateFilter) const;
		hkResult removeFromWorld () const;
		inline hkpWorld* getWorld() const;
		void getWorldFromBoneTransform (int i, hkQsTransform& worldFromBoneOut) const;
		void getApproxWorldFromBoneTransformAt (int i, hkReal time, hkQsTransform& worldFromBoneOut) const;
	public:
		 hkArray<hkpRigidBody*> m_rigidBodies;
		 hkArray<hkpConstraintInstance*> m_constraints;
		 hkArray<int> m_boneToRigidBodyMap;
		const hkaSkeleton* m_skeleton;
	public:
		hkaRagdollInstance( hkFinishLoadedObjectFlag f ) : m_rigidBodies(f), m_constraints(f), m_boneToRigidBodyMap(f) { }
	private:
		void commonInit (const hkArray<hkpRigidBody*>& rigidBodies, const hkArray<hkpConstraintInstance*>& constraints, const hkaSkeleton* skeleton);
};
hkpRigidBody* hkaRagdollInstance::getRigidBodyOfBone (int i) const
{
	const int rbIdx = m_boneToRigidBodyMap[i];
	return (rbIdx<0) ? 0 : m_rigidBodies[rbIdx];
}
void hkaRagdollInstance::FUN_00961550( const hkQsTransform* poseModelSpaceA, const hkQsTransform& worldFromModelA, const hkQsTransform* poseModelSpaceB, const hkQsTransform& worldFromModelB, hkReal timestep )
{
	const int numBones = m_skeleton->m_numBones;
	const hkReal invTimestep = 1.0f / timestep;
	for (int b=0; b < numBones; b++)
	{
		hkpRigidBody* rbody = getRigidBodyOfBone(b);
		if (rbody)
		{
			hkQsTransform rbTransformA; rbTransformA.setMul( worldFromModelA, poseModelSpaceA[b] );
			rbTransformA.m_rotation.normalize();
			hkQsTransform rbTransformB; rbTransformB.setMul( worldFromModelB, poseModelSpaceB[b] );
			rbTransformB.m_rotation.normalize();
			rbody->setPositionAndRotation( rbTransformB.getTranslation(), rbTransformB.getRotation() );
			{
				hkVector4 linearVelocity; linearVelocity.setSub4( rbTransformB.getTranslation(), rbTransformA.getTranslation() );
				linearVelocity.setMul4( invTimestep, linearVelocity );
				rbody->setLinearVelocity( linearVelocity );
			}
			{
				hkVector4 angularVelocity; hkQuaternion quatDif; quatDif.setMulInverse( rbTransformB.getRotation(), rbTransformA.getRotation() );
				quatDif.normalize();
				if ( !quatDif.hasValidAxis() )
				{
					angularVelocity.setZero4();
				}
				else
				{
					hkReal angle = quatDif.getAngle();
					quatDif.getAxis( angularVelocity );
					angularVelocity.setMul4( angle * invTimestep, angularVelocity );
				}
				rbody->setAngularVelocity( angularVelocity );
			}
		}
	}
}

}  // namespace f3m_00961550

// @f3 0x0096b630 (community match, verified in this file)
extern float DAT_010f2e88;
extern float FUN_00f79acc;
namespace f3m_0096b630 {
struct __declspec(align(16)) QVec4 {
    float x, y, z, w;
    QVec4& operator=(const QVec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};


struct QCharObj;
struct QCharSub {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    QVec4 m_dir;
};
struct QCharVtbl;
struct QCharObj {
    QCharVtbl* vtbl;
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
    unsigned int m_flags;
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
    QVec4 m_v320;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    float m_f340;
    float m_f344;
    int unk348;
    int unk34C;
    int m_state;
    int unk354;
    int unk358;
    int unk35C;
    QVec4 m_normal;
    QVec4 m_v370;
    int unk380;
    int unk384;
    float m_f388;
    int unk38C;
    QVec4 m_vel;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    float m_f3c0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    float m_f3d4;
    float m_f3d8;
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
    unsigned char m_b4a0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    QVec4 m_v4b0;
    double FUN_008ed050();
    void FUN_008ea1f0(QVec4* out);
    void FUN_008e8900();
    void FUN_008ea1d0();
};

struct QCharVtbl {
    void* vf00;
    void* vf04;
    void* vf08;
    void* vf0C;
    void* vf10;
    void* vf14;
    void* vf18;
    void* vf1C;
    void* vf20;
    void* vf24;
    void* vf28;
    void* vf2C;
    void* vf30;
    void* vf34;
    void* vf38;
    void* vf3C;
    void* vf40;
    void* vf44;
    void* vf48;
    void* vf4C;
    void* vf50;
    void* vf54;
    void* vf58;
    void* vf5C;
    void* vf60;
    void* vf64;
    void* vf68;
    void* vf6C;
    void* vf70;
    void* vf74;
    void* vf78;
    void* vf7C;
    void* vf80;
    void* vf84;
    void* vf88;
    void* vf8C;
    void* vf90;
    void* vf94;
    QCharSub* (__thiscall* GetSub)(QCharObj*);
};

struct QParams {
    float m_factor;
    int unk04;
    int unk08;
    int unk0C;
    QVec4 m_v10;
    QVec4 m_v20;
    QVec4 m_v30;
    QVec4 m_v40;
    QVec4 m_v50;
    float m_f60;
    int unk64;
    int unk68;
    int unk6C;
    QVec4 m_v70;
};

void FUN_00a062a0(QParams* params, QVec4* vel);

struct QState {
    int unk00;
    int unk04;
    float m_f08;
    void FUN_0096b630(QCharObj* obj);
};

static inline float QDot3(const QVec4& a, const QVec4& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
static inline void QAddMul4(QVec4& d, float s, const QVec4& a) {
    d.x += s * a.x; d.y += s * a.y; d.z += s * a.z; d.w += s * a.w;
}
static inline void QAddMul4b(QVec4& d, float s, const QVec4& a) {
    d.x += a.x * s; d.y += a.y * s; d.z += a.z * s; d.w += a.w * s;
}
static inline void QMul4(QVec4& d, float s) {
    d.x *= s; d.y *= s; d.z *= s; d.w *= s;
}

// pdb: bhkCharacterStateInAir::Update | bhkCharacterStateInAir.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInput
void QState::FUN_0096b630(QCharObj* obj)
{
    if ((unsigned char)(obj->m_flags >> 8) & 1) {
        obj->m_state = 0;
        // Fake match: volatile view of the flags word (as in the FNV twin) keeps the flag test and
        // the or-store as separate memory operations; a plain |= changes the frame and 22 lines.
        const_cast<volatile unsigned int&>(obj->m_flags) |= 0x80;
    }
    if (obj->m_state == 11 && obj->m_f3d4 > 1.0f && obj->FUN_008ed050() < 0.10000000149011612) {
        obj->m_state = 0;
        obj->m_b4a0 = 1;
        QVec4 v;
        obj->FUN_008ea1f0(&v);
        obj->m_v4b0 = v;
    }
    if (obj->m_state != 11) {
        if (obj->m_state == 1) {
            obj->m_state = 11;
        } else {
            obj->m_f3d4 = 0.0f;
            obj->FUN_008e8900();
            return;
        }
    }
    const float& speed = obj->m_f3c0;
    if (speed > 0.0f) {
        QParams params;
        params.m_factor = (obj->m_flags & 0x1800) ? 1.0f : speed * FUN_00f79acc + DAT_010f2e88;
        params.m_v10 = obj->m_v370;
        params.m_v20 = obj->m_normal;
        params.m_v30 = obj->m_normal;
        params.m_v70 = obj->m_v320;
        params.m_v40 = obj->m_vel;
        params.m_f60 = m_f08;
        params.m_v50.set(obj->m_f344, obj->m_f340, 0.0f, 0.0f);
        QVec4* vel = &obj->m_vel;
        FUN_00a062a0(&params, vel);
        { float d = QDot3(*vel, obj->m_normal); QAddMul4b(*vel, -d, obj->m_normal); }
        QAddMul4(*vel, QDot3(obj->m_normal, params.m_v40), obj->m_normal);
    }
    {
        obj->vtbl->GetSub(obj);
        QVec4 dir;
        dir = obj->vtbl->GetSub(obj)->m_dir;
        obj->vtbl->GetSub(obj);
        QMul4(dir, obj->m_f3d8);
        QAddMul4(obj->m_vel, obj->m_f388, dir);
    }
    obj->FUN_008ea1d0();
}
}   // namespace f3m_0096b630

// @f3 0x009787c0 (community match, verified in this file)
#include <windows.h>
namespace f3m_009787c0 {

// 0x009787c0: casts a ray against everything that overlaps an AABB phantom and reports the hits to a collector
// (hkpAabbPhantom::castRay in Havok terms). For each overlapping collidable that has a shape, the ray is moved into
// the collidable's local space and handed to the shape.

namespace f3m_009787c0 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern DWORD DAT_0116913c;      // TLS slot of the per-thread monitor stream

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

struct hkRotation;
struct hkTransform;

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    // this = r^-1 * b
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);
    // this = t^-1 * b, as a point
    __forceinline void _setTransformedInversePos(const hkTransform& t, const hkVector4& b);

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedInversePos(const hkTransform& t, const hkVector4& b)
{
    hkReal v0 = b(0) - t.getTranslation()(0);
    hkReal v1 = b(1) - t.getTranslation()(1);
    hkReal v2 = b(2) - t.getTranslation()(2);
    x = t.getRotation()(0, 0) * v0 + t.getRotation()(1, 0) * v1 + t.getRotation()(2, 0) * v2;
    y = t.getRotation()(0, 1) * v0 + t.getRotation()(1, 1) * v1 + t.getRotation()(2, 1) * v2;
    z = t.getRotation()(0, 2) * v0 + t.getRotation()(1, 2) * v1 + t.getRotation()(2, 2) * v2;
    w = 0;
}

class hkpRayShapeCollectionFilter
{
public:
    virtual int isCollisionEnabled(const void* aInput, const void* bShape, const void* bContainer, unsigned int bKey) const;
};

// the world's collision filter; it is several filter interfaces at once
class hkpCollisionFilter
{
public:
    virtual void vf00();
    int unk04;
    struct CollidableCollidable { virtual void vf00(); } m_collidableCollidable;
    struct ShapeCollection { virtual void vf00(); } m_shapeCollection;
};

class hkpRayHitCollector;
struct hkpCollidable;

struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    hkUint32 m_filterInfo;
    const hkpRayShapeCollectionFilter* m_rayShapeCollectionFilter;

    __forceinline hkpShapeRayCastInput()
    {
        m_rayShapeCollectionFilter = 0;
        m_filterInfo = 0;
    }
};

struct hkpWorldRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    bool m_enableShapeCollectionFilter;
    hkUint32 m_filterInfo;
};

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void castRayWithCollector(const hkpShapeRayCastInput& input, const hkpCollidable& cdBody, hkpRayHitCollector& collector) const;
};

struct hkpCollidable
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCollidable* m_parent;

    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
};

struct hkpWorld
{
    char pad00[0x70];
    void* m_collisionFilter;
};

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline T* begin() { return m_data; }
    __forceinline const T* begin() const { return m_data; }
    __forceinline int getSize() const { return m_size; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
};

class hkpAabbPhantom
{
public:
    void FUN_009787c0(const hkpWorldRayCastInput& input, hkpRayHitCollector& collector) const;

    void* m_vtable;
    int unk04;
    hkpWorld* m_world;
    char pad0c[0xc0 - 0x0c];
    hkArray<hkpCollidable*> m_overlappingCollidables;
};

// pdb: hkpAabbPhantom::castRay | hkpAabbPhantom.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: input, collector
void hkpAabbPhantom::FUN_009787c0(const hkpWorldRayCastInput& input, hkpRayHitCollector& collector) const
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtrcPhantom";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpShapeRayCastInput sinput;
    sinput.m_filterInfo = input.m_filterInfo;
    if (input.m_enableShapeCollectionFilter && m_world->m_collisionFilter)
    {
        sinput.m_rayShapeCollectionFilter = reinterpret_cast<const hkpRayShapeCollectionFilter*>(static_cast<char*>(m_world->m_collisionFilter) + 0x10);
    }
    else
    {
        sinput.m_rayShapeCollectionFilter = 0;
    }

    hkpCollidable* const* col = m_overlappingCollidables.begin();
    for (int i = m_overlappingCollidables.getSize() - 1; i >= 0; i--)
    {
        const hkpShape* shape = (*col)->getShape();
        if (shape)
        {
            const hkTransform& trans = (*col)->getTransform();
            hkVector4& localFrom = sinput.m_from;
            hkVector4& localTo = sinput.m_to;
            localFrom._setTransformedInversePos(trans, input.m_from);
            localTo._setTransformedInversePos(trans, input.m_to);
            shape->castRayWithCollector(sinput, **col, collector);
        }
        col++;
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009787c0

// @f3 0x009789b0 (community match, verified in this file)
#include <windows.h>
namespace f3m_009789b0 {

// 0x009789b0: casts a ray against everything that overlaps an AABB phantom and keeps the closest hit
// (hkpAabbPhantom::castRay with a hkpWorldRayCastOutput in Havok terms). For each overlapping collidable that has a
// shape, the ray is moved into the collidable's local space and cast against the shape; the collidable of the last
// improving hit is remembered, and at the end the hit normal is rotated back into world space.

namespace f3m_009789b0 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern DWORD DAT_0116913c;      // TLS slot of the per-thread monitor stream

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

struct hkRotation;
struct hkTransform;

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    // this = r^-1 * b
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);
    // this = t^-1 * b, as a point
    __forceinline void _setTransformedInversePos(const hkTransform& t, const hkVector4& b);
    // this = r * b
    void hkVector4_setRotatedDir(const hkRotation& r, const hkVector4& b);

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedInversePos(const hkTransform& t, const hkVector4& b)
{
    hkReal v0 = b(0) - t.getTranslation()(0);
    hkReal v1 = b(1) - t.getTranslation()(1);
    hkReal v2 = b(2) - t.getTranslation()(2);
    x = t.getRotation()(0, 0) * v0 + t.getRotation()(1, 0) * v1 + t.getRotation()(2, 0) * v2;
    y = t.getRotation()(0, 1) * v0 + t.getRotation()(1, 1) * v1 + t.getRotation()(2, 1) * v2;
    z = t.getRotation()(0, 2) * v0 + t.getRotation()(1, 2) * v1 + t.getRotation()(2, 2) * v2;
    w = 0;
}

class hkpRayShapeCollectionFilter
{
public:
    virtual int isCollisionEnabled(const void* aInput, const void* bShape, const void* bContainer, unsigned int bKey) const;
};

// the world's collision filter; it is several filter interfaces at once
class hkpCollisionFilter
{
public:
    virtual void vf00();
    int unk04;
    struct CollidableCollidable { virtual void vf00(); } m_collidableCollidable;
    struct ShapeCollection { virtual void vf00(); } m_shapeCollection;
};

struct hkpCollidable;

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// result of a ray cast against a shape; the closest hit so far
struct hkpShapeRayCastOutput
{
    hkVector4 m_normal;
    hkReal m_hitFraction;
    int m_extraInfo;
    unsigned int m_shapeKeys[8];
    int m_shapeKeyIndex;
    int pad3c[5];
};

struct hkpWorldRayCastOutput : public hkpShapeRayCastOutput
{
    const hkpCollidable* m_rootCollidable;
};

struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    hkUint32 m_filterInfo;
    const hkpRayShapeCollectionFilter* m_rayShapeCollectionFilter;

    __forceinline hkpShapeRayCastInput()
    {
        m_rayShapeCollectionFilter = 0;
        m_filterInfo = 0;
    }
};

struct hkpWorldRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    bool m_enableShapeCollectionFilter;
    hkUint32 m_filterInfo;
};

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual hkBool castRay(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output) const;
};

struct hkpCollidable
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCollidable* m_parent;

    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
};

struct hkpWorld
{
    char pad00[0x70];
    void* m_collisionFilter;
};

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline T* begin() { return m_data; }
    __forceinline const T* begin() const { return m_data; }
    __forceinline int getSize() const { return m_size; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
};

class hkpAabbPhantom
{
public:
    void hkpAabbPhantom_castRay(const hkpWorldRayCastInput& input, hkpWorldRayCastOutput& output) const;

    void* m_vtable;
    int unk04;
    hkpWorld* m_world;
    char pad0c[0xc0 - 0x0c];
    hkArray<hkpCollidable*> m_overlappingCollidables;
};

// pdb: hkpAabbPhantom::castRay | hkpAabbPhantom.obj | fnv360_0822_retail, caller_sim + bridge(ustr_rel|call_seq) + skyrim(caller_sim), high
void hkpAabbPhantom::hkpAabbPhantom_castRay(const hkpWorldRayCastInput& input, hkpWorldRayCastOutput& output) const
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtrcPhantom";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpShapeRayCastInput sinput;
    sinput.m_filterInfo = input.m_filterInfo;
    if (input.m_enableShapeCollectionFilter && m_world->m_collisionFilter)
    {
        sinput.m_rayShapeCollectionFilter = reinterpret_cast<const hkpRayShapeCollectionFilter*>(static_cast<char*>(m_world->m_collisionFilter) + 0x10);
    }
    else
    {
        sinput.m_rayShapeCollectionFilter = 0;
    }

    hkpCollidable* const* col = m_overlappingCollidables.begin();
    for (int i = m_overlappingCollidables.getSize() - 1; i >= 0; i--)
    {
        const hkpShape* shape = (*col)->getShape();
        if (shape)
        {
            // the ray in the space of the collidable
            hkVector4& localTo = sinput.m_to;
            const hkTransform& trans = (*col)->getTransform();
            hkVector4& localFrom = sinput.m_from;
            localFrom._setTransformedInversePos(trans, input.m_from);
            localTo._setTransformedInversePos(trans, input.m_to);
            hkBool hit = shape->castRay(sinput, output);
            if (hit)
            {
                output.m_rootCollidable = *col;
            }
        }
        col++;
    }

    // the normal of the hit, back in world space
    if (output.m_rootCollidable != 0)
    {
        output.m_normal.hkVector4_setRotatedDir(output.m_rootCollidable->getTransform().getRotation(), output.m_normal);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009789b0

// @f3 0x00960f40 (community match, verified in this file)
namespace f3m_00960f40 {
// 0x00960f40: gives the pose of a ragdoll in model space (hkaRagdollInstance::getPoseModelSpace in Havok terms): the
// pose is read in world space, then every bone transform is multiplied on the left by the inverse of the
// world-from-model transform.
//
// The quaternion product (0x008d3290) is written out here as well: it is an inline function the compiler chose not
// to expand, and the code of this function depends on the compiler having seen its body (it knows the call leaves
// the inverse transform untouched and keeps its parts in registers across the loop).

namespace f3m_00960f40 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = v.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    // this = direction rotated by the inverse of quat
    __forceinline void setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.w; }
    __forceinline void setInverse(const hkQuaternion& q) { m_vec.setNeg3(q.getImag()); }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);      // setMul
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkVector4& imag = quat.getImag();

    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = imag.dot3(direction);

    ret.addMul4(imagDotDir, imag);

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(imag, direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// this = q0 * q1 (0x008d3290)
inline void hkQuaternion::FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1)
{
    hkVector4 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.getReal(), q1.getImag());
    vec.addMul4(q1.getReal(), q0.getImag());
    hkReal w = q0.getReal() * q1.getReal() - q0.getImag().dot3(q1.getImag());
    m_vec = vec;
    m_vec(3) = w;
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    // this = t^-1
    __forceinline void setInverse(const hkQsTransform& t)
    {
        m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
        m_translation.setNeg4(m_translation);
        m_rotation.setInverse(t.m_rotation);
        hkVector4 invScale;
        invScale.set(1.0f / t.m_scale(0), 1.0f / t.m_scale(1), 1.0f / t.m_scale(2));
        m_scale = invScale;
    }
    // this = t1 * t2
    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        // rotation and position go together
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);

        // scale goes apart
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
    // this = t1^-1 * t2
    __forceinline void setMulInverseMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkQsTransform h;
        h.setInverse(t1);
        setMul(h, t2);
    }
};

struct hkaSkeleton
{
    char* m_name;
    short* m_parentIndices;
    int m_numParentIndices;
    struct hkaBone** m_bones;
    int m_numBones;
};

class hkaRagdollInstance
{
public:
    __forceinline int getNumBones() const { return m_skeleton->m_numBones; }
    void FUN_00960c70(hkQsTransform* poseWorldSpaceOut) const;      // getPoseWorldSpace
    void FUN_00960f40(hkQsTransform* poseModelSpaceOut, const hkQsTransform& worldFromModel) const;

    char pad00[0x2c];
    const hkaSkeleton* m_skeleton;
};

void hkaRagdollInstance::FUN_00960f40(hkQsTransform* poseModelSpaceOut, const hkQsTransform& worldFromModel) const
{
    // first the pose in world space
    FUN_00960c70(poseModelSpaceOut);

    const int numBones = getNumBones();

    // then into the space of the model
    hkQsTransform modelFromWorld;
    modelFromWorld.setInverse(worldFromModel);

    for (int i = 0; i < numBones; i++)
    {
        poseModelSpaceOut[i].setMul(modelFromWorld, poseModelSpaceOut[i]);
    }
}

}
}   // namespace f3m_00960f40

// @f3 0x00972180 (community match, verified in this file)
namespace f3m_00972180 {
// 0x00972180: hkpInertiaTensorComputer::convertInertiaTensorToPrincipleAxis(hkMatrix3& inertia, hkRotation& principleAxisOut)
// of Havok 5.5.0 (hkpUtilities, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Turns an inertia tensor to its principal axes by Jacobi rotations: at most five passes, each zeroing the largest
// off-diagonal element of the lower triangle, the rotations accumulated in principleAxisOut, which is then made
// orthonormal (column 0 normalized, column 1 = column 2 x column 0, column 2 = column 0 x column 1).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py); the declarations above the function are therefore the SDK's
// text with its names. The function body follows the SDK's unoptimized (hybrid) library object of this function
// statement by statement, and built with the SDK's headers it reproduces both that object and the release object.
// Only the function itself carries the packet's name; its callees keep the SDK's names.
namespace f3m_00972180 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool;
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
template<typename T> class hkArray;
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline void hkMatrix3::operator= ( const hkMatrix3& a )
{
	m_col0 = a.getColumn(0);
	m_col1 = a.getColumn(1);
	m_col2 = a.getColumn(2);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}
struct hkGeometry;
class hkpShape;
class hkpRigidBodyCinfo;
class hkpRigidBody;
class hkpConstraintInstance;
struct hkpMassProperties;
struct hkpMassElement;
class hkpInertiaTensorComputer
{
	public:
		static hkResult __cdecl computeSphereVolumeMassProperties( hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeBoxVolumeMassProperties(const hkVector4& halfExtents, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeCapsuleVolumeMassProperties( const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeSphereSurfaceMassProperties( hkReal radius, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeBoxSurfaceMassProperties(const hkVector4& halfExtents, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeTriangleSurfaceMassProperties(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeCylinderVolumeMassProperties(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeVertexHullVolumeMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeVertexCloudMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometrySurfaceMassProperties(const hkGeometry* geom, hkReal surfaceThickness, hkBool distributeUniformly, hkReal mass, hkpMassProperties &result);
		static void __cdecl computeGeometryVolumeMassProperties(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometryVolumeMassPropertiesChecked(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl combineMassProperties(const hkArray<hkpMassElement>& elements, hkpMassProperties& result );
		static void __cdecl computeShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpMassProperties &result);
		static void __cdecl setShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setMassProperties(const hkpMassProperties& props, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToDensity(const hkpMassProperties& props, hkReal density, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToMass(const hkpMassProperties& props, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl clipInertia(hkReal maxInertiaRatio, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl simplifyInertiaTensorToOrientedParticle(hkMatrix3 &inertia);
		static void __cdecl FUN_00972180( hkMatrix3& inertia, hkRotation& principleAxisOut );
		static void __cdecl optimizeInertiasOfConstraintTree( hkpConstraintInstance*const* constraints, int numConstraints, hkpRigidBody* rootBody, hkReal inertiaFactorHint = 1.5f );
		static void __cdecl shiftInertiaToCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
		static void __cdecl shiftInertiaFromCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
};
// pdb: hkInertiaTensorComputer::convertInertiaTensorToPrincipleAxis | hkInertiaTensorComputer.obj | tesv_win, caller_sim, low
void hkpInertiaTensorComputer::FUN_00972180(hkMatrix3& inertia, hkRotation& principleAxisOut)
{
	principleAxisOut.setIdentity();
	for (int iterations = 5; iterations > 0; iterations--)
	{
		hkReal maxValSqrd = inertia(1, 0) * inertia(1, 0);
		int maxR = 1;
		int maxC = 0;
		for (int c = 0; c < 2; c++)
		{
			hkReal in = inertia(2, c);
			in *= in;
			if (in > maxValSqrd)
			{
				maxValSqrd = in;
				maxR = 2;
				maxC = c;
			}
		}
		if (maxValSqrd < 1.4210855e-14f)
		{
			break;
		}
		hkReal si;
		hkReal co;
		{
			hkReal w = inertia(maxC, maxR);
			hkReal x = inertia(maxC, maxC);
			hkReal y = inertia(maxR, maxR);
			hkReal a = (y - x) / (2.0 * w);
			hkReal sina = a > 0.0f ? 1.0f : -1.0f;
			hkReal r = sina / (hkMath::fabs(a) + hkMath::sqrt(1.0f + a * a));
			co = 1.0f / hkMath::sqrt(1.0f + r * r);
			si = r * co;
		}
		hkRotation rot; rot.setIdentity();
		rot(maxC, maxC) = co;
		rot(maxR, maxR) = co;
		rot(maxC, maxR) = -si;
		rot(maxR, maxC) = si;
		hkRotation tmp; tmp.setMul(rot, inertia);
		rot(maxC, maxR) = si;
		rot(maxR, maxC) = -si;
		inertia.setMul(tmp, rot);
		tmp.setMul(principleAxisOut, rot);
		principleAxisOut = tmp;
	}
	principleAxisOut.getColumn(0).normalize3();
	principleAxisOut.getColumn(1).setCross(principleAxisOut.getColumn(2), principleAxisOut.getColumn(0));
	principleAxisOut.getColumn(1).normalize3();
	principleAxisOut.getColumn(2).setCross(principleAxisOut.getColumn(0), principleAxisOut.getColumn(1));
	principleAxisOut.getColumn(2).normalize3();
}

}  // namespace f3m_00972180
}   // namespace f3m_00972180

// @f3 0x0096a3b0 (community match, verified in this file)
#include <math.h>
namespace f3m_0096a3b0 {

// FUN_0096a3b0: addCdPoint of a hkpAllCdPointCollector-derived collector (Havok FPU build).
// The collector remembers each new body B it touches (with its first contact) and, for entities
// and layer-30 bodies, appends the contact to m_hits; for a triangle it classifies the contact by
// comparing the triangle normal with the contact normal (cos 0.5 degrees).
namespace f3m_0096a3b0 {

// Havok's hkBool. The three tests below copy-assign it into a local before returning it (a guess
// at the source): that keeps the original's sete/test pair, where a returned comparison folds
// into a single jump.
class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) : m_bool(static_cast<char>(b)) {}
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

static __forceinline float sqrtInverse(float r) { return 1.0f / sqrtf(r); }

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b)
    {
        const float nx = a.y * b.z - a.z * b.y;
        const float ny = a.z * b.x - a.x * b.z;
        const float nz = a.x * b.y - a.y * b.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline float dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline float lengthInverse3() const
    {
        float l2 = (x * x + y * y + z * z);
        return l2 ? sqrtInverse(l2) : 0;
    }
    __forceinline void mul4(float rs)
    {
        float s = float(rs);
        (*this)(0) *= s;
        (*this)(1) *= s;
        (*this)(2) *= s;
        (*this)(3) *= s;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setNeg3(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
    }
    void hkVector4_setRotatedDir(const void* rotation, const hkVector4& v);   // setRotatedDir
};

struct hkpShape
{
    int unk00;
    int unk04;
    int unk08;
    int m_type;
    hkVector4 unk10;
    hkVector4 m_vertexA;   // hkpTriangleShape vertices
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;

    hkBool isTriangle() const { hkBool result; result = (m_type == 4); return result; }
};

struct hkpCollidable;

struct hkpCdBody
{
    hkpShape* m_shape;
    int m_shapeKey;
    void* m_motion;
    hkpCdBody* m_parent;

    __forceinline const hkpCollidable* getRootCollidable() const
    {
        const hkpCdBody* body = this;
        while (body->m_parent)
            body = body->m_parent;
        return reinterpret_cast<const hkpCollidable*>(body);
    }
};

struct hkpCollidable : hkpCdBody
{
    signed char m_ownerOffset;
    char unk11;
    short unk12;
    int m_broadPhaseId;         // hkpTypedBroadPhaseHandle
    char m_broadPhaseType;
    char unk19;
    char unk1a;
    char unk1b;
    unsigned m_collisionFilterInfo;

    __forceinline void* getOwner() const { return (char*)this + m_ownerOffset; }
};

// The collidable's owner (an entity or a phantom).
struct hkpWorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkpCollidable m_collidable;

    void FUN_009316e0();   // addReference
    hkBool isEntity() const { hkBool result; result = (m_collidable.m_broadPhaseType == 1); return result; }
    hkBool isLayer30() const { hkBool result; result = ((m_collidable.m_collisionFilterInfo & 0x7f) == 30); return result; }
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpCdPoint
{
    hkContactPoint m_contact;
    hkpCdBody* m_cdBodyA;
    hkpCdBody* m_cdBodyB;
};

// 64-byte root contact point (fields up to +0x3b; the copy at 0x568710 copies exactly those).
// +0x24 holds body A's shape key in m_newPoints and a state in m_hits (0, then 2 for a
// triangle, 1 for a triangle whose normal is within 0.5 degrees of the contact normal).
// The copy's body is visible here: with it hidden, the local newPoint escapes and the root
// walks of body A are scheduled after the contact copy instead of between its stores.
struct RootCdPoint
{
    hkContactPoint m_contact;
    const hkpCollidable* m_rootA;
    int m_state;
    const hkpCollidable* m_rootB;
    int m_shapeKeyB;
    int unk30;
    int unk34;
    int unk38;

    RootCdPoint() {}
    __declspec(noinline) RootCdPoint& FUN_00568710(const RootCdPoint& other)   // operator=
    {
        m_contact.m_position = other.m_contact.m_position;
        m_contact.m_separatingNormal = other.m_contact.m_separatingNormal;
        m_rootA = other.m_rootA;
        m_state = other.m_state;
        m_rootB = other.m_rootB;
        m_shapeKeyB = other.m_shapeKeyB;
        unk30 = other.unk30;
        unk34 = other.unk34;
        unk38 = other.unk38;
        return *this;
    }
};

void __cdecl FUN_00901f10(void* array, int elementSize);   // hkArrayUtil::_reserveMore

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline void reserveMore()
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
    }
    __forceinline void pushBack(const T& t)
    {
        reserveMore();
        m_data[m_size] = t;
        ++m_size;
    }
    __forceinline T& expandOne()
    {
        reserveMore();
        return m_data[m_size++];
    }
    __forceinline int indexOf(const T& t) const
    {
        for (int i = 0; i < m_size; ++i)
            if (m_data[i] == t)
                return i;
        return -1;
    }
};

struct Collector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkArray<RootCdPoint> m_hits;
    int unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038;
    int unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058;
    int unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078;
    int unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098;
    int unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8;
    int unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8;
    int unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8;
    int unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118;
    int unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138;
    int unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158;
    int unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178;
    int unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198;
    int unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8;
    int unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8;
    int unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8;
    int unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214, unk218;
    int unk21c, unk220;
    hkArray<hkpWorldObject*> m_bodies;
    hkArray<int> m_states;
    hkArray<RootCdPoint> m_newPoints;

    void FUN_00969ff0();
    void FUN_0096a3b0(const hkpCdPoint& point);
};

}

// pdb: bhkCharacterPointCollector::addCdPoint | bhkCharacterPointCollector.obj | fnv360_0822_retail, caller_sim, low
// pdb params: event
void f3m_0096a3b0::Collector::FUN_0096a3b0(const hkpCdPoint& point)
{
    const hkpCollidable* root = point.m_cdBodyB->getRootCollidable();
    hkpWorldObject* owner = static_cast<hkpWorldObject*>(root->getOwner());
    if (!owner)
        return;

    int index = m_bodies.indexOf(owner);
    if (index == -1)
    {
        owner->FUN_009316e0();
        m_bodies.pushBack(owner);
        RootCdPoint newPoint;
        newPoint.m_contact = point.m_contact;
        newPoint.m_rootA = point.m_cdBodyA->getRootCollidable();
        newPoint.m_state = point.m_cdBodyA->m_shapeKey;
        newPoint.m_rootB = point.m_cdBodyB->getRootCollidable();
        newPoint.m_shapeKeyB = point.m_cdBodyB->m_shapeKey;
        m_newPoints.expandOne().FUN_00568710(newPoint);
        m_states.pushBack(0);
    }
    else
    {
        int& state = m_states.m_data[index];
        if (state == 1)
            state = 2;
    }

    if (owner->isEntity() || owner->isLayer30())
    {
        RootCdPoint& hit = m_hits.expandOne();
        hit.m_contact = point.m_contact;
        hit.m_rootA = point.m_cdBodyA->getRootCollidable();
        hit.m_rootB = point.m_cdBodyB->getRootCollidable();
        hit.m_state = 0;
        hit.m_shapeKeyB = point.m_cdBodyB->m_shapeKey;
        const float cosTolerance = cosf(0.008726646192371845f);   // cos(0.5 degrees)
        if (point.m_cdBodyB->m_shape->isTriangle())
        {
            hit.m_state = 2;
            const hkpShape* triangle = point.m_cdBodyB->m_shape;
            hkVector4 edge0, edge1, normal;
            edge0.setSub4(triangle->m_vertexB, triangle->m_vertexA);
            edge1.setSub4(triangle->m_vertexC, triangle->m_vertexB);
            normal.setCross(edge0, edge1);
            normal.normalize3();
            normal.hkVector4_setRotatedDir(point.m_cdBodyB->m_motion, normal);
            if (normal.dot3(hit.m_contact.m_separatingNormal) < 0.0f)
                normal.setNeg3(normal);
            if (normal.dot3(hit.m_contact.m_separatingNormal) > cosTolerance)
                hit.m_state = 1;
            FUN_00969ff0();
        }
    }
}
}   // namespace f3m_0096a3b0

// @f3 0x0097f200 (community match, verified in this file)
namespace f3m_0097f200 {
// pdb: hkpSimulation::checkDeltaTimeIsOk | hkpSimulation.obj | fnv360_0822_retail, objrun, low
// pdb params: deltaTime
void __stdcall FUN_0097f200(void*)
{
}
}   // namespace f3m_0097f200

// @f3 0x00961be0 (community match, verified in this file)
namespace f3m_00961be0 {
struct O961be0 {
    int unk00;
    int unk04;
    int unk08;
};

struct W961be0 {
    void addArray(void** arr, int count, int flag);
    void addObj(O961be0* obj);
    void setThing(void* p, int a, int b);
};

struct C961be0 {
    int unk00;
    int unk04;
    O961be0** arr08;
    int count0c;
    int unk10;
    O961be0** arr14;
    int count18;
    int hkaRagdollInstance_addToWorld(W961be0* w, bool flag);
};

// pdb: hkaRagdollInstance::addToWorld | hkaRagdollInstance.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
int C961be0::hkaRagdollInstance_addToWorld(W961be0* w, bool flag)
{
    O961be0** arr = this->arr08;
    O961be0* first = arr[0];
    if (first != 0 && first->unk08 != 0)
        return 1;
    w->addArray((void**)arr, this->count0c, 1);
    for (int i = 0; i < this->count18; i++)
        w->addObj(this->arr14[i]);
    if (flag) {
        int n = this->count0c;
        for (int j = 0; j < n; j++)
            w->setThing(this->arr08[j], 1, 0);
    }
    return 0;
}
}   // namespace f3m_00961be0

// @f3 0x00961300 (community match, verified in this file)
// 0x00961300: hkaRagdollInstance::setPoseModelSpace(const hkQsTransform* poseIn, const hkQsTransform& worldFromModel)
// of Havok 5.5.0 (hkaRagdoll, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Puts the ragdoll into a pose given in model space: for every bone with a rigid body, the body's transform is
// worldFromModel * poseIn[bone] (rotation normalized), and its linear and angular velocity are set to zero.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself carries the packet's
// name; its callees keep the SDK's names.
namespace f3m_00961300 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
	public:
		__forceinline hkSmallArray();
		explicit __forceinline hkSmallArray(int size);
		__forceinline ~hkSmallArray();
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		void clearAndDeallocate();
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
	public:
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern const hkQuadReal hkQuadReal0000;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkSweptTransform() { }
	public:
		__forceinline void _approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
class hkQsTransform
{
	public:
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}
inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&hkQuadReal0000);
	return zero;
}
inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}
const hkVector4& hkQsTransform::getTranslation() const
{
	return m_translation;
}
const hkQuaternion& hkQsTransform::getRotation() const
{
	return m_rotation;
}
void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);
	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
			;
		}
		__forceinline bool isMarkedForWrite( )
		{
			return true;
		}
		__forceinline bool isMarkedForReadRecursive()
		{
			return true;
		}
		__forceinline void unmarkForRead( )
		{
			;
		}
		__forceinline void unmarkForWrite()
		{
			;
		}
		void disableChecks();
		void enableChecks();
		bool isCheckingEnabled() const;
		void accessCheck( AccessType type ) const;
		static void __cdecl accessCheckWithParent( const hkMultiThreadCheck* parentLock, AccessType parentType, const hkMultiThreadCheck& lock, AccessType type );
		static void staticInit();
		static void staticQuit();
	protected:
		void markForReadImpl(ReadMode mode  );
		void markForWriteImpl( );
		bool isMarkedForWriteImpl( );
		void unmarkForReadImpl( );
		void unmarkForWriteImpl();
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
struct hkAabbUint32;
enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
class hkpWorld;
typedef hkUint32 hkpShapeKey;
class hkpShape;
class hkMotionState;
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpCdBody(  ){}
		friend class hkpCollidable;
		__forceinline hkpCdBody( const hkpShape* shape, const hkMotionState* motionState );
		__forceinline hkpCdBody( const hkpShape* shape, const hkTransform* t );
		__forceinline hkpCdBody( const hkpCdBody& body ){}
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
		__forceinline const hkpCollidable* getRootCollidable() const;
		__forceinline hkpShapeKey getShapeKey() const ;
		__forceinline const hkpCdBody* getParent() const;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkMotionState* ms );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkTransform* t );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
		__forceinline const hkMotionState* getMotionState() const;
		__forceinline void setMotionState( const hkMotionState* state );
		__forceinline void setTransform( const hkTransform* t );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_KEYFRAMED,
	HK_COLLIDABLE_QUALITY_DEBRIS,
	HK_COLLIDABLE_QUALITY_MOVING,
	HK_COLLIDABLE_QUALITY_CRITICAL,
	HK_COLLIDABLE_QUALITY_BULLET,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpTypedBroadPhaseHandle( int type );
		__forceinline hkpTypedBroadPhaseHandle( void* owner, int type );
		__forceinline int getType() const;
		__forceinline void setOwner(void* o);
		__forceinline void* getOwner() const;
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		hkpTypedBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ) : hkpBroadPhaseHandle(flag) {}
	protected:
		enum { OFFSET_INVALID = 127 };
		inline void setType( int type );
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline hkpCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpCollidable();
		inline const hkpShape* getShape() const;
		inline void setShape(const hkpShape* shape);
		inline void setOwner( void* owner );
		inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
		void checkPerformance();
		inline const hkpTypedBroadPhaseHandle* getBroadPhaseHandle() const;
		inline       hkpTypedBroadPhaseHandle* getBroadPhaseHandle();
		__forceinline hkpCollidableQualityType getQualityType() const;
		__forceinline void setQualityType(hkpCollidableQualityType type);
		__forceinline hkReal getAllowedPenetrationDepth() const;
		__forceinline void setAllowedPenetrationDepth( hkReal val );
	public:
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		__forceinline int getType() const;
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				BoundingVolumeData();
				__forceinline const hkAabbUint32& getAabbUint32() const { return reinterpret_cast<const hkAabbUint32&>(m_min); }
				__forceinline       hkAabbUint32& getAabbUint32()		  { return reinterpret_cast<      hkAabbUint32&>(m_min); }
				__forceinline void invalidate() { m_min[0] = 1; m_max[0] = 0; }
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpLinkedCollidable();
		inline hkpLinkedCollidable( class hkFinishLoadedObjectFlag flag ) : hkpCollidable(flag) {}
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};
struct hkpPropertyValue;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void addProperty( hkUint32 key, hkpPropertyValue value );
		hkpPropertyValue removeProperty( hkUint32 key );
		void editProperty( hkUint32 key, hkpPropertyValue value );
		inline hkpPropertyValue getProperty( hkUint32 key ) const;
		inline hkBool hasProperty( hkUint32 key ) const;
		void lockProperty( hkUint32 key );
		void unlockProperty( hkUint32 key );
		void checkReadWrite();
		void checkReadOnly() const;
		void addReference();
		void removeReference();
		void addReferenceAsCriticalOperation();
		void removeReferenceAsCriticalOperation();
	public:
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		inline void setWorld( hkpWorld* world );
		virtual class hkMotionState* getMotionState() = 0;
		hkpWorldObject( const hkpShape* shape, BroadPhaseType type );
		inline virtual ~hkpWorldObject();
	public:
		inline hkMultiThreadCheck& getMultiThreadCheck();
		inline const hkMultiThreadCheck& getMultiThreadCheck() const;
		inline void copyProperties( const hkpWorldObject* otherObj );
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
class hkpMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpMaterial();
		inline hkReal getFriction() const;
		inline hkReal getRestitution() const;
		inline void setFriction( hkReal newFriction );
		inline void setRestitution( hkReal newRestitution );
		static inline hkReal __cdecl getCombinedFriction( hkReal frictionA, hkReal frictionB);
		static inline hkReal __cdecl getCombinedRestitution( hkReal restitutionA, hkReal restitutionB);
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
		inline void setResponseType( enum hkpMaterial::ResponseType t );
		inline enum hkpMaterial::ResponseType getResponseType() const;
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
	public:
		hkpMaterial( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpConstraintData;
class hkpEntity;
class hkpRigidBody;
class hkpConstraintOwner;
class hkpSimulationIsland;
typedef void hkpConstraintRuntime;
class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
		enum AddReferences
		{
			DO_NOT_ADD_REFERENCES,
			DO_ADD_REFERENCES
		};
		enum CloningMode
		{
			CLONE_INSTANCES_ONLY,
			CLONE_DATAS_WITH_MOTORS
		};
		hkpConstraintInstance(hkpEntity* entityA, hkpEntity* entityB, hkpConstraintData* data, ConstraintPriority priority = PRIORITY_PSI);
		class hkpEntity* m_entities[2];
	public:
		hkEnum<ConstraintPriority,hkUint8> m_priority;
	protected:
		hkBool				m_wantRuntime;
		const char* m_name;
	public:
		hkUlong m_userData;
		struct hkConstraintInternal* m_internal;
	public:
		hkpConstraintInstance(hkFinishLoadedObjectFlag f) { }
	private:
		friend class hkpWorldConstraintUtil;
		friend class hkpSimpleConstraintContactMgr;
		friend class hkpSaveContactPointsUtil;
		hkpConstraintInstance(){}
};
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	inline MotionType getType() const { return m_type; }
	hkpMotion(const hkVector4& position, const hkQuaternion& rotation, bool wantDeactivation = false);
	hkReal getMass() const;
	inline hkSimdReal getMassInv() const;
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	inline const hkVector4& getCenterOfMassLocal() const;
	inline const hkVector4& getCenterOfMassInWorld() const;
	inline hkMotionState* getMotionState();
	inline const hkMotionState* getMotionState() const;
	inline const hkVector4& getPosition() const;
	virtual void setPosition(const hkVector4& position);
	inline const hkQuaternion& getRotation() const;
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline const hkTransform& getTransform() const;
	void approxTransformAt( hkTime time, hkTransform& transformOut );
	virtual void setTransform(const hkTransform& transform);
	inline const hkVector4& getLinearVelocity() const;
	virtual void setLinearVelocity(const hkVector4& newVel);
	inline const hkVector4& getAngularVelocity() const;
	virtual void setAngularVelocity(const hkVector4& newVel);
	__forceinline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
	inline hkReal getLinearDamping();
	inline void setLinearDamping( hkReal d );
	inline hkReal getAngularDamping();
	inline void setAngularDamping( hkReal d );
	inline int getDeactivationClass();
	void setDeactivationClass(int deactivationClass);
	inline void enableDeactivation( bool value, int randomNumber = 0, int worldFlag0 = 0, int worldFlag1 = 0, int worldDeactivationIntegrateCounter = 0);
	inline bool isActivationEnabled() const;
public:
	virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
	inline int getNumInactiveFrames(int select);
	inline int getNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
	inline void setWorldSelectFlagsNeg(int worldFlag0, int worldFlag1, int worldDeactivationIntegrateCounter);
	inline void incrementNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
	inline void zeroNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
public:
	enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );
		virtual ~hkpKeyframedRigidMotion();
		virtual void setMass(hkReal m);
		virtual void setMassInv(hkReal mInv);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	protected:
		hkpKeyframedRigidMotion(): hkpMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = 0; }
	public:
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
	public:
		hkpKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpMaxSizeMotion() : hkpKeyframedRigidMotion( ) {}
		hkpMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkpKeyframedRigidMotion( flag ) {}
	private:
		void operator=(const hkpMaxSizeMotion& other);
		hkpMaxSizeMotion( const hkpMaxSizeMotion& other );
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkpDynamicsContactMgr;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpEntity();
		void addEntityListener( hkpEntityListener* el);
		void removeEntityListener( hkpEntityListener* el);
		void addEntityActivationListener( hkpEntityActivationListener* el);
		void removeEntityActivationListener( hkpEntityActivationListener* el);
		void addCollisionListener( hkpCollisionListener* cl );
		void removeCollisionListener( hkpCollisionListener* cl);
		inline const hkSmallArray<hkpEntityListener*>& getEntityListeners() const;
		inline const hkSmallArray<hkpEntityActivationListener*>& getEntityActivationListeners() const;
		inline const hkSmallArray<hkpCollisionListener*>& getCollisionListeners() const;
		inline bool areCollisionListenersAdded() const;
		inline hkUint16 getProcessContactCallbackDelay() const;
		inline void setProcessContactCallbackDelay( hkUint16 delay );
		inline hkpMaterial& getMaterial();
		inline const hkpMaterial& getMaterial() const;
		inline hkBool isFixed() const;
		inline hkBool isFixedOrKeyframed() const;
		inline hkUint32 getUid() const;
		hkpDynamicsContactMgr* findContactMgrTo(const hkpEntity* entity) const;
		void activate();
		void deactivate();
		void activateAsCriticalOperation();
		void deactivateAsCriticalOperation();
		hkBool isActive() const;
		inline int getNumActions() const;
		inline hkpAction* getAction(int i);
		int getNumConstraints() const;
		hkpConstraintInstance* getConstraint( int i );
		const hkpConstraintInstance* getConstraint( int i ) const;
		inline const hkSmallArray<struct hkConstraintInternal>&  getConstraintMasters() const;
		inline hkSmallArray<struct hkConstraintInternal>&  getConstraintMastersRw();
		inline const hkArray<class hkpConstraintInstance*>&  getConstraintSlaves() const;
		void calcStatistics( hkStatisticsCollector* collector) const;
		void setCachedShapeData(const hkpWorld* world, const hkpShape* shape);
		void updateCachedAabb();
	protected:
		const	hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersImpl() const;
				hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersRwImpl();
		const	hkArray<class hkpConstraintInstance*>&	getConstraintSlavesImpl() const;
		hkpEntity( const hkpShape* shape );
	public:
		hkpEntity( class hkFinishLoadedObjectFlag flag );
		inline hkpMotion* getMotion();
		inline hkpSimulationIsland* getSimulationIsland() const;
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SpuCollisionCallback():
				m_util(0),
				m_capacity(0),
				m_eventFilter(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
				m_userFilter(0x01)
			{
			}
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};
class hkpEntityDeactivator : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool shouldDeactivateHighFrequency( const hkpEntity* entity ) = 0;
		virtual hkBool shouldDeactivateLowFrequency( const hkpEntity* entity ) = 0;
	protected:
		hkpEntityDeactivator() {}
	public:
		hkpEntityDeactivator( class hkFinishLoadedObjectFlag flag ) {}
};
class hkpRigidBodyDeactivator : public hkpEntityDeactivator
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum DeactivatorType
		{
			DEACTIVATOR_INVALID,
			DEACTIVATOR_NEVER,
			DEACTIVATOR_SPATIAL,
			DEACTIVATOR_MAX_ID
		};
		virtual enum DeactivatorType getRigidBodyDeactivatorType() const = 0;
};
class hkpRigidBodyCinfo;
class hkpRigidBody : public hkpEntity
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpRigidBody( const hkpRigidBodyCinfo& info );
		virtual ~hkpRigidBody();
		void getCinfo(hkpRigidBodyCinfo& info) const;
		inline hkReal getMass() const;
		inline hkReal getMassInv() const;
		void setMass(hkReal m);
		void setMassInv(hkReal mInv);
		inline void getInertiaLocal(hkMatrix3& inertiaOut) const;
		inline void getInertiaWorld(hkMatrix3& inertiaOut) const;
		void setInertiaLocal(const hkMatrix3& inertia);
		void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		inline void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		inline void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		void setCenterOfMassLocal(const hkVector4& centerOfMass);
		inline const hkVector4& getCenterOfMassLocal() const;
		inline const hkVector4& getCenterOfMassInWorld() const;
		inline const hkVector4& getPosition() const;
		void setPosition(const hkVector4& position);
		inline const hkQuaternion& getRotation() const;
		void setRotation(const hkQuaternion& rotation);
		void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
		inline const hkTransform& getTransform() const;
		void setTransform(const hkTransform& transform);
		void setPositionAndRotationAsCriticalOperation(const hkVector4& position, const hkQuaternion& rotation);
		inline void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		inline void approxCurrentTransform( hkTransform& transformOut ) const;
		inline const hkVector4& getLinearVelocity() const;
		inline void	setLinearVelocity(const hkVector4& newVel);
		inline const hkVector4& getAngularVelocity() const;
		inline void	setAngularVelocity(const hkVector4& newVel);
		inline void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
		void setLinearVelocityAsCriticalOperation(const hkVector4& newVel);
		void setAngularVelocityAsCriticalOperation(const hkVector4& newVel);
		inline void applyLinearImpulse(const hkVector4& imp);
		inline void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		inline void applyAngularImpulse(const hkVector4& imp);
		void applyLinearImpulseAsCriticalOperation(const hkVector4& imp);
		void applyPointImpulseAsCriticalOperation(const hkVector4& imp, const hkVector4& p);
		void setMotionType( hkpMotion::MotionType newState,
							hkpEntityActivation preferredActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE,
							hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode = HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
		inline hkpMotion::MotionType getMotionType() const;
		hkpMotion* getStoredDynamicMotion();
		const hkpMotion* getStoredDynamicMotion() const;
		void updateCachedShapeInfo (const hkpShape* shape, hkVector4& extentOut );
		inline hkReal getFriction() const;
		inline hkReal getRestitution() const;
		void setFriction( hkReal newFriction );
		void setRestitution( hkReal newRestitution );
		hkWorldOperation::Result setShape(const hkpShape* shape);
		virtual hkpRigidBody* clone() const;
	public:
		inline hkpMotion* getRigidMotion() const;
		void checkPerformance() const;
	public:
		static void __cdecl createDynamicRigidMotion( hkpMotion::MotionType motionType,
																const hkVector4& position, const hkQuaternion& rotation,
																hkReal mass, const hkMatrix3& inertiaLocal, const hkVector4& centreOfMassLocal,
																hkReal maxLinearVelocity, hkReal maxAngularVelocity,
																hkpMaxSizeMotion* motionBufferOut );
		static void __cdecl updateBroadphaseAndResetCollisionInformationOfWarpedBody( hkpEntity* entity );
	protected:
		virtual hkMotionState* getMotionState();
	public:
		hkpRigidBody( class hkFinishLoadedObjectFlag flag ) : hkpEntity( flag ) {}
};
inline hkpMotion* hkpRigidBody::getRigidMotion() const
{
	return const_cast<hkpMaxSizeMotion*>(&m_motion);
}
void hkpRigidBody::setLinearVelocity(const hkVector4& newVel)
{
	;
	activate();
	getRigidMotion()->setLinearVelocity(newVel);
}
void hkpRigidBody::setAngularVelocity(const hkVector4& newVel)
{
	;
	activate();
	getRigidMotion()->setAngularVelocity(newVel);
}
class hkaBone;
class hkaSkeleton
{
	public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkaSkeleton();
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int		m_numReferencePose;
		char**	m_floatSlots;
		hkInt32 m_numFloatSlots;
	public:
		__forceinline hkaSkeleton( hkFinishLoadedObjectFlag flag ) {}
};
class hkaRagdollInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkaRagdollInstance ( const hkArray<hkpRigidBody*>& rigidBodies, const hkArray<hkpConstraintInstance*>& constraints, const hkaSkeleton* skeleton );
		virtual ~hkaRagdollInstance ();
		virtual hkaRagdollInstance* clone(hkpConstraintInstance::CloningMode mode = hkpConstraintInstance::CLONE_INSTANCES_ONLY) const;
		inline int getNumBones () const;
		inline hkpRigidBody* getRigidBodyOfBone (int i) const;
		inline int getBoneIndexOfRigidBody (hkpRigidBody* rb) const;
		inline hkpConstraintInstance* getConstraintOfBone (int i) const;
		inline const hkaSkeleton* getSkeleton () const;
		inline int getParentOfBone (int i) const;
		inline const hkArray<hkpRigidBody*>& getRigidBodyArray() const;
		inline const hkArray<hkpConstraintInstance*>& getConstraintArray() const;
		inline hkBool hasNonRigidBodyBones () const;
		void getPoseWorldSpace (hkQsTransform* poseWorldSpaceOut) const;
		void setPoseWorldSpace (const hkQsTransform* poseModelSpaceIn);
		void getPoseModelSpace (hkQsTransform* poseModelSpaceOut, const hkQsTransform& worldFromModel) const;
		void FUN_00961300 (const hkQsTransform* poseModelSpaceIn, const hkQsTransform& worldFromModel);
		void setPoseAndVelocitiesModelSpace ( const hkQsTransform* poseModelSpaceA, const hkQsTransform& worldFromModelA,
											const hkQsTransform* poseModelSpaceB, const hkQsTransform& worldFromModelB, hkReal timestep);
		hkResult addToWorld (hkpWorld* world, hkBool updateFilter) const;
		hkResult removeFromWorld () const;
		inline hkpWorld* getWorld() const;
		void getWorldFromBoneTransform (int i, hkQsTransform& worldFromBoneOut) const;
		void getApproxWorldFromBoneTransformAt (int i, hkReal time, hkQsTransform& worldFromBoneOut) const;
	public:
		 hkArray<hkpRigidBody*> m_rigidBodies;
		 hkArray<hkpConstraintInstance*> m_constraints;
		 hkArray<int> m_boneToRigidBodyMap;
		const hkaSkeleton* m_skeleton;
	public:
		hkaRagdollInstance( hkFinishLoadedObjectFlag f ) : m_rigidBodies(f), m_constraints(f), m_boneToRigidBodyMap(f) { }
	private:
		void commonInit (const hkArray<hkpRigidBody*>& rigidBodies, const hkArray<hkpConstraintInstance*>& constraints, const hkaSkeleton* skeleton);
};
hkpRigidBody* hkaRagdollInstance::getRigidBodyOfBone (int i) const
{
	const int rbIdx = m_boneToRigidBodyMap[i];
	return (rbIdx<0) ? 0 : m_rigidBodies[rbIdx];
}
void hkaRagdollInstance::FUN_00961300( const hkQsTransform* poseIn, const hkQsTransform& worldFromModel )
{
	const int numBones = m_skeleton->m_numBones;
	for (int b=0; b < numBones; b++)
	{
		hkpRigidBody* rbody = getRigidBodyOfBone(b);
		if (rbody)
		{
			hkQsTransform rbTransform; rbTransform.setMul( worldFromModel, poseIn[b] );
			rbTransform.m_rotation.normalize();
			rbody->setPositionAndRotation( rbTransform.getTranslation(), rbTransform.getRotation() );
			rbody->setLinearVelocity( hkVector4::getZero() );
			rbody->setAngularVelocity( hkVector4::getZero() );
		}
	}
}

}  // namespace f3m_00961300

// @f3 0x00961b50 (community match, verified in this file)
namespace f3m_00961b50 {
extern int DAT_01092a50;
namespace n961b50 {
struct Vector4 { float x, y, z, w; };
struct Point3 { float x, y, z; };
struct Quaternion { float x, y, z, w; };
struct MotionState {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void SetLinearVelocity(const Vector4& v);
    virtual void SetAngularVelocity(const Vector4& v);
};
struct RigidBody {
    char pad[0xd0];
    MotionState motion;
    void FUN_0090d650(const Point3& position, const Quaternion& rotation);
    void FUN_0090b500();
};
struct Pose { Point3 translation; char pad0[4]; Quaternion rotation; char pad1[0x10]; };
struct Skeleton { char pad[0x10]; int count; };
}
struct RagdollHelper961b50 {
    char pad0[8];
    n961b50::RigidBody** bodies;
    char pad1[0x14];
    int* boneMap;
    char pad2[8];
    n961b50::Skeleton* skeleton;
    void FUN_00961b50(const n961b50::Pose* pose);
};
// pdb: hkaRagdollInstance::setPoseWorldSpace | hkaRagdollInstance.obj | tesv_win, caller_sim, low
void RagdollHelper961b50::FUN_00961b50(const n961b50::Pose* pose)
{
    int numBones = skeleton->count;
    int i = 0;
    if (numBones > 0)
    {
        const n961b50::Pose* cursor = pose;
        do
        {
            int rbIndex = boneMap[i];
            if (rbIndex >= 0)
            {
                n961b50::RigidBody* rb = bodies[rbIndex];
                if (rb)
                {
                    const n961b50::Vector4& zero = *(const n961b50::Vector4*)&DAT_01092a50;
                    rb->FUN_0090d650(cursor->translation, cursor->rotation);
                    rb->FUN_0090b500();
                    rb->motion.SetLinearVelocity(zero);
                    rb->FUN_0090b500();
                    rb->motion.SetAngularVelocity(zero);
                }
            }
            ++cursor;
            ++i;
        } while (i < numBones);
    }
}
}

// @f3 0x0097f1c0 (community match, verified in this file)
namespace f3m_0097f1c0 {
// claim clm_3dd184e1b8ce4185ba73 -- FUN_0097f1c0 at 0x0097f1c0, 64 bytes
//
// The original stores the vtable of the polymorphic Havok class hkpSimulation
// (its RTTI type descriptor is ".?AVhkpSimulation@@") plus the constants
// 0.0f, -1.0f, 0.0001f and 1/0 into fixed member offsets, i.e. it is that
// class's constructor taking one argument on the stack.
//
// The stores split into two phases: the ones at 0x06 and 0x0c are emitted
// before the vtable store and the ones at 0x10/0x14/0x18/0x20/0x24/0x28 after
// it, which is what an inlined base-class constructor (whose own vtable store
// the optimiser drops) followed by the derived constructor produces.

class hkpSimulationBase
{
public:
    hkpSimulationBase(int world) { m_unk06 = 1; m_unk0c = world; }

    virtual void FUN_vb0();
    virtual void FUN_vb1();
    virtual void FUN_vb2();
    virtual void FUN_vb3();
    virtual void FUN_vb4();
    virtual void FUN_vb5();
    virtual void FUN_vb6();

    short m_unk04;
    short m_unk06;
    int m_unk08;
    int m_unk0c;
};

class hkpSimulation : public hkpSimulationBase
{
public:
    hkpSimulation(int world);

    virtual void FUN_v00();
    virtual void FUN_v01();
    virtual void FUN_v02();

    char m_unk10;
    float m_unk14;
    float m_unk18;
    float m_unk1c;
    float m_unk20;
    float m_unk24;
    int m_unk28;
};

// pdb: hkpSimulation::hkpSimulation | hkpSimulation.obj | fnv360_0822_retail, call_gap, medium
// pdb params: world
hkpSimulation::hkpSimulation(int world)
    : hkpSimulationBase(world)
{
    m_unk14 = 0.0f;
    m_unk18 = 0.0f;
    m_unk20 = -1.0f;
    m_unk24 = 0.0001f;
    m_unk28 = 0;
    m_unk10 = 1;
    m_unk08 = 0;
}
}   // namespace f3m_0097f1c0

// @f3 0x0096fa60 (community match, verified in this file)
namespace f3m_0096fa60 {
struct __declspec(align(16)) Vfa60
{
    float x, y, z, w;
    __forceinline void operator=(const Vfa60& a)
    {
        x = a.x; y = a.y; z = a.z; w = a.w;
    }
    __forceinline void setSub4(const Vfa60& a, const Vfa60& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void setAdd4(const Vfa60& a, const Vfa60& b)
    {
        x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w;
    }
    __forceinline float dot3(const Vfa60& a) const
    {
        return x * a.x + y * a.y + z * a.z;
    }
    __forceinline void addMul4(float rs, const Vfa60& a)
    {
        float r = float(rs);
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
};
// pdb: hkLineSegmentUtil::closestPointLineSeg | hkLineSegmentUtil.obj | fnv360_0822_retail, call_seq, medium
// pdb params: A, B, B2, result
int FUN_0096fa60(const Vfa60& p, const Vfa60& a, const Vfa60& b, Vfa60& out)
{
    Vfa60 ap;
    ap.setSub4(p, a);
    Vfa60 ab;
    ab.setSub4(b, a);
    float t = ab.dot3(ap);
    float l = ab.dot3(ab);
    if (t <= 0.0f)
    {
        out = a;
        return 8;
    }
    if (l <= t)
    {
        out.setAdd4(a, ab);
        return 4;
    }
    out = a;
    out.addMul4(t / l, ab);
    return 0;
}
}   // namespace f3m_0096fa60

// @f3 0x00960820 (community match, verified in this file)
namespace f3m_00960820 {



__declspec(align(16)) struct Vec4_960820 {
    union { struct { float x, y, z, w; }; float lanes[4]; };
    Vec4_960820& operator=(const Vec4_960820& a) { x = a.x; y = a.y; z = a.z; w = a.w; return *this; }
    void setZero4() { x = y = z = w = 0.0f; }
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void _setRotatedDir(const struct Quat_960820& quat, const Vec4_960820& direction);
    void setAll(float f) { x = f; y = f; z = f; w = f; }
    float dot3(const Vec4_960820& a) const { return x * a.x + y * a.y + z * a.z; }
    float dot4(const Vec4_960820& a) const { return x * a.x + y * a.y + z * a.z + w * a.w; }
    void setMul4(float r, const Vec4_960820& a) { x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    void addMul4(float r, const Vec4_960820& a) { x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    void setAdd4(const Vec4_960820& a, const Vec4_960820& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    void sub4(const Vec4_960820& a) { x -= a.x; y -= a.y; z -= a.z; w -= a.w; }
    void setCross(const Vec4_960820& a, const Vec4_960820& b)
    {
        float cx = a.y * b.z - a.z * b.y;
        float cy = a.z * b.x - a.x * b.z;
        float cz = a.x * b.y - a.y * b.x;
        x = cx; y = cy; z = cz; w = 0.0f;
    }
};

struct RotationBasis_960820 { Vec4_960820 columns[3]; };

struct Quat_960820 {
    Vec4_960820 m_vec;
    void FUN_00924360(const RotationBasis_960820& rotation);
    void FUN_008d3290(const Quat_960820& first, const Quat_960820& second);
    const Vec4_960820& getImag() const { return m_vec; }
    void setIdentity() { m_vec.set(0.0f, 0.0f, 0.0f, 1.0f); }
    void FUN_008db610(const Vec4_960820& from, const Vec4_960820& to);
    void FUN_00924a70(const Vec4_960820& axis, Quat_960820& restOut, float& angleOut) const;
    void FUN_009240d0(const Vec4_960820& axis, float angle);
};

__forceinline void Vec4_960820::_setRotatedDir(const Quat_960820& quat, const Vec4_960820& direction)
{
    float qreal = quat.m_vec.w;
    float q2minus1 = qreal * qreal - 0.5f;

    Vec4_960820 ret;
    ret.setMul4(q2minus1, direction);

    float imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());

    Vec4_960820 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

struct QsTransform_960820 {
    Vec4_960820 m_translation;
    Quat_960820 m_rotation;
    Vec4_960820 m_scale;
    void setIdentity() { m_translation.setZero4(); m_rotation.setIdentity(); m_scale.setAll(1.0f); }
};

struct Elem_960820 { Vec4_960820 a; Vec4_960820 b; };
extern float DAT_00de6e60;
static void FUN_009604c0(const Vec4_960820& up, Quat_960820& poseRotation)
{
    Vec4_960820 seed;
    seed.setZero4();
    const float ax = static_cast<float>(fabs(up.x));
    const float ay = static_cast<float>(fabs(up.y));
    const float az = static_cast<float>(fabs(up.z));
    const int dominant = ay > ax ? (az > ay ? 2 : 1) : (az > ax ? 2 : 0);
    seed.lanes[(dominant + 1) % 3] = 1.0f;

    Vec4_960820 heading;
    heading._setRotatedDir(poseRotation, seed);
    Vec4_960820 right;
    right.setCross(heading, up);
    const float squared = right.dot3(right);
    const float invLength = squared == 0.0f ? 0.0f : 1.0f / static_cast<float>(sqrt(squared));
    right.setMul4(invLength, right);

    RotationBasis_960820 basis;
    basis.columns[0].setCross(up, right);
    basis.columns[1] = up;
    basis.columns[2] = right;
    Quat_960820 frame;
    frame.FUN_00924360(basis);
    Quat_960820 inverseFrame;
    inverseFrame.m_vec.set(-frame.m_vec.x, -frame.m_vec.y, -frame.m_vec.z, frame.m_vec.w);
    Quat_960820 residual;
    residual.FUN_008d3290(inverseFrame, poseRotation);
    poseRotation = residual;
}

struct Owner_960820 {
    Elem_960820* m_data;
    int m_size;
    int unk08;
    int unk0c;
    Vec4_960820 modelUp;
    short unk20;
    void FUN_00960090(const QsTransform_960820* pose, Quat_960820* out);
    int FUN_00960820(const QsTransform_960820* pose, float* outDist);

};

static inline float absf_960820(float f) { return (float)fabs(f); }

// pdb: hkaPoseMatchingUtility::findBestCandidatePoseIndex | hkaPoseMatchingUtility.obj | tesv_win, caller_sim, low
int Owner_960820::FUN_00960820(const QsTransform_960820* pose, float* outDist)
{
    Quat_960820 poseRotation;
    FUN_00960090(pose, &poseRotation);
    FUN_009604c0(modelUp, poseRotation);
    
    *outDist = DAT_00de6e60;
    int best = -1;
    for (int i = 0; i < m_size; i++) {
        const Vec4_960820& p = m_data[i].a;
        float d = poseRotation.m_vec.dot4(p);
        d = absf_960820(d);
        d = 1.0f - d;
        if (d < *outDist) {
            *outDist = d;
            best = i;
        }
    }
    return best;
}

}   // namespace f3m_00960820

// @f3 0x009608e0 (community match, verified in this file)
#include <math.h>
namespace f3m_009608e0 {
namespace pose9608 {
typedef float hkReal;
typedef float hkSimdReal;
typedef float hkSimdRealParameter;
struct hkQuaternion;
struct __declspec(align(16)) hkVector4 {
    float x,y,z,w;
    __forceinline void sub4(const hkVector4& a) { x-=a.x; y-=a.y; z-=a.z; w-=a.w; }
    __forceinline void setAll(float a) { x=a; y=a; z=a; w=a; }
    __forceinline void setZero4() { x=y=z=w=0; }
    __forceinline float& operator()(int);
    __forceinline const float& operator()(int) const;
    __forceinline void operator=(const hkVector4&);
    __forceinline void set(float,float,float,float);
    __forceinline void setAdd4(const hkVector4&, const hkVector4&);
    __forceinline void setSub4(const hkVector4&, const hkVector4&);
    __forceinline void setMul4(float,const hkVector4&);
    __forceinline void addMul4(float,const hkVector4&);
    __forceinline void setCross(const hkVector4&,const hkVector4&);
    __forceinline float dot3(const hkVector4&) const;
    __forceinline void setRotatedDir(const hkQuaternion&,const hkVector4&);
};
struct Basis { hkVector4 column[3]; };
struct hkQuaternion {
    void FUN_00924360(const Basis&);
    hkVector4 m_vec;
    __forceinline void setIdentity() { m_vec.set(0,0,0,1); }
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline void operator=(const hkQuaternion& q) { m_vec = q.m_vec; }
    void FUN_008db610(const hkQuaternion*,const hkQuaternion*);
    void FUN_00924a70(const hkVector4*,hkQuaternion*,float*) const;
    void FUN_009240d0(const hkVector4*,float);
};
struct hkQsTransform {
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
    __forceinline const hkQuaternion& getRotation() const { return m_rotation; }
    __forceinline void setTranslation(const hkVector4& v) { m_vTranslation=v; }
    __forceinline const hkVector4& getTranslation() const { return m_vTranslation; }
    __forceinline void setIdentity() {
        m_vTranslation.setZero4();
        m_rotation.setIdentity();
        m_vScale.setAll(1.0f);
    }
};
inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}

inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}

struct OrientationReader
{
    void FUN_00960090(const hkQsTransform* arr, hkQuaternion* out);
};

struct PoseLayout
{
    hkVector4 referenceDirection;
    hkVector4 modelUp;
    short rootIndex, secondIndex, thirdIndex;
};

// Normalize the three spatial components, scaling all four lanes.
static __forceinline void normalize3(hkVector4& v) {
    float d = v.dot3(v);
    float s = d ? 1.0f/(float)sqrt(d) : 0.0f;
    v.setMul4(s,v);
}
// Build the pose basis from the three indexed bone positions.
inline void OrientationReader::FUN_00960090(const hkQsTransform* arr, hkQuaternion* out) {
    const PoseLayout* self = (const PoseLayout*)this;
    hkVector4 p0 = arr[self->rootIndex].m_vTranslation;
    hkVector4 p1 = arr[self->secondIndex].m_vTranslation;
    hkVector4 p2 = arr[self->thirdIndex].m_vTranslation;
    hkVector4 n1, n2, c, c2, b;
    n1.setSub4(p1,p0);
    normalize3(n1);
    n2.setSub4(p2,p0);
    normalize3(n2);
    c.setCross(n2,n1);
    normalize3(c);
    c2.setCross(c,n1);
    normalize3(c2);
    b.setCross(n1,c2);
    Basis axes;
    axes.column[0] = c2;
    axes.column[1] = b;
    axes.column[2] = n1;
    hkQuaternion q;
    q.FUN_00924360(axes);
    *out = q;
}

// Product of the first rotation and the inverse of the second.
inline void hkQuaternion::FUN_008db610(const hkQuaternion* first, const hkQuaternion* second) {
    const hkVector4& a=first->m_vec;
    const hkVector4& b=second->m_vec;
    hkVector4 v;
    v.setCross(b,a);
    float r=a.w;
    v.x -= r*b.x;
    v.y -= r*b.y;
    v.z -= r*b.z;
    v.w -= r*b.w;
    v.addMul4(b.w,a);
    m_vec=v;
    m_vec.w=a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

class PoseMatcher
{
  public:
    void FUN_009608e0(const hkQsTransform* sourcePose, const hkQsTransform* targetPose, hkQsTransform* twistTransform, hkQsTransform* fullTransform);
};

void PoseMatcher::FUN_009608e0(const hkQsTransform* sourcePose, const hkQsTransform* targetPose, hkQsTransform* twistTransform, hkQsTransform* fullTransform)
{
    PoseLayout* self = (PoseLayout*)this;
    hkQuaternion q0, q1;

    ((OrientationReader*)self)->FUN_00960090(sourcePose, &q0);
    ((OrientationReader*)self)->FUN_00960090(targetPose, &q1);

    fullTransform->setIdentity();
    int index = self->rootIndex;
    fullTransform->setTranslation(targetPose[index].getTranslation());
    fullTransform->m_rotation.FUN_008db610(&q1, &q0);

    hkVector4 rotated;
    rotated.setRotatedDir(fullTransform->getRotation(), sourcePose[index].getTranslation());
    fullTransform->m_vTranslation.sub4(rotated);

    twistTransform->setIdentity();
    *twistTransform = *fullTransform;

    {
        float angle;
        hkQuaternion axis;
        twistTransform->m_rotation.FUN_00924a70(&self->modelUp, &axis, &angle);
        twistTransform->m_rotation.FUN_009240d0(&self->modelUp, angle);
    }
}
}
}   // namespace f3m_009608e0

// @f3 0x0097eaf0 (community match, verified in this file)
namespace f3m_0097eaf0 {
namespace f3m_0097eaf0 {

struct hkClass;
struct hkClassMember;
struct MemberInfo;
struct Collector;

struct ClassRegistry
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual MemberInfo* getClassInfo(const hkClass& klass);
};

struct hkClass
{
    int FUN_00d46f70() const;                         // getNumMembers()
    const hkClassMember& FUN_00d46f80(int i) const;   // getMember(i)
    int FUN_00d470d0() const;                         // getObjectSize()
};

struct hkBool
{
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }
    char m_bool;
};

struct hkClassMember
{
    enum Type
    {
        TYPE_POINTER = 20,
        TYPE_FUNCTIONPOINTER,
        TYPE_ARRAY,
        TYPE_INPLACEARRAY,
        TYPE_ENUM,
        TYPE_STRUCT,
        TYPE_SIMPLEARRAY,
        TYPE_HOMOGENEOUSARRAY,
        TYPE_VARIANT,
        TYPE_CSTRING
    };
    enum FlagValues
    {
        NOT_OWNED = 512
    };

    const char* m_name;
    const hkClass* m_class;
    const void* m_enum;
    unsigned char m_type;
    unsigned char m_subtype;
    short m_cArraySize;
    unsigned short m_flags;
    unsigned short m_offset;

    __forceinline hkBool isNotOwned() const { return (m_flags & NOT_OWNED) != 0; }
    int FUN_00d86940() const;              // getCstyleArraySize()
    const hkClass& FUN_00d46d60() const;   // getStructClass()
};

struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};

struct hkArrayBase
{
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct hkClassMemberAccessor
{
    struct SimpleArray
    {
        void* data;
        int size;
    };
    struct HomogeneousArray
    {
        const hkClass* klass;
        void* data;
        int size;
    };

    void* m_address;
    const hkClassMember* m_member;

    hkClassMemberAccessor* FUN_00d87180(void* object, const hkClassMember* member);
    __forceinline hkClassMemberAccessor(void* object, const hkClassMember* member) { FUN_00d87180(object, member); }

    char*& FUN_00d87220(int index);              // asCstring(index)
    SimpleArray& FUN_00d87290(int index);        // asSimpleArray(index)
    HomogeneousArray& FUN_00d87350(int index);   // asHomogeneousArray(index)
};

ClassRegistry* FUN_0097e8d0(ClassRegistry* registry);
void FUN_0097e7a0(const hkClassMember* member, const char* string, MemberInfo* info, Collector* collector);
void FUN_0097e7f0(const hkClassMember* member, const void* data, int size, int capacity, int elementSize, MemberInfo* info, Collector* collector);
void FUN_0097e900(const char* name, const void* object, const hkClass* klass, Collector* collector, ClassRegistry* registry);
int FUN_0097e9c0(const hkClassMember* member);
void FUN_0097ea00(const hkClassMember* member, const void* data, const hkClass* klass, int size, Collector* collector, ClassRegistry* registry);
void FUN_0097ea60(const hkClassMember* member, const void* data, int size, Collector* collector, ClassRegistry* registry);

}
using namespace f3m_0097eaf0;

void __cdecl FUN_0097eaf0(void* object, const hkClass& klass, Collector* collector, ClassRegistry* registry)
{
    if (object == 0)
    {
        return;
    }

    registry = FUN_0097e8d0(registry);
    MemberInfo* info = registry->getClassInfo(klass);

    int numMembers = klass.FUN_00d46f70();
    for (int i = 0; i < numMembers; i++)
    {
        const hkClassMember& member = klass.FUN_00d46f80(i);
        if (member.isNotOwned())
        {
            continue;
        }

        switch (member.m_type)
        {
            case hkClassMember::TYPE_CSTRING:
            {
                hkClassMemberAccessor maccess(object, &member);
                int arraySize = member.FUN_00d86940();
                if (arraySize <= 1)
                {
                    FUN_0097e7a0(&member, maccess.FUN_00d87220(0), info, collector);
                }
                else
                {
                    for (int j = 0; j < arraySize; j++)
                    {
                        FUN_0097e7a0(&member, maccess.FUN_00d87220(j), info, collector);
                    }
                }
                break;
            }
            case hkClassMember::TYPE_ARRAY:
            {
                hkArrayBase& array = *reinterpret_cast<hkArrayBase*>(static_cast<char*>(object) + member.m_offset);
                if (array.m_capacityAndFlags & hkArrayBase::DONT_DEALLOCATE_FLAG)
                {
                    break;
                }
                int size = array.m_size;
                int capacity = array.m_capacityAndFlags & hkArrayBase::CAPACITY_MASK;
                int elementSize = FUN_0097e9c0(&member);
                FUN_0097e7f0(&member, array.m_data, size, capacity, elementSize, info, collector);
                FUN_0097ea60(&member, array.m_data, size, collector, registry);
                break;
            }
            case hkClassMember::TYPE_SIMPLEARRAY:
            {
                hkClassMemberAccessor maccess(object, &member);
                hkClassMemberAccessor::SimpleArray array = maccess.FUN_00d87290(0);
                int elementSize = FUN_0097e9c0(&member);
                FUN_0097e7f0(&member, array.data, array.size, array.size, elementSize, info, collector);
                FUN_0097ea60(&member, array.data, array.size, collector, registry);
                break;
            }
            case hkClassMember::TYPE_HOMOGENEOUSARRAY:
            {
                hkClassMemberAccessor maccess(object, &member);
                hkClassMemberAccessor::HomogeneousArray array = maccess.FUN_00d87350(0);
                if (array.size > 0 && array.klass && array.data)
                {
                    FUN_0097e7f0(&member, array.data, array.size, array.size, array.klass->FUN_00d470d0(), info, collector);
                    FUN_0097ea00(&member, array.data, array.klass, array.size, collector, registry);
                }
                break;
            }
            case hkClassMember::TYPE_POINTER:
            {
                if (member.m_subtype == hkClassMember::TYPE_STRUCT)
                {
                    void* pointer = *reinterpret_cast<void**>(static_cast<char*>(object) + member.m_offset);
                    const char* name = member.m_name;
                    FUN_0097e900(name, pointer, &member.FUN_00d46d60(), collector, registry);
                }
                break;
            }
            case hkClassMember::TYPE_VARIANT:
            {
                hkVariant& variant = *reinterpret_cast<hkVariant*>(static_cast<char*>(object) + member.m_offset);
                if (variant.m_object && variant.m_class)
                {
                    FUN_0097e900(member.m_name, variant.m_object, variant.m_class, collector, registry);
                }
                break;
            }
        }
    }
}
}   // namespace f3m_0097eaf0

// @f3 0x00963fc0 (community match, verified in this file)
#include <math.h>
namespace f3m_00963fc0 {
namespace f3m_00963fc0 {

__forceinline float sqrtInverse(float r)
{
    return 1.0f / sqrtf(r);
}

struct hkVector4
{
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;

    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline float operator()(int i) const { return (&x)[i]; }

    __forceinline void set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    __forceinline float dot4(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z) + (w * a.w);
    }

    __forceinline void mul4(float rs)
    {
        float s = float(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }

    __forceinline void setSqrtInverse4(const hkVector4& v)
    {
        x = sqrtInverse(v.x);
        y = sqrtInverse(v.y);
        z = sqrtInverse(v.z);
        w = sqrtInverse(v.w);
    }

    __forceinline float getSimdAt(int i) const { return (&x)[i]; }
};

struct hkQuaternion
{
    hkVector4 m_vec;
    void FUN_004e5c20();
    __forceinline void normalize() { FUN_004e5c20(); }
};

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

__forceinline void dot4_4vs4(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                             const hkVector4& a2, const hkVector4& b2, const hkVector4& a3, const hkVector4& b3,
                             hkVector4& dotsOut)
{
    dotsOut.set(a0.dot4(b0), a1.dot4(b1), a2.dot4(b2), a3.dot4(b3));
}

__forceinline void normalizeRotations(hkQsTransform* transformsInOut, unsigned int numTransforms)
{
    hkQsTransform* blockStart = transformsInOut;
    unsigned int numTransformsOver4 = numTransforms / 4;
    for (unsigned int i = 0; i < numTransformsOver4; i++)
    {
        hkVector4 dots;
        dot4_4vs4(blockStart[0].m_rotation.m_vec, blockStart[0].m_rotation.m_vec,
                  blockStart[1].m_rotation.m_vec, blockStart[1].m_rotation.m_vec,
                  blockStart[2].m_rotation.m_vec, blockStart[2].m_rotation.m_vec,
                  blockStart[3].m_rotation.m_vec, blockStart[3].m_rotation.m_vec,
                  dots);
        hkVector4 inverseSqrtDots;
        inverseSqrtDots.setSqrtInverse4(dots);

        blockStart[0].m_rotation.m_vec.mul4(inverseSqrtDots.getSimdAt(0));
        blockStart[1].m_rotation.m_vec.mul4(inverseSqrtDots.getSimdAt(1));
        blockStart[2].m_rotation.m_vec.mul4(inverseSqrtDots.getSimdAt(2));
        blockStart[3].m_rotation.m_vec.mul4(inverseSqrtDots.getSimdAt(3));
        blockStart += 4;
    }

    unsigned int leftovers = numTransforms % 4;
    for (unsigned int j = 0; j < leftovers; j++)
    {
        blockStart[j].m_rotation.normalize();
    }
}

}

using namespace f3m_00963fc0;

void __cdecl FUN_00963fc0(hkQsTransform* transforms, const float* weights, unsigned int numTransforms)
{
    for (unsigned int i = 0; i < numTransforms; i++)
    {
        const float invWeight = 1.0f / weights[i];
        transforms[i].m_translation.mul4(invWeight);
        transforms[i].m_scale.mul4(invWeight);
    }
    normalizeRotations(transforms, numTransforms);
}
}   // namespace f3m_00963fc0

// @f3 0x00963ba0 (community match, verified in this file)
namespace f3m_00963ba0 {
namespace f3m_00963ba0 {

struct hkThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    static hkThreadMemory* getInstance() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};

template <class T> __forceinline void _copy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
        dst[i] = src[i];
}

template <class T> struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    __forceinline hkArray& operator=(const hkArray& a) {
        if (getCapacity() < a.size) {
            if ((capacityAndFlags & 0x80000000) == 0)
                hkThreadMemory::getInstance()->FUN_008f6d90(data, getCapacity() * sizeof(T), 0x17);
            data = (T*)hkThreadMemory::getInstance()->FUN_008f6d30(a.size * sizeof(T), 0x17);
            capacityAndFlags = (capacityAndFlags & 0x40000000) | a.size;
        }
        size = a.size;
        _copy(data, a.data, size);
        return *this;
    }
};

struct hkVector4 {
    float x, y, z, w;
    hkVector4& operator=(const hkVector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};

struct hkQsTransform {
    hkVector4 m_translation;
    hkVector4 m_rotation;
    hkVector4 m_scale;
};

struct SimpleMapping {
    short m_boneA;
    short m_boneB;
    int pad04, pad08, pad0c;
    hkQsTransform m_aFromBTransform;
    SimpleMapping& operator=(const SimpleMapping& o)
    {
        m_boneA = o.m_boneA;
        m_boneB = o.m_boneB;
        m_aFromBTransform = o.m_aFromBTransform;
        return *this;
    }
};

struct ChainMapping {
    short m_startBoneA, m_endBoneA, m_startBoneB, m_endBoneB;
    int pad08, pad0c;
    hkQsTransform m_startAFromBTransform;
    hkQsTransform m_endAFromBTransform;
    ChainMapping& FUN_00963ab0(const ChainMapping& o);
    ChainMapping& operator=(const ChainMapping& o) { return FUN_00963ab0(o); }
};

struct hkaSkeletonMapperData {
    void* m_skeletonA;
    void* m_skeletonB;
    hkArray<SimpleMapping> m_simpleMappings;
    hkArray<ChainMapping> m_chainMappings;
    hkArray<short> m_unmappedBones;
    bool m_keepUnmappedLocal;
    hkaSkeletonMapperData& FUN_00963ba0(const hkaSkeletonMapperData& o);
};

hkaSkeletonMapperData& hkaSkeletonMapperData::FUN_00963ba0(const hkaSkeletonMapperData& o)
{
    m_skeletonA = o.m_skeletonA;
    m_skeletonB = o.m_skeletonB;
    m_simpleMappings = o.m_simpleMappings;
    m_chainMappings = o.m_chainMappings;
    m_unmappedBones = o.m_unmappedBones;
    m_keepUnmappedLocal = o.m_keepUnmappedLocal;
    return *this;
}

}
}   // namespace f3m_00963ba0
