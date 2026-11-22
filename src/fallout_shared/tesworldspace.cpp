// fallout_shared/tesworldspace.cpp: TESWorldSpace, TESObjectCELL, TESRegion, InterfaceManager and more (19 functions)
#include "f3_common.h"
#include "tesworldspace_packet.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_FloatToInt for 0x00501250); no F3 match in this file yet
// @fnv 0x00425fd0
// Sets the world space's map name from the given string and returns true.
// @fnv 0x00583330
// Returns the terrain manager of the parent world space if one exists, otherwise this world space's own terrain.
// @fnv 0x00586170
// Returns parent if it exists and GetParentUseFlag(flag) is set, otherwise returns null.
// @fnv 0x00586390
// Looks up key in cellMap and returns the stored reference cast to TESObjectCELL, or null if not found.
// @fnv 0x00587630
// If ref is non-null and not temporary, creates a persistent cell and adds ref to it.
// @fnv 0x00587ff0
// @fnv 0x004f1260
// @fnv 0x00473ff0
// Clears night and looping sounds, effect shader, calls three helpers, resets the full name and zeroes 16 bytes at offset 0x80.
// @fnv 0x00586480
// Validates x and y are within -32768..32767, builds a key from them, and looks up the cell in cellMap, returning it or null.
// @fnv 0x005875a0
// @fnv 0x00586150
// @fnv 0x00584bc0
// @fnv 0x00586110
// @fnv 0x00586130
// @fnv 0x005861b0
// @fnv 0x005862e0
// Sets parent to world and clears field4E when world is null.
// @fnv 0x005863d0

struct FUN_005861d0_shell : public TESWorldSpace
{
    void SetFlagBit0(bool);
};

struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

int __cdecl TruncateFloatToInt(float);

// @f3 0x00501250 (community match, verified in this file)
int __cdecl FUN_00c01895(double value);
int __cdecl FUN_00c018aa(double value);

// pdb: TESWorldSpace::GetKeyForWorldCoord | TESWorldSpace.obj | fnv360_0822_retail, uconst, low
// pdb params: aCoord
int __cdecl FUN_00587440(const NiPoint3* aCoord)
{
    if (!FUN_00c01895(aCoord->x) || !FUN_00c01895(aCoord->y) || !FUN_00c01895(aCoord->z) ||
        FUN_00c018aa(aCoord->x) || FUN_00c018aa(aCoord->y) || FUN_00c018aa(aCoord->z))
    {
        return 0x7fff7fff;
    }

    int iX = fnv_FloatToInt(aCoord->x) >> 12;
    int iY = fnv_FloatToInt(aCoord->y) >> 12;
    return ((int)(short)iX << 16) | (unsigned short)(short)iY;
}


void* __cdecl operator new(unsigned int);

class NiPoint2
{
  public:
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float, float);
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
    void SetAt(unsigned int, unsigned int);
};

void __fastcall _ref_006815c0(void* pThis);

void __fastcall _ref_00726070(void*);

struct Flt
{
    operator unsigned int() const;
};

struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
    bool IsCellPersistent();
};
struct S54de10
{
    void FUN_0054de10(TESWorldSpace*);
};
unsigned int __fastcall _ref_0084e3a0(void*);

template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList<T>* next;
    ~BSSimpleList();
    void operator delete(void*);
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
extern ATM g_011ca60c;
struct MapH
{
    bool RemoveAt(unsigned int);
};
bool __cdecl FUN_00587c80(void*);

namespace stub {
struct TESObjectCELL
{
    TESObjectCELL();
    char pad[0xe0];
};
}

struct FileH
{
    bool __thiscall IsMasterFile(void);
    bool __thiscall SetOffset(unsigned int);
    unsigned int __thiscall GetFormID(void);
};

struct FormIDData
{
    unsigned int pad0[5];
    unsigned int formID;
};

extern unsigned int __fastcall _ref_0084e3a0(void*);

struct FUN_005858b0_shell
{
    FormIDData* __thiscall FUN_00588a90(FileH* apFile);
    bool IsFileFormIDMatching(FileH* apFile);
};

namespace fnv_00587550 {
extern "C"
{
    int __cdecl TruncateFloatToInt(float);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

}  // namespace fnv_00587550

extern "C"
{
    struct TESWaterForm;
}

extern TESWaterForm* DAT_011ca53c;

template <class T> class BSSimpleList;

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<2>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

void __cdecl _Deallocate(void*);

void _Deallocate(void*);

namespace fnv_00584530 {
struct FileH;

struct FormIDData
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
};

struct FUN_005858b0_shell
{
    FormIDData* FUN_00588a90(FileH*);
    int FUN_00584530(FileH* file, int x, int y);
};

}  // namespace fnv_00584530

class TESWaterForm;
extern TESWaterForm* DAT_011ca53c;

namespace fnv_00587760 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct S54de10
{
    void FUN_0054de10(TESWorldSpace*);
};

}  // namespace fnv_00587760

namespace fnv_00587870 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
template <class T> struct BSSimpleList
{
};
}  // namespace fnv_00587870

namespace fnv_00588a90 {
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct FormIDData
{
    int dummy;
};
}  // namespace fnv_00588a90

struct BGSCameraPath;
struct NiFormArray;
struct CameraPathManager
{
    void InitializeCameraPaths();
    static BGSCameraPath* GetTextureResourcePath();
    void AddCameraPath(BGSCameraPath*);
    void UpdateCameraPaths();
    void ClearCameraPaths();
    NiFormArray* GetRootPathArray();
    BGSCameraPath* SetCameraPathEnabled(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_kCameraPathArray[24];
    char m_kCameraPathList[16];
};
typedef char _sizecheck_BGSCameraPathManager[sizeof(CameraPathManager) == 40 ? 1 : -1];

namespace fnv_00582c20 {
namespace stand {
struct TESFullName
{
    TESFullName();
    ~TESFullName();
    virtual void V();
    int x[2];
};
}
struct TESTexture
{
    TESTexture();
    ~TESTexture();
    virtual void V();
    int x[2];
};
struct GO
{
    GO(int);
    ~GO();
    int x;
};
struct FUN_006815c0
{
    float x, y;
    FUN_006815c0();
};
struct FUN_00589000
{
    FUN_00589000(unsigned int);
    int x[4];
};

}  // namespace fnv_00582c20

namespace fnv_005857b0 {
struct FileH
{
    int m_uiData;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};
struct FUN_005858b0_shell
{
    FileH* FUN_00588a90(int);
};
}  // namespace fnv_005857b0

struct MapX
{
    void* GetFirstPos();
};
struct MyMap
{
    void RemoveAll();
    virtual ~MyMap();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};

namespace fnv_00588c80 {
struct MapX
{
    void* GetFirstPos();
};
struct MyMap
{
    void RemoveAll();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
void __cdecl _Deallocate(void*);
struct FUN_00588c80
{
    void PerformNoArgumentOperation();
};
}  // namespace fnv_00588c80

namespace fnv_00583070 {

struct FUN_005861d0_shell
{
    void SetFlagBit0(bool);
};

struct GO
{
    void operator=(void*);
};

}  // namespace fnv_00583070

struct GO
{
    operator unsigned int() const;
    void operator=(void*);
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

namespace fnv_00588150 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};

struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

extern ATM g_011ca60c;

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct BSSimpleList
{
    bool _ref_008256d0();
    TESObjectREFR** _ref_006815c0();
    BSSimpleList* _ref_00726070();
};

}  // namespace fnv_00588150

namespace fnv_00588560 {
class NiTMap
{
  public:
    void GetNext(void*& position, unsigned int& key, void*& value);
};

class MapX : public NiTMap
{
  public:
    void* GetFirstPos();
};

}  // namespace fnv_00588560

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
    Pt3& operator*=(float);
    Pt3 operator-(const Pt3&) const;
    Pt3 operator+(const Pt3&) const;
};

struct FUN_00483630_holder
{
    virtual ~FUN_00483630_holder();
    unsigned int flags, formID, fileData, changedFlags, recordData;
};
struct FUN_00591300
{
    virtual ~FUN_00591300();
    unsigned int nameData, nameLength;
};
struct TESTexture
{
    virtual ~TESTexture();
    unsigned int textureData, textureLength;
};
struct FUN_0048e2e0
{
    unsigned int type, data, length;
    ~FUN_0048e2e0();
};
struct FUN_0057ce90_shell
{
    unsigned int head;
    ~FUN_0057ce90_shell();
};
struct FUN_00589130
{
    unsigned int table, count, allocator, entries;
    ~FUN_00589130();
};
struct FUN_00589230
{
    unsigned int entries, size, capacity, allocator;
    ~FUN_00589230();
};
struct BSStringTChar
{
    unsigned int data, length;
    ~BSStringTChar();
};
struct GO633
{
    void* node;
    ~GO633();
};
struct WorldTerrain
{
    void FUN_006fca70();
    ~WorldTerrain();
};
struct WorldCellMap
{
    virtual ~WorldCellMap();
};
struct WorldLandMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~WorldLandMap();
};
struct FUN_00582e30 : FUN_00483630_holder, FUN_00591300, TESTexture
{
    WorldCellMap* cellMap;
    WorldLandMap* landMap;
    FUN_0057ce90_shell cellList;
    WorldTerrain* terrain;
    unsigned int water, parentUseFlags, climate, worldFlags;
    FUN_00589130 offsetMap;
    BSSimpleList<int> regionList;
    unsigned int worldspaceID;
    GO633 node;
    unsigned int parent, music, encounterZone, location, mapScale, mapX, mapY;
    unsigned int minX, minY, maxX, maxY, landHeight, waterHeight, lodWater;
    unsigned int lodWaterType, impactData;
    FUN_00589230 offsetArray;
    BSStringTChar mapName;
    float usableX, usableY;
    unsigned int mapDimensions;
    FUN_0048e2e0 m_kCloudLayerTextures;
    FUN_0048e2e0 waterTexture;
    virtual ~FUN_00582e30();
    void ClearAllLists();
    void DestroyMapEntries();
    void FUN_00583180();
    void FUN_005877e0();
    void FUN_00588c80();
};
extern FUN_00582e30* DAT_011c3f44;
// Clears the global worldspace pointer if it is this object, then releases terrain, cell and land maps and other owned resources.
// @fnv 0x00582e30
FUN_00582e30::~FUN_00582e30()
{
    if (DAT_011c3f44 == this)
        DAT_011c3f44 = 0;
    ClearAllLists();
    DestroyMapEntries();
    if (terrain)
    {
        terrain->FUN_006fca70();
        delete terrain;
        terrain = 0;
    }
    FUN_00583180();
    FUN_005877e0();
    delete cellMap;
    cellMap = 0;
    delete landMap;
    landMap = 0;
    FUN_00588c80();
}

void BSEndian(float*, EndianSizeTag<4>);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);

struct FUN_0058efd0
{
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
    FUN_0058efd0();
    ~FUN_0058efd0();
    void CopyFrom(FUN_0058efd0*);
};

struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x, y, z;
};
typedef GlobalObject_006815c0 Point;

struct QueryPoint2
{
    float x, y;
    QueryPoint2(float x, float y);
};
struct WorldQuery;
struct AreaQuery
{
    bool FUN_004f8360(const QueryPoint2* point);
};
struct CellQuery;
template <class T> struct QueryLink
{
    T* item;
    QueryLink* next;
    T** FUN_006815c0();
    QueryLink* FUN_00726070();
};
struct CellQuery
{
    bool FUN_00549580();
    bool FUN_00440d80();
    WorldQuery* FUN_007af430();
    QueryLink<AreaQuery>* FUN_00441110();
};
struct WorldQuery
{
    bool IsFlag8Set();
    bool ContainsPoint(const NiPoint3* position);
};

namespace fnv_00583560 {
void* operator new(unsigned int);
void operator delete(void*);
class File583
{
  public:
    int FUN_00472660();
    bool FUN_00471c20();
    unsigned int GetOffset();
    int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool ReadChunkInt(void*);
    bool ReadChunkData(unsigned short*);
    bool FUN_00401680();
    bool GetNextChunk();
};
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
class FUN_0058efd0
{
  public:
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
    FUN_0058efd0();
    void FUN_0058f180(File583*);
};
class FUN_00589000
{
  public:
    virtual ~FUN_00589000();
    unsigned int a, b, c;
    FUN_00589000(unsigned int);
    unsigned int FUN_0084e3a0();
};

}  // namespace fnv_00583560

namespace fnv_005878d0 {
class DummyPointerMap
{
  public:
    int a;
    int b;
    int c;
    int d;
    DummyPointerMap(int);
    bool GetAt(unsigned int, int&) const;
    void SetAt(unsigned int, unsigned int);
};
int TruncateFloatToInt(float);

}  // namespace fnv_005878d0

struct String65
{
    char* text;
    unsigned short length, capacity;
    String65();
    ~String65();
    bool Set(const char*, unsigned = 0);
    operator const char*() const;
    unsigned Length();
    int StrCmp(const char*, bool = true) const;
};

namespace WsH_587D10 {
}
bool __cdecl FUN_00587c80(void*);
