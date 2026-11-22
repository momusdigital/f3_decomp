#include "f3_common.h"
// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Pair
{
    int a;
    int b;
};

struct Out
{
    int res;
    int val;
};

struct Updater
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int update(int x, int y);
};

// Copies src into dest, calling self->update and other->update for each changed component and storing results in out1 and out2.
// @fnv 0x00da4a50
// pdb: extractChildShapes | hkpAgent1nMachineProcess.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00da4a50(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y,
                                              Out* out2, Out* out1)
{
    Out** ppOut1 = &out1;
    Out* pOut1 = *ppOut1;
    int b = src->b;
    if (dest->b != b)
    {
        dest->b = b;
        pOut1->res = self->update(b, flag);
        pOut1->val = b;
    }
    int a = src->a;
    if (dest->a != a)
    {
        dest->a = a;
        out2->res = other->update(a, y);
        out2->val = a;
    }
}

void S00da4a50_Wrap(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1)
{
    FUN_00da4a50(self, flag, dest, src, other, y, out2, out1);
}

// @fnv 0x00da4960
static __declspec(noinline) int FUN_00da4960(int savedValue, Out* out, Updater* obj, int value)
{
    int result = obj->update(savedValue, value);
    out->res = result;
    out->val = savedValue;
    return result;
}
extern int volatile probeSaved;
extern Out* volatile probeOut;
extern Updater* volatile probeObj;
extern int volatile probeValue;
extern int volatile probeSink;
void callProbe()
{
    probeSink = FUN_00da4960(probeSaved, probeOut, probeObj, probeValue);
}

extern "C" void _ReadWriteBarrier();
struct DaPair
{
    void* a;
    void* b;
};
struct DaSub
{
    DaPair pair;
    void* unk08;
};
struct DaShape
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
    float unk50;
};
struct DaSource
{
    DaSub* unk00;
    DaSub* unk04;
    void* unk08;
    DaShape* unk0c;
    void* unk10;
};
struct DaDest
{
    DaPair pair;
    void* unk08;
    DaSub* unk0c;
};
struct DaResult
{
    void* unk00;
    void* unk04;
    void* unk08;
    DaShape* unk0c;
    void* unk10;
};
struct DaNode
{
    void* unk00;
    void* unk04;
    void* unk08;
    DaSub* unk0c;
};
// Calls FUN_00cf1510 to fill dest+0x20 and dest+0x60, sets up dest, its node and result from source, then calls FUN_00cb22f0 on result+0x20.
// @f3 0x00a2b820 (community match, verified in this file)
namespace wa2b820 {
struct Src {
    DaSub* unk00;
    DaSub* unk04;
    DaShape* unk08;
    void* unk0c;
};
struct Res {
    void* unk00;
    void* unk04;
    DaShape* unk08;
    void* unk0c;
};
struct Recv {
    void FUN_00925300(void*, void*);
};
void* __cdecl hkSweptTransformUtil_lerp2(void*, float, void*);
}
// pdb: hkpProcessCollisionData::ToiInfo::flip | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkAgent1nMachine_initInputAtTime)
static __declspec(noinline) void FUN_00da49b0(DaDest* dest, DaSource* source_, void* p)
{
    using namespace wa2b820;
    Src* source = (Src*)source_;
    Res* result = (Res*)p;
    float value = source->unk08->unk50;
    void* first = (char*)dest + 0x20;
    hkSweptTransformUtil_lerp2((char*)source->unk00->unk08 + 0x40, value, first);
    p = (char*)dest + 0x60;
    hkSweptTransformUtil_lerp2((char*)source->unk04->unk08 + 0x40, source->unk08->unk50, p);
    DaNode* node = (DaNode*)((char*)dest + 0x10);
    result->unk00 = dest;
    result->unk04 = node;
    result->unk0c = source->unk0c;
    result->unk08 = source->unk08;
    void* b = source->unk00->pair.b;
    void* a = source->unk00->pair.a;
    dest->pair.a = a;
    dest->pair.b = b;
    dest->unk0c = source->unk00;
    dest->unk08 = first;
    if (node)
    {
        _ReadWriteBarrier();
        node->unk0c = source->unk04;
        node->unk08 = p;
    }
    _ReadWriteBarrier();
    ((Recv*)((char*)result + 0x10))->FUN_00925300(first, p);
}

DaDest* volatile daDest;
DaSource* volatile daSource;
DaResult* volatile daResult;
void daCaller()
{
    FUN_00da49b0(daDest, daSource, daResult);
}
