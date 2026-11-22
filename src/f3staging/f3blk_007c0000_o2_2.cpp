#include <math.h>
#include <string.h>
#include <windows.h>
#pragma intrinsic(_ReadWriteBarrier)
#include <windows.h>
// src/f3staging/f3blk_007c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007dab20 (community match, verified in this file)
namespace f3m_007dab20 {

namespace destructor1342 {
struct Ref {virtual ~Ref(); virtual void DeleteThis(); long count; void DecRefCount() {if(InterlockedDecrement(&count)==0)DeleteThis();}};
struct Ptr {Ref* p; ~Ptr(){if(p)p->DecRefCount();}};
struct Base {virtual void Slot00(); ~Base() {}};
struct FUN_007dab20:Base {
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
Ptr member;
virtual void Slot00();
~FUN_007dab20();
};
// pdb: CombatProcedureMove::~CombatProcedureMove | CombatProcedureMove.obj | fnv360_0822_retail, call_seq, medium
FUN_007dab20::~FUN_007dab20() {}
}
}   // namespace f3m_007dab20

// @f3 0x007cc260 (community match, verified in this file)
namespace f3m_007cc260 {
// FUN_007cc260 -- reference member: broad-phase AABB query around the reference's position; marks script events
// on the first trigger phantom (layer 0x17 or 0x18) whose owner reference is found.




struct Point3X
{
    float x;
    float y;
    float z;
};

extern Point3X DAT_00f725bc;         // query half extent
extern const double DAT_00dbe7c0;    // game units to Havok units
extern unsigned long DAT_010f3170;   // thread memory TLS index
extern void* DAT_010716a4;

struct BroadPhaseX;
struct WorldOwnerX;
struct CellX;

struct StringX
{
    const char* data;
    unsigned short length;

    unsigned int GetLength() const
    {
        return length == 0xffff ? (unsigned int)strlen(data) : length;
    }
};

struct FormX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int flags60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
    int unka4;
    StringX name;

    bool GetFlag60(unsigned int bit) const
    {
        return (flags60 >> bit) & 1;
    }
};

struct ExtraListX
{
    WorldOwnerX* FUN_00410f00();
};

struct HkWorldX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50;
    BroadPhaseX* broadPhase;
};

struct WorldOwnerX
{
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094();
    virtual HkWorldX* GetWorld();
};

extern WorldOwnerX* DAT_01071564;

struct CellX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags24;
    ExtraListX extra28;

    WorldOwnerX* GetWorldOwner()
    {
        return (flags24 & 1) ? extra28.FUN_00410f00() : DAT_01071564;
    }
};

struct ThreadMemoryX
{
    void FUN_008f6d90(void* apData, int aiBytes, int aiClass);
};

struct HandlePairX
{
    char* a;
    char* b;
};

struct HitArrayX
{
    HandlePairX* data;
    int size;
    int capacityAndFlags;
    HandlePairX storage[128];

    HitArrayX()
    {
        data = storage;
        size = 0;
        capacityAndFlags = 0x80000080;
    }

    ~HitArrayX()
    {
        if ((capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = capacityAndFlags & 0x3fffffff;
            ThreadMemoryX* pMemory = (ThreadMemoryX*)TlsGetValue(DAT_010f3170);
            pMemory->FUN_008f6d90(data, capacity * sizeof(HandlePairX), 0x17);
        }
    }
};

__declspec(align(16)) struct Vector4X
{
    float x, y, z, w;
};

struct AabbX
{
    Vector4X min;
    Vector4X max;
};

struct BroadPhaseX
{
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void QueryAabb(const AabbX& aabb, HitArrayX& hits);
};

class FilterX
{
  public:
    unsigned int iFilter;

    unsigned int GetLayer() const
    {
        return iFilter & 0x7f;
    }
};

struct PhantomOwnerX
{
    FilterX FUN_00424270() const;
};

struct WorldObjectX
{
    int unk00, unk04, unk08;
    PhantomOwnerX* userData;
};

struct CollidableX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char ownerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    signed char type;
};

struct RefX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int extra40;
};

void* __cdecl FUN_004780d0(CollidableX* apCollidable);
RefX* __cdecl FUN_004e7b90(void* apObject);
void __cdecl Script_SetActionFlag(void* apSource, int* apExtra, unsigned int auiEvent);

struct RefBaseX
{
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0(); virtual void v0c4(); virtual void v0c8(); virtual void v0cc();
    virtual void v0d0(); virtual void v0d4(); virtual void v0d8(); virtual void v0dc();
    virtual void v0e0(); virtual void v0e4(); virtual void v0e8(); virtual void v0ec();
    virtual void v0f0(); virtual void v0f4(); virtual void v0f8(); virtual void v0fc();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13c();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14c();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15c();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16c();
    virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17c();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18c();
    virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19c();
    virtual void v1a0(); virtual void v1a4(); virtual void v1a8(); virtual void v1ac();
    virtual void v1b0(); virtual void v1b4(); virtual void v1b8(); virtual void v1bc();
    virtual void v1c0(); virtual void v1c4(); virtual void v1c8(); virtual void v1cc();
    virtual void v1d0(); virtual void v1d4(); virtual void v1d8(); virtual void v1dc();
    virtual void v1e0(); virtual void v1e4(); virtual void v1e8(); virtual void v1ec();
    virtual void v1f0();
    virtual const Point3X* GetPos();

    int unk04, unk08, unk0c, unk10, unk14, unk18;
    FormX* baseForm;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    CellX* parentCell;

    bool FUN_007cc260();
};

// pdb: Projectile::TestProjectileInTriggerZone | Projectile.obj | fnv360_0721_beta, udata, medium
bool RefBaseX::FUN_007cc260()
{
    bool bFound = false;
    FormX* pForm = baseForm;
    if (pForm->GetFlag60(3))
    {
        if (pForm->name.GetLength() != 0)
        {
            CellX* pCell = parentCell;
            WorldOwnerX* pOwner = pCell ? pCell->GetWorldOwner() : 0;
            if (!pOwner)
                return false;
            HkWorldX* pWorld = pOwner->GetWorld();
            BroadPhaseX* pBroadPhase = pWorld ? pWorld->broadPhase : 0;

            Point3X kLow;
            kLow.x = DAT_00f725bc.x;
            kLow.y = DAT_00f725bc.y;
            kLow.z = DAT_00f725bc.z;
            const Point3X* pPos = GetPos();
            float fLowX = pPos->x - kLow.x;
            float fLowY = pPos->y - kLow.y;
            float fLowZ = pPos->z - kLow.z;
            Point3X kHigh;
            kHigh.x = DAT_00f725bc.x;
            kHigh.y = DAT_00f725bc.y;
            kHigh.z = DAT_00f725bc.z;
            pPos = GetPos();
            float fHighX = pPos->x + kHigh.x;
            float fHighY = pPos->y + kHigh.y;
            float fHighZ = pPos->z + kHigh.z;

            AabbX kBox;
            kBox.min.x = fLowX * DAT_00dbe7c0;
            kBox.min.y = fLowY * DAT_00dbe7c0;
            kBox.min.z = fLowZ * DAT_00dbe7c0;
            kBox.max.x = fHighX * DAT_00dbe7c0;
            kBox.max.y = fHighY * DAT_00dbe7c0;
            kBox.max.z = fHighZ * DAT_00dbe7c0;

            HitArrayX kHits;
            pBroadPhase->QueryAabb(kBox, kHits);

            // The identical-arms increment is a guess at the source: it gives i one more use in the loop
            // latch when registers are assigned (i then wins ebx over this, as in the original) and the two
            // arms merge afterwards, so it emits only the plain add.
            for (int i = 0; !bFound && i < kHits.size; i = (i < 0) ? i + 1 : i + 1)
            {
                char* pHandle = kHits.data[i].b;
                CollidableX* pCollidable = (CollidableX*)(pHandle + pHandle[5]);
                RefX* pRef = FUN_004e7b90(FUN_004780d0(pCollidable));
                if (pCollidable->type == 2)
                {
                    WorldObjectX* pPhantom = (WorldObjectX*)((char*)pCollidable + pCollidable->ownerOffset);
                    if (pPhantom)
                    {
                        PhantomOwnerX* pObject = pPhantom->userData;
                        if (pObject && pRef)
                        {
                            if (pObject->FUN_00424270().GetLayer() == 0x17 ||
                                pObject->FUN_00424270().GetLayer() == 0x18)
                            {
                                bFound = true;
                                Script_SetActionFlag(this, &pRef->extra40, 0x80);
                                Script_SetActionFlag(DAT_010716a4, &pRef->extra40, 0x100);
                            }
                        }
                    }
                }
            }
        }
    }

    return bFound;
}
}   // namespace f3m_007cc260

// @f3 0x007c8280 (community match, verified in this file)
namespace f3m_007c8280 {
struct Point8280 { float x,y,z; };
struct Node8280 {
    virtual void slot0();
    virtual void destroy();
    volatile long refs;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NodePtr8280 {
    Node8280* p;
    NodePtr8280() : p(0) {}
    ~NodePtr8280();
    void clear() {
        Node8280* old=p;
        if (old) {
            if (InterlockedDecrement(&old->refs)==0) old->destroy();
            p=0;
        }
    }
};
struct Cause8280 { void FUN_005a22f0(); };
struct CausePtr8280 {
    Cause8280* p;
    CausePtr8280() : p(0) {}
    ~CausePtr8280();
    void clear() { if(p) { p->FUN_005a22f0(); p=0; } }
};
struct List8280 {
    void* first; void* next;
    List8280() : first(0),next(0) {}
    ~List8280();
};
struct Sound8280 {
    int unk00; bool unk04; int unk08;
    Sound8280() : unk00(-1),unk04(false),unk08(0) {}
};
struct Transform8280 {
    float unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    Point8280 unk24; float unk30;
    void FUN_00851550();
};
struct ItemForm8280 { int unk00; unsigned char unk04; };
struct Entry8280 {
    int unk00,unk04; ItemForm8280* unk08;
    float FUN_0047cf30(int);
    float FUN_0047d300(void*,float,bool);
};
struct Process8280 {
    virtual void s000(); virtual void s004(); virtual void s008(); virtual void s00c();
    virtual void s010(); virtual void s014(); virtual void s018(); virtual void s01c();
    virtual void s020(); virtual void s024(); virtual void s028(); virtual void s02c();
    virtual void s030(); virtual void s034(); virtual void s038(); virtual void s03c();
    virtual void s040(); virtual void s044(); virtual void s048(); virtual void s04c();
    virtual void s050(); virtual void s054(); virtual void s058(); virtual void s05c();
    virtual void s060(); virtual void s064(); virtual void s068(); virtual void s06c();
    virtual void s070(); virtual void s074(); virtual void s078(); virtual void s07c();
    virtual void s080(); virtual void s084(); virtual void s088(); virtual void s08c();
    virtual void s090(); virtual void s094(); virtual void s098(); virtual void s09c();
    virtual void s0a0(); virtual void s0a4(); virtual void s0a8(); virtual void s0ac();
    virtual void s0b0(); virtual void s0b4(); virtual void s0b8(); virtual void s0bc();
    virtual void s0c0(); virtual void s0c4(); virtual void s0c8(); virtual void s0cc();
    virtual void s0d0(); virtual void s0d4(); virtual void s0d8(); virtual void s0dc();
    virtual void s0e0(); virtual void s0e4(); virtual void s0e8(); virtual void s0ec();
    virtual void s0f0(); virtual void s0f4(); virtual void s0f8(); virtual void s0fc();
    virtual void s100(); virtual void s104(); virtual void s108(); virtual void s10c();
    virtual void s110(); virtual void s114(); virtual void s118(); virtual void s11c();
    virtual void s120(); virtual void s124(); virtual void s128(); virtual void s12c();
    virtual void s130(); virtual void s134(); virtual void s138(); virtual void s13c();
    virtual void s140(); virtual void s144(); virtual Entry8280* get();
};
struct Source8280 {
    virtual void s000(); virtual void s004(); virtual void s008(); virtual void s00c();
    virtual void s010(); virtual void s014(); virtual void s018(); virtual void s01c();
    virtual void s020(); virtual void s024(); virtual void s028(); virtual void s02c();
    virtual void s030(); virtual void s034(); virtual void s038(); virtual void s03c();
    virtual void s040(); virtual void s044(); virtual void s048(); virtual void s04c();
    virtual void s050(); virtual void s054(); virtual void s058(); virtual void s05c();
    virtual void s060(); virtual void s064(); virtual void s068(); virtual void s06c();
    virtual void s070(); virtual void s074(); virtual void s078(); virtual void s07c();
    virtual void s080(); virtual void s084(); virtual void s088(); virtual void s08c();
    virtual void s090(); virtual void s094(); virtual void s098(); virtual void s09c();
    virtual void s0a0(); virtual void s0a4(); virtual void s0a8(); virtual void s0ac();
    virtual void s0b0(); virtual void s0b4(); virtual void s0b8(); virtual void s0bc();
    virtual void s0c0(); virtual void s0c4(); virtual void s0c8(); virtual void s0cc();
    virtual void s0d0(); virtual void s0d4(); virtual void s0d8(); virtual void s0dc();
    virtual void s0e0(); virtual void s0e4(); virtual void s0e8(); virtual void s0ec();
    virtual void s0f0(); virtual void s0f4(); virtual void s0f8(); virtual void s0fc();
    virtual bool test();
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    Process8280* unk60;
    int unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c;
    int unk90,unk94,unk98,unk9c;
    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;
    int unke0,unke4,unke8,unkec,unkf0,unkf4;
    bool unkf8;
    Entry8280* FUN_007818b0();
};
struct Clip8280 {
    virtual void s0(); virtual void s4(); virtual void s8(); virtual void sc();
    virtual unsigned short get();
};
struct Weapon8280 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98;
    Clip8280 unk9c; int unka0,unka4; ItemForm8280* unka8;
    int unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc;
    int unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec;
    int unkf0,unkf4,unkf8,unkfc,unk100,unk104,unk108,unk10c;
    int unk110,unk114,unk118; unsigned short unk11c; unsigned char unk11e;
};
struct Primary8280 {
    virtual ~Primary8280();
    int unk04,unk08,unk0c,unk10,unk14;
};
struct Secondary8280 { virtual void slot(); };
struct Base8280 : Primary8280, Secondary8280 {
    int unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;
    int unk70,unk74,unk78,unk7c;
    Base8280();
    virtual ~Base8280();
    void FUN_004eeae0(const Point8280&);
    void FUN_004e8750(float);
    void FUN_004e8710(float);
    void FUN_004e8730(float);
    void TESObjectREFR_SetObjectReference(void*);
    void TESForm_SetInitialized(int);
};
struct Setting8280 { float* FUN_00401eb0(); };
extern Setting8280 DAT_00f607c4, DAT_00f607b8;
namespace f3m_7c8280_globals { extern Source8280* DAT_0107a104; extern Point8280 DAT_0108ec68; }
extern float DAT_00db9568;

unsigned int FUN_00456720(ItemForm8280*);
float FUN_0045c010(ItemForm8280*);
float FUN_00401e20(float,float);
struct FUN_007c8280 : Base8280 {
    List8280 unk80;
    bool unk88;
    Transform8280 unk8c;
    unsigned int unkc0;
    float unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0;
    int unke4,unke8;
    float unkec;
    Weapon8280* unkf0;
    Source8280* unkf4;
    int unkf8;
    Point8280 unkfc;
    float unk108;
    NodePtr8280 unk10c;
    int unk110;
    NodePtr8280 unk114;
    CausePtr8280 unk118;
    float unk11c;
    Sound8280 unk120,unk12c;
    int unk138;
    Entry8280* unk13c;
    FUN_007c8280(void*,Source8280*,Weapon8280*,Point8280,float,float);
    virtual ~FUN_007c8280();
    virtual void slot();
};
// pdb: Projectile::Projectile | Projectile.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apProjectileBase, apShooter, apFromWeapon, aOrigin, afZAngle, afXAngle
FUN_007c8280::FUN_007c8280(void* base,Source8280* source,Weapon8280* weapon,Point8280 point,float ax,float az)
{
    unk60=0;
    FUN_004eeae0(point);
    FUN_004e8750(ax);
    FUN_004e8710(az);
    FUN_004e8730(0.0f);
    unkf4=source;
    unkf8=0;
    unkf0=0;
    unkc4=1.0f;
    unkc8=1.0f;
    unkd4=0.0f;
    unkcc=0.0f;
    unkd8=1.0f;
    unkdc=DAT_00db9568;
    unke0=0.0f;
    unk114.clear();
    unk118.clear();
    unk88=false;
    unk138=0;
    unk13c=0;
    unkec=1.0f;
    TESObjectREFR_SetObjectReference(base);
    if(weapon) {
        Entry8280* entry=0;
        unkf0=weapon;
        unkd4=weapon->unk9c.get();
        if(unkf4 && unkf4->test()) {
            Source8280* actor=unkf4;
            Process8280* process=actor->unk60;
            if(process) {
                entry=process->get();
                if(entry) {
                    ItemForm8280* form=entry->unk08;
                    unkec=entry->FUN_0047cf30(0)/FUN_00456720(form);
                    unkd4=entry->FUN_0047d300(&actor->unk9c,1.0f,true);
                }
            }
        }
        unkd4=unkd4/unkf0->unk11e;
    }
    if(unkf4==f3m_7c8280_globals::DAT_0107a104 && unkf0 && unkf0->unka8 && unkf0->unka8->unk04==0x55) {
        Entry8280* ammo=f3m_7c8280_globals::DAT_0107a104->FUN_007818b0();
        if(ammo) {
            unk13c=ammo;
            ItemForm8280* form=ammo->unk08;
            if(form) {
                float spread=*DAT_00f607b8.FUN_00401eb0()*FUN_00401e20(*DAT_00f607c4.FUN_00401eb0(),FUN_0045c010(form));
                unkd4+=FUN_00401e20(0.0f,spread);
            }
        }
    }
    unkc0=0;
    unkd0=0.0f;
    unk108=0.0f;
    unkfc=f3m_7c8280_globals::DAT_0108ec68;
    unk10c.clear();
    unk11c=0.0f;
    unk8c.FUN_00851550();
    if(unkf4 && unkf4->test()) {
        if(unkf4->unkf8) unkc0|=0x80000;
    }
    TESForm_SetInitialized(0);
}


}   // namespace f3m_007c8280
