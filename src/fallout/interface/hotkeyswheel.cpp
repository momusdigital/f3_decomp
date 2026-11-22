// fallout/interface/hotkeyswheel.cpp: Wheel, HotkeyWheelUpdate, HWShell (1 function)
#include "f3_common.h"
#include "hotkeyswheel_decls.h"

bool __cdecl HotkeyWheelProbeA();
int __cdecl HotkeyWheelProbeB(int, int);

// Returns 1 if HotkeyWheelProbeA succeeds and any of HotkeyWheelProbeB(2/1/4/3, 0) is not -1, otherwise 0.
// @f3 0x00618820 (community match, verified in this file)
// pdb: HotKeysWheel::IsDPadPressed | HotKeysWheel.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap_sim), high
unsigned char HotKeysWheel_IsDPadPressed()
{
    int result;
    if (HotkeyWheelProbeA() && (HotkeyWheelProbeB(2, 0) != -1 || HotkeyWheelProbeB(1, 0) != -1 ||
                                HotkeyWheelProbeB(4, 0) != -1 || HotkeyWheelProbeB(3, 0) != -1))
        result = 1;
    else
        result = 0;
    return result;
}


namespace BGSEquipType {
enum EQUIP_TYPE
{
};
}

static const char str_InterfaceIcons[] = "Interface\\Icons\\";
static const char str_HotKeyIcon[] = "_HotKeyIcon";
static const char str_HotKeyAssigned[] = "_HotKeyAssigned";
static const char str_FormatCount[] = "%s (%d)";
