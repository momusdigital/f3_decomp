// fallout/interface/menus/levelupmenu.cpp: Holder, LBItemListBox, LevelUpMenu, EffectSetting and more (3 functions)
#include "f3_common.h"
#include "levelupmenu_decls.h"

struct ActorValue
{
    static bool __cdecl GetFlag(int, unsigned int);
};

struct Menu;
struct Tile;

namespace fnv_007851d0 {
struct ActorValue
{
    enum Index
    {
    };
};
struct NiNodeBooleanState
{
    bool GetBooleanValue();
    void FUN_008d5270();
};
struct Actor
{
    void ConfigureActorState(bool, bool);
};
struct Tile
{
    void Set(int, int);
};
struct PC7d
{
    NiNodeBooleanState* FUN_00464e10();
    void ConfigureActorState(bool, bool);
};
extern PC7d* g_thePlayer;
extern int DAT_011d9fdc;
void __cdecl FUN_008d5270();

}  // namespace fnv_007851d0

extern int DAT_011d9fdc;

struct FUN_007866e0_shell
{
    void UpdateDisplayValue(const char*);
};

struct TESObjectREFR
{
};
struct FUN_00785150_This
{
    bool FUN_00785150(TESObjectREFR*);
};

struct Tile
{
    bool ContainsTrait(int);
    void Set(int, int);
};
struct Holder
{
    void UpdateTileEffects(Tile*);
};
extern int DAT_011d9fdc;
extern int DAT_011d9fe0;
// If the tile reports the state stored in DAT_011d9fe0, clears that state via Set and notifies the holder at DAT_011d9fdc.
// @f3 0x0048bad0 (community match, verified in this file)
struct A1450MemoryManager { void Deallocate(void*); };
extern A1450MemoryManager DAT_011f6238;
struct Cls_0048bad0 {
    int unk00, unk04;
    void** ptr08;
    void* ptr0c;
    void FUN_0048bad0();
};
// pdb: LipSynchAnim::~LipSynchAnim | LipSynchAnim.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: MobileObject::DialogueConversationCallBack)
void Cls_0048bad0::FUN_0048bad0() {
    DAT_011f6238.Deallocate(*ptr08);
    DAT_011f6238.Deallocate(ptr08);
    DAT_011f6238.Deallocate(ptr0c);
}


namespace fnv_00786570 {
struct BGSPerk;
struct Tile
{
    bool ContainsTrait(int);
};
extern int DAT_011d9fe0;
template <int N> struct Pad;
template <> struct Pad<1>
{
    virtual void F(int (*)[1]);
};
template <int N> struct Pad : Pad<N - 1>
{
    virtual void F(int (*)[N]);
};
struct PC7d : Pad<294>
{
    virtual void Func498(BGSPerk*, int);
    virtual void Filler();
    virtual bool Func4A0(BGSPerk*, int, int);
};
extern PC7d* g_thePlayer;
}  // namespace fnv_00786570

namespace fnv_007871c0 {
struct WeatherEntry;
struct BSSimpleList
{
    void Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
struct Holder
{
    char _0[4];
    BSSimpleList _4;
    void SortWeatherEntries(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
    void ResetAndProcessTiles();
};
}  // namespace fnv_007871c0

namespace fnv_007864e0 {
struct TESObjectREFR;
struct PC7d;
struct FUN_006aabf0_shell
{
    signed char GetByteAt39();
};
struct FUN_00785150_This
{
    bool FUN_00785150(TESObjectREFR*);
};
struct Actor
{
    unsigned short GetLevel();
};
struct Tile
{
    void Set(int, float, bool);
};
extern int DAT_011d9ff4;
extern PC7d* g_thePlayer;
}  // namespace fnv_007864e0

namespace fnv_00786110 {
struct Tile
{
    bool ContainsTrait(int);
};
}  // namespace fnv_00786110

struct TGF
{
    float GetFloat(int);
};
int __cdecl GetTileValueID(const char*, int);

namespace fnv_00785990 {

struct Tile
{
    void Set(int, int);
    void Set(int, char const*, bool);
};

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);

}  // namespace fnv_00785990

namespace fnv_007865d0 {
class FUN_006aabf0_shell
{
  public:
    unsigned char GetByteAt39(void);
};

class TGF
{
  public:
    float GetFloat(int);
};

class Tile : public TGF
{
  public:
    char const* GetString(int);
};

class BGSPerk : public Tile
{
};

template <class T> class ListBoxItem
{
  public:
    T m_pInventoryEntryData;
    FUN_006aabf0_shell* m_pShell;
};

extern int DAT_011d9ff4;

}  // namespace fnv_007865d0

namespace fnv_007866e0 {
struct TGF
{
    float GetFloat(int);
};

struct Tile : public TGF
{
    void Set(int, char const*, bool);
};

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);
int __cdecl MinInt(int, int);
int __cdecl FUN_00647b70(int, int);
int GetTileValueID(char const*, int);

extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;

struct FUN_007866e0_shell
{
    void UpdateDisplayValue(Tile* apTile);
};

}  // namespace fnv_007866e0

// FUN_00786bb0 : constructor of a polymorphic object. It constructs the base,
// constructs the sub-object at +4, installs its own vtable, zeroes a set of
// members and two words, clears three floats, runs two setup calls and
// returns this.

void* __cdecl FUN_00a00940(const void* data, int flags);

struct LevelValue
{
    float __thiscall FUN_00a011b0(unsigned int property);
    void __thiscall FUN_00a012d0(int property, float value, int doUpdate);
    void __thiscall FUN_00700320(int property, int value);
};
extern "C" int __cdecl FUN_00a01860(const char*);
extern "C" int __cdecl FUN_00647b70(int, int);

struct ViewTile
{
    void Set(int, const char*, bool);
    void Set(int, int);
    const char* GetString(int);
    ViewTile* Parent();
};
struct SkillList
{
    virtual void Select(ViewTile*);
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
    unsigned int Lookup(ViewTile*);
};

namespace fnv_00785540 {
struct SkillTile
{
    void SetName(const char*);
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, int);
};
struct SkillList
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void Sort(void(__cdecl*)());
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
    void FUN_0075a0d0(Tile*, const char*);
    SkillTile* AddListEntry(int, const char*, int, int);
    SkillTile* AddItemTile(void*, const char*, int, int);
};
struct ActorValues
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual int GetValue(int);
};
struct Perk;
struct PlayerSkills
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot00a();
    virtual void slot00b();
    virtual void slot00c();
    virtual void slot00d();
    virtual void slot00e();
    virtual void slot00f();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot01a();
    virtual void slot01b();
    virtual void slot01c();
    virtual void slot01d();
    virtual void slot01e();
    virtual void slot01f();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot02a();
    virtual void slot02b();
    virtual void slot02c();
    virtual void slot02d();
    virtual void slot02e();
    virtual void slot02f();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot03a();
    virtual void slot03b();
    virtual void slot03c();
    virtual void slot03d();
    virtual void slot03e();
    virtual void slot03f();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot04a();
    virtual void slot04b();
    virtual void slot04c();
    virtual void slot04d();
    virtual void slot04e();
    virtual void slot04f();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot05a();
    virtual void slot05b();
    virtual void slot05c();
    virtual void slot05d();
    virtual void slot05e();
    virtual void slot05f();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot06a();
    virtual void slot06b();
    virtual void slot06c();
    virtual void slot06d();
    virtual void slot06e();
    virtual void slot06f();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot07a();
    virtual void slot07b();
    virtual void slot07c();
    virtual void slot07d();
    virtual void slot07e();
    virtual void slot07f();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot08a();
    virtual void slot08b();
    virtual void slot08c();
    virtual void slot08d();
    virtual void slot08e();
    virtual void slot08f();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot09a();
    virtual void slot09b();
    virtual void slot09c();
    virtual void slot09d();
    virtual void slot09e();
    virtual void slot09f();
    virtual void slot0a0();
    virtual void slot0a1();
    virtual void slot0a2();
    virtual void slot0a3();
    virtual void slot0a4();
    virtual void slot0a5();
    virtual void slot0a6();
    virtual void slot0a7();
    virtual void slot0a8();
    virtual void slot0a9();
    virtual void slot0aa();
    virtual void slot0ab();
    virtual void slot0ac();
    virtual void slot0ad();
    virtual void slot0ae();
    virtual void slot0af();
    virtual void slot0b0();
    virtual void slot0b1();
    virtual void slot0b2();
    virtual void slot0b3();
    virtual void slot0b4();
    virtual void slot0b5();
    virtual void slot0b6();
    virtual void slot0b7();
    virtual void slot0b8();
    virtual void slot0b9();
    virtual void slot0ba();
    virtual void slot0bb();
    virtual void slot0bc();
    virtual void slot0bd();
    virtual void slot0be();
    virtual void slot0bf();
    virtual void slot0c0();
    virtual void slot0c1();
    virtual void slot0c2();
    virtual void slot0c3();
    virtual void slot0c4();
    virtual void slot0c5();
    virtual void slot0c6();
    virtual void slot0c7();
    virtual void slot0c8();
    virtual void slot0c9();
    virtual void slot0ca();
    virtual void slot0cb();
    virtual void slot0cc();
    virtual void slot0cd();
    virtual void slot0ce();
    virtual void slot0cf();
    virtual void slot0d0();
    virtual void slot0d1();
    virtual void slot0d2();
    virtual void slot0d3();
    virtual void slot0d4();
    virtual void slot0d5();
    virtual void slot0d6();
    virtual void slot0d7();
    virtual void slot0d8();
    virtual void slot0d9();
    virtual void slot0da();
    virtual void slot0db();
    virtual void slot0dc();
    virtual void slot0dd();
    virtual void slot0de();
    virtual void slot0df();
    virtual void slot0e0();
    virtual void slot0e1();
    virtual void slot0e2();
    virtual void slot0e3();
    virtual void slot0e4();
    virtual void slot0e5();
    virtual void slot0e6();
    virtual void slot0e7();
    virtual void slot0e8();
    virtual void slot0e9();
    virtual void slot0ea();
    virtual void slot0eb();
    virtual void slot0ec();
    virtual void slot0ed();
    virtual void slot0ee();
    virtual void slot0ef();
    virtual void slot0f0();
    virtual void slot0f1();
    virtual void slot0f2();
    virtual void slot0f3();
    virtual void slot0f4();
    virtual void slot0f5();
    virtual void slot0f6();
    virtual void slot0f7();
    virtual void slot0f8();
    virtual void slot0f9();
    virtual void slot0fa();
    virtual void slot0fb();
    virtual void slot0fc();
    virtual void slot0fd();
    virtual void slot0fe();
    virtual void slot0ff();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot10a();
    virtual void slot10b();
    virtual void slot10c();
    virtual void slot10d();
    virtual void slot10e();
    virtual void slot10f();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot11a();
    virtual void slot11b();
    virtual void slot11c();
    virtual void slot11d();
    virtual void slot11e();
    virtual void slot11f();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual unsigned char GetPerkRank(void*, int);
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
    ActorValues values;
};
struct PerkName
{
    const char* FUN_00408da0();
};
struct Perk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    PerkName name;
    unsigned char FUN_005d4ee0();
};
extern PlayerSkills* DAT_011dea3c;
extern int DAT_011d9ff0, DAT_011d9fe4, DAT_011d9ff8;
extern const char str_01073dcc[], str_01073db8[], str_0106eb00[];
int MinInt(int, int);
int FUN_00406d00(char*, unsigned int, const char*, ...);
}  // namespace fnv_00785540

int FUN_00a01860(const char*);
extern int DAT_011d9fe8;
extern int DAT_011d9fd8;
extern int DAT_011d9fd4;

extern int DAT_011dea3c;
extern int DAT_011d9ff0;

extern int DAT_011d9ff8;

void FUN_00786240(Tile* tile, int idx);

// Destructor: clear the model list, unregister from the global tracker, then the list member is destroyed.

class C6C80List
{
  public:
    ~C6C80List();

    void* m_pkHead;
    void* m_pkTail;
};

class FUN_00786c80;
void __cdecl C6C80Unregister(FUN_00786c80* pkObject);

class FUN_00786c80
{
  public:
    virtual ~FUN_00786c80();
    void Clear();

    C6C80List m_kModels;
};

// Clears the object's model list, then unregisters the object from the C6C80 registry.
// @fnv 0x00786c80
FUN_00786c80::~FUN_00786c80()
{
    Clear();
    C6C80Unregister(this);
}

struct LBTile;
struct LBMenu
{
    LBTile* AddTileFromTemplate(LBTile* parent, const char* templ, int unk);
};
struct LBValue
{
    void ResetOps();
    void AddOp(int op, LBTile* src, int traitID);
    void AddFloatOp(int op, float val);
    void Finish(bool b);
};
struct LBTile
{
    LBMenu* GetMenu();
    void* GetValue(int traitID);
    void Set(int traitID, int val);
    void SetString(int traitID, const char* str, bool propagate);
    float GetFloat(int traitID);
    LBValue* GetActionValue(int traitID);
    static int __cdecl TraitNameToID(const char* name, int unk);
};
struct LBItem
{
    LBItem(LBTile* tile, int* item);
    LBTile* tile;
    int item;
    bool filtered;
};
struct LBItemList
{
    LBItem* data;
    LBItemList* next;
    void Insert(LBItem* item, int (*sortFunc)(LBItem*, LBItem*));
    void AddTail(LBItem* const& item);
};
struct LBItemListBox
{
    int unk00;
    LBItemList list;
    LBTile* parentTile;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_007242c0(unsigned int a);
    void Sort();
    void AccumulateTileHeight(LBTile* tile);
    void FUN_007880a0();
    int GetNumVisible();
    LBTile* AddItemTile(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* templ);
};

namespace fnv_00786f90 {

struct LBTile
{
    virtual ~LBTile();
    void Set(int aiID, float afValue, bool abPropagate);
};

struct LBObject
{
    ~LBObject();
};

struct LBItem
{
    LBTile* pTile;
    LBObject* pObject;
};

}  // namespace fnv_00786f90

int __cdecl FUN_00a00940(const char* pcName, int iDefault);

class Tile;
class Menu;
struct InterfaceManager;
int FUN_00a01860(const char* apName);
InterfaceManager* FUN_004b7210();
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int aiTrait, float afValue, bool abFlag);
};
struct FUN_00a01290_shell
{
    void SetTraitAndReset(int aiTrait, float afValue);
};
struct FUN_00a03c90_shell
{
    Menu* FUN_00a03c90();
};

int __cdecl TraitNameToID(const char* name, int unk);
extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;
extern int DAT_011d9fe8;
extern int DAT_011d9fd8;
extern int DAT_011d9fd4;
extern int DAT_011d9ff8;
extern int DAT_011d9fe0;
extern int DAT_011d9ff4;
struct Menu
{
    Menu();
    virtual ~Menu();
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
};
template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList* next;
    BSSimpleList();
    ~BSSimpleList();
};

int __cdecl FUN_00a00940(const char* s, int n);

struct ScrollTile;

struct ScrollMenuObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetValue(int aiValue, ScrollTile* apTile);
};

struct ScrollTile
{
    void SetFloat(int aiID, float afValue, bool abPropagate);
    void SetFloatNoProp(int aiID, float afValue);
    float GetFloat(unsigned int aiID);
    ScrollTile* GetParentTile();
    ScrollMenuObj* GetParentMenu();
};

namespace fnv_00787260 {
struct LBTile
{
    double FUN_00a011b0(int traitID);
    bool IsTraitNonZero(int traitID);
};
int __cdecl FUN_00a01860(const char* name);
int __cdecl FUN_00a00940(const char* name, int fallback);

struct LBItem
{
    LBTile* tile;
    int item;
    bool filtered;
};
struct LBItemList
{
    LBItem* data;
    LBItemList* next;
    LBItemList* FUN_00726070();
    LBItem** FUN_006815c0();
};
struct LBItemListBox : LBItemList
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual LBTile* GetItemTile(unsigned int index, bool option);
    LBTile* parentTile;
    LBTile* selectedTile;
    int unk14;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_00787b70();
    LBTile* FUN_00787260(int key);
};

}  // namespace fnv_00787260

namespace fnv_00784c80 {
struct Tile;
struct FUN_00a03c90_shell
{
    Menu* FUN_00a03c90();
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int, float);
};
struct FUN_00a01290_shell
{
    void SetTraitAndReset(int, float);
};
extern int DAT_011dea3c;
void* FUN_004b7210();
int FUN_00406d00(char*, int, const char*, ...);
struct ContNode;
ContNode* __fastcall FUN_00726070(ContNode*);
struct FUN_006aabf0_shell
{
    unsigned char GetByteAt39();
};
int FUN_00a01860(const char*);

static const char s_xml[] = "Data\\Menus\\levelup_menu.xml";
static const char s_err[] = "MENUS: Level Up Menu Creation Failed... Are your menu and art resources up to date?";
static const char s_title0[] = "_Title_0";
static const char s_title1[] = "_Title_1";
static const char s_curpage[] = "_CurrentPage";
static const char s_endpage[] = "_EndPage";
}  // namespace fnv_00784c80

extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;

// Finds the matching item, adjusts its stored value against tile bounds and overflow, then updates a tile trait.
// @f3 0x00655570 (community match, verified in this file)
struct F6AD50_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct Tile_00655570
{
    float __thiscall FUN_00becf40(int trait);
    void __thiscall FUN_00bee190(int trait, float value, int doUpdate);
    void SetInt(int trait, int value) { FUN_00bee190(trait, (float)value, 1); }
    void AddInt(const int& trait, const int& value) { FUN_00bee190(trait, FUN_00becf40(trait) + value, 1); }
};
struct Array_00f6ad50
{
    F6AD50_Entry* data;
    unsigned int count;
    unsigned int GetCount() const { return count; }
    F6AD50_Entry* GetItem(unsigned int index) const { return &data[index]; }
};
extern Array_00f6ad50 DAT_00f6ad50;
extern int DAT_010768f4;
extern int DAT_010768fc;
extern int DAT_01076900;
extern char str_00e06058[];
extern char str_00e06064[];
extern char str_00e06070[];
extern "C" int __cdecl FUN_00bea9e0(const char*);

// pdb: LevelUpMenu::PerkUpdateFunc | LevelUpMenu.obj | fnv360_0822_retail, ustr, medium
// pdb params: apTile, aeIndex
void __cdecl FUN_00786240(LevelValue* apTile, int aiMatchValue)
{
    Tile_00655570* T = (Tile_00655570*)apTile;
    unsigned int i = 0;
    for (; i < DAT_00f6ad50.GetCount(); ++i)
    {
        if (DAT_00f6ad50.GetItem(i)->unk10 == aiMatchValue)
        {
            int totalI = (int)(T->FUN_00becf40(DAT_010768f4) + T->FUN_00becf40(DAT_010768fc) + T->FUN_00becf40(DAT_01076900));
            int overflow = FUN_00bea9e0(str_00e06070);
            if (T->FUN_00becf40(overflow) != 0.0f)
            {
                DAT_00f6ad50.GetItem(i)->unk00 += (int)T->FUN_00becf40(overflow);
                T->FUN_00bee190(overflow, 0.0f, 1);
            }
            if ((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) > T->FUN_00becf40(FUN_00bea9e0(str_00e06064)))
            {
                int diff = (int)((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) - T->FUN_00becf40(FUN_00bea9e0(str_00e06064)));
                T->SetInt(FUN_00bea9e0(str_00e06070), diff);
                DAT_00f6ad50.GetItem(i)->unk00 -= diff;
            }
            else if ((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) < T->FUN_00becf40(FUN_00bea9e0(str_00e06058)))
            {
                int diff = (int)((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) - T->FUN_00becf40(FUN_00bea9e0(str_00e06058)));
                T->SetInt(FUN_00bea9e0(str_00e06070), diff);
                DAT_00f6ad50.GetItem(i)->unk00 -= diff;
            }
            T->AddInt(DAT_010768fc, DAT_00f6ad50.GetItem(i)->unk00);
        }
    }
}
