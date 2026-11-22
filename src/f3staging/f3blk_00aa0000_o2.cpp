#include <stdio.h>
// src/f3staging/f3blk_00aa0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00aa2480 (community match, verified in this file)
class FUN_00aaa070
{
public:
    virtual ~FUN_00aaa070();
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
    unsigned int flags;
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
    FUN_00aaa070();
};
struct EmptyTaskArray
{
    ~EmptyTaskArray();
    int* data;
    int size;
    int capacity;
    EmptyTaskArray(unsigned int initialCapacity = 0) : capacity(0)
    {
        data = 0;
        size = 0;
        if (initialCapacity)
        {
            data = new int[initialCapacity];
            capacity = initialCapacity;
        }
    }
};
class EmptyTaskMemberBase
{
public:
    virtual ~EmptyTaskMemberBase();
    int unk04; int unk08; int unk0C;
    EmptyTaskMemberBase() : unk04(0), unk08(0), unk0C(0) {}
};
class EmptyTaskMember : public EmptyTaskMemberBase
{
public:
    virtual ~EmptyTaskMember();
    EmptyTaskMember() {}
};
class FUN_00aa2480 : public FUN_00aaa070
{
public:
    EmptyTaskArray first;
    EmptyTaskArray second;
    int unkCC;
    EmptyTaskArray third;
    EmptyTaskMember member;
    FUN_00aa2480();
    virtual ~FUN_00aa2480();
};
// pdb: BSMultiBoundRoom::BSMultiBoundRoom | BSMultiBoundRoom.obj | fnv360_0822_retail, call_dedup, medium
FUN_00aa2480::FUN_00aa2480()
{
    flags |= 0x800;
    unkCC = 0;
}

// @f3 0x00aad9a0 (community match, verified in this file)
struct Vec3_ad9a {
    float x, y, z;
};
struct Sphere_ad9a {
    Vec3_ad9a center;
    float radius;
};
struct Shape_ad9a {
    int unk00; int unk04; int unk08;
    Vec3_ad9a center;
    float radius;
    float GetRadius() const { return radius; }
    void FUN_00aad9a0(Sphere_ad9a* out);
};
// pdb: BSMultiBoundSphere::GetNiBound | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aBound
void Shape_ad9a::FUN_00aad9a0(Sphere_ad9a* out)
{
    float r = GetRadius();
    out->center = center;
    out->radius = r;
}

// @f3 0x00aa5440 (community match, verified in this file)
#include <string.h>

struct FileHashAA5440
{
    unsigned int lo;
    unsigned int hi;
};

void BuildAssetPath(int src, char* dest, int size);
void HashPathAA5440(const char* path, FileHashAA5440* dirHash, FileHashAA5440* fileHash);
void* FindEntryAA5440(int archive, FileHashAA5440* dirHash, FileHashAA5440* fileHash, const char* path);

struct FileLookupAA5440
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24;
    const char* unk28;
    void* unk2C;
    void FUN_00aa5440(int archive);
};

// pdb: QueuedFileEntry::LookupFileEntry | QueuedFiles.obj | fnv360_0721_retail, call_seq, medium
// pdb params: aeArchiveTypeIndex
void FileLookupAA5440::FUN_00aa5440(int archive)
{
    if (unk28)
    {
        FileHashAA5440 dirHash;
        FileHashAA5440 fileHash;
        char path[260];
        if (archive == 0)
            BuildAssetPath((int)unk28, path, 260);
        else
            strcpy_s(path, 260, unk28);
        HashPathAA5440(path, &dirHash, &fileHash);
        unk2C = FindEntryAA5440(archive, &dirHash, &fileHash, path);
    }
}

// @f3 0x00ab5c60 (community match, verified in this file)
void FUN_00aba530();
void FUN_00ab0d80();
void FUN_00ab01f0();
void FUN_00ab7e40();
void FUN_00aba030();
void FUN_00ab7b90();
void FUN_00aa5f20();

extern bool g_initializedAL_ab5;

// pdb: BSMain::InitSDM | BSMain.obj | fnv360_0822_retail, call_gap, low
void FUN_00ab5c60()
{
    if (!g_initializedAL_ab5) {
        FUN_00aba530();
        FUN_00ab0d80();
        FUN_00ab01f0();
        FUN_00ab7e40();
        FUN_00aba030();
        FUN_00ab7b90();
        FUN_00aa5f20();
        g_initializedAL_ab5 = true;
    }
}

// @f3 0x00aa2ee0 (community match, verified in this file)
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::IsKeyGreaterOrEqual | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aKey1, aKey2
int __stdcall FUN_00aa2ee0(__int64 first, __int64 second) {
    return first >= second;
}

// @f3 0x00ab5ca0 (community match, verified in this file)
namespace State372 { extern unsigned char DAT_0116eb38; }
void __cdecl FUN_00aba5b0();
void __cdecl FUN_00ab0f20();
void __cdecl FUN_00ab0400();
void __cdecl FUN_00ab8440();
void __cdecl FUN_00aba1b0();
void __cdecl FUN_00ab7d10();
void __cdecl FUN_00aa6130();
// pdb: BSMain::KillSDM | BSMain.obj | fnv360_0822_retail, udata + bridge(call_gap_sim|udata), high
void __cdecl BSMain_KillSDM() {
    if (State372::DAT_0116eb38) {
        FUN_00aba5b0();
        FUN_00ab0f20();
        FUN_00ab0400();
        FUN_00ab8440();
        FUN_00aba1b0();
        FUN_00ab7d10();
        FUN_00aa6130();
        State372::DAT_0116eb38 = 0;
    }
}

// @f3 0x00ab8880 (community match, verified in this file)
struct Component394 {
    void FUN_00ab8130(unsigned int count);
    void FUN_00ab87c0(unsigned int index, unsigned int* value);
};
struct Target394 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    Component394 component;
};
struct Owner394 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int* values;
    unsigned short unk64;
    unsigned short count;
    void NiPSysVolumeEmitter_CopyMembers(Target394* target, unsigned int flags);
    void BSPSysArrayEmitter_CopyMembers(Target394* target, unsigned int flags);
};
// pdb: BSPSysArrayEmitter::CopyMembers | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap_sim) + skyrim(objopen_prop), high
void Owner394::BSPSysArrayEmitter_CopyMembers(Target394* target, unsigned int flags) {
    NiPSysVolumeEmitter_CopyMembers(target, flags);
    unsigned int remaining = count;
    if (remaining) {
        Component394& component = target->component;
        component.FUN_00ab8130(remaining);
        do {
            --remaining;
            component.FUN_00ab87c0(remaining, &values[remaining]);
        } while (remaining);
    }
}

// @f3 0x00aac320 (community match, verified in this file)
struct Triple418 { unsigned short first, second, third; };
struct Records418 { unsigned int unk00; Triple418* entries; };
struct Owner418 {
    unsigned int unk00, unk04;
    Records418* records;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    int count;
    bool FUN_00aac1f0(void* first, void* second, unsigned int a, unsigned int b, unsigned int c);
    bool FUN_00aac320(void* first, void* second);
};
// pdb: BSPolygon2D::IsPointInsidePoly | BSPolygon.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afPoint
bool Owner418::FUN_00aac320(void* first, void* second) {
    int total = count;
    int i = 0;
    if (total > 0) {
        Triple418* current = records->entries;
        do {
            if (FUN_00aac1f0(first, second, current->first, current->second, current->third))
                return true;
            ++i;
            ++current;
        } while (i < total);
    }
    return false;
}

// @f3 0x00aa9a50 (community match, verified in this file)
void* __cdecl FUN_0089eb90(unsigned int);
extern int DAT_00e89f04;
struct Node481 {
    void* table;
    unsigned int unk4,unk8,unkc,unk10,unk14,unk18,unk1c,unk20;
    unsigned int unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40;
    unsigned int unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60;
    unsigned int unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80;
    unsigned int unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0;
    unsigned int unka4,unka8;
    unsigned char flagAC,flagAD,flagAE,flagAF;
    static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); }
    void FUN_00ab5d60(); void BSRangeNode_SetCurrent(unsigned char);
    Node481() { FUN_00ab5d60();table=&DAT_00e89f04;flagAE=0;flagAF=0xff;flagAD=0;flagAC=1; }
};
struct Owner481 {
    unsigned int unk0,unk4,unk8,unkc,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    unsigned int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    unsigned int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    unsigned int unka0,unka4,unka8;
    unsigned char flagAC,flagAD,flagAE,flagAF;
    void FUN_00ab5d90(Node481*,void*);
    Node481* FUN_00aa9a50(void*);
};
// pdb: BSRangeNode::CreateClone | BSRangeNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
Node481* Owner481::FUN_00aa9a50(void* argument) {
    Node481* node=new Node481;
    FUN_00ab5d90(node,argument);
    node->flagAE=flagAE;node->flagAF=flagAF;
    node->BSRangeNode_SetCurrent(flagAD);
    return node;
}

// @f3 0x00aa0b30 (community match, verified in this file)
struct Words539 {int x,y,z;};
struct Other539 {virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1c();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2c();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3c();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4c();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5c();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6c();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7c();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8c();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9c();virtual void slota0();virtual void slota4();virtual void slota8();virtual void slotac();virtual void slotb0();virtual void slotb4();virtual void Set(void**);unsigned int unk04,unk08,unk0c,unk10,unk14;Words539 position;};
struct Owner539 {unsigned int unk00,unk04,unk08;void* handle;unsigned int unk10,unk14;Words539 position;void BSMultiBoundShape_CopyMembers(Other539*,int);void FUN_00aa0b30(Other539*,int);};
// pdb: BSMultiBoundAABB::CopyMembers | BSMultiBoundAABB.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pDest, arCloneData
void Owner539::FUN_00aa0b30(Other539* other,int argument) {BSMultiBoundShape_CopyMembers(other,argument);other->Set(&handle);other->position=position;}

// @f3 0x00aa6460 (community match, verified in this file)
namespace f3m_00aa6460 {
void FUN_008f24c0();
struct Target725 {
    virtual void slot00();
    virtual void slot04();
};
// pdb: BSTaskManagerThread::~BSTaskManagerThread | BSTaskManager.obj | tesv_win, objrun_open, low
int __stdcall FUN_00aa6460(Target725* target)
{
    FUN_008f24c0();
    target->slot04();
    return 0;
}
}   // namespace f3m_00aa6460

// @f3 0x00aa48b0 (community match, verified in this file)
namespace f3m_00aa48b0 {
struct Task_00aa48b0
{
    virtual ~Task_00aa48b0();
    virtual void slot04();
    virtual void slot08();
    int unk04;
    int unk08;
    int unk0C;
};

struct Class_00aa48b0
{
    void FUN_00424b70(Task_00aa48b0* task);
    void FUN_00aa48b0(Task_00aa48b0* task);
};

// pdb: BSTaskManager<__int64>::FinishTask | IOManager.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: IOManager::GetBucketForKey)
// pdb params: apTask
void Class_00aa48b0::FUN_00aa48b0(Task_00aa48b0* task)
{
    task->unk0C = 4;
    task->slot08();
    task->unk0C = 5;
    FUN_00424b70(task);
}
}   // namespace f3m_00aa48b0

// @f3 0x00ab4be0 (community match, verified in this file)
namespace f3m_00ab4be0 {
struct Reader5 { void FUN_00bea7b0(void* object, void** result); };
struct Handle5 { Reader5* reader; };
struct Owner5 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    void* ref5c;
    void FUN_00abbbd0(Handle5* handle);
    void FUN_00ab4be0(void* argument);
};
// pdb: BSPSysMultiTargetEmitterCtlr::ProcessClone | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCloning
void Owner5::FUN_00ab4be0(void* argument) {
    Handle5* handle = (Handle5*)*(void* volatile*)&argument;
    FUN_00abbbd0(handle);
    Reader5* reader = handle->reader;
    argument = 0;
    reader->FUN_00bea7b0(this, &argument);
    Owner5* result = (Owner5*)argument;
    handle->reader->FUN_00bea7b0(ref5c, &argument);
    result->ref5c = argument;
}
}   // namespace f3m_00ab4be0

// @f3 0x00aa6170 (community match, verified in this file)
extern const char* DAT_0116d6e4;
namespace f3m_00aa6170 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847b90(const char* label, bool value);

__forceinline char* FormatViewerFlag(const char* label, const bool& value)
{
    return FUN_00847b90(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class BSXFlags
{
public:
    void FUN_00863fe0(ViewerStrings* strings);
    void FUN_00aa6170(ViewerStrings* strings);

    void** table;
    unsigned int references;
    const char* name;
    unsigned int animated : 1;
    unsigned int havok : 1;
    unsigned int ragDoll : 1;
    unsigned int complex : 1;
    unsigned int addon : 1;
    unsigned int editorMarker : 1;
    unsigned int dynamic : 1;
    unsigned int articulated : 1;
    unsigned int iKTarget : 1;
};

// pdb: BSXFlags::GetViewerStrings | BSXFlags.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void BSXFlags::FUN_00aa6170(ViewerStrings* strings)
{
    FUN_00863fe0(strings);
    strings->Add(FUN_00847b50(DAT_0116d6e4));
    strings->Add(FormatViewerFlag("bAnimated", animated != 0));
    strings->Add(FormatViewerFlag("bHavok", havok != 0));
    strings->Add(FormatViewerFlag("bRagDoll", ragDoll != 0));
    strings->Add(FormatViewerFlag("bComplex", complex != 0));
    strings->Add(FormatViewerFlag("bAddon", addon != 0));
    strings->Add(FormatViewerFlag("bEditorMarker", editorMarker != 0));
    strings->Add(FormatViewerFlag("bDynamic", dynamic != 0));
    strings->Add(FormatViewerFlag("bArticulated", articulated != 0));
    strings->Add(FormatViewerFlag("bIKTarget", iKTarget != 0));
}

}   // namespace f3m_00aa6170

// @f3 0x00ab6840 (community match, verified in this file)
extern const char* DAT_0116eb4c;
namespace f3m_00ab6840 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847dd0(const char* label, float value);

__forceinline char* FormatViewerFloat(const char* label, const float& value)
{
    return FUN_00847dd0(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

struct ViewerColor
{
    char* FUN_0083f9c0(const char* label);
    float r, g, b, a;
};

class BSPSysSimpleColorModifier
{
public:
    void FUN_00ac60d0(ViewerStrings* strings);
    void FUN_00ab6840(ViewerStrings* strings);

    unsigned int fields00[6];
    ViewerColor firstColor, secondColor, thirdColor;
    float fadeIn, fadeOut;
    float firstEnd, secondStart, secondEnd, thirdStart;
};

// pdb: BSPSysSimpleColorModifier::GetViewerStrings | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void BSPSysSimpleColorModifier::FUN_00ab6840(ViewerStrings* strings)
{
    FUN_00ac60d0(strings);
    strings->Add(FUN_00847b50(DAT_0116eb4c));
    strings->Add(FormatViewerFloat("Color 1 End Pct", firstEnd * 100.0f));
    strings->Add(FormatViewerFloat("Color 2 Start Pct", secondStart * 100.0f));
    strings->Add(FormatViewerFloat("Color 2 End Pct", secondEnd * 100.0f));
    strings->Add(FormatViewerFloat("Color 3 Start Pct", thirdStart * 100.0f));
    strings->Add(FormatViewerFloat("Fade In Pct", fadeIn * 100.0f));
    strings->Add(FormatViewerFloat("Fade Out Pct", fadeOut * 100.0f));
    strings->Add(firstColor.FUN_0083f9c0("Color 1"));
    strings->Add(secondColor.FUN_0083f9c0("Color 2"));
    strings->Add(thirdColor.FUN_0083f9c0("Color 3"));
}
}   // namespace f3m_00ab6840

// @f3 0x00aa7740 (community match, verified in this file)
#include <string.h>
extern char* DAT_0106cb94;
namespace f3m_00aa7740 {
extern "C" __declspec(dllimport) unsigned int __stdcall GetPrivateProfileIntA(const char* app, const char* key, int def, const char* file);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPrivateProfileStringA(const char* app, const char* key, const char* def, char* out, unsigned int n, const char* file);

struct Setting;
unsigned int FUN_00a9d930(const char* name);
void INISettingCollection_MainKey(Setting* s, char* section);
void INISettingCollection_SubKey(Setting* s, char* key);
int FUN_00c04515(const char* buf, const char* fmt, ...);
int FUN_00403230(char* buf, unsigned int n, const char* fmt, ...);
void FUN_00401e50(char* dst, const char* src);
unsigned int FUN_0061dbb0(unsigned int a, unsigned int b, unsigned int c, unsigned int d);

struct Setting {
    int unk00;
    unsigned int unk04;
    const char* unk08;
    int* GetIntPtr();
    float* GetFloatPtr();
    char* GetBoolPtr();
    void SetString(const char* s);
};

struct Flags { bool pad0; bool pad1; bool result; bool opened; };

struct IniFile {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void Open(int a);
    virtual void Close();
    char szIniPath[0x104];
    int unk108;
    bool INISettingCollection_ReadSetting(Setting* s);
};

// pdb: INISettingCollection::ReadSetting | XINISetting_Xenon.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(ustr), high
bool IniFile::INISettingCollection_ReadSetting(Setting* s)
{
    Flags f;
    f.result = false;
    if (s->unk08) {
        f.opened = (unk108 == 0);
        if (f.opened)
            Open(1);
        if (unk108) {
            char section[0x40];
            char key[0x40];
            char buf[0x100];
            unsigned int v[4];
            unsigned int type = FUN_00a9d930(s->unk08);
            INISettingCollection_MainKey(s, section);
            INISettingCollection_SubKey(s, key);
            switch (type) {
            case 6: {
                char out[0x400];
                if (strcmp(section, "LANGUAGE") == 0) {
                    char tmp[0x400];
                    GetPrivateProfileStringA("General", "sLanguage", DAT_0106cb94, tmp, 0x100, szIniPath);
                    FUN_00401e50(section, tmp);
                }
                GetPrivateProfileStringA(section, key, (char*)s->unk04, out, 0x100, szIniPath);
                s->SetString(out);
                break;
            }
            case 1:
                *(unsigned char*)&s->unk04 = (unsigned char)GetPrivateProfileIntA(section, key, *s->GetIntPtr(), szIniPath);
                break;
            case 3:
                s->unk04 = GetPrivateProfileIntA(section, key, *s->GetIntPtr(), szIniPath);
                break;
            case 5: {
                char fbuf[0x100];
                FUN_00403230(fbuf, 0x100, "%f", (double)*s->GetFloatPtr());
                if (GetPrivateProfileStringA(section, key, fbuf, buf, 0x100, szIniPath))
                    f.result = FUN_00c04515(buf, "%f", &s->unk04) == 1;
                break;
            }
            case 7: {
                if (GetPrivateProfileStringA(section, key, "", buf, 0x100, szIniPath)) {
                    f.result = FUN_00c04515(buf, "%u,%u,%u", &v[1], &v[0], &v[2]) == 3;
                    s->unk04 = (v[1] << 24) | ((v[0] & 0xff) << 16) | ((v[2] & 0xff) << 8) | 0xff;
                }
                break;
            }
            case 8: {
                if (GetPrivateProfileStringA(section, key, "", buf, 0x100, szIniPath)) {
                    f.result = FUN_00c04515(buf, "%u,%u,%u,%u", &v[3], &v[0], &v[1], &v[2]) == 4;
                    s->unk04 = FUN_0061dbb0(v[3], v[0], v[1], v[2]);
                }
                break;
            }
            case 0: {
                int def = *s->GetBoolPtr() != 0;
                *(unsigned char*)&s->unk04 = GetPrivateProfileIntA(section, key, def, szIniPath) != 0;
                break;
            }
            default:
                s->unk04 = GetPrivateProfileIntA(section, key, s->unk04, szIniPath);
                break;
            }
        }
        if (f.opened)
            Close();
    }
    return f.result;
}
}   // namespace f3m_00aa7740

// @f3 0x00aa6940 (community match, verified in this file)
struct RtType { RtType* unk00; RtType* parent; };
struct Helper { void FUN_00bea7b0(int a, int* out); };
struct Self;
struct Item {
    virtual void v0(); virtual void v1();
    virtual RtType* GetType();
    virtual void v3(Self* s);
    virtual void v4(Self* s);
    virtual void v5(Self* s);
    virtual void v6(Self* s);
    virtual void v7(Self* s);
    virtual void v8(Self* s);
    virtual void v9(Self* s);
    virtual void v10(Self* s);
    virtual void v11(Self* s);
    virtual void v12(Self* s);
    virtual void v13(Self* s);
    virtual void v14(Self* s);
    virtual void v15(Self* s);
    virtual void v16(Self* s);
    virtual void v17(Self* s);
    virtual void v18(Self* s);
    virtual void v19(Self* s);
    virtual void v20(Self* s);
    virtual void v21(Self* s);
    virtual void v22(Self* s);
    virtual void v23(Self* s);
    virtual void v24(Self* s);
    virtual void v25(Self* s);
    virtual void v26(Self* s);
    virtual void v27(Self* s);
};
extern RtType DAT_0108ec84;
extern unsigned int DAT_00e89ca8;
extern unsigned int DAT_00e89ca0;
unsigned int FUN_0082a480(unsigned int* p);
static bool IsKind(Item* o)
{
    for (RtType* t = o->GetType(); t; t = t->parent)
        if (t == &DAT_0108ec84) return true;
    return false;
}
struct Self {
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
    virtual bool v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual bool v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
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
    Item** unk1F0;
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
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
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
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    Helper* unk5C4;
    void FUN_0082b4a0(); bool FUN_0082c870(); void FUN_0082b8d0(); void FUN_0082ab10(); void FUN_0082bd90(); bool FUN_0082cb10();
    bool BSStream_LoadStream();
};
// pdb: BSStream::LoadStream | BSStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
bool Self::BSStream_LoadStream()
{
    if (unk5C4 != 0) {
        if (!v13())
        return false;
    unk29C = 0; unk298 = 0; unk294 = 0;
    FUN_0082b4a0();
    unsigned int d = unkD8;
    bool b = d >= FUN_0082a480(&DAT_00e89ca8);
    if (b) {
        if (!FUN_0082c870())
            return false;
    }
    d = unkD8;
    if (d >= FUN_0082a480(&DAT_00e89ca0))
        FUN_0082b8d0();
    unsigned int n = unk1F4;
    for (; unk294 < n; unk294++) {
        if (unk28C == 2) return false;
        if (b) unk1F0[unk294]->v19(this);
        else if (!v20()) return false;
    }
    v18();
    for (; unk298 < n; unk298++) {
        if (unk28C == 2) return false;
        Item* o = unk1F0[unk298];
        if (o) {
            Item* c = IsKind(o) ? o : 0;
            int out;
            if (c) { Helper* h = unk5C4; int r = ((int*)c)[2];  out = 0;   if (h && r) {
                h->FUN_00bea7b0(r, &out);
                if (out) continue;
            } }
        }
        o->v20(this);
    }
    for (; unk29C < n; unk29C++) {
        if (unk28C == 2) return false;
        Item* o = unk1F0[unk29C];
        if (o) {
            Item* c = IsKind(o) ? o : 0;
            int out;
            if (c) { Helper* h = unk5C4; int r = ((int*)c)[2];  out = 0;   if (h && r) {
                h->FUN_00bea7b0(r, &out);
                if (out) continue;
            } }
        }
        o->v27(this);
    }
    FUN_0082ab10();
    FUN_0082bd90();
    return true;
    }
    return FUN_0082cb10();
}

// @f3 0x00aa0c60 (community match, verified in this file)
struct CornerVec {
    float x,y,z;
    CornerVec() {}
    CornerVec(float a,float b,float c):x(a),y(b),z(c) {}
    CornerVec operator*(float s) const { return CornerVec(x*s,y*s,z*s); }
    CornerVec operator+(const CornerVec& b) const { return CornerVec(x+b.x,y+b.y,z+b.z); }
    CornerVec operator-(const CornerVec& b) const { return CornerVec(x-b.x,y-b.y,z-b.z); }
};
extern CornerVec DAT_00f72598;
extern CornerVec DAT_00f725a4;
extern CornerVec DAT_00f725b0;
struct CornerBox {
    int unk00,unk04,unk08;
    CornerVec center;
    float ex,ey,ez;
    void BSMultiBoundAABB_GetVertices(CornerVec* out);
};
// pdb: BSMultiBoundAABB::GetVertices | BSMultiBoundAABB.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void CornerBox::BSMultiBoundAABB_GetVertices(CornerVec* out) {
    CornerVec a=DAT_00f72598*ex;
    CornerVec b=DAT_00f725a4*ey;
    CornerVec c=DAT_00f725b0*ez;
    out[0]=center+a+b+c;
    out[1]=center+a+b-c;
    out[2]=center+a-b+c;
    out[3]=center+a-b-c;
    out[4]=center-a+b+c;
    out[5]=center-a+b-c;
    out[6]=center-a-b+c;
    out[7]=center-a-b-c;
}

// @f3 0x00ab5200 (community match, verified in this file)
#include <float.h>
#include <math.h>
extern const float DAT_00db7260;
extern const double DAT_00db7268;
namespace f3m_00ab5200 {

namespace SequenceAdvance {


struct Track {
    unsigned char unknown00[0xb8];
    unsigned short keyCount;
};

struct LinkedSequence {
    unsigned char unknown00[0xd4];
    float callbackTime;
};

class Callback {
public:
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
    virtual bool UpdateTime(float weight, LinkedSequence* sequence, float* time);
};

struct Sequence {
    unsigned char unknown00[8];
    unsigned short flags;
    unsigned short unknown0a;
    float speed;
    float startOffset;
    unsigned int unknown14;
    float duration;
    float origin;
    float lastTime;
    float accumulatedTime;
    float phase;
    LinkedSequence* linked;
    unsigned char unknown30[0xc];
    void* events;
    unsigned char unknown40[8];
    float previousPhase;
    unsigned char unknown4c[0x10];
    Track* track;

    Callback* NiPSysEmitterCtlr_GetBirthRateInterpolator();
    void FUN_00ab4d70(float callbackTime, float end, float begin, float weight,
                      float duration, float interval);
    void FUN_00ab5200(const float* time);
};

// pdb: BSPSysMultiTargetEmitterCtlr::Update | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable, medium
// pdb params: UpdateData
void Sequence::FUN_00ab5200(const float* time)
{
    if (track->keyCount == 0) {
        lastTime = *time;
        return;
    }

    if (lastTime > *time)
        previousPhase = DAT_00db7260;
    if (!linked || !events)
        return;
    const unsigned short playback = flags;
    if (!(static_cast<unsigned char>(playback >> 3) & 1))
        return;
    if (lastTime == *time && !(static_cast<unsigned char>(playback >> 7) & 1))
        return;

    const double timeOrigin = origin;
    const double invalid = -static_cast<double>(FLT_MAX);
    if (timeOrigin == invalid)
        origin = *time;
    float delta = lastTime == invalid ? 0.0f : *time - lastTime;
    const float next = speed * delta + accumulatedTime;
    accumulatedTime = next;
    const float unwrapped = next + startOffset;
    phase = unwrapped;
    lastTime = *time;

    const float length = duration;
    if (length != 0.0f) {
        const float wrapped = static_cast<float>(fmod(unwrapped, length));
        phase = wrapped;
        if (wrapped < 0.0f)
            phase = wrapped + length;
    } else {
        phase = 0.0f;
    }

    if (previousPhase == DAT_00db7268) {
        if (phase > 0.0f) {
            previousPhase = 0.0f;
        } else {
            previousPhase = phase;
            return;
        }
    }

    Callback* callback = NiPSysEmitterCtlr_GetBirthRateInterpolator();
    LinkedSequence* sequence = linked;
    const float callbackTime = sequence->callbackTime;
    float callbackInterval;
    bool wrapped = false;
    float interval;
    if (phase > previousPhase) {
        interval = phase - previousPhase;
    } else {
        interval = duration - previousPhase + phase;
        wrapped = true;
    }
    if (callback && callback->UpdateTime(0.0f, sequence, &callbackInterval)) {
        const float end = wrapped ? duration : phase;
        FUN_00ab4d70(interval + callbackTime, end, previousPhase, 0.0f, duration, callbackInterval);
    }
    previousPhase = phase;
}

}
}   // namespace f3m_00ab5200

// @f3 0x00aa87c0 (community match, verified in this file)
#include <math.h>
extern float FUN_00db954c;
namespace f3m_00aa87c0 {

struct Vec3AA { float x,y,z; };

struct TriAA { Vec3AA a,b,c,d; };
struct TripleAA { int kind, index, extra; };

struct RecordAA { int value[25]; };

struct SourceAA {

    void BSOcclusionPlane_GetVertices(TriAA* out);

    void FUN_00a9e0b0(TripleAA v, RecordAA* rec);

};

struct PlaneAA { float x,y,z,d; void FUN_00832fb0(Vec3AA* a, Vec3AA* b, Vec3AA* c); };

struct BufferAA {

    int unk00;

    int unk04;

    RecordAA* records;

    int unk0c;

    int recordCapacity;

    int unk14;

    TripleAA* items;

    int unk1c;

    int itemCapacity;

    int recordCount;

    int itemCount;

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

    Vec3AA direction;

    void FUN_00aa87c0(SourceAA* src, float threshold);

};

struct GrowListAA {void FUN_005bb760(int count,int grow);void FUN_00aa8350(int count,int grow);};


// pdb: BSCompoundFrustum::AddPortal | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apPortal, abFinalRoom
void BufferAA::FUN_00aa87c0(SourceAA* src,float threshold)
{
    if (itemCount + 2 >= itemCapacity)
        ((GrowListAA*)((char*)this+0x14))->FUN_005bb760(itemCapacity+10,1);
    if (recordCount+1 >= recordCapacity)
        ((GrowListAA*)((char*)this+4))->FUN_00aa8350(recordCapacity+4,1);

    TriAA tri;
    PlaneAA plane;
    src->BSOcclusionPlane_GetVertices(&tri);
    plane.FUN_00832fb0(&tri.a,&tri.b,&tri.c);
    items[itemCount].kind = 7;
    ++itemCount;
    items[itemCount].kind = recordCount;
        ++itemCount;
    TripleAA params = *reinterpret_cast<TripleAA*>(&direction);
    src->FUN_00a9e0b0(params,&records[recordCount]);
    float distance=direction.y*plane.y+direction.x*plane.x+direction.z*plane.z;
    distance = distance - plane.d;
    distance = fabs(distance);
    if (distance > 5.0f)
        records[recordCount].value[24]=0x3f;
    else
        records[recordCount].value[24]=0;
    ++recordCount;
}
}   // namespace f3m_00aa87c0

// @f3 0x00aac380 (community match, verified in this file)
extern "C" char DAT_01090a78;
namespace f3m_00aac380 {
// Reconstruction of 0x00c4e1e0
typedef unsigned int size_t;
extern "C" void* memmove(void*, const void*, size_t);
void* __cdecl NiMalloc(unsigned int);

struct MMgr
{
    void* __thiscall FUN_0086b930(unsigned int);
};
inline void* NiAlloc(unsigned int n)
{
    return ((MMgr*)&DAT_01090a78)->FUN_0086b930(n);
}

class NiPoint3
{
public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    __forceinline static void* operator new[](size_t n)
    {
        return NiAlloc(n);
    }
    static void operator delete[](void*)
    {}
};
class NiPoint2
{
public:
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float a, float b)
    {
        x = a;
        y = b;
    }
    __forceinline static void* operator new[](size_t n)
    {
        return NiAlloc(n);
    }
    static void operator delete[](void*)
    {}
};
class RgbaColor
{
public:
    float r, g, b, a;
    RgbaColor() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
    RgbaColor(float q, float w, float e, float t)
    {
        r = q;
        g = w;
        b = e;
        a = t;
    }
    __forceinline static void* operator new[](size_t n)
    {
        return NiAlloc(n);
    }
    static void operator delete[](void*)
    {}
};

inline NiPoint3* At3(NiPoint3* p, int i)
{
    return p + i;
}
inline unsigned short* At2(unsigned short* p, int i)
{
    return p + i;
}
inline void CopyMem(void* dest, const void* src, unsigned int size)
{
    memmove(dest, src, size);
}

struct P3Arr
{
    int unk0;
    NiPoint3* p;
};
struct ShArr
{
    int unk0;
    unsigned short* p;
};

enum NiGeometryData__DataFlags { NoDataFlags = 0 };
struct NiMemObject
{
    static void* operator new(unsigned int n);
    static void operator delete(void*, unsigned int);
};
struct NiTriShapeData : NiMemObject
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
    NiTriShapeData(unsigned short a1, NiPoint3* a2, NiPoint3* a3, RgbaColor* a4, NiPoint2* a5, unsigned short a6, NiGeometryData__DataFlags a7, unsigned short a8,
                            unsigned short* a9);
};

struct C4E1E0
{
    P3Arr* m0;
    int m4;
    ShArr* m8;
    NiPoint3* m0c;
    unsigned char* m10;
    NiPoint3* m14;
    NiPoint2* m18;
    RgbaColor* m1c;
    int m20;
    int m24;
    int m28;
    NiTriShapeData* FUN_00aac380();
};

// @fnv 0x00c4e1e0
// pdb: BSPolygon2D::CreateTriData | BSPolygon.obj | fnv360_0822_retail, objrun, medium
NiTriShapeData* C4E1E0::FUN_00aac380()
{
    m0c = new NiPoint3[m24];
    m14 = new NiPoint3[m24];
    m18 = new NiPoint2[m24];
    m1c = new RgbaColor[m24];
    m10 = (unsigned char*)NiMalloc(m28 * 3 * 2);
    CopyMem(m0c, At3(m0->p, 0), m24 * 12);
    CopyMem(m10, At2(m8->p, 0), m28 * 6);
    for (int i = 0; i < m24; i++)
    {
        m14[i] = NiPoint3(0.0f, 0.0f, 1.0f);
    }
    float fDiv = 100.0f;
    for (int j = 0; j < m24; j++)
    {
        m18[j] = NiPoint2(m0c[j].x / fDiv, m0c[j].y / fDiv);
    }
    for (int k = 0; k < m24; k++)
    {
        m1c[k] = RgbaColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
    NiTriShapeData* pCtrl =
        new NiTriShapeData((unsigned short)m24, m0c, m14, m1c, m18, 1, NoDataFlags, (unsigned short)m28, (unsigned short*)m10);
    return pCtrl;
}

}   // namespace f3m_00aac380

// @f3 0x00aa04a0 (community match, verified in this file)
namespace BoxGeometry {

struct Point3
{

    float x, y, z;

    __forceinline Point3()
    {}

    Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Point3 operator-(const Point3& p) const
    {
        return Point3(x - p.x, y - p.y, z - p.z);
    }
    Point3 operator+(const Point3&) const;
    Point3 operator*(float) const;
};

struct Color
{
    float r, g, b, a;
};

extern Color DAT_00f73220;
extern Point3 DAT_011a946c, DAT_011a9478, DAT_011a9484;

struct GeometryData
{

    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    Point3* vertices;

    unsigned int unk24;

    Color* colors;

    unsigned int unk2c, unk30, unk34, unk38, unk3c;

    bool* flags;

    unsigned short* FUN_006a05c0();

    __forceinline Point3* GetVertices()
    {
        Point3* result = vertices;
        return result;
    }

    __forceinline Color* GetColors()
    {
        Color* result = colors;
        return result;
    }

    __forceinline bool* GetFlags()
    {
        bool* result = flags;
        return result;
    }
};

struct Geometry
{

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

    Point3 position;

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

    GeometryData* data;

    __forceinline GeometryData* GetData()
    {
        return data;
    }
};

struct Bound
{

    unsigned int unk00, unk04, unk08;

    Point3 center;

    float extentX, extentY, extentZ;
    // pdb: BSMultiBoundOBB::GetVertices | BSMultiBoundOBB.obj | fnv360_0822_retail, call_seq + bridge(call_gap|caller), high
    void BSMultiBoundOBB_GetVertices(Point3* out)
    {
        Point3 axisX = DAT_011a946c * extentX;
        Point3 axisY = DAT_011a9478 * extentY;
        Point3 axisZ = DAT_011a9484 * extentZ;
        out[0] = center + axisX + axisY + axisZ;
        out[1] = center + axisX + axisY - axisZ;
        out[2] = center + axisX - axisY + axisZ;
        out[3] = center + axisX - axisY - axisZ;
        out[4] = center - axisX + axisY + axisZ;
        out[5] = center - axisX + axisY - axisZ;
        out[6] = center - axisX - axisY + axisZ;
        out[7] = center - axisX - axisY - axisZ;
    }

    void FUN_00aa04a0(Geometry*, Geometry*, Color);
};

// @fnv 0x00c38b00
// pdb: BSMultiBoundOBB::MakeDebugGeom | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: apLines, apShape, akBaseColor
void Bound::FUN_00aa04a0(Geometry* lines, Geometry* triangles, Color color)
{

    Point3 corners[8];

    BSMultiBoundOBB_GetVertices(corners);

    unsigned short edgesA[12][2] = {{0, 1}, {0, 2}, {1, 3}, {3, 2}, {4, 5}, {4, 6},
                                    {5, 7}, {7, 6}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

    unsigned short faces[12][3] = {{2, 3, 1}, {2, 1, 0}, {5, 7, 6}, {5, 6, 4}, {7, 2, 6}, {7, 3, 2},
                                   {4, 0, 5}, {5, 0, 1}, {6, 0, 4}, {6, 2, 0}, {3, 7, 1}, {7, 5, 1}};

    Color faceColor9 = color;

    Color edgeColor = DAT_00f73220;

    Point3* vertices9 = lines->GetData()->GetVertices();

    Color* colors8 = lines->GetData()->GetColors();

    bool* lineFlags9 = lines->GetData()->GetFlags();

    lines->position = center;

    for (int edge = 0; edge < 12; ++edge)
    {

        vertices9[2 * edge] = corners[edgesA[edge][0]] - center;

        colors8[2 * edge] = edgeColor;

        vertices9[2 * edge + 1] = corners[edgesA[edge][1]] - center;

        colors8[2 * edge + 1] = edgeColor;

        lineFlags9[2 * edge] = true;

        lineFlags9[2 * edge + 1] = false;
    }

    vertices9 = triangles->GetData()->GetVertices();

    colors8 = triangles->GetData()->GetColors();

    unsigned short* indices = triangles->GetData()->FUN_006a05c0();

    triangles->position = center;

    for (unsigned short triangle3 = 0; triangle3 < 12; ++triangle3)
    {

        vertices9[3 * triangle3] = corners[faces[triangle3][0]] - center;

        colors8[3 * triangle3] = faceColor9;

        vertices9[3 * triangle3 + 1] = corners[faces[triangle3][1]] - center;

        colors8[3 * triangle3 + 1] = faceColor9;

        vertices9[3 * triangle3 + 2] = corners[faces[triangle3][2]] - center;

        colors8[3 * triangle3 + 2] = faceColor9;

        indices[3 * triangle3] = 3 * triangle3;

        indices[3 * triangle3 + 1] = 3 * triangle3 + 1;

        indices[3 * triangle3 + 2] = 3 * triangle3 + 2;
    }
}

}

// @f3 0x00aa8910 (community match, verified in this file)
namespace f3m_00aa8910 {
struct FNV_Local
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
    void FUN_0045c620();
};
struct Elem0C
{
    int a;
    int b;
    int c;
};
// Geometry command emission for a polygon and its adjoining polygon.
struct GeometryPoint
{
    float x, y, z;
    GeometryPoint()
    {}
};
struct FUN_00a699d0
{
    GeometryPoint normal;
    float distance;
    FUN_00a699d0();
    FUN_00a699d0(const GeometryPoint*, const GeometryPoint*, const GeometryPoint*);
    int ClassifyPoint(const GeometryPoint* point)
    {
        float value = normal.x * point->x + normal.y * point->y + normal.z * point->z - distance;
        if (value < 0.0)
            return 2;
        else if (value > 0.0)
            return 1;
        else
            return 0;
    }
};
struct FUN_0045c620
{
    FUN_00a699d0 planes[6];
    int unk60;
    FUN_0045c620()
    {
        unk60 = 0x3f;
    }
    __forceinline void ClearPlane(int bit)
    {
        unk60 &= ~(1 << bit);
    }
};
struct CommandPolygon
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int type;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8;
    CommandPolygon* neighbors[4];
    int FUN_00c35980();
    void FUN_00c33870(GeometryPoint, void*);
    void FUN_00c35c10(GeometryPoint*);
    __forceinline CommandPolygon* NeighborAt(int i) const
    {
        return neighbors[i];
    }
    __forceinline int GetType() const
    {
        int value = type;
        return value;
    }
    __forceinline int SideIndex() const
    {
        int value = neighbors[1] ? 1 : 3;
        return value;
    }
    __forceinline int EndIndex() const
    {
        int value = neighbors[0] ? 0 : 2;
        return value;
    }
    __forceinline CommandPolygon* SideNeighbor() const
    {
        int index1 = SideIndex();
        return NeighborAt(index1);
    }
    __forceinline CommandPolygon* EndNeighbor() const
    {
        int index1 = neighbors[0] ? 0 : 2;
        return NeighborAt(index1);
    }
};
struct CommandRecords
{
    void* vtable;
    FUN_0045c620* data;
    int allocated;
    int capacity;
    void FUN_00c4a070(int, bool);
    __forceinline int GetCapacity() const
    {
        int value = capacity;
        return value;
    }
    __forceinline FUN_0045c620& operator[](int i)
    {
        return data[i];
    }
};
struct CommandArray
{
    void* vtable;
    Elem0C* m_pData;
    int allocated, m_uiSize;
    void FUN_00c4a1e0(int, bool);
    __forceinline int GetCapacity() const
    {
        int value = m_uiSize;
        return value;
    }
    __forceinline Elem0C& operator[](int i)
    {
        return m_pData[i];
    }
};
struct GeometryCommands
{
    unsigned char state;
    CommandRecords records;
    CommandArray commands;
    int recordCount, commandCount, unknown2c;
    FNV_Local workingRecord;
    GeometryPoint origin;
    void FUN_00aa8910(CommandPolygon* polygon);
};
// pdb: BSCompoundFrustum::AddOcclusionPlane | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apPlane
void GeometryCommands::FUN_00aa8910(CommandPolygon* polygon)
{
    int type = polygon->FUN_00c35980();
    CommandPolygon* neighborTriangleA =
        type == 1 ? polygon->NeighborAt(polygon->SideIndex()) : polygon->NeighborAt(polygon->EndIndex());
    bool kA1_1 = false;
    int side = 0;
    if (neighborTriangleA)
    {
        GeometryPoint verticesCheck2[4];
        FUN_0045c620 record2_2;
        polygon->FUN_00c33870(origin, &record2_2);
        polygon->FUN_00c35c10(verticesCheck2);
        FUN_00a699d0 plane4(&verticesCheck2[0], &verticesCheck2[1], &verticesCheck2[2]);
        side = plane4.ClassifyPoint(&origin);
        neighborTriangleA->FUN_00c33870(origin, &record2_2);
        neighborTriangleA->FUN_00c35c10(verticesCheck2);
        plane4 = FUN_00a699d0(&verticesCheck2[0], &verticesCheck2[1], &verticesCheck2[2]);
        kA1_1 = side == plane4.ClassifyPoint(&origin);
    }
    if ((neighborTriangleA && neighborTriangleA->GetType() != 1) || !kA1_1)
    {
        if (commandCount + 2 >= commands.GetCapacity())
        {
            commands.FUN_00c4a1e0(commands.GetCapacity() + 10, true);
        }
        if (recordCount + 1 >= records.GetCapacity())
            records.FUN_00c4a070(records.GetCapacity() + 4, true);
        commands[commandCount].a = 8;
        ++commandCount;
        commands[commandCount].a = recordCount;
        ++commandCount;
        polygon->FUN_00c33870(origin, &records[recordCount]);
        ++recordCount;
        return;
    }
    switch (type)
    {
    case 0: {
        if (commandCount + 2 >= commands.GetCapacity())
        {
            commands.FUN_00c4a1e0(commands.GetCapacity() + 10, true);
        }
        if (recordCount + 1 >= records.GetCapacity())
            records.FUN_00c4a070(records.GetCapacity() + 4, true);
        commands[commandCount].a = 8;
        ++commandCount;
        commands[commandCount].a = recordCount;
        ++commandCount;
        polygon->FUN_00c33870(origin, &records[recordCount]);
        ++recordCount;
        return;
        break;
    }
    case 1: {
        if (commandCount + 12 >= commands.GetCapacity())
        {
            commands.FUN_00c4a1e0(commands.GetCapacity() + 12, true);
        }
        if (recordCount + 4 >= records.GetCapacity())
            records.FUN_00c4a070(records.GetCapacity() + 4, true);
        commands[commandCount++].a = 4;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 1;
        commands[commandCount++].a = 5;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 2;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 3;
        commands[commandCount++].a = 6;
        commands[commandCount++].a = 6;
        polygon->FUN_00c33870(origin, &records[recordCount]);
        polygon->FUN_00c33870(origin, &records[recordCount + 2]);
        int index1 = polygon->neighbors[1] ? 1 : 3;
        int kA114_2 = 0;
        side = 1;
        if (index1 == 1)
            kA114_2 = side == 1 ? 2 : 3;
        else
            kA114_2 = side == 1 ? 3 : 5;
        records[recordCount + 2].ClearPlane(kA114_2);
        CommandPolygon* adjacent3 = polygon->neighbors[index1];
        adjacent3->FUN_00c33870(origin, &records[recordCount + 1]);
        adjacent3->FUN_00c33870(origin, &records[recordCount + 3]);
        if (index1 == 1)
            kA114_2 = kA114_2 == 2 ? 3 : 2;
        else
            kA114_2 = kA114_2 == 4 ? 5 : 4;
        records[recordCount + 3].ClearPlane(kA114_2);
        recordCount += 4;
        break;
    }
    }
}
}   // namespace f3m_00aa8910

// @f3 0x00ab6250 (community match, verified in this file)
namespace f3m_00ab6250 {
struct MyColorA
{
    float r;
    float g;
    float b;
    float a;
};

struct Point3ParameterData
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    float unk18;
};

struct NiPSysData
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
    MyColorA* m_pkParticleColors;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short m_usNumParticles;
    short pad52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
};

struct BSPSysSimpleColorModifierCand
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MyColorA m_kColor1;
    MyColorA m_kColor2;
    MyColorA m_kColor3;
    float m_fFadeInPercent;
    float m_fFadeOutPercent;
    float m_fColor1End;
    float m_fColor2Start;
    float m_fColor2End;
    float m_fColor3Start;

    void FUN_00ab6250(float fTime, NiPSysData* pkData);
};

// FNV particle-color interpolation reference.
// pdb: BSPSysSimpleColorModifier::Update | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: fTime, pkData
void BSPSysSimpleColorModifierCand::FUN_00ab6250(float fTime, NiPSysData* pkData)
{
    unsigned short usNumParticlesTmp;
    MyColorA* pkColors8;
    float fRangeVal;
    float fRange4;
    unsigned short us4;
    float fNormAge3;
    Point3ParameterData* pkInfo3;
    float kFLerp1;
    float fLerp4;
    float fFadeOutLerpA;
    float fFadeInLerp3;
    Point3ParameterData* pkParticleInfo3;

    pkColors8 = pkData->m_pkParticleColors;
    if (!pkColors8)
        return;

    fRange4 = m_fColor2Start - m_fColor1End;
    fRangeVal = m_fColor3Start - m_fColor2End;

    usNumParticlesTmp = pkData->m_usNumParticles;
    for (us4 = 0; us4 < usNumParticlesTmp; us4++)
    {
        pkParticleInfo3 = pkData->m_pkParticleInfo;
        pkInfo3 = &pkParticleInfo3[us4];
        fNormAge3 = pkInfo3->m_fXValue / pkInfo3->m_fYValue;

        if (fRange4 != 0.0 && fNormAge3 < m_fColor2Start)
        {
            if (fNormAge3 < m_fColor1End)
            {
                pkColors8[us4].r = m_kColor1.r;
                pkColors8[us4].g = m_kColor1.g;
                pkColors8[us4].b = m_kColor1.b;
            }
            else
            {
                kFLerp1 = (fNormAge3 - m_fColor1End) / fRange4;
                pkColors8[us4].r = m_kColor1.r + (m_kColor2.r - m_kColor1.r) * kFLerp1;
                pkColors8[us4].g = m_kColor1.g + (m_kColor2.g - m_kColor1.g) * kFLerp1;
                pkColors8[us4].b = m_kColor1.b + (m_kColor2.b - m_kColor1.b) * kFLerp1;
            }
        }
        else if (fRangeVal != 0.0 && fNormAge3 > m_fColor2End)
        {
            if (fNormAge3 > m_fColor3Start)
            {
                pkColors8[us4].r = m_kColor3.r;
                pkColors8[us4].g = m_kColor3.g;
                pkColors8[us4].b = m_kColor3.b;
            }
            else
            {
                fLerp4 = (fNormAge3 - m_fColor2End) / fRangeVal;
                pkColors8[us4].r = m_kColor2.r + (m_kColor3.r - m_kColor2.r) * fLerp4;
                pkColors8[us4].g = m_kColor2.g + (m_kColor3.g - m_kColor2.g) * fLerp4;
                pkColors8[us4].b = m_kColor2.b + (m_kColor3.b - m_kColor2.b) * fLerp4;
            }
        }
        else
        {
            pkColors8[us4].r = m_kColor2.r;
            pkColors8[us4].g = m_kColor2.g;
            pkColors8[us4].b = m_kColor2.b;
        }

        if (m_fFadeOutPercent != 0.0 && fNormAge3 > m_fFadeOutPercent)
        {
            fFadeOutLerpA = (fNormAge3 - m_fFadeOutPercent) / (1.0f - m_fFadeOutPercent);
            pkColors8[us4].a = m_kColor2.a + (m_kColor3.a - m_kColor2.a) * fFadeOutLerpA;
        }
        else if (m_fFadeInPercent != 0.0 && fNormAge3 < m_fFadeInPercent)
        {
            fFadeInLerp3 = fNormAge3 / (float)(m_fFadeInPercent);
            pkColors8[us4].a = m_kColor1.a + (m_kColor2.a - m_kColor1.a) * fFadeInLerp3;
        }
        else
        {
            pkColors8[us4].a = m_kColor2.a;
        }
    }
}
}   // namespace f3m_00ab6250

// @f3 0x00ab93e0 (community match, verified in this file)
namespace fo3_00ab93e0 {
struct Point3
{
    float x, y, z;
    Point3() {}
};
extern Point3 DAT_0108ec68;
struct BoxPoints
{
    unsigned short unk00;
    Point3 unk04[8];
    Point3 unk64[8];
    BoxPoints* FUN_00ab93e0();
};

// pdb: DECAL_PLACEMENT_VECTOR_GROUP_DATA::DECAL_PLACEMENT_VECTOR_GROUP_DATA | BSDecalPVExtraData.obj | fnv360_0822_retail, call_seq, medium
BoxPoints* BoxPoints::FUN_00ab93e0()
{
    unk00 = 0;
    for (int i = 0; i < 8; ++i)
    {
        unk04[i] = DAT_0108ec68;
        unk64[i] = DAT_0108ec68;
    }
    return this;
}
}

// @f3 0x00ab8130 (community match, verified in this file)
namespace f3m_00ab8130 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace fo3_ab8130 {
void* __cdecl FUN_0089e810(unsigned int);
void __cdecl FUN_0089e890(void*);
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    __forceinline NiPtr(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPtr<T>& operator=(const NiPtr<T>& other)
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
    __forceinline bool operator!=(const NiPtr<T>& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

template <class T> struct MallocIf
{
    static T* Allocate(unsigned int auiCount)
    {
        return (T*)FUN_0089e810(sizeof(T) * auiCount);
    }
};

template <class T> class PtrArray
{
  public:
    virtual ~PtrArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00ab8130(unsigned int uiMaxSize);
};

// @fnv 0x00c628c0
// pdb: NiTArray<NiPointer<NiAVObject>,NiTMallocInterface<NiPointer<NiAVObject> > >::SetSize | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_seq, high
// pdb params: uiMaxSize
template <class T> void PtrArray<T>::FUN_00ab8130(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != T(0))
            {
                m_pBase[i] = T(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    T* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = MallocIf<T>::Allocate(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = T(0);
    }
    else
    {
        m_pBase = 0;
    }
    FUN_0089e890(pSaveBase);
}

template class PtrArray<NiPtr<RefObj> >;
}
}   // namespace f3m_00ab8130

// @f3 0x00ab7460 (community match, verified in this file)
namespace fo3_ab7460 {
void* __cdecl FUN_0089e810(unsigned int);
void __cdecl FUN_0089e890(void*);

struct ViewerStrings
{
    virtual ~ViewerStrings();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00555790(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;
        unsigned short i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = 0;
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }
        char** pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = Alloc(m_usMaxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = 0;
        }
        else
        {
            m_pBase = 0;
        }
        Free(pSaveBase);
    }
    static char** Alloc(unsigned int n)
    {
        return (char**)FUN_0089e810(n * sizeof(char*));
    }
    static void Free(char** p)
    {
        FUN_0089e890(p);
    }
    void FUN_005b3880(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00555790(uiIndex + m_usGrowBy);
        FUN_005b3880(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char* const& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct RTTI_Stub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};
extern RTTI_Stub DAT_0116eb5c;

char* __cdecl FUN_00847b50(const char* name);
char* __cdecl FUN_00847d80(const char* label, unsigned int value);
char* __cdecl FUN_00847ce0(const char* label, unsigned short value);
char* __cdecl FUN_00847e20(const char* label, void* value);

struct NiFixedString
{
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

struct NamedObject
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    NiFixedString m_kName;
    const char* GetName() const
    {
        return m_kName;
    }
};

struct ListItem
{
    ListItem* m_pkNext;
    ListItem* m_pkPrev;
    NamedObject* m_element;
};

struct ObjList
{
    ListItem* m_pkHead;
    ListItem* m_pkTail;
    ListItem* GetHeadPos() const
    {
        return m_pkHead;
    }
    NamedObject* GetNext(ListItem*& kPos) const
    {
        NamedObject* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct EmitterBase
{
    void FUN_0082ee90(ViewerStrings* pkStrings);
};

struct MeshEmitter : EmitterBase
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
    ObjList m_kThirdFollowingStreamField;
    int unkb4;
    unsigned short unkb8;
    unsigned short m_usIndex;
    int unkbc;
    int unkc0;
    unsigned int m_uiMax;

    void FUN_00ab7460(ViewerStrings* pkStrings);
};

// @fnv 0x00c5e9f0
// pdb: BSMasterParticleSystem::GetViewerStrings | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void MeshEmitter::FUN_00ab7460(ViewerStrings* pkStrings)
{
    EmitterBase::FUN_0082ee90(pkStrings);
    pkStrings->Add(FUN_00847b50(DAT_0116eb5c.GetName()));
    pkStrings->Add(FUN_00847d80("Index", m_uiMax));
    pkStrings->Add(FUN_00847ce0("Max Emitter Objs", m_usIndex));
    pkStrings->Add(FUN_00847b50("Emitter Objs"));
    ListItem* kPos = m_kThirdFollowingStreamField.GetHeadPos();
    while (kPos)
    {
        NamedObject* pkObj = m_kThirdFollowingStreamField.GetNext(kPos);
        pkStrings->Add(FUN_00847e20(pkObj->GetName() ? pkObj->GetName() : "No Name", pkObj));
    }
}

}

// @f3 0x00aa65e0 (community match, verified in this file)
extern char const DAT_00e89c04[];
extern char const DAT_00e89bf0[];
extern char const DAT_00e89bd8[];
extern char const DAT_00e89bd0[];
extern char const DAT_00e89a54[];
extern char const DAT_00e89bb0[];
extern char const DAT_00e89ba0[];
extern char const DAT_00e89b84[];
extern char const DAT_00e89b70[];
extern char const DAT_00e89b5c[];
extern char const DAT_00e89b50[];
extern char const DAT_00e89b40[];
extern char const DAT_00e89b34[];
extern char const DAT_00e89b28[];
extern char const DAT_00e89b08[];
extern char const DAT_00e89af0[];
extern char const DAT_00e89450[];
extern char const DAT_00e89adc[];
extern char const DAT_00e89488[];
extern char const DAT_00e89460[];
extern char const DAT_00e89ac8[];
extern char const DAT_00e89ab4[];
extern char const DAT_00e89a98[];
extern char const DAT_00e89a88[];
extern char const DAT_00e89a6c[];
namespace f3m_00aa65e0 {
namespace f3_00aa65e0 {
struct NiObject
{
};
struct FUN_00c465a0;
struct FUN_00c4fb10_shell;
struct FUN_00c61b10;

typedef NiObject*(__cdecl* PFN_NiObjectLoader)(void);

struct NiStream
{
    static int __cdecl FUN_0082b9e0(char const* name, PFN_NiObjectLoader loader);
};

NiObject* __cdecl FUN_00ab9bf0();
NiObject* __cdecl FUN_00ab9e50();
NiObject* __cdecl FUN_00aafc50();
NiObject* __cdecl FUN_00ab0e80();
NiObject* __cdecl FUN_00aa6080();
NiObject* __cdecl FUN_00ab9ab0();
FUN_00c465a0* __cdecl FUN_00aaa860();
NiObject* __cdecl FUN_00ab8ff0();
NiObject* __cdecl FUN_00ab08a0();
FUN_00c61b10* __cdecl FUN_00ab8590();
NiObject* __cdecl FUN_00ab7ca0();
NiObject* __cdecl FUN_00aab240();
NiObject* __cdecl FUN_00aaaf70();
NiObject* __cdecl FUN_00aa7020();
NiObject* __cdecl FUN_00ab50a0();
NiObject* __cdecl FUN_00ab7ac0();
NiObject* __cdecl FUN_00a9f370();
NiObject* __cdecl FUN_00aaa2c0();
NiObject* __cdecl FUN_00aa0c00();
NiObject* __cdecl FUN_00a9f530();
NiObject* __cdecl FUN_00ab6be0();
FUN_00c4fb10_shell* __cdecl FUN_00aad720();
NiObject* __cdecl FUN_00ab64f0();
NiObject* __cdecl FUN_00aab0e0();
NiObject* __cdecl FUN_00ab5f10();


// @fnv 0x00c3a6d0
// pdb: BSStream::InitLoaders | BSStream.obj | fnv360_0822_retail, strset, low
void FUN_00aa65e0()
{
    NiStream::FUN_0082b9e0(DAT_00e89c04, FUN_00ab9bf0);
    NiStream::FUN_0082b9e0(DAT_00e89bf0, FUN_00ab9e50);
    NiStream::FUN_0082b9e0(DAT_00e89bd8, FUN_00aafc50);
    NiStream::FUN_0082b9e0(DAT_00e89bd0, FUN_00ab0e80);
    NiStream::FUN_0082b9e0(DAT_00e89a54, FUN_00aa6080);
    NiStream::FUN_0082b9e0(DAT_00e89bb0, FUN_00ab9ab0);
    NiStream::FUN_0082b9e0(DAT_00e89ba0, reinterpret_cast<PFN_NiObjectLoader>(FUN_00aaa860));
    NiStream::FUN_0082b9e0(DAT_00e89b84, FUN_00ab8ff0);
    NiStream::FUN_0082b9e0(DAT_00e89b70, FUN_00ab08a0);
    NiStream::FUN_0082b9e0(DAT_00e89b5c, reinterpret_cast<PFN_NiObjectLoader>(FUN_00ab8590));
    NiStream::FUN_0082b9e0(DAT_00e89b50, FUN_00ab7ca0);
    NiStream::FUN_0082b9e0(DAT_00e89b40, FUN_00aab240);
    NiStream::FUN_0082b9e0(DAT_00e89b34, FUN_00aaaf70);
    NiStream::FUN_0082b9e0(DAT_00e89b28, FUN_00aa7020);
    NiStream::FUN_0082b9e0(DAT_00e89b08, FUN_00ab50a0);
    NiStream::FUN_0082b9e0(DAT_00e89af0, FUN_00ab7ac0);
    NiStream::FUN_0082b9e0(DAT_00e89450, FUN_00a9f370);
    NiStream::FUN_0082b9e0(DAT_00e89adc, FUN_00aaa2c0);
    NiStream::FUN_0082b9e0(DAT_00e89488, FUN_00aa0c00);
    NiStream::FUN_0082b9e0(DAT_00e89460, FUN_00a9f530);
    NiStream::FUN_0082b9e0(DAT_00e89ac8, FUN_00ab6be0);
    NiStream::FUN_0082b9e0(DAT_00e89ab4, reinterpret_cast<PFN_NiObjectLoader>(FUN_00aad720));
    NiStream::FUN_0082b9e0(DAT_00e89a98, FUN_00ab64f0);
    NiStream::FUN_0082b9e0(DAT_00e89a88, FUN_00aab0e0);
    NiStream::FUN_0082b9e0(DAT_00e89a6c, FUN_00ab5f10);
}

}
}   // namespace f3m_00aa65e0

// @f3 0x00aa1680 (community match, verified in this file)
#include <math.h>
namespace f3m_00aa1680 {
namespace fo3_00aa1680 {
struct Vec3
{
    float x;
    float y;
    float z;
    __forceinline Vec3()
    {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec3 operator-(const Vec3& v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
};
__forceinline float AbsPoint(float x)
{
    return (double)(float)fabs((double)x);
}
struct Bound16
{
    Vec3 c;
    float r;
};
struct PtOp
{
    float x;
    float y;
    float z;
    PtOp FUN_00439ef0(const PtOp& o) const;
};
struct Prim;
struct Param
{
    int p_00;
    int p_04;
    int p_08;
    Prim* m_0c;
    __forceinline Prim* GetBV()
    {
        Prim* result = m_0c;
        return result;
    }
};
struct Prim
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
    virtual int v35();
    virtual void v36();
    virtual void v37();
    virtual int v38(void* p);
    virtual void v39();
    virtual void v40();
    virtual int v41(void* p);
    int m_04;
    int m_08;
    Vec3 m_kCenterPosition;
    Vec3 m_radii;
    inline bool FUN_00aa1540(Vec3 v)
    {
        Vec3 delta = v - m_kCenterPosition;
        return AbsPoint(delta.x) - m_radii.x <= 0.01 && AbsPoint(delta.y) - m_radii.y <= 0.01 &&
               AbsPoint(delta.z) - m_radii.z <= 0.01;
    }
    void BSMultiBoundOBB_GetVertices(Vec3* arr);
    int FUN_00aa1680(Param* arg);
};

// @fnv 0x00c384f0
// pdb: BSMultiBoundAABB::CheckBound | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aTargetBound
int Prim::FUN_00aa1680(Param* arg)
{
    int mode_2 = arg->GetBV()->v35();
    if (mode_2 == 1)
    {
        Prim* q = arg->GetBV();
        Vec3 diff_2 = m_kCenterPosition - q->m_kCenterPosition;
        float resZ = AbsPoint(diff_2.x) + q->m_radii.x - m_radii.x;
        float resY4 = AbsPoint(diff_2.y) + q->m_radii.y - m_radii.y;
        float resX9 = AbsPoint(diff_2.z) + q->m_radii.z - m_radii.z;
        if (resZ > 0.0 || resY4 > 0.0 || resX9 > 0.0)
            return 0;
        return 2;
    }
    else if (mode_2 == 2)
    {
        Prim* q = arg->GetBV();
        if (!FUN_00aa1540(q->m_kCenterPosition))
            return 0;
        else
        {
            Vec3 arr[8];
            q->BSMultiBoundOBB_GetVertices(arr);
            for (int i3 = 0; i3 < 8; ++i3)
            {
                if (!FUN_00aa1540(arr[i3]))
                    return 0;
            }
            return 2;
        }
    }
    else if (mode_2 == 3)
    {
        Prim* q = arg->GetBV();
        Bound16 out;
        q->v41(&out);
        return v38(&out);
    }
    return 0;
}

}
}   // namespace f3m_00aa1680

// @f3 0x00aa1250 (community match, verified in this file)
namespace f3m_00aa1250 {
namespace fo3_00aa1250 {
struct Pt3
{
    float x, y, z;
    Pt3()
    {}
    Pt3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    Pt3 operator*(float f) const
    {
        return Pt3(x * f, y * f, z * f);
    }
    Pt3 operator+(const Pt3& r) const;
    Pt3 operator-(const Pt3& r) const;
    static const Pt3 ms_kFirstPoint;
    static const Pt3 ms_kSecondPoint;
    static const Pt3 ms_kThirdPoint;
};

struct Plane4
{
    float nx, ny, nz, d;
    int WhichSide(const Pt3* p) const
    {
        float fDist = nx * p->x + ny * p->y + nz * p->z - d;
        if (fDist < 0.0)
            return 2;
        if (fDist > 0.0)
            return 1;
        return 0;
    }
};

struct Frustum6
{
    Plane4 m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};

struct OccShape
{
    int unk00, unk04, unk08;
    Pt3 kTargetCenter;
    float fScaleMultiplier, m_fGlyphExtent, m_fGlyphWidthInPixels;
    void BSMultiBoundAABB_GetVertices(Pt3* m_pkDeltas)
    {
        Pt3 vX = Pt3::ms_kFirstPoint * fScaleMultiplier;
        Pt3 vY = Pt3::ms_kSecondPoint * m_fGlyphExtent;
        Pt3 vZ = Pt3::ms_kThirdPoint * m_fGlyphWidthInPixels;
        m_pkDeltas[0] = kTargetCenter + vX + vY + vZ;
        m_pkDeltas[1] = kTargetCenter + vX + vY - vZ;
        m_pkDeltas[2] = kTargetCenter + vX - vY + vZ;
        m_pkDeltas[3] = kTargetCenter + vX - vY - vZ;
        m_pkDeltas[4] = kTargetCenter - vX + vY + vZ;
        m_pkDeltas[5] = kTargetCenter - vX + vY - vZ;
        m_pkDeltas[6] = kTargetCenter - vX - vY + vZ;
        m_pkDeltas[7] = kTargetCenter - vX - vY - vZ;
    }
    bool FUN_00aa1250(Frustum6* pkPlanes);
};

// @fnv 0x00c387f0
// pdb: BSMultiBoundAABB::WithinFrustum | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aPlanes
bool OccShape::FUN_00aa1250(Frustum6* pkPlanes)
{
    Pt3 kVerts[8];
    bool bFlat = (m_fGlyphWidthInPixels == 0.0);
    BSMultiBoundAABB_GetVertices(kVerts);
    for (int i = 0; i < 6; i++)
    {
        if (bool(pkPlanes->m_uiActivePlaneMask & (1 << i)))
        {
            bool bAllOut = true;
            for (int j = 0; j < 8; j++)
            {
                if (!bFlat || (j % 2) != 0)
                {
                    if (pkPlanes->m_akPlanes[i].WhichSide(&kVerts[j]) != 2)
                        bAllOut = false;
                }
            }
            if (bAllOut)
                return false;
        }
    }
    return true;
}

}
}   // namespace f3m_00aa1250

// @f3 0x00aac1f0 (community match, verified in this file)
namespace f3m_00aac1f0 {
namespace fo3_aac1f0 {
struct VertexDE80 {
    float m_00, m_04, m_08;
};
struct DataDE80 {
    int m_00;
    VertexDE80* m_04;
};
struct ObjectDE80 {
    DataDE80* m_00;
    bool FUN_00aac1f0(float x, float y, int A, int B, int C);
};

// @fnv 0x00c4de80
// pdb: BSPolygon2D::IsPointInsideTri | BSPolygon.obj | fnv360_0822_retail, objrun, medium
// pdb params: afPoint, aiIndex1, aiIndex2, aiIndex3
bool ObjectDE80::FUN_00aac1f0(float x, float y, int A, int B, int C)
{
    float p, h, a, i, s, f, eb, cf, q, b, ba, k, l, c, e;
    VertexDE80& j = m_00->m_04[C];
    eb = (double)j.m_00 - m_00->m_04[B].m_00;
    {
        VertexDE80* j;
        a = (j = &m_00->m_04[C])->m_04 - m_00->m_04[B].m_04;
        {
            VertexDE80* j;
            cf = (double)(j = &m_00->m_04[A])->m_00 - m_00->m_04[C].m_00;
            {
                VertexDE80* j;
                e = (j = &m_00->m_04[A])->m_04 - m_00->m_04[C].m_04;
                {
                    VertexDE80* j;
                    h = (double)(j = &m_00->m_04[B])->m_00 - m_00->m_04[A].m_00;
                    {
                        VertexDE80* j;
                        k = (j = &m_00->m_04[B])->m_04 - m_00->m_04[A].m_04;
                        p = (double)x - m_00->m_04[A].m_00;
                        f = y - m_00->m_04[A].m_04;
                        ba = (double)x - m_00->m_04[B].m_00;
                        b = y - m_00->m_04[B].m_04;
                        q = (double)x - m_00->m_04[C].m_00;
                        c = y - m_00->m_04[C].m_04;
                        l = eb * b - a * ba;
                        i = h * f - k * p;
                        s = cf * c - e * q;
                        return l <= 0.0 && s <= 0.0 && i <= 0.0;
                    }
                }
            }
        }
    }
}

}
}   // namespace f3m_00aac1f0

// @f3 0x00ab8300 (community match, verified in this file)
namespace f3m_00ab8300 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace fo3_ab8300 {
void* FUN_0089e810(unsigned int);
void FUN_0089e890(void*);
struct CmpRefObject
{
    virtual ~CmpRefObject();
    virtual void DeleteThis();
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

struct CmpPtr
{
    CmpRefObject* m_pObject;
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
    CmpPtr& FUN_008e9600(const CmpPtr& other)
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
        return (CmpPtr*)FUN_0089e810(sizeof(CmpPtr) * auiCount);
    }
    void FUN_00ab8300();
};

// @fnv 0x00c63030
// pdb: NiTArray<NiPointer<NiAVObject>,NiTMallocInterface<NiPointer<NiAVObject> > >::Compact | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_seq, medium
void CmpPtrArray::FUN_00ab8300()
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
                    m_pBase[j].FUN_008e9600(m_pBase[i]);
                j++;
            }
        }
    }

    CmpPtr* pSaveBase = m_pBase;
    m_usMaxSize = m_usSize = m_usESize;
    if (m_usMaxSize > 0)
    {
        m_pBase = Allocate(m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i].FUN_008e9600(pSaveBase[i]);
    }
    else
    {
        m_pBase = 0;
    }
    FUN_0089e890(pSaveBase);
}


}
}   // namespace f3m_00ab8300

// @f3 0x00aa5580 (community match, verified in this file)
extern const char DAT_00e89874[];
extern const char DAT_00e8987c[];
extern const char DAT_00e8988c[];
extern const char DAT_00e898bc[];
#include <string.h>
namespace f3m_00aa5580 {
extern int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
struct QEntry
{
    unsigned int unk00, unk04, packedSize, packedOffset;
};
struct QTask
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Describe(char*, unsigned int);
};
struct QPointer
{
    QTask* value;
    operator QTask*()
    {
        return value;
    }
};
struct QArray
{
    unsigned int unk00;
    QPointer* data;
    unsigned int count;
};
struct QRequest
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    QArray* tasks;
    unsigned int unk24;
    const char* name;
    QEntry* entry;
    bool FUN_00aa5580(char*, unsigned int, const char*);
};
// @fnv 0x00c3d0e0
// pdb: QueuedFileEntry::GetDescription | QueuedFiles.obj | fnv360_0822_retail, ustr, medium
// pdb params: apDescription, aiBufferSize, apFileEntryTypeDescription
bool QRequest::FUN_00aa5580(char* out, unsigned int size, const char* type)
{
    char buffer[13000];
    unsigned int i;
    {
        QEntry* a;
        const char* b;
        if ((a = entry) && (b = name))
        {
            QEntry* f = entry;
            unsigned int g = f->packedSize & 0x3fffffff;
            unsigned int c;
            QEntry* d = entry;
            c = d->packedOffset & 0x7fffffff;
            const char* e = name;
            FUN_00403230(out, size, DAT_00e898bc, type, e, c, g);
        }
        else
        {
            QEntry* h = entry;
            if (h)
            {
                QEntry* k = entry;
                unsigned int l = k->packedSize & 0x3fffffff;
                QEntry* j = entry;
                FUN_00403230(out, size, DAT_00e8988c, type,
                             j->packedOffset & 0x7fffffff, l);
            }
            else
            {
                const char* m = name;
                FUN_00403230(out, size, DAT_00e8987c, type, m);
            }
        }
        if (tasks)
        {
            unsigned int n;
            for (i = 0; i < (n = tasks->count); i++)
            {
                QPointer* p = &tasks->data[i];
                QTask* o = p->value;
                if (o)
                {
                    QPointer* q = &tasks->data[i];
                    if (static_cast<QTask*>(*q)->Describe(buffer, sizeof(buffer)))
                    {
                        strcat_s(out, size, DAT_00e89874);
                        strcat_s(out, size, buffer);
                    }
                }
            }
        }
    }
    return true;
}

}   // namespace f3m_00aa5580

// @f3 0x00ab5aa0 (community match, verified in this file)
namespace f3m_00ab5aa0 {
namespace fo3_ab5aa0 {
int __cdecl FUN_00a9d930(int);
int __cdecl GetStateResult(int* apParams)
{
    int iResult = 0;
    int iState = FUN_00a9d930(apParams[2]);
    switch (iState)
    {
    case 0: iResult = 3; break;
    case 6: iResult = 1; break;
    default: iResult = 4; break;
    }
    return iResult;
}
typedef struct HKEY__* HKEY;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(HKEY hKey, const char* lpValueName, DWORD* lpReserved, DWORD* lpType, BYTE* lpData, DWORD* lpcbData);

extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);

struct Setting {
    int unk00;
    int value;
    const char* name;
    unsigned int FUN_00a9da00();
    Setting& FUN_00a9da90(const char* str);
};

int __cdecl GetStateResult(int* apParams);

struct RegSettingCollection {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Open(int a);
    virtual void Close();
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104;
    HKEY hKey;
    bool FUN_00ab5aa0(Setting* pSetting);
};

// @fnv 0x00c5d780
bool RegSettingCollection::FUN_00ab5aa0(Setting* pSetting) {
    bool bResultTmp = false;
    char shortName6[64];
    char strBuf_[264];
    const char* pName4 = pSetting->name;
    if (pName4) {
        bool bOpened5;
        DWORD dwSize3;
        DWORD kDwType;
        BYTE* pData6;
        {
            HKEY hOpenKeyX = hKey;
            bOpened5 = hOpenKeyX == 0;
        }
        if (bOpened5) {
            Open(0);
        }
        {
            HKEY hCurKey5 = hKey;
            if (hCurKey5) {
                dwSize3 = pSetting->FUN_00a9da00();
                kDwType = GetStateResult((int*)pSetting);
                if (kDwType == 1) {
                    strcpy_s(shortName6, 0x40, pName4);
                    shortName6[0] = 's';
                    pName4 = shortName6;
                    strBuf_[0] = 0;
                    dwSize3 = 0x104;
                    pData6 = (BYTE*)strBuf_;
                } else {
                    pData6 = (BYTE*)&pSetting->value;
                }
                HKEY hQueryKey = hKey;
                bResultTmp = RegQueryValueExA(hQueryKey, pName4, 0, &kDwType, pData6, &dwSize3) == 0;
                if (bResultTmp && kDwType == 1) {
                    pSetting->FUN_00a9da90(strBuf_);
                }
            }
        }
        if (bOpened5) {
            Close();
        }
    }
    return bResultTmp;
}

}
}   // namespace f3m_00ab5aa0

// @f3 0x00ab6f80 (community match, verified in this file)
namespace f3m_00ab6f80 {
struct NiObject;
struct BaseForCall { bool FUN_0082e460(NiObject*); };
struct SwitchChild {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58();
    virtual bool IsEqual(SwitchChild* pOther);
};

struct ListNode {
    ListNode* m_pkNext;
    ListNode* m_pkPrev;
    int m_element;
};

struct ListOwner_c5e830 : BaseForCall {
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
    ListNode* m_pkHead;
    int unkB0;
    int unkB4;
    unsigned short m_usB8;
    unsigned short m_usBA;
    unsigned short m_usBC;
    unsigned short unkBE;
    int unkC0;
    int m_iC4;
    int unkC8;
    int unkCC;
    SwitchChild** m_ppChildren;
    unsigned short unkD4;
    unsigned short m_usChildCount;

    bool FUN_00ab6f80(NiObject* pObject);
};

// @fnv 0x00c5e830
// pdb: BSMasterParticleSystem::IsEqual | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkObject
bool ListOwner_c5e830::FUN_00ab6f80(NiObject* pObject)
{
    ListOwner_c5e830* kPOther;
    ListNode* kPos8;
    ListNode* kPos4;
    int a7;
    int b2;
    unsigned int aUiCount1;
    unsigned int uiCount2;
    unsigned int i_;
    SwitchChild* p1;
    SwitchChild* p6;

    if (!BaseForCall::FUN_0082e460(pObject))
        return false;

    kPOther = (ListOwner_c5e830*)pObject;
    {
        ListNode* pHead4 = m_pkHead;
        kPos8 = pHead4;
    }
    {
        ListNode* pHead7 = kPOther->m_pkHead;
        kPos4 = pHead7;
    }

    if (m_usB8 != kPOther->m_usB8 || m_usBA != kPOther->m_usBA || m_iC4 != kPOther->m_iC4
        || m_usBC != kPOther->m_usBC)
        return false;

    while (kPos8 && kPos4)
    {
        {
            int* pElemA = &kPos8->m_element;
            kPos8 = kPos8->m_pkNext;
            a7 = *pElemA;
        }
        {
            int* pElem4 = &kPos4->m_element;
            kPos4 = kPos4->m_pkNext;
            b2 = *pElem4;
        }
        if (a7 != b2)
            return false;
    }

    aUiCount1 = m_usChildCount;
    uiCount2 = kPOther->m_usChildCount;
    if (aUiCount1 != uiCount2)
        return false;

    for (i_ = 0; i_ < aUiCount1; i_++)
    {
        p1 = m_ppChildren[i_];
        p6 = kPOther->m_ppChildren[i_];
        if ((p1 && !p6) || (!p1 && p6))
            return false;
        if (p1 && !p1->IsEqual(p6))
            return false;
    }

    if (kPos8 || kPos4)
        return false;
    else
        return true;
}
}   // namespace f3m_00ab6f80

// @f3 0x00aa8e30 (community match, verified in this file)
namespace f3m_00aa8e30 {
struct NavEntryItem
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_60;
};
struct Elem_c48800
{
    int field0;
    int field4;
    int field8;
};

__forceinline Elem_c48800* elemAt(Elem_c48800* p, int i)
{
    return &p[i];
}

struct Sub_c4a070
{
    int unk00;
    void FUN_00aa8350(int, bool);
};

struct Sub_c4a1e0
{
    int unk00;
    void FUN_005bb760(int, bool);
};

struct FUN_00aa8e30_cls
{
    char m_00;
    char unk01;
    char unk02;
    char unk03;
    Sub_c4a070 m_04;
    NavEntryItem* m_08;
    int unk0C;
    int m_10;
    Sub_c4a1e0 m_14;
    Elem_c48800* m_18;
    int unk1C;
    int m_20;
    int m_24;
    int m_28;

    void FUN_00aa8e30(FUN_00aa8e30_cls* arg);
};

// @fnv 0x00c48800
// pdb: BSCompoundFrustum::AddCompoundFrustum | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apFrustum
void FUN_00aa8e30_cls::FUN_00aa8e30(FUN_00aa8e30_cls* arg)
{
    int cf;
    int q;
    int b;
    int ba;
    int k;
    int l;
    int c;
    Elem_c48800* e;
    NavEntryItem* j;

    ba = this->m_20;
    if (arg->m_28 + this->m_28 + 1 >= ba)
    {
        this->m_14.FUN_005bb760((k = this->m_20) + (arg->m_28 + 1 > 10 ? arg->m_28 + 1 : 10), true);
    }
    l = this->m_10;
    if (arg->m_24 + this->m_24 + 1 >= l)
    {
        this->m_04.FUN_00aa8350((c = this->m_10) + (arg->m_24 + 1 > 4 ? arg->m_24 + 1 : 4), true);
    }
    this->m_00 = 0;
    for (cf = 0; cf < arg->m_28; ++cf)
    {
        e = &arg->m_18[cf];
        this->m_18[this->m_28 + cf].field0 = e->field0;
    }
    for (q = 0; q < arg->m_24; ++q)
    {
        j = &arg->m_08[q];
        this->m_08[this->m_24 + q] = *j;
    }
    if (this->m_24 != 0)
    {
        for (b = this->m_28; b < this->m_28 + arg->m_28; ++b)
        {
            switch (this->m_18[b].field0)
            {
            case 7:
            case 8:
                elemAt(this->m_18, b + 1)->field0 += this->m_24;
                b++;
                break;
            }
        }
    }
    this->m_28 += arg->m_28;
    this->m_24 += arg->m_24;
}
}   // namespace f3m_00aa8e30

// @f3 0x00aabd50 (community match, verified in this file)
namespace f3_00aabd50 {
struct NiPoint3 { float x, y, z; };
struct ThreeByThreeMatrix {
    float m_afEntries[3][3];
    inline float GetEntry(int row, int col) const { return m_afEntries[row][col]; }
};
struct NiTransform { ThreeByThreeMatrix m_kOrientation; NiPoint3 m_kTranslation; float m_fScale; };
struct NiAVObject { void FUN_00477790(NiTransform*); };
struct Mat4 { float m[4][4]; };
extern NiPoint3 DAT_0108f04c;
extern "C" Mat4* __stdcall FUN_00c20844(Mat4*, float*, const Mat4*);
// @fnv 0x00c4c2d0
// pdb: BSUtilities::GetInverseWorldMatrix | BSUtilities.obj | fnv360_0822_retail, call_gap, low
// pdb params: aWorld, apSkin, aOut
void __cdecl FUN_00aabd50(NiAVObject* pObj, int bInverse, Mat4* pOut)
{
    if (!bInverse)
    {
        NiTransform kXf;
        pObj->FUN_00477790(&kXf);
        pOut->m[0][0] = kXf.m_kOrientation.GetEntry(0, 0) * kXf.m_fScale;
        pOut->m[0][1] = kXf.m_kOrientation.GetEntry(1, 0) * kXf.m_fScale;
        pOut->m[0][2] = kXf.m_kOrientation.GetEntry(2, 0) * kXf.m_fScale;
        pOut->m[0][3] = 0.0f;
        pOut->m[1][0] = kXf.m_kOrientation.GetEntry(0, 1) * kXf.m_fScale;
        pOut->m[1][1] = kXf.m_kOrientation.GetEntry(1, 1) * kXf.m_fScale;
        pOut->m[1][2] = kXf.m_kOrientation.GetEntry(2, 1) * kXf.m_fScale;
        pOut->m[1][3] = 0.0f;
        pOut->m[2][0] = kXf.m_kOrientation.GetEntry(0, 2) * kXf.m_fScale;
        pOut->m[2][1] = kXf.m_kOrientation.GetEntry(1, 2) * kXf.m_fScale;
        pOut->m[2][2] = kXf.m_kOrientation.GetEntry(2, 2) * kXf.m_fScale;
        pOut->m[2][3] = 0.0f;
        pOut->m[3][0] = kXf.m_kTranslation.x;
        pOut->m[3][1] = kXf.m_kTranslation.y;
        pOut->m[3][2] = kXf.m_kTranslation.z;
        pOut->m[3][3] = 1.0f;
    }
    else
    {
        Mat4 kM;
        kM.m[3][2] = 0.0f;
        kM.m[3][1] = 0.0f;
        kM.m[3][0] = 0.0f;
        kM.m[2][3] = 0.0f;
        kM.m[2][1] = 0.0f;
        kM.m[2][0] = 0.0f;
        kM.m[1][3] = 0.0f;
        kM.m[1][2] = 0.0f;
        kM.m[1][0] = 0.0f;
        kM.m[0][3] = 0.0f;
        kM.m[0][2] = 0.0f;
        kM.m[0][1] = 0.0f;
        kM.m[3][3] = 1.0f;
        kM.m[2][2] = 1.0f;
        kM.m[1][1] = 1.0f;
        kM.m[0][0] = 1.0f;
        const NiPoint3& rPos = DAT_0108f04c;
        kM.m[3][0] = rPos.x;
        kM.m[3][1] = rPos.y;
        kM.m[3][2] = rPos.z;
        FUN_00c20844(pOut, 0, &kM);
    }
}

}

// @f3 0x00aae9e0 (community match, verified in this file)
#include <string.h>
struct RtTypeE9 { RtTypeE9* unk00; RtTypeE9* parent; };
extern RtTypeE9 DAT_0116eb5c;
struct MemoryManager { void* Allocate(unsigned int size); void Deallocate(void* p); };
extern MemoryManager _g_memoryManager;
struct ItemE9 {
    virtual void v0();
    virtual void v1();
    virtual RtTypeE9* GetType();
    unsigned int unk04; unsigned int unk08; unsigned int unk0C; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1C; unsigned int unk20;
    unsigned int unk24; unsigned int unk28; unsigned int unk2C; unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C; unsigned int unk40;
    unsigned int unk44; unsigned int unk48; unsigned int unk4C; unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C; unsigned int unk60;
    unsigned int unk64; unsigned int unk68; unsigned int unk6C; unsigned int unk70; unsigned int unk74; unsigned int unk78; unsigned int unk7C; unsigned int unk80;
    unsigned int unk84; unsigned int unk88; unsigned int unk8C; unsigned int unk90; unsigned int unk94; unsigned int unk98; unsigned int unk9C; unsigned int unkA0;
    unsigned int unkA4; unsigned int unkA8; unsigned int unkAC; unsigned int unkB0; unsigned int unkB4; unsigned int unkB8; unsigned int unkBC; unsigned int unkC0;
    unsigned int unkC4;
};
void* operator new(unsigned int size) { return _g_memoryManager.Allocate(size); }
void operator delete(void* p) { _g_memoryManager.Deallocate(p); }
struct Node_a94440 {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1C;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C; unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C; unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
    unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6C; unsigned int unk70; unsigned int unk74; unsigned int unk78; unsigned int unk7C;
    unsigned int unk80; unsigned int unk84; unsigned int unk88; unsigned int unk8C; unsigned int unk90; unsigned int unk94; unsigned int unk98; unsigned int unk9C;
    unsigned int unkA0; unsigned int unkA4; unsigned int unkA8;
    int* unkAC;
    unsigned int unkB0;
    void FUN_00a5ed10(void* item, int arg);
    int FUN_00aae7d0(void* item);
    void FUN_00aae9e0(ItemE9* item, int arg);
};
// pdb: BSParticleSystemManager::AttachChild | BSParticleSystemManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: apChild, abFirstAvail
void Node_a94440::FUN_00aae9e0(ItemE9* item, int arg)
{
    if (item) {
        bool b = item->GetType() == &DAT_0116eb5c;
        if (b && b) {
            unsigned int index = item->unkC4;
            if (index != -1) {
                if (index < unkB0) {
                    if (unkAC[index] != -1) return;
                } else {
                    unsigned int newCap = unkB0 + 10 * ((index - unkB0 + 1) / 10 + 1);
                    int* newData = new int[newCap];
                    memset(newData, -1, newCap * 4);
                    memcpy(newData, unkAC, unkB0 * 4);
                    delete[] unkAC;
                    unkAC = newData;
                    unkB0 = newCap;
                }
                FUN_00a5ed10(item, arg);
                unkAC[index] = FUN_00aae7d0(item);
            }
        }
    }
}

// @f3 0x00ab6dd0 (community match, verified in this file)
extern const char* DAT_0116eb54;
namespace f3m_00ab6dd0 {
namespace q4 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847dd0(const char* label, float value);

__forceinline char* FormatViewerFloat(const char* label, const float& value)
{
    return FUN_00847dd0(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

struct ViewerPoint3
{
    char* FUN_00823dc0(const char* label);
    float x, y, z;
};

class QSphereObj
{
public:
    void FUN_008beac0(ViewerStrings* strings);
    void FUN_00ab6dd0(ViewerStrings* strings);

    void** table;
    unsigned int references;
    unsigned int unk08;
    ViewerPoint3 first;
    ViewerPoint3 second;
    float radius;
};

// pdb: BSMultiBoundCapsule::GetViewerStrings | BSMultiBoundCapsule.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void QSphereObj::FUN_00ab6dd0(ViewerStrings* strings)
{
    FUN_008beac0(strings);
    strings->Add(FUN_00847b50(DAT_0116eb54));
    strings->Add(first.FUN_00823dc0("PointA"));
    strings->Add(second.FUN_00823dc0("PointB"));
    float r = radius;
    strings->Add(FormatViewerFloat("Radius", r));
}
}
}   // namespace f3m_00ab6dd0

// @f3 0x00aaeff0 (community match, verified in this file)
#include <math.h>
extern bool DAT_0116da2c;
extern int DAT_0116da38;
extern int DAT_0116da44;
extern int DAT_0116da50;
namespace f3m_00aaeff0 {
namespace f3m_00aaeff0 {

struct QFrustum { float l, r, t, b, n, f; bool ortho; };
struct QCamera {
    int unk00;
    void UpdateViewFrustum(const QFrustum& fr);
};
struct QCamHolder {
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
    virtual void ve0(); virtual void ve4(); virtual void ve8(); virtual void vec();
    virtual void vf0(); virtual void vf4(); virtual void vf8(); virtual void vfc();
    virtual float GetFar();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8;
    QCamera* unkac;
    void FUN_00aaeff0(float dt);
};
}
using namespace f3m_00aaeff0;
namespace f3m_00aaeff0 {
// pdb: BSSceneGraph::SetViewDistanceBasedOnFrameRate | BSSceneGraph.obj | fnv360_0822_retail, vtable, medium
// pdb params: afTime
void QCamHolder::FUN_00aaeff0(float dt)
{
    if (!DAT_0116da2c) return;
    static float s_far = GetFar();
    if (dt > 1.0f / DAT_0116da38 || dt < 1.0f / DAT_0116da44) {
        float cur = GetFar();
        float base = (float)DAT_0116da50;
        float g = base;
        float t = (1.0f / dt - DAT_0116da38) / DAT_0116da44;
        if (t > 1.0f) g = cur;
        else if (t > 0.0f) g = base + (cur - base) * t;
        float d = g - s_far;
        if (fabs(d) > 10.0f) {
            s_far = s_far + d * dt;
            QFrustum fr = *(QFrustum*)((char*)unkac + 0xdc);
            fr.f = s_far;
            unkac->UpdateViewFrustum(fr);
        }
    }
}
}
}   // namespace f3m_00aaeff0

// @f3 0x00ab8600 (community match, verified in this file)
#include <math.h>
namespace fnv_00c625f0 {
extern int __cdecl FUN_00c04d9a(void);
extern double DAT_00dc8dc8;
float FUN_004579e0(float);

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3& operator*=(float scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }
    NiPoint3 operator*(float scale) const
    {
        return NiPoint3(scale * x, scale * y, scale * z);
    }
    float Length() const
    {
        float squared = x * x + y * y + z * z;
        return (float)sqrt((double)squared);
    }
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

extern NiPoint3 DAT_0108ec68;

struct Matrix9
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    NiPoint3 FUN_004752c0(const NiPoint3& point) { return NiPoint3(m00*point.x+m01*point.y+m02*point.z,m10*point.x+m11*point.y+m12*point.z,m20*point.x+m21*point.y+m22*point.z); }
};

struct GeometryData
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
    virtual unsigned short GetVertexCount();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* vertices;
    NiPoint3* normals;
};

struct Geometry
{
    void** vtable;
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
    struct DataPtr
    {
        GeometryData* object;
        GeometryData* operator->() const
        {
            return object;
        }
    } modelData;
    NiPoint3* GetVertices() const
    {
        return modelData->vertices;
    }
    NiPoint3* GetNormals() const
    {
        return modelData->normals;
    }
};

struct EmitterObject
{
    void** vtable;
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
    Matrix9 rotation;
    int unk8c;
    int unk90;
    int unk94;
    float scale;
    float GetScale() const
    {
        return scale;
    }
};

typedef Geometry*(__thiscall* GetGeometryFunction)(EmitterObject*);
typedef unsigned short(__thiscall* GetVertexCountFunction)(GeometryData*);

struct EmitterSampler
{
    void FUN_00ab8600(EmitterObject* object, NiPoint3& position, NiPoint3& direction);
};

// @fnv 0x00c625f0
// pdb: BSPSysArrayEmitter::GetPointFromGeometry | BSPSysArrayEmitter.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pObject, arPos, arVel
void EmitterSampler::FUN_00ab8600(EmitterObject* object, NiPoint3& position, NiPoint3& direction)
{
    Geometry* geometry = object ? ((GetGeometryFunction)object->vtable[6])(object) : 0;
    if (geometry)
    {
        unsigned short count = geometry->modelData->GetVertexCount();
        int index = (unsigned int)((double)count * (float)(FUN_00c04d9a() / DAT_00dc8dc8));
        if (index == count)
            index--;
        position = geometry->GetVertices()[index];
        position *= object->GetScale();
        NiPoint3* normals = geometry->GetNormals();
        if (normals)
        {
            NiPoint3 normal = normals[index];
            normal = object->rotation.FUN_004752c0(normal);
            float length = (float)sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
            direction = normal * length;
        }
    }
    else
    {
        position = DAT_0108ec68;
    }
}
}  // namespace fnv_00c625f0

// @f3 0x00aae800 (community match, verified in this file)
namespace Task1126 {
struct C50Type
{
    const char* field_00;
    C50Type* field_04;
};
struct C50Object
{
    virtual void slot_00();
    virtual void slot_04();
    virtual C50Type* slot_08();
    virtual C50Object* slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1c();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2c();
    virtual C50Object* slot_30();
    inline bool GetParentWorldSpace()
    {
        return field_c4;
    }
    inline const char* GetName()
    {
        return field_08;
    }
    inline C50Object* GetModifiers()
    {
        C50Object* head = field_0c;
        return head;
    }
    inline C50Object* GetNext()
    {
        C50Object* next = field_30;
        return next;
    }
    inline void* GetRoot()
    {
        return field_5c;
    }
    unsigned field_04;
    const char* field_08;
    C50Object* field_0c;
    unsigned field_10;
    unsigned field_14;
    unsigned field_18;
    unsigned field_1c;
    unsigned field_20;
    unsigned field_24;
    unsigned field_28;
    unsigned field_2c;
    C50Object* field_30;
    unsigned field_34;
    unsigned field_38;
    C50Object* field_3c;
    unsigned field_40;
    unsigned field_44;
    unsigned field_48;
    unsigned field_4c;
    unsigned field_50;
    unsigned field_54;
    unsigned field_58;
    void* field_5c;
    unsigned field_60;
    unsigned field_64;
    unsigned field_68;
    unsigned field_6c;
    unsigned field_70;
    unsigned field_74;
    unsigned field_78;
    unsigned field_7c;
    unsigned field_80;
    unsigned field_84;
    unsigned field_88;
    unsigned field_8c;
    unsigned field_90;
    unsigned field_94;
    unsigned field_98;
    unsigned field_9c;
    C50Object** field_a0;
    unsigned short field_a4, field_a6;
    unsigned field_a8;
    unsigned field_ac;
    unsigned field_b0;
    unsigned field_b4;
    unsigned field_b8;
    unsigned field_bc;
    unsigned field_c0;
    bool field_c4;
};
extern C50Type DAT_0116ec70, DAT_0116ebd8, DAT_0116db0c;
extern bool __cdecl FUN_00424d20(const C50Type*,C50Object*);
extern void __cdecl FUN_00887da0(const char*,...);
extern char DAT_00e8a938[], DAT_00e8a898[], DAT_00e8a8e8[];
inline bool C50Exact(C50Object* object, const void* type)
{
    if (!object)
        return false;
    return object->slot_08() == type;
}
inline bool C50Kind(C50Object* object)
{
    C50Type* type = object->slot_08();
    while (type)
    {
        if (type == &DAT_0116ec70)
            return true;
        type = type->field_04;
    }
    return false;
}
inline bool C50IsKind(C50Object* object) { return FUN_00424d20(&DAT_0116ec70,object); }
struct C50ChildLookup
{
    C50Object* value;
    C50Object** entry;
};
inline C50Object* C50ChildAt(C50Object* node, unsigned int index)
{
    C50ChildLookup lookup;
    lookup.entry = &node->field_a0[index];
    lookup.value = *lookup.entry;
    return lookup.value;
}
// @fnv 0x00c50f90
// pdb: BSParticleSystemManager::CheckEmitterRecurse | BSParticleSystemManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: apObject, apMasterSystem
bool __cdecl FUN_00aae800(C50Object* object, void* material)
{
    if (!object)
        return false;
    if (object->slot_30())
    {
        if (C50Exact(object, &DAT_0116ebd8))
        {
            C50Object* system = object;
            if (!system->GetParentWorldSpace())
            {
                FUN_00887da0(DAT_00e8a938, object->GetName());
                return false;
            }
            C50Object* modifier = system->GetModifiers();
            while (modifier)
            {
                if (C50Exact(modifier, &DAT_0116db0c))
                {
                    C50Object* emitter = modifier;
                    C50Object* target7 = emitter->field_3c;
                    if (material)
                    {
                        if (emitter->GetRoot() != material)
                        {
                            FUN_00887da0(DAT_00e8a898, object->GetName());
                            return false;
                        }
                    }
                    if (FUN_00424d20(&DAT_0116ec70,target7))
                        return true;
                    return false;
                }
                else
                {
                    modifier = modifier->GetNext();
                }
            }
        }
        FUN_00887da0(DAT_00e8a8e8, object->GetName());
        return false;
    }
    else
    {
        C50Object* node = object ? object->slot_0c() : 0;
        if (node)
        {
            unsigned int count = node->field_a6;
            for (unsigned int index = 0; index < count; ++index)
            {
                C50Object* child = C50ChildAt(node, index);
                if (child && !FUN_00aae800(child, material))
                    return false;
            }
        }
    }
    return true;
}

}

// @f3 0x00ab2f20 (community match, verified in this file)
#include <cmath>
extern "C" char DAT_01090a78;
namespace f3m_00ab2f20 {
struct NiMemObject {static void* operator new(unsigned);static void operator delete(void*,unsigned);};
namespace fnv_00c58f00 {
struct FUN_0086b930_alloc
{
    void* __thiscall FUN_0086b930(unsigned int size);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
extern "C" double __cdecl cos(double angle);
extern "C" double __cdecl sin(double angle);

struct Vec3Item
{
    float x;
    float y;
    float z;
    __forceinline Vec3Item()
    {}
    __forceinline Vec3Item(float a, float b, float c) : x(a), y(b), z(c)
    {}
    static __forceinline void* operator new[](unsigned int size)
    {
        return ((FUN_0086b930_alloc*)&DAT_01090a78)->FUN_0086b930(size);
    }
};

struct Vec4Item
{
    float x;
    float y;
    float z;
    float w;
    __forceinline Vec4Item() : x(0), y(0), z(0), w(0)
    {}
    static __forceinline void* operator new[](unsigned int size)
    {
        return ((FUN_0086b930_alloc*)&DAT_01090a78)->FUN_0086b930(size);
    }
};

struct SpawnedObject_b10495 : NiMemObject
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
    SpawnedObject_b10495(unsigned short count, Vec3Item* a, Vec4Item* b, int c, int d, int e, unsigned char* flags);
};

__forceinline float CircleTrigA(float a)
{
    return std::cos(a);
}
__forceinline float CircleTrigB(float a)
{
    return std::sin(a);
}
// @fnv 0x00c58f00
// pdb: BSTestObjects::CreateCircle | BSTestObjects.obj | fnv360_0822_retail, call_dedup, low
// pdb params: afRadius, asSegments, apColor
void* __cdecl FUN_00ab2f20(float radius, unsigned short count, Vec4Item* color)
{
    Vec3Item* aVal = new Vec3Item[count];
    unsigned char* flagsB = new unsigned char[count];
    Vec4Item* b5 = color ? new Vec4Item[count] : 0;
    float step3 = 6.2831854820251465 / (int)count;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (b5 != 0)
        {
            b5[i] = *color;
        }
        flagsB[i] = 1;
        aVal[i] = Vec3Item(CircleTrigB(step3 * i) * radius, CircleTrigA(step3 * i) * radius, 0.0f);
    }
    SpawnedObject_b10495* result5 = new SpawnedObject_b10495(count, aVal, b5, 0, 1, 0, flagsB);
    return result5;
}
}
}   // namespace f3m_00ab2f20

// @f3 0x00aaf1a0 (community match, verified in this file)
namespace f3m_00aaf1a0 {


extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern const char* DAT_00e207a8;
const char* FUN_008242a0(const char*);
struct RootFixedZ {
 const char* value;
 RootFixedZ(const char* str):value(FUN_008242a0(str)){}
 ~RootFixedZ(){if(value!=DAT_00e207a8)InterlockedDecrement((volatile long*)(value-8));}
};
class NiMemObject {
public:
 static void* operator new(unsigned int);
 static void operator delete(void*);
};
struct MatrixRootZ {
 float m00,m01,m02,m10,m11,m12,m20,m21,m22;
 MatrixRootZ(float a,float b,float c,float d,float e,float f,float g,float h,float i):m00(a),m01(b),m02(c),m10(d),m11(e),m12(f),m20(g),m21(h),m22(i){}
};
struct FrustumRootZ {
 float left,right,top,bottom;
 FrustumRootZ(float a,float b,float c,float d):left(a),right(b),top(c),bottom(d){}
};
struct CenterRootZ {float x,y,z;};
extern CenterRootZ DAT_0108ec68;
struct BoundRootZ {CenterRootZ center;float radius;
 void Reset() {center=DAT_0108ec68;radius=0.0f;}
};

class NiNode : public NiMemObject {
public:
 virtual ~NiNode();
 virtual void DeleteThis();
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
 virtual void SetBound(void*);
 volatile long refs;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 BoundRootZ* bound;
 int unk24;
 int unk28;
 int unk2c;
 unsigned flags;
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
 NiNode(unsigned short);
 void FUN_008245d0(const RootFixedZ&);
 void FUN_0082eb10(NiNode*,bool);
};
static __forceinline void InstallBoundRootZ(NiNode* node,void* p) {node->SetBound(p);}
class A91D80Camera : public NiMemObject {
public:
 virtual ~A91D80Camera();
 virtual void DeleteThis();
 volatile long refs;
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
 MatrixRootZ transform;
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
 float scale;
 float reciprocal;
 FrustumRootZ frustum;
 int unk110;
 A91D80Camera();
 void FUN_008245d0(const RootFixedZ&);
};
struct CameraRefRootZ {
 A91D80Camera* value;
 CameraRefRootZ():value(0){}
 ~CameraRefRootZ(){if(value && InterlockedDecrement(&value->refs)==0)value->DeleteThis();}
 CameraRefRootZ& operator=(A91D80Camera* p) {
  A91D80Camera* old=value; if(old!=p){if(old && InterlockedDecrement(&old->refs)==0)old->DeleteThis();value=p;if(p)InterlockedIncrement(&p->refs);}return *this;
 }
};
struct RootHeapZ { void* FUN_0086b930(unsigned); };
extern RootHeapZ DAT_01090a78;
class FUN_00a69400 {
public:
 virtual ~FUN_00a69400();
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
 FUN_00a69400(void*);
};
class BSCullingProcess : public FUN_00a69400 {
public:
 virtual ~BSCullingProcess();
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
 BSCullingProcess():FUN_00a69400(0),unk90(0),unkbc(0),unkc0(0),unkc4(0){}
 static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void*);
};
extern float DAT_0116d9e8,DAT_0116d9f4;
struct CameraArgRootZ {A91D80Camera* value; CameraArgRootZ(A91D80Camera* p):value(p){}};
class BSSceneGraph : public NiNode {
public:
 CameraRefRootZ camera;
 int unkb0;
 BSCullingProcess* culling;
 bool unkb8;
 BSSceneGraph(const char*,bool,CameraArgRootZ);
 virtual ~BSSceneGraph();
 float FUN_00aaedd0();
 void FUN_00aaeaf0(float,int,int,int);
 void FUN_00aaef70();
};
// pdb: BSSceneGraph::BSSceneGraph | BSSceneGraph.obj | fnv360_0822_retail, ustr, high
// pdb params: apSceneGraphName, abMenuSceneGraph, apCamera
BSSceneGraph::BSSceneGraph(const char* name,bool enabled,CameraArgRootZ cameraArg):NiNode(0),camera() {
 unkb8=enabled;
 culling=new BSCullingProcess;
 unkb0=0;
 char buffer[512];
 sprintf_s(buffer,512,"%sRoot Node",name);
 FUN_008245d0(RootFixedZ(buffer));
 NiNode* node=new NiNode(0);
 sprintf_s(buffer,512,"%sRoot CameraNode",name);
 node->FUN_008245d0(RootFixedZ(buffer));
 FUN_0082eb10(node,true);
 if(cameraArg.value) camera=cameraArg.value;
 else {
  camera=new A91D80Camera;
  sprintf_s(buffer,512,"%sRoot Camera",name);
  camera.value->FUN_008245d0(RootFixedZ(buffer));
  FrustumRootZ frustum(0,1,1,0);
  camera.value->frustum=frustum;
  MatrixRootZ identity(0,0,1,1,0,0,0,1,0);
  camera.value->transform=identity;
  camera.value->scale=1.0f;
  camera.value->reciprocal=FUN_00aaedd0()/DAT_0116d9e8;
  FUN_00aaeaf0(DAT_0116d9f4,1,0,0);
 }
 FUN_00aaef70();
 flags|=0x800;
 if(!bound) {InstallBoundRootZ(this,DAT_01090a78.FUN_0086b930(16));
 bound->Reset();}
 bound->radius=1.0f;
 flags|=0x2000;
}
}   // namespace f3m_00aaf1a0

// @f3 0x00aa1800 (community match, verified in this file)
namespace f3m_00aa1800 {
namespace BoxGeometry {


struct Point3
{

    float x, y, z;

    __forceinline Point3()
    {}

    Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Point3 operator-(const Point3& p) const
    {
        return Point3(x - p.x, y - p.y, z - p.z);
    }
    Point3 operator+(const Point3&) const;
    Point3 operator*(float) const;
};

struct Color
{
    float r, g, b, a;
};

extern Color DAT_00f73220;
extern Point3 DAT_011a946c, DAT_011a9478, DAT_011a9484;

struct GeometryData
{

    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    Point3* vertices;

    unsigned int unk24;

    Color* colors;

    unsigned int unk2c, unk30, unk34, unk38, unk3c;

    bool* flags;

    unsigned short* FUN_006a05c0();

    __forceinline Point3* GetVertices()
    {
        Point3* result = vertices;
        return result;
    }

    __forceinline Color* GetColors()
    {
        Color* result = colors;
        return result;
    }

    __forceinline bool* GetFlags()
    {
        bool* result = flags;
        return result;
    }
};

struct Geometry
{

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

    Point3 position;

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

    GeometryData* data;

    __forceinline GeometryData* GetData()
    {
        return data;
    }
};

struct Bound
{

    unsigned int unk00, unk04, unk08;

    Point3 center;

    float extentX, extentY, extentZ;
    void BSMultiBoundAABB_GetVertices(Point3* out)
    {
        Point3 axisX = DAT_011a946c * extentX;
        Point3 axisY = DAT_011a9478 * extentY;
        Point3 axisZ = DAT_011a9484 * extentZ;
        out[0] = center + axisX + axisY + axisZ;
        out[1] = center + axisX + axisY - axisZ;
        out[2] = center + axisX - axisY + axisZ;
        out[3] = center + axisX - axisY - axisZ;
        out[4] = center - axisX + axisY + axisZ;
        out[5] = center - axisX + axisY - axisZ;
        out[6] = center - axisX - axisY + axisZ;
        out[7] = center - axisX - axisY - axisZ;
    }

    void FUN_00aa1800(Geometry*, Geometry*, Color);
};

// @fnv 0x00c38b00
// pdb: BSMultiBoundAABB::MakeDebugGeom | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: apLines, apShape, akBaseColor
void Bound::FUN_00aa1800(Geometry* lines, Geometry* triangles, Color color)
{

    Point3 corners[8];

    BSMultiBoundAABB_GetVertices(corners);

    unsigned short edgesA[12][2] = {{0, 1}, {0, 2}, {1, 3}, {3, 2}, {4, 5}, {4, 6},
                                    {5, 7}, {7, 6}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

    unsigned short faces[12][3] = {{2, 3, 1}, {2, 1, 0}, {5, 7, 6}, {5, 6, 4}, {7, 2, 6}, {7, 3, 2},
                                   {4, 0, 5}, {5, 0, 1}, {6, 0, 4}, {6, 2, 0}, {3, 7, 1}, {7, 5, 1}};

    Color faceColor9 = color;

    Color edgeColor = DAT_00f73220;

    Point3* vertices9 = lines->GetData()->GetVertices();

    Color* colors8 = lines->GetData()->GetColors();

    bool* lineFlags9 = lines->GetData()->GetFlags();

    lines->position = center;

    for (int edge = 0; edge < 12; ++edge)
    {

        vertices9[2 * edge] = corners[edgesA[edge][0]] - center;

        colors8[2 * edge] = edgeColor;

        vertices9[2 * edge + 1] = corners[edgesA[edge][1]] - center;

        colors8[2 * edge + 1] = edgeColor;

        lineFlags9[2 * edge] = true;

        lineFlags9[2 * edge + 1] = false;
    }

    vertices9 = triangles->GetData()->GetVertices();

    colors8 = triangles->GetData()->GetColors();

    unsigned short* indices = triangles->GetData()->FUN_006a05c0();

    triangles->position = center;

    for (unsigned short triangle3 = 0; triangle3 < 12; ++triangle3)
    {

        vertices9[3 * triangle3] = corners[faces[triangle3][0]] - center;

        colors8[3 * triangle3] = faceColor9;

        vertices9[3 * triangle3 + 1] = corners[faces[triangle3][1]] - center;

        colors8[3 * triangle3 + 1] = faceColor9;

        vertices9[3 * triangle3 + 2] = corners[faces[triangle3][2]] - center;

        colors8[3 * triangle3 + 2] = faceColor9;

        indices[3 * triangle3] = 3 * triangle3;

        indices[3 * triangle3 + 1] = 3 * triangle3 + 1;

        indices[3 * triangle3 + 2] = 3 * triangle3 + 2;
    }
}


}
}   // namespace f3m_00aa1800

// @f3 0x00aadb90 (community match, verified in this file)
#include <math.h>
namespace f3m_00aadb90 {
namespace task1393 {
template <class T> class NiTArray;
class NiControllerManager;
class NiBound;
class NiStream;
class NiObjectCopyInfo;
class bhkLimitedHingeConstraint;
class bhkRigidBody;
class bhkBlendCollisionObject;
class bhkNiCollisionObject;
class NiLines;
class NiParticles;
class BSResizableTriShape;
class BSSegmentedTriShape;
class NiTriShape;
class NiTriStrips;
class NiTriBasedGeom;
class NiGeometry;
class BSMultiBoundNode;
class BSFadeNode;
class NiNode;
class NiRTTI;
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int references;
};
class NiObject : public NiRefObject
{
  public:
    virtual NiRTTI* GetType();
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
    virtual BSMultiBoundNode* GetMultiBoundNode();
    virtual NiGeometry* GetNiGeometry();
    virtual NiTriBasedGeom* GetTriBasedGeom();
    virtual NiTriStrips* GetTriStrips();
    virtual NiTriShape* GetTriShape();
    virtual BSSegmentedTriShape* GetSegmentedTriShape();
    virtual BSResizableTriShape* GetResizableTriShape();
    virtual NiParticles* GetNiParticles();
    virtual NiLines* GetNiLines();
    virtual bhkNiCollisionObject* GetCollisionObject();
    virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    virtual bhkRigidBody* GetRigidBody();
    virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    virtual NiObject* Clone(NiObjectCopyInfo*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual void RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool Compare(NiObject*);
    virtual void GetViewerStrings(NiTArray<char*>*);
    virtual void AddViewerStrings(NiTArray<char*>*);
    virtual void ProcessClone(NiObjectCopyInfo*);
    virtual void PostLinkObject(NiStream*);
    virtual bool StreamCanSkip();
    virtual NiRTTI* GetStreamableRTTI();
    virtual void SetWorldBound(NiBound*);
    virtual unsigned int GetBlockAllocationSize();
    virtual void Unk_20();
    virtual void Unk_21(unsigned int);
    virtual NiControllerManager* GetControllerManager();
};

inline float FUN_004019b0(float value) { return static_cast<float>(sqrt(static_cast<double>(value))); }
inline float FUN_004579e0(float value)
{
    return FUN_004019b0(value);
}
struct BoundPoint
{
    float x, y, z;
    BoundPoint()
    {}
    BoundPoint(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    BoundPoint FUN_00439ef0(const BoundPoint& rhs) const
    {
        return BoundPoint(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    float FUN_004a7290() const
    {
        return x * x + y * y + z * z;
    }
    float FUN_00457990() const
    {
        return FUN_004579e0(x * x + y * y + z * z);
    }
};
template <class T> struct BoundPointer
{
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};
class BSMultiBoundShape : public NiObject
{
  public:
    unsigned int flags;
    virtual int GetShapeType();
};
class BSMultiBoundAABB : public BSMultiBoundShape
{
  public:
    BoundPoint center;
    BoundPoint halfExtents;
    void BSMultiBoundAABB_GetVertices(BoundPoint*);
};
class BSMultiBoundOBB : public BSMultiBoundShape
{
  public:
    void BSMultiBoundOBB_GetVertices(BoundPoint*);
};
class BSMultiBound : public NiObject
{
  public:
    unsigned int flags;
    BoundPointer<BSMultiBoundShape> shape;
    BSMultiBoundShape* GetShape() const
    {
        return shape;
    }
};
class BSMultiBoundSphere : public BSMultiBoundShape
{
  public:
    BoundPoint center;
    float radius;
    int FUN_00aadb90(BSMultiBound*);
};
// @fnv 0x00c4ff60
// pdb: BSMultiBoundSphere::CheckBound | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aTargetBound
int BSMultiBoundSphere::FUN_00aadb90(BSMultiBound* other)
{
    int type = other->GetShape()->GetShapeType();
    if (type == 1)
    {
        BSMultiBoundAABB* box2 = static_cast<BSMultiBoundAABB*>(other->GetShape());
        BoundPoint _vertices[8];
        box2->BSMultiBoundAABB_GetVertices(_vertices);
        float radiusSquared8 = radius * radius;
        for (int i = 0; i < 8; i++)
        {
            BoundPoint diff2 = center.FUN_00439ef0(_vertices[i]);
            float distanceSquared = diff2.FUN_004a7290();
            if (distanceSquared > radiusSquared8)
                return 0;
        }
        return 2;
    }
    else if (type == 2)
    {
        BSMultiBoundOBB* box3 = static_cast<BSMultiBoundOBB*>(other->GetShape());
        BoundPoint vertices5[8];
        box3->BSMultiBoundOBB_GetVertices(vertices5);
        float radiusSquared = radius * radius;
        for (int i = 0; i < 8; i++)
        {
            BoundPoint diff = center.FUN_00439ef0(vertices5[i]);
            {
                float distanceSquared = diff.FUN_004a7290();
                if (distanceSquared > radiusSquared)
                    return 0;
            }
        }
        return 2;
    }
    else if (type == 3)
    {
        BSMultiBoundSphere* sphere = static_cast<BSMultiBoundSphere*>(other->GetShape());
        {
            BoundPoint diff3 = center.FUN_00439ef0(sphere->center);
            {
                float distance = diff3.FUN_00457990();
                if (distance + sphere->radius - radius <= 0.0)
                    return 2;
            }
        }
    }
    return 0;
}
}  // namespace task1393
}   // namespace f3m_00aadb90

// @f3 0x00ab1490 (community match, verified in this file)
#include <new>
#include <math.h>
namespace shape1414 {struct Heap {void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;}
inline void* __cdecl operator new[](unsigned n){return shape1414::DAT_01090a78.FUN_0086b930(n);}
namespace shape1414 {
struct Point3
{
    float x;
    float y;
    float z;
    static void operator delete[](void*);
    __forceinline Point3()
    {}
    __forceinline Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    static __forceinline void* operator new[](unsigned int size)
    {
        return DAT_01090a78.FUN_0086b930(size);
    }
    __forceinline Point3 operator+(const Point3& o) const
    {
        return Point3(o.x + x, o.y + y, (float)((double)o.z + z));
    }
    __forceinline Point3 operator*(float s) const
    {
        return Point3(s * x, s * y, s * z);
    }
    Point3 FUN_00439ef0(const Point3& other) const
    {
        const Point3* self = this;
        return Point3(self->x - other.x, self->y - other.y, self->z - other.z);
    }
    Point3 FUN_004b3800(const Point3& axis) const
    {
        const Point3* self = this;
        return Point3(self->y * axis.z - self->z * axis.y, self->z * axis.x - self->x * axis.z,
                      self->x * axis.y - self->y * axis.x);
    }
    __declspec(noinline) void FUN_00468d00() {float n=(float)sqrt(x*x+y*y+z*z); if(n>1e-6f){float r=1.0f/n;x*=r;y*=r;z*=r;}else{x=0;y=0;z=0;}}
    Point3 FUN_00439e90(const Point3& shift) const {return Point3(x+shift.x,y+shift.y,z+shift.z);}
};

struct FilterData
{
    void FUN_0046c350();
    unsigned int collisionLayer;
    unsigned int group;
    unsigned int flags;
    unsigned int subsystem;

    static __forceinline void* operator new[](unsigned int size)
    {
        return DAT_01090a78.FUN_0086b930(size);
    }
    static void operator delete[](void*);
};
extern void* __cdecl FUN_00bffa60(void*,const void*,unsigned);extern unsigned char DAT_00e8af40;extern void* __cdecl FUN_0089eb90(unsigned);
void __stdcall FUN_00401020(void*,unsigned,unsigned,void(FilterData::*)());
struct FilterArray {FilterData values[8];FilterArray(){FUN_00401020(values,16,8,&FilterData::FUN_0046c350);}static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}static void operator delete(void*);};
struct CollisionShape
{
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
};
struct CollisionGenerator : CollisionShape
{
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
    static __forceinline void* operator new(unsigned int size)
    {
        return FUN_0089eb90(size);
    }
    static void operator delete(void*);
    CollisionGenerator(unsigned int count, Point3* vertices, int unused, FilterData* _filters, int a, int b, int c,
                       int d, void* data);
};
// @fnv 0x00c55d50
// pdb: BSTestObjects::CreateBox | BSTestObjects.obj | fnv360_0822_retail, caller, medium
// pdb params: arLeftCorner, arRightCorner, afForwardDepth, afBackwardDepth, afUpwardHeight, afDownwardHeight, apLeftColor, apRightColor
CollisionShape* __cdecl FUN_00ab1490(Point3* start, Point3* end, float forwardExtent, float backwardExtent,
                                     float upExtent, float downExtent, FilterData* nearFilter, FilterData* farFilter)
{
    Point3* verticesX;
    verticesX = new Point3[8];
    Point3 directionX = start->FUN_00439ef0(*end);
    Point3 verticalAxisB(0.0f, 0.0f, 1.0f);
    Point3 crossVal2 = directionX.FUN_004b3800(verticalAxisB);
    crossVal2.z = 0.0f;
    crossVal2.FUN_00468d00();
    Point3 forwardVectorB = crossVal2 * forwardExtent;
    Point3 reverseVector2 = crossVal2 * (-backwardExtent);
    Point3 offset(0.0f, 0.0f, upExtent);
    Point3 below2(0.0f, 0.0f, -downExtent);
    verticesX[0] = offset + (reverseVector2 + *end);
    verticesX[1] = offset + (forwardVectorB + *end);
    verticesX[2] = below2 + (reverseVector2 + *end);
    verticesX[3] = below2 + (forwardVectorB + *end);
    verticesX[4] = offset + (reverseVector2 + *start);
    verticesX[5] = offset + (forwardVectorB + *start);
    verticesX[6] = below2 + (reverseVector2 + *start);
    verticesX[7] = below2 + (forwardVectorB + *start);
    FilterData* _filters = 0;
    if (nearFilter || farFilter)
    {
        _filters = reinterpret_cast<FilterData*>(new FilterArray);
        if (nearFilter && !farFilter)
            farFilter = nearFilter;
        else if (farFilter && !nearFilter)
            nearFilter = farFilter;
        for (unsigned int indexC = 0; indexC < 4; ++indexC)
            _filters[indexC] = *farFilter;
        for (unsigned int index7 = 4; index7 < 8; ++index7)
            _filters[index7] = *nearFilter;
    }
    unsigned short* pData6 = new unsigned short[36];
    FUN_00bffa60(pData6, &DAT_00e8af40, 0x48);
    CollisionGenerator* shape2 = new CollisionGenerator(8, verticesX, 0, _filters, 0, 0, 0, 12, pData6);
    shape2->slot0e8();
    return shape2;
}

}

// @f3 0x00ab3850 (community match, verified in this file)
#include <math.h>
namespace task1412 {
struct Heap {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned) throw();
void __cdecl FUN_0089e890(void*);
struct ArrayMem {static void* operator new[](unsigned n) throw() {return DAT_01090a78.FUN_0086b930(n);} static void operator delete[](void* p) {DAT_01090a78.FUN_0086ba60(p);} };
struct Vec3 {
 static void* operator new[](unsigned n) throw() {return DAT_01090a78.FUN_0086b930(n);} static void operator delete[](void* p) {DAT_01090a78.FUN_0086ba60(p);}
 float x,y,z;
 Vec3() {}
 Vec3(float a,float b,float c) : x(a),y(b),z(c) {}
 Vec3 FUN_00439ef0(const Vec3& v) const {return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 FUN_00439e90(const Vec3& v) const {return Vec3(x+v.x,y+v.y,z+v.z);}
 Vec3 FUN_004b3800(const Vec3& v) const {return Vec3(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);}
 float NiPoint3_UnitizeGetLength();
 void FUN_00468d00();
 Vec3 operator*(float f) const {return Vec3(f*x,f*y,f*z);}
 Vec3 operator+(const Vec3& v) const {return Vec3(v.x+x,v.y+y,v.z+z);}
 Vec3 operator-(const Vec3& v) const {return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3& operator*=(float f) {x*=f;y*=f;z*=f;return *this;}
};
extern const float DAT_00db88e0;
// pdb: NiPoint3::UnitizeGetLength | TES.obj | fnv360_0822_debug, call_seq + skyrim(caller), high
inline float Vec3::NiPoint3_UnitizeGetLength() {
 float squared=x*x+y*y+z*z;
 float magnitude=static_cast<float>(sqrt(static_cast<double>(squared)));
 if(magnitude>DAT_00db88e0) {float inverse=1.0f/magnitude;x*=inverse;y*=inverse;z*=inverse;}
 else {x=0.0f;y=0.0f;z=0.0f;magnitude=0.0f;}
 return magnitude;
}
struct FUN_0046c350 { static void* operator new[](unsigned n) throw() {return DAT_01090a78.FUN_0086b930(n);} static void operator delete[](void* p) {DAT_01090a78.FUN_0086ba60(p);}float r,g,b,a;FUN_0046c350();};
typedef FUN_0046c350 Color4;
struct Vec2 {float x,y;};
struct ObjectMem {static void* operator new(unsigned n) throw() {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089e890(p);} };
struct FUN_0083f490 : ObjectMem {
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
 virtual void vdc();
 virtual void ve0();
 virtual void ve4();
 virtual void Update();
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
 unsigned unkb8;
 unsigned unkbc;
 unsigned unkc0;
 FUN_0083f490(unsigned short,Vec3*,Vec3*,Color4*,Vec2*,bool,bool,unsigned short,unsigned short*);
};
typedef FUN_0083f490 Mesh;
struct FUN_0082ea60 : ObjectMem {
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
 virtual void AttachChildInAvailableSlot(Mesh*,bool);
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
 FUN_0082ea60(int);
};
typedef FUN_0082ea60 MeshRoot;
Mesh* __cdecl FUN_00ab1490(const Vec3&,const Vec3&,float,float,float,float,const Color4*,const Color4*);
void* __cdecl FUN_0089e810(unsigned);
void* __cdecl FUN_00bffa60(void*,const void*,unsigned);
extern const unsigned short DAT_00e8aff0[];
extern const unsigned short DAT_00e8af40[];
inline Mesh* __cdecl FUN_00ab1490(const Vec3& start, const Vec3& end, float forwardExtent, float backwardExtent,
                                     float upExtent, float downExtent, const Color4* nearFilter, const Color4* farFilter)
{
    Vec3* verticesX;
    verticesX = new Vec3[8];
    Vec3 directionX = start.FUN_00439ef0(end);
    Vec3 verticalAxisB(0.0f, 0.0f, 1.0f);
    Vec3 crossVal2 = directionX.FUN_004b3800(verticalAxisB);
    crossVal2.z = 0.0f;
    crossVal2.FUN_00468d00();
    Vec3 forwardVectorB = crossVal2 * forwardExtent;
    Vec3 reverseVector2 = crossVal2 * (-backwardExtent);
    Vec3 offset(0.0f, 0.0f, upExtent);
    Vec3 below2(0.0f, 0.0f, -downExtent);
    verticesX[0] = offset + (reverseVector2 + end);
    verticesX[1] = offset + (forwardVectorB + end);
    verticesX[2] = below2 + (reverseVector2 + end);
    verticesX[3] = below2 + (forwardVectorB + end);
    verticesX[4] = offset + (reverseVector2 + start);
    verticesX[5] = offset + (forwardVectorB + start);
    verticesX[6] = below2 + (reverseVector2 + start);
    verticesX[7] = (forwardVectorB + start).FUN_00439e90(below2);
    Color4* _filters = 0;
    if (nearFilter || farFilter)
    {
        _filters = new Color4[8];
        if (nearFilter && !farFilter)
            farFilter = nearFilter;
        else if (farFilter && !nearFilter)
            nearFilter = farFilter;
        for (unsigned int indexC = 0; indexC < 4; ++indexC)
            _filters[indexC] = *farFilter;
        for (unsigned int index7 = 4; index7 < 8; ++index7)
            _filters[index7] = *nearFilter;
    }
    unsigned short* pData6 = (unsigned short*)DAT_01090a78.FUN_0086b930(72);
    FUN_00bffa60(pData6, DAT_00e8af40, 0x48);
    Mesh* shape2 = new Mesh(8, verticesX, 0, _filters, 0, 0, 0, 12, pData6);
    shape2->Update();
    return shape2;
}

// @fnv 0x00c5a0f0
// pdb: BSTestObjects::Create3DArrow | BSTestObjects.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStart, arFinish, afSize, afHeight, apStartColor, apEndColor
MeshRoot* FUN_00ab3850(const Vec3& start, const Vec3& end, float width, float height, const Color4* shaftColor,
                       const Color4* tipColor)
{
    MeshRoot* rootNode4 = new MeshRoot(0);
    Vec3 direction6 = end.FUN_00439ef0(start);
    float lengthX = direction6.NiPoint3_UnitizeGetLength();
    float length = 0.0f;
    float tipLength3 = width * 6.0;
    if (lengthX > tipLength3)
        length = lengthX - tipLength3;
    else
        tipLength3 = lengthX;
    const Vec3 nearEnd4 = start.FUN_00439e90(direction6 * length);
    if (length > 0.0)
    {
        Mesh* shaft2 = FUN_00ab1490(start, nearEnd4, width, width, height, 0.0f, shaftColor, tipColor);
        rootNode4->AttachChildInAvailableSlot(shaft2, true);
    }
    Vec3* verticesX3 = new Vec3[6];
    Vec3 up4(0.0f, 0.0f, 1.0f);
    Vec3 sideC7 = direction6.FUN_004b3800(up4);
    sideC7 *= width * 4.0;
    Vec3 elevation5(0.0f, 0.0f, height);
    verticesX3[0] = elevation5 + end;
    verticesX3[1] = elevation5 + (sideC7 + nearEnd4);
    verticesX3[2] = end;
    verticesX3[3] = sideC7 + nearEnd4;
    verticesX3[4] = elevation5 + (nearEnd4 - sideC7);
    verticesX3[5] = nearEnd4 - sideC7;
    if (shaftColor && !tipColor)
        tipColor = shaftColor;
    Color4* colors = tipColor ? new Color4[6] : 0;
    if (colors)
    {
        for (unsigned int i2 = 0; i2 < 6; ++i2)
            colors[i2] = *tipColor;
    }
    unsigned short* indices_10 = (unsigned short*)FUN_0089e810(48);
    FUN_00bffa60(indices_10, DAT_00e8aff0, 48);
    Mesh* meshTmp = new Mesh(6, verticesX3, 0, colors, 0, 0, 0, 8, indices_10);
    meshTmp->Update();
    rootNode4->AttachChildInAvailableSlot(meshTmp, true);
    return rootNode4;
}

}

// @f3 0x00aa9660 (community match, verified in this file)
extern int DAT_0116d700;
namespace f3m_00aa9660 {
namespace task1605 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct StandRTTI
{
    const char* m_pcName;
    const StandRTTI* m_pBaseRTTI;
};
struct StandRef
{
    virtual ~StandRef();
    virtual void DeleteThis();
    virtual const StandRTTI* GetRTTI() const;
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
template <class T> struct StandPtr
{
    T* m_pObject;
    StandPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~StandPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};
struct StandNode;
struct StandChildren
{
    virtual ~StandChildren();
    StandRef** data;
    unsigned short capacity;
    unsigned short firstFree;
    unsigned short size;
    unsigned short grow;
    StandRef* const& GetAt(unsigned int i) const
    {
        StandRef* const& item = data[i];
        return item;
    }
};
struct StandNode : StandRef
{
    virtual void Unk0c();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1c();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2c();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3c();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4c();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5c();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6c();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7c();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8c();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9c();
    virtual void Unka0();
    virtual void Unka4();
    virtual void Unka8();
    virtual void Unkac();
    virtual void Unkb0();
    virtual void Unkb4();
    virtual void Unkb8();
    virtual void Unkbc();
    virtual void Unkc0();
    virtual void Unkc4();
    virtual void Unkc8();
    virtual void Unkcc();
    virtual void Unkd0();
    virtual void Unkd4();
    virtual void Unkd8();
    virtual void Unkdc();
    virtual void Unke0();
    virtual void Unke4();
    virtual void Unke8();
    virtual void RemoveAt(unsigned int i, StandPtr<StandRef>& removed);
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
    StandChildren children;
    float time;
    float UpdateTime(float f)
    {
        float delta = time != 0.0f ? f - time : time;
        time = f;
        return delta;
    }
    StandRef* GetChild(unsigned int i) { return children.data[i]; }
    void SetTime(float f)
    {
        time = f;
        if (time < 0.0f)
            time = 0.0f;
    }
    bool Expired() const
    {
        return time == 0.0f;
    }
    void FUN_00aa9660(float);
};
__forceinline bool IsKindOfType(const StandRTTI* target, const StandRef* object)
{
    const StandRTTI* rtti = object->GetRTTI();
    while (rtti)
    {
        if (rtti == target)
            return true;
        rtti = rtti->m_pBaseRTTI;
    }
    return false;
}
__forceinline StandNode* CastNode(StandRef* object)
{
    if (!object)
        return 0;
    return IsKindOfType(reinterpret_cast<const StandRTTI*>(&DAT_0116d700), object) ? static_cast<StandNode*>(object) : 0;
}
// @fnv 0x00c44ed0
// pdb: BSTempNodeManager::RemoveExpired | BSTempNodeManager.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSOrderedNode::UpdateOrderedBound)
// pdb params: afTime
void StandNode::FUN_00aa9660(float f)
{
    StandPtr<StandRef> spRemoved;
    float delta = UpdateTime(f);
    {
        unsigned int i = children.firstFree;
        while (i--)
        {
            StandRef* object = GetChild(i);
            StandNode* child = CastNode(object);
            if (child)
            {
                child->SetTime(child->time - delta);
                if (child->Expired())
                    RemoveAt(i, spRemoved);
            }
        }
    }
}

}
}   // namespace f3m_00aa9660

// @f3 0x00ab0630 (community match, verified in this file)
namespace qab0630 {
struct Heap {void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
struct Color {float r,g,b;Color() {}};
struct Entry {
 Color color; unsigned short value; unsigned char flag;
 Entry(int v) {value=(unsigned short)v;flag=0;}
 __declspec(noinline) bool FUN_00ab0190(const Entry& rhs) {return !(color.r==rhs.color.r && color.g==rhs.color.g && color.b==rhs.color.b && flag==rhs.flag && value==rhs.value);}
 bool FUN_00ab0190(const Entry& rhs) const;
 bool operator==(const Entry& rhs) const;
};
Entry* __cdecl FUN_00ab0440(unsigned);
struct Array {
 unsigned table; unsigned data; unsigned short capacity,size,count,grow;
 void FUN_00ab0630(unsigned);
};
// pdb: NiTArray<FurnitureMark,NiTNewInterface<FurnitureMark> >::SetSize | BSFurnitureMarker.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: FurnitureMark::LoadBinary)
// pdb params: uiMaxSize
void Array::FUN_00ab0630(unsigned n) {
 if(n==capacity) return;
 unsigned short i;
 if(n<size) {
  for(i=(unsigned short)n;i<size;i++) {
   if(((Entry*)data)[i].FUN_00ab0190(Entry(0))) { ((Entry*)data)[i]=Entry(0);count--; }
  }
  size=(unsigned short)n;
 }
 Entry* old=(Entry*)data;
 capacity=(unsigned short)n;
 if(n>0) {
  data=(unsigned)FUN_00ab0440(capacity);
  for(i=0;i<size;i++) ((Entry*)data)[i]=old[i];
  for(i=size;i<capacity;i++) ((Entry*)data)[i]=Entry(0);
 } else data=0;
 DAT_01090a78.FUN_0086ba60(old);
}
}

// @f3 0x00aa2220 (community match, verified in this file)
namespace room_cleanup1974 {
struct Heap { void FUN_0086ba60(void*); }; extern Heap DAT_01090a78;
struct Base {virtual ~Base(); unsigned int unk04;
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
unsigned int unkB0; };
struct Array12 {void* data;unsigned int size,capacity;void FUN_00bd12d0();~Array12() throw();};
struct ArrayD0 {void* data;unsigned int size,capacity;void FUN_00abb340();~ArrayD0();};
struct Culling {void FUN_00aa8280();};
struct Lights;
struct Dispatch {void (__thiscall* destroy)(Lights*,unsigned int);void* (__thiscall* allocate)(Lights*,unsigned int);void (__thiscall* release)(Lights*,void*);};
extern const Dispatch DAT_00e894a0;
struct Lights {const Dispatch* vtable;void* data;unsigned int size,capacity;
 __forceinline void Clear(){if(data){vtable->release(this,data);data=0;capacity=0;size=0;}}
 __forceinline ~Lights(){vtable=&DAT_00e894a0;if(data){vtable->release(this,data);data=0;capacity=0;size=0;}}
};
struct Room:Base {Array12 first,second;Culling* culling;ArrayD0 third;Lights lights;virtual ~Room();};
// pdb: BSMultiBoundRoom::~BSMultiBoundRoom | BSMultiBoundRoom.obj | fnv360_0822_retail, call_seq, high
Room::~Room(){first.FUN_00bd12d0();second.FUN_00bd12d0();third.FUN_00abb340();lights.Clear();Culling* owned=culling;if(owned){owned->FUN_00aa8280();DAT_01090a78.FUN_0086ba60(owned);culling=0;}}
}

// @f3 0x00aa20a0 (community match, verified in this file)
namespace qaa20a0 {
struct Point {float x,y,z;};
struct Bound {Point center;float radius;void FUN_0084a3a0(const Bound&);};
extern Bound DAT_0108edc8;extern Point DAT_0108ec68;
struct Heap{void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;
struct Provider{
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
virtual void GetBound(Bound&);
};
struct Controller{int unk00,unk04,unk08;Provider* provider;};
struct Link{Link* next;int unk04;Controller* controller;};
struct Node{
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
virtual void SetBound(Bound*);
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
Bound* bound;int unk24,unk28,unk2c;unsigned flags;
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
Node** children;unsigned short capacity,size,used,grow;Controller* controller;
int unkb0;
int unkb4;
int unkb8;
int unkbc;
int unkc0;
int unkc4;
int unkc8;
int unkcc;
Link* head;int unkD4;unsigned count;
void FUN_004d3210();
unsigned char Flag(){return static_cast<unsigned char>(flags>>19)&1;}
void FUN_00aa20a0();
};
// pdb: BSMultiBoundRoom::UpdateWorldBound | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable_prefix, medium
void Node::FUN_00aa20a0()
{
    const Bound* a0;
    float aAcoustic;
    Node** aATmp;
    Bound* a2;
    float aAction;
    const Bound* aA6;
    int a114;
    int a3;
    int aActorList;
    float aActive;
    Node** aAct;
    Bound* a4;
    Provider* a2_3;
    Controller* a1c8;
    Controller** aAVal;
    Link* aAB;
    int aAEPos;
    int a60;
    int a5;
    Provider* aA3;
    Controller* aAX;
    Controller* a9;
    Node* a7;
    unsigned int a8;
    unsigned int aA5;
    Bound aA;
    Link* aA2;
    Provider* aAa;
    bool first;
    first = true;
    a9 = controller;
    if (a9)
    {
        aAX = controller;
        aA3 = aAX->provider;
        aAa = aA3;
        if (aAa)
        {
            FUN_004d3210();
            aAa->GetBound(*bound);
            if (!(unsigned char)(unsigned int)(count == 0))
            {
                aAB = head;
                aA2 = aAB;
                while (aA2)
                {
                    aAVal = &aA2->controller;
                    aA2 = aA2->next;
                    a1c8 = *aAVal;
                    a2_3 = a1c8->provider;
                    aAa = a2_3;
                    aAa->GetBound(aA);
                    bound->FUN_0084a3a0(aA);
                }
            }
            first = false;
        }
    }
    if (first)
    {
        if (bound && Flag())
        {
            a4 = bound;
            a4->radius = 0.0f;
        }
        a8 = size;
        for (aA5 = 0; aA5 < a8; ++aA5)
        {
            aAct = &children[aA5];
            a7 = *aAct;
            if (a7 && ((a7->bound && ((aActive = a7->bound->radius), (double)aActive != 0.0)) ? 1 : 0))
            {
                if (!bound) {
 Bound* allocated=(Bound*)DAT_01090a78.FUN_0086b930(sizeof(Bound));
 SetBound(allocated);Bound* dest=bound;dest->center=DAT_0108ec68;dest->radius=0.0f;
}
                aA6 = a7->bound ? a7->bound : &DAT_0108edc8;
                a2 = bound;
                aAction = aA6->radius;
                a2->center = aA6->center;
                a2->radius = aAction;
                ++aA5;
                break;
            }
        }
        for (; aA5 < a8; ++aA5)
        {
            aATmp = &children[aA5];
            a7 = *aATmp;
            if (a7 && ((a7->bound && ((aAcoustic = a7->bound->radius), (double)aAcoustic != 0.0)) ? 1 : 0))
            {
                a0 = a7->bound ? a7->bound : &DAT_0108edc8;
                bound->FUN_0084a3a0(*a0);
            }
        }
    }
}

}

// @f3 0x00ab8b90 (community match, verified in this file)
extern const char* DAT_0116eb74;
namespace f3m_00ab8b90 {
namespace f3m_00ab8b90 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847e70(const char* label, int value);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }
    __forceinline void AddInline(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        if (index >= firstFree) {
            firstFree = index + 1;
            if (value != 0)
                count++;
        } else {
            if (value != 0) {
                if (buffer[index] == 0)
                    count++;
            } else {
                if (buffer[index] != 0)
                    count--;
            }
        }
        buffer[index] = value;
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

__declspec(noinline) void ViewerStrings::FUN_005b3880(unsigned int index,char* const& value)
{
    if(index>=firstFree) {
        firstFree=index+1;
        if(value) ++count;
    } else {
        if(value) { if(!buffer[index]) ++count; }
        else { if(buffer[index]) --count; }
    }
    buffer[index]=value;
}

struct Entry { int unk00; int unk04; int unk08; };

class Controller {
public:
    void FUN_00ac6410(ViewerStrings* strings);
    char* FUN_00ab7ed0(const char* label, unsigned int value);
    void FUN_00ab8b90(ViewerStrings* strings);
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

    unsigned int arrayType;
    int unk5c;
    Entry** entries;
    unsigned short unk64;
    unsigned short entryCount;
};

// pdb: BSPSysArrayEmitter::GetViewerStrings | BSPSysArrayEmitter.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void Controller::FUN_00ab8b90(ViewerStrings* strings)
{
    FUN_00ac6410(strings);
    strings->Add(FUN_00847b50(DAT_0116eb74));
    unsigned int typeValue=arrayType;
    strings->Add(FUN_00ab7ed0("ArrayType", typeValue));
    unsigned int i = entryCount;
    while (i != 0) {
        Entry* e = entries[--i];
        if (e) {
            int elementValue=e->unk08;
            strings->AddInline(FUN_00847e70("E", elementValue));
        }
    }
}
}
}   // namespace f3m_00ab8b90

// @f3 0x00ab7f60 (community match, verified in this file)
namespace EmissionInterpolation {
extern "C" int __cdecl rand();
struct EmissionPoint {
    float x,y,z;
    EmissionPoint() {}
    EmissionPoint(float a,float b,float c):x(a),y(b),z(c){}
    EmissionPoint operator-(const EmissionPoint& p) const { return EmissionPoint(x-p.x,y-p.y,z-p.z); }
    EmissionPoint operator+(const EmissionPoint& p) const { return EmissionPoint(x+p.x,y+p.y,z+p.z); }
    EmissionPoint operator*(float f) const { return EmissionPoint(x*f,y*f,z*f); }
    void FUN_006b1f50(float);
};
extern EmissionPoint DAT_0108ec68;
struct EmissionRotation { float matrix[3][3];EmissionPoint FUN_004752c0(const EmissionPoint&); };
struct EmissionObject {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    EmissionObject* parent;
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
    EmissionRotation rotation;
    EmissionPoint position;
    float scale;
};
struct EmissionController {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EmissionObject* target;
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
    unsigned int arrayType;
    void FUN_00ab7f60(EmissionObject*,EmissionPoint*,EmissionPoint*);
};
// pdb: BSPSysArrayEmitter::GetPointFromObject | BSPSysArrayEmitter.obj | fnv360_0822_retail, objrun, medium
// pdb params: pObject, arPos, arVel
void EmissionController::FUN_00ab7f60(EmissionObject* object,EmissionPoint* position,EmissionPoint* direction)
{
    if(object) {
    EmissionObject* parent=object->parent;
    if(arrayType!=1 && parent) {
        *position=object->position-parent->position;
        float random=(float)(rand()/32767.0);
        *position=parent->position+(*position*random);
        if(target) {
            float scale=target->scale;
            if(scale!=1.0f && scale!=0.0f) position->FUN_006b1f50(1.0f/scale);
        }
    } else {
        *position=object->position;
        if(arrayType==1) *direction=object->rotation.FUN_004752c0(*direction);
    }
    } else *position=DAT_0108ec68;
}

}

// @f3 0x00ab96c0 (community match, verified in this file)
#include <new>
namespace f3m_00ab96c0 {
namespace decal_load1998 {
struct Heap{void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;
struct ComponentSize{unsigned int size;__forceinline ComponentSize(unsigned int value):size(value){}__forceinline operator const unsigned int*()const{return &size;}};
struct Binary{unsigned int unk00,position;unsigned int(__cdecl* read)(Binary*,void*,unsigned int,const unsigned int*,unsigned int);};
struct Stream{unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14C;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15C;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16C;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17C;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18C;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19C;unsigned int unk1A0;unsigned int unk1A4;unsigned int unk1A8;unsigned int unk1AC;unsigned int unk1B0;unsigned int unk1B4;unsigned int unk1B8;unsigned int unk1BC;unsigned int unk1C0;unsigned int unk1C4;unsigned int unk1C8;unsigned int unk1CC;unsigned int unk1D0;unsigned int unk1D4;unsigned int unk1D8;unsigned int unk1DC;unsigned int unk1E0;unsigned int unk1E4;unsigned int unk1E8;unsigned int unk1EC;unsigned int unk1F0;unsigned int unk1F4;unsigned int unk1F8;unsigned int unk1FC;unsigned int unk200;unsigned int unk204;unsigned int unk208;unsigned int unk20C;unsigned int unk210;unsigned int unk214;unsigned int unk218;unsigned int unk21C;unsigned int unk220;unsigned int unk224;unsigned int unk228;unsigned int unk22C;unsigned int unk230;unsigned int unk234;unsigned int unk238;unsigned int unk23C;unsigned int unk240;unsigned int unk244;unsigned int unk248; Binary* binary;__forceinline void Read(void* destination,unsigned int bytes,unsigned int componentSize){Binary* b=binary;b->position+=b->read(b,destination,bytes,ComponentSize(componentSize),1);}__forceinline void ReadPointArray(void* destination,const unsigned short& pointCount){Binary* b=binary;unsigned int bytes=pointCount*3*sizeof(float);b->position+=b->read(b,destination,bytes,ComponentSize(4),1);}};
struct Point3{float x,y,z;__forceinline Point3(){}};
struct BoxPoints{unsigned short count,unk02;Point3 first[8],second[8];BoxPoints* FUN_00ab93e0();};
__forceinline BoxPoints* CreateBox(){BoxPoints* p=(BoxPoints*)DAT_01090a78.FUN_0086b930(sizeof(BoxPoints));if(p){new(p) BoxPoints;return p->FUN_00ab93e0();}return 0;}
struct DecalExtra{unsigned int unk00,unk04,unk08,unk0C;unsigned short count,unk12;BoxPoints* groups[8];void* listHead;void* listTail;unsigned int listCount;void FUN_00863fa0(Stream*);void BSDecalPlacementVectorExtraData_LoadBinary(Stream*);};
typedef char BoxSize[(sizeof(BoxPoints)==0xc4)?1:-1];typedef char ExtraSize[(sizeof(DecalExtra)==0x40)?1:-1];
// pdb: BSDecalPlacementVectorExtraData::LoadBinary | BSDecalPVExtraData.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun), high
void DecalExtra::BSDecalPlacementVectorExtraData_LoadBinary(Stream* stream){FUN_00863fa0(stream);stream->Read(&count,2,2);for(int i=0;i<count;++i){groups[i]=CreateBox();stream->Read(&groups[i]->count,2,2);stream->ReadPointArray(groups[i]->first,groups[i]->count);stream->ReadPointArray(groups[i]->second,groups[i]->count);}}
}
}   // namespace f3m_00ab96c0

// @f3 0x00aa91e0 (community match, verified in this file)
extern "C" char DAT_01090a78;
extern unsigned int DAT_00e27ed4;
extern char DAT_010c1e44[];
namespace f3m_00aa91e0 {
struct GraphRecord { int kind, yes, no; };
struct RecordArray {
    int unk00;
    GraphRecord* data;
    int unk08;
    int capacity;
    void FUN_005bb760(int, bool);
};
struct GraphHeap {
    void* ScrapHeap_Allocate(unsigned int, unsigned int);
    void ScrapHeap_Deallocate(void*);
};
struct GraphMemory { GraphHeap* FUN_0086bcb0(); };
void __cdecl FUN_005b5e40(const char*);
void* __cdecl FUN_00c00610(void*, int, unsigned int);
struct ControlGraph {
    bool ready;
    int unk04, unk08, unk0c, unk10;
    RecordArray records;
    int unk24;
    int count;
    int first;
    void FUN_00aa91e0();
};

// @fnv 0x00c49850
// pdb: BSCompoundFrustum::PrethreadOpList | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
void ControlGraph::FUN_00aa91e0() {
    if (!ready && count > 0) {
        GraphRecord* local60;
        GraphRecord* recordE4;
        GraphRecord* recordD5;
        GraphRecord* recordCTmp;
        GraphRecord* recordB3;
        GraphRecord* local57;
        int grow8;
        int capacity;
        int local55;
        int local53;
        int kd;
        int j8;
        int i22;
        bool found3;
        GraphHeap* heapA;
        int* local26;
        int depth5;
        int* endsX;
        int* groups_;
        int endIndex9;
        int stackCapacity7;
        int local19;
        int local8;
        endIndex9 = count + 1;
        local19 = count + 2;
        capacity = records.capacity;
        if (count + 3 >= capacity) {
            grow8 = records.capacity;
            records.FUN_005bb760(grow8 + 10, true);
        }
        records.data[count].kind = 1;
        records.data[count + 1].kind = 2;
        records.data[count + 2].kind = 3;
        stackCapacity7 = count / 2;
        heapA = ((GraphMemory*)&DAT_01090a78)->FUN_0086bcb0();
        local26 = (int*)heapA->ScrapHeap_Allocate(stackCapacity7 * sizeof(int), DAT_00e27ed4);
        local26[0] = 0;
        depth5 = 0;
        local8 = 1;
        endsX = (int*)heapA->ScrapHeap_Allocate(stackCapacity7 * sizeof(int), DAT_00e27ed4);
        groups_ = (int*)heapA->ScrapHeap_Allocate(stackCapacity7 * sizeof(int), DAT_00e27ed4);
        for (i22 = 0; i22 < count + 1; ++i22) {
            switch (records.data[i22].kind) {
            case 1:
                endsX[0] = i22;
                if (depth5 != 0) { count = 0; return; }
                break;
            case 4:
            case 5:
                ++depth5;
                local26[depth5] = local8;
                ++local8;
                break;
            case 6:
                endsX[local26[depth5]] = i22;
                --depth5;
                break;
            case 7:
            case 8:
                ++i22;
                break;
            }
        }
        FUN_00c00610(local26, 0, stackCapacity7 * sizeof(int));
        local26[0] = 0;
        groups_[0] = 0;
        depth5 = 1;
        local8 = 1;
        found3 = false;
        for (j8 = 0; j8 < count + 1; ++j8) {
            switch (records.data[j8].kind) {
            case 1:
                records.data[j8].yes = endIndex9;
                records.data[j8].no = local19;
                break;
            case 6:
                --depth5;
                switch (local26[depth5 - 1]) {
                case 0:
                    records.data[j8].yes = j8 + 1;
                    records.data[j8].no = j8 + 1;
                    break;
                case 5:
                    records.data[j8].yes = endsX[groups_[depth5 - 1]];
                    records.data[j8].no = j8 + 1;
                    break;
                case 4:
                    records.data[j8].yes = j8 + 1;
                    records.data[j8].no = endsX[groups_[depth5 - 1]];
                    break;
                }
                break;
            case 7:
            case 8:
                if (!found3) { first = j8; found3 = true; }
                switch (local26[depth5 - 1]) {
                case 0:
                    records.data[j8].yes = count;
                    records.data[j8].no = count;
                    break;
                case 5:
                    records.data[j8].yes = endsX[groups_[depth5 - 1]];
                    records.data[j8].no = j8 + 2;
                    break;
                case 4:
                    records.data[j8].yes = j8 + 2;
                    records.data[j8].no = endsX[groups_[depth5 - 1]];
                    break;
                }
                ++j8;
                break;
            case 4:
            case 5:
                local26[depth5] = records.data[j8].kind;
                groups_[depth5] = local8;
                ++local8;
                ++depth5;
                records.data[j8].yes = j8 + 1;
                records.data[j8].no = j8 + 1;
                break;
            }
        }
        if (!found3) {
            first = endIndex9;
            ready = true;
            return;
        }
        kd = first;
        if (kd < count) {
        int byteOffset = kd * sizeof(GraphRecord);
        do {
            switch ((*(GraphRecord*)((char*)records.data + byteOffset)).kind) {
            case 7:
            case 8:
                while (true) {
                    local57 = &(*(GraphRecord*)((char*)records.data + byteOffset));
                    local53 = records.data[local57->yes].kind;
                    if (local53 == 7 || local53 == 8 || local53 == 2 || local53 == 3) break;
                    else {
                        recordB3 = &(*(GraphRecord*)((char*)records.data + byteOffset));
                        recordCTmp = &records.data[recordB3->yes];
                        (*(GraphRecord*)((char*)records.data + byteOffset)).yes = recordCTmp->yes;
                    }
                }
                while (true) {
                    recordD5 = &(*(GraphRecord*)((char*)records.data + byteOffset));
                    local55 = records.data[recordD5->no].kind;
                    if (local55 == 7 || local55 == 8 || local55 == 2 || local55 == 3) break;
                    else {
                        recordE4 = &(*(GraphRecord*)((char*)records.data + byteOffset));
                        local60 = &records.data[recordE4->no];
                        (*(GraphRecord*)((char*)records.data + byteOffset)).no = local60->no;
                    }
                }
                ++kd;
                byteOffset += sizeof(GraphRecord);
                break;
            }
            ++kd;
            byteOffset += sizeof(GraphRecord);
        } while (kd < count);
        }
        heapA->ScrapHeap_Deallocate(local26);
        heapA->ScrapHeap_Deallocate(endsX);
        heapA->ScrapHeap_Deallocate(groups_);
    }
    ready = true;
}
}   // namespace f3m_00aa91e0

// @f3 0x00aa2d70 (community match, verified in this file)
#include <stddef.h>
extern __declspec(thread) int DAT_0117c298;
namespace f3m_00aa2d70 {
namespace MapMemory2022 {struct Heap {void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;}
void* __cdecl operator new(size_t bytes){return MapMemory2022::DAT_01090a78.FUN_0086b930(bytes);}
void* __cdecl operator new[](size_t bytes){return MapMemory2022::DAT_01090a78.FUN_0086b930(bytes);}
namespace MapConstruct2022 {
struct InterfacedClass {virtual ~InterfacedClass();};
struct MemoryContext {int saved;MemoryContext(){saved=DAT_0117c298;DAT_0117c298=6;}~MemoryContext(){DAT_0117c298=saved;}};
struct Node;
struct FUN_0059acc0 {Node* head;FUN_0059acc0();};
struct FUN_005e5280 {unsigned int unk00,unk04,unk08,unk0C;FUN_005e5280(unsigned int);};
struct Map:InterfacedClass {Node** deletedBuffers;unsigned int bucketCount;FUN_0059acc0* buckets;unsigned int deleteBatchSize;FUN_005e5280* manager;volatile unsigned int itemUpdates;Map(unsigned int,unsigned int,unsigned int);virtual ~Map();};
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMap<__int64,NiPointer<BSTask<__int64> > > | IOManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiMaxThreads, aiNumBuckets, aiDeleteBatchSize
Map::Map(unsigned int threads,unsigned int count,unsigned int batch){
 MemoryContext context;
 itemUpdates=0;
 bucketCount=count;
 buckets=new FUN_0059acc0[bucketCount];
 deletedBuffers=new Node*[threads*3];
 deleteBatchSize=batch;
 manager=new FUN_005e5280(threads);
}
}
}   // namespace f3m_00aa2d70

// @f3 0x00aa28f0 (community match, verified in this file)
#include <stddef.h>
extern __declspec(thread) int DAT_0117c298;
namespace f3m_00aa28f0 {
namespace QueueMemory2023 {struct Heap{void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;}
void* __cdecl operator new(size_t bytes){return QueueMemory2023::DAT_01090a78.FUN_0086b930(bytes);}
void* __cdecl operator new[](size_t bytes){return QueueMemory2023::DAT_01090a78.FUN_0086b930(bytes);}
namespace QueueConstruct2023 {
struct InterfacedClass{virtual ~InterfacedClass();};
struct MemoryContext{int saved;MemoryContext(){saved=DAT_0117c298;DAT_0117c298=6;}~MemoryContext(){DAT_0117c298=saved;}};
struct RefObject{void IncRefCount();void DecRefCount();};
struct Entry{Entry* next;NiPointer<RefObject> data;Entry() throw():next(0),data(0){}};
struct FUN_005e5280{unsigned int unk00,unk04,unk08,unk0C;FUN_005e5280(unsigned int);};
struct Queue:InterfacedClass{Entry* head;Entry* tail;unsigned int deleteBatchSize;Entry** deletedBuffers;FUN_005e5280* manager;volatile int count;Queue(unsigned int,unsigned int);virtual ~Queue();};
// pdb: LockFreeQueue<NiPointer<IOTask> >::LockFreeQueue<NiPointer<IOTask> > | IOManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiMaxThreads, aiDeleteBatchSize
Queue::Queue(unsigned int threads,unsigned int batch){MemoryContext context;count=0;head=new Entry;tail=head;deleteBatchSize=batch;deletedBuffers=new Entry*[threads*2];manager=new FUN_005e5280(threads);}
}
}   // namespace f3m_00aa28f0

// @f3 0x00aa9df0 (community match, verified in this file)
#include <stddef.h>
#include <stdio.h>
namespace f3m_00aa9df0 {
namespace WorkerMemory2025 {struct Heap{void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;extern unsigned int DAT_01066780;extern const char DAT_00e8a040[];}
void* __cdecl operator new(size_t bytes){return WorkerMemory2025::DAT_01090a78.FUN_0086b930(bytes);}
class ThreadOwner2025;
class BSLinearTaskThread {public:virtual ~BSLinearTaskThread();unsigned int unk04;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2C;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3C;unsigned int unk40;unsigned int unk44;unsigned int unk48; BSLinearTaskThread();void FUN_0086ce90(unsigned int,const char*);void FUN_0078c030(const char*);void FUN_0078c030(unsigned int);void FUN_0086ce30(int);};
class BSParallelTaskThread:public BSLinearTaskThread {public:ThreadOwner2025* owner;BSParallelTaskThread(ThreadOwner2025* p):owner(p){}virtual ~BSParallelTaskThread();};
class ThreadOwner2025 {public:BSParallelTaskThread** thread;unsigned int unk04,unk08;bool unk0C;ThreadOwner2025();};
typedef char ThreadSize[(sizeof(BSParallelTaskThread)==0x50)?1:-1];
// pdb: BSParallelTaskManager::BSParallelTaskManager | BSParallelTaskManager.obj | fnv360_0822_retail, ustr, medium
ThreadOwner2025::ThreadOwner2025(){
 thread=0;unk04=0;unk08=0;unk0C=false;
 thread=new BSParallelTaskThread*;
 *thread=new BSParallelTaskThread(this);
 char name[0x104];
 sprintf_s(name,sizeof(name),WorkerMemory2025::DAT_00e8a040,WorkerMemory2025::DAT_01066780);
 (*thread)->FUN_0086ce90(0x8000,name);
 (*thread)->FUN_0078c030(name);
 (*thread)->FUN_0078c030(WorkerMemory2025::DAT_01066780);
 (*thread)->FUN_0086ce30(15);
}
}   // namespace f3m_00aa9df0

// @f3 0x00ab9060 (community match, verified in this file)
namespace VelocityAB {
struct Vec {
 float x,y,z;
 Vec() {}
 Vec(float X,float Y,float Z):x(X),y(Y),z(Z) {}
 bool FUN_00914730(const Vec&) const;
 bool FUN_00914770(const Vec&) const;
 Vec operator-(const Vec& o) const { return Vec(x-o.x,y-o.y,z-o.z); }
 Vec operator*(float s) const { return Vec(x*s,y*s,z*s); }
 Vec operator/(const float& s) const {return *this*(1.0f/s);}
};
extern Vec DAT_0108ec68;
struct Transform {
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
Vec position;
};
struct Link {int unk00,unk04,unk08,unk0c,unk10,unk14; Transform* target;};
struct Particle {Vec velocity;int unk0c,unk10,unk14,unk18;};
struct Data {
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
unsigned short count; unsigned short unk52;
 unsigned int unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;
 Particle* particles;
};
struct Owner {
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
unsigned int unk04,unk08,unk0c;
 Link* link;
 unsigned int unk14;
 float delta,lastTime,scale;
 Vec lastPosition,velocity;
 void FUN_00ab9060(float,Data*);
};
}
// pdb: BSParentVelocityModifier::Update | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: afTime, apData
void VelocityAB::Owner::FUN_00ab9060(float time,Data* data) {
 if(!data->count) return;
 Transform* target=link->target;
 if(!target) {Slot94(); return;}
 if(lastPosition.FUN_00914730(DAT_0108ec68)) {
  velocity=DAT_0108ec68;
  lastTime=time;
  lastPosition=target->position;
 }
 Vec position=target->position;
 float dt=time-lastTime;
 unsigned int count=data->count;
 if(dt!=0.0f) {
  Vec nextVelocity=((position-lastPosition)*scale)/dt;
  Vec change=nextVelocity-velocity;
  if(change.FUN_00914770(DAT_0108ec68)) {
   Particle* __restrict particle=data->particles;
   while(count--) {
    particle->velocity.x+=change.x;
    particle->velocity.y+=change.y;
    particle->velocity.z+=change.z;
    ++particle;
   }
  }
  velocity=nextVelocity;
 }
 delta=dt;
 lastPosition=position;
 lastTime=time;
}

// @f3 0x00aa4cc0 (community match, verified in this file)
namespace Task1803 {
struct Heap { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
extern char DAT_00e8968c,DAT_00e895ec;
extern const char DAT_00e895f4[];
struct FUN_00aa2d70 {
 virtual void v0(); unsigned unk04,unk08,unk0c,unk10,unk14,unk18;
 FUN_00aa2d70(unsigned,unsigned,unsigned); ~FUN_00aa2d70();
};
struct FUN_00aa6490 {
 virtual void v0(); unsigned unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
 FUN_00aa6490(unsigned,const char*); ~FUN_00aa6490();
};
struct FUN_00aa4cc0;
struct Worker : FUN_00aa6490 {
 FUN_00aa4cc0* owner;
 Worker(FUN_00aa4cc0* p,unsigned id):FUN_00aa6490(id,DAT_00e895f4),owner(p) {}
 virtual void v0();
 void FUN_00aa6480();
 static void* operator new(unsigned n) {return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct Slot {void* value;static void* operator new[](unsigned n){return DAT_01090a78.FUN_0086b930(n);}};
struct WorkerPointer {Worker* value;
 operator Worker*() const {return value;}
 Worker* operator->()const{return value;}
 WorkerPointer& operator=(Worker* p){value=p;return *this;}
 static void* operator new[](unsigned n){return DAT_01090a78.FUN_0086b930(n);}
};
struct FUN_00aa4cc0:FUN_00aa2d70 {
 struct State {bool stopped;unsigned count20,count24;State():stopped(false),count20(0),count24(0){}} state;unsigned workers;
 WorkerPointer* threads; Slot* slots; unsigned count34;
 FUN_00aa4cc0(unsigned,unsigned,unsigned);virtual void v0();
};
}
// pdb: BSTaskManager<__int64>::BSTaskManager<__int64> | IOManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: aiNumInterfaceThreads, aiNumTaskThreads, aiNumTaskBuckets
Task1803::FUN_00aa4cc0::FUN_00aa4cc0(unsigned reserved,unsigned n,unsigned slotCount):FUN_00aa2d70(reserved+n,slotCount,12),workers(n) {
 slots=new Slot[slotCount];
 memset(slots,0,slotCount*sizeof(void*));
 count34=0;
 threads=new WorkerPointer[workers];
 for(unsigned i=0;i<workers;i++) {threads[i]=new Worker(this,i+2);threads[i]->FUN_00aa6480();}
}

// @f3 0x00aa3eb0 (community match, verified in this file)
namespace f3m_00aa3eb0 {
namespace f3m_00aa3eb0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);

struct SemaphoreLock {
    volatile long count;
    void* semaphore;
    void Lock() {
        WaitForSingleObject(semaphore, 0xffffffff);
        InterlockedDecrement(&count);
    }
    void Unlock() {
        ReleaseSemaphore(semaphore, 1, 0);
        InterlockedIncrement(&count);
    }
};

struct Task {
    virtual void DeleteThis(int flags);
    int unk04;
    volatile long refs;
    long state;
    bool TryStart() { bool ok = InterlockedCompareExchange((volatile long*)&state, 3, 1) == 1; return ok; }
};

struct TaskPtr {
    Task* p;
    TaskPtr() : p(0) {}
    ~TaskPtr() {
        if (p) { long r = InterlockedDecrement(&p->refs); if (r == 0) p->DeleteThis(1); }
    }
    TaskPtr& operator=(Task* o) {
        if (p != o) {
            if (p) { long r = InterlockedDecrement(&p->refs); if (r == 0) p->DeleteThis(1); }
            p = o;
            if (o)
                InterlockedIncrement(&o->refs);
        }
        return *this;
    }
};

struct JobData {
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char flags;
    int unk1c;
    JobData() { unk08 = 0; unk10 = 0; unk14 = 0; flags = 0; }
};

struct Job : JobData {
    virtual ~Job() {}
    virtual void Release();
    void Clear() {
        Release();
        flags &= 0xfc;
        unk08 = 0;
    }
};

struct Owner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44();
    virtual void Run(Task* task);
    virtual void Finish(Task* task);
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    volatile char stop;
    bool FUN_00aa3df0(Job* job, __int64* extra, TaskPtr* task, bool first);
};

struct Worker {
    void* vtable;
    int unk04, unk08;
    SemaphoreLock wake;
    int unk14;
    SemaphoreLock lock;
    int unk20;
    Owner* owner;
    void FUN_00aa3eb0();
};
}
using namespace f3m_00aa3eb0;

__declspec(noinline) bool Owner::FUN_00aa3df0(Job* job, __int64* extra, TaskPtr* task, bool first)
{
    *extra = 0;
    if (!first || !(job->flags & 1))
        return false;
    *task = (Task*)unk18;
    return task->p != 0;
}

// pdb: BSTaskManagerThread<__int64>::ThreadUpdate | IOManager.obj | fnv360_0822_retail, vtable, medium
void Worker::FUN_00aa3eb0()
{
    while (owner->stop != 1) {
        wake.Lock();
        Job job;
        bool busy = false;
        do {
            if (WaitForSingleObject(lock.semaphore, 0) == 0x102) {
                lock.Lock();
                job.Clear();
            }
            TaskPtr task;
            __int64 extra;
            if (owner->FUN_00aa3df0(&job, &extra, &task, !busy)) {
                if (task.p->state == 1 && task.p->TryStart()) {
                    busy = true;
                    owner->Run(task.p);
                    owner->Finish(task.p);
                }
            } else if (!(job.flags & 2)) {
                job.Clear();
                busy = false;
            }
            task = 0;
            lock.Unlock();
        } while (!(job.flags & 2));
    }
}
}   // namespace f3m_00aa3eb0

// @f3 0x00ab4d70 (community match, verified in this file)
extern unsigned short DAT_01066b84;
namespace f3m_00ab4d70 {
namespace Task1953 {
inline int MinCount(unsigned short a, int b)
{
    return a < b ? a : b;
}
struct Emitted
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
    unsigned int flags;
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
    float time;
    float GetTime() const
    {
        return time;
    }
};
struct ParticleNode
{
    ParticleNode* next;
    ParticleNode* previous;
    Emitted* value;
};
struct Emitter
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
    ParticleNode* first;
    int unkb0;
    int unkb4;
    unsigned short count;
    unsigned short GetCount() const
    {
        return count;
    }
    int unkbc;
    ParticleNode* next;
    inline Emitted* PopFrontNode()
    {
        ParticleNode** cursor = &next;
        Emitted** value = &(*cursor)->value;
        *cursor = (*cursor)->next;
        Emitted* result = *value;
        if (!next)
        {
            ParticleNode* head = first;
            next = head;
        }
        return result;
    }
};
struct S240
{
    float* data;
    float* GetData() const
    {
        return data;
    }
    unsigned int capacity;
    unsigned int count;
    void FUN_00ab4c90(const float& value);
};
struct ParticleSystem
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
    virtual void Emit(float now, unsigned short count, float* times);
    virtual void va8();
    virtual void SetCurrent(Emitted* particle);
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
    float time;
    Emitted* current;
    void SetTime(float value)
    {
        time = value;
    }
};
struct Controller
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
    ParticleSystem* system;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    S240 times;
    Emitter* emitter;
    unsigned short maxCount;
    void FUN_00ab4d70(float now, float start, float end, float emitStart, float emitEnd, float rate);
};
// @fnv 0x00c5c790
// pdb: BSPSysMultiTargetEmitterCtlr::EmitParticles | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, call_gap, medium
// pdb params: fTime, fCurTime, fLastTime, fEmitStart, fEmitStop, fBirthRate
void Controller::FUN_00ab4d70(float now, float start, float end, float emitStart, float emitEnd, float rate)
{
    float age;
    Emitted* particle5;
    unsigned short idx2;
    float interval;
    ParticleSystem* ps1;
    unsigned short count2;
    unsigned int steps2;
    unsigned short remainingVal;
    float savedTime;
    unsigned short limitA5;
    Emitted* saved;
    unsigned short previousB;
    unsigned short addedB;
    unsigned short total_13;
    float duration20;
    float elapsed_2;

    if (emitter && rate > 0.0 && emitStart < emitEnd && start > emitStart && end < emitEnd)
    {

        if (start <= emitEnd)
            duration20 = start - emitStart;
        else
            duration20 = emitEnd - emitStart;
        elapsed_2 = 0.0f;
        if (end >= emitStart)
            elapsed_2 = end - emitStart;
        if (emitter->GetCount())
        {
            total_13 = (unsigned short)(rate * duration20);
            previousB = (unsigned short)(rate * elapsed_2);
            addedB = total_13 - previousB;
            if (addedB > 0)
            {
                limitA5 = maxCount * addedB;
                remainingVal = emitter->count;
                count2 = MinCount(limitA5, addedB * remainingVal);
                steps2 = (unsigned short)(count2 / remainingVal);
                if ((unsigned short)steps2 > DAT_01066b84)
                    steps2 = DAT_01066b84;
                if (!(unsigned short)steps2)
                {
                    remainingVal = count2;
                    steps2 = 1;
                }
                interval = 1.0f / rate;
                times.count = 0;
                for (idx2 = 0; idx2 < (unsigned short)steps2; idx2++)
                {
                    previousB++;
                    age = duration20 - previousB * interval;
                    times.FUN_00ab4c90(age);
                }
                ps1 = system;
                saved = ps1->current;
                savedTime = ps1->time;
                while (remainingVal > 0)
                {
                    particle5 = emitter->PopFrontNode();
                    if (particle5 && !(bool)(particle5->flags & 1 ? 1 : 0))
                    {
                        ps1->SetCurrent(particle5);
                        ps1->SetTime(particle5->GetTime());
                        ps1->Emit(now, steps2, times.GetData());
                        remainingVal--;
                    }
                }
                ps1->SetCurrent(saved);
                ps1->time = savedTime;
            }
        }
    }
}

}
}   // namespace f3m_00ab4d70

// @f3 0x00ab27e0 (community match, verified in this file)
extern char* DAT_00e207a8;
namespace f3m_00ab27e0 {
namespace f3m_00ab27e0 {
namespace task0566_ab27e0 {
struct MeshAllocator_ab27e0
{
    void* FUN_0086b930(unsigned int);
};
__forceinline void* operator new[](unsigned int n)
{
    return reinterpret_cast<MeshAllocator_ab27e0&>(::DAT_01090a78).FUN_0086b930(n);
}
struct MeshPoint_ab27e0
{
    float x, y, z;
    __forceinline MeshPoint_ab27e0()
    {}
    __forceinline MeshPoint_ab27e0(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    static __forceinline void* operator new[](unsigned int n) throw()
    {
        return reinterpret_cast<MeshAllocator_ab27e0&>(::DAT_01090a78).FUN_0086b930(n);
    }
};
struct MeshUV_ab27e0
{
    float x, y;
    __forceinline MeshUV_ab27e0()
    {}
    __forceinline MeshUV_ab27e0(float a, float b)
    {
        x = a;
        y = b;
    }
    static __forceinline void* operator new[](unsigned int n) throw()
    {
        return reinterpret_cast<MeshAllocator_ab27e0&>(::DAT_01090a78).FUN_0086b930(n);
    }
};
struct MeshColor_ab27e0
{
    float r, g, b, a;
    __forceinline MeshColor_ab27e0() : r(0), g(0), b(0), a(0)
    {}
    static __forceinline void* operator new[](unsigned int n) throw()
    {
        return reinterpret_cast<MeshAllocator_ab27e0&>(::DAT_01090a78).FUN_0086b930(n);
    }
};

char* __cdecl FUN_008242a0(const char*);
struct StringHeader_ab27e0
{
    long refs;
    long length;
    char text;
};
struct MeshName_ab27e0
{
    char* value;
    __forceinline MeshName_ab27e0(const char* name)
    {
        if (!name)
            value = DAT_00e207a8;
        else
            value = FUN_008242a0(name);
    }
    __forceinline ~MeshName_ab27e0()
    {
        if (value == DAT_00e207a8)
            return;
        long* refs = (long*)value - 2;
        InterlockedDecrement(refs);
    }
};
struct CylinderMesh_ab27e0
{
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
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void Update();
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
    static void* operator new(unsigned int);
    CylinderMesh_ab27e0(unsigned short, MeshPoint_ab27e0*, MeshPoint_ab27e0*, MeshColor_ab27e0*, MeshUV_ab27e0*, unsigned short, int, unsigned short,
                 unsigned short, unsigned short*, unsigned short*);
    void FUN_008245d0(const MeshName_ab27e0&);
};

// pdb: BSTestObjects::CreateCylinder | BSTestObjects.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
CylinderMesh_ab27e0* __cdecl BSTestObjects_CreateCylinder(float bottom, float top, float height, unsigned short slices, unsigned short stacks,
                                   MeshColor_ab27e0* color)
{
    unsigned short stripSizeX = 2 * slices + 2;
    unsigned int count7 = stacks * stripSizeX;
    MeshPoint_ab27e0* point15 = new MeshPoint_ab27e0[count7];
    MeshPoint_ab27e0* normal6 = new MeshPoint_ab27e0[count7];
    MeshColor_ab27e0* pkColors8 = color ? new MeshColor_ab27e0[count7] : 0;
    MeshUV_ab27e0* finalTexcoords6 = new MeshUV_ab27e0[count7];
    unsigned short* lengthsVal = new unsigned short[stacks];
    unsigned short* indices_19 = new unsigned short[count7];
    unsigned short index4 = 0;
    float angleStep6 = 6.2831854820251465 / slices;
    float radiusStep2 = (top - bottom) / stacks;
    float heightStep = height / stacks;
    float uStep9 = 1.0f / slices;
    float kVStep = 1.0f / stacks;
    float v2 = 1.0f;
    float zl = 0.0f;
    float rRadius = bottom;
    float _normal = (bottom - top) / height;  // Z component of the unnormalized surface normal.
    float aNormalScale = 1.0f;
    for (unsigned int row = 0; row < stacks; row++)
    {
        float u = 0.0f;
        for (unsigned int col = 0; col <= slices; col++)
        {
            float sine, cosine;
            if (col == slices)
            {
                sine = 0.0f;
                cosine = 1.0f;
            }
            else
            {
                sine = sin(col * angleStep6);
                cosine = cos(col * angleStep6);
            }
            point15[index4] = MeshPoint_ab27e0(sine * rRadius, cosine * rRadius, zl);
            normal6[index4] = MeshPoint_ab27e0(sine * aNormalScale, cosine * aNormalScale, _normal * aNormalScale);
            if (color)
                pkColors8[index4] = *color;
            finalTexcoords6[index4] = MeshUV_ab27e0(u, v2);
            indices_19[index4] = index4;
            index4++;
            point15[index4] =
                MeshPoint_ab27e0(sine * (rRadius + radiusStep2), cosine * (rRadius + radiusStep2), zl + heightStep);
            normal6[index4] = MeshPoint_ab27e0(sine * aNormalScale, cosine * aNormalScale, _normal * aNormalScale);
            if (color)
                pkColors8[index4] = *color;
            finalTexcoords6[index4] = MeshUV_ab27e0(u, v2 - kVStep);
            indices_19[index4] = index4;
            index4++;
            u += uStep9;
        }
        rRadius += radiusStep2;
        v2 -= kVStep;
        zl += heightStep;
        lengthsVal[row] = stripSizeX;
    }
    CylinderMesh_ab27e0* mesh2 = new CylinderMesh_ab27e0(index4, point15, normal6, pkColors8, finalTexcoords6, 1, 0,
                                           2 * stacks * slices, stacks, lengthsVal, indices_19);
    mesh2->FUN_008245d0(MeshName_ab27e0("BSTestObjects Cylinder"));
    mesh2->Update();
    return mesh2;
}
}  // namespace task0566_ab27e0
}
}   // namespace f3m_00ab27e0

// @f3 0x00aa10c0 (community match, verified in this file)
#include <math.h>
namespace f3m_00aa10c0 {
namespace task1256 {
struct NiPoint3 {float x,y,z;};struct NiBound {NiPoint3 m_kCenter;float m_fBoundRadius;};
struct SphereBoxTest
{
    int unk00;
    int unk04;
    int unk08;
    NiPoint3 m_kCenter;
    NiPoint3 m_kExtents;
    int FUN_00aa10c0(const NiBound& bound);
};
// Tests a sphere against the axis-aligned box m_kCenter/m_kExtents and returns 2 for inside, 1 for intersecting, or 0 for outside.
// @fnv 0x00c382b0
// pdb: BSMultiBoundAABB::CheckBound | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aTargetBound
int SphereBoxTest::FUN_00aa10c0(const NiBound& bound)
{
    NiPoint3 p = bound.m_kCenter;
    float cf = bound.m_fBoundRadius;
    bool s = true;
    bool eb = true;
    float f, q, b;
    float c, e, j;
    c = (p.x) - (m_kCenter.x);
    f = abs(c);
    s &= f - (m_kExtents.x - cf) <= 0.0;
    eb &= f - (m_kExtents.x + cf) <= 0.0;
    if (s || eb)
    {
        e = (p.y) - (m_kCenter.y);
        q = abs(e);
        if (s)
            s &= q - (m_kExtents.y - cf) <= 0.0;
        eb &= q - (m_kExtents.y + cf) <= 0.0;
        if (s || eb)
        {
            j = (p.z) - (m_kCenter.z);
            b = abs(j);
            if (s)
                s &= b - (m_kExtents.z - cf) <= 0.0;
            eb &= b - (m_kExtents.z + cf) <= 0.0;
        }
    }
    return s ? 2 : (eb ? 1 : 0);
}


}
}   // namespace f3m_00aa10c0

// @f3 0x00aafcc0 (community match, verified in this file)
extern "C" char DAT_01090a78;
namespace f3m_00aafcc0 {


namespace f3_aafcc0 {

struct Heap
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};

struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream* stream, void* buffer, unsigned int bytes,
                                     unsigned int* componentSizes, unsigned int numComponents);

    unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* componentSizes,
                            unsigned int numComponents)
    {
        unsigned int read = m_pfnRead(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += read;
        return read;
    }
};

template <class T> inline void NiStreamLoadBinary(NiBinaryStream& stream, T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(&value, sizeof(T), &size, 1);
}

struct NiStream
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
    NiBinaryStream* m_pkIstr;
    void FUN_0082b560();
};

template <class T> struct NiTPrimitiveSet
{
    T* m_pBase;
    unsigned int m_uiAlloced;
    unsigned int m_uiUsed;

    static void* operator new(unsigned int size)
    {
        return ((Heap*)&DAT_01090a78)->FUN_0086b930(size);
    }
    static void operator delete(void* p)
    {
        ((Heap*)&DAT_01090a78)->FUN_0086ba60(p);
    }
    NiTPrimitiveSet(unsigned int initialSize = 0) : m_pBase(0), m_uiAlloced(0), m_uiUsed(0)
    {
        if (initialSize > 0)
            FUN_008cde60(initialSize);
    }
    void FUN_008cde60(unsigned int size);
    void Add(const T& element)
    {
        if (m_uiUsed == m_uiAlloced)
            FUN_008cde60(m_uiAlloced > 0 ? 2 * m_uiAlloced : 1);
        m_pBase[m_uiUsed++] = element;
    }
};

typedef NiTPrimitiveSet<void*> BoneSet;

struct BoneSetArray
{
    void* vtbl;
    BoneSet** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00555790(unsigned int maxSize);
    void SetAt(unsigned int index, BoneSet* const& element)
    {
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[index] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[index] != 0)
                    m_usESize--;
            }
        }
        m_pBase[index] = element;
    }
    unsigned int SetAtGrow(unsigned int index, BoneSet* const& element)
    {
        if (index >= m_usMaxSize)
            FUN_00555790(index + m_usGrowBy);
        SetAt(index, element);
        return index;
    }
};

struct NiBoneLODController
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
    int m_iLOD;
    unsigned int m_uiNumLODs;
    BoneSetArray m_kBoneArray;
    void FUN_008381d0(NiStream* stream);
    void FUN_00aafcc0(NiStream* stream);
};

// pdb: NiBSBoneLODController::LoadBinary | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void NiBoneLODController::FUN_00aafcc0(NiStream* stream)
{
    unsigned int i;
    FUN_008381d0(stream);
    NiStreamLoadBinary(*stream->m_pkIstr, m_iLOD);
    NiStreamLoadBinary(*stream->m_pkIstr, m_uiNumLODs);
    unsigned int numArrays = 0;
    NiStreamLoadBinary(*stream->m_pkIstr, numArrays);
    for (i = 0; i < numArrays; i++)
    {
        BoneSet* set = new BoneSet;
        m_kBoneArray.SetAtGrow(i, set);
        unsigned int numBones = 0;
        NiStreamLoadBinary(*stream->m_pkIstr, numBones);
        for (unsigned int j = 0; j < numBones; j++)
        {
            void* object = this;
            set->Add(object);
            stream->FUN_0082b560();
        }
    }
}

}
}   // namespace f3m_00aafcc0

// @f3 0x00aa4df0 (community match, verified in this file)
#include <stddef.h>
extern __declspec(thread) int DAT_0117c298;
namespace f3m_00aa4df0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Heap {void* FUN_0086b930(unsigned int);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
struct MemoryContext {int saved;MemoryContext(){saved=DAT_0117c298;DAT_0117c298=6;}~MemoryContext(){DAT_0117c298=saved;}};
struct RefObject {
 virtual ~RefObject();
 int unk04;
 volatile long refs;
 void IncRefCount(){InterlockedIncrement(&refs);}
 void DecRefCount(){long r=InterlockedDecrement(&refs);if(r==0)delete this;}
};
template <class T> class NiPtr {
public:
 T* m_pObject;
 NiPtr(T* object=0){m_pObject=object;if(m_pObject)m_pObject->IncRefCount();}
 ~NiPtr(){if(m_pObject)m_pObject->DecRefCount();}
 NiPtr<T>& operator=(T* object){if(m_pObject!=object){if(m_pObject)m_pObject->DecRefCount();m_pObject=object;if(m_pObject)m_pObject->IncRefCount();}return *this;}
};
struct Entry {
 Entry* next;
 NiPtr<RefObject> data;
 Entry() throw():next(0),data(0){}
 static void* operator new(size_t n){return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}
};
struct FUN_005e5280 {
 unsigned int unk00,unk04,unk08,unk0C;
 FUN_005e5280(unsigned int);
 ~FUN_005e5280(){FUN_00aa4080();}
 void FUN_00aa4080();
 static void* operator new(size_t n){return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}
};
struct Queue {
 virtual ~Queue();
 Entry* head;
 Entry* tail;
 unsigned int deleteBatchSize;
 Entry** deletedBuffers;
 FUN_005e5280* manager;
 volatile int count;
 void FUN_00aa4df0(bool keepEmpty);
};
// pdb: LockFreePriorityQueue<NiPointer<IOTask> >::RemoveAll | IOManager.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: LockFreeMap<__int64,class NiPointer<class BSTask> >::LockFreeMapInterface::SetAt)
void Queue::FUN_00aa4df0(bool keepEmpty){
 MemoryContext context;
 unsigned int threads=manager->unk00;
 delete manager;
 manager=0;
 count=0;
 while(head){
  Entry* next=head->next;
  head->data=0;
  delete head;
  head=next;
 }
 if(!keepEmpty){
  Entry* e=new Entry;
  head=e;
  tail=e;
  manager=new FUN_005e5280(threads);
 }
}
}

// @f3 0x00aad4e0 (community match, verified in this file)
namespace naad4e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Target;
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void Apply(Target* target);
};
struct Ptr
{
    RefObj* m_pObject;
    Ptr(RefObj* object = 0) : m_pObject(object) {}
    ~Ptr()
    {
        if (Get() && InterlockedDecrement(&Get()->m_uiRefCount) == 0)
            Get()->DeleteThis();
    }
    __declspec(noalias) RefObj* Get() const { return m_pObject; }
    __declspec(noalias) Ptr& FUN_008e9600(const Ptr& other);
    __declspec(noalias) Ptr& FUN_008e9650(RefObj* object);
};
struct Globals { int m0; int m4; RefObj* m8; };
extern Globals* DAT_0108f048;
struct Self;
struct Other { __declspec(noalias) void FUN_00826660(Self* self); };
struct Target { char pad[0xdc]; int mdc; };
struct Self
{
    int m00;
    int m04;
    void* m08;
    Target* m0c;
    char pad10[0xc4 - 0x10];
    Ptr mc4;
    void FUN_008338b0(int* p);
    void FUN_00aad4e0(Target* target, Other* other, void* override);
};
// pdb: BSCullingProcess::Process | BSCullingProcess.obj | fnv360_0822_retail, vtable, medium
// pdb params: apCamera, apScene, apVisibleSet
void Self::FUN_00aad4e0(Target* target, Other* other, void* override)
{
    if (!target || !other)
        return;
    m0c = target;
    FUN_008338b0(&target->mdc);
    void* saved = 0;
    if (override)
    {
        saved = m08;
        m08 = override;
    }
    Ptr p;
    if (!m08)
    {
        p.FUN_008e9600(mc4);
        if (!p.Get())
        {
            RefObj* fallback = DAT_0108f048->m8;
            p.FUN_008e9650(fallback);
        }
        if (p.Get())
            p.Get()->Apply(target);
    }
    other->FUN_00826660(this);
    if (override)
        m08 = saved;
}
}

// @f3 0x00aac080 (community match, verified in this file)
namespace f3m_00aac080 {
namespace fo3_aac080 {
struct Vertex { float x, y, z; };
struct Data { int m_00; Vertex* m_04; };
struct Polygon {
    Data* m_00;
    int pad[8];
    int m_24;
    float FUN_00aac080();
};
}
using fo3_aac080::Polygon;

// pdb: BSPolygon2D::Area | BSPolygon.obj | fnv360_0822_retail, callee_sim, low
float Polygon::FUN_00aac080()
{
    float area = 0.0f;
    for (int i = 0; i < m_24; i++) {
        int n = m_24;
        int j = (i + 1) % n;
        area += m_00->m_04[i].x * m_00->m_04[j].y;
        area -= m_00->m_04[i].y * m_00->m_04[j].x;
    }
    return area * 0.5;
}
}   // namespace f3m_00aac080

// @f3 0x00aa5950 (community match, verified in this file)
class QueuedFile;
namespace naa5950 {
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
}
class QueuedFile {
public:
    virtual ~QueuedFile();
    int unk04;
    long refCount;
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (InterlockedDecrement(&refCount) == 0) delete this; }
    void FUN_00aa5870(void* owner);
};
template <> class BSSimpleArray<NiPointer<QueuedFile>, 1024> {
public:
    NiPointer<QueuedFile>* buffer;
    unsigned int size;
    unsigned int capacity;
    int FUN_005e5350();
    BSSimpleArray(unsigned int count)
    {
        buffer = 0;
        size = 0;
        capacity = 0;
        if (count) {
            BSSimpleArray* self = this;
            buffer = self->Allocate(count);
            capacity = count;
        }
    }
    virtual ~BSSimpleArray();
    virtual NiPointer<QueuedFile>* Allocate(unsigned int count);
};
class QueuedParents : public BSSimpleArray<NiPointer<QueuedFile>, 1024> {
public:
    QueuedParents() : BSSimpleArray<NiPointer<QueuedFile>, 1024>(5) {}
    virtual ~QueuedParents();
    static void* operator new(unsigned int size) { return naa5950::DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { naa5950::DAT_01090a78.FUN_0086ba60(p); }
    int FUN_00ae1370(QueuedFile** item, unsigned int start, int (__cdecl* compare)(const void*, const void*));
    void FUN_00aa56b0(const NiPointer<QueuedFile>& item);
    __declspec(noinline) int FUN_00aa56b0_Impl(const NiPointer<QueuedFile>& item);
};
__declspec(noinline) void QueuedParents::FUN_00aa56b0(const NiPointer<QueuedFile>& item) { buffer[size] = item; size++; }
namespace naa5950 {
int __cdecl FUN_00ae13c0(const void* a, const void* b);
struct Owner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    QueuedParents* parents;
    void FUN_00aa5950(QueuedFile* file);
};
// pdb: QueuedFile::AddAdditionalParent | QueuedFiles.obj | fnv360_0822_retail, call_gap, low
// pdb params: apAdditionalParent
void Owner::FUN_00aa5950(QueuedFile* file)
{
    if (!parents)
        parents = new QueuedParents;
    else if (parents->FUN_00ae1370(&file, 0, FUN_00ae13c0) != -1)
        return;
    {
        NiPointer<QueuedFile> item(file);
        parents->FUN_00aa56b0(item);
    }
    file->FUN_00aa5870(this);
}
}

// @f3 0x00aa9c80 (community match, verified in this file)
namespace f3m_00aa9c80 {
namespace naa9c80 {
struct ByteValue { unsigned char value; };
char* __cdecl FUN_00847c40(const char* label, ByteValue value);
char* __cdecl FUN_00847b90(const char* label, bool value);

__forceinline char* FormatViewerByte(const char* label, const unsigned char& value)
{
    ByteValue v; v.value = value;
    return FUN_00847c40(label, v);
}

__forceinline char* FormatViewerFlag(const char* label, const bool& value)
{
    return FUN_00847b90(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_0082ee90(ViewerStrings* strings);
    void FUN_00aa9c80(ViewerStrings* strings);

    char unk00[0xac];
    bool enabled;
    unsigned char current;
    unsigned char minimum;
    unsigned char maximum;
};

// pdb: BSRangeNode::GetViewerStrings | BSRangeNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void Owner::FUN_00aa9c80(ViewerStrings* strings)
{
    FUN_0082ee90(strings);
    strings->Add(FormatViewerByte("Min", minimum));
    strings->Add(FormatViewerByte("Max", maximum));
    strings->Add(FormatViewerByte("Current", current));
    strings->Add(FormatViewerFlag("Enabled", enabled != 0));
}
}
}   // namespace f3m_00aa9c80

// @f3 0x00aa4b30 (community match, verified in this file)
extern bool DAT_01066430;
namespace f3m_00aa4b30 {
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long ms);
namespace naa4b30 {
struct Source {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual unsigned int GetCount();
};
struct Loader {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    volatile unsigned int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    volatile unsigned int* counts30;
    int unk34;
    int unk38;
    Source* source3c;
    int state40;
    unsigned int (*pending44)();
    int unk48;
    int unk4c;
    void (*progress50)(float);
    void FUN_00aa42d0(int state, int arg);
    bool FUN_00aa49c0();
    __forceinline unsigned int Sum(int type)
    {
        unsigned int sum = 0;
        for (unsigned int i = 0; i <= (unsigned int)(type * 4 + 3); i++)
            sum += counts30[i];
        return sum;
    }
    __forceinline unsigned int Extra() { return pending44 ? pending44() : 0; }
    __forceinline unsigned int Pending(int type)
    {
        unsigned int sum = Sum(type);
        unsigned int queued = source3c->GetCount();
        return Extra() + sum + queued;
    }
    void FUN_00aa4b30(int state);
};
// pdb: IOManager::LoadQueuedPriority | IOManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: aePriority
void Loader::FUN_00aa4b30(int state)
{
    if (state40 == 7)
        return;
    DAT_01066430 = false;
    if (unk18 == 0 && source3c->GetCount() == 0 && (!pending44 || pending44() == 0))
    {
        state40 = 6;
        DAT_01066430 = true;
        return;
    }
    state40 = state;
    FUN_00aa42d0(state, 0);
    unsigned int total = Pending(state);
    unsigned int left = total;
    bool done = false;
    while (left != 0 || !done)
    {
        if (progress50)
            progress50((float)((float)(total - left) / (float)total * 100.0));
        unsigned int waiting = unk18;
        if (waiting > source3c->GetCount())
            Sleep(50);
        done = FUN_00aa49c0();
        left = Pending(state);
    }
    state40 = 6;
    if (progress50)
        progress50(100.0f);
    DAT_01066430 = true;
}
}
}   // namespace f3m_00aa4b30

// @f3 0x00ab1a80 (community match, verified in this file)
#include <math.h>
#include <stddef.h>
namespace sphere2305 {
struct MeshAllocator { void* Allocate(unsigned int); };
extern MeshAllocator DAT_01090a78;
extern char DAT_00e8af88[];
extern const double DAT_00dc0760;
extern char* FUN_00e207a8;
extern char* InternName(const char*);
struct MeshName {
 char* p;
 MeshName(const char* text) : p(InternName(text)) {}
 ~MeshName() { if(p != FUN_00e207a8) InterlockedDecrement((long*)(p-8)); }
};
struct MeshMemory {
 static void* operator new(size_t n) { return AllocateObject(n); }
 static void operator delete(void* p);
 static void* operator new[](size_t n) { return DAT_01090a78.Allocate(n); }
 static void operator delete[](void* p);
 static void* AllocateObject(unsigned int);
};
struct MeshPoint : MeshMemory {
 float x,y,z;
 MeshPoint() {}
 MeshPoint(float a,float b,float c):x(a),y(b),z(c) {}
};
struct MeshUV : MeshMemory {
 float x,y;
 MeshUV() {}
 MeshUV(float a,float b):x(a),y(b) {}
};
struct MeshColor : MeshMemory {
 float r,g,b,a;
 MeshColor() : r(0),g(0),b(0),a(0) {}
};
struct SceneMesh : MeshMemory {
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
 virtual void Attach(SceneMesh*,int);
 virtual void ve0();
 virtual void ve4();
 virtual void Update();
};
struct SphereNode : SceneMesh {
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
 SphereNode(unsigned short);
 void SetName(const MeshName*);
};
struct FUN_0083f490 : SceneMesh {
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
 FUN_0083f490(unsigned short,MeshPoint*,MeshPoint*,MeshColor*,MeshUV*,unsigned short,int,unsigned short,unsigned short*);
};
struct FUN_0083c020 : SceneMesh {
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
 FUN_0083c020(unsigned short,MeshPoint*,MeshPoint*,MeshColor*,MeshUV*,unsigned short,int,unsigned short,unsigned short,unsigned short*,unsigned short*);
};
struct MeshIndex : MeshMemory { unsigned short value; };
inline float SphereCosValue(float angle) { return static_cast<float>(sin(static_cast<double>(angle))); }
inline float SphereSinValue(float angle) { return static_cast<float>(cos(angle)); }
inline double SphereCos(float angle) { return static_cast<double>(SphereCosValue(angle)); }
inline float SphereSin(float angle) { return static_cast<double>(SphereSinValue(angle)); }
// @fnv 0x00c56680
// pdb: BSTestObjects::CreateSphere | BSTestObjects.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
SphereNode* __cdecl BSTestObjects_CreateSphere(float radius, unsigned short slices, unsigned short stacks, const MeshColor* color)
{
    SphereNode* rootUpdate6;
    MeshPoint* capNormals7;
    unsigned int capacity0;
    float angle36;
    float vStep3;
    MeshUV* capUVs2;
    float uvX;
    float radius5;
    FUN_0083f490* capShape2;
    MeshPoint* capVertices2;
    unsigned short poleIndex8;
    float southernLatitude7;
    FUN_0083c020* sideShape8;
    float uStep;
    unsigned short* strips2;
    unsigned short vertexCount5;
    unsigned short* sideD3;
    unsigned short* capIndicesA;
    float angle28;
    MeshColor* color9;
    unsigned short indexB;
    float capUX;
    unsigned short intermediateBands5;
    unsigned short strip;
    rootUpdate6 = new SphereNode(0);
    rootUpdate6->SetName(&MeshName(DAT_00e8af88));

    radius5 = 1.0f;
    angle36 = 3.1415927410125732 / static_cast<float>(stacks);
    angle28 = DAT_00dc0760 / static_cast<float>(slices);
    uStep = 1.0f / static_cast<float>(slices);
    vStep3 = 1.0f / static_cast<float>(stacks);

    capVertices2 = new MeshPoint[2 * slices + 2];
    capNormals7 = new MeshPoint[2 * slices + 2];
    color9 = color ? new MeshColor[2 * slices + 2] : 0;
    capUVs2 = new MeshUV[2 * slices + 2];
    capIndicesA = (unsigned short*)new MeshIndex[slices * 6];

    vertexCount5 = 0;
    indexB = 0;
    poleIndex8 = vertexCount5;

    capVertices2[vertexCount5] = MeshPoint(0.0f, 0.0f, radius5 * radius);
    capNormals7[vertexCount5] = MeshPoint(0.0f, 0.0f, 1.0f);
    if (color)
        color9[vertexCount5] = *color;
    capUVs2[vertexCount5] = MeshUV(0.5f, 0.0f);
    ++vertexCount5;
    capUX = 0.0f;
    uvX = vStep3;
    for (unsigned int slice9 = 0; slice9 < slices; ++slice9)
    {
        float angle44;
        float z6;
        float x15;
        float y23;
        angle44 = static_cast<float>(slice9) * angle28;
        x15 = -static_cast<float>(SphereCos(angle44)) * static_cast<float>(SphereCosValue(angle36));
        y23 = static_cast<float>(SphereSin(angle44)) * static_cast<float>(SphereCosValue(angle36));
        z6 = radius5 * static_cast<float>(SphereSin(angle36));
        capVertices2[vertexCount5] = MeshPoint(x15 * radius, y23 * radius, z6 * radius);
        capNormals7[vertexCount5] = MeshPoint(x15 * radius5, y23 * radius5, z6 * radius5);
        if (color)
            color9[vertexCount5] = *color;
        capUVs2[vertexCount5] = MeshUV(capUX, uvX);
        ++vertexCount5;
        capUX += uStep;
        if (slice9 > 0)
        {
            capIndicesA[indexB++] = poleIndex8;
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 2);
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
        }
    }
    capIndicesA[indexB++] = poleIndex8;
    capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
    capIndicesA[indexB++] = static_cast<unsigned short>(poleIndex8 + 1);

    poleIndex8 = vertexCount5;

    capVertices2[vertexCount5] = MeshPoint(0.0f, 0.0f, -radius * radius5);
    capNormals7[vertexCount5] = MeshPoint(0.0f, 0.0f, -1.0f);
    if (color)
        color9[vertexCount5] = *color;
    capUVs2[vertexCount5] = MeshUV(0.5f, 1.0f);
    ++vertexCount5;
    southernLatitude7 = 3.1415927410125732 - angle36;
    capUX = 1.0f;
    uvX = 1.0f - vStep3;
    for (unsigned int indexA4 = slices; indexA4 > 0; --indexA4)
    {
        float angle57;
        float z7;
        float x26;
        float fY5;
        angle57 = indexA4 == slices ? 0.0f : static_cast<float>(indexA4) * angle28;
        x26 = -static_cast<float>(SphereCos(angle57)) * static_cast<float>(SphereCosValue(southernLatitude7));
        fY5 = static_cast<float>(SphereSin(angle57)) * static_cast<float>(SphereCosValue(southernLatitude7));
        z7 = radius5 * static_cast<float>(SphereSin(southernLatitude7));
        capVertices2[vertexCount5] = MeshPoint(x26 * radius, fY5 * radius, z7 * radius);
        capNormals7[vertexCount5] = MeshPoint(x26 * radius5, fY5 * radius5, z7 * radius5);
        if (color)
            color9[vertexCount5] = *color;
        capUVs2[vertexCount5] = MeshUV(capUX, uvX);
        ++vertexCount5;
        capUX -= uStep;
        if (indexA4 != slices)
        {
            capIndicesA[indexB++] = poleIndex8;
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 2);
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
        }
    }
    capIndicesA[indexB++] = poleIndex8;
    capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
    capIndicesA[indexB++] = static_cast<unsigned short>(poleIndex8 + 1);

    capShape2 =
        new FUN_0083f490(vertexCount5, capVertices2, capNormals7, color9, capUVs2, true, false, indexB / 3, capIndicesA);
    capShape2->Update();
    rootUpdate6->Attach(capShape2, true);

    uvX = 0.0f;
    intermediateBands5 = static_cast<unsigned short>(stacks - 2);
    strip = static_cast<unsigned short>(2 * slices + 2);
    capacity0 = static_cast<unsigned int>(intermediateBands5) * strip;
    capVertices2 = new MeshPoint[capacity0];
    capNormals7 = new MeshPoint[capacity0];
    color9 = color ? new MeshColor[capacity0] : 0;
    capUVs2 = new MeshUV[capacity0];
    strips2 = (unsigned short*)new MeshIndex[intermediateBands5];
    sideD3 = (unsigned short*)new MeshIndex[capacity0];
    vertexCount5 = 0;
    for (unsigned int band = 0; band < intermediateBands5; ++band)
    {
        southernLatitude7 = (band + 1) * angle36;
        capUX = 0.0f;
        for (unsigned int vertexCount9 = 0; vertexCount9 <= slices; ++vertexCount9)
        {
            float angle72;
            float zq;
            float x29;
            float fYA;
            angle72 = vertexCount9 == slices ? 0.0f : static_cast<float>(vertexCount9) * angle28;
            x29 = -static_cast<float>(SphereCos(angle72)) * static_cast<float>(SphereCosValue(southernLatitude7));
            fYA = static_cast<float>(SphereSin(angle72)) * static_cast<float>(SphereCosValue(southernLatitude7));
            zq = radius5 * static_cast<float>(SphereSin(southernLatitude7));
            capVertices2[vertexCount5] = MeshPoint(x29 * radius, fYA * radius, zq * radius);
            capNormals7[vertexCount5] = MeshPoint(x29 * radius5, fYA * radius5, zq * radius5);
            if (color)
                color9[vertexCount5] = *color;
            capUVs2[vertexCount5] = MeshUV(capUX, uvX);
            sideD3[vertexCount5] = vertexCount5;
            ++vertexCount5;
            x29 = -static_cast<float>(SphereCos(angle72)) *
                  static_cast<float>(SphereCosValue(southernLatitude7 + angle36));
            fYA = static_cast<float>(SphereSin(angle72)) *
                  static_cast<float>(SphereCosValue(southernLatitude7 + angle36));
            zq = radius5 * static_cast<float>(SphereSin(southernLatitude7 + angle36));
            capVertices2[vertexCount5] = MeshPoint(x29 * radius, fYA * radius, zq * radius);
            capNormals7[vertexCount5] = MeshPoint(x29 * radius5, fYA * radius5, zq * radius5);
            if (color)
                color9[vertexCount5] = *color;
            capUVs2[vertexCount5] = MeshUV(capUX, uvX + vStep3);
            sideD3[vertexCount5] = vertexCount5;
            ++vertexCount5;
            capUX += uStep;
        }
        uvX += vStep3;
        strips2[band] = strip;
    }

    sideShape8 = new FUN_0083c020(vertexCount5, capVertices2, capNormals7, color9, capUVs2, true, false,
                          intermediateBands5 * (slices * 2), intermediateBands5, strips2, sideD3);
    sideShape8->Update();
    rootUpdate6->Attach(sideShape8, true);
    return rootUpdate6;
}

}

// @f3 0x00aa0010 (community match, verified in this file)
#include <math.h>
namespace f3m_00aa0010 {
namespace waa0010 {
struct NiPoint3 {
    float x, y, z;
    float operator*(const NiPoint3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct NiPlane {
    NiPoint3 normal;
    float constant;
    NiPlane();
    float Distance(const NiPoint3& p) const { return normal * p - constant; }
};
struct FUN_00aa0010_Box {
    char pad[0x18];
    NiPoint3 extent;
    void FUN_00a9fa20(NiPlane* planes);
    bool FUN_00aa0010(const NiPoint3* p);
};
// pdb: BSMultiBoundOBB::QPointWithin | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: aPoint
bool FUN_00aa0010_Box::FUN_00aa0010(const NiPoint3* p)
{
    NiPlane planes[3];
    FUN_00a9fa20(planes);
    if (fabs(planes[0].Distance(*p)) - extent.x > 0.01f)
        return false;
    if (fabs(planes[1].Distance(*p)) - extent.y > 0.01f)
        return false;
    if (fabs(planes[2].Distance(*p)) - extent.z > 0.01f)
        return false;
    return true;
}
}
}   // namespace f3m_00aa0010

// @f3 0x00aac680 (community match, verified in this file)
namespace f3m_00aac680 {
struct Pt { float x, y, z; };
struct PtArray {
    int unk00;
    Pt* items;
    void FUN_005df840(int index, int n);
};
}
class FUN_00b988c0 {
public:
    short* indices;
    int unk08;
    int unk0c;
    FUN_00b988c0(unsigned int initialSize = 0) : indices(0), unk08(0), unk0c(0) { if (initialSize > 0) Grow(initialSize); }
    virtual ~FUN_00b988c0();
    void Grow(unsigned int n);
    int FUN_005b9790();
};
namespace f3m_00aac680 {
typedef ::FUN_00b988c0 IndexList;
inline int Side(float v)
{
    if (v < 0.0f) return 1;
    if (v > 0.0f) return -1;
    return 0;
}
struct Polygon {
    PtArray* points;
    IndexList* convex;
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20;
    int count;
    void FUN_00aac680();
};

// pdb: BSPolygon2D::StoreConcaveVertices | BSPolygon.obj | fnv360_0822_retail, objrun, medium
void Polygon::FUN_00aac680()
{
    if (convex)
        return;
    convex = new IndexList;
    bool removed = false;
    for (int i = 0; i < count; i++) {
        if (removed)
            i--;
        int prev = i == 0 ? count - 1 : i - 1;
        int next = (i + 1) % count;
        Pt a = points->items[next];
        Pt b = points->items[prev];
        Pt c = points->items[i];
        float v = (c.x - b.x) * (a.y - c.y) - (c.y - b.y) * (a.x - c.x);
        int side = Side(v);
        removed = false;
        if (side == -1) {
            IndexList* list = convex;
            int k = list->FUN_005b9790();
            list->indices[k] = (short)i;
        } else if (side == 0) {
            points->FUN_005df840(i, 1);
            count--;
            removed = true;
        }
    }
}
}

// @f3 0x00aa8740 (community match, verified in this file)
namespace f3m_00aa87c0 {

struct Buf00aa8740 : BufferAA {
    void FUN_00aa8740();
};

// pdb: BSCompoundFrustum::StartGroupUnion | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
void Buf00aa8740::FUN_00aa8740() {
    if (itemCount + 1 >= itemCapacity)
        ((GrowListAA*)((char*)this + 0x14))->FUN_005bb760(itemCapacity + 10, 1);
    *(unsigned char*)this = 0;
    items[itemCount].kind = 5;
    ++itemCount;
}

}

// @f3 0x00ab9f60 (community match, verified in this file)
namespace f3m_00ab9f60 {
struct NiObject;
struct NiStream {
    NiObject* GetLoadedObject();
};
struct NiExtraData {
    void LinkObject(NiStream& stream);
};
struct Holder00ab9f60 : NiExtraData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiObject** items;
    unsigned int count;
    void FUN_00ab9f60(NiStream& stream);
};
// pdb: BSTextureData::LinkObject | BSTextureData.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Holder00ab9f60::FUN_00ab9f60(NiStream& stream)
{
    LinkObject(stream);
    for (unsigned int i = 0; i < count; ++i) {
        NiObject** slot = items + i;
        *slot = stream.GetLoadedObject();
    }
}
}   // namespace f3m_00ab9f60

// @f3 0x00aae7d0 (community match, verified in this file)
// pdb: BSParticleSystemManager::FindChildIndex | BSParticleSystemManager.obj | fnv360_0822_debug, call_gap, low
// pdb params: apChild
int __thiscall Node_a94440::FUN_00aae7d0(void* item)
{
    unsigned int count = (unsigned int)((unsigned short)unkA8);
    unsigned int i = 0;

    if (count > 0) {
        int* p = (int*)unkA0;
        int target = (int)item;

        while (i < count) {
            if (*p == target) {
                return (int)i;
            }
            p++;
            i++;
        }
    }

    return -1;
}

// @f3 0x00aa8190 (community match, verified in this file)
namespace f3m_00aa8190 {
struct Heap { void* FUN_0086bae0(void* block, unsigned int size); };
extern Heap DAT_01090a78;
// pdb: BSSimpleArray<NiFrustumPlanes,1024>::_Reallocate | BSCompoundFrustum.obj | fnv360_0822_retail, vtable, medium
// pdb params: apBuffer, aiNewSizeInItem
void* __stdcall FUN_00aa8190(void* block, unsigned int count)
{
    return DAT_01090a78.FUN_0086bae0(block, count * 100);
}
}

// @f3 0x00aa5c40 (community match, verified in this file)
extern unsigned int* DAT_0116d6c4;
namespace f3m_00aa5c40 {


class FUN_00aa5c40_Class {
public:
    unsigned int unk00;
    unsigned char unk04;
    unsigned int* FUN_00aa5c40(unsigned char param_2);
};

void __cdecl FUN_0086c3e0();

// pdb: MessageHandler::MessageHandler | MessageHandler.obj | fnv360_0822_retail, call_seq, high
// pdb params: abStatic
unsigned int* FUN_00aa5c40_Class::FUN_00aa5c40(unsigned char param_2) {
    FUN_0086c3e0();
    this->unk04 = param_2;
    this->unk00 = 0xe89930;
    DAT_0116d6c4 = reinterpret_cast<unsigned int*>(this);
    return reinterpret_cast<unsigned int*>(this);
}
}   // namespace f3m_00aa5c40

// @f3 0x00aa81b0 (community match, verified in this file)
struct Dispatch
{
    void (__thiscall* destroy)(void*, unsigned int);
    void* (__thiscall* allocate)(void*, unsigned int);
    void (__thiscall* release)(void*, void*);
};

extern const Dispatch DAT_00e89ebc;

class FUN_00aa81b0
{
public:
    const Dispatch* vtable;
    void* data;
    unsigned int size;
    unsigned int capacity;
    ~FUN_00aa81b0();
};

FUN_00aa81b0::~FUN_00aa81b0()
{
    vtable = &DAT_00e89ebc;
    if (data)
    {
        vtable->release(this, data);
        data = 0;
        capacity = 0;
        size = 0;
    }
}

// @f3 0x00abcb40 (community match, verified in this file)
extern const char* DAT_0116ebe0;
namespace f3m_00abcb40 {
struct FUN_00abcb40_Param {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;

    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
};

struct FUN_00abcb40_Target {
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
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void FUN_00abcb40_target(FUN_00abcb40_Param* param);
};

struct FUN_00abcb40_Owner {
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
    FUN_00abcb40_Target* unk40;

    void FUN_00abcb40(FUN_00abcb40_Param* param);
};


void __stdcall FUN_00ac67c0(FUN_00abcb40_Param* param);
char* __cdecl FUN_00847b50(const char* label);

// pdb: NiPSysEmitterCtlr::GetViewerStrings | NiPSysEmitterCtlr.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkStrings
void FUN_00abcb40_Owner::FUN_00abcb40(FUN_00abcb40_Param* param)
{
    FUN_00ac67c0(param);

    char* value = FUN_00847b50(DAT_0116ebe0);

    unsigned int size = param->unk0A;
    unsigned int capacity = param->unk08;

    if (size >= capacity) {
        unsigned int newCapacity = param->unk0E;
        newCapacity += size;
        param->FUN_00555790(newCapacity);
    }

    param->FUN_005b3880(size, value);

    FUN_00abcb40_Target* target = unk40;
    if (target != 0) {
        target->FUN_00abcb40_target(param);
    }
}
}   // namespace f3m_00abcb40

// @f3 0x00ab9c70 (community match, verified in this file)
#include <string.h>
namespace f3m_00ab9c70 {
struct FUN_00ab9c70_Arg { int unk00; int unk04; const char* name; };
struct FUN_00ab9c70_Obj {
    int unk00;
    int unk04;
    const char* name;
    bool FUN_008258d0(FUN_00ab9c70_Arg* a);
    bool FUN_00ab9c70(FUN_00ab9c70_Arg* arg);
};
// pdb: BSReference::IsEqual | BSReference.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
bool FUN_00ab9c70_Obj::FUN_00ab9c70(FUN_00ab9c70_Arg* arg)
{
    if (FUN_008258d0(arg)) {
        if (name != 0) {
            if (arg->name != 0)
                return _stricmp(name, arg->name) == 0;
        }
    }
    return false;
}
}   // namespace f3m_00ab9c70

// @f3 0x00aaa030 (community match, verified in this file)
namespace f3m_00aaa030 {
struct FUN_00aa9f80_Type {};

void __stdcall FUN_00aa9fc0(FUN_00aa9f80_Type* a, unsigned int b);

// pdb: BSParallelTaskManager::RunTask | BSParallelTaskManager.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apArrayTask
void __stdcall FUN_00aaa030(unsigned int param_1) {
    static FUN_00aa9f80_Type instance;
    FUN_00aa9fc0(&instance, param_1);
}
}   // namespace f3m_00aaa030

// @f3 0x00ab0320 (community match, verified in this file)
namespace f3m_00ab0320 {
struct FUN_00ab0320_Obj {
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;
    unsigned char unk0e;
    void FUN_00ab0320();
};

void FUN_00ab0320_Obj::FUN_00ab0320()
{
    unk0c = 0;
    unk0e = 0xff;
}
}   // namespace f3m_00ab0320

// @f3 0x00aaedd0 (community match, verified in this file)
extern float DAT_00e1226c;
extern float DAT_0116d9dc;
extern float DAT_0116d9d0;
extern float DAT_0116d9c4;
namespace f3m_00aaedd0 {
class BSSceneGraph {
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
 bool unkb8;
 float FUN_00aaedd0();
};

// pdb: BSSceneGraph::GetFarDistance | BSSceneGraph.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: NiMatrix3::SetRow)
float BSSceneGraph::FUN_00aaedd0() {
    float result;
    if (unkb8) {
        result = DAT_00e1226c;
    } else {
        float lo = 0.0f;
        float hi = 1.0f;
        result = DAT_0116d9c4 + (DAT_0116d9d0 - DAT_0116d9c4) * ((DAT_0116d9dc - lo) / (hi - lo));
    }
    return result;
}
}   // namespace f3m_00aaedd0

// @f3 0x00ab6be0 (community match, verified in this file)
namespace f3m_00ab6be0 {
void* __cdecl FUN_0089eb90(unsigned int);
struct NiObject {
    virtual void Update();
};
struct FUN_00aad5f0 : NiObject {
    FUN_00aad5f0();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
};
struct FUN_00ab6be0_Obj : FUN_00aad5f0 {
 int unk04;
 int unk08;
 int unk0C;
 int unk10;
 int unk14;
 int unk18;
 int unk1C;
 int unk20;
 int unk24;
};
// pdb: BSMultiBoundCapsule::CreateObject | BSMultiBoundCapsule.obj | fnv360_0822_retail, objrun, medium
NiObject* __cdecl FUN_00ab6be0() {
    FUN_00ab6be0_Obj* p = new FUN_00ab6be0_Obj();
    return p;
}
}   // namespace f3m_00ab6be0

// @f3 0x00aa6770 (community match, verified in this file)
namespace f3m_00aa6770 {
class NiBinaryStream {
public:
    virtual ~NiBinaryStream();
};
class FileA609 : public NiBinaryStream {
public:
    virtual ~FileA609();
};
class NiStream {
public:
    bool BSStream_Save(const char* path);
    bool Save(NiBinaryStream* stream);
};
FileA609* __cdecl FUN_00aa1a20(const char* path, int mode, unsigned int size);

// pdb: BSStream::Save | BSStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
bool NiStream::BSStream_Save(const char* path) {
    FileA609* file = FUN_00aa1a20(path, 1, 0x2800);
    bool ok = false;
    if (file) {
        ok = Save(file);
        delete file;
    }
    return ok;
}
}   // namespace f3m_00aa6770

// @f3 0x00aaaaf0 (community match, verified in this file)
namespace f3m_00aaaaf0 {
struct ComponentSize417 {
    unsigned int size;
    __forceinline ComponentSize417(unsigned int value) : size(value) {}
    __forceinline operator const unsigned int*() const { return &size; }
};
struct Stream417 {
    void* vtbl;
    unsigned int pos;
    unsigned int unk08;
    unsigned int(__cdecl* read)(Stream417*, void*, unsigned int, const unsigned int*, unsigned int);
};
struct Save417 {
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
    Stream417* unk250;
};
struct FnvModBase {
    void FUN_00c31950(void* s);
};
struct Mod417 : FnvModBase {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    void FUN_00aaaaf0(Save417* s);
};

// pdb: BSPSysStripUpdateModifier::SaveBinary | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Mod417::FUN_00aaaaf0(Save417* s) {
    FnvModBase::FUN_00c31950(s);
    Stream417* b = s->unk250;
    b->pos += b->read(b, &unk18, 4, ComponentSize417(4), 1);
}
}   // namespace f3m_00aaaaf0

// @f3 0x00ab5e70 (community match, verified in this file)
namespace f3m_00ab5e70 {
struct Ptr417 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int unk10;
};
struct Sub417 {
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
    Ptr417* unkBC;
};
struct Node417 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual Sub417* slot18();
};
struct Set417 {
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
    Node417** items;
    unsigned short unkA4;
    unsigned short count;
};
struct Owner417 {
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
    virtual void slot8C();
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
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void slotE0();
    virtual void slotE4();
    virtual void slotE8();
    virtual void slotEC();
    virtual void slotF0();
    virtual void slotF4();
    virtual void slotF8();
    virtual void slotFC();
    virtual void slot100(int a, int b);
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
    void FUN_00ab5e70(Set417* a, int b);
};

// pdb: BSNiNode::ReparentSkinInstances | BSNiNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apRoot, apNewParent
void Owner417::FUN_00ab5e70(Set417* a, int b) {
    if (!a)
        return;
    if (!b)
        return;
    for (unsigned int i = 0; i < a->count; ++i) {
        Node417* n = a->items[i];
        if (n) {
            int r = n->slot0C();
            if (r) {
                slot100(r, b);
            } else {
                Sub417* s = n->slot18();
                if (s && s->unkBC)
                    s->unkBC->unk10 = b;
            }
        }
    }
}
}   // namespace f3m_00ab5e70

// @f3 0x00ab8ed0 (community match, verified in this file)
extern unsigned int DAT_0108ec68;
extern unsigned int DAT_0108ec6c;
extern unsigned int DAT_0108ec70;
namespace f3m_00ab8ed0 {
struct StandIn_ab8ed0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float unk18;
    int unk1C;
    float unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;

    void __declspec(noinline) FUN_00ac5e10();
    StandIn_ab8ed0* FUN_00ab8ed0();
};


// pdb: BSParentVelocityModifier::BSParentVelocityModifier | BSParentVelocityModifier.obj | fnv360_0822_retail, uvref, medium
StandIn_ab8ed0* StandIn_ab8ed0::FUN_00ab8ed0()
{
    FUN_00ac5e10();

    float zero = 0.0f;

    unk00 = 0xE8B984;
    unk0C = 3000;

    unk24 = DAT_0108ec68;
    unk28 = DAT_0108ec6c;
    unk2C = DAT_0108ec70;
    unk30 = DAT_0108ec68;
    unk34 = DAT_0108ec6c;
    unk38 = DAT_0108ec70;

    unk20 = zero;
    unk18 = zero;

    return this;
}
}   // namespace f3m_00ab8ed0

// @f3 0x00aa48a0 (community match, verified in this file)
namespace f3m_00aa48a0 {
// pdb: BSTaskManager<__int64>::RunTask | IOManager.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: IOTask::Process)
// pdb params: apTask
void __stdcall FUN_00aa48a0(f3m_00aa48b0::Task_00aa48b0* task)
{
    task->slot04();
}
}   // namespace f3m_00aa48a0

// @f3 0x00ab7b40 (community match, verified in this file)
namespace f3m_00ab7b40 {
extern char __stdcall FUN_00849750(int value);

// pdb: BSDecalPlacementVectorExtraData::RegisterStreamables | BSDecalPVExtraData.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
bool __stdcall FUN_00ab7b40(int value)
{
    return FUN_00849750(value) == 0;
}
}   // namespace f3m_00ab7b40

// @f3 0x00aa0ae0 (community match, verified in this file)
namespace f3m_00aa0ae0 {
struct FUN_00aa0ae0_Base
{
    virtual ~FUN_00aa0ae0_Base();
    int unk04;
    int unk08;

    void FUN_0083fa20(int value);
};

struct FUN_00aa0ae0_Owner
{
    virtual ~FUN_00aa0ae0_Owner();
    int unk04;
    int unk08;
    FUN_00aa0ae0_Base first;
    FUN_00aa0ae0_Base second;

    void FUN_00aa0ae0(int value);
};

void __stdcall FUN_008cbd30(int value);

void FUN_00aa0ae0_Owner::FUN_00aa0ae0(int value)
{
    FUN_008cbd30(value);
    first.FUN_0083fa20(value);
    second.FUN_0083fa20(value);
}
}   // namespace f3m_00aa0ae0

// @f3 0x00aab300 (community match, verified in this file)
extern const char* DAT_0116d770;
namespace f3m_00aab300 {
namespace f3m_00aab300 {
struct Array {
    unsigned int unk00;
    char** data;
    unsigned short capacity, size, count, growth;
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char** value);
};
char* FUN_00847b50(const char* text);
struct Owner {
    void FUN_00aa9c80(Array* output);
    void FUN_00aab300(Array* output);
};
// pdb: BSDamageStage::GetViewerStrings | BSDamageStage1.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void Owner::FUN_00aab300(Array* output) {
    FUN_00aa9c80(output);
    char* text = FUN_00847b50(DAT_0116d770);
    unsigned int index = output->size;
    if (index >= output->capacity) output->FUN_00555790(index + output->growth);
    output->FUN_005b3880(index, &text);
}
}
}   // namespace f3m_00aab300

// @f3 0x00aadeb0 (community match, verified in this file)
namespace f3m_00aadeb0 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec00(void*);

namespace f3m_00aadeb0 {

struct Obj {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8;
    int unkfc;
    int unk100;
    int unk104;

    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ec00(p); }
    Obj();
    Obj* FUN_00aadeb0(int unused);
};

// pdb: BSPortal::CreateClone | BSPortal.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
Obj* Obj::FUN_00aadeb0(int)
{
    Obj* copy = new Obj;
    copy->unkfc = unkfc;
    copy->unk100 = unk100;
    return copy;
}

}
}   // namespace f3m_00aadeb0

// @f3 0x00aade20 (community match, verified in this file)
extern void* const DAT_00dbee5c[];
namespace f3m_00aade20 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace f3m_00aade20 {


struct RefObj {
    virtual void Destroy0();
    virtual void DeleteThis();
    volatile long refs;
};

struct RefPtr {
    RefObj* p;
    RefPtr() : p(0) {}
    ~RefPtr() { if (p && InterlockedDecrement(&p->refs) == 0) p->DeleteThis(); }
    RefPtr& operator=(RefObj* q)
    {
        RefObj* old = p;
        if (old != q) {
            if (old && InterlockedDecrement(&old->refs) == 0)
                old->DeleteThis();
            p = q;
        }
        return *this;
    }
};

struct Base {
    void* vptr;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100;
    Base() { FUN_00a9dcf0(); }
    void FUN_00a9dcf0();
    ~Base();
};

struct Mid : Base {
    Mid() { vptr = (void*)DAT_00dbee5c; }
};

struct Obj : Mid {
    RefPtr ref;
    int unk108;
    Obj();
};

// pdb: BSPortal::BSPortal | BSPortal.obj | fnv360_0822_retail, call_seq, medium
Obj::Obj()
{
    ref = 0;
}

}
}   // namespace f3m_00aade20

// @f3 0x00ab9350 (community match, verified in this file)
extern const char* DAT_0116eb8c;
namespace f3m_00ab9350 {
namespace f3m_00ab9350 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847dd0(const char* label, float value);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Modifier
{
public:
    void FUN_00ac60d0(ViewerStrings* strings);
    void FUN_00ab9350(ViewerStrings* strings);

    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float damping;
};

// pdb: BSParentVelocityModifier::GetViewerStrings | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void Modifier::FUN_00ab9350(ViewerStrings* strings)
{
    FUN_00ac60d0(strings);
    strings->Add(FUN_00847b50(::DAT_0116eb8c));
    strings->Add(FUN_00847dd0("Damping", damping));
}
}
}   // namespace f3m_00ab9350

// @f3 0x00ab6110 (community match, verified in this file)
extern const char* DAT_0116eb44;
namespace f3m_00ab6110 {
namespace f3m_00ab6110 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847dd0(const char* label, float value);
class ViewerStrings {
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }
    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};
class Modifier {
public:
    void FUN_00ac60d0(ViewerStrings* strings);
    void FUN_00ab6110(ViewerStrings* strings);
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    float value;
};
// pdb: BSPSysStripUpdateModifier::GetViewerStrings | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void Modifier::FUN_00ab6110(ViewerStrings* strings)
{
    FUN_00ac60d0(strings);
    strings->Add(FUN_00847b50(::DAT_0116eb44));
    strings->Add(FUN_00847dd0("fUpdateDeltaTime", value));
}
}
}   // namespace f3m_00ab6110

// @f3 0x00aaf880 (community match, verified in this file)
namespace f3m_00aaf880 {
namespace f3m_00aaf880 {
struct Resource {virtual void v00();virtual void v04();virtual void v08();virtual unsigned int GetValue();};
struct Owner {
    unsigned int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28;
    Resource* resource;
    bool FUN_00aaf880();
};
// pdb: NiBSBoneLODController::TargetIsRequiredType | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
bool Owner::FUN_00aaf880(){if(resource && resource->GetValue())return true;return false;}
}
}   // namespace f3m_00aaf880

// @f3 0x00ab5940 (community match, verified in this file)
namespace f3m_00ab5940 {
namespace f3m_00ab5940 {
typedef struct HKEY__* HKEY;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
extern "C" __declspec(dllimport) long __stdcall FUN_00d9b010(HKEY hKey, const char* lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData, DWORD cbData);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);
unsigned int FUN_00a9d930(const char* name);

struct Setting {
    int unk00;
    int value;
    const char* name;
    unsigned int FUN_00a9da00();
};

struct Flags { bool pad0; bool pad1; bool result; bool opened; };

struct RegSettingCollection {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14();
    virtual void Open(int a);
    virtual void Close();
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104;
    HKEY hKey;
    bool FUN_00ab5940(Setting* setting);
};

// pdb: RegSettingCollection::WriteSetting | XRegSetting.obj | tesv_win, uimport, low
bool RegSettingCollection::FUN_00ab5940(Setting* setting)
{
    Flags f;
    f.result = false;
    const char* name = setting->name;
    if (name) {
        f.opened = (hKey == 0);
        if (f.opened)
            Open(1);
        if (hKey) {
            DWORD size = setting->FUN_00a9da00();
            DWORD type = FUN_00a9d930(name);
            char buffer[0x40];
            if (type == 1) {
                strcpy_s(buffer, 0x40, name);
                buffer[0] = 's';
                name = buffer;
            }
            HKEY key = hKey;
            f.result = FUN_00d9b010(key, name, 0, type, (const BYTE*)&setting->value, size) == 0;
        }
        if (f.opened)
            Close();
    }
    return f.result;
}
}
}   // namespace f3m_00ab5940

// @f3 0x00aad2d0 (community match, verified in this file)
namespace f3m_00aad2d0 {
namespace f3m_00aad2d0 {

struct IUnk {
    virtual long __stdcall QueryInterface(const void* iid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct ComPtr {
    IUnk* p;
    void FUN_00aad2d0();
};

// pdb: BSOcclusionQuery::~BSOcclusionQuery | BSOcclusionQuery.obj | fnv360_0721_beta, call_seq, low, conflict (skyrim: BSTempEffect::Initialize)
void ComPtr::FUN_00aad2d0()
{
    if (p)
        p->Release();
}

}
}   // namespace f3m_00aad2d0

// @f3 0x00aa9b20 (community match, verified in this file)
namespace f3m_00aa9b20 {
namespace f3m_00aa9b20 {
struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream* stream, void* buffer, unsigned int bytes,
                                     unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        unsigned int read = m_pfnRead(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += read;
        return read;
    }
};
template <class T> inline void NiStreamLoadBinary(NiBinaryStream& stream, T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(&value, sizeof(T), &size, 1);
}
struct NiStream {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248;
    NiBinaryStream* m_pkIstr;
};
struct Node {
    void* vtable;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8;
    unsigned char flagAC, flagAD, flagAE, flagAF;
    void FUN_0082db60(NiStream* stream);
    void BSRangeNode_SetCurrent(unsigned char value);
    void FUN_00aa9b20(NiStream* stream);
};
// pdb: BSRangeNode::LoadBinary | BSRangeNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Node::FUN_00aa9b20(NiStream* stream)
{
    FUN_0082db60(stream);
    unsigned char value;
    NiStreamLoadBinary(*stream->m_pkIstr, value);
    flagAE = value;
    NiStreamLoadBinary(*stream->m_pkIstr, value);
    flagAF = value;
    NiStreamLoadBinary(*stream->m_pkIstr, value);
    BSRangeNode_SetCurrent(value);
}
}
}   // namespace f3m_00aa9b20

// @f3 0x00ab8e50 (community match, verified in this file)
namespace f3m_00ab8e50 {
struct Class {
    unsigned int pad[21];
    unsigned int unk54;
    void FUN_00ab8dc0();
    void FUN_00ab8e50(unsigned int arg);
};

// pdb: BSPSysArrayEmitter::SetEmitterObj | BSPSysArrayEmitter.obj | fnv360_0822_retail, vtable, medium
// pdb params: apEmitter
void Class::FUN_00ab8e50(unsigned int arg) {
    unk54 = arg;
    FUN_00ab8dc0();
}
}   // namespace f3m_00ab8e50

// @f3 0x00ab9d10 (community match, verified in this file)
namespace f3m_00ab9d10 {

struct Element {
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
    virtual void v52(); virtual void v53(); virtual void v54();
    virtual void f55(void* second, int zero);
};

struct List {
    unsigned int sub_82a2b0();
    void* sub_82a280();
};

struct Obj8 {
    void sub_555790(unsigned int count);
};

struct Obj {
    void sub_78c030(List* list);
    char pad[8];
    Obj8 m8;
    void FUN_00ab9d10(List* list);
};

// pdb: BSNodeReferences::LinkObject | BSReference.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Obj::FUN_00ab9d10(List* list) {
    sub_78c030(list);
    unsigned int count = list->sub_82a2b0();
    if (!count)
        return;
    m8.sub_555790(count);
    count >>= 1;
    if (!count)
        return;
    for (unsigned int i = count; i != 0; i--) {
        Element* a = (Element*)list->sub_82a280();
        Element* b = (Element*)list->sub_82a280();
        if (a && b)
            a->f55(b, 0);
    }
}
}   // namespace f3m_00ab9d10

// @f3 0x00aad310 (community match, verified in this file)
extern unsigned char DAT_0116d984;
namespace f3m_00aad310 {

struct FUN_00aad310_Owner
{
    void* unk0;
    void FUN_00aad310();
};

// pdb: BSOcclusionQuery::End | BSOcclusionQuery.obj | fnv360_0822_retail, call_gap, medium
void FUN_00aad310_Owner::FUN_00aad310()
{
    if (DAT_0116d984 == 0)
        return;
    DAT_0116d984 = 0;
    void* x = unk0;
    void* y = *(void**)x;
    void(__stdcall * fn)(void*, int) = *(void(__stdcall**)(void*, int))((char*)y + 0x18);
    fn(x, 1);
}
}   // namespace f3m_00aad310

// @f3 0x00aaadc0 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace f3m_00aaadc0 {
extern "C" __declspec(dllimport) long __stdcall FUN_00d9b06c(volatile long* dest, long exchange, long comparand);
extern "C" __declspec(dllimport) unsigned long __stdcall FUN_00d9b090();

struct Lock {
    long volatile owner;
    unsigned int depth;
    void FUN_00409a80(const char* source);
    void Release()
    {
        if (--depth == 0) {
            const long previousOwner = owner;
            FUN_00d9b06c(&owner, 0, previousOwner);
        }
    }
};
extern Lock DAT_0116d740;

struct RefObj {
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
};
struct RefPtr {
    RefObj* p;
    ~RefPtr() { if (p) { RefObj* o = p; if (InterlockedDecrement(&o->refs) == 0) o->DeleteThis(); } }
};

struct RefList {
    void* vtable;
    RefObj** data;
    unsigned short maxSize;
    unsigned short capacity;
    unsigned short count;
    unsigned short growBy;
    RefPtr FUN_006e2e40(unsigned int index);
    void FUN_005574c0(unsigned int size);
};
extern RefList DAT_010667f0;
extern unsigned long DAT_010667ec;

// pdb: NiObjectGarbage::Update | NiObjectGarbage.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00aaadc0()
{
    DAT_0116d740.FUN_00409a80(0);
    unsigned long start = FUN_00d9b090();
    unsigned long deadline = DAT_010667ec + start;
    unsigned int count = DAT_010667f0.count;
    unsigned long now = 0;
    if (count > 200)
        deadline += 1000;
    while (count > 0 && now < deadline) {
        {
            RefPtr removed = DAT_010667f0.FUN_006e2e40(count - 1);
        }
        now = FUN_00d9b090();
        count--;
    }
    if (count == 0 && DAT_010667f0.capacity > 100)
        DAT_010667f0.FUN_005574c0(100);
    DAT_0116d740.Release();
}
}

// @f3 0x00ab9e10 (community match, verified in this file)
namespace f3m_00ab9e10 {
namespace f3m_00ab9e10 {
class ViewerStrings {
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
    unsigned int FUN_00ab9e10(char* const& value);
    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};
// pdb: NiTArray<unsigned int,NiTMallocInterface<unsigned int> >::Add | TESObjectTREE.obj | fnv360_0822_retail, call_seq, medium
// pdb params: element
unsigned int ViewerStrings::FUN_00ab9e10(char* const& value)
{
    unsigned int index = firstFree;
    if (index >= capacity)
        FUN_00555790(index + growBy);
    FUN_005b3880(index, value);
    return index;
}
}
}   // namespace f3m_00ab9e10

// @f3 0x00ab7ed0 (community match, verified in this file)
#include <string.h>
namespace f3m_00ab7ed0 {
struct MemoryManager { void* FUN_0086b930(unsigned int size); };
extern MemoryManager DAT_01090a78;
int FUN_00403230(char* buf, unsigned int n, const char* fmt, ...);
class Controller {
public:
    char* FUN_00ab7ed0(const char* label, unsigned int value);
};
// pdb: BSPSysArrayEmitter::GetViewerString | BSPSysArrayEmitter.obj | fnv360_0822_retail, ustr, medium
// pdb params: apPrefix, aeType
char* Controller::FUN_00ab7ed0(const char* label, unsigned int value)
{
    unsigned int size = strlen(label) + 0x10;
    char* text = (char*)DAT_01090a78.FUN_0086b930(size);
    switch (value) {
    case 0:
        FUN_00403230(text, size, "%s = AT_VERTICES", label);
        break;
    case 1:
        FUN_00403230(text, size, "%s = AT_SPECIFICOBJS", label);
        break;
    case 2:
        FUN_00403230(text, size, "%s = AT_NODES", label);
        break;
    }
    return text;
}
}

// @f3 0x00ab42f0 (community match, verified in this file)
namespace f3m_00ab42f0 {
namespace f3m_00ab42f0 {
struct Item;
struct ItemList { void FUN_0066bcc0(Item* const& item); };
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10;
    ItemList items;
    void FUN_00ab42f0(Item* item);
};
// pdb: BSPortalGraph::RemovePortal | BSPortalGraph.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apPortal
void Owner::FUN_00ab42f0(Item* item)
{
    if (item)
        items.FUN_0066bcc0(item);
}
}
}   // namespace f3m_00ab42f0

// @f3 0x00aa4780 (community match, verified in this file)
namespace f3m_00aa4780 {
struct MemoryManager { void FUN_0086ba60(void* memory); };
extern MemoryManager DAT_01090a78;
struct Base {
    virtual ~Base() {}
};
struct Pool : Base {
    void* blocks;
    int unk08;
    void* table;
    void FUN_00aa44f0(bool freeAll);
    virtual ~Pool();
};
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::~LockFreeMap<__int64,NiPointer<BSTask<__int64> > > | IOManager.obj | fnv360_0822_retail, call_seq, medium
Pool::~Pool()
{
    FUN_00aa44f0(true);
    DAT_01090a78.FUN_0086ba60(table);
    { void* volatile p = blocks; void* q = p; DAT_01090a78.FUN_0086ba60(q); }
}
}

// @f3 0x00ab95d0 (community match, verified in this file)
#include <new>
namespace f3m_00ab95d0 {
struct Heap { void* FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
struct Point3 { float x, y, z; __forceinline Point3() {} };
struct BoxPoints { unsigned short count, unk02; Point3 first[8], second[8]; BoxPoints* FUN_00ab93e0(); };
__forceinline BoxPoints* CreateBox() { BoxPoints* p = (BoxPoints*)DAT_01090a78.FUN_0086b930(sizeof(BoxPoints)); if (p) { new (p) BoxPoints; return p->FUN_00ab93e0(); } return 0; }
struct CloningProcess;
struct DecalExtra {
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned short count, unk12;
    BoxPoints* groups[8];
    void* listHead;
    void* listTail;
    unsigned int listCount;
    void FUN_00863e90(DecalExtra* dest, CloningProcess& process);
    void BSDecalPlacementVectorExtraData_CopyMembers(DecalExtra* dest, CloningProcess& process);
};
// pdb: BSDecalPlacementVectorExtraData::CopyMembers | BSDecalPVExtraData.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_seq) + skyrim(caller_sim), high
void DecalExtra::BSDecalPlacementVectorExtraData_CopyMembers(DecalExtra* dest, CloningProcess& process)
{
    FUN_00863e90(dest, process);
    dest->count = count;
    for (int i = 0; i < count; ++i) {
        dest->groups[i] = CreateBox();
        dest->groups[i]->count = groups[i]->count;
        for (int j = 0; j < groups[i]->count; ++j) {
            dest->groups[i]->first[j] = groups[i]->first[j];
            dest->groups[i]->second[j] = groups[i]->second[j];
        }
    }
}
}

// @f3 0x00aba140 (community match, verified in this file)
namespace f3m_00aba140 {
namespace f3m_00aba140 {
struct NiObject;
struct BinaryWrite_aba140 {
    unsigned int unk00;
    unsigned int position;
    unsigned int unk08;
    unsigned int(__cdecl* write)(BinaryWrite_aba140*, const void*, unsigned int, const unsigned int*, unsigned int);
};
struct ComponentSize_aba140 {
    unsigned int size;
    __forceinline ComponentSize_aba140(unsigned int value) : size(value) {}
    __forceinline operator const unsigned int*() const { return &size; }
};
struct NiStream_aba140 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void SaveLinkedObject(NiObject* object);
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
    BinaryWrite_aba140* binary;
};
struct NiExtraData_aba140 {
    void SaveBinary(NiStream_aba140& stream);
};
struct Holder00aba140 : NiExtraData_aba140 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiObject** items;
    unsigned int count;
    void FUN_00aba140(NiStream_aba140& stream);
};
// pdb: BSTextureData::SaveBinary | BSTextureData.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Holder00aba140::FUN_00aba140(NiStream_aba140& stream)
{
    SaveBinary(stream);
    unsigned int n = count;
    BinaryWrite_aba140* binary = stream.binary;
    binary->position += binary->write(binary, &n, 4, ComponentSize_aba140(4), 1);
    for (unsigned int i = 0; i < count; ++i) {
        stream.SaveLinkedObject(items[i]);
    }
}
}
}   // namespace f3m_00aba140

// @f3 0x00ab9d80 (community match, verified in this file)
namespace f3m_00ab9d80 {
namespace f3m_00ab9d80 {
struct NiBinaryStream {
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream* stream, const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        unsigned int written = m_pfnWrite(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += written;
        return written;
    }
};
template <class T> inline void NiStreamSaveBinary(NiBinaryStream& stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(&value, sizeof(T), &size, 1);
}
struct NiObject;
struct NiStream {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void SaveLinkID(const void* object);
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c;
    NiBinaryStream* m_pkOstr;
};
struct Child { int unk00, unk04, unk08, unk0c, unk10, unk14; NiObject* target; };
struct Base { void FUN_0078c030(NiStream* stream); };
struct Controller : Base {
    void* vtable;
    int unk04, unk08;
    Child** children;
    int unk10;
    unsigned short count;
    void FUN_00ab9d80(NiStream* stream);
};
// pdb: BSNodeReferences::SaveBinary | BSReference.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Controller::FUN_00ab9d80(NiStream* stream)
{
    FUN_0078c030(stream);
    unsigned int count2 = count;
    unsigned int value = count2 * 2;
    NiStreamSaveBinary(*stream->m_pkOstr, value);
    for (unsigned int i = 0; i < count2; i++) {
        Child* child = children[i];
        if (child) {
            stream->SaveLinkID(child->target);
            stream->SaveLinkID(child);
        }
    }
}
}
}   // namespace f3m_00ab9d80

// @f3 0x00aa1f90 (community match, verified in this file)
namespace f3m_00aa1f90 {
namespace f3m_00aa1f90 {
struct Handler {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual bool Handle(int event);
};
struct Node {
    Node* next;
    Node* prev;
    Handler* item;
    Handler*& Get() { return item; }
};
struct Dispatcher {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8;
    Handler* primary;
    int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc;
    Node* head;
    Node* tail;
    int count;
    void FUN_00aa1f90(int event);
};
// pdb: BSMultiBoundRoom::QPointWithin | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aPoint
void Dispatcher::FUN_00aa1f90(int event)
{
    if (primary->Handle(event))
        return;
    if (!count)
        return;
    Node* node = head;
    bool handled = false;
    while (!handled) {
        if (!node)
            break;
        Handler*& handler = node->Get();
        node = node->next;
        handled = handler->Handle(event);
    }
}
}
}   // namespace f3m_00aa1f90

// @f3 0x00ab0e80 (community match, verified in this file)
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec00(void*);
namespace f3m_00ab0e80 {
struct NiFixedString { char* handle; };
extern NiFixedString DAT_0108f3fc;
struct NiObject {
    void* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ec00(p); }
    NiObject();
    void FUN_008245d0(const NiFixedString& name);
};
// pdb: BSBound::CreateObject | BSBound.obj | fnv360_0822_retail, objrun, medium
NiObject* __cdecl FUN_00ab0e80()
{
    NiObject* object = new NiObject;
    object->FUN_008245d0(DAT_0108f3fc);
    return object;
}
}

// @f3 0x00aa2560 (community match, verified in this file)
namespace f3m_00aa2560 {
struct FUN_00aa2560_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    void FUN_00aa2560();
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapIterator::ClearKey | IOManager.obj | fnv360_0822_retail, vtable, medium
void FUN_00aa2560_Obj::FUN_00aa2560() {
    unk10 = 0;
    unk14 = 0;
}
}   // namespace f3m_00aa2560

// @f3 0x00aa6130 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace f3m_00aa6130 {

struct MemoryManager {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};
extern MemoryManager DAT_01090a78;
extern char* FUN_00e207a8;

struct FixedString {
    char* value;
    ~FixedString()
    {
        if (value != FUN_00e207a8)
            InterlockedDecrement((volatile long*)(value - 8));
    }
    static void operator delete(void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
};

extern FixedString* DAT_0116d6e0;

// pdb: BSXFlags::KillSDM | BSXFlags.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSTaskManager::ForceSignal)
void __cdecl FUN_00aa6130()
{
    delete DAT_0116d6e0;
    DAT_0116d6e0 = 0;
}

}

// @f3 0x00aa7d20 (community match, verified in this file)
extern "C" char DAT_01090a78;
namespace f3m_00aa7d20 {
namespace f3m_00aa7d20 {
struct FUN_00aa54a0_s { void Deallocate(void* p); };
class MemMgr5 { public: FUN_00aa54a0_s* GetCtx(); };
class Owner_00aa7d20 {
public:
    int unk00;
    int unk04;
    char* m08;
    int unk0C;
    int m10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54;
    int unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C;
    unsigned int m90;
    void FUN_00aa7d20(unsigned int* src);
};
// pdb: BSCompoundFrustum::SetActivePlaneState | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apPlaneState
void Owner_00aa7d20::FUN_00aa7d20(unsigned int* src)
{
    m90 = src[0];
    int i = 1;
    if (m24 + 1 > 1)
    {
        do
        {
            if (i >= m10)
                break;
            *(unsigned int*)(m08 + 100 * i - 4) = src[i];
            ++i;
        } while (i < m24 + 1);
    }
    FUN_00aa54a0_s* ctx = ((MemMgr5*)&DAT_01090a78)->GetCtx();
    ctx->Deallocate(src);
}
}
}   // namespace f3m_00aa7d20

// @f3 0x00ab0ca0 (community match, verified in this file)
namespace f3m_00ab0ca0 {
namespace f3m_00ab0ca0 {
struct NiObject;
struct Obj {
    bool FUN_008459a0(NiObject* other);
    bool FUN_00ab0ca0(NiObject* other);
};
// pdb: BSBound::RegisterStreamables | BSBound.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSNonUniformScaleExtraData::RegisterStreamables)
// pdb params: arStream
bool Obj::FUN_00ab0ca0(NiObject* other)
{
    return !FUN_008459a0(other);
}
}
}   // namespace f3m_00ab0ca0

// @f3 0x00aaf6a0 (community match, verified in this file)
namespace f3m_00aaf6a0 {
namespace f3m_00aaf6a0 {
struct NiObject;
struct NiStream { NiObject* FUN_0082a280(); };
struct LinkArray {
    NiObject** data;
    unsigned int unk04;
    unsigned int size;
    void SetAt(unsigned int index, NiObject* value) { if (index < size) data[index] = value; }
};
struct Base { void FUN_008380f0(NiStream* stream); };
struct Node : Base {
    void* vtable;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    LinkArray** lists;
    unsigned short unk44;
    unsigned short count;
    void FUN_00aaf6a0(NiStream* stream);
};
// pdb: NiBSBoneLODController::LinkObject | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Node::FUN_00aaf6a0(NiStream* stream)
{
    FUN_008380f0(stream);
    for (unsigned int i = 0; i < count; i++) {
        LinkArray* list = lists[i];
        if (list) {
            for (unsigned int j = 0; j < list->size; j++)
                list->SetAt(j, stream->FUN_0082a280());
        }
    }
}
}
}   // namespace f3m_00aaf6a0

// @f3 0x00aa4990 (community match, verified in this file)
namespace f3m_00aa4990 {
namespace f3m_00aa4990 {
struct Settings {
    int FUN_00aa4990(__int64 key);
};
// pdb: IOManager::GetBucketForKey | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiKey
int Settings::FUN_00aa4990(__int64 key)
{
    unsigned char group = (unsigned char)(key >> 16);
    unsigned char index = (unsigned char)(key >> 56);
    return index + group * 4;
}
}
}   // namespace f3m_00aa4990

// @f3 0x00ab5180 (community match, verified in this file)
namespace f3m_00ab5180 {
namespace f3m_00ab5180 {
struct NiBinaryStream {
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream* stream, const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        unsigned int written = m_pfnWrite(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += written;
        return written;
    }
};
template <class T> inline void NiStreamSaveBinary(NiBinaryStream& stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(&value, sizeof(T), &size, 1);
}
struct NiObject;
struct NiStream {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void SaveLinkID(const void* object);
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c;
    NiBinaryStream* m_pkOstr;
};
struct Base { void FUN_00abbc50(NiStream* stream); };
struct Controller : Base {
    void* vtable;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58;
    NiObject* target;
    unsigned short flags;
    void BSPSysMultiTargetEmitterCtlr_SaveBinary(NiStream* stream);
};
// pdb: BSPSysMultiTargetEmitterCtlr::SaveBinary | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void Controller::BSPSysMultiTargetEmitterCtlr_SaveBinary(NiStream* stream)
{
    FUN_00abbc50(stream);
    NiStreamSaveBinary(*stream->m_pkOstr, flags);
    stream->SaveLinkID(target);
}
}
}   // namespace f3m_00ab5180

// @f3 0x00ab0c70 (community match, verified in this file)
namespace f3m_00ab0c70 {
struct Ab0c70Part {
    int unk00;
    int unk04;
    int unk08;

    void __thiscall FUN_00823eb0(int argument);
};

class Ab0c70Owner {
public:
    int unk00;
    int unk04;
    int unk08;
    Ab0c70Part part0C;
    Ab0c70Part part18;

    void __thiscall FUN_00ab0c70(int argument);
};

void __stdcall FUN_00845bc0(int argument);

// pdb: BSBound::LoadBinary | BSBound.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSNonUniformScaleExtraData::LoadBinary)
// pdb params: arStream
void __thiscall Ab0c70Owner::FUN_00ab0c70(int argument) {
    FUN_00845bc0(argument);
    part0C.FUN_00823eb0(argument);
    part18.FUN_00823eb0(argument);
}
}   // namespace f3m_00ab0c70

// @f3 0x00aa7c50 (community match, verified in this file)
namespace f3m_00aa7c50 {
namespace FrustumPlanes {
struct Frustum { int unk00; };
struct Transform { int unk00; };
class Planes { public: void NiFrustumPlanes_Set(const Frustum* frustum, const Transform* transform); };
}
namespace f3m_00aa7c50 {
struct Triple_a7c50 { int a, b, c; };
class Owner_00aa7c50 {
public:
    unsigned char unk00;
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
    unsigned char unkA0;
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
    void FUN_00aa7c50(Owner_00aa7c50* other);
};
// pdb: BSCompoundFrustum::SetCamera | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apCamera
void Owner_00aa7c50::FUN_00aa7c50(Owner_00aa7c50* other)
{
    if (other)
    {
        reinterpret_cast<FrustumPlanes::Planes*>(&unk30)->NiFrustumPlanes_Set(
            reinterpret_cast<FrustumPlanes::Frustum*>(&other->unkDC),
            reinterpret_cast<FrustumPlanes::Transform*>(&other->unk68));
        *(Triple_a7c50*)&unk94 = *(Triple_a7c50*)&other->unk8C;
    }
    unk24 = 0;
    unk28 = 0;
    unk00 = 0;
    unk2C = 0;
    unkA0 = 0;
}
}
}   // namespace f3m_00aa7c50

// @f3 0x00ab5fe0 (community match, verified in this file)
namespace f3m_00ab5fe0 {
class FUN_00c25de0_shell
{
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    unsigned short cnt50;
    float BSStripPSysData_GetPointLastUpdateTime(unsigned short idx);
};

class TrailSystem
{
public:
    void BSStripPSysData_UpdatePoints(unsigned short idx, float v);
};

struct TrailOwnerAB5
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    float unk18;
    void BSPSysStripUpdateModifier_Update(float a, FUN_00c25de0_shell* obj);
};

// pdb: BSPSysStripUpdateModifier::Update | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objopen_prop), high
void TrailOwnerAB5::BSPSysStripUpdateModifier_Update(float a, FUN_00c25de0_shell* obj)
{
    unsigned short n = obj->cnt50;
    for (unsigned short i = 0; i < n; i++)
    {
        double ad = a;
        float d = (float)(ad - obj->BSStripPSysData_GetPointLastUpdateTime(i));
        if (d > this->unk18)
            ((TrailSystem*)obj)->BSStripPSysData_UpdatePoints(i, a);
    }
}
}   // namespace f3m_00ab5fe0

// @f3 0x00aad3d0 (community match, verified in this file)
namespace f3m_00aad3d0 {
struct StandIn_aad3d0 {
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
    int unk94[10];
    int unkBC;

    void FUN_00aad3d0();
};

// pdb: BSCullingProcess::PopCullMode | BSCullingProcess.obj | fnv360_0822_retail, call_gap, medium
void StandIn_aad3d0::FUN_00aad3d0() {
    unkBC--;
    unk90 = unk94[unkBC];
}
}   // namespace f3m_00aad3d0

// @f3 0x00aa5f20 (community match, verified in this file)
namespace f3m_00aa5f20 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
const char* __cdecl FUN_008242a0(const char* text);   // pooled string handle for text
struct NameHolder {
    const char* name;
    explicit NameHolder(const char* text) { name = FUN_008242a0(text); }
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116d6e0;
}

// pdb: BSXFlags::InitSDM | BSXFlags.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00aa5f20()
{
    f3m_00aa5f20::DAT_0116d6e0 = new f3m_00aa5f20::NameHolder("BSX");
}

// @f3 0x00ab01f0 (community match, verified in this file)
namespace f3m_00ab01f0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
const char* __cdecl FUN_008242a0(const char* text);   // pooled string handle for text
struct NameHolder {
    const char* name;
    explicit NameHolder(const char* text) { name = FUN_008242a0(text); }
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116da60;
}

// pdb: BSFurnitureMarker::InitSDM | BSFurnitureMarker.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab01f0()
{
    f3m_00ab01f0::DAT_0116da60 = new f3m_00ab01f0::NameHolder("FRN");
}

// @f3 0x00ab7b90 (community match, verified in this file)
namespace f3m_00ab7b90 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
const char* __cdecl FUN_008242a0(const char* text);   // pooled string handle for text
struct NameHolder {
    const char* name;
    explicit NameHolder(const char* text) { name = FUN_008242a0(text); }
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116eb64;
}

// pdb: BSWArray::InitSDM | BSWArray.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab7b90()
{
    f3m_00ab7b90::DAT_0116eb64 = new f3m_00ab7b90::NameHolder("BSW");
}

// @f3 0x00ab7e40 (community match, verified in this file)
namespace f3m_00ab7e40 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
const char* __cdecl FUN_008242a0(const char* text);   // pooled string handle for text
struct NameHolder {
    const char* name;
    explicit NameHolder(const char* text) { name = FUN_008242a0(text); }
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116eb70;
}

// pdb: PArrayPoint::InitSDM | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab7e40()
{
    f3m_00ab7e40::DAT_0116eb70 = new f3m_00ab7e40::NameHolder("PAP");
}

// @f3 0x00aba030 (community match, verified in this file)
namespace f3m_00aba030 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
const char* __cdecl FUN_008242a0(const char* text);   // pooled string handle for text
struct NameHolder {
    const char* name;
    explicit NameHolder(const char* text) { name = FUN_008242a0(text); }
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116ebb0;
}

// pdb: BSTextureData::InitSDM | BSTextureData.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00aba030()
{
    f3m_00aba030::DAT_0116ebb0 = new f3m_00aba030::NameHolder("TXD");
}

// @f3 0x00ab0400 (community match, verified in this file)
namespace f3m_00ab0400 {
namespace f3m_00ab0400 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
extern char* DAT_0109b220;   // the empty pooled string
struct NameHolder {
    char* name;
    ~NameHolder()
    {
        if (name != DAT_0109b220)
            InterlockedDecrement((long*)(name - 8));
    }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116da60;
}

// pdb: BSFurnitureMarker::KillSDM | BSFurnitureMarker.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab0400()
{
    delete f3m_00ab0400::DAT_0116da60;
    f3m_00ab0400::DAT_0116da60 = 0;
}
}   // namespace f3m_00ab0400

// @f3 0x00ab0f20 (community match, verified in this file)
namespace f3m_00ab0f20 {
namespace f3m_00ab0f20 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
extern char* DAT_0109b220;   // the empty pooled string
struct NameHolder {
    char* name;
    ~NameHolder()
    {
        if (name != DAT_0109b220)
            InterlockedDecrement((long*)(name - 8));
    }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116da80;
}

// pdb: BSBound::KillSDM | BSBound.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab0f20()
{
    delete f3m_00ab0f20::DAT_0116da80;
    f3m_00ab0f20::DAT_0116da80 = 0;
}
}   // namespace f3m_00ab0f20

// @f3 0x00ab7d10 (community match, verified in this file)
namespace f3m_00ab7d10 {
namespace f3m_00ab7d10 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
extern char* DAT_0109b220;   // the empty pooled string
struct NameHolder {
    char* name;
    ~NameHolder()
    {
        if (name != DAT_0109b220)
            InterlockedDecrement((long*)(name - 8));
    }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116eb64;
}

// pdb: BSWArray::KillSDM | BSWArray.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab7d10()
{
    delete f3m_00ab7d10::DAT_0116eb64;
    f3m_00ab7d10::DAT_0116eb64 = 0;
}
}   // namespace f3m_00ab7d10

// @f3 0x00ab8440 (community match, verified in this file)
namespace f3m_00ab8440 {
namespace f3m_00ab8440 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
extern char* DAT_0109b220;   // the empty pooled string
struct NameHolder {
    char* name;
    ~NameHolder()
    {
        if (name != DAT_0109b220)
            InterlockedDecrement((long*)(name - 8));
    }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116eb70;
}

// pdb: PArrayPoint::KillSDM | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab8440()
{
    delete f3m_00ab8440::DAT_0116eb70;
    f3m_00ab8440::DAT_0116eb70 = 0;
}
}   // namespace f3m_00ab8440

// @f3 0x00aba1b0 (community match, verified in this file)
namespace f3m_00aba1b0 {
namespace f3m_00aba1b0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
extern char* DAT_0109b220;   // the empty pooled string
struct NameHolder {
    char* name;
    ~NameHolder()
    {
        if (name != DAT_0109b220)
            InterlockedDecrement((long*)(name - 8));
    }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116ebb0;
}

// pdb: BSTextureData::KillSDM | BSTextureData.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSReference::CreateObject)
void __cdecl FUN_00aba1b0()
{
    delete f3m_00aba1b0::DAT_0116ebb0;
    f3m_00aba1b0::DAT_0116ebb0 = 0;
}
}   // namespace f3m_00aba1b0

// @f3 0x00aba5b0 (community match, verified in this file)
namespace f3m_00aba5b0 {
namespace f3m_00aba5b0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
extern char* DAT_0109b220;   // the empty pooled string
struct NameHolder {
    char* name;
    ~NameHolder()
    {
        if (name != DAT_0109b220)
            InterlockedDecrement((long*)(name - 8));
    }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern NameHolder* DAT_0116ebbc;
}

// pdb: BSAttachPoints::KillSDM | BSAttachPoints.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00aba5b0()
{
    delete f3m_00aba5b0::DAT_0116ebbc;
    f3m_00aba5b0::DAT_0116ebbc = 0;
}
}   // namespace f3m_00aba5b0

// @f3 0x00aaa230 (community match, verified in this file)
namespace f3m_00aaa230 {
namespace f3m_00aaa230 {
struct BaseData {
    bool FUN_0082e410(const void* other);   // base-class compare/copy
};
struct Target {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(const void* other);
};
struct Data : BaseData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
    Target* target;
    bool FUN_00aaa230(const void* other);
};
}

// pdb: BSMultiBoundNode::RegisterStreamables | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSFadeNode::RegisterStreamables)
// pdb params: arStream
bool f3m_00aaa230::Data::FUN_00aaa230(const void* other)
{
    if (!FUN_0082e410(other))
        return false;
    target->v54(other);
    return true;
}
}   // namespace f3m_00aaa230

// @f3 0x00ab5f70 (community match, verified in this file)
namespace f3m_00ab5f70 {
namespace f3m_00ab5f70 {
struct BaseData {
    bool FUN_00ac5f20(const void* other);   // base-class compare/copy
};
struct Data : BaseData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    float value;
    char FUN_00ab5f70(const Data* other);
};
}

// pdb: BSPSysStripUpdateModifier::IsEqual | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkObject
char f3m_00ab5f70::Data::FUN_00ab5f70(const Data* other)
{
    if (FUN_00ac5f20(other) && other->value == value)
        return 1;
    return 0;
}
}   // namespace f3m_00ab5f70

// @f3 0x00ab4ba0 (community match, verified in this file)
namespace f3m_00ab4ba0 {
namespace f3m_00ab4ba0 {
struct BaseData {
    bool FUN_00abbc70(const void* other);   // base-class compare/copy
};
struct Data : BaseData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58;
    int value5C;
    unsigned short value60;
    char BSPSysMultiTargetEmitterCtlr_IsEqual(const Data* other);
};
}

// pdb: BSPSysMultiTargetEmitterCtlr::IsEqual | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
char f3m_00ab4ba0::Data::BSPSysMultiTargetEmitterCtlr_IsEqual(const Data* other)
{
    if (FUN_00abbc70(other) && value5C == other->value5C && value60 == other->value60)
        return 1;
    return 0;
}
}   // namespace f3m_00ab4ba0

// @f3 0x00aaa9a0 (community match, verified in this file)
namespace f3m_00aaa9a0 {
namespace f3m_00aaa9a0 {
struct BaseData {
    bool FUN_00ac5f20(const void* other);   // base-class compare/copy
};
struct Data : BaseData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    float value;
    char FUN_00aaa9a0(const Data* other);
};
}

// pdb: BSWindModifier::IsEqual | BSWindModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
char f3m_00aaa9a0::Data::FUN_00aaa9a0(const Data* other)
{
    char equal = FUN_00ac5f20(other);
    if (equal) {
        if (value == other->value)
            equal = 1;
        else
            equal = 0;
    }
    return equal;
}
}   // namespace f3m_00aaa9a0

// @f3 0x00ab8ea0 (community match, verified in this file)
namespace f3m_00ab8ea0 {
namespace f3m_00ab8ea0 {
struct BaseData {
    bool FUN_00ac5f20(const void* other);   // base-class compare/copy
};
struct Data : BaseData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    float value;
    char FUN_00ab8ea0(const Data* other);
};
}

// pdb: BSParentVelocityModifier::IsEqual | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
char f3m_00ab8ea0::Data::FUN_00ab8ea0(const Data* other)
{
    char equal = FUN_00ac5f20(other);
    if (equal) {
        if (other->value == value)
            equal = 1;
        else
            equal = 0;
    }
    return equal;
}
}   // namespace f3m_00ab8ea0

// @f3 0x00aa6bb0 (community match, verified in this file)
namespace f3m_00aa6bb0 {
struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;
class ExtraBase {
public:
    ExtraBase();               // 0x00825800
    virtual ~ExtraBase();
    int unk04;
};
class ArrayBase {
public:
    virtual ~ArrayBase();
    void* data;
    unsigned short maxSize;
    unsigned short size;
    unsigned short emptyRunStart;
    unsigned short growBy;
    ArrayBase(unsigned int maxSz, unsigned int grow)
    {
        maxSize = (unsigned short)maxSz;
        size = 0;
        emptyRunStart = 0;
        if (maxSize > 0)
            data = DAT_01090a78.FUN_0086b930(maxSize * 4);
        else
            data = 0;
        growBy = (unsigned short)grow;
    }
};
class PrimitiveArray : public ArrayBase {
public:
    PrimitiveArray() : ArrayBase(0, 1) {}
    virtual ~PrimitiveArray();
};
}
class BSNodeReferences : public f3m_00aa6bb0::ExtraBase { // src: F3_EXE vtable 0x00e89cb4 (old: FUN_00aa6bb0)
public:
    BSNodeReferences();
    virtual ~BSNodeReferences();
    f3m_00aa6bb0::PrimitiveArray items;
};

// pdb: BSNodeReferences::BSNodeReferences | BSStream.obj | fnv360_0822_debug, call_gap, low
BSNodeReferences::BSNodeReferences()
{
}

// @f3 0x00ab0f60 (community match, verified in this file)
extern const char* DAT_0116da84;
namespace f3m_00ab0f60 {
char* __cdecl FUN_00847b50(const char* label);
struct ViewerPoint3
{
    char* FUN_00823dc0(const char* label);
    float x, y, z;
};
class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};
class FUN_00ab0f60_Class
{
public:
    void FUN_00845ca0(ViewerStrings* strings);
    void FUN_00ab0f60(ViewerStrings* strings);

    int unk00;
    int unk04;
    int unk08;
    ViewerPoint3 center;
    ViewerPoint3 extents;
};
// pdb: BSBound::GetViewerStrings | BSBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void FUN_00ab0f60_Class::FUN_00ab0f60(ViewerStrings* strings)
{
    FUN_00845ca0(strings);
    strings->Add(FUN_00847b50(DAT_0116da84));
    static const char* const centerLabel = "Center";
    strings->Add(center.FUN_00823dc0(centerLabel));
    static const char* const extentsLabel = "Extents";
    strings->Add(extents.FUN_00823dc0(extentsLabel));
}
}   // namespace f3m_00ab0f60

// @f3 0x00ab7d50 (community match, verified in this file)
extern const char* DAT_0116eb68;
namespace f3m_00ab7d50 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847d80(const char* label, unsigned int value);
class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};
class FUN_00ab7d50_Class
{
public:
    void FUN_00863d60(ViewerStrings* strings);
    void FUN_00ab7d50(ViewerStrings* strings);

    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiSize;
};
// pdb: BSWArray::GetViewerStrings | BSWArray.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void FUN_00ab7d50_Class::FUN_00ab7d50(ViewerStrings* strings)
{
    FUN_00863d60(strings);
    strings->Add(FUN_00847b50(DAT_0116eb68));
    static const char* const sizeLabel = "m_uiSize";
    strings->Add(FUN_00847d80(sizeLabel, m_uiSize));
}
}   // namespace f3m_00ab7d50

// @f3 0x00aa9f80 (community match, verified in this file)
namespace f3m_00aa9f80 {
extern int (__stdcall *FUN_00d9b068)(volatile long*);

typedef void (__cdecl *FUN_00aa9f80_Callback)(void*, unsigned int);

struct FUN_00aa9f80_Object
{
    FUN_00aa9f80_Callback unk00;
    void* unk04;
    unsigned int unk08;
    volatile long unk0C;
};

// pdb: BSParallelTaskThread::`scalar deleting destructor' | BSParallelTaskManager.obj | fnv360_0721_beta, objrun, medium
void __cdecl FUN_00aa9f80(FUN_00aa9f80_Object* object)
{
    unsigned int index = 0;
    while (index < object->unk08) {
        index = InterlockedIncrement(&object->unk0C) - 1;
        if (index < object->unk08)
            object->unk00(object->unk04, index);
    }
}
}   // namespace f3m_00aa9f80

// @f3 0x00aa5df0 (community match, verified in this file)
struct GlobalObjectO2_00d472a0 { };
extern GlobalObjectO2_00d472a0 g_01269fe8;
extern const char DAT_0116d880[];
int __cdecl FUN_00ec65a6(char* buffer, unsigned int size, const char* format);
int __cdecl _strcat_s(char* dest, unsigned int size, const char* src);

// pdb: MessageHandler::SetProgrammerOutputFileName | MessageHandler.obj | fnv360_0721_retail, objrun, medium
// pdb params: apFileName
void __cdecl FUN_00aa5df0(const char* arg)
{
    FUN_00ec65a6((char*)&g_01269fe8, 0x104, DAT_0116d880);
    _strcat_s((char*)&g_01269fe8, 0x104, arg);
}

// @f3 0x00ab8590 (community match, verified in this file)
namespace f3m_00ab8590 {
namespace f3m_00ab8590 {
void* __cdecl FUN_0089eb90(unsigned int bytes);   // NiMemObject operator new
void __cdecl FUN_0089ebb0(void* p);               // NiMemObject operator delete
}
class FUN_00ab8480 {
public:
    FUN_00ab8480();
    static void* operator new(unsigned int bytes) { return f3m_00ab8590::FUN_0089eb90(bytes); }
    static void operator delete(void* p) { f3m_00ab8590::FUN_0089ebb0(p); }
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
};

FUN_00ab8480* __cdecl FUN_00ab8590()
{
    return new FUN_00ab8480;
}
}   // namespace f3m_00ab8590

// @f3 0x00aafc50 (community match, verified in this file)
namespace f3m_00aafc50 {
namespace f3m_00aafc50 {
void* __cdecl FUN_0089eb90(unsigned int bytes);   // NiMemObject operator new
void __cdecl FUN_0089ebb0(void* p);               // NiMemObject operator delete
class FUN_00aaf800 {
public:
    FUN_00aaf800();
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
};
}

// pdb: NiBSBoneLODController::CreateObject | NiBSBoneLODController.obj | fnv360_0822_debug, objrun, medium
f3m_00aafc50::FUN_00aaf800* __cdecl FUN_00aafc50()
{
    return new f3m_00aafc50::FUN_00aaf800;
}
}   // namespace f3m_00aafc50

// @f3 0x00ab8ff0 (community match, verified in this file)
namespace f3m_00ab8ff0 {
namespace f3m_00ab8ff0 {
void* __cdecl FUN_0089eb90(unsigned int bytes);   // NiMemObject operator new
void __cdecl FUN_0089ebb0(void* p);               // NiMemObject operator delete
class FUN_00ab8ed0 {
public:
    FUN_00ab8ed0();
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38;
};
}

// pdb: BSParentVelocityModifier::CreateObject | BSParentVelocityModifier.obj | fnv360_0822_retail, objrun, medium
f3m_00ab8ff0::FUN_00ab8ed0* __cdecl FUN_00ab8ff0()
{
    return new f3m_00ab8ff0::FUN_00ab8ed0;
}
}   // namespace f3m_00ab8ff0

// @f3 0x00ab9e50 (community match, verified in this file)
namespace f3m_00ab9e50 {
namespace f3m_00ab9e50 {
void* __cdecl FUN_0089eb90(unsigned int bytes);   // NiMemObject operator new
void __cdecl FUN_0089ebb0(void* p);               // NiMemObject operator delete
class BSNodeReferences { // src: F3_EXE vtable 0x00e89cb4 (old: FUN_00aa6bb0)
public:
    BSNodeReferences();
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
    int unk00, unk04, unk08, unk0c, unk10, unk14;
};
}

f3m_00ab9e50::BSNodeReferences* __cdecl FUN_00ab9e50()
{
    return new f3m_00ab9e50::BSNodeReferences;
}
}   // namespace f3m_00ab9e50

// @f3 0x00ab7ac0 (community match, verified in this file)
namespace f3m_00ab7ac0 {
namespace f3m_00ab7ac0 {
void* __cdecl FUN_0089eb90(unsigned int bytes);   // NiMemObject operator new
void __cdecl FUN_0089ebb0(void* p);               // NiMemObject operator delete
class FUN_00ab7930 {
public:
    FUN_00ab7930();
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
};
}

f3m_00ab7ac0::FUN_00ab7930* __cdecl FUN_00ab7ac0()
{
    return new f3m_00ab7ac0::FUN_00ab7930;
}
}   // namespace f3m_00ab7ac0

// @f3 0x00aa9bd0 (community match, verified in this file)
namespace f3m_00aa9bd0 {
namespace f3m_00aa9bd0 {
struct NiBinaryStream {
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream* stream, const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        unsigned int written = m_pfnWrite(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += written;
        return written;
    }
};
template <class T> inline void NiStreamSaveBinary(NiBinaryStream& stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(&value, sizeof(T), &size, 1);
}
struct NiObject;
struct NiStream {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void SaveLinkID(const void* object);
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c;
    NiBinaryStream* m_pkOstr;
};
struct Node {
    void* vtable;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8;
    unsigned char flagAC, flagAD, flagAE, flagAF;
    void FUN_0082e820(NiStream* stream);
    void FUN_00aa9bd0(NiStream* stream);
};
// pdb: BSRangeNode::SaveBinary | BSRangeNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Node::FUN_00aa9bd0(NiStream* stream)
{
    FUN_0082e820(stream);
    unsigned char value = flagAE;
    NiStreamSaveBinary(*stream->m_pkOstr, value);
    value = flagAF;
    NiStreamSaveBinary(*stream->m_pkOstr, value);
    value = flagAD;
    NiStreamSaveBinary(*stream->m_pkOstr, value);
}
}
}   // namespace f3m_00aa9bd0

// @f3 0x00ab5120 (community match, verified in this file)
namespace f3m_00ab5120 {
namespace f3m_00ab5120 {
struct NiBinaryStream {
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream* stream, void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        unsigned int read = m_pfnRead(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += read;
        return read;
    }
};
template <class T> inline void NiStreamLoadBinary(NiBinaryStream& stream, T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(&value, sizeof(T), &size, 1);
}
struct NiStream {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248;
    NiBinaryStream* m_pkIstr;
    int FUN_0082b5d0();
};
struct Base { void FUN_00abbc00(NiStream* stream); };
struct Controller : Base {
    void* vtable;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58;
    int target;
    unsigned short count;
    void BSPSysMultiTargetEmitterCtlr_LoadBinary(NiStream* stream);
};
// pdb: BSPSysMultiTargetEmitterCtlr::LoadBinary | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void Controller::BSPSysMultiTargetEmitterCtlr_LoadBinary(NiStream* stream)
{
    FUN_00abbc00(stream);
    NiStreamLoadBinary(*stream->m_pkIstr, count);
    if (count < 1)
        count = 1;
    target = stream->FUN_0082b5d0();
}
}
}   // namespace f3m_00ab5120

// @f3 0x00ab7120 (community match, verified in this file)
namespace f3m_00ab7120 {
namespace f3m_00ab7120 {
struct NiObject;
struct NiStream {
    int unk00;
    unsigned int version;
    NiObject* FUN_0082a280();
    unsigned int FUN_0082a2b0();
};
struct ObjectArray {
    void FUN_00555790(unsigned int size);
    void FUN_005b3880(unsigned int index, NiObject* const& value);
};
struct Base { void FUN_0082e780(NiStream* stream); };
struct Node : Base {
    void* vtable;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8;
    ObjectArray objects;
    void FUN_00ab7120(NiStream* stream);
};
// pdb: BSMasterParticleSystem::LinkObject | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Node::FUN_00ab7120(NiStream* stream)
{
    FUN_0082e780(stream);
    if (stream->version > 0xf) {
        unsigned int count = stream->FUN_0082a2b0();
        if (count) {
            objects.FUN_00555790(count);
            for (unsigned int i = 0; i < count; i++)
                objects.FUN_005b3880(i, stream->FUN_0082a280());
        }
    }
}
}
}   // namespace f3m_00ab7120

// @f3 0x00ab8dc0 (community match, verified in this file)
namespace f3m_00ab8dc0 {
namespace f3m_00ab8dc0 {
struct UpdateData {
    float time;
    bool flag4, flag5, flag6, flag7, flag8;
};
struct AVObject;
struct ChildArray {
    void* vtable;
    AVObject** data;
    unsigned short capacity, size;
};
struct Node {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    ChildArray children;
    void FUN_008264c0(UpdateData& data);
};
struct AVObject {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual Node* IsNode();
};
struct Sub { void FUN_00aaab30(); };
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50;
    AVObject* root;
    int unk58;
    Sub sub;
    void FUN_00ab8cc0(AVObject* child);
    void FUN_00ab8dc0();
};
}

// pdb: BSPSysArrayEmitter::SetupArray | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSSegmentedTriShape::MergeEnabledSegments)
void f3m_00ab8dc0::Owner::FUN_00ab8dc0()
{
    sub.FUN_00aaab30();
    AVObject* object = root;
    if (object) {
        Node* node = object->IsNode();
        if (node) {
            UpdateData data;
            data.time = 0.0f;
            data.flag4 = false;
            data.flag5 = false;
            data.flag6 = false;
            data.flag7 = false;
            data.flag8 = false;
            node->FUN_008264c0(data);
            unsigned int i = node->children.size;
            while (i != 0)
                FUN_00ab8cc0(node->children.data[--i]);
        }
    }
}
}   // namespace f3m_00ab8dc0

// @f3 0x00ab9a00 (community match, verified in this file)
extern void* const DAT_00e8ba2c[];
namespace f3m_00ab9a00 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec00(void*);
namespace f3m_00ab9a00 {
struct BoxPoints;
struct CloningProcess;
struct ExtraBase {
    void* const* vptr;
    unsigned int unk04, unk08, unk0C;
    void FUN_008459f0();
    ExtraBase() { FUN_008459f0(); }
};
struct DecalBase : ExtraBase {
    DecalBase() { unk0C = 0; vptr = DAT_00e8ba2c; }
};
struct DecalExtra : DecalBase {
    unsigned short count, unk12;
    BoxPoints* groups[8];
    void* listHead;
    void* listTail;
    unsigned int listCount;
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ec00(p); }
    DecalExtra()
    {
        listCount = 0;
        listHead = 0;
        listTail = 0;
        count = 0;
        for (int i = 0; i < 8; i++)
            groups[i] = 0;
    }
};
struct Source {
    void BSDecalPlacementVectorExtraData_CopyMembers(DecalExtra* dest, CloningProcess& process);
    DecalExtra* FUN_00ab9a00(CloningProcess& process);
};
// pdb: BSDecalPlacementVectorExtraData::CreateClone | BSDecalPVExtraData.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
DecalExtra* Source::FUN_00ab9a00(CloningProcess& process)
{
    DecalExtra* clone = new DecalExtra;
    BSDecalPlacementVectorExtraData_CopyMembers(clone, process);
    return clone;
}
}
}   // namespace f3m_00ab9a00

// @f3 0x00aac5f0 (community match, verified in this file)
namespace f3m_00aac5f0 {
namespace f3m_00aac5f0 {
struct Elem { int a, b, c; };
struct Array {
    int unk00;
    Elem* data;
    int count;
    void FUN_00aac5f0();
};
}

// pdb: BSSimpleArray<NiPoint3,1024>::Reverse | BSPolygon.obj | fnv360_0822_retail, objrun, medium
void f3m_00aac5f0::Array::FUN_00aac5f0()
{
    int j = count - 1;
    for (int i = 0; i < j; i++, j--) {
        Elem tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}
}   // namespace f3m_00aac5f0

// @f3 0x00aae690 (community match, verified in this file)
namespace f3m_00aae690 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace f3m_00aae690 {
struct Child {
    virtual void v0();
    virtual void DeleteThis();
    volatile long refCount;
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0;
    int slot;
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (InterlockedDecrement(&refCount) == 0) DeleteThis(); }
};
struct Node {
    void* vtable;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8;
    int* slots;
    void FUN_0082e680(Child* child, NiPointer<Child>& removed);
    void FUN_00aae690(Child* child, NiPointer<Child>& removed);
};
// pdb: BSParticleSystemManager::DetachChild | BSParticleSystemManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkChild, aspAVObject
void Node::FUN_00aae690(Child* child, NiPointer<Child>& removed)
{
    NiPointer<Child> detached;
    FUN_0082e680(child, detached);
    if (detached) {
        int index = detached->slot;
        slots[index] = -1;
    }
    removed = detached;
}
}
}   // namespace f3m_00aae690

// @f3 0x00ab5680 (community match, verified in this file)
namespace f3m_00ab5680 {
namespace f3m_00ab5680 {
void* __cdecl FUN_0089eb90(unsigned int bytes);   // NiMemObject operator new
void __cdecl FUN_0089ebb0(void* p);
class FUN_0083f520 {   // base, ctor 0x0083f520
public:
    FUN_0083f520();
    virtual ~FUN_0083f520();
    void NiTriShape_CopyMembers(FUN_0083f520* dest, void* cloning);   // base CopyMembers
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
};
class Light : public FUN_0083f520 {
public:
    Light() {}
    virtual ~Light();
    struct Quad { int a, b, c, d; } values;
    Light* FUN_00ab5680(void* cloning);
};
}

// pdb: BSScissorTriShape::CreateClone | BSScissorTriShape.obj | fnv360_0822_debug, vtable, low, conflict (skyrim: BSLODTriShape::CreateClone)
// pdb params: arCloneData
f3m_00ab5680::Light* f3m_00ab5680::Light::FUN_00ab5680(void* cloning)
{
    Light* clone = new Light;
    clone->values = values;
    NiTriShape_CopyMembers(clone, cloning);
    return clone;
}
}   // namespace f3m_00ab5680

// @f3 0x00aba270 (community match, verified in this file)
namespace f3m_00aba270 {
void* __cdecl FUN_0089eb90(unsigned int size);

struct Shape {
    int a, b, c, d, e, f, g;
    Shape();
    static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); }
};

// pdb: BSTextureData::CreateObject | BSTextureData.obj | fnv360_0721_beta, caller_sim, low
Shape* __cdecl FUN_00aba270()
{
    return new Shape;
}
}   // namespace f3m_00aba270

// @f3 0x00aab2b0 (community match, verified in this file)
namespace f3m_00aab2b0 {
namespace f3m_00aab2b0 {
struct Base {
    void FUN_0082dcf0(int a, int b);
};
struct Object : Base {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned char flags;
    void FUN_00aab2b0(int a, int b);
};
}

// pdb: BSDamageStage::UpdateSelectedDownwardPass | BSDamageStage1.obj | fnv360_0822_retail, vtable, medium
// pdb params: UpdateData, uFlags
void f3m_00aab2b0::Object::FUN_00aab2b0(int a, int b)
{
    if (!(flags & 1))
        FUN_0082dcf0(a, b);
}
}   // namespace f3m_00aab2b0

// @f3 0x00aa5320 (community match, verified in this file)
class AA5320Target
{
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C(int value);
};

struct AA5320Array
{
    int unk00;
    AA5320Target** unk04;
    unsigned int unk08;
};

class AA5320Owner
{
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    AA5320Array* unk20;

    void __thiscall FUN_00aa5320(int value);
};

class AA2BA0
{
public:
    void __thiscall FUN_00aa2ba0(AA5320Owner* owner, int value);
};

extern AA2BA0* DAT_0116d138;

// pdb: QueuedFile::Requeue | QueuedFiles.obj | fnv360_0822_retail, vtable, medium
// pdb params: aeNewPriority
void __thiscall AA5320Owner::FUN_00aa5320(int value)
{
    AA5320Owner* self = this;
    AA5320Array* array = self->unk20;
    if (array)
    {
        unsigned int count = array->unk08;
        unsigned int index = 0;
        while (index < count)
        {
            AA5320Target* target = self->unk20->unk04[index];
            if (target)
                target->slot1C(value);
            ++index;
        }
    }

    DAT_0116d138->FUN_00aa2ba0(self, value);
}

// @f3 0x00aa2ce0 (community match, verified in this file)
namespace f3m_00aa2ce0 {
struct CounterAA2CE0 {
    unsigned unk00, unk04, unk08;
    volatile long counter;
    void FUN_00aa2ce0();
};

// pdb: LockFreePriorityQueue<NiPointer<IOTask> >::IncrementCount | IOManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
void CounterAA2CE0::FUN_00aa2ce0() {
    InterlockedIncrement(&counter);
}
}   // namespace f3m_00aa2ce0

// @f3 0x00aa2cf0 (community match, verified in this file)
namespace f3m_00aa2cf0 {
struct CountedState {
    unsigned int unk00, unk04, unk08;
    volatile long count;
    void FUN_00aa2cf0();
};

// pdb: LockFreePriorityQueue<NiPointer<IOTask> >::DecrementCount | IOManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
void CountedState::FUN_00aa2cf0() {
    InterlockedDecrement(&count);
}
}   // namespace f3m_00aa2cf0

// @f3 0x00aa2eb0 (community match, verified in this file)
namespace f3m_00aa2eb0 {
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::CopyKey | IOManager.obj | fnv360_0721_beta, vtable, medium
// pdb params: aKey
__int64 __stdcall FUN_00aa2eb0(__int64 value) {
    return value;
}
}   // namespace f3m_00aa2eb0

// @f3 0x00aa2f40 (community match, verified in this file)
namespace f3m_00aa2f40 {
struct CountedStateAA2F40 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    volatile long count;
    void FUN_00aa2f40();
};

// pdb: LockFreeMap<MobileObject *,NiPointer<LipTask> >::IncrementCount | LipSyncBackgroundManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
void CountedStateAA2F40::FUN_00aa2f40() {
    InterlockedIncrement(&count);
}
}   // namespace f3m_00aa2f40

// @f3 0x00aa73d0 (community match, verified in this file)
namespace f3m_00aa73d0 {
struct ObjectAA73D0 {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    unsigned unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c;
    unsigned unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c;
    unsigned unk90, unk94, unk98, unk9c;
    unsigned unka0, unka4, unka8, unkac;
    unsigned unkb0, unkb4, unkb8, unkbc;
    unsigned unkc0, unkc4, unkc8, unkcc;
    unsigned unkd0, unkd4, unkd8, unkdc;
    unsigned unke0, unke4, unke8, unkec;
    unsigned unkf0, unkf4, unkf8, unkfc;
    unsigned unk100, unk104;
    ObjectAA73D0* owner;
    bool FUN_00aa73d0(void*);
};

// pdb: INISettingCollection::Open | XINISetting.obj | fnv360_0822_retail, vtable, medium
// pdb params: abWrite
bool ObjectAA73D0::FUN_00aa73d0(void*) {
    owner = this;
    return true;
}
}   // namespace f3m_00aa73d0

// @f3 0x00ab3db0 (community match, verified in this file)
namespace f3m_00ab3db0 {
struct EntryTable {
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
    unsigned int* entries;
    unsigned int FUN_00ab3db0(unsigned int index) const;
};

// pdb: BSPortalGraph::GetAlwaysRenderAt | BSPortalGraph.obj | fnv360_0822_retail, call_gap, medium
// pdb params: i
unsigned int EntryTable::FUN_00ab3db0(unsigned int index) const {
    return entries[index];
}
}   // namespace f3m_00ab3db0

// @f3 0x00aa2ea0 (community match, verified in this file)
namespace f3m_00aa2ea0 {
struct TableAA2EA0 {
    unsigned unk00, unk04;
    unsigned bucketCount;
    unsigned FUN_00aa2ea0(unsigned __int64 key);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::GetBucketForKey | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aKey
unsigned TableAA2EA0::FUN_00aa2ea0(unsigned __int64 key) {
    return static_cast<unsigned>(key) % bucketCount;
}
}   // namespace f3m_00aa2ea0

// @f3 0x00aa9de0 (community match, verified in this file)
namespace f3m_00aa9de0 {
struct Callback {
    unsigned int unk00;
    void (__cdecl *invoke)(void*);
    void* context;
};

struct CallbackOwner {
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
    Callback* callback;
    void FUN_00aa9de0();
};

// pdb: BSParallelTaskThread::RunLinearTasks | BSParallelTaskManager.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSMultiBoundNode::IsMultiBoundNode)
void CallbackOwner::FUN_00aa9de0() {
    callback->invoke(callback->context);
}
}   // namespace f3m_00aa9de0

// @f3 0x00aab2a0 (community match, verified in this file)
namespace f3m_00aab2a0 {
struct FNV_UpdateFlags;
struct FUN_00a94040_shell {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    unsigned flags;
    void FUN_00a5dd70(FNV_UpdateFlags* update, unsigned options);
};

struct NodeAAB2A0 : FUN_00a94040_shell {
    void FUN_00aab2a0(FNV_UpdateFlags* update, unsigned options);
};

// pdb: BSDamageStage::UpdateDownwardPass | BSDamageStage1.obj | fnv360_0822_retail, vtable, medium
// pdb params: UpdateData, uFlags
void NodeAAB2A0::FUN_00aab2a0(FNV_UpdateFlags* update, unsigned options) {
    if ((flags & 1) == 0)
        FUN_00a5dd70(update, options);
}
}   // namespace f3m_00aab2a0

// @f3 0x00aaa6c0 (community match, verified in this file)
namespace f3m_00aaa6c0 {
struct DispatchTarget {
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
    virtual void Dispatch(void* value);
};

struct DispatchOwner {
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
    DispatchTarget* target;
    void FUN_00aaa6c0(void* value);
};

// pdb: BSMultiBoundNode::QPointWithin | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: aPoint
void DispatchOwner::FUN_00aaa6c0(void* value) {
    target->Dispatch(value);
}
}   // namespace f3m_00aaa6c0

// @f3 0x00aad3f0 (community match, verified in this file)
namespace f3m_00aad3f0 {
struct TargetAAD3F0 {
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
    virtual bool dispatch(void* object);
};
struct OwnerAAD3F0 {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    unsigned unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c;
    unsigned unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c;
    unsigned unk90, unk94, unk98, unk9c;
    unsigned unka0, unka4, unka8, unkac;
    unsigned unkb0, unkb4, unkb8, unkbc;
    unsigned unkc0;
    TargetAAD3F0* target;
    bool FUN_00aad3f0(void* object);
};
// pdb: BSCullingProcess::AddShared | BSCullingProcess.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apObject
bool OwnerAAD3F0::FUN_00aad3f0(void* object) {
    return target->dispatch(object);
}
}   // namespace f3m_00aad3f0

// @f3 0x00aad400 (community match, verified in this file)
namespace f3m_00aad400 {
struct DispatchTargetAAD400 {
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
    virtual void Dispatch();
};

struct DispatchOwnerAAD400 {
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
    DispatchTargetAAD400* target;
    void FUN_00aad400();
};

// pdb: BSCullingProcess::ClearSharedMap | BSCullingProcess.obj | fnv360_0822_retail, call_seq, medium
void DispatchOwnerAAD400::FUN_00aad400() {
    target->Dispatch();
}
}   // namespace f3m_00aad400

// @f3 0x00aaa290 (community match, verified in this file)
namespace f3m_00aaa290 {
struct Aaa290Owner
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

    unsigned char FUN_00aaa290(int argument);
};

void __stdcall FUN_0082e460(void* object);

// pdb: BSMultiBoundNode::IsEqual | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSFadeNode::IsEqual)
// pdb params: apObject
unsigned char Aaa290Owner::FUN_00aaa290(int argument)
{
    FUN_0082e460((void*)argument);
    return unkAC == ((Aaa290Owner*)argument)->unkAC;
}
}   // namespace f3m_00aaa290

// @f3 0x00aab140 (community match, verified in this file)
extern const char* DAT_0116d768;
namespace f3m_00aab140 {


char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00aa9c80(f3m_00aa6170::ViewerStrings* strings);

// pdb: BSDebrisNode::GetViewerStrings | BSDebrisNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void __stdcall FUN_00aab140(f3m_00aa6170::ViewerStrings* strings)
{
    FUN_00aa9c80(strings);

    char* label = FUN_00847b50(DAT_0116d768);
    unsigned int index = strings->firstFree;
    unsigned int capacity = strings->capacity;

    if (index >= capacity)
        strings->FUN_00555790(index + strings->growBy);

    strings->FUN_005b3880(index, label);
}
}   // namespace f3m_00aab140

// @f3 0x00aaa6f0 (community match, verified in this file)
namespace f3m_00aaa6f0 {
struct TargetAAA6F0 {
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
    virtual unsigned dispatch(void*);
};
struct LinkAAA6F0 {
    unsigned unk00, unk04, unk08;
    TargetAAA6F0* target;
};
struct OwnerAAA6F0 {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    unsigned unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c;
    unsigned unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c;
    unsigned unk90, unk94, unk98, unk9c;
    unsigned unka0, unka4, unka8;
    LinkAAA6F0* link;
    unsigned FUN_00aaa6f0(void* argument);
};
// pdb: BSMultiBoundNode::CheckBound | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: aTargetBound
unsigned OwnerAAA6F0::FUN_00aaa6f0(void* argument) {
    return link->target->dispatch(argument);
}
}   // namespace f3m_00aaa6f0

// @f3 0x00aa2ec0 (community match, verified in this file)
namespace f3m_00aa2ec0 {
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::CopyKeyDirect | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aKey, arCopiedKey
void __stdcall FUN_00aa2ec0(__int64 value, __int64* destination) {
    *destination = value;
}
}   // namespace f3m_00aa2ec0

// @f3 0x00ab5d60 (community match, verified in this file)
extern char DAT_00e8b28c;
namespace f3m_00ab5d60 {
struct State00ab5d60 {
    void* table;
    void FUN_0082ea60(int value);
    State00ab5d60* FUN_00ab5d60();
};
State00ab5d60* State00ab5d60::FUN_00ab5d60() {
    FUN_0082ea60(0);
    table = &DAT_00e8b28c;
    return this;
}
}   // namespace f3m_00ab5d60

// @f3 0x00aa2380 (community match, verified in this file)
namespace f3m_00aa2380 {
struct FUN_00a5db30_shell {
    void FUN_00a5db30();
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
    virtual void finish();
};
struct NodeAA2380 : FUN_00a5db30_shell {
    void FUN_00aa2380();
};
// pdb: BSMultiBoundNode::UpdateUpwardPass | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSMultiBoundRoom::GetRTTI)
void NodeAA2380::FUN_00aa2380() {
    FUN_00a5db30();
    finish();
}
}   // namespace f3m_00aa2380

// @f3 0x00aa8170 (community match, verified in this file)
namespace Alloc00aa8170 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
};
extern Heap DAT_01090a78;
}
// pdb: BSSimpleArray<NiFrustumPlanes,1024>::_Allocate | BSCompoundFrustum.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiSizeInItem
void* __stdcall FUN_00aa8170(unsigned int count) {
    return Alloc00aa8170::DAT_01090a78.FUN_0086b930(count * 100u);
}

// @f3 0x00ab6db0 (community match, verified in this file)
namespace f3m_00ab6db0 {
struct Target00ab6db0 {
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
    virtual void Dispatch();
};
struct Argument00ab6db0 {
    unsigned int unk00, unk04, unk08;
    Target00ab6db0* target;
};
// pdb: BSMultiBoundCapsule::CheckBound | BSMultiBoundCapsule.obj | fnv360_0822_retail, vtable, medium
// pdb params: aTargetBound
int __stdcall FUN_00ab6db0(Argument00ab6db0* argument) {
    argument->target->Dispatch();
    return 0;
}
}   // namespace f3m_00ab6db0

// @f3 0x00ab4100 (community match, verified in this file)
namespace f3m_00ab4100 {
struct Member00ab4100 {
    void FUN_0066bcc0(void** value);
};
struct Owner00ab4100 {
    unsigned int unk00, unk04;
    Member00ab4100 member;
    void FUN_00ab4100(void* value);
};
// pdb: BSPortalGraph::RemoveOccluder | BSPortalGraph.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apOccluder
void Owner00ab4100::FUN_00ab4100(void* value) {
    if (value)
        member.FUN_0066bcc0(&value);
}
}   // namespace f3m_00ab4100

// @f3 0x00aa2840 (community match, verified in this file)
namespace f3m_00aa2840 {
struct OwnerAA2840 {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    unsigned unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54;
    void (__cdecl *callback)();
    bool FUN_00aa2650();
    void FUN_00aa2840();
};
// pdb: IOManager::Resume | IOManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void OwnerAA2840::FUN_00aa2840() {
    if (FUN_00aa2650() && callback)
        callback();
}
}   // namespace f3m_00aa2840

// @f3 0x00aa5000 (community match, verified in this file)
namespace Task2403 {
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
struct Entry { unsigned unk00,unk04; void* data; };
struct FUN_00aa4cc0 {
    void* vptr;
    unsigned unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
    Entry** entries;
    unsigned unk30,unk34;
    FUN_00aa4cc0(int,int,int);
    ~FUN_00aa4cc0();
    void* GetDataAt(unsigned i) { return entries[i]->data; }
};
struct FUN_00aa2be0 {
    unsigned unk00,unk04,unk08,unk0c;
    FUN_00aa2be0(int,int,int);
    static void* operator new(unsigned n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void*);
};
extern char DAT_00e896ec;
struct FUN_00aa5000 : FUN_00aa4cc0 {
    void* firstData;
    FUN_00aa2be0* helper;
    unsigned unk40,unk44,unk48,unk4c,unk50,unk54,unk58;
    FUN_00aa5000();
};
// pdb: IOManager::IOManager | IOManager.obj | fnv360_0822_retail, call_gap, low
FUN_00aa5000::FUN_00aa5000() : FUN_00aa4cc0(10,1,24) {
    vptr = &DAT_00e896ec;
    unk48=0; unk50=0; unk44=0; unk54=0; unk58=0; unk40=6;
    helper = new FUN_00aa2be0(6,7,8);
    firstData = GetDataAt(0);
}
}

// @f3 0x00aa1d60 (community match, verified in this file)
extern const char* DAT_0116d124;
extern const char DAT_00e89480[];
extern const char DAT_00e89470[];
namespace f3m_00aa1d60 {
struct ViewerStrings {
    void* vtable; char** data;
    unsigned short capacity, count, used, grow;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char* const&);
};
struct Point { float x,y,z; char* FUN_00823dc0(const char*); };
char* __cdecl FUN_00847b50(const char*);
struct Bounds {
    void* vtable; unsigned int unk04, unk08;
    Point center, halfExtents;
    void FUN_008beac0(ViewerStrings*);
    void FUN_00aa1d60(ViewerStrings*);
};
// pdb: BSMultiBoundAABB::GetViewerStrings | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: apStrings
void Bounds::FUN_00aa1d60(ViewerStrings* strings) {
    FUN_008beac0(strings);
    char* name=FUN_00847b50(DAT_0116d124);
    unsigned int index=strings->count;
    if(index>=strings->capacity) strings->FUN_00555790(index+strings->grow);
    strings->FUN_005b3880(index,name);
    name=center.FUN_00823dc0(DAT_00e89480);
    index=strings->count;
    if(index>=strings->capacity) strings->FUN_00555790(index+strings->grow);
    strings->FUN_005b3880(index,name);
    name=halfExtents.FUN_00823dc0(DAT_00e89470);
    index=strings->count;
    if(index>=strings->capacity) strings->FUN_00555790(index+strings->grow);
    strings->FUN_005b3880(index,name);
}
}   // namespace f3m_00aa1d60

// @f3 0x00aaf610 (community match, verified in this file)
namespace f3m_00aaf610 {
namespace Task2409 {
struct Q52Ent {
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
    unsigned m_flags;
    void SetFlag(unsigned m,bool b) { if(b) m_flags|=m; else m_flags&=~m; }
};
struct Q52Arr {
    Q52Ent** m_data; unsigned unk04, m_uiItemCount;
    unsigned Count() {return m_uiItemCount;}
};
struct Q52Obj {
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
    unsigned m_cur,m_num,unk3c;
    Q52Arr** m_arrs;
    unsigned short unk44,m_arrCount;
    bool FUN_00aaf610(unsigned idx);
};
// @fnv 0x00aaf610
// pdb: NiBSBoneLODController::SetBoneLOD | NiBSBoneLODController.obj | fnv360_0822_retail, objrun, low
// pdb params: iLOD
bool Q52Obj::FUN_00aaf610(unsigned idx)
{
    if (m_num > 0 && m_cur != idx)
    {
        if ((int)idx == -1 || ((int)idx > -1 && idx < m_num))
        {
            unsigned i;
            bool sel = false;
            unsigned j;
            for (i = 0; i < m_arrCount; i++)
            {
                Q52Arr* arr = m_arrs[i];
                if (arr)
                {
                    if (i == idx)
                        sel = true;
                    for (j = 0; j < arr->Count(); j++)
                    {
                        if (arr->m_data[j])
                        {
                            arr->m_data[j]->SetFlag(2, sel);
                        }
                    }
                }
            }
            m_cur = idx;
            return true;
        }
    }
    return false;
}

}
}   // namespace f3m_00aaf610

// @f3 0x00ab4310 (community match, verified in this file)
namespace f3m_00ab4310 {
namespace worker2404
{
struct RefObject
{
    virtual void Slot00();
    virtual void DeleteThis();
    long references;

    void AddReference() { InterlockedIncrement(&references); }
    void RemoveReference()
    {
        if (InterlockedDecrement(&references) == 0)
            DeleteThis();
    }
};

struct Pointer
{
    RefObject* object;
    Pointer(RefObject* value = 0) : object(value)
    {
        if (object)
            object->AddReference();
    }
    ~Pointer()
    {
        if (object)
            object->RemoveReference();
    }
    Pointer& operator=(const Pointer& other)
    {
        if (object != other.object)
        {
            if (object)
                object->RemoveReference();
            object = other.object;
            if (object)
                object->AddReference();
        }
        return *this;
    }
};

struct Array
{
    void* vtable;
    Pointer* data;
    int FUN_005e5350();

    __declspec(noinline) int FUN_006b5880(const Pointer& value)
    {
        int index = FUN_005e5350();
        Pointer* destination = data + index;
        new (destination) Pointer();
        data[index] = value;
        return index;
    }
};

struct Owner
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
    Array objects;
    void FUN_00ab4310(RefObject* object);
};

// pdb: BSPortalGraph::AddUnboundNode | BSPortalGraph.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apNode
void Owner::FUN_00ab4310(RefObject* object)
{
    if (object)
    {
        Pointer value(object);
        objects.FUN_006b5880(value);
    }
}
}
}   // namespace f3m_00ab4310

// @f3 0x00ab8480 (community match, verified in this file)
extern int DAT_00e8b888;
namespace f3m_00ab8480 {
class FUN_00c31af0 {
public:
    virtual void vf00();
    FUN_00c31af0();
    ~FUN_00c31af0();
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
void* FUN_0096afc0(unsigned int);
struct Array2423 {
    void* table;
    void** data;
    unsigned short capacity, size, live, grow;
    void Init(unsigned int a, unsigned int b) {
        capacity = (unsigned short)a;
        grow = (unsigned short)b;
        size = 0;
        live = 0;
        unsigned int count = capacity;
        if (count > 0) data = (void**)FUN_0096afc0(count);
        else data = 0;
    }
    Array2423() {
        Init(0,1);
        table = &DAT_00e8b888;
    }
};
class FUN_00ab8480 : public FUN_00c31af0 {
public:
    int type;
    Array2423 values;
    virtual void vf00();
    FUN_00ab8480();
};
// pdb: NiTPrimitiveArray<NiPointer<NiAVObject> >::NiTPrimitiveArray<NiPointer<NiAVObject> > | BSPSysArrayEmitter.obj | fnv360_0822_retail, uvref, high
// pdb params: uiMaxSize, uiGrowBy
FUN_00ab8480::FUN_00ab8480() : type(2) {}
}   // namespace f3m_00ab8480

// @f3 0x00aafff0 (community match, verified in this file)
namespace f3m_00aafff0 {
namespace Task2421 {
void __cdecl FUN_0089e890(void*);
struct Base {
    virtual void vf();
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
    ~Base();
};
struct GroupArray {
    virtual void vf();
    void* data;
    unsigned short capacity,count,grow;
    ~GroupArray() { void* p = data; FUN_0089e890(p); }
};
struct FUN_00aafff0 : Base {
    int unk34,unk38;
    GroupArray groups;
    void FUN_00aafeb0();
    ~FUN_00aafff0();
};
// pdb: NiBSBoneLODController::~NiBSBoneLODController | NiBSBoneLODController.obj | fnv360_0822_debug, call_seq, high
FUN_00aafff0::~FUN_00aafff0() { FUN_00aafeb0(); }
}
}   // namespace f3m_00aafff0

// @f3 0x00ab50a0 (community match, verified in this file)
extern void* DAT_00e8b034[];
namespace f3m_00ab50a0 {
namespace task2413 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*,unsigned int);
struct FUN_00abc050 {
    void** vtable;
    unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44;
    float unk48;
    unsigned char unk4c,unk4d,unk4e,unk4f;
    unsigned int unk50,unk54,unk58;
    FUN_00abc050();
};
struct Object: FUN_00abc050 {
    void* data;
    unsigned short count,unk62;
    Object() {vtable=DAT_00e8b034;data=0;count=0;}
    static void* operator new(unsigned int size) {return FUN_0089eb90(size);}
    static void operator delete(void* pointer,unsigned int size) {FUN_0089ec10(pointer,size);}
};
// pdb: BSPSysMultiTargetEmitterCtlr::CreateObject | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, caller_sim, low
Object* __cdecl FUN_00ab50a0() {return new Object;}
}
}   // namespace f3m_00ab50a0

// @f3 0x00ab07b0 (community match, verified in this file)
namespace f3m_00ab07b0 {
namespace task2426 {
struct Fixed {const char* data;};extern Fixed* DAT_0116da60;
struct A7F920ExtraData {A7F920ExtraData();virtual ~A7F920ExtraData();unsigned unk04,unk08;void FUN_008245d0(const Fixed&);};
struct ArrayBase {
 ArrayBase(unsigned short maximum,unsigned short growth){maxSize=maximum;growBy=growth;size=0;effectiveSize=0;data=0;}
 virtual ~ArrayBase();
 void* data;unsigned short maxSize,size,effectiveSize,growBy;
};
struct Array:ArrayBase {Array():ArrayBase(0,1){}virtual ~Array();};
struct Extra: A7F920ExtraData {Array entries;Extra();virtual ~Extra();};
// pdb: NiTObjectArray<FurnitureMark>::NiTObjectArray<FurnitureMark> | BSFurnitureMarker.obj | fnv360_0822_retail, uvref, medium
// pdb params: uiMaxSize, uiGrowBy
Extra::Extra(){FUN_008245d0(*DAT_0116da60);}
}
}   // namespace f3m_00ab07b0

// @f3 0x00ab00a0 (community match, verified in this file)
extern float DAT_01066a50;
namespace f3m_00ab00a0 {
namespace task2432 {
struct Owner {unsigned unk00,unk04,unk08;unsigned short value;void FUN_00ab00a0(float);};
// pdb: FurnitureMark::SetHeading | BSFurnitureMarker.obj | fnv360_0822_debug, caller, medium
// pdb params: afHeading
void Owner::FUN_00ab00a0(float angle){
 while(angle<0.0f)angle+=DAT_01066a50;
 while(angle>=DAT_01066a50)angle-=DAT_01066a50;
 value=(unsigned short)(angle*1000.0);
}
}
}   // namespace f3m_00ab00a0

// @f3 0x00ab7a30 (community match, verified in this file)
namespace f3m_00ab7a30 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00ab7930 {
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
 unsigned short unkB8, flagsBA;
 unsigned int unkBC;
 unsigned int unkC0;
 unsigned int unkC4;
 unsigned int unkC8;
 unsigned int unkCC;
 unsigned int unkD0;
 unsigned int unkD4;
 unsigned int unkD8;
 unsigned int unkDC;
 static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
 FUN_00ab7930();
 void FUN_0082daa0(FUN_00ab7930*,void*);
 FUN_00ab7930* FUN_00ab7a30(void*);
};
// pdb: BSMasterParticleSystem::CreateClone | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCloning
FUN_00ab7930* FUN_00ab7930::FUN_00ab7a30(void* process) {
 FUN_00ab7930* object=0;
 object=new FUN_00ab7930();
 FUN_0082daa0(object,process);
 object->flagsBA=flagsBA;
 return object;
}
}   // namespace f3m_00ab7a30

// @f3 0x00ab5000 (community match, verified in this file)
namespace f3m_00ab5000 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00c1c390 {
 virtual void vf00();
 FUN_00c1c390();
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
};
struct Clone2441 : FUN_00c1c390 {
 int unk5c;
 unsigned short flags60;
 virtual void vf00();
 static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
 Clone2441() { unk5c=0; flags60=0; }
 void FUN_00abbb40(Clone2441*,void*);
 Clone2441* FUN_00ab5000(void*);
};
// pdb: BSPSysMultiTargetEmitterCtlr::CreateClone | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCloning
Clone2441* Clone2441::FUN_00ab5000(void* process) {
 Clone2441* object=new Clone2441();
 FUN_00abbb40(object,process);
 object->flags60=flags60;
 return object;
}
}   // namespace f3m_00ab5000

// @f3 0x00aaaa60 (community match, verified in this file)
namespace f3m_00aaaa60 {
namespace Task2445 {
void* __cdecl FUN_0089eb90(unsigned);
struct CloneContext;
struct FUN_00ac5e10 {
    virtual ~FUN_00ac5e10();
    unsigned unk04,unk08,kind,unk10,unk14;
    FUN_00ac5e10();
    void FUN_00ac5e70(FUN_00ac5e10*,CloneContext&);
};
struct Modifier : FUN_00ac5e10 {
    float strength;
    Modifier() : strength(1.0f) {kind=4000;}
    static void* operator new(unsigned n) {return FUN_0089eb90(n);}
    Modifier* FUN_00aaaa60(CloneContext&);
};
// pdb: BSWindModifier::CreateClone | BSWindModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
Modifier* Modifier::FUN_00aaaa60(CloneContext& context) {
    Modifier* result = new Modifier();
    FUN_00ac5e70(result,context);
    result->strength = strength;
    return result;
}
}
}   // namespace f3m_00aaaa60

// @f3 0x00aa14b0 (community match, verified in this file)
namespace f3m_00aa14b0 {
extern "C" double __cdecl fabs(double);

class Pt
{
  public:
    float x, y, z;
    Pt()
    {}
    Pt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Pt operator-(const Pt& pt) const
    {
        return Pt(x - pt.x, y - pt.y, z - pt.z);
    }
};

inline float PtFabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float PtFabs(float _X)
{
    return (PtFabsf(_X));
}
inline float PtAbs(float _X)
{
    return (PtFabs(_X));
}

class CenteredPointBounds
{
  public:
    int unk00;
    int unk04;
    int unk08;
    Pt m_kCenter;
    Pt m_kExtent;
    int FUN_00aa14b0(const Pt& kPoint);
};

// @fnv 0x00c38a20
// pdb: BSMultiBoundAABB::QPointWithin | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: kpoint
int CenteredPointBounds::FUN_00aa14b0(const Pt& kPoint)
{
    Pt kDiff = kPoint - m_kCenter;
    return !(PtAbs(kDiff.x) - m_kExtent.x > 0.01f) && !(PtAbs(kDiff.y) - m_kExtent.y > 0.01f) &&
           (PtAbs(kDiff.z) - m_kExtent.z <= 0.01f);
}

}   // namespace f3m_00aa14b0

// @f3 0x00aa5790 (community match, verified in this file)
namespace f3m_00aa5790 {
struct MemoryManager2424 { void FUN_0086ba60(void*); };

struct FUN_00aa51a0 {
 virtual ~FUN_00aa51a0();
 int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
};
struct DAT_00e89844 : FUN_00aa51a0 {
 void* data28;
 __forceinline ~DAT_00e89844() { ((MemoryManager2424*)&DAT_01090a78)->FUN_0086ba60(data28); }
 DAT_00e89844* FUN_00aa5790(unsigned flags);
};
// pdb: QueuedFileEntry::`scalar deleting destructor' | QueuedFiles.obj | fnv360_0822_retail, vtable, medium
DAT_00e89844* DAT_00e89844::FUN_00aa5790(unsigned flags) {
 this->DAT_00e89844::~DAT_00e89844();
 if(flags & 1) ((MemoryManager2424*)&DAT_01090a78)->FUN_0086ba60(this);
 return this;
}
}   // namespace f3m_00aa5790

// @f3 0x00aae340 (community match, verified in this file)
namespace f3m_00aae340 {
namespace Task2456 {
struct ChildObject_j61
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
    virtual void Process(void*, int);
};
__forceinline ChildObject_j61*& ChildAt(ChildObject_j61** children, unsigned int index)
{
    ChildObject_j61** entry = &children[index];
    return *entry;
}
struct ProcessOwner_j61
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
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void Finish();
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
    ChildObject_j61** children;
    unsigned short capacity, count;
    int unka8, unkac, unkb0;
    void* event;
    void FUN_00aae340(void* context);
};
// pdb: BSParticleSystemManager::UpdateParallel | BSParticleSystemManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: updateData
void ProcessOwner_j61::FUN_00aae340(void* context)
{
    unsigned int total = count;
    for (unsigned int index = 0; index < total; ++index)
    {
        ChildObject_j61* child = ChildAt(children, index);
        if (child) child->Process(context, 0);
    }
    Finish();
}
}
}   // namespace f3m_00aae340

// @f3 0x00ab0270 (community match, verified in this file)
namespace f3m_00ab0270 {
namespace worker2442 {
struct ElemZ
{
    int a, b, c;
    unsigned short m_usD;
    unsigned char m_ucE;
    ElemZ()
    {
        m_usD = 0;
        m_ucE = 0;
    }
    bool FUN_00ab0140(const ElemZ& kOther) const;
    bool FUN_00ab0190(const ElemZ& kOther) const;
    bool operator!=(const ElemZ& kOther) const
    {
        return FUN_00ab0190(kOther);
    }
};
struct FUN_00c54a30
{
    void* m_pv0;
    ElemZ* m_pUserData;
    unsigned short m_us8;
    unsigned short m_usSize;
    unsigned short m_usUsed;
    void FUN_00ab0270(unsigned int uiIndex, const ElemZ& kElem);
};
// @fnv 0x00c54a30
// pdb: NiTArray<FurnitureMark,NiTNewInterface<FurnitureMark> >::SetAt | BSFurnitureMarker.obj | fnv360_0822_retail, call_seq, medium
// pdb params: uiIndex, element
void FUN_00c54a30::FUN_00ab0270(unsigned int uiIndex, const ElemZ& kElem)
{
    static ElemZ s_kEmpty;
    if (uiIndex >= m_usSize)
    {
        m_usSize = uiIndex + 1;
        if (kElem != s_kEmpty)
            m_usUsed++;
    }
    else if (kElem != s_kEmpty)
    {
        if (m_pUserData[uiIndex].FUN_00ab0140(s_kEmpty))
            m_usUsed++;
    }
    else
    {
        ElemZ* pkCur = &m_pUserData[uiIndex];
        if (*pkCur != s_kEmpty)
            m_usUsed--;
    }
    m_pUserData[uiIndex] = kElem;
}


}
}   // namespace f3m_00ab0270

// @f3 0x00aae1f0 (community match, verified in this file)
namespace f3m_00aae1f0 {
namespace f3m_00aae1f0 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ebe0(void*);
struct FUN_00aae130 {
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
    FUN_00aae130(int src);
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ebe0(p); }
};
struct Source {
    void* table;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0;
    FUN_00aae130* FUN_00aae1f0(int unused);
};
// pdb: BSPortalSharedNode::CreateClone | BSPortal.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
FUN_00aae130* Source::FUN_00aae1f0(int unused)
{
    return new FUN_00aae130(unkc0);
}
}
}   // namespace f3m_00aae1f0

// @f3 0x00aa2820 (community match, verified in this file)
namespace f3m_00aa2820 {
namespace f3m_00aa2820 {
typedef void (__cdecl* Callback)();
struct Obj {
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
    Callback callback;
    bool FUN_00aa25b0();
    void FUN_00aa2820();
};
// pdb: GetCurrentThreadId | getcurrentthreadid.obj | fnv360_0721_retail, call_seq, medium
void Obj::FUN_00aa2820()
{
    if (FUN_00aa25b0() && callback)
        callback();
}
}
}   // namespace f3m_00aa2820

// @f3 0x00aa2410 (community match, verified in this file)
namespace f3m_00aa2410 {
struct S00b66050_list
{
    void Remove(unsigned int* item);
};

struct Owner2410
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    S00b66050_list list;
    void FUN_00aa2410(unsigned int key);
};

// pdb: BSMultiBoundRoom::RemoveOccluder | BSMultiBoundRoom.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apOccluder
void Owner2410::FUN_00aa2410(unsigned int key)
{
    if (key)
        list.Remove(&key);
}
}   // namespace f3m_00aa2410

// @f3 0x00aada50 (community match, verified in this file)
namespace f3m_00aada50 {
namespace f3m_00aada50 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ebe0(void*);
struct Process;
struct FUN_00aad5f0 {
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
    virtual void SetValue(const void* v);
    int unk04;
    int unk08;
    FUN_00aad5f0();
    void BSMultiBoundShape_CopyMembers(FUN_00aad5f0* dst, Process& proc);
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ebe0(p); }
};
struct Clone : FUN_00aad5f0 {
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    Clone() {}
    Clone* FUN_00aada50(Process& proc);
};
// pdb: BSMultiBoundSphere::CreateClone | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: arCloneData
Clone* Clone::FUN_00aada50(Process& proc)
{
    Clone* c = new Clone;
    BSMultiBoundShape_CopyMembers(c, proc);
    c->SetValue(&unk0c);
    c->unk18 = unk18;
    return c;
}
}
}   // namespace f3m_00aada50

// @f3 0x00ab7280 (community match, verified in this file)
namespace f3m_00ab7280 {
namespace f3m_00ab7280 {
struct Ostr;
typedef int (__cdecl* WriteFn)(Ostr* s, const void* data, unsigned int size, int* comp, int count);
struct Ostr { int unk00; int pos; int unk08; WriteFn write; };
struct Object;
struct Stream {
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
    virtual void SaveLink(Object* obj);
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
    Ostr* ostr;
};
template <class T> inline void SaveValue(Ostr* o, const T* v)
{
    int comp = sizeof(T);
    o->pos += o->write(o, v, sizeof(T), &comp, 1);
}
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
    short unk0b8;
    short unk0ba;
    int unk0bc, unk0c0, unk0c4, unk0c8, unk0cc;
    Object** links;
    short unk0d4;
    unsigned short linkCount;
    void FUN_0082e820(Stream& s);
    void FUN_00ab7280(Stream& s);
};
// pdb: BSMasterParticleSystem::SaveBinary | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Object::FUN_00ab7280(Stream& s)
{
    FUN_0082e820(s);
    SaveValue(s.ostr, &unk0ba);
    unsigned int n = linkCount;
    SaveValue(s.ostr, &n);
    for (unsigned int i = 0; i < n; i++)
        s.SaveLink(links[i]);
}
}
}   // namespace f3m_00ab7280

// @f3 0x00ab9bf0 (community match, verified in this file)
namespace f3m_00ab9bf0 {
namespace f3m_00ab9bf0 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ebe0(void*);
struct FUN_00825800 {
    virtual void v00();
    int refs;
    FUN_00825800();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ebe0(p); }
};
struct Created : FUN_00825800 {
    int unk08;
    Created() : unk08(0) {}
    virtual void v00();
};
// pdb: BSReference::CreateObject | BSReference.obj | fnv360_0822_retail, objrun, medium
FUN_00825800* __cdecl FUN_00ab9bf0()
{
    return new Created;
}
}
}   // namespace f3m_00ab9bf0

// @f3 0x00aad660 (community match, verified in this file)
namespace f3m_00aad660 {
namespace f3m_00aad660 {
struct Process;
struct Base {
    void* vtable;
    int refs;
    void FUN_008258b0(Base* dst, Process& proc);
};
struct Obj : Base {
    int unk08;
    void BSMultiBoundShape_CopyMembers(Obj* dst, Process& proc);
};
// pdb: BSMultiBoundShape::CopyMembers | BSMultiBoundShape.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(caller_sim), high
void Obj::BSMultiBoundShape_CopyMembers(Obj* dst, Process& proc)
{
    FUN_008258b0(dst, proc);
    dst->unk08 = unk08;
}
}
}   // namespace f3m_00aad660

// @f3 0x00ab7230 (community match, verified in this file)
namespace f3m_00ab7230 {
namespace Task2480 {
struct BinaryStream {
    unsigned unk00,position;
    unsigned (__cdecl* read)(void*,void*,unsigned,unsigned*,unsigned);
    void ReadShort(unsigned short& value) { unsigned size=2; position+=read(this,&value,2,&size,1); }
};
struct Stream {
    unsigned unk00,version;
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
    BinaryStream* underlying;
    void FUN_0082b620();
};
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
    unsigned short unkB8,value;
    void FUN_0082db60(Stream&);
    void FUN_00ab7230(Stream&);
};
// pdb: BSMasterParticleSystem::LoadBinary | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Owner::FUN_00ab7230(Stream& stream) {
    FUN_0082db60(stream);
    stream.underlying->ReadShort(value);
    if(stream.version>15) stream.FUN_0082b620();
}
}
}   // namespace f3m_00ab7230

// @f3 0x00aba1f0 (community match, verified in this file)
namespace task2484 {
struct FixedString { const char* data; };
extern FixedString* DAT_0116ebb0;
extern void* const DAT_00e8bacc[];
struct FUN_00845b60 {
    virtual ~FUN_00845b60();
    unsigned references;
    FixedString name;
    FUN_00845b60(const FixedString&);
};
struct Array;
struct ArrayVtable { void* (__thiscall *Destroy)(Array*,unsigned); void* (__thiscall *Allocate)(Array*,unsigned); };
extern const ArrayVtable DAT_00e32b88;
struct Array {
    const ArrayVtable* vptr;
    void* data;
    unsigned size,capacity;
    Array(unsigned count=0);
};
Array::Array(unsigned count) : data(0), size(0), capacity(0) {
    vptr=&DAT_00e32b88;
    if(count) { data=vptr->Allocate(this,count); capacity=count; }
}
struct FUN_00aba1f0 : FUN_00845b60 {
    virtual ~FUN_00aba1f0();
    Array array;
    FUN_00aba1f0();
};
// pdb: BSTextureData::BSTextureData | BSTextureData.obj | fnv360_0822_retail, call_seq, high
FUN_00aba1f0::FUN_00aba1f0() : FUN_00845b60(*DAT_0116ebb0) {}
}

// @f3 0x00ab0cc0 (community match, verified in this file)
namespace f3m_00ab0cc0 {
struct Ab0cc0Part
{
    int unk00;
    int unk04;
    int unk08;

    void __thiscall FUN_0083fa20(int value);
};

class Ab0cc0Owner
{
public:
    int unk00;
    int unk04;
    int unk08;
    Ab0cc0Part part0C;
    Ab0cc0Part part18;

    void __thiscall FUN_00ab0cc0(int value);
};

void __stdcall FUN_008459d0(int value);

// pdb: BSBound::SaveBinary | BSBound.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSNonUniformScaleExtraData::SaveBinary)
// pdb params: arStream
void __thiscall Ab0cc0Owner::FUN_00ab0cc0(int value)
{
    FUN_008459d0(value);
    part0C.FUN_0083fa20(value);
    part18.FUN_0083fa20(value);
}
}   // namespace f3m_00ab0cc0

// @f3 0x00aaeaf0 (community match, verified in this file)
#include <math.h>
extern double DAT_00dc2df0,DAT_00db7de8;
extern float DAT_0116d9f4,DAT_0116d9e8;
namespace f3m_00aaeaf0 {
namespace Task2496 {
struct C52020Dev; extern C52020Dev* DAT_0108f048;
struct NiFrustum {
    NiFrustum(bool);
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};

struct NiUpdateData {
    float m_fTime;
    bool m_b0;
    bool m_b1;
    bool m_b2;
    bool m_b3;
    bool m_b4;
};

struct C52020Res {
    unsigned unk00,unk04;
    unsigned int m_08;
    unsigned int m_0c;
};

struct C52020Obj;

struct C52020Dev {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual C52020Res* vfn_b0(int);
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual C52020Dev* vfn_c8();
    virtual C52020Dev* vfn_cc();
    unsigned int FUN_004dee70() { C52020Dev* d=vfn_c8(); if(!d) return 0; C52020Res* r=d->vfn_b0(0); if(!r) return 0; return r->m_0c; }
    unsigned int FUN_004dee10() { C52020Dev* d=vfn_c8(); if(!d) return 0; C52020Res* r=d->vfn_b0(0); if(!r) return 0; return r->m_08; }
};

struct C52020Setting { float m_fReserved; float m_fValue; };

struct C52020Filler {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct C52020Obj {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual float vfn_100();
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
    C52020Obj* m_ac;
    unsigned unkB0,unkB4;
    unsigned char m_b8;
    unsigned char unkB9; unsigned short unkBA;
    float m_bc;
    unsigned unkc0;
unsigned unkc4;
unsigned unkc8;
unsigned unkcc;
unsigned unkd0;
unsigned unkd4;
unsigned unkd8;
unsigned unkdc;
unsigned unke0;
unsigned unke4;
unsigned unke8;
unsigned unkec;
unsigned unkf0;
unsigned unkf4;
unsigned unkf8;
    float m_fc;
    float m_100;
    float m_104;
    float m_108;
    float m_10c;
    float m_110;
    void FUN_00839f90(NiFrustum* apFrustum);
    void FUN_008264c0(const NiUpdateData& kData);
    void FUN_00aaeaf0(float m_fFirstFloat, unsigned char ucFlag, C52020Obj* pObj, unsigned char ucArg4);
};

// pdb: BSSceneGraph::SetCameraFOV | BSSceneGraph.obj | fnv360_0721_beta, call_seq, medium
// pdb params: afFOV, abForce, apCamera, abSetLODMult
void C52020Obj::FUN_00aaeaf0(float afFov,unsigned char ucFlag,C52020Obj* apTarget,unsigned char ucArg4) {
    C52020Obj* aTarget=apTarget;
    if(!aTarget) aTarget=m_ac;
    if(!apTarget) {
        if(!ucFlag && m_bc==afFov) {
            if(ucArg4) aTarget->m_110=afFov/DAT_0116d9f4;
            return;
        }
        m_bc=afFov;
    }
    float aHdr=afFov*DAT_00dc2df0*DAT_00db7de8;
    NiFrustum aTile(false);
    aTile.m_fFarPlane=vfn_100();
    aTile.m_fNearPlane=DAT_0116d9e8;
    aTarget->m_fc=aTile.m_fFarPlane/aTile.m_fNearPlane;
    C52020Dev* aValue=DAT_0108f048;
    float aStart,aLen;
    if(aValue) {
        aStart=(float)aValue->FUN_004dee70()*(aTarget->m_108-aTarget->m_10c);
        aLen=(float)aValue->FUN_004dee10()*(aTarget->m_104-aTarget->m_100);
    } else {
        aStart=aTarget->m_108-aTarget->m_10c;
        aLen=aTarget->m_104-aTarget->m_100;
    }
    if(aValue) {
        if(aValue->vfn_cc() && aValue->vfn_cc()!=aValue->vfn_c8()) {
            C52020Res* aNode=aValue->vfn_cc()->vfn_b0(0);
            aStart=(float)aNode->m_0c;
            C52020Res* aRef=aValue->vfn_cc()->vfn_b0(0);
            aLen=(float)aRef->m_08;
        }
    }
    float aState=aStart/aLen;
    float aSize;
    if(m_b8 && !apTarget) aSize=1.0f;
    else aSize=0.75/(aStart/aLen);
    aTile.m_fLeftBound=-(float)tan(aHdr)*aSize;
    aTile.m_fRightBound=(float)tan(aHdr)*aSize;
    aTile.m_fBottomBound=-(float)tan(aHdr)*aState*aSize;
    aTile.m_fTopBound=(float)tan(aHdr)*aState*aSize;
    aTarget->FUN_00839f90(&aTile);
    NiUpdateData aOut={0.0f,false,false,false,false,false};
    aTarget->FUN_008264c0(aOut);
    if(ucArg4) aTarget->m_110=afFov/DAT_0116d9f4;
}
}
}   // namespace f3m_00aaeaf0

// @f3 0x00aa7e80 (community match, verified in this file)
namespace task2503 {
class NiPoint3 { public: float x,y,z; };
extern NiPoint3 DAT_0108ec68;
struct SSNode {
 bool __thiscall BSOcclusionPlane_WithinFrustumDistFirst(void*, void*);
 bool __thiscall BSOcclusionPlane_WithinFrustum(void*, int, NiPoint3);
 bool __thiscall FUN_00a9e540(void*);
};
struct DecisionNode { int type; int trueIndex; int falseIndex; };
struct VolumeRecord {
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
};
struct DecisionTree {
 int unk00;
 int unk04;
 VolumeRecord* volumes;
 int unk0c;
 int unk10;
 int unk14;
 DecisionNode* nodes;
 int unk1c;
 int unk20;
 int unk24;
 int nodeCount;
 int rootIndex;
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
 bool skipBounds;
 bool __thiscall FUN_00aa7e80(SSNode* query);
};
// @fnv 0x00c49560
// pdb: BSCompoundFrustum::ProcessPlane | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apPlane
bool DecisionTree::FUN_00aa7e80(SSNode* query) {
 VolumeRecord* result = 0;
 bool bResult = true;
 if (!skipBounds)
  bResult = query->BSOcclusionPlane_WithinFrustumDistFirst(&unk30, &unk94);
 if (bResult && nodeCount > 0) {
  int index = rootIndex;
  while (nodes[index].type != 2 && nodes[index].type != 3) {
   bool passed = false;
   switch (nodes[index].type) {
   case 7: {
    DecisionNode* next = &nodes[index+1];
    result = &volumes[next->type];
    passed = query->BSOcclusionPlane_WithinFrustum(result, 0, DAT_0108ec68);
    break;
   }
   case 8: {
    DecisionNode* next = &nodes[index+1];
    result = &volumes[next->type];
    passed = !query->FUN_00a9e540(result);
    break;
   }
   }
   index = passed ? nodes[index].trueIndex : nodes[index].falseIndex;
  }
  bResult = nodes[index].type == 2;
 }
 return bResult;
}

}

// @f3 0x00aa9930 (community match, verified in this file)
#include <string.h>
extern const char DAT_00dfa7b0[];
namespace f3m_00aa9930 {
namespace task2509 {
long __cdecl FUN_00c047de(const char*);
struct RangeNameObj {
    int unk00;
    int unk04;
    const char* m_pcName;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    short unkAC;
    unsigned char m_ucMin;
    unsigned char m_ucMax;
    void FUN_00aa9930();
};
// @fnv 0x00c45670
// pdb: BSRangeNode::ParseNameForRanges | BSRangeNode.obj | fnv360_0822_retail, vtable, medium
void RangeNameObj::FUN_00aa9930()
{
    const char* pcName2 = m_pcName;
    const char* pcStr = pcName2;
    unsigned int uiLen = strlen(pcStr);
    unsigned int i = 1;
    while (((pcStr[uiLen - i] >= '0' && pcStr[uiLen - i] <= '9') || pcStr[uiLen - i] == '-') && i <= uiLen)
        i++;
    pcStr = pcStr + (uiLen - i) + 1;
    int iMin = 0;
    int iMax_2 = 0xff;
    const char* pcDash = strstr(pcStr, DAT_00dfa7b0);
    if (pcDash) {
        if (pcDash != pcStr)
            iMin = FUN_00c047de(pcStr);
        pcStr = pcDash + 1;
        if (*pcStr)
            iMax_2 = FUN_00c047de(pcStr);
    } else if (*pcStr) {
        iMin = FUN_00c047de(pcStr);
        iMax_2 = iMin;
    }
    int iLow6;
    if (iMin < iMax_2)
        iLow6 = iMin;
    else
        iLow6 = iMax_2;
    m_ucMin = (unsigned char)iLow6;
    int iHigh4;
    if (iMin > iMax_2)
        iHigh4 = iMin;
    else
        iHigh4 = iMax_2;
    m_ucMax = (unsigned char)iHigh4;
}

}
}   // namespace f3m_00aa9930

// @f3 0x00aad410 (community match, verified in this file)
namespace f3m_00aad410 {
namespace Worker2512 {
struct HostV;
struct ObjV {
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
    virtual void Attach(HostV*);
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
    unsigned int m_uiValue1;
    bool TestFlag(unsigned int mask) const { return (m_uiValue1&mask)!=0; }
};
struct CtrlV {
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
    int m_i28;
    bool IsEmpty() const { return m_i28==0; }
    int BSCompoundFrustum_GetActivePlaneState();
    bool FUN_00aa7d80(ObjV*);
    void FUN_00aa7d20(int);
};
struct HostV {
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
    void* m_pv8c;
    int m_iFadeIndex;
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
    CtrlV* m_pkCtrl;
    bool HasX() const { return (bool)m_pv8c; }
    void FUN_008338f0(ObjV*);
    void FUN_00aad410(ObjV*);
};
// @fnv 0x00c4ee90
// pdb: BSCullingProcess::Process | BSCullingProcess.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
void HostV::FUN_00aad410(ObjV* pkObj)
{
    if (m_iFadeIndex != 2 && m_iFadeIndex != 1)
    {
        ObjV* pkTmp = pkObj;
        if (pkTmp->TestFlag(0x1000))
        {
            if (!pkTmp->TestFlag(0x100000))
                pkObj->Attach(this);
        }
        else if (!m_pkCtrl || m_pkCtrl->IsEmpty() || m_iFadeIndex == 3)
        {
            if (pkObj->TestFlag(0x800) || !HasX())
                pkObj->Attach(this);
            else
                FUN_008338f0(pkObj);
        }
        else if (pkObj->TestFlag(0x800) || ((!m_pkCtrl || m_pkCtrl->IsEmpty()) && !HasX()))
        {
            pkObj->Attach(this);
        }
        else
        {
            int iState = m_pkCtrl->BSCompoundFrustum_GetActivePlaneState();
            if (m_pkCtrl->FUN_00aa7d80(pkObj))
                pkObj->Attach(this);
            m_pkCtrl->FUN_00aa7d20(iState);
        }
    }
    else if (m_iFadeIndex == 1)
    {
        pkObj->Attach(this);
    }
}

}
}   // namespace f3m_00aad410

// @f3 0x00ab5570 (community match, verified in this file)
namespace f3m_00ab5570 {
namespace Task2517 {
struct D3DRect_Stub
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D3DDevice_Stub
{
    virtual long __stdcall v000();
    virtual long __stdcall v004();
    virtual long __stdcall v008();
    virtual long __stdcall v00c();
    virtual long __stdcall v010();
    virtual long __stdcall v014();
    virtual long __stdcall v018();
    virtual long __stdcall v01c();
    virtual long __stdcall v020();
    virtual long __stdcall v024();
    virtual long __stdcall v028();
    virtual long __stdcall v02c();
    virtual long __stdcall v030();
    virtual long __stdcall v034();
    virtual long __stdcall v038();
    virtual long __stdcall v03c();
    virtual long __stdcall v040();
    virtual long __stdcall v044();
    virtual long __stdcall v048();
    virtual long __stdcall v04c();
    virtual long __stdcall v050();
    virtual long __stdcall v054();
    virtual long __stdcall v058();
    virtual long __stdcall v05c();
    virtual long __stdcall v060();
    virtual long __stdcall v064();
    virtual long __stdcall v068();
    virtual long __stdcall v06c();
    virtual long __stdcall v070();
    virtual long __stdcall v074();
    virtual long __stdcall v078();
    virtual long __stdcall v07c();
    virtual long __stdcall v080();
    virtual long __stdcall v084();
    virtual long __stdcall v088();
    virtual long __stdcall v08c();
    virtual long __stdcall v090();
    virtual long __stdcall v094();
    virtual long __stdcall v098();
    virtual long __stdcall v09c();
    virtual long __stdcall v0a0();
    virtual long __stdcall v0a4();
    virtual long __stdcall v0a8();
    virtual long __stdcall v0ac();
    virtual long __stdcall v0b0();
    virtual long __stdcall v0b4();
    virtual long __stdcall v0b8();
    virtual long __stdcall v0bc();
    virtual long __stdcall v0c0();
    virtual long __stdcall v0c4();
    virtual long __stdcall v0c8();
    virtual long __stdcall v0cc();
    virtual long __stdcall v0d0();
    virtual long __stdcall v0d4();
    virtual long __stdcall v0d8();
    virtual long __stdcall v0dc();
    virtual long __stdcall v0e0();
    virtual long __stdcall SetRenderState(int eState, unsigned long dwValue);
    virtual long __stdcall v0e8();
    virtual long __stdcall v0ec();
    virtual long __stdcall v0f0();
    virtual long __stdcall v0f4();
    virtual long __stdcall v0f8();
    virtual long __stdcall v0fc();
    virtual long __stdcall v100();
    virtual long __stdcall v104();
    virtual long __stdcall v108();
    virtual long __stdcall v10c();
    virtual long __stdcall v110();
    virtual long __stdcall v114();
    virtual long __stdcall v118();
    virtual long __stdcall v11c();
    virtual long __stdcall v120();
    virtual long __stdcall v124();
    virtual long __stdcall v128();
    virtual long __stdcall SetScissorRect(const D3DRect_Stub* pRect);
};

struct NiDX9Renderer_Stub
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
    D3DDevice_Stub* m_pDirect3DDevice;
    D3DDevice_Stub* GetD3DDevice()
    {
        return m_pDirect3DDevice;
    }
};

struct ScissorBase_Stub
{
    void FUN_0083f630(NiDX9Renderer_Stub* pkRenderer);
};

struct ScissorProperty_Stub : ScissorBase_Stub
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
    D3DRect_Stub m_kScissorRect;

    void FUN_00ab5570(NiDX9Renderer_Stub* pkRenderer);
};

// @fnv 0x00c5d110
// pdb: BSScissorTriShape::RenderImmediate | BSScissorTriShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkRenderer
void ScissorProperty_Stub::FUN_00ab5570(NiDX9Renderer_Stub* pkRenderer)
{
    NiDX9Renderer_Stub* pkDX9Renderer = pkRenderer;
    unsigned long dwOldValue = 0;
    bool bScissorSetRes = false;

    if (m_kScissorRect.bottom != 0 || m_kScissorRect.top != 0 || m_kScissorRect.left != 0 || m_kScissorRect.right != 0)
    {
        if ((m_kScissorRect.left < 0 && m_kScissorRect.right < 0) ||
            (m_kScissorRect.left > 1 && m_kScissorRect.right > 1) ||
            (m_kScissorRect.top < 0 && m_kScissorRect.bottom < 0) ||
            (m_kScissorRect.top > 1 && m_kScissorRect.bottom > 1))
        {
            pkDX9Renderer->GetD3DDevice()->SetRenderState(0xae, 1);
            pkDX9Renderer->GetD3DDevice()->SetScissorRect(&m_kScissorRect);
            bScissorSetRes = true;
        }
    }

    FUN_0083f630(pkRenderer);

    if (bScissorSetRes)
        pkDX9Renderer->GetD3DDevice()->SetRenderState(0xae, dwOldValue);
}
}
}   // namespace f3m_00ab5570

// @f3 0x00aabed0 (community match, verified in this file)
namespace f3m_00aabed0 {
namespace Worker2524 {
struct Array {
    virtual void Slot00();
    virtual unsigned short* Allocate(unsigned int size);
    virtual void Free(unsigned short* data);
    unsigned short* data;
    unsigned int count;
    unsigned int capacity;
    void FUN_005480e0(unsigned short* dst,unsigned short* src,unsigned int count);
    bool ShouldShrink() {
        if (capacity>0x400) {
            if (count<=capacity-0x800) return true;
        } else {
            if (count<=(capacity>>2)) return true;
        }
        return false;
    }
    unsigned int ShrinkSize() { return capacity>0x800 ? capacity-0x400 : capacity>>1; }
    void FUN_00aabed0(unsigned int index,bool resize);
};
// pdb: BSSimpleArray<unsigned short,1024>::Remove | BSPolygon.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aiIndex, abShrink
void Array::FUN_00aabed0(unsigned int index,bool resize)
{
    if (resize && ShouldShrink()) {
        unsigned int newSize=ShrinkSize();
        unsigned short* newData=Allocate(newSize);
        FUN_005480e0(newData,data,index);
        FUN_005480e0(newData+index,data+index+1,count-1);
        Free(data);
        data=0;
        data=newData;
        capacity=newSize;
    } else {
        FUN_005480e0(data+index,data+index+1,count-index-1);
    }
    --count;
}
}
}   // namespace f3m_00aabed0

// @f3 0x00aaee80 (community match, verified in this file)
namespace f3m_00aaee80 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FUN_0082e4f0
{
    virtual ~FUN_0082e4f0();
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
};
inline long NiAtomicIncrementC51(long& lValue)
{
    return InterlockedIncrement(&lValue);
}
inline long NiAtomicDecrementC51(long& lValue)
{
    return InterlockedDecrement(&lValue);
}
class RefObjectC51
{
  public:
    virtual ~RefObjectC51();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrementC51(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicDecrementC51(m_uiRefCount) == 0)
            DeleteThis();
    }
    long m_uiRefCount;
};
template <class T> class NiPointerC51
{
  public:
    ~NiPointerC51()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerC51& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};
struct OwnedA
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual ~OwnedA();
};
struct MM2507 { void FUN_0086ba60(void*); };
void __cdecl FUN_0089e890(void*);
struct OwnedB
{
    void* data;
    ~OwnedB()
    {
        FUN_0089e890(data);
    }
    static void operator delete(void* p)
    {
        ((MM2507*)&DAT_01090a78)->FUN_0086ba60(p);
    }
};
struct DAT_00e8aa0c : FUN_0082e4f0
{
    NiPointerC51<RefObjectC51> m_spNode;
    OwnedB* m_pUserData;
    OwnedA* m_pkOwned;
    virtual ~DAT_00e8aa0c();
    void FUN_00aaee80();
};
// @fnv 0x00c51df0
__forceinline DAT_00e8aa0c::~DAT_00e8aa0c()
{
    m_spNode = 0;
    delete m_pkOwned;
    delete m_pUserData;
}


// pdb: BSSceneGraph::~BSSceneGraph | BSSceneGraph.obj | fnv360_0822_retail, call_seq, medium
void DAT_00e8aa0c::FUN_00aaee80() { this->DAT_00e8aa0c::~DAT_00e8aa0c(); }
}   // namespace f3m_00aaee80

// @f3 0x00aae280 (community match, verified in this file)
namespace Worker2530 {
struct FUN_0082ea60 {
 virtual void v0();
 ~FUN_0082ea60();
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
 FUN_0082ea60(unsigned int);
};
struct WorkerMemory { void* FUN_0086b930(unsigned int); };
extern WorkerMemory DAT_01090a78;
void* __cdecl FUN_00c00610(void*,int,unsigned int);
struct WorkerTask { unsigned int value; };
struct WorkerTaskManager { void FUN_00bce2c0(); };
WorkerTaskManager& __stdcall FUN_00bce1f0(WorkerTask*);
struct FUN_00aae280 : FUN_0082ea60 {
    unsigned int* data;
    unsigned int count;
    WorkerTask* task;
    FUN_00aae280();
};
// @fnv 0x00c503d0
// pdb: BSParticleSystemManager::BSParticleSystemManager | BSParticleSystemManager.obj | fnv360_0822_retail, call_seq, medium
FUN_00aae280::FUN_00aae280() : FUN_0082ea60(0) {
    count = 10;
    void* allocated = DAT_01090a78.FUN_0086b930(40);
    data = (unsigned int*)allocated;
    unsigned int result = count * 4;
    void* destination = data;
    FUN_00c00610(destination,-1,result);
    WorkerTask* storage = (WorkerTask*)DAT_01090a78.FUN_0086b930(4);
    WorkerTask* size = storage ? (storage->value = 0, storage) : 0;
    task = size;
    FUN_00bce1f0(task).FUN_00bce2c0();
}
}

// @f3 0x00aaf730 (community match, verified in this file)
namespace f3m_00aaf730 {
struct ObjX
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22();
    virtual bool IsEqual(ObjX* pkObj);
};
struct ListX
{
    ObjX** m_pBase;
    unsigned int m_uiMax;
    unsigned int m_uiSize;
    unsigned int GetSize() const
    {
        unsigned int n = m_uiSize;
        return n;
    }
    ObjX*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct FUN_00c53af0
{
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c; unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2c; unsigned int unk30;
    int m_i34;
    int m_i38;
    unsigned int unk3c;
    ListX** m_ppkLists;
    unsigned short unk44;
    unsigned short m_usElementCount;
    unsigned int GetCount() const
    {
        unsigned int n = m_usElementCount;
        return n;
    }
    bool FUN_00837860(FUN_00c53af0* pkObj);
    bool FUN_00aaf730(FUN_00c53af0* pkObj);
};
// @fnv 0x00c53af0
// pdb: NiBSBoneLODController::IsEqual | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkObject
bool FUN_00c53af0::FUN_00aaf730(FUN_00c53af0* pkObj)
{
    unsigned int i;
    if (!FUN_00837860(pkObj))
        return false;
    FUN_00c53af0* pkOther = pkObj;
    if (m_i34 != pkOther->m_i34 || m_i38 != pkOther->m_i38 || GetCount() != pkOther->m_usElementCount)
        return false;
    for (i = 0; i < m_usElementCount; i++)
    {
        ListX* pkA = m_ppkLists[i];
        ListX* pkB_fuj = pkOther->m_ppkLists[i];
        if ((pkA && !pkB_fuj) || (!pkA && pkB_fuj))
            return false;
        if (pkA && pkB_fuj)
        {
            if (pkA->GetSize() != pkB_fuj->GetSize())
                return false;
            for (unsigned int j = 0; j < pkA->GetSize(); j++)
            {
                if (!pkA->GetAt(j)->IsEqual(pkB_fuj->GetAt(j)))
                    return false;
            }
        }
    }
    return true;
}

}   // namespace f3m_00aaf730

// @f3 0x00aaff20 (community match, verified in this file)
extern const char* DAT_0116da58;
namespace f3m_00aaff20 {
class BA55320StringArray
{
  public:
    virtual ~BA55320StringArray();
    void FUN_00555790(unsigned int uiMaxSize);
    void FUN_005b3880(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00555790(uiIndex + m_usGrowBy);
        FUN_005b3880(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};


char* __cdecl FUN_00847b50(const char* pcString);
char* __cdecl FUN_00847d30(const char* pcPrefix, int iValue);
char* __cdecl FUN_00847d80(const char* pcPrefix, unsigned int uiValue);

class A55320Object
{
  public:
    void* m_pVtbl;
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
    int m_iLOD;
    unsigned int m_uiNumLODs;

    void FUN_00aaff20(BA55320StringArray* pkStrings);
};

// Appends the class name and formatted m_iLOD and m_uiNumLODs strings to pkStrings.
// @fnv 0x00a55320
// pdb: NiBSBoneLODController::GetViewerStrings | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void A55320Object::FUN_00aaff20(BA55320StringArray* pkStrings)
{
    pkStrings->Add(FUN_00847b50(DAT_0116da58));
    pkStrings->Add(FUN_00847d30("m_iLOD", m_iLOD));
    pkStrings->Add(FUN_00847d80("m_uiNumLODs", m_uiNumLODs));
}

}   // namespace f3m_00aaff20

// @f3 0x00aa7f70 (community match, verified in this file)
namespace f3m_00aa7f70 {
namespace task2526 {
struct Entry { int type; int a; int b; };
struct Target {
 int unk00, unk04, unk08, unk0c, unk10, unk14;
 Entry* data;
 int unk1c, unk20, unk24;
 int count;
 void BSCompoundFrustum_RemoveEmptyGroups();
};
// Compacts the entry array in place, skipping type 4/5 pairs followed by type 6 and copying type 7/8 entries with their following entry.
// @fnv 0x00c49700
// pdb: BSCompoundFrustum::RemoveEmptyGroups | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
void Target::BSCompoundFrustum_RemoveEmptyGroups() {
 int original = 0;
 int removed = count;
 for (int i = 0; i < count; i++) {
  while (i < count && count > 0 && (data[i + original].type == 4 || data[i + original].type == 5) && data[i + original + 1].type == 6) {
   original += 2;
   count -= 2;
  }
  if (i + original < removed) {
   int* source = &data[i + original].type;
   data[i].type = *source;
   if (data[i].type == 7 || data[i].type == 8) {
    int* next = &data[i + original + 1].type;
    data[i + 1].type = *next;
    i++;
   }
  }
 }
}


}
}   // namespace f3m_00aa7f70

// @f3 0x00aae5e0 (community match, verified in this file)
namespace Worker2540 {
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct Task {
    unsigned int value;
    ~Task() {}
    static void operator delete(void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
};
struct Manager { void FUN_00bce370(); };
Manager* __stdcall FUN_00bce1f0(Task*);
struct FUN_0082e4f0 { virtual ~FUN_0082e4f0(); };
struct FUN_00aae5e0 : FUN_0082e4f0 {
    virtual ~FUN_00aae5e0();
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
    void* data;
    unsigned int count;
    Task* task;
};
// pdb: BSParticleSystemManager::~BSParticleSystemManager | BSParticleSystemManager.obj | fnv360_0822_retail, call_seq, high
FUN_00aae5e0::~FUN_00aae5e0()
{
    void* old=data;
    DAT_01090a78.FUN_0086ba60(old);
    data=0;
    count=0;
    FUN_00bce1f0(task)->FUN_00bce370();
    delete task;
}
}

// @f3 0x00ab6580 (community match, verified in this file)
namespace f3m_00ab6580 {
struct FUN_00ab6580_Part
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    bool __thiscall FUN_007ff810(FUN_00ab6580_Part* other);
};

class FUN_00ab6580_Obj
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;

    FUN_00ab6580_Part part18;
    FUN_00ab6580_Part part28;
    FUN_00ab6580_Part part38;

    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;

    bool __thiscall FUN_00ac5f20(FUN_00ab6580_Obj* other);
    bool __thiscall BSPSysSimpleColorModifier_IsEqual(FUN_00ab6580_Obj* other);
};

// pdb: BSPSysSimpleColorModifier::IsEqual | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
bool FUN_00ab6580_Obj::BSPSysSimpleColorModifier_IsEqual(FUN_00ab6580_Obj* other) {
    if (!FUN_00ac5f20(other)) return false;
    if (other->unk48 == unk48 && other->unk4C == unk4C && other->unk50 == unk50 &&
        other->unk54 == unk54 && other->unk58 == unk58 && other->unk5C == unk5C &&
        other->part18.FUN_007ff810(&part18) && other->part28.FUN_007ff810(&part28) &&
        other->part38.FUN_007ff810(&part38)) return true;
    return false;
}
}   // namespace f3m_00ab6580

// @f3 0x00ab6b30 (community match, verified in this file)
namespace f3m_00ab6b30 {
namespace Task2534 {
struct NiObject;
struct TCVec3
{
    float x, y, z;
};

struct TCEq
{
    bool FUN_008c1550(NiObject* pObject);
};

struct TCColorEq : public TCEq
{
    int unk00;
    int unk04;
    int unk08;
    TCVec3 m0c;
    TCVec3 m18;
    float m24;
    bool FUN_00ab6b30(NiObject* pObject);
};

// Calls the base equality check, then compares m0c, m18 and m24 against the same fields of pObject cast to TCColorEq.
// @fnv 0x00c60f60
// pdb: BSMultiBoundCapsule::IsEqual | BSMultiBoundCapsule.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
bool TCColorEq::FUN_00ab6b30(NiObject* pObject)
{
    bool bResultTmp = FUN_008c1550(pObject);
    if (bResultTmp)
    {
        TCColorEq* pOther = (TCColorEq*)pObject;
        {
            TCVec3* pB = &pOther->m0c;
            TCVec3* pA = &m0c;
            bResultTmp = pA->x == pB->x && pA->y == pB->y && pA->z == pB->z;
        }
        {
            TCVec3* pB3 = &pOther->m18;
            TCVec3* pA9 = &m18;
            bResultTmp &= (bool)(int)(pA9->x == pB3->x && pA9->y == pB3->y && pA9->z == pB3->z);
        }
        {
            float fValue3 = m24;
            bResultTmp &= (fValue3 == pOther->m24);
        }
    }
    return bResultTmp;
}

}
}   // namespace f3m_00ab6b30

// @f3 0x00aa4800 (community match, verified in this file)
namespace task2553 {
struct FUN_00c3fa70_elem
{
    virtual int vDtor(int flags);
};

struct DynamicMemoryAllocator
{
    void FUN_0086ba60(void* apPtr);
};

extern "C" DynamicMemoryAllocator DAT_01090a78;

struct FUN_00aa4780
{
    virtual void v00();
    ~FUN_00aa4780();
};

struct FUN_00aa4800 : public FUN_00aa4780
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned int m_uCount4c;
    FUN_00c3fa70_elem** m_ppItems50;
    void* m_p54;

    virtual ~FUN_00aa4800();
};

// @fnv 0x00c3fa70
// pdb: BSTaskManager<__int64>::~BSTaskManager<__int64> | IOManager.obj | fnv360_0822_retail, call_seq, high
FUN_00aa4800::~FUN_00aa4800()
{
    unsigned int i = 0;
    FUN_00c3fa70_elem* item3;
    FUN_00c3fa70_elem* eTmp;
    for (; i < m_uCount4c; i++)
    {
        item3 = m_ppItems50[i];
        eTmp = item3;
        (eTmp != 0) ? eTmp->vDtor(1) : 0;
    }
    void* pItems = m_ppItems50;
    DAT_01090a78.FUN_0086ba60(pItems);
    void* pTail2 = m_p54;
    DAT_01090a78.FUN_0086ba60(pTail2);
}


}

// @f3 0x00aaab30 (community match, verified in this file)
namespace f3m_00aaab30 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct Ref2554 {
 virtual ~Ref2554();
 virtual void DeleteThis();
 long refs;
 void IncRefCount() { InterlockedIncrement(&refs); }
 void DecRefCount() { if (InterlockedDecrement(&refs)==0) DeleteThis(); }
};
struct Array2554:NiTObjectArray<NiPointer<Ref2554> > { void FUN_00aaab30(); };
// pdb: NiTArray<NiPointer<BSTempEffect>,NiTNewInterface<NiPointer<BSTempEffect> > >::RemoveAll | GarbageCollector.obj | fnv360_0822_retail, call_seq, medium
void Array2554::FUN_00aaab30() {
 for (unsigned short i=0;i<m_usSize;i++) {m_pBase[i]=NiPointer<Ref2554>();}
 m_usSize=0;
 m_usESize=0;
}
}   // namespace f3m_00aaab30

// @f3 0x00ab9ec0 (community match, verified in this file)
namespace Worker2557 {
struct Type { void* name; Type* parent; };
extern Type DAT_0108edc0;
struct Payload { unsigned int unk00,unk04; void* key; };
struct Object {
    virtual void Slot00();
    virtual void Slot04();
    virtual Type* GetType();
    unsigned int unk04,unk08,unk0c,unk10,unk14;
    Payload* payload;
};
struct Map { bool FUN_00bea7b0(void*,void**); };
struct Context {
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
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    Map* map;
};
struct Destination { void FUN_00ab9e10(Object* const*); };
inline bool InList(Type*& type) {
    while(type) {
        if(type==&DAT_0108edc0) return true;
        type=type->parent;
    }
    return false;
}
struct Owner {
    unsigned int unk00,unk04;
    Destination destination;
    bool FUN_00ab9ec0(Context*,Object*);
};
// pdb: BSNodeReferences::AddParentRef | BSReference.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: arStream, apObject
bool Owner::FUN_00ab9ec0(Context* context,Object* object)
{
    Object* local;
    Payload* payload;
    Type* type;
    bool found;
    Object* result;
    void* key;
    {
        void* out;
        if(!object) result=0;
        else {
            type=object->GetType();
            found=InList(type);
            result=(Object*)((found ? -1 : 0)&(int)object);
        }
        local=result;
        if(local) {
            payload=local->payload;
            if(payload) {
                key=payload->key;
                out=0;
                if(context->map && key) context->map->FUN_00bea7b0(key,&out);
                if(out) {
                    destination.FUN_00ab9e10(&local);
                    return true;
                }
            }
        }
    }
    return false;
}
}

// @f3 0x00aabf90 (community match, verified in this file)
namespace f3m_00aabf90 {
struct CleanupObj2544
{
    virtual int V0(int a);
    virtual void V1();
    long rc;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct CleanupRef2544
{
    CleanupObj2544* p;
    ~CleanupRef2544()
    {
        if (p)
        {
            CleanupObj2544* q = p;
            if (InterlockedDecrement(&q->rc) == 0)
                q->V1();
        }
    }
};
struct FUN_00aabf90
{
    CleanupObj2544* m00;
    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24;
    int m28;
    CleanupRef2544 r2c;
    CleanupRef2544 r30;
    ~FUN_00aabf90();
};
// @fnv 0x00c4ccd0
// pdb: BSPolygon2D::~BSPolygon2D | BSPolygon.obj | fnv360_0822_retail, call_gap, low
FUN_00aabf90::~FUN_00aabf90()
{
    if (m28 == 0)
    {
        CleanupObj2544* o = m00;
        CleanupObj2544* p = o;
        (void)(p ? p->V0(1) : 0);
    }
}

}   // namespace f3m_00aabf90

// @f3 0x00aa6c20 (community match, verified in this file)
namespace f3m_00aa6c20 {
namespace task2565 {
void __cdecl FUN_0089e890(void*);

class NiMemObject
{
};
class FUN_00825830 : public NiMemObject
{
  public:
    virtual ~FUN_00825830();
    unsigned int m_uiRefCount;
};

struct NodeRef;
struct NodeArrayAlloc
{
    static inline void Deallocate(void* p)
    {
        FUN_0089e890(p);
    }
};
struct NodeArray
{
    virtual ~NodeArray()
    {
        NodeArrayAlloc::Deallocate(m_pBase);
    }
    NodeRef** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    inline void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; ++i)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

class FUN_00aa6c20 : public FUN_00825830
{
  public:
    NodeArray m_aiIndexedValues;
    ~FUN_00aa6c20();
};

// @fnv 0x00c3bab0
// pdb: BSNodeReferences::~BSNodeReferences | BSStream.obj | fnv360_0822_retail, call_seq, high
FUN_00aa6c20::~FUN_00aa6c20()
{
    m_aiIndexedValues.RemoveAll();
}
}  // namespace task2565
}   // namespace f3m_00aa6c20

// @f3 0x00ab0cf0 (community match, verified in this file)
namespace f3m_00ab0cf0 {
class ColorPair2572
{
  public:
    float r;
    float g;
    float b;
    bool operator==(const ColorPair2572& c) const
    {
        return r == c.r && g == c.g && b == c.b;
    }
};

class ColorBase2572
{
  public:
    bool FUN_00845af0(const ColorBase2572* pkOther);
};

class ColorProperty2572 : public ColorBase2572
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ColorPair2572 m_kPrimaryColor;  // +0x0c
    ColorPair2572 m_kColorB;        // +0x18

    bool FUN_00ab0cf0(const ColorBase2572* pkObject);
};

// @fnv 0x00c38090
// pdb: BSBound::IsEqual | BSBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
bool ColorProperty2572::FUN_00ab0cf0(const ColorBase2572* pkObject)
{
    bool bEqual = FUN_00845af0(pkObject);
    if (bEqual)
    {
        const ColorProperty2572* pkOther = (const ColorProperty2572*)pkObject;
        bEqual = m_kPrimaryColor == pkOther->m_kPrimaryColor;
        bEqual &= m_kColorB == pkOther->m_kColorB;
    }
    return bEqual;
}

}   // namespace f3m_00ab0cf0

// @f3 0x00aa0b70 (community match, verified in this file)
namespace f3m_00aa0b70 {
namespace task2571 {
class ColorPair
{
  public:
    float r;
    float g;
    float b;
    bool operator==(const ColorPair& c) const
    {
        return r == c.r && g == c.g && b == c.b;
    }
};

class ColorPropertyBase
{
  public:
    bool FUN_008c1550(const ColorPropertyBase* pkOther);
};

class ColorProperty : public ColorPropertyBase
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ColorPair m_kPrimaryColor;  // +0x0c
    ColorPair m_kColorB;        // +0x18

    bool FUN_00aa0b70(const ColorPropertyBase* pkObject);
};

// @fnv 0x00c38090
// pdb: BSMultiBoundAABB::IsEqual | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: apObject
bool ColorProperty::FUN_00aa0b70(const ColorPropertyBase* pkObject)
{
    bool bEqual = FUN_008c1550(pkObject);
    if (bEqual)
    {
        const ColorProperty* pkOther = (const ColorProperty*)pkObject;
        bEqual = m_kPrimaryColor == pkOther->m_kPrimaryColor;
        bEqual &= m_kColorB == pkOther->m_kColorB;
    }
    return bEqual;
}


}
}   // namespace f3m_00aa0b70

// @f3 0x00aa0a00 (community match, verified in this file)
extern const char* DAT_0116d11c;
namespace f3m_00aa0a00 {
char* __cdecl FUN_00847b50(const char*);
struct Array2578 {
 virtual ~Array2578();
 void* m_pBase;
 unsigned short m_usMaxSize,m_usSize,m_usESize,m_usGrowBy;
 void FUN_00555790(unsigned int);
 void FUN_005b3880(unsigned int,void**);
};
struct Member2578 { void* FUN_00823bc0(const char*); };
struct Viewer2578 {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
Member2578 axis;
 void FUN_00aa1d60(Array2578*);
 void FUN_00aa0a00(Array2578*);
};
// @fnv 0x00a564d0
// pdb: BSMultiBoundOBB::GetViewerStrings | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void Viewer2578::FUN_00aa0a00(Array2578* pArray2578)
{
    FUN_00aa1d60(pArray2578);
    void* result = FUN_00847b50(DAT_0116d11c);
    unsigned int index = pArray2578->m_usSize;
    if (index >= pArray2578->m_usMaxSize)
        pArray2578->FUN_00555790(index + pArray2578->m_usGrowBy);
    pArray2578->FUN_005b3880(index, &result);
    result = axis.FUN_00823bc0("Axis");
    index = pArray2578->m_usSize;
    if (index >= pArray2578->m_usMaxSize)
        pArray2578->FUN_00555790(index + pArray2578->m_usGrowBy);
    pArray2578->FUN_005b3880(index, &result);
}
}   // namespace f3m_00aa0a00

// @f3 0x00ab1020 (community match, verified in this file)
#include <math.h>
namespace f3m_00ab1020 {
struct PerpPoint2555 { float x,y,z; PerpPoint2555 NiPoint3_UnitCross(const PerpPoint2555&) const; PerpPoint2555 FUN_00ab1020() const; };
// @fnv 0x00c5a800
// pdb: NiPoint3::Perpendicular | BSTestObjects.obj | fnv360_0822_debug, callee_sim, low
PerpPoint2555 PerpPoint2555::FUN_00ab1020() const
{
    if (fabs(x) < fabs(y))
    {
        if (fabs(z) < fabs(x))
            return NiPoint3_UnitCross(reinterpret_cast<const PerpPoint2555&>(DAT_00f725b0));
        else
            return NiPoint3_UnitCross(reinterpret_cast<const PerpPoint2555&>(DAT_00f72598));
    }
    else
    {
        if (fabs(z) < fabs(y))
            return NiPoint3_UnitCross(reinterpret_cast<const PerpPoint2555&>(DAT_00f725b0));
        else
            return NiPoint3_UnitCross(reinterpret_cast<const PerpPoint2555&>(DAT_00f725a4));
    }
}
}   // namespace f3m_00ab1020

// @f3 0x00aa8030 (community match, verified in this file)
namespace f3m_00aa8030 {
struct FUN_00832f20 { float x,y,z,constant; FUN_00832f20(); };
struct FrustumPlaneSet
{
    FUN_00832f20 planes[6];
    unsigned int activePlanes;
    static __forceinline void* operator new(unsigned int, void* storage)
    {
        return storage;
    }
    static void operator delete(void*, void*);
    __forceinline FrustumPlaneSet()
    {
        activePlanes = 63;
    }
};

struct FrustumArrayConstruction
{
    void FUN_00aa8030(void* elements, int count);
};

// @fnv 0x00c4a360
void FrustumArrayConstruction::FUN_00aa8030(void* elements, int count)
{
    for (unsigned int index = 0; index < static_cast<unsigned int>(count); ++index)
    {
        new (static_cast<FrustumPlaneSet*>(elements) + index) FrustumPlaneSet;
    }
}
}   // namespace f3m_00aa8030

// @f3 0x00aab060 (community match, verified in this file)
namespace f3m_00aab060 {
namespace Task2590 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00aa9840
{
    FUN_00aa9840();
    virtual void vf0();
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
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
};
struct S_00c4aca0_Obj : FUN_00aa9840
{
    S_00c4aca0_Obj()
    {}
    virtual void vf0();
};
struct S_00c4aca0_Self
{
    void __thiscall FUN_00aa9a10(S_00c4aca0_Obj* obj, int arg);
    S_00c4aca0_Obj* __thiscall FUN_00aab060(int arg);
};
// @fnv 0x00c4aca0
// pdb: BSDebrisNode::CreateClone | BSDebrisNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
S_00c4aca0_Obj* __thiscall S_00c4aca0_Self::FUN_00aab060(int arg)
{
    S_00c4aca0_Obj* p = new S_00c4aca0_Obj;
    this->FUN_00aa9a10(p, arg);
    return p;
}

}
}   // namespace f3m_00aab060

// @f3 0x00ab61a0 (community match, verified in this file)
namespace f3m_00ab61a0 {
namespace Worker2580 {
struct CloneProcess;
struct Group { unsigned int a,b,c,d; };
struct ModifierBase {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;
    void FUN_00ac5e70(ModifierBase*,CloneProcess&);
};
struct Modifier : ModifierBase {
    Group first,second,third;
    float value48,value4c,value50,value54,value58,value5c;
    void FUN_00ab61a0(ModifierBase*,CloneProcess&);
};
// pdb: BSPSysSimpleColorModifier::CopyMembers | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSPSysSubTexModifier::CopyMembers)
// pdb params: pkDest, kCloning
void Modifier::FUN_00ab61a0(ModifierBase* base,CloneProcess& process)
{
    FUN_00ac5e70(base,process);
    Modifier* destination=static_cast<Modifier*>(base);
    destination->first=first;
    destination->second=second;
    destination->third=third;
    destination->value48=value48;
    destination->value4c=value4c;
    destination->value50=value50;
    destination->value54=value54;
    destination->value58=value58;
    destination->value5c=value5c;
}
}
}   // namespace f3m_00ab61a0

// @f3 0x00aae3d0 (community match, verified in this file)
namespace f3m_00aae3d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct RefTarget2598
{
    virtual void Reserved();
    virtual void DeleteThis();
    volatile long refCount;
};
struct ScopedRef2598
{
    RefTarget2598* object;
    __forceinline ScopedRef2598() : object(0)
    {
        if (object)
        {
            RefTarget2598* retained = object;
            InterlockedIncrement(&retained->refCount);
        }
    }
    __forceinline ~ScopedRef2598()
    {
        if (object)
        {
            RefTarget2598* released = object;
            if (InterlockedDecrement(&released->refCount) == 0)
                released->DeleteThis();
        }
    }
};
struct Owner2598
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
    virtual void v56();
    virtual void GetRefTarget2598(int, RefTarget2598**);
    void FUN_00aae3d0(int);
};
// @fnv 0x00c51700
// pdb: BSParticleSystemManager::DetachChild | BSParticleSystemManager.obj | fnv360_0721_beta, vtable, medium
// pdb params: pkChild
void Owner2598::FUN_00aae3d0(int arg)
{
    ScopedRef2598 ptr;
    GetRefTarget2598(arg, &ptr.object);
}

}   // namespace f3m_00aae3d0

// @f3 0x00ab6050 (community match, verified in this file)
namespace f3m_00ab6050 {
namespace Task2596 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00ac5e10
{
    FUN_00ac5e10();
    virtual void vf0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
};
struct S_00c4aca0_Obj : FUN_00ac5e10
{
    S_00c4aca0_Obj()
    {}
    virtual void vf0();
};
struct S_00c4aca0_Self
{
    void __thiscall FUN_00ac5e70(S_00c4aca0_Obj* obj, int arg);
    S_00c4aca0_Obj* __thiscall FUN_00ab6050(int arg);
};
// @fnv 0x00c4aca0
// pdb: BSPSysStripUpdateModifier::CreateClone | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCloning
S_00c4aca0_Obj* __thiscall S_00c4aca0_Self::FUN_00ab6050(int arg)
{
    S_00c4aca0_Obj* p = new S_00c4aca0_Obj;
    this->FUN_00ac5e70(p, arg);
    return p;
}

}
}   // namespace f3m_00ab6050

// @f3 0x00aaaef0 (community match, verified in this file)
namespace f3m_00aaaef0 {
namespace task2589 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00aa9840
{
    FUN_00aa9840();
    virtual void vf0();
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
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
};
struct S_00c4aca0_Obj : FUN_00aa9840
{
    S_00c4aca0_Obj()
    {}
    virtual void vf0();
};
struct S_00c4aca0_Self
{
    void __thiscall FUN_00aa9a10(S_00c4aca0_Obj* obj, int arg);
    S_00c4aca0_Obj* __thiscall FUN_00aaaef0(int arg);
};
// @fnv 0x00c4aca0
// pdb: BSBlastNode::CreateClone | BSBlastNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
S_00c4aca0_Obj* __thiscall S_00c4aca0_Self::FUN_00aaaef0(int arg)
{
    S_00c4aca0_Obj* p = new S_00c4aca0_Obj;
    this->FUN_00aa9a10(p, arg);
    return p;
}


}
}   // namespace f3m_00aaaef0

// @f3 0x00ab0d80 (community match, verified in this file)
namespace task2604 {
class F3StringAllocator
{
public:
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};

extern F3StringAllocator DAT_01090a78;
extern char* __cdecl FUN_008242a0(const char* text);

class NiFixedString;
extern NiFixedString EmptyFS;

class NiFixedString
{
public:
    char* m_kHandle;

    void* operator new(unsigned int size)
    {
        return DAT_01090a78.FUN_0086b930(size);
    }

    void operator delete(void* memory)
    {
        DAT_01090a78.FUN_0086ba60(memory);
    }

    NiFixedString(const char* text)
    {
        if (text == 0)
            m_kHandle = EmptyFS.m_kHandle;
        else
            m_kHandle = FUN_008242a0(text);
    }
};

extern NiFixedString* DAT_0116da80;

// pdb: BSBound::InitSDM | BSBound.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00ab0d80()
{
    DAT_0116da80 = new NiFixedString("BBX");
}

}

// @f3 0x00aa7020 (community match, verified in this file)
namespace f3m_00aa7020 {
void* __cdecl FUN_0089eb90(unsigned);
struct FUN_00ab5d60 {
 virtual ~FUN_00ab5d60();
 FUN_00ab5d60();
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
};
struct DAT_00e89d44 : FUN_00ab5d60 {
 unsigned fieldb0,fieldb4;
 DAT_00e89d44() { fieldb0=0; fieldb4=0; }
 static void* operator new(unsigned n) throw() { return FUN_0089eb90(n); }
};
// pdb: BSValueNode::CreateObject | BSValueNode.obj | fnv360_0822_retail, objrun, medium
DAT_00e89d44* __cdecl FUN_00aa7020() { return new DAT_00e89d44(); }
}   // namespace f3m_00aa7020

// @f3 0x00aab1c0 (community match, verified in this file)
namespace f3m_00aab1c0 {
namespace Worker2591 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00aa9840 {
    virtual void Slot00();
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
    FUN_00aa9840();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};
struct Object : FUN_00aa9840 {
    Object() {}
    virtual void Slot00();
};
struct Factory {
    void FUN_00aa9a10(Object*,int);
    Object* FUN_00aab1c0(int);
};
// pdb: BSDamageStage::CreateClone | BSDamageStage1.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
Object* Factory::FUN_00aab1c0(int argument)
{
    Object* result=new Object;
    FUN_00aa9a10(result,argument);
    return result;
}
}
}   // namespace f3m_00aab1c0

// @f3 0x00ab0440 (community match, verified in this file)
namespace task2615 {
struct Heap2615 {void* FUN_0086b930(unsigned int);};
extern Heap2615 DAT_01090a78;
struct FUN_00ab0320 {
 unsigned int m_00,m_04,m_08;
 unsigned short m_0c; unsigned char m_0e;
 FUN_00ab0320() {m_0c=0; m_0e=0xff;}
 static void* operator new[](unsigned int size) {return DAT_01090a78.FUN_0086b930(size);}
};
FUN_00ab0320* __cdecl FUN_00ab0440(unsigned int n) {return new FUN_00ab0320[n];}

}

// @f3 0x00aae560 (community match, verified in this file)
namespace f3m_00aae560 {
namespace Task2620 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*,unsigned int);
struct FUN_00aae280 {
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
FUN_00aae280();
static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
static void operator delete(void* p,unsigned int n) { FUN_0089ec10(p,n); }
};
struct Owner {
void FUN_0082daa0(FUN_00aae280*,void*);
FUN_00aae280* FUN_00aae560(void*);
};
// pdb: BSParticleSystemManager::CreateClone | BSParticleSystemManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCloning
FUN_00aae280* Owner::FUN_00aae560(void* arg) {
 FUN_00aae280* obj=0;
 obj=new FUN_00aae280();
 FUN_0082daa0(obj,arg);
 return obj;
}
}
}   // namespace f3m_00aae560

// @f3 0x00aae450 (community match, verified in this file)
namespace f3m_00aae450 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace task2599 {
struct RefTarget
{
    virtual void Reserved();
    virtual void DeleteThis();
    volatile long refCount;
};
struct ScopedRef
{
    RefTarget* object;
    __forceinline ScopedRef() : object(0)
    {
        if (object)
        {
            RefTarget* retained = object;
            InterlockedIncrement(&retained->refCount);
        }
    }
    __forceinline ~ScopedRef()
    {
        if (object)
        {
            RefTarget* released = object;
            if (InterlockedDecrement(&released->refCount) == 0)
                released->DeleteThis();
        }
    }
};
struct Owner
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
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void GetRefTarget(int, RefTarget**);
    void FUN_00aae450(int);
};
// @fnv 0x00c51700
// pdb: BSParticleSystemManager::DetachChildAt | BSParticleSystemManager.obj | fnv360_0721_beta, vtable, medium
// pdb params: i
void Owner::FUN_00aae450(int arg)
{
    ScopedRef ptr;
    GetRefTarget(arg, &ptr.object);
}

}
}   // namespace f3m_00aae450

// @f3 0x00aabe60 (community match, verified in this file)
namespace f3m_00aabe60 {
namespace task2627 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_0083f500 {
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
FUN_0083f500(unsigned int);
static void* operator new(unsigned int size) {return FUN_0089eb90(size);}
};
FUN_0083f500* __stdcall FUN_00aabe60(unsigned int value) {return new FUN_0083f500(value);}
}
}   // namespace f3m_00aabe60

// @f3 0x00aba530 (community match, verified in this file)
namespace task2605 {
class F3StringAllocator
{
public:
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};

extern F3StringAllocator DAT_01090a78;
extern char* __cdecl FUN_008242a0(const char* text);

class NiFixedString;
extern NiFixedString EmptyFS;

class NiFixedString
{
public:
    char* m_kHandle;

    void* operator new(unsigned int size)
    {
        return DAT_01090a78.FUN_0086b930(size);
    }

    void operator delete(void* memory)
    {
        DAT_01090a78.FUN_0086ba60(memory);
    }

    NiFixedString(const char* text)
    {
        if (text == 0)
            m_kHandle = EmptyFS.m_kHandle;
        else
            m_kHandle = FUN_008242a0(text);
    }
};

extern NiFixedString* DAT_0116ebbc;

// pdb: BSAttachPoints::InitSDM | BSAttachPoints.obj | fnv360_0822_retail, call_seq, medium
void __cdecl FUN_00aba530()
{
    DAT_0116ebbc = new NiFixedString("ATP");
}

}

// @f3 0x00ab8b10 (community match, verified in this file)
namespace f3m_00ab8b10 {
namespace task2624 {
void* FUN_0089eb90(unsigned int);
struct FUN_00ab8480 {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void*);
    FUN_00ab8480();
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
};
struct Owner {
    void BSPSysArrayEmitter_CopyMembers(FUN_00ab8480*,int);
    FUN_00ab8480* FUN_00ab8b10(int);
};
// pdb: BSPSysArrayEmitter::CreateClone | BSPSysArrayEmitter.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
FUN_00ab8480* Owner::FUN_00ab8b10(int arg) {
    FUN_00ab8480* item = new FUN_00ab8480;
    BSPSysArrayEmitter_CopyMembers(item,arg);
    return item;
}
}
}   // namespace f3m_00ab8b10

// @f3 0x00ab9250 (community match, verified in this file)
namespace f3m_00ab9250 {
namespace task2611 {
void* __cdecl FUN_0089eb90(unsigned);struct CloningProcess;
struct Modifier {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;float value;unsigned unk24,unk28,unk2c,unk30,unk34,unk38;void FUN_00ac5e70(Modifier*,CloningProcess&);Modifier* FUN_00ab9250(CloningProcess&);};
struct FUN_00ab8ed0:Modifier {FUN_00ab8ed0();static void*operator new(unsigned n){return FUN_0089eb90(n);}static void operator delete(void*);};
// pdb: BSParentVelocityModifier::CreateClone | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
Modifier* Modifier::FUN_00ab9250(CloningProcess& process){Modifier*p=new FUN_00ab8ed0;FUN_00ac5e70(p,process);p->value=value;return p;}
}
}   // namespace f3m_00ab9250

// @f3 0x00ab7ca0 (community match, verified in this file)
namespace task2637 {
void* __cdecl FUN_0089eb90(unsigned int);
struct Fixed {const char* value;};
extern Fixed DAT_0108f3fc;
struct FUN_00ab7c10 {
 unsigned int unk00,unk04,unk08,unk0c,unk10;
 FUN_00ab7c10();
 static void* operator new(unsigned int size) {return FUN_0089eb90(size);}
 void FUN_008245d0(const Fixed&);
};
FUN_00ab7c10* FUN_00ab7ca0() {
 FUN_00ab7c10* object=new FUN_00ab7c10;
 object->FUN_008245d0(DAT_0108f3fc);
 return object;
}
}

// @f3 0x00aa6080 (community match, verified in this file)
namespace Task2635 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*,unsigned int);
struct FixedString { const char* text; };
extern FixedString DAT_0108f3fc;
struct FUN_00aa5fa0 {
 int unk00,unk04,unk08,unk0c;
 FUN_00aa5fa0();
 static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
 static void operator delete(void* p,unsigned int n) { FUN_0089ec10(p,n); }
 void FUN_008245d0(const FixedString&);
};
// pdb: BSXFlags::CreateObject | BSXFlags.obj | fnv360_0822_retail, objrun, medium
FUN_00aa5fa0* FUN_00aa6080() {
 FUN_00aa5fa0* object=new FUN_00aa5fa0;
 object->FUN_008245d0(DAT_0108f3fc);
 return object;
}
}

// @f3 0x00aad6b0 (community match, verified in this file)
namespace f3m_00aad6b0 {
namespace task2630 {
struct NiPoint3 {float x,y,z;};
struct FUN_00c4fce0_cls
{
    int unk00,unk04,unk08;
    NiPoint3 m_pos;
    float m_18;
    bool FUN_008c1550(void* other);
    bool FUN_00aad6b0(FUN_00c4fce0_cls* other);
};

// Compares this object with another: first calls FUN_008c1550, then checks m_pos x/y/z and m_18 are equal, returning the combined result.
// @fnv 0x00c4fce0
// pdb: BSMultiBoundSphere::IsEqual | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: apObject
bool FUN_00c4fce0_cls::FUN_00aad6b0(FUN_00c4fce0_cls* other)
{
    bool r6 = FUN_008c1550(other);
    if (r6)
    {
        FUN_00c4fce0_cls* o4 = other;
        NiPoint3* pb = &o4->m_pos;
        NiPoint3* pa = &m_pos;
        r6 = (pa->x == pb->x && pa->y == pb->y && pa->z == pb->z);
        float t = m_18;
        r6 = r6 & (t == o4->m_18);
    }
    return r6;
}


}
}   // namespace f3m_00aad6b0

// @f3 0x00aae010 (community match, verified in this file)
namespace f3m_00aae010 {
struct FUN_00aae010_arg;
struct FUN_00aa91e0_cls { void FUN_00aa91e0(); };
struct FUN_00826660_cls { void FUN_00826660(FUN_00aae010_arg*); };
struct FUN_00aae010_sub
{
    int unk00;
    FUN_00826660_cls** unk04;
    unsigned short unk08;
    unsigned short unk0A;
};

struct FUN_00aae010_arg
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
    FUN_00aa91e0_cls* m_pThing;
};

struct FUN_00aae010_cls
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
    FUN_00aae010_sub m_sub;
    unsigned short m_uFlag;
    unsigned short unkAA;
    FUN_00aa91e0_cls* m_pEntryObject;

    void FUN_00aae010(FUN_00aae010_arg* pObj);
};

// @fnv 0x00c4f6d0
// pdb: BSPortalSharedNode::OnVisible | BSPortal.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: NiSwitchNode::OnVisible)
// pdb params: kCuller
void FUN_00aae010_cls::FUN_00aae010(FUN_00aae010_arg* pObj)
{
    FUN_00aae010_sub* tgtC;
    FUN_00aae010_arg* subB = 0;
    FUN_00aa91e0_cls* savA;
    FUN_00aa91e0_cls* pSwapE;
    unsigned int cntB;
    unsigned int idxD;
    FUN_00826660_cls** pSlotE;
    FUN_00826660_cls* pElemA;
    if (m_uFlag == 0)
    {
    }
    else
    {
        subB = pObj;
        savA = subB->m_pThing;
        pSwapE = m_pEntryObject;
        subB->m_pThing = pSwapE;
        if (m_pEntryObject != 0)
        {
            m_pEntryObject->FUN_00aa91e0();
        }
        tgtC = &this->m_sub;
        cntB = tgtC->unk0A;
        for (idxD = 0; idxD < cntB; idxD++)
        {
            pSlotE = &tgtC->unk04[idxD];
            pElemA = *pSlotE;
            if (pElemA != 0)
            {
                pElemA->FUN_00826660(pObj);
            }
        }
        subB->m_pThing = savA;
    }
}

}   // namespace f3m_00aae010

// @f3 0x00aaa2c0 (community match, verified in this file)
namespace f3m_00aaa2c0 {
namespace Task2641 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*,unsigned int);
struct FUN_00aaa070 {
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
FUN_00aaa070();
static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
static void operator delete(void* p,unsigned int n) { FUN_0089ec10(p,n); }
};
// pdb: BSMultiBoundNode::CreateObject | BSMultiBoundNode.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: BSMultiBoundNode::RegisterStreamables)
FUN_00aaa070* FUN_00aaa2c0() { return new FUN_00aaa070; }
}
}   // namespace f3m_00aaa2c0

// @f3 0x00ab08a0 (community match, verified in this file)
namespace task2636 {
void* FUN_0089eb90(unsigned);
struct FixedString {const char* text;};
extern FixedString DAT_0108f3fc;
struct FUN_00ab07b0 {
int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
FUN_00ab07b0();
static void* operator new(unsigned n){return FUN_0089eb90(n);}
static void operator delete(void*);
void FUN_008245d0(const FixedString&);
};
// pdb: BSFurnitureMarker::CreateObject | BSFurnitureMarker.obj | fnv360_0822_retail, objrun, medium
FUN_00ab07b0* FUN_00ab08a0(){FUN_00ab07b0* object=new FUN_00ab07b0;object->FUN_008245d0(DAT_0108f3fc);return object;}
}

// @f3 0x00aa7ab0 (community match, verified in this file)
namespace f3m_00aa7ab0 {
namespace Task2623 {
void* __cdecl FUN_00c01530(void*,const void*,unsigned int);
struct Copier {void FUN_00aa7ab0(char*,char*,unsigned int);};
// @fnv 0x006dbf20
// pdb: BSSimpleArray<NiFrustumPlanes,1024>::_MoveItems | BSCompoundFrustum.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apDestAddr, apSrcAddr, aiCount
void __thiscall Copier::FUN_00aa7ab0(char* dst, char* src, unsigned int count)
{
    if (!(count > 0))
    {
    }
    else
    {
        if ((unsigned int)dst < (unsigned int)src)
        {
            for (unsigned int i = 0; i < count; ++i)
                FUN_00c01530(dst + i * 0x64, src + i * 0x64, 0x64);
        }
        else if ((unsigned int)dst > (unsigned int)src)
        {
            for (int i = (int)count - 1; i >= 0; --i)
                FUN_00c01530(dst + i * 0x64, src + i * 0x64, 0x64);
        }
    }
}

}
}   // namespace f3m_00aa7ab0

// @f3 0x00ab0350 (community match, verified in this file)
namespace f3m_00ab0350 {
namespace task2632 {
struct Heap {void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct Array {void*data;virtual ~Array(){DAT_01090a78.FUN_0086ba60(data);}};
struct FUN_00845a20 {unsigned unk04,unk08;virtual void vfn();~FUN_00845a20();};
struct FUN_00ab0350:FUN_00845a20 {Array items;~FUN_00ab0350();};
// pdb: BSFurnitureMarker::~BSFurnitureMarker | BSFurnitureMarker.obj | fnv360_0822_debug, call_seq, medium
FUN_00ab0350::~FUN_00ab0350(){}
}
}   // namespace f3m_00ab0350

// @f3 0x00aa5e70 (community match, verified in this file)
namespace task2653 {
void FUN_00aa5d10();
extern unsigned char DAT_01066650,DAT_01066651,DAT_01066652,DAT_01066653;
typedef void*(__cdecl* Callback)(void*,void*,unsigned);
extern Callback DAT_0116d6ac;
extern unsigned char DAT_01090bbc[24];
extern unsigned DAT_0116d6c4,DAT_01090bd4;
// pdb: GetLocalTime | getlocaltime.obj | fnv360_0721_retail, objrun_prop, low, conflict (bridge: XSetFileCacheSize)
// pdb params: lpLocalTime
void FUN_00aa5e70(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned e){
FUN_00aa5d10();DAT_01066650=a;DAT_01066651=b;DAT_01066652=c;DAT_01066653=d;DAT_0116d6ac=reinterpret_cast<Callback>(e);
for(int i=0;i<24;i++) DAT_01090bbc[i]=0;
DAT_01090bd4=DAT_0116d6c4;
}
}

// @f3 0x00aa4920 (community match, verified in this file)
namespace f3m_00aa4920 {
namespace task2645 {
class OwnedHelper
{
public:
    virtual ~OwnedHelper();
};

class FUN_00aa4800
{
public:
    virtual ~FUN_00aa4800();
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

};

class FUN_00aa4920 : public FUN_00aa4800
{
public:
    virtual ~FUN_00aa4920();
    OwnedHelper* m_pkHelper;
};

// pdb: IOManager::~IOManager | IOManager.obj | fnv360_0822_debug, call_seq, high
FUN_00aa4920::~FUN_00aa4920()
{
    delete m_pkHelper;
}

}
}   // namespace f3m_00aa4920

// @f3 0x00ab8500 (community match, verified in this file)
namespace f3m_00ab8500 {
namespace Task2651 {
void __cdecl FUN_0089e890(void*);
struct Array {
 virtual ~Array() { FUN_0089e890(data); }
 void* data;
 int count, capacity;
};
struct FUN_00ac5e40 {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58;
 ~FUN_00ac5e40();
};
struct FUN_00ab8500 : FUN_00ac5e40 {
 Array array;
 ~FUN_00ab8500();
};
// pdb: BSPSysArrayEmitter::~BSPSysArrayEmitter | BSPSysArrayEmitter.obj | fnv360_0822_debug, call_seq, medium
FUN_00ab8500::~FUN_00ab8500() {}
}
}   // namespace f3m_00ab8500

// @f3 0x00aaa860 (community match, verified in this file)
namespace f3m_00aaa860 {
void* __cdecl FUN_0089eb90(unsigned int);
struct ModifierBase {
    virtual void v0();
    unsigned int unk04, unk08, order, unk10, unk14;
    ModifierBase();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
};
struct Modifier : ModifierBase {
    float amount;
    virtual void v0();
    Modifier() : amount(1.0f) { order=4000; }
};
Modifier* FUN_00aaa860() { return new Modifier; }
}   // namespace f3m_00aaa860

// @f3 0x00aaa710 (community match, verified in this file)
namespace f3m_00aaa710 {
namespace Factory2619 {
void* __cdecl FUN_0089eb90(unsigned);
struct FUN_00aaa070 {
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
 FUN_00aaa070();
 static void* operator new(unsigned n) { return FUN_0089eb90(n); }
};
struct Factory { void FUN_00aaa360(FUN_00aaa070*,void*); FUN_00aaa070* FUN_00aaa710(void*); };
// pdb: BSMultiBoundNode::CreateClone | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
FUN_00aaa070* Factory::FUN_00aaa710(void* arg) { FUN_00aaa070* obj=0; obj=new FUN_00aaa070(); FUN_00aaa360(obj,arg); return obj; }
}
}   // namespace f3m_00aaa710

// @f3 0x00aa68a0 (community match, verified in this file)
namespace f3m_00aa68a0 {
namespace Task2654 {
int __cdecl FUN_0089f1d0(unsigned int, unsigned int, unsigned int);
void __cdecl FUN_0089eb20(void*);
void __cdecl FUN_00c007fc(void*, unsigned int, unsigned int);

class SpawnedObject
{
  public:
    virtual int vfn_00(int);
};

class FUN_00aa68a0_cls
{
  public:
    void** m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    char m_e0[0x104];
    bool FUN_0082a090(unsigned int);
    bool FUN_00aa68a0(unsigned int, unsigned int);
};

// @fnv 0x00c3a8a0
// pdb: BSStream::Load | BSStream.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFileName, apFile
bool FUN_00aa68a0_cls::FUN_00aa68a0(unsigned int a1, unsigned int a2)
{
    if (a2 == 0)
    {
        a2 = FUN_0089f1d0(a1, 0, 0x2800);
    }
    bool result = false;
    if (a2 != 0)
    {
        void* e = &m_e0;
        FUN_00c007fc(e, 0x104, a1);
        FUN_0089eb20(&m_e0);
        result = FUN_0082a090(a2);
        SpawnedObject* p1 = (SpawnedObject*)a2;
        SpawnedObject* p2 = p1;
        (p2 != 0) ? p2->vfn_00(1) : 0;
    }
    return result;
}


}
}   // namespace f3m_00aa68a0

// @f3 0x00aa7cb0 (community match, verified in this file)
namespace task2655 {
struct NavEntryItem {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_60;
};

class NavAllocator {
public:
    int* ScrapHeap_Allocate(unsigned int size, unsigned int tag);
};

class NavHolder {
public:
    NavAllocator* FUN_0086bcb0();
};

extern NavHolder DAT_01090a78;
extern unsigned int DAT_00e27ed4;

class NavEntryOwner {
public:
    int unk00;
    int unk04;
    NavEntryItem* m_08;
    int unk0C;
    int m_10;
    int unk14, unk18, unk1C, unk20;
    int m_24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C;
    int m_90;

    int* BSCompoundFrustum_GetActivePlaneState();
};

// @fnv 0x00c49050
// pdb: BSCompoundFrustum::GetActivePlaneState | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
int* NavEntryOwner::BSCompoundFrustum_GetActivePlaneState() {
    NavAllocator* alloc7 = DAT_01090a78.FUN_0086bcb0();
    int count = this->m_10;
    int* result5 = alloc7->ScrapHeap_Allocate(count * 4, DAT_00e27ed4);
    int firstB = this->m_90;
    result5[0] = firstB;
    int i6;
    int limit;
    NavEntryItem* item;
    int value7;
    for (i6 = 1; i6 < this->m_24 + 1 && i6 < (limit = this->m_10); i6++) {
        item = this->m_08 + (i6 - 1);
        value7 = item->m_60;
        result5[i6] = value7;
    }
    return result5;
}

}

// @f3 0x00aa67b0 (community match, verified in this file)
namespace f3m_00aa67b0 {
namespace task2674 {
struct FUN_00825800 {virtual void v0();virtual void DeleteThis();long refs;FUN_00825800();void FUN_00825830();~FUN_00825800(){FUN_00825830();}};
struct FUN_00aa67b0: FUN_00825800 {void* member;FUN_00aa67b0(void*);virtual void v0();void BSReference_SetName(void*);};
// pdb: BSReference::BSReference | BSStream.obj | fnv360_0822_retail, call_dedup, medium, conflict (bridge: BSReference::SetName)
// pdb params: apName
FUN_00aa67b0::FUN_00aa67b0(void* p){member=0;BSReference_SetName(p);}
}

}   // namespace f3m_00aa67b0

// @f3 0x00ab54f0 (community match, verified in this file)
namespace f3m_00ab54f0 {
namespace Geometry2633 {
struct FUN_0083f490 { virtual ~FUN_0083f490();
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
 unsigned unkb8;
 unsigned unkbc;
 unsigned unkc0;
 FUN_0083f490(unsigned short a, void* b, void* c, void* d, void* e, unsigned short f, unsigned g, unsigned short h, unsigned short* i);
};
struct FUN_00ab54f0 : FUN_0083f490 {
 int left,top,right,bottom;
 virtual ~FUN_00ab54f0();
 FUN_00ab54f0(unsigned short a, void* b, void* c, void* d, void* e, unsigned short f, unsigned g, unsigned short h, unsigned short* i,int j,int k,int l,int m);
};
// pdb: BSScissorTriShape::BSScissorTriShape | BSScissorTriShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: usVertices, pkVertex, pkNormal, pkColor, pkTexture, usNumTextureSets, eNBTMethod, usTriangles, pusTriList, aiLeft, aiTop, aiRight, aiBottom
FUN_00ab54f0::FUN_00ab54f0(unsigned short a, void* b, void* c, void* d, void* e, unsigned short f, unsigned g, unsigned short h, unsigned short* i,int j,int k,int l,int m) : FUN_0083f490(a,b,c,d,e,f,g,h,i) { left=j;top=k;right=l;bottom=m; }
}

}   // namespace f3m_00ab54f0

// @f3 0x00aab240 (community match, verified in this file)
namespace f3m_00aab240 {
namespace Worker2672 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00aa9840 {
    virtual void Slot00();
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
    FUN_00aa9840();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
};
struct Object : FUN_00aa9840 {
    Object() {}
    virtual void Slot00();
};
// pdb: BSDamageStage::CreateObject | BSDamageStage1.obj | fnv360_0822_retail, caller_sim, medium
Object* FUN_00aab240() { return new Object; }
}
}   // namespace f3m_00aab240

// @f3 0x00aa1fe0 (community match, verified in this file)
namespace f3m_00aa1fe0 {
namespace task2664 {
struct FUN_00c39c80_obj
{
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
    virtual int v94(int a);
    virtual int v98(int a);
};
struct FUN_00c39c80_holder
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00c39c80_obj* m_0c;
    FUN_00c39c80_obj* GetObj()
    {
        FUN_00c39c80_obj* a = m_0c;
        return a;
    }
};
struct FUN_00c39c80_node
{
    FUN_00c39c80_node* m_00;
    int unk04;
    FUN_00c39c80_holder* m_08;
};
inline FUN_00c39c80_holder* const& GetNext(FUN_00c39c80_node*& pos)
{
    FUN_00c39c80_holder* const& e = pos->m_08;
    pos = pos->m_00;
    return e;
}
struct FUN_00c39c80_cls
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
    FUN_00c39c80_holder* m_ac;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    FUN_00c39c80_node* m_d0;
    int unkD4;
    int m_d8;
    FUN_00c39c80_node* GetHead()
    {
        FUN_00c39c80_node* first = m_d0;
        return first;
    }
    int FUN_00aa1fe0(int a1);
};

// @fnv 0x00c39c80
// pdb: BSMultiBoundRoom::CheckBound | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aTargetBound
int FUN_00c39c80_cls::FUN_00aa1fe0(int a1)
{
    int res;
    FUN_00c39c80_node* cur;
    FUN_00c39c80_holder* group;
    int r2;
    FUN_00c39c80_holder* owner;
    owner = m_ac;
    res = owner->GetObj()->v98(a1);
    if (res != 1 && !(bool)(int)(m_d8 == 0))
    {
        cur = GetHead();
        while (res != 1 && cur != 0)
        {
            group = GetNext(cur);
            r2 = group->GetObj()->v98(a1);
            if (r2 != 0)
            {
                res = r2;
            }
        }
    }
    return res;
}
}
}   // namespace f3m_00aa1fe0

// @f3 0x00aad720 (community match, verified in this file)
namespace f3m_00aad720 {
namespace task2677 {
void*__cdecl FUN_0089eb90(unsigned);
struct FUN_00aad5f0{virtual ~FUN_00aad5f0();unsigned unk04,unk08,unk0c,unk10,unk14,unk18;FUN_00aad5f0();};
struct Derived:FUN_00aad5f0{virtual ~Derived();static void*operator new(unsigned n){return FUN_0089eb90(n);}static void operator delete(void*);};
// pdb: BSMultiBoundSphere::CreateObject | BSMultiBoundSphere.obj | fnv360_0822_retail, objrun, medium
FUN_00aad5f0*__cdecl FUN_00aad720(){return new Derived();}
}
}   // namespace f3m_00aad720

// @f3 0x00aa6820 (community match, verified in this file)
namespace f3m_00aa6820 {
namespace Task2675 {
struct FUN_00825830 { virtual ~FUN_00825830(); };
struct FUN_00aa6820 : FUN_00825830 {
 virtual ~FUN_00aa6820();
 void BSReference_SetName(bool);
};
// pdb: BSReference::`scalar deleting destructor' | BSStream.obj | fnv360_0721_beta, objrun, low, conflict (skyrim: BSReference::~BSReference)
FUN_00aa6820::~FUN_00aa6820() { BSReference_SetName(false); }
}
}   // namespace f3m_00aa6820

// @f3 0x00aaaf70 (community match, verified in this file)
namespace f3m_00aaaf70 {
namespace task2670 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00aa9840 {
 virtual void slot0();
 unsigned int field004;
 unsigned int field008;
 unsigned int field00c;
 unsigned int field010;
 unsigned int field014;
 unsigned int field018;
 unsigned int field01c;
 unsigned int field020;
 unsigned int field024;
 unsigned int field028;
 unsigned int field02c;
 unsigned int field030;
 unsigned int field034;
 unsigned int field038;
 unsigned int field03c;
 unsigned int field040;
 unsigned int field044;
 unsigned int field048;
 unsigned int field04c;
 unsigned int field050;
 unsigned int field054;
 unsigned int field058;
 unsigned int field05c;
 unsigned int field060;
 unsigned int field064;
 unsigned int field068;
 unsigned int field06c;
 unsigned int field070;
 unsigned int field074;
 unsigned int field078;
 unsigned int field07c;
 unsigned int field080;
 unsigned int field084;
 unsigned int field088;
 unsigned int field08c;
 unsigned int field090;
 unsigned int field094;
 unsigned int field098;
 unsigned int field09c;
 unsigned int field0a0;
 unsigned int field0a4;
 unsigned int field0a8;
 unsigned int field0ac;
 FUN_00aa9840();
};
struct Object : FUN_00aa9840 {
 virtual void slot0();
 static void* operator new(unsigned int n) {return FUN_0089eb90(n);}
 Object() {}
};
// pdb: BSBlastNode::CopyMembers | BSBlastNode.obj | fnv360_0822_debug, objrun, low, conflict (bridge: BSBlastNode::CreateObject)
// pdb params: pDest, arCloneData
Object* FUN_00aaaf70() {return new Object;}
}
}   // namespace f3m_00aaaf70

// @f3 0x00ab5f10 (community match, verified in this file)
namespace f3m_00ab5f10 {
namespace Task2679 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00ac5e10
{
    FUN_00ac5e10();
    virtual void vf0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
};
struct S_00c4aca0_Obj : FUN_00ac5e10
{
    S_00c4aca0_Obj()
    {}
    virtual void vf0();
};
// pdb: BSPSysStripUpdateModifier::CreateObject | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, objrun, medium
S_00c4aca0_Obj* FUN_00ab5f10() { return new S_00c4aca0_Obj; }
}
}   // namespace f3m_00ab5f10

// @f3 0x00ab7870 (community match, verified in this file)
namespace f3m_00ab7870 {
struct UpdateOwner {
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
    unsigned short m_b8;
    unsigned short unkBA;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    float m_dc;

    void BSMasterParticleSystem_ClearUnreferencedEmitters();
    unsigned char BSMasterParticleSystem_ChildHasActiveParticles();
    void FUN_0082dcf0(float* f, int b);
    void BSMasterParticleSystem_UpdateSelectedDownwardPass(float* f, int b);
};
// @fnv 0x00c5e450
// pdb: BSMasterParticleSystem::UpdateSelectedDownwardPass | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void UpdateOwner::BSMasterParticleSystem_UpdateSelectedDownwardPass(float* pfValue, int b)
{
    float saved;
    int a0;
    int a1;
    int a2;
    int a3;
    BSMasterParticleSystem_ClearUnreferencedEmitters();
    if (m_b8 > 0 || BSMasterParticleSystem_ChildHasActiveParticles())
    {
        m_dc += *pfValue;
        saved = *pfValue;
        *pfValue = m_dc;
        FUN_0082dcf0(pfValue, b);
        *pfValue = saved;
    }
}
}   // namespace f3m_00ab7870

// @f3 0x00aa0c00 (community match, verified in this file)
namespace f3m_00aa0c00 {
namespace task2676 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00aad5f0 {
 virtual void slot0();
 unsigned int field004;
 unsigned int field008;
 unsigned int field00c;
 unsigned int field010;
 unsigned int field014;
 unsigned int field018;
 unsigned int field01c;
 unsigned int field020;
 FUN_00aad5f0();
};
struct Object : FUN_00aad5f0 {
 virtual void slot0();
 static void* operator new(unsigned int n) {return FUN_0089eb90(n);}
 Object() {}
};
Object* FUN_00aa0c00() {return new Object;}
}
}   // namespace f3m_00aa0c00

// @f3 0x00ab78d0 (community match, verified in this file)
namespace f3m_00ab78d0 {
namespace task2689 {
struct FUN_00ab78d0_cls {
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
    unsigned short m_b8;
    unsigned short unkBA;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    float m_dc;

    void BSMasterParticleSystem_ClearUnreferencedEmitters();
    unsigned char BSMasterParticleSystem_ChildHasActiveParticles();
    void FUN_0082e030(float* f, int b);
    void BSMasterParticleSystem_UpdateRigidDownwardPass(float* f, int b);
};

// Calls BSMasterParticleSystem_ClearUnreferencedEmitters, then if m_b8 > 0 or BSMasterParticleSystem_ChildHasActiveParticles() is true, adds *f to m_dc, passes the sum to FUN_0082e030, and restores *f.
// @fnv 0x00c5e450
// pdb: BSMasterParticleSystem::UpdateRigidDownwardPass | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(objrun_prop), high
void FUN_00ab78d0_cls::BSMasterParticleSystem_UpdateRigidDownwardPass(float* pfValue, int b)
{
    float saved;
    BSMasterParticleSystem_ClearUnreferencedEmitters();
    if (m_b8 > 0 || BSMasterParticleSystem_ChildHasActiveParticles())
    {
        m_dc += *pfValue;
        saved = *pfValue;
        *pfValue = m_dc;
        FUN_0082e030(pfValue, b);
        *pfValue = saved;
    }
}

}
}   // namespace f3m_00ab78d0

// @f3 0x00aabca0 (community match, verified in this file)
namespace f3m_00aabca0 {
namespace f3_2710 {
struct Node { virtual void v0(); virtual void v1(); virtual void v2(); virtual Node* GetNode();
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
unsigned int flags;
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
Node** children; unsigned short capacity,count;
};
// @fnv 0x00c4b500
// pdb: BSUtilities::ProcessSelectiveUpdate | BSUtilities.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apObject
void FUN_00aabca0(Node* apNode)
{
    if (apNode) {
                if (1) apNode->flags |= 2; else apNode->flags &= ~(unsigned)(apNode, 2);
                if (1) apNode->flags |= 4; else apNode->flags &= ~(unsigned)(apNode, 4);
                if (0) apNode->flags |= 0x10; else apNode->flags &= ~(unsigned)(apNode, 0x10);
        Node* g = apNode->GetNode();
        if (g) {
            for (unsigned i = 0; i < g->count; i++) {
                Node** p = &g->children[i];
                Node* pChildNode = *p;
                FUN_00aabca0(pChildNode);
            }
        }
    }
}

}
}   // namespace f3m_00aabca0

// @f3 0x00aaa1d0 (community match, verified in this file)
namespace f3m_00aaa1d0 {
namespace Task2694 {
struct NiStream; struct NiObject;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiObjectHelper
{
    virtual void FUN_0082e780(NiStream&);
};
struct NiStreamHelper
{
    NiObject* FUN_0082a280();
};
struct NiPalette
{
    virtual ~NiPalette();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct NiPersistentSrcTextureRendererData
{
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8;
    NiPalette* m_spPalette;
    void FUN_00aaa1d0(NiStream&);
};
// Links the object to the stream, then swaps m_spPalette to the stream's palette, releasing the old one and incrementing the new one's refcount.
// @fnv 0x00a98110
// pdb: BSMultiBoundNode::LinkObject | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void NiPersistentSrcTextureRendererData::FUN_00aaa1d0(NiStream& kStream)
{
    ((NiObjectHelper*)this)->NiObjectHelper::FUN_0082e780(kStream);
    NiPalette* pkPalette = (NiPalette*)((NiStreamHelper*)&kStream)->FUN_0082a280();
    NiPalette* pkOld = m_spPalette;
    if (pkOld != pkPalette)
    {
        if (pkOld && InterlockedDecrement((long volatile*)&pkOld->m_iObjectReferenceCount) == 0)
            pkOld->DeleteThis();
        m_spPalette = pkPalette;
        if (pkPalette)
            InterlockedIncrement((long volatile*)&pkPalette->m_iObjectReferenceCount);
    }
}
}
}   // namespace f3m_00aaa1d0

// @f3 0x00aa2040 (community match, verified in this file)
namespace f3m_00aa2040 {
struct FUN_00aa2040_obj
{
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
    virtual int v94(int a);
    virtual int v98(int a);
};
struct FUN_00aa2040_holder
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00aa2040_obj* m_0c;
    FUN_00aa2040_obj* GetObj()
    {
        FUN_00aa2040_obj* a = m_0c;
        return a;
    }
};
struct FUN_00aa2040_node
{
    FUN_00aa2040_node* m_00;
    int unk04;
    FUN_00aa2040_holder* m_08;
};
inline FUN_00aa2040_holder* const& GetNext(FUN_00aa2040_node*& pos)
{
    FUN_00aa2040_holder* const& e = pos->m_08;
    pos = pos->m_00;
    return e;
}
struct FUN_00aa2040_cls
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
    FUN_00aa2040_holder* m_ac;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    FUN_00aa2040_node* m_d0;
    int unkD4;
    int m_d8;
    FUN_00aa2040_node* GetHead()
    {
        FUN_00aa2040_node* first = m_d0;
        return first;
    }
    int FUN_00aa2040(int a1);
};

// @fnv 0x00c39c80
// pdb: BSMultiBoundRoom::CheckBound | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aTargetBound
int FUN_00aa2040_cls::FUN_00aa2040(int a1)
{
    int res;
    FUN_00aa2040_node* cur;
    FUN_00aa2040_holder* group;
    int r2;
    FUN_00aa2040_holder* owner;
    owner = m_ac;
    res = owner->GetObj()->v94(a1);
    if (res != 1 && !(bool)(int)(m_d8 == 0))
    {
        cur = GetHead();
        while (res != 1 && cur != 0)
        {
            group = GetNext(cur);
            r2 = group->GetObj()->v94(a1);
            if (r2 != 0)
            {
                res = r2;
            }
        }
    }
    return res;
}

}   // namespace f3m_00aa2040

// @f3 0x00aaee20 (community match, verified in this file)
namespace f3m_00aaee20 {
namespace task2708 {
struct CameraViewportC52
{
    float left, right, top, bottom;
    inline CameraViewportC52()
    {}
    inline CameraViewportC52(float x0, float x1, float y1, float y0) : left(x0), right(x1), top(y1), bottom(y0)
    {}
};
struct C52020Obj
{
    virtual void vfn_00();
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
    CameraViewportC52 viewport;
};
struct C52520Camera
{
    virtual void vfn_00();
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
    C52020Obj* m_ac;
    int unkb0;
    int unkb4;
    unsigned char m_b8;
    float m_bc;
    inline C52020Obj* GetObj() const
    {
        return m_ac;
    }
    void FUN_00aaeaf0(float m_fFirstFloat, unsigned char ucFlag, C52020Obj* pObj, unsigned char ucArg4);
    void FUN_00aaee20();
};
// @fnv 0x00c52520
void C52520Camera::FUN_00aaee20()
{
    CameraViewportC52 port(0.0f, 1.0f, 1.0f, 0.0f);
    GetObj()->viewport = port;
    FUN_00aaeaf0(m_bc, 1, 0, 0);
}
}
}   // namespace f3m_00aaee20

// @f3 0x00aab0e0 (community match, verified in this file)
namespace f3m_00aab0e0 {
void* __cdecl FUN_0089eb90(unsigned);
struct FUN_00aa9840 {
 virtual ~FUN_00aa9840();
 FUN_00aa9840();
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
};
struct DAT_00e8a35c : FUN_00aa9840 {
 DAT_00e8a35c() {}
 static void* operator new(unsigned n) throw() { return FUN_0089eb90(n); }
};
// pdb: BSDebrisNode::CopyMembers | BSDebrisNode.obj | fnv360_0822_debug, objrun, low, conflict (bridge: BSDebrisNode::CreateObject)
// pdb params: pDest, arCloneData
DAT_00e8a35c* __cdecl FUN_00aab0e0() { return new DAT_00e8a35c(); }
}   // namespace f3m_00aab0e0

// @f3 0x00aa2430 (community match, verified in this file)
namespace f3_2734 {
struct StrArr
{
    unsigned field0, field4;
    unsigned short m8;
    unsigned short mA;
    unsigned short fieldC;
    unsigned short mE;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
void __stdcall FUN_00aaa790(StrArr*);
char* FUN_00847b50(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 DAT_0116d12c;
// @fnv 0x00bc28f0
// pdb: BSMultiBoundRoom::GetViewerStrings | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: pStrings
void __stdcall FUN_00aa2430(StrArr* pStrArr)
{
    FUN_00aaa790(pStrArr);
    char* pStr = FUN_00847b50(DAT_0116d12c.f0);
    unsigned int uiIndex = pStrArr->mA;
    unsigned int cnt = pStrArr->m8;
    if (uiIndex >= cnt)
    {
        pStrArr->FUN_00555790(pStrArr->mE + uiIndex);
    }
    pStrArr->FUN_005b3880(uiIndex, pStr);
}

}

// @f3 0x00aab440 (community match, verified in this file)
namespace lookup2719 {
struct RTTI { const char* name; const RTTI* base; };
extern RTTI DAT_01091f04;
struct Owner {
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
 virtual int v35(void**);
 virtual void v36();
 virtual void v37();
 virtual void v38();
 virtual int v39(void**);
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
 Owner* unk78;
 Owner* FUN_00825200(const RTTI*);
};
// @fnv 0x00c4b470
// pdb: BSUtilities::GetObjectByName | BSUtilities.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apScene, apName, bTestScenegraph
int __cdecl FUN_00aab440(Owner* pOwner, void** a2, unsigned char bFallback)
{
    Owner* node7;
    int r7;
    void* cur;
    Owner* m78;
    Owner* obj;
    if (pOwner == 0 || (cur = *a2) == 0) {
        return 0;
    }
    node7 = pOwner->FUN_00825200(&DAT_01091f04);
    if (node7 != 0) {
        m78 = node7->unk78;
        obj = m78;
        r7 = obj->v35(a2);
        if (r7 != 0) {
            return r7;
        }
    }
    if (bFallback != 0) {
        return pOwner->v39(a2);
    }
    return 0;
}

}

// @f3 0x00aaac90 (community match, verified in this file)
namespace f3_00aaac90 {
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct FUN_00424aa0 {
    void* object;
    ~FUN_00424aa0();
    static void operator delete[](void* allocation) { DAT_01090a78.FUN_0086ba60(allocation); }
};
struct BufferOwner {
    FUN_00424aa0* elements;
    virtual ~BufferOwner() { delete[] elements; }
    void* FUN_00aaac90(unsigned char flags);
};
// pdb: NiTArray<NiPointer<NiRefObject>,NiTNewInterface<NiPointer<NiRefObject> > >::`scalar deleting destructor' | NiObjectGarbage.obj | fnv360_0822_retail, vtable, high
void* BufferOwner::FUN_00aaac90(unsigned char flags)
{
    this->BufferOwner::~BufferOwner();
    if (flags & 1)
        DAT_01090a78.FUN_0086ba60(this);
    return this;
}
}

// @f3 0x00ab6f30 (community match, verified in this file)
namespace f3m_00ab6f30 {
namespace stream2725 {
struct Stream;
struct Child {
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
 virtual bool RegisterStreamables(Stream&);
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
 Child** children;
 unsigned short capacity,count;
 bool FUN_0082e410(Stream&);
 bool FUN_00ab6f30(Stream&);
};
// pdb: BSMasterParticleSystem::RegisterStreamables | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
bool Node::FUN_00ab6f30(Stream& stream) {
 if(!FUN_0082e410(stream)) return false;
 for(unsigned int i=0;i<count;++i) {
  Child* c=children[i];
  if(c) c->RegisterStreamables(stream);
 }
 return true;
}
}
}   // namespace f3m_00ab6f30

// @f3 0x00aa98d0 (community match, verified in this file)
namespace task2714 {
typedef void (__cdecl *Callback)(void*, bool);
extern Callback DAT_0116d708;
struct Node {
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
unsigned int flags;
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
unsigned short unkac;
unsigned char low, high;
void SetBit(bool b, unsigned m) { if(b) flags |= m; else flags &= ~m; }
bool IsHidden() { return (flags & 1)!=0; }
unsigned char GetLow() { unsigned char c=low; return c; }
unsigned char GetHigh() { unsigned char c=high; return c; }
bool BSRangeNode_SetCurrent(unsigned char);
};
// pdb: BSRangeNode::SetCurrent | BSRangeNode.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
bool Node::BSRangeNode_SetCurrent(unsigned char level) {
 bool bNew; bool bOld=!IsHidden();
 bNew=level>=GetLow() && level<=GetHigh();
 if(bOld!=bNew) { SetBit(!bNew,1); if(DAT_0116d708) DAT_0116d708(this,bNew); }
 return bNew;
}
}

// @f3 0x00ab0140 (community match, verified in this file)
namespace f3m_00ab0140 {
namespace Task2724 {
struct FUN_00ab0140_cls {
 float m_00,m_04,m_08;
 unsigned short m_0c;unsigned char m_0e;
 bool FUN_00ab0140(FUN_00ab0140_cls*);
};
// @fnv 0x00c54cc0
// pdb: FurnitureMark::LoadBinary | BSFurnitureMarker.obj | fnv360_0822_debug, objrun, low
// pdb params: arStream
bool FUN_00ab0140_cls::FUN_00ab0140(FUN_00ab0140_cls* other)
{
    return (bool)(((m_00 == other->m_00) && (m_04 == other->m_04) && (m_08 == other->m_08)) ? 1 : 0) &&
           (m_0e == other->m_0e) && (m_0c == other->m_0c);
}

}
}   // namespace f3m_00ab0140

// @f3 0x00aa1e50 (community match, verified in this file)
extern void (__stdcall* DAT_00e894a8)(void*);
namespace Task2757 {
struct Memory { void FUN_0086ba60(void*); };
extern Memory DAT_01090a78;
struct SsArr {
 virtual ~SsArr() {
  if(data) {
   DAT_00e894a8(data);
   data=0;
   b=0;
   a=0;
  }
 }
 void* data;
 int a,b;
};
// pdb: BSSimpleArray<ShadowSceneLight *,1024>::`scalar deleting destructor' | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable, medium
SsArr* __fastcall FUN_00aa1e50(SsArr* p,int,unsigned flags) {
 p->SsArr::~SsArr();
 if(flags&1) DAT_01090a78.FUN_0086ba60(p);
 return p;
}
}

// @f3 0x00ab98d0 (community match, verified in this file)
namespace append2736 {
struct StrArr
{
    unsigned field0, field4;
    unsigned short m8;
    unsigned short mA;
    unsigned short fieldC;
    unsigned short mE;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
void __stdcall FUN_00863fe0(StrArr*);
char* FUN_00847b50(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 DAT_0108f200;
// @fnv 0x00bc28f0
// pdb: BSDecalPlacementVectorExtraData::GetViewerStrings | BSDecalPVExtraData.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void __stdcall FUN_00ab98d0(StrArr* pStrArr)
{
    FUN_00863fe0(pStrArr);
    char* pStr = FUN_00847b50(DAT_0108f200.f0);
    unsigned int uiIndex = pStrArr->mA;
    unsigned int cnt = pStrArr->m8;
    if (uiIndex >= cnt)
    {
        pStrArr->FUN_00555790(pStrArr->mE + uiIndex);
    }
    pStrArr->FUN_005b3880(uiIndex, pStr);
}

}

// @f3 0x00aa5bb0 (community match, verified in this file)
namespace f3m_00aa5bb0 {
namespace task2699 {
struct Heap { void FUN_0086ba60(void*); }; extern Heap DAT_01090a78;
struct Array {
 virtual __forceinline ~Array() { RemoveAll(); }
 __forceinline void RemoveAll() {
  if(data) {
   FUN_00aa5720(data,size);
   Free(data);
   data=0; capacity=0; size=0;
  }
 }
 virtual void v04();
 virtual void Free(void*);
 void* data; unsigned size,capacity;
 void FUN_00aa5720(void*,unsigned);
 Array* FUN_00aa5bb0(unsigned char flags);
};
// pdb: BSSimpleArray<NiPointer<QueuedFile>,1024>::~BSSimpleArray<NiPointer<QueuedFile>,1024> | QueuedFiles.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: MessageHandler::RemoveAssertHandler)
Array* Array::FUN_00aa5bb0(unsigned char flags) {
 this->Array::~Array();
 if(flags & 1) DAT_01090a78.FUN_0086ba60(this);
 return this;
}
}

}   // namespace f3m_00aa5bb0

// @f3 0x00aa9880 (community match, verified in this file)
namespace f3m_00aa9880 {
namespace Task2735 {
struct S_00aa9880_Obj {
 int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38,unk3C,unk40,unk44,unk48,unk4C,unk50,unk54,unk58,unk5C,unk60,unk64,unk68,unk6C,unk70,unk74,unk78,unk7C,unk80,unk84,unk88,unk8C,unk90,unk94,unk98,unk9C,unkA0,unkA4,unkA8;
 unsigned char unkAC,unkAD,unkAE,unkAF;
 bool FUN_0082e460(S_00aa9880_Obj*);
 char FUN_00aa9880(S_00aa9880_Obj*);
};
// @fnv 0x00aa9880
// pdb: BSRangeNode::IsEqual | BSRangeNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
char S_00aa9880_Obj::FUN_00aa9880(S_00aa9880_Obj* other) {
    bool r7 = FUN_0082e460(other);
    if (r7) {
        S_00aa9880_Obj* oB = other;
        unsigned char a8, b, c5, d, e, f7;
        r7 = ((a8 = unkAE, b = oB->unkAE, a8 == b) && (c5 = unkAF, d = oB->unkAF, c5 == d) && (e = unkAD, f7 = oB->unkAD, e == f7)) ? 1 : 0;
    }
    return r7;
}

}
}   // namespace f3m_00aa9880

// @f3 0x00ab70d0 (community match, verified in this file)
namespace f3m_00ab70d0 {
namespace Task2741 {
struct EB90Sub
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
    virtual unsigned short GetFlags();
};

struct EB90Item
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;
    EB90Sub* m_pSub;
};

struct EB90Obj
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    EB90Item** m_ppItems;
    unsigned short unkD4;
    unsigned short m_usElementCount;

    bool BSMasterParticleSystem_ChildHasActiveParticles();
};

// @fnv 0x00c5eb90
// pdb: BSMasterParticleSystem::ChildHasActiveParticles | BSMasterParticleSystem.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
bool EB90Obj::BSMasterParticleSystem_ChildHasActiveParticles()
{
    unsigned int count = m_usElementCount;
    for (unsigned int i = 0; i < count; i++)
    {
        EB90Item* item3 = m_ppItems[i];
        if (item3)
            if ((int)item3->m_pSub->GetFlags() > 0)
                return true;
    }
    return false;
}

}
}   // namespace f3m_00ab70d0

// @f3 0x00ab9cb0 (community match, verified in this file)
namespace f3m_00ab9cb0 {
struct S_00ab9cb0_Map
{
    bool FUN_00bea7b0(unsigned int, void**);
};

struct S_00ab9cb0_Stream
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
    virtual void v28(void* apObject);
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
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    S_00ab9cb0_Map* unk5c4;
    void FUN_0082bdd0(void** appString);
};

struct S_00ab9cb0_Base
{
    int unk00;
    int unk04;
    void* unk08;
    void FUN_00825ad0(S_00ab9cb0_Stream* apStream);
};

struct S_00ab9cb0 : S_00ab9cb0_Base
{
    void FUN_00ab9cb0(S_00ab9cb0_Stream* apStream);
};

// Calls FUN_00825ad0, reads unk08 from the stream, looks it up in the stream's map, and passes any found object to apStream->v28.
// @fnv 0x00ab9cb0
// pdb: BSReference::LoadBinary | BSReference.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void S_00ab9cb0::FUN_00ab9cb0(S_00ab9cb0_Stream* apStream)
{
    FUN_00825ad0(apStream);
    apStream->FUN_0082bdd0(&unk08);

    void* pObject;
    {
        S_00ab9cb0_Stream* pStream = apStream;
        unsigned int uiLinkID = (unsigned int)unk08;
        void* pFound = 0;
        if (pStream->unk5c4 && uiLinkID)
            pStream->unk5c4->FUN_00bea7b0(uiLinkID, &pFound);
        pObject = pFound;
    }
    if (pObject)
        apStream->v28(pObject);
    {
        int ReportDiagnostic;
        int unused1;
    }
}
}   // namespace f3m_00ab9cb0

// @f3 0x00aabd00 (community match, verified in this file)
namespace task2750 {
class NiRTTIC4BB
{
  public:
    const NiRTTIC4BB* GetBaseRTTI() const
    {
        return m_pBaseRTTI;
    }
    const char* m_pcName;
    const NiRTTIC4BB* m_pBaseRTTI;
};

extern const NiRTTIC4BB DAT_0108f20c;
class NiObjectC4BB
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const NiRTTIC4BB* GetRTTI() const;
};

inline bool IsKindOfC4BB(const NiRTTIC4BB* pkRTTI, const NiObjectC4BB* pkObject)
{
    const NiRTTIC4BB* pkTmp = pkObject->GetRTTI();
    while (pkTmp)
    {
        if (pkTmp == pkRTTI)
            return true;
        pkTmp = pkTmp->GetBaseRTTI();
    }
    return false;
}

class TargetC4BB : public NiObjectC4BB
{
  public:
    void* GetDataImpl() const
    {
        return m_pResource;
    }
    void* GetData() const
    {
        return GetDataImpl();
    }
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
    void* m_pResource;
};

inline TargetC4BB* DynamicCastC4BB(NiObjectC4BB* pkObject)
{
    return !pkObject ? 0 : (TargetC4BB*)(IsKindOfC4BB(&DAT_0108f20c, pkObject) ? pkObject : 0);
}

// @fnv 0x00c4bb40
// pdb: BSUtilities::GetTextureName | BSUtilities.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apTexture
void* __cdecl FUN_00aabd00(NiObjectC4BB* pkObject)
{
    void* pvData = 0;
    TargetC4BB* pkTarget;
    if (!pkObject)
        pkTarget = 0;
    else
        pkTarget = (TargetC4BB*)(IsKindOfC4BB(&DAT_0108f20c, pkObject) ? pkObject : 0);
    if (pkTarget)
        pvData = pkTarget->GetData();
    return pvData;
}

}

// @f3 0x00aa6fe0 (community match, verified in this file)
namespace f3m_00aa6fe0 {
namespace f3_2779 {
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
unsigned char flag; int p;
bool FUN_0082e460(Object*);
char FUN_00aa6fe0(Object*);
};
// pdb: BSValueNode::IsEqual | BSValueNode.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: NiSwitchNode::IsEqual)
// pdb params: apObject
char Object::FUN_00aa6fe0(Object* other) {
bool result=FUN_0082e460(other);
if(result) {
Object* local=other;
int selfValue=p;
int otherValue=local->p;
result=(selfValue==otherValue && flag==local->flag)?1:0;
}
return result;
}
}
}   // namespace f3m_00aa6fe0

// @f3 0x00aa8230 (community match, verified in this file)
namespace f3m_00aa8230 {
extern void (__stdcall *DAT_00e89ec4)(void*);
namespace task2759 {
struct MemoryManager { void FUN_0086ba60(void*); };
}
namespace task2759 { extern MemoryManager DAT_01090a78; }
struct SsArr2759 {
 virtual ~SsArr2759() {
  if (data) {
   DAT_00e89ec4(data);
   data = 0;
   capacity = 0;
   size = 0;
  }
 }
 void* data;
 unsigned int size;
 unsigned int capacity;
};
// pdb: BSSimpleArray<BSCompoundFrustum::FunctionOp,1024>::`scalar deleting destructor' | BSCompoundFrustum.obj | fnv360_0822_retail, vtable, medium
SsArr2759* __fastcall FUN_00aa8230(SsArr2759* object, int, unsigned int flags) {
 object->SsArr2759::~SsArr2759();
 if (flags & 1) task2759::DAT_01090a78.FUN_0086ba60(object);
 return object;
}




}   // namespace f3m_00aa8230

// @f3 0x00ab9fe0 (community match, verified in this file)
namespace f3m_00ab9fe0 {
namespace task2755 {
struct FUN_00c5f100_cls { int unk00,unk04,unk08,unk0c;void**m_ppItems;unsigned m_uiCount;bool FUN_00ab9fe0(FUN_00c5f100_cls*); };
// @fnv 0x00c5f100
// pdb: BSTextureData::IsEqual | BSTextureData.obj | fnv360_0822_retail, vtable, medium
// pdb params: pObject
bool FUN_00c5f100_cls::FUN_00ab9fe0(FUN_00c5f100_cls* other) {
    if (other == 0) {
        return false;
    }
    FUN_00c5f100_cls* rhs3 = other;
    unsigned int lhsCountB = m_uiCount;
    unsigned int rhsCount = rhs3->m_uiCount;
    if (lhsCountB != rhsCount) {
        return false;
    }
    unsigned int i;
    unsigned int n3;
    for (i = 0; i < (n3 = m_uiCount); i++) {
        void** item = &m_ppItems[i];
        if (*item != rhs3->m_ppItems[i]) {
            return false;
        }
    }
    return true;
}
}
}   // namespace f3m_00ab9fe0

// @f3 0x00aadaf0 (community match, verified in this file)
namespace f3m_00aadaf0 {
namespace Task2765 {
struct Buffer { int unk00;unsigned int position;int (__cdecl* read)(void*,void*,unsigned int,unsigned int*,int); };
struct Stream { int unk000,unk004,unk008,unk00c,unk010,unk014,unk018,unk01c,unk020,unk024,unk028,unk02c,unk030,unk034,unk038,unk03c,unk040,unk044,unk048,unk04c,unk050,unk054,unk058,unk05c,unk060,unk064,unk068,unk06c,unk070,unk074,unk078,unk07c,unk080,unk084,unk088,unk08c,unk090,unk094,unk098,unk09c,unk0a0,unk0a4,unk0a8,unk0ac,unk0b0,unk0b4,unk0b8,unk0bc,unk0c0,unk0c4,unk0c8,unk0cc,unk0d0,unk0d4,unk0d8,unk0dc,unk0e0,unk0e4,unk0e8,unk0ec,unk0f0,unk0f4,unk0f8,unk0fc,unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c,unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c,unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc,unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc,unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c,unk240,unk244,unk248; Buffer* buffer; };
struct Vector {float x,y,z;void FUN_00823eb0(Stream*);};
struct Object {
 int unk00,unk04,unk08;Vector vector;unsigned int value;
 void FUN_00c22010(Stream*);void FUN_00aadaf0(Stream*);
};
// pdb: BSMultiBoundSphere::LoadBinary | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: arStream
void Object::FUN_00aadaf0(Stream* stream) {
 FUN_00c22010(stream);
 vector.FUN_00823eb0(stream);
 Buffer* reader=stream->buffer;
 { unsigned int size=4;reader->position+=reader->read(reader,&value,4,&size,1); }
}
}
}   // namespace f3m_00aadaf0

// @f3 0x00abb860 (community match, verified in this file)
extern int DAT_011ae754;
extern int DAT_011ae758;
namespace f3m_00abb860 {


// pdb: NiPSysEmitterCtlr::GetInterpolatorID | NiPSysEmitterCtlr.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
int __stdcall NiPSysEmitterCtlr_GetInterpolatorID(short value)
{
    if (value == 0)
        return DAT_011ae754;
    return value == 1 ? DAT_011ae758 : 0;
}
}   // namespace f3m_00abb860

// @f3 0x00aadb40 (community match, verified in this file)
namespace f3m_00aadb40 {
namespace save2766 {
struct Writer {
 int unk00;
 unsigned int position;
 void* read;
 unsigned int (__cdecl *write)(Writer*,const void*,unsigned int,unsigned int*,unsigned int);
};
struct Stream {
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
 Writer* buffer;
};
struct Point { float x,y,z; void FUN_0083fa20(Stream*); };
struct Owner {
 int unk00,unk04,unk08;
 Point point;
 int value;
 void FUN_008cbd30(Stream*);
 void FUN_00aadb40(Stream*);
};
// pdb: BSMultiBoundSphere::SaveBinary | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: arStream
void Owner::FUN_00aadb40(Stream* stream) {
 FUN_008cbd30(stream);
 point.FUN_0083fa20(stream);
 Writer* writer=stream->buffer;
 { unsigned int stream=4;
 writer->position+=writer->write(writer,&value,4,&stream,1);
 }
}
}
}   // namespace f3m_00aadb40

// @f3 0x00aa5d90 (community match, verified in this file)
extern int DAT_01269f88;
namespace f3m_00aa5d90 {


// pdb: MessageHandler::SetWarningFileName | MessageHandler.obj | fnv360_0822_retail, udata, high
void __cdecl MessageHandler_SetWarningFileName(const char* text)
{
    strcpy_s((char*)&DAT_01269f88, 260, DAT_0116d880);
    strcat_s((char*)&DAT_01269f88, 260, text);
}
}   // namespace f3m_00aa5d90

// @f3 0x00ab9fa0 (community match, verified in this file)
namespace f3m_00ab9fa0 {
namespace task2774 {
class F010Item
{
  public:
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
    virtual void v54(void* a);
};
class F010Cls
{
  public:
    int m_00, m_04, m_08, m_0c;
    F010Item** m_10;
    unsigned int m_14;
    bool FUN_008459a0(void* a);
    unsigned int Count() const
    {
        return m_14;
    }
    F010Item*& Get(unsigned int i) const
    {
        return m_10[i];
    }
    bool FUN_00ab9fa0(void* a);
};
// @fnv 0x00c5f010
// pdb: BSTextureData::RegisterStreamables | BSTextureData.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
bool F010Cls::FUN_00ab9fa0(void* a)
{
    if (!FUN_008459a0(a))
        return false;

    for (unsigned int i = 0; i < Count(); ++i)
    {

        Get(i)->v54(a);
    }
    return true;
}
}
}   // namespace f3m_00ab9fa0

// @f3 0x00aa81e0 (community match, verified in this file)
extern void (__stdcall* DAT_00e89ed8)(void*);
namespace Task2758 {
struct Memory { void FUN_0086ba60(void*); };
extern Memory DAT_01090a78;
struct SsArr {
 virtual ~SsArr() {
  if(data) {
   DAT_00e89ed8(data);
   data=0;
   b=0;
   a=0;
  }
 }
 void* data;
 int a,b;
};
// pdb: BSSimpleArray<NiFrustumPlanes,1024>::`scalar deleting destructor' | BSCompoundFrustum.obj | fnv360_0822_retail, vtable, medium
SsArr* __fastcall FUN_00aa81e0(SsArr* p,int,unsigned flags) {
 p->SsArr::~SsArr();
 if(flags&1) DAT_01090a78.FUN_0086ba60(p);
 return p;
}
}

// @f3 0x00aa73e0 (community match, verified in this file)
namespace f3m_00aa73e0 {
namespace task2783 {
const char* __cdecl FUN_00c01980(const char*,int);
int __cdecl FUN_00c007fc(char*,unsigned int,const char*);
struct PathOwner {int field0,field4; const char* path;};
// @fnv 0x00c43da0
// pdb: INISettingCollection::MainKey | XINISetting.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_dedup), high
void __cdecl INISettingCollection_MainKey(PathOwner* param_1, char* pDest)
{
    const char* name = "MAIN";
    if (pDest) {
        const char* path = param_1->path;
        if (path) {
            const char* colon = FUN_00c01980(path, ':');
            if (colon) name = colon + 1;
        }
        FUN_00c007fc(pDest, 0x40, name);
    }
}

}
}   // namespace f3m_00aa73e0

// @f3 0x00aa5160 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

struct TlsBlock2777
{
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
    int m_298;
};

extern __declspec(thread) TlsBlock2777 DAT_tls_0x0;

struct RefObj2777
{
    int unk00;
    int unk04;
    long m_08;
};

struct RefPtr2777
{
    RefObj2777* m_pObject;
};

struct FUN_00424c00
{
    virtual void vfn_base();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00424c00(int a1);
};

struct FUN_00aa5160 : FUN_00424c00
{
    virtual void vfn_0();
    virtual void vfn_4();
    int m_18;
    RefPtr2777 m_1c;
    int m_20;
    int m_24;
    FUN_00aa5160(int a1);
};

// @fnv 0x00c3c590
// pdb: QueuedFile::QueuedFile | QueuedFiles.obj | fnv360_0822_retail, call_seq, high
// pdb params: aePriority
FUN_00aa5160::FUN_00aa5160(int a1) : FUN_00424c00(a1)
{
    RefPtr2777* p;
    RefObj2777* kObj;
    int tls;
    p = &m_1c;
    p->m_pObject = 0;
    if (p->m_pObject != 0)
    {
        kObj = p->m_pObject;
        InterlockedIncrement(&kObj->m_08);
    }
    m_20 = 0;
    m_24 = 0;
    tls = DAT_tls_0x0.m_298;
    m_18 = tls;
}

// @f3 0x00ab9310 (community match, verified in this file)
namespace f3m_00ab9310 {
namespace Task2790 {
struct Buffer { int unk00;unsigned int position;int unk08;int (__cdecl* write)(void*,const void*,unsigned int,unsigned int*,int); };
struct Stream { int unk000,unk004,unk008,unk00c,unk010,unk014,unk018,unk01c,unk020,unk024,unk028,unk02c,unk030,unk034,unk038,unk03c,unk040,unk044,unk048,unk04c,unk050,unk054,unk058,unk05c,unk060,unk064,unk068,unk06c,unk070,unk074,unk078,unk07c,unk080,unk084,unk088,unk08c,unk090,unk094,unk098,unk09c,unk0a0,unk0a4,unk0a8,unk0ac,unk0b0,unk0b4,unk0b8,unk0bc,unk0c0,unk0c4,unk0c8,unk0cc,unk0d0,unk0d4,unk0d8,unk0dc,unk0e0,unk0e4,unk0e8,unk0ec,unk0f0,unk0f4,unk0f8,unk0fc,unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c,unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c,unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc,unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc,unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c,unk240,unk244,unk248,unk24c; Buffer* buffer; };
struct Vector {float x,y,z;void FUN_00823eb0(Stream*);};
struct Object {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;unsigned int value;
 void FUN_00ac6040(Stream*);void FUN_00ab9310(Stream*);
};
// pdb: BSParentVelocityModifier::SaveBinary | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Object::FUN_00ab9310(Stream* stream) {
 FUN_00ac6040(stream);
 Buffer* reader=stream->buffer;
 { unsigned int size=4;reader->position+=reader->write(reader,&value,4,&size,1); }
}
}
}   // namespace f3m_00ab9310

// @f3 0x00ab60d0 (community match, verified in this file)
namespace f3m_00ab60d0 {
namespace task2788 {
struct Binary {void* vtable; unsigned int position; unsigned int (__cdecl* read)(Binary*,void*,unsigned int,unsigned int*,unsigned int);};
struct Stream {
unsigned int field000;
unsigned int field004;
unsigned int field008;
unsigned int field00c;
unsigned int field010;
unsigned int field014;
unsigned int field018;
unsigned int field01c;
unsigned int field020;
unsigned int field024;
unsigned int field028;
unsigned int field02c;
unsigned int field030;
unsigned int field034;
unsigned int field038;
unsigned int field03c;
unsigned int field040;
unsigned int field044;
unsigned int field048;
unsigned int field04c;
unsigned int field050;
unsigned int field054;
unsigned int field058;
unsigned int field05c;
unsigned int field060;
unsigned int field064;
unsigned int field068;
unsigned int field06c;
unsigned int field070;
unsigned int field074;
unsigned int field078;
unsigned int field07c;
unsigned int field080;
unsigned int field084;
unsigned int field088;
unsigned int field08c;
unsigned int field090;
unsigned int field094;
unsigned int field098;
unsigned int field09c;
unsigned int field0a0;
unsigned int field0a4;
unsigned int field0a8;
unsigned int field0ac;
unsigned int field0b0;
unsigned int field0b4;
unsigned int field0b8;
unsigned int field0bc;
unsigned int field0c0;
unsigned int field0c4;
unsigned int field0c8;
unsigned int field0cc;
unsigned int field0d0;
unsigned int field0d4;
unsigned int field0d8;
unsigned int field0dc;
unsigned int field0e0;
unsigned int field0e4;
unsigned int field0e8;
unsigned int field0ec;
unsigned int field0f0;
unsigned int field0f4;
unsigned int field0f8;
unsigned int field0fc;
unsigned int field100;
unsigned int field104;
unsigned int field108;
unsigned int field10c;
unsigned int field110;
unsigned int field114;
unsigned int field118;
unsigned int field11c;
unsigned int field120;
unsigned int field124;
unsigned int field128;
unsigned int field12c;
unsigned int field130;
unsigned int field134;
unsigned int field138;
unsigned int field13c;
unsigned int field140;
unsigned int field144;
unsigned int field148;
unsigned int field14c;
unsigned int field150;
unsigned int field154;
unsigned int field158;
unsigned int field15c;
unsigned int field160;
unsigned int field164;
unsigned int field168;
unsigned int field16c;
unsigned int field170;
unsigned int field174;
unsigned int field178;
unsigned int field17c;
unsigned int field180;
unsigned int field184;
unsigned int field188;
unsigned int field18c;
unsigned int field190;
unsigned int field194;
unsigned int field198;
unsigned int field19c;
unsigned int field1a0;
unsigned int field1a4;
unsigned int field1a8;
unsigned int field1ac;
unsigned int field1b0;
unsigned int field1b4;
unsigned int field1b8;
unsigned int field1bc;
unsigned int field1c0;
unsigned int field1c4;
unsigned int field1c8;
unsigned int field1cc;
unsigned int field1d0;
unsigned int field1d4;
unsigned int field1d8;
unsigned int field1dc;
unsigned int field1e0;
unsigned int field1e4;
unsigned int field1e8;
unsigned int field1ec;
unsigned int field1f0;
unsigned int field1f4;
unsigned int field1f8;
unsigned int field1fc;
unsigned int field200;
unsigned int field204;
unsigned int field208;
unsigned int field20c;
unsigned int field210;
unsigned int field214;
unsigned int field218;
unsigned int field21c;
unsigned int field220;
unsigned int field224;
unsigned int field228;
unsigned int field22c;
unsigned int field230;
unsigned int field234;
unsigned int field238;
unsigned int field23c;
unsigned int field240;
unsigned int field244;
unsigned int field248;
Binary* input;};
struct Owner {
unsigned int field00;
unsigned int field04;
unsigned int field08;
unsigned int field0c;
unsigned int field10;
unsigned int field14;
float value; void FUN_00ac5fa0(Stream*); void FUN_00ab60d0(Stream*);};
// pdb: BSPSysStripUpdateModifier::LoadBinary | BSPSysStripUpdateModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Owner::FUN_00ab60d0(Stream* stream) {
FUN_00ac5fa0(stream);
Binary* __restrict input=stream->input; unsigned int size=4;
input->position+=input->read(input,&value,4,&size,1);
}
}
}   // namespace f3m_00ab60d0

// @f3 0x00aa8780 (community match, verified in this file)
namespace f3m_00aa8780 {
namespace task2804 {
struct Item {int type,unk04,unk08;};
struct Array {int unk00;Item*data;int unk08,capacity,unk10,count;void FUN_005bb760(int,bool);};
struct Owner {unsigned char dirty;int unk04,unk08,unk0c,unk10;Array entries;void FUN_00aa8780();};
// pdb: BSCompoundFrustum::EndGroup | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
void Owner::FUN_00aa8780(){int cap=entries.capacity;if(entries.count+1>=cap){int c=entries.capacity;entries.FUN_005bb760(c+10,true);}dirty=0;entries.data[entries.count].type=6;entries.count=entries.count+1;}
}
}   // namespace f3m_00aa8780

// @f3 0x00ab92d0 (community match, verified in this file)
namespace f3m_00ab92d0 {
struct Binary2789 {
 void* vtable;
 unsigned int position;
 unsigned int (__cdecl *read)(Binary2789*,void*,unsigned int,unsigned int*,unsigned int);
 void Read(void* destination) { unsigned int size=4; position+=read(this,destination,4,&size,1); }
};
struct Stream2789;
struct Loader2789 {
 void FUN_00ac5fa0(Stream2789*);
 void FUN_00ab92d0(Stream2789*);
};
// pdb: BSParentVelocityModifier::LoadBinary | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Loader2789::FUN_00ab92d0(Stream2789* stream) {
 FUN_00ac5fa0(stream);
 Binary2789* input=*(Binary2789**)((char*)stream+0x24c);
 input->Read((char*)this+0x20);
}
}   // namespace f3m_00ab92d0

// @f3 0x00aa8700 (community match, verified in this file)
namespace f3m_00aa8700 {
namespace task2816 {
struct Item {int type,unk04,unk08;};
struct Array {int unk00;Item*data;int unk08,capacity,unk10,count;void FUN_005bb760(int,bool);};
struct Owner {unsigned char dirty;int unk04,unk08,unk0c,unk10;Array entries;void FUN_00aa8700();};
// pdb: BSCompoundFrustum::StartGroupIntersection | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, medium
void Owner::FUN_00aa8700(){int cap=entries.capacity;if(entries.count+1>=cap){int c=entries.capacity;entries.FUN_005bb760(c+10,true);}entries.data[entries.count].type=4;entries.count=entries.count+1;}
}
}   // namespace f3m_00aa8700

// @f3 0x00aae920 (community match, verified in this file)
namespace f3_2821 {
struct Object { virtual void v0(); virtual void v1(); virtual void* v2(); };
extern char DAT_0116eb5c;
bool FUN_00aae800(Object*,Object*);
// @fnv 0x00c511f0
// pdb: BSParticleSystemManager::IsValidMasterParticleSystem | BSParticleSystemManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject
bool __cdecl FUN_00aae920(Object* obj)
{
    bool result2 = false;
    Object* tmp;
    {
        bool gate;
        if (obj == 0) {
            gate = false;
        } else {
            gate = obj->v2() == (void*)&DAT_0116eb5c;
        }
        if (gate) {
            tmp = obj;
            result2 = FUN_00aae800(obj, tmp);
        }
    }
    return result2;
}

}

// @f3 0x00aa97b0 (community match, verified in this file)
namespace f3m_00aa97b0 {
struct FUN_00aa97b0_owner
{
    void FUN_00aa9660(float value);
    void UpdateDownwardPass(void* data, unsigned int flags);
    void FUN_00aa97b0(float* arg, unsigned int second);
};

// pdb: BSTempNodeManager::UpdateDownwardPass | BSTempNodeManager.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSOrderedNode::UpdateDownwardPass)
// pdb params: UpdateData, uFlags
void FUN_00aa97b0_owner::FUN_00aa97b0(float* arg, unsigned int second)
{
    FUN_00aa9660(*arg);
    UpdateDownwardPass(arg, second);
}
}   // namespace f3m_00aa97b0

// @f3 0x00aa0a90 (community match, verified in this file)
namespace f3m_00aa0a90 {
struct Sub0a90
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00823eb0(void* arg);
};

struct FUN_00aa0a90_owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Sub0a90 sub0C;
    Sub0a90 sub18;
    void FUN_00c22010(void* arg);
    void FUN_00aa0a90(void* arg);
};

// pdb: BSMultiBoundAABB::LoadBinary | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: arStream
void FUN_00aa0a90_owner::FUN_00aa0a90(void* arg)
{
    FUN_00c22010(arg);
    sub0C.FUN_00823eb0(arg);
    sub18.FUN_00823eb0(arg);
}
}   // namespace f3m_00aa0a90

// @f3 0x00ab9b90 (community match, verified in this file)
#include <string.h>
namespace f3m_00ab9b90 {
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);

struct Owner_00ab9b90 {
    int unk00;
    int unk04;
    char* unk08;
    void BSReference_SetName(const char* src);
};

// pdb: BSReference::SetName | BSReference.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
void Owner_00ab9b90::BSReference_SetName(const char* src)
{
    _g_memoryManager.Deallocate(unk08);
    unk08 = 0;
    if (src)
    {
        unsigned int size = strlen(src) + 1;
        char* buffer = (char*)_g_memoryManager.Allocate(size);
        unk08 = buffer;
        if (buffer)
        {
            strcpy_s(buffer, size, src);
        }
    }
}
}   // namespace f3m_00ab9b90

// @f3 0x00ab6740 (community match, verified in this file)
namespace f3m_00ab6740 {
namespace f3_2833 {
struct Writer {
unsigned int unk00,position,unk08;
unsigned int (__cdecl* write)(Writer*,const void*,unsigned int,unsigned int*,unsigned int);
unsigned int Write(const void* p,unsigned int n) {
unsigned int size=n;
unsigned int result=write(this,p,n,&size,1);
position+=result;
return result;
}
};
struct Stream {
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
Writer* writer;
};
struct Color { float r,g,b,a; void FUN_0083fb40(Stream*); };
struct Serializer {
unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
Color first,second,third;
unsigned int field48,field4c,field50,field54,field58,field5c;
void FUN_00ac6040(Stream*); void FUN_00ab6740(Stream*);
};
// pdb: BSPSysSimpleColorModifier::SaveBinary | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Serializer::FUN_00ab6740(Stream* stream) {
FUN_00ac6040(stream);
stream->writer->Write(&field48,4);
stream->writer->Write(&field4c,4);
stream->writer->Write(&field50,4);
stream->writer->Write(&field54,4);
stream->writer->Write(&field58,4);
stream->writer->Write(&field5c,4);
first.FUN_0083fb40(stream);
second.FUN_0083fb40(stream);
third.FUN_0083fb40(stream);
}
}
}   // namespace f3m_00ab6740

// @f3 0x00ab6640 (community match, verified in this file)
namespace f3m_00ab6640 {
namespace task2834 {
struct Writer;typedef unsigned (__cdecl*Callback)(Writer*,void*,unsigned,unsigned*,unsigned);
struct Writer{int unk00;unsigned bytesWritten;Callback write;};
struct Stream{
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
Writer*writer;Writer*WriterPtr(){return writer;} };
struct Color{float r,g,b,a;void FUN_0083faa0(Stream*);};
struct State{int unk00,unk04,unk08,unk0c,unk10,unk14;Color c1,c2,c3;float red,green,blue,alpha,threshold,blendMode;void FUN_00ac5fa0(Stream*);void FUN_00ab6640(Stream*);};
// pdb: BSPSysSimpleColorModifier::LoadBinary | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void State::FUN_00ab6640(Stream* stream){FUN_00ac5fa0(stream);Writer* __restrict writer=stream->WriterPtr();unsigned elementWidth=4;
writer->bytesWritten += writer->write(writer,&red,4,&elementWidth,1);
writer=stream->WriterPtr();elementWidth=4;
writer->bytesWritten += writer->write(writer,&green,4,&elementWidth,1);
writer=stream->WriterPtr();elementWidth=4;
writer->bytesWritten += writer->write(writer,&blue,4,&elementWidth,1);
writer=stream->WriterPtr();elementWidth=4;
writer->bytesWritten += writer->write(writer,&alpha,4,&elementWidth,1);
writer=stream->WriterPtr();elementWidth=4;
writer->bytesWritten += writer->write(writer,&threshold,4,&elementWidth,1);
writer=stream->WriterPtr();elementWidth=4;
writer->bytesWritten += writer->write(writer,&blendMode,4,&elementWidth,1);
c1.FUN_0083faa0(stream);c2.FUN_0083faa0(stream);c3.FUN_0083faa0(stream);}
}
}   // namespace f3m_00ab6640

// @f3 0x00ab7320 (community match, verified in this file)
namespace f3m_00ab7320 {
namespace task2842 {
struct RefQ
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct ItemQ
{
    ItemQ* m_pkNext;
    ItemQ* m_pkPrev;
    T m_element;
};
template <class T> struct PoolQ {
    unsigned int m_uiCount;
    ItemQ<T>* FUN_00423640();
};
template <class T> struct PtrListQ
{
    ItemQ<T>* m_pkHead;
    ItemQ<T>* m_pkTail;
    PoolQ<T> m_pool;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((ItemQ<T>*)pos)->m_element;
        pos = ((ItemQ<T>*)pos)->m_pkNext;
        return e;
    }
    void* FindPos(const T& val, void* pos = 0) const
    {
        if (pos == 0)
            pos = GetHeadPos();
        while (pos)
        {
            void* pkFound = pos;
            if (val == GetNext(pos))
                return pkFound;
        }
        return 0;
    }
    __declspec(noinline) void __thiscall FUN_00827100(const T& item) {
        ItemQ<T>* node = m_pool.FUN_00423640();
        node->m_element = item;
        node->m_pkNext = 0;
        node->m_pkPrev = m_pkTail;
        if (m_pkTail) m_pkTail->m_pkNext = node;
        else m_pkHead = node;
        ++m_pool.m_uiCount;
        m_pkTail = node;
    }
};
struct FUN_00ab7320_cls
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
    PtrListQ<NiPointer<RefQ> > m_kNode;
    void __thiscall FUN_00ab7320(RefQ* pObj);
};
// @fnv 0x00c5dcd0
// pdb: BSMasterParticleSystem::AddEmitterObj | BSMasterParticleSystem.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apEmitterObj
void __thiscall FUN_00ab7320_cls::FUN_00ab7320(RefQ* pObj)
{
    void* pos = m_kNode.FindPos(pObj);
    if (!pos) {
        const NiPointer<RefQ> item(pObj);
        m_kNode.FUN_00827100(item);
    }
}
}  // namespace task2842
}   // namespace f3m_00ab7320

// @f3 0x00aa72f0 (community match, verified in this file)
extern const char* DAT_0116d6ec;
extern const char DAT_00de0334[], DAT_00e89e4c[];
namespace f3m_00aa72f0 {
namespace f3_2845 {
struct StrArr {
unsigned int unk00,unk04; unsigned short capacity,count,unk0c,grow;
void FUN_00555790(unsigned int); void FUN_005b3880(unsigned int,char* const&);
__forceinline void Add(char** slot) { char* text=*slot; unsigned int index=count; if(index>=capacity) FUN_00555790(index+grow); FUN_005b3880(index,text); }
};
char* FUN_00847b50(const char*);
char* FUN_00847d30(const char*,int);
char* FUN_00847e70(const char*,const char*);
struct Viewer {
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
unsigned int flags; int value;
void FUN_0082ee90(StrArr*); void FUN_00aa72f0(StrArr*);
};
// pdb: BSValueNode::GetViewerStrings | BSValueNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void Viewer::FUN_00aa72f0(StrArr* strings) {
FUN_0082ee90(strings);
char* text=FUN_00847b50(DAT_0116d6ec); strings->Add(&text);
unsigned int number=value;
char* numeric=FUN_00847d30(DAT_00de0334,number); strings->Add(&numeric);
if(flags&1) {
char* line=FUN_00847e70(DAT_00e89e4c,(flags&1)?"true":"false"); strings->Add(&line);
}
}
}
}   // namespace f3m_00aa72f0

// @f3 0x00aa5c70 (community match, verified in this file)
namespace task2864 {
struct Size {unsigned low,high;};
int __cdecl FUN_005932b0(const char*,Size*);int __cdecl BSSystemFile_DeleteFileA(const char*);
extern char DAT_0116d5a0[];
struct FUN_0086c3f0 {virtual ~FUN_0086c3f0();};typedef FUN_0086c3f0 Base;
struct FUN_00aa5c70:Base {virtual ~FUN_00aa5c70();};
extern Base* DAT_0116d6c4;
// pdb: MessageHandler::~MessageHandler | MessageHandler.obj | fnv360_0822_retail, call_seq, high
FUN_00aa5c70::~FUN_00aa5c70(){Size info;if(FUN_005932b0(DAT_0116d5a0,&info)==0){if(info.low==0x46&&info.high==0)BSSystemFile_DeleteFileA(DAT_0116d5a0);}if(DAT_0116d6c4==this)DAT_0116d6c4=0;}
}

// @f3 0x00ab5de0 (community match, verified in this file)
namespace f3m_00ab5de0 {
namespace task2870 {
void* __cdecl FUN_0089eb90(unsigned) throw();void __cdecl FUN_0089ec10(void*,unsigned);
struct FUN_0082ea60 {
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
FUN_0082ea60(unsigned);};
struct Node: FUN_0082ea60 {virtual void v00();static void*operator new(unsigned n)throw(){return FUN_0089eb90(n);}static void operator delete(void*p,unsigned n){FUN_0089ec10(p,n);}Node():FUN_0082ea60(0){}void FUN_0082daa0(Node*,int);Node* FUN_00ab5de0(int);};
// pdb: BSNiNode::CreateClone | BSNiNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
Node* Node::FUN_00ab5de0(int arg){Node*p=new Node;FUN_0082daa0(p,arg);p->vbc();return p;}
}
}   // namespace f3m_00ab5de0

// @f3 0x00ab41f0 (community match, verified in this file)
namespace f3m_00ab41f0 {
namespace task2856 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class RefObjectB06
{
  public:
    virtual ~RefObjectB06();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};

template <class T> class NiPointerB06
{
  public:
    NiPointerB06(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointerB06(const NiPointerB06& other) : m_pObject(other.m_pObject) { if(m_pObject) m_pObject->IncRefCount(); }
    ~NiPointerB06()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};

struct RefSetB06
{
    struct Node {Node* next;Node* prev;NiPointerB06<RefObjectB06> value;};
    Node* head;
    NiPointerB06<RefObjectB06> FUN_00ab43e0(Node*&);
    __declspec(noinline) NiPointerB06<RefObjectB06> FUN_00af0700(const NiPointerB06<RefObjectB06>& input) {
        Node* found=head;
        while(found && found->value.m_pObject!=input.m_pObject) found=found->next;
        return found ? FUN_00ab43e0(found) : input;
    }
};

struct OwnerB06
{
    void* m_pVTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RefSetB06 m_kSet;

    void BSPortalGraph_RemoveRoom(RefObjectB06* pkObject);
};

// @fnv 0x00c5b060
// pdb: BSPortalGraph::RemoveRoom | BSPortalGraph.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void OwnerB06::BSPortalGraph_RemoveRoom(RefObjectB06* pkObject)
{
    if(pkObject)
    {
        NiPointerB06<RefObjectB06> spRetainedObject(pkObject);
        m_kSet.FUN_00af0700(spRetainedObject);
    }
}


}
}   // namespace f3m_00ab41f0

// @f3 0x00aa8350 (community match, verified in this file)
namespace f3m_00aa8350 {
namespace f3aa8350 {
struct Element {
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
};
struct Array {
    virtual void v00();
    virtual Element* Allocate(unsigned int);
    virtual void Free(Element*);
    Element* m_pBuffer;
    unsigned int m_uiSize, m_uiCapacity;
    void ReleaseBuffer(bool bFree) {
        if (m_pBuffer) {
            if (bFree) { Free(m_pBuffer); m_pBuffer=0; m_uiCapacity=0; }
            m_uiSize=0;
        }
    }
    void FUN_00aa80d0(unsigned int, unsigned int);
    void FUN_00aa8030(Element*, unsigned int);
    void DestructItems(Element* p, unsigned int n) { for (unsigned int i=0;i<n;++i) p[i].~Element(); }
    void Shrink(unsigned int n) { FUN_00aa80d0(n,n);m_uiCapacity=n; }
    void FUN_00aa8350(unsigned int,bool);
};
// @fnv 0x00c4a070
// pdb: BSSimpleArray<NiFrustumPlanes,1024>::SetSize | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aiNewSize, abFreeMemory
void Array::FUN_00aa8350(unsigned int uiNewSize, bool bFree)
{
    if (uiNewSize == 0)
    {
        ReleaseBuffer(bFree);
        return;
    }
    if (uiNewSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(uiNewSize);
            m_uiCapacity = uiNewSize;
        }
        else
        {
            FUN_00aa80d0(uiNewSize, m_uiSize);
            m_uiCapacity = uiNewSize;
        }
        FUN_00aa8030(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
    else if (uiNewSize < m_uiSize)
    {
        DestructItems(m_pBuffer + uiNewSize, m_uiSize - uiNewSize);
        m_uiSize = uiNewSize;
        if (bFree && uiNewSize <= m_uiCapacity >> 2)
        {
            FUN_00aa80d0(uiNewSize, uiNewSize);
            m_uiCapacity = uiNewSize;
        }
    }
    else
    {
        FUN_00aa8030(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
}

}
}   // namespace f3m_00aa8350

// @f3 0x00aa7150 (community match, verified in this file)
namespace f3m_00aa7150 {
namespace f3_2857 {
void* FUN_0089eb90(unsigned int);
struct FUN_00ab5d60 {
virtual ~FUN_00ab5d60(); FUN_00ab5d60();
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
unsigned char flags;
static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
};
struct Object : FUN_00ab5d60 {
unsigned int value,other;
Object():value(0),other(0){}
virtual ~Object() {}
void FUN_00ab5d90(Object*,int);
Object* FUN_00aa7150(int);
};
// pdb: BSValueNode::CreateClone | BSValueNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
Object* Object::FUN_00aa7150(int arg) {
Object* object=new Object;
FUN_00ab5d90(object,arg);
object->value=value;
object->flags=flags;
return object;
}
}
}   // namespace f3m_00aa7150

// @f3 0x00aba3c0 (community match, verified in this file)
namespace f3m_00aba3c0 {
namespace task2882 {
void* FUN_0089eb90(unsigned);
struct Array { int unk00,unk04,unk08,unk0c; void FUN_00602700(Array&) const; };
struct FUN_00aba1f0 {
static void* operator new(unsigned n){return FUN_0089eb90(n);}
static void operator delete(void*);
FUN_00aba1f0();
int unk00,unk04,unk08;
Array values;
void FUN_00845a50(FUN_00aba1f0*,int);
FUN_00aba1f0* FUN_00aba3c0(int);
};
// pdb: BSTextureData::CreateClone | BSTextureData.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCloning
FUN_00aba1f0* FUN_00aba1f0::FUN_00aba3c0(int context) {
FUN_00aba1f0* result = new FUN_00aba1f0;
FUN_00845a50(result,context);
values.FUN_00602700(result->values);
return result;
}
}
}   // namespace f3m_00aba3c0

// @f3 0x00aa5d10 (community match, verified in this file)
namespace Task2880 {
struct Heap {void* FUN_0086b930(unsigned int);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
class FUN_0086c3e0 {public:
 FUN_0086c3e0();
 virtual void v00();
 static void* operator new(unsigned int n){return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}
};
class Derived:public FUN_0086c3e0 {public:bool enabled;Derived():enabled(false){}virtual void v00();};
extern Derived* DAT_0116d6c4;
// pdb: XapipGetTimeZoneBias | xapipgettimezonebias.obj | fnv360_0721_retail, objrun_prop, low
// pdb params: bias
void FUN_00aa5d10(){DAT_0116d6c4=new Derived;}
}

// @f3 0x00aaf8a0 (community match, verified in this file)
namespace f3m_00aaf8a0 {
namespace f3_2881 {
void* FUN_0089eb90(unsigned int);
struct FUN_00aaf800 {
unsigned int field00;
unsigned int field04;
unsigned int field08;
unsigned int field0c;
unsigned int field10;
unsigned int field14;
unsigned int field18;
unsigned int field1c;
unsigned int field20;
unsigned int field24;
unsigned int field28;
unsigned int field2c;
unsigned int field30;
unsigned int field34;
unsigned int field38;
unsigned int field3c;
unsigned int field40;
unsigned int field44;
unsigned int field48;
FUN_00aaf800();
static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
static void operator delete(void*);
void FUN_00837bc0(FUN_00aaf800*,int);
FUN_00aaf800* FUN_00aaf8a0(int);
};
// pdb: NiBSBoneLODController::CreateClone | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
FUN_00aaf800* FUN_00aaf800::FUN_00aaf8a0(int argument) {
FUN_00aaf800* object=new FUN_00aaf800;
FUN_00837bc0(object,argument);
object->field34=field34;
object->field38=field38;
return object;
}
}
}   // namespace f3m_00aaf8a0

// @f3 0x00ab05a0 (community match, verified in this file)
namespace f3m_00ab05a0 {
namespace f3ab05a0 {
struct Binary {
    void* vtable;
    unsigned int position;
    void* read;
    unsigned int (__cdecl *write)(Binary*, const void*, unsigned int, unsigned int*, unsigned int);
    template<class T> void Write(const T& data) {
        unsigned int size=sizeof(T);
        position += write(this,&data,size,&size,1);
    }
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
int unk24c;
Binary* output;
};
template<class T> inline void Save(Stream& s,const T& value) {
    s.output->Write(value);
}
struct Object {
    int unk00,unk04,unk08;
    unsigned short flags;
    unsigned char value;
    void FUN_0083fa20(Stream&);
    void FUN_00ab05a0(Stream&);
};
// pdb: FurnitureMark::SaveBinary | BSFurnitureMarker.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream
void Object::FUN_00ab05a0(Stream& s) {
    FUN_0083fa20(s);
    Save(s,flags);
    Save(s,value);
    Save(s,value);
}
}
}   // namespace f3m_00ab05a0

// @f3 0x00aa6010 (community match, verified in this file)
extern const char* DAT_0116d6e0;
namespace f3m_00aa6010 {
namespace Task2892 {
struct FUN_008459f0 {FUN_008459f0();~FUN_008459f0();virtual void v00();int refs;void* name;void FUN_008245d0(const char*);};
struct IntData: FUN_008459f0 {int value;IntData(int v):value(v){}};
struct FUN_00aa6010: IntData {FUN_00aa6010(int);virtual void v00();};
// pdb: BSXFlags::BSXFlags | BSXFlags.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiValue
FUN_00aa6010::FUN_00aa6010(int v):IntData(v){FUN_008245d0(DAT_0116d6e0);}
}
}   // namespace f3m_00aa6010

// @f3 0x00aa5120 (community match, verified in this file)
#include <string.h>
extern "C" char DAT_01090a78;
namespace f3m_00aa5120 {

struct Heap00aa5120 { void* FUN_0086b930(unsigned int); };

struct Owner00aa5120 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    char* unk28;
    void FUN_00aa5120(const char* src);
};

// pdb: QueuedFileEntry::SetFileName | QueuedFiles.obj | fnv360_0721_retail, call_seq, medium
// pdb params: apFileName
void Owner00aa5120::FUN_00aa5120(const char* src)
{
    if (src) {
        unsigned int len = strlen(src) + 1;
        unk28 = (char*)((Heap00aa5120*)&DAT_01090a78)->FUN_0086b930(len);
        strcpy_s(unk28, len, src);
    }
}
}   // namespace f3m_00aa5120

// @f3 0x00ab9b50 (community match, verified in this file)
namespace f3m_00ab9b50 {
struct NiStreamView9b50 { void NiStream_SaveCString(unsigned int value); };

struct Owner9b50 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_0078c030(NiStreamView9b50* stream);
    void FUN_00ab9b50(NiStreamView9b50* stream);
};

// pdb: BSReference::SaveBinary | BSReference.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Owner9b50::FUN_00ab9b50(NiStreamView9b50* stream)
{
    FUN_0078c030(stream);
    stream->NiStream_SaveCString(unk08);
}
}   // namespace f3m_00ab9b50

// @f3 0x00aba0b0 (community match, verified in this file)
namespace f3m_00aba0b0 {
namespace task2884 {
class RefBase {
public:
 virtual ~RefBase();
 unsigned refs;
};

// the pack's BSSimpleArray stand-in has a manual vtable field; the real class is polymorphic
template <class Element, int Size>
class BSSimpleArray {
public:
	typedef unsigned int T;
	virtual ~BSSimpleArray() { Clear(); }
	virtual T* Allocate(unsigned int auiCount);
	virtual void Deallocate(T* apData);
	virtual T* Reallocate(T* apData, unsigned int auiCount);

	void Clear()
	{
		if (pBuffer) {
			Deallocate(pBuffer);
			pBuffer = 0;
			uiAllocSize = 0;
			uiSize = 0;
		}
	}

	T* pBuffer;                  // 04
	unsigned int uiSize;         // 08
	unsigned int uiAllocSize;    // 0C
};

class Owner : public RefBase {
public:
	virtual ~Owner();
	unsigned unk08;

	BSSimpleArray<unsigned int, 1024> guardedRefs;   // 0C
};

// pdb: BSTextureData::~BSTextureData | BSTextureData.obj | fnv360_0822_debug, call_seq, medium
Owner::~Owner()
{
}

}
}   // namespace f3m_00aba0b0

// @f3 0x00ab7c10 (community match, verified in this file)
extern const char* DAT_0116eb64;
namespace f3m_00ab7c10 {
namespace task2896 {
struct FUN_008459f0 { FUN_008459f0(); virtual ~FUN_008459f0(); unsigned refs; const char* name; void FUN_008245d0(const char*); };
struct Integers2896:FUN_008459f0 { unsigned count; int* values; virtual ~Integers2896(); Integers2896(){values=0;count=0;} };
struct FUN_00ab7c10:Integers2896 { FUN_00ab7c10(); virtual ~FUN_00ab7c10(); };
// pdb: BSWArray::CreateObject | BSWArray.obj | fnv360_0822_retail, udata, high
FUN_00ab7c10::FUN_00ab7c10(){FUN_008245d0(DAT_0116eb64);}
}
}   // namespace f3m_00ab7c10

// @f3 0x00aa5fa0 (community match, verified in this file)
namespace task2897 {
struct FUN_008459f0 {int unk04,unk08;FUN_008459f0();virtual ~FUN_008459f0();};
struct Mid: FUN_008459f0 {int unk0c;Mid(){unk0c=0;}virtual ~Mid(){}};
extern int DAT_0116d6e0;
struct FUN_00aa5fa0:Mid {FUN_00aa5fa0();virtual ~FUN_00aa5fa0();void FUN_008245d0(int);};
// pdb: BSXFlags::BSXFlags | BSXFlags.obj | fnv360_0822_retail, call_seq, high
FUN_00aa5fa0::FUN_00aa5fa0(){FUN_008245d0(DAT_0116d6e0);}
}

// @f3 0x00ab0e00 (community match, verified in this file)
namespace f3_2905 {
struct FixedString { const char* value; };
extern FixedString* DAT_0116da80;
struct Point { float x,y,z; };
extern Point DAT_0108ec68;
struct FUN_00845b60 {
 virtual ~FUN_00845b60();
 unsigned int references;
 FixedString name;
 FUN_00845b60(const FixedString&);
};
struct FUN_00ab0e00 : FUN_00845b60 {
 Point first,second;
 FUN_00ab0e00();
 virtual ~FUN_00ab0e00();
};
// pdb: BSBound::BSBound | BSBound.obj | fnv360_0822_retail, uvref, high
FUN_00ab0e00::FUN_00ab0e00() : FUN_00845b60(*DAT_0116da80) {
 first=DAT_0108ec68;
 second=DAT_0108ec68;
}
}

// @f3 0x00aa60f0 (community match, verified in this file)
namespace f3m_00aa60f0 {
namespace task2913 {
struct Extra {virtual void v0();virtual void v4();virtual void* v8();};
struct Object {Extra* FUN_00824a50(void*);};extern void* DAT_0116d6e0;extern int DAT_0116d6e4;
// pdb: BSXFlags::Find | BSXFlags.obj | fnv360_0822_debug, udata, low, conflict (skyrim: BSXFlags::GetFlags)
// pdb params: apObject
void* FUN_00aa60f0(Object*obj){void*result=0;if(obj){Extra*extra=obj->FUN_00824a50(DAT_0116d6e0);bool ok;if(!extra)ok=false;else ok=extra->v8()==&DAT_0116d6e4;if(ok)result=extra;}return result;}
}
}   // namespace f3m_00aa60f0

// @f3 0x00ab43a0 (community match, verified in this file)
namespace f3m_00ab43a0 {
namespace task2915 {
struct Array {unsigned unk00;unsigned* data;unsigned count;void FUN_00ab4040(unsigned,unsigned);};
inline unsigned Find(Array*p,unsigned value){for(unsigned i=0;i<p->count;++i){if(p->data && p->data[i]==value)return i;}return ~0u;}
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
Array values;void FUN_00ab43a0(unsigned);};
// pdb: BSPortalGraph::RemoveUnboundNode | BSPortalGraph.obj | fnv360_0822_retail, call_gap, low
// pdb params: apNode
void Owner::FUN_00ab43a0(unsigned value){unsigned index=Find(&values,value);if(index!=~0u)values.FUN_00ab4040(index,1);}
}
}   // namespace f3m_00ab43a0

// @f3 0x00ab5650 (community match, verified in this file)
namespace f3m_00ab5650 {

void __cdecl FUN_008553d0();
void __cdecl FUN_0089ec10(unsigned int* param, unsigned int value);

struct FUN_00ab5650_This {
    unsigned int unk00;
};

class FUN_00ab5650_Class {
public:
    unsigned int* FUN_00ab5650(unsigned char param2);
};

// pdb: BSScissorTriShape::`scalar deleting destructor' | BSScissorTriShape.obj | fnv360_0822_retail, vtable_prefix, medium
unsigned int* FUN_00ab5650_Class::FUN_00ab5650(unsigned char param2)
{
    *reinterpret_cast<unsigned int*>(this) = 0xe8b15c;
    FUN_008553d0();
    if (param2 & 1) {
        FUN_0089ec10(reinterpret_cast<unsigned int*>(this), 0xd4);
    }
    return reinterpret_cast<unsigned int*>(this);
}
}   // namespace f3m_00ab5650

// @f3 0x00ab7440 (community match, verified in this file)
namespace f3m_00ab7440 {
struct Input00ab7440 { unsigned int unk00; unsigned int size; };
struct State00ab7440 {
    void FUN_00825330(Input00ab7440*);
    void FUN_00ab7400();
    void FUN_00ab7440(Input00ab7440*);
};
// pdb: BSMasterParticleSystem::PostLinkObject | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void State00ab7440::FUN_00ab7440(Input00ab7440* input) {
    FUN_00825330(input);
    if (input->size < 16)
        FUN_00ab7400();
}
}   // namespace f3m_00ab7440

// @f3 0x00aa6f80 (community match, verified in this file)
extern unsigned char DAT_00e89d44;
namespace f3m_00aa6f80 {

struct BaseInitView_00ab5d60 {
    void FUN_00ab5d60();
};

struct BSValueNodeView_aa6f80 {
    void* vtable;
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
    BSValueNodeView_aa6f80* FUN_00aa6f80();
};

// pdb: BSValueNode::BSValueNode | BSValueNode.obj | fnv360_0822_retail, call_gap, low
BSValueNodeView_aa6f80* BSValueNodeView_aa6f80::FUN_00aa6f80()
{
    ((BaseInitView_00ab5d60*)this)->FUN_00ab5d60();
    unkb0 = 0;
    unkb4 = 0;
    vtable = &DAT_00e89d44;
    return this;
}
}   // namespace f3m_00aa6f80

// @f3 0x00aaa260 (community match, verified in this file)
namespace f3m_00aaa260 {
struct Stream00aaa260 {
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
    virtual void Apply(void*);
};
struct State00aaa260 {
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
    void* member;
    void FUN_0082e820(Stream00aaa260*);
    void FUN_00aaa260(Stream00aaa260*);
};
// pdb: BSMultiBoundNode::SaveBinary | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSFadeNode::SaveBinary)
// pdb params: arStream
void State00aaa260::FUN_00aaa260(Stream00aaa260* stream) {
    FUN_0082e820(stream);
    stream->Apply(member);
}
}   // namespace f3m_00aaa260

// @f3 0x00aaa330 (community match, verified in this file)
void __cdecl operator delete(void* object, unsigned int size);

struct BaseInitView_aaa120 {
    void FUN_00aaa120();
};

struct ObjectInitView_aaa330 : BaseInitView_aaa120 {
    ObjectInitView_aaa330* FUN_00aaa330(unsigned char mode);
};

// pdb: BSMultiBoundNode::`scalar deleting destructor' | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, high
ObjectInitView_aaa330* ObjectInitView_aaa330::FUN_00aaa330(unsigned char mode)
{
    FUN_00aaa120();
    if (mode & 1)
        ::operator delete(this, 0xb4);
    return this;
}

// @f3 0x00aa97e0 (community match, verified in this file)
namespace f3m_00aa97e0 {
namespace f3m_00aa97e0 {
struct Owner {
    void FUN_00aa9660(float value);
    void FUN_0082dcf0(const float* input, int flag);
    void FUN_00aa97e0(const float* input, int flag);
};
// pdb: BSTempNodeManager::UpdateSelectedDownwardPass | BSTempNodeManager.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSOrderedNode::UpdateSelectedDownwardPass)
// pdb params: UpdateData, uFlags
void Owner::FUN_00aa97e0(const float* input, int flag)
{
    FUN_00aa9660(*input);
    FUN_0082dcf0(input, flag);
}
}
}   // namespace f3m_00aa97e0

// @f3 0x00ab4cd0 (community match, verified in this file)
namespace f3m_00ab4cd0 {
namespace task2878 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void __cdecl FUN_0089e890(void*);
struct Ref {
 virtual void v0(); virtual void DeleteThis();
 long refs;
 void IncRefCount() { InterlockedIncrement(&refs); }
 void DecRefCount() { if(InterlockedDecrement(&refs)==0) DeleteThis(); }
};
struct Base {
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
 ~Base();
};
struct Owner : Base {
 NiPointer<Ref> ref;
 unsigned unk44,unk48,unk4C;
 void* buffer;
 ~Owner();
};
// pdb: NiPSysEmitterCtlr::~NiPSysEmitterCtlr | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, call_seq, low
Owner::~Owner() { void* b = buffer; FUN_0089e890(b); }
}
}   // namespace f3m_00ab4cd0

// @f3 0x00aa53c0 (community match, verified in this file)
extern char DAT_00e89844;
namespace f3m_00aa53c0 {
struct Heap00aa53c0 { void FUN_0086ba60(void*); };
namespace HeapNamespace00aa53c0 { extern Heap00aa53c0 DAT_01090a78; }
struct State00aa53c0 {
    void* table;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    void* memory;
    void FUN_00aa51a0();
    void FUN_00aa53c0();
};
// pdb: QueuedFileEntry::~QueuedFileEntry | QueuedFiles.obj | fnv360_0822_retail, call_seq, medium
void State00aa53c0::FUN_00aa53c0() {
    table = &DAT_00e89844;
    HeapNamespace00aa53c0::DAT_01090a78.FUN_0086ba60(memory);
    FUN_00aa51a0();
}
}   // namespace f3m_00aa53c0

// @f3 0x00aa2f10 (community match, verified in this file)
namespace f3m_00aa2f10 {
// pdb: NiTMapBase<DFALL<NiTMapItem<__int64,int> >,__int64,int>::IsKeysEqual | BGSSaveLoadGame.obj | fnv360_0822_retail, vtable, medium
// pdb params: key1, key2
int __stdcall FUN_00aa2f10(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    return a == c && b == d;
}
}   // namespace f3m_00aa2f10

// @f3 0x00aad2e0 (community match, verified in this file)
namespace f3m_00aad2e0 {
struct Object_aad2e0;
struct Table_aad2e0 {
    void* slot00; void* slot04; void* slot08; void* slot0c; void* slot10; void* slot14;
    void (__stdcall *slot18)(Object_aad2e0*, int);
};
struct Object_aad2e0 { Table_aad2e0* table; };
struct Owner_aad2e0 {
    Object_aad2e0* object;
    bool FUN_00aad2e0();
};
// pdb: BSOcclusionQuery::Begin | BSOcclusionQuery.obj | fnv360_0822_retail, call_gap, low
bool Owner_aad2e0::FUN_00aad2e0()
{
    if (DAT_0116d984)
        return false;
    DAT_0116d984 = true;
    object->table->slot18(object, 2);
    return true;
}
}   // namespace f3m_00aad2e0

// @f3 0x00ab7a00 (community match, verified in this file)
namespace f3m_00ab7a00 {
void __cdecl operator delete(void*, unsigned int);
struct State00ab7a00 {
    void FUN_00ab7600();
    State00ab7a00* FUN_00ab7a00(unsigned int flags);
};
// pdb: BSMasterParticleSystem::`scalar deleting destructor' | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, high
State00ab7a00* State00ab7a00::FUN_00ab7a00(unsigned int flags) {
    FUN_00ab7600();
    if (flags & 1)
        operator delete(this, 0xe0);
    return this;
}

}   // namespace f3m_00ab7a00

// @f3 0x00aa2350 (community match, verified in this file)
namespace f3m_00aa2350 {
struct Dispatch_aa2350 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    void FUN_0082db90(unsigned int, unsigned int);
    void FUN_00aa2350(unsigned int, unsigned int);
};
// pdb: BSMultiBoundNode::UpdateDownwardPass | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSMultiBoundRoom::UpdateDownwardPass)
// pdb params: UpdateData, uFlags
void Dispatch_aa2350::FUN_00aa2350(unsigned int first, unsigned int second)
{
    FUN_0082db90(first, second);
    slotbc();
}
}   // namespace f3m_00aa2350

// @f3 0x00ab03d0 (community match, verified in this file)
namespace f3m_00ab03d0 {
struct State00ab03d0 { void* FUN_00824a50(void*); };
namespace Globals00ab03d0 { extern void* DAT_0116da60; extern unsigned int DAT_0116da64; }
void* __cdecl FUN_00424d50(void*, void*);
// pdb: BSFurnitureMarker::Find | BSFurnitureMarker.obj | fnv360_0822_debug, udata, high
void* __cdecl BSFurnitureMarker_Find(State00ab03d0* state) {
    void* result = 0;
    if (state)
        result = FUN_00424d50(&Globals00ab03d0::DAT_0116da64, state->FUN_00824a50(Globals00ab03d0::DAT_0116da60));
    return result;
}
}   // namespace f3m_00ab03d0

// @f3 0x00ab0ef0 (community match, verified in this file)
namespace f3m_00ab0ef0 {
extern void* DAT_0116da80;
extern unsigned char DAT_0116da84;
struct Source_ab0ef0 { void* FUN_00824a50(void*); };
extern void* __cdecl FUN_00424d50(void*, void*);
// pdb: BSBound::Find | BSBound.obj | fnv360_0822_retail, udata, high
void* __cdecl BSBound_Find(Source_ab0ef0* source)
{
    void* result = 0;
    if (source)
        result = FUN_00424d50(&DAT_0116da84, source->FUN_00824a50(DAT_0116da80));
    return result;
}

}   // namespace f3m_00ab0ef0

// @f3 0x00aa9810 (community match, verified in this file)
namespace f3m_00aa9810 {
struct Input00aa9810 { float value; };
struct State00aa9810 {
    void FUN_00aa9660(float value);
    void FUN_0082e030(Input00aa9810* input, void* other);
    void FUN_00aa9810(Input00aa9810* input, void* other);
};
// pdb: BSTempNodeManager::UpdateRigidDownwardPass | BSTempNodeManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: UpdateData, uFlags
void State00aa9810::FUN_00aa9810(Input00aa9810* input, void* other) {
    FUN_00aa9660(input->value);
    FUN_0082e030(input, other);
}
}   // namespace f3m_00aa9810

// @f3 0x00aad2a0 (community match, verified in this file)
struct Target00aad2a0;
struct Table00aad2a0 {
    void* slot0;
    void* slot4;
    void* slot8;
    void* slotc;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1c;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2c;
    void* slot30;
    void* slot34;
    void* slot38;
    void* slot3c;
    void* slot40;
    void* slot44;
    void* slot48;
    void* slot4c;
    void* slot50;
    void* slot54;
    void* slot58;
    void* slot5c;
    void* slot60;
    void* slot64;
    void* slot68;
    void* slot6c;
    void* slot70;
    void* slot74;
    void* slot78;
    void* slot7c;
    void* slot80;
    void* slot84;
    void* slot88;
    void* slot8c;
    void* slot90;
    void* slot94;
    void* slot98;
    void* slot9c;
    void* slota0;
    void* slota4;
    void* slota8;
    void* slotac;
    void* slotb0;
    void* slotb4;
    void* slotb8;
    void* slotbc;
    void* slotc0;
    void* slotc4;
    void* slotc8;
    void* slotcc;
    void* slotd0;
    void* slotd4;
    void* slotd8;
    void* slotdc;
    void* slote0;
    void* slote4;
    void* slote8;
    void* slotec;
    void* slotf0;
    void* slotf4;
    void* slotf8;
    void* slotfc;
    void* slot100;
    void* slot104;
    void* slot108;
    void* slot10c;
    void* slot110;
    void* slot114;
    void* slot118;
    void* slot11c;
    void* slot120;
    void* slot124;
    void* slot128;
    void* slot12c;
    void* slot130;
    void* slot134;
    void* slot138;
    void* slot13c;
    void* slot140;
    void* slot144;
    void* slot148;
    void* slot14c;
    void* slot150;
    void* slot154;
    void* slot158;
    void* slot15c;
    void* slot160;
    void* slot164;
    void* slot168;
    void* slot16c;
    void* slot170;
    void* slot174;
    void* slot178;
    void* slot17c;
    void* slot180;
    void* slot184;
    void* slot188;
    void* slot18c;
    void* slot190;
    void* slot194;
    void* slot198;
    void* slot19c;
    void* slot1a0;
    void* slot1a4;
    void* slot1a8;
    void* slot1ac;
    void* slot1b0;
    void* slot1b4;
    void* slot1b8;
    void* slot1bc;
    void* slot1c0;
    void* slot1c4;
    void* slot1c8;
    void* slot1cc;
    void* slot1d0;
    void* slot1d4;
    void (__stdcall *registerCallback)(Target00aad2a0*, int, void*);
};
struct Target00aad2a0 { Table00aad2a0* table; };
struct Global00aad2a0 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    Target00aad2a0* target;
};
extern Global00aad2a0* DAT_0108f048;
struct State00aad2a0 {
    unsigned int value;
    State00aad2a0* FUN_00aad2a0();
};
// pdb: BSOcclusionQuery::BSOcclusionQuery | BSOcclusionQuery.obj | fnv360_0822_retail, call_gap, medium
State00aad2a0* State00aad2a0::FUN_00aad2a0() {
    value = 0;
    Target00aad2a0* target = DAT_0108f048->target;
    target->table->registerCallback(target, 9, this);
    return this;
}

// @f3 0x00aad330 (community match, verified in this file)
namespace f3m_00aad330 {
struct Object_aad330;
struct Table_aad330 {
    void* slot00; void* slot04; void* slot08; void* slot0c; void* slot10; void* slot14; void* slot18;
    int (__stdcall *slot1c)(Object_aad330*, void*, unsigned int, int);
};
struct Object_aad330 { Table_aad330* table; };
struct Owner_aad330 { Object_aad330* object; bool FUN_00aad330(void* value, bool enabled); };
// pdb: BSOcclusionQuery::GetResult | BSOcclusionQuery.obj | fnv360_0721_beta, call_seq, medium
// pdb params: pResult, bFlush
bool Owner_aad330::FUN_00aad330(void* value, bool enabled)
{
    int mode = 0;
    if (enabled)
        mode = 1;
    if (object->table->slot1c(object, value, 4, mode) == 0)
        return true;
    return false;
}
}   // namespace f3m_00aad330

// @f3 0x00ab5a70 (community match, verified in this file)
namespace f3m_00ab5a70 {
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(struct HKEY__*);
struct State00ab5a70 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    HKEY__* key;
    bool FUN_00ab5a70();
};
// pdb: RegSettingCollection::Close | XRegSetting.obj | fnv360_0822_debug, vtable, medium
bool State00ab5a70::FUN_00ab5a70() {
    bool result = true;
    if (key) {
        result = RegCloseKey(key) == 0;
        key = 0;
    }
    return result;
}



}   // namespace f3m_00ab5a70

// @f3 0x00aaae80 (community match, verified in this file)
struct LockObject_00aaae80 {
    long value;
    void __thiscall FUN_00409a80(int argument);
};

struct CounterObject_00aaae80 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    void __thiscall FUN_00aaab30();
    void __thiscall FUN_005574c0(int value);
};

extern LockObject_00aaae80 DAT_0116d740;
extern CounterObject_00aaae80 DAT_010667f0;
extern int DAT_0116d744;

typedef long (__stdcall *InterlockedCompareExchangeFn_00aaae80)(
    long* destination,
    long exchange,
    long comparand);

extern InterlockedCompareExchangeFn_00aaae80 DAT_00d9b06c;

// pdb: NiObjectGarbage::ClearAll | NiObjectGarbage.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void __cdecl NiObjectGarbage_ClearAll() {
    DAT_0116d740.FUN_00409a80(0);
    DAT_010667f0.FUN_00aaab30();

    if (DAT_010667f0.unk0A > 100) {
        DAT_010667f0.FUN_005574c0(100);
    }

    --DAT_0116d744;
    if (DAT_0116d744 == 0) {
        DAT_00d9b06c(&DAT_0116d740.value, 0, DAT_0116d740.value);
    }
}

// @f3 0x00aa15d0 (community match, verified in this file)
namespace f3m_00aa15d0 {
namespace task2926 {
void* FUN_0089eb90(unsigned);void FUN_0089ec10(void*,unsigned);
struct Point {float x,y,z;};
struct FUN_00aad5f0 {
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
virtual void vb8(const Point&);
int unk04,unk08;Point pos,other;FUN_00aad5f0();};
struct Object:FUN_00aad5f0 {virtual void v00();static void*operator new(unsigned n){return FUN_0089eb90(n);}static void operator delete(void*p,unsigned n){FUN_0089ec10(p,n);}Object(){}void BSMultiBoundShape_CopyMembers(Object*,int);Object* FUN_00aa15d0(int);};
// pdb: BSMultiBoundAABB::CreateClone | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: arCloneData
Object* Object::FUN_00aa15d0(int context){Object*p=new Object;BSMultiBoundShape_CopyMembers(p,context);p->vb8(pos);p->other=other;return p;}
}
}   // namespace f3m_00aa15d0

// @f3 0x00aae130 (community match, verified in this file)
namespace f3aae130 {
struct Heap { void* FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
struct FUN_0082ea60 {
 virtual ~FUN_0082ea60();
 FUN_0082ea60(unsigned int);
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
unsigned int flags;
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
};
struct Descriptor {
 virtual ~Descriptor();
 void* data;
 unsigned int size,capacity;
 Descriptor():data(0),size(0),capacity(0) {}
};
struct FUN_00aa8410 {
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
FUN_00aa8410();
 static void* operator new(unsigned int n) { return DAT_01090a78.FUN_0086b930(n); }
 static void operator delete(void*);
};
struct FUN_00aae130: FUN_0082ea60 {
 FUN_00aa8410* child;
 Descriptor descriptor;
 int value;
 virtual ~FUN_00aae130();
 FUN_00aae130(int);
};
// pdb: BSPortalSharedNode::BSPortalSharedNode | BSPortal.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apPortal
FUN_00aae130::FUN_00aae130(int input):FUN_0082ea60(0) {
 child=new FUN_00aa8410;
 flags |= 0x800;
 value=input;
}
}

// @f3 0x00ab6440 (community match, verified in this file)
namespace f3m_00ab6440 {
namespace task2925 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_00ac5e10 {
 FUN_00ac5e10();
 virtual void slot00();
 int unk04,unk08,unk0C,unk10,unk14;
};
struct Scalar { float value; Scalar& operator=(float v) { value=v;return *this; } };
struct Object : FUN_00ac5e10 {
 virtual void slot00();
 Scalar value18,value1C,value20,value24,value28,value2C,value30,value34,value38,value3C,value40,value44;
 int unk48,unk4C,unk50,unk54,unk58,unk5C;
 static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
 Object() { value18=0.0f;value1C=0.0f;value20=0.0f;value24=0.0f;value28=0.0f;value2C=0.0f;value30=0.0f;value34=0.0f;value38=0.0f;value3C=0.0f;value40=0.0f;value44=0.0f; }
};
struct Host {
 void FUN_00ab61a0(Object*,int);
 Object* FUN_00ab6440(int argument);
};
// pdb: BSPSysSimpleColorModifier::CreateClone | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCloning
Object* Host::FUN_00ab6440(int argument) {
 Object* p=new Object;
 FUN_00ab61a0(p,argument);
 return p;
}
}
}   // namespace f3m_00ab6440

// @f3 0x00aa50d0 (community match, verified in this file)
namespace f3m_00aa50d0 {
namespace f3_2937 {
struct Item { void FUN_00aa4df0(int); };
struct Group {
 unsigned int unk00;
 Item** items;
 unsigned int count;
 unsigned int active;
 void Clear(){
  unsigned int i;
  active=0;
  for(i=0;i<count;++i) items[i]->FUN_00aa4df0(0);
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
 Group* group;
 void FUN_00aa41f0();
 void FUN_00aa50d0();
};
// pdb: IOManager::CancelAllTasks | IOManager.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: LockFreeMap<__int64,class NiPointer<class BSTask> >::SetAt)
void Owner::FUN_00aa50d0(){FUN_00aa41f0();group->Clear();}
}
}   // namespace f3m_00aa50d0

// @f3 0x00aa5dc0 (community match, verified in this file)
namespace f3m_00aa5dc0 {

extern void* DAT_0116d498;
extern void* DAT_0116d880;

void FUN_00c007fc(void* a, unsigned int b, void* c);
void FUN_00c00fcc(void* a, unsigned int b, void* c);

// pdb: MessageHandler::SetProgramFlowFileName | MessageHandler.obj | fnv360_0721_retail, objrun, medium
// pdb params: apFileName
void __cdecl FUN_00aa5dc0(void* param_1)
{
    FUN_00c007fc(&DAT_0116d498, 0x104, &DAT_0116d880);
    FUN_00c00fcc(&DAT_0116d498, 0x104, param_1);
}
}   // namespace f3m_00aa5dc0

// @f3 0x00ab5db0 (community match, verified in this file)
extern char DAT_00e8b28c;
namespace f3m_00ab5db0 {
void __cdecl operator delete(void*, unsigned int);
struct State00ab5db0 {
    void* table;
    void FUN_0082e4f0();
    State00ab5db0* FUN_00ab5db0(unsigned int flags);
};
// pdb: BSNiNode::`scalar deleting destructor' | BSNiNode.obj | fnv360_0822_retail, vtable, high
State00ab5db0* State00ab5db0::FUN_00ab5db0(unsigned int flags) {
    table = &DAT_00e8b28c;
    FUN_0082e4f0();
    if (flags & 1)
        operator delete(this, 0xac);
    return this;
}

}   // namespace f3m_00ab5db0

// @f3 0x00aa6910 (community match, verified in this file)
namespace f3m_00aa6910 {
struct Object_aa6910 {
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
    void FUN_0082b4a0();
    void FUN_0082bd90();
    void BSStream_FreeAllObjects();
};
// pdb: BSStream::FreeAllObjects | BSStream.obj | fnv360_0822_retail, call_gap + skyrim(caller_sim), high
void Object_aa6910::BSStream_FreeAllObjects()
{
    FUN_0082b4a0();
    unk25c = 0;
    unk26c = 0;
    unk260 = 0;
    unk270 = 0;
    FUN_0082bd90();
}
}   // namespace f3m_00aa6910

// @f3 0x00aac030 (community match, verified in this file)
namespace f3m_00aac030 {
namespace f3m_00aac030 {
namespace fo3_aac030 {

struct Vertex { float x, y, z; };
struct Data { int m_00; Vertex* m_04; };
struct Polygon {
    Data* m_00;
    int pad[8];
    int m_24;
    void FUN_00aac030();
};

// pdb: BSPolygon2D::RemoveZ | BSPolygon.obj | fnv360_0822_retail, call_gap_sim, low
void Polygon::FUN_00aac030()
{
    for (int i = 0; i < m_24; i++) {
        Vertex* p = &m_00->m_04[i];
        Vertex tmp = *p;
        tmp.z = 0.0f;
        *p = tmp;
    }
}

}
}
}   // namespace f3m_00aac030

// @f3 0x00aa8280 (community match, verified in this file)
namespace f3m_00aa8280 {
struct ArrA;
struct ArrB;
extern int DAT_00e89ed0;
extern int DAT_00e89ebc;
extern void (__thiscall* DAT_00e89ed8)(ArrA*, void*);
extern void (__thiscall* DAT_00e89ec4)(ArrB*, void*);
struct ArrA {
    virtual void v00();
    virtual void v04();
    virtual void Release(void* p);
    void* data;
    unsigned int size;
    unsigned int capacity;
    void RemoveAll() {
        if (data) {
            Release(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    ~ArrA() {
        *(void**)this = &DAT_00e89ed0;
        if (data) {
            DAT_00e89ed8(this, data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
};
struct ArrB {
    virtual void v00();
    virtual void v04();
    virtual void Release(void* p);
    void* data;
    unsigned int size;
    unsigned int capacity;
    void RemoveAll() {
        if (data) {
            Release(data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
    ~ArrB() {
        *(void**)this = &DAT_00e89ebc;
        if (data) {
            DAT_00e89ec4(this, data);
            data = 0;
            capacity = 0;
            size = 0;
        }
    }
};
}
struct FUN_00aa8280 {
    int unk00;
    f3m_00aa8280::ArrA a;
    f3m_00aa8280::ArrB b;
    ~FUN_00aa8280();
};
// pdb: BSCompoundFrustum::~BSCompoundFrustum | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSTArray<class BSTEventSink<struct Pickpocket::Event> *,class BSTArrayHeapAllocator>::Clear)
FUN_00aa8280::~FUN_00aa8280()
{
    a.RemoveAll();
    b.RemoveAll();
}

// @f3 0x00aa25b0 (community match, verified in this file)
extern unsigned char DAT_0116d134;
namespace f3m_00aa25b0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);


struct Sem25B0 {
    volatile long count;
    void* semaphore;
    void Lock() {
        WaitForSingleObject(semaphore, 0xffffffff);
        InterlockedDecrement(&count);
    }
    void Unlock() {
        ReleaseSemaphore(semaphore, 1, 0);
        InterlockedIncrement(&count);
    }
};

struct Worker25B0 {
    void* vtable;
    int unk04;
    int unk08;
    Sem25B0 wake;
    int unk14;
    Sem25B0 lock;
    int unk20;
    Worker25B0* owner;
};

struct Pool25B0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    volatile long count20;
    volatile long count24;
    unsigned workers;
    Worker25B0** threads;
    bool FUN_00aa25b0();
};

// pdb: BSTaskManager<__int64>::Pause | IOManager.obj | fnv360_0822_retail, udata, high
bool Pool25B0::FUN_00aa25b0()
{
    DAT_0116d134 = 0;
    if (InterlockedIncrement(&count24) == 1) {
        while (count20)
            Sleep(1);
        for (unsigned i = 0; i < workers; i++) {
            Worker25B0* w = threads[i];
            if (w->wake.count == 0)
                w->wake.Unlock();
            w->lock.Lock();
            InterlockedIncrement(&count20);
        }
        return true;
    }
    return false;
}
}   // namespace f3m_00aa25b0

// @f3 0x00aa7b30 (community match, verified in this file)
namespace f3m_00aa7b30 {
struct FUN_00aa7b30_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct FUN_00aa7b30_Container
{
    FUN_00aa7b30_Entry entries[6];
    unsigned int flags;
};

struct FUN_00aa7b30_Manager
{
    int method(FUN_00aa7b30_Entry* entry);
};

// pdb: BSCompoundFrustum::TestIntersection | BSCompoundFrustum.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apBound, apPlanes
char __stdcall FUN_00aa7b30(FUN_00aa7b30_Manager* manager, FUN_00aa7b30_Container* container)
{
    if (!container->flags)
        return 1;

    int i;
    for (i = 0; i < 6; ++i)
    {
        unsigned int flags = container->flags;
        unsigned int mask = 1u << i;
        if (flags & mask)
        {
            int result = manager->method(&container->entries[i]);
            if (result == 2)
                break;
            if (result == 1)
                container->flags = flags & ~mask;
        }
    }
    return i == 6;
}
}   // namespace f3m_00aa7b30

// @f3 0x00aa23b0 (community match, verified in this file)
namespace f3m_00aa23b0 {
namespace f3m_00aa23b0 {
struct Node { Node* next; Node* prev; void* data; };
struct Allocator { unsigned int count; Node* FUN_00423640(); };
struct Obj {
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
    Node* head;
    Node* tail;
    Allocator alloc;
    void AddNodeTail(Node* p) {
        p->next = 0;
        p->prev = tail;
        if (tail)
            tail->next = p;
        else
            head = p;
        tail = p;
        alloc.count++;
    }
    void FUN_00aa23b0(void* elem);
};
void Obj::FUN_00aa23b0(void* elem)
{
    if (!elem)
        return;
    Node* p = alloc.FUN_00423640();
    p->data = elem;
    AddNodeTail(p);
}
}
}   // namespace f3m_00aa23b0

// @f3 0x00aab2c0 (community match, verified in this file)
namespace f3m_00aab2c0 {
class S_aab2c0
{
public:
    virtual ~S_aab2c0();
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
    unsigned int flags;
    void FUN_0082e030(int a, int b);
    void FUN_00aab2c0(int a, int b);
};

// pdb: BSDamageStage::UpdateRigidDownwardPass | BSDamageStage1.obj | fnv360_0822_retail, vtable, medium
// pdb params: UpdateData, uFlags
void S_aab2c0::FUN_00aab2c0(int a, int b)
{
    if (flags & 1) return;
    FUN_0082e030(a, b);
}
}   // namespace f3m_00aab2c0

// @f3 0x00aa70b0 (community match, verified in this file)
namespace f3m_00aa70b0 {
struct Block36 { int a0, a1, a2, a3, a4, a5, a6, a7, a8; };
extern Block36 DAT_00f72574;
struct Obj {
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
    Block36 block;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    unsigned char flags;
    void FUN_00833110(int arg);
    void FUN_00aa70b0(int arg);
};
// pdb: BSValueNode::UpdateWorldData | BSValueNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: UpdateData
void Obj::FUN_00aa70b0(int arg)
{
    FUN_00833110(arg);
    if (flags & 1)
        block = DAT_00f72574;
}
}

// @f3 0x00ab40b0 (community match, verified in this file)
namespace f3m_00ab40b0 {
namespace f3m_00ab40b0 {
struct Node { Node* next; Node* prev; void* data; };
struct Allocator { unsigned int count; Node* FUN_00423640(); };
struct Obj {
    int unk00, unk04;
    Node* head;
    Node* tail;
    Allocator alloc;
    void AddNodeTail(Node* p) {
        p->next = 0;
        p->prev = tail;
        if (tail)
            tail->next = p;
        else
            head = p;
        tail = p;
        alloc.count++;
    }
    void FUN_00ab40b0(void* elem);
};
// pdb: BSPortalGraph::AddOccluder | BSPortalGraph.obj | fnv360_0721_beta, caller, medium
// pdb params: apOccluder
void Obj::FUN_00ab40b0(void* elem)
{
    if (!elem)
        return;
    Node* p = alloc.FUN_00423640();
    p->data = elem;
    AddNodeTail(p);
}
}
}   // namespace f3m_00ab40b0

// @f3 0x00ab8af0 (community match, verified in this file)
namespace f3m_00ab8af0 {
class C_00ab8af0 {
public:
    void FUN_00ab8a10(int, int);
    void FUN_00ab8af0(int a, int b, int c);
};

// pdb: BSPSysArrayEmitter::ComputeVolumeInitialPositionAndVelocity | BSPSysArrayEmitter.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: NiPSysVolumeEmitter::~NiPSysVolumeEmitter)
// pdb params: arEmitterToPSys, arPosition, arVelocity
void C_00ab8af0::FUN_00ab8af0(int a, int b, int c)
{
    FUN_00ab8a10(b, c);
}
}   // namespace f3m_00ab8af0

// @f3 0x00ab8e60 (community match, verified in this file)
namespace f3m_00ab8e60 {
struct C00ab8e60 {
    void FUN_00ab8dc0();
    void FUN_0078c030(void* a);
    void FUN_00ab8e60(void* a);
};

// pdb: BSPSysArrayEmitter::PostLinkObject | BSPSysArrayEmitter.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSSegmentedTriShape::RenderImmediate)
// pdb params: arStream
void C00ab8e60::FUN_00ab8e60(void* a)
{
    FUN_00ab8dc0();
    FUN_0078c030(a);
}
}   // namespace f3m_00ab8e60

// @f3 0x00aa5e20 (community match, verified in this file)
#include <string.h>
extern char DAT_0116d288[];
namespace f3m_00aa5e20 {
// pdb: MessageHandler::SetCrashTraceFileName | MessageHandler.obj | fnv360_0721_retail, objrun, medium
// pdb params: apFileName
int __cdecl FUN_00aa5e20(const char* suffix)
{
    strcpy_s(DAT_0116d288, 260, DAT_0116d880);
    return strcat_s(DAT_0116d288, 260, suffix);
}
}   // namespace f3m_00aa5e20

// @f3 0x00ab51d0 (community match, verified in this file)
namespace f3m_00ab51d0 {
extern char DAT_00e8b034;
void __cdecl operator delete(void*, unsigned int);
struct State00ab51d0 {
    void* table;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int value;
    void FUN_00ab4cd0();
    State00ab51d0* FUN_00ab51d0(unsigned int flags);
};
// pdb: BSPSysMultiTargetEmitterCtlr::`scalar deleting destructor' | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable, high
State00ab51d0* State00ab51d0::FUN_00ab51d0(unsigned int flags) {
    table = &DAT_00e8b034;
    value = 0;
    FUN_00ab4cd0();
    if (flags & 1) operator delete(this, 0x64);
    return this;
}

}   // namespace f3m_00ab51d0

// @f3 0x00aa9840 (community match, verified in this file)
namespace f3m_00aa9840 {
struct Node_aa9840 {
    void* table;
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
    unsigned char flagac, flagad, flagae, flagaf;
    void FUN_00ab5d60();
    Node_aa9840* FUN_00aa9840();
};
// pdb: BSRangeNode::BSRangeNode | BSRangeNode.obj | fnv360_0822_retail, call_seq, medium
Node_aa9840* Node_aa9840::FUN_00aa9840()
{
    FUN_00ab5d60();
    flagae = 0;
    flagad = 0;
    table = &DAT_00e89f04;
    flagaf = 0xff;
    flagac = 1;
    return this;
}
}   // namespace f3m_00aa9840

// @f3 0x00aae770 (community match, verified in this file)
namespace f3m_00aae770 {
struct Reference00aae770 {
    virtual void Reserved();
    virtual void Destroy();
    volatile long references;
};
// pdb: BSParticleSystemManager::DetachChildAt | BSParticleSystemManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: i, aspAVObject
void __stdcall FUN_00aae770(void* unused, Reference00aae770** slot) {
    Reference00aae770* value = *slot;
    if (value) {
        if (InterlockedDecrement(&value->references) == 0)
            value->Destroy();
        *slot = 0;
    }
}
}   // namespace f3m_00aae770

// @f3 0x00aa6560 (community match, verified in this file)
extern char DAT_00e89a64;
namespace f3m_00aa6560 {
extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct State00aa6560 {
    void* table;
    void* thread;
    unsigned int unk08, unk0c;
    void* handle10;
    unsigned int unk14, unk18;
    void* handle1c;
    void FUN_00aa6560();
};
// pdb: BSTaskThread::~BSTaskThread | BSTaskManager_Xenon.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: TESModelDB::TESQueuedHandles::TESQueuedHandles)
void State00aa6560::FUN_00aa6560() {
    table = &DAT_00e89a64;
    SuspendThread(thread);
    CloseHandle(thread);
    CloseHandle(handle1c);
    CloseHandle(handle10);
}

}   // namespace f3m_00aa6560

// @f3 0x00ab8ab0 (community match, verified in this file)
namespace f3m_00ab8ab0 {
struct State00ab8ab0 {
    unsigned int unk00, unk04;
    unsigned short capacity, size, unk0c, growth;
    void FUN_00ab8130(unsigned int capacity);
    void FUN_00ab87c0(unsigned int index, void* value);
    unsigned int FUN_00ab8ab0(void* value);
};
// pdb: NiTArray<NiPointer<NiAVObject>,NiTMallocInterface<NiPointer<NiAVObject> > >::Add | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: BSPSysArrayEmitter::CreateObject)
// pdb params: element
unsigned int State00ab8ab0::FUN_00ab8ab0(void* value) {
    unsigned int index = size;
    if (index >= capacity)
        FUN_00ab8130(index + growth);
    FUN_00ab87c0(index, value);
    return index;
}
}   // namespace f3m_00ab8ab0

// @f3 0x00aa39f0 (community match, verified in this file)
namespace f3m_00aa39f0 {
struct Lock;

struct Node
{
    int unk00;
    int unk04;
    int unk08;
    volatile int flags;
};

class C
{
public:
    void* unk00;
    int* unk04;
    int* unk08;
    int* unk0c;
    void* unk10;
    unsigned int unk14;
    int unk18;
    bool FUN_00aa31d0(int a, int b, int c);
    bool FUN_00aa39f0(int a, int b, int c, Lock* d);
};

struct Lock
{
    void LockIt(void* p);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::GetAt | IOManager.obj | fnv360_0822_debug, call_seq, medium
// pdb params: aKey, arData
bool C::FUN_00aa39f0(int a, int b, int c, Lock* d)
{
    bool ok = FUN_00aa31d0(a, b, c);
    if (ok) {
        d->LockIt((void*)((unk14 & ~1) + 8));
        Node* node = (Node*)(unk14 & ~1);
        if (node->flags & 1)
            ok = false;
    }
    *unk04 = 0;
    *unk08 = 0;
    *unk0c = 0;
    return ok;
}
}   // namespace f3m_00aa39f0

// @f3 0x00aa2d10 (community match, verified in this file)
namespace f3m_00aa2d10 {
namespace task2938 {
struct Shape {virtual ~Shape();};
struct Heap {void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct FUN_00aa2d10 {virtual ~FUN_00aa2d10();Shape** data;unsigned count;};
// pdb: LockFreePriorityQueue<NiPointer<IOTask> >::~LockFreePriorityQueue<NiPointer<IOTask> > | IOManager.obj | fnv360_0822_retail, call_seq, high
FUN_00aa2d10::~FUN_00aa2d10(){for(unsigned i=0;i<count;++i)delete data[i];DAT_01090a78.FUN_0086ba60(data);}
}
}   // namespace f3m_00aa2d10

// @f3 0x00aaa400 (community match, verified in this file)
namespace f3m_00aaa400 {
namespace task2943 {
struct UpdateContext {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c;
 int state;
};
struct BoundBase {
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
 virtual bool Test(void*);
};
struct BoundTester : BoundBase {
 int unk04;
 int state;
};
struct BoundReference { int unk00,unk04,unk08; BoundTester* object; };
struct UpdateChild { void FUN_00826660(UpdateContext*); };
struct UpdateOwner {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
 UpdateChild** children;
 unsigned short capacity,count,enabled,unkAA;
 BoundReference* reference;
 int replacement;
 void FUN_00aaa400(UpdateContext*);
};
// @fnv 0x00c46f60
// pdb: BSMultiBoundNode::OnVisible | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: kCuller
void UpdateOwner::FUN_00aaa400(UpdateContext* pContext) {
 UpdateChild** slot;
 int replacementState2;
 BoundTester* cacheObject5;
 BoundReference* cacheReference;
 BoundTester* _unknownObject;
 BoundReference* unknownReference;
 BoundTester* specialObject2;
 BoundReference* specialReference6;
 int kRequestState;
 BoundTester* aReadObject;
 BoundReference* readReference8;
 BoundReference* checkReference;
 UpdateChild* child;
 unsigned int i;
 int state2;
 bool accepted9;
 int oldState9;
 UpdateContext* context4;

 context4=0;
 oldState9=0;
 if (!enabled) return;
 context4=pContext;
 oldState9=context4->state;
 accepted9=true;
 if (oldState9!=3 && oldState9!=1) {
  checkReference=reference;
  if (checkReference) {
   readReference8=reference;
   aReadObject=readReference8->object;
   state2=aReadObject->state;
   kRequestState=context4->state;
   if (kRequestState==4) {
    specialReference6=reference;
    specialObject2=specialReference6->object;
    accepted9=specialObject2->Test(reinterpret_cast<char*>(pContext)+0x2c);
    state2=accepted9?1:2;
   }
   switch(state2) {
   case 0:
    unknownReference=reference;
    _unknownObject=unknownReference->object;
    accepted9=_unknownObject->Test(reinterpret_cast<char*>(pContext)+0x2c);
    cacheReference=reference;
    cacheObject5=cacheReference->object;
    cacheObject5->state=accepted9?1:2;
    break;
   case 1: accepted9=true;break;
   default:accepted9=false;break;
   }
  }
 }
 if (!accepted9) return;
 if (oldState9!=3) {
  replacementState2=replacement;
  context4->state=replacementState2;
 }
 for (i=0;i<count;i++) {
  slot=&children[i];
  child=*slot;
  if (child) child->FUN_00826660(pContext);
 }
 context4->state=oldState9;
}


}
}   // namespace f3m_00aaa400

// @f3 0x00aaa790 (community match, verified in this file)
extern const char* DAT_0116d718;
namespace f3m_00aaa790 {
namespace Task2946 {
struct Array {void* vtable;char** data;unsigned short capacity,count,used,grow;void FUN_00555790(unsigned);void FUN_005b3880(unsigned,char* const&);void add(char* const& value){unsigned i=count;if(i>=capacity)FUN_00555790(i+grow);FUN_005b3880(i,value);}};
char* __cdecl FUN_00847b50(const char*);
char* __cdecl FUN_00847e70(const char*,const char*);
struct Viewed {
 virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual void v48();virtual void v4c();virtual void v50();virtual void v54();virtual void v58();virtual void v5c();virtual void view(Array*);
};
struct Holder {char pad[12];Viewed* object;};
struct Owner {char pad[0xac];Holder* holder;unsigned mode;void FUN_0082ee90(Array*);void FUN_00aaa790(Array*);};
// pdb: BSMultiBoundNode::GetViewerStrings | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void Owner::FUN_00aaa790(Array* arr){
 FUN_0082ee90(arr);
 arr->add(FUN_00847b50(DAT_0116d718));
 arr->add(FUN_00847e70("cull mode",mode==0?"NORMAL":mode==1?"ALLPASS":"ALLFAIL"));
 if(holder){Viewed* object=holder->object;if(object)object->view(arr);}
}
}

}   // namespace f3m_00aaa790

// @f3 0x00aaa580 (community match, verified in this file)
namespace Task2984 {
struct Point {float x,y,z;};
struct Bound {Point center;float radius;void FUN_0084a3a0(const Bound&);};
extern Bound DAT_0108edc8;extern Point DAT_0108ec68;
struct Heap{void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;
struct Provider{
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
virtual void GetBound(Bound&);
};
struct Controller{int unk00,unk04,unk08;Provider* provider;};
struct Link{Link* next;int unk04;Controller* controller;};
struct Node{
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
virtual void SetBound(Bound*);
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
Bound* bound;int unk24,unk28,unk2c;unsigned flags;
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
Node** children;unsigned short capacity,size,used,grow;Controller* controller;
int unkb0;
int unkb4;
int unkb8;
int unkbc;
int unkc0;
int unkc4;
int unkc8;
int unkcc;
Link* head;int unkD4;unsigned count;
void FUN_004d3210();
unsigned char Flag(){return static_cast<unsigned char>(flags>>19)&1;}
void FUN_00aaa580();
};
// pdb: BSMultiBoundNode::UpdateWorldBound | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
void Node::FUN_00aaa580()
{
    const Bound* a0;
    float aAcoustic;
    Node** aATmp;
    Bound* a2;
    float aAction;
    const Bound* aA6;
    int a114;
    int a3;
    int aActorList;
    float aActive;
    Node** aAct;
    Bound* a4;
    Provider* a2_3;
    Controller* a1c8;
    Controller** aAVal;
    Link* aAB;
    int aAEPos;
    int a60;
    int a5;
    Provider* aA3;
    Controller* aAX;
    Controller* a9;
    Node* a7;
    unsigned int a8;
    unsigned int aA5;
    Bound aA;
    Link* aA2;
    Provider* aAa;
    bool first;
    first = true;
    a9 = controller;
    if (a9)
    {
        aAX = controller;
        aA3 = aAX->provider;
        aAa = aA3;
        if (aAa)
        {
            FUN_004d3210();
            aAa->GetBound(*bound);
            return;
            first = false;
        }
    }
    if (first)
    {
        if (bound && Flag())
        {
            a4 = bound;
            a4->radius = 0.0f;
        }
        a8 = size;
        for (aA5 = 0; aA5 < a8; ++aA5)
        {
            aAct = &children[aA5];
            a7 = *aAct;
            if (a7 && ((a7->bound && ((aActive = a7->bound->radius), (double)aActive != 0.0)) ? 1 : 0))
            {
                if (!bound) {
 Bound* allocated=(Bound*)DAT_01090a78.FUN_0086b930(sizeof(Bound));
 SetBound(allocated);Bound* dest=bound;dest->center=DAT_0108ec68;dest->radius=0.0f;
}
                aA6 = a7->bound ? a7->bound : &DAT_0108edc8;
                a2 = bound;
                aAction = aA6->radius;
                a2->center = aA6->center;
                a2->radius = aAction;
                ++aA5;
                break;
            }
        }
        for (; aA5 < a8; ++aA5)
        {
            aATmp = &children[aA5];
            a7 = *aATmp;
            if (a7 && ((a7->bound && ((aAcoustic = a7->bound->radius), (double)aAcoustic != 0.0)) ? 1 : 0))
            {
                a0 = a7->bound ? a7->bound : &DAT_0108edc8;
                bound->FUN_0084a3a0(*a0);
            }
        }
    }
}

}

// @f3 0x00aa5a60 (community match, verified in this file)
namespace naa5a60 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
struct RefObj {
    virtual ~RefObj();
    int m04;
    long refs;
    __forceinline void IncRef() { InterlockedIncrement(&refs); }
    __forceinline void DecRef() { if (InterlockedDecrement(&refs) == 0) delete this; }
};
template <class T> struct Ptr {
    T* obj;
    __forceinline Ptr& operator=(T* p) {
        if (obj != p) {
            if (obj) obj->DecRef();
            obj = p;
            if (obj) obj->IncRef();
        }
        return *this;
    }
};
struct List {
    virtual ~List();
    RefObj** data;
    unsigned int count;
    void FUN_00aa5810(unsigned int index, int flag);
};
struct Mgr {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40();
    virtual void Queue(void* p);
    void FUN_00427340(RefObj* item, void* owner);
};
extern Mgr* DAT_0116d138;
struct Task : RefObj {
    long state;
    int m10, m14, m18;
    Ptr<RefObj> current;
    List* children;
    List* pending;
    void FUN_00aa5a60(long newState, RefObj* p);
};
}
// pdb: QueuedFile::Cancel | QueuedFiles.obj | fnv360_0822_retail, vtable, medium
// pdb params: aePreviousState, apTaskOwner
void naa5a60::Task::FUN_00aa5a60(long newState, RefObj* p)
{
    IncRef();
    if (p) {
        if (current.obj == p) {
            current = 0;
        } else if (pending) {
            for (unsigned int i = 0; i < pending->count; i++) {
                if (pending->data[i] == p) {
                    pending->FUN_00aa5810(i, 1);
                    break;
                }
            }
            if (pending->count == 0) {
                delete pending;
                pending = 0;
            }
        }
    } else {
        current = 0;
        if (pending)
            delete pending;
        pending = 0;
    }
    if (!current.obj && !pending) {
        if (children) {
            unsigned int n = children->count;
            for (unsigned int i = 0; i < n; i++) {
                RefObj* c = children->data[i];
                if (c)
                    DAT_0116d138->FUN_00427340(c, this);
            }
        }
    } else if (newState == 1) {
        DAT_0116d138->Queue(this);
    } else {
        InterlockedCompareExchange(&state, newState, state);
    }
    DecRef();
}

// @f3 0x00aae960 (community match, verified in this file)
namespace f3m_00aae960 {

void operator delete(void* memory, unsigned int size);

struct FUN_00aae960_shell {
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
    void FUN_00aae5e0();
    void* FUN_00aae960(unsigned int flags);
};

// pdb: BSParticleSystemManager::`scalar deleting destructor' | BSParticleSystemManager.obj | fnv360_0822_retail, vtable, high
void* FUN_00aae960_shell::FUN_00aae960(unsigned int flags)
{
    FUN_00aae5e0();
    if (flags & 1) {
        operator delete(this, 0xb8);
    }
    return this;
}
}   // namespace f3m_00aae960

// @f3 0x00ab4120 (community match, verified in this file)
namespace f3m_00ab4120 {
namespace Unique3001 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer(const NiPointer<T>& other)
    {
        m_pObject = other.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    NiPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiPointer<T>& operator=(const NiPointer<T>& other)
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
    bool operator==(T* object) const
    {
        return m_pObject == object;
    }
    bool operator==(const NiPointer<T>& other) const
    {
        return m_pObject == other.m_pObject;
    }
    bool operator!=(const NiPointer<T>& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

struct RefQ
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct ItemQ
{
    ItemQ* m_pkNext;
    ItemQ* m_pkPrev;
    T m_element;
};
template <class T> struct AllocQ {unsigned int count;ItemQ<T>* FUN_00423640();};
template <class T> struct PtrListQ
{
    ItemQ<T>* m_pkHead;
    ItemQ<T>* m_pkTail;
    AllocQ<T> allocator;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((ItemQ<T>*)pos)->m_element;
        pos = ((ItemQ<T>*)pos)->m_pkNext;
        return e;
    }
    void* FindPos(const T& val, void* pos = 0) const
    {
        if (pos == 0)
            pos = GetHeadPos();
        while (pos)
        {
            void* pkFound = pos;
            if (val == GetNext(pos))
                return pkFound;
        }
        return 0;
    }
    __declspec(noinline) void FUN_00827100(const T& item) {
ItemQ<T>* node=allocator.FUN_00423640();
node->m_element=item;
node->m_pkNext=0;node->m_pkPrev=m_pkTail;
if(m_pkTail)m_pkTail->m_pkNext=node;else m_pkHead=node;
++allocator.count;m_pkTail=node;
}
};
struct FUN_00ab4120_cls
{
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    PtrListQ<NiPointer<RefQ> > m_kNode;
    void __thiscall FUN_00ab4120(RefQ* pObj);
};
// @fnv 0x00c5aef0
// pdb: BSPortalGraph::AddRoom | BSPortalGraph.obj | fnv360_0721_beta, objrun, medium
// pdb params: apRoom
void __thiscall FUN_00ab4120_cls::FUN_00ab4120(RefQ* pObj)
{
    if (pObj)
    {
        if (!m_kNode.FindPos(pObj))
        {
            m_kNode.FUN_00827100(pObj);
        }
    }
}
}  // namespace fnv_00c5aef0
}   // namespace f3m_00ab4120

// @f3 0x00ab7400 (community match, verified in this file)
namespace f3m_00ab7400 {
struct Array00ab7400 {
    void* table;
    void** values;
    unsigned short capacity, size, effective, grow;
};
struct State00ab7400 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    Array00ab7400 array;

    void FUN_00ab7400();
};
void __stdcall FUN_00ab7180(State00ab7400*, Array00ab7400*);
// pdb: BSMasterParticleSystem::UpdateParticleSystemList | BSMasterParticleSystem.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BSMasterParticleSystem::AddEmitterObj)
void State00ab7400::FUN_00ab7400() {
    Array00ab7400& local = array;
    for (unsigned short i = 0; i < local.size; ++i)
        local.values[i] = 0;
    local.size = 0;
    local.effective = 0;
    FUN_00ab7180(this, &local);
}
}   // namespace f3m_00ab7400

// @f3 0x00ab42a0 (community match, verified in this file)
namespace f3m_00ab42a0 {
struct Node00ab42a0 { Node00ab42a0* next; Node00ab42a0* previous; void* value; };
struct Alloc00ab42a0 { unsigned int count; Node00ab42a0* FUN_00423640(); };
struct State00ab42a0 {
    unsigned int unk00,unk04,unk08,unk0c,unk10;
    Node00ab42a0* head;
    Node00ab42a0* tail;
    Alloc00ab42a0 allocator;
    void FUN_00ab42a0(void* value);
};
// pdb: BSPortalGraph::AddPortal | BSPortalGraph.obj | fnv360_0822_debug, objrun, medium
// pdb params: apPortal
void State00ab42a0::FUN_00ab42a0(void* value) {
    if (!value) return;
    Node00ab42a0* node = allocator.FUN_00423640();
    node->value = value;
    node->next = 0;
    node->previous = tail;
    if (tail) tail->next = node;
    else head = node;
    ++allocator.count;
    tail = node;
}
}   // namespace f3m_00ab42a0

// @f3 0x00aa7420 (community match, verified in this file)
#include <string.h>
namespace f3m_00aa7420 {
struct Setting00aa7420 {
    unsigned int unk00, unk04;
    const char* name;
};
// pdb: INISettingCollection::SubKey | XINISetting.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_dedup), high
void __cdecl INISettingCollection_SubKey(Setting00aa7420* setting, char* key) {
    if (!key) return;
    key[0] = 0;
    const char* name = setting->name;
    if (name) {
        const char* separator = strchr(name, ':');
        size_t length = separator ? static_cast<size_t>(separator - name) : strlen(name);
        strncpy_s(key, length + 1, name, length);
        key[length] = 0;
    }
}
}   // namespace f3m_00aa7420

// @f3 0x00aa6fb0 (community match, verified in this file)
namespace f3m_00aa6fb0 {
struct NiMemObject
{
    static void operator delete(void*, unsigned int);
};

struct Base_aa6fb0 : NiMemObject
{
    ~Base_aa6fb0();
};

struct FUN_00aa6fb0 : Base_aa6fb0
{
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
    virtual ~FUN_00aa6fb0();
};

FUN_00aa6fb0::~FUN_00aa6fb0()
{
    Base_aa6fb0::~Base_aa6fb0();
}
}   // namespace f3m_00aa6fb0

// @f3 0x00aa85b0 (community match, verified in this file)
namespace f3m_00aa85b0 {
namespace f3m_00aa85b0 {
struct NavEntryItem
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60;
};
struct Elem
{
    int field0;
    int field4;
    int field8;
};

struct ElemArray
{
    virtual void v00();
    virtual Elem* Allocate(unsigned int count);
    virtual void Free(Elem* data);
    Elem* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_0079ecc0(unsigned int count, unsigned int keep);
    __forceinline void SetSize(unsigned int count)
    {
        if (!count) {
            if (data) {
                Free(data);
                data = 0;
                capacity = 0;
                size = 0;
            }
            return;
        }
        if (count > capacity) {
            if (!capacity)
                data = Allocate(count);
            else
                FUN_0079ecc0(count, size);
            capacity = count;
            size = count;
        } else if (count < size) {
            size = count;
            if (count <= capacity >> 2) {
                FUN_0079ecc0(count, count);
                capacity = count;
            }
        } else {
            size = count;
        }
    }
};

struct EntryArray
{
    int unk00;
    void FUN_00aa8350(int count, bool exact);
};

struct Payload
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60;
};

struct Vec3{int x,y,z;};
struct Nav
{
    char m_00;
    char unk01;
    char unk02;
    char unk03;
    EntryArray m_04;
    NavEntryItem* m_08;
    int unk0C;
    unsigned int m_10;
    ElemArray m_14;
    int m_24;
    int m_28;
    int m_2C;
    Payload m_30;
    Vec3 vector94;

    void FUN_00aa85b0(Nav* dst);
};

// pdb: BSCompoundFrustum::CopyMembers | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, low
// pdb params: apDest
void Nav::FUN_00aa85b0(Nav* dst)
{
    dst->m_28 = m_28;
    dst->m_24 = m_24;
    dst->m_2C = m_2C;
    dst->vector94 = vector94;
    dst->m_30 = m_30;
    dst->m_00 = m_00;
    dst->m_14.SetSize(m_14.capacity);
    for (unsigned int i = 0; i < m_14.capacity; i++) {
        { Elem* p0=&m_14.data[i]; dst->m_14.data[i].field0 = p0->field0; }
        { Elem* p1=&m_14.data[i]; dst->m_14.data[i].field4 = p1->field4; }
        { Elem* p2=&m_14.data[i]; dst->m_14.data[i].field8 = p2->field8; }
    }
    dst->m_04.FUN_00aa8350(m_10, true);
    for (unsigned int i = 0; i < m_10; i++)
        dst->m_08[i] = m_08[i];
}
}
}   // namespace f3m_00aa85b0

// @f3 0x00aaafd0 (community match, verified in this file)
extern "C" char* __cdecl FUN_00847b50(const char* label);
extern const char* DAT_0116d760;
namespace fo3_ab7460 {
void __stdcall FUN_00aa9c80(ViewerStrings* s);
// pdb: BSBlastNode::GetViewerStrings | BSBlastNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStrings
void __stdcall FUN_00aaafd0(ViewerStrings* self)
{
    FUN_00aa9c80(self);
    char* value = FUN_00847b50(DAT_0116d760);
    unsigned int index = self->m_usSize;
    if (index >= self->m_usMaxSize)
        self->FUN_00555790(index + self->m_usGrowBy);
    self->FUN_005b3880(index, value);
}
}

// @f3 0x00ab5ce0 (community match, verified in this file)
namespace f3m_00ab5ce0 {
struct NameAB { const char* text; };
struct ObjAB {
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
 virtual NameAB* getName();
};
struct PairAB { int first, second; };
bool __cdecl FUN_00bc8820(const char*, char*, unsigned int);
void __cdecl FUN_00bccca0(char*, PairAB*, PairAB*);
void* __cdecl FUN_00bca5c0(int, PairAB*, PairAB*, char*);
// pdb: BSEntryMap::SetAt | BSTexturePalette.obj | fnv360_0721_beta, call_seq, low
// pdb params: apEntry, apValue
void* __cdecl FUN_00ab5ce0(ObjAB* object) {
 char buffer[260]; PairAB first, second;
 FUN_00bc8820(object->getName()->text, buffer, 260);
 FUN_00bccca0(buffer, &first, &second);
 return FUN_00bca5c0(1, &first, &second, buffer);
}


}   // namespace f3m_00ab5ce0

// @f3 0x00ab5bd0 (community match, verified in this file)
namespace f3m_00ab5bd0 {
class ViewerStringsAB5BD0
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

char* __cdecl FUN_00847b50(const char* name);
char* __cdecl FUN_00847d80(const char* label, unsigned int value);

class RegSettingsAB5BD0
{
public:
    unsigned int FUN_0042b600(ViewerStringsAB5BD0* strings);
    unsigned int FUN_00ab5bd0(ViewerStringsAB5BD0* strings);
};

// pdb: RegSettingCollection::GetViewerStrings | XRegSetting.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStringsA
unsigned int RegSettingsAB5BD0::FUN_00ab5bd0(ViewerStringsAB5BD0* strings)
{
    strings->Add(FUN_00847b50("RegSettings"));
    unsigned int total = FUN_0042b600(strings);
    strings->Add(FUN_00847d80("Total RegSettings", total));
    return total;
}
}   // namespace f3m_00ab5bd0

// @f3 0x00ab6f00 (community match, verified in this file)
namespace f3m_00ab6f00 {
struct ChildAB6 { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; unsigned char dirty; };
struct OwnerAB6 { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; ChildAB6** volatile items; unsigned short unkD4, count; void FUN_00ab6f00(); };
// pdb: BSMasterParticleSystem::ClearAllParticles | BSMasterParticleSystem.obj | fnv360_0822_retail, call_seq, medium
void OwnerAB6::FUN_00ab6f00() {
 unsigned int n=count;
 for (unsigned int i=0; i<n; ++i) {
  ChildAB6* child=items[i];
  if (child) child->dirty=1;
 }
}

}   // namespace f3m_00ab6f00

// @f3 0x00aae3a0 (community match, verified in this file)
namespace f3m_00aae3a0 {
class FUN_00aae3a0_Node
{
public:
    void __thiscall FUN_00ab6f00();
};

class FUN_00aae3a0_Obj
{
public:
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
    FUN_00aae3a0_Node** unkA0;
    unsigned char unkA4;
    unsigned char unkA5;
    unsigned short unkA6;

    void __thiscall FUN_00aae3a0();
};

// pdb: BSParticleSystemManager::ClearAllParticles | BSParticleSystemManager.obj | fnv360_0822_retail, callee_sim, low
void __thiscall FUN_00aae3a0_Obj::FUN_00aae3a0()
{
    unsigned int count = unkA6;
    unsigned int index = 0;

    while (index < count)
    {
        FUN_00aae3a0_Node* node = unkA0[index];
        if (node != 0)
            node->FUN_00ab6f00();
        ++index;
    }
}
}   // namespace f3m_00aae3a0

// @f3 0x00aa6590 (community match, verified in this file)
extern "C" void* FUN_00d9b0a4;
namespace f3m_00aa6590 {
extern "C" unsigned long (__stdcall *DAT_00d9b1b8)(unsigned long);

typedef int (__stdcall *CloseHandleFunc)(void*);

struct GlobalType_01090a78
{
    void FUN_0086ba60(void* object);
};

class Holder_00aa6590
{
public:
    int vtable;
    unsigned int thread;
    int unk08;
    int unk0C;
    unsigned int handle10;
    int unk14;
    int unk18;
    unsigned int handle1C;

    void* __thiscall FUN_00aa6590(int flag);
};

// pdb: BSTaskThread::`scalar deleting destructor' | BSTaskManager_Xenon.obj | fnv360_0822_retail, vtable, high
void* Holder_00aa6590::FUN_00aa6590(int flag)
{
    unsigned int thread = this->thread;

    this->vtable = 0xE89A64;

    DAT_00d9b1b8(thread);

    CloseHandleFunc closeHandle = (CloseHandleFunc)FUN_00d9b0a4;

    closeHandle((void*)this->thread);
    closeHandle((void*)this->handle1C);
    closeHandle((void*)this->handle10);

    if ((*(unsigned char*)&flag & 1) != 0)
        reinterpret_cast<GlobalType_01090a78*>(&DAT_01090a78)->FUN_0086ba60(this);

    return this;
}
}   // namespace f3m_00aa6590

// @f3 0x00aa7480 (community match, verified in this file)
    extern char const DAT_00e89e74[];
    extern char const DAT_00e89e60[];
namespace f3m_00aa7480 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847d80(const char* label, unsigned int value);

struct ViewerStringsArg {
    void** table;
    char** buffer;
    unsigned short capacity;
    unsigned short firstFree;
    unsigned short count;
    unsigned short growBy;

    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
};

class StringOwner {
public:
    unsigned int FUN_0042b600(ViewerStringsArg* strings);
    unsigned int FUN_00aa7480(ViewerStringsArg* strings);
};

// pdb: INISettingCollection::GetViewerStrings | XINISetting.obj | fnv360_0822_retail, vtable, medium
// pdb params: apStringsA
unsigned int StringOwner::FUN_00aa7480(ViewerStringsArg* strings)
{

    char* value = FUN_00847b50(DAT_00e89e74);
    unsigned int first = strings->firstFree;
    if (first >= strings->capacity)
        strings->FUN_00555790(first + strings->growBy);
    strings->FUN_005b3880(first, value);

    unsigned int result = FUN_0042b600(strings);

    {
        char* other = FUN_00847d80(DAT_00e89e60, result);
        first = strings->firstFree;
        if (first >= strings->capacity)
            strings->FUN_00555790(first + strings->growBy);
        strings->FUN_005b3880(first, other);
    }
    return result;
}
}   // namespace f3m_00aa7480

// @f3 0x00aba440 (community match, verified in this file)
extern const char* DAT_0116ebb4;
namespace f3m_00aba440 {
namespace f3m_00aba440 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847e70(const char* label, int value);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }
    __forceinline void AddInline(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        if (index >= firstFree) {
            firstFree = index + 1;
            if (value != 0)
                count++;
        } else {
            if (value != 0) {
                if (buffer[index] == 0)
                    count++;
            } else {
                if (buffer[index] != 0)
                    count--;
            }
        }
        buffer[index] = value;
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

struct Entry { int unk00; int unk04; int unk08; };

class Owner {
public:
    void FUN_00845ca0(ViewerStrings* strings);
    void FUN_00aba440(ViewerStrings* strings);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Entry** entries;
    unsigned int entryCount;
};

// pdb: BSTextureData::GetViewerStrings | BSTextureData.obj | fnv360_0822_retail, vtable, medium
// pdb params: pStrings
void Owner::FUN_00aba440(ViewerStrings* strings)
{
    FUN_00845ca0(strings);
    strings->Add(FUN_00847b50(DAT_0116ebb4));
    for (unsigned int i = 0; i < entryCount; i++)
    {
        int value = entries[i]->unk08;
        strings->AddInline(FUN_00847e70("ObjectName", value));
    }
}
}
}   // namespace f3m_00aba440

// @f3 0x00aad3a0 (community match, verified in this file)
namespace f3m_00aad3a0 {
struct f3m_00aad3a0_Obj
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int m_iCurrent;
    int m_aiStack[10];
    int m_iDepth;
    void FUN_00aad3a0(int value);
};
// pdb: BSCullingProcess::PushCullMode | BSCullingProcess.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aeType
void f3m_00aad3a0_Obj::FUN_00aad3a0(int value)
{
    m_aiStack[m_iDepth++] = m_iCurrent;
    m_iCurrent = value;
}
}   // namespace f3m_00aad3a0

// @f3 0x00ab7600 (community match, verified in this file)
namespace f3m_00ab7600 {
namespace f3m_00ab7600 {
void __cdecl FUN_0089e890(void* p);

class Base
{
  public:
    virtual ~Base();
    char unk04[0xac - 4];
};

class PointerList
{
  public:
    ~PointerList() { FUN_00abb340(); }
    void FUN_00abb340();
    int unk00; int unk04; int unk08; int unk0c; int unk10;
};

template <class T> class PrimitiveArray
{
  public:
    virtual ~PrimitiveArray() { FUN_0089e890(m_pBase); }
    void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
}

class FUN_00ab7600 : public f3m_00ab7600::Base
{
  public:
    virtual ~FUN_00ab7600();
    f3m_00ab7600::PointerList m_kList;
    int m_iC0;
    int unkC4;
    int unkC8;
    f3m_00ab7600::PrimitiveArray<void*> m_kArray;
};

// pdb: BSMasterParticleSystem::~BSMasterParticleSystem | BSMasterParticleSystem.obj | fnv360_0822_retail, call_seq, high
FUN_00ab7600::~FUN_00ab7600()
{
    m_iC0 = 0;
    m_kList.FUN_00abb340();
    m_kArray.RemoveAll();
}
}   // namespace f3m_00ab7600

// @f3 0x00abd420 (community match, verified in this file)
namespace f3m_00abd420 {
namespace f3m_00abd420 {
class NiRefObjectd420 {
public:
    virtual ~NiRefObjectd420();
    virtual void DeleteThis();
    volatile long m_uiRefCount;

    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

template <class T>
class NiPointerd420 {
public:
    NiPointerd420(T* a_pObject = 0) : m_pObject(a_pObject) {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerd420() {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerd420& operator=(const NiPointerd420& a_rOther) {
        if (m_pObject != a_rOther.m_pObject) {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = a_rOther.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(const NiPointerd420& a_rOther) const { return m_pObject == a_rOther.m_pObject; }
    bool operator!=(const NiPointerd420& a_rOther) const { return m_pObject != a_rOther.m_pObject; }

    T* m_pObject;
};

template <class T>
class NiTObjectArrayd420 {
public:
    virtual ~NiTObjectArrayd420();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetAt(unsigned int a_uiIndex, const T& a_rElement);
};

typedef NiPointerd420<NiRefObjectd420> ObjectPtrd420;

class FUN_00abd420_Array : public NiTObjectArrayd420<ObjectPtrd420> {
public:
    void FUN_00abd420(unsigned int a_uiIndex, const ObjectPtrd420& a_rElement);
};

// pdb: NiTArray<NiPointer<NiGeometry>,NiTNewInterface<NiPointer<NiGeometry> > >::SetAt | NiPSysMeshEmitter.obj | fnv360_0721_beta, callee_sim, medium
// pdb params: uiIndex, element
void FUN_00abd420_Array::FUN_00abd420(unsigned int a_uiIndex, const ObjectPtrd420& a_rElement) {
    static ObjectPtrd420 s_kInvalid;

    if (a_uiIndex >= m_usSize) {
        m_usSize = (unsigned short)(a_uiIndex + 1);
        if (a_rElement != s_kInvalid)
            m_usESize++;
    } else {
        if (a_rElement != s_kInvalid) {
            if (m_pBase[a_uiIndex] == s_kInvalid)
                m_usESize++;
        } else {
            if (m_pBase[a_uiIndex] != s_kInvalid)
                m_usESize--;
        }
    }
    m_pBase[a_uiIndex] = a_rElement;
}
}
}   // namespace f3m_00abd420

// @f3 0x00ab8e80 (community match, verified in this file)
// Fallout 3 1.7.0.3 - FUN_00ab8e80 (thiscall, this in ECX)
// Particle-system owner: clears the cached follow position back to the
// shared default vector so the next velocity update recomputes it.

namespace ParticleVelocity {

struct Vec3 {
    float x;
    float y;
    float z;
};

// Shared default (zero) vector used throughout the particle code.
extern Vec3 DAT_0108ec68;

class Owner {
public:
    void* pVftable;                 // 0x00 virtual function table
    unsigned int state[8];          // 0x04 - timing / link information
    Vec3 lastPosition;              // 0x24 cached position of the followed object
    Vec3 velocity;                  // 0x30 cached velocity applied to new particles

    void ResetLastPosition() { lastPosition = DAT_0108ec68; }
};

} // namespace ParticleVelocity

// pdb: BSParentVelocityModifier::HandleReset | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
void __fastcall FUN_00ab8e80(ParticleVelocity::Owner* pThis)
{
    pThis->ResetLastPosition();
}

// @f3 0x00ab76f0 (community match, verified in this file)
namespace f3m_00ab76f0 {
namespace MeshCursorAB76 {
    struct RefObject {
        virtual void Slot00();
        virtual void DeleteThis();
        long refs;
        unsigned unk08, unk0c, unk10, unk14, unk18, unk1c;
        unsigned unk20, unk24, unk28, unk2c;
        unsigned flags;
        __forceinline void DecRefCount() {
            if (InterlockedDecrement(&refs) == 0) DeleteThis();
        }
    };

    struct RefPtr {
        RefObject* object;
        ~RefPtr() {
            if (object) object->DecRefCount();
        }
    };

    struct Node {
        static __forceinline Node* NextOrNull(Node* node) {return node ? node->next : 0;}
        Node* next;
        Node* previous;
        RefObject* object;
    };

    struct List {
        Node* head;
        Node* tail;
        unsigned count;
        RefPtr FUN_00ab43e0(Node*& cursor);
    };

    struct Emitter {
        unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
        unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
        unsigned unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
        unsigned unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
        unsigned unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
        unsigned unka0, unka4, unka8;
        List nodes;
        unsigned short accepted;
        unsigned short limit;
        unsigned unkbc;
        Node* cursor;
        void BSMasterParticleSystem_ClearUnreferencedEmitters();
    };

    inline unsigned short MinCount(unsigned short found, unsigned short maximum) { return found < maximum ? found : maximum; }

    // pdb: BSMasterParticleSystem::ClearUnreferencedEmitters | BSMasterParticleSystem.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
    void Emitter::BSMasterParticleSystem_ClearUnreferencedEmitters()
    {
        accepted = 0;
        if (!cursor)
            cursor = nodes.head;
        unsigned remaining = nodes.count;
        Node* selected = 0;
        if (cursor) {
            do {
                if (remaining-- <= 0)
                    break;
                Node* node = cursor;
                RefObject* object = node->object;
                if (object->refs == 1 || (object->flags & 1)) {
                    nodes.FUN_00ab43e0(cursor);
                } else {
                    if (accepted == limit)
                        selected = node;
                    ++accepted;
                    cursor = Node::NextOrNull(cursor);
                }
            } while (cursor || (cursor = nodes.head));
            if (selected)
                cursor = selected;
        }
        const unsigned short maximum = limit;
        const unsigned short found = accepted;
        const unsigned short count = MinCount(found, maximum);
        accepted = count;
        if (!count)
            cursor = 0;
    }
}
}   // namespace f3m_00ab76f0

// @f3 0x00ab10c0 (community match, verified in this file)
#include <math.h>
namespace Box3097 {
struct Heap {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned) throw();
void __cdecl FUN_0089e890(void*);
struct ArrayMem {static void* operator new[](unsigned n) throw() {return DAT_01090a78.FUN_0086b930(n);} static void operator delete[](void* p) {DAT_01090a78.FUN_0086ba60(p);} };
struct Vec3 {
 static void* operator new[](unsigned n) throw() {return DAT_01090a78.FUN_0086b930(n);} static void operator delete[](void* p) {DAT_01090a78.FUN_0086ba60(p);}
 float x,y,z;
 Vec3() {}
 Vec3(float a,float b,float c) : x(a),y(b),z(c) {}
 Vec3 FUN_00439ef0(const Vec3& v) const {return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 FUN_00439e90(const Vec3& v) const {return Vec3(x+v.x,y+v.y,z+v.z);}
 Vec3 FUN_004b3800(const Vec3& v) const {return Vec3(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);}
 float NiPoint3_UnitizeGetLength();
 void FUN_00468d00();
 Vec3 operator*(float f) const {return Vec3(f*x,f*y,f*z);}
 Vec3 operator+(const Vec3& v) const {return Vec3(v.x+x,v.y+y,v.z+z);}
 Vec3 operator-(const Vec3& v) const {return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3& operator*=(float f) {x*=f;y*=f;z*=f;return *this;}
};
extern const float DAT_00db88e0;
// pdb: NiPoint3::UnitizeGetLength | TES.obj | fnv360_0822_debug, call_seq + skyrim(caller), high
inline float Vec3::NiPoint3_UnitizeGetLength() {
 float squared=x*x+y*y+z*z;
 float magnitude=static_cast<float>(sqrt(static_cast<double>(squared)));
 if(magnitude>DAT_00db88e0) {float inverse=1.0f/magnitude;x*=inverse;y*=inverse;z*=inverse;}
 else {x=0.0f;y=0.0f;z=0.0f;magnitude=0.0f;}
 return magnitude;
}
struct FUN_0046c350 { static void* operator new[](unsigned n) throw() {return DAT_01090a78.FUN_0086b930(n);} static void operator delete[](void* p) {DAT_01090a78.FUN_0086ba60(p);}float r,g,b,a;FUN_0046c350():r(0),g(0),b(0),a(0) {}};
typedef FUN_0046c350 Color4;
struct Vec2 {float x,y;};
struct ObjectMem {static void* operator new(unsigned n) throw() {return FUN_0089eb90(n);} static void operator delete(void* p) {FUN_0089e890(p);} };
struct FUN_0083f490 : ObjectMem {
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
 virtual void vdc();
 virtual void ve0();
 virtual void ve4();
 virtual void Update();
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
 unsigned unkb8;
 unsigned unkbc;
 unsigned unkc0;
 FUN_0083f490(unsigned short,Vec3*,Vec3*,Color4*,Vec2*,bool,bool,unsigned short,unsigned short*);
};
typedef FUN_0083f490 Mesh;

extern const unsigned short DAT_00e8af40[];
void* __cdecl FUN_00bffa60(void*,const void*,unsigned);
// pdb: BSTestObjects::CreateBox | BSTestObjects.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arExtents, apColor
Mesh* FUN_00ab10c0(const Vec3& size,const Color4* color) {
 static Vec3 corners[8]={Vec3(.5f,.5f,.5f),Vec3(.5f,.5f,-.5f),Vec3(.5f,-.5f,.5f),Vec3(.5f,-.5f,-.5f),Vec3(-.5f,.5f,.5f),Vec3(-.5f,.5f,-.5f),Vec3(-.5f,-.5f,.5f),Vec3(-.5f,-.5f,-.5f)};
 Vec3* vertices=new Vec3[8];
 for(int i=0;i<8;++i) {vertices[i].x=corners[i].x*size.x;vertices[i].y=corners[i].y*size.y;vertices[i].z=corners[i].z*size.z;}
 Color4* colors=color?new Color4[8]:0;
 if(colors) for(unsigned j=0;j<8;++j) colors[j]=*color;
 unsigned short* indices=(unsigned short*)DAT_01090a78.FUN_0086b930(72);
 FUN_00bffa60(indices,DAT_00e8af40,72);
 Mesh* shape=new Mesh(8,vertices,0,colors,0,0,0,12,indices);
 shape->Update();return shape;
}
}

// @f3 0x00aa3640 (community match, verified in this file)
namespace f3m_00aa3640 {
namespace f3m_00aa3640 {

extern "C" __declspec(dllimport) long __stdcall FUN_00d9b06c(long volatile*, long, long);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

class QObjA3640 {
public:
    virtual ~QObjA3640();
    int unk04;
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) delete this; }
};

class QPtrA3640 {
public:
    QObjA3640* m_pObject;
    QPtrA3640& operator=(QObjA3640* pObject)
    {
        if (m_pObject != pObject) {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    QPtrA3640& operator=(const QPtrA3640& ptr)
    {
        if (m_pObject != ptr.m_pObject) {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct QNodeA3640 {
    QNodeA3640* next;
    QPtrA3640 data;
};

class QQueueA3640 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    QNodeA3640* head;
    QNodeA3640* tail;
};

class QPopA3640 {
public:
    QQueueA3640* queue;
    QNodeA3640** hazard1;
    QNodeA3640** hazard2;
    void FUN_0042dbf0(QNodeA3640* node);
    bool FUN_00aa3640(QPtrA3640* volatile out);
};

// pdb: LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueInterface::Pop | ModelLoader.obj | fnv360_0822_retail, call_dedup, low
// pdb params: arData
bool QPopA3640::FUN_00aa3640(QPtrA3640* volatile out)
{
    QNodeA3640* nodes[2];
    QNodeA3640* volatile& head = nodes[0];
    QNodeA3640* volatile& next = nodes[1];
    head = 0;
    for (;;) {
        do {
            head = queue->head;
            *hazard1 = head;
        } while (head != queue->head);
        QNodeA3640* tail = queue->tail;
        next = head->next;
        *hazard2 = next;
        if (head == queue->head) {
            if (!next) {
                *hazard1 = 0;
                *out = 0;
                return false;
            }
            if (head == tail) {
                QNodeA3640* nx = next;
                FUN_00d9b06c((volatile long*)&queue->tail, (long)nx, (long)tail);
            } else {
                QPtrA3640* src = &next->data;
                QPtrA3640& o = *out;
                if (o.m_pObject != src->m_pObject) {
                    if (o.m_pObject)
                        o.m_pObject->DecRefCount();
                    QObjA3640* nv = src->m_pObject;
                    out->m_pObject = nv;
                    if (nv)
                        nv->IncRefCount();
                }
                QNodeA3640* h = head;
                long nl = (long)next;
                long* ph = (long*)&queue->head;
                if (FUN_00d9b06c(ph, nl, (long)h) == (long)h)
                    break;
            }
        }
    }
    queue->v0C();
    next->data = 0;
    *hazard1 = 0;
    *hazard2 = 0;
    FUN_0042dbf0(head);
    return true;
}

}
}   // namespace f3m_00aa3640

// @f3 0x00aad8f0 (community match, verified in this file)
namespace f3m_00aad8f0 {
struct Vec3 { float x; float y; float z; };

struct Shape_ad9a_L {
    int unk00;
    int unk04;
    int unk08;
    Vec3 center;
    float radius;
};

struct Plane {
    float nx;
    float ny;
    float nz;
    float d;
};

struct PlaneSet {
    Plane planes[6];
    unsigned int mask;
};

struct Sph { Vec3 c; float r; };

class BoundSphere_L {
public:
    int unk00;
    int unk04;
    int unk08;
    Sph sph;

    bool FUN_00aad8f0(PlaneSet* ps);
};

// pdb: BSMultiBoundSphere::CompletelyWithinFrustum | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aPlanes
bool BoundSphere_L::FUN_00aad8f0(PlaneSet* ps) {
    Sph s;
    s.r = sph.r;
    s.c = sph.c;
    unsigned int mask = ps->mask;
    unsigned int i = 0;
    do {
        if (mask & (1 << i)) {
            Plane& p = ps->planes[i];
            float t = (p.ny * s.c.y + p.nx * s.c.x) + p.nz * s.c.z;
            t -= p.d;
            if (t <= -s.r || !(t >= s.r)) {
                return false;
            }
        }
        i++;
    } while (i < 6);
    return true;
}
}   // namespace f3m_00aad8f0

// @f3 0x00aa0130 (community match, verified in this file)
#include <string.h>
extern int DAT_00dbefb4;
namespace f3m_00aa0130 {

struct Block36 { unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44; };

struct NewObjAA0130
{
    void* table;
    unsigned int unk04, unk08, unk0C, unk10, unk14;
    Words539 position;
    Block36 block24;
    static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); }
    void FUN_00aa0b10();
    NewObjAA0130() { FUN_00aa0b10(); table = &DAT_00dbefb4; }
};

struct OwnerAA0130
{
    unsigned int unk00, unk04, unk08;
    void* handle;
    unsigned int unk10, unk14;
    Words539 position;
    Block36 block24;
    void FUN_00aa0b30(NewObjAA0130*, int);
    NewObjAA0130* FUN_00aa0130(int argument);
};

// pdb: BSMultiBoundOBB::CreateClone | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
NewObjAA0130* OwnerAA0130::FUN_00aa0130(int argument)
{
    NewObjAA0130* o = new NewObjAA0130();
    FUN_00aa0b30(o, argument);
    memcpy(&o->block24, &block24, 36);
    return o;
}
}   // namespace f3m_00aa0130

// @f3 0x00aa5810 (community match, verified in this file)
namespace f3m_00aa5810 {
struct OwnerAA58 {
 int unk00; unsigned int* data; unsigned int size;
 void FUN_00aa5720(unsigned int*, unsigned int);
 void FUN_005e30b0(unsigned int*, unsigned int*, unsigned int);
 void FUN_00aa5810(unsigned int index, unsigned int count);
};
// pdb: BSSimpleArray<NiPointer<QueuedFile>,1024>::RemoveFast | QueuedFiles.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aiIndex, aiHowMany
void OwnerAA58::FUN_00aa5810(unsigned int index, unsigned int count) {
 unsigned int remaining = size - index - count;
 unsigned int j = remaining < count ? remaining : count;
 FUN_00aa5720((data + index), count);
 FUN_005e30b0(data + index, data + size - j, j);
 size -= count;
}
}   // namespace f3m_00aa5810

// @f3 0x00ab6d10 (community match, verified in this file)
namespace f3m_00ab6d10 {
struct File00ab6d10 {
    void* vtable;
    unsigned int position;
    unsigned int (__cdecl* read)(File00ab6d10*, void*, unsigned int, unsigned int*, unsigned int);
};
struct Stream00ab6d10 { unsigned int field000; unsigned int field004; unsigned int field008; unsigned int field00c; unsigned int field010; unsigned int field014; unsigned int field018; unsigned int field01c; unsigned int field020; unsigned int field024; unsigned int field028; unsigned int field02c; unsigned int field030; unsigned int field034; unsigned int field038; unsigned int field03c; unsigned int field040; unsigned int field044; unsigned int field048; unsigned int field04c; unsigned int field050; unsigned int field054; unsigned int field058; unsigned int field05c; unsigned int field060; unsigned int field064; unsigned int field068; unsigned int field06c; unsigned int field070; unsigned int field074; unsigned int field078; unsigned int field07c; unsigned int field080; unsigned int field084; unsigned int field088; unsigned int field08c; unsigned int field090; unsigned int field094; unsigned int field098; unsigned int field09c; unsigned int field0a0; unsigned int field0a4; unsigned int field0a8; unsigned int field0ac; unsigned int field0b0; unsigned int field0b4; unsigned int field0b8; unsigned int field0bc; unsigned int field0c0; unsigned int field0c4; unsigned int field0c8; unsigned int field0cc; unsigned int field0d0; unsigned int field0d4; unsigned int field0d8; unsigned int field0dc; unsigned int field0e0; unsigned int field0e4; unsigned int field0e8; unsigned int field0ec; unsigned int field0f0; unsigned int field0f4; unsigned int field0f8; unsigned int field0fc; unsigned int field100; unsigned int field104; unsigned int field108; unsigned int field10c; unsigned int field110; unsigned int field114; unsigned int field118; unsigned int field11c; unsigned int field120; unsigned int field124; unsigned int field128; unsigned int field12c; unsigned int field130; unsigned int field134; unsigned int field138; unsigned int field13c; unsigned int field140; unsigned int field144; unsigned int field148; unsigned int field14c; unsigned int field150; unsigned int field154; unsigned int field158; unsigned int field15c; unsigned int field160; unsigned int field164; unsigned int field168; unsigned int field16c; unsigned int field170; unsigned int field174; unsigned int field178; unsigned int field17c; unsigned int field180; unsigned int field184; unsigned int field188; unsigned int field18c; unsigned int field190; unsigned int field194; unsigned int field198; unsigned int field19c; unsigned int field1a0; unsigned int field1a4; unsigned int field1a8; unsigned int field1ac; unsigned int field1b0; unsigned int field1b4; unsigned int field1b8; unsigned int field1bc; unsigned int field1c0; unsigned int field1c4; unsigned int field1c8; unsigned int field1cc; unsigned int field1d0; unsigned int field1d4; unsigned int field1d8; unsigned int field1dc; unsigned int field1e0; unsigned int field1e4; unsigned int field1e8; unsigned int field1ec; unsigned int field1f0; unsigned int field1f4; unsigned int field1f8; unsigned int field1fc; unsigned int field200; unsigned int field204; unsigned int field208; unsigned int field20c; unsigned int field210; unsigned int field214; unsigned int field218; unsigned int field21c; unsigned int field220; unsigned int field224; unsigned int field228; unsigned int field22c; unsigned int field230; unsigned int field234; unsigned int field238; unsigned int field23c; unsigned int field240; unsigned int field244; unsigned int field248; File00ab6d10* input; };
struct Member00ab6d10 { unsigned int field00, field04, field08; void FUN_00823eb0(Stream00ab6d10*); };
struct State00ab6d10 {
    unsigned int field00, field04, field08;
    Member00ab6d10 first, second;
    float value;
    void FUN_00c22010(Stream00ab6d10*);
    void FUN_00ab6d10(Stream00ab6d10*);
};
// pdb: BSMultiBoundCapsule::LoadBinary | BSMultiBoundCapsule.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void State00ab6d10::FUN_00ab6d10(Stream00ab6d10* stream) {
    FUN_00c22010(stream);
    first.FUN_00823eb0(stream);
    second.FUN_00823eb0(stream);
    File00ab6d10* __restrict input = stream->input;
    unsigned int size = 4;
    input->position += input->read(input, &value, 4, &size, 1);
}
}   // namespace f3m_00ab6d10

// @f3 0x00aa41a0 (community match, verified in this file)
namespace f3m_00aa41a0 {
struct FUN_00aa41a0_Obj;

struct FUN_0042ba10_Obj
{
    unsigned int unk00;
    unsigned int unk04;

    unsigned int __thiscall FUN_0042ba10(FUN_00aa41a0_Obj* object);
};

struct Args20
{
    unsigned int a1;
    unsigned int a2;
    unsigned int a3;
    unsigned int a4;
    unsigned int a5;
};

struct FUN_00aa3a60_Obj
{
    void __thiscall FUN_00aa3a60(
        unsigned int arg1,
        unsigned int arg2,
        unsigned int arg3,
        unsigned int arg4,
        unsigned int arg5);
};

struct FUN_00aa41a0_Obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_0042ba10_Obj* unk14;

    void __thiscall FUN_00aa41a0(Args20 s);
};

extern "C" __declspec(dllimport) unsigned long __stdcall TlsGetValue(unsigned long dwTlsIndex);

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::SetAt | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiBucket, aKey, aData, abReplaceExisting
void __thiscall FUN_00aa41a0_Obj::FUN_00aa41a0(Args20 s)
{
    FUN_0042ba10_Obj* tls = unk14;
    unsigned int value = TlsGetValue(tls->unk04);

    if (value == 0)
        value = tls->FUN_0042ba10(this);

    ((FUN_00aa3a60_Obj*)value)->FUN_00aa3a60(s.a1, s.a2, s.a3, s.a4, s.a5);
}
}   // namespace f3m_00aa41a0

// @f3 0x00aa2f50 (community match, verified in this file)
namespace f3m_00aa2f50 {
namespace f3m_00aa2f50 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefObj {
    virtual void Release(int reason);
    unsigned int unk04;
    long refs;
    __forceinline void IncRef() { InterlockedIncrement(&refs); }
    __forceinline void DecRef() { if (InterlockedDecrement(&refs) == 0) { if (this) Release(1); } }
};

template <class T> class NiPtr {
public:
    T* m_pObject;
    __forceinline NiPtr(T* object = 0) { m_pObject = object; if (m_pObject) m_pObject->IncRef(); }
    __forceinline ~NiPtr() { if (m_pObject) m_pObject->DecRef(); }
    __forceinline NiPtr<T>& operator=(const NiPtr<T>& other) {
        if (m_pObject != other.m_pObject) {
            if (m_pObject) m_pObject->DecRef();
            m_pObject = other.m_pObject;
            if (m_pObject) m_pObject->IncRef();
        }
        return *this;
    }
};

struct FUN_00aa2f50 {
    unsigned int unk00;
    unsigned int unk04;
    NiPtr<RefObj> ptr08;
    unsigned int unk0C;
    FUN_00aa2f50(unsigned int a, unsigned int b, const NiPtr<RefObj>& src);
};

FUN_00aa2f50::FUN_00aa2f50(unsigned int a, unsigned int b, const NiPtr<RefObj>& src) : ptr08(0), unk0C(0)
{
    unk00 = a;
    unk04 = b;
    ptr08 = src;
}
}
}   // namespace f3m_00aa2f50

// @f3 0x00ab4040 (community match, verified in this file)
namespace f3m_00ab4040 {
class Ab4040StandIn
{
public:
    int unk00;
    int* unk04;
    unsigned int unk08;

    void __thiscall FUN_005e5240(int* data, unsigned int count);
    void __thiscall FUN_005e30b0(int* dst, int* src, unsigned int count);

    void __thiscall FUN_00ab4040(unsigned int index, unsigned int amount);
};

void __thiscall Ab4040StandIn::FUN_00ab4040(unsigned int index, unsigned int amount)
{
    unsigned int rest = unk08 - index - amount;
    unsigned int moved = rest < amount ? rest : amount;
    FUN_005e5240(unk04 + index, amount);
    FUN_005e30b0(unk04 + index, unk04 + (unk08 - moved), moved);
    unk08 -= amount;
}
}   // namespace f3m_00ab4040

// @f3 0x00aa2650 (community match, verified in this file)
namespace f3m_00aa2650 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
struct Ref00aa2650
{
    volatile long count;
    void* sem;
};
struct Elem00aa2650
{
    int unk00, unk04, unk08;
    Ref00aa2650 a;
    int unk14;
    Ref00aa2650 b;
};
struct Pool00aa2650
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    volatile long count20;
    volatile long refs24;
    unsigned int n28;
    Elem00aa2650** arr2c;
    bool FUN_00aa2650();
};
// pdb: BSTaskManager<__int64>::Resume | IOManager.obj | fnv360_0721_retail, objrun_prop, medium
bool Pool00aa2650::FUN_00aa2650()
{
    if (refs24 == 0 || InterlockedDecrement(&refs24) != 0)
        return false;
    if (count20 != n28)
    {
        do
        {
            Sleep(1);
        } while (count20 != n28);
    }
    for (unsigned int i = 0; i < n28; ++i)
    {
        Elem00aa2650* e = arr2c[i];
        Ref00aa2650& r = e->a;
        if (r.count == 0)
        {
            ReleaseSemaphore(r.sem, 1, 0);
            InterlockedIncrement(&r.count);
        }
        Ref00aa2650& q = e->b;
        ReleaseSemaphore(q.sem, 1, 0);
        InterlockedIncrement(&q.count);
        InterlockedDecrement(&count20);
    }
    return true;
}
}   // namespace f3m_00aa2650

// @f3 0x00ab7180 (community match, verified in this file)
namespace f3m_00ab7180 {
struct unkNode;
struct unkArr {
    unsigned short unk00, unk02, unk04, unk06;
    unsigned short capacity;
    unsigned short count;
    unsigned short unkC;
    unsigned short grow;
    void FUN_00555790(unsigned int n);
    void FUN_005b3880(unsigned int idx, unkNode** pp);
};
struct unkChild {
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
    unkNode** items;
    unsigned short unkA4;
    unsigned short n;
};
struct unkNode {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unkChild* v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual int v12();
};
struct unkThis { void FUN_00ab7180(unkNode* node, unkArr* arr); };
// pdb: BSMasterParticleSystem::FindNiParticlesRecurse | BSMasterParticleSystem.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject, apNiParticles
void unkThis::FUN_00ab7180(unkNode* node, unkArr* arr)
{
    if (node) {
        if (node->v12()) {
            unkNode* tmp = node;
            unsigned int c = arr->count;
            if (c >= arr->capacity)
                arr->FUN_00555790(c + arr->grow);
            arr->FUN_005b3880(c, &tmp);
        } else {
            unkChild* ch = node->v3();
            if (ch) {
                unsigned int cnt = ch->n;
                for (unsigned int i = 0; i < cnt; i++) {
                    unkNode* n = ch->items[i];
                    if (n) FUN_00ab7180(n, arr);
                }
            }
        }
    }
}
}   // namespace f3m_00ab7180

// @f3 0x00aadf30 (community match, verified in this file)
namespace b1582 {
struct HeapZ { void FUN_0086ba60(void* p); };
extern HeapZ g_heapQ;
struct ArrBase;
typedef void (__thiscall *FreeFn)(ArrBase*, void*);
extern void* DAT_00e894a0;
extern FreeFn DAT_00e894a8;
extern void* DAT_00e8a66c;

struct ItemQ { ~ItemQ(); static void operator delete(void* p) { g_heapQ.FUN_0086ba60(p); } };

struct ArrBase {
    void* vptr;
    void* unk04;
    int unk08;
    int unk0c;
    __forceinline ~ArrBase() {
        vptr = &DAT_00e894a0;
        if (unk04) {
            DAT_00e894a8(this, unk04);
            unk04 = 0;
            unk0c = 0;
            unk08 = 0;
        }
    }
};

struct ArrDerived : ArrBase {
    __forceinline void Reset() {
        if (unk04) {
            ((FreeFn*)vptr)[2](this, unk04);
            unk04 = 0;
            unk0c = 0;
            unk08 = 0;
        }
    }
};

struct Base0 { virtual ~Base0(); };
}
using namespace b1582;

struct FUN_00aadf30 : Base0 {
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
    ItemQ* unkAC;
    ArrDerived unkB0;
    int unkC0;
    ~FUN_00aadf30();
};

// pdb: BSPortalSharedNode::~BSPortalSharedNode | BSPortal.obj | fnv360_0822_retail, call_seq, high
FUN_00aadf30::~FUN_00aadf30() {
    delete unkAC;
    unkB0.Reset();
    unkC0 = 0;
}

// @f3 0x00ab6d60 (community match, verified in this file)
namespace f3m_00ab6d60 {
class Target6d60
{
public:
    typedef int (__cdecl *CallType)(Target6d60*, void*, int, int*, int);

    void* vtable;
    int unk04;
    int unk08;
    CallType call0c;
};

class Sub6d60
{
public:
    void FUN_0083fa20(int argument);
    int unk04;
    int unk08;
    int unk0C;
};


static inline int Rd(Target6d60* t, int* dest)
{
    int size = 4;
    return t->call0c(t, dest, 4, &size, 1);
}
class FUN_00ab6d60_Obj
{
public:
    int unk00;
    int unk04;
    int unk08;
    Sub6d60 first;
    Sub6d60 second;
    int unk24;
    void FUN_00ab6d60(int argument);
    void FUN_008cbd30(int argument);
};
// pdb: BSMultiBoundCapsule::SaveBinary | BSMultiBoundCapsule.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void FUN_00ab6d60_Obj::FUN_00ab6d60(int argument)
{
    FUN_008cbd30(argument);
    first.FUN_0083fa20(argument);
    second.FUN_0083fa20(argument);

    Target6d60* target = *(Target6d60**)((char*)argument + 0x250);
    target->unk04 += Rd(target, &unk24);
}
}   // namespace f3m_00ab6d60

// @f3 0x00ab9920 (community match, verified in this file)
extern void* const DAT_00e2652c[];
namespace f3m_00ab9920 {

struct PoolAlloc_ab9920 {
    void Free(void* p);
};


struct Node_ab9920 {
    Node_ab9920* next;
    int unk04;
    int unk08;
};

struct Base_ab9920 {
    void* vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~Base_ab9920();
};

struct Obj_ab9920;

struct ListClear_ab9920 {
    Obj_ab9920* o;
    ListClear_ab9920(Obj_ab9920* p);
    ~ListClear_ab9920();
};

struct Obj_ab9920 : Base_ab9920 {
    void* slots[8];
    Node_ab9920* lhead;
    Node_ab9920* ltail;
    int lcount;
    void FUN_00ab9920();
};

// pdb: BSDecalPlacementVectorExtraData::~BSDecalPlacementVectorExtraData | BSDecalPVExtraData.obj | fnv360_0822_retail, call_seq, high
void Obj_ab9920::FUN_00ab9920()
{
    {
        ListClear_ab9920 lc(this);
        for (int i = 0; i < 8; i++) {
            if (slots[i] != 0) {
                ((PoolAlloc_ab9920*)&DAT_01090a78)->Free(slots[i]);
            }
            slots[i] = 0;
        }
        Node_ab9920* n = lhead;
        while (n != 0) {
            Node_ab9920* cur = n;
            n = n->next;
            cur->unk08 = 0;
            ((PoolAlloc_ab9920*)&DAT_01090a78)->Free(cur);
        }
    }
    vptr = (void*)DAT_00e2652c;
    this->Base_ab9920::~Base_ab9920();
}


ListClear_ab9920::~ListClear_ab9920()
{
    o->lcount = 0;
    o->lhead = 0;
    o->ltail = 0;
}

ListClear_ab9920::ListClear_ab9920(Obj_ab9920* p)
{
    o = p;
    p->vptr = (void*)DAT_00e8ba2c;
}
}   // namespace f3m_00ab9920

// @f3 0x00ab9ab0 (community match, verified in this file)
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec00(void*);

namespace b1706 {
struct NiFixedString { char* handle; };
extern NiFixedString DAT_0108f3fc;
extern void* DAT_00e8ba2c;

struct NiObjectBase {
    void* vptr;
    int unk04, unk08;
    NiObjectBase();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ec00(p); }
    void FUN_008245d0(const NiFixedString& name);
};

struct Obj : NiObjectBase {
    int unk0c;
    unsigned short unk10;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int unk34, unk38, unk3c;
    Obj() {
        unk0c = 0;
        vptr = &DAT_00e8ba2c;
        unk3c = 0; unk34 = 0; unk38 = 0;
        unk10 = 0;
        unk14 = 0; unk18 = 0; unk1c = 0; unk20 = 0;
        unk24 = 0; unk28 = 0; unk2c = 0; unk30 = 0;
    }
};

NiObjectBase* __cdecl FUN_00ab9ab0()
{
    Obj* object = new Obj;
    object->FUN_008245d0(DAT_0108f3fc);
    return object;
}
}

// @f3 0x00aa7d80 (community match, verified in this file)
namespace f3m_00aa7d80 {
namespace task2443 {
struct TreeVector;
struct TreePlane
{
    float x, y, z, distance;
    float EvaluatePlane(const TreeVector& vector) const;
};
struct TreeVector
{
    float x;
    float y;
    float z;
    float w;
    float GetW() const
    {
        return w;
    }
    int ClassifySphereAgainstPlane(TreePlane* plane) const;
    int ClassifySphereAgainstPlane(TreePlane* plane)
    {
        float distance = plane->EvaluatePlane(*this);
        if (distance < -w)
            return 2;
        else if (distance > w)
            return 1;
        else
            return 0;
    }
};

struct TreeQuery
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TreeVector* m_pkVector;

    int HasVector() const
    {
        return m_pkVector && m_pkVector->GetW() != 0.0;
    }
};

struct TreeEntry
{
    TreePlane planes[6];
    unsigned int activePlanes;
};

struct TreeNode
{
    int m_iType;
    int m_iField04;
    int m_iFail;
};

class TreeEvaluator
{
  public:
    int unk00;
    int unk04;
    TreeEntry* m_pkEntryArray;
    int unk0c;
    int unk10;
    int unk14;
    TreeNode* m_pkNodes;
    int unk1c;
    int unk20;
    int unk24;
    int m_iNodeCount;
    int m_iRoot;
    TreeEntry m_kRootEntry;
    int unk94;
    int unk98;
    int unk9c;
    bool m_bSkipRoot;

    TreeEntry* GetEntry(int index)
    {
        TreeNode* pkNext = &m_pkNodes[index];
        return &m_pkEntryArray[pkNext->m_iType];
    }
    bool FUN_00aa7b30(const TreeVector*, TreeEntry*);
    bool FUN_00aa7ba0(TreeVector*, TreeEntry*);
    bool FUN_00aa7d80(TreeQuery* pkQuery);
};

// pdb: BSCompoundFrustum::Process | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject
bool TreeEvaluator::FUN_00aa7d80(TreeQuery* pkQuery)
{
    if (!pkQuery->HasVector())
        return false;
    TreeEntry* pkEntry = 0;
    TreeVector* pkVec = pkQuery->m_pkVector;
    TreeVector kVector;
    __int64* kDst = (__int64*)&kVector;
    const __int64* __restrict kSrc = (const __int64*)pkVec;
    kDst[0] = kSrc[0];
    kDst[1] = kSrc[1];
    bool bResultTmp = true;
    if (!m_bSkipRoot)
        bResultTmp = FUN_00aa7b30(static_cast<const TreeVector*>(&kVector), &m_kRootEntry);
    if (bResultTmp && m_iNodeCount > 0)
    {
        int i = m_iRoot;
        while (m_pkNodes[i].m_iType != 2 && m_pkNodes[i].m_iType != 3)
        {
            bool bPass = false;
            switch (m_pkNodes[i].m_iType)
            {
            case 7: {
                pkEntry = GetEntry(i + 1);
                bPass = FUN_00aa7b30(&kVector, pkEntry);
                break;
            }
            case 8: {
                pkEntry = GetEntry(i + 1);
                bPass = FUN_00aa7ba0(&kVector, pkEntry);
                break;
            }
            }
            i = bPass ? m_pkNodes[i].m_iField04 : m_pkNodes[i].m_iFail;
        }
        bResultTmp = m_pkNodes[i].m_iType == 2;
    }
    return bResultTmp;
}

}
}   // namespace f3m_00aa7d80

// @f3 0x00aa1e20 (community match, verified in this file)
namespace qaa1e20 {
struct Dispatch
{
    void (__thiscall* destroy)(void*, unsigned int);
    void* (__thiscall* allocate)(void*, unsigned int);
    void (__thiscall* release)(void*, void*);
};
extern const Dispatch DAT_00e894a0;
class FUN_00aa1e20
{
public:
    const Dispatch* vtable;
    void* data;
    unsigned int size;
    unsigned int capacity;
    ~FUN_00aa1e20();
};
FUN_00aa1e20::~FUN_00aa1e20()
{
    vtable = &DAT_00e894a0;
    if (data)
    {
        vtable->release(this, data);
        data = 0;
        capacity = 0;
        size = 0;
    }
}
}

// @f3 0x00ab88d0 (community match, verified in this file)
namespace f3m_00ab88d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace wab88d0 {
struct Obj {
    virtual ~Obj();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};
typedef NiPointer<Obj> Ptr;
struct Map { __declspec(noalias) bool FUN_00bea7b0(void* key, void** value); };
struct Handle { Map* map; };
struct Arr {
    virtual ~Arr();
    Ptr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __declspec(noinline) void FUN_00ab87c0(unsigned int index, const Ptr& value)
    {
        static const Ptr null(0);
        if (index >= m_usSize) {
            m_usSize = (unsigned short)(index + 1);
            if (value != null)
                ++m_usESize;
        } else if (value != null) {
            if (m_pBase[index] == null)
                ++m_usESize;
        } else if (m_pBase[index] != null) {
            --m_usESize;
        }
        m_pBase[index] = value;
    }
    Ptr FUN_006e2e40(unsigned int index);
    void FUN_00ab8300();
    const Ptr& GetAt(unsigned int index) const { return m_pBase[index]; }
};
struct Clone {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    Arr array;
};
struct Self {
    void FUN_00ac62f0(Handle* handle);
    void FUN_00ab88d0(Handle* handle);
};
// pdb: BSPSysArrayEmitter::ProcessClone | BSPSysArrayEmitter.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
void Self::FUN_00ab88d0(Handle* handle)
{
    FUN_00ac62f0(handle);
    void* result;
    if (!handle->map->FUN_00bea7b0(this, &result))
        return;
    Clone* clone = (Clone*)result;
    unsigned int i = clone->array.m_usSize;
    unsigned int found = 0;
    if (i) {
        do {
            --i;
            Obj* object;
            bool cloned = handle->map->FUN_00bea7b0((Obj*)clone->array.GetAt(i), (void**)&object);
            if (cloned) {
                ++found;
                Ptr value(object);
                clone->array.FUN_00ab87c0(i, value);
            } else {
                clone->array.FUN_006e2e40(i);
            }
        } while (i);
    }
    if (found != clone->array.m_usSize)
        clone->array.FUN_00ab8300();
}
}
}   // namespace f3m_00ab88d0

// @f3 0x00aaa910 (community match, verified in this file)
namespace AA {
struct V3 {
    float x, y, z;
    V3() {}
    V3(float a, float b, float c) : x(a), y(b), z(c) {}
    V3 operator*(float s) const { return V3(x * s, y * s, z * s); }
    V3& operator+=(const V3& o) { x += o.x; y += o.y; z += o.z; return *this; }
    V3 operator+(const V3& o) const { V3 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
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
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    float* arr;
};
struct Self {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float f18;
    void FUN_00aaa910(float d, Node* n);
};
}
extern AA::V3 DAT_0116d728;
namespace AA { struct P7 { V3 pos; float u0C; float u10; float u14; float u18; }; }
// pdb: BSWindModifier::Update | BSWindModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: afTime, apData
void AA::Self::FUN_00aaa910(float d, AA::Node* n) {
    unsigned short c = n->count;
    if (c == 0) return;
    P7* q = (P7*)n->arr;
    unsigned int k = c;
    while (k != 0) {
        k--;
        q->pos += DAT_0116d728 * ((d - q->u14) * f18);
        q++;
    }
}

// @f3 0x00ab64f0 (community match, verified in this file)
extern char DAT_00e8b464;
namespace f3m_00ab64f0 {
struct Vec3_ab64f0 { float x, y, z; void Zero() { x = 0.0f; y = 0.0f; z = 0.0f; } };
extern void* __cdecl FUN_0089eb90(unsigned int);

struct State00ab64f0 {
    void* table;
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    Vec3_ab64f0 unk18, unk24, unk30, unk3c;
    unsigned int unk48, unk4c, unk50, unk54, unk58, unk5c;

    void FUN_00ac5e10();

    static void* __cdecl operator new(unsigned int) {
        return FUN_0089eb90(0x60);
    }

    State00ab64f0() {
        FUN_00ac5e10();
        table = &DAT_00e8b464;
        unk18.Zero();
        unk24.Zero();
        unk30.Zero();
        unk3c.Zero();
    }
};

// pdb: BSPSysSimpleColorModifier::CreateObject | BSPSysSimpleColorModifier.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: BSPSysSimpleColorModifier::BSPSysSimpleColorModifier)
State00ab64f0* __cdecl FUN_00ab64f0() {
    return new State00ab64f0;
}
}   // namespace f3m_00ab64f0

// @f3 0x00aa5240 (community match, verified in this file)
namespace f3m_00aa5240 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace f3m_00aa5240 {
struct Task;
struct RefObject {
    virtual ~RefObject();
    int unk04;
    volatile long refs;
    __forceinline void IncRef() { InterlockedIncrement(&refs); }
    __forceinline void DecRef() { if (InterlockedDecrement(&refs) == 0) delete this; }
};
struct Listener : RefObject {
    virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20();
    virtual void OnFinished(Task* task);
};
struct ListenerPtr {
    Listener* p;
    operator Listener*() const {return p;}
    Listener* operator->() const {return p;}
    __forceinline ListenerPtr& operator=(Listener* q)
    {
        if (p != q) {
            if (p) p->DecRef();
            p = q;
        }
        return *this;
    }
};
struct ListenerList {
    virtual ~ListenerList();
    Listener** items;
    unsigned int count;
};
struct Progress {
    int unk00, unk04;
    int done;
    int unk0c;
    volatile int total;
    unsigned GetSize() const {return done;}
    unsigned GetFinished() const {return total;}
    bool IsComplete() const { return GetSize() == GetFinished(); }
};
struct Task : RefObject {
    int state;
    int unk10, unk14, unk18;
    ListenerPtr listener;
    Progress* progress;
    ListenerList* listeners;
    bool AllFinished() const {return progress ? progress->IsComplete() : 1;}
    void FUN_00aa5240();
};
// pdb: QueuedFile::CheckFinished | QueuedFiles.obj | fnv360_0822_retail, vtable, medium
void Task::FUN_00aa5240()
{
    if (!listener && !listeners)
        return;
    if (state < 4)
        return;
    if (!AllFinished())
        return;
    IncRef();
    if (listener) {
        listener->OnFinished(this);
        listener = 0;
    }
    if (listeners) {
        for (unsigned int i = 0; i < listeners->count; i++)
            listeners->items[i]->OnFinished(this);
        delete listeners;
        listeners = 0;
    }
    DecRef();
}
}
}   // namespace f3m_00aa5240

// @f3 0x00aa8f50 (community match, verified in this file)
namespace f3m_00aa8f50 {
namespace b1853 {
struct Item { int type, unk04, unk08; };
struct Array {
    int unk00;
    Item* data;
    int unk08, capacity, unk10, count;
    void FUN_005bb760(int, bool);
};
struct Owner {
    unsigned char dirty;
    int unk04, unk08, unk0c, unk10;
    Array entries;
    bool IsClosed(int& n);
    void FUN_00aa8f50();
};

__forceinline bool Owner::IsClosed(int& n)
{
    Item* data = entries.data;
    if (data[0].type != 5)
        return false;
    n = entries.count;
    int depth = 1;
    int i = 1;
    Item* p = &data[1];
    do {
        if (i >= n)
            break;
        switch (p->type) {
        case 4:
        case 5:
            depth++;
            break;
        case 6:
            depth--;
            break;
        }
        i++;
        p++;
    } while (depth > 0);
    return i == n && depth == 0;
}

// pdb: BSCompoundFrustum::MakeIntoUnion | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: NavMeshObstacleCutter::GetModifiedTriangleList)
void Owner::FUN_00aa8f50()
{
    int n;
    if (!IsClosed(n)) {
        if (entries.count + 1 >= entries.capacity)
            entries.FUN_005bb760(entries.capacity + 10, true);
        if (entries.count + 1 >= entries.capacity)
            entries.FUN_005bb760(entries.capacity + 10, true);
        int n = entries.count;
        if (n >= 1) {
            for (int j = n, off = n * 12; j >= 1; j--) {
                char* d = (char*)entries.data;
                int prev = off - 12;
                *(int*)(d + prev + 12) = *(int*)(d + prev);
                off = prev;
            }
        }
        entries.count++;
        entries.data[0].type = 5;
    } else {
        entries.count = n - 1;
    }
}
}
}   // namespace f3m_00aa8f50

// @f3 0x00aad780 (community match, verified in this file)
#include <math.h>
namespace f3m_00aad780 {

struct Shape97 : Shape_ad9a {
    int __thiscall FUN_00aad780(Sphere_ad9a* other);
};

// pdb: BSMultiBoundSphere::CheckBound | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aTargetBound
int __thiscall Shape97::FUN_00aad780(Sphere_ad9a* other)
{
    Vec3_ad9a delta;
    delta.x = center.x - other->center.x;
    delta.y = center.y - other->center.y;
    delta.z = center.z - other->center.z;
    float sum = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
    float d = sqrtf(sum);
    if (d - (GetRadius() - other->radius) <= 0.0f) return 2;
    if (d - (other->radius + GetRadius()) <= 0.0f) return 1;
    return 0;
}
}   // namespace f3m_00aad780

// @f3 0x00aa7200 (community match, verified in this file)
namespace f3m_00aa7200 {
namespace f3m_00aa7200 {
struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream* stream, void* buffer, unsigned int bytes,
                                     unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        unsigned int read = m_pfnRead(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += read;
        return read;
    }
};
template <class T> inline void NiStreamLoadBinary(NiBinaryStream& stream, T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(&value, sizeof(T), &size, 1);
}
struct NiStream {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248;
    NiBinaryStream* m_pkIstr;
};
struct Node {
    void* vtable;
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

    unsigned char unkac, unkad, unkae, unkaf;
    int unkb0;
    void FUN_0082db60(NiStream* stream);
    void FUN_00aa7200(NiStream* stream);
};
// pdb: BSValueNode::LoadBinary | BSValueNode.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: NiSwitchNode::LoadBinary)
// pdb params: arStream
void Node::FUN_00aa7200(NiStream* stream)
{
    FUN_0082db60(stream);
    int value;
    NiStreamLoadBinary(*stream->m_pkIstr, value);
    unkb0 = value;
    if ((unsigned int)stream->unk004 > 0x18)
        NiStreamLoadBinary(*stream->m_pkIstr, unkac);
}
}
}   // namespace f3m_00aa7200

// @f3 0x00aba2e0 (community match, verified in this file)
namespace f3m_00aba2e0 {
namespace f3m_00aba2e0 {
struct Stream {
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    unsigned int(__cdecl* m_pfnRead)(Stream* stream, void* buffer, unsigned int bytes,
                                     unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* componentSizes,
                            unsigned int numComponents)
    {
        unsigned int read = m_pfnRead(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += read;
        return read;
    }
};
template <class T> inline void LoadBinary(Stream& stream, T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(&value, sizeof(T), &size, 1);
}
struct Manager {
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
    Stream* m_pkIstr;
    void FUN_0082b560();
};
struct Buffer {
    virtual void slot0();
    virtual void* Alloc(unsigned int count);
    virtual void Free(void* ptr);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void FUN_00799ae0(unsigned int a, unsigned int b);
    __forceinline void SetSize(unsigned int n)
    {
        if (n == 0)
        {
            if (unk04 != 0)
            {
                Free((void*)unk04);
                unk04 = 0;
                unk0c = 0;
                unk08 = 0;
            }
            return;
        }
        if (n > unk0c)
        {
            if (unk0c == 0)
            {
                unsigned int ptr = (unsigned int)Alloc(n);
                unk08 = n;
                unk0c = n;
                unk04 = ptr;
                return;
            }
            FUN_00799ae0(n, unk08);
            unk08 = n;
            unk0c = n;
            return;
        }
        if (n < unk08)
        {
            unk08 = n;
            if (n <= (unk0c >> 2))
            {
                FUN_00799ae0(n, n);
                unk0c = n;
            }
        }
        else
            unk08 = n;
    }
};
struct Owner {
    int unk00;
    int unk04;
    int unk08;
    Buffer buf;
    void FUN_00aba2e0(Manager* manager);
};
void __stdcall FUN_00845bc0(Manager* manager);
}
using namespace f3m_00aba2e0;
// pdb: BSTextureData::LoadBinary | BSTextureData.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void Owner::FUN_00aba2e0(Manager* manager)
{
    FUN_00845bc0(manager);
    int count;
    LoadBinary(*manager->m_pkIstr, count);
    for (int i = 0; i < count; i++)
        manager->FUN_0082b560();
    buf.SetSize(count);
}
}   // namespace f3m_00aba2e0

// @f3 0x00aa6cd0 (community match, verified in this file)
namespace f3m_00aa6cd0 {
namespace f3m_00aa6cd0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089e890(void*);
struct RefObject {
    long refCount;
    virtual void V0();
    virtual void DeleteThis();
};
struct Controller : RefObject {
    int unk08; int unk0c; int unk10; int unk14;
    Controller();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089e890(p); }
};
template <class T> struct RefPtr {
    T* p;
    RefPtr& operator=(T* o)
    {
        if (p != o) {
            T* old = p;
            if (old && InterlockedDecrement(&old->refCount) == 0) old->DeleteThis();
            p = o;
            if (o) InterlockedIncrement(&o->refCount);
        }
        return *this;
    }
    operator T*() const { return p; }
};
struct Owner {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300; int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c; int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c; int unk340; int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c; int unk360; int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c; int unk380; int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c; int unk3a0; int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc; int unk3c0; int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc; int unk3e0; int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc; int unk400; int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c; int unk420; int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c; int unk440; int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c; int unk460; int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c; int unk480; int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c; int unk4a0; int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc; int unk4c0; int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc; int unk4e0; int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc; int unk500; int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c; int unk520; int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c; int unk540; int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c; int unk560; int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c; int unk580; int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c; int unk5a0; int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc; int unk5c0;
    int enabled;
    RefPtr<Controller> controller;
    void FUN_0082d150(Controller* c);
    bool FUN_0082d5d0();
    bool BSStream_SaveStream();
};
// pdb: BSStream::SaveStream | BSStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
bool Owner::BSStream_SaveStream()
{
    if (enabled) {
        controller = new Controller;
        FUN_0082d150(controller);
    }
    bool r = FUN_0082d5d0();
    controller = 0;
    return r;
}
}
}   // namespace f3m_00aa6cd0

// @f3 0x00ab0830 (community match, verified in this file)
namespace f3m_00ab0830 {
namespace f3m_00ab0830 {
using f3m_00ab05a0::f3ab05a0::Stream;
using f3m_00ab05a0::f3ab05a0::Object;
using f3m_00ab05a0::f3ab05a0::Save;
struct Obj {
    int unk00, unk04, unk08, unk0c;
    Object* items;
    int unk14;
    unsigned short count;
    void FUN_008459d0(Stream* s);
    void FUN_00ab0830(Stream* s);
};
// pdb: BSFurnitureMarker::SaveBinary | BSFurnitureMarker.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Obj::FUN_00ab0830(Stream* sp)
{
    Stream* s = *(Stream* volatile*)&sp;
    FUN_008459d0(s);
    unsigned int n = count;
    Save(*s, n);
    for (unsigned int i = 0; i < n; i++)
        items[i].FUN_00ab05a0(*s);
}
}
}   // namespace f3m_00ab0830

// @f3 0x00aa9f10 (community match, verified in this file)
namespace f3m_00aa9f10 {
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Heap {
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;

struct SemPair {
    volatile long count;
    void* handle;
    __forceinline void Signal() {
        ReleaseSemaphore(handle, 1, 0);
        InterlockedIncrement(&count);
    }
    __forceinline void Wait() {
        WaitForSingleObject(handle, 0xFFFFFFFF);
        InterlockedDecrement(&count);
    }
};

struct Data {
    virtual ~Data();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    SemPair a;
    int unk38;
    SemPair b;
    int unk44;
    bool flag48;
    __forceinline void Stop() {
        flag48 = true;
        a.Signal();
    }
};

struct Outer {
    Data* inner;
};

struct Owner {
    Outer* outer;
    void FUN_00aa9f10();
};

// pdb: BSParallelTaskManager::~BSParallelTaskManager | BSParallelTaskManager.obj | fnv360_0822_retail, call_gap, low
void Owner::FUN_00aa9f10() {
    outer->inner->Stop();
    outer->inner->b.Wait();
    delete outer->inner;
    outer->inner = 0;
    DAT_01090a78.FUN_0086ba60(outer);
}
}

// @f3 0x00aad9d0 (community match, verified in this file)
#include <math.h>
namespace f3m_00aad9d0 {
namespace f3m_00aad9d0 {
inline float FUN_004019b0(float value) { return static_cast<float>(sqrt(static_cast<double>(value))); }
inline float FUN_004579e0(float value)
{
    return FUN_004019b0(value);
}
struct BoundPoint
{
    float x, y, z;
    BoundPoint() {}
    BoundPoint(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth) {}
    BoundPoint FUN_00439ef0(const BoundPoint& rhs) const
    {
        return BoundPoint(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    float FUN_00457990() const
    {
        return FUN_004579e0(x * x + y * y + z * z);
    }
};
struct BSMultiBoundSphere
{
    int unk00, unk04, unk08;
    BoundPoint center;
    float radius;
    bool FUN_00aad9d0(const BoundPoint& pt) const;
};
// pdb: BSMultiBoundSphere::QPointWithin | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aPoint
bool BSMultiBoundSphere::FUN_00aad9d0(const BoundPoint& pt) const
{
    if (pt.FUN_00439ef0(center).FUN_00457990() < radius)
        return true;
    return false;
}
}
}   // namespace f3m_00aad9d0

// @f3 0x00aa4f70 (community match, verified in this file)
extern int DAT_010a24b8;
namespace task2889 {
struct Base2889 {
    virtual __forceinline ~Base2889() {
        *(int**)this = &DAT_010a24b8;
    }
};
struct Heap2889 { void FUN_0086ba60(void*); };
extern Heap2889 DAT_01090a78;
struct Queue2889 : Base2889 {
    unsigned unk04, unk08, unk0c;
    void* data;
    void FUN_00aa4df0(bool);
    virtual ~Queue2889();
};
// pdb: LockFreeQueue<NiPointer<IOTask> >::~LockFreeQueue<NiPointer<IOTask> > | IOManager.obj | fnv360_0822_debug, call_seq, high
Queue2889::~Queue2889() {
    FUN_00aa4df0(true);
    void* volatile pData = data;
    void* q = pData;
    DAT_01090a78.FUN_0086ba60(q);
}
}

// @f3 0x00aa1450 (community match, verified in this file)
#include <math.h>
namespace f3m_00aa1450 {
struct VecAA1450 { unsigned int x, y, z; float w; };
struct OwnerAA1450 {
    int unk00, unk04, unk08;
    unsigned int originX, originY, originZ;
    float x, y, z;
    void FUN_00aa1450(VecAA1450* out);
};
// pdb: BSMultiBoundAABB::GetNiBound | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable, medium
// pdb params: aBound
void OwnerAA1450::FUN_00aa1450(VecAA1450* out) {
    float squared = x * x + y * y + z * z;
    float length = (float)sqrt((double)squared);
    *(volatile float*)&squared = length;
    out->x = originX;
    double radius = *(volatile float*)&squared;
    out->y = originY;
    out->z = originZ;
    out->w = (float)radius;
}
}   // namespace f3m_00aa1450

// @f3 0x00aa7280 (community match, verified in this file)
namespace f3m_00aa7280 {
using f3m_00ab05a0::f3ab05a0::Stream;
using f3m_00ab05a0::f3ab05a0::Save;

namespace f3m_00aa7280 {
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
    unsigned char fieldAC;
    int fieldB0;
    void FUN_0082e820(Stream& s);
    void FUN_00aa7280(Stream& s);
};
// pdb: BSValueNode::SaveBinary | BSValueNode.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: NiSwitchNode::SaveBinary)
// pdb params: arStream
void Owner::FUN_00aa7280(Stream& s) {
    FUN_0082e820(s);
    int v = fieldB0;
    Save(s, v);
    Save(s, fieldAC);
}
}
}   // namespace f3m_00aa7280

// @f3 0x00aa7ba0 (community match, verified in this file)
namespace f3m_00aa7ba0 {
namespace f3m_00aa7ba0 {
struct Entry {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct Set {
    Entry entries[6];
    unsigned int mask;
};

struct Target {
    int FUN_004754d0(Entry* entry);
};

// pdb: BSCompoundFrustum::TestNotContained | BSCompoundFrustum.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apBound, apPlanes
char __stdcall FUN_00aa7ba0(Target* target, Set* set)
{
    if (set->mask == 0)
        return false;
    int i = 0;
    Entry* e = set->entries;
    do {
        unsigned int mask = set->mask;
        unsigned int bit = 1 << i;
        if (mask & bit) {
            if (target->FUN_004754d0(e) != 1)
                break;
            (*(Set* volatile*)&set)->mask = mask & ~bit;
        }
        ++i;
        ++e;
    } while (i < 6);
    return i != 6;
}
}
}   // namespace f3m_00aa7ba0

// @f3 0x00aa4690 (community match, verified in this file)
namespace f3m_00aa4690 {
extern void* (__stdcall * const DAT_00d9b080)(unsigned long);
namespace f3m_00aa4690 {
struct Owner;
struct Wrapper;
struct TlsObj {
    unsigned int unk00;
    unsigned long tlsIndex;
    Wrapper* __thiscall FUN_0042ba10(Owner* o);
    __forceinline Wrapper* Get(Owner* o) {
        Wrapper* w = (Wrapper*)DAT_00d9b080(tlsIndex);
        if (!w) return FUN_0042ba10(o);
        return w;
    }
};
struct Inner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual int slot20(int a, int b, int c, int d, int e);
};
struct Wrapper {
    Inner* inner;
    void __thiscall FUN_00aa39f0(int v);
};
struct Owner {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    TlsObj* tls;
    void __thiscall FUN_00aa4690(int a, int b, int c);
};
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::GetAt | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aKey, arData
void Owner::FUN_00aa4690(int a, int b, int c) {
    Wrapper* w = tls->Get(this);
    int a0 = a;
    int c0 = *(volatile int*)&c;
    w->FUN_00aa39f0(w->inner->slot20(a0, b, a0, b, c0));
}
}
}   // namespace f3m_00aa4690

// @f3 0x00aa4080 (community match, verified in this file)
namespace f3m_00aa4df0 {

struct Node4080
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_0042bbb0();
};

struct Item4080
{
    int unk00;
    Node4080* node;
};

}

extern int (__stdcall * const DAT_00d9b07c)(unsigned long index);

// pdb: ThreadSpecificInterfaceManager<LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueInterface>::~ThreadSpecificInterfaceManager<LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueInterface> | ModelLoader.obj | fnv360_0822_retail, call_dedup, low
void f3m_00aa4df0::FUN_005e5280::FUN_00aa4080()
{
    unsigned int index = 0;

    if (index < static_cast<unsigned int>(unk00))
    {
        do
        {
            f3m_00aa4df0::Node4080* volatile current =
                reinterpret_cast<f3m_00aa4df0::Item4080*>(unk08)[index].node;

            current = current;

            if (current != 0)
            {
                f3m_00aa4df0::Node4080* node = current;

                while (node->unk0C != 0)
                    node->FUN_0042bbb0();

                DAT_01090a78.FUN_0086ba60(node);
            }

            index += 1;
        }
        while (index < static_cast<unsigned int>(unk00));
    }

    DAT_01090a78.FUN_0086ba60(reinterpret_cast<void*>(unk08));
    DAT_00d9b07c(static_cast<unsigned long>(unk04));
}

// @f3 0x00aa53e0 (community match, verified in this file)
extern volatile long DAT_0116d13c;
namespace f3m_00aa53e0 {
namespace f3m_00aa53e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct Sub2C {
    int unk00, unk04, unk08;
    unsigned int val0c : 31;
    unsigned int flag0c : 1;
};

struct Base {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual char v2c();
    int unk04, unk08, unk0c;
};

struct AA53 : Base {
    __int64 i10;
    int unk18, unk1c, unk20, unk24, unk28;
    Sub2C* sub2c;

    void FUN_00424150(char kind, int value, unsigned char group, unsigned short id);
    void FUN_00424c80();
    void FUN_00aa53e0();
};

// pdb: QueuedFileEntry::GenerateKey | QueuedFiles.obj | fnv360_0822_retail, vtable, medium
void AA53::FUN_00aa53e0() {
    if (sub2c) {
        unsigned int id = (unsigned short)InterlockedIncrement(&DAT_0116d13c);
        char b = (char)(i10 >> 16);
        int v = sub2c->val0c;
        FUN_00424150(v2c(), v, b, id);
        return;
    }
    FUN_00424c80();
}
}
}   // namespace f3m_00aa53e0

// @f3 0x00aa6490 (community match, verified in this file)
namespace f3m_00aa6490 {
extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*,long,long,const char*);
namespace Thread6490 {
struct FUN_00aa6490 {
    typedef void* Handle;
    static int (__stdcall * const DAT_00d9b0a4)(Handle);
    static Handle (__stdcall * const DAT_00d9b170)(void*,unsigned long,unsigned long (__stdcall *)(void*),void*,unsigned long,unsigned long*);
    static unsigned long __stdcall FUN_00aa6460(void* parameter);
    static void __cdecl FUN_0089fee0(unsigned int id,const char* name);
    struct Semaphore {
        volatile long count;
        Handle handle;
        long maximum;
        Semaphore(long initial,long limit) : count(initial),maximum(limit) {
            handle=CreateSemaphoreA(0,count,limit,0);
        }
        ~Semaphore() { DAT_00d9b0a4(handle); }
    };
    virtual void v0();
    Handle thread;
    unsigned long threadId;
    Semaphore wake;
    Semaphore lock;
    FUN_00aa6490(unsigned unused,const char* name);
    ~FUN_00aa6490();
};
// pdb: BSTaskThread::BSTaskThread | BSTaskManager_Xenon.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiProcessor, apThreadName
FUN_00aa6490::FUN_00aa6490(unsigned unused,const char* name) : wake(0,0x7fffffff),lock(1,1) {
    thread=DAT_00d9b170(0,0,FUN_00aa6460,this,4,&threadId);
    if(name) FUN_0089fee0(threadId,name);
}
}
}   // namespace f3m_00aa6490

// @f3 0x00aad840 (community match, verified in this file)
namespace f3m_00aad840 {
namespace f3m_00aad840 {
struct NiPoint3
{
    float x, y, z;
    float Dot(const NiPoint3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct NiPlane
{
    NiPoint3 m_kNormal;
    float m_fConstant;
    float Distance(const NiPoint3& p) const
    {
        float dot = m_kNormal.Dot(p);
        return dot - m_fConstant;
    }
};
struct NiBound
{
    NiPoint3 m_kCenter;
    float m_fRadius;
    NiBound(const NiBound& o) : m_kCenter(o.m_kCenter), m_fRadius(o.m_fRadius) {}
};
struct Frustum
{
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlanes;
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    NiBound m_kBound;
    bool FUN_00aad840(const Frustum* frustum);
};

// pdb: BSMultiBoundSphere::WithinFrustum | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aPlanes
bool Owner::FUN_00aad840(const Frustum* frustum)
{
    NiBound bound = m_kBound;
    unsigned int active = frustum->m_uiActivePlanes;
    for (unsigned int i = 0; i < 6; i++)
    {
        if (active & (1 << i))
        {
            float dist = frustum->m_akPlanes[i].Distance(bound.m_kCenter);
            if (dist <= -bound.m_fRadius)
                return false;
        }
    }
    return true;
}
}
}   // namespace f3m_00aad840

// @f3 0x00ab5730 (community match, verified in this file)
#include <stdlib.h>
extern float DAT_0116eb30;
extern float DAT_0116db20[514];
extern int DAT_0116e328[514];
extern double FUN_00db8d70;
extern double FUN_00dd6570;
extern double FUN_00db38a8;
namespace f3m_00ab5730 {


// pdb: hkStringPtr::printf | hkStringPtr.obj | fnv360_0822_retail, uconst + skyrim(uconst), high
float hkStringPtr_printf(float x)
{
    if (DAT_0116eb30 == 0.0f) {
        int i;
        for (i = 0; i < 256; ++i) {
            DAT_0116e328[i] = i;
            DAT_0116db20[i] = (float)((rand() % 512 - 256) * FUN_00dd6570);
        }
        while (--i) {
            int saved = DAT_0116e328[i];
            int j = rand() % 256;
            DAT_0116e328[i] = DAT_0116e328[j];
            DAT_0116e328[j] = saved;
        }
        for (i = 0; i < 258; ++i) {
            DAT_0116e328[256 + i] = DAT_0116e328[i];
            DAT_0116db20[256 + i] = DAT_0116db20[i];
        }
        DAT_0116eb30 = 1.0f;
    }

    float xx = (float)(x + FUN_00db8d70);
    int ip = (int)xx;
    float f = (float)(xx - ip);
    int idx = ip & 255;
    int p0 = DAT_0116e328[idx];
    int p1 = DAT_0116e328[(idx + 1) & 255];
    float gA = DAT_0116db20[p0];
    float gB = DAT_0116db20[p1];
    float A = (float)(gA * f);
    float fm1 = (float)(f - FUN_00db38a8);
    float B = (float)(gB * fm1);
    double f2 = f * f;
    double f3 = f2 * f;
    double f4 = f * f3;
    double f5 = f4 * f;
    float E = (float)((6.0 * f5 - 15.0 * f4) + 10.0 * f3);
    return (float)(A + (B - A) * E);
}
}   // namespace f3m_00ab5730

// @f3 0x00ab8f60 (community match, verified in this file)
namespace f3m_00ab8f60 {
struct V3 { float x,y,z; };
struct Rec28 { V3 v; float pad[4]; };
struct Data { char pad[0x20-0]; V3* b; char pad2[0x70-0x24]; Rec28* a; };
struct K {
 char pad[0x18]; float s; char pad2[0x30-0x1c]; V3 v;
 void FUN_00ab8f60(Data* d, unsigned short i);
};
// pdb: BSParentVelocityModifier::Initialize | BSParentVelocityModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: apData, aiNewParticle
void K::FUN_00ab8f60(Data* d, unsigned short i) {
 V3* pa=&d->a[i].v;
 pa->x=v.x+pa->x; pa->y=v.y+pa->y; pa->z=v.z+pa->z;
 float s2=s;
 V3 t; t.x=v.x*s2; t.y=v.y*s2; t.z=v.z*s2;
 V3* pb=&d->b[i];
 pb->x-=t.x; pb->y-=t.y; pb->z-=t.z;
}
}   // namespace f3m_00ab8f60

// @f3 0x00aad360 (community match, verified in this file)
namespace f3m_00aad360 {
extern char FUN_00dc01b0;                        // default message used when the field is null
extern char DAT_00e21a78;                         // the format/label string pushed as an immediate address
void __cdecl FUN_00c24b70(void* first, void* second);   // cdecl free: push / push / call / add esp, 8

struct Checker {
    virtual int vv0();
    virtual int vv1();
    virtual int vv2();
    virtual int vv3();
    virtual int vv4();
    virtual int vv5();
    virtual int vv6();
    virtual int vv7();
    virtual int vv8();
    virtual int vv9();
    virtual int vv10();
    virtual int vv11();
    virtual int vv12();
    virtual int vv13();
    virtual int vv14();
    virtual int vv15();
    virtual int vv16();
    virtual int vv17();
    virtual int vv18();
    virtual int vv19();
    virtual int vv20();
    virtual int vv21();
    virtual int vv22();
    virtual int vv23();
    virtual int vv24();
    virtual int vv25();
    virtual int vv26();
    virtual int vv27();
    virtual int vv28();
    virtual int vv29();
    virtual int vv30();
    virtual int vv31();
    virtual int vv32();
    virtual int vv33();
    virtual int vv34();
    virtual int vv35();
    virtual int vv36();
    virtual int vv37();
    virtual bool v98(void* p);                    // slot +0x98 (index 38), one stack arg, callee cleans
};

struct AAD {
    unsigned char raw[0xc8];                      // field at +0xc4 is the Checker pointer

    void FUN_00aad360(void* p);                   // thiscall member, one stack param (ret 4)
};

// pdb: BSCullingProcess::AppendVirtual | BSCullingProcess.obj | fnv360_0822_retail, vtable, medium
// pdb params: kVisible
void AAD::FUN_00aad360(void* p) {
    Checker* c = *(Checker**)(raw + 0xc4);        // ORIG: mov ecx,[ecx+0xc4] - this is never saved
    bool ok = false;

    if (c != 0) {                                 // ORIG: test ecx,ecx ; push esi / mov esi,[esp+8] ; je L_001e
        ok = c->v98(p);                           // ORIG: mov eax,[ecx] ; mov edx,[eax+0x98] ; push esi ; call edx
    }

    if (ok == false) {                            // ORIG: test al,al ; jne L_0038 - byte test of a bool result
        void* msg = *(void**)((char*)p + 8);      // ORIG: mov eax,[esi+8] ; test eax,eax ; jne L_002a
        if (msg == 0) {
            msg = (void*)&FUN_00dc01b0;           // ORIG: mov eax, offset FUN_00dc01b0
        }
        FUN_00c24b70((void*)&DAT_00e21a78, msg);  // ORIG: push eax ; push 0xe21a78 ; call ; add esp,8
    }
}
}   // namespace f3m_00aad360

// @f3 0x00ab97d0 (community match, verified in this file)
namespace f3m_00ab97d0 {
struct FUN_00ab97d0_Manager
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int (__cdecl* call)(FUN_00ab97d0_Manager*, void*, int, int*, int);
};
struct FUN_00ab97d0_Record { unsigned short unk00; };
struct FUN_00ab97d0_Param { char pad[0x250]; FUN_00ab97d0_Manager* unk250; };
void __stdcall FUN_00864a70(FUN_00ab97d0_Param* parameter);
struct FUN_00ab97d0_Object
{
    int unk00; int unk04; int unk08; int unk0C; unsigned short unk10;
    FUN_00ab97d0_Record* unk14[1];
    void BSDecalPlacementVectorExtraData_SaveBinary(FUN_00ab97d0_Param* parameter);
};
// pdb: BSDecalPlacementVectorExtraData::SaveBinary | BSDecalPVExtraData.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void FUN_00ab97d0_Object::BSDecalPlacementVectorExtraData_SaveBinary(FUN_00ab97d0_Param* parameter)
{
    FUN_00ab97d0_Param* prm = parameter;
    int sz;
    FUN_00864a70(prm);
    sz = 2;
    { *(unsigned short**)&parameter = &unk10; FUN_00ab97d0_Manager* __restrict m = prm->unk250; FUN_00ab97d0_Manager* m2 = prm->unk250; int r = m->call(m, &unk10, 2, &sz, 1); m2->unk04 += r; }
    for (int i = 0; i < **(unsigned short* volatile*)&parameter; i++)
    {
        { FUN_00ab97d0_Record* q = unk14[i]; FUN_00ab97d0_Manager* __restrict m = prm->unk250; FUN_00ab97d0_Manager* m2 = prm->unk250; sz = 2; int r = m->call(m, q, 2, &sz, 1); m2->unk04 += r; }
        { unsigned t = (unsigned)unk14[i]; FUN_00ab97d0_Manager* __restrict m = prm->unk250; FUN_00ab97d0_Manager* m2 = prm->unk250; char* b = (char*)t + 4; t = *(unsigned short*)t * 12; sz = 4; int r = m->call(m, b, (int)t, &sz, 1); m2->unk04 += r; }
        { unsigned t = (unsigned)unk14[i]; FUN_00ab97d0_Manager* __restrict m = prm->unk250; FUN_00ab97d0_Manager* m2 = prm->unk250; char* b = (char*)t + 0x64; t = *(unsigned short*)t * 12; sz = 4; int r = m->call(m, b, (int)t, &sz, 1); m2->unk04 += r; }
    }
}
}   // namespace f3m_00ab97d0

// @f3 0x00aaace0 (community match, verified in this file)
namespace f3m_00aaace0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall FUN_00d9b06c(volatile long* dest, long exchange, long comparand);
struct Lock {
    long volatile owner;
    unsigned int depth;
    void FUN_00409a80(const char* source);
    void Release()
    {
        if (--depth == 0) {
            const long previousOwner = owner;
            FUN_00d9b06c(&owner, 0, previousOwner);
        }
    }
};
extern Lock DAT_0116d740;
struct RefObj {
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
};
struct RefPtr {
    RefObj* p;
    RefPtr(RefObj* o) { p = o; if (o) InterlockedIncrement(&o->refs); }
    ~RefPtr() { RefObj* t = p; if (t) { if (InterlockedDecrement(&t->refs) == 0) t->DeleteThis(); } }
};
struct RefList {
    void* vtable;
    RefObj** data;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_005574c0(unsigned int size);
    __declspec(noinline) void FUN_00aaabd0(unsigned int index, const RefPtr& r);
    void Add(const RefPtr& r) { unsigned int idx = unk0A; if (idx >= unk08) FUN_005574c0(unk0E + idx); FUN_00aaabd0(idx, r); }
};
extern RefList DAT_010667f0;

// callee defined in this unit so the compiler sees it only reads r (no reload of r.p after the call)
__declspec(noinline) void RefList::FUN_00aaabd0(unsigned int index, const RefPtr& r) { RefObj* n = r.p; if (n) InterlockedIncrement(&n->refs); RefObj* old = data[index]; data[index] = n; if (old) { if (InterlockedDecrement(&old->refs) == 0) old->DeleteThis(); } }

// pdb: NiObjectGarbage::Add | NiObjectGarbage.obj | fnv360_1110_retail, call_seq, medium
// pdb params: apObject
void __cdecl FUN_00aaace0(RefObj* o)
{
    DAT_0116d740.FUN_00409a80(0);
    DAT_010667f0.Add(RefPtr(o));
    DAT_0116d740.Release();
}}

// @f3 0x00aa13c0 (community match, verified in this file)
namespace f3m_00aa13c0 {
class FUN_00aa13c0_Box
{
public:
    void BSMultiBoundAABB_GetVertices(CornerVec* out);
    bool FUN_00aa13c0(const f3m_00aa1250::fo3_00aa1250::Frustum6* planes);
};

// pdb: BSMultiBoundAABB::CompletelyWithinFrustum | BSMultiBoundAABB.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: aPlanes
bool FUN_00aa13c0_Box::FUN_00aa13c0(const f3m_00aa1250::fo3_00aa1250::Frustum6* planes)
{
    CornerVec corners[8];
    BSMultiBoundAABB_GetVertices(corners);

    unsigned int flags = planes->m_uiActivePlaneMask;
    for (int i = 0; i < 6; ++i)
    {
        if (flags & (1 << i))
        {
            const float* p = &corners[0].x;
            for (int j = 0; j < 8; ++j)
            {
                const f3m_00aa1250::fo3_00aa1250::Plane4& plane = planes->m_akPlanes[i];
                float store = p[0] * plane.nx + p[1] * plane.ny + p[2] * plane.nz - plane.d;
                float& dv = store;
                if (dv < 0.0f)
                    return false;
                p += 3;
            }
        }
    }
    return true;
}
}   // namespace f3m_00aa13c0

// @f3 0x00ab0bc0 (community match, verified in this file)
namespace f3m_00ab0bc0 {
namespace Batch88 {
struct TargetBC0 {unsigned unk00,used;int (__cdecl* acquire)(TargetBC0*,unsigned*,unsigned,unsigned*,unsigned);};
struct ParamBC0;
struct LocalBC0 {unsigned unk00,unk04,unk08;unsigned short index;unsigned char flags,extra;LocalBC0():index(0),flags(255){} void FUN_00ab04e0(ParamBC0*);};
struct MemberBC0 {unsigned unk00,unk04;unsigned short capacity,size,count,grow;void FUN_00ab0630(unsigned);void FUN_00ab0270(unsigned,const LocalBC0*);};
struct ParamBC0
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
    TargetBC0* unk24C;
};


struct Owner {unsigned unk00,unk04,unk08;MemberBC0 elements;void FUN_00845bc0(ParamBC0*);void FUN_00ab0bc0(ParamBC0*);};
// pdb: BSFurnitureMarker::LoadBinary | BSFurnitureMarker.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Owner::FUN_00ab0bc0(ParamBC0* parameter){
 FUN_00845bc0(parameter);
 TargetBC0* __restrict target=parameter->unk24C;
 unsigned count;unsigned stride=4;
 int result=target->acquire(target,&count,4,&stride,1);
 target->used+=result;
 if(count){
  MemberBC0* values=&elements;
  values->FUN_00ab0630(count);
  LocalBC0 local;
  for(unsigned i=0;i<count;++i){
   local.FUN_00ab04e0(parameter);
   unsigned index=values->size;
   if(index>=values->capacity)values->FUN_00ab0630(values->grow+index);
   values->FUN_00ab0270(index,&local);
  }
 }
}
}
}   // namespace f3m_00ab0bc0

// @f3 0x00aae090 (community match, verified in this file)
namespace f3m_00aae090 {
namespace W_AAE {

struct LeafAae;                                     // the end of each three-step chain
struct MidAae {                                     // reached through +0x0C of a middle node
    char unk00[0xc];
    LeafAae* leaf;                                  // ORIG: mov edx, dword ptr [edx + 0xc] ; test edx,edx ; je L_0022 - null here yields the zero answer
};
struct HeadAae {                                    // reached from the receiver at +0xFC and +0x100
    char unk00[0xac];
    MidAae* mid;                                    // ORIG: mov edx, dword ptr [edx + 0xac] ; test edx,edx ; je - the first of two inner guards
};
struct LeafAae {
    char unk00[8];
    int kind;                                       // ORIG: mov eax, dword ptr [edx + 8] then cmp eax,1 - compared against one, never a bit test
};

struct OwnerAae {                                   // thiscall receiver with no arguments: the entry ends in a bare ret
    char unk00[0xfc];
    HeadAae* headA;                                 // +0xFC walked for the first answer
    HeadAae* headB;                                 // +0x100 walked for the value that is ORed into it

    int FUN_00aae090();
};

}

// pdb: BSPortal::AnyRoomsVisible | BSPortal.obj | fnv360_0822_debug, objrun, medium
int W_AAE::OwnerAae::FUN_00aae090() {               // ORIG: mov edx,[ecx+0xfc] with no frame at all - a leaf using only volatile registers and ecx
    using namespace W_AAE;

    int result = 0;                                 // ORIG: xor eax,eax sits BEFORE the first test, so the answer is zeroed up front and survives into the second block
    if (this->headA != 0) {                         // ORIG: test edx,edx ; je L_002e - a null head leaves that zero untouched
        int value;                                  // ORIG: no initialiser here - the zero is written at a shared failure label reached by both inner guards
        MidAae* mid = this->headA->mid;             // ORIG: mov edx, dword ptr [edx + 0xac] ; test edx,edx ; je L_0022
        if (mid != 0) {                             // ORIG: the success path falls through to the load and then jumps over the shared zero store
            LeafAae* leaf = mid->leaf;              // ORIG: mov edx, dword ptr [edx + 0xc] ; test edx,edx ; je L_0022
            if (leaf != 0) { value = leaf->kind; } else { value = 0; }   // ORIG: mov eax,[edx+8] ; jmp L_0024 with L_0022: xor eax,eax - the two zero stores merge into one label
        } else { value = 0; }                       // ORIG: this guard and the inner one share that single store, which is why only one xor appears after the jump target
        result = (value == 1);                      // ORIG: xor edx,edx ; cmp eax,1 ; sete dl ; mov eax,edx - a materialised bool, not a branch
    }

    HeadAae* second = this->headB;                  // ORIG L_002e: mov ecx,[ecx+0x100] - the receiver is re-read here because ecx was reused as the walker
    if (second != 0) {                              // ORIG: test ecx,ecx ; je L_0063 - a null second head skips this block entirely
        int value2;                                 // ORIG L_0057: xor ecx,ecx - even the failed path materialises its zero and compares it against one
        MidAae* mid2 = second->mid;                 // ORIG: mov ecx,[ecx+0xac] ; test ecx,ecx ; je L_0057
        if (mid2 != 0) {                            // ORIG: the same merged-zero structure as block one
            LeafAae* leaf2 = mid2->leaf;            // ORIG: mov ecx,[ecx+0xc] ; test ecx,ecx ; je L_0057
            if (leaf2 != 0) { value2 = leaf2->kind; } else { value2 = 0; }
        } else { value2 = 0; }
        result |= (value2 == 1);                    // ORIG: xor edx,edx ; cmp ecx,1 ; sete dl ; or eax,edx - the second bool is ORed rather than assigned
    }

    return result;                                  // ORIG L_0063: ret with eax already holding the answer
}
}   // namespace f3m_00aae090

// @f3 0x00aa41f0 (community match, verified in this file)
namespace f3m_00aa41f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Obj2968 {
    virtual void Destroy(bool);
    int unk04;
    volatile long references;
    void release() {
        long refs = InterlockedDecrement(&references);
        if (refs == 0) Destroy(true);
    }
};
struct Ptr2968 { Obj2968* object; Ptr2968():object(0) {} ~Ptr2968(){ if(object) object->release(); } };
struct IteratorBase2968 {
    virtual __forceinline ~IteratorBase2968() {}
    virtual void FUN_00aa2560() { current=0; tail=0; }
    int unk04,index,unk0c;
    void* current;
    void* tail;
    unsigned char flags;
    int unk1c;
    IteratorBase2968():index(0),current(0),tail(0),flags(0) {}
    bool atEnd() const {return (flags&2)!=0;}
};
struct FUN_00aa2580 : IteratorBase2968 { virtual __forceinline ~FUN_00aa2580() {} };
struct Owner2968 {
    Obj2968* p;
    bool FUN_00aa3df0(FUN_00aa2580*,__int64*,Ptr2968*,bool);
    void FUN_00427340(Obj2968*,int);
    void FUN_00aa41f0();
};
__declspec(noinline) bool Owner2968::FUN_00aa3df0(FUN_00aa2580* it, __int64* key, Ptr2968* item, bool b) {
    FUN_00427340(0, 0);
    it->flags = b ? 2 : 0;
    *key = it->index;
    item->object = p;
    return p != 0;
}
// pdb: BSTaskManager<__int64>::CancelAllTasks | IOManager.obj | fnv360_0822_retail, vtable, medium
void Owner2968::FUN_00aa41f0() {
    bool changed=true;
    while(changed) {
        changed=false;
        FUN_00aa2580 iterator;
        while(!iterator.atEnd()) {
            __int64 key;
            Ptr2968 item;
            if(FUN_00aa3df0(&iterator,&key,&item,true)) {
                FUN_00427340(item.object,0);
                changed=true;
            }
        }
    }
}
}   // namespace f3m_00aa41f0

// @f3 0x00aa2ba0 (community match, verified in this file)
namespace f3m_00aa2ba0 {
namespace W_AA2B {

struct Owner2b {                                    // the receiver is only forwarded to the inner call: no field of this object is read here
    int FUN_00aa2860(void* obj, int low, int high);  // ORIG: mov ecx,ebp ; push ebx ; push esi ; push edi - the same receiver, with the two halves passed after it
    int FUN_00aa2ba0(void* obj, int value);              // ORIG: the entry itself is a member of this type - ecx carries its receiver
};

}

// pdb: IOManager::RequeueTask | IOManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apTask, aeNewPriority
int W_AA2B::Owner2b::FUN_00aa2ba0(void* obj, int value) {   // ORIG: ecx holds the receiver and is parked in ebp; this function cleans its two stack arguments (ret 8)
    unsigned long long total = (unsigned long long)(long long)value * 0x10000LL + (*(long long*)((char*)obj + 0x10) & (long long)0xffffffffff00ffffLL);   // ORIG: cdq sign-extends the argument for the multiply, then add esi,eax ; adc edi,edx - unsigned so the high half is used straight out of its register with no shift at all

    return this->FUN_00aa2860(obj, (int)total, (int)(total >> 32));   // ORIG: push edi ; push esi ; push ebx ; mov ecx,ebp ; call FUN_00aa2860 - low half then high half after the object pointer
}



}   // namespace f3m_00aa2ba0

// @f3 0x00aa54e0 (community match, verified in this file)
namespace f3m_00aa54e0 {
extern "C" void __fastcall __security_check_cookie(unsigned int);
void* __cdecl FUN_00bcca60(int, void*, int, int);
void __cdecl BuildAssetPath(int, char*, int);
int __cdecl FUN_00ec65a6(char*, unsigned int, const char*);
void* __cdecl FUN_00bc7fc0(char*, int, int, int);

struct unkB
{
    int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;int unk18;int unk1C;int unk20;int unk24;
    const char* unk28;
    void* unk2C;
    void* FUN_00aa54e0(int arg1, int arg2);
};
// pdb: QueuedFileEntry::GetFile | QueuedFiles.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeArchiveTypeIndex, aeArchiveType
void* unkB::FUN_00aa54e0(int arg1, int arg2)
{
    void* result = 0;
    char path[260];
    if (unk2C)
    {
        result = FUN_00bcca60(arg1, unk2C, -1, 0);
    }
    else if (unk28)
    {
        if (arg1 == 0)
            BuildAssetPath((int)unk28, path, 0x104);
        else
            FUN_00ec65a6(path, 0x104, unk28);
        result = FUN_00bc7fc0(path, 0, -1, arg2);
    }
    return result;
}
}   // namespace f3m_00aa54e0

// @f3 0x00aa51a0 (community match, verified in this file)
extern volatile long DAT_0116d178;
extern int DAT_00e89814;
extern int DAT_00db785c;
namespace f3m_00aa51a0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace f3m_00aa51a0 {

struct VirtualObj {
    virtual ~VirtualObj();
};

struct CountedObj : VirtualObj {
    int unk04;
    volatile long refs;
    __forceinline void DecRef() {
        if (InterlockedDecrement(&refs) == 0)
            delete this;
    }
};

struct SmartPtr {
    CountedObj* p;
    ~SmartPtr() {
        if (p)
            p->DecRef();
    }
};

struct BaseObj {
    void* vtbl;
    int unk04;
    int unk08;
    ~BaseObj() {
        vtbl = &DAT_00db785c;
        InterlockedDecrement(&DAT_0116d178);
    }
};

struct TaskObj : BaseObj {
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    SmartPtr unk1C;
    VirtualObj* unk20;
    VirtualObj* unk24;

    ~TaskObj();
    void FUN_00aa51a0();
};

// pdb: QueuedFile::~QueuedFile | QueuedFiles.obj | fnv360_0822_retail, call_seq, medium
void TaskObj::FUN_00aa51a0() {
    vtbl = &DAT_00e89814;
    this->TaskObj::~TaskObj();
}

__forceinline TaskObj::~TaskObj() {
    delete unk20;
    delete unk24;
}

}
}   // namespace f3m_00aa51a0

// @f3 0x00ab04e0 (community match, verified in this file)
namespace f3m_00ab04e0 {
namespace f3m_00ab04e0 {
struct Istr;
typedef int (__cdecl* ReadFn)(Istr* s, void* data, unsigned int size, int* comp, int count);
struct Istr { int unk00; int pos; ReadFn read; };
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
    Istr* istr;
};
template <class T> inline void LoadValue(Istr* s, T* v, unsigned int sz = sizeof(T))
{
    int comp = sz;
    s->pos += s->read(s, v, sz, &comp, 1);
}
struct Obj {
    int unk00, unk04, unk08;
    short value;
    unsigned char flag;
    unsigned char unk0f;
    void FUN_00823eb0(Stream& s);
    void FUN_00ab00a0(float f);
    void FUN_00ab04e0(Stream& s);
};
// pdb: FurnitureMark::LoadBinary | BSFurnitureMarker.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream
void Obj::FUN_00ab04e0(Stream& s)
{
    FUN_00823eb0(s);
    {
        bool unused;
        LoadValue(s.istr, &value);
        LoadValue(s.istr, &flag);
        LoadValue(s.istr, &unused);
    }
    if (value < 0) {
        FUN_00ab00a0((float)(value / 1000.0));
    }
}
}
}   // namespace f3m_00ab04e0

// @f3 0x00aa46e0 (community match, verified in this file)
namespace f3m_00aa46e0 {
namespace f3m_00aa46e0 {

extern void* (__stdcall * const DAT_00d9b080)(unsigned long);

struct Owner;
struct Wrapper;

struct TlsObj {
    unsigned int unk00;
    unsigned long tlsIndex;
    Wrapper* __thiscall FUN_0042ba10(Owner* o);
    __forceinline Wrapper* Get(Owner* o) {
        Wrapper* w = (Wrapper*)DAT_00d9b080(tlsIndex);
        if (!w)
            return FUN_0042ba10(o);
        return w;
    }
};

struct Inner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int slot20(unsigned int s0, unsigned int s1);
};

struct Wrapper {
    Inner* inner;
    void __thiscall FUN_00aa3a60(unsigned int r, unsigned int o0, unsigned int o1, unsigned int o2, unsigned int o3);
};

struct Owner {
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    TlsObj* tls;
    void __thiscall FUN_00aa46e0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4);
};


// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::SetAt | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aKey, aData, abReplaceExisting
void __thiscall Owner::FUN_00aa46e0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4) {
    Wrapper* w = tls->Get(this);
    unsigned int a4v = *(volatile unsigned int*)&a4;
    w->FUN_00aa3a60(w->inner->slot20(a1, a2), a1, a2, a3, a4v);
}

}
}   // namespace f3m_00aa46e0

// @f3 0x00aa5370 (community match, verified in this file)
namespace f3m_00aa5370 {
namespace TaskAA5370 {
struct FUN_00424c00 {
    virtual void vfn_base();
    int unk04, unk08, unk0c, unk10, unk14;
    FUN_00424c00(int argument);
};
struct RefObject { int unk00, unk04; long count; };
struct RefPointer { RefObject* object; };
struct FUN_00aa5160 : FUN_00424c00 {
    virtual void vfn_0();
    virtual void vfn_4();
    int threadValue;
    RefPointer reference;
    int count, capacity;
    FUN_00aa5160(int argument) : FUN_00424c00(argument) {
        reference.object = 0;
        count = 0;
        capacity = 0;
        threadValue = DAT_tls_0x0.m_298;
    }
};
struct FUN_00aa5370 : FUN_00aa5160 {
    virtual void vfn_0();
    virtual void vfn_4();
    int extraCount, extraCapacity;
    FUN_00aa5370(int argument);
};
// pdb: QueuedFileEntry::QueuedFileEntry | QueuedFiles.obj | fnv360_0721_retail, call_seq, medium
// pdb params: aePriority
FUN_00aa5370::FUN_00aa5370(int argument) : FUN_00aa5160(argument) {
    extraCount = 0;
    extraCapacity = 0;
}
}
}   // namespace f3m_00aa5370

// @f3 0x00aa9020 (community match, verified in this file)
namespace f3m_00aa9020 {
namespace f3m_00aa9020 {
typedef f3m_00aa85b0::f3m_00aa85b0::Nav Nav;

struct S00aa9020_Ctx
{
    bool FUN_00a9e3b0(f3m_00aa85b0::f3m_00aa85b0::NavEntryItem* item);
    __forceinline unsigned int EmptyMask()
    {
        return (((((unsigned int)(b0E9 == 0) << 1) | (b0E8 == 0)) << 1 | (b0E7 == 0)) << 1) | (b0E6 == 0);
    }
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0;
    short unkE4;
    char b0E6, b0E7, b0E8, b0E9;
};

struct S00aa9020_Nav : Nav
{
    void FUN_00aa9020(Nav* src, S00aa9020_Ctx* ctx);
};

// pdb: BSCompoundFrustum::BuildForPortal | BSCompoundFrustum.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apExistingFrustum, apPortal
void S00aa9020_Nav::FUN_00aa9020(Nav* src, S00aa9020_Ctx* ctx)
{
    Nav* s = src;
    int n = s->m_28;
    m_14.SetSize(n);
    m_04.FUN_00aa8350(s->m_24, true);
    for (int i = 0; i < n; i++) {
        int type = s->m_14.data[i].field0;
        if ((unsigned int)(type - 7) <= 1) {
            bool ok = ctx->FUN_00a9e3b0(&s->m_08[s->m_14.data[i + 1].field0]);
            m_14.data[i].field0 = s->m_14.data[i].field0;
            m_28++;
            m_14.data[i + 1].field0 = m_24;
            m_28++;
            m_08[s->m_14.data[i + 1].field0] = s->m_08[s->m_14.data[i + 1].field0];
            m_24++;
            if (ok && ctx->EmptyMask() == 0xf)
                m_08[s->m_14.data[i + 1].field0].unk60 = 0;
            i++;
        } else {
            m_14.data[i].field0 = type;
            m_28++;
        }
    }
    m_28 = n;
    ((f3m_00aa7f70::task2526::Target*)this)->BSCompoundFrustum_RemoveEmptyGroups();
}
}
}   // namespace f3m_00aa9020

// @f3 0x00ab3120 (community match, verified in this file)
extern char* DAT_00e207a8;
namespace f3m_00ab3120 {
namespace task0569_ab3120 {
struct PointJack
{
    float x, y, z;
    PointJack()
    {}
    PointJack(float a, float b, float c) : x(a), y(b), z(c)
    {}
    static void* operator new[](unsigned int n);
};
struct ColorJack
{
    float r, g, b, a;
    ColorJack() : r(0), g(0), b(0), a(0)
    {}
    static void* operator new[](unsigned int n);
};
struct MatrixJack
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct PoolJack
{
    void* FUN_0086b930(unsigned int);
};
struct S00ab3120_JackGlobals
{
    static PointJack DAT_0108ec68;
    static MatrixJack DAT_00f72574;
    static ColorJack DAT_01066b38, DAT_01066b48, DAT_01066b58;
};
char* __cdecl FUN_008242a0(const char*);
struct NameJack
{
    char* p;
    NameJack(const char* text)
    {
        if (!text)
            p = DAT_00e207a8;
        else
            p = FUN_008242a0(text);
    }
    ~NameJack() throw()
    {
        if (p == DAT_00e207a8)
        {
        }
        else
        {
            long* q = (long*)(p - 8);
            InterlockedDecrement(q);
        }
    }
};
inline void* operator new[](unsigned int n)
{
    return reinterpret_cast<PoolJack&>(::DAT_01090a78).FUN_0086b930(n);
}
inline void* PointJack::operator new[](unsigned int n)
{
    return reinterpret_cast<PoolJack&>(::DAT_01090a78).FUN_0086b930(n);
}
inline void* ColorJack::operator new[](unsigned int n)
{
    return reinterpret_cast<PoolJack&>(::DAT_01090a78).FUN_0086b930(n);
}
struct JackGeometry
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30;
    MatrixJack matrix;
    PointJack position;
    unsigned int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    static void* operator new(unsigned int);
    static void operator delete(void*);
    JackGeometry(int, PointJack*, ColorJack*, int, int, int, char*);
    void FUN_008245d0(const NameJack&);
};

// pdb: BSTestObjects::CreateCoordinateJack | BSTestObjects.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
JackGeometry* __cdecl BSTestObjects_CreateCoordinateJack(float scale)
{
    PointJack* positions = new PointJack[6];
    positions[0] = PointJack(0, 0, 0);
    positions[1] = PointJack(scale, 0, 0);
    positions[2] = PointJack(0, 0, 0);
    positions[3] = PointJack(0, scale, 0);
    positions[4] = PointJack(0, 0, 0);
    positions[5] = PointJack(0, 0, scale);
    ColorJack* colors = new ColorJack[6];
    colors[0] = S00ab3120_JackGlobals::DAT_01066b38;
    colors[1] = S00ab3120_JackGlobals::DAT_01066b38;
    colors[2] = S00ab3120_JackGlobals::DAT_01066b48;
    colors[3] = S00ab3120_JackGlobals::DAT_01066b48;
    colors[4] = S00ab3120_JackGlobals::DAT_01066b58;
    colors[5] = S00ab3120_JackGlobals::DAT_01066b58;
    char* flags3 = new char[6];
    flags3[0] = 1;
    flags3[1] = 0;
    flags3[2] = 1;
    flags3[3] = 0;
    flags3[4] = 1;
    flags3[5] = 0;
    JackGeometry* result9 = new JackGeometry(6, positions, colors, 0, 0, 0, flags3);
    result9->position = S00ab3120_JackGlobals::DAT_0108ec68;
    result9->matrix = S00ab3120_JackGlobals::DAT_00f72574;
    result9->FUN_008245d0(NameJack("BSTestObjects Coordinate Jack"));
    return result9;
}

}
}   // namespace f3m_00ab3120

// @f3 0x00aa49c0 (community match, verified in this file)
extern bool DAT_0116d174;
extern unsigned int DAT_0116d148;
extern unsigned int DAT_0116d154;
extern float DAT_00f75448;
namespace f3m_00aa49c0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

namespace f3m_00aa49c0 {

struct QItem {
    virtual void DeleteThis(int);
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Process();
    int unk04;
    long m_iRefCount;
};

template<class T> struct QPtr {
    T* m_p;
    QPtr() : m_p(0) {}
    ~QPtr() { if (m_p && InterlockedDecrement(&m_p->m_iRefCount) == 0) m_p->DeleteThis(1); }
    QPtr& operator=(T* p) {
        if (m_p != p) {
            if (m_p && InterlockedDecrement(&m_p->m_iRefCount) == 0) m_p->DeleteThis(1);
            m_p = p;
            if (p)
                InterlockedIncrement(&p->m_iRefCount);
        }
        return *this;
    }
    operator T*() const { return m_p; }
    T* operator->() const { return m_p; }
};

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long, void*);

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);

struct QNode {
    QNode* next;
    QPtr<QItem> value;
};

struct QList {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void OnRemoved();
    QNode* head;
    QNode* tail;
};

struct QQueue {
    QList* list;
    QNode** hazardHead;
    QNode** hazardNext;
    void FUN_0042dbf0(QNode* node);
    __declspec(noinline) bool FUN_00aa3640(QPtr<QItem>* out);
};

bool QQueue::FUN_00aa3640(QPtr<QItem>* out)
{
    for (;;) {
        QNode* head = list->head;
        *hazardHead = head;
        if (head != list->head)
            continue;
        QNode* tail = list->tail;
        QNode* next = head->next;
        *hazardNext = next;
        if (head != list->head)
            continue;
        if (!next) {
            *hazardHead = 0;
            *out = 0;
            return false;
        }
        if (head == tail) {
            InterlockedCompareExchange((long volatile*)&list->tail, (long)next, (long)tail);
            continue;
        }
        *out = next->value;
        if (InterlockedCompareExchange((long volatile*)&list->head, (long)next, (long)head) == (long)head) {
            list->OnRemoved();
            next->value = 0;
            *hazardHead = 0;
            *hazardNext = 0;
            FUN_0042dbf0(head);
            return true;
        }
    }
}

struct QThreadEntry { unsigned long threadId; QQueue* queue; };

struct QThreadSlots {
    unsigned int capacity;
    unsigned long tlsIndex;
    QThreadEntry* entries;
    long used;
};

struct QSource {
    virtual void Unk00();
    virtual QQueue* CreateQueue(unsigned int index);
    int unk04, unk08, unk0C, unk10;
    QThreadSlots* slots;
};

struct QCtx {
    virtual void Unk00();
    virtual void Unk04();
    virtual void OnPopped();
    QSource** sources;
    unsigned int count;
    __declspec(noinline) bool FUN_00aa4430(QPtr<QItem>* out);
};

bool QCtx::FUN_00aa4430(QPtr<QItem>* out)
{
    for (unsigned int i = 0; i < count; ++i) {
        QSource* source = sources[i];
        QThreadSlots* slots = source->slots;
        QQueue* queue = (QQueue*)FUN_00d9b080(slots->tlsIndex);
        if (!queue) {
            unsigned int index = InterlockedIncrement(&slots->used) - 1;
            if (index < slots->capacity) {
                queue = source->CreateQueue(index);
                slots->entries[index].queue = queue;
                slots->entries[index].threadId = GetCurrentThreadId();
                TlsSetValue(slots->tlsIndex, queue);
            }
        }
        if (queue->FUN_00aa3640(out)) {
            OnPopped();
            return true;
        }
    }
    return false;
}
typedef bool (__cdecl *QCallback)();
struct QTimeBudget { __int64 start; __int64 limit; };

struct QTarget {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
    QCtx* unk3C;
    int unk40;
    int unk44;
    QCallback unk48;
    QCallback unk4C;
};

}
using namespace f3m_00aa49c0;

__int64 __cdecl FUN_0086c140();

// pdb: IOManager::UpdateQueue | IOManager.obj | fnv360_0822_retail, caller, medium
bool __fastcall FUN_00aa49c0(QTarget* t, int)
{
    if (DAT_0116d174)
        return true;
    unsigned int budget;
    bool result;
    if (t->unk40 == 6) {
        budget = DAT_0116d148;
        result = true;
        DAT_0116d174 = true;
    } else {
        budget = DAT_0116d154;
        result = true;
        DAT_0116d174 = true;
    }
    QTimeBudget time;
    time.start = FUN_0086c140();
    time.limit = (__int64)(budget * DAT_00f75448);
    if (t->unk4C)
        result = t->unk4C();
    QPtr<QItem> item;
    t->unk3C->FUN_00aa4430(&item);
    while (item) {
        item->Process();
        if (t->unk48)
            t->unk48();
        if (FUN_0086c140() - time.start > time.limit) {
            item = 0;
            break;
        }
        t->unk3C->FUN_00aa4430(&item);
    }
    DAT_0116d174 = false;
    return result;
}
}   // namespace f3m_00aa49c0

// @f3 0x00aa3850 (community match, verified in this file)
#include <stddef.h>
namespace f3m_00aa3850 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace IterateAA {
struct Ref;
struct RefCount {
 volatile long value;
};
struct Ref {
 virtual ~Ref();
 unsigned int unk04;
 RefCount refs;
 void IncRef() {InterlockedIncrement(&refs.value);}
 void DecRef() {if(InterlockedDecrement(&refs.value)==0) delete (Ref*)((char*)&refs-offsetof(Ref,refs));}
};
struct Smart {
 Ref* object;
 Smart& operator=(const Smart& other) {
  if(object!=other.object) {
   if(object) object->DecRef();
   object=other.object;
   if(object) object->IncRef();
  }
  return *this;
 }
 Smart& operator=(Ref* other) {
  if(object!=other) {
   if(object) object->DecRef();
   object=other;
   if(object) object->IncRef();
  }
  return *this;
 }
};
struct Pair {unsigned int a,b;};
struct Helper {
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
virtual void Slot2c(Pair,Pair*);
};
inline unsigned int LoadWord(const volatile unsigned int& word) {return word;}
struct Node {Pair key;Smart value;unsigned int flags;unsigned int GetFlags() const {return LoadWord(flags);}};
struct Owner {
 Helper* helper;
 void** out1;void** out2;void** out3;
 unsigned int unk10;
 unsigned int left,right;
 Node* Left() const {return (Node*)(LoadWord(left) & ~1u);}
 Node* Right() const {return (Node*)(LoadWord(right) & ~1u);}
 bool FUN_00aa31d0(void*,unsigned int,unsigned int);
 bool FUN_00aa3850(void*,Pair*,Smart*);
};
}
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::GetNext | IOManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiBucket, arKey, arData
bool IterateAA::Owner::FUN_00aa3850(void* context,Pair* key,Smart* result) {
 bool found;
 for(;;) {
  if(FUN_00aa31d0(context,key->a,key->b)) {
   if(!Right()) {found=false;break;}
   if(Right()->GetFlags()&1) continue;
   helper->Slot2c(Right()->key,key);
   *result=Right()->value;
   found=true;
   if(!(Right()->GetFlags()&1)) break;
   *result=0;
  } else {
   if(!Left()) {found=false;break;}
   if(Left()->GetFlags()&1) continue;
   helper->Slot2c(Left()->key,key);
   *result=Left()->value;
   found=true;
   if(!(Left()->GetFlags()&1)) break;
   *result=0;
  }
 }
 *out1=0;*out2=0;*out3=0;
 return found;
}
}   // namespace f3m_00aa3850

// @f3 0x00aac8e0 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace PolygonWork {
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned);
void __cdecl FUN_0089ec10(void*,unsigned);
struct Point { float x,y,z; bool operator!=(const Point& q)const {return x!=q.x || y!=q.y || z!=q.z;} };
struct IndexArray;
struct IndexTable {
 void* destructor;
 unsigned* (__thiscall* allocate)(IndexArray*,unsigned);
 void (__thiscall* free)(IndexArray*,unsigned*);
};
extern IndexTable DAT_00db72c8;
struct IndexArray {
 IndexTable* table;
 ~IndexArray() {table=&DAT_00db72c8;if(data) Free(data);}
 unsigned* Allocate(unsigned n){return table->allocate(this,n);}
 void Free(unsigned* p){table->free(this,p);}
 unsigned* data; unsigned size,capacity;
 unsigned& GetAt(unsigned i)const{return data[i];}
 IndexArray():table(&DAT_00db72c8),data(0),size(0),capacity(0){}
 void FUN_00799ae0(unsigned n,unsigned old);
 void FUN_005e30b0(unsigned* dst,unsigned* src,unsigned n);
 __forceinline unsigned AddUninitialized() {
  if(size==capacity) {
   if(!capacity) { data=Allocate(4);capacity=4; }
   else {unsigned n=capacity>1024?capacity+1024:capacity*2;FUN_00799ae0(n,size);capacity=n;}
  }
  return ++size-1;
 }
 __forceinline void Add(unsigned value) { unsigned n=AddUninitialized(); data[n]=value; }
 bool ShouldShrink()const {if(capacity>1024) {if(size<=capacity-2048)return true;}else {if(size<=(capacity>>2))return true;}return false;}
 unsigned ShrinkSize()const {return capacity>2048?capacity-1024:capacity>>1;}
 __forceinline void Remove(unsigned index) {
  if(ShouldShrink()) {
   unsigned n=capacity>2048?capacity-1024:capacity>>1;
   unsigned* p=Allocate(n);
   FUN_005e30b0(p,data,index);
   FUN_005e30b0(p+index,data+index+1,size-1);
   Free(data);data=0;data=p;capacity=n;
  } else FUN_005e30b0(data+index,data+index+1,size-index-1);
  --size;
 }
};
struct ShortArray;
struct ShortTable {
 void* destructor;
 unsigned short* (__thiscall* allocate)(ShortArray*,unsigned);
 void (__thiscall* free)(ShortArray*,unsigned short*);
};
extern ShortTable DAT_00dffe50;
struct ShortArray {
 ShortTable* table;
 ~ShortArray();
 unsigned short* Allocate(unsigned n){return table->allocate(this,n);}
 void Free(unsigned short* p){table->free(this,p);}
 unsigned short* data;unsigned size,capacity;
 ShortArray(unsigned initial=0):table(&DAT_00dffe50),data(0),size(0),capacity(0){if(initial){data=Allocate(initial);capacity=initial;}}
 static void* operator new(unsigned n) throw() {return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p);
 void FUN_00548790(unsigned n,unsigned old);
 unsigned FUN_005b9790() {
  if(size==capacity) {
   if(!capacity){data=Allocate(4);capacity=4;}
   else {unsigned n=capacity>1024?capacity+1024:capacity*2;FUN_00548790(n,size);capacity=n;}
  }
  return ++size-1;
 }
 void Add(const unsigned short& value) {unsigned n=FUN_005b9790();data[n]=value;}
 void FUN_00aabed0(unsigned index,bool shrink);
 bool FUN_005c37e0(const unsigned short& value) const;
 unsigned Find(unsigned value) const {
  for(unsigned n=0;n<size;++n)if(data && data[n]==value)return n;
  return -1;
 }
};
struct PointArray {void* vptr;Point* data;unsigned size,capacity; unsigned GetSize()const{return size;} Point& GetAt(unsigned i)const{return data[i];} };
struct Object {
 virtual void slot00();virtual void DeleteThis();
 long refs;
};
struct Node: Object {
 virtual void slot08();
 virtual void slot0c();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1c();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2c();
 virtual void slot30();
 virtual void slot34();
 virtual void slot38();
 virtual void slot3c();
 virtual void slot40();
 virtual void slot44();
 virtual void slot48();
 virtual void slot4c();
 virtual void slot50();
 virtual void slot54();
 virtual void slot58();
 virtual void slot5c();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6c();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7c();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8c();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9c();
 virtual void slota0();
 virtual void slota4();
 virtual void slota8();
 virtual void slotac();
 virtual void slotb0();
 virtual void slotb4();
 virtual void slotb8();
 virtual void slotbc();
 virtual void slotc0();
 virtual void slotc4();
 virtual void slotc8();
 virtual void slotcc();
 virtual void slotd0();
 virtual void slotd4();
 virtual void slotd8();
 virtual void AttachChild(Object*,bool);
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
 Node(unsigned);
 static void* operator new(unsigned n) throw() {return FUN_0089eb90(n);}
 static void operator delete(void* p,unsigned n) {FUN_0089ec10(p,n);}
};
template<class T> struct Ptr {
 T* p;
 __forceinline void operator=(T* q) {
  if(p!=q){T* old=p;if(old && !InterlockedDecrement(&old->refs))old->DeleteThis();p=q;if(q)InterlockedIncrement(&q->refs);}
 }
 T* operator->()const{return p;}
 operator T*()const{return p;}
};
__forceinline void Wrap(int& value,int count) {if(count>=0) {if(value<0)value=value%count+count;else value=value%count;}}
__forceinline int InternalAngle(Point current,Point previous,Point next) {
 const float& z=(current.x-previous.x)*(next.y-current.y)-(next.x-current.x)*(current.y-previous.y);
 return (z<0.0f || z==0.0f) && z!=0.0f;
}
struct Polygon {
 PointArray* vertices;ShortArray* concave;ShortArray* triangles;
 Point* points;void* data10;void* data14;void* data18;void* data1c;
 int unk20,unk24,triangleCount;
 Ptr<Node> root;Ptr<Object> shape;
 bool FUN_00aac1f0(float x,float y,unsigned a,unsigned b,unsigned c);
 bool FUN_00aac810(unsigned,unsigned,unsigned);
 void* FUN_00aac380();Object* FUN_00aabe60(void*);
 void FUN_00aac8e0();
};
__declspec(noinline) bool ShortArray::FUN_005c37e0(const unsigned short& value) const {
 unsigned n;
 for(n=0;n<size;++n) if(data && data[n]==value) goto found;
 n=(unsigned)-1;
found:
 return n!=(unsigned)-1;
}
__declspec(noinline) bool Polygon::FUN_00aac1f0(float x,float y,unsigned a,unsigned b,unsigned c) {
 Point* p=vertices->data;
 Point& pa=p[a]; Point& pb=p[b]; Point& pc=p[c];
 float d1=(pb.x-pa.x)*(y-pa.y)-(x-pa.x)*(pb.y-pa.y);
 if(d1<0.0f) return false;
 float d2=(pc.x-pb.x)*(y-pb.y)-(x-pb.x)*(pc.y-pb.y);
 if(d2<0.0f) return false;
 float d3=(pa.x-pc.x)*(y-pc.y)-(x-pc.x)*(pa.y-pc.y);
 if(d3<0.0f) return false;
 return true;
}
__declspec(noinline) bool Polygon::FUN_00aac810(unsigned a,unsigned b,unsigned c) {
 ShortArray* list=concave;
 if(list && list->size) {
  unsigned count=list->size;
  unsigned short key=(unsigned short)a;
  if(list->FUN_005c37e0(key)) return false;
  for(unsigned n=0;n<count;++n) {
   unsigned v=list->data[n];
   if(v==b || v==c) continue;
   Point& q=vertices->data[v];
   if(FUN_00aac1f0(q.x,q.y,b,a,c)) return false;
  }
 }
 return true;
}
// pdb: BSPolygon2D::Triangulate | BSPolygon.obj | fnv360_0721_beta, objrun, medium
void Polygon::FUN_00aac8e0() {
 IndexArray indexlist; IndexArray& indices=indexlist;
 for(unsigned n=0;n<vertices->GetSize();++n)indices.Add(n);
 Point current=vertices->data[2];
 int i=2;
 Point first=vertices->data[0];
 while(current!=first && indices.size>3) {
  int j=i-2,k=i-1;
  Wrap(j,indices.size);Wrap(k,indices.size);
  if(FUN_00aac810(indices.data[k],indices.data[j],indices.data[i])) {
   if(!triangles)triangles=new ShortArray;
   unsigned item=indices.data[i];triangles->Add((unsigned short)item);
   triangles->Add((unsigned short)indices.data[k]);
   triangles->Add((unsigned short)indices.data[j]);
   ++triangleCount;
   --i;indices.Remove(i);
   if(concave) {
    int a=i-1,b=i+1;
    Wrap(a,indices.size);Wrap(b,indices.size);
    unsigned found=concave->Find(indices.data[i]);
    if(found!=-1 && InternalAngle(vertices->data[indices.data[i]],vertices->data[indices.data[a]],vertices->data[indices.data[b]])==1)concave->FUN_00aabed0(found,true);
    a=i-1;b=i-2;
    Wrap(a,indices.size);Wrap(b,indices.size);
    found=concave->Find(indices.data[a]);
    if(found!=-1 && InternalAngle(vertices->data[indices.data[a]],vertices->data[indices.data[b]],vertices->data[indices.data[i]])==1)concave->FUN_00aabed0(found,true);
   }
   int a=i-1;Wrap(a,indices.size);
   if(indices.data[a]==0) {++i;current=vertices->data[indices.data[i%indices.size]];}
  } else {++i;current=vertices->data[indices.data[i%indices.size]];}
 }
 if(triangles && indices.size==3) {
  triangles->Add((unsigned short)indices.data[2]);
  triangles->Add((unsigned short)indices.data[1]);
  triangles->Add((unsigned short)indices.data[0]);
  ++triangleCount;
 }
 if(triangleCount>0) {
  shape=FUN_00aabe60(FUN_00aac380());
  root=new Node(0);
  root->AttachChild(shape,true);
  if(shape.p) {points=0;data14=0;data18=0;data1c=0;data10=0;}
 }
}
}

// @f3 0x00aaa360 (community match, verified in this file)
namespace f3m_00aaa360 {
namespace f3m_00aaa360 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObject {
    virtual ~RefObject();
    virtual void DeleteThis();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual RefObject* vfn_18(void* arg);

    long m_uiRefCount;

    void IncRefCount() {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct SmartPtr {
    RefObject* m_pObject;
    SmartPtr& operator=(RefObject* pObject) {
        if (m_pObject != pObject) {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (pObject)
                pObject->IncRefCount();
        }
        return *this;
    }
};

struct Node {
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
    int unka0; int unka4; int unka8;
    SmartPtr m_spAC;
    int m_b0;

    void FUN_00ab5d90(Node* dst, void* arg);
    void FUN_00aaa360(Node* dst, void* arg);
};

// pdb: BSMultiBoundNode::CopyMembers | BSMultiBoundNode.obj | fnv360_0822_debug, call_seq, medium
// pdb params: pDest, arCloneData
void Node::FUN_00aaa360(Node* dst, void* arg)
{
    FUN_00ab5d90(dst, arg);
    dst->m_spAC = m_spAC.m_pObject->vfn_18(arg);
    dst->m_b0 = m_b0;
}
}
}   // namespace f3m_00aaa360

// @f3 0x00aafb10 (community match, verified in this file)
namespace f3m_00aafb10 {
namespace bone_lod_save1999 {
struct NiObject;

struct NiBinaryStream {
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream* stream, const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents);
    unsigned int BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        unsigned int written = m_pfnWrite(this, buffer, bytes, componentSizes, numComponents);
        m_uiAbsoluteCurrentPos += written;
        return written;
    }
};

template <class T>
inline void NiStreamSaveBinary(NiBinaryStream& stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(&value, sizeof(T), &size, 1);
}

struct NiStream {
    virtual void Slot000();virtual void Slot004();virtual void Slot008();virtual void Slot00C();virtual void Slot010();virtual void Slot014();virtual void Slot018();virtual void Slot01C();virtual void Slot020();virtual void Slot024();virtual void Slot028();virtual void Slot02C();
    virtual void SaveLinkID(NiObject*);
    unsigned int unk004[147];
    NiBinaryStream* m_pkOstr;
};

template <class T>
inline void NiStreamSaveBinary(NiStream& stream, const T& value)
{
    NiStreamSaveBinary(*stream.m_pkOstr, value);
}

struct Group {
    NiObject** m_aspElements;
    unsigned int unk04;
    unsigned int m_uiCount;
};

struct NiTimeController {
    virtual ~NiTimeController();
    unsigned int unk04[12];
    void SaveBinary(NiStream&);
};

struct NodeGroupArray {
    virtual ~NodeGroupArray();
    Group** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __forceinline unsigned short GetSize() const { return m_usSize; }
    __forceinline Group* GetAt(unsigned int i) const { return m_pBase[i]; }
};

struct NiBoneLODController : NiTimeController {
    unsigned int m_uiLOD;
    unsigned int m_uiLODCount;
    NodeGroupArray m_kNodeGroups;
    virtual void FUN_00aafb10(NiStream& stream);
};

typedef char ControllerSize[(sizeof(NiBoneLODController) == 0x4c) ? 1 : -1];

// pdb: NiBSBoneLODController::SaveBinary | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void NiBoneLODController::FUN_00aafb10(NiStream& stream)
{
    SaveBinary(stream);

    NiStreamSaveBinary(stream, m_uiLOD);
    NiStreamSaveBinary(stream, m_uiLODCount);

    {
        unsigned int uiGroupCount = m_kNodeGroups.GetSize();
        NiStreamSaveBinary(stream, uiGroupCount);
    }

    for (unsigned int i = 0; i < m_kNodeGroups.GetSize(); i++)
    {
        Group* pkGroup = m_kNodeGroups.GetAt(i);
        if (pkGroup)
        {
            unsigned int uiCount = pkGroup->m_uiCount;
            NiStreamSaveBinary(stream, uiCount);
            for (unsigned int j = 0; j < pkGroup->m_uiCount; j++)
            {
                stream.SaveLinkID(pkGroup->m_aspElements[j]);
            }
        }
        else
        {
            unsigned int uiZero = 0;
            NiStreamSaveBinary(stream, uiZero);
        }
    }
}
}
}   // namespace f3m_00aafb10

// @f3 0x00aafeb0 (community match, verified in this file)
namespace f3m_00aafeb0 {

void __cdecl FUN_0089e890(void*);

struct Heap {
    void FUN_0086ba60(void*);
};
extern Heap DAT_01090a78;

struct Elem {
    void* ptr;
    ~Elem() {
        FUN_0089e890(ptr);
    }
    static void operator delete(void* p) {
        DAT_01090a78.FUN_0086ba60(p);
    }
};

struct GroupArray {
    virtual void vf();
    Elem** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short esize;
    unsigned short grow;

    void RemoveAll() {
        for (unsigned short i = 0; i < count; i++) {
            data[i] = 0;
        }
        count = 0;
        esize = 0;
    }
};

struct FUN_00aafff0 {
    virtual void vf();
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
    GroupArray groups;

    void FUN_00aafeb0();
};

void FUN_00aafff0::FUN_00aafeb0()
{
    for (unsigned int i = 0; i < groups.count; i++) {
        Elem* p = groups.data[i];
        if (p) {
            delete p;
        }
    }
    groups.RemoveAll();
}

}

// @f3 0x00aa9a10 (community match, verified in this file)
namespace f3m_00aa9a10 {
namespace Copyaa9a10 {
struct Object {
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
unsigned char unkac,mode,first,second;
void FUN_00ab5d90(Object*,void*);
void BSRangeNode_SetCurrent(unsigned char);
void FUN_00aa9a10(Object*,void*);
};
// pdb: BSRangeNode::CopyMembers | BSRangeNode.obj | fnv360_0822_retail, call_seq, low
// pdb params: pDest, arCloneData
void Object::FUN_00aa9a10(Object* dest,void* context) {
FUN_00ab5d90(dest,context);
dest->first=first;
dest->second=second;
dest->BSRangeNode_SetCurrent(mode);
}
}
}   // namespace f3m_00aa9a10

// @f3 0x00aaef70 (community match, verified in this file)
namespace f3m_00aaef70 {
namespace Attachaaef70 {
struct Config {float time;bool a,b,c,d,e;Config(){time=0;a=0;b=0;c=0;d=0;e=0;}};struct Data;
struct Node {virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac(); virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc(); virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc(); virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void attach(Data*,int);};
struct Data {int unk00,unk04,unk08,unk0c,unk10,unk14;Node* parent;void FUN_008264c0(Config*);};
struct Object {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; Node** items;unsigned short capacity,count;int unka8;Data* data;Node* first(){if(0>=count)return 0;return items[0];}void FUN_00aaef70();};
// pdb: BSSceneGraph::SetCameraScene | BSSceneGraph.obj | fnv360_0822_retail, call_gap, low
void Object::FUN_00aaef70(){Node* parent=data->parent;if(parent!=first()){first()->attach(data,1);Config c;data->FUN_008264c0(&c);}}
}

}   // namespace f3m_00aaef70

// @f3 0x00aaa070 (community match, verified in this file)
namespace f3m_00aaa070 {
namespace Construct303 {
extern long (__stdcall* DAT_00d9b064)(volatile long*);
struct Item {virtual void v00();virtual void destroy();long refs;};struct Ptr {Item* value;Ptr():value(0){}void clear(){Item* p=*(Item* volatile*)&value;if(p){if(!DAT_00d9b064(&p->refs))p->destroy();value=0;}}~Ptr(){clear();}};
struct FUN_00ab5d60 {virtual ~FUN_00ab5d60();int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;unsigned flags;int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8;FUN_00ab5d60();};
struct FUN_00aaa070:FUN_00ab5d60 {Ptr item;FUN_00aaa070();virtual ~FUN_00aaa070();};
// pdb: BSMultiBoundNode::BSMultiBoundNode | BSMultiBoundNode.obj | fnv360_0822_retail, call_seq, medium
FUN_00aaa070::FUN_00aaa070(){item.clear();flags|=0x800;}
}
}   // namespace f3m_00aaa070

// @f3 0x00aaa4e0 (community match, verified in this file)
namespace f3m_00aaa4e0 {
namespace Query322 {
struct Vec3 {float x,y,z;};struct Query {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; Query();};
struct Type {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int type;};struct Input {void FUN_00a9e0b0(Vec3,Query*);};
struct Receiver {virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c(); virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c(); virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c(); virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c(); virtual bool query(Query*);int unk04;int state;};struct Data {int unk00,unk04,unk08;Receiver* receiver;};
struct Owner {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; Data* data;bool FUN_00aaa4e0(Vec3,Type*,Input*);};
// pdb: BSMultiBoundNode::VisibleAgainstActiveOccluders | BSMultiBoundNode.obj | fnv360_0822_retail, call_seq, medium
// pdb params: akViewPoint, akCuller, apOccluder
bool Owner::FUN_00aaa4e0(Vec3 pos,Type* type,Input* input){if(type->type!=3&&type->type!=1&&input){Query q;input->FUN_00a9e0b0(pos,&q);if(data->receiver->query(&q)){data->receiver->state=2;return false;}}return true;}
}
}   // namespace f3m_00aaa4e0

// @f3 0x00ab8a10 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ab8a10 {
namespace Random357 {
// pdb: BSPSysArrayEmitter::GetAPoint | BSPSysArrayEmitter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arPos, arVel
extern double DAT_00dc8dc8;struct Owner{int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int mode;int unk5c;void** data;unsigned short capacity,count;void FUN_00ab7f60(void*,int,int);void FUN_00ab8600(void*,int,int);void FUN_00ab8a10(int,int);};void Owner::FUN_00ab8a10(int a,int b){void* selected;unsigned n=count;if(n){float f=(float)(rand()/DAT_00dc8dc8);unsigned index=(unsigned)(f*n);if(index==n)--index;selected=data[index];}else selected=0;if(mode)FUN_00ab7f60(selected,a,b);else FUN_00ab8600(selected,a,b);}
}

}   // namespace f3m_00ab8a10

// @f3 0x00ab6c60 (community match, verified in this file)
extern void* DAT_00e8b58c[];
namespace f3m_00ab6c60 {
namespace f3m_00ab6c60 {
void* __cdecl FUN_0089eb90(unsigned int size) throw();
void __cdecl FUN_0089e890(void* memory);

struct ObjectMem
{
    static void* operator new(unsigned int size) throw() { return FUN_0089eb90(size); }
    static void operator delete(void* memory) { FUN_0089e890(memory); }
};

struct FUN_00aad5f0 : ObjectMem
{
    void** vtable;
    int unk04;
    int unk08;
    FUN_00aad5f0();
    void BSMultiBoundShape_CopyMembers(FUN_00aad5f0* clone, void* cloning);
};

struct ClonedObject : FUN_00aad5f0
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float unk24;
    ClonedObject() { vtable = DAT_00e8b58c; }
    ClonedObject* FUN_00ab6c60(void* cloning);
};

// pdb: BSMultiBoundCapsule::CreateClone | BSMultiBoundCapsule.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
ClonedObject* ClonedObject::FUN_00ab6c60(void* cloning)
{
    ClonedObject* clone = new ClonedObject;
    BSMultiBoundShape_CopyMembers(clone, cloning);
    clone->unk0c = unk0c;
    clone->unk10 = unk10;
    clone->unk14 = unk14;
    clone->unk18 = unk18;
    clone->unk1c = unk1c;
    clone->unk20 = unk20;
    clone->unk24 = unk24;
    return clone;
}
}
}   // namespace f3m_00ab6c60

// @f3 0x00aadd50 (community match, verified in this file)
extern const char* DAT_0116d998;
extern const char DAT_00e89480[],DAT_00db6ee8[];
namespace f3m_00aadd50 {
namespace Viewer457 {
char* FUN_00847b50(const char*);
char* FUN_00847dd0(const char*,float);
__forceinline char* format(const char* label,const float& value) {return FUN_00847dd0(label,value);}
struct Strings {
 void* table;char** buffer;
 unsigned short capacity,firstFree,count,growBy;
 void FUN_00555790(unsigned);
 void FUN_005b3880(unsigned,char* const&);
 __forceinline void add(char* value) {
  unsigned index=firstFree;
  if(index>=capacity)FUN_00555790(index+growBy);
  FUN_005b3880(index,value);
 }
};
struct Vector {float x,y,z;char* FUN_00823dc0(const char*);};
struct Object {
 void* table;unsigned references,unk08;
 Vector point;
 float value;
 void FUN_008beac0(Strings*);
 void FUN_00aadd50(Strings*);
};
// pdb: BSMultiBoundSphere::GetViewerStrings | BSMultiBoundSphere.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: apStrings
void Object::FUN_00aadd50(Strings* strings) {
 FUN_008beac0(strings);
 strings->add(FUN_00847b50(DAT_0116d998));
 strings->add(point.FUN_00823dc0(DAT_00e89480));
 float scalar=value;
 strings->add(format(DAT_00db6ee8,scalar));
}
}
}   // namespace f3m_00aadd50

// @f3 0x00aa3c20 (community match, verified in this file)
namespace f3m_00aa3c20 {
namespace ns_00aa3c20 {

extern "C" __declspec(dllimport) long __stdcall FUN_00d9b06c(volatile long*, long, long);

struct Helper {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0c();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1c();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2c();
    virtual void Slot30(); virtual void Slot34(); virtual void Slot38(); virtual void Slot3c();
};

struct Pair { unsigned int a, b; };

inline unsigned int LoadWord(const volatile unsigned int& word) { return word; }
inline void StoreWord(volatile unsigned int& word, unsigned int val) { word = val; }

struct Node {
    int unk00, unk04, unk08;
    unsigned int next;
};

struct MarkedPtr {
    unsigned int raw;
    MarkedPtr(Node* p, bool mark) {
        StoreWord(raw, (unsigned int)p);
        if (mark)
            raw = LoadWord(raw) | 1u;
        else
            raw = LoadWord(raw) & ~1u;
    }
    unsigned int Get() const { return LoadWord(raw); }
};

struct Owner_aa3c20 {
    Helper* helper;
    void** out1;
    void** out2;
    void** out3;
    unsigned int prevNext;
    unsigned int left;
    unsigned int right;

    Node* Left() const { return (Node*)(LoadWord(left) & ~1u); }
    Node* Right() const { return (Node*)(LoadWord(right) & ~1u); }
    bool FUN_00aa31d0(void* context, unsigned int a, unsigned int b);
    void FUN_00aa3170(Node* node);
    bool FUN_00aa3c20(void* context, Pair key);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::RemoveAt | IOManager.obj | fnv360_0822_debug, call_seq, medium
// pdb params: aKey
bool Owner_aa3c20::FUN_00aa3c20(void* context, Pair key)
{
    bool ok;
    for (;;) {
        if (!FUN_00aa31d0(context, key.a, key.b)) {
            ok = false;
        } else {
            MarkedPtr oldNext(Right(), false);
            MarkedPtr newNext(Right(), true);
            long prev = oldNext.Get();
            if (FUN_00d9b06c((volatile long*)&Left()->next, newNext.Get(), prev) != prev)
                continue;
            MarkedPtr currNode(Left(), false);
            long cmp = currNode.Get();
            if (FUN_00d9b06c((volatile long*)LoadWord(prevNext), oldNext.Get(), cmp) == cmp)
                FUN_00aa3170(Left());
            else
                FUN_00aa31d0(context, key.a, key.b);
            helper->Slot3c();
            ok = true;
        }
        break;
    }
    *out1 = 0;
    *out2 = 0;
    *out3 = 0;
    return ok;
}

}
}   // namespace f3m_00aa3c20

// @f3 0x00aa1ea0 (community match, verified in this file)
namespace f3m_00aa1ea0 {
namespace f3m_00aa1ea0 {
struct Token {void FUN_00aa91e0();};
struct Context {unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; int mode; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; Token* token;};
struct Child {void FUN_00826660(Context*);};
struct Type {unsigned unk00,unk04;volatile int kind;};
struct Info {unsigned unk00,unk04,unk08;Type* type;};
struct Owner {
unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c;
Child** children;unsigned short capacity,count,active,unkaa;
Info* info;int mode;unsigned unkb4,unkb8;void* extra;unsigned unkc0,unkc4,unkc8;Token* token;
void FUN_00aa1ea0(Context*);
};
// pdb: BSMultiBoundRoom::OnVisible | BSMultiBoundRoom.obj | fnv360_0822_retail, vtable_prefix, medium
// pdb params: kCuller
void Owner::FUN_00aa1ea0(Context* context) {
    if(!active && !extra) return;
    int kind=info->type->kind;
    if(context->mode!=3 && context->mode!=1 && kind!=1) return;

    Token* oldToken=context->token;
    Token* current=token;
    int oldMode=context->mode;
    if(context->mode!=3) context->mode=mode;
    if(context->mode!=3 && context->mode!=1) {
        if(current) current->FUN_00aa91e0();
        context->token=current;
        if(current) current->FUN_00aa91e0();
    }
    for(unsigned i=0;i<count;++i) {
        Child* child=children[i];
        if(child) child->FUN_00826660(context);
    }
    context->mode=oldMode;
    if(oldMode!=3 && oldMode!=1) context->token=oldToken;
}
}



}   // namespace f3m_00aa1ea0

// @f3 0x00aad1b0 (community match, verified in this file)
namespace f3m_00aad1b0 {
typedef f3m_00ab8130::fo3_ab8130::RefObj Ref;
struct Point {float x,y,z;};
extern Point DAT_0108ec68;
extern float DAT_00eaad58;
struct Points {unsigned unk00;Point* data;int count;void FUN_00aac5f0();};
struct FUN_00aad1b0 {
    Points* points;void* convex;unsigned unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    int count;unsigned unk28;
    NiPointer<Ref> first,second;
    Point position;
    FUN_00aad1b0(Points*);
    float FUN_00aac080();void FUN_00aac680();
};
// pdb: BSPolygon2D::BSPolygon2D | BSPolygon.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apVertexSimpleArray
FUN_00aad1b0::FUN_00aad1b0(Points* input) : first(0),second(0) {
    count=input->count;
    points=input;
    unk08=0;
    convex=0;
    unk28=0;
    second=(Ref*)0;
    first=(Ref*)0;
    position=DAT_0108ec68;
    if(FUN_00aac080()>=0.0f) points->FUN_00aac5f0();
    FUN_00aac680();
}
}

// @f3 0x00ab7810 (community match, verified in this file)
namespace f3m_00ab7810 {
namespace f3m_00ab7810 {
struct Emitter : f3m_00ab76f0::MeshCursorAB76::Emitter {
 unsigned unkc4,unkc8,unkcc,unkd0,unkd4,unkd8;float elapsed;
 bool BSMasterParticleSystem_ChildHasActiveParticles();void FUN_0082db90(float*,void*);
 void FUN_00ab7810(float*,void*);
};
// pdb: BSMasterParticleSystem::UpdateDownwardPass | BSMasterParticleSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: UpdateData, uFlags
void Emitter::FUN_00ab7810(float* time,void* data){
 BSMasterParticleSystem_ClearUnreferencedEmitters();
 if(accepted>0 || BSMasterParticleSystem_ChildHasActiveParticles()){
  float total=*time+elapsed;
  elapsed=total;
  float saved=*time;
  *time=total;
  FUN_0082db90(time,data);
  *time=saved;
 }
}
}
}   // namespace f3m_00ab7810

// @f3 0x00abb340 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* dest, long exchange, long comparand);
namespace f3m_00abb340 {
struct Lock
{
    long volatile owner;
    unsigned int depth;
    void FUN_00409a80(const char* source);
    void Release()
    {
        if (--depth == 0)
        {
            const long previousOwner = owner;
            InterlockedCompareExchange(&owner, 0, previousOwner);
        }
    }
};
extern Lock DAT_0106e5a0;
struct Item { virtual void v00(); virtual void DeleteThis(); volatile long refs; };
struct Node { Node* next; void* key; Item* value; };
extern Node* DAT_0106e588;
struct Map
{
    Node* first;
    Node* last;
    int count;
    void FUN_00abb340();
};

// pdb: NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::RemoveAll | BSTempEffectSimpleDecal.obj | fnv360_0822_retail, call_seq, high
void Map::FUN_00abb340()
{
    Node* n = first;
    if (n)
    {
      do
      {
        Node* cur = n;
        n = cur->next;
        Item* value = cur->value;
        if (value)
        {
            if (InterlockedDecrement(&value->refs) == 0)
                value->DeleteThis();
            cur->value = 0;
        }
        DAT_0106e5a0.FUN_00409a80(0);
        cur->key = 0;
        cur->next = DAT_0106e588;
        DAT_0106e588 = cur;
        DAT_0106e5a0.Release();
      } while (n);
    }
    count = 0;
    first = 0;
    last = 0;
}
}

// @f3 0x00aaa6d0 (community match, verified in this file)
namespace f3m_00aaa6d0 {
namespace f3m_00aaa6d0 {
struct TargetAAA6D0 {
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
    virtual unsigned dispatch(void*);
};
struct LinkAAA6D0 {
    unsigned unk00, unk04, unk08;
    TargetAAA6D0* target;
};
struct OwnerAAA6D0 {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c;
    unsigned unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c;
    unsigned unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c;
    unsigned unk90, unk94, unk98, unk9c;
    unsigned unka0, unka4, unka8;
    LinkAAA6D0* link;
    unsigned FUN_00aaa6d0(void* argument);
};
// pdb: BSMultiBoundNode::CheckBound | BSMultiBoundNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: aTargetBound
unsigned OwnerAAA6D0::FUN_00aaa6d0(void* argument) {
    return link->target->dispatch(argument);
}
}
}   // namespace f3m_00aaa6d0

// @f3 0x00aa70e0 (community match, verified in this file)
#include <string.h>
namespace f3m_00aa70e0 {
namespace Small530 {
long __cdecl FUN_00c047de(const char*);
struct Owner {int unk00,unk04;const char* name;int unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac;long value;bool FUN_00aa70e0();};
// pdb: BSValueNode::ParseNameForValue | BSValueNode.obj | fnv360_0822_retail, vtable, medium
bool Owner::FUN_00aa70e0(){
    unsigned length;
    bool found=false;
    const char* text=name;
    length=(unsigned)strlen(text);
    unsigned count=1;
    const char* cursor=text+length-1;
    while(((*cursor>='0'&&*cursor<='9')||*cursor=='#'||*cursor=='@')&&count<=length){++count;--cursor;}
    try { length-=count; } catch(...) {}
    const char* suffix=name+length+1;
    if(*suffix)found=true;
    value=FUN_00c047de(suffix);
    return found;
}}
}   // namespace f3m_00aa70e0

// @f3 0x00aa42d0 (community match, verified in this file)
namespace f3m_00aa42d0 {
namespace S00aa42d0_ns {

struct S00aa42d0_Task {
    virtual void DeleteThis(int flags);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Run(int arg);
    int field04;
    volatile long refs;
};

struct S00aa42d0_TaskPtr {
    S00aa42d0_Task* p;
    S00aa42d0_TaskPtr() : p(0) {}
    ~S00aa42d0_TaskPtr() {
        S00aa42d0_Task* t = p;
        if (t && InterlockedDecrement(&t->refs) == 0)
            t->DeleteThis(1);
    }
};

struct S00aa42d0_JobData {
    int field04;
    int startIndex;
    int field0c;
    int field10;
    int field14;
    unsigned char flags;
    int field1c;
    S00aa42d0_JobData() {
        startIndex = 0;
        field10 = 0;
        field14 = 0;
        flags = 0;
    }
};

struct S00aa42d0_Job : S00aa42d0_JobData {
    virtual ~S00aa42d0_Job() {}
    virtual void Release();
    void Start(int start) {
        Release();
        startIndex = start;
        flags &= 0xfc;
    }
};

struct S00aa42d0_Owner {
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50;
    void (*onLock)();
    void (*onUnlock)();
    bool FUN_00aa25b0();
    bool FUN_00aa2650();
    bool FUN_00aa3df0(S00aa42d0_Job* job, __int64* key, S00aa42d0_TaskPtr* task, bool first);
    void Lock() { if (FUN_00aa25b0() && onLock) onLock(); }
    void Unlock() { if (FUN_00aa2650() && onUnlock) onUnlock(); }
    void FUN_00aa42d0(int maxPriority, int arg);
};

}

__declspec(noinline) bool S00aa42d0_ns::S00aa42d0_Owner::FUN_00aa3df0(
    S00aa42d0_Job* job, __int64* key, S00aa42d0_TaskPtr* task, bool first)
{
    FUN_00aa25b0();
    job->flags = first ? 2 : 0;
    *key = job->startIndex;
    task->p = (S00aa42d0_Task*)field00;
    return task->p != 0;
}

// pdb: IOManager::RequeuePrioritiesToNewPriority | IOManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: aeOldPriority, aeNewPriority
void S00aa42d0_ns::S00aa42d0_Owner::FUN_00aa42d0(int maxPriority, int arg)
{
    if (maxPriority <= arg)
        return;
    Lock();
    S00aa42d0_Job job;
    job.Start(arg * 4 + 4);
    while (!(job.flags & 2)) {
        __int64 key = 0;
        S00aa42d0_TaskPtr task;
        if (FUN_00aa3df0(&job, &key, &task, true)) {
            if ((unsigned char)(key >> 16) > maxPriority)
                break;
            task.p->Run(arg);
        }
    }
    Unlock();
}
}   // namespace f3m_00aa42d0

// @f3 0x00aa44f0 (community match, verified in this file)
#include <stddef.h>
extern __declspec(thread) int DAT_0117c298;
namespace f3m_00aa44f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Heap {void* FUN_0086b930(unsigned int);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
struct MemoryContext {int saved;MemoryContext(){saved=DAT_0117c298;DAT_0117c298=6;}~MemoryContext(){DAT_0117c298=saved;}};
struct RefObject {
 virtual ~RefObject();
 int unk04;
 volatile long refs;
 void IncRefCount(){InterlockedIncrement(&refs);}
 void DecRefCount(){long r=InterlockedDecrement(&refs);if(r==0)delete this;}
};
template <class T> class NiPtr {
public:
 T* m_pObject;
 NiPtr(T* object=0){m_pObject=object;if(m_pObject)m_pObject->IncRefCount();}
 ~NiPtr(){if(m_pObject)m_pObject->DecRefCount();}
 NiPtr<T>& operator=(T* object){if(m_pObject!=object){if(m_pObject)m_pObject->DecRefCount();m_pObject=object;if(m_pObject)m_pObject->IncRefCount();}return *this;}
};
struct Node;
struct Link {
 volatile unsigned int value;
 Node* Get() const {return (Node*)(value & ~1u);}
 void Clear() {value=0;}
 Node* Get2() {Link* link=this; return (Node*)(link->value & ~1u);}
 void Clear2() {Link* link=this; link->value=0;}
};
struct Node {
 int key0;
 int key1;
 NiPtr<RefObject> data;
 Link next;
 static void* operator new(size_t n){return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}
};
struct FUN_005e5280 {
 unsigned int unk00,unk04,unk08,unk0C;
 FUN_005e5280(unsigned int);
 ~FUN_005e5280(){FUN_00aa37d0();}
 void FUN_00aa37d0();
 static void* operator new(size_t n){return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}
};
struct Map {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
 virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20();
 virtual void ReleaseKey(int key0, int key1);
 Node** deletedBuffers;
 unsigned int bucketCount;
 Link* buckets;
 unsigned int deleteBatchSize;
 FUN_005e5280* manager;
 volatile unsigned int itemUpdates;
 Link& GetBucket(unsigned int i) {return buckets[i];}
 Link* BucketPtr(unsigned int i) {return &buckets[i];}
 void FUN_00aa44f0(bool keepPool);
};
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::RemoveAll | IOManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: abCalledByDestructor
void Map::FUN_00aa44f0(bool keepPool){
 MemoryContext context;
 if(!manager)
  return;
 unsigned int threads=manager->unk00;
 delete manager;
 manager=0;
 itemUpdates=0;
 for(unsigned int i=0;i<bucketCount;i++){
  Node* node=buckets[i].Get();
  buckets[i].Clear();
  while(node){
   Node* next=node->next.Get();
   node->next.value=0;
   node->data=0;
   ReleaseKey(node->key0,node->key1);
   delete node;
   node=next;
  }
 }
 if(!keepPool)
  manager=new FUN_005e5280(threads);
}
}

// @f3 0x00aa6dc0 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
namespace f3m_00aa6dc0 {
struct RefObj {
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_iRefCount;
    void IncRefCount() { InterlockedIncrement(&m_iRefCount); }
    void DecRefCount() { long count=InterlockedDecrement(&m_iRefCount); if (count == 0) DeleteThis(); }
};
struct SP {
    RefObj* m_p;
    SP() : m_p(0) {}
    SP(RefObj* p) { m_p = p; if (m_p) m_p->IncRefCount(); }
    ~SP() { if (m_p) m_p->DecRefCount(); }
    __declspec(noalias) SP& FUN_008e9650(RefObj* p);
    __declspec(noinline) SP& FUN_008e9600(const SP& o);
    operator RefObj*() const { return m_p; }
};
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089e890(void* p);
struct FUN_00aa67b0 : RefObj {
    void* member;
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089e890(p); }
    FUN_00aa67b0(void* src);
};
struct RtType { int x; };
extern RtType DAT_0108ec84;
struct Handle { int unk00; int unk04; void* unk08; void* Get() const { return unk08; } };
Handle* __cdecl FUN_00424d50(RtType* type, RefObj* key);
struct Map {
    bool FUN_00bea7b0(void* k, void** out);
    bool Contains(void* k) { void* out; return FUN_00bea7b0(k, &out); }
    void FUN_00880f70(RefObj* k, unsigned int v);
};
struct Owner;
struct Other { bool FUN_00ab9ec0(Owner* o, RefObj* k); };
struct Array {
    void* m_vtbl;
    SP* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void FUN_0082c0d0(unsigned int uiMaxSize);
    __declspec(noinline) void FUN_0082b0b0(unsigned int uiIndex, const SP& element);
    unsigned int Add(const SP& element) {
        unsigned int uiIndex = m_uiSize;
        if (uiIndex >= m_uiMaxSize)
            FUN_0082c0d0(uiIndex + m_uiGrowBy);
        FUN_0082b0b0(uiIndex, element);
        return uiIndex;
    }
};
SP& SP::FUN_008e9600(const SP& o)
{
    if (m_p != o.m_p) {
        if (m_p)
            m_p->DecRefCount();
        m_p = o.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    return *this;
}
void Array::FUN_0082b0b0(unsigned int uiIndex, const SP& element)
{
    if (uiIndex >= m_uiSize) {
        m_uiSize = uiIndex + 1;
        if (element.m_p)
            m_uiESize++;
    } else if (element.m_p) {
        if (!m_pBase[uiIndex].m_p)
            m_uiESize++;
    } else if (m_pBase[uiIndex].m_p) {
        m_uiESize--;
    }
    m_pBase[uiIndex].FUN_008e9600(element);
}
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
    Array arr;
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
    Map reader;
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
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    Map* m_5c4;
    Other* m_5c8;
    bool FUN_0082d1c0(RefObj* key);
    bool BSStream_RegisterSaveObject(RefObj* key);
};

__forceinline bool Find(Map* map, void* k)
{
    void* out;
    out = 0;
    if (map && k)
        map->FUN_00bea7b0(k, &out);
    return out != 0;
}

// pdb: BSStream::RegisterSaveObject | BSStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable_prefix), high
bool Owner::BSStream_RegisterSaveObject(RefObj* key)
{
    if (m_5c4) {
        RefObj* obj = key;
        if (reader.Contains(key))
            return false;
        SP sp;
        Handle* h = FUN_00424d50(&DAT_0108ec84, key);
        if (h && Find(m_5c4, h->unk08)) {
            sp.FUN_008e9650(new FUN_00aa67b0(h->Get()));
            obj = sp.m_p;
        } else {
            m_5c8->FUN_00ab9ec0(this, key);
        }
        unsigned int idx = arr.m_uiSize;
        reader.FUN_00880f70(key, idx);
        {
            SP t(obj);
            unsigned int uiIndex = arr.m_uiSize;
            Array& a = arr;
            if (uiIndex >= a.m_uiMaxSize)
                a.FUN_0082c0d0(uiIndex + a.m_uiGrowBy);
            a.FUN_0082b0b0(uiIndex, t);
        }
        return true;
    }
    return FUN_0082d1c0(key);
}
}

// @f3 0x00aa3d10 (community match, verified in this file)
namespace f3m_00aa3d10 {
namespace f3m_00aa3d10 {
extern "C" __declspec(dllimport) long __stdcall FUN_00d9b06c(volatile long*, long, long);
inline unsigned int LoadWord(const volatile unsigned int& word) { return word; }
inline void StoreWord(volatile unsigned int& word, unsigned int val) { word = val; }
struct Node {
    int unk00, unk04, unk08;
    unsigned int next;
};
struct MarkedPtr {
    unsigned int raw;
    MarkedPtr(Node* p, bool mark) {
        StoreWord(raw, (unsigned int)p);
        if (mark)
            raw = LoadWord(raw) | 1u;
        else
            raw = LoadWord(raw) & ~1u;
    }
    unsigned int Get() const { return LoadWord(raw); }
};
struct Owner {
    void* unk00;
    void** out1;
    void** out2;
    void** out3;
    unsigned int prevNext;
    unsigned int left;
    unsigned int right;
    Node* Left() const { return (Node*)(LoadWord(left) & ~1u); }
    Node* Right() const { return (Node*)(LoadWord(right) & ~1u); }
    bool FUN_00aa33a0(unsigned int a, unsigned int b);
    void FUN_00aa3170(Node* node);
    bool FUN_00aa3d10(unsigned int a, unsigned int b);
};
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::Remove | IOManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiBucket, arData
bool Owner::FUN_00aa3d10(unsigned int a, unsigned int b)
{
    bool ok;
    for (;;) {
        if (!FUN_00aa33a0(a, b)) {
            ok = false;
        } else {
            MarkedPtr oldNext(Right(), false);
            MarkedPtr newNext(Right(), true);
            long prev = oldNext.Get();
            if (FUN_00d9b06c((volatile long*)&Left()->next, newNext.Get(), prev) != prev)
                continue;
            MarkedPtr currNode(Left(), false);
            long cmp = currNode.Get();
            if (FUN_00d9b06c((volatile long*)LoadWord(prevNext), oldNext.Get(), cmp) == cmp)
                FUN_00aa3170(Left());
            else
                FUN_00aa33a0(a, b);
            ok = true;
        }
        break;
    }
    *out1 = 0;
    *out2 = 0;
    *out3 = 0;
    return ok;
}
}
}   // namespace f3m_00aa3d10

// @f3 0x00aa2be0 (community match, verified in this file)
extern __declspec(thread) int DAT_0117c298;
namespace Task3209 {
struct Heap { void* FUN_0086b930(unsigned); };
extern Heap DAT_01090a78;
struct Context {
 int saved;
 Context(int value) { saved=DAT_0117c298; DAT_0117c298=value; }
 ~Context() { DAT_0117c298=saved; }
};
struct FUN_00aa28f0 {
 unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
 FUN_00aa28f0(void*,void*);
 static void* operator new(unsigned size) { return DAT_01090a78.FUN_0086b930(size); }
 static void operator delete(void*) {}
};
struct FUN_00aa2be0 {
 virtual ~FUN_00aa2be0();
 FUN_00aa28f0** queues;
 unsigned size,count;
 FUN_00aa2be0(unsigned,void*,void*);
};
}
// pdb: LockFreePriorityQueue<NiPointer<IOTask> >::LockFreePriorityQueue<NiPointer<IOTask> > | IOManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiPriorityCount, aiMaxThreads, aiDeleteBatchSize
Task3209::FUN_00aa2be0::FUN_00aa2be0(unsigned n,void* a,void* b) {
 Context context(6);
 count=0;
 size=n;
 queues=new FUN_00aa28f0*[size];
 for(unsigned i=0;i<size;i++) queues[i]=new FUN_00aa28f0(a,b);
}

// @f3 0x00aa4730 (community match, verified in this file)
namespace f3m_00aa4730 {
struct LockFreeMap;
struct KeyHandler {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual unsigned int Hash(__int64 key);
};
struct MapNode {
    KeyHandler* handler;
    bool FUN_00aa3c20(unsigned int hash, __int64 key);
};
struct NodeStore {
    int unk00;
    unsigned long tlsIndex;
    MapNode* FUN_0042ba10(LockFreeMap* map);
};
typedef MapNode* (__stdcall* TlsGetter)(unsigned long index);
extern TlsGetter const DAT_00d9b080;
inline bool Call(MapNode* node, __int64 key)
{
    return node->FUN_00aa3c20(node->handler->Hash(key), key);
}
struct LockFreeMap {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual bool FUN_00aa4730(__int64 key);
    int unk04, unk08, unk0c, unk10;
    NodeStore* store;
    MapNode* GetNode()
    {
        NodeStore* s = store;
        unsigned long index = s->tlsIndex;
        MapNode* node = DAT_00d9b080(index);
        if (node)
            return node;
        return s->FUN_0042ba10(this);
    }
};
// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::RemoveAt | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aKey
bool LockFreeMap::FUN_00aa4730(__int64 key)
{
    return Call(GetNode(), key);
}
}

// @f3 0x00aa4100 (community match, verified in this file)
namespace f3m_00aa4100 {
namespace f3m_00aa4100 {

extern "C" __declspec(dllimport) unsigned long __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct NiRef {
    virtual void Destroy(int freeMem);
    int unk04;
    volatile long refCount;
};

struct NiPtr {
    NiRef* p;
    NiPtr() {}
    ~NiPtr() {
        if (p && InterlockedDecrement(&p->refCount) == 0) p->Destroy(1);
    }
};

struct Ctx {
    __declspec(noalias) bool FUN_00aa3d10(int a, NiPtr* out);
};

struct TlsHolder {
    int unk00;
    unsigned long tlsIndex;
    void* FUN_0042ba10(void* owner);
};

struct Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    TlsHolder* m_pTls;
    bool FUN_00aa4100(int arg1, NiPtr arg2);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::Remove | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiBucket, aData
bool Owner::FUN_00aa4100(int arg1, NiPtr arg2)
{
    TlsHolder* holder = m_pTls;
    void* ctx = (void*)TlsGetValue(holder->tlsIndex);
    if (ctx == 0)
        ctx = holder->FUN_0042ba10(this);
    return ((Ctx*)ctx)->FUN_00aa3d10(arg1, &arg2);
}
}
}   // namespace f3m_00aa4100

// @f3 0x00aa9650 (community match, verified in this file)
extern void* DAT_00db88f4;
namespace f3m_00aa9650 {
struct DispatchTransitionA293 {
    void** dispatch;
    void FUN_0082e4f0();
    void FUN_00aa9650();
};
// pdb: BSTempNodeManager::~BSTempNodeManager | BSTempNodeManager.obj | fnv360_0822_retail, call_seq, high
void DispatchTransitionA293::FUN_00aa9650() {
    dispatch=&DAT_00db88f4;
    FUN_0082e4f0();
}
}   // namespace f3m_00aa9650

// @f3 0x00ab5d80 (community match, verified in this file)
extern char DAT_00e8b28c;
namespace f3m_00ab5d80 {
struct CleanupObject { void* table; void FUN_0082e4f0(); void FUN_00ab5d80(); };
// pdb: BSNiNode::~BSNiNode | BSNiNode.obj | fnv360_0822_retail, call_seq, high
void CleanupObject::FUN_00ab5d80() { table = &DAT_00e8b28c; FUN_0082e4f0(); }
}   // namespace f3m_00ab5d80

// @f3 0x00aaa9d0 (community match, verified in this file)
namespace f3m_00aaa9d0 {
// pdb: BSWindModifier::SetWind | BSWindModifier.obj | fnv360_0822_retail, call_gap, low
// pdb params: afSpeed, afAngle
void __cdecl FUN_00aaa9d0(float arg1, float arg2)
{
    AA::V3 in;
    f3_00aabd50::ThreeByThreeMatrix m;
    float sn, cs;
    in.y=arg1 * 100.0; in.x=0.0f; in.z=0.0f;
    fnv_SinCos(arg2, sn, cs);
    m.m_afEntries[0][0] = cs;
    m.m_afEntries[0][1] = sn;
    m.m_afEntries[0][2] = 0.0f;
    m.m_afEntries[1][0] = -sn;
    m.m_afEntries[1][1] = cs;
    m.m_afEntries[1][2] = 0.0f;
    m.m_afEntries[2][0] = 0.0f;
    m.m_afEntries[2][1] = 0.0f;
    m.m_afEntries[2][2] = 1.0f;
    AA::V3 r;
    r.x = m.GetEntry(0,0)*in.x + m.GetEntry(1,0)*in.y + m.GetEntry(2,0)*in.z;
    r.y = m.GetEntry(0,1)*in.x + m.GetEntry(1,1)*in.y + m.GetEntry(2,1)*in.z;
    r.z = m.GetEntry(0,2)*in.x + m.GetEntry(1,2)*in.y + m.GetEntry(2,2)*in.z;
    DAT_0116d728 = r;
}
}   // namespace f3m_00aaa9d0

// @f3 0x00aa3000 (community match, verified in this file)
#include <string.h>

namespace naa3000 {

extern __declspec(thread) int g_tls[];

struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* memory);
};
extern Heap DAT_01090a78;

struct TlsGuard {
    int saved;
    TlsGuard(int v) { saved = g_tls[0x298 / 4]; g_tls[0x298 / 4] = v; }
    ~TlsGuard() { g_tls[0x298 / 4] = saved; }
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Ref {
    virtual ~Ref();
    int unk04;
    long refCount;
    void Release()
    {
        if (InterlockedDecrement(&refCount) == 0)
            delete this;
    }
};

struct Node {
    int item;
    int unk04;
    union {
        Node* next;
        Ref* ref;
    };
    ~Node()
    {
        if (ref)
            ref->Release();
    }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Entry {
    Node* node;
    static void* operator new[](unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

// pdb: BSSegmentedTriShape::CopyMembers | BSSegmentedTriShape.obj | fnv360_0822_retail, objrun_prop, high (was: CopyEntries)
__forceinline void BSSegmentedTriShape_CopyMembers(Entry* dst, const Entry* src, unsigned int n)
{
    memcpy(dst, src, n * sizeof(Entry));
}

struct Count {
    unsigned int count;
};

struct Source {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(int item, int other);
    Entry* data;
    int unk08;
    int unk0c;
    int unk10;
    Count* count;
};

struct Owner {
    Source* source;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Node* head;
    unsigned int count;
    void FUN_00aa3000();
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::ScanForDeletedNodes | IOManager.obj | fnv360_0721_beta, caller, low
void Owner::FUN_00aa3000()
{
    TlsGuard guard(6);
    unsigned int n = source->count->count * 3;
    Entry* entries = new Entry[n];
    BSSegmentedTriShape_CopyMembers(entries, ((Source* volatile*)&source)[0]->data, n);
    Node* newHead = 0;
    unsigned int newCount = 0;
    while (head)
    {
        Node* node = head;
        unsigned int i = 0;
        head = node->next;
        for (; i < n; i++)
        {
            if (node == entries[i].node)
                goto found;
        }
        node->next = 0;
        source->v24(node->item, node->unk04);
        delete node;
        continue;
    found:
        node->next = newHead;
        newCount++;
        newHead = node;
    }
    delete[] entries;
    head = newHead;
    count = newCount;
}

}

// @f3 0x00ab47e0 (community match, verified in this file)
extern char DAT_0116daf4;
namespace f3m_00ab47e0 {
extern "C" void (__stdcall* DAT_00fdf05c)(void*);
extern "C" void (__stdcall* DAT_00fdf100)(void*);
namespace fnv_00c5b370 {
struct RefObject
{
    virtual ~RefObject();
    virtual void DeleteThis();
    long refCount;

    inline void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    inline void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};

template <class T> class PtrAb
{
  public:
    T* m_p;
    inline PtrAb(T* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    inline ~PtrAb()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    inline bool operator==(T* rhs) const { return m_p == rhs; }
    inline operator T*() const
    {
        return m_p;
    }
    inline PtrAb& operator=(const PtrAb& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};

struct ItemNode
{
    ItemNode* next;
    ItemNode* prev;
    PtrAb<RefObject> item;
};

struct NodePool { unsigned int count; ItemNode* FUN_00423640(); };
struct ItemList {
    ItemNode* tail;
    ItemNode* head;
    union { unsigned int count; NodePool pool; };
    __declspec(noinline) void FUN_00827100(const PtrAb<RefObject>& ref);
};
void ItemList::FUN_00827100(const PtrAb<RefObject>& ref) {
    ItemNode* node=pool.FUN_00423640();
    node->item=ref;
    node->next=0;
    node->prev=head;
    if(head) head->next=node; else tail=node;
    head=node; ++count;
}

struct PendingList
{
    ItemNode* head;
    __declspec(noinline) PtrAb<RefObject> FUN_00ab43e0(ItemNode*& iter);
    inline ItemNode* GetHead() const
    {
        return head;
    }
    inline PtrAb<RefObject>& GetNext(ItemNode*& iter)
    {
        PtrAb<RefObject>& item = iter->item;
        iter = iter->next;
        return item;
    }
};

__declspec(noinline) PtrAb<RefObject> PendingList::FUN_00ab43e0(ItemNode*& iter)
{
    ItemNode* node = iter;
    iter = node ? node->next : 0;
    return node ? node->item : PtrAb<RefObject>(0);
}


struct ItemQueue
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
    PendingList pending;
    int unk54;
    int unk58;
    ItemList items;
    void FUN_00ab47e0(RefObject* obj);
};

// pdb: BSPortalGraph::DetachAlwaysRenderChild | BSPortalGraph.obj | fnv360_0822_retail, call_gap, low
// pdb params: pkChild
void ItemQueue::FUN_00ab47e0(RefObject* obj)
{
    DAT_00fdf05c(&DAT_0116daf4);
    items.FUN_00827100(obj);
    ItemNode* it = pending.GetHead();
    while (it)
    {
        ItemNode* cur = it;
        if (pending.GetNext(it) == obj)
        {
            pending.FUN_00ab43e0(cur);
            break;
        }
    }
    DAT_00fdf100(&DAT_0116daf4);
}
}
}   // namespace f3m_00ab47e0

// @f3 0x00aa8410 (community match, verified in this file)
namespace f3m_00aa8410 {
struct NiPoint3 { float x, y, z; NiPoint3() {} };
extern NiPoint3 DAT_0108ec68;
extern int DAT_00e89ed0;
extern int DAT_00e89ebc;

struct FUN_00832f20 { float v[4]; FUN_00832f20(); };

struct NiFrustumPlanes {
    FUN_00832f20 planes[6];
    unsigned int m_uiActivePlanes;
    NiFrustumPlanes() { m_uiActivePlanes = 0x3f; }
};

struct ArrayVtbl { virtual void unk00(); virtual void* Allocate(unsigned int uiCount); };

struct PlanesArray {
    void* vtable;
    NiFrustumPlanes* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiAllocSize;
    PlanesArray() { vtable = &DAT_00e89ed0; m_pBuffer = 0; m_uiSize = 0; m_uiAllocSize = 0; }
    ~PlanesArray();
    void FUN_00aa80d0(unsigned int uiNewSize, unsigned int uiCopy);
    void FUN_00aa8030(NiFrustumPlanes* pItems, unsigned int uiCount);
    __forceinline void SetSize(unsigned int uiSize, bool bFree) {
        if (uiSize > m_uiAllocSize) {
            if (m_uiAllocSize == 0) {
                m_pBuffer = (NiFrustumPlanes*)((ArrayVtbl*)this)->Allocate(uiSize);
                m_uiAllocSize = uiSize;
            } else {
                FUN_00aa80d0(uiSize, m_uiSize);
                m_uiAllocSize = uiSize;
            }
            FUN_00aa8030(m_pBuffer + m_uiSize, uiSize - m_uiSize);
            m_uiSize = uiSize;
        } else if (uiSize < m_uiSize) {
            m_uiSize = uiSize;
            if (bFree && uiSize <= m_uiAllocSize / 4) {
                FUN_00aa80d0(uiSize, uiSize);
                m_uiAllocSize = uiSize;
            }
        } else {
            FUN_00aa8030(m_pBuffer + m_uiSize, uiSize - m_uiSize);
            m_uiSize = uiSize;
        }
    }
};

struct OpArray {
    void* vtable;
    void* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiAllocSize;
    OpArray() { vtable = &DAT_00e89ebc; m_pBuffer = 0; m_uiSize = 0; m_uiAllocSize = 0; }
    ~OpArray();
    void FUN_0079ecc0(unsigned int uiNewSize, unsigned int uiCopy);
    __forceinline void SetSize(unsigned int uiSize, bool bFree) {
        if (uiSize > m_uiAllocSize) {
            if (m_uiAllocSize == 0) {
                m_pBuffer = ((ArrayVtbl*)this)->Allocate(uiSize);
                m_uiAllocSize = uiSize;
            } else {
                FUN_0079ecc0(uiSize, m_uiSize);
                m_uiAllocSize = uiSize;
            }
            m_uiSize = uiSize;
        } else if (uiSize < m_uiSize) {
            m_uiSize = uiSize;
            if (bFree && uiSize <= m_uiAllocSize / 4) {
                FUN_0079ecc0(uiSize, uiSize);
                m_uiAllocSize = uiSize;
            }
        } else {
            m_uiSize = uiSize;
        }
    }
};

struct FUN_00aa8410 {
    bool m_b0;
    PlanesArray m_kList4;
    OpArray m_kList14;
    int m_24;
    int m_28;
    int m_2c;
    NiFrustumPlanes m_kFrustumPlanes;
    NiPoint3 m_kPoint;
    bool m_bA0;
    FUN_00aa8410();
};

// pdb: BSCompoundFrustum::BSCompoundFrustum | BSCompoundFrustum.obj | fnv360_0822_retail, call_seq, medium
FUN_00aa8410::FUN_00aa8410()
{
    m_24 = 0;
    m_28 = 0;
    m_kPoint = DAT_0108ec68;
    m_kList4.SetSize(4, true);
    m_kList14.SetSize(10, true);
    m_b0 = false;
    m_2c = 0;
    m_bA0 = false;
}
}

// @f3 0x00ab6b20 (community match, verified in this file)
namespace f3m_00ab6b20 {
struct S_00ab6b20 {
    char pad[36];
    float m;
    float FUN_00ab6b20();
};
// pdb: MobileObject::GetLooking | MobileObject.obj | fnv360_0822_retail, vtable, medium
float S_00ab6b20::FUN_00ab6b20()
{
    return m;
}
}   // namespace f3m_00ab6b20

// @f3 0x00ab3dc0 (community match, verified in this file)
namespace f3m_00ab3dc0 {
struct S_00ab3dc0 {
    char pad[72];
    unsigned short m;
    int FUN_00ab3dc0();
};
// pdb: BSPortalGraph::GetAlwaysRenderArrayCount | BSPortalGraph.obj | fnv360_0721_beta, call_seq, medium
int S_00ab3dc0::FUN_00ab3dc0()
{
    return m;
}
}   // namespace f3m_00ab3dc0

// @f3 0x00ab0190 (community match, verified in this file)
bool qab0630::Entry::operator==(const Entry& rhs) const
{
    return color.r == rhs.color.r && color.g == rhs.color.g && color.b == rhs.color.b && flag == rhs.flag && value == rhs.value;
}
// pdb: FurnitureMark::SaveBinary | BSFurnitureMarker.obj | fnv360_0822_debug, objrun, medium
// pdb params: arStream
bool qab0630::Entry::FUN_00ab0190(const Entry& rhs) const
{
    return !(*this == rhs);
}

// @f3 0x00aa56b0 (community match, verified in this file)
// pdb: QueuedChildren::`scalar deleting destructor' | QueuedFiles.obj | fnv360_0822_debug, objrun, medium
__declspec(noinline) int QueuedParents::FUN_00aa56b0_Impl(const NiPointer<QueuedFile>& item)
{
    int index = FUN_005e5350();
    new (buffer + index) NiPointer<QueuedFile>();
    buffer[index] = item;
    return index;
}

// @f3 0x00ab3410 (community match, verified in this file)
// 0x00ab3410 -- build the debug direction arrow: a five-point line set (shaft and two head
// strokes), six colours (two caller colours, the rest green) and connection flags.
#include <math.h>
namespace task2184 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*);
struct ArrowMemory
{
    void* FUN_0086b930(unsigned int);
};
extern ArrowMemory DAT_01090a78;
struct ArrowPoint
{
    float x, y, z;
    ArrowPoint(){}
    ArrowPoint(float X,float Y,float Z):x(X),y(Y),z(Z){}
    ArrowPoint operator*(float f) const {return ArrowPoint(x*f,y*f,z*f);}
    ArrowPoint operator-(const ArrowPoint& p)const{return ArrowPoint(x-p.x,y-p.y,z-p.z);}
    ArrowPoint operator+(const ArrowPoint& p)const{return ArrowPoint(x+p.x,y+p.y,z+p.z);}
float Length() const {float square=x*x+y*y+z*z;return (float)sqrt(square);}
static void* operator new[](unsigned n){return DAT_01090a78.FUN_0086b930(n);}
    ArrowPoint NiPoint3_UnitCross(const ArrowPoint& pt) const;
    ArrowPoint FUN_00ab1020() const;
};
extern const ArrowPoint DAT_00f72598;
extern const ArrowPoint DAT_00f725a4;
extern const ArrowPoint DAT_00f725b0;
// pdb: NiPoint3::UnitCross | TESLand.obj | fnv360_0822_debug, caller + skyrim(call_seq), high
inline ArrowPoint ArrowPoint::NiPoint3_UnitCross(const ArrowPoint& pt) const
{
    ArrowPoint cross(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
    float length = cross.Length();
    if (length > 1e-06f)
    {
        float inverse = 1.0f / length;
        return ArrowPoint(cross.x * inverse, cross.y * inverse, cross.z * inverse);
    }
    return ArrowPoint(0.0f, 0.0f, 0.0f);
}
inline ArrowPoint ArrowPoint::FUN_00ab1020() const
{
    float ax = fabs(x);
    float ay = fabs(y);
    if (ax < ay)
    {
        if (fabs(z) < ax)
            return NiPoint3_UnitCross(DAT_00f725b0);
        return NiPoint3_UnitCross(DAT_00f72598);
    }
    if (fabs(z) < ay)
        return NiPoint3_UnitCross(DAT_00f725b0);
    return NiPoint3_UnitCross(DAT_00f725a4);
}
struct FUN_0046c350
{
    float r, g, b, a;
FUN_0046c350();
FUN_0046c350(float R,float G,float B,float A):r(R),g(G),b(B),a(A){}
static void* operator new[](unsigned n){return DAT_01090a78.FUN_0086b930(n);}
};
typedef FUN_0046c350 ArrowColor;
extern ArrowColor DAT_01066b38;
extern ArrowPoint DAT_0108ec68;
struct ArrowMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
extern ArrowMatrix DAT_00f72574;
extern char* DAT_00e207a8;
char* __cdecl FUN_008242a0(const char*);

struct ArrowString
{
    char* value;
    __forceinline ArrowString(const char* text)
    {
        if (!text)
            value = DAT_00e207a8;
        else
            value = FUN_008242a0(text);
    }
    __forceinline ~ArrowString()
    {
        if (value == DAT_00e207a8)
            return;
        long* count = ((long*)value) - 2;
        InterlockedDecrement(count);
    }
};
struct FUN_0083f750
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
    ArrowMatrix rotation;
    ArrowPoint translation;
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
    FUN_0083f750(unsigned short, ArrowPoint*, ArrowColor*, void*, void*, void*, unsigned char*);
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
    void FUN_008245d0(const ArrowString&);
};
}
// pdb: BSTestObjects::CreateDirArrow | BSTestObjects.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
task2184::FUN_0083f750* __cdecl BSTestObjects_CreateDirArrow(const task2184::ArrowPoint& direction,const task2184::ArrowColor* color){
 using namespace task2184;
 ArrowPoint n=direction;
 float q=n.Length();
 if(q<8.0){n=n*(8.0/q);q=n.Length();}
 ArrowPoint* vertices=new ArrowPoint[5];
 vertices[0]=ArrowPoint(0,0,0);
 ArrowPoint side;
 float scale = q*0.15000000596046448;
 side = n.FUN_00ab1020()*scale;
 ArrowPoint head=n*0.75;
 ArrowPoint colors=head-side;
 head=head+side;
 vertices[1]=n;vertices[2]=head;vertices[3]=n;vertices[4]=colors;
 if(!color)color=&task2184::DAT_01066b38;
 ArrowColor* left=new ArrowColor[6];
 left[0]=*color;left[1]=*color;
 left[2]=ArrowColor(0,1,0,1);
 left[3]=ArrowColor(0,1,0,1);
 left[4]=ArrowColor(0,1,0,1);
 unsigned char* flags=(unsigned char*)task2184::DAT_01090a78.FUN_0086b930(6);
 flags[0]=1;flags[1]=0;flags[2]=1;flags[3]=1;flags[4]=0;
 FUN_0083f750* result=new FUN_0083f750(5,vertices,left,0,0,0,flags);
 result->translation=task2184::DAT_0108ec68;result->rotation=task2184::DAT_00f72574;
 result->FUN_008245d0(ArrowString("BSTestObjects DirArrow"));
 return result;
}

// @f3 0x00aa3a60 (community match, verified in this file)
extern "C" char DAT_01090a78;
extern __declspec(thread) int g_tls[];
namespace f3m_00aa3a60 {
extern "C" __declspec(dllimport) long __stdcall FUN_00d9b06c(volatile long*, long, long);
extern "C" __declspec(dllimport) long __stdcall FUN_00d9b064(volatile long*);

namespace f3m_00aa3a60 {

struct Heap {
    void* FUN_0086b930(unsigned int);
    void FUN_0086ba60(void*);
};


struct TlsGuard {
    int saved;
    TlsGuard(int v) { saved = g_tls[0x298 / 4]; g_tls[0x298 / 4] = v; }
    ~TlsGuard() { g_tls[0x298 / 4] = saved; }
};

inline unsigned int LoadWord(const volatile unsigned int& word) { return word; }
inline void StoreWord(volatile unsigned int& word, unsigned int val) { word = val; }

struct Object {
    virtual ~Object();
    unsigned int unk04;
    long refs;
    void Release() {
        if (FUN_00d9b064(&refs) == 0)
            delete this;
    }
};

struct Ref {
    Object* ptr;
    ~Ref() { if (ptr) ptr->Release(); }
    Ref& FUN_00427450(const Ref&);
};

struct Node {
    __int64 key;
    Ref obj;
    unsigned int next;
    Node(__int64, const Ref&);
    static void* operator new(unsigned int n) { return ((Heap*)&DAT_01090a78)->FUN_0086b930(n); }
    static void operator delete(void* p) { ((Heap*)&DAT_01090a78)->FUN_0086ba60(p); }
};

struct MarkedPtr {
    unsigned int raw;
    MarkedPtr(Node* p, bool mark) {
        StoreWord(raw, (unsigned int)p);
        if (mark)
            raw = LoadWord(raw) | 1u;
        else
            raw = LoadWord(raw) & ~1u;
    }
    unsigned int Get() const { return LoadWord(raw); }
};

struct Pair { unsigned int a, b; };

struct Handler {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0c();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1c();
    virtual void Slot20(); virtual void Slot24();
    virtual __int64 MakeKey(Pair);
    virtual void Slot2c(); virtual void Slot30(); virtual void Slot34();
    virtual void Done();
};

struct Owner {
    Handler* handler;
    void** out1;
    void** out2;
    void** out3;
    unsigned int prevNext;
    unsigned int left;

    Node* Left() const { return (Node*)(LoadWord(left) & ~1u); }
    bool FUN_00aa31d0(int index, Pair key);
    bool FUN_00aa3a60(int index, Pair key, Ref* value, bool replace);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::SetAt | IOManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiBucket, aKey, arData, abReplaceExisting
bool Owner::FUN_00aa3a60(int index, Pair key, Ref* value, bool replace)
{
    TlsGuard guard(6);
    bool result = true;
    Node* node = 0;
    for (;;) {
        if (FUN_00aa31d0(index, key)) {
            delete node;
            if (replace)
                Left()->obj.FUN_00427450(*value);
            else
                result = false;
            break;
        }
        if (!node)
            node = new Node(handler->MakeKey(key), *value);
        MarkedPtr next(Left(), false);
        MarkedPtr desired(node, false);
        long expected = next.Get();
        node->next = next.Get();
        if (FUN_00d9b06c((volatile long*)LoadWord(prevNext), desired.Get(), expected) == expected) {
            handler->Done();
            break;
        }
    }
    *out1 = 0;
    *out2 = 0;
    *out3 = 0;
    return result;
}

}
}   // namespace f3m_00aa3a60

// @f3 0x00aab4a0 (community match, verified in this file)
#include <cmath>
namespace f3m_00aab4a0 {
namespace task1317 {
struct Pt
{
    float x, y, z;
    Pt()
    {}
    Pt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    __declspec(noinline) void FUN_00468d00()
    {
        float fLength = (float)sqrt(x * x + y * y + z * z);
        if (fLength > 1e-06f)
        {
            float fRecip = 1.0f / fLength;
            x *= fRecip;
            y *= fRecip;
            z *= fRecip;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
    Pt FUN_004b3800(const Pt& kPt) const
    {
        return Pt(y * kPt.z - z * kPt.y, z * kPt.x - x * kPt.z, x * kPt.y - y * kPt.x);
    }
};

struct Mat3
{
    float m_afEntries[3][3];
    void SetRow(unsigned int uiRow, const Pt& kRow)
    {
        m_afEntries[uiRow][0] = kRow.x;
        m_afEntries[uiRow][1] = kRow.y;
        m_afEntries[uiRow][2] = kRow.z;
    }
};

inline float NiAbs(float fValue)
{
    return (float)fabs(fValue);
}

// @fnv 0x00c4b600
// pdb: BSUtilities::GetRotationZToVector | BSUtilities.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apVector
Mat3 __cdecl FUN_00aab4a0(Pt kWorldPosition)
{
    Pt kAt = kWorldPosition;
    kAt.FUN_00468d00();
    Pt kAbs;
    kAbs.x=NiAbs(kAt.x);
    kAbs.y=NiAbs(kAt.y);
    kAbs.z=NiAbs(kAt.z);
    Pt kRight2;
    if (kAbs.x <= kAbs.y && kAbs.x <= kAbs.z)
        kRight2 = Pt(0.0f, -kAt.z, kAt.y);
    else if (kAbs.y <= kAbs.x && kAbs.y <= kAbs.z)
        kRight2 = Pt(-kAt.z, 0.0f, kAt.x);
    else
        kRight2 = Pt(-kAt.y, kAt.x, 0.0f);
    kRight2.FUN_00468d00();
    Pt kUpVal;
    kUpVal = kRight2.FUN_004b3800(kAt);
    kUpVal.FUN_00468d00();
    kRight2 = kUpVal.FUN_004b3800(kAt);
    kRight2.FUN_00468d00();
    Mat3 kMatX;
    kMatX.SetRow(0, kRight2);
    kMatX.SetRow(1, kUpVal);
    kMatX.SetRow(2, kAt);
    return kMatX;
}

}
}   // namespace f3m_00aab4a0

// @f3 0x00aa31d0 (community match, verified in this file)
namespace f3m_00aa31d0 {
namespace f3m_00aa31d0 {
inline unsigned int LoadWord(const volatile unsigned int& word) { return word; }
inline void StoreWord(volatile unsigned int& word, unsigned int val) { word = val; }

struct Marked31 {
    unsigned int raw;
    Marked31() {}
    Marked31(unsigned int p, bool mark) {
        StoreWord(raw, p);
        if (mark)
            raw = LoadWord(raw) | 1u;
        else
            raw = LoadWord(raw) & ~1u;
    }
    void set_unmarked(unsigned int p) {
        StoreWord(raw, p & ~1u);
        raw = LoadWord(raw) & ~1u;
    }
    unsigned int Get() const { return LoadWord(raw); }
};

struct Node31;
struct Tag31 {
    volatile unsigned bits;
    Tag31() {}
    Tag31(unsigned v) { bits = v & ~1u; }
    void set(unsigned v) { bits = v & ~1u; }
    void clear2() { unsigned v = Ref() & ~1u; bits = v; }
    void clear() { unsigned v = bits & ~1u; bits = v; }
    operator unsigned() const { return bits; }
    const volatile unsigned& Ref() const { return bits; }
    unsigned Value() const { return bits; }
    Tag31& operator=(unsigned v) { bits = v; return *this; }
    Tag31& operator=(const Tag31& other) { bits = other.bits; return *this; }
};
struct Payload31 {
    virtual ~Payload31();
    int unk04;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { if (InterlockedDecrement(&refs) == 0) delete this; }
};
struct Node31 { unsigned key0, key1; NiPointer<Payload31> payload; Tag31 next; };
struct Map31 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual bool compare(unsigned, unsigned, unsigned, unsigned);
    virtual bool result(unsigned, unsigned, unsigned, unsigned);
    int unk04, unk08; Tag31* buckets; unsigned threshold;
};
struct Search31 {
    Map31* map;
    volatile unsigned* hazardNext;
    volatile unsigned* hazardCurrent;
    volatile unsigned* hazardPrevious;
    Tag31* link;
    Tag31 current;
    Tag31 next;
    Node31* retired;
    unsigned count;
    void cleanup();
    bool FUN_00aa31d0(unsigned index, unsigned a, unsigned b);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::Find | IOManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiBucket, aKey
bool Search31::FUN_00aa31d0(unsigned index, unsigned a, unsigned b) {
    Tag31* volatile bucket = map->buckets + index;
    Tag31 s;
    unsigned k0, k1;
restart:
    do {
        link = bucket;
        Tag31** pl = &link;
        current.bits = (*pl)->bits;
        *hazardCurrent = current & ~1u;
        s.set(current);
        s.clear();
        if (*link == (unsigned)s) break;
    } while (true);
    while (true) {
        if (!(current & ~1u)) return false;
        next.bits = ((Node31*)(current & ~1u))->next.bits;
        *hazardNext = next & ~1u;
        unsigned observedNext = next;
        Node31* nn = (Node31*)(current & ~1u);
        if (observedNext != nn->next.bits) goto restart;
        Node31* node = (Node31*)(current & ~1u);
        k0 = node->key0;
        k1 = node->key1;
        Tag31 candidate((unsigned)current);
        candidate.clear();
        if (*link != (unsigned)candidate) goto restart;
        if (!(next & 1)) {
            if (map->compare(k0, k1, a, b)) break;
            link = (Tag31*)&((Node31*)(current & ~1u))->next;
            *hazardPrevious = current & ~1u;
        } else {
            Marked31 dead(next & ~1u, false);
            unsigned old = candidate;
            long r = dead.Get();
            Tag31* desired = link;
            if ((unsigned)DAT_00d9b06c((long*)desired, r, old) != old) goto restart;
            Node31* lk = (Node31*)(current & ~1u);
            lk->payload = 0;
            lk->payload.m_pObject = (Payload31*)retired;
            ++count;
            retired = lk;
            if (count == map->threshold) cleanup();
        }
        current = next;
        *hazardCurrent = next & ~1u;
    }
    return map->result(k0, k1, a, b);
}
}
}   // namespace f3m_00aa31d0

// @f3 0x00ab4500 (community match, verified in this file)
extern volatile long DAT_0108ed80;
extern "C" char DAT_01090a78;
namespace f3m_00ab4500 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

namespace f3m_00ab4500 {
struct Heap { void FUN_0086ba60(void*); };

struct CountedObject
{
    virtual __forceinline ~CountedObject()
    {
        InterlockedDecrement(&DAT_0108ed80);
    }
    virtual void Destroy();
    inline void IncRefCount() { InterlockedIncrement(&refs); }
    inline void DecRefCount() { if (!InterlockedDecrement(&refs)) Destroy(); }
    volatile long refs;
};

struct PTListItem { PTListItem* next; PTListItem* prev; CountedObject* data; };
struct NiTListBase {
    PTListItem* head; PTListItem* tail; int count;
    void FUN_00bd12d0() throw();
    __forceinline ~NiTListBase() { FUN_00bd12d0(); }
};
struct ClearList : NiTListBase { __forceinline ~ClearList() {} };

struct PtrListBase {
    PTListItem* head; PTListItem* tail; int count;
    void FUN_00abb340();
    __forceinline ~PtrListBase() { FUN_00abb340(); }
};
struct PtrList : PtrListBase { __forceinline ~PtrList() {} };

struct DynArray {
    virtual __forceinline ~DynArray() { Clear(); }
    __forceinline void Clear() { if (data) { FUN_005e5240(data, size); Free(data); data = 0; capacity = 0; size = 0; } }
    virtual void Unk04(); virtual void Free(void*);
    void** data; unsigned int size, capacity;
    void FUN_005e5240(void**, unsigned int);
};
struct FUN_0045cec0
{
    CountedObject* ptr;
    ~FUN_0045cec0();
    static void operator delete[](void* p) { ((Heap*)&DAT_01090a78)->FUN_0086ba60(p); }
};
struct A5E930Buffer
{
    FUN_0045cec0* elements;
    unsigned short capacity, size, grow, used;
    virtual __forceinline ~A5E930Buffer() { delete[] elements; }
    void FUN_00aaab30();
};
struct FUN_00ab4500 : CountedObject
{
    ClearList sub08;
    ClearList sub14;
    PtrList sub20;
    NiPointer<CountedObject> ptr2c;
    PtrList sub30;
    A5E930Buffer arr3c;
    NiPointer<CountedObject> ptr4c;
    PtrList sub50, sub5c;
    DynArray sub68;
    virtual ~FUN_00ab4500();
};
static __forceinline void ShutdownTask(FUN_00ab4500* self)
{
    self->sub14.FUN_00bd12d0();
    self->sub20.FUN_00abb340();
    self->sub08.FUN_00bd12d0();
    self->arr3c.FUN_00aaab30();
    self->ptr2c = (CountedObject*)0;
    self->ptr4c = (CountedObject*)0;
}
// pdb: BSPortalGraph::~BSPortalGraph | BSPortalGraph.obj | fnv360_0822_retail, call_seq, high
FUN_00ab4500::~FUN_00ab4500()
{
    ShutdownTask(this);
}
}
}   // namespace f3m_00ab4500

// @f3 0x00aa33a0 (community match, verified in this file)
namespace f3m_00aa33a0 {
namespace f3m_00aa33a0 {
extern "C" __declspec(dllimport) long __stdcall FUN_00d9b06c(volatile long*, long, long);
inline unsigned int LoadWord(const volatile unsigned int& word) { return word; }
inline void StoreWord(volatile unsigned int& word, unsigned int val) { word = val; }

struct Marked33 {
    unsigned int raw;
    Marked33() {}
    Marked33(unsigned int p, bool mark) {
        StoreWord(raw, p);
        if (mark)
            raw = LoadWord(raw) | 1u;
        else
            raw = LoadWord(raw) & ~1u;
    }
    unsigned int Get() const { return LoadWord(raw); }
};

struct Tag33 {
    volatile unsigned bits;
    Tag33() {}
    Tag33(unsigned v) { bits = v & ~1u; }
    void set(unsigned v) { bits = v & ~1u; }
    void clear() { unsigned v = bits & ~1u; bits = v; }
    operator unsigned() const { return bits; }
    Tag33& operator=(unsigned v) { bits = v; return *this; }
    Tag33& operator=(const Tag33& other) { bits = other.bits; return *this; }
};

struct Payload33 {
    virtual ~Payload33();
    int unk04;
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { long c = InterlockedDecrement(&refs); if (c == 0) delete this; }
};

struct Node33 {
    unsigned key0, key1;
    NiPointer<Payload33> payload;
    Tag33 next;
};

struct Map33 {
    int unk00, unk04, unk08;
    Tag33* buckets;
    unsigned threshold;
};

struct Search33 {
    Map33* map;
    volatile unsigned* hazardNext;
    volatile unsigned* hazardCurrent;
    volatile unsigned* hazardPrevious;
    Tag33* link;
    Tag33 current;
    Tag33 next;
    Node33* retired;
    unsigned count;
    void FUN_00aa3000();
    bool FUN_00aa33a0(unsigned index, const NiPointer<Payload33>& value);
};

inline bool CasLink(Tag33* dest, long exchange, long comparand) {
    return FUN_00d9b06c((volatile long*)dest, exchange, comparand) == comparand;
}

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::FindValue | IOManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiBucket, arData
bool Search33::FUN_00aa33a0(unsigned index, const NiPointer<Payload33>& value) {
    Tag33* bucket = map->buckets + index;
    Tag33 s;
    for (;;) {
        link = bucket;
        Tag33** pl = &link;
        current.bits = (*pl)->bits;
        *hazardCurrent = current & ~1u;
        s.set(current);
        s.clear();
        if (*link != (unsigned)s) continue;
        for (;;) {
            if (!(current & ~1u)) return false;
            next.bits = ((Node33*)(current & ~1u))->next.bits;
            *hazardNext = next & ~1u;
            unsigned observedNext = next;
            Node33* nn = (Node33*)(current & ~1u);
            if (observedNext != nn->next.bits) break;
            NiPointer<Payload33> item = ((Node33*)(current & ~1u))->payload;
            Tag33 candidate((unsigned)current);
            candidate.clear();
            if (*link != (unsigned)candidate) break;
            if (!(next & 1)) {
                if (item == value) return true;
                link = (Tag33*)&((Node33*)(current & ~1u))->next;
                *hazardPrevious = current & ~1u;
            } else {
                Marked33 dead(next & ~1u, false);
                unsigned old = candidate;
                long r = dead.Get();
                Tag33* desired = link;
                bool ok = CasLink(desired, r, old);
                if (!ok) break;
                Node33* lk = (Node33*)(current & ~1u);
                lk->payload = (Payload33*)0;
                lk->payload.m_pObject = (Payload33*)retired;
                ++count;
                retired = lk;
                if (count == map->threshold) FUN_00aa3000();
            }
            current = next;
            *hazardCurrent = next & ~1u;
        }
    }
}
}
}   // namespace f3m_00aa33a0

// @f3 0x00aab6b0 (community match, verified in this file)
#include <math.h>
namespace f3m_00aab6b0 {
namespace f3m_00aab6b0 {
struct Vec3_aab6 {
    float x, y, z;
    __declspec(noinline) void FUN_00468d00() {
        float n = (float)sqrt(x*x + y*y + z*z);
        if (n > 1e-6f) { float r = 1.0f / n; x *= r; y *= r; z *= r; }
        else { x = 0; y = 0; z = 0; }
    }
    void RevCrossInto(const Vec3_aab6& a, Vec3_aab6& r) const {
        r.x = a.y * z - a.z * y;
        r.y = a.z * x - a.x * z;
        r.z = a.x * y - a.y * x;
    }
};
struct Matrix_aab6 { float elements[9]; };
// pdb: BSUtilities::GetRotationZToVectorTranspose | BSUtilities.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apVector
Matrix_aab6 FUN_00aab6b0(Vec3_aab6 input)
{
    Vec3_aab6 v;
    struct UpCross { Vec3_aab6 up; Vec3_aab6 cross; } basis;
    Vec3_aab6& c = basis.up;
    v = input;
    v.FUN_00468d00();
    c.x = fabs(v.x);
    c.y = fabs(v.y);
    c.z = fabs(v.z);
    if (c.x <= c.y && c.x <= c.z) {
        c.x = 0.0f; c.y = -v.z; c.z = v.y;
    } else if (c.y <= c.x && c.y <= c.z) {
        c.x = -v.z; c.y = 0.0f; c.z = v.x;
    } else {
        c.x = -v.y; c.y = v.x; c.z = 0.0f;
    }
    Vec3_aab6 p = c;
    p.FUN_00468d00();
    v.RevCrossInto(p, basis.cross);
    c = basis.cross;
    c.FUN_00468d00();
    v.RevCrossInto(c, basis.cross);
    p = basis.cross;
    p.FUN_00468d00();
    Matrix_aab6 result;
    float* out = result.elements;
    out[0] = p.x; out[3] = p.y; out[6] = p.z;
    out[1] = c.x; out[4] = c.y; out[7] = c.z;
    out[2] = v.x; out[5] = v.y; out[8] = v.z;
    return result;
}
}
}   // namespace f3m_00aab6b0

// @f3 0x00aaf920 (community match, verified in this file)
extern "C" char DAT_01090a78;
namespace f3m_00aaf920 {
namespace Clone90 {
struct Heap {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};
struct PointerSet {
 void** data;unsigned capacity,count;
 static void* operator new(unsigned n){return reinterpret_cast<Heap*>(&DAT_01090a78)->FUN_0086b930(n);}
 static void operator delete(void* p){reinterpret_cast<Heap*>(&DAT_01090a78)->FUN_0086ba60(p);}
 PointerSet(unsigned n=0):data(0),capacity(0),count(0){if(n)FUN_008cde60(n);}
 void FUN_008cde60(unsigned);
 void Add(void* const& value){if(count==capacity)FUN_008cde60(capacity>0?2*capacity:1);data[count++]=value;}
};
struct Array {
 unsigned table;PointerSet** data;unsigned short capacity,size,count,grow;
 void FUN_00555790(unsigned);void FUN_005b3880(unsigned,PointerSet* const&);
 void Set(unsigned i,PointerSet* const& value){if(i>=capacity)FUN_00555790(i+grow);FUN_005b3880(i,value);}
};
__declspec(noinline) void Array::FUN_005b3880(unsigned i,PointerSet* const& value){
 if(i>=size){size=static_cast<unsigned short>(i+1);if(value)++count;}
 else if(value){if(!data[i])++count;}else if(data[i])--count;
 data[i]=value;
}
struct MapNode { MapNode* next; void* key; void* val; };
struct Map {
    void* vtbl; unsigned hashSize; MapNode** buckets; unsigned count;
    __declspec(noinline) bool FUN_00bea7b0(void* key, void** out) {
        MapNode* p = buckets[((unsigned)key >> 4) % hashSize];
        while (p) { if (p->key == key) { *out = p->val; return true; } p = p->next; }
        return false;
    }
};
struct Context {Map* map;};
struct Owner {
 unsigned f00,f04,f08,f0c,f10,f14,f18,f1c,f20,f24,f28,f2c,f30;
 unsigned current,num;Array sets;
 void FUN_00837ca0(Context*);bool FUN_00aaf610(unsigned);void FUN_00aaf920(Context*);
 void ResetCurrent(){unsigned old=current;current=~0u;FUN_00aaf610(old);}
};
// pdb: NiBSBoneLODController::ProcessClone | NiBSBoneLODController.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
void Owner::FUN_00aaf920(Context* context){
 FUN_00837ca0(context);
 Owner* clone=0;
 context->map->FUN_00bea7b0(this,reinterpret_cast<void**>(&clone));
 for(unsigned i=0;i<sets.size;++i){
  PointerSet* source=sets.data[i];
  if(source){
   PointerSet* destination=new PointerSet;
   clone->sets.Set(i,destination);
   for(unsigned j=0;j<source->count;++j){
    void* value=source->data[j];
    if(value){
     void* mapped=0;
     if(context->map->FUN_00bea7b0(value,&mapped))destination->Add(mapped);
     else destination->Add(0);
    }else destination->Add(0);
   }
  }else{PointerSet* empty=0;clone->sets.Set(i,empty);}
 }
 clone->ResetCurrent();
}
}
}   // namespace f3m_00aaf920

// @f3 0x00aab8c0 (community match, verified in this file)
#include <math.h>
namespace f3m_00aab8c0 {
namespace f3m_00aab8c0 {

class NiPoint3 {
public:
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
    NiPoint3 operator+(const NiPoint3& kPt) const { return NiPoint3(x + kPt.x, y + kPt.y, z + kPt.z); }
    NiPoint3 operator-(const NiPoint3& kPt) const { return NiPoint3(x - kPt.x, y - kPt.y, z - kPt.z); }
    float operator*(const NiPoint3& kPt) const { return x * kPt.x + y * kPt.y + z * kPt.z; }
    NiPoint3 operator*(float fScalar) const { return NiPoint3(x * fScalar, y * fScalar, z * fScalar); }
    NiPoint3 operator-() const { return NiPoint3(-x, -y, -z); }
    __declspec(noinline) void FUN_00468d00() { float d = x*x + y*y + z*z; if (d > 0.0f) { x *= d; y *= d; z *= d; } }
};

class NiMatrix3 {
public:
    float m_pEntry[3][3];
    void GetCol(int uiCol, NiPoint3& col) const {
        col.x = m_pEntry[0][uiCol];
        col.y = m_pEntry[1][uiCol];
        col.z = m_pEntry[2][uiCol];
    }
    void SetCol(int uiCol, const NiPoint3& col) {
        m_pEntry[0][uiCol] = col.x;
        m_pEntry[1][uiCol] = col.y;
        m_pEntry[2][uiCol] = col.z;
    }
};

class NiPlane {
public:
    NiPoint3 m_kNormal;
    float m_fConstant;
    __forceinline NiPoint3 ReflectPoint(NiPoint3 kPt) const { return kPt + -m_kNormal * (2.0f * Distance(kPt)); }
    float Distance(const NiPoint3& kPt) const { return m_kNormal * kPt - m_fConstant; }
};

struct NiFrustum {
    float m_fLeft, m_fRight, m_fTop, m_fBottom, m_fNear, m_fFar;
    bool m_bOrtho;
};

struct NiUpdateData {
    float m_fTime;
    bool m_b0;
    bool m_b1;
    bool m_b2;
    bool m_b3;
    bool m_b4;
};

class NiTransform {
public:
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;
};

class NiCamera {
public:
    void* vtbl;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    NiTransform m_kLocal;
    NiTransform m_kWorld;
    unsigned int unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    unsigned int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    NiFrustum m_kViewFrustum;
    void FUN_00839f90(const NiFrustum* pkFrustum);
    void FUN_008264c0(const NiUpdateData& kData);
};


// pdb: BSUtilities::ReflectCameraAboutArbitraryPlane | BSUtilities.obj | fnv360_0822_retail, call_gap, low
// pdb params: apCamera, apPlane, apReflectedCamera
void FUN_00aab8c0(NiCamera* pkSrc, const NiPlane& kPlane, NiCamera* pkDst)
{
    NiPoint3 kDir, kUp, kRight;
    pkSrc->m_kWorld.m_Rotate.GetCol(0, kDir);
    pkSrc->m_kWorld.m_Rotate.GetCol(2, kRight);
    pkSrc->m_kWorld.m_Rotate.GetCol(1, kUp);

    NiPoint3 kNewTrans = kPlane.ReflectPoint(pkSrc->m_kWorld.m_Translate);

    NiPoint3 kV = -kDir;
    kV.FUN_00468d00();
    NiPoint3 kNewDir = kPlane.m_kNormal * (2.0f * (kPlane.m_kNormal * kV)) - kV;

    kV = -kRight;
    kV.FUN_00468d00();
    NiPoint3 kNewRight = kPlane.m_kNormal * (2.0f * (kPlane.m_kNormal * kV)) - kV;

    kV = kUp;
    kV.FUN_00468d00();
    NiPoint3 kNewUp = kPlane.m_kNormal * (2.0f * (kPlane.m_kNormal * kV)) - kV;

    NiMatrix3 kRot;
    kRot.SetCol(0, kNewDir);
    kRot.SetCol(1, kNewUp);
    kRot.SetCol(2, kNewRight);
    pkDst->m_kLocal.m_Translate = kNewTrans;
    pkDst->m_kLocal.m_Rotate = kRot;
    pkDst->m_kLocal.m_fScale = (float)fabs(pkSrc->m_kWorld.m_fScale);
    pkDst->FUN_00839f90(&pkSrc->m_kViewFrustum);
    NiUpdateData kData = {0.0f, false, false, false, false, false};
    pkDst->FUN_008264c0(kData);
}

}
}   // namespace f3m_00aab8c0

// @f3 0x00aa2a00 (community match, verified in this file)
namespace f3m_00aa2a00 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
namespace f3m_00aa2a00 {
struct TaskHeader { virtual ~TaskHeader(); unsigned unk04; long refs; unsigned state; };
struct Task : TaskHeader {
    __int64 key;
    void SetState(unsigned s) { state = s; }
    __int64 GetKey() const { return key; }
    void AddRef() { InterlockedIncrement(&refs); }
    void Release() { if (!InterlockedDecrement(&refs)) delete this; }
};
struct TaskPtr { Task* value; TaskPtr(Task* p) : value(p) { if (value) value->AddRef(); } ~TaskPtr() { if (value) value->Release(); } };
struct Signal {
    volatile long count;
    void* semaphore;
    void Unlock() {
        ReleaseSemaphore(semaphore, 1, 0);
        InterlockedIncrement(&count);
    }
};
struct Queue {
    unsigned unk00, unk04, unk08;
    Signal signal;
    void Wake() {
        if (signal.count == 0)
            signal.Unlock();
    }
};
struct Target {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual bool Remove(__int64, const TaskPtr&, bool);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned Bucket(__int64);
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
    virtual unsigned Priority(Task*);
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Queue** queues; long* buckets; long total;
    void IncrementBucket(unsigned b) { InterlockedIncrement(&buckets[b]); }
    bool FUN_00aa2a00(Task*);
};
// pdb: BSTaskManager<__int64>::AddTask | IOManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: apTask
bool Target::FUN_00aa2a00(Task* task) {
    task->SetState(1);
    unsigned bucket = Bucket(task->GetKey());
    unsigned priority = Priority(task);
    bool removed;
    { TaskPtr hold(task); removed = Remove(task->GetKey(), hold, false); }
    if (removed) { IncrementBucket(bucket); InterlockedIncrement(&total); queues[priority]->Wake(); return true; }
    return false;
}
}
}   // namespace f3m_00aa2a00

// @f3 0x00aa26f0 (community match, verified in this file)
namespace f3m_00aa26f0 {
namespace f3m_00aa26f0 {
extern long (__stdcall *DAT_00d9b064)(volatile long*);
extern long (__stdcall *DAT_00d9b068)(volatile long*);
struct RefObjectStandIn
{
    virtual void Destroy(unsigned int);
    int unk04;
    long refCount;
    __forceinline void DecRef()
    {
        if (DAT_00d9b064(&refCount) == 0 && this)
            Destroy(1);
    }
};

struct PtrAA26
{
    RefObjectStandIn* m_pObject;
    __forceinline PtrAA26& Assign(const PtrAA26& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRef();
            m_pObject = other.m_pObject;
            if (m_pObject)
                DAT_00d9b068(&m_pObject->refCount);
        }
        return *this;
    }
};

struct NodeAA26
{
    __int64 tKey;
    PtrAA26 tData;
    volatile unsigned int pNext;
};

inline unsigned int LoadWord(const volatile unsigned int& word) { return word; }
inline void StoreWord(volatile unsigned int& word, unsigned int val) { word = val; }

struct MarkedPtr {
    unsigned int raw;
    MarkedPtr(NodeAA26* p, bool mark) {
        StoreWord(raw, (unsigned int)p);
        if (mark)
            raw = LoadWord(raw) | 1u;
        else
            raw = LoadWord(raw) & ~1u;
    }
    unsigned int Get() const { return LoadWord(raw); }
};

struct TableAA26
{
    virtual ~TableAA26();
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
    virtual void CopyKeyDirect(__int64 key, __int64& out);
    int unk04;
    int unk08;
    volatile unsigned int* m_pBuckets;
};

struct ScannerAA26
{
    TableAA26* pOwner;
    NodeAA26** firstBuffer; NodeAA26** secondBuffer; NodeAA26** thirdBuffer;
    volatile unsigned int* volatile pPrev;
    volatile unsigned int kCurrent;
    bool FUN_00aa26f0(unsigned int auiBucket, __int64& arKey, PtrAA26& arData);
};

// pdb: LockFreeMap<__int64,NiPointer<BSTask<__int64> > >::LockFreeMapInterface::GetFirst | IOManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiBucket, arKey, arData
bool ScannerAA26::FUN_00aa26f0(unsigned int auiBucket, __int64& arKey, PtrAA26& arData)
{
    bool tmp;
    unsigned offset = auiBucket * 4;
    
    for (;;)
    {
        pPrev = (volatile unsigned int*)((char*)pOwner->m_pBuckets + offset);
        kCurrent = **(unsigned int**)&pPrev;
        *secondBuffer = (NodeAA26*)(kCurrent & ~1u);
        MarkedPtr expect((NodeAA26*)(kCurrent & ~1u), false);
        unsigned int curr = *(volatile unsigned int*)pPrev;
        if (curr != expect.Get()) continue;
        if ((kCurrent & ~1u) == 0) { tmp = false; break; }
        pOwner->CopyKeyDirect(((NodeAA26*)(kCurrent & ~1u))->tKey, arKey);
        arData.Assign(((NodeAA26*)(kCurrent & ~1u))->tData);
        tmp = true;
        NodeAA26* n = (NodeAA26*)(kCurrent & ~1u);
        if (!(n->pNext & 1)) break;
    }
    *firstBuffer = 0;
    *secondBuffer = 0;
    *thirdBuffer = 0;
    return tmp;
}
}
}   // namespace f3m_00aa26f0

// @f3 0x00ab2d70 (community match, verified in this file)
extern float FUN_00e8af38;
namespace f3m_00ab2d70 {
struct NiPoint3
{
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
};
struct NiMatrix3
{
    float m_pEntry[3][3];
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};
class NiAVObject : public NiMemObject
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    NiMatrix3 m_kRotate;
    NiPoint3 m_kTranslate;
};
class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short usChildren);
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
    virtual void AttachChild(NiAVObject* pkChild, bool bFirstAvail);
    int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
};
NiAVObject* __cdecl BSTestObjects_CreateCylinder(float fX, float fY, float fZ, int iArg0, int iArg1, int iArg2);

// pdb: BSTestObjects::CreateCappedCylinder | BSTestObjects.obj | fnv360_0822_retail, call_dedup, low
// pdb params: afBaseRadius, afTopRadius, afHeight, aiSlices, aiStacks, apColor
NiNode* __cdecl FUN_00ab2d70(float fX, float fY, float fZ, int iArg0, int iArg1, int iArg2)
{
    NiNode* pkNode = new NiNode(0);
    NiAVObject* pkFirst = BSTestObjects_CreateCylinder(fX, fY, fZ, iArg0, iArg1, iArg2);
    NiAVObject* pkSecond = BSTestObjects_CreateCylinder(fX, 0.0f, 0.0f, iArg0, 1, iArg2);
    float fSin, fCos;
    fnv_SinCos(FUN_00e8af38, fSin, fCos);
    NiMatrix3 kRot;
    kRot.m_pEntry[0][0] = 1.0f; kRot.m_pEntry[0][1] = 0.0f; kRot.m_pEntry[0][2] = 0.0f;
    kRot.m_pEntry[1][0] = 0.0f; kRot.m_pEntry[1][1] = fCos; kRot.m_pEntry[1][2] = fSin;
    kRot.m_pEntry[2][0] = 0.0f; kRot.m_pEntry[2][1] = -fSin; kRot.m_pEntry[2][2] = fCos;
    pkSecond->m_kRotate = kRot;
    NiAVObject* pkThird = BSTestObjects_CreateCylinder(fX, 0.0f, 0.0f, iArg0, 1, iArg2);
    pkThird->m_kTranslate = NiPoint3(0.0f, 0.0f, fZ);
    pkNode->AttachChild(pkFirst, true);
    pkNode->AttachChild(pkSecond, true);
    pkNode->AttachChild(pkThird, true);
    return pkNode;
}
}   // namespace f3m_00ab2d70

// @f3 0x00aa01c0 (community match, verified in this file)
#include <math.h>
namespace f3m_00aa01c0 {
// 0x00aa01c0: BSMultiBoundOBB::CheckBSBound. Tests the 8 corners of another box (axis-aligned or oriented) against
// the three slabs of this box; returns 2 when every corner is inside, 0 otherwise. A sphere goes to CheckBound.
namespace f3m_00aa01c0 {
struct NiPoint3 {
    float x, y, z;
    float operator*(const NiPoint3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct NiPlane {
    NiPoint3 normal;
    float constant;
    NiPlane();
    float Distance(const NiPoint3& p) const { float d = normal * p; d -= constant; return d; }
    float DistanceTo(const NiPoint3& p) const { float d = p * normal; d -= constant; return d; }
    float SignedDistance(const NiPoint3& p) const { return p * normal - constant; }
};
struct NiSphere {
    NiPoint3 center;
    float radius;
};
class NiRefObject {
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
class NiObject : public NiRefObject {
public:
    virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
};
class BSMultiBound;
class BSMultiBoundShape : public NiObject {
public:
    virtual int GetType();
    virtual float GetLength();
    virtual int CheckBSBound(BSMultiBound*);
    virtual int CheckBound(NiSphere*);
    virtual bool WithinPoint(const NiPoint3&);
    virtual void SetCenter(const NiPoint3&);
    virtual void GetSphere(NiSphere* out);
    unsigned int m_uiCullResult;
};
class BSMultiBound : public NiObject {
public:
    unsigned int m_uiBoundFrameCount;
    BSMultiBoundShape* m_spShape;
    BSMultiBoundShape* GetShape() const { return m_spShape; }
};
class BSMultiBoundAABB : public BSMultiBoundShape {
public:
    NiPoint3 m_kCenter;
    NiPoint3 m_kHalfExtents;
    void BSMultiBoundAABB_GetVertices(NiPoint3* out);
};
class BSMultiBoundOBB : public BSMultiBoundAABB {
public:
    NiPoint3 m_kAxis[3];
    void BSMultiBoundOBB_GetVertices(NiPoint3* out);
    void FUN_00a9fa20(NiPlane* planes);
    int FUN_00aa01c0(BSMultiBound* other);
};
// pdb: BSMultiBoundOBB::CheckBound | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: aTargetBound
int BSMultiBoundOBB::FUN_00aa01c0(BSMultiBound* other)
{
    int type = other->m_spShape->GetType();
    if (type == 1) {
        NiPoint3 corners[8];
        BSMultiBoundAABB* aabb = static_cast<BSMultiBoundAABB*>(other->m_spShape);
        aabb->BSMultiBoundAABB_GetVertices(corners);
        NiPlane planes[3];
        FUN_00a9fa20(planes);
        const NiPlane& q0 = planes[0];
        for (int i = 0; i < 8; i++) {
            if (fabs(q0.Distance(corners[i])) - m_kHalfExtents.x > 0.0f)
                return 0;
            if (fabs(planes[1].Distance(corners[i])) - m_kHalfExtents.y > 0.0f)
                return 0;
            if (fabs(planes[2].Distance(corners[i])) - m_kHalfExtents.z > 0.0f)
                return 0;
        }
        return 2;
    } else if (type == 2) {
        NiPoint3 corners[8];
        BSMultiBoundOBB* obb = static_cast<BSMultiBoundOBB*>(other->m_spShape);
        obb->BSMultiBoundOBB_GetVertices(corners);
        NiPlane planes[3];
        FUN_00a9fa20(planes);
        const NiPlane& q1 = planes[1];
        const NiPlane& q2 = planes[2];
        for (int i = 0; i < 8; i++) {
            if (fabs(planes[0].DistanceTo(corners[i])) - m_kHalfExtents.x > 0.0f)
                return 0;
            if (fabs(q1.DistanceTo(corners[i])) - m_kHalfExtents.y > 0.0f)
                return 0;
            if (fabs(q2.SignedDistance(corners[i])) - m_kHalfExtents.z > 0.0f)
                return 0;
        }
        return 2;
    } else if (type == 3) {
        NiSphere sphere;
        other->m_spShape->GetSphere(&sphere);
        return CheckBound(&sphere);
    }
    return 0;
}
}
}   // namespace f3m_00aa01c0

// @f3 0x00aa5870 (community match, verified in this file)
// 0x00aa5870: add an owner to this file's list of parents; the list is created on first use.
namespace f3m_00aa5870 {
extern const char DAT_00e898f4[];
extern const char DAT_00e89908[];
extern NiPointer<QueuedFile>* (__thiscall *DAT_00e898f8)(void*, unsigned int);

class ParentsList {
public:
    const char* vptr;
    NiPointer<QueuedFile>* buffer;
    unsigned int size;
    unsigned int capacity;
    int unk10;
    ParentsList()
    {
        vptr = DAT_00e898f4;
        buffer = 0;
        size = 0;
        capacity = 0;
        buffer = DAT_00e898f8(this, 5);
        capacity = 5;
        vptr = DAT_00e89908;
        unk10 = 0;
    }
    static void* operator new(unsigned int size) { return naa5950::DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { naa5950::DAT_01090a78.FUN_0086ba60(p); }
};

// Debug tracing is compiled out: the flag is a constant false, so the statement in FUN_00aa5870 that uses it
// generates no code. It is kept on purpose, because it is what makes the compiler treat the parameter as
// address-taken. The smart pointer handed to the list then cannot be overlaid on the parameter's own stack
// home and takes the frame slot of the allocation temporary instead, as in the original. Without this
// statement the source is 2 instructions off (that one stack operand, at +0x80 and +0x90). The trace function
// and its name are our reconstruction of whatever took the parameter's address in the original source.
static const bool kTraceParents = false;
void TraceParentAdded(void* const& owner);
}


void QueuedFile::FUN_00aa5870(void* owner)
{
    f3m_00aa5870::ParentsList*& parents = *(f3m_00aa5870::ParentsList**)((char*)this + 0x20);
    // Compiled-out trace: kTraceParents is a constant false, so this statement emits no code. It is kept
    // because it makes the compiler treat the parameter as address-taken (see the note at kTraceParents).
    if (f3m_00aa5870::kTraceParents)
        f3m_00aa5870::TraceParentAdded(owner);
    if (!parents)
        parents = new f3m_00aa5870::ParentsList;
    NiPointer<QueuedFile> item((QueuedFile*)owner);
    ((QueuedParents*)parents)->FUN_00aa56b0(item);
}

// @f3 0x00aa8140 (community match, verified in this file)
extern int DAT_00e89ed0;
namespace f3m_00aa8140 {
namespace f3m_00aa8140 {
extern void (__stdcall* DAT_00e89ed8)(void*);
struct SimpleArray {
    void* vtable;
    void* data;
    unsigned size;
    unsigned capacity;
    void FUN_00aa8140();
};
void SimpleArray::FUN_00aa8140() {
    vtable = &DAT_00e89ed0;
    if (data) {
        DAT_00e89ed8(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
}
}
}   // namespace f3m_00aa8140

// @f3 0x00aa80d0 (community match, verified in this file)
namespace f3m_00aa80d0 {
namespace f3m_00aa80d0 {
struct Arr {
    virtual void V00();
    virtual void* Allocate(unsigned int count);
    virtual void Free(void* p);
    virtual void* Reallocate(void* p, unsigned int count);
    void* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_00aa7ab0(void* dst, void* src, unsigned int count);
    void FUN_00aa80d0(unsigned int newCapacity, unsigned int count);
};
void Arr::FUN_00aa80d0(unsigned int newCapacity, unsigned int count) {
    if (data) {
        if (count == capacity) {
            data = Reallocate(data, newCapacity);
        } else {
            void* p = Allocate(newCapacity);
            FUN_00aa7ab0(p, data, count);
            Free(data);
            data = p;
        }
    } else {
        data = Allocate(newCapacity);
        capacity = newCapacity;
    }
}
}
}   // namespace f3m_00aa80d0
