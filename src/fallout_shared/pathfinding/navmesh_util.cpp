// fallout_shared/pathfinding/navmesh_util.cpp: NavMesh, std, CircularArc, ASC and more (1 function)
#include "f3_common.h"
#include "navmesh_util_decls.h"

struct ASC
{
    float s, c;
    void _ref_006815c0();
    ASC& operator=(const ASC&);
    ASC* Multiply(ASC* out, const ASC* o);
};

extern int DAT_0106b1b8;

extern int DAT_0106b1b8;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

struct EH
{
    char b[12];
    EH& operator=(const EH&);
};

extern unsigned int _data_011c16bc;
struct B006815c0
{
    char p[8];
    B006815c0();
};

struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    virtual void SetValue(IT*, TwoIntRecord, void*);
    virtual void v4();
    virtual IT* NewItem();
    unsigned int cnt;
    IT** table;
    unsigned int count;
};
struct VW
{
    void* p;
};

namespace fnv_0069b4d0 {
struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    unsigned int cnt;
    IT** table;
};
struct VW
{
    void** p;
};
}  // namespace fnv_0069b4d0

namespace p07 {
}

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float afX, float afY, float afZ);
    NiPoint3 operator+(const NiPoint3& arPt) const;
};

struct ObstacleDataEx : public ObstacleData
{
    NiPoint3Ex WorldMin;
    NiPoint3Ex WorldMax;
};

struct ObstacleDataPtr
{
    ObstacleDataEx* object;
    ObstacleDataEx* operator->() const;
};

bool __cdecl AreWideCharsEqual(const unsigned short& a, const unsigned short& b);

struct NavMeshTriList : public BSSimpleArray<unsigned short>
{
    unsigned int GetSize() const;
    const unsigned short& FUN_0069dec0(unsigned int auiIndex) const;
    int FindMatchingIndex(const unsigned short& arItem, unsigned int auiStart,
                          bool(__cdecl* apCompare)(const unsigned short&, const unsigned short&));
};

bool __cdecl FUN_00696540(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
extern const float DAT_01015f5c;

struct NavMeshVertexEdgeData;

struct Flt
{
    operator unsigned int() const;
};

struct Arr
{
    Flt* GetAt(int);
};

struct FUN_00699630_shell
{
    int FindEntryIndex(int);
    Arr arr;
    int FUN_00699630(int param1, unsigned int* out);
};

namespace std {
float __cdecl abs(float);
}

struct FindTriangleForLocationFilter;

namespace fnv_00698fc0 {
struct FUN_00699630_shell
{
    int FUN_00699630(int, unsigned int*);
};
}  // namespace fnv_00698fc0

struct S0069afb0
{
    int FUN_0069afb0(unsigned short, int);
};
struct S006997b0
{
    char _pad[0xE0];
    S0069afb0* p;
    int FUN_006997b0(unsigned short, int);
};
// @f3 0x005fd4e0 (community match, verified in this file)
extern "C" int DAT_00dc4dc0;

struct S_5fcac0
{
    void PathingLocation_SetupData(unsigned short, int, int);
};

// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_debug, objrun, medium
// pdb params: aLocation, apCell
int S006997b0::FUN_006997b0(unsigned short a, int b)
{
    *(void**)this = (void*)&DAT_00dc4dc0;
    ((S_5fcac0*)this)->PathingLocation_SetupData(a, b, 0);
    return (int)this;
}


struct ArrSI
{
    unsigned int GetFlags();
};

namespace fnv_0069a940 {
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);

struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
};

struct GlobalObject_00869f00
{
    void Clear(bool);
    BSSimpleArray<unsigned short> m_kAdditionalIndexList;
};

}  // namespace fnv_0069a940

class SoundPlaybackHandle;
template <> class NiTPointerMap<unsigned int, SoundPlaybackHandle*>
{
  public:
    bool IsEmpty();
};
struct FUN_0069b0a0_shell
{
    void LookupValue(unsigned short, unsigned int);
};

namespace fnv_006b39a0 {
struct EH
{
    int a;
    int b;
    int c;
    EH& operator=(EH const&);
};
}  // namespace fnv_006b39a0

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct FindTriangleForLocationFilter;
struct NavMeshPtr;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct PathingLocation
{
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadGameBuffer*);
    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    struct blob12 GetLocation();
    TESObjectCELL* GetContainingCell();
    TESWorldSpace* GetParentWorldspace();
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    unsigned short GetTriangle();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    bool GetAllMeshesReachable();
    void* __vecDelDtor(unsigned int);
    NiPoint3 Location;
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    char _pad_27[1];
};
typedef char _sizecheck_PathingLocation[sizeof(PathingLocation) == 40 ? 1 : -1];

namespace fnv_00697810 {
struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct FUN_00697810_t;
struct NavCallback_00697810
{
    virtual bool Test(const NiPoint3&, NavMesh*, unsigned short, B006815c0&);
};
struct FUN_00697810_t : public NavMesh
{
    bool TestPointOnTriangle(unsigned short ausTri, const NiPoint3& arPoint, float& arZ,
                             NavCallback_00697810* apCallback);
};
}  // namespace fnv_00697810

namespace NavCircum {
struct NiPoint3
{
    float x, y, z;
    void Set(float, float, float);
};
}

namespace fnv_0069a830 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int);
};
struct FUN_0069b0a0_shell
{
    bool LookupValue(unsigned short, unsigned int);
};
namespace S {
struct NiTPointerMap
{
    bool IsEmpty();
};
}
struct GlobalObject_00869f00
{
    void Clear(bool);
};

}  // namespace fnv_0069a830

struct Helper62d0
{
    void* operator=(const void*);
};

namespace fnv_006be6f0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int i);
};
struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
    void FUN_0069add0(int, bool);
};
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);
}  // namespace fnv_006be6f0

namespace fnv_00697590 {
class ArrSI
{
  public:
    unsigned int GetFlags(void);
};

}  // namespace fnv_00697590

namespace fnv_006995c0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct GO
{
    operator unsigned int() const;
};
struct NiPointerStandIn
{
    bool operator==(void*) const;
};

}  // namespace fnv_006995c0

namespace fnv_006bbb80 {
extern int _data_011c16bc;

struct GO
{
    int value;

    GO(int);
    ~GO();
};

}  // namespace fnv_006bbb80

class Pt3
{
  public:
    float x, y, z;
    Pt3 operator+(const Pt3&) const;
    Pt3 operator*(float) const;
    Pt3 operator-(const Pt3&) const;
    float GetSquaredXYLength() const;
};

// NavMesh: get the extra info for a triangle edge, creating and linking a fresh record when missing,
// then reset its link fields.

struct FUN_006986d0_cls;

void* __cdecl FUN_00401000(unsigned int size);

struct b9_big
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58;
    static void* operator new(unsigned int size)
    {
        return FUN_00401000(size);
    }
    static void operator delete(void*, unsigned int);
    b9_big();
    void InitializeFromMeshSource(FUN_006986d0_cls* o);
    void SetField54(FUN_006986d0_cls* o);
};

struct FUN_006986d0_cls
{
    void* FUN_0084e3a0();
    int FUN_0068efb0();
    void FUN_006d3100(b9_big* p);
    bool FUN_006986d0();
};

struct P507Array
{
    void* table;
    void* data;
    unsigned int size, capacity;
    unsigned int FUN_0044ddc0();
    void** FUN_00877a30(unsigned int);
    void FUN_006bf8f0(unsigned int, bool);
};

struct P507Edge
{
    int unk00;
    unsigned int owner;
};
struct P507Mesh
{
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
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void SetChanged(bool);
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
    P507Array edges;
    P507Edge* GetEdge(unsigned short);
    void UpdateTriangleExtraInfo(unsigned short);
};
struct NavMeshPtr
{
    NavMesh* object;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NiPointer<NavMesh>&);
    void* FUN_00458b50();
    P507Mesh* FUN_00559450();
};

extern const float DAT_01016970;
extern const float DAT_01015f5c;

extern const float DAT_01016970;

namespace fnv_00696a50 {
extern float DAT_01016970;
}  // namespace fnv_00696a50

namespace fnv_00696cf0 {
extern float DAT_01016970;

}  // namespace fnv_00696cf0

struct UndoOwner;
struct SavedMesh
{
    void* object;
    SavedMesh();
    ~SavedMesh();
    SavedMesh& operator=(const SavedMesh&);
};
struct UndoEntry
{
    int unk00, unk04;
    int type;
    SavedMesh mesh;
};
struct UndoPtr
{
    UndoEntry* Get();
};
struct UndoArray
{
    UndoPtr& At(unsigned int);
    unsigned int Size();
};
struct UndoOwner
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
    UndoArray entries;
    void Erase(int);
    unsigned int Find(UndoEntry*);
    bool UndoToPosition(unsigned int position, void* output);
};

namespace fnv_0069aa20 {
class EdgePoint
{
  public:
    float x, y, z;
    EdgePoint();
    EdgePoint operator-(const EdgePoint&) const;
    float FUN_004a7290() const;
};
struct LinkedMesh;
struct NavMeshPtr
{
    LinkedMesh* mesh;
    NavMeshPtr();
    ~NavMeshPtr();
    LinkedMesh* FUN_00559450();
};
struct MeshInfo
{
    bool FUN_0069ad00(NavMeshPtr&);
};
struct LinkInfo
{
    int type;
    MeshInfo* mesh;
    unsigned short triangle;
};
struct LinkedTriangle : NavMeshTriangle
{
    bool FUN_00690e10();
};
struct LinkedMesh
{
    unsigned int FUN_00558200();
    LinkedTriangle* FUN_005582f0(unsigned short);
    LinkInfo* GetEdge(unsigned short);
    void FUN_0068f0c0(unsigned short, int, EdgePoint&, EdgePoint&);
    LinkInfo* GetOrCreateEdgeInfo(unsigned short, int);
    MeshInfo* FUN_0068efb0();
    bool LinkMatchingEdges();
};
}  // namespace fnv_0069aa20

struct NavMeshTriList;
float FUN_00406ce0(float afValue);

struct NavObstacleObject
{
    void FUN_00401970();
};
struct NavObstaclePtr
{
    NavObstacleObject* object;
    NavObstaclePtr(int);
    NavObstaclePtr(const NavObstaclePtr&);
    ~NavObstaclePtr();
    void FUN_006e5cc0(const NavObstaclePtr&);
    NavObstacleObject* FUN_00559450();
};
struct NavMap
{
    unsigned int unk00, unk04, unk08, unk0C;
    bool FUN_0069afb0(unsigned short, NavObstaclePtr&);
    void FUN_006946a0(unsigned short, NavObstaclePtr);
    void FUN_0049c250(unsigned short);
};
struct NavIndexArray
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int FUN_0044ddc0();
    unsigned short& GetBufferEntry(unsigned int);
    bool FUN_0076b610();
};
struct NavChange;
struct NavChange
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    virtual ~NavChange();
    unsigned int unk04, state;
    NavObstaclePtr obstacle;
    unsigned int oldVertices, newVertices, oldTriangles, newTriangles;
    NavIndexArray affected;
    float centerX, centerY, centerZ;
    unsigned int unk3C;
    NavMap obstacleMap;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    NavChange();
};

struct FindTriangleForLocationFilter;

extern const float DAT_01016970;
extern const float DAT_01015f5c;
float __cdecl FUN_00406ce0(float);
bool __cdecl FUN_00696540(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);
