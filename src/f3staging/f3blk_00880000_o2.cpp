// src/f3staging/f3blk_00880000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0089ae90 (community match, verified in this file)
struct Heap8 { void* FUN_0086b930(unsigned int); };
extern Heap8 DAT_01090a78;
extern unsigned char DAT_01400000;
struct Buffer8 {
    unsigned int unk00;
    void* unk04;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    unsigned int unk3c;
    Buffer8* FUN_00899f20();
};
struct Destination8 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned short index18, unk1a;
    Buffer8* buffer1c;
};
struct Owner8 { void FUN_0089e520(Buffer8*); void FUN_0089ae90(Destination8*); };
// pdb: NiDynamicGeometryGroup::AddObject | NiDynamicGeometryGroup.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkScreenTexture
void Owner8::FUN_0089ae90(Destination8* destination) {
    if (!destination->buffer1c) {
        Buffer8* ptr = (Buffer8*)DAT_01090a78.FUN_0086b930(0x54);
        Buffer8* buffer = ptr ? ptr->FUN_00899f20() : 0;
        buffer->unk3c = 4;
        destination->buffer1c = buffer;
        buffer->unk04 = &DAT_01400000;
        FUN_0089e520(buffer);
        destination->index18 = 0xffff;
    }
}

// @f3 0x00881db0 (community match, verified in this file)
extern unsigned char DAT_00e29b54;
namespace f3m_00881db0 {
void __cdecl FUN_0089ec10(void*, unsigned int);
void __cdecl FUN_0089e890(void*);
struct Part21 { void FUN_00bd12d0(); };
struct Item21 { unsigned int unk00,unk04,unk08,unk0c; Part21 part; };
struct Object21 { void FUN_00881750(); };
struct Owner21 {
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
    void* vtable450;
    Item21** items;
    unsigned short unk458, count;
    unsigned int unk45c;
    Object21* first;
    Object21* second;
    void FUN_00881db0();
};
// pdb: NiDX9AdapterDesc::~NiDX9AdapterDesc | NiDX9SystemDesc.obj | tesv_win, call_gap, low
void Owner21::FUN_00881db0() {
    for(unsigned int i=0; i<count; ++i) {
        Item21* item = items[i];
        if(item) {
            item->part.FUN_00bd12d0();
            FUN_0089ec10(item,0x1c);
        }
    }
    Object21* object = first;
    if(object) { object->FUN_00881750(); FUN_0089ec10(object,0x144); }
    object = second;
    if(object) { object->FUN_00881750(); FUN_0089ec10(object,0x144); }
    Item21** data = items;
    vtable450 = &DAT_00e29b54;
    FUN_0089e890(data);
}
}   // namespace f3m_00881db0

// @f3 0x0088ef50 (community match, verified in this file)
struct Dispatch22 {
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
    virtual void Set(unsigned int,int,int,int);
    virtual void unknown0c4();
    virtual void unknown0c8();
    virtual void unknown0cc();
    virtual void unknown0d0();
    virtual void unknown0d4();
    virtual void unknown0d8();
    virtual void Reset(unsigned int,int);
};
extern Dispatch22* DAT_01091a68;
extern unsigned int DAT_00f7661c;
extern unsigned int DAT_00f76624;
void __cdecl FUN_0088ef50(unsigned int start) {
    unsigned int i=start;
    if(i<DAT_00f7661c) {
        do {
            DAT_01091a68->Reset(i,0);
            DAT_01091a68->Set(i,1,1,0);
            DAT_01091a68->Set(i,4,1,0);
            DAT_01091a68->Set(i,0x18,0,0);
        } while(++i<DAT_00f7661c);
    }
    while(i<DAT_00f76624) { DAT_01091a68->Reset(i,0); ++i; }
}

// @f3 0x0088ba60 (community match, verified in this file)
struct CRITICAL_SECTION { unsigned int debug,lockCount,recursion,thread,semaphore,spin; };
extern void (__stdcall *DAT_00d9b09c)(CRITICAL_SECTION*);
extern void (__stdcall *DAT_00d9b0a0)(CRITICAL_SECTION*);
struct Data24 {
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
    virtual int IsStatic();
    virtual void unknown0a0();
    virtual Data24* GetA4();
    virtual void unknown0a8();
    virtual Data24* GetAC();
};
struct Object24 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Data24* data;
};
struct Render24 {
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
    CRITICAL_SECTION critical;
};
extern Render24* DAT_0108f048;
extern unsigned char DAT_0108f20c;
Object24* __cdecl FUN_00424d50(const void*,Object24*);
Data24* __cdecl FUN_0087bfe0(Object24*,void*);
struct Owner24 { unsigned int unk00,unk04,unk08; void* stream; bool FUN_0088ba60(Object24*,void*,void*); };
// pdb: NiXenonTextureManager::PrecacheTexture | NiXenonTextureManager.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: NiDX9Renderer::PrecacheTexture)
// pdb params: pkIm, bForceLoad, bLocked
bool Owner24::FUN_0088ba60(Object24* object, void* unused1, void* unused2) {
    if(!object) return false;
    Render24* renderer = *(Render24* volatile*)&DAT_0108f048;
    CRITICAL_SECTION* lock=&renderer->critical;
    DAT_00d9b09c(lock);
    Data24* data=object->data;
    if(!data) {
        Object24* found=FUN_00424d50(&DAT_0108f20c,object);
        if(found) data=FUN_0087bfe0(found,stream);
        else { DAT_00d9b0a0(lock); return false; }
    }
    DAT_00d9b0a0(lock);
    Data24* result=data->GetA4();
    if(!result) result=data->GetAC();
    if(result) { bool isStatic = result->IsStatic()!=0; return isStatic; }
    return true;
}

// @f3 0x0089aae0 (community match, verified in this file)
void __cdecl FUN_0089ec10(void*, unsigned int);
void __cdecl FUN_0089e890(void*);
void __cdecl operator delete(void*, unsigned int);
extern int DAT_00e2be70;
extern void* DAT_00e2be98;
extern void* DAT_00e2be78;
extern void* DAT_01091c98;
extern unsigned int DAT_00e2bf00;
extern unsigned int DAT_00e2bdb8;
extern unsigned int DAT_00e2bed8;
extern unsigned int DAT_00e2beb8;

struct ReleaseBuffer
{
    void** vtable;
};
typedef void(__stdcall* ReleaseFn)(ReleaseBuffer*);
struct DynamicSetData
{
    unsigned int unk00, unk04, capacity;
    ReleaseBuffer* buffer0c;
    ReleaseBuffer* buffer10;
    unsigned int offset;
    void Destroy()
    {
        ReleaseBuffer* a = buffer10;
        if (a)
            ((ReleaseFn)a->vtable[2])(a);
        ReleaseBuffer* b = buffer0c;
        if (b)
            ((ReleaseFn)b->vtable[2])(b);
    }
};
struct DynamicChipData
{
    static __forceinline void operator delete(void* p, unsigned int size) { ::operator delete(p, size); }
    ~DynamicChipData()
    {
        buffer = 0;
    }
    unsigned int index;
    DynamicSetData* set;
    ReleaseBuffer* buffer;
    unsigned int size, offset, stride, unk18, unk1c;
};
template <class T> struct MapEntryData
{
    MapEntryData* next;
    const char* key;
    T* value;
};
template <class T> struct DynamicMapData;
template <class T> struct MapVtableData
{
    void* slot0;
    unsigned int(__thiscall* hash)(DynamicMapData<T>*, const char*);
};
template <class T> struct DynamicMapData
{
    MapVtableData<T>* vtable;
    unsigned int size;
    MapEntryData<T>** table;
    unsigned int count;
    bool FUN_00899cf0(const char*);
    void FUN_006bd950();
    void Destroy(void* derivedVtable, void* baseVtable)
    {
        vtable = (MapVtableData<T>*)derivedVtable;
        FUN_006bd950();
        vtable = (MapVtableData<T>*)baseVtable;
        FUN_006bd950();
        FUN_0089e890(table);
    }
    void* GetFirst() const
    {
        for (unsigned int i = 0; i < size; ++i)
            if (table[i])
                return table[i];
        return 0;
    }
    void FUN_0089a5d0(void*& pos, const char*& key, T*& value)
    {
        MapEntryData<T>* item = (MapEntryData<T>*)pos;
        key = item->key;
        value = item->value;
        if (item->next)
        {
            pos = item->next;
        }
        else
        {
            unsigned int i = vtable->hash(this, item->key);
            for (++i; i < size; i++)
            {
                item = table[i];
                if (item)
                {
                    pos = item;
                    return;
                }
            }
            pos = 0;
        }
    }
};
template <class T> struct DynamicArrayData
{
    void* vtable;
    T** data;
    unsigned short capacity, size, count, grow;
    T* RemoveAt(unsigned int i)
    {
        if (i >= size)
            return 0;
        T* value = data[i];
        data[i] = 0;
        if (value)
            --count;
        if (i == (unsigned short)(size - 1))
            --size;
        return value;
    }
};
struct DynamicGroupData
{
    void* vtable;
    unsigned int refs;
    void* device;
    DynamicMapData<DynamicSetData> sets;
    DynamicMapData<DynamicChipData> chips;
    DynamicArrayData<DynamicSetData> streamSets;
    DynamicArrayData<DynamicChipData> streamChips;
    unsigned int nextIndex;
    void FUN_0089e500();
    void FUN_0089aae0();
};

// Iterates the set and chip maps and stream arrays, destroys entries, updates vtables, clears a matching global pointer, and calls FUN_0089e500.
// @fnv 0x00e95880
// pdb: NiDynamicGeometryGroup::~NiDynamicGeometryGroup | NiDynamicGeometryGroup.obj | fnv360_0822_retail, caller_sim, high
void DynamicGroupData::FUN_0089aae0()
{
    vtable = &DAT_00e2bf00;
    DynamicSetData* set;
    DynamicChipData* chip;
    void* setPos = sets.GetFirst();
    while (setPos)
    {
        const char* key;
        sets.FUN_0089a5d0(setPos, key, set);
        sets.FUN_00899cf0(key);
        if (set)
        {
            set->Destroy();
            operator delete(set, sizeof(DynamicSetData));
        }
    }
    void* chipPos = chips.GetFirst();
    while (chipPos)
    {
        const char* key;
        chips.FUN_0089a5d0(chipPos, key, chip);
        chips.FUN_00899cf0(key);
        chip->buffer = 0;
        delete chip;
    }
    for (unsigned int i = 0; i < streamSets.capacity; ++i)
    {
        set = streamSets.RemoveAt(i);
        if (set)
        {
            set->Destroy();
            operator delete(set, sizeof(DynamicSetData));
        }
        chip = streamChips.RemoveAt(i);
        chip->buffer = 0;
        delete chip;
    }
    if (this == (void*)DAT_01091c98)
        DAT_01091c98 = 0;
    streamChips.vtable = &DAT_00e2bdb8;
    FUN_0089e890(streamChips.data);
    streamSets.vtable = &DAT_00e2be70;
    FUN_0089e890(streamSets.data);
    chips.Destroy(&DAT_00e2bed8, &DAT_00e2beb8);
    sets.Destroy(&DAT_00e2be98, &DAT_00e2be78);
    FUN_0089e500();
}

// @f3 0x00880240 (community match, verified in this file)
namespace f3m_00880240 {
namespace fo3_00880240 {
void* __cdecl FUN_00c00610(void*,int,unsigned int);
struct FUN_00880240_Info {
    int eType;
    unsigned short usComps;
    unsigned short pad06;
    unsigned short usVerts;
    unsigned short pad0a;
    unsigned short* pusRemap;
    unsigned short* psSrc;
    unsigned int pad14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;
};

// @fnv 0x00e77eb0
// pdb: NiD3DShaderDeclaration::Pack_UnsignedShortToUnsignedByte | NiXenonShaderDeclaration.obj | fnv360_0822_retail, objrun_open, low
// pdb params: kParams
unsigned int FUN_00880240(FUN_00880240_Info* pkInfo)
{
    unsigned int uiSize = 0;
    unsigned short* psSrc = pkInfo->psSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;
    unsigned char* pucDest = pkInfo->pucDest;

    if (!psSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            FUN_00c00610(pucDest, 0, pkInfo->uiDestSize);
            pucDest += pkInfo->uiDestStride;
            uiSize += pkInfo->uiDestSize;
        }
        return uiSize;
    }

    unsigned short usCompCount = pkInfo->usComps - 16;
    unsigned short usComps = (usCompCount > 4) ? 4 : usCompCount;

    if (pusRemap)
    {
        unsigned short usIdx = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned short* psIn = (unsigned short*)((char*)psSrc + pusRemap[usIdx++] * pkInfo->uiSrcStride);
            unsigned char* pucOut = pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pucOut++ = (unsigned char)*psIn++;
            if (j < 4)
                FUN_00c00610(pucOut, 0, (unsigned short)(4 - j));
            uiSize += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned short* psIn = psSrc;
            unsigned char* pucOut = pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pucOut++ = (unsigned char)*psIn++;
            if (j < 4)
                FUN_00c00610(pucOut, 0, (unsigned short)(4 - j));
            uiSize += pkInfo->uiDestSize;
            psSrc = (unsigned short*)((char*)psSrc + pkInfo->uiSrcStride);
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiSize;
}

}
}   // namespace f3m_00880240

// @f3 0x00882800 (community match, verified in this file)
namespace f3m_00882800 {
namespace f3m_00882800 { extern int DAT_0109181c; }
// pdb: Menu::OnXMLDataChange | MenuManager.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: NiDX92DBufferData::GetRTTI)
// pdb params: aiTrait
int* __cdecl FUN_00882800() { return &f3m_00882800::DAT_0109181c; }
}   // namespace f3m_00882800

// @f3 0x00886790 (community match, verified in this file)
namespace f3m_00886790 {
struct O886790 { char pad[0x20]; unsigned char value; void FUN_00886790(unsigned char v); };
// pdb: NiD3DShader::SetUsesNiRenderState | NiXenonFragmentShader.obj | fnv360_0822_retail, objrun_sim, low, conflict (bridge: BSShader::SetCurrentPass)
// pdb params: bUses
void O886790::FUN_00886790(unsigned char v) { value = v; }
}   // namespace f3m_00886790

// @f3 0x0088ee40 (community match, verified in this file)
namespace f3m_0088ee40 {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct O {
    ~O();
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern O* DAT_01091a18;
}
// pdb: NiTArray<NiPointer<NiD3DTextureStage>,NiTNewInterface<NiPointer<NiD3DTextureStage> > >::`scalar deleting destructor' | NiD3DPass.obj | fnv360_0822_debug, objrun_open, low
void __cdecl FUN_0088ee40() { delete f3m_0088ee40::DAT_01091a18; }

// @f3 0x0089a050 (community match, verified in this file)
extern int DAT_00f777c0;
extern int DAT_00f777c4;
namespace f3m_0089a050 {
namespace n89a050 {
struct ArrBase {
    void** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    ArrBase(unsigned int maxSize = 0, unsigned int growBy = 1)
        {
        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
    }
    virtual ~ArrBase();
    void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};
struct PtrArray : ArrBase {
    PtrArray() {}
    virtual ~PtrArray();
};
struct FUN_0089a050 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    PtrArray arr;
    int unk2c;
    int unk30;
    FUN_0089a050();
};
// pdb: NiVBSet::NiVBSet | NiStaticGeometryGroup.obj | tesv_win, call_seq, medium
FUN_0089a050::FUN_0089a050()
{
    unk0c = DAT_00f777c0;
    unk04 = 0;
    unk08 = 0;
    unk00 = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    arr.RemoveAll();
    unk2c = 0;
    unk30 = DAT_00f777c4;
}
}
}   // namespace f3m_0089a050

// @f3 0x00899740 (community match, verified in this file)
namespace f3m_00899740 {
struct P899740 { char pad[8]; unsigned int f8; char pad2[8]; int f14; int f18; };
// pdb: NiVBSet::DetermineUsageAndPool | NiVBSet.obj | fnv360_0822_retail, callee_sim, low
// pdb params: pkSet
void __cdecl FUN_00899740(P899740* p) { p->f14 = 8; p->f18 = 1; if (p->f8 & 0x80000000) p->f14 = 0x18; }
}   // namespace f3m_00899740

// @f3 0x0089feb0 (community match, verified in this file)
namespace f3m_0089feb0 {
namespace f3m_0089feb0 { extern int (__stdcall* DAT_00d9b1b8)(void* h); }
struct O89feb0 { char pad[0x1c]; int f1c; char pad2[4]; void* h; int FUN_0089feb0(); };
// pdb: NiThread::SystemSuspend | NiThread_Xenon.obj | fnv360_0822_retail, call_seq, medium
int O89feb0::FUN_0089feb0() { if (!h) return -1; int r = f3m_0089feb0::DAT_00d9b1b8(h); if (r != -1) f1c = 1; return r; }
}   // namespace f3m_0089feb0

// @f3 0x00888e70 (community match, verified in this file)
namespace f3m_00888e70 {
namespace f3m_00888e70 { struct Heap { void FUN_0086ba60(void* p); }; extern Heap DAT_01090a78; struct O { ~O(); static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); } }; extern O* DAT_01091928; }
void __cdecl FUN_00888e70() { delete f3m_00888e70::DAT_01091928; f3m_00888e70::DAT_01091928 = 0; }
}   // namespace f3m_00888e70

// @f3 0x0088cf60 (community match, verified in this file)
extern const char* DAT_0109195c;
namespace f3m_0088cf60 {
namespace register_name_0088cf60 {
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
    void FUN_00862990(NameArray*);
    void FUN_0088cf60(NameArray*);
};
// pdb: NiXenonPersistentSrcTextureRendererData::GetViewerStrings | NiXenonPersistentSrcTextureRendererData.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_0088cf60(NameArray* names) {
    FUN_00862990(names);
    void* value=FUN_00847b50(DAT_0109195c);
    names->Append(value);
}
}

}   // namespace f3m_0088cf60

// @f3 0x008969d0 (community match, verified in this file)
#include <string.h>
namespace f3m_008969d0 {
namespace task0752 {
void __cdecl FUN_0089e890(void*);
void* __cdecl FUN_0089e810(unsigned int);
int __cdecl FUN_00c007fc(char*, unsigned int, const char*);
struct FUN_008969d0_shell { void* m_vtbl; unsigned int value04; unsigned int type08; unsigned int unk0c; char* m_pcName; void FUN_008969d0(const char*); };
// @fnv 0x00be0920
// pdb: NiD3DShaderProgram::SetShaderProgramName | NiD3DShaderProgramCreatorHLSL.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pszName
void FUN_008969d0_shell::FUN_008969d0(const char* pszName)
{
    if (!pszName || strcmp(pszName, "") == 0)
    {
        FUN_0089e890(m_pcName);
        m_pcName = 0;
    }
    else
    {
        unsigned int uiNewLen = strlen(pszName) + 1;

        if (m_pcName)
        {
            if (strlen(m_pcName) < uiNewLen)
            {
                FUN_0089e890(m_pcName);
                m_pcName = 0;
            }
        }

        if (!m_pcName)
            m_pcName = static_cast<char*>(FUN_0089e810(uiNewLen));

        FUN_00c007fc(m_pcName, uiNewLen, pszName);
    }
}

}
}   // namespace f3m_008969d0

// @f3 0x0089b8d0 (community match, verified in this file)
extern int DAT_00e2c070;
extern int DAT_00e2c050;
extern int DAT_00e2c030;
namespace f3m_0089b8d0 {
namespace task0836 {

void __cdecl FUN_0089e890(void* p);
void __fastcall FUN_006bd950(void* self);

struct FUN_00a2e460_node
{
    FUN_00a2e460_node* m_pkNext;
    void* m_pvVal;
};

struct FUN_00a2e460_cls
{
    int* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    FUN_00a2e460_node** m_ppkHashTable;
    unsigned int unk0c;
    unsigned char m_bOwnsNodes;
    void FUN_0089b8d0();
};

// Frees each stored value in the hash table when nodes are owned, then releases the table and resets the vtable pointers.
// @fnv 0x00a2e460
// pdb: NiTStringTemplateMap<NiTPointerMap<char const *,NiPointer<NiShaderLibrary> >,NiPointer<NiShaderLibrary> >::~NiTStringTemplateMap<NiTPointerMap<char const *,NiPointer<NiShaderLibrary> >,NiPointer<NiShaderLibrary> > | NiD3DShaderFactory.obj | fnv360_0721_beta, objrun_open, low
void FUN_00a2e460_cls::FUN_0089b8d0()
{
    m_ppVirtualMethodTable = &DAT_00e2c070;
    if (m_bOwnsNodes != 0)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            FUN_00a2e460_node* node = m_ppkHashTable[i];
            while (node != 0)
            {
                FUN_00a2e460_node* cur = node;
                void* val = cur->m_pvVal;
                node = cur->m_pkNext;
                FUN_0089e890(val);
            }
        }
    }
    m_ppVirtualMethodTable = &DAT_00e2c050;
    FUN_006bd950(this);
    m_ppVirtualMethodTable = &DAT_00e2c030;
    FUN_006bd950(this);
    FUN_0089e890(m_ppkHashTable);
}

}
}   // namespace f3m_0089b8d0

// @f3 0x00898080 (community match, verified in this file)
namespace f3m_00898080 {
namespace task0837 {
void FUN_0089e890(void*) throw();
struct Node { Node* next; void* value; };
struct MapBase {
    virtual ~MapBase() throw() { FUN_006bd950(); FUN_0089e890(buckets); }
    unsigned int hashSize;
    Node** buckets;
    unsigned int count;
    void FUN_006bd950() throw();
};
struct Map : MapBase {
    virtual ~Map() throw() { FUN_006bd950(); }
};
struct FUN_00898080 : Map {
    unsigned char owns;
    virtual ~FUN_00898080() throw();
};
FUN_00898080::~FUN_00898080() throw() {
    if(owns) {
        for(unsigned int i=0;i<hashSize;i++) {
            Node* node=buckets[i];
            while(node) {
                Node* cur=node;
                void* value=cur->value;
                node=cur->next;
                FUN_0089e890(value);
            }
        }
    }
}
}
}   // namespace f3m_00898080

// @f3 0x00899e20 (community match, verified in this file)
namespace f3m_00899e20 {
namespace Clear301{void __cdecl FUN_0089ec10(void*,unsigned int);struct Value301{
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
~Value301(){FUN_00899a00();}void FUN_00899a00();static void operator delete(void*p,unsigned int size){FUN_0089ec10(p,size);}};struct Node301{unsigned int unk00;};struct Map301{void*vtable;unsigned int size;Node301**buckets;__forceinline Node301* First(){for(unsigned int i=0;i<size;++i)if(buckets[i])return buckets[i];return 0;}void FUN_0089a5d0(Node301*&,unsigned int&,Value301* volatile&);void FUN_00899cf0(unsigned int);};struct Owner301{unsigned int unk00,unk04,unk08;Map301 map;void NiStaticGeometryGroup_Purge();};
// pdb: NiStaticGeometryGroup::Purge | NiStaticGeometryGroup.obj | fnv360_0822_retail, call_gap + skyrim(objrun_prop), high
void Owner301::NiStaticGeometryGroup_Purge(){Node301*position=map.First();while(position){unsigned int key;Value301* volatile value;map.FUN_0089a5d0(position,key,value);map.FUN_00899cf0(key);Value301*current=value;if(current){current->FUN_00899a00();FUN_0089ec10(current,sizeof(Value301));}}}
}
}   // namespace f3m_00899e20

// @f3 0x00886df0 (community match, verified in this file)
namespace f3m_00886df0 {
namespace task0931 {
struct FUN_00c22440
{
    FUN_00c22440();
    void* __thiscall FUN_00c22460(unsigned int a);
};

struct SubObj_e8db90
{
    virtual void unk00();
    FUN_00c22440 m_inner;
    SubObj_e8db90() : m_inner()
    {}
};

struct FUN_0088bb70
{
    FUN_0088bb70();
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};

struct FieldsMid_e8db90
{
    unsigned char m_24;
    unsigned char m_25;
    unsigned char m_26;
    unsigned char m_27;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    FieldsMid_e8db90()
    {
        m_24 = 0;
        m_25 = 0;
        m_28 = 0;
        m_2c = 0;
        m_30 = 0;
        m_34 = 0;
        m_38 = 0;
    }
};

struct FUN_00886df0 : FUN_0088bb70, FieldsMid_e8db90
{
    virtual void unk00();
    SubObj_e8db90 m_3c;
    FUN_00886df0(unsigned int a);
};

// @fnv 0x00e8db90
// pdb: NiXenonFragmentShader::NiXenonFragmentShader | NiXenonFragmentShader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkDesc
FUN_00886df0::FUN_00886df0(unsigned int a)
{
    m_3c.m_inner.FUN_00c22460(a);
}


}
}   // namespace f3m_00886df0

// @f3 0x008866f0 (community match, verified in this file)
namespace f3m_008866f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace task1092 {
struct Ref{virtual void slot0();virtual void Delete();volatile long refs;};struct Object{
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
Ref* ref;void FUN_008866f0(Ref*);};
void Object::FUN_008866f0(Ref* value){Ref* old=ref;if(old!=value){if(old && !InterlockedDecrement(&old->refs))old->Delete();ref=value;if(value)InterlockedIncrement(&value->refs);}}
}
}   // namespace f3m_008866f0

// @f3 0x0089ba60 (community match, verified in this file)
struct Class89ba60 {
    int unk00;
    const Class89ba60* parent;
    bool isSuperClass(const Class89ba60* other) const {
        const Class89ba60* c = other;
        while (c) {
            if (c == this) return true;
            c = c->parent;
        }
        return false;
    }
};

extern Class89ba60 DAT_01091954;

struct Obj89ba60 {
    virtual void vf00();
    virtual void vf04();
    virtual const Class89ba60* vf08();
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
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual bool vfe4();
};

bool __stdcall FUN_0089ba60(Obj89ba60* object) {
    if (object) {
        Obj89ba60* typed = DAT_01091954.isSuperClass(object->vf08()) ? object : 0;
        if (typed) return typed->vfe4();
    }
    return false;
}

// @f3 0x0088b900 (community match, verified in this file)
namespace f3m_0088b900 {

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct RendererBlob
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
};

struct RendererLock
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
};

class Renderer
{
public:
    RendererBlob m_b00, m_b20, m_b40, m_b60, m_b80, m_ba0, m_bc0, m_be0,
                 m_b100, m_b120, m_b140, m_b160;   // 0x000 .. 0x17f
    RendererLock m_kLock;                          // 0x180
    void Lock()   { EnterCriticalSection(&m_kLock); }
    void Unlock() { LeaveCriticalSection(&m_kLock); }
};

extern Renderer* DAT_0108f048;
extern int DAT_0108f20c;

void* __cdecl FUN_00424d50(void*, void*);
void* __cdecl FUN_0087bfe0(void*, void*);

class TexData;

typedef void* (__thiscall* TGetObjFn)(void*);
typedef void  (__thiscall* TUpdateFn)(void*);
typedef unsigned int (__thiscall* TGetLevelsFn)(void*);

class TexData
{
public:
    TGetObjFn* m_ppVtbl;              // 0x00
    int unk04;
    int unk08;
    unsigned int m_uiImageWidth;      // 0x0c
    unsigned int m_uiImageHeight;     // 0x10
};

class Texture
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
    TexData* m_pTextureRendererData;  // 0x24
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    unsigned char m_bIsStatic;        // 0x40
};

class FUN_0088b900_shell
{
public:
    int unk00;
    int unk04;
    int unk08;
    void* m_pOwnerShader;             // 0x0c
    void* FUN_0088b900(Texture* pkTexture, bool* pbChanged, bool* pbMipmap, bool* pbNonPow2);
};

inline bool IsPowerOfTwo(unsigned int x)
{
    if (x == 0)
        return false;
    return (x & (x - 1)) == 0;
}

void* FUN_0088b900_shell::FUN_0088b900(Texture* pkTexture, bool* pbChanged, bool* pbMipmap, bool* pbNonPow2)
{
    *pbChanged = false;
    *pbMipmap = false;
    *pbNonPow2 = false;
    if (!pkTexture)
        return 0;

    Renderer* pkR = DAT_0108f048;
    pkR->Lock();
    TexData* pkData = pkTexture->m_pTextureRendererData;
    if (!pkData)
    {
        void* pkSrc = FUN_00424d50(&DAT_0108f20c, pkTexture);
        if (pkSrc)
        {
            pkData = (TexData*)FUN_0087bfe0(pkSrc, m_pOwnerShader);
            *pbChanged = true;
        }
        else
        {
            pkR->Unlock();
            return 0;
        }
    }
    pkR->Unlock();

    *pbNonPow2 = (IsPowerOfTwo(pkData->m_uiImageWidth) && IsPowerOfTwo(pkData->m_uiImageHeight)) ? false : true;

    TexData* pkOther = (TexData*)((TGetObjFn)pkData->m_ppVtbl[0xa4 / 4])(pkData);
    if (!pkOther)
        pkOther = (TexData*)((TGetObjFn)pkData->m_ppVtbl[0xac / 4])(pkData);
    if (pkOther)
        return ((TGetObjFn)pkOther->m_ppVtbl[0x9c / 4])(pkOther);

    TexData* pkSource = (TexData*)((TGetObjFn)pkData->m_ppVtbl[0xa8 / 4])(pkData);
    if (pkSource)
    {
        if (!((TGetObjFn)pkData->m_ppVtbl[0x9c / 4])(pkData))
        {
            ((TUpdateFn)pkSource->m_ppVtbl[0xb4 / 4])(pkSource);
            *pbChanged = true;
        }
        else if (!pkTexture->m_bIsStatic)
        {
            ((TUpdateFn)pkSource->m_ppVtbl[0xb4 / 4])(pkSource);
        }
    }
    *pbMipmap = ((TGetLevelsFn)pkData->m_ppVtbl[0x98 / 4])(pkData) > 1;
    return ((TGetObjFn)pkData->m_ppVtbl[0x9c / 4])(pkData);
}
}   // namespace f3m_0088b900

// @f3 0x00886f30 (community match, verified in this file)
namespace f3m_00886f30 {
namespace shader_constant_map_ctor {
struct NiShaderConstantMapEntry;
template<class T> struct NiPointer { T* object; };
template<class T> struct NiTArray {
    virtual ~NiTArray() throw();
    T* data;unsigned short capacity,count,liveCount,growBy;
    __forceinline NiTArray() throw() : capacity(0),count(0),liveCount(0),growBy(1) { data=0; }
    void FUN_008a8a50() throw();
};
template<class T> struct NiTObjectArray : NiTArray<T> { __forceinline NiTObjectArray() throw() {} };
struct NiShaderConstantMap {
    virtual ~NiShaderConstantMap() throw();
    unsigned int referenceCount,unk08;
    NiShaderConstantMap(unsigned int) throw();
};
struct NiD3DShaderConstantMap : NiShaderConstantMap {
    NiTObjectArray<NiPointer<NiShaderConstantMapEntry> > first,second;
    bool modified;unsigned char unk2d;unsigned short unk2e;
    unsigned int unk30,unk34,unk38,unk3c,unk40;
    void FUN_00890b70(unsigned int) throw();
    NiD3DShaderConstantMap(unsigned int,unsigned int) throw();
};
// pdb: NiD3DShaderConstantMap::NiD3DShaderConstantMap | NiXenonFragmentShader.obj | fnv360_0822_retail, call_gap, low
// pdb params: pkRenderer, eType
NiD3DShaderConstantMap::NiD3DShaderConstantMap(unsigned int device,unsigned int type) throw() : NiShaderConstantMap(type),modified(true),unk30(0),unk34(0),unk38(0),unk3c(0),unk40(0) { FUN_00890b70(device);first.FUN_008a8a50(); }
}
}   // namespace f3m_00886f30

// @f3 0x00881070 (community match, verified in this file)
namespace f3m_00881070 {
void __cdecl FUN_0089ec10(void* memory, int size) throw();
void __cdecl FUN_0089e890(void* memory) throw();

struct Value881 {
    int unk00;
};

class MapBase881 {
public:
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
    void FUN_006bd950() throw();
    virtual ~MapBase881()
    {
        FUN_006bd950();
        FUN_0089e890(m_ppkHashTable);
    }
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    void FUN_0089a5d0(void** pos, unsigned int* key, Value881** value) throw();
};

class Map881 : public MapBase881 {
public:
    virtual ~Map881() { FUN_006bd950(); }
};

struct Owner881 {
    int unk00;
    int unk04;
    Map881 m_map;
    ~Owner881();
};

// pdb: NiDX9DeviceDesc::DisplayFormatInfo::~DisplayFormatInfo | NiDX9SystemDesc.obj | tesv_win, call_seq, medium
Owner881::~Owner881()
{
    void* pos = m_map.GetFirstPos();
    while (pos) {
        unsigned int key;
        Value881* value;
        m_map.FUN_0089a5d0(&pos, &key, &value);
        FUN_0089ec10(value, 0x48);
    }
}
}   // namespace f3m_00881070

// @f3 0x00888b40 (community match, verified in this file)
extern char DAT_00e2a648,DAT_00e2a640,DAT_00e2a65c;extern unsigned DAT_00f7661c;
namespace f3m_00888b40 {
namespace Construct273 {
void* FUN_00887780(unsigned);
struct Array {void* table;void* data;unsigned short capacity,count,used,grow;__forceinline Array(unsigned cap){table=&DAT_00e2a640;capacity=cap;grow=4;count=0;used=0;if((unsigned short)cap>0)data=FUN_00887780((unsigned short)cap);else data=0;}};
struct DerivedArray:Array {__forceinline DerivedArray(unsigned cap):Array(cap){table=&DAT_00e2a65c;}};
struct FUN_00888b40 {void* table;bool flag;int unk08,unk0c,unk10;int a,b,c;DerivedArray array;int d,e,f,g,h,i,j;bool flag4c;int k,l,m,n;bool flag60,flag61;int o;FUN_00888b40();};
// pdb: NiD3DPass::NiD3DPass | NiD3DPass.obj | fnv360_0721_beta, objrun_open, low, conflict (bridge: NiD3DPass::InitializePools)
FUN_00888b40::FUN_00888b40():table(&DAT_00e2a648),a(0),b(0),c(0),array(DAT_00f7661c),d(0),e(0),f(0),g(0),h(0),i(0),j(0),flag4c(false),k(0),l(0),m(0),n(0),flag60(false),flag61(false),o(0){flag=false;}

}




}   // namespace f3m_00888b40

// @f3 0x0089f040 (community match, verified in this file)
#include <string.h>
namespace f3m_0089f040 {
namespace Write439 {
unsigned FUN_00c06cf8(const void*,unsigned,unsigned,void*);
struct Buffer {
 int unk00,unk04,unk08,unk0c;
 unsigned capacity,unk14,position,unk1c;
 char* data;
 void* file;
 int unk28;
 bool writable;
 bool FUN_0089edd0();
 unsigned NiFile_FileWrite(const char*,unsigned);
};
// pdb: NiFile::FileWrite | NiFile_Xenon.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(objrun), high
unsigned Buffer::NiFile_FileWrite(const char* source,unsigned count) {
 if(writable) {
 unsigned done=0;
 unsigned available=capacity-position;
 if(count>available) {
  if(available>0) {
   memcpy(data+position,source,available);
   source+=available;
   count-=available;
   done=available;
   position=capacity;
  }
  if(!FUN_0089edd0()) return 0;
  if(count>=capacity) return done+FUN_00c06cf8(source,1,count,file);
 }
 memcpy(data+position,source,count);
 position+=count;
 return done+count;
 }
 return 0;
}
}

}   // namespace f3m_0089f040

// @f3 0x0089ef80 (community match, verified in this file)
#include <stdio.h>
#include <string.h>
namespace f3m_0089ef80 {
namespace Read398 {


struct Stream {
 int unk00,unk04,unk08,unk0c;
 unsigned int capacity,available,position,total;
 char* buffer; FILE* file; int unk28; bool enabled;
 void FUN_0089edd0();
 unsigned int FUN_0089ef80(char*,unsigned int);
};
// pdb: NiFile::Seek | NiFile_Xenon.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: NiFile::FileRead)
// pdb params: iOffset, iWhence
unsigned int Stream::FUN_0089ef80(char* dest,unsigned int size) {
 if(enabled) {

 unsigned int copied=0;
 unsigned int remaining=available-position;
 if(size>remaining) {
  if(remaining>0) {
   memcpy(dest,buffer+position,remaining);
   dest+=remaining;
   size-=remaining;
   copied=remaining;
  }
  FUN_0089edd0();
  if(size>capacity) {
   unsigned int read=fread(dest,1,size,file);
   total+=read;
   return copied+read;
  }
  char* p=buffer;
  unsigned int read=fread(p,1,capacity,file);
  total+=read;
  available=read;
  if(read<size) size=read;
 }
 memcpy(dest,buffer+position,size);
 position+=size;
 return copied+size;
 }
 return 0;
}
}





}   // namespace f3m_0089ef80

// @f3 0x0089de80 (community match, verified in this file)
namespace f3m_0089de80 {
bool __cdecl FUN_00897bf0(void* object);
struct QueryAdapterA73 {
    void FUN_0089de80();
};
// pdb: NiD3DVertexShader::RecreateRendererData | NiD3DVertexShader.obj | fnv360_0721_beta, objopen_prop, low
void QueryAdapterA73::FUN_0089de80() {
    FUN_00897bf0(this);
}
}   // namespace f3m_0089de80

// @f3 0x00888360 (community match, verified in this file)
extern int DAT_00f76620;
namespace f3m_00888360 {

// pdb: NiD3DPass::SetMaxSimultaneousTextures | NiD3DPass.obj | fnv360_0822_retail, objrun_open, low
// pdb params: uiMaxSimultaneousTextures
void FUN_00888360(int value)
{
    DAT_00f76620 = value;
}
}   // namespace f3m_00888360

// @f3 0x00888370 (community match, verified in this file)
extern unsigned int DAT_00f76624;
namespace f3m_00888370 {

// pdb: NiD3DPass::SetMaxSamplers | NiD3DPass.obj | fnv360_0822_retail, objrun_open, low
// pdb params: uiMaxSamplers
void FUN_00888370(unsigned int value)
{
    DAT_00f76624 = value;
}
}   // namespace f3m_00888370

// @f3 0x0089f9e0 (community match, verified in this file)
extern char DAT_00e2c578;
namespace f3m_0089f9e0 {

struct X0089f9e0
{
    void* vptr;
    void*& FUN_0089f9e0();
};

// pdb: BSNiAllocator::BSNiAllocator | BSNiAllocator.obj | fnv360_0822_retail, call_seq, high
void*& X0089f9e0::FUN_0089f9e0()
{
    return *(void**)this = &DAT_00e2c578;
}
}   // namespace f3m_0089f9e0

// @f3 0x00888350 (community match, verified in this file)
extern unsigned int DAT_00f7661c;
namespace f3m_00888350 {

// pdb: NiD3DPass::SetMaxTextureBlendStages | NiD3DPass.obj | fnv360_0822_retail, objrun_open, low
// pdb params: uiMaxTextureBlendStages
void FUN_00888350(unsigned int value)
{
    DAT_00f7661c = value;
}
}   // namespace f3m_00888350

// @f3 0x0088d410 (community match, verified in this file)
namespace f3m_0088d410 {
void FUN_00888bd0();
void FUN_0088fdf0();

void FUN_0088d410()
{
    FUN_00888bd0();
    FUN_0088fdf0();
}
}   // namespace f3m_0088d410

// @f3 0x0088d420 (community match, verified in this file)
namespace f3m_0088d420 {
void FUN_00888e70();
void FUN_0088fee0();

void FUN_0088d420()
{
    FUN_00888e70();
    FUN_0088fee0();
}
}   // namespace f3m_0088d420

// @f3 0x0089dff0 (community match, verified in this file)
namespace f3m_0089dff0 {
void FUN_00897ba0(void*);

struct Object89dff0
{
    void FUN_0089dff0();
};

// pdb: NiD3DPixelShader::RecreateRendererData | NiD3DPixelShader.obj | fnv360_0721_beta, objopen_prop, low, conflict (bridge: NiD3DVertexShader::RecreateRendererData)
void Object89dff0::FUN_0089dff0()
{
    FUN_00897ba0(this);
}
}   // namespace f3m_0089dff0

// @f3 0x00897ca0 (community match, verified in this file)
namespace f3m_00897ca0 {
namespace fn_00897ca0 {
struct ListNode {
    ListNode* m_next;
    ListNode* m_prev;
    void* m_value;
};
struct PointerList {
    int m_allocator;
    int m_count;
    ListNode* m_head;
    void* FUN_00897ca0(ListNode** pos);
};
// pdb: NiD3DShaderProgramFactory::GetFirstProgramDirectory | NiD3DShaderProgramFactory.obj | fnv360_1110_retail, objrun, medium
// pdb params: kIter
void* PointerList::FUN_00897ca0(ListNode** pos) {
    ListNode* node = m_head;
    *pos = node;
    if (node) {
        *pos = node->m_next;
        return node->m_value;
    }
    return 0;
}
}
}   // namespace f3m_00897ca0

// @f3 0x00897c30 (community match, verified in this file)
extern void* g_renderer_00897c30;
extern void* g_device_00897c30;
extern void* g_hwnd_00897c30;
namespace f3m_00897c30 {
namespace fn_00897c30 {
struct D3DDevice {
    virtual int __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct Renderer {
    int m_head[162];
    D3DDevice* m_device;
    int m_mid[395];
    void* m_hwnd;
};
// pdb: NiD3DShaderProgramFactory::SetD3DRenderer | NiD3DShaderProgramFactory.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkD3DRenderer
void __cdecl FUN_00897c30(Renderer* renderer) {
    g_renderer_00897c30 = renderer;
    if (renderer) {
        D3DDevice* dev = renderer->m_device;
        D3DDevice* old = (D3DDevice*)g_device_00897c30;
        if (old) {
            old->Release();
        }
        g_device_00897c30 = dev;
        if (dev) {
            dev->AddRef();
        }
        g_hwnd_00897c30 = ((Renderer*)g_renderer_00897c30)->m_hwnd;
    } else {
        D3DDevice* old = (D3DDevice*)g_device_00897c30;
        g_hwnd_00897c30 = 0;
        if (old) {
            old->Release();
        }
        g_device_00897c30 = 0;
    }
}
}
}   // namespace f3m_00897c30

// @f3 0x00894a80 (community match, verified in this file)
extern char DAT_01091ac0;
extern int DAT_01090998[];
namespace f3m_00894a80 {
namespace f3m_00894a80 {
struct Obj {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    int unk18;
};
struct Device {
    virtual void V00(); virtual void V04(); virtual void V08(); virtual void V0c(); virtual void V10(); virtual void V14(); virtual void V18(); virtual void V1c();
    virtual void V20(); virtual void V24(); virtual void V28(); virtual void V2c(); virtual void V30(); virtual void V34(); virtual void V38(); virtual void V3c();
    virtual void V40(); virtual void V44(); virtual void V48(); virtual void V4c(); virtual void V50(); virtual void V54(); virtual void V58(); virtual void V5c();
    virtual void V60(); virtual void V64(); virtual void V68(); virtual void V6c(); virtual void V70();
    virtual bool V74(Obj* obj, void* data, int flags);
};
int __cdecl FUN_008669a0(int a, int b, int c);
int __cdecl FUN_00866530(int a, unsigned int* b, int* c);
bool __cdecl FUN_00893d10(void* data, int offset, int a, int b, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10);
// pdb: NiD3DShaderConstantMap::SetObjectConstant | NiD3DShaderConstantMap.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkShaderProgram, pkEntry, pkGeometry, pkSkin, pkPartition, pkBuffData, pkState, pkEffects, kWorld, kWorldBound, uiPass
int __stdcall FUN_00894a80(Device* device, Obj* obj, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10)
{
    int result = 0;
    int u = obj->unk18;
    int t = DAT_01090998[obj->unk15];
    int r = FUN_008669a0(p7, t, u);
    int a = obj->unk10;
    unsigned int index;
    int other;
    if (!FUN_00866530(a, &index, &other))
        return 0x10;
    unsigned int half = index * 8;
    if (!FUN_00893d10(&DAT_01091ac0, half * 2, a, r, p2, p3, p4, p5, p6, p7, p8, p9, p10))
        result = 0x60;
    if (!device->V74(obj, &DAT_01091ac0, 0))
        result = 0x50;
    return result;
}
}
}   // namespace f3m_00894a80

// @f3 0x00884620 (community match, verified in this file)
namespace f3m_00884620 {
namespace f3m_00884620 {

enum ResourceType { Texture2D = 3, VolumeTexture = 4, CubeTexture = 5 };
enum { D3DFMT_A8P8 = 40, D3DFMT_P8 = 41 };

struct SurfaceDesc {
    unsigned int format, type, usage, pool;
    unsigned int multiSampleType, multiSampleQuality;
    unsigned int width, height;
};

struct VolumeDesc {
    unsigned int format, type, usage, pool;
    unsigned int width, height, depth;
};

struct BaseTex {
    virtual long __stdcall QueryInterface(const void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetDevice(void**);
    virtual long __stdcall SetPrivateData(const void*, const void*, unsigned int, unsigned int);
    virtual long __stdcall GetPrivateData(const void*, void*, unsigned int*);
    virtual long __stdcall FreePrivateData(const void*);
    virtual unsigned int __stdcall SetPriority(unsigned int);
    virtual unsigned int __stdcall GetPriority();
    virtual void __stdcall PreLoad();
    virtual ResourceType __stdcall GetType();
    virtual unsigned int __stdcall SetLOD(unsigned int);
    virtual unsigned int __stdcall GetLOD();
    virtual unsigned int __stdcall GetLevelCount();
    virtual long __stdcall SetAutoGenFilterType(unsigned int);
    virtual unsigned int __stdcall GetAutoGenFilterType();
    virtual void __stdcall GenerateMipSubLevels();
};

struct Tex2D : BaseTex { virtual long __stdcall GetLevelDesc(unsigned int, SurfaceDesc*); };
struct TexCube : BaseTex { virtual long __stdcall GetLevelDesc(unsigned int, SurfaceDesc*); };
struct TexVolume : BaseTex { virtual long __stdcall GetLevelDesc(unsigned int, VolumeDesc*); };

struct PixelComponent {
    unsigned int component, representation;
    unsigned char bits;
    bool isSigned;
};

struct PixelFormat {
    unsigned char flags, bitsPerPixel;
    unsigned short unknown02;
    unsigned int format, tiling, rendererHint, extraData;
    PixelComponent components[4];
};

void __cdecl FUN_008823b0(unsigned int format, PixelFormat* output);

struct TextureInfo {
    void* vtable;
    unsigned int refCount;
    void* owner;
    unsigned int width, height;
    PixelFormat pixelFormat;
    unsigned int unknown58, unknown5c, unknown60;
    BaseTex* texture;
    unsigned int levelCount;

    bool FUN_00884620(BaseTex* texture);
};

// pdb: NiDX9TextureData::InitializeFromD3DTexture | NiDX9TextureData.obj | tesv_win, caller_sim, low
bool TextureInfo::FUN_00884620(BaseTex* texture)
{
    levelCount = texture->GetLevelCount();
    ResourceType type = texture->GetType();
    if (type == Texture2D) {
        SurfaceDesc desc;
        if (static_cast<Tex2D*>(texture)->GetLevelDesc(0, &desc) < 0)
            return false;
        width = desc.width;
        height = desc.height;
        if (desc.format == D3DFMT_A8P8 || desc.format == D3DFMT_P8)
            return false;
        FUN_008823b0(desc.format, &pixelFormat);
    } else if (type == CubeTexture) {
        SurfaceDesc desc;
        if (static_cast<TexCube*>(texture)->GetLevelDesc(0, &desc) < 0)
            return false;
        width = desc.width;
        height = desc.height;
        if (desc.format == D3DFMT_A8P8 || desc.format == D3DFMT_P8)
            return false;
        FUN_008823b0(desc.format, &pixelFormat);
    } else if (type == VolumeTexture) {
        VolumeDesc desc;
        if (static_cast<TexVolume*>(texture)->GetLevelDesc(0, &desc) < 0)
            return false;
        width = desc.width;
        height = desc.height;
        if (desc.format == D3DFMT_A8P8 || desc.format == D3DFMT_P8)
            return false;
        FUN_008823b0(desc.format, &pixelFormat);
    }
    return true;
}

} // namespace f3m_00884620
}   // namespace f3m_00884620
