#include <stdlib.h>
#include <new>
#include <new>
#include <new>
#include <new>
// src/f3staging/f3blk_00cc0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00cdc090 (community match, verified in this file)
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager g_memoryManager;

class FUN_00403100
{
  public:
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    FUN_00403100(const char* a, const char* b);
    int unk00;
    int unk04;
    int unk08;
};

void operator delete(void* p);

extern FUN_00403100* DAT_01073410;
extern FUN_00403100* DAT_01073414;
extern FUN_00403100* DAT_01073418;
extern FUN_00403100* DAT_0107341c;
extern FUN_00403100* DAT_01073420;
extern FUN_00403100* DAT_01073424;
extern FUN_00403100* DAT_01073428;
extern FUN_00403100* DAT_0107342c;
extern char DAT_00dfa9ac[];
extern char DAT_00dfa998[];
extern char DAT_00dfa9a4[];
extern char DAT_00dfa98c[];
extern char DAT_00dfa974[];
extern char DAT_00dfa984[];
extern char DAT_00dfa968[];
extern char DAT_00dbe0d8[];
extern char DAT_00dbe0d4[];
extern char DAT_00dfa950[];
extern char DAT_00dfa960[];
extern char DAT_00dfa944[];
extern char DAT_00dfa930[];
extern char DAT_00dfa93c[];

// pdb: `dynamic initializer for 'psJoystick'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void FUN_00cdc090()
{
    DAT_01073410 = new FUN_00403100(DAT_00dfa9ac, DAT_00dbe0d4);
    DAT_01073414 = new FUN_00403100(DAT_00dfa998, DAT_00dfa9a4);
    DAT_01073418 = new FUN_00403100(DAT_00dfa98c, "Right");
    DAT_0107341c = new FUN_00403100(DAT_00dfa974, DAT_00dfa984);
    DAT_01073420 = new FUN_00403100(DAT_00dfa968, DAT_00dbe0d8);
    DAT_01073424 = new FUN_00403100(DAT_00dfa950, DAT_00dfa960);
    DAT_01073428 = new FUN_00403100(DAT_00dfa944, "Left");
    DAT_0107342c = new FUN_00403100(DAT_00dfa930, DAT_00dfa93c);
}

// @f3 0x00cdbe50 (community match, verified in this file)
class GameSettingCollection;

class Setting
{
public:
    virtual ~Setting();

    const char* value;
    const char* name;
};

class SettingHeap
{
public:
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};
extern SettingHeap DAT_01090a78;

template <class Collection>
class SettingT : public Setting
{
public:
    SettingT(const char* name, const char* value);
    virtual ~SettingT();

    static void* operator new(unsigned int size) throw()
    {
        return DAT_01090a78.FUN_0086b930(size);
    }

    static void operator delete(void* memory)
    {
        DAT_01090a78.FUN_0086ba60(memory);
    }
};

typedef SettingT<GameSettingCollection> GameSetting;

extern GameSetting* DAT_0107339c;
extern GameSetting* DAT_010733a0;
extern GameSetting* DAT_010733a4;
extern GameSetting* DAT_010733a8;
extern GameSetting* DAT_010733ac;
extern GameSetting* DAT_010733b0;
extern GameSetting* DAT_010733b4;
extern GameSetting* DAT_010733b8;
extern GameSetting* DAT_010733bc;

// pdb: `dynamic initializer for 'psMouse'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void __cdecl FUN_00cdbe50()
{
    DAT_0107339c = new GameSetting("sMouseLeftButton", "Mouse1");
    DAT_010733a0 = new GameSetting("sMouseRightButton", "Mouse2");
    DAT_010733a4 = new GameSetting("sMouseMiddleButton", "Wheel");
    DAT_010733a8 = new GameSetting("sMouseButton3", "Button 3");
    DAT_010733ac = new GameSetting("sMouseButton4", "Button 4");
    DAT_010733b0 = new GameSetting("sMouseButton5", "Button 5");
    DAT_010733b4 = new GameSetting("sMouseButton6", "Button 6");
    DAT_010733b8 = new GameSetting("sMouseButton7", "Button 7");
    DAT_010733bc = new GameSetting("sMouseButton8", "Button 8");
}

// @f3 0x00cd9c70 (community match, verified in this file)
extern const char DAT_00db4aa0[];
extern const char DAT_00db50b0[];
extern const char DAT_00db8e9c[];
extern const char DAT_00db8ea0[];
extern const char DAT_00dc0cc8[];
extern const char DAT_00dcbab8[];
extern const char DAT_00dd7ed0[];
extern const char DAT_00dd7ed4[];
extern const char DAT_00de0230[];
extern const char DAT_00de0234[];
extern const char DAT_00de0480[];
extern const char DAT_00de04e8[];
extern const char DAT_00de2f88[];
extern const char DAT_00de2f90[];
extern const char DAT_00df2014[];
extern const char DAT_00df2da4[];
extern const char DAT_00df3740[];
extern const char DAT_00df68bc[];
extern const char DAT_00df8d94[];
extern const char DAT_00df95d0[];
extern const char DAT_00df9fd8[];
extern const char DAT_00df9fe8[];
extern const char DAT_00df9ff0[];
extern const char DAT_00df9ff8[];
extern const char DAT_00dfa008[];
extern const char DAT_00dfa010[];
extern const char DAT_00dfa01c[];
extern const char DAT_00dfa024[];
extern const char DAT_00dfa034[];
extern const char DAT_00dfa03c[];
extern const char DAT_00dfa048[];
extern const char DAT_00dfa054[];
extern const char DAT_00dfa064[];
extern const char DAT_00dfa06c[];
extern const char DAT_00dfa07c[];
extern const char DAT_00dfa080[];
extern const char DAT_00dfa090[];
extern const char DAT_00dfa098[];
extern const char DAT_00dfa0a0[];
extern const char DAT_00dfa0ac[];
extern const char DAT_00dfa0b4[];
extern const char DAT_00dfa0c0[];
extern const char DAT_00dfa0c8[];
extern const char DAT_00dfa0d0[];
extern const char DAT_00dfa0d8[];
extern const char DAT_00dfa0e0[];
extern const char DAT_00dfa0e8[];
extern const char DAT_00dfa0f0[];
extern const char DAT_00dfa0fc[];
extern const char DAT_00dfa108[];
extern const char DAT_00dfa110[];
extern const char DAT_00dfa118[];
extern const char DAT_00dfa120[];
extern const char DAT_00dfa128[];
extern const char DAT_00dfa130[];
extern const char DAT_00dfa13c[];
extern const char DAT_00dfa144[];
extern const char DAT_00dfa150[];
extern const char DAT_00dfa158[];
extern const char DAT_00dfa160[];
extern const char DAT_00dfa168[];
extern const char DAT_00dfa170[];
extern const char DAT_00dfa17c[];
extern const char DAT_00dfa188[];
extern const char DAT_00dfa190[];
extern const char DAT_00dfa19c[];
extern const char DAT_00dfa1a8[];
extern const char DAT_00dfa1b4[];
extern const char DAT_00dfa1bc[];
extern const char DAT_00dfa1cc[];
extern const char DAT_00dfa1d4[];
extern const char DAT_00dfa1e0[];
extern const char DAT_00dfa1e4[];
extern const char DAT_00dfa1f0[];
extern const char DAT_00dfa1f8[];
extern const char DAT_00dfa208[];
extern const char DAT_00dfa210[];
extern const char DAT_00dfa220[];
extern const char DAT_00dfa230[];
extern const char DAT_00dfa238[];
extern const char DAT_00dfa248[];
extern const char DAT_00dfa250[];
extern const char DAT_00dfa258[];
extern const char DAT_00dfa260[];
extern const char DAT_00dfa26c[];
extern const char DAT_00dfa274[];
extern const char DAT_00dfa284[];
extern const char DAT_00dfa290[];
extern const char DAT_00dfa2a0[];
extern const char DAT_00dfa2b0[];
extern const char DAT_00dfa2bc[];
extern const char DAT_00dfa2c4[];
extern const char DAT_00dfa2cc[];
extern const char DAT_00dfa2dc[];
extern const char DAT_00dfa2e0[];
extern const char DAT_00dfa2ec[];
extern const char DAT_00dfa2f0[];
extern const char DAT_00dfa2f8[];
extern const char DAT_00dfa2fc[];
extern const char DAT_00dfa30c[];
extern const char DAT_00dfa314[];
extern const char DAT_00dfa324[];
extern const char DAT_00dfa32c[];
extern const char DAT_00dfa338[];
extern const char DAT_00dfa344[];
extern const char DAT_00dfa34c[];
extern const char DAT_00dfa350[];
extern const char DAT_00dfa358[];
extern const char DAT_00dfa35c[];
extern const char DAT_00dfa364[];
extern const char DAT_00dfa368[];
extern const char DAT_00dfa370[];
extern const char DAT_00dfa374[];
extern const char DAT_00dfa37c[];
extern const char DAT_00dfa380[];
extern const char DAT_00dfa38c[];
extern const char DAT_00dfa390[];
extern const char DAT_00dfa39c[];
extern const char DAT_00dfa3a4[];
extern const char DAT_00dfa3b0[];
extern const char DAT_00dfa3b8[];
extern const char DAT_00dfa3c4[];
extern const char DAT_00dfa3cc[];
extern const char DAT_00dfa3d8[];
extern const char DAT_00dfa3e0[];
extern const char DAT_00dfa3ec[];
extern const char DAT_00dfa3f4[];
extern const char DAT_00dfa3fc[];
extern const char DAT_00dfa404[];
extern const char DAT_00dfa410[];
extern const char DAT_00dfa418[];
extern const char DAT_00dfa424[];
extern const char DAT_00dfa42c[];
extern const char DAT_00dfa438[];
extern const char DAT_00dfa440[];
extern const char DAT_00dfa44c[];
extern const char DAT_00dfa454[];
extern const char DAT_00dfa460[];
extern const char DAT_00dfa468[];
extern const char DAT_00dfa474[];
extern const char DAT_00dfa47c[];
extern const char DAT_00dfa488[];
extern const char DAT_00dfa490[];
extern const char DAT_00dfa49c[];
extern const char DAT_00dfa4a4[];
extern const char DAT_00dfa4b0[];
extern const char DAT_00dfa4b4[];
extern const char DAT_00dfa4bc[];
extern const char DAT_00dfa4c0[];
extern const char DAT_00dfa4c8[];
extern const char DAT_00dfa4cc[];
extern const char DAT_00dfa4d4[];
extern const char DAT_00dfa4d8[];
extern const char DAT_00dfa4e0[];
extern const char DAT_00dfa4e4[];
extern const char DAT_00dfa4ec[];
extern const char DAT_00dfa4f0[];
extern const char DAT_00dfa4f8[];
extern const char DAT_00dfa4fc[];
extern const char DAT_00dfa504[];
extern const char DAT_00dfa508[];
extern const char DAT_00dfa510[];
extern const char DAT_00dfa514[];
extern const char DAT_00dfa51c[];
extern const char DAT_00dfa520[];
extern const char DAT_00dfa528[];
extern const char DAT_00dfa52c[];
extern const char DAT_00dfa538[];
extern const char DAT_00dfa544[];
extern const char DAT_00dfa54c[];
extern const char DAT_00dfa558[];
extern const char DAT_00dfa560[];
extern const char DAT_00dfa56c[];
extern const char DAT_00dfa574[];
extern const char DAT_00dfa580[];
extern const char DAT_00dfa588[];
extern const char DAT_00dfa594[];
extern const char DAT_00dfa598[];
extern const char DAT_00dfa5a4[];
extern const char DAT_00dfa5b0[];
extern const char DAT_00dfa5b4[];
extern const char DAT_00dfa5bc[];
extern const char DAT_00dfa5c0[];
extern const char DAT_00dfa5c8[];
extern const char DAT_00dfa5d0[];
extern const char DAT_00dfa5d4[];
extern const char DAT_00dfa5dc[];
extern const char DAT_00dfa5e0[];
extern const char DAT_00dfa5e8[];
extern const char DAT_00dfa5ec[];
extern const char DAT_00dfa5f4[];
extern const char DAT_00dfa5fc[];
extern const char DAT_00dfa60c[];
extern const char DAT_00dfa618[];
extern const char DAT_00dfa620[];
extern const char DAT_00dfa62c[];
extern const char DAT_00dfa630[];
extern const char DAT_00dfa640[];
extern const char DAT_00dfa644[];
extern const char DAT_00dfa654[];
extern const char DAT_00dfa658[];
extern const char DAT_00dfa660[];
extern const char DAT_00dfa668[];
extern const char DAT_00dfa66c[];
extern const char DAT_00dfa674[];
extern const char DAT_00dfa678[];
extern const char DAT_00dfa680[];
extern const char DAT_00dfa688[];
extern const char DAT_00dfa68c[];
extern const char DAT_00dfa694[];
extern const char DAT_00dfa698[];
extern const char DAT_00dfa6a0[];
extern const char DAT_00dfa6a4[];
extern const char DAT_00dfa6ac[];
extern const char DAT_00dfa6b0[];
extern const char DAT_00dfa6b8[];
extern const char DAT_00dfa6bc[];
extern const char DAT_00dfa6c8[];
extern const char DAT_00dfa6d0[];
extern const char DAT_00dfa6dc[];
extern const char DAT_00dfa6e4[];
extern const char DAT_00dfa6f0[];
extern const char DAT_00dfa6f4[];
extern const char DAT_00dfa700[];
extern const char DAT_00dfa704[];
extern const char DAT_00dfa70c[];
extern const char DAT_00dfa710[];
extern const char DAT_00dfa718[];
extern const char DAT_00dfa71c[];
extern const char DAT_00dfa724[];
extern const char DAT_00dfa728[];
extern const char DAT_00dfa730[];
extern const char DAT_00dfa734[];
extern const char DAT_00dfa73c[];
extern const char DAT_00dfa744[];
extern const char DAT_00dfa748[];
extern const char DAT_00dfa750[];
extern const char DAT_00dfa754[];
extern const char DAT_00dfa75c[];
extern const char DAT_00dfa760[];
extern const char DAT_00dfa768[];
extern const char DAT_00dfa770[];
extern const char DAT_00dfa774[];
extern const char DAT_00dfa77c[];
extern const char DAT_00dfa780[];
extern const char DAT_00dfa788[];
extern const char DAT_00dfa794[];
extern const char DAT_00dfa7a0[];
extern const char DAT_00dfa7a4[];
extern const char DAT_00dfa7b0[];
extern const char DAT_00dfa7b4[];
extern const char DAT_00dfa7bc[];
extern const char DAT_00dfa7c4[];
extern const char DAT_00dfa7c8[];
extern const char DAT_00dfa7d0[];
extern const char DAT_00dfa7d4[];
extern const char DAT_00dfa7dc[];
extern const char DAT_00dfa7e0[];
extern const char DAT_00dfa7e8[];
extern const char DAT_00dfa7ec[];
extern const char DAT_00dfa7f4[];
extern const char DAT_00dfa7f8[];
extern const char DAT_00dfa800[];
extern const char DAT_00dfa804[];
extern const char DAT_00dfa80c[];
extern const char DAT_00dfa810[];
extern const char DAT_00dfa818[];
extern const char DAT_00dfa81c[];
extern const char DAT_00dfa824[];
extern const char DAT_00dfa828[];
extern const char DAT_00dfa830[];
extern FUN_00403100* DAT_01073524;
extern FUN_00403100* DAT_01073528;
extern FUN_00403100* DAT_0107352c;
extern FUN_00403100* DAT_01073530;
extern FUN_00403100* DAT_01073534;
extern FUN_00403100* DAT_01073538;
extern FUN_00403100* DAT_0107353c;
extern FUN_00403100* DAT_01073540;
extern FUN_00403100* DAT_01073544;
extern FUN_00403100* DAT_01073548;
extern FUN_00403100* DAT_0107354c;
extern FUN_00403100* DAT_01073550;
extern FUN_00403100* DAT_01073554;
extern FUN_00403100* DAT_01073558;
extern FUN_00403100* DAT_0107355c;
extern FUN_00403100* DAT_01073560;
extern FUN_00403100* DAT_01073564;
extern FUN_00403100* DAT_01073568;
extern FUN_00403100* DAT_0107356c;
extern FUN_00403100* DAT_01073570;
extern FUN_00403100* DAT_01073574;
extern FUN_00403100* DAT_01073578;
extern FUN_00403100* DAT_0107357c;
extern FUN_00403100* DAT_01073580;
extern FUN_00403100* DAT_01073584;
extern FUN_00403100* DAT_01073588;
extern FUN_00403100* DAT_0107358c;
extern FUN_00403100* DAT_01073590;
extern FUN_00403100* DAT_01073594;
extern FUN_00403100* DAT_01073598;
extern FUN_00403100* DAT_0107359c;
extern FUN_00403100* DAT_010735a0;
extern FUN_00403100* DAT_010735a4;
extern FUN_00403100* DAT_010735a8;
extern FUN_00403100* DAT_010735ac;
extern FUN_00403100* DAT_010735b0;
extern FUN_00403100* DAT_010735b4;
extern FUN_00403100* DAT_010735b8;
extern FUN_00403100* DAT_010735bc;
extern FUN_00403100* DAT_010735c0;
extern FUN_00403100* DAT_010735c4;
extern FUN_00403100* DAT_010735c8;
extern FUN_00403100* DAT_010735cc;
extern FUN_00403100* DAT_010735d0;
extern FUN_00403100* DAT_010735d4;
extern FUN_00403100* DAT_010735d8;
extern FUN_00403100* DAT_010735dc;
extern FUN_00403100* DAT_010735e0;
extern FUN_00403100* DAT_010735e4;
extern FUN_00403100* DAT_010735e8;
extern FUN_00403100* DAT_010735ec;
extern FUN_00403100* DAT_010735f0;
extern FUN_00403100* DAT_010735f4;
extern FUN_00403100* DAT_010735f8;
extern FUN_00403100* DAT_010735fc;
extern FUN_00403100* DAT_01073600;
extern FUN_00403100* DAT_01073604;
extern FUN_00403100* DAT_01073608;
extern FUN_00403100* DAT_0107360c;
extern FUN_00403100* DAT_01073610;
extern FUN_00403100* DAT_01073614;
extern FUN_00403100* DAT_01073618;
extern FUN_00403100* DAT_0107361c;
extern FUN_00403100* DAT_01073620;
extern FUN_00403100* DAT_01073624;
extern FUN_00403100* DAT_01073628;
extern FUN_00403100* DAT_0107362c;
extern FUN_00403100* DAT_01073630;
extern FUN_00403100* DAT_01073634;
extern FUN_00403100* DAT_01073638;
extern FUN_00403100* DAT_0107363c;
extern FUN_00403100* DAT_01073640;
extern FUN_00403100* DAT_01073644;
extern FUN_00403100* DAT_01073648;
extern FUN_00403100* DAT_0107364c;
extern FUN_00403100* DAT_01073650;
extern FUN_00403100* DAT_01073654;
extern FUN_00403100* DAT_01073658;
extern FUN_00403100* DAT_0107365c;
extern FUN_00403100* DAT_01073660;
extern FUN_00403100* DAT_01073664;
extern FUN_00403100* DAT_01073668;
extern FUN_00403100* DAT_0107366c;
extern FUN_00403100* DAT_01073670;
extern FUN_00403100* DAT_01073674;
extern FUN_00403100* DAT_01073678;
extern FUN_00403100* DAT_0107367c;
extern FUN_00403100* DAT_01073680;
extern FUN_00403100* DAT_01073684;
extern FUN_00403100* DAT_01073688;
extern FUN_00403100* DAT_0107368c;
extern FUN_00403100* DAT_01073690;
extern FUN_00403100* DAT_01073694;
extern FUN_00403100* DAT_01073698;
extern FUN_00403100* DAT_0107369c;
extern FUN_00403100* DAT_010736a0;
extern FUN_00403100* DAT_010736a4;
extern FUN_00403100* DAT_010736a8;
extern FUN_00403100* DAT_010736ac;
extern FUN_00403100* DAT_010736b0;
extern FUN_00403100* DAT_010736b4;
extern FUN_00403100* DAT_010736b8;
extern FUN_00403100* DAT_010736bc;
extern FUN_00403100* DAT_010736c0;
extern FUN_00403100* DAT_010736c4;
extern FUN_00403100* DAT_010736c8;
extern FUN_00403100* DAT_010736cc;
extern FUN_00403100* DAT_010736d0;
extern FUN_00403100* DAT_010736d4;
extern FUN_00403100* DAT_010736d8;
extern FUN_00403100* DAT_010736dc;
extern FUN_00403100* DAT_010736e0;
extern FUN_00403100* DAT_010736e4;
extern FUN_00403100* DAT_010736e8;
extern FUN_00403100* DAT_010736ec;
extern FUN_00403100* DAT_010736f0;
extern FUN_00403100* DAT_010736f4;
extern FUN_00403100* DAT_010736f8;
extern FUN_00403100* DAT_010736fc;
extern FUN_00403100* DAT_01073700;
extern FUN_00403100* DAT_01073704;
extern FUN_00403100* DAT_01073708;
extern FUN_00403100* DAT_0107370c;
extern FUN_00403100* DAT_01073710;
extern FUN_00403100* DAT_01073714;
extern FUN_00403100* DAT_01073718;
extern FUN_00403100* DAT_0107371c;
extern FUN_00403100* DAT_01073720;
extern FUN_00403100* DAT_01073724;
extern FUN_00403100* DAT_01073728;
extern FUN_00403100* DAT_0107372c;
extern FUN_00403100* DAT_01073730;
extern FUN_00403100* DAT_01073734;
extern FUN_00403100* DAT_01073738;
extern FUN_00403100* DAT_0107373c;
extern FUN_00403100* DAT_01073740;
extern FUN_00403100* DAT_01073744;
extern FUN_00403100* DAT_01073748;
extern FUN_00403100* DAT_0107374c;
extern FUN_00403100* DAT_01073750;
extern FUN_00403100* DAT_01073754;
extern FUN_00403100* DAT_01073758;
extern FUN_00403100* DAT_0107375c;
extern FUN_00403100* DAT_01073760;
extern FUN_00403100* DAT_01073764;
extern FUN_00403100* DAT_01073768;
extern FUN_00403100* DAT_0107376c;
extern FUN_00403100* DAT_01073770;
extern FUN_00403100* DAT_01073774;
extern FUN_00403100* DAT_01073778;
extern FUN_00403100* DAT_0107377c;
extern FUN_00403100* DAT_01073780;
extern FUN_00403100* DAT_01073784;
extern FUN_00403100* DAT_01073788;
extern FUN_00403100* DAT_0107378c;
extern FUN_00403100* DAT_01073790;
extern FUN_00403100* DAT_01073794;
extern FUN_00403100* DAT_01073798;
extern FUN_00403100* DAT_0107379c;
extern FUN_00403100* DAT_010737a0;
extern FUN_00403100* DAT_010737a4;
extern FUN_00403100* DAT_010737a8;
extern FUN_00403100* DAT_010737ac;
extern FUN_00403100* DAT_010737b0;
extern FUN_00403100* DAT_010737b4;
extern FUN_00403100* DAT_010737b8;
extern FUN_00403100* DAT_010737bc;
extern FUN_00403100* DAT_010737c0;
extern FUN_00403100* DAT_010737c4;
extern FUN_00403100* DAT_010737c8;
extern FUN_00403100* DAT_010737cc;
extern FUN_00403100* DAT_010737d0;
extern FUN_00403100* DAT_010737d4;
extern FUN_00403100* DAT_010737d8;
extern FUN_00403100* DAT_010737dc;
extern FUN_00403100* DAT_010737e0;
extern FUN_00403100* DAT_010737e4;
extern FUN_00403100* DAT_010737e8;
extern FUN_00403100* DAT_010737ec;
extern FUN_00403100* DAT_010737f0;
extern FUN_00403100* DAT_010737f4;
extern FUN_00403100* DAT_010737f8;
extern FUN_00403100* DAT_010737fc;
extern FUN_00403100* DAT_01073800;
extern FUN_00403100* DAT_01073804;
extern FUN_00403100* DAT_01073808;
extern FUN_00403100* DAT_0107380c;
extern FUN_00403100* DAT_01073810;
extern FUN_00403100* DAT_01073814;
extern FUN_00403100* DAT_01073818;
extern FUN_00403100* DAT_0107381c;
extern FUN_00403100* DAT_01073820;
extern FUN_00403100* DAT_01073824;
extern FUN_00403100* DAT_01073828;
extern FUN_00403100* DAT_0107382c;
extern FUN_00403100* DAT_01073830;
extern FUN_00403100* DAT_01073834;
extern FUN_00403100* DAT_01073838;
extern FUN_00403100* DAT_0107383c;
extern FUN_00403100* DAT_01073840;
extern FUN_00403100* DAT_01073844;
extern FUN_00403100* DAT_01073848;
extern FUN_00403100* DAT_0107384c;
extern FUN_00403100* DAT_01073850;
extern FUN_00403100* DAT_01073854;
extern FUN_00403100* DAT_01073858;
extern FUN_00403100* DAT_0107385c;
extern FUN_00403100* DAT_01073860;
extern FUN_00403100* DAT_01073864;
extern FUN_00403100* DAT_01073868;
extern FUN_00403100* DAT_0107386c;
extern FUN_00403100* DAT_01073870;
extern FUN_00403100* DAT_01073874;
extern FUN_00403100* DAT_01073878;
extern FUN_00403100* DAT_0107387c;
extern FUN_00403100* DAT_01073880;
extern FUN_00403100* DAT_01073884;
extern FUN_00403100* DAT_01073888;
extern FUN_00403100* DAT_0107388c;
extern FUN_00403100* DAT_01073890;
extern FUN_00403100* DAT_01073894;
extern FUN_00403100* DAT_01073898;
extern FUN_00403100* DAT_0107389c;
extern FUN_00403100* DAT_010738a0;
extern FUN_00403100* DAT_010738a4;
extern FUN_00403100* DAT_010738a8;
extern FUN_00403100* DAT_010738ac;
extern FUN_00403100* DAT_010738b0;
extern FUN_00403100* DAT_010738b4;
extern FUN_00403100* DAT_010738b8;
extern FUN_00403100* DAT_010738bc;
extern FUN_00403100* DAT_010738c0;
extern FUN_00403100* DAT_010738c4;
extern FUN_00403100* DAT_010738c8;
extern FUN_00403100* DAT_010738cc;
extern FUN_00403100* DAT_010738d0;
extern FUN_00403100* DAT_010738d4;
namespace f3m_00cd9c70 {
class SettingsHeap { public: void* FUN_0086b930(unsigned); };


// pdb: `dynamic initializer for 'psKeyboard'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void __cdecl FUN_00cd9c70()
{
    DAT_01073524 = new FUN_00403100(DAT_00dfa828, DAT_00dfa830);
    DAT_01073528 = new FUN_00403100(DAT_00dfa81c, DAT_00dfa824);
    DAT_0107352c = new FUN_00403100(DAT_00dfa810, DAT_00dfa818);
    DAT_01073530 = new FUN_00403100(DAT_00dfa804, DAT_00dfa80c);
    DAT_01073534 = new FUN_00403100(DAT_00dfa7f8, DAT_00dfa800);
    DAT_01073538 = new FUN_00403100(DAT_00dfa7ec, DAT_00dfa7f4);
    DAT_0107353c = new FUN_00403100(DAT_00dfa7e0, DAT_00dfa7e8);
    DAT_01073540 = new FUN_00403100(DAT_00dfa7d4, DAT_00dfa7dc);
    DAT_01073544 = new FUN_00403100(DAT_00dfa7c8, DAT_00dfa7d0);
    DAT_01073548 = new FUN_00403100(DAT_00dfa7bc, DAT_00dfa7c4);
    DAT_0107354c = new FUN_00403100(DAT_00dfa7b4, DAT_00dc0cc8);
    DAT_01073550 = new FUN_00403100(DAT_00dfa7a4, DAT_00dfa7b0);
    DAT_01073554 = new FUN_00403100(DAT_00dfa794, DAT_00dfa7a0);
    DAT_01073558 = new FUN_00403100(DAT_00dfa780, DAT_00dfa788);
    DAT_0107355c = new FUN_00403100(DAT_00dfa774, DAT_00dfa77c);
    DAT_01073560 = new FUN_00403100(DAT_00dfa768, DAT_00dfa770);
    DAT_01073564 = new FUN_00403100(DAT_00dfa760, DAT_00dcbab8);
    DAT_01073568 = new FUN_00403100(DAT_00dfa754, DAT_00dfa75c);
    DAT_0107356c = new FUN_00403100(DAT_00dfa748, DAT_00dfa750);
    DAT_01073570 = new FUN_00403100(DAT_00dfa73c, DAT_00dfa744);
    DAT_01073574 = new FUN_00403100(DAT_00dfa734, DAT_00db8ea0);
    DAT_01073578 = new FUN_00403100(DAT_00dfa728, DAT_00dfa730);
    DAT_0107357c = new FUN_00403100(DAT_00dfa71c, DAT_00dfa724);
    DAT_01073580 = new FUN_00403100(DAT_00dfa710, DAT_00dfa718);
    DAT_01073584 = new FUN_00403100(DAT_00dfa704, DAT_00dfa70c);
    DAT_01073588 = new FUN_00403100(DAT_00dfa6f4, DAT_00dfa700);
    DAT_0107358c = new FUN_00403100(DAT_00dfa6e4, DAT_00dfa6f0);
    DAT_01073590 = new FUN_00403100(DAT_00dfa6d0, DAT_00dfa6dc);
    DAT_01073594 = new FUN_00403100(DAT_00dfa6bc, DAT_00dfa6c8);
    DAT_01073598 = new FUN_00403100(DAT_00dfa6b0, DAT_00dfa6b8);
    DAT_0107359c = new FUN_00403100(DAT_00dfa6a4, DAT_00dfa6ac);
    DAT_010735a0 = new FUN_00403100(DAT_00dfa698, DAT_00dfa6a0);
    DAT_010735a4 = new FUN_00403100(DAT_00dfa68c, DAT_00dfa694);
    DAT_010735a8 = new FUN_00403100(DAT_00dfa680, DAT_00dfa688);
    DAT_010735ac = new FUN_00403100(DAT_00dfa678, DAT_00dd7ed0);
    DAT_010735b0 = new FUN_00403100(DAT_00dfa66c, DAT_00dfa674);
    DAT_010735b4 = new FUN_00403100(DAT_00dfa660, DAT_00dfa668);
    DAT_010735b8 = new FUN_00403100(DAT_00dfa658, DAT_00dd7ed4);
    DAT_010735bc = new FUN_00403100(DAT_00dfa644, DAT_00dfa654);
    DAT_010735c0 = new FUN_00403100(DAT_00dfa630, DAT_00dfa640);
    DAT_010735c4 = new FUN_00403100(DAT_00dfa620, DAT_00dfa62c);
    DAT_010735c8 = new FUN_00403100(DAT_00dfa60c, DAT_00dfa618);
    DAT_010735cc = new FUN_00403100(DAT_00dfa5fc, DAT_00db4aa0);
    DAT_010735d0 = new FUN_00403100(DAT_00dfa5f4, DAT_00de0230);
    DAT_010735d4 = new FUN_00403100(DAT_00dfa5ec, DAT_00de0234);
    DAT_010735d8 = new FUN_00403100(DAT_00dfa5e0, DAT_00dfa5e8);
    DAT_010735dc = new FUN_00403100(DAT_00dfa5d4, DAT_00dfa5dc);
    DAT_010735e0 = new FUN_00403100(DAT_00dfa5c8, DAT_00dfa5d0);
    DAT_010735e4 = new FUN_00403100(DAT_00dfa5c0, DAT_00db8e9c);
    DAT_010735e8 = new FUN_00403100(DAT_00dfa5b4, DAT_00dfa5bc);
    DAT_010735ec = new FUN_00403100(DAT_00dfa5a4, DAT_00dfa5b0);
    DAT_010735f0 = new FUN_00403100(DAT_00dfa598, DAT_00de0480);
    DAT_010735f4 = new FUN_00403100(DAT_00dfa588, DAT_00dfa594);
    DAT_010735f8 = new FUN_00403100(DAT_00dfa574, DAT_00dfa580);
    DAT_010735fc = new FUN_00403100(DAT_00dfa560, DAT_00dfa56c);
    DAT_01073600 = new FUN_00403100(DAT_00dfa54c, DAT_00dfa558);
    DAT_01073604 = new FUN_00403100(DAT_00dfa538, DAT_00dfa544);
    DAT_01073608 = new FUN_00403100(DAT_00dfa52c, DAT_00df3740);
    DAT_0107360c = new FUN_00403100(DAT_00dfa520, DAT_00dfa528);
    DAT_01073610 = new FUN_00403100(DAT_00dfa514, DAT_00dfa51c);
    DAT_01073614 = new FUN_00403100(DAT_00dfa508, DAT_00dfa510);
    DAT_01073618 = new FUN_00403100(DAT_00dfa4fc, DAT_00dfa504);
    DAT_0107361c = new FUN_00403100(DAT_00dfa4f0, DAT_00dfa4f8);
    DAT_01073620 = new FUN_00403100(DAT_00dfa4e4, DAT_00dfa4ec);
    DAT_01073624 = new FUN_00403100(DAT_00dfa4d8, DAT_00dfa4e0);
    DAT_01073628 = new FUN_00403100(DAT_00dfa4cc, DAT_00dfa4d4);
    DAT_0107362c = new FUN_00403100(DAT_00dfa4c0, DAT_00dfa4c8);
    DAT_01073630 = new FUN_00403100(DAT_00dfa4b4, DAT_00dfa4bc);
    DAT_01073634 = new FUN_00403100(DAT_00dfa4a4, DAT_00dfa4b0);
    DAT_01073638 = new FUN_00403100(DAT_00dfa490, DAT_00dfa49c);
    DAT_0107363c = new FUN_00403100(DAT_00dfa47c, DAT_00dfa488);
    DAT_01073640 = new FUN_00403100(DAT_00dfa468, DAT_00dfa474);
    DAT_01073644 = new FUN_00403100(DAT_00dfa454, DAT_00dfa460);
    DAT_01073648 = new FUN_00403100(DAT_00dfa440, DAT_00dfa44c);
    DAT_0107364c = new FUN_00403100(DAT_00dfa42c, DAT_00dfa438);
    DAT_01073650 = new FUN_00403100(DAT_00dfa418, DAT_00dfa424);
    DAT_01073654 = new FUN_00403100(DAT_00dfa404, DAT_00dfa410);
    DAT_01073658 = new FUN_00403100(DAT_00dfa3f4, DAT_00dfa3fc);
    DAT_0107365c = new FUN_00403100(DAT_00dfa3e0, DAT_00dfa3ec);
    DAT_01073660 = new FUN_00403100(DAT_00dfa3cc, DAT_00dfa3d8);
    DAT_01073664 = new FUN_00403100(DAT_00dfa3b8, DAT_00dfa3c4);
    DAT_01073668 = new FUN_00403100(DAT_00dfa3a4, DAT_00dfa3b0);
    DAT_0107366c = new FUN_00403100(DAT_00dfa390, DAT_00dfa39c);
    DAT_01073670 = 0;
    DAT_01073674 = 0;
    DAT_01073678 = new FUN_00403100(DAT_00dfa380, DAT_00dfa38c);
    DAT_0107367c = new FUN_00403100(DAT_00dfa374, DAT_00dfa37c);
    DAT_01073680 = new FUN_00403100(DAT_00dfa368, DAT_00dfa370);
    DAT_01073684 = 0;
    DAT_01073688 = 0;
    DAT_0107368c = 0;
    DAT_01073690 = 0;
    DAT_01073694 = 0;
    DAT_01073698 = 0;
    DAT_0107369c = 0;
    DAT_010736a0 = 0;
    DAT_010736a4 = 0;
    DAT_010736a8 = 0;
    DAT_010736ac = 0;
    DAT_010736b0 = new FUN_00403100(DAT_00dfa35c, DAT_00dfa364);
    DAT_010736b4 = new FUN_00403100(DAT_00dfa350, DAT_00dfa358);
    DAT_010736b8 = new FUN_00403100(DAT_00dfa344, DAT_00dfa34c);
    DAT_010736bc = 0;
    DAT_010736c0 = 0;
    DAT_010736c4 = 0;
    DAT_010736c8 = 0;
    DAT_010736cc = 0;
    DAT_010736d0 = 0;
    DAT_010736d4 = 0;
    DAT_010736d8 = 0;
    DAT_010736dc = 0;
    DAT_010736e0 = 0;
    DAT_010736e4 = 0;
    DAT_010736e8 = 0;
    DAT_010736ec = new FUN_00403100(DAT_00dfa338, DAT_00dfa594);
    DAT_010736f0 = 0;
    DAT_010736f4 = 0;
    DAT_010736f8 = 0;
    DAT_010736fc = 0;
    DAT_01073700 = 0;
    DAT_01073704 = 0;
    DAT_01073708 = 0;
    DAT_0107370c = 0;
    DAT_01073710 = 0;
    DAT_01073714 = 0;
    DAT_01073718 = new FUN_00403100(DAT_00dfa32c, DAT_00dfa39c);
    DAT_0107371c = 0;
    DAT_01073720 = 0;
    DAT_01073724 = 0;
    DAT_01073728 = 0;
    DAT_0107372c = 0;
    DAT_01073730 = 0;
    DAT_01073734 = 0;
    DAT_01073738 = 0;
    DAT_0107373c = 0;
    DAT_01073740 = 0;
    DAT_01073744 = 0;
    DAT_01073748 = 0;
    DAT_0107374c = 0;
    DAT_01073750 = 0;
    DAT_01073754 = new FUN_00403100(DAT_00dfa314, DAT_00dfa324);
    DAT_01073758 = 0;
    DAT_0107375c = 0;
    DAT_01073760 = new FUN_00403100(DAT_00dfa2fc, DAT_00dfa30c);
    DAT_01073764 = new FUN_00403100(DAT_00dfa2f0, DAT_00dfa2f8);
    DAT_01073768 = new FUN_00403100(DAT_00dfa2e0, DAT_00dfa2ec);
    DAT_0107376c = new FUN_00403100(DAT_00dfa2cc, DAT_00dfa2dc);
    DAT_01073770 = 0;
    DAT_01073774 = new FUN_00403100(DAT_00dfa2bc, DAT_00dfa2c4);
    DAT_01073778 = 0;
    DAT_0107377c = new FUN_00403100(DAT_00dfa2a0, DAT_00dfa2b0);
    DAT_01073780 = 0;
    DAT_01073784 = new FUN_00403100(DAT_00dfa290, DAT_00df2014);
    DAT_01073788 = 0;
    DAT_0107378c = 0;
    DAT_01073790 = new FUN_00403100(DAT_00dfa274, DAT_00dfa284);
    DAT_01073794 = new FUN_00403100(DAT_00dfa260, DAT_00dfa26c);
    DAT_01073798 = 0;
    DAT_0107379c = 0;
    DAT_010737a0 = new FUN_00403100(DAT_00dfa250, DAT_00dfa258);
    DAT_010737a4 = new FUN_00403100(DAT_00dfa238, DAT_00dfa248);
    DAT_010737a8 = new FUN_00403100(DAT_00dfa220, DAT_00dfa230);
    DAT_010737ac = 0;
    DAT_010737b0 = new FUN_00403100(DAT_00dfa210, DAT_00dfa2c4);
    DAT_010737b4 = 0;
    DAT_010737b8 = 0;
    DAT_010737bc = 0;
    DAT_010737c0 = 0;
    DAT_010737c4 = 0;
    DAT_010737c8 = 0;
    DAT_010737cc = 0;
    DAT_010737d0 = 0;
    DAT_010737d4 = 0;
    DAT_010737d8 = new FUN_00403100(DAT_00dfa1f8, DAT_00dfa208);
    DAT_010737dc = 0;
    DAT_010737e0 = new FUN_00403100(DAT_00dfa1e4, DAT_00dfa1f0);
    DAT_010737e4 = 0;
    DAT_010737e8 = new FUN_00403100(DAT_00dfa1d4, DAT_00dfa1e0);
    DAT_010737ec = new FUN_00403100(DAT_00dfa1bc, DAT_00dfa1cc);
    DAT_010737f0 = 0;
    DAT_010737f4 = new FUN_00403100(DAT_00dfa1a8, DAT_00dfa1b4);
    DAT_010737f8 = 0;
    DAT_010737fc = new FUN_00403100(DAT_00dfa190, DAT_00dfa19c);
    DAT_01073800 = new FUN_00403100(DAT_00dfa17c, DAT_00dfa188);
    DAT_01073804 = 0;
    DAT_01073808 = 0;
    DAT_0107380c = 0;
    DAT_01073810 = 0;
    DAT_01073814 = 0;
    DAT_01073818 = 0;
    DAT_0107381c = 0;
    DAT_01073820 = 0;
    DAT_01073824 = 0;
    DAT_01073828 = 0;
    DAT_0107382c = 0;
    DAT_01073830 = 0;
    DAT_01073834 = new FUN_00403100(DAT_00dfa170, DAT_00df68bc);
    DAT_01073838 = 0;
    DAT_0107383c = new FUN_00403100(DAT_00dfa160, DAT_00dfa168);
    DAT_01073840 = new FUN_00403100(DAT_00dfa158, DAT_00dbe0d4);
    DAT_01073844 = new FUN_00403100(DAT_00dfa144, DAT_00dfa150);
    DAT_01073848 = 0;
    DAT_0107384c = new FUN_00403100(DAT_00dfa13c, DAT_00de2f90);
    DAT_01073850 = 0;
    DAT_01073854 = new FUN_00403100(DAT_00dfa130, DAT_00de2f88);
    DAT_01073858 = 0;
    DAT_0107385c = new FUN_00403100(DAT_00dfa128, DAT_00de04e8);
    DAT_01073860 = new FUN_00403100(DAT_00dfa120, DAT_00dbe0d8);
    DAT_01073864 = new FUN_00403100(DAT_00dfa110, DAT_00dfa118);
    DAT_01073868 = new FUN_00403100(DAT_00dfa0fc, DAT_00dfa108);
    DAT_0107386c = new FUN_00403100(DAT_00dfa0f0, DAT_00df8d94);
    DAT_01073870 = 0;
    DAT_01073874 = 0;
    DAT_01073878 = 0;
    DAT_0107387c = 0;
    DAT_01073880 = 0;
    DAT_01073884 = 0;
    DAT_01073888 = 0;
    DAT_0107388c = new FUN_00403100(DAT_00dfa0e0, DAT_00dfa0e8);
    DAT_01073890 = new FUN_00403100(DAT_00dfa0d0, DAT_00dfa0d8);
    DAT_01073894 = new FUN_00403100(DAT_00dfa0c0, DAT_00dfa0c8);
    DAT_01073898 = new FUN_00403100(DAT_00dfa0b4, DAT_00db50b0);
    DAT_0107389c = new FUN_00403100(DAT_00dfa0a0, DAT_00dfa0ac);
    DAT_010738a0 = 0;
    DAT_010738a4 = 0;
    DAT_010738a8 = 0;
    DAT_010738ac = new FUN_00403100(DAT_00dfa090, DAT_00dfa098);
    DAT_010738b0 = 0;
    DAT_010738b4 = new FUN_00403100(DAT_00dfa080, DAT_00df95d0);
    DAT_010738b8 = new FUN_00403100(DAT_00dfa06c, DAT_00dfa07c);
    DAT_010738bc = new FUN_00403100(DAT_00dfa054, DAT_00dfa064);
    DAT_010738c0 = new FUN_00403100(DAT_00dfa03c, DAT_00dfa048);
    DAT_010738c4 = new FUN_00403100(DAT_00dfa024, DAT_00dfa034);
    DAT_010738c8 = new FUN_00403100(DAT_00dfa010, DAT_00dfa01c);
    DAT_010738cc = new FUN_00403100(DAT_00df9ff8, DAT_00dfa008);
    DAT_010738d0 = new FUN_00403100(DAT_00df9fe8, DAT_00df9ff0);
    DAT_010738d4 = new FUN_00403100(DAT_00df9fd8, DAT_00df2da4);
}
}   // namespace f3m_00cd9c70

// @f3 0x00cdd120 (community match, verified in this file)
extern char DAT_00dfb134[];
extern char DAT_00dfb118[];
extern char DAT_00dfb104[];
extern char DAT_00dfb0ec[];
extern char DAT_00dfb0d8[];
extern char DAT_00dfb0c0[];
extern char DAT_00dfb0b8[];
extern char DAT_00dfb09c[];
extern char DAT_00dfb08c[];
extern char DAT_00dfb06c[];
extern char DAT_00dfb064[];
extern char DAT_00dfb04c[];
extern char DAT_00dfb040[];
extern char DAT_00dfb024[];
extern char DAT_00dfb014[];
extern char DAT_00dfaff4[];
extern char DAT_00dfafe4[];
extern char DAT_00dfafc8[];
extern char DAT_00dfafbc[];
extern char DAT_00dfafa0[];
extern char DAT_00dfaf98[];
extern char DAT_00dfaf7c[];
extern char DAT_00dbb564[];
extern char DAT_00dfaf64[];
extern FUN_00403100* DAT_01073368;
extern FUN_00403100* DAT_0107336c;
extern FUN_00403100* DAT_01073370;
extern FUN_00403100* DAT_01073374;
extern FUN_00403100* DAT_01073378;
extern FUN_00403100* DAT_0107337c;
extern FUN_00403100* DAT_01073380;
extern FUN_00403100* DAT_01073384;
extern FUN_00403100* DAT_01073388;
extern FUN_00403100* DAT_0107338c;
extern FUN_00403100* DAT_01073390;
extern FUN_00403100* DAT_01073394;
extern int DAT_01073398;
namespace f3m_00cdd120 {
// pdb: `dynamic initializer for 'psWeaponTypes'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void FUN_00cdd120()
{
    DAT_01073368 = new FUN_00403100(DAT_00dfb118, DAT_00dfb134);
    DAT_0107336c = new FUN_00403100(DAT_00dfb0ec, DAT_00dfb104);
    DAT_01073370 = new FUN_00403100(DAT_00dfb0c0, DAT_00dfb0d8);
    DAT_01073374 = new FUN_00403100(DAT_00dfb09c, DAT_00dfb0b8);
    DAT_01073378 = new FUN_00403100(DAT_00dfb06c, DAT_00dfb08c);
    DAT_0107337c = new FUN_00403100(DAT_00dfb04c, DAT_00dfb064);
    DAT_01073380 = new FUN_00403100(DAT_00dfb024, DAT_00dfb040);
    DAT_01073384 = new FUN_00403100(DAT_00dfaff4, DAT_00dfb014);
    DAT_01073388 = new FUN_00403100(DAT_00dfafc8, DAT_00dfafe4);
    DAT_0107338c = new FUN_00403100(DAT_00dfafa0, DAT_00dfafbc);
    DAT_01073390 = new FUN_00403100(DAT_00dfaf7c, DAT_00dfaf98);
    DAT_01073394 = new FUN_00403100(DAT_00dfaf64, DAT_00dbb564);
    DAT_01073398 = 0;
}
}   // namespace f3m_00cdd120

// @f3 0x00cd9b30 (community match, verified in this file)
extern GameSetting* DAT_01073954;
extern GameSetting* DAT_01073958;
extern GameSetting* DAT_0107395c;
extern GameSetting* DAT_01073960;
namespace f3m_00cd9b30 {

// pdb: `dynamic initializer for 'psDevice'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void __cdecl FUN_00cd9b30()
{
    DAT_01073954 = new GameSetting("sDeviceKeyboard", "Keyboard");
    DAT_01073958 = new GameSetting("sDeviceMouse", "Mouse");
    DAT_0107395c = new GameSetting("sDeviceJoystick", "Joystick");
    DAT_01073960 = new GameSetting("sDeviceGamepad", "Xbox 360 Controller");
}
}   // namespace f3m_00cd9b30

// @f3 0x00cdd420 (community match, verified in this file)
namespace f3m_00cdd420 {


class SettingsHeap { public: void* FUN_0086b930(unsigned int); };
extern SettingsHeap DAT_01090a78;

class FUN_00403100 {
public:
    void* unk00;
    const char* value04;
    const char* name08;
    FUN_00403100(const char* name, const char* value);
    static void* operator new(size_t bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

extern FUN_00403100* DAT_010733c4;
extern FUN_00403100* DAT_010733c8;
extern FUN_00403100* DAT_010733cc;
extern FUN_00403100* DAT_010733d0;
extern FUN_00403100* DAT_010733d4;
extern FUN_00403100* DAT_010733d8;
extern FUN_00403100* DAT_010733dc;
extern FUN_00403100* DAT_010733e0;
extern FUN_00403100* DAT_010733e4;
extern FUN_00403100* DAT_010733e8;
extern FUN_00403100* DAT_010733ec;
extern FUN_00403100* DAT_010733f0;
extern FUN_00403100* DAT_010733f4;
extern FUN_00403100* DAT_010733f8;
extern FUN_00403100* DAT_010733fc;
extern FUN_00403100* DAT_01073400;
extern FUN_00403100* DAT_01073404;
extern FUN_00403100* DAT_01073408;
extern FUN_00403100* DAT_0107340c;

// pdb: `dynamic initializer for 'psTargetTypes'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void FUN_00cdd420()
{
    DAT_010733c4 = new FUN_00403100("sTargetTypeTake", "Take");
    DAT_010733c8 = new FUN_00403100("sTargetTypeOpen", "Open");
    DAT_010733cc = new FUN_00403100("sTargetTypeSit", "Sit");
    DAT_010733d0 = new FUN_00403100("sTargetTypeActivate", "Activate");
    DAT_010733d4 = new FUN_00403100("sTargetTypeSleep", "Sleep");
    DAT_010733d8 = new FUN_00403100("sTargetTypeRead", "Read");
    DAT_010733dc = new FUN_00403100("sTargetTypeTalk", "Talk");
    DAT_010733e0 = new FUN_00403100("sTargetTypeOpenDoor", "Open");
    DAT_010733e4 = new FUN_00403100("sTargetTypeHorse", "Ride");
    DAT_010733e8 = new FUN_00403100("sTargetTypeCrown", "Talk");
    DAT_010733ec = new FUN_00403100("sTargetTypeVampire", "Feed/Talk");
    DAT_010733f0 = new FUN_00403100("sTargetTypeEquip", "Equip");
    DAT_010733f4 = new FUN_00403100("sTargetTypeUnequip", "Unequip");
    DAT_010733f8 = new FUN_00403100("sTargetTypeDrink", "Drink");
    DAT_010733fc = new FUN_00403100("sTargetTypeEat", "Eat");
    DAT_01073400 = new FUN_00403100("sTargetTypeRecharge", "Recharge");
    DAT_01073404 = new FUN_00403100("sTargetTypeBrew", "Brew");
    DAT_01073408 = new FUN_00403100("sTargetTypeApply", "Apply");
    DAT_0107340c = new FUN_00403100("sTargetTypeRepair", "Repair");
}
}   // namespace f3m_00cdd420

// @f3 0x00cd94a0 (community match, verified in this file)
namespace f3m_00cd94a0 {


class SettingsHeap { public: void* FUN_0086b930(unsigned int); };
extern SettingsHeap DAT_01090a78;

class FUN_00403100 {
public:
    void* unk00;
    const char* value04;
    const char* name08;
    FUN_00403100(const char* name, const char* value);
    static void* operator new(size_t bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

extern FUN_00403100* DAT_01073430;
extern FUN_00403100* DAT_01073434;
extern FUN_00403100* DAT_01073438;
extern FUN_00403100* DAT_0107343c;
extern FUN_00403100* DAT_01073440;
extern FUN_00403100* DAT_01073444;
extern FUN_00403100* DAT_01073448;
extern FUN_00403100* DAT_0107344c;
extern FUN_00403100* DAT_01073450;
extern FUN_00403100* DAT_01073454;
extern FUN_00403100* DAT_01073458;
extern FUN_00403100* DAT_0107345c;
extern FUN_00403100* DAT_01073460;
extern FUN_00403100* DAT_01073464;
extern FUN_00403100* DAT_01073468;
extern FUN_00403100* DAT_0107346c;
extern FUN_00403100* DAT_01073470;
extern FUN_00403100* DAT_01073474;
extern FUN_00403100* DAT_01073478;
extern FUN_00403100* DAT_0107347c;
extern FUN_00403100* DAT_01073480;
extern FUN_00403100* DAT_01073484;
extern FUN_00403100* DAT_01073488;
extern FUN_00403100* DAT_0107348c;
extern FUN_00403100* DAT_01073490;
extern FUN_00403100* DAT_01073494;
extern FUN_00403100* DAT_01073498;
extern FUN_00403100* DAT_0107349c;

// pdb: `dynamic initializer for 'psUserActions'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: UserEvents::UserEvents)
void FUN_00cd94a0()
{
    DAT_01073430 = new FUN_00403100("sUActnForward", "Forward");
    DAT_01073434 = new FUN_00403100("sUActnBack", "Back");
    DAT_01073438 = new FUN_00403100("sUActnSldleft", "Strafe Left");
    DAT_0107343c = new FUN_00403100("sUActnSldright", "Strafe Right");
    DAT_01073440 = new FUN_00403100("sUActnUse", "Attack");
    DAT_01073444 = new FUN_00403100("sUActnActivate", "Activate");
    DAT_01073448 = new FUN_00403100("sUActnBlock", "Block");
    DAT_0107344c = new FUN_00403100("sUActnRdyitem", "Ready/Reload");
    DAT_01073450 = new FUN_00403100("sUActnCrouch", "Sneak");
    DAT_01073454 = new FUN_00403100("sUActnRun", "Run");
    DAT_01073458 = new FUN_00403100("sUActnTogglerun", "Always Run");
    DAT_0107345c = new FUN_00403100("sUActnAutomove", "Auto Move");
    DAT_01073460 = new FUN_00403100("sUActnJump", "Jump");
    DAT_01073464 = new FUN_00403100("sUActnTogglepov", "Change View");
    DAT_01073468 = new FUN_00403100("sUActnMenumode", "Pip-Boy");
    DAT_0107346c = new FUN_00403100("sUActnRestmenu", "Wait");
    DAT_01073470 = new FUN_00403100("sUActnVats", "VATS");
    DAT_01073474 = new FUN_00403100("sUActnHotKey1", "Hotkey 1");
    DAT_01073478 = new FUN_00403100("sUActnHotKey2", "Hotkey 2");
    DAT_0107347c = new FUN_00403100("sUActnHotKey3", "Hotkey 3");
    DAT_01073480 = new FUN_00403100("sUActnHotKey4", "Hotkey 4");
    DAT_01073484 = new FUN_00403100("sUActnHotKey5", "Hotkey 5");
    DAT_01073488 = new FUN_00403100("sUActnHotKey6", "Hotkey 6");
    DAT_0107348c = new FUN_00403100("sUActnHotKey7", "Hotkey 7");
    DAT_01073490 = new FUN_00403100("sUActnHotKey8", "Hotkey 8");
    DAT_01073494 = new FUN_00403100("sUActnQuicksave", "Quicksave");
    DAT_01073498 = new FUN_00403100("sUActnQuickload", "Quickload");
    DAT_0107349c = new FUN_00403100("sUActnGrab", "Grab");
}
}   // namespace f3m_00cd94a0

// @f3 0x00cdc2a0 (community match, verified in this file)
namespace f3m_00cdc2a0 {


class SettingsHeap { public: void* FUN_0086b930(unsigned int); };
extern SettingsHeap DAT_01090a78;

class FUN_00403100 {
public:
    void* unk00;
    const char* value04;
    const char* name08;
    FUN_00403100(const char* name, const char* value);
    static void* operator new(size_t bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

extern FUN_00403100* DAT_010734a0;
extern FUN_00403100* DAT_010734a4;
extern FUN_00403100* DAT_010734a8;
extern FUN_00403100* DAT_010734ac;
extern FUN_00403100* DAT_010734b0;
extern FUN_00403100* DAT_010734b4;
extern FUN_00403100* DAT_010734b8;
extern FUN_00403100* DAT_010734bc;
extern FUN_00403100* DAT_010734c0;
extern FUN_00403100* DAT_010734c4;
extern FUN_00403100* DAT_010734c8;
extern FUN_00403100* DAT_010734cc;
extern FUN_00403100* DAT_010734d0;
extern FUN_00403100* DAT_010734d4;
extern FUN_00403100* DAT_010734d8;
extern FUN_00403100* DAT_010734dc;
extern FUN_00403100* DAT_010734e0;
extern FUN_00403100* DAT_010734e4;
extern FUN_00403100* DAT_010734e8;
extern FUN_00403100* DAT_010734ec;
extern FUN_00403100* DAT_010734f0;
extern FUN_00403100* DAT_010734f4;
extern FUN_00403100* DAT_010734f8;
extern FUN_00403100* DAT_010734fc;
extern FUN_00403100* DAT_01073500;
extern FUN_00403100* DAT_01073504;
extern FUN_00403100* DAT_01073508;
extern FUN_00403100* DAT_0107350c;
extern FUN_00403100* DAT_01073510;
extern FUN_00403100* DAT_01073514;
extern FUN_00403100* DAT_01073518;

// pdb: `dynamic initializer for 'psXBoxGamepadText'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void FUN_00cdc2a0()
{
    DAT_010734a0 = new FUN_00403100("sXBDPadY", "D-Pad Up / Down");
    DAT_010734a4 = new FUN_00403100("sXBDPadUp", "D-Pad Up");
    DAT_010734a8 = new FUN_00403100("sXBDPadDown", "D-Pad Down");
    DAT_010734ac = new FUN_00403100("sXBDPadX", "D-Pad Left / Right");
    DAT_010734b0 = new FUN_00403100("sXBDPadRight", "D-Pad Right");
    DAT_010734b4 = new FUN_00403100("sXBDPadLeft", "D-Pad Left");
    DAT_010734b8 = new FUN_00403100("sXBStartBtn", "START");
    DAT_010734bc = new FUN_00403100("sXBBackBtn", "Back");
    DAT_010734c0 = new FUN_00403100("sXBLThumb", "\\general_button_ls.dds\\");
    DAT_010734c4 = new FUN_00403100("sXBRThumb", "\\general_button_rs.dds\\");
    DAT_010734c8 = new FUN_00403100("sXBABtn", "\\general_button_a.dds\\");
    DAT_010734cc = new FUN_00403100("sXBBBtn", "\\general_button_b.dds\\");
    DAT_010734d0 = new FUN_00403100("sXBXBtn", "\\general_button_x.dds\\");
    DAT_010734d4 = new FUN_00403100("sXBYBtn", "\\general_button_y.dds\\");
    DAT_010734d8 = new FUN_00403100("sXBRBumper", "\\general_button_rb.dds\\");
    DAT_010734dc = new FUN_00403100("sXBLBumper", "\\general_button_lb.dds\\");
    DAT_010734e0 = new FUN_00403100("sXBLTrigger", "\\general_button_lt.dds\\");
    DAT_010734e4 = new FUN_00403100("sXBRTrigger", "\\general_button_rt.dds\\");
    DAT_010734e8 = new FUN_00403100("sXBLThumbY", "the Left Stick Up / Down");
    DAT_010734ec = new FUN_00403100("sXBLThumbUp", "the Left Stick Up");
    DAT_010734f0 = new FUN_00403100("sXBLThumbDown", "the Left Stick Down");
    DAT_010734f4 = new FUN_00403100("sXBLThumbX", "the Left Stick Left / Right");
    DAT_010734f8 = new FUN_00403100("sXBLThumbRight", "the Left Stick Right");
    DAT_010734fc = new FUN_00403100("sXBLThumbLeft", "the Left Stick Left");
    DAT_01073500 = new FUN_00403100("sXBRThumbY", "the Right Stick Up / Down");
    DAT_01073504 = new FUN_00403100("sXBRThumbUp", "the Right Stick Up");
    DAT_01073508 = new FUN_00403100("sXBRThumbDown", "the Right Stick Down");
    DAT_0107350c = new FUN_00403100("sXBRThumbX", "the Right Stick Left / Right");
    DAT_01073510 = new FUN_00403100("sXBRThumbRight", "the Right Stick Right");
    DAT_01073514 = new FUN_00403100("sXBRThumbLeft", "the Right Stick Left");
    DAT_01073518 = new FUN_00403100("sXBUnboundBtn", "<NOT BOUND>");
}
}   // namespace f3m_00cdc2a0

// @f3 0x00cdc9e0 (community match, verified in this file)
namespace f3m_00cdc9e0 {


class SettingsHeap { public: void* FUN_0086b930(unsigned int); };
extern SettingsHeap DAT_01090a78;

class FUN_00403100 {
public:
    void* unk00;
    const char* value04;
    const char* name08;
    FUN_00403100(const char* name, const char* value);
    static void* operator new(size_t bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};

extern FUN_00403100* DAT_010738d8;
extern FUN_00403100* DAT_010738dc;
extern FUN_00403100* DAT_010738e0;
extern FUN_00403100* DAT_010738e4;
extern FUN_00403100* DAT_010738e8;
extern FUN_00403100* DAT_010738ec;
extern FUN_00403100* DAT_010738f0;
extern FUN_00403100* DAT_010738f4;
extern FUN_00403100* DAT_010738f8;
extern FUN_00403100* DAT_010738fc;
extern FUN_00403100* DAT_01073900;
extern FUN_00403100* DAT_01073904;
extern FUN_00403100* DAT_01073908;
extern FUN_00403100* DAT_0107390c;
extern FUN_00403100* DAT_01073910;
extern FUN_00403100* DAT_01073914;
extern FUN_00403100* DAT_01073918;
extern FUN_00403100* DAT_0107391c;
extern FUN_00403100* DAT_01073920;
extern FUN_00403100* DAT_01073924;
extern FUN_00403100* DAT_01073928;
extern FUN_00403100* DAT_0107392c;
extern FUN_00403100* DAT_01073930;
extern FUN_00403100* DAT_01073934;
extern FUN_00403100* DAT_01073938;
extern FUN_00403100* DAT_0107393c;
extern FUN_00403100* DAT_01073940;
extern FUN_00403100* DAT_01073944;
extern FUN_00403100* DAT_01073948;
extern FUN_00403100* DAT_0107394c;
extern FUN_00403100* DAT_01073950;

// pdb: `dynamic initializer for 'psPS3GamepadText'' | MenuGamesettings.obj | fnv360_0822_retail, ustr, medium
void FUN_00cdc9e0()
{
    DAT_010738d8 = new FUN_00403100("sPS3DPadY", "D-Pad Up/Down");
    DAT_010738dc = new FUN_00403100("sPS3DPadUp", "D-Pad Up");
    DAT_010738e0 = new FUN_00403100("sPS3DPadDown", "D-Pad Down");
    DAT_010738e4 = new FUN_00403100("sPS3DPadX", "D-Pad Left/Right");
    DAT_010738e8 = new FUN_00403100("sPS3DPadRight", "D-Pad Right");
    DAT_010738ec = new FUN_00403100("sPS3DPadLeft", "D-Pad Left");
    DAT_010738f0 = new FUN_00403100("sPS3StartBtn", "Start");
    DAT_010738f4 = new FUN_00403100("sPS3SelectBtn", "Select");
    DAT_010738f8 = new FUN_00403100("sPS3L3", "\\general_button_ls.dds\\");
    DAT_010738fc = new FUN_00403100("sPS3R3", "\\general_button_rs.dds\\");
    DAT_01073900 = new FUN_00403100("sPS3Ecks", "\\general_button_a.dds\\");
    DAT_01073904 = new FUN_00403100("sPS3Circle", "\\general_button_b.dds\\");
    DAT_01073908 = new FUN_00403100("sPS3Square", "\\general_button_x.dds\\");
    DAT_0107390c = new FUN_00403100("sPS3Triangle", "\\general_button_y.dds\\");
    DAT_01073910 = new FUN_00403100("sPS3R1", "\\general_button_rb.dds\\");
    DAT_01073914 = new FUN_00403100("sPS3L1", "\\general_button_lb.dds\\");
    DAT_01073918 = new FUN_00403100("sPS3R2", "\\general_button_rt.dds\\");
    DAT_0107391c = new FUN_00403100("sPS3L2", "\\general_button_lt.dds\\");
    DAT_01073920 = new FUN_00403100("sPS3LThumbY", "the Left Stick Up / Down");
    DAT_01073924 = new FUN_00403100("sPS3LThumbUp", "the Left Stick Up");
    DAT_01073928 = new FUN_00403100("sPS3LThumbDown", "the Left Stick Down");
    DAT_0107392c = new FUN_00403100("sPS3LThumbX", "the Left Stick Left / Right");
    DAT_01073930 = new FUN_00403100("sPS3LThumbRight", "the Left Stick Right");
    DAT_01073934 = new FUN_00403100("sPS3LThumbLeft", "the Left Stick Left");
    DAT_01073938 = new FUN_00403100("sPS3RThumbY", "the Right Stick Up / Down");
    DAT_0107393c = new FUN_00403100("sPS3RThumbUp", "the Right Stick Up");
    DAT_01073940 = new FUN_00403100("sPS3RThumbDown", "the Right Stick Down");
    DAT_01073944 = new FUN_00403100("sPS3RThumbX", "the Right Stick Left / Right");
    DAT_01073948 = new FUN_00403100("sPS3RThumbRight", "the Right Stick Right");
    DAT_0107394c = new FUN_00403100("sPS3RThumbLeft", "the Right Stick Left");
    DAT_01073950 = new FUN_00403100("sPS3UnboundBtn", "<NOT BOUND>");
}
}   // namespace f3m_00cdc9e0

// @f3 0x00cdf4a0 (community match, verified in this file)
class SettingStandIn
{
public:
    void FUN_0043b7f0(const char* name, int value);
};
extern SettingStandIn DAT_01073b0c;
void FUN_00d94920();
extern "C" int __cdecl atexit(void (__cdecl* fn)(void));

// pdb: `dynamic initializer for 'BSFaceGenManager::uiMaxEGTDataSize'' | BSFaceGenManager.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'BSFaceGenManager::bUseCustomizationMorphs'')
void FUN_00cdf4a0()
{
    DAT_01073b0c.FUN_0043b7f0("uiFaceGenMaxEGTDataSize:General", 0x4000000);
    atexit(FUN_00d94920);
}

// @f3 0x00cc8e40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63614;
void __cdecl FUN_00d91960();

void __cdecl FUN_00cc8e40()
{
    DAT_00f63614.Setting::Setting();
    atexit(FUN_00d91960);
}
}

// @f3 0x00cd7880 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7880 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65300;
void __cdecl FUN_00d93ff0();

void __cdecl FUN_00cd7880()
{
    DAT_00f65300.Setting::Setting();
    atexit(FUN_00d93ff0);
}
}

// @f3 0x00cd7520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65294;
void __cdecl FUN_00d93f60();

void __cdecl FUN_00cd7520()
{
    DAT_00f65294.Setting::Setting();
    atexit(FUN_00d93f60);
}
}

// @f3 0x00ccb840 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb840 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b48;
void __cdecl FUN_00d92050();

void __cdecl FUN_00ccb840()
{
    DAT_00f63b48.Setting::Setting();
    atexit(FUN_00d92050);
}
}

// @f3 0x00cc4b80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62dbc;
void __cdecl FUN_00d90e40();

void __cdecl FUN_00cc4b80()
{
    DAT_00f62dbc.Setting::Setting();
    atexit(FUN_00d90e40);
}
}

// @f3 0x00cca9a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca9a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63980;
void __cdecl FUN_00d91df0();

void __cdecl FUN_00cca9a0()
{
    DAT_00f63980.Setting::Setting();
    atexit(FUN_00d91df0);
}
}

// @f3 0x00cc6560 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6560 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f630f8;
void __cdecl FUN_00d91290();

void __cdecl FUN_00cc6560()
{
    DAT_00f630f8.Setting::Setting();
    atexit(FUN_00d91290);
}
}

// @f3 0x00cddd80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cddd80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65720;
void __cdecl FUN_00d94570();

void __cdecl FUN_00cddd80()
{
    DAT_00f65720.Setting::Setting();
    atexit(FUN_00d94570);
}
}

// @f3 0x00cc3320 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3320 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a8c;
void __cdecl FUN_00d908d0();

void __cdecl FUN_00cc3320()
{
    DAT_00f62a8c.Setting::Setting();
    atexit(FUN_00d908d0);
}
}

// @f3 0x00cd7d00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7d00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65390;
void __cdecl FUN_00d940b0();

void __cdecl FUN_00cd7d00()
{
    DAT_00f65390.Setting::Setting();
    atexit(FUN_00d940b0);
}
}

// @f3 0x00cc0ec0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0ec0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62600;
void __cdecl FUN_00d902c0();

void __cdecl FUN_00cc0ec0()
{
    DAT_00f62600.Setting::Setting();
    atexit(FUN_00d902c0);
}
}

// @f3 0x00cc58a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc58a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62f60;
void __cdecl FUN_00d91070();

void __cdecl FUN_00cc58a0()
{
    DAT_00f62f60.Setting::Setting();
    atexit(FUN_00d91070);
}
}

// @f3 0x00cd90e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd90e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6560c;
void __cdecl FUN_00d94400();

void __cdecl FUN_00cd90e0()
{
    DAT_00f6560c.Setting::Setting();
    atexit(FUN_00d94400);
}
}

// @f3 0x00cc2060 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2060 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62834;
void __cdecl FUN_00d905b0();

void __cdecl FUN_00cc2060()
{
    DAT_00f62834.Setting::Setting();
    atexit(FUN_00d905b0);
}
}

// @f3 0x00ccc320 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc320 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63ca4;
void __cdecl FUN_00d92220();

void __cdecl FUN_00ccc320()
{
    DAT_00f63ca4.Setting::Setting();
    atexit(FUN_00d92220);
}
}

// @f3 0x00cccf20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccf20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63e24;
void __cdecl FUN_00d92420();

void __cdecl FUN_00cccf20()
{
    DAT_00f63e24.Setting::Setting();
    atexit(FUN_00d92420);
}
}

// @f3 0x00cc9440 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f636d4;
void __cdecl FUN_00d91a60();

void __cdecl FUN_00cc9440()
{
    DAT_00f636d4.Setting::Setting();
    atexit(FUN_00d91a60);
}
}

// @f3 0x00cd0be0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd0be0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f645bc;
void __cdecl FUN_00d92e40();

void __cdecl FUN_00cd0be0()
{
    DAT_00f645bc.Setting::Setting();
    atexit(FUN_00d92e40);
}
}

// @f3 0x00cdea30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdea30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65888;
void __cdecl FUN_00d94740();

void __cdecl FUN_00cdea30()
{
    DAT_00f65888.Setting::Setting();
    atexit(FUN_00d94740);
}
}

// @f3 0x00cd8600 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f654b0;
void __cdecl FUN_00d94230();

void __cdecl FUN_00cd8600()
{
    DAT_00f654b0.Setting::Setting();
    atexit(FUN_00d94230);
}
}

// @f3 0x00cd5560 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5560 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64eec;
void __cdecl FUN_00d93a80();

void __cdecl FUN_00cd5560()
{
    DAT_00f64eec.Setting::Setting();
    atexit(FUN_00d93a80);
}
}

// @f3 0x00cc8240 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63494;
void __cdecl FUN_00d91760();

void __cdecl FUN_00cc8240()
{
    DAT_00f63494.Setting::Setting();
    atexit(FUN_00d91760);
}
}

// @f3 0x00cd4f00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4f00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64e20;
void __cdecl FUN_00d93970();

void __cdecl FUN_00cd4f00()
{
    DAT_00f64e20.Setting::Setting();
    atexit(FUN_00d93970);
}
}

// @f3 0x00ccc8c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc8c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63d58;
void __cdecl FUN_00d92310();

void __cdecl FUN_00ccc8c0()
{
    DAT_00f63d58.Setting::Setting();
    atexit(FUN_00d92310);
}
}

// @f3 0x00cc7460 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7460 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f632d8;
void __cdecl FUN_00d91510();

void __cdecl FUN_00cc7460()
{
    DAT_00f632d8.Setting::Setting();
    atexit(FUN_00d91510);
}
}

// @f3 0x00cc5de0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5de0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63008;
void __cdecl FUN_00d91150();

void __cdecl FUN_00cc5de0()
{
    DAT_00f63008.Setting::Setting();
    atexit(FUN_00d91150);
}
}

// @f3 0x00cd6d40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6d40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65198;
void __cdecl FUN_00d93e10();

void __cdecl FUN_00cd6d40()
{
    DAT_00f65198.Setting::Setting();
    atexit(FUN_00d93e10);
}
}

// @f3 0x00cc46a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc46a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62d20;
void __cdecl FUN_00d90d70();
}

void __cdecl FUN_00cc46a0()
{
    f3m_00cc46a0::DAT_00f62d20.f3m_00cc46a0::Setting::Setting();
    atexit(f3m_00cc46a0::FUN_00d90d70);
}

// @f3 0x00cc79a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc79a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63380;
void __cdecl FUN_00d915f0();
}

void __cdecl FUN_00cc79a0()
{
    f3m_00cc79a0::DAT_00f63380.f3m_00cc79a0::Setting::Setting();
    atexit(f3m_00cc79a0::FUN_00d915f0);
}

// @f3 0x00cd3340 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3340 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64aa8;
void __cdecl FUN_00d934d0();

void __cdecl FUN_00cd3340()
{
    DAT_00f64aa8.Setting::Setting();
    atexit(FUN_00d934d0);
}
}

// @f3 0x00cd7940 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7940 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65318;
void __cdecl FUN_00d94010();

void __cdecl FUN_00cd7940()
{
    DAT_00f65318.Setting::Setting();
    atexit(FUN_00d94010);
}
}

// @f3 0x00cc9680 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9680 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6371c;
void __cdecl FUN_00d91ac0();

void __cdecl FUN_00cc9680()
{
    DAT_00f6371c.Setting::Setting();
    atexit(FUN_00d91ac0);
}
}

// @f3 0x00cd9440 (community match, verified in this file)
#include <stdlib.h>
struct RegistrySetting;
struct Manager { virtual void v00(); virtual void Register(RegistrySetting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct RegistrySetting : Cleanup {
    __forceinline RegistrySetting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern RegistrySetting DAT_00f65678;
void __cdecl FUN_00d94490();

void __cdecl FUN_00cd9440()
{
    DAT_00f65678.RegistrySetting::RegistrySetting();
    atexit(FUN_00d94490);
}

// @f3 0x00cd3ac0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3ac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64b98;
void __cdecl FUN_00d93610();
}

void __cdecl FUN_00cd3ac0()
{
    f3m_00cd3ac0::DAT_00f64b98.f3m_00cd3ac0::Setting::Setting();
    atexit(f3m_00cd3ac0::FUN_00d93610);
}

// @f3 0x00ccaca0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccaca0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f639d4;
void __cdecl FUN_00d91e60();

void __cdecl FUN_00ccaca0()
{
    DAT_00f639d4.Setting::Setting();
    atexit(FUN_00d91e60);
}
}

// @f3 0x00cc33e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc33e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62aa4;
void __cdecl FUN_00d908f0();

void __cdecl FUN_00cc33e0()
{
    DAT_00f62aa4.Setting::Setting();
    atexit(FUN_00d908f0);
}
}

// @f3 0x00cdefd0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdefd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6593c;
void __cdecl FUN_00d94830();

void __cdecl FUN_00cdefd0()
{
    DAT_00f6593c.Setting::Setting();
    atexit(FUN_00d94830);
}
}

// @f3 0x00cccaa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccaa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63d94;
void __cdecl FUN_00d92360();
}

void __cdecl FUN_00cccaa0()
{
    f3m_00cccaa0::DAT_00f63d94.f3m_00cccaa0::Setting::Setting();
    atexit(f3m_00cccaa0::FUN_00d92360);
}

// @f3 0x00cca4c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca4c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f638e4;
void __cdecl FUN_00d91d20();

void __cdecl FUN_00cca4c0()
{
    DAT_00f638e4.Setting::Setting();
    atexit(FUN_00d91d20);
}
}

// @f3 0x00cc37a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc37a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62b1c;
void __cdecl FUN_00d90990();

void __cdecl FUN_00cc37a0()
{
    DAT_00f62b1c.Setting::Setting();
    atexit(FUN_00d90990);
}
}

// @f3 0x00cc5cc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5cc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62fe4;
void __cdecl FUN_00d91120();

void __cdecl FUN_00cc5cc0()
{
    DAT_00f62fe4.Setting::Setting();
    atexit(FUN_00d91120);
}
}

// @f3 0x00cc1760 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1760 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62714;
void __cdecl FUN_00d90430();

void __cdecl FUN_00cc1760()
{
    DAT_00f62714.Setting::Setting();
    atexit(FUN_00d90430);
}
}

// @f3 0x00cdeaf0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdeaf0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f658a0;
void __cdecl FUN_00d94760();

void __cdecl FUN_00cdeaf0()
{
    DAT_00f658a0.Setting::Setting();
    atexit(FUN_00d94760);
}
}

// @f3 0x00cdfd70 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdfd70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65f50;
void __cdecl FUN_00d94ab0();

void __cdecl FUN_00cdfd70()
{
    DAT_00f65f50.Setting::Setting();
    atexit(FUN_00d94ab0);
}
}

// @f3 0x00cc9800 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9800 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6374c;
void __cdecl FUN_00d91b00();

void __cdecl FUN_00cc9800()
{
    DAT_00f6374c.Setting::Setting();
    atexit(FUN_00d91b00);
}
}

// @f3 0x00cc9740 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9740 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63734;
void __cdecl FUN_00d91ae0();

void __cdecl FUN_00cc9740()
{
    DAT_00f63734.Setting::Setting();
    atexit(FUN_00d91ae0);
}
}

// @f3 0x00cc8060 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8060 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63458;
void __cdecl FUN_00d91710();

void __cdecl FUN_00cc8060()
{
    DAT_00f63458.Setting::Setting();
    atexit(FUN_00d91710);
}
}

// @f3 0x00cc5960 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62f78;
void __cdecl FUN_00d91090();
}

void __cdecl FUN_00cc5960()
{
    f3m_00cc5960::DAT_00f62f78.f3m_00cc5960::Setting::Setting();
    atexit(f3m_00cc5960::FUN_00d91090);
}

// @f3 0x00ccbfc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbfc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63c38;
void __cdecl FUN_00d92190();

void __cdecl FUN_00ccbfc0()
{
    DAT_00f63c38.Setting::Setting();
    atexit(FUN_00d92190);
}
}

// @f3 0x00cd77c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd77c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f652e8;
void __cdecl FUN_00d93fd0();

void __cdecl FUN_00cd77c0()
{
    DAT_00f652e8.Setting::Setting();
    atexit(FUN_00d93fd0);
}
}

// @f3 0x00ccbea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63c14;
void __cdecl FUN_00d92160();

void __cdecl FUN_00ccbea0()
{
    DAT_00f63c14.Setting::Setting();
    atexit(FUN_00d92160);
}
}

// @f3 0x00cc6f80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6f80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6323c;
void __cdecl FUN_00d91440();

void __cdecl FUN_00cc6f80()
{
    DAT_00f6323c.Setting::Setting();
    atexit(FUN_00d91440);
}
}

// @f3 0x00ccfa40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccfa40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64388;
void __cdecl FUN_00d92b50();

void __cdecl FUN_00ccfa40()
{
    DAT_00f64388.Setting::Setting();
    atexit(FUN_00d92b50);
}
}

// @f3 0x00cc4040 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4040 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62c54;
void __cdecl FUN_00d90c60();

void __cdecl FUN_00cc4040()
{
    DAT_00f62c54.Setting::Setting();
    atexit(FUN_00d90c60);
}
}

// @f3 0x00cc5f60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5f60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63038;
void __cdecl FUN_00d91190();

void __cdecl FUN_00cc5f60()
{
    DAT_00f63038.Setting::Setting();
    atexit(FUN_00d91190);
}
}

// @f3 0x00cc0920 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6254c;
void __cdecl FUN_00d901d0();

void __cdecl FUN_00cc0920()
{
    DAT_00f6254c.Setting::Setting();
    atexit(FUN_00d901d0);
}
}

// @f3 0x00ccc980 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63d70;
void __cdecl FUN_00d92330();

void __cdecl FUN_00ccc980()
{
    DAT_00f63d70.Setting::Setting();
    atexit(FUN_00d92330);
}
}

// @f3 0x00cc8f60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8f60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63638;
void __cdecl FUN_00d91990();

void __cdecl FUN_00cc8f60()
{
    DAT_00f63638.Setting::Setting();
    atexit(FUN_00d91990);
}
}

// @f3 0x00ccd160 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd160 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f63e6c;
void __cdecl FUN_00403080();
void __cdecl FUN_00d92480();
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}
void __cdecl FUN_00ccd160()
{
    f3m_00ccd160::DAT_00f63e6c.f3m_00ccd160::SettingRegistration::SettingRegistration();
    atexit(f3m_00ccd160::FUN_00d92480);
}

// @f3 0x00cc1a00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1a00 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f62768;
void __cdecl FUN_00403080();
void __cdecl FUN_00d904a0();
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}
void __cdecl FUN_00cc1a00()
{
    f3m_00cc1a00::DAT_00f62768.f3m_00cc1a00::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc1a00::FUN_00d904a0);
}

// @f3 0x00cc1400 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f626a8;
void __cdecl FUN_00d903a0();

void __cdecl FUN_00cc1400()
{
    DAT_00f626a8.Setting::Setting();
    atexit(FUN_00d903a0);
}
}

// @f3 0x00cd8d20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8d20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65594;
void __cdecl FUN_00d94360();

void __cdecl FUN_00cd8d20()
{
    DAT_00f65594.Setting::Setting();
    atexit(FUN_00d94360);
}
}

// @f3 0x00cd2c20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2c20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f649c4;
void __cdecl FUN_00d933a0();

void __cdecl FUN_00cd2c20()
{
    DAT_00f649c4.Setting::Setting();
    atexit(FUN_00d933a0);
}
}

// @f3 0x00cd7ca0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7ca0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65384;
void __cdecl FUN_00d940a0();

void __cdecl FUN_00cd7ca0()
{
    DAT_00f65384.Setting::Setting();
    atexit(FUN_00d940a0);
}
}

// @f3 0x00cc2b40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2b40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62990;
void __cdecl FUN_00d90780();

void __cdecl FUN_00cc2b40()
{
    DAT_00f62990.Setting::Setting();
    atexit(FUN_00d90780);
}
}

// @f3 0x00cc34a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc34a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62abc;
void __cdecl FUN_00d90910();

void __cdecl FUN_00cc34a0()
{
    DAT_00f62abc.Setting::Setting();
    atexit(FUN_00d90910);
}
}

// @f3 0x00cd2b60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2b60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f649ac;
void __cdecl FUN_00d93380();

void __cdecl FUN_00cd2b60()
{
    DAT_00f649ac.Setting::Setting();
    atexit(FUN_00d93380);
}
}

// @f3 0x00cd60e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd60e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6500c;
void __cdecl FUN_00d93c00();

void __cdecl FUN_00cd60e0()
{
    DAT_00f6500c.Setting::Setting();
    atexit(FUN_00d93c00);
}
}

// @f3 0x00cd3040 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3040 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64a48;
void __cdecl FUN_00d93450();

void __cdecl FUN_00cd3040()
{
    DAT_00f64a48.Setting::Setting();
    atexit(FUN_00d93450);
}
}

// @f3 0x00cc8d20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8d20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f635f0;
void __cdecl FUN_00d91930();

void __cdecl FUN_00cc8d20()
{
    DAT_00f635f0.Setting::Setting();
    atexit(FUN_00d91930);
}
}

// @f3 0x00cd7760 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7760 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f652dc;
void __cdecl FUN_00d93fc0();

void __cdecl FUN_00cd7760()
{
    DAT_00f652dc.Setting::Setting();
    atexit(FUN_00d93fc0);
}
}

// @f3 0x00cd1360 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f646ac;
void __cdecl FUN_00d92f80();

void __cdecl FUN_00cd1360()
{
    DAT_00f646ac.Setting::Setting();
    atexit(FUN_00d92f80);
}
}

// @f3 0x00cd6c20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6c20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65174;
void __cdecl FUN_00d93de0();

void __cdecl FUN_00cd6c20()
{
    DAT_00f65174.Setting::Setting();
    atexit(FUN_00d93de0);
}
}

// @f3 0x00cd0b80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd0b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f645b0;
void __cdecl FUN_00d92e30();

void __cdecl FUN_00cd0b80()
{
    DAT_00f645b0.Setting::Setting();
    atexit(FUN_00d92e30);
}
}

// @f3 0x00cc6aa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6aa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f631a0;
void __cdecl FUN_00d91370();

void __cdecl FUN_00cc6aa0()
{
    DAT_00f631a0.Setting::Setting();
    atexit(FUN_00d91370);
}
}

// @f3 0x00ccde20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccde20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64004;
void __cdecl FUN_00d926a0();

void __cdecl FUN_00ccde20()
{
    DAT_00f64004.Setting::Setting();
    atexit(FUN_00d926a0);
}
}

// @f3 0x00cd8780 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8780 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f654e0;
void __cdecl FUN_00d94270();

void __cdecl FUN_00cd8780()
{
    DAT_00f654e0.Setting::Setting();
    atexit(FUN_00d94270);
}
}

// @f3 0x00cd0dc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd0dc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f645f8;
void __cdecl FUN_00d92e90();

void __cdecl FUN_00cd0dc0()
{
    DAT_00f645f8.Setting::Setting();
    atexit(FUN_00d92e90);
}
}

// @f3 0x00cd9380 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd9380 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65660;
void __cdecl FUN_00d94470();

void __cdecl FUN_00cd9380()
{
    DAT_00f65660.Setting::Setting();
    atexit(FUN_00d94470);
}
}

// @f3 0x00cc5e40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63014;
void __cdecl FUN_00d91160();

void __cdecl FUN_00cc5e40()
{
    DAT_00f63014.Setting::Setting();
    atexit(FUN_00d91160);
}
}

// @f3 0x00cd05e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd05e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f644fc;
void __cdecl FUN_00d92d40();

void __cdecl FUN_00cd05e0()
{
    DAT_00f644fc.Setting::Setting();
    atexit(FUN_00d92d40);
}
}

// @f3 0x00cd5380 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5380 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64eb0;
void __cdecl FUN_00d93a30();

void __cdecl FUN_00cd5380()
{
    DAT_00f64eb0.Setting::Setting();
    atexit(FUN_00d93a30);
}
}

// @f3 0x00cc09e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc09e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62564;
void __cdecl FUN_00d901f0();

void __cdecl FUN_00cc09e0()
{
    DAT_00f62564.Setting::Setting();
    atexit(FUN_00d901f0);
}
}

// @f3 0x00cc3ce0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3ce0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62bc4;
void __cdecl FUN_00d90a70();

void __cdecl FUN_00cc3ce0()
{
    DAT_00f62bc4.Setting::Setting();
    atexit(FUN_00d90a70);
}
}

// @f3 0x00cd93e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd93e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6566c;
void __cdecl FUN_00d94480();

void __cdecl FUN_00cd93e0()
{
    DAT_00f6566c.Setting::Setting();
    atexit(FUN_00d94480);
}
}

// @f3 0x00cc60e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc60e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63068;
void __cdecl FUN_00d911d0();

void __cdecl FUN_00cc60e0()
{
    DAT_00f63068.Setting::Setting();
    atexit(FUN_00d911d0);
}
}

// @f3 0x00cc2c00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f629a8;
void __cdecl FUN_00d907a0();

void __cdecl FUN_00cc2c00()
{
    DAT_00f629a8.Setting::Setting();
    atexit(FUN_00d907a0);
}
}

// @f3 0x00cd4600 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64d00;
void __cdecl FUN_00d937f0();

void __cdecl FUN_00cd4600()
{
    DAT_00f64d00.Setting::Setting();
    atexit(FUN_00d937f0);
}
}

// @f3 0x00ccc140 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63c68;
void __cdecl FUN_00d921d0();

void __cdecl FUN_00ccc140()
{
    DAT_00f63c68.Setting::Setting();
    atexit(FUN_00d921d0);
}
}

// @f3 0x00cc9140 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63674;
void __cdecl FUN_00d919e0();

void __cdecl FUN_00cc9140()
{
    DAT_00f63674.Setting::Setting();
    atexit(FUN_00d919e0);
}
}

// @f3 0x00cccbc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccbc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63db8;
void __cdecl FUN_00d92390();

void __cdecl FUN_00cccbc0()
{
    DAT_00f63db8.Setting::Setting();
    atexit(FUN_00d92390);
}
}

// @f3 0x00cc4280 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4280 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62c9c;
void __cdecl FUN_00d90cc0();

void __cdecl FUN_00cc4280()
{
    DAT_00f62c9c.Setting::Setting();
    atexit(FUN_00d90cc0);
}
}

// @f3 0x00cd8c00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65570;
void __cdecl FUN_00d94330();

void __cdecl FUN_00cd8c00()
{
    DAT_00f65570.Setting::Setting();
    atexit(FUN_00d94330);
}
}

// @f3 0x00cc3aa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3aa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62b7c;
void __cdecl FUN_00d90a10();

void __cdecl FUN_00cc3aa0()
{
    DAT_00f62b7c.Setting::Setting();
    atexit(FUN_00d90a10);
}
}

// @f3 0x00cc4520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62cf0;
void __cdecl FUN_00d90d30();

void __cdecl FUN_00cc4520()
{
    DAT_00f62cf0.Setting::Setting();
    atexit(FUN_00d90d30);
}
}

// @f3 0x00cd5860 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64f4c;
void __cdecl FUN_00d93b00();

void __cdecl FUN_00cd5860()
{
    DAT_00f64f4c.Setting::Setting();
    atexit(FUN_00d93b00);
}
}

// @f3 0x00cd70a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd70a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65204;
void __cdecl FUN_00d93ea0();

void __cdecl FUN_00cd70a0()
{
    DAT_00f65204.Setting::Setting();
    atexit(FUN_00d93ea0);
}
}

// @f3 0x00cd5020 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5020 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64e44;
void __cdecl FUN_00d939a0();

void __cdecl FUN_00cd5020()
{
    DAT_00f64e44.Setting::Setting();
    atexit(FUN_00d939a0);
}
}

// @f3 0x00cc4fa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4fa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62e40;
void __cdecl FUN_00d90ef0();

void __cdecl FUN_00cc4fa0()
{
    DAT_00f62e40.Setting::Setting();
    atexit(FUN_00d90ef0);
}
}

// @f3 0x00cc91a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc91a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63680;
void __cdecl FUN_00d919f0();

void __cdecl FUN_00cc91a0()
{
    DAT_00f63680.Setting::Setting();
    atexit(FUN_00d919f0);
}
}

// @f3 0x00cd44e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd44e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64cdc;
void __cdecl FUN_00d937c0();

void __cdecl FUN_00cd44e0()
{
    DAT_00f64cdc.Setting::Setting();
    atexit(FUN_00d937c0);
}
}

// @f3 0x00cd1d80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1d80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f647f0;
void __cdecl FUN_00d93130();

void __cdecl FUN_00cd1d80()
{
    DAT_00f647f0.Setting::Setting();
    atexit(FUN_00d93130);
}
}

// @f3 0x00cd1180 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64670;
void __cdecl FUN_00d92f30();

void __cdecl FUN_00cd1180()
{
    DAT_00f64670.Setting::Setting();
    atexit(FUN_00d92f30);
}
}

// @f3 0x00cc94a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc94a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f636e0;
void __cdecl FUN_00d91a70();

void __cdecl FUN_00cc94a0()
{
    DAT_00f636e0.Setting::Setting();
    atexit(FUN_00d91a70);
}
}

// @f3 0x00ccf260 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf260 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6428c;
void __cdecl FUN_00d92a00();

void __cdecl FUN_00ccf260()
{
    DAT_00f6428c.Setting::Setting();
    atexit(FUN_00d92a00);
}
}

// @f3 0x00cd0220 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd0220 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64484;
void __cdecl FUN_00d92ca0();

void __cdecl FUN_00cd0220()
{
    DAT_00f64484.Setting::Setting();
    atexit(FUN_00d92ca0);
}
}

// @f3 0x00cc4a60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4a60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62d98;
void __cdecl FUN_00d90e10();

void __cdecl FUN_00cc4a60()
{
    DAT_00f62d98.Setting::Setting();
    atexit(FUN_00d90e10);
}
}

// @f3 0x00cc2780 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2780 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62918;
void __cdecl FUN_00d906e0();

void __cdecl FUN_00cc2780()
{
    DAT_00f62918.Setting::Setting();
    atexit(FUN_00d906e0);
}
}

// @f3 0x00cd7400 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65270;
void __cdecl FUN_00d93f30();

void __cdecl FUN_00cd7400()
{
    DAT_00f65270.Setting::Setting();
    atexit(FUN_00d93f30);
}
}

// @f3 0x00ccdac0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccdac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63f98;
void __cdecl FUN_00d92610();

void __cdecl FUN_00ccdac0()
{
    DAT_00f63f98.Setting::Setting();
    atexit(FUN_00d92610);
}
}

// @f3 0x00cc06e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc06e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62504;
void __cdecl FUN_00d90170();

void __cdecl FUN_00cc06e0()
{
    DAT_00f62504.Setting::Setting();
    atexit(FUN_00d90170);
}
}

// @f3 0x00cc8180 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6347c;
void __cdecl FUN_00d91740();

void __cdecl FUN_00cc8180()
{
    DAT_00f6347c.Setting::Setting();
    atexit(FUN_00d91740);
}
}

// @f3 0x00cd29e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd29e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6497c;
void __cdecl FUN_00d93340();

void __cdecl FUN_00cd29e0()
{
    DAT_00f6497c.Setting::Setting();
    atexit(FUN_00d93340);
}
}

// @f3 0x00cd3fa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3fa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64c34;
void __cdecl FUN_00d936e0();

void __cdecl FUN_00cd3fa0()
{
    DAT_00f64c34.Setting::Setting();
    atexit(FUN_00d936e0);
}
}

// @f3 0x00cc7520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f632f0;
void __cdecl FUN_00d91530();

void __cdecl FUN_00cc7520()
{
    DAT_00f632f0.Setting::Setting();
    atexit(FUN_00d91530);
}
}

// @f3 0x00cd08e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd08e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6455c;
void __cdecl FUN_00d92dc0();

void __cdecl FUN_00cd08e0()
{
    DAT_00f6455c.Setting::Setting();
    atexit(FUN_00d92dc0);
}
}

// @f3 0x00cccce0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccce0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63ddc;
void __cdecl FUN_00d923c0();

void __cdecl FUN_00cccce0()
{
    DAT_00f63ddc.Setting::Setting();
    atexit(FUN_00d923c0);
}
}

// @f3 0x00cde730 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde730 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65828;
void __cdecl FUN_00d946c0();

void __cdecl FUN_00cde730()
{
    DAT_00f65828.Setting::Setting();
    atexit(FUN_00d946c0);
}
}

// @f3 0x00cc3680 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3680 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62af8;
void __cdecl FUN_00d90960();

void __cdecl FUN_00cc3680()
{
    DAT_00f62af8.Setting::Setting();
    atexit(FUN_00d90960);
}
}

// @f3 0x00ccb8a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb8a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b54;
void __cdecl FUN_00d92060();

void __cdecl FUN_00ccb8a0()
{
    DAT_00f63b54.Setting::Setting();
    atexit(FUN_00d92060);
}
}

// @f3 0x00cd4c60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4c60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64dcc;
void __cdecl FUN_00d93900();

void __cdecl FUN_00cd4c60()
{
    DAT_00f64dcc.Setting::Setting();
    atexit(FUN_00d93900);
}
}

// @f3 0x00cd6e60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6e60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f651bc;
void __cdecl FUN_00d93e40();

void __cdecl FUN_00cd6e60()
{
    DAT_00f651bc.Setting::Setting();
    atexit(FUN_00d93e40);
}
}

// @f3 0x00cc48e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc48e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62d68;
void __cdecl FUN_00d90dd0();

void __cdecl FUN_00cc48e0()
{
    DAT_00f62d68.Setting::Setting();
    atexit(FUN_00d90dd0);
}
}

// @f3 0x00cd6aa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6aa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65144;
void __cdecl FUN_00d93da0();

void __cdecl FUN_00cd6aa0()
{
    DAT_00f65144.Setting::Setting();
    atexit(FUN_00d93da0);
}
}

// @f3 0x00cc1d00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1d00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f627c8;
void __cdecl FUN_00d90520();

void __cdecl FUN_00cc1d00()
{
    DAT_00f627c8.Setting::Setting();
    atexit(FUN_00d90520);
}
}

// @f3 0x00cc68c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc68c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63164;
void __cdecl FUN_00d91320();

void __cdecl FUN_00cc68c0()
{
    DAT_00f63164.Setting::Setting();
    atexit(FUN_00d91320);
}
}

// @f3 0x00cc4dc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4dc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62e04;
void __cdecl FUN_00d90ea0();

void __cdecl FUN_00cc4dc0()
{
    DAT_00f62e04.Setting::Setting();
    atexit(FUN_00d90ea0);
}
}

// @f3 0x00cd3520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ae4;
void __cdecl FUN_00d93520();

void __cdecl FUN_00cd3520()
{
    DAT_00f64ae4.Setting::Setting();
    atexit(FUN_00d93520);
}
}

// @f3 0x00cc3440 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62ab0;
void __cdecl FUN_00d90900();

void __cdecl FUN_00cc3440()
{
    DAT_00f62ab0.Setting::Setting();
    atexit(FUN_00d90900);
}
}

// @f3 0x00ccb5a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb5a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63af4;
void __cdecl FUN_00d91fe0();

void __cdecl FUN_00ccb5a0()
{
    DAT_00f63af4.Setting::Setting();
    atexit(FUN_00d91fe0);
}
}

// @f3 0x00cd4780 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4780 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64d30;
void __cdecl FUN_00d93830();

void __cdecl FUN_00cd4780()
{
    DAT_00f64d30.Setting::Setting();
    atexit(FUN_00d93830);
}
}

// @f3 0x00cd7e80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7e80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f653c0;
void __cdecl FUN_00d940f0();

void __cdecl FUN_00cd7e80()
{
    DAT_00f653c0.Setting::Setting();
    atexit(FUN_00d940f0);
}
}

// @f3 0x00cc0500 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0500 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f624c8;
void __cdecl FUN_00d90120();

void __cdecl FUN_00cc0500()
{
    DAT_00f624c8.Setting::Setting();
    atexit(FUN_00d90120);
}
}

// @f3 0x00ccd4c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd4c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63ed8;
void __cdecl FUN_00d92510();

void __cdecl FUN_00ccd4c0()
{
    DAT_00f63ed8.Setting::Setting();
    atexit(FUN_00d92510);
}
}

// @f3 0x00cc44c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc44c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62ce4;
void __cdecl FUN_00d90d20();

void __cdecl FUN_00cc44c0()
{
    DAT_00f62ce4.Setting::Setting();
    atexit(FUN_00d90d20);
}
}

// @f3 0x00cd4180 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64c70;
void __cdecl FUN_00d93730();

void __cdecl FUN_00cd4180()
{
    DAT_00f64c70.Setting::Setting();
    atexit(FUN_00d93730);
}
}

// @f3 0x00cd5260 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5260 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64e8c;
void __cdecl FUN_00d93a00();

void __cdecl FUN_00cd5260()
{
    DAT_00f64e8c.Setting::Setting();
    atexit(FUN_00d93a00);
}
}

// @f3 0x00cd5500 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5500 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ee0;
void __cdecl FUN_00d93a70();

void __cdecl FUN_00cd5500()
{
    DAT_00f64ee0.Setting::Setting();
    atexit(FUN_00d93a70);
}
}

// @f3 0x00cc7ee0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7ee0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63428;
void __cdecl FUN_00d916d0();

void __cdecl FUN_00cc7ee0()
{
    DAT_00f63428.Setting::Setting();
    atexit(FUN_00d916d0);
}
}

// @f3 0x00cc7ca0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7ca0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f633e0;
void __cdecl FUN_00d91670();

void __cdecl FUN_00cc7ca0()
{
    DAT_00f633e0.Setting::Setting();
    atexit(FUN_00d91670);
}
}

// @f3 0x00cc7b80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f633bc;
void __cdecl FUN_00d91640();

void __cdecl FUN_00cc7b80()
{
    DAT_00f633bc.Setting::Setting();
    atexit(FUN_00d91640);
}
}

// @f3 0x00cd2140 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64868;
void __cdecl FUN_00d931d0();

void __cdecl FUN_00cd2140()
{
    DAT_00f64868.Setting::Setting();
    atexit(FUN_00d931d0);
}
}

// @f3 0x00cc71c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc71c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63284;
void __cdecl FUN_00d914a0();

void __cdecl FUN_00cc71c0()
{
    DAT_00f63284.Setting::Setting();
    atexit(FUN_00d914a0);
}
}

// @f3 0x00cc0e60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0e60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f625f4;
void __cdecl FUN_00d902b0();

void __cdecl FUN_00cc0e60()
{
    DAT_00f625f4.Setting::Setting();
    atexit(FUN_00d902b0);
}
}

// @f3 0x00cde910 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde910 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65864;
void __cdecl FUN_00d94710();

void __cdecl FUN_00cde910()
{
    DAT_00f65864.Setting::Setting();
    atexit(FUN_00d94710);
}
}

// @f3 0x00cd6860 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f650fc;
void __cdecl FUN_00d93d40();

void __cdecl FUN_00cd6860()
{
    DAT_00f650fc.Setting::Setting();
    atexit(FUN_00d93d40);
}
}

// @f3 0x00ccbe40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbe40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63c08;
void __cdecl FUN_00d92150();

void __cdecl FUN_00ccbe40()
{
    DAT_00f63c08.Setting::Setting();
    atexit(FUN_00d92150);
}
}

// @f3 0x00cd66e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd66e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f650cc;
void __cdecl FUN_00d93d00();

void __cdecl FUN_00cd66e0()
{
    DAT_00f650cc.Setting::Setting();
    atexit(FUN_00d93d00);
}
}

// @f3 0x00cdebb0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdebb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f658b8;
void __cdecl FUN_00d94780();

void __cdecl FUN_00cdebb0()
{
    DAT_00f658b8.Setting::Setting();
    atexit(FUN_00d94780);
}
}

// @f3 0x00ccb4e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb4e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63adc;
void __cdecl FUN_00d91fc0();

void __cdecl FUN_00ccb4e0()
{
    DAT_00f63adc.Setting::Setting();
    atexit(FUN_00d91fc0);
}
}

// @f3 0x00cc9920 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63770;
void __cdecl FUN_00d91b30();

void __cdecl FUN_00cc9920()
{
    DAT_00f63770.Setting::Setting();
    atexit(FUN_00d91b30);
}
}

// @f3 0x00cc2120 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2120 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6284c;
void __cdecl FUN_00d905d0();

void __cdecl FUN_00cc2120()
{
    DAT_00f6284c.Setting::Setting();
    atexit(FUN_00d905d0);
}
}

// @f3 0x00ccaac0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccaac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f639a4;
void __cdecl FUN_00d91e20();

void __cdecl FUN_00ccaac0()
{
    DAT_00f639a4.Setting::Setting();
    atexit(FUN_00d91e20);
}
}

// @f3 0x00cc9560 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9560 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f636f8;
void __cdecl FUN_00d91a90();

void __cdecl FUN_00cc9560()
{
    DAT_00f636f8.Setting::Setting();
    atexit(FUN_00d91a90);
}
}

// @f3 0x00ccf080 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf080 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64250;
void __cdecl FUN_00d929b0();

void __cdecl FUN_00ccf080()
{
    DAT_00f64250.Setting::Setting();
    atexit(FUN_00d929b0);
}
}

// @f3 0x00cccb60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccb60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63dac;
void __cdecl FUN_00d92380();

void __cdecl FUN_00cccb60()
{
    DAT_00f63dac.Setting::Setting();
    atexit(FUN_00d92380);
}
}

// @f3 0x00cc3ec0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3ec0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62c24;
void __cdecl FUN_00d90c20();

void __cdecl FUN_00cc3ec0()
{
    DAT_00f62c24.Setting::Setting();
    atexit(FUN_00d90c20);
}
}

// @f3 0x00cc6ec0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6ec0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63224;
void __cdecl FUN_00d91420();

void __cdecl FUN_00cc6ec0()
{
    DAT_00f63224.Setting::Setting();
    atexit(FUN_00d91420);
}
}

// @f3 0x00cc66e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc66e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63128;
void __cdecl FUN_00d912d0();

void __cdecl FUN_00cc66e0()
{
    DAT_00f63128.Setting::Setting();
    atexit(FUN_00d912d0);
}
}

// @f3 0x00cc3c80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3c80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62bb8;
void __cdecl FUN_00d90a60();

void __cdecl FUN_00cc3c80()
{
    DAT_00f62bb8.Setting::Setting();
    atexit(FUN_00d90a60);
}
}

// @f3 0x00ccbf00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbf00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63c20;
void __cdecl FUN_00d92170();

void __cdecl FUN_00ccbf00()
{
    DAT_00f63c20.Setting::Setting();
    atexit(FUN_00d92170);
}
}

// @f3 0x00cc1700 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1700 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62708;
void __cdecl FUN_00d90420();

void __cdecl FUN_00cc1700()
{
    DAT_00f62708.Setting::Setting();
    atexit(FUN_00d90420);
}
}

// @f3 0x00cd88a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd88a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65504;
void __cdecl FUN_00d942a0();

void __cdecl FUN_00cd88a0()
{
    DAT_00f65504.Setting::Setting();
    atexit(FUN_00d942a0);
}
}

// @f3 0x00cd7b20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7b20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65354;
void __cdecl FUN_00d94060();

void __cdecl FUN_00cd7b20()
{
    DAT_00f65354.Setting::Setting();
    atexit(FUN_00d94060);
}
}

// @f3 0x00cc7160 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7160 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63278;
void __cdecl FUN_00d91490();

void __cdecl FUN_00cc7160()
{
    DAT_00f63278.Setting::Setting();
    atexit(FUN_00d91490);
}
}

// @f3 0x00ccb180 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63a70;
void __cdecl FUN_00d91f30();

void __cdecl FUN_00ccb180()
{
    DAT_00f63a70.Setting::Setting();
    atexit(FUN_00d91f30);
}
}

// @f3 0x00cd78e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd78e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6530c;
void __cdecl FUN_00d94000();

void __cdecl FUN_00cd78e0()
{
    DAT_00f6530c.Setting::Setting();
    atexit(FUN_00d94000);
}
}

// @f3 0x00ccea20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccea20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64184;
void __cdecl FUN_00d928a0();

void __cdecl FUN_00ccea20()
{
    DAT_00f64184.Setting::Setting();
    atexit(FUN_00d928a0);
}
}

// @f3 0x00cc8c60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8c60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f635d8;
void __cdecl FUN_00d91910();

void __cdecl FUN_00cc8c60()
{
    DAT_00f635d8.Setting::Setting();
    atexit(FUN_00d91910);
}
}

// @f3 0x00cd5dc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5dc0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_010732f0;
void __cdecl FUN_00d90be0();
}

// pdb: `dynamic initializer for 'iConcentricLengthMaxEasy'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5dc0()
{
    f3m_00cd5dc0::DAT_010732f0.FUN_0043b7f0("iConcentricLengthMaxEasy", 200);
    atexit(f3m_00cd5dc0::FUN_00d90be0);
}

// @f3 0x00cd65c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd65c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f650a8;
void __cdecl FUN_00d93cd0();

void __cdecl FUN_00cd65c0()
{
    DAT_00f650a8.Setting::Setting();
    atexit(FUN_00d93cd0);
}
}

// @f3 0x00cc6380 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6380 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f630bc;
void __cdecl FUN_00d91240();

void __cdecl FUN_00cc6380()
{
    DAT_00f630bc.Setting::Setting();
    atexit(FUN_00d91240);
}
}

// @f3 0x00cd2a40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2a40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64988;
void __cdecl FUN_00d93350();

void __cdecl FUN_00cd2a40()
{
    DAT_00f64988.Setting::Setting();
    atexit(FUN_00d93350);
}
}

// @f3 0x00ccb600 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b00;
void __cdecl FUN_00d91ff0();

void __cdecl FUN_00ccb600()
{
    DAT_00f63b00.Setting::Setting();
    atexit(FUN_00d91ff0);
}
}

// @f3 0x00ccb240 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63a88;
void __cdecl FUN_00d91f50();

void __cdecl FUN_00ccb240()
{
    DAT_00f63a88.Setting::Setting();
    atexit(FUN_00d91f50);
}
}

// @f3 0x00ccb6c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb6c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b18;
void __cdecl FUN_00d92010();

void __cdecl FUN_00ccb6c0()
{
    DAT_00f63b18.Setting::Setting();
    atexit(FUN_00d92010);
}
}

// @f3 0x00cce120 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce120 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64064;
void __cdecl FUN_00d92720();

void __cdecl FUN_00cce120()
{
    DAT_00f64064.Setting::Setting();
    atexit(FUN_00d92720);
}
}

// @f3 0x00cc8a20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8a20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63590;
void __cdecl FUN_00d918b0();

void __cdecl FUN_00cc8a20()
{
    DAT_00f63590.Setting::Setting();
    atexit(FUN_00d918b0);
}
}

// @f3 0x00ccddc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccddc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63ff8;
void __cdecl FUN_00d92690();

void __cdecl FUN_00ccddc0()
{
    DAT_00f63ff8.Setting::Setting();
    atexit(FUN_00d92690);
}
}

// @f3 0x00cdeb50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdeb50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f658ac;
void __cdecl FUN_00d94770();

void __cdecl FUN_00cdeb50()
{
    DAT_00f658ac.Setting::Setting();
    atexit(FUN_00d94770);
}
}

// @f3 0x00cce540 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce540 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f640e8;
void __cdecl FUN_00d927d0();

void __cdecl FUN_00cce540()
{
    DAT_00f640e8.Setting::Setting();
    atexit(FUN_00d927d0);
}
}

// @f3 0x00cc42e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc42e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62ca8;
void __cdecl FUN_00d90cd0();

void __cdecl FUN_00cc42e0()
{
    DAT_00f62ca8.Setting::Setting();
    atexit(FUN_00d90cd0);
}
}

// @f3 0x00cc11c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc11c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62660;
void __cdecl FUN_00d90340();

void __cdecl FUN_00cc11c0()
{
    DAT_00f62660.Setting::Setting();
    atexit(FUN_00d90340);
}
}

// @f3 0x00cd53e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd53e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ebc;
void __cdecl FUN_00d93a40();

void __cdecl FUN_00cd53e0()
{
    DAT_00f64ebc.Setting::Setting();
    atexit(FUN_00d93a40);
}
}

// @f3 0x00cd85a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd85a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f654a4;
void __cdecl FUN_00d94220();

void __cdecl FUN_00cd85a0()
{
    DAT_00f654a4.Setting::Setting();
    atexit(FUN_00d94220);
}
}

// @f3 0x00cd35e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd35e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64afc;
void __cdecl FUN_00d93540();

void __cdecl FUN_00cd35e0()
{
    DAT_00f64afc.Setting::Setting();
    atexit(FUN_00d93540);
}
}

// @f3 0x00cc27e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc27e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62924;
void __cdecl FUN_00d906f0();

void __cdecl FUN_00cc27e0()
{
    DAT_00f62924.Setting::Setting();
    atexit(FUN_00d906f0);
}
}

// @f3 0x00cc3200 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a68;
void __cdecl FUN_00d908a0();

void __cdecl FUN_00cc3200()
{
    DAT_00f62a68.Setting::Setting();
    atexit(FUN_00d908a0);
}
}

// @f3 0x00ccd280 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd280 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63e90;
void __cdecl FUN_00d924b0();

void __cdecl FUN_00ccd280()
{
    DAT_00f63e90.Setting::Setting();
    atexit(FUN_00d924b0);
}
}

// @f3 0x00ccb660 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb660 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b0c;
void __cdecl FUN_00d92000();

void __cdecl FUN_00ccb660()
{
    DAT_00f63b0c.Setting::Setting();
    atexit(FUN_00d92000);
}
}

// @f3 0x00cde670 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde670 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65810;
void __cdecl FUN_00d946a0();

void __cdecl FUN_00cde670()
{
    DAT_00f65810.Setting::Setting();
    atexit(FUN_00d946a0);
}
}

// @f3 0x00cd5320 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5320 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ea4;
void __cdecl FUN_00d93a20();

void __cdecl FUN_00cd5320()
{
    DAT_00f64ea4.Setting::Setting();
    atexit(FUN_00d93a20);
}
}

// @f3 0x00ccefc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccefc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64238;
void __cdecl FUN_00d92990();

void __cdecl FUN_00ccefc0()
{
    DAT_00f64238.Setting::Setting();
    atexit(FUN_00d92990);
}
}

// @f3 0x00cdd9c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdd9c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f656a8;
void __cdecl FUN_00d944d0();

void __cdecl FUN_00cdd9c0()
{
    DAT_00f656a8.Setting::Setting();
    atexit(FUN_00d944d0);
}
}

// @f3 0x00cd4a20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4a20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64d84;
void __cdecl FUN_00d938a0();

void __cdecl FUN_00cd4a20()
{
    DAT_00f64d84.Setting::Setting();
    atexit(FUN_00d938a0);
}
}

// @f3 0x00cd1c00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f647c0;
void __cdecl FUN_00d930f0();

void __cdecl FUN_00cd1c00()
{
    DAT_00f647c0.Setting::Setting();
    atexit(FUN_00d930f0);
}
}

// @f3 0x00cd55c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd55c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ef8;
void __cdecl FUN_00d93a90();

void __cdecl FUN_00cd55c0()
{
    DAT_00f64ef8.Setting::Setting();
    atexit(FUN_00d93a90);
}
}

// @f3 0x00ccd3a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd3a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63eb4;
void __cdecl FUN_00d924e0();

void __cdecl FUN_00ccd3a0()
{
    DAT_00f63eb4.Setting::Setting();
    atexit(FUN_00d924e0);
}
}

// @f3 0x00cc0a40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0a40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62570;
void __cdecl FUN_00d90200();

void __cdecl FUN_00cc0a40()
{
    DAT_00f62570.Setting::Setting();
    atexit(FUN_00d90200);
}
}

// @f3 0x00ccb480 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63ad0;
void __cdecl FUN_00d91fb0();

void __cdecl FUN_00ccb480()
{
    DAT_00f63ad0.Setting::Setting();
    atexit(FUN_00d91fb0);
}
}

// @f3 0x00cc6c80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6c80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f631dc;
void __cdecl FUN_00d913c0();

void __cdecl FUN_00cc6c80()
{
    DAT_00f631dc.Setting::Setting();
    atexit(FUN_00d913c0);
}
}

// @f3 0x00cc0f80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0f80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62618;
void __cdecl FUN_00d902e0();

void __cdecl FUN_00cc0f80()
{
    DAT_00f62618.Setting::Setting();
    atexit(FUN_00d902e0);
}
}

// @f3 0x00cd3820 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3820 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64b44;
void __cdecl FUN_00d935a0();

void __cdecl FUN_00cd3820()
{
    DAT_00f64b44.Setting::Setting();
    atexit(FUN_00d935a0);
}
}

// @f3 0x00cc5c60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5c60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62fd8;
void __cdecl FUN_00d91110();

void __cdecl FUN_00cc5c60()
{
    DAT_00f62fd8.Setting::Setting();
    atexit(FUN_00d91110);
}
}

// @f3 0x00cd51a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd51a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64e74;
void __cdecl FUN_00d939e0();

void __cdecl FUN_00cd51a0()
{
    DAT_00f64e74.Setting::Setting();
    atexit(FUN_00d939e0);
}
}

// @f3 0x00cd64a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd64a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65084;
void __cdecl FUN_00d93ca0();

void __cdecl FUN_00cd64a0()
{
    DAT_00f65084.Setting::Setting();
    atexit(FUN_00d93ca0);
}
}

// @f3 0x00cd2ce0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2ce0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f649dc;
void __cdecl FUN_00d933c0();

void __cdecl FUN_00cd2ce0()
{
    DAT_00f649dc.Setting::Setting();
    atexit(FUN_00d933c0);
}
}

// @f3 0x00cd3d00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3d00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64be0;
void __cdecl FUN_00d93670();

void __cdecl FUN_00cd3d00()
{
    DAT_00f64be0.Setting::Setting();
    atexit(FUN_00d93670);
}
}

// @f3 0x00cc1520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f626cc;
void __cdecl FUN_00d903d0();

void __cdecl FUN_00cc1520()
{
    DAT_00f626cc.Setting::Setting();
    atexit(FUN_00d903d0);
}
}

// @f3 0x00ccef60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccef60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6422c;
void __cdecl FUN_00d92980();

void __cdecl FUN_00ccef60()
{
    DAT_00f6422c.Setting::Setting();
    atexit(FUN_00d92980);
}
}

// @f3 0x00ccf380 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf380 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f642b0;
void __cdecl FUN_00d92a30();

void __cdecl FUN_00ccf380()
{
    DAT_00f642b0.Setting::Setting();
    atexit(FUN_00d92a30);
}
}

// @f3 0x00cc5060 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5060 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62e58;
void __cdecl FUN_00d90f10();

void __cdecl FUN_00cc5060()
{
    DAT_00f62e58.Setting::Setting();
    atexit(FUN_00d90f10);
}
}

// @f3 0x00ccf980 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64370;
void __cdecl FUN_00d92b30();

void __cdecl FUN_00ccf980()
{
    DAT_00f64370.Setting::Setting();
    atexit(FUN_00d92b30);
}
}

// @f3 0x00cce2a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce2a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64094;
void __cdecl FUN_00d92760();

void __cdecl FUN_00cce2a0()
{
    DAT_00f64094.Setting::Setting();
    atexit(FUN_00d92760);
}
}

// @f3 0x00cc9bc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9bc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f637c4;
void __cdecl FUN_00d91ba0();

void __cdecl FUN_00cc9bc0()
{
    DAT_00f637c4.Setting::Setting();
    atexit(FUN_00d91ba0);
}
}

// @f3 0x00cc6320 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6320 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f630b0;
void __cdecl FUN_00d91230();

void __cdecl FUN_00cc6320()
{
    DAT_00f630b0.Setting::Setting();
    atexit(FUN_00d91230);
}
}

// @f3 0x00cd28c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd28c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64958;
void __cdecl FUN_00d93310();

void __cdecl FUN_00cd28c0()
{
    DAT_00f64958.Setting::Setting();
    atexit(FUN_00d93310);
}
}

// @f3 0x00cc7700 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7700 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6332c;
void __cdecl FUN_00d91580();

void __cdecl FUN_00cc7700()
{
    DAT_00f6332c.Setting::Setting();
    atexit(FUN_00d91580);
}
}

// @f3 0x00ccd760 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd760 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63f2c;
void __cdecl FUN_00d92580();

void __cdecl FUN_00ccd760()
{
    DAT_00f63f2c.Setting::Setting();
    atexit(FUN_00d92580);
}
}

// @f3 0x00ccf860 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6434c;
void __cdecl FUN_00d92b00();

void __cdecl FUN_00ccf860()
{
    DAT_00f6434c.Setting::Setting();
    atexit(FUN_00d92b00);
}
}

// @f3 0x00cc6da0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6da0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63200;
void __cdecl FUN_00d913f0();

void __cdecl FUN_00cc6da0()
{
    DAT_00f63200.Setting::Setting();
    atexit(FUN_00d913f0);
}
}

// @f3 0x00cc2de0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2de0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f629e4;
void __cdecl FUN_00d907f0();

void __cdecl FUN_00cc2de0()
{
    DAT_00f629e4.Setting::Setting();
    atexit(FUN_00d907f0);
}
}

// @f3 0x00cd84e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd84e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6548c;
void __cdecl FUN_00d94200();

void __cdecl FUN_00cd84e0()
{
    DAT_00f6548c.Setting::Setting();
    atexit(FUN_00d94200);
}
}

// @f3 0x00cd2080 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2080 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64850;
void __cdecl FUN_00d931b0();

void __cdecl FUN_00cd2080()
{
    DAT_00f64850.Setting::Setting();
    atexit(FUN_00d931b0);
}
}

// @f3 0x00cc3620 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3620 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62aec;
void __cdecl FUN_00d90950();

void __cdecl FUN_00cc3620()
{
    DAT_00f62aec.Setting::Setting();
    atexit(FUN_00d90950);
}
}

// @f3 0x00ccfe60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccfe60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6440c;
void __cdecl FUN_00d92c00();

void __cdecl FUN_00ccfe60()
{
    DAT_00f6440c.Setting::Setting();
    atexit(FUN_00d92c00);
}
}

// @f3 0x00cd1a20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1a20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64784;
void __cdecl FUN_00d930a0();

void __cdecl FUN_00cd1a20()
{
    DAT_00f64784.Setting::Setting();
    atexit(FUN_00d930a0);
}
}

// @f3 0x00cca460 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca460 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f638d8;
void __cdecl FUN_00d91d10();

void __cdecl FUN_00cca460()
{
    DAT_00f638d8.Setting::Setting();
    atexit(FUN_00d91d10);
}
}

// @f3 0x00cc7400 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f632cc;
void __cdecl FUN_00d91500();

void __cdecl FUN_00cc7400()
{
    DAT_00f632cc.Setting::Setting();
    atexit(FUN_00d91500);
}
}

// @f3 0x00cd2380 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2380 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f648b0;
void __cdecl FUN_00d93230();

void __cdecl FUN_00cd2380()
{
    DAT_00f648b0.Setting::Setting();
    atexit(FUN_00d93230);
}
}

// @f3 0x00cc21e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc21e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62864;
void __cdecl FUN_00d905f0();

void __cdecl FUN_00cc21e0()
{
    DAT_00f62864.Setting::Setting();
    atexit(FUN_00d905f0);
}
}

// @f3 0x00ccb960 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b6c;
void __cdecl FUN_00d92080();

void __cdecl FUN_00ccb960()
{
    DAT_00f63b6c.Setting::Setting();
    atexit(FUN_00d92080);
}
}

// @f3 0x00cd25c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd25c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f648f8;
void __cdecl FUN_00d93290();

void __cdecl FUN_00cd25c0()
{
    DAT_00f648f8.Setting::Setting();
    atexit(FUN_00d93290);
}
}

// @f3 0x00cc2720 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6290c;
void __cdecl FUN_00d906d0();

void __cdecl FUN_00cc2720()
{
    DAT_00f6290c.Setting::Setting();
    atexit(FUN_00d906d0);
}
}

// @f3 0x00cd15a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd15a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f646f4;
void __cdecl FUN_00d92fe0();

void __cdecl FUN_00cd15a0()
{
    DAT_00f646f4.Setting::Setting();
    atexit(FUN_00d92fe0);
}
}

// @f3 0x00cd63e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd63e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6506c;
void __cdecl FUN_00d93c80();

void __cdecl FUN_00cd63e0()
{
    DAT_00f6506c.Setting::Setting();
    atexit(FUN_00d93c80);
}
}

// @f3 0x00cddf00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cddf00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65750;
void __cdecl FUN_00d945b0();

void __cdecl FUN_00cddf00()
{
    DAT_00f65750.Setting::Setting();
    atexit(FUN_00d945b0);
}
}

// @f3 0x00cd39a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd39a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64b74;
void __cdecl FUN_00d935e0();

void __cdecl FUN_00cd39a0()
{
    DAT_00f64b74.Setting::Setting();
    atexit(FUN_00d935e0);
}
}

// @f3 0x00cd6140 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65018;
void __cdecl FUN_00d93c10();

void __cdecl FUN_00cd6140()
{
    DAT_00f65018.Setting::Setting();
    atexit(FUN_00d93c10);
}
}

// @f3 0x00ccd9a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd9a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63f74;
void __cdecl FUN_00d925e0();

void __cdecl FUN_00ccd9a0()
{
    DAT_00f63f74.Setting::Setting();
    atexit(FUN_00d925e0);
}
}

// @f3 0x00cc1ac0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1ac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62780;
void __cdecl FUN_00d904c0();

void __cdecl FUN_00cc1ac0()
{
    DAT_00f62780.Setting::Setting();
    atexit(FUN_00d904c0);
}
}

// @f3 0x00cd68c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd68c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65108;
void __cdecl FUN_00d93d50();

void __cdecl FUN_00cd68c0()
{
    DAT_00f65108.Setting::Setting();
    atexit(FUN_00d93d50);
}
}

// @f3 0x00ccf560 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf560 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f642ec;
void __cdecl FUN_00d92a80();

void __cdecl FUN_00ccf560()
{
    DAT_00f642ec.Setting::Setting();
    atexit(FUN_00d92a80);
}
}

// @f3 0x00ccdb20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccdb20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63fa4;
void __cdecl FUN_00d92620();

void __cdecl FUN_00ccdb20()
{
    DAT_00f63fa4.Setting::Setting();
    atexit(FUN_00d92620);
}
}

// @f3 0x00cca700 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca700 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6392c;
void __cdecl FUN_00d91d80();

void __cdecl FUN_00cca700()
{
    DAT_00f6392c.Setting::Setting();
    atexit(FUN_00d91d80);
}
}

// @f3 0x00cd58c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd58c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64f58;
void __cdecl FUN_00d93b10();

void __cdecl FUN_00cd58c0()
{
    DAT_00f64f58.Setting::Setting();
    atexit(FUN_00d93b10);
}
}

// @f3 0x00ccbd20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbd20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63be4;
void __cdecl FUN_00d92120();

void __cdecl FUN_00ccbd20()
{
    DAT_00f63be4.Setting::Setting();
    atexit(FUN_00d92120);
}
}

// @f3 0x00cc2360 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62894;
void __cdecl FUN_00d90630();

void __cdecl FUN_00cc2360()
{
    DAT_00f62894.Setting::Setting();
    atexit(FUN_00d90630);
}
}

// @f3 0x00cd7100 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7100 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65210;
void __cdecl FUN_00d93eb0();

void __cdecl FUN_00cd7100()
{
    DAT_00f65210.Setting::Setting();
    atexit(FUN_00d93eb0);
}
}

// @f3 0x00ccc3e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc3e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63cbc;
void __cdecl FUN_00d92240();

void __cdecl FUN_00ccc3e0()
{
    DAT_00f63cbc.Setting::Setting();
    atexit(FUN_00d92240);
}
}

// @f3 0x00cc63e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc63e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f630c8;
void __cdecl FUN_00d91250();

void __cdecl FUN_00cc63e0()
{
    DAT_00f630c8.Setting::Setting();
    atexit(FUN_00d91250);
}
}

// @f3 0x00cc5360 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62eb8;
void __cdecl FUN_00d90f90();

void __cdecl FUN_00cc5360()
{
    DAT_00f62eb8.Setting::Setting();
    atexit(FUN_00d90f90);
}
}

// @f3 0x00cd5e00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5e00 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01073284;
void __cdecl FUN_00d90c00();
}

// pdb: `dynamic initializer for 'iConcentricLengthMaxHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5e00()
{
    f3m_00cd5e00::DAT_01073284.FUN_0043b7f0("iConcentricLengthMaxHard", 200);
    atexit(f3m_00cd5e00::FUN_00d90c00);
}

// @f3 0x00cd42a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd42a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64c94;
void __cdecl FUN_00d93760();

void __cdecl FUN_00cd42a0()
{
    DAT_00f64c94.Setting::Setting();
    atexit(FUN_00d93760);
}
}

// @f3 0x00ccb0c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb0c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63a58;
void __cdecl FUN_00d91f10();

void __cdecl FUN_00ccb0c0()
{
    DAT_00f63a58.Setting::Setting();
    atexit(FUN_00d91f10);
}
}

// @f3 0x00cccf80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccf80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63e30;
void __cdecl FUN_00d92430();

void __cdecl FUN_00cccf80()
{
    DAT_00f63e30.Setting::Setting();
    atexit(FUN_00d92430);
}
}

// @f3 0x00cd5c00 (community match, verified in this file)
class C_010732cc
{
public:
    void __thiscall FUN_0043b7f0(int, int);
};

extern C_010732cc DAT_010732cc;

extern char DAT_00df7dec[];

void __cdecl FUN_00d90b00();
void __cdecl FUN_00c00d1f(void (*)(void));

// pdb: `dynamic initializer for 'iSweetSpotLengthMinAverage'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void FUN_00cd5c00()
{
    DAT_010732cc.FUN_0043b7f0((int)DAT_00df7dec, 0x64);
    FUN_00c00d1f(FUN_00d90b00);
}

// @f3 0x00cccc80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccc80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63dd0;
void __cdecl FUN_00d923b0();

void __cdecl FUN_00cccc80()
{
    DAT_00f63dd0.Setting::Setting();
    atexit(FUN_00d923b0);
}
}

// @f3 0x00cd2aa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2aa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64994;
void __cdecl FUN_00d93360();

void __cdecl FUN_00cd2aa0()
{
    DAT_00f64994.Setting::Setting();
    atexit(FUN_00d93360);
}
}

// @f3 0x00cd8240 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65438;
void __cdecl FUN_00d94190();

void __cdecl FUN_00cd8240()
{
    DAT_00f65438.Setting::Setting();
    atexit(FUN_00d94190);
}
}

// @f3 0x00cd61a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd61a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65024;
void __cdecl FUN_00d93c20();

void __cdecl FUN_00cd61a0()
{
    DAT_00f65024.Setting::Setting();
    atexit(FUN_00d93c20);
}
}

// @f3 0x00cd03a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd03a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f644b4;
void __cdecl FUN_00d92ce0();

void __cdecl FUN_00cd03a0()
{
    DAT_00f644b4.Setting::Setting();
    atexit(FUN_00d92ce0);
}
}

// @f3 0x00cc9f80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9f80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6383c;
void __cdecl FUN_00d91c40();

void __cdecl FUN_00cc9f80()
{
    DAT_00f6383c.Setting::Setting();
    atexit(FUN_00d91c40);
}
}

// @f3 0x00cd5c20 (community match, verified in this file)
class C0043b7f0
{
public:
    void FUN_0043b7f0(const char* a, unsigned int b);
};

extern C0043b7f0 DAT_01073314;
extern char DAT_00df7e08[];
void FUN_00d90b10();
int FUN_00c00d1f(void* f);

// pdb: `dynamic initializer for 'iSweetSpotLengthMinHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void FUN_00cd5c20()
{
    DAT_01073314.FUN_0043b7f0(DAT_00df7e08, 0x32);
    FUN_00c00d1f(FUN_00d90b10);
}

// @f3 0x00cd6020 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6020 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ff4;
void __cdecl FUN_00d93be0();

void __cdecl FUN_00cd6020()
{
    DAT_00f64ff4.Setting::Setting();
    atexit(FUN_00d93be0);
}
}

// @f3 0x00cc5240 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62e94;
void __cdecl FUN_00d90f60();

void __cdecl FUN_00cc5240()
{
    DAT_00f62e94.Setting::Setting();
    atexit(FUN_00d90f60);
}
}

// @f3 0x00cd5f00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5f00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64fd0;
void __cdecl FUN_00d93bb0();

void __cdecl FUN_00cd5f00()
{
    DAT_00f64fd0.Setting::Setting();
    atexit(FUN_00d93bb0);
}
}

// @f3 0x00cc80c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc80c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63464;
void __cdecl FUN_00d91720();

void __cdecl FUN_00cc80c0()
{
    DAT_00f63464.Setting::Setting();
    atexit(FUN_00d91720);
}
}

// @f3 0x00cc8540 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8540 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f634f4;
void __cdecl FUN_00d917e0();

void __cdecl FUN_00cc8540()
{
    DAT_00f634f4.Setting::Setting();
    atexit(FUN_00d917e0);
}
}

// @f3 0x00cd6440 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65078;
void __cdecl FUN_00d93c90();

void __cdecl FUN_00cd6440()
{
    DAT_00f65078.Setting::Setting();
    atexit(FUN_00d93c90);
}
}

// @f3 0x00cd7700 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7700 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f652d0;
void __cdecl FUN_00d93fb0();

void __cdecl FUN_00cd7700()
{
    DAT_00f652d0.Setting::Setting();
    atexit(FUN_00d93fb0);
}
}

// @f3 0x00cd4c00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64dc0;
void __cdecl FUN_00d938f0();

void __cdecl FUN_00cd4c00()
{
    DAT_00f64dc0.Setting::Setting();
    atexit(FUN_00d938f0);
}
}

// @f3 0x00ccc2c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc2c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63c98;
void __cdecl FUN_00d92210();

void __cdecl FUN_00ccc2c0()
{
    DAT_00f63c98.Setting::Setting();
    atexit(FUN_00d92210);
}
}

// @f3 0x00cd6680 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6680 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f650c0;
void __cdecl FUN_00d93cf0();

void __cdecl FUN_00cd6680()
{
    DAT_00f650c0.Setting::Setting();
    atexit(FUN_00d93cf0);
}
}

// @f3 0x00cc2e40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f629f0;
void __cdecl FUN_00d90800();

void __cdecl FUN_00cc2e40()
{
    DAT_00f629f0.Setting::Setting();
    atexit(FUN_00d90800);
}
}

// @f3 0x00cca0a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca0a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63860;
void __cdecl FUN_00d91c70();

void __cdecl FUN_00cca0a0()
{
    DAT_00f63860.Setting::Setting();
    atexit(FUN_00d91c70);
}
}

// @f3 0x00cc1f40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1f40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62810;
void __cdecl FUN_00d90580();

void __cdecl FUN_00cc1f40()
{
    DAT_00f62810.Setting::Setting();
    atexit(FUN_00d90580);
}
}

// @f3 0x00ccf0e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf0e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6425c;
void __cdecl FUN_00d929c0();

void __cdecl FUN_00ccf0e0()
{
    DAT_00f6425c.Setting::Setting();
    atexit(FUN_00d929c0);
}
}

// @f3 0x00cd0e20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd0e20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64604;
void __cdecl FUN_00d92ea0();

void __cdecl FUN_00cd0e20()
{
    DAT_00f64604.Setting::Setting();
    atexit(FUN_00d92ea0);
}
}

// @f3 0x00cc8720 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63530;
void __cdecl FUN_00d91830();

void __cdecl FUN_00cc8720()
{
    DAT_00f63530.Setting::Setting();
    atexit(FUN_00d91830);
}
}

// @f3 0x00cdfad0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdfad0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65efc;
void __cdecl FUN_00d94a40();

void __cdecl FUN_00cdfad0()
{
    DAT_00f65efc.Setting::Setting();
    atexit(FUN_00d94a40);
}
}

// @f3 0x00cc0b00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0b00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62588;
void __cdecl FUN_00d90220();

void __cdecl FUN_00cc0b00()
{
    DAT_00f62588.Setting::Setting();
    atexit(FUN_00d90220);
}
}

// @f3 0x00cce8a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce8a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64154;
void __cdecl FUN_00d92860();

void __cdecl FUN_00cce8a0()
{
    DAT_00f64154.Setting::Setting();
    atexit(FUN_00d92860);
}
}

// @f3 0x00cc02c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc02c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62480;
void __cdecl FUN_00d900c0();

void __cdecl FUN_00cc02c0()
{
    DAT_00f62480.Setting::Setting();
    atexit(FUN_00d900c0);
}
}

// @f3 0x00ccdd60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccdd60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63fec;
void __cdecl FUN_00d92680();

void __cdecl FUN_00ccdd60()
{
    DAT_00f63fec.Setting::Setting();
    atexit(FUN_00d92680);
}
}

// @f3 0x00cce480 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f640d0;
void __cdecl FUN_00d927b0();

void __cdecl FUN_00cce480()
{
    DAT_00f640d0.Setting::Setting();
    atexit(FUN_00d927b0);
}
}

// @f3 0x00cd5d00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5d00 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_010732b4;
void __cdecl FUN_00d90b80();
}

// pdb: `dynamic initializer for 'iConcentricLengthMinVeryEasy'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5d00()
{
    f3m_00cd5d00::DAT_010732b4.FUN_0043b7f0("iConcentricLengthMinVeryEasy", 200);
    atexit(f3m_00cd5d00::FUN_00d90b80);
}

// @f3 0x00cca820 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca820 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63950;
void __cdecl FUN_00d91db0();

void __cdecl FUN_00cca820()
{
    DAT_00f63950.Setting::Setting();
    atexit(FUN_00d91db0);
}
}

// @f3 0x00ccc920 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63d64;
void __cdecl FUN_00d92320();

void __cdecl FUN_00ccc920()
{
    DAT_00f63d64.Setting::Setting();
    atexit(FUN_00d92320);
}
}

// @f3 0x00cc8d80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8d80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f635fc;
void __cdecl FUN_00d91940();

void __cdecl FUN_00cc8d80()
{
    DAT_00f635fc.Setting::Setting();
    atexit(FUN_00d91940);
}
}

// @f3 0x00cc2f60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2f60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a14;
void __cdecl FUN_00d90830();

void __cdecl FUN_00cc2f60()
{
    DAT_00f62a14.Setting::Setting();
    atexit(FUN_00d90830);
}
}

// @f3 0x00cd1b40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1b40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f647a8;
void __cdecl FUN_00d930d0();

void __cdecl FUN_00cd1b40()
{
    DAT_00f647a8.Setting::Setting();
    atexit(FUN_00d930d0);
}
}

// @f3 0x00cd7340 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7340 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65258;
void __cdecl FUN_00d93f10();

void __cdecl FUN_00cd7340()
{
    DAT_00f65258.Setting::Setting();
    atexit(FUN_00d93f10);
}
}

// @f3 0x00cc12e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc12e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62684;
void __cdecl FUN_00d90370();

void __cdecl FUN_00cc12e0()
{
    DAT_00f62684.Setting::Setting();
    atexit(FUN_00d90370);
}
}

// @f3 0x00cc1340 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1340 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62690;
void __cdecl FUN_00d90380();

void __cdecl FUN_00cc1340()
{
    DAT_00f62690.Setting::Setting();
    atexit(FUN_00d90380);
}
}

// @f3 0x00cc1be0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1be0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f627a4;
void __cdecl FUN_00d904f0();

void __cdecl FUN_00cc1be0()
{
    DAT_00f627a4.Setting::Setting();
    atexit(FUN_00d904f0);
}
}

// @f3 0x00cd75e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd75e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f652ac;
void __cdecl FUN_00d93f80();

void __cdecl FUN_00cd75e0()
{
    DAT_00f652ac.Setting::Setting();
    atexit(FUN_00d93f80);
}
}

// @f3 0x00cdfc50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdfc50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65f2c;
void __cdecl FUN_00d94a80();

void __cdecl FUN_00cdfc50()
{
    DAT_00f65f2c.Setting::Setting();
    atexit(FUN_00d94a80);
}
}

// @f3 0x00ccb1e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb1e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63a7c;
void __cdecl FUN_00d91f40();

void __cdecl FUN_00ccb1e0()
{
    DAT_00f63a7c.Setting::Setting();
    atexit(FUN_00d91f40);
}
}

// @f3 0x00ccfbc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccfbc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f643b8;
void __cdecl FUN_00d92b90();

void __cdecl FUN_00ccfbc0()
{
    DAT_00f643b8.Setting::Setting();
    atexit(FUN_00d92b90);
}
}

// @f3 0x00cd3880 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3880 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64b50;
void __cdecl FUN_00d935b0();

void __cdecl FUN_00cd3880()
{
    DAT_00f64b50.Setting::Setting();
    atexit(FUN_00d935b0);
}
}

// @f3 0x00cc20c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc20c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62840;
void __cdecl FUN_00d905c0();

void __cdecl FUN_00cc20c0()
{
    DAT_00f62840.Setting::Setting();
    atexit(FUN_00d905c0);
}
}

// @f3 0x00ccb900 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb900 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b60;
void __cdecl FUN_00d92070();

void __cdecl FUN_00ccb900()
{
    DAT_00f63b60.Setting::Setting();
    atexit(FUN_00d92070);
}
}

// @f3 0x00cc3fe0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3fe0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62c48;
void __cdecl FUN_00d90c50();

void __cdecl FUN_00cc3fe0()
{
    DAT_00f62c48.Setting::Setting();
    atexit(FUN_00d90c50);
}
}

// @f3 0x00cd0d60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd0d60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f645ec;
void __cdecl FUN_00d92e80();

void __cdecl FUN_00cd0d60()
{
    DAT_00f645ec.Setting::Setting();
    atexit(FUN_00d92e80);
}
}

// @f3 0x00cdecd0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdecd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f658dc;
void __cdecl FUN_00d947b0();

void __cdecl FUN_00cdecd0()
{
    DAT_00f658dc.Setting::Setting();
    atexit(FUN_00d947b0);
}
}

// @f3 0x00cd43c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd43c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64cb8;
void __cdecl FUN_00d93790();

void __cdecl FUN_00cd43c0()
{
    DAT_00f64cb8.Setting::Setting();
    atexit(FUN_00d93790);
}
}

// @f3 0x00cc78e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc78e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63368;
void __cdecl FUN_00d915d0();

void __cdecl FUN_00cc78e0()
{
    DAT_00f63368.Setting::Setting();
    atexit(FUN_00d915d0);
}
}

// @f3 0x00ccca40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccca40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63d88;
void __cdecl FUN_00d92350();

void __cdecl FUN_00ccca40()
{
    DAT_00f63d88.Setting::Setting();
    atexit(FUN_00d92350);
}
}

// @f3 0x00ccbb40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbb40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63ba8;
void __cdecl FUN_00d920d0();

void __cdecl FUN_00ccbb40()
{
    DAT_00f63ba8.Setting::Setting();
    atexit(FUN_00d920d0);
}
}

// @f3 0x00ccc440 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63cc8;
void __cdecl FUN_00d92250();

void __cdecl FUN_00ccc440()
{
    DAT_00f63cc8.Setting::Setting();
    atexit(FUN_00d92250);
}
}

// @f3 0x00cd86c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd86c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f654c8;
void __cdecl FUN_00d94250();

void __cdecl FUN_00cd86c0()
{
    DAT_00f654c8.Setting::Setting();
    atexit(FUN_00d94250);
}
}

// @f3 0x00cd71c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd71c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65228;
void __cdecl FUN_00d93ed0();

void __cdecl FUN_00cd71c0()
{
    DAT_00f65228.Setting::Setting();
    atexit(FUN_00d93ed0);
}
}

// @f3 0x00cd2920 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64964;
void __cdecl FUN_00d93320();

void __cdecl FUN_00cd2920()
{
    DAT_00f64964.Setting::Setting();
    atexit(FUN_00d93320);
}
}

// @f3 0x00cc70a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc70a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63260;
void __cdecl FUN_00d91470();

void __cdecl FUN_00cc70a0()
{
    DAT_00f63260.Setting::Setting();
    atexit(FUN_00d91470);
}
}

// @f3 0x00cc4100 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4100 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62c6c;
void __cdecl FUN_00d90c80();

void __cdecl FUN_00cc4100()
{
    DAT_00f62c6c.Setting::Setting();
    atexit(FUN_00d90c80);
}
}

// @f3 0x00cc6980 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6317c;
void __cdecl FUN_00d91340();

void __cdecl FUN_00cc6980()
{
    DAT_00f6317c.Setting::Setting();
    atexit(FUN_00d91340);
}
}

// @f3 0x00cc0140 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62450;
void __cdecl FUN_00d90080();

void __cdecl FUN_00cc0140()
{
    DAT_00f62450.Setting::Setting();
    atexit(FUN_00d90080);
}
}

// @f3 0x00ccbc00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbc00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63bc0;
void __cdecl FUN_00d920f0();

void __cdecl FUN_00ccbc00()
{
    DAT_00f63bc0.Setting::Setting();
    atexit(FUN_00d920f0);
}
}

// @f3 0x00cc5300 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5300 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62eac;
void __cdecl FUN_00d90f80();

void __cdecl FUN_00cc5300()
{
    DAT_00f62eac.Setting::Setting();
    atexit(FUN_00d90f80);
}
}

// @f3 0x00cc77c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc77c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63344;
void __cdecl FUN_00d915a0();

void __cdecl FUN_00cc77c0()
{
    DAT_00f63344.Setting::Setting();
    atexit(FUN_00d915a0);
}
}

// @f3 0x00cc7b20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7b20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f633b0;
void __cdecl FUN_00d91630();

void __cdecl FUN_00cc7b20()
{
    DAT_00f633b0.Setting::Setting();
    atexit(FUN_00d91630);
}
}

// @f3 0x00ccdc40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccdc40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63fc8;
void __cdecl FUN_00d92650();

void __cdecl FUN_00ccdc40()
{
    DAT_00f63fc8.Setting::Setting();
    atexit(FUN_00d92650);
}
}

// @f3 0x00ccce00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccce00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63e00;
void __cdecl FUN_00d923f0();

void __cdecl FUN_00ccce00()
{
    DAT_00f63e00.Setting::Setting();
    atexit(FUN_00d923f0);
}
}

// @f3 0x00ccf6e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf6e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6431c;
void __cdecl FUN_00d92ac0();

void __cdecl FUN_00ccf6e0()
{
    DAT_00f6431c.Setting::Setting();
    atexit(FUN_00d92ac0);
}
}

// @f3 0x00cdf560 (community match, verified in this file)
#include <stdlib.h>
extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void* attributes, long initialCount, long maximumCount, const char* name);
namespace f3m_00cdf560 {
struct Semaphore
{
    volatile int m_iCount;
    int m_iMaxCount;
    void* m_hSemaphore;
    __forceinline Semaphore(int count = 1, int maxCount = 1)
    {
        m_iCount = count;
        m_iMaxCount = maxCount;
        m_hSemaphore = CreateSemaphoreA(0, m_iCount, maxCount, 0);
    }
};
extern Semaphore DAT_01073ae4;
void __cdecl FUN_00d94880();

// pdb: `anonymous namespace'::`dynamic initializer for 'HeadModelArgs'' | BSFaceGenManager.obj | tesv_win, objrun_open, low
void __cdecl FUN_00cdf560()
{
    DAT_01073ae4.Semaphore::Semaphore();
    atexit(FUN_00d94880);
}
}

// @f3 0x00cc7760 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7760 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63338;
void __cdecl FUN_00d91590();

void __cdecl FUN_00cc7760()
{
    DAT_00f63338.Setting::Setting();
    atexit(FUN_00d91590);
}
}

// @f3 0x00cc6b60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6b60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f631b8;
void __cdecl FUN_00d91390();

void __cdecl FUN_00cc6b60()
{
    DAT_00f631b8.Setting::Setting();
    atexit(FUN_00d91390);
}
}

// @f3 0x00cc3140 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a50;
void __cdecl FUN_00d90880();

void __cdecl FUN_00cc3140()
{
    DAT_00f62a50.Setting::Setting();
    atexit(FUN_00d90880);
}
}

// @f3 0x00cd8e40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f655b8;
void __cdecl FUN_00d94390();

void __cdecl FUN_00cd8e40()
{
    DAT_00f655b8.Setting::Setting();
    atexit(FUN_00d94390);
}
}

// @f3 0x00cdf480 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdf480 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, unsigned int a1);
};
extern Setting DAT_01073a14;
void __cdecl FUN_00d94910();
}

// pdb: `dynamic initializer for 'BSFaceGenManager::uiMaxEGMDataSize'' | BSFaceGenManager.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'BSFaceGenManager::bUseRaceMorph'')
void __cdecl FUN_00cdf480()
{
    f3m_00cdf480::DAT_01073a14.FUN_0043b7f0("uiFaceGenMaxEGMDataSize:General", 67108864u);
    atexit(f3m_00cdf480::FUN_00d94910);
}

// @f3 0x00cc4be0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4be0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62dc8;
void __cdecl FUN_00d90e50();

void __cdecl FUN_00cc4be0()
{
    DAT_00f62dc8.Setting::Setting();
    atexit(FUN_00d90e50);
}
}

// @f3 0x00cc6920 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63170;
void __cdecl FUN_00d91330();

void __cdecl FUN_00cc6920()
{
    DAT_00f63170.Setting::Setting();
    atexit(FUN_00d91330);
}
}

// @f3 0x00cc5720 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62f30;
void __cdecl FUN_00d91030();

void __cdecl FUN_00cc5720()
{
    DAT_00f62f30.Setting::Setting();
    atexit(FUN_00d91030);
}
}

// @f3 0x00cd4840 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4840 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64d48;
void __cdecl FUN_00d93850();

void __cdecl FUN_00cd4840()
{
    DAT_00f64d48.Setting::Setting();
    atexit(FUN_00d93850);
}
}

// @f3 0x00cc28a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc28a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6293c;
void __cdecl FUN_00d90710();

void __cdecl FUN_00cc28a0()
{
    DAT_00f6293c.Setting::Setting();
    atexit(FUN_00d90710);
}
}

// @f3 0x00cd4720 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64d24;
void __cdecl FUN_00d93820();

void __cdecl FUN_00cd4720()
{
    DAT_00f64d24.Setting::Setting();
    atexit(FUN_00d93820);
}
}

// @f3 0x00cc7dc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7dc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63404;
void __cdecl FUN_00d916a0();

void __cdecl FUN_00cc7dc0()
{
    DAT_00f63404.Setting::Setting();
    atexit(FUN_00d916a0);
}
}

// @f3 0x00cceea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cceea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64214;
void __cdecl FUN_00d92960();

void __cdecl FUN_00cceea0()
{
    DAT_00f64214.Setting::Setting();
    atexit(FUN_00d92960);
}
}

// @f3 0x00cc1e20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1e20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f627ec;
void __cdecl FUN_00d90550();

void __cdecl FUN_00cc1e20()
{
    DAT_00f627ec.Setting::Setting();
    atexit(FUN_00d90550);
}
}

// @f3 0x00cd8540 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8540 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65498;
void __cdecl FUN_00d94210();

void __cdecl FUN_00cd8540()
{
    DAT_00f65498.Setting::Setting();
    atexit(FUN_00d94210);
}
}

// @f3 0x00cdfdd0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdfdd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65f5c;
void __cdecl FUN_00d94ac0();

void __cdecl FUN_00cdfdd0()
{
    DAT_00f65f5c.Setting::Setting();
    atexit(FUN_00d94ac0);
}
}

// @f3 0x00cd7ac0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7ac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65348;
void __cdecl FUN_00d94050();

void __cdecl FUN_00cd7ac0()
{
    DAT_00f65348.Setting::Setting();
    atexit(FUN_00d94050);
}
}

// @f3 0x00cc62c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc62c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f630a4;
void __cdecl FUN_00d91220();

void __cdecl FUN_00cc62c0()
{
    DAT_00f630a4.Setting::Setting();
    atexit(FUN_00d91220);
}
}

// @f3 0x00cc4880 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4880 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62d5c;
void __cdecl FUN_00d90dc0();

void __cdecl FUN_00cc4880()
{
    DAT_00f62d5c.Setting::Setting();
    atexit(FUN_00d90dc0);
}
}

// @f3 0x00cd37c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd37c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64b38;
void __cdecl FUN_00d93590();

void __cdecl FUN_00cd37c0()
{
    DAT_00f64b38.Setting::Setting();
    atexit(FUN_00d93590);
}
}

// @f3 0x00cd24a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd24a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f648d4;
void __cdecl FUN_00d93260();

void __cdecl FUN_00cd24a0()
{
    DAT_00f648d4.Setting::Setting();
    atexit(FUN_00d93260);
}
}

// @f3 0x00cc9860 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63758;
void __cdecl FUN_00d91b10();

void __cdecl FUN_00cc9860()
{
    DAT_00f63758.Setting::Setting();
    atexit(FUN_00d91b10);
}
}

// @f3 0x00cd4de0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4de0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64dfc;
void __cdecl FUN_00d93940();

void __cdecl FUN_00cd4de0()
{
    DAT_00f64dfc.Setting::Setting();
    atexit(FUN_00d93940);
}
}

// @f3 0x00cc16a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc16a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f626fc;
void __cdecl FUN_00d90410();

void __cdecl FUN_00cc16a0()
{
    DAT_00f626fc.Setting::Setting();
    atexit(FUN_00d90410);
}
}

// @f3 0x00cd3b80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64bb0;
void __cdecl FUN_00d93630();

void __cdecl FUN_00cd3b80()
{
    DAT_00f64bb0.Setting::Setting();
    atexit(FUN_00d93630);
}
}

// @f3 0x00cd5e40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64fb8;
void __cdecl FUN_00d93b90();

void __cdecl FUN_00cd5e40()
{
    DAT_00f64fb8.Setting::Setting();
    atexit(FUN_00d93b90);
}
}

// @f3 0x00cc5c00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62fcc;
void __cdecl FUN_00d91100();

void __cdecl FUN_00cc5c00()
{
    DAT_00f62fcc.Setting::Setting();
    atexit(FUN_00d91100);
}
}

// @f3 0x00ccea80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccea80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64190;
void __cdecl FUN_00d928b0();

void __cdecl FUN_00ccea80()
{
    DAT_00f64190.Setting::Setting();
    atexit(FUN_00d928b0);
}
}

// @f3 0x00ccdb80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccdb80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63fb0;
void __cdecl FUN_00d92630();

void __cdecl FUN_00ccdb80()
{
    DAT_00f63fb0.Setting::Setting();
    atexit(FUN_00d92630);
}
}

// @f3 0x00cd62c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd62c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65048;
void __cdecl FUN_00d93c50();

void __cdecl FUN_00cd62c0()
{
    DAT_00f65048.Setting::Setting();
    atexit(FUN_00d93c50);
}
}

// @f3 0x00cc39e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc39e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62b64;
void __cdecl FUN_00d909f0();

void __cdecl FUN_00cc39e0()
{
    DAT_00f62b64.Setting::Setting();
    atexit(FUN_00d909f0);
}
}

// @f3 0x00cc3260 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3260 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a74;
void __cdecl FUN_00d908b0();

void __cdecl FUN_00cc3260()
{
    DAT_00f62a74.Setting::Setting();
    atexit(FUN_00d908b0);
}
}

// @f3 0x00cc81e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc81e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63488;
void __cdecl FUN_00d91750();

void __cdecl FUN_00cc81e0()
{
    DAT_00f63488.Setting::Setting();
    atexit(FUN_00d91750);
}
}

// @f3 0x00cc7d00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7d00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f633ec;
void __cdecl FUN_00d91680();

void __cdecl FUN_00cc7d00()
{
    DAT_00f633ec.Setting::Setting();
    atexit(FUN_00d91680);
}
}

// @f3 0x00cd7c40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd7c40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65378;
void __cdecl FUN_00d94090();

void __cdecl FUN_00cd7c40()
{
    DAT_00f65378.Setting::Setting();
    atexit(FUN_00d94090);
}
}

// @f3 0x00cc65c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc65c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63104;
void __cdecl FUN_00d912a0();

void __cdecl FUN_00cc65c0()
{
    DAT_00f63104.Setting::Setting();
    atexit(FUN_00d912a0);
}
}

// @f3 0x00cde2b0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde2b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65798;
void __cdecl FUN_00d94600();

void __cdecl FUN_00cde2b0()
{
    DAT_00f65798.Setting::Setting();
    atexit(FUN_00d94600);
}
}

// @f3 0x00cd3160 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3160 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64a6c;
void __cdecl FUN_00d93480();

void __cdecl FUN_00cd3160()
{
    DAT_00f64a6c.Setting::Setting();
    atexit(FUN_00d93480);
}
}

// @f3 0x00cd2bc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2bc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f649b8;
void __cdecl FUN_00d93390();

void __cdecl FUN_00cd2bc0()
{
    DAT_00f649b8.Setting::Setting();
    atexit(FUN_00d93390);
}
}

// @f3 0x00ccf4a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf4a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f642d4;
void __cdecl FUN_00d92a60();

void __cdecl FUN_00ccf4a0()
{
    DAT_00f642d4.Setting::Setting();
    atexit(FUN_00d92a60);
}
}

// @f3 0x00cc30e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc30e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a44;
void __cdecl FUN_00d90870();

void __cdecl FUN_00cc30e0()
{
    DAT_00f62a44.Setting::Setting();
    atexit(FUN_00d90870);
}
}

// @f3 0x00cddea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cddea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65744;
void __cdecl FUN_00d945a0();

void __cdecl FUN_00cddea0()
{
    DAT_00f65744.Setting::Setting();
    atexit(FUN_00d945a0);
}
}

// @f3 0x00cc5d80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5d80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62ffc;
void __cdecl FUN_00d91140();

void __cdecl FUN_00cc5d80()
{
    DAT_00f62ffc.Setting::Setting();
    atexit(FUN_00d91140);
}
}

// @f3 0x00cd2320 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2320 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f648a4;
void __cdecl FUN_00d93220();

void __cdecl FUN_00cd2320()
{
    DAT_00f648a4.Setting::Setting();
    atexit(FUN_00d93220);
}
}

// @f3 0x00cc2600 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f628e8;
void __cdecl FUN_00d906a0();

void __cdecl FUN_00cc2600()
{
    DAT_00f628e8.Setting::Setting();
    atexit(FUN_00d906a0);
}
}

// @f3 0x00cd06a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd06a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64514;
void __cdecl FUN_00d92d60();

void __cdecl FUN_00cd06a0()
{
    DAT_00f64514.Setting::Setting();
    atexit(FUN_00d92d60);
}
}

// @f3 0x00cd01c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd01c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64478;
void __cdecl FUN_00d92c90();

void __cdecl FUN_00cd01c0()
{
    DAT_00f64478.Setting::Setting();
    atexit(FUN_00d92c90);
}
}

// @f3 0x00ccbcc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbcc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63bd8;
void __cdecl FUN_00d92110();

void __cdecl FUN_00ccbcc0()
{
    DAT_00f63bd8.Setting::Setting();
    atexit(FUN_00d92110);
}
}

// @f3 0x00ccb3c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb3c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63ab8;
void __cdecl FUN_00d91f90();

void __cdecl FUN_00ccb3c0()
{
    DAT_00f63ab8.Setting::Setting();
    atexit(FUN_00d91f90);
}
}

// @f3 0x00cddb40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cddb40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f656d8;
void __cdecl FUN_00d94510();

void __cdecl FUN_00cddb40()
{
    DAT_00f656d8.Setting::Setting();
    atexit(FUN_00d94510);
}
}

// @f3 0x00ccfec0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccfec0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64418;
void __cdecl FUN_00d92c10();

void __cdecl FUN_00ccfec0()
{
    DAT_00f64418.Setting::Setting();
    atexit(FUN_00d92c10);
}
}

// @f3 0x00cd4ea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4ea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64e14;
void __cdecl FUN_00d93960();

void __cdecl FUN_00cd4ea0()
{
    DAT_00f64e14.Setting::Setting();
    atexit(FUN_00d93960);
}
}

// @f3 0x00cc5000 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5000 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62e4c;
void __cdecl FUN_00d90f00();

void __cdecl FUN_00cc5000()
{
    DAT_00f62e4c.Setting::Setting();
    atexit(FUN_00d90f00);
}
}

// @f3 0x00cd91a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd91a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65624;
void __cdecl FUN_00d94420();

void __cdecl FUN_00cd91a0()
{
    DAT_00f65624.Setting::Setting();
    atexit(FUN_00d94420);
}
}

// @f3 0x00cc1220 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1220 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6266c;
void __cdecl FUN_00d90350();

void __cdecl FUN_00cc1220()
{
    DAT_00f6266c.Setting::Setting();
    atexit(FUN_00d90350);
}
}

// @f3 0x00cc1280 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1280 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62678;
void __cdecl FUN_00d90360();

void __cdecl FUN_00cc1280()
{
    DAT_00f62678.Setting::Setting();
    atexit(FUN_00d90360);
}
}

// @f3 0x00cd5d20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5d20 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_010732e4;
void __cdecl FUN_00d90b90();
}

// pdb: `dynamic initializer for 'iConcentricLengthMinEasy'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5d20()
{
    f3m_00cd5d20::DAT_010732e4.FUN_0043b7f0("iConcentricLengthMinEasy", 200);
    atexit(f3m_00cd5d20::FUN_00d90b90);
}

// @f3 0x00cd5200 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64e80;
void __cdecl FUN_00d939f0();

void __cdecl FUN_00cd5200()
{
    DAT_00f64e80.Setting::Setting();
    atexit(FUN_00d939f0);
}
}

// @f3 0x00cce300 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce300 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f640a0;
void __cdecl FUN_00d92770();

void __cdecl FUN_00cce300()
{
    DAT_00f640a0.Setting::Setting();
    atexit(FUN_00d92770);
}
}

// @f3 0x00cc6500 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6500 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f630ec;
void __cdecl FUN_00d91280();
}
void __cdecl FUN_00cc6500()
{
    using namespace f3m_00cc6500;
    DAT_00f630ec.Setting::Setting();
    atexit(FUN_00d91280);
}

// @f3 0x00ccaa00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccaa00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6398c;
void __cdecl FUN_00d91e00();

void __cdecl FUN_00ccaa00()
{
    DAT_00f6398c.Setting::Setting();
    atexit(FUN_00d91e00);
}
}

// @f3 0x00cc2d20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2d20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f629cc;
void __cdecl FUN_00d907d0();

void __cdecl FUN_00cc2d20()
{
    DAT_00f629cc.Setting::Setting();
    atexit(FUN_00d907d0);
}
}

// @f3 0x00cc1b80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62798;
void __cdecl FUN_00d904e0();

void __cdecl FUN_00cc1b80()
{
    DAT_00f62798.Setting::Setting();
    atexit(FUN_00d904e0);
}
}

// @f3 0x00cd8960 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6551c;
void __cdecl FUN_00d942c0();

void __cdecl FUN_00cd8960()
{
    DAT_00f6551c.Setting::Setting();
    atexit(FUN_00d942c0);
}
}

// @f3 0x00cc0f20 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f6260c;
namespace f3m_00cc0f20 {
void __cdecl FUN_00d902d0();

void __cdecl FUN_00cc0f20()
{
    DAT_00f6260c.RegistrySetting::RegistrySetting();
    atexit(FUN_00d902d0);
}
}   // namespace f3m_00cc0f20

// @f3 0x00cc35c0 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f62ae0;
namespace f3m_00cc35c0 {
void __cdecl FUN_00d90940();

void __cdecl FUN_00cc35c0()
{
    DAT_00f62ae0.RegistrySetting::RegistrySetting();
    atexit(FUN_00d90940);
}
}   // namespace f3m_00cc35c0

// @f3 0x00cce1e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce1e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6407c;
void __cdecl FUN_00d92740();

void __cdecl FUN_00cce1e0()
{
    DAT_00f6407c.Setting::Setting();
    atexit(FUN_00d92740);
}
}

// @f3 0x00cd1960 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6476c;
void __cdecl FUN_00d93080();

void __cdecl FUN_00cd1960()
{
    DAT_00f6476c.Setting::Setting();
    atexit(FUN_00d93080);
}
}

// @f3 0x00cc3980 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62b58;
void __cdecl FUN_00d909e0();

void __cdecl FUN_00cc3980()
{
    DAT_00f62b58.Setting::Setting();
    atexit(FUN_00d909e0);
}
}

// @f3 0x00cc6200 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6308c;
void __cdecl FUN_00d91200();

void __cdecl FUN_00cc6200()
{
    DAT_00f6308c.Setting::Setting();
    atexit(FUN_00d91200);
}
}

// @f3 0x00ccd8e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd8e0 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f63f5c;
void __cdecl FUN_00403080();
void __cdecl FUN_00d925c0();
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}
void __cdecl FUN_00ccd8e0()
{
    f3m_00ccd8e0::DAT_00f63f5c.f3m_00ccd8e0::SettingRegistration::SettingRegistration();
    atexit(f3m_00ccd8e0::FUN_00d925c0);
}

// @f3 0x00cc23c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_cc23c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f628a0;
void __cdecl FUN_00d90640();

void __cdecl FUN_00cc23c0()
{
    DAT_00f628a0.Setting::Setting();
    atexit(FUN_00d90640);
}
}

// @f3 0x00cd87e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd87e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f654ec;
void __cdecl FUN_00d94280();

void __cdecl FUN_00cd87e0()
{
    DAT_00f654ec.Setting::Setting();
    atexit(FUN_00d94280);
}
}

// @f3 0x00cc3d40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc3d40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62bd0;
void __cdecl FUN_00d90a80();

void __cdecl FUN_00cc3d40()
{
    DAT_00f62bd0.Setting::Setting();
    atexit(FUN_00d90a80);
}
}

// @f3 0x00cc5a20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5a20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62f90;
void __cdecl FUN_00d910b0();

void __cdecl FUN_00cc5a20()
{
    DAT_00f62f90.Setting::Setting();
    atexit(FUN_00d910b0);
}
}

// @f3 0x00ccab80 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f639b0;
namespace f3m_00ccab80 {
void __cdecl FUN_00d91e30();

void __cdecl FUN_00ccab80()
{
    DAT_00f639b0.RegistrySetting::RegistrySetting();
    atexit(FUN_00d91e30);
}
}   // namespace f3m_00ccab80

// @f3 0x00cc90e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc90e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63668;
void __cdecl FUN_00d919d0();

void __cdecl FUN_00cc90e0()
{
    DAT_00f63668.Setting::Setting();
    atexit(FUN_00d919d0);
}
}

// @f3 0x00cd20e0 (community match, verified in this file)
namespace f3m_00cd20e0 {

struct RegistrySetting;
struct Manager { virtual void v00(); virtual void Register(RegistrySetting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct RegistrySetting : Cleanup {
    __forceinline RegistrySetting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern RegistrySetting DAT_00f6485c;
void __cdecl FUN_00d931c0();
void __cdecl FUN_00cd20e0()
{
    DAT_00f6485c.RegistrySetting::RegistrySetting();
    atexit(FUN_00d931c0);
}
}   // namespace f3m_00cd20e0

// @f3 0x00cdfb90 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f65f14;
namespace f3m_00cdfb90 {
void __cdecl FUN_00d94a60();

void __cdecl FUN_00cdfb90()
{
    DAT_00f65f14.RegistrySetting::RegistrySetting();
    atexit(FUN_00d94a60);
}
}   // namespace f3m_00cdfb90

// @f3 0x00cdd900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdd900 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65690;
void __cdecl FUN_00d944b0();

void __cdecl FUN_00cdd900()
{
    DAT_00f65690.Setting::Setting();
    atexit(FUN_00d944b0);
}
}

// @f3 0x00cdd8a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdd8a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65684;
void __cdecl FUN_00d944a0();

void __cdecl FUN_00cdd8a0()
{
    DAT_00f65684.Setting::Setting();
    atexit(FUN_00d944a0);
}
}

// @f3 0x00cddcc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cddcc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65708;
void __cdecl FUN_00d94550();

void __cdecl FUN_00cddcc0()
{
    DAT_00f65708.Setting::Setting();
    atexit(FUN_00d94550);
}
}

// @f3 0x00ccd5e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd5e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63efc;
void __cdecl FUN_00d92540();

void __cdecl FUN_00ccd5e0()
{
    DAT_00f63efc.Setting::Setting();
    atexit(FUN_00d92540);
}
}

// @f3 0x00cc0860 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_mine {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62534;
void __cdecl FUN_00d901b0();

void __cdecl FUN_00cc0860()
{
    DAT_00f62534.Setting::Setting();
    atexit(FUN_00d901b0);
}
}

// @f3 0x00cce780 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce780 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64130;
void __cdecl FUN_00d92830();

void __cdecl FUN_00cce780()
{
    DAT_00f64130.Setting::Setting();
    atexit(FUN_00d92830);
}
}

// @f3 0x00cd6fe0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd6fe0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f651ec;
void __cdecl FUN_00d93e80();

void __cdecl FUN_00cd6fe0()
{
    DAT_00f651ec.Setting::Setting();
    atexit(FUN_00d93e80);
}
}

// @f3 0x00cc4820 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4820 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62d50;
void __cdecl FUN_00d90db0();

void __cdecl FUN_00cc4820()
{
    DAT_00f62d50.Setting::Setting();
    atexit(FUN_00d90db0);
}
}

// @f3 0x00cc64a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc64a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f630e0;
void __cdecl FUN_00d91270();

void __cdecl FUN_00cc64a0()
{
    DAT_00f630e0.Setting::Setting();
    atexit(FUN_00d91270);
}
}

// @f3 0x00ccd7c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd7c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63f38;
void __cdecl FUN_00d92590();
}

void __cdecl FUN_00ccd7c0()
{
    f3m_00ccd7c0::DAT_00f63f38.f3m_00ccd7c0::Setting::Setting();
    atexit(f3m_00ccd7c0::FUN_00d92590);
}

// @f3 0x00ccfb60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccfb60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f643ac;
void __cdecl FUN_00d92b80();

void __cdecl FUN_00ccfb60()
{
    DAT_00f643ac.Setting::Setting();
    atexit(FUN_00d92b80);
}
}

// @f3 0x00cc4640 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4640 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62d14;
void __cdecl FUN_00d90d60();

void __cdecl FUN_00cc4640()
{
    DAT_00f62d14.Setting::Setting();
    atexit(FUN_00d90d60);
}
}

// @f3 0x00cc8de0 (community match, verified in this file)
#include <stdlib.h>
namespace my_cc8de0 {
struct GSetting;
struct GManager { virtual void v00(); virtual void Register(GSetting* setting); };
extern GManager* DAT_010701a8;
void FUN_00403080();
struct GCleanup {
    void FUN_00403170();
    __forceinline ~GCleanup() { FUN_00403170(); }
};
struct GSetting : GCleanup {
    __forceinline GSetting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern GSetting DAT_00f63608;
void __cdecl FUN_00d91950();

void __cdecl FUN_00cc8de0()
{
    DAT_00f63608.GSetting::GSetting();
    atexit(FUN_00d91950);
}
}

// @f3 0x00cd2e00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2e00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64a00;
void __cdecl FUN_00d933f0();

void __cdecl FUN_00cd2e00()
{
    DAT_00f64a00.Setting::Setting();
    atexit(FUN_00d933f0);
}
}

// @f3 0x00cd3b20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3b20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ba4;
void __cdecl FUN_00d93620();

void __cdecl FUN_00cd3b20()
{
    DAT_00f64ba4.Setting::Setting();
    atexit(FUN_00d93620);
}
}

// @f3 0x00ccb300 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb300 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63aa0;
void __cdecl FUN_00d91f70();

void __cdecl FUN_00ccb300()
{
    DAT_00f63aa0.Setting::Setting();
    atexit(FUN_00d91f70);
}
}

// @f3 0x00cd5b00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5b00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64fa0;
void __cdecl FUN_00d93b70();

void __cdecl FUN_00cd5b00()
{
    DAT_00f64fa0.Setting::Setting();
    atexit(FUN_00d93b70);
}
}

// @f3 0x00cc4d00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc4d00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62dec;
void __cdecl FUN_00d90e80();

void __cdecl FUN_00cc4d00()
{
    DAT_00f62dec.Setting::Setting();
    atexit(FUN_00d90e80);
}
}

// @f3 0x00cd4420 (community match, verified in this file)
#include <stdlib.h>
namespace n4420 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline Cleanup() {}
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64cc4;
void __cdecl FUN_00d937a0();

void __cdecl FUN_00cd4420()
{
    DAT_00f64cc4.Setting::Setting();
    atexit(FUN_00d937a0);
}
}

// @f3 0x00cd1ea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1ea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64814;
void __cdecl FUN_00d93160();

void __cdecl FUN_00cd1ea0()
{
    DAT_00f64814.Setting::Setting();
    atexit(FUN_00d93160);
}
}

// @f3 0x00cd4480 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4480 {
struct Setting2;
struct Manager2 { virtual void v00(); virtual void Register(Setting2* setting); };
extern Manager2* DAT_010701a8;
void FUN_00403080();
struct Cleanup2 {
    void FUN_00403170();
    __forceinline ~Cleanup2() { FUN_00403170(); }
};
struct Setting2 : Cleanup2 {
    __forceinline Setting2() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting2 DAT_00f64cd0;
void __cdecl FUN_00d937b0();

void __cdecl FUN_00cd4480()
{
    DAT_00f64cd0.Setting2::Setting2();
    atexit(FUN_00d937b0);
}
}

// @f3 0x00cc1a60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1a60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62774;
void __cdecl FUN_00d904b0();

void __cdecl FUN_00cc1a60()
{
    DAT_00f62774.Setting::Setting();
    atexit(FUN_00d904b0);
}
}

// @f3 0x00cd4240 (community match, verified in this file)
#include <stdlib.h>
#include <new>
namespace f3m_00cd4240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64c88;
void __cdecl FUN_00d93750();

void __cdecl FUN_00cd4240()
{
    DAT_00f64c88.Setting::Setting();
    atexit(FUN_00d93750);
}
}

// @f3 0x00ccc860 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63d4c;
void __cdecl FUN_00d92300();

void __cdecl FUN_00ccc860()
{
    DAT_00f63d4c.Setting::Setting();
    atexit(FUN_00d92300);
}
}

// @f3 0x00cd8f60 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f655dc;
namespace f3m_00cd8f60 {
void __cdecl FUN_00d943c0();

void __cdecl FUN_00cd8f60()
{
    DAT_00f655dc.RegistrySetting::RegistrySetting();
    atexit(FUN_00d943c0);
}
}   // namespace f3m_00cd8f60

// @f3 0x00cc5ea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5ea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63020;
void __cdecl FUN_00d91170();

void __cdecl FUN_00cc5ea0()
{
    DAT_00f63020.Setting::Setting();
    atexit(FUN_00d91170);
}
}

// @f3 0x00cd2980 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f64970;
namespace f3m_00cd2980 {
void __cdecl FUN_00d93330();

void __cdecl FUN_00cd2980()
{
    DAT_00f64970.RegistrySetting::RegistrySetting();
    atexit(FUN_00d93330);
}
}   // namespace f3m_00cd2980

// @f3 0x00cd9020 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd9020 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f655f4;
void __cdecl FUN_00d943e0();

void __cdecl FUN_00cd9020()
{
    DAT_00f655f4.Setting::Setting();
    atexit(FUN_00d943e0);
}
}

// @f3 0x00ccfd40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccfd40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f643e8;
void __cdecl FUN_00d92bd0();

void __cdecl FUN_00ccfd40()
{
    DAT_00f643e8.Setting::Setting();
    atexit(FUN_00d92bd0);
}
}

// @f3 0x00cc4c40 (community match, verified in this file)
namespace f3m_b1156 {
#include <stdlib.h>
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62dd4;
void __cdecl FUN_00d90e60();

void __cdecl FUN_00cc4c40()
{
    DAT_00f62dd4.Setting::Setting();
    atexit(FUN_00d90e60);
}
}

// @f3 0x00ccf740 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf740 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64328;
void __cdecl FUN_00d92ad0();

void __cdecl FUN_00ccf740()
{
    DAT_00f64328.Setting::Setting();
    atexit(FUN_00d92ad0);
}
}

// @f3 0x00cccfe0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cccfe0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63e3c;
void __cdecl FUN_00d92440();

void __cdecl FUN_00cccfe0()
{
    DAT_00f63e3c.Setting::Setting();
    atexit(FUN_00d92440);
}
}

// @f3 0x00cca6a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca6a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63920;
void __cdecl FUN_00d91d70();

void __cdecl FUN_00cca6a0()
{
    DAT_00f63920.Setting::Setting();
    atexit(FUN_00d91d70);
}
}

// @f3 0x00cce960 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6416c;
void __cdecl FUN_00d92880();

void __cdecl FUN_00cce960()
{
    DAT_00f6416c.Setting::Setting();
    atexit(FUN_00d92880);
}
}

// @f3 0x00cc13a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc13a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6269c;
void __cdecl FUN_00d90390();

void __cdecl FUN_00cc13a0()
{
    DAT_00f6269c.Setting::Setting();
    atexit(FUN_00d90390);
}
}

// @f3 0x00cd23e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd23e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f648bc;
void __cdecl FUN_00d93240();

void __cdecl FUN_00cd23e0()
{
    DAT_00f648bc.Setting::Setting();
    atexit(FUN_00d93240);
}
}

// @f3 0x00cd8360 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6545c;
void __cdecl FUN_00d941c0();

void __cdecl FUN_00cd8360()
{
    DAT_00f6545c.Setting::Setting();
    atexit(FUN_00d941c0);
}
}

// @f3 0x00cd1480 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd1480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f646d0;
void __cdecl FUN_00d92fb0();

void __cdecl FUN_00cd1480()
{
    DAT_00f646d0.Setting::Setting();
    atexit(FUN_00d92fb0);
}
}

// @f3 0x00cc3080 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_x {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a38;
void __cdecl FUN_00d90860();

void __cdecl FUN_00cc3080()
{
    DAT_00f62a38.Setting::Setting();
    atexit(FUN_00d90860);
}
}

// @f3 0x00cc93e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc93e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f636c8;
void __cdecl FUN_00d91a50();

void __cdecl FUN_00cc93e0()
{
    DAT_00f636c8.Setting::Setting();
    atexit(FUN_00d91a50);
}
}

// @f3 0x00cc1ee0 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f62804;
namespace f3m_00cc1ee0 {
void __cdecl FUN_00d90570();

void __cdecl FUN_00cc1ee0()
{
    DAT_00f62804.RegistrySetting::RegistrySetting();
    atexit(FUN_00d90570);
}
}   // namespace f3m_00cc1ee0

// @f3 0x00cd6740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6740 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f650d8;
void __cdecl FUN_00d93d10();
}

void __cdecl FUN_00cd6740()
{
    using namespace f3m_00cd6740;
    DAT_00f650d8.Setting::Setting();
    atexit(FUN_00d93d10);
}

// @f3 0x00cc7040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7040 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63254;
void __cdecl FUN_00d91460();
}

void __cdecl FUN_00cc7040()
{
    using namespace f3m_00cc7040;
    DAT_00f63254.Setting::Setting();
    atexit(FUN_00d91460);
}

// @f3 0x00cd1e40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1e40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64808;
void __cdecl FUN_00d93150();
}

void __cdecl FUN_00cd1e40()
{
    using namespace f3m_00cd1e40;
    DAT_00f64808.Setting::Setting();
    atexit(FUN_00d93150);
}

// @f3 0x00cd5c80 (community match, verified in this file)
namespace f3m_00cd5c80 {
class Standin_010732a8
{
public:
    void FUN_0043b7f0(int a, int b);
};
extern Standin_010732a8 DAT_010732a8;

extern "C" void __cdecl FUN_00c00d1f(void (__cdecl* fn)(void));
void FUN_00d90b40();

// pdb: `dynamic initializer for 'iSweetSpotLengthMaxEasy'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void FUN_00cd5c80()
{
    DAT_010732a8.FUN_0043b7f0(0xdf7e58, 0xc8);
    FUN_00c00d1f(FUN_00d90b40);
}
}   // namespace f3m_00cd5c80

// @f3 0x00cc0980 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0980 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62558;
void __cdecl FUN_00d901e0();
}

void __cdecl FUN_00cc0980()
{
    using namespace f3m_00cc0980;
    DAT_00f62558.Setting::Setting();
    atexit(FUN_00d901e0);
}

// @f3 0x00cde8b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde8b0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65858;
void __cdecl FUN_00d94700();
}

void __cdecl FUN_00cde8b0()
{
    using namespace f3m_00cde8b0;
    DAT_00f65858.Setting::Setting();
    atexit(FUN_00d94700);
}

// @f3 0x00cd0d00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0d00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f645e0;
void __cdecl FUN_00d92e70();
}

void __cdecl FUN_00cd0d00()
{
    using namespace f3m_00cd0d00;
    DAT_00f645e0.Setting::Setting();
    atexit(FUN_00d92e70);
}

// @f3 0x00cd19c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd19c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64778;
void __cdecl FUN_00d93090();
}

void __cdecl FUN_00cd19c0()
{
    using namespace f3m_00cd19c0;
    DAT_00f64778.Setting::Setting();
    atexit(FUN_00d93090);
}

// @f3 0x00cc3560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3560 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ad4;
void __cdecl FUN_00d90930();
}

void __cdecl FUN_00cc3560()
{
    using namespace f3m_00cc3560;
    DAT_00f62ad4.Setting::Setting();
    atexit(FUN_00d90930);
}

// @f3 0x00ccc680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc680 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63d10;
void __cdecl FUN_00d922b0();
}

void __cdecl FUN_00ccc680()
{
    using namespace f3m_00ccc680;
    DAT_00f63d10.Setting::Setting();
    atexit(FUN_00d922b0);
}

// @f3 0x00cc9b00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9b00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f637ac;
void __cdecl FUN_00d91b80();
}

void __cdecl FUN_00cc9b00()
{
    using namespace f3m_00cc9b00;
    DAT_00f637ac.Setting::Setting();
    atexit(FUN_00d91b80);
}

// @f3 0x00ccfce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccfce0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f643dc;
void __cdecl FUN_00d92bc0();
}

void __cdecl FUN_00ccfce0()
{
    using namespace f3m_00ccfce0;
    DAT_00f643dc.Setting::Setting();
    atexit(FUN_00d92bc0);
}

// @f3 0x00cd92c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd92c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65648;
void __cdecl FUN_00d94450();
}

void __cdecl FUN_00cd92c0()
{
    using namespace f3m_00cd92c0;
    DAT_00f65648.Setting::Setting();
    atexit(FUN_00d94450);
}

// @f3 0x00cd07c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd07c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64538;
void __cdecl FUN_00d92d90();
}

void __cdecl FUN_00cd07c0()
{
    using namespace f3m_00cd07c0;
    DAT_00f64538.Setting::Setting();
    atexit(FUN_00d92d90);
}

// @f3 0x00cc1b20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1b20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6278c;
void __cdecl FUN_00d904d0();
}

void __cdecl FUN_00cc1b20()
{
    using namespace f3m_00cc1b20;
    DAT_00f6278c.Setting::Setting();
    atexit(FUN_00d904d0);
}

// @f3 0x00cce240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce240 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64088;
void __cdecl FUN_00d92750();
}

void __cdecl FUN_00cce240()
{
    using namespace f3m_00cce240;
    DAT_00f64088.Setting::Setting();
    atexit(FUN_00d92750);
}

// @f3 0x00ccd100 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd100 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63e60;
void __cdecl FUN_00d92470();
}

void __cdecl FUN_00ccd100()
{
    using namespace f3m_00ccd100;
    DAT_00f63e60.Setting::Setting();
    atexit(FUN_00d92470);
}

// @f3 0x00cd5080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5080 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64e50;
void __cdecl FUN_00d939b0();
}

void __cdecl FUN_00cd5080()
{
    using namespace f3m_00cd5080;
    DAT_00f64e50.Setting::Setting();
    atexit(FUN_00d939b0);
}

// @f3 0x00ccac40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccac40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f639c8;
void __cdecl FUN_00d91e50();
}

void __cdecl FUN_00ccac40()
{
    using namespace f3m_00ccac40;
    DAT_00f639c8.Setting::Setting();
    atexit(FUN_00d91e50);
}

// @f3 0x00cc86c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc86c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63524;
void __cdecl FUN_00d91820();
}

void __cdecl FUN_00cc86c0()
{
    using namespace f3m_00cc86c0;
    DAT_00f63524.Setting::Setting();
    atexit(FUN_00d91820);
}

// @f3 0x00cc5480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5480 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62edc;
void __cdecl FUN_00d90fc0();
}

void __cdecl FUN_00cc5480()
{
    using namespace f3m_00cc5480;
    DAT_00f62edc.Setting::Setting();
    atexit(FUN_00d90fc0);
}

// @f3 0x00cc61a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc61a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63080;
void __cdecl FUN_00d911f0();
}

void __cdecl FUN_00cc61a0()
{
    using namespace f3m_00cc61a0;
    DAT_00f63080.Setting::Setting();
    atexit(FUN_00d911f0);
}

// @f3 0x00ccfaa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccfaa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64394;
void __cdecl FUN_00d92b60();
}

void __cdecl FUN_00ccfaa0()
{
    using namespace f3m_00ccfaa0;
    DAT_00f64394.Setting::Setting();
    atexit(FUN_00d92b60);
}

// @f3 0x00cc8420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8420 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f634d0;
void __cdecl FUN_00d917b0();
}

void __cdecl FUN_00cc8420()
{
    using namespace f3m_00cc8420;
    DAT_00f634d0.Setting::Setting();
    atexit(FUN_00d917b0);
}

// @f3 0x00cd6b60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6b60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6515c;
void __cdecl FUN_00d93dc0();
}

void __cdecl FUN_00cd6b60()
{
    using namespace f3m_00cd6b60;
    DAT_00f6515c.Setting::Setting();
    atexit(FUN_00d93dc0);
}

// @f3 0x00ccb360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb360 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63aac;
void __cdecl FUN_00d91f80();
}

void __cdecl FUN_00ccb360()
{
    using namespace f3m_00ccb360;
    DAT_00f63aac.Setting::Setting();
    atexit(FUN_00d91f80);
}

// @f3 0x00cc7640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7640 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63314;
void __cdecl FUN_00d91560();
}

void __cdecl FUN_00cc7640()
{
    using namespace f3m_00cc7640;
    DAT_00f63314.Setting::Setting();
    atexit(FUN_00d91560);
}

// @f3 0x00cc29c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc29c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62960;
void __cdecl FUN_00d90740();
}

void __cdecl FUN_00cc29c0()
{
    using namespace f3m_00cc29c0;
    DAT_00f62960.Setting::Setting();
    atexit(FUN_00d90740);
}

// @f3 0x00cc4940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4940 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62d74;
void __cdecl FUN_00d90de0();
}

void __cdecl FUN_00cc4940()
{
    using namespace f3m_00cc4940;
    DAT_00f62d74.Setting::Setting();
    atexit(FUN_00d90de0);
}

// @f3 0x00cd3e80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3e80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c10;
void __cdecl FUN_00d936b0();
}

void __cdecl FUN_00cd3e80()
{
    using namespace f3m_00cd3e80;
    DAT_00f64c10.Setting::Setting();
    atexit(FUN_00d936b0);
}

// @f3 0x00ccae80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccae80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a10;
void __cdecl FUN_00d91eb0();
}

void __cdecl FUN_00ccae80()
{
    using namespace f3m_00ccae80;
    DAT_00f63a10.Setting::Setting();
    atexit(FUN_00d91eb0);
}

// @f3 0x00cd81e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd81e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6542c;
void __cdecl FUN_00d94180();
}

void __cdecl FUN_00cd81e0()
{
    using namespace f3m_00cd81e0;
    DAT_00f6542c.Setting::Setting();
    atexit(FUN_00d94180);
}

// @f3 0x00cc19a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc19a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6275c;
void __cdecl FUN_00d90490();
}

void __cdecl FUN_00cc19a0()
{
    using namespace f3m_00cc19a0;
    DAT_00f6275c.Setting::Setting();
    atexit(FUN_00d90490);
}

// @f3 0x00cd6800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6800 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f650f0;
void __cdecl FUN_00d93d30();
}

void __cdecl FUN_00cd6800()
{
    using namespace f3m_00cd6800;
    DAT_00f650f0.Setting::Setting();
    atexit(FUN_00d93d30);
}

// @f3 0x00cd1f60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1f60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6482c;
void __cdecl FUN_00d93180();
}

void __cdecl FUN_00cd1f60()
{
    using namespace f3m_00cd1f60;
    DAT_00f6482c.Setting::Setting();
    atexit(FUN_00d93180);
}

// @f3 0x00cc0bc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0bc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f625a0;
void __cdecl FUN_00d90240();
}

void __cdecl FUN_00cc0bc0()
{
    using namespace f3m_00cc0bc0;
    DAT_00f625a0.Setting::Setting();
    atexit(FUN_00d90240);
}

// @f3 0x00ccd400 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd400 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63ec0;
void __cdecl FUN_00d924f0();
}

void __cdecl FUN_00ccd400()
{
    using namespace f3m_00ccd400;
    DAT_00f63ec0.Setting::Setting();
    atexit(FUN_00d924f0);
}

// @f3 0x00ccfb00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccfb00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f643a0;
void __cdecl FUN_00d92b70();
}

void __cdecl FUN_00ccfb00()
{
    using namespace f3m_00ccfb00;
    DAT_00f643a0.Setting::Setting();
    atexit(FUN_00d92b70);
}

// @f3 0x00cd4f60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4f60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64e2c;
void __cdecl FUN_00d93980();
}

void __cdecl FUN_00cd4f60()
{
    using namespace f3m_00cd4f60;
    DAT_00f64e2c.Setting::Setting();
    atexit(FUN_00d93980);
}

// @f3 0x00cc8360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8360 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f634b8;
void __cdecl FUN_00d91790();
}

void __cdecl FUN_00cc8360()
{
    using namespace f3m_00cc8360;
    DAT_00f634b8.Setting::Setting();
    atexit(FUN_00d91790);
}

// @f3 0x00cc7220 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7220 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63290;
void __cdecl FUN_00d914b0();
}

void __cdecl FUN_00cc7220()
{
    using namespace f3m_00cc7220;
    DAT_00f63290.Setting::Setting();
    atexit(FUN_00d914b0);
}

// @f3 0x00ccf9e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf9e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6437c;
void __cdecl FUN_00d92b40();
}

void __cdecl FUN_00ccf9e0()
{
    using namespace f3m_00ccf9e0;
    DAT_00f6437c.Setting::Setting();
    atexit(FUN_00d92b40);
}

// @f3 0x00cc4ac0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4ac0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62da4;
void __cdecl FUN_00d90e20();
}

void __cdecl FUN_00cc4ac0()
{
    using namespace f3m_00cc4ac0;
    DAT_00f62da4.Setting::Setting();
    atexit(FUN_00d90e20);
}

// @f3 0x00cc7c40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7c40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f633d4;
void __cdecl FUN_00d91660();
}

void __cdecl FUN_00cc7c40()
{
    using namespace f3m_00cc7c40;
    DAT_00f633d4.Setting::Setting();
    atexit(FUN_00d91660);
}

// @f3 0x00cc3020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3020 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62a2c;
void __cdecl FUN_00d90850();
}

void __cdecl FUN_00cc3020()
{
    using namespace f3m_00cc3020;
    DAT_00f62a2c.Setting::Setting();
    atexit(FUN_00d90850);
}

// @f3 0x00cd2e60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2e60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a0c;
void __cdecl FUN_00d93400();
}

void __cdecl FUN_00cd2e60()
{
    using namespace f3m_00cd2e60;
    DAT_00f64a0c.Setting::Setting();
    atexit(FUN_00d93400);
}

// @f3 0x00ccede0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccede0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f641fc;
void __cdecl FUN_00d92940();
}

void __cdecl FUN_00ccede0()
{
    f3m_00ccede0::DAT_00f641fc.Setting::Setting();
    atexit(f3m_00ccede0::FUN_00d92940);
}

// @f3 0x00cdea90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdea90 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65894;
void __cdecl FUN_00d94750();
}

void __cdecl FUN_00cdea90()
{
    f3m_00cdea90::DAT_00f65894.Setting::Setting();
    atexit(f3m_00cdea90::FUN_00d94750);
}

// @f3 0x00cd1060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1060 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6464c;
void __cdecl FUN_00d92f00();
}

void __cdecl FUN_00cd1060()
{
    f3m_00cd1060::DAT_00f6464c.Setting::Setting();
    atexit(f3m_00cd1060::FUN_00d92f00);
}

// @f3 0x00ccec00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccec00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f641c0;
void __cdecl FUN_00d928f0();
}

void __cdecl FUN_00ccec00()
{
    f3m_00ccec00::DAT_00f641c0.Setting::Setting();
    atexit(f3m_00ccec00::FUN_00d928f0);
}

// @f3 0x00cc2cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2cc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f629c0;
void __cdecl FUN_00d907c0();
}

void __cdecl FUN_00cc2cc0()
{
    f3m_00cc2cc0::DAT_00f629c0.Setting::Setting();
    atexit(f3m_00cc2cc0::FUN_00d907c0);
}

// @f3 0x00cc0090 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0090 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62438;
void __cdecl FUN_00d90070();
}

void __cdecl FUN_00cc0090()
{
    f3m_00cc0090::DAT_00f62438.Setting::Setting();
    atexit(f3m_00cc0090::FUN_00d90070);
}

// @f3 0x00cc8ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8ba0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f635c0;
void __cdecl FUN_00d918f0();
}

void __cdecl FUN_00cc8ba0()
{
    f3m_00cc8ba0::DAT_00f635c0.Setting::Setting();
    atexit(f3m_00cc8ba0::FUN_00d918f0);
}

// @f3 0x00cc8300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8300 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f634ac;
void __cdecl FUN_00d91780();
}

void __cdecl FUN_00cc8300()
{
    f3m_00cc8300::DAT_00f634ac.Setting::Setting();
    atexit(f3m_00cc8300::FUN_00d91780);
}

// @f3 0x00cd2200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2200 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64880;
void __cdecl FUN_00d931f0();
}

void __cdecl FUN_00cd2200()
{
    f3m_00cd2200::DAT_00f64880.Setting::Setting();
    atexit(f3m_00cd2200::FUN_00d931f0);
}

// @f3 0x00cccc20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cccc20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63dc4;
void __cdecl FUN_00d923a0();
}

void __cdecl FUN_00cccc20()
{
    f3m_00cccc20::DAT_00f63dc4.Setting::Setting();
    atexit(f3m_00cccc20::FUN_00d923a0);
}

// @f3 0x00cc99e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc99e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63788;
void __cdecl FUN_00d91b50();
}

void __cdecl FUN_00cc99e0()
{
    f3m_00cc99e0::DAT_00f63788.Setting::Setting();
    atexit(f3m_00cc99e0::FUN_00d91b50);
}

// @f3 0x00cc17c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc17c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62720;
void __cdecl FUN_00d90440();
}

void __cdecl FUN_00cc17c0()
{
    f3m_00cc17c0::DAT_00f62720.Setting::Setting();
    atexit(f3m_00cc17c0::FUN_00d90440);
}

// @f3 0x00ccd0a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd0a0
{
struct Setting;
struct Manager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup
{
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};
extern Setting DAT_00f63e54;
void __cdecl FUN_00d92460();
}

void __cdecl FUN_00ccd0a0()
{
    f3m_00ccd0a0::DAT_00f63e54.f3m_00ccd0a0::Setting::Setting();
    atexit(f3m_00ccd0a0::FUN_00d92460);
}

// @f3 0x00cd0fa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0fa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64634;
void __cdecl FUN_00d92ee0();
}

void __cdecl FUN_00cd0fa0()
{
    f3m_00cd0fa0::DAT_00f64634.Setting::Setting();
    atexit(f3m_00cd0fa0::FUN_00d92ee0);
}

// @f3 0x00cd1fc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1fc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64838;
void __cdecl FUN_00d93190();
}

void __cdecl FUN_00cd1fc0()
{
    f3m_00cd1fc0::DAT_00f64838.Setting::Setting();
    atexit(f3m_00cd1fc0::FUN_00d93190);
}

// @f3 0x00cd1720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1720 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64724;
void __cdecl FUN_00d93020();
}

void __cdecl FUN_00cd1720()
{
    f3m_00cd1720::DAT_00f64724.Setting::Setting();
    atexit(f3m_00cd1720::FUN_00d93020);
}

// @f3 0x00ccd880 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd880 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63f50;
void __cdecl FUN_00d925b0();
}

void __cdecl FUN_00ccd880()
{
    f3m_00ccd880::DAT_00f63f50.Setting::Setting();
    atexit(f3m_00ccd880::FUN_00d925b0);
}

// @f3 0x00cce360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce360 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f640ac;
void __cdecl FUN_00d92780();
}

void __cdecl FUN_00cce360()
{
    f3m_00cce360::DAT_00f640ac.Setting::Setting();
    atexit(f3m_00cce360::FUN_00d92780);
}

// @f3 0x00cc45e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc45e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62d08;
void __cdecl FUN_00d90d50();
}

void __cdecl FUN_00cc45e0()
{
    f3m_00cc45e0::DAT_00f62d08.Setting::Setting();
    atexit(f3m_00cc45e0::FUN_00d90d50);
}

// @f3 0x00cd52c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd52c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64e98;
void __cdecl FUN_00d93a10();
}

void __cdecl FUN_00cd52c0()
{
    f3m_00cd52c0::DAT_00f64e98.Setting::Setting();
    atexit(f3m_00cd52c0::FUN_00d93a10);
}

// @f3 0x00cd4660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4660 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d0c;
void __cdecl FUN_00d93800();
}

void __cdecl FUN_00cd4660()
{
    f3m_00cd4660::DAT_00f64d0c.Setting::Setting();
    atexit(f3m_00cd4660::FUN_00d93800);
}

// @f3 0x00cd50e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd50e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64e5c;
void __cdecl FUN_00d939c0();
}

void __cdecl FUN_00cd50e0()
{
    f3m_00cd50e0::DAT_00f64e5c.Setting::Setting();
    atexit(f3m_00cd50e0::FUN_00d939c0);
}

// @f3 0x00cc9380 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9380 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f636bc;
void __cdecl FUN_00d91a40();
}

void __cdecl FUN_00cc9380()
{
    f3m_00cc9380::DAT_00f636bc.Setting::Setting();
    atexit(f3m_00cc9380::FUN_00d91a40);
}

// @f3 0x00cc92c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc92c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f636a4;
void __cdecl FUN_00d91a20();
}

void __cdecl FUN_00cc92c0()
{
    f3m_00cc92c0::DAT_00f636a4.Setting::Setting();
    atexit(f3m_00cc92c0::FUN_00d91a20);
}

// @f3 0x00cd7f40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7f40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f653d8;
void __cdecl FUN_00d94110();
}

void __cdecl FUN_00cd7f40()
{
    f3m_00cd7f40::DAT_00f653d8.Setting::Setting();
    atexit(f3m_00cd7f40::FUN_00d94110);
}

// @f3 0x00cd6920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6920 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65114;
void __cdecl FUN_00d93d60();
}

void __cdecl FUN_00cd6920()
{
    f3m_00cd6920::DAT_00f65114.Setting::Setting();
    atexit(f3m_00cd6920::FUN_00d93d60);
}

// @f3 0x00ccdca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccdca0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63fd4;
void __cdecl FUN_00d92660();
}

void __cdecl FUN_00ccdca0()
{
    f3m_00ccdca0::DAT_00f63fd4.Setting::Setting();
    atexit(f3m_00ccdca0::FUN_00d92660);
}

// @f3 0x00cc98c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc98c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63764;
void __cdecl FUN_00d91b20();
}

void __cdecl FUN_00cc98c0()
{
    f3m_00cc98c0::DAT_00f63764.Setting::Setting();
    atexit(f3m_00cc98c0::FUN_00d91b20);
}

// @f3 0x00cd8840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8840 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f654f8;
void __cdecl FUN_00d94290();
}

void __cdecl FUN_00cd8840()
{
    f3m_00cd8840::DAT_00f654f8.Setting::Setting();
    atexit(f3m_00cd8840::FUN_00d94290);
}

// @f3 0x00cdda80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdda80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f656c0;
void __cdecl FUN_00d944f0();
}

void __cdecl FUN_00cdda80()
{
    f3m_00cdda80::DAT_00f656c0.Setting::Setting();
    atexit(f3m_00cdda80::FUN_00d944f0);
}

// @f3 0x00cde430 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde430 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f657c8;
void __cdecl FUN_00d94640();
}

void __cdecl FUN_00cde430()
{
    f3m_00cde430::DAT_00f657c8.Setting::Setting();
    atexit(f3m_00cde430::FUN_00d94640);
}

// @f3 0x00cc7280 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7280 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6329c;
void __cdecl FUN_00d914c0();
}

void __cdecl FUN_00cc7280()
{
    f3m_00cc7280::DAT_00f6329c.Setting::Setting();
    atexit(f3m_00cc7280::FUN_00d914c0);
}

// @f3 0x00cd40c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd40c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c58;
void __cdecl FUN_00d93710();
}

void __cdecl FUN_00cd40c0()
{
    f3m_00cd40c0::DAT_00f64c58.Setting::Setting();
    atexit(f3m_00cd40c0::FUN_00d93710);
}

// @f3 0x00cd5c40 (community match, verified in this file)
extern C0043b7f0 DAT_010732c0;
extern char DAT_00df7e20[];
namespace f3m_00cd5c40 {

class C0043b7f0
{
public:
    void FUN_0043b7f0(const char* a, unsigned int b);
};

void FUN_00d90b20();
int FUN_00c00d1f(void* f);

// pdb: `dynamic initializer for 'iSweetSpotLengthMinVeryHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void FUN_00cd5c40()
{
    DAT_010732c0.FUN_0043b7f0(DAT_00df7e20, 0x19);
    FUN_00c00d1f(FUN_00d90b20);
}
}   // namespace f3m_00cd5c40

// @f3 0x00cc6f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6f20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63230;
void __cdecl FUN_00d91430();
}

void __cdecl FUN_00cc6f20()
{
    f3m_00cc6f20::DAT_00f63230.Setting::Setting();
    atexit(f3m_00cc6f20::FUN_00d91430);
}

// @f3 0x00cc7580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7580 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f632fc;
void __cdecl FUN_00d91540();
}

void __cdecl FUN_00cc7580()
{
    f3m_00cc7580::DAT_00f632fc.Setting::Setting();
    atexit(f3m_00cc7580::FUN_00d91540);
}

// @f3 0x00cd3e20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3e20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c04;
void __cdecl FUN_00d936a0();
}

void __cdecl FUN_00cd3e20()
{
    f3m_00cd3e20::DAT_00f64c04.Setting::Setting();
    atexit(f3m_00cd3e20::FUN_00d936a0);
}

// @f3 0x00cd6620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6620 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f650b4;
void __cdecl FUN_00d93ce0();
}

void __cdecl FUN_00cd6620()
{
    f3m_00cd6620::DAT_00f650b4.Setting::Setting();
    atexit(f3m_00cd6620::FUN_00d93ce0);
}

// @f3 0x00cd32e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd32e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a9c;
void __cdecl FUN_00d934c0();
}

void __cdecl FUN_00cd32e0()
{
    f3m_00cd32e0::DAT_00f64a9c.Setting::Setting();
    atexit(f3m_00cd32e0::FUN_00d934c0);
}

// @f3 0x00cd11e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd11e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6467c;
void __cdecl FUN_00d92f40();
}

void __cdecl FUN_00cd11e0()
{
    f3m_00cd11e0::DAT_00f6467c.Setting::Setting();
    atexit(f3m_00cd11e0::FUN_00d92f40);
}

// @f3 0x00cc83c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc83c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f634c4;
void __cdecl FUN_00d917a0();
}

void __cdecl FUN_00cc83c0()
{
    f3m_00cc83c0::DAT_00f634c4.Setting::Setting();
    atexit(f3m_00cc83c0::FUN_00d917a0);
}

// @f3 0x00cc9a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9a40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63794;
void __cdecl FUN_00d91b60();
}

void __cdecl FUN_00cc9a40()
{
    f3m_00cc9a40::DAT_00f63794.Setting::Setting();
    atexit(f3m_00cc9a40::FUN_00d91b60);
}

// @f3 0x00cce7e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce7e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6413c;
void __cdecl FUN_00d92840();
}

void __cdecl FUN_00cce7e0()
{
    f3m_00cce7e0::DAT_00f6413c.Setting::Setting();
    atexit(f3m_00cce7e0::FUN_00d92840);
}

// @f3 0x00cde250 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde250 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6578c;
void __cdecl FUN_00d945f0();
}

void __cdecl FUN_00cde250()
{
    f3m_00cde250::DAT_00f6578c.Setting::Setting();
    atexit(f3m_00cde250::FUN_00d945f0);
}

// @f3 0x00cd0a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0a60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6458c;
void __cdecl FUN_00d92e00();
}

void __cdecl FUN_00cd0a60()
{
    f3m_00cd0a60::DAT_00f6458c.Setting::Setting();
    atexit(f3m_00cd0a60::FUN_00d92e00);
}

// @f3 0x00cc8780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8780 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6353c;
void __cdecl FUN_00d91840();
}

void __cdecl FUN_00cc8780()
{
    f3m_00cc8780::DAT_00f6353c.Setting::Setting();
    atexit(f3m_00cc8780::FUN_00d91840);
}

// @f3 0x00ccb120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb120 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a64;
void __cdecl FUN_00d91f20();
}

void __cdecl FUN_00ccb120()
{
    f3m_00ccb120::DAT_00f63a64.Setting::Setting();
    atexit(f3m_00ccb120::FUN_00d91f20);
}

// @f3 0x00cc5f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5f00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6302c;
void __cdecl FUN_00d91180();
}

void __cdecl FUN_00cc5f00()
{
    f3m_00cc5f00::DAT_00f6302c.Setting::Setting();
    atexit(f3m_00cc5f00::FUN_00d91180);
}

// @f3 0x00cde610 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde610 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65804;
void __cdecl FUN_00d94690();
}

void __cdecl FUN_00cde610()
{
    f3m_00cde610::DAT_00f65804.Setting::Setting();
    atexit(f3m_00cde610::FUN_00d94690);
}

// @f3 0x00cca580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca580 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f638fc;
void __cdecl FUN_00d91d40();
}

void __cdecl FUN_00cca580()
{
    f3m_00cca580::DAT_00f638fc.Setting::Setting();
    atexit(f3m_00cca580::FUN_00d91d40);
}

// @f3 0x00cce180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce180 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64070;
void __cdecl FUN_00d92730();
}

void __cdecl FUN_00cce180()
{
    f3m_00cce180::DAT_00f64070.Setting::Setting();
    atexit(f3m_00cce180::FUN_00d92730);
}

// @f3 0x00cd1d20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1d20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f647e4;
void __cdecl FUN_00d93120();
}

void __cdecl FUN_00cd1d20()
{
    f3m_00cd1d20::DAT_00f647e4.Setting::Setting();
    atexit(f3m_00cd1d20::FUN_00d93120);
}

// @f3 0x00cc3f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3f20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62c30;
void __cdecl FUN_00d90c30();
}

void __cdecl FUN_00cc3f20()
{
    f3m_00cc3f20::DAT_00f62c30.Setting::Setting();
    atexit(f3m_00cc3f20::FUN_00d90c30);
}

// @f3 0x00cd7280 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7280 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65240;
void __cdecl FUN_00d93ef0();
}

void __cdecl FUN_00cd7280()
{
    f3m_00cd7280::DAT_00f65240.Setting::Setting();
    atexit(f3m_00cd7280::FUN_00d93ef0);
}

// @f3 0x00cd7dc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7dc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f653a8;
void __cdecl FUN_00d940d0();
}

void __cdecl FUN_00cd7dc0()
{
    f3m_00cd7dc0::DAT_00f653a8.Setting::Setting();
    atexit(f3m_00cd7dc0::FUN_00d940d0);
}

// @f3 0x00cc2ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2ba0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6299c;
void __cdecl FUN_00d90790();
}

void __cdecl FUN_00cc2ba0()
{
    f3m_00cc2ba0::DAT_00f6299c.Setting::Setting();
    atexit(f3m_00cc2ba0::FUN_00d90790);
}

// @f3 0x00cd8ea0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8ea0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f655c4;
void __cdecl FUN_00d943a0();
}

void __cdecl FUN_00cd8ea0()
{
    f3m_00cd8ea0::DAT_00f655c4.Setting::Setting();
    atexit(f3m_00cd8ea0::FUN_00d943a0);
}

// @f3 0x00cd0700 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0700 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64520;
void __cdecl FUN_00d92d70();
}

void __cdecl FUN_00cd0700()
{
    f3m_00cd0700::DAT_00f64520.Setting::Setting();
    atexit(f3m_00cd0700::FUN_00d92d70);
}

// @f3 0x00ccffe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccffe0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6443c;
void __cdecl FUN_00d92c40();
}

void __cdecl FUN_00ccffe0()
{
    f3m_00ccffe0::DAT_00f6443c.Setting::Setting();
    atexit(f3m_00ccffe0::FUN_00d92c40);
}

// @f3 0x00cc4a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4a00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62d8c;
void __cdecl FUN_00d90e00();
}

void __cdecl FUN_00cc4a00()
{
    f3m_00cc4a00::DAT_00f62d8c.Setting::Setting();
    atexit(f3m_00cc4a00::FUN_00d90e00);
}

// @f3 0x00cd79a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd79a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65324;
void __cdecl FUN_00d94020();
}

void __cdecl FUN_00cd79a0()
{
    f3m_00cd79a0::DAT_00f65324.Setting::Setting();
    atexit(f3m_00cd79a0::FUN_00d94020);
}

// @f3 0x00cc8b40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8b40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f635b4;
void __cdecl FUN_00d918e0();
}

void __cdecl FUN_00cc8b40()
{
    f3m_00cc8b40::DAT_00f635b4.Setting::Setting();
    atexit(f3m_00cc8b40::FUN_00d918e0);
}

// @f3 0x00cd1a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1a80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64790;
void __cdecl FUN_00d930b0();
}

void __cdecl FUN_00cd1a80()
{
    f3m_00cd1a80::DAT_00f64790.Setting::Setting();
    atexit(f3m_00cd1a80::FUN_00d930b0);
}

// @f3 0x00cd3be0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3be0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64bbc;
void __cdecl FUN_00d93640();
}

void __cdecl FUN_00cd3be0()
{
    f3m_00cd3be0::DAT_00f64bbc.Setting::Setting();
    atexit(f3m_00cd3be0::FUN_00d93640);
}

// @f3 0x00cd8180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8180 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65420;
void __cdecl FUN_00d94170();
}

void __cdecl FUN_00cd8180()
{
    f3m_00cd8180::DAT_00f65420.Setting::Setting();
    atexit(f3m_00cd8180::FUN_00d94170);
}

// @f3 0x00cc9200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9200 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6368c;
void __cdecl FUN_00d91a00();
}

void __cdecl FUN_00cc9200()
{
    f3m_00cc9200::DAT_00f6368c.Setting::Setting();
    atexit(f3m_00cc9200::FUN_00d91a00);
}

// @f3 0x00cc4220 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4220 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62c90;
void __cdecl FUN_00d90cb0();
}

void __cdecl FUN_00cc4220()
{
    f3m_00cc4220::DAT_00f62c90.Setting::Setting();
    atexit(f3m_00cc4220::FUN_00d90cb0);
}

// @f3 0x00cc4700 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4700 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62d2c;
void __cdecl FUN_00d90d80();
}

void __cdecl FUN_00cc4700()
{
    f3m_00cc4700::DAT_00f62d2c.Setting::Setting();
    atexit(f3m_00cc4700::FUN_00d90d80);
}

// @f3 0x00cc72e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc72e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f632a8;
void __cdecl FUN_00d914d0();
}

void __cdecl FUN_00cc72e0()
{
    f3m_00cc72e0::DAT_00f632a8.Setting::Setting();
    atexit(f3m_00cc72e0::FUN_00d914d0);
}

// @f3 0x00ccbc60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccbc60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63bcc;
void __cdecl FUN_00d92100();
}

void __cdecl FUN_00ccbc60()
{
    f3m_00ccbc60::DAT_00f63bcc.Setting::Setting();
    atexit(f3m_00ccbc60::FUN_00d92100);
}

// @f3 0x00cc2840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2840 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62930;
void __cdecl FUN_00d90700();
}

void __cdecl FUN_00cc2840()
{
    f3m_00cc2840::DAT_00f62930.Setting::Setting();
    atexit(f3m_00cc2840::FUN_00d90700);
}

// @f3 0x00cd7820 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7820 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f652f4;
void __cdecl FUN_00d93fe0();
}

void __cdecl FUN_00cd7820()
{
    f3m_00cd7820::DAT_00f652f4.Setting::Setting();
    atexit(f3m_00cd7820::FUN_00d93fe0);
}

// @f3 0x00cd4960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4960 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d6c;
void __cdecl FUN_00d93880();
}

void __cdecl FUN_00cd4960()
{
    f3m_00cd4960::DAT_00f64d6c.Setting::Setting();
    atexit(f3m_00cd4960::FUN_00d93880);
}

// @f3 0x00cd5e20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5e20 {
extern const char DAT_00df7fc8[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01073308;
void __cdecl FUN_00d90c10();
}

// pdb: `dynamic initializer for 'iConcentricLengthMaxVeryHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5e20()
{
    f3m_00cd5e20::DAT_01073308.FUN_0043b7f0(f3m_00cd5e20::DAT_00df7fc8, 200);
    atexit(f3m_00cd5e20::FUN_00d90c10);
}

// @f3 0x00cca760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca760 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63938;
void __cdecl FUN_00d91d90();
}

void __cdecl FUN_00cca760()
{
    f3m_00cca760::DAT_00f63938.Setting::Setting();
    atexit(f3m_00cca760::FUN_00d91d90);
}

// @f3 0x00cd7d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7d60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6539c;
void __cdecl FUN_00d940c0();
}

void __cdecl FUN_00cd7d60()
{
    f3m_00cd7d60::DAT_00f6539c.Setting::Setting();
    atexit(f3m_00cd7d60::FUN_00d940c0);
}

// @f3 0x00cc8840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8840 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63554;
void __cdecl FUN_00d91860();
}

void __cdecl FUN_00cc8840()
{
    f3m_00cc8840::DAT_00f63554.Setting::Setting();
    atexit(f3m_00cc8840::FUN_00d91860);
}

// @f3 0x00cc7340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7340 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f632b4;
void __cdecl FUN_00d914e0();
}

void __cdecl FUN_00cc7340()
{
    f3m_00cc7340::DAT_00f632b4.Setting::Setting();
    atexit(f3m_00cc7340::FUN_00d914e0);
}

// @f3 0x00cd46c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd46c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d18;
void __cdecl FUN_00d93810();
}

void __cdecl FUN_00cd46c0()
{
    f3m_00cd46c0::DAT_00f64d18.Setting::Setting();
    atexit(f3m_00cd46c0::FUN_00d93810);
}

// @f3 0x00cc89c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc89c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63584;
void __cdecl FUN_00d918a0();
}

void __cdecl FUN_00cc89c0()
{
    f3m_00cc89c0::DAT_00f63584.Setting::Setting();
    atexit(f3m_00cc89c0::FUN_00d918a0);
}

// @f3 0x00cd6980 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6980 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65120;
void __cdecl FUN_00d93d70();
}

void __cdecl FUN_00cd6980()
{
    f3m_00cd6980::DAT_00f65120.Setting::Setting();
    atexit(f3m_00cd6980::FUN_00d93d70);
}

// @f3 0x00cd7b80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7b80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65360;
void __cdecl FUN_00d94070();
}

void __cdecl FUN_00cd7b80()
{
    f3m_00cd7b80::DAT_00f65360.Setting::Setting();
    atexit(f3m_00cd7b80::FUN_00d94070);
}

// @f3 0x00ccd940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd940 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63f68;
void __cdecl FUN_00d925d0();
}

void __cdecl FUN_00ccd940()
{
    f3m_00ccd940::DAT_00f63f68.Setting::Setting();
    atexit(f3m_00ccd940::FUN_00d925d0);
}

// @f3 0x00cc0030 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0030 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6242c;
void __cdecl FUN_00d90060();
}

void __cdecl FUN_00cc0030()
{
    f3m_00cc0030::DAT_00f6242c.Setting::Setting();
    atexit(f3m_00cc0030::FUN_00d90060);
}

// @f3 0x00cc7a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7a60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63398;
void __cdecl FUN_00d91610();
}

void __cdecl FUN_00cc7a60()
{
    f3m_00cc7a60::DAT_00f63398.Setting::Setting();
    atexit(f3m_00cc7a60::FUN_00d91610);
}

// @f3 0x00cd47e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd47e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d3c;
void __cdecl FUN_00d93840();
}

void __cdecl FUN_00cd47e0()
{
    f3m_00cd47e0::DAT_00f64d3c.Setting::Setting();
    atexit(f3m_00cd47e0::FUN_00d93840);
}

// @f3 0x00cc04a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc04a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f624bc;
void __cdecl FUN_00d90110();
}

void __cdecl FUN_00cc04a0()
{
    f3m_00cc04a0::DAT_00f624bc.Setting::Setting();
    atexit(f3m_00cc04a0::FUN_00d90110);
}

// @f3 0x00ccb540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb540 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63ae8;
void __cdecl FUN_00d91fd0();
}

void __cdecl FUN_00ccb540()
{
    f3m_00ccb540::DAT_00f63ae8.Setting::Setting();
    atexit(f3m_00ccb540::FUN_00d91fd0);
}

// @f3 0x00cc2960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2960 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62954;
void __cdecl FUN_00d90730();
}

void __cdecl FUN_00cc2960()
{
    f3m_00cc2960::DAT_00f62954.Setting::Setting();
    atexit(f3m_00cc2960::FUN_00d90730);
}

// @f3 0x00cd5a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5a40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f88;
void __cdecl FUN_00d93b50();
}

void __cdecl FUN_00cd5a40()
{
    f3m_00cd5a40::DAT_00f64f88.Setting::Setting();
    atexit(f3m_00cd5a40::FUN_00d93b50);
}

// @f3 0x00cde490 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde490 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f657d4;
void __cdecl FUN_00d94650();
}

void __cdecl FUN_00cde490()
{
    f3m_00cde490::DAT_00f657d4.Setting::Setting();
    atexit(f3m_00cde490::FUN_00d94650);
}

// @f3 0x00cddc60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddc60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f656fc;
void __cdecl FUN_00d94540();
}

void __cdecl FUN_00cddc60()
{
    f3m_00cddc60::DAT_00f656fc.Setting::Setting();
    atexit(f3m_00cddc60::FUN_00d94540);
}

// @f3 0x00cc9980 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9980 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6377c;
void __cdecl FUN_00d91b40();
}

void __cdecl FUN_00cc9980()
{
    f3m_00cc9980::DAT_00f6377c.Setting::Setting();
    atexit(f3m_00cc9980::FUN_00d91b40);
}

// @f3 0x00cd8d80 (community match, verified in this file)
extern RegistrySetting DAT_00f655a0;
namespace f3m_00cd8d80 {
void __cdecl FUN_00d94370();

void __cdecl FUN_00cd8d80()
{
    DAT_00f655a0.RegistrySetting::RegistrySetting();
    atexit(FUN_00d94370);
}
}   // namespace f3m_00cd8d80

// @f3 0x00cc5d20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5d20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ff0;
void __cdecl FUN_00d91130();
}

void __cdecl FUN_00cc5d20()
{
    f3m_00cc5d20::DAT_00f62ff0.Setting::Setting();
    atexit(f3m_00cc5d20::FUN_00d91130);
}

// @f3 0x00cc3f80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3f80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62c3c;
void __cdecl FUN_00d90c40();
}

void __cdecl FUN_00cc3f80()
{
    f3m_00cc3f80::DAT_00f62c3c.Setting::Setting();
    atexit(f3m_00cc3f80::FUN_00d90c40);
}

// @f3 0x00cc18e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc18e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62744;
void __cdecl FUN_00d90470();
}

void __cdecl FUN_00cc18e0()
{
    f3m_00cc18e0::DAT_00f62744.Setting::Setting();
    atexit(f3m_00cc18e0::FUN_00d90470);
}

// @f3 0x00cc5120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5120 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e70;
void __cdecl FUN_00d90f30();
}

void __cdecl FUN_00cc5120()
{
    f3m_00cc5120::DAT_00f62e70.Setting::Setting();
    atexit(f3m_00cc5120::FUN_00d90f30);
}

// @f3 0x00cd2800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2800 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64940;
void __cdecl FUN_00d932f0();
}

void __cdecl FUN_00cd2800()
{
    f3m_00cd2800::DAT_00f64940.Setting::Setting();
    atexit(f3m_00cd2800::FUN_00d932f0);
}

// @f3 0x00cd7be0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7be0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6536c;
void __cdecl FUN_00d94080();
}

void __cdecl FUN_00cd7be0()
{
    f3m_00cd7be0::DAT_00f6536c.Setting::Setting();
    atexit(f3m_00cd7be0::FUN_00d94080);
}

// @f3 0x00cd4ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4ae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d9c;
void __cdecl FUN_00d938c0();
}

void __cdecl FUN_00cd4ae0()
{
    f3m_00cd4ae0::DAT_00f64d9c.Setting::Setting();
    atexit(f3m_00cd4ae0::FUN_00d938c0);
}

// @f3 0x00cd7220 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7220 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65234;
void __cdecl FUN_00d93ee0();
}

void __cdecl FUN_00cd7220()
{
    f3m_00cd7220::DAT_00f65234.Setting::Setting();
    atexit(f3m_00cd7220::FUN_00d93ee0);
}

// @f3 0x00ccf500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf500 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f642e0;
void __cdecl FUN_00d92a70();
}

void __cdecl FUN_00ccf500()
{
    f3m_00ccf500::DAT_00f642e0.Setting::Setting();
    atexit(f3m_00ccf500::FUN_00d92a70);
}

// @f3 0x00cc6620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6620 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63110;
void __cdecl FUN_00d912b0();
}

void __cdecl FUN_00cc6620()
{
    f3m_00cc6620::DAT_00f63110.Setting::Setting();
    atexit(f3m_00cc6620::FUN_00d912b0);
}

// @f3 0x00cd8660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8660 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f654bc;
void __cdecl FUN_00d94240();
}

void __cdecl FUN_00cd8660()
{
    f3m_00cd8660::DAT_00f654bc.Setting::Setting();
    atexit(f3m_00cd8660::FUN_00d94240);
}

// @f3 0x00cc95c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc95c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63704;
void __cdecl FUN_00d91aa0();
}

void __cdecl FUN_00cc95c0()
{
    f3m_00cc95c0::DAT_00f63704.Setting::Setting();
    atexit(f3m_00cc95c0::FUN_00d91aa0);
}

// @f3 0x00cd27a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd27a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64934;
void __cdecl FUN_00d932e0();
}

void __cdecl FUN_00cd27a0()
{
    f3m_00cd27a0::DAT_00f64934.Setting::Setting();
    atexit(f3m_00cd27a0::FUN_00d932e0);
}

// @f3 0x00cd12a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd12a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64694;
void __cdecl FUN_00d92f60();
}

void __cdecl FUN_00cd12a0()
{
    f3m_00cd12a0::DAT_00f64694.Setting::Setting();
    atexit(f3m_00cd12a0::FUN_00d92f60);
}

// @f3 0x00cc9c20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9c20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f637d0;
void __cdecl FUN_00d91bb0();
}

void __cdecl FUN_00cc9c20()
{
    f3m_00cc9c20::DAT_00f637d0.Setting::Setting();
    atexit(f3m_00cc9c20::FUN_00d91bb0);
}

// @f3 0x00cd8fc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8fc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f655e8;
void __cdecl FUN_00d943d0();
}

void __cdecl FUN_00cd8fc0()
{
    f3m_00cd8fc0::DAT_00f655e8.Setting::Setting();
    atexit(f3m_00cd8fc0::FUN_00d943d0);
}

// @f3 0x00cccec0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cccec0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63e18;
void __cdecl FUN_00d92410();
}

void __cdecl FUN_00cccec0()
{
    f3m_00cccec0::DAT_00f63e18.Setting::Setting();
    atexit(f3m_00cccec0::FUN_00d92410);
}

// @f3 0x00cd69e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd69e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6512c;
void __cdecl FUN_00d93d80();
}

void __cdecl FUN_00cd69e0()
{
    f3m_00cd69e0::DAT_00f6512c.Setting::Setting();
    atexit(f3m_00cd69e0::FUN_00d93d80);
}

// @f3 0x00cc5ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5ba0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62fc0;
void __cdecl FUN_00d910f0();
}

void __cdecl FUN_00cc5ba0()
{
    f3m_00cc5ba0::DAT_00f62fc0.Setting::Setting();
    atexit(f3m_00cc5ba0::FUN_00d910f0);
}

// @f3 0x00cdfb30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdfb30 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65f08;
void __cdecl FUN_00d94a50();
}

void __cdecl FUN_00cdfb30()
{
    f3m_00cdfb30::DAT_00f65f08.Setting::Setting();
    atexit(f3m_00cdfb30::FUN_00d94a50);
}

// @f3 0x00ccd2e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd2e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63e9c;
void __cdecl FUN_00d924c0();
}

void __cdecl FUN_00ccd2e0()
{
    f3m_00ccd2e0::DAT_00f63e9c.Setting::Setting();
    atexit(f3m_00ccd2e0::FUN_00d924c0);
}

// @f3 0x00cd1780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1780 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64730;
void __cdecl FUN_00d93030();
}

void __cdecl FUN_00cd1780()
{
    f3m_00cd1780::DAT_00f64730.Setting::Setting();
    atexit(f3m_00cd1780::FUN_00d93030);
}

// @f3 0x00cc6800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6800 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6314c;
void __cdecl FUN_00d91300();
}

void __cdecl FUN_00cc6800()
{
    f3m_00cc6800::DAT_00f6314c.Setting::Setting();
    atexit(f3m_00cc6800::FUN_00d91300);
}

// @f3 0x00ccb780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb780 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63b30;
void __cdecl FUN_00d92030();
}

void __cdecl FUN_00ccb780()
{
    f3m_00ccb780::DAT_00f63b30.Setting::Setting();
    atexit(f3m_00ccb780::FUN_00d92030);
}

// @f3 0x00cd09a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd09a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64574;
void __cdecl FUN_00d92de0();
}

void __cdecl FUN_00cd09a0()
{
    f3m_00cd09a0::DAT_00f64574.Setting::Setting();
    atexit(f3m_00cd09a0::FUN_00d92de0);
}

// @f3 0x00cd45a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd45a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64cf4;
void __cdecl FUN_00d937e0();
}

void __cdecl FUN_00cd45a0()
{
    f3m_00cd45a0::DAT_00f64cf4.Setting::Setting();
    atexit(f3m_00cd45a0::FUN_00d937e0);
}

// @f3 0x00cc07a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc07a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6251c;
void __cdecl FUN_00d90190();
}

void __cdecl FUN_00cc07a0()
{
    f3m_00cc07a0::DAT_00f6251c.Setting::Setting();
    atexit(f3m_00cc07a0::FUN_00d90190);
}

// @f3 0x00ccd520 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd520 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63ee4;
void __cdecl FUN_00d92520();
}

void __cdecl FUN_00ccd520()
{
    f3m_00ccd520::DAT_00f63ee4.Setting::Setting();
    atexit(f3m_00ccd520::FUN_00d92520);
}

// @f3 0x00ccdfa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccdfa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64034;
void __cdecl FUN_00d926e0();
}

void __cdecl FUN_00ccdfa0()
{
    f3m_00ccdfa0::DAT_00f64034.Setting::Setting();
    atexit(f3m_00ccdfa0::FUN_00d926e0);
}

// @f3 0x00ccda00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccda00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63f80;
void __cdecl FUN_00d925f0();
}

void __cdecl FUN_00ccda00()
{
    f3m_00ccda00::DAT_00f63f80.Setting::Setting();
    atexit(f3m_00ccda00::FUN_00d925f0);
}

// @f3 0x00cd3d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3d60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64bec;
void __cdecl FUN_00d93680();
}

void __cdecl FUN_00cd3d60()
{
    f3m_00cd3d60::DAT_00f64bec.Setting::Setting();
    atexit(f3m_00cd3d60::FUN_00d93680);
}

// @f3 0x00cdde40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdde40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65738;
void __cdecl FUN_00d94590();
}

void __cdecl FUN_00cdde40()
{
    f3m_00cdde40::DAT_00f65738.Setting::Setting();
    atexit(f3m_00cdde40::FUN_00d94590);
}

// @f3 0x00ccafa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccafa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a34;
void __cdecl FUN_00d91ee0();
}

void __cdecl FUN_00ccafa0()
{
    f3m_00ccafa0::DAT_00f63a34.Setting::Setting();
    atexit(f3m_00ccafa0::FUN_00d91ee0);
}

// @f3 0x00cc32c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc32c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62a80;
void __cdecl FUN_00d908c0();
}

void __cdecl FUN_00cc32c0()
{
    f3m_00cc32c0::DAT_00f62a80.Setting::Setting();
    atexit(f3m_00cc32c0::FUN_00d908c0);
}

// @f3 0x00cc8960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8960 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63578;
void __cdecl FUN_00d91890();
}

void __cdecl FUN_00cc8960()
{
    f3m_00cc8960::DAT_00f63578.Setting::Setting();
    atexit(f3m_00cc8960::FUN_00d91890);
}

// @f3 0x00cd8ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8ae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6554c;
void __cdecl FUN_00d94300();
}

void __cdecl FUN_00cd8ae0()
{
    f3m_00cd8ae0::DAT_00f6554c.Setting::Setting();
    atexit(f3m_00cd8ae0::FUN_00d94300);
}

// @f3 0x00ccc800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc800 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63d40;
void __cdecl FUN_00d922f0();
}

void __cdecl FUN_00ccc800()
{
    f3m_00ccc800::DAT_00f63d40.Setting::Setting();
    atexit(f3m_00ccc800::FUN_00d922f0);
}

// @f3 0x00cc03e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc03e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f624a4;
void __cdecl FUN_00d900f0();
}

void __cdecl FUN_00cc03e0()
{
    f3m_00cc03e0::DAT_00f624a4.Setting::Setting();
    atexit(f3m_00cc03e0::FUN_00d900f0);
}

// @f3 0x00ccc620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc620 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63d04;
void __cdecl FUN_00d922a0();
}

void __cdecl FUN_00ccc620()
{
    f3m_00ccc620::DAT_00f63d04.Setting::Setting();
    atexit(f3m_00ccc620::FUN_00d922a0);
}

// @f3 0x00cc6d40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6d40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f631f4;
void __cdecl FUN_00d913e0();
}

void __cdecl FUN_00cc6d40()
{
    f3m_00cc6d40::DAT_00f631f4.Setting::Setting();
    atexit(f3m_00cc6d40::FUN_00d913e0);
}

// @f3 0x00cc8cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8cc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f635e4;
void __cdecl FUN_00d91920();
}

void __cdecl FUN_00cc8cc0()
{
    f3m_00cc8cc0::DAT_00f635e4.Setting::Setting();
    atexit(f3m_00cc8cc0::FUN_00d91920);
}

// @f3 0x00cce060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce060 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6404c;
void __cdecl FUN_00d92700();
}

void __cdecl FUN_00cce060()
{
    f3m_00cce060::DAT_00f6404c.Setting::Setting();
    atexit(f3m_00cce060::FUN_00d92700);
}

// @f3 0x00ccf620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf620 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64304;
void __cdecl FUN_00d92aa0();
}

void __cdecl FUN_00ccf620()
{
    f3m_00ccf620::DAT_00f64304.Setting::Setting();
    atexit(f3m_00ccf620::FUN_00d92aa0);
}

// @f3 0x00cde9d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde9d0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6587c;
void __cdecl FUN_00d94730();
}

void __cdecl FUN_00cde9d0()
{
    f3m_00cde9d0::DAT_00f6587c.Setting::Setting();
    atexit(f3m_00cde9d0::FUN_00d94730);
}

// @f3 0x00cd57a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd57a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f34;
void __cdecl FUN_00d93ae0();
}

void __cdecl FUN_00cd57a0()
{
    f3m_00cd57a0::DAT_00f64f34.Setting::Setting();
    atexit(f3m_00cd57a0::FUN_00d93ae0);
}

// @f3 0x00cc3c20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3c20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62bac;
void __cdecl FUN_00d90a50();
}

void __cdecl FUN_00cc3c20()
{
    f3m_00cc3c20::DAT_00f62bac.Setting::Setting();
    atexit(f3m_00cc3c20::FUN_00d90a50);
}

// @f3 0x00cc9b60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9b60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f637b8;
void __cdecl FUN_00d91b90();
}

void __cdecl FUN_00cc9b60()
{
    f3m_00cc9b60::DAT_00f637b8.Setting::Setting();
    atexit(f3m_00cc9b60::FUN_00d91b90);
}

// @f3 0x00cd2560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2560 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f648ec;
void __cdecl FUN_00d93280();
}

void __cdecl FUN_00cd2560()
{
    f3m_00cd2560::DAT_00f648ec.Setting::Setting();
    atexit(f3m_00cd2560::FUN_00d93280);
}

// @f3 0x00cd2fe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2fe0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a3c;
void __cdecl FUN_00d93440();
}

void __cdecl FUN_00cd2fe0()
{
    f3m_00cd2fe0::DAT_00f64a3c.Setting::Setting();
    atexit(f3m_00cd2fe0::FUN_00d93440);
}

// @f3 0x00cd26e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd26e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6491c;
void __cdecl FUN_00d932c0();
}

void __cdecl FUN_00cd26e0()
{
    f3m_00cd26e0::DAT_00f6491c.Setting::Setting();
    atexit(f3m_00cd26e0::FUN_00d932c0);
}

// @f3 0x00cd0340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0340 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f644a8;
void __cdecl FUN_00d92cd0();
}

void __cdecl FUN_00cd0340()
{
    f3m_00cd0340::DAT_00f644a8.Setting::Setting();
    atexit(f3m_00cd0340::FUN_00d92cd0);
}

// @f3 0x00cd0760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0760 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6452c;
void __cdecl FUN_00d92d80();
}

void __cdecl FUN_00cd0760()
{
    f3m_00cd0760::DAT_00f6452c.Setting::Setting();
    atexit(f3m_00cd0760::FUN_00d92d80);
}

// @f3 0x00cd14e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd14e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f646dc;
void __cdecl FUN_00d92fc0();
}

void __cdecl FUN_00cd14e0()
{
    f3m_00cd14e0::DAT_00f646dc.Setting::Setting();
    atexit(f3m_00cd14e0::FUN_00d92fc0);
}

// @f3 0x00cc8900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8900 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6356c;
void __cdecl FUN_00d91880();
}

void __cdecl FUN_00cc8900()
{
    f3m_00cc8900::DAT_00f6356c.Setting::Setting();
    atexit(f3m_00cc8900::FUN_00d91880);
}

// @f3 0x00ccb000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb000 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a40;
void __cdecl FUN_00d91ef0();
}

void __cdecl FUN_00ccb000()
{
    f3m_00ccb000::DAT_00f63a40.Setting::Setting();
    atexit(f3m_00ccb000::FUN_00d91ef0);
}

// @f3 0x00cdd960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdd960 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6569c;
void __cdecl FUN_00d944c0();
}

void __cdecl FUN_00cdd960()
{
    f3m_00cdd960::DAT_00f6569c.Setting::Setting();
    atexit(f3m_00cdd960::FUN_00d944c0);
}

// @f3 0x00cd5da0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5da0 {
extern const char DAT_00df7f54[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107326c;
void __cdecl FUN_00d90bd0();
}

// pdb: `dynamic initializer for 'iConcentricLengthMaxVeryEasy'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5da0()
{
    f3m_00cd5da0::DAT_0107326c.FUN_0043b7f0(f3m_00cd5da0::DAT_00df7f54, 200);
    atexit(f3m_00cd5da0::FUN_00d90bd0);
}

// @f3 0x00cd5d40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5d40 {
extern const char DAT_00df7efc[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01073278;
void __cdecl FUN_00d90ba0();
}

// pdb: `dynamic initializer for 'iConcentricLengthMinAverage'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5d40()
{
    f3m_00cd5d40::DAT_01073278.FUN_0043b7f0(f3m_00cd5d40::DAT_00df7efc, 200);
    atexit(f3m_00cd5d40::FUN_00d90ba0);
}

// @f3 0x00cd4540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4540 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64ce8;
void __cdecl FUN_00d937d0();
}

void __cdecl FUN_00cd4540()
{
    f3m_00cd4540::DAT_00f64ce8.Setting::Setting();
    atexit(f3m_00cd4540::FUN_00d937d0);
}

// @f3 0x00cc1100 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1100 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62648;
void __cdecl FUN_00d90320();
}

void __cdecl FUN_00cc1100()
{
    f3m_00cc1100::DAT_00f62648.Setting::Setting();
    atexit(f3m_00cc1100::FUN_00d90320);
}

// @f3 0x00cd4060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4060 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c4c;
void __cdecl FUN_00d93700();
}

void __cdecl FUN_00cd4060()
{
    f3m_00cd4060::DAT_00f64c4c.Setting::Setting();
    atexit(f3m_00cd4060::FUN_00d93700);
}

// @f3 0x00cd8900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8900 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65510;
void __cdecl FUN_00d942b0();
}

void __cdecl FUN_00cd8900()
{
    f3m_00cd8900::DAT_00f65510.Setting::Setting();
    atexit(f3m_00cd8900::FUN_00d942b0);
}

// @f3 0x00cde850 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde850 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6584c;
void __cdecl FUN_00d946f0();
}

void __cdecl FUN_00cde850()
{
    f3m_00cde850::DAT_00f6584c.Setting::Setting();
    atexit(f3m_00cde850::FUN_00d946f0);
}

// @f3 0x00cddde0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddde0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6572c;
void __cdecl FUN_00d94580();
}

void __cdecl FUN_00cddde0()
{
    f3m_00cddde0::DAT_00f6572c.Setting::Setting();
    atexit(f3m_00cddde0::FUN_00d94580);
}

// @f3 0x00cc3740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3740 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b10;
void __cdecl FUN_00d90980();
}

void __cdecl FUN_00cc3740()
{
    f3m_00cc3740::DAT_00f62b10.Setting::Setting();
    atexit(f3m_00cc3740::FUN_00d90980);
}

// @f3 0x00cceba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cceba0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f641b4;
void __cdecl FUN_00d928e0();
}

void __cdecl FUN_00cceba0()
{
    f3m_00cceba0::DAT_00f641b4.Setting::Setting();
    atexit(f3m_00cceba0::FUN_00d928e0);
}

// @f3 0x00cd9260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd9260 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6563c;
void __cdecl FUN_00d94440();
}

void __cdecl FUN_00cd9260()
{
    f3m_00cd9260::DAT_00f6563c.Setting::Setting();
    atexit(f3m_00cd9260::FUN_00d94440);
}

// @f3 0x00cc5600 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5600 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f0c;
void __cdecl FUN_00d91000();
}

void __cdecl FUN_00cc5600()
{
    f3m_00cc5600::DAT_00f62f0c.Setting::Setting();
    atexit(f3m_00cc5600::FUN_00d91000);
}

// @f3 0x00cc1160 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1160 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62654;
void __cdecl FUN_00d90330();
}

void __cdecl FUN_00cc1160()
{
    f3m_00cc1160::DAT_00f62654.Setting::Setting();
    atexit(f3m_00cc1160::FUN_00d90330);
}

// @f3 0x00cd0280 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0280 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64490;
void __cdecl FUN_00d92cb0();
}

void __cdecl FUN_00cd0280()
{
    f3m_00cd0280::DAT_00f64490.Setting::Setting();
    atexit(f3m_00cd0280::FUN_00d92cb0);
}

// @f3 0x00cc0260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0260 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62474;
void __cdecl FUN_00d900b0();
}

void __cdecl FUN_00cc0260()
{
    f3m_00cc0260::DAT_00f62474.Setting::Setting();
    atexit(f3m_00cc0260::FUN_00d900b0);
}

// @f3 0x00cc4f40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4f40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e34;
void __cdecl FUN_00d90ee0();
}

void __cdecl FUN_00cc4f40()
{
    f3m_00cc4f40::DAT_00f62e34.Setting::Setting();
    atexit(f3m_00cc4f40::FUN_00d90ee0);
}

// @f3 0x00cd5cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5cc0 {
extern const char DAT_00df7e8c[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01073350;
void __cdecl FUN_00d90b60();
}

// pdb: `dynamic initializer for 'iSweetSpotLengthMaxHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5cc0()
{
    f3m_00cd5cc0::DAT_01073350.FUN_0043b7f0(f3m_00cd5cc0::DAT_00df7e8c, 50);
    atexit(f3m_00cd5cc0::FUN_00d90b60);
}

// @f3 0x00cc1640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1640 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f626f0;
void __cdecl FUN_00d90400();
}

void __cdecl FUN_00cc1640()
{
    f3m_00cc1640::DAT_00f626f0.Setting::Setting();
    atexit(f3m_00cc1640::FUN_00d90400);
}

// @f3 0x00cc6bc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6bc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f631c4;
void __cdecl FUN_00d913a0();
}

void __cdecl FUN_00cc6bc0()
{
    f3m_00cc6bc0::DAT_00f631c4.Setting::Setting();
    atexit(f3m_00cc6bc0::FUN_00d913a0);
}

// @f3 0x00cc7820 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7820 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63350;
void __cdecl FUN_00d915b0();
}

void __cdecl FUN_00cc7820()
{
    f3m_00cc7820::DAT_00f63350.Setting::Setting();
    atexit(f3m_00cc7820::FUN_00d915b0);
}

// @f3 0x00ccdf40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccdf40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64028;
void __cdecl FUN_00d926d0();
}

void __cdecl FUN_00ccdf40()
{
    f3m_00ccdf40::DAT_00f64028.Setting::Setting();
    atexit(f3m_00ccdf40::FUN_00d926d0);
}

// @f3 0x00cc4e80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4e80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e1c;
void __cdecl FUN_00d90ec0();
}

void __cdecl FUN_00cc4e80()
{
    f3m_00cc4e80::DAT_00f62e1c.Setting::Setting();
    atexit(f3m_00cc4e80::FUN_00d90ec0);
}

// @f3 0x00cdfcb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdfcb0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65f38;
void __cdecl FUN_00d94a90();
}

void __cdecl FUN_00cdfcb0()
{
    f3m_00cdfcb0::DAT_00f65f38.Setting::Setting();
    atexit(f3m_00cdfcb0::FUN_00d94a90);
}

// @f3 0x00ccf2c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf2c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64298;
void __cdecl FUN_00d92a10();
}

void __cdecl FUN_00ccf2c0()
{
    f3m_00ccf2c0::DAT_00f64298.Setting::Setting();
    atexit(f3m_00ccf2c0::FUN_00d92a10);
}

// @f3 0x00cc74c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc74c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f632e4;
void __cdecl FUN_00d91520();
}

void __cdecl FUN_00cc74c0()
{
    f3m_00cc74c0::DAT_00f632e4.Setting::Setting();
    atexit(f3m_00cc74c0::FUN_00d91520);
}

// @f3 0x00cc1820 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1820 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6272c;
void __cdecl FUN_00d90450();
}

void __cdecl FUN_00cc1820()
{
    f3m_00cc1820::DAT_00f6272c.Setting::Setting();
    atexit(f3m_00cc1820::FUN_00d90450);
}

// @f3 0x00cd80c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd80c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65408;
void __cdecl FUN_00d94150();
}

void __cdecl FUN_00cd80c0()
{
    f3m_00cd80c0::DAT_00f65408.Setting::Setting();
    atexit(f3m_00cd80c0::FUN_00d94150);
}

// @f3 0x00ccc380 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc380 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63cb0;
void __cdecl FUN_00d92230();
}

void __cdecl FUN_00ccc380()
{
    f3m_00ccc380::DAT_00f63cb0.Setting::Setting();
    atexit(f3m_00ccc380::FUN_00d92230);
}

// @f3 0x00cc0440 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0440 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f624b0;
void __cdecl FUN_00d90100();
}

void __cdecl FUN_00cc0440()
{
    f3m_00cc0440::DAT_00f624b0.Setting::Setting();
    atexit(f3m_00cc0440::FUN_00d90100);
}

// @f3 0x00cd9320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd9320 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65654;
void __cdecl FUN_00d94460();
}

void __cdecl FUN_00cd9320()
{
    f3m_00cd9320::DAT_00f65654.Setting::Setting();
    atexit(f3m_00cd9320::FUN_00d94460);
}

// @f3 0x00cd3ee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3ee0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c1c;
void __cdecl FUN_00d936c0();
}

void __cdecl FUN_00cd3ee0()
{
    f3m_00cd3ee0::DAT_00f64c1c.Setting::Setting();
    atexit(f3m_00cd3ee0::FUN_00d936c0);
}

// @f3 0x00cc9320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9320 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f636b0;
void __cdecl FUN_00d91a30();
}

void __cdecl FUN_00cc9320()
{
    f3m_00cc9320::DAT_00f636b0.Setting::Setting();
    atexit(f3m_00cc9320::FUN_00d91a30);
}

// @f3 0x00cc47c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc47c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62d44;
void __cdecl FUN_00d90da0();
}

void __cdecl FUN_00cc47c0()
{
    f3m_00cc47c0::DAT_00f62d44.Setting::Setting();
    atexit(f3m_00cc47c0::FUN_00d90da0);
}

// @f3 0x00cd2b00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2b00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f649a0;
void __cdecl FUN_00d93370();
}

void __cdecl FUN_00cd2b00()
{
    f3m_00cd2b00::DAT_00f649a0.Setting::Setting();
    atexit(f3m_00cd2b00::FUN_00d93370);
}

// @f3 0x00cd2260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2260 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6488c;
void __cdecl FUN_00d93200();
}

void __cdecl FUN_00cd2260()
{
    f3m_00cd2260::DAT_00f6488c.Setting::Setting();
    atexit(f3m_00cd2260::FUN_00d93200);
}

// @f3 0x00cc0ce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0ce0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f625c4;
void __cdecl FUN_00d90270();
}

void __cdecl FUN_00cc0ce0()
{
    f3m_00cc0ce0::DAT_00f625c4.Setting::Setting();
    atexit(f3m_00cc0ce0::FUN_00d90270);
}

// @f3 0x00cd1900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1900 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64760;
void __cdecl FUN_00d93070();
}

void __cdecl FUN_00cd1900()
{
    f3m_00cd1900::DAT_00f64760.Setting::Setting();
    atexit(f3m_00cd1900::FUN_00d93070);
}

// @f3 0x00cd5680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5680 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f10;
void __cdecl FUN_00d93ab0();
}

void __cdecl FUN_00cd5680()
{
    f3m_00cd5680::DAT_00f64f10.Setting::Setting();
    atexit(f3m_00cd5680::FUN_00d93ab0);
}

// @f3 0x00cd0820 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0820 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64544;
void __cdecl FUN_00d92da0();
}

void __cdecl FUN_00cd0820()
{
    f3m_00cd0820::DAT_00f64544.Setting::Setting();
    atexit(f3m_00cd0820::FUN_00d92da0);
}

// @f3 0x00ccadc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccadc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f639f8;
void __cdecl FUN_00d91e90();
}

void __cdecl FUN_00ccadc0()
{
    f3m_00ccadc0::DAT_00f639f8.Setting::Setting();
    atexit(f3m_00ccadc0::FUN_00d91e90);
}

// @f3 0x00cc5780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5780 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f3c;
void __cdecl FUN_00d91040();
}

void __cdecl FUN_00cc5780()
{
    f3m_00cc5780::DAT_00f62f3c.Setting::Setting();
    atexit(f3m_00cc5780::FUN_00d91040);
}

// @f3 0x00cd0580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0580 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f644f0;
void __cdecl FUN_00d92d30();
}

void __cdecl FUN_00cd0580()
{
    f3m_00cd0580::DAT_00f644f0.Setting::Setting();
    atexit(f3m_00cd0580::FUN_00d92d30);
}

// @f3 0x00cc8ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8ae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f635a8;
void __cdecl FUN_00d918d0();
}

void __cdecl FUN_00cc8ae0()
{
    f3m_00cc8ae0::DAT_00f635a8.Setting::Setting();
    atexit(f3m_00cc8ae0::FUN_00d918d0);
}

// @f3 0x00ccd040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd040 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63e48;
void __cdecl FUN_00d92450();
}

void __cdecl FUN_00ccd040()
{
    f3m_00ccd040::DAT_00f63e48.Setting::Setting();
    atexit(f3m_00ccd040::FUN_00d92450);
}

// @f3 0x00cc9ec0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9ec0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63824;
void __cdecl FUN_00d91c20();
}

void __cdecl FUN_00cc9ec0()
{
    f3m_00cc9ec0::DAT_00f63824.Setting::Setting();
    atexit(f3m_00cc9ec0::FUN_00d91c20);
}

// @f3 0x00cd13c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd13c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f646b8;
void __cdecl FUN_00d92f90();
}

void __cdecl FUN_00cd13c0()
{
    f3m_00cd13c0::DAT_00f646b8.Setting::Setting();
    atexit(f3m_00cd13c0::FUN_00d92f90);
}

// @f3 0x00cc4160 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4160 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62c78;
void __cdecl FUN_00d90c90();
}

void __cdecl FUN_00cc4160()
{
    f3m_00cc4160::DAT_00f62c78.Setting::Setting();
    atexit(f3m_00cc4160::FUN_00d90c90);
}

// @f3 0x00cd6e00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6e00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f651b0;
void __cdecl FUN_00d93e30();
}

void __cdecl FUN_00cd6e00()
{
    f3m_00cd6e00::DAT_00f651b0.Setting::Setting();
    atexit(f3m_00cd6e00::FUN_00d93e30);
}

// @f3 0x00cca340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca340 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f638b4;
void __cdecl FUN_00d91ce0();
}

void __cdecl FUN_00cca340()
{
    f3m_00cca340::DAT_00f638b4.Setting::Setting();
    atexit(f3m_00cca340::FUN_00d91ce0);
}

// @f3 0x00cd17e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd17e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6473c;
void __cdecl FUN_00d93040();
}

void __cdecl FUN_00cd17e0()
{
    f3m_00cd17e0::DAT_00f6473c.Setting::Setting();
    atexit(f3m_00cd17e0::FUN_00d93040);
}

// @f3 0x00cc01a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc01a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6245c;
void __cdecl FUN_00d90090();
}

void __cdecl FUN_00cc01a0()
{
    f3m_00cc01a0::DAT_00f6245c.Setting::Setting();
    atexit(f3m_00cc01a0::FUN_00d90090);
}

// @f3 0x00ccf8c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf8c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64358;
void __cdecl FUN_00d92b10();
}

void __cdecl FUN_00ccf8c0()
{
    f3m_00ccf8c0::DAT_00f64358.Setting::Setting();
    atexit(f3m_00ccf8c0::FUN_00d92b10);
}

// @f3 0x00ccef00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccef00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64220;
void __cdecl FUN_00d92970();
}

void __cdecl FUN_00ccef00()
{
    f3m_00ccef00::DAT_00f64220.Setting::Setting();
    atexit(f3m_00ccef00::FUN_00d92970);
}

// @f3 0x00cc7e20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7e20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63410;
void __cdecl FUN_00d916b0();
}

void __cdecl FUN_00cc7e20()
{
    f3m_00cc7e20::DAT_00f63410.Setting::Setting();
    atexit(f3m_00cc7e20::FUN_00d916b0);
}

// @f3 0x00cd6f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6f20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f651d4;
void __cdecl FUN_00d93e60();
}

void __cdecl FUN_00cd6f20()
{
    f3m_00cd6f20::DAT_00f651d4.Setting::Setting();
    atexit(f3m_00cd6f20::FUN_00d93e60);
}

// @f3 0x00ccb720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb720 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63b24;
void __cdecl FUN_00d92020();
}

void __cdecl FUN_00ccb720()
{
    f3m_00ccb720::DAT_00f63b24.Setting::Setting();
    atexit(f3m_00ccb720::FUN_00d92020);
}

// @f3 0x00cd8000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8000 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f653f0;
void __cdecl FUN_00d94130();
}

void __cdecl FUN_00cd8000()
{
    f3m_00cd8000::DAT_00f653f0.Setting::Setting();
    atexit(f3m_00cd8000::FUN_00d94130);
}

// @f3 0x00ccf020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf020 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64244;
void __cdecl FUN_00d929a0();
}

void __cdecl FUN_00ccf020()
{
    f3m_00ccf020::DAT_00f64244.Setting::Setting();
    atexit(f3m_00ccf020::FUN_00d929a0);
}

// @f3 0x00cce9c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce9c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64178;
void __cdecl FUN_00d92890();
}

void __cdecl FUN_00cce9c0()
{
    f3m_00cce9c0::DAT_00f64178.Setting::Setting();
    atexit(f3m_00cce9c0::FUN_00d92890);
}

// @f3 0x00ccf3e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf3e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f642bc;
void __cdecl FUN_00d92a40();
}

void __cdecl FUN_00ccf3e0()
{
    f3m_00ccf3e0::DAT_00f642bc.Setting::Setting();
    atexit(f3m_00ccf3e0::FUN_00d92a40);
}

// @f3 0x00cc52a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc52a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ea0;
void __cdecl FUN_00d90f70();
}

void __cdecl FUN_00cc52a0()
{
    f3m_00cc52a0::DAT_00f62ea0.Setting::Setting();
    atexit(f3m_00cc52a0::FUN_00d90f70);
}

// @f3 0x00cd0ca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0ca0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f645d4;
void __cdecl FUN_00d92e60();
}

void __cdecl FUN_00cd0ca0()
{
    f3m_00cd0ca0::DAT_00f645d4.Setting::Setting();
    atexit(f3m_00cd0ca0::FUN_00d92e60);
}

// @f3 0x00cd5b60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5b60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64fac;
void __cdecl FUN_00d93b80();
}

void __cdecl FUN_00cd5b60()
{
    f3m_00cd5b60::DAT_00f64fac.Setting::Setting();
    atexit(f3m_00cd5b60::FUN_00d93b80);
}

// @f3 0x00cc6260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6260 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63098;
void __cdecl FUN_00d91210();
}

void __cdecl FUN_00cc6260()
{
    f3m_00cc6260::DAT_00f63098.Setting::Setting();
    atexit(f3m_00cc6260::FUN_00d91210);
}

// @f3 0x00cc0c80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0c80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f625b8;
void __cdecl FUN_00d90260();
}

void __cdecl FUN_00cc0c80()
{
    f3m_00cc0c80::DAT_00f625b8.Setting::Setting();
    atexit(f3m_00cc0c80::FUN_00d90260);
}

// @f3 0x00cc6740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6740 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63134;
void __cdecl FUN_00d912e0();
}

void __cdecl FUN_00cc6740()
{
    f3m_00cc6740::DAT_00f63134.Setting::Setting();
    atexit(f3m_00cc6740::FUN_00d912e0);
}

// @f3 0x00cc4b20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4b20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62db0;
void __cdecl FUN_00d90e30();
}

void __cdecl FUN_00cc4b20()
{
    f3m_00cc4b20::DAT_00f62db0.Setting::Setting();
    atexit(f3m_00cc4b20::FUN_00d90e30);
}

// @f3 0x00cca2e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca2e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f638a8;
void __cdecl FUN_00d91cd0();
}

void __cdecl FUN_00cca2e0()
{
    f3m_00cca2e0::DAT_00f638a8.Setting::Setting();
    atexit(f3m_00cca2e0::FUN_00d91cd0);
}

// @f3 0x00cc3b60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3b60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b94;
void __cdecl FUN_00d90a30();
}

void __cdecl FUN_00cc3b60()
{
    f3m_00cc3b60::DAT_00f62b94.Setting::Setting();
    atexit(f3m_00cc3b60::FUN_00d90a30);
}

// @f3 0x00cc6440 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6440 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f630d4;
void __cdecl FUN_00d91260();
}

void __cdecl FUN_00cc6440()
{
    f3m_00cc6440::DAT_00f630d4.Setting::Setting();
    atexit(f3m_00cc6440::FUN_00d91260);
}

// @f3 0x00cdfe30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdfe30 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65f68;
void __cdecl FUN_00d94ad0();
}

void __cdecl FUN_00cdfe30()
{
    f3m_00cdfe30::DAT_00f65f68.Setting::Setting();
    atexit(f3m_00cdfe30::FUN_00d94ad0);
}

// @f3 0x00cc4d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4d60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62df8;
void __cdecl FUN_00d90e90();
}

void __cdecl FUN_00cc4d60()
{
    f3m_00cc4d60::DAT_00f62df8.Setting::Setting();
    atexit(f3m_00cc4d60::FUN_00d90e90);
}

// @f3 0x00cc57e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc57e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f48;
void __cdecl FUN_00d91050();
}

void __cdecl FUN_00cc57e0()
{
    f3m_00cc57e0::DAT_00f62f48.Setting::Setting();
    atexit(f3m_00cc57e0::FUN_00d91050);
}

// @f3 0x00cca940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca940 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63974;
void __cdecl FUN_00d91de0();
}

void __cdecl FUN_00cca940()
{
    f3m_00cca940::DAT_00f63974.Setting::Setting();
    atexit(f3m_00cca940::FUN_00d91de0);
}

// @f3 0x00cd5440 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5440 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64ec8;
void __cdecl FUN_00d93a50();
}

void __cdecl FUN_00cd5440()
{
    f3m_00cd5440::DAT_00f64ec8.Setting::Setting();
    atexit(f3m_00cd5440::FUN_00d93a50);
}

// @f3 0x00cd2d40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2d40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f649e8;
void __cdecl FUN_00d933d0();
}

void __cdecl FUN_00cd2d40()
{
    f3m_00cd2d40::DAT_00f649e8.Setting::Setting();
    atexit(f3m_00cd2d40::FUN_00d933d0);
}

// @f3 0x00cc0560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0560 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f624d4;
void __cdecl FUN_00d90130();
}

void __cdecl FUN_00cc0560()
{
    f3m_00cc0560::DAT_00f624d4.Setting::Setting();
    atexit(f3m_00cc0560::FUN_00d90130);
}

// @f3 0x00cc5ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5ae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62fa8;
void __cdecl FUN_00d910d0();
}

void __cdecl FUN_00cc5ae0()
{
    f3m_00cc5ae0::DAT_00f62fa8.Setting::Setting();
    atexit(f3m_00cc5ae0::FUN_00d910d0);
}

// @f3 0x00cc24e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc24e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f628c4;
void __cdecl FUN_00d90670();
}

void __cdecl FUN_00cc24e0()
{
    f3m_00cc24e0::DAT_00f628c4.Setting::Setting();
    atexit(f3m_00cc24e0::FUN_00d90670);
}

// @f3 0x00cce5a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce5a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f640f4;
void __cdecl FUN_00d927e0();
}

void __cdecl FUN_00cce5a0()
{
    f3m_00cce5a0::DAT_00f640f4.Setting::Setting();
    atexit(f3m_00cce5a0::FUN_00d927e0);
}

// @f3 0x00ccf680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf680 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64310;
void __cdecl FUN_00d92ab0();
}

void __cdecl FUN_00ccf680()
{
    f3m_00ccf680::DAT_00f64310.Setting::Setting();
    atexit(f3m_00ccf680::FUN_00d92ab0);
}

// @f3 0x00cd72e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd72e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6524c;
void __cdecl FUN_00d93f00();
}

void __cdecl FUN_00cd72e0()
{
    f3m_00cd72e0::DAT_00f6524c.Setting::Setting();
    atexit(f3m_00cd72e0::FUN_00d93f00);
}

// @f3 0x00cde310 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde310 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f657a4;
void __cdecl FUN_00d94610();
}

void __cdecl FUN_00cde310()
{
    f3m_00cde310::DAT_00f657a4.Setting::Setting();
    atexit(f3m_00cde310::FUN_00d94610);
}

// @f3 0x00cd7580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7580 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f652a0;
void __cdecl FUN_00d93f70();
}

void __cdecl FUN_00cd7580()
{
    f3m_00cd7580::DAT_00f652a0.Setting::Setting();
    atexit(f3m_00cd7580::FUN_00d93f70);
}

// @f3 0x00cce660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce660 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6410c;
void __cdecl FUN_00d92800();
}

void __cdecl FUN_00cce660()
{
    f3m_00cce660::DAT_00f6410c.Setting::Setting();
    atexit(f3m_00cce660::FUN_00d92800);
}

// @f3 0x00cd8b40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8b40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65558;
void __cdecl FUN_00d94310();
}

void __cdecl FUN_00cd8b40()
{
    f3m_00cd8b40::DAT_00f65558.Setting::Setting();
    atexit(f3m_00cd8b40::FUN_00d94310);
}

// @f3 0x00cc9fe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9fe0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63848;
void __cdecl FUN_00d91c50();
}

void __cdecl FUN_00cc9fe0()
{
    f3m_00cc9fe0::DAT_00f63848.Setting::Setting();
    atexit(f3m_00cc9fe0::FUN_00d91c50);
}

// @f3 0x00cc49a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc49a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62d80;
void __cdecl FUN_00d90df0();
}

void __cdecl FUN_00cc49a0()
{
    f3m_00cc49a0::DAT_00f62d80.Setting::Setting();
    atexit(f3m_00cc49a0::FUN_00d90df0);
}

// @f3 0x00cc6b00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6b00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f631ac;
void __cdecl FUN_00d91380();
}

void __cdecl FUN_00cc6b00()
{
    f3m_00cc6b00::DAT_00f631ac.Setting::Setting();
    atexit(f3m_00cc6b00::FUN_00d91380);
}

// @f3 0x00cd6380 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6380 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65060;
void __cdecl FUN_00d93c70();
}

void __cdecl FUN_00cd6380()
{
    f3m_00cd6380::DAT_00f65060.Setting::Setting();
    atexit(f3m_00cd6380::FUN_00d93c70);
}

// @f3 0x00cd3580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3580 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64af0;
void __cdecl FUN_00d93530();
}

void __cdecl FUN_00cd3580()
{
    f3m_00cd3580::DAT_00f64af0.Setting::Setting();
    atexit(f3m_00cd3580::FUN_00d93530);
}

// @f3 0x00ccbae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccbae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63b9c;
void __cdecl FUN_00d920c0();
}

void __cdecl FUN_00ccbae0()
{
    f3m_00ccbae0::DAT_00f63b9c.Setting::Setting();
    atexit(f3m_00ccbae0::FUN_00d920c0);
}

// @f3 0x00ccc0e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc0e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63c5c;
void __cdecl FUN_00d921c0();
}

void __cdecl FUN_00ccc0e0()
{
    f3m_00ccc0e0::DAT_00f63c5c.Setting::Setting();
    atexit(f3m_00ccc0e0::FUN_00d921c0);
}

// @f3 0x00cd1600 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1600 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64700;
void __cdecl FUN_00d92ff0();
}

void __cdecl FUN_00cd1600()
{
    f3m_00cd1600::DAT_00f64700.Setting::Setting();
    atexit(f3m_00cd1600::FUN_00d92ff0);
}

// @f3 0x00cc4400 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4400 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ccc;
void __cdecl FUN_00d90d00();
}

void __cdecl FUN_00cc4400()
{
    f3m_00cc4400::DAT_00f62ccc.Setting::Setting();
    atexit(f3m_00cc4400::FUN_00d90d00);
}

// @f3 0x00ccec60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccec60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f641cc;
void __cdecl FUN_00d92900();
}

void __cdecl FUN_00ccec60()
{
    f3m_00ccec60::DAT_00f641cc.Setting::Setting();
    atexit(f3m_00ccec60::FUN_00d92900);
}

// @f3 0x00cd4e40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4e40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64e08;
void __cdecl FUN_00d93950();
}

void __cdecl FUN_00cd4e40()
{
    f3m_00cd4e40::DAT_00f64e08.Setting::Setting();
    atexit(f3m_00cd4e40::FUN_00d93950);
}

// @f3 0x00cc08c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc08c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62540;
void __cdecl FUN_00d901c0();
}

void __cdecl FUN_00cc08c0()
{
    f3m_00cc08c0::DAT_00f62540.Setting::Setting();
    atexit(f3m_00cc08c0::FUN_00d901c0);
}

// @f3 0x00ccba80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccba80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b90;
void __cdecl FUN_00d920b0();
}

void __cdecl FUN_00ccba80()
{
    using namespace f3m_00ccba80;
    DAT_00f63b90.Setting::Setting();
    atexit(FUN_00d920b0);
}

// @f3 0x00cc15e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc15e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f626e4;
void __cdecl FUN_00d903f0();
}

void __cdecl FUN_00cc15e0()
{
    using namespace f3m_00cc15e0;
    DAT_00f626e4.Setting::Setting();
    atexit(FUN_00d903f0);
}

// @f3 0x00cde550 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde550 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f657ec;
void __cdecl FUN_00d94670();
}

void __cdecl FUN_00cde550()
{
    using namespace f3m_00cde550;
    DAT_00f657ec.Setting::Setting();
    atexit(FUN_00d94670);
}

// @f3 0x00cc6680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6680 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6311c;
void __cdecl FUN_00d912c0();
}

void __cdecl FUN_00cc6680()
{
    f3m_00cc6680::DAT_00f6311c.Setting::Setting();
    atexit(f3m_00cc6680::FUN_00d912c0);
}

// @f3 0x00ccc7a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc7a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63d34;
void __cdecl FUN_00d922e0();
}

void __cdecl FUN_00ccc7a0()
{
    f3m_00ccc7a0::DAT_00f63d34.Setting::Setting();
    atexit(f3m_00ccc7a0::FUN_00d922e0);
}

// @f3 0x00cd6080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6080 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65000;
void __cdecl FUN_00d93bf0();
}

void __cdecl FUN_00cd6080()
{
    f3m_00cd6080::DAT_00f65000.Setting::Setting();
    atexit(f3m_00cd6080::FUN_00d93bf0);
}

// @f3 0x00cd8420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8420 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65474;
void __cdecl FUN_00d941e0();
}

void __cdecl FUN_00cd8420()
{
    f3m_00cd8420::DAT_00f65474.Setting::Setting();
    atexit(f3m_00cd8420::FUN_00d941e0);
}

// @f3 0x00cd9080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd9080 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65600;
void __cdecl FUN_00d943f0();
}

void __cdecl FUN_00cd9080()
{
    f3m_00cd9080::DAT_00f65600.Setting::Setting();
    atexit(f3m_00cd9080::FUN_00d943f0);
}

// @f3 0x00cc9f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9f20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63830;
void __cdecl FUN_00d91c30();
}

void __cdecl FUN_00cc9f20()
{
    f3m_00cc9f20::DAT_00f63830.Setting::Setting();
    atexit(f3m_00cc9f20::FUN_00d91c30);
}

// @f3 0x00cc88a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc88a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63560;
void __cdecl FUN_00d91870();
}

void __cdecl FUN_00cc88a0()
{
    f3m_00cc88a0::DAT_00f63560.Setting::Setting();
    atexit(f3m_00cc88a0::FUN_00d91870);
}

// @f3 0x00cd04c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd04c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f644d8;
void __cdecl FUN_00d92d10();
}

void __cdecl FUN_00cd04c0()
{
    f3m_00cd04c0::DAT_00f644d8.Setting::Setting();
    atexit(f3m_00cd04c0::FUN_00d92d10);
}

// @f3 0x00cd5620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5620 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f04;
void __cdecl FUN_00d93aa0();
}

void __cdecl FUN_00cd5620()
{
    f3m_00cd5620::DAT_00f64f04.Setting::Setting();
    atexit(f3m_00cd5620::FUN_00d93aa0);
}

// @f3 0x00cddd20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddd20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65714;
void __cdecl FUN_00d94560();
}

void __cdecl FUN_00cddd20()
{
    f3m_00cddd20::DAT_00f65714.Setting::Setting();
    atexit(f3m_00cddd20::FUN_00d94560);
}

// @f3 0x00cceb40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cceb40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f641a8;
void __cdecl FUN_00d928d0();
}

void __cdecl FUN_00cceb40()
{
    using namespace f3m_00cceb40;
    DAT_00f641a8.Setting::Setting();
    atexit(FUN_00d928d0);
}

// @f3 0x00cc9c80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9c80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f637dc;
void __cdecl FUN_00d91bc0();
}

void __cdecl FUN_00cc9c80()
{
    using namespace f3m_00cc9c80;
    DAT_00f637dc.Setting::Setting();
    atexit(FUN_00d91bc0);
}

// @f3 0x00cceae0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cceae0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6419c;
void __cdecl FUN_00d928c0();
}

void __cdecl FUN_00cceae0()
{
    using namespace f3m_00cceae0;
    DAT_00f6419c.Setting::Setting();
    atexit(FUN_00d928c0);
}

// @f3 0x00cde370 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde370 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f657b0;
void __cdecl FUN_00d94620();
}

void __cdecl FUN_00cde370()
{
    using namespace f3m_00cde370;
    DAT_00f657b0.Setting::Setting();
    atexit(FUN_00d94620);
}

// @f3 0x00cd18a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd18a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64754;
void __cdecl FUN_00d93060();
}

void __cdecl FUN_00cd18a0()
{
    f3m_00cd18a0::DAT_00f64754.Setting::Setting();
    atexit(f3m_00cd18a0::FUN_00d93060);
}

// @f3 0x00ccaa60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccaa60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63998;
void __cdecl FUN_00d91e10();
}

void __cdecl FUN_00ccaa60()
{
    f3m_00ccaa60::DAT_00f63998.Setting::Setting();
    atexit(f3m_00ccaa60::FUN_00d91e10);
}

// @f3 0x00cce420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce420 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f640c4;
void __cdecl FUN_00d927a0();
}

void __cdecl FUN_00cce420()
{
    f3m_00cce420::DAT_00f640c4.Setting::Setting();
    atexit(f3m_00cce420::FUN_00d927a0);
}

// @f3 0x00cc6020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6020 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63050;
void __cdecl FUN_00d911b0();
}

void __cdecl FUN_00cc6020()
{
    f3m_00cc6020::DAT_00f63050.Setting::Setting();
    atexit(f3m_00cc6020::FUN_00d911b0);
}

// @f3 0x00cc56c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc56c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f24;
void __cdecl FUN_00d91020();
}

void __cdecl FUN_00cc56c0()
{
    f3m_00cc56c0::DAT_00f62f24.Setting::Setting();
    atexit(f3m_00cc56c0::FUN_00d91020);
}

// @f3 0x00cc7fa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7fa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63440;
void __cdecl FUN_00d916f0();
}

void __cdecl FUN_00cc7fa0()
{
    using namespace f3m_00cc7fa0;
    DAT_00f63440.Setting::Setting();
    atexit(FUN_00d916f0);
}

// @f3 0x00cd0460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0460 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f644cc;
void __cdecl FUN_00d92d00();
}

void __cdecl FUN_00cd0460()
{
    f3m_00cd0460::DAT_00f644cc.Setting::Setting();
    atexit(f3m_00cd0460::FUN_00d92d00);
}

// @f3 0x00cce4e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce4e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f640dc;
void __cdecl FUN_00d927c0();
}

void __cdecl FUN_00cce4e0()
{
    using namespace f3m_00cce4e0;
    DAT_00f640dc.Setting::Setting();
    atexit(FUN_00d927c0);
}

// @f3 0x00cc0380 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0380 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62498;
void __cdecl FUN_00d900e0();
}

void __cdecl FUN_00cc0380()
{
    f3m_00cc0380::DAT_00f62498.Setting::Setting();
    atexit(f3m_00cc0380::FUN_00d900e0);
}

// @f3 0x00cd21a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd21a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64874;
void __cdecl FUN_00d931e0();
}

void __cdecl FUN_00cd21a0()
{
    f3m_00cd21a0::DAT_00f64874.Setting::Setting();
    atexit(f3m_00cd21a0::FUN_00d931e0);
}

// @f3 0x00cc2240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2240 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62870;
void __cdecl FUN_00d90600();
}

void __cdecl FUN_00cc2240()
{
    f3m_00cc2240::DAT_00f62870.Setting::Setting();
    atexit(f3m_00cc2240::FUN_00d90600);
}

// @f3 0x00ccc740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc740 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63d28;
void __cdecl FUN_00d922d0();
}

void __cdecl FUN_00ccc740()
{
    f3m_00ccc740::DAT_00f63d28.Setting::Setting();
    atexit(f3m_00ccc740::FUN_00d922d0);
}

// @f3 0x00cd49c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd49c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d78;
void __cdecl FUN_00d93890();
}

void __cdecl FUN_00cd49c0()
{
    f3m_00cd49c0::DAT_00f64d78.Setting::Setting();
    atexit(f3m_00cd49c0::FUN_00d93890);
}

// @f3 0x00cc3a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3a40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b70;
void __cdecl FUN_00d90a00();
}

void __cdecl FUN_00cc3a40()
{
    f3m_00cc3a40::DAT_00f62b70.Setting::Setting();
    atexit(f3m_00cc3a40::FUN_00d90a00);
}

// @f3 0x00cd5d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5d60 {
extern const char DAT_00df7f18[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01073260;
void __cdecl FUN_00d90bb0();
}

// pdb: `dynamic initializer for 'iConcentricLengthMinHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5d60()
{
    f3m_00cd5d60::DAT_01073260.FUN_0043b7f0(f3m_00cd5d60::DAT_00df7f18, 200);
    atexit(f3m_00cd5d60::FUN_00d90bb0);
}

// @f3 0x00cc8ea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8ea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63620;
void __cdecl FUN_00d91970();
}

void __cdecl FUN_00cc8ea0()
{
    using namespace f3m_00cc8ea0;
    DAT_00f63620.Setting::Setting();
    atexit(FUN_00d91970);
}

// @f3 0x00cdedf0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdedf0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65900;
void __cdecl FUN_00d947e0();
}

void __cdecl FUN_00cdedf0()
{
    f3m_00cdedf0::DAT_00f65900.Setting::Setting();
    atexit(f3m_00cdedf0::FUN_00d947e0);
}

// @f3 0x00cc9ce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9ce0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f637e8;
void __cdecl FUN_00d91bd0();
}

void __cdecl FUN_00cc9ce0()
{
    f3m_00cc9ce0::DAT_00f637e8.Setting::Setting();
    atexit(f3m_00cc9ce0::FUN_00d91bd0);
}

// @f3 0x00ccd700 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd700 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63f20;
void __cdecl FUN_00d92570();
}

void __cdecl FUN_00ccd700()
{
    f3m_00ccd700::DAT_00f63f20.Setting::Setting();
    atexit(f3m_00ccd700::FUN_00d92570);
}

// @f3 0x00cc8480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8480 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f634dc;
void __cdecl FUN_00d917c0();
}

void __cdecl FUN_00cc8480()
{
    f3m_00cc8480::DAT_00f634dc.Setting::Setting();
    atexit(f3m_00cc8480::FUN_00d917c0);
}

// @f3 0x00cc2ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2ae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62984;
void __cdecl FUN_00d90770();
}

void __cdecl FUN_00cc2ae0()
{
    f3m_00cc2ae0::DAT_00f62984.Setting::Setting();
    atexit(f3m_00cc2ae0::FUN_00d90770);
}

// @f3 0x00cc82a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc82a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f634a0;
void __cdecl FUN_00d91770();
}

void __cdecl FUN_00cc82a0()
{
    f3m_00cc82a0::DAT_00f634a0.Setting::Setting();
    atexit(f3m_00cc82a0::FUN_00d91770);
}

// @f3 0x00cddfc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddfc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65768;
void __cdecl FUN_00d945d0();
}

void __cdecl FUN_00cddfc0()
{
    f3m_00cddfc0::DAT_00f65768.Setting::Setting();
    atexit(f3m_00cddfc0::FUN_00d945d0);
}

// @f3 0x00cddf60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddf60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6575c;
void __cdecl FUN_00d945c0();
}

void __cdecl FUN_00cddf60()
{
    f3m_00cddf60::DAT_00f6575c.Setting::Setting();
    atexit(f3m_00cddf60::FUN_00d945c0);
}

// @f3 0x00cc2d80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2d80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f629d8;
void __cdecl FUN_00d907e0();
}

void __cdecl FUN_00cc2d80()
{
    f3m_00cc2d80::DAT_00f629d8.Setting::Setting();
    atexit(f3m_00cc2d80::FUN_00d907e0);
}

// @f3 0x00ccbde0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccbde0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63bfc;
void __cdecl FUN_00d92140();
}

void __cdecl FUN_00ccbde0()
{
    f3m_00ccbde0::DAT_00f63bfc.Setting::Setting();
    atexit(f3m_00ccbde0::FUN_00d92140);
}

// @f3 0x00cd74c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd74c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65288;
void __cdecl FUN_00d93f50();
}

void __cdecl FUN_00cd74c0()
{
    using namespace f3m_00cd74c0;
    DAT_00f65288.Setting::Setting();
    atexit(FUN_00d93f50);
}

// @f3 0x00cd2da0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2da0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f649f4;
void __cdecl FUN_00d933e0();
}

void __cdecl FUN_00cd2da0()
{
    f3m_00cd2da0::DAT_00f649f4.Setting::Setting();
    atexit(f3m_00cd2da0::FUN_00d933e0);
}

// @f3 0x00cc7e80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7e80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6341c;
void __cdecl FUN_00d916c0();
}

void __cdecl FUN_00cc7e80()
{
    f3m_00cc7e80::DAT_00f6341c.Setting::Setting();
    atexit(f3m_00cc7e80::FUN_00d916c0);
}

// @f3 0x00cc9500 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9500 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f636ec;
void __cdecl FUN_00d91a80();
}

void __cdecl FUN_00cc9500()
{
    using namespace f3m_00cc9500;
    DAT_00f636ec.Setting::Setting();
    atexit(FUN_00d91a80);
}

// @f3 0x00cc0800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0800 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62528;
void __cdecl FUN_00d901a0();
}

void __cdecl FUN_00cc0800()
{
    f3m_00cc0800::DAT_00f62528.Setting::Setting();
    atexit(f3m_00cc0800::FUN_00d901a0);
}

// @f3 0x00cd56e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd56e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f1c;
void __cdecl FUN_00d93ac0();
}

void __cdecl FUN_00cd56e0()
{
    f3m_00cd56e0::DAT_00f64f1c.Setting::Setting();
    atexit(f3m_00cd56e0::FUN_00d93ac0);
}

// @f3 0x00cde7f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde7f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65840;
void __cdecl FUN_00d946e0();
}

void __cdecl FUN_00cde7f0()
{
    using namespace f3m_00cde7f0;
    DAT_00f65840.Setting::Setting();
    atexit(FUN_00d946e0);
}

// @f3 0x00cc0aa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0aa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6257c;
void __cdecl FUN_00d90210();
}

void __cdecl FUN_00cc0aa0()
{
    f3m_00cc0aa0::DAT_00f6257c.Setting::Setting();
    atexit(f3m_00cc0aa0::FUN_00d90210);
}

// @f3 0x00ccc5c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc5c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63cf8;
void __cdecl FUN_00d92290();
}

void __cdecl FUN_00ccc5c0()
{
    using namespace f3m_00ccc5c0;
    DAT_00f63cf8.Setting::Setting();
    atexit(FUN_00d92290);
}

// @f3 0x00cc40a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc40a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62c60;
void __cdecl FUN_00d90c70();
}

void __cdecl FUN_00cc40a0()
{
    using namespace f3m_00cc40a0;
    DAT_00f62c60.Setting::Setting();
    atexit(FUN_00d90c70);
}

// @f3 0x00cd3640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3640 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b08;
void __cdecl FUN_00d93550();
}

void __cdecl FUN_00cd3640()
{
    f3m_00cd3640::DAT_00f64b08.Setting::Setting();
    atexit(f3m_00cd3640::FUN_00d93550);
}

// @f3 0x00ccc9e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc9e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63d7c;
void __cdecl FUN_00d92340();
}

void __cdecl FUN_00ccc9e0()
{
    f3m_00ccc9e0::DAT_00f63d7c.Setting::Setting();
    atexit(f3m_00ccc9e0::FUN_00d92340);
}

// @f3 0x00cc59c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc59c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f84;
void __cdecl FUN_00d910a0();
}

void __cdecl FUN_00cc59c0()
{
    f3m_00cc59c0::DAT_00f62f84.Setting::Setting();
    atexit(f3m_00cc59c0::FUN_00d910a0);
}

// @f3 0x00ccff20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccff20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64424;
void __cdecl FUN_00d92c20();
}

void __cdecl FUN_00ccff20()
{
    using namespace f3m_00ccff20;
    DAT_00f64424.Setting::Setting();
    atexit(FUN_00d92c20);
}

// @f3 0x00cd3400 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64ac0;
void __cdecl FUN_00d934f0();
}

void __cdecl FUN_00cd3400()
{
    using namespace f3m_00cd3400;
    DAT_00f64ac0.Setting::Setting();
    atexit(FUN_00d934f0);
}

// @f3 0x00ccc1a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc1a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63c74;
void __cdecl FUN_00d921e0();
}

void __cdecl FUN_00ccc1a0()
{
    f3m_00ccc1a0::DAT_00f63c74.Setting::Setting();
    atexit(f3m_00ccc1a0::FUN_00d921e0);
}

// @f3 0x00cd3ca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3ca0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64bd4;
void __cdecl FUN_00d93660();
}

void __cdecl FUN_00cd3ca0()
{
    f3m_00cd3ca0::DAT_00f64bd4.Setting::Setting();
    atexit(f3m_00cd3ca0::FUN_00d93660);
}

// @f3 0x00ccfe00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccfe00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64400;
void __cdecl FUN_00d92bf0();
}

void __cdecl FUN_00ccfe00()
{
    using namespace f3m_00ccfe00;
    DAT_00f64400.Setting::Setting();
    atexit(FUN_00d92bf0);
}

// @f3 0x00cd8ba0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8ba0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65564;
void __cdecl FUN_00d94320();
}

void __cdecl FUN_00cd8ba0()
{
    using namespace f3m_00cd8ba0;
    DAT_00f65564.Setting::Setting();
    atexit(FUN_00d94320);
}

// @f3 0x00cd8300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8300 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65450;
void __cdecl FUN_00d941b0();
}

void __cdecl FUN_00cd8300()
{
    f3m_00cd8300::DAT_00f65450.Setting::Setting();
    atexit(f3m_00cd8300::FUN_00d941b0);
}

// @f3 0x00cc9e00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9e00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6380c;
void __cdecl FUN_00d91c00();
}

void __cdecl FUN_00cc9e00()
{
    f3m_00cc9e00::DAT_00f6380c.Setting::Setting();
    atexit(f3m_00cc9e00::FUN_00d91c00);
}

// @f3 0x00cd1660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1660 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6470c;
void __cdecl FUN_00d93000();
}

void __cdecl FUN_00cd1660()
{
    f3m_00cd1660::DAT_00f6470c.Setting::Setting();
    atexit(f3m_00cd1660::FUN_00d93000);
}

// @f3 0x00cd3dc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3dc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64bf8;
void __cdecl FUN_00d93690();
}

void __cdecl FUN_00cd3dc0()
{
    f3m_00cd3dc0::DAT_00f64bf8.Setting::Setting();
    atexit(f3m_00cd3dc0::FUN_00d93690);
}

// @f3 0x00ccda60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccda60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63f8c;
void __cdecl FUN_00d92600();
}

void __cdecl FUN_00ccda60()
{
    using namespace f3m_00ccda60;
    DAT_00f63f8c.Setting::Setting();
    atexit(FUN_00d92600);
}

// @f3 0x00ccf800 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf800 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64340;
void __cdecl FUN_00d92af0();
}

void __cdecl FUN_00ccf800()
{
    using namespace f3m_00ccf800;
    DAT_00f64340.Setting::Setting();
    atexit(FUN_00d92af0);
}

// @f3 0x00cd5f60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5f60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64fdc;
void __cdecl FUN_00d93bc0();
}

void __cdecl FUN_00cd5f60()
{
    f3m_00cd5f60::DAT_00f64fdc.Setting::Setting();
    atexit(f3m_00cd5f60::FUN_00d93bc0);
}

// @f3 0x00cc9020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9020 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63650;
void __cdecl FUN_00d919b0();
}

void __cdecl FUN_00cc9020()
{
    f3m_00cc9020::DAT_00f63650.Setting::Setting();
    atexit(f3m_00cc9020::FUN_00d919b0);
}

// @f3 0x00ccc080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc080 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63c50;
void __cdecl FUN_00d921b0();
}

void __cdecl FUN_00ccc080()
{
    f3m_00ccc080::DAT_00f63c50.Setting::Setting();
    atexit(f3m_00ccc080::FUN_00d921b0);
}

// @f3 0x00cc2180 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc2180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62858;
void __cdecl FUN_00d905e0();
}

void __cdecl FUN_00cc2180()
{
    using namespace f3m_00cc2180;
    DAT_00f62858.Setting::Setting();
    atexit(FUN_00d905e0);
}

// @f3 0x00cd8120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8120 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65414;
void __cdecl FUN_00d94160();
}

void __cdecl FUN_00cd8120()
{
    f3m_00cd8120::DAT_00f65414.Setting::Setting();
    atexit(f3m_00cd8120::FUN_00d94160);
}

// @f3 0x00cd1420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1420 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f646c4;
void __cdecl FUN_00d92fa0();
}

void __cdecl FUN_00cd1420()
{
    f3m_00cd1420::DAT_00f646c4.Setting::Setting();
    atexit(f3m_00cd1420::FUN_00d92fa0);
}

// @f3 0x00cdef10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdef10 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65924;
void __cdecl FUN_00d94810();
}

void __cdecl FUN_00cdef10()
{
    f3m_00cdef10::DAT_00f65924.Setting::Setting();
    atexit(f3m_00cdef10::FUN_00d94810);
}

// @f3 0x00cca040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca040 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63854;
void __cdecl FUN_00d91c60();
}

void __cdecl FUN_00cca040()
{
    f3m_00cca040::DAT_00f63854.Setting::Setting();
    atexit(f3m_00cca040::FUN_00d91c60);
}

// @f3 0x00cd3940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3940 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b68;
void __cdecl FUN_00d935d0();
}

void __cdecl FUN_00cd3940()
{
    f3m_00cd3940::DAT_00f64b68.Setting::Setting();
    atexit(f3m_00cd3940::FUN_00d935d0);
}

// @f3 0x00cd2c80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2c80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f649d0;
void __cdecl FUN_00d933b0();
}

void __cdecl FUN_00cd2c80()
{
    f3m_00cd2c80::DAT_00f649d0.Setting::Setting();
    atexit(f3m_00cd2c80::FUN_00d933b0);
}

// @f3 0x00cd30a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd30a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64a54;
void __cdecl FUN_00d93460();
}

void __cdecl FUN_00cd30a0()
{
    using namespace f3m_00cd30a0;
    DAT_00f64a54.Setting::Setting();
    atexit(FUN_00d93460);
}

// @f3 0x00ccf7a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf7a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64334;
void __cdecl FUN_00d92ae0();
}

void __cdecl FUN_00ccf7a0()
{
    using namespace f3m_00ccf7a0;
    DAT_00f64334.Setting::Setting();
    atexit(FUN_00d92ae0);
}

// @f3 0x00cd0e80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0e80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64610;
void __cdecl FUN_00d92eb0();
}

void __cdecl FUN_00cd0e80()
{
    f3m_00cd0e80::DAT_00f64610.Setting::Setting();
    atexit(f3m_00cd0e80::FUN_00d92eb0);
}

// @f3 0x00cc55a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc55a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f00;
void __cdecl FUN_00d90ff0();
}

void __cdecl FUN_00cc55a0()
{
    f3m_00cc55a0::DAT_00f62f00.Setting::Setting();
    atexit(f3m_00cc55a0::FUN_00d90ff0);
}

// @f3 0x00cc7be0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7be0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f633c8;
void __cdecl FUN_00d91650();
}

void __cdecl FUN_00cc7be0()
{
    using namespace f3m_00cc7be0;
    DAT_00f633c8.Setting::Setting();
    atexit(FUN_00d91650);
}

// @f3 0x00cd34c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd34c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64ad8;
void __cdecl FUN_00d93510();
}

void __cdecl FUN_00cd34c0()
{
    f3m_00cd34c0::DAT_00f64ad8.Setting::Setting();
    atexit(f3m_00cd34c0::FUN_00d93510);
}

// @f3 0x00ccff80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccff80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64430;
void __cdecl FUN_00d92c30();
}

void __cdecl FUN_00ccff80()
{
    f3m_00ccff80::DAT_00f64430.Setting::Setting();
    atexit(f3m_00ccff80::FUN_00d92c30);
}

// @f3 0x00cce600 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64100;
void __cdecl FUN_00d927f0();
}

void __cdecl FUN_00cce600()
{
    using namespace f3m_00cce600;
    DAT_00f64100.Setting::Setting();
    atexit(FUN_00d927f0);
}

// @f3 0x00cd1120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1120 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64664;
void __cdecl FUN_00d92f20();
}

void __cdecl FUN_00cd1120()
{
    f3m_00cd1120::DAT_00f64664.Setting::Setting();
    atexit(f3m_00cd1120::FUN_00d92f20);
}

// @f3 0x00cd31c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd31c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a78;
void __cdecl FUN_00d93490();
}

void __cdecl FUN_00cd31c0()
{
    f3m_00cd31c0::DAT_00f64a78.Setting::Setting();
    atexit(f3m_00cd31c0::FUN_00d93490);
}

// @f3 0x00cc2f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2f00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62a08;
void __cdecl FUN_00d90820();
}

void __cdecl FUN_00cc2f00()
{
    f3m_00cc2f00::DAT_00f62a08.Setting::Setting();
    atexit(f3m_00cc2f00::FUN_00d90820);
}

// @f3 0x00cc7a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7a00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6338c;
void __cdecl FUN_00d91600();
}

void __cdecl FUN_00cc7a00()
{
    f3m_00cc7a00::DAT_00f6338c.Setting::Setting();
    atexit(f3m_00cc7a00::FUN_00d91600);
}

// @f3 0x00cd8a80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd8a80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65540;
void __cdecl FUN_00d942f0();
}

void __cdecl FUN_00cd8a80()
{
    using namespace f3m_00cd8a80;
    DAT_00f65540.Setting::Setting();
    atexit(FUN_00d942f0);
}

// @f3 0x00cc6860 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc6860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63158;
void __cdecl FUN_00d91310();
}

void __cdecl FUN_00cc6860()
{
    using namespace f3m_00cc6860;
    DAT_00f63158.Setting::Setting();
    atexit(FUN_00d91310);
}

// @f3 0x00cd3a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3a60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b8c;
void __cdecl FUN_00d93600();
}

void __cdecl FUN_00cd3a60()
{
    f3m_00cd3a60::DAT_00f64b8c.Setting::Setting();
    atexit(f3m_00cd3a60::FUN_00d93600);
}

// @f3 0x00cde4f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cde4f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f657e0;
void __cdecl FUN_00d94660();
}

void __cdecl FUN_00cde4f0()
{
    using namespace f3m_00cde4f0;
    DAT_00f657e0.Setting::Setting();
    atexit(FUN_00d94660);
}

// @f3 0x00ccbba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccbba0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63bb4;
void __cdecl FUN_00d920e0();
}

void __cdecl FUN_00ccbba0()
{
    f3m_00ccbba0::DAT_00f63bb4.Setting::Setting();
    atexit(f3m_00ccbba0::FUN_00d920e0);
}

// @f3 0x00ccf140 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf140 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64268;
void __cdecl FUN_00d929d0();
}

void __cdecl FUN_00ccf140()
{
    f3m_00ccf140::DAT_00f64268.Setting::Setting();
    atexit(f3m_00ccf140::FUN_00d929d0);
}

// @f3 0x00cc41c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc41c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62c84;
void __cdecl FUN_00d90ca0();
}

void __cdecl FUN_00cc41c0()
{
    f3m_00cc41c0::DAT_00f62c84.Setting::Setting();
    atexit(f3m_00cc41c0::FUN_00d90ca0);
}

// @f3 0x00cca280 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca280 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6389c;
void __cdecl FUN_00d91cc0();
}

void __cdecl FUN_00cca280()
{
    using namespace f3m_00cca280;
    DAT_00f6389c.Setting::Setting();
    atexit(FUN_00d91cc0);
}

// @f3 0x00cd2440 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd2440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f648c8;
void __cdecl FUN_00d93250();
}

void __cdecl FUN_00cd2440()
{
    using namespace f3m_00cd2440;
    DAT_00f648c8.Setting::Setting();
    atexit(FUN_00d93250);
}

// @f3 0x00ccdd00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccdd00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63fe0;
void __cdecl FUN_00d92670();
}

void __cdecl FUN_00ccdd00()
{
    f3m_00ccdd00::DAT_00f63fe0.Setting::Setting();
    atexit(f3m_00ccdd00::FUN_00d92670);
}

// @f3 0x00ccecc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccecc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f641d8;
void __cdecl FUN_00d92910();
}

void __cdecl FUN_00ccecc0()
{
    f3m_00ccecc0::DAT_00f641d8.Setting::Setting();
    atexit(f3m_00ccecc0::FUN_00d92910);
}

// @f3 0x00cd0ac0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0ac0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64598;
void __cdecl FUN_00d92e10();
}

void __cdecl FUN_00cd0ac0()
{
    f3m_00cd0ac0::DAT_00f64598.Setting::Setting();
    atexit(f3m_00cd0ac0::FUN_00d92e10);
}

// @f3 0x00cd4d80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4d80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64df0;
void __cdecl FUN_00d93930();
}

void __cdecl FUN_00cd4d80()
{
    f3m_00cd4d80::DAT_00f64df0.Setting::Setting();
    atexit(f3m_00cd4d80::FUN_00d93930);
}

// @f3 0x00cd6500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6500 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65090;
void __cdecl FUN_00d93cb0();
}

void __cdecl FUN_00cd6500()
{
    f3m_00cd6500::DAT_00f65090.Setting::Setting();
    atexit(f3m_00cd6500::FUN_00d93cb0);
}

// @f3 0x00cc6c20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6c20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f631d0;
void __cdecl FUN_00d913b0();
}

void __cdecl FUN_00cc6c20()
{
    f3m_00cc6c20::DAT_00f631d0.Setting::Setting();
    atexit(f3m_00cc6c20::FUN_00d913b0);
}

// @f3 0x00ccd580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd580 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63ef0;
void __cdecl FUN_00d92530();
}

void __cdecl FUN_00ccd580()
{
    f3m_00ccd580::DAT_00f63ef0.Setting::Setting();
    atexit(f3m_00ccd580::FUN_00d92530);
}

// @f3 0x00cde6d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde6d0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6581c;
void __cdecl FUN_00d946b0();
}

void __cdecl FUN_00cde6d0()
{
    f3m_00cde6d0::DAT_00f6581c.Setting::Setting();
    atexit(f3m_00cde6d0::FUN_00d946b0);
}

// @f3 0x00cc8660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8660 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63518;
void __cdecl FUN_00d91810();
}

void __cdecl FUN_00cc8660()
{
    f3m_00cc8660::DAT_00f63518.Setting::Setting();
    atexit(f3m_00cc8660::FUN_00d91810);
}

// @f3 0x00ccdbe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccdbe0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63fbc;
void __cdecl FUN_00d92640();
}

void __cdecl FUN_00ccdbe0()
{
    f3m_00ccdbe0::DAT_00f63fbc.Setting::Setting();
    atexit(f3m_00ccdbe0::FUN_00d92640);
}

// @f3 0x00cc5a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5a80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f9c;
void __cdecl FUN_00d910c0();
}

void __cdecl FUN_00cc5a80()
{
    f3m_00cc5a80::DAT_00f62f9c.Setting::Setting();
    atexit(f3m_00cc5a80::FUN_00d910c0);
}

// @f3 0x00cc0b60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0b60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62594;
void __cdecl FUN_00d90230();
}

void __cdecl FUN_00cc0b60()
{
    f3m_00cc0b60::DAT_00f62594.Setting::Setting();
    atexit(f3m_00cc0b60::FUN_00d90230);
}

// @f3 0x00cd2680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2680 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64910;
void __cdecl FUN_00d932b0();
}

void __cdecl FUN_00cd2680()
{
    f3m_00cd2680::DAT_00f64910.Setting::Setting();
    atexit(f3m_00cd2680::FUN_00d932b0);
}

// @f3 0x00cc8a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8a80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6359c;
void __cdecl FUN_00d918c0();
}

void __cdecl FUN_00cc8a80()
{
    f3m_00cc8a80::DAT_00f6359c.Setting::Setting();
    atexit(f3m_00cc8a80::FUN_00d918c0);
}

// @f3 0x00cc2a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2a80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62978;
void __cdecl FUN_00d90760();
}

void __cdecl FUN_00cc2a80()
{
    f3m_00cc2a80::DAT_00f62978.Setting::Setting();
    atexit(f3m_00cc2a80::FUN_00d90760);
}

// @f3 0x00cd1840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1840 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64748;
void __cdecl FUN_00d93050();
}

void __cdecl FUN_00cd1840()
{
    f3m_00cd1840::DAT_00f64748.Setting::Setting();
    atexit(f3m_00cd1840::FUN_00d93050);
}

// @f3 0x00cc5900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5900 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f6c;
void __cdecl FUN_00d91080();
}

void __cdecl FUN_00cc5900()
{
    f3m_00cc5900::DAT_00f62f6c.Setting::Setting();
    atexit(f3m_00cc5900::FUN_00d91080);
}

// @f3 0x00cd83c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd83c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65468;
void __cdecl FUN_00d941d0();
}

void __cdecl FUN_00cd83c0()
{
    f3m_00cd83c0::DAT_00f65468.Setting::Setting();
    atexit(f3m_00cd83c0::FUN_00d941d0);
}

// @f3 0x00cca100 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca100 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6386c;
void __cdecl FUN_00d91c80();
}

void __cdecl FUN_00cca100()
{
    f3m_00cca100::DAT_00f6386c.Setting::Setting();
    atexit(f3m_00cca100::FUN_00d91c80);
}

// @f3 0x00cc7940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7940 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63374;
void __cdecl FUN_00d915e0();
}

void __cdecl FUN_00cc7940()
{
    f3m_00cc7940::DAT_00f63374.Setting::Setting();
    atexit(f3m_00cc7940::FUN_00d915e0);
}

// @f3 0x00ccb7e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccb7e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63b3c;
void __cdecl FUN_00d92040();
}

void __cdecl FUN_00ccb7e0()
{
    using namespace f3m_00ccb7e0;
    DAT_00f63b3c.Setting::Setting();
    atexit(FUN_00d92040);
}

// @f3 0x00cc0620 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0620 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f624ec;
void __cdecl FUN_00d90150();
}

void __cdecl FUN_00cc0620()
{
    using namespace f3m_00cc0620;
    DAT_00f624ec.Setting::Setting();
    atexit(FUN_00d90150);
}

// @f3 0x00cd3a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3a00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b80;
void __cdecl FUN_00d935f0();
}

void __cdecl FUN_00cd3a00()
{
    f3m_00cd3a00::DAT_00f64b80.Setting::Setting();
    atexit(f3m_00cd3a00::FUN_00d935f0);
}

// @f3 0x00cd3f40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3f40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c28;
void __cdecl FUN_00d936d0();
}

void __cdecl FUN_00cd3f40()
{
    f3m_00cd3f40::DAT_00f64c28.Setting::Setting();
    atexit(f3m_00cd3f40::FUN_00d936d0);
}

// @f3 0x00cd59e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd59e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f7c;
void __cdecl FUN_00d93b40();
}

void __cdecl FUN_00cd59e0()
{
    f3m_00cd59e0::DAT_00f64f7c.Setting::Setting();
    atexit(f3m_00cd59e0::FUN_00d93b40);
}

// @f3 0x00cc9080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9080 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6365c;
void __cdecl FUN_00d919c0();
}

void __cdecl FUN_00cc9080()
{
    f3m_00cc9080::DAT_00f6365c.Setting::Setting();
    atexit(f3m_00cc9080::FUN_00d919c0);
}

// @f3 0x00cd3100 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3100 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a60;
void __cdecl FUN_00d93470();
}

void __cdecl FUN_00cd3100()
{
    f3m_00cd3100::DAT_00f64a60.Setting::Setting();
    atexit(f3m_00cd3100::FUN_00d93470);
}

// @f3 0x00cce000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce000 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64040;
void __cdecl FUN_00d926f0();
}

void __cdecl FUN_00cce000()
{
    f3m_00cce000::DAT_00f64040.Setting::Setting();
    atexit(f3m_00cce000::FUN_00d926f0);
}

// @f3 0x00cd2860 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2860 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6494c;
void __cdecl FUN_00d93300();
}

void __cdecl FUN_00cd2860()
{
    f3m_00cd2860::DAT_00f6494c.Setting::Setting();
    atexit(f3m_00cd2860::FUN_00d93300);
}

// @f3 0x00cc5420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5420 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ed0;
void __cdecl FUN_00d90fb0();
}

void __cdecl FUN_00cc5420()
{
    f3m_00cc5420::DAT_00f62ed0.Setting::Setting();
    atexit(f3m_00cc5420::FUN_00d90fb0);
}

// @f3 0x00cd8c60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8c60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6557c;
void __cdecl FUN_00d94340();
}

void __cdecl FUN_00cd8c60()
{
    f3m_00cd8c60::DAT_00f6557c.Setting::Setting();
    atexit(f3m_00cd8c60::FUN_00d94340);
}

// @f3 0x00cd7a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7a60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6533c;
void __cdecl FUN_00d94040();
}

void __cdecl FUN_00cd7a60()
{
    f3m_00cd7a60::DAT_00f6533c.Setting::Setting();
    atexit(f3m_00cd7a60::FUN_00d94040);
}

// @f3 0x00cc3920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3920 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b4c;
void __cdecl FUN_00d909d0();
}

void __cdecl FUN_00cc3920()
{
    f3m_00cc3920::DAT_00f62b4c.Setting::Setting();
    atexit(f3m_00cc3920::FUN_00d909d0);
}

// @f3 0x00cca7c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca7c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63944;
void __cdecl FUN_00d91da0();
}

void __cdecl FUN_00cca7c0()
{
    f3m_00cca7c0::DAT_00f63944.Setting::Setting();
    atexit(f3m_00cca7c0::FUN_00d91da0);
}

// @f3 0x00cd7fa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7fa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f653e4;
void __cdecl FUN_00d94120();
}

void __cdecl FUN_00cd7fa0()
{
    f3m_00cd7fa0::DAT_00f653e4.Setting::Setting();
    atexit(f3m_00cd7fa0::FUN_00d94120);
}

// @f3 0x00cd4d20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4d20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64de4;
void __cdecl FUN_00d93920();
}

void __cdecl FUN_00cd4d20()
{
    f3m_00cd4d20::DAT_00f64de4.Setting::Setting();
    atexit(f3m_00cd4d20::FUN_00d93920);
}

// @f3 0x00cc4460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4460 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62cd8;
void __cdecl FUN_00d90d10();
}

void __cdecl FUN_00cc4460()
{
    f3m_00cc4460::DAT_00f62cd8.Setting::Setting();
    atexit(f3m_00cc4460::FUN_00d90d10);
}

// @f3 0x00cd0a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0a00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64580;
void __cdecl FUN_00d92df0();
}

void __cdecl FUN_00cd0a00()
{
    f3m_00cd0a00::DAT_00f64580.Setting::Setting();
    atexit(f3m_00cd0a00::FUN_00d92df0);
}

// @f3 0x00cd22c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd22c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64898;
void __cdecl FUN_00d93210();
}

void __cdecl FUN_00cd22c0()
{
    f3m_00cd22c0::DAT_00f64898.Setting::Setting();
    atexit(f3m_00cd22c0::FUN_00d93210);
}

// @f3 0x00cca3a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca3a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f638c0;
void __cdecl FUN_00d91cf0();
}

void __cdecl FUN_00cca3a0()
{
    f3m_00cca3a0::DAT_00f638c0.Setting::Setting();
    atexit(f3m_00cca3a0::FUN_00d91cf0);
}

// @f3 0x00cdef70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdef70 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65930;
void __cdecl FUN_00d94820();
}

void __cdecl FUN_00cdef70()
{
    f3m_00cdef70::DAT_00f65930.Setting::Setting();
    atexit(f3m_00cdef70::FUN_00d94820);
}

// @f3 0x00ccb2a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb2a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a94;
void __cdecl FUN_00d91f60();
}

void __cdecl FUN_00ccb2a0()
{
    f3m_00ccb2a0::DAT_00f63a94.Setting::Setting();
    atexit(f3m_00ccb2a0::FUN_00d91f60);
}

// @f3 0x00cd8de0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8de0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f655ac;
void __cdecl FUN_00d94380();
}

void __cdecl FUN_00cd8de0()
{
    f3m_00cd8de0::DAT_00f655ac.Setting::Setting();
    atexit(f3m_00cd8de0::FUN_00d94380);
}

// @f3 0x00cd4a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4a80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d90;
void __cdecl FUN_00d938b0();
}

void __cdecl FUN_00cd4a80()
{
    f3m_00cd4a80::DAT_00f64d90.Setting::Setting();
    atexit(f3m_00cd4a80::FUN_00d938b0);
}

// @f3 0x00cd38e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd38e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b5c;
void __cdecl FUN_00d935c0();
}

void __cdecl FUN_00cd38e0()
{
    f3m_00cd38e0::DAT_00f64b5c.Setting::Setting();
    atexit(f3m_00cd38e0::FUN_00d935c0);
}

// @f3 0x00cd4300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4300 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64ca0;
void __cdecl FUN_00d93770();
}

void __cdecl FUN_00cd4300()
{
    f3m_00cd4300::DAT_00f64ca0.Setting::Setting();
    atexit(f3m_00cd4300::FUN_00d93770);
}

// @f3 0x00cc3e60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3e60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62bf4;
void __cdecl FUN_00d90ab0();
}

void __cdecl FUN_00cc3e60()
{
    f3m_00cc3e60::DAT_00f62bf4.Setting::Setting();
    atexit(f3m_00cc3e60::FUN_00d90ab0);
}

// @f3 0x00ccf920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf920 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64364;
void __cdecl FUN_00d92b20();
}

void __cdecl FUN_00ccf920()
{
    f3m_00ccf920::DAT_00f64364.Setting::Setting();
    atexit(f3m_00ccf920::FUN_00d92b20);
}

// @f3 0x00cd36a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd36a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b14;
void __cdecl FUN_00d93560();
}

void __cdecl FUN_00cd36a0()
{
    f3m_00cd36a0::DAT_00f64b14.Setting::Setting();
    atexit(f3m_00cd36a0::FUN_00d93560);
}

// @f3 0x00cd2f80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2f80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a30;
void __cdecl FUN_00d93430();
}

void __cdecl FUN_00cd2f80()
{
    f3m_00cd2f80::DAT_00f64a30.Setting::Setting();
    atexit(f3m_00cd2f80::FUN_00d93430);
}

// @f3 0x00ccf200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf200 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64280;
void __cdecl FUN_00d929f0();
}

void __cdecl FUN_00ccf200()
{
    f3m_00ccf200::DAT_00f64280.Setting::Setting();
    atexit(f3m_00ccf200::FUN_00d929f0);
}

// @f3 0x00cc1940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1940 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62750;
void __cdecl FUN_00d90480();
}

void __cdecl FUN_00cc1940()
{
    f3m_00cc1940::DAT_00f62750.Setting::Setting();
    atexit(f3m_00cc1940::FUN_00d90480);
}

// @f3 0x00cd1300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1300 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f646a0;
void __cdecl FUN_00d92f70();
}

void __cdecl FUN_00cd1300()
{
    f3m_00cd1300::DAT_00f646a0.Setting::Setting();
    atexit(f3m_00cd1300::FUN_00d92f70);
}

// @f3 0x00cd1c60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1c60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f647cc;
void __cdecl FUN_00d93100();
}

void __cdecl FUN_00cd1c60()
{
    f3m_00cd1c60::DAT_00f647cc.Setting::Setting();
    atexit(f3m_00cd1c60::FUN_00d93100);
}

// @f3 0x00cc9e60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9e60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63818;
void __cdecl FUN_00d91c10();
}

void __cdecl FUN_00cc9e60()
{
    f3m_00cc9e60::DAT_00f63818.Setting::Setting();
    atexit(f3m_00cc9e60::FUN_00d91c10);
}

// @f3 0x00cc8f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8f00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6362c;
void __cdecl FUN_00d91980();
}

void __cdecl FUN_00cc8f00()
{
    f3m_00cc8f00::DAT_00f6362c.Setting::Setting();
    atexit(f3m_00cc8f00::FUN_00d91980);
}

// @f3 0x00cc2420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2420 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f628ac;
void __cdecl FUN_00d90650();
}

void __cdecl FUN_00cc2420()
{
    f3m_00cc2420::DAT_00f628ac.Setting::Setting();
    atexit(f3m_00cc2420::FUN_00d90650);
}

// @f3 0x00cc3380 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3380 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62a98;
void __cdecl FUN_00d908e0();
}

void __cdecl FUN_00cc3380()
{
    f3m_00cc3380::DAT_00f62a98.Setting::Setting();
    atexit(f3m_00cc3380::FUN_00d908e0);
}

// @f3 0x00ccabe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccabe0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f639bc;
void __cdecl FUN_00d91e40();
}

void __cdecl FUN_00ccabe0()
{
    f3m_00ccabe0::DAT_00f639bc.Setting::Setting();
    atexit(f3m_00ccabe0::FUN_00d91e40);
}

// @f3 0x00cc6140 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6140 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63074;
void __cdecl FUN_00d911e0();
}

void __cdecl FUN_00cc6140()
{
    f3m_00cc6140::DAT_00f63074.Setting::Setting();
    atexit(f3m_00cc6140::FUN_00d911e0);
}

// @f3 0x00cde020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde020 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65774;
void __cdecl FUN_00d945e0();
}

void __cdecl FUN_00cde020()
{
    f3m_00cde020::DAT_00f65774.Setting::Setting();
    atexit(f3m_00cde020::FUN_00d945e0);
}

// @f3 0x00cc26c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc26c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62900;
void __cdecl FUN_00d906c0();
}

void __cdecl FUN_00cc26c0()
{
    f3m_00cc26c0::DAT_00f62900.Setting::Setting();
    atexit(f3m_00cc26c0::FUN_00d906c0);
}

// @f3 0x00cc3500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3500 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ac8;
void __cdecl FUN_00d90920();
}

void __cdecl FUN_00cc3500()
{
    f3m_00cc3500::DAT_00f62ac8.Setting::Setting();
    atexit(f3m_00cc3500::FUN_00d90920);
}

// @f3 0x00cd5740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5740 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f28;
void __cdecl FUN_00d93ad0();
}

void __cdecl FUN_00cd5740()
{
    f3m_00cd5740::DAT_00f64f28.Setting::Setting();
    atexit(f3m_00cd5740::FUN_00d93ad0);
}

// @f3 0x00cd1cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1cc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f647d8;
void __cdecl FUN_00d93110();
}

void __cdecl FUN_00cd1cc0()
{
    f3m_00cd1cc0::DAT_00f647d8.Setting::Setting();
    atexit(f3m_00cd1cc0::FUN_00d93110);
}

// @f3 0x00ccc560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc560 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63cec;
void __cdecl FUN_00d92280();
}

void __cdecl FUN_00ccc560()
{
    f3m_00ccc560::DAT_00f63cec.Setting::Setting();
    atexit(f3m_00ccc560::FUN_00d92280);
}

// @f3 0x00cd3460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3460 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64acc;
void __cdecl FUN_00d93500();
}

void __cdecl FUN_00cd3460()
{
    f3m_00cd3460::DAT_00f64acc.Setting::Setting();
    atexit(f3m_00cd3460::FUN_00d93500);
}

// @f3 0x00cc6e60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6e60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63218;
void __cdecl FUN_00d91410();
}

void __cdecl FUN_00cc6e60()
{
    f3m_00cc6e60::DAT_00f63218.Setting::Setting();
    atexit(f3m_00cc6e60::FUN_00d91410);
}

// @f3 0x00cc2540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2540 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f628d0;
void __cdecl FUN_00d90680();
}

void __cdecl FUN_00cc2540()
{
    f3m_00cc2540::DAT_00f628d0.Setting::Setting();
    atexit(f3m_00cc2540::FUN_00d90680);
}

// @f3 0x00cd6c80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6c80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65180;
void __cdecl FUN_00d93df0();
}

void __cdecl FUN_00cd6c80()
{
    f3m_00cd6c80::DAT_00f65180.Setting::Setting();
    atexit(f3m_00cd6c80::FUN_00d93df0);
}

// @f3 0x00cc87e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc87e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63548;
void __cdecl FUN_00d91850();
}

void __cdecl FUN_00cc87e0()
{
    f3m_00cc87e0::DAT_00f63548.Setting::Setting();
    atexit(f3m_00cc87e0::FUN_00d91850);
}

// @f3 0x00cc5180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5180 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e7c;
void __cdecl FUN_00d90f40();
}

void __cdecl FUN_00cc5180()
{
    f3m_00cc5180::DAT_00f62e7c.Setting::Setting();
    atexit(f3m_00cc5180::FUN_00d90f40);
}

// @f3 0x00ccae20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccae20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a04;
void __cdecl FUN_00d91ea0();
}

void __cdecl FUN_00ccae20()
{
    f3m_00ccae20::DAT_00f63a04.Setting::Setting();
    atexit(f3m_00ccae20::FUN_00d91ea0);
}

// @f3 0x00cca640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca640 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63914;
void __cdecl FUN_00d91d60();
}

void __cdecl FUN_00cca640()
{
    f3m_00cca640::DAT_00f63914.Setting::Setting();
    atexit(f3m_00cca640::FUN_00d91d60);
}

// @f3 0x00cd3760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3760 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b2c;
void __cdecl FUN_00d93580();
}

void __cdecl FUN_00cd3760()
{
    f3m_00cd3760::DAT_00f64b2c.Setting::Setting();
    atexit(f3m_00cd3760::FUN_00d93580);
}

// @f3 0x00cc6e00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6e00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6320c;
void __cdecl FUN_00d91400();
}

void __cdecl FUN_00cc6e00()
{
    f3m_00cc6e00::DAT_00f6320c.Setting::Setting();
    atexit(f3m_00cc6e00::FUN_00d91400);
}

// @f3 0x00cd0640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0640 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64508;
void __cdecl FUN_00d92d50();
}

void __cdecl FUN_00cd0640()
{
    f3m_00cd0640::DAT_00f64508.Setting::Setting();
    atexit(f3m_00cd0640::FUN_00d92d50);
}

// @f3 0x00cc05c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc05c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f624e0;
void __cdecl FUN_00d90140();
}

void __cdecl FUN_00cc05c0()
{
    f3m_00cc05c0::DAT_00f624e0.Setting::Setting();
    atexit(f3m_00cc05c0::FUN_00d90140);
}

// @f3 0x00ccb9c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb9c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63b78;
void __cdecl FUN_00d92090();
}

void __cdecl FUN_00ccb9c0()
{
    f3m_00ccb9c0::DAT_00f63b78.Setting::Setting();
    atexit(f3m_00ccb9c0::FUN_00d92090);
}

// @f3 0x00ccf320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf320 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f642a4;
void __cdecl FUN_00d92a20();
}

void __cdecl FUN_00ccf320()
{
    f3m_00ccf320::DAT_00f642a4.Setting::Setting();
    atexit(f3m_00ccf320::FUN_00d92a20);
}

// @f3 0x00cc8c00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8c00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f635cc;
void __cdecl FUN_00d91900();
}

void __cdecl FUN_00cc8c00()
{
    f3m_00cc8c00::DAT_00f635cc.Setting::Setting();
    atexit(f3m_00cc8c00::FUN_00d91900);
}

// @f3 0x00cca8e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca8e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63968;
void __cdecl FUN_00d91dd0();
}

void __cdecl FUN_00cca8e0()
{
    f3m_00cca8e0::DAT_00f63968.Setting::Setting();
    atexit(f3m_00cca8e0::FUN_00d91dd0);
}

// @f3 0x00cd1de0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1de0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f647fc;
void __cdecl FUN_00d93140();
}

void __cdecl FUN_00cd1de0()
{
    f3m_00cd1de0::DAT_00f647fc.Setting::Setting();
    atexit(f3m_00cd1de0::FUN_00d93140);
}

// @f3 0x00cc3e00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3e00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62be8;
void __cdecl FUN_00d90aa0();
}

void __cdecl FUN_00cc3e00()
{
    f3m_00cc3e00::DAT_00f62be8.Setting::Setting();
    atexit(f3m_00cc3e00::FUN_00d90aa0);
}

// @f3 0x00cc3da0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3da0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62bdc;
void __cdecl FUN_00d90a90();
}

void __cdecl FUN_00cc3da0()
{
    f3m_00cc3da0::DAT_00f62bdc.Setting::Setting();
    atexit(f3m_00cc3da0::FUN_00d90a90);
}

// @f3 0x00cc2660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2660 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f628f4;
void __cdecl FUN_00d906b0();
}

void __cdecl FUN_00cc2660()
{
    f3m_00cc2660::DAT_00f628f4.Setting::Setting();
    atexit(f3m_00cc2660::FUN_00d906b0);
}

// @f3 0x00ccce60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccce60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63e0c;
void __cdecl FUN_00d92400();
}

void __cdecl FUN_00ccce60()
{
    f3m_00ccce60::DAT_00f63e0c.Setting::Setting();
    atexit(f3m_00ccce60::FUN_00d92400);
}

// @f3 0x00cc31a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc31a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62a5c;
void __cdecl FUN_00d90890();
}

void __cdecl FUN_00cc31a0()
{
    f3m_00cc31a0::DAT_00f62a5c.Setting::Setting();
    atexit(f3m_00cc31a0::FUN_00d90890);
}

// @f3 0x00ccc020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc020 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63c44;
void __cdecl FUN_00d921a0();
}

void __cdecl FUN_00ccc020()
{
    f3m_00ccc020::DAT_00f63c44.Setting::Setting();
    atexit(f3m_00ccc020::FUN_00d921a0);
}

// @f3 0x00cc85a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc85a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63500;
void __cdecl FUN_00d917f0();
}

void __cdecl FUN_00cc85a0()
{
    f3m_00cc85a0::DAT_00f63500.Setting::Setting();
    atexit(f3m_00cc85a0::FUN_00d917f0);
}

// @f3 0x00ccd6a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd6a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63f14;
void __cdecl FUN_00d92560();
}

void __cdecl FUN_00ccd6a0()
{
    f3m_00ccd6a0::DAT_00f63f14.Setting::Setting();
    atexit(f3m_00ccd6a0::FUN_00d92560);
}

// @f3 0x00cc2900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2900 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62948;
void __cdecl FUN_00d90720();
}

void __cdecl FUN_00cc2900()
{
    f3m_00cc2900::DAT_00f62948.Setting::Setting();
    atexit(f3m_00cc2900::FUN_00d90720);
}

// @f3 0x00cc67a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc67a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63140;
void __cdecl FUN_00d912f0();
}

void __cdecl FUN_00cc67a0()
{
    f3m_00cc67a0::DAT_00f63140.Setting::Setting();
    atexit(f3m_00cc67a0::FUN_00d912f0);
}

// @f3 0x00cce720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce720 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64124;
void __cdecl FUN_00d92820();
}

void __cdecl FUN_00cce720()
{
    f3m_00cce720::DAT_00f64124.Setting::Setting();
    atexit(f3m_00cce720::FUN_00d92820);
}

// @f3 0x00cc0da0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0da0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f625dc;
void __cdecl FUN_00d90290();
}

void __cdecl FUN_00cc0da0()
{
    f3m_00cc0da0::DAT_00f625dc.Setting::Setting();
    atexit(f3m_00cc0da0::FUN_00d90290);
}

// @f3 0x00cdda20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdda20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f656b4;
void __cdecl FUN_00d944e0();
}

void __cdecl FUN_00cdda20()
{
    f3m_00cdda20::DAT_00f656b4.Setting::Setting();
    atexit(f3m_00cdda20::FUN_00d944e0);
}

// @f3 0x00cc1460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1460 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f626b4;
void __cdecl FUN_00d903b0();
}

void __cdecl FUN_00cc1460()
{
    f3m_00cc1460::DAT_00f626b4.Setting::Setting();
    atexit(f3m_00cc1460::FUN_00d903b0);
}

// @f3 0x00cd4000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4000 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c40;
void __cdecl FUN_00d936f0();
}

void __cdecl FUN_00cd4000()
{
    f3m_00cd4000::DAT_00f64c40.Setting::Setting();
    atexit(f3m_00cd4000::FUN_00d936f0);
}

// @f3 0x00cddba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddba0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f656e4;
void __cdecl FUN_00d94520();
}

void __cdecl FUN_00cddba0()
{
    f3m_00cddba0::DAT_00f656e4.Setting::Setting();
    atexit(f3m_00cddba0::FUN_00d94520);
}

// @f3 0x00ccfc80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccfc80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f643d0;
void __cdecl FUN_00d92bb0();
}

void __cdecl FUN_00ccfc80()
{
    f3m_00ccfc80::DAT_00f643d0.Setting::Setting();
    atexit(f3m_00ccfc80::FUN_00d92bb0);
}

// @f3 0x00cc7ac0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7ac0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f633a4;
void __cdecl FUN_00d91620();
}

void __cdecl FUN_00cc7ac0()
{
    f3m_00cc7ac0::DAT_00f633a4.Setting::Setting();
    atexit(f3m_00cc7ac0::FUN_00d91620);
}

// @f3 0x00ccad60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccad60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f639ec;
void __cdecl FUN_00d91e80();
}

void __cdecl FUN_00ccad60()
{
    f3m_00ccad60::DAT_00f639ec.Setting::Setting();
    atexit(f3m_00ccad60::FUN_00d91e80);
}

// @f3 0x00cc9260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc9260 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63698;
void __cdecl FUN_00d91a10();
}

void __cdecl FUN_00cc9260()
{
    f3m_00cc9260::DAT_00f63698.Setting::Setting();
    atexit(f3m_00cc9260::FUN_00d91a10);
}

// @f3 0x00cc1dc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1dc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f627e0;
void __cdecl FUN_00d90540();
}

void __cdecl FUN_00cc1dc0()
{
    f3m_00cc1dc0::DAT_00f627e0.Setting::Setting();
    atexit(f3m_00cc1dc0::FUN_00d90540);
}

// @f3 0x00ccad00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccad00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f639e0;
void __cdecl FUN_00d91e70();
}

void __cdecl FUN_00ccad00()
{
    f3m_00ccad00::DAT_00f639e0.Setting::Setting();
    atexit(f3m_00ccad00::FUN_00d91e70);
}

// @f3 0x00cd2f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2f20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a24;
void __cdecl FUN_00d93420();
}

void __cdecl FUN_00cd2f20()
{
    f3m_00cd2f20::DAT_00f64a24.Setting::Setting();
    atexit(f3m_00cd2f20::FUN_00d93420);
}

// @f3 0x00cc3860 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3860 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b34;
void __cdecl FUN_00d909b0();
}

void __cdecl FUN_00cc3860()
{
    f3m_00cc3860::DAT_00f62b34.Setting::Setting();
    atexit(f3m_00cc3860::FUN_00d909b0);
}

// @f3 0x00cd6f80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6f80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f651e0;
void __cdecl FUN_00d93e70();
}

void __cdecl FUN_00cd6f80()
{
    f3m_00cd6f80::DAT_00f651e0.Setting::Setting();
    atexit(f3m_00cd6f80::FUN_00d93e70);
}

// @f3 0x00cd0940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0940 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64568;
void __cdecl FUN_00d92dd0();
}

void __cdecl FUN_00cd0940()
{
    f3m_00cd0940::DAT_00f64568.Setting::Setting();
    atexit(f3m_00cd0940::FUN_00d92dd0);
}

// @f3 0x00cc10a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc10a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6263c;
void __cdecl FUN_00d90310();
}

void __cdecl FUN_00cc10a0()
{
    f3m_00cc10a0::DAT_00f6263c.Setting::Setting();
    atexit(f3m_00cc10a0::FUN_00d90310);
}

// @f3 0x00cd10c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd10c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64658;
void __cdecl FUN_00d92f10();
}

void __cdecl FUN_00cd10c0()
{
    f3m_00cd10c0::DAT_00f64658.Setting::Setting();
    atexit(f3m_00cd10c0::FUN_00d92f10);
}

// @f3 0x00cc73a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc73a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f632c0;
void __cdecl FUN_00d914f0();
}

void __cdecl FUN_00cc73a0()
{
    f3m_00cc73a0::DAT_00f632c0.Setting::Setting();
    atexit(f3m_00cc73a0::FUN_00d914f0);
}

// @f3 0x00cd4fc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4fc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64e38;
void __cdecl FUN_00d93990();
}

void __cdecl FUN_00cd4fc0()
{
    f3m_00cd4fc0::DAT_00f64e38.Setting::Setting();
    atexit(f3m_00cd4fc0::FUN_00d93990);
}

// @f3 0x00cd0c40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0c40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f645c8;
void __cdecl FUN_00d92e50();
}

void __cdecl FUN_00cd0c40()
{
    f3m_00cd0c40::DAT_00f645c8.Setting::Setting();
    atexit(f3m_00cd0c40::FUN_00d92e50);
}

// @f3 0x00cd6ce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6ce0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6518c;
void __cdecl FUN_00d93e00();
}

void __cdecl FUN_00cd6ce0()
{
    f3m_00cd6ce0::DAT_00f6518c.Setting::Setting();
    atexit(f3m_00cd6ce0::FUN_00d93e00);
}

// @f3 0x00cc8000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8000 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6344c;
void __cdecl FUN_00d91700();
}

void __cdecl FUN_00cc8000()
{
    f3m_00cc8000::DAT_00f6344c.Setting::Setting();
    atexit(f3m_00cc8000::FUN_00d91700);
}

// @f3 0x00cd6200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6200 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65030;
void __cdecl FUN_00d93c30();
}

void __cdecl FUN_00cd6200()
{
    f3m_00cd6200::DAT_00f65030.Setting::Setting();
    atexit(f3m_00cd6200::FUN_00d93c30);
}

// @f3 0x00cd3c40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3c40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64bc8;
void __cdecl FUN_00d93650();
}

void __cdecl FUN_00cd3c40()
{
    f3m_00cd3c40::DAT_00f64bc8.Setting::Setting();
    atexit(f3m_00cd3c40::FUN_00d93650);
}

// @f3 0x00cc2a20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2a20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6296c;
void __cdecl FUN_00d90750();
}

void __cdecl FUN_00cc2a20()
{
    f3m_00cc2a20::DAT_00f6296c.Setting::Setting();
    atexit(f3m_00cc2a20::FUN_00d90750);
}

// @f3 0x00cd5ce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5ce0 {
extern const char DAT_00df7ea4[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107329c;
void __cdecl FUN_00d90b70();
}

// pdb: `dynamic initializer for 'iSweetSpotLengthMaxVeryHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5ce0()
{
    f3m_00cd5ce0::DAT_0107329c.FUN_0043b7f0(f3m_00cd5ce0::DAT_00df7ea4, 25);
    atexit(f3m_00cd5ce0::FUN_00d90b70);
}

// @f3 0x00ccb060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb060 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a4c;
void __cdecl FUN_00d91f00();
}

void __cdecl FUN_00ccb060()
{
    f3m_00ccb060::DAT_00f63a4c.Setting::Setting();
    atexit(f3m_00ccb060::FUN_00d91f00);
}

// @f3 0x00cd4900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4900 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d60;
void __cdecl FUN_00d93870();
}

void __cdecl FUN_00cd4900()
{
    f3m_00cd4900::DAT_00f64d60.Setting::Setting();
    atexit(f3m_00cd4900::FUN_00d93870);
}

// @f3 0x00cd2620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2620 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64904;
void __cdecl FUN_00d932a0();
}

void __cdecl FUN_00cd2620()
{
    f3m_00cd2620::DAT_00f64904.Setting::Setting();
    atexit(f3m_00cd2620::FUN_00d932a0);
}

// @f3 0x00cd2740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2740 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64928;
void __cdecl FUN_00d932d0();
}

void __cdecl FUN_00cd2740()
{
    f3m_00cd2740::DAT_00f64928.Setting::Setting();
    atexit(f3m_00cd2740::FUN_00d932d0);
}

// @f3 0x00ccc260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc260 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63c8c;
void __cdecl FUN_00d92200();
}

void __cdecl FUN_00ccc260()
{
    f3m_00ccc260::DAT_00f63c8c.Setting::Setting();
    atexit(f3m_00ccc260::FUN_00d92200);
}

// @f3 0x00cd5de0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5de0 {
extern const char DAT_00df7f90[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107332c;
void __cdecl FUN_00d90bf0();
}

// pdb: `dynamic initializer for 'iConcentricLengthMaxAverage'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5de0()
{
    f3m_00cd5de0::DAT_0107332c.FUN_0043b7f0(f3m_00cd5de0::DAT_00df7f90, 200);
    atexit(f3m_00cd5de0::FUN_00d90bf0);
}

// @f3 0x00cd2ec0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2ec0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a18;
void __cdecl FUN_00d93410();
}

void __cdecl FUN_00cd2ec0()
{
    f3m_00cd2ec0::DAT_00f64a18.Setting::Setting();
    atexit(f3m_00cd2ec0::FUN_00d93410);
}

// @f3 0x00cd41e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd41e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c7c;
void __cdecl FUN_00d93740();
}

void __cdecl FUN_00cd41e0()
{
    f3m_00cd41e0::DAT_00f64c7c.Setting::Setting();
    atexit(f3m_00cd41e0::FUN_00d93740);
}

// @f3 0x00cd3280 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3280 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64a90;
void __cdecl FUN_00d934b0();
}

void __cdecl FUN_00cd3280()
{
    f3m_00cd3280::DAT_00f64a90.Setting::Setting();
    atexit(f3m_00cd3280::FUN_00d934b0);
}

// @f3 0x00cc2300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2300 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62888;
void __cdecl FUN_00d90620();
}

void __cdecl FUN_00cc2300()
{
    f3m_00cc2300::DAT_00f62888.Setting::Setting();
    atexit(f3m_00cc2300::FUN_00d90620);
}

// @f3 0x00cd0ee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0ee0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6461c;
void __cdecl FUN_00d92ec0();
}

void __cdecl FUN_00cd0ee0()
{
    f3m_00cd0ee0::DAT_00f6461c.Setting::Setting();
    atexit(f3m_00cd0ee0::FUN_00d92ec0);
}

// @f3 0x00cc69e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc69e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63188;
void __cdecl FUN_00d91350();
}

void __cdecl FUN_00cc69e0()
{
    f3m_00cc69e0::DAT_00f63188.Setting::Setting();
    atexit(f3m_00cc69e0::FUN_00d91350);
}

// @f3 0x00cd8f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8f00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f655d0;
void __cdecl FUN_00d943b0();
}

void __cdecl FUN_00cd8f00()
{
    f3m_00cd8f00::DAT_00f655d0.Setting::Setting();
    atexit(f3m_00cd8f00::FUN_00d943b0);
}

// @f3 0x00cd6bc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6bc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65168;
void __cdecl FUN_00d93dd0();
}

void __cdecl FUN_00cd6bc0()
{
    f3m_00cd6bc0::DAT_00f65168.Setting::Setting();
    atexit(f3m_00cd6bc0::FUN_00d93dd0);
}

// @f3 0x00cc0320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0320 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6248c;
void __cdecl FUN_00d900d0();
}

void __cdecl FUN_00cc0320()
{
    f3m_00cc0320::DAT_00f6248c.Setting::Setting();
    atexit(f3m_00cc0320::FUN_00d900d0);
}

// @f3 0x00cd5d80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5d80 {
extern const char DAT_00df7f34[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107335c;
void __cdecl FUN_00d90bc0();
}

// pdb: `dynamic initializer for 'iConcentricLengthMinVeryHard'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5d80()
{
    f3m_00cd5d80::DAT_0107335c.FUN_0043b7f0(f3m_00cd5d80::DAT_00df7f34, 200);
    atexit(f3m_00cd5d80::FUN_00d90bc0);
}

// @f3 0x00cc4340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4340 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62cb4;
void __cdecl FUN_00d90ce0();
}

void __cdecl FUN_00cc4340()
{
    f3m_00cc4340::DAT_00f62cb4.Setting::Setting();
    atexit(f3m_00cc4340::FUN_00d90ce0);
}

// @f3 0x00cc4ca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4ca0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62de0;
void __cdecl FUN_00d90e70();
}

void __cdecl FUN_00cc4ca0()
{
    f3m_00cc4ca0::DAT_00f62de0.Setting::Setting();
    atexit(f3m_00cc4ca0::FUN_00d90e70);
}

// @f3 0x00cc14c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc14c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f626c0;
void __cdecl FUN_00d903c0();
}

void __cdecl FUN_00cc14c0()
{
    f3m_00cc14c0::DAT_00f626c0.Setting::Setting();
    atexit(f3m_00cc14c0::FUN_00d903c0);
}

// @f3 0x00cd8060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8060 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f653fc;
void __cdecl FUN_00d94140();
}

void __cdecl FUN_00cd8060()
{
    f3m_00cd8060::DAT_00f653fc.Setting::Setting();
    atexit(f3m_00cd8060::FUN_00d94140);
}

// @f3 0x00cc51e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc51e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e88;
void __cdecl FUN_00d90f50();
}

void __cdecl FUN_00cc51e0()
{
    f3m_00cc51e0::DAT_00f62e88.Setting::Setting();
    atexit(f3m_00cc51e0::FUN_00d90f50);
}

// @f3 0x00ccfc20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccfc20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f643c4;
void __cdecl FUN_00d92ba0();
}

void __cdecl FUN_00ccfc20()
{
    f3m_00ccfc20::DAT_00f643c4.Setting::Setting();
    atexit(f3m_00ccfc20::FUN_00d92ba0);
}

// @f3 0x00cc3bc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3bc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ba0;
void __cdecl FUN_00d90a40();
}

void __cdecl FUN_00cc3bc0()
{
    f3m_00cc3bc0::DAT_00f62ba0.Setting::Setting();
    atexit(f3m_00cc3bc0::FUN_00d90a40);
}

// @f3 0x00cc2c60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2c60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f629b4;
void __cdecl FUN_00d907b0();
}

void __cdecl FUN_00cc2c60()
{
    f3m_00cc2c60::DAT_00f629b4.Setting::Setting();
    atexit(f3m_00cc2c60::FUN_00d907b0);
}

// @f3 0x00cd8cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8cc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65588;
void __cdecl FUN_00d94350();
}

void __cdecl FUN_00cd8cc0()
{
    f3m_00cd8cc0::DAT_00f65588.Setting::Setting();
    atexit(f3m_00cd8cc0::FUN_00d94350);
}

// @f3 0x00cd1ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1ae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6479c;
void __cdecl FUN_00d930c0();
}

void __cdecl FUN_00cd1ae0()
{
    f3m_00cd1ae0::DAT_00f6479c.Setting::Setting();
    atexit(f3m_00cd1ae0::FUN_00d930c0);
}

// @f3 0x00cd02e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd02e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6449c;
void __cdecl FUN_00d92cc0();
}

void __cdecl FUN_00cd02e0()
{
    f3m_00cd02e0::DAT_00f6449c.Setting::Setting();
    atexit(f3m_00cd02e0::FUN_00d92cc0);
}

// @f3 0x00cca220 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca220 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63890;
void __cdecl FUN_00d91cb0();
}

void __cdecl FUN_00cca220()
{
    f3m_00cca220::DAT_00f63890.Setting::Setting();
    atexit(f3m_00cca220::FUN_00d91cb0);
}

// @f3 0x00cced80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cced80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f641f0;
void __cdecl FUN_00d92930();
}

void __cdecl FUN_00cced80()
{
    f3m_00cced80::DAT_00f641f0.Setting::Setting();
    atexit(f3m_00cced80::FUN_00d92930);
}

// @f3 0x00cc1ca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1ca0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f627bc;
void __cdecl FUN_00d90510();
}

void __cdecl FUN_00cc1ca0()
{
    f3m_00cc1ca0::DAT_00f627bc.Setting::Setting();
    atexit(f3m_00cc1ca0::FUN_00d90510);
}

// @f3 0x00cdec70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdec70 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f658d0;
void __cdecl FUN_00d947a0();
}

void __cdecl FUN_00cdec70()
{
    f3m_00cdec70::DAT_00f658d0.Setting::Setting();
    atexit(f3m_00cdec70::FUN_00d947a0);
}

// @f3 0x00cd4120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4120 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64c64;
void __cdecl FUN_00d93720();
}

void __cdecl FUN_00cd4120()
{
    f3m_00cd4120::DAT_00f64c64.Setting::Setting();
    atexit(f3m_00cd4120::FUN_00d93720);
}

// @f3 0x00cc1040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1040 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62630;
void __cdecl FUN_00d90300();
}

void __cdecl FUN_00cc1040()
{
    f3m_00cc1040::DAT_00f62630.Setting::Setting();
    atexit(f3m_00cc1040::FUN_00d90300);
}

// @f3 0x00ccf5c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccf5c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f642f8;
void __cdecl FUN_00d92a90();
}

void __cdecl FUN_00ccf5c0()
{
    f3m_00ccf5c0::DAT_00f642f8.Setting::Setting();
    atexit(f3m_00ccf5c0::FUN_00d92a90);
}

// @f3 0x00cc4ee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4ee0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e28;
void __cdecl FUN_00d90ed0();
}

void __cdecl FUN_00cc4ee0()
{
    f3m_00cc4ee0::DAT_00f62e28.Setting::Setting();
    atexit(f3m_00cc4ee0::FUN_00d90ed0);
}

// @f3 0x00ccd1c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd1c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63e78;
void __cdecl FUN_00d92490();
}

void __cdecl FUN_00ccd1c0()
{
    f3m_00ccd1c0::DAT_00f63e78.Setting::Setting();
    atexit(f3m_00ccd1c0::FUN_00d92490);
}

// @f3 0x00cc1fa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1fa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6281c;
void __cdecl FUN_00d90590();
}

void __cdecl FUN_00cc1fa0()
{
    f3m_00cc1fa0::DAT_00f6281c.Setting::Setting();
    atexit(f3m_00cc1fa0::FUN_00d90590);
}

// @f3 0x00cccd40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cccd40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63de8;
void __cdecl FUN_00d923d0();
}

void __cdecl FUN_00cccd40()
{
    f3m_00cccd40::DAT_00f63de8.Setting::Setting();
    atexit(f3m_00cccd40::FUN_00d923d0);
}

// @f3 0x00cd6da0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6da0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f651a4;
void __cdecl FUN_00d93e20();
}

void __cdecl FUN_00cd6da0()
{
    f3m_00cd6da0::DAT_00f651a4.Setting::Setting();
    atexit(f3m_00cd6da0::FUN_00d93e20);
}

// @f3 0x00cc1d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1d60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f627d4;
void __cdecl FUN_00d90530();
}

void __cdecl FUN_00cc1d60()
{
    f3m_00cc1d60::DAT_00f627d4.Setting::Setting();
    atexit(f3m_00cc1d60::FUN_00d90530);
}

// @f3 0x00ccfda0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccfda0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f643f4;
void __cdecl FUN_00d92be0();
}

void __cdecl FUN_00ccfda0()
{
    f3m_00ccfda0::DAT_00f643f4.Setting::Setting();
    atexit(f3m_00ccfda0::FUN_00d92be0);
}

// @f3 0x00cc6ce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6ce0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f631e8;
void __cdecl FUN_00d913d0();
}

void __cdecl FUN_00cc6ce0()
{
    f3m_00cc6ce0::DAT_00f631e8.Setting::Setting();
    atexit(f3m_00cc6ce0::FUN_00d913d0);
}

// @f3 0x00cdec10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdec10 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f658c4;
void __cdecl FUN_00d94790();
}

void __cdecl FUN_00cdec10()
{
    f3m_00cdec10::DAT_00f658c4.Setting::Setting();
    atexit(f3m_00cdec10::FUN_00d94790);
}

// @f3 0x00cc3800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3800 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b28;
void __cdecl FUN_00d909a0();
}

void __cdecl FUN_00cc3800()
{
    f3m_00cc3800::DAT_00f62b28.Setting::Setting();
    atexit(f3m_00cc3800::FUN_00d909a0);
}

// @f3 0x00cdeeb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdeeb0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65918;
void __cdecl FUN_00d94800();
}

void __cdecl FUN_00cdeeb0()
{
    f3m_00cdeeb0::DAT_00f65918.Setting::Setting();
    atexit(f3m_00cdeeb0::FUN_00d94800);
}

// @f3 0x00cd82a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd82a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65444;
void __cdecl FUN_00d941a0();
}

void __cdecl FUN_00cd82a0()
{
    f3m_00cd82a0::DAT_00f65444.Setting::Setting();
    atexit(f3m_00cd82a0::FUN_00d941a0);
}

// @f3 0x00cd4b40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4b40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64da8;
void __cdecl FUN_00d938d0();
}

void __cdecl FUN_00cd4b40()
{
    f3m_00cd4b40::DAT_00f64da8.Setting::Setting();
    atexit(f3m_00cd4b40::FUN_00d938d0);
}

// @f3 0x00cc8fc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc8fc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63644;
void __cdecl FUN_00d919a0();
}

void __cdecl FUN_00cc8fc0()
{
    f3m_00cc8fc0::DAT_00f63644.Setting::Setting();
    atexit(f3m_00cc8fc0::FUN_00d919a0);
}

// @f3 0x00cc38c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc38c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b40;
void __cdecl FUN_00d909c0();
}

void __cdecl FUN_00cc38c0()
{
    f3m_00cc38c0::DAT_00f62b40.Setting::Setting();
    atexit(f3m_00cc38c0::FUN_00d909c0);
}

// @f3 0x00cde3d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde3d0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f657bc;
void __cdecl FUN_00d94630();
}

void __cdecl FUN_00cde3d0()
{
    f3m_00cde3d0::DAT_00f657bc.Setting::Setting();
    atexit(f3m_00cde3d0::FUN_00d94630);
}

// @f3 0x00cc0fe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0fe0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62624;
void __cdecl FUN_00d902f0();
}

void __cdecl FUN_00cc0fe0()
{
    f3m_00cc0fe0::DAT_00f62624.Setting::Setting();
    atexit(f3m_00cc0fe0::FUN_00d902f0);
}

// @f3 0x00ccc500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc500 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63ce0;
void __cdecl FUN_00d92270();
}

void __cdecl FUN_00ccc500()
{
    f3m_00ccc500::DAT_00f63ce0.Setting::Setting();
    atexit(f3m_00ccc500::FUN_00d92270);
}

// @f3 0x00cd8720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8720 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f654d4;
void __cdecl FUN_00d94260();
}

void __cdecl FUN_00cd8720()
{
    f3m_00cd8720::DAT_00f654d4.Setting::Setting();
    atexit(f3m_00cd8720::FUN_00d94260);
}

// @f3 0x00cd73a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd73a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65264;
void __cdecl FUN_00d93f20();
}

void __cdecl FUN_00cd73a0()
{
    f3m_00cd73a0::DAT_00f65264.Setting::Setting();
    atexit(f3m_00cd73a0::FUN_00d93f20);
}

// @f3 0x00cd7460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7460 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6527c;
void __cdecl FUN_00d93f40();
}

void __cdecl FUN_00cd7460()
{
    f3m_00cd7460::DAT_00f6527c.Setting::Setting();
    atexit(f3m_00cd7460::FUN_00d93f40);
}

// @f3 0x00cd6a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6a40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65138;
void __cdecl FUN_00d93d90();
}

void __cdecl FUN_00cd6a40()
{
    f3m_00cd6a40::DAT_00f65138.Setting::Setting();
    atexit(f3m_00cd6a40::FUN_00d93d90);
}

// @f3 0x00ccaee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccaee0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63a1c;
void __cdecl FUN_00d91ec0();
}

void __cdecl FUN_00ccaee0()
{
    f3m_00ccaee0::DAT_00f63a1c.Setting::Setting();
    atexit(f3m_00ccaee0::FUN_00d91ec0);
}

// @f3 0x00cdfbf0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cdfbf0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65f20;
void __cdecl FUN_00d94a70();
}

void __cdecl FUN_00cdfbf0()
{
    f3m_00cdfbf0::DAT_00f65f20.Setting::Setting();
    atexit(f3m_00cdfbf0::FUN_00d94a70);
}

// @f3 0x00cd00a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd00a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64454;
void __cdecl FUN_00d92c60();
}

void __cdecl FUN_00cd00a0()
{
    f3m_00cd00a0::DAT_00f64454.Setting::Setting();
    atexit(f3m_00cd00a0::FUN_00d92c60);
}

// @f3 0x00cc3b00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc3b00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62b88;
void __cdecl FUN_00d90a20();
}

void __cdecl FUN_00cc3b00()
{
    f3m_00cc3b00::DAT_00f62b88.Setting::Setting();
    atexit(f3m_00cc3b00::FUN_00d90a20);
}

// @f3 0x00cd7a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7a00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65330;
void __cdecl FUN_00d94030();
}

void __cdecl FUN_00cd7a00()
{
    f3m_00cd7a00::DAT_00f65330.Setting::Setting();
    atexit(f3m_00cd7a00::FUN_00d94030);
}

// @f3 0x00cd5800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5800 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f40;
void __cdecl FUN_00d93af0();
}

void __cdecl FUN_00cd5800()
{
    f3m_00cd5800::DAT_00f64f40.Setting::Setting();
    atexit(f3m_00cd5800::FUN_00d93af0);
}

// @f3 0x00cc5fc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5fc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63044;
void __cdecl FUN_00d911a0();
}

void __cdecl FUN_00cc5fc0()
{
    f3m_00cc5fc0::DAT_00f63044.Setting::Setting();
    atexit(f3m_00cc5fc0::FUN_00d911a0);
}

// @f3 0x00cd9140 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd9140 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65618;
void __cdecl FUN_00d94410();
}

void __cdecl FUN_00cd9140()
{
    f3m_00cd9140::DAT_00f65618.Setting::Setting();
    atexit(f3m_00cd9140::FUN_00d94410);
}

// @f3 0x00cde790 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde790 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65834;
void __cdecl FUN_00d946d0();
}

void __cdecl FUN_00cde790()
{
    f3m_00cde790::DAT_00f65834.Setting::Setting();
    atexit(f3m_00cde790::FUN_00d946d0);
}

// @f3 0x00cd1f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1f00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64820;
void __cdecl FUN_00d93170();
}

void __cdecl FUN_00cd1f00()
{
    f3m_00cd1f00::DAT_00f64820.Setting::Setting();
    atexit(f3m_00cd1f00::FUN_00d93170);
}

// @f3 0x00cd5ea0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5ea0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64fc4;
void __cdecl FUN_00d93ba0();
}

void __cdecl FUN_00cd5ea0()
{
    f3m_00cd5ea0::DAT_00f64fc4.Setting::Setting();
    atexit(f3m_00cd5ea0::FUN_00d93ba0);
}

// @f3 0x00cd8a20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8a20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65534;
void __cdecl FUN_00d942e0();
}

void __cdecl FUN_00cd8a20()
{
    f3m_00cd8a20::DAT_00f65534.Setting::Setting();
    atexit(f3m_00cd8a20::FUN_00d942e0);
}

// @f3 0x00cd0100 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0100 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64460;
void __cdecl FUN_00d92c70();
}

void __cdecl FUN_00cd0100()
{
    f3m_00cd0100::DAT_00f64460.Setting::Setting();
    atexit(f3m_00cd0100::FUN_00d92c70);
}

// @f3 0x00cc0c20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0c20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f625ac;
void __cdecl FUN_00d90250();
}

void __cdecl FUN_00cc0c20()
{
    f3m_00cc0c20::DAT_00f625ac.Setting::Setting();
    atexit(f3m_00cc0c20::FUN_00d90250);
}

// @f3 0x00cd6ec0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6ec0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f651c8;
void __cdecl FUN_00d93e50();
}

void __cdecl FUN_00cd6ec0()
{
    f3m_00cd6ec0::DAT_00f651c8.Setting::Setting();
    atexit(f3m_00cd6ec0::FUN_00d93e50);
}

// @f3 0x00cc0d40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0d40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f625d0;
void __cdecl FUN_00d90280();
}

void __cdecl FUN_00cc0d40()
{
    f3m_00cc0d40::DAT_00f625d0.Setting::Setting();
    atexit(f3m_00cc0d40::FUN_00d90280);
}

// @f3 0x00cc6080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6080 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6305c;
void __cdecl FUN_00d911c0();
}

void __cdecl FUN_00cc6080()
{
    f3m_00cc6080::DAT_00f6305c.Setting::Setting();
    atexit(f3m_00cc6080::FUN_00d911c0);
}

// @f3 0x00cc5840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5840 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62f54;
void __cdecl FUN_00d91060();
}

void __cdecl FUN_00cc5840()
{
    f3m_00cc5840::DAT_00f62f54.Setting::Setting();
    atexit(f3m_00cc5840::FUN_00d91060);
}

// @f3 0x00cddae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddae0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f656cc;
void __cdecl FUN_00d94500();
}

void __cdecl FUN_00cddae0()
{
    f3m_00cddae0::DAT_00f656cc.Setting::Setting();
    atexit(f3m_00cddae0::FUN_00d94500);
}

// @f3 0x00cc50c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc50c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e64;
void __cdecl FUN_00d90f20();
}

void __cdecl FUN_00cc50c0()
{
    f3m_00cc50c0::DAT_00f62e64.Setting::Setting();
    atexit(f3m_00cc50c0::FUN_00d90f20);
}

// @f3 0x00cc75e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc75e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63308;
void __cdecl FUN_00d91550();
}

void __cdecl FUN_00cc75e0()
{
    f3m_00cc75e0::DAT_00f63308.Setting::Setting();
    atexit(f3m_00cc75e0::FUN_00d91550);
}

// @f3 0x00cd67a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd67a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f650e4;
void __cdecl FUN_00d93d20();
}

void __cdecl FUN_00cd67a0()
{
    f3m_00cd67a0::DAT_00f650e4.Setting::Setting();
    atexit(f3m_00cd67a0::FUN_00d93d20);
}

// @f3 0x00ccb420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccb420 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63ac4;
void __cdecl FUN_00d91fa0();
}

void __cdecl FUN_00ccb420()
{
    f3m_00ccb420::DAT_00f63ac4.Setting::Setting();
    atexit(f3m_00ccb420::FUN_00d91fa0);
}

// @f3 0x00ccc6e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccc6e0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63d1c;
void __cdecl FUN_00d922c0();
}

void __cdecl FUN_00ccc6e0()
{
    f3m_00ccc6e0::DAT_00f63d1c.Setting::Setting();
    atexit(f3m_00ccc6e0::FUN_00d922c0);
}

// @f3 0x00cd6260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6260 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6503c;
void __cdecl FUN_00d93c40();
}

void __cdecl FUN_00cd6260()
{
    f3m_00cd6260::DAT_00f6503c.Setting::Setting();
    atexit(f3m_00cd6260::FUN_00d93c40);
}

// @f3 0x00cded90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cded90 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f658f4;
void __cdecl FUN_00d947d0();
}

void __cdecl FUN_00cded90()
{
    f3m_00cded90::DAT_00f658f4.Setting::Setting();
    atexit(f3m_00cded90::FUN_00d947d0);
}

// @f3 0x00cc2480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2480 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f628b8;
void __cdecl FUN_00d90660();
}

void __cdecl FUN_00cc2480()
{
    f3m_00cc2480::DAT_00f628b8.Setting::Setting();
    atexit(f3m_00cc2480::FUN_00d90660);
}

// @f3 0x00cce6c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce6c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64118;
void __cdecl FUN_00d92810();
}

void __cdecl FUN_00cce6c0()
{
    f3m_00cce6c0::DAT_00f64118.Setting::Setting();
    atexit(f3m_00cce6c0::FUN_00d92810);
}

// @f3 0x00cd89c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd89c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65528;
void __cdecl FUN_00d942d0();
}

void __cdecl FUN_00cd89c0()
{
    f3m_00cd89c0::DAT_00f65528.Setting::Setting();
    atexit(f3m_00cd89c0::FUN_00d942d0);
}

// @f3 0x00ccde80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccde80 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64010;
void __cdecl FUN_00d926b0();
}

void __cdecl FUN_00ccde80()
{
    f3m_00ccde80::DAT_00f64010.Setting::Setting();
    atexit(f3m_00ccde80::FUN_00d926b0);
}

// @f3 0x00cd1540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1540 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f646e8;
void __cdecl FUN_00d92fd0();
}

void __cdecl FUN_00cd1540()
{
    f3m_00cd1540::DAT_00f646e8.Setting::Setting();
    atexit(f3m_00cd1540::FUN_00d92fd0);
}

// @f3 0x00cde5b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde5b0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f657f8;
void __cdecl FUN_00d94680();
}

void __cdecl FUN_00cde5b0()
{
    f3m_00cde5b0::DAT_00f657f8.Setting::Setting();
    atexit(f3m_00cde5b0::FUN_00d94680);
}

// @f3 0x00ccbf60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccbf60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63c2c;
void __cdecl FUN_00d92180();
}

void __cdecl FUN_00ccbf60()
{
    f3m_00ccbf60::DAT_00f63c2c.Setting::Setting();
    atexit(f3m_00ccbf60::FUN_00d92180);
}

// @f3 0x00cc4e20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4e20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62e10;
void __cdecl FUN_00d90eb0();
}

void __cdecl FUN_00cc4e20()
{
    f3m_00cc4e20::DAT_00f62e10.Setting::Setting();
    atexit(f3m_00cc4e20::FUN_00d90eb0);
}

// @f3 0x00cd0880 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0880 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64550;
void __cdecl FUN_00d92db0();
}

void __cdecl FUN_00cd0880()
{
    f3m_00cd0880::DAT_00f64550.Setting::Setting();
    atexit(f3m_00cd0880::FUN_00d92db0);
}

// @f3 0x00cd3700 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd3700 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64b20;
void __cdecl FUN_00d93570();
}

void __cdecl FUN_00cd3700()
{
    f3m_00cd3700::DAT_00f64b20.Setting::Setting();
    atexit(f3m_00cd3700::FUN_00d93570);
}

// @f3 0x00cc2ea0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2ea0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f629fc;
void __cdecl FUN_00d90810();
}

void __cdecl FUN_00cc2ea0()
{
    f3m_00cc2ea0::DAT_00f629fc.Setting::Setting();
    atexit(f3m_00cc2ea0::FUN_00d90810);
}

// @f3 0x00cc6a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6a40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63194;
void __cdecl FUN_00d91360();
}

void __cdecl FUN_00cc6a40()
{
    f3m_00cc6a40::DAT_00f63194.Setting::Setting();
    atexit(f3m_00cc6a40::FUN_00d91360);
}

// @f3 0x00cce3c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce3c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f640b8;
void __cdecl FUN_00d92790();
}

void __cdecl FUN_00cce3c0()
{
    f3m_00cce3c0::DAT_00f640b8.Setting::Setting();
    atexit(f3m_00cce3c0::FUN_00d92790);
}

// @f3 0x00cd2500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2500 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f648e0;
void __cdecl FUN_00d93270();
}

void __cdecl FUN_00cd2500()
{
    f3m_00cd2500::DAT_00f648e0.Setting::Setting();
    atexit(f3m_00cd2500::FUN_00d93270);
}

// @f3 0x00cc7d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc7d60 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f633f8;
void __cdecl FUN_00d91690();
}

void __cdecl FUN_00cc7d60()
{
    f3m_00cc7d60::DAT_00f633f8.Setting::Setting();
    atexit(f3m_00cc7d60::FUN_00d91690);
}

// @f3 0x00cd7040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7040 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f651f8;
void __cdecl FUN_00d93e90();
}

void __cdecl FUN_00cd7040()
{
    f3m_00cd7040::DAT_00f651f8.Setting::Setting();
    atexit(f3m_00cd7040::FUN_00d93e90);
}

// @f3 0x00ccba20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccba20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63b84;
void __cdecl FUN_00d920a0();
}

void __cdecl FUN_00ccba20()
{
    f3m_00ccba20::DAT_00f63b84.Setting::Setting();
    atexit(f3m_00ccba20::FUN_00d920a0);
}

// @f3 0x00cc5540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc5540 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62ef4;
void __cdecl FUN_00d90fe0();
}

void __cdecl FUN_00cc5540()
{
    f3m_00cc5540::DAT_00f62ef4.Setting::Setting();
    atexit(f3m_00cc5540::FUN_00d90fe0);
}

// @f3 0x00ccd820 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd820 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63f44;
void __cdecl FUN_00d925a0();
}

void __cdecl FUN_00ccd820()
{
    f3m_00ccd820::DAT_00f63f44.Setting::Setting();
    atexit(f3m_00ccd820::FUN_00d925a0);
}

// @f3 0x00ccd220 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccd220 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63e84;
void __cdecl FUN_00d924a0();
}

void __cdecl FUN_00ccd220()
{
    f3m_00ccd220::DAT_00f63e84.Setting::Setting();
    atexit(f3m_00ccd220::FUN_00d924a0);
}

// @f3 0x00cced20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cced20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f641e4;
void __cdecl FUN_00d92920();
}

void __cdecl FUN_00cced20()
{
    f3m_00cced20::DAT_00f641e4.Setting::Setting();
    atexit(f3m_00cced20::FUN_00d92920);
}

// @f3 0x00cce0c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce0c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64058;
void __cdecl FUN_00d92710();
}

void __cdecl FUN_00cce0c0()
{
    f3m_00cce0c0::DAT_00f64058.Setting::Setting();
    atexit(f3m_00cce0c0::FUN_00d92710);
}

// @f3 0x00cd0b20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0b20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f645a4;
void __cdecl FUN_00d92e20();
}

void __cdecl FUN_00cd0b20()
{
    f3m_00cd0b20::DAT_00f645a4.Setting::Setting();
    atexit(f3m_00cd0b20::FUN_00d92e20);
}

// @f3 0x00cca160 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca160 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63878;
void __cdecl FUN_00d91c90();
}

void __cdecl FUN_00cca160()
{
    f3m_00cca160::DAT_00f63878.Setting::Setting();
    atexit(f3m_00cca160::FUN_00d91c90);
}

// @f3 0x00cd33a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd33a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64ab4;
void __cdecl FUN_00d934e0();
}

void __cdecl FUN_00cd33a0()
{
    f3m_00cd33a0::DAT_00f64ab4.Setting::Setting();
    atexit(f3m_00cd33a0::FUN_00d934e0);
}

// @f3 0x00cd0160 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0160 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6446c;
void __cdecl FUN_00d92c80();
}

void __cdecl FUN_00cd0160()
{
    f3m_00cd0160::DAT_00f6446c.Setting::Setting();
    atexit(f3m_00cd0160::FUN_00d92c80);
}

// @f3 0x00cd76a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd76a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f652c4;
void __cdecl FUN_00d93fa0();
}

void __cdecl FUN_00cd76a0()
{
    f3m_00cd76a0::DAT_00f652c4.Setting::Setting();
    atexit(f3m_00cd76a0::FUN_00d93fa0);
}

// @f3 0x00cd5aa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5aa0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64f94;
void __cdecl FUN_00d93b60();
}

void __cdecl FUN_00cd5aa0()
{
    f3m_00cd5aa0::DAT_00f64f94.Setting::Setting();
    atexit(f3m_00cd5aa0::FUN_00d93b60);
}

// @f3 0x00cccb00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cccb00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63da0;
void __cdecl FUN_00d92370();
}

void __cdecl FUN_00cccb00()
{
    f3m_00cccb00::DAT_00f63da0.Setting::Setting();
    atexit(f3m_00cccb00::FUN_00d92370);
}

// @f3 0x00cd7e20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7e20 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f653b4;
void __cdecl FUN_00d940e0();
}

void __cdecl FUN_00cd7e20()
{
    f3m_00cd7e20::DAT_00f653b4.Setting::Setting();
    atexit(f3m_00cd7e20::FUN_00d940e0);
}

// @f3 0x00cd5140 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd5140 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64e68;
void __cdecl FUN_00d939d0();
}

void __cdecl FUN_00cd5140()
{
    f3m_00cd5140::DAT_00f64e68.Setting::Setting();
    atexit(f3m_00cd5140::FUN_00d939d0);
}

// @f3 0x00cd6560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6560 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6509c;
void __cdecl FUN_00d93cc0();
}

void __cdecl FUN_00cd6560()
{
    f3m_00cd6560::DAT_00f6509c.Setting::Setting();
    atexit(f3m_00cd6560::FUN_00d93cc0);
}

// @f3 0x00cd5ca0 (community match, verified in this file)
struct Obj_cd5ca0
{
    int unk00;
    void FUN_0043b7f0(const char* name, int value);
};
extern Obj_cd5ca0 DAT_01073344;
extern const char DAT_00df7e70[];
void __cdecl FUN_00d90b50();

// pdb: `dynamic initializer for 'iSweetSpotLengthMaxAverage'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5ca0()
{
    DAT_01073344.FUN_0043b7f0(DAT_00df7e70, 0x64);
    atexit(FUN_00d90b50);
}

// @f3 0x00cccda0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cccda0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63df4;
void __cdecl FUN_00d923e0();
}

void __cdecl FUN_00cccda0()
{
    f3m_00cccda0::DAT_00f63df4.Setting::Setting();
    atexit(f3m_00cccda0::FUN_00d923e0);
}

// @f3 0x00ccdee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ccdee0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f6401c;
void __cdecl FUN_00d926c0();
}

void __cdecl FUN_00ccdee0()
{
    f3m_00ccdee0::DAT_00f6401c.Setting::Setting();
    atexit(f3m_00ccdee0::FUN_00d926c0);
}

// @f3 0x00cde970 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cde970 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65870;
void __cdecl FUN_00d94720();
}

void __cdecl FUN_00cde970()
{
    f3m_00cde970::DAT_00f65870.Setting::Setting();
    atexit(f3m_00cde970::FUN_00d94720);
}

// @f3 0x00cc76a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc76a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63320;
void __cdecl FUN_00d91570();
}

void __cdecl FUN_00cc76a0()
{
    f3m_00cc76a0::DAT_00f63320.Setting::Setting();
    atexit(f3m_00cc76a0::FUN_00d91570);
}

// @f3 0x00cd4cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd4cc0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64dd8;
void __cdecl FUN_00d93910();
}

void __cdecl FUN_00cd4cc0()
{
    f3m_00cd4cc0::DAT_00f64dd8.Setting::Setting();
    atexit(f3m_00cd4cc0::FUN_00d93910);
}

// @f3 0x00cc4760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4760 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62d38;
void __cdecl FUN_00d90d90();
}

void __cdecl FUN_00cc4760()
{
    f3m_00cc4760::DAT_00f62d38.Setting::Setting();
    atexit(f3m_00cc4760::FUN_00d90d90);
}

// @f3 0x00cd48a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd48a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64d54;
void __cdecl FUN_00d93860();
}

void __cdecl FUN_00cd48a0()
{
    f3m_00cd48a0::DAT_00f64d54.Setting::Setting();
    atexit(f3m_00cd48a0::FUN_00d93860);
}

// @f3 0x00cd2020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd2020 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64844;
void __cdecl FUN_00d931a0();
}

void __cdecl FUN_00cd2020()
{
    f3m_00cd2020::DAT_00f64844.Setting::Setting();
    atexit(f3m_00cd2020::FUN_00d931a0);
}

// @f3 0x00cd0400 (community match, verified in this file)
namespace f3m_00cd0400 {
struct Subject_cd0400;
struct Manager_cd0400 { virtual void v00(); virtual void Register(Subject_cd0400* setting); };
extern Manager_cd0400* DAT_010701a8;
void FUN_00403080();
struct Cleanup_cd0400 {
    void FUN_00403170();
    __forceinline ~Cleanup_cd0400() { FUN_00403170(); }
};
struct Subject_cd0400 : Cleanup_cd0400 {
    __forceinline Subject_cd0400() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Subject_cd0400 DAT_00f644c0;
void __cdecl FUN_00d92cf0();

void __cdecl FUN_00cd0400()
{
    DAT_00f644c0.Subject_cd0400::Subject_cd0400();
    atexit(FUN_00d92cf0);
}
}   // namespace f3m_00cd0400

// @f3 0x00cddc00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cddc00 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f656f0;
void __cdecl FUN_00d94530();
}

void __cdecl FUN_00cddc00()
{
    f3m_00cddc00::DAT_00f656f0.Setting::Setting();
    atexit(f3m_00cddc00::FUN_00d94530);
}

// @f3 0x00cc4580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc4580 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62cfc;
void __cdecl FUN_00d90d40();
}

void __cdecl FUN_00cc4580()
{
    f3m_00cc4580::DAT_00f62cfc.Setting::Setting();
    atexit(f3m_00cc4580::FUN_00d90d40);
}

// @f3 0x00cc2000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc2000 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62828;
void __cdecl FUN_00d905a0();
}

void __cdecl FUN_00cc2000()
{
    f3m_00cc2000::DAT_00f62828.Setting::Setting();
    atexit(f3m_00cc2000::FUN_00d905a0);
}

// @f3 0x00cc0e00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0e00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f625e8;
void __cdecl FUN_00d902a0();

void __cdecl FUN_00cc0e00()
{
    DAT_00f625e8.Setting::Setting();
    atexit(FUN_00d902a0);
}
}

// @f3 0x00ccaf40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccaf40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63a28;
void __cdecl FUN_00d91ed0();

void __cdecl FUN_00ccaf40()
{
    DAT_00f63a28.Setting::Setting();
    atexit(FUN_00d91ed0);
}
}

// @f3 0x00cd5980 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64f70;
void __cdecl FUN_00d93b30();

void __cdecl FUN_00cd5980()
{
    DAT_00f64f70.Setting::Setting();
    atexit(FUN_00d93b30);
}
}

// @f3 0x00ccee40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccee40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64208;
void __cdecl FUN_00d92950();

void __cdecl FUN_00ccee40()
{
    DAT_00f64208.Setting::Setting();
    atexit(FUN_00d92950);
}
}

// @f3 0x00cd4ba0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4ba0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64db4;
void __cdecl FUN_00d938e0();

void __cdecl FUN_00cd4ba0()
{
    DAT_00f64db4.Setting::Setting();
    atexit(FUN_00d938e0);
}
}

// @f3 0x00cce900 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cce900 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64160;
void __cdecl FUN_00d92870();

void __cdecl FUN_00cce900()
{
    DAT_00f64160.Setting::Setting();
    atexit(FUN_00d92870);
}
}

// @f3 0x00cd1000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1000 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f64640;
void __cdecl FUN_00403080();
void __cdecl FUN_00d92ef0();
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}
void __cdecl FUN_00cd1000()
{
    f3m_00cd1000::DAT_00f64640.f3m_00cd1000::SettingRegistration::SettingRegistration();
    atexit(f3m_00cd1000::FUN_00d92ef0);
}

// @f3 0x00cc9aa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9aa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f637a0;
void __cdecl FUN_00d91b70();

void __cdecl FUN_00cc9aa0()
{
    DAT_00f637a0.Setting::Setting();
    atexit(FUN_00d91b70);
}
}

// @f3 0x00cc8120 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8120 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63470;
void __cdecl FUN_00d91730();

void __cdecl FUN_00cc8120()
{
    DAT_00f63470.Setting::Setting();
    atexit(FUN_00d91730);
}
}

// @f3 0x00cca520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63908;
void __cdecl FUN_00d91d50();

void __cdecl FUN_00cca520()
{
    DAT_00f63908.Setting::Setting();
    atexit(FUN_00d91d50);
}
}

// @f3 0x00cc7100 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc7100 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f632cc;
void __cdecl FUN_00d91500();

void __cdecl FUN_00cc7100()
{
    DAT_00f632cc.Setting::Setting();
    atexit(FUN_00d91500);
}
}

// @f3 0x00ccd340 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccd340 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63f1c;
void __cdecl FUN_00d92530();

void __cdecl FUN_00ccd340()
{
    DAT_00f63f1c.Setting::Setting();
    atexit(FUN_00d92530);
}
}

// @f3 0x00cc0200 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc0200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62468;
void __cdecl FUN_00d900a0();

void __cdecl FUN_00cc0200()
{
    DAT_00f62468.Setting::Setting();
    atexit(FUN_00d900a0);
}
}

// @f3 0x00cdf030 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cdf030 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65948;
void __cdecl FUN_00d94840();

void __cdecl FUN_00cdf030()
{
    DAT_00f65948.Setting::Setting();
    atexit(FUN_00d94840);
}
}

// @f3 0x00cc0680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc0680 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f624f8;
void __cdecl FUN_00d90160();

void __cdecl FUN_00cc0680()
{
    DAT_00f624f8.Setting::Setting();
    atexit(FUN_00d90160);
}
}

// @f3 0x00cd1ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1ba0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f647b4;
void __cdecl FUN_00d930e0();

void __cdecl FUN_00cd1ba0()
{
    DAT_00f647b4.Setting::Setting();
    atexit(FUN_00d930e0);
}
}

// @f3 0x00cded30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cded30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f658e8;
void __cdecl FUN_00d947c0();

void __cdecl FUN_00cded30()
{
    DAT_00f658e8.Setting::Setting();
    atexit(FUN_00d947c0);
}
}

// @f3 0x00ccc200 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63c80;
void __cdecl FUN_00d921f0();

void __cdecl FUN_00ccc200()
{
    DAT_00f63c80.Setting::Setting();
    atexit(FUN_00d921f0);
}
}

// @f3 0x00cc8600 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc8600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6350c;
void __cdecl FUN_00d91800();

void __cdecl FUN_00cc8600()
{
    DAT_00f6350c.Setting::Setting();
    atexit(FUN_00d91800);
}
}

// @f3 0x00cc84e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc84e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f634e8;
void __cdecl FUN_00d917d0();

void __cdecl FUN_00cc84e0()
{
    DAT_00f634e8.Setting::Setting();
    atexit(FUN_00d917d0);
}
}

// @f3 0x00cc6fe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc6fe0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63248;
void __cdecl FUN_00d91450();

void __cdecl FUN_00cc6fe0()
{
    DAT_00f63248.Setting::Setting();
    atexit(FUN_00d91450);
}
}

// @f3 0x00cc53c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc53c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62ec4;
void __cdecl FUN_00d90fa0();

void __cdecl FUN_00cc53c0()
{
    DAT_00f62ec4.Setting::Setting();
    atexit(FUN_00d90fa0);
}
}

// @f3 0x00cc54e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc54e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62ee8;
void __cdecl FUN_00d90fd0();
}
void __cdecl FUN_00cc54e0()
{
    f3m_00cc54e0::DAT_00f62ee8.f3m_00cc54e0::Setting::Setting();
    atexit(f3m_00cc54e0::FUN_00d90fd0);
}

// @f3 0x00ccd640 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f63f08;
namespace f3m_00ccd640 {
void __cdecl FUN_00d92550();

void __cdecl FUN_00ccd640()
{
    DAT_00f63f08.RegistrySetting::RegistrySetting();
    atexit(FUN_00d92550);
}
}   // namespace f3m_00ccd640

// @f3 0x00cd3220 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd3220 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64a84;
void __cdecl FUN_00d934a0();

void __cdecl FUN_00cd3220()
{
    DAT_00f64a84.Setting::Setting();
    atexit(FUN_00d934a0);
}
}

// @f3 0x00cd5fc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd5fc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64fe8;
void __cdecl FUN_00d93bd0();

void __cdecl FUN_00cd5fc0()
{
    DAT_00f64fe8.Setting::Setting();
    atexit(FUN_00d93bd0);
}
}

// @f3 0x00cd7640 (community match, verified in this file)
#include <stdlib.h>
extern RegistrySetting DAT_00f652b8;
namespace f3m_00cd7640 {
void __cdecl FUN_00d93f90();

void __cdecl FUN_00cd7640()
{
    DAT_00f652b8.RegistrySetting::RegistrySetting();
    atexit(FUN_00d93f90);
}
}   // namespace f3m_00cd7640

// @f3 0x00cc22a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc22a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6287c;
void __cdecl FUN_00d90610();

void __cdecl FUN_00cc22a0()
{
    DAT_00f6287c.Setting::Setting();
    atexit(FUN_00d90610);
}
}

// @f3 0x00ccc4a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccc4a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63cd4;
void __cdecl FUN_00d92260();

void __cdecl FUN_00ccc4a0()
{
    DAT_00f63cd4.Setting::Setting();
    atexit(FUN_00d92260);
}
}

// @f3 0x00cd4360 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd4360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64cac;
void __cdecl FUN_00d93780();

void __cdecl FUN_00cd4360()
{
    DAT_00f64cac.Setting::Setting();
    atexit(FUN_00d93780);
}
}

// @f3 0x00cc36e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc36e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62b04;
void __cdecl FUN_00d90970();

void __cdecl FUN_00cc36e0()
{
    DAT_00f62b04.Setting::Setting();
    atexit(FUN_00d90970);
}
}

// @f3 0x00cc9da0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc9da0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63800;
void __cdecl FUN_00d91bf0();

void __cdecl FUN_00cc9da0()
{
    DAT_00f63800.Setting::Setting();
    atexit(FUN_00d91bf0);
}
}

// @f3 0x00cc1580 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1580 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6269c;
void __cdecl FUN_00d90390();

void __cdecl FUN_00cc1580()
{
    DAT_00f6269c.Setting::Setting();
    atexit(FUN_00d90390);
}
}

// @f3 0x00ccf1a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccf1a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64274;
void __cdecl FUN_00d929e0();

void __cdecl FUN_00ccf1a0()
{
    DAT_00f64274.Setting::Setting();
    atexit(FUN_00d929e0);
}
}

// @f3 0x00ccbd80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ccbd80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f63bf0;
void __cdecl FUN_00d92130();

void __cdecl FUN_00ccbd80()
{
    DAT_00f63bf0.Setting::Setting();
    atexit(FUN_00d92130);
}
}

// @f3 0x00cd16c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cd16c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f64718;
void __cdecl FUN_00d93010();

void __cdecl FUN_00cd16c0()
{
    DAT_00f64718.Setting::Setting();
    atexit(FUN_00d93010);
}
}

// @f3 0x00cca400 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f638cc;
void __cdecl FUN_00d91d00();
}

void __cdecl FUN_00cca400()
{
    using namespace f3m_00cca400;
    DAT_00f638cc.Setting::Setting();
    atexit(FUN_00d91d00);
}

// @f3 0x00cc2fc0 (community match, verified in this file)
namespace f3m_00cc2fc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62a20;
void __cdecl FUN_00d90840();

void __cdecl FUN_00cc2fc0()
{
    DAT_00f62a20.Setting::Setting();
    atexit(FUN_00d90840);
}
}

// @f3 0x00cdf090 (community match, verified in this file)
namespace f3m_00cdf090 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f65954;
void __cdecl FUN_00d94850();
extern void __cdecl FUN_00c00d1f(void (__cdecl*)()) throw();

void __cdecl FUN_00cdf090()
{
    DAT_00f65954.Setting::Setting();
    FUN_00c00d1f(FUN_00d94850);
}
}

// @f3 0x00cc1880 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc1880 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62738;
void __cdecl FUN_00d90460();

void __cdecl FUN_00cc1880()
{
    DAT_00f62738.Setting::Setting();
    atexit(FUN_00d90460);
}
}

// @f3 0x00cd1240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd1240 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64688;
void __cdecl FUN_00d92f50();
}

void __cdecl FUN_00cd1240()
{
    f3m_00cd1240::DAT_00f64688.Setting::Setting();
    atexit(f3m_00cd1240::FUN_00d92f50);
}

// @f3 0x00cd7ee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd7ee0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f653cc;
void __cdecl FUN_00d94100();
}

void __cdecl FUN_00cd7ee0()
{
    f3m_00cd7ee0::DAT_00f653cc.Setting::Setting();
    atexit(f3m_00cd7ee0::FUN_00d94100);
}

// @f3 0x00cd0f40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0f40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64628;
void __cdecl FUN_00d92ed0();
}

void __cdecl FUN_00cd0f40()
{
    f3m_00cd0f40::DAT_00f64628.Setting::Setting();
    atexit(f3m_00cd0f40::FUN_00d92ed0);
}

// @f3 0x00cd9200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd9200 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65630;
void __cdecl FUN_00d94430();
}

void __cdecl FUN_00cd9200()
{
    f3m_00cd9200::DAT_00f65630.Setting::Setting();
    atexit(f3m_00cd9200::FUN_00d94430);
}

// @f3 0x00cc97a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc97a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63740;
void __cdecl FUN_00d91af0();
}

void __cdecl FUN_00cc97a0()
{
    f3m_00cc97a0::DAT_00f63740.Setting::Setting();
    atexit(f3m_00cc97a0::FUN_00d91af0);
}

// @f3 0x00cd0520 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd0520 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f644e4;
void __cdecl FUN_00d92d20();
}

void __cdecl FUN_00cd0520()
{
    f3m_00cd0520::DAT_00f644e4.Setting::Setting();
    atexit(f3m_00cd0520::FUN_00d92d20);
}

// @f3 0x00cca1c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cca1c0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f63884;
void __cdecl FUN_00d91ca0();
}

void __cdecl FUN_00cca1c0()
{
    f3m_00cca1c0::DAT_00f63884.Setting::Setting();
    atexit(f3m_00cca1c0::FUN_00d91ca0);
}

// @f3 0x00cc43a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc43a0 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f62cc0;
void __cdecl FUN_00d90cf0();
}

void __cdecl FUN_00cc43a0()
{
    f3m_00cc43a0::DAT_00f62cc0.Setting::Setting();
    atexit(f3m_00cc43a0::FUN_00d90cf0);
}

// @f3 0x00cd8480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd8480 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65480;
void __cdecl FUN_00d941f0();
}

void __cdecl FUN_00cd8480()
{
    f3m_00cd8480::DAT_00f65480.Setting::Setting();
    atexit(f3m_00cd8480::FUN_00d941f0);
}

// @f3 0x00ccf440 (community match, verified in this file)
namespace f3m_00ccf440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f642c8;
void __cdecl FUN_00d92a50();

void __cdecl FUN_00ccf440()
{
    DAT_00f642c8.Setting::Setting();
    atexit(FUN_00d92a50);
}
}

// @f3 0x00cd54a0 (community match, verified in this file)
namespace f3m_00cd54a0 {
struct RegistrySetting;
struct Manager { virtual void v00(); virtual void Register(RegistrySetting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct RegistrySetting : Cleanup {
    __forceinline RegistrySetting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern RegistrySetting DAT_00f64ed4;
void __cdecl FUN_00d93a60();
void __cdecl FUN_00c00d1f(void (*p)()) throw();
}

void __cdecl FUN_00cd54a0()
{
    f3m_00cd54a0::DAT_00f64ed4.f3m_00cd54a0::RegistrySetting::RegistrySetting();
    f3m_00cd54a0::FUN_00c00d1f(f3m_00cd54a0::FUN_00d93a60);
}

// @f3 0x00cca880 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cca880 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6395c;
void __cdecl FUN_00d91dc0();

void __cdecl FUN_00cca880()
{
    DAT_00f6395c.Setting::Setting();
    atexit(FUN_00d91dc0);
}
}

// @f3 0x00cce840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cce840 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f64148;
void __cdecl FUN_00d92850();
}

void __cdecl FUN_00cce840()
{
    f3m_00cce840::DAT_00f64148.Setting::Setting();
    atexit(f3m_00cce840::FUN_00d92850);
}

// @f3 0x00cd6320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cd6320 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f65054;
void __cdecl FUN_00d93c60();
}

void __cdecl FUN_00cd6320()
{
    f3m_00cd6320::DAT_00f65054.Setting::Setting();
    atexit(f3m_00cd6320::FUN_00d93c60);
}

// @f3 0x00cc0740 (community match, verified in this file)
namespace f3m_00cc0740 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f62510 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f62510;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d90180();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc0740()
{
    f3m_00cc0740::DAT_00f62510.f3m_00cc0740::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc0740::FUN_00d90180);
}

// @f3 0x00cc1e80 (community match, verified in this file)
namespace f3m_00cc1e80 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f627f8 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f627f8;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d90560();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc1e80()
{
    f3m_00cc1e80::DAT_00f627f8.f3m_00cc1e80::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc1e80::FUN_00d90560);
}

// @f3 0x00cc1c40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cc1c40 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f627b0;
void __cdecl FUN_00d90500();
}

void __cdecl FUN_00cc1c40()
{
    f3m_00cc1c40::DAT_00f627b0.Setting::Setting();
    atexit(f3m_00cc1c40::FUN_00d90500);
}

// @f3 0x00cc25a0 (community match, verified in this file)
namespace f3m_00cc25a0 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f628dc is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f628dc;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d90690();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc25a0()
{
    f3m_00cc25a0::DAT_00f628dc.f3m_00cc25a0::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc25a0::FUN_00d90690);
}

// @f3 0x00cc5660 (community match, verified in this file)
namespace f3m_00cc5660 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f62f18 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f62f18;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d91010();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc5660()
{
    f3m_00cc5660::DAT_00f62f18.f3m_00cc5660::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc5660::FUN_00d91010);
}

// @f3 0x00cc7880 (community match, verified in this file)
namespace f3m_00cc7880 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f6335c is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f6335c;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d915c0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc7880()
{
    f3m_00cc7880::DAT_00f6335c.f3m_00cc7880::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc7880::FUN_00d915c0);
}

// @f3 0x00cc7f40 (community match, verified in this file)
namespace f3m_00cc7f40 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f63434 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f63434;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d916e0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc7f40()
{
    f3m_00cc7f40::DAT_00f63434.f3m_00cc7f40::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc7f40::FUN_00d916e0);
}

// @f3 0x00cc9620 (community match, verified in this file)
namespace f3m_00cc9620 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f63710 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f63710;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d91ab0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc9620()
{
    f3m_00cc9620::DAT_00f63710.f3m_00cc9620::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc9620::FUN_00d91ab0);
}

// @f3 0x00cc96e0 (community match, verified in this file)
namespace f3m_00cc96e0 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f63728 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f63728;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d91ad0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc96e0()
{
    f3m_00cc96e0::DAT_00f63728.f3m_00cc96e0::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc96e0::FUN_00d91ad0);
}

// @f3 0x00cc9d40 (community match, verified in this file)
namespace f3m_00cc9d40 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f637f4 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f637f4;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d91be0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cc9d40()
{
    f3m_00cc9d40::DAT_00f637f4.f3m_00cc9d40::SettingRegistration::SettingRegistration();
    atexit(f3m_00cc9d40::FUN_00d91be0);
}

// @f3 0x00cca5e0 (community match, verified in this file)
namespace f3m_00cca5e0 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f63908 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f63908;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d91d50();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cca5e0()
{
    f3m_00cca5e0::DAT_00f63908.f3m_00cca5e0::SettingRegistration::SettingRegistration();
    atexit(f3m_00cca5e0::FUN_00d91d50);
}

// @f3 0x00ccd460 (community match, verified in this file)
namespace f3m_00ccd460 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f63ecc is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f63ecc;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d92500();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00ccd460()
{
    f3m_00ccd460::DAT_00f63ecc.f3m_00ccd460::SettingRegistration::SettingRegistration();
    atexit(f3m_00ccd460::FUN_00d92500);
}

// @f3 0x00cd0040 (community match, verified in this file)
namespace f3m_00cd0040 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f64448 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f64448;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d92c50();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cd0040()
{
    f3m_00cd0040::DAT_00f64448.f3m_00cd0040::SettingRegistration::SettingRegistration();
    atexit(f3m_00cd0040::FUN_00d92c50);
}

// @f3 0x00cd5920 (community match, verified in this file)
namespace f3m_00cd5920 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f64f64 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f64f64;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d93b20();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cd5920()
{
    f3m_00cd5920::DAT_00f64f64.f3m_00cd5920::SettingRegistration::SettingRegistration();
    atexit(f3m_00cd5920::FUN_00d93b20);
}

// @f3 0x00cd6b00 (community match, verified in this file)
namespace f3m_00cd6b00 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f65150 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f65150;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d93db0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cd6b00()
{
    f3m_00cd6b00::DAT_00f65150.f3m_00cd6b00::SettingRegistration::SettingRegistration();
    atexit(f3m_00cd6b00::FUN_00d93db0);
}

// @f3 0x00cd7160 (community match, verified in this file)
namespace f3m_00cd7160 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f6521c is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f6521c;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d93ec0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cd7160()
{
    f3m_00cd7160::DAT_00f6521c.f3m_00cd7160::SettingRegistration::SettingRegistration();
    atexit(f3m_00cd7160::FUN_00d93ec0);
}

// @f3 0x00cdee50 (community match, verified in this file)
namespace f3m_00cdee50 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f6590c is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f6590c;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d947f0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cdee50()
{
    f3m_00cdee50::DAT_00f6590c.f3m_00cdee50::SettingRegistration::SettingRegistration();
    atexit(f3m_00cdee50::FUN_00d947f0);
}

// @f3 0x00cdfd10 (community match, verified in this file)
namespace f3m_00cdfd10 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f65f44 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f65f44;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d94aa0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00cdfd10()
{
    f3m_00cdfd10::DAT_00f65f44.f3m_00cdfd10::SettingRegistration::SettingRegistration();
    atexit(f3m_00cdfd10::FUN_00d94aa0);
}

// @f3 0x00cc5b40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cc5b40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f62fb4;
void __cdecl FUN_00d910e0();

void __cdecl FUN_00cc5b40()
{
    DAT_00f62fb4.Setting::Setting();
    atexit(FUN_00d910e0);
}
}

// @f3 0x00cd5be0 (community match, verified in this file)
#include <stdlib.h>
extern SettingStandIn DAT_010732fc;
extern const char DAT_00df7dd4[];
namespace f3m_00cd5be0 {

void __cdecl FUN_00d90af0();

// pdb: `dynamic initializer for 'iSweetSpotLengthMinEasy'' | MenuGamesettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cd5be0()
{
    DAT_010732fc.FUN_0043b7f0(DAT_00df7dd4, 200);
    atexit(FUN_00d90af0);
}
}   // namespace f3m_00cd5be0

// @f3 0x00cde220 (community match, verified in this file)
struct Obj010739bc
{
    void FUN_008a8440();
};

extern Obj010739bc DAT_010739bc;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSFaceGenAnimationData.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cde220()
{
    DAT_010739bc.FUN_008a8440();
}

// @f3 0x00cdf350 (community match, verified in this file)
struct Obj01073b28
{
    void FUN_008a8440();
};

extern Obj01073b28 DAT_01073b28;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSFaceGenModel.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cdf350()
{
    DAT_01073b28.FUN_008a8440();
}

// @f3 0x00cdf8f0 (community match, verified in this file)
struct Obj01073bfc
{
    void FUN_008a8440();
};

extern Obj01073bfc DAT_01073bfc;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSFaceGenNiNode.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cdf8f0()
{
    DAT_01073bfc.FUN_008a8440();
}

// @f3 0x00cdfac0 (community match, verified in this file)
struct Obj01073ce0
{
    void FUN_008a8440();
};

extern Obj01073ce0 DAT_01073ce0;

void FUN_00cdfac0()
{
    DAT_01073ce0.FUN_008a8440();
}
