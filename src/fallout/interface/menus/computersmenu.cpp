#include "f3_common.h"
// src/fallout/interface/menus/computersmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/computersmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Tile
{
    Tile* pParent;
};

struct ComputersMenu
{
    char _base[0x28];
    Tile* m_pTiles[64];
    void FUN_00754c00(int aiID, Tile* apTile);
};

namespace fnv_00757a10 {
struct ComputersMenu
{
    int __thiscall GetMenuId();
};

}  // namespace fnv_00757a10

namespace fnv_007596a0 {
struct Tile
{
    void Set(int a, int b);
};
extern int __cdecl GetTileValueID(const char*, int);

}  // namespace fnv_007596a0

struct GlobalObject_0048f200
{
    GlobalObject_0048f200();
};
GlobalObject_0048f200::GlobalObject_0048f200()
{}

void __cdecl operator delete(void*);

namespace fnv_007597f0 {
struct GlobalObject_0048f200
{
    ~GlobalObject_0048f200();
};
}  // namespace fnv_007597f0

struct Flt
{
    operator unsigned int();
};

void __cdecl operator delete(void*);

int __cdecl GetTileValueID(char const*, int);

void* __cdecl operator new(unsigned int);

struct GO
{
    operator unsigned int();
};

struct BStr
{
    char* p;
    short len;
    short max;
    ~BStr();
};
extern int DAT_011d934c;

unsigned int __cdecl gm_GetTickCount();

struct BSStringT
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT(const char* apStr);
    ~BSStringT();
    BSStringT& operator+=(const char* apStr);
    operator const char*() const;
};

int __cdecl TraitNameToID(const char* apName, int aiDefault);

// Destructor: release the entries, unregister this object, then the entry list member is destroyed.

class A060EntryList
{
  public:
    ~A060EntryList();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0075a060;
void __cdecl A060Unregister(FUN_0075a060* pkObject);

class FUN_0075a060
{
  public:
    virtual ~FUN_0075a060();
    void Clear();

    A060EntryList m_kEntries;
};

// Clears the object's entry list, then unregisters the object via A060Unregister.
// @fnv 0x0075a060
FUN_0075a060::~FUN_0075a060()
{
    Clear();
    A060Unregister(this);
}

// Refresh the terminal menu tile; if the rendered menu is showing this menu's scene, refresh the rendered terminal too.

class InterfaceManager;

namespace fnv_00758470 {
struct InterfaceManager;
struct S8840
{
    bool FUN_00718840(int);
};
struct InterfaceManager
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
    S8840 unk4d4;
};
template <class T> struct ListBox
{
    void Traverse(void (*f)(Tile*, T), int, int);
};
unsigned int __cdecl gm_GetTickCount();
}  // namespace fnv_00758470

struct CHCondition
{
    bool Evaluate(void* apSubject, int aiUnk);
};

struct CHChallenge;

struct CHListNode
{
    CHChallenge* pItem;
    CHListNode* pNext;

    CHChallenge** GetItem();
    CHListNode* GetNext();
};

struct CHDescription
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual const char* Get(CHChallenge* apForm, unsigned int auiChunk);
};

struct CHChallenge
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
    CHCondition kCondition;
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
    CHDescription kDescription;

    CHListNode* GetChallengeList();
    bool IsCompleted();
    const char* GetName();
    void SetSeen(bool abSeen);
};

extern int DAT_0119f278;
struct TextTile
{
    void Set(int, int);
    double Read(int);
    void* Find(int);
    void* GetValue(int);
};
struct TextString
{
    char* text;
    unsigned short len, capacity;
    bool Set(const char*);
    operator const char*() const;
    unsigned int Length() const;
};
struct TextLayout
{
    TextLayout(int, int, int, int, int);
    ~TextLayout();
    operator const char*() const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int consumed;
    int unk1c;
    int unk20;
    int unk24;
};
struct TextSource;
struct TextSourceInterface
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual const char* GetText(TextSource*, int, int);
};
struct TextSource
{
    TextSourceInterface* GetInterface();
};

namespace fnv_007598d0 {
struct TextTile
{
    TextTile* FUN_0045cd60();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00700320(int, int);
    void* FUN_00a00f30(int);
    void FUN_00a04640(bool);
    void FUN_00a04620(bool);
    bool IsAllChildrenFlag0();
};
struct TextSound
{
    int id;
    int state;
    int flags;
    ~TextSound();
    void FUN_00ad8870();
    void FUN_00ad8830(bool);
};
struct TextAudioManager
{
    TextSound ResolveAudioHandle(const char*, int, unsigned int, int);
};
TextAudioManager* FUN_00ad9060();
}  // namespace fnv_007598d0

int __cdecl TraitNameToID(const char* apName, int aiDefault);

struct LBTile;

struct LBTileValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int aiOperator, LBTile* apTile, int aiID);
    void AppendFloatAction(int aiOperator, float afValue);
    void FUN_00a09410(int aiFlag);
};

struct LBTileMenu
{
    LBTile* AddTileFromTemplate(LBTile* apParent, const char* apTemplate, int aiUnk);
};

struct LBTile
{
    LBTileMenu* GetMenu();
    void* GetValue(int aiID);
    LBTileValue* GetValueAction(int aiID);
    void SetInt(int aiID, int aiValue);
    void SetString(int aiID, const char* apString, bool abPropagate);
    float GetFloat(int aiID);
};

int __cdecl FUN_00a01860(const char* name);

int __cdecl FUN_00a01860(const char*);

int __cdecl FUN_00a01860(const char* apText);

namespace fnv_00757b70 {
struct Terminal;
struct Ref
{
    Terminal* GetTerminal();
};
struct Terminal
{
    unsigned char IsFlagBitSet();
    bool CanUse(Ref*);
};
extern int DAT_011d934c;
struct OpenTile;
struct ListUI
{
    void Initialize(OpenTile*, const char*);
};
struct SoundUI
{
    bool Play(bool);
};
struct OpenMenu
{
    virtual ~OpenMenu();
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
    virtual int ID();
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
    OpenTile* root;
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
    ListUI list;
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
    Terminal* terminal;
    Ref* ref;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
    SoundUI sound;
    void Attach(OpenTile*, bool);
    bool Validate(int*);
    void Populate();
    void Alternate();
    void Show(int);
    void* Data();
};
struct OpenTile
{
    OpenTile* ReadFile(const char*);
    OpenMenu* GetMenu();
    float Value(int);
    void Set(int, float, bool);
};
}  // namespace fnv_00757b70

struct HighlightTile;
struct HighlightValue
{
    void FUN_00a09130(int trait, HighlightTile* tile, int sourceTrait);
    void FUN_00a09410(int mode);
};
struct HighlightTile
{
    HighlightValue* FUN_00a00f30(const char* trait);
    bool GetSpeechChallengeFailure();
    HighlightTile* FUN_00a03da0(const char* name);
    void FUN_0071aa60(bool visible);
    void FUN_00a07530(int flags);
    void FUN_00700320(const char* trait, int value);
};

#include <string.h>
struct StrMem
{
    StrMem();
    ~StrMem();
    char* text;
    unsigned short length;
    unsigned short capacity;
};
struct BSSoundHandleEx
{
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx&);
    unsigned int id;
    unsigned int state;
    unsigned int sound;
};
struct ConstructorAudio
{
    BSSoundHandleEx ResolveAudioHandle(const char*, unsigned int);
};
ConstructorAudio* FUN_00ad9060();
void SetTextSource();

namespace fnv_00757f70 {
struct TileF;
struct Value
{
    const char* FUN_0084e3a0();
};
struct TileF
{
    void FUN_00700320(int, int);
    bool IsAllChildrenFlag0();
    Value* FUN_00a00f30(int);
    void* FindTraitValue(int);
};
struct BStr
{
    void* m_data;
    int m_len;
    BStr();
    ~BStr();
    const char* FUN_00559450();
};
struct NameObj
{
    const char* FUN_00408da0();
};
struct Note
{
    void* m_n0[18];
    NameObj m_name;
    int GetNoteType();
};
struct Obj
{
    void* m_00;
    void* m_04;
    BStr m_str;
    void* m_rest[23];
    Note* m_note;
    void* m_70;
    void SetFlag4(bool);
    void FUN_00501830(void*);
    bool FUN_00758350();
    bool FUN_00758390();
};
struct ListObj
{
    void* m_items[14];
    bool ContainsKey(TileF*);
    Obj* FindItemData(TileF*);
    void FUN_007314c0(void(__cdecl*)(TileF*, void*), int, int);
};
struct SoundObj
{
    void* m_s0;
    void* m_s4;
    void* m_s8;
    bool FUN_00ad8830(bool);
};
struct Mgr
{
    void ProcessAllTiles();
    void InsertAtPosition(const char*, void*, void*, int);
};
int __cdecl FUN_00406f60(BStr*, const char*, ...);
struct HostF
{
    void* m_pFirstNode[10];
    TileF* m_pTiles[16];
    ListObj m_kNode;
    int m_a0;
    int m_a4;
    void* m_a8;
    void* m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    unsigned char m_c0;
    unsigned char m_c1;
    unsigned char m_c2[26];
    SoundObj m_sound;
    Mgr* m_pManager;
    typedef void (HostF::*Handler)(Note*);
    Handler m_handlers[16];
    void SetTextSource(int);
    void FUN_007586e0(int);
    void FUN_00758a80();
    void RefreshDisplay();
    void __thiscall FUN_00757f70(int a1, TileF* a2);
};
}  // namespace fnv_00757f70

namespace fnv_00758ad0 {
struct StrMem
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    StrMem();
    ~StrMem();
    const char* FUN_00559450() const;
};
extern int DAT_0119f278;
struct TextTile
{
    void* FindTraitValue(int);
    void* FUN_00a00f30(int);
};
int __cdecl FUN_00406f60(StrMem*, const char*, ...);

}  // namespace fnv_00758ad0

// @f3 0x004a5280 (community match, verified in this file)
namespace f3m_004a5280 {
int __cdecl FUN_00509780(void* a);

class S_0050a0f0
{
public:
    int __thiscall FUN_0050a0f0(int aiValue);
};

class BGSExplosion
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
    S_0050a0f0* unk90;

public:
    int __thiscall FUN_004a5280(void* a);
};

// pdb: BGSExplosion::GetImpactData | BGSExplosion.obj | fnv360_0822_retail, call_gap, low
// pdb params: aehkMatType
int __thiscall BGSExplosion::FUN_004a5280(void* a)
{
    int r = 0;
    S_0050a0f0* p = unk90;
    if (p)
        r = p->FUN_0050a0f0(FUN_00509780(a));
    return r;
}


}   // namespace f3m_004a5280
