// staging/blk_00cc0000_o2.cpp: CacheOwner_cls, Owner, Obj, hkVector4CDA and more (184 functions)
#include <math.h>
#include "f3_common.h"
// src/staging/blk_00cc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct hkReferencedObject {
    void __thiscall hkSweptTransformUtil_setTimeInformation();
};
extern "C" void* DAT_010c9314;
struct hkOstream {
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;
    hkOstream* __thiscall FUN_00cc00b0(void* owner);
};

extern "C" void __cdecl _delete(void* p, int flags);

void __cdecl FUN_00cc1520();

struct FUN_00cc1710_Class {
    FUN_00cc1710_Class* __thiscall FUN_00cc1710(int a);
};

// Calls FUN_00cc1520, then if bit 0 of a is set frees this with _delete, and returns this.
// @fnv 0x00cc1710
// pdb: bhkAabbPhantom::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00cc1710_Class* __thiscall FUN_00cc1710_Class::FUN_00cc1710(int aiFlags)
{
    FUN_00cc1520();
    if (aiFlags & 1)
        _delete(this, 24);
    return this;
}

struct NiStream { unsigned int ReadUnsignedInteger(); };
struct NiExtraData { void LoadBinary(NiStream&); };
struct FUN_00cc1970 : NiExtraData {
    void LoadBinary(NiStream& stream);
};
// @fnv 0x00cc1970
// pdb: NiPSysEmitterCtlr::LoadBinary | NiPSysEmitterCtlr.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void FUN_00cc1970::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    stream.ReadUnsignedInteger();
}

struct NiStream;

struct FUN_00a7b290_shell
{
    bool FUN_00a7b290(NiStream* apStream);
};

struct FUN_00cc1990_class : FUN_00a7b290_shell
{
    bool FUN_00cc1990(NiStream* apStream);
};

// @fnv 0x00cc1990
// pdb: bhkExtraData::RegisterStreamables | bhkExtraData.obj | fnv360_0721_beta, objrun_open, low
// pdb params: arStream
bool FUN_00cc1990_class::FUN_00cc1990(NiStream* apStream)
{
    bool bResult = FUN_00a7b290(apStream);

    unsigned int ItemUpdateArray = *(unsigned int*)((char*)this + 0x1c);
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        void* pObject = *(void**)(*(char**)((char*)this + 0x10) + i * 4);
        if (pObject)
        {
            void** ppVtbl = *(void***)pObject;
            ((void (__thiscall*)(void*, NiStream*))ppVtbl[21])(pObject, apStream);
        }
    }

    return bResult;
}

extern "C" void NiFreeAlias(void*);

void __cdecl FUN_00cc1e40();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00cc1f60_Class {
    void* __thiscall FUN_00cc1f60(bool flag);
};

// Calls FUN_00cc1e40, then deletes this (size 0x24) when flag bit 0 is set, and returns this.
// @fnv 0x00cc1f60
// pdb: NiShaderFactory::`scalar deleting destructor' | NiShaderFactory.obj | fnv360_0822_retail, caller_sim, low
void* __thiscall FUN_00cc1f60_Class::FUN_00cc1f60(bool flag)
{
    FUN_00cc1e40();
    if (flag & 1)
        operator delete(this, 0x24);
    return this;
}

void __cdecl FUN_00cc2ac0();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00cc2b40_class {
    FUN_00cc2b40_class* __thiscall FUN_00cc2b40(int flag);
};
// Calls FUN_00cc2ac0, frees this with operator delete when flag bit 0 is set, and returns this.
// @fnv 0x00cc2b40
// pdb: NiSkinPartition::`scalar deleting destructor' | NiSkinPartition.obj | fnv360_0822_retail, objrun, high
FUN_00cc2b40_class* __thiscall FUN_00cc2b40_class::FUN_00cc2b40(int flag)
{
    FUN_00cc2ac0();
    if (flag & 1)
        operator delete(this, 0x10);
    return this;
}

namespace fnv_00cc3a30 {
extern "C" void __cdecl _delete(void*, unsigned int);

void __cdecl FUN_00cc39b0();

struct GSGeometry
{
    GSGeometry();
    ~GSGeometry();
    GSGeometry* FUN_00cc3a30(int flags);
};

// Calls FUN_00cc39b0, deletes this with size 0x10 when flags has bit 0 set, and returns this.
// @fnv 0x00cc3a30
// pdb: bhkStiffSpringConstraint::`scalar deleting destructor' | bhkUtilFunctions.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: BSTObjectArena<struct `anonymous namespace'::ShapeShrinkInfo,struct BSTObjectArenaScrapAlloc,32>::~BSTObjectArena<struct `anonymous namespace'::ShapeShrinkInfo,struct BSTObjectArenaScrapAlloc,32>)
GSGeometry* GSGeometry::FUN_00cc3a30(int flags)
{
    FUN_00cc39b0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc3a30

namespace fnv_00cc5110 {
extern "C" void __cdecl _delete(void* p, size_t size);

void FUN_00cc5090();

struct FUN_00cc5110_Class {
    FUN_00cc5110_Class* FUN_00cc5110(int flags);
};

// Calls FUN_00cc5090, then deletes this with size 0x10 if flags has bit 0 set, and returns this.
// @fnv 0x00cc5110
FUN_00cc5110_Class* FUN_00cc5110_Class::FUN_00cc5110(int flags)
{
    FUN_00cc5090();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc5110

namespace fnv_00cc74e0 {
extern "C" void __cdecl operator delete(void*, unsigned int);

void __cdecl FUN_00cc7450();

struct FUN_00cc74e0_Class {
    void __thiscall FUN_00cc7450();
    void* __thiscall FUN_00cc74e0(int flags);
};

// Calls FUN_00cc7450, then deletes this with size 16 when flags has bit 0 set, and returns this.
// @fnv 0x00cc74e0
// pdb: bhkBallAndSocketConstraint::`scalar deleting destructor' | bhkRagdollTemplate.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void* __thiscall FUN_00cc74e0_Class::FUN_00cc74e0(int flags)
{
    FUN_00cc7450();
    if (flags & 1)
        operator delete(this, 16);
    return this;
}
}  // namespace fnv_00cc74e0

namespace fnv_00cc8500 {
extern "C" void __cdecl _delete(void*, unsigned int);

struct FUN_00cc8500_class {
    void FUN_00cc8480();
    void* FUN_00cc8500(int flags);
};

// Calls FUN_00cc8480, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00cc8500
void* FUN_00cc8500_class::FUN_00cc8500(int flags)
{
    FUN_00cc8480();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc8500

struct MemoryManager { void Deallocate(void*); };
struct MM { void Deallocate(void*); };
extern MM g_memoryManager;
extern int DAT_0108ffb4;
struct FUN_009ba5f0_shell { void SetChildObject(int); };
struct FUN_00cc8920_shell : FUN_009ba5f0_shell {
    int* m_p;
    FUN_00cc8920_shell* FUN_00cc8920(int a);
};
// Sets m_p to DAT_0108ffb4, calls SetChildObject(0), and if bit 0 of a is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00cc8920
FUN_00cc8920_shell* FUN_00cc8920_shell::FUN_00cc8920(int a)
{
    m_p = &DAT_0108ffb4;
    SetChildObject(0);
    if (a & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

namespace fnv_00cc8d80 {
void FUN_00d53220();

extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00cc8d80_class {
    FUN_00cc8d80_class* __thiscall FUN_00cc8d80(int);
};

// Calls FUN_00d53220, deletes this with size 0x10 when bit 0 of arg is set, and returns this.
// @fnv 0x00cc8d80
FUN_00cc8d80_class* __thiscall FUN_00cc8d80_class::FUN_00cc8d80(int arg)
{
    FUN_00d53220();
    if (arg & 1)
        operator delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc8d80

void __cdecl FUN_00cc8ce0();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00cc8da0_Class {
    FUN_00cc8da0_Class* FUN_00cc8da0(bool b);
};
// Calls FUN_00cc8ce0, then deletes this object with size 16 when b has bit 0 set, and returns this.
// @fnv 0x00cc8da0
// pdb: hkBreakableConstraintCinfo::SetWrappedConstraintData | bhkBreakableConstraint.obj | tesv_win, objrun_open, low
FUN_00cc8da0_Class* FUN_00cc8da0_Class::FUN_00cc8da0(bool b)
{
    FUN_00cc8ce0();
    if (b & 1)
        operator delete(this, 16);
    return this;
}

extern "C" void __cdecl _delete(void*, int);
extern "C" void __cdecl bhkConstraintChain();

void __cdecl FUN_00ccbc00();

void __cdecl _delete(void*, unsigned int);

struct FUN_00ccc420_class {
    void* __thiscall FUN_00ccc420(int);
};

// Calls FUN_00ccbc00, then if bit 0 of a is set frees this with size 0x18, and returns this.
// @fnv 0x00ccc420
// pdb: bhkSimpleShapePhantom::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
void* __thiscall FUN_00ccc420_class::FUN_00ccc420(int aiFlags)
{
    FUN_00ccbc00();
    if (aiFlags & 1)
        _delete(this, 0x18);
    return this;
}

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00ccc720_holder {
    void FUN_00ccc720();
    void* __thiscall DestroyHolder(int arg);
};

// Calls FUN_00ccc720, then frees this with operator delete when arg has bit 0 set, and returns this.
// @fnv 0x00cccfb0
void* __thiscall FUN_00ccc720_holder::DestroyHolder(int aiFlags)
{
    FUN_00ccc720();
    if (aiFlags & 1)
        operator delete(this, 0x10);
    return this;
}

void FUN_00ccd080();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00ccd150_cls {
    FUN_00ccd150_cls* __thiscall FUN_00ccd150(int flags);
};

// Calls FUN_00ccd080, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00ccd150
// pdb: bhkSphereShape::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00ccd150_cls* __thiscall FUN_00ccd150_cls::FUN_00ccd150(int flags)
{
    FUN_00ccd080();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

extern "C" void __cdecl _delete(void*, int);

struct FUN_00ccf870_class {
    int FUN_00ccf740();
    int FUN_00ccf870(int flags);
};

// @fnv 0x00ccf870
// pdb: bhkTriSampledHeightFieldBvTreeShape::`scalar deleting destructor' | CellMopp.obj | fnv360_0822_retail, vtable_prefix, high
int FUN_00ccf870_class::FUN_00ccf870(int flags)
{
    FUN_00ccf740();
    if (flags & 1)
        _delete((void*)this, 0x14);
    return (int)this;
}

extern float DAT_0104da48;

namespace fnv_00cd7f30 {
extern "C" void __cdecl _delete(void*, unsigned int);

void __cdecl FUN_00ccdbc0();

struct FUN_00cd7f30_class {
    FUN_00cd7f30_class* __thiscall FUN_00cd7f30(unsigned char flags);
};

// Calls FUN_00ccdbc0, then frees this with _delete when bit 0 of flags is set, and returns this.
// @fnv 0x00cd7f30
// pdb: bhkMultiSphereShape::`scalar deleting destructor' | BSTreeNode.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00cd7f30_class* __thiscall FUN_00cd7f30_class::FUN_00cd7f30(unsigned char flags)
{
    FUN_00ccdbc0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}
}  // namespace fnv_00cd7f30

struct FUN_00cdea00_cls {
    void __thiscall FUN_00cdea00(char param_2);
};

// @fnv 0x00cdea00
// pdb: hkpRagdollConstraintData::setConeLimitStabilization | hkpRagdollConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: enable
void __thiscall FUN_00cdea00_cls::FUN_00cdea00(char param_2)
{
    ((char*)this)[0x116] = (param_2 != 0) * 0x38;
}

struct FUN_00cdf250_class {
    void __thiscall FUN_00cd55b0(int* a, int b);
    void __thiscall FUN_00cdf250(int a);
};

// @fnv 0x00cdf250
// pdb: hkpRagdollConstraintData::setTarget | hkpRagdollConstraintData.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpRagdollConstraintData::setTargetRelativeOrientationOfBodies)
// pdb params: target_cbRca
void __thiscall FUN_00cdf250_class::FUN_00cdf250(int a)
{
    ((FUN_00cdf250_class*)((char*)this + 0xb0))->FUN_00cd55b0((int*)a, (int)((char*)this + 0x20));
}

namespace fnv_00cdf7a0 {
struct hkReferencedObject { void removeReference(); };
}  // namespace fnv_00cdf7a0

void __cdecl NiFreeAlias(void* p);
extern MM g_memoryManager;

extern int DAT_0126810c;
extern int DAT_01268238;
extern int DAT_01268208;
extern int DAT_012685a0;
extern int DAT_01030394;
extern int DAT_0103078c;
extern int DAT_010306b4;
extern int DAT_010c4694;
struct bhkRefObject {
    bhkRefObject* Initialize();
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned char m_bFlag;
};
struct FUN_00cc23c0_class {
    bhkRefObject* __thiscall InitializeRefObject();
};
// Calls Initialize, sets the vtable and clears data fields and a flag, incrementing four global counters along the way.
// @fnv 0x00cc23c0
// pdb: bhkCachingShapePhantom::bhkCachingShapePhantom | bhkCachingShapePhantom.obj | fnv360_0822_retail, objrun, medium
bhkRefObject* __thiscall FUN_00cc23c0_class::InitializeRefObject()
{
    bhkRefObject* self = (bhkRefObject*)this;
    self->Initialize();
    self->m_pVtable = (void*)&DAT_01030394;
    self->m_uiData1 = 0;
    self->m_uiData2 = 0;
    DAT_0126810c += 1;
    self->m_pVtable = (void*)&DAT_0103078c;
    DAT_01268238 += 1;
    self->m_pVtable = (void*)&DAT_010306b4;
    DAT_01268208 += 1;
    self->m_bFlag = 0;
    self->m_pVtable = (void*)&DAT_010c4694;
    DAT_012685a0 += 1;
    self->m_bFlag = 0;
    return self;
}

struct FUN_00cc3d30_class {
    void* m_p;
    void* m_pUnk0;
    void* m_pUnk1;
    void* m_pData;
    void __thiscall FreeDataIfRequested(bool flag);
};

// If flag is set, deallocates the block preceding m_pData and clears m_pData.
// @fnv 0x00cc3d30
// pdb: bhkBoxShape::KillCinfo | bhkBoxShape.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: hkpCharacterRigidBody::entityRemovedCallback)
// pdb params: abCreated
void __thiscall FUN_00cc3d30_class::FreeDataIfRequested(bool abFree)
{
    if (abFree) {
        if (m_pData)
            g_memoryManager.Deallocate((char*)m_pData - *(unsigned char*)((char*)m_pData - 1));
        m_pData = 0;
    }
}

struct bhkConstraint {
    virtual ~bhkConstraint();
    void FUN_00c876a0();
};
extern int DAT_0126860c;

namespace fnv_00cca950 {
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_01268660;
extern int DAT_01030bf4;
extern int DAT_01030b0c;
extern int DAT_01030a24;
extern int DAT_010ca3f4;
struct bhkRefObject {
    bhkRefObject* __thiscall Initialize();
};
struct FUN_00cca950_class {
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiValue2;
    unsigned int m_uiExtra2;
    FUN_00cca950_class* FUN_00cca950();
};
// @fnv 0x00cca950
// pdb: hkMemoryAllocator::_bufAlloc<hkVector4> | bhkCapsuleShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkCapsuleShape::bhkCapsuleShape)
// pdb params: reqNumInOut
FUN_00cca950_class* FUN_00cca950_class::FUN_00cca950()
{
    ((bhkRefObject*)this)->Initialize();
    m_uiValue2 = 0;
    m_uiExtra2 = 0;
    m_ppVirtualMethodTable = (void*)&DAT_01030bf4;
    ++DAT_012680f8;
    m_ppVirtualMethodTable = (void*)&DAT_01030b0c;
    ++DAT_01268274;
    m_ppVirtualMethodTable = (void*)&DAT_01030a24;
    ++DAT_01268250;
    m_ppVirtualMethodTable = (void*)&DAT_010ca3f4;
    ++DAT_01268660;
    return this;
}
}  // namespace fnv_00cca950

extern "C" void __cdecl bhkConstraintChain();
extern "C" void __cdecl _delete(void*, int);
extern int DAT_010ca4dc;
extern int DAT_0126866c;

namespace fnv_00ccd100 {
extern int DAT_01030a24;
extern int DAT_01030b0c;
extern int DAT_01030bf4;
extern int DAT_010ca834;
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_0126868c;
struct bhkRefObject {
    void* m_pVtable;
    int m_iRefCount;
    int m_iUnk;
    int m_iUnk2;
    int m_iUnk3;
    bhkRefObject* __thiscall Initialize();
    bhkRefObject* __thiscall FUN_00ccd100();
};
// Calls Initialize, zeroes m_iUnk2 and m_iUnk3, assigns four successive vtables and increments four counters, then returns this.
// @fnv 0x00ccd100
// pdb: bhkTriangleShape::bhkTriangleShape | bhkTriangleShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
bhkRefObject* __thiscall bhkRefObject::FUN_00ccd100()
{
    Initialize();
    m_iUnk2 = 0;
    m_iUnk3 = 0;
    m_pVtable = &DAT_01030bf4;
    ++DAT_012680f8;
    m_pVtable = &DAT_01030b0c;
    ++DAT_01268274;
    m_pVtable = &DAT_01030a24;
    ++DAT_01268250;
    m_pVtable = &DAT_010ca834;
    ++DAT_0126868c;
    return this;
}
}  // namespace fnv_00ccd100

namespace fnv_00cce990 {
struct bhkRefObject {
    void* m_ppVirtualMethodTable;
    int m_iRefCount;
    int m_iFlags;
    int m_iUnk;
    int m_iUnk2;
    bhkRefObject* Initialize();
};
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
extern int DAT_012686ac;
extern int DAT_01030bf4;
extern int DAT_01030b0c;
extern int DAT_01030a24;
extern int DAT_010caa0c;
struct FUN_00cce990_shell : bhkRefObject {
    bhkRefObject* FUN_00cce990();
};
// @fnv 0x00cce990
// pdb: bhkConvexVerticesShape::bhkConvexVerticesShape | bhkConvexVerticesShape.obj | fnv360_0822_retail, objopen_prop, low
bhkRefObject* FUN_00cce990_shell::FUN_00cce990()
{
    Initialize();
    m_iUnk = 0;
    m_iUnk2 = 0;
    m_ppVirtualMethodTable = (void*)&DAT_01030bf4;
    DAT_012680f8 += 1;
    m_ppVirtualMethodTable = (void*)&DAT_01030b0c;
    DAT_01268274 += 1;
    m_ppVirtualMethodTable = (void*)&DAT_01030a24;
    DAT_01268250 += 1;
    m_ppVirtualMethodTable = (void*)&DAT_010caa0c;
    DAT_012686ac += 1;
    return this;
}
}  // namespace fnv_00cce990

namespace fnv_00ccf7c0 {
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_012686c0;
extern int DAT_01030bf4;
extern int DAT_01030b0c;
extern int DAT_01030a24;
extern int DAT_010cabdc;
struct bhkRefObject {
    bhkRefObject* __thiscall Initialize();
    void* m_pVtable;
    int m_iRefCount;
    int m_iUnk;
    int m_iUnk2;
    int m_iUnk3;
};
struct FUN_00ccf7c0_class : bhkRefObject {
    FUN_00ccf7c0_class* FUN_00ccf7c0();
};
// Calls Initialize, zeroes m_iUnk2 and m_iUnk3, sets m_pVtable through four vtable assignments and increments four counters, then returns this.
// @fnv 0x00ccf7c0
// pdb: bhkConvexTransformShape::bhkConvexTransformShape | bhkConvexTransformShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00ccf7c0_class* FUN_00ccf7c0_class::FUN_00ccf7c0()
{
    Initialize();
    m_iUnk2 = 0;
    m_iUnk3 = 0;
    m_pVtable = (void*)&DAT_01030bf4;
    ++DAT_012680f8;
    m_pVtable = (void*)&DAT_01030b0c;
    ++DAT_01268274;
    m_pVtable = (void*)&DAT_01030a24;
    ++DAT_01268250;
    m_pVtable = (void*)&DAT_010cabdc;
    ++DAT_012686c0;
    return this;
}
}  // namespace fnv_00ccf7c0

void __cdecl IncRefCountAllEntries();
void __cdecl ReleaseAllNodes();
struct H_00c8c810 { void __thiscall FUN_00c84e50(bool); };
struct FUN_00ccfe20_class {
    void __thiscall FUN_00ccfe20(bool a);
};
// Calls IncRefCountAllEntries when a is true, otherwise ReleaseAllNodes, then forwards a to FUN_00c84e50 on this.
// @fnv 0x00ccfe20
// pdb: bhkConvexListShape::Link | bhkConvexListShape.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: abAttach
void __thiscall FUN_00ccfe20_class::FUN_00ccfe20(bool a)
{
    if (a)
        IncRefCountAllEntries();
    else
        ReleaseAllNodes();
    ((H_00c8c810*)this)->FUN_00c84e50(a);
}

// @fnv 0x00cde9f0
// pdb: hkpRagdollConstraintData::setMaxFrictionTorque | hkpRagdollConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(objrun_open), high
void __fastcall hkpRagdollConstraintData_setMaxFrictionTorque(void* self, int, float v)
{
    *(float*)((char*)self + 0xf8) = v;
}

void __stdcall SetContactNormal(int a, int b);
// @fnv 0x00cdea70
// pdb: hkpRagdollConstraintData::setPlaneMotor | hkpRagdollConstraintData.obj | tesv_win, call_seq, medium
void __stdcall FUN_00cdea70(int param_1)
{
    SetContactNormal(0, param_1);
}

void __stdcall SetContactNormal(int a, int b);
// @fnv 0x00cdea90
// pdb: hkpRagdollConstraintData::setTwistMotor | hkpRagdollConstraintData.obj | tesv_win, callee_sim, low
void __stdcall FUN_00cdea90(int param_1)
{
    SetContactNormal(2, param_1);
}

struct bhkLimitedHingeVector {
    void __thiscall FUN_004b4db0(const float*);
};
struct MyObj { void* m_kPointA; void* m_kPointB; void* m_iThirdValue; };
struct OutS {
    bhkLimitedHingeVector m_kPointA;
    bhkLimitedHingeVector m_kPointB;
    bhkLimitedHingeVector m_iThirdValue;
};
void __fastcall bhkConvexShape_CopyCinfo(MyObj* self, int, OutS* out);

namespace fnv_00ccb1b0 {
struct bhkLimitedHingeVector {
    void FUN_004b4db0(const float*);
};
struct MyObj {
    void FUN_00c84e20(void*);
};
}  // namespace fnv_00ccb1b0

struct FUN_00cce990 {
    void* m_p;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cce990();
    static void* __cdecl operator new(unsigned int size);
};
struct BSFadeNode {
    static void* __cdecl operator new(unsigned int size);
};
// Allocates and returns a new FUN_00cce990 object via its operator new.
// @fnv 0x00ccea70
// pdb: bhkConvexTransformShape::CreateObject | bhkConvexTransformShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00cce990* __stdcall FUN_00ccea70()
{
    return new FUN_00cce990;
}

extern int DAT_0102016c;
extern int DAT_010c5ef4;
extern int DAT_010c955c;
extern int DAT_01268154;
extern int DAT_01268194;
extern int DAT_012685ac;

struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base {
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    S_00cb79d0_Base();
};

struct DerivedStandin : A51BF0Base, S_00cb79d0_Base {
    unsigned int m_uiField3;

    DerivedStandin()
        : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c955c);
        DAT_012685ac += count;
    }
};

// Allocates and constructs a DerivedStandin object, returning its pointer.
// @fnv 0x00cc2bc0
void* CreateDerivedStandin()
{
    return new DerivedStandin;
}

struct FUN_00cc4180_Class {
    void __thiscall FUN_00cc4180();
    void* __thiscall FUN_00cc4200(int flag);
};
// @fnv 0x00cc4200
// pdb: WeaponObject::~WeaponObject | WeaponObject.obj | tesv_win, objrun_open, low
void* FUN_00cc4180_Class::FUN_00cc4200(int flag)
{
    FUN_00cc4180();
    if (flag & 1)
        _delete(this, 16);
    return this;
}

struct FUN_00cc47f0_t {
    void __thiscall FUN_00cc47f0();
    FUN_00cc47f0_t* __thiscall FUN_00cc48e0(int a);
};
// Calls FUN_00cc47f0, then deletes this with size 0x10 when bit 0 of a is set, and returns this.
// @fnv 0x00cc48e0
// pdb: bhkBinaryAction::`scalar deleting destructor' | bhkSpringAction.obj | fnv360_0822_retail, caller_sim, low
FUN_00cc47f0_t* __thiscall FUN_00cc47f0_t::FUN_00cc48e0(int aiFlags)
{
    FUN_00cc47f0();
    if (aiFlags & 1)
        _delete(this, 0x10);
    return this;
}

extern int DAT_010c99e0;

namespace fnv_00cc5130 {
extern int DAT_0108febc;
extern int DAT_01268188;
extern int DAT_010c9a14;
extern int DAT_012685e8;

struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct Derived5130 : S_00cb79d0_Base {
    int* m_p;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;

    Derived5130()
    {
        m_p = &DAT_0108febc;
        m_cByteAtOffset3 = 0;
        ++DAT_01268188;
        m_p = &DAT_010c9a14;
        ++DAT_012685e8;
    }
};

// Allocates and constructs a Derived5130 object, returning the new instance.
// @fnv 0x00cc5130
// pdb: bhkWheelConstraint::`scalar deleting destructor' | bhkWheelConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void* CreateDerived5130()
{
    return new Derived5130;
}
}  // namespace fnv_00cc5130

extern int DAT_010c9af0;

struct FUN_00cc5f10_Class {
    void __thiscall FUN_00cc5e60();
    FUN_00cc5f10_Class* __thiscall FUN_00cc5f10(unsigned int flag);
};

// @fnv 0x00cc5f10
FUN_00cc5f10_Class* FUN_00cc5f10_Class::FUN_00cc5f10(unsigned int flag)
{
    FUN_00cc5e60();
    if (flag & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_00cc60b0 {
extern int DAT_0108febc;
extern int DAT_010c9b0c;
extern int DAT_01268188;
extern int DAT_01268600;

struct A51BF0Base {
    void* m_pVtable;
    unsigned char m_ucUnknownByte[8];

    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct FUN_cc60b0_object : S_00cb79d0_Base {
    unsigned int m_uiCurrentValue;

    FUN_cc60b0_object();
};

FUN_cc60b0_object::FUN_cc60b0_object()
    : S_00cb79d0_Base()
{
    m_pVtable = &DAT_0108febc;
    m_uiCurrentValue = 0;
    ++DAT_01268188;
    m_pVtable = &DAT_010c9b0c;
    ++DAT_01268600;
}

// Allocates and constructs a new FUN_cc60b0_object, returning its pointer.
// @fnv 0x00cc60b0
// pdb: bhkRagdollLimitsConstraint::CreateObject | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void* __cdecl FUN_00cc60b0()
{
    return new FUN_cc60b0_object;
}
}  // namespace fnv_00cc60b0

struct NiPoint3 {
    float x;
    float y;
    float z;

    char* __thiscall FUN_00a59af0(char const* name);
};

typedef NiPoint3 NiPoint3_local;

struct hkVector4 {
    float x;
    float y;
    float z;
    float w;
};

struct StrArr {
    void* m_pVtable;
    void* m_pData;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned char m_pad000C;
    unsigned short m_usIncrement;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

char* __cdecl FUN_00a7d550(char const* name, float value);

namespace fnv_00cc7500 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

extern int DAT_0108febc;
extern int DAT_010c9c84;
extern int DAT_01268188;
extern int DAT_01268618;

struct S_00cb79d0_Base : A51BF0Base {
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    unsigned int m_uiField3;

    S_00cb79d0_Base();
};

struct Object_00cc7500 : S_00cb79d0_Base {
    Object_00cc7500()
    {
        m_pVtable = reinterpret_cast<void*>(&DAT_0108febc);
        m_uiField3 = 0;
        ++DAT_01268188;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c9c84);
        ++DAT_01268618;
    }
};

// Allocates and constructs a new Object_00cc7500, returning the new instance.
// @fnv 0x00cc7500
Object_00cc7500* FUN_00cc7500()
{
    return new Object_00cc7500;
}
}  // namespace fnv_00cc7500

extern "C" void __cdecl _delete(void* p, int flags);
extern "C" void __cdecl FUN_00d50020();
struct FUN_00cc7da0_shell {
    FUN_00cc7da0_shell* FUN_00cc7da0(int flags);
};
// Calls FUN_00d50020, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00cc7da0
FUN_00cc7da0_shell* FUN_00cc7da0_shell::FUN_00cc7da0(int flags)
{
    FUN_00d50020();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_00cc8520 {
extern int DAT_0108febc;
extern int DAT_010c9f74;
extern int DAT_01268188;
extern int DAT_01268630;

struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct Object_00cc8520 : S_00cb79d0_Base {
    int* m_pVtable;
    void* m_pA;
    void* m_pB;
    int m_iValue;

    Object_00cc8520()
        : m_pVtable(&DAT_0108febc),
          m_iValue(0)
    {
        ++DAT_01268188;
        m_pVtable = &DAT_010c9f74;
        ++DAT_01268630;
    }
};

// Allocates and constructs a new Object_00cc8520 instance, returning its pointer.
// @fnv 0x00cc8520
// pdb: bhkHingeLimitsConstraint::`scalar deleting destructor' | bhkHingeLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void* FUN_00cc8520()
{
    return new Object_00cc8520;
}
}  // namespace fnv_00cc8520

struct FUN_00cc94b0_Class {
    void __thiscall FreeSpawnedStorage();
};
struct FUN_00cc9540_Class : FUN_00cc94b0_Class {
    FUN_00cc9540_Class* __thiscall FUN_00cc9540(char flag);
};

// @fnv 0x00cc9540
// pdb: ExtraMapMarker::`scalar deleting destructor' | ExtraDataObjects.obj | fnv360_0822_debug, vtable, high
FUN_00cc9540_Class* FUN_00cc9540_Class::FUN_00cc9540(char flag)
{
    FUN_00cc94b0_Class::FreeSpawnedStorage();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00cc9e60 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base {
    void* m_pVtable;
    unsigned int m_kPointA;
    unsigned int m_kPointB;

    S_00cb79d0_Base();
};

extern int DAT_01030bf4;
extern int _DAT_0104dbac;
extern int DAT_010ca24c;
extern int DAT_012680f8;
extern int _DAT_012682cc;
extern int DAT_01268654;

struct bhkBvTreeShape : S_00cb79d0_Base {
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;

    static void* __cdecl operator new(unsigned int size)
    {
        return A51BF0Base::operator new(size);
    }

    bhkBvTreeShape()
    {
        m_iThirdValue = 0;
        m_iFourthElementInteger = 0;

        m_pVtable = reinterpret_cast<void*>(&DAT_01030bf4);
        ++DAT_012680f8;

        m_pVtable = reinterpret_cast<void*>(&_DAT_0104dbac);
        ++_DAT_012682cc;

        m_pVtable = reinterpret_cast<void*>(&DAT_010ca24c);
        ++DAT_01268654;
    }
};

// Allocates and constructs a new bhkBvTreeShape, returning the pointer.
// @fnv 0x00cc9e60
// pdb: bhkMoppBvTreeShape::CreateObject | bhkMoppBvTreeShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
bhkBvTreeShape* CreateBhkBvTreeShape()
{
    return new bhkBvTreeShape;
}
}  // namespace fnv_00cc9e60

struct FUN_00cca8d0_shell {
    void __thiscall FUN_00cca8d0();
};

struct FUN_00cca9a0_class : FUN_00cca8d0_shell {
    FUN_00cca8d0_shell* __thiscall DestroyOrDelete(int flags);
};

// @fnv 0x00cca9a0
// pdb: bhkConvexShape::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00cca8d0_shell* FUN_00cca9a0_class::DestroyOrDelete(int flags)
{
    FUN_00cca8d0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

// @fnv 0x00ccba20
// pdb: bhkExtendedMeshShapeData::IsEqual | bhkExtendedMeshShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: apObject
bool __fastcall FUN_00ccba20(char* p, int, char* q)
{
    return q == p;
}

namespace fnv_00ccbd70 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

extern int DAT_01030bf4;
extern int DAT_010c44e4;
extern int DAT_010ca744;
extern int DAT_012680f8;
extern int DAT_01268678;
extern int DAT_012686d0;

struct BD70_Object : S_00cb79d0_Base {
    void* m_pVtable;
    int m_unused04;
    int m_unused08;
    int m_field0C;
    int m_field10;
    int m_field14;

    BD70_Object()
    {
        m_pVtable = &DAT_01030bf4;
        m_field0C = 0;
        m_field10 = 0;
        ++DAT_012680f8;
        m_pVtable = &DAT_010c44e4;
        ++DAT_012686d0;
        m_pVtable = &DAT_010ca744;
        m_field14 = 0;
        ++DAT_01268678;
    }
};

// Allocates and constructs a BD70_Object, returning it as an S_00cb79d0_Base pointer.
// @fnv 0x00ccbd70
S_00cb79d0_Base* __cdecl CreateBD70Object()
{
    return new BD70_Object;
}
}  // namespace fnv_00ccbd70

struct NiStreamResolveLinkID
{
    void* __thiscall DeserializeObject();
};

struct NiStreamVirtual
{
    virtual void* m_pVtable00();
    virtual void* m_pVtable04();
    virtual void* m_pVtable08();
    virtual void* m_pVtable0C();
    virtual void* m_pVtable10();
    virtual void* m_pVtable14();
    virtual void* m_pVtable18();
    virtual void* m_pVtable1C();
    virtual void* m_pVtable20();
    virtual void* m_pVtable24();
    virtual void m_pVtable28(void*);
};

struct FUN_00ccf570_class
{
    void __thiscall FUN_00c9fbc0(NiStream* stream);
    void __thiscall bhkConvexSweepShape_LoadBinary(NiStream* stream);
};

// @fnv 0x00ccf570
// pdb: bhkConvexSweepShape::LoadBinary | bhkConvexSweepShape.obj | fnv360_0822_retail, caller_sim + bridge(vtable_prefix|caller_sim) + skyrim(caller_sim), high
void FUN_00ccf570_class::bhkConvexSweepShape_LoadBinary(NiStream* stream)
{
    void* resolved = reinterpret_cast<NiStreamResolveLinkID*>(stream)->DeserializeObject();
    FUN_00c9fbc0(stream);
    reinterpret_cast<NiStreamVirtual*>(stream)->m_pVtable28(resolved);
}

extern "C" void __cdecl _delete(void* p, int flags);

struct FUN_00ccf5b0_shell {
    void __thiscall FUN_00ccf4f0();
    FUN_00ccf5b0_shell* __thiscall FUN_00ccf5b0(bool flag);
};

// Calls FUN_00ccf4f0, then frees this with _delete when flag bit 0 is set, and returns this.
// @fnv 0x00ccf5b0
// pdb: bhkBvTreeShape::`scalar deleting destructor' | CellMopp.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00ccf5b0_shell* __thiscall FUN_00ccf5b0_shell::FUN_00ccf5b0(bool abFree)
{
    FUN_00ccf4f0();
    if (abFree & 1)
        _delete(this, 0x14);
    return this;
}

namespace fnv_00cd2fd0 {
struct StrArr {
    unsigned char m_auiShapeKeys[8];
    unsigned short m_pRayCursor;
    unsigned short m_iElementCount;
    unsigned short m_unknown;
    unsigned short m_growth;

    void __thiscall SetSize(unsigned int size);
    void __thiscall SetAt(unsigned int index, char*& value);
};

extern __declspec(thread) unsigned char DAT_00cd2fd0[0x2b8];

struct TLSGuard {
    unsigned int m_oldValue;

    TLSGuard()
    {
        m_oldValue = *reinterpret_cast<unsigned int*>(DAT_00cd2fd0 + 0x2b4);
        *reinterpret_cast<unsigned int*>(DAT_00cd2fd0 + 0x2b4) = 0x10;
    }

    ~TLSGuard()
    {
        *reinterpret_cast<unsigned int*>(DAT_00cd2fd0 + 0x2b4) = m_oldValue;
    }
};

}  // namespace fnv_00cd2fd0

extern int DAT_010cb3c4;
struct FUN_00cd44c0_cls {
    int m_vft;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    FUN_00cd44c0_cls* FUN_00cd44c0();
};
// @fnv 0x00cd44c0
// pdb: bhkCharacterStateSwimming::bhkCharacterStateSwimming | bhkCharacterStateSwimming.obj | fnv360_0822_retail, call_gap_sim, low
FUN_00cd44c0_cls* FUN_00cd44c0_cls::FUN_00cd44c0()
{
    m_kPointB = 1;
    m_vft = (int)&DAT_010cb3c4;
    return this;
}

extern int DAT_010cb3f0;
struct FUN_00cd47e0_t {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned char m_bFlag;
    unsigned short m_usFlags;
    FUN_00cd47e0_t();
};
// @fnv 0x00cd47e0
// pdb: bhkCharacterStateOnGround::bhkCharacterStateOnGround | bhkCharacterStateOnGround.obj | fnv360_0822_retail, callee_sim, low
FUN_00cd47e0_t::FUN_00cd47e0_t()
{
    *(unsigned short*)((char*)this + 6) = 1;
    m_pVtable = (void*)&DAT_010cb3f0;
    m_bFlag = 1;
}

// @fnv 0x00cdeab0
// pdb: hkpRagdollConstraintData::setPlaneMotor | hkpRagdollConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkpRagdollConstraintData::setConeMotor)
// pdb params: motor
void __stdcall FUN_00cdeab0(int a)
{
    SetContactNormal(1, a);
}

class CC1AD0BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CC1AD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CC1AD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class CC1AD0Object;

class CC1AD0Stream {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(CC1AD0Object* pkObject);

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    CC1AD0BinaryStream* m_pBackingStream;
};

template <class T>
inline void CC1AD0BinaryStreamSave(CC1AD0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CC1AD0SaveBinary(CC1AD0Stream& kStream, const T& value) {
    CC1AD0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class CC1AD0ExtraData {
public:
    void SaveBinary(CC1AD0Stream& kStream);

    int unk00; int unk04; int unk08; int unk0C;
};

class CC1AD0ListExtra : public CC1AD0ExtraData {
public:
    CC1AD0Object** m_ppkObjects;
    int unk14;
    int unk18;
    unsigned int m_uiCount;

    void FUN_00cc1ad0(CC1AD0Stream& kStream);
};

// SaveBinary
// Saves the base extra data, writes m_uiCount, then saves a link ID for each non-null object in m_ppkObjects.
// @fnv 0x00cc1ad0
// pdb: bhkRagdollTemplate::SaveBinary | bhkRagdollTemplate.obj | fnv360_0822_retail, caller_sim, low, conflict (bridge: bhkExtraData::SaveBinary)
// pdb params: arStream
void CC1AD0ListExtra::FUN_00cc1ad0(CC1AD0Stream& kStream) {
    CC1AD0ExtraData::SaveBinary(kStream);
    unsigned int ItemUpdateArray = m_uiCount;
    CC1AD0SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        CC1AD0Object* pkObject = m_ppkObjects[i];
        if (pkObject)
            kStream.SaveLinkID(pkObject);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct ArrayRefObject {
    virtual void vf0();
    virtual void DeleteThis();
    long volatile refs;
    void DecRef() { if (InterlockedDecrement(&refs) == 0) DeleteThis(); }
    void AcquireReference() { InterlockedIncrement(&refs); }
};
struct RefBool { bool value; RefBool(bool v): value(v) {} operator bool() const { return value; } };
struct ArrayRefPtr {
    ArrayRefObject* ptr;
    ArrayRefPtr() : ptr(0) {}
    ~ArrayRefPtr() { if (ptr) ptr->DecRef(); }
    RefBool operator!=(ArrayRefObject* other) const { return ptr != other; }
    ArrayRefPtr& operator=(const ArrayRefPtr& rhs) {
        if (ptr != rhs.ptr) {
            if (ptr) ptr->DecRef();
            ptr = rhs.ptr;
            if (ptr) ptr->AcquireReference();
        }
        return *this;
    }
};
void* __cdecl FUN_00aa1070(unsigned);
void __cdecl FUN_00aa10f0(void*);
struct ReferenceArray {
    void* vtable;
    ArrayRefPtr* data;
    unsigned capacity, used, live;
    void Resize(unsigned);
};
// Resizes the reference array to n slots: releases entries past n, reallocates storage, copies live entries and default-initialises the rest.
// @fnv 0x00cc1b40
// pdb: NiTLargeArray<NiPointer<NiTimeController>,NiTMallocInterface<NiPointer<NiTimeController> > >::SetSize | bhkExtraData.obj | fnv360_0822_retail, call_seq, high
// pdb params: uiMaxSize
void ReferenceArray::Resize(unsigned uiCapacity) {
    if (uiCapacity != capacity) {
        if (uiCapacity < used) {
            for (unsigned i = uiCapacity; i < used; ++i) {
                if (data[i] != (ArrayRefObject*)0) { data[i] = ArrayRefPtr(); --live; }
            }
            used = uiCapacity;
        }
        ArrayRefPtr* old = data;
        capacity = uiCapacity;
        if (uiCapacity > 0) {
            data = (ArrayRefPtr*)FUN_00aa1070(uiCapacity * sizeof(ArrayRefPtr));
            for (unsigned i = 0; i < used; ++i) data[i] = old[i];
            for (unsigned i = used; i < capacity; ++i) data[i] = ArrayRefPtr();
        } else data = 0;
        FUN_00aa10f0(old);
    }
}

extern int DAT_01268598;

// @fnv 0x00cc1e30
int __cdecl FUN_00cc1e30() {
    return reinterpret_cast<int>(&DAT_01268598);
}

struct FUN_00cc1e40_tls {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00cc1e40_tls g_tls_00cc1e40;

struct TlsFlagGuard_00cc1e40 {
    unsigned int m_saved;
    TlsFlagGuard_00cc1e40() {
        m_saved = g_tls_00cc1e40.m_2b4;
        g_tls_00cc1e40.m_2b4 = 0x10;
    }
    ~TlsFlagGuard_00cc1e40() {
        g_tls_00cc1e40.m_2b4 = m_saved;
    }
};

void __cdecl FUN_00aa10f0(void* apMemory);

struct Member_00cc1e40 {
    virtual void unk00();
    void* m_04;
    void Destroy();
    ~Member_00cc1e40() {
        void* p = m_04;
        FUN_00aa10f0(p);
    }
};

struct FUN_00cc1d80_object {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    FUN_00cc1d80_object();
    static void* __cdecl operator new(unsigned int bytes);
    void __thiscall AssignFixedString(void* value);
};
extern "C" char DAT_011f49e0;
// @fnv 0x00cc1ef0
FUN_00cc1d80_object* __cdecl CreateObjectWithGlobal()
{
    FUN_00cc1d80_object* value = new FUN_00cc1d80_object;
    value->AssignFixedString(&DAT_011f49e0);
    return value;
}

extern __declspec(thread) int g_iCC1F80AllocTag;

struct BCC1F80AllocTagScope {
    int m_iSaved;

    BCC1F80AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC1F80AllocTag;
        g_iCC1F80AllocTag = aiAllocationTag;
    }
    ~BCC1F80AllocTagScope() { g_iCC1F80AllocTag = m_iSaved; }
};

class BCC1F80StringArray {
public:
    virtual ~BCC1F80StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

extern "C" __declspec(thread) unsigned int g_tlsMode;
struct ThreadModeGuard {
    unsigned int previous;
    ThreadModeGuard() : previous(g_tlsMode) { g_tlsMode = 16; }
    ~ThreadModeGuard() { g_tlsMode = previous; }
};

void* FUN_00aa13e0(unsigned int size);

struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};

extern __declspec(thread) ThreadHeapState g_threadHeapState;

struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard() { saved = g_threadHeapState.m_2b4; g_threadHeapState.m_2b4 = 0x10; }
    ~TlsHeapGuard() { g_threadHeapState.m_2b4 = saved; }
};

class SpawnedThing
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    static void* operator new(unsigned int size);
    SpawnedThing();
};

void* SpawnedThing::operator new(unsigned int size)
{
    return FUN_00aa13e0(size);
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct RefObject24_b9018 {
    char m00[0x18];
    RefObject24_b9018();
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
};

// Allocates and constructs a RefObject24_b9018 via its operator new and returns the pointer.
// @fnv 0x00cc2410
// pdb: bhkCachingShapePhantom::CreateObject | bhkCachingShapePhantom.obj | fnv360_0822_retail, objrun, medium
RefObject24_b9018* CreateRefObject24() {
    return new RefObject24_b9018();
}

struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_2b4;
};
extern __declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t(int saved)
    {
        m_saved = saved;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void FUN_00c876f0();
void FUN_00c87700();

class SpawnedObject_t
{
public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    void* operator new(unsigned int size);
    SpawnedObject_t();
};


struct ThreadTlsBlock {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadTlsBlock g_tls;

struct TlsFlagGuard {
    unsigned int m_saved;
    TlsFlagGuard() { m_saved = g_tls.m_2b4; g_tls.m_2b4 = 0x10; }
    ~TlsFlagGuard() { g_tls.m_2b4 = m_saved; }
};

class FUN_00cc2a00_alloc {
public:
    unsigned char* Alloc(unsigned int size);
};
extern FUN_00cc2a00_alloc DAT_011f6238;

extern int DAT_012685b0;

// @fnv 0x00cc2b30
// pdb: bhkBallAndSocketConstraint::GetRTTI | bhkRagdollTemplate.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00cc2b30()
{
    return &DAT_012685b0;
}

namespace fnv_00cc2c60 {
extern "C" void __cdecl FUN_00c876f0();
extern "C" void __cdecl FUN_00c87700();
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

extern unsigned int g_ctorCount1;
extern unsigned int g_ctorCount2;
extern unsigned int g_ctorCount3;

class NodeRoot_cls {
public:
    NodeRoot_cls();
    virtual void r00();
};

class NodeA_cls : public NodeRoot_cls {
public:
    int unk04;
    int unk08;
    volatile int m_0c;
    NodeA_cls() : NodeRoot_cls() {
        m_0c = 0;
        g_ctorCount1 += 1;
    }
    virtual void a00();
};

class NodeB_cls : public NodeA_cls {
public:
    NodeB_cls() : NodeA_cls() {
        g_ctorCount2++;
    }
    virtual void b00();
};

class NodeC_cls : public NodeB_cls {
public:
    NodeC_cls() : NodeB_cls() {
        g_ctorCount3++;
    }
    virtual void c00();
    static void* operator new(unsigned int size) throw() {
        return FUN_00aa13e0(size);
    }
};

}  // namespace fnv_00cc2c60

struct Col4 { float r, g, b, a; Col4& operator*=(float s) { r *= s; g *= s; b *= s; a *= s; return *this; } };
struct S_00cc2d20_result {
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    Col4 m_kPointA;
    Col4 m_kPointB;
};

struct S_00cc2d20_argument {
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    float m_f10;
};

struct S_00cc2d20_class {
    virtual void* v00(char*) { return 0; }
    virtual void* v01(char*) { return 0; }
    virtual void* v02(char*) { return 0; }
    virtual void* v03(char*) { return 0; }
    virtual void* v04(char*) { return 0; }
    virtual void* v05(char*) { return 0; }
    virtual void* v06(char*) { return 0; }
    virtual void* v07(char*) { return 0; }
    virtual void* v08(char*) { return 0; }
    virtual void* v09(char*) { return 0; }
    virtual void* v10(char*) { return 0; }
    virtual void* v11(char*) { return 0; }
    virtual void* v12(char*) { return 0; }
    virtual void* v13(char*) { return 0; }
    virtual void* v14(char*) { return 0; }
    virtual void* v15(char*) { return 0; }
    virtual void* v16(char*) { return 0; }
    virtual void* v17(char*) { return 0; }
    virtual void* v18(char*) { return 0; }
    virtual void* v19(char*) { return 0; }
    virtual void* v20(char*) { return 0; }
    virtual void* v21(char*) { return 0; }
    virtual void* v22(char*) { return 0; }
    virtual void* v23(char*) { return 0; }
    virtual void* v24(char*) { return 0; }
    virtual void* v25(char*) { return 0; }
    virtual void* v26(char*) { return 0; }
    virtual void* v27(char*) { return 0; }
    virtual void* v28(char*) { return 0; }
    virtual void* v29(char*) { return 0; }
    virtual void* v30(char*) { return 0; }
    virtual void* v31(char*) { return 0; }
    virtual void* v32(char*) { return 0; }
    virtual void* v33(char*) { return 0; }
    virtual void* v34(char*) { return 0; }
    virtual void* v35(char*) { return 0; }
    virtual void* v36(char*) { return 0; }
    virtual void* v37(char*) { return 0; }
    virtual void* v38(char*) { return 0; }
    virtual void* v39(char*) { return 0; }
    virtual void* v40(char*) { return 0; }
    virtual void* v41(char*) { return 0; }
    virtual void* v42(char*) { return 0; }
    virtual void* v43(char*) { return 0; }
    virtual void* v44(char*) { return 0; }
    virtual S_00cc2d20_result* v45(char*) { return 0; }

    void __thiscall ClonePhysicsData(void* arg1, void* arg2);
    void __thiscall FUN_00cc2d20(
        void* arg1,
        S_00cc2d20_argument* arg2);
};

extern float DAT_0101e2bc;

typedef unsigned int CC2F90size_t;

extern __declspec(thread) int g_CC2F90AllocTag;

struct CC2F90AllocTagScope {
    int m_iSaved;

    CC2F90AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CC2F90AllocTag;
        g_CC2F90AllocTag = aiAllocationTag;
    }
    ~CC2F90AllocTagScope() { g_CC2F90AllocTag = m_iSaved; }
};

struct CC2F90Child {
    CC2F90Child();

    static void* operator new(CC2F90size_t, void* pvMem) { return pvMem; }
};

extern int DAT_012685b8;

struct FUN_00cc3270_base {
    virtual ~FUN_00cc3270_base();
};

struct FUN_00cc3270 : FUN_00cc3270_base {
    virtual ~FUN_00cc3270();
};

// @fnv 0x00cc3270
FUN_00cc3270::~FUN_00cc3270()
{
    ((bhkConstraint*)this)->FUN_00c876a0();
    --DAT_012685b8;
}

extern int DAT_012685bc;

// @fnv 0x00cc32e0
// pdb: bhkRagdollConstraint::GetRTTI | bhkRagdollTemplate.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
void* __cdecl bhkRagdollConstraint_GetRTTI()
{
    return &DAT_012685bc;
}

// @fnv 0x00cc32f0
// pdb: BGSSaveLoadManager::GetMajorVersion | BGSSaveLoadManager.obj | fnv360_0822_retail, call_gap_sim, low
int __cdecl FUN_00cc32f0() {
    return 0x30;
}

void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct S_00cc3300 {
    int unk00, unk04, unk08, unk0c;
    void FUN_00cc3270();
    S_00cc3300* FUN_00cc3300(unsigned int flags);
};
// @fnv 0x00cc3300
// pdb: BSAnimNotes::`scalar deleting destructor' | BSAnimNote.obj | fnv360_0822_retail, objrun, high
S_00cc3300* S_00cc3300::FUN_00cc3300(unsigned int flags)
{
    FUN_00cc3270();
    if (flags & 1)
        FUN_00aa1460(this, 0x10);
    return this;
}

extern float DAT_01267e30;

struct CC3320Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_afPivot[4];
    float m_fMinimum;
    float m_fMaximum;
};

struct CC3320Vector {
    void FUN_004b4db0(const float* pfValues);
};

struct CC3320Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC3320Vector m_kPivot;
    int unk14;
    int unk18;
    int unk1C;
    float m_fMinimum;
    float m_fMaximum;
    bool m_bStreamFlag;
};

class CC3320Base {
public:
    void GetInfo(CC3320Info* pkInfo);
};

class CC3320Constraint : public CC3320Base {
public:
    int unk00;
    int unk04;
    CC3320Data* m_pUserData;

    static const float* GetPivot(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_afPivot : &DAT_01267e30;
    }
    static float GetMax(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMaximum : 0.0f;
    }
    static float GetMin(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMinimum : 0.0f;
    }

    void FUN_00cc3320(CC3320Info* pkInfo);
};

namespace fnv_00cc33a0 {
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_010c9634;
extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;

struct PhysicsElement {
    void* vtable;
    unsigned int referenceCount;
    unsigned int flags;
    unsigned int payload;

    void __thiscall FUN_00c87c30();

    static void* __cdecl operator new(unsigned int size) {
        return FUN_00aa13e0(size);
    }
    static void __cdecl operator delete(void*);

    PhysicsElement() {
        FUN_00c87c30();
        vtable = &DAT_0102016c;
        payload = 0;
        ++DAT_01268154;
        vtable = &DAT_0102009c;
        ++DAT_01268118;
        vtable = &DAT_010c9634;
        ++DAT_012685b8;
    }
};

// Allocates and constructs a new PhysicsElement, returning the pointer.
// @fnv 0x00cc33a0
// pdb: bhkMotorAction::CopyCinfo | bhkMotorAction.obj | fnv360_0721_beta, objrun, medium
// pdb params: arInfo
PhysicsElement* __cdecl CreatePhysicsElement() {
    return new PhysicsElement();
}
}  // namespace fnv_00cc33a0

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

struct PacketReader {
    void __thiscall FUN_00c868b0(void* context);
    void __thiscall ReadPacketWithByteSwap(void* context);
};
typedef unsigned int* (__thiscall *GetPacketBlock)(PacketReader*, unsigned char*);

namespace fnv_00cc3630 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct HeapAllocator_t
{
    char* Alloc(unsigned int size);
};
extern HeapAllocator_t DAT_011f6238;
extern unsigned int DAT_0126fd98;

struct AlignedObj_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    unsigned char unk28;
};

class CacheOwner_cls
{
public:
    int unk00;
    int unk04;
    int m_08;
    AlignedObj_t* m_0c;
    void FUN_00cc3320(AlignedObj_t* p);
    AlignedObj_t* FUN_00cc3630(bool* out);
};

}  // namespace fnv_00cc3630

extern int DAT_012685c4;

class FUN_00cc39b0_base {
public:
    virtual void unk00();
    ~FUN_00cc39b0_base();
    int unk04;
};

class FUN_00cc39b0 : public FUN_00cc39b0_base {
public:
    virtual ~FUN_00cc39b0();
    void unk08();
};

// Calls unk08 on this object and decrements the global counter DAT_012685c4.
// @fnv 0x00cc39b0
FUN_00cc39b0::~FUN_00cc39b0()
{
    this->unk08();
    DAT_012685c4--;
}

extern int DAT_012685c8;

// @fnv 0x00cc3a20
// pdb: bhkRagdollTemplateData::GetRTTI | bhkRagdollTemplate.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(udata), high
void* __cdecl bhkRagdollTemplateData_GetRTTI()
{
    return &DAT_012685c8;
}

extern int DAT_010c970c;
extern int DAT_012685c4;

struct DerivedStandin2 : A51BF0Base, S_00cb79d0_Base {
    unsigned int m_uiField3;

    DerivedStandin2()
        : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c970c);
        DAT_012685c4 += count;
    }
};

// Allocates and constructs a DerivedStandin2 object, returning its pointer.
// @fnv 0x00cc3b30
// pdb: bhkDashpotAction::CreateObject | bhkDashpotAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void* CreateDerivedStandin2() {
    return new DerivedStandin2();
}

namespace fnv_00cc3e50 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct HeapAllocator_t
{
    char* Alloc(unsigned int size);
};
extern HeapAllocator_t DAT_011f6238;
extern unsigned int DAT_0126fd98;
extern float DAT_0101e2bc;
extern float DAT_01013ea4;

struct AlignedObj_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
};

class CacheOwner_cls
{
public:
    int unk00;
    int unk04;
    int m_08;
    AlignedObj_t* m_0c;
    void FUN_00cc3a50(AlignedObj_t* p);
    AlignedObj_t* FUN_00cc3e50(bool* out);
};

}  // namespace fnv_00cc3e50

extern int DAT_012685d4;

// @fnv 0x00cc41f0
// pdb: bhkRagdollTemplate::GetRTTI | bhkRagdollTemplate.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(udata), high
int* __cdecl bhkRagdollTemplate_GetRTTI()
{
    return &DAT_012685d4;
}

struct FUN_00cc4220_source {
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
};

struct FUN_00cc4220_output {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
};

struct FUN_00cc4220_class {
    void* unk00;
    void* unk04;
    FUN_00cc4220_source* m_p;

    void __thiscall WriteScriptTargetInfo(void* p);
    void __thiscall FUN_00cc4220(void* p);
};

extern "C" float DAT_012683b0[4];

// Calls WriteScriptTargetInfo, then copies m_f34, the four floats at m_f20 and m_f30 from m_p into the output, using defaults when m_p is null.
// @fnv 0x00cc4220
// pdb: bhkAngularDashpotAction::CopyCinfo | bhkAngularDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: arInfo
void __thiscall FUN_00cc4220_class::FUN_00cc4220(void* apOutput)
{
    FUN_00cc4220_output* out = static_cast<FUN_00cc4220_output*>(apOutput);

    this->WriteScriptTargetInfo(apOutput);

    float value = (this != 0 && this->m_p != 0)
        ? this->m_p->m_f34
        : 0.0f;
    out->m_f24 = value;

    const float* values = (this != 0 && this->m_p != 0)
        ? &this->m_p->m_f20
        : DAT_012683b0;

    out->m_f10 = values[0];
    out->m_f14 = values[1];
    out->m_f18 = values[2];
    out->m_f1c = values[3];

    float position = (this != 0 && this->m_p != 0)
        ? this->m_p->m_f30
        : 0.0f;
    out->m_f20 = position;
}

namespace fnv_00cc4340 {
extern "C" void __cdecl FUN_00c876f0();
extern "C" void __cdecl FUN_00c87700();
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

extern unsigned int g_ctorCount1;
extern unsigned int g_ctorCount2;
extern unsigned int g_ctorCount3;

class NodeRoot_cls {
public:
    NodeRoot_cls();
    virtual void r00();
};

class NodeA_cls : public NodeRoot_cls {
public:
    int unk04;
    int unk08;
    volatile int m_0c;
    NodeA_cls() : NodeRoot_cls() {
        m_0c = 0;
        g_ctorCount1 += 1;
    }
    virtual void a00();
};

class NodeB_cls : public NodeA_cls {
public:
    NodeB_cls() : NodeA_cls() {
        g_ctorCount2++;
    }
    virtual void b00();
};

class NodeC_cls : public NodeB_cls {
public:
    NodeC_cls() : NodeB_cls() {
        g_ctorCount3++;
    }
    virtual void c00();
    static void* operator new(unsigned int size) throw() {
        return FUN_00aa13e0(size);
    }
};

}  // namespace fnv_00cc4340

namespace fnv_00cc4500 {
extern "C" float DAT_0101e2bc;
extern "C" float DAT_01013ea4;
extern "C" float DAT_012683b0;

}  // namespace fnv_00cc4500

extern int g_012685e0;

// @fnv 0x00cc4860
// pdb: hkVersionUtil::getCurrentVersion | hkVersionUtil.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00cc4860()
{
    return &g_012685e0;
}

extern int g_ctorCountA;
extern int g_ctorCountD;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct OwnerBase {
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw() {
        return FUN_00aa13e0(size);
    }
};

struct ChainA_cls : public OwnerBase {
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_cls() {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};

struct SpawnedObject : public ChainA_cls {
    virtual void unkD2();
    SpawnedObject() {
        g_ctorCountD += 1;
    }
};

// Allocates and constructs a new SpawnedObject via its operator new and returns the pointer.
// @fnv 0x00cc4900
SpawnedObject* FUN_00cc4900() {
    return new SpawnedObject();
}

struct S_00cc4b90_Tls {
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
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00cc4b90_Tls DAT_tls;

struct S_00cc4b90_Ctx {
    int saved;
    __forceinline S_00cc4b90_Ctx(int c) { saved = DAT_tls.ctx; DAT_tls.ctx = c; }
    __forceinline ~S_00cc4b90_Ctx() { DAT_tls.ctx = saved; }
};
struct S_00cc4b90_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00cc4b90_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00cc4b90_Alloc* unk10;
    S_00cc4b90_Alloc& heap() { return *unk10; }
};
S_00cc4b90_Router* FUN_00c85750() throw();
extern float DAT_01017b78;
struct S_00cc4b90_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00cc4b90_RefObj();
    void* operator new(unsigned int n) {
        S_00cc4b90_RefObj* b = static_cast<S_00cc4b90_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
};
struct S_00cc4b90_Base : S_00cc4b90_RefObj {
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00cc4b90_Base(int a);
};
struct __declspec(novtable) S_00cc4b90_Mid : S_00cc4b90_Base {
    float f20;
    S_00cc4b90_Mid() : S_00cc4b90_Base(0), f20(DAT_01017b78) {}
};
struct S_00cc4b90_Obj : S_00cc4b90_Mid {
    unsigned char b24;
    unsigned char b25;
    S_00cc4b90_Obj() { b24 = 0; b25 = 0; }
};

namespace fnv_00cc4c60 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;
extern int g_ctrA;
extern int g_ctrD;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void FUN_00c876f0();
void FUN_00c87700();
void* __cdecl FUN_00aa13e0(unsigned int size);

class OwnerBase_t
{
public:
    OwnerBase_t();
    virtual void unkB0();
    virtual ~OwnerBase_t();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

class ChainA_t : public OwnerBase_t
{
public:
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_t()
    {
        m_0c = 0;
        g_ctrA += 1;
    }
};

class SpawnedObject_t : public ChainA_t
{
public:
    virtual void unkD2();
    SpawnedObject_t()
    {
        g_ctrD += 1;
    }
};

}  // namespace fnv_00cc4c60

struct FUN_00cc4e90_stream;

typedef unsigned int (__cdecl* FUN_00cc4e90_readfn)(FUN_00cc4e90_stream* s, void* dst, unsigned int size, unsigned int* outCount, unsigned int count);

struct FUN_00cc4e90_stream
{
    int unk00;
    unsigned int m_04;
    int unk08;
    FUN_00cc4e90_readfn m_0c;
};

struct FUN_00cc4e90_sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
};

void __cdecl FUN_00cf4bc0(int a1, int v);

class FUN_00cc4e90_cls
{
public:
    int unk00;
    FUN_00cc4e90_sub* m_04;
    void __thiscall FUN_00c8a280(int a1);
    void LoadSubData(int a1);
};

// Calls FUN_00c8a280, passes m_04->m_18 to FUN_00cf4bc0, then reads 4 bytes into m_04->unk20 and 1 byte into m_04->unk24 from the stream at a1+0x250.
// @fnv 0x00cc4e90
// pdb: hkBreakableConstraintCinfo::SaveBinary | bhkBreakableConstraint.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arStream
void FUN_00cc4e90_cls::LoadSubData(int a1)
{
    FUN_00c8a280(a1);
    FUN_00cc4e90_sub* b = m_04;
    FUN_00cf4bc0(a1, b->m_18);
    FUN_00cc4e90_stream* s = *(FUN_00cc4e90_stream**)((char*)a1 + 0x250);
    { unsigned int n = 4; s->m_04 += s->m_0c(s, &b->unk20, 4, &n, 1); }
    s = *(FUN_00cc4e90_stream**)((char*)a1 + 0x250);
    { unsigned int n = 1; s->m_04 += s->m_0c(s, &b->unk24, 1, &n, 1); }
}

extern int DAT_012685e8;

struct SpawnedBase {
    virtual ~SpawnedBase();
};

struct FUN_00cc5090 : SpawnedBase {
    virtual ~FUN_00cc5090();
};

// @fnv 0x00cc5090
FUN_00cc5090::~FUN_00cc5090()
{
    ((bhkConstraint*)this)->FUN_00c876a0();
    DAT_012685e8--;
}

extern int g_unk012685ec;

// @fnv 0x00cc5100
// pdb: bhkPoseArray::GetRTTI | bhkPoseArray.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(udata), high
void* __cdecl bhkPoseArray_GetRTTI(void)
{
    return &g_unk012685ec;
}

namespace fnv_00cc5340 {
extern "C" __declspec(thread) int g_memoryContext;

struct Allocator {
    virtual void Release();
    virtual void* Allocate(unsigned int size);
};

struct MemorySystem {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Allocator* allocator;

    void* Allocate(unsigned int bytes) {
        return allocator->Allocate(bytes);
    }
};

extern "C" MemorySystem* __cdecl FUN_00c85750();

struct FUN_00d4edc0 {
    FUN_00d4edc0();
    static void* operator new(unsigned int size) {
        void* memory = FUN_00c85750()->Allocate(0x160);
        *reinterpret_cast<unsigned short*>(
            static_cast<char*>(memory) + 4) = 0x160;
        return memory;
    }
};

struct AllocationContext {
    int previous;
    AllocationContext() {
        previous = g_memoryContext;
        g_memoryContext = 0x10;
    }
    ~AllocationContext() {
        g_memoryContext = previous;
    }
};

}  // namespace fnv_00cc5340

namespace fnv_00cc53f0 {
extern void* __cdecl FUN_00aa13e0(unsigned int);
extern "C" void __cdecl FUN_00c876f0();
extern "C" void __cdecl FUN_00c87700();
extern int DAT_0108febc;
extern int DAT_010c9a14;
extern int DAT_01268188;
extern int DAT_012685e8;
extern __declspec(thread) int hkThreadAllocationFlag;

struct HavokRuntimeObject {
    void* vtable;
    int refCount;
    int heapFlags;
    int extra;
    void __thiscall FUN_00c87c30();
    static void* __cdecl operator new(unsigned int size) { return FUN_00aa13e0(size); }
    HavokRuntimeObject() {
        FUN_00c87c30();
        vtable = &DAT_0108febc;
        extra = 0;
        ++DAT_01268188;
        vtable = &DAT_010c9a14;
        ++DAT_012685e8;
    }
};
struct HavokThreadScope {
    int oldValue;
    HavokThreadScope() {
        oldValue = hkThreadAllocationFlag;
        hkThreadAllocationFlag = 16;
    }
    ~HavokThreadScope() {
        FUN_00c87700();
        hkThreadAllocationFlag = oldValue;
    }
};
}  // namespace fnv_00cc53f0

struct BinaryStream {
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    int (__cdecl *m_write)(BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count) {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct StreamContext {
    BinaryStream* OutputStream() {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<unsigned char*>(this) + 0x250);
    }
};

extern int DAT_012685f4;

class FUN_00cc58c0_base {
public:
    virtual void unk00();
    ~FUN_00cc58c0_base();
    int unk04;
};

class FUN_00cc58c0 : public FUN_00cc58c0_base {
public:
    virtual ~FUN_00cc58c0();
    void unk08();
};

// Calls unk08 on this object and decrements the global counter DAT_012685f4.
// @fnv 0x00cc58c0
// pdb: bhkStiffSpringConstraint::~bhkStiffSpringConstraint | bhkStiffSpringConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00cc58c0::~FUN_00cc58c0()
{
    this->unk08();
    DAT_012685f4--;
}

extern int DAT_0108febc;
extern int DAT_010c52bc;
extern int DAT_01268188;
extern int DAT_012685f4;

struct CC5930_Base {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiData08;
    CC5930_Base();
    static void* __cdecl operator new(unsigned int size);
};

struct CC5930_Obj : CC5930_Base {
    unsigned int m_uiData0C;

    CC5930_Obj()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0108febc);
        m_uiData0C = 0;
        DAT_01268188 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c52bc);
        DAT_012685f4 += count;
    }
};

// Allocates and constructs a CC5930_Obj, returning the new object.
// @fnv 0x00cc5930
CC5930_Obj* __cdecl CreateCC5930Obj()
{
    return new CC5930_Obj;
}

struct CC5D40BinaryStream {
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CC5D40BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes, unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

class CC5DD0BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CC5DD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CC5DD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

extern int DAT_01268600;

struct FUN_00cc5e60 : bhkConstraint {
    ~FUN_00cc5e60();
};

// @fnv 0x00cc5e60
FUN_00cc5e60::~FUN_00cc5e60()
{
    FUN_00c876a0();
    --DAT_01268600;
}

extern int DAT_01268604;

// @fnv 0x00cc5ed0
// pdb: bhkExtraData::GetRTTI | bhkExtraData.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
int* __cdecl bhkExtraData_GetRTTI()
{
    return &DAT_01268604;
}

struct FUN_00cc5ee0_interface
{
    virtual void __thiscall FUN_00cc5ee0_call(int value) = 0;
};

struct FUN_00cc5ee0_class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;

    void __thiscall ClearInterface(char param_2);
};

// @fnv 0x00cc5ee0
// pdb: bhkRagdollLimitsConstraint::bhkRagdollLimitsConstraint | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void __thiscall FUN_00cc5ee0_class::ClearInterface(char abClear)
{
    if (abClear != 0)
    {
        if (unk0c != 0)
        {
            FUN_00cc5ee0_interface* object =
                reinterpret_cast<FUN_00cc5ee0_interface*>(
                    reinterpret_cast<unsigned char*>(unk0c) - 4);

            if (object != 0)
            {
                object->FUN_00cc5ee0_call(1);
            }
        }

        unk0c = 0;
    }
}

namespace fnv_00cc6140 {

struct Helper2 {
    void* FUN_00c87c30();
};

extern "C" void __cdecl FUN_00c876f0();
extern "C" void __cdecl FUN_00c87700();
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);

extern int DAT_01268188;
extern int DAT_01268600;
extern int DAT_0108febc;
extern int DAT_010c9b0c;

struct Obj {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;

    static void* operator new(unsigned int s) { return FUN_00aa13e0(s); }

    Obj() {
        ((Helper2*)this)->FUN_00c87c30();
        m_pVtable = (void*)&DAT_0108febc;
        int one = 1;
        m_uiData1 = 0;
        DAT_01268188 += one;
        m_pVtable = (void*)&DAT_010c9b0c;
        DAT_01268600 += one;
    }
};

struct C {
    void* FUN_00cc6140(int arg);
};

}  // namespace fnv_00cc6140

namespace fnv_00cc6310 {
struct S_cc6310_Tls {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
};
__declspec(thread) S_cc6310_Tls g_tls_cc6310;
struct S_cc6310_Guard {
    int saved;
    S_cc6310_Guard() { saved = g_tls_cc6310.unk2B4; g_tls_cc6310.unk2B4 = 0x10; }
    ~S_cc6310_Guard() { g_tls_cc6310.unk2B4 = saved; }
};
struct S_cc6310_Pool {
    void* FUN_00aa3e40(unsigned int n);
};
extern S_cc6310_Pool DAT_011f6238;
struct S_cc6310_Base {
    int unk00;
};
struct S_cc6310_Obj {
    int* unk00;
    S_cc6310_Base base;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int n) { return DAT_011f6238.FUN_00aa3e40(n); }
};
}  // namespace fnv_00cc6310

namespace fnv_00cc6720 {
struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr {
    int unk00[4];
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap() { return *unk10; }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();

class RefObj {
public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        RefObj* b = (RefObj*)((AudioMgr*)FUN_00c85750())->heap().AllocateMemoryBlock(nbytes);
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void __cdecl operator delete(void* p);
};

class Payload : public RefObj {
public:
    Payload();
    char m_08[0x140 - 8];
};

class Owner {
public:
    int m_00;
    Payload* m_pkPayload;
    int EnsurePayload();
};

}  // namespace fnv_00cc6720

extern int DAT_01268618;

class FUN_00cc7450_base {
public:
    virtual void unk00();
    ~FUN_00cc7450_base();
    int unk04;
};

class FUN_00cc7450 : public FUN_00cc7450_base {
public:
    virtual ~FUN_00cc7450();
    void unk08();
};

// @fnv 0x00cc7450
FUN_00cc7450::~FUN_00cc7450()
{
    this->unk08();
    DAT_01268618--;
}

extern int DAT_0126861c;

// @fnv 0x00cc74c0
// pdb: bhkSpringAction::GetRTTI | bhkSpringAction.obj | fnv360_1110_retail, objopen_prop, low
void* __cdecl FUN_00cc74c0()
{
    return &DAT_0126861c;
}

// FUN_00cc75b0: thiscall, one stack arg (int a1).
class FUN_00cc75b0_F {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    float m_b4;
};

class FUN_00cc75b0_C {
public:
    FUN_00cc75b0_F* m_00;
};

class FUN_00cc75b0_B {
public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_F* m_08;
    FUN_00cc75b0_F* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char unk1c;
    unsigned char m_1d;
};

class FUN_00cc75b0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_B* m_08;
    FUN_00cc75b0_C* m_0c;
    void Call(int a1);
    void FUN_00cc75b0(int a1);
};

// @fnv 0x00cc75b0
// pdb: bhkPrismaticConstraint::Init | bhkPrismaticConstraint.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: arInfo
void FUN_00cc75b0_cls::FUN_00cc75b0(int aiArg) {
    FUN_00cc75b0_F* f = 0;
    Call(aiArg);
    if (this != 0 && this->m_08 != 0) {
        f = this->m_08->m_0c;
    } else {
        FUN_00cc75b0_C* c = this->m_0c;
        if (c != 0) f = c->m_00;
    }
    if (f != 0 && f->m_b4 != 0.0f) {
        FUN_00cc75b0_B* b = this->m_08;
        if (b != 0) b->m_1d = 1;
    }
}

namespace fnv_00cc7890 {
void FUN_00c876f0();
void* FUN_00aa13e0(unsigned int size);

struct SpawnBase
{
    virtual ~SpawnBase();
    SpawnBase();
    unsigned int unk04;
    unsigned int unk08;
};

extern unsigned int g_spawnCountA;
extern unsigned int g_spawnCountB;

struct SpawnChainA : SpawnBase
{
    SpawnChainA();
    unsigned int m_0c;
};

struct SpawnedObject : SpawnChainA
{
    virtual ~SpawnedObject() {}
    static void* operator new(unsigned int size);
    SpawnedObject();
};

void* SpawnedObject::operator new(unsigned int size)
{
    FUN_00c876f0();
    return FUN_00aa13e0(size);
}

SpawnChainA::SpawnChainA()
{
    m_0c = 0;
    g_spawnCountA++;
}

SpawnedObject::SpawnedObject()
{
    g_spawnCountB++;
}

struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};

extern __declspec(thread) ThreadHeapState g_threadHeapState;

void FUN_00c87700();

class FUN_00cc7890_cls
{
public:
    void* FUN_00cc7890(unsigned int arg);
    void SpawnInit(SpawnedObject* obj, unsigned int arg);
};

struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard() { saved = g_threadHeapState.m_2b4; g_threadHeapState.m_2b4 = 0x10; }
    ~TlsHeapGuard() { g_threadHeapState.m_2b4 = saved; }
};

// Allocates a SpawnedObject under a TLS heap guard, initializes it via SpawnInit with arg, calls FUN_00c87700 and returns the object.
// @fnv 0x00cc7890
void* FUN_00cc7890_cls::FUN_00cc7890(unsigned int arg)
{
    TlsHeapGuard guard;
    SpawnedObject* obj = new SpawnedObject();
    SpawnInit(obj, arg);
    FUN_00c87700();
    return obj;
}
}  // namespace fnv_00cc7890

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

struct NiBinaryStreamSI {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamSI* pThis, void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

extern int DAT_01268624;

extern int DAT_01268628;

// @fnv 0x00cc7d70
// pdb: bhkMotorAction::GetRTTI | bhkMotorAction.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata), high
int* __cdecl bhkMotorAction_GetRTTI()
{
    return &DAT_01268628;
}

// @fnv 0x00cc7d80
// pdb: bhkListShape::QCinfoSize | bhkCharacterController.obj | fnv360_0721_beta, objrun_open, low
int __cdecl FUN_00cc7d80()
{
    return 28;
}

struct CpuOpaque;
extern CpuOpaque DAT_01268f78;
// @fnv 0x00cc7d90
// pdb: bhkDashpotAction::GetRTTI | bhkDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
CpuOpaque* __cdecl FUN_00cc7d90()
{
    return &DAT_01268f78;
}

extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
struct __declspec(novtable) S_00cc7dc0_Root {
    unsigned int unk04;
    unsigned int unk08;
    int unk0c;
    S_00cc7dc0_Root() { Initialize(); unk0c = 0; }
    virtual ~S_00cc7dc0_Root();
    void Initialize();
};
struct S_00cc7dc0_A : S_00cc7dc0_Root {
    S_00cc7dc0_A() { DAT_01268188++; }
    virtual ~S_00cc7dc0_A();
};
struct S_00cc7dc0_B : S_00cc7dc0_A {
    S_00cc7dc0_B() { DAT_01268f74++; }
    virtual ~S_00cc7dc0_B();
};

namespace fnv_00cc83b0 {
extern __declspec(thread) unsigned int hkThreadAllocationTag;
struct AllocationManager {
    void* __thiscall FUN_00aa3e40(unsigned int bytes);
};
extern AllocationManager DAT_011f6238;

struct FUN_00cc83b0_Class;

struct ScopedAllocationTag {
    unsigned int previous;
    ScopedAllocationTag() : previous(hkThreadAllocationTag) {
        hkThreadAllocationTag = 16;
    }
    ~ScopedAllocationTag() {
        hkThreadAllocationTag = previous;
    }
};

struct FUN_00cc83b0_Class {
    void* vtable;
    void* unknown04;
    void* owner;
    void* object;
    void* __thiscall FUN_00cc83b0(bool* created);
};

}  // namespace fnv_00cc83b0

extern int DAT_01268630;
struct FUN_00cc8480 : bhkConstraint {
    ~FUN_00cc8480();
};
// @fnv 0x00cc8480
FUN_00cc8480::~FUN_00cc8480()
{
    FUN_00c876a0();
    DAT_01268630--;
}

extern int g_unk01268634;

// @fnv 0x00cc84f0
// pdb: bhkAngularDashpotAction::GetRTTI | bhkAngularDashpotAction.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00cc84f0()
{
    return &g_unk01268634;
}

extern __declspec(thread) int g_iCC8770AllocTag;

struct BCC8770AllocTagScope {
    int m_iSaved;

    BCC8770AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC8770AllocTag;
        g_iCC8770AllocTag = aiAllocationTag;
    }
    ~BCC8770AllocTagScope() { g_iCC8770AllocTag = m_iSaved; }
};

class BCC8770RefObject {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BCC8770RefObject();
    virtual ~BCC8770RefObject();

    int unk04;
    int unk08;
};

class BCC8770Shape : public BCC8770RefObject {
public:
    BCC8770Shape() : m_pkShape(0) { ms_uiInstances++; }
    virtual ~BCC8770Shape();

    void* m_pkShape;

    static unsigned int ms_uiInstances;
};

class BCC8770DerivedShape : public BCC8770Shape {
public:
    BCC8770DerivedShape() { ms_uiInstances++; }
    virtual ~BCC8770DerivedShape();

    static unsigned int ms_uiInstances;
};

extern __declspec(thread) int g_tlsMemContext;

struct SerializationMemoryContext {
    int previous;
    SerializationMemoryContext() : previous(g_tlsMemContext) {
        g_tlsMemContext = 16;
    }
    ~SerializationMemoryContext() {
        g_tlsMemContext = previous;
    }
};

extern int DAT_0126863c;
struct S_cc8ce0_Base {
    virtual ~S_cc8ce0_Base();
    void FUN_00c876a0();
};
struct FUN_00cc8ce0 : S_cc8ce0_Base {
    ~FUN_00cc8ce0();
};
// @fnv 0x00cc8ce0
FUN_00cc8ce0::~FUN_00cc8ce0() {
    FUN_00c876a0();
    DAT_0126863c--;
}

extern int DAT_01268640;

// @fnv 0x00cc8d50
// pdb: bhkBreakableConstraint::GetRTTI | bhkBreakableConstraint.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
int* __cdecl bhkBreakableConstraint_GetRTTI()
{
    return &DAT_01268640;
}

// @fnv 0x00cc8d60
// pdb: bhkBallSocketConstraintChain::QCinfoSize | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00cc8d60()
{
    return 44;
}

extern int DAT_01268f84;

// @fnv 0x00cc8d70
// pdb: bhkWheelConstraint::GetRTTI | bhkWheelConstraint.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
int* bhkWheelConstraint_GetRTTI()
{
    return &DAT_01268f84;
}

namespace fnv_00cc8dc0 {
extern int g_ctorCountA;
extern int g_ctorCountB;
extern int g_ctorCountD;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct OwnerBase {
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw() {
        return FUN_00aa13e0(size);
    }
};

struct ChainA_cls : public OwnerBase {
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_cls() {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        g_ctorCountB += 1;
    }
};

struct SpawnedObject : public ChainB_cls {
    virtual void unkD2();
    SpawnedObject() {
        g_ctorCountD += 1;
    }
};

// Allocates and constructs a new SpawnedObject via its operator new and returns the pointer.
// @fnv 0x00cc8dc0
// pdb: bhkBallSocketConstraintChain::CreateObject | bhkBallSocketConstraintChain.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
SpawnedObject* FUN_00cc8dc0() {
    return new SpawnedObject();
}
}  // namespace fnv_00cc8dc0

struct NiBinaryStreamStandIn {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamStandIn* pkThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Write(const T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
};

struct NiStreamImpl {
    char pad[0x250];
    NiBinaryStreamStandIn* m_pBackingStream;
};

template <class T> inline void SerializeValue(NiStreamImpl& stream, const T& value)
{
    stream.m_pBackingStream->Write(&value);
}

void __cdecl FUN_00cf0cf0(NiStreamImpl& stream, void* pValue);

struct HavokData_cc8 {
    char pad[0x24];
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
};

struct FUN_00cc8f60_cls {
    int unk00;
    HavokData_cc8* m_pUserData;
    char pad08[0x18];
    int m_20;

    void FUN_00d53360(NiStreamImpl& stream);
    void FUN_00cc8f60(NiStreamImpl& stream);
};

// @fnv 0x00cc8f60
// pdb: hkBallSocketChainCinfo::SaveBinary | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arStream
void FUN_00cc8f60_cls::FUN_00cc8f60(NiStreamImpl& stream)
{
    HavokData_cc8* pkData = m_pUserData;
    FUN_00cf0cf0(stream, &m_20);
    SerializeValue(stream, pkData->m_f28);
    SerializeValue(stream, pkData->m_f24);
    SerializeValue(stream, pkData->m_f2c);
    SerializeValue(stream, pkData->m_f30);
    FUN_00d53360(stream);
}

extern __declspec(thread) int g_iCC90D0MemContext;

class CC90D0MemContext {
public:
    CC90D0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCC90D0MemContext;
        g_iCC90D0MemContext = aiMemoryContext;
    }
    ~CC90D0MemContext() { g_iCC90D0MemContext = m_iPrevious; }

    int m_iPrevious;
};

void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();

class CC90D0RefObject {
public:
    CC90D0RefObject();
    virtual ~CC90D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};

class CC90D0Level1 : public CC90D0RefObject {
public:
    CC90D0Level1() : m_pPointer(0) { ++ms_uiInstances; }
    virtual ~CC90D0Level1();

    void* m_pPointer;

    static unsigned int ms_uiInstances;
};

class CC90D0Level2 : public CC90D0Level1 {
public:
    CC90D0Level2() { ++ms_uiInstances; }
    virtual ~CC90D0Level2();

    static unsigned int ms_uiInstances;
};

class CC90D0Level3 : public CC90D0Level2 {
public:
    CC90D0Level3() { ++ms_uiInstances; }
    virtual ~CC90D0Level3();

    static unsigned int ms_uiInstances;
};

namespace fnv_00cc94b0 {
struct SpawnedAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedAllocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();

struct SpawnedScopeOwner;

struct SpawnedScopeGuard {
    SpawnedScopeOwner* m_pSharedOwner;
    SpawnedScopeGuard(SpawnedScopeOwner* owner) : m_pSharedOwner(owner) {}
    ~SpawnedScopeGuard();
};

struct SpawnedScopeBase {
    void Cleanup();
};

struct SpawnedScopeOwner : public SpawnedScopeBase {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FreeSpawnedStorage();
};

}  // namespace fnv_00cc94b0

extern int DAT_01268648;

extern int DAT_0108febc;
extern int DAT_010c8b0c;
extern int DAT_01268188;
extern int DAT_01268648;

struct PhysicsAllocator {
    static void* __cdecl operator new(unsigned int size);
};

struct PhysicsReference {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    PhysicsReference();
};

struct PhysicsObject : PhysicsAllocator, PhysicsReference {
    unsigned int m_uiData;

    PhysicsObject() : PhysicsReference()
    {
        unsigned int count = 1;
        m_pVtable = &DAT_0108febc;
        m_uiData = 0;
        DAT_01268188 += count;
        m_pVtable = &DAT_010c8b0c;
        DAT_01268648 += count;
    }
};

// MakeClone for a Havok wrapper: under the world lock, create a new wrapper and copy our data into it.

extern __declspec(thread) int g_iCC9940AllocTag;

struct CC9940AllocTagScope {
    int m_iSaved;

    CC9940AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC9940AllocTag;
        g_iCC9940AllocTag = aiAllocationTag;
    }
    ~CC9940AllocTagScope() { g_iCC9940AllocTag = m_iSaved; }
};

extern int g_iCC9940RefObjectCount;
extern int g_iCC9940WrapperCount;

class CC9940Root {
public:
    CC9940Root();
    virtual ~CC9940Root();
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class CC9940Holder : public CC9940Root {
public:
    CC9940Holder() : m_pkHavokObject(0) {}
    virtual ~CC9940Holder();
    void* m_pkHavokObject;
};

class CC9940RefObject : public CC9940Holder {
public:
    CC9940RefObject() { ++g_iCC9940RefObjectCount; }
    virtual ~CC9940RefObject();
};

class CC9940Wrapper : public CC9940RefObject {
public:
    CC9940Wrapper() { ++g_iCC9940WrapperCount; }
    virtual ~CC9940Wrapper();

    void CopyMemberData(CC9940Wrapper* pkDest, int iCloning);
    CC9940Wrapper* FUN_00cc9940(int iCloning);
};

class BCC9B80BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(BCC9B80BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

namespace fnv_00cc9bf0 {
struct NiBinaryStreamStandIn {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamStandIn* pkThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Write(const T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
};

struct NiStreamImpl {
    char pad[0x250];
    NiBinaryStreamStandIn* m_pBackingStream;
};

template <class T> inline void SerializeValue(NiStreamImpl& stream, const T& value)
{
    stream.m_pBackingStream->Write(&value);
}

}  // namespace fnv_00cc9bf0

class CC9C60Base {
public:
    virtual ~CC9C60Base();

    void Shutdown();
};

class bhkBallAndSocketConstraint : public CC9C60Base { // src: F3_EXE vtable 0x00e36ee4 (old: FUN_00cc9c60)
public:
    virtual ~bhkBallAndSocketConstraint();

    static unsigned int ms_uiInstances;
};

// Destructor that calls Shutdown and decrements the static instance counter ms_uiInstances.
// @fnv 0x00cc9c60
// pdb: bhkBallAndSocketConstraint::~bhkBallAndSocketConstraint | bhkBallAndSocketConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
bhkBallAndSocketConstraint::~bhkBallAndSocketConstraint()
{
    Shutdown();
    --ms_uiInstances;
}

namespace fnv_00cc9d80 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00cc9d80_cls {
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d54960();

    FUN_00cc9d80_cls* FUN_00cc9d80(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00cc9d80

extern int DAT_01268658;

// @fnv 0x00cc9db0
// pdb: bhkRagdollLimitsConstraint::GetRTTI | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
void* __cdecl bhkRagdollLimitsConstraint_GetRTTI()
{
    return &DAT_01268658;
}

// @fnv 0x00cc9dc0
// pdb: UseWeaponActorPackageData::GetPackageType | PackageDataUseWeapon.obj | fnv360_0822_retail, vtable, medium
int __cdecl FUN_00cc9dc0() { return 16; }

struct S_00cc9df0_Val {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_f;
};
struct S_00cc9df0_Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00cc9df0_Val* m_kPointA;
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
    S_00cc9df0_Val* m_kPointB;
};
struct S_00cc9df0_Out {
    int unk00;
    int unk04;
    S_00cc9df0_Val* m_v;
    float m_fValue;
};
struct S_00cc9df0_Cls;
struct S_00cc9df0_Cls {
    int unk00;
    int unk04;
    S_00cc9df0_Data* m_iFourthElementInteger;
    void bhkBvTreeShape_CopyCinfo(S_00cc9df0_Out* out);
    void SetRatioFromValues(S_00cc9df0_Out* out);
};

// Apply a scale: multiply the Havok shape's radius by the scale, refresh the shape, then the base handles the rest.

struct Owner_Target {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class FUN_00cca0e0_cls {
public:
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual Owner_Target* v45(unsigned int* p);
    void FUN_00ca4ec0(unsigned int a);
    void FUN_00cca0e0(unsigned int param);
};

extern __declspec(thread) int g_iCCA1B0MemContext;

class CCA1B0MemContext {
public:
    CCA1B0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCCA1B0MemContext;
        g_iCCA1B0MemContext = aiMemoryContext;
    }
    ~CCA1B0MemContext() { g_iCCA1B0MemContext = m_iPrevious; }

    int m_iPrevious;
};

void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();

class CCA1B0RefObject {
public:
    CCA1B0RefObject();
    virtual ~CCA1B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};

class CCA1B0Level1 : public CCA1B0RefObject {
public:
    CCA1B0Level1() : m_pkFirst(0), m_pkSecond(0) { ++ms_uiInstances; }
    virtual ~CCA1B0Level1();

    void* m_pkFirst;
    void* m_pkSecond;

    static unsigned int ms_uiInstances;
};

class CCA1B0Level2 : public CCA1B0Level1 {
public:
    CCA1B0Level2() { ++ms_uiInstances; }
    virtual ~CCA1B0Level2();

    static unsigned int ms_uiInstances;
};

class CCA1B0Level3 : public CCA1B0Level2 {
public:
    CCA1B0Level3() { ++ms_uiInstances; }
    virtual ~CCA1B0Level3();

    static unsigned int ms_uiInstances;
};

namespace fnv_00cca4e0 {
extern int DAT_012680f8;
extern int DAT_012682cc;
extern int DAT_01268654;

struct FUN_00c87c30_owner {
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct ChainA_cls : public FUN_00c87c30_owner {
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls() {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        DAT_012682cc += 1;
    }
};

}  // namespace fnv_00cca4e0

extern int DAT_01268664;

// @fnv 0x00cca940
int __cdecl FUN_00cca940() {
    return reinterpret_cast<int>(&DAT_01268664);
}

class CCAA80Object {
public:
    CCAA80Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// Allocates and constructs a new CCAA80Object, returning the pointer.
// @fnv 0x00ccaa80
// pdb: bhkTriangleShape::CreateObject | bhkTriangleShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
CCAA80Object* __cdecl CreateCCAA80Object()
{
    return new CCAA80Object;
}

extern "C" void _ReadWriteBarrier(void);

struct FUN_00ccab60_arg {
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
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};

struct FUN_00ccab60_rec {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};

struct FUN_00ccab60_cls {
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual FUN_00ccab60_rec* GetRec(FUN_00ccab60_arg*& a);
    void FUN_00c9fbc0(FUN_00ccab60_arg* a);
    void ProcessRecord(FUN_00ccab60_arg* a1);
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long value);

namespace fnv_00ccacf0 {
struct S_00ccacf0_Tls {
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
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00ccacf0_Tls DAT_tls;

struct S_00ccacf0_Ctx {
    int saved;
    __forceinline S_00ccacf0_Ctx(int c) { saved = DAT_tls.ctx; DAT_tls.ctx = c; }
    __forceinline ~S_00ccacf0_Ctx() { DAT_tls.ctx = saved; }
};

void FUN_00c876f0();
void FUN_00c87700();
void* __cdecl FUN_00aa13e0(unsigned int n);

struct S_00ccacf0_Obj {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    S_00ccacf0_Obj();
    static void* operator new(unsigned int n) { return FUN_00aa13e0(n); }
    static void operator delete(void*) {}
};

}  // namespace fnv_00ccacf0

namespace fnv_00ccae90 {
struct ResourceManager {
    void __thiscall FUN_00aa4060(void* resource);
};
extern ResourceManager DAT_011f6238;
extern __declspec(thread) unsigned int tlsCurrentContext;
}  // namespace fnv_00ccae90

extern __declspec(thread) int g_iCCB080AllocTag;

struct BCCB080AllocTagScope {
    int m_iSaved;

    BCCB080AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCB080AllocTag;
        g_iCCB080AllocTag = aiAllocationTag;
    }
    ~BCCB080AllocTagScope() { g_iCCB080AllocTag = m_iSaved; }
};

class BCCB080StringArray {
public:
    virtual ~BCCB080StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

extern int DAT_01268670;
// @fnv 0x00ccb130
// pdb: bhkGenericConstraint::GetRTTI | bhkFixedConstraint.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
void* __cdecl bhkGenericConstraint_GetRTTI() {
    return &DAT_01268670;
}

// @fnv 0x00ccb140
// pdb: bhkTriangleShape::QCinfoSize | bhkTriangleShape.obj | fnv360_0721_beta, objrun_open, low
int __cdecl FUN_00ccb140()
{
    return 64;
}

extern int g_unk01268f90;

// @fnv 0x00ccb150
// pdb: bhkGenericConstraint::QCinfoSize | bhkFixedConstraint.obj | fnv360_0822_debug, objrun_open, low
void* FUN_00ccb150()
{
    return &g_unk01268f90;
}

extern int DAT_01030bf4;
extern int DAT_010ca5c4;
extern int DAT_010ca4dc;
extern int DAT_012680f8;
extern int DAT_01268f8c;
extern int DAT_0126866c;

struct AllocationBase {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00c87c30_Base {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    S_00c87c30_Base();
};

struct TargetObject : AllocationBase, S_00c87c30_Base {
    TargetObject() : S_00c87c30_Base() {
        m_pVtable = &DAT_01030bf4;
        unsigned int count = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
        DAT_012680f8 += count;
        m_pVtable = &DAT_010ca5c4;
        DAT_01268f8c += count;
        m_pVtable = &DAT_010ca4dc;
        DAT_0126866c += count;
    }
};

// Allocates and constructs a TargetObject, returning the new instance.
// @fnv 0x00ccb200
// pdb: bhkPlaneShape::CopyCinfo | bhkPlaneShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInfo
TargetObject* __cdecl CreateTargetObject() {
    return new TargetObject();
}

namespace fnv_00ccb4e0 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

extern "C" void __cdecl FUN_00c876f0();
extern "C" void __cdecl FUN_00c87700();
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern "C" int DAT_012680f8;
extern "C" int DAT_01268f8c;
extern "C" int DAT_0126866c;

struct SpawnRoot_cls
{
    virtual void v_root();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    SpawnRoot_cls();
    static void* operator new(unsigned int size) throw() { return FUN_00aa13e0(size); }
};

struct SpawnA_cls : SpawnRoot_cls
{
    virtual void v_a0();
    SpawnA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct SpawnB_cls : SpawnA_cls
{
    virtual void v_b0();
    SpawnB_cls()
    {
        DAT_01268f8c += 1;
    }
};

struct SpawnC_cls : SpawnB_cls
{
    virtual void v_c0();
    SpawnC_cls()
    {
        DAT_0126866c += 1;
    }
};

}  // namespace fnv_00ccb4e0

typedef unsigned int CCB730size_t;

extern __declspec(thread) int g_CCB730AllocTag;

struct CCB730AllocTagScope {
    int m_iSaved;

    CCB730AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCB730AllocTag;
        g_CCB730AllocTag = aiAllocationTag;
    }
    ~CCB730AllocTagScope() { g_CCB730AllocTag = m_iSaved; }
};

struct CCB730Child {
    CCB730Child() throw()
        : m_pkOwnerManager(0), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {
    }

    void* m_pkOwnerManager;
    int unk04;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCB730size_t, void* pvMem) { return pvMem; }
};

extern int DAT_01268684;

// @fnv 0x00ccb990
// pdb: bhkHingeLimitsConstraint::GetRTTI | bhkHingeLimitsConstraint.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
void* __cdecl bhkHingeLimitsConstraint_GetRTTI()
{
    return &DAT_01268684;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct FunObjBase_b9645 {
    FunObjBase_b9645();
    virtual void unk00();
    unsigned int m_04;
    static void* operator new(unsigned int size) throw() {
        return FUN_00aa13e0(size);
    }
};

struct FunObj_b9645 : public FunObjBase_b9645 {
    virtual void unk10();
    unsigned int m_08;
    unsigned int m_0c;
    FunObj_b9645() {
        m_08 = 0;
        m_0c = 0;
    }
};

// Allocates and constructs a new FunObj_b9645, returning the new object.
// @fnv 0x00ccb9a0
// pdb: bhkExtendedMeshSubPart::`vector deleting destructor' | bhkExtendedMeshShape.obj | fnv360_0822_retail, objopen_prop, low
FunObj_b9645* CreateFunObj() {
    return new FunObj_b9645();
}

// Decompilation candidate for FUN_00ccba30 (0x00ccba30, 32 bytes).
//
// Shape: a member function that (1) forwards its single argument to a virtual
// slot of an object held at offset 0x14 of itself and (2) hands the same
// argument to its own member helper FUN_00aa0ad0.

struct TargetObj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v15(NiStream* stream);
};

struct HC1Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    TargetObj* m_pEntryObject;
    bool __thiscall FUN_00aa0ad0(NiStream* stream);
    void __thiscall FUN_00ccba30(NiStream* stream);
};

// @fnv 0x00ccba30
void HC1Base::FUN_00ccba30(NiStream* stream)
{
    m_pEntryObject->v15(stream);
    FUN_00aa0ad0(stream);
}

struct FUN_00ccba50_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_14;
    char FUN_00c84dc0(FUN_00ccba50_cls* p);
    char Equals(FUN_00ccba50_cls* p);
};

// @fnv 0x00ccba50
// pdb: bhkExtendedMeshShape::IsEqual | bhkExtendedMeshShape.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apObject
char FUN_00ccba50_cls::Equals(FUN_00ccba50_cls* apOther)
{
    char r = FUN_00c84dc0(apOther);
    if (r)
        r = (m_14 == apOther->m_14);
    return r;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

struct RefObjCC {
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T>
struct NiPtrCC {
    T* m_pObject;
    NiPtrCC(T* p = 0) : m_pObject(p) { if (m_pObject) m_pObject->IncRefCount(); }
    ~NiPtrCC();
    NiPtrCC& operator=(T* pObject)
    {
        if (m_pObject != pObject) {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct FUN_00ccbaa0 {
    void* m_p0;
    NiPtrCC<RefObjCC> m_sp;
    FUN_00ccbaa0(RefObjCC* p);
};

// Constructs the holder with a null pointer and stores the given RefObjCC in the smart pointer, incrementing its reference count.
// @fnv 0x00ccbaa0
// pdb: hkExtendedMeshShapeCinfo::~hkExtendedMeshShapeCinfo | bhkExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
FUN_00ccbaa0::FUN_00ccbaa0(RefObjCC* apObject)
    : m_p0(0), m_sp(0)
{
    m_sp = apObject;
}

extern int DAT_0126867c;

// @fnv 0x00ccbb30
// pdb: bhkConstraintChain::GetRTTI | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
int __cdecl bhkConstraintChain_GetRTTI() {
    return reinterpret_cast<int>(&DAT_0126867c);
}

// @fnv 0x00ccbb40
// pdb: bhkConvexVerticesShape::QCinfoSize | bhkConvexVerticesShape.obj | fnv360_0721_beta, objrun_open, low
int __cdecl FUN_00ccbb40()
{
    return 0x20;
}

namespace fnv_00ccbb50 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;


struct TlsFlagGuard
{
    int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct FUN_00ccbb50_pool
{
    void FUN_00aa4060(int p);
};
extern FUN_00ccbb50_pool DAT_011f6238;

}  // namespace fnv_00ccbb50

namespace fnv_00ccc2f0 {
extern __declspec(thread) unsigned int g_tlsMemContext;

struct MemContextGuard {
    unsigned int uiOld;
    MemContextGuard(unsigned int uiNew) {
        uiOld = g_tlsMemContext;
        g_tlsMemContext = uiNew;
    }
    ~MemContextGuard() { g_tlsMemContext = uiOld; }
};

struct StreamStub {
    int unk00;
    int iPos;
    int (__cdecl* pfnWrite)(StreamStub*, void*, unsigned int, int, int);
};

struct SaveCtx {
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
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
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
    StreamStub* pStream;
};

}  // namespace fnv_00ccc2f0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct FNVRefObj;
struct FNVRefVTable {
    void (__thiscall *m_method00)(FNVRefObj*);
    void (__thiscall *m_release)(FNVRefObj*);
};
struct FNVRefObj {
    FNVRefVTable* m_ppVirtualMethodTable;
    volatile long m_refcount;
};
struct FNVHolder {
    void* m_ppVirtualMethodTable;
    FNVRefObj* m_object;
};
struct FNVParam {
    FNVRefObj* __thiscall FUN_00a63430();
};
struct FNVTarget {
    void* m_ppVirtualMethodTable;
    void __thiscall FUN_00c84cc0(FNVParam*);
    void __thiscall AssignRefObject(FNVParam*);
};
typedef FNVHolder* (__thiscall *FNVQuery)(FNVTarget*, bool*);

struct S_00ccc620_BinStream {
    int unk00;
    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int (__cdecl *m_pfnWrite)(S_00ccc620_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
template <class T> inline void WriteBinaryArray(S_00ccc620_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytes = uiNumEls * sizeof(T);
    kStream.Write(pkValue, uiBytes, &uiSize, 1);
}

class CCCF00BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CCCF00BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CCCF00BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n) {
        unsigned int size = n;
        return BinaryWrite(p, n, &size, 1);
    }
};

// bhkBallSocketConstraintChain_GetRTTI : a one-line function - getter
extern int g_target_00ccd0f0;
// @fnv 0x00ccd0f0
// pdb: bhkBallSocketConstraintChain::GetRTTI | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata) + skyrim(udata), high
void* bhkBallSocketConstraintChain_GetRTTI() { return &g_target_00ccd0f0; }

namespace fnv_00ccd1d0 {
extern int DAT_01267e30;

}  // namespace fnv_00ccd1d0

extern void* __cdecl FUN_00aa13e0(unsigned int size);
struct FUN_00ccd100 {
    void* vtable;
    unsigned int refCount;
    unsigned int flags;
    unsigned int dataA;
    unsigned int dataB;
    FUN_00ccd100();
    static void* __cdecl operator new(unsigned int bytes) {
        return FUN_00aa13e0(bytes);
    }
};
// Allocates and constructs a new FUN_00ccd100 object, returning its pointer.
// @fnv 0x00ccd250
// pdb: bhkCylinderShape::CreateClone | bhkCylinderShape.obj | fnv360_1110_retail, objrun_prop, low, conflict (bridge: bhkExtendedMeshShape::CreateObject)
// pdb params: arCloneData
FUN_00ccd100* __cdecl FUN_00ccd250() {
    return new FUN_00ccd100;
}

extern "C" void _ReadWriteBarrier(void);

struct S_00ccd330_Arg {
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
    unsigned char unk1E4;
    unsigned char m1E5;
};

struct S_00ccd330_Data {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};

struct S_00ccd330_Foo {
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual S_00ccd330_Data* FUN_v45(void** value);
    S_00ccd330_Data* m_pData;
    void __thiscall FUN_00c9fbc0(S_00ccd330_Arg* a1);
    void FUN_00ccd330(S_00ccd330_Arg* a1);
};

struct FUN_00ccd3a0_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char m_1e4;
};

namespace fnv_00ccd520 {
extern "C" __declspec(thread) int g_currentMemoryContext;
extern "C" float DAT_010c72bc;

struct MemoryHeap {
    void* __thiscall FUN_00aa3e40(unsigned int byteCount);
};
extern MemoryHeap DAT_011f6238;

struct MemoryContextScope {
    int previousContext;
    MemoryContextScope() {
        previousContext = g_currentMemoryContext;
        g_currentMemoryContext = 0x10;
    }
    ~MemoryContextScope() {
        g_currentMemoryContext = previousContext;
    }
};

}  // namespace fnv_00ccd520

namespace fnv_00ccd610 {
struct S_00ccd610_Tls {
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
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00ccd610_Tls DAT_tls;

struct S_00ccd610_Ctx {
    int saved;
    __forceinline S_00ccd610_Ctx(int c) { saved = DAT_tls.ctx; DAT_tls.ctx = c; }
    __forceinline ~S_00ccd610_Ctx() { DAT_tls.ctx = saved; }
};

struct S_00ccd610_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00ccd610_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00ccd610_Alloc* unk10;
    S_00ccd610_Alloc& heap() { return *unk10; }
};
S_00ccd610_Router* FUN_00c85750() throw();

struct S_00ccd610_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00ccd610_RefObj();
    void FUN_00c905b0();
    void* operator new(unsigned int n) {
        S_00ccd610_RefObj* b = static_cast<S_00ccd610_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
};

}  // namespace fnv_00ccd610

extern int g_012686a0;

// @fnv 0x00ccdc30
// pdb: bhkMoppBvTreeShape::GetRTTI | bhkMoppBvTreeShape.obj | fnv360_0822_debug, udata + bridge(vtable_prefix|udata), high
int* __cdecl bhkMoppBvTreeShape_GetRTTI()
{
    return &g_012686a0;
}

// Constructor of a four-level Havok wrapper class: each level bumps its own live-instance counter.

extern int g_iCDC40LevelACount;
extern int g_iCDC40LevelBCount;
extern int g_iCDC40LevelCCount;
extern int g_iCDC40LevelDCount;

class CDC40Root {
public:
    CDC40Root();
    virtual ~CDC40Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class CDC40Holder : public CDC40Root {
public:
    CDC40Holder() : m_pkHavokObject(0), m_uiData(0) {}
    virtual ~CDC40Holder();
    void* m_pkHavokObject;
    unsigned int m_uiData;
};

class CDC40LevelA : public CDC40Holder {
public:
    CDC40LevelA() { ++g_iCDC40LevelACount; }
    virtual ~CDC40LevelA();
};

class CDC40LevelB : public CDC40LevelA {
public:
    CDC40LevelB() { ++g_iCDC40LevelBCount; }
    virtual ~CDC40LevelB();
};

class CDC40LevelC : public CDC40LevelB {
public:
    CDC40LevelC() { ++g_iCDC40LevelCCount; }
    virtual ~CDC40LevelC();
};

class FUN_00ccdc40 : public CDC40LevelC {
public:
    FUN_00ccdc40();
    virtual ~FUN_00ccdc40();
};

// Constructs a CDC40LevelD object and increments the global CDC40 level D instance counter.
// @fnv 0x00ccdc40
// pdb: bhkCylinderShape::bhkCylinderShape | bhkCylinderShape.obj | fnv360_1110_retail, objrun, medium
FUN_00ccdc40::FUN_00ccdc40()
{
    ++g_iCDC40LevelDCount;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct RefObject20_b9084 {
    char m00[0x14];
    RefObject20_b9084();
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
};

// Allocates and constructs a RefObject20_b9084 via its operator new and returns the new object.
// @fnv 0x00ccdd00
// pdb: hkConvexVerticesShapeCinfo::Scale | bhkConvexVerticesShape.obj | fnv360_0822_retail, objopen_prop, low, conflict (bridge: bhkConvexVerticesShape::CreateObject)
// pdb params: afScale
RefObject20_b9084* CreateRefObject20() {
    return new RefObject20_b9084();
}

extern float DAT_010c72bc;

namespace fnv_00cce0d0 {
struct SpawnedAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedAllocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();

}  // namespace fnv_00cce0d0

extern __declspec(thread) int g_iCCE110AllocTag;

struct BCCE110AllocTagScope {
    int m_iSaved;

    BCCE110AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCE110AllocTag;
        g_iCCE110AllocTag = aiAllocationTag;
    }
    ~BCCE110AllocTagScope() { g_iCCE110AllocTag = m_iSaved; }
};

class BCCE110StringArray {
public:
    virtual ~BCCE110StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

namespace fnv_00cce290 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize);
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct AudioScopeGuard {
    void* m_pSharedOwner;
    AudioScopeGuard(void* owner) { m_pSharedOwner = owner; }
    ~AudioScopeGuard() { m_pSharedOwner = 0; }
};

}  // namespace fnv_00cce290

extern int DAT_012686b0;

// @fnv 0x00cce970
// pdb: bhkTriangleShape::GetRTTI | bhkTriangleShape.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00cce970()
{
    return &DAT_012686b0;
}

// @fnv 0x00cce980
// pdb: bhkTransformShape::QCinfoSize | BSTreeNode.obj | fnv360_0721_beta, objrun, medium
int __cdecl FUN_00cce980()
{
    return 0x50;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00cce9e0_cls {
    int unk00;

    void BaseCleanup();

    FUN_00cce9e0_cls* FUN_00cce9e0(unsigned char acFlags);
};

// @fnv 0x00cce9e0
// pdb: bhkBoxShape::`scalar deleting destructor' | TESObjectREFR.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00cce9e0_cls* FUN_00cce9e0_cls::FUN_00cce9e0(unsigned char acFlags)
{
    BaseCleanup();
    if (acFlags & 1) {
        FUN_00aa1460(this, 0x14);
    }
    return this;
}

struct FUN_00cced20_C {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54(int a);
};

struct FUN_00cced20_B {
    int unk00;
    int unk04;
    FUN_00cced20_C* m_08;
};

struct FUN_00cced20_A {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00cced20_B* m_18;
};

struct FUN_00cced20_cls {
    int unk00;
    int unk04;
    FUN_00cced20_A* m_08;

    void FUN_00aa0ad0(int a);
    void ForwardToNestedVtable(int a1);
};

// Walks this->m_08->m_18->m_08 and, if non-null, calls its v54 with a1, then calls FUN_00aa0ad0(a1).
// @fnv 0x00cced20
// pdb: bhkConvexTransformShape::RegisterStreamables | bhkConvexTransformShape.obj | fnv360_0721_retail, objrun, medium
// pdb params: arStream
void FUN_00cced20_cls::ForwardToNestedVtable(int aiValue)
{
    if (this != 0) {
        FUN_00cced20_A* pRoot = m_08;
        if (pRoot != 0) {
            FUN_00cced20_B* pMid = pRoot->m_18;
            if (pMid != 0) {
                FUN_00cced20_C* pLeaf = pMid->m_08;
                if (pLeaf != 0) {
                    pLeaf->v54(aiValue);
                }
            }
        }
    }
    FUN_00aa0ad0(aiValue);
}

namespace fnv_00ccef50 {
extern __declspec(thread) int g_iMemContext;

struct AutoMemCtx {
    int m_iOld;
    AutoMemCtx(int ctx) { m_iOld = g_iMemContext; g_iMemContext = ctx; }
    ~AutoMemCtx() { g_iMemContext = m_iOld; }
};

struct hkMemAllocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int size);
};

struct hkThreadMem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemAllocator* m_pAllocator;
};

hkThreadMem* FUN_00c85750();

struct IntegerBlock18 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct hkObj {
    void* m_pVtable;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
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

    static void* operator new(unsigned int size) {
        hkThreadMem* t = FUN_00c85750();
        hkObj* p = (hkObj*)t->m_pAllocator->AllocateMemoryBlock(size);
        p->m_usMemSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
    hkObj(int a, IntegerBlock18* b, int c);
    void removeReference();
};

}  // namespace fnv_00ccef50

extern __declspec(thread) int gThreadAllocState;
struct ScopedThreadSetting {
    int prior;
    ScopedThreadSetting() : prior(gThreadAllocState) {
        gThreadAllocState = 16;
    }
    ~ScopedThreadSetting() { gThreadAllocState = prior; }
};

struct TaskTls {
 int unk000;
 int unk004;
 int unk008;
 int unk00C;
 int unk010;
 int unk014;
 int unk018;
 int unk01C;
 int unk020;
 int unk024;
 int unk028;
 int unk02C;
 int unk030;
 int unk034;
 int unk038;
 int unk03C;
 int unk040;
 int unk044;
 int unk048;
 int unk04C;
 int unk050;
 int unk054;
 int unk058;
 int unk05C;
 int unk060;
 int unk064;
 int unk068;
 int unk06C;
 int unk070;
 int unk074;
 int unk078;
 int unk07C;
 int unk080;
 int unk084;
 int unk088;
 int unk08C;
 int unk090;
 int unk094;
 int unk098;
 int unk09C;
 int unk0A0;
 int unk0A4;
 int unk0A8;
 int unk0AC;
 int unk0B0;
 int unk0B4;
 int unk0B8;
 int unk0BC;
 int unk0C0;
 int unk0C4;
 int unk0C8;
 int unk0CC;
 int unk0D0;
 int unk0D4;
 int unk0D8;
 int unk0DC;
 int unk0E0;
 int unk0E4;
 int unk0E8;
 int unk0EC;
 int unk0F0;
 int unk0F4;
 int unk0F8;
 int unk0FC;
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
 int context;
};
__declspec(thread) TaskTls g_taskTls;
struct AutoMemContext {
 int old;
 AutoMemContext(int value) { old=g_taskTls.context; g_taskTls.context=value; }
 ~AutoMemContext() { g_taskTls.context=old; }
};
struct ThreeByThreeMatrix {
 float m00,m01,m02,m10,m11,m12,m20,m21,m22;
 char* ToString(const char*);
};
struct Transform403 { hkVector4 row0,row1,row2,translation; };
struct Output403 {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
 virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
 virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
 virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
 virtual void Output(StrArr*);
};
struct Link403 { int unk00,unk04; Output403* target; };
struct Data403 { int unk00,unk04,unk08,unk0c,unk10,unk14; Link403* link; int unk1c; Transform403 transform; };
extern Transform403 DAT_01268370;
extern const char g_010c6050[],g_010c604c[];
char* __cdecl FUN_00a7d330(const char*);
struct StringArray403 : StrArr {
 void Add(char* value) {
  unsigned int index=m_usElementCount;
  if(index >= m_usSize) SetSize(index+m_usIncrement);
  SetAt(index,value);
 }
};
struct Holder403 {
 int unk00,unk04;
 Data403* data;
 void FUN_00c9fc50(StrArr*);
 const Transform403& GetTransform() const {
  if(this && data) return data->transform;
  return DAT_01268370;
 }
 void AppendTransformStrings(StringArray403*);
};

extern int DAT_012686b8;

// @fnv 0x00ccf550
// pdb: bhkHeightFieldShape::GetRTTI | bhkPlaneShape.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata), high
void* __cdecl bhkHeightFieldShape_GetRTTI()
{
    return &DAT_012686b8;
}

// FUN_00ccf560 - a virtual forwarder.
//
// The object pointer arrives in ECX (a __thiscall member).  The function reads
// the object's vtable pointer and tail-jumps to the virtual that lives at
// vtable offset 0xbc, forwarding its own 4-byte stack argument IN PLACE.
//
// Forwarding the argument in place is what keeps the frame frameless and puts
// the jump target in EAX (a forward with no forwarded argument would use EDX).
//
// The 47 dummy virtuals only place the forwarded virtual at vtable offset 0xbc:
// the first virtual of a class sits at vptr+0, so offset 0xbc is the 48th slot.

struct bhkConvexShape {
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
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC(int arg);
};

struct bhkConvexSweepShape : public bhkConvexShape {
    void __thiscall FUN_00ccf560(int arg);
};

// @fnv 0x00ccf560
// pdb: bhkConvexSweepShape::Init | bhkConvexSweepShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: CreateNS_bhkConvexSweepShape::Create)
// pdb params: arInfo
void __thiscall bhkConvexSweepShape::FUN_00ccf560(int arg) {
    v0BC(arg);
}

namespace fnv_00ccf5d0 {
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern "C" void __cdecl FUN_00c87c30();
extern "C" char DAT_01030bf4[];
extern "C" char DAT_01030b0c[];
extern "C" char DAT_01030a24[];
extern "C" char DAT_010caaf4[];
extern "C" int DAT_012680f8;
extern "C" int DAT_01268274;
extern "C" int DAT_01268250;

struct PackedObj {
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void ctorBase();
    PackedObj() {
        ctorBase();
        m_vtbl = (void*)DAT_01030bf4;
        unk0C = 0;
        unk10 = 0;
        unsigned int count = 1;
        DAT_012680f8 += count;
        m_vtbl = (void*)DAT_01030b0c;
        DAT_01268274 += count;
        m_vtbl = (void*)DAT_01030a24;
        DAT_01268250 += count;
        m_vtbl = (void*)DAT_010caaf4;
    }
    void* operator new(unsigned int size) throw() { return FUN_00aa13e0(size); }
};

// Allocates and constructs a PackedObj, returning the new object pointer.
// @fnv 0x00ccf5d0
// pdb: bhkConvexSweepShape::CreateObject | bhkConvexSweepShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void* __cdecl CreatePackedObj() {
    PackedObj* p = new PackedObj();
    return p;
}
}  // namespace fnv_00ccf5d0

extern int DAT_012686c4;

// @fnv 0x00ccf7b0
// pdb: bhkPlaneShape::GetRTTI | bhkPlaneShape.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|udata), high
void* __cdecl bhkPlaneShape_GetRTTI()
{
    return &DAT_012686c4;
}

// FUN_00ccf810: thiscall, 21 bytes, 2 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x38] / jmp eax / end: ret 8
// Forwards the two stack arguments to virtual slot 0x38 of the object
// pointed to by the member at this+8.
struct Target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void Tail(int a, int b);
};

namespace fnv_00ccf830 {
// DispatchTail: thiscall, 21 bytes, 3 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x3c] / jmp eax / end: ret 0xc
// Forwards the three stack arguments to virtual slot 0x3c of the object
// pointed to by the member at this+8.
struct Target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void Tail(int a, int b, int c);
};

}  // namespace fnv_00ccf830

namespace fnv_00ccf850 {
// FUN_00ccf850: thiscall, 21 bytes, 1 stack arg.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x34] / jmp eax / end: ret 4
// Forwards the stack argument to virtual slot 0x34 of the object pointed to
// by the member pointer at this+8.
struct Target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void Tail(int a);
};

}  // namespace fnv_00ccf850

struct Link {
    void* m_type;
    unsigned int m_flags;
    void* m_object;
};
struct RefObject {
    void** m_ppVirtualMethodTable;
    unsigned int m_flags;
    Link* m_link;
};
struct LinkCollection {
    unsigned int m_type;
    unsigned int m_flags;
    unsigned int m_pRayCursor;
    unsigned int m_generation;
    Link** m_ppLinks;
    int m_uiItemCount;
};
struct Owner {
    void** m_ppVirtualMethodTable;
    void __thiscall bhkShape_CopyMembers(void* item, void* key);
    void __thiscall FUN_00ccf900(void* item, void* key);
};
typedef LinkCollection* (__thiscall *AcquireLinks)(Owner*, unsigned char*);
typedef bool (__thiscall *CheckRef)(RefObject*, void*);
typedef RefObject* (__thiscall *FindRef)(RefObject*, void*);

struct FNVCountInterface {
    virtual void Reserved();
    virtual unsigned int GetCount();
};

struct FNVNotificationReceiver {
    virtual void Reserved00();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Notify(int context);
};

struct FNVNotificationEntry {
    void* m_unknown00;
    void* m_unknown04;
    FNVNotificationReceiver* m_receiver;
};

struct FNVNotificationCollection {
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    FNVCountInterface m_countInterface;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    unsigned int m_unknown3c;
    unsigned int m_unknown40;
    FNVNotificationEntry** m_entries;
};

struct FNVNotificationOwner {
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    FNVNotificationCollection* m_pShapeCollection;
    void NotifyAllReceivers(int context);
    void FUN_00aa0ad0(int context);
};

// Calls Notify(context) on each non-null receiver in the collection's entries, then calls FUN_00aa0ad0(context).
// @fnv 0x00ccf990
// pdb: bhkConvexListShape::RegisterStreamables | bhkConvexListShape.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: arStream
void FNVNotificationOwner::NotifyAllReceivers(int context)
{
    unsigned int count;
    FNVNotificationCollection* collection;
    if (this && (collection = m_pShapeCollection))
        count = collection->m_countInterface.GetCount();
    else
        count = 0;
    for (unsigned int index = 0; index < count; ++index) {
        if (this && m_pShapeCollection) {
            FNVNotificationEntry* entry = m_pShapeCollection->m_entries[index];
            if (entry) {
                FNVNotificationReceiver* receiver = entry->m_receiver;
                if (receiver)
                    receiver->Notify(context);
            }
        }
    }
    FUN_00aa0ad0(context);
}

class CCFA00RefObject {
public:
    virtual ~CCFA00RefObject();

    unsigned int m_uiRefCount;

    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
};

struct CCFA00Entry {
    int unk00;
    int unk04;
    CCFA00RefObject* m_pPointer;
};

class CCFA00List {
public:
    virtual void vfunc00();
    virtual int GetSize();
};

struct CCFA00Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    CCFA00List m_kList;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34;
    int unk38; int unk3C; int unk40;
    CCFA00Entry** m_ppkEntries;
};

class CCFA00Holder {
public:
    int unk00;
    int unk04;
    CCFA00Data* m_pUserData;

    void IncRefCountAllEntries();
};

// If the holder's data is valid, iterates its entries and increments the reference count of each entry's referenced object.
// @fnv 0x00ccfa00
// pdb: bhkConvexListShape::RembhkShapeRef | bhkConvexListShape.obj | fnv360_0721_beta, objrun_prop, low, conflict (bridge: bhkConvexListShape::AddbhkShapeRef)
void CCFA00Holder::IncRefCountAllEntries()
{
    CCFA00Data* pkData;
    if (this && (pkData = m_pUserData) != 0) {
        int i = pkData->m_kList.GetSize();
        while (i) {
            i--;
            if (m_pUserData) {
                CCFA00Entry* pkEntry = m_pUserData->m_ppkEntries[i];
                if (pkEntry && pkEntry->m_pPointer)
                    pkEntry->m_pPointer->IncRefCount();
            }
        }
    }
}

struct ObjC;

struct ObjD {
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(int p1, int p2);
};

struct ObjC {
    unsigned int unk00;
    unsigned int unk04;
    ObjD* m_08;
};

struct ItemFlags {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int flags;
};
struct ItemEntry {
    unsigned int unk00;
    unsigned int unk04;
    ItemFlags* details;
};
struct CountProvider {
    virtual void unused();
    virtual unsigned int LastIndex();
};
struct ItemContainer {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    CountProvider counter;
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
    ItemEntry** entries;
};
struct ItemCollection {
    unsigned int unk00;
    unsigned int unk04;
    ItemContainer* container;
    unsigned int unk0c;
    unsigned int defaultFlags;
    unsigned int __thiscall GetItemFlags(unsigned int index);
};
// @fnv 0x00ccfb40
unsigned int ItemCollection::GetItemFlags(unsigned int index) {
    if (index != 0xffffffffu) {
        unsigned int lastIndex;
        if (this != 0) {
            ItemContainer* pContainer = container;
            if (pContainer != 0)
                lastIndex = pContainer->counter.LastIndex();
            else
                lastIndex = 0;
        } else
            lastIndex = 0;
        if (index <= lastIndex && this != 0 && container != 0) {
            ItemEntry* entry = container->entries[index];
            if (entry != 0 && entry->details != 0)
                return entry->details->flags & 0x1f;
        }
    }
    return defaultFlags & 0x1f;
}

namespace fnv_00ccfba0 {
struct TlsBlock_b9412 {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock_b9412 g_tls;

void* __cdecl FUN_00aa13e0(unsigned int size);
void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();

struct SpawnedObj_b9412 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedObj_b9412();
    static void* operator new(unsigned int size) throw() { return FUN_00aa13e0(size); }
};

struct TlsGuard_b9412 {
    unsigned int m_saved;
    TlsGuard_b9412() { m_saved = g_tls.m_2b4; g_tls.m_2b4 = 0x10; }
    ~TlsGuard_b9412() { g_tls.m_2b4 = m_saved; }
};

}  // namespace fnv_00ccfba0

namespace fnv_00ccfc60 {
struct CCFAllocator {
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct CCFMemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CCFAllocator* m_pStreamAllocator;

    CCFAllocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CCFMemoryRouter& __cdecl FUN_00c85750();

extern __declspec(thread) int g_CCFAllocTag;

struct CCFAllocTagScope {
    int m_iSaved;

    CCFAllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCFAllocTag;
        g_CCFAllocTag = aiAllocationTag;
    }
    ~CCFAllocTagScope() { g_CCFAllocTag = m_iSaved; }
};

class hkReferencedObjectCCF {
public:
    virtual ~hkReferencedObjectCCF();
    void removeReference();

    static void* operator new(unsigned int uiSize) {
        void* p = FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        static_cast<hkReferencedObjectCCF*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

}  // namespace fnv_00ccfc60

namespace fnv_00ccfd40 {
struct NodeRelease_tls {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int m_2b4;
};
extern __declspec(thread) NodeRelease_tls g_tls;

struct NodeRelease_guard {
    unsigned int m_saved;
    NodeRelease_guard() {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~NodeRelease_guard() {
        g_tls.m_2b4 = m_saved;
    }
};

class NodeRelease_sub {
public:
    virtual void vfn_0();
    virtual int vfn_4();
};

class NodeRelease_ref {
public:
    virtual void vfn_0();
    virtual void vfn_4();
    long m_04;
};

struct NodeRelease_node {
    unsigned int unk00;
    unsigned int unk04;
    NodeRelease_ref* m_08;
};

struct NodeRelease_mgr {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    NodeRelease_sub m_14;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    NodeRelease_node** m_44;
};

class NodeRelease_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    NodeRelease_mgr* m_08;
    void ReleaseAllNodes();
};

// Decrements the reference count of each node's ref in m_08's m_44 array and calls its vfn_4 when the count reaches zero.
// @fnv 0x00ccfd40
void NodeRelease_cls::ReleaseAllNodes() {
    NodeRelease_guard guard;
    if (this != 0) {
        NodeRelease_mgr* mgr = m_08;
        if (mgr != 0) {
            int i = mgr->m_14.vfn_4();
            if (i != 0) {
                do {
                    --i;
                    mgr = m_08;
                    if (mgr != 0) {
                        NodeRelease_node* node = mgr->m_44[i];
                        if (node != 0) {
                            NodeRelease_ref* ref = node->m_08;
                            if (ref != 0) {
                                if (InterlockedDecrement((volatile long*)&ref->m_04) == 0) {
                                    ref->vfn_4();
                                }
                            }
                        }
                    }
                } while (i != 0);
            }
        }
    }
}
}  // namespace fnv_00ccfd40

namespace fnv_00cd0480 {
extern __declspec(thread) int g_tlsMemContext;
class ContextScope {
 int previous;
public:
 ContextScope() { previous = g_tlsMemContext; g_tlsMemContext = 16; }
 ~ContextScope() { g_tlsMemContext = previous; }
};
inline void Add(StrArr* array,char* value) {
 unsigned int index = array->m_usElementCount;
 if(index >= array->m_usSize) array->SetSize(index+array->m_usIncrement);
 array->SetAt(index,value);
}
struct CountInterface { virtual void unused(); virtual int count(); };
struct CountObject { int unk00,unk04,unk08,unk0c,unk10; CountInterface value; };
extern char* DAT_012686c4;
char* FUN_00a7d330(char*);
struct ListOwner {
 int unk00,unk04; CountObject* object;
 void FUN_00c9fc50(StrArr*);
 void AppendCountInfo(StrArr*);
 static int GetCount(ListOwner* p) {
 CountObject* o = p ? p->object : 0;
 return o ? o->value.count() : 0;
 }
};
}  // namespace fnv_00cd0480

extern void __cdecl FUN_00c908c0(void* allocator, void* array, int newCapacity, int elementSize);
extern void __cdecl FUN_00d2cc70(void* dest, const void* src, unsigned int byteCount);

// FUN_00cd3b00 : an empty __stdcall function with four arguments.
// MSVC emits only the stack cleanup: ret 0x10.
// @fnv 0x00cd3b00
void __stdcall FUN_00cd3b00(int a, int b, int c, int d) {
}

// FUN_00cd3c80: constant return 6
// @fnv 0x00cd3c80
// pdb: CombatProcedureMove::GetType | CombatProcedureMove.obj | fnv360_0822_retail, vtable, high
int __cdecl FUN_00cd3c80()
{
    return 6;
}

extern int DAT_010cb344;

struct FUN_00cd3c90_cls
{
    void* m_pVtable;
    unsigned short m_uiValue1;
    unsigned short m_uiUnk;

    void* FUN_00cd3c90();
};

// @fnv 0x00cd3c90
// pdb: bhkCharacterStateProjectile::bhkCharacterStateProjectile | bhkCharacterStateProjectile.obj | fnv360_0822_retail, call_gap, low
void* FUN_00cd3c90_cls::FUN_00cd3c90()
{
    m_uiUnk = 1;
    m_pVtable = (void*)&DAT_010cb344;
    return this;
}

extern float DAT_01013970;

struct SpawnedObjectBase
{
    unsigned short m_unk00;
    unsigned short m_unk02;
    float m_unk04;

    SpawnedObjectBase()
    {
        m_unk04 = DAT_01013970;
        m_unk02 = 1;
    }
};

struct bhkCharacterStateInAir : SpawnedObjectBase // src: F3_EXE vtable 0x00e7c6a4 (old: FUN_00cd3f90)
{
    virtual void Unk00();

    bhkCharacterStateInAir();
};

// @fnv 0x00cd3f90
// pdb: bhkCharacterStateInAir::bhkCharacterStateInAir | bhkCharacterStateInAir.obj | fnv360_0822_retail, callee_sim, low
bhkCharacterStateInAir::bhkCharacterStateInAir()
{
}

extern char DAT_010cb398[];

struct FUN_00cd4260_cls {
    void* m_vptr;
    unsigned short unk04;
    unsigned short m_w06;

    FUN_00cd4260_cls* FUN_00cd4260();
};

// @fnv 0x00cd4260
// pdb: bhkCharacterStateJumping::bhkCharacterStateJumping | bhkCharacterStateJumping.obj | fnv360_0822_retail, call_gap_sim, low
FUN_00cd4260_cls* FUN_00cd4260_cls::FUN_00cd4260()
{
    m_w06 = 1;
    m_vptr = DAT_010cb398;
    return this;
}

namespace fnv_00cd7d60 {
struct TlsMemBlock {
    int unk000; int unk004; int unk008; int unk00c;
    int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c;
    int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c;
    int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c;
    int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c;
    int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac;
    int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc;
    int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec;
    int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c;
    int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c;
    int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c;
    int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c;
    int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c;
    int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac;
    int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc;
    int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec;
    int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c;
    int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c;
    int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c;
    int unk250; int unk254; int unk258; int unk25c;
    int unk260; int unk264; int unk268; int unk26c;
    int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c;
    int unk290; int unk294; int unk298; int unk29c;
    int unk2a0; int unk2a4; int unk2a8; int unk2ac;
    int unk2b0;
    int m_iTrailingValue;
};
extern __declspec(thread) TlsMemBlock g_tlsMem;

struct MemClassGuard {
    int saved;
    MemClassGuard(int cls) { saved = g_tlsMem.m_iTrailingValue; g_tlsMem.m_iTrailingValue = cls; }
    ~MemClassGuard() { g_tlsMem.m_iTrailingValue = saved; }
};

struct ChunkAllocator {
    virtual void unk00();
    virtual void* allocateChunk(int size);
    virtual void freeChunk(void* p, int size);
};
struct MemHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ChunkAllocator* allocator;
    void* allocateChunk(int n) { return allocator->allocateChunk(n); }
    void freeChunk(void* p, int n) { allocator->freeChunk(p, n); }
};
MemHolder* GetMemHolder();

struct ShapeData {
    int data;
    int count;
    int stride;
};
struct ShapeParam {
    int unk00;
    float radius;
    int data;
    int count;
    int unk10;
    int extra;
};

struct RefObject {
    void* vtbl;
    unsigned short GetAllocationSize;
    short refCount;
    void removeReference();
    static void* operator new(unsigned int size) {
        RefObject* b = static_cast<RefObject*>(GetMemHolder()->allocateChunk(size));
        b->GetAllocationSize = static_cast<unsigned short>(size);
        return b;
    }
    static void operator delete(void* p, unsigned int size) {
        GetMemHolder()->freeChunk(p, size);
    }
};

struct ShapeBase : RefObject {
    int unk08;
    int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    ShapeBase(const ShapeData& d, int* extra, float radius);
};

extern void* ShapeDerived_vftable;
struct ShapeDerived : ShapeBase {
    ShapeDerived(const ShapeData& d, int* extra, float radius) : ShapeBase(ShapeData(d), extra, radius) {
        vtbl = &ShapeDerived_vftable;
    }
};

struct ShapeOwner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void SetShape(RefObject* shape);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void ApplyParam(ShapeParam* p);
    void CreateShapeAndApplyParam(ShapeParam* p);
};

// Builds a ShapeDerived from the ShapeParam's data, count, radius and extra, sets it on the owner, releases the reference, then applies the param.
// @fnv 0x00cd7d60
void ShapeOwner::CreateShapeAndApplyParam(ShapeParam* apParam) {
    MemClassGuard guard(0x10);
    ShapeData d;
    d.count = apParam->count;
    d.stride = 0x10;
    d.data = apParam->data;
    ShapeDerived* shape = new ShapeDerived(d, &apParam->extra, apParam->radius);
    SetShape(shape);
    shape->removeReference();
    ApplyParam(apParam);
}
}  // namespace fnv_00cd7d60

namespace fnv_00cd7e80 {
extern unsigned int DAT_012680f8;
extern unsigned int DAT_01268274;
extern unsigned int DAT_01268250;
extern unsigned int DAT_0126869c;

struct FUN_00c87c30_owner {
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct ChainA_cls : public FUN_00c87c30_owner {
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls() {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        DAT_01268274 += 1;
    }
};

struct ChainC_cls : public ChainB_cls {
    virtual void unkC2();
    ChainC_cls() {
        DAT_01268250 += 1;
    }
};

struct ChainD_cls : public ChainC_cls {
    virtual void unkD3();
    ChainD_cls() {
        DAT_0126869c += 1;
    }
};

struct FUN_00cd7e80 : public ChainD_cls {
    virtual void unkE4();
    void CreateShapeAndApplyParam(unsigned int a);
    FUN_00cd7e80(unsigned int a);
};

// Runs CreateShapeAndApplyParam with a, then increments DAT_0126869c.
// @fnv 0x00cd7e80
// pdb: bhkCharControllerShape::bhkCharControllerShape | bhkCharControllerShape.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: arInfo
FUN_00cd7e80::FUN_00cd7e80(unsigned int auiValue) {
    CreateShapeAndApplyParam(auiValue);
    DAT_0126869c += 1;
}
}  // namespace fnv_00cd7e80

extern int DAT_012686e8;

// @fnv 0x00cd7f20
// pdb: bhkExtendedMeshShape::GetRTTI | bhkExtendedMeshShape.obj | fnv360_0822_retail, udata, high
int* __cdecl bhkExtendedMeshShape_GetRTTI()
{
    return &DAT_012686e8;
}

namespace fnv_00cd8820 {
extern "C" unsigned int DAT_01267e30;
extern "C" unsigned int DAT_01267e34;
extern "C" unsigned int DAT_01267e38;
extern "C" unsigned int DAT_01267e3c;

}  // namespace fnv_00cd8820

// FUN_00cd9ed0 : sets a byte flag through its first argument.
//   mov eax,[esp+4] / mov byte ptr [eax],1 / ret 8
// @fnv 0x00cd9ed0
// pdb: ahkpWorld::setUserData | bhkWorld.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: bhkWorld::QInitGroupDuringAdd)
// pdb params: apData
void __stdcall FUN_00cd9ed0(unsigned char* flag, int unused) {
    *flag = 1;
}

struct hkMemoryAllocator;

struct NineIntegerRecord {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};

NineIntegerRecord& __cdecl GetMemoryRouter();

struct HavokArrayUtilities {
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& alloc, void* array, int capacity, int elemSize);
};

struct RouterHeapAllocatorProvider {
    hkMemoryAllocator& get() { return GetMemoryRouter().heap(); }
};

template <class T>
struct hkArr {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void GrowArrayCapacity(hkMemoryAllocator& alloc, int n) {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = cap * 2;
            int newSize = n < cap2 ? cap2 : n;
            HavokArrayUtilities::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
        }
    }

    void _setSize(hkMemoryAllocator& alloc, int n) {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }

    void _setSize(hkMemoryAllocator& alloc, int n, T fill) {
        GrowArrayCapacity(alloc, n);
        int num = n - m_iElementCount;
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < num; i++) {
            p[i] = fill;
        }
        m_iElementCount = n;
    }

    void _reserveExactly(hkMemoryAllocator& alloc, int n) {
        if (getCapacity() < n) {
            HavokArrayUtilities::GrowArrayCapacity(alloc, this, n, sizeof(T));
        }
    }

    void SetSizeAndGrow(int n) { _setSize(RouterHeapAllocatorProvider().get(), n); }
    void SetSizeAndGrow(int n, T fill) { _setSize(RouterHeapAllocatorProvider().get(), n, fill); }
    void reserveExactly(int n) { _reserveExactly(RouterHeapAllocatorProvider().get(), n); }
};

struct S_00cdb2f0_Arr {
    int* data;
    int size;
    unsigned int cap;
    S_00cdb2f0_Arr() : data(0), size(0), cap(0x80000000) {}
};

class FUN_00cdb3d0_cls {
public:
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
	int m_28;
	void FUN_00cdb3d0(int value);
};

// @fnv 0x00cdb3d0
void FUN_00cdb3d0_cls::FUN_00cdb3d0(int value)
{
	m_28 = value;
}

namespace fnv_00cdb6f0 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00cdb6f0

namespace fnv_00cde880 {
struct FUN_00cde880_cls {
    unsigned short* m_data;
    int m_len;
    unsigned int m_cap;

    void ReplaceRange(void* owner, int pos, int nRemove, const unsigned short* src, int nInsert);
};

extern "C" void __cdecl FUN_00c908c0(void* owner, FUN_00cde880_cls* buf, int newCap, int stride);
extern "C" void __cdecl FUN_00d2cc70(void* dst, const void* src, unsigned int bytes);

}  // namespace fnv_00cde880

struct FUN_00cdea80_cls {
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
    int m_e8;
    int FUN_00cdea80();
};

// @fnv 0x00cdea80
// pdb: MiddleHighProcess::GetRunOnceProcedureIndex | HighProcess.obj | fnv360_0822_retail, objrun_open, low
int FUN_00cdea80_cls::FUN_00cdea80() {
    return m_e8;
}

class FUN_00cdeaa0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int m_iE4;
    unsigned int FUN_00cdeaa0();
};
// @fnv 0x00cdeaa0
// pdb: BSTreeNode::GetModel | BSTreeNode.obj | fnv360_0822_retail, vtable, medium
unsigned int FUN_00cdeaa0_cls::FUN_00cdeaa0() { return m_iE4; }

struct FUN_00cdeac0_cls {
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
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char m_bA2;
    unsigned char* __thiscall FUN_00cdeac0(unsigned char* pOut);
};

// @fnv 0x00cdeac0
// pdb: hkpRagdollConstraintData::getConstraintFrameA | hkpRagdollConstraintData.obj | fnv360_0822_debug, objrun_sim, low
// pdb params: constraintFrameA
unsigned char* FUN_00cdeac0_cls::FUN_00cdeac0(unsigned char* pOut)
{
    *pOut = m_bA2;
    return pOut;
}

class RefObj {
public:
    RefObj() { m_sReferenceCount = 1; }
    virtual void v0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

class RangeBase : public RefObj {
public:
    RangeBase() { m_bEnableState = false; }
    virtual void v0();
    struct HkBool { char m_cBooleanValue; HkBool() {} HkBool(bool b) { m_cBooleanValue = (char)b; } HkBool& operator=(bool b) { m_cBooleanValue = (char)b; return *this; } } m_bEnableState;
};

class FUN_00cdf560 : public RangeBase {
public:
    FUN_00cdf560(int iUnused);
    virtual void v0();
    float m_fMinimum;
    float m_fMaximum;
    float m_fFactor;
    float m_fScaleA;
    float m_fExponent;
    float m_fScaleB;
};

// Initializes the range bounds to -1000000 and 1000000, enables the range flag, and sets factor, scale and exponent defaults.
// @fnv 0x00cdf560
// pdb: hkpPositionConstraintMotor::hkpPositionConstraintMotor | hkpPositionConstraintMotor.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: currentPosition
FUN_00cdf560::FUN_00cdf560(int iUnused)
{
    m_fMinimum = -1000000.0f;
    m_fMaximum = 1000000.0f;
    m_bEnableState = true;
    m_fFactor = 0.8f;
    m_fScaleA = 1.0f;
    m_fScaleB = 1.0f;
    m_fExponent = 2.0f;
}

struct CDF760FinishFlag {
    int m_bFinishing;
};

struct CDF760Member {
    int unk00;
    int unk04;
    void* m_pvOwner;

    void FUN_00d21ce0(void* pvOwner);

    CDF760Member(CDF760FinishFlag flag) {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_pvOwner);
    }
};

extern __declspec(thread) int g_iCC2950AllocTag;

struct BCC2950AllocTagScope {
    int m_iSaved;

    BCC2950AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC2950AllocTag;
        g_iCC2950AllocTag = aiAllocationTag;
    }
    ~BCC2950AllocTagScope() { g_iCC2950AllocTag = m_iSaved; }
};

class BCC2950StringArray {
public:
    virtual ~BCC2950StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl FUN_00a7d330(const char* pcString);

struct S_arg
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00C;
    unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01C;
    unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02C;
    unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03C;
    unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04C;
    unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05C;
    unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06C;
    unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07C;
    unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08C;
    unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09C;
    unsigned int unk0A0; unsigned int unk0A4; unsigned int unk0A8; unsigned int unk0AC;
    unsigned int unk0B0; unsigned int unk0B4; unsigned int unk0B8; unsigned int unk0BC;
    unsigned int unk0C0; unsigned int unk0C4; unsigned int unk0C8; unsigned int unk0CC;
    unsigned int unk0D0; unsigned int unk0D4; unsigned int unk0D8; unsigned int unk0DC;
    unsigned int unk0E0; unsigned int unk0E4; unsigned int unk0E8; unsigned int unk0EC;
    unsigned int unk0F0; unsigned int unk0F4; unsigned int unk0F8; unsigned int unk0FC;
    unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10C;
    unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11C;
    unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12C;
    unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13C;
    unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14C;
    unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15C;
    unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16C;
    unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17C;
    unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18C;
    unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19C;
    unsigned int unk1A0; unsigned int unk1A4; unsigned int unk1A8; unsigned int unk1AC;
    unsigned int unk1B0; unsigned int unk1B4; unsigned int unk1B8; unsigned int unk1BC;
    unsigned int unk1C0; unsigned int unk1C4; unsigned int unk1C8; unsigned int unk1CC;
    unsigned int unk1D0; unsigned int unk1D4; unsigned int unk1D8; unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1E5;
};

struct S_res
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
};

class C
{
public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0A();
    virtual void* v0B();
    virtual void* v0C();
    virtual void* v0D();
    virtual void* v0E();
    virtual void* v0F();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1A();
    virtual void* v1B();
    virtual void* v1C();
    virtual void* v1D();
    virtual void* v1E();
    virtual void* v1F();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v2A();
    virtual void* v2B();
    virtual void* v2C();
    virtual S_res* v45(S_arg** out);
    void FUN_00c8a7a0(S_arg* arg);
    void ProcessAndByteSwapResult(S_arg* arg);
};

struct CC3840Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    float m_fSpinRate;
    float m_fGain;
};

class CC3840Base {
public:
    void CollectBaseNames(BCC1F80StringArray* pkArray);
};

class CC3840Node : public CC3840Base {
public:
    int unk00;
    int unk04;
    CC3840Data* m_pUserData;

    static float GetSpinRate(CC3840Node* p) { return (p && p->m_pUserData) ? p->m_pUserData->m_fSpinRate : 0.0f; }
    static float GetGain(CC3840Node* p) { return (p && p->m_pUserData) ? p->m_pUserData->m_fGain : 0.0f; }
    void FUN_00cc3840(BCC1F80StringArray* pkArray);
};

struct BinaryInput {
 int unk00; unsigned int position;
 unsigned int (__cdecl* reader)(BinaryInput*,void*,unsigned int,unsigned int*,unsigned int);
 void Read(void* dst,unsigned int size) {
  unsigned int componentSize=size;
  position+=reader(this,dst,size,&componentSize,1);
 }
};
struct LoadStream {
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
int unk138;
int unk13c;
int unk140;
int unk144;
int unk148;
int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
int unk170;
int unk174;
int unk178;
int unk17c;
int unk180;
int unk184;
int unk188;
int unk18c;
int unk190;
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
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
BinaryInput* input;
};

// Lazily create the Havok helper object; report the object size.

extern __declspec(thread) int g_iCC5AE0AllocTag;

struct CC5AE0AllocTagScope {
    int m_iSaved;

    CC5AE0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC5AE0AllocTag;
        g_iCC5AE0AllocTag = aiAllocationTag;
    }
    ~CC5AE0AllocTagScope() { g_iCC5AE0AllocTag = m_iSaved; }
};

struct CC5AE0Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct CC5AE0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC5AE0Allocator* m_pStreamAllocator;

    CC5AE0Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CC5AE0MemoryRouter& __cdecl CC5AE0GetMemoryRouter();

class CC5AE0Helper {
public:
    CC5AE0Helper();
    virtual ~CC5AE0Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC5AE0Helper* p = static_cast<CC5AE0Helper*>(CC5AE0GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes) { CC5AE0GetMemoryRouter().heap().ReleaseBlock(p, nbytes); }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};

struct CC61F0BinaryStream {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(CC61F0BinaryStream* pThis, void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T> inline void CC61F0LoadBinary(CC61F0BinaryStream& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct CC61F0Stream {
    void* m_pVtable;
    unsigned int m_uiNifVersion;
    int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024;
    int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044;
    int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064;
    int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084;
    int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4;
    int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4;
    int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4;
    int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104;
    int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124;
    int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144;
    int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164;
    int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180; int unk184;
    int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4;
    int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4;
    int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0; unsigned char unk1E4; unsigned char m_bLittleEndian; unsigned short unk1E6;
    int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204;
    int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220; int unk224;
    int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240; int unk244;
    int unk248;
    CC61F0BinaryStream* m_pUnderlyingStream;
};
struct CC61F0Vector4 { float x; float y; float z; float w; };
struct CC61F0Rotation { CC61F0Vector4 m_kColumn0; CC61F0Vector4 m_kColumn1; CC61F0Vector4 m_kColumn2; };
void __cdecl CC61F0SwapRotation(CC61F0Rotation* pkRotation);
struct CC61F0ConstraintData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    CC61F0Rotation m_kRotA;
    CC61F0Rotation m_kRotB;
    int unk80; int unk84;
    float m_f88;
    float m_f8C;
    int unk90; int unk94; int unk98; int unk9C;
    float m_fA0;
    int unkA4; int unkA8; int unkAC;
    float m_fB0;
    float m_fB4;
};
struct CC61F0ConstraintBase {
    int unk00;
    CC61F0ConstraintData* m_pUserData;
    void LoadBinaryBase(CC61F0Stream& kStream);
};
struct FUN_00cc61f0_class : CC61F0ConstraintBase {
    void FUN_00cc61f0(CC61F0Stream& kStream);
};

// Loads the base constraint data, reads two rotations (byte-swapping them if the stream is not little-endian) and five floats into the constraint data.
// @fnv 0x00cc61f0
// pdb: hkRagdollLimitsConstraintCinfo::LoadBinary | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arStream
void FUN_00cc61f0_class::FUN_00cc61f0(CC61F0Stream& kStream)
{
    LoadBinaryBase(kStream);
    CC61F0ConstraintData* pkData = m_pUserData;
    kStream.m_pUnderlyingStream->Read(&pkData->m_kRotA, sizeof(CC61F0Rotation));
    kStream.m_pUnderlyingStream->Read(&pkData->m_kRotB, sizeof(CC61F0Rotation));
    if (kStream.m_bLittleEndian != 1) {
        CC61F0SwapRotation(&pkData->m_kRotA);
        CC61F0SwapRotation(&pkData->m_kRotB);
    }
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_fA0);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_fB0);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_fB4);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_f88);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_f8C);
}

struct CC63E0_Stream {
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    unsigned int (__cdecl *m_write)(CC63E0_Stream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count) {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct CC63E0_Context {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC;
    int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0;
    unsigned char m_1e4; unsigned char unk1E5; unsigned char unk1E6; unsigned char unk1E7;
    int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C;
    CC63E0_Stream* m_stream;
};
struct CC63E0_Block {
    float m00; float m04; float m08; float m0C; float m10; float m14; float m18; float m1C; float m20; float m24; float m28; float m2C;
};
struct CC63E0_Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    CC63E0_Block m_20;
    CC63E0_Block m_50;
    int unk80; int unk84;
    int m_88; int m_8C;
    int unk90; int unk94; int unk98; int unk9C;
    int m_A0; int unkA4; int unkA8; int unkAC;
    int m_B0; int m_B4;
};
void __cdecl CC63E0_SwapBlock(CC63E0_Block* b);
struct CC63E0_Obj {
    void* m_ppVirtualMethodTable;
    CC63E0_Data* m_data;
    void SaveBase(CC63E0_Context* ctx);
    void FUN_00cc63e0(CC63E0_Context* ctx);
};
// @fnv 0x00cc63e0
void CC63E0_Obj::FUN_00cc63e0(CC63E0_Context* ctx)
{
    SaveBase(ctx);
    CC63E0_Data* d = m_data;
    if (ctx->m_1e4 != 1) {
        CC63E0_SwapBlock(&d->m_20);
        CC63E0_SwapBlock(&d->m_50);
    }
    ctx->m_stream->Write(&d->m_20, 0x30);
    ctx->m_stream->Write(&d->m_50, 0x30);
    ctx->m_stream->Write(&d->m_A0, 4);
    ctx->m_stream->Write(&d->m_B0, 4);
    ctx->m_stream->Write(&d->m_B4, 4);
    ctx->m_stream->Write(&d->m_88, 4);
    ctx->m_stream->Write(&d->m_8C, 4);
    if (ctx->m_1e4 != 1) {
        CC63E0_SwapBlock(&d->m_20);
        CC63E0_SwapBlock(&d->m_50);
    }
}

struct __declspec(novtable) ReferenceRoot78 {
    unsigned int unk04;
    unsigned int unk08;
    static void* __cdecl operator new(unsigned int size);
    static void __cdecl operator delete(void*);
    virtual ~ReferenceRoot78();
    void Initialize();
    ReferenceRoot78() { Initialize(); }
};
struct ConstraintBase78 : ReferenceRoot78 {
    unsigned int data;
    ConstraintBase78() { data = 0; ++DAT_01268188; }
    virtual ~ConstraintBase78();
};
struct Constraint78 : ConstraintBase78 {
    Constraint78() { ++DAT_0126860c; }
    virtual ~Constraint78();
};

// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.

extern __declspec(thread) int g_iCC69D0AllocTag;

struct CC69D0AllocTagScope {
    int m_iSaved;

    CC69D0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC69D0AllocTag;
        g_iCC69D0AllocTag = aiAllocationTag;
    }
    ~CC69D0AllocTagScope() { g_iCC69D0AllocTag = m_iSaved; }
};

class CC69D0RefObject {
public:
    CC69D0RefObject();
    virtual ~CC69D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};

class CC69D0Shape : public CC69D0RefObject {
public:
    CC69D0Shape() : m_pUserData(0) { ++ms_iCount; }
    virtual ~CC69D0Shape();

    void* m_pUserData;

    static int ms_iCount;
};

class CC69D0ListShape : public CC69D0Shape {
public:
    CC69D0ListShape() { ++ms_iCount; }
    virtual ~CC69D0ListShape();

    static int ms_iCount;
};

extern int DAT_010c8ce4;

struct Child_00cc6ab0
{
    void* m_pVtable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    static void* operator new(unsigned int, void* p) { return p; }

    Child_00cc6ab0()
        : m_08(1), m_0c(0), m_10(0)
    {
        m_pVtable = &DAT_010c8ce4;
        m_04 = 0;
    }
};

struct CC77E0Allocator {
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct CC77E0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC77E0Allocator* m_pStreamAllocator;

    CC77E0Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CC77E0MemoryRouter& __cdecl hkMemoryRouterCC77();

extern __declspec(thread) int g_CC77E0AllocTag;

struct CC77E0AllocTagScope {
    int m_iSaved;

    CC77E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CC77E0AllocTag;
        g_CC77E0AllocTag = aiAllocationTag;
    }
    ~CC77E0AllocTagScope() { g_CC77E0AllocTag = m_iSaved; }
};

class CC77E0Child {
public:
    CC77E0Child();
    virtual ~CC77E0Child();

    static void* operator new(unsigned int uiSize) {
        void* p = hkMemoryRouterCC77().heap().AllocateMemoryBlock(uiSize);
        static_cast<CC77E0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC;
};

struct NiBinaryStream {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents) {
        unsigned int uiWritten = m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};
struct NiStreamView {
    char pad[0x250];
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void WriteBinaryArray(NiBinaryStream& kBinStream, const T* pValue, unsigned int uiNumEls) {
    unsigned int uiSize = sizeof(T);
    kBinStream.Write(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStreamView& kStream, const T& kValue) {
    WriteBinaryArray(*kStream.m_pBackingStream, &kValue, 1);
}
struct SaveMatrix { float m[16]; };
struct SaveData {
    char pad00[0x20];
    SaveMatrix kFirst;
    SaveMatrix kSecond;
    char pad60[2];
    bool bFlag;
    char padA3[9];
    void* pLinked;
    char padB0[4];
    unsigned int uiB4;
    char padB8[0x10];
    unsigned int uiC8;
    unsigned int uiCC;
};
struct FUN_00cc7bc0_shell {
    void* m_pVtable;
    SaveData* m_pData;
    void FUN_00c8a280(NiStreamView& kStream);
    void SaveShape(void* pLinked, NiStreamView& kStream);
    void FUN_00cc7bc0(NiStreamView& kStream);
};
// @fnv 0x00cc7bc0
// pdb: hkPrismaticConstraintCinfo::SaveBinary | bhkPrismaticConstraint.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: arStream
void FUN_00cc7bc0_shell::FUN_00cc7bc0(NiStreamView& kStream) {
    FUN_00c8a280(kStream);
    SaveData* pData = m_pData;
    SerializeValue(kStream, pData->kFirst);
    SerializeValue(kStream, pData->kSecond);
    SerializeValue(kStream, pData->uiC8);
    SerializeValue(kStream, pData->uiCC);
    SerializeValue(kStream, pData->uiB4);
    SaveShape(pData->pLinked, kStream);
    if (pData->pLinked)
        SerializeValue(kStream, pData->bFlag);
}

extern __declspec(thread) int g_iCC7F30AllocTag;

struct BCC7F30AllocTagScope {
    int m_iSaved;

    BCC7F30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC7F30AllocTag;
        g_iCC7F30AllocTag = aiAllocationTag;
    }
    ~BCC7F30AllocTagScope() { g_iCC7F30AllocTag = m_iSaved; }
};

class BCC7F30Allocator {
public:
    virtual void VFunc00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* pvMem, int iNumBytes);
};

class BCC7F30Router {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BCC7F30Allocator* m_pkHeap;

    BCC7F30Allocator& heap() { return *m_pkHeap; }
};

BCC7F30Router* BCC7F30GetRouter();

class BCC7F30ReferencedObject {
public:
    void* operator new(unsigned int uiNumBytes)
    {
        BCC7F30ReferencedObject* pkObject = static_cast<BCC7F30ReferencedObject*>(BCC7F30GetRouter()->heap().AllocateMemoryBlock(uiNumBytes));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiNumBytes;
        return pkObject;
    }
    void operator delete(void* pvMem)
    {
        BCC7F30ReferencedObject* pkObject = static_cast<BCC7F30ReferencedObject*>(pvMem);
        BCC7F30GetRouter()->heap().ReleaseBlock(pvMem, pkObject->m_usMemSizeAndFlags);
    }

    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class BCC8950BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(BCC8950BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

// Lazily create the Havok helper object; report the object size.

extern __declspec(thread) int g_iCC9890AllocTag;

struct CC9890AllocTagScope {
    int m_iSaved;

    CC9890AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC9890AllocTag;
        g_iCC9890AllocTag = aiAllocationTag;
    }
    ~CC9890AllocTagScope() { g_iCC9890AllocTag = m_iSaved; }
};

struct CC9890Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct CC9890MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC9890Allocator* m_pStreamAllocator;

    CC9890Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CC9890MemoryRouter& __cdecl CC9890GetMemoryRouter();

class CC9890Helper {
public:
    CC9890Helper();
    virtual ~CC9890Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC9890Helper* p = static_cast<CC9890Helper*>(CC9890GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes) { CC9890GetMemoryRouter().heap().ReleaseBlock(p, nbytes); }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};

struct CcaArg {
    int unkCur;
    int unkValue;
    int uNewnk;
    int unk00C;
    int uTmpnk;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    unsigned char m_b1e4;
};

struct CcaRes {
    int unk;
    int unk04;
    void* m_08;
    unsigned int m_0c;
};

struct CcaOwner {
    virtual ~CcaOwner() {}
    virtual void vf();
    virtual void vfCur();
    virtual void vfValue();
    virtual void vNewf();
    virtual void vTmpf();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41(int a);
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual CcaRes* vf45(int& out);
    void FUN_00ca4f80(CcaArg* a);
};

__declspec(thread) unsigned int DAT_0126fd98;

struct FUN_00cca450_param_item {
    void* unk00;
    void* unk04;
    struct FUN_00cca450_hook* unk08;
};
struct FUN_00cca450_hook {
    void __thiscall FUN_00c905b0();
};

typedef unsigned int CCADB0size_t;

struct CCADB0MemoryManager {
    void* Allocate(unsigned int uiSize);
};
extern CCADB0MemoryManager g_CCADB0MemoryManager;

extern __declspec(thread) int g_CCADB0AllocTag;

struct CCADB0AllocTagScope {
    int m_iSaved;

    CCADB0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCADB0AllocTag;
        g_CCADB0AllocTag = aiAllocationTag;
    }
    ~CCADB0AllocTagScope() { g_CCADB0AllocTag = m_iSaved; }
};

extern const float g_fCCADB0DefaultScale;

struct CCADB0Child {
    CCADB0Child() throw()
        : m_pkOwnerManager(0), m_fScale(g_fCCADB0DefaultScale), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {
    }

    void* m_pkOwnerManager;
    float m_fScale;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCADB0size_t uiSize) throw() { return g_CCADB0MemoryManager.Allocate(uiSize); }
    static void operator delete(void* pvMem) {}
};

extern int DAT_012686d0;
extern int DAT_01268678;
extern int DAT_010c44e4;
extern int DAT_010ca744;

struct BccObj : S_00c87c30_Base {
    unsigned int m_14;
    BccObj() : S_00c87c30_Base() {
        m_pVtable = &DAT_01030bf4;
        unsigned int* q = &m_uiData1;
        q[0] = 0;
        q[1] = 0;
        DAT_012680f8 += 1;
        m_pVtable = &DAT_010c44e4;
        DAT_012686d0 += 1;
        m_pVtable = &DAT_010ca744;
        m_14 = 0;
        DAT_01268678 += 1;
    }
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
    static void operator delete(void* p) {}
};

namespace fnv_00ccc7e0 {
struct MemoryManagerAllocHelper { void* Allocate(unsigned int size); };
extern MemoryManagerAllocHelper g_memoryHeap;

extern __declspec(thread) int g_tlsAllocPool;

static int GetMemContext() { return g_tlsAllocPool; }
static void SetMemContext(int context) { g_tlsAllocPool = context; }

struct TlsPoolGuard {
    int m_iOld;
    TlsPoolGuard(int context) { m_iOld = GetMemContext(); SetMemContext(context); }
    ~TlsPoolGuard() { Leave(); }
    void Leave() { SetMemContext(m_iOld); }
};

struct LoadStream;
typedef int (__cdecl *LoadStreamReadFn)(LoadStream* stream, void* buffer, int elemSize, int* count, int flag);
struct LoadStream {
    int unk00;
    int m_iPosition;
    LoadStreamReadFn m_pfnRead;
    void ReadUInt(unsigned int* value) {
        int count = 4;
        int read = m_pfnRead(this, value, 4, &count, 1);
        m_iPosition += read;
    }
};

struct LoadContext {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    LoadStream* m_pBinaryStream;
};

struct FiveIntegerLoadRecord {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FiveIntegerLoadRecord();
    ~FiveIntegerLoadRecord();
    void Load(LoadContext* ctx);
    static void* operator new[](unsigned int size) { return g_memoryHeap.Allocate(size); }
};

}  // namespace fnv_00ccc7e0

// SaveBinary of an element array: the count, then each element saves itself.

class CCC920BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CCC920BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CCC920BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n, unsigned int uiComponentSize) {
        unsigned int size = uiComponentSize;
        return BinaryWrite(p, n, &size, 1);
    }
};

class CCC920Stream {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    CCC920BinaryStream* m_pBackingStream;
};

template <class T>
inline void CCC920BinaryStreamSave(CCC920BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CCC920SaveBinary(CCC920Stream& kStream, const T& value) {
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

template <class T>
inline void CCC920SaveBinary(CCC920Stream& kStream, const T* pValues, unsigned int ItemUpdateArray) {
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, pValues, ItemUpdateArray);
}

struct CCC920Element {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    void SaveBinary(CCC920Stream& kStream);
};

class CCC920Array {
public:
    void* m_pVtbl;
    int unk04;
    unsigned int m_uiCount;
    CCC920Element* m_pkVertexElements;

    void FUN_00ccc920(CCC920Stream& kStream);
};

// Writes m_uiCount to the stream, then calls SaveBinary on each of the m_uiCount elements in the array.
// @fnv 0x00ccc920
// pdb: bhkExtendedMeshShapeData::SaveBinary | bhkExtendedMeshShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: arStream
void CCC920Array::FUN_00ccc920(CCC920Stream& kStream)
{
    CCC920SaveBinary(kStream, m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
        m_pkVertexElements[i].SaveBinary(kStream);
}

extern __declspec(thread) int g_iCCDE60MemContext;

class CCDE60MemContext {
public:
    CCDE60MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCCDE60MemContext;
        g_iCCDE60MemContext = aiMemoryContext;
    }
    ~CCDE60MemContext() { g_iCCDE60MemContext = m_iPrevious; }

    int m_iPrevious;
};

void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();

class CCDE60Object {
public:
    CCDE60Object();
    virtual ~CCDE60Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class AllocatorCCD {
public:
    virtual void vfn00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};

struct MemoryCCD {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorCCD* m_pHeapAllocator;

    AllocatorCCD& heap() { return *m_pHeapAllocator; }
};

MemoryCCD* __cdecl GetMemoryCCD();

extern __declspec(thread) int g_iAllocTagCCD;

struct AllocTagScopeCCD {
    int m_iSaved;

    AllocTagScopeCCD(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagCCD;
        g_iAllocTagCCD = aiAllocationTag;
    }
    ~AllocTagScopeCCD() { g_iAllocTagCCD = m_iSaved; }
};

class ReferencedObjectCCD {
public:
    static void* operator new(unsigned int uiSize)
    {
        ReferencedObjectCCD* pkObject = static_cast<ReferencedObjectCCD*>(GetMemoryCCD()->heap().AllocateMemoryBlock(uiSize));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObject;
    }
    static void operator delete(void* pvMem);

    virtual ~ReferencedObjectCCD();

    void removeReference();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

struct CE340Allocator {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CE340Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CE340Allocator* m_pStreamAllocator;
    CE340Allocator& heap() { return *m_pStreamAllocator; }
};
CE340Router* CE340GetRouter() throw();

struct CE340Vec4 {
    float x, y, z, w;
};

template <class T>
struct CE340Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CE340Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~CE340Array() { _clearAndDeallocate(CE340GetRouter()->heap()); }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void _clearAndDeallocate(CE340Allocator& alloc) {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void swap(CE340Array& a) {
        T* d = m_data; m_data = a.m_data; a.m_data = d;
        int s = m_iElementCount; m_iElementCount = a.m_iElementCount; a.m_iElementCount = s;
        int c = m_iCapacityState; m_iCapacityState = a.m_iCapacityState; a.m_iCapacityState = c;
    }
};

struct CE340Data {
    int unk00;
    int unk04;
    CE340Array<CE340Vec4> m_arr08;
    CE340Array<CE340Vec4> m_arr14;
};

typedef FUN_00ccd3a0_arg CE340Stream;

void __cdecl FUN_00cf0930(CE340Data* data, void* ctx, CE340Array<CE340Vec4>* arr);
void __cdecl FUN_00cf0cf0(CE340Stream* stream, void* value);

// Release the cached Havok data when requested.

extern __declspec(thread) int g_iCCE860AllocTag;

struct CCE860AllocTagScope {
    int m_iSaved;

    CCE860AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCE860AllocTag;
        g_iCCE860AllocTag = aiAllocationTag;
    }
    ~CCE860AllocTagScope() { g_iCCE860AllocTag = m_iSaved; }
};

class CCE860MemoryManager {
public:
    void Deallocate(void* pvMem);
};
extern CCE860MemoryManager g_kCCE860MemoryManager;

inline void __cdecl operator delete(void* pvMem)
{
    g_kCCE860MemoryManager.Deallocate(pvMem);
}

__declspec(thread) unsigned int currentAllocationContext = 0x3b;

struct ThreadContextGuard
{
    unsigned int oldValue;
    ThreadContextGuard()
        : oldValue(currentAllocationContext)
    {
        currentAllocationContext = 0x10;
    }
    ~ThreadContextGuard()
    {
        currentAllocationContext = oldValue;
    }
};

struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int size);
};

extern float DAT_010c72bc;
extern MM g_memoryManager;

class BCCFA50Arg;

class BCCFA50Shape {
public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void VFuncA4();
    virtual void VFuncA8();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual void VFuncB4();
    virtual void VFuncB8();
    virtual void VFuncBC();
    virtual void VFuncC0();
    virtual void VFuncC4();
    virtual void VFuncC8();
    virtual void VFuncCC();
    virtual bool Process(BCCFA50Arg* pkArg);
};

struct BCCFA50Child {
    int unk00;
    int unk04;
    BCCFA50Shape* m_pkShape;
};

class BCCFA50Counter {
public:
    virtual void VFunc00();
    virtual int GetCount();
};

struct BCCFA50HavokList {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    BCCFA50Counter m_kCounter;
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
    BCCFA50Child** m_ppkChildren;
};

class BCCFA50Wrapper {
public:
    bool BaseProcess(BCCFA50Arg* pkArg);
    __forceinline BCCFA50HavokList* GetList() { return this ? m_pkList : 0; }
    bool ProcessChildren(BCCFA50Arg* pkArg);

    int unk00;
    int unk04;
    BCCFA50HavokList* m_pkList;
};

// Returns the lazily created settings block, creating it under the Havok allocation tag and registering it when owned.

extern __declspec(thread) int g_iCCFFD0AllocTag;

struct CCFFD0AllocTagScope {
    int m_iSaved;

    CCFFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCFFD0AllocTag;
        g_iCCFFD0AllocTag = aiAllocationTag;
    }
    ~CCFFD0AllocTagScope() { g_iCCFFD0AllocTag = m_iSaved; }
};

extern float g_fCCFFD0DefaultScale;

class CCFFD0Settings {
public:
    CCFFD0Settings()
    {
        m_pUserData = 0;
        m_fScale = g_fCCFFD0DefaultScale;
        m_pEntries = 0;
        m_iEntryCount = 0;
        m_iCapacityAndFlags = 0x80000000;
    }

    static void* operator new(unsigned int uiSize, void* pvMem) throw() { return pvMem; }

    void* m_pUserData;
    float m_fScale;
    int unk08;
    int unk0C;
    void* m_pEntries;
    int m_iEntryCount;
    int m_iCapacityAndFlags;
};

struct hkMemoryAllocStub {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void deallocateChunk(void* p, int nbytes);
};

template <class T>
struct hkArrayRaw {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

};

template <class T>
struct hkArrayStub {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayStub() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~hkArrayStub()
    {
        hkMemoryAllocStub* mem = reinterpret_cast<hkMemoryAllocStub*>(FUN_00c85750()->unk10);
        if ((m_iCapacityState & 0x80000000) == 0)
            mem->deallocateChunk(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    hkArrayStub(const hkArrayRaw<T>& r) : m_data(r.m_data), m_iElementCount(r.m_iElementCount), m_iCapacityState(r.m_iCapacityState) {}
    __forceinline hkArrayRaw<T> release()
    {
        int s = m_iElementCount;
        T* d = m_data;
        m_data = 0;
        m_iElementCount = 0;
        int c = m_iCapacityState;
        m_iCapacityState = 0x80000000;
        hkArrayRaw<T> r;
        r.m_data = d;
        r.m_iElementCount = s;
        r.m_iCapacityState = c;
        return r;
    }
    void swap(hkArrayStub& a)
    {
        int s = a.m_iElementCount;
        T* d = a.m_data;
        a.m_data = m_data;
        a.m_iElementCount = m_iElementCount;
        m_data = d;
        m_iElementCount = s;
        int c = a.m_iCapacityState;
        a.m_iCapacityState = m_iCapacityState;
        m_iCapacityState = c;
    }
};

struct NiBinaryStreamStub {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStreamStub* stream, const void* buffer, unsigned int bytes,
                               unsigned int* componentSizes, unsigned int numComponents);

    void BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, buffer, bytes, componentSizes, numComponents);
    }
};

struct LinkedObjStub {
    int unk00;
    int unk04;
    void* m_pLinked;
};

struct SaveStreamStub {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void SaveLinkID(void* obj);
};

struct SaveStreamFields : SaveStreamStub {
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC;
    int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0;
    unsigned char m_bUnk1E4;
    unsigned char unk1E5; unsigned short unk1E6;
    int unk1E8; int unk1EC;
    int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C;
    NiBinaryStreamStub* m_pOstr;
};

struct CountedSub {
    virtual void v00();
    virtual int GetCount();
};

struct CountedOwner {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    CountedSub m_sub;
};

struct SavedData {
    int unk00;
    int unk04;
    char m_cUnk08;
    int m_iUnk0C;
    hkArrayStub<LinkedObjStub*> m_ppData;
};

void FUN_00cf0930(SavedData* data, void* source, hkArrayStub<LinkedObjStub*>* out);

struct bhkSaveOwner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4();
    virtual void* GetSource();
    virtual void vAC(); virtual void vB0();
    virtual SavedData* GetData(bool* pbOut);

    int unk04;
    CountedOwner* m_pSharedOwner;

    int GetCount() { CountedOwner* owner = m_pSharedOwner; return owner ? owner->m_sub.GetCount() : 0; }
    void FUN_00c9fc00(SaveStreamFields* stream);
    void SaveLinkedObjects(SaveStreamFields* stream);
};

struct StateCountSource {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_iArrayLength;
};
struct StateResetPart {
    int unk00;
};
struct StateResetTarget {
    StateCountSource* m_pSource;
    StateResetPart m_kPart;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int* m_piStates;
    int unk20;
    int unk24;
    bool m_bFlag28;
    bool m_bFlag29;

    StateResetPart* ResetStates();
};

// @fnv 0x00cd9fb0
StateResetPart* StateResetTarget::ResetStates()
{
    int iCount = m_pSource->m_iArrayLength;
    for (int i = 0; i < iCount; ++i)
        m_piStates[i] = 2;
    m_bFlag28 = false;
    m_bFlag29 = true;
    return &m_kPart;
}

extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_010c9634;
extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;

struct C200125Base
{
    void FUN_00c87c30();
};

struct C200125Object : C200125Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }

    C200125Object()
    {
        unsigned int count = 1;
        FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_0102009c;
        DAT_01268118 += count;
        m_pVtable = &DAT_010c9634;
        DAT_012685b8 += count;
    }
};

struct SaveStream;
typedef unsigned int (__cdecl *SaveStreamWriteFn)(SaveStream*, const void*, unsigned int, unsigned int*, unsigned int);

struct SaveStream {
    void* unk00;
    unsigned int m_04;
    void* unk08;
    SaveStreamWriteFn m_0c;
    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int num)
    { unsigned int r = m_0c(this, p, n, sizes, num); m_04 += r; return r; }
    unsigned int Write(const void* p, unsigned int n)
    { unsigned int cnt = n; return BinaryWrite(p, n, &cnt, 1); }
};

struct SaveCtx {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    SaveStream* m_pBinaryStream;
};

// bhk wrapper LoadBinary: load the parent part, then fix up the Havok cinfo block when the
// stream's endianness differs (translation swapped inline, rotation through the shared helper).

struct TransformDataX {
    unsigned int m_rotation00, m_rotation04, m_rotation08, m_rotation0c;
    unsigned int m_rotation10, m_rotation14, m_rotation18, m_rotation1c;
    unsigned int m_rotation20, m_rotation24, m_rotation28, m_rotation2c;
    unsigned int m_uiX, m_uiY, m_uiZ, m_w;
};
void __cdecl FUN_00c8c020(TransformDataX* pkRotation);

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

namespace cce {
struct Block { char pad[0x30]; unsigned long m_kPointA; unsigned long m_kPointB; unsigned long m_iThirdValue; unsigned long m_iFourthElementInteger; };
void __cdecl FUN_00c8c020(Block* b);
struct Hdr { char pad[0x10]; Block m_kBlock; };
struct Info { int unk; int unkCur; void* m_pName; };
struct Meta { char pad[0x18]; Info* m_pObjectInfo; };
struct Writer {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void SetName(void* p);
    char pad[0x1e4 - 4]; unsigned char m_ucMode;
};
struct Obj {
    virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual void v48();virtual void v4c();virtual void v50();virtual void v54();virtual void v58();virtual void v5c();virtual void v60();virtual void v64();virtual void v68();virtual void v6c();virtual void v70();virtual void v74();virtual void v78();virtual void v7c();virtual void v80();virtual void v84();virtual void v88();virtual void v8c();virtual void v90();virtual void v94();virtual void v98();virtual void v9c();virtual void va();virtual void vaCur();virtual void vaValue();virtual void vac();virtual void vb();
    virtual Hdr* GetHeader(int* pSize);
    int unkCur; Meta* m_pMeta;
    void FUN_00c9fc00(Writer* w);
    void FUN_00ccec00(Writer* w);
};
}

extern char g_vtblInst0104da28[];
extern char g_vtblInst010cb300[];

struct ContactPointPair
{
    int m_00; int m_04; int m_08; int m_0c;
    int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c;
    int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44; int m_48; int m_4c;
    int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c;
};

struct HavokElementArray
{
    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapFlags;
    void Init()
    {
        m_pData = 0;
        m_uiLogicalSize = 0;
        m_iCapFlags = (int)0x80000000;
    }
};

struct FUN_00cd3410
{
    void* volatile m_pVtable;           // 0x00
    volatile float m_fEarlyOutDistance;  // 0x04
    int m_unk08;                        // 0x08
    int m_unk0c;                        // 0x0c
    void* m_pHits;                      // 0x10
    int m_iHitsSize;                    // 0x14
    int m_iHitsCapFlags;                // 0x18
    int m_unk1c;                        // 0x1c
    ContactPointPair m_kHits[8];               // 0x20 (8 * 112 = 0x380)
    volatile unsigned int m_3a0;        // 0x3a0
    HavokElementArray m_a1;                   // 0x3a4
    HavokElementArray m_a2;                   // 0x3b0
    HavokElementArray m_a3;                   // 0x3bc

    FUN_00cd3410(unsigned int param);
};

// Initializes the object: sets vtable pointers, hit capacity flags, hit buffer to inline storage, stores param, and inits three sub-objects.
// @fnv 0x00cd3410
FUN_00cd3410::FUN_00cd3410(unsigned int param)
{
    m_fEarlyOutDistance = 3.40282e38F;
    m_pVtable = g_vtblInst0104da28;
    m_iHitsCapFlags = 0x80000008;
    m_pHits = m_kHits;
    m_fEarlyOutDistance = 3.40282e38F;
    m_3a0 = param;
    m_pVtable = g_vtblInst010cb300;
    m_a1.Init();
    m_a2.Init();
    m_a3.Init();
    m_iHitsSize = 0;
    m_fEarlyOutDistance = 3.40282e38F;
}

inline void* operator new(unsigned int, void* p) { return p; }





extern const float runtimeFloatSettingDefault92;
extern const float runtimeFloatSettingDefault506;
extern const float g_011db1d4_arg1;
struct Defaults {
 float strength, damping, gain, recovery, maxVelocity, u14,u18,u1c,u20,u24,u28,u2c;
 Defaults() : strength(.17f),damping(0),gain(1),recovery(.6f),maxVelocity(.05f),u14(runtimeFloatSettingDefault92),u18(runtimeFloatSettingDefault506),u1c(.1f),u20(.3f),u24(.3f),u28(g_011db1d4_arg1),u2c(.1f) {}
 Defaults(int) {}
 Defaults* FUN_00cdb360();
};
template<class T> struct Array {
 T* data; int size; int capacity;
 Array():data(0),size(0),capacity(0x80000000) {}
 __forceinline void reserve(S_00cc4b90_Alloc& alloc,int n) { int c=capacity&0x3fffffff; if(c<n) { int doubled=c*2; FUN_00c908c0(&alloc,this,n<doubled?doubled:n,sizeof(T)); } }
 __forceinline void resizeUninitialized(int n) { reserve(FUN_00c85750()->heap(),n); size=n; }
 __forceinline void resize(int n) { reserve(FUN_00c85750()->heap(),n); int delta=n-size; T* start=data+size; for(int i=0;i<delta;i++) new(start+i) T; size=n; }
 __forceinline void resize(int n,T value) { reserve(FUN_00c85750()->heap(),n); int delta=n-size; T* start=data+size; for(int i=0;i<delta;i++) start[i]=value; size=n; }
};
struct Skeleton { int u00,u04,u08; short* parents; int u10,u14,u18; int count; };

class hkTargetCC01 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void handle(void* pv);
};

class hkObjCC01 {
public:
    int unk00;
    int unk04;
    hkTargetCC01* m_target;

    void* DispatchToTarget(void* pv);
};

// @fnv 0x00cc0100
// pdb: hkOstream::isOk | hkOStream.obj | tesv_win, objrun_open, low
void* hkObjCC01::DispatchToTarget(void* pv)
{
    m_target->handle(pv);
    return pv;
}

extern "C" int __cdecl hkString_snprintf(char* dst, int maxlen, const char* fmt, ...);
extern "C" int __cdecl hkString_strLen(const char* s);

struct hkStreamWriter {
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual void unk0c() = 0;
    virtual int write(const void* buf, int len) = 0;
};

static __declspec(noinline) void FUN_00cc0080(hkStreamWriter* writer, const char* str) {
    if (str) {
        writer->write(str, hkString_strLen(str));
    } else {
        writer->write("(null)", 6);
    }
}

extern "C" void* DAT_010c9314;

struct OwnerManager {
    virtual void* Reserved0();
    virtual void* Reserved1();
    virtual void* Reserved2();
    virtual void* Reserved3();
    virtual void* CreateOwner(void* owner);
};

extern "C" OwnerManager* DAT_01268364;

struct FUN_00cc04d0_Class {
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;

    FUN_00cc04d0_Class* __thiscall FUN_00cc04d0(void* owner);
};

// @fnv 0x00cc04d0
// pdb: hkOstream::hkOstream | hkOStream.obj | fnv360_0822_retail, call_seq, medium
// pdb params: filename
FUN_00cc04d0_Class* __thiscall FUN_00cc04d0_Class::FUN_00cc04d0(void* owner)
{
    m_iUnk = 1;
    m_pVtable = &DAT_010c9314;
    m_pSharedOwner = DAT_01268364->CreateOwner(owner);
    return this;
}

struct CpuOpaque;
extern CpuOpaque DAT_01268590;
// @fnv 0x00cc1280
// pdb: bhkForceController::GetRTTI | bhkForceController.obj | fnv360_0822_retail, objrun, medium
CpuOpaque* __cdecl FUN_00cc1280()
{
    return &DAT_01268590;
}

struct FUN_00a5d2f0_shell {
    bool NiObject_RegisterStreamables(void* apStream);
};
struct FUN_00cc1310_class : FUN_00a5d2f0_shell {
    unsigned int m_uiUnk0;
    unsigned int m_uiUnk4;
    unsigned int m_uiCount;
    void* m_pData;
    bool FUN_00cc1310(void* apStream);
};
// @fnv 0x00cc1310
// pdb: bhkPoseArray::RegisterStreamables | bhkPoseArray.obj | fnv360_0822_debug, objrun_open, low
// pdb params: arStream
bool FUN_00cc1310_class::FUN_00cc1310(void* apStream)
{
    bool b = NiObject_RegisterStreamables(apStream);
    if (b) {
        for (unsigned int i = 0; i < m_uiCount; ++i)
            ((void (__thiscall *)(void*, void*))(*(void***)apStream)[8])(apStream, (char*)m_pData + i * 4);
    }
    return b;
}

struct Stream {
    int unk0;
    int total;
    int unk8;
    int (*io)(Stream* s, void* buf, int size, int* out, int n);
    void Rd(void* p) { int sz = 4; total += io(this, p, 4, &sz, 1); }
};
struct Item { unsigned int count; char** data; };
struct Loader {
    char pad[0x250];
    Stream* stream;
    void Read(unsigned int* p);
    void NiStream_SaveFixedString(unsigned int* p);
};
struct Obj {
    int unk0, unk4;
    unsigned int count1;
    unsigned int* arr1;
    unsigned int count2;
    Item** arr2;
    void ReadFromStream(Loader* l);
};

void __cdecl FUN_00a5d430(void);

// @fnv 0x00cc1960
// pdb: NiPSysModifierBoolCtlr::RegisterStreamables | NiPSysModifierBoolCtlr.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
void __cdecl FUN_00cc1960(void)
{
    FUN_00a5d430();
}

struct RefObjC {
    virtual ~RefObjC();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T>
struct LargeArrayC {
    virtual ~LargeArrayC();
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int uiMaxSize);
    __declspec(noinline) void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiSize) {
            m_uiSize = uiIndex + 1;
            if (element.m_pObject)
                m_uiESize++;
        } else {
            if (element.m_pObject) {
                if (!m_pBase[uiIndex].m_pObject)
                    m_uiESize++;
            } else {
                if (m_pBase[uiIndex].m_pObject)
                    m_uiESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiMaxSize)
            SetSize(uiIndex + m_uiGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element) { return SetAtGrow(m_uiSize, element); }
};

struct OwnerC {
    int unk00, unk04, unk08;
    LargeArrayC<NiPointer<RefObjC> > m_kArray;
    void AddRefObject(RefObjC* pkObject);
};

// If pkObject is non-null, appends it to m_kArray.
// @fnv 0x00cc2080
// pdb: bhkExtraData::PrependController | bhkExtraData.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apController
void OwnerC::AddRefObject(RefObjC* pkObject)
{
    if (pkObject)
        m_kArray.Add(pkObject);
}

void __cdecl FUN_00c8a560();

// @fnv 0x00cc5080
// pdb: NiBoolInterpController::SaveBinary | NiBoolInterpController.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
void __cdecl FUN_00cc5080() {
    FUN_00c8a560();
}

struct S_54d0_Poly {
    void* m_pVtable;
};

struct S_54d0_Child {
    void* m_pUnk00;

    S_54d0_Child() {}
};

struct S_54d0_Heap {
    void* Allocate(unsigned int uiSize);
};

extern S_54d0_Heap g_54d0Heap;
extern int DAT_010c9af0;

struct S_54d0_Node : S_54d0_Poly, S_54d0_Child {
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;

    static void* operator new(unsigned int uiSize) { return g_54d0Heap.Allocate(uiSize); }

    S_54d0_Node() {
        S_54d0_Child* pkSelf = this;
        m_uiRefCount = 1;
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_pVtable = (void*)&DAT_010c9af0;
        pkSelf->m_pUnk00 = 0;
    }
};

struct CC7970_Allocator { void* __thiscall FUN_00aa3e40(unsigned int); };

void FUN_00d50000();

// @fnv 0x00cc7ce0
// pdb: NiPSysModifierCtlr::LinkObject | NiPSysModifierCtlr.obj | fnv360_0822_retail, call_gap, high
// pdb params: kStream
void FUN_00cc7ce0() {
    FUN_00d50000();
}

void __cdecl FUN_00d50010();

// @fnv 0x00cc7cf0
// pdb: NiBoolInterpController::CopyMembers | NiBoolInterpController.obj | fnv360_0822_retail, call_seq, high
// pdb params: pkDest, kCloning
void __cdecl FUN_00cc7cf0()
{
    FUN_00d50010();
}

void* FUN_00aa13e0(unsigned int);
void FUN_00aa1460(void*,unsigned int);
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
// Constructor stand-in for the twelve-byte bhkRefObject base.
struct FUN_00c87c30 {
    virtual ~FUN_00c87c30();
    unsigned int references;
    void* handle;
    FUN_00c87c30();
};
// The pack's bhkConstraint shell omits its base and data member.
// This stand-in models the actual sixteen-byte constraint layout.
class Constraint348 : public FUN_00c87c30 {
public:
    void* constraint;
    Constraint348() : constraint(0) { ++DAT_01268188; }
    virtual ~Constraint348();
};
class bhkGenericConstraint : public Constraint348 {
public:
    bhkGenericConstraint() { ++DAT_01268f74; }
    virtual ~bhkGenericConstraint();
};
class bhkFixedConstraint : public bhkGenericConstraint {
public:
    bhkFixedConstraint() { ++DAT_01268624; }
    virtual ~bhkFixedConstraint();
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
    static void operator delete(void* pointer, unsigned int size) { FUN_00aa1460(pointer,size); }
};

void __cdecl FUN_00ca4f00();

// @fnv 0x00cc9cd0
// pdb: NiFloatInterpController::LoadBinary | NiFloatInterpController.obj | fnv360_0721_beta, call_seq + bridge(vtable|call_seq) + skyrim(caller_sim), high
void __cdecl NiFloatInterpController_LoadBinary()
{
    FUN_00ca4f00();
}

// Forward declaration of the target function
void __cdecl FUN_00ca4f40();

// Tail call wrapper - jumps to FUN_00ca4f40
// @fnv 0x00cc9ce0
// pdb: bhkCollisionObject::CopyMembers | bhkCollisionObject.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apDest, arCloneData
void __cdecl FUN_00cc9ce0() {
    FUN_00ca4f40();
}

void __cdecl FUN_00c8bf40();
// @fnv 0x00cc9cf0
// pdb: bhkCollisionObject::LoadBinary | bhkCollisionObject.obj | fnv360_0721_beta, objrun, medium
// pdb params: arStream
void __cdecl FUN_00cc9cf0()
{
    FUN_00c8bf40();
}

namespace fnv_00cca2a0 {
inline void* __cdecl operator new(unsigned int, void* place) { return place; }
struct Vec4 {
    unsigned int x, y, z;
    float w;
    Vec4() : x(0), y(0), z(0), w(1.0f) {}
};
struct Allocator {
    void* __thiscall FUN_00aa3e40(unsigned int bytes);
};
extern "C" Allocator DAT_011f6238;
extern __declspec(thread) int g_threadMemoryMode;
struct ScopedMemoryMode {
    int previous;
    ScopedMemoryMode() : previous(g_threadMemoryMode) { g_threadMemoryMode = 16; }
    ~ScopedMemoryMode() { g_threadMemoryMode = previous; }
};
}  // namespace fnv_00cca2a0

struct FUN_00cce5e0_class {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
    FUN_00cce5e0_class* __thiscall Construct();
};
// @fnv 0x00cce5e0
// pdb: hkGeometry::hkGeometry | bhkConvexVerticesShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
FUN_00cce5e0_class* __thiscall FUN_00cce5e0_class::Construct()
{
    m_pVtable = 0;
    m_uiRefCount = 0;
    m_uiValue1 = 0x80000000;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_uiData3 = 0x80000000;
    return this;
}

struct Cls00ccf5a0 {
    void FUN_00c84cc0(int a);
    void FUN_00ccf5a0(int a);
};

// @fnv 0x00ccf5a0
// pdb: bhkCollisionObject::LinkObject | bhkCollisionObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Cls00ccf5a0::FUN_00ccf5a0(int a) {
    FUN_00c84cc0(a);
}

void __cdecl FUN_00c908c0(void* alloc, void* arr, int cap, int elemSize);
struct FE50Iter {
    virtual void v00();
    virtual unsigned int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
};
struct FE50Hk {
    char pad00[0x14];
    FE50Iter m_kIter;
    float m18;
    char pad1c[0x28];
    void** m44;
    bool FUN_00d5e0c0();
};
struct FE50Out {
    int m0, m4;
    unsigned char m8;
    float mc;
    Array<void*> m10;
};
struct FE50Wrap {
    int m0, m4;
    FE50Hk* m8;
    void bhkConvexShape_CopyCinfo(FE50Out* out);
    float GetF() { if (this && m8) return m8->m18; return 0.0f; }
    int GetB() { if (this && m8) return m8->FUN_00d5e0c0(); return 0; }
    unsigned int GetCount() { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetCount(); if (0) return m8->m_kIter.GetCount(); return 0; }
    void* GetFirst() { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetFirst(); if (0) return m8->m_kIter.GetFirst(); return 0; }
    void* GetNext(void* it) { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetNext(it); if (0) return m8->m_kIter.GetNext(it); return 0; }
    void* GetAt(unsigned int i) { if (this && m8) return m8->m44[i]; return 0; }
    void FillOutput(FE50Out* out);
};

struct AGBinStream {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(AGBinStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

struct FnvCpu_FUN_00cd0cf0_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    void FUN_00cd0cf0(unsigned char arg0);
};
// @fnv 0x00cd0cf0
// pdb: TESLeveledList::SetChanceNone | TESLeveledList.obj | fnv360_0822_retail, call_gap, low
// pdb params: acChance
void FnvCpu_FUN_00cd0cf0_CpuObject::FUN_00cd0cf0(unsigned char arg0)
{
    value = arg0;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkSection);

extern void (__stdcall *DAT_00fdf100)(int*);

// @fnv 0x00cd3b10
void __stdcall FUN_00cd3b10(int, int, int, int) {
}

struct FUN_00cdb3c0_class {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* __thiscall FUN_00cdb3c0();
};

// @fnv 0x00cdb3c0
void* FUN_00cdb3c0_class::FUN_00cdb3c0()
{
    return unk38;
}

struct hkMemoryAllocator {
    virtual void vfn0() throw() = 0;
    virtual void vfn1() throw() = 0;
    virtual void vfn2() throw() = 0;
    virtual void vfn3() throw() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) throw() = 0;
};

void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize) throw();
void __cdecl FUN_00c908c0(void* allocator, void* array, int newCapacity, int elementSize) throw();
template <typename T> inline void ConstructWithCopy(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }

template <typename T>
struct MyArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    enum {
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline MyArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG) {}

    __forceinline int getCapacity() const throw() { return m_iCapacityState & 0x3fffffff; }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator* alloc, int n) throw() {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = cap * 2;
            int newCap = n < cap2 ? cap2 : n;
            FUN_00c908c0(alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline void SetSizeAndGrow(int n, T fill) throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        GrowArrayCapacity(router->m_pStreamAllocator, n);
        ConstructWithCopy<T>(m_data + m_iElementCount, n - m_iElementCount, fill);
        m_iElementCount = n;
    }

    __forceinline void AddBack(const T& val) throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        if (m_iElementCount == getCapacity()) {
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        }
        ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }

    __forceinline ~MyArray() throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        hkMemoryAllocator* alloc = router->m_pStreamAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc->ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};

template <typename T>
struct MyLocalArray : public MyArray<T> {
    void* m_initialStack;

    __forceinline MyLocalArray(int capacity) throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        int numBytes = capacity * sizeof(T);
        int aligned = (numBytes + 0x7f) & ~0x7f;
        void* p = (void*)router->unk00;
        router->unk00 = (int)((char*)p + aligned);
        this->m_iCapacityState = capacity | MyArray<T>::DONT_DEALLOCATE_FLAG;
        this->m_data = (T*)p;
        this->m_initialStack = p;
    }

    __forceinline ~MyLocalArray() throw() {
        void* p = m_initialStack;
        if (p == this->m_data) {
            this->m_iElementCount = 0;
        }
        ((NineIntegerRecord*)FUN_00c85750())->unk00 = (int)p;
    }
};

struct FUN_00cdea20_cls {
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
    int m_e0;

    int hkpRagdollConstraintData_getTwistMotor() const;
};

// @fnv 0x00cdea20
// pdb: hkpRagdollConstraintData::getTwistMotor | hkpRagdollConstraintData.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int FUN_00cdea20_cls::hkpRagdollConstraintData_getTwistMotor() const
{
    return m_e0;
}

struct CC0280Stream {
    virtual void Write(const char* str, int len);
};

int hkString_strLen(int);

static void __declspec(noinline) FUN_00cc0080(CC0280Stream* s, const char* str)
{
    if (str == 0) {
        s->Write("(null)", 6);
        return;
    }
    s->Write(str, hkString_strLen((int)str));
}

struct CC0280Writer : hkOstream {
    CC0280Writer* WriteBool(bool b);
};

// Writes the string "true" or "false" to the underlying stream based on the input boolean value and returns this.
// @fnv 0x00cc0170
// pdb: hkOstream::operator<< | hkOStream.obj | tesv_win, hash, low
CC0280Writer* CC0280Writer::WriteBool(bool abValue)
{
    FUN_00cc0080((CC0280Stream*)m_pSharedOwner, abValue ? "true" : "false");
    return this;
}

int __cdecl hkString_strLen(int);
int __cdecl hkString_snprintf(char*, unsigned int, const char*, ...);

struct WriterObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Write(const char* s, int len);
};

static __declspec(noinline) void FUN_00cc0080(WriterObj* obj, const char* str)
{
    if (!str)
        obj->Write("(null)", 6);
    else
        obj->Write(str, hkString_strLen((int)str));
}

struct FUN_00cc01e0_class {
    void* m_kPointA;
    void* m_kPointB;
    WriterObj* m_obj;
    FUN_00cc01e0_class* __thiscall WriteShort(short v);
};

// Formats the short parameter v as a decimal integer into a local buffer and writes it to m_obj via FUN_00cc0080, returning this.
// @fnv 0x00cc01e0
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, objrun, medium
// pdb params: s
FUN_00cc01e0_class* FUN_00cc01e0_class::WriteShort(short asValue)
{
    int buf[2506];
    hkString_snprintf((char*)buf, 0x2728, "%i", asValue);
    FUN_00cc0080(m_obj, (char*)buf);
    return this;
}

extern "C" void __stdcall FUN_00ec5fce(void*, unsigned int, unsigned int, const void*);
extern "C" void FUN_004381b0();
struct FUN_00a5d3d0 {
    virtual void dummy();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    ~FUN_00a5d3d0();
};
struct FUN_00cc1520 : FUN_00a5d3d0 {
    virtual void dummy();
    char* m_pName;
    unsigned int m_uiCount;
    void** m_pEntryData;
    ~FUN_00cc1520();
};
// Frees the name buffer, each entry in m_pEntryData, and the entry array itself under the TLS block guard.
// @fnv 0x00cc1520
FUN_00cc1520::~FUN_00cc1520() {
    {
        TlsGuard_t guard(g_tlsBlock.m_2b4);
        if (m_pName) {
            char* header = m_pName - 4;
            FUN_00ec5fce(m_pName, 4, *reinterpret_cast<unsigned int*>(header), &FUN_004381b0);
            g_memoryManager.Deallocate(header);
        }
        if (m_pEntryData) {
            for (unsigned int i = 0; i < m_uiCount; ++i) {
                void* item = m_pEntryData[i];
                if (item)
                    g_memoryManager.Deallocate(item);
            }
            void** releaseArray = m_pEntryData;
            g_memoryManager.Deallocate(releaseArray);
        }
    }
}

extern int DAT_01268188;
extern int DAT_012685f4;
extern int DAT_0108febc;
extern int DAT_010c52bc;
extern __declspec(thread) int g_ThreadData;
extern void* __cdecl FUN_00aa13e0(unsigned int bytes);
void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
void __cdecl FUN_00aa4060(void* p);

struct S_00cc5b90_Node
{
    int* vtable;
    int data04;
    int data08;
    int data0c;
    void __thiscall FUN_00c87c30();
};
struct S_00cc5b90_Scope
{
    volatile int savedState;
    S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(
            reinterpret_cast<char*>(&g_ThreadData) + 0x2b4);
        savedState = *currentState;
        *currentState = 16;
    }
    __forceinline ~S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(
            reinterpret_cast<char*>(&g_ThreadData) + 0x2b4);
        *currentState = savedState;
    }
};
struct S_00cc5b90_PendingAllocation
{
    S_00cc5b90_Node* object;
    explicit S_00cc5b90_PendingAllocation(S_00cc5b90_Node* p) : object(p) {}
    __forceinline ~S_00cc5b90_PendingAllocation() { if (object) FUN_00aa4060(object); }
    void Transfer() { object = 0; }
};

struct SaveBody {
 unsigned int field000;
 unsigned int field004;
 unsigned int field008;
 unsigned int field00c;
 unsigned int field010;
 unsigned int field014;
 unsigned int field018;
 unsigned int field01c;
 SaveMatrix transform;
 SaveMatrix inverse;
 unsigned short flags;unsigned char enabled;unsigned char unk0a3;
 unsigned int field0a4;
 unsigned int field0a8;
 unsigned int field0ac;
 unsigned int field0b0;
 unsigned int field0b4;
 unsigned int field0b8;
 unsigned int field0bc;
 unsigned int field0c0;
 unsigned int field0c4;
 unsigned int field0c8;
 unsigned int field0cc;
 unsigned int field0d0;
 unsigned int field0d4;
 unsigned int field0d8;
 unsigned int field0dc;
 unsigned int field0e0;
 unsigned int field0e4;
 unsigned int field0e8;
 unsigned int field0ec;
 unsigned int field0f0;
 unsigned int field0f4;
 unsigned int field0f8;
 unsigned int field0fc;
 unsigned int field100;
 unsigned int field104;
 unsigned int field108;
 unsigned int field10c;
 unsigned int field110;
 unsigned int field114;
 unsigned int field118;
 unsigned int field11c;
 unsigned int field120;
 unsigned int field124;
 unsigned int field128;
 unsigned int field12c;
 unsigned int field130;
};
struct SaveObject {
 int unk00;SaveBody* body;
 void FUN_00c8a280(SaveCtx*);
 void SaveShape(unsigned int,SaveCtx*);
 void hkRagdollConstraintCinfo_SaveBinary(SaveCtx*);
};
// Calls FUN_00c8a280, writes transform, inverse and six more body fields to the stream, saves the shape, and writes enabled if field0e0 is nonzero.
// @fnv 0x00cc6ef0
// pdb: hkRagdollConstraintCinfo::SaveBinary | bhkRagdollConstraint.obj | fnv360_0822_retail, objrun_sim + bridge(hash|objrun), high
void SaveObject::hkRagdollConstraintCinfo_SaveBinary(SaveCtx* stream) {
 FUN_00c8a280(stream);
 SaveBody* data=body;
 stream->m_pBinaryStream->Write(&data->transform,64);
 stream->m_pBinaryStream->Write(&data->inverse,64);
 stream->m_pBinaryStream->Write(&data->field11c,4);
 stream->m_pBinaryStream->Write(&data->field12c,4);
 stream->m_pBinaryStream->Write(&data->field130,4);
 stream->m_pBinaryStream->Write(&data->field104,4);
 stream->m_pBinaryStream->Write(&data->field108,4);
 stream->m_pBinaryStream->Write(&data->field0f8,4);
 SaveShape(data->field0e0,stream);
 if(data->field0e0)stream->m_pBinaryStream->Write(&data->enabled,1);
}

extern int DAT_0108febc; extern int DAT_010c9e5c; extern int DAT_010c9d7c;
extern int DAT_01268188; extern int DAT_01268f74; extern int DAT_01268624;
void FUN_00c876f0(); void FUN_00c87700() throw();
void* FUN_00aa13e0(unsigned int size);
struct ThreadHeapContext { unsigned int m_allocationTag; };
extern __declspec(thread) ThreadHeapContext g_threadHeapContext;
struct PhysicsNode {
    void* m_ppVirtualMethodTable; unsigned int m_sReferenceCount; unsigned int m_flags; unsigned int m_data;
    void FUN_00c87c30();
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
    PhysicsNode() {
        FUN_00c87c30(); m_ppVirtualMethodTable = &DAT_0108febc;
        unsigned int increment = 1; m_data = 0;
        DAT_01268188 += increment; m_ppVirtualMethodTable = &DAT_010c9e5c;
        DAT_01268f74 += increment; m_ppVirtualMethodTable = &DAT_010c9d7c; DAT_01268624 += increment;
    }
};
struct AllocationScope {
    unsigned int m_previousTag;
    AllocationScope() {
        m_previousTag = g_threadHeapContext.m_allocationTag;
        g_threadHeapContext.m_allocationTag = 16;
    }
    __forceinline ~AllocationScope() throw() {
        FUN_00c87700();
        g_threadHeapContext.m_allocationTag = m_previousTag;
    }
};

namespace fnv_00cc8cd0 {
extern void FUN_00cc5080();

// @fnv 0x00cc8cd0
// pdb: NiPSysModifierCtlr::RegisterStreamables | NiPSysModifierCtlr.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void FUN_00cc8cd0()
{
    FUN_00cc5080();
}
}  // namespace fnv_00cc8cd0

extern const float g_fCCE1C0DefaultScale;

struct CCE1C0MemoryManager {
    void* Allocate(unsigned int uiSize);
};
extern CCE1C0MemoryManager g_CCE1C0MemoryManager;

extern __declspec(thread) int g_CCE1C0AllocTag;

struct CCE1C0AllocTagScope {
    int m_iSaved;

    CCE1C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCE1C0AllocTag;
        g_CCE1C0AllocTag = aiAllocationTag;
    }
    ~CCE1C0AllocTagScope() { g_CCE1C0AllocTag = m_iSaved; }
};

struct CCE1C0Vec {
    float x, y, z, w;
};

template <class T>
struct CCE1C0Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CCE1C0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};

struct CCE1C0Child {
    CCE1C0Child() throw()
        : m_pkOwnerManager(0), m_fScale(g_fCCE1C0DefaultScale), m_arr08(), m_arr14()
    {
    }

    void* m_pkOwnerManager;
    float m_fScale;
    CCE1C0Array<CCE1C0Vec> m_arr08;
    CCE1C0Array<CCE1C0Vec> m_arr14;

    static void* operator new(unsigned int uiSize) throw() { return g_CCE1C0MemoryManager.Allocate(uiSize); }
    static void operator delete(void* pvMem) {}
};

extern __declspec(thread) unsigned int t_uiMemContextC01;

class AutoMemContextC01 {
public:
    AutoMemContextC01(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = t_uiMemContextC01;
        t_uiMemContextC01 = m_uiGeometryShaderFlags;
    }
    ~AutoMemContextC01() { t_uiMemContextC01 = m_uiPrevious; }
    unsigned int m_uiPrevious;
};

class hkMemoryAllocatorC01 {
public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* p, int iNumBytes);
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct hkMemoryRouterC01 {
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorC01* m_pTemp;
    hkMemoryAllocatorC01* m_pStreamAllocator;
    hkMemoryAllocatorC01& heap() { return *m_pStreamAllocator; }
};
hkMemoryRouterC01& __cdecl GetMemoryRouterC01();
template <typename T> __forceinline void constructWithCopyC01(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct hkArrayUtilC01 {
    static void __cdecl GrowArray(hkMemoryAllocatorC01& kAlloc, void* apvArray, int iSizeElem);
    static void __cdecl GrowArrayCapacity(hkMemoryAllocatorC01& kAlloc, void* apvArray, int iNumElements, int iSizeElem);
};

template <typename T> struct hkArrayC01 {
    hkArrayC01() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~hkArrayC01()
    {
        hkMemoryAllocatorC01& kAlloc = GetMemoryRouterC01().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    void clear() { m_iElementCount = 0; }
    __forceinline void ClearAndRelease()
    {
        hkMemoryAllocatorC01& kAlloc = GetMemoryRouterC01().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void AddBack(const T& t)
    {
        hkMemoryAllocatorC01& kAlloc = GetMemoryRouterC01().heap();
        if (m_iElementCount == getCapacity())
            hkArrayUtilC01::GrowArray(kAlloc, this, sizeof(T));
        constructWithCopyC01(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void reserve(hkMemoryAllocatorC01& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n) {
            int iCap2 = 2 * iCap;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            hkArrayUtilC01::GrowArrayCapacity(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(GetMemoryRouterC01().heap(), n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class NiCloningProcessC01;
class hkpShapeContainerC01;
class NiObjectC01 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual NiObjectC01* MakeClone(NiCloningProcessC01& kCloning);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual hkpShapeContainerC01* GetContainer(char* pcOut);
};

template <class K, class V> struct NiTMapItemC01 {
    NiTMapItemC01* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> class NiTMapC01 {
public:
    virtual void v00();
    virtual unsigned int KeyToHashIndex(K key) const;
    virtual bool IsKeysEqual(K key1, K key2) const;
    bool GetAt(K key, V& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTMapItemC01<K, V>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem) {
            if (IsKeysEqual(key, pkItem->m_key)) {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    unsigned int m_uiHashSize;
    NiTMapItemC01<K, V>** m_ppkHashTable;
};

class NiCloningProcessC01 {
public:
    NiTMapC01<NiObjectC01*, NiObjectC01*>* m_pCloneMap;
};

class bhkRefObjectC01 : public NiObjectC01 {
public:
    unsigned int m_uiRefCount;
    void* m_phkObject;
};

class hkpShapeC01 {
public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    bhkRefObjectC01* m_pkWrapper;
};

class hkpShapeContainerC01 {
public:
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    hkArrayC01<hkpShapeC01*> m_kChildShapes;
};

class FUN_00cdb360_cls
{
public:
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00cdb360_cls* FUN_00cdb360();
};

// Sets the twelve float fields to fixed constants and returns this.
// @fnv 0x00cdb360
// pdb: hkaKeyFrameHierarchyUtility::ControlData::ControlData | hkbRagdollDriver.obj | tesv_win, hash, low
FUN_00cdb360_cls* FUN_00cdb360_cls::FUN_00cdb360()
{
    m_00 = 0.17f;
    m_04 = 0.0f;
    m_08 = 1.0f;
    m_0c = 0.6f;
    m_10 = 0.05f;
    m_14 = 1.4f;
    m_18 = 1.8f;
    m_1c = 0.1f;
    m_20 = 0.3f;
    m_24 = 0.3f;
    m_28 = 0.03f;
    m_2c = 0.1f;
    return this;
}

// 10024 bytes of scratch stack space with no array type (the original frame
// carries no /GS cookie), spelled as nested scalar blocks sized 8..8192.
struct CcScratch8 { int m0, m1; };
struct CcScratch32 { CcScratch8 m0, m1, m2, m3; };
struct CcScratch256 { CcScratch32 m0, m1, m2, m3, m4, m5, m6, m7; };
struct CcScratch512 { CcScratch256 m0, m1; };
struct CcScratch1K { CcScratch256 m0, m1, m2, m3; };
struct CcScratch8K { CcScratch1K m0, m1, m2, m3, m4, m5, m6, m7; };
struct CcScratchBuf { CcScratch8K a; CcScratch1K b; CcScratch512 c; CcScratch256 d; CcScratch32 e; CcScratch8 f; };

struct Cc0230Self {
	void* unk00;
	void* unk04;
	hkStreamWriter* unk08;
	Cc0230Self* WriteUInt16(unsigned short w);
};

// Formats w into a buffer and writes it to the stream in unk08, returning this.
// @fnv 0x00cc0230
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, objrun, medium
// pdb params: s
Cc0230Self* Cc0230Self::WriteUInt16(unsigned short w)
{
	CcScratchBuf buffer;
	hkString_snprintf((char*)&buffer, 10024, "%u", w);
	FUN_00cc0080(unk08, (const char*)&buffer);
	return this;
}

extern const char str_01094cf0[];

struct FloatArgStream {
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;
    FloatArgStream* WriteFloat(float value);
};

// @fnv 0x00cc0320
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_debug, objrun, medium
// pdb params: f
FloatArgStream* FloatArgStream::WriteFloat(float value) {
    int buf[2506];
    hkString_snprintf((char*)buf, 0x2728, str_01094cf0, value);
    FUN_00cc0080((hkStreamWriter*)m_pSharedOwner, (const char*)buf);
    return this;
}

struct T { char pad[0x20]; unsigned short m_20; };
// @fnv 0x00cc0e00
T* volatile g_a; T* volatile g_b; T* volatile g_sink;

extern int DAT_010c93fc;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct CC1290Object {
    void __thiscall FUN_00a5d3a0();

    void* operator new(unsigned int size) { return FUN_00aa13e0(size); }

    CC1290Object() {
        FUN_00a5d3a0();
        m_pVtable = reinterpret_cast<void*>(&DAT_010c93fc);
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_uiData2 = 0;
        m_uiData3 = 0;
    }

    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
};

// Allocates and returns a new CC1290Object instance via its operator new.
// @fnv 0x00cc1290
// pdb: bhkPoseArray::CreateObject | bhkPoseArray.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
CC1290Object* __cdecl CreateCC1290Object()
{
    return new CC1290Object;
}

struct LoadMM { void* Allocate(unsigned int); };
extern LoadMM loadManager;
struct LoadTLS {
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
int unk138;
int unk13c;
int unk140;
int unk144;
int unk148;
int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
int unk170;
int unk174;
int unk178;
int unk17c;
int unk180;
int unk184;
int unk188;
int unk18c;
int unk190;
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
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
int unk24c;
int unk250;
int unk254;
int unk258;
int unk25c;
int unk260;
int unk264;
int unk268;
int unk26c;
int unk270;
int unk274;
int unk278;
int unk27c;
int unk280;
int unk284;
int unk288;
int unk28c;
int unk290;
int unk294;
int unk298;
int unk29c;
int unk2a0;
int unk2a4;
int unk2a8;
int unk2ac;
int unk2b0;
int context;
};
extern __declspec(thread) LoadTLS loadTLS;
struct LoadScope { int old; LoadScope() { old=loadTLS.context; loadTLS.context=16; } ~LoadScope() { loadTLS.context=old; } };
struct LoadIO { int unk00; unsigned int position; unsigned int (__cdecl *read)(LoadIO*,void*,unsigned int,unsigned int*,unsigned int); void Read(void* p) { unsigned int size=4; position+=read(this,p,4,&size,1); } };
struct LoadString { void* value; LoadString(); ~LoadString(); static void* operator new[](unsigned int n) { return loadManager.Allocate(n); } };
struct LoadElem { int a,b,c,d,e,f,g,h,i,j,k,l; };
struct LoadGroup { unsigned int count; LoadElem* data; LoadGroup() : count(0), data(0) {} static void* operator new(unsigned int n) { return loadManager.Allocate(n); } };
struct LoadGroupPtr { LoadGroup* value; static void* operator new[](unsigned int n) { return loadManager.Allocate(n); } };

extern int DAT_010c970c;
extern int DAT_012685c4;
struct CC3D60Base
{
    void FUN_00c87c30();
};
struct CC3D60Object : CC3D60Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }

    CC3D60Object()
    {
        unsigned int count = 1;
        FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c970c;
        DAT_012685c4 += count;
    }
};

#include <xmmintrin.h>
extern __declspec(thread) unsigned int memoryCategory;
struct ScopedMemoryCategory {
    unsigned int previous;
    ScopedMemoryCategory() : previous(memoryCategory) { memoryCategory = 16; }
    ~ScopedMemoryCategory() { memoryCategory = previous; }
};

struct hkMemoryAllocatorCC3 {
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterCC3 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorCC3* m_pStreamAllocator;
    hkMemoryAllocatorCC3& heap() { return *m_pStreamAllocator; }
};



struct CCVector {
    __m128 value;
    __forceinline void set(float x,float y,float z,float w) { value=_mm_setr_ps(x,y,z,w); }
    __forceinline CCVector& operator=(const CCVector& other) { value=other.value; return *this; }
};

class hkReferencedObjectCC3 {
public:
    virtual ~hkReferencedObjectCC3();

    void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectCC3* b = static_cast<hkReferencedObjectCC3*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void operator delete(void* p, unsigned int nbytes)
    {
        ((hkMemoryRouterCC3*)FUN_00c85750())->heap().ReleaseBlock(p, nbytes);
    }
    void FUN_00c905b0(); // removeReference

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d4d980 : public hkReferencedObjectCC3 {
public:
    FUN_00d4d980(unsigned int a, unsigned int b, int c); // FUN_00d4d980

    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __forceinline void assign(float ax,float ay,float az,float aw,float bx,float by,float bz,float bw) { m_kMinimumCorner.value=_mm_setr_ps(ax,ay,az,aw);m_kMaximumCorner.value=_mm_setr_ps(bx,by,bz,bw); }
    CCVector m_kMinimumCorner;
    CCVector m_kMaximumCorner;
    float m_fBoundRadius;
    float m_fFriction;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};

extern int DAT_010c97e4;
extern int DAT_012685d0;
struct CC42A0Base
{
    void FUN_00c87c30();
};
struct CC42A0Object : CC42A0Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }

    CC42A0Object()
    {
        unsigned int count = 1;
        FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c97e4;
        DAT_012685d0 += count;
    }
};
// Allocates and returns a new CC42A0Object instance via its operator new.
// @fnv 0x00cc42a0
// pdb: bhkAngularDashpotAction::CreateObject | bhkAngularDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
CC42A0Object* CreateCC42A0Object()
{
    return new CC42A0Object;
}

namespace c4a80 {
}

extern __declspec(thread) unsigned int t_uiMemContext4D40;
inline unsigned int GetMemContext4D40()
{
    return t_uiMemContext4D40;
}
inline void SetMemContext4D40(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContext4D40 = m_uiGeometryShaderFlags;
}
class AutoMemContext4D40 {
public:
    AutoMemContext4D40(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContext4D40();
        SetMemContext4D40(m_uiGeometryShaderFlags);
    }
    ~AutoMemContext4D40() { SetMemContext4D40(m_uiPrevious); }
    unsigned int m_uiPrevious;
};

struct MemoryManager4D40 {
    void* Allocate(unsigned int uiSize);
};
extern MemoryManager4D40 g_kMemoryManager4D40;

class PolyBase4D40 {
public:
    void* m_pVtable;
};

struct Interface4D40 {
    Interface4D40() {}
    int m_iFirst;
    int m_iArrayLength;
    int m_iA;
    int m_iB;
};

class Object4D40 : public PolyBase4D40, public Interface4D40 {
public:
    static void* operator new(unsigned int uiSize) throw() { return g_kMemoryManager4D40.Allocate(uiSize); }
    Object4D40() { Interface4D40* self = this; m_iArrayLength = 1; m_iA = 0; m_iB = 0; m_pVtable = &DAT_010c99e0; self->m_iFirst = 0; }
};

extern __declspec(thread) int g_tlsMemContext;
struct ViewerMemoryContext {
    int previous;
    ViewerMemoryContext() : previous(g_tlsMemContext) { g_tlsMemContext = 16; }
    ~ViewerMemoryContext() { g_tlsMemContext = previous; }
};
struct ViewerStrings {
    void* vtable;
    char** values;
    unsigned short capacity, count, used, growth;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
    void Append(char* value) {
        unsigned int index = count;
        if (index >= capacity) FUN_0096ad30(index + growth);
        FUN_0096ae90(index, value);
    }
};
struct ViewerConstraint {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual int type();
};
char* __cdecl FUN_00a7d550(const char*, float);
extern const char DAT_010c9a04[], DAT_010c99f8[];
struct ViewerFlag { unsigned char value; operator bool() const { return value != 0; } };
struct ViewerData {
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    ViewerConstraint* constraint;
    int unk1C;
    float strength;
    ViewerFlag enabled;
    ViewerConstraint* GetConstraint() { return constraint; }
};
struct DataViewer {
    void* vtable;
    ViewerData* data;
    void FUN_00c8a560(ViewerStrings*);
    ViewerData* GetData() { return data; }
    float Strength() { return GetData() ? GetData()->strength : 0.0f; }
    bool Enabled() { return GetData() ? bool(GetData()->enabled) : false; }
    ViewerConstraint* Constraint() { return GetData() ? GetData()->GetConstraint() : 0; }
    void FUN_00cc4f00(ViewerStrings* strings);
};

struct FUN_00d4f2a0 {
    int unk00;
    unsigned short m_us4;
    FUN_00d4f2a0();
    void* operator new(unsigned int, unsigned int n) {
        void* b = FUN_00c85750()->heap().AllocateMemoryBlock(n);
        ((FUN_00d4f2a0*)b)->m_us4 = (unsigned short)n;
        return b;
    }
    void operator delete(void*, unsigned int) {}
};

struct O9410;

struct G9410
{
    O9410* m_pSharedOwner;
    G9410(void* p) { m_pSharedOwner = (O9410*)p; }
    ~G9410();
};

struct O9410
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    void* m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiValue1;

    void SetChildObject(int flag);
    void FUN_00cc9410();
};

extern "C" void* DAT_010ca22c;
extern __declspec(thread) int DAT_012722b4;

struct S00cc9560_TlsFlag {
    int m_saved;
    S00cc9560_TlsFlag() {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cc9560_TlsFlag() {
        DAT_012722b4 = m_saved;
    }
};

struct CacheValueVbase {
    void* m_pVtbl;
};
struct CacheValueFields {
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    CacheValueFields() {
        m_uiRefCount = 0;
        m_uiValue1 = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
    }
};
struct CacheValueMid {
    unsigned int m_uiData3;
    unsigned int m_uiData4;
    CacheValueMid() {
        m_uiData3 = 0;
        m_uiData4 = 0;
    }
};
struct CacheValue : CacheValueVbase, CacheValueFields, CacheValueMid {
    unsigned int m_uiCapacityAndFlags;
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiFinalFlags;
    CacheValue() : CacheValueFields(), CacheValueMid() {
        m_uiCapacityAndFlags = 0x80000000;
        m_pVtbl = &DAT_010ca22c;
        m_pData = 0;
        m_uiSize = 0;
        m_uiFinalFlags = 0x80000000;
    }
    static void* operator new(unsigned int size) throw() {
        return reinterpret_cast<CC7970_Allocator*>(&DAT_011f6238)->FUN_00aa3e40(size);
    }
};

extern int DAT_010ca744;
extern "C" int DAT_01268678;
extern "C" int (__cdecl *DAT_00fdf1c4)(void*);

class NiRefObject {
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};

struct FUN_00ccbc00_elem {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C;
    unsigned int unk10; unsigned int m_14; unsigned int unk18; unsigned int unk1C;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C;
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
};

struct FUN_00ccbc00_inner {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C;
    unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1C;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C;
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
    unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6C;
    unsigned int unk70; unsigned int unk74; unsigned int unk78; unsigned int unk7C;
    unsigned int unk80; unsigned int unk84; unsigned int unk88; unsigned int unk8C;
    unsigned int unk90; unsigned int unk94; unsigned int unk98; unsigned int unk9C;
    unsigned int unkA0; unsigned int unkA4; unsigned int unkA8; unsigned int unkAC;
    unsigned int unkB0; FUN_00ccbc00_elem* m_b4; unsigned int m_b8;
};


struct CcbcOwnerBase {
    void FUN_00c876a0();
    void FUN_00cd2de0();
    ~CcbcOwnerBase() { FUN_00cd2de0(); }
};

struct RefSmartPtr {
    NiRefObject* ptr;
    ~RefSmartPtr() {
        NiRefObject* p = ptr;
        if (p) {
            if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0) p->DeleteThis();
        }
    }
};

class FUN_00ccbc00 : public CcbcOwnerBase {
public:
    void* volatile m_pVtable;
    unsigned int unk04;
    FUN_00ccbc00_inner* volatile m_08;
    unsigned int unk0c;
    unsigned int unk10;
    RefSmartPtr m_14;
    ~FUN_00ccbc00();
};

// Sets vtable to DAT_010ca744, zeroes m_14 in each m_b4 element, calls FUN_00c876a0, decrements DAT_01268678, and releases m_14.ptr.
// @fnv 0x00ccbc00
FUN_00ccbc00::~FUN_00ccbc00() {
    m_pVtable = (void*)&DAT_010ca744;
    FUN_00ccbc00_inner* x = m_08;
    if ((int)x->m_b8 > 0) {
        int n = (int)x->m_b8;
        unsigned int off = 0;
        do {
            *(unsigned int*)((char*)x->m_b4 + off + 0x14) = 0;
            off += 0x60;
        } while (--n != 0);
    }
    FUN_00c876a0();
    int one = 1;
    DAT_01268678 -= one;
    NiRefObject* p = m_14.ptr;
    if (p) {
        if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0) p->DeleteThis();
        m_14.ptr = 0;
    }

}

static volatile float S00ccd2c0_sink;

struct EE60Vec
{
    __m128 m_vComponents;

    __forceinline void operator=(const EE60Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline float& operator()(int i) { return m_vComponents.m128_f32[i]; }
};

struct EE60Mat
{
    EE60Vec m_kColumn0;
    EE60Vec m_kColumn1;
    EE60Vec m_kColumn2;

    __forceinline void setIdentity()
    {
        EE60Vec zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct EE60Xf
{
    EE60Mat m_rotation;
    EE60Vec m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

extern __declspec(thread) int g_EE60Ctx;
inline int GetMemContext() { return g_EE60Ctx; }
inline void SetMemContext(int aiMemoryContext) { g_EE60Ctx = aiMemoryContext; }
struct MemContextGuard {
    int m_iSaved;
    MemContextGuard(int aiMemoryContext) { m_iSaved = GetMemContext(); SetMemContext(aiMemoryContext); }
    ~MemContextGuard() { SetMemContext(m_iSaved); }
};

class EE60MemMgr { public: void* Allocate(unsigned int); };
extern EE60MemMgr g_EE60MemMgr;

extern float DAT_010c72bc;

struct CcEE60Data
{
    int unk00;
    float m_f04;
    int unk08;
    int unk0C;
    EE60Xf m_kMotionTransform;

    static void* operator new(unsigned int nbytes)
    {
        unsigned char* p = (unsigned char*)g_EE60MemMgr.Allocate(nbytes + 16);
        unsigned char offset = (unsigned char)(16 - ((unsigned int)p & 15));
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void* p);

    CcEE60Data()
    {
        unk00 = 0;
        m_f04 = DAT_010c72bc;
        unk08 = 0;
        m_kMotionTransform.setIdentity();
    }
};

struct WorkingState { __declspec(align(16)) unsigned char data[512]; };
struct Arg;
struct ActionTarget {
virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
virtual void v52();
    virtual void apply(Arg* first, Arg* second);
};
struct Result { int ReportDiagnostic; int unused4; ActionTarget* action; };
struct Cursor {
    virtual void reserved0();
    virtual void reserved1();
    virtual int first();
    virtual int next(int index);
    virtual void FunctionAtSlot4();
    virtual Result* lookup(int index, WorkingState* state);
};
struct Collection {
    int unk00, unk04, unk08, unk0C;
    Cursor cursor;
};

struct TargetAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReleaseBlock(void* data, int size);
    void ReturnMemory(void* data, int size) { ReleaseBlock(data, size); }
};
template<class T> struct AllocatorArray {
    T* data;
    int size;
    int capacityAndFlags;
    static void deallocate(TargetAllocator& a, T* p, int n) { a.ReturnMemory(p, n * int(sizeof(T))); }
    int GetLogicalSize() const { return size; }
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void ClearAndRelease(TargetAllocator& allocator) {
        size = 0;
        if (!(capacityAndFlags & 0x80000000))
            deallocate(allocator, data, getCapacity());
        data = 0;
        capacityAndFlags = 0x80000000;
    }
    void ClearAndRelease() {
        ClearAndRelease(reinterpret_cast<TargetAllocator&>(FUN_00c85750()->heap()));
    }
    ~AllocatorArray() { ClearAndRelease(reinterpret_cast<TargetAllocator&>(FUN_00c85750()->heap())); }
};

struct __declspec(align(16)) hkMatrix3_Scaled {
    __m128 col0;
    __m128 col1;
    __m128 col2;
    const __m128* __thiscall FUN_00cd4d40(const __m128* scale, const hkMatrix3_Scaled* source);
};

void* __cdecl FUN_00aa13e0(unsigned int size);
void __cdecl FUN_00aa1460(void* p);
extern float DAT_010c72bc;
namespace nd {
struct Arr { void* p; unsigned int n; unsigned int cap; Arr() : p(0), n(0), cap(0x80000000) {} };
}
class FUN_00cce290 {
public:
    int m_iWordAt00;
    float m_iWordAt04;
    nd::Arr m_8;
    nd::Arr m_14;
    FUN_00cce290() : m_iWordAt00(0) {}
    ~FUN_00cce290();
};
struct SrcD;
struct SrcD { int m_iWordAt00; int m_iWordAt04; };
class FUN_00cd7e80 {
public:
    char pad[0x14];
    FUN_00cd7e80(FUN_00cce290* data);
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
    static void operator delete(void* p) { FUN_00aa1460(p); }
};

struct FUN_00cdb290 {
    void FUN_00cda690();
    StateResetPart* ResetStates();
    StateResetPart* FUN_00cdb0a0();
};

// @fnv 0x00cdb0a0
// pdb: WaterShader::ReloadShaders | WaterShader.obj | fnv360_0822_debug, caller_sim, low
StateResetPart* FUN_00cdb290::FUN_00cdb0a0()
{
    FUN_00cda690();
    return ResetStates();
}

namespace fnv_00cdb0b0 {
template<class T> struct PoseArray {
    T* data;
    int size;
    int capacity;
    T& operator[](int i) { return data[i]; }
};
struct PoseTransform {
    __m128 translation;
    __m128 rotation;
    __m128 scale;
};
struct PoseBone {
    const char* name;
    bool locked;
    unsigned char unk05;
    unsigned short unk06;
};
struct PoseSkeleton {
    int unk00;
    int unk04;
    int unk08;
    PoseArray<short> parents;
    PoseArray<PoseBone> bones;
    PoseArray<PoseTransform> referencePose;
};
struct FUN_00cdb290 {
    PoseSkeleton* skeleton;
    PoseArray<PoseTransform> localPose;
    PoseArray<PoseTransform> modelPose;
    PoseArray<unsigned int> flags;
    void FUN_00cda690();
    void UpdateLockedPoseFlags();
};
}  // namespace fnv_00cdb0b0

struct __declspec(align(16)) EntryData { __m128 coordinates,rotation,metadata; };

namespace fnv_00cdd320 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
};

}  // namespace fnv_00cdd320

namespace scdd360 {

}

struct hkVector4_s {
    __m128 m_vComponents;
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
};

struct hkRotation_s {
    hkVector4_s m_kColumn0;
    hkVector4_s m_kColumn1;
    hkVector4_s m_kColumn2;
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransform_s {
    hkRotation_s m_rotation;
    hkVector4_s m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

struct hkBool_s {
    char m_cBooleanValue;
    hkBool_s(bool b) { m_cBooleanValue = (char)b; }
};


struct RefObjectBase_s {
    virtual void vfunc00();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObjectBase_s() { m_sReferenceCount = 1; }
};

struct ConstraintDataBase_s : RefObjectBase_s {
    int m_ulUserData;
    ConstraintDataBase_s() { m_ulUserData = 0; }
    void setSolvingFlag(hkBool_s flag);
};

extern "C" void _ReadWriteBarrier();
extern float DAT_0104da48;

#include <string.h>

struct __declspec(align(16)) Q1420V4
{
    float x;
    float y;
    float z;
    float w;
    Q1420V4& operator=(const Q1420V4& o)
    {
        *(__m128*)this = *(const __m128*)&o;
        return *this;
    }
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char DAT_010c94a4, DAT_010c9498, str_010c9488;
extern "C" unsigned int DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* name);
struct FUN_00a7b2e0 {
 unsigned int unk04, unk08;

 FUN_00a7b2e0();
 virtual ~FUN_00a7b2e0();
};
struct ExtraMember {
 void* vptr; unsigned int unk10,unk14,unk18,unk1c,count;
 ExtraMember() { unk14=0; count=1; unk18=0; unk1c=0; unk10=0; vptr=&DAT_010c9498; }
 ~ExtraMember();
};
struct NameRef {
 char* name;
 NameRef(const char* n) { name=FUN_00a5b690(n); }
 ~NameRef() throw() { if ((unsigned int)name!=DAT_0109b220) InterlockedDecrement((long volatile*)(name-8)); }
};
struct bhkExtraData : FUN_00a7b2e0 { // src: F3_EXE vtable 0x00e7a35c (old: FUN_00cc1d80)
 ExtraMember member;

 void AssignFixedString(const void*);
 bhkExtraData();
 ~bhkExtraData();
};
// Constructs the object and calls AssignFixedString with a name reference built from the string at str_010c9488.
// @fnv 0x00cc1d80
// pdb: bhkExtraData::bhkExtraData | bhkExtraData.obj | fnv360_0721_beta, caller_sim, low
bhkExtraData::bhkExtraData() {

 AssignFixedString(&NameRef(&str_010c9488));
}

class CC4180Base {
public:
    virtual ~CC4180Base();

    void Shutdown();
};

class FUN_00cc4180 : public CC4180Base {
public:
    virtual ~FUN_00cc4180();

    static unsigned int ms_uiInstances;
};

// Calls Shutdown and decrements the static instance counter ms_uiInstances.
// @fnv 0x00cc4180
FUN_00cc4180::~FUN_00cc4180()
{
    Shutdown();
    --ms_uiInstances;
}

class CC47F0Base {
public:
    virtual ~CC47F0Base();
};

extern int g_iCC47F0Count;

class FUN_00cc47f0 : public CC47F0Base {
public:
    void Release();

    virtual ~FUN_00cc47f0();
};

// Destructor that calls Release and decrements the global g_iCC47F0Count.
// @fnv 0x00cc47f0
FUN_00cc47f0::~FUN_00cc47f0() {
    Release();
    --g_iCC47F0Count;
}

extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);

class FUN_00cc7e50 {
public:
    FUN_00cc7e50();
    virtual ~FUN_00cc7e50();

    static void operator delete(void* pvMem, unsigned int uiSize) { operator_delete_sized(pvMem, uiSize); }

    int unk04;
    int unk08;
    int unk0C;
};

// @fnv 0x00cc7e50
FUN_00cc7e50::FUN_00cc7e50()
{
}

struct FUN_00cc9dd0 {
    FUN_00cc9dd0();
    virtual ~FUN_00cc9dd0();

    static void operator delete(void* p, unsigned int size);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// @fnv 0x00cc9dd0
FUN_00cc9dd0::FUN_00cc9dd0()
{
}



struct FUN_00ccbb50 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~FUN_00ccbb50();
    static void operator delete[](void* p) { g_memoryManager.Deallocate(p); }
};

class FUN_00ccc720 : public NiRefObject {
public:
    unsigned int unk08;
    FUN_00ccbb50* entries;
    virtual ~FUN_00ccc720();
};

// Destructor that deletes the entries array inside an AutoMemContext(16) scope.
// @fnv 0x00ccc720
FUN_00ccc720::~FUN_00ccc720() {
    AutoMemContext context(16);
    delete[] entries;
}

namespace fnv_00cd3ad0 {
struct CD3AD0Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct CD3AD0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CD3AD0Allocator* m_pStreamAllocator;

    CD3AD0Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CD3AD0MemoryRouter& __cdecl FUN_00c85750();

class FUN_00cd3ad0 {
// @fnv 0x00cd3ad0
public:
    FUN_00cd3ad0() {}
    virtual ~FUN_00cd3ad0();

    static void* operator new(unsigned int, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void operator delete(void* p, unsigned int nbytes)
    {
        if (p)
            FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
};

}  // namespace fnv_00cd3ad0

extern "C" unsigned __int64 __rdtsc(void);
extern "C" int DAT_0126835c;
extern "C" void* DAT_00fdf044;

struct FUN_00cdfe00_Object {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual int* vf40();
};

void __cdecl hkpWorldConstraintUtil_removeAndDeleteModifier(int* a, FUN_00cdfe00_Object* b, int c);

typedef void* (__stdcall *TlsGetValueFunc)(int);

// If vf40 returns non-null, calls vf18 on param2, logs a TtClrSurfVel TLS entry, calls hkpWorldConstraintUtil_removeAndDeleteModifier(result, param2, 0x1a), then logs an Et entry.
// @fnv 0x00cdfe00
// pdb: hkpResponseModifier::clearSurfaceVelocity | hkpResponseModifier.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
void hkpResponseModifier_clearSurfaceVelocity(FUN_00cdfe00_Object* param1, FUN_00cdfe00_Object* param2) {
    int* result = param1->vf40();
    if (result != 0) {
        param2->vf18();

        TlsGetValueFunc getTls = reinterpret_cast<TlsGetValueFunc>(DAT_00fdf044);
        char* pTlsBuffer = reinterpret_cast<char*>(getTls(DAT_0126835c));

        char* entry = *reinterpret_cast<char**>(pTlsBuffer + 4);
        if (entry < *reinterpret_cast<char**>(pTlsBuffer + 0xC)) {
            *reinterpret_cast<const char**>(entry) = "TtClrSurfVel";
            _ReadWriteBarrier();
            volatile unsigned int timestamp = __rdtsc();
            *reinterpret_cast<unsigned int*>(entry + 4) = timestamp;
            *reinterpret_cast<char**>(pTlsBuffer + 4) = entry + 12;
        }

        hkpWorldConstraintUtil_removeAndDeleteModifier(result, param2, 0x1a);

        pTlsBuffer = reinterpret_cast<char*>(getTls(DAT_0126835c));
        entry = *reinterpret_cast<char**>(pTlsBuffer + 4);
        if (entry < *reinterpret_cast<char**>(pTlsBuffer + 0xC)) {
            *reinterpret_cast<const char**>(entry) = "Et";
            _ReadWriteBarrier();
            volatile unsigned int timestamp = __rdtsc();
            *reinterpret_cast<unsigned int*>(entry + 4) = timestamp;
            *reinterpret_cast<char**>(pTlsBuffer + 4) = entry + 12;
        }
    }
}

struct LocalBinaryStream {
    void* vtable;
    unsigned int position;
    unsigned int (__cdecl *read)(LocalBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* p, unsigned int bytes, unsigned int* sizes, unsigned int count) {
        unsigned int result = read(this,p,bytes,sizes,count);
        position += result;
        return result;
    }
    void Read(void* p, unsigned int bytes) {
        unsigned int size = bytes;
        BinaryRead(p,bytes,&size,1);
    }
};

struct LocalStream {
    void* vtable;
    unsigned int version;
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
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    LocalBinaryStream* input;
};

struct LocalReference { void removeReference(); };

struct RagdollConstraintData {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    __m128 axisA;
    __m128 planeA;
    __m128 binormalA;
    __m128 pivotA;
    __m128 axisB;
    __m128 planeB;
    __m128 binormalB;
    __m128 pivotB;
    unsigned short atomType;
    unsigned char enabled;
    unsigned char unk0a3;
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
    float maxFrictionTorque;
    unsigned int unk0fc;
    unsigned int unk100;
    float twistMin;
    float twistMax;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    float coneMax;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    float planeMin;
    float planeMax;
    void FUN_00cdea70(LocalReference*);
    void FUN_00cdeab0(LocalReference*);
    void FUN_00cdea90(LocalReference*);
};

struct FUN_00d53200_class {
    void* vtable;
    RagdollConstraintData* data;
    void FUN_00c8a230(LocalStream&);
    LocalReference* FUN_00c8a330(LocalStream&);
    void FUN_00cc6b80(LocalStream&);
};


extern const float DAT_01011d78;
extern const float DAT_01016248;
extern const float DAT_01017718;

namespace fnv_00cc8e60 {
struct ReadIO {
    int unk00;
    unsigned int m_04;
    unsigned int (__cdecl *m_08)(ReadIO*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p) { unsigned int size = 4; unsigned int n = m_08(this, p, 4, &size, 1); m_04 += n; return n; }
};

struct ReadData {
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

    void __thiscall Push(void* first, void* second);
};

struct ReadContext {
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
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
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
    ReadIO* io;
};



struct ReadVec { float x,y,z,w; };

struct FUN_00d53200_class {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();

    ReadData* m_04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ReadVec* m_20;
    int m_24;

    void FUN_00d53200(NiStream&);
    void __thiscall FUN_00cc8e60(ReadContext* owner);
};

}  // namespace fnv_00cc8e60

extern float DAT_0104da48;

struct ContactSource {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28;
    unsigned int m_uiCollisionFilterData;
    void FUN_00c905b0();
};

struct ContactHit;

struct ContactListener {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void OnEnter(ContactHit* hit);
    virtual void OnStay(ContactHit* hit);
};

struct ContactHandler {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    ContactListener* m_kListener;
};

struct ContactUser {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    ContactHandler* m_handler;
};

struct ContactOwner {
    int unk00; int unk04;
    ContactUser* m_user;
    void* getUserData() const { return m_user; }
};

struct ContactCollidable;
__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out);
struct ContactCollidable {
    int unk00; int unk04; int unk08; int unk0C;
    signed char m_iOwnerOffset;
    void* getOwner() const { return (char*)this + m_iOwnerOffset; }
};

struct ContactHit {
    int m_00; int m_04; int m_08; int m_0c;
    int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c;
    int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44;
    ContactCollidable* m_kCollidable;
    int m_4c;
    int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c;
};

struct CopyBlock8 {
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

template <int N> struct MemCpyAligned {
    static __forceinline void copy(void* dst, const void* src)
    {
        const CopyBlock8* s = (const CopyBlock8*)src;
        CopyBlock8* d = (CopyBlock8*)dst;
        for (int i=0; i<N/8; i++) d[i]=s[i];
        if (N==4) *(unsigned int*)dst=*(const unsigned int*)src;
    }
};

__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    out = owner ? owner->m_user : 0;
}

__forceinline void* getUserData(const ContactCollidable* c)
{
    const ContactOwner* owner = (const ContactOwner*)c->getOwner();
    return owner ? owner->getUserData() : 0;
}

__forceinline ContactUser* getUser(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    return owner ? owner->m_user : 0;
}

__forceinline ContactUser* getUser2(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    if (!owner) {
        return 0;
    }
    return owner->m_user;
}

template <class T> struct ContactArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index) {
            MemCpyAligned<sizeof(T)>::copy(&m_data[index], &m_data[m_iElementCount]);
        }
    }
};

struct TriggerCollector : FUN_00cd3410 {
    ContactArray<ContactSource*>& sources() { return *(ContactArray<ContactSource*>*)&m_a1; }
    ContactArray<int>& states() { return *(ContactArray<int>*)&m_a2; }
    ContactArray<ContactHit>& hits() { return *(ContactArray<ContactHit>*)&m_a3; }
    void ProcessContactEvents();
};

struct __declspec(align(16)) QuadCDA { float x, y, z, w; };
__forceinline __m128& quad(QuadCDA& q) { return *(__m128*)&q; }
__forceinline const __m128& quad(const QuadCDA& q) { return *(const __m128*)&q; }

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_rcp_ps(__m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);

extern const __m128 DAT_010c7170;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c4c10;

class hkQuaternionCDA;

class hkVector4CDA {
public:
    QuadCDA m_vComponents;

    __forceinline hkVector4CDA& operator=(const hkVector4CDA& v)
    {
        quad(m_vComponents) = quad(v.m_vComponents);
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CDA& a, const hkVector4CDA& b) { quad(m_vComponents) = _mm_add_ps(quad(a.m_vComponents), quad(b.m_vComponents)); }
    __forceinline void add4(const hkVector4CDA& a) { quad(m_vComponents) = _mm_add_ps(quad(m_vComponents), quad(a.m_vComponents)); }
    __forceinline void setMul4(const hkVector4CDA& a, const hkVector4CDA& b) { quad(m_vComponents) = _mm_mul_ps(quad(a.m_vComponents), quad(b.m_vComponents)); }
    __forceinline void addMul4(const hkVector4CDA& a, const hkVector4CDA& b) { quad(m_vComponents) = _mm_add_ps(quad(m_vComponents), _mm_mul_ps(quad(a.m_vComponents), quad(b.m_vComponents))); }
    __forceinline void addMul4(__m128 s, const hkVector4CDA& b) { quad(m_vComponents) = _mm_add_ps(quad(m_vComponents), _mm_mul_ps(_mm_shuffle_ps(s, s, 0), quad(b.m_vComponents))); }
    __forceinline void setNeg4(const hkVector4CDA& a) { quad(m_vComponents) = _mm_xor_ps(quad(a.m_vComponents), DAT_010c44d0); }
    __forceinline void setCross(const hkVector4CDA& v1, const hkVector4CDA& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(quad(v1.m_vComponents), quad(v1.m_vComponents), 0xc9), _mm_shuffle_ps(quad(v2.m_vComponents), quad(v2.m_vComponents), 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(quad(v1.m_vComponents), quad(v1.m_vComponents), 0xd2), _mm_shuffle_ps(quad(v2.m_vComponents), quad(v2.m_vComponents), 0xc9));
        quad(m_vComponents) = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CDA& v) const
    {
        __m128 x2 = _mm_mul_ps(quad(m_vComponents), quad(v.m_vComponents));
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CDA& v)
    {
        quad(m_vComponents) = _mm_rcp_ps(quad(v.m_vComponents));
        __m128 rr = _mm_mul_ps(_mm_mul_ps(quad(m_vComponents), quad(v.m_vComponents)), quad(m_vComponents));
        quad(m_vComponents) = _mm_sub_ps(_mm_add_ps(quad(m_vComponents), quad(m_vComponents)), rr);
    }
    void SetRotatedDirection(const hkQuaternionCDA& q, const hkVector4CDA& dir);
    void setRotatedInverseDir(const hkQuaternionCDA& q, const hkVector4CDA& dir);
};

class hkQuaternionCDA {
public:
    hkVector4CDA m_vec;

    __forceinline void SetConjugate(const hkQuaternionCDA& q) { quad(m_vec.m_vComponents) = _mm_xor_ps(quad(q.m_vec.m_vComponents), DAT_010c4c00); }
    void FUN_00c66320(const hkQuaternionCDA& q0, const hkQuaternionCDA& q1);
};


class hkQsTransformCDA {
public:
    hkVector4CDA m_vTranslation;
    hkQuaternionCDA m_rotation;
    hkVector4CDA m_vScale;

    struct InvTR {
        hkVector4CDA m_vTranslation;
        hkQuaternionCDA m_rotation;
        hkVector4CDA m_vScale;

        __forceinline void SetConjugate(const hkQsTransformCDA& t)
        {
            m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
            m_vTranslation.setNeg4(m_vTranslation);
            m_rotation.SetConjugate(t.m_rotation);
            hkVector4CDA scale;
            quad(scale.m_vComponents) = _mm_shuffle_ps(quad(t.m_vScale.m_vComponents), _mm_unpackhi_ps(quad(t.m_vScale.m_vComponents), DAT_010c7170), 0xc4);
            m_vScale.setReciprocal4(scale);
            quad(m_vScale.m_vComponents) = _mm_and_ps(quad(m_vScale.m_vComponents), DAT_010c4c10);
        }
    };

    __forceinline void SetProduct(const InvTR& t1, const hkQsTransformCDA& t2)
    {
        hkVector4CDA temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        quad(m_vScale.m_vComponents) = _mm_mul_ps(quad(t2.m_vScale.m_vComponents), quad(t1.m_vScale.m_vComponents));
    }
    __forceinline void SetMulInverse(const hkQsTransformCDA& a, const hkQsTransformCDA& b)
    {
        InvTR h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
};

template <typename T>
class hkArrayCDA
{
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
};

struct hkaSkeletonCDA
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int m_parentIndicesSize;
    int m_parentIndicesCap;
    int unk18;
    int m_iBoneCount;
};

struct hkBoolCDA {
    char m_cBooleanValue;
    __forceinline hkBoolCDA& operator=(bool b) { m_cBooleanValue = b; return *this; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};

class hkaPoseCDA
{
public:
    enum { F_DIRTY_LOCAL = 0x1, F_DIRTY_MODEL = 0x2, F_INTERNAL1 = 0x4 };
    hkaSkeletonCDA* m_pSkeleton;
    hkArrayCDA<hkQsTransformCDA> m_pLocalPose;
    hkArrayCDA<hkQsTransformCDA> m_pModelPose;
    hkArrayCDA<unsigned int> m_pBoneFlags;
    hkBoolCDA m_bPoseFlag;
    hkBoolCDA m_bPoseInitialized;

    const hkQsTransformCDA& FUN_00cda180(int boneIdx);

    __forceinline void makeFirstChildrenModelSpace(int boneIdx)
    {
        const int nb = m_pSkeleton->m_iBoneCount;
        for (int b = boneIdx + 1; b < nb; ++b)
        {
            const int i = b;
            if (m_pSkeleton->m_kParentIndices[i] == boneIdx)
            {
                if (m_pBoneFlags[i] & F_DIRTY_MODEL)
                    FUN_00cda180(i);
                m_pBoneFlags[i] = F_DIRTY_LOCAL;
                m_bPoseInitialized = false;
            }
        }
    }

    __forceinline int isFlagOn(int boneIdx, int flag) const { return m_pBoneFlags[boneIdx] & flag; }
    __forceinline void setFlag(int boneIdx, unsigned int flag) { m_pBoneFlags[boneIdx] |= flag; }
    __forceinline void clearFlag(int boneIdx, unsigned int flag) { m_pBoneFlags[boneIdx] &= ~flag; }

    __forceinline const hkQsTransformCDA& calculateBoneLocalSpace(int boneIdx)
    {
        const hkQsTransformCDA& modelFromBone = m_pModelPose[boneIdx];
        const short parentIdx = m_pSkeleton->m_kParentIndices[boneIdx];
        if (parentIdx != -1)
        {
            const hkQsTransformCDA& modelFromParent = isFlagOn(parentIdx, F_DIRTY_MODEL) == 0
                ? m_pModelPose[parentIdx] : FUN_00cda180(parentIdx);
            m_pLocalPose[boneIdx].SetMulInverse(modelFromParent, modelFromBone);
        }
        else
        {
            m_pLocalPose[boneIdx] = m_pModelPose[boneIdx];
        }
        clearFlag(boneIdx, F_DIRTY_LOCAL);
        return m_pLocalPose[boneIdx];
    }

    __forceinline void makeAllChildrenLocalSpace(int boneIdx)
    {
        const int numBones = m_pSkeleton->m_iBoneCount;
        setFlag(boneIdx, F_INTERNAL1);
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            const short parentIdx = m_pSkeleton->m_kParentIndices[i];
            if (parentIdx != -1 && isFlagOn(parentIdx, F_INTERNAL1))
            {
                if (isFlagOn(i, F_DIRTY_LOCAL))
                    calculateBoneLocalSpace(i);
                setFlag(i, F_INTERNAL1);
                m_bPoseFlag = false;
            }
        }
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            unsigned int& f = m_pBoneFlags[i];
            if (f & F_INTERNAL1)
                f = (f & ~F_INTERNAL1) | F_DIRTY_MODEL;
        }
    }

    hkQsTransformCDA& FUN_00cdad80(int boneIdx, int propagate);
};

namespace fnv_00cc1cf0 {
#include <windows.h>


// Stand-in for the game's NiTimeController: a reference-counted, polymorphic
// object whose reference counter lives at +4 and whose "release" virtual sits
// in the second vtable slot.
struct FNV_TCtrl {
    virtual void FNV_v0();
    virtual void FNV_Release();
    virtual void FNV_DecRefCount();
    virtual void FNV_IncRefCount();
    unsigned int m_uiRefCount;
};

// Stand-in for the game's NiPointer<NiTimeController>: a single pointer whose
// destructor drops the reference (that destructor is what gives the enclosing
// function its exception-handling frame).
struct FNV_TCtrlPtr {
    FNV_TCtrl* m_pObject;
    FNV_TCtrlPtr(FNV_TCtrl* object = 0) { m_pObject = object; if (m_pObject) m_pObject->FNV_IncRefCount(); }
    ~FNV_TCtrlPtr() { if (m_pObject) m_pObject->FNV_DecRefCount(); }
};

// Stand-in for the game's NiTLargeArray<NiPointer<NiTimeController> >.
struct FNV_TCtrlArray {
    void** m_ppVirtualMethodTable;
    FNV_TCtrlPtr* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void FUN_00cc1cf0();
};

// Releases every element in the array by decrementing ref counts and calling FNV_Release when the count reaches zero, then resets m_uiSize and m_uiESize.
// @fnv 0x00cc1cf0
void FNV_TCtrlArray::FUN_00cc1cf0() {
    for (unsigned int i = 0; i < m_uiSize; i++) {
        FNV_TCtrlPtr ptr;
        FNV_TCtrlPtr* pElem = &m_pBase[i];
        FNV_TCtrl* pCtrl = pElem->m_pObject;
        if (pCtrl) {
            if (InterlockedDecrement((volatile LONG*)&pCtrl->m_uiRefCount) == 0) {
                pCtrl->FNV_Release();
            }
            pElem->m_pObject = 0;
        }
    }
    m_uiSize = 0;
    m_uiESize = 0;
}
}  // namespace fnv_00cc1cf0

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);


extern "C" int DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct Key4
{
    int v;
    Key4(const Key4& other) : v(other.v) {}
};

struct Mat4
{
    __m128 rows[4];
};

struct HitBool
{
    unsigned char value;
    HitBool(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};

struct Rotation3 { __m128 a, b, c; };

static __forceinline void Transpose(Rotation3& out, const Mat4* m)
{
    __m128 r0 = m->rows[0];
    __m128 r1 = m->rows[1];
    __m128 r2 = m->rows[2];
    __m128 lo = _mm_unpacklo_ps(r0, r1);
    __m128 hi = _mm_unpackhi_ps(r0, r1);
    out.a = _mm_movelh_ps(lo, r2);
    out.b = _mm_shuffle_ps(_mm_movehl_ps(hi, lo), r2, 0xd4);
    out.c = _mm_shuffle_ps(hi, r2, 0xe4);
}

extern "C" int DAT_012685ac;
void __cdecl FUN_00c876a0();
struct FUN_00c8a720 {
  void* vtable;
  virtual ~FUN_00c8a720();
};
struct FUN_00cc2ac0 : FUN_00c8a720 {
  virtual ~FUN_00cc2ac0();
};
// Destructor that calls FUN_00c876a0 and decrements the global DAT_012685ac.
// @fnv 0x00cc2ac0
FUN_00cc2ac0::~FUN_00cc2ac0() {
  FUN_00c876a0();
  --DAT_012685ac;
}

namespace fnv_00cc5c70 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

extern int DAT_010c5398;


struct PoolAlloc { void* __thiscall FUN_00aa3e40(unsigned int n); };
extern PoolAlloc DAT_011f6238;
struct B0 { void* vf; };
struct Inner { Inner* p; int rc; int a; int b; };

struct NewObj : B0, Inner
{
    static void* __cdecl operator new(unsigned int n) { return DAT_011f6238.FUN_00aa3e40(n); }
    NewObj()
    {
        Inner* in = static_cast<Inner*>(this);
        rc = 1;
        a = 0;
        b = 0;
        vf = (void*)&DAT_010c5398;
        in->p = 0;
    }
};

}  // namespace fnv_00cc5c70

namespace fnv_00cc81c0 {
extern __declspec(thread) int g_tlsAllocType;

struct hkTransformStub { float m00, m04, m08, m0C, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };
extern hkTransformStub DAT_01268370;

struct RefBase {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    RefBase() : unk04(0), unk08(1), unk0C(0), unk10(0) {}
    virtual ~RefBase() { Release(0); }
    void Release(int);
};

struct AllocTypeGuard {
    int m_saved;
    AllocTypeGuard(int type) { m_saved = g_tlsAllocType; g_tlsAllocType = type; }
    ~AllocTypeGuard() { g_tlsAllocType = m_saved; }
};

struct CinfoA : RefBase {
    int unk14;
    int unk18;
    CinfoA() {}
    ~CinfoA() {}
    void SetTransform(const hkTransformStub& t);
};

struct CinfoB : RefBase {
    CinfoB() {}
    void InitB();
    void SetB(int v);
    void SetScale(float f);
};

struct ResultBase {
    int unk00; int unk04; int unk08; int unk0C;
    static void* __cdecl operator new(unsigned int size);
};

}  // namespace fnv_00cc81c0

static const __m128 signMask = {-0.0f,-0.0f,-0.0f,-0.0f};

__forceinline __m128 readQuad(const __m128* __restrict p){return *p;}
__forceinline const __m128& readQuadRef(const __m128* __restrict p){return *p;}
__forceinline __m128 readFloats(const float* __restrict p){return _mm_load_ps(p);}
__forceinline const __m128& readFloatsRef(const float* __restrict p){return *reinterpret_cast<const __m128*>(p);}

struct Bool {
    char value;
    Bool(bool v) : value(v) {}
    operator bool() const {return value!=0;}
};
struct Shape {
    int unk00, unk04, unk08, type;
    __m128 unk10, vertexA, vertexB, vertexC;
    Bool isTriangle() const {Bool result=type==3; _ReadWriteBarrier(); return result;}
};
struct Body {
    Shape* shape;
    int key;
    void* transform;
    Body* parent;
    signed char bodyOffset;
    char unk11,unk12,unk13;
    int unk14,unk18,unk1c,unk20,unk24;
    char kind,unk29,unk2a,unk2b;
    unsigned flags;
    void FUN_00c90510();
    Bool isSpecial() const {Bool result=kind==1; _ReadWriteBarrier(); return result;}
    Bool isFlagged() const {Bool result=(flags&0x7f)==30; _ReadWriteBarrier(); return result;}
};
struct ShapeKeys { unsigned keys[8]; };
struct Collision {
    __m128 position,direction;
    Body* a; int state;
    ShapeKeys shapeKeysA;
    Body* b; int key;
    ShapeKeys shapeKeysB;
    Collision() {}
    __forceinline Collision(const Collision& c) {_mm_store_ps(position.m128_f32,c.position); _mm_store_ps(direction.m128_f32,c.direction); a=c.a; state=c.state; shapeKeysA=c.shapeKeysA; b=c.b; key=c.key; shapeKeysB=c.shapeKeysB; }
};

template<class T> struct PointArray {
    T* data; int count; unsigned capacity;
    void reserve() {
        S_00cc4b90_Router* ctx=FUN_00c85750();
        if(count==int(capacity&0x3fffffff)) ResizeAudioStream(ctx->unk10,this,sizeof(T));
    }
    __forceinline void append(const T& value) {reserve(); new(data+count) T(value); ++count;}
    T& expand() {reserve(); return data[count++];}
    __forceinline void appendPointer(Body* value) {
        reserve(); T* item=data+count; _ReadWriteBarrier(); *item=value; ++count;
    }
    int find(Body* value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};

extern float DAT_01267e30;
extern float DAT_01267e34;
extern float DAT_01267e38;
extern float DAT_01267e3c;
extern const float DAT_01016248;

struct S00cd8920_Vec {
    float x;
    float y;
    float z;
    float w;
};

struct S00cd8920_Obj {
    const struct Skeleton* unk00;
    short unk04a;short unk04b;
    short unk08;
    unsigned short unk0A;
    unsigned int unk0C;
    S00cd8920_Vec unk10;
    S00cd8920_Vec unk20;
    S00cd8920_Vec unk30;
    S00cd8920_Vec unk40;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    float unk70;
    bool unk74;

    S00cd8920_Obj* FUN_00cd8920();
};

#include <xmmintrin.h>
namespace fnv_00cd9d10 {
struct __declspec(intrin_type) __declspec(align(16)) __m128 { float x,y,z,w; };
extern "C" {
extern __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern __m128 _mm_unpackhi_ps(__m128 _A, __m128 _B);
extern __m128 _mm_xor_ps(__m128 _A, __m128 _B);
}

extern __m128 DAT_010c44d0;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;

struct VectorLocal {
 __m128 value;
 __forceinline VectorLocal() {}
 __forceinline VectorLocal(__m128 v):value(v){}
 __forceinline operator __m128() const { return value; }
 __forceinline VectorLocal& operator=(__m128 v) {value=v;return *this;}
};

}  // namespace fnv_00cd9d10

#include <windows.h>
#include <intrin.h>



struct TimerEvent {
    const char* name;
    unsigned int ticks;
    unsigned int auxiliary;
};
struct TimerBuffer {
    TimerEvent* begin;
    TimerEvent* current;
    TimerEvent* storage;
    TimerEvent* end;
    void emit(const char* name) {
        TimerEvent* event = current;
        if (event < end) {
            event->name = name;
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            event->ticks = ticks;
            current = event + 1;
        }
    }
};
struct ConstraintRecord {
    unsigned short type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    unsigned short size;
    unsigned short unk12;
    unsigned int unk14, unk18, unk1c;
    ConstraintRecord() : type(27), size(32) {}
    static void* operator new(unsigned int n) {
        return FUN_00c85750()->heap().AllocateMemoryBlock(n);
    }
};
void* __cdecl hkpWorldConstraintUtil_findModifier(void*, int);

void* __cdecl hkpWorldConstraintUtil_findModifier(void* p, int type);

#include <xmmintrin.h>
namespace CE6Memory {
S_00cc4b90_Router* FUN_00c85750();
void __cdecl FUN_00c908c0(void*, void*, int, int);
}

struct CE6Heap {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void Free(void* p,int n);
};
struct CE6Vec { __m128 v; };
struct CE6Array {
 CE6Vec* data; int size; int capacity;
 CE6Array():data(0),size(0),capacity(0x80000000) {}
 ~CE6Array() { clear(CE6Memory::FUN_00c85750()->heap()); }
 void clear(S_00cc4b90_Alloc& alloc) { size=0; if(!(capacity&0x80000000)) reinterpret_cast<CE6Heap&>(alloc).Free(data,(capacity&0x3fffffff)*sizeof(CE6Vec)); data=0;capacity=0x80000000; }
 void reserve(S_00cc4b90_Alloc& heap,int n) { int cap=capacity&0x3fffffff; if(cap<n) { int doubled=cap*2; CE6Memory::FUN_00c908c0(&heap,this,n<doubled?doubled:n,sizeof(CE6Vec)); } }
 void resize(int n) { reserve(CE6Memory::FUN_00c85750()->heap(),n); size=n; }
};
struct CE6View { CE6Vec* data; int count; int stride; CE6View(const CE6Array& a) { count=a.size; stride=sizeof(CE6Vec); data=a.data; } };

struct TlsGuard_t_SV
{
    int m_saved;
    TlsGuard_t_SV()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t_SV()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();


// @f3twin 0x0095a000 of 0x0073b180
struct F3Twin_0095a000 : public FUN_00cdea80_cls { int hkpRagdollConstraintData_getConeMotor() ; };
// pdb: hkpRagdollConstraintData::getConeMotor | hkpRagdollConstraintData.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int F3Twin_0095a000::hkpRagdollConstraintData_getConeMotor() 
{
    return m_e8;
}

// @f3twin 0x00a28310 of 0x008d3560
// pdb: hkpDefaultToiResourceMgr::shouldHandleGivenToi | hkpDefaultToiResourceMgr.obj | tesv_win, objrun, medium
void __stdcall F3_FUN_00a28310(unsigned char* flag, int unused) {
    *flag = 1;
}

// @f3twin 0x00a829e0 of 0x00943650
struct F3Twin_00a829e0 : public hkObjCC01 { void* F3_FUN_00a829e0(void* pv) ; };
void* F3Twin_00a829e0::F3_FUN_00a829e0(void* pv) 
{
    m_target->handle(pv);
    return pv;
}
