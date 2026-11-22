// gamebryo2.2/corelibs/niparticle/nipsyspositionmodifier.cpp: NiPSysPositionModifier, Helper, NiPSysModifier (7 functions)
#include "f3_common.h"
#include "nipsyspositionmodifier_decls.h"

// @fnv 0x00c31720
// pdb: NiPSysModifier::NiPSysModifier | NiPSysModifier.obj | fnv360_1110_retail, objrun, high
NiPSysPositionModifier::NiPSysPositionModifier()
{
    m_kName = EmptyFS;
    m_uiUpdateOrder = 0;
    m_pkTarget = 0;
    m_bModifierActive = true;
}

void __cdecl FUN_00c31750(void);
void __cdecl _delete(void*, unsigned int);
struct Helper
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00c31750, then deletes this with size 0x18 when bit 0 of flags is set, and returns this.
// @fnv 0x00c28ba0
// pdb: bhkShapePhantom::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
void* Helper::DestroyIfFlagged(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        _delete(this, 0x18);
    return this;
}

struct FnvV3
{
    float x, y, z;
};

struct FnvPSysPos
{
    float x, y, z;
};

struct FnvPSysPart
{
    float x, y, z;
    float unk0c, unk10;
    float lastTime;
    int unk18;
};

struct FnvMod
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FnvPSysPos* positions;
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
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    FnvPSysPart* parts;
    int unk74;
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void Slot43();
};

// Advances each particle position by its velocity times the elapsed time since its last update, then stores the new time.
// @fnv 0x00c28bc0
// pdb: NiPSysPositionModifier::Update | NiPSysPositionModifier.obj | fnv360_0822_retail, objrun_open, low
// pdb params: fTime, pkData
void __stdcall IntegrateParticlePositions(float fTime, FnvMod* pMod)
{
    pMod->Slot43();
    FnvPSysPart* parts = pMod->parts;
    for (unsigned short usIndex = 0; usIndex < pMod->count; usIndex++)
    {
        FnvPSysPart* part = parts + usIndex;
        FnvPSysPos* pos = pMod->positions + usIndex;
        // the time delta is built in two steps: the copy of fTime and the
        // subtraction of the stored stamp.  Keeping them apart changes how
        // cl 15.00.30729.01 schedules the x87 stack, which is what the
        // original code shows.
        float dt = fTime;
        dt = dt - part->lastTime;
        FnvV3 v;
        v.x = part->x * dt;
        v.y = part->y * dt;
        v.z = part->z * dt;
        pos->x += v.x;
        pos->y += v.y;
        pos->z += v.z;
        part->lastTime = fTime;
    }
}

class BC28C60CloningProcess;

class BC28C60Modifier
{
  public:
    static void* operator new(unsigned int uiSize);

    BC28C60Modifier() throw();
    virtual ~BC28C60Modifier();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class BC28C60GravityModifier : public BC28C60Modifier
{
  public:
    __forceinline BC28C60GravityModifier()
    {}
    virtual ~BC28C60GravityModifier();

    void CopyMemberData(BC28C60GravityModifier* pkDest, BC28C60CloningProcess& kCloning);
    BC28C60GravityModifier* NiPSysPositionModifier_CreateClone(BC28C60CloningProcess& kCloning);
};

// @fnv 0x00c28c60
// pdb: NiPSysPositionModifier::CreateClone | NiPSysPositionModifier.obj | fnv360_0822_retail, objopen_prop + bridge(vtable|objopen_prop) + skyrim(caller_sim), high
BC28C60GravityModifier* BC28C60GravityModifier::NiPSysPositionModifier_CreateClone(BC28C60CloningProcess& kCloning)
{
    BC28C60GravityModifier* pkClone = new BC28C60GravityModifier;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

class NiStream;
class NiPSysModifier
{
  public:
    void LoadBinary(NiStream& stream);
    void FUN_00c28b50(NiStream& a1);
};
// @fnv 0x00c28b50
// pdb: NiAmbientLight::IsEqual | NiAmbientLight.obj | fnv360_0822_retail, objrun_prop, high
// pdb params: pObject
void NiPSysModifier::FUN_00c28b50(NiStream& a1)
{
    LoadBinary(a1);
}

void __cdecl FUN_00c31830();
// @fnv 0x00c28b80
// pdb: NiAlphaAccumulator::RegisterStreamables | NiAlphaAccumulator.obj | fnv360_0822_retail, caller_sim + bridge(vtable|caller_sim) + skyrim(caller_sim), high
void __cdecl NiAlphaAccumulator_RegisterStreamables()
{
    FUN_00c31830();
}

void __cdecl FUN_00c31950();

// @fnv 0x00c28b70
// pdb: BSMultiBoundOBB::LinkObject | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, high
// pdb params: arStream
void __cdecl FUN_00c28b70()
{
    FUN_00c31950();
}
