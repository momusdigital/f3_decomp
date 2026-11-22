#include "f3_common.h"
// src/havok/physics/collide/filter/null/hkpnullcollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/null/hkpnullcollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpNullCollisionFilter.h"

extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
struct __declspec(align(16)) S_00cfab30_vec
{
    union
    {
        __m128 v;
        float f[4];
    };
};

struct S_00cfab30_arg
{
    S_00cfab30_vec vec;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char unk20;
};

struct __declspec(align(16)) S_00cfab30_local
{
    S_00cfab30_vec vec;
    int unk10;
    void* unk14;
    int unk18;
    void* unk1c;
};

struct S_00cfab30_record
{
    const char* name;
    unsigned int timestamp;
    unsigned int reserved;
};

struct S_00cfab30_allocator
{
    int unk00;
    S_00cfab30_record* next;
    int unk08;
    S_00cfab30_record* end;
};

struct S_00cfab30_this;

struct S_00cfab30_object
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v0a() = 0;
    virtual void v0b() = 0;
    virtual void v0c() = 0;
    virtual void v0d() = 0;
    virtual void v0e() = 0;
    virtual void v0f() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void target_call(S_00cfab30_local*, S_00cfab30_this*, int) = 0;
};

struct S_00cfab30_this
{
    void** vtable;
    void* unk04;
    void* unk08;
    void* unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* unk34;

    void __thiscall hkpSimpleWorldRayCaster_castRaysFromSinglePoint(S_00cfab30_object*, S_00cfab30_arg*, void*, void*, void*, void*);
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);

// Records a start timestamp, stores arguments into fields, invokes target_call on arg08 with a local struct, then records an end timestamp.
// @f3 0x00984970 (community match, verified in this file)
extern S_00cfab30_allocator* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_0116913c;
extern char DAT_00e7d4ec,DAT_00e32798;
struct __declspec(align(16)) Dispatch570{float x,y,z,w;void* context;void* info;int size;void* extra;};
struct Target570 {
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
    virtual void Dispatch(Dispatch570*,S_00cfab30_this*,int);
};
// pdb: hkpSimpleWorldRayCaster::castRaysFromSinglePoint | hkpSimpleWorldRayCaster.obj | fnv360_0822_retail, ustr, high
// pdb params: broadphase, inputArray, numRays, filter, cache, outputs
// pdb: hkpSimpleWorldRayCaster::castRaysFromSinglePoint | hkpSimpleWorldRayCaster.obj | fnv360_0822_retail, ustr, high (was: RecordAndDispatch)
void S_00cfab30_this::hkpSimpleWorldRayCaster_castRaysFromSinglePoint(S_00cfab30_object* target,S_00cfab30_arg* input,void* context,void* adjusted,void* extra,void* owner){
    S_00cfab30_allocator* (__stdcall* lookup)(unsigned long)=DAT_00d9b080;
    volatile unsigned int timestamp;
    S_00cfab30_allocator* allocator=lookup(DAT_0116913c);
    S_00cfab30_record* record=allocator->next;
    if(record<allocator->end){
        record->name=&DAT_00e7d4ec;_ReadWriteBarrier();
        timestamp=(unsigned int)__rdtsc();record->timestamp=timestamp;allocator->next=record+1;
    }
    unk04=input;unk0c=owner;unk08=adjusted?(char*)adjusted+0x14:0;
    if(input->unk20)unk34=adjusted?(char*)adjusted+0x10:0;else unk34=0;
    Dispatch570 local;
    local.x=input->vec.f[0];local.y=input->vec.f[1];local.z=input->vec.f[2];local.w=input->vec.f[3];
    local.extra=extra;local.info=&input->unk10;local.size=0x30;local.context=context;
    ((Target570*)target)->Dispatch(&local,this,0);
    allocator=lookup(DAT_0116913c);record=allocator->next;
    if(record<allocator->end){
        record->name=&DAT_00e32798;_ReadWriteBarrier();
        timestamp=(unsigned int)__rdtsc();record->timestamp=timestamp;allocator->next=record+1;
    }
}

