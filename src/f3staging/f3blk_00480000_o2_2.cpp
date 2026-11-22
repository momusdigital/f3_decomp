#include <math.h>
#include <windows.h>
#include <string.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
#include <string.h>
#include <windows.h>
// src/f3staging/f3blk_00480000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x0049add0 (community match, verified in this file)
namespace f3m_0049add0 {
namespace S0049add0_ns {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

struct S0049add0_Point {
    float x, y, z;
    S0049add0_Point() {}
    S0049add0_Point(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    void Unitize();
};
extern S0049add0_Point DAT_0108ec68;
extern char DAT_00f4cf80;
extern char DAT_0106fdcc;
extern float DAT_00db75c8;

struct S0049add0_Matrix {
    float entry[3][3];
    S0049add0_Point operator*(const S0049add0_Point& p) const;
};
struct S0049add0_Plane {
    S0049add0_Point normal;
    float constant;
    S0049add0_Plane(const S0049add0_Point& n, const S0049add0_Point& p);
};
bool FUN_00464d70(const S0049add0_Point* point, const S0049add0_Plane* plane, float epsilon);

struct S0049add0_Entry {
    S0049add0_Entry* next;
    S0049add0_Entry* prev;
    void* item;
};
struct S0049add0_List {
    S0049add0_Entry* head;
    S0049add0_Entry* tail;
    unsigned int count;
    S0049add0_Entry* GetHeadPos() const { return head; }
    void FUN_00496910(S0049add0_Entry*& pos);
};
struct S0049add0_Ref {
    virtual void vfn00();
    virtual void vfn04();
    volatile long refCount;
};
struct S0049add0_Ptr {
    S0049add0_Ref* p;
    __forceinline void Clear() {
        S0049add0_Ref* r = p;
        if (r) {
            if (InterlockedDecrement(&r->refCount) == 0)
                r->vfn04();
            p = 0;
        }
    }
};
struct S0049add0_State {
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
    S0049add0_Ptr unk138;
    S0049add0_Ptr unk13C;
    S0049add0_Ptr unk140;
    S0049add0_Ptr unk144;
};
struct S0049add0_Form {
    S0049add0_State* FUN_00826590(int kind);
};
struct S0049add0_Box {
    int unk00;
    S0049add0_Point unk04;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    S0049add0_List unk24;
    void FUN_0049a1c0();
};
struct S0049add0_Heap {
    void FUN_0086ba60(void* p);
};
extern S0049add0_Heap DAT_01090a78;

struct S0049add0_Owner {
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
    S0049add0_List unk3C;
    S0049add0_Form* FUN_004941a0(void* object);
    void FUN_00495b90(int a, int b);
    void FUN_00493d10();
    bool FUN_0049add0(void* object, const S0049add0_Point* position, const S0049add0_Matrix* rotation);
};

// pdb: TESWaterSystem::RemovePlaceableWater | TESWater.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apWaterRef, arPosition, arRotation
bool S0049add0_Owner::FUN_0049add0(void* object, const S0049add0_Point* position, const S0049add0_Matrix* rotation) {
    if (DAT_00f4cf80 && DAT_0106fdcc) {
        S0049add0_Point dir(0.0f, 0.0f, 1.0f);
        S0049add0_Point pos = DAT_0108ec68;
        {
            dir = *rotation * dir;
            dir.Unitize();
        }
        pos = *position;
        {
            S0049add0_Plane plane(dir, pos);
            S0049add0_Entry* node = unk3C.GetHeadPos();
            while (node) {
                S0049add0_Entry* next = node ? node->next : 0;
                if (node) {
                    S0049add0_Box* box = (S0049add0_Box*)node->item;
                    if (FUN_00464d70(&box->unk04, &plane, 0.01f) && fabs(box->unk10 - plane.constant) <= 0.01f) {
                        S0049add0_Entry* sub = box->unk24.head;
                        while (sub) {
                            S0049add0_Entry* subNext = sub ? sub->next : 0;
                            void* item = sub ? sub->item : 0;
                            if (!sub) break;
                            {
                            if (item == object) {
                                box->unk24.FUN_00496910(sub);
                                S0049add0_Form* form = FUN_004941a0(item);
                                if (form) {
                                    S0049add0_State* state = form->FUN_00826590(3);
                                    state->unk13C.Clear();
                                    state->unk140.Clear();
                                    state->unk138.Clear();
                                    state->unk144.Clear();
                                }
                                if (box->unk24.count == 0) {
                                    unk3C.FUN_00496910(node);
                                    box->FUN_0049a1c0();
                                    DAT_01090a78.FUN_0086ba60(box);
                                }
                                if (unk3C.count == 0)
                                    FUN_00495b90(1, 0);
                                FUN_00493d10();
                                return true;
                            }
                            }
                            sub = subNext;
                        }
                    }
                }
                node = next;
            }
        }
    }
    return false;
}
}
}   // namespace f3m_0049add0

// @f3 0x00481490 (community match, verified in this file)
extern void* g_heap_00481490;
extern void* g_player_00481490;
extern void* g_taskQueue_00481490;
extern __declspec(thread) void* g_tlsRef_00481490;
extern __declspec(thread) void* g_tls3D_00481490;
namespace f3m_00481490 {


namespace fn_00481490 {

struct InvHeap
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};

inline InvHeap* GetHeap() { return reinterpret_cast<InvHeap*>(&g_heap_00481490); }

class TESObjectREFR;

struct ExtraDataList
{
    virtual ~ExtraDataList();
    void* m_data;
    unsigned int presence[5];
    bool IsEmpty() { return !m_data; }
    bool ExtraDataList_GetCanNotWear();
    TESObjectREFR* FUN_0040bd70();
    bool ExtraDataList_GetWorn(bool abLeft);
    void FUN_0040b5e0(bool abWorn, bool abWornLeft);
    unsigned int BaseExtraList_ItemsInList();
    char FUN_0040e260();
    void FUN_0040e1b0(unsigned char aucHotKey);
    short FUN_0040ac80();
    void ExtraDataList_SetCount(unsigned short ausCount);
    bool ExtraDataList_CompareListForContainer(ExtraDataList* apOther, bool abFlag);
};

template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList<T>* next;
    bool IsEmpty() { return !next && !item; }
    T& GetItem() { return item; }
    BSSimpleList<T>* GetNext() { return next; }
    void FUN_006c8220();
    ~BSSimpleList() { FUN_006c8220(); }
    void FUN_00421610(const T& apItem);
    static void* operator new(unsigned int size) { return GetHeap()->FUN_0086b930(size); }
    static void operator delete(void* memory) { GetHeap()->FUN_0086ba60(memory); }
};

template <class T> inline void BSSimpleList<T>::FUN_00421610(const T& apItem)
{
    if (!apItem || IsEmpty())
        return;
    BSSimpleList<T>* pkFirst = this;
    BSSimpleList<T>* pkSecond = this;
    while (pkFirst && pkFirst->item != apItem)
    {
        pkSecond = pkFirst;
        pkFirst = pkFirst->next;
    }
    if (pkFirst)
    {
        if (pkFirst == this)
        {
            if (next)
            {
                pkSecond = next;
                next = pkSecond->next;
                item = pkSecond->item;
                pkSecond->next = 0;
                delete pkSecond;
            }
            else
                item = 0;
        }
        else
        {
            pkSecond->next = pkFirst->next;
            pkFirst->next = 0;
            delete pkFirst;
        }
    }
}

typedef BSSimpleList<ExtraDataList*> ExtraNode;

class TESForm
{
public:
    void* vtbl;
    unsigned char cFormType;
    int GetFormType() { return cFormType; }
};

struct TESBipedModelForm
{
    void* vtbl;
    unsigned int uiBipedObjectSlots;
    unsigned char cBipedFlags;
    bool FUN_00451d60();
    bool IsHeavy() { return (cBipedFlags & 0x80) != 0; }
};

class TESObjectARMO : public TESForm
{
public:
    unsigned int m_f08;
    unsigned int m_f0c;
    unsigned int m_f10;
    unsigned int m_f14;
    unsigned int m_f18;
    unsigned int m_f1c;
    unsigned int m_f20;
    unsigned int m_f24;
    unsigned int m_f28;
    unsigned int m_f2c;
    unsigned int m_f30;
    unsigned int m_f34;
    unsigned int m_f38;
    unsigned int m_f3c;
    unsigned int m_f40;
    unsigned int m_f44;
    unsigned int m_f48;
    unsigned int m_f4c;
    unsigned int m_f50;
    unsigned int m_f54;
    unsigned int m_f58;
    unsigned int m_f5c;
    unsigned int m_f60;
    unsigned int m_f64;
    unsigned int m_f68;
    unsigned int m_f6c;
    TESBipedModelForm bipedModel;
};

struct ItemChange
{
    ExtraNode* list;
    int count;
    TESForm* form;
    int GetCount() { return count; }
    ExtraNode* GetExtraList() { return list; }
    int FUN_0047ce40(bool abWornIgnore);
    void FUN_00424690(unsigned int auiFlags);
};

typedef BSSimpleList<ItemChange*> ItemChangeNode;

class Actor;

struct BaseProcess
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
    virtual void v140(); virtual void v144();
    virtual ItemChange* CurrentWeapon();
    virtual ItemChange* CurrentAmmo();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15c();
    virtual void SetWeapon(ItemChange* apWeapon, int aiUnused);
    virtual void v164();
    virtual void SetAmmo(ItemChange* apAmmo);
    virtual void v16c(); virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17c();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18c();
    virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19c();
    virtual void v1a0(); virtual void v1a4(); virtual void v1a8(); virtual void v1ac();
    virtual void v1b0(); virtual void v1b4(); virtual void v1b8(); virtual void v1bc();
    virtual void v1c0(); virtual void v1c4(); virtual void v1c8(); virtual void v1cc();
    virtual void v1d0(); virtual void v1d4(); virtual void v1d8(); virtual void v1dc();
    virtual void v1e0(); virtual void v1e4(); virtual void v1e8(); virtual void v1ec();
    virtual void v1f0(); virtual void v1f4(); virtual void v1f8(); virtual void v1fc();
    virtual void v200(); virtual void v204(); virtual void v208(); virtual void v20c();
    virtual void v210(); virtual void v214(); virtual void v218(); virtual void v21c();
    virtual void v220(); virtual void v224(); virtual void v228(); virtual void v22c();
    virtual void v230(); virtual void v234(); virtual void v238(); virtual void v23c();
    virtual void v240(); virtual void v244(); virtual void v248(); virtual void v24c();
    virtual void v250(); virtual void v254(); virtual void v258(); virtual void v25c();
    virtual void v260(); virtual void v264(); virtual void v268(); virtual void v26c();
    virtual void v270(); virtual void v274(); virtual void v278(); virtual void v27c();
    virtual void v280(); virtual void v284(); virtual void v288(); virtual void v28c();
    virtual void v290(); virtual void v294(); virtual void v298(); virtual void v29c();
    virtual void v2a0(); virtual void v2a4(); virtual void v2a8(); virtual void v2ac();
    virtual void v2b0(); virtual void v2b4(); virtual void v2b8(); virtual void v2bc();
    virtual void v2c0(); virtual void v2c4(); virtual void v2c8(); virtual void v2cc();
    virtual void v2d0(); virtual void v2d4(); virtual void v2d8(); virtual void v2dc();
    virtual void v2e0(); virtual void v2e4(); virtual void v2e8(); virtual void v2ec();
    virtual void v2f0(); virtual void v2f4(); virtual void v2f8(); virtual void v2fc();
    virtual void v300(); virtual void v304(); virtual void v308(); virtual void v30c();
    virtual void v310(); virtual void v314(); virtual void v318(); virtual void v31c();
    virtual void v320(); virtual void v324(); virtual void v328(); virtual void v32c();
    virtual void v330(); virtual void v334(); virtual void v338(); virtual void v33c();
    virtual void v340(); virtual void v344(); virtual void v348(); virtual void v34c();
    virtual void v350(); virtual void v354(); virtual void v358(); virtual void v35c();
    virtual void v360(); virtual void v364(); virtual void v368(); virtual void v36c();
    virtual void v370(); virtual void v374(); virtual void v378(); virtual void v37c();
    virtual void v380(); virtual void v384(); virtual void v388(); virtual void v38c();
    virtual void v390(); virtual void v394(); virtual void v398(); virtual void v39c();
    virtual void v3a0(); virtual void v3a4(); virtual void v3a8(); virtual void v3ac();
    virtual void v3b0(); virtual void v3b4(); virtual void v3b8(); virtual void v3bc();
    virtual void v3c0(); virtual void v3c4(); virtual void v3c8(); virtual void v3cc();
    virtual void v3d0(); virtual void v3d4(); virtual void v3d8(); virtual void v3dc();
    virtual void v3e0(); virtual void v3e4(); virtual void v3e8(); virtual void v3ec();
    virtual void v3f0(); virtual void v3f4(); virtual void v3f8(); virtual void v3fc();
    virtual void v400(); virtual void v404(); virtual void v408(); virtual void v40c();
    virtual void v410(); virtual void v414(); virtual void v418(); virtual void v41c();
    virtual void v420(); virtual void v424(); virtual void v428(); virtual void v42c();
    virtual void v430(); virtual void v434(); virtual void v438(); virtual void v43c();
    virtual void v440(); virtual void v444(); virtual void v448(); virtual void v44c();
    virtual void v450(); virtual void v454(); virtual void v458(); virtual void v45c();
    virtual void v460();
    virtual void SetUpdate(int aiState);
    virtual void v468(); virtual void v46c();
    virtual void v470(); virtual void v474(); virtual void v478(); virtual void v47c();
    virtual void v480(); virtual void v484(); virtual void v488(); virtual void v48c();
    virtual void v490(); virtual void v494(); virtual void v498(); virtual void v49c();
    virtual void v4a0(); virtual void v4a4(); virtual void v4a8(); virtual void v4ac();
    virtual void v4b0(); virtual void v4b4(); virtual void v4b8(); virtual void v4bc();
    virtual void v4c0(); virtual void v4c4(); virtual void v4c8(); virtual void v4cc();
    virtual void v4d0(); virtual void v4d4(); virtual void v4d8(); virtual void v4dc();
    virtual void v4e0(); virtual void v4e4(); virtual void v4e8(); virtual void v4ec();
    virtual void v4f0(); virtual void v4f4(); virtual void v4f8(); virtual void v4fc();
    virtual void v500(); virtual void v504(); virtual void v508(); virtual void v50c();
    virtual void v510(); virtual void v514(); virtual void v518(); virtual void v51c();
    virtual void v520(); virtual void v524(); virtual void v528(); virtual void v52c();
    virtual void v530(); virtual void v534(); virtual void v538(); virtual void v53c();
    virtual void v540(); virtual void v544(); virtual void v548(); virtual void v54c();
    virtual void v550(); virtual void v554(); virtual void v558(); virtual void v55c();
    virtual void v560(); virtual void v564(); virtual void v568(); virtual void v56c();
    virtual void v570(); virtual void v574(); virtual void v578(); virtual void v57c();
    virtual void v580(); virtual void v584(); virtual void v588(); virtual void v58c();
    virtual void v590(); virtual void v594(); virtual void v598(); virtual void v59c();
    virtual void v5a0(); virtual void v5a4(); virtual void v5a8(); virtual void v5ac();
    virtual void v5b0(); virtual void v5b4(); virtual void v5b8(); virtual void v5bc();
    virtual void v5c0(); virtual void v5c4(); virtual void v5c8(); virtual void v5cc();
    virtual void v5d0(); virtual void v5d4(); virtual void v5d8(); virtual void v5dc();
    virtual void v5e0(); virtual void v5e4(); virtual void v5e8(); virtual void v5ec();
    virtual void v5f0(); virtual void v5f4(); virtual void v5f8(); virtual void v5fc();
    virtual void v600(); virtual void v604(); virtual void v608(); virtual void v60c();
    virtual void v610(); virtual void v614(); virtual void v618(); virtual void v61c();
    virtual void v620(); virtual void v624(); virtual void v628(); virtual void v62c();
    virtual void v630(); virtual void v634(); virtual void v638(); virtual void v63c();
    virtual void v640(); virtual void v644(); virtual void v648(); virtual void v64c();
    virtual void v650(); virtual void v654(); virtual void v658(); virtual void v65c();
    virtual void v660(); virtual void v664(); virtual void v668(); virtual void v66c();
    virtual void v670(); virtual void v674(); virtual void v678(); virtual void v67c();
    virtual void v680(); virtual void v684(); virtual void v688(); virtual void v68c();
    virtual void v690(); virtual void v694(); virtual void v698(); virtual void v69c();
    virtual void v6a0(); virtual void v6a4(); virtual void v6a8(); virtual void v6ac();
    virtual void v6b0(); virtual void v6b4(); virtual void v6b8(); virtual void v6bc();
    virtual void v6c0(); virtual void v6c4(); virtual void v6c8(); virtual void v6cc();
    virtual void v6d0(); virtual void v6d4(); virtual void v6d8();
    virtual void UpdateArmor(Actor* apActor);
};

struct TESContainer
{
    int FUN_00452c40(TESForm* apObject);
};

struct LoadedRefData
{
    unsigned int m_f00;
    unsigned int m_f04;
    unsigned int m_f08;
    unsigned int m_f0c;
    unsigned int m_f10;
    void* p3D;
};

class TESObjectREFR
{
public:
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044();
    virtual void MarkAsModified(unsigned int auiFlags);
    virtual void v04c();
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
    virtual bool IsActor();
    virtual void v104(); virtual void v108(); virtual void v10c();
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
    virtual void v1f0(); virtual void v1f4(); virtual void v1f8(); virtual void v1fc();
    virtual void v200(); virtual void v204(); virtual void v208(); virtual void v20c();
    virtual void v210(); virtual void v214(); virtual void v218(); virtual void v21c();
    virtual void v220(); virtual void v224(); virtual void v228();
    virtual bool CanRemove(bool abForce);
    virtual void v230(); virtual void v234(); virtual void v238(); virtual void v23c();
    virtual void v240(); virtual void v244(); virtual void v248(); virtual void v24c();
    virtual void v250(); virtual void v254(); virtual void v258(); virtual void v25c();
    virtual void v260(); virtual void v264(); virtual void v268(); virtual void v26c();
    virtual void v270(); virtual void v274(); virtual void v278(); virtual void v27c();
    virtual void v280(); virtual void v284(); virtual void v288(); virtual void v28c();
    virtual void v290(); virtual void v294(); virtual void v298(); virtual void v29c();
    virtual void v2a0(); virtual void v2a4(); virtual void v2a8(); virtual void v2ac();
    virtual void v2b0(); virtual void v2b4(); virtual void v2b8(); virtual void v2bc();
    virtual void v2c0(); virtual void v2c4(); virtual void v2c8(); virtual void v2cc();
    virtual void v2d0(); virtual void v2d4(); virtual void v2d8(); virtual void v2dc();
    virtual void v2e0(); virtual void v2e4(); virtual void v2e8(); virtual void v2ec();
    virtual void v2f0(); virtual void v2f4(); virtual void v2f8(); virtual void v2fc();
    virtual void v300(); virtual void v304(); virtual void v308();
    virtual void SetTotalWeight(float afWeight);
    unsigned int m_f04;
    unsigned int m_f08;
    unsigned int uiFormID;
    unsigned int m_f10;
    unsigned int m_f14;
    unsigned int m_f18;
    unsigned int m_f1c;
    unsigned int m_f20;
    unsigned int m_f24;
    unsigned int m_f28;
    unsigned int m_f2c;
    unsigned int m_f30;
    unsigned int m_f34;
    unsigned int m_f38;
    unsigned int m_f3c;
    unsigned int m_f40;
    unsigned int m_f44;
    unsigned int m_f48;
    unsigned int m_f4c;
    unsigned int m_f50;
    unsigned int m_f54;
    unsigned int m_f58;
    unsigned int GetFormID() { return uiFormID; }
    LoadedRefData* pLoadedData;
    BaseProcess* pBaseProcess;
    TESContainer* FUN_004e66c0();
    void* Get3D();
};


inline void* TESObjectREFR::Get3D()
{
    if (this == (TESObjectREFR*)g_tlsRef_00481490)
        return g_tls3D_00481490;
    void* result;
    if (pLoadedData)
        result = pLoadedData->p3D;
    else
        result = 0;
    return result;
}

class Actor : public TESObjectREFR
{
public:
    unsigned int m_f64;
    unsigned int m_f68;
    unsigned int m_f6c;
    unsigned int m_f70;
    unsigned int m_f74;
    unsigned int m_f78;
    unsigned int m_f7c;
    unsigned int m_f80;
    unsigned int m_f84;
    unsigned int m_f88;
    unsigned int m_f8c;
    unsigned int m_f90;
    unsigned int m_f94;
    unsigned int m_f98;
    unsigned int m_f9c;
    unsigned int m_fa0;
    unsigned int m_fa4;
    unsigned int m_fa8;
    unsigned int m_fac;
    unsigned int m_fb0;
    unsigned int m_fb4;
    unsigned int m_fb8;
    unsigned int m_fbc;
    unsigned int m_fc0;
    unsigned int m_fc4;
    unsigned int m_fc8;
    unsigned int m_fcc;
    unsigned int m_fd0;
    unsigned int m_fd4;
    unsigned int m_fd8;
    unsigned int m_fdc;
    unsigned int m_fe0;
    unsigned int m_fe4;
    unsigned int m_fe8;
    unsigned int m_fec;
    unsigned int m_ff0;
    unsigned int m_ff4;
    unsigned int m_ff8;
    unsigned int m_ffc;
    unsigned int m_f100;
    unsigned int m_f104;
    unsigned int m_f108;
    unsigned int m_f10c;
    unsigned int m_f110;
    unsigned int m_f114;
    unsigned int m_f118;
    unsigned int m_f11c;
    unsigned int m_f120;
    unsigned int m_f124;
    unsigned int m_f128;
    unsigned int m_f12c;
    unsigned int m_f130;
    unsigned int m_f134;
    unsigned int m_f138;
    unsigned int m_f13c;
    unsigned int m_f140;
    unsigned int m_f144;
    unsigned int m_f148;
    unsigned int m_f14c;
    unsigned int m_f150;
    unsigned int m_f154;
    unsigned int m_f158;
    unsigned int m_f15c;
    unsigned int m_f160;
    unsigned int m_f164;
    unsigned int m_f168;
    unsigned int m_f16c;
    unsigned int m_f170;
    unsigned int m_f174;
    unsigned int m_f178;
    unsigned int m_f17c;
    unsigned int m_f180;
    unsigned int m_f184;
    unsigned int m_f188;
    unsigned int m_f18c;
    unsigned int m_f190;
    unsigned int m_f194;
    unsigned int m_f198;
    unsigned int m_f19c;
    unsigned int m_f1a0;
    unsigned int m_f1a4;
    unsigned int m_f1a8;
    unsigned int m_f1ac;
    unsigned int m_f1b0;
    void* pField1b4;
    BaseProcess* GetCurrentProcess() { return pBaseProcess; }
    void FUN_004ed800();
    void FUN_00c24b70();
    void FUN_00701b40(void* apNode);
};

struct TaskQueueInterface
{
    void FUN_006f2f20(Actor* apActor, TESForm* apWeapon);
};

TESBipedModelForm* FUN_00451da0(TESForm* apObject);
bool FUN_00724400();

struct InventoryChanges
{
    ItemChangeNode* objList;
    TESObjectREFR* ref;
    float fcontainerweight;
    float fpreviousContainerWeight;
    TESContainer* GetOriginalContainer() { return ref ? ref->FUN_004e66c0() : 0; }
    void ResetCachedWeights()
    {
        fpreviousContainerWeight = fcontainerweight;
        fcontainerweight = -1.0f;
        if (ref && ref->IsActor())
        {
            Actor* pact = static_cast<Actor*>(ref);
            pact->SetTotalWeight(-1.0f);
        }
    }
    // InventoryChanges::GetObjectInList (the twin's 0x004bfba0; Fallout 3's out-of-line copy is 0x0047e180).
    ItemChange* GetObjectInList(TESForm* apObj, bool ableveled, unsigned int aId)
    {
        ItemChangeNode* pkFirst = objList;
        bool bflag = true;
        while (pkFirst && bflag)
        {
            ItemChange* pchange = pkFirst->item;
            if (pchange && pchange->form == apObj)
                bflag = false;
            else
                pkFirst = pkFirst->next;
        }
        if (pkFirst)
        {
            ItemChange* pchange = pkFirst->item;
            if (pchange && aId)
            {
                ExtraNode* node = pchange->list;
                while (node)
                {
                    ExtraDataList* pextra = node->item;
                    if (pextra && pextra->FUN_0040bd70() && pextra->FUN_0040bd70()->GetFormID() == aId)
                        return pchange;
                    node = node->next;
                }
                return 0;
            }
            else
                return pchange;
        }
        else
            return 0;
    }
    bool InventoryChanges_RemoveWorn(bool* abRemoved, TESForm* apObject, int aiNumber, Actor* apActor, ExtraDataList* apExtra,
                      bool ableft, bool abforce);
};

// pdb: InventoryChanges::RemoveWorn | InventoryChanges.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
bool InventoryChanges::InventoryChanges_RemoveWorn(bool* abRemoved, TESForm* apObject, int aiNumber, Actor* apActor,
                                    ExtraDataList* apExtra, bool ableft, bool abforce)
{
    ResetCachedWeights();
    ItemChange* pchangeItem = GetObjectInList(apObject, true, 0);
    if (!pchangeItem)
        return true;
    *abRemoved = true;
    ExtraNode* pkFirst = pchangeItem->list;
    bool bExtraGood = true;
    int iorgCount;
    bool bremovedPowerArmor = false;
    while (pkFirst && pkFirst->GetItem())
    {
        ExtraDataList* pExtra = pkFirst->GetItem();
        if (pExtra->ExtraDataList_GetCanNotWear() && !apActor->CanRemove(false))
        {
            *abRemoved = false;
            return bExtraGood;
        }
        if (pExtra->ExtraDataList_GetWorn(ableft) && (!apExtra || apExtra == pExtra))
        {
            ItemChange* pitem = 0;
            TESBipedModelForm* pmodel = FUN_00451da0(apObject);
            if (apActor && apActor->GetCurrentProcess())
            {
                switch (apObject->GetFormType())
                {
                case 26:
                    apActor->pBaseProcess->SetUpdate(1);
                    break;
                case 40:
                    pitem = apActor->GetCurrentProcess()->CurrentWeapon();
                    if (pitem)
                    {
                        if (pitem->list->GetItem() == pExtra || !apExtra)
                        {
                            if (apActor == (Actor*)g_player_00481490)
                                ((Actor*)g_player_00481490)->pField1b4 = 0;
                            if (FUN_00724400())
                                ((TaskQueueInterface*)g_taskQueue_00481490)->FUN_006f2f20(apActor, pitem->form);
                            else
                            {
                                apActor->FUN_004ed800();
                                apActor->GetCurrentProcess()->SetWeapon(0, 0);
                            }
                        }
                    }
                    break;
                case 24:
                    if (static_cast<TESObjectARMO*>(apObject)->bipedModel.FUN_00451d60() ||
                        static_cast<TESObjectARMO*>(apObject)->bipedModel.IsHeavy())
                        bremovedPowerArmor = true;
                    apActor->pBaseProcess->SetUpdate(1);
                    break;
                case 41:
                    pitem = apActor->GetCurrentProcess()->CurrentAmmo();
                    if (pitem)
                    {
                        if (pitem->list->GetItem() == pExtra)
                        {
                            apActor->FUN_00c24b70();
                            apActor->GetCurrentProcess()->SetAmmo(0);
                        }
                    }
                    break;
                }
            }
            pExtra->FUN_0040b5e0(false, ableft);
            if (pExtra->BaseExtraList_ItemsInList() <= 1)
            {
                if (pExtra->FUN_0040e260() >= 0)
                    pExtra->ExtraDataList_SetCount(pchangeItem->GetCount() - pchangeItem->FUN_0047ce40(false));
                else
                    pExtra->ExtraDataList_SetCount(0);
            }
            if (pExtra->IsEmpty())
            {
                pchangeItem->list->FUN_00421610(pExtra);
                delete pExtra;
                pExtra = 0;
                bExtraGood = false;
                break;
            }
            else
            {
                ExtraNode* node2 = pchangeItem->list;
                while (node2 && node2->GetItem() && bExtraGood)
                {
                    ExtraDataList* pCurrent = node2->GetItem();
                    ExtraDataList* pcompare = pExtra;
                    bool bcomp = true;
                    if (pcompare)
                        bcomp = pcompare->ExtraDataList_CompareListForContainer(pCurrent, false) || pCurrent->ExtraDataList_CompareListForContainer(pcompare, false);
                    if (bcomp || pExtra == pCurrent)
                        node2 = node2->GetNext();
                    else
                    {
                        pCurrent->ExtraDataList_SetCount(pCurrent->FUN_0040ac80() + aiNumber);
                        if (pExtra->FUN_0040e260() >= 0)
                            pCurrent->FUN_0040e1b0(pExtra->FUN_0040e260());
                        if (pCurrent->IsEmpty())
                        {
                            pchangeItem->list->FUN_00421610(pCurrent);
                            delete pCurrent;
                        }
                        else
                            pchangeItem->list->FUN_00421610(pExtra);
                        delete pExtra;
                        pExtra = 0;
                        bExtraGood = false;
                    }
                }
            }
            pkFirst = 0;
        }
        else
            pkFirst = pkFirst->GetNext();
    }
    if (bremovedPowerArmor)
    {
        if (apActor)
        {
            if (apActor->GetCurrentProcess())
                apActor->GetCurrentProcess()->UpdateArmor(apActor);
        }
    }
    if (ref)
        ref->MarkAsModified(0x20);
    iorgCount = GetOriginalContainer()->FUN_00452c40(apObject);
    if (pchangeItem && pchangeItem->list && pchangeItem->list->IsEmpty() &&
        (!pchangeItem->GetCount() || iorgCount == pchangeItem->GetCount()))
    {
        objList->FUN_00421610(pchangeItem);
        pchangeItem->FUN_00424690(1);
        return false;
    }
    else if (pchangeItem->GetCount() < 0 && pchangeItem->GetExtraList())
        pchangeItem->GetExtraList()->FUN_006c8220();
    if (apActor)
        apActor->FUN_00701b40(apActor->Get3D());
    return bExtraGood;
}

}
}   // namespace f3m_00481490
