#include "f3_common.h"
// src/staging/blk_00400000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void __cdecl FUN_004055d0(int, char);

extern "C" void __cdecl Init(int);
extern int DAT_01012258;

struct FUN_00405600_class
{
    void __thiscall Init(int);
    void* __thiscall FUN_00405600(int param_2);
};

// Calls Init with param_2, stores the address of DAT_01012258 into this, and returns this.
// @fnv 0x00405600
void* __thiscall FUN_00405600_class::FUN_00405600(int param_2)
{
    Init(param_2);
    *(int*)this = (int)&DAT_01012258;
    return this;
}

struct EffectSetting
{
    bool IsFlagSet(unsigned int);
    void* __thiscall FUN_00402a10(void*);
    void __thiscall FUN_00405e60(const void*);
    void* __thiscall FUN_00405e60(void*);
};

// @f3 0x00402af0 (community match, verified in this file)
// pdb: EffectItem::GetEffectName | EffectItem.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: NiTStringMap<class Setting *>::~NiTStringMap<class Setting *>)
void* __thiscall EffectSetting::FUN_00405e60(void* a0)
{
    EffectSetting* p = *(EffectSetting**)((char*)this + 0x14);
    volatile int unused = 0;
    p->FUN_00402a10(a0);
    return a0;
}


struct BSExtraData;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* FUN_00418200();
};
// @f3 0x00401b10 (community match, verified in this file)
struct Layout_BSExtraList
{
    BSExtraData* m_pExtra;
    unsigned short m_us4;
    unsigned short m_us6;
};
struct Global_01090a78
{
    void* FUN_0086ba60(void* p);
};
extern Global_01090a78 DAT_01090a78;
// pdb: TESRegionData::SetPriority | TESRegionData.obj | tesv_win, call_gap, low
BSExtraData* BaseExtraList::FUN_00418200()
{
    Layout_BSExtraList* self = (Layout_BSExtraList*)this;
    BSExtraData* p = self->m_pExtra;
    if (p)
        p = (BSExtraData*)DAT_01090a78.FUN_0086ba60(p);
    self->m_pExtra = 0;
    self->m_us6 = 0;
    self->m_us4 = 0;
    return p;
}


namespace fnv_0041af30 {
struct BaseExtraList
{
    void RemoveExtra(unsigned char);
};

}  // namespace fnv_0041af30

void __cdecl Deallocate(void*);

void __cdecl operator delete(void*);
void FUN_00405310();

namespace fnv_0040ecd0 {
struct BSExtraData
{
    virtual ~BSExtraData();
    void* __thiscall FUN_0040ecd0(unsigned int flags);
};
}  // namespace fnv_0040ecd0

extern int DAT_01012238;
struct FUN_004055d0 : public FUN_00405600_class
{
    FUN_004055d0(int, char);
};
// Calls the base constructor with a, installs the vtable from DAT_01012238, and stores b at offset 0x10.
// @fnv 0x004055d0
FUN_004055d0::FUN_004055d0(int a, char b)
{
    FUN_00405600(a);
    *(int**)this = &DAT_01012238;
    *(char*)((char*)this + 0x10) = b;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern "C" void* DAT_01012278;
struct FUN_00405630_s
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00405630_s* __thiscall Init(int count);
};
// Sets the vtable, stores count, allocates count*4 zeroed bytes into data and returns this.
// @fnv 0x00405630
FUN_00405630_s* __thiscall FUN_00405630_s::Init(int count)
{
    vtbl = &DAT_01012278;
    this->count = count;
    pad = 0;
    unsigned int size = this->count << 2;
    data = NiMalloc(size);
    memset(data, 0, this->count << 2);
    return this;
}

struct SL
{
    int m1;
    int m2;
    SL();
};

namespace fnv_00406db0 {
struct SL
{
    SL();
};
}  // namespace fnv_00406db0

struct Flt
{
    operator unsigned int();
};

struct TESSound;

struct RecursiveSpinLock
{
    unsigned int* pCount;
    unsigned int count;
    void __thiscall FUN_0040fba0();
};

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned char*, EndianSizeTag<10>);

namespace fnv_00411ea0 {
int DAT_01014458;
struct BSExtraData
{
    virtual ~BSExtraData();
};
}  // namespace fnv_00411ea0

extern int DAT_01012238;

struct FUN_00405310
{
    virtual ~FUN_00405310();
};

class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    void SetFormType(ENUM_FORM_ID eType);
};

template <> class BSSimpleList<TESForm*>
{
  public:
    TESForm* m_item;
    BSSimpleList<TESForm*>* m_pkNext;

    void FUN_004019f0();
};

template <class T> class SettingCollection
{
  public:
    virtual ~SettingCollection();
    char path[260];
    void* handle;
};
// Representative of the native case-insensitive setting pointer map.

namespace fnv_00405310 {
void __fastcall DeleteAllEntries(void* pkMap);

class FUN_00405370
{
  public:
    virtual ~FUN_00405370();
};

class FUN_00405310 : public FUN_00405370
{
  public:
    virtual ~FUN_00405310();
};

// Destructor that calls DeleteAllEntries with this.
// @fnv 0x00405310
FUN_00405310::~FUN_00405310()
{
    DeleteAllEntries(this);
}
}  // namespace fnv_00405310

template <class T> class PathingRef
{
  public:
    void Reset(void* p);
};

class TESFormV
{
  public:
    virtual ~TESFormV();
};
class TESObject : public TESFormV
{
};
class TESBoundObject : public TESObject
{
  public:
    int GetFormType() const;
};
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
