#include "f3_common.h"
// src/staging/blk_004c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern void(__stdcall* DAT_00fdf28c)(void*, int, int, int);

struct TESObjectREFR;

struct Arr
{
    unsigned int GetSize();
};

namespace fnv_004dcd00 {
struct Arr
{
    unsigned int* GetAt(int);
};
}  // namespace fnv_004dcd00

void __stdcall ClearAndFreePointer(void*);

struct GO
{
    GO& operator=(void*);
};

void Deallocate(void*);

void __cdecl Deallocate(void* p);

extern "C" void* __cdecl NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

void __cdecl _Deallocate(void*);

void __cdecl _Deallocate(void*);

extern void* DAT_011c6d50[43];

extern void*(__stdcall* DAT_00fdf020)(void*, int, int, int, int, int, int);

extern void(__stdcall* DAT_00fdf290)(void*);
struct FUN_004d7440_Class
{
    char _0[8];
    void* p8;
    void* pC;
    void __thiscall FUN_004d7440();
};
// @f3 0x004c1150 (community match, verified in this file)
struct ReleaseTarget {
    void FUN_004d81b0(int mode);
};
struct LinkedNode {
    unsigned int unk00, unk04, unk08;
    ReleaseTarget* target;
};
struct LinkReceiver {
    void FUN_004c0fe0(LinkedNode* node);
};
// pdb: ExteriorCellLoaderTask::Run | ExteriorCellLoader.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: ExteriorCellLoader::~ExteriorCellLoader)
void FUN_004d7440_Class::FUN_004d7440() {
    ((LinkReceiver*)*(void**)((char*)this + 0x18))
        ->FUN_004c0fe0((LinkedNode*)*(void**)((char*)this + 0x1c));
    ((LinkedNode*)*(void**)((char*)this + 0x1c))
        ->target->FUN_004d81b0(1);
}


extern int(__cdecl* DAT_011c6f18)(int, int, int, int);

struct FUN_004d8560_Inner
{
    virtual void f0();
    virtual void* f1();
};
struct FUN_004d8560_Outer
{
    char _0[0x10];
    FUN_004d8560_Inner _10;
};
struct ScriptLocalsX
{
    FUN_004d8560_Outer* GetLocalData();
};

namespace fnv_004d8630 {
struct ScriptLocalsX
{
    void* __thiscall GetLocalData();
};
}  // namespace fnv_004d8630

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int count);

void __cdecl _Deallocate(void*);

void __cdecl _Deallocate(void*);

void Deallocate(void* p);

struct Flt
{
    operator unsigned int();
};
struct Date
{
    ~Date();
};
struct NiNode;

namespace fnv_004dc590 {
struct Flt
{
    operator unsigned int();
};
struct Date
{
    ~Date();
};
struct GlobalObject_00633c90
{
    char _pad;
};
}  // namespace fnv_004dc590

struct G7d1
{
    bool GetBoolValue();
};
G7d1 g_011c726c;

void __cdecl _Deallocate(void*);

extern "C" void __cdecl FUN_00401030(void*);

struct FUN_0040c150
{
    int value0;
    int value4;
    int value8;
    FUN_0040c150(char* text, int index);
};

struct FUN_004d5b60
{
    FUN_0040c150* object;
    int value;
    FUN_004d5b60(int index, int number, int extra);
};

namespace fnv_004d5c80 {
struct FUN_004d5b60
{
    char* m_p0;
    unsigned short m_w4;
    unsigned short m_w6;
    FUN_004d5b60(const char* name, unsigned int index, unsigned short flags);
};
extern void* DAT_011c6d50[43];

}  // namespace fnv_004d5c80

extern void* DAT_011c6d50[43];

extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

void __cdecl _Deallocate(void* p);

struct FUN_004d9070
{
    ~FUN_004d9070();
};

struct InitCommonControls4d63
{
    unsigned long m_ulSize;
    unsigned long m_ulICC;
};
struct Rect4d63
{
    long left;
    long top;
    long right;
    long bottom;
};
struct WndClass4d63
{
    unsigned int style;
    long(__stdcall* lpfnWndProc)(void*, unsigned int, unsigned int, long);
    int cbClsExtra;
    int cbWndExtra;
    void* hInstance;
    void* hIcon;
    void* hCursor;
    void* hbrBackground;
    const char* lpszMenuName;
    const char* lpszClassName;
};

extern int(__stdcall* DAT_00fdf024)(InitCommonControls4d63*);
extern void*(__stdcall* DAT_00fdf280)(void*, const char*);
extern void*(__stdcall* DAT_00fdf2a0)(void*, const char*);
extern void*(__stdcall* DAT_00fdf03c)(int);
extern unsigned short(__stdcall* DAT_00fdf2b4)(const WndClass4d63*);
extern void*(__stdcall* DAT_00fdf2b8)(unsigned long, const char*, const char*, unsigned long, int, int, int, int, void*,
                                      void*, void*, void*);
extern int(__stdcall* DAT_00fdf2bc)(void*, Rect4d63*);
const char* PrepareScriptMessage(const char* pcText, bool bFlag);

const char* __cdecl FUN_00464f30(const char* value, bool format);
typedef int(__stdcall* SendMessageResult64)(void*, int, int, int);
extern void(__stdcall* DAT_00fdf288)(void*, int);
extern void(__stdcall* DAT_00fdf284)(void*);

extern void(__stdcall* DAT_00fdf01c)(void*);

typedef int(__stdcall* SendTreeMessage)(void*, int, int, int);

class NiObject
{
  public:
    int m_aiObject[2];
};

class NiFixedString
{
  public:
    operator const char*() const;
    const char* m_kHandle;
};

struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int m_pkUpdateProcess;
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);
};

class NiAVObject : public NiObject
{
  public:
    void FUN_00450f90(bool bCulled);
    void FUN_00a5a040();
    void Update(NiUpdateData& kUpdateData);
    NiFixedString& GetName();
};

struct NiObject;
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
NiObject* __cdecl FUN_00653270(const NiRTTI*, NiObject*);

const char* __cdecl PrepareScriptMessage(const char* msg, bool flag);

struct NiTArray_Layout;
void __fastcall FUN_005e03d0(NiTArray_Layout*);

void __cdecl TESFurniture_GetMarkerEnabled(char* dst, const char* src, unsigned int count);

typedef int(__stdcall* DAT_00fdf28c_fn)(void*, int, int, void*);

struct Node7
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
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
    virtual void v24(void*);
    void* FUN_006fa820();
};
struct FUN_004d9100
{
    FUN_004d9100(int, int);
    virtual ~FUN_004d9100();
    char pad[12];
    unsigned GetShortAtOffsetA();
    char** FUN_00877a30(unsigned);
    void FUN_005e03d0();
};
Node7* __cdecl FUN_00653270(void*, Node7*);
const char* __cdecl FUN_00464f30(const char*, bool);
const char* __fastcall FUN_00559450(void*);
void __cdecl TESFurniture_GetMarkerEnabled(char*, const char*, unsigned);

namespace fnv_004d80b0 {
struct FUN_004d9100
{
    virtual ~FUN_004d9100();
    unsigned int length;
    unsigned int capacity;
    void* elements;
    FUN_004d9100(unsigned int initialCapacity, unsigned int growthCapacity);
    unsigned int GetShortAtOffsetA();
    void** FUN_00877a30(unsigned int index);
    void FUN_005e03d0();
};
extern void* __cdecl FUN_00653270(const void*, void*);
extern char* __cdecl FUN_00464f30(const void*, int);
extern void __cdecl TESFurniture_GetMarkerEnabled(char*, const char*, unsigned int);
}  // namespace fnv_004d80b0

typedef void*(__stdcall* SendMessage4d86)(void*, int, int, int);

const char* PrepareScriptMessage(const char* pcText, bool bFlag);

typedef void*(__stdcall* SendMessage4d88)(void*, int, int, int);

const char* PrepareScriptMessage(const char* pcText, bool bFlag);

namespace fnv_004d8a40 {

const char* PrepareScriptMessage(const char* pcText, bool bFlag);

struct FUN_004d9100
{
    FUN_004d9100(int aiInitialSize, int iGrowBy);
    virtual ~FUN_004d9100();
    unsigned int GetShortAtOffsetA();
    const char** FUN_00877a30(unsigned int uiIndex);
    void FUN_005e03d0();
    int unk04[3];
};

}  // namespace fnv_004d8a40

char* DAT_01202fa0;

extern int DAT_011c6fbc;

extern unsigned int DAT_0118947c;

extern int DAT_01189480;

extern int DAT_01189468;

extern int DAT_0118946c;

namespace fnv_004dd180 {
int __cdecl FUN_004dc270();
int __cdecl MapIndexToValue(int value);
struct DispatchInterface;
struct DispatchVTable
{
    void* method00;
    void* method01;
    void* method02;
    void* method03;
    void* method04;
    void* method05;
    void* method06;
    void* method07;
    void* method08;
    void* method09;
    void* method10;
    long(__stdcall* dispatch)(DispatchInterface*, int, int, int);
};
struct DispatchInterface
{
    DispatchVTable* vtable;
};
}  // namespace fnv_004dd180

extern float DAT_01189490;

struct DisplayDevice4de1
{
    unsigned long cb;
    char DeviceName[32];
    char DeviceString[128];
    unsigned long StateFlags;
    char DeviceID[128];
    char DeviceKey[128];
};

extern int(__stdcall* DAT_00fdf2f0)(const char*, unsigned long, DisplayDevice4de1*, unsigned long);
extern float DAT_01189490;
extern float DAT_01189498;
extern bool DAT_011c70ed;

extern "C" void __cdecl FUN_00401030(void*);

void* __cdecl operator new(unsigned int uiSize);
void __cdecl operator delete(void* pvMem);

class C4DF040Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};

class C4DF040Point3
{
  public:
    C4DF040Point3();
    C4DF040Point3(float fX, float fY, float fZ);

    C4DF040Point3 operator+(const C4DF040Point3& kPt) const;

    float x;
    float y;
    float z;
};

class C4DF040Point2
{
  public:
    C4DF040Point2();
    C4DF040Point2(float fX, float fY);

    C4DF040Point2 operator+(const C4DF040Point2& kPt) const;

    float x;
    float y;
};

class C4DF040Matrix3
{
  public:
    C4DF040Matrix3();

    void MakeRandomRotation();
    C4DF040Point3 operator*(const C4DF040Point3& kPt) const;

    float m_afEntries[3][3];
};

namespace fnv_004d9070 {

class FUN_004d90d0
{
  public:
    virtual ~FUN_004d90d0();
};

class FUN_004d9070 : public FUN_004d90d0
{
  public:
    virtual ~FUN_004d9070();
};

}  // namespace fnv_004d9070

extern int DAT_011c6fbc;

struct OutT
{
    int x;
    int y;
};
extern int(__stdcall* DAT_00fdf2ec)(int, int);
extern int(__stdcall* DAT_00fdf2e8)(unsigned int, int);
extern int(__stdcall* DAT_00fdf310)(OutT*, int, int);
extern int(__stdcall* DAT_00fdf2a4)(unsigned int, int, int);

class NiAVObject;
struct FUN_004dc540_shell
{
    void FUN_004dc540(NiAVObject*);
};

class BSAudio
{
  public:
    unsigned int FUN_0044ddc0();
};

class GlobalObject_00633c90
{
  public:
    FUN_004dc540_shell* FUN_00559450();
};

extern bool DAT_011c70ed;

extern float DAT_01189498;

namespace fnv_004dc710 {
#include <windows.h>
#include <d3d9.h>

namespace std {
}
int __cdecl FUN_004dc270();
D3DFORMAT __cdecl MapIndexToValue(int format);
extern unsigned int DAT_0118947c;
extern unsigned int DAT_01189480;
extern unsigned int DAT_0118946c;
extern unsigned int DAT_01189468;

}  // namespace fnv_004dc710

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* pcFileName);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* pvModule, const char* pcProcName);
extern int(__stdcall* DAT_00fdf0a8)(void* pvModule);

struct EFAdapterText
{
    unsigned int word00, word04, word08, word0c;
    unsigned int word10, word14, word18, word1c;
    unsigned int word20, word24, word28, word2c;
    unsigned int word30, word34, word38, word3c;
    unsigned int word40, word44, word48, word4c;
    unsigned int word50, word54, word58, word5c;
    unsigned int word60, word64, word68, word6c;
    unsigned int word70, word74, word78, word7c;
    unsigned int word80, word84, word88, word8c;
    unsigned int word90, word94, word98, word9c;
    unsigned int worda0, worda4, worda8, wordac;
    unsigned int wordb0, wordb4, wordb8, wordbc;
    unsigned int wordc0, wordc4, wordc8, wordcc;
    unsigned int wordd0, wordd4, wordd8, worddc;
    unsigned int worde0, worde4, worde8, wordec;
    unsigned int wordf0, wordf4, wordf8, wordfc;
};
struct EFAdapterInfo
{
    int iSize;
    int iAdapterIndex;
    EFAdapterText strUDID;
    int iBusNumber;
    int iDeviceNumber;
    int iFunctionNumber;
    int iVendorID;
    EFAdapterText strAdapterName;
    EFAdapterText strDisplayName;
    int iPresent;
    int iExist;
    EFAdapterText strDriverPath;
    EFAdapterText strDriverPathExt;
    EFAdapterText strPNPString;
    int iOSDisplayIndex;
};
struct EFDisplayTarget
{
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iDisplayMapIndex;
    int iDisplayTargetMask;
    int iDisplayTargetValue;
};
struct EFMode
{
    int iAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
};
struct EFDisplayMap
{
    int iDisplayMapIndex;
    EFMode displayMode;
    int iNumDisplayTarget;
    int iFirstDisplayTargetArrayIndex;
    int iDisplayMapMask;
    int iDisplayMapValue;
};
struct EFSLSTarget
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iDisplayMapIndex;
    int iDisplayTargetMask;
    int iDisplayTargetValue;
    int iGridX;
    int iGridY;
    EFMode viewSize;
    int iSLSTargetMask;
    int iSLSTargetValue;
};
struct EFNativeMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iSLSModeIndex;
    int iModeAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
    int iSLSNativeModeMask;
    int iSLSNativeModeValue;
};
struct EFBezelMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iBezelModeIndex;
    int iModeAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSBezelTransientModeMask;
    int iSLSBezelTransientModeValue;
};
struct EFTransientMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iSLSModeIndex;
    EFMode displayMode;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSBezelTransientModeMask;
    int iSLSBezelTransientModeValue;
};
struct EFSLSOffset
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iBezelModeIndex;
    int iLeft;
    int iTop;
    int iWidth;
    int iHeight;
    int iBezelOffsetMask;
    int iBezelOffsetValue;
};
struct EFSLSGrid
{
    int iAdapterIndex;
    int iSLSGridIndex;
    int iSLSGridRow;
    int iSLSGridColumn;
    int iSLSGridMask;
    int iSLSGridValue;
};
struct EFSLSMap
{
    int iAdapterIndex;
    int iSLSMapIndex;
    EFSLSGrid kGrid;
    int iSurfaceMapIndex;
    int iOrientation;
    int iNumSLSTarget;
    int iFirstSLSTargetArrayIndex;
    int iNumNativeMode;
    int iFirstNativeModeArrayIndex;
    int iNumBezelMode;
    int iFirstBezelModeArrayIndex;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSMapMask;
    int iSLSMapValue;
};

typedef int (*EFMainControlCreate)(void*(__stdcall* pfnAlloc)(unsigned int), int iEnumConnectedAdapters);
typedef int (*EFMainControlDestroy)();
typedef int (*EFNumberOfAdaptersGet)(int* piNumAdapters);
typedef int (*EFAdapterInfoGet)(EFAdapterInfo* pkInfo, int iInputSize);
typedef int (*EFSLSMapIndexGet)(int iAdapterIndex, int iTargetCount, EFDisplayTarget* pkTargets, int* piSLSMapIndex);
typedef int (*EFSLSMapConfigGet)(int iAdapterIndex, int iSLSMapIndex, EFSLSMap* pkMap, int* piNumTarget,
                                 EFSLSTarget** ppkTarget, int* piNumNative, EFNativeMode** ppkNative, int* piNumBezel,
                                 EFBezelMode** ppkBezel, int* piNumTransient, EFTransientMode** ppkTransient,
                                 int* piNumOffset, EFSLSOffset** ppkOffset, int iOption);
typedef int (*EFModesGet)(int iAdapterIndex, int iDisplayIndex, int* piNumModes, EFMode** ppkModes);
typedef int (*EFDisplayMapConfigGet)(int iAdapterIndex, int* piNumMap, EFDisplayMap** ppkMap, int* piNumTarget,
                                     EFDisplayTarget** ppkTarget, int iOptions);

void __stdcall ClearAndFreePointer(void* pointer);
