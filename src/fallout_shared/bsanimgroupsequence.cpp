// fallout_shared/bsanimgroupsequence.cpp: BSAnimGroupSequence, TaskQueueInterface, TargetClass, SoundPlaybackManager (1 function)
#include "f3_common.h"
#include "bsanimgroupsequence_decls.h"

struct HY
{
    float FUN_004eec60(float);
};

struct BSAnimGroupSequence;

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

namespace fnv_004efb20 {
// Stand-ins for types not in scope
struct TESSaveLoadGame
{
    unsigned char FUN_008df040(void);
    void FUN_008579b0(void* data, unsigned int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

}  // namespace fnv_004efb20

struct NiControllerManager
{
    int GetStringAtOffset(int);
};
struct TargetClass
{
    char _pad[0x40];
    NiControllerManager* field40;
    int NiControllerSequence_ResolveTransformInterpolators(int, int);
    int FUN_004eedd0(int, int);
};
// Returns the result of NiControllerSequence_ResolveTransformInterpolators with a1 and the value GetStringAtOffset returns for a2 on field40.
// @f3 0x005fd4b0 (community match, verified in this file)
struct ArgumentObjectView6
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
    void* m_field3c;
    void* FUN_004e8880();
};

struct TargetTableView6
{
    void* m_pTable;
    void PathingLocation_SetupData(int a, int f, void* r);
};

extern int DAT_00dc4dc0;

// pdb: PathingLocation::PathingLocation | PathingLocation.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aLocation, apRef
int TargetClass::FUN_004eedd0(int a, int b)
{
    ArgumentObjectView6* p = (ArgumentObjectView6*)b;
    TargetTableView6* self = reinterpret_cast<TargetTableView6*>(this);
    self->m_pTable = (void*)&DAT_00dc4dc0;
    int f = (int)p->m_field3c;
    void* r = p->FUN_004e8880();
    self->PathingLocation_SetupData(a, f, r);
    return (int)(void*)this;
}


struct GO
{
    int data;

    GO(int);
    ~GO();
    operator unsigned int() const;
    void operator=(void*);
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

namespace fnv_004efbc0 {
class TESSaveLoadGame
{
  public:
    void ReadTypedData(void* data, unsigned int size);
};

class HY
{
  public:
    float FUN_004eec60(float value);
    void FUN_004efbc0(float value);
};

}  // namespace fnv_004efbc0

struct NameECB
{
    void* GetItem();
};
struct CollectionECB;
struct CollectionECB
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void* v09C(NameECB*);
};
struct PointerECB
{
    void* object;
    PointerECB& operator=(void*);
};
extern unsigned char DAT_01096968;

extern unsigned char DAT_01096968;
