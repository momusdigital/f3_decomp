#include <math.h>
#include <string.h>
#include <math.h>
#include <math.h>
#include <intrin.h>
// src/f3staging/f3blk_008e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008f25c0 (community match, verified in this file)
struct Holder {
    int* unk00;
    int unk04;
    unsigned int unk08;
};

extern "C" int __cdecl FUN_008f2280(int a);
extern "C" void __cdecl FUN_00901f10(Holder* p, int n);
extern "C" void __cdecl FUN_008f2350(int x, Holder* p);

// pdb: bhkUtilFunctions::GatherConstrainedBodies | bhkUtilFunctions.obj | fnv360_1110_retail, objrun_prop, low
// pdb params: apBody, arBodyA
void FUN_008f25c0(int a, Holder* p) {
    int x = FUN_008f2280(a);
    if (p->unk04 == (int)(p->unk08 & 0x3fffffff)) {
        FUN_00901f10(p, 4);
    }
    p->unk00[p->unk04] = x;
    p->unk04++;
    FUN_008f2350(x, p);
}

// @f3 0x008f6f60 (community match, verified in this file)
struct Heap337 {};
struct Owner337 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Heap337 heap;
};
struct Header337 {
    unsigned int magic;
    Owner337* owner;
    unsigned int size;
    unsigned int reserved;
};
Header337* __stdcall FUN_008f6d30(Heap337* heap, unsigned int size);
// pdb: hkStringPtr::hkStringPtr | hkStringPtr.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkMemoryRouter::easyAlloc)
void* __stdcall FUN_008f6f60(Owner337* owner, unsigned int size) {
    Header337* header = FUN_008f6d30(&owner->heap, size);
    header->owner = owner;
    header->size = size;
    header->magic = 0x02345656;
    return header + 1;
}

// @f3 0x008e9e90 (community match, verified in this file)
struct Channel376 { void hkpWorldObject_addProperty(unsigned int value, __int64 amount); };
struct Handler376 {
    unsigned int unk00;
    unsigned int unk04;
    Channel376* channel;
    bool FUN_008e96a0(unsigned int value);
};
struct Owner376 {
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
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    Handler376* handler;
    void FUN_008e9e90(unsigned int value, volatile int amount);
};
// pdb: bhkCharacterController::SetBSReference | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiKey, apObject
void Owner376::FUN_008e9e90(unsigned int value, volatile int amount) {
    Handler376* current = handler;
    if (current && !current->FUN_008e96a0(value)) {
        Channel376* channel = current->channel;
        __int64 wideAmount = amount;
        if (channel) channel->hkpWorldObject_addProperty(value, wideAmount);
    }
}

// @f3 0x008f6d90 (community match, verified in this file)
struct FreeBlock443 { FreeBlock443* next; };
struct Fallback443 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void Free(FreeBlock443* block, int bytes, unsigned int tag);
};
struct Bucket443 { FreeBlock443* head; volatile int count; };
struct Heap443 {
    unsigned int unk00, unk04, unk08, unk0C;
    Fallback443* fallback;
    unsigned int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int limit;
    Bucket443 buckets[25];
    unsigned int unk100;
    signed char smallBucket[513];
    unsigned char unk305, unk306, unk307;
    int largeBucket[8];
    void FUN_008f6890(int index, FreeBlock443* block, unsigned int tag);
    void FUN_008f6d90(FreeBlock443* block, int bytes, unsigned int tag);
};
void Heap443::FUN_008f6d90(FreeBlock443* block, int bytes, unsigned int tag) {
    if (block) {
        if (bytes <= 0x2000) {
            int index = bytes <= 0x200 ? smallBucket[bytes] : largeBucket[(bytes - 1) >> 10];
            Bucket443& bucket = buckets[index];
            if (bucket.count >= limit)
                FUN_008f6890(index,block,tag);
            else {
                FreeBlock443* head = bucket.head;
                ++bucket.count;
                block->next = head;
                bucket.head = block;
            }
        } else {
            fallback->Free(block,bytes,tag);
        }
    }
}

// @f3 0x008f6fc0 (community match, verified in this file)
namespace f3m_008f6fc0 {
struct AlignedHeader337 {
    unsigned int magic;
    unsigned int size;
    void* tag;
    unsigned int offset;
};

struct HeapAlloc337 {
    Header337* FUN_008f6d30(unsigned int uiSize, unsigned int uiTag);
    void* FUN_008f6fc0(unsigned int uiAlign, unsigned int uiSize, unsigned int uiTag);
};

void* HeapAlloc337::FUN_008f6fc0(unsigned int uiAlign, unsigned int uiSize, unsigned int uiTag)
{
    unsigned int uiTotal = uiSize + uiAlign;
    Header337* pRaw = FUN_008f6d30(uiTotal + 0x10, uiTag);
    unsigned int uiAligned = ((unsigned int)pRaw + uiAlign + 0xf) & ~(uiAlign - 1);
    AlignedHeader337* pHeader = (AlignedHeader337*)uiAligned - 1;
    pHeader->size = uiTotal;
    pHeader->tag = (void*)uiTag;
    pHeader->magic = 0x02345656;
    pHeader->offset = uiAligned - (unsigned int)pRaw;
    return (void*)uiAligned;
}
}   // namespace f3m_008f6fc0

// @f3 0x008fd390 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008fd390 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace SerializationF3 {
struct Allocator {
    void FUN_008f6d90(void*, unsigned int, int);
};
template <class T>
struct Array {
    T* data;
    unsigned int count;
    int capacityFlags;

    __forceinline Array() : data(0), count(0), capacityFlags(0x80000000u) {}
    __forceinline ~Array() {
        if (!(capacityFlags & 0x80000000u)) {
            unsigned int capacity = capacityFlags & 0x3fffffff;
            Allocator* allocator = static_cast<Allocator*>(TlsGetValue(DAT_010f3170));
            allocator->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
    __forceinline void Swap(Array& other) {
        T* oldData = other.data;
        other.data = data;
        data = oldData;
        unsigned int oldCount = other.count;
        other.count = count;
        count = oldCount;
        int oldFlags = other.capacityFlags;
        other.capacityFlags = capacityFlags;
        capacityFlags = oldFlags;
    }
};
struct ObjectReference {
    unsigned int unk00, unk04;
    void* object;
};
struct ArrayOwner {
    unsigned int unk00;
    Array<ObjectReference*> objects;
    Array<unsigned int> indices;
};
struct StreamData {
    unsigned int unk00;
    unsigned int bytesWritten;
    unsigned int unk08;
    unsigned int (__cdecl* write)(StreamData*, const void*, unsigned int, const unsigned int*, unsigned int);
    __forceinline unsigned int WriteCount(const unsigned int& count, unsigned int width) {
        return write(this, &count, sizeof(count), &width, 1);
    }
};
struct Stream {
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
    virtual void WriteObject(void*);
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
    unsigned char mode;
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
    StreamData* data;
};
struct Owner {
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
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual int Context();
    virtual void slot2b();
    virtual void slot2c();
    virtual ArrayOwner* GetArrays(bool*);
    void FUN_008f74e0(Stream*);
    void FUN_008fd390(Stream*);
};
extern void FUN_009793e0(ArrayOwner*, int, void*);
extern void FUN_00979900(Stream*, Array<unsigned int>*);

// pdb: bhkListShape::SaveBinary | bhkListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arStream
void Owner::FUN_008fd390(Stream* stream)
{
    bool flag;
    ArrayOwner* source = GetArrays(&flag);
    Array<ObjectReference*> objects;
    Array<unsigned int> indices;
    if (source) {
        objects.Swap(source->objects);
        indices.Swap(source->indices);
        if (stream->mode != 1) {
            int context = Context();
            FUN_009793e0(source, context, &source->indices);
            FUN_009793e0(source, context, &source->objects);
        }
    }

    unsigned int count = objects.count;
    StreamData* writer = stream->data;
    writer->bytesWritten += writer->WriteCount(count, sizeof(count));
    for (unsigned int i = 0; i < count; ++i) {
        ObjectReference* ref = objects.data[i];
        stream->WriteObject(ref ? ref->object : 0);
    }
    FUN_008f74e0(stream);
    FUN_00979900(stream, &indices);

    if (source && stream->mode != 1) {
        int context = Context();
        FUN_009793e0(source, context, &source->indices);
        FUN_009793e0(source, context, &source->objects);
    }
}
}
}   // namespace f3m_008fd390

// @f3 0x008f88e0 (community match, verified in this file)
namespace f3m_008f88e0 {
struct Stream_8f88e0 {
    void Reset_82b560();
};
struct Result_8f88e0 {
    int unk00;
    int unk04;
};
struct FUN_008f88e0_Owner {
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
    virtual Result_8f88e0* Lookup_0B4(int* key);
    void Load_8f7ea0(Stream_8f88e0* stream);
    void FUN_008f88e0(Stream_8f88e0* stream);
};
// pdb: bhkUnaryAction::LoadBinary | bhkUnaryAction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream
void FUN_008f88e0_Owner::FUN_008f88e0(Stream_8f88e0* stream)
{
    stream->Reset_82b560();
    Load_8f7ea0(stream);
    int key;
    Result_8f88e0* result = Lookup_0B4(&key);
    if (result)
        result->unk04 = 0;
}
}   // namespace f3m_008f88e0

// @f3 0x008fd5b0 (community match, verified in this file)
namespace f3m_008fd5b0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
};
extern Heap DAT_01090a78;
struct Arr {
    int data;
    int size;
    unsigned int cap;
    Arr() : data(0), size(0), cap(0x80000000) {}
};
struct List {
    int unk00;
    Arr unk04;
    Arr unk10;
    List() : unk00(0) {}
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};
}
using namespace f3m_008fd5b0;
struct Owner_8fd5b0 {
    int unk00;
    int unk04;
    int unk08;
    List* unk0C;
    void FUN_008fcd80(List* list);
    List* FUN_008fd5b0(bool& created);
};
// pdb: bhkListShape::CreateCinfo | bhkListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCreated
List* Owner_8fd5b0::FUN_008fd5b0(bool& created)
{
    if (unk0C == 0) {
        unk0C = new List;
        if (unk08 != 0)
            FUN_008fcd80(unk0C);
        created = true;
    } else {
        created = false;
    }
    return unk0C;
}

// @f3 0x008f6800 (community match, verified in this file)
namespace f3m_008f6800 {
namespace f3m_008f6800 {
struct Block { Block* next; };
struct Allocator {
    virtual void Vfn00();
    virtual void AllocateBatch(void** out, int count, int size);
    virtual void Vfn08();
    virtual void* Allocate(int size, int align);
};
struct FreeList { Block* head; int count; void Push(Block* b) { ++count; b->next = head; head = b; } };
}
using namespace f3m_008f6800;
struct CachedBlockAllocator {
    int unk00; int unk04; int unk08; int unk0C;
    Allocator* allocator;
    int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30;
    int batchCount;
    FreeList lists[17];
    int blockSizes[16];
    void* FUN_008f6800(int index, int align);
};
void* CachedBlockAllocator::FUN_008f6800(int index, int align)
{
    int count = batchCount;
    if (!count)
        return allocator->Allocate(blockSizes[index], align);
    if (count >= 4)
        count = 4;
    void* blocks[4];
    allocator->AllocateBatch(blocks, count, blockSizes[index]);
    for (int i = 1; i < count; i++) {
        lists[index].Push((Block*)blocks[i]);
    }
    return blocks[0];
}
}   // namespace f3m_008f6800

// @f3 0x008f8bb0 (community match, verified in this file)
#include <stdio.h>
extern const char* DAT_010f31bc;
namespace f3m_008f8bb0 {
namespace f3m_008f8bb0 {
struct StrArr {
    int unk00;
    int unk04;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_00555790(unsigned int newCapacity);
    void FUN_005b3880(unsigned int index, char** item);
    void Add(char* item)
    {
        unsigned int n = size;
        if (n >= capacity)
            FUN_00555790(growBy + n);
        FUN_005b3880(n, &item);
    }
};
struct Data {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    void* m18;
};
}
using namespace f3m_008f8bb0;
char* __cdecl FUN_00847b50(const char* name);
char* __cdecl FUN_00847e70(const char* label, const char* value);

struct FUN_008f8bb0_cls {
    int unk00;
    int unk04;
    Data* data;
    void FUN_008f82c0(StrArr* out);
    void FUN_008f8bb0(StrArr* out);
};

// pdb: bhkUnaryAction::GetViewerStrings | bhkUnaryAction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apStrings
void FUN_008f8bb0_cls::FUN_008f8bb0(StrArr* out)
{
    FUN_008f82c0(out);
    out->Add(FUN_00847b50(DAT_010f31bc));
    void* p = (this && data) ? data->m18 : 0;
    char buffer[32];
    sprintf_s(buffer, 32, "0x%08X", p);
    out->Add(FUN_00847e70("hkpRigidBody", buffer));
}
}   // namespace f3m_008f8bb0

// @f3 0x008fdca0 (community match, verified in this file)
namespace f3m_008fdca0 {
struct RenderHolder {
    int   unk00;
    int   unk04;
    void* link08;
};

struct RenderResult {
    int           unk00;
    RenderHolder* holder04;
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    float colour40;
    float colour44;
    float colour48;
    float colour4C;
};

class FUN_00c84df0_cls;

class RenderNodeStub {
public:
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual RenderHolder* Fetch(FUN_00c84df0_cls* arg);
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual bool NeedsRefresh(FUN_00c84df0_cls* arg);
};

class FUN_00c84df0_cls {
public:
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual void t05();
    virtual void t06();
    virtual void t07();
    virtual void t08();
    virtual void t09();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual void t39();
    virtual void t40();
    virtual void t41();
    virtual void t42();
    virtual void t43();
    virtual void t44();
    virtual RenderResult* GetRendered(unsigned char* flag);
    int   unk04;
    int   unk08;
    int   unk0C;
    float alpha10;
    void bhkShape_CopyMembers(FUN_00c84df0_cls* a, FUN_00c84df0_cls* b);
    void FUN_008fdca0(FUN_00c84df0_cls* input, FUN_00c84df0_cls* arg);
};

// pdb: bhkTransformShape::CopyMembers | bhkTransformShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: apDest, arCloneData
void FUN_00c84df0_cls::FUN_008fdca0(FUN_00c84df0_cls* input, FUN_00c84df0_cls* arg) {
    unsigned char ignored;
    RenderResult* result = GetRendered(&ignored);
    if (result == 0)
        goto complete;
    {
        RenderHolder* holder = result->holder04;
        RenderNodeStub* node = holder ? (RenderNodeStub*)holder->link08 : 0;
        float alpha = arg->alpha10;
        if (alpha != 1.0f) {
            result->colour40 = result->colour40 * alpha;
            result->colour44 = result->colour44 * alpha;
            result->colour48 = result->colour48 * alpha;
            result->colour4C = result->colour4C * alpha;
        } else {
            if (node == 0)
                goto complete;
            if (node->NeedsRefresh(arg))
                goto complete;
        }
        {
            RenderHolder* replacement = node->Fetch(arg);
            result->holder04 = replacement ? (RenderHolder*)replacement->link08 : 0;
        }
    }
complete:
    bhkShape_CopyMembers(input, arg);
}
}   // namespace f3m_008fdca0

// @f3 0x008fdbe0 (community match, verified in this file)
extern _RTL_CRITICAL_SECTION DAT_010f3194;
extern int g_iCDC40LevelACount;
extern int DAT_012681b0;
namespace f3m_008fdbe0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* cs);


class NiMemObject {
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int size);
};

class S_00c87c30_Base : public NiMemObject {
public:
    S_00c87c30_Base();
    virtual void vf00();
    int unk04;
    int unk08;
};

class S_cb9a90_A : public S_00c87c30_Base {
public:
    int unk0C;
    int unk10;
    S_cb9a90_A() : unk0C(0), unk10(0) { ++g_iCDC40LevelACount; }
};

class bhkTransformShape : public S_cb9a90_A { // src: F3_EXE vtable 0x00dfcfd4 (old: FUN_00c8bed0_cls)
public:
    bhkTransformShape() { ++DAT_012681b0; }
};

class ShapeHolder {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual bhkTransformShape* vf48(bhkTransformShape* shape, int a);
    bhkTransformShape* FUN_008fdbe0(int a);
};

// pdb: bhkTransformShape::CreateObject | bhkTransformShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkTransformShape::CreateClone)
bhkTransformShape* ShapeHolder::FUN_008fdbe0(int a)
{
    EnterCriticalSection(&DAT_010f3194);
    bhkTransformShape* shape = new bhkTransformShape();
    vf48(shape, a);
    LeaveCriticalSection(&DAT_010f3194);
    return shape;
}
}   // namespace f3m_008fdbe0

// @f3 0x008fdd50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_008fdd50 {

struct TransformX {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

struct CinfoX {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    TransformX m_kMotionTransform;
};

struct NiStreamX {
    unsigned int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    unsigned int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    unsigned int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    unsigned int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    unsigned int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    unsigned int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    unsigned int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    unsigned int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    unsigned int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    unsigned int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    unsigned int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    unsigned int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    unsigned int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    unsigned int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    unsigned int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    bool m_bSameEndian;
    void FUN_0082b560();
};

inline void SwapDword(unsigned int& uiValue) {
    uiValue = _byteswap_ulong(uiValue);
}

void FUN_008fdad0(unsigned int* puiValue);

struct ThisClassX {
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
    virtual void v44();
    virtual CinfoX* GetCinfo(int* piSize);
    void FUN_008f7490(NiStreamX& kStream);
    void FUN_008fdd50(NiStreamX& kStream);
};

// pdb: bhkTransformShape::LoadBinary | bhkTransformShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void ThisClassX::FUN_008fdd50(NiStreamX& kStream) {
    kStream.FUN_0082b560();
    FUN_008f7490(kStream);
    int iSize;
    CinfoX* pkCinfo = GetCinfo(&iSize);
    if (!pkCinfo) {
        return;
    }
    pkCinfo->unk04 = 0;
    if (kStream.m_bSameEndian != 1) {
        TransformX* pkTransform = &pkCinfo->m_kMotionTransform;
        SwapDword(pkTransform->m_uiX);
        SwapDword(pkTransform->m_uiY);
        SwapDword(pkTransform->m_uiZ);
        SwapDword(pkTransform->m_w);
        FUN_008fdad0((unsigned int*)pkTransform);
    }
}
}   // namespace f3m_008fdd50

// @f3 0x008f9110 (community match, verified in this file)
class MemoryManagerAlloc
{
  public:
    void* Allocate(unsigned int size);
    void Deallocate(void* memory);
};
extern MemoryManagerAlloc g_memoryManager;

__forceinline void* FUN_aligned_alloc(unsigned int size)
{
    unsigned char* p = (unsigned char*)g_memoryManager.Allocate(size);
    unsigned char pad = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
    p += pad;
    p[-1] = pad;
    return p;
}

struct Child008f9110
{
    int unk00;
    int unk04;
    Child008f9110* FUN_00477a90();
};

class Obj008f9110
{
  public:
    int unk00;
    int unk04;
    int* unk08;
    Child008f9110* child0C;

    void FUN_008f8cf0(Child008f9110* child);
    Child008f9110* FUN_008f9110(bool* pbCreated);
};
// pdb: bhkMouseSpringAction::CreateCinfo | bhkMouseSpringAction.obj | fnv360_0822_retail, objrun, low
// pdb params: arCreated
Child008f9110* Obj008f9110::FUN_008f9110(bool* pbCreated)
{
    if (child0C == 0)
    {
        Child008f9110* p = (Child008f9110*)FUN_aligned_alloc(0x50);
        child0C = p->FUN_00477a90();
        if (unk08)
            FUN_008f8cf0(child0C);
        *pbCreated = true;
        return child0C;
    }
    *pbCreated = false;
    return child0C;
}

// @f3 0x008f7d50 (community match, verified in this file)
extern "C" void* g_010f3184;
namespace f3m_008f7d50 {
struct StrArr {
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);

    inline unsigned int Add(char* const& element)
    {
        unsigned int i = m_usSize;
        if (i >= m_usMaxSize)
            SetSize(m_usGrowBy + i);
        SetAt(i, element);
        return i;
    }
};

struct RefObj {
    int unk00;
    short unk04;
    short m_sReferenceCount;
};

struct Base380 {
    int unk00;
    int unk04;
    RefObj* m_pPointer;

    void AppendCameraPathEntries(StrArr* apStrings);
    void FUN_008f7d50(StrArr* apStrings);
};

char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl ViewerStringStr(const char* pcPrefix, const char* pcValue);
char* __cdecl CreateDebugString(const char* pcName, int iValue);
int __cdecl sprintf_s(char* pcBuffer, unsigned int uiSizeOfBuffer, const char* pcFormat, ...);

// pdb: bhkRefObject::GetViewerStrings | bhkRefObject.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Base380::FUN_008f7d50(StrArr* apStrings)
{
    AppendCameraPathEntries(apStrings);
    apStrings->Add(FUN_00a7d330((const char*)g_010f3184));

    char acBuffer[32];
    sprintf_s(acBuffer, 32, "0x%08X", (unsigned int)m_pPointer);
    apStrings->Add(ViewerStringStr("hkObject", acBuffer));

    if (m_pPointer)
    {
        apStrings->Add(CreateDebugString("hkRefcount", m_pPointer->m_sReferenceCount));
    }
}
}   // namespace f3m_008f7d50

// @f3 0x008ff460 (community match, verified in this file)
extern int DAT_010f2c30;
namespace f3m_008ff460 {
struct Value8ff460 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int value24;
};
struct Object8ff460 {
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void slot06(); virtual void slot07(); virtual void slot08();
    virtual void slot09(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual Value8ff460* slot15();
};
struct Result8ff460 { Object8ff460* object; int unk04; };
struct Lookup8ff460 { Result8ff460* FUN_00477900(Result8ff460*, int*); };
struct Owner8ff460 {
    int unk00, unk04;
    Lookup8ff460* lookup08;
    bool FUN_008f9b20(int value);
    void FUN_008ff290(int value);
    bool FUN_008ff460(int value);
};
// pdb: bhkRigidBody::ForceAdd | bhkRigidBody.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apWorld
bool Owner8ff460::FUN_008ff460(int value)
{
    bool result = FUN_008f9b20(value);
    if (result) FUN_008ff290(value);
    if (this && lookup08) {
        Result8ff460 holder;
        Object8ff460* object = lookup08->FUN_00477900(&holder, &DAT_010f2c30)->object;
        if (object) {
            Value8ff460* target = object->slot15();
            if (target) target->value24 = value;
        }
    }
    return result;
}
}   // namespace f3m_008ff460

// @f3 0x008f3510 (community match, verified in this file)
#include <string.h>

class NiFixedString {
public:
    const char* text;
    NiFixedString(const NiFixedString&);
    ~NiFixedString();

    const char* Get() const { return text; }
};

extern "C" NiFixedString DAT_011f49e0;

namespace SkeletonCollision {

struct Node;
struct Collision;
struct Controller;
struct ControllerType;

struct SceneObject {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual Node* AsNode();

    unsigned int refCount;
    NiFixedString name;
    unsigned int field0c, field10, field14;
    SceneObject* parent;
    Collision* collision;
    unsigned int field20, field24, field28, field2c;
    unsigned int flags;

    void NiAVObject_SetCollisionObject(Collision* value);
    Controller* FUN_00825200(const ControllerType* type);
};

struct Node : SceneObject {
    unsigned int field34, field38, field3c, field40, field44;
    unsigned int field48, field4c, field50, field54, field58;
    unsigned int field5c, field60, field64, field68, field6c;
    unsigned int field70, field74, field78, field7c, field80;
    unsigned int field84, field88, field8c, field90, field94;
    unsigned int field98, field9c;
    SceneObject** children;
    unsigned short capacity, childCount;

    SceneObject* FUN_00434470(unsigned int index);
};

struct Controller {
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
    virtual void SetTarget(SceneObject* object);
};

struct ErrorReporter {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Report(int severity, unsigned int id, const char* message, const char* file, int line);
};

struct WriterFlag {
    bool value;
    WriterFlag(bool enabled) : value(enabled) {}
};

struct FUN_00943ae0 {
    void* vtable;
    unsigned short flags;
    unsigned short referenceCount;
    void* writer;
    FUN_00943ae0(char* buffer, int length, WriterFlag enabled);
    ~FUN_00943ae0();
    FUN_00943ae0& FUN_00943710(const char* text);
    FUN_00943ae0& FUN_009436f0(char character);
};

extern const ControllerType DAT_010f32f8;
extern ErrorReporter* DAT_010f3364;
extern const char str_00dc0a60[], str_00e2d084[], str_00e0398c[];
extern const char str_00e33aa8[], str_00e33ac4[], str_00e33a60[];

Collision* __cdecl FUN_007235f0(SceneObject* object);

inline const NiFixedString* NameAddress(const NiFixedString& name)
{
    return &name;
}

// pdb: bhkBlendCollisionObject::MoveBipToNonAccum | bhkBlendCollisionObject.obj | fnv360_0822_debug, ustr, low, conflict (bridge: hkStatisticsCollector::memoryTypeToCstring)
// pdb params: apObject
bool __cdecl FUN_008f3510(SceneObject* object)
{
    bool repaired = false;
    if (object) {
        Node* node = object->AsNode();
        if (node) {
            const char* name = node->name.Get();
            if (name && _strnicmp(name, str_00dc0a60, 3) == 0) {
                if (strlen(name) == 5) {
                    SceneObject* child = node->FUN_00434470(0);
                    const char* childName = (child ? NameAddress(NiFixedString(child->name)) : &DAT_011f49e0)->Get();
                    if (childName && _stricmp(childName + 6, str_00e2d084) == 0) {
                        Collision* collision = FUN_007235f0(node);
                        if (collision) {
                            child->NiAVObject_SetCollisionObject(collision);
                            node->NiAVObject_SetCollisionObject(0);
                            child->flags = (child->flags & ~0x10u) | 6;
                            repaired = true;
                            Controller* controller = node->FUN_00825200(&DAT_010f32f8);
                            if (controller)
                                controller->SetTarget(child);

                            SceneObject* parent = node->parent;
                            if (parent) {
                                const char* parentName = parent->name.Get();
                                if (!parentName)
                                    parentName = str_00e0398c;
                                char message[512];
                                FUN_00943ae0 writer(message, sizeof(message), true);
                                writer.FUN_00943710(str_00e33aa8).FUN_009436f0(parentName[0]).FUN_00943710(str_00e33ac4);
                                DAT_010f3364->Report(1, 0x234f224f, message, str_00e33a60, 0x26e);
                            }
                        }
                    }
                }
            } else {
                for (unsigned int i = 0; i < node->childCount;) {
                    SceneObject* child = node->children[i];
                    repaired = FUN_008f3510(child);
                    ++i;
                }
            }
        }
    }
    return repaired;
}

}

// @f3 0x008f33c0 (community match, verified in this file)
extern int DAT_010f2edc;
namespace f3m_008f33c0 {
typedef unsigned int size_t;

struct NiMemObject {
    static void* operator new(size_t size);
    static void operator delete(void* p, size_t size);
};

struct BaseCollisionObject : public NiMemObject {
    virtual ~BaseCollisionObject();
    int unk04;
    int unk08;
    short flags;
    short unk0e;
    int unk10;

    BaseCollisionObject();
};


struct bhkBlendCollisionObject : public BaseCollisionObject {
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    float unk18;
    float unk1c;
    int unk20;
    int unk24;
    int unk28;

    bhkBlendCollisionObject() {
        ++DAT_010f2edc;
        unk18 = 0.0f;
        flags &= ~0x0100;
        unk1c = 1.0f;
        unk20 = 10;
        unk24 = 0;
        unk28 = 0;
        unk14 = 0;
    }
};

// pdb: bhkBlendCollisionObject::CreateObject | bhkBlendCollisionObject.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void* FUN_008f33c0()
{
    return new bhkBlendCollisionObject();
}
}   // namespace f3m_008f33c0

// @f3 0x008f8530 (community match, verified in this file)
namespace f3m_008f8530 {
struct FUN_009786b0_Obj {
    void hkMotionState_initMotionState(float* value, unsigned int amount);
};

struct FUN_008f8530_Obj {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned short unk0A;
    unsigned short unk0C;

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

    float unkB4;
    float unkB8;

    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;

    float unkD0;
    float unkD4;
    float unkD8;
    float unkDC;

    float unkE0;
    float unkE4;
    float unkE8;
    float unkEC;

    float unkF0;
    float unkF4;
    float unkF8;
    float unkFC;

    float unk100;
    float unk104;
    float unk108;
    float unk10C;

    unsigned int unk110;
    unsigned int unk114;

    FUN_008f8530_Obj* FUN_008f8530(float* value, unsigned int amount, unsigned char enabled);
};

// pdb: hkpMotion::hkpMotion | hkpMotion.obj | fnv360_0822_retail, call_seq, high
// pdb params: position, rotation, wantDeactivation
FUN_008f8530_Obj* FUN_008f8530_Obj::FUN_008f8530(float* value, unsigned int amount, unsigned char enabled) {
    *(volatile unsigned short*)&unk06 = 1;
    *(volatile unsigned int*)&unk00 = 0x00e34224;

    *(volatile float*)&unkDC = 0.0f;
    *(volatile float*)&unkD8 = 0.0f;
    *(volatile float*)&unkD4 = 0.0f;
    *(volatile float*)&unkD0 = 0.0f;
    *(volatile float*)&unkEC = 0.0f;
    *(volatile float*)&unkE8 = 0.0f;
    *(volatile float*)&unkE4 = 0.0f;
    *(volatile float*)&unkE0 = 0.0f;

    reinterpret_cast<FUN_009786b0_Obj*>(
        reinterpret_cast<char*>(this) + 0x10)->hkMotionState_initMotionState(value, amount);

    *(volatile float*)&unkB4 = 0.0f;
    *(volatile float*)&unkB8 = 0.0f;
    unk08 = 0;

    if (enabled != 0) {
        unk09 = (unsigned char)((int)*value & 0xf);
    } else {
        unk09 = 0xff;
    }

    unk0A = 0;
    unk0C = 0;

    *(volatile float*)&unkFC = 0.0f;
    *(volatile float*)&unkF8 = 0.0f;
    *(volatile float*)&unkF4 = 0.0f;
    *(volatile float*)&unkF0 = 0.0f;
    *(volatile float*)&unk10C = 0.0f;
    *(volatile float*)&unk108 = 0.0f;
    *(volatile float*)&unk104 = 0.0f;
    *(volatile float*)&unk100 = 0.0f;
    *(volatile unsigned int*)&unk110 = 0;
    *(volatile unsigned int*)&unk114 = 0;
    return this;
}
}   // namespace f3m_008f8530

// @f3 0x008f9eb0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008f9eb0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace f3m_008f9eb0 {
struct Allocator { void FUN_008f6d90(void*, unsigned int, int); };
template <class T> struct Array {
    T* data; unsigned int count; int capacityFlags;
    __forceinline ~Array() {
        if (!(capacityFlags & 0x80000000)) {
            unsigned int capacity = capacityFlags & 0x3fffffff;
            Allocator* allocator = static_cast<Allocator*>(TlsGetValue(DAT_010f3170));
            allocator->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};
template <class T> struct Array2 {
    T* data; unsigned int count; int capacityFlags;
    __forceinline ~Array2() {
        unsigned int cap = capacityFlags;
        if (!(cap & 0x80000000)) {
            Allocator* allocator = static_cast<Allocator*>(TlsGetValue(DAT_010f3170));
            allocator->FUN_008f6d90(data, (cap & 0x3fffffff) * sizeof(T), 0x17);
        }
    }
};
struct Info {
    int f0; int f4; bool f8; Array<__int64> arr;
    Info() { arr.data = 0; arr.count = 0; arr.capacityFlags = 0x80000000; f0 = 0; f4 = 0; f8 = true; }
};
struct Info1 {
    int f0; int f4; bool f8; Array2<__int64> arr;
    Info1() { arr.data = 0; arr.count = 0; arr.capacityFlags = 0x80000000; f0 = 0; f4 = 0; f8 = true; }
};
struct InfoPlain { int f0; int f4; bool f8; __int64* data; unsigned int count; int capacityFlags; };
struct C8CCC0Base {
    int unk00; int unk04; void* unk08;
    bool FUN_008c1550(const C8CCC0Base* other) const;
    void FUN_008f9940(Info* info) const;
    bool FUN_008f9eb0(const C8CCC0Base& other) const;
};
// pdb: bhkStream::Endian | bhkMouseSpringAction.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: arVector
bool C8CCC0Base::FUN_008f9eb0(const C8CCC0Base& other) const
{
    bool result = FUN_008c1550(&other);
    if (result) {
        Info1 info1;
        InfoPlain info2;
        info2.data = result ? (__int64*)0 : (__int64*)0; info2.capacityFlags = 0x80000000;
        FUN_008f9940(reinterpret_cast<Info*>(&info1));
        other.FUN_008f9940(reinterpret_cast<Info*>(&info2));
        if (!(info2.capacityFlags & 0x80000000)) {
            unsigned int capacity = info2.capacityFlags & 0x3fffffff;
            Allocator* allocator = static_cast<Allocator*>(TlsGetValue(DAT_010f3170));
            allocator->FUN_008f6d90(info2.data, capacity * sizeof(__int64), 0x17);
        }
    }
    return result;
}
}
using namespace f3m_008f9eb0;
}   // namespace f3m_008f9eb0

// @f3 0x008e3200 (community match, verified in this file)
namespace f3m_008e3200 {
namespace f3_0284 {
struct U16Array
{
    virtual void v0();
    virtual unsigned short* Allocate(unsigned int n);
    virtual void Free(unsigned short* p);
    unsigned short* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void FUN_00548790(unsigned int newCap, unsigned int oldSize);

    __forceinline void SetSize(unsigned int n)
    {
        if (n == 0)
        {
            if (m_data)
            {
                Free(m_data);
                m_data = 0;
                m_pRayCursor = 0;
                m_iElementCount = 0;
            }
        }
        else if (n > m_pRayCursor)
        {
            if (m_pRayCursor == 0)
                m_data = Allocate(n);
            else
                FUN_00548790(n, m_iElementCount);
            m_pRayCursor = n;
            m_iElementCount = n;
        }
        else if (n < m_iElementCount)
        {
            unsigned int quarter = m_pRayCursor >> 2;
            m_iElementCount = n;
            if (n <= quarter)
            {
                FUN_00548790(n, n);
                m_pRayCursor = n;
            }
        }
        else
        {
            m_iElementCount = n;
        }
    }
};

struct FUN_00c7a790_Data
{
    char m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    int m_38;
    int m_3c;
    U16Array m_ppData;

    void FUN_008e3200(const FUN_00c7a790_Data& src);
};

// @fnv 0x00c7a790
// pdb: RagdollFeedbackData::Copy | bhkRagdollController.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: bhkRagdollController::ApplyTetheredOffset)
// pdb params: arData
void FUN_00c7a790_Data::FUN_008e3200(const FUN_00c7a790_Data& src)
{
    m_ppData.SetSize(src.m_ppData.m_iElementCount);
    for (unsigned int i = 0; i < src.m_ppData.m_iElementCount; i++)
        m_ppData.m_data[i] = src.m_ppData.m_data[i];
    m_00 = src.m_00;
    m_04 = src.m_04;
    m_08 = src.m_08;
    m_0c = src.m_0c;
    m_10 = src.m_10;
    m_14 = src.m_14;
    m_18 = src.m_18;
    m_1c = src.m_1c;
    m_20 = src.m_20;
    m_24 = src.m_24;
    m_28 = src.m_28;
    m_2c = src.m_2c;
    m_30 = src.m_30;
    m_34 = src.m_34;
    m_38 = src.m_38;
    m_3c = src.m_3c;
}

}
}   // namespace f3m_008e3200

// @f3 0x008e5c40 (community match, verified in this file)
extern float DAT_00f79760,DAT_00f75448;
namespace f3m_008e5c40 {
namespace Z8e5c40 {
using f3m_008fd390::TlsGetValue;
struct Vec { float x,y,z,w; __forceinline Vec& operator=(const Vec& a) { x=a.x;y=a.y;z=a.z;w=a.w;return *this; } };
struct Scratch {
 virtual void v00();
 virtual void v04();
 virtual void v08();
 virtual void v0c();
 virtual void v10();
 virtual void* Allocate(unsigned int);
 virtual void Release(void*);
 unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 char* unk20; char* unk24; void* unk28; char* unk2c;
};
struct StackPolicy {
 __forceinline Vec* Allocate(int n) {
 Scratch* s=(Scratch*)TlsGetValue(DAT_010f3170);
 unsigned int bytes=(n*sizeof(Vec)+16)&~15;
 char* start=s->unk20;
 char* end=start+bytes;
 Vec* result;
 if(end<=s->unk2c){s->unk20=end;result=(Vec*)start;}
 else result=(Vec*)s->Allocate(bytes);
 return result;
 }
 __forceinline void Release(Vec* data) { Scratch* s=(Scratch*)TlsGetValue(DAT_010f3170);s->unk20=(char*)data;if(data==s->unk28)s->Release(data); }
};
struct Buffer {
 Vec* data;
 StackPolicy allocator;
 __forceinline Buffer(int n) { data=allocator.Allocate(n); }
 __forceinline ~Buffer() { allocator.Release(data); }
};
void FUN_00923500(void*,int,unsigned int);
unsigned __int64 FUN_0086c140();
struct Timer { unsigned __int64 unk00,unk08;void FUN_004242d0(float); };
struct Motion {
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
 virtual void SetFirst(const Vec*);
 virtual void SetSecond(const Vec*);
 unsigned int unk04; unsigned char unk08,unk09,unk0a,unk0b;
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
 Vec unkD0;Vec unkE0;
};
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
 unsigned short unk28,unk2a;
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
 Motion unkD0;
 void hkpRigidBody_setMotionType(int,int,int);
 void FUN_0090c670(int);
 void FUN_0090b500();
};
struct BodyCount {unsigned int unk00,unk04,unk08,unk0c;int unk10;};
struct Bodies {
 unsigned int unk00,unk04; Body** unk08;unsigned int unk0c,unk10,unk14,unk18,unk1c;
 int* unk20;unsigned int unk24,unk28;BodyCount* unk2c;
};
struct ShortArray { unsigned int unk00; unsigned short* unk04; unsigned int unk08;
 __forceinline int Find(unsigned short id) { for(unsigned int i=0;i<unk08;++i)if(unk04 && unk04[i]==id)return i;return -1; }
};
struct IndexSet {
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
 ShortArray unk40;
};
struct IndexOwner {
 unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;IndexSet* unk18;
};
struct SelectionRef { IndexOwner* pointer; __forceinline IndexOwner* get() const { return pointer; } };
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
 Bodies* unk048;
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
 unsigned char unk28c,unk28d,unk28e,unk28f;
 unsigned int unk290,unk294,unk298,unk29c,unk2a0;SelectionRef unk2a4;
 Timer unk2a8;
 void FUN_008dc980(bool);
 void FUN_008e5c40(bool enabled);
 __forceinline void Capture(int i,Vec* b,Vec* a) {
 int index=unk048->unk20[i];
 if(index>=0){Body* body=unk048->unk08[index];if(body){int type=body->unkD0.unk08;if(type<6 || type==8){*a=body->unkD0.unkD0;*b=body->unkD0.unkE0;}}}
 }
};
// pdb: bhkRagdollController::SetRagdollFeedbackActive | bhkRagdollController.obj | fnv360_0721_beta, call_seq, medium
// pdb params: abActive
void Owner::FUN_008e5c40(bool enabled) {
 if(!unk28d || (!enabled && !unk28e))return;
 if(unk28e && enabled){unk2a8.FUN_004242d0(DAT_00f79760);return;}
 FUN_008dc980(enabled);
 if(enabled){float delay=DAT_00f79760;unk2a8.unk00=FUN_0086c140();unk2a8.unk08=(__int64)(DAT_00f75448*delay);}else unk2a8.unk08=0;
 int count=unk048->unk2c->unk10;
 Buffer first(count); Buffer second(count);
 Vec* a=first.data;Vec* b=second.data;
 FUN_00923500(a,0,count*sizeof(Vec));FUN_00923500(b,0,count*sizeof(Vec));
 for(int i=0;i<count;++i)Capture(i,b+i,a+i);
 for(int i=0;i<count;++i){
 int index=unk048->unk20[i];
 if(index>=0){Body* body=unk048->unk08[index];if(body){
 if(unk2a4.get()->unk18->unk40.Find((unsigned short)i)!=-1){
 if(enabled){if(body->unkD0.unk08==6 || body->unk2a!=4){body->hkpRigidBody_setMotionType(1,1,0);body->unk2a=4;body->FUN_0090c670(1);}}
 else {if(body->unkD0.unk08!=6 || body->unk2a!=2){body->hkpRigidBody_setMotionType(6,1,0);body->unk2a=2;body->FUN_0090c670(2);}}
 }
 body->FUN_0090b500();body->unkD0.SetFirst(a+i);body->FUN_0090b500();body->unkD0.SetSecond(b+i);
 }}
 }
 unk28e=enabled;
}
}
}   // namespace f3m_008e5c40

// @f3 0x008f9be0 (community match, verified in this file)
namespace f3m_008f9be0 {
struct QColl { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18; unsigned int m_filter; };
struct QWO { int unk00, unk04, unk08, unk0c; QColl m_coll; };
struct FUN_008f9be0_Class {
    virtual void vf00() {}
    virtual void vf04() {}
    virtual void vf08() {}
    virtual void vf0C() {}
    virtual void vf10() {}
    virtual void vf14() {}
    virtual void vf18() {}
    virtual void vf1C() {}
    virtual void vf20() {}
    virtual void vf24() {}
    virtual void vf28() {}
    virtual void vf2C() {}
    virtual void vf30() {}
    virtual void vf34() {}
    virtual void vf38() {}
    virtual void vf3C() {}
    virtual void vf40() {}
    virtual void vf44() {}
    virtual void vf48() {}
    virtual void vf4C() {}
    virtual void vf50() {}
    virtual void vf54() {}
    virtual void vf58() {}
    virtual void vf5C() {}
    virtual void vf60() {}
    virtual void vf64() {}
    virtual void vf68() {}
    virtual void vf6C() {}
    virtual void vf70() {}
    virtual void vf74() {}
    virtual void vf78() {}
    virtual void vf7C() {}
    virtual void vf80() {}
    virtual void vf84() {}
    virtual void vf88() {}
    virtual void vf8C() {}
    virtual void vf90() {}
    virtual void vf94() {}
    virtual void vf98() {}
    virtual void vf9C() {}
    virtual void vfA0() {}
    virtual void vfA4() {}
    virtual void vfA8() {}
    virtual void vfAC() {}
    virtual void vfB0() {}
    virtual void vfB4() {}
    virtual void vfB8() {}
    virtual void vfBC() {}
    virtual void vfC0() {}

    int unk04;
    QWO* unk08;
    QColl* GetColl() { return unk08 ? &unk08->m_coll : 0; }
    void FUN_008f9be0(char flag);
};

static unsigned int GetFilter(FUN_008f9be0_Class* o)
{
    QColl* c = o ? o->GetColl() : 0;
    return c ? c->m_filter : 0;
}
static void SetFilter(FUN_008f9be0_Class* o, unsigned int v)
{
    QColl* c = o ? o->GetColl() : 0;
    if (c)
        c->m_filter = v;
}
// pdb: bhkWorldObject::EnableCollision | bhkWorldObject.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: bhkNiCollisionObject::SetActive)
// pdb params: abTF
void FUN_008f9be0_Class::FUN_008f9be0(char flag)
{
    unsigned int f = GetFilter(this);
    unsigned int n;
    if (flag == 0)
        n = f | 0x4000;
    else
        n = f & ~0x4000u;
    SetFilter(this, n);
    vfC0();
}
}   // namespace f3m_008f9be0

// @f3 0x008e7760 (community match, verified in this file)
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

struct Q78Heap {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int limit;
    FreeBlock443* heads[1];
    void FUN_008f6890(int index, FreeBlock443* block, unsigned int tag);
    void FUN_008f6d90(void* block, int bytes, unsigned int tag);
};

static __forceinline Q78Heap* Q78GetHeap() { return (Q78Heap*)FUN_00d9b080(DAT_010f3170); }

struct Q78FreeList { FreeBlock443* head; int count; void Push(FreeBlock443* b) { ++count; b->next = head; head = b; } };
static __forceinline void Q78PoolFree(void* p, int index) {
    Q78Heap* heap = Q78GetHeap();
    Q78FreeList* bucket = &((Q78FreeList*)&heap->heads)[index];
    FreeBlock443* block = (FreeBlock443*)p;
    if (*(volatile int*)&bucket->count >= heap->limit)
        heap->FUN_008f6890(index, block, 0xe);
    else {
        bucket->Push(block);
    }
}

template <class T> struct Q78Array {
    T* data; int size; int capacityFlags;
    __forceinline ~Q78Array() {
        if (!(capacityFlags & 0x80000000)) {
            unsigned int capacity = capacityFlags & 0x3fffffff;
            Q78Heap* heap = Q78GetHeap();
            heap->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};

struct Q78HkRef {
    virtual ~Q78HkRef();
    unsigned short memSizeAndFlags;
    short refCount;
    __forceinline void removeReference() {
        if (memSizeAndFlags != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};

struct Q78NiRef {
    virtual ~Q78NiRef();
    virtual void DeleteThis();
    long refCount;
    __forceinline void IncRefCount() { InterlockedIncrement((volatile long*)&refCount); }
    __forceinline void DecRefCount() { if (InterlockedDecrement((volatile long*)&refCount) == 0) DeleteThis(); }
};

extern char* DAT_00e207a8;
struct Q78FixedString {
    char* handle;
    __forceinline operator char*() const { return handle; }
    __forceinline ~Q78FixedString() {
        if (handle != DAT_00e207a8) InterlockedDecrement((volatile long*)(handle - 8));
    }
};

struct Q78SimpleArray;
static __forceinline void Q78CallFree(Q78SimpleArray* a, void* p);
struct Q78SimpleArray {
    virtual ~Q78SimpleArray() {
        if (buffer) { Q78CallFree(this, buffer); buffer = 0; alloc = 0; size = 0; }
    }
    virtual void v1();
    virtual void Free(void* p) = 0;
    void* buffer; int size; int alloc;
};

static __forceinline void Q78CallFree(Q78SimpleArray* a, void* p) { a->Free(p); }
struct Q78SimpleArrayD : Q78SimpleArray { virtual void Free(void* p); };
struct Q78Elem { Q78HkRef* obj; int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
    unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C,
    unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC,
    unkC0, unkC4, unkC8, unkCC; };
struct Q78E30 { int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C; };
struct Q78E20 { int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C; };

struct Q78Obj4C { void FUN_0095b530(); };
struct Q78Obj54 { void FUN_008e46c0(); };
struct Q78Obj248 { Q78Array<Q78E20> arr; static void operator delete(void* p) { Q78PoolFree(p, 4); } };

struct Q78Map {
    bool FUN_005c8b00(char* key, Q78NiRef** out);
    void FUN_00899cf0(char* key);
};
extern Q78Map DAT_00f79764;
extern Q78Map DAT_00f79774;

struct Q78Base {
    virtual ~Q78Base() {}
};

struct FUN_008e7760 : Q78Base {
    ~FUN_008e7760();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    Q78HkRef* unk48;
    Q78Obj4C* unk4C;
    int unk50;
    Q78Obj54* unk54;
    int unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    NiPointer<Q78NiRef> unk84;
    Q78Obj54* unk88;
    int unk8C, unk90;
    Q78Array<Q78E30> unk94;
    Q78SimpleArrayD unkA0;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC,
        unkF0, unkF4, unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C,
        unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC,
        unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0, unk1E4, unk1E8, unk1EC,
        unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C, unk220, unk224, unk228;
    Q78Array<Q78Elem> unk22C;
    int unk238, unk23C, unk240, unk244;
    Q78Obj248* unk248;
    Q78FixedString unk24C;
    NiPointer<Q78NiRef> unk250;
    int unk254, unk258, unk25C, unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C, unk280, unk284, unk288, unk28C,
        unk290, unk294, unk298, unk29C;
    Q78FixedString unk2A0;
    NiPointer<Q78NiRef> unk2A4;
};

// pdb: bhkRagdollController::~bhkRagdollController | bhkRagdollController.obj | fnv360_0822_retail, caller_sim, medium
FUN_008e7760::~FUN_008e7760() {
    int count = unk22C.size;
    for (int i = 0; i < count; i++)
        unk22C.data[i].obj->removeReference();
    unk22C.size = 0;
    {
        Q78Obj4C* p = unk4C;
        if (p) {
            p->FUN_0095b530();
            Q78PoolFree(p, 6);
        }
    }
    if (unk48) unk48->removeReference();
    {
        Q78Obj54* p = unk54;
        if (p) {
            p->FUN_008e46c0();
            Q78PoolFree(p, 5);
        }
    }
    {
        Q78Obj54* p = unk88;
        if (p) {
            p->FUN_008e46c0();
            Q78PoolFree(p, 5);
        }
    }
    DAT_00f79764.FUN_005c8b00(unk24C, &unk250.m_pObject);
    if (unk250 && unk250->refCount == 2)
        DAT_00f79764.FUN_00899cf0(unk24C);
    if (unk2A4 && unk2A4->refCount == 2)
        DAT_00f79774.FUN_00899cf0(unk2A0);
    unk2A4 = 0;
    unk250 = 0;
    delete unk248;
}

// @f3 0x008fec30 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008fec30 {
namespace n8fec30 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long);
struct Obj { int vtbl; unsigned short memSize; };
// pdb: bhkRigidBody::RemoveAllActionConstraints | bhkRigidBody.obj | tesv_win, objrun_open, low
void __cdecl FUN_008fec30(Obj* p)
{
    Alloc* al = FUN_00d9b080(DAT_010f3170);
    al->FUN_008f6d90(p, p->memSize, 0x2d);
}
}
}   // namespace f3m_008fec30

// @f3 0x008f8620 (community match, verified in this file)
namespace f3m_008f8620 {
struct Sub8f8620 { char pad[0xc0]; void FUN_008f8720(Sub8f8620* src); };
struct Obj8f8620 {
    char pad00[9];
    bool flag09;
    char pad0a[6];
    Sub8f8620 sub;
    float f[8];
    void FUN_008f8620(Obj8f8620* dst);
};
// pdb: hkpMotion::getMotionStateAndVelocitiesAndDeactivationType | hkpMotion.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: motionOut
void Obj8f8620::FUN_008f8620(Obj8f8620* dst)
{
    dst->sub.FUN_008f8720(&sub);
    dst->f[0] = f[0]; dst->f[1] = f[1]; dst->f[2] = f[2]; dst->f[3] = f[3];
    dst->f[4] = f[4]; dst->f[5] = f[5]; dst->f[6] = f[6]; dst->f[7] = f[7];
    dst->flag09 = flag09;
}
}   // namespace f3m_008f8620

// @f3 0x008fc020 (community match, verified in this file)
namespace f3m_008fc020 {
struct Inner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct Accessor008fc020 {
    int unk00;
    int unk04;
    Inner* unk08;
    int FUN_008fc020();
};
int Accessor008fc020::FUN_008fc020() {
    Inner* value = this ? unk08 : 0;
    int result = 0;
    if (value)
        result = value->unk14;
    return result;
}
}   // namespace f3m_008fc020

// @f3 0x008f9c90 (community match, verified in this file)
namespace n8f9c90 {
struct Result { void* object; int unk04; };
struct Lookup { Result* FUN_00477900(Result* out, int* key); };
extern int DAT_0108edc0;
}
struct Owner8f9c90 {
    int unk00, unk04;
    n8f9c90::Lookup* lookup08;
    bool FUN_008e96a0(int* key);
    void* FUN_008f9c90(int* key);
    __forceinline void* Get(int* key) {
        if (this && lookup08) {
            n8f9c90::Result holder;
            return lookup08->FUN_00477900(&holder, key)->object;
        }
        return 0;
    }
};
// pdb: bhkWorldObject::GetAVObject | bhkWorldObject.obj | fnv360_0822_retail, call_seq, low
// pdb params: aiKey
void* Owner8f9c90::FUN_008f9c90(int* key)
{
    void* result = 0;
    if (!key) key = &n8f9c90::DAT_0108edc0;
    if (FUN_008e96a0(key)) result = Get(key);
    return result;
}

// @f3 0x008ff270 (community match, verified in this file)
namespace f3m_008ff270 {
struct Member8ff270 { void FUN_005e3010(); };
struct Obj8ff270 {
    char pad[0x14];
    Member8ff270 m;
    void FUN_008f7ef0();
    void FUN_008ff270();
};
void Obj8ff270::FUN_008ff270()
{
    m.FUN_005e3010();
    FUN_008f7ef0();
}
}   // namespace f3m_008ff270

// @f3 0x008f9880 (community match, verified in this file)
extern int DAT_010f31d0;
namespace f3m_008f9880 {
struct Buffer008f9880 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_00555790(unsigned int value);
    void FUN_005b3880(unsigned int offset, int* result);
};
void __stdcall FUN_008da7d0(Buffer008f9880* buffer);
int __cdecl FUN_00847b50(int value);
// pdb: bhkPCollisionObject::AddViewerStrings | bhkPCollisionObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void __stdcall FUN_008f9880(Buffer008f9880* buffer) {
    FUN_008da7d0(buffer);
    int result = FUN_00847b50(DAT_010f31d0);
    unsigned int end = buffer->unk0A;
    unsigned int current = buffer->unk08;
    if (end >= current)
        buffer->FUN_00555790(buffer->unk0E + end);
    buffer->FUN_005b3880(end, &result);
}
}   // namespace f3m_008f9880

// @f3 0x008e96a0 (community match, verified in this file)
namespace f3m_008e96a0 {
namespace n8e96a0 {
struct Entry { void* key; int a, b, c; };
struct Inner {
    char pad[0x74];
    Entry* entries;
    int count;
    __forceinline bool Has(void* k) {
        for (int i = 0; i < count; i++)
            if (entries[i].key == k) return true;
        return false;
    }
};
}
struct Obj8e96a0 {
    int x0, x4;
    n8e96a0::Inner* inner;
    bool FUN_008e96a0(void* k);
};
// pdb: bhkWorldObject::HasProperty | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiKey
bool Obj8e96a0::FUN_008e96a0(void* k)
{
    if (this && inner)
        return inner->Has(k) ? true : false;
    return false;
}
}   // namespace f3m_008e96a0

// @f3 0x008e9020 (community match, verified in this file)
extern int DAT_00dcdbac, DAT_00e3348c, DAT_00e33574;
extern int DAT_010f3174, DAT_011692b0, DAT_010f3204;
namespace f3m_008e9020 {
namespace task0787 {
struct FUN_008f7c10 {
 void* vtable; unsigned int referenceCount; unsigned int field08;
 FUN_008f7c10();
};
struct FUN_0096ab10 : FUN_008f7c10 {
 unsigned int field0c, field10;
 FUN_0096ab10() {
  vtable=&DAT_00dcdbac;
  field0c=0; field10=0;
  DAT_010f3174+=1;
  vtable=&DAT_00e3348c;
  DAT_011692b0+=1;
 }
 ~FUN_0096ab10();
};
struct FUN_008e9020 : FUN_0096ab10 {
 void FUN_008fceb0(unsigned int);
 FUN_008e9020(unsigned int a);
};
FUN_008e9020::FUN_008e9020(unsigned int a) {
 vtable=&DAT_00e33574;
 FUN_008fceb0(a);
 DAT_010f3204+=1;
}
}
}   // namespace f3m_008e9020

// @f3 0x008fa290 (community match, verified in this file)
extern unsigned int DAT_010f31f8, DAT_010f3340;
extern const char DAT_00e1c304[], DAT_00e3443c[];
namespace f3m_008fa290 {
namespace task0808 {
struct FUN_008f7c10 {
 const char* classTable;
 unsigned int field04, field08;
 FUN_008f7c10();
};
struct FUN_008fbad0 : FUN_008f7c10 {
 unsigned int initialized0c;
 FUN_008fbad0() : initialized0c(0) {
  classTable=DAT_00e1c304;
  ++DAT_010f31f8;
 }
 ~FUN_008fbad0();
};
struct FUN_008fa290 : FUN_008fbad0 {
 FUN_008fa290(void*);
 void FUN_008fc4a0(void*);
};
// pdb: bhkLimitedHingeConstraint::bhkLimitedHingeConstraint | WeaponObject.obj | fnv360_0721_beta, call_gap, medium
// pdb params: arInfo
FUN_008fa290::FUN_008fa290(void* context) : FUN_008fbad0() {
 classTable=DAT_00e3443c;
 FUN_008fc4a0(context ? (char*)context+4 : 0);
 ++DAT_010f3340;
}
}
}   // namespace f3m_008fa290

// @f3 0x008e95c0 (community match, verified in this file)
namespace f3m_008e95c0 {
namespace f3m_008e95c0 {

struct Inner {
    int unk0, unk4, unk8;
    void* unkc;
};

struct Owner {
    char unk0[0x4c0];
    Inner* inner;
    void* FUN_008e95c0();
};

// pdb: bhkCharacterController::GetBumpedBody | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
void* Owner::FUN_008e95c0() {
    Inner* p = inner;
    if (p)
        return p->unkc;
    return 0;
}

}
}   // namespace f3m_008e95c0

// @f3 0x008f9b20 (community match, verified in this file)
namespace f3m_008f9b20 {
namespace task0853 {
class Obj
{
  public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0a();
    virtual void* v0b();
    virtual void* v0c();
    virtual void* v0d();
    virtual void* v0e();
    virtual void* v0f();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1a();
    virtual void* v1b();
    virtual void* v1c();
    virtual void* v1d();
    virtual void* v1e();
    virtual void* v1f();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    unsigned int unk04;
    Obj* m_08;
    void FUN_008d8370(Obj* p);
    bool FUN_008f9b20(Obj* a);
};
// If m_08 is set: with a null, calls v28; otherwise if v25() differs from a->m_08, calls v28, passes m_08 to a->FUN_008d8370 and returns true.
// @fnv 0x00c85810
// pdb: bhkWorldObject::Add | bhkWorldObject.obj | fnv360_0822_retail, call_gap, low
// pdb params: apWorld
bool Obj::FUN_008f9b20(Obj* a)
{
    Obj* p = this ? m_08 : 0;
    bool r = false;
    if (p)
    {
        if (a)
        {
            Obj* w = (Obj*)this->v26();
            if (w != a->m_08)
            {
                this->v28();
                a->FUN_008d8370(p);
                r = true;
            }
        }
        else
        {
            this->v28();
        }
    }
    return r;
}

}
}   // namespace f3m_008f9b20

// @f3 0x008f8120 (community match, verified in this file)
extern int DAT_010f31ac;
namespace f3m_008f8120 {
namespace task0856 {
struct FUN_008f7ff0 {
 virtual void slot00();
 int field04;
 ~FUN_008f7ff0();
};
struct FUN_008f8120 : FUN_008f7ff0 {
 virtual ~FUN_008f8120();
 void FUN_008f7ef0();
};
// pdb: bhkAction::~bhkAction | bhkAction.obj | fnv360_0822_retail, call_seq, high
FUN_008f8120::~FUN_008f8120() {
 FUN_008f7ef0();
 DAT_010f31ac--;
}
}
}   // namespace f3m_008f8120

// @f3 0x008f8c80 (community match, verified in this file)
extern int DAT_010f31c4;
namespace f3m_008f8c80 {
namespace Task0860 {
struct FUN_008f87c0 {
 virtual void slot00();
 int unk04;
 ~FUN_008f87c0();
};
struct FUN_008f8c80: FUN_008f87c0 {
 virtual ~FUN_008f8c80();
 void FUN_008f7ef0();
};
// pdb: bhkMouseSpringAction::~bhkMouseSpringAction | bhkMouseSpringAction.obj | fnv360_0822_retail, call_seq, high
FUN_008f8c80::~FUN_008f8c80(){FUN_008f7ef0(); --DAT_010f31c4;}
}
}   // namespace f3m_008f8c80

// @f3 0x008e9250 (community match, verified in this file)
namespace f3m_008e9250 {
struct In_8e9250 { void FUN_00931b80(); };
struct O_8e9250 { char pad[0x42c]; In_8e9250* p; void FUN_008e9250(); };
// pdb: bhkCharacterController::UpdateCollisionBox | bhkCharacterController.obj | fnv360_0822_retail, caller_sim, low
void O_8e9250::FUN_008e9250() { if (p) p->FUN_00931b80(); }
}   // namespace f3m_008e9250

// @f3 0x008f67e0 (community match, verified in this file)
namespace f3m_008f67e0 {
struct O_8f67e0 { virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3(); virtual void Del(int f); int u04, u08, u0c, u10; int refs; void FUN_008f67e0(); };
// pdb: hkMemorySystem::FrameInfo::FrameInfo | hkMemorySystem.obj | fnv360_0822_retail, callee_sim, low, conflict (skyrim: bhkThreadMemoryRouter::SetMainInit)
void O_8f67e0::FUN_008f67e0() { if (--refs == 0) Del(1); }
}   // namespace f3m_008f67e0

// @f3 0x008f87c0 (community match, verified in this file)
extern int DAT_010f31b8;
namespace f3m_008f87c0 {
namespace task0859 {
class FUN_008f8120 {
public:
 virtual void unk00();
 ~FUN_008f8120();
 int unk04;
};
class FUN_008f87c0 : public FUN_008f8120 {
public:
 virtual ~FUN_008f87c0();
 void FUN_008f7ef0();
};
// pdb: bhkUnaryAction::~bhkUnaryAction | bhkUnaryAction.obj | fnv360_0822_retail, call_seq, high
FUN_008f87c0::~FUN_008f87c0() {
 FUN_008f7ef0();
 DAT_010f31b8--;
}
}
}   // namespace f3m_008f87c0

// @f3 0x008fe2d0 (community match, verified in this file)
namespace n8fe2d0 {
struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;
inline void* AlignedAlloc(unsigned int size) {
    unsigned char* raw = (unsigned char*)DAT_01090a78.FUN_0086b930(size + 16);
    unsigned char off = (unsigned char)(16 - ((unsigned int)raw & 15));
    raw += off;
    raw[-1] = off;
    return raw;
}
struct Item {
    char data[0x50];
    Item* FUN_005a02b0();
};
}
struct Obj8fe2d0 {
    int a0, a4;
    void* owner;
    n8fe2d0::Item* item;
    void FUN_008fdff0(n8fe2d0::Item* it);
    n8fe2d0::Item* FUN_008fe2d0(bool* created);
};
// pdb: bhkTransformShape::CreateCinfo | bhkTransformShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arCreated
n8fe2d0::Item* Obj8fe2d0::FUN_008fe2d0(bool* created)
{
    if (!item) {
        item = ((n8fe2d0::Item*)n8fe2d0::AlignedAlloc(sizeof(n8fe2d0::Item)))->FUN_005a02b0();
        if (owner) FUN_008fdff0(item);
        *created = true;
        return item;
    }
    *created = false;
    return item;
}

// @f3 0x008e95a0 (community match, verified in this file)
namespace f3m_008e95a0 {
struct In_8e95a0 { int u0, u4, u8; int v; };
struct O_8e95a0 { char pad[0x49c]; In_8e95a0* p; int FUN_008e95a0(); };
// pdb: bhkCharacterController::GetSupportBody | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
int O_8e95a0::FUN_008e95a0() { if (p) return p->v; return 0; }
}   // namespace f3m_008e95a0

// @f3 0x008f98d0 (community match, verified in this file)
extern int DAT_010f31d8;
namespace f3m_008f98d0 {
namespace task0862 {
struct FUN_008f7ff0 {
    virtual void slot00();
    int unk04;
    ~FUN_008f7ff0();
};
struct FUN_008f98d0 : FUN_008f7ff0 {
    virtual ~FUN_008f98d0();
    void FUN_008f7ef0();
};
// pdb: bhkWorldObject::~bhkWorldObject | bhkWorldObject.obj | fnv360_0822_retail, call_seq, high
FUN_008f98d0::~FUN_008f98d0() {
    FUN_008f7ef0();
    --DAT_010f31d8;
}
}
}   // namespace f3m_008f98d0

// @f3 0x008fc040 (community match, verified in this file)
namespace f3m_008fc040 {
namespace Get353{
struct Data{unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,value;unsigned int Get(){unsigned int result=0;if(this)result=value;return result;}};
struct Owner{unsigned int unk00,unk04;Data*data;Data*GetData(){return this?data:0;}unsigned int FUN_008fc040();};
unsigned int Owner::FUN_008fc040(){return GetData()->Get();}
}
}   // namespace f3m_008fc040

// @f3 0x008ea1d0 (community match, verified in this file)
namespace f3m_008ea1d0 {
struct O_8ea1d0 { char pad[0x388]; float a; char pad2[0x48]; float b; void FUN_008ea1d0(); };
// pdb: bhkCharacterController::UpdateFalling | bhkCharacterController.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: bhkCharProxyControllerCinfo::GetKeepDistanceImpl)
void O_8ea1d0::FUN_008ea1d0() { b = a + b; }
}   // namespace f3m_008ea1d0

// @f3 0x008ec9f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008ec9f0 {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
namespace n8ec9f0 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    ~Array() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
}
struct FUN_008ec9f0 {
    int unk0;
    n8ec9f0::Array<int> a;
    n8ec9f0::Array<int> b;
    ~FUN_008ec9f0();
};
FUN_008ec9f0::~FUN_008ec9f0() {}
}   // namespace f3m_008ec9f0

// @f3 0x008e95e0 (community match, verified in this file)
namespace f3m_008e95e0 {
struct In_8e95e0 { char pad[0xc0]; int v; };
struct O_8e95e0 { char pad[0x4c8]; In_8e95e0* p; int FUN_008e95e0(); };
// pdb: bhkCharacterController::GetBumpedCharacterController | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
int O_8e95e0::FUN_008e95e0() { if (p) return p->v; return 0; }
}   // namespace f3m_008e95e0

// @f3 0x008fec50 (community match, verified in this file)
extern double DAT_00db88e8;
namespace f3m_008fec50 {
float __cdecl FUN_004e6160();
float __cdecl FUN_008fec50() { return (float)(FUN_004e6160() * DAT_00db88e8); }
}   // namespace f3m_008fec50

// @f3 0x008e31a0 (community match, verified in this file)
namespace f3m_008e31a0 {
namespace task0882 {
struct Array { virtual void slot00(); virtual void* Alloc(unsigned int); void** m_pBuffer; unsigned int m_uiLogicalSize,m_iReservedSize; void FUN_008dd050(unsigned int,unsigned int); unsigned int FUN_008e31a0(); };
// @fnv 0x00a11ee0
// pdb: hkArrayBase<hkpRigidBody const *>::operator[] | LoadedAreaBound.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: bhkRagdollController::SetFootIKActive)
// pdb params: i
unsigned int Array::FUN_008e31a0() {
    unsigned int unkC, tmp0, a0;
    unsigned int cap;
    unsigned int newCap;
    bool fullTmp;
    if (m_uiLogicalSize == m_iReservedSize)
        fullTmp = true;
    else
        fullTmp = false;
    if (fullTmp) {
        if (m_iReservedSize == 0) {
            cap = 4;
            m_pBuffer = (void**)Alloc(cap);
            m_iReservedSize = cap;
        } else {
            newCap = (m_iReservedSize > 0x400) ? m_iReservedSize + 0x400 : m_iReservedSize * 2;
            FUN_008dd050(newCap, m_uiLogicalSize);
            m_iReservedSize = newCap;
        }
    }
    m_uiLogicalSize++;
    return m_uiLogicalSize - 1;
}

}
}   // namespace f3m_008e31a0

// @f3 0x008e8880 (community match, verified in this file)
namespace f3m_008e8880 {
namespace n8e8880 {
struct Obj {
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
    Obj(int a, int b, float c);
    char pad[0x14];
};
}
// pdb: hkListShapeCinfo::~hkListShapeCinfo | bhkCharacterController.obj | fnv360_0721_beta, call_gap_sim, low
n8e8880::Obj* FUN_008e8880(int a, int b, float c)
{
    return new n8e8880::Obj(a, b, c);
}
}   // namespace f3m_008e8880

// @f3 0x008e30e0 (community match, verified in this file)
namespace f3m_008e30e0 {
struct Heap_8e30e0 { void FUN_0086ba60(void* p); };
struct O_8e30e0 { char pad[8]; unsigned short w8; };
// pdb: NiTMap<bhkRigidBody *,unsigned short>::DeleteItem | LoadedAreaBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkItem
void __stdcall FUN_008e30e0(O_8e30e0* p) { p->w8 = 0; ((Heap_8e30e0*)&DAT_01090a78)->FUN_0086ba60(p); }
}   // namespace f3m_008e30e0

// @f3 0x008f82c0 (community match, verified in this file)
struct StrArr
{
    char _pad[8];
    unsigned short m8;
    unsigned short mA;
    char _padC[2];
    unsigned short mE;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
void __stdcall FUN_008f80d0(StrArr*);
char* FUN_00847b50(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 DAT_010f31b0;
// @fnv 0x00bc28f0
// pdb: bhkAction::GetViewerStrings | bhkAction.obj | fnv360_0822_retail, call_gap, low
// pdb params: apStrings
void __stdcall FUN_008f82c0(StrArr* pStrArr)
{
    FUN_008f80d0(pStrArr);
    char* pStr = FUN_00847b50(DAT_010f31b0.f0);
    unsigned int uiIndex = pStrArr->mA;
    unsigned int cnt = pStrArr->m8;
    if (uiIndex >= cnt)
    {
        pStrArr->FUN_00555790(pStrArr->mE + uiIndex);
    }
    pStrArr->FUN_005b3880(uiIndex, pStr);
}

// @f3 0x008fd0b0 (community match, verified in this file)
namespace f3m_008fd0b0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
namespace n8fd0b0 {
struct RefObj {
    virtual void v0();
    virtual void DeleteThis();
    long refCount;
    void Release() { if (InterlockedDecrement(&refCount) == 0) DeleteThis(); }
};
struct Entry { char pad[8]; RefObj* obj; };
struct Slot { Entry* entry; int pad[3]; };
struct Counter { virtual void v0(); virtual unsigned int Count(); };
struct Owner { char pad[0x10]; Counter counter; char pad14[0x18 - 0x14]; Slot* slots; };
}
struct FUN_008fd0b0_c {
    char pad[8];
    n8fd0b0::Owner* owner;
    void FUN_008fd0b0();
};
// pdb: bhkListShape::AddbhkShapeRef | bhkListShape.obj | fnv360_0721_beta, objrun_sim, low, conflict (bridge: bhkListShape::RembhkShapeRef)
void FUN_008fd0b0_c::FUN_008fd0b0()
{
    if (!this) return;
    n8fd0b0::Owner* o = owner;
    if (o) {
        unsigned int n = o->counter.Count();
        while (n) {
            n--;
            if (owner) {
                n8fd0b0::Entry* e = owner->slots[n].entry;
                if (e && e->obj)
                    e->obj->Release();
            }
        }
    }
}
}   // namespace f3m_008fd0b0

// @f3 0x008e8d40 (community match, verified in this file)
namespace f3m_008e8d40 {
namespace n8e8d40 {
void __cdecl FUN_0089ec10(void* p, unsigned int size);
}
struct FUN_008e8d40_c {
    char pad[0x260];
    void FUN_0092ac70();
    void* FUN_008e8d40(unsigned int flags);
};
// pdb: bhkCharacterProxy::`scalar deleting destructor' | bhkCharacterController.obj | fnv360_0822_retail, caller_sim, low
void* FUN_008e8d40_c::FUN_008e8d40(unsigned int flags)
{
    FUN_0092ac70();
    if (flags & 1)
        n8e8d40::FUN_0089ec10(this, sizeof(*this));
    return this;
}
}   // namespace f3m_008e8d40

// @f3 0x008f2430 (community match, verified in this file)
extern void (__stdcall* DAT_00e3396c)(void*);
namespace task0951 {
struct Memory { void FUN_0086ba60(void*); };
extern Memory DAT_01090a78;
struct SsArr {
 virtual ~SsArr() {
  if(data) {
   DAT_00e3396c(data);
   data=0;
   b=0;
   a=0;
  }
 }
 void* data;
 int a,b;
};
// pdb: BSSimpleArray<bhkUtilFunctions::AVLevel,1024>::`scalar deleting destructor' | bhkUtilFunctions.obj | fnv360_0721_beta, objrun_open, low
SsArr* __fastcall FUN_008f2430(SsArr* p,int,unsigned flags) {
 p->SsArr::~SsArr();
 if(flags&1) DAT_01090a78.FUN_0086ba60(p);
 return p;
}
}

// @f3 0x008e3150 (community match, verified in this file)
namespace f3m_008e3150 {
namespace task0950 { struct Heap { void FUN_0086ba60(void*); }; extern Heap DAT_01090a78; }
extern void (__stdcall *DAT_00e32ba4)(void*);
struct Array950 {
    virtual ~Array950() {
        if (data) {
            DAT_00e32ba4(data);
            data = 0;
            b = 0;
            a = 0;
        }
    }
    void* data;
    int a, b;
};
// pdb: BSSimpleArray<bhkRagdollController::bhkSkeletonBone *,1024>::`scalar deleting destructor' | bhkRagdollController.obj | fnv360_0721_beta, objrun_open, low
Array950* __fastcall FUN_008e3150(Array950* p, int, unsigned int flags)
{
    p->Array950::~Array950();
    if (flags & 1) task0950::DAT_01090a78.FUN_0086ba60(p);
    return p;
}

}   // namespace f3m_008e3150

// @f3 0x008e3100 (community match, verified in this file)
namespace task0952 {
extern int DAT_00e32c70;
extern void (__stdcall *DAT_00e32c78)(void*);
struct MemoryManager { void FUN_0086ba60(void*); };
extern MemoryManager DAT_01090a78;
struct SsArr {
 void* vtable;
 void* data;
 int a,b;
 ~SsArr() { vtable=&DAT_00e32c70; if(data) { DAT_00e32c78(data); data=0; b=0; a=0; } }
};
// pdb: BSSimpleArray<bhkRagdollController::BoneTransf,1024>::`scalar deleting destructor' | bhkRagdollController.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: bhkRagdollController::GetSkeleton)
SsArr* __fastcall FUN_008e3100(SsArr* p, int, unsigned flags) {
 p->SsArr::~SsArr();
 if(flags & 1) DAT_01090a78.FUN_0086ba60(p);
 return p;
}
}

// @f3 0x008fd8d0 (community match, verified in this file)
namespace n8fd8d0 {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct Obj { void FUN_008ec9f0(); };
}
struct FUN_008fd8d0_c {
    char pad[0xc];
    n8fd8d0::Obj* obj;
    void FUN_008fd8d0(bool release);
};
// pdb: hkArray<hkpShape *,hkContainerHeapAllocator>::setSize | bhkListShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: size
void FUN_008fd8d0_c::FUN_008fd8d0(bool release)
{
    if (release) {
        n8fd8d0::Obj* o = obj;
        if (o) {
            o->FUN_008ec9f0();
            n8fd8d0::DAT_01090a78.FUN_0086ba60(o);
        }
        obj = 0;
    }
}

// @f3 0x008fc680 (community match, verified in this file)
namespace f3m_008fc680 {
namespace Task0955 {
struct Binary {
 void* vtable;unsigned int position;
 unsigned int (__cdecl *read)(Binary*,void*,unsigned int,int*,unsigned int);
 unsigned int Read(void* p,unsigned int n,int* sizes,unsigned int count){unsigned int got=read(this,p,n,sizes,count);position+=got;return got;}
};
struct Stream {
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
 Binary* binary;
 void FUN_0082b620();
};
template<class T> inline void Load(Binary* binary,T* value,unsigned int count=1) {
 int size=sizeof(T);
 binary->Read(value,count*size,&size,1);
}
template<class T> inline void ReadValue(Stream* stream,T& value) {Load(stream->binary,&value);}
struct Object {
 virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();
 int unk04;int value;
 void FUN_008fc680(Stream&,int);
};
void Object::FUN_008fc680(Stream& stream,int) {
 stream.FUN_0082b620();
 v14();
 ReadValue(&stream,value);
}
}
}   // namespace f3m_008fc680

// @f3 0x008e8900 (community match, verified in this file)
namespace f3m_008e8900 {
struct O_8e8900 { char pad[0x270]; int a; char pad2[0xdc]; int b; void FUN_008e8900(); };
// pdb: bhkCharacterController::UpdateState | bhkCharacterController.obj | fnv360_0721_beta, call_gap_sim, medium
void O_8e8900::FUN_008e8900() { if (b != 0xb) { a = b; b = 0xb; } }
}   // namespace f3m_008e8900

// @f3 0x008f3130 (community match, verified in this file)
extern int DAT_00e3399c,DAT_010f2edc;
namespace f3m_008f3130 {
namespace Task0966 {
struct FUN_008d9f90 {
 void* table;int unk04,unk08;unsigned short flags,unk0e;int unk10;
 FUN_008d9f90();
};
struct FUN_008f3130: FUN_008d9f90 {
 unsigned char state;float blend,weight;int mode,unk24,unk28;
 FUN_008f3130();
};
// pdb: bhkBlendCollisionObject::bhkBlendCollisionObject | bhkBlendCollisionObject.obj | fnv360_0721_beta, call_seq, medium
FUN_008f3130::FUN_008f3130() {
 table=&DAT_00e3399c;
 ++DAT_010f2edc;
 blend=0.0f;
 flags&=0xfeff;
 weight=1.0f;
 mode=10;
 unk24=0;unk28=0;state=0;
}
}
}   // namespace f3m_008f3130

// @f3 0x008e90f0 (community match, verified in this file)
namespace f3m_008e90f0 {
namespace n8e90f0 {
struct RefObj {
    virtual void* Delete(unsigned int flags);
    unsigned short memSize;
    short refCount;
    void addReference() { if (memSize != 0) ++refCount; }
    void removeReference() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) Delete(1);
        }
    }
};
}
struct FUN_008e90f0_c {
    char pad[0xa4];
    n8e90f0::RefObj* obj;
    void FUN_008e90f0(n8e90f0::RefObj* p);
};
void FUN_008e90f0_c::FUN_008e90f0(n8e90f0::RefObj* p)
{
    if (obj != p) {
        if (obj)
            obj->removeReference();
        obj = p;
        if (p)
            p->addReference();
    }
}
}   // namespace f3m_008e90f0

// @f3 0x008e8f70 (community match, verified in this file)
namespace f3m_008e8f70 {
struct FUN_008e8f70_c {
    char pad[0x410];
    struct Q { float a, b, c, d; void Reset() { d = 0.0f; c = 0.0f; b = 0.0f; a = 0.0f; } } q;
    int m420;
    void FUN_008e8f70();
};
// pdb: bhkCharacterProxy::operator* | MagicBallProjectile.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void FUN_008e8f70_c::FUN_008e8f70()
{
    if (m420) {
        q.Reset();
        m420 = 0;
    }
}
}   // namespace f3m_008e8f70

// @f3 0x008e30b0 (community match, verified in this file)
namespace f3m_008e30b0 {
struct FUN_008e30b0 {
 virtual void Slot0();
 virtual void** Allocate(unsigned int);
 virtual void Free(void*);
 void** data;
 unsigned int size, capacity;
 void Clear(bool release) {
  if (data) {
   typedef void* Element;
   for (unsigned int i=0; i<size; ++i) data[i].~Element();
   if (release) { Free(data); data=0; data=0; capacity=0; }
   size=0;
  }
 }
 ~FUN_008e30b0();
};
FUN_008e30b0::~FUN_008e30b0() { Clear(true); }


}   // namespace f3m_008e30b0

// @f3 0x008e9260 (community match, verified in this file)
extern double DAT_00dbe7c0;
namespace f3m_008e9260 {
struct O_8e9260 { char pad[0x350]; int state; char pad2[0x78]; float f; void bhkCharacterController_Jump(float x); };
// pdb: bhkCharacterController::Jump | bhkCharacterController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void O_8e9260::bhkCharacterController_Jump(float x) { state = 1; f = (float)(x * DAT_00dbe7c0); }
}   // namespace f3m_008e9260

// @f3 0x008e3080 (community match, verified in this file)
namespace f3m_008e3080 {
extern void (__stdcall* DAT_00e32c78)(void*);
namespace task1019 {
struct FUN_008e3080 {
 virtual ~FUN_008e3080();
 void* data;
 int a,b;
};
FUN_008e3080::~FUN_008e3080() {
 if(data) {
  DAT_00e32c78(data);
  data=0;
  b=0;
  a=0;
 }
}
}
}   // namespace f3m_008e3080

// @f3 0x008fc0c0 (community match, verified in this file)
namespace f3m_008fc0c0 {
namespace task1058 {
struct Shape;
struct Linked { unsigned unknown[9]; Shape* back; };
struct Shape {
 unsigned unknown[2];
 Linked* next;
 void FUN_008f7c70(bool);
 void FUN_008fc0c0(bool);
};
// pdb: bhkConstraint::Link | bhkConstraint.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: bhkConstraint::SetEntityA)
// pdb params: abAttach
void Shape::FUN_008fc0c0(bool b) {
 if(this && next) next->back=b ? this : 0;
 FUN_008f7c70(b);
}
}
}   // namespace f3m_008fc0c0

// @f3 0x008ec690 (community match, verified in this file)
namespace f3m_008ec690 {
namespace task1091 {
struct Primary{virtual void* FUN_008ec690(unsigned int);
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
};
struct Secondary{virtual void* FUN_008ec690(unsigned int);};
struct Derived:Primary,Secondary{Derived(); virtual void* FUN_008ec690(unsigned int);};
Derived::Derived() {}
}
}   // namespace f3m_008ec690

// @f3 0x008e97e0 (community match, verified in this file)
namespace f3m_008e97e0 {
namespace f3m_008e97e0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
void __cdecl FUN_008e97e0(f3m_008e97e0::P* p) { f3m_008e97e0::T* t = (f3m_008e97e0::T*)f3m_008e97e0::DAT_00d9b080(f3m_008e97e0::DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x34); }
}   // namespace f3m_008e97e0

// @f3 0x008f90f0 (community match, verified in this file)
namespace f3m_008f90f0 {
namespace f3m_008f90f0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
void __cdecl FUN_008f90f0(f3m_008f90f0::P* p) { f3m_008f90f0::T* t = (f3m_008f90f0::T*)f3m_008f90f0::DAT_00d9b080(f3m_008f90f0::DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x29); }
}   // namespace f3m_008f90f0

// @f3 0x008e8b30 (community match, verified in this file)
namespace f3m_008e8b30 {
namespace n8e8b30 {
struct Vec4 {
    float x, y, z, w;
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Data { Vec4 r[8]; };
}
struct Obj8e8b30 {
    int m00, m04;
    n8e8b30::Data* data;
    void FUN_008e8b30(int i, const n8e8b30::Vec4& v);
};
void Obj8e8b30::FUN_008e8b30(int i, const n8e8b30::Vec4& v)
{
    if (this && data) {
        n8e8b30::Data* d = data;
        d->r[i + 2] = v;
        d->r[i + 2].w = d->r[1].x;
    }
}
}   // namespace f3m_008e8b30

// @f3 0x008f8470 (community match, verified in this file)
namespace f3m_008f8470 {
struct V4_008f8470 { float x, y, z, w; };
struct O_008f8470 { char pad[0xd0]; V4_008f8470 v; void FUN_008f8470(const V4_008f8470* s); };
// pdb: hkpMotion::setLinearVelocity | hkpMotion.obj | fnv360_0822_retail, objrun, medium
// pdb params: newVel
void O_008f8470::FUN_008f8470(const V4_008f8470* s) { v.x = s->x; v.y = s->y; v.z = s->z; v.w = s->w; }
}   // namespace f3m_008f8470

// @f3 0x008f84a0 (community match, verified in this file)
namespace f3m_008f84a0 {
struct V4_008f84a0 { float x, y, z, w; };
struct O_008f84a0 { char pad[0xe0]; V4_008f84a0 v; void FUN_008f84a0(const V4_008f84a0* s); };
// pdb: hkpMotion::setAngularVelocity | hkpMotion.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpMotion::applyLinearImpulse)
// pdb params: newVel
void O_008f84a0::FUN_008f84a0(const V4_008f84a0* s) { v.x = s->x; v.y = s->y; v.z = s->z; v.w = s->w; }
}   // namespace f3m_008f84a0

// @f3 0x008f7ff0 (community match, verified in this file)
namespace f3m_008f7ff0 {
namespace task1171 {
struct Heap {void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct FUN_008f7cb0 {virtual ~FUN_008f7cb0();unsigned unk04,unk08;void* data;};
struct FUN_008f7ff0: FUN_008f7cb0 {virtual ~FUN_008f7ff0();};
// pdb: bhkSerializable::~bhkSerializable | bhkSerializable.obj | fnv360_0822_retail, uvref, medium
FUN_008f7ff0::~FUN_008f7ff0() {DAT_01090a78.FUN_0086ba60(data);data=0;}
}
}   // namespace f3m_008f7ff0

// @f3 0x008fda60 (community match, verified in this file)
namespace f3m_008fda60 {
struct Matrix {float data[16];Matrix& FUN_008fda60(const Matrix&);};
// pdb: bhkTransform::operator= | bhkShapePhantom.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkpConvexPenetrationUtil::init)
// pdb params: arSrc
Matrix& Matrix::FUN_008fda60(const Matrix& source){
data[0]=source.data[0];
data[1]=source.data[1];
data[2]=source.data[2];
data[3]=source.data[3];
data[4]=source.data[4];
data[5]=source.data[5];
data[6]=source.data[6];
data[7]=source.data[7];
data[8]=source.data[8];
data[9]=source.data[9];
data[10]=source.data[10];
data[11]=source.data[11];
data[12]=source.data[12];
data[13]=source.data[13];
data[14]=source.data[14];
data[15]=source.data[15];
return *this;
}
}   // namespace f3m_008fda60

// @f3 0x008f8b40 (community match, verified in this file)
namespace f3m_008f8b40 {
namespace task1232 {
struct Obj {
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
virtual void unused28();
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
virtual Obj* v25();
virtual void v9c();
virtual void v28();
unsigned unk04;Obj* m_08;void FUN_008d8af0(Obj*);void FUN_008f8a00(Obj*);bool FUN_008f8b40(Obj*);};
// @fnv 0x00c85810
// pdb: bhkUnaryAction::Add | bhkUnaryAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: apWorld
bool Obj::FUN_008f8b40(Obj* a)
{
    Obj* p = this ? m_08 : 0;
    bool r = false;
    if (p)
    {
        if (a)
        {
            Obj* w = (Obj*)this->v25();
            if (w != a->m_08)
            {
                this->v28();
                this->FUN_008f8a00(a);
                a->FUN_008d8af0(p);
                r = true;
            }
        }
        else
        {
            this->v28();
        }
    }
    return r;
}

}
}   // namespace f3m_008f8b40

// @f3 0x008f6f20 (community match, verified in this file)
namespace f3m_008f6f20 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
extern int (__stdcall* const DAT_00d9b084)(unsigned int, void*);
struct Pool_8f6f20 {
    void FUN_008f67f0();
    void FUN_008f67e0();
};
// pdb: hkMemoryRouter::replaceInstance | hkMemoryRouter.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: a
void __cdecl FUN_008f6f20(Pool_8f6f20* pool) {
    if (pool) pool->FUN_008f67f0();
    Pool_8f6f20* old = (Pool_8f6f20*)DAT_00d9b080(DAT_010f3170);
    if (old) old->FUN_008f67e0();
    DAT_00d9b084(DAT_010f3170, pool);
}
}   // namespace f3m_008f6f20

// @f3 0x008fc3f0 (community match, verified in this file)
namespace f3m_008fc3f0 {
namespace f3m_008fc3f0 {

struct RefObj {
    virtual void slot00(int flag);
    short unk04;
    short unk06;
    RefObj* unk08;
};

struct FUN_009ba5f0_shell {
    void SetChildObject(int p);
    void FUN_008fc3f0(RefObj* obj, int unused);
};

// pdb: hkConstraintCinfo::CloneData | bhkConstraint.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apData, __formal
void FUN_009ba5f0_shell::FUN_008fc3f0(RefObj* obj, int unused) {
    SetChildObject((int)obj);
    if (obj->unk04 != 0) {
        if (--obj->unk06 == 0) {
            obj->slot00(1);
        }
    }
}

}
}   // namespace f3m_008fc3f0

// @f3 0x008f25a0 (community match, verified in this file)
namespace f3m_008f25a0 {
struct FUN_008f25a0_Object {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* __thiscall FUN_008f25a0();
};

// pdb: NiMultiTargetTransformController::GetInterpolatorTarget | bhkUtilFunctions.obj | tesv_win, objopen_prop, low
void* FUN_008f25a0_Object::FUN_008f25a0()
{
    unk04 = 0;
    unk0C = 0;
    unk10 = 0;
    unk08 = 1;
    unk00 = (void*)0xe33978;
    return this;
}
}   // namespace f3m_008f25a0

// @f3 0x008f76e0 (community match, verified in this file)
namespace f3m_008f76e0 {
struct VObj;

struct VObj {
    virtual void u00();
    virtual void u04();
    virtual void u08();
    virtual void u0c();
    virtual void u10();
    virtual void u14();
    virtual void u18();
    virtual void u1c();
    virtual void u20();
    virtual void u24();
    virtual void u28();
    virtual void u2c();
    virtual void u30();
    virtual void u34();
    virtual void u38();
    virtual void u3c();
    virtual void u40();
    virtual void u44();
    virtual void u48();
    virtual void u4c();
    virtual void u50();
    virtual void u54();
    virtual void u58();
    virtual void u5c();
    virtual void u60();
    virtual void u64();
    virtual void u68();
    virtual void u6c();
    virtual void u70();
    virtual void u74();
    virtual void u78();
    virtual void u7c();
    virtual void u80();
    virtual void u84();
    virtual void u88();
    virtual void u8c();
    virtual void u90();
    virtual void u94();
    virtual void u98();
    virtual void u9c();
    virtual void ua0();
    virtual void ua4();
    virtual void ua8();
    virtual void uac();
    virtual void ub0();
    virtual void ub4();
    virtual void ub8();
    virtual void ubc();
    virtual void uc0();
    virtual void uc4();
    virtual VObj* uC8();
    virtual void ucc();
    virtual void ud0();
    virtual void ud4();
    virtual void ud8();
    virtual void udc();
    virtual bool uE0(int a, int b);
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    bool FUN_008f76e0(int a, int b);
};

// pdb: bhkShape::GetSubMaterialVarType | bhkShape.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aiKey, aeType
bool VObj::FUN_008f76e0(int a, int b)
{
    if (a != -1) {
        VObj* p = uC8();
        if (p)
            return p->uE0(a, b);
    }
    return (m_10 & b) != 0;
}
}   // namespace f3m_008f76e0

// @f3 0x008e96f0 (community match, verified in this file)
namespace f3m_008e96f0 {
void __cdecl FUN_008e96f0(void* p) {
    if (p) {
        Q78Heap* heap = Q78GetHeap();
        Q78FreeList* bucket = &((Q78FreeList*)&heap->heads)[7];
        FreeBlock443* block = (FreeBlock443*)p;
        if (*(volatile int*)&bucket->count >= heap->limit)
            heap->FUN_008f6890(7, block, 0xd);
        else
            bucket->Push(block);
    }
}
}   // namespace f3m_008e96f0

// @f3 0x008e8d70 (community match, verified in this file)
extern int DAT_010f31d8;
extern int DAT_010f324c;
extern int DAT_010f3294;
extern unsigned int DAT_00dcdc8c;
extern unsigned int DAT_00dcde2c;
extern unsigned int DAT_00dce264;
extern unsigned int DAT_00e332e4;
namespace f3m_008e8d70 {

class bhkRefObject
{
public:
    bhkRefObject();
    ~bhkRefObject();
    unsigned int m_vft;
    unsigned int unk04;
    int refCount;
};

class bhkWorldObject : public bhkRefObject
{
public:
    bhkWorldObject()
    {
        unk0c = 0;
        unk10 = 0;
        m_vft = (unsigned int)&DAT_00dcdc8c;
        DAT_010f31d8 += 1;
    }
    ~bhkWorldObject();
    unsigned int unk0c;
    unsigned int unk10;
};

class bhkPhantom : public bhkWorldObject
{
public:
    bhkPhantom()
    {
        m_vft = (unsigned int)&DAT_00dcde2c;
        DAT_010f324c += 1;
    }
    ~bhkPhantom();
};

class bhkAabbPhantom : public bhkPhantom
{
public:
    bhkAabbPhantom()
    {
        m_vft = (unsigned int)&DAT_00dce264;
        DAT_010f3294 += 1;
        unk14 = false;
    }
    ~bhkAabbPhantom();
    bool unk14;
};

class bhkAvoidBox : public bhkAabbPhantom
{
public:
    bhkAvoidBox(unsigned int value);
    ~bhkAvoidBox();
    void FUN_0091b5a0(unsigned int value);
};

bhkAvoidBox::bhkAvoidBox(unsigned int value)
{
    m_vft = (unsigned int)&DAT_00e332e4;
    FUN_0091b5a0(value);
}
}   // namespace f3m_008e8d70

// @f3 0x008f7040 (community match, verified in this file)
namespace f3m_008f7040 {
extern void (__cdecl* DAT_00f7b4d0)(void*);
class FUN_008f6d00 { public: virtual ~FUN_008f6d00(); };
class FUN_008f7040 : public FUN_008f6d00 {
public:
    virtual ~FUN_008f7040();
    static void operator delete(void* p) { DAT_00f7b4d0(p); }
};
FUN_008f7040::~FUN_008f7040()
{
}
}   // namespace f3m_008f7040

// @f3 0x008fa6c0 (community match, verified in this file)
extern int DAT_00e34374;
extern __declspec(thread) int DAT_0117c298;
namespace f3m_008fa6c0 {
namespace task0734 {
void* __cdecl FUN_0089eb90(unsigned int);
struct AllocatedObject { static void* operator new(unsigned int size) { return FUN_0089eb90(size); } };
void* __fastcall FUN_008f3130(void*);
struct MyType : AllocatedObject {
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
MyType(){ FUN_008f3130(this); *(void**)this=&DAT_00e34374; }
};
struct ScopedMemoryContext {
int oldVal;
ScopedMemoryContext(int newVal) {oldVal=DAT_0117c298;DAT_0117c298=newVal;}
~ScopedMemoryContext(){DAT_0117c298=oldVal;}
};
struct CollisionObject {
void FUN_008f3040(MyType*,void*);
MyType* FUN_008fa6c0(void* param);
};
// pdb: WeaponObject::CreateClone | WeaponObject.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCloneData
MyType* CollisionObject::FUN_008fa6c0(void* param) {
ScopedMemoryContext scope(0x10);
MyType* obj=new MyType;
FUN_008f3040(obj,param);
return obj;
}
}
}   // namespace f3m_008fa6c0

// @f3 0x008e8b80 (community match, verified in this file)
extern float FUN_00de6e60;
namespace f3m_008e8b80 {
namespace f3m_008e8b80 {
struct Params {
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    int unk2c;
    float unk30, unk34, unk38, unk3c, unk40, unk44;
    volatile int unk48;
    float unk4c, unk50;
    volatile int unk54;
    float unk58, unk5c, unk60, unk64, unk68;
    volatile int unk6c;
    volatile bool unk70;
    Params();
};
// pdb: hkpCharacterProxyCinfo::hkpCharacterProxyCinfo | bhkCharacterController.obj | fnv360_0822_retail, callee_sim, medium
Params::Params() {
    unk00 = 0.0f; unk04 = 0.0f; unk08 = 0.0f; unk0c = 0.0f;
    unk10 = 0.0f; unk14 = 0.0f; unk18 = 0.0f; unk1c = 0.0f;
    unk20 = 1.0f; unk24 = 0.0f; unk28 = 0.1f;
    unk30 = 0.0f; unk38 = 0.0f; unk3c = 0.0f; unk34 = 1.0f;
    unk48 = 0; unk54 = 4; unk40 = 0.0f; unk6c = 10; unk44 = 0.0f; unk70 = false;
    unk4c = 0.05f; unk50 = 10.0f; unk58 = 10.0f;
    unk5c = FUN_00de6e60; unk60 = 0.0f; unk64 = 1.5707964f; unk68 = 1.0f;
}
}
}   // namespace f3m_008e8b80

// @f3 0x008e4590 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008e4590 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
namespace f3m_008e4590 {
struct Mem { void FUN_008f6d90(void* p, unsigned int size, int tag); };
template <class T> struct Array {
    T* data;
    int size;
    unsigned int cap;
    ~Array() {
        if ((cap & 0x80000000) == 0) {
            int n = cap & 0x3fffffff;
            Mem* m = (Mem*)TlsGetValue(DAT_010f3170);
            m->FUN_008f6d90(data, n * sizeof(T), 0x17);
        }
    }
};
struct E64 { int v[16]; };
struct E112 { int v[28]; };
struct Holder {
    ~Holder();
    int unk00;
    int unk04;
    Array<E64> a;
    Array<E112> b;
    Array<short> c;
};
// pdb: hkaSkeletonMapperData::~hkaSkeletonMapperData | hkaSkeletonMapperData.obj | tesv_win, call_seq, medium
Holder::~Holder() {
}
}
}   // namespace f3m_008e4590

// @f3 0x008e9d30 (community match, verified in this file)
namespace f3m_008e9d30 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace Destroy319{struct Atomic319{virtual void v0();virtual void Destroy();long refs;};struct Ref319{Atomic319*object;~Ref319(){Atomic319*p=object;if(p&&!InterlockedDecrement(&p->refs))p->Destroy();}};struct Havok319{virtual ~Havok319();unsigned short memory;short refs;unsigned int Count()const{return refs;}void Release(){if(memory){--refs;if((unsigned short)Count()==0)delete this;}}};struct Owner319{
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
Ref319 ref;Havok319*havok;~Owner319();};
// pdb: bhkCharacterControllerCinfo::~bhkCharacterControllerCinfo | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
Owner319::~Owner319(){Havok319*current=havok;if(current){current->Release();havok=0;}}
}
}   // namespace f3m_008e9d30

// @f3 0x008e4560 (community match, verified in this file)
namespace f3m_008e4560 {
namespace mapping_data_default_ctor {
struct Skeleton;struct SimpleMapping;struct ChainMapping;
template<class T> struct Array {
 T* data;int count;unsigned int capacityAndFlags;
 __forceinline Array() : data(0),count(0),capacityAndFlags(0x80000000u) {}
};
struct MappingData {
 Skeleton* skeletonA;Skeleton* skeletonB;
 Array<SimpleMapping> simpleMappings;Array<ChainMapping> chainMappings;Array<short> unmappedBones;
 bool keepUnmappedLocal;
 MappingData();
};
// pdb: hkaSkeletonMapperData::hkaSkeletonMapperData | hkaSkeletonMapperData.obj | fnv360_0822_retail, call_gap, medium
MappingData::MappingData() { skeletonA=0;skeletonB=0;keepUnmappedLocal=true; }
}
}   // namespace f3m_008e4560

// @f3 0x008e6b50 (community match, verified in this file)
namespace f3m_008e6b50 {
namespace f3m_008e6b50 {

using namespace f3m_008e5c40::Z8e5c40;

struct Allocator4 {
    void FUN_008f6d90(void* block, unsigned int bytes, int tag);
};

struct FloatArray {
    float* data;
    unsigned int count;
    int capacityFlags;
    ~FloatArray() {
        if (!(capacityFlags & 0x80000000u)) {
            unsigned int capacity = capacityFlags & 0x3fffffff;
            Allocator4* allocator = static_cast<Allocator4*>(TlsGetValue(DAT_010f3170));
            allocator->FUN_008f6d90(data, capacity * sizeof(float), 0x17);
        }
    }
};

class Obj {
public:
    FloatArray m_arr;
    Vec* m_p;
    StackPolicy m_policy;
    ~Obj();
};

Obj::~Obj() {
    m_policy.Release(m_p);
}

}
}   // namespace f3m_008e6b50

// @f3 0x008f8920 (community match, verified in this file)
namespace f3m_008f8920 {
struct Dst_8f8920 { int u0, a4; };
struct Rec_8f8920 { int u0, u4, v8; };
struct Arg_8f8920 { Rec_8f8920* FUN_0082a280(); };
struct O_8f8920 {
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual void t05();
    virtual void t06();
    virtual void t07();
    virtual void t08();
    virtual void t09();
    virtual void t0a();
    virtual void t0b();
    virtual void t0c();
    virtual void t0d();
    virtual void t0e();
    virtual void t0f();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t1a();
    virtual void t1b();
    virtual void t1c();
    virtual void t1d();
    virtual void t1e();
    virtual void t1f();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t2a();
    virtual void t2b();
    virtual void t2c();
    virtual Dst_8f8920* v0b4(char* flag);
    void FUN_008f7ec0(Arg_8f8920* x);
    void FUN_008f8920(Arg_8f8920* x);
};
// pdb: bhkUnaryAction::LinkObject | bhkUnaryAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void O_8f8920::FUN_008f8920(Arg_8f8920* x) {
    char flag;
    Dst_8f8920* a = v0b4(&flag);
    Rec_8f8920* b = x->FUN_0082a280();
    if (a && b) a->a4 = b->v8;
    FUN_008f7ec0(x);
}
}   // namespace f3m_008f8920

// @f3 0x008fbbb0 (community match, verified in this file)
#include <intrin.h>
#pragma intrinsic(_ReadWriteBarrier)
namespace f3m_008fbbb0 {

struct Node8fbbb0 {
    virtual void release(int);
    unsigned short flag;
    unsigned short refs;
    void* owner;
};

struct Owner8fbbb0 {
    int unk00;
    Node8fbbb0* node;
    void FUN_008fbbb0(Node8fbbb0* next);
};

// pdb: hkConstraintCinfo::SetData | bhkConstraint.obj | fnv360_0822_retail, call_seq, low
// pdb params: apData
void Owner8fbbb0::FUN_008fbbb0(Node8fbbb0* next)
{
    Node8fbbb0* old = *(Node8fbbb0* volatile*)&node;
    if (old) {
        old->owner = 0;
        Node8fbbb0* cur = *(Node8fbbb0* volatile*)&node;
        if (*(short*)((char*)cur + 4)) {
            short& refs = *(short*)((char*)cur + 6);
            --refs;
            if (refs == 0)
                cur->release(1);
        }
    }
    if (next) {
        if (*(short*)((char*)next + 4)) {
            short& refs = *(short*)((char*)next + 6);
            ++refs;
        }
        next->owner = this;
    }
    node = next;
}
}   // namespace f3m_008fbbb0

// @f3 0x008e8fa0 (community match, verified in this file)
namespace f3m_008e8fa0 {
namespace task1288 {
struct RgbaColor { float r,g,b,a; };
struct Manager {
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
RgbaColor tint; unsigned int count; void FUN_008e8fa0(RgbaColor&);
};
// pdb: bhkCharacterProxy::GethkLinearVelocity | bhkCharacterListenerSpell.obj | fnv360_0721_beta, call_gap, low
void Manager::FUN_008e8fa0(RgbaColor& color) { RgbaColor& t=tint; t.r+=color.r; t.g+=color.g; t.b+=color.b; t.a+=color.a; ++count; }
}
}   // namespace f3m_008e8fa0

// @f3 0x008f9940 (community match, verified in this file)
namespace f3m_008f9940 {
struct In_8f9940 { int v0; char pad[0x14]; char b18; char pad2[3]; int v1c; };
struct Mid_8f9940 { char pad[0x10]; In_8f9940 in; };
struct Out_8f9940 { int a0, a4; char b8; char pad[7]; int a10; };
struct O_8f9940 {
    int u0, u4; Mid_8f9940* p8;
    In_8f9940* Sub() { if (this && p8) { In_8f9940* i = &p8->in; if (i) return i; } return 0; }
    void FUN_008f9940(Out_8f9940* o);
};
// pdb: bhkWorldObject::CopyCinfo | bhkWorldObject.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: bhkWorldObject::SetUnderwater)
// pdb params: arInfo
void O_8f9940::FUN_008f9940(Out_8f9940* o) {
    if (this && p8) {
        In_8f9940* i = &p8->in;
        if (i) { o->a4 = i->v0; o->b8 = i->b18; }
    }
    o->a10 = 0;
    int r;
    if (this && p8) {
        In_8f9940* i = &p8->in;
        if (i) r = i->v1c; else r = 0;
    } else r = 0;
    o->a0 = r;
}
}   // namespace f3m_008f9940

// @f3 0x008f89b0 (community match, verified in this file)
namespace f3m_008f89b0 {
struct C8fData { int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;void* value;};
struct C8fOwner {int unk00;int unk04;C8fData* data; bool FUN_008c1550(C8fOwner*);void* Value() {return this && data ? data->value : 0;} bool FUN_008f89b0(C8fOwner*);};
// pdb: bhkUnaryAction::IsEqual | bhkUnaryAction.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
bool C8fOwner::FUN_008f89b0(C8fOwner* other) { bool result=FUN_008c1550(other); if(result) { void* a=Value(); void* b=other->Value(); result &= a==b; } return result; }
}   // namespace f3m_008f89b0

// @f3 0x008f84d0 (community match, verified in this file)
namespace f3m_008f84d0 {
struct VectorB8f84d0 { float x,y,z,w; void add(float s, const VectorB8f84d0& v) { x+=v.x*s; y+=v.y*s; z+=v.z*s; w+=v.w*s; } };
struct OwnerB8f84d0 {
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
float scale; VectorB8f84d0 value; void FUN_008f84d0(VectorB8f84d0* v); };
// pdb: hkpMotion::applyLinearImpulse | hkpMotion.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpMotion::hkpMotion)
// pdb params: imp
void OwnerB8f84d0::FUN_008f84d0(VectorB8f84d0* v) { value.add(scale,*v); }
}   // namespace f3m_008f84d0

// @f3 0x008f3a70 (community match, verified in this file)
namespace f3m_008f3a70 {
// pdb: bhkBlendCollisionObject::SetStoredWorld | bhkBlendCollisionObject.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject, apWorld
namespace Task8f3a {struct Body{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int value;};struct Interface{void**methods;};struct Node;struct Object{void**methods;};struct Node{int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;Object** children;unsigned short unkA4;unsigned short count;};Interface* __cdecl FUN_00424fe0(Object*);typedef Body*(__thiscall* GetBody)(Interface*);typedef Node*(__thiscall* GetNode)(Object*);void __cdecl FUN_008f3a70(Object*obj,int value){if(obj){Interface* face=FUN_00424fe0(obj);if(face){Body* body=((GetBody)face->methods[15])(face);if(body)body->value=value;}Node* node=((GetNode)obj->methods[3])(obj);if(node)for(unsigned i=0;i<node->count;++i)FUN_008f3a70(node->children[i],value);}}}
}   // namespace f3m_008f3a70

// @f3 0x008f8720 (community match, verified in this file)
namespace f3m_008f8720 {
namespace f3m_008f8720 {
struct Sub_8720 {
    char data[0x50];
    Sub_8720& FUN_008f86a0(const Sub_8720& o);
};
struct Base_8720 {
    char data[0x40];
    Base_8720& FUN_008fda60(const Base_8720& o);
};
struct Cls_8720 : Base_8720 {
    Sub_8720 sub;
    float unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    bool unkAC, unkAD, unkAE;
    Cls_8720& FUN_008f8720(const Cls_8720& o);
};
}
using namespace f3m_008f8720;

// pdb: hkMotionState::operator= | hkpMotion.obj | tesv_win, call_gap, low
Cls_8720& Cls_8720::FUN_008f8720(const Cls_8720& o)
{
    FUN_008fda60(o);
    sub.FUN_008f86a0(o.sub);
    unk90 = o.unk90;
    unk94 = o.unk94;
    unk98 = o.unk98;
    unk9C = o.unk9C;
    unkA0 = o.unkA0;
    unkA4 = o.unkA4;
    unkA8 = o.unkA8;
    unkAC = o.unkAC;
    unkAD = o.unkAD;
    unkAE = o.unkAE;
    return *this;
}
}   // namespace f3m_008f8720

// @f3 0x008fda10 (community match, verified in this file)
namespace f3m_008fda10 {
struct Dst_8fda10 { char pad[0x30]; float x, y, z, w; };
struct O_8fda10 {
    char pad[0x30]; float x, y, z, w;
    void FUN_008fd970(Dst_8fda10* d);
    Dst_8fda10* FUN_008fda10(Dst_8fda10* d);
};
// pdb: bhkTransform::ToHK | bhkSimpleShapePhantom.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arDst
Dst_8fda10* O_8fda10::FUN_008fda10(Dst_8fda10* d) {
    FUN_008fd970(d);
    float b = y, c = z, e = w;
    d->x = x; d->y = b; d->z = c; d->w = e;
    return d;
}
}   // namespace f3m_008fda10

// @f3 0x008fe950 (community match, verified in this file)
struct Value8fe {float x,y,z,w;Value8fe& operator=(const Value8fe& other){x=other.x;y=other.y;z=other.z;w=other.w;return *this;}};
extern Value8fe DAT_00f7b120;
struct Inner8fe {int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; Value8fe value;};
struct Owner8fe {int unk00;int unk04;Inner8fe* inner;Value8fe* FUN_008fe950(Value8fe*);};
// pdb: bhkRigidBody::GetRotation | bhkRigidBody.obj | fnv360_0721_beta, objrun, medium
// pdb params: arRot
Value8fe* Owner8fe::FUN_008fe950(Value8fe* out){const Value8fe* value;if(this && inner)value=&inner->value;else value=&DAT_00f7b120;*out=*value;return out;}

// @f3 0x008f6d30 (community match, verified in this file)
namespace f3m_008f6d30 {
namespace workerB8f6d30 {
struct Block {Block* next;};
struct Allocator {virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void* Allocate(int,unsigned int);};
struct Bucket {Block* head; int count;};
struct Heap {
 int unk00,unk04,unk08,unk0c; Allocator* fallback; int unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,limit;
 Bucket buckets[25]; int unk100; signed char smallBucket[513]; unsigned char unk305,unk306,unk307; int largeBucket[8];
 void* FUN_008f6800(int,unsigned int); void* FUN_008f6d30(int,unsigned int);
};
// pdb: hkpPhysicsSystem::hkpPhysicsSystem | hkpPhysicsSystem.obj | tesv_win, call_dedup, low
void* Heap::FUN_008f6d30(int size,unsigned int tag){if(size<=0x2000){int i;if(size<=0x200)i=smallBucket[size];else i=largeBucket[(size-1)>>10]; Block* p=buckets[i].head;if(p){--buckets[i].count;buckets[i].head=p->next;return p;}return FUN_008f6800(i,tag);}return fallback->Allocate(size,tag);}
}
}   // namespace f3m_008f6d30

// @f3 0x008ea150 (community match, verified in this file)
namespace f3m_008ea150 {
namespace getter8e {
struct Type {int unk00;Type* parent;};extern Type DAT_010f3350;extern float DAT_00f7a690;
struct Value {int unk00,unk04,unk08,unk0C;float value;};
struct Node {virtual void V0();virtual void V4();virtual Type* GetType();int unk04;Value* value;
 bool IsKind(Type* type){for(Type* current=GetType();current;current=current->parent)if(current==type)return true;return false;}
 Node* Cast(Type* type){return IsKind(type)?this:0;}
 float GetValue(){if(value){float result=value->value;return result;}float result=DAT_00f7a690;return result;}
};
struct Owner {int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0; int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240; int unk244; int unk248; int unk24C; int unk250; int unk254; int unk258; int unk25C; int unk260; int unk264; int unk268; int unk26C; int unk270; int unk274; int unk278; int unk27C; int unk280; int unk284; int unk288; int unk28C; int unk290; int unk294; int unk298; int unk29C; int unk2A0; int unk2A4; int unk2A8; int unk2AC; int unk2B0; int unk2B4; int unk2B8; int unk2BC; int unk2C0; int unk2C4; int unk2C8; int unk2CC; int unk2D0; int unk2D4; int unk2D8; int unk2DC; int unk2E0; int unk2E4; int unk2E8; int unk2EC; int unk2F0; int unk2F4; int unk2F8; int unk2FC; int unk300; int unk304; int unk308; int unk30C; int unk310; int unk314; int unk318; int unk31C; int unk320; int unk324; int unk328; int unk32C; int unk330; int unk334; int unk338; int unk33C; int unk340; int unk344; int unk348; int unk34C; int unk350; int unk354; int unk358; int unk35C; int unk360; int unk364; int unk368; int unk36C; int unk370; int unk374; int unk378; int unk37C; int unk380; int unk384; int unk388; int unk38C; int unk390; int unk394; int unk398; int unk39C; int unk3A0; int unk3A4; int unk3A8; int unk3AC; int unk3B0; int unk3B4; int unk3B8; int unk3BC; int unk3C0; int unk3C4; int unk3C8; int unk3CC; int unk3D0; int unk3D4; int unk3D8; int unk3DC; int unk3E0; int unk3E4; int unk3E8; int unk3EC; int unk3F0; int unk3F4; int unk3F8; int unk3FC; int unk400; int unk404; int unk408; int unk40C; int unk410; int unk414; int unk418; int unk41C; int unk420; int unk424; int unk428; int unk42C; int unk430; int unk434; Node* node;int unk43C; int unk440; int unk444; int unk448; int unk44C; int unk450; int unk454; int unk458; int unk45C; int unk460; int unk464; int unk468; int unk46C; int unk470; int unk474; int unk478; int unk47C; float fallback;__forceinline float Get();float bhkCharacterController_GetRadius();};
__forceinline float Owner::Get(){if(node){Node* selected=node->Cast(&DAT_010f3350);if(selected){float result=selected->GetValue();return result;}}float result=fallback;return result;}
// pdb: bhkCharacterController::GetRadius | bhkCharacterController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap_sim), high
float Owner::bhkCharacterController_GetRadius(){return Get();}
}
}   // namespace f3m_008ea150

// @f3 0x008fd2f0 (community match, verified in this file)
namespace f3m_008fd2f0 {
struct Receiver8fd; struct Table8fd { void* unk000; void* unk004; void* unk008; void* unk00c; void* unk010; void* unk014; void* unk018; void* unk01c; void* unk020; void* unk024; void* unk028; void* unk02c; void* unk030; void* unk034; void* unk038; void* unk03c; void* unk040; void* unk044; void* unk048; void* unk04c; void* unk050; void* unk054; void* unk058; void* unk05c; void* unk060; void* unk064; void* unk068; void* unk06c; void* unk070; void* unk074; void* unk078; void* unk07c; void* unk080; void* unk084; void* unk088; void* unk08c; void* unk090; void* unk094; void* unk098; void* unk09c; void* unk0a0; void* unk0a4; void* unk0a8; void* unk0ac; void* unk0b0; void* unk0b4; void* unk0b8; void* unk0bc; void* unk0c0; void* unk0c4; Receiver8fd* (__thiscall* get)(Receiver8fd*); void* unk0cc; void* unk0d0; void* unk0d4; void* unk0d8; void* unk0dc; bool (__thiscall* check)(Receiver8fd*,int,unsigned int); }; struct Receiver8fd { Table8fd* table; };
struct Count8fd; struct CountTable8fd { void* unk00; unsigned int (__thiscall* count)(Count8fd*); }; struct Count8fd { CountTable8fd* table; unsigned int Count(){return table->count(this);} };
struct Entry8fd { int unk00; int unk04; Receiver8fd* object; }; struct Slot8fd { Entry8fd* entry; int unk04; int unk08; int unk0c; }; struct Data8fd { int unk00; int unk04; int unk08; int unk0c; Count8fd counter; int unk14; Slot8fd* slots; };
struct Owner8fd { int unk00; int unk04; Data8fd* data; int unk0c; unsigned int flags; unsigned int Count(){if(this && data)return data->counter.Count();return 0;} Receiver8fd* Get(unsigned int i){if(this && data){Entry8fd* entry=data->slots[i].entry;if(entry)return entry->object;}return 0;} bool FUN_008fd2f0(int,unsigned int); };
// pdb: bhkListShape::RembhkShapeRef | bhkListShape.obj | fnv360_0721_beta, objrun_sim, low, conflict (bridge: bhkListShape::QSubMaterial)
bool Owner8fd::FUN_008fd2f0(int a,unsigned int mask){bool result=false;unsigned int count=Count();for(unsigned int i=0;i<count;++i){if(result)break;Receiver8fd* object=Get(i);Receiver8fd* next=object->table->get(object);if(next)result=next->table->check(next,a,mask);}if(!result) result=(flags & mask)!=0; return result;}
}   // namespace f3m_008fd2f0

// @f3 0x008fe4f0 (community match, verified in this file)
extern float DAT_00e35180[];
namespace f3m_008fe4f0 {
struct Z1350 {unsigned char index;void FUN_0090aba0(float*);};
struct Y1350 {
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
unsigned char ubc;Z1350 z;};
struct A1350 {Y1350* hkpRigidBody_getStoredDynamicMotion();
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
unsigned char u18c,index;};
struct Obj1350 {unsigned int u0,u4;A1350* owner;float Value();float FUN_008fe4f0();};
__forceinline float Obj1350::Value(){
 float ret;
 if(this && owner){
  A1350* a=owner;
  Y1350* result=a->hkpRigidBody_getStoredDynamicMotion();
  Z1350* z; Z1350 local;
  if(result)z=&result->z;
  else{ret=DAT_00e35180[a->index];local.FUN_0090aba0(&ret);z=&local;}
  ret=DAT_00e35180[z->index];return ret;
 }
 ret=0.0f;return ret;
}

// pdb: bhkRigidBody::GetMaxAngularVelocity | bhkRigidBody.obj | fnv360_0822_retail, call_gap, medium
float Obj1350::FUN_008fe4f0(){float value=Value();return value;}
}   // namespace f3m_008fe4f0

// @f3 0x008fc060 (community match, verified in this file)
namespace f3m_008fc060 {
namespace bind060 {struct Ref;struct Tracker {
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
// pdb: bhkConstraint::SethkObject | bhkConstraint.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aphkObject
int count;};struct Link {int unk00;int unk04;Tracker* tracker;};struct Manager;struct Table {void* unk00;void* unk04;void* unk08;void* unk0c;void (__thiscall *remove)(Manager*,Ref*);};struct Manager {Table* table;};struct Ref {int unk00;int unk04;Manager* manager;int unk0c;int unk10;Link* link;};struct Owner {int unk00;int unk04;Ref* current;Ref* Get(){return this?current:0;}void FUN_008f7c30(Ref*);void FUN_008fc060(Ref*);};void Owner::FUN_008fc060(Ref* incoming){Ref* old=Get();if(incoming!=old){if(old){Manager* manager=old->manager;if(manager){Tracker* tracker=old->link->tracker;if(tracker)++tracker->count;manager->table->remove(manager,old);if(tracker)--tracker->count;}}FUN_008f7c30(incoming);}}}
}   // namespace f3m_008fc060

// @f3 0x008fbb40 (community match, verified in this file)
namespace f3m_008fbb40 {
struct OwnerBB {
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
    virtual int GetC8();
    virtual int GetCC();
    bool FUN_008c1550(OwnerBB*);
    bool FUN_008fbb40(OwnerBB*);
};
// pdb: bhkConstraint::CopyCinfo | bhkConstraint.obj | fnv360_0822_debug, objrun, low, conflict (bridge: bhkConstraint::IsEqual)
// pdb params: arInfo
bool OwnerBB::FUN_008fbb40(OwnerBB* other) {
    bool result=FUN_008c1550(other);
    if (result) {
        result &= GetC8()==other->GetC8();
        result &= GetCC()==other->GetCC();
    }
    return result;
}
}   // namespace f3m_008fbb40

// @f3 0x008f6ee0 (community match, verified in this file)
namespace f3m_008f6ee0 {
namespace previous_frame_release {
struct Frame {unsigned int unk00,unk04;char* begin;char* end;};
struct Owner {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;Frame current;void FUN_008f6d90(void*,unsigned int,int);void FUN_008f6ee0(unsigned int);};
// pdb: hkMemoryRouter::resetPeakMemoryStatistics | hkMemoryRouter.obj | tesv_win, objrun_open, low
void Owner::FUN_008f6ee0(unsigned int unused){char* begin=current.begin;Frame* previous=reinterpret_cast<Frame*>(begin-sizeof(Frame));unsigned int bytes=static_cast<unsigned int>(current.end-begin+sizeof(Frame));current=*previous;FUN_008f6d90(previous,bytes,23);}
}
}   // namespace f3m_008f6ee0

// @f3 0x008fe480 (community match, verified in this file)
namespace f3m_008fe480 {
struct Owner {
 char pad[0x70];
 float m_70,m_74,m_78,m_7c,m_80,m_84,m_88,m_8c,m_90,m_94,m_98,m_9c;
 void FUN_008fe480(const float* src);
};
void Owner::FUN_008fe480(const float* src) {
 m_70=src[0]; m_74=src[1]; m_78=src[2]; m_7c=src[3];
 m_80=src[4]; m_84=src[5]; m_88=src[6]; m_8c=src[7];
 m_90=src[8]; m_94=src[9]; m_98=src[10]; m_9c=src[11];
}
}   // namespace f3m_008fe480

// @f3 0x008f24c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* DAT_010f3400;
namespace f3m_008f24c0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern void* (*DAT_00f7b4cc)(unsigned int size, unsigned int align);
extern void (*DAT_00f7b4d0)(void* p);

int FUN_00cbb930(void* p);

struct TlsBlock298 {
    char pad0000[0x298];
    int unk298;
};
__declspec(thread) TlsBlock298 g_tlsBlock;

struct TlsGuard {
    int m_old;
    __forceinline TlsGuard(int value)
    {
        m_old = g_tlsBlock.unk298;
        g_tlsBlock.unk298 = value;
    }
    __forceinline ~TlsGuard() { g_tlsBlock.unk298 = m_old; }
};

struct HkAllocator {
    void* Allocate(unsigned int size, unsigned int tag);
};

struct FUN_008f6a50 {
    virtual void* vf0(unsigned int a, unsigned int b, unsigned int c);
    virtual void* vf1(unsigned int a, unsigned int b, unsigned int c);
    virtual void vf2(void* buffer, unsigned int size);
    char unk04[0x330 - 4];

    FUN_008f6a50(void* manager, int count);

    static void* operator new(unsigned int size, unsigned int align) { return DAT_00f7b4cc(size, align); }
    static void operator delete(void* p) { DAT_00f7b4d0(p); }
    static void operator delete(void* p, unsigned int) { DAT_00f7b4d0(p); }
};

// pdb: DoThreadSetup | bhkUtilFunctions.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: task_thread
void FUN_008f24c0()
{
    TlsGuard guard(0x10);

    FUN_008f6a50* memory = new (0x10) FUN_008f6a50(DAT_010f3400, 0x10);

    if (memory) {
        FUN_00cbb930(memory);
        HkAllocator* allocator = (HkAllocator*)TlsGetValue(DAT_010f3170);
        void* buffer = allocator->Allocate(0x5000, 1);
        memory->vf2(buffer, 0x5000);
    }
}
}   // namespace f3m_008f24c0

// @f3 0x008e9730 (community match, verified in this file)
extern unsigned int DAT_00de6e68;
namespace f3m_008e9730 {
namespace f3m_008e9730 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Block9730 { Block9730* next; };
struct Bucket9730 {
    Block9730* head;
    int count;
    void Push(Block9730* b) { ++count; b->next = head; head = b; }
};
struct Heap9730 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30;
    int limit;
    Bucket9730 buckets[25];
    void FUN_008f6890(int index, Block9730* block, unsigned int tag);
};
struct Cls9730 {
    unsigned int m_vtbl;
    Cls9730* FUN_008e9730(unsigned int flags);
};

static __forceinline void PoolFree9730(void* p, int index)
{
    Heap9730* heap = (Heap9730*)TlsGetValue(DAT_010f3170);
    Bucket9730* bucket = &heap->buckets[index];
    Block9730* block = (Block9730*)p;
    if (*(volatile int*)&bucket->count >= heap->limit)
        heap->FUN_008f6890(index, block, 0x1f);
    else
        bucket->Push(block);
}

// pdb: hkpClosestCdPointCollector::`scalar deleting destructor' | bhkCharacterController.obj | fnv360_0822_retail, objrun_sim, low
Cls9730* Cls9730::FUN_008e9730(unsigned int flags)
{
    m_vtbl = (unsigned int)&DAT_00de6e68;
    if (flags & 1)
        PoolFree9730(this, 6);
    return this;
}

}
}   // namespace f3m_008e9730

// @f3 0x008f7070 (community match, verified in this file)
namespace f3m_008f7070 {
namespace Append407{struct Node{unsigned int unk00,unk04,unk08;Node*next;};struct Header{float a,b,c,d,e;unsigned int first,second,third;};struct Payload{
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
// pdb: hkpAllRayHitCollector::addRayHit | hkpAllRayHitCollector.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
};struct Record{Header header;Payload payload;Node*last;unsigned int unk54,unk58,unk5c;void Set(const Header&h){header.a=h.a;header.b=h.b;header.c=h.c;header.d=h.d;header.e=h.e;header.first=h.first;header.second=h.second;header.third=h.third;}};struct Array{Record*data;unsigned int count,capacityFlags;Record*Append();};void __cdecl FUN_00901f10(Array*,unsigned int);__forceinline Record*Array::Append(){if(count==(capacityFlags&0x3fffffff))FUN_00901f10(this,96);return &data[count++];}void __cdecl FUN_009712f0(Payload*,int,Node*);struct Owner{unsigned int unk00,unk04,unk08,unk0c;Array array;void hkpAllRayHitCollector_addRayHit(Node*,const Header*);};void Owner::hkpAllRayHitCollector_addRayHit(Node*node,const Header*header){Record*record=array.Append();record->Set(*header);FUN_009712f0(&record->payload,8,node);Node*last=node;while(last->next)last=last->next;record->last=last;}}
}   // namespace f3m_008f7070

// @f3 0x008f86a0 (community match, verified in this file)
namespace f3m_008f86a0 {
// pdb: hkMotionState::operator= | hkpMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: __that
struct FUN_008f86a0{float values[20];FUN_008f86a0(const FUN_008f86a0&);};FUN_008f86a0::FUN_008f86a0(const FUN_008f86a0&source){
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
values[16]=source.values[16];
values[17]=source.values[17];
values[18]=source.values[18];
values[19]=source.values[19];
}
}   // namespace f3m_008f86a0

// @f3 0x008e8a00 (community match, verified in this file)
namespace f3m_008e8a00 {
struct Vector337 {
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

    void __thiscall FUN_008e8a00(Vector337* source);
};

// pdb: hkMatrix3::operator= | Projectile.obj | tesv_win, call_gap, low
void __thiscall Vector337::FUN_008e8a00(Vector337* source) {
    unk00 = source->unk00;
    unk04 = source->unk04;
    unk08 = source->unk08;
    unk0C = source->unk0C;
    unk10 = source->unk10;
    unk14 = source->unk14;
    unk18 = source->unk18;
    unk1C = source->unk1C;
    unk20 = source->unk20;
    unk24 = source->unk24;
    unk28 = source->unk28;
    unk2C = source->unk2C;
}
}   // namespace f3m_008e8a00

// @f3 0x008fd970 (community match, verified in this file)
namespace f3m_008fd970 {
struct FUN_008fd970_Obj {
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

    void FUN_008fd970(float* dest);
};

void FUN_008fd970_Obj::FUN_008fd970(float* dest) {
    {
        float value1 = unk04;
        float value2 = unk08;
        float value3 = unk0C;
        dest[0] = unk00;
        dest[1] = value1;
        dest[2] = value2;
        dest[3] = value3;
    }
    {
        float value1 = unk14;
        float value2 = unk18;
        float value3 = unk1C;
        dest[4] = unk10;
        dest[5] = value1;
        dest[6] = value2;
        dest[7] = value3;
    }
    {
        float value1 = unk24;
        float value2 = unk28;
        float value3 = unk2C;
        dest[8] = unk20;
        dest[9] = value1;
        dest[10] = value2;
        dest[11] = value3;
    }
}
}   // namespace f3m_008fd970

// @f3 0x008e4660 (community match, verified in this file)
namespace f3m_008e4660 {
struct NativeArray12 {
    void* data; int count; unsigned int capacity;
    void Init() { data=0; count=0; capacity=0x80000000u; }
};
struct ArrayOwner {
    int unk00, unk04, unk08; float unk0C;
    NativeArray12 first, second, third;
    bool unk34, unk35;
    ArrayOwner();
};
// pdb: hkaSkeletonMapperUtils::Params::Params | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
ArrayOwner::ArrayOwner() {
    unk0C=0.0f; unk00=0; unk04=0; unk08=0;
    first.Init(); second.Init(); third.Init();
    unk34=true; unk35=true;
}
}   // namespace f3m_008e4660

// @f3 0x008e9460 (community match, verified in this file)
namespace f3m_008e9460 {
struct Float4 {
    float x,y,z,w;
    Float4(const Float4& source):x(source.x),y(source.y),z(source.z),w(source.w) {}
};
struct MatrixRecord {
    Float4 first,second,third; unsigned int metadata;
    MatrixRecord(const MatrixRecord&);
};
MatrixRecord::MatrixRecord(const MatrixRecord& source):first(source.first),second(source.second),third(source.third),metadata(source.metadata) {}
}   // namespace f3m_008e9460

// @f3 0x008f7cb0 (community match, verified in this file)
namespace f3m_008f7cb0 {
namespace Task1579 {
struct RefObj {virtual ~RefObj();short size,refs;void Release(){if(size){if(--refs==0)delete this;}}};
struct FUN_00825830 {virtual ~FUN_00825830();int flags;};
struct FUN_008f7cb0:FUN_00825830 {RefObj* p;virtual ~FUN_008f7cb0();};
// pdb: bhkRefObject::~bhkRefObject | bhkRefObject.obj | fnv360_0822_retail, call_seq, medium
FUN_008f7cb0::~FUN_008f7cb0(){if(p)p->Release();}
}

}   // namespace f3m_008f7cb0

// @f3 0x008e47d0 (community match, verified in this file)
namespace f3m_008e47d0 {
namespace f3m_008e47d0 {
using namespace f3m_008f9eb0::f3m_008f9eb0;

struct FUN_008e47d0 {
    unsigned int unk00, unk04, unk08, unk0c;
    Array<__int64> m10;
    Array<__int64> m1c;
    Array<__int64> m28;
    ~FUN_008e47d0();
};

// pdb: hkaSkeletonMapperUtils::Params::~Params | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
FUN_008e47d0::~FUN_008e47d0() {}
}
}   // namespace f3m_008e47d0

// @f3 0x008fea20 (community match, verified in this file)
struct Vec4_8fea20 { float x, y, z, w; };
extern Vec4_8fea20 DAT_01092a50;
struct C_8fea20 { int unk00; int unk04; void* unk08; Vec4_8fea20* FUN_008fea20(Vec4_8fea20* out); };
// pdb: bhkRigidBody::GetCenterOfMassLocal | bhkRigidBody.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arCOM
Vec4_8fea20* C_8fea20::FUN_008fea20(Vec4_8fea20* out)
{
    Vec4_8fea20* src = (this && unk08) ? (Vec4_8fea20*)((char*)unk08 + 0x160) : &DAT_01092a50;
    out->x = src->x; out->y = src->y; out->z = src->z; out->w = src->w;
    return out;
}

// @f3 0x008fb1d0 (community match, verified in this file)
namespace f3m_008fb1d0 {
struct AttachInfo1783 {void* data;};
struct Info8fb { int m_00, m_04, m_08, m_0c; int m_10; };
struct Ctrl8fb {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual Info8fb* GetInfo();
};
struct Node8fb {
    char pad[0x18];
    Node8fb* m_parent;
    Ctrl8fb* m_ctrl;
 Node8fb* GetParent()const{return m_parent;}
};
Node8fb* FUN_00aab350(Node8fb* root, const char* name, int flags);
void FUN_008fa8d0(void* a, AttachInfo1783 b, Node8fb* node, Node8fb* anchor, bool d);
static __forceinline Node8fb* FindAttachParent(Node8fb* node, Node8fb* root) {
    Node8fb* p=node ? node->GetParent():0;
    while (p) {
        Ctrl8fb* c = p->m_ctrl;
        if (c && (!c->GetInfo() || p->m_ctrl->GetInfo()->m_10)) break;
        if (p == root) break;
        p = p->GetParent();
    }
    if (p == root) return 0;
    return p;
}
// pdb: WeaponObject::UpdateConstraints | WeaponObject.obj | fnv360_0822_retail, call_gap, low
// pdb params: abEnable, aOwnerFilter, apRoot3d, abDefaultKeyframed
void __stdcall FUN_008fb1d0(void* a, AttachInfo1783 b, Node8fb* root, bool d) {
    Node8fb* node = FUN_00aab350(root, "Weapon", 0);
    Node8fb* parent = FindAttachParent(node, root);
    if (node && parent) FUN_008fa8d0(a, b, node, parent, d);
    node = FUN_00aab350(root, "Backpack", 0);
    parent = FindAttachParent(node, root);
    if (node && parent) FUN_008fa8d0(a, b, node, parent, d);
}
}   // namespace f3m_008fb1d0

// @f3 0x008fc4a0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008fc4a0 {
namespace w8fc4a0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Heap {
    void* FUN_008f6d30(int size, unsigned int tag);
    void FUN_008f6d90(void* p, unsigned int size, unsigned int tag);
};

struct RefObject {
    virtual ~RefObject();
    unsigned short memSizeAndFlags;
    short referenceCount;

    static __forceinline void* operator new(unsigned int size) {
        Heap* heap = static_cast<Heap*>(TlsGetValue(DAT_010f3170));
        RefObject* p = static_cast<RefObject*>(heap->FUN_008f6d30(size, size));
        p->memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static __forceinline void operator delete(void* p, unsigned int size) {
        Heap* heap = static_cast<Heap*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(p, size, size);
    }
    __forceinline void RemoveReference() {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0) delete this;
        }
    }
};

struct FUN_00979fb0 : RefObject {
    char pad[0x2c - 8];
    FUN_00979fb0(int a, int b, int c, int d);
};

struct Source {
    void* vtbl;
    int f04, f08, f0c, f10;
    int A() const { return f04; } int B() const { return f08; } int C() const { return f0c; } int D() const { return f10; }
};

struct Owner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void SetShape(RefObject* shape);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8();
    virtual void SetSource(void* source);
    void FUN_008fc4a0(void* source);
};

// pdb: bhkConstraint::Init | bhkConstraint.obj | fnv360_0721_beta, objrun_prop, medium
// pdb params: arInfo
void Owner::FUN_008fc4a0(void* source)
{
    if (source) {
        Source* s = (Source*)((char*)source - 4);
        if (s) {
            FUN_00979fb0* shape = new FUN_00979fb0(s->C(), s->D(), s->f04, s->f08);
            SetShape(shape);
            shape->RemoveReference();
            SetSource(source);
        }
    }
}
}
}   // namespace f3m_008fc4a0

// @f3 0x008ea810 (community match, verified in this file)
namespace f3m_008ea810 {
namespace w8ea810 {
struct Info { int unk00, unk04, unk08, unk0C; unsigned int info10; };
struct ShapeData { int unk00, unk04; Info* info08; };
struct Body {
    ShapeData* shape00;
    int unk04;
    int unk08;
    Body* parent0C;
    signed char ownerOffset10;
    char pad11[7];
    unsigned char type18;
    char pad19[3];
    unsigned int filter1C;
    const Body* GetRoot() const { const Body* b = this; while (b->parent0C) b = b->parent0C; return b; }
};
struct Material {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual unsigned int GetInfo(int key);
};
Material* FUN_008f1b30(const Body* body);
inline void SetFlag(unsigned int& flags, unsigned int mask, bool set) { if (set) flags |= mask; else flags &= ~mask; }
struct Contact { char pad[0x28]; const Body* body28; int key2C; };
struct Controller {
    char pad[0x294];
    unsigned int flags294;
    char pad298[0x2b4 - 0x298];
    int material2B4;
    int layer2B8;
    int unk2BC;
    Vec4_8fea20 surface2C0;
    void FUN_008ea810(Contact* c);
};

// pdb: bhkCharacterController::SetSupportMaterial | bhkCharacterController.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: bhkCharProxyController::~bhkCharProxyController)
// pdb params: arManifold
void Controller::FUN_008ea810(Contact* c)
{
    if (material2B4 == 15)
        return;
    int mat = 32;
    const Body* body = c->body28;
    if (!body)
        return;
    int layer = body->GetRoot()->filter1C & 0x7f;
    layer2B8 = layer;
    const Body* root = body->GetRoot();
    const char* owner = root->type18 == 1 ? (const char*)root + root->ownerOffset10 : 0;
    const Vec4_8fea20* src = owner ? (const Vec4_8fea20*)(owner + 0x1a0) : &DAT_01092a50;
    surface2C0.x = src->x;
    surface2C0.y = src->y;
    surface2C0.z = src->z;
    surface2C0.w = src->w;
    bool flagB = false;
    bool flagA = false;
    if (c->key2C == -1) {
        ShapeData* shape = body->shape00;
        if (shape && shape->info08) {
            unsigned int info = shape->info08->info10;
            mat = (int)(info & 0x1f) < 0x1f ? (info & 0x1f) : 0x1f;
            flagB = (info >> 6) & 1;
            flagA = (info >> 5) & 1;
        }
    } else if (layer != 0x11) {
        Material* m = FUN_008f1b30(body);
        if (m) {
            unsigned int info = m->GetInfo(c->key2C);
            mat = (int)info < 0x1f ? info : 0x1f;
            flagB = (info >> 6) & 1;
            flagA = (info >> 5) & 1;
        }
    }
    if (material2B4 == 32 || mat == 15) {
        material2B4 = mat;
        SetFlag(flags294, 1 << 23, flagA);
        SetFlag(flags294, 1 << 24, flagB);
        if ((flags294 >> 16) & 1 || mat == 15)
            SetFlag(flags294, 1 << 17, material2B4 == 15);
    }
}
}
}   // namespace f3m_008ea810

// @f3 0x008f7a20 (community match, verified in this file)
extern const char* DAT_010f317c;
extern const char* DAT_00f79fb0[];
namespace f3m_008f7a20 {
namespace w8f7a20 {
struct StrArr {
    int unk00;
    int unk04;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_00555790(unsigned int newCapacity);
    void FUN_005b3880(unsigned int index, char** item);
    void Add(char* item)
    {
        unsigned int n = size;
        if (n >= capacity)
            FUN_00555790(growBy + n);
        FUN_005b3880(n, &item);
    }
};
char* __cdecl FUN_00847b50(const char* name);
char* __cdecl FUN_00847e70(const char* label, const char* value);
struct B1 { bool v; };
char* __cdecl FUN_00847b90(const char* label, B1 value);

struct FUN_008f7a20_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int flags;
    void FUN_008f80d0(StrArr* out);
    void FUN_008f7a20(StrArr* out);
};

// pdb: bhkShape::GetViewerStrings | bhkShape.obj | fnv360_0822_retail, call_gap, low
// pdb params: apStrings
void FUN_008f7a20_cls::FUN_008f7a20(StrArr* out)
{
    FUN_008f80d0(out); const char* material;
    out->Add(FUN_00847b50(DAT_010f317c));
    out->Add(FUN_00847e70("MATERIAL", material = DAT_00f79fb0[flags & 0x1f]));
    B1 b6; b6.v = (flags >> 6) & 1; out->Add(FUN_00847b90("-STAIRS", b6));
    B1 b5; b5.v = (flags >> 5) & 1; out->Add(FUN_00847b90("-PLATFORM", b5));
}
}
}   // namespace f3m_008f7a20

// @f3 0x008fdff0 (community match, verified in this file)
struct __declspec(align(16)) Block37 { float m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33; void FUN_008fda60(const Block37*); };
struct Out37 { int unk00,value04,unk08,unk0c; Block37 block; };
struct Inner37 { int unk00,unk04,unk08,unk0c,unk10,value14,unk18,unk1c,unk20,unk24,unk28,unk2c; Block37 block; };
extern Block37 DAT_010f3370;
struct Owner37 { int unk00,unk04; Inner37* inner; void FUN_008f75b0(Out37*); void FUN_008fdff0(Out37*); };
// pdb: bhkTransformShape::CopyCinfo | bhkTransformShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
void Owner37::FUN_008fdff0(Out37* output) {
    FUN_008f75b0(output);
    output->value04=(this && inner) ? inner->value14 : 0;
    Block37* source;
    if(this) {
        Inner37* p=inner;
        source=(Block37*)((char*)p+0x30);
        if(!p) source=&DAT_010f3370;
    } else source=&DAT_010f3370;
    Block37 local;
    local.FUN_008fda60(source);
    output->block.FUN_008fda60(&local);
}

// @f3 0x008e9280 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();

namespace f3m_008e9280 {

extern const double DAT_00dbe7c0;

struct Vector3 {
    float x, y, z;
};

struct __declspec(align(16)) Vector4 {
    float x, y, z, w;

    __forceinline Vector4(const Vector3& input)
    {
        x = static_cast<float>(input.x * DAT_00dbe7c0);
        y = static_cast<float>(input.y * DAT_00dbe7c0);
        z = static_cast<float>(input.z * DAT_00dbe7c0);
        // The legacy XYZ constructor leaves the fourth lane untouched.
    }

    __forceinline void Scale(const float& value)
    {
        float scale = value;
        _ReadWriteBarrier();
        x = scale * x;
        y *= scale;
        z *= scale;
        w *= scale;
    }

    __forceinline float LengthSquared() const
    {
        return x * x + y * y + z * z;
    }

    __forceinline void Copy(const Vector4& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
    }
};

class Owner {
public:
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
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    unsigned unk320;
    unsigned unk324;
    unsigned unk328;
    unsigned unk32c;
    unsigned unk330;
    unsigned unk334;
    unsigned unk338;
    unsigned unk33c;
    unsigned unk340;
    unsigned unk344;
    unsigned unk348;
    unsigned unk34c;
    unsigned unk350;
    unsigned unk354;
    unsigned unk358;
    unsigned unk35c;
    unsigned unk360;
    unsigned unk364;
    unsigned unk368;
    unsigned unk36c;
    unsigned unk370;
    unsigned unk374;
    unsigned unk378;
    unsigned unk37c;
    unsigned unk380;
    unsigned unk384;
    unsigned unk388;
    unsigned unk38c;
    unsigned unk390;
    unsigned unk394;
    unsigned unk398;
    unsigned unk39c;
    Vector4 maximum3a0;
    float time3b0;
    void FUN_008e9280(const Vector3& input, float time);
};

// pdb: bhkCharacterController::SetVelocityModifier | bhkCharacterController.obj | fnv360_0822_retail, call_gap, medium
// pdb params: arVelocity, afTime
void Owner::FUN_008e9280(const Vector3& input, float time)
{
    Vector4 velocity(input);
    velocity.Scale(1.0f / time);
    if (velocity.LengthSquared() > maximum3a0.LengthSquared()) {
        time3b0 = time;
        maximum3a0.Copy(velocity);
    }
}

}

// @f3 0x008f2010 (community match, verified in this file)
namespace f3m_008f2010 {

struct __declspec(align(16)) QVec4 {
    float x;
    float y;
    float z;
    float w;
};

extern QVec4 DAT_01092a50;

struct QBody {
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
    QVec4 unk1A0;
    QVec4 unk1B0;
};

static inline const QVec4& GetA(QBody* b) { return b ? b->unk1A0 : DAT_01092a50; }
static inline const QVec4& GetB(QBody* b) { return b ? b->unk1B0 : DAT_01092a50; }

struct QWrap {
    int unk00;
    int unk04;
    QBody* unk08;
    void FUN_004e6280(const QVec4& v);
    void FUN_004e62c0(const QVec4& v);
};

struct QHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    QWrap* unk10;
};

struct QNode;

struct QObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual QNode* GetAsNode();
};

struct QNode {
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
    QObj** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

QHolder* FUN_00424fe0(QObj* obj);

// pdb: bhkUtilFunctions::DampBodiesVelocity | bhkUtilFunctions.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject, afDamp
void FUN_008f2010(QObj* obj, float scale)
{
    if (!obj)
        return;
    QHolder* h = FUN_00424fe0(obj);
    QWrap* w;
    if (h && (w = h->unk10) != 0) {
        QVec4 a;
        QVec4 b;
        const QVec4& sa = GetA(w->unk08);
        a.x = sa.x;
        a.y = sa.y;
        a.z = sa.z;
        a.w = sa.w;
        const QVec4& sb = GetB(w->unk08);
        b.x = sb.x;
        b.y = sb.y;
        b.z = sb.z;
        b.w = sb.w;
        a.x *= scale;
        a.y *= scale;
        a.z *= scale;
        a.w *= scale;
        b.x *= scale;
        b.y *= scale;
        b.z *= scale;
        b.w *= scale;
        w->FUN_004e6280(a);
        w->FUN_004e62c0(b);
    }
    QNode* n = obj->GetAsNode();
    if (n) {
        for (unsigned int i = 0; i < n->unkA6; i++)
            FUN_008f2010(n->unkA0[i], scale);
    }
}

}

// @f3 0x008ea1f0 (community match, verified in this file)
struct f3Vec3 { float x, y, z; };
struct f3Mat3;

struct __declspec(align(16)) f3Vec4
{
    float x, y, z, w;
    void hkVector4_setRotatedDir(f3Mat3* mat, f3Vec3* point);
};

struct f3ObjA
{
    f3Vec4* FUN_0091dd60();
};

struct f3ObjQ
{
    int unk00;
    int unk04;
    char* unk08;
};

extern f3Vec4 g_f3UnknownVec4;

class f3Owner
{
public:
    int unk00;
    int unk04;
    f3ObjA* unk08;
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
    f3Vec3 unk400;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    f3ObjQ* unk424;

    void FUN_008ea1f0(f3Vec4* out);
};

// pdb: bhkCharacterController::GetPosition | MagicBoltProjectile.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arPos
void f3Owner::FUN_008ea1f0(f3Vec4* out)
{
    f3Vec4 local;
    char* holder = this->unk424 ? this->unk424->unk08 : 0;
    f3Mat3* mat = (f3Mat3*)(holder + 0xa0);
    local.hkVector4_setRotatedDir(mat, &this->unk400);
    f3Vec4* pos = this->unk08 ? this->unk08->FUN_0091dd60() : &g_f3UnknownVec4;
    out->x = pos->x - local.x;
    out->y = pos->y - local.y;
    out->z = pos->z - local.z;
    out->w = pos->w - local.w;
}

// @f3 0x008f15c0 (community match, verified in this file)
extern float DAT_010f2ed4;
extern float DAT_010f2ed8;
extern float DAT_00f79c90;
extern float DAT_00f79c94;
extern float DAT_00de707c;
extern double DAT_00e33850;
namespace f3m_008f15c0 {
namespace task1824 {
struct __declspec(align(16)) C74570_Vec {float x,y,z,w;};
struct C74570_Ctrl
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
    virtual void Apply(float t, void* data);
};
struct C74570_Obj
{
    void FUN_0090b500();
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
    C74570_Ctrl ctrl;
};
struct C74570_Item
{
    int unk00;
    int unk04;
    C74570_Obj* obj;
};
struct C74570_Node
{
    C74570_Item* item;
    C74570_Node* next;
};
struct C74570_Mat
{
    C74570_Vec r0;
    C74570_Vec r1;
    C74570_Vec r2;
    void FUN_00924c60(void* out, float angle);
};
struct C74570_Xf
{
    C74570_Vec a;
    void hkVector4_setRotatedDir(void* p, void* q);
};
struct C74570_This
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
    virtual float Eval(float t);
    int unk04;
    bool enabled;
    C74570_Node list;
    void FUN_008f15c0(float dt);
};

// @fnv 0x00c74570
// pdb: bhkWindListener::Update | bhkWindListener.obj | fnv360_0822_retail, objrun, medium
// pdb params: afTime
void C74570_This::FUN_008f15c0(float dt)
{
    if (!enabled)
        return;
    if (DAT_010f2ed4 == 0.0f)
        return;
    C74570_Node* node = &list;
    C74570_Node*& n = node;
    float sign = (float)(1 - (int)(dt / DAT_00e33850));
    for (; n; n = n->next)
    {
        {
            if (!n->item)
                break;
            C74570_Obj* obj = n->item->obj;
            float a = Eval(DAT_010f2ed4) + DAT_010f2ed4 * 0.25;
            if (a < 0.0f)
                a = 0.0f;
            if (a > DAT_00f79c90)
                a = DAT_00f79c90;
            a *= sign;
            float b = Eval(DAT_00de707c);
            b = DAT_010f2ed8 + b;
            if (b > DAT_00f79c94)
                b -= DAT_00f79c94;
            else if (b < 0.0f)
                b += DAT_00f79c94;
            C74570_Vec v0;
            C74570_Xf xf;
            C74570_Vec v1;
            v1.x=0.0f;v1.y=a;v1.z=0.0f;v1.w=0.0f;
            v0.x=0.0f;v0.y=0.0f;v0.z=1.0f;v0.w=0.0f;
            C74570_Mat m;
            m.FUN_00924c60(&v0, b);
            xf.hkVector4_setRotatedDir(&m, &v1);
            if (obj)
            {
                obj->FUN_0090b500();
                obj->ctrl.Apply(dt, &xf);
            }
        }
    }
}


}
}   // namespace f3m_008f15c0

// @f3 0x008e9fc0 (community match, verified in this file)
namespace f3m_008e9fc0 {

struct Vec {
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

struct Source {
    int pad[52];
    float x;
    float y;
    float z;
};

struct Handle {
    int pad0;
    int pad1;
    Source* source;
};

struct Target {
    void FUN_0091a630(Vec*, int);
};

struct ThisClass {
    char pad[0x424];
    Handle* handle;
    Target* target;
    void __thiscall FUN_008e9fc0(int index, float f);
};

void __thiscall ThisClass::FUN_008e9fc0(int index, float f) {
    if (target) {
        Source* src = handle ? handle->source : 0;
        Vec v;
        v.x = src->x;
        v.y = src->y;
        v.z = src->z;
        v.w = f;
        target->FUN_0091a630(&v, index);
    }
}
}   // namespace f3m_008e9fc0

// @f3 0x008ef910 (community match, verified in this file)
extern float DAT_0104da48;
extern const float DAT_0104da4c;
namespace f3m_008ef910 {

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) : m_bool(static_cast<char>(b)) {}
    __forceinline operator bool() const { return m_bool != 0; }
private:
    char m_bool;
};

__declspec(align(16)) struct hkVector4
{
    float x;
    float y;
    float z;
    float w;

    __forceinline hkVector4() {}
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, float r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
};

__declspec(align(16)) struct hkpRootCdPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
    const void* m_rootCollidableA;
    unsigned int m_shapeKeyA;
    unsigned int m_shapeKeyA0;
    unsigned int m_shapeKeyA1;
    const void* m_rootCollidableB;
    unsigned int m_shapeKeyB;
    unsigned int m_shapeKeyB0;
    unsigned int m_shapeKeyB1;
};

template <typename T>
class hkArrayBase
{
public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000)
    };

    __forceinline hkArrayBase(T* ptr, int size, int capacity)
        : m_data(ptr), m_size(size), m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
    {
    }

    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline int getSize() const { return m_size; }
    __forceinline void clear() { m_size = 0; }

protected:
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
class hkArray : public hkArrayBase<T>
{
public:
    __forceinline hkArray(T* buffer, int size, int capacity)
        : hkArrayBase<T>(buffer, size, capacity)
    {
    }
};

template <typename T, unsigned int N>
class hkInplaceArray : public hkArray<T>
{
public:
    __forceinline hkInplaceArray(int size = 0)
        : hkArray<T>(&m_storage0, size, N)
    {
    }

    T m_storage0;
    T m_storage1;
    T m_storage2;
    T m_storage3;
    T m_storage4;
    T m_storage5;
    T m_storage6;
    T m_storage7;
};

class hkpCdPointCollector
{
public:
    __forceinline hkpCdPointCollector() { reset(); }
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const void* point) = 0;
    virtual inline void reset() { m_earlyOutDistance = DAT_0104da48; }

protected:
    float m_earlyOutDistance;
};

class SortableArray : public hkpCdPointCollector
{
public:
    __forceinline void reset()
    {
        m_hits.clear();
        hkpCdPointCollector::reset();
    }
    __forceinline SortableArray()
    {
        reset();
    }
    virtual ~SortableArray();
    virtual void addCdPoint(const void* point);

    __forceinline const hkArray<hkpRootCdPoint>& getHits() const { return m_hits; }
    __forceinline hkArray<hkpRootCdPoint>& getHits() { return m_hits; }
    __forceinline hkBool hasHit() const { return m_hits.getSize() > 0; }
    void hkpAllCdPointCollector_sortHits();

protected:
    hkInplaceArray<hkpRootCdPoint, 8> m_hits;
};

struct hkpLinearCastInput
{
    hkVector4 m_to;
    float m_maxExtraPenetration;
    float m_startPointTolerance;

    __forceinline hkpLinearCastInput()
        : m_maxExtraPenetration(DAT_0104da4c), m_startPointTolerance(DAT_0104da4c)
    {
    }
};

struct bhkShapePhantom
{
    void FUN_00568600(const hkVector4& kStart, const hkpLinearCastInput& lcInput, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

class hkpCharacterProxyListener
{
public:
    virtual ~hkpCharacterProxyListener();
    virtual void processConstraintsCallback();
    virtual void contactPointAddedCallback(const hkpRootCdPoint& point);
};

class bhkCharacterListener : public hkpCharacterProxyListener
{
public:
    unsigned int iFlags;
    int unk08;
    int unk0c;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;
    hkVector4 unk60;

    __forceinline unsigned int GetFlag(unsigned int a_uiFlag) const
    {
        return iFlags & a_uiFlag;
    }
};

struct Block80
{
    hkVector4 v0;
    hkVector4 v1;
    hkVector4 v2;
    hkVector4 v3;
    hkVector4 v4;
    hkVector4 v5;
    hkVector4 v6;
    hkVector4 v7;
};

class bhkCharacterController_StandIn
{
public:
    Block80 unk000;
    Block80 unk080;
    Block80 unk100;
    Block80 unk180;
    Block80 unk200;
    hkVector4 unk280;
    bhkCharacterListener listener;
    Block80 unk300;
    hkVector4 unk380;
    hkVector4 OutVelocity;
    Block80 unk3a0;
    int unk420;
    NiPointer<bhkShapePhantom> spShapePhantom;

    __forceinline bool QProjectile() const
    {
        return listener.GetFlag(0x80000) != 0;
    }

    __declspec(noalias) void FUN_008ea1f0(hkVector4& a_kPos);
    __declspec(noalias) void bhkCharacterController_SetPosition(const hkVector4& a_kPos);
    void FUN_008ef910(float a_fTime);
};

// pdb: bhkCharacterController::MoveAsProjectile | bhkCharacterController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: afTimeDelta
void bhkCharacterController_StandIn::FUN_008ef910(float a_fTime)
{
    if (QProjectile() && spShapePhantom)
    {
        SortableArray collector;
        hkpLinearCastInput lcInput;
        hkVector4 kStart;
        FUN_008ea1f0(kStart);
        lcInput.m_to.setAddMul4(kStart, OutVelocity, a_fTime);
        spShapePhantom->FUN_00568600(kStart, lcInput, collector, 0);
        if (collector.hasHit())
        {
            collector.hkpAllCdPointCollector_sortHits();
            for (int i = 0; i < collector.getHits().getSize(); ++i)
            {
                listener.contactPointAddedCallback(collector.getHits()[i]);
            }
        }
        bhkCharacterController_SetPosition(lcInput.m_to);
    }
    else
    {
        hkVector4 kStart;
        FUN_008ea1f0(kStart);
        hkVector4 kEnd;
        kEnd.setAddMul4(kStart, OutVelocity, a_fTime);
        bhkCharacterController_SetPosition(kEnd);
    }
}
}   // namespace f3m_008ef910

// @f3 0x008f1290 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern float DAT_00f79adc;
namespace f3m_008f1290 {
namespace Controller2048 {
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    Vector4(){}
    Vector4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
    Vector4& operator=(const Vector4& v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
    static Vector4 Up(){Vector4 v;v.x=0;v.y=0;v.z=1;v.w=0;return v;}
    void SetZero(){x=y=z=w=0.0f;}
};
struct Proxy {
    Proxy();virtual ~Proxy();
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
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
};
struct Manager;
struct Context {
    Context(int,Manager*);virtual ~Context();
    unsigned short memorySize,refs;
    unsigned int unk08;Manager* manager;int state,previous;
    unsigned char flag,unk19,unk1A,unk1B;
    float unk1C,unk20,unk24;
};
struct ListenerInterface {virtual ~ListenerInterface();};
struct Listener:ListenerInterface {
    Listener(const Vector4&,float,float);virtual ~Listener();
    unsigned int unk04,unk08,unk0C;
    Vector4 up;
    float angle;unsigned int unk24,unk28,unk2C;
    Vector4 unk30,velocity,unk50;
    float mass,unk64;unsigned char flag68,flag69,unk6A,unk6B;
    unsigned int unk6C;
};
struct SurfaceInfo {
    int state;unsigned int unk04,unk08,unk0C;
    Vector4 normal,velocity;
    float value;unsigned int flags,unk38,unk3C;
    SurfaceInfo():state(2),normal(0,0,1,0),velocity(0,0,0,0),value(0),flags(7){}
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObject {virtual ~RefObject();virtual void Destroy();long refs;
    void IncRefCount(){InterlockedIncrement(&refs);}
    void DecRefCount(){if(InterlockedDecrement(&refs)==0)Destroy();}
};
struct Memory {void* FUN_008f6d30(int,int);};
extern Memory* (__stdcall* DAT_00d9b080)(unsigned long);
struct Frame {Vector4 a,b,c,d;};
inline void* AllocateFrames(unsigned int bytes){Memory* allocator=DAT_00d9b080(DAT_010f3170);return allocator->FUN_008f6d30(bytes,0x17);}
struct Buffer {
    Frame* data;unsigned int count,capacity;
    Buffer(unsigned int n):data((Frame*)AllocateFrames(n*sizeof(Frame))),count(n),capacity(n){}
    ~Buffer(){FUN_00568800();}
    void FUN_00568800();
};
struct List8 {
    void* value;List8* next;
    List8():value(0),next(0){}
    ~List8(){FUN_004d2c90();}
    void FUN_004d2c90();
};
struct Info {
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
    Manager* manager;
    unsigned int unkA0;int state;float factorA8,factorAC;
    float Product()const{float result=factorAC*factorA8;return result;}
};
struct Controller:Proxy,Context,Listener,SurfaceInfo {
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    Vector4 direction360,direction370;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    Vector4 vector3A0;
    float unk3B0;
    float unk3B4;
    float unk3B8;
    float unk3BC;
    float unk3C0;
    float unk3C4;
    float unk3C8;
    float unk3CC;
    float unk3D0;
    float unk3D4;
    float unk3D8;
    float unk3DC;
    float unk3E0;
    float unk3E4;
    float unk3E8;
    float unk3EC;
    float unk3F0;
    float unk3F4;
    float unk3F8;
    float unk3FC;
    Vector4 vector400;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    NiPointer<RefObject> ref424,ref428,ref42C;
    int mode430,mode434;
    NiPointer<RefObject> refs438[2];
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    float value480,value484,value488,value48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned char flag4A0,unk4A1,unk4A2,unk4A3;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    Vector4 vector4B0;
    unsigned int unk4C0;float value4C4;unsigned int unk4C8;
    Buffer buffer;
    List8 list;
    Controller(const Info*);
    virtual ~Controller();
    void bhkCharacterController_Init(const Info*);
};
typedef char SizeController[(sizeof(Controller)==0x4e0)?1:-1];
// pdb: bhkCharacterController::bhkCharacterController | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
Controller::Controller(const Info* info):Context(info->state,info->manager),Listener(Vector4::Up(),(float)(DAT_00f79adc*0.01745329238474369),info->Product()),buffer(5) {
    unk490=0;
    value480=2;
    Listener::unk04=0;
    value488=2;
    value484=10;
    unk3D0=0;unk3D4=0;unk3B0=0;unk3DC=0;unk3E0=0;unk3E4=1;
    unk3BC=0;unk3B4=0;unk3B8=0;value48C=-1;unk3C0=0;unk3C4=0;unk3D8=1;
    vector400.SetZero();vector3A0.SetZero();
    direction360=Vector4(0,0,1,0);
    direction370=Vector4(1,0,0,0);
    unk350=0;value4C4=0;mode430=2;mode434=2;
    unk494=0;unk498=0;unk49C=0;unk4C0=0;unk4C8=0;
    Listener::velocity.SetZero();buffer.count=0;flag4A0=0;vector4B0.SetZero();
    bhkCharacterController_Init(info);
}
}
}   // namespace f3m_008f1290

// @f3 0x008e9380 (community match, verified in this file)
namespace f3m_008e9380 {
struct __declspec(align(16)) Q4 { float x, y, z, w; };
extern float DAT_01092a50;
extern float DAT_01092a54;
extern float DAT_01092a58;
extern float DAT_01092a5c;

struct FUN_008e9380_cls {
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C;
    int unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C;
    int unk280, unk284, unk288, unk28C, unk290;
    int unk294;
    int unk298, unk29C, unk2A0, unk2A4, unk2A8, unk2AC;
    int unk2B0, unk2B4, unk2B8, unk2BC, unk2C0, unk2C4, unk2C8, unk2CC;
    int unk2D0, unk2D4, unk2D8, unk2DC, unk2E0, unk2E4, unk2E8, unk2EC;
    int unk2F0, unk2F4, unk2F8, unk2FC, unk300, unk304, unk308, unk30C;
    int unk310, unk314, unk318, unk31C, unk320, unk324, unk328, unk32C;
    int unk330, unk334, unk338, unk33C, unk340, unk344, unk348, unk34C;
    int unk350, unk354, unk358, unk35C, unk360, unk364, unk368, unk36C;
    int unk370, unk374, unk378, unk37C, unk380, unk384, unk388, unk38C;
    float unk390, unk394, unk398, unk39C;
    float unk3A0, unk3A4, unk3A8, unk3AC;
    float unk3B0;

    void FUN_008e9380();
};

// pdb: bhkCharacterController::ApplyVelocityMod | bhkCharacterController.obj | fnv360_0721_beta, objrun_prop, low
void FUN_008e9380_cls::FUN_008e9380()
{
    if (unk3B0 > 0.0f) {
        float delta = unk3B0;
        Q4 q;
        q.x = unk3A0 * delta;
        q.y = unk3A4 * delta;
        q.z = unk3A8 * delta;
        q.w = delta * unk3AC;
        if ((unk294 & 0x1800) == 0) {
            unk390 = unk390 + q.x;
            unk394 = unk394 + q.y;
            unk398 = q.z + unk398;
            unk39C = unk39C + q.w;
        }
    } else {
        unk3A0 = DAT_01092a50;
        unk3A4 = DAT_01092a54;
        unk3A8 = DAT_01092a58;
        unk3AC = DAT_01092a5c;
    }
}
}   // namespace f3m_008e9380

// @f3 0x008f92e0 (community match, verified in this file)
extern void* DAT_010f31c8;
extern const char DAT_00e34358[], DAT_00e3434c[], DAT_00e3433c[], DAT_00e34330[];
namespace f3m_008f92e0 {
namespace Stats550
{
void* __cdecl FUN_00847b50(void*);
void* __cdecl FUN_00847dd0(const char*, float);
struct Output
{
    char pad[8];
    unsigned short capacity, count, pad0c, growth;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, void**);
    __forceinline void Add(void* object)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_00555790(index + growth);
        FUN_005b3880(index, &object);
    }
};
struct __declspec(align(16)) Snapshot
{
    unsigned int pad00, pad04, pad08, pad0c;
    unsigned int pad10, pad14, pad18, pad1c;
    unsigned int pad20, pad24, pad28, pad2c;
    float first, second, third, fourth;
    void FUN_00477a90();
};
struct Owner
{
    void FUN_008f8bb0(Output*);
    void FUN_008f8cf0(Snapshot*);
    void FUN_008f92e0(Output*);
};
// pdb: bhkMouseSpringAction::GetViewerStrings | bhkMouseSpringAction.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Owner::FUN_008f92e0(Output* output)
{
    FUN_008f8bb0(output);
    output->Add(FUN_00847b50(DAT_010f31c8));
    Snapshot snapshot;
    snapshot.FUN_00477a90();
    FUN_008f8cf0(&snapshot);
    output->Add(FUN_00847dd0(DAT_00e34358, snapshot.first));
    output->Add(FUN_00847dd0(DAT_00e3434c, snapshot.second));
    output->Add(FUN_00847dd0(DAT_00e3433c, snapshot.fourth));
    output->Add(FUN_00847dd0(DAT_00e34330, snapshot.third));
}
}

}   // namespace f3m_008f92e0

// @f3 0x008ea4f0 (community match, verified in this file)
namespace f3m_008ea4f0 {
// bhkPickData ray query (FNV S00c6e680 twin): the ray input, its output, the filter info and the closest-hit collector.
struct Vec4
{
    float x, y, z, w;
    // Member-wise copy; z is read through a volatile view so the value just stored is reloaded, as in the original.
    __forceinline Vec4& operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = *(volatile const float*)&v.z;
        w = v.w;
        return *this;
    }
};

extern float DAT_01092a50;
extern float DAT_01092a54;
extern float DAT_01092a58;
extern float DAT_01092a5c;

struct __declspec(align(16)) PickData
{
    Vec4 from;                 // +00
    Vec4 to;                   // +10
    char enableShapeFilter;    // +20
    unsigned int filterInfo;   // +24
    unsigned int unk28;
    unsigned int unk2C;
    float normalX;             // +30
    float normalY;
    float normalZ;
    float normalW;
    float hitFraction;         // +40
    int extraInfo;             // +44
    int unk48;
    int unk4C;
    unsigned int shapeKey0;    // +50
    unsigned int shapeKey1;
    unsigned int shapeKey2;
    unsigned int shapeKey3;
    unsigned int shapeKey4;
    unsigned int shapeKey5;
    unsigned int shapeKey6;
    unsigned int shapeKey7;
    void* rootCollidable;      // +70
    int unk74;
    int unk78;
    int unk7C;
    void* unk80;               // +80
    int unk84;
    int unk88;
    int unk8C;
    float unk90x;              // +90
    float unk90y;
    float unk90z;
    float unk90w;
    unsigned int unkA0;        // +A0
    void* collectorPointer;    // +A4
    unsigned int unkA8;        // +A8
    float unkAC;
    PickData();
};

struct RayHitCollector
{
    virtual ~RayHitCollector();
    float earlyOutHitFraction;   // +04
    __forceinline RayHitCollector() {}
};

RayHitCollector::~RayHitCollector() {}

struct ClosestRayHitCollector : RayHitCollector
{
    __forceinline ~ClosestRayHitCollector() {}
    int unk08;
    int unk0C;
    int normalX;                 // +10
    int normalY;
    int normalZ;
    int normalW;
    float hitFraction;           // +20
    int extraInfo;               // +24
    int unk28;
    int unk2C;
    int shapeKey0;               // +30
    int shapeKey1;
    int shapeKey2;
    int shapeKey3;
    int shapeKey4;
    int shapeKey5;
    int shapeKey6;
    int shapeKey7;
    int rootCollidable;          // +50
    int unk54;
    int unk58;
    int unk5C;
    int unk60;                   // +60
    int unk64;
    int unk68;
    int unk6C;
    __forceinline ClosestRayHitCollector()
    {
        hitFraction = 1.0f;
        earlyOutHitFraction = 1.0f;
        unk60 = 0;
        extraInfo = -1;
        rootCollidable = 0;
        shapeKey0 = -1;
    }
};

struct bhkWorld
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
    virtual void Lock();                 // +98
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
    virtual char Pick(PickData* pick);   // +C8
};

struct WorldObject
{
    __forceinline bhkWorld* GetWorld() { return *(bhkWorld**)((char*)this + 0x310); }
};

struct HolderResult
{
    unsigned int unk00;
    unsigned int unk04;
    WorldObject* object;
};

struct Holder
{
    HolderResult* hkpCharacterProxy_getShapePhantom();
};

struct PickOwner
{
    unsigned int unk00;
    unsigned int unk04;
    Holder* holder;
    void GetFilterInfo(float* filter);
    char FUN_008ea4f0(int index, Vec4* position);
};

// pdb: bhkCharacterController::FindSupportPoint | bhkCharacterController.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aiFrontBack, arPos
char PickOwner::FUN_008ea4f0(int index, Vec4* position)
{
    PickData pick;
    ClosestRayHitCollector collector;
    pick.collectorPointer = &collector;

    Vec4* source = ((Vec4*)this) + index + 0x44;
    position->x = source->x;
    position->y = source->y;
    position->z = source->z;
    float value = source->w;
    position->w = value;
    pick.unkA8 = 0;
    pick.from.x = position->x;
    pick.from.y = position->y;
    pick.from.z = position->z;
    pick.from.w = value;

    position->z = position->z - 25.0;
    pick.unk90x = DAT_01092a50;
    pick.unk90y = DAT_01092a54;
    pick.unk90z = DAT_01092a58;
    pick.unk90w = DAT_01092a5c;
    pick.to = *position;

    GetFilterInfo(&value);
    *(int*)&pick.filterInfo = *(int*)&value;

    HolderResult* result = this && holder ? holder->hkpCharacterProxy_getShapePhantom() : 0;
    WorldObject* object = result->object;
    bhkWorld* world = object ? object->GetWorld() : 0;
    if (world)
        world->Lock();
    char hit = world->Pick(&pick);
    world->Lock();
    if (hit)
    {
        float fraction = 1.0f - collector.hitFraction;
        position->z = fraction * 25.0 + position->z;
    }
    return hit;
}
}   // namespace f3m_008ea4f0

// @f3 0x008ea020 (community match, verified in this file)
namespace f3m_008ea020 {

struct Type {
    const char* name;
    const Type* parent;
};

extern const Type DAT_010f3350;
extern const float DAT_010c72bc;

struct __declspec(align(16)) hkVector4 {
    float x;
    float y;
    float z;
    float w;

    void set(const hkVector4& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
};

extern const hkVector4 DAT_01092a50;

struct hkpCapsuleShape {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_radius; // +0x10
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_vertexA; // +0x20
    hkVector4 m_vertexB; // +0x30
};

struct bhkCapsuleShape {
    virtual void* vtbl00();
    virtual void* vtbl04();
    virtual const Type* GetRTTI(); // +0x08
    int unk04;
    hkpCapsuleShape* m_pShape; // +0x08
};

__forceinline bool IsKindOf(const Type* actual, const Type* desired)
{
    if (actual) {
        do {
            if (actual == desired)
                return true;
            actual = actual->parent;
        } while (actual);
    }
    return false;
}

template<class T>
__forceinline T* Cast(bhkCapsuleShape* object, const Type* desired)
{
    if (!object)
        return 0;
    const bool matches = IsKindOf(object->GetRTTI(), desired);
    return matches ? static_cast<T*>(object) : 0;
}

class StandinClass {
public:
    char pad438[0x438];
    bhkCapsuleShape* m_spShape;

    void FUN_008ea020(float fRadius);
};

// pdb: bhkCharacterController::SetRadius | bhkCharacterController.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: afRadius
void StandinClass::FUN_008ea020(float fRadius)
{
    bhkCapsuleShape* shape = m_spShape;
    if (!shape)
        return;

    bhkCapsuleShape* capsule = Cast<bhkCapsuleShape>(shape, &DAT_010f3350);
    if (!capsule)
        return;

    hkpCapsuleShape* sub = capsule->m_pShape;

    float oldRadius = sub ? sub->m_radius : DAT_010c72bc;
    float delta = oldRadius - fRadius;

    const hkVector4& vA = sub ? sub->m_vertexA : DAT_01092a50;
    hkVector4 local_vA;
    local_vA.set(vA);

    const hkVector4& vB = sub ? sub->m_vertexB : DAT_01092a50;
    hkVector4 local_vB;
    local_vB.set(vB);

    local_vA.z += delta;
    local_vB.z -= delta;

    if (sub) {
        sub->m_vertexA.set(local_vA);
        sub->m_vertexA.w = sub->m_radius;
        sub->m_vertexB.set(local_vB);
        sub->m_vertexB.w = sub->m_radius;
        sub->m_radius = fRadius;
    }
}
}   // namespace f3m_008ea020

// @f3 0x008ea300 (community match, verified in this file)
#include <math.h>
namespace f3m_008ea300 {
struct __declspec(align(16)) Vec { float x,y,z,w; void init(); };
struct __declspec(align(16)) RotMatrix { float a,b,c,d,e,f,g,h,i,j,k,l; };
struct __declspec(align(16)) Matrix { float a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p; void load(void*); void apply(Vec*); void FUN_0090dd40(Matrix*); void multiply(RotMatrix*); };
struct Frame { Vec scratch; Matrix m; };
struct Node { int unk00, unk04; Matrix* transform; void FUN_00c24b70(); };
struct Owner {
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
 unsigned flags;
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
 int unk350;
 int unk354;
 int unk358;
 int unk35c;
 int unk360;
 int unk364;
 int unk368;
 int unk36c;
 int unk370;
 int unk374;
 int unk378;
 int unk37c;
 int unk380;
 int unk384;
 int unk388;
 int unk38c;
 int unk390;
 int unk394;
 int unk398;
 int unk39c;
 int unk3a0;
 int unk3a4;
 int unk3a8;
 int unk3ac;
 int unk3b0;
 int unk3b4;
 int unk3b8;
 int unk3bc;
 int unk3c0;
 int unk3c4;
 int unk3c8;
 int unk3cc;
 int unk3d0;
 int unk3d4;
 int unk3d8;
 float angleX;
 float angleY;
 int unk3e4;
 int unk3e8;
 int unk3ec;
 int unk3f0;
 int unk3f4;
 int unk3f8;
 int unk3fc;
 int unk400;
 int unk404;
 int unk408;
 int unk40c;
 int unk410;
 int unk414;
 int unk418;
 int unk41c;
 int unk420;
 Node* node;
 __forceinline bool flagX() const { return (flags >> 25) & 1; }
 __forceinline bool flagY() const { return (flags >> 26) & 1; }
 void FUN_008ea300(Vec*);
};
extern void lock_node(Node*);
// pdb: bhkCharacterController::ApplyPitchAndRoll | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
// pdb params: arRot
void Owner::FUN_008ea300(Vec* v) {
 Vec copy; copy.x=v->x; copy.y=v->y; copy.z=v->z; copy.w=v->w;
 copy.init();
 Node* n = node;
 Frame frame;
 frame.m.load((char*)(n ? n->transform : 0) + 0xa0);
 frame.m.apply(&copy);
 if (angleX != 0.0f && flagX()) {
  float c = cosf(angleX), s = sinf(angleX);
  frame.scratch.z = -s;
  RotMatrix r = {1,0,0,0, 0,c,frame.scratch.z,0, 0,s,c,0};
  frame.m.multiply(&r);
 }
 if (angleY != 0.0f && flagY()) {
  float c = cosf(angleY), s = sinf(angleY);
  frame.scratch.x = -s;
  RotMatrix r = {c,0,s,0, 0,1,0,0, frame.scratch.x,0,c,0};
  frame.m.multiply(&r);
 }
 if (n && n->transform) { Matrix* t = n->transform; n->FUN_00c24b70(); t->FUN_0090dd40(&frame.m); n->FUN_00c24b70(); }
}

}   // namespace f3m_008ea300

// @f3 0x008f96c0 (community match, verified in this file)
extern long (__stdcall *const DAT_00d9b06c)(volatile long*,long,long);
namespace codex_8f96c0 {
struct __declspec(align(16)) Vec4 { float x,y,z,w; };
struct Bounds { Vec4 low,high; };
struct Pose { float m00,m04,m08,m0c,m10,m14,m18,m1c,m20; float x,y,z,scale; };
struct Source { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64; Pose pose; void FUN_008330a0(); };
struct BoundsTarget {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void NiGeometryData_GetNormalsIterator(Bounds*);
 void hkpAabbPhantom_setAabb(Bounds*);
};
struct Node { int unk00,unk04; BoundsTarget* target; void FUN_00c24b70(); };
struct Lock { volatile long owner; long count; void FUN_00409a80(int); };
extern Lock DAT_010f2c40;
extern const double DAT_00dbe7c0;
struct Owner { int unk00,unk04; Source* source; int unk0c; Node* node; void FUN_008f96c0(); };
void Owner::FUN_008f96c0() {
 Source* src=source; Node* n=node;
 if(!src) return;
 src->FUN_008330a0();
 if(!n) return;
 BoundsTarget* initial=n->target;
 if(!initial) return;
 Pose pose=src->pose;
 Bounds b;
 initial->NiGeometryData_GetNormalsIterator(&b);
 b.high.x-=b.low.x; b.high.y-=b.low.y; b.high.z-=b.low.z; b.high.w-=b.low.w;
 b.high.x*=0.5; b.high.y*=0.5; b.high.z*=0.5; b.high.w*=0.5;
 b.low.x=b.high.x * -1.0; b.low.y=b.high.y * -1.0; b.low.z=b.high.z * -1.0; b.low.w=b.high.w * -1.0;
 // The target reads the fourth component without an observable initialization.
 Vec4 position; position.x=pose.x*DAT_00dbe7c0; position.y=pose.y*DAT_00dbe7c0; position.z=pose.z*DAT_00dbe7c0;
 b.low.x+=position.x; b.low.y+=position.y; b.low.z+=position.z; b.low.w+=position.w;
 b.high.x+=position.x; b.high.y+=position.y; b.high.z+=position.z; b.high.w+=position.w;
 DAT_010f2c40.FUN_00409a80(0);
 BoundsTarget* t=n->target;
 if(t) { n->FUN_00c24b70(); t->hkpAabbPhantom_setAabb(&b); n->FUN_00c24b70(); }
 if(--DAT_010f2c40.count==0) { long old=DAT_010f2c40.owner; DAT_00d9b06c(&DAT_010f2c40.owner,0,old); }
}
}

// @f3 0x008fa550 (community match, verified in this file)
namespace f3m_008fa550 {

struct __declspec(align(16)) QMat4_8fa
{
    float m00, m01, m02, m03, m10, m11, m12, m13;
    float m20, m21, m22, m23, m30, m31, m32, m33;
};
struct QPt3_8fa
{
    float x, y, z;
};
struct QXform_8fa
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22;
    QPt3_8fa translate;
    float scale;
    QXform_8fa FUN_0056fe20(const QXform_8fa& other);
};
struct QQuat_8fa
{
    float w, x, y, z;
    void FUN_00837260(const QXform_8fa& t);
};
struct __declspec(align(16)) QVec4_8fa
{
    float x, y, z, w;
    void FUN_004e5c20();
};
struct QObj_8fa
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
    virtual void v55();
    virtual int SetTransform(QVec4_8fa* pos, QVec4_8fa* rot);
    virtual void v57();
    virtual void v58();
    virtual void GetWorld(QMat4_8fa* out);
    int unk04, unk08, unk0c, unk10, unk14;
    int unk18;
    void* unk1c;
void* GetKey() const {return unk1c;}
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94;
    float unk98;
};
struct QWrap_8fa
{
    int unk00, unk04;
    QObj_8fa* source;
    int unk0c;
    QObj_8fa* destination;
};
inline QObj_8fa* GetSource_8fa(QWrap_8fa* p) { return p ? p->source : 0; }
inline QObj_8fa* GetDest_8fa(QWrap_8fa* p) { return p ? p->destination : 0; }
struct QLock_8fa
{
    volatile long owner;
    int count;
    void FUN_00409a80(int a);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
extern QWrap_8fa* __cdecl FUN_008f1d20(QObj_8fa* a);
extern QWrap_8fa* __cdecl FUN_00424d50(void* table, void* key);
extern void __cdecl FUN_0056ad20(QXform_8fa* out, QMat4_8fa* in);
extern void __cdecl FUN_008fa4f0(QObj_8fa* source, QObj_8fa* a1, QXform_8fa* out);
extern void __cdecl FUN_00468f10(QVec4_8fa* out, QPt3_8fa* in);
extern char DAT_01092a48;
extern QLock_8fa DAT_010f2c40;

// pdb: WeaponObject::UpdateRigidBodyTransforms | WeaponObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apObject, apParent
void __cdecl FUN_008fa550(QObj_8fa* a0, QObj_8fa* a1)
{
    QWrap_8fa* p = a0 ? FUN_008f1d20(a0) : 0;
    QObj_8fa* source = GetSource_8fa(p);
    _ReadWriteBarrier();
    QObj_8fa* destination = GetDest_8fa(p);
    QWrap_8fa* cast = a1 ? FUN_00424d50(&DAT_01092a48, a1->GetKey()) : 0;
    QObj_8fa* body = GetDest_8fa(cast);
    if (destination && body && source && a1 && a1->unk18)
    {
        QMat4_8fa world;
        QXform_8fa converted;
        QXform_8fa relative;
        body->GetWorld(&world);
        FUN_0056ad20(&converted, &world);
        converted.scale = a1->unk98;
        FUN_008fa4f0(source, a1, &relative);
        QXform_8fa combined = converted.FUN_0056fe20(relative);
        QQuat_8fa q;
        q.FUN_00837260(combined);
        QVec4_8fa position;
        FUN_00468f10(&position, &combined.translate);
        QVec4_8fa rotation;
        rotation.x = q.x;
        rotation.y = q.y;
        rotation.z = q.z;
        rotation.w = q.w;
        rotation.FUN_004e5c20();
        DAT_010f2c40.FUN_00409a80(0);
        destination->SetTransform(&position, &rotation);
        if (--DAT_010f2c40.count == 0) {
            extern long (__stdcall *DAT_00d9b06c)(volatile long*, long, long);
            long owner = DAT_010f2c40.owner;
            DAT_00d9b06c(&DAT_010f2c40.owner, 0, owner);
        }
    }
}




}   // namespace f3m_008fa550

// @f3 0x008f9580 (community match, verified in this file)
namespace f3m_008f9580 {
namespace Bounds658 {
struct Vector { float x, y, z, w; };
struct __declspec(align(16)) Bounds { Vector low, high; };
struct Transform { float matrix[9]; float x, y, z, scale; };
struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void BoundsAt(Bounds*);
};
struct Holder { char pad[8]; Target* target; };
struct Owner {
    void** table;
    char pad[12];
    Holder* holder;
    void FUN_008f9580();
};
void Owner::FUN_008f9580() {
    if (!holder)
        return;
    Target* target = holder->target;
    if (!target)
        return;
    Bounds box;
    Transform transform;
    transform.matrix[0] = 1.0f;
    transform.matrix[1] = 0.0f;
    transform.matrix[2] = 0.0f;
    transform.matrix[3] = 0.0f;
    transform.matrix[5] = 0.0f;
    transform.matrix[6] = 0.0f;
    transform.matrix[7] = 0.0f;
    transform.matrix[4] = 1.0f;
    transform.matrix[8] = 1.0f;
    transform.scale = 1.0f;
    target->BoundsAt(&box);
    typedef void (__thiscall* Apply)(Owner*, Transform*);
    void** dispatch = table;
    box.high.x -= box.low.x;
    box.high.y -= box.low.y;
    box.high.z -= box.low.z;
    box.high.w -= box.low.w;
    box.high.x *= 0.5;
    box.high.y *= 0.5;
    box.high.z *= 0.5;
    box.high.w *= 0.5;
    box.low.x += box.high.x;
    box.low.y += box.high.y;
    box.low.z += box.high.z;
    box.low.w += box.high.w;
    transform.x = box.high.x * 6.999040126800537;
    transform.y = box.high.y * 6.999040126800537;
    transform.z = box.high.z * 6.999040126800537;
    reinterpret_cast<Apply>(dispatch[46])(this, &transform);
}
}

}   // namespace f3m_008f9580

// @f3 0x008fece0 (community match, verified in this file)
namespace f3m_008fece0 {

struct __declspec(align(16)) Vec4_8fece0
{
    float x;
    float y;
    float z;
    float w;
    Vec4_8fece0() {}
    Vec4_8fece0(const Vec4_8fece0& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    Vec4_8fece0& operator=(const Vec4_8fece0& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
};
static __forceinline Vec4_8fece0 Get(const Vec4_8fece0& v) { return v; }
struct __declspec(align(16)) Matrix34_8fece0 { Vec4_8fece0 row0,row1,row2; };
class Obj60_8fece0
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
    Matrix34_8fece0 FUN_008fd970();
};
struct Src_8fece0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4_8fece0 vec20;
    Vec4_8fece0 vec30;
    Vec4_8fece0 vec40;
    Vec4_8fece0 vec50;
    Obj60_8fece0 obj60;
    Vec4_8fece0 vec90;
    Vec4_8fece0 vecA0;
    float fB0;
    char byteB4;
    char byteB5;
};
class This_8fece0
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
    Vec4_8fece0 vec30;
    Vec4_8fece0 vec40;
    Vec4_8fece0 vec50;
    Vec4_8fece0 vec60;
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
    Vec4_8fece0 vecA0;
    Vec4_8fece0 vecB0;
    float fC0;
    float unkC4;
    int unkC8;
    int unkCC;
    char byteD0;
    char byteD1;
    void FUN_008fe480(const Matrix34_8fece0& a_rValue);
    This_8fece0& FUN_008fece0(Src_8fece0* src);
};
// pdb: bhkRigidBodyCinfo::operator= | bhkRigidBody.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInfo
This_8fece0& This_8fece0::FUN_008fece0(Src_8fece0* src)
{
    struct CopyWorkspace { Vec4_8fece0 common,second; };
    CopyWorkspace work;
    this->unk00 = src->unk00;
    this->unk20 = this->unk00;
    this->unk04 = src->unk04;
    this->unk24 = this->unk04;
    work.common=src->vec20;
    this->vec30=work.common;
    work.second=src->vec30;
    this->vec40=work.second;
    work.common=src->vec40;
    this->vec50=work.common;
    work.common=src->vec50;
    this->vec60=work.common;
    this->FUN_008fe480(src->obj60.FUN_008fd970());
    work.common=src->vec90;
    this->vecA0=work.common;
    this->vecB0.x = src->vecA0.x;
    this->vecB0.y = src->vecA0.y;
    this->vecB0.z = src->vecA0.z;
    this->vecB0.w = src->vecA0.w;
    this->fC0 = src->fB0;
    this->byteD0 = src->byteB4;
    this->byteD1 = src->byteB5;
    if (this->unkC4 > 1000.0)
        this->unkC4 = 1000.0f;
    return *this;
}
}   // namespace f3m_008fece0

// @f3 0x008fe150 (community match, verified in this file)
#include <new>
namespace Scene659 {
extern const double DAT_00db88e8;
struct Vector { float x,y,z; };
static __forceinline void AssignVector(Vector& destination,Vector value) { destination=value; }
struct Rotation { float xx, xy, xz, yx, yy, yz, zx, zy, zz; };
struct Transform { Rotation rotation; Vector translation; float scale; };
struct __declspec(align(16)) FUN_008fda60 {
    Rotation basisRotation;
    Vector basisTranslation;
    Vector position;
    FUN_008fda60(const Transform*);
};
extern Transform DAT_010f3370;
struct FUN_0082ea60 {
    unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030;
    Transform transform;
    unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8;
    FUN_0082ea60(int);
    void FUN_008245d0(const void*);
};
void* FUN_0089eb90(unsigned);
void FUN_0086ba60(void*);
void FUN_0056ac90(Transform*, FUN_008fda60*);
extern char DAT_00e324dc[];
extern const char* DAT_00e207a8;
const char* FUN_008242a0(const char*);
extern long (__stdcall *DAT_00d9b064)(long*);
struct Name {
    const char* value;
    Name(const char* input) : value(FUN_008242a0(input)) {}
    ~Name() {
        if (value != DAT_00e207a8)
            DAT_00d9b064(reinterpret_cast<long*>(const_cast<char*>(value) - 8));
    }
};
struct Receiver { void** table; };
struct Callback { unsigned unk000; unsigned unk004; Receiver* receiver; };
struct Data { unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; Callback* callback; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; Transform transform; };
struct Owner {
    unsigned unk000; unsigned unk004;
    Data* data;
    void bhkTransformShape_BuildDisplayGeometry(Receiver*);
};
}
inline void* operator new(size_t size, int) { return Scene659::FUN_0089eb90(size); }
inline void operator delete(void* storage, int) { Scene659::FUN_0086ba60(storage); }
namespace Scene659 {
// pdb: bhkTransformShape::BuildDisplayGeometry | bhkTransformShape.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|vtable), high
void Owner::bhkTransformShape_BuildDisplayGeometry(Receiver* receiver) {
    FUN_008fda60 world(this && data ? &data->transform : &DAT_010f3370);
    Transform local;
    FUN_0056ac90(&local, &world);
    local.translation.x = world.position.x * DAT_00db88e8;
    local.translation.y = world.position.y * DAT_00db88e8;
    local.translation.z = world.position.z * DAT_00db88e8;
    FUN_0082ea60* child = new(0) FUN_0082ea60(0);
    {
        Name name(DAT_00e324dc);
        child->FUN_008245d0(&name);
    }
    typedef void (__thiscall* Attach)(Receiver*, FUN_0082ea60*, int);
    reinterpret_cast<Attach>(receiver->table[55])(receiver, child, 1);
    AssignVector(child->transform.translation,local.translation);
    child->transform.rotation = local.rotation;
    if (this && data && data->callback && data->callback->receiver) {
        Receiver* target = data->callback->receiver;
        typedef void (__thiscall* Notify)(Receiver*, FUN_0082ea60*);
        reinterpret_cast<Notify>(target->table[52])(target, child);
    }
}
}

// @f3 0x008ea9c0 (community match, verified in this file)
#include <math.h>
namespace f3m_008ea9c0 {
extern "C" void _ReadBarrier();
namespace Ray8EA9C0 {
struct __declspec(align(16)) Vec4 {
 float x,y,z,w;
 Vec4() {}
 Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
 Vec4(const Vec4& v):x(v.x),y(v.y),z(v.z),w(v.w){}
 Vec4& operator=(const Vec4& v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
 void FUN_008d2970(const struct Transform&,const Vec4&);
 __forceinline void Normalize(){float length=x*x+y*y+z*z;float inverse;if(length!=0.0f){length=(float)sqrt(length);inverse=1.0f/length;}else{inverse=0.0f;}x=inverse*x;y=inverse*y;z=inverse*z;}
};
struct __declspec(align(16)) Transform { Vec4 a,b,c,d;__forceinline Transform(const Vec4& v0,const Vec4& v1,const Vec4& v2,const Vec4& v3):a(v0),b(v1),c(v2),d(v3){} };
struct RayInput {Vec4 from,to;unsigned filter;unsigned enable;RayInput():filter(0),enable(0){}};
struct Bool {char value;Bool(){}Bool(bool b):value(b?1:0){} operator bool() const{return value!=0;}};
struct HitBase {Vec4 normal;float fraction;int extra;HitBase():extra(-1){} void Reset(){fraction=1.0f;} __forceinline Bool HasHit() const{return Bool(fraction<1.0f);}};
struct Hit:HitBase {int keys[8];int level;Hit():level(0){keys[0]=-1;}};

struct Filter {unsigned char FUN_008f76e0(int,unsigned char);};
struct Shape {virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual Bool Cast(const RayInput&,Hit&) const;unsigned unk04;Filter* unk08;};
struct Header {Shape* shape;unsigned unk04,unk08,unk0c;signed char offset;unsigned unk14;unsigned char kind;};
struct Source {
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
 Vec4 a,b,c,d;
};
struct Query {float x,y,z;unsigned unk0c,unk10,unk14,unk18,unk1c;Header* a;unsigned unk24;Header* b;};

struct Owner {
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
 unsigned unk248;
 unsigned unk24c;
 unsigned unk250;
 unsigned unk254;
 unsigned unk258;
 unsigned unk25c;
 unsigned unk260;
 unsigned unk264;
 unsigned unk268;
 unsigned unk26c;
 unsigned unk270;
 unsigned unk274;
 unsigned unk278;
 unsigned unk27c;
 unsigned unk280;
 unsigned unk284;
 unsigned unk288;
 unsigned unk28c;
 unsigned unk290;
 unsigned flags;
 unsigned unk298;
 unsigned unk29c;
 unsigned unk2a0;
 unsigned unk2a4;
 unsigned unk2a8;
 unsigned unk2ac;
 unsigned unk2b0;
 unsigned unk2b4;
 unsigned unk2b8;
 unsigned unk2bc;
 unsigned unk2c0;
 unsigned unk2c4;
 unsigned unk2c8;
 unsigned unk2cc;
 unsigned unk2d0;
 unsigned unk2d4;
 unsigned unk2d8;
 unsigned unk2dc;
 unsigned unk2e0;
 unsigned unk2e4;
 unsigned unk2e8;
 unsigned unk2ec;
 float height;
 float radius;
 unsigned unk2f8;
 unsigned unk2fc;
 unsigned unk300;
 unsigned unk304;
 unsigned unk308;
 unsigned unk30c;
 unsigned unk310;
 unsigned unk314;
 unsigned unk318;
 unsigned unk31c;
 unsigned unk320;
 unsigned unk324;
 unsigned unk328;
 unsigned unk32c;
 unsigned unk330;
 unsigned unk334;
 unsigned unk338;
 unsigned unk33c;
 unsigned unk340;
 unsigned unk344;
 unsigned unk348;
 unsigned unk34c;
 unsigned unk350;
 unsigned unk354;
 unsigned unk358;
 unsigned unk35c;
 unsigned unk360;
 unsigned unk364;
 unsigned unk368;
 unsigned unk36c;
 unsigned unk370;
 unsigned unk374;
 unsigned unk378;
 unsigned unk37c;
 unsigned unk380;
 unsigned unk384;
 unsigned unk388;
 unsigned unk38c;
 unsigned unk390;
 unsigned unk394;
 unsigned unk398;
 unsigned unk39c;
 unsigned unk3a0;
 unsigned unk3a4;
 unsigned unk3a8;
 unsigned unk3ac;
 unsigned unk3b0;
 unsigned unk3b4;
 unsigned unk3b8;
 unsigned unk3bc;
 unsigned unk3c0;
 unsigned unk3c4;
 unsigned unk3c8;
 unsigned unk3cc;
 unsigned unk3d0;
 unsigned unk3d4;
 unsigned unk3d8;
 unsigned unk3dc;
 unsigned unk3e0;
 unsigned unk3e4;
 unsigned unk3e8;
 unsigned unk3ec;
 unsigned unk3f0;
 unsigned unk3f4;
 unsigned unk3f8;
 unsigned unk3fc;
 unsigned unk400;
 unsigned unk404;
 unsigned unk408;
 unsigned unk40c;
 unsigned unk410;
 unsigned unk414;
 unsigned unk418;
 unsigned unk41c;
 unsigned unk420;
 unsigned unk424;
 unsigned unk428;
 unsigned unk42c;
 unsigned unk430;
 unsigned unk434;
 unsigned unk438;
 unsigned unk43c;
 unsigned unk440;
 unsigned unk444;
 unsigned unk448;
 unsigned unk44c;
 unsigned unk450;
 unsigned unk454;
 unsigned unk458;
 unsigned unk45c;
 unsigned unk460;
 unsigned unk464;
 unsigned unk468;
 unsigned unk46c;
 unsigned unk470;
 unsigned unk474;
 unsigned unk478;
 unsigned unk47c;
 float limit;
 void FUN_008ea1f0(Vec4&);
 bool FUN_008ea9c0(Query*);
};
// pdb: bhkCharProxyController::Init | bhkCharProxyController.obj | tesv_win, objopen_prop, low
bool Owner::FUN_008ea9c0(Query* q){
 Header* first=q->a;
 void* object=first->kind==2?(char*)first+first->offset:0;
 Header* second=q->b;
 Source* src=second->kind==1?(Source*)((char*)second+second->offset):0;
 bool result=true;
 if(object && src){
 Shape* shape=*(Shape* volatile*)&second->shape;
 Vec4 a(src->a),point(src->b),c(src->c),d(src->d);
 RayInput input;
 Hit hit;
 Transform transform(a,point,c,d);hit.Reset();
 Vec4& origin=d;origin.x=q->x;origin.y=q->y;origin.z=q->z;
 FUN_008ea1f0(point);
 double adjustedZ=point.z;_ReadBarrier();point.z=adjustedZ+height;
 bool above=false;
 float gap=origin.z-point.z;
 if(gap>0.0f){if(height/3.0<gap)return result;above=true;}
 Vec4& direction=a;direction.x=point.x-origin.x;direction.y=point.y-origin.y;direction.z=0.0f;
 direction.Normalize();
 c.z=point.z;c.w=point.w;
 float distance;
 if(radius>limit)distance=radius;else distance=limit+limit-radius;
 if(above)distance+=5.0;
 Vec4& end=c;end.x=point.x-distance*direction.x;end.y=point.y-distance*direction.y;
 input.from.FUN_008d2970(transform,point);
 input.to.FUN_008d2970(transform,end);
 shape->Cast(input,hit);
 result=hit.HasHit();
 if(result){
   if(shape->unk08){int key=-1;for(int i=0;i<8;++i){int current=hit.keys[i];if(current==-1)break;key=current;}if(shape->unk08->FUN_008f76e0(key,0x40))result=false;}
 }else if(above){result=true;}
 if(above && !hit.HasHit() && (flags&0x1000000))result=false;
 }
 return result;
}
}
}   // namespace f3m_008ea9c0

// @f3 0x008fea60 (community match, verified in this file)
namespace n8fea60 {
struct V4 {
    float x;
    float y;
    float z;
    float w;
};

extern V4 DAT_01092a50;

struct Body {
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
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    V4 pos;
};
}

struct C8fea60 {
    int unk00;
    int unk04;
    n8fea60::Body* body;
    n8fea60::V4 __thiscall FUN_008fea60();
};

// pdb: bhkRigidBody::GetCenterOfMassInWorld | bhkRigidBody.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arCOM
n8fea60::V4 __thiscall C8fea60::FUN_008fea60()
{
    const volatile n8fea60::V4* source;

    if (this && body)
        source = &body->pos;
    else
        source = &n8fea60::DAT_01092a50;

    n8fea60::V4 result;
    result.x = source->x;
    result.y = source->y;
    result.z = source->z;
    result.w = source->w;
    return result;
}

// @f3 0x008ea6d0 (community match, verified in this file)
namespace f3m_008ea6d0 {

namespace Transform647 {
struct NodeType { int unk00; int unk04; int unk08; int type; };
struct Transform;
struct FNV_ALIGN(16) Vector {
    float x, y, z, w;
    void hkVector4_setTransformedPos(const Transform*, const Vector*);
    void raiseFirst(const float& value) { z += value; }
    void raise(float value) { z += value; }
};
struct Node { int unk00; int unk04; int unk08; int unk0c; NodeType* type; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; };
struct Handle { Node* FUN_0091ddd0(); };
struct Owner {
    int unk00; int unk04;
    Handle* handle;
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
    unsigned flags;
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
    float height;
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
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    Vector corners[4];
    float width, depth;
    void FUN_008ea6d0();
};
// pdb: bhkCharacterController::InitFrontBack | bhkCharacterController.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: bhkCharProxyController::bhkCharProxyController)
void Owner::FUN_008ea6d0() {
    if (!(flags & 1))
        return;
    Node* node = handle ? handle->FUN_0091ddd0() : 0;
    float z = width;
    NodeType* type = node->type;
    float nearSide = static_cast<float>(depth * 0.5 - z);
    float farSide = static_cast<float>(-1.0 * nearSide);
    if (type->type != 10)
        z = static_cast<float>(-width * 0.5);
    const Transform* transform = reinterpret_cast<Transform*>(reinterpret_cast<char*>(node) + 0xa0);
    Vector point = {0.0f, nearSide, z, 0.0f};
    float* corner = &corners[0].z;
    {
    int count = 2;
    do {
        reinterpret_cast<Vector*>(corner - 2)->hkVector4_setTransformedPos(transform, &point);
        reinterpret_cast<Vector*>(corner - 2)->raiseFirst(height);
        corner += 4;
        point.y = farSide;
    } while (--count);
    }
    point.x = farSide;
    point.y = 0.0f;
    point.z = z;
    point.w = 0.0f;
    corner = &corners[2].z;
    {
    int count = 2;
    do {
        reinterpret_cast<Vector*>(corner - 2)->hkVector4_setTransformedPos(transform, &point);
        reinterpret_cast<Vector*>(corner - 2)->raise(height);
        corner += 4;
        point.x = nearSide;
    } while (--count);
    }
}
}
}   // namespace f3m_008ea6d0

// @f3 0x008f7c70 (community match, verified in this file)
namespace f3m_008f7c70 {
class RefCountedObj {
public:
    virtual void Virtual0(int param);
};

class C8f7c70 {
public:
    void FUN_008f7c70(bool param);
};

// pdb: bhkRefObject::Link | bhkRefObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abAttach
void C8f7c70::FUN_008f7c70(bool param)
{
    RefCountedObj* obj = (RefCountedObj*)*(void**)((char*)this + 8);
    if (obj != 0) {
        if (param) {
            if (*(short*)((char*)obj + 4) != 0) {
                *(short*)((char*)obj + 6) += 1;
            }
        } else {
            if (*(short*)((char*)obj + 4) != 0) {
                *(short*)((char*)obj + 6) -= 1;
                if (*(unsigned short*)((char*)obj + 6) == 0) {
                    obj->Virtual0(1);
                }
            }
        }
    }
}
}   // namespace f3m_008f7c70

// @f3 0x008ed480 (community match, verified in this file)
namespace task2126 {

struct __declspec(align(16)) V4 { float x, y, z, w; };

struct Inner8 { int unk00; int unk04; int unk08; int unk0c; float val10; int unk14; int unk18; int unk1c; V4 v20; V4 v30; };

extern float DAT_00f7a690;

struct Obj8e { int unk00; int unk04; Inner8* inner; float GetScale() const {return inner ? inner->val10 : DAT_00f7a690;} void FUN_008e8b30(int idx, V4* v); };

extern V4 DAT_01092a50;

extern int DAT_010f3350;

void* FUN_00424d50(int* tbl, int id);

extern float DAT_00f7a690;

static float getv(Inner8* p) { return p ? p->val10 : DAT_00f7a690; }

struct Mover8 {

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

unsigned flags294;

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

int unk434;

int unk438;

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

float unk480;

unsigned int unk484;

float unk488;

unsigned int unk48c;

int unk490;

    unsigned char GetFlags() const { return *static_cast<const volatile unsigned*>(&flags294) >> 20; }

    float GetCurrent() const {return unk488;}

    void FUN_008ed0a0(int a);

    void bhkCharacterController_ChangeSize(float step);

};

__forceinline float AdvanceValue(float previous, const float& target, float& delta)
{
    float next;
    if (previous > target)
    {
        next = previous - delta;
        if (next <= target) { delta = target - previous; return target; }
        delta = -delta;
        return next;
    }
    next = delta + previous;
    if (next >= target) { delta = target - previous; return target; }
    return next;
}

// pdb: bhkCharacterController::ChangeSize | bhkCharacterController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap_sim), high
void Mover8::bhkCharacterController_ChangeSize(float step)

{

    if (unk490 != 2) return;

    float v;

    Obj8e* o = static_cast<Obj8e*>(FUN_00424d50(&DAT_010f3350, unk438));

    if (o) {

        unsigned char flagByte = GetFlags();
        if (flagByte & 1) step = 100.0f;

        Inner8* in = o->inner;

        float delta;

        float scale=getv(in);

        v=*(volatile float*)&scale;

        delta = step * 5.0;

        v = AdvanceValue(v, unk488, delta);

        V4 v1, v2;

        const V4* s1 = in ? &in->v20 : &DAT_01092a50;

        v1.x = s1->x; v1.y = s1->y; v1.z = s1->z; v1.w = s1->w;

        const V4* s2 = in ? &in->v30 : &DAT_01092a50;

        v2.x = s2->x; v2.y = s2->y; v2.z = s2->z; v2.w = s2->w;

        v1.z = v1.z - delta;

        v2.z = v2.z + delta;

        o->FUN_008e8b30(0, &v1);

        o->FUN_008e8b30(1, &v2);

        in = o->inner;

        if (in) in->val10 = v;

    } else {

        v = unk488;

    }

    if (v != unk488) return;

    if (v == unk480) {

        if (unk434 != 2) { FUN_008ed0a0(unk434); unk434 = 2; }

        unk490 = 0;

    } else {

        unk490 = 1;

    }

}

}

// @f3 0x008e46c0 (community match, verified in this file)
namespace f3m_008e46c0 {
struct Obj54_8e46c0 {
    int unk00;
    Q78Array<Q78E30> arr48a;
    Q78Array<Q78E30> arr48b;
    Q78Array<int> arr4a;
    int unk28;
    Q78Array<int> arr4b;
    ~Obj54_8e46c0();
};
// pdb: hkaPose::~hkaPose | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
Obj54_8e46c0::~Obj54_8e46c0() {
}
}   // namespace f3m_008e46c0

// @f3 0x008f1880 (community match, verified in this file)
extern int DAT_010f3350, DAT_010f2ee0, DAT_010f33b4;
namespace f3m_008f1880 {
struct Obj;
struct __declspec(align(16)) Mat4 { float m00, m01, m02, m03, m04, m05, m06, m07, m08, m09, m0a, m0b, m0c, m0d, m0e, m0f;
    void hkTransform_setMul(Mat4* a, Obj* o); };
struct Xf { float x0, x1, x2, x3; };
struct __declspec(align(16)) Obj {
    float p00, p01, p02, p03, p04, p05, p06, p07, p08, p09, p0a, p0b;
    float s30, s34, s38, s3c;
    Obj(Xf* x);
};
struct __declspec(align(16)) Out { float u00, u04, u08, u0c, u10, u14, u18, u1c; void FUN_005686c0(Out* o); };
struct Hdr { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; unsigned unk1c; };
struct Form { int unk00; int unk04; int unk08; int unk0c; Hdr unk10; };
struct Result { void* unk00; int unk04; int unk08; int unk0c; Out unk10; };
struct Tgt {
    virtual void v00();
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b(); virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b(); virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v2a(); virtual void v2b(); virtual void v2c(); virtual void v2d(); virtual void v2e(); virtual void v2f(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3a();
    virtual void Ex(Mat4* m);
    int unk04; Form* unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    Xf unk20; float unk30; float unk34; float unk38; float unk3c;
    void* FUN_004706e0();
    bool FUN_00726810();
};
struct Scene { int unk00; int unk04; int unk08; int unk0c; Tgt* unk10; int unk14; float f18; };
struct Target2 { bool FUN_0091d650(void* a, Mat4* loc, Out* out); };
struct Item;
struct Cont { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; Item** unkA0; unsigned short unkA4; unsigned short unkA6; };
struct Item {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual Cont* GetCont();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68;
};
extern Scene* FUN_00424fe0(Item* r);
extern Target2* FUN_00424d50(void* d, void* p);
extern bool FUN_00424d20(void* d, void* p);
extern void FUN_004e5e40(Mat4* out, void* src);

// pdb: bhkUtilFunctions::GetClosestBodyRec | bhkUtilFunctions.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject, arSphere, arClosest, abIgnoreHead
bool FUN_008f1880(Item* ref, void* a, Result* b, bool flag)
{
    bool result = false;
    Item* me = ref;
    if (me) {
        Scene* sc = FUN_00424fe0(me);
        if (sc && sc->unk10) {
            Tgt* t = sc->unk10;
            Form* f = t->unk08;
            Hdr* h = f ? &f->unk10 : 0;
            unsigned ty = h ? h->unk1c : 0;
            if ((ty & 0x7f) == 8 || (ty & 0x7f) == 0x1d) {
                unsigned k = (ty >> 8) & 0x1f;
                bool go = false;
                if (k != 1) { if (k - 2 <= 0xe) go = true; } else { go = (flag == 0); if (!go) go = false; }
                if (go) {
                    void* m = t->FUN_004706e0();
                    Target2* tg = m ? FUN_00424d50(&DAT_010f3350, m) : 0;
                    if (tg) {
                        Mat4 loc;
                        t->Ex(&loc);
                        if (FUN_00424d20(&DAT_010f2ee0, sc)) {
                            if (!t->FUN_00726810() || sc->f18 == 1.0f) {
                                FUN_004e5e40(&loc, &me->unk68);
                                if (FUN_00424d20(&DAT_010f33b4, t)) {
                                    Mat4 loc2;
                                        loc2.m00 = loc.m00;
                                        loc2.m01 = loc.m01;
                                        loc2.m02 = loc.m02;
                                        loc2.m03 = loc.m03;
                                        loc2.m04 = loc.m04;
                                        loc2.m05 = loc.m05;
                                        loc2.m06 = loc.m06;
                                        loc2.m07 = loc.m07;
                                        loc2.m08 = loc.m08;
                                        loc2.m09 = loc.m09;
                                        loc2.m0a = loc.m0a;
                                        loc2.m0b = loc.m0b;
                                        loc2.m0c = loc.m0c;
                                        loc2.m0d = loc.m0d;
                                        loc2.m0e = loc.m0e;
                                        loc2.m0f = loc.m0f;
                                    Obj o(&t->unk20);
                                    o.s30 = t->unk30; o.s34 = t->unk34; o.s38 = t->unk38; o.s3c = t->unk3c;
                                    loc.hkTransform_setMul(&loc2, &o);
                                }
                            }
                        } else {
                            t->Ex(&loc);
                        }
                        Out out;
                        if (tg->FUN_0091d650(a, &loc, &out)) {
                            if (b->unk00 == 0 || b->unk10.u1c > out.u1c) {
                                b->unk00 = t;
                                b->unk10.FUN_005686c0(&out);
                            }
                        }
                    }
                }
            }
        }
        Cont* c = me->GetCont();
        if (c) {
            for (unsigned i = 0; i < c->unkA6; i++) {
                Item* it = c->unkA0[i];
                result |= FUN_008f1880(it, a, b, flag);
            }
        }
    }
    return result;
}
}   // namespace f3m_008f1880

// @f3 0x008e8f40 (community match, verified in this file)
namespace f3m_008e8f40 {
// Reports whether the attached component is in one of three live states.

class F3Sub_8e8f40
{
  public:
    int FUN_00919ef0();
};

class F3Owner_8e8f40
{
  public:
    char pad00[0x260];
};

// pdb: bhkCharacterController::QUseZ | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
bool __fastcall FUN_008e8f40(F3Owner_8e8f40* pThis, int iUnused)
{
    int iState = ((F3Sub_8e8f40*)((char*)pThis + 0x260))->FUN_00919ef0();
    return iState == 5 || iState == 6 || iState == 4;
}
}   // namespace f3m_008e8f40

// @f3 0x008e9600 (community match, verified in this file)
namespace f3m_008e9600 {
struct RefCounted008e9600 {
    virtual void Slot00();
    virtual void Destroy();
    long refCount;
};

extern long (__stdcall* const DAT_00d9b064)(long volatile* addend);
extern long (__stdcall* const DAT_00d9b068)(long volatile* addend);

struct Ptr008e9600 {
    RefCounted008e9600* ptr;
    Ptr008e9600& FUN_008e9600(RefCounted008e9600* const& rhs);
};

// pdb: NiPointer<PathingSolution>::operator= | TESScriptFunctions.obj | fnv360_0721_beta, call_seq, high
// pdb params: ptr
Ptr008e9600& Ptr008e9600::FUN_008e9600(RefCounted008e9600* const& rhs) {
    RefCounted008e9600* old = ptr;
    if (old != rhs) {
        if (old) {
            if (DAT_00d9b064(&old->refCount) == 0) {
                old->Destroy();
            }
        }
        RefCounted008e9600* added = rhs;
        ptr = added;
        if (added) {
            DAT_00d9b068(&added->refCount);
        }
    }
    return *this;
}
}   // namespace f3m_008e9600

// @f3 0x008fbff0 (community match, verified in this file)
namespace f3m_008fbff0 {
struct Other8fbff0 {
    void FUN_009316e0();
    void FUN_009316f0();
};
struct Sub8fbff0 {
    char unk00[0x18];
    Other8fbff0* m_pField18;
};
struct Class8fbff0 {
    char unk00[8];
    Sub8fbff0* m_pField8;
    void FUN_008fbff0(Other8fbff0* arg);
};
// pdb: bhkConstraint::SetEntityB | bhkConstraint.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apEntity
void Class8fbff0::FUN_008fbff0(Other8fbff0* arg)
{
    if (this == 0)
        return;
    Sub8fbff0* sub = m_pField8;
    if (sub == 0)
        return;
    if (arg != 0)
        arg->FUN_009316e0();
    if (sub->m_pField18 != 0)
        sub->m_pField18->FUN_009316f0();
    sub->m_pField18 = arg;
}
}   // namespace f3m_008fbff0

// @f3 0x008f6a10 (community match, verified in this file)
namespace f3m_008f6a10 {
namespace Buffer8f6a10 {
struct Buffer {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 unsigned start;int unk24;int sentinel;unsigned end,size;
 void FUN_008f6a10(unsigned pointer,unsigned length);
};
void Buffer::FUN_008f6a10(unsigned pointer,unsigned length) {
 unsigned remainder=pointer&15;
 sentinel=-1;
 size=length;
 if(remainder) {start=pointer-remainder;start+=16;end=start-remainder+length;}
 else {start=pointer;end=pointer+length;}
}
}

}   // namespace f3m_008f6a10

// @f3 0x008e8920 (community match, verified in this file)
#include <math.h>
namespace f3m_008e8920 {
namespace Maximum8e8920 {
inline float absValue(float value){return static_cast<float>(fabs(value));}
struct Object {
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
int unk350;
int unk354;
int unk358;
int unk35c;
int unk360;
int unk364;
int unk368;
int unk36c;
int unk370;
int unk374;
int unk378;
int unk37c;
int unk380;
int unk384;
int unk388;
int unk38c;
int unk390;
int unk394;
int unk398;
int unk39c;
int unk3a0;
int unk3a4;
int unk3a8;
int unk3ac;
int unk3b0;
float value,associated;
void FUN_008e8920(float,float);
};
// pdb: bhkCharacterController::SetRotationModifier | bhkCharacterController.obj | fnv360_0822_debug, call_gap_sim, low
// pdb params: afRotationMod, afTime
void Object::FUN_008e8920(float input,float other) {
if(absValue(input)>absValue(value)){value=input;associated=other;}
}
}
}   // namespace f3m_008e8920

// @f3 0x008f2480 (community match, verified in this file)
namespace f3m_008f2480 {
namespace Query8f2480 {
struct __declspec(align(16)) Query {
 int result, unk04, unk08, unk0c;
 int unk10, unk14, unk18, unk1c;
 int unk20, unk24, unk28, unk2c;
};
void __cdecl FUN_008f1880(void*,void*,Query*,void*);
// pdb: bhkUtilFunctions::GetClosestBody | bhkUtilFunctions.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkUtilFunctions::GetMaterialIsStairs)
// pdb params: apRoot, arSphere, abIgnoreHead
int __cdecl FUN_008f2480(void* first,void* second,void* third) {
 Query query;
 query.result=0;
 FUN_008f1880(first,second,&query,third);
 return query.result;
}
}
}   // namespace f3m_008f2480

// @f3 0x008ed050 (community match, verified in this file)
namespace f3m_008ed050 {
namespace Delta8ed050 {
struct __declspec(align(16)) Vec4 {float x,y,z,w;};extern double DAT_00db88e8;
struct Object {
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
int unk350;
int unk354;
int unk358;
int unk35c;
int unk360;
int unk364;
int unk368;
int unk36c;
int unk370;
int unk374;
int unk378;
int unk37c;
int unk380;
int unk384;
int unk388;
int unk38c;
int unk390;
int unk394;
int unk398;
int unk39c;
int unk3a0;
int unk3a4;
int unk3a8;
int unk3ac;
int unk3b0;
int unk3b4;
int unk3b8;
int unk3bc;
int unk3c0;
int unk3c4;
int unk3c8;
int unk3cc;
float value;
void FUN_008ea1f0(Vec4*);float FUN_008ed050();
};
// pdb: bhkCharacterController::GetFallDistance | bhkCharacterController.obj | fnv360_0822_retail, call_gap, medium
float Object::FUN_008ed050(){
float result=0;
if(value!=0){Vec4 position;FUN_008ea1f0(&position);float scaled=static_cast<float>(position.z*DAT_00db88e8);result=value-scaled;}
return result;
}
}
}   // namespace f3m_008ed050

// @f3 0x008ed680 (community match, verified in this file)
namespace f3m_008ed680 {
namespace Apply8ed680 {
struct Vec3 {unsigned x,y,z;};extern Vec3 DAT_0108ec68;
struct Input {float value;int unk04,unk08,unk0c;Vec3 vector;};struct State {int FUN_00919ef0();};
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
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void apply(Input*);int unk004;
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
State state;void bhkCharacterController_ChangeSize(float);void FUN_008ed680(Input*,bool);};
// pdb: bhkCharacterController::MoveImmobile | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
// pdb params: arData, abAllowFalling
void Object::FUN_008ed680(Input* input,bool useVector){bool special=state.FUN_00919ef0()==2;if(useVector&&special){input->vector=DAT_0108ec68;apply(input);}else bhkCharacterController_ChangeSize(input->value);}
}
}   // namespace f3m_008ed680

// @f3 0x008ed0a0 (community match, verified in this file)
namespace f3m_008ed0a0 {
extern int DAT_01092a50;

struct Sub08 {
    void* FUN_0091dd60();
};

struct Obj8ed0a0 {
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
    virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(int a);

    int u004;
    Sub08* sub08;
    int u00c, u010, u014, u018, u01c, u020, u024, u028, u02c, u030, u034, u038, u03c;
    int u040, u044, u048, u04c, u050, u054, u058, u05c, u060, u064, u068, u06c, u070, u074, u078, u07c;
    int u080, u084, u088, u08c, u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc;
    int u0c0, u0c4, u0c8, u0cc, u0d0, u0d4, u0d8, u0dc, u0e0, u0e4, u0e8, u0ec, u0f0, u0f4, u0f8, u0fc;
    int u100, u104, u108, u10c, u110, u114, u118, u11c, u120, u124, u128, u12c, u130, u134, u138, u13c;
    int u140, u144, u148, u14c, u150, u154, u158, u15c, u160, u164, u168, u16c, u170, u174, u178, u17c;
    int u180, u184, u188, u18c, u190, u194, u198, u19c, u1a0, u1a4, u1a8, u1ac, u1b0, u1b4, u1b8, u1bc;
    int u1c0, u1c4, u1c8, u1cc, u1d0, u1d4, u1d8, u1dc, u1e0, u1e4, u1e8, u1ec, u1f0, u1f4, u1f8, u1fc;
    int u200, u204, u208, u20c, u210, u214, u218, u21c, u220, u224, u228, u22c, u230, u234, u238, u23c;
    int u240, u244, u248, u24c, u250, u254, u258, u25c, u260, u264, u268, u26c, u270, u274, u278, u27c;
    int u280, u284, u288, u28c, u290;
    unsigned int flags294;
    int u298, u29c, u2a0, u2a4, u2a8, u2ac, u2b0, u2b4, u2b8, u2bc;
    int u2c0, u2c4, u2c8, u2cc, u2d0, u2d4, u2d8, u2dc, u2e0, u2e4, u2e8, u2ec, u2f0, u2f4, u2f8, u2fc;
    int u300, u304, u308, u30c, u310, u314, u318, u31c, u320, u324, u328, u32c, u330, u334, u338, u33c;
    int u340, u344, u348, u34c, u350, u354, u358, u35c, u360, u364, u368, u36c, u370, u374, u378, u37c;
    int u380, u384, u388, u38c, u390, u394, u398, u39c, u3a0, u3a4, u3a8, u3ac, u3b0, u3b4, u3b8, u3bc;
    int u3c0, u3c4, u3c8, u3cc, u3d0, u3d4, u3d8, u3dc, u3e0, u3e4, u3e8, u3ec, u3f0, u3f4, u3f8, u3fc;
    int u400, u404, u408, u40c, u410, u414, u418, u41c, u420, u424, u428, u42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;

    void FUN_008ecaa0();
    void* FUN_008e98a0(void* p);
    void bhkCharacterController_SetShape(void* p);
    void* GetSub() const { return sub08 ? sub08->FUN_0091dd60() : &DAT_01092a50; }
    void FUN_008ed0a0(int a);
};

// pdb: bhkCharacterController::SetShapeType | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeType
void Obj8ed0a0::FUN_008ed0a0(int a) {
    if (unk430 != a && a < 2 && (&unk438)[a] != 0) {
        bool flag = (flags294 >> 15) & 1;
        if (flag) {
            FUN_008ecaa0();
        }
        unk430 = a;
        bhkCharacterController_SetShape(FUN_008e98a0(GetSub()));
        if (flag) {
            v51(0);
        }
    }
}
}

// @f3 0x008f9990 (community match, verified in this file)
namespace f3m_008f9990 {
namespace Update8f9990 {
struct Shape;struct Link {int unk00,unk04;Shape* shape;};struct Result {int unk00,unk04;Link* link;};
struct Shape {virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual Result* replace(void*);virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c(); virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac(); virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc(); virtual void v0c0(); virtual void v0c4(); virtual void v0c8(); virtual bool has(void*);};
struct State {unsigned short first,flags;Link* link;int unk08,unk0c;unsigned value;};
struct Object {virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c(); virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac(); virtual void v0b0(); virtual State* get(bool*);void FUN_008f7e50(int,void*);void FUN_008f9990(int,void*);};
// pdb: bhkWorldObject::CopyMembers | bhkWorldObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apDest, arCloneData
void Object::FUN_008f9990(int mode,void* value){bool valid;State* state=get(&valid);if(state){state->value=0;if(state->link){Shape* shape=state->link->shape;if(shape&&!shape->has(value)){Result* result=shape->replace(value);state->link=result?result->link:0;}}state->flags=0;}FUN_008f7e50(mode,value);}
}
}   // namespace f3m_008f9990

// @f3 0x008f94a0 (community match, verified in this file)
namespace f3m_008f94a0 {
namespace Make8f94a0 {
void* FUN_0089eb90(unsigned);extern char DAT_00dfcd64;
struct FUN_008d9f90 {void* table;int unk04,unk08,unk0c,unk10;FUN_008d9f90();};
struct Product:FUN_008d9f90 {Product(){table=&DAT_00dfcd64;}static void* operator new(unsigned n){return FUN_0089eb90(n);}static void operator delete(void*);};
struct Object {void FUN_008da090(Product*,int);Product* FUN_008f94a0(int);};
// pdb: bhkPCollisionObject::CreateClone | bhkPCollisionObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arCloneData
Product* Object::FUN_008f94a0(int value){Product* p=new Product;FUN_008da090(p,value);return p;}
}
}   // namespace f3m_008f94a0

// @f3 0x008e9ed0 (community match, verified in this file)
namespace f3m_008e9ed0 {
// Model of FUN_008E9ED0 (35 bytes) - claim clm_ccfa84e203194911939e ✓✓ The pack declares this callees signature twice, which pins everything I need: line 2598 'struct Lookup { Result* FUN_00477900(Result* out, int* key); }'
// with a sibling body at line 2609 'return lookup08->FUN_00477900(&holder, key)->object;' ✓✗→✓✓ (line 1375/1389 show the same routine in another stand-in ✓ ) so the first parameter is an OUTPUT address and the second a key ✗
//   mov ecx,[esp+arg_4] ; sub esp,8 ; xor eax,eax ; test ecx,ecx ; jz short +27h   
//     - ECX receives the SECOND stack parameter and is only ever used as a call receiver ✓✗→✓✓ so this is a free cdecl function (plain 'retn', caller-cleaned; the 'add esp,8' below releases only its own frame ✗✗→? ) whose
//     second argument is an object pointer. The null test short-circuits everything: EAX was pre-cleared to zero and that becomes the return value ✓✗→✓✓ a null receiver yields zero without touching memory ✗✗→? 
//   mov eax,[esp+8+arg_0] ; push eax ; lea edx,[esp+0Ch+var_8] ; push edx ; call sub_477900   
//     - two arguments with the KEY first in source order (pushed last ✓ ) and the address of a stack local second ✗✗→✓✓ exactly matching the preludes declared '(Result* out, int* key)' shape ✓ and ECX still holds the
//     receiver from the prologue ✓✗→? so the callee is a member routine on that object, not a free function ✓ 
//   mov eax,[esp+8+var_8]   
//     - after the call, the LOCAL IS READ BACK and becomes the return value ✓✗→✓✓ an out parameter written through the pointer ✗✗→? note this read happens ONLY on the non-null path (the jump target skips it ✓ ) 
//   add esp,8 ; retn   
//     - frame released; nothing cleaned by the callee so the two parameters belong to a cdecl caller ✗✗→✓✓ and the eight-byte local area explains 'sub esp,8' ✗✗→? 

struct ResultHolders { unsigned long object00; unsigned long field04; };   // v2: TWO dwords - their build reserves EIGHT bytes of local area (a sub-esp-eight in the prologue and a read-back at [esp] after one push)    // while my single-dword version let this compiler fold the reservation away entirely, losing that prologue line and shifting every ESP displacement - ten of twelve differing lines ✓
                                                     //     The second dword is never read here; the SIZE of the out object is what their frame arithmetic proves ✗✗→✓✓ a field name inferred from geometry, marked as such ✓ 
struct LookupFree { struct ResultHolders* FUN_00477900(struct ResultHolders* out, int* key); };   // signature copied from prelude line 2598 'struct Lookup { Result* FUN_00477900(Result* out, int* key); }' ✓✗→✓✓ declared
                                                     //     WITHOUT a body so the call stays out of line ✗✗→✓✓ (an inline definition would expand into my function instead of emitting their call - measured trap on another
                                                     //     entry this session ✓ ) 

// pdb: bhkCharacterController::FindBSReference | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiKey, apPhantom
int FUN_008e9ed0(int* key, struct LookupFree* lookup) {   // cdecl with TWO parameters; the second arrives at [esp+arg_4] and is moved into ECX as a call receiver ✓✗→✓✓ nothing is cleaned by the callee ('retn' ✗✗→? ) 
    int value = 0;                                     // ORIG: 'xor eax,eax' in the prologue - the zero this function returns when there is no receiver ✓✗→✓✓ and it must be established BEFORE the branch because their
                                                     //     build jumps straight to the epilogue with EAX already set ✗✗→? 
    if (lookup != 0) {                                 // ORIG: 'test ecx,ecx ; je +27h' skipping both the call AND the read-back ✓✗→✓✓ one shared epilogue for both paths ✗✗→? 
        struct ResultHolders out;                      // ORIG: a stack local whose address is taken ('lea edx,[esp+0Ch+var_8]') and which is read back afterwards ✓✗→✓✓ the eight-byte frame reservation fits it plus
                                                     //     eight bytes here, matching their reservation ✓✗→✓✓ left uninitialised because their build never writes it before the call - an initialiser would add a store they do not emit ✓ 
        lookup->FUN_00477900(&out, key);               // ORIG: 'push eax(key) ; push edx(&out) ; call' with ECX = the receiver ✓✗→✓✓ parameter order (out, key) exactly as prelude line 2598 declares and as the sibling body
                                                     //     at line 2609 spells it ✗✗→? 
        value = (int)out.object00;                     // ORIG: 'mov eax,[esp+8+var_8]' - reading the out parameter back into the return register ✓✗→✓✓ only on this path ✗✗→? 
    }                                                 

    return value;                                      // ORIG: 'add esp,8 ; retn' with EAX holding either that read-back or the prologue zero ✓✗→✓✓ (their two paths share one epilogue, so writing a single return at the
                                                     //     end is faithful here rather than an early-return shortcut ✗✗→? ) 
}                                                      // closes the function - no namespace wrapper, which previously changed a mangled name and broke symbol lookup ✓ 

}   // namespace f3m_008e9ed0

// @f3 0x008f21f0 (community match, verified in this file)
namespace f3m_008f21f0 {
namespace Walk276 {
struct Object;struct Children {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;Object** data;unsigned short capacity,count;};
struct Object {virtual void v00();virtual void v04();virtual void v08();virtual Children* children();};
struct Data {int unk00,unk04;int value;};struct Extra {int unk00,unk04,unk08,unk0c;Data* data;};Extra* FUN_00424fe0(Object*);
struct Output {int* data;int count;unsigned capacity;};void FUN_00901f10(Output*,int);
// pdb: bhkUtilFunctions::GatherRigidBodies | bhkUtilFunctions.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject, arBodyA
void FUN_008f21f0(Object* object,Output* out){if(object){Extra* e=FUN_00424fe0(object);if(e&&e->data){int value=e->data->value;if(out->count==(int)(out->capacity&0x3fffffff))FUN_00901f10(out,4);out->data[out->count]=value;++out->count;}Children* c=object->children();if(c){for(unsigned i=0;i<c->count;++i)FUN_008f21f0(c->data[i],out);}}}
}
}   // namespace f3m_008f21f0

// @f3 0x008feaa0 (community match, verified in this file)
namespace f3m_008feaa0 {
namespace Transform8feaa0 {
struct Matrix {float a,b,c,d,e,f,g,h,i,j,k,l;Matrix():a(0),b(0),c(0),d(0),e(0),f(0),g(0),h(0),i(0),j(0),k(0),l(0){a=f=k=1;}};
struct Source;
struct Object;
struct __declspec(align(16)) Transform {volatile float a,b,c,d,e,f,g,h,i,j,k,l,x,y,z,w;Transform(Object*);void FUN_008fda60(const Source*);};
struct Source {};struct Data {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;Source source;};
struct Object {int unk00,unk04;Data* data;Transform FUN_008feaa0();};
__forceinline Transform::Transform(Object* source){if(source&&source->data){FUN_008fda60(&source->data->source);}else{a=0;b=0;c=0;d=0;e=0;f=0;g=0;h=0;i=0;j=0;k=0;l=0;a=1;f=1;k=1;x=y=z=w=0;}}
// pdb: bhkRigidBody::GetTransform | bhkRigidBody.obj | fnv360_0822_retail, objrun, medium
// pdb params: arTrans
Transform Object::FUN_008feaa0(){Transform result(this);return result;}
}

}   // namespace f3m_008feaa0

// @f3 0x008e8c80 (community match, verified in this file)
namespace f3m_008e8c80 {
namespace f3m_008e8c80 {

struct Sub_8e8c80 {
    int unk00;
    void FUN_0096a1d0();
};

struct __declspec(align(16)) Snapshot_8e8c80 {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c;
    int unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c;
    Snapshot_8e8c80(Sub_8e8c80* source);
    ~Snapshot_8e8c80();
};

struct Target_8e8c80 {
    int unk00; int unk04; int unk08; int unk0c;
    Sub_8e8c80 sub10;
};

struct World_8e8c80 {
    void hkpCharacterProxy_integrateImplementation(int arg, Sub_8e8c80* a, Snapshot_8e8c80* snapshot, Sub_8e8c80* b);
};

struct Owner_8e8c80 {
    void** vtbl;
    int unk04;
    World_8e8c80* unk08;
    int unk0c;
    Sub_8e8c80 sub10;
    Target_8e8c80* GetTarget() { return ((Target_8e8c80*(__thiscall*)(Owner_8e8c80*))vtbl[0x98 / 4])(this); }
    void FUN_0092ac40();
    void FUN_008e8c80(int arg);
};

// pdb: bhkCharacterProxy::Integrate | bhkCharacterController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void Owner_8e8c80::FUN_008e8c80(int arg)
{
    FUN_0092ac40();
    if (this) {
        World_8e8c80* world = unk08;
        if (world) {
            Snapshot_8e8c80 snapshot(&sub10);
            Target_8e8c80* target = GetTarget();
            world->hkpCharacterProxy_integrateImplementation(arg, &target->sub10, &snapshot, &sub10);
            sub10.FUN_0096a1d0();
        }
    }
    FUN_0092ac40();
}
}
}   // namespace f3m_008e8c80

// @f3 0x008e9780 (community match, verified in this file)
namespace f3m_008e9780 {





namespace f3m_008e9780d {

struct Record8E9 {                                 
    unsigned long formType;                        
    int unk04,unk08,unk0c;                       
};

struct Entry8E9; struct Holder8E9 {void* value;int unk04;}; struct Manager8E9 {                                
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70;
    struct Record8E9* records;                     
    int count;Entry8E9* FUN_00477900(Holder8E9*,unsigned long);                                     
};

struct Resolver8E9 {                               
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    void* resolvedC0;                              
};

struct Entry8E9 {                                  
    struct Resolver8E9* resolver;                  
};

struct Entry8E9* __cdecl FUN_00477900(unsigned long formType, unsigned long* outHolder);   

void* __stdcall FUN_008e9780(struct Manager8E9* manager) {
    Holder8E9 holder;                          
                                                   

    if (manager != 0) {      
        for (int index = 0; index < manager->count; ++index) {          
            if (manager->records[index].formType == 0x1300) {           
                struct Entry8E9* entry = manager->FUN_00477900(&holder,0x1300);   
                return entry->resolver->resolvedC0;                     
            }
        }
    }

    return 0;                                      
}

}



}   // namespace f3m_008e9780

// @f3 0x008f7b50 (community match, verified in this file)
namespace ns_008f7b50 {

void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ecc0(void* ptr);

struct Color3 {
    int r, g, b;
};

extern Color3 DAT_00f7a030[];
extern bool DAT_010f3178;

struct FUN_00a75730_cls {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    Color3 color;
    int unk34, unk38, unk3c, unk40;
    int rev;
    int unk48;
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* ptr) { FUN_0089ecc0(ptr); }
    FUN_00a75730_cls();
};

struct Target {
    void FUN_004236f0(FUN_00a75730_cls* prop);
};

struct Owner {
    int unk00, unk04, unk08, unk0c;
    unsigned int flags;
    void FUN_008f7b50(Target* target);
};

// pdb: bhkUtilFunctions::PrepareDebugGeom | bhkUtilFunctions.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apDebugGeom, apParent, aeMat, arDefColor
void Owner::FUN_008f7b50(Target* target)
{
    if (target && DAT_010f3178) {
        Color3 c = DAT_00f7a030[flags & 0x1f];
        FUN_00a75730_cls* prop = new FUN_00a75730_cls();
        prop->rev += 1;
        prop->color = c;
        target->FUN_004236f0(prop);
    }
}

}

// @f3 0x008e94c0 (community match, verified in this file)
#include <math.h>

namespace ns_008e94c0 {

struct Vec3 {
    float x, y, z;
    __forceinline float LengthSquared() const { return x * x + y * y + z * z; }
    __forceinline float Length() const { return (float)sqrt(LengthSquared()); }
};

struct Sphere {
    float x, y, z, r;
};

extern Sphere DAT_0108edc8;

struct Target {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Sphere* sphere;
    const Sphere* GetSphere() const { return sphere ? sphere : &DAT_0108edc8; }
};

__forceinline float MaxF(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

struct Owner {
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
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c;
    int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488;
    float value48C;
    void FUN_008e94c0(const Vec3* pos, const Target* target);
};

void Owner::FUN_008e94c0(const Vec3* pos, const Target* target)
{
    if (target) {
        Sphere s = *target->GetSphere();
        Vec3 d;
        d.x = pos->x - s.x;
        d.y = pos->y - s.y;
        d.z = pos->z - s.z;
        value48C = MaxF(d.Length() - s.r, 0.0f);
    }
}

}

// @f3 0x008e2af0 (community match, verified in this file)
namespace f3m_008e2af0 {
struct Flagged_8e2af0
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
    unsigned int flags30;
    void SetHidden(bool show)
    {
        if (!show)
            flags30 |= 1;
        else
            flags30 &= ~1;
    }
};
struct Group_8e2af0
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
    Flagged_8e2af0** items;
};
struct Target_8e2af0
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
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc(Group_8e2af0* group, int flag);
    virtual void ve0();
    virtual void ve4();
    virtual void ve8(Group_8e2af0* group);
};
struct Source_8e2af0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Target_8e2af0* v0c();
};
struct Owner_8e2af0
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
    Source_8e2af0* unk58;
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
    Group_8e2af0* unk84;
    void FUN_008e2af0(bool a, bool b, bool c);
};
// pdb: bhkRagdollController::UpdateDebugSkeleton | bhkRagdollController.obj | fnv360_0822_retail, call_gap, low
// pdb params: abKeyframed, abRagdoll, abFinal
void Owner_8e2af0::FUN_008e2af0(bool a, bool b, bool c)
{
    unk84->items[0]->SetHidden(a);
    unk84->items[1]->SetHidden(b);
    unk84->items[2]->SetHidden(c);
    Target_8e2af0* target = unk58->v0c();
    if (target)
    {
        if (!a && !b && !c)
        {
            target->ve8(unk84);
        }
        else
        {
            Group_8e2af0* group = unk84;
            if (group->unk18 == 0)
                target->vdc(group, 1);
        }
    }
}
}   // namespace f3m_008e2af0

// @f3 0x008f2280 (community match, verified in this file)
namespace f3m_008f2280 {
namespace ns_008f2280 {

struct ConstraintData {
  virtual void v00();
  virtual void v04();
  virtual void v08();
  virtual void v0C();
  virtual int GetType();
  int unk04;
  int unk08;
  int unk0C;
  int unk10;
  int unk14;
  int unk18;
  unsigned short index1C;
};

struct ConstraintOwner {
  int unk00;
  int unk04;
  int unk08;
  int unk0C;
  int unk10;
  int unk14;
  int unk18;
  char* flags1C;
};

struct Node;

struct ConstraintInstance {
  int unk00;
  int unk04;
  int unk08;
  ConstraintData* data0C;
  int unk10;
  Node* entityA;
  Node* entityB;
  int unk1C;
  int unk20;
  int unk24;
  ConstraintOwner* owner28;
};

struct ConstraintEntry {
  ConstraintInstance* inst;
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
};

struct Node {
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
  ConstraintEntry* arr98;
  unsigned short count9C;
};

} // namespace ns_008f2280

// pdb: bhkUtilFunctions::FindConstrainedSystemRoot | bhkUtilFunctions.obj | fnv360_1110_retail, objrun_prop, low
// pdb params: apBody
extern "C" int __cdecl FUN_008f2280(int a) {
  ns_008f2280::Node* node = (ns_008f2280::Node*)a;
restart:
  bool all11 = true;
  for (int i = 0; i < node->count9C; ++i) {
    if (!all11) break;
    ns_008f2280::ConstraintData* d = node->arr98[i].inst->data0C;
    all11 = (d->GetType() == 11);
  }
  if (all11) return (int)node;

  for (int j = 0; j < node->count9C; ++j) {
    ns_008f2280::ConstraintInstance* inst = node->arr98[j].inst;
    if (inst->data0C->GetType() != 11) {
      bool skip = false;
      if (inst->data0C->GetType() == 12) {
        skip = (inst->owner28->flags1C[inst->data0C->index1C] != 0);
      }
      if (!skip) {
        ns_008f2280::Node* next = inst->entityA;
        if (next == node) next = inst->entityB;
        node = next;
        goto restart;
      }
    }
  }
  return (int)node;
}
}   // namespace f3m_008f2280

// @f3 0x008ecfc0 (community match, verified in this file)
namespace f3m_008ecfc0 {
namespace Small539 {
struct Heap {void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct Ref {virtual void Slot0();virtual void Destroy();volatile long refs;};
struct Item {Ref* reference;};
struct Node {Item* item;Node* next;void FUN_006c8220();};
struct Owner {unsigned unk000;unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;unsigned unk02c;unsigned unk030;unsigned unk034;unsigned unk038;unsigned unk03c;unsigned unk040;unsigned unk044;unsigned unk048;unsigned unk04c;unsigned unk050;unsigned unk054;unsigned unk058;unsigned unk05c;unsigned unk060;unsigned unk064;unsigned unk068;unsigned unk06c;unsigned unk070;unsigned unk074;unsigned unk078;unsigned unk07c;unsigned unk080;unsigned unk084;unsigned unk088;unsigned unk08c;unsigned unk090;unsigned unk094;unsigned unk098;unsigned unk09c;unsigned unk0a0;unsigned unk0a4;unsigned unk0a8;unsigned unk0ac;unsigned unk0b0;unsigned unk0b4;unsigned unk0b8;unsigned unk0bc;unsigned unk0c0;unsigned unk0c4;unsigned unk0c8;unsigned unk0cc;unsigned unk0d0;unsigned unk0d4;unsigned unk0d8;unsigned unk0dc;unsigned unk0e0;unsigned unk0e4;unsigned unk0e8;unsigned unk0ec;unsigned unk0f0;unsigned unk0f4;unsigned unk0f8;unsigned unk0fc;unsigned unk100;unsigned unk104;unsigned unk108;unsigned unk10c;unsigned unk110;unsigned unk114;unsigned unk118;unsigned unk11c;unsigned unk120;unsigned unk124;unsigned unk128;unsigned unk12c;unsigned unk130;unsigned unk134;unsigned unk138;unsigned unk13c;unsigned unk140;unsigned unk144;unsigned unk148;unsigned unk14c;unsigned unk150;unsigned unk154;unsigned unk158;unsigned unk15c;unsigned unk160;unsigned unk164;unsigned unk168;unsigned unk16c;unsigned unk170;unsigned unk174;unsigned unk178;unsigned unk17c;unsigned unk180;unsigned unk184;unsigned unk188;unsigned unk18c;unsigned unk190;unsigned unk194;unsigned unk198;unsigned unk19c;unsigned unk1a0;unsigned unk1a4;unsigned unk1a8;unsigned unk1ac;unsigned unk1b0;unsigned unk1b4;unsigned unk1b8;unsigned unk1bc;unsigned unk1c0;unsigned unk1c4;unsigned unk1c8;unsigned unk1cc;unsigned unk1d0;unsigned unk1d4;unsigned unk1d8;unsigned unk1dc;unsigned unk1e0;unsigned unk1e4;unsigned unk1e8;unsigned unk1ec;unsigned unk1f0;unsigned unk1f4;unsigned unk1f8;unsigned unk1fc;unsigned unk200;unsigned unk204;unsigned unk208;unsigned unk20c;unsigned unk210;unsigned unk214;unsigned unk218;unsigned unk21c;unsigned unk220;unsigned unk224;unsigned unk228;unsigned unk22c;unsigned unk230;unsigned unk234;unsigned unk238;unsigned unk23c;unsigned unk240;unsigned unk244;unsigned unk248;unsigned unk24c;unsigned unk250;unsigned unk254;unsigned unk258;unsigned unk25c;unsigned unk260;unsigned unk264;unsigned unk268;unsigned unk26c;unsigned unk270;unsigned unk274;unsigned unk278;unsigned unk27c;unsigned unk280;unsigned unk284;unsigned unk288;unsigned unk28c;unsigned unk290;unsigned unk294;unsigned unk298;unsigned unk29c;unsigned unk2a0;unsigned unk2a4;unsigned unk2a8;unsigned unk2ac;unsigned unk2b0;unsigned unk2b4;unsigned unk2b8;unsigned unk2bc;unsigned unk2c0;unsigned unk2c4;unsigned unk2c8;unsigned unk2cc;unsigned unk2d0;unsigned unk2d4;unsigned unk2d8;unsigned unk2dc;unsigned unk2e0;unsigned unk2e4;unsigned unk2e8;unsigned unk2ec;unsigned unk2f0;unsigned unk2f4;unsigned unk2f8;unsigned unk2fc;unsigned unk300;unsigned unk304;unsigned unk308;unsigned unk30c;unsigned unk310;unsigned unk314;unsigned unk318;unsigned unk31c;unsigned unk320;unsigned unk324;unsigned unk328;unsigned unk32c;unsigned unk330;unsigned unk334;unsigned unk338;unsigned unk33c;unsigned unk340;unsigned unk344;unsigned unk348;unsigned unk34c;unsigned unk350;unsigned unk354;unsigned unk358;unsigned unk35c;unsigned unk360;unsigned unk364;unsigned unk368;unsigned unk36c;unsigned unk370;unsigned unk374;unsigned unk378;unsigned unk37c;unsigned unk380;unsigned unk384;unsigned unk388;unsigned unk38c;unsigned unk390;unsigned unk394;unsigned unk398;unsigned unk39c;unsigned unk3a0;unsigned unk3a4;unsigned unk3a8;unsigned unk3ac;unsigned unk3b0;unsigned unk3b4;unsigned unk3b8;unsigned unk3bc;unsigned unk3c0;unsigned unk3c4;unsigned unk3c8;unsigned unk3cc;unsigned unk3d0;unsigned unk3d4;unsigned unk3d8;unsigned unk3dc;unsigned unk3e0;unsigned unk3e4;unsigned unk3e8;unsigned unk3ec;unsigned unk3f0;unsigned unk3f4;unsigned unk3f8;unsigned unk3fc;unsigned unk400;unsigned unk404;unsigned unk408;unsigned unk40c;unsigned unk410;unsigned unk414;unsigned unk418;unsigned unk41c;unsigned unk420;unsigned unk424;unsigned unk428;unsigned unk42c;unsigned unk430;unsigned unk434;unsigned unk438;unsigned unk43c;unsigned unk440;unsigned unk444;unsigned unk448;unsigned unk44c;unsigned unk450;unsigned unk454;unsigned unk458;unsigned unk45c;unsigned unk460;unsigned unk464;unsigned unk468;unsigned unk46c;unsigned unk470;unsigned unk474;unsigned unk478;unsigned unk47c;unsigned unk480;unsigned unk484;unsigned unk488;unsigned unk48c;unsigned unk490;unsigned unk494;unsigned unk498;unsigned unk49c;unsigned unk4a0;unsigned unk4a4;unsigned unk4a8;unsigned unk4ac;unsigned unk4b0;unsigned unk4b4;unsigned unk4b8;unsigned unk4bc;unsigned unk4c0;unsigned unk4c4;unsigned unk4c8;unsigned unk4cc;unsigned unk4d0;unsigned unk4d4; Node head;void FUN_008ecfc0();};
// pdb: bhkCharacterController::ClearHurtfulHits | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
void Owner::FUN_008ecfc0(){while(head.next||head.item){Item* item=head.item;if(item){Ref* p=item->reference;if(p&&::InterlockedDecrement(&p->refs)==0)p->Destroy();DAT_01090a78.FUN_0086ba60(item);}Node* next=head.next;if(next){head.next=next->next;head.item=next->item;next->next=0;next->FUN_006c8220();DAT_01090a78.FUN_0086ba60(next);}else head.item=0;}}
}
}   // namespace f3m_008ecfc0

// @f3 0x008febc0 (community match, verified in this file)
namespace ns_8febc0 {
__declspec(align(16)) struct hkVector4
{
    float x, y, z, w;
    void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};
struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};
struct hkTransform;
extern hkTransform DAT_010f3370;
struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransform& localToWorld, float tolerance, hkAabb& out);
};
struct Collidable
{
    Shape* m_shape;
    Shape* getShape() { return m_shape; }
};
struct Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Collidable m_collidable;
    Collidable* getCollidable() { return &m_collidable; }
};
struct Owner
{
    int unk00;
    int unk04;
    Body* m_body;
    Body* GetBody() { return this ? m_body : 0; }
    Shape* GetShape()
    {
        Body* body = GetBody();
        Collidable* collidable = body ? body->getCollidable() : 0;
        return collidable ? collidable->getShape() : 0;
    }
    void FUN_008febc0(hkAabb& out);
};
// pdb: bhkRigidBody::GetAabbLocal | bhkRigidBody.obj | fnv360_0721_beta, objrun, low
// pdb params: arOut
void Owner::FUN_008febc0(hkAabb& out)
{
    Shape* shape = GetShape();
    if (shape)
    {
        shape->getAabb(DAT_010f3370, 0.001f, out);
    }
    else
    {
        hkVector4 ext;
        ext.set(0.001f, 0.001f, 0.001f);
        out.m_min.set(-ext.x, -ext.y, -ext.z);
        out.m_max.set(ext.x, ext.y, ext.z);
    }
}
}

// @f3 0x008e34c0 (community match, verified in this file)
extern void* DAT_010f31e4;                           
extern void* DAT_010f3220;                           
extern void* DAT_0108f200;                           
namespace f3m_008e34c0 {

namespace f3m_008e34c0 {

struct Holder8E3;                                    
struct Collision8E3;                                 



struct Collision8E3 { unsigned unk00,unk04,unk08,unk0c; void* key10; };   

struct Holder8E3 {                                   

    unsigned unk00;unsigned unk04;unsigned unk08;unsigned unk0c;unsigned unk10;unsigned unk14;unsigned unk18;unsigned unk1c;unsigned unk20;unsigned unk24;unsigned unk28;unsigned unk2c;unsigned unk30;unsigned unk34;unsigned unk38;unsigned unk3c;unsigned unk40;unsigned unk44;unsigned unk48;unsigned unk4c;unsigned unk50;unsigned unk54;unsigned unk58;unsigned unk5c;unsigned unk60;unsigned unk64;unsigned unk68;unsigned unk6c;unsigned unk70;unsigned unk74;unsigned unk78;unsigned unk7c;unsigned unk80;unsigned unk84;unsigned unk88;unsigned unk8c;unsigned unk90;unsigned unk94;unsigned unk98;unsigned unk9c;                               
    void** arrayA0;                                  
    unsigned short unkA4;                                   
    unsigned short countA6;                          
};                                                   

extern "C" struct Collision8E3* FUN_007235f0(void* object);   

extern "C" void* FUN_00424d50(void* table, void* key);         

extern "C" void bhkRagdollController_AddToArrays(void* item, void* second, void* third);   

// pdb: bhkRagdollController::FindBones | bhkRagdollController.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apObject, arRigidBodies, arConstraints
void FUN_008e34c0(void* first, void* second, void* third) {   
    if (first == 0) return;                          

    struct Collision8E3* collision = FUN_007235f0(first);   
    void* secondParameter = second;                  

    void* thirdParameter = third;                    

    if (collision != 0) {                            
        void* firstLookup = FUN_00424d50(&DAT_010f31e4, collision);   
        collision = (Collision8E3*)collision->key10;
        void* secondLookup = FUN_00424d50(&DAT_010f3220, collision);   

        if (secondLookup != 0 && firstLookup == 0) {  

            bhkRagdollController_AddToArrays(secondLookup, secondParameter, thirdParameter);   
        }                                           

    }                                               

    struct Holder8E3* holder = (struct Holder8E3*)FUN_00424d50(&DAT_0108f200, first);   

    if (holder != 0) {                               
        for (unsigned int index = 0; index < (unsigned int)holder->countA6; ++index) {   

            void* element = holder->arrayA0[index];  
            FUN_008e34c0(element, secondParameter, thirdParameter);   

        }                                           

    }                                               

}                                                    

}                                                    



}   // namespace f3m_008e34c0

// @f3 0x008e98a0 (community match, verified in this file)
namespace f3m_008e98a0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace f3m_008e98a0 {
struct Object {
 virtual void v00();
 virtual void Destroy();
 long references;
};
struct Ptr {
 Object* value;
 Ptr():value(0){}
 ~Ptr(){if(value && !InterlockedDecrement(&value->references)) value->Destroy();}
 operator Object*()const{return value;}
};
struct Owner {
 unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c; unsigned unk140; unsigned unk144; unsigned unk148; unsigned unk14c; unsigned unk150; unsigned unk154; unsigned unk158; unsigned unk15c; unsigned unk160; unsigned unk164; unsigned unk168; unsigned unk16c; unsigned unk170; unsigned unk174; unsigned unk178; unsigned unk17c; unsigned unk180; unsigned unk184; unsigned unk188; unsigned unk18c; unsigned unk190; unsigned unk194; unsigned unk198; unsigned unk19c; unsigned unk1a0; unsigned unk1a4; unsigned unk1a8; unsigned unk1ac; unsigned unk1b0; unsigned unk1b4; unsigned unk1b8; unsigned unk1bc; unsigned unk1c0; unsigned unk1c4; unsigned unk1c8; unsigned unk1cc; unsigned unk1d0; unsigned unk1d4; unsigned unk1d8; unsigned unk1dc; unsigned unk1e0; unsigned unk1e4; unsigned unk1e8; unsigned unk1ec; unsigned unk1f0; unsigned unk1f4; unsigned unk1f8; unsigned unk1fc; unsigned unk200; unsigned unk204; unsigned unk208; unsigned unk20c; unsigned unk210; unsigned unk214; unsigned unk218; unsigned unk21c; unsigned unk220; unsigned unk224; unsigned unk228; unsigned unk22c; unsigned unk230; unsigned unk234; unsigned unk238; unsigned unk23c; unsigned unk240; unsigned unk244; unsigned unk248; unsigned unk24c; unsigned unk250; unsigned unk254; unsigned unk258; unsigned unk25c; unsigned unk260; unsigned unk264; unsigned unk268; unsigned unk26c; unsigned unk270; unsigned unk274; unsigned unk278; unsigned unk27c; unsigned unk280; unsigned unk284; unsigned unk288; unsigned unk28c; unsigned unk290; unsigned unk294; unsigned unk298; unsigned unk29c; unsigned unk2a0; unsigned unk2a4; unsigned unk2a8; unsigned unk2ac; unsigned unk2b0; unsigned unk2b4; unsigned unk2b8; unsigned unk2bc; unsigned unk2c0; unsigned unk2c4; unsigned unk2c8; unsigned unk2cc; unsigned unk2d0; unsigned unk2d4; unsigned unk2d8; unsigned unk2dc; unsigned unk2e0; unsigned unk2e4; unsigned unk2e8; unsigned unk2ec; unsigned unk2f0; unsigned unk2f4; unsigned unk2f8; unsigned unk2fc; unsigned unk300; unsigned unk304; unsigned unk308; unsigned unk30c; unsigned unk310; unsigned unk314; unsigned unk318; unsigned unk31c; unsigned unk320; unsigned unk324; unsigned unk328; unsigned unk32c; unsigned unk330; unsigned unk334; unsigned unk338; unsigned unk33c; unsigned unk340; unsigned unk344; unsigned unk348; unsigned unk34c; unsigned unk350; unsigned unk354; unsigned unk358; unsigned unk35c; unsigned unk360; unsigned unk364; unsigned unk368; unsigned unk36c; unsigned unk370; unsigned unk374; unsigned unk378; unsigned unk37c; unsigned unk380; unsigned unk384; unsigned unk388; unsigned unk38c; unsigned unk390; unsigned unk394; unsigned unk398; unsigned unk39c; unsigned unk3a0; unsigned unk3a4; unsigned unk3a8; unsigned unk3ac; unsigned unk3b0; unsigned unk3b4; unsigned unk3b8; unsigned unk3bc; unsigned unk3c0; unsigned unk3c4; unsigned unk3c8; unsigned unk3cc; unsigned unk3d0; unsigned unk3d4; unsigned unk3d8; unsigned unk3dc; unsigned unk3e0; unsigned unk3e4; unsigned unk3e8; unsigned unk3ec; unsigned unk3f0; unsigned unk3f4; unsigned unk3f8; unsigned unk3fc; unsigned unk400; unsigned unk404; unsigned unk408; unsigned unk40c; unsigned unk410; unsigned unk414; unsigned unk418; unsigned unk41c; unsigned unk420; unsigned unk424; unsigned unk428; unsigned unk42c;
 int index;
 unsigned unk434;
 Ptr values[2];
 Object* FUN_008e98a0();
};
Object* Owner::FUN_008e98a0(){
 return index<2 ? (const Ptr&)values[index] : (const Ptr&)Ptr();
}
}
}   // namespace f3m_008e98a0

// @f3 0x008ed3e0 (community match, verified in this file)
extern double DAT_00db7de8;
namespace f3m_008ed3e0 {
namespace f3m_008ed3e0 {
struct Mover:task2126::Mover8 {void bhkCharacterController_SetSize(float);};
inline double Cap(float value,double maximum){return value>maximum?(double)(float)maximum:(double)value;}
// pdb: bhkCharacterController::SetSize | bhkCharacterController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
void Mover::bhkCharacterController_SetSize(float input){
 double value;
 if(flags294&1)return;
 double maximum=*reinterpret_cast<float*>(&unk484)*DAT_00db7de8;
 value=Cap(input,maximum);
 input=(float)(value<=0.0f?unk480:value);
 if(input!=unk488){
  if(unk434==2){unk434=unk430;FUN_008ed0a0(0);}
  unk490=2;unk488=input;
 }
}
}



}   // namespace f3m_008ed3e0

// @f3 0x008f2150 (community match, verified in this file)
namespace f3m_008f2150 {
namespace f3m_008f2150 {
using namespace f3m_008f1880;
void FUN_008f2150(Item* item,unsigned value){
 if(!item)return;
 Scene* scene=FUN_00424fe0(item);
 if(scene && scene->unk10){
  Tgt* target=scene->unk10;
  Form* form=target->unk08;
  Hdr* header=form?&form->unk10:0;
  unsigned old=header?header->unk1c:0;
  unsigned flags=old^((old^value)&0x7f);
  header=form?&form->unk10:0;
  if(header)header->unk1c=flags;
  target->v30();
 }
 Cont* node=item->GetCont();
 if(node){for(unsigned i=0;i<node->unkA6;++i)FUN_008f2150(node->unkA0[i],value);}
}
}
}   // namespace f3m_008f2150

// @f3 0x008f7730 (community match, verified in this file)
namespace f3m_008f7730 {

struct Heap8f77 { void* FUN_0086b930(unsigned int bytes); };
extern Heap8f77 DAT_01090a78;

void* __cdecl FUN_0089eb90(unsigned int size);

struct Pt8f77 { float x, y, z; };
struct Vec4_8f77 { float x, y, z, w; };
struct Tri8f77 { int a, b, c; };

struct SourceMesh8f77 {
    Vec4_8f77* unk00;
    unsigned int unk04;
    unsigned int unk08;
    Tri8f77* unk0c;
    unsigned int unk10;
};

struct Normals8f77 { void FUN_00830d30(bool flag); };

struct Alloc8f77 { static void* operator new(unsigned int size) { return FUN_0089eb90(size); } };

extern const char* DAT_00e207a8;
extern long (__stdcall *DAT_00d9b064)(long*);
const char* __cdecl FUN_008242a0(const char* input);

struct Nm8f77 {
    const char* value;
    Nm8f77(const char* input) : value(FUN_008242a0(input)) {}
    ~Nm8f77() {
        if (value != DAT_00e207a8)
            DAT_00d9b064(reinterpret_cast<long*>(const_cast<char*>(value) - 8));
    }
};

struct FUN_0083f490 : Alloc8f77 {
    char pad[0xb8];
    Normals8f77* unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    FUN_0083f490(unsigned short vertexCount, Pt8f77* vertices, int a, int b, int c, int d, int e,
                 unsigned short triCount, unsigned short* indices);
    void FUN_008245d0(const void* name);
};

extern void (__cdecl* DAT_010f2c24)(void*);

struct Itf8f77 { void** table; };

struct Builder8f77 {
    void FUN_008f7730(Itf8f77* receiver, SourceMesh8f77* mesh, const char* name);
};

// pdb: bhkShape::BuildDisplayFromhkGeometry | bhkShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkNiTriStripsShape::BuildDisplayGeometry)
// pdb params: apNode, apGeom, arDefColor, apName
void Builder8f77::FUN_008f7730(Itf8f77* receiver, SourceMesh8f77* mesh, const char* name)
{
    if (mesh)
    {
        unsigned int vertexCount = mesh->unk04;
        unsigned int triangleCount = mesh->unk10;
        if (vertexCount && triangleCount)
        {
            Pt8f77* vertices = new Pt8f77[vertexCount];
            unsigned short* indices = new unsigned short[triangleCount * 3];
            double scale = ::DAT_00db88e8;
            for (unsigned int i = 0; i < vertexCount; ++i)
            {
                const Vec4_8f77* source = &mesh->unk00[i];
                Pt8f77* target = &vertices[i];
                float fx = source->x;
                target->x = scale * fx;
                float fy = source->y;
                target->y = scale * fy;
                float fz = source->z;
                target->z = scale * fz;
            }
            for (unsigned int j = 0; j < triangleCount; ++j)
            {
                Tri8f77 triangle = mesh->unk0c[j];
                indices[j * 3] = (unsigned short)triangle.a;
                indices[j * 3 + 1] = (unsigned short)triangle.b;
                indices[j * 3 + 2] = (unsigned short)triangle.c;
            }
            FUN_0083f490* shape = new FUN_0083f490((unsigned short)vertexCount, vertices, 0, 0, 0, 0, 0,
                                                   (unsigned short)triangleCount, indices);
            if (name)
            {
                Nm8f77 temp(name);
                shape->FUN_008245d0(&temp);
            }
            shape->unkb8->FUN_00830d30(true);
            reinterpret_cast<void (__thiscall*)(Builder8f77*, void*)>(
                reinterpret_cast<Itf8f77*>(this)->table[54])(this, shape);
            if (DAT_010f2c24)
                DAT_010f2c24(shape);
            reinterpret_cast<void (__thiscall*)(Itf8f77*, void*, int)>(
                receiver->table[55])(receiver, shape, 1);
        }
    }
}

}

void* __cdecl operator new[](unsigned int size)
{
    return f3m_008f7730::DAT_01090a78.FUN_0086b930(size);
}

// @f3 0x008f1b30 (community match, verified in this file)
namespace f3m_008f1b30 {
namespace f3ns_008f1b30 {
struct Sub { int unk00; };
struct Inner {
    unsigned value;
    int type;
};
struct Base {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0c(); virtual void v10();
    virtual Sub* converted();
    int unk04;
    Inner inner;
};
struct Derived : Base, Sub {};
struct Holder {
    Base* base;
    int unk04;
    int unk08;
    Holder* other;
};
// pdb: bhkUtilFunctions::FindbhkShapeCollection | bhkUtilFunctions.obj | fnv360_0822_retail, call_gap, medium
// pdb params: arBody
unsigned FUN_008f1b30(Holder* input) {
    Holder* holder = input->other;
    if (!holder) holder = input;
    unsigned result = 0;
    if (holder) {
        Base* base = holder->base;
        Inner* in = &base->inner;
        if (in->type == 9 || in->type == 11) {
            Sub* sub = base->converted();
            Derived* d = static_cast<Derived*>(sub);
            if (d) return d->inner.value;
            return 0;
        }
        if (base && in->type == 10)
            result = base->inner.value;
    }
    return result;
}
}
}   // namespace f3m_008f1b30

// @f3 0x008e9800 (community match, verified in this file)
namespace f3m_008e9800 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace Reset355 {
struct Ref{virtual void v0();virtual void destroy();volatile long refs;void IncRef();void release(){if(!InterlockedDecrement(&refs))destroy();}};
struct Ptr{Ref* p;Ptr():p(0){}~Ptr(){if(p)p->release();}
    Ptr& operator=(Ref* r){if(p!=r){if(r)r->IncRef();Ref* old=p;p=r;if(old)old->release();}return *this;}};
struct Vec{float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}~Vec(){}};
struct FUN_008e9800{Ptr ptr;Vec a,b,c;FUN_008e9800();};
FUN_008e9800::FUN_008e9800(){ptr=0;a=Vec(0.0f,0.0f,0.0f);b=Vec(0.0f,0.0f,0.0f);c=Vec(0.0f,0.0f,0.0f);}
}
}   // namespace f3m_008e9800

// @f3 0x008ec480 (community match, verified in this file)
extern float DAT_010f2e8c;
namespace f3m_008ec480 {
namespace f3m_008ec480 {
struct Part { unsigned unk00, unk04; float FUN_008f8410(); };
struct Object {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    volatile unsigned flags2c;
    unsigned unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    unsigned unkc0, unkc4, unkc8, unkcc;
    Part part;
    unsigned char kind;
    unsigned Type() const { return flags2c & 0x7f; }
};
// pdb: bhkCharacterController::IsHurtfulBody | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkCharProxyController::objectInteractionCallback)
// pdb params: apBody
bool __cdecl FUN_008ec480(Object* object)
{
    bool result = false;
    if (object) {
        int kind = object->kind;
        float value;
        if ((kind < 6 || kind == 8) && (value = object->part.FUN_008f8410(), value > DAT_010f2e8c))
            result = true;
        else if (object->Type() == 6)
            result = true;
    }
    return result;
}
}
}   // namespace f3m_008ec480

// @f3 0x008fe330 (community match, verified in this file)
extern const char* DAT_010f3214;
extern double DAT_00db88e8;
namespace f3m_008fe330 {

struct StrArr {
    int unk00;
    int unk04;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_00555790(unsigned int newCapacity);
    void FUN_005b3880(unsigned int index, char** item);
    void Add(char* item)
    {
        unsigned int n = size;
        if (n >= capacity)
            FUN_00555790(growBy + n);
        FUN_005b3880(n, &item);
    }
};

char* __cdecl FUN_00847b50(const char* name);

struct Vector3 {
    float x, y, z;
    char* FUN_00823dc0(const char* label);
};

struct Rotation3 {
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    char* FUN_00823bc0(const char* label);
};

struct Transform {
    Rotation3 rotation;
    Vector3 translation;
    float scale;
};

struct Vec4 {
    float x, y, z, w;
};

struct HkTransform {
    Vec4 col0;
    Vec4 col1;
    Vec4 col2;
    Vec4 translation;
};

extern HkTransform DAT_010f3370;
void __cdecl FUN_0056ac90(Transform* dst, const HkTransform* src);

struct Receiver {
    void** table;
};

struct Callback {
    unsigned int unk00;
    unsigned int unk04;
    Receiver* receiver;
};

struct Data {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Callback* callback;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    HkTransform transform;
};

struct Owner {
    unsigned int unk00;
    unsigned int unk04;
    Data* data;
    void FUN_008f7a20(StrArr* out);
    void FUN_008fe330(StrArr* out);
};

// pdb: bhkTransformShape::GetViewerStrings | bhkTransformShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Owner::FUN_008fe330(StrArr* out)
{
    FUN_008f7a20(out);
    out->Add(FUN_00847b50(DAT_010f3214));
    const HkTransform* world = (this && data) ? &data->transform : &DAT_010f3370;
    Transform local;
    FUN_0056ac90(&local, world);
    local.translation.x = world->translation.x * DAT_00db88e8;
    local.translation.y = world->translation.y * DAT_00db88e8;
    local.translation.z = world->translation.z * DAT_00db88e8;
    out->Add(local.translation.FUN_00823dc0("Trans"));
    out->Add(local.rotation.FUN_00823bc0("Rot"));
    if (this && data && data->callback && data->callback->receiver) {
        Receiver* target = data->callback->receiver;
        typedef void (__thiscall* ViewerFn)(Receiver*, StrArr*);
        reinterpret_cast<ViewerFn>(target->table[24])(target, out);
    }
}

}

// @f3 0x008fbce0 (community match, verified in this file)
namespace ns_008fbce0 {

struct ErrorReporter8fbce0 {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Report(int severity, unsigned int id, const char* message, const char* file, int line);
};

struct WriterFlag8fbce0 {
    bool value;
    WriterFlag8fbce0(bool enabled) : value(enabled) {}
};

struct FUN_00943ae0 {
    void* vtable;
    unsigned short flags;
    unsigned short referenceCount;
    void* writer;
    FUN_00943ae0(char* buffer, int length, WriterFlag8fbce0 enabled);
    void FUN_00943a60();
    ~FUN_00943ae0() { FUN_00943a60(); }
    FUN_00943ae0& FUN_00943710(const char* text);
};

struct Stream8fbce0 {
    void* vftable;
    unsigned int fileVersion;
    char userName[4];
    unsigned int f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
    unsigned int f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70;
    unsigned int f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c, fa0, fa4;
    unsigned int fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4, fc8, fcc, fd0, fd4, fd8, fdc;
    char fileName[4];
    void FUN_0082b620();
};

struct Constraint8fbce0 {
    void FUN_008f7ea0(Stream8fbce0* stream);
    void FUN_008fbce0(Stream8fbce0* stream);
};

extern ErrorReporter8fbce0* DAT_010f3364;
extern const char str_00e3462c[];
extern const char str_00e3466c[];
extern const char str_00e34674[];
extern const char str_00e34698[];
extern const char str_00e346a4[];

// pdb: bhkConstraint::LoadCInfo | bhkConstraint.obj | fnv360_0822_debug, objrun, medium
// pdb params: arStream
void Constraint8fbce0::FUN_008fbce0(Stream8fbce0* stream)
{
    if (stream->fileVersion < 6) {
        {
            const char* fileName = stream->fileName;
            const char* user = stream->userName[0] ? stream->userName : str_00e346a4;
            char message[512];
            FUN_00943ae0 writer(message, sizeof(message), true);
            writer.FUN_00943710(str_00e3466c)
                  .FUN_00943710(fileName)
                  .FUN_00943710(str_00e34674)
                  .FUN_00943710(user)
                  .FUN_00943710(str_00e34698);
            DAT_010f3364->Report(1, 0x234f2250, message, str_00e3462c, 0x18b);
        }
        stream->FUN_0082b620();
    }
    FUN_008f7ea0(stream);
}

} // namespace ns_008fbce0

// @f3 0x008fc1b0 (community match, verified in this file)
#include <intrin.h>
#pragma intrinsic(_ReadWriteBarrier)
namespace f3m_008fc1b0 {

namespace ns_008fc1b0 {

struct Physics {
    bool FUN_008d6140(void* item);
};

struct Source {
    int f000, f004, f008, f00c, f010, f014, f018, f01c, f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044, f048, f04c, f050, f054, f058, f05c, f060, f064, f068, f06c, f070, f074, f078, f07c;
    int f080, f084, f088, f08c, f090, f094, f098, f09c, f0a0, f0a4, f0a8, f0ac, f0b0, f0b4, f0b8, f0bc;
    int f0c0, f0c4, f0c8, f0cc, f0d0, f0d4, f0d8, f0dc, f0e0, f0e4, f0e8, f0ec, f0f0, f0f4, f0f8, f0fc;
    int f100, f104, f108, f10c, f110, f114, f118, f11c, f120, f124, f128, f12c, f130, f134, f138, f13c;
    int f140, f144, f148, f14c, f150, f154, f158, f15c, f160, f164, f168, f16c, f170, f174, f178, f17c;
    int f180, f184, f188, f18c, f190, f194, f198, f19c, f1a0, f1a4, f1a8, f1ac, f1b0, f1b4, f1b8, f1bc;
    int f1c0, f1c4, f1c8, f1cc, f1d0, f1d4, f1d8, f1dc, f1e0, f1e4, f1e8, f1ec, f1f0, f1f4, f1f8, f1fc;
    int f200, f204, f208, f20c, f210, f214, f218, f21c, f220, f224, f228, f22c, f230, f234, f238, f23c;
    int f240, f244, f248, f24c, f250, f254, f258, f25c, f260, f264, f268, f26c, f270, f274, f278, f27c;
    int f280, f284, f288, f28c, f290, f294, f298, f29c, f2a0, f2a4, f2a8, f2ac, f2b0, f2b4, f2b8, f2bc;
    int f2c0, f2c4, f2c8, f2cc, f2d0, f2d4, f2d8, f2dc, f2e0, f2e4, f2e8, f2ec, f2f0, f2f4, f2f8, f2fc;
    int f300, f304, f308, f30c;
    Physics* physics;
};

struct Object {
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
    virtual Source* GetSource();
    virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void Associate(Physics* physics, int arg);
    int f04;
    void* item;
    bool FUN_008fc1b0();
};

// pdb: bhkConstraint::Remove | bhkConstraint.obj | fnv360_0822_retail, objrun_open, low
bool Object::FUN_008fc1b0()
{
    bool result = false;
    Source* source = GetSource();
    Physics* physics = source ? source->physics : 0;
    _ReadWriteBarrier();
    if (physics) {
        result = physics->FUN_008d6140(item);
        Associate(physics, 0);
    }
    return result;
}

} // namespace ns_008fc1b0
}   // namespace f3m_008fc1b0

// @f3 0x008e8970 (community match, verified in this file)
namespace f3m_008e8970 {
namespace S008e8970_ns {

struct Owner {
    unsigned unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    unsigned unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    unsigned unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    unsigned unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    unsigned unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    unsigned unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    unsigned unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    unsigned unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    unsigned unk3a0, unk3a4, unk3a8, unk3ac, unk3b0;
    float speed;
    float remaining;
    float FUN_008e8970(float value, float delta);
};

float Owner::FUN_008e8970(float value, float delta)
{
    float result = value;
    if (remaining > 0.0f) {
        float rem = remaining;
        float step;
        if (delta < rem)
            step = delta;
        else
            step = rem;
        result += speed * step;
        remaining -= delta;
        speed -= (double)0.05f;
    } else {
        speed = 0.0f;
    }
    return result;
}

}
}   // namespace f3m_008e8970

// @f3 0x008ff4c0 (community match, verified in this file)
namespace f3m_008ff4c0 {
namespace S008ff4c0_ns {
struct Flags
{
    union
    {
        unsigned int raw;
        struct
        {
            unsigned int type : 7;
            unsigned int rest : 25;
        };
    };
};
struct Hdr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Flags flags;
};
struct Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Hdr base;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4;
    unsigned char state;
    void hkpRigidBody_setMotionType(int layer, bool a, int b);
};
inline int IsLowLayer(int layer) { return layer < 6 || layer == 8; }
inline unsigned PickLayerType(char low) { return low ? 0x1d : 8; }
inline bool IsSpecial(unsigned int type) { return type == 8 || type == 0x1d; }
bool __cdecl FUN_0056fab0(int layer);
struct Phantom
{
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
    virtual void vc0();
    int unk04;
    Body* obj;
    Body* GetBody() { return this ? obj : 0; }
    void FUN_00c24b70();
    float FUN_0056f860();
    void Apply(Flags f)
    {
        Body* o2 = GetBody();
        Hdr* b = o2 ? &o2->base : 0;
        if (b)
            b->flags = f;
    }
    bool FUN_008ff4c0(int layer);
};
// pdb: bhkRigidBody::SetMotionType | bhkRigidBody.obj | fnv360_0822_retail, objrun, medium
// pdb params: aeMotion
bool Phantom::FUN_008ff4c0(int layer)
{
    Body* o = GetBody();
    if (o)
    {
        Hdr* b = o ? &o->base : 0;
        Flags flags;
        flags.raw = b ? b->flags.raw : 0;
        if (IsSpecial(flags.type))
        {
            Flags newFlags = flags;
            newFlags.type = PickLayerType(IsLowLayer(layer));
            Apply(newFlags);
            vc0();
            FUN_00c24b70();
            o->hkpRigidBody_setMotionType(layer, true, 0);
            FUN_00c24b70();
            return true;
        }
        int iCurrent = o->state;
        if (iCurrent != layer)
        {
            switch (iCurrent)
            {
            case 6:
            case 7:
                if (FUN_0056fab0(layer) && FUN_0056f860() == 0.0f)
                    return false;
                break;
            }
            FUN_00c24b70();
            o->hkpRigidBody_setMotionType(layer, true, 0);
            FUN_00c24b70();
            return true;
        }
    }
    return false;
}
}
}   // namespace f3m_008ff4c0

// @f3 0x008ee870 (community match, verified in this file)
extern const float DAT_00dcf18c;
namespace f3m_008ee870 {
namespace ns_8ee870 {
struct Anim;
struct Node
{
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
    virtual void v09c(Anim* anim);
    virtual void v0a0();
};
struct Blend;
Blend* __cdecl FUN_00921850(int a, int b, int c, int d);
struct Anim
{
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
    void FUN_008d5730(Node* node, Blend* blend);
};
struct Holder
{
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
    Anim* unk310;
};
struct Info
{
    int unk00;
    int unk04;
    Holder* unk08;
};
struct Slot
{
    int unk00;
    int unk04;
};
struct Data
{
    Info* FUN_0091ddd0();
    Slot* FUN_0091dd50();
};
struct Owner
{
    int unk00;
    int unk04;
    Data* unk08;
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
    unsigned int flags294;
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
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    Node* unk424;
    Node* unk428;
    Node* unk42c;
    Info* GetInfo() { return (this && unk08) ? unk08->FUN_0091ddd0() : 0; }
    Anim* GetCurrent()
    {
        Holder* holder = GetInfo()->unk08;
        return holder ? holder->unk310 : 0;
    }
    bool Flag0() const { return (flags294 & 1) != 0; }
    bool Flag20() const { return (flags294 >> 20) & 1; }
    void FUN_0092ac50();
    void bhkCharacterController_SetSize(float value);
    void FUN_008ea020(float value);
    void bhkCharacterController_SetWorld(Anim* anim);
};
// pdb: bhkCharacterController::SetWorld | bhkCharacterController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Owner::bhkCharacterController_SetWorld(Anim* anim)
{
    Anim* current = GetCurrent();
    if (current != anim)
    {
        if (current)
        {
            current->v098();
            FUN_0092ac50();
            {
                Node* node = unk424;
                if (node)
                    node->v0a0();
            }
            {
                Node* node = unk428;
                if (node)
                    node->v0a0();
            }
            {
                Node* node = unk42c;
                if (node)
                    node->v0a0();
            }
            current->v098();
        }
        if (this && unk08)
            unk08->FUN_0091dd50()->unk04 = 0;
        if (anim)
        {
            if (unk424)
            {
                if (!Flag0() && !Flag20())
                {
                    bhkCharacterController_SetSize(0.001428767223842442f);
                    FUN_008ea020(0.001428767223842442f);
                    bhkCharacterController_SetSize(0.0f);
                }
                unk424->v09c(anim);
                Node* node = unk424;
                Blend* blend = FUN_00921850(0x96, 0x96, 0, 0x19);
                anim->FUN_008d5730(node, blend);
            }
            {
                Node* node = unk428;
                if (node)
                    node->v09c(anim);
            }
            {
                Node* node = unk42c;
                if (node)
                    node->v09c(anim);
            }
        }
    }
}
}
}   // namespace f3m_008ee870

// @f3 0x008e9dd0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008e9dd0 {
namespace State1007 {
struct FUN_008e9900;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
void __cdecl FUN_008e96f0(void*);
struct Heap {
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
 FUN_008e9900* head;
 int count;
 FUN_008e9900* FUN_008f6800(int index,int tag);
};
struct FUN_008e9900 {
 FUN_008e9900* next;
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
 FUN_008e9900(int);
 static __forceinline void* operator new(unsigned int) throw() {
  Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);
  FUN_008e9900* p=heap->head;
  if(p) { --heap->count;heap->head=p->next; return p; }
  return heap->FUN_008f6800(9,0xD);
 }
 static __forceinline void operator delete(void* p) { FUN_008e96f0(p); }
};
struct Owner {
 unsigned int unk00,unk04,unk08;
 FUN_008e9900* state;
 void FUN_0092a9d0(FUN_008e9900*);
 FUN_008e9900* FUN_008e9dd0(unsigned char* created);
};
// pdb: bhkCharacterController::CreateCinfo | bhkCharacterController.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arCreated
FUN_008e9900* Owner::FUN_008e9dd0(unsigned char* created) {
 if(!state) {
  state=new FUN_008e9900(1);
  if(unk08) FUN_0092a9d0(state);
  *created=1;
 } else *created=0;
 return state;
}
}
}   // namespace f3m_008e9dd0

// @f3 0x008fe910 (community match, verified in this file)
namespace f3m_008fe910 {
struct C_8fe910 { int unk00; int unk04; void* unk08; Vec4_8fea20* FUN_008fe910(Vec4_8fea20* out); };
// pdb: bhkRigidBody::GetPosition | bhkRigidBody.obj | fnv360_0721_beta, objrun, medium
// pdb params: arPos
Vec4_8fea20* C_8fe910::FUN_008fe910(Vec4_8fea20* out)
{
    Vec4_8fea20* src;
    if (this) {
        void* const p = unk08;
        src = (Vec4_8fea20*)((char*)p + 0x110);
        if (!p) src = &DAT_01092a50;
    } else {
        src = &DAT_01092a50;
    }
    out->x = src->x; out->y = src->y; out->z = src->z; out->w = src->w;
    return out;
}
}   // namespace f3m_008fe910

// @f3 0x008ec6a0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008ec6a0 {
namespace f3m_008ec6a0 {
struct FreeNode {
    FreeNode* next;
};

struct FreeBucket {
    FreeNode* head;
    int count;
    void Push(FreeNode* b) {
        ++count;
        b->next = head;
        head = b;
    }
};

struct ThreadHeap {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int limit;
    FreeNode* heads[1];
    void FUN_008f6890(int index, FreeNode* block, unsigned int tag);
};

extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct HeldObject {
    ~HeldObject() { FUN_008e9d30(); }
    void FUN_008e9d30();
    static void operator delete(void* p) {
        if (p) {
            ThreadHeap* heap = (ThreadHeap*)DAT_00d9b080(DAT_010f3170);
            FreeBucket* bucket = &((FreeBucket*)&heap->heads)[7];
            FreeNode* block = (FreeNode*)p;
            if (*(volatile int*)&bucket->count >= heap->limit)
                heap->FUN_008f6890(7, block, 0xd);
            else
                bucket->Push(block);
        }
    }
};

struct Owner {
    int unk00, unk04, unk08;
    HeldObject* held;
    void FUN_008ec6a0(bool releaseHeld);
};

// pdb: bhkCharProxyController::contactPointRemovedCallback | bhkCharProxyController.obj | tesv_win, objrun_open, low
void Owner::FUN_008ec6a0(bool releaseHeld) {
    if (releaseHeld) {
        delete held;
        held = 0;
    }
}
}
}   // namespace f3m_008ec6a0

// @f3 0x008e1960 (community match, verified in this file)
#pragma intrinsic(_ReadWriteBarrier)
#include <math.h>
#pragma intrinsic(sqrt)
namespace f3m_008e1960 {
extern "C" void _ReadWriteBarrier();
struct B0Quat { float x, y, z, w; };
struct B0Mat { float m[9]; };
struct B0T12 { float m[12]; };
struct B0Xform { float r[9]; float t[3]; float s; };
struct B0Seq { int unk00; short* unk04; };
struct B0Anim { int unk00; int unk04; int unk08; B0Seq* unkC; int unk10; int unk14; int unk18; B0Quat* unk1C; };
struct B0Node { float unk00; float unk04; float unk08; float unk0C; float unk10; float unk14; float unk18; float unk1C; float unk20; float unk24; float unk28; float unk2C; float unk30; float unk34; float unk38; float unk3C; float unk40; float unk44; float unk48; float unk4C; float unk50; float unk54; float unk58; float unk5C; float unk60; float unk64; B0Xform unk68; };

struct B0Skel {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int* unk10;      // elements of 0x30
    int unk14;
    int unk18;
    int* unk1C;      // flags
    B0Quat* hkaPose_calculateBoneModelSpace(int i);
};

struct B0Tgt {
    int unk00; int unk04; int unk08; int unk0C;
    char* unk10; char* unk14; char* unk18; char* unk1C;
};

extern short FUN_00957b20(B0Seq* a, int b, int c);
struct B0Sub { int unk00; B0Mat* FUN_00424020(B0T12* a, B0Xform* b); };
extern void FUN_008db970(B0T12* a, B0Xform* b);


static inline B0Quat* B0Get(B0Skel* sk, int i) {
    char* e;
    if ((((char*)sk->unk1C)[i * 4] & 2) == 0) e = (char*)sk->unk10 + i * 0x30;
    else e = (char*)sk->hkaPose_calculateBoneModelSpace(i);
    return (B0Quat*)(e + 0x10);
}

struct B0Slot {
    int unk00; short s4; short s6; int unk08; int unk0C;
    float a[4]; float b[4];
    int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C;
};

struct B0Owner {
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
    B0Node* unk58;
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
    short unkB0;
    char unkB2;
    char unkB3;
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
    B0Slot slots[2];
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
    B0Anim* unk2A4;
    bool FUN_008e1960(B0Skel* sk, int a, int idx);
};

__declspec(align(16)) struct B0V4 {
    float x, y, z, w;
    __forceinline void Scale(float s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline void Set(const B0V4& a) { x=a.x; y=a.y; z=a.z; w=a.w; }
    float GetReal() const { return w; }
    float Sc(float a) const { return a * a - 0.5; }
    float Dot3(const B0V4& b) const { return (x * b.x + y * b.y) + z * b.z; }
    void SetMul(float s, const B0V4& d) { x = s * d.x; y = s * d.y; z = s * d.z; w = s * d.w; }
    void AddMul(float s, const B0V4& d) { x += s * d.x; y += s * d.y; z += s * d.z; w += s * d.w; }
    void SetCross(const B0V4& a, const B0V4& b) { x = a.y * b.z - a.z * b.y; y = a.z * b.x - a.x * b.z; z = a.x * b.y - a.y * b.x; }
    __forceinline float LenSq() const { return x * x + y * y + z * z; }
    void SetAdd(const B0V4& a, const B0V4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
};

struct B0Result { float value;B0Result(float v):value((float)v){} void SetInverse(float x){ value=x != 0.0f ? (float)(1.0 / (float)sqrt((double)x)) : 0.0f; } };
// Fake match: one struct for the accumulator and the cross product keeps their two stack slots adjacent.
struct B0RC { B0V4 r; B0V4 c; };

static __forceinline float B0InvLen(float x) { B0Result r(0.0f); r.SetInverse(x); return r.value; }
static __forceinline void B0Rot(const B0Quat* q, float* out, bool ordered) {
    const B0V4& qv = *(const B0V4*)q;
    B0V4 dir; dir.x = 0.0f; dir.y = 1.0f; dir.z = 0.0f; dir.w = 0.0f;
    B0RC t;
    B0V4& r = t.r;
    B0V4& c = t.c;
    float w = qv.GetReal();
    r.SetMul(qv.Sc(w), dir);
    r.AddMul(qv.Dot3(dir), qv);
    // Fake match: the barrier only orders the cross-product loads after the scaled add for the first call; it emits no code.
    if(ordered) _ReadWriteBarrier();
    c.SetCross(dir, qv);
    r.x += w * c.x; r.y += w * c.y; r.z += w * c.z; r.w += w * 0.0f;
    ((B0V4*)out)->SetAdd(r, r);
}

// pdb: bhkRagdollController::InitBoneParams | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apPose, apNodeName, aeBone
bool B0Owner::FUN_008e1960(B0Skel* sk, int a, int idx)
{
    bool ok = true;
    B0Anim* an = unk2A4;
    slots[idx].s4 = FUN_00957b20(an->unkC, a, 0);
    short r = slots[idx].s4;
    if (slots[idx].s4 == -1) ok = false;
    else {
        slots[idx].s6 = unk2A4->unkC->unk04[r];
        if (slots[idx].s6 == -1) ok = false;
    }
    unkB2 = 0;
    if (ok) {
    B0Xform xf = unk58->unk68;
    B0T12 t2;
    B0Mat* m = ((B0Sub*)&unk60)->FUN_00424020(&t2, &xf);
    *(B0Mat*)&xf = *m;
    xf.s = 1.0f;
    FUN_008db970(&t2, &xf);
    B0Quat* qa = B0Get(sk, slots[idx].s4);
    B0Quat* qb = B0Get(sk, slots[idx].s6);
    B0Rot(qb, slots[idx].b, true);
    B0Rot(qa, slots[idx].a, false);
    // Fake match: a named copy of the slot index for the length and the scale. With the parameter itself the
    // y product loads memory first and multiplies by the resident reciprocal; the original duplicates the
    // reciprocal and multiplies by memory for both y and z.
    int i2 = idx;
    B0V4* v = (B0V4*)slots[i2].a;
    float l = v->LenSq();
    float inv = B0InvLen(l);
    slots[i2].a[0] *= inv; slots[i2].a[1] *= inv; slots[i2].a[2] *= inv; slots[i2].a[3] *= inv;
    char* p = (char*)unk2A4->unk1C;
    if (p && idx == 1) {
        B0Quat* p1 = (B0Quat*)(p + 0x10);
        ((B0V4*)slots[1].b)->Set(*(const B0V4*)p1);
        B0Quat* p2 = (B0Quat*)((char*)unk2A4->unk1C + 0x20);
        ((B0V4*)slots[1].a)->Set(*(const B0V4*)p2);
    }
    slots[idx].unk00 = unk88;
    }
    return ok;
}
}   // namespace f3m_008e1960

// @f3 0x008ec4e0 (community match, verified in this file)
#include <intrin.h>
extern unsigned f3_tlsIndex;
namespace f3m_008ec4e0 {
// bhkRagdollController-style destructor: 3 polymorphic bases at 0, 0x260, 0x290,
// then refcounted pointers, a 0x94 chunk, an array and an out-of-line member dtor.


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long idx);

struct f3_VObj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98();
};

struct f3_Ref {
    virtual void r0();
    virtual void r1();
    int m_refCount;
};

struct f3_RefPtr {
    f3_Ref* m_p;
    ~f3_RefPtr() {
        f3_Ref* p = m_p;
        if (p && InterlockedDecrement((volatile long*)&p->m_refCount) == 0)
            p->r1();
    }
};

struct f3_Sub3 {
    virtual ~f3_Sub3() {}
    virtual void s3();
    int a[100];
};

struct f3_Sub2 {
    virtual ~f3_Sub2();
    virtual void s2();
    int a[11];
};

struct f3_Level {
    void* m00;
    void* m04;
    void* m08;
    void* getter();
    void unlock(void* sub);
};

struct f3_Sub1 {
    virtual ~f3_Sub1();
    virtual void s1();
    int m4;
    f3_Level* m8;
    int a[149];
};

struct f3_Heap { void deallocate(void* block, int bytes, unsigned tag); };

extern void f3_release_fn();
extern void __stdcall f3_dealloc_chunk(void* p, unsigned size, unsigned align, void* fn);

struct f3_Chunk {
    int a[37];
    ~f3_Chunk() { f3_dealloc_chunk(this, 4, 2, (void*)&f3_release_fn); }
};

struct f3_Arr {
    void* m_data;
    int m_size;
    int m_capFlags;
    ~f3_Arr() {
        int c = m_capFlags;
        if (!(c & 0x80000000)) {
            int cap = c & 0x3fffffff;
            f3_Heap* heap = (f3_Heap*)TlsGetValue(f3_tlsIndex);
            heap->deallocate(m_data, cap * 64, 0x17);
        }
    }
};

struct f3_Obj4d8 {
    int a[4];
    ~f3_Obj4d8();
};

struct f3_C : f3_Sub1, f3_Sub2, f3_Sub3 {
    f3_RefPtr m424;
    f3_RefPtr m428;
    f3_RefPtr m42c;
    int m430;
    int m434;
    f3_Chunk m438;
    f3_Arr m4cc;
    f3_Obj4d8 m4d8;
    virtual ~f3_C();
};

// pdb: bhkCharacterController::~bhkCharacterController | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
f3_C::~f3_C() {
    m4cc.m_size = 0;
    f3_Level* p = m8 ? (f3_Level*)m8->getter() : 0;
    void* q = p->m08;
    f3_VObj* t = q ? *(f3_VObj**)((char*)q + 0x310) : 0;
    _ReadWriteBarrier();
    if (t) {
        t->v98();
        if (m8)
            m8->unlock((void*)(f3_Sub3*)this);
        t->v98();
    }
}
}   // namespace f3m_008ec4e0

// @f3 0x008eb980 (community match, verified in this file)
#include <math.h>
namespace f3m_008eb980 {
// 0x008eb980  FUN_008eb980
// Projects a motion vector: scales the direction in [v] by a per-type factor and
// by the distance/length ratio, and records the largest resulting length.


extern float  flt_00f79758;   // 95.0f
extern float  flt_00dbcbd0;   // 2.0f
extern float  flt_00dbe8fc;   // 0.1f
extern float  flt_00db886c;   // 3.0f
extern double dbl_00db7de8;   // 0.5
extern double dbl_00db8c48;   // 1000.0
extern double dbl_00e012a0;   // (double)0.9f

struct __declspec(align(16)) HkVector4
{
    union { struct { float x, y, z, w; }; float m_quad[4]; };
    __forceinline float& operator()(int i) { return m_quad[i]; }
};

struct HkMotion
{
    int m_unk00, m_unk04, m_unk08, m_unk0C;
    int m_unk10, m_unk14, m_unk18, m_unk1C;
    int m_unk20, m_unk24, m_unk28, m_unk2C;
    int m_unk30, m_unk34, m_unk38, m_unk3C;
    int m_unk40, m_unk44, m_unk48, m_unk4C;
    int m_unk50, m_unk54, m_unk58, m_unk5C;
    int m_unk60, m_unk64, m_unk68, m_unk6C;
    int m_unk70, m_unk74, m_unk78, m_unk7C;
    int m_unk80, m_unk84, m_unk88, m_unk8C;
    int m_unk90, m_unk94, m_unk98, m_unk9C;
    int m_unkA0, m_unkA4, m_unkA8, m_unkAC;
    int m_unkB0, m_unkB4, m_unkB8, m_unkBC;
    int m_unkC0, m_unkC4, m_unkC8;
    float m_fCC;
    float FUN_008f8410();
};

struct HkEntity
{
    int m_unk00, m_unk04, m_unk08, m_unk0C;
    int m_unk10, m_unk14, m_unk18, m_unk1C;
    int m_unk20, m_unk24, m_unk28;
    int m_type;                 // 0x2C
    int m_unk30, m_unk34, m_unk38, m_unk3C;
    int m_unk40, m_unk44, m_unk48, m_unk4C;
    int m_unk50, m_unk54, m_unk58, m_unk5C;
    int m_unk60, m_unk64, m_unk68, m_unk6C;
    int m_unk70, m_unk74, m_unk78, m_unk7C;
    int m_unk80, m_unk84, m_unk88, m_unk8C;
    int m_unk90, m_unk94, m_unk98, m_unk9C;
    int m_unkA0, m_unkA4, m_unkA8, m_unkAC;
    int m_unkB0, m_unkB4, m_unkB8, m_unkBC;
    int m_unkC0, m_unkC4, m_unkC8, m_unkCC;
    HkMotion m_motion;          // 0xD0
    void Release();
    void Retain();
};

struct HkRefPtr
{
    HkEntity* m_p;
    HkRefPtr& operator=(HkEntity* o)
    {
        if (m_p != o)
        {
            if (m_p)
                m_p->Release();
            m_p = o;
            if (m_p)
                m_p->Retain();
        }
        return *this;
    }
};

struct HkBase
{
    void FUN_008ea1f0(HkVector4* out);
};

struct B8EB980
{
    int m_unk00, m_unk04;
    float m_f08;                // 0x08
    int m_unk0C, m_unk10, m_unk14, m_unk18, m_unk1C;
    int m_unk20, m_unk24, m_unk28, m_unk2C;
    HkEntity* m_p30;            // 0x30
};

struct C8EB980
{
    void*    m_vtbl;            // 0x000
    union { unsigned int m_flags; unsigned char m_flagLo; };       // 0x004
    bool IsBit3() const { return (m_flags >> 3) & 1; }
    int m_unk08, m_unk0C;
    int m_unk10, m_unk14, m_unk18, m_unk1C;
    int m_unk20, m_unk24, m_unk28, m_unk2C;
    int m_unk30, m_unk34, m_unk38, m_unk3C;
    int m_unk40, m_unk44, m_unk48, m_unk4C;
    int m_unk50, m_unk54, m_unk58, m_unk5C;
    int m_unk60, m_unk64, m_unk68, m_unk6C;
    int m_unk70, m_unk74, m_unk78, m_unk7C;
    int m_unk80, m_unk84, m_unk88, m_unk8C;
    int m_unk90, m_unk94, m_unk98, m_unk9C;
    int m_unkA0, m_unkA4, m_unkA8, m_unkAC;
    int m_unkB0, m_unkB4, m_unkB8, m_unkBC;
    int m_unkC0, m_unkC4, m_unkC8, m_unkCC;
    int m_unkD0, m_unkD4, m_unkD8, m_unkDC;
    int m_unkE0, m_unkE4, m_unkE8, m_unkEC;
    int m_unkF0, m_unkF4, m_unkF8, m_unkFC;
    HkVector4 m_rot;            // 0x100
    int m_unk110, m_unk114, m_unk118, m_unk11C;
    int m_unk120, m_unk124, m_unk128, m_unk12C;
    int m_unk130, m_unk134, m_unk138, m_unk13C;
    int m_unk140, m_unk144, m_unk148, m_unk14C;
    int m_unk150, m_unk154, m_unk158, m_unk15C;
    int m_unk160, m_unk164, m_unk168, m_unk16C;
    int m_unk170, m_unk174, m_unk178, m_unk17C;
    int m_unk180, m_unk184, m_unk188, m_unk18C;
    int m_unk190, m_unk194, m_unk198, m_unk19C;
    int m_unk1A0, m_unk1A4, m_unk1A8, m_unk1AC;
    int m_unk1B0, m_unk1B4, m_unk1B8, m_unk1BC;
    int m_unk1C0, m_unk1C4, m_unk1C8, m_unk1CC;
    int m_unk1D0, m_unk1D4, m_unk1D8, m_unk1DC;
    int m_unk1E0, m_unk1E4, m_unk1E8, m_unk1EC;
    int m_unk1F0;
    float m_f1F4;               // 0x1F4
    int m_unk1F8, m_unk1FC, m_unk200, m_unk204;
    int m_unk208, m_unk20C, m_unk210, m_unk214;
    int m_unk218, m_unk21C, m_unk220, m_unk224;
    int m_unk228, m_unk22C;
    HkRefPtr m_p230;            // 0x230
    float m_f234;               // 0x234

    void FUN_008eb980(int unused, B8EB980* b, HkVector4* v);
};

// pdb: bhkCharacterController::objectInteractionCallback | bhkCharacterController.obj | fnv360_0822_retail, vtable, medium
// pdb params: __formal, arInput, arOutput
void C8EB980::FUN_008eb980(int unused, B8EB980* b, HkVector4* v)
{
    HkEntity* e = b->m_p30;
    float a = e->m_motion.FUN_008f8410();
    float len = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
    float s;

    if (a > 0.0f && a < flt_00f79758)
    {
        switch (b->m_p30->m_type & 0x7f)
        {
        case 6:
            s = 0.0f;
            break;
        case 0xa:
            s = (flt_00f79758 * dbl_00db7de8 < a) ? flt_00dbe8fc : flt_00db886c;
            break;
        case 0xe:
            s = flt_00dbe8fc;
            break;
        default:
            s = flt_00dbcbd0;
            break;
        }

        float r = len / a;
        if (dbl_00db8c48 < r)
            s = dbl_00db8c48 / r * s;

        if (!(m_flagLo & 1) && IsBit3())
        {
            HkVector4 pos;
            ((HkBase*)((char*)this - 0x290))->FUN_008ea1f0(&pos);
            pos.z = b->m_f08 - pos.z;
            if (pos.z > m_f1F4 * dbl_00e012a0)
            {
                pos.x = m_rot.x;
                pos.y = m_rot.y;
                pos.z = m_rot.z;
                pos.w = m_rot.w;
                float inv;
                float l2 = pos.x * pos.x + pos.y * pos.y + pos.z * pos.z;
                if (l2 != 0.0f)
                    inv = 1.0f / sqrtf(l2);
                else
                    inv = 0.0f;
                pos.x *= inv;
                pos.y *= inv;
                pos.z *= inv;
                pos.w *= inv;
                v->x = pos.x * len;
                for (int i = 1; i < 4; i++) v->m_quad[i] = pos.m_quad[i] * len;
            }
        }

        v->x *= s;
        for (int i = 1; i < 4; i++) (*v)(i) *= s;
        len *= s;
    }
    else
    {
        v->x = v->y = v->z = v->w = 0.0f;
    }

    if (len > m_f234)
    {
        m_f234 = len;
        m_p230 = b->m_p30;
    }
}
}   // namespace f3m_008eb980

// @f3 0x008fba10 (community match, verified in this file)
namespace f3m_008fba10 {
namespace f3m_008fba10 {
struct Y8fba10;
struct X8fba10 {
    unsigned int unk00, unk04, unk08;
    Y8fba10* unk0c;
};
struct Y8fba10 {
    virtual void v00_8fba10();
    virtual void v01_8fba10();
    virtual void v02_8fba10();
    virtual void v03_8fba10();
    virtual void v04_8fba10();
    virtual void v05_8fba10();
    virtual void v06_8fba10();
    virtual void v07_8fba10();
    virtual void v08_8fba10();
    virtual void v09_8fba10();
    virtual void v10_8fba10();
    virtual void v11_8fba10();
    virtual void v12_8fba10();
    virtual void v13_8fba10();
    virtual void v14_8fba10();
    virtual void v15_8fba10();
    virtual void v16_8fba10();
    virtual void v17_8fba10();
    virtual void v18_8fba10();
    virtual void v19_8fba10();
    virtual void v20_8fba10();
    virtual void v21_8fba10();
    virtual void v22_8fba10();
    virtual void v23_8fba10();
    virtual void v24_8fba10();
    virtual void v25_8fba10();
    virtual void v26_8fba10();
    virtual void v27_8fba10();
    virtual void v28_8fba10();
    virtual void v29_8fba10();
    virtual void v30_8fba10();
    virtual void v31_8fba10();
    virtual void v32_8fba10();
    virtual void v33_8fba10();
    virtual void v34_8fba10();
    virtual void v35_8fba10();
    virtual void v36_8fba10();
    virtual void v37_8fba10();
    virtual void v38_8fba10();
    virtual bool Vfn39_8fba10(void* arg);
};
struct B8fba10 {
    char pad00[0x1c];
    X8fba10* unk1c;
};
__forceinline X8fba10* GetX8fba10(B8fba10* b) { X8fba10* r = 0; if (b) r = b->unk1c; return r; }
struct S8fba10 {
    virtual void u00_8fba10();
    virtual void u01_8fba10();
    virtual void u02_8fba10();
    virtual void u03_8fba10();
    virtual void u04_8fba10();
    virtual void u05_8fba10();
    virtual void u06_8fba10();
    virtual void u07_8fba10();
    virtual void u08_8fba10();
    virtual void u09_8fba10();
    virtual void u10_8fba10();
    virtual void u11_8fba10();
    virtual void u12_8fba10();
    virtual void u13_8fba10();
    virtual void u14_8fba10();
    virtual void u15_8fba10();
    virtual void u16_8fba10();
    virtual void u17_8fba10();
    virtual void u18_8fba10();
    virtual void u19_8fba10();
    virtual void u20_8fba10();
    virtual void u21_8fba10();
    virtual void u22_8fba10();
    virtual void u23_8fba10();
    virtual void u24_8fba10();
    virtual void u25_8fba10();
    virtual void u26_8fba10();
    virtual void u27_8fba10();
    virtual void u28_8fba10();
    virtual void u29_8fba10();
    virtual void u30_8fba10();
    virtual void u31_8fba10();
    virtual void u32_8fba10();
    virtual void u33_8fba10();
    virtual void u34_8fba10();
    virtual void u35_8fba10();
    virtual void u36_8fba10();
    virtual void u37_8fba10();
    virtual void u38_8fba10();
    virtual void u39_8fba10();
    virtual void Vfn40_8fba10();
    unsigned int unk04;
    B8fba10* unk08;
    bool FUN_008f8210(void* arg);
    bool FUN_008fba10(void* arg);
};

// pdb: bhkBinaryAction::Add | bhkBinaryAction.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: apWorld
bool S8fba10::FUN_008fba10(void* arg)
{
    bool result = false;
    if (this && unk08) {
        B8fba10* b=unk08; _ReadWriteBarrier();
        if (arg) {
            X8fba10* x = b ? b->unk1c : 0;
            _ReadWriteBarrier();
            if (x) {
                Y8fba10* y = x->unk0c;
                if (y && !y->Vfn39_8fba10(arg))
                    goto done;
            }
            result = FUN_008f8210(arg);
        }
        else Vfn40_8fba10();
    }
done:
    return result;
}
}
}   // namespace f3m_008fba10

// @f3 0x008ec700 (community match, verified in this file)
namespace f3m_008ec700 {



extern float flt_00f79ae8[];
extern float flt_00f79b08[];
extern unsigned int DAT_010f3170;

void FUN_00901e90(void* array, int numElems, int elemSize);
void FUN_00901f10(void* array, int elemSize);
void* FUN_00970d40(void* array);

struct MemRouter
{
    void FUN_008f6d90(void* p, int numBytes, int memoryClass);
};
extern MemRouter* (__stdcall* DAT_00d9b080)(unsigned int index);

struct __declspec(align(16)) Vec4
{
    float components[4];
    __forceinline float& component(unsigned int index) { return components[index]; }
    __forceinline const float& component(unsigned int index) const { return components[index]; }
    __forceinline Vec4& operator=(const Vec4& other)
    {
        component(0) = other.component(0);
        component(1) = other.component(1);
        component(2) = other.component(2);
        component(3) = other.component(3);
        return *this;
    }
};

struct Arr4
{
    Vec4* m_data;
    int m_size;
    int m_capFlags;

    __forceinline Arr4() { m_data=0; m_size=0; m_capFlags=(int)0x80000000u; }
    __forceinline int capacity() const { return m_capFlags & 0x3fffffff; }
    __forceinline void reserve(int count)
    {
        FUN_00901e90(this, count, sizeof(Vec4));
    }
    __forceinline void addBack(const Vec4& value)
    {
        if (m_size == capacity())
            FUN_00901f10(this, sizeof(Vec4));
        m_data[m_size++] = value;
    }
    __forceinline ~Arr4()
    {
        if ((static_cast<unsigned int>(m_capFlags) & 0x80000000u) == 0)
        {
            const int allocationCapacity = capacity();
            MemRouter* router = DAT_00d9b080(DAT_010f3170);
            router->FUN_008f6d90(m_data, allocationCapacity * sizeof(Vec4), 0x17);
        }
    }
};
typedef char Vec4Size[(sizeof(Vec4) == 16) ? 1 : -1];
typedef char Arr4Size[(sizeof(Arr4) == 12) ? 1 : -1];

// pdb: MakeConvex | bhkCharacterController.obj | fnv360_0721_beta, call_gap_sim, low
// pdb params: arTop, arBottom, afRadius, afStepHeight
void* FUN_008ec700(const float* a, const float* b, float radius, float rise)
{
    float scaledRadius = radius * 0.1428767293691635;
    Arr4 arr;
    arr.reserve(18);

    Vec4 vertex;
    Vec4 ringVertex;
    vertex.component(0) = b[0] * 0.1428767293691635;
    vertex.component(1) = b[1] * 0.1428767293691635;
    vertex.component(2) = b[2] * 0.1428767293691635;
    vertex.component(2) -= scaledRadius;
    arr.addBack(vertex);

    vertex.component(2) += rise + 0.10000000149011612;
    for (unsigned int i = 0; i < 8; ++i)
    {
        ringVertex = vertex;
        ringVertex.component(0) += flt_00f79ae8[i] * scaledRadius;
        ringVertex.component(1) += flt_00f79b08[i] * scaledRadius;
        arr.addBack(ringVertex);
    }

    vertex.component(0) = a[0] * 0.1428767293691635;
    vertex.component(1) = a[1] * 0.1428767293691635;
    vertex.component(2) = a[2] * 0.1428767293691635;
    double halfRadius = scaledRadius * 0.5;
    vertex.component(2) += halfRadius;
    for (unsigned int i = 0; i < 8; ++i)
    {
        ringVertex = vertex;
        ringVertex.component(0) = flt_00f79ae8[i] * scaledRadius;
        ringVertex.component(1) = flt_00f79b08[i] * scaledRadius;
        arr.addBack(ringVertex);
    }
    vertex.component(2) += halfRadius;
    arr.addBack(vertex);
    return FUN_00970d40(&arr);
}




}   // namespace f3m_008ec700

// @f3 0x008f67f0 (community match, verified in this file)
namespace f3m_008f67f0 {
struct S_008f67f0 {
    char pad[20];
    int m;
    void FUN_008f67f0();
};
// pdb: hkMemorySystem::getInstancePtr | hkMemorySystem.obj | fnv360_0822_retail, objrun_open, low
void S_008f67f0::FUN_008f67f0()
{
    ++m;
}
}   // namespace f3m_008f67f0

// @f3 0x008fb8f0 (community match, verified in this file)
#include <intrin.h>
namespace f3m_008fb8f0 {

class C_008fb8f0_Q;
class C_008fb8f0_Obj8;

class C_008fb8f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
    virtual void* v98();
    bool FUN_008f8280();
    bool FUN_008fb8f0();
};

class C_008fb8f0_Q {
public:
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual void q4(); virtual void q5(); virtual void q6(); virtual void q7();
    virtual void q8(); virtual void q9(); virtual void q10(); virtual void q11();
    virtual void q12(); virtual void q13(); virtual void q14(); virtual void q15();
    virtual void q16(); virtual void q17(); virtual void q18(); virtual void q19();
    virtual void q20(); virtual void q21(); virtual void q22(); virtual void q23();
    virtual void q24(); virtual void q25(); virtual void q26(); virtual void q27();
    virtual void q28(); virtual void q29(); virtual void q30(); virtual void q31();
    virtual void q32(); virtual void q33(); virtual void q34(); virtual void q35();
    virtual void q36(); virtual void q37();
    virtual void* q98();
};

class C_008fb8f0_Obj8 {
public:
    void FUN_00979df0(int);
};

// pdb: bhkBinaryAction::Remove | bhkBinaryAction.obj | fnv360_0822_retail, caller_sim, low
__declspec(noinline) bool C_008fb8f0::FUN_008fb8f0()
{
    bool result = false;
    void* p = v98();
    void* q;
    if (p)
        q = *(void**)((char*)p + 0x310);
    else
        q = 0;
    _ReadWriteBarrier();
    if (q)
    {
        result = FUN_008f8280();
        void* obj8 = *(void**)((char*)this + 8);
        int cmpVal;
        if (obj8)
            cmpVal = *(int*)((char*)obj8 + 0x1c);
        else
            cmpVal = 0;
        void* p2 = ((C_008fb8f0_Q*)q)->q98();
        int val2;
        if (p2)
            val2 = *(int*)((char*)p2 + 0x24);
        else
            val2 = 0;
        if (cmpVal == val2)
        {
            void* obj8b = *(void**)((char*)this + 8);
            if (obj8b)
                ((C_008fb8f0_Obj8*)obj8b)->FUN_00979df0(0);
        }
    }
    return result;
}
}   // namespace f3m_008fb8f0

// @f3 0x008e9f00 (community match, verified in this file)
namespace f3m_008e9f00 {

extern const char DAT_00e329b8[];
extern int DAT_0108f200;

extern int __cdecl FUN_00c009eb(const char*, const char*);
extern void* __cdecl FUN_00424d50(void*, void*);

struct Item {
    int unk00;
    int unk04;
    const char* name;
};

struct Array {
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
    Item** entries;
    unsigned short unkA4;
    unsigned short count;
};

struct Obj {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual Array* getArray();
};

struct Source {
    Obj* FUN_008f9c90(int);
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
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    Source* unk424;
    Item* FUN_008e9f00();
};

// pdb: bhkCharacterController::FindDisplayGeometry | bhkCharacterController.obj | fnv360_0822_retail, call_seq, medium
Item* Owner::FUN_008e9f00() {
    unsigned int* flags = &unk294;
    Item* result = 0;

    if (*flags & 0x8000) {
        Source* source = unk424;
        if (source) {
            Obj* obj = source->FUN_008f9c90(0);
            if (obj) {
                Array* array = obj->getArray();
                if (array) {
                    Item* first;
                    if (array->count <= 0) {
                        first = 0;
                    } else {
                        first = array->entries[0];
                    }

                    Array* found = (Array*)FUN_00424d50(&DAT_0108f200, first);
                    if (found) {
                        unsigned int count = found->count;
                        while (count != 0) {
                            --count;
                            Item* item = found->entries[count];

                            if (item) {
                                const char* name = item->name;
                                if (name) {
                                    if (FUN_00c009eb(name, DAT_00e329b8) == 0) {
                                        result = item;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (!result) {
            *flags &= 0xFFFF7FFF;
        }
    }

    return result;
}

}

// @f3 0x008e4d50 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_010f3170;
namespace f3m_008e4d50 {
// FUN_008e4d50 - 0x008e4d50, 1086 bytes
// Owner::FUN_008e4d50(const char*)  __thiscall; official pack flags, exact match.

// ---------------------------------------------------------------- memory manager
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct MemBlock { MemBlock* next; };
struct MemBucket { MemBlock* head; int count; };

struct MemHeap {                                    // the TLS block allocator
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30;
    int limit;                                   // 0x34
    MemBucket heads[1];                         // 0x38, one bucket per size class
    void* FUN_008f6800(int index, int align);
    void  FUN_008f6890(int index, MemBlock* block, unsigned int tag);
    void  FUN_008f6f60(int dummy);
    void* FUN_008f6f60(unsigned int size, int align);
    void  FUN_008f6d90(MemBlock* block, int bytes, unsigned int tag);
};

static __forceinline MemHeap* GetHeap() { return (MemHeap*)DAT_00d9b080(DAT_010f3170); }

static __forceinline MemBucket* Bucket(int index) {
    MemHeap* heap = GetHeap();
    return &((MemBucket*)&heap->heads)[index];
}

static __forceinline void* PoolTake(int index, int count) {
    MemHeap* heap = GetHeap();
    MemBucket* bucket = &((MemBucket*)&heap->heads)[index];
    MemBlock* block = bucket->head;
    if (block) {
        --bucket->count;
        bucket->head = block->next;
        return block;
    } else {
        return heap->FUN_008f6800(index, count);
    }
}

static __forceinline void PoolGive(void* p, int index, unsigned int tag) {
    MemHeap* heap = GetHeap();
    MemBucket* bucket = &((MemBucket*)&heap->heads)[index];
    MemBlock* block = (MemBlock*)p;
    if (bucket->count >= heap->limit) {
        heap->FUN_008f6890(index, block, tag);
    } else {
        ++bucket->count;
        block->next = bucket->head;
        bucket->head = block;
    }
}

void* FUN_008dba50(unsigned int size);            // allocate with 16-byte alignment
void  FUN_008db970(void* dst, const void* src);   // rotation matrix + translation -> quaternion form
void* FUN_00901e90(void* array, int count, unsigned int elemSize);

struct NiPoint3 { float x; float y; float z; };
struct ThreeByThreeMatrix { float m[3][3]; };
struct NiTransform {
    ThreeByThreeMatrix m_kRotate;                 // 0x00
    NiPoint3           m_kTranslate;              // 0x24
    float              m_fScale;                  // 0x30
    void ResetToIdentity();
};

// ---------------------------------------------------------------- arrays
struct E30 { int unk00; int unk04; int unk08; int unk0c;
             int unk10; int unk14; int unk18; int unk1c;
             int unk20; int unk24; int unk28; int unk2c; };   // 0x30

template <class T> struct Arr8e4d50 {
    T* data; int count; int capacityFlags;
    __forceinline Arr8e4d50() : data(0), count(0), capacityFlags(0x80000000) {}
    ~Arr8e4d50() {
        if (!(capacityFlags & 0x80000000)) {
            unsigned int capacity = capacityFlags & 0x3fffffff;
            MemHeap* heap = GetHeap();
            heap->FUN_008f6d90((MemBlock*)data, capacity * sizeof(T), 0x17);
        }
    }
    void SetSize(int n) {
        int have = capacityFlags & 0x3fffffff;
        if (have < n) {
            int want = have * 2;
            if (n >= want) want = n;
            FUN_00901e90(this, want, sizeof(T));
        }
        count = n;
    }
};

// ---------------------------------------------------------------- objects
struct Item8 { void* value; bool flag; };
struct Data24 {                                  // 0x24 bytes
    void* f00; short* f04; int f08; Item8** f0c;
    int f10; E30* f14; int f18; int f1c; int f20;
    Data24* FUN_008db420();
};

struct V4 {
    float x, y, z, w;
    __forceinline V4& operator=(const V4& r) { x=r.x; y=r.y; z=r.z; w=r.w; return *this; }
    __forceinline void Set(float a, float b, float c, float d) { x=a; y=b; z=c; w=d; }
};
struct Holder30 {                                // 0x30 bytes, this->p2a4->p1c
    Data24* data;                                // 0x00
    int unk04; int unk08; int unk0c;
    V4 m1;
    V4 m2;
    __forceinline Holder30() : data(0) {}
    static void* operator new(unsigned int n) { return FUN_008dba50(n); }
};

struct Pair8 { void* a; void* b; };

struct Sub {                                     // this->p2a4
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18;
    Holder30* p1c;                               // 0x1c
};

struct Q54 {                                     // 0x38 bytes, pool 5
    Data24* data;                                // 0x00
    Arr8e4d50<E30> a;                                // 0x04
    Arr8e4d50<E30> b;                                // 0x10
    Arr8e4d50<int> c;                                // 0x1c
    bool       b28; bool b29; short unk2a;
    Arr8e4d50<int> d;                                // 0x2c
    __forceinline Q54(Data24* src) : data(src), b28(false), b29(false) {
        int n = data->f10;
        b.SetSize(n);
        a.SetSize(n);
        c.SetSize(n);
        d.SetSize(data->f20);
    }
    void FUN_00955070();
    void hkaPose_syncModelSpace();
    static void* operator new(unsigned int size) { return PoolTake(5, 0xe); }
    static void  operator delete(void* p) { if (p) PoolGive(p, 5, 0xe); }
};

// ---------------------------------------------------------------- the owner
struct Owner {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    short unk40;
    bool b42; char pad43;
    int unk44; int unk48; int unk4c; int unk50;
    Q54* p54;
    int unk58; int unk5c; int unk60; int unk64;
    int unk68; int unk6c; int unk70; int unk74;
    int unk78; int unk7c; int unk80; int unk84;
    void* p88;
    int unk8c; int unk90; int unk94; int unk98;
    int unk9c; int unka0; int unka4; int unka8; int unkac;
    char b0; char padb1; short padb2;
    int unkb4; int unkb8; int unkbc; int unkc0;
    int unkc4; int unkc8; int unkcc; int unkd0;
    int unkd4; int unkd8; int unkdc; int unke0;
    int unke4; int unke8; int unkec;
    void* pf0;
    short wf4;
    short wf6;
    int unkf8; int unkfc;
    V4 v100;
    V4 v110;
    int unk120; int unk124; int unk128; int unk12c;
    int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c;
    V4 v150;
    V4 v160;
    int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c;
    char b190; char pad191; short pad192;
    int i194;
    int unk198; int unk19c; int unk1a0; int unk1a4;
    int unk1a8; int unk1ac; int unk1b0; int unk1b4;
    int unk1b8; int unk1bc; int unk1c0; int unk1c4;
    int unk1c8; int unk1cc; int unk1d0; int unk1d4;
    int unk1d8; int unk1dc; int unk1e0; int unk1e4;
    int unk1e8; int unk1ec; int unk1f0; int unk1f4;
    int unk1f8; int unk1fc; int unk200; int unk204;
    int unk208; int unk20c; int unk210; int unk214;
    int unk218; int unk21c; int unk220; int unk224;
    int unk228; int unk22c; int unk230; int unk234;
    int unk238; int unk23c; int unk240; int unk244;
    int unk248; int unk24c; int unk250; int unk254;
    int unk258; int unk25c; int unk260; int unk264;
    int unk268; int unk26c; int unk270; int unk274;
    int unk278; int unk27c; int unk280; int unk284;
    int unk288; int unk28c; int unk290; int unk294;
    int unk298; int unk29c; int unk2a0;
    Sub* p2a4;
    __forceinline Sub* GetSub() { return p2a4; }
    bool FUN_008e1960(void* p, const char* arg, int one);
    bool FUN_008e4d50(const char* arg);
};

// ---------------------------------------------------------------- the function
// pdb: bhkRagdollController::InitLookIK | bhkRagdollController.obj | fnv360_0822_retail, call_gap, low
// pdb params: apNodeName
bool Owner::FUN_008e4d50(const char* arg) {
    bool ok = b42;
    if (ok) {
        ok = FUN_008e1960(p88, arg, 1);
        if (ok) {
            i194 = 1;
            if (b190) {
                if (!GetSub()->p1c) {
                    GetSub()->p1c = new Holder30;

                    short* e4 = (short*)g_memoryManager.Allocate(4);
                    E30* key = (E30*)GetHeap()->FUN_008f6f60(0x60, 9);
                    Item8** pair = (Item8**)g_memoryManager.Allocate(8);

                    Item8* blkA = (Item8*)PoolTake(1, 0x3b);
                    Item8* blkB = (Item8*)PoolTake(1, 0x3b);

                    e4[0] = -1;
                    e4[1] = 0;
                    NiTransform xf;
                    xf.ResetToIdentity();
                    FUN_008db970(key, &xf);
                    xf.m_kTranslate.x = 9.0f;
                    xf.m_kTranslate.y = 6.0f;
                    xf.m_kTranslate.z = 0.0f;
                    FUN_008db970(key + 1, &xf);
                    pair[0] = blkA;
                    pair[1] = blkB;

                    Data24* d = (Data24*)PoolTake(4, 0x3b);
                    if (d) d = d->FUN_008db420();
                    else d = 0;
                    GetSub()->p1c->data = d;

                    GetSub()->p1c->data->f0c = pair;
                    GetSub()->p1c->data->f10 = 2;
                    GetSub()->p1c->data->f08 = 2;
                    GetSub()->p1c->data->f04 = e4;
                    GetSub()->p1c->data->f14 = key;
                    GetSub()->p1c->data->f18 = 2;

                    GetSub()->p1c->m1 = v160;
                    GetSub()->p1c->m2 = v150;
                }

                Q54* q = new Q54(GetSub()->p1c->data);
                p54 = q;
                q->FUN_00955070();
                p54->hkaPose_syncModelSpace();

                v100.Set(0.0f, 1.0f, 0.0f, 0.0f);
                v110.Set(0.0f, 1.0f, 0.0f, 0.0f);
                pf0 = p54;
                wf4 = 1;
                wf6 = 0;
                i194 = 0;
            }
        }
        b0 = ok;
    }
    return ok;
}
}   // namespace f3m_008e4d50

// @f3 0x008e7130 (community match, verified in this file)
#include <string.h>
namespace Sol8e7130 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
struct Heap {
    void* FUN_0086b930(unsigned int);
    void FUN_0086ba60(void*);
};
extern Heap DAT_01090a78;
void* __cdecl FUN_0089e810(unsigned int);
void __cdecl FUN_0089e890(void*);
void* __cdecl FUN_00c00610(void*, int, unsigned int);
void __cdecl FUN_00901e90(void*, int, int);

struct Block { Block* next; };
struct Bucket { Block* head; int count; };
struct Pool {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Bucket buckets[25];
    void* FUN_008f6800(int, int);
    void* FUN_008f6f60(unsigned int, int);
    void FUN_008f6d90(void*, unsigned int, int);
    __forceinline void* Allocate(int index, int tag) {
        Block* p = buckets[index].head;
        if (p) {
            --buckets[index].count;
            buckets[index].head = p->next;
            return p;
        }
        return FUN_008f6800(index, tag);
    }
};
__forceinline Pool* CurrentPool() { return (Pool*)DAT_00d9b080(DAT_010f3170); }

struct __declspec(align(16)) Vec {
    float x,y,z,w;
    __forceinline Vec& operator=(const Vec& b) {
        x=b.x; y=b.y; z=b.z; w=b.w; return *this;
    }
};
struct Transform {
    Vec a,b,c;
    static void* operator new[](unsigned int size) { return CurrentPool()->FUN_008f6f60(size,9); }
};
template<class T> struct Array {
    T* data;
    int size;
    int capacityFlags;
    __forceinline Array() : data(0),size(0),capacityFlags(0x80000000u) {}
    __forceinline ~Array() {
        if (!(capacityFlags & 0x80000000u))
            CurrentPool()->FUN_008f6d90(data,(capacityFlags&0x3fffffff)*sizeof(T),0x17);
    }
    __forceinline int GetCapacity() const { return capacityFlags&0x3fffffff; }
    __forceinline void Reserve(int n) {
        const int capacity = GetCapacity();
        if (capacity<n) {
            int cap = capacity*2;
            FUN_00901e90(this,n<cap?cap:n,sizeof(T));
        }
    }
    __forceinline void SetSize(int n) {
        Reserve(n);
        size=n;
    }
};
struct Bone {
    const char* name;
    unsigned char locked;
    static void* operator new(unsigned int) { return CurrentPool()->Allocate(1,0x3b); }
};
struct Skeleton {
    const char* name;
    short* parents;
    int numParents;
    Bone** bones;
    int numBones;
    Transform* transforms;
    int numTransforms;
    void* extra;
    int numExtra;
    __forceinline Skeleton() : name(0),parents(0),numParents(0),bones(0),numBones(0),transforms(0),numTransforms(0),extra(0),numExtra(0) {}
    static void* operator new(unsigned int) { return CurrentPool()->Allocate(4,0x3b); }
};
struct Pose {
    const Skeleton* skeleton;
    Array<Transform> local;
    Array<Transform> model;
    Array<unsigned int> flags;
    unsigned char ready, initialized;
    Array<float> extra;
    __forceinline Pose(const Skeleton* s) : skeleton(s),ready(0),initialized(0) {
        int n=skeleton->numBones;
        model.SetSize(n);
        local.SetSize(n);
        flags.SetSize(n);
        extra.SetSize(skeleton->numExtra);
    }
    static void* operator new(unsigned int) { return CurrentPool()->Allocate(5,0xe); }
    static void operator delete(void* p,unsigned int size) { CurrentPool()->FUN_008f6d90(p,size,0xe); }
    void FUN_00955070();
};
struct BoneRecord {
    const char* name;
    int unk04,unk08,unk0c;
    Transform transform;
    short parent;
};
struct RecordArray;
struct RecordTable {
    void* destroy;
    void* alloc;
    void (__thiscall* free)(RecordArray*,void*);
};
extern const RecordTable DAT_00e32b9c;
struct RecordArray {
    const RecordTable* table;
    BoneRecord** data;
    unsigned int size;
    unsigned int capacity;
    RecordArray() : table(&DAT_00e32b9c),data(0),size(0),capacity(0) {}
    ~RecordArray() {
        table=&DAT_00e32b9c;
        if(data) table->free(this,data);
    }
    __forceinline void Clear() {
        if(data) {
            table->free(this,data);
            data=0; capacity=0; size=0;
        }
    }
};
struct MapBase {
    virtual ~MapBase() {
        FUN_006bd950();
        FUN_0089e890(data);
    }
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    unsigned int buckets;
    void* data;
    unsigned int count;
    MapBase() : buckets(37),count(0) {
        unsigned int allocationSize=sizeof(void*)*buckets;
        data=FUN_0089e810(allocationSize);
        unsigned int bytes=buckets*sizeof(void*);
        FUN_00c00610(data,0,bytes);
    }
    void FUN_006bd950();
};
struct Map : MapBase {
    Map() {}
    virtual ~Map() { FUN_006bd950(); }
};
struct NodeInfo { int unk00,unk04; void* payload; };
NodeInfo* __cdecl FUN_008f1d20(void*);
struct Holder { int unk00,unk04,unk08; Skeleton* skeleton; };
template<class T> struct PlainPtr {
    T* ptr;
    __forceinline T* operator->() const { return ptr; }
    __forceinline operator T*() const { return ptr; }
};
struct Owner {
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
    void* root;
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
    Pose* pose;
    int unk08c;
    int unk090;
    Array<Transform> transforms;
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
    PlainPtr<Holder> holder;

    void FUN_008e5520(void*,RecordArray*,Map*);
    void FUN_008e7130();
};

// pdb: bhkRagdollController::CreateSGSkeleton | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
void Owner::FUN_008e7130() {
    if (!root) return;
    void* node=FUN_008f1d20(root)->payload;
    RecordArray records;
    Map map;
    FUN_008e5520(node,&records,&map);
    if(!holder->skeleton) {
        unsigned int n=records.size;
        Bone** bones=new Bone*[n];
        Transform* transforms=new Transform[n];
        short* parents=new short[n];
        for(unsigned int i=0;i<records.size;++i) {
            Bone* b=new Bone;
            b->name=records.data[i]->name;
            b->locked=1;
            bones[i]=b;
            transforms[i]=records.data[i]->transform;
            parents[i]=records.data[i]->parent;
        }
        holder->skeleton=new Skeleton;
        holder->skeleton->bones=bones;
        holder->skeleton->numBones=n;
        holder->skeleton->parents=parents;
        holder->skeleton->numParents=n;
        holder->skeleton->transforms=transforms;
        holder->skeleton->numTransforms=n;
    }
    for(unsigned int i=0;i<records.size;++i) {
        BoneRecord* r=records.data[i];
        if(r) DAT_01090a78.FUN_0086ba60((char*)r-((unsigned char*)r)[-1]);
    }
    records.Clear();
    pose=new Pose(holder->skeleton);
    pose->FUN_00955070();
    transforms.SetSize(holder->skeleton->numBones);
}
}

// @f3 0x008fb0b0 (community match, verified in this file)
namespace f3m_008fb0b0 {
struct State { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c; unsigned flags; };
struct Link { int unk00, unk04; State* state; };
struct PropValue { int lo; int hi; };
struct Entry { int unk00, unk04; Entry* owner; int* FUN_00477900(PropValue*, const void*); };
struct Root { int unk00, unk04, unk08, unk0c; Entry* excluded; };
struct Heap { void FUN_008f6d90(void* p, int bytes, int cls); };
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
extern char DAT_010f2c30;
Root* FUN_008f1d20(void*);

template <typename T>
inline void DeallocateChunk(T* p, int nelem, int cls)
{
    Heap* mem = static_cast<Heap*>(DAT_00d9b080(DAT_010f3170));
    mem->FUN_008f6d90(p, nelem * (int)sizeof(T), cls);
}

struct Entries {
    Entry** data;
    int size;
    int capacityAndFlags;
    Entries() : data(0), size(0), capacityAndFlags(0x80000000) {}
    Entry*& operator[](int i) { return data[i]; }
    ~Entries()
    {
        if ((capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = capacityAndFlags & 0x3fffffff;
            Heap* mem = static_cast<Heap*>(DAT_00d9b080(DAT_010f3170));
            mem->FUN_008f6d90(data, capacity * (int)sizeof(Entry*), 0x17);
        }
    }
};
void FUN_008f21f0(void*, Entries*);

inline int GetHandle(Entry* e)
{
    PropValue v;
    return e ? *e->FUN_00477900(&v, &DAT_010f2c30) : 0;
}

struct Owner {
    int unk00, unk04;
    void* root;
    void FUN_008fb0b0();
};
// pdb: WeaponObject::UpdateChildRB3D | WeaponObject.obj | fnv360_0822_retail, call_gap, low
void Owner::FUN_008fb0b0()
{
    void* source = root;
    if (!source)
        return;
    Root* resolved = FUN_008f1d20(source);
    Entry* excluded = resolved ? resolved->excluded : 0;
    Entries entries;
    FUN_008f21f0(source, &entries);
    for (int i = 0; i < entries.size; ++i) {
        if (!excluded)
            break;
        Entry* exOwner = excluded->owner;
        if (entries.data[i] != exOwner && entries.data[i]->owner == 0) {
            __int64 widened = GetHandle(entries.data[i]);
            reinterpret_cast<Link*>(static_cast<int>(widened))->state->flags |= 1;
        }
    }
}
}

// @f3 0x008ed120 (community match, verified in this file)
#include <math.h>
namespace f3m_008ed120 {

void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0086ba60(void* p);
const char* __cdecl FUN_008242a0(const char* input);
extern const char* DAT_00e207a8;
extern long (__stdcall *DAT_00d9b064)(long*);
extern double DAT_00db88e8;
extern char DAT_00e329b8[];
extern char DAT_0108f200[];

struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
    NiPoint3 operator*(float f) const { return NiPoint3(x * f, y * f, z * f); }
    float& operator[](int i) { const float* base = &x; return (float&)base[i]; }
};

struct Name {
    const char* value;
    Name(const char* input) : value(FUN_008242a0(input)) {}
    ~Name()
    {
        if (value != DAT_00e207a8)
            DAT_00d9b064(reinterpret_cast<long*>(const_cast<char*>(value) - 8));
    }
};

inline float Abs(float f) { return (float)fabs(f); }

struct Prop {
    void* vtbl;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    NiPoint3 m_color;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    int m_revision;
    unsigned unk048;
    Prop();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0086ba60(p); }
};

struct Node {
    void* vtbl;
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
    float m_rot34;
    float m_rot38;
    float m_rot3c;
    float m_rot40;
    float m_rot44;
    float m_rot48;
    float m_rot4c;
    float m_rot50;
    float m_rot54;
    NiPoint3 m_translate;
    float m_scale;
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
    Node(int);
    void FUN_008245d0(const void* name);
    void FUN_004236f0(Prop* prop);
    void FUN_008268a0();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0086ba60(p); }
};

struct Display {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual Display* GetObject0c();
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
    virtual void Notify(Node* node);
    virtual void vd4(); virtual void vd8();
    virtual void AttachChild(Node* child, int first);
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
    float m_scale;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned short unk0a4;
    unsigned short m_childCount;
    float GetScale() const { return m_scale; }
    Display* FUN_00434470(int index);
};

struct Finder {
    Display* FUN_008f9c90(int* key);
};

struct Handle { int value; };
void __cdecl FUN_008f6020(int id, NiPoint3* color);
Display* __cdecl FUN_00424d50(void* rtti, Display* obj);

struct Owner {
    void* vtbl;
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
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned m_flags;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    unsigned unk320;
    unsigned unk324;
    unsigned unk328;
    unsigned unk32c;
    unsigned unk330;
    unsigned unk334;
    unsigned unk338;
    unsigned unk33c;
    unsigned unk340;
    unsigned unk344;
    unsigned unk348;
    unsigned unk34c;
    unsigned unk350;
    unsigned unk354;
    unsigned unk358;
    unsigned unk35c;
    unsigned unk360;
    unsigned unk364;
    unsigned unk368;
    unsigned unk36c;
    unsigned unk370;
    unsigned unk374;
    unsigned unk378;
    unsigned unk37c;
    unsigned unk380;
    unsigned unk384;
    unsigned unk388;
    unsigned unk38c;
    unsigned unk390;
    unsigned unk394;
    unsigned unk398;
    unsigned unk39c;
    unsigned unk3a0;
    unsigned unk3a4;
    unsigned unk3a8;
    unsigned unk3ac;
    unsigned unk3b0;
    unsigned unk3b4;
    unsigned unk3b8;
    unsigned unk3bc;
    unsigned unk3c0;
    unsigned unk3c4;
    unsigned unk3c8;
    unsigned unk3cc;
    unsigned unk3d0;
    unsigned unk3d4;
    unsigned unk3d8;
    unsigned unk3dc;
    unsigned unk3e0;
    unsigned unk3e4;
    unsigned unk3e8;
    unsigned unk3ec;
    unsigned unk3f0;
    unsigned unk3f4;
    unsigned unk3f8;
    unsigned unk3fc;
    float m_x;
    float m_y;
    float m_z;
    unsigned unk40c;
    unsigned unk410;
    unsigned unk414;
    unsigned unk418;
    unsigned unk41c;
    unsigned unk420;
    Finder* m_finder;
    int FUN_008e9f00();
    Display* FUN_008e98a0();
    Handle FUN_0061f4f0();
    float X() const { return m_x; }
    float Y() const { return m_y; }
    float Z() const { return m_z; }
    void FUN_008ed120(Display* parent);
};

void Owner::FUN_008ed120(Display* parent)
{
    int busy = FUN_008e9f00();
    if (busy)
        return;
    if (!parent)
    {
        if (!m_finder)
            return;
        Display* found = m_finder->FUN_008f9c90(0);
        if (!found)
            return;
        parent = found->GetObject0c();
        if (!parent)
            return;
        if (parent->m_childCount)
            parent = FUN_00424d50(DAT_0108f200, parent->FUN_00434470(0));
        if (!parent)
            return;
    }
    if (!FUN_008e98a0())
        return;
    Node* node = new Node(0);
    parent->AttachChild(node, 1);
    node->FUN_008245d0(&Name(DAT_00e329b8));
    float s = parent->GetScale();
    NiPoint3 pos;
    pos.x = X() * DAT_00db88e8;
    // Fake match: the y lane is stored through the index accessor, so its address is taken before the scale below;
    // that makes the compiler load pos.y first there (fld y; fmul st(1)) as the original does. Plain pos.y = ... keeps
    // the factor first. The original construct that took the address of y is not known.
    pos[1] = Y() * DAT_00db88e8;
    pos.z = Z() * DAT_00db88e8;
    pos = pos * (1.0f / s);
    node->m_translate = pos;
    if (parent->GetScale() != 0.0f)
        node->m_scale = Abs(1.0f / parent->GetScale());
    NiPoint3 color(0.0f, 0.0f, 0.0f);
    FUN_008f6020(FUN_0061f4f0().value, &color);
    Prop* prop = new Prop;
    prop->m_color = color;
    prop->m_revision++;
    node->FUN_004236f0(prop);
    FUN_008e98a0()->Notify(node);
    node->FUN_008268a0();
    m_flags |= 0x8000;
}

}

// @f3 0x008efb10 (community match, verified in this file)
namespace F3NativeBodySettings {
extern __declspec(thread) int tlsHeapTag;
struct HeapTag {
    int previous;
    HeapTag() { previous = tlsHeapTag; tlsHeapTag = 0x10; }
    ~HeapTag() { tlsHeapTag = previous; }
};
struct ScratchAllocator {
    void FUN_008f6d90(void* allocation, unsigned int bytes, unsigned int category);
};
extern unsigned int DAT_010f3170;
extern ScratchAllocator* (__stdcall* DAT_00d9b080)(unsigned int index);
struct NativeVectorFB { __declspec(align(16)) float x;float y,z,w; };
struct NativeMatrixFB { NativeVectorFB column0,column1,column2,translation; };
struct FUN_004f64e0 {
    void* first;
    void* second;
    unsigned char mode, unk009, unk00a, unk00b;
    void* data;
    int size;
    int capacityFlags;
    unsigned int unk018, unk01c;
    NativeMatrixFB transform;
    FUN_004f64e0();
    ~FUN_004f64e0()
    {
        if ((static_cast<unsigned int>(capacityFlags) & 0x80000000u) == 0) {
            const unsigned int capacity = capacityFlags & 0x3fffffff;
            ScratchAllocator* allocator = DAT_00d9b080(DAT_010f3170);
            allocator->FUN_008f6d90(data, capacity * 8, 0x17);
        }
    }
};
struct FUN_008e8a50;
struct Binding {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned char unk01c, unk01d;
    bool requiresRefresh;
    unsigned char unk01f;
    void FUN_008d5730(FUN_008e8a50* driver, void* settings);
};
void* __cdecl FUN_0089eb90(unsigned int bytes);
struct FUN_008e8a50 {
    virtual void Slot00();
    virtual void Destroy();
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
    virtual void SetBinding(Binding* binding);
    long references;
    void* handle;
    unsigned int unk00c, unk010;
    unsigned char active, unk015, unk016, unk017;
    FUN_008e8a50(FUN_004f64e0* settings);
    static void operator delete(void* object);
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
};
struct FlagState {
    unsigned int unk00;
    unsigned int flags;
    void Set(unsigned int bit, bool enabled)
    {
        if (enabled)
            flags |= bit;
        else
            flags &= ~bit;
    }
};
struct Model {
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
    bool needsUpdate;
    void FUN_0091ecc0(FlagState* flags);
    void SetNeedsUpdate(bool value) { needsUpdate = value; }
};
struct Input {
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
    void* activeHandle;
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
    void* scene;
    Binding* binding;
    float firstLimit, secondLimit;
    unsigned char unk094, unk095, unk096;
    bool optionA;
    bool optionB;
    unsigned char unk099, unk09a, unk09b;
    unsigned int parameter;
    unsigned int unk0a0, unk0a4;
    float firstScale, secondScale;
    unsigned int unk0b0;
    void* output;
};
struct Actor;
void* __cdecl FUN_00921850(unsigned int first, unsigned int second, int zero, unsigned int mode);
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
    virtual void Refresh(bool enabled);

    unsigned int unk004;
    Model* model;
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
    FlagState state;
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
    float scale;
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
    unsigned int parameter;
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
    float firstLimit;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    float secondLimit;
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
    FUN_008e8a50* mainDriver;
    FUN_008e8a50* secondaryDriver;
    FUN_008e8a50* thirdDriver;
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
    void* output;
    void SetScale(const float& value) { scale = value; }
    void SetParameter(unsigned int value) { parameter = value; }
    void SetOutput(void* value) { output = value; }
    void FUN_008ee9e0(Input* input);
    FUN_008e8a50* FUN_008e98a0();
    void FUN_0092acf0(Input* input);
    void bhkCharacterController_Init(Input* input);
};
// pdb: bhkCharacterController::Init | bhkCharacterController.obj | fnv360_0721_beta, call_seq + bridge(call_gap|vtable), high
void Actor::bhkCharacterController_Init(Input* input)
{
    HeapTag tag;
    if (input) {
        SetScale(input->firstScale * input->secondScale);
        FUN_008ee9e0(input);
        FUN_004f64e0 setup;
        setup.first = input->scene;
        FUN_008e8a50* existing = FUN_008e98a0();
        setup.second = existing ? existing->handle : 0;
        FUN_008e8a50* replacement = new FUN_008e8a50(&setup);
        if (mainDriver != replacement) {
            FUN_008e8a50* old = mainDriver;
            if (old && InterlockedDecrement(&old->references) == 0)
                old->Destroy();
            mainDriver = replacement;
            if (replacement)
                InterlockedIncrement(&replacement->references);
        }
        if (input->binding) {
            if (mainDriver) {
                mainDriver->SetBinding(input->binding);
                FUN_008e8a50* current = mainDriver;
                void* settings = FUN_00921850(0x96, 0x96, 0, 0x19);
                input->binding->FUN_008d5730(current, settings);
                if (input->binding->requiresRefresh)
                    Refresh(false);
            }
            if (secondaryDriver)
                secondaryDriver->SetBinding(input->binding);
            if (thirdDriver)
                thirdDriver->SetBinding(input->binding);
        }
        SetParameter(input->parameter);
        firstLimit = input->firstLimit;
        secondLimit = input->secondLimit;
        SetOutput(input->output);
        input->activeHandle = mainDriver ? mainDriver->handle : 0;
        FUN_0092acf0(input);
        model->SetNeedsUpdate(true);
        state.Set(0x02000000, input->optionA);
        state.Set(0x04000000, input->optionB);
        if (model)
            model->FUN_0091ecc0(&state);
    }
}
}

// @f3 0x008e5190 (community match, verified in this file)
namespace f3m_008e5190 {
// 0x008e5190 (904 bytes), __thiscall with 4 stack arguments. The code is /O2 (aligned frame, ids in registers).
// Shape: assign the fixed name, resolve three bone ids, create the pooled pose controller, then for every cached
// matrix set copy its local bone transforms into a thread-stack buffer and convert them into a second buffer.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

extern const char* DAT_00e207a8;
extern const char DAT_00dbfbdc[];
extern const char DAT_00dfb5f8[];
extern const char DAT_00dc0844[];
extern unsigned int DAT_010f3170;
const char* __cdecl FUN_008242a0(const char* name);

struct FixedNameHeader {
    volatile long references;
    unsigned int length;
};

struct BoneTree {
    unsigned int unk00;
    void* transformData;
    unsigned int unk08, unk0c;
    int boneCount;
};

struct ActorPose {
    unsigned int unk00, unk04;
    BoneTree* root;
};

unsigned short __cdecl FUN_00957b20(BoneTree* tree, const char* name, bool required);

struct PoolNode { PoolNode* next; };

struct Arena {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual unsigned char* Expand(unsigned int bytes);
    virtual void FreeBlock(unsigned char* address);
    unsigned int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned char* cursor;
    unsigned int unk024;
    unsigned char* blockStart;
    unsigned char* blockEnd;
    unsigned int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054;
    PoolNode* freeController;
    int freeControllerCount;
    void* FUN_008f6800(unsigned int sizeClass, unsigned int category);
    __forceinline void* AllocateChunk(unsigned int bytes, unsigned int category)
    {
        PoolNode* head = freeController;
        if (head) {
            --freeControllerCount;
            freeController = head->next;
            return head;
        }
        return FUN_008f6800(bytes >> 4, category);
    }
    __forceinline void* Allocate(int bytes)
    {
        bytes = (bytes + 16) & ~15;
        unsigned char* position = cursor;
        unsigned char* after = position + bytes;
        if (after <= blockEnd) {
            cursor = after;
            return position;
        } else {
            return Expand(bytes);
        }
    }
};

__forceinline Arena* ThreadArena()
{
    return reinterpret_cast<Arena*>(TlsGetValue(DAT_010f3170));
}

__forceinline void* AllocateStack(int bytes)
{
    Arena* arena = ThreadArena();
    return arena->Allocate(bytes);
}

template <class T> struct LocalBuffer {
    T* data;
    int unk04;
    __forceinline LocalBuffer(int n) : data(static_cast<T*>(AllocateStack(n * sizeof(T)))) {}
    __forceinline ~LocalBuffer()
    {
        Arena* arena = ThreadArena();
        arena->cursor = (unsigned char*)data;
        if ((unsigned char*)data == arena->blockStart)
            arena->FreeBlock((unsigned char*)data);
    }
    __forceinline T& operator[](int i) { return data[i]; }
    __forceinline T* begin() { return data; }
};

struct RowCopy {
    float x, y, z, w;
    __forceinline void operator=(const RowCopy& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
    }
};

struct BoneMatrix {
    RowCopy row0, row1, row2;
    __forceinline BoneMatrix& operator=(const BoneMatrix& other)
    {
        row0 = other.row0;
        row1 = other.row1;
        row2 = other.row2;
        return *this;
    }
};

struct __declspec(align(16)) Direction {
    float x, y, z, w;
    Direction(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};

struct PoseController {
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    PoseController(unsigned int pelvis, unsigned int head, unsigned int arm, const Direction* direction);
    void FUN_00960bd0(const BoneMatrix* transforms, unsigned int options, float step);
    static void operator delete(void* address);
    __forceinline static void* operator new(unsigned int size) throw()
    {
        return ThreadArena()->AllocateChunk(size, 0xe);
    }
};

struct MatrixSet {
    unsigned int unk00;
    BoneMatrix* bones;
};

struct MatrixCache {
    virtual ~MatrixCache();
    virtual void DeleteThis();
    long references;
    unsigned int unk08, unk0c;
    unsigned int count;
    MatrixSet** sets;
    bool FUN_00944a70(BoneTree* root);
};

struct MatrixCacheRef {
    MatrixCache* cache;

    MatrixCache* operator->() const { return cache; }
    operator MatrixCache*() const { return cache; }

    void Assign(MatrixCache* replacement) {
        if (cache != replacement) {
            if (cache && !InterlockedDecrement(&cache->references))
                cache->DeleteThis();
            cache = replacement;
            if (cache)
                InterlockedIncrement(&cache->references);
        }
    }
};

struct MatrixMap {
    struct Bucket { Bucket* next; const char* name; MatrixCache* cache; };
    virtual ~MatrixMap();
    virtual unsigned Hash(const char*) const;
    virtual bool Equal(const char*, const char*) const;
    unsigned bucketCount;
    Bucket** buckets;
    unsigned entryCount;

    __declspec(noinline) bool FUN_005c8b00(const char* name, MatrixCacheRef& result) {
        for (Bucket* b=buckets[Hash(name)]; b; b=b->next)
            if (Equal(name,b->name)) {
                result.Assign(b->cache);
                return true;
            }
        return false;
    }
};

extern MatrixMap DAT_00f79764;
void __cdecl FUN_009584b0(int count, void* boneData, const BoneMatrix* source, BoneMatrix* destination);

struct Actor {
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned char unk040, unk041;
    bool enabled;
    unsigned char unk043;
    unsigned int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    unsigned int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    unsigned int unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0;
    unsigned int unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
    unsigned int unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0;
    unsigned int unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100;
    unsigned int unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120;
    unsigned int unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140;
    unsigned int unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160;
    unsigned int unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180;
    unsigned int unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0;
    unsigned int unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0;
    unsigned int unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0;
    unsigned int unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200;
    unsigned int unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220;
    unsigned int unk224, unk228, unk22c, unk230, unk234, unk238, unk23c, unk240;
    unsigned int unk244;
    PoseController* controller;
    const char* fixedName;
    MatrixCacheRef matrices;
    bool cacheCoversPose;
    unsigned char unk255, unk256, unk257;
    unsigned int unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274;
    unsigned int unk278, unk27c, unk280, unk284, unk288, unk28c, unk290, unk294;
    unsigned int unk298, unk29c, unk2a0;
    ActorPose* pose;
    bool FUN_008dc690();
    void FUN_008e5190(const char* name, short pelvis, short head, short arm);
};

// pdb: bhkRagdollController::InitPoseMatching | bhkRagdollController.obj | fnv360_0822_retail, strset, low
// pdb params: apFileName, asRootIndex, asBone2Index, asBone3Index
void Actor::FUN_008e5190(const char* name, short pelvis, short head, short arm)
{
    if (enabled == 0)
        return;
    const char* previousName = fixedName;
    if (previousName != name) {
        fixedName = FUN_008242a0(name);
        if (previousName != DAT_00e207a8) {
            FixedNameHeader* header = reinterpret_cast<FixedNameHeader*>(const_cast<char*>(previousName)) - 1;
            InterlockedDecrement(&header->references);
        }
    }
    ActorPose* currentPose = pose;
    BoneTree* root = currentPose->root;
    unsigned int pelvisId, headId, armId;
    if (pelvis != -1)
        pelvisId = static_cast<unsigned short>(pelvis);
    else
        pelvisId = FUN_00957b20(root, DAT_00dfb5f8, false);
    if (head != -1)
        headId = static_cast<unsigned short>(head);
    else
        headId = FUN_00957b20(root, DAT_00dbfbdc, false);
    if (arm != -1)
        armId = static_cast<unsigned short>(arm);
    else
        armId = FUN_00957b20(root, DAT_00dc0844, false);
    Direction axis(0.0f, 0.0f, 1.0f, 0.0f);
    if (!FUN_008dc690() &&
        static_cast<short>(pelvisId) != -1 &&
        static_cast<short>(headId) != -1 &&
        static_cast<short>(armId) != -1)
        return;
    controller = new PoseController(pelvisId, headId, armId, &axis);
    DAT_00f79764.FUN_005c8b00(name, matrices);
    if (!matrices)
        return;
    for (unsigned int i = 0; i < matrices->count; ++i) {
        MatrixSet* set = matrices->sets[i];
        const int count = root->boneCount;
        LocalBuffer<BoneMatrix> localBones(count);
        LocalBuffer<BoneMatrix> resultBones(count);
        for (int j = 0; j < root->boneCount; ++j) {
            BoneMatrix* bone = set->bones;
            localBones[j] = bone[j];
        }
        FUN_009584b0(count, root->transformData, localBones.begin(), resultBones.begin());
        controller->FUN_00960bd0(resultBones.begin(), 0, 0.0f);
    }
    cacheCoversPose = matrices->FUN_00944a70(root);
}

}   // namespace f3m_008e5190

// @f3 0x008e1dd0 (community match, verified in this file)
#include <math.h>

namespace n8e1dd0
{


typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef short hkInt16;
typedef int hkInt32;
typedef unsigned int hkUint32;

namespace hkMath
{
    inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
    inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class hkBool
{
  public:
    hkBool() {}
    hkBool(bool b) { m_bool = static_cast<char>(b); }
    operator bool() const { return m_bool != 0; }
    hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }

  private:
    char m_bool;
};

class hkQuaternion;

class hkVector4
{
  public:
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v);
    __forceinline void operator=(const hkVector4& v);
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d);
    __forceinline hkReal& operator()(int i);
    __forceinline const hkReal& operator()(int i) const;
    __forceinline hkSimdReal getSimdAt(int i) const;
    __forceinline void setAll(hkReal a);
    __forceinline hkSimdReal lengthInverse4() const;
    __forceinline void normalize4();
    __forceinline void setXYZ0(const hkVector4& xyz);
    __forceinline void setReciprocal3(const hkVector4& v);
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a);
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a);
    __forceinline void setNeg4(const hkVector4& v);
    __forceinline void setNeg3(const hkVector4& v);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline hkSimdReal dot3(const hkVector4& a) const;
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

class hkQuaternion
{
  public:
    hkQuaternion() {}
    inline void operator=(const hkQuaternion& q);
    __forceinline const hkVector4& getImag() const;
    inline hkReal getReal() const;
    inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
    inline void setInverse(const hkQuaternion& q);
    inline void normalize();

    hkVector4 m_vec;
};

class hkQsTransform
{
  public:
    __forceinline hkQsTransform() {}
    __forceinline void setInverse(const hkQsTransform& t);
    __forceinline void setMul(const hkQsTransform& aTb, const hkQsTransform& bTc);
    __forceinline void setMulInverseMul(const hkQsTransform& a, const hkQsTransform& b);

    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	return (&x)[i];
}

__forceinline void hkVector4::setXYZ0(const hkVector4& xyz)
{
	x = xyz.x;
	y = xyz.y;
	z = xyz.z;
	w = 0;
}

inline void hkVector4::setReciprocal3(const hkVector4& v)
{
	x = 1.0f / v.x;
	y = 1.0f / v.y;
	z = 1.0f / v.z;
	w = 1.0f;
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

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
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

inline void hkQuaternion::operator= (const hkQuaternion& q)
{
	m_vec = q.m_vec;
}

inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}

inline hkReal hkQuaternion::getReal() const
{
	return m_vec(3);
}

inline void hkQuaternion::setInverse( const hkQuaternion &q )
{
	m_vec.setNeg3( q.getImag() );
}

inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
	hkVector4 vec;
	vec.setCross(q0.getImag(), q1.getImag());
	vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
	vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
	hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.m_vec.dot3( q1.m_vec ) );
	m_vec = vec;
	m_vec(3) = real;
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

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;

	hkVector4 ret;
	ret.setMul4( q2minus1, direction );

	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );

	hkVector4 imagCrossDir;
	imagCrossDir.setCross( direction, quat.getImag() );
	ret.addMul4( qreal, imagCrossDir );

	this->setAdd4( ret, ret );
}

__forceinline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}

__forceinline hkSimdReal hkVector4::lengthInverse4() const
{
	hkReal l2 = (x*x) + (y*y) + (z*z) + (w*w);
	return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize4()
{
	this->mul4( this->lengthInverse4() );
}

inline void hkQuaternion::normalize()
{
	m_vec.normalize4();
}

inline void hkQsTransform::setInverse( const hkQsTransform& t )
{
	m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
	m_translation.setNeg4(m_translation);
	m_rotation.setInverse(t.m_rotation);

	hkVector4 invScale; invScale.setReciprocal3( t.m_scale );
	m_scale.setXYZ0( invScale );
}

inline void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);

	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}

inline void hkQsTransform::setMulInverseMul( const hkQsTransform& a, const hkQsTransform &b )
{
	hkQsTransform h;
	h.setInverse( a );
	setMul(h, b);
}

template <typename T>
class hkArray
{
  public:
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline T* begin() { return m_data; }
    __forceinline const T* begin() const { return m_data; }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

class hkaSkeleton
{
  public:
    const char* m_name;
    hkInt16* m_parentIndices;
    hkInt32 m_numParentIndices;
    void* m_bones;
    hkInt32 m_numBones;
};

class hkaPose
{
  public:
    typedef hkUint32 hkaPoseFlag;
    enum
    {
        F_BONE_LOCAL_DIRTY = 0x1,
        F_BONE_MODEL_DIRTY = 0x2,
        F_BONE_INTERNAL_FLAG1 = 0x4
    };

    void syncModelSpace() const;
    const hkArray<hkQsTransform>& getSyncedPoseLocalSpace() const;
    __forceinline void setBoneLocalSpace(int boneIdx, const hkQsTransform& boneLocal);

    __forceinline int isFlagOn(int boneIdx, hkaPoseFlag enumToCheck) const;
    __forceinline void setFlag(int boneIdx, hkaPoseFlag enumToCheck) const;
    __forceinline void clearFlag(int boneIdx, hkaPoseFlag enumToCheck) const;
    __forceinline int isFlagOnExplicit(hkaPoseFlag flag, hkaPoseFlag enumToCheck) const;
    __forceinline void setFlagExplicit(hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const;
    __forceinline void clearFlagExplicit(hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const;
    __forceinline const hkQsTransform& getBoneModelSpace(int boneIdx) const;
    __forceinline const hkQsTransform& getBoneLocalSpace(int boneIdx) const;
    __forceinline void makeAllChildrenLocalSpace(int boneIdx) const;
    const hkQsTransform& calculateBoneModelSpace(int boneIdx) const;

    const hkaSkeleton* m_skeleton;
    mutable hkArray<hkQsTransform> m_localPose;
    mutable hkArray<hkQsTransform> m_modelPose;
    mutable hkArray<hkaPoseFlag> m_boneFlags;
    mutable hkBool m_modelInSync;
    mutable hkBool m_localInSync;
};

int hkaPose::isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const
{
	return m_boneFlags[boneIdx] & enumToCheck;
}

void hkaPose::setFlag (int boneIdx, hkaPoseFlag enumToCheck) const
{
	m_boneFlags[boneIdx] |= enumToCheck;
}

void hkaPose::clearFlag (int boneIdx, hkaPoseFlag enumToCheck) const
{
	m_boneFlags[boneIdx] &= static_cast<hkaPoseFlag>(~enumToCheck);
}

int hkaPose::isFlagOnExplicit (hkaPoseFlag flag, hkaPoseFlag enumToCheck) const
{
	return flag & enumToCheck;
}

void hkaPose::setFlagExplicit (hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const
{
	flag |= enumToCheck;
}

void hkaPose::clearFlagExplicit (hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const
{
	flag &= static_cast<hkaPoseFlag>(~enumToCheck);
}

const hkQsTransform& hkaPose::getBoneModelSpace (int boneIdx) const
{
	if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY))
	{
		return m_modelPose[boneIdx];
	}
	else
	{
		return calculateBoneModelSpace(boneIdx);
	}
}

const hkQsTransform& hkaPose::getBoneLocalSpace (int boneIdx) const
{
	if (! isFlagOn (boneIdx, F_BONE_LOCAL_DIRTY))
	{
		return m_localPose[boneIdx];
	}
	else
	{
		const hkQsTransform& modelFromBone = m_modelPose[boneIdx];

		const hkInt16 parentIdx = m_skeleton->m_parentIndices[boneIdx];

		if (parentIdx != -1)
		{
			const hkQsTransform& modelFromParent = getBoneModelSpace(parentIdx);

			m_localPose[boneIdx].setMulInverseMul(modelFromParent, modelFromBone);

		}
		else
		{
			m_localPose[boneIdx] = modelFromBone;
		}

		clearFlag (boneIdx, F_BONE_LOCAL_DIRTY);

		return m_localPose[boneIdx];
	}
}

void hkaPose::makeAllChildrenLocalSpace(int boneIdx) const
{
	const int numBones = m_skeleton->m_numBones;

	setFlag(boneIdx, F_BONE_INTERNAL_FLAG1);

	{
		for (int i= boneIdx+1; i<numBones; ++i)
		{
			const hkInt16 parentId = m_skeleton->m_parentIndices[i];
			if (isFlagOn(parentId, F_BONE_INTERNAL_FLAG1))
			{
				getBoneLocalSpace( i );
				setFlag( i, F_BONE_INTERNAL_FLAG1);
				m_modelInSync = false;
			}
		}
	}

	{
		for (int i= boneIdx+1; i < numBones; ++i)
		{
			hkaPoseFlag f = m_boneFlags[i];
			if (isFlagOnExplicit( f, F_BONE_INTERNAL_FLAG1))
			{
				setFlagExplicit( f, F_BONE_MODEL_DIRTY);
				clearFlagExplicit( f, F_BONE_INTERNAL_FLAG1);
				m_boneFlags[i] = f;
			}
		}
	}

}

void hkaPose::setBoneLocalSpace (int boneIdx, const hkQsTransform& boneLocal)
{
	makeAllChildrenLocalSpace(boneIdx);

	m_localPose[boneIdx] = boneLocal;

	m_boneFlags[boneIdx] = F_BONE_MODEL_DIRTY;

	m_modelInSync = false;
}

struct NiPoint3 { float x, y, z; };
struct NiMatrix3 { float m_pEntry[3][3]; };
struct NiTransform
{
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;
};
class NiQuaternion
{
  public:
    float m_fW, m_fX, m_fY, m_fZ;
    void FromRotation(const NiMatrix3& kRot);
};
extern const double DAT_00dbe7c0;

__declspec(noinline) hkQsTransform* __cdecl FUN_008db970(hkQsTransform* out, const NiTransform* in)
{
    NiQuaternion kQuat;
    kQuat.FromRotation(in->m_Rotate);
    out->m_rotation.m_vec.set(kQuat.m_fX, kQuat.m_fY, kQuat.m_fZ, kQuat.m_fW);
    out->m_rotation.normalize();
    hkVector4 translation;
    translation(0) = (hkReal)(in->m_Translate.x * DAT_00dbe7c0);
    translation(1) = (hkReal)(in->m_Translate.y * DAT_00dbe7c0);
    translation(2) = (hkReal)(in->m_Translate.z * DAT_00dbe7c0);
    out->m_translation = translation;
    out->m_scale.setAll(in->m_fScale);
    return out;
}
void* __cdecl FUN_009234e0(void* dst, const void* src, unsigned int n);

struct Attachment {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
    NiTransform transform34;
};
struct Definition { int unk00,unk04,unk08; hkaSkeleton* skeleton; };
struct ScaleConfig {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94;
    float scale98;
};
struct Owner {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54;
    ScaleConfig* config58;
    int unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84;
    hkaPose* pose88;
    int unk8c,unk90;
    hkQsTransform* output94;
    int unk98,unk9c,unka0;
    Attachment** attachmentsa4;
    int unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;
    int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;
    int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;
    int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc;
    int unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc;
    int unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c;
    int unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c,unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c;
    int unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c,unk2a0;
    Definition* definition2a4;
    void bhkRagdollController_GetSGPoseLocalSpace();
};

// pdb: bhkRagdollController::GetSGPoseLocalSpace | bhkRagdollController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Owner::bhkRagdollController_GetSGPoseLocalSpace()
{
    hkReal scale = config58->scale98;
    for (int i = 0; i < definition2a4->skeleton->m_numBones; ++i)
    {
        hkQsTransform transform;
        FUN_008db970(&transform, &attachmentsa4[i]->transform34);
        transform.m_translation.mul4(scale);
        pose88->setBoneLocalSpace(i, transform);
    }
    pose88->syncModelSpace();
    Definition* definition = definition2a4;
    const hkArray<hkQsTransform>& local = pose88->getSyncedPoseLocalSpace();
    FUN_009234e0(output94, local.begin(), definition->skeleton->m_numBones * sizeof(hkQsTransform));
}

}

// @f3 0x008eadd0 (community match, verified in this file)
#include <math.h>
namespace f3m_008eadd0 {

// FO3 x87 Havok build of the character controller's step test for one contact (FNV twin FUN_00c6eb00).

struct hkTransform;

__forceinline float hkFabs(float r) { return (float)fabs(r); }

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void setAbs4(const hkVector4& v) { x = hkFabs(v.x); y = hkFabs(v.y); z = hkFabs(v.z); w = hkFabs(v.w); }
    __forceinline void mul4(float rs) { float s = rs; x *= s; y *= s; z *= s; w *= s; }
    __forceinline float lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
    // Guess at the source: named lane copies give the y, x, z load order of the two squared lengths compared at +0x3a5.
    __forceinline float sqrLength3() const { float fx = x; float fy = y; float fz = z; return (fx * fx) + (fy * fy) + (fz * fz); }
    static __forceinline float sqrtInverse(float r)
    {
        float root = (float)sqrt(r);
        return 1.0f / root;
    }
    __forceinline float lengthInverse3() const
    {
        float l2 = lengthSquared3();
        return (l2 != 0.0f) ? sqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline int compareLessThanEqual4(float limit) const
    {
        return (x <= limit ? 8 : 0) | (y <= limit ? 4 : 0) | (z <= limit ? 2 : 0) | (w <= limit ? 1 : 0);
    }
    __forceinline bool equals4(const hkVector4& v, float epsilon) const
    {
        hkVector4 t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        return (t.compareLessThanEqual4(epsilon) & 0xf) == 0xf;
    }
    __forceinline void setTransformedPos(const hkTransform& t, const hkVector4& b);

    void hkVector4_setTransformedPos(const hkTransform& t, const hkVector4& b);
    void FUN_008d2970(const hkTransform& t, const hkVector4& b);
    void hkVector4_setRotatedDir(const hkTransform& t, const hkVector4& b);
};

struct hkTransform
{
    hkVector4 m_col0, m_col1, m_col2, m_translation;
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2, const hkVector4& t)
        : m_col0(c0), m_col1(c1), m_col2(c2), m_translation(t)
    {
    }
};

__forceinline void hkVector4::setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkTransform& r = t;
    float b0 = b.x;
    float b1 = b.y;
    float b2 = b.z;
    x = r.m_col0.x * b0 + r.m_col1.x * b1 + r.m_col2.x * b2 + r.m_translation.x;
    y = r.m_col0.y * b0 + r.m_col1.y * b1 + r.m_col2.y * b2 + r.m_translation.y;
    z = r.m_col0.z * b0 + r.m_col1.z * b1 + r.m_col2.z * b2 + r.m_translation.z;
    w = 0.0f;
}

struct hkBool
{
    char m_bool;
    __forceinline hkBool() {}
};

struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    unsigned int m_filterInfo;
    const void* m_rayShapeCollectionFilter;
    __forceinline hkpShapeRayCastInput() : m_filterInfo(0), m_rayShapeCollectionFilter(0) {}
};

struct hkpShapeRayCastOutput
{
    hkVector4 m_normal;
    float m_hitFraction;
    int m_extraInfo;
    int unk18, unk1c;
    int m_shapeKeys[8];
    int m_shapeKeyIndex;
    __forceinline hkpShapeRayCastOutput()
    {
        m_hitFraction = 1.0f;
        m_extraInfo = -1;
        m_shapeKeys[0] = -1;
        m_shapeKeyIndex = 0;
    }
};

struct bhkShapeData
{
    int unk00, unk04, unk08, unk0c;
    unsigned int m_flags;
    __forceinline char getFlag(unsigned int n) const { return (unsigned char)(m_flags >> n) & 1; }
    bool FUN_008f76e0(int key, unsigned int flag);
};

struct hkpShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual hkBool castRay(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output) const;
    int m_memSizeAndFlags;
    bhkShapeData* m_userData;
    int m_type;
    __forceinline int getType() const { return m_type; }
};

struct hkpConvexShape : hkpShape
{
    float m_radius;
    int unk14, unk18, unk1c;
    __forceinline float getRadius() const { return m_radius; }
};

struct hkpCapsuleShape : hkpConvexShape
{
    hkVector4 m_vertices[2];
};

struct hkpTriangleShape : hkpConvexShape
{
    hkVector4 m_vertices[3];
};

struct hkpShapeContainer
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10();
    virtual const hkpShape* getChildShape(int key, char* buffer) const;
};

struct hkpShapeCollection : hkpShape, hkpShapeContainer
{
};

struct hkpBvTreeShape : hkpShape
{
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    const hkpShape* m_child;
};

struct hkpCollidable
{
    const hkpShape* m_shape;
    int unk04, unk08, unk0c;
    signed char m_ownerOffset;
    unsigned char unk11, unk12, unk13;
    int unk14;
    unsigned char m_type;
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline void* getOwner() const { return (char*)this + m_ownerOffset; }
};

struct hkpPhantom
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    hkTransform m_transform;
    __forceinline const hkTransform& getTransform() const { return m_transform; }
};

struct hkpRigidBody
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    hkTransform m_transform;
    __forceinline const hkTransform& getTransform() const { return m_transform; }
};

__forceinline hkpPhantom* hkGetPhantom(const hkpCollidable* collidable)
{
    if (collidable->m_type == 2)
        return static_cast<hkpPhantom*>(collidable->getOwner());
    return 0;
}

__forceinline hkpRigidBody* hkGetRigidBody(const hkpCollidable* collidable)
{
    if (collidable->m_type == 1)
        return static_cast<hkpRigidBody*>(collidable->getOwner());
    return 0;
}

struct hkpRootCdPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
    const hkpCollidable* m_rootCollidableA;
    int m_shapeKeyA;
    const hkpCollidable* m_rootCollidableB;
    int m_shapeKeyB;
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
    __forceinline float getDistance() const { return m_separatingNormal.w; }
};

struct PointTriangleDistanceCache
{
    float m_invEdgeLen[3];
    float m_normalLen;
    float m_invNormalLen;
};

void __cdecl FUN_0096fd30(const hkVector4* triVertices, PointTriangleDistanceCache* cache);
void __cdecl FUN_0096e450(const hkVector4* capsulePoints, float capsuleRadius, const hkVector4* triVertices,
                          float triRadius, const PointTriangleDistanceCache* cache, float tolerance, int searchManifold,
                          hkContactPoint* points);

struct ParentPrefix
{
    virtual void pv00();
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
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
    int unk280, unk284, unk288, unk28c;
};

struct ListenerC
{
    virtual void lv00();
    void FUN_008dae80(int index, float height);
};

struct ParentC : ParentPrefix, ListenerC
{
    unsigned int flags;
    int unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    int unk2e0, unk2e4, unk2e8, unk2ec;
    float height;
    float unk2f4;
    int unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c;
    int unk430;
    int unk434, unk438, unk43c;
    hkVector4 m_points[2];
    int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    float m_radius;
    float m_halfHeight;

    bool FUN_008ea9c0(hkpRootCdPoint* contact);
    void FUN_008ea1f0(hkVector4* position);
    bool FUN_008eadd0(hkpRootCdPoint* contact);
};

// pdb: bhkCharacterController::IsStep | bhkCharacterController.obj | fnv360_0721_beta, objrun, medium
// pdb params: arPoint
bool ParentC::FUN_008eadd0(hkpRootCdPoint* contact)
{
    if (unk430 == 1)
        return FUN_008ea9c0(contact);

    hkpPhantom* phantom = hkGetPhantom(contact->m_rootCollidableA);
    hkpRigidBody* body = hkGetRigidBody(contact->m_rootCollidableB);
    bool result = true;
    if (phantom && body)
    {
        const hkpShape* shapeB = contact->m_rootCollidableB->getShape();
        const hkpShape* shapeA = contact->m_rootCollidableA->getShape();
        result = false;
        const hkpCapsuleShape* capsule;
        float radius;
        if (shapeA->getType() == 6)
        {
            capsule = static_cast<const hkpCapsuleShape*>(shapeA);
            radius = capsule->getRadius();
        }
        else
        {
            radius = m_radius;
            capsule = 0;
        }
        hkpShapeRayCastInput input;
        // Guess at the source: both body transform copies go through four column temporaries (separate stack temps in the
        // target); a plain hkTransform copy gives other x87 operand orders in the triangle loop.
        hkVector4 col0 = body->getTransform().m_col0;
        hkVector4 col1 = body->getTransform().m_col1;
        hkVector4 col2 = body->getTransform().m_col2;
        hkVector4 col3 = body->getTransform().m_translation;
        hkTransform transform(col0, col1, col2, col3);
        hkpShapeRayCastOutput output;
        hkVector4 pos = contact->m_position;
        float posZ = pos.z;
        hkVector4 q;
        FUN_008ea1f0(&q);
        int idx = 0;
        hkVector4 dir;
        if (flags & 1)
        {
            hkVector4 diff[2];
            for (unsigned int i = 0; i < 2; i++)
            {
                hkVector4 p;
                if (capsule)
                    p = capsule->m_vertices[i];
                else
                {
                    // The double halfHeight * 0.5 converts implicitly; an explicit (float) moves the operand order of later adds.
                    p.set(0.0f, m_halfHeight * 0.5, radius, 0.0f);
                    if (i == 1)
                        p.y = (float)(p.y * -1.0);
                }
                m_points[i].hkVector4_setTransformedPos(phantom->getTransform(), p);
                // Guess at the source: the lane writes through operator() below set which operand of the two "+= height"
                // adds is loaded first (height first here at +0x34d, q.z first at +0x58a).
                m_points[i](2) += height;
                diff[i].setSub4(pos, m_points[i]);
            }
            if (diff[0].sqrLength3() < diff[1].sqrLength3())
                idx = 0;
            else
                idx = 1;
            q.x = m_points[idx].x;
            q.y = m_points[idx].y;
            dir.setSub4(q, pos);
            dir.z = 0.0f;
            dir.normalize3();
        }
        else
        {
            dir.setSub4(q, pos);
            dir.z = 0.0f;
            dir.normalize3();
        }
        bool blocked = false;
        q(2) += height;
        pos.z = q(2);
        float step = posZ - q(2);
        if (step > 0.0f)
        {
            if (step > height / 3.0)
            {
                if (!(flags & 1))
                    return true;
                step = posZ - m_points[idx].z + height;
                if (step > 0.0f)
                {
                    if (step > height / 3.0)
                        return true;
                    blocked = true;
                }
            }
            else
                blocked = true;
        }
        int key = contact->m_shapeKeyB;
        if (key != -1)
        {
            const hkpShape* shape = shapeB;
            int type = shape->getType();
            if (type == 11)
            {
                shape = static_cast<const hkpBvTreeShape*>(shape)->m_child;
                type = shape->getType();
            }
            if (type == 22)
            {
                __declspec(align(16)) char buffer[512];
                const hkpTriangleShape* triangle = static_cast<const hkpTriangleShape*>(
                    static_cast<const hkpShapeCollection*>(shape)->getChildShape(key, buffer));
                hkVector4 c0 = body->getTransform().m_col0;
                hkVector4 c1 = body->getTransform().m_col1;
                hkVector4 c2 = body->getTransform().m_col2;
                hkVector4 c3 = body->getTransform().m_translation;
                hkTransform t(c0, c1, c2, c3);
                hkVector4 vertices[3];
                int i = 2;
                do
                {
                    vertices[i].setTransformedPos(t, triangle->m_vertices[i]);
                } while (--i >= 0);
                PointTriangleDistanceCache cache;
                FUN_0096fd30(vertices, &cache);
                hkVector4 capsulePoints[2];
                capsulePoints[0] = pos;
                capsulePoints[1] = pos;
                // Guess at the source: dir read through operator() loads the lane before unk2f4 (+0x85d).
                capsulePoints[1].x -= dir(0) * unk2f4;
                capsulePoints[1].y -= dir(1) * unk2f4;
                hkContactPoint points[3];
                FUN_0096e450(capsulePoints, 0.5f, vertices, triangle->getRadius(), &cache, 0.0f, 0, points);
                bool hit = points[0].getDistance() < 0.0f || points[1].getDistance() < 0.0f;
                if (hit)
                {
                    bhkShapeData* data = shape->m_userData;
                    if (data && data->getFlag(6))
                        hit = false;
                }
                else if (blocked)
                    hit = true;
                if ((flags & 1) && !hit)
                    ListenerC::FUN_008dae80(idx, contact->m_position.z);
                return hit;
            }
        }
        hkVector4 to = q;
        float reach = unk2f4 + radius;
        to.x -= dir.x * reach;
        // Guess at the source: reading dir's y lane through operator() here is what gives the y lane of the earlier
        // dir.normalize3() its target order (fld [dir.y]; fmul st(1) at +0x56a); with dir.y here it is fld st(0); fmul [dir.y].
        to.y -= dir(1) * reach;
        q.x += dir.x * reach;
        q.y += dir(1) * reach;
        input.m_from.FUN_008d2970(transform, q);
        input.m_to.FUN_008d2970(transform, to);
        shapeB->castRay(input, output);
        if (output.m_hitFraction < 1.0f)
        {
            int hitKey = -1;
            for (int k = 0; 8 > k; ++k)
            {
                int next = output.m_shapeKeys[k];
                if (next == -1)
                    break;
                hitKey = next;
            }
            hkVector4 normal;
            bool sameKey = true;
            if (hitKey != contact->m_shapeKeyB)
            {
                normal.hkVector4_setRotatedDir(transform, output.m_normal);
                if (!normal.equals4(dir, 0.01f))
                    sameKey = false;
            }
            if (sameKey)
            {
                result = true;
                bhkShapeData* data = shapeB->m_userData;
                if (data && data->FUN_008f76e0(hitKey, 0x40))
                    result = false;
            }
            else if (blocked)
                result = true;
        }
        if ((flags & 1) && !result)
            ListenerC::FUN_008dae80(idx, contact->m_position.z);
    }
    return result;
}
}   // namespace f3m_008eadd0

// @f3 0x008efe30 (community match, verified in this file)
// 0x008efe30: character controller move routine (x87 build of the physics library), from the earlier drafts.
// Worked under /MT /O2 /GS /EHsc /Gy (the pack lists /Od; the target is /O2 code: aligned ebp frame).
#include <math.h>
#include <stddef.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace N8efe30 {

extern unsigned long DAT_0116913c;   // monitor stream thread slot
extern const char DAT_00e33808[];
extern const char DAT_00e337ec[];
extern const double DAT_00dbe7c0;
extern const float DAT_00e337e8;   // 0.13725491f colour alpha (loaded with fld: not a visible literal)

struct Flags
{
    unsigned int value;
    __forceinline void Or(unsigned int m) { value |= m; }
    __forceinline void Clear(unsigned int m) { value &= ~m; }
    __forceinline void Set(unsigned int m, bool on) { if (on) Or(m); else Clear(m); }
    __forceinline bool Bit(int n) const { return (value >> n) & 1; }
};

class Bool
{
public:
    __forceinline Bool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }
    char m_bool;
};

struct TraceEntry
{
    const char* label;
    unsigned long tick;
    unsigned long unused;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        tick = ticks;
    }
};

template <typename T>
class Pad
{
public:
    __forceinline T& val() { return m_storage; }
    __forceinline void operator=(const T& p) { m_storage = p; }
    T m_storage;
};

struct TraceBuffer
{
    Pad<char*> m_start, m_end, m_cursor, m_capacityMinus16;
    static __forceinline TraceBuffer& getInstance() { return *(TraceBuffer*)TlsGetValue(DAT_0116913c); }
    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline Bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }
};

__forceinline void Trace(const char* label)
{
    TraceBuffer& stream = TraceBuffer::getInstance();
    if (stream.memoryAvailable())
    {
        TraceEntry* h = reinterpret_cast<TraceEntry*>(stream.getEnd());
        h->label = label;
        h->setTime();
        stream.setEnd((char*)(h + 1));
    }
}

__forceinline float Fabs(float r) { return (float)fabs(r); }
__forceinline float Sqrt(float r) { return (float)sqrt(r); }

class __declspec(align(16)) Vec
{
public:
    float x, y, z, w;
    __forceinline Vec() {}
    __forceinline Vec(const Vec& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const Vec& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void setNeg4(const Vec& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
    __forceinline void setAdd4(const Vec& a, const Vec& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void setSub4(const Vec& a, const Vec& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void setAbs4(const Vec& v) { x = Fabs(v.x); y = Fabs(v.y); z = Fabs(v.z); w = Fabs(v.w); }
    __forceinline void setMul4(float rs, const Vec& a) { float r = rs; x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    __forceinline void addMul4(float rs, const Vec& a) { float r = rs; x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    // Guess at the source: this grouping gives the x, y, z product order of the velocity length at +0xb67.
    __forceinline float lengthSquared3() const { return (x * x) + y * y + (z * z); }
    __forceinline void setCross(const Vec& v1, const Vec& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline float dot3(const Vec& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline float length3() const { return Sqrt((x * x) + (y * y) + (z * z)); }
    __forceinline int compareLessThanEqual4(float limit) const
    {
        return (x <= limit ? 8 : 0) | (y <= limit ? 4 : 0) | (z <= limit ? 2 : 0) | (w <= limit ? 1 : 0);
    }
    __forceinline bool equals3(const Vec& v, float epsilon = 1e-3f) const
    {
        Vec t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        return (t.compareLessThanEqual4(epsilon) & 0xe) == 0xe;
    }
    __forceinline bool equals4(const Vec& v, float epsilon = 1e-3f) const
    {
        Vec t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        return (t.compareLessThanEqual4(epsilon) & 0xf) == 0xf;
    }
    __forceinline void setRotatedDir(const Vec& quat, const Vec& direction)
    {
        float qreal = quat.w;
        float q2minus1 = qreal * qreal - 0.5f;
        Vec ret;
        ret.setMul4(q2minus1, direction);
        float imagDotDir = quat.dot3(direction);
        ret.addMul4(imagDotDir, quat);
        Vec imagCrossDir;
        imagCrossDir.setCross(quat, direction);
        ret.addMul4(qreal, imagCrossDir);
        setAdd4(ret, ret);
    }
};

struct NiPoint3
{
    float x, y, z;
    __forceinline void operator*=(float f) { x *= f; y *= f; z *= f; }
    bool FUN_00914730(const NiPoint3& other) const;
};

struct Colour
{
    float r, g, b;
    __forceinline Colour() {}
    __forceinline Colour(float fr, float fg, float fb) { r = fr; g = fg; b = fb; }
};

extern Vec DAT_01092a50;        // zero vector
extern NiPoint3 DAT_0108ec68;   // zero point
extern float DAT_010f2e90;
extern float DAT_010f2e80;
extern float DAT_00f79ae0;
extern double DAT_00db5748;

__forceinline const Vec& Zero() { return DAT_01092a50; }

struct MovementInput
{
    float dt, angle, unk08, speed;
    NiPoint3 displacement;
    unsigned int unk1c;
    float scale;
    bool active;
};

struct Rotation
{
    Vec q;
    void FUN_009240d0(const Vec* axis, float angle);
};

struct State
{
    unsigned unk00, unk04, unk08;
    int FUN_00919ef0();
};

struct Action
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void update(void*);
};

struct ActionSet { Action* FUN_0092f420(unsigned int); };

struct Entity { void FUN_009316f0(); };
struct EntityRef
{
    Entity* m_p;
    __forceinline void Clear() { if (m_p) { m_p->FUN_009316f0(); m_p = 0; } }
};

struct RefObj
{
    virtual ~RefObj();
    unsigned short memSizeAndFlags;
    short referenceCount;
    __forceinline void removeReference()
    {
        if (memSizeAndFlags != 0)
        {
            --referenceCount;
            if (referenceCount == 0)
                delete this;
        }
    }
};

struct Hit
{
    Vec normal, position;
    unsigned int material, unk24;
    unsigned int object, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    void FUN_00568710(const Hit* other);
};

void __cdecl FUN_00901f10(void* array, int elementSize);

struct HitArray
{
    Hit* data;
    int size;
    int capacity;
    __forceinline void pushBack(const Hit* src)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(Hit));
        data[size++].FUN_00568710(src);
    }
};

struct WorldDraw
{
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
    unsigned count;
    void FUN_008d5730(unsigned, unsigned);
};

struct World
{
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
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    WorldDraw* draw;
};

struct WorldObject
{
    unsigned unk00, unk04;
    World* world;
};

struct Body
{
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
    int mode;
    HitArray* FUN_0091dd50();
    Vec* FUN_0091dd60();
    void hkpCharacterProxy_setPosition(Vec*);
    Vec* FUN_0091dda0();
    void hkpCharacterProxy_setLinearVelocity(Vec*);
    WorldObject* FUN_0091ddd0();
    void FUN_009215d0(Vec*, unsigned*);
};

struct Gravity
{
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
    float acceleration;
};
extern Gravity* DAT_010f2e84;

struct Property
{
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
    Colour colour;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned revision;
    __forceinline void setColour(const Colour& c) { colour = c; revision++; }
};

struct Node { Property* FUN_00826590(int); };

bool __cdecl FUN_00464d70(NiPoint3*, NiPoint3*, float);
unsigned __cdecl FUN_00921880(float, float, float, float);

__forceinline void ToPhysics(Vec* out, NiPoint3 in)
{
    out->x = in.x * 0.1428767293691635;
    out->y = in.y * 0.1428767293691635;
    out->z = in.z * 0.1428767293691635;
}

struct ControllerBase
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
    virtual int Ready();
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
    virtual void Notify(unsigned, float);
};

struct Controller : ControllerBase
{
    unsigned unk004;
    Body* body;
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
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    State state;
    ActionSet* actions;
    unsigned actionIndex;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    Flags fl;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    float slopeLimit;
    unsigned value2b4;
    unsigned value2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    Vec surfaceNormal;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned char byte2f8;
    unsigned char byte2f9;
    unsigned char byte2fa;
    unsigned char byte2fb;
    unsigned unk2fc;
    unsigned support;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    Vec vec320;
    unsigned unk330;
    unsigned unk334;
    unsigned unk338;
    unsigned unk33c;
    Vec desiredVelocity;
    unsigned value350;
    unsigned unk354;
    unsigned unk358;
    unsigned unk35c;
    Vec axis;
    Vec normal;
    unsigned value380;
    unsigned unk384;
    float stepTime;
    float inverseStepTime;
    Vec velocity;
    Vec extraVelocity;
    float timer3b0;
    float value3b4;
    float value3b8;
    float timer3bc;
    unsigned unk3c0;
    float value3c4;
    unsigned unk3c8;
    unsigned unk3cc;
    unsigned unk3d0;
    unsigned unk3d4;
    unsigned unk3d8;
    unsigned unk3dc;
    unsigned unk3e0;
    unsigned unk3e4;
    unsigned unk3e8;
    unsigned unk3ec;
    unsigned unk3f0;
    float scale3f4;
    unsigned unk3f8;
    unsigned unk3fc;
    unsigned unk400;
    unsigned unk404;
    float value408;
    unsigned unk40c;
    unsigned unk410;
    unsigned unk414;
    unsigned unk418;
    unsigned unk41c;
    unsigned unk420;
    unsigned value424;
    unsigned unk428;
    unsigned unk42c;
    unsigned unk430;
    unsigned unk434;
    unsigned unk438;
    unsigned unk43c;
    unsigned unk440;
    unsigned unk444;
    unsigned unk448;
    unsigned unk44c;
    unsigned unk450;
    unsigned unk454;
    unsigned unk458;
    unsigned unk45c;
    unsigned unk460;
    unsigned unk464;
    unsigned unk468;
    unsigned unk46c;
    unsigned unk470;
    unsigned unk474;
    unsigned unk478;
    unsigned unk47c;
    unsigned unk480;
    unsigned unk484;
    unsigned unk488;
    unsigned unk48c;
    unsigned unk490;
    unsigned unk494;
    unsigned unk498;
    unsigned unk49c;
    unsigned unk4a0;
    unsigned unk4a4;
    unsigned unk4a8;
    unsigned unk4ac;
    unsigned unk4b0;
    unsigned unk4b4;
    unsigned unk4b8;
    unsigned unk4bc;
    EntityRef ref4c0;
    float value4c4;
    RefObj* ref4c8;
    HitArray hits;

    void FUN_008ecfc0();
    void FUN_008e8f70();
    bool FUN_008e8f40();
    void bhkCharacterController_ChangeSize(float);
    float FUN_008e8970(float, float);
    void FUN_008ea300(Rotation*);
    void FUN_008ea6d0();
    void FUN_008ef910(float);
    void FUN_008e8c80(unsigned*);
    void FUN_008ecb40();
    Node* FUN_008e9f00();
    void FUN_0092ac40();
    Vec* FUN_006a3050();
    Body* FUN_00568660();

    __forceinline WorldObject* getWorldObject() { return body ? body->FUN_0091ddd0() : 0; }
    __forceinline World* getWorld() { return getWorldObject()->world; }
    __forceinline WorldDraw* getDraw() { World* w = getWorld(); return w ? w->draw : 0; }
    __forceinline void draw(unsigned id, unsigned packed) { getDraw()->FUN_008d5730(id, packed); }
    __forceinline Vec* getBodyVelocity() { return body ? body->FUN_0091dda0() : &DAT_01092a50; }
    __forceinline void setBodyVelocity(Vec* v) { if (body) body->hkpCharacterProxy_setLinearVelocity(v); }
    __forceinline void checkSupport(Vec* direction, unsigned* out)
    {
        Body* b = body;
        if (b)
        {
            FUN_0092ac40();
            b->FUN_009215d0(direction, out);
            FUN_0092ac40();
        }
    }

    int bhkCharacterController_Move(MovementInput* in);
};

// Visible body of the same-file speed helper: the caller keeps the input pointer in edx across this call, which the
// compiler only does when it has seen that the callee leaves edx alone. Ported from the callee's code by meaning;
// it has not been checked byte for byte on its own.
__declspec(noinline) float Controller::FUN_008e8970(float angle, float time)
{
    if (value3b8 > 0)
    {
        float step = value3b8;
        if (step > time)
            step = time;
        angle += value3b4 * step;
        value3b8 -= time;
        value3b4 -= 0.05000000074505806;
    }
    else
        value3b4 = 0;
    return angle;
}

typedef char check_flags[(offsetof(Controller, fl) == 0x294) ? 1 : -1];
typedef char check_axis[(offsetof(Controller, axis) == 0x360) ? 1 : -1];
typedef char check_hits[(offsetof(Controller, hits) == 0x4cc) ? 1 : -1];
typedef char check_hit[(sizeof(Hit) == 0x40) ? 1 : -1];

// pdb: bhkCharacterController::Move | bhkCharacterController.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
int Controller::bhkCharacterController_Move(MovementInput* in)
{
    int result = 0;
    bool changed;
    fl.Clear(0xc0);
    FUN_008ecfc0();
    ref4c0.Clear();
    value4c4 = 0;
    if (ref4c8)
    {
        ref4c8->removeReference();
        ref4c8 = 0;
    }
    scale3f4 = in->scale / DAT_010f2e90;
    int ready = Ready();
    bool skip = in->dt <= DAT_00db5748 || !ready;
    if (!skip)
    {
        if (fl.Bit(22))
        {
            if (getDraw()->count > 0)
                goto done;
            fl.Clear(0x400000);
        }
        float dt = in->dt;
        bool idle = FUN_00464d70(&in->displacement, &DAT_0108ec68, 0.05f);
        bool mode19 = fl.Bit(19);
        bool mode20 = fl.Bit(20);
        if (!idle)
        {
            FUN_008e8f70();
            value3b4 = 0;
            value3b8 = 0;
        }
        idle &= extraVelocity.equals3(Zero());
        if (!idle)
            fl.Or(8);
        else
            fl.Clear(8);
        Trace(DAT_00e33808);
        {
            Vec negAxis;
            Rotation rot;
            int iterations = 1;
            bhkCharacterController_ChangeSize(dt);
            value2b4 = 0x20;
            value2b8 = 0;
            in->speed = FUN_008e8970(in->speed, in->dt);
            rot.FUN_009240d0(&axis, -in->speed);
            stepTime = in->dt;
            inverseStepTime = 1.0f / in->dt;
            NiPoint3* displacement = &in->displacement;
            {
                // The by-value NiPoint3 of ToPhysics and the member passed straight to operator*= give the target's
                // lane order of the scale (x lane loads x first, y lane duplicates the factor).
                NiPoint3 temp = *displacement;
                if (state.FUN_00919ef0() != 5 && !fl.Bit(11))
                    temp.z = 0;
                temp *= inverseStepTime;
                ToPhysics(&desiredVelocity, temp);
            }
            if (FUN_008e8f40() && in->angle != 0)
            {
                Vec axisAngle;
                axisAngle.set(-1.0f, 0.0f, 0.0f, 0.0f);
                Rotation q;
                q.FUN_009240d0(&axisAngle, in->angle);
                desiredVelocity.setRotatedDir(q.q, desiredVelocity);
            }
            // Guess at the source (earlier draft): storing through a pointer places the flag-word load ahead of the
            // first axis lane load.
            float* stepOut = &value408;
            *stepOut = value3c4;
            Vec down;
            down.x = 0.0f; down.y = -1.0f; down.z = 0.0f; down.w = 0.0f;
            negAxis.setNeg4(axis);
            if (fl.Bit(25) || fl.Bit(26) || fl.Bit(0))
                FUN_008ea300(&rot);
            Vec rotated;
            rotated.setRotatedDir(rot.q, down);
            if (!idle || !rotated.equals3(normal))
                timer3bc = DAT_00f79ae0;
            changed = true;
            normal = rotated;
            Body* savedBody = body;
            if (mode19)
            {
                velocity = *FUN_006a3050();
                vec320 = Zero();
                Trace(DAT_00e337ec);
                actions->FUN_0092f420(actionIndex)->update(this);
                Trace("Et");
                setBodyVelocity(&velocity);
                FUN_008ef910(stepTime);
            }
            else
            {
                while (iterations--)
                {
                    DAT_010f2e84 = 0;
                    velocity = *getBodyVelocity();
                    if (idle && state.FUN_00919ef0() != 2)
                        velocity.z = 0;
                    if (in->active || state.FUN_00919ef0() != 0 || !displacement->FUN_00914730(DAT_0108ec68) ||
                        surfaceNormal.equals4(Zero()))
                    {
                        fl.Clear(0x600);
                        fl.Or(0x10000);
                        FUN_008ea6d0();
                        unsigned& supportState = support;
                        checkSupport(&negAxis, &supportState);
                        fl.Clear(0x10000);
                        bool contact = supportState == 2 && !byte2f8;
                        if (fl.value & 0x2000)
                        {
                            if (!(contact || fl.Bit(9)) || velocity.z <= 0)
                            {
                                fl.Clear(0x2000);
                            }
                            else
                            {
                                Vec vStore; Vec& v=vStore; v=velocity;
                                float length = Sqrt(v.lengthSquared3());
                                if (length > 0)
                                {
                                    // Guess at the source: the scale written per lane, the y, z and w lanes on the local itself and
                                    // the x lane through the reference, gives the target's lane order at +0xbb3 (x: factor copied
                                    // first; y: lane loaded first); the inline mul4(1 / length) copies the factor first in both.
                                    float inv = 1.0f / length;
                                    v.x *= inv;
                                    vStore.y *= inv;
                                    vStore.z *= inv;
                                    vStore.w *= inv;
                                    if (contact && fl.Bit(9) && surfaceNormal(2) >= slopeLimit)
                                    {
                                        float dot = surfaceNormal.dot3(v);
                                        if (dot <= 0.05000000074505806)
                                            fl.Clear(0x2000);
                                    }
                                }
                            }
                            contact = false;
                        }
                        else
                            contact |= fl.Bit(9);
                        fl.Set(0x100, contact);
                    }
                    Trace(DAT_00e337ec);
                    actions->FUN_0092f420(actionIndex)->update(this);
                    Trace("Et");
                    setBodyVelocity(&velocity);
                    changed = true;
                    if (idle && state.FUN_00919ef0() != 2 && (state.FUN_00919ef0() != 5 || velocity.z == 0) &&
                        savedBody->FUN_0091dd50()->size <= hits.size)
                    {
                        changed = false;
                        for (int i = 0; !changed; ++i)
                        {
                            HitArray* loopArray = savedBody->FUN_0091dd50();
                            if (i >= loopArray->size)
                                break;
                            HitArray* currentArray = savedBody->FUN_0091dd50();
                            if (!hits.data[i].normal.equals4(currentArray->data[i].normal))
                                changed = true;
                            else
                            {
                                currentArray = savedBody->FUN_0091dd50();
                                // Guess at the source (earlier draft): the entry pointer is first computed inside the
                                // condition, after the position compare (keeps &hits.data[i] in edi for the material compare).
                                Hit* previous;
                                if (!hits.data[i].position.equals4(currentArray->data[i].position) ||
                                    (previous = &hits.data[i], previous->material != savedBody->FUN_0091dd50()->data[i].material))
                                    changed = true;
                                else
                                {
                                    Hit& previousObject = hits.data[i];
                                    if (previousObject.object != savedBody->FUN_0091dd50()->data[i].object)
                                        changed = true;
                                }
                            }
                        }
                    }
                    if (changed)
                    {
                        if (mode20)
                            savedBody->mode = 1;
                        else
                            savedBody->mode = 4;
                        FUN_008e8c80(&value380);
                        savedBody->mode = 4;
                    }
                    else
                    {
                        velocity = Zero();
                        setBodyVelocity(&velocity);
                    }
                    if (DAT_010f2e84 && !(fl.value & 0x2000))
                    {
                        FUN_0092ac40();
                        Body* target = FUN_00568660();
                        Vec position = *target->FUN_0091dd60();
                        float gravity = DAT_010f2e84->acceleration * stepTime;
                        position.z = value408 + DAT_010f2e80 + gravity;
                        target->hkpCharacterProxy_setPosition(&position);
                        position.z = gravity + DAT_010f2e80;
                        FUN_0092ac40();
                    }
                    value350 = 11;
                }
                int size = savedBody->FUN_0091dd50()->size;
                int n = size > 5 ? 5 : size;
                for (int i = 0; i < n; ++i)
                {
                    if (i < hits.size)
                        hits.data[i].FUN_00568710(&savedBody->FUN_0091dd50()->data[i]);
                    else
                        hits.pushBack(&savedBody->FUN_0091dd50()->data[i]);
                }
            }
        }
        if (fl.Bit(25) || fl.Bit(26))
            FUN_008ecb40();
        if (fl.value & 0xc0)
            result = 2;
        Colour picked;
        if (fl.Bit(2))
            picked = Colour(1.0f, 0.2f, 0.0f);
        else if (!changed)
            picked = Colour(0.0f, 1.0f, 0.2f);
        else
        {
            switch (state.FUN_00919ef0())
            {
            case 2:
                picked = Colour(0.0f, 0.5f, 1.0f);
                break;
            case 5:
                picked = Colour(0.5f, 0.0f, 0.5f);
                break;
            default:
                picked = Colour(1.0f, 1.0f, 0.0f);
                break;
            }
        }
        Colour colour = picked;
        if (getDraw())
        {
            unsigned packed = FUN_00921880(colour.r, colour.g, colour.b, DAT_00e337e8);
            draw(value424, packed);
        }
        Notify(in->unk1c, in->speed);
        Node* node = FUN_008e9f00();
        if (node)
        {
            Property* property = node->FUN_00826590(2);
            if (property)
                property->setColour(colour);
        }
        Trace("Et");
        if (timer3b0 > 0)
        {
            float remaining = timer3b0 - dt;
            timer3b0 = remaining;
            if (remaining <= 0)
            {
                timer3b0 = 0;
                extraVelocity.setZero4();
            }
        }
        if (timer3bc > 0)
            timer3bc -= dt;
        fl.Clear(0x1000);
    done:;
    }
    return result;
}

}

// @f3 0x008ee9e0 (community match, verified in this file)
namespace Task3122 {
// FUN_008ee9e0: builds the character controller's collision shapes (capsules / list shape) and the optional
// AABB phantom and sphere phantom. Started from the FNV-twin reconstruction (ShapeOwner::FUN_00c72410).
// The original is optimised code: it matches under /MT /O2 /GS /EHsc /Gy (the pack lists /Od).

struct NiPoint3;
struct ShapeRef;
struct ShapeInput;
struct NodeBounds;
struct Bound;
struct Geometry;



extern float DAT_00f7a690;
extern Bound DAT_0108edc8;
extern NiPoint3 DAT_0108ec68;

struct ShapeRef
{
    virtual void Reserved();
    virtual void Destroy();
    long references;
    void* shape;
    int unk0c;
    float radius;
};

struct ShapePointer
{
    ShapeRef* m_pObject;
    void FUN_008e9650(ShapeRef* in);
    ShapePointer& operator=(ShapeRef* in) { FUN_008e9650(in); return *this; }
    void FUN_008e9600(ShapePointer const&);
};

struct NiPoint3
{
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float a,float b,float c):x(a),y(b),z(c) {}
    NiPoint3 operator-(NiPoint3 const& v) const {return NiPoint3(x-v.x,y-v.y,z-v.z);}
    NiPoint3 FUN_00432b40(float scale) const;
    float FUN_00432bd0() const;
};

struct __declspec(align(16)) Bound
{
    float x, y, z, radius;
};

struct Geometry
{
    int unk00, unk04, unk08;
    NiPoint3 center;
    NiPoint3 extents;
};

struct NodeBounds
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Bound* bound; void FUN_0091dd60();
};

void __cdecl FUN_00901f10(void*, int);
struct RawArray
{
    void** data;
    int count;
    unsigned int capacity;
    __forceinline void Add(void* value) { if(count == (capacity & 0x3fffffff)) FUN_00901f10(this,4); data[count++]=value; }
};

struct CompoundInfo
{
    int material;
    RawArray shapes;
    RawArray extra;
    CompoundInfo():material(0) {shapes.data=0;shapes.count=0;shapes.capacity=0x80000000;extra.data=0;extra.count=0;extra.capacity=0x80000000;}
    void FUN_008ec9f0();
    ~CompoundInfo() { FUN_008ec9f0(); }
};

struct ShapeInput
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048;
    float margin;
    float maxSize;
    int unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c;
    NodeBounds* node;
    unsigned int flags;
    int unk088, unk08c, unk090;
    bool flag94; unsigned char flag95, flag96, flag97;
    bool HasPhantom() const { return flag94; }
    int unk098, unk09c;
    ShapeRef* existingShape;
    int unk0a4, unk0a8;
    float scale;
    unsigned int index;
    ShapeRef* GetShape() const { return existingShape; }
    float GetScale() const { return scale; }
    unsigned int GetIndex() const { return existingShape ? 0 : index; }
};

Geometry* __cdecl BSBound_Find(NodeBounds*);
ShapeRef* __cdecl FUN_008e8880(NiPoint3*, NiPoint3*, float);
ShapeRef* __cdecl FUN_008ec700(NiPoint3 const&, NiPoint3 const&, float, float);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
struct TLSHeap {void* FUN_008f6d30(int,int);void FUN_008f6d90(void*,int,int);};
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*,unsigned);
void __cdecl FUN_008d36a0(void*);
void __cdecl FUN_00951b90(void*);

struct HavokHeap { void* FUN_0086b930(unsigned int size); };
extern HavokHeap DAT_01090a78;

struct FUN_0091da10 : ShapeRef
{
    FUN_0091da10(NiPoint3 const&, NiPoint3 const&, float);
    static void* operator new(unsigned int n) {return FUN_0089eb90(n);}
    static void operator delete(void* p,unsigned n) { FUN_0089ec10(p,n); }
};

struct FUN_008e9020 : ShapeRef
{
    FUN_008e9020(CompoundInfo const&);
    static void* operator new(unsigned int n) {return FUN_0089eb90(n);}
    static void operator delete(void* p,unsigned n) { FUN_0089ec10(p,n); }
};

struct FUN_00970f60 {
    int vtable; unsigned short size, refs; int unk08,unk0c;float radius;int unk14,unk18,unk1c;
    FUN_00970f60(float);
    static void* operator new(unsigned int n) { TLSHeap* mem=(TLSHeap*)TlsGetValue(DAT_010f3170); FUN_00970f60* p=(FUN_00970f60*)mem->FUN_008f6d30(n,0x27); p->size=(unsigned short)n;return p; }
    static void operator delete(void* p) { FUN_00951b90(p); }
};
struct __declspec(align(16)) Vector4 {float x,y,z,w;};
// The layer is ORed in as a separate step: written as one expression VC8 folds the mask to 0xffffff9f/0xffffffa0.
inline unsigned MakeFilter(unsigned flags, unsigned layer) { unsigned f = flags & 0xffffff80; f |= layer; return f; }
struct __declspec(align(16)) FUN_008e8d70Cinfo {
    unsigned filterInfo; int unk04; unsigned char type,unk09,unk0a,unk0b;
    RawArray entries; int unk18,unk1c; Vector4 lo,hi;
    FUN_008e8d70Cinfo() {entries.data=0;entries.count=0;entries.capacity=0x80000000;unk04=0;type=2;}
    ~FUN_008e8d70Cinfo(){if(!(entries.capacity&0x80000000)) { int n = entries.capacity&0x3fffffff; TLSHeap* mem = (TLSHeap*)TlsGetValue(DAT_010f3170); mem->FUN_008f6d90(entries.data,n*8,0x17);}}
};
struct FUN_008e8d70 : ShapeRef {
    int unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    float offx,offy,offz,offw;int unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;
    FUN_008e8d70(FUN_008e8d70Cinfo const&);
    static void* operator new(unsigned n) {unsigned char* p=(unsigned char*)DAT_01090a78.FUN_0086b930(n+16);unsigned char off=16-((unsigned)p&15);p+=off;p[-1]=off;return p;}
    static void operator delete(void* p) { FUN_008d36a0(p); }
};
struct __declspec(align(16)) FUN_008e8e90Cinfo {
    unsigned filterInfo; FUN_00970f60* shape; int unk08; RawArray entries; int unk18,unk1c;
    Vector4 row0,row1,row2,row3;
    void FUN_004f64e0();
    FUN_008e8e90Cinfo(){FUN_004f64e0();}
    ~FUN_008e8e90Cinfo(){if(!(entries.capacity&0x80000000)) { int n = entries.capacity&0x3fffffff; TLSHeap* mem = (TLSHeap*)TlsGetValue(DAT_010f3170); mem->FUN_008f6d90(entries.data,n*8,0x17);}}
};
struct FUN_008e8e90 : ShapeRef {
    int unk14,unk18,unk1c;
    FUN_008e8e90(FUN_008e8e90Cinfo const&, void*);
    static void* operator new(unsigned n) {unsigned char* p=(unsigned char*)DAT_01090a78.FUN_0086b930(n+16);unsigned char off=16-((unsigned)p&15);p+=off;p[-1]=off;return p;}
    static void operator delete(void* p) { FUN_008d36a0(p); }
};
extern ShapePointer DAT_010f2ea0;
class ShapeOwner
{
public:
    int unk000; int unk004; NodeBounds* node; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290;
    unsigned int flags;
    int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec;
    float maxRadius;
    int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c; int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c; int unk340; int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c; int unk360; int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c; int unk380; int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c; int unk3a0; int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc; int unk3c0;
    float height;
    int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc; int unk3e0; int unk3e4; int unk3e8; int unk3ec;
    float fullHeight;
    int unk3f4, unk3f8, unk3fc;
    float centerX;
    float centerY;
    float heightAccum;
    int unk40c; int unk410; int unk414; int unk418; int unk41c; int unk420; int unk424;
    ShapePointer primaryAuxiliary;
    ShapePointer secondaryAuxiliary;
    int unk430;
    unsigned int shapeCount;
    ShapePointer shapes[2];
    int unk440; int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c; int unk460; int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c;
    float dimx, dimy, dimz;

    ShapeRef* FUN_008e98a0();
    void FUN_008ed0a0(unsigned int);
    float GetMaxRadius() const { return maxRadius; }
    float GetBoundRadius(ShapeRef* bound) const
    {
        return bound && bound->shape ? ((ShapeRef*)bound->shape)->radius : DAT_00f7a690;
    }
    void FUN_008ee9e0(ShapeInput* input);
};

// pdb: bhkCharacterController::InitShapes | bhkCharacterController.obj | fnv360_0721_beta, call_gap, low
// pdb params: arInfo
void ShapeOwner::FUN_008ee9e0(ShapeInput* input)
{
    shapeCount = 2;
    if(!input) return;
    float upper=0,lower=0,marginExtent=0,offset=0;
    float diameter, radius;
    float scratch;
    NiPoint3 extents, center;
    if (input->GetShape())
    {
        ShapeRef* incoming=input->GetShape();
        unsigned index=input->GetIndex();
        shapes[index].FUN_008e9650(incoming);
        ShapeRef* bound = FUN_008e98a0();
        radius = GetBoundRadius(bound) * 6.999040126800537;
        diameter = 0;
    }
    else
    {
        NiPoint3 scaled, b;
        if (input->node && !input->flag96)
        {
            Geometry* geometry = BSBound_Find(input->node);
            if (geometry)
            {
                extents = geometry->extents.FUN_00432b40(input->GetScale());
                center = geometry->center.FUN_00432b40(input->GetScale());
                scaled = DAT_0108ec68;
            }
            else
            {
                NodeBounds* nb = input->node;
                Bound* local = nb->bound ? nb->bound : &DAT_0108edc8;
                if (flags & 1)
                {
                    extents.y = local->radius;
                    scratch = (float)(input->scale * 25.0);
                    extents.z = scratch;
                    extents.x = scratch;
                }
                else
                {
                    extents.z = local->radius;
                    scratch = (float)(input->scale * 25.0);
                    extents.y = scratch;
                    extents.x = scratch;
                }
                scaled = DAT_0108ec68;
                center = DAT_0108ec68;
            }
        }
        else
        {
            float scale = input->flag96 ? 1.0f : input->scale;
            extents.x = (float)(23.0 * scale);
            extents.y = (float)(17.5 * scale);
            extents.z = (float)(64.0 * scale);
            center = DAT_0108ec68;
            scaled = DAT_0108ec68;
        }
        if (extents.x > extents.z || extents.y > extents.z)
            flags |= 1;
        float z;
        diameter = 0;
        if (flags & 1)
        {
            scaled = center;
            scaled.z = 0;
            if (extents.x > extents.y)
            {
                diameter = (float)(2.0 * extents.x);
                if (extents.y < extents.z) { radius = extents.y; z = extents.z; }
                else { radius = extents.z; z = extents.y; }
                scaled.x += extents.x - radius;
                b = scaled;
                b.x = (float)(scaled.x * -1.0);
            }
            else
            {
                diameter = (float)(2.0 * extents.y);
                if (extents.x < extents.z) { radius = extents.x; z = extents.z; }
                else { radius = extents.z; z = extents.x; }
                scaled.y += extents.y - radius;
                b = scaled;
                b.y = (float)(scaled.y * -1.0);
            }
            if (z * 0.75 > radius)
            {
                z -= radius;
                scaled.z = (float)(z * 2.0 + radius + 0.0);
                b.z = scaled.z;
                height=(float)(input->margin*2.0); heightAccum+=height;
                if (input->maxSize == 0)
                    input->maxSize = radius * 0.1428767293691635;   // no explicit (float): with it the x87 operands at +0xbe2 swap
                CompoundInfo info;
                ShapeRef* halfLength = new FUN_0091da10(scaled, b, radius);
                upper=(float)(scaled.z*0.1428767293691635);lower=0; marginExtent=(float)(radius*0.1428767293691635);
                offset=(float)((scaled-b).FUN_00432bd0()*0.5);offset=(float)(offset*0.1428767293691635)+marginExtent*2.0;
                scaled.z = z;
                scaled.y = (float)(scaled.y - 8.0);
                NiPoint3 sideA = scaled;
                float sideZ = (float)(z + 1.0);
                scaled.z = sideZ;
                sideA.z = (float)(sideA.z - 1.0);
                ShapeRef* left = new FUN_0091da10(scaled, sideA, (float)(z - 1.0));
                b.z = z;
                b.y = (float)(b.y + 8.0);
                NiPoint3 sideB = b;
                b.z = sideZ;
                sideB.z = (float)(sideB.z - 1.0);
                ShapeRef* right = new FUN_0091da10(b, sideB, (float)(z - 1.0));
                info.shapes.Add(halfLength ? halfLength->shape : 0);
                info.shapes.Add(left ? left->shape : 0);
                info.shapes.Add(right ? right->shape : 0);
                info.extra.Add(0);
                info.extra.Add(0);
                info.extra.Add(0);
                input->index = 0;
                shapes[input->GetIndex()].FUN_008e9650(new FUN_008e9020(info));
            }
        }
        else
        {
            diameter = extents.z + extents.z;
            radius = (float)((extents.x + extents.y) * 0.5);
            scaled.z += extents.z - radius;
            b = scaled;
            b.z = (float)(scaled.z * -1.0);
            float limit = (float)(radius * 0.75);
            limit = (float)(limit * 0.1428767293691635);
            if (maxRadius < limit)
                maxRadius = limit;
        }
        centerX = (float)(center.x * 0.1428767293691635);
        centerY = (float)(center.y * 0.1428767293691635);
        ShapePointer& first = shapes[0];
        if (!first.m_pObject)
        {
            float h = scaled.z + radius;
            h = (float)(h * 0.1428767293691635);
            h += input->margin * 2.0;
            height=h;heightAccum+=height;
            if (input->maxSize == 0)
                input->maxSize = radius * 0.1428767293691635;
            marginExtent=input->maxSize;
            offset=(float)(marginExtent*2.0 + marginExtent*0.5);
            lower=(float)((float)(b.z*0.1428767293691635) - marginExtent);
            if (flags & 1)
            {
                input->index = 0;
                upper=(float)((float)(scaled.z*0.1428767293691635)+marginExtent);
                shapes[input->GetIndex()].FUN_008e9650(new FUN_0091da10(scaled, b, radius));
            }
            else
            {
                upper=(float)(scaled.z*0.1428767293691635);
                first.FUN_008e9650(FUN_008e8880(&scaled, &b, radius));
                if (input->flag96)
                {
                    if (!DAT_010f2ea0.m_pObject)
                        DAT_010f2ea0.FUN_008e9650((ShapeRef*)FUN_008ec700(scaled, b, radius, GetMaxRadius()));
                    shapes[1].FUN_008e9600(DAT_010f2ea0);
                }
                else
                    shapes[1].FUN_008e9650((ShapeRef*)FUN_008ec700(scaled, b, radius, GetMaxRadius()));
            }
        }
    }
    double units = 0.1428767293691635;
    float width = (float)(radius * 0.1428767293691635);
    dimx = width;
    dimz = width;
    dimy = (float)(units * diameter);
    float total = extents.z * 2;
    fullHeight = (float)(units * total);
    FUN_008ed0a0(input->GetIndex());
    if (input->HasPhantom())
    {
        FUN_008e8d70Cinfo info;
        unsigned filter = input->flags & 0xffffff80;
        filter |= 0x1f;
        info.filterInfo = filter;
        lower += maxRadius;
        upper += marginExtent;
        if (lower >= upper)
            upper += maxRadius;
        // Guess at the source: the corner lanes are written in a loop; the original stores them to the 16-aligned
        // temporary at esp+0x84 and reloads them, which plain lane stores do not reproduce (VC8 forwards those).
        NiPoint3 lowerCorner;
        for (int i = 0; i < 2; i++) (&lowerCorner.x)[i] = (float)(-marginExtent*2.0);
        info.lo.x = lowerCorner.x;
        info.lo.y = lowerCorner.y;
        info.lo.z = lower;
        info.lo.w = 0.0f;
        NiPoint3 upperCorner;
        for (int i = 0; i < 2; i++) (&upperCorner.x)[i] = (float)(marginExtent*2.0);
        info.hi.x = upperCorner.x;
        info.hi.y = upperCorner.y;
        info.hi.z = upper;
        info.hi.w = 0.0f;
        FUN_008e8d70* aux = new FUN_008e8d70(info);
        primaryAuxiliary.FUN_008e9650(aux);
        aux=(FUN_008e8d70*)primaryAuxiliary.m_pObject;
        aux->offx = 0.0f;
        aux->offy = offset;
        aux->offz = 0.0f;
        aux->offw = 0.0f;
    }
    if (input->flag95)
    {
        FUN_008e8e90Cinfo info;
        info.filterInfo = MakeFilter(input->flags, 0x20);
        info.shape = 0;
        // Guess at the source: a flag cleared on the node path; this places the no-node arm behind the return and
        // shares the size = 1 block with the non-positive-radius case, as in the original.
        float size;
        bool noNode = true;
        if (input->node)
        {
            Bound value = input->node->bound ? *input->node->bound : DAT_0108edc8;
            size = value.radius;
            noNode = false;
        }
        if (noNode)
        {
            if(node) node->FUN_0091dd60();
            size = 1.0f;
        }
        else
        {
            if (!(size > 0.0f))
                size = 1.0f;
        }
        info.shape = new FUN_00970f60((float)(size * 0.1428767293691635));
        secondaryAuxiliary.FUN_008e9650(new FUN_008e8e90(info, this));
    }
}

}

// @f3 0x008ebc30 (community match, verified in this file)
namespace f3m_008ebc30 {


static inline float Sqrt8eb(float r) { return sqrtf(r); }
static inline float InverseSqrt8eb(float r) { return 1.0f / Sqrt8eb(r); }
class __declspec(align(16)) HkVector4
{
public:
    float x, y, z, w;
__forceinline float currentInverse() const { const float& xv = x; float l2 = xv*xv + y*y + z*z; return l2 ? InverseSqrt8eb(l2) : 0; }
__forceinline void normalizeCurrent() { mul4(currentInverse()); }

    inline HkVector4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}

    __forceinline HkVector4() {}
    __forceinline HkVector4(const HkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void operator=(const HkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline void mul4(float rs)
    {
        float s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void sub4(const HkVector4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    __forceinline float dot3(const HkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline float lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }
    __forceinline float length3() const
    {
        return Sqrt8eb((x * x) + (y * y) + (z * z));
    }
    __forceinline float lengthInverse3() const
    {
        float l2 = (x * x) + (y * y) + (z * z);
        return l2 ? InverseSqrt8eb(l2) : 0;
    }
    __forceinline void normalize3()
    {
        mul4(lengthInverse3());
    }
    __forceinline void setCross(const HkVector4& v1, const HkVector4& v2)
    {
        const float nx = v1.y * v2.z - v1.z * v2.y;
        const float ny = v1.z * v2.x - v1.x * v2.z;
        const float nz = v1.x * v2.y - v1.y * v2.x;
        x = nx;
        y = ny;
        z = nz;
        w = 0.0f;
    }
};

inline HkVector4 planarValue(const HkVector4& v) { return HkVector4(v.x,v.y,0.0f,v.w); }
inline void storeLane(float& out, float value) { out=value; }
struct DotValue {
    float x,y,z,w;
    inline DotValue(const HkVector4& v) : x(v.x),y(v.y),z(v.z),w(v.w) {}
};
inline float dotRightValue(const HkVector4& a, DotValue b) { return a.x*b.x+a.y*b.y+a.z*b.z; }

inline HkVector4 currentPlanar(const HkVector4& source) { HkVector4 result; storeLane(result.x,source.x); storeLane(result.y,source.y); storeLane(result.z,0.0f); storeLane(result.w,source.w); return result; }
struct Point3 { float x, y, z; };
struct StoredVector4 { float x,y,z,w; };
struct NativeOwner980;
struct Entity {
    virtual ~Entity();
    unsigned short allocationFlags; short references;
    unsigned unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024;
    unsigned unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044;
    unsigned unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064;
    unsigned unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084;
    unsigned unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4;
    unsigned unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    NativeOwner980* controller;
    HkVector4* FUN_0091dda0();
    HkVector4* FUN_0091dd60();
};
struct Input { HkVector4 position, velocity; };
struct HkRefPtr { Entity* m_p; };
extern HkVector4 DAT_01092a50;
extern float DAT_00f79c8c, DAT_00f79c88;
extern const double DAT_0109c9e0;
extern const double DAT_00db88e8;
float FUN_0090d870(float, float);
float FUN_00401e20(float, float);
struct HkBase {
    virtual ~HkBase();
    unsigned unk004;
    Entity* physics;
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
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
};
struct NativeContext980 {
    virtual ~NativeContext980();
    unsigned short sizeAndFlags;short refs;
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
};
static inline void releaseRef8eb(Entity* e)
{
    if (e->allocationFlags != 0)
    {
        --e->references;
        if (e->references == 0)
            delete e;
    }
}
static inline void addRef8eb(Entity* e) { if (e->allocationFlags) ++e->references; }
struct EntityRef8eb
{
    Entity* m_p;
    inline void operator=(Entity* e)
    {
        if (m_p != e)
        {
            if (m_p)
                releaseRef8eb(m_p);
            m_p = e;
            addRef8eb(e);
        }
    }
};
struct C8EB980
{
    virtual ~C8EB980();         // hkpCharacterProxyListener native vptr
    unsigned m_flags;      // 0x004
    int m_unk08, m_unk0C;
    int m_unk10, m_unk14, m_unk18, m_unk1C;
    int m_unk20, m_unk24, m_unk28, m_unk2C;
    int m_unk30, m_unk34, m_unk38, m_unk3C;
    int m_unk40, m_unk44, m_unk48, m_unk4C;
    int m_unk50, m_unk54, m_unk58, m_unk5C;
    int m_unk60, m_unk64, m_unk68, m_unk6C;
    int m_unk70, m_unk74, m_unk78, m_unk7C;
    int m_unk80, m_unk84, m_unk88, m_unk8C;
    int m_unk90, m_unk94, m_unk98, m_unk9C;
    int m_unkA0, m_unkA4, m_unkA8, m_unkAC;
    int m_unkB0, m_unkB4, m_unkB8, m_unkBC;
    int m_unkC0, m_unkC4, m_unkC8, m_unkCC;
    int m_unkD0, m_unkD4, m_unkD8, m_unkDC;
    float directionX, directionY, directionZ, directionW;
    int m_unkF0, m_unkF4, m_unkF8, m_unkFC;
    StoredVector4 m_rot;            // 0x100
    int m_unk110, m_unk114, m_unk118, m_unk11C;
    int m_unk120, m_unk124, m_unk128, m_unk12C;
    int m_unk130, m_unk134, m_unk138, m_unk13C;
    int m_unk140, m_unk144, m_unk148, m_unk14C;
    int m_unk150, m_unk154, m_unk158, m_unk15C;
    int m_unk160, m_unk164, m_unk168, m_unk16C;
    int m_unk170, m_unk174, m_unk178, m_unk17C;
    int m_unk180, m_unk184, m_unk188, m_unk18C;
    int m_unk190, m_unk194, m_unk198, m_unk19C;
    int m_unk1A0, m_unk1A4, m_unk1A8, m_unk1AC;
    int m_unk1B0, m_unk1B4, m_unk1B8, m_unk1BC;
    int m_unk1C0, m_unk1C4, m_unk1C8, m_unk1CC;
    int m_unk1D0, m_unk1D4, m_unk1D8, m_unk1DC;
    int m_unk1E0, m_unk1E4, m_unk1E8, m_unk1EC;
    int m_unk1F0;
    float m_f1F4;               // 0x1F4
    int m_unk1F8, m_unk1FC; int mode; unsigned threshold;
    int m_unk208, m_unk20C, m_unk210, m_unk214;
    int m_unk218, m_unk21C, m_unk220, m_unk224;
    int m_unk228, m_unk22C;
    HkRefPtr m_p230;            // 0x230
    float m_f234;               // 0x234

    EntityRef8eb current;
    void FUN_008ebc30(int unused, Entity* entity, Input* input);
};

// Native hierarchy already proved by RTTI: primary proxy0, context260, listener290.
struct NativeOwner980 : HkBase, NativeContext980, C8EB980 {
    void FUN_008e8fa0(HkVector4* vector);
    void FUN_008e9280(Point3* vector, float step);
    void FUN_008e8920(float amount, float step);
};
typedef char check_listener[(offsetof(NativeOwner980,m_flags)==0x294)?1:-1];
typedef char check_current[(offsetof(NativeOwner980,current)==0x4c8)?1:-1];
typedef char check_controller[(offsetof(Entity,controller)==0xc0)?1:-1];
static inline HkVector4* velocityOrZero8eb(NativeOwner980* o) { return (o && o->physics) ? o->physics->FUN_0091dda0() : &DAT_01092a50; }
static inline HkVector4* positionOrZero8eb(NativeOwner980* o) { return o->physics ? o->physics->FUN_0091dd60() : &DAT_01092a50; }
static inline void scaledPoint8eb(Point3* out, const HkVector4* v)
{
    out->x = (float)(v->x * DAT_00db88e8);
    out->y = (float)(v->y * DAT_00db88e8);
    out->z = (float)(v->z * DAT_00db88e8);
}
// pdb: bhkCharacterController::characterInteractionCallback | bhkCharacterController.obj | fnv360_0822_retail, vtable, medium
// pdb params: __formal, apOtherProxy, arContact
void C8EB980::FUN_008ebc30(int unused, Entity* entity, Input* input)
{
    NativeOwner980* body = entity->controller;
    NativeOwner980* self = reinterpret_cast<NativeOwner980*>(reinterpret_cast<char*>(this) - (offsetof(NativeOwner980, m_flags) - offsetof(C8EB980, m_flags)));
    self->current = entity;
    if (!body)
        return;
    int kind = mode;
    if (body->threshold > threshold || (body->m_flags & 0x4000))
        return;
    {
        Point3 push;
        HkVector4 own = *entity->FUN_0091dda0();
        HkVector4 velocity = input->velocity;
        velocity(2) = 0.0f;
        if (velocity.lengthSquared3() > 0.0f)
            velocity.normalize3();
        own = *velocityOrZero8eb(self);
        own(2) = 0.0f;
        float speed = own.length3();
        if (kind == 2)
            speed = (float)(speed + 20.0);
        speed = (float)(speed * DAT_0109c9e0);
        velocity.mul4(speed);
        scaledPoint8eb(&push, &velocity);
        body->FUN_008e8fa0(&velocity);
        body->FUN_008e9280(&push, 0.01f);
    }
    if (!(body->m_flags & 1))
        return;
    HkVector4 separation = input->position;
    separation.sub4(*positionOrZero8eb(body));
    separation.z = 0.0f;
    HkVector4 projection = *(const HkVector4*)&body->directionX;
    projection.z = 0.0f;
    projection.normalize3();
    float along = separation.dot3(projection);
    projection.mul4(along);
    const float reduce = (float)(projection.length3() / (body->m_f1F4 * 0.5) - DAT_00f79c8c);
    HkVector4 incoming=planarValue(input->velocity);
    incoming.normalize3();
    HkVector4 current = currentPlanar(*velocityOrZero8eb(self));
    current.normalizeCurrent();
    float headOn = -dotRightValue(incoming,current) * reduce;
    float turn = FUN_00401e20(0.0f, FUN_0090d870(1.0f, headOn));
    if (turn > 0.0f)
    {
        HkVector4 side;
        side.setCross(separation, projection);
        if (side(2) > 0.0f)
            turn = (float)(turn * -1.0);
        body->FUN_008e8920(turn * DAT_00f79c88, 0.2f);
    }
}




}   // namespace f3m_008ebc30

// @f3 0x008e0300 (community match, verified in this file)
namespace f3m_008e0300 {
// FUN_008e0300: look-at update of one bone of the head/neck controller (x87 Havok maths).
// Optimised code: exact under /MT /O2 /GS /EHsc /Gy, not under the listed /Od set (flag proof).
// Builds on the stored draft best1.cpp (another contributor, board draft chk_37270bd8c2494b279406). Kept from
// it: the game-side layouts (Setup, BoneParams, Controller), the statement order of FUN_008e0300 and the body
// of the angle limiter FUN_008dc360. Replaced: all of its hand-made vector, quaternion, transform and pose
// helpers (about 70, in per-site copies tuned with parentheses, scalar copies and double factors) by ONE
// definition each, written the way the Havok 5.5.0 x87 inline functions are written (vector, quaternion,
// QS transform, pose getters/setter, array index). No per-site copies and no numbering devices are left.
// The x87 operand order comes out right only with those shapes: index accessor in the cross product and for
// the quaternion real part, a float copy of the scalar in the scale helpers, the parenthesised sums in dot and
// inverse length, set() in the cross product, the imaginary-part accessor, the two named references in the
// local-pose getter, array elements through an inline index operator, forced inlining of the vector,
// transform and pose members. FUN_008d3290 (quaternion product) and FUN_008db610 (product with the inverse)
// are plain inlines with visible bodies that the compiler leaves out of line; FUN_008dc360 has its body in
// this file. Without those three bodies the frame is 0x184 instead of 0x154.


typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef int hkBool32;
typedef unsigned int hkUint32;
typedef short hkInt16;

namespace Math {
    inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
    inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / Math::sqrt(r); }
    inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}

struct Quaternion;
struct Transform;

struct VecComparison {
    enum Mask { MASK_NONE=0, MASK_W=1, MASK_Z=2, MASK_ZW=3, MASK_Y=4, MASK_YW=5, MASK_YZ=6, MASK_YZW=7,
                MASK_X=8, MASK_XW=9, MASK_XZ=10, MASK_XZW=11, MASK_XY=12, MASK_XYW=13, MASK_XYZ=14, MASK_XYZW=15 };
    hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
    int m_mask;
};

struct Vec {
    __forceinline Vec() { }
    __forceinline Vec( const Vec& v);
    __forceinline void operator= ( const Vec& v );
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
    __forceinline void setAll3(hkReal x);
    __forceinline void setZero4();
    __forceinline void add4(const Vec& a);
    __forceinline void setAdd4(const Vec& a, const Vec& b);
    __forceinline void setSub4(const Vec& a, const Vec& b);
    __forceinline void setMul4(const Vec& a, const Vec& b);
    __forceinline void mul4(hkSimdRealParameter a);
    __forceinline void setMul4(hkSimdRealParameter r, const Vec& a);
    __forceinline void addMul4(hkSimdRealParameter r, const Vec& a);
    __forceinline void subMul4(hkSimdRealParameter r, const Vec& a);
    __forceinline void setCross( const Vec& a, const Vec& b );
    __forceinline hkBool32 equals3(const Vec &a, hkReal epsilon = 1e-3f ) const;
    __forceinline VecComparison compareLessThanEqual4(const Vec& a) const;
    __forceinline void setNeg3(const Vec& v);
    __forceinline void setNeg4(const Vec& v);
    __forceinline void setAbs4(const Vec& v);
    __forceinline void setRotatedDir(const Quaternion& q, const Vec& b);
    __forceinline void setRotatedInverseDir(const Quaternion& q, const Vec& b);
    void FUN_008d2ca0(const Transform& a, const Vec& b);
    __forceinline hkSimdReal dot3(const Vec& a) const;
    __forceinline hkSimdReal dot4(const Vec& a) const;
    __forceinline hkSimdReal length3() const;
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();
    __forceinline hkReal& operator() (int i);
    __forceinline const hkReal& operator() (int i) const;
    __forceinline void setXYZ0(const Vec& xyz);
    __forceinline void setReciprocal3(const Vec& v);
    inline hkSimdReal getSimdAt(int i) const;
    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct Quaternion {
    inline Quaternion() { }
    inline void operator= (const Quaternion& q);
    inline void setIdentity();
    inline void setInverse( const Quaternion &q );
    inline hkReal getReal() const;
    inline const Vec& getImag() const;
    inline void FUN_008d3290(const Quaternion& q0, const Quaternion& q1);
    inline void FUN_008db610(const Quaternion& q0, const Quaternion& q1);
    hkReal FUN_008db810() const;
    void FUN_008db880(Vec &axis) const;
    void FUN_009240d0(const Vec& axis, hkReal angle);
    void FUN_004e5c20();
    struct ByteBool FUN_00924140() const;
    Vec value;
};

inline hkReal& Vec::operator() (int i) { return (&x)[i]; }
inline const hkReal& Vec::operator() (int i) const { return (&x)[i]; }
__forceinline void Vec::setXYZ0(const Vec& xyz) { x = xyz.x; y = xyz.y; z = xyz.z; w = 0; }
inline void Vec::setReciprocal3(const Vec& v) { x = 1.0f / v.x; y = 1.0f / v.y; z = 1.0f / v.z; w = 1.0f; }
inline hkSimdReal Vec::getSimdAt(int i) const { return (&x)[i]; }
inline void Vec::operator= (const Vec& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
inline Vec::Vec( const Vec& v) { *this = v; }
inline void Vec::set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
inline void Vec::setAll3(hkReal a) { x = a; y = a; z = a; w = a; }
inline void Vec::setZero4() { x = y = z = w = 0; }
inline void Vec::add4(const Vec& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
inline void Vec::setAdd4(const Vec& v0, const Vec& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
inline void Vec::setSub4(const Vec& v0, const Vec& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
inline void Vec::setMul4(const Vec& a, const Vec& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
inline void Vec::mul4(hkSimdRealParameter rs) { hkReal s = hkReal(rs); x *= s; y *= s; z *= s; w *= s; }
inline void Vec::setMul4(hkSimdRealParameter rs, const Vec& a) { hkReal r = hkReal(rs); x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
inline void Vec::addMul4(hkSimdRealParameter rs, const Vec& a) { hkReal r = hkReal(rs); x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
inline void Vec::subMul4(hkSimdRealParameter rs, const Vec& a) { hkReal r = hkReal(rs); x -= r * a.x; y -= r * a.y; z -= r * a.z; w -= r * a.w; }
inline void Vec::setCross(const Vec& v1, const Vec& v2) {
    const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
    const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
    const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
    this->set( nx, ny, nz , 0.0f );
}
inline VecComparison Vec::compareLessThanEqual4(const Vec& a) const {
    VecComparison ret;
    ret.m_mask =
        ((x<=a.x) ? VecComparison::MASK_X : 0) |
        ((y<=a.y) ? VecComparison::MASK_Y : 0) |
        ((z<=a.z) ? VecComparison::MASK_Z : 0) |
        ((w<=a.w) ? VecComparison::MASK_W : 0);
    return ret;
}
inline void Vec::setNeg4(const Vec& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
inline void Vec::setNeg3(const Vec& v) { x = -v.x; y = -v.y; z = -v.z; w =  v.w; }
inline void Vec::setAbs4(const Vec& v) { x = Math::fabs(v.x); y = Math::fabs(v.y); z = Math::fabs(v.z); w = Math::fabs(v.w); }
inline hkSimdReal Vec::dot3(const Vec& a) const { return (x * a.x) + ( y * a.y ) + ( z * a.z ); }
inline hkSimdReal Vec::dot4(const Vec& a) const { return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w * a.w ); }
inline hkSimdReal Vec::length3() const { return Math::sqrt((x * x) + ( y * y ) + ( z * z )); }
inline hkSimdReal Vec::lengthInverse3() const { hkReal l2 = (x*x) + (y*y) + (z*z); return l2 ? Math::sqrtInverse(l2) : 0; }
inline void Vec::normalize3() { this->mul4( this->lengthInverse3() ); }

inline const Vec& Quaternion::getImag() const { return value; }
inline hkReal Quaternion::getReal() const { return value(3); }
inline void Quaternion::operator= (const Quaternion& q) { value = q.value; }
inline void Quaternion::setIdentity() { value.set(0,0,0,1); }
void Quaternion::setInverse( const Quaternion &q ) { value.setNeg3( q.getImag() ); }

__forceinline void Vec::setRotatedDir(const Quaternion& quat, const Vec& direction) {
    hkReal qreal = quat.value(3);
    hkReal q2minus1 = qreal*qreal - 0.5f;

    Vec ret;
    ret.setMul4( q2minus1, direction );

    hkReal imagDotDir = quat.getImag().dot3( direction );
    ret.addMul4( imagDotDir, quat.getImag() );

    Vec imagCrossDir;
    imagCrossDir.setCross( quat.getImag(), direction );
    ret.addMul4( qreal, imagCrossDir );

    this->setAdd4( ret, ret );
}
__forceinline void Vec::setRotatedInverseDir(const Quaternion& quat, const Vec& direction) {
    hkReal qreal = quat.value(3);
    hkReal q2minus1 = qreal*qreal - 0.5f;

    Vec ret;
    ret.setMul4( q2minus1, direction );

    hkReal imagDotDir = quat.getImag().dot3( direction );
    ret.addMul4( imagDotDir, quat.getImag() );

    Vec imagCrossDir;
    imagCrossDir.setCross( direction, quat.getImag() );
    ret.addMul4( qreal, imagCrossDir );

    this->setAdd4( ret, ret );
}
inline hkBool32 Vec::equals3(const Vec &v, hkReal epsilon) const {
    Vec t;
    t.setSub4(*this, v);
    t.setAbs4( t );
    Vec epsilon_v;
    epsilon_v.setAll3( epsilon );
    return t.compareLessThanEqual4( epsilon_v ).allAreSet( VecComparison::MASK_XYZ );
}

inline void Quaternion::FUN_008d3290(const Quaternion& q0, const Quaternion& q1) {
    Vec vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.value.getSimdAt(3), q1.getImag());
    vec.addMul4(q1.value.getSimdAt(3), q0.getImag());
    hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.value.dot3( q1.value ) );
    value = vec;
    value(3) = real;
}
struct Transform {
    __forceinline Transform() { }
    __forceinline Transform(const Transform& other);
    __forceinline void setInverse( const Transform &t );
    __forceinline void setMul( const Transform &t1, const Transform &t2 );
    __forceinline void setMulInverseMul( const Transform& t1, const Transform &t2 );
    void FUN_008dbcd0(const Transform&);
    Vec position;
    Quaternion rotation;
    Vec scale;
};
Transform::Transform(const Transform& t) {
    position = t.position;
    rotation = t.rotation;
    scale = t.scale;
}
void Transform::setInverse( const Transform& t ) {
    position.setRotatedInverseDir(t.rotation, t.position);
    position.setNeg4(position);
    rotation.setInverse(t.rotation);

    Vec invScale; invScale.setReciprocal3( t.scale );
    scale.setXYZ0( invScale );
}
void Transform::setMul( const Transform& aTb, const Transform& bTc ) {
    Vec extraTrans;
    extraTrans.setRotatedDir(aTb.rotation, bTc.position);
    position.setAdd4(aTb.position, extraTrans);
    rotation.FUN_008d3290(aTb.rotation, bTc.rotation);
    scale.setMul4(aTb.scale, bTc.scale);
}
void Transform::setMulInverseMul( const Transform& a, const Transform &b ) {
    Transform h;
    h.setInverse( a );
    setMul(h, b);
}

template <typename T>
struct Array {
    inline T& operator[] (int i) { return m_data[i]; }
    inline const T& operator[] (int i) const { return m_data[i]; }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};
struct Skeleton {
    const char* name;
    hkInt16* parentIndices;
    int numParentIndices;
    void** bones;
    int numBones;
};
struct Pose {
    typedef hkUint32 PoseFlag;
    __forceinline const Transform& getBoneLocalSpace (int boneIdx) const;
    __forceinline const Transform& getBoneModelSpace (int boneIdx) const;
    __forceinline void setBoneLocalSpace (int boneIdx, const Transform& boneLocal);
    Transform& FUN_00956290(int);
    Transform& FUN_00956b90(int,int);
    const Skeleton* skeleton;
    mutable Array<Transform> localPose;
    mutable Array<Transform> modelPose;
    mutable Array<PoseFlag> boneFlags;
    mutable bool modelInSync;
    mutable bool localInSync;
    enum { F_BONE_LOCAL_DIRTY = 0x1, F_BONE_MODEL_DIRTY = 0x2, F_BONE_INTERNAL_FLAG1 = 0x4 };
    __forceinline int isFlagOn (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline void setFlag (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline void clearFlag (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline int isFlagOnExplicit (PoseFlag flag, PoseFlag enumToCheck) const;
    __forceinline void setFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const;
    __forceinline void clearFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const;
    __forceinline void makeAllChildrenLocalSpace (int boneIdx) const;
    const Transform& hkaPose_calculateBoneModelSpace(int) const;
};
int Pose::isFlagOn (int boneIdx, PoseFlag enumToCheck) const { return boneFlags[boneIdx] & enumToCheck; }
void Pose::setFlag (int boneIdx, PoseFlag enumToCheck) const { boneFlags[boneIdx] |= enumToCheck; }
void Pose::clearFlag (int boneIdx, PoseFlag enumToCheck) const { boneFlags[boneIdx] &= static_cast<PoseFlag>(~enumToCheck); }
int Pose::isFlagOnExplicit (PoseFlag flag, PoseFlag enumToCheck) const { return flag & enumToCheck; }
void Pose::setFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const { flag |= enumToCheck; }
void Pose::clearFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const { flag &= static_cast<PoseFlag>(~enumToCheck); }
const Transform& Pose::getBoneModelSpace (int boneIdx) const {
    if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY)) {
        return modelPose[boneIdx];
    } else {
        return hkaPose_calculateBoneModelSpace(boneIdx);
    }
}
const Transform& Pose::getBoneLocalSpace (int boneIdx) const {
    if (! isFlagOn (boneIdx, F_BONE_LOCAL_DIRTY)) {
        return localPose[boneIdx];
    } else {
        const Transform& modelFromBone = modelPose[boneIdx];
        const hkInt16 parentIdx = skeleton->parentIndices[boneIdx];
        if (parentIdx != -1) {
            const Transform& modelFromParent = getBoneModelSpace(parentIdx);
            localPose[boneIdx].setMulInverseMul(modelFromParent, modelFromBone);
        } else {
            localPose[boneIdx].FUN_008dbcd0(modelFromBone);
        }
        clearFlag (boneIdx, F_BONE_LOCAL_DIRTY);
        return localPose[boneIdx];
    }
}
void Pose::makeAllChildrenLocalSpace(int boneIdx) const {
    const int numBones = skeleton->numBones;
    setFlag(boneIdx, F_BONE_INTERNAL_FLAG1);
        for (int i= boneIdx+1; i<numBones; ++i) {
            const hkInt16 parentId = skeleton->parentIndices[i];
            if (isFlagOn(parentId, F_BONE_INTERNAL_FLAG1)) {
                getBoneLocalSpace( i );
                setFlag( i, F_BONE_INTERNAL_FLAG1);
                modelInSync = false;
            }
        }
        for (int i= boneIdx+1; i < numBones; ++i) {
            PoseFlag f = boneFlags[i];
            if (isFlagOnExplicit( f, F_BONE_INTERNAL_FLAG1)) {
                setFlagExplicit( f, F_BONE_MODEL_DIRTY);
                clearFlagExplicit( f, F_BONE_INTERNAL_FLAG1);
                boneFlags[i] = f;
            }
        }
}
void Pose::setBoneLocalSpace (int boneIdx, const Transform& boneLocal) {
    makeAllChildrenLocalSpace(boneIdx);
    localPose[boneIdx].FUN_008dbcd0(boneLocal);
    boneFlags[boneIdx] = F_BONE_MODEL_DIRTY;
    modelInSync = false;
}
struct ByteBool { unsigned char value; ByteBool() {} ByteBool(bool b):value(b) {} operator bool() const { return value!=0; } };
struct Setup {
    Vec forward,eye,axis;
    hkReal angle;
    Setup() { eye.setZero4(); }
};
ByteBool FUN_0095d370(const Setup&,const Vec&,float,Transform&);
extern Vec DAT_01092a50;
extern float DAT_010f2d90;

struct BoneParams {
    Pose* pose;
    short bone,parent;
    float maxAngle;
    unsigned unk0c;
    Vec forward,parentForward; Quaternion previousRotation;
    bool limit,active;
    unsigned short unk42;
    float deadHeading,deadPitch;
    unsigned unk4c;
};
struct Controller {
    unsigned unk00,unk04,unk08,unk0c;
    Transform worldFromModel;
    unsigned unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    unsigned unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    unsigned unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    unsigned unka0,unka4,unka8,unkac;
    bool initLook,enableLook,easeOut,activeLook,applyOffset;
    unsigned unkb8,unkbc;
    Vec headRotationOffset;
    Vec currentTarget,eyeOffset;
    BoneParams bones[2];
    bool useHeadPose;
    int currentBone;
    float FUN_008dc360(int,const Quaternion&);
    bool FUN_008e0300(int which,Transform& world);
};
extern float DAT_010f2d84;
extern float DAT_010f2d78;
inline void Quaternion::FUN_008db610(const Quaternion& q0, const Quaternion& q1) {
    Vec h; h.setCross(q1.getImag(), q0.getImag());
    h.subMul4(q0.value.getSimdAt(3), q1.getImag());
    h.addMul4(q1.value.getSimdAt(3), q0.getImag());
    value = h;
    value(3) = q0.value.dot4(q1.value);
}
float Controller::FUN_008dc360(int which,const Quaternion& rotation) {
    float angle=0.0f;
    if(!rotation.value.equals3(bones[which].previousRotation.value,0.001f)) {
        Quaternion delta;
        delta.FUN_008db610(rotation,bones[which].previousRotation);
        angle=delta.FUN_008db810();
        float limit=easeOut ? DAT_010f2d84 : DAT_010f2d78;
        if(angle>limit*(3.14159265358979f / 180.0f)) {
            angle=limit*(3.14159265358979f / 180.0f);
            Vec axis;
            delta.FUN_008db880(axis);
            axis.normalize3();
            delta.FUN_009240d0(axis,angle);
        }
        Quaternion output;
        output.FUN_008d3290(delta,bones[which].previousRotation);
        output.FUN_004e5c20();
        bones[which].pose->FUN_00956290(bones[which].bone).rotation=output;
        bones[which].previousRotation=output;
    }
    return angle;
}
bool Controller::FUN_008e0300(int which,Transform& world) {
    Setup setup;
    setup.forward=bones[which].forward;
    setup.angle=bones[which].maxAngle;
    setup.axis.setRotatedDir(bones[which].pose->getBoneModelSpace(bones[which].parent).rotation,bones[which].parentForward);
    setup.axis.normalize3();
    Vec target;
    target.FUN_008d2ca0(world,currentTarget);
    if(useHeadPose && which==1) {
        Vec normal;
        normal.setCross(bones[which].forward,bones[0].pose->FUN_00956290(1).position);
        normal.normalize3();
        Vec projected;
        projected.setCross(normal,bones[which].forward);
        projected.normalize3();
        hkReal amount=projected.dot3(bones[0].pose->FUN_00956290(1).position)/projected.length3();
        Vec direction;
        direction.setSub4(target,bones[which].pose->getBoneModelSpace(bones[which].bone).position);
        hkReal distance=direction.length3();
        direction.normalize3();
        if(distance<amount) {
            direction.mul4(amount);
            target.add4(direction);
        }
        setup.eye=bones[0].pose->FUN_00956290(1).position;
    }
    Transform saved(bones[which].pose->getBoneLocalSpace(bones[which].bone));
    if(bones[which].previousRotation.value.equals3(DAT_01092a50,0.001f))
        bones[which].previousRotation=saved.rotation;
    bool solved=FUN_0095d370(setup,target,1.0f,bones[which].pose->FUN_00956b90(bones[which].bone,1));
    Transform after(bones[which].pose->getBoneLocalSpace(bones[which].bone));
    float angle=bones[which].limit ? FUN_008dc360(which,after.rotation) : 0.0f;
    if(!bones[which].pose->getBoneModelSpace(bones[which].bone).rotation.FUN_00924140())
        bones[which].pose->setBoneLocalSpace(bones[which].bone,saved);
    bones[which].limit=true;
    if(easeOut && angle<DAT_010f2d90*(3.14159265358979f / 180.0f)) {
        bones[which].previousRotation.setIdentity();
        if(which==0 || !useHeadPose) { easeOut=false; activeLook=false; }
        else { bones[currentBone].active=false; --currentBone; }
    }
    return !solved;
}
}   // namespace f3m_008e0300

// @f3 0x008ff5a0 (community match, verified in this file)
#include <math.h>
namespace f3m_008ff5a0 {
// 0x008ff5a0 (1308 bytes), __thiscall, 4 stack arguments (nextPosition, nextOrientation, invDeltaTime, blend).
// Offline MATCH under /MT,/O2,/GS,/EHsc,/Gy (pack lists /MT,/Od,/Oy-,/GS,/EHsc,/Gy: compile-flag proof).
// Structure from fnv_decomp src\unmapped\bhkrigidbody_rtm_variant.cpp KFRigidBody::bhkRigidBody_ApplyKeyframe (New Vegas 0x00c8de20):
// statement order and callee meanings; its SSE helpers and devices are not used. Maths as the Havok 5.5.0 SDK x87 (FPU) inline
// bodies (hk550 hkFpuVector4.inl, hkVector4.inl setRotatedDir/getZero, hkQuaternion.inl setInverse, hkpRigidBody.inl velocity
// accessors); the angular scope block follows hkpKeyFrameUtility::applyHardKeyFrame's debug record (hk550 hybrid library).
// Depends on: setMul4 taking its scalar as const hkReal& (SDK FPU: by value + copy); linearVelocity.mul4(invDeltaTime) where the
// twin writes setMul4(invDeltaTime, v); getZero() as the SDK's reinterpret_cast of a hkQuadReal global; the angular block from
// angularVelocity's declaration to the setters, with quatDif in a nested block; gravity copied to a local V (z lane used).
namespace Z8ff5 {
typedef float hkReal;typedef hkReal hkSimdReal;typedef hkReal hkSimdRealParameter;
namespace hkMath {inline hkReal sqrt(hkReal r){return ::sqrtf(r);}}
struct V;
struct Q4;
struct hkQuadReal{float v[4];};extern const hkQuadReal DAT_01092a50;
struct __declspec(align(16)) V {
float x,y,z,w;
__forceinline hkReal& operator()(int i){return (&x)[i];}
__forceinline const hkReal& operator()(int i)const{return (&x)[i];}
__forceinline void operator=(const V& v){x=v.x;y=v.y;z=v.z;w=v.w;}
__forceinline void set(hkReal a,hkReal b,hkReal c,hkReal d){x=a;y=b;z=c;w=d;}
__forceinline void add4(const V& v){x+=v.x;y+=v.y;z+=v.z;w+=v.w;}
__forceinline void setAdd4(const V& v0,const V& v1){x=v0.x+v1.x;y=v0.y+v1.y;z=v0.z+v1.z;w=v0.w+v1.w;}
__forceinline void setSub4(const V& v0,const V& v1){x=v0.x-v1.x;y=v0.y-v1.y;z=v0.z-v1.z;w=v0.w-v1.w;}
__forceinline void mul4(hkSimdRealParameter rs){hkReal s=hkReal(rs);x*=s;y*=s;z*=s;w*=s;}
__forceinline void setMul4(const hkReal& s,const V& a){x=s*a.x;y=s*a.y;z=s*a.z;w=s*a.w;}
__forceinline void addMul4(hkSimdRealParameter rs,const V& a){hkReal r=hkReal(rs);x+=r*a.x;y+=r*a.y;z+=r*a.z;w+=r*a.w;}
__forceinline void setNeg3(const V& v){x=-v.x;y=-v.y;z=-v.z;w=v.w;}
__forceinline void setCross(const V& v1,const V& v2){const hkReal nx=v1(1)*v2(2)-v1(2)*v2(1);const hkReal ny=v1(2)*v2(0)-v1(0)*v2(2);const hkReal nz=v1(0)*v2(1)-v1(1)*v2(0);this->set(nx,ny,nz,0.0f);}
__forceinline hkSimdReal dot3(const V& a)const{return (x*a.x)+(y*a.y)+(z*a.z);}
__forceinline hkSimdReal length3()const{return hkMath::sqrt((x*x)+(y*y)+(z*z));}
__forceinline void setInterpolate4(const V& v0,const V& v1,hkSimdRealParameter rt){hkReal t=hkReal(rt);hkReal s=1.0f-t;V& d=*this;d(0)=s*v0(0)+t*v1(0);d(1)=s*v0(1)+t*v1(1);d(2)=s*v0(2)+t*v1(2);d(3)=s*v0(3)+t*v1(3);}
__forceinline void setRotatedDir(const Q4& quat,const V& direction);
static __forceinline const V& getZero(){const V& zero=*reinterpret_cast<const V*>(&DAT_01092a50);return zero;}
};
struct Q4 {V m_vec;
inline const V& getImag()const{return m_vec;}
inline void setInverse(const Q4& q){m_vec.setNeg3(q.getImag());}
void setMul(const Q4& q0,const Q4& q1);void normalize();hkReal getAngle()const;void getAxis(V& axis)const;
};
__forceinline void V::setRotatedDir(const Q4& quat,const V& direction){
hkReal qreal=quat.m_vec(3);
hkReal q2minus1=qreal*qreal-0.5f;
V ret;
ret.setMul4(q2minus1,direction);
hkReal imagDotDir=quat.getImag().dot3(direction);
ret.addMul4(imagDotDir,quat.getImag());
V imagCrossDir;
imagCrossDir.setCross(quat.getImag(),direction);
ret.addMul4(qreal,imagCrossDir);
this->setAdd4(ret,ret);
}
struct Motion {
virtual void v00();virtual void v04();virtual void v08();virtual void v0c();
virtual void v10();virtual void v14();virtual void v18();virtual void v1c();
virtual void v20();virtual void v24();virtual void v28();virtual void v2c();
virtual void v30();virtual void v34();virtual void v38();virtual void v3c();
virtual void setLinearVelocity(const V& v);virtual void setAngularVelocity(const V& v);
int unk010,unk014,unk018,unk01c,unk020,unk024,unk028,unk02c,unk030,unk034,unk038,unk03c,unk040;
int unk044,unk048,unk04c,unk050,unk054,unk058,unk05c,unk060,unk064,unk068,unk06c,unk070,unk074,unk078,unk07c,unk080;
int unk084,unk088,unk08c,unk090,unk094,unk098,unk09c,unk0a0,unk0a4,unk0a8,unk0ac,unk0b0,unk0b4,unk0b8,unk0bc,unk0c0;
int unk0c4,unk0c8,unk0cc;
V m_linearVelocity;V m_angularVelocity;
};
struct RigidBody {
int unk000,unk004,unk008,unk00c,unk010,unk014,unk018,unk01c,unk020,unk024,unk028,unk02c,unk030,unk034,unk038,unk03c;
int unk040,unk044,unk048,unk04c,unk050,unk054,unk058,unk05c,unk060,unk064,unk068,unk06c,unk070,unk074,unk078,unk07c;
int unk080,unk084,unk088,unk08c,unk090,unk094,unk098,unk09c,unk0a0,unk0a4,unk0a8,unk0ac,unk0b0,unk0b4,unk0b8,unk0bc;
int unk0c0,unk0c4,unk0c8,unk0cc;
Motion m_motion;
void FUN_0090b500();
inline Motion* getRigidMotion()const{return const_cast<Motion*>(&m_motion);}
inline const V& getLinearVelocity()const{return getRigidMotion()->m_linearVelocity;}
inline const V& getAngularVelocity()const{return getRigidMotion()->m_angularVelocity;}
inline void setLinearVelocity(const V& newVel){FUN_0090b500();getRigidMotion()->setLinearVelocity(newVel);}
inline void setAngularVelocity(const V& newVel){FUN_0090b500();getRigidMotion()->setAngularVelocity(newVel);}
};
struct World {int unk00,unk04,unk08,unk0c;V m_gravity;};
struct Entity {
virtual void v000();virtual void v004();virtual void v008();virtual void v00c();
virtual void v010();virtual void v014();virtual void v018();virtual void v01c();
virtual void v020();virtual void v024();virtual void v028();virtual void v02c();
virtual void v030();virtual void v034();virtual void v038();virtual void v03c();
virtual void v040();virtual void v044();virtual void v048();virtual void v04c();
virtual void v050();virtual void v054();virtual void v058();virtual void v05c();
virtual void v060();virtual void v064();virtual void v068();virtual void v06c();
virtual void v070();virtual void v074();virtual void v078();virtual void v07c();
virtual void v080();virtual void v084();virtual void v088();virtual void v08c();
virtual void v090();virtual void v094();virtual void v098();virtual void v09c();
virtual void v0a0();virtual void v0a4();virtual void v0a8();virtual void v0ac();
virtual void v0b0();virtual void v0b4();virtual void v0b8();virtual void v0bc();
virtual void v0c0();virtual void v0c4();virtual void v0c8();virtual void v0cc();
virtual Q4 GetRotation();
virtual void v0d4();virtual void v0d8();virtual void v0dc();virtual void v0e0();
virtual const V& GetCenterOfMassLocal(V& out);
virtual const V& GetCenterOfMassInWorld(V& out);
int unk04;RigidBody* body;
float FUN_004e6160();float FUN_008fe4f0();World* FUN_008f81f0();void FUN_00c24b70();
const V& GetLinearVelocity(){RigidBody* b=body;return b?b->getLinearVelocity():V::getZero();}
const V& GetAngularVelocity(){RigidBody* b=body;return b?b->getAngularVelocity():V::getZero();}
void SetLinearVelocity(const V& v){RigidBody* b=body;if(b){FUN_00c24b70();b->setLinearVelocity(v);FUN_00c24b70();}}
void SetAngularVelocity(const V& v){RigidBody* b=body;if(b){FUN_00c24b70();b->setAngularVelocity(v);FUN_00c24b70();}}
void FUN_008ff5a0(const V& nextPosition,const Q4& nextOrientation,hkReal invDeltaTime,hkReal blend);
};
// pdb: bhkRigidBody::ApplyKeyframe | bhkRigidBody.obj | fnv360_0822_retail, call_gap, low
// pdb params: arNewPos, arNewRot, afInvDeltaTime, afVelGain
void Entity::FUN_008ff5a0(const V& nextPosition,const Q4& nextOrientation,hkReal invDeltaTime,hkReal blend){
V center;
V newCenterOfMassPosition;
newCenterOfMassPosition.setRotatedDir(nextOrientation,GetCenterOfMassLocal(center));
newCenterOfMassPosition.add4(nextPosition);
V linearVelocity;
linearVelocity.setSub4(newCenterOfMassPosition,GetCenterOfMassInWorld(center));
linearVelocity.mul4(invDeltaTime);
hkReal linLen=linearVelocity.length3();
hkReal maxLin=FUN_004e6160();
if(linLen>maxLin){linearVelocity.mul4(maxLin/linLen);}
{
V angularVelocity;
{
Q4 quatDif;
Q4 inverse;inverse.setInverse(GetRotation());quatDif.setMul(nextOrientation,inverse);
quatDif.normalize();
angularVelocity=V::getZero();
hkReal angle=quatDif.getAngle();
if(0.001f<angle){quatDif.getAxis(angularVelocity);angularVelocity.setMul4(angle*invDeltaTime,angularVelocity);}
}
hkReal angLen=angularVelocity.length3();
hkReal maxAng=FUN_008fe4f0();
if(angLen>maxAng){angularVelocity.mul4(maxAng/angLen);}
World* world=FUN_008f81f0();
if(world){V gravity;gravity=world->m_gravity;linearVelocity(2)-=gravity(2)*blend/invDeltaTime;}
V newLin;newLin.setInterpolate4(GetLinearVelocity(),linearVelocity,blend);
V newAng;newAng.setInterpolate4(GetAngularVelocity(),angularVelocity,blend);
SetLinearVelocity(newLin);
SetAngularVelocity(newAng);
}
}
}
}   // namespace f3m_008ff5a0

// @f3 0x008f9b90 (community match, verified in this file)
namespace f3m_008f9b90 {
struct PackedInner { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; unsigned value; };
struct PackedMid {int unk00,unk04,unk08,unk0C;PackedInner inner;};
struct PackedOwner;
struct PackedMethods {void* unk[0x30]; void (__thiscall* update)(PackedOwner*);};
struct PackedOwner {PackedMethods* methods;int unk04;PackedMid* mid;
PackedInner* GetInner(){ if(this&&mid) return &mid->inner; return 0; }
unsigned Get(){PackedInner* p=GetInner(); return p? p->value:0;}
void Set(unsigned v){PackedInner* p=GetInner(); if(p) p->value=v;}
void FUN_008f9b90(unsigned);};
// pdb: bhkWorldObject::SetCollisionGroup | bhkWorldObject.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiGroup
void PackedOwner::FUN_008f9b90(unsigned high){unsigned v=Get()&0xffff; v|=high<<16; Set(v); methods->update(this);}
}   // namespace f3m_008f9b90

// @f3 0x008e3320 (community match, verified in this file)
namespace f3m_008e3320 {
void __cdecl FUN_0095ee30(void* p);

namespace f3m_008e3320 {

struct MemMgr_008e3320 { void FUN_0086ba60(void* p); };

struct Node_008e3320 {
    unsigned int unk00;
    void* unk04;
    unsigned int unk08;
    void** items;
    int count;
    void* unk14;
};

static __forceinline void MemFree_008e3320(void* p) { ((MemMgr_008e3320*)&f3m_008fd5b0::DAT_01090a78)->FUN_0086ba60(p); }

struct S_8dd250_008e3320 { void FUN_008dd250(); };
struct S_8f6f90_008e3320 { void FUN_008f6f90(void* p); };

}

struct FUN_008e3320 : f3m_008f7cb0::Task1579::FUN_00825830 {
    void* unk08;
    f3m_008e3320::Node_008e3320* node;
    f3m_008f7cb0::Task1579::RefObj* unk10;
    f3m_008f7cb0::Task1579::RefObj* unk14;
    unsigned int unk18;
    char* unk1c;
    virtual ~FUN_008e3320();
};

FUN_008e3320::~FUN_008e3320()
{
    if (unk08)
        FUN_0095ee30(unk08);
    if (node) {
        for (int i = 0; i < node->count; ++i) {
            FreeBlock443* b = (FreeBlock443*)node->items[i];
            if (b) {
                Heap443* h = (Heap443*)FUN_00d9b080(DAT_010f3170);
            if (h->buckets[1].count >= h->limit)
                h->FUN_008f6890(1, b, 0x3b);
            else
                ((Q78FreeList*)&h->buckets[1])->Push(b);
            }
        }
        f3m_008e3320::MemFree_008e3320(node->items);
        void* pv = node->unk14;
        Heap443* h2 = (Heap443*)FUN_00d9b080(DAT_010f3170);
        ((f3m_008e3320::S_8f6f90_008e3320*)h2)->FUN_008f6f90(pv);
        f3m_008e3320::MemFree_008e3320(node->unk04);
        FreeBlock443* n = (FreeBlock443*)node;
        if (n) {
            Heap443* h3 = (Heap443*)FUN_00d9b080(DAT_010f3170);
            if (h3->buckets[4].count >= h3->limit)
                h3->FUN_008f6890(4, n, 0x3b);
            else
                ((Q78FreeList*)&h3->buckets[4])->Push(n);
        }
    }
    if (unk10) unk10->Release();
    if (unk14) unk14->Release();
    char* p = unk1c;
    if (p) {
        ((f3m_008e3320::S_8dd250_008e3320*)p)->FUN_008dd250();
        f3m_008e3320::MemFree_008e3320(p - (unsigned char)p[-1]);
    }
}
}   // namespace f3m_008e3320

// @f3 0x008e2480 (community match, verified in this file)
extern double DAT_00db88e8;
#include <math.h>
namespace f3m_008e2480 {
// FUN_008e2480: bhkRagdollController::SetSGPoseLocalSpace (name from the New Vegas twin's PDB record, @fnv 0x00c79a50).
// Copies the ragdoll pose's local-space bone transforms (Havok) onto the bones' NiAVObject local transforms.
// Havok maths: hkVector4 / hkQuaternion / hkQsTransform / hkArray / hkaPose inline bodies as in the Havok 5.5.0 SDK
// (FPU build), with the SDK's __forceinline / inline declarations. Gamebryo: NiQuaternion::ToRotation is written out
// (it is the function at 0x0049da00, still called); NiQuaternion::Normalize is the body of 0x008af830 (inlined here).

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef short hkInt16;
typedef int hkInt32;
typedef unsigned int hkaPoseFlag;

class hkQuaternion;

class hkVector4
{
public:
	__forceinline hkVector4() { }
	__forceinline hkVector4(hkReal a, hkReal b, hkReal c, hkReal d=0);
	__forceinline hkVector4( const hkVector4& v);
	__forceinline hkReal& operator() (int i);
	__forceinline const hkReal& operator() (int i) const;
	__forceinline void setXYZ0(const hkVector4& xyz);
	__forceinline void setReciprocal3(const hkVector4& v);
	__forceinline hkSimdReal getSimdAt(int i) const;
	__forceinline void operator= (const hkVector4& v);
	__forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d=0);
	__forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
	__forceinline void setMul4(const hkVector4& a, const hkVector4& b);
	__forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a);
	__forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a);
	__forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
	__forceinline void setNeg4(const hkVector4& v);
	__forceinline void setNeg3(const hkVector4& v);
	__forceinline hkSimdReal dot3(const hkVector4& a) const;
	__forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
	__forceinline void setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction);

	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};

class hkQuaternion
{
public:
	inline hkQuaternion() { }
	__forceinline const hkVector4& getImag() const;
	hkReal getReal() const;
	void operator= (const hkQuaternion& q);
	void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
	void setInverse(const hkQuaternion& q);

	hkVector4 m_vec;
};

class hkQsTransform
{
public:
	__forceinline hkQsTransform() { }
	__forceinline hkQsTransform(const hkQsTransform& t);
	__forceinline void setInverse(const hkQsTransform& t);
	__forceinline void setMul(const hkQsTransform& aTb, const hkQsTransform& bTc);
	__forceinline void setMulInverseMul(const hkQsTransform& a, const hkQsTransform& b);

	hkVector4 m_translation;
	hkQuaternion m_rotation;
	hkVector4 m_scale;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

__forceinline void hkVector4::setXYZ0(const hkVector4& xyz)
{
	x = xyz.x;
	y = xyz.y;
	z = xyz.z;
	w = 0;
}

inline void hkVector4::setReciprocal3(const hkVector4& v)
{
	x = 1.0f / v.x;
	y = 1.0f / v.y;
	z = 1.0f / v.z;
	w = 1.0f;
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
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

inline hkVector4::hkVector4(hkReal a, hkReal b, hkReal c, hkReal d)
	: x(a), y(b), z(c), w(d)
{
}

inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
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

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}

inline hkReal hkQuaternion::getReal() const
{
	return m_vec(3);
}

inline void hkQuaternion::operator= (const hkQuaternion& q)
{
	m_vec = q.m_vec;
}

inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
	hkVector4 vec;
	vec.setCross(q0.getImag(), q1.getImag());
	vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
	vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
	hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.m_vec.dot3( q1.m_vec ) );
	m_vec = vec;
	m_vec(3) = real;
}

inline void hkQuaternion::setInverse( const hkQuaternion &q )
{
	m_vec.setNeg3( q.getImag() );
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

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;

	hkVector4 ret;
	ret.setMul4( q2minus1, direction );

	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );

	hkVector4 imagCrossDir;
	imagCrossDir.setCross( direction, quat.getImag() );
	ret.addMul4( qreal, imagCrossDir );

	this->setAdd4( ret, ret );
}

inline hkQsTransform::hkQsTransform(const hkQsTransform& t)
{
	m_translation = t.m_translation;
	m_rotation = t.m_rotation;
	m_scale = t.m_scale;
}

inline void hkQsTransform::setInverse( const hkQsTransform& t )
{
	m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
	m_translation.setNeg4(m_translation);
	m_rotation.setInverse(t.m_rotation);

	hkVector4 invScale; invScale.setReciprocal3( t.m_scale );
	m_scale.setXYZ0( invScale );
}

inline void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);

	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}

inline void hkQsTransform::setMulInverseMul( const hkQsTransform& a, const hkQsTransform &b )
{
	hkQsTransform h;
	h.setInverse( a );
	setMul(h, b);
}

template <typename T>
class hkArray
{
public:
	__forceinline T& operator[] (int i);
	__forceinline const T& operator[] (int i) const;

	T* m_data;
	int m_size;
	int m_capacityAndFlags;
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	return m_data[i];
}

class hkaBone;

class hkaSkeleton
{
public:
	const char* m_name;
	hkInt16* m_parentIndices;
	hkInt32 m_numParentIndices;
	hkaBone** m_bones;
	hkInt32 m_numBones;
};

class hkaPose
{
public:
	const hkQsTransform& getBoneLocalSpace (int boneIdx) const;
	const hkQsTransform& getBoneModelSpace (int boneIdx) const;
	void syncLocalSpace () const;

	int isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const;
	void clearFlag (int boneIdx, hkaPoseFlag enumToCheck) const;
	const hkQsTransform& calculateBoneModelSpace (int boneIdx) const;

	enum
	{
		F_BONE_LOCAL_DIRTY = 0x1,
		F_BONE_MODEL_DIRTY = 0x2
	};

	const hkaSkeleton* m_skeleton;
	mutable hkArray<hkQsTransform> m_localPose;
	mutable hkArray<hkQsTransform> m_modelPose;
	mutable hkArray<hkaPoseFlag> m_boneFlags;
};

__forceinline int hkaPose::isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const
{
	return m_boneFlags[boneIdx] & enumToCheck;
}

__forceinline void hkaPose::clearFlag (int boneIdx, hkaPoseFlag enumToCheck) const
{
	m_boneFlags[boneIdx] &= static_cast<hkaPoseFlag>(~enumToCheck);
}

__forceinline const hkQsTransform& hkaPose::getBoneModelSpace (int boneIdx) const
{
	if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY))
	{
		return m_modelPose[boneIdx];
	}
	else
	{
		return calculateBoneModelSpace(boneIdx);
	}
}

__forceinline const hkQsTransform& hkaPose::getBoneLocalSpace (int boneIdx) const
{
	if (! isFlagOn (boneIdx, F_BONE_LOCAL_DIRTY))
	{
		return m_localPose[boneIdx];
	}
	else
	{
		const hkQsTransform& modelFromBone = m_modelPose[boneIdx];

		const hkInt16 parentIdx = m_skeleton->m_parentIndices[boneIdx];

		if (parentIdx != -1)
		{
			const hkQsTransform& modelFromParent = getBoneModelSpace(parentIdx);

			m_localPose[boneIdx].setMulInverseMul(modelFromParent, modelFromBone);
		}
		else
		{
			m_localPose[boneIdx] = modelFromBone;
		}

		clearFlag (boneIdx, F_BONE_LOCAL_DIRTY);

		return m_localPose[boneIdx];
	}
}

// Gamebryo maths
class NiPoint3
{
public:
	NiPoint3& operator*= (float fScalar)
	{
		x *= fScalar;
		y *= fScalar;
		z *= fScalar;
		return *this;
	}
	float x, y, z;
};

class NiMatrix3
{
public:
	void SetCol(unsigned int uiCol, float f0, float f1, float f2)
	{
		m_pEntry[0][uiCol] = f0;
		m_pEntry[1][uiCol] = f1;
		m_pEntry[2][uiCol] = f2;
	}
	float m_pEntry[3][3];
};

class NiTransform
{
public:
	NiMatrix3 m_Rotate;
	NiPoint3 m_Translate;
	float m_fScale;
};

class NiQuaternion
{
public:
	NiQuaternion() { }
	void SetW(float w) { m_fW = w; }
	void SetX(float x) { m_fX = x; }
	void SetY(float y) { m_fY = y; }
	void SetZ(float z) { m_fZ = z; }
	void Normalize()
	{
		float fNorm = m_fW * m_fW + m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ;
		float fScale = 1.0f / (float)sqrt(fNorm);
		m_fW *= fScale;
		m_fX *= fScale;
		m_fY *= fScale;
		m_fZ *= fScale;
	}
	void ToRotation(NiMatrix3& kRot) const;

	float m_fW, m_fX, m_fY, m_fZ;
};

void NiQuaternion::ToRotation(NiMatrix3& rot) const
{
	float tx = 2.0f*m_fX;
	float ty = 2.0f*m_fY;
	float tz = 2.0f*m_fZ;
	float twx = tx*m_fW;
	float twy = ty*m_fW;
	float twz = tz*m_fW;
	float txx = tx*m_fX;
	float txy = ty*m_fX;
	float txz = tz*m_fX;
	float tyy = ty*m_fY;
	float tyz = tz*m_fY;
	float tzz = tz*m_fZ;

	rot.SetCol(0, 1.0f-(tyy+tzz), txy+twz, txz-twy);
	rot.SetCol(1, txy-twz, 1.0f-(txx+tzz), tyz+twx);
	rot.SetCol(2, txz+twy, tyz-twx, 1.0f-(txx+tyy));
}


inline float HK2NI(float f)
{
	return (float)(f * DAT_00db88e8);
}

inline void HK2NI(NiPoint3& arNiP, const hkVector4& arhkV)
{
	arNiP.x = HK2NI(arhkV(0));
	arNiP.y = HK2NI(arhkV(1));
	arNiP.z = HK2NI(arhkV(2));
}

inline void HK2NI(NiQuaternion& arNiQ, const hkQuaternion& arhkQ)
{
	arNiQ.SetX(arhkQ.m_vec(0));
	arNiQ.SetY(arhkQ.m_vec(1));
	arNiQ.SetZ(arhkQ.m_vec(2));
	arNiQ.SetW(arhkQ.m_vec(3));
}

inline NiQuaternion HK2NI(const hkQuaternion& arhkQ)
{
	NiQuaternion kQ;
	HK2NI(kQ, arhkQ);
	return kQ;
}

inline void HK2NI(NiTransform& arNiTran, const hkQsTransform& arhkTran)
{
	NiQuaternion kQuat = HK2NI(arhkTran.m_rotation);
	kQuat.Normalize();
	kQuat.ToRotation(arNiTran.m_Rotate);
	HK2NI(arNiTran.m_Translate, arhkTran.m_translation);
	arNiTran.m_fScale = arhkTran.m_scale(0);
}

// Game-side objects (offsets from the code; names are ours unless noted)
class bhkBlendCollisionObject
{
public:
	int unk00, unk04, unk08, unk0c, unk10;
	bool m_bDirty;
};

class NiCollisionObject
{
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
	virtual void v30(); virtual void v34(); virtual void v38();
	virtual bhkBlendCollisionObject* GetAsBlendCollisionObject();
};

class NiAVObject
{
public:
	int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
	NiPointer<NiCollisionObject> m_spCollisionObject;
	int unk20, unk24, unk28, unk2c, unk30;
	NiTransform m_kLocal;
	void SetTranslate(const NiPoint3& kTrans) { m_kLocal.m_Translate = kTrans; }
	void SetRotate(const NiMatrix3& kRot) { m_kLocal.m_Rotate = kRot; }
};

class RagdollScale
{
public:
	int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094;
	float m_fScale;
};

class SkeletonSource
{
public:
	int unk00, unk04, unk08;
	const hkaSkeleton* m_skeleton;
};

class bhkRagdollController
{
public:
	int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054;
	RagdollScale* m_pScale;
	int unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084;
	hkaPose* m_pPose;
	int unk08c, unk090, unk094, unk098, unk09c, unk0a0;
	NiAVObject** m_ppBones;
	int unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c, unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0;
	SkeletonSource* m_pSource;

	void FUN_008e2480();
};

// pdb: bhkRagdollController::SetSGPoseLocalSpace | bhkRagdollController.obj | fnv360_0822_retail, call_gap, medium
void bhkRagdollController::FUN_008e2480()
{
	int inumSkelBones = m_pSource->m_skeleton->m_numBones;
	m_pPose->syncLocalSpace();
	float fragdollScaleInv = 1.0f / m_pScale->m_fScale;
	for (int i = 0; i < inumSkelBones; i++)
	{
		NiAVObject* pobj = m_ppBones[i];
		NiTransform transf;
		const hkQsTransform& kLocal = m_pPose->getBoneLocalSpace(i);
		HK2NI(transf, kLocal);
		transf.m_Translate *= fragdollScaleInv;
		pobj->SetTranslate(transf.m_Translate);
		pobj->SetRotate(transf.m_Rotate);
		NiCollisionObject* pcol = pobj->m_spCollisionObject;
		if (pcol)
		{
			bhkBlendCollisionObject* pblendCol = pcol->GetAsBlendCollisionObject();
			if (pblendCol)
				pblendCol->m_bDirty = true;
		}
	}
}
}   // namespace f3m_008e2480

// @f3 0x008e2bb0 (community match, verified in this file)
#include <math.h>
extern const char str_00e32bf0[];
extern const char str_00e32c34[];
extern const char str_00e32c40[];
extern const char str_00e32c48[];
extern const char str_00e32c68[];
namespace f3m_008e2bb0 {
// FUN_008e2bb0: bhkRagdollController::CheckMappersForWarnings (name from the New Vegas twin's PDB record, @fnv 0x00c79e20,
// fnv_decomp src\staging\blk_00c60000_o2.cpp). For both skeleton mappers of the ragdoll (ragdoll->animation and back),
// warns (HK_WARN_ALWAYS expansion: assertBuf / hkErrStream ostr / hkError::message, id 0xbadbadba) for every simple
// mapping whose B bone locks translation, whose bone has no matching rigid body, and whose mapping translation is longer
// than 0.01. Returns true if a mapper is missing or a warning was written.
// Havok: hkVector4 / hkQsTransform / hkArray / hkaSkeletonMapperData / hkaRagdollInstance / hkpWorldObject declarations
// and inline bodies as in the Havok 5.5.0 SDK (FPU build), HK_FORCE_INLINE as __forceinline, HK_ALIGN16 as align(16).

namespace f3m_008e2bb0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef short hkInt16;
typedef int hkInt32;
typedef unsigned long hkUlong;

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
}

class hkBool
{
public:
	operator bool() const { return m_bool != 0; }
	char m_bool;
};

class hkVector4
{
public:
	__forceinline hkSimdReal length3() const;
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};

__forceinline hkSimdReal hkVector4::length3() const
{
	return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
}

class hkQuaternion
{
public:
	hkVector4 m_vec;
};

class hkQsTransform
{
public:
	__forceinline const hkVector4& getTranslation() const;
	hkVector4 m_translation;
	hkQuaternion m_rotation;
	hkVector4 m_scale;
};

__forceinline const hkVector4& hkQsTransform::getTranslation() const
{
	return m_translation;
}

template <typename T>
class hkArray
{
public:
	__forceinline T& operator[] (int i) { return m_data[i]; }
	__forceinline const T& operator[] (int i) const { return m_data[i]; }
	__forceinline int getSize() const { return m_size; }
	T* m_data;
	int m_size;
	int m_capacityAndFlags;
};

class hkaBone
{
public:
	char* m_name;
	hkBool m_lockTranslation;
};

class hkaSkeleton
{
public:
	const char* m_name;
	hkInt16* m_parentIndices;
	hkInt32 m_numParentIndices;
	hkaBone** m_bones;
	hkInt32 m_numBones;
};

class hkReferencedObject
{
public:
	virtual ~hkReferencedObject();
	unsigned short m_memSizeAndFlags;
	short m_referenceCount;
};

class hkaSkeletonMapperData
{
public:
	struct SimpleMapping
	{
		hkInt16 m_boneA;
		hkInt16 m_boneB;
		hkQsTransform m_aFromBTransform;
	};
	const hkaSkeleton* m_skeletonA;
	const hkaSkeleton* m_skeletonB;
	hkArray<struct SimpleMapping> m_simpleMappings;
};

class hkaSkeletonMapper : public hkReferencedObject
{
public:
	hkaSkeletonMapperData m_mapping;
};

class hkOstream : public hkReferencedObject
{
public:
	~hkOstream();
	hkOstream& operator<< (const char* s);
	hkOstream& operator<< (float f);
	void* m_writer;
};

class hkErrStream : public hkOstream
{
public:
	hkErrStream( void* buf, int bufSize );
};

class hkError : public hkReferencedObject
{
public:
	enum Message { MESSAGE_REPORT, MESSAGE_WARNING, MESSAGE_ASSERT, MESSAGE_ERROR };
	virtual void v04();
	virtual void v08();
	virtual int message(Message m, int id, const char* description, const char* file, int line) = 0;
	static hkError& getInstance();
};
extern hkError* DAT_010f3364; // hkSingleton<hkError>::s_instance
inline hkError& hkError::getInstance() { return *DAT_010f3364; }

// Gamebryo RTTI
class NiRTTI
{
public:
	const NiRTTI* GetBaseRTTI() const { return m_pkBaseRTTI; }
	const char* m_pcName;
	const NiRTTI* m_pkBaseRTTI;
};

class NiObject
{
public:
	virtual void v00();
	virtual void v04();
	virtual const NiRTTI* GetRTTI() const;
	bool IsKindOf(const NiRTTI* pkRTTI) const
	{
		const NiRTTI* pkTmp = GetRTTI();
		while (pkTmp)
		{
			if (pkTmp == pkRTTI)
				return true;
			pkTmp = pkTmp->GetBaseRTTI();
		}
		return false;
	}
};

// 0x00424d50: Gamebryo NiDynamicCast(const NiRTTI*, NiObject*), out of line (named by address for the checker).
extern "C" NiObject* __cdecl FUN_00424d50(const NiRTTI* pkRTTI, const NiObject* pkObject);
extern NiRTTI DAT_010f33b4; // ms_RTTI of the bhk rigid-body class both loops test


class hkpWorldObject : public hkReferencedObject
{
public:
	inline hkUlong getUserData() const;
	void* m_world;
	hkUlong m_userData;
};

inline hkUlong hkpWorldObject::getUserData() const
{
	return m_userData;
}

class hkpRigidBody : public hkpWorldObject
{
};

class hkpConstraintInstance;

class hkaRagdollInstance : public hkReferencedObject
{
public:
	inline hkpRigidBody* getRigidBodyOfBone (int i) const;
	hkArray<hkpRigidBody*> m_rigidBodies;
	hkArray<hkpConstraintInstance*> m_constraints;
	hkArray<int> m_boneToRigidBodyMap;
	const hkaSkeleton* m_skeleton;
};

inline hkpRigidBody* hkaRagdollInstance::getRigidBodyOfBone (int i) const
{
	const int rbIdx = m_boneToRigidBodyMap[i];
	return (rbIdx<0) ? 0 : m_rigidBodies[rbIdx];
}

// Ragdoll data object at bhkRagdollController+0x2a4 (a raw pointer, as in our verified 0x008e2480, read through the inline accessor GetSource()). Name and layout ours, offsets from the
// code; +0x0c is the skeleton 0x008e2480 reads, +0x10/+0x14 the two skeleton mappers.
class SkeletonSource
{
public:
	int unk00, unk04, unk08;
	const hkaSkeleton* m_skeleton;
	hkaSkeletonMapper* m_mappers[2];
};

class bhkRagdollController
{
public:
	int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044;
	hkaRagdollInstance* m_pRagdoll;
	int unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c, unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0;
	SkeletonSource* m_pSource;
	SkeletonSource* GetSource() const { return m_pSource; }

	bool FUN_008e2bb0();
};

// pdb: bhkRagdollController::CheckMappersForWarnings | bhkRagdollController.obj | fnv360_0822_retail, strset, low, conflict (skyrim: `anonymous namespace'::CheckMapperForWarnings)
bool bhkRagdollController::FUN_008e2bb0()
{
	bool bret = false;
	if (!GetSource() || !GetSource()->m_mappers[0] || !GetSource()->m_mappers[1])
	{
		bret = true;
		goto done;
	}

	for (int i = 0; i < GetSource()->m_mappers[0]->m_mapping.m_simpleMappings.getSize(); i++)
	{
		const hkaSkeletonMapperData::SimpleMapping& simpleMapping = GetSource()->m_mappers[0]->m_mapping.m_simpleMappings[i];
		hkInt16 boneIdA = simpleMapping.m_boneA;
		hkInt16 boneIdB = simpleMapping.m_boneB;
		const hkaBone* rboneA = GetSource()->m_mappers[0]->m_mapping.m_skeletonA->m_bones[boneIdA];
		const hkaBone* rboneB = GetSource()->m_mappers[0]->m_mapping.m_skeletonB->m_bones[boneIdB];
		hkpRigidBody* prb = m_pRagdoll->getRigidBodyOfBone(boneIdB);
		NiObject* prbBHK = FUN_00424d50(&DAT_010f33b4, prb ? (NiObject*)prb->getUserData() : 0);
		if (rboneB->m_lockTranslation && !prbBHK)
		{
			const hkVector4& trans = simpleMapping.m_aFromBTransform.getTranslation();
			hkReal err = trans.length3();
			if (err > 0.01f)
			{
				{
					char assertBuf[512];
					hkErrStream ostr(assertBuf, sizeof(assertBuf));
					ostr << str_00e32c34 << rboneA->m_name << str_00e32c40 << rboneB->m_name << str_00e32c48 << err << str_00e32c68;
					hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xbadbadba, assertBuf, str_00e32bf0, 0xc19);
				}
				bret = true;
			}
		}
	}

	for (int i = 0; i < GetSource()->m_mappers[1]->m_mapping.m_simpleMappings.getSize(); i++)
	{
		const hkaSkeletonMapperData::SimpleMapping& simpleMapping = GetSource()->m_mappers[1]->m_mapping.m_simpleMappings[i];
		hkInt16 boneIdA = simpleMapping.m_boneA;
		hkInt16 boneIdB = simpleMapping.m_boneB;
		const hkaBone* rboneA = GetSource()->m_mappers[1]->m_mapping.m_skeletonA->m_bones[boneIdA];
		const hkaBone* rboneB = GetSource()->m_mappers[1]->m_mapping.m_skeletonB->m_bones[boneIdB];
		hkpRigidBody* prb = m_pRagdoll->getRigidBodyOfBone(boneIdA);
		NiObject* prbBHK = prb ? (NiObject*)prb->getUserData() : 0;
		NiObject* prbT = !prbBHK ? 0 : (prbBHK->IsKindOf(&DAT_010f33b4) ? prbBHK : 0);
		if (rboneB->m_lockTranslation && !prbT)
		{
			const hkVector4& trans = simpleMapping.m_aFromBTransform.getTranslation();
			hkReal err = trans.length3();
			if (err > 0.01f)
			{
				{
					char assertBuf[512];
					hkErrStream ostr(assertBuf, sizeof(assertBuf));
					ostr << str_00e32c34 << rboneA->m_name << str_00e32c40 << rboneB->m_name << str_00e32c48 << err << str_00e32c68;
					hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xbadbadba, assertBuf, str_00e32bf0, 0xc33);
				}
				bret = true;
			}
		}
	}
done:
	return bret;
}


}
}   // namespace f3m_008e2bb0

// @f3 0x008ed6f0 (community match, verified in this file)
namespace f3m_008ed6f0 {



// FO3 x87 Havok build of FNV ParentC::FUN_00c711d0 (character listener processConstraintsCallback).

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;

extern const float DAT_00dcda0c;
extern const double DAT_00e337d8;
extern const double DAT_00db88e8;
extern const double DAT_00e337d0;
extern const float DAT_00e337cc;
extern float DAT_00f79758;
extern const float DAT_00e337c8;
extern const double DAT_00dba5c8;
extern const float DAT_00e337c4;
extern const float DAT_00db7260;
extern float DAT_010f2e80;

inline float hkSqrtInverseSafe(float r)
{
    if (r != 0.0f)
        return 1.0f / (float)sqrt(r);
    return 0.0f;
}

struct hkSimdReal
{
    float m_real;
    inline hkSimdReal(float f) : m_real(f) {}
    inline float getReal() const { return m_real; }
};

struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    float v[4];

    __forceinline hkVector4() {}
    __forceinline hkVector4(float a, float b, float c, float d)
    {
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
    }
    __forceinline hkVector4(const hkVector4& o)
    {
        v[0] = o.v[0];
        v[1] = o.v[1];
        v[2] = o.v[2];
        v[3] = o.v[3];
    }
    inline void operator=(const hkVector4& o)
    {
        v[0] = o.v[0];
        v[1] = o.v[1];
        v[2] = o.v[2];
        v[3] = o.v[3];
    }
    __forceinline void set(float a, float b, float c, float d)
    {
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
    }
    // +0x44: the constant fill is two members, w first and then a chain over x, y, z. With one four-lane chain the
    // compiler emits the flag clear before the load of the constant; with this split the load comes first, as in
    // the target (and the stores keep the order w, z, y, x).
    __forceinline void setXYZ(float f)
    {
        v[0] = v[1] = v[2] = f;
    }
    __forceinline void setW(float f)
    {
        v[3] = f;
    }
    __forceinline void setZero4()
    {
        v[0] = v[1] = v[2] = v[3] = 0.0f;
    }
    __forceinline void add4(const hkVector4& o)
    {
        v[0] += o.v[0];
        v[1] += o.v[1];
        v[2] += o.v[2];
        v[3] += o.v[3];
    }
    __forceinline void sub4(const hkVector4& o)
    {
        v[0] -= o.v[0];
        v[1] -= o.v[1];
        v[2] -= o.v[2];
        v[3] -= o.v[3];
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        v[0] = a.v[0] + b.v[0];
        v[1] = a.v[1] + b.v[1];
        v[2] = a.v[2] + b.v[2];
        v[3] = a.v[3] + b.v[3];
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        v[0] = a.v[0] - b.v[0];
        v[1] = a.v[1] - b.v[1];
        v[2] = a.v[2] - b.v[2];
        v[3] = a.v[3] - b.v[3];
    }
    __forceinline void mul4(float s)
    {
        float f = s;
        v[0] *= f;
        v[1] *= f;
        v[2] *= f;
        v[3] *= f;
    }
    // +0xb64, +0xcdf, +0xefa: the squared length is dot3(*this) with an hkSimdReal result, as in Havok's own
    // headers. This gives the target's y, x, z load order for the local vectors d and direction; a plain
    // v[0]*v[0] + v[1]*v[1] + v[2]*v[2] loads x first.
    __forceinline hkSimdReal dot3(const hkVector4& a) const
    {
        return v[0] * a.v[0] + v[1] * a.v[1] + v[2] * a.v[2];
    }
    __forceinline float lengthSquared3() const
    {
        return dot3(*this).getReal();
    }
    __forceinline float lengthInverse3() const
    {
        return hkSqrtInverseSafe(lengthSquared3());
    }
    __forceinline void normalize3()
    {
        float invLen = lengthInverse3();
        mul4(invLen);
    }
    __forceinline float& operator()(int i)
    {
        return v[i];
    }
    inline float getComponent(int i) const
    {
        return v[i];
    }

    void hkVector4_setTransformedPos(const hkTransform& t, const hkVector4& o);
    void FUN_008d2970(const hkTransform& t, const hkVector4& o);
};

struct hkTransform
{
    hkVector4 m_col0, m_col1, m_col2, m_translation;
};

struct NiPoint3
{
    float x, y, z;
    inline NiPoint3() {}
    inline NiPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
    __forceinline void RemoveProjection(const NiPoint3& projection, float& length) { float projected = projection.Dot(*this); if (projected > 0.0f) { x-=projection.x; y-=projection.y; z-=projection.z; length=SqrLength(); }  }
    inline NiPoint3& operator=(const NiPoint3& p) { x=p.x; y=p.y; z=p.z; return *this; }
    inline float Dot(const NiPoint3& pt) const { return x * pt.x + y * pt.y + z * pt.z; }
    inline float SqrLength() const { return x * x + y * y + z * z; }
    inline NiPoint3 operator*(float fScalar) const { return NiPoint3(fScalar * x, fScalar * y, fScalar * z); }
    inline NiPoint3 operator/(float fScalar) const { float fInvScalar = 1.0f / fScalar; return NiPoint3(fInvScalar * x, fInvScalar * y, fInvScalar * z); }
};


inline float HavokToNi(float f)
{
    return (float)(f * 6.999040126800537);
}

__forceinline void HavokToNiPoint(NiPoint3* out, const hkVector4& in)
{
    out->x = HavokToNi(in.getComponent(0));
    out->y = HavokToNi(in.getComponent(1));
    out->z = HavokToNi(in.getComponent(2));
}

struct hkThreadMemory
{
    void* FUN_008f6d30(int nbytes, int cls);
    void FUN_008f6d90(void* p, int nbytes, int cls);
    static inline hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};

template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
    }
    __forceinline ~hkArray()
    {
        releaseMemory();
    }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline hkArray<T>& operator=(const hkArray<T>& a)
    {
        if (getCapacity() < a.m_size)
        {
            releaseMemory();
            m_data = (T*)hkThreadMemory::getInstance().FUN_008f6d30(a.m_size * sizeof(T), 0x17);
            m_capacityAndFlags = a.m_size;
        }
        m_size = a.m_size;
        T* dst = m_data;
        const T* src = a.m_data;
        for (int i = 0; i < m_size; ++i)
            dst[i] = src[i];
        return *this;
    }
};

struct hkBool
{
    char m_bool;
    inline hkBool() {}
};

struct hkpShapeMaterial
{
    int unk00, unk04, unk08, unk0c;
    unsigned int m_flags;
    inline int getType() const { return m_flags & 0x1f; }
};

struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    int m_filterInfo;
    int m_collectionFilter;
    int unk28, unk2c;
};

struct hkpShapeRayCastOutputFields
{
    hkVector4 m_normal;
    float m_hitFraction;
    int m_extraInfo;
    int unk18, unk1c;
    int m_shapeKeys[8];
    void* m_rootCollidable;
    __forceinline void reset()
    {
        m_hitFraction = 1.0f;
        m_extraInfo = -1;
        m_rootCollidable = 0;
        m_shapeKeys[0] = -1;
    }
};

struct hkpShapeRayCastOutput : hkpShapeRayCastOutputFields
{
    __forceinline hkpShapeRayCastOutput() { reset(); }
};

struct hkpShapeBase
{
    virtual void v00();
    virtual int v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual hkBool castRay(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output);
};

struct hkpShape : hkpShapeBase
{
    int unk04;
    hkpShapeMaterial* m_material;
    int m_kind;
    __forceinline int getType() const { return m_kind; }
};

struct hkpConvexShape : hkpShape
{
    float m_radius;
    int unk14, unk18, unk1c;
    inline float getRadius() const { return m_radius; }
};

struct hkpCapsuleShape : hkpConvexShape
{
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpShapeContainer
{
    virtual void v00();
    virtual int getNumChildShapes();
};

struct hkpListShapeBase : hkpShapeBase
{
    int unk04;
    hkpShapeMaterial* m_material;
    int m_kind;
    __forceinline int getType() const { return m_kind; }
};

struct hkpWrappedShape : hkpListShapeBase, hkpShapeContainer
{
    struct __declspec(align(16)) ChildInfo
    {
        hkpShape* m_shape;
        unsigned int m_collisionFilterInfo;
        mutable int m_shapeSize;
        mutable int m_numChildShapes;
    };
    bool m_disableWelding;
    hkArray<ChildInfo> m_childInfo;
    inline hkpShape* getChildShapeInl(int i) const { return m_childInfo[i].m_shape; }
};

struct hkpRigidBody;

struct hkpCollidable
{
    hkpShape* m_shape;
    int unk04, unk08, unk0c;
    signed char m_ownerOffset;
    unsigned char unk11, unk12, unk13;
    int unk14;
    unsigned char m_type;
    unsigned char unk19, unk1a, unk1b;
    unsigned int m_collisionFilterInfo;
    __forceinline unsigned char getType() const { return m_type; }
    inline hkpRigidBody* getOwner()
    {
        return m_type == 1 ? reinterpret_cast<hkpRigidBody*>(reinterpret_cast<char*>(this) + m_ownerOffset) : 0;
    }
};

struct hkpMotion
{
    float FUN_008f8410();
};

struct bhkRigidBody;

struct hkpRigidBody
{
    int unk000, unk004, unk008;
    bhkRigidBody* m_userData;
    int unk010, unk014, unk018, unk01c, unk020, unk024, unk028;
    unsigned int m_filterInfo;
    int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
    int unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc;
    hkpMotion m_motion;
    int unk0d4;
    unsigned char m_motionType;
    unsigned char unk0d9, unk0da, unk0db;
    int unk0dc;
    hkTransform m_transform;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c;
    hkArray<hkpCollidable*> m_collidables;
    int unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    hkVector4 m_linearVelocity;
    inline int getMotionType() const { return m_motionType; }
    void FUN_009316e0();
    void FUN_009316f0();
};

extern hkVector4 DAT_01092a50;

struct bhkRigidBody
{
    int unk00, unk04;
    hkpRigidBody* m_body;
};

struct ShapeBody
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    hkTransform m_transform;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c;
    hkArray<hkpCollidable*> m_collidables;
};

struct NodeC
{
    int unk00, unk04;
    ShapeBody* body;
};

struct ShapeNodeC
{
    int unk00, unk04;
    hkpWrappedShape* body;
    inline hkpWrappedShape* GetBody() const { return body; }
};

struct hkpRootCdPoint
{
    hkVector4 m_position;
    hkVector4 m_normal;
    int unk20, unk24;
    hkpCollidable* m_rootCollidableB;
    int unk2c, unk30, unk34, unk38, unk3c;
};

struct hkpSurfaceConstraintInfo
{
    hkVector4 m_plane;
    hkVector4 m_velocity;
    float unk20, unk24;
    float m_extraDownStaticFriction;
    float m_dynamicFriction;
    int unk30, unk34, unk38, unk3c;
    void FUN_008e9460(const hkpSurfaceConstraintInfo* other);
};

struct hkpSimplexSolverInput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44;
    hkpSurfaceConstraintInfo* m_constraints;
    int m_numConstraints;
};

struct hkpRayHitCollector
{
    float m_earlyOutHitFraction;
    inline hkpRayHitCollector() { m_earlyOutHitFraction = 1.0f; }
    __forceinline void reset() { m_earlyOutHitFraction = 1.0f; }
    virtual void addRayHit(const void*, const void*) = 0;
    virtual ~hkpRayHitCollector() {}
};

struct hkpClosestRayHitCollector : hkpRayHitCollector
{
    int unk08, unk0c;
    hkpShapeRayCastOutputFields m_rayHit;
    void* m_root;
    inline hkpClosestRayHitCollector()
    {
        reset();
    }
    __forceinline void reset()
    {
        m_root = 0;
        m_rayHit.reset();
        hkpRayHitCollector::reset();
    }
    virtual void addRayHit(const void*, const void*);
};

struct MemoryManager
{
    void* FUN_0086b930(unsigned int size);
};
extern MemoryManager DAT_01090a78;

struct EntryPointer
{
    void* FUN_008e9650(void* object);
};

struct CollisionEntry
{
    EntryPointer object;
    NiPoint3 position, normal, velocity;
    CollisionEntry();
    static void* operator new(unsigned int size)
    {
        return DAT_01090a78.FUN_0086b930(size);
    }
    static void operator delete(void* p);
};

struct EntryList
{
    void FUN_0049fac0(CollisionEntry** item);
};

struct NearProxy
{
    int FUN_00919ef0();
};

extern hkpRigidBody* DAT_010f2e84;

bool __cdecl FUN_008ec480(hkpRigidBody* body);
hkpShapeMaterial* __cdecl FUN_008f1b30(hkpCollidable* collidable);

struct ParentPrefix
{
    virtual void pv00();
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
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
    NearProxy nearProxy;
    int unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c;
};

struct ListenerC
{
    virtual void lv00();
    virtual void FUN_008ed6f0(hkArray<hkpRootCdPoint>& manifold, hkpSimplexSolverInput& input);
    void FUN_008db020(hkTransform* transform, hkpRootCdPoint* contact);
};

struct ParentC : ParentPrefix, ListenerC
{
    union
    {
        unsigned int flags;
        struct
        {
            unsigned char flagLo, flagMid, flagHi, flagTop;
        };
    };
    int unk2b8, unk2bc, unk2c0, unk2c4, unk2c8, unk2cc;
    float threshold;
    int unk2d4;
    int material;
    int unk2dc, unk2e0, unk2e4, unk2e8, unk2ec;
    hkVector4 normal;
    hkVector4 minV;
    float height;
    int unk2f4;
    bool allAuxiliary;
    unsigned char unk2f9;
    unsigned short unk2fa;
    int unk2fc, unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    hkVector4 initialNormal;
    int unk370, unk374, unk378, unk37c, unk380, unk384, unk388, unk38c;
    int unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac;
    int unk3b0, unk3b4, unk3b8, unk3bc, unk3c0, unk3c4, unk3c8, unk3cc;
    int unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec;
    int unk3f0;
    float scale;
    int unk3f8, unk3fc, unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420;
    NodeC* node;
    int unk428, unk42c;
    int unk430;
    int unk434;
    ShapeNodeC* shapeNode;
    int unk43c;
    hkTransform transform;
    int unk480, unk484, unk488, unk48c, unk490, unk494;
    int accepted;
    hkpRigidBody* reference;
    int unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4;
    EntryList entries;

    inline char getFlag(unsigned int n) const
    {
        return (unsigned char)(flags >> n) & 1;
    }
    inline void SetFlag(unsigned int m, bool b)
    {
        if (b)
            flags |= m;
        else
            flags &= ~m;
    }
    inline bool IsState1() const { return unk430 == 1; }
    inline void SetReference(hkpRigidBody* body)
    {
        if (reference != body)
        {
            if (reference)
                reference->FUN_009316f0();
            reference = body;
            body->FUN_009316e0();
        }
    }

    virtual void FUN_008ed6f0(hkArray<hkpRootCdPoint>& manifold, hkpSimplexSolverInput& input);
    void FUN_0059fb50(NiPoint3* velocity);
    void FUN_008ea1f0(hkVector4* position);
    bool FUN_008eadd0(hkpRootCdPoint* contact);
    void FUN_008ea810(hkpRootCdPoint* contact);
    ParentC* FUN_008e9780(void* object);
};

static inline bool IsDynamicMotion(const int& type)
{
    return type < 6 || type == 8;
}

// pdb: bhkCharacterController::processConstraintsCallback | bhkCharacterController.obj | fnv360_0822_retail, uconst, low, conflict (skyrim: bhkCharProxyController::processConstraintsCallback)
// pdb params: __formal, arManifold, arInput
void ParentC::FUN_008ed6f0(hkArray<hkpRootCdPoint>& contacts, hkpSimplexSolverInput& results)
{
    normal.setZero4();
    flags &= ~4u;
    minV.setW(1.175494351e-38f);
    minV.setXYZ(1.175494351e-38f);
    if (getFlag(16) && reference)
    {
        reference->FUN_009316f0();
        reference = 0;
    }
    accepted = 0;
    int inewConstraintsAdded = 0, auxiliary = 0;
    bool bnormalSet = false;
    normal = initialNormal;
    bool bcheckspheres = false;
    hkVector4 sphere0, sphere1;
    ShapeBody* pbody;
    bool state1 = IsState1();
    float fcheckradSqr = 0.0f;
    if (!state1 && !getFlag(5) && node && (pbody = node->body) != 0 && shapeNode && shapeNode->GetBody())
    {
        hkpWrappedShape* pshape = shapeNode->GetBody();
        if (pshape->getType() == 10 && pshape->getNumChildShapes() == 3)
        {
            hkpShape* pchild = pshape->getChildShapeInl(1);
            if (pchild && pchild->getType() == 6)
            {
                const hkpCapsuleShape& rcap = static_cast<const hkpCapsuleShape&>(*pchild);
                hkVector4 quadStiltSphereTop1 = rcap.m_vertexA;
                float r0 = rcap.getRadius();
                quadStiltSphereTop1(2) += r0;
                const hkTransform& rtransf = pbody->m_transform;
                sphere0.hkVector4_setTransformedPos(rtransf, quadStiltSphereTop1);
                hkpCapsuleShape* pp;
                pp = static_cast<hkpCapsuleShape*>(pshape->getChildShapeInl(2));
                if (pp && pp->getType() == 6)
                {
                    hkVector4 quadStiltSphereTop2 = pp->m_vertexA;
                    float r1 = pp->getRadius();
                    quadStiltSphereTop2.v[2] += r1;
                    sphere1.hkVector4_setTransformedPos(rtransf, quadStiltSphereTop2);
                    float accumulated = pp->getRadius();
                    fcheckradSqr = (float)(accumulated * DAT_00e337d8);
                    fcheckradSqr *= fcheckradSqr;
                    bcheckspheres = true;
                }
            }
        }
    }
    int iorigConstraints = results.m_numConstraints;
    bool hasMaterial2;
    hasMaterial2 = false;
    for (int i = 0; i < iorigConstraints; ++i)
    {
        hkpSurfaceConstraintInfo* response = &results.m_constraints[i];
        hkpRootCdPoint* contact = &contacts[i];
        hkpCollidable* source = contact->m_rootCollidableB;
        hkpRigidBody* bodyOwner = source->getOwner();
        unsigned int ifilter = source->m_collisionFilterInfo;
        if (getFlag(16) && (flags & 0x200000) && FUN_008ec480(bodyOwner) && bodyOwner)
        {
            bhkRigidBody* nodeBody;
            nodeBody = bodyOwner->m_userData;
            if (nodeBody)
            {
                NiPoint3 velocity;
                hkpRigidBody* rb = nodeBody->m_body;
                HavokToNiPoint(&velocity, rb ? rb->m_linearVelocity : DAT_01092a50);
                float squaredMagnitude = velocity.SqrLength();
                if (squaredMagnitude > 0.0f)
                {
                    NiPoint3 other(0.0f, 0.0f, 0.0f);
                    FUN_0059fb50(&other);
                    float velocityDot = other.Dot(velocity);
                    NiPoint3 proj;
                    proj = velocity * velocityDot / squaredMagnitude;
                    velocity.RemoveProjection(proj, squaredMagnitude);
                    if (squaredMagnitude > 0.0f)
                    {
                        CollisionEntry* entry = new CollisionEntry;
                        {
                            CollisionEntry* added = entry;
                            entry->object.FUN_008e9650(nodeBody);
                            HavokToNiPoint(&entry->position, contact->m_position);
                            HavokToNiPoint(&entry->normal, contact->m_normal);
                            memcpy(&entry->velocity, &velocity, sizeof(velocity));
                            entries.FUN_0049fac0(&added);
                        }
                    }
                }
            }
        }
        unsigned long elayer;
        elayer = ifilter & 0x7f;
        hasMaterial2 |= elayer == 2;
        bool eligibleContact = !getFlag(11);
        float fsurfaceVerticalComponent = contact->m_normal.v[2];
        bool bsupported = eligibleContact;
        if (bodyOwner && fsurfaceVerticalComponent > DAT_00e337d0 && bodyOwner->m_motionType == 6 && !DAT_010f2e84)
        {
            hkVector4 transformBody;
            FUN_008ea1f0(&transformBody);
            transformBody.v[2] += height;
            float contactZ = contact->m_position.getComponent(2);
            if (contactZ <= transformBody.v[2])
            {
                hkpClosestRayHitCollector collectorState;
                hkArray<hkpCollidable*> array;
                NodeC* n = node;
                ShapeBody* sourceBody = n->body;
                array = sourceBody->m_collidables;
                static const hkVector4 upOffset(0.0f, 0.0f, 36.0f, 0.0f);
                static const hkVector4 downOffset(0.0f, 0.0f, 54.0f, 0.0f);
                hkVector4 rayFrom;
                rayFrom.setAdd4(contact->m_position, upOffset);
                hkVector4 rayTo;
                rayTo.setSub4(rayFrom, downOffset);
                DAT_010f2e80 = DAT_00db7260;
                for (int rayIndex = 0; rayIndex < array.getSize(); ++rayIndex)
                {
                    hkpCollidable* tmp = array[rayIndex];
                    hkpRigidBody* b = tmp->getOwner();
                    if (!b || b->m_motionType != 6)
                        continue;
                    hkpShapeRayCastInput input;
                    input.m_filterInfo = 0;
                    input.m_collectionFilter = 0;
                    hkpShapeRayCastOutput rayOutput;
                    input.m_from.FUN_008d2970(b->m_transform, rayFrom);
                    input.m_to.FUN_008d2970(b->m_transform, rayTo);
                    tmp->m_shape->castRay(input, rayOutput);
                    if (rayOutput.m_hitFraction < 1.0f)
                    {
                        this->material = b->m_filterInfo & 0x7f;
                        int layer = this->material;
                        int idx;
                        idx = -1;
                        for (int k = 0; 8 > k; ++k)
                        {
                            int next = rayOutput.m_shapeKeys[k];
                            if (next == -1)
                                break;
                            idx = next;
                        }
                        if (idx == -1)
                        {
                            hkpShape* s = tmp->m_shape;
                            if (!s)
                                continue;
                            hkpShapeMaterial* m = s->m_material;
                            if (!m)
                                continue;
                            if (m->getType() != 0xf)
                                continue;
                        }
                        else
                        {
                            if (layer == 0x11)
                                continue;
                            hkpShapeMaterial* m = FUN_008f1b30(tmp);
                            if (!m || m->getType() != 0xf)
                                continue;
                        }
                        {
                            float intersectionHeight = rayFrom.v[2] + (rayTo.v[2] - rayFrom.v[2]) * rayOutput.m_hitFraction;
                            if (intersectionHeight > DAT_010f2e80)
                            {
                                DAT_010f2e80 = intersectionHeight;
                                DAT_010f2e84 = b;
                            }
                        }
                    }
                }
            }
        }
        hkVector4 tempSupportNormal;
        tempSupportNormal = response->m_plane;
        if (bodyOwner)
        {
            switch (elayer)
            {
            case 2: {
                int n = bodyOwner->getMotionType();
                if (6 == n || n == 7)
                {
                    response->m_extraDownStaticFriction = DAT_00e337cc;
                    break;
                }
            }
            case 10: {
                if (!(flagHi & 1))
                {
                    tempSupportNormal.set(0.0f, 0.0f, 1.0f, 0.0f);
                    fsurfaceVerticalComponent = 1.0f;
                    response->m_dynamicFriction = 0;
                    if (IsDynamicMotion(bodyOwner->getMotionType()))
                        response->m_velocity.setZero4();
                }
                eligibleContact = false;
                break;
            }
            case 4:
            case 5:
            case 6:
                if (!(flagHi & 1))
                {
                    float f;
                    f = bodyOwner->m_motion.FUN_008f8410();
                    if (f < DAT_00f79758)
                        response->m_velocity.setZero4();
                    tempSupportNormal.set(0.0f, 0.0f, 1.0f, 0.0f);
                    fsurfaceVerticalComponent = 1.0f;
                }
                eligibleContact = false;
                break;
            default:
                if (bcheckspheres && !getFlag(5))
                {
                    hkVector4 d;
                    d = contact->m_position;
                    d.sub4(sphere0);
                    if (d.lengthSquared3() < fcheckradSqr)
                    {
                        SetFlag(0x20, true);
                    }
                    else
                    {
                        d = contact->m_position;
                        d.sub4(sphere1);
                        if (d.lengthSquared3() < fcheckradSqr)
                            SetFlag(0x20, true);
                    }
                }
                break;
            }
        }
        if (!bodyOwner)
        {
            switch (elayer)
            {
            case 12:
            case 16:
            case 22:
            case 23:
            case 24:
            case 41:
                response->m_velocity.setZero4();
                continue;
            case 14:
                if (flagHi & 1)
                    response->m_velocity.setZero4();
                break;
            case 30: {
                hkpCollidable* tmp = contact->m_rootCollidableB;
                unsigned char ownerType = tmp->getType();
                void* ownerObject = ownerType == 2 ? reinterpret_cast<char*>(tmp) + tmp->m_ownerOffset : 0;
                ParentC* collidable = this->FUN_008e9780(ownerObject);
                if (collidable->flags & 0x8000000)
                {
                    response->m_plane.setZero4();
                    response->m_velocity.setZero4();
                }
                else
                {
                    response->m_plane(2) = 0;
                    float inverseLength = response->m_plane.lengthInverse3();
                    response->m_plane.mul4(inverseLength);
                }
                break;
            }
            default:
                break;
            }
            continue;
        }
        if (DAT_00e337c8 <= fsurfaceVerticalComponent)
        {
            bsupported = true;
            if (fsurfaceVerticalComponent < threshold)
            {
                bool onSlope = FUN_008eadd0(contact);
                if (onSlope)
                {
                    if ((eligibleContact || getFlag(11)) && fsurfaceVerticalComponent < DAT_00dba5c8)
                        bsupported = false;
                    if (inewConstraintsAdded < 4 && eligibleContact)
                    {
                        int index = results.m_numConstraints;
                        hkpSurfaceConstraintInfo* accumulated = &results.m_constraints[index];
                        accumulated->FUN_008e9460(response);
                        accumulated->m_velocity.setZero4();
                        accumulated->m_plane(2) = 0;
                        accumulated->m_plane.normalize3();
                        inewConstraintsAdded += 1;
                        results.m_numConstraints += 1;
                        if (bsupported)
                            auxiliary++;
                    }
                }
                else
                {
                    if (!(flags & 0x800) && !(flags & 0x1000))
                        response->m_dynamicFriction = 0;
                    tempSupportNormal.v[2] = 1.0f;
                    flags |= 0x404;
                    tempSupportNormal.normalize3();
                    response->m_plane = tempSupportNormal;
                }
            }
            else
            {
                if (!(flagHi & 1) && (flagLo & 1))
                    ListenerC::FUN_008db020(&transform, contact);
                {
                    unsigned int& f = flags;
                    f |= 0x400;
                }
                if (!getFlag(3))
                    response->m_extraDownStaticFriction = DAT_00e337c4;
            }
            if (!nearProxy.FUN_00919ef0())
                response->m_dynamicFriction *= scale;
            if (bsupported)
            {
                {
                    unsigned int& f = flags;
                    f |= 0x200;
                }
                accepted += 1;
                this->FUN_008ea810(&contacts[i]);
                if (bnormalSet)
                    normal.add4(tempSupportNormal);
                else
                {
                    bnormalSet = true;
                    normal = tempSupportNormal;
                }
                if (flagHi & 1)
                    SetReference(bodyOwner);
            }
        }
    }
    if (hasMaterial2)
        flags |= 0x20000000;
    else
        flags &= ~0x20000000;
    allAuxiliary = accepted == auxiliary;
    if (accepted && normal.lengthSquared3() > 0.0f)
        normal.normalize3();
}


}   // namespace f3m_008ed6f0

// @f3 0x008fa8b0 (community match, verified in this file)
namespace f3m_008fa8b0 {
namespace fn_008fa8b0 {
struct ConstraintBase {
    int m_memSizeAndFlags;
    int m_type;
    int m_constraintPriority;
    int m_constraintData;
    virtual void build();
    ConstraintBase() : m_memSizeAndFlags(0), m_constraintPriority(0), m_constraintData(0) {
        m_type = 1;
    }
};
struct FUN_008fa8b0 : ConstraintBase {
    virtual void build();
    FUN_008fa8b0();
};
// pdb: hkLimitedHingeConstraintCinfo::SetMaxFrictionTorque | WeaponObject.obj | tesv_win, objrun_open, low
FUN_008fa8b0::FUN_008fa8b0() : ConstraintBase() {
}
}
}   // namespace f3m_008fa8b0

// @f3 0x008e4500 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008e4500 {
namespace f3m_008e4500 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct Array {
    void* data;
    int size;
    int capacityAndFlags;
    void FUN_008e4500();
};
void Array::FUN_008e4500() {
    if (!(capacityAndFlags & 0x80000000)) {
        unsigned int capacity = capacityAndFlags & 0x3fffffff;
        Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(data, capacity * 0x70, 0x17);
    }
}
}
}   // namespace f3m_008e4500

// @f3 0x008e44c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008e44c0 {
namespace f3m_008e44c0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct Array {
    void* data;
    int size;
    int capacityAndFlags;
    void FUN_008e44c0();
};
void Array::FUN_008e44c0() {
    if (!(capacityAndFlags & 0x80000000)) {
        unsigned int capacity = capacityAndFlags & 0x3fffffff;
        Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(data, capacity * 0xd0, 0x17);
    }
}
}
}   // namespace f3m_008e44c0

// @f3 0x008fa890 (community match, verified in this file)
namespace f3m_008fa890 {
namespace f3m_008fa890 {
void __cdecl FUN_0089ec10(void*, unsigned);
struct Obj {
    void FUN_008fa3f0();
    Obj* FUN_008fa890(unsigned flags);
};
// pdb: WeaponObject::`scalar deleting destructor' | WeaponObject.obj | fnv360_0822_retail, caller_sim, low
Obj* Obj::FUN_008fa890(unsigned flags) {
    FUN_008fa3f0();
    if (flags & 1) FUN_0089ec10(this, 44);
    return this;
}
}
}   // namespace f3m_008fa890

// @f3 0x008f2400 (community match, verified in this file)
extern int DAT_00e33964;
namespace f3m_008f2400 {
namespace f3m_008f2400 {
extern void (__stdcall* DAT_00e3396c)(void*);
struct SimpleArray {
    void* vtable;
    void* data;
    unsigned size;
    unsigned capacity;
    void FUN_008f2400();
};
void SimpleArray::FUN_008f2400() {
    vtable = &DAT_00e33964;
    if (data) {
        DAT_00e3396c(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
}
}
}   // namespace f3m_008f2400

// @f3 0x008e4530 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_008e4530 {
namespace f3m_008e4530 {
struct Heap {
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual void Vf18(int value);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    int unk24;
    int unk28;
};
extern Heap* (__stdcall * const DAT_00d9b080)(unsigned long);
struct Obj {
    int unk00;
    void FUN_008e4530();
};
void Obj::FUN_008e4530() {
    int value = unk00;
    Heap* heap = DAT_00d9b080(DAT_010f3170);
    heap->unk20 = value;
    if (value == heap->unk28) heap->Vf18(value);
}
}
}   // namespace f3m_008e4530

// @f3 0x008f2350 (community match, verified in this file)
namespace f3m_008f2350 {
namespace fn_008f2350 {
struct ConstraintData {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual int getType();
    int m_fields[6];
    unsigned short m_runtimeIndex;
};
struct ConstraintOwner { int m_fields[7]; unsigned char* m_disabledFlags; };
struct RigidBody;
struct ConstraintInstance {
    int m_head[3]; ConstraintData* m_data; int m_field10; RigidBody* m_entityA; RigidBody* m_entityB;
    int m_mid[3]; ConstraintOwner* m_owner;
};
struct RigidBody { int m_head[40]; ConstraintInstance** m_constraints; int m_numConstraints; };
struct BodyArray { RigidBody** m_data; int m_size; int m_capacityAndFlags; };
void __cdecl ReserveArray(BodyArray* arr, int elemSize);
void __cdecl FUN_008f2350(RigidBody* body, BodyArray* outBodies) {
    for (int i = 0; i < body->m_numConstraints; ++i) {
        ConstraintInstance* ci = body->m_constraints[i];
        if (ci->m_data->getType() == 11) continue;
        bool disabled = false;
        if (ci->m_data->getType() == 12) {
            disabled = ci->m_owner->m_disabledFlags[ci->m_data->m_runtimeIndex] != 0;
        }
        if (disabled) continue;
        RigidBody* other = (ci->m_entityA == body) ? ci->m_entityB : ci->m_entityA;
        FUN_008f2350(other, outBodies);
        if (outBodies->m_size == (outBodies->m_capacityAndFlags & 0x3fffffff)) ReserveArray(outBodies, sizeof(RigidBody*));
        outBodies->m_data[outBodies->m_size++] = other;
    }
}
}
}   // namespace f3m_008f2350

// @f3 0x008e9900 (community match, verified in this file)
namespace n8e9900 {
struct RefObj {
    virtual void Delete(int flags);
    unsigned short unk04;
    short unk06;
    RefObj() { unk06 = 1; }
};

struct Alloc {
    void* FUN_008f6d30(unsigned int size, unsigned int tag);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct PoolObj : RefObj {
    static void operator delete(void* p);
    static void* operator new(unsigned int sz) {
        Alloc* a = (Alloc*)TlsGetValue(DAT_010f3170);
        void* p = a->FUN_008f6d30(sz, 0x34);
        *(unsigned short*)((char*)p + 4) = (unsigned short)sz;
        return p;
    }
};

struct Map : PoolObj {
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    Map();
    void hkpCharacterStateManager_registerState(RefObj* o, int key);
};
struct ObjB : PoolObj { int unk08; ObjB(); };
struct ObjC : PoolObj { ObjC(); };
struct ObjD : PoolObj { ObjD(); };
struct ObjE : PoolObj { int unk08; ObjE(); };
struct ObjH : PoolObj { ObjH(); };
}

class bhkCharacterStateClimbing : public n8e9900::PoolObj {
  public:
    bhkCharacterStateClimbing() {}
    virtual void Delete(int flags);
};
class bhkCharacterStateFlying : public n8e9900::PoolObj {
  public:
    bhkCharacterStateFlying() {}
    virtual void Delete(int flags);
};

namespace n8e9900 {
extern Map* DAT_010f2e7c;
extern unsigned int FUN_00f79e58;

inline void Rel(RefObj* o) {
    if (o->unk04 != 0) {
        if (--o->unk06 == 0)
            o->Delete(1);
    }
}

struct Vec4_local {
    float x, y, z, w;
    __forceinline Vec4_local& operator=(const Vec4_8fea20& o) {
        x = o.x; y = o.y; z = o.z; w = o.w;
        return *this;
    }
};
struct BaseT {
    Vec4_local unk00;
    Vec4_local unk10;
    float unk20; float unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    float unk40; float unk44; int unk48; int unk4c;
    float unk50; int unk54; float unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    BaseT();
    ~BaseT();
};
}

struct FUN_008e9900 : n8e9900::BaseT {
    int unk80;
    unsigned int unk84;
    int unk88;
    float unk8c;
    float unk90;
    unsigned char unk94;
    unsigned char unk95;
    unsigned char unk96;
    unsigned char unk97;
    unsigned char unk98;
    int unk9c;
    int unka0;
    int unka4;
    float unka8;
    float unkac;
    int unkb0;
    int unkb4;
    FUN_008e9900(bool flag);
    void FUN_008e90f0(n8e9900::Map* m);
};

// pdb: bhkCharacterControllerCinfo::bhkCharacterControllerCinfo | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
// pdb params: abDefaultStates
FUN_008e9900::FUN_008e9900(bool flag) {
    unk84 = 0;
    unka0 = 0;
    unk94 = 0;
    unk95 = 0;
    unk80 = 0;
    unsigned int h = (n8e9900::FUN_00f79e58 + 1) & 0xffff;
    n8e9900::FUN_00f79e58 = h;
    if (!h) {
        h = 10;
        n8e9900::FUN_00f79e58 = h;
    }
    unk88 = 0;
    unk8c = 0.0f;
    unk9c = 0;
    unk90 = 1.0f;
    unka4 = 0;
    unkb0 = 1;
    unka8 = 4.4291787f;
    unkb4 = 0;
    unk96 = 0;
    unk97 = 0;
    unk98 = 0;
    unkac = 1.0f;
    unk84 = (h << 16) | 0x1e;
    unk00 = DAT_01092a50;
    unk10 = DAT_01092a50;
    unk50 = 0.0f;
    unk24 = 0.0f;
    unk40 = 0.0f;
    unk44 = 0.0f;
    unk20 = 1.0f;
    unk58 = 100.0f;
    unk48 = 0;
    unk54 = 4;
    if (flag) {
        if (n8e9900::DAT_010f2e7c == 0) {
            n8e9900::Map* m = new n8e9900::Map;
            n8e9900::DAT_010f2e7c = m;
            n8e9900::ObjB* b = new n8e9900::ObjB;
            n8e9900::DAT_010f2e7c->hkpCharacterStateManager_registerState(b, 0);
            n8e9900::Rel(b);
            n8e9900::ObjC* ptr = new n8e9900::ObjC;
            n8e9900::DAT_010f2e7c->hkpCharacterStateManager_registerState(ptr, 5);
            n8e9900::Rel(ptr);
            n8e9900::ObjD* c5 = new n8e9900::ObjD;
            n8e9900::DAT_010f2e7c->hkpCharacterStateManager_registerState(c5, 1);
            n8e9900::Rel(c5);
            n8e9900::ObjE* g = new n8e9900::ObjE;
            n8e9900::DAT_010f2e7c->hkpCharacterStateManager_registerState(g, 2);
            n8e9900::Rel(g);
            bhkCharacterStateClimbing* f = new bhkCharacterStateClimbing;
            n8e9900::DAT_010f2e7c->hkpCharacterStateManager_registerState(f, 3);
            n8e9900::Rel(f);
            bhkCharacterStateFlying* j = new bhkCharacterStateFlying;
            n8e9900::DAT_010f2e7c->hkpCharacterStateManager_registerState(j, 4);
            n8e9900::Rel(j);
            n8e9900::ObjH* e;
            e = new n8e9900::ObjH;
            n8e9900::DAT_010f2e7c->hkpCharacterStateManager_registerState(e, 6);
            n8e9900::Rel(e);
        }
        FUN_008e90f0(n8e9900::DAT_010f2e7c);
    }
}

// @f3 0x008e3ab0 (community match, verified in this file)
#include <math.h>
namespace f3m_008e3ab0 {

namespace f3LookAt {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef short hkInt16;
typedef unsigned int hkUint32;

struct Quaternion;
struct Vec {
    __declspec(align(16)) hkReal x;
    hkReal y, z, w;
    __forceinline Vec() {}
    __forceinline void operator=(const Vec& v) {
        x = v.x; y = v.y; z = v.z; w = v.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0) {
        x = a; y = b; z = c; w = d;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline hkSimdReal getSimdAt(int i) const { return (&x)[i]; }
    __forceinline void setXYZ0(const Vec& a) { x = a.x; y = a.y; z = a.z; w = 0; }
    __forceinline void setReciprocal3(const Vec& a) {
        x = 1.0f / a.x; y = 1.0f / a.y; z = 1.0f / a.z; w = 1.0f;
    }
    __forceinline void setNeg3(const Vec& a) { x = -a.x; y = -a.y; z = -a.z; w = a.w; }
    __forceinline void setNeg4(const Vec& a) { x = -a.x; y = -a.y; z = -a.z; w = -a.w; }
    __forceinline void setAdd4(const Vec& a, const Vec& b) {
        x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w;
    }
    __forceinline void setMul4(const Vec& a, const Vec& b) {
        x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w;
    }
    __forceinline void setMul4(hkSimdRealParameter rs, const Vec& a) {
        hkReal r = rs;
        x = r * a(0); y = r * a(1); z = r * a(2); w = r * a(3);
    }
    static __forceinline void addScaled(hkReal& accumulator, const hkReal& value, hkReal scale) {
        accumulator += scale * value;
    }
    __forceinline void addMul4(hkSimdRealParameter rs, const Vec& a) {
        const hkReal r = rs;
        addScaled(x, a.x, r);
        addScaled(y, a.y, r);
        addScaled(z, a.z, r);
        w += r * a.w;
    }
    __forceinline hkSimdReal dot3(const Vec& a) const {
        return (hkReal)(x * a.x + y * a.y + (double)(z * a.z));
    }
    __forceinline hkReal dot3fpu(const Vec& a) const {
        return static_cast<hkReal>((double)(z * a.z) + (x * a.x + y * a.y));
    }
    __forceinline void setCross(const Vec& a, const Vec& b) {
        const hkReal nx = a(1)*b(2) - a(2)*b(1);
        const hkReal ny = a(2)*b(0) - a(0)*b(2);
        const hkReal nz = a(0)*b(1) - a(1)*b(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline void setRotatedDir(const Quaternion& quat, const Vec& direction);
    __forceinline void setRotatedInverseDir(const Quaternion& quat, const Vec& direction);
};
struct Quaternion {
    Vec value;
    inline hkReal getReal() const { return value(3); }
    inline const Vec& getImag() const { return value; }
    inline void operator=(const Quaternion& q) { value = q.value; }
    inline void setInverse(const Quaternion& q) { value.setNeg3(q.getImag()); }
    inline void FUN_008d3290(const Quaternion& q0, const Quaternion& q1);
};
__forceinline void Vec::setRotatedDir(const Quaternion& quat, const Vec& direction) {
    hkReal qreal = quat.value(3);
    hkReal q2minus1 = qreal*qreal - 0.5f;

    Vec ret;
    ret.setMul4( q2minus1, direction );

    hkReal imagDotDir = quat.getImag().dot3( direction );
    ret.addMul4( imagDotDir, quat.getImag() );

    Vec imagCrossDir;
    imagCrossDir.setCross( quat.getImag(), direction );
    ret.addMul4( qreal, imagCrossDir );

    this->setAdd4( ret, ret );
}
__forceinline void Vec::setRotatedInverseDir(const Quaternion& quat, const Vec& direction) {
    hkReal qreal = quat.value(3);
    hkReal q2minus1 = qreal*qreal - 0.5f;

    Vec ret;
    ret.setMul4( q2minus1, direction );

    hkReal imagDotDir = quat.getImag().dot3( direction );
    ret.addMul4( imagDotDir, quat.getImag() );

    Vec imagCrossDir;
    imagCrossDir.setCross( direction, quat.getImag() );
    ret.addMul4( qreal, imagCrossDir );

    this->setAdd4( ret, ret );
}

inline void Quaternion::FUN_008d3290(const Quaternion& q0, const Quaternion& q1) {
    Vec vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.value.getSimdAt(3), q1.getImag());
    vec.addMul4(q1.value.getSimdAt(3), q0.getImag());
    hkReal real = q0.getReal() * q1.getReal() - q0.value.dot3(q1.value);
    value = vec;
    value(3) = real;
}
struct Transform {
    __forceinline Transform() { }

    __forceinline void setInverse( const Transform &t );
    __forceinline void setMul( const Transform &t1, const Transform &t2 );
    __forceinline void setMulInverseMul( const Transform& t1, const Transform &t2 );
    __forceinline void operator=(const Transform& other) { position = other.position; rotation = other.rotation; scale = other.scale; }
    Vec position;
    Quaternion rotation;
    Vec scale;
};
void Transform::setInverse( const Transform& t ) {
    position.setRotatedInverseDir(t.rotation, t.position);
    position.setNeg4(position);
    rotation.setInverse(t.rotation);

    Vec invScale; invScale.setReciprocal3( t.scale );
    scale.setXYZ0( invScale );
}
void Transform::setMul( const Transform& aTb, const Transform& bTc ) {
    Vec extraTrans;
    extraTrans.setRotatedDir(aTb.rotation, bTc.position);
    position.setAdd4(aTb.position, extraTrans);
    rotation.FUN_008d3290(aTb.rotation, bTc.rotation);
    scale.setMul4(aTb.scale, bTc.scale);
}
void Transform::setMulInverseMul( const Transform& a, const Transform &b ) {
    Transform h;
    h.setInverse( a );
    setMul(h, b);
}

template <typename T>
struct Array {
    inline T& operator[] (int i) { return m_data[i]; }
    inline const T& operator[] (int i) const { return m_data[i]; }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};
struct Skeleton {
    const char* name;
    hkInt16* parentIndices;
    int numParentIndices;
    void** bones;
    int numBones;
};
struct ByteBool {
    char value;
    inline ByteBool& operator=(bool flag) { value = static_cast<char>(flag); return *this; }
};
struct Pose {
    typedef hkUint32 PoseFlag;
    __forceinline const Transform& getBoneLocalSpace (int boneIdx) const;
    __forceinline const Transform& getBoneModelSpace (int boneIdx) const;
    enum PropagateOrNot { KeepChildrenModel, Propagate };
    __forceinline void makeFirstChildrenModelSpace(int boneIdx) const {
        const int numBones = skeleton->numBones;
        for (int i = boneIdx + 1; i < numBones; ++i) {
            if (skeleton->parentIndices[i] == boneIdx) {
                getBoneModelSpace(i);
                boneFlags[i] = F_BONE_LOCAL_DIRTY;
                localInSync = false;
            }
        }
    }
    __forceinline void setBoneModelSpace(int boneIdx, const Transform& boneModel, PropagateOrNot propagate);
    void FUN_00955070();
    Transform& FUN_00956b90(int,int);
    const Skeleton* skeleton;
    mutable Array<Transform> localPose;
    mutable Array<Transform> modelPose;
    mutable Array<PoseFlag> boneFlags;
    mutable ByteBool modelInSync;
    mutable ByteBool localInSync;
    enum { F_BONE_LOCAL_DIRTY = 0x1, F_BONE_MODEL_DIRTY = 0x2, F_BONE_INTERNAL_FLAG1 = 0x4 };
    __forceinline int isFlagOn (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline void setFlag (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline void clearFlag (int boneIdx, PoseFlag enumToCheck) const;
    __forceinline int isFlagOnExplicit (PoseFlag flag, PoseFlag enumToCheck) const;
    __forceinline void setFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const;
    __forceinline void clearFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const;
    __forceinline void makeAllChildrenLocalSpace (int boneIdx) const;
    const Transform& hkaPose_calculateBoneModelSpace(int) const;
};
int Pose::isFlagOn (int boneIdx, PoseFlag enumToCheck) const { return boneFlags[boneIdx] & enumToCheck; }
void Pose::setFlag (int boneIdx, PoseFlag enumToCheck) const { boneFlags[boneIdx] |= enumToCheck; }
void Pose::clearFlag (int boneIdx, PoseFlag enumToCheck) const { boneFlags[boneIdx] &= ~enumToCheck; }
int Pose::isFlagOnExplicit (PoseFlag flag, PoseFlag enumToCheck) const { return flag & enumToCheck; }
void Pose::setFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const { flag |= enumToCheck; }
void Pose::clearFlagExplicit (PoseFlag& flag, PoseFlag enumToCheck) const { flag &= ~enumToCheck; }
const Transform& Pose::getBoneModelSpace (int boneIdx) const {
    if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY)) {
        return modelPose[boneIdx];
    } else {
        return hkaPose_calculateBoneModelSpace(boneIdx);
    }
}
const Transform& Pose::getBoneLocalSpace (int boneIdx) const {
    if (! isFlagOn (boneIdx, F_BONE_LOCAL_DIRTY)) {
        return localPose[boneIdx];
    } else {
        const Transform& modelFromBone = modelPose[boneIdx];
        const hkInt16 parentIdx = skeleton->parentIndices[boneIdx];
        if (parentIdx != -1) {
            const Transform& modelFromParent = getBoneModelSpace(parentIdx);
            localPose[boneIdx].setMulInverseMul(modelFromParent, modelFromBone);
        } else {
            localPose[boneIdx] = modelFromBone;
        }
        clearFlag (boneIdx, F_BONE_LOCAL_DIRTY);
        return localPose[boneIdx];
    }
}
void Pose::makeAllChildrenLocalSpace(int boneIdx) const {
    const int numBones = skeleton->numBones;
    setFlag(boneIdx, F_BONE_INTERNAL_FLAG1);
    for (int i = boneIdx + 1; i < numBones; ++i) {
        const hkInt16 parentId = skeleton->parentIndices[i];
        if (isFlagOn(parentId, F_BONE_INTERNAL_FLAG1)) {
            getBoneLocalSpace( i );
            setFlag( i, F_BONE_INTERNAL_FLAG1);
            modelInSync = false;
        }
    }
    for (int i = boneIdx + 1; i < numBones; ++i) {
        PoseFlag f = boneFlags[i];
        if (isFlagOnExplicit( f, F_BONE_INTERNAL_FLAG1)) {
            setFlagExplicit( f, F_BONE_MODEL_DIRTY);
            clearFlagExplicit( f, F_BONE_INTERNAL_FLAG1);
            boneFlags[i] = f;
        }
    }
}

void Pose::setBoneModelSpace(int boneIdx, const Transform& boneModel, PropagateOrNot propagate) {
    if (!propagate)
        makeFirstChildrenModelSpace(boneIdx);
    else
        makeAllChildrenLocalSpace(boneIdx);
    modelPose[boneIdx] = boneModel;
    boneFlags[boneIdx] = F_BONE_LOCAL_DIRTY;
    localInSync = false;
}

struct bhkRagdollController {
    unsigned unk00, unk04, unk08, unk0c;
    Transform worldFromModel;
    unsigned unk40, unk44, unk48, unk4c, unk50;
    Pose* referencePose;
    unsigned unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84;
    Pose* pose;
    unsigned unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    unsigned unkb0, unkb4, unkb8, unkbc;
    Quaternion headRotationOffset;
    Vec currentTarget, eyeOffset;
    unsigned unkf0, unkf4, unkf8, unkfc;
    Vec eyeForward, parentForward;
    Quaternion eyeRotation;
    unsigned unk130;
    float pitchLimit, yawLimit;
    unsigned unk13c, unk140;
    short bone, parentBone;
    float maxAngle;
    unsigned unk14c;
    Vec headForward, headParentForward;
    Quaternion previousHeadRotation;
    bool limit, changed;
    unsigned short unk182;
    float deadHeading, deadPitch;
    unsigned unk18c;
    bool enabled;
    int forceChanged;
    unsigned unk198;
    float pitch, yaw;

    void FUN_008dfb90();
    bool FUN_008e0300(int boneSlot, const Transform& world);
    void FUN_008e3ab0(const Transform& arWorldFromModel);
};

void bhkRagdollController::FUN_008e3ab0(const Transform& arWorldFromModel) {
    FUN_008dfb90();
    if (changed || !enabled) {
        forceChanged = 1;
        FUN_008e0300(1, arWorldFromModel);
    }

    Transform& currHeadMS = pose->FUN_00956b90(bone, 1);
    currHeadMS.rotation.FUN_008d3290(currHeadMS.rotation, headRotationOffset);
    pose->setBoneModelSpace(bone, currHeadMS, Pose::Propagate);

    if (enabled) {
        Transform worldFromHead;
        worldFromHead.setMul(arWorldFromModel, pose->getBoneModelSpace(bone));
        changed = FUN_008e0300(0, worldFromHead) || forceChanged != 0;

        Vec rightHS, forwardHS, upHS;
        rightHS.set(1, 0, 0);
        forwardHS.set(0, 1, 0);
        upHS.set(0, 0, -1);
        Vec fwdEyeHS;
        fwdEyeHS.setRotatedDir(referencePose->getBoneModelSpace(1).rotation, forwardHS);
        float pitchValue = 1.5707963267948966f - acosf(fwdEyeHS.dot3fpu(upHS));
        pitch = pitchValue;
        yaw = 1.5707963267948966f - acosf(fwdEyeHS.dot3fpu(rightHS));
        if (fabsf(yaw) > yawLimit)
            changed = true;
        if (fabsf(pitchValue) > pitchLimit)
            changed = true;
        referencePose->FUN_00955070();
    }
}
} // namespace f3LookAt

}   // namespace f3m_008e3ab0
