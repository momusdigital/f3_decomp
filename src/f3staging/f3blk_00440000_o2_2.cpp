#include <windows.h>
#include <stdio.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0044f140 (community match, verified in this file)
namespace f3m_0044f140 {
namespace ActorDefaults232 {
extern float DAT_00f4a194;
extern float DAT_00f4a1a0;
extern unsigned short DAT_00f4a1b8;
}
class FUN_0044f520 {
public:
    virtual __declspec(noinline) void FUN_0044f140();
    virtual void ClearData();
    virtual void CopyData(const void* other);
    unsigned int flags04;
    unsigned short value08, value0A, value0C, value0E, value10, value12;
    float value14;
    unsigned short value18, value1A;
    unsigned int value1C, value20, value24, value28, value2C, value30;
    FUN_0044f520();
};
// pdb: TESActorBaseData::InitializeDataComponent | TESActorBaseData.obj | fnv360_0822_retail, vtable, medium
void FUN_0044f520::FUN_0044f140() {
    flags04 = 0;
    value08 = static_cast<unsigned short>(ActorDefaults232::DAT_00f4a194);
    value0A = 0;
    value0C = 1;
    value0E = 0;
    value10 = 0;
    value12 = 100;
    value14 = ActorDefaults232::DAT_00f4a1a0;
    value18 = ActorDefaults232::DAT_00f4a1b8;
    value20 = 0;
    value1C = 0;
    value24 = 0;
    value1A = 0;
    value28 = 0;
}
FUN_0044f520::FUN_0044f520() : value2C(0), value30(0) {
    FUN_0044f140();
}
}   // namespace f3m_0044f140

// @f3 0x0045c010 (community match, verified in this file)
extern float DAT_00db38b8;
namespace f3m_0045c010 {


float __cdecl FUN_0045c010(int param_1) {
    if (param_1 != 0) {
        unsigned char index = *(unsigned char*)(param_1 + 4);
        int adjusted_param = param_1;
        switch (index) {
        case 0x2f:
            adjusted_param += 0x94;
            break;
        case 0x19:
        case 0x28:
            adjusted_param += 0x8c;
            break;
        case 0x1f:
        case 0x2e:
        case 0x32:
            adjusted_param += 0x7c;
            break;
        case 0x1b:
            adjusted_param += 0x74;
            break;
        case 0x18:
        case 0x1a:
            adjusted_param += 0x60;
            break;
        case 0x1d:
        case 0x1e:
            adjusted_param += 0x84;
            break;
        default:
            return DAT_00db38b8;
        }
        if (adjusted_param != 0) {
            return *(float*)(adjusted_param + 4);
        }
    }
    return DAT_00db38b8;
}
}   // namespace f3m_0045c010

// @f3 0x00447390 (community match, verified in this file)
namespace f3m_00447390 {



struct NameNode447390
{
    const char* name;
    NameNode447390* next;
};

struct FileSize447390
{
    unsigned int sizeLow;
    unsigned int sizeHigh;
};

struct SizeNode447390
{
    FileSize447390* size;
    SizeNode447390* next;
};

struct Owner447390
{
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC;
    int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0; int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C; int unk250; int unk254; int unk258; int unk25C;
    int unk260; int unk264; int unk268; int unk26C; int unk270; int unk274; int unk278; int unk27C;
    int unk280; int unk284; int unk288; int unk28C; int unk290; int unk294; int unk298; int unk29C;
    int unk2A0; int unk2A4; int unk2A8; int unk2AC; int unk2B0; int unk2B4; int unk2B8; int unk2BC;
    int unk2C0; int unk2C4; int unk2C8; int unk2CC; int unk2D0; int unk2D4; int unk2D8; int unk2DC;
    int unk2E0; int unk2E4; int unk2E8; int unk2EC; int unk2F0; int unk2F4; int unk2F8; int unk2FC;
    int unk300; int unk304; int unk308; int unk30C; int unk310; int unk314; int unk318; int unk31C;
    int unk320; int unk324; int unk328; int unk32C; int unk330; int unk334; int unk338; int unk33C;
    int unk340; int unk344; int unk348; int unk34C; int unk350; int unk354; int unk358; int unk35C;
    int unk360; int unk364; int unk368; int unk36C; int unk370; int unk374; int unk378; int unk37C;
    int unk380; int unk384; int unk388; int unk38C; int unk390; int unk394; int unk398; int unk39C;
    int unk3A0; int unk3A4; int unk3A8; int unk3AC; int unk3B0; int unk3B4; int unk3B8; int unk3BC;
    int unk3C0; int unk3C4; int unk3C8; int unk3CC; int unk3D0; int unk3D4; int unk3D8; int unk3DC;
    int unk3E0; int unk3E4; int unk3E8;
    NameNode447390 names3EC;
    SizeNode447390 sizes3F4;
    bool FUN_00447390();
};

// pdb: TESFile::MastersChanged | TESFile.obj | fnv360_0822_retail, call_gap, low
bool Owner447390::FUN_00447390()
{
    NameNode447390* name = &names3EC;
    SizeNode447390* sizeNode = &sizes3F4;
    bool changed = false;
    while (name && name->name && sizeNode && sizeNode->size)
    {
        char path[MAX_PATH];
        WIN32_FIND_DATAA data;
        sprintf_s(path, MAX_PATH, "%s", name->name);
        FileSize447390* size = sizeNode->size;
        HANDLE handle = FindFirstFileA(path, &data);
        if (handle != INVALID_HANDLE_VALUE)
        {
            FindClose(handle);
            if (data.nFileSizeLow != size->sizeLow || data.nFileSizeHigh != size->sizeHigh)
                changed = true;
        }
        else
        {
            if (size->sizeLow != 0 || size->sizeHigh != 0)
                changed = true;
        }
        name = name->next;
        sizeNode = sizeNode->next;
    }
    return changed;
}
}   // namespace f3m_00447390

// @f3 0x0045f320 (community match, verified in this file)
#include <windows.h>
namespace f3m_0045f320 {

class RefObject45f320 {
public:
    virtual ~RefObject45f320();
    virtual void DeleteThis();
    volatile long m_refCount;
    void IncRefCount() { InterlockedIncrement(&m_refCount); }
    void DecRefCount() {
        if (!InterlockedDecrement(&m_refCount))
            DeleteThis();
    }
};

template <class T> class NiPointer45f320
{
  public:
    T* m_pObject;
    NiPointer45f320(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer45f320()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct Arg45f320 {
    int unk00;
    int unk04;
    RefObject45f320* unk08;
    volatile long unk0C;
    volatile long unk10;
};

struct Lock45f320 {
    void Enter(Arg45f320** a);
};

class Owner45f320 {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100;
    Lock45f320 m_lock;  // at +0x104
    void FUN_0045f320(Arg45f320* a);
};

// pdb: Animation::QueueReplacementAnimation | Animation.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apKFModel
void Owner45f320::FUN_0045f320(Arg45f320* a)
{
    Arg45f320* arg = *(Arg45f320* volatile*)&a;
    NiPointer45f320<RefObject45f320> hold(arg->unk08);
    if (hold.m_pObject) {
        InterlockedIncrement(&arg->unk10);
        InterlockedIncrement(&arg->unk10);
        m_lock.Enter(&a);
        return;
    }
}
}   // namespace f3m_0045f320

// @f3 0x00442e50 (community match, verified in this file)
#include <windows.h>
namespace f3m_00442e50 {

struct Sub {
    virtual void vf00();
    virtual void vf04();
    unsigned int unk04;
};

struct Node {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    Sub sub;
};

struct Holder {
    Node* node;
    ~Holder() {
        if (node != 0) {
            Sub* s = &node->sub;
            if (TryEnterCriticalSection((LPCRITICAL_SECTION)&s->unk04) == 0) {
                s->vf04();
            }
        }
    }
};

unsigned int __stdcall FUN_0041a4b0(Node** out);

// pdb: NavMeshArray::AddNavMesh | TESDataHandler.obj | fnv360_0822_retail, call_seq + skyrim(call_gap), high
unsigned int __stdcall NavMeshArray_AddNavMesh(Holder h) {
    unsigned int r = FUN_0041a4b0(&h.node);
    return r;
}
}   // namespace f3m_00442e50

// @f3 0x00446ec0 (community match, verified in this file)
namespace f3m_00446ec0 {
namespace f3m_00446ec0 {
struct TESFile {
    char pad000[0x3fc];
    unsigned int masterCount;
    TESFile** masters;

    TESFile* FUN_00446ec0(unsigned int index);
};

// pdb: TESFile::GetIndexFile | TESFile.obj | fnv360_0822_retail, call_dedup, low
// pdb params: index
TESFile* TESFile::FUN_00446ec0(unsigned int index)
{
    if (index <= masterCount) {
        if (index == 0) return this;
        if (masters) return masters[index - 1];
    }
    return 0;
}
}
}   // namespace f3m_00446ec0
