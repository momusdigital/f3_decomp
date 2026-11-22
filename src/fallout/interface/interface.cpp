// fallout/interface/interface.cpp: Interface, ConsoleManager, FileFinder, TESCreature and more (3 functions)
#include "f3_common.h"
#include "interface_rebase_packet.h"

class TESWorldSpace;
class Menu;
class TESForm;
class TESObjectREFR;
class NiControllerSequence;

class Interface
{
  public:
    static const char* GetInterfaceName();
    static float GetFirstInterfaceFloat();
    static float UpdateInterfaceState();
    static float GetThirdInterfaceFloat();
    static float GetFourthInterfaceFloat();
    static bool IsInterfaceOpen();
    static float GetInterfaceFloat();
    static Tile* GetPrimaryInterfaceTile();
    static Tile* GetSecondaryInterfaceTile();
    static NiNode* GetInterfaceNode();
    static bool IsAnyMenuOpen();

    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
    static bool IsInterfaceActive();

    enum enumMenus
    {
        eNoMenu = 0,
        eMainFour = 1,
        eOtherRoot = 2,
        eConsoleMenu = 3,
        eFirstMenu = 1001,
        eMessageMenu = 1001,
        eInventoryMenu = 1002,
        eStatsMenu = 1003,
        eHUDMainMenu = 1004,
        eLoadingMenu = 1007,
        eContainerMenu = 1008,
        eDialogMenu = 1009,
        eSleepWaitMenu = 1012,
        eStartMenu = 1013,
        eLockPickMenu = 1014,
        eQuantityMenu = 1016,
        eAudioMenu = 1017,
        eVideoMenu = 1018,
        eGameplayMenu = 1020,
        eMapMenu = 1023,
        eBookMenu = 1026,
        eLevelUpMenu = 1027,
        eBirthSignMenu = 1029,
        eRepairMenu = 1035,
        eRaceSexMenu = 1036,
        eCreditsMenu = 1047,
        eCharGenMenu = 1048,
        eTextEditMenu = 1051,
        eBarterMenu = 1053,
        eSurgeryMenu = 1054,
        eHackingMenu = 1055,
        eVATSMenu = 1056,
        eComputersMenu = 1057,
        eRepairServicesMenu = 1058,
        eTutorialMenu = 1059,
        eSPECIALBookMenu = 1060,
        eItemModMenu = 1061,
        eLoveTesterMenu = 1074,
        eCompanionWheelMenu = 1075,
        eTraitSelectMenu = 1076,
        eRecipeMenu = 1077,
        eSlotMachineMenu = 1080,
        eBlackJackMenu = 1081,
        eRouletteMenu = 1082,
        eCaravanMenu = 1083,
        eTraitMenu = 1084,
        eLastMenu = 1084
    };
    static void Init(bool);
    static void RefreshInterfaceState();
    static void SetQuestTarget(TESForm*, bool);
    static bool IsPipBoyOpen();
    static bool GetStatsMenuVisible();
    static bool IsGamePaused();
    static bool ContainerIsRecipe();
    static bool ContainerIsBarter();
    static void SetLookAtReference(TESObjectREFR*);
    static bool PlayNifSounds(NiControllerSequence*);
    static Menu* GetMenuById(int);
    static void SetHUDVisible(bool);
    static void SetTileFormattedText(Tile*, int, const char*, ...);
};

#include "interface_rebase_closure.h"

const char kMeshesFolder[] = "Meshes";

// Fresh-claim additions verified against the supplied PC spans.

class Modifier
{
  public:
    char GetKey(void);
};

namespace fnv_007023c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_007023c0

namespace fnv_00702400 {
struct Modifier
{
    bool GetKey();
    int GetMenuStackEntry(int);
};
}  // namespace fnv_00702400

namespace fnv_00702450 {
class Modifier
{
  public:
    char GetKey();
};

}  // namespace fnv_00702450

namespace fnv_00702640 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_00702640

namespace fnv_007027e0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_007027e0

namespace fnv_00702810 {
class Modifier
{
  public:
    char GetKey();
};

}  // namespace fnv_00702810

namespace fnv_00702840 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_00702840

namespace fnv_00702870 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class BGSMoviePlayer
{
  public:
    bool FUN_00ec17c0();
};

extern BGSMoviePlayer* DAT_0126fac4;

}  // namespace fnv_00702870

namespace fnv_007028b0 {
class Modifier
{
  public:
    bool GetKey();
};

class BGSMoviePlayer
{
  public:
    bool FUN_00ec17c0();
};

extern BGSMoviePlayer* DAT_0126fac4;

}  // namespace fnv_007028b0

struct FUN_00703060_shell : public InterfaceManager
{
    void FUN_00703060(bool);
};

namespace fnv_00703180 {
struct Modifier
{
    bool GetKey();
    TESObjectREFR* FUN_007031c0();
};
}  // namespace fnv_00703180

namespace fnv_00703d50 {
struct Modifier
{
    bool GetKey();
};
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    bool IsConsoleActive();
};
}  // namespace fnv_00703d50

namespace fnv_00703da0 {
struct Modifier
{
    bool GetKey();
    int AddMenuStackEntry(int, bool);
};
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    bool IsConsoleActive();
    void FUN_0071d580();
};
}  // namespace fnv_00703da0

namespace fnv_00704140 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl FUN_00796b90();

}  // namespace fnv_00704140

namespace fnv_00704490 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl FUN_00796b90();

}  // namespace fnv_00704490

namespace fnv_007046c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl FUN_00796b90();

}  // namespace fnv_007046c0

namespace fnv_007048c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class InventoryMenu
{
  public:
    static Tile* Create();
};

}  // namespace fnv_007048c0

namespace fnv_00704be0 {
class Modifier
{
  public:
    char GetKey(void);
};

}  // namespace fnv_00704be0

namespace fnv_00704f50 {
class Modifier
{
  public:
    char GetKey();
};

class ContainerMenu
{
  public:
    static void __cdecl Close();
};

}  // namespace fnv_00704f50

namespace fnv_00705070 {
struct Modifier
{
    bool GetKey();
};
}  // namespace fnv_00705070

namespace fnv_007050d0 {
class Modifier
{
  public:
    char GetKey(void);
};

}  // namespace fnv_007050d0

namespace fnv_007053f0 {
class Modifier
{
  public:
    char GetKey(void);
};

class StartMenu
{
  public:
    static bool __cdecl Create(bool, bool);
};

}  // namespace fnv_007053f0

namespace fnv_007058e0 {
class Modifier
{
  public:
    char GetKey(void);
};

}  // namespace fnv_007058e0

namespace fnv_00705910 {
struct Modifier
{
    bool GetKey();
};
struct TESNPC
{
    int FUN_00602170();
};
}  // namespace fnv_00705910

namespace fnv_00705990 {
struct Modifier
{
    bool GetKey();
};
struct TESNPC
{
    int FUN_00602170();
};
}  // namespace fnv_00705990

namespace fnv_007059d0 {
class Modifier
{
  public:
    char GetKey(void);
};

}  // namespace fnv_007059d0

namespace fnv_00705a00 {
class Modifier
{
  public:
    char GetKey();
};

bool __cdecl FUN_00709c00();

}  // namespace fnv_00705a00

namespace fnv_00705a90 {
class Modifier
{
  public:
    char GetKey();
};

}  // namespace fnv_00705a90

struct FUN_00705b10_Dummy
{
    char pad[0xc4];
    int val;
    void Set(int a);
};

namespace fnv_00705b30 {
struct Modifier
{
    bool GetKey();
};
struct IMStandIn
{
    void FUN_00716010(int a);
};
}  // namespace fnv_00705b30

class MapMenu
{
  public:
    void FUN_007069f0(unsigned char);
};
extern MapMenu* DAT_011da368;

int __cdecl MinInt(int, int);

class InventoryMenu
{
  public:
    char pad00[0x5c];
    Tile* pTile5C;
    char pad60[0x24];
    int iTab84;
    static InventoryMenu* ms_pInventoryMenu;
    static int ms_iCurrentTabTileID;
};

struct Tile_Set_Helper : public Tile
{
    void Set(int, int);
};

namespace fnv_00706a90 {
class StatsMenu
{
  public:
    static void __cdecl UpdateStatusEffects();
};
class MapMenu
{
  public:
    static void __cdecl SetMapPositionToPlayer();
    static void __cdecl UpdateMapPosition();
};

void __cdecl ClearMapMenuNote();

}  // namespace fnv_00706a90

struct BGSQuestObjective;
struct TESQuest;
struct RegionObjectEntry;
struct TESWorldSpace;

class MapMenu;
extern MapMenu* DAT_011da368;

int __cdecl FUN_004dc200();

struct FUN_00714d90_struct
{
    void PushMenuStackEntry(int);
};

struct IMStandIn
{
    void FUN_00715860(int a, int b, int c);
};

class TESResponse
{
  public:
    TESResponse* GetNext();
};

namespace fnv_00707930 {
struct Modifier
{
    void SetNeed(bool);
};
}  // namespace fnv_00707930

class FORenderedMenu;

int __cdecl FUN_004dc200();

extern int g_011d8950;
extern int DAT_011d8954;
extern int DAT_011d8958;
extern int DAT_011d895c;
extern int DAT_011d8964;
extern int DAT_011d899c;

class TESRace;
template <> class BSSimpleList<TESRace*>
{
  public:
    int GetSize();
};

struct StrHelper
{
    operator const char*() const;
};

namespace fnv_00703e80 {
struct InterfaceManager;
struct Modifier
{
    unsigned char GetKey();
};
InterfaceManager* FUN_004b7210();
bool QueueMessage(const char*, const char*, const char*, int, void*, int, int, const char*, char**, int, int, int,
                  float, float, float);
}  // namespace fnv_00703e80

namespace fnv_007053b0 {
struct InterfaceManager;
struct Modifier
{
    unsigned char GetKey();
};
InterfaceManager* FUN_004b7210();
}  // namespace fnv_007053b0

namespace fnv_00705b70 {
struct InterfaceManager;
struct Modifier
{
    unsigned char GetKey();
};
namespace fnv_0070b810 {
}
namespace fnv_0070b870 {
}
InterfaceManager* FUN_004b7210();
int MinInt(int, int);
}  // namespace fnv_00705b70

struct InterfaceManager;
class PlayerCharacter;
struct MobileObject;
struct Im7181
{
    void SetRenderedMenu(int);
};
extern PlayerCharacter* g_thePlayer;
InterfaceManager* FUN_004b7210();
MobileObject* GetDialogCastSound();
void ClearMapMenuNote();
MobileObject* GetDialogCastSound();

struct InterfaceManager;
InterfaceManager* FUN_004b7210();

struct QuantityData
{
    Tile* GetItem();
};

namespace fnv_00704af0 {
struct Modifier
{
    unsigned char GetKey();
};
bool __cdecl FUN_00702680(int, unsigned int);
void __cdecl FUN_00704bc0();

}  // namespace fnv_00704af0

namespace fnv_00705420 {
struct Modifier
{
    unsigned char GetKey();
};
struct BSS
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    ~BSS();
    operator const char*() const;
};
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

}  // namespace fnv_00705420

namespace fnv_00702330 {
class Modifier
{
  public:
    unsigned char GetKey(void);
};

}  // namespace fnv_00702330

Tile* __cdecl FindMenuById(int);
bool __cdecl FUN_00709c00();
class InterfaceManagerPC
{
  public:
    bool GetKey();
};

namespace fnv_00702960 {
struct Modifier
{
    unsigned char GetKey();
};
struct BGSMoviePlayer
{
    bool FUN_00ec17c0();
};
extern BGSMoviePlayer* DAT_0126fac4;

}  // namespace fnv_00702960

namespace fnv_00703000 {
struct Modifier
{
    unsigned char GetKey();
    void FUN_00703030();
};

}  // namespace fnv_00703000

namespace fnv_007030c0 {
struct Modifier
{
    unsigned char GetKey();
    void SetTileValues(int, int);
};

}  // namespace fnv_007030c0

namespace fnv_00703390 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class InterfaceManager;

}  // namespace fnv_00703390

char __cdecl ConsumeByteAtE4();

namespace fnv_007043d0 {
struct Modifier
{
    unsigned char GetKey();
};

}  // namespace fnv_007043d0

namespace fnv_00704420 {
struct Modifier
{
    unsigned char GetKey();
};

}  // namespace fnv_00704420

class MapMenu;
extern MapMenu* DAT_011da368;

namespace fnv_00704690 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_00704690

class ContainerMenu
{
  public:
    void FUN_0075c280(int);
};
extern ContainerMenu* DAT_011d93f8;

// @f3 0x00619590 (community match, verified in this file)
struct EventState {
    unsigned char enabled, unk01, unk02, unk03;
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
    unsigned char pending;
};
extern EventState* DAT_01075b24;
void __cdecl FUN_00bf3580(int);
// pdb: Interface::SetFirstChanceTextureRelease | Interface.obj | fnv360_0822_retail, call_gap, medium
void FUN_00704bc0() {
    if (DAT_01075b24 && DAT_01075b24->enabled) {
        DAT_01075b24->pending = 1;
        FUN_00bf3580(0);
    }
}


namespace fnv_00704f80 {
struct Modifier
{
    bool GetKey();
};

}  // namespace fnv_00704f80

namespace fnv_00704fc0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_00704fc0

namespace fnv_00705050 {
class ContainerMenu;
extern ContainerMenu* DAT_011d93f8;

}  // namespace fnv_00705050

namespace fnv_00705800 {
class Modifier
{
  public:
    unsigned char GetKey();
};
class StartMenu
{
  public:
    static bool Create(bool, bool);
};

}  // namespace fnv_00705800

namespace fnv_00705830 {
struct Modifier
{
    unsigned char GetKey();
};

}  // namespace fnv_00705830

struct GlobalObject_0045cfe0
{
    int* Int();
};
extern int g_011d8950;
extern int DAT_011d8960;

void GetOrCreateMenuTile(int);

namespace fnv_00705a60 {
struct Modifier
{
    unsigned char GetKey();
    void FUN_00717e30();
};

}  // namespace fnv_00705a60

namespace fnv_00705ad0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

struct FUN_00705b10_Dummy
{
    void Set(int);
};

}  // namespace fnv_00705ad0

namespace fnv_00705d90 {
struct Modifier
{
    unsigned char GetKey();
    int FUN_00705dd0();
};

}  // namespace fnv_00705d90

namespace fnv_00706230 {
struct Modifier
{
    unsigned char GetKey();
};

}  // namespace fnv_00706230

namespace fnv_00706270 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_00706270

class MapMenu;
extern MapMenu* DAT_011da368;

struct FUN_005e3fc0_shell
{
    unsigned int Get();
};

class Tile;

class TileMenu
{
  public:
    const char* FUN_00709a50();
};

namespace fnv_00703150 {
struct Modifier
{
    unsigned char GetKey();
};

}  // namespace fnv_00703150

namespace fnv_00703e10 {
class ConsoleManager
{
  public:
    static ConsoleManager* __cdecl Instance(bool);
    bool IsConsoleActive(void);
    void FUN_0071d580();
};

class Modifier
{
  public:
    unsigned char GetKey(void);
};

class FUN_00714d90_struct
{
  public:
    void PushMenuStackEntry(int);
};

}  // namespace fnv_00703e10

namespace fnv_00705cb0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

}  // namespace fnv_00705cb0

namespace fnv_00703030 {
struct FUN_00703060_shell
{
    char _pad[0x7c];
    bool b7c;
    void FUN_00703060(bool);
    void FUN_00703030();
};
}  // namespace fnv_00703030

namespace fnv_00703080 {
struct Modifier
{
    char GetKey();
};
}  // namespace fnv_00703080

namespace fnv_007037e0 {
class Modifier
{
  public:
    char GetKey();
    void ClearMenuIDs();
};
}  // namespace fnv_007037e0

namespace fnv_00703810 {
struct Modifier
{
    char GetKey();
};
InterfaceManager* FUN_004b7210();
}  // namespace fnv_00703810

namespace fnv_00705d10 {
struct Modifier
{
    char GetKey();
};
}  // namespace fnv_00705d10

namespace fnv_00705d50 {
struct Modifier
{
    char GetKey();
};
}  // namespace fnv_00705d50

int __cdecl MinInt(int, int);

struct Dummy00712450
{
    int SetNodeAlpha();
};
Dummy00712450* __stdcall _FUN_004b7210(int, float, float);

namespace fnv_00706860 {
struct SaveLoadFile;
struct NiQuaternion;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];

InterfaceManager* FUN_004b7210();
struct Tile_Set_Helper
{
    void Set(int, int);
};
class StatsMenu
{
  public:
    static void SetStatsPage(unsigned char);
};
void* memset(void*, int, unsigned int);
}  // namespace fnv_00706860

namespace fnv_00703610 {
struct Tile_Set_Helper
{
    void Set(int, int);
};
class InterfaceManagerPC
{
  public:
    bool GetKey();
};
struct Im7181
{
    void SetRenderedMenu(int);
};
Tile* __cdecl FindMenuById(int);

}  // namespace fnv_00703610

namespace fnv_007024e0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class BSThread
{
  public:
    unsigned int GetThreadID();
};

void* __cdecl _FUN_004b7210();
Menu* __cdecl FindMenuById(int);

}  // namespace fnv_007024e0

namespace fnv_00704170 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class MapMenu
{
  public:
    static void MenuDepthController();
};

Menu* __cdecl FindMenuById(int);
void __cdecl FUN_00704390();
void __cdecl ResetItemModMenu();
void __cdecl ResetRepairMenu();

}  // namespace fnv_00704170

namespace fnv_007056f0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

Menu* __cdecl FindMenuById(int);
Modifier* __cdecl _FUN_004b7210();

}  // namespace fnv_007056f0

class FUN_004b7210_class;

extern FUN_004b7210_class* __cdecl _FUN_004b7210();

class FUN_004b7210_class
{
  public:
    unsigned char GetKey();
    BSSimpleList<BGSPerk*>* GetBGSPerkList();
};

namespace fnv_007073d0 {
struct Setting
{
};

struct StartMenu : Setting
{
    const char* GetMenuTitle();
};

struct GlobalObject_0045cfe0 : Setting
{
    int* Int();
};

struct GameSettingCollection
{
    static GameSettingCollection* Instance();
    Setting* FUN_004f8a30(const char*);
};

template <class T> struct SettingCollectionList
{
    T* GetPtr(const char*);
};

struct INISettingCollection : SettingCollectionList<Setting>
{
};

template <class T> struct SettingT
{
    static INISettingCollection* GetCollection();
};

struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};

}  // namespace fnv_007073d0

namespace fnv_00702c80 {

class Modifier
{
  public:
    unsigned char GetKey();
};

class GO
{
  public:
    operator unsigned int() const;
};

class FUN_005e3fc0_shell
{
  public:
    unsigned int Get();
};

void* _FUN_004b7210();

}  // namespace fnv_00702c80

class B706130Node;

class B706130Tile
{
  public:
    B706130Node* FUN_0056c7f0();
};

class B706130Pick
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    B706130Pick();

    void SetTile(B706130Tile* pkTile);
    void FUN_00705fc0(B706130Node* pkNode);

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
};

extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int uExitCode);

char ConsumeByteAtE4();

struct Player;
struct Helper;
struct ActiveObject
{
    int FUN_0041ca90();
};
struct InterfaceObject
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Release();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual ActiveObject* CurrentObject();
};
struct Helper
{
    void SetPackageType(int);
    void FUN_00826b40(int);
    void FUN_00826b90(int);
    void FUN_00984f60(int);
};
struct Player
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Unknown010();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual void Unknown159();
    virtual void Unknown160();
    virtual void Unknown161();
    virtual void Unknown162();
    virtual void Unknown163();
    virtual void Unknown164();
    virtual void Unknown165();
    virtual void Unknown166();
    virtual void Unknown167();
    virtual void Unknown168();
    virtual void Unknown169();
    virtual void Unknown170();
    virtual void Unknown171();
    virtual void Unknown172();
    virtual void Unknown173();
    virtual void Unknown174();
    virtual void Unknown175();
    virtual void Unknown176();
    virtual void Unknown177();
    virtual void Unknown178();
    virtual void Unknown179();
    virtual void Unknown180();
    virtual void Unknown181();
    virtual void Unknown182();
    virtual void Unknown183();
    virtual void Unknown184();
    virtual void Unknown185();
    virtual void Unknown186();
    virtual void Unknown187();
    virtual void Unknown188();
    virtual void ActivateInterface(Helper*, int, int);
    InterfaceObject* FUN_008d8520();
    bool FUN_00437bf0();
    bool FUN_00437bd0();
    int FUN_008d6f30(int);
    void OpenDialogMenu();
};

bool __cdecl QueueMessage(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a10, va_list* args, int enabled,
                          int left, int right, float zero, float x, float y);

#include <stdarg.h>
struct HWND__;
struct WinPoint
{
    long x, y;
};
struct WinMessage
{
    HWND__* hwnd;
    unsigned int message, wParam;
    long lParam;
    unsigned int time;
    WinPoint pt;
};
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(WinMessage*, HWND__*, unsigned int, unsigned int,
                                                            unsigned int);
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const WinMessage*);
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const WinMessage*);

bool __cdecl QueueMessage(const char*, int, int, int, void (*)(), int, int, int, va_list*, bool, int, int, float, float,
                          float);
void __cdecl FUN_00403d30(void*, int, unsigned int);
class InputManager
{
  public:
    void FUN_00a23010();
};
class OSGlobals
{
  public:
    InputManager* FUN_00877720();
};

struct MenuProxy
{
    void FUN_00a1d910();
    void InitializeStatsMenu();
    void FUN_00a1db20();
};
struct TileProxy
{
    MenuProxy* FUN_00a03c90();
};
TileProxy* FUN_00a09030(int);
void ResetRepairMenu();
void ResetItemModMenu();

struct Data
{
    int GetLength();
    void GetData(char*);
};
struct Buffer
{
    void SaveData(void*, unsigned, int);
};
void FUN_00403d30(void*, int, unsigned);
// @f3 0x0061a210 (community match, verified in this file)
#include <string.h>
struct F3Setting_61a210
{
    float FUN_00becf40(int id);
};
struct F3Data_61a210
{
    void FUN_0061ee20(char* out);
};
struct F3Mgr_61a210
{
    char pad[0x9c];
    F3Setting_61a210* settings;
    char pad2[0x4d8 - 0xa0];
    F3Data_61a210 data;
};
struct F3Player_61a210
{
    char pad[0x70];
    unsigned char state;
};
extern F3Player_61a210* DAT_01076bb8;
unsigned char FUN_006847a0();
unsigned char FUN_00652de0();
float FUN_0065d800();
float FUN_0065d830();
struct F3Buffer_61a210
{
    void FUN_006e1830(void* data, unsigned size, int flags);
};

// pdb: Interface::SaveGame | Interface.obj | fnv360_0822_debug, call_seq, medium
// pdb params: apSaveGameBuffer
void FUN_007066d0(Buffer* buffer_)
{
    F3Buffer_61a210* buffer = (F3Buffer_61a210*)buffer_;
    char text[100];
    int length = (int)((F3Mgr_61a210*)DAT_01075b24)->settings->FUN_00becf40(0x1771);
    unsigned char a = FUN_006847a0();
    unsigned char b = FUN_00652de0();
    unsigned char c;
    if (DAT_01076bb8)
        c = DAT_01076bb8->state - 0x1c;
    else
        c = 4;
    buffer->FUN_006e1830(&length, 4, 0);
    buffer->FUN_006e1830(&a, 1, 0);
    buffer->FUN_006e1830(&b, 1, 0);
    buffer->FUN_006e1830(&c, 1, 0);
    float f1 = FUN_0065d800();
    float f2 = FUN_0065d830();
    buffer->FUN_006e1830(&f1, 4, 0);
    buffer->FUN_006e1830(&f2, 4, 0);
    memset(text, 0, 100);
    int size = 4;
    ((F3Mgr_61a210*)DAT_01075b24)->data.FUN_0061ee20(text);
    buffer->FUN_006e1830(&size, 4, 0);
    buffer->FUN_006e1830(text, size, 0);
}


class TESForm;
class TESGlobal;
class Setting;

class TESGlobal : public TESForm
{
  public:
    char FUN_00529ea0();
    float GetValue();
};

class Setting
{
  public:
    const char* String();
};

class NiStream
{
  public:
    virtual ~NiStream();
    char fileName[260];
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
    unsigned int unk5C4;
    unsigned int unk5C8;
    bool FUN_00c3a8a0(const char*, bool);
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NONE
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};

class B7AB690FullName
{
  public:
    const char* GetName() const;
};

class TESNPC : public TESBoundObject
{
  public:
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
    B7AB690FullName m_kFullName;
};

namespace fnv_008d66b0 {
#include <string.h>
#include <stdio.h>

struct WobbleName : NiFixedString
{
    WobbleName(const char*);
    ~WobbleName();
    operator const char*() const;
};
struct FileFinder
{
    static int Exist(const char*, char*, unsigned int, unsigned int);
};
int FUN_00406d30(char*, unsigned int, const char*);
}  // namespace fnv_008d66b0

namespace sleep704 {
struct M70Tile
{
    void FUN_00a1d910();
    void FUN_00a1db20();
};
struct M70Menu
{
    M70Tile* FUN_00a03c90();
};
struct M70Trait
{
    void FUN_00700320(int id, int value);
};
struct M70Hud
{
    void FUN_007f8a80();
    void FUN_007fa010(int a);
    bool IsUnk28Set();
};
struct M70Player
{
    bool FUN_009373f0();
    M70Trait* FUN_00586150();
    M70Hud* FUN_00704370();
};
M70Player* FUN_004b7210();
M70Menu* FUN_00a09030(int id);
bool FUN_00702680(int id, int a);
void FUN_00704390();
void ResetRepairMenu();
void ResetItemModMenu();
void FUN_00782470(int a);

}

// Candidate for FUN_0079ffb0 (claim clm_f5183b6336444303ae13, 0x0079ffb0, 5190 bytes)
// World-map tile mesh build / screenshot dump; param_1 != 0 selects the dump path.
// Builds on the packet's best prior attempt; corrected constructors, calls and local layout.
// Packet flags: /MT /Od /Oy- /GS /EHsc /Gy /GF. Entry ABI: __cdecl, caller pops.

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);

namespace points {
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
    FUN_006815c0(float, float, float);
    void FUN_0063c8a0(const FUN_006815c0*);
};
}
typedef points::FUN_006815c0 NiPt3;
namespace uvs {
struct FUN_006815c0
{
    float u, v;
    FUN_006815c0();
    FUN_006815c0(float, float);
};
}
typedef uvs::FUN_006815c0 NiPt2;
struct FUN_004a7800
{
    float r, g, b, a;
    FUN_004a7800();
    FUN_004a7800(float, float, float, float);
};
typedef FUN_004a7800 NiCol;

// chain objects reached through DAT_011dea3c members
struct Local12;
struct Mesh34;
struct V3Maker;
struct Mesh34
{
    void FUN_00439410(void*);
    void FUN_00a5a040();
    void FUN_004bc1f0(float, float, float);
};

// small local-object stand-ins (methods invoked with ecx = local)
struct V3Maker
{
    float x, y, z;
    NiPt3& FUN_00416870(float x, float y, float z);
    NiPt2& FUN_00452dc0(float u, float v);
    NiCol& FUN_00414430(float a, float b, float c, float d);
    void FUN_0043d410(float a, int b, int c);
    void FUN_0063c8a0(NiPt3* p);
};
struct Obj16
{
    struct FloatColor
    {
        float r, g, b, a;
    } c;
    Obj16(float, float, float, float);
};
struct Local12
{
    unsigned int value;
    Local12(int);
    ~Local12();
    unsigned int FUN_00559450();
    void FUN_0066b0d0(int);
};

// mesh/material stand-ins
struct ObjD4
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjD4(unsigned short, void*, void*, void*, void*, int, int, unsigned int, void*, int, int, int, int);
};
struct ObjB0
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjB0(bool);
    void FUN_00bb7a10(unsigned int);
    void FUN_008cc6d0(int);
    void SetNavMeshInfo(Obj16*);
    void SetFlag(int);
};
struct Obj1C
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Obj1C();
    void FUN_00439340(int);
    void FUN_00439390(int);
    void FUN_0049ed90(int);
};

// free helpers; conventions read from add esp evidence
extern "C" void __cdecl FUN_006815c0();
extern "C" void __cdecl FUN_004a7800();

namespace fnv_00705ec0 {
class IMHelper
{
  public:
    bool FUN_009373f0();
    void SetRenderedMenu();
};
class ValueHolder
{
  public:
    void* FUN_0056c7f0();
};
class DatHolder
{
  public:
    unsigned char* FUN_00408d60();
};
extern DatHolder DAT_011db620;
class SpawnedObject
{
  public:
    SpawnedObject();
    SpawnedObject* Init();
    void Attach(ValueHolder* a);
    void Set(void* a);
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
};
InterfaceManager* FUN_004b7210();
IMHelper* __stdcall Getter2(SpawnedObject* obj);
ValueHolder* FUN_00765b80(void* a);
void FUN_00a04200(int a);
// @fnv 0x00705ec0
bool FUN_00705ec0(void* arg)
{
    if (FUN_004b7210() != 0 && ((IMHelper*)FUN_004b7210())->FUN_009373f0())
    {
        ValueHolder* v = FUN_00765b80(arg);
        if (*DAT_011db620.FUN_00408d60())
        {
            FUN_00a04200(0);
            SpawnedObject* obj = new SpawnedObject();
            obj->Attach(v);
            obj->Set(v->FUN_0056c7f0());
            Getter2(obj)->SetRenderedMenu();
        }
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00705ec0

namespace fnv_007046f0 {
struct MenuQ
{
    void FUN_00a1d910();
    void FUN_00a1db20();
};
struct TileQ
{
    MenuQ* FUN_00a03c90();
    void FUN_00700320(int, int);
};
TileQ* FUN_00a09030(int);
bool FUN_00702680(int, int);
void FUN_00704390();
void FUN_00782470(int);

}  // namespace fnv_007046f0

namespace s7094f0 {

struct InterfaceManagerView
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
    int m_iModalCount;

    bool FUN_007023a0();
    int FUN_00586150(int iArg);
};

struct NameMenu
{
    NameMenu(int iArg0, int iArg1);

    void FUN_00a087d0(int iTile);
    void FUN_00707e10(const char* pcName);
    void FUN_00409480(struct NameTile* pkTile);

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
    int unk3c;
};

struct NameTile
{
    NameTile();

    void FUN_00a1dc70(NameMenu* pkNameMenu, int iArg);

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
    int unk28;
};

extern TESObjectREFR* DAT_011d8954;
extern int DAT_011d8958;
extern int DAT_011d895c;
extern int DAT_011d8960;
extern int DAT_011d8964;
extern int DAT_011d899c;

InterfaceManagerView* FUN_004b7210();
bool FUN_00705ec0(TESObjectREFR* pkRef);
int GetOrCreateMenuTile(int iArg);

static const char s_szPlayerNameEntryMenu[] = "Player Name Entry Menu";

}

struct DisplayTile;
struct DisplayItem;
struct DisplayForm;
struct DisplayPlayer;

struct DisplayList
{
    void* FUN_00726070();
    DisplayTile** FUN_00683520(void**);
    void** FUN_006815c0();
};

struct DisplayName
{
    const char* FUN_00408da0();
};

struct DisplayTile
{
    int unk00;
    DisplayList children;
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
};

struct DisplayItem
{
    DisplayForm* FUN_0044ddc0();
    DisplayForm* GetExtraForm();
    float FUN_004bd400();
    unsigned char FUN_004bd820();
    bool HasEffect(int);
    float FUN_004bcdb0(bool);
    DisplayList* FUN_00559450();
    int FUN_00726070();
};

struct DisplayForm
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

    DisplayName name;
    int FUN_00401170();
    void FUN_00503a70(char*, int);
    float FUN_004be380(bool);
    int GetField19C();
    unsigned char FUN_00525b20(bool, int, DisplayPlayer*);
    DisplayForm* Script_IsInListFunction(DisplayPlayer*);
    const char* GetStringAtOffsetC4();
    int GetFlaggedValue(bool);
    float FUN_00709430(int);
    float FUN_004be060();
    float FUN_004be180();
    DisplayForm* FUN_004bd570(int);
    bool FUN_0040e210(int);
};

struct DisplayProcess
{

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

    virtual void v59();

    virtual void v60();

    virtual void v61();

    virtual void v62();

    virtual void v63();

    virtual void v64();

    virtual void v65();

    virtual void v66();

    virtual void v67();

    virtual void v68();

    virtual void v69();

    virtual void v70();

    virtual void v71();

    virtual void v72();

    virtual void v73();

    virtual void v74();

    virtual void v75();

    virtual void v76();

    virtual void v77();

    virtual void v78();

    virtual void v79();

    virtual void v80();

    virtual void v81();

    virtual DisplayItem* Weapon();
    virtual DisplayItem* Ammo();
};

struct ActorValues
{
    int unk00;
};

struct DisplayPlayerPrefix
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
};

struct DisplayPlayer : DisplayPlayerPrefix, ActorValues
{
    bool FUN_004d1360();
    DisplayProcess* FUN_008d8520();
};

struct DisplaySetting
{
    const char* FUN_00403df0();
    float* FUN_00403e20();
};

extern DisplaySetting *DAT_0118a644, *DAT_0118a648, *DAT_0118a640;

extern DisplaySetting DAT_011d4024, DAT_011c6478, DAT_011c64a8, DAT_011c3cb4, DAT_011d20c4, DAT_011d412c, DAT_011d2c7c,
    DAT_011d2aa8, DAT_011d26a0, DAT_011d4da4, DAT_011d4edc, DAT_011d330c;

extern char DAT_0106ed20[], DAT_0106ed18[], DAT_0106ed0c[], DAT_0106ecfc[], DAT_01020764[], DAT_0106ecf4[],
    DAT_01019f08[], DAT_0106ece8[], DAT_01047008[], DAT_0106ece0[], DAT_0106ecd8[], DAT_0106ecd0[], DAT_0106ecc8[],
    DAT_01020768[], DAT_01030018[], DAT_01018348[];

void FUN_00406d30(char*, unsigned int, const char*);
int MinInt(int, int);
