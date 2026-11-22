// staging/blk_00e40000_o2.cpp: KnotVector, ThunkDerived, FourComponentVector, Quat4 and more (49 functions)
#include "f3_common.h"
#include "fnv_asm_helpers.h"
// src/staging/blk_00e40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void __cdecl FUN_00cb0a60();

struct FUN_00e4e400_class {
    FUN_00e4e400_class* __thiscall FUN_00e4e400();
};

// @f3 0x00424f00 (community match, verified in this file)
struct A8AE50Stream
{
    virtual void unk00();
    A8AE50Stream();
};
class BSStream : public A8AE50Stream
{
public:
    virtual void unk00();
};
// pdb: BSStream::BSStream | ModelLoader.obj | fnv360_0822_retail, call_gap, low
FUN_00e4e400_class* FUN_00e4e400_class::FUN_00e4e400()
{
    reinterpret_cast<BSStream*>(this)->BSStream::BSStream();
    int zero = 0;
    *(volatile int*)((char*)this + 0x5c8) = zero;
    *(volatile int*)((char*)this + 0x5c4) = zero;
    return this;
}


struct FUN_00e58780_Class {
    int* GetElementPtr(int a, int b);
};

// @fnv 0x00e58780
int* FUN_00e58780_Class::GetElementPtr(int a, int b)
{
    return *(int**)(this + 0) + a * *(int*)((char*)this + 0x10) + b;
}

struct GlobalObjectO2_00d472a0 { int x; };
GlobalObjectO2_00d472a0 g_0126e600;
void __stdcall FUN_00e5c540(int, GlobalObjectO2_00d472a0*);
// @fnv 0x00e5c5b0
void __stdcall FUN_00e5c5b0(int a)
{
    FUN_00e5c540(a, &g_0126e600);
}

extern "C" void __stdcall FUN_00e5c540(int, int);

struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c5f0;

// Calls FUN_00e5c540 with the argument a and the address of g_0126c5f0.
// @fnv 0x00e5c5f0
void __stdcall FUN_00e5c5f0(int aiValue)
{
    FUN_00e5c540(aiValue, (int)&g_0126c5f0);
}

namespace fnv_00e5c610 {
struct GlobalObjectO2_00d472a0;
extern "C" void __stdcall FUN_00e5c540(int, GlobalObjectO2_00d472a0*);
}  // namespace fnv_00e5c610

namespace fnv_00e5c650 {
struct GlobalObjectO2_00d472a0 {};
void __stdcall FUN_00e5c540(int, GlobalObjectO2_00d472a0*);
}  // namespace fnv_00e5c650

namespace fnv_00e5c670 {
struct GlobalObjectO2_00d472a0;
extern "C" void* __stdcall FUN_00e5c540(void*, void*);

}  // namespace fnv_00e5c670

struct FUN_00e459c0_class {
    void SetBitMaskFlags(int a, int b);
};

// If both masks are zero sets byte 0x30 to 1; otherwise ORs each set bit's mask into the corresponding int at offset 0x34.
// @fnv 0x00e459c0
// pdb: hkpGroupCollisionFilter::enableCollisionGroups | hkpGroupCollisionFilter.obj | fnv360_0822_retail, objrun_open, low
// pdb params: groupBitsA, groupBitsB
void FUN_00e459c0_class::SetBitMaskFlags(int a, int b)
{
    if (!a && !b)
    {
        ((char*)this)[0x30] = 1;
        return;
    }
    for (int i = 0; i < 32; i++)
    {
        if (a & (1 << i))
            ((int*)((char*)this + 0x34))[i] |= b;
        if (b & (1 << i))
            ((int*)((char*)this + 0x34))[i] |= a;
    }
}

struct FUN_00e45a10_class {
    void __thiscall ClearFlags(int a, int b);
};
// If both masks are zero, clears the byte at offset 0x30; otherwise for each of 32 bits, clears the other mask's bits in the corresponding dword at 0x34 + i*4.
// @fnv 0x00e45a10
// pdb: hkpGroupCollisionFilter::disableCollisionGroups | hkpGroupCollisionFilter.obj | fnv360_0822_retail, objrun_open, low
// pdb params: groupBitsA, groupBitsB
void __thiscall FUN_00e45a10_class::ClearFlags(int a, int b)
{
    if (!a && !b)
    {
        *(unsigned char*)((char*)this + 0x30) = 0;
        return;
    }
    for (int i = 0; i < 32; ++i)
    {
        if (a & (1 << i))
            *(unsigned int*)((char*)this + 0x34 + i * 4) &= ~b;
        if (b & (1 << i))
            *(unsigned int*)((char*)this + 0x34 + i * 4) &= ~a;
    }
}

struct FUN_00e587b0_Class {
    int* __thiscall FUN_00e587b0(int idx);
};

namespace fnv_00e589e0 {
struct FUN_00e587b0_Class {
    float* FUN_00e587b0(int);
    int FUN_00e58890();
};
}  // namespace fnv_00e589e0

extern int DAT_010ec1fc;

extern const char* const g_0126c5f0_arg1;
void __stdcall FUN_00e5c540(int, int);
// @fnv 0x00e5c5d0
void __stdcall FUN_00e5c5d0(int aiValue)
{
    FUN_00e5c540(aiValue, (int)&g_0126c5f0_arg1);
}

struct GlobalObjectO2_00d472a0;
void __stdcall FUN_00e5c540(int a, GlobalObjectO2_00d472a0* b);

struct GlobalObjectO2_00d472a0;
void __stdcall FUN_00e5c540(int, GlobalObjectO2_00d472a0*);

struct HolderStub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

HolderStub* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize);

struct ValueArray {
    unsigned int* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

class BE41DF0ReferencedObject {
public:
    BE41DF0ReferencedObject() throw() : m_sReferenceCount(1) {}
    virtual ~BE41DF0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

template <class T>
struct BE41DF0Array {
    BE41DF0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct FUN_00e43f30_cls {
    void* volatile m_00;
    unsigned short m_04;
    volatile unsigned short m_06;
    volatile float m_08;
    volatile float m_0c;
    volatile float m_10;
    volatile float m_14;
    volatile float m_18;
    volatile int m_1c;
    volatile int m_20;
    volatile unsigned int m_24;
    volatile int m_28;
    volatile int m_2c;
    volatile unsigned int m_30;
    FUN_00e43f30_cls();
};

// @f3 0x004f4180 (community match, verified in this file)
FUN_00e43f30_cls::FUN_00e43f30_cls() {
    *(unsigned int*)&m_14 = 0x80000000u;
    *(unsigned int*)&m_0c = 0;
    *(unsigned int*)&m_10 = 0;
    *(unsigned int*)&m_00 = 0;
    *(unsigned int*)&m_04 = 0;
    *(volatile unsigned char*)&m_08 = 2;
    *(volatile float*)&m_2c = 0.0f;
    *(volatile float*)&m_28 = 0.0f;
    *(volatile float*)&m_24 = 0.0f;
    *(volatile float*)&m_20 = 0.0f;
    *(volatile float*)((char*)this + 0x3c) = 0.0f;
    *(volatile float*)((char*)this + 0x38) = 0.0f;
    *(volatile float*)((char*)this + 0x34) = 0.0f;
    *(volatile float*)&m_30 = 0.0f;
}


class BE468B0Base {
public:
    virtual ~BE468B0Base();

    int m_iRefCount;
};

class BE468B0InterfaceA {
public:
    virtual void OnA();
};

class BE468B0InterfaceB {
public:
    virtual void OnB();
};

class BE468B0InterfaceC {
public:
    virtual void OnC();
};

class BE468B0InterfaceD {
public:
    virtual void OnD();
};

class BE468B0Shape : public BE468B0Base, public BE468B0InterfaceA, public BE468B0InterfaceB,
    public BE468B0InterfaceC, public BE468B0InterfaceD {
public:
    BE468B0Shape();
    virtual ~BE468B0Shape();

    int m_iFirst;
    int m_iSecond;
    int m_iEnabled;
    int unk24;
    int unk28;
    int unk2C;
};

class BE468B0Listener {
public:
    virtual void OnEvent();
};

template <class T>
class BE468B0Array {
public:
    BE468B0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkpPairwiseCollisionFilter : public BE468B0Shape, public BE468B0Listener { // src: F3_EXE vtable 0x00e81cec (old: FUN_00e468b0_cls)
public:
    hkpPairwiseCollisionFilter();
    virtual ~hkpPairwiseCollisionFilter();
    virtual void OnA();
    virtual void OnB();
    virtual void OnC();
    virtual void OnD();
    virtual void OnEvent();

    BE468B0Array<int> m_kEntries;
};

// @fnv 0x00e468b0
hkpPairwiseCollisionFilter::hkpPairwiseCollisionFilter()
{
}

struct S_e49fe0_Arr {
    int m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_e49fe0_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000) {}
};

struct E4AAA0Allocator;

void __cdecl FUN_00c908c0(E4AAA0Allocator* alloc, void* array, int numElements, int sizeElem);

struct E4AAA0Element {
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};

struct E4AAA0Array {
    E4AAA0Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void reserve(E4AAA0Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(E4AAA0Element));
        }
    }

    void InsertElements(E4AAA0Allocator& alloc, int index, int numdel, const E4AAA0Element* p, int numtoinsert);
};

class E4AE50ReferencedObject {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    E4AE50ReferencedObject() { m_sReferenceCount = 1; }
    virtual ~E4AE50ReferencedObject() {}
};

template <class T>
class E4AE50Array {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E4AE50Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};

// FUN_00e4ae80 (11 bytes)
//
//   00e4ae80  8b c1                    mov eax, ecx
//   00e4ae82  c7 00 ec c1 0e 01        mov dword ptr [eax], 0x010ec1ec
//   00e4ae88  c2 04 00                 ret 4
//
// This is a CONSTRUCTOR of the class whose vftable lives at 0x010ec1ec
// (hkxMaterialShaderSet - see tools/pe.py rtti 0x010ec1ec).  A constructor
// returns `this` in EAX, so `this` is live-out in EAX and MSVC emits the vptr
// store through EAX (a hand written `this->m_vtbl = ...` would instead give
// `mov eax,OFFSET sym / mov [ecx],eax`).  The single 4-byte stack argument is
// unused, which is why the epilogue is `ret 4`.
//
// The class is stand-in only: it needs one virtual so that the compiler emits
// a vftable, and the vftable slot points at the (undefined) virtual, so the
// only defined function symbol in this translation unit is the constructor.

// add ecx,0x14; jmp FUN_00cb0c10 : the derived override forwards to the secondary base's
// virtual, so `this` is moved forward by the size of the primary base (vptr + 4 ints = 0x14)
// before the tail jump to the secondary base's implementation.
struct ThunkPrimary
{
    virtual void HavokError_enableAll();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct ThunkSecondary
{
    virtual void FUN_00cb0c10();
};

struct ThunkDerived : ThunkPrimary, ThunkSecondary
{
    ThunkDerived();
    virtual void HavokError_enableAll();
};

ThunkDerived::ThunkDerived()
{
}

// @fnv 0x00e4af50
// pdb: HavokError::enableAll | HavokStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void ThunkDerived::HavokError_enableAll()
{
    this->ThunkSecondary::FUN_00cb0c10();
}

struct S_00e4af60_helper {
    void FUN_00cb0a60();
};

struct S_00e4af60_class {
    void* unk00;
    short unk04;
    short unk06;
    void* unk08;
    int unk0c;
    int unk10;
    S_00e4af60_helper unk14;

    S_00e4af60_class* FUN_00e4af60();
};

extern int DAT_010ec1fc;

// @f3 0x00a0a240 (community match, verified in this file)
struct S_00e4af60_inner {
    void FUN_00922cb0();
};
// pdb: hkSerializeMultiMap<class hkDataClassDict *,class hkDataClassDict *,class hkPointerMap<class hkDataClassDict *,int,struct hkContainerHeapAllocator> >::clear | hkDataObjectDict.obj | tesv_win, caller_sim, low
S_00e4af60_class* S_00e4af60_class::FUN_00e4af60()
{
    this->unk06 = 1;
    this->unk00 = &DAT_010ec1fc;
    ((S_00e4af60_inner*)&this->unk08)->FUN_00922cb0();
    return this;
}


namespace fnv_00e50ca0 {
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

}  // namespace fnv_00e50ca0

extern const float g_x;

// @fnv 0x00e52f40
// pdb: MagicSystem::GetChameleonMaxRefraction | MagicSystem.obj | fnv360_0822_retail, call_seq, medium
float __cdecl FUN_00e52f40()
{
    return g_x;
}

extern const float g_010ec960;

// @fnv 0x00e52f50
// pdb: AiFormulas::AVDeriveBodyPartCondition | AiFormulas.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apActor, aiWhich
float __cdecl FUN_00e52f50()
{
    return g_010ec960;
}

extern const float g_010af2f0;

// @fnv 0x00e52f60
// pdb: CombatFormulas::GetPowerAttackDamageMultiplier | CombatFormulas.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aiWeaponSkill, aePowerAttackGroup
float __cdecl FUN_00e52f60()
{
    return g_010af2f0;
}

extern const float g_010ec964;

// @fnv 0x00e52f70
// pdb: ActionPoints::GetActionPointsRestoreRate | ActionPoints.obj | fnv360_0822_retail, objrun_open, low
float __cdecl FUN_00e52f70()
{
    return g_010ec964;
}

extern const float DAT_010ec968;

// @fnv 0x00e52f80
// pdb: Interface::GetRenderedMenuScreenWidth | Interface.obj | fnv360_0822_retail, call_gap_sim, low
float __cdecl FUN_00e52f80()
{
    return DAT_010ec968;
}

extern float DAT_0104da4c;

// @fnv 0x00e52f90
// pdb: StatsMenu::GetRadMeterMax | StatsMenu.obj | fnv360_0822_retail, call_gap_sim, low
float __cdecl FUN_00e52f90(void)
{
    return DAT_0104da4c;
}

extern "C" void _ReadWriteBarrier(void);

class FUN_00e53160 {
public:
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;

    FUN_00e53160(float fX, float fY, float fZ, float fW);
};

struct FUN_00e53180_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53180_cls(const float* pSrc);
};

// @f3 0x005686c0 (community match, verified in this file)
// pdb: hkpCdPointCollector::`scalar deleting destructor' | CameraCaster.obj | fnv360_1110_retail, objrun, medium
FUN_00e53180_cls::FUN_00e53180_cls(const float* pSrc)
{
    m_00 = pSrc[0];
    m_04 = pSrc[1];
    m_08 = pSrc[2];
    m_0c = pSrc[3];
    (&m_00)[4] = pSrc[4];
    (&m_00)[5] = pSrc[5];
    (&m_00)[6] = pSrc[6];
    (&m_00)[7] = pSrc[7];
}


struct FUN_00e531a0_struct {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;

    FUN_00e531a0_struct* FUN_00e531a0(const FUN_00e531a0_struct* other);
};

// Adds the four float components of other into this object's components and returns this.
// @f3 0x00432b70 (community match, verified in this file)
FUN_00e531a0_struct* FUN_00e531a0_struct::FUN_00e531a0(const FUN_00e531a0_struct* other) {
    m_00 = other->m_00 + m_00;
    m_04 = other->m_04 + m_04;
    m_08 = other->m_08 + m_08;
    return this;
}


// FUN_00e531d0: thiscall member of a 4-float vector; subtracts a vector
// (given by pointer/reference) from itself, in place, and returns itself.
struct FUN_00e531d0_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e531d0_cls* FUN_00e531d0(const float* pOther);
};

// Subtracts the four floats pointed to by pOther from m_00..m_0c and returns this.
// @f3 0x00432ba0 (community match, verified in this file)
FUN_00e531d0_cls* FUN_00e531d0_cls::FUN_00e531d0(const float* other) {
    m_00 -= other[0];
    m_04 -= other[1];
    m_08 -= other[2];
    return this;
}


struct FUN_00e53200_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53200_cls(float s);
};

// Multiplies the four float members m_00, m_04, m_08 and m_0c by s.
// @f3 0x006b1f50 (community match, verified in this file)
// pdb: NiPoint3::operator*= | MultiBoundMarkerData.obj | fnv360_0822_debug, call_gap, low, conflict (skyrim: TESHavokUtilities::AddVelocity)
// pdb params: fScalar
FUN_00e53200_cls::FUN_00e53200_cls(float afScale)
{
    m_00 = m_00 * afScale;
    m_04 = m_04 * afScale;
    m_08 = m_08 * afScale;
}


struct FourFloatVector {
    float x;
    float y;
    float z;
    float w;

    FourFloatVector& FUN_00e531a0(int parameter);
    FourFloatVector FUN_00e53260(int parameter);
};

struct S_e53300_Vec;
struct S_e53300_Vec {
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    S_e53300_Vec& FUN_00e53200(float f);
    S_e53300_Vec ScaleCopy(float f);
};

struct SpawnedObject {
    void Method(float* pOut, float f);
};

// @fnv 0x00e533a0
float* __cdecl FUN_00e533a0(float* pOut, float fValue, SpawnedObject* pObj)
{
    pObj->Method(pOut, fValue);
    return pOut;
}

// Returns a FourComponentVector whose components are each passed through FUN_00ec6940.
// @f3 0x007e02b0 (community match, verified in this file)
namespace f3m_007e02b0 {
struct NP3_7e02b0 { float x, y, z; };
struct V2_7e02b0 { float a, b; };

struct Big7e02b0
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual float* vf1f4();
};

float __cdecl FUN_00477b20(const float*);

struct C7e02b0
{
    char pad[0x28];
    Big7e02b0* unk28;

    bool FUN_007df5a0(float ang, int d) const;
    bool FUN_007e02b0(NP3_7e02b0 pt, int d) const;
};

// pdb: ActorMover::RequestRotateActor | ActorMover.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aTargetPoint, abForceTurn
bool C7e02b0::FUN_007e02b0(NP3_7e02b0 pt, int d) const
{
    const float* v = unk28->vf1f4();
    V2_7e02b0 t;
    t.a = pt.y - v[1];
    t.b = pt.z - v[2];
    NP3_7e02b0 arr;
    arr.x = pt.x - v[0];
    arr.y = t.a;
    arr.z = t.b;
    float ang = FUN_00477b20(&arr.x);
    return FUN_007df5a0(ang, d);
}
}   // namespace f3m_007e02b0


struct Vec4f {
    float x;
    float y;
    float z;
    float w;
    Vec4f(float a, float b, float c, float d);
    float operator[](int i) const;
    float& operator[](int i);
};

__declspec(noinline) Vec4f::Vec4f(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__declspec(noinline) float Vec4f::operator[](int i) const
{
    return (&x)[i];
}

__declspec(noinline) float& Vec4f::operator[](int i)
{
    return (&x)[i];
}

char* __cdecl IsSampleBoundary(int* base, int idx, int b, int c);

namespace fnv_00e55080 {
struct FourFloatVector {
    float x;
    float y;
    float z;
    float w;
};
void __cdecl FUN_00e54630(FourFloatVector* result, int a, int b, int c, int d, float value);
float __cdecl LookupAndConsume(const FourFloatVector* a, const FourFloatVector* b);

}  // namespace fnv_00e55080

struct Float4 { float x, y, z, w; };
void __cdecl FUN_00e54630(Float4* out, int a, int b, int c, int d, float input);
float __cdecl LookupAndConsume(const Float4* left, const Float4* right);

struct SpawnArray
{
    void* unk00;
    int unk04;
    unsigned int unk08;
    void Reset()
    {
        unk00 = 0;
        unk04 = 0;
        unk08 = 0x80000000;
    }
};

namespace fnv_00e58b90 {
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

}  // namespace fnv_00e58b90

namespace fnv_00e58c30 {
extern "C" void _ReadWriteBarrier(void);

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize) throw();

struct ValueArray {
    int* data;
    int count;
    unsigned int capFlags;
};

}  // namespace fnv_00e58c30

namespace fnv_00e58cf0 {
struct AllocatorIface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* Alloc(int* pSize);
    virtual void Free(void* pBuffer, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocatorIface* m_pAllocator;
};

AllocHolder* FUN_00c85750();
void FUN_00c908c0(AllocatorIface* alloc, void* arr, unsigned int newCap, int elemSize);

}  // namespace fnv_00e58cf0

namespace fnv_00e58df0 {

struct FUN_00e58df0_cls;
void* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(void* allocator, FUN_00e58df0_cls* arr, int newCap, int elemSize);

struct FUN_00e58df0_cls {
    float* m_00;
    int m_04;
    unsigned int m_08;
    int m_0C;
    int m_10;
    int FUN_00e58890();
    FUN_00e58df0_cls* CopyFrom(FUN_00e58df0_cls* src);
};

}  // namespace fnv_00e58df0

int hkString_strCasecmp(unsigned int item, unsigned int ctx);

struct ConfigValue { unsigned type, identifier; const void* data; };
struct CharBuffer {
    char* destination;
    unsigned capacity, length;
    void FUN_00cb1600(char*, unsigned);
    CharBuffer* FUN_00cc01c0(const char*);
    CharBuffer* WriteName(const void*);
    void FUN_00cc00e0();
};
struct DiagnosticLogger {
    virtual void open(); virtual void close(); virtual void flush();
    virtual void report(int, unsigned, const char*, const char*, int);
};
extern DiagnosticLogger* DAT_01268360;
extern const char str_010ecd20[],str_010eccfc[],str_010ecd0c[],str_010eccc8[];
struct ConfigTable {
    ConfigValue* FUN_00e5c5d0(const char*);
    ConfigValue* FUN_00e5c5b0(const char*);
    ConfigValue* FUN_00e5c5f0(const char*);
    int GetUnsignedValue(const char*, bool, unsigned*);
};
// @fnv 0x00e5c7a0
int ConfigTable::GetUnsignedValue(const char* name, bool reportMissing, unsigned* puiValue) {
    ConfigValue* entry = FUN_00e5c5d0(name);
    if (entry) {
        *puiValue = *static_cast<const unsigned*>(entry->data);
        return 0;
    }
    entry = FUN_00e5c5b0(name);
    if (entry) {
        *puiValue = *static_cast<const unsigned char*>(entry->data) != 0;
        return 0;
    }
    entry = FUN_00e5c5f0(name);
    if (entry) {
        *puiValue = *static_cast<const unsigned*>(entry->data);
        return 0;
    }
    if (reportMissing) {
        CharBuffer buffer;
        unsigned text[128];
        buffer.FUN_00cb1600(reinterpret_cast<char*>(text), 512);
        buffer.FUN_00cc01c0(str_010ecd20)->FUN_00cc01c0(name)->FUN_00cc01c0(str_010eccfc)->WriteName(this)->FUN_00cc01c0(str_010ecd0c);
        DAT_01268360->report(1, 0xabbaab81u, reinterpret_cast<char*>(text), str_010eccc8, 90);
        buffer.FUN_00cc00e0();
    }
    return 1;
}

// FUN_00e5cec0 - forwards this + four stack arguments to SpliceArray,
// with a literal zero inserted as the third argument.

struct S_00e5cfb0_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

struct S_00e65ee0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void __thiscall FUN_00e65ee0(int* buffer, int value);
};

// Stores value in a local struct and calls FUN_00e65ee0 with a zeroed buffer and object->unk20.
// @fnv 0x00e5cfb0
// pdb: hkMoppFindAllVirtualMachine_getAllKeys | hkpMoppMachine.obj | fnv360_0822_retail, objrun, medium
// pdb params: code, primitives_out
void __cdecl FUN_00e5cfb0(S_00e5cfb0_Object* object, int value)
{
    S_00e65ee0_Class local;
    int buffer[2];

    local.unk00 = value;
    buffer[0] = 0;
    buffer[1] = 0;

    local.FUN_00e65ee0(buffer, object->unk20);
}

namespace fnv_00e42960 {
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
}  // namespace fnv_00e42960

class PrimaryE45 {
public:
    virtual ~PrimaryE45();

    int unk04;
};

class ListenerAE45 {
public:
    virtual void OnAdded();
};

class ListenerBE45 {
public:
    virtual void OnRemoved();
};

class ListenerCE45 {
public:
    virtual void OnActivated();
};

class ListenerDE45 {
public:
    virtual void OnDeactivated();
};

class BaseE45 : public PrimaryE45, public ListenerAE45, public ListenerBE45, public ListenerCE45, public ListenerDE45 {
public:
    BaseE45();
    virtual ~BaseE45();

    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

class EnabledFlagE45 {
public:
    __forceinline EnabledFlagE45() : m_bEnableState(true) {}

    bool m_bEnableState;
};

class SlotTableE45 {
public:
    __forceinline SlotTableE45()
        : m_pv00(0),
          m_pv04(0),
          m_pv08(0),
          m_pv0C(0),
          m_pv10(0),
          m_pv14(0),
          m_pv18(0),
          m_pv1C(0),
          m_pv20(0),
          m_pv24(0),
          m_pv28(0),
          m_pv2C(0),
          m_pv30(0),
          m_pv34(0),
          m_pv38(0),
          m_pv3C(0),
          m_pv40(0),
          m_pv44(0),
          m_pv48(0),
          m_pv4C(0),
          m_pv50(0),
          m_pv54(0),
          m_pv58(0),
          m_pv5C(0),
          m_pv60(0),
          m_pv64(0),
          m_pv68(0),
          m_pv6C(0),
          m_pv70(0),
          m_pv74(0),
          m_pv78(0),
          m_pv7C(0)
    {
    }

    void* m_pv00;
    void* m_pv04;
    void* m_pv08;
    void* m_pv0C;
    void* m_pv10;
    void* m_pv14;
    void* m_pv18;
    void* m_pv1C;
    void* m_pv20;
    void* m_pv24;
    void* m_pv28;
    void* m_pv2C;
    void* m_pv30;
    void* m_pv34;
    void* m_pv38;
    void* m_pv3C;
    void* m_pv40;
    void* m_pv44;
    void* m_pv48;
    void* m_pv4C;
    void* m_pv50;
    void* m_pv54;
    void* m_pv58;
    void* m_pv5C;
    void* m_pv60;
    void* m_pv64;
    void* m_pv68;
    void* m_pv6C;
    void* m_pv70;
    void* m_pv74;
    void* m_pv78;
    void* m_pv7C;
};

class FUN_00e45530_Manager : public BaseE45 {
public:
    FUN_00e45530_Manager();
    virtual ~FUN_00e45530_Manager();

    EnabledFlagE45 m_kEnabled;
    SlotTableE45 m_kSlots;
};

// Initializes the manager by constructing its base and default-constructing the enabled flag and slot table members.
// @fnv 0x00e45530
// pdb: hkpGroupCollisionFilter::hkpGroupCollisionFilter | hkpGroupCollisionFilter.obj | tesv_win, hash, low
FUN_00e45530_Manager::FUN_00e45530_Manager()
{
}

struct AllocationHeap {
    virtual void Unused0();
    virtual void* Allocate(unsigned int bytes);
    virtual void Unused8();
    virtual void UnusedC();
    virtual void Deallocate(void* pointer, unsigned int bytes);
};

struct CListener {
    virtual ~CListener() throw() {}
};

template <typename T>
struct HkSmallArray {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    HkSmallArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000) {}

    int indexOf(const T& element) const {
        for (int i = 0; i < (int)m_iElementCount; ++i) {
            if (m_data[i] == element) {
                return i;
            }
        }
        return -1;
    }
};

struct ExtendedListeners {
    HkSmallArray<void*> first;
    HkSmallArray<CListener*> second;

    static void* operator new(size_t sz) {
        HolderStub* mgr = FUN_00c85750();
        return ((AllocationHeap*)mgr->m_pAllocator)->Allocate(sz);
    }
};

struct ActorEntry {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210;
    ExtendedListeners* m_pExtendedListeners;

    ExtendedListeners* getExtendedListeners() {
        if (!m_pExtendedListeners) {
            m_pExtendedListeners = new ExtendedListeners;
        }
        return m_pExtendedListeners;
    }

    void __thiscall FUN_00c9c670(CListener* el);
};

template <typename T>
struct HkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() {
        HolderStub* mgr = FUN_00c85750();
        AllocationHeap* heap = (AllocationHeap*)mgr->m_pAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            heap->Deallocate(m_data, (cap & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct CBase0 {
    virtual ~CBase0() throw() {}
    int m_ref;
};
struct CBase8 {
    virtual ~CBase8() throw() {}
};
struct CBaseC {
    virtual ~CBaseC() throw() {}
};
struct CBase10 {
    virtual ~CBase10() throw() {}
};
struct CBase14 {
    virtual ~CBase14() throw() {}
};
struct CShape : CBase0, CBase8, CBaseC, CBase10, CBase14 {
    virtual ~CShape() throw() {}
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct Ref { void FUN_00c90510(); };
int FUN_00e60cb0(unsigned char,int);
struct Entry { Ref* name; Ref* pClassInfo; unsigned char type; unsigned char flags; unsigned short reserved; int count; unsigned char storage; unsigned char ReplaceImpactData; unsigned short reserved12; void* data; int unk18; int unk1c; int length() const { int t=type; return FUN_00e60cb0(t,count); } };
struct Allocator {};
struct Router { int a,b,c,d; Allocator* heap; Allocator& getHeap() {return *heap;} };
int FUN_00e60cb0(unsigned char type,int count);
extern "C" void FUN_00c908c0(Allocator*,void*,int,int);
struct String { void* value; void init() throw(); void assign(const char*) throw(); };
struct ArrayBase {
 void* data; int size; int capacity;
 ArrayBase():data(0),size(0),capacity(0x80000000){}
 int getCapacity() const {return capacity & 0x3fffffff;}
 static void grow(Allocator& heap,ArrayBase* a,int n,int stride) { int cap=a->getCapacity(); if(cap<n) FUN_00c908c0(&heap,a,n<2*cap?2*cap:n,stride); }
 void reserve(Allocator& heap,int n,int stride){grow(heap,this,n,stride);}
};
template<class T> struct Arr : ArrayBase {
 void reserve(Allocator& heap,int n){ArrayBase::reserve(heap,n,sizeof(T));}
 void SetSizeAndGrow(Allocator& heap,int n){reserve(heap,n);size=n;}
 T* expand(Allocator& heap,int n) {int old=size; reserve(heap,old+n); size+=n; return (T*)data+old;}
};
struct Base { virtual void dummy(); unsigned short flags; short refs; Base(){refs=1;} };

struct ArrayAllocator;
struct FloatArray;
void FUN_00c908c0(ArrayAllocator* alloc, FloatArray* arr, int newCap, int elemSize);
struct FloatArray {
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void reserve(ArrayAllocator& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n) {
            int c = 2 * cap;
            FUN_00c908c0(&alloc, this, n < c ? c : n, 4);
        }
    }
};
struct MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ArrayAllocator* m_pStreamAllocator;
    ArrayAllocator& heap() { return *m_pStreamAllocator; }
};

// Element-wise subtract another matrix of the same shape from this one.

class E87E0Matrix {
public:
    float* m_pfData;
    int unk04;
    int unk08;
    int m_iRows;
    int m_iColumns;

    float& Element(int i) { return m_pfData[i]; }
    E87E0Matrix& FUN_00e587e0(const E87E0Matrix& kOther);
};

extern int DAT_010e7874;
extern int DAT_010e7868;
extern int DAT_010e7854;
extern int DAT_010e7848;
extern int DAT_010e783c;
extern int DAT_010e781c;
extern int DAT_010cb1e4;

extern int DAT_010e7874;
extern int DAT_010e7868;
extern int DAT_010e7854;
extern int DAT_010e7848;
extern int DAT_010e783c;
extern int DAT_010e781c;
extern int DAT_010cb1e4;

struct FUN_00e46e80 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e46e80();
};

// @fnv 0x00e46e80
// pdb: hkpExtendedMaterial::hkpExtendedMaterial | bhkExtendedMeshShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: auiFilter, auiMaterial
FUN_00e46e80::FUN_00e46e80()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_10 = 0;
}

struct E473C0Owner;

struct E473C0Owner {
    int unk00;
    unsigned short unk04;

    void __thiscall FUN_00e47020();
    E473C0Owner* __thiscall FUN_00e473c0(unsigned char flags);
};

struct FnvCpu_FUN_00e473f0_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    void FUN_00e473f0(unsigned char arg0);
};
// @fnv 0x00e473f0
// pdb: hkpLinearParametricCurve::isClosedLoop | hkpLinearParametricCurve.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpLinearParametricCurve::setClosedLoop)
void FnvCpu_FUN_00e473f0_CpuObject::FUN_00e473f0(unsigned char arg0)
{
    value = arg0;
}

extern int DAT_010cb76c;
extern int DAT_010cb780;
extern int DAT_010e83b4;

struct SourceData {
    void* m_ppVirtualMethodTable;
    unsigned short m_unknown04,m_flags;
    unsigned char m_uiContentCount,m_unknown09,m_unknown0a,m_unknown0b;
    float m_pHeadNode,m_iSecondInteger;
    int m_third,m_fourth,m_fifth,m_sixth,m_seventh;
};
struct FUN_00e48400 {
    int* m_ppVirtualMethodTable;
    unsigned short m_unknown04,m_flags;
    unsigned char m_uiContentCount,m_unknown09,m_unknown0a,m_unknown0b;
    float m_pHeadNode,m_iSecondInteger;
    int m_third,m_fourth,m_fifth,m_sixth,m_seventh;
    FUN_00e48400(const SourceData* source);
};
// @fnv 0x00e48400
// pdb: hkpCallbackConstraintMotor::hkpCallbackConstraintMotor | hkpCallbackConstraintMotor.obj | tesv_win, caller, medium
FUN_00e48400::FUN_00e48400(const SourceData* source) {
    m_ppVirtualMethodTable = &DAT_010cb76c;
    m_flags = 1;

    unsigned char state = source->m_uiContentCount;
    *reinterpret_cast<int* volatile*>(&m_ppVirtualMethodTable) = &DAT_010cb780;
    m_uiContentCount = state;

    m_pHeadNode = source->m_pHeadNode;
    m_iSecondInteger = source->m_iSecondInteger;
    m_ppVirtualMethodTable = &DAT_010e83b4;

    m_third = source->m_third;
    m_fourth = source->m_fourth;
    m_fifth = source->m_fifth;
    m_sixth = source->m_sixth;
    m_seventh = source->m_seventh;
}

struct FUN_00e484a0_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char* m_base20;
};
struct FUN_00e484a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int* m_items0C;
    int m_count10;
    void ClearReferencedBytes(FUN_00e484a0_Arg* arg);
};
// For each of m_count10 items, reads the byte at arg->m_base20 + (item >> 8), stores it in the item's low byte, and zeroes that byte.
// @fnv 0x00e484a0
// pdb: hkpRemoveTerminalsMoppModifier::applyRemoveTerminals | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objrun_open, low
// pdb params: moppCode
void FUN_00e484a0_Class::ClearReferencedBytes(FUN_00e484a0_Arg* arg)
{
    for (int i = 0; i < m_count10; ++i)
    {
        unsigned int* entry = &m_items0C[i];
        unsigned char* target = arg->m_base20 + (*entry >> 8);
        unsigned char value = *target;
        *(unsigned char*)entry = 0;
        *entry |= value;
        *target = 0;
    }
}

struct FUN_00e484e0_dst {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char* m_20;
};
struct FUN_00e484e0_class {
    int unk00;
    int unk04;
    int unk08;
    unsigned int* m_0c;
    int m_10;
    void ScatterBytes(FUN_00e484e0_dst* dst);
};
// For each of m_10 entries in m_0c, writes the low byte of the entry into dst->m_20 at index entry >> 8.
// @fnv 0x00e484e0
// pdb: hkpRemoveTerminalsMoppModifier::undoRemoveTerminals | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objrun_open, low
// pdb params: moppCode
void FUN_00e484e0_class::ScatterBytes(FUN_00e484e0_dst* dst) {
    for (int i = 0; i < m_10; ++i) {
        unsigned int v = m_0c[i];
        unsigned char b = *(unsigned char*)&m_0c[i];
        dst->m_20[v >> 8] = b;
    }
}

extern "C" int DAT_010e8ab0;
extern "C" int DAT_010e8a90;
struct FUN_00e48db0_holder {
    void FUN_00dcd310(float f, void* p);
};
struct FUN_00e48db0_class {
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e48db0_class* __thiscall InitFromFloatAndPointer(float f, void* p);
};
// Calls FUN_00dcd310 with f and p, then stores pointers to DAT_010e8ab0 and DAT_010e8a90 in m_00 and m_10, returning this.
// @fnv 0x00e48db0
// pdb: hkpFastMeshShape::hkpFastMeshShape | hkpFastMeshShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: radius, numBitsForSubpartIndex
FUN_00e48db0_class* FUN_00e48db0_class::InitFromFloatAndPointer(float f, void* p)
{
    ((FUN_00e48db0_holder*)this)->FUN_00dcd310(f, p);
    m_00 = &DAT_010e8ab0;
    m_10 = (int)&DAT_010e8a90;
    return this;
}

int hkString_strCasecmp(const char* a, const char* b);

struct Node4a5
{
    char pad[0x14];
    unsigned int m_uiName;

    const char* GetName() const { return (const char*)(m_uiName & ~1); }

    Node4a5* FindChildByName(const char* pcName);
};

struct GtrStand_ {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* FUN_00e4af40();
};
// @fnv 0x00e4af40
// pdb: hkpConvexTransformShape::getContainer | hkpConvexTransformShape.obj | fnv360_0822_retail, objrun_open, low
void* GtrStand_::FUN_00e4af40()
{
    return &unk14;
}

struct HolderStub;
HolderStub* __cdecl FUN_00c85750();
// @fnv 0x00e4e3f0
// pdb: bhkSPCollisionObject::LoadBinary | bhkSPCollisionObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
HolderStub* __cdecl FUN_00e4e3f0()
{
    return FUN_00c85750();
}

namespace fnv_00e53130 {

}  // namespace fnv_00e53130

class hkBool
{
public:
    hkBool(bool b) { m_cBooleanValue = (char)b; }
    char m_cBooleanValue;
};

int GetUnsignedValue(const char*, bool, unsigned*);

// @fnv 0x00e5c8a0
// pdb: bhkSPCollisionObject::LinkObject | bhkSPCollisionObject.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
int FUN_00e5c8a0(const char* p, bool b, unsigned* u)
{
    return GetUnsignedValue(p, b, u);
}

struct UnkRet;

struct FUN_00e47390_obj {
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, unsigned int bytes);
};

struct UnkRet {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00e47390_obj* m_10;
};

class RefObjectE483 {
public:
    RefObjectE483() { m_sReferenceCount = 1; }
    virtual ~RefObjectE483();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

class TypedObjectE483 : public RefObjectE483 {
public:
    TypedObjectE483() { m_type = 0; }
    unsigned char m_type;
};

// @fnv 0x00e48460
// pdb: getMoppInstruction | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objrun_open, low
unsigned char __cdecl FUN_00e48460(unsigned char value)
{
    return value;
}

// @fnv 0x00e48470
// pdb: getMoppOffset | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objrun_open, low
__declspec(noinline) static unsigned int FUN_00e48470(unsigned int uiValue) {
    return uiValue >> 8;
}

unsigned int E48470Shift(unsigned int uiValue) {
    return FUN_00e48470(uiValue);
}

struct e48480_cls { unsigned char b; };
extern "C" e48480_cls* e48480_target(void);
extern "C" unsigned char e48480_val(void);
// @fnv 0x00e48480
// pdb: setMoppInstruction | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objopen_prop, low
static __declspec(noinline) void FUN_00e48480(e48480_cls* dst, unsigned char val)
{
    *(unsigned char*)dst = 0;
    *(unsigned int*)dst |= (unsigned int)val;
}
void e48480_caller(void) { FUN_00e48480(e48480_target(), e48480_val()); }

// FUN_00e48490: ORs the low byte at [this] with an incoming value shifted
// left by 8, stores the dword back, and returns the shifted value in eax.
// The value arrives in eax via VC9's private calling convention for a
// single-call-site static function, driven by a dummy caller that passes
// two extern-call returns.
union E48490Cell {
    unsigned char m_b0;
    int m_cell;
};

E48490Cell* E48490PtrSrc();
int E48490ValSrc();

// @fnv 0x00e48490
// pdb: setMoppOffset | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) int FUN_00e48490(E48490Cell* cell, int value)
{
    unsigned int shifted = value << 8;
    cell->m_cell = cell->m_b0 | shifted;
    return shifted;
}

void E48490Driver()
{
    FUN_00e48490(E48490PtrSrc(), E48490ValSrc());
}

// Source struct: only its float members at 0x80..0x94 take part; the rest are
// stand-in fields holding the earlier offsets.
struct Src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    float m_80;
    float m_84;
    unsigned int m_88;
    unsigned int m_8c;
    float m_90;
    float m_94;
};

// Destination object: receives the two scaled components at 0x1c / 0x20.
struct Dst
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    float m_1c;
    float m_20;
};

// in-TU caller so c2 keeps the body and negotiates the register convention.
static Dst* volatile g_dst;
static Src* volatile g_src;

#include <math.h>

#include <xmmintrin.h>
extern int DAT_010e6834;
struct MotorObject {
    int* vtable;
    unsigned short flags;
    unsigned short references;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
    int unk1c;
    __m128 vector20;
    __m128 vector30;
    float value40;
    float value44;
    void FUN_00d2b260(void*, int);
    MotorObject* FUN_00e444c0();
};
// Zeroes value40, value44, vector20 and vector30, sets vtable to DAT_010e6834, calls FUN_00d2b260(0, 0) and returns this.
// @f3 0x00a73270 (community match, verified in this file)
static __forceinline void SetZero4(__m128* v)
{
    float* f = reinterpret_cast<float*>(v);
    f[3] = 0.0f;
    f[2] = 0.0f;
    f[1] = 0.0f;
    f[0] = 0.0f;
}

// pdb: hkpReorientAction::hkpReorientAction | hkpReorientAction.obj | fnv360_0822_debug, caller_sim, high
// pdb params: body, rotationAxis, upAxis, strength, damping
MotorObject* MotorObject::FUN_00e444c0()
{
    FUN_00d2b260(0, 0);
    value40 = 0.0f;
    value44 = 0.0f;
    vtable = &DAT_010e6834;
    SetZero4(&vector20);
    SetZero4(&vector30);
    return this;
}


// Calls FUN_00e46f20, sets vtable to DAT_010ec004, sets type to 4 when flag.finishing is true, and returns this.
// @f3 0x00bce490 (community match, verified in this file)
namespace f3m_00bce490 {
namespace f3m_00bce490 {
struct Holder00bce490 {
    void* object;
    void FUN_00bce450() throw();
};
struct Base00bce490 {
    virtual ~Base00bce490()
    {
        if (unk08)
            unk08 = 0;
    }
    int unk04;
    void* unk08;
    int unk0c;
};
struct FUN_00bce490 : Base00bce490 {
    Holder00bce490 holder;
    virtual ~FUN_00bce490();
};
// pdb: BSXenonTaskletData::~BSXenonTaskletData | BSXenonTaskletData.obj | fnv360_0822_debug, caller, low, conflict (skyrim: BSWin32TaskletData::~BSWin32TaskletData)
FUN_00bce490::~FUN_00bce490()
{
    holder.FUN_00bce450();
    holder.object = 0;
}
}
}   // namespace f3m_00bce490


void* operator new(size_t, void* p) { return p; }

struct Actor : ActorEntry {
    void hkpEntity_addEntityListener(CListener* listener);
    __forceinline ExtendedListeners* listeners() {
        if (!m_pExtendedListeners) m_pExtendedListeners = new ExtendedListeners;
        return m_pExtendedListeners;
    }
};

template<class T> struct EntityArray : HkArray<T> {
    __forceinline int indexOf(const T& element) const {
        for (int i = 0; i < this->m_iElementCount; ++i) {
            if (this->m_data[i] == element) return i;
        }
        return -1;
    }
    __forceinline void AddBack(const T& element) {
        HolderStub* holder = FUN_00c85750();
        if (this->m_iElementCount == (this->m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(holder->m_pAllocator, this, sizeof(T));
        }
        T* destination = this->m_data + this->m_iElementCount;
        for (int k = 0; k < 1; ++k) destination[k] = element;
        ++this->m_iElementCount;
    }
};

struct SmallBool { unsigned char value; SmallBool(bool v) : value(v) {} };

struct BitLinks {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    unsigned int m_ppLinks[64];

    void SetLink(int a, int b);
};

// Sets the bit for b in m_ppLinks[a] and the bit for a in m_ppLinks[b], recording a symmetric link between the two indices.
// @fnv 0x00e48910
// pdb: hkpGroupFilter::enableCollisionsBetween | hkpGroupFilter.obj | fnv360_0822_retail, objrun, medium
// pdb params: layerA, layerB
void BitLinks::SetLink(int aiIndexA, int aiIndexB)
{
    m_ppLinks[aiIndexA] |= 1u << aiIndexB;
    m_ppLinks[aiIndexB] |= 1u << aiIndexA;
}

namespace se49080 {

void __fastcall FUN_00c90510(void* pvObject);

}

namespace se493a0 {

struct Stats {
    int m_iTotal;
    int m_iArrayLength;
    float m_fAverage;
    int m_iMaxControlPoint;
};

struct Layout {
    int unk000;
    int unk004;
    int* m_piSizes;
    int unk00c;
    int unk010;
    int* m_piIndices;
    int m_iNumIndices;
    int unk01c;
    int unk020;
    int m_iBase;
};

struct Owner {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Layout* m_pkLayout;

    void FUN_00e493a0(Stats* pkStats);
};

// Accumulates m_iBase and per-index sizes into pkStats, tracking the max control point size and computing the average.
// @fnv 0x00e493a0
// pdb: hkpConvexPieceMeshShape::getStats | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: statsOut
void Owner::FUN_00e493a0(Stats* pkStats)
{
    pkStats->m_iTotal += m_pkLayout->m_iBase;
    pkStats->m_iArrayLength += m_pkLayout->m_iBase;
    for (int i = 0; i < m_pkLayout->m_iNumIndices; i++)
    {
        int iSize = m_pkLayout->m_piSizes[m_pkLayout->m_piIndices[i]];
        pkStats->m_iTotal += iSize;
        pkStats->m_iMaxControlPoint = pkStats->m_iMaxControlPoint > iSize ? pkStats->m_iMaxControlPoint : iSize;
    }
    pkStats->m_iArrayLength += m_pkLayout->m_iNumIndices;
    pkStats->m_fAverage = (float)pkStats->m_iTotal / pkStats->m_iArrayLength;
}

}

class AllocatorIface
{
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* Alloc(int* pSize);
    virtual void Free(void* pBuffer, unsigned int size);
};


namespace fnv_00e4e420 {
struct IntegerHolder {
    int m_00;
    IntegerHolder() {}
    IntegerHolder(const IntegerHolder& other) { FUN_00cb0bd0(&other); }
    void FUN_00cb0bd0(const IntegerHolder*);
    void FUN_00cb0c00();
    void FUN_00cb0c30(const IntegerHolder*);
};
struct CopyEntry {
    float m_00;
    IntegerHolder m_04;
    CopyEntry(const CopyEntry& other) { m_00 = other.m_00; m_04.FUN_00cb0bd0(&other.m_04); }
    CopyEntry& operator=(const CopyEntry& other) { m_00 = other.m_00; m_04.FUN_00cb0c30(&other.m_04); return *this; }
    ~CopyEntry() { m_04.FUN_00cb0c00(); }
};
inline void* operator new(unsigned int, void* p) { return p; }
struct CopyAllocator { int m_00, m_04, m_08, m_0c; void* m_10; };
CopyAllocator* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(void*, void*, int, int);
static __forceinline void destroyEntries(CopyEntry* p, int count) {
    for (int i = 0; i < count; ++i) p[i].~CopyEntry();
}
static __forceinline void assignEntries(CopyEntry* dst, const CopyEntry* src, int count) {
    for (int i = 0; i < count; ++i) dst[i] = src[i];
}
static __forceinline void constructEntries(CopyEntry* dst, const CopyEntry* src, int count) {
    for (int i = 0; i < count; ++i) new(dst + i) CopyEntry(src[i]);
}
struct CopyArray {
    CopyEntry* m_00;
    int m_04;
    int m_08;
    __forceinline CopyArray(const CopyArray& src) : m_00(0), m_04(0), m_08(0x80000000) {
        CopyAllocator* manager = FUN_00c85750();
        int oldSize = m_04;
        int newSize = src.m_04;
        void* allocator = manager->m_10;
        int common = newSize > oldSize ? oldSize : newSize;
        int capacity = m_08 & 0x3fffffff;
        if (capacity < newSize) {
            int grown = capacity * 2;
            if (newSize >= grown) grown = newSize;
            FUN_00c908c0(allocator, this, grown, 8);
        }
        destroyEntries(m_00 + newSize, oldSize - newSize);
        assignEntries(m_00, src.m_00, common);
        constructEntries(m_00 + common, src.m_00 + common, newSize - common);
        m_04 = newSize;
    }
};
}  // namespace fnv_00e4e420

struct Count { int n; };

namespace fnv_00e51070 {
struct Count { int n; };

}  // namespace fnv_00e51070

struct ThresholdAllocator {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void ReleaseBlock(void*, int);
};
struct ThresholdArray {
    float* data;
    int size;
    int capacity;
    float* original;
    void SetSizeAndGrow(int count) {
        HolderStub* mgr = FUN_00c85750();
        E4AAA0Allocator* heap = (E4AAA0Allocator*)mgr->m_pAllocator;
        int current = capacity & 0x3fffffff;
        if (current < count) {
            int grown = 2 * current;
            FUN_00c908c0(heap, this, count < grown ? grown : count, 4);
        }
        size = count;
    }
    void release() {
        float* saved = original;
        if (saved == data) size = 0;
        FUN_00c85750()->unk00 = (int)saved;
        ClearAndRelease();
    }
    void ClearAndRelease() {
        HolderStub* mgr = FUN_00c85750();
        ThresholdAllocator* heap = (ThresholdAllocator*)mgr->m_pAllocator;
        int cap = capacity;
        size = 0;
        if ((cap & 0x80000000) == 0) heap->ReleaseBlock(data, (cap & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};

struct Q { __m128 m_vComponents; void FUN_005611c0(); };
struct QRef { Q* p; Q* operator->() const { return p; } };

template<class T> struct CurveArg { T value; };
struct V4 { float x, y, z, w; };
float __cdecl FUN_00e54cb0(int a3, int a4, int a5, int a6, float* p, int a9, int a10, float a11, float a12);
void __cdecl FUN_00e54630(V4* out, int a3, int a4, int a5, int a6, float v);

__declspec(noalias) float __cdecl LookupAndConsume(const Float4* left, const Float4* right);
extern "C" float __cdecl FUN_00e54cb0(int a, int b, int c, int d, Float4* p, int e, int f, float g, float h);

// hkpConstraintChainUtil_getAdjointEntities  (__cdecl, 4 args) -- walk a link array, collect incident entries
// The array append keeps the slot address materialised in a register (the original's
// `lea eax,[ecx+eax*4] ; mov [eax],edx`), which a single indexed store does not:
// the slot is reached through a local pointer that is written twice.
struct ChainElem {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_link14;
    void* m_link18;
};

template <class T>
struct ChainArray {
    T* m_data;
    int m_iElementCount;
    int m_capFlags;

    void Add(T const& value) {
        HolderStub* mgr = FUN_00c85750();
        if (m_iElementCount == (m_capFlags & 0x3fffffff))
            ResizeAudioStream(mgr->m_pAllocator, this, (int)sizeof(T));
        T* pSlot = &m_data[m_iElementCount];
        pSlot[0] = value;
        pSlot[0] = value;
        ++m_iElementCount;
    }
};

void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, int auiNewSize);

// @f3 0x00a914e0 (community match, verified in this file)
void __cdecl FUN_00901f10(void* array, int sizeOfElement);
// pdb: hkpConstraintChainUtil::getAdjointEntities | hkpConstraintChainUtil.obj | fnv360_0822_retail, call_gap, high
// pdb params: allConstraints, entity, entitiesOut, constraintsOut
// pdb: hkpConstraintChainUtil::getAdjointEntities | hkpConstraintChainUtil.obj | fnv360_0822_retail, call_gap, high (was: CollectConnectedNodesAndEdges)
void __cdecl hkpConstraintChainUtil_getAdjointEntities(ChainArray<void*>* src, void* node, ChainArray<void*>* outNodes, ChainArray<void*>* outEdges)
{
    for (int i = 0; i < src->m_iElementCount; ++i)
    {
        ChainElem* elem = (ChainElem*)src->m_data[i];
        void* a = elem->m_link14;
        if (a == node || elem->m_link18 == node)
        {
            void* other = (void*)((unsigned int)elem->m_link18 ^ (unsigned int)a ^ (unsigned int)node);
            if (outNodes->m_iElementCount == (outNodes->m_capFlags & 0x3fffffff))
                FUN_00901f10(outNodes, 4);
            outNodes->m_data[outNodes->m_iElementCount] = other;
            ++outNodes->m_iElementCount;
            if (outEdges->m_iElementCount == (outEdges->m_capFlags & 0x3fffffff))
                FUN_00901f10(outEdges, 4);
            outEdges->m_data[outEdges->m_iElementCount] = elem;
            ++outEdges->m_iElementCount;
        }
    }
}


namespace ns_e5c5 { int __cdecl hkString_strCasecmp(const char* a, const char* b) throw(); }
struct Resource_e5c5 {
    const char* FUN_00d46d40() throw();
    void FUN_00c905b0() throw();
};

template <class T> struct hkRefPtr_e5c5 {
    T* m_pRetainedObject;
    ~hkRefPtr_e5c5() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    T* FUN_00d477a0() throw();
    T* val() const { return m_pRetainedObject; }
};

struct Registry_e5c5 {
    hkRefPtr_e5c5<Resource_e5c5> FUN_00e5c4d0(const char* name) throw();
    Resource_e5c5* FUN_00e5c540(const char* name, Resource_e5c5* expected);
};

// Looks up a resource by name and returns it if expected is null or its name matches case-insensitively, otherwise returns null.
// @fnv 0x00e5c540
Resource_e5c5* Registry_e5c5::FUN_00e5c540(const char* name, Resource_e5c5* expected)
{
    hkRefPtr_e5c5<Resource_e5c5> found = FUN_00e5c4d0(name);
    if (found.m_pRetainedObject) {
        if (!expected || ns_e5c5::hkString_strCasecmp(expected->FUN_00d46d40(), found.FUN_00d477a0()->FUN_00d46d40()) == 0)
            return found.m_pRetainedObject;
    }
    return 0;
}

struct __declspec(align(16)) Aabb {
    float minX, minY, minZ, minW;
    float maxX, maxY, maxZ, maxW;
};

struct RefObject {
    virtual ~RefObject() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObject() throw() { m_sReferenceCount = 1; }
};

struct HkArr {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    HkArr() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};

struct CollectorBase {
    virtual void Dummy0() throw();
    CollectorBase() throw() {}
};

struct Mid : RefObject, CollectorBase {
    HkArr m_ppData;
    int m_18;
    Mid() throw() : m_18(0) {}
};

struct FnvCpu_FUN_00e49bb0_CpuObject { char* FUN_00e49bb0(); };
// @fnv 0x00e49bb0
// pdb: hkpCollisionFilterList::getCollisionFilters | hkpCollisionFilterList.obj | fnv360_0822_retail, objrun_open, low
char* FnvCpu_FUN_00e49bb0_CpuObject::FUN_00e49bb0()
{
    return reinterpret_cast<char*>(this) + 48;
}

namespace Components {
struct FUN_00e53160 {
    float x, y, z, w;
    __declspec(noinline) FUN_00e53160(float a, float b, float c, float d);
};
}

struct KnotVector {
    float x,y,z,w;
    KnotVector(float a=0,float b=0,float c=0,float d=0);
    KnotVector& FUN_00e53180(const KnotVector&);
    KnotVector& operator=(const KnotVector& v) { return FUN_00e53180(v); }
    KnotVector& FUN_00e531a0(const KnotVector&);
    KnotVector& FUN_00e531d0(const KnotVector&);
    KnotVector& FUN_00e53200(float);
    KnotVector& DivideByScalar(float);
    KnotVector ScaleCopy(float) const;
    KnotVector FUN_00e532b0(const KnotVector&) const;
    KnotVector FUN_00e53260(const KnotVector&) const;
    KnotVector EvalCopy(float) const;
};
__declspec(noinline) KnotVector::KnotVector(float a,float b,float c,float d) : x(a),y(b),z(c),w(d) {}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53180(const KnotVector& v) { x=v.x;y=v.y;z=v.z;w=v.w;return *this; }

void* _fnv_zlib_memset(void*,int,int);
struct MarkHeap {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual void* Allocate(int&);
 virtual void Free(void*,int);
 template<class T> __forceinline T* reserve(int& count) {
  int bytes=count*sizeof(T);
  T* p=(T*)Allocate(bytes);
  count=bytes/sizeof(T);
  return p;
 }
 template<class T> __forceinline void freeBuffer(T* p,int count) {Free(p,count*sizeof(T));}
};
struct MarkPolicy {
 __forceinline MarkHeap& get(void* owner) {HolderStub* h=FUN_00c85750();return *(MarkHeap*)h->m_pAllocator;}
};
template<class T> struct MarkStorage {
 T* data; int size; int capacity;
 __forceinline MarkStorage():data(0),size(0),capacity(0x80000000){}
 __forceinline void own(T* p,int n,int c) {data=p;size=n;capacity=c;}
 __forceinline T& operator[](int i) {return data[i];}
};
template<class T> struct MarkArray:MarkStorage<T> {
 __forceinline MarkArray(int count,const T& initial) {
  MarkHeap& heap=MarkPolicy().get(this);
  T* p=count ? heap.reserve<T>(count) : 0;
  int flags=count ? count : (int)0x80000000;
  own(p,count,flags);
  if(size>0) _fnv_zlib_memset(data,initial,size);
 }
 __forceinline void release() {
  MarkHeap* heap=(MarkHeap*)FUN_00c85750()->m_pAllocator;
  int cap=capacity;
  size=0;
  if((cap&0x80000000)==0) heap->Free(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;
 }
};
struct MarkBounds { float* data; };
int FindFloatInterval(int,int,float,MarkBounds*);
bool* IsSampleBoundary(bool*,int,MarkBounds*,int);
void* _fnv_zlib_memset(void*,int,int);

namespace fnv_00e57620 {
struct KnotVector {
 float x,y,z,w;
 KnotVector(float a=0,float b=0,float c=0,float d=0);
 __declspec(noinline) KnotVector& FUN_00e53180(const KnotVector&);
 __declspec(noinline) KnotVector& FUN_00e531a0(const KnotVector&);
 __declspec(noinline) KnotVector FUN_00e532b0(const KnotVector&) const;
 __declspec(noinline) KnotVector& FUN_00e531d0(const KnotVector&);
 __declspec(noinline) KnotVector& FUN_00e53200(float);
 __declspec(noinline) KnotVector ScaleCopy(float) const;
 __declspec(noinline) float& FUN_00e53590(int);
 __declspec(noinline) const float& FUN_00e53590(int) const;
 __declspec(noinline) float FUN_00e53580(int) const;
};
__declspec(noinline) KnotVector::KnotVector(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53180(const KnotVector& b) {x=b.x;y=b.y;z=b.z;w=b.w;return *this;}
__declspec(noinline) KnotVector __cdecl FUN_00e533a0(float s,const KnotVector& b);
struct ElevationAllocator {
 virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2();
 virtual void* allocate(int* bytes); virtual void release(void* data,int bytes);
};
void __cdecl FUN_00c908c0(void* alloc, void* array,int count,int elementSize);
template<class T> struct ElevationArray {
 T* data; int count; int capacity;
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline void allocate(int requested) {
  ElevationAllocator* allocator=(ElevationAllocator*)FUN_00c85750()->m_pAllocator;
  T* ptr;
  if(requested) {int bytes=requested*sizeof(T);ptr=(T*)allocator->allocate(&bytes);requested=bytes/(int)sizeof(T);} else ptr=0;
  int flags=requested?requested:0x80000000;
  data=ptr;count=requested;capacity=flags;
 }
 __forceinline void reserve(int requested) {
  HolderStub* h=FUN_00c85750();
  void* allocator=h->m_pAllocator;
  int cap=capacity&0x3fffffff;
  if(cap<requested) {int doubled=cap*2;FUN_00c908c0(allocator,this,requested<doubled?doubled:requested,sizeof(T));}
 }
 __forceinline void resize(int requested) {
  reserve(requested);
  int added=requested-count;
  T* start=data+count;
  for(int k=0;k<added;++k) new(start+k) T;
  count=requested;
 }
 __forceinline void free() {
  HolderStub* h=FUN_00c85750();
  ElevationAllocator* allocator=(ElevationAllocator*)h->m_pAllocator;
  int cap=capacity;
  count=0;
  if((cap & 0x80000000)==0) allocator->release(data,(cap&0x3fffffff)*sizeof(T));
  data=0;capacity=0x80000000;
 }
 void SwapThreeInts(ElevationArray<T>* other);
};
struct FitMatrix {
 ElevationArray<float> values; int rows,cols;
 void InitFloatArray(int a,int b,float f);
 void InitArray(int a,int b);
 float& GetElementPtr(int a,int b);
 __declspec(noinline) int FUN_00e587a0();
 __declspec(noinline) int FUN_00cc0760();
 void FUN_00c7b0f0();
 __forceinline void set(int a,int b,float value) {GetElementPtr(a,b)=value;}
};
}  // namespace fnv_00e57620

struct MemoryAllocator;
// Adapted from an unverified 2026-10-23 saved reconstruction (credited as 'you').
struct Vertex4 {

    float x, y, z, w;

    Vertex4(float a=0, float b=0, float c=0, float d=0);

    Vertex4* FUN_00e53180(const Vertex4* source);

};
__declspec(noinline) Vertex4::Vertex4(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
__declspec(noinline) Vertex4* Vertex4::FUN_00e53180(const Vertex4* source) { x=source->x; y=source->y; z=source->z; w=source->w; return this; }
struct FloatVector {
    void reserve(MemoryAllocator& alloc, int wanted);

    float* data;

    int count;

    unsigned int capacity;

};
struct VertexVector {
    void SetSizeAndGrow(int wanted);
    void reserve(MemoryAllocator& alloc, int wanted);

    Vertex4* data;

    int count;

    unsigned int capacity;

};
struct MemoryAllocator {

    virtual void ReportDiagnostic();

    virtual void unused1();

    virtual void unused2();

    virtual void* Allocate(int* requestedBytes);

    virtual void Free(void* pointer, int requestedBytes);

};
extern const float DAT_010718c0, DAT_010959f4;
__forceinline void FloatVector::reserve(MemoryAllocator& heap, int wanted) {
    MemoryAllocator* alloc = &heap;
    FloatVector* vec = this;

    int cap = (int)(vec->capacity & 0x3fffffff);

    if (cap < wanted) {

        const int doubled = cap + cap;

        const int newCapacity = wanted < doubled ? doubled : wanted;

        FUN_00c908c0((E4AAA0Allocator*)alloc, vec, newCapacity, 4);

    }

}
__forceinline void VertexVector::reserve(MemoryAllocator& heap, int wanted) {
    MemoryAllocator* alloc = &heap;
    VertexVector* vec = this;

    int cap = (int)(vec->capacity & 0x3fffffff);

    if (cap < wanted) {

        const int doubled = cap + cap;

        const int newCapacity = wanted < doubled ? doubled : wanted;

        FUN_00c908c0((E4AAA0Allocator*)alloc, vec, newCapacity, 16);

    }

}

struct SpawnedBlockRef {
    void* data;
    int count;
    unsigned int flags;
};

void __cdecl ProcessGeometryPasses(int a1, int a2, SpawnedBlockRef* block, hkBool enabled, int b1, float b2, int b3, int b4, int b5);

extern float DAT_0104da4c;
extern const float runtimeFloatSettingDefault1085 = 1.1f;

inline void ApplyBound(float& out, float value) {
    out = value;
    if (out < -1.1f) out = -1.1f;
    else if (out > runtimeFloatSettingDefault1085) out = runtimeFloatSettingDefault1085;
}

struct Se5b160_Heap {
    virtual ~Se5b160_Heap();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct Se5b160_Router {
    int unk00; int unk04; int unk08; int unk0c;
    Se5b160_Heap* m_pStreamAllocator;
    Se5b160_Heap& heap() { return *m_pStreamAllocator; }
    static Se5b160_Router& GetMonitorStream() { return *reinterpret_cast<Se5b160_Router*>(FUN_00c85750()); }
};
struct Se5b160_Motor { void FUN_00c90510(); };
struct Se5b160_RefObj {
    virtual ~Se5b160_RefObj();
    static Se5b160_Heap& heap() { return reinterpret_cast<Se5b160_Router*>(FUN_00c85750())->heap(); }
    unsigned short m_usAllocationSize;
    unsigned short m_iObjectReferenceCount;
    static void* operator new(unsigned int nbytes) {
        Se5b160_RefObj* b = static_cast<Se5b160_RefObj*>(Se5b160_Router::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usAllocationSize = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void*) {}
    void FUN_00c905b0();
};
struct Se5b160_HingeAtoms {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    Se5b160_Motor* motor0;
    void CopyStateFrom(const Se5b160_HingeAtoms* source);
};
struct Se5b160_RagdollAtoms {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    Se5b160_Motor* motor0;
    Se5b160_Motor* motor1;
    Se5b160_Motor* motor2;
    void FUN_00d85ba0(const Se5b160_RagdollAtoms* source);
};
static __declspec(noinline) void FUN_00e5b110(const Se5b160_HingeAtoms* source, Se5b160_HingeAtoms* destination) {
    destination->CopyStateFrom(source);
    Se5b160_Motor* m = destination->motor0;
    if (m) m->FUN_00c90510();
}
static __declspec(noinline) void FUN_00e5b130(const Se5b160_RagdollAtoms* source, Se5b160_RagdollAtoms* destination) {
    destination->FUN_00d85ba0(source);
    Se5b160_Motor** motor = &destination->motor0;
    for (int i = 0; i < 3; ++i, ++motor) {
        if (*motor) (*motor)->FUN_00c90510();
    }
}
enum Se5b160_Type { S5b160_T0, S5b160_T1, S5b160_LIMITEDHINGE, S5b160_T3, S5b160_T4, S5b160_T5, S5b160_T6, S5b160_RAGDOLL };
struct Se5b160_Data : Se5b160_RefObj {
    virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Se5b160_Type getType() const;
    int unk08; int unk0c;
};
struct Se5b160_StrPtr {
    const char* m_pcText;
    const char* cString() const { return reinterpret_cast<const char*>(reinterpret_cast<unsigned int>(m_pcText) & ~1u); }
    void FUN_00cb0c10(const char* s);
};
struct Se5b160_Entity;
enum Se5b160_Prio { S5b160_PRIO_INVALID, S5b160_PRIO_PSI, S5b160_PRIO_TOI };
struct Se5b160_PrioEnum {
    unsigned char m_kStorage;
    operator Se5b160_Prio() const { return static_cast<Se5b160_Prio>(m_kStorage); }
};
struct FUN_00cf3ea0 : Se5b160_RefObj {
    int unk08;
    Se5b160_Data* m_data;
    int unk10;
    Se5b160_Entity* m_pEntityA;
    Se5b160_Entity* m_pEntityB;
    Se5b160_PrioEnum m_priority;
    unsigned char unk1d;
    unsigned short unk1e;
    int unk20;
    int unk24;
    Se5b160_StrPtr m_name;
    int unk2c; int unk30; int unk34;
    FUN_00cf3ea0(Se5b160_Entity* a, Se5b160_Entity* b, Se5b160_Data* data, Se5b160_Prio priority) throw();
    Se5b160_Prio getPriority() const { return m_priority; }
    Se5b160_Entity* getEntityA() const { return m_pEntityA; }
    Se5b160_Entity* getEntityB() const { return m_pEntityB; }
};
typedef FUN_00cf3ea0 Se5b160_Instance;

// @f3 0x00a90d40 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;

// Target-build layout views: the pack's stand-ins for the referenced-object, constraint-data and
// constraint-instance classes are shaped like the later engine (router allocation,
// type query at virtual slot 8, instance name at 0x28) and cannot be redefined here.
// This build allocates referenced objects from the thread memory, has the type query
// at vtable byte offset 0x10 and a 0x2c-byte instance with the name at 0x20. The Pc_ classes below
// carry that layout; the function views its pack-typed argument and result through
// them. Nothing else steers the compiler.
struct Pc_ThreadMemory {
    void* allocateChunk(int numBytes, int memoryClass);
    static Pc_ThreadMemory& getInstance() {
        return *static_cast<Pc_ThreadMemory*>(TlsGetValue(DAT_010f3170));
    }
};
struct Pc_RefObj {
    virtual ~Pc_RefObj();
    unsigned short m_usAllocationSize;
    short m_iObjectReferenceCount;
    static void* operator new(unsigned int nbytes) {
        Pc_RefObj* b = static_cast<Pc_RefObj*>(Pc_ThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes), 0x2c));
        b->m_usAllocationSize = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);
    void removeReference() {
        if (m_usAllocationSize != 0) {
            --m_iObjectReferenceCount;
            if (m_iObjectReferenceCount == 0)
                delete this;
        }
    }
};
struct Pc_Data : Pc_RefObj {
    virtual void v1(); virtual void v2(); virtual void v3();
    virtual Se5b160_Type getType() const;
    int unk08; int unk0c;
};
struct Pc_HingeData : Pc_Data {
    Se5b160_HingeAtoms m_kBridgeAtoms;
    int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    Pc_HingeData() throw();
    void SetReferencedObject(Se5b160_Motor* motor);
    void FUN_00cb8fe0(void* info, bool enabled);
};
struct Pc_RagdollData : Pc_Data {
    Se5b160_RagdollAtoms m_kBridgeAtoms;
    int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    Pc_RagdollData() throw();
    void FUN_00cdea70(Se5b160_Motor* motor);
    void FUN_00cdeab0(Se5b160_Motor* motor);
    void FUN_00cdea90(Se5b160_Motor* motor);
    void SetFlagAndClearFloats(void* info, bool enabled);
};
struct Pc_Instance : Pc_RefObj {
    int unk08;
    Pc_Data* m_data;
    int unk10;
    Se5b160_Entity* m_pEntityA;
    Se5b160_Entity* m_pEntityB;
    Se5b160_PrioEnum m_priority;
    unsigned char unk1d;
    unsigned short unk1e;
    const char* m_name;
    int unk24;
    int unk28;
    Pc_Instance(Se5b160_Entity* a, Se5b160_Entity* b, Pc_Data* data, Se5b160_Prio priority) throw();
    Pc_Data* getData() const { return m_data; }
    Se5b160_Prio getPriority() const { return m_priority; }
    Se5b160_Entity* getEntityA() const { return m_pEntityA; }
    Se5b160_Entity* getEntityB() const { return m_pEntityB; }
    const char* getName() const { return m_name; }
    void setName(const char* name) { m_name = name; }
};

// The pack's prototype qualifies the first parameter __restrict; the definition leaves
// the qualifier off (same function, same symbol), because with it the size store of the
// last allocation sinks below the argument loads of the constructor call.
Se5b160_Instance* __cdecl hkpConstraintUtils_convertToPowered(const Se5b160_Instance* __restrict original, Se5b160_Motor* motor, bool enableMotors);

// pdb: hkpConstraintUtils::convertToPowered | hkpConstraintUtils.obj | fnv360_0822_retail, ustr, high
// pdb params: originalConstraint, constraintMotor, enableMotors
// pdb: hkpConstraintUtils::convertToPowered | hkpConstraintUtils.obj | fnv360_0822_retail, ustr, high (was: CreatePoweredConstraint)
Se5b160_Instance* __cdecl hkpConstraintUtils_convertToPowered(const Se5b160_Instance* original, Se5b160_Motor* motor, bool enableMotors) {
    // View the shared prototype through the independently checked target-build layout.
    const Pc_Instance* originalConstraint = reinterpret_cast<const Pc_Instance*>(original);
    Pc_Instance* newConstraint = 0;
    Pc_Data* constraintData = originalConstraint->getData();
    Se5b160_Entity* entityA = originalConstraint->getEntityA();
    Se5b160_Entity* entityB = originalConstraint->getEntityB();
    switch (constraintData->getType()) {
    case S5b160_LIMITEDHINGE: {
        Pc_HingeData* oldData = static_cast<Pc_HingeData*>(constraintData);
        Pc_HingeData* newData = new Pc_HingeData();
        newData->m_kBridgeAtoms.CopyStateFrom(&oldData->m_kBridgeAtoms);
        newData->SetReferencedObject(motor);
        newData->FUN_00cb8fe0(0, enableMotors);
        newConstraint = new Pc_Instance(entityA, entityB, newData, originalConstraint->getPriority());
        newData->removeReference();
        newConstraint->setName(originalConstraint->getName());
        break;
    }
    case S5b160_RAGDOLL: {
        Pc_RagdollData* oldData = static_cast<Pc_RagdollData*>(constraintData);
        Pc_RagdollData* newData = new Pc_RagdollData();
        newData->m_kBridgeAtoms.FUN_00d85ba0(&oldData->m_kBridgeAtoms);
        newData->FUN_00cdea70(motor);
        newData->FUN_00cdeab0(motor);
        newData->FUN_00cdea90(motor);
        newData->SetFlagAndClearFloats(0, enableMotors);
        newConstraint = new Pc_Instance(entityA, entityB, newData, originalConstraint->getPriority());
        newData->removeReference();
        newConstraint->setName(originalConstraint->getName());
        break;
    }
    default:
        {
            int buf[128];
            CharBuffer ostr;
            ostr.FUN_00cb1600(reinterpret_cast<char*>(buf), sizeof(buf));
            ostr.FUN_00cc01c0("Cannot convert constraint \"")->FUN_00cc01c0(originalConstraint->getName())->FUN_00cc01c0("\" to a powered constraint.");
            DAT_01268360->report(1, 0xabba1b34, reinterpret_cast<char*>(buf), ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 87);
            ostr.FUN_00cc00e0();
        }
        {
            int buf[128];
            CharBuffer ostr;
            ostr.FUN_00cb1600(reinterpret_cast<char*>(buf), sizeof(buf));
            ostr.FUN_00cc01c0("Only limited hinges and ragdoll constraints can be powered.");
            DAT_01268360->report(1, 0xabba1b34, reinterpret_cast<char*>(buf), ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 88);
            ostr.FUN_00cc00e0();
        }
        return 0;
    }
    return reinterpret_cast<Se5b160_Instance*>(newConstraint);
}


struct E5B130Object {
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
    Ref* items[3];
    void FUN_00d85ba0(int finishFlags);
};

// Calls FUN_00d85ba0 with finishFlags, then iterates the three item pointers and calls FUN_00c90510 on each non-null item.
// @f3 0x00615e50 (community match, verified in this file)
// Candidate for 0x00615e50.
// The matching body (member FUN_00615e50) is the byte-exact function.
// Also provide a definition for the stale overload declaration
// `static void FUN_00e5b130(E5B130Object*, int)` that exists in this unit,
// so CallFinishObject() keeps resolving against an E5B130Object* argument.

namespace terrain_615e50 {

struct Heap
{
    void FUN_0086ba60(void* memory);
};

extern Heap DAT_01090a78;

struct Payload
{
    void FUN_00614f90();
};

struct Node
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Payload* payload;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    Node* children[4];
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned char ownsPayload;

    void FUN_00615e50();
};

// pdb: BGSTerrainNode::UnloadPersistentDataRecurse | BGSTerrainNode.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BGSTerrainManager::GetCurrentWorldHasLOD)
void Node::FUN_00615e50()
{
    Payload* owned = payload;
    if (owned && ownsPayload)
    {
        owned->FUN_00614f90();
        DAT_01090a78.FUN_0086ba60(owned);
        payload = 0;
    }

    Node** cursor = children;
    unsigned int remaining = sizeof(children) / sizeof(children[0]);
    do
    {
        Node* child = *cursor;
        if (child)
            child->FUN_00615e50();
        ++cursor;
    } while (--remaining);
}

} // namespace terrain_615e50

// Re-declare and define the stale overload so the project file's
// CallFinishObject() still sees an E5B130Object* overload at its call site.
struct E5B130Object;

E5B130Object* volatile g_finishObject;
volatile int g_finishFlags;

#include <xmmintrin.h>
namespace fnv_00e4b6e0 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {float f[4];};
extern "C" {__m128 _mm_mul_ps(__m128,__m128);__m128 _mm_sub_ps(__m128,__m128);__m128 _mm_add_ss(__m128,__m128);__m128 _mm_shuffle_ps(__m128,__m128,int);int _mm_movemask_ps(__m128);__m128 _mm_rsqrt_ss(__m128);}

struct __declspec(align(16)) Vec4 {
__m128 q;
__m128 get()const { return q; }
void set(__m128 v){ q=v; }
Vec4(){} Vec4(__m128 v){set(v);} Vec4(const Vec4& v){set(v.get());} Vec4& operator=(const Vec4& v){set(v.get());return *this;}
void sub(const Vec4& x,const Vec4& y){set(_mm_sub_ps(x.get(),y.get()));}
__m128 dot(const Vec4& y) const {__m128 v=_mm_mul_ps(get(),y.get()); __m128 xy=_mm_add_ss(_mm_shuffle_ps(v,v,0x55),v); return _mm_add_ss(_mm_shuffle_ps(v,v,0xaa),xy);}
void normalize(){__m128 squared=dot(*this);__m128 inv=_mm_rsqrt_ss(squared);set(_mm_mul_ps(get(),_mm_shuffle_ps(inv,inv,0)));}
void cross(const Vec4& x,const Vec4& y){__m128 xv=x.get(),yv=y.get();__m128 pos=_mm_mul_ps(_mm_shuffle_ps(xv,xv,0xc9),_mm_shuffle_ps(yv,yv,0xd2));__m128 neg=_mm_mul_ps(_mm_shuffle_ps(xv,xv,0xd2),_mm_shuffle_ps(yv,yv,0xc9));set(_mm_sub_ps(pos,neg));}
};
struct PointArg {const Vec4* p; PointArg(const Vec4* v):p(v){}};
struct Segment {Vec4 first,second,unk20,unk30,firstMeta,secondMeta;};
// Tests a point against segment endpoints; between them writes a cross product and returns count, otherwise writes a difference vector and returns 1.
// @fnv 0x00e4b6e0
Vec4* volatile pointInput;Segment* volatile segmentInput;Vec4* volatile resultInput;volatile int kindInput;
}  // namespace fnv_00e4b6e0

struct S00e58310_Allocator {
    virtual ~S00e58310_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T>
    inline T* _bufAlloc(int& reqNumInOut)
    {
        const int SIZE_ELEM = sizeof(T);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<T*>(p);
    }
    template <typename T>
    inline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};

struct S00e58310_Router {
    int m_aiEntries;
    int m_pTemp;
    int m_pSolver;
    int m_pDebugAllocator;
    S00e58310_Allocator* m_pStreamAllocator;
    S00e58310_Allocator& heap() { return *m_pStreamAllocator; }
    static __forceinline S00e58310_Router& GetMonitorStream();
};

__forceinline S00e58310_Router& S00e58310_Router::GetMonitorStream()
{
    return *(S00e58310_Router*)FUN_00c85750();
}

struct S00e58310_HeapAllocator {
    S00e58310_Allocator& get(const void*) { return S00e58310_Router::GetMonitorStream().heap(); }
};

struct S00e58310_TypeIsPod {};

struct S00e58310_Util {
    template <typename T>
    static __forceinline void destruct(T*, int, S00e58310_TypeIsPod) {}
};

template <typename T>
struct S00e58310_ArrayBase {
    enum { CAPACITY_MASK = 0x3FFFFFFF, DONT_DEALLOCATE_FLAG = 0x80000000 };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & CAPACITY_MASK; }
    static __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i) {
            dst[i] = src[i];
        }
    }
    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void clear()
    {
        S00e58310_Util::destruct(m_data, m_iElementCount, S00e58310_TypeIsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(S00e58310_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline S00e58310_ArrayBase<T>& copyFromArray(S00e58310_Allocator& alloc, const S00e58310_ArrayBase<T>& a, S00e58310_TypeIsPod)
    {
        if (getCapacity() < a.GetLogicalSize()) {
            if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
                alloc._bufFree<T>(m_data, getCapacity());
            }
            int n = a.GetLogicalSize();
            m_data = alloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copy(m_data, a.m_data, m_iElementCount);
        return *this;
    }
};

template <typename T>
struct S00e58310_Array : S00e58310_ArrayBase<T> {
    __forceinline S00e58310_Array<T>& operator=(const S00e58310_Array<T>& a)
    {
        copyFromArray(S00e58310_HeapAllocator().get(this), a, S00e58310_TypeIsPod());
        return *this;
    }
    __forceinline void destroy()
    {
        _clearAndDeallocate(S00e58310_HeapAllocator().get(this));
    }
};

struct CurvePoint { float x,y,z,w; CurvePoint(float a=0,float b=0,float c=0,float d=0) throw(); float& FUN_00e53590(int); };
__declspec(noinline) CurvePoint::CurvePoint(float a,float b,float c,float d) throw():x(a),y(b),z(c),w(d){}
struct CurveHeap {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void* allocate(int& bytes) throw();
 virtual void release(void* ptr,int bytes) throw();
 template<class T> __forceinline T* allocateItems(int& n) {
  int request=n*(int)sizeof(T);
  T* ptr=static_cast<T*>(allocate(request));
  n=request/(int)sizeof(T);
  return ptr;
 }
 template<class T> __forceinline void freeItems(T* ptr,int n) {release(ptr,n*(int)sizeof(T));}
};
struct CurvePolicy {
 __forceinline CurveHeap& get(void*) {return *static_cast<CurveHeap*>(FUN_00c85750()->m_pAllocator);}
};
__forceinline void initializeItems(float*,int) {}
__forceinline void initializeItems(CurvePoint* ptr,int n) {for(int i=0;i<n;++i) new(ptr+i) CurvePoint;}
template<class T> struct FitOwnedArrayBase {
 T* data;int size;int capacity;
 __forceinline FitOwnedArrayBase():data(0),size(0),capacity(0x80000000){}
 __forceinline void set(T* p,int n,int cap) {data=p;size=n;capacity=cap;}
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline const T& operator[](int i) const {return data[i];}
 __forceinline void clear(CurveHeap& heap) {
  size=0;
  int cap=capacity;
  if(!(cap&0x80000000)) heap.freeItems<T>(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;
 }
};
template<class T> struct FitOwnedArray:FitOwnedArrayBase<T> {
 __forceinline FitOwnedArray() throw() {}
 __forceinline FitOwnedArray(int n) throw() {
  HolderStub* holder=FUN_00c85750(); CurveHeap* heap=static_cast<CurveHeap*>(holder->m_pAllocator);
  T* p=n?heap->allocateItems<T>(n):0;
  int cap=n?n:0x80000000;
  set(p,n,cap);
  initializeItems(data,n);
 }
 __forceinline ~FitOwnedArray() throw() {HolderStub* holder=FUN_00c85750(); CurveHeap* heap=static_cast<CurveHeap*>(holder->m_pAllocator);
  int cap=capacity; size=0;
  if(!(cap&0x80000000)) heap->freeItems<T>(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;}
};
struct CurveWirePoints {CurvePoint* data;int size;int capacity;};
void __cdecl ProcessGeometryPasses(int,const CurveWirePoints*,FitOwnedArray<float>*,hkBool,int,float,int*,FitOwnedArray<float>*,FitOwnedArray<CurvePoint>*) throw();

struct E589Values { float* data; int unknown04; int unknown08; int rows; int columns;
    __declspec(noinline) float FUN_00e58880(int index) { return data[index]; }
    int FUN_00e58890();
};
struct E589ScaledValues { float* data; int unknown04; int unknown08; int rows; int columns;
    __declspec(noinline) float FUN_00e58880(int index) { return data[index]; }
};

extern "C" void _ReadWriteBarrier();
extern __m128 DAT_01017d10;
extern const double DAT_01091c00;
struct __declspec(align(16)) PlaneVector {

    float f[4];

    __forceinline const __m128& quad() const { return *reinterpret_cast<const __m128*>(this); }

    __forceinline void assign(__m128 q) { *reinterpret_cast<__m128*>(this)=q; }

    __forceinline void setAnd(const PlaneVector& a, const __m128& b) { assign(_mm_and_ps(a.quad(), b)); }

    __forceinline void setZero4() { assign(_mm_setzero_ps()); }

    __forceinline void setAdd4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_add_ps(a.quad(), b.quad())); }

    __forceinline void setMul4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_mul_ps(a.quad(), b.quad())); }

    __forceinline void addMul4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_add_ps(quad(), _mm_mul_ps(a.quad(), b.quad()))); }

    __forceinline void setBroadcast(const PlaneVector& v, int i) { assign(_mm_shuffle_ps(v.quad(), v.quad(), 0)); }

    __forceinline void setAbs4(const PlaneVector& a) { assign(_mm_and_ps(a.quad(),DAT_01017d10)); }
    __forceinline void add4(const PlaneVector& a) { assign(_mm_add_ps(quad(),a.quad())); }
    __forceinline void setAll3(float f) { assign(_mm_set_ps1(f)); }

    float& operator()(int i) { return f[i]; }

    const float& operator()(int i) const { return f[i]; }

};


struct PlaneGroup {

    PlaneVector x, y, z, w;

    __forceinline void set(const PlaneVector& a, const PlaneVector& b, const PlaneVector& c, const PlaneVector& d) {

        x.assign(_mm_setr_ps(a(0),b(0),c(0),d(0)));

        y.assign(_mm_setr_ps(a(1),b(1),c(1),d(1)));

        z.assign(_mm_setr_ps(a(2),b(2),c(2),d(2)));

        w.assign(_mm_setr_ps(a(3),b(3),c(3),d(3)));

    }

};

struct QueryCode {
    void* table;
    unsigned short memoryFlags, references;
    PlaneVector origin;
    const unsigned char* program;
};
struct PlaneView { int count; const PlaneVector* data; };
struct QueryState { int x,y,z,primitive,property,shift; };
struct QueryBounds { PlaneVector minimum, scale; };
struct QueryMachine {
    int partial;
    __declspec(align(16)) float inverseScale;
    __declspec(align(16)) int complete;
    __declspec(align(16)) int count;
    PlaneGroup groups[8], magnitudes[8];
    void __thiscall FUN_00e5e430(QueryState*,const unsigned char*,QueryBounds*);
    __forceinline void prepare(const PlaneView& view, unsigned codeBits) {
        const QueryCode* code=reinterpret_cast<const QueryCode*>(codeBits);
        __assume(view.count>=0 && view.count<=32); int end=view.count & ~3;
        PlaneGroup* dest=groups;
        const PlaneVector* cursor=view.data;
        count=0;
        int n=0;
        for(;n<end;n+=4) {
            dest->set(cursor[0],cursor[1],cursor[2],cursor[3]);
            ++dest; ++count; cursor+=4;
        }
        const PlaneVector* a=cursor;
        const PlaneVector* b=cursor+1;
        const PlaneVector* c=cursor+2;
        const PlaneVector* d=cursor+3;
        switch(view.count-n) {
        case 1:b=a;
        case 2:c=a;
        case 3:d=a;
            dest->set(*a,*b,*c,*d);
            ++dest; ++count;
        }
        PlaneGroup* absolute=magnitudes+count;
        --absolute; --dest;
        for(;dest>=groups;--dest,--absolute) {
            PlaneGroup* g=dest; PlaneVector PlaneGroup::* yfield=&PlaneGroup::y; PlaneVector PlaneGroup::* zfield=&PlaneGroup::z;
            _ReadWriteBarrier(); absolute->x.setAbs4(g->x); _ReadWriteBarrier();
            absolute->y.setAbs4((g->*yfield)); _ReadWriteBarrier();
            absolute->z.assign(_mm_and_ps(DAT_01017d10,(g->*zfield).quad())); _ReadWriteBarrier();
            absolute->w.setZero4(); _ReadWriteBarrier();

        const PlaneVector& offset = code->origin;

        g->w.assign(_mm_add_ps(_mm_add_ps(_mm_add_ps(

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0x00), g->x.quad()),

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0x55), (g->*yfield).quad())),

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0xaa), (g->*zfield).quad())), g->w.quad()));

        _ReadWriteBarrier();

        const __m128& w = g->w.quad();

        _ReadWriteBarrier();

        g->w.assign(_mm_add_ps(g->w.quad(), w));


        }
    }
    __forceinline void query(unsigned codeBits,const PlaneView& view,int output,int properties) {
        const QueryCode* code=reinterpret_cast<const QueryCode*>(codeBits);
        const unsigned char* pc=code->program;
        partial=output;
        QueryState state;
        QueryBounds bounds;
        inverseScale=1.0f/code->origin(3);
        state.z=0; state.primitive=0; state.property=0; state.shift=16;
        state.x=0; state.y=0;
        bounds.minimum.setZero4();
        bounds.scale.setAll3(float(inverseScale*DAT_01091c00));
        prepare(view,codeBits);
        complete=properties;
        FUN_00e5e430(&state,pc,&bounds);
    }
};

#include <xmmintrin.h>
namespace fnv_00e5d650 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" {
__m128 _mm_set_ps1(float a);
__m128 _mm_setzero_ps(void);
__m128 _mm_add_ps(__m128 a, __m128 b);
__m128 _mm_sub_ps(__m128 a, __m128 b);
__m128 _mm_unpackhi_ps(__m128 a, __m128 b);
__m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
}
struct hkVector4 {
    __m128 m_vComponents;
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void SetAllComponents(float x) { m_vComponents = _mm_set_ps1(x); }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void add4(const hkVector4& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    __forceinline void setXYZ(const hkVector4& v) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4); }
    __forceinline float& operator()(int i) { return m_vComponents.m128_f32[i]; }
    __forceinline const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
};
extern const double DAT_01091c00;
}  // namespace fnv_00e5d650

#include <xmmintrin.h>
namespace fnv_00e5d710 {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_set_ps1(float);
extern "C" double DAT_01091c00;
union __declspec(align(16)) QueryVector {
    __m128 quad;
    struct { float x, y, z, w; } components;
};
struct QueryCode {
    int unk00, unk04, unk08, unk0c;
    QueryVector offset;
    unsigned char* data;
};
struct QueryState {
    int primitiveOffset, properties, x, y, z, shift;
    QueryState() { x=0; y=0; z=0; primitiveOffset=0; properties=0; }
};
struct QueryBounds { QueryVector low, high; };
}  // namespace fnv_00e5d710

struct S00e49e00_Slot {};
inline void* operator new(size_t, void* p, S00e49e00_Slot) { __assume(p != 0); return p; }
inline void operator delete(void*, void*, S00e49e00_Slot) {}

namespace se49e00 {

struct Allocator;

struct AllocatorHolder {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    Allocator* m_pHeapAllocator;
};

AllocatorHolder* FUN_00c85750();
void ResizeAudioStream(Allocator* pkAllocator, void* apvArray, unsigned int uiStride);
void __fastcall FUN_00c90510(void* pvObject);

template <class T> struct ObjectArray {
    T* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;

    void PushBack(const T& kElement)
    {
        AllocatorHolder* pkHolder = FUN_00c85750();
        if (m_uiLogicalSize == (m_iCapacityAndFlags & 0x3fffffff))
            ResizeAudioStream(pkHolder->m_pHeapAllocator, this, sizeof(T));
        new (&m_pData[m_uiLogicalSize], S00e49e00_Slot()) T(kElement);
        m_uiLogicalSize++;
    }
};

}

namespace e54 {
int __cdecl FindFloatInterval(int a, int degree, float u, float** knots);
}
