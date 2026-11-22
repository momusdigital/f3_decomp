#include "f3_common.h"
// src/havok/common/base/system/io/ostream/hkostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/ostream/hkostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkOstream.h"

extern int DAT_01268108;
extern "C" __declspec(dllimport) void __stdcall free(void*);

// @fnv 0x00c85750
// pdb: `dynamic atexit destructor for 'iMaxGrassTypesPerTexture'' | TESLand.obj | tesv_win, objrun_open, low
void __cdecl FUN_00c85750()
{
    free((void*)DAT_01268108);
}

extern char _DAT_010c9314;
extern char _DAT_0102e388;
struct Old
{
    void ReleaseReference();
};
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    ~FUN_00cc00e0();
};
// @fnv 0x00cc00e0
FUN_00cc00e0::~FUN_00cc00e0()
{
    vtbl = (void*)&_DAT_010c9314;
    if (m_pStreamWriter)
        m_pStreamWriter->ReleaseReference();
    vtbl = (void*)&_DAT_0102e388;
}

// @f3 0x007d7a60 (community match, verified in this file)
namespace f3m_007d7a60 {
struct Listener_7d7a60
{
    void FUN_006f8ce0();
};

struct BroadPhase_7d7a60
{
    unsigned char _pad0[0xbc];
    Listener_7d7a60* m_listener;
};

struct World_7d7a60
{
    int unk00;
    BroadPhase_7d7a60* m_broadPhase;
    void FUN_007d7a60();
    void FUN_007ab540();
    void FUN_007ab580();
};

// pdb: CombatProcedureHideFromTarget::Shutdown | CombatProcedureHideFromTarget.obj | fnv360_0822_retail, vtable, medium
void World_7d7a60::FUN_007d7a60()
{
    m_broadPhase->m_listener->FUN_006f8ce0();
    FUN_007ab540();
    FUN_007ab580();
}
}   // namespace f3m_007d7a60


struct FUN_00cc07f0_StandIn
{
    // Virtual destructor for the stand-in type; does nothing.
// @fnv 0x00cc07f0
    virtual ~FUN_00cc07f0_StandIn()
    {}
    void FUN_00cc0780();
    unsigned short m_nSize;

    FUN_00cc07f0_StandIn* FUN_00cc07f0(unsigned int deletingFlag);
};

struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    CpuInterface* target;
    void FUN_00cc0460();
};
// @fnv 0x00cc0460
void CpuObject::FUN_00cc0460()
{
    target->Invoke();
}

// hkOstream_write : the stub family - load a sub-object out of `this` and tail-jump to
// one of its virtuals (vtable offset 0x10).
struct Sub_00cc0470
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(void* a);
};

struct Own_00cc0470
{
    int u00;
    int u04;
    Sub_00cc0470* m_sub;
    void __thiscall hkOstream_write(void* a);
};

// @fnv 0x00cc0470
// pdb: hkOstream::write | hkOStream.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
void __thiscall Own_00cc0470::hkOstream_write(void* a)
{
    m_sub->v10(a);
}

extern int g_unk01268560;

// @fnv 0x00cc04c0
// pdb: hkpConstraintData::isBuildJacobianCallbackRequired | bhkMalleableConstraint.obj | fnv360_0721_beta, objrun_open, low, conflict (bridge: bhkMalleableConstraint::GetRTTI)
int* __cdecl FUN_00cc04c0()
{
    return &g_unk01268560;
}

extern int DAT_01268ad8;

// @fnv 0x00cc0770
// pdb: bhkRigidBodyT::GetRTTI | bhkRigidBodyT.obj | fnv360_0822_retail, objrun_prop, low
int __cdecl FUN_00cc0770()
{
    return reinterpret_cast<int>(&DAT_01268ad8);
}

// @fnv 0x00e3b490
// pdb: hkOffsetOnlyStreamWriter::isOk | hkOffsetOnlyStreamWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkOffsetOnlyStreamWriter_isOk(bool* p)
{
    *p = true;
}

class hkMemoryAllocatorCC06
{
  public:
    virtual ~hkMemoryAllocatorCC06() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCC06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorCC06* m_pStreamAllocator;

    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750() throw();
}

class hkRefObjCC06
{
  public:
    virtual ~hkRefObjCC06() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjCC06()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes) throw()
    {
        hkRefObjCC06* b = static_cast<hkRefObjCC06*>(hkRouterCC06::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class FUN_00cc06f0 : public hkRefObjCC06
{
  public:
    int unk08;
    int unk0C;
    int unk10;

    FUN_00cc06f0(void* owner, int flag) throw();
};

// @f3 0x0074a440 (community match, verified in this file)
namespace f3m_0074a440 {
namespace Dispatch110Table {
struct Owner;
struct Table {
 unsigned unk000;
 unsigned unk004;
 unsigned unk008;
 unsigned unk00c;
 unsigned unk010;
 unsigned unk014;
 unsigned unk018;
 unsigned unk01c;
 unsigned unk020;
 unsigned unk024;
 unsigned unk028;
 unsigned unk02c;
 unsigned unk030;
 unsigned unk034;
 unsigned unk038;
 unsigned unk03c;
 unsigned unk040;
 unsigned unk044;
 unsigned unk048;
 unsigned unk04c;
 unsigned unk050;
 unsigned unk054;
 unsigned unk058;
 unsigned unk05c;
 unsigned unk060;
 unsigned unk064;
 unsigned unk068;
 unsigned unk06c;
 unsigned unk070;
 unsigned unk074;
 unsigned unk078;
 unsigned unk07c;
 unsigned unk080;
 unsigned unk084;
 unsigned unk088;
 unsigned unk08c;
 unsigned unk090;
 unsigned unk094;
 unsigned unk098;
 unsigned unk09c;
 unsigned unk0a0;
 unsigned unk0a4;
 unsigned unk0a8;
 unsigned unk0ac;
 unsigned unk0b0;
 unsigned unk0b4;
 unsigned unk0b8;
 unsigned unk0bc;
 unsigned unk0c0;
 unsigned unk0c4;
 unsigned unk0c8;
 unsigned unk0cc;
 unsigned unk0d0;
 unsigned unk0d4;
 unsigned unk0d8;
 unsigned unk0dc;
 unsigned unk0e0;
 unsigned unk0e4;
 unsigned unk0e8;
 unsigned unk0ec;
 unsigned unk0f0;
 unsigned unk0f4;
 unsigned unk0f8;
 unsigned unk0fc;
 unsigned unk100;
 unsigned unk104;
 unsigned unk108;
 unsigned unk10c;
 unsigned unk110;
 unsigned unk114;
 unsigned unk118;
 unsigned unk11c;
 unsigned unk120;
 unsigned unk124;
 unsigned unk128;
 void (__thiscall* apply)(Owner*,void*);
 unsigned unk130;
 unsigned unk134;
 unsigned unk138;
 unsigned unk13c;
 unsigned unk140;
 unsigned unk144;
 unsigned unk148;
 unsigned unk14c;
 unsigned unk150;
 unsigned unk154;
 unsigned unk158;
 unsigned unk15c;
 unsigned unk160;
 unsigned unk164;
 unsigned unk168;
 unsigned unk16c;
 unsigned unk170;
 unsigned unk174;
 unsigned unk178;
 unsigned unk17c;
 unsigned unk180;
 unsigned unk184;
 unsigned unk188;
 unsigned unk18c;
 unsigned unk190;
 unsigned unk194;
 unsigned unk198;
 unsigned unk19c;
 unsigned unk1a0;
 unsigned unk1a4;
 unsigned unk1a8;
 unsigned unk1ac;
 unsigned unk1b0;
 unsigned unk1b4;
 unsigned unk1b8;
 unsigned unk1bc;
 unsigned unk1c0;
 unsigned unk1c4;
 unsigned unk1c8;
 unsigned unk1cc;
 unsigned unk1d0;
 unsigned unk1d4;
 unsigned unk1d8;
 unsigned unk1dc;
 unsigned unk1e0;
 unsigned unk1e4;
 unsigned unk1e8;
 unsigned unk1ec;
 unsigned unk1f0;
 unsigned unk1f4;
 unsigned unk1f8;
 unsigned unk1fc;
 unsigned unk200;
 unsigned unk204;
 unsigned unk208;
 unsigned unk20c;
 unsigned unk210;
 unsigned unk214;
 unsigned unk218;
 unsigned unk21c;
 unsigned unk220;
 unsigned unk224;
 unsigned (__thiscall* mode)(Owner*);
 unsigned unk22c;
 unsigned unk230;
 unsigned unk234;
 unsigned unk238;
 unsigned unk23c;
 unsigned unk240;
 unsigned unk244;
 unsigned unk248;
 unsigned unk24c;
 unsigned unk250;
 unsigned unk254;
 unsigned unk258;
 unsigned unk25c;
 unsigned unk260;
 unsigned unk264;
 unsigned unk268;
 unsigned unk26c;
 unsigned unk270;
 unsigned unk274;
 unsigned unk278;
 unsigned unk27c;
 unsigned unk280;
 unsigned unk284;
 unsigned unk288;
 unsigned unk28c;
 unsigned unk290;
 unsigned unk294;
 unsigned unk298;
 unsigned unk29c;
 unsigned unk2a0;
 unsigned unk2a4;
 unsigned unk2a8;
 unsigned unk2ac;
 unsigned unk2b0;
 unsigned unk2b4;
 unsigned unk2b8;
 unsigned unk2bc;
 unsigned unk2c0;
 unsigned unk2c4;
 unsigned unk2c8;
 unsigned unk2cc;
 unsigned unk2d0;
 unsigned unk2d4;
 unsigned unk2d8;
 unsigned unk2dc;
 unsigned unk2e0;
 unsigned unk2e4;
 unsigned unk2e8;
 unsigned unk2ec;
 unsigned unk2f0;
 unsigned unk2f4;
 unsigned unk2f8;
 unsigned unk2fc;
 unsigned unk300;
 unsigned unk304;
 unsigned unk308;
 unsigned unk30c;
 unsigned unk310;
 unsigned unk314;
 unsigned unk318;
 unsigned unk31c;
 unsigned unk320;
 unsigned unk324;
 unsigned unk328;
 unsigned unk32c;
 unsigned unk330;
 unsigned unk334;
 unsigned unk338;
 unsigned unk33c;
 unsigned unk340;
 unsigned unk344;
 unsigned unk348;
 unsigned unk34c;
 unsigned unk350;
 unsigned unk354;
 unsigned unk358;
 unsigned unk35c;
 unsigned unk360;
 unsigned unk364;
 unsigned unk368;
 unsigned unk36c;
 unsigned unk370;
 unsigned unk374;
 unsigned unk378;
 unsigned unk37c;
 unsigned unk380;
 unsigned unk384;
 unsigned unk388;
 unsigned unk38c;
 unsigned unk390;
 unsigned unk394;
 unsigned unk398;
 unsigned unk39c;
 unsigned unk3a0;
 unsigned unk3a4;
 unsigned unk3a8;
 unsigned unk3ac;
 unsigned unk3b0;
 unsigned unk3b4;
 unsigned unk3b8;
 unsigned unk3bc;
 unsigned unk3c0;
 unsigned unk3c4;
 unsigned unk3c8;
 unsigned unk3cc;
 unsigned unk3d0;
 unsigned unk3d4;
 unsigned unk3d8;
 unsigned unk3dc;
 unsigned unk3e0;
 unsigned unk3e4;
 unsigned unk3e8;
 unsigned unk3ec;
 unsigned unk3f0;
 unsigned unk3f4;
 unsigned unk3f8;
 unsigned unk3fc;
 unsigned unk400;
 unsigned unk404;
 unsigned unk408;
 unsigned unk40c;
 unsigned unk410;
 unsigned unk414;
 unsigned unk418;
 unsigned unk41c;
 unsigned unk420;
 unsigned unk424;
 unsigned unk428;
 unsigned unk42c;
 unsigned unk430;
 unsigned unk434;
 unsigned unk438;
 unsigned unk43c;
 unsigned unk440;
 unsigned unk444;
 unsigned unk448;
 unsigned unk44c;
 unsigned unk450;
 unsigned unk454;
 unsigned unk458;
 unsigned unk45c;
 unsigned unk460;
 unsigned unk464;
 unsigned unk468;
 unsigned unk46c;
 unsigned unk470;
 unsigned unk474;
 unsigned unk478;
 unsigned unk47c;
 unsigned unk480;
 unsigned unk484;
 unsigned unk488;
 unsigned unk48c;
 unsigned unk490;
 unsigned unk494;
 unsigned unk498;
 unsigned unk49c;
 unsigned unk4a0;
 unsigned unk4a4;
 unsigned unk4a8;
 unsigned unk4ac;
 unsigned unk4b0;
 unsigned unk4b4;
 unsigned unk4b8;
 unsigned unk4bc;
 unsigned unk4c0;
 unsigned unk4c4;
 unsigned unk4c8;
 unsigned unk4cc;
 unsigned unk4d0;
 unsigned unk4d4;
 unsigned unk4d8;
 unsigned unk4dc;
 unsigned unk4e0;
 unsigned unk4e4;
 unsigned unk4e8;
 unsigned unk4ec;
 unsigned unk4f0;
 unsigned unk4f4;
 unsigned unk4f8;
 unsigned unk4fc;
 unsigned unk500;
 unsigned unk504;
 unsigned unk508;
 unsigned unk50c;
 unsigned unk510;
 unsigned unk514;
 unsigned unk518;
 unsigned unk51c;
 unsigned unk520;
 unsigned unk524;
 unsigned unk528;
 unsigned unk52c;
 unsigned unk530;
 unsigned unk534;
 unsigned unk538;
 unsigned unk53c;
 unsigned unk540;
 unsigned unk544;
 unsigned unk548;
 unsigned unk54c;
 unsigned unk550;
 unsigned unk554;
 unsigned unk558;
 unsigned unk55c;
 unsigned unk560;
 unsigned unk564;
 unsigned unk568;
 unsigned unk56c;
 unsigned unk570;
 unsigned unk574;
 unsigned unk578;
 unsigned unk57c;
 unsigned unk580;
 unsigned unk584;
 unsigned unk588;
 unsigned unk58c;
 unsigned unk590;
 unsigned unk594;
 unsigned unk598;
 unsigned unk59c;
 unsigned unk5a0;
 unsigned unk5a4;
 unsigned unk5a8;
 unsigned unk5ac;
 unsigned unk5b0;
 unsigned unk5b4;
 unsigned unk5b8;
 unsigned unk5bc;
 unsigned unk5c0;
 unsigned unk5c4;
 unsigned unk5c8;
 unsigned unk5cc;
 unsigned unk5d0;
 unsigned unk5d4;
 unsigned unk5d8;
 unsigned unk5dc;
 unsigned unk5e0;
 unsigned unk5e4;
 unsigned unk5e8;
 unsigned unk5ec;
 unsigned unk5f0;
 unsigned unk5f4;
 unsigned unk5f8;
 unsigned unk5fc;
 unsigned unk600;
 unsigned unk604;
 unsigned unk608;
 unsigned unk60c;
 unsigned unk610;
 unsigned unk614;
 unsigned unk618;
 unsigned unk61c;
 unsigned unk620;
 unsigned unk624;
 unsigned unk628;
 unsigned unk62c;
 unsigned unk630;
 unsigned unk634;
 unsigned unk638;
 unsigned unk63c;
 unsigned unk640;
 unsigned unk644;
 unsigned unk648;
 unsigned unk64c;
 unsigned unk650;
 unsigned unk654;
 unsigned unk658;
 unsigned unk65c;
 unsigned unk660;
 unsigned unk664;
 unsigned unk668;
 unsigned unk66c;
 unsigned unk670;
 unsigned unk674;
 unsigned unk678;
 unsigned unk67c;
 unsigned unk680;
 unsigned unk684;
 unsigned unk688;
 unsigned unk68c;
 unsigned unk690;
 unsigned unk694;
 unsigned unk698;
 unsigned unk69c;
 unsigned unk6a0;
 unsigned unk6a4;
 unsigned unk6a8;
 unsigned unk6ac;
 unsigned unk6b0;
 unsigned unk6b4;
 unsigned unk6b8;
 unsigned unk6bc;
 unsigned unk6c0;
 unsigned unk6c4;
 unsigned unk6c8;
 unsigned unk6cc;
 unsigned unk6d0;
 unsigned unk6d4;
 unsigned unk6d8;
 unsigned unk6dc;
 unsigned unk6e0;
 unsigned unk6e4;
 unsigned unk6e8;
 unsigned unk6ec;
 unsigned unk6f0;
 unsigned unk6f4;
 unsigned unk6f8;
 unsigned unk6fc;
 unsigned unk700;
 unsigned unk704;
 unsigned unk708;
 unsigned unk70c;
 unsigned unk710;
 unsigned unk714;
 unsigned unk718;
 unsigned unk71c;
 unsigned unk720;
 unsigned unk724;
 unsigned unk728;
 unsigned unk72c;
 unsigned unk730;
 unsigned unk734;
 unsigned unk738;
 unsigned unk73c;
 unsigned unk740;
 unsigned unk744;
 unsigned unk748;
 unsigned unk74c;
 unsigned unk750;
 unsigned unk754;
 unsigned unk758;
 unsigned unk75c;
 unsigned unk760;
 unsigned unk764;
 unsigned unk768;
 unsigned unk76c;
 unsigned unk770;
 unsigned unk774;
 unsigned unk778;
 unsigned unk77c;
 unsigned unk780;
 unsigned unk784;
 unsigned unk788;
 unsigned unk78c;
 unsigned unk790;
 unsigned unk794;
 unsigned unk798;
 unsigned unk79c;
 unsigned unk7a0;
 unsigned unk7a4;
 unsigned unk7a8;
 unsigned unk7ac;
 unsigned unk7b0;
 unsigned unk7b4;
 unsigned unk7b8;
 unsigned unk7bc;
 unsigned unk7c0;
 unsigned unk7c4;
 unsigned unk7c8;
 unsigned unk7cc;
 unsigned unk7d0;
 unsigned unk7d4;
 unsigned unk7d8;
 unsigned unk7dc;
 unsigned unk7e0;
 unsigned unk7e4;
 unsigned unk7e8;
 unsigned unk7ec;
 unsigned unk7f0;
 unsigned unk7f4;
 void* (__thiscall* resolve)(Owner*,void*,unsigned);
};
struct Owner {
 Table* table;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 void* result;
 bool FUN_0074a440(void*);
};
// pdb: LowProcess::SetTargetForPackage | LowProcess.obj | fnv360_1110_retail, objrun, medium
// pdb params: apActor
bool Owner::FUN_0074a440(void* input){
 unsigned mode=table->mode(this);
 Table* dispatch=table;
 void* value=dispatch->resolve(this,input,mode);
 dispatch->apply(this,value);
 if(result)return true;
 return false;
}
}
}   // namespace f3m_0074a440


namespace fnv_00cc0690 {
class hkMemoryAllocatorCC06
{
  public:
    virtual ~hkMemoryAllocatorCC06() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCC06
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCC06* m_pStreamAllocator;
    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750();
}

class FUN_00d46be0_class
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    void FUN_00d46be0() throw();
    ~FUN_00d46be0_class() throw()
    {
        FUN_00d46be0();
    }
    static void operator delete(void* p) throw()
    {
        hkRouterCC06::FUN_00c85750().heap().ReleaseBlock(p, sizeof(FUN_00d46be0_class));
    }
};

class hkReferencedObjectCC06
{
  public:
    virtual ~hkReferencedObjectCC06() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkRouterCC06::FUN_00c85750().heap().ReleaseBlock(p,
                                                         static_cast<hkReferencedObjectCC06*>(p)->m_usMemSizeAndFlags);
    }
};

class hkStreamCC06 : public hkReferencedObjectCC06
{
  public:
    FUN_00d46be0_class* m_stream;
    void* m_external;

    virtual ~hkStreamCC06() throw()
    {
        if (m_external == 0)
            delete m_stream;
    }
    hkStreamCC06* DestroyStream(unsigned int uiFlags) throw();
};

}  // namespace fnv_00cc0690

namespace fnv_00cc06f0 {
class hkMemoryAllocatorCC06;

struct hkMemoryRouterCC06
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorCC06* m_pTemp;
    hkMemoryAllocatorCC06* m_pStreamAllocator;
    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorCC06& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayCC06
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorCC06& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        reserve(hkRouterCC06::FUN_00c85750().heap(), n);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterCC06::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

class hkRefObjCC06
{
  public:
    virtual ~hkRefObjCC06() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCC06() throw()
    {
        m_sReferenceCount = 1;
    }
};

class FUN_00cc06f0 : public hkRefObjCC06
{
  public:
    hkArrayCC06<char>* m_buffer;
    int m_kRayStart;
    int m_flags;

    FUN_00cc06f0(hkArrayCC06<char>* buffer, int flags) throw();
    virtual ~FUN_00cc06f0() throw();
};

}  // namespace fnv_00cc06f0

class hkMemoryAllocatorCC07
{
  public:
    virtual ~hkMemoryAllocatorCC07() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCC07
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCC07* m_pStreamAllocator;
    hkMemoryAllocatorCC07& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC07 {
extern "C" hkMemoryRouterCC07& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayCC07
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterCC07::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
    ~hkArrayCC07() throw()
    {
        hkMemoryAllocatorCC07& kAlloc = hkRouterCC07::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkBaseObjectCC07
{
  public:
    virtual ~hkBaseObjectCC07() throw()
    {}
};

class FUN_00cc0780 : public hkBaseObjectCC07
{
  public:
    int unk04;
    hkArrayCC07<unsigned char>* m_buffer;
    int unk0C;
    int m_external;

    virtual ~FUN_00cc0780() throw();
};

// Destructor that deletes m_buffer unless m_external is set.
// @fnv 0x00cc0780
FUN_00cc0780::~FUN_00cc0780() throw()
{
    if (!m_external)
        delete m_buffer;
}

struct GlobalObject_0045cfe0
{
    ~GlobalObject_0045cfe0();
    int unk00;
};

class FUN_00cbf430 : public GlobalObject_0045cfe0
{
  public:
    ~FUN_00cbf430();
    void FUN_00cbf2f0();
};

// @fnv 0x00cbf430
FUN_00cbf430::~FUN_00cbf430()
{
    FUN_00cbf2f0();
}

class hkMemoryAllocatorD60B
{
  public:
    virtual ~hkMemoryAllocatorD60B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD60B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD60B* m_pStreamAllocator;

    hkMemoryAllocatorD60B& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD60B {
extern "C" hkMemoryRouterD60B& __cdecl FUN_00c85750() throw();
}

class hkRefObjD60B
{
  public:
    virtual ~hkRefObjD60B() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjD60B()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjD60B* b = static_cast<hkRefObjD60B*>(hkRouterD60B::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

struct NiBinaryStream;
typedef unsigned int(__cdecl* NiBinaryReadFn)(NiBinaryStream* stream, void* buffer, unsigned int bytes,
                                              unsigned int* componentSizes, unsigned int numComponents);

struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    NiBinaryReadFn m_pfnRead;
};

struct NiStream
{
    void* vtbl;
    unsigned int m_uiFormatVersion;
    char m_author[0xd8];
    char m_fileName[0x105];
    char m_bLittleEndian;
    short unk1e6;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_binaryStream;
};

struct HavokError
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Warning(int type, int id, const char* desc, const char* file, int line);
};

struct BoolType
{
    char m_cBooleanValue;
    BoolType(bool b) : m_cBooleanValue(b)
    {}
    BoolType(const BoolType& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
};

namespace MoppLoadStream {
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    __declspec(noinline) ~FUN_00cc00e0();
};
}

struct OStream : public MoppLoadStream::FUN_00cc00e0
{
    OStream(void* mem, int GetAllocationSize, BoolType isArray);
    OStream& operator<<(const char* s);
};

struct MoppCodeHeader
{
    int unk00;
    int unk04;
    int unk08;
    unsigned long m_data;
};

struct bhkMoppBvTreeShape
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual unsigned int slotA8();
    virtual void v2b();
    virtual void v2c();
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void FUN_00c87710(NiStream& stream);

    unsigned int FUN_00cc9f60(NiStream& stream);
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// Gets a size and buffer, reads binary data and warns for versions below 6, otherwise calls FUN_00c87710 and may byte-swap m_data.
// @f3 0x0094d790 (community match, verified in this file)
extern "C" char DAT_00e346a4[];
extern "C" char DAT_00e34698[];
extern "C" char DAT_00e7b274[];
extern "C" char DAT_00e3466c[];
extern "C" char DAT_00e7b230[];
extern HavokError* DAT_010f3364;
struct FUN_008f7f40_cls
{
    void __thiscall FUN_008f7f40(NiStream& stream);
};

// pdb: bhkMoppBvTreeShape::LoadCInfo | bhkMoppBvTreeShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: arStream
unsigned int bhkMoppBvTreeShape::FUN_00cc9f60(NiStream& stream)
{
    unsigned int size = slotA8();
    char allocated;
    MoppCodeHeader* buffer = slotB4(&allocated);

    if (stream.m_uiFormatVersion < 6)
    {
        NiBinaryStream* pBinaryStream = stream.m_binaryStream;
        pBinaryStream->m_uiStreamFlags += pBinaryStream->m_pfnRead(pBinaryStream, buffer, size -= 4, 0, 0);

        const char* pcFileName = stream.m_fileName;
        const char* pcAuthor = stream.m_author;
        if (!*pcAuthor)
        {
            pcAuthor = (const char*)&DAT_00e346a4;
        }

        char szWarning[512];
        OStream s(szWarning, sizeof(szWarning), true);
        s << (const char*)&DAT_00e34698 << pcFileName << (const char*)&DAT_00e7b274 << pcAuthor << (const char*)&DAT_00e3466c;
        DAT_010f3364->Warning(1, 0x234f2250, szWarning, (const char*)&DAT_00e7b230, 200);
    }
    else
    {
        ((FUN_008f7f40_cls*)this)->FUN_008f7f40(stream);
        if (stream.m_bLittleEndian != 1)
        {
            buffer->m_data = _byteswap_ulong(buffer->m_data);
        }
    }

    return size;
}


// @f3twin 0x009d88f0 of 0x00902310
struct F3Twin_009d88f0 : public CpuObject { void hkSubStreamWriter_flush() ; };
// pdb: hkSubStreamWriter::flush | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void F3Twin_009d88f0::hkSubStreamWriter_flush() 
{
    target->Invoke();
}
