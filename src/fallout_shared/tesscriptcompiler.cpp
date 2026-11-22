// fallout_shared/tesscriptcompiler.cpp: ScriptCompiler, BGSCameraPath, S7f, S5a and more (4 functions)
#include "f3_common.h"
#include "tesscriptcompiler_packet_decls.h"

struct ScriptReferencedObject;
struct ScriptVariableData;
struct Script;
struct CStringArgument
{
    bool GetVariable(ScriptVariableData*);
    ScriptReferencedObject* GetReferencedForm(unsigned int);
    bool GetReferencedForm(ScriptVariableData*, bool, bool);
    bool IsPartialScript();
    void* GetScriptLineList();
    void* GetReferencedObjectList();
    void* GetVariableList();
    void ClearAllScriptLines();
    void ClearAllReferenceObjects();
    void ClearAllVariables();
    void* __vecDelDtor(unsigned int);
    char* input;
    unsigned int m_uiInputOffset;
    int m_eCompilerIndex;
    char m_kScriptName[8];
    int m_eErrorCode;
    bool m_bIsPartialScript;
    char _pad_19[3];
    unsigned int m_uiLastLineNumber;
    char* pOutput;
    unsigned int m_uiOutputOffset;
    char header[20];
    char m_kVariableList[8];
    char m_kReferencedObjectList[8];
    Script* m_pCurrentScript;
    char m_kLineList[8];
};
typedef char _sizecheck_ScriptCompileData[sizeof(CStringArgument) == 88 ? 1 : -1];
struct FUN_00613790_shell : public CStringArgument
{
    void* FUN_00613790();
};

struct S5a
{
    S5a* ValidateScriptNameTables();
};
// @f3 0x00519ab0 (community match, verified in this file)
extern int FUN_00f5a440;
extern int FUN_00f54b58;
extern "C" void __cdecl FUN_00c24b70(const char*);
// pdb: ScriptCompiler::ScriptCompiler | TESScriptCompiler.obj | fnv360_0822_retail, ustr, high
S5a* S5a::ValidateScriptNameTables()
{
    if (FUN_00f5a440 != 0x1238)
        FUN_00c24b70("The script function list doesn't have all the names filled in.\r\n");
    if (FUN_00f54b58 != 0x1cc)
        FUN_00c24b70("The script console-command list doesn't have all the names filled in.\r\n");
    return this;
}


extern "C" void* __cdecl memset(void*, int, unsigned int);

struct ScriptVariableData
{
    char m_auiShapeKeys[0x200];
    unsigned int m_uiVariableID;
    char m_cTypeCode;
    unsigned int m_uiReferenceID;
    unsigned int m_uiFormID;
    void* pForm;
    ScriptVariableData* Reset();
};

int __cdecl FUN_005b3cd0(unsigned short arg1, void* arg2, void* arg3, void* arg4, int arg5, int arg6);

int __cdecl FUN_005b3cd0(unsigned short, void*, void*, void*, int, int);

int __cdecl FUN_005b3cd0(unsigned short, void*, void*, void*, int, int);

void __cdecl _Deallocate(void*);
struct List
{
    bool _ref_008256d0();
    void*& _ref_006815c0();
    void _ref_0063f7b0();
};
struct TESDataHandler
{
    List* GetTESHairList();
    void ClearHairList();
};

void* __cdecl memset(void* dst, int c, unsigned int n);

struct FUN_005af370_shell
{
    unsigned int m_uiValueBeforeData;
    char m_data[0x200];
    unsigned int uiSize;
    unsigned int uiElapsedMilliseconds;
    char m_auiShapeKeys[0x40c - 0x20c];
    unsigned int m_uiValueAfterSecondBuffer;
    char m_pAuxiliaryObject[8];
    unsigned int m_uiTrailingValue;
    FUN_005af370_shell();
};

// @fnv 0x005af370
FUN_005af370_shell::FUN_005af370_shell()
{
    m_uiValueBeforeData = 0;
    uiSize = 0;
    uiElapsedMilliseconds = 0;
    m_uiValueAfterSecondBuffer = 0;
    m_uiTrailingValue = 0;
    memset(m_data, 0, 0x200);
    memset((char*)this + 0x20c, 0, 0x200);
}

namespace fnv_005afeb0 {
struct TESForm
{
    static TESForm* __cdecl LookupFormByEditorID(const char*);
};
struct ScriptVariableData
{
    char pText[512];
    char pad[24];
    ScriptVariableData* Reset();
};
bool __cdecl ResolveScriptCommand(char*);
}  // namespace fnv_005afeb0

namespace fnv_005aedb0 {
template <class T> class BSSimpleList;
struct ScriptReferencedObject;
class Script
{
  public:
    char* GetText();
    static void __cdecl CopyScriptReferences(BSSimpleList<ScriptReferencedObject*>*,
                                             BSSimpleList<ScriptReferencedObject*>*, Script*);
};
class TESObjectREFR
{
  public:
    Script* FUN_005673c0();
};
class BSStr
{
  public:
    bool Set(const char*, unsigned int);
};
class Str6a70
{
  public:
    char* pString;
    unsigned short usLen, usMax;
    Str6a70& operator=(const char*);
};
void* __memcpy(void*, const void*, unsigned int);
enum COMPILER_NAME
{
    COMPILER_NAME_0,
    COMPILER_NAME_1
};

struct FUN_005ae490;
struct FUN_005ae5c0;
template <class A, class B> class ScriptCompileDataT
{
  public:
    char* pText;
    unsigned int uiElapsedMilliseconds;
    COMPILER_NAME m_eCompilerIndex;
    Str6a70 m_pName;
    unsigned int unk14;
    bool bPartial;
    unsigned int unk1C[3];
    unsigned int kHeader[5];
    unsigned int unk3C[2];
    unsigned int kRefObjects[2];
    Script* pScript;
    unsigned int unk50;
    ScriptCompileDataT();
    ~ScriptCompileDataT();
};
typedef ScriptCompileDataT<FUN_005ae490, FUN_005ae5c0> CStringArgument;

class ScriptCompiler
{
  public:
    bool FUN_005aeb90(Script*, CStringArgument*);
    bool FUN_005aedb0(Script* apScript, TESObjectREFR* apOwnerObject, COMPILER_NAME index, bool abOnLoad);
};

}  // namespace fnv_005aedb0

struct BSStr
{
    bool Set(char const*, unsigned int);
    unsigned char _padding[8];
};

struct StrMem : BSStr
{
    StrMem();
    ~StrMem();

    int _field08;
    unsigned char _field0c;
    int _field10;
    char* _field14;
    int _field18;
    unsigned char _field1c[0x14];
};

struct SL
{
    SL();
    ~SL();
    unsigned char _padding[8];
};

void* __cdecl memset(void*, int, unsigned int);
char* __cdecl AllocateZeroed(int, int);

extern char $SG3295[];

struct FUN_005ae490
{
    unsigned char _padding0[4];
    int _field04;
    int _field08;
    StrMem _field0c;
    SL _field3c;
    SL _field44;
    int _field4c;
    SL _field50;

    FUN_005ae490();
};

// @fnv 0x005ae490
FUN_005ae490::FUN_005ae490()
{
    _field0c._field10 = 0;
    _field04 = 0;
    _field0c._field18 = 0;

    _field0c._field14 = AllocateZeroed(1, 0x4000);
    memset(_field0c._field14, 0, 4);
    memset(_field0c._field1c, 0, 0x14);
    memset(_field0c._field14, 0, 4);

    _field08 = 0;
    _field0c._field0c = 0;
    _field4c = 0;

    _field0c.Set($SG3295, 0);

    _field0c._field08 = 0;
}

namespace fnv_005ae5c0 {
struct TESDataHandler
{
    void ClearHairList();
    unsigned char padding[0x0C];
};

struct BSS
{
    unsigned char padding[0x14];
    ~BSS();
};

struct ListX
{
    unsigned char padding[8];
    ~ListX();
};

void __cdecl _Deallocate(void* ptr);
void __fastcall ClearList(void* ptr);
void __fastcall FUN_005ae730(void* ptr);

struct FUN_005ae5c0 : public TESDataHandler, public BSS
{
    char* pOutput;
    unsigned char padding[0x18];
    ListX list1;
    ListX list2;
    unsigned int value;
    ListX list3;

    ~FUN_005ae5c0();
};

// Runs TESDataHandler cleanup, calls two helper teardown routines on this, then deallocates pOutput.
// @fnv 0x005ae5c0
FUN_005ae5c0::~FUN_005ae5c0()
{
    TESDataHandler::ClearHairList();
    ClearList(this);
    FUN_005ae730(this);
    _Deallocate(pOutput);
}
}  // namespace fnv_005ae5c0

extern "C" int __cdecl isalnum(int);
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct ScriptLineBuffer
{
    unsigned int m_uiValueBeforeData;
    char cLine[0x200];
    unsigned int uiSize;
    unsigned int uiElapsedMilliseconds;
    char cOutput[0x200];
    unsigned int m_uiValueAfterSecondBuffer;
    int unk410;
    int unk414;
    unsigned int m_uiTrailingValue;
};

struct ScriptRefHolder;
struct TESForm;
struct TESObjectREFR;
struct Target;
struct ListNode;
struct Item;

int __cdecl FUN_0044a670(ScriptRefHolder* p);

struct TESForm
{
    int FUN_00401170();
};

struct TESObjectREFR
{
    void FUN_00565730();
    Target* FUN_005673c0();
};

struct Target
{
    bool FUN_005ac6a0(ScriptRefHolder* p, int* out);
};

struct ListNode
{
    void*& Slot();
    ListNode* Next();
};

struct Buf
{
    char* GetBuf();
};

struct Item
{
    int value;
    char unk04[0x0c];
    unsigned char flag;
    char unk11[7];
    Buf m_18;
};

struct ScriptRefHolder
{
    char unk00[0x200];
    int m_200;
    signed char m_204;
    char unk205[7];
    int m_20c;
    TESForm* m_210;
};

static const char scriptNameError[] = "You need to start scripts with \"scriptname ScriptName\"";

struct ScriptHeaderView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int variableCount;
    unsigned char scriptType;
    unsigned char flags;
};
struct Script
{
    ScriptHeaderView* FUN_00500940();
    void InitFromCompileData(CStringArgument*);
};
struct ScriptCompiler
{
    bool FUN_005aeb90(Script* script, FUN_00613790_shell* data);
    unsigned int ParseLine(CStringArgument*);
    bool FUN_005b1180(CStringArgument*);
    bool FUN_005aff40(Script*, CStringArgument*, ScriptLineBuffer*);
};

struct Word95
{
    char text[512];
    unsigned int reference;
    char kind;
    int code;
    int variable;
    void* form;
    Word95();
};
struct Line95
{
    unsigned int number;
    char input[512];
    unsigned int size;
    unsigned int cursor;
    char output[512];
    unsigned int outputSize;
    int code;
    unsigned int reference;
    int error;
    Line95();
};
struct Queue95
{
    void FUN_00905820(Line95**);
};
struct Name95
{
    int value;
    int length;
    void FUN_004037f0(const char*, int);
};
struct Compile95
{
    const char* input;
    unsigned int offset;
    int compiler;
    Name95 name;
    int error;
    int unk18;
    unsigned int line;
    Queue95* FUN_00613790();
};
int __cdecl FUN_005af5f0(Compile95*, Word95*, const char*, unsigned int*, int, int);
void __cdecl ReportScriptError(Compile95*, const char*, ...);

// CRT isalnum in the game image
int strcpy_s(char* dst, unsigned int size, const char* src);
void* __memcpy(void* dst, const void* src, unsigned int size);

typedef bool(__cdecl* ScriptParseFunctionB15)(unsigned short usParamCount, void* pParams,
                                              FUN_005af370_shell* pkLineBuffer, CStringArgument* pkData);

int __cdecl FUN_005af5f0(CStringArgument* pkData, ScriptVariableData* pkWord, char* pInput, unsigned int* puiOffset,
                         int a5, int a6);

struct ScriptLineS
{
    unsigned int m_uiLineNumber;
    char padCur[0x40c];
    unsigned int m_uiType;
};
struct ScriptLineNode
{
    ScriptLineS*& FUN_006815c0();
    ScriptLineNode* FUN_00726070();
};
bool __fastcall FUN_008256d0(ScriptLineNode* pkNode);
struct ScriptBufferS
{
    char pad[0x1c];
    unsigned int m_uiCurrentLine;
    ScriptLineNode* FUN_00613790();
};
void ReportScriptError(ScriptBufferS* pkBuffer, const char* pcError);

namespace fnv_005b12c0 {
struct ScriptLine
{
    unsigned int m_uiValueBeforeData;
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
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
};

struct LineNode
{
    ScriptLine** FUN_006815c0();
    LineNode* FUN_00726070();
    bool FUN_008256d0();
};

struct CStringArgument
{
    LineNode* FUN_00613790();
};

void ReportScriptError(CStringArgument* apData, const char* apMsg, ...);

}  // namespace fnv_005b12c0

void __cdecl ReportScriptError(CStringArgument* a, const char* fmt, ...);
unsigned char __cdecl ResolveScriptCommand(ScriptVariableData* w);
int __cdecl strcpy_s(char* dst, unsigned int n, const char* src);
extern "C" int isalnum(int c);

namespace fnv_005afa50 {
struct FUN_005afa50_list
{
    void*& head();
    FUN_005afa50_list* next();
};

struct CStringArgument
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
    FUN_005afa50_list m_kReferencedObjectList;
};

void __cdecl ReportScriptError(void* owner, const char* fmt, const char* name);

}  // namespace fnv_005afa50

#include <stdlib.h>
unsigned int __cdecl FUN_0044a670(const char*);

namespace MsgCompileData {
}
struct MessageParseWord_5b3c
{
    char text[0x200];
    unsigned int reference;
    char type;
    unsigned int function;
    unsigned int variable;
    TESForm* form;
    MessageParseWord_5b3c* Reset();
};
int __cdecl FUN_005af5f0(void*, MessageParseWord_5b3c*, char*, unsigned int*, bool, bool);
void __cdecl ReportScriptError(void*, const char*, ...);
