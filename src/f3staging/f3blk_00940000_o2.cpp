#include <new>
// src/f3staging/f3blk_00940000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009439d0 (community match, verified in this file)
extern const char DAT_00dbfab8[];
namespace f3m_009439d0 {
struct Object763 {
    void FUN_00943710(const char* name);
    void FUN_009439b0();
};
Object763* FUN_009439d0(Object763* object)
{
    object->FUN_00943710(DAT_00dbfab8);
    object->FUN_009439b0();
    return object;
}
}   // namespace f3m_009439d0

// @f3 0x00954ec0 (community match, verified in this file)
namespace f3m_00954ec0 {
struct FUN_00954ec0_Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_uiItemCount;
};
struct FUN_00954ec0_cls {
    FUN_00954ec0_Info* m_pObjectInfo;
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    int* m_pEntryData;
    int unk20; int unk24;
    unsigned char m_flag28;
    unsigned char m_flag29;
    void FUN_00954ec0();
};
// pdb: hkaPose::setNonInitializedFlags | hkaPose.obj | fnv360_0822_retail, objrun_open, low
void FUN_00954ec0_cls::FUN_00954ec0() {
    int count = m_pObjectInfo->m_uiItemCount;
    for (int i = 0; i < count; ++i) {
        m_pEntryData[i] = 3;
    }
    m_flag28 = 0;
    m_flag29 = 0;
}
}   // namespace f3m_00954ec0

// @f3 0x0094efa0 (community match, verified in this file)
namespace f3m_0094efa0 {
struct Result874 { int unk00; unsigned int flags04; };
struct Target874 { Result874* FUN_009e34d0(int argument); };
struct Owner874 {
    int unk00, unk04;
    Target874* target08;
    unsigned int FUN_0094efa0(int argument);
};
// pdb: hkpExtendedMeshShape::getCollisionFilterInfo | hkpExtendedMeshShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: key
unsigned int Owner874::FUN_0094efa0(int argument) {
    unsigned int result = 0;
    Target874* target = this ? target08 : 0;
    if (argument != -1) result = target->FUN_009e34d0(argument)->flags04 & 0x1f;
    return result;
}
}   // namespace f3m_0094efa0

// @f3 0x00944a70 (community match, verified in this file)
#include <string.h>
namespace f3m_00944a70 {

namespace f3m_00944a70 {
struct Named
{
    const char* name;
};

struct NamedArray
{
    int unk00;
    int unk04;
    int unk08;
    Named** data;
    unsigned int count;
};

struct StringArray
{
    int unk00;
    int unk04;
    unsigned int count;
    const char** data;

    bool FUN_00944a70(NamedArray* other);
};

// pdb: bhkPoseArray::BoneMatch | bhkPoseArray.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: apSkel
bool StringArray::FUN_00944a70(NamedArray* other)
{
    bool result = true;
    for (unsigned int i = 0; i < other->count && result; i++) {
        const char* name = other->data[i]->name;
        bool found = false;
        for (unsigned int j = 0; j < count && !found; j++) {
            if (strcmp(name, data[j]) == 0)
                found = true;
        }
        if (!found)
            result = false;
    }
    return result;
}
}
}   // namespace f3m_00944a70

// @f3 0x00954ff0 (community match, verified in this file)
namespace f3m_00954ff0 {
struct Owner_954ff0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int count;
};

struct FUN_00954ff0_cls
{
    Owner_954ff0* owner;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int* flags;
    int unk20;
    int unk24;
    bool check28;
    bool check29;

    bool* FUN_00954ff0(bool* result);
};

// pdb: hkaPose::checkPoseValidity | hkaPose.obj | fnv360_0822_retail, objrun_sim, low
bool* FUN_00954ff0_cls::FUN_00954ff0(bool* result)
{
    int count = owner->count;
    int i;
    for (i = 0; i < count; i++) {
        unsigned int v = flags[i];
        if ((v & 1) != 0 && (v & 2) != 0)
            goto fail;
    }
    if (check29) {
        for (i = 0; i < count; i++) {
            if ((flags[i] & 1) != 0)
                goto fail;
        }
    }
    if (check28) {
        for (i = 0; i < count; i++) {
            if ((flags[i] & 2) != 0)
                goto fail;
        }
    }
    *result = true;
    return result;
fail:
    *result = false;
    return result;
}
}   // namespace f3m_00954ff0

// @f3 0x0094b3d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0094b3d0 {

class NiBinaryStreamB3D
{
  public:
    typedef unsigned int (__cdecl *ReadFunction)(NiBinaryStreamB3D* pkThis, char* pcBuffer, unsigned int uiBytes,
        unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    virtual ~NiBinaryStreamB3D();
    unsigned int m_uiAbsoluteCurrentPos;
    ReadFunction m_pfnRead;

    unsigned int Read(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes = 0, unsigned int uiNumComponents = 0)
    {
        unsigned int uiBytesRead = m_pfnRead(this, (char*)pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiAbsoluteCurrentPos += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void NiStreamLoadBinaryB3D(NiBinaryStreamB3D& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.Read(&kValue, uiSize, &uiSize, 1);
}

struct NiStreamB3D
{
    int unk000;
    unsigned int m_uiNifFileVersion;
    int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
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
    int unk1e0;
    unsigned char unk1e4;
    unsigned char m_ucEndian;
    unsigned char unk1e6; unsigned char unk1e7;
    int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248;
    NiBinaryStreamB3D* m_pkIstr;
};

struct hkVector4B3D
{
    float x, y, z, w;
};

struct hkRotationB3D
{
    hkVector4B3D col0, col1, col2;
};

struct hkTransformB3D
{
    hkRotationB3D m_rotation;
    hkVector4B3D m_translation;
};

void __cdecl SwapRotationB3D(hkRotationB3D* pkRotation);

extern "C" void _ReadWriteBarrier(void);
inline void SwapVectorB3D(hkVector4B3D& kVec)
{
    unsigned int* puiData = (unsigned int*)&kVec;
    puiData[0] = _byteswap_ulong(puiData[0]); _ReadWriteBarrier();
    puiData[1] = _byteswap_ulong(puiData[1]); _ReadWriteBarrier();
    puiData[2] = _byteswap_ulong(puiData[2]); _ReadWriteBarrier();
    puiData[3] = _byteswap_ulong(puiData[3]);
}

inline void SwapTransformB3D(hkTransformB3D& kTransform)
{
    SwapVectorB3D(kTransform.m_translation);
    SwapRotationB3D(&kTransform.m_rotation);
}

class hkReferencedObjectB3D
{
  public:
    virtual ~hkReferencedObjectB3D();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            m_referenceCount--;
            if (m_referenceCount == 0)
            {
                delete this;
            }
        }
    }
};

struct ConstraintDataB3D
{
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    hkTransformB3D m_kFrameA;
    hkTransformB3D m_kFrameB;
    unsigned short unk0a0;
    bool m_bMotorEnabled;
    unsigned char unk0a3;
    int unk0a4; int unk0a8; int unk0ac; int unk0b0;
    float m_fB4;
    int unk0b8; int unk0bc; int unk0c0; int unk0c4;
    float m_fC8;
    float m_fCC;
    void SetMotor(hkReferencedObjectB3D* pkMotor);
};

struct ConstraintB3D
{
    int unk000;
    ConstraintDataB3D* m_pData;
    void LoadBinaryBase(NiStreamB3D& kStream);
    hkReferencedObjectB3D* LoadMotor(NiStreamB3D& kStream);
    void FUN_0094b3d0(NiStreamB3D& kStream);
};

// pdb: hkPrismaticConstraintCinfo::LoadBinary | bhkPrismaticConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arStream
void ConstraintB3D::FUN_0094b3d0(NiStreamB3D& kStream)
{
    LoadBinaryBase(kStream);
    ConstraintDataB3D* pData = m_pData;
    kStream.m_pkIstr->Read(&pData->m_kFrameA, 0x40);
    kStream.m_pkIstr->Read(&pData->m_kFrameB, 0x40);
    NiStreamLoadBinaryB3D(*kStream.m_pkIstr, pData->m_fC8);
    NiStreamLoadBinaryB3D(*kStream.m_pkIstr, pData->m_fCC);
    NiStreamLoadBinaryB3D(*kStream.m_pkIstr, pData->m_fB4);
    if (kStream.m_ucEndian != 1)
    {
        SwapTransformB3D(pData->m_kFrameA);
        SwapTransformB3D(pData->m_kFrameB);
    }
    if (kStream.m_uiNifFileVersion > 0x1d)
    {
        hkReferencedObjectB3D* pMotor = LoadMotor(kStream);
        pData->SetMotor(pMotor);
        if (pMotor)
        {
            NiStreamLoadBinaryB3D(*kStream.m_pkIstr, pData->m_bMotorEnabled);
            pMotor->removeReference();
        }
    }
}
}   // namespace f3m_0094b3d0

// @f3 0x009528c0 (community match, verified in this file)
namespace f3m_009528c0 {
namespace f3m_009528c0 {
struct ObjD {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void Notify(int a1);
};
struct ObjC {
    int m_00; int m_04;
    ObjD* m_08;
};
struct Counter {
    virtual void vfn0();
    virtual int vfn1();
};
struct ObjA {
    int m_00; int m_04; int m_08; int m_0C; int m_10;
    Counter m_14;
    int m_18; int m_1C; int m_20; int m_24; int m_28; int m_2C; int m_30; int m_34; int m_38; int m_3C; int m_40;
    ObjC** m_44;
};
struct FUN_009528c0_cls {
    int m_00; int m_04;
    ObjA* m_08;
    void FUN_009528c0(int a1);
};
// pdb: bhkConvexListShape::BuildDisplayGeometry | bhkConvexListShape.obj | fnv360_0721_beta, objrun_open, low, conflict (bridge: bhkConvexListShape::CanShare)
// pdb params: apNode, arDefColor
void FUN_009528c0_cls::FUN_009528c0(int a1) {
    int count;
    ObjA* a0 = (this != 0) ? this->m_08 : 0;
    if (a0 != 0) {
        count = a0->m_14.vfn1();
    } else {
        count = 0;
    }
    int i = 0;
    if (count > 0) {
        do {
            if (this != 0) {
                ObjA* a = this->m_08;
                if (a != 0) {
                    ObjC* c = a->m_44[i];
                    if (c != 0) {
                        ObjD* d = c->m_08;
                        if (d != 0) {
                            d->Notify(a1);
                        }
                    }
                }
            }
            ++i;
        } while (i < count);
    }
}
}
}   // namespace f3m_009528c0

// @f3 0x009479e0 (community match, verified in this file)
namespace f3m_009479e0 {
struct ByteFlag_9479e0
{
    char value;
    ByteFlag_9479e0(bool v) : value(v) {}
    ByteFlag_9479e0(const ByteFlag_9479e0& o) : value(o.value) {}
};

struct ShortPair_9479e0
{
    int first;
    int second;
};

struct RefObj_9479e0
{
    virtual void Destroy(bool free);
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14(ByteFlag_9479e0 flag, ShortPair_9479e0* out);
    short active;
    short refCount;

    void IncRef()
    {
        if (active)
            ++refCount;
    }
    void DecRef()
    {
        if (active)
        {
            --refCount;
            if (refCount == 0)
                Destroy(true);
        }
    }
};

struct Sub_9479e0
{
    void hkpBridgeConstraintAtom_init(void* owner);
};

struct Class_9479e0
{
    int unk00;
    int unk04;
    int unk08;
    Sub_9479e0 subobject;
    int unk10;
    int unk14;
    RefObj_9479e0* owner;
    unsigned short state;
    unsigned short substate;
    void FUN_009479e0(RefObj_9479e0* apOwner);
};

// pdb: ahkpBreakableConstraintData::SetChild | bhkBreakableConstraint.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apData
void Class_9479e0::FUN_009479e0(RefObj_9479e0* apOwner)
{
    if (apOwner)
        apOwner->IncRef();
    if (owner)
        owner->DecRef();
    owner = apOwner;
    ShortPair_9479e0 result;
    owner->vf14(ByteFlag_9479e0(true), &result);
    state = (unsigned short)result.first;
    substate = (unsigned short)result.second;
    subobject.hkpBridgeConstraintAtom_init(this);
}
}   // namespace f3m_009479e0

// @f3 0x00941bf0 (community match, verified in this file)
namespace f3m_00941bf0 {
struct Lookup954 {
    int unk00, unk04, unk08, unk0C;
    int FUN_009b10f0(int first, int last);
};
struct Dispatch954 {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual int Slot10(int value);
};
struct Owner954 {
    int unk00, unk04;
    Lookup954 lookup08;
    Dispatch954* receiver18;
    int FUN_00941bf0(int key);
};
// pdb: hkCpuJobThreadPool::SharedThreadData::SharedThreadData | hkCpuJobThreadPool.obj | fnv360_0822_retail, objrun_open, low
int Owner954::FUN_00941bf0(int key) {
    int value = lookup08.FUN_009b10f0(key, key);
    if (receiver18) return receiver18->Slot10(value);
    return 0;
}
}   // namespace f3m_00941bf0

// @f3 0x00954f90 (community match, verified in this file)
namespace f3m_00954f90 {
struct StateResetSource { int unk00, unk04, unk08, unk0C, m_iArrayLength; };
struct StateResetPart { int unk00; };
struct StateResetTarget {
    StateResetSource* m_pSource;
    StateResetPart m_kPart;
    int unk08, unk0C, unk10, unk14, unk18;
    int* m_piStates;
    int unk20, unk24;
    bool m_bFlag28, m_bFlag29;
    StateResetPart* FUN_00954f90();
};
// pdb: hkaPose::accessUnsyncedPoseLocalSpace | hkaPose.obj | fnv360_0822_retail, objrun_open, low
StateResetPart* StateResetTarget::FUN_00954f90()
{
    int iCount = m_pSource->m_iArrayLength;
    for (int i = 0; i < iCount; ++i)
        m_piStates[i] = 2;
    m_bFlag28 = false;
    m_bFlag29 = true;
    return &m_kPart;
}
}   // namespace f3m_00954f90

// @f3 0x009454b0 (community match, verified in this file)
namespace f3m_009454b0 {
void NiFree(void* p);

namespace f3m_009454b0 {

struct ArrM
{
    void* data04;
    int unk08;
    int unk0C;
    void FUN_00945270();
    virtual ~ArrM();
};

inline ArrM::~ArrM()
{
    void* p = data04;
    NiFree(p);
}

struct BaseM
{
    int unk04;
    int unk08;
    virtual ~BaseM();
};

struct FUN_009454b0 : BaseM
{
    ArrM arr0C;
    virtual ~FUN_009454b0();
};

FUN_009454b0::~FUN_009454b0()
{
    arr0C.FUN_00945270();
}
}
}   // namespace f3m_009454b0

// @f3 0x009543b0 (community match, verified in this file)
namespace f3m_009543b0 {
struct Event987;
struct Owner987 { void FUN_00953330(Event987* event); };
struct Object987 {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0C();
    virtual int GetType();
};
struct Event987 { int unk00, unk04, unk08; Object987* object0C; };
struct Primary987 { Owner987* owner00;
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
};
struct Host987;
struct Sub987 { int unk00; void FUN_009543b0(Event987* event); };
struct Host987 : Primary987, Sub987 {};
// pdb: hkpPhysicsContext::constraintRemovedCallback | hkpPhysicsContext.obj | fnv360_0822_debug, objrun, medium
// pdb params: constraint
void Sub987::FUN_009543b0(Event987* event) {
    Host987& host = *reinterpret_cast<Host987*>(reinterpret_cast<char*>(this) - 0x58);
    if (host.owner00) {
        Object987* object = event->object0C;
        if (object && object->GetType() != 11) host.owner00->FUN_00953330(event);
    }
}
}   // namespace f3m_009543b0

// @f3 0x009465d0 (community match, verified in this file)
namespace f3m_009465d0 {
struct Quat {
    float x, y, z, w;
    Quat& operator=(const Quat& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
extern Quat DAT_01092a50;
struct Data {
    int unk00[8];
    Quat pivot;
    float fMin;
    float fMax;
};
struct Info {
    int unk00[4];
    Quat m_kPivot;
    float m_fMinimum;
    float m_fMaximum;
    bool m_bStreamFlag;
};
struct Base {
    void FUN_008f8840(Info* pkInfo);
};
struct Constraint : Base {
    int unk00;
    int unk04;
    Data* unk08;
    void FUN_009465d0(Info* pkInfo);
};
static inline const Quat& GetPivot(Constraint* p) {
    if (p && p->unk08) return p->unk08->pivot;
    return DAT_01092a50;
}
static inline float GetMax(Constraint* p) {
    if (p && p->unk08) return p->unk08->fMax;
    return 0.0f;
}
static inline float GetMin(Constraint* p) {
    if (p && p->unk08) return p->unk08->fMin;
    return 0.0f;
}
// pdb: bhkMotorAction::`scalar deleting destructor' | bhkMotorAction.obj | fnv360_0721_beta, objrun, low
void Constraint::FUN_009465d0(Info* pkInfo) {
    FUN_008f8840(pkInfo);
    pkInfo->m_bStreamFlag = true;
    pkInfo->m_kPivot = GetPivot(this);
    pkInfo->m_fMaximum = GetMax(this);
    pkInfo->m_fMinimum = GetMin(this);
}
}

// @f3 0x00952530 (community match, verified in this file)
namespace f3m_00952530 {
void __cdecl FUN_00901e90(void* arr, int capacity, int stride);

namespace f3m_00952530 {
struct Arr {
    void** data;
    int size;
    int capacityAndFlags;
    void reserve(int n)
    {
        int cap = capacityAndFlags & 0x3fffffff;
        if (cap < n) {
            int c2 = cap * 2;
            FUN_00901e90(this, n < c2 ? c2 : n, 4);
        }
    }
    void resize(int n) { reserve(n); size = n; }
};
struct Out {
    int unk00;
    int unk04;
    unsigned char m08;
    float m0c;
    Arr m10;
};
struct Iter {
    virtual void v00();
    virtual int Count();
    virtual void* First();
    virtual void* Next(void* it);
};
struct Impl {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    Iter m14;
    float m18;
    int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;
    int unk34; int unk38; int unk3c; int unk40;
    void** m44;
    unsigned char FUN_009edad0();
};
}
using namespace f3m_00952530;

struct FUN_00952530_cls {
    int unk00;
    int unk04;
    Impl* m08;
    void FUN_0090c4a0(Out* out);
    float GetF() { return (this && m08) ? m08->m18 : 0.0f; }
    int GetB() { return (this && m08) ? m08->FUN_009edad0() : 0; }
    int GetCount() { if (this) { Impl* p = m08; if (p) return p->m14.Count(); } return 0; }
    void* GetFirst() { if (this) { Impl* p = m08; if (p) return p->m14.First(); } return 0; }
    void* GetNext(void* it) { if (this) { Impl* p = m08; if (p) return p->m14.Next(it); } return 0; }
    void* GetAt(unsigned int i) { return (this && m08) ? m08->m44[i] : 0; }
    void FUN_00952530(Out* out);
};

// pdb: bhkConvexListShape::CopyCinfo | bhkConvexListShape.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arInfo
void FUN_00952530_cls::FUN_00952530(Out* out)
{
    FUN_0090c4a0(out);
    out->m0c = GetF();
    out->m08 = GetB();
    int n = GetCount();
    out->m10.size = 0;
    out->m10.resize(n);
    void* it = GetFirst();
    for (unsigned int i = 0; i < (unsigned int)n; i++) {
        out->m10.data[i] = GetAt(i);
        it = GetNext(it);
    }
}
}   // namespace f3m_00952530

// @f3 0x00946080 (community match, verified in this file)
namespace f3m_00946080 {
namespace f3m_00946080 {
struct Vec4 {
    float x, y, z, w;
    Vec4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
};
struct Result {
    int unk00, unk04, unk08, unk0C;
    Vec4 m_kPointA;
    Vec4 m_kPointB;
};
struct Argument {
    int unk00, unk04, unk08, unk0C;
    float m_f10;
};
class Base946080 {
public:
    virtual void v00();
    void FUN_008fb680(void* arg1, Argument* apArgument);
};
class Shape946080 : public Base946080 {
public:
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0();
    virtual Result* vB4(char* out);
    void FUN_00946080(void* arg1, Argument* apArgument);
};
// pdb: bhkDashpotAction::CopyMembers | bhkDashpotAction.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apDest, arCloneData
void Shape946080::FUN_00946080(void* arg1, Argument* apArgument)
{
    char local;
    Result* result = vB4(&local);
    if (result) {
        float scale = apArgument->m_f10;
        if (scale != 1.0f) {
            result->m_kPointA *= scale;
            result->m_kPointB *= scale;
        }
    }
    FUN_008fb680(arg1, apArgument);
}
}
}   // namespace f3m_00946080

// @f3 0x0094ebf0 (community match, verified in this file)
namespace f3m_0094ebf0 {
class Heap_ebf0
{
public:
    void* FUN_0086b930(unsigned int bytes);
};
extern Heap_ebf0 DAT_01090a78;

struct Child_ebf0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float f10; float f14; float f18; float f1C;
    float f20; float f24; float f28; float f2C;
    float f30; float f34; float f38; float f3C;
    Child_ebf0()
    {
        unk00 = 0;
        f10 = 0.0f; f14 = 0.0f; f18 = 0.0f; f1C = 0.0f;
        f20 = 0.0f; f24 = 0.0f; f28 = 0.0f; f2C = 0.0f;
        f30 = 0.0f; f34 = 0.0f; f38 = 0.0f; f3C = 0.0f;
    }
};

inline void* AlignedAlloc_ebf0(unsigned int size)
{
    unsigned char* memory = (unsigned char*)DAT_01090a78.FUN_0086b930(size + 16);
    unsigned char pad = (unsigned char)(16 - ((unsigned char)(unsigned int)memory & 0xf));
    memory += pad;
    memory[-1] = pad;
    return memory;
}
}

inline void* operator new(unsigned int, void* p, int) { return p; }

class FUN_0094ebf0_Owner {
public:
    int unk00;
    int unk04;
    int parent08;
    f3m_0094ebf0::Child_ebf0* child0C;
    void FUN_0094e610(f3m_0094ebf0::Child_ebf0* c);
    f3m_0094ebf0::Child_ebf0* FUN_0094ebf0(bool* pbCreated);
};

f3m_0094ebf0::Child_ebf0* FUN_0094ebf0_Owner::FUN_0094ebf0(bool* pbCreated)
{
    if (!child0C) {
        child0C = new (f3m_0094ebf0::AlignedAlloc_ebf0(0x40), 0) f3m_0094ebf0::Child_ebf0();
        if (parent08)
            FUN_0094e610(child0C);
        *pbCreated = true;
    } else {
        *pbCreated = false;
    }
    return child0C;
}

// @f3 0x0094c360 (community match, verified in this file)
namespace f3m_0094c360 {
struct FUN_0094c360_data {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    float unk30, unk34, unk38;
    int unk3c;
    float unk40, unk44, unk48;
    int unk4c;
    float unk50, unk54, unk58;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    float unk84, unk88;
};

struct ListW {
    int unk00;
    int unk04;
    unsigned short cap;
    unsigned short count;
    unsigned short unk0c;
    unsigned short growBy;
    void Grow(unsigned int newCount);
    void Insert(unsigned int index, void** value);
};

struct Vec3 {
    float x, y, z;
    void* MakeNamed(const char* name);
};

void* FloatNamed(const char* name, float f);

struct FUN_0094c360_cls {
    int unk00;
    FUN_0094c360_data* m_pData;
    void Prep(ListW* arr);
    void FUN_0094c360(ListW* arr);
};

static void Append(ListW* arr, void* value)
{
    unsigned int n = arr->count;
    if (n >= arr->cap) {
        arr->Grow(n + arr->growBy);
    }
    arr->Insert(n, &value);
}

// pdb: hkHingeLimitsConstraintCinfo::GetViewerStrings | bhkHingeLimitsConstraint.obj | fnv360_0822_retail, strset, low
// pdb params: apStrings
void FUN_0094c360_cls::FUN_0094c360(ListW* arr)
{
    Prep(arr);
    FUN_0094c360_data* d = m_pData;
    if (d == 0) {
        return;
    }
    Vec3 v;
    v.x = d->unk50;
    v.y = d->unk54;
    v.z = d->unk58;
    Append(arr, v.MakeNamed("AxleInB"));

    v.x = d->unk30;
    v.y = d->unk34;
    v.z = d->unk38;
    Append(arr, v.MakeNamed("Perp2AxleInA1"));

    v.x = d->unk40;
    v.y = d->unk44;
    v.z = d->unk48;
    Append(arr, v.MakeNamed("Perp2AxleInA2"));

    Append(arr, FloatNamed("MinAngle", d->unk84));
    Append(arr, FloatNamed("MaxAngle", d->unk88));
}
}   // namespace f3m_0094c360

// @f3 0x0094da70 (community match, verified in this file)
namespace f3m_0094da70 {
struct Target {
    virtual void Release(int flags);
    unsigned short unk04;
    short unk06;
};

struct Ref {
    int unk00;
    int unk04;
    Target* unk08;
};

struct Owner {
    void FUN_008f7f20(Ref* r);
    void FUN_0094da70(Ref* r);
};

// pdb: bhkMoppBvTreeShape::RegisterStreamables | bhkMoppBvTreeShape.obj | fnv360_0822_debug, objrun, low
// pdb params: arStream
void Owner::FUN_0094da70(Ref* r)
{
    Target* t = r->unk08;
    if (t != 0 && t->unk04 != 0) {
        t->unk06 -= 1;
        if (t->unk06 == 0)
            t->Release(1);
    }
    FUN_008f7f20(r);
}
}   // namespace f3m_0094da70

// @f3 0x00954ef0 (community match, verified in this file)
namespace f3m_00954ef0 {
struct FUN_00954ef0_owner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    void* m_pPool;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int* m_pData;
    unsigned int unk20;
    unsigned int unk24;
    volatile unsigned char unk28;
    unsigned char unk29;

    void FUN_00954ef0(const int& a);
};

void FUN_009234e0(void* pool, int a, unsigned int size);

// pdb: hkaPose::setPoseLocalSpace | hkaPose.obj | fnv360_0822_retail, objrun_open, low
// pdb params: poseLocal
void FUN_00954ef0_owner::FUN_00954ef0(const int& a)
{
    int* vt = *(int**)this;
    int n = vt[4];
    FUN_009234e0(m_pPool, a, n * 48);
    for (int i = 0; i < n; i++) {
        m_pData[i] = 2;
    }
    unk28 = 0;
    unk29 = 1;
}
}   // namespace f3m_00954ef0

// @f3 0x009476b0 (community match, verified in this file)
struct V4f { float x; float y; float z; float w; };

extern V4f DAT_012683b0;

struct C009476b0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;

    C009476b0* FUN_009476b0();
};

// pdb: bhkAngularDashpotAction::CreateCinfo | bhkAngularDashpotAction.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: arCreated
C009476b0* C009476b0::FUN_009476b0()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    float* pf = &f10;
    pf[0] = 0.0f;
    pf[1] = 0.0f;
    pf[2] = 0.0f;
    pf[3] = 0.0f;
    f10 = DAT_012683b0.x;
    f14 = DAT_012683b0.y;
    f18 = DAT_012683b0.z;
    f1c = DAT_012683b0.w;
    f20 = 0.1f;
    f24 = 0.01f;
    return this;
}

// @f3 0x00950ba0 (community match, verified in this file)
extern float DAT_010c72bc;
namespace f3m_00950ba0 {
struct NiStream;

struct Vector3
{
    float x;
    float y;
    float z;
};


void __cdecl FUN_00cf0930(void* pvData, int iShape, Vector3* pkVector);
void __cdecl FUN_009799c0(NiStream* pkStream, Vector3* pkVector);

struct NiStreamBlock
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
    int unk3C;
};

struct NiStream
{
    NiStreamBlock u000;
    NiStreamBlock u040;
    NiStreamBlock u080;
    NiStreamBlock u0C0;
    NiStreamBlock u100;
    NiStreamBlock u140;
    NiStreamBlock u180;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    char unk1E4;
    unsigned char m_ucPlatform;
};

struct CCDDE0Data
{
    int unk00;
    float m_fScale;
    Vector3 m_kMin;
    Vector3 m_kMax;
};

class CCDDE0Object
{
public:
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
    virtual void v1F();
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
    virtual void* GetShape();
    virtual void v2B();
    virtual void v2C();
    virtual void* GetData(unsigned int* puiSize);
    void FUN_00c9fbc0(NiStream* pkStream);
    void FUN_00950ba0(NiStream* pkStream);
};

// pdb: bhkConvexVerticesShape::LoadBinary | bhkConvexVerticesShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void CCDDE0Object::FUN_00950ba0(NiStream* pkStream)
{
    FUN_00c9fbc0(pkStream);
    unsigned int uiSize;
    CCDDE0Data* pkData = (CCDDE0Data*)GetData(&uiSize);
    if (pkData)
    {
        pkData->m_fScale = DAT_010c72bc;
        if (pkStream->m_ucPlatform != 1)
        {
            void* pkShape = GetShape();
            FUN_00cf0930(pkData, (int)pkShape, &pkData->m_kMin);
            FUN_00cf0930(pkData, (int)pkShape, &pkData->m_kMax);
        }
        FUN_009799c0(pkStream, &pkData->m_kMin);
        FUN_009799c0(pkStream, &pkData->m_kMax);
    }
}
}   // namespace f3m_00950ba0

// @f3 0x00951170 (community match, verified in this file)
// FUN_00951170 -- owner of one lazily created child object.
// The allocation goes through the game's global memory manager.

class MemoryManager
{
public:
    void* Allocate(unsigned int uiSize);
};

extern MemoryManager _g_memoryManager;
extern float DAT_010c72bc;

class CChildNode
{
public:
    int          unk00;   // 0x00
    float        unk04;   // 0x04
    void*        unk08;   // 0x08
    void*        unk0C;   // 0x0C
    unsigned int unk10;   // 0x10
    void*        unk14;   // 0x14
    void*        unk18;   // 0x18
    unsigned int unk1C;   // 0x1C

    static void* operator new(unsigned int uiSize) { return _g_memoryManager.Allocate(uiSize); }
    static void operator delete(void*) {}

    CChildNode();
};

extern "C" void _ReadWriteBarrier(void);

CChildNode::CChildNode()
{
    unk00 = 0;
    unk04 = DAT_010c72bc;
    _ReadWriteBarrier();
    const unsigned int nInvalid = 0x80000000;
    unk08 = 0;
    unk0C = 0;
    unk10 = nInvalid;
    unk14 = 0;
    unk18 = 0;
    unk1C = nInvalid;
}

class CChildOwner
{
public:
    int          unk00;   // 0x00
    int          unk04;   // 0x04
    void*        unk08;   // 0x08, parent/attachment
    CChildNode*  unk0C;   // 0x0C, lazily created child

    void FUN_00950fe0(CChildNode* pkChild);
    CChildNode* FUN_00951170(bool* pbCreated);
};

// pdb: hkConvexVerticesShapeCinfo::~hkConvexVerticesShapeCinfo | bhkConvexVerticesShape.obj | fnv360_0721_beta, objrun_sim, low
CChildNode* CChildOwner::FUN_00951170(bool* pbCreated)
{
    if (!unk0C)
    {
        CChildNode* pkChild = new CChildNode;
        unk0C = pkChild;
        if (unk08)
            FUN_00950fe0(pkChild);
        *pbCreated = true;
        return unk0C;
    }
    *pbCreated = false;
    return unk0C;
}

// @f3 0x00943bb0 (community match, verified in this file)
namespace f3m_00943bb0 {

class hkBaseObject
{
  public:
    virtual void hkBaseObject_dtor();
};

struct hkArrayChar
{
    char* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    void reserve(int n);
};

void FUN_00901e90(hkArrayChar* arr, int newCapacity, int elementSize);

void hkArrayChar::reserve(int n)
{
    if (getCapacity() < n)
    {
        int newCapacity = getCapacity() * 2;
        if (n < newCapacity)
            n = newCapacity;
        FUN_00901e90(this, n, 1);
    }
}

class hkStreamWriter
{
  public:
    virtual void hkStreamWriter_vf();
    unsigned short m_us04;
    unsigned short m_us06;
    hkStreamWriter() : m_us06(1) {}
};

class FUN_00943bb0 : public hkStreamWriter
{
  public:
    hkArrayChar* m_buffer;
    int m_size;
    int m_owner;
    FUN_00943bb0(hkArrayChar* buffer, int flags);
    virtual ~FUN_00943bb0();
};

// pdb: hkArrayStreamWriter::nullTerminate | hkOStream.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkArrayStreamWriter::hkArrayStreamWriter)
FUN_00943bb0::FUN_00943bb0(hkArrayChar* buffer, int flags)
    : m_buffer(buffer), m_size(buffer->m_size), m_owner(flags)
{
    int n = m_buffer->m_size + 1;
    int cap = m_buffer->getCapacity();
    if (cap < n)
    {
        cap *= 2;
        if (n < cap) n = cap;
        FUN_00901e90(m_buffer, n, 1);
    }
    m_buffer->m_data[m_buffer->m_size] = 0;
}
}   // namespace f3m_00943bb0

// @f3 0x0095bac0 (community match, verified in this file)
struct Quad4 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};

extern Quad4 DAT_01092a50;
extern float DAT_00e08fe4;
extern float DAT_00db9254;
extern float DAT_00db38b8;
extern float DAT_00dbe1e0;
extern float DAT_00de20b0;

struct Cls0095bac0 {
    unsigned int unk00;
    short unk04;
    short unk06;
    short unk08;
    unsigned int unk0c;
    Quad4 q[4];
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    unsigned char unk74;

    Cls0095bac0* FUN_0095bac0();
};

// pdb: hkaFootPlacementIkSolver::Setup::Setup | hkaFootPlacementIkSolver.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
Cls0095bac0* Cls0095bac0::FUN_0095bac0()
{
    unk00 = 0;
    int neg = -1;
    unk04 = (short)neg;
    unk06 = (short)neg;
    unk08 = (short)neg;
    q[0] = DAT_01092a50;
    q[1] = DAT_01092a50;
    q[2] = DAT_01092a50;
    q[3].x = DAT_01092a50.x;
    q[3].y = DAT_01092a50.y;
    q[3].z = DAT_01092a50.z;
    q[3].w = DAT_01092a50.w;
    unk58 = unk54 = unk50 = 0.0f;
    unk5c = DAT_00db9254;
    unk60 = DAT_00e08fe4;
    unk64 = DAT_00db38b8;
    unk68 = 1.0f;
    unk6c = DAT_00dbe1e0;
    unk70 = DAT_00de20b0;
    *(volatile unsigned char*)&unk74 = 0;
    return this;
}

// @f3 0x0095aac0 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern float DAT_00dbe8fc;
extern float DAT_00db8d0c;
namespace f3m_0095aac0 {
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct ProfRec { const char* m_pName; unsigned int m_iTick; unsigned int unk08; };
struct ProfBuf { unsigned int unk00; ProfRec* m_pCur; unsigned int unk08; ProfRec* m_pEnd; };

struct FreeNode { FreeNode* m_pNext; };
struct NodePool {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    FreeNode* m_pFree;
    int m_nFree;
};

void* __stdcall FUN_008f6800(unsigned int a, unsigned int b);

struct Effect {
    unsigned short m_type;
    unsigned int unk04, unk08, unk0C;
    unsigned short unk10;
    unsigned int unk14, unk18, unk1C;
    float m_f20;
    float m_f24;
    unsigned int unk28;
    static void* operator new(unsigned int) {
        NodePool* pool = (NodePool*)TlsGetValue(DAT_010f3170);
        void* r = pool->m_pFree;
        if (r) {
            pool->m_nFree--;
            pool->m_pFree = *(FreeNode**)r;
        } else {
            r = FUN_008f6800(4, 0x2c);
        }
        return r;
    }
    Effect() {
        m_f20 = DAT_00dbe8fc;
        m_type = 0x17;
        unk10 = 0x30;
        m_f24 = DAT_00db8d0c;
    }
};

struct Holder { int unk; };
struct Target {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
};
struct Owner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual Holder* v40();
};

Effect* __cdecl FUN_009a94f0(Holder* h, int type);
void __cdecl FUN_009a9550(Holder* h, Target* t, Effect* e);
// pdb: hkpResponseModifier::setImpulseScalingForContact | hkpResponseModifier.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
void __cdecl hkpResponseModifier_setImpulseScalingForContact(Owner* a1, int a2, int a3, Target* a4, float f1, float f2)
{
    volatile unsigned int ticks;
    Holder* h = a1->v40();
    if (h) {
        a4->v18();
        ProfBuf* pb = (ProfBuf*)TlsGetValue(DAT_0116913c);
        ProfRec* r = pb->m_pCur;
        if (r < pb->m_pEnd) {
            r->m_pName = "TtSetSoftContact";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            r->m_iTick = ticks;
            pb->m_pCur = r + 1;
        }
        Effect* e = FUN_009a94f0(h, 0x17);
        if (e) {
            e->m_f20 = f1;
            e->m_f24 = f2;
        } else {
            e = new Effect;
            e->m_f20 = f1;
            e->m_f24 = f2;
            FUN_009a9550(h, a4, e);
        }
        pb = (ProfBuf*)TlsGetValue(DAT_0116913c);
        ProfRec* r2 = pb->m_pCur;
        if (r2 < pb->m_pEnd) {
            r2->m_pName = "Et";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            r2->m_iTick = ticks;
            pb->m_pCur = r2 + 1;
        }
    }
}
}   // namespace f3m_0095aac0

// @f3 0x00952ca0 (community match, verified in this file)
struct Alloc_01090a78 {
    void* FUN_0086b930(unsigned int size);
};
extern Alloc_01090a78 DAT_01090a78;

extern float DAT_00f7a690;

struct Obj1C {
    int unk00;
    float unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int unk18;
    Obj1C();
    static void* operator new(unsigned int n) throw() { return DAT_01090a78.FUN_0086b930(n); }
};

Obj1C::Obj1C() : unk00(0), unk04(DAT_00f7a690), unk10(0), unk14(0), unk18(0x80000000)
{
}

struct Owner952 {
    int unk00;
    int unk04;
    int unk08;
    Obj1C* unk0C;
    void FUN_00952530(Obj1C* p);
    Obj1C* FUN_00952ca0(unsigned char* out);
};

// pdb: bhkConvexListShape::CreateCinfo | bhkConvexListShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arCreated
Obj1C* Owner952::FUN_00952ca0(unsigned char* out)
{
    if (unk0C == 0) {
        Obj1C* p = new Obj1C();
        unk0C = p;
        if (unk08 != 0) {
            FUN_00952530(p);
        }
        *out = 1;
        return unk0C;
    }
    *out = 0;
    return unk0C;
}

// @f3 0x009462c0 (community match, verified in this file)
namespace f3m_009462c0 {
struct FUN_009462c0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    bool unk3c;
    bool unk3d;
    FUN_009462c0_cls* FUN_009462c0();
};

// pdb: bhkSpringAction::CreateCinfo | bhkSpringAction.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: arCreated
FUN_009462c0_cls* FUN_009462c0_cls::FUN_009462c0()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    *(volatile float*)&unk10 = 0.0f;
    *(volatile float*)&unk14 = 0.0f;
    *(volatile float*)&unk18 = 0.0f;
    *(volatile float*)&unk1c = 0.0f;
    *(volatile float*)&unk20 = 0.0f;
    *(volatile float*)&unk24 = 0.0f;
    *(volatile float*)&unk28 = 0.0f;
    *(volatile float*)&unk2c = 0.0f;
    *(volatile float*)&unk10 = 0.0f;
    *(volatile float*)&unk14 = 0.0f;
    *(volatile float*)&unk18 = 0.0f;
    *(volatile float*)&unk1c = 0.0f;
    *(volatile float*)&unk20 = 0.0f;
    *(volatile float*)&unk24 = 0.0f;
    *(volatile float*)&unk28 = 0.0f;
    *(volatile float*)&unk2c = 0.0f;
    unk30 = 1.0f;
    unk34 = 1000.0f;
    unk38 = 0.1f;
    *(volatile bool*)&unk3c = true;
    *(volatile bool*)&unk3d = true;
    return this;
}
}   // namespace f3m_009462c0

// @f3 0x00957ad0 (community match, verified in this file)
namespace f3m_00957ad0 {
struct Item { int unk00; unsigned char unk04; };
struct Table { int unk00; short* unk04; int unk08; Item** unk0C; int unk10; };
// pdb: hkaSkeletonUtils::lockTranslations | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkaSkeletonUtils::enforceSkeletonConstraintsLocalSpace)
// pdb params: skeleton, exceptRoots
void FUN_00957ad0(Table* t, unsigned char flag)
{
    int n = t->unk10;
    for (int i = 0; i < n; ++i) {
        short* w = t->unk04;
        Item* it = t->unk0C[i];
        if (w[i] > 0 || flag == 0) {
            it->unk04 = 1;
        }
    }
}
}   // namespace f3m_00957ad0

// @f3 0x00953410 (community match, verified in this file)
struct Logger {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void v03(int a, int b, const char* c, const char* d, int e) throw();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void v07(int a, const char* b) throw();
    virtual int v08() throw();
};
extern Logger* DAT_010f3364;
struct StrBuf {
    int unk0, unk4, unk8;
    void FUN_00923070(char* buf, int size);
    void FUN_00943710(const char* s);
    void FUN_00943a60();
};
struct Obj {
    int unk00, unk04;
    struct Dtor { virtual void Destroy(int f) throw(); } *unk08;
    int unk0c;
    int unk10;
    void FUN_009530f0(int i, float f) throw();
    void hkVisualDebugger_deleteClient(int i) throw();
    int FUN_00953410();
};
static void Log(const char* msg, int line)
{
    unsigned int buf[0x80];
    StrBuf sb;
    sb.FUN_00923070((char*)buf, 0x200);
    sb.FUN_00943710(msg);
    DAT_010f3364->v03(0, -1, (const char*)buf, ".\\hkVisualDebugger.cpp", line);
    sb.FUN_00943a60();
}
// pdb: hkVisualDebugger::shutdown | hkVisualDebugger.obj | fnv360_0822_retail, ustr, medium
int Obj::FUN_00953410()
{
    DAT_010f3364->v07(0x1293adef, "Shuting down Visual Debugger..");
    for (int i = unk10 - 1; i >= 0; i--) {
        FUN_009530f0(i, 0.0f);
        hkVisualDebugger_deleteClient(i);
        Log("Client deleted.", 0x55);
    }
    if (unk08) {
        unk08->Destroy(1);
        unk08 = 0;
        Log("Server deleted.", 0x5c);
    }
    return DAT_010f3364->v08();
}

// @f3 0x00955070 (community match, verified in this file)
#include <intrin.h>
namespace f3m_00955070 {

struct A {
    char unk00[0x10];
    int count;          // 0x10
    void* src;          // 0x14
    int unk18;          // 0x18
    int unk1c;          // 0x1C
    int n34;            // 0x20
};

struct S {
    A* a;               // 0x00
    void* p04;          // 0x04
    char pad08[0x14];   // 0x08 .. 0x1B
    int* arr1c;         // 0x1C
    char pad20[0x08];   // 0x20 .. 0x27
    unsigned char b28;  // 0x28
    unsigned char b29;  // 0x29
    char pad2a[0x02];   // 0x2A .. 0x2B
    float* arr2c;       // 0x2C

    int FUN_00955070();
};

extern "C" void FUN_00cb1260(void* dst, const void* src, unsigned int n);

// pdb: hkaPose::setToReferencePose | hkaPose.obj | fnv360_0822_retail, call_gap_sim, low
int S::FUN_00955070() {
    FUN_00cb1260(this->p04, this->a->src, this->a->count * 0x30);
    int i = 0;
    for (; i < this->a->count; ++i)
        this->arr1c[i] = 2;
    this->b28 = 0;
    this->b29 = 1;
    _ReadWriteBarrier();
    A* a = this->a;
    int result = 0;
    if (a->n34 > 0) {
        float* f = this->arr2c;
        do {
            *f = 0.0f;
            ++result;
            ++f;
        } while (result < a->n34);
    }
    return result;
}
}   // namespace f3m_00955070

// @f3 0x00946a90 (community match, verified in this file)
extern void* DAT_0116916c;
extern char DAT_00e7a5b0;
namespace f3m_00946a90 {
// FUN_00946a90: thiscall (Owner*), one stack param (Args*), ret 4.
struct Sub {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    float unk30;
    float unk34;
};

struct Args {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
    void FUN_00555790(unsigned int n);
    void FUN_005b3880(unsigned int idx, Sub** out);
};

struct Owner {
    int unk00;
    int unk04;
    Sub* unk08;
    void FUN_008f8bb0(Args* a);
    void FUN_00946a90(Args* a);
};

extern "C" void FUN_00e2e78c();
extern "C" Sub* __cdecl FUN_00847b50(void* p);
extern "C" Sub* __cdecl FUN_00847dd0(void* name, float v);

// pdb: bhkMotorAction::GetViewerStrings | bhkMotorAction.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Owner::FUN_00946a90(Args* a) {
    FUN_008f8bb0(a);
    union { Sub* p; float f; } u;
    u.p = FUN_00847b50(DAT_0116916c);
    unsigned int idx = a->unk0a;
    if (idx >= a->unk08) {
        a->FUN_00555790(idx + a->unk0e);
    }
    a->FUN_005b3880(idx, &u.p);
    if (this != 0 && this->unk08 != 0) {
        u.f = this->unk08->unk30;
    } else {
        u.f = 0.0f;
    }
    u.p = FUN_00847dd0(&DAT_00e7a5b0, u.f);

    idx = a->unk0a;
    if (idx >= a->unk08) {
        a->FUN_00555790(idx + a->unk0e);
    }
    a->FUN_005b3880(idx, &u.p);
    if (this != 0 && this->unk08 != 0) {
        u.f = this->unk08->unk34;
    } else {
        u.f = 0.0f;
    }
    u.p = FUN_00847dd0((void*)FUN_00e2e78c, u.f);

    idx = a->unk0a;
    if (idx >= a->unk08) {
        a->FUN_00555790(idx + a->unk0e);
    }
    a->FUN_005b3880(idx, &u.p);
}
}   // namespace f3m_00946a90

// @f3 0x0094f840 (community match, verified in this file)
namespace f3m_0094f840 {

struct NiBinaryStream {
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

struct NiStream {
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
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    NiBinaryStream* m_pBackingStream;
};

template <class T>
inline void NiBinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

struct Sub10 {
    unsigned int a;
    unsigned int b;
};

struct FUN_0094f840_Class {
    unsigned int unk00;
    float* unk04;
    unsigned int unk08;
    unsigned short* unk0C;
    Sub10* unk10;

    void FUN_0094f840(NiStream& kStream);
};

// pdb: bhkExtendedMeshSubPart::SaveBinary | bhkExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arStream
void FUN_0094f840_Class::FUN_0094f840(NiStream& kStream)
{
    NiBinaryStreamSave(*kStream.m_pBackingStream, &unk00, 1);
    NiBinaryStreamSave(*kStream.m_pBackingStream, unk04, unk00 * 3);
    NiBinaryStreamSave(*kStream.m_pBackingStream, &unk08, 1);
    NiBinaryStreamSave(*kStream.m_pBackingStream, unk0C, unk08 * 3);
    NiBinaryStreamSave(*kStream.m_pBackingStream, &unk10->a, 1);
    unsigned int b = unk10->b;
    NiBinaryStreamSave(*kStream.m_pBackingStream, &b, 1);
}
}   // namespace f3m_0094f840

// @f3 0x0095a690 (community match, verified in this file)
namespace f3m_0095a690 {
// Based on the starting_draft with 100% similarity
// The function signature is: void __thiscall hkpRagdollConstraintData_setMotorsActive(int a, char b)
// with __thiscall (this in ecx), callee pops 8 bytes (2 stack parameters)

// Create a simple class that has this member function
struct FUN_0095a690_Class {
    void __thiscall hkpRagdollConstraintData_setMotorsActive(int a, char b);
};

// pdb: hkpRagdollConstraintData::setMotorsActive | hkpRagdollConstraintData.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_gap) + skyrim(call_gap_sim), high
void __thiscall FUN_0095a690_Class::hkpRagdollConstraintData_setMotorsActive(int a, char b)
{
    // Exact implementation from starting_draft with 100% similarity:
    ((char*)this)[0xa2] = (char)b;
    ((char*)this)[0xf2] = (char)!b;
    if (a && *(int*)(a + 0x28) && *(int*)(*(int*)(a + 0x28) + 0x1c)) {
        float* p = (float*)(*(int*)(*(int*)(a + 0x28) + 0x1c) + 0x18);
        *p = 0.0f;
        *(p + 1) = 0.0f;
        *(p + 2) = 0.0f;
        *(p + 3) = 0.0f;
        *(p + 4) = 0.0f;
        *(p + 5) = 0.0f;
        *(p - 6) = 0.0f;
        *(p - 5) = 0.0f;
        *(p - 4) = 0.0f;
        *(p - 3) = 0.0f;
        *(p - 2) = 0.0f;
        *(p - 1) = 0.0f;
    }
}
}   // namespace f3m_0095a690

// @f3 0x0094d990 (community match, verified in this file)
#include <intrin.h>
namespace f3m_0094d990 {

struct CcaArg
{
    char pad_0000[0x1e4];
    unsigned char m_b1e4;
};

struct CcaRes
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

class CcaThis
{
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
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
    virtual void vf41(int flag);
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual CcaRes* vf45(int* out);

    void FUN_00910f30(CcaArg* a1);

    void FUN_0094d990(CcaArg* a1);
};

void FUN_00979830(CcaArg* a1, int value);

// pdb: bhkMoppBvTreeShape::LoadBinary | bhkMoppBvTreeShape.obj | fnv360_0822_debug, objrun, low, conflict (bridge: bhkMoppBvTreeShape::SaveBinary)
// pdb params: arStream
void CcaThis::FUN_0094d990(CcaArg* a1)
{
    int flag;
    CcaRes* res = vf45(&flag);
    if (res != 0) {
        if (a1->m_b1e4 != 1) {
            res->m_0c = _byteswap_ulong(res->m_0c);
        }
    }
    FUN_00910f30(a1);
    if (res != 0) {
        FUN_00979830(a1, res->m_08);
        vf41(flag);
        if (!(unsigned char)flag && a1->m_b1e4 != 1) {
            res->m_0c = _byteswap_ulong(res->m_0c);
        }
    }
}
}   // namespace f3m_0094d990

// @f3 0x00944c30 (community match, verified in this file)
#include <string.h>
namespace f3m_00944c30 {

struct Chunk { float unk00, unk04, unk08, unk0c; };
struct Elem12 { Chunk c[3]; };
static inline void CopyChunk(Chunk* d, const Chunk* p)
{
    d->unk00 = p->unk00;
    d->unk04 = p->unk04;
    d->unk08 = p->unk08;
    d->unk0c = p->unk0c;
}

struct NameEntry {
    const char* name;
};

struct EntryList {
    int unk00;
    int unk04;
    int unk08;
    NameEntry** entries;
    int count;
};

struct Obj {
    int unk00;
    Elem12* data;
};

struct NameLookup {
    int unk00;
    int unk04;
    int unk08;
    const char** names;
    int unk10;
    Obj** objs;

    void FUN_00944c30(Elem12* out, EntryList* list, int idx);
};

// pdb: bhkPoseArray::CreatePoseForRagdoll | bhkPoseArray.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apPoseTransfA, apSkeleton, uiPoseIdx
void NameLookup::FUN_00944c30(Elem12* out, EntryList* list, int idx)
{
    Elem12* dst = out;
    for (int i = 0; i < list->count; ++i) {
        const char* name = list->entries[i]->name;
        bool found = false;
        unsigned int n = (unsigned int)unk08;
        unsigned int j = 0;
        for (; j < n; ++j) {
            if (found) {
                break;
            }
            if (strcmp(name, names[j]) == 0) {
                found = true;
            }
        }
        if (found) {
            Elem12* src = &objs[idx]->data[j - 1];
            CopyChunk(&dst->c[0], &src->c[0]);
            CopyChunk(&dst->c[1], &src->c[1]);
            CopyChunk(&dst->c[2], &src->c[2]);
        }
        ++dst;
    }
}
}   // namespace f3m_00944c30

// @f3 0x0094c860 (community match, verified in this file)
namespace f3m_0094c860 {
struct NiStream;
namespace f3_0094c860 {
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

    void __thiscall hkpBallSocketChainData_addConstraintInfoInBodySpace(void* first, void* second);
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



void __cdecl FUN_009799c0(void* owner, void* data);

struct ReadVec { float x,y,z,w; };

struct FUN_009e0c30_class {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vfExtra();
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

    void FUN_009e0c30(NiStream&);
    void __thiscall FUN_0094c860(ReadContext* owner);
};

// Calls vf10 and FUN_009799c0, passes m_20 entries in pairs to hkpBallSocketChainData_addConstraintInfoInBodySpace, reads four fields via io, then calls FUN_009e0c30.
// @fnv 0x00cc8e60
// pdb: hkBallSocketChainCinfo::LoadBinary | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arStream
void FUN_009e0c30_class::FUN_0094c860(ReadContext* owner)
{
    vf10();

    FUN_009799c0(owner, &m_20);

    ReadData* pReadData = m_04;
    int index = 0;
    while (index < m_24) {
        pReadData->hkpBallSocketChainData_addConstraintInfoInBodySpace(&m_20[index], &m_20[index + 1]);
        index += 2;
    }

    owner->io->Read(&pReadData->unk28);
    owner->io->Read(&pReadData->unk24);
    owner->io->Read(&pReadData->unk2C);
    owner->io->Read(&pReadData->unk30);
    FUN_009e0c30(*reinterpret_cast<NiStream*>(owner));
}
}  // namespace f3_0094c860
}   // namespace f3m_0094c860

// @f3 0x00952840 (community match, verified in this file)
namespace f3m_00952840 {
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
    bool FUN_008f7650(BCCFA50Arg* pkArg);
    __forceinline BCCFA50HavokList* GetList() { return this ? m_pkList : 0; }
    bool FUN_00952840(BCCFA50Arg* pkArg);

    int unk00;
    int unk04;
    BCCFA50HavokList* m_pkList;
};

// Calls FUN_008f7650, then processes each child shape in the list while the result stays true, returning the combined result.
// @fnv 0x00ccfa50
// pdb: bhkConvexListShape::CanShare | bhkConvexListShape.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: arCloneData
bool BCCFA50Wrapper::FUN_00952840(BCCFA50Arg* pkArg)
{
    bool bResult = FUN_008f7650(pkArg);
    if (bResult) {
        int iCount = GetList() ? GetList()->m_kCounter.GetCount() : 0;
        for (int i = 0; bResult && i < iCount; i++) {
            BCCFA50Child* pkChild = GetList() ? GetList()->m_ppkChildren[i] : 0;
            BCCFA50Shape* pkShape = pkChild ? pkChild->m_pkShape : 0;
            if (pkShape)
                bResult &= pkShape->Process(pkArg);
        }
    }
    return bResult;
}

}   // namespace f3m_00952840

// @f3 0x0094d4e0 (community match, verified in this file)
namespace f3m_0094d4e0 {
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
    S_00cc9df0_Val* m_kPointA;
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
    S_00cc9df0_Val* m_kPointB;
};
struct S_00cc9df0_Out {
    int unk00;
    int unk04;
    S_00cc9df0_Val* m_v;
    float m_fValue;
};
struct S_00cc9df0_Cls;
inline S_00cc9df0_Val* GetA(S_00cc9df0_Data* d) { return d ? d->m_kPointA : 0; }
inline S_00cc9df0_Val* GetB(S_00cc9df0_Data* d) { return d ? d->m_kPointB : 0; }
struct S_00cc9df0_Cls {
    int unk00;
    int unk04;
    S_00cc9df0_Data* m_iFourthElementInteger;
    void FUN_00910dc0(S_00cc9df0_Out* out);
    void FUN_0094d4e0(S_00cc9df0_Out* out);
};
inline S_00cc9df0_Data* GetD(S_00cc9df0_Cls* c) { return c ? c->m_iFourthElementInteger : 0; }
// @fnv 0x00cc9df0
// pdb: bhkMoppBvTreeShape::CopyCinfo | bhkMoppBvTreeShape.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arInfo
void S_00cc9df0_Cls::FUN_0094d4e0(S_00cc9df0_Out* out)
{
    FUN_00910dc0(out);
    out->m_v = GetB(GetD(this));
    S_00cc9df0_Data* pData = GetD(this);
    if (pData && pData->m_kPointA) {
        S_00cc9df0_Data* pData2 = GetD(this);
        if (GetB(pData2)) {
            S_00cc9df0_Val* a = GetA(GetD(this));
            S_00cc9df0_Val* b = GetB(GetD(this));
            out->m_fValue = a->m_f / b->m_f;
        }
    }
}

}   // namespace f3m_0094d4e0

// @f3 0x009461b0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_009461b0 {

namespace f3m_009461b0 {

typedef f3m_0094b3d0::NiStreamB3D Stream;

struct Data {
    unsigned long unk00, unk04, unk08, unk0c;
    unsigned long value10, value14, value18, value1c;
    unsigned long value20, value24, value28, value2c;
    unsigned long value30, value34, value38;

    __forceinline void Swap() volatile
    {
        value10 = _byteswap_ulong(value10);
        value14 = _byteswap_ulong(value14);
        value18 = _byteswap_ulong(value18);
        value1c = _byteswap_ulong(value1c);
        value20 = _byteswap_ulong(value20);
        value24 = _byteswap_ulong(value24);
        value28 = _byteswap_ulong(value28);
        value2c = _byteswap_ulong(value2c);
        value30 = _byteswap_ulong(value30);
        value34 = _byteswap_ulong(value34);
        value38 = _byteswap_ulong(value38);
    }
};

class Owner {
public:
    virtual void Slot000();
    virtual void Slot004();
    virtual void Slot008();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual void Slot09c();
    virtual void Slot0a0();
    virtual void Slot0a4();
    virtual void Slot0a8();
    virtual void Slot0ac();
    virtual void Slot0b0();
    virtual Data* GetData(int* state);
    void FUN_008fb9a0(Stream* stream);
    void FUN_009461b0(Stream* stream);
};

// pdb: bhkSpringAction::SaveBinary | bhkSpringAction.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arStream
void Owner::FUN_009461b0(Stream* stream)
{
    Stream* const actualStream = stream;
    int state;
    if (actualStream->unk1e4 != 1) {
        Data* data = GetData(&state);
        if (data)
            data->Swap();
    }

    FUN_008fb9a0(actualStream);

    if (actualStream->unk1e4 != 1) {
        Data* data = GetData(&state);
        if (data)
            data->Swap();
    }
}

}

}   // namespace f3m_009461b0

// @f3 0x00954530 (community match, verified in this file)
namespace f3m_00954530 {
namespace f3m_00954530 {
struct Callback {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Notify(void* item);
};
struct ObjectArrays {
    virtual void Destroy(bool free);
    short active04;
    short refs06;
    void** first08;
    int firstCount0c;
    unsigned unk10;
    void** fourth14;
    int fourthCount18;
    unsigned unk1c;
    void** third20;
    int thirdCount24;
    unsigned unk28;
    void** second2c;
    int secondCount30;
    void DecRef()
    {
        if (active04) {
            --refs06;
            if (refs06 == 0)
                Destroy(true);
        }
    }
};
struct Source {
    void FUN_00902a60(Callback*);
    void FUN_00902ab0(Callback*);
    void FUN_009029c0(Callback*);
    void FUN_00902a10(Callback*);
    ObjectArrays* FUN_009035e0();
};
class Owner {
public:
    unsigned unk00;
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
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    Callback first5c;
    Callback second60;
    Callback fourth64;
    Callback third68;
    void FUN_00954530(Source* source);
};
// pdb: hkpPhysicsContext::removeFromInspection | hkpPhysicsContext.obj | fnv360_0822_retail, call_seq, medium
// pdb params: w
void Owner::FUN_00954530(Source* source)
{
    if (!unk0c)
        return;
    if (!source)
        return;
    Callback* first = &first5c;
    source->FUN_00902a60(first);
    Callback* second = &second60;
    source->FUN_00902ab0(second);
    Callback* third = &third68;
    source->FUN_009029c0(third);
    Callback* fourth = &fourth64;
    source->FUN_00902a10(fourth);
    ObjectArrays* objects = source->FUN_009035e0();
    for (int i = 0; i < objects->firstCount0c; ++i)
        first->Notify(objects->first08[i]);
    for (int i = 0; i < objects->secondCount30; ++i)
        second->Notify(objects->second2c[i]);
    for (int i = 0; i < objects->thirdCount24; ++i)
        third->Notify(objects->third20[i]);
    for (int i = 0; i < objects->fourthCount18; ++i)
        fourth->Notify(objects->fourth14[i]);
    objects->DecRef();
}
}
}   // namespace f3m_00954530

// @f3 0x00940870 (community match, verified in this file)
extern const char DAT_00e79948[];
extern const char DAT_00dbfab8[];
extern const char DAT_00e79978[];
extern const char DAT_00dfa7b0[];
extern const char DAT_00dc10f0[];
extern const char DAT_00e79a14[];
extern const char DAT_00e79a38[];
extern const char DAT_00e79ad0[];
extern const char DAT_00e79aac[];
extern const char DAT_00e79964[];
extern unsigned long DAT_010f3170;
namespace f3m_00940870 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();

struct MemoryContext {
    void FUN_008f6d90(void* data, int bytes, int category) throw();
};
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize) throw();
int __cdecl FUN_009233f0(const char* text) throw();
void __cdecl FUN_009234e0(void* destination, const void* source, int size) throw();
const char* __cdecl FUN_0093e470() throw();

struct NoInit {};
struct Text {
    __forceinline Text(NoInit) throw() {}
    char* data;
    int size;
    int capacityAndFlags;
    int capacity() const { return capacityAndFlags & 0x3fffffff; }
    __forceinline void reserve(int count) {
        int cap = capacity();
        if (cap < count) {
            cap *= 2;
            if (count >= cap) cap = count;
            FUN_00901e90(this, cap, 1);
        }
    }
    __forceinline Text(const char* s) throw() : data(0), size(0), capacityAndFlags(0x80000000) {
        if (s) {
            int n = FUN_009233f0(s) + 1;
            reserve(n);
            size = n;
            FUN_009234e0(data, s, n);
        } else {
            reserve(1);
            size = 1;
            data[0] = 0;
        }
    }
    __forceinline void clear() throw() {
        if ((capacityAndFlags & 0x80000000u) == 0) {
            int cap = capacity();
            MemoryContext* context = (MemoryContext*)TlsGetValue(DAT_010f3170);
            context->FUN_008f6d90(data, cap, 0x17);
        }
    }
    Text* Replace(Text* result, const Text& from, const Text& to, int all) const throw();
};
struct Output {
    void FUN_00943710(const char* s) throw();
};
void __cdecl FUN_00943960(Output* stream, const char* format, ...) throw();
struct ClassInfo {
    const char* FUN_009b0490() const throw();
    void* FUN_009b0bb0(int index) const throw();
};
struct MapFlag {
    char value;
    MapFlag(char v) : value(v) {}
};
struct NameMap {
    void* data;
    int size;
    int mask;
    int generation;
    NameMap(MapFlag flag) throw();
    ~NameMap() throw();
    int FUN_009b0f20(const char* name) const throw();
    char* FUN_009b0e40(char* result, int iterator) const throw();
    void FUN_009b0e60(const char* name, int value) throw();
};

int __cdecl FUN_00940870(Output* stream, const char* guard, const ClassInfo* const* classes, const char* registry)
{
    if (!classes || !registry) return 1;
    if (guard) {
        FUN_00943960(stream, DAT_00e79948, guard, guard);
        stream->FUN_00943710(DAT_00dbfab8);
    }
    stream->FUN_00943710(DAT_00e79978);
    Text blank3(""), dot("."), blank2(""), dash(DAT_00dfa7b0), blank1(""), product(DAT_00dc10f0), version(FUN_0093e470());
    Text temp1((NoInit())), temp2((NoInit())), name((NoInit()));
    version.Replace(&temp1, product, blank1, 1)->Replace(&temp2, dash, blank2, 1)->Replace(&name, dot, blank3, 1);
    temp2.clear(); temp1.clear(); version.clear(); product.clear(); blank1.clear(); dash.clear(); blank2.clear(); dot.clear(); blank3.clear();
    FUN_00943960(stream, DAT_00e79a14, name.data);
    FUN_00943960(stream, DAT_00e79a38, registry);
    stream->FUN_00943710(DAT_00dbfab8);
    {
    NameMap names(MapFlag(0));
    const ClassInfo* const* current = classes;
    for (;;) {
        const ClassInfo* info;
        for (int once = 0; once < 1; ++once) info = *current;
        if (!info) break;
        char found;
        names.FUN_009b0e40(&found, names.FUN_009b0f20(info->FUN_009b0490()));
        if (!found) {
            const char* key = info->FUN_009b0490();
            names.FUN_009b0e60(key, 1);
            FUN_00943960(stream, DAT_00e79ad0, (*current)->FUN_009b0490(), (*current)->FUN_009b0bb0(0));
        }
        ++current;
    }
    FUN_00943960(stream, DAT_00e79aac, name.data);
    if (guard) {
        FUN_00943960(stream, DAT_00e79964, guard);
        stream->FUN_00943710(DAT_00dbfab8);
    }
    }
    name.clear();
    return 0;
}
}   // namespace f3m_00940870

// @f3 0x00952a10 (community match, verified in this file)
namespace f3m_00952a10 {
struct CE340Array { int unk0; int unk1; int unk2; };

struct CE340Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CE340Array m_arr10;
};

struct CE340Obj {
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03(); virtual void vf04();
    virtual void vf05(); virtual void vf06(); virtual void vf07(); virtual void vf08(); virtual void vf09();
    virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13(); virtual void vf14();
    virtual void vf15(); virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23(); virtual void vf24();
    virtual void vf25(); virtual void vf26(); virtual void vf27(); virtual void vf28(); virtual void vf29();
    virtual void vf30(); virtual void vf31(); virtual void vf32(); virtual void vf33(); virtual void vf34();
    virtual void vf35(); virtual void vf36(); virtual void vf37(); virtual void vf38(); virtual void vf39();
    virtual void vf40();
    virtual void SetFlag(bool flag);
    virtual void* GetContext();
    virtual void vf43();
    virtual void vf44();
    virtual CE340Data* GetData(bool* flag);
    void FUN_0090c4f0(void* stream);
    void FUN_00952a10(void* stream);
};

struct QStrm {
    typedef int (__cdecl *ReadFn)(QStrm*, void*, int, int*, int);
    int unk00; int unk04; ReadFn read;
    static inline void Load(QStrm* s, void* p, int n) { int sz = n; s->unk04 += s->read(s, p, n, &sz, 1); }
};
struct S82 { void FUN_0082b620(); };

void FUN_009793e0(CE340Data* d, void* ctx, CE340Array* a);

// pdb: bhkConvexListShape::LoadBinary | bhkConvexListShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void CE340Obj::FUN_00952a10(void* stream_)
{
    unsigned char* stream = (unsigned char*)stream_;
    ((S82*)stream)->FUN_0082b620();
    this->FUN_0090c4f0(stream);
    bool flag;
    CE340Data* data = this->GetData(&flag);
    if (data != 0) {
        if (stream[0x1e5] != 1) {
            void* ctx = this->GetContext();
            FUN_009793e0(data, ctx, &data->m_arr10);
        }
        QStrm::Load(*(QStrm**)(stream + 0x24c), (char*)data + 8, 1);
        QStrm::Load(*(QStrm**)(stream + 0x24c), (char*)data + 0xc, 4);
        if (stream[0x1e5] != 1) {
            void* ctx = this->GetContext();
            FUN_009793e0(data, ctx, &data->m_arr10);
        }
    }
}
}   // namespace f3m_00952a10

// @f3 0x00957d70 (community match, verified in this file)
namespace f3m_00957d70 {
struct QFlag957 { int unk00; bool bActive; };
struct QList957 { int unk00; int unk04; int unk08; QFlag957** ppItems; int iCount; };
struct QQuat957 { float w; float x; float y; float z;
    QQuat957& operator=(const QQuat957& o) { w = o.w; x = o.x; y = o.y; z = o.z; return *this; } };
struct QElem957 { QQuat957 q; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; };

void __cdecl FUN_00957d70(QList957* list, QElem957* src, QElem957* dst)
{
    int count = list->iCount;
    for (int i = 0; i < count; i++) {
        if (list->ppItems[i]->bActive)
            dst[i].q = src[i].q;
    }
}
}   // namespace f3m_00957d70

// @f3 0x0095ade0 (community match, verified in this file)
namespace f3m_0095ade0 {
namespace f3m_0095ade0 {
using f3m_0095aac0::ProfRec;
using f3m_0095aac0::ProfBuf;
using f3m_0095aac0::TlsGetValue;
using f3m_0095aac0::_ReadWriteBarrier;

struct QFreeNode { QFreeNode* m_pNext; };
struct QPool {
    void* unk00; void* unk04; void* unk08; void* unk0C; void* unk10; void* unk14; void* unk18; void* unk1C;
    void* unk20; void* unk24; void* unk28; void* unk2C; void* unk30; void* unk34; void* unk38; void* unk3C;
    void* unk40; void* unk44; void* unk48; void* unk4C;
    QFreeNode* m_pFree;
    int m_nFree;
    void* FUN_008f6800(unsigned int a, unsigned int b);
    void* Allocate()
    {
        QFreeNode* r = m_pFree;
        if (r) {
            m_nFree--;
            m_pFree = r->m_pNext;
            return r;
        }
        return FUN_008f6800(3, 0x2c);
    }
};

struct QEffect {
    unsigned short m_type;
    unsigned int unk04, unk08, unk0C;
    unsigned short unk10;
    unsigned int unk14, unk18, unk1C, unk20, unk24, unk28;
    static void* operator new(unsigned int) {
        return ((QPool*)TlsGetValue(DAT_010f3170))->Allocate();
    }
    QEffect() {
        m_type = 0x19;
        unk10 = 0x20;
    }
};

struct QHolder { int unk; };
struct QTarget {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
};
struct QOwner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual QHolder* v40();
};

QEffect* __cdecl FUN_009a94f0(QHolder* h, int type);
void __cdecl FUN_009a9550(QHolder* h, QTarget* t, QEffect* e);

// pdb: hkpResponseModifier::setLowSurfaceViscosity | hkpResponseModifier.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
void __cdecl hkpResponseModifier_setLowSurfaceViscosity(QOwner* a1, QTarget* a2)
{
    volatile unsigned int ticks;
    QHolder* h = a1->v40();
    if (h) {
        a2->v18();
        ProfBuf* pb = (ProfBuf*)TlsGetValue(DAT_0116913c);
        ProfRec* r = pb->m_pCur;
        if (r < pb->m_pEnd) {
            r->m_pName = "TtSetSurfVisc";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            r->m_iTick = ticks;
            pb->m_pCur = r + 1;
        }
        if (!FUN_009a94f0(h, 0x19)) {
            QEffect* e = new QEffect;
            FUN_009a9550(h, a2, e);
        }
        pb = (ProfBuf*)TlsGetValue(DAT_0116913c);
        ProfRec* r2 = pb->m_pCur;
        if (r2 < pb->m_pEnd) {
            r2->m_pName = "Et";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            r2->m_iTick = ticks;
            pb->m_pCur = r2 + 1;
        }
    }
}
}
}   // namespace f3m_0095ade0

// @f3 0x00953550 (community match, verified in this file)
namespace f3m_00953550 {
struct unk953550Pair {
    int a;
    int b;
};

struct unk953550Bool {
    char v;
    unk953550Bool(bool b) { v = (char)b; }
};
struct unk953550Data { int v; };
typedef void (__cdecl *unk953550Cb)(int, int, unk953550Bool, unk953550Data);

template <class T> struct unk953550Vec {
    T* m_data;
    int m_size;
    int m_cap;
    T& operator[](int i) { return m_data[i]; }
    int getSize() const { return m_size; }
};

struct unk953550Arr {
    unk953550Pair* data;
    unsigned int count;
    unsigned int cap;
};

void __cdecl FUN_00901f10(void* arr, unsigned int elemSize);

class unk953550Owner {
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unk953550Arr items;
    unk953550Vec<unk953550Cb> cbs;
    unk953550Vec<unk953550Data> datas;
    void FUN_00953550(int a, int b, int c);
};

// pdb: hkVisualDebugger::addTrackedObject | hkVisualDebugger.obj | fnv360_0822_retail, call_seq, medium
// pdb params: obj, klass, group, tagId
void unk953550Owner::FUN_00953550(int a, int b, int c) {
    unk953550Arr* arr = &items;
    if (arr->count == (arr->cap & 0x3fffffff)) {
        FUN_00901f10(arr, 8);
    }
    unk953550Pair* p = arr->data + arr->count;
    arr->count = arr->count + 1;
    p->a = a;
    p->b = b;
    for (int i = 0; i < cbs.m_size; ++i) {
        cbs[i](a, b, true, datas[i]);
    }
}
}   // namespace f3m_00953550

// @f3 0x00942950 (community match, verified in this file)
namespace f3m_00942950 {
struct QBool { char m_bool; QBool() {} };
struct QVec4 { float x, y, z, w; };
struct QXform { QVec4 c0; QVec4 c1; QVec4 c2; QVec4 t; };
struct QShape;
struct QBody { QShape* shape; int unk04; QXform* xf; };
struct QColl { int unk00; char unk04; signed char ownerOffset; };
struct QOut { int unk00; float hitFraction; };
struct QRayIn { QVec4 from; QVec4 to; int filterInfo; };
struct QEntry { QVec4 from; QVec4 to; int unk20; int filterInfo; int unk28; int unk2c; };
struct QShape {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void CastRay(QRayIn* in, QBody* body, QOut* out);
};
struct QFilter {
    virtual void v00();
    virtual QBool IsEnabled(QEntry* e, QBody* body);
};

static __forceinline void SetRotatedInverseDir(QVec4& out, const QXform& a, float b0, float b1, float b2)
{
    out.x = a.c0.x * b0 + a.c0.y * b1 + a.c0.z * b2;
    out.y = a.c1.x * b0 + a.c1.y * b1 + a.c1.z * b2;
    out.z = a.c2.x * b0 + a.c2.y * b1 + a.c2.z * b2;
    out.w = 0.0f;
}
static __forceinline void SetTransformedInversePos(QVec4& out, const QXform& a, const QVec4& b)
{
    SetRotatedInverseDir(out, a, b.x - a.t.x, b.y - a.t.y, b.z - a.t.z);
}

class QRayCollector {
public:
    int unk00;
    QEntry* entries;
    QFilter* filter;
    char* outs;
    int outStride;
    int unk14, unk18, unk1c;
    QRayIn input;
    float hkpWorldRayCaster_addBroadPhaseHandle(QColl* coll, int idx);
};

// pdb: hkpWorldRayCaster::addBroadPhaseHandle | hkpWorldRayCaster.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
float QRayCollector::hkpWorldRayCaster_addBroadPhaseHandle(QColl* coll, int idx)
{
    QBody* body = (QBody*)((char*)coll + coll->ownerOffset);
    QOut* out = (QOut*)(outs + outStride * idx);
    QShape* shape = body->shape;
    if (shape) {
        QEntry* e = &entries[idx];
        if (filter->IsEnabled(e, body).m_bool) {
            SetTransformedInversePos(input.from, *body->xf, entries->from);
            SetTransformedInversePos(input.to, *body->xf, e->to);
            input.filterInfo = e->filterInfo;
            shape->CastRay(&input, body, out);
        }
    }
    return out->hitFraction;
}
}   // namespace f3m_00942950

// @f3 0x00945fb0 (community match, verified in this file)
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
namespace n945fb0 {
extern _RTL_CRITICAL_SECTION DAT_010f3194;
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ebb0(void* p);
struct FUN_008f7c10 {
    int unk04;
    int unk08;
    FUN_008f7c10();
    virtual ~FUN_008f7c10();
};
struct L1 : FUN_008f7c10 {
    int unk0c;
    static int ms_count;
    L1() : unk0c(0) { ++ms_count; }
};
struct L2 : L1 {
    static int ms_count;
    L2() { ++ms_count; }
};
struct L3 : L2 {
    static int ms_count;
    L3() { ++ms_count; }
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
};
struct Owner {
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void Add(L1* obj, int arg);
    L3* FUN_00945fb0(int arg);
};
L3* Owner::FUN_00945fb0(int arg)
{
    EnterCriticalSection(&DAT_010f3194);
    L3* obj = new L3;
    Add(obj, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return obj;
}
}

// @f3 0x0094d6d0 (community match, verified in this file)
namespace f3m_0094d6d0 {
namespace n94d6d0 {
struct Counter { int unk00; unsigned short active; unsigned short hits; };
struct Entry { char pad[8]; Counter* counter; float time; };
struct Event { char pad[0x10]; float time; };
struct Base {
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual Entry* Find(bool* created);
    void FUN_00910e00(int a, Event* e);
};
struct Obj : Base {
    void FUN_0094d6d0(int a, Event* e);
};
// pdb: bhkMoppBvTreeShape::CopyMembers | bhkMoppBvTreeShape.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apDest, arCloneData
void Obj::FUN_0094d6d0(int a, Event* e)
{
    bool created;
    Entry* entry = Find(&created);
    if (entry) {
        entry->time = e->time;
        Counter* c = entry->counter;
        if (c && c->active)
            c->hits++;
    }
    FUN_00910e00(a, e);
}
}
}   // namespace f3m_0094d6d0

// @f3 0x00948cf0 (community match, verified in this file)
extern _RTL_CRITICAL_SECTION DAT_010f3194;
namespace f3m_00948cf0 {
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
namespace n948cf0 {
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ebb0(void* p);
struct FUN_008f7c10 {
    int unk04;
    int unk08;
    FUN_008f7c10();
    virtual ~FUN_008f7c10();
};
struct L1 : FUN_008f7c10 {
    int unk0c;
    static int ms_count;
    L1() : unk0c(0) { ++ms_count; }
};
struct L2 : L1 {
    static int ms_count;
    L2() { ++ms_count; }
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
};
struct Owner {
    void FUN_008fbc00(L1* obj, int arg);
    L2* FUN_00948cf0(int arg);
};
// pdb: bhkStiffSpringConstraint::CreateClone | bhkStiffSpringConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCloneData
L2* Owner::FUN_00948cf0(int arg)
{
    EnterCriticalSection(&DAT_010f3194);
    L2* obj = new L2;
    FUN_008fbc00(obj, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return obj;
}
}
}   // namespace f3m_00948cf0

// @f3 0x00959c40 (community match, verified in this file)
namespace f3m_00959c40 {
void __cdecl FUN_009a1770(void* field, int id, void* value);
struct Obj959c40 {
    char pad00[0x10];
    char field10[4];
    void FUN_00959c40(void* value);
};
// pdb: hkpRagdollConstraintData::getConstraintInfo | hkpRagdollConstraintData.obj | tesv_win, objrun_open, low
void Obj959c40::FUN_00959c40(void* value)
{
    FUN_009a1770(field10, 0x12a, value);
}
}   // namespace f3m_00959c40

// @f3 0x00954220 (community match, verified in this file)
namespace f3m_00954220 {
namespace f3m_00954220 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00954220 { char pad[4]; unsigned short w; void FUN_009b1a20(); O00954220* FUN_00954220(unsigned int flags); };
// pdb: hkVisualDebugger::`scalar deleting destructor' | hkVisualDebugger.obj | fnv360_0822_retail, vtable, medium
O00954220* O00954220::FUN_00954220(unsigned int flags) { FUN_009b1a20(); if (flags & 1) { f3m_00954220::T* t = (f3m_00954220::T*)f3m_00954220::DAT_00d9b080(f3m_00954220::DAT_010f3170); t->FUN_008f6d90(this, w, 0x35); } return this; }
}   // namespace f3m_00954220

// @f3 0x0094edd0 (community match, verified in this file)
namespace n94edd0 {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
}
static __forceinline void AlignedFree94edd0(unsigned char* p) { if (p) n94edd0::DAT_01090a78.FUN_0086ba60(p - p[-1]); }
struct Obj94edd0 {
    int f0;
    void* a;
    int f8;
    void* b;
    unsigned char* aligned;
    void FUN_0094edd0();
};
// pdb: bhkExtendedMeshSubPart::~bhkExtendedMeshSubPart | bhkExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
void Obj94edd0::FUN_0094edd0()
{
    if (a) n94edd0::DAT_01090a78.FUN_0086ba60(a);
    if (b) n94edd0::DAT_01090a78.FUN_0086ba60(b);
    AlignedFree94edd0(aligned);
}

// @f3 0x0094ffc0 (community match, verified in this file)
namespace f3m_0094ffc0 {
namespace task0739 {
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

class CCCF00Stream {
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
    virtual void SaveLinkID(void* pvObject);

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
    CCCF00BinaryStream* m_pBackingStream;
};

struct CCCF00Vector4 {
    float x;
    float y;
    float z;
    float w;
};

struct CCCF00Entity {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
CCCF00Vector4 m_kValue;
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
float m_fMass;
};

class CCCF00RigidBody {
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
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void Unlock(bool bLocked);
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void Lock(bool& bLocked);

    int unk04;
    CCCF00Entity* m_pkEntity;
    int unk0C;
    int unk10;
    void* m_pvLinked;

    void FUN_008f74e0(CCCF00Stream& kStream);
    void FUN_0094ffc0(CCCF00Stream& kStream);
};

// @fnv 0x00cccf00
// pdb: bhkExtendedMeshShape::SaveBinary | bhkExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arStream
void CCCF00RigidBody::FUN_0094ffc0(CCCF00Stream& kStream) {
    bool bLocked;
    Lock(bLocked);
    CCCF00Entity* pkEntity = m_pkEntity;
    FUN_008f74e0(kStream);
    float fMass = pkEntity->m_fMass;
    kStream.m_pBackingStream->Write(&fMass, sizeof(fMass));
    kStream.m_pBackingStream->Write(&pkEntity->m_kValue, sizeof(CCCF00Vector4));
    kStream.SaveLinkID(m_pvLinked);
    Unlock(bLocked);
}

}
}   // namespace f3m_0094ffc0

// @f3 0x0094b8c0 (community match, verified in this file)
extern int DAT_00e1c304, DAT_00e7ad2c, DAT_00e7ac54;
extern int DAT_010f31f8, DAT_011697b4, DAT_011691d4;
namespace f3m_0094b8c0 {
namespace Task0757 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*, unsigned int);
class RefObject {
public:
 int* vtable;
 int unk04;
 int unk08;
 int unk0c;
 void FUN_008f7c10();
 static void* operator new(unsigned int size) {return FUN_0089eb90(size);}
 static void operator delete(void* p, unsigned int size) {FUN_0089ec10(p,size);}
 __forceinline RefObject() {
  FUN_008f7c10();
  vtable=&DAT_00e1c304;
  unk0c=0;
  ++DAT_010f31f8;
  vtable=&DAT_00e7ad2c;
  ++DAT_011697b4;
  vtable=&DAT_00e7ac54;
  ++DAT_011691d4;
 }
};
// pdb: bhkFixedConstraint::CreateObject | bhkFixedConstraint.obj | fnv360_0721_beta, objrun, medium
RefObject* __cdecl FUN_0094b8c0() {return new RefObject;}
}
}   // namespace f3m_0094b8c0

// @f3 0x009421c0 (community match, verified in this file)
namespace f3m_009421c0 {
struct O_9421c0 { char pad[0x148]; int v; int FUN_009421c0(); };
// pdb: hkCpuJobThreadPool::getNumThreads | hkCpuJobThreadPool.obj | tesv_win, objrun_open, low
int O_9421c0::FUN_009421c0() { return v; }
}   // namespace f3m_009421c0

// @f3 0x0094e160 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0094e160 {
namespace task0761 {
inline void Swap86(unsigned long* p)
{
    *p = _byteswap_ulong(*p);
}
struct NiStream86
{
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
    unsigned char unk1e4;
    unsigned char m_bSameEndian;
};
struct Block86
{
    int m_00, m_04, m_08, m_0c;
    unsigned long m_aulData[12];
};
struct FUN_0090c4f0_t
{
    void FUN_0090c4f0(NiStream86* pkStream);
};
class FUN_0094e160_t
{
  public:
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
    virtual void v43();
    virtual void v44();
    virtual Block86* GetBlock(int* piSize);
    void FUN_0094e160(NiStream86* pkStream);
};
// @fnv 0x00c86e80
// pdb: bhkTriangleShape::LoadBinary | bhkTriangleShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_0094e160_t::FUN_0094e160(NiStream86* pkStream)
{
    ((FUN_0090c4f0_t*)this)->FUN_0090c4f0(pkStream);
    if (pkStream->m_bSameEndian == 1)
        return;
    int iSize;
    Block86* pkBlock = GetBlock(&iSize);
    if (!pkBlock) return;
    Swap86(&pkBlock->m_aulData[0]);
    Swap86(&pkBlock->m_aulData[1]);
    Swap86(&pkBlock->m_aulData[2]);
    Swap86(&pkBlock->m_aulData[3]);
    Swap86(&pkBlock->m_aulData[4]);
    Swap86(&pkBlock->m_aulData[5]);
    Swap86(&pkBlock->m_aulData[6]);
    Swap86(&pkBlock->m_aulData[7]);
    Swap86(&pkBlock->m_aulData[8]);
    Swap86(&pkBlock->m_aulData[9]);
    Swap86(&pkBlock->m_aulData[10]);
    Swap86(&pkBlock->m_aulData[11]);
}

}
}   // namespace f3m_0094e160

// @f3 0x0094e8a0 (community match, verified in this file)
namespace f3m_0094e8a0 {
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
namespace task0762 {
inline void Swap86(unsigned long* p)
{
    *p = _byteswap_ulong(*p);
}
struct NiStream86
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
    unsigned char unk1e4;
    unsigned char m_bSameEndian;
};
struct Block86
{
    int m_00, m_04, m_08, m_0c;
    unsigned long m_aulData[12];
};
struct FUN_008f7490_t
{
    void FUN_008f7490(NiStream86* pkStream);
};
class FUN_0094e8a0_t
{
  public:
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
    virtual void v43();
    virtual void v44();
    virtual Block86* GetBlock(int* piSize);
    void FUN_0094e8a0(NiStream86* pkStream);
};
// @fnv 0x00c86e80
// pdb: bhkPlaneShape::LoadBinary | bhkPlaneShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_0094e8a0_t::FUN_0094e8a0(NiStream86* pkStream)
{
    ((FUN_008f7490_t*)this)->FUN_008f7490(pkStream);
    if (pkStream->m_bSameEndian == 1)
        return;
    int iSize;
    Block86* pkBlock = GetBlock(&iSize);
    if (!pkBlock) return;
    Swap86(&pkBlock->m_aulData[0]);
    Swap86(&pkBlock->m_aulData[1]);
    Swap86(&pkBlock->m_aulData[2]);
    Swap86(&pkBlock->m_aulData[3]);
    Swap86(&pkBlock->m_aulData[4]);
    Swap86(&pkBlock->m_aulData[5]);
    Swap86(&pkBlock->m_aulData[6]);
    Swap86(&pkBlock->m_aulData[7]);
    Swap86(&pkBlock->m_aulData[8]);
    Swap86(&pkBlock->m_aulData[9]);
    Swap86(&pkBlock->m_aulData[10]);
    Swap86(&pkBlock->m_aulData[11]);
}


}
}   // namespace f3m_0094e8a0

// @f3 0x0094cea0 (community match, verified in this file)
extern int DAT_00e1c304, DAT_00e36ee4, DAT_010f31f8, DAT_011691f8;
namespace f3m_0094cea0 {
namespace task0763 {
void* __cdecl FUN_0089eb90(unsigned int) throw();
struct AllocationBase { static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } };
struct FUN_008f7c10 : AllocationBase { void* vtable; int referenceCount; int field08; FUN_008f7c10(); };
struct Constraint : FUN_008f7c10 {
 int field0c;
 Constraint() { vtable=&DAT_00e1c304; field0c=0; DAT_010f31f8+=1; vtable=&DAT_00e36ee4; DAT_011691f8+=1; }
};
Constraint* FUN_0094cea0() { return new Constraint; }
}
}   // namespace f3m_0094cea0

// @f3 0x00949aa0 (community match, verified in this file)
extern int DAT_00e1c304, DAT_00e36fbc;
extern int DAT_010f31f8, DAT_011691bc;
namespace f3m_00949aa0 {
namespace Task0764 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*, unsigned int);
class RefObject {
public:
 int* vtable;
 int unk04;
 int unk08;
 int unk0c;
 void FUN_008f7c10();
 static void* operator new(unsigned int size) {return FUN_0089eb90(size);}
 static void operator delete(void* p, unsigned int size) {FUN_0089ec10(p,size);}
 __forceinline RefObject() {
  FUN_008f7c10();
  vtable=&DAT_00e1c304;
  unk0c=0;
  ++DAT_010f31f8;
  vtable=&DAT_00e36fbc;
  ++DAT_011691bc;
 }
};
// pdb: bhkRagdollConstraint::CreateObject | bhkRagdollConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
RefObject* __cdecl FUN_00949aa0() {return new RefObject;}
}
}   // namespace f3m_00949aa0

// @f3 0x00941f40 (community match, verified in this file)
namespace f3m_00941f40 {
struct FUN_00941f40 {
    int a;
    int b;
    int c;
    bool d;
    int e;
    int f;
    FUN_00941f40();
};
// pdb: hkCpuJobThreadPoolCinfo::hkCpuJobThreadPoolCinfo | hkCpuJobThreadPool.obj | fnv360_0822_retail, uconst, low
FUN_00941f40::FUN_00941f40() : a(0), b(1), c(4000000), d(true), e(0), f(0)
{
}
}   // namespace f3m_00941f40

// @f3 0x0094d4a0 (community match, verified in this file)
namespace f3m_0094d4a0 {
struct Tgt_0094d4a0 {
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual int v();
};
struct O_0094d4a0 { char pad[0x34]; Tgt_0094d4a0* p; int FUN_0094d4a0(); };
// pdb: hkpMoppBvTreeShape::getContainer | bhkMoppBvTreeShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: CreateNS_bhkMoppBvTreeShape::Create)
int O_0094d4a0::FUN_0094d4a0() { return p->v(); }
}   // namespace f3m_0094d4a0

// @f3 0x00951c70 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00951c70 {
namespace n951c70 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long);
struct Src { int a0, a4; void* p8; int pc; char sub[4]; };
struct NewObj {
    virtual ~NewObj();
    unsigned short memSize;
    short refCount;
    NewObj* FUN_009ecf50(void* a, void* b);
    NewObj(void* a, void* b);
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x27);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x27);
    }
    void RemoveReference() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
    char pad[0x60 - 8];
};
struct D { char pad[0x10]; unsigned int flags; };
struct C { char pad[8]; D* d; };
struct B { char pad[0x18]; C* c; };
}
struct Obj951c70 {
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
    virtual void AddThing(n951c70::NewObj* o);
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
    virtual void Use(n951c70::Src* s);
    int f4;
    n951c70::B* b;
    int fc;
    unsigned int f10;
    void FUN_00951c70(n951c70::Src* s);
};
// pdb: bhkConvexTransformShape::Link | bhkConvexTransformShape.obj | fnv360_0721_retail, objrun, low
// pdb params: abAttach
void Obj951c70::FUN_00951c70(n951c70::Src* s)
{
    if (!s) return;
    n951c70::NewObj* o = new n951c70::NewObj(s->p8, s->sub);
    AddThing(o);
    o->RemoveReference();
    Use(s);
    if (b && b->c && b->c->d)
        f10 = b->c->d->flags & 0x1f;
}
}   // namespace f3m_00951c70

// @f3 0x00957f00 (community match, verified in this file)
namespace f3m_00957f00 {
namespace n957f00 {
struct T { float v[12]; };
void __cdecl blendTwoTransforms(const T* a, const T* b, float t, T* out);
}
// pdb: hkaSkeletonUtils::blendPoses | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: numBones, poseA, poseB, weight, poseOut
void __cdecl FUN_00957f00(unsigned int n, const n957f00::T* a, const n957f00::T* b, float t, n957f00::T* out)
{
    for (unsigned int i = 0; i < n; i++)
        n957f00::blendTwoTransforms(&a[i], &b[i], t, &out[i]);
}
}   // namespace f3m_00957f00

// @f3 0x00945780 (community match, verified in this file)
namespace f3m_00945780 {
namespace task0817 {
void* FUN_0089eb90(unsigned int);
struct FUN_009453f0 {
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void*);
    FUN_009453f0();
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
};
struct Owner {
    void FUN_009456e0(FUN_009453f0*,int);
    FUN_009453f0* FUN_00945780(int);
};
FUN_009453f0* Owner::FUN_00945780(int arg) {
    FUN_009453f0* item = new FUN_009453f0;
    FUN_009456e0(item,arg);
    return item;
}
}
}   // namespace f3m_00945780

// @f3 0x0094b760 (community match, verified in this file)
namespace n94b760 {
extern int DAT_011691d4;
class Base {
public:
    virtual ~Base();
    void FUN_008f7ef0();
};
}
class FUN_0094b760 : public n94b760::Base {
public:
    virtual ~FUN_0094b760();
};
// pdb: bhkGenericConstraint::bhkGenericConstraint | bhkFixedConstraint.obj | fnv360_0822_debug, objopen_prop, low
FUN_0094b760::~FUN_0094b760()
{
    FUN_008f7ef0();
    --n94b760::DAT_011691d4;
}

// @f3 0x0094f320 (community match, verified in this file)
namespace f3m_0094f320 {
namespace n94f320 {
extern long (__stdcall* const FUN_00d9b064)(long volatile* p);
extern long (__stdcall* const FUN_00d9b068)(long volatile* p);
struct RefObj {
    virtual void v0();
    virtual void DeleteThis();
    long volatile refCount;
};
struct Data { char pad[0x10]; float x, y, z; };
struct Clone { char pad[0x14]; RefObj* ref; };
struct Src { char pad[0x10]; float x, y, z; };
}
struct NiPoint3H { char pad[0x10]; float x, y, z; };
struct Obj94f320 {
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
    virtual struct NiPoint3H* GetData(char* out);
    char pad[0x10];
    n94f320::RefObj* ref;
    void FUN_008f7580(n94f320::Clone* dst, n94f320::Src* src);
    void FUN_0094f320(n94f320::Clone* dst, n94f320::Src* src);
};
void Obj94f320::FUN_0094f320(n94f320::Clone* dst, n94f320::Src* src)
{
    char tmp;
    NiPoint3H* d = GetData(&tmp);
    if (d) {
        d->x = src->x;
        d->y = src->y;
        d->z = src->z;
    }
    n94f320::RefObj* old = dst->ref;
    if (old != ref) {
        if (old && n94f320::FUN_00d9b064(&old->refCount) == 0)
            old->DeleteThis();
        n94f320::RefObj* n = ref;
        dst->ref = n;
        if (n)
            n94f320::FUN_00d9b068(&n->refCount);
    }
    FUN_008f7580(dst, src);
}
}   // namespace f3m_0094f320

// @f3 0x0095b0c0 (community match, verified in this file)
namespace f3m_0095b0c0 {
class Object0095b0c0
{
public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void* FUN_0095b0c0_vfn0C(void* arg);
};

class FUN_0095b0c0_cls
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void* FUN_0095b0c0(void* arg);
};

// pdb: hkpMalleableConstraintData::isValid | hkpMalleableConstraintData.obj | fnv360_0822_debug, objrun_open, low
void* FUN_0095b0c0_cls::FUN_0095b0c0(void* arg)
{
    Object0095b0c0* obj = (Object0095b0c0*)this->unk0C;
    obj->FUN_0095b0c0_vfn0C(arg);
    return arg;
}
}   // namespace f3m_0095b0c0

// @f3 0x00942700 (community match, verified in this file)
namespace f3m_00942700 {
namespace Slot303{struct Owner303;struct Slot303;void __cdecl FUN_00942350(Slot303*);struct Callback303{unsigned int unk00,unk04,unk08,unk0c;void FUN_00984aa0(void(__cdecl*)(Slot303*),Slot303*);};struct Slot303{Owner303*owner;unsigned int unk04;Callback303 callback;int index;unsigned char active,unk1d,unk1e,unk1f;unsigned int unk20,unk24,first,second;};struct Root303{
unsigned int unk00;
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
unsigned int unk48;
unsigned int unk4c;
unsigned int unk50;
unsigned int unk54;
unsigned int unk58;
unsigned int unk5c;
unsigned int unk60;
unsigned int unk64;
unsigned int unk68;
unsigned int unk6c;
unsigned int unk70;
unsigned int unk74;
unsigned int unk78;
unsigned int unk7c;
unsigned int unk80;
unsigned int unk84;
unsigned int unk88;
unsigned int unk8c;
unsigned int unk90;
unsigned int unk94;
unsigned int unk98;
unsigned int unk9c;
unsigned int unka0;
unsigned int unka4;
unsigned int unka8;
unsigned int unkac;
unsigned int unkb0;
unsigned int unkb4;
unsigned int unkb8;
unsigned int unkbc;
unsigned int unkc0;
unsigned int unkc4;
unsigned int unkc8;
unsigned int unkcc;
unsigned int unkd0;
unsigned int unkd4;
unsigned int unkd8;
int type;};struct Owner303{Root303*root;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
unsigned int unk24;
Slot303 slots[6];int count;void FUN_009421d0();int FUN_00942700();};
// pdb: hkCpuJobThreadPool::addThread | hkCpuJobThreadPool.obj | tesv_win, objrun_open, low
int Owner303::FUN_00942700(){int limit=root->type>=3?6:1;if(count<limit){Slot303*slot=&slots[count];slot->owner=this;slot->index=count;slot->first=0;slot->second=0;slot->active=0;slot->callback.FUN_00984aa0(FUN_00942350,slot);++count;FUN_009421d0();return 0;}return 1;}
}
}   // namespace f3m_00942700

// @f3 0x0094f130 (community match, verified in this file)
namespace f3m_0094f130 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
namespace f3m_0094f130 {
struct RefObj {
    virtual void F0();
    virtual void DeleteThis();
    long rc;
};
struct RefPtr {
    RefObj* p;
    RefPtr& operator=(const RefPtr& o) {
        RefObj* old = p;
        if (old != o.p) {
            if (old && InterlockedDecrement(&old->rc) == 0) old->DeleteThis();
            p = o.p;
            if (p) InterlockedIncrement(&p->rc);
        }
        return *this;
    }
};
struct Data {
    char unk0[0x20];
    float a, b, c, d;
    char unk30[0x80];
    float e;
};
struct Out {
    int unk0;
    RefPtr sp;
    float e;
    int unkC;
    float a, b, c, d;
};
struct FUN_0094f130c {
    int unk0, unk4;
    Data* data;
    int unkC, unk10;
    RefPtr sp;
    void FUN_0096ab80(Out* o);
    void FUN_0094f130(Out* o);
};
void FUN_0094f130c::FUN_0094f130(Out* o) {
    FUN_0096ab80(o);
    Data* d = this ? data : 0;
    o->sp = sp;
    o->e = d->e;
    o->a = d->a;
    o->b = d->b;
    o->c = d->c;
    o->d = d->d;
}
}
}   // namespace f3m_0094f130

// @f3 0x0094f940 (community match, verified in this file)
namespace f3m_0094f940 {
struct Stream {
    int unk0;
    unsigned int pos;
    unsigned int (__cdecl *read)(Stream*, void*, unsigned int, unsigned int*, int);
    __forceinline void Read(void* dst, unsigned int size) {
        unsigned int n = size;
        pos += read(this, dst, size, &n, 1);
    }
};
struct Reader { int unk0[0x93]; Stream* stream; };
struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;
struct Item {
    int unk0[5];
    Item();
    ~Item();
    void* operator new[](unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    void operator delete[](void* p);
    void Load(Reader* r);
};
struct Owner {
    int unk0[2];
    unsigned int count;
    Item* items;
    void FUN_0094f940(Reader* r);
};
// pdb: bhkExtendedMeshShapeData::LoadBinary | bhkExtendedMeshShape.obj | fnv360_0721_beta, objrun, medium
// pdb params: arStream
void Owner::FUN_0094f940(Reader* r) {
    r->stream->Read(&count, 4);
    items = new Item[count];
    for (unsigned int i = 0; i < count; ++i)
        items[i].Load(r);
}
}

// @f3 0x00941bb0 (community match, verified in this file)
namespace f3m_00941bb0 {
namespace f3m_00941bb0 {
struct Child {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
struct Owner {
    int unk0[6];
    Child* child;
    int FUN_00941bb0();
};
int Owner::FUN_00941bb0() {
    if (child) return child->v3();
    return 0;
}
}
}   // namespace f3m_00941bb0

// @f3 0x00942860 (community match, verified in this file)
namespace f3m_00942860 {
struct Sub_942860 { int u; int FUN_0086c5d0(int a); };
struct O_942860 { char pad[0xa18]; Sub_942860 sub; int FUN_00942860(); };
int O_942860::FUN_00942860() { return sub.FUN_0086c5d0(0); }
}   // namespace f3m_00942860

// @f3 0x0094e380 (community match, verified in this file)
namespace n94e380 {
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct Item {
    char data[0x40];
    Item() throw();
    static void* operator new(unsigned int n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
}
struct Obj94e380 {
    int a0, a4;
    void* owner;
    n94e380::Item* item;
    void FUN_0094df30(n94e380::Item* it);
    n94e380::Item* FUN_0094e380(bool* created);
};
// pdb: bhkTriangleShape::CreateCinfo | bhkTriangleShape.obj | fnv360_1110_retail, objopen_prop, low
// pdb params: arCreated
n94e380::Item* Obj94e380::FUN_0094e380(bool* created)
{
    if (!item) {
        item = new n94e380::Item;
        if (owner) FUN_0094df30(item);
        *created = true;
        return item;
    }
    *created = false;
    return item;
}

// @f3 0x009439f0 (community match, verified in this file)
namespace f3m_009439f0 {
struct O_9439f0 { void FUN_009439b0(); };
O_9439f0* __cdecl FUN_009439f0(O_9439f0* x) { x->FUN_009439b0(); return x; }
}   // namespace f3m_009439f0

// @f3 0x0095b310 (community match, verified in this file)
namespace f3m_0095b310 {
int __cdecl FUN_00a029e0(void* sub, int v);
struct O_95b310 { char pad[0x18]; char sub[0x10]; int v28; int FUN_0095b310(); };
// pdb: hkaRagdollRigidBodyController::reinitialize | hkaRagdollRigidBodyController.obj | fnv360_0822_retail, call_seq, medium
int O_95b310::FUN_0095b310() { return FUN_00a029e0(sub, v28); }
}   // namespace f3m_0095b310

// @f3 0x0094efd0 (community match, verified in this file)
namespace f3m_0094efd0 {
namespace n94efd0 {
struct Info { int a; unsigned int flags; };
struct Table { Info* FUN_009e34d0(int index); };
}
struct FUN_0094efd0_t {
    int a, b;
    n94efd0::Table* m_table;
    n94efd0::Table* GetTable() { return this ? m_table : 0; }
    bool FUN_0094efd0(int index, unsigned int mask);
};
// pdb: bhkExtendedMeshShape::QSubMaterial | bhkExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: aiKey
bool FUN_0094efd0_t::FUN_0094efd0(int index, unsigned int mask) {
    bool res = false;
    n94efd0::Table* t = GetTable();
    if (index != -1)
        res = (t->FUN_009e34d0(index)->flags & mask) != 0;
    return res;
}
}   // namespace f3m_0094efd0

// @f3 0x00959e00 (community match, verified in this file)
namespace f3m_00959e00 {
struct Owner329{unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;float values[12];void FUN_00959e00(float*);};
void Owner329::FUN_00959e00(float*output){output[0]=values[0];output[1]=values[1];output[2]=values[2];output[3]=values[3];output[4]=values[4];output[5]=values[5];output[6]=values[6];output[7]=values[7];output[8]=values[8];output[9]=values[9];output[10]=values[10];output[11]=values[11];}
}   // namespace f3m_00959e00

// @f3 0x00950fb0 (community match, verified in this file)
namespace f3m_00950fb0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Free332{
extern unsigned long DAT_010f3170;struct Heap332{void FUN_008f6d90(void*,unsigned int,int);};
struct Array332{void*data;unsigned int size,capacityFlags;void FUN_00950fb0();};
// pdb: bhkConvexVerticesShape::GetViewerStrings | bhkConvexVerticesShape.obj | fnv360_0721_beta, objrun, medium
// pdb params: apStrings
void Array332::FUN_00950fb0(){if(!(capacityFlags&0x80000000)){unsigned int capacity=capacityFlags&0x3fffffff;Heap332*heap=(Heap332*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(data,capacity*16,23);}}
}
}   // namespace f3m_00950fb0

// @f3 0x009456e0 (community match, verified in this file)
namespace f3m_009456e0 {
namespace Copy345{
struct Object345{virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual Object345* Clone(void*);};
struct List345{void FUN_009450a0(unsigned int);};struct Destination345{unsigned int unk00,unk04,unk08;List345 list;void FUN_00945640(Object345*);};
struct Owner345{unsigned int unk00,unk04,unk08,unk0c;Object345**data;unsigned int unk14,unk18,count;void FUN_00845a50(Destination345*,void*);void FUN_009456e0(Destination345*,void*);};
// pdb: bhkExtraData::CopyMembers | bhkExtraData.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: pDest, arCloneData
void Owner345::FUN_009456e0(Destination345*destination,void*context){FUN_00845a50(destination,context);unsigned int size=count;destination->list.FUN_009450a0(size);for(unsigned int i=0;i<size;++i){Object345*value=data[i];if(value)value=value->Clone(context);destination->FUN_00945640(value);}}
}
}   // namespace f3m_009456e0

// @f3 0x0094de30 (community match, verified in this file)
extern int DAT_01169210;
namespace f3m_0094de30 {
namespace task0865 {
class FUN_0090c430 {
public:
 virtual void unk00();
 ~FUN_0090c430();
 int unk04;
};
class FUN_0094de30 : public FUN_0090c430 {
public:
 virtual ~FUN_0094de30();
 void FUN_008f7ef0();
};
// pdb: hkScaledMoppBvTreeShape::~hkScaledMoppBvTreeShape | hkScaledMoppBvTreeShape.obj | tesv_win, objopen_prop, low
FUN_0094de30::~FUN_0094de30() {
 FUN_008f7ef0();
 DAT_01169210--;
}
}
}   // namespace f3m_0094de30

// @f3 0x0094c590 (community match, verified in this file)
extern int DAT_011691ec;
namespace f3m_0094c590 {
namespace task0867 {
struct FUN_009e0c50 {
 virtual void slot00();
 int field04;
 ~FUN_009e0c50();
};
struct FUN_0094c590 : FUN_009e0c50 {
 virtual ~FUN_0094c590();
 void FUN_008f7ef0();
};
FUN_0094c590::~FUN_0094c590() {
 FUN_008f7ef0();
 DAT_011691ec--;
}
}
}   // namespace f3m_0094c590

// @f3 0x0094d410 (community match, verified in this file)
extern int DAT_01169204;
namespace f3m_0094d410 {
namespace task0866 {

class FUN_00910d50
{
  public:
    virtual void unk00();
    ~FUN_00910d50();
    int unk04;
};

class FUN_0094d410 : public FUN_00910d50
{
  public:
    virtual ~FUN_0094d410();
    void FUN_008f7ef0();
};

// @fnv 0x00c86720
// pdb: bhkMoppBvTreeShape::~bhkMoppBvTreeShape | bhkMoppBvTreeShape.obj | tesv_win, caller_sim, low
FUN_0094d410::~FUN_0094d410()
{
    this->FUN_008f7ef0();
    DAT_01169204--;
}

}
}   // namespace f3m_0094d410

// @f3 0x00943500 (community match, verified in this file)
namespace f3m_00943500 {
void __cdecl FUN_009bf1b0(int param);
void __cdecl hkpConvexListAgent_registerAgent(int param);
void __cdecl FUN_009bcf60(int param);
void __cdecl FUN_009bbcc0(int param);
void __cdecl FUN_009bada0(int param);

// pdb: hkpAgentRegisterUtil::_registerListAgents | hkpAgentRegisterUtil.obj | tesv_win, call_gap, low
void __cdecl FUN_00943500(int param) {
    FUN_009bf1b0(param);
    hkpConvexListAgent_registerAgent(param);
    FUN_009bcf60(param);
    FUN_009bbcc0(param);
    FUN_009bada0(param);
}
}   // namespace f3m_00943500

// @f3 0x009467b0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_009467b0 {
namespace n9467b0 {
struct Stream { char pad[0x1e5]; char native; };
struct Data { char pad[0x10]; unsigned long w[6]; };
inline void Swap32(unsigned long& v) { v = _byteswap_ulong(v); }
}
struct FUN_009467b0_t {
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
    virtual n9467b0::Data* GetData(unsigned int* size);
    void FUN_008f88e0(n9467b0::Stream* s);
    void FUN_009467b0(n9467b0::Stream* s);
};
// pdb: bhkMotorAction::LoadBinary | bhkMotorAction.obj | fnv360_0721_beta, objrun, medium
// pdb params: arStream
void FUN_009467b0_t::FUN_009467b0(n9467b0::Stream* s) {
    FUN_008f88e0(s);
    if (s->native == 1) return;
    unsigned int size;
    n9467b0::Data* d = GetData(&size);
    if (!d) return;
    n9467b0::Swap32(d->w[0]);
    n9467b0::Swap32(d->w[1]);
    n9467b0::Swap32(d->w[2]);
    n9467b0::Swap32(d->w[3]);
    n9467b0::Swap32(d->w[4]);
    n9467b0::Swap32(d->w[5]);
}
}   // namespace f3m_009467b0

// @f3 0x00941bd0 (community match, verified in this file)
namespace f3m_00941bd0 {
struct T_941bd0 {
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void v(int x);
};
struct O_941bd0 { char pad[0x18]; T_941bd0* p; void FUN_00941bd0(int x); };
void O_941bd0::FUN_00941bd0(int x) { if (p) p->v(x); }
}   // namespace f3m_00941bd0

// @f3 0x0094cbf0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094cbf0 {
namespace n94cbf0 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
struct Elem { float v[4]; };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    ~Array() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct Base {
    char pad[0x20];
    ~Base();
};
}
struct FUN_0094cbf0 : n94cbf0::Base {
    n94cbf0::Array<n94cbf0::Elem> arr;
    ~FUN_0094cbf0();
};
// pdb: hkConstraintChainCinfo::~hkConstraintChainCinfo | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, objopen_prop, low
FUN_0094cbf0::~FUN_0094cbf0() {}
}   // namespace f3m_0094cbf0

// @f3 0x0095b530 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0095b530 {
namespace n95b530 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long) throw();
template <int N> struct Elem { char b[N]; };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct RefObj {
    virtual void Delete(int flags) throw();
    unsigned short memSize;
    short refCount;
    void RemoveReference() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) Delete(1);
        }
    }
};
}
struct FUN_0095b530 {
    n95b530::Array< n95b530::Elem<0x30> > a0;
    n95b530::Array<int> a1;
    int unk18[4];
    n95b530::Array< n95b530::Elem<0x40> > a2;
    n95b530::RefObj* ref;
    n95b530::Array<short> a3;
    ~FUN_0095b530() throw();
};
// pdb: hkaRagdollRigidBodyController::~hkaRagdollRigidBodyController | hkaRagdollRigidBodyController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_0095b530::~FUN_0095b530() throw() {
    ref->RemoveReference();
}
}   // namespace f3m_0095b530

// @f3 0x0094ba20 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094ba20 {
namespace n94ba20 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
struct Obj {
    virtual ~Obj();
    unsigned short memSize;
    short refCount;
    Obj();
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x2c);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x2c);
    }
    char pad[0x58 - 8];
};
}
struct FUN_0094ba20_t {
    void FUN_009dd9b0(n94ba20::Obj* o, int arg);
    void FUN_0094ba20(n94ba20::Obj* o, int arg);
};
// pdb: hkFixedConstraintCinfo::CloneData | bhkFixedConstraint.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apData, arCloneData
void FUN_0094ba20_t::FUN_0094ba20(n94ba20::Obj* o, int arg) {
    if (!o)
        o = new n94ba20::Obj;
    FUN_009dd9b0(o, arg);
}
}   // namespace f3m_0094ba20

// @f3 0x0094f0b0 (community match, verified in this file)
namespace n94f0b0 {
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct Elem {
    char pad[0x14];
    ~Elem();
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct Base {
    virtual ~Base();
    int a, b;
};
}
struct FUN_0094f0b0 : n94f0b0::Base {
    n94f0b0::Elem* items;
    virtual ~FUN_0094f0b0();
};
FUN_0094f0b0::~FUN_0094f0b0() {
    delete[] items;
}

// @f3 0x00941fa0 (community match, verified in this file)
namespace f3m_00941fa0 {
struct Ref_941fa0 { int u0; unsigned short w4; unsigned short w6; };
struct O_941fa0 { Ref_941fa0* p; void FUN_00941fa0(Ref_941fa0* r); };
void O_941fa0::FUN_00941fa0(Ref_941fa0* r) { p = r; if (r->w4) ++r->w6; }
}   // namespace f3m_00941fa0

// @f3 0x00952340 (community match, verified in this file)
namespace f3m_00952340 {
struct T_00952340 {
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void v(int a, int b, int c);
};
struct O_00952340 { int u0, u4; T_00952340* p; void FUN_00952340(int a, int b, int c); };
// pdb: bhkConvexListShape::ConvertVertexIdsToVertices | bhkConvexListShape.obj | fnv360_0822_retail, objrun_sim, low, conflict (bridge: bhkConvexListShape::GetSupportingVertex)
// pdb params: pIds, inumIds, pverticesOut
void O_00952340::FUN_00952340(int a, int b, int c) { if (this) { T_00952340* t = p; if (t) t->v(a, b, c); } }
}   // namespace f3m_00952340

// @f3 0x00952360 (community match, verified in this file)
namespace f3m_00952360 {
struct T_00952360 {
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void v(int a);
};
struct O_00952360 { int u0, u4; T_00952360* p; void FUN_00952360(int a); };
// pdb: bhkConvexListShape::GetFirstVertex | bhkConvexListShape.obj | fnv360_0822_retail, objrun_sim, low, conflict (bridge: bhkConvexListShape::ConvertVertexIdsToVertices)
// pdb params: arVertex
void O_00952360::FUN_00952360(int a) { if (this) { T_00952360* t = p; if (t) t->v(a); } }
}   // namespace f3m_00952360

// @f3 0x009491e0 (community match, verified in this file)
extern int DAT_011691b0;
namespace f3m_009491e0 {
namespace task0869 {
struct FUN_008fbad0 {
    virtual void slot00();
    int unk04;
    ~FUN_008fbad0();
};
struct FUN_009491e0 : FUN_008fbad0 {
    virtual ~FUN_009491e0();
    void FUN_008f7ef0();
};
FUN_009491e0::~FUN_009491e0() {
    FUN_008f7ef0();
    --DAT_011691b0;
}
}

}   // namespace f3m_009491e0

// @f3 0x00954f40 (community match, verified in this file)
namespace f3m_00954f40 {
class FUN_00954f40_cls {
public:
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void* m_10;
    unsigned int unk14;
    unsigned int unk18;
    int* m_1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_28;
    unsigned char m_29;
    void FUN_00954f40(int* p);
};

void __cdecl FUN_009234e0(void* dst, int value, unsigned int size);

// @fnv 0x00954f40
// pdb: hkaPose::setPoseModelSpace | hkaPose.obj | fnv360_0822_retail, objrun_open, low
// pdb params: poseModel
void FUN_00954f40_cls::FUN_00954f40(int* p)
{
    void** vt = *(void***)this;
    int count = *(int*)((char*)vt + 0x10);
    FUN_009234e0(m_10, *p, (unsigned int)(count * 3 * 16));
    int i = 0;
    unsigned char zero = 0;
    if (count > 0) {
        do {
            m_1c[i] = 1;
            ++i;
        } while (i < count);
    }
    *(volatile unsigned char*)&m_29 = zero;
    *(volatile unsigned char*)&m_28 = 1;
}

}   // namespace f3m_00954f40

// @f3 0x009597d0 (community match, verified in this file)
namespace f3m_009597d0 {
namespace n9597d0 {
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize);
template <class T> inline void copyBackwards(T* dst, const T* src, int n)
{
    for (int i = n - 1; i >= 0; --i)
        dst[i] = src[i];
}
}
struct FUN_009597d0_c {
    short* data;
    int size;
    int capAndFlags;
    void FUN_009597d0(int index, const short* p, int numToInsert);
};
void FUN_009597d0_c::FUN_009597d0(int index, const short* p, int numToInsert)
{
    const int newSize = size + numToInsert;
    const int numToMove = size - index;
    int cap = capAndFlags & 0x3fffffff;
    if (cap < newSize) {
        int cap2 = 2 * cap;
        int newCap = (newSize < cap2) ? cap2 : newSize;
        n9597d0::FUN_00901e90(this, newCap, sizeof(short));
    }
    n9597d0::copyBackwards(data + index + numToInsert, data + index, numToMove);
    n9597d0::copyBackwards(data + index, p, numToInsert);
    size = newSize;
}
}   // namespace f3m_009597d0

// @f3 0x009511e0 (community match, verified in this file)
struct StrArr
{
    unsigned field0, field4;
    unsigned short m8;
    unsigned short mA;
    unsigned short fieldC;
    unsigned short mE;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
void __stdcall FUN_0090c5a0(StrArr*);
char* FUN_00847b50(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 DAT_0116924c;
// @fnv 0x00bc28f0
// pdb: bhkConvexVerticesShape::GetViewerStrings | bhkConvexVerticesShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apStrings
void __stdcall FUN_009511e0(StrArr* pStrArr)
{
    FUN_0090c5a0(pStrArr);
    char* pStr = FUN_00847b50(DAT_0116924c.f0);
    unsigned int uiIndex = pStrArr->mA;
    unsigned int cnt = pStrArr->m8;
    if (uiIndex >= cnt)
    {
        pStrArr->FUN_00555790(pStrArr->mE + uiIndex);
    }
    pStrArr->FUN_005b3880(uiIndex, pStr);
}

// @f3 0x00945d50 (community match, verified in this file)
extern const char* DAT_01169154;
namespace f3m_00945d50 {
namespace Task0919 {
struct StrArr {
 void* vtable;char** data;unsigned short capacity,size,effective,grow;
 void FUN_00555790(unsigned int);void FUN_005b3880(unsigned int,char*&);
};
void __stdcall FUN_0090db50(StrArr*);
char* FUN_00847b50(const char*);
// pdb: bhkCachingShapePhantom::GetViewerStrings | bhkCachingShapePhantom.obj | fnv360_0822_retail, objrun, medium
// pdb params: apStrings
void __stdcall FUN_00945d50(StrArr* array) {
 FUN_0090db50(array);
 char* str=FUN_00847b50(DAT_01169154);
 unsigned int index=array->size;
 unsigned int count=array->capacity;
 if(index>=count) array->FUN_00555790(array->grow+index);
 array->FUN_005b3880(index,str);
}
}
}   // namespace f3m_00945d50

// @f3 0x0094e550 (community match, verified in this file)
extern const char* DAT_01169214;
namespace f3m_0094e550 {
struct StringArray918 {
    unsigned int unk00, unk04;
    unsigned short capacity, size, unk0c, growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
void __stdcall FUN_0090c5a0(StringArray918*);
char* __cdecl FUN_00847b50(const char*);
// pdb: bhkTriangleShape::GetViewerStrings | bhkTriangleShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apStrings
void __stdcall FUN_0094e550(StringArray918* array)
{
    FUN_0090c5a0(array);
    char* str = FUN_00847b50(DAT_01169214);
    unsigned int index = array->size;
    unsigned int count = array->capacity;
    if (index >= count) array->FUN_00555790(array->growBy + index);
    array->FUN_005b3880(index, str);
}
}   // namespace f3m_0094e550

// @f3 0x00942690 (community match, verified in this file)
namespace f3m_00942690 {
namespace n942690 {
struct Thread { void FUN_00984aa0(void (__cdecl* fn)(void*), void* arg); };
void __cdecl FUN_00942350(void* arg);
}
struct FUN_00942690_c;
namespace n942690 {
struct Job { FUN_00942690_c* owner; int pad4; Thread thread; char padc[0x18 - 0xc]; int index; char pad1c[0x30 - 0x1c]; };
}
struct FUN_00942690_c {
    char pad[0x28];
    n942690::Job jobs[6];
    int numJobs;
    void FUN_00941fa0(int a);
    void FUN_009421d0();
    void FUN_00942690(int a, int n);
};
void FUN_00942690_c::FUN_00942690(int a, int n)
{
    FUN_00941fa0(a);
    if (n > 6)
        n = 6;
    for (int i = 0; i < n; i++) {
        n942690::Job* j = &jobs[numJobs++];
        j->owner = this;
        j->index = i;
        j->thread.FUN_00984aa0(n942690::FUN_00942350, j);
    }
    FUN_009421d0();
}
}   // namespace f3m_00942690

// @f3 0x00943a00 (community match, verified in this file)
namespace f3m_00943a00 {
namespace n943a00 {
struct RefObj {
    unsigned short memSize;
    short refCount;
    RefObj() : refCount(1) {}
    virtual ~RefObj();
    void addReference() { if (memSize != 0) ++refCount; }
};
}
struct FUN_00943a00 : n943a00::RefObj {
    n943a00::RefObj* obj;
    FUN_00943a00(n943a00::RefObj* p);
    virtual ~FUN_00943a00();
};
// pdb: hkOstream::hkOstream | hkOStream.obj | fnv360_0822_retail, call_gap, high
// pdb params: sw
FUN_00943a00::FUN_00943a00(n943a00::RefObj* p) : obj(p)
{
    if (p)
        p->addReference();
}
}   // namespace f3m_00943a00

// @f3 0x0094e5e0 (community match, verified in this file)
extern int DAT_0116921c;
namespace f3m_0094e5e0 {
struct FUN_0094e5e0_Obj {
    void* unk00;

    FUN_0094e5e0_Obj* __thiscall FUN_0094e5e0(unsigned char flag);
};

extern "C" void FUN_00e7b39c();

void __cdecl FUN_009e28c0();
void __cdecl FUN_0089ec10(FUN_0094e5e0_Obj* obj, int value);

// pdb: bhkHeightFieldShape::`scalar deleting destructor' | bhkPlaneShape.obj | fnv360_0822_retail, caller_sim, low
FUN_0094e5e0_Obj* __thiscall FUN_0094e5e0_Obj::FUN_0094e5e0(unsigned char flag)
{
    unk00 = (void*)&FUN_00e7b39c;
    DAT_0116921c = DAT_0116921c - 1;
    FUN_009e28c0();
    if ((flag & 1) != 0) {
        FUN_0089ec10(this, 0x14);
    }
    return this;
}
}   // namespace f3m_0094e5e0

// @f3 0x00951b50 (community match, verified in this file)
namespace f3m_00951b50 {
namespace task0969 {
struct CTarget
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual bool vf0D0(int value);
};

struct CLevel2
{
    int unk00;
    int unk04;
    CTarget* unk08;
};

struct CLevel1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    CLevel2* unk18;
};

struct CObj
{
    int unk00;
    int unk04;
    CLevel1* unk08;

    bool __thiscall FUN_00951b50(int value);
};

bool __stdcall FUN_008f7650(void* value);

inline bool Walk(CObj* o, int v, bool r)
{
    if (o)
    {
        CLevel1* l = o->unk08;
        if (l)
        {
            CLevel2* l2 = l->unk18;
            if (l2)
            {
                CTarget* t = l2->unk08;
                if (t)
                    r = t->vf0D0(v);
            }
        }
    }
    return r;
}
// @fnv 0x00c8c3d0
// pdb: bhkConvexTransformShape::CreateClone | bhkConvexTransformShape.obj | fnv360_0721_retail, objrun, medium
// pdb params: arCloneData
bool __thiscall CObj::FUN_00951b50(int value)
{
    bool r = FUN_008f7650((void*)value);
    if (r)
        r = Walk(this, value, r);
    return r;
}


}
}   // namespace f3m_00951b50

// @f3 0x00947ee0 (community match, verified in this file)
namespace f3m_00947ee0 {
class B_00947ee0 { public: virtual void v0(); int a4, a8, ac, a10; B_00947ee0() { a4 = 0; ac = 0; a10 = 0; a8 = 1; } };
class FUN_00947ee0 : public B_00947ee0 { public: FUN_00947ee0(); virtual void v0(); };
FUN_00947ee0::FUN_00947ee0() {}
}   // namespace f3m_00947ee0

// @f3 0x00948b40 (community match, verified in this file)
namespace f3m_00948b40 {
class B_00948b40 { public: virtual void v0(); int a4, a8, ac, a10; B_00948b40() { a4 = 0; ac = 0; a10 = 0; a8 = 1; } };
class FUN_00948b40 : public B_00948b40 { public: FUN_00948b40(); virtual void v0(); };
// pdb: bhkWheelConstraint::CreateObject | bhkWheelConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00948b40::FUN_00948b40() {}
}   // namespace f3m_00948b40

// @f3 0x0094b680 (community match, verified in this file)
namespace f3m_0094b680 {
class B_0094b680 { public: virtual void v0(); int a4, a8, ac, a10; B_0094b680() { a4 = 0; ac = 0; a10 = 0; a8 = 1; } };
class FUN_0094b680 : public B_0094b680 { public: FUN_0094b680(); virtual void v0(); };
FUN_0094b680::FUN_0094b680() {}
}   // namespace f3m_0094b680

// @f3 0x00951300 (community match, verified in this file)
namespace f3m_00951300 {
namespace task951300 {
struct Heap { void FUN_0086ba60(void*); }; extern Heap DAT_01090a78;
struct Item { void FUN_00950d10(); };
struct Owner { int unk00,unk04,unk08; Item* unk0c; void FUN_00951300(bool); };
// pdb: hkGeometry::hkGeometry | bhkConvexVerticesShape.obj | fnv360_0822_retail, objrun, medium
void Owner::FUN_00951300(bool clear) {
 if (clear) { Item* item=unk0c; if (item) { item->FUN_00950d10(); DAT_01090a78.FUN_0086ba60(item); } unk0c=0; }
}
}
}   // namespace f3m_00951300

// @f3 0x00946320 (community match, verified in this file)
namespace f3m_00946320 {
// FUN_00946320 -- lazily create the child object, aligned-allocate 0x40 bytes.

namespace f3m_00946320 {

inline void* AlignedAlloc_946320(unsigned int size)
{
    unsigned char* memory = (unsigned char*)DAT_01090a78.FUN_0086b930(size + 16);
    unsigned char pad = (unsigned char)(16 - ((unsigned char)(unsigned int)memory & 0xf));
    memory += pad;
    memory[-1] = pad;
    return memory;
}

struct Owner_946320 {
    int unk00;
    int unk04;
    int unk08;
    f3m_009462c0::FUN_009462c0_cls* unk0C;
    void FUN_00945ea0(f3m_009462c0::FUN_009462c0_cls* child);
    f3m_009462c0::FUN_009462c0_cls* FUN_00946320(bool* pbCreated);
};

// pdb: bhkSpringAction::KillCinfo | bhkSpringAction.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: abCreated
f3m_009462c0::FUN_009462c0_cls* Owner_946320::FUN_00946320(bool* pbCreated)
{
    if (!unk0C) {
        unk0C = ((f3m_009462c0::FUN_009462c0_cls*)AlignedAlloc_946320(0x40))->FUN_009462c0();
        if (unk08)
            FUN_00945ea0(unk0C);
        *pbCreated = true;
    } else {
        *pbCreated = false;
    }
    return unk0C;
}
}
}   // namespace f3m_00946320

// @f3 0x00954fc0 (community match, verified in this file)
namespace f3m_00954fc0 {
namespace task1017 {
struct Shared {unsigned field0,field4,field8,fieldc; int count;};
struct Owner {Shared* shared; unsigned field4,field8,fieldc,value10,field14,field18; int* flags; unsigned field20,field24; unsigned char byte28,byte29; void* FUN_00954fc0();};
// pdb: hkaPose::accessUnsyncedPoseModelSpace | hkaPose.obj | fnv360_0822_retail, call_gap_sim, low
void* Owner::FUN_00954fc0() {int count=shared->count; for(int i=0;i<count;++i) flags[i]=1; byte29=0; byte28=1; return &value10;}
}
}   // namespace f3m_00954fc0

// @f3 0x00958030 (community match, verified in this file)
namespace f3m_00958030 {
namespace task1070 {
struct Member{int unk00;void FUN_004e5c20();};
struct Item{int unk00,unk04,unk08,unk0c;Member member;int unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;};
void __cdecl FUN_00958030(Item* items,int n){for(int i=0;i<n;++i)items[i].member.FUN_004e5c20();}
}
}   // namespace f3m_00958030

// @f3 0x00952320 (community match, verified in this file)
namespace f3m_00952320 {
namespace task1085{
struct Target{
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
virtual void Tail(int,int);};
struct Object{int unk00,unk04;Target* target;void FUN_00952320(int,int);};
// pdb: bhkConvexListShape::GetSupportingVertex | bhkConvexListShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: arDir, arSupportingVertexOut
void Object::FUN_00952320(int a,int b){if(this){Target* p=target;if(p)p->Tail(a,b);}}
}
}   // namespace f3m_00952320

// @f3 0x009445b0 (community match, verified in this file)
namespace f3m_009445b0 {
namespace Task1020 {
struct Entry {void* data;int unk04;};
struct Owner {
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
 Entry* entries;int count;
};
void FUN_009985d0(void*,void*);
// pdb: hkpWorldAgentUtil::invalidateTim | hkpWorldAgentUtil.obj | tesv_win, call_gap, low
void FUN_009445b0(Owner* owner,void* context){
 for(int i=0;i<owner->count;++i) FUN_009985d0(owner->entries[i].data,context);
}
}
}   // namespace f3m_009445b0

// @f3 0x009543e0 (community match, verified in this file)
extern char DAT_00e3277c; extern char DAT_01169984;
namespace f3m_009543e0 {
struct S_009543e0 { void FUN_00953550(int a, void* p, void* q); };
struct O_009543e0 { char pad[0x80]; void FUN_009543e0(int a); };
// pdb: hkpPhysicsContext::actionAddedCallback | hkpPhysicsContext.obj | fnv360_0822_retail, vtable, medium
// pdb params: action
void O_009543e0::FUN_009543e0(int a) { S_009543e0* s = *(S_009543e0**)((char*)this - 0x5c); if (s) s->FUN_00953550(a, &DAT_01169984, &DAT_00e3277c); }
}   // namespace f3m_009543e0

// @f3 0x00954310 (community match, verified in this file)
extern char DAT_00e32764; extern char DAT_011698e4;
namespace f3m_00954310 {
struct S_00954310 { void FUN_00953550(int a, void* p, void* q); };
struct O_00954310 { char pad[0x80]; void hkpPhysicsContext_entityAddedCallback(int a); };
// pdb: hkpPhysicsContext::entityAddedCallback | hkpPhysicsContext.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|vtable), high
void O_00954310::hkpPhysicsContext_entityAddedCallback(int a) { S_00954310* s = *(S_00954310**)((char*)this - 0x50); if (s) s->FUN_00953550(a, &DAT_011698e4, &DAT_00e32764); }
}   // namespace f3m_00954310

// @f3 0x00954340 (community match, verified in this file)
extern char DAT_00e32744; extern char DAT_01169914;
namespace f3m_00954340 {
struct S_00954340 { void FUN_00953550(int a, void* p, void* q); };
struct O_00954340 { char pad[0x80]; void FUN_00954340(int a); };
// pdb: hkpPhysicsContext::phantomAddedCallback | hkpPhysicsContext.obj | fnv360_0822_retail, vtable, medium
// pdb params: phantom
void O_00954340::FUN_00954340(int a) { S_00954340* s = *(S_00954340**)((char*)this - 0x54); if (s) s->FUN_00953550(a, &DAT_01169914, &DAT_00e32744); }
}   // namespace f3m_00954340

// @f3 0x0094ce00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0094ce00 {
extern "C" void _ReadWriteBarrier(void);
namespace n94ce00 {
struct Stream {
    int m00;
    int pos;
    int (__cdecl* read)(Stream* s, void* buf, int size, int a, int b);
};
struct Loader {
    char pad[0x1e5];
    unsigned char sameEndian;
    char pad2[0x24c - 0x1e6];
    Stream* stream;
};
struct Data { char pad[0x20]; unsigned int v20[4]; unsigned int v30[4]; };
inline void Swap4(unsigned int* p)
{
    p[0] = _byteswap_ulong(p[0]); _ReadWriteBarrier();
    p[1] = _byteswap_ulong(p[1]); _ReadWriteBarrier();
    p[2] = _byteswap_ulong(p[2]); _ReadWriteBarrier();
    p[3] = _byteswap_ulong(p[3]);
}
}
struct Block94ce00 {
    void* vtable;
    n94ce00::Data* data;
    void FUN_008fc580(n94ce00::Loader* l);
    void FUN_0094ce00(n94ce00::Loader* l);
};
void Block94ce00::FUN_0094ce00(n94ce00::Loader* l)
{
    FUN_008fc580(l);
    n94ce00::Data* d = data;
    n94ce00::Stream* s = l->stream;
    s->pos += s->read(s, d->v20, 0x10, 0, 0);
    s = l->stream;
    s->pos += s->read(s, d->v30, 0x10, 0, 0);
    if (l->sameEndian != 1) {
        n94ce00::Swap4(d->v20);
        n94ce00::Swap4(d->v30);
    }
}
}   // namespace f3m_0094ce00

// @f3 0x00951b90 (community match, verified in this file)
namespace f3m_00951b90 {
namespace f3m_00951b90 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
void __cdecl FUN_00951b90(f3m_00951b90::P* p) { f3m_00951b90::T* t = (f3m_00951b90::T*)f3m_00951b90::DAT_00d9b080(f3m_00951b90::DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x27); }
}   // namespace f3m_00951b90

// @f3 0x00943b80 (community match, verified in this file)
namespace f3m_00943b80 {
struct P_943b80 { int a, b; };
struct T_943b80 { virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3(); virtual void v4(int a, int b); };
struct O_943b80 { int u0, u4; T_943b80* t; O_943b80* FUN_00943b80(const P_943b80* p); };
// pdb: hkOstream::operator<< | hkOStream.obj | tesv_win, call_gap, low
O_943b80* O_943b80::FUN_00943b80(const P_943b80* p) { t->v4(p->a, p->b - 1); return this; }
}   // namespace f3m_00943b80

// @f3 0x00952190 (community match, verified in this file)
namespace n952190 {
struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;
extern float DAT_00f7a690;
extern const float DAT_00db8d0c;
extern const float DAT_00db954c;
struct Data {
    int m00;
    float m04;
    int m08;
    float m0c;
    float m10;
    Data() : m00(0), m04(DAT_00f7a690), m08(0), m0c(DAT_00db8d0c), m10(DAT_00db954c) {}
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};
}
struct Holder952190 {
    int m00, m04, m08;
    n952190::Data* data;
    n952190::Data* FUN_00952190(bool* created);
};
n952190::Data* Holder952190::FUN_00952190(bool* created)
{
    if (!data) {
        data = new n952190::Data;
        *created = true;
    } else {
        *created = false;
    }
    return data;
}

// @f3 0x00954b30 (community match, verified in this file)
namespace n954b30 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
}
struct C954b30 {
    void* vtbl;
    unsigned short memSize;
    short refCount;
    void FUN_00954940();
    C954b30* FUN_00954b30(unsigned int flags);
};
// pdb: hkpPhysicsContext::`scalar deleting destructor' | hkpPhysicsContext.obj | fnv360_0822_retail, vtable, medium
C954b30* C954b30::FUN_00954b30(unsigned int flags)
{
    FUN_00954940();
    if (flags & 1) {
        n954b30::Alloc* a = n954b30::FUN_00d9b080(n954b30::DAT_010f3170);
        a->FUN_008f6d90(this, memSize, 0x35);
    }
    return this;
}

// @f3 0x00946ea0 (community match, verified in this file)
#include <intrin.h>
namespace f3m_00946ea0 {
namespace task1158 {
struct Object {
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
unsigned char unk1e4,flag;};
struct Output {
unsigned long f00;
unsigned long f04;
unsigned long f08;
unsigned long f0c;
unsigned long f10;
unsigned long f14;
unsigned long f18;
unsigned long f1c;
unsigned long f20;
unsigned long f24;
unsigned long f28;
unsigned long f2c;
unsigned long f30;
unsigned long f34;
};
void __stdcall FUN_008fb740(Object*);
struct Processor {
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
virtual Output* Get(Object**);void FUN_00946ea0(Object*);};
// pdb: bhkDashpotAction::LoadBinary | bhkDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: arStream
void Processor::FUN_00946ea0(Object* obj){Object* o=*(Object* volatile*)&obj;FUN_008fb740(o);if(o->flag!=1){Output* p=Get(&obj);if(p){
p->f10=_byteswap_ulong(p->f10);_ReadWriteBarrier();
p->f14=_byteswap_ulong(p->f14);_ReadWriteBarrier();
p->f18=_byteswap_ulong(p->f18);_ReadWriteBarrier();
p->f1c=_byteswap_ulong(p->f1c);_ReadWriteBarrier();
p->f20=_byteswap_ulong(p->f20);_ReadWriteBarrier();
p->f24=_byteswap_ulong(p->f24);_ReadWriteBarrier();
p->f28=_byteswap_ulong(p->f28);_ReadWriteBarrier();
p->f2c=_byteswap_ulong(p->f2c);_ReadWriteBarrier();
p->f30=_byteswap_ulong(p->f30);_ReadWriteBarrier();
p->f34=_byteswap_ulong(p->f34);_ReadWriteBarrier();
}}}
}
}   // namespace f3m_00946ea0

// @f3 0x00947580 (community match, verified in this file)
namespace f3m_00947580 {
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
namespace Task1175 {
struct Context {
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
unsigned unk12c;
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
unsigned char unk1e4,byteOrder1e5;
};
struct Data {
unsigned long value00;
unsigned long value04;
unsigned long value08;
unsigned long value0c;
unsigned long value10;
unsigned long value14;
unsigned long value18;
unsigned long value1c;
unsigned long value20;
unsigned long value24;
};
struct Reader {
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
virtual Data* Get(Context**);
 void FUN_008fb740(Context*);
 void FUN_00947580(Context*);
};
// pdb: bhkAngularDashpotAction::LoadBinary | bhkAngularDashpotAction.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arStream
void Reader::FUN_00947580(Context* volatile context) {
 Context* original=context;
 FUN_008fb740(original);
 if(original->byteOrder1e5!=1) {
  volatile Data* p=Get((Context**)&context);
  if(p) {
p->value10=_byteswap_ulong(p->value10);
p->value14=_byteswap_ulong(p->value14);
p->value18=_byteswap_ulong(p->value18);
p->value1c=_byteswap_ulong(p->value1c);
p->value20=_byteswap_ulong(p->value20);
p->value24=_byteswap_ulong(p->value24);
  }
 }
}
}
}   // namespace f3m_00947580

// @f3 0x00943480 (community match, verified in this file)
namespace f3m_00943480 {
namespace f3m_00943480 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00943480 { char pad[4]; unsigned short w; void FUN_008d34a0(); O00943480* FUN_00943480(unsigned int flags); };
// pdb: bhkCollisionFilter::`scalar deleting destructor' | bhkWorld.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
O00943480* O00943480::FUN_00943480(unsigned int flags) { FUN_008d34a0(); if (flags & 1) { f3m_00943480::T* t = (f3m_00943480::T*)f3m_00943480::DAT_00d9b080(f3m_00943480::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_00943480

// @f3 0x00947bb0 (community match, verified in this file)
namespace f3m_00947bb0 {
namespace f3m_00947bb0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O00947bb0 { char pad[4]; unsigned short w; void FUN_009dad50(); O00947bb0* FUN_00947bb0(unsigned int flags); };
// pdb: hkpBreakableConstraintData::`scalar deleting destructor' | hkpBreakableConstraintData.obj | fnv360_0822_retail, vtable_prefix, medium
O00947bb0* O00947bb0::FUN_00947bb0(unsigned int flags) { FUN_009dad50(); if (flags & 1) { f3m_00947bb0::T* t = (f3m_00947bb0::T*)f3m_00947bb0::DAT_00d9b080(f3m_00947bb0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2c); } return this; }
}   // namespace f3m_00947bb0

// @f3 0x0094dab0 (community match, verified in this file)
namespace f3m_0094dab0 {
namespace f3m_0094dab0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O0094dab0 { char pad[4]; unsigned short w; void FUN_009e22e0(); O0094dab0* FUN_0094dab0(unsigned int flags); };
// pdb: hkScaledMoppBvTreeShape::`scalar deleting destructor' | bhkMoppBvTreeShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: bhkCompressedMeshShape::SetWeldingType)
O0094dab0* O0094dab0::FUN_0094dab0(unsigned int flags) { FUN_009e22e0(); if (flags & 1) { f3m_0094dab0::T* t = (f3m_0094dab0::T*)f3m_0094dab0::DAT_00d9b080(f3m_0094dab0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_0094dab0

// @f3 0x00951970 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00951970 {
struct C8C260Block
{
    int unk00;
    int m_flags;
    int unk08;
    int unk0C;
    int m_kHeader[16];
};

void __cdecl FUN_008fdad0(int* header);

inline void C8C260Swap32(unsigned int* p)
{
    *p = _byteswap_ulong(*p);
}

struct C8C260Renderer
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void SetTarget(void* target);

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
    unsigned char m_ucLittleEndian;
};

inline void C8C260Prepare(C8C260Block* block, C8C260Renderer* pkRenderer)
{
    if (block && pkRenderer->m_ucLittleEndian != 1)
    {
        int* header = block->m_kHeader;
        C8C260Swap32((unsigned int*)(header + 12));
        C8C260Swap32((unsigned int*)(header + 13));
        C8C260Swap32((unsigned int*)(header + 14));
        C8C260Swap32((unsigned int*)(header + 15));
        FUN_008fdad0(header);
    }
}

struct C8C260Inner
{
    int unk00;
    int unk04;
    void* m_target;
};

struct C8C260Link
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    C8C260Inner* m_inner;
};

struct C8C260Shader
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual C8C260Block* GetBlock(bool* pbCreated);

    int unk04;
    C8C260Link* m_link;

    void bhkConvexShape_SaveBinary(C8C260Renderer* pkRenderer);
    void FUN_00951970(C8C260Renderer* pkRenderer);
};

inline void* C8C260GetTarget(C8C260Shader* p)
{
    return (p && p->m_link && p->m_link->m_inner) ? p->m_link->m_inner->m_target : 0;
}

// @fnv 0x00c8c260
// pdb: bhkConvexTransformShape::SaveBinary | bhkConvexTransformShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void C8C260Shader::FUN_00951970(C8C260Renderer* pkRenderer)
{
    pkRenderer->SetTarget(C8C260GetTarget(this));
    bool bCreated;
    C8C260Block* pkBlock = GetBlock(&bCreated);
    C8C260Prepare(pkBlock, pkRenderer);
    bhkConvexShape_SaveBinary(pkRenderer);
    C8C260Prepare(pkBlock, pkRenderer);
}

}   // namespace f3m_00951970

// @f3 0x00942800 (community match, verified in this file)
namespace f3m_00942800 {
namespace task942800 {
struct Small { int unk00; void FUN_009b4a30(); };
struct Item { int unk00,unk04,unk08,unk0c,unk10,unk14; Small part; int unk1c,unk20,unk24,unk28,unk2c; void FUN_00984b30(); };
struct Owner { int unk00,unk04,unk08; Small a,b,c,d,e,f; int unk24,unk28,unk2c; Item entries[6]; void FUN_00942800(); };
void Owner::FUN_00942800() {
 int i=5;
 Item* current=entries+6;
 for(;i>=0;i--) { --current; current->part.FUN_009b4a30(); current->FUN_00984b30(); }
 f.FUN_009b4a30();e.FUN_009b4a30();d.FUN_009b4a30();c.FUN_009b4a30();b.FUN_009b4a30();a.FUN_009b4a30();
}
}
}   // namespace f3m_00942800

// @f3 0x00951c10 (community match, verified in this file)
namespace f3m_00951c10 {
namespace n951c10 {
struct Child {
    char data[0x50];
    Child();
};
}
class C951c10 {
public:
    int unk00;
    int unk04;
    int parent08;
    n951c10::Child* child0C;
    void FUN_00951700(n951c10::Child* c);
    n951c10::Child* FUN_00951c10(bool* pbCreated);
};
// pdb: bhkConvexTransformShape::RembhkShapeRef | bhkConvexTransformShape.obj | fnv360_0721_retail, objrun, medium
n951c10::Child* C951c10::FUN_00951c10(bool* pbCreated)
{
    if (!child0C) {
        child0C = new (f3m_0094ebf0::AlignedAlloc_ebf0(0x50), 0) n951c10::Child();
        if (parent08)
            FUN_00951700(child0C);
        *pbCreated = true;
    } else {
        *pbCreated = false;
    }
    return child0C;
}
}   // namespace f3m_00951c10

// @f3 0x009524a0 (community match, verified in this file)
namespace f3m_009524a0 {
struct FUN_00c84df0_cls;

namespace f3m_009524a0 {

struct Container;

struct Entry {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual Entry* Resolve(void* arg);
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual bool Skip(void* arg);
    int unk04;
    Entry* m08;
};

struct Container {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Entry** m10;
    int m14;
};

}

using namespace f3m_009524a0;

struct FUN_00c84df0_cls {
    void bhkShape_CopyMembers(FUN_00c84df0_cls* a1, FUN_00c84df0_cls* a2);
};

struct FUN_009524a0_cls {
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
    virtual void v44();
    virtual Container* GetContainer(char* p);
    void FUN_009524a0(void* a1, void* a2);
};

// pdb: bhkConvexListShape::CopyMembers | bhkConvexListShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apDest, arCloneData
void FUN_009524a0_cls::FUN_009524a0(void* a1, void* a2)
{
    char buf;
    Container* c = GetContainer(&buf);
    if (c != 0) {
        for (int i = 0; i < c->m14; ++i) {
            Entry* e = c->m10[i];
            if (e == 0) continue;
            Entry* sub = e->m08;
            if (sub == 0) continue;
            if (sub->Skip(a2)) continue;
            Entry* r = sub->Resolve(a2);
            c->m10[i] = (r != 0) ? r->m08 : 0;
        }
    }
    ((FUN_00c84df0_cls*)this)->bhkShape_CopyMembers((FUN_00c84df0_cls*)a1, (FUN_00c84df0_cls*)a2);
}
}   // namespace f3m_009524a0

// @f3 0x00942130 (community match, verified in this file)
namespace f3m_00942130 {
struct Guard023e0 {
    void hkpWorld_checkDeterminism();
};

struct Owner {
    Guard023e0* unk00;
    void FUN_00942000(float a, int b);
    void FUN_00942060();
    void FUN_00942130(float a, int b);
};

void Owner::FUN_00942130(float a, int b)
{
    unk00->hkpWorld_checkDeterminism();
    FUN_00942000(a, b);
    FUN_00942060();
    unk00->hkpWorld_checkDeterminism();
}
}   // namespace f3m_00942130

// @f3 0x00951850 (community match, verified in this file)
namespace f3m_00951850 {
namespace f3m_00951850 {

class FUN_00c84df0_cls;

class FUN_00c84df0_cls {
public:
    void bhkShape_CopyMembers(FUN_00c84df0_cls* a, FUN_00c84df0_cls* b);
};

struct Arg2_951850;
struct Holder_951850;
struct Mid_951850;
struct Node_951850;

struct Sub_951850 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual Holder_951850* v18(Arg2_951850* a);
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual bool v51(Arg2_951850* a);
};

struct Mid_951850 {
    int unk00;
    int unk04;
    Sub_951850* m_pSub08;
};

struct Holder_951850 {
    int unk00;
    int unk04;
    Mid_951850* m_pMid08;
};

struct Node_951850 {
    int unk00;
    int unk04;
    Mid_951850* m_pMid08;
    int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30;
    int unk34; int unk38; int unk3C;
    float m_f40;
    float m_f44;
    float m_f48;
    float m_f4C;
};

struct Arg2_951850 {
    int unk00; int unk04; int unk08; int unk0C;
    float m_f10;
};

struct FUN_00951850_cls {
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
    virtual void v44();
    virtual Node_951850* v45(bool* pbFlag);
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    void FUN_00951850(FUN_00951850_cls* a1, Arg2_951850* a2);
};

void FUN_00951850_cls::FUN_00951850(FUN_00951850_cls* a1, Arg2_951850* a2)
{
    bool bFlag;
    Node_951850* pNode = v45(&bFlag);
    if (pNode != 0) {
        Mid_951850* pMid = pNode->m_pMid08;
        Sub_951850* pSub = (pMid != 0) ? pMid->m_pSub08 : 0;
        float fScale = a2->m_f10;
        if (fScale != 1.0f) {
            pNode->m_f40 = pNode->m_f40 * fScale;
            pNode->m_f44 = pNode->m_f44 * fScale;
            pNode->m_f48 = pNode->m_f48 * fScale;
            pNode->m_f4C = pNode->m_f4C * fScale;
        } else {
            if (pSub == 0 || pSub->v51(a2)) {
                goto done;
            }
        }
        {
            Holder_951850* pRes = pSub->v18(a2);
            pNode->m_pMid08 = (pRes != 0) ? pRes->m_pMid08 : 0;
        }
    }
done:
    ((FUN_00c84df0_cls*)this)->bhkShape_CopyMembers((FUN_00c84df0_cls*)a1, (FUN_00c84df0_cls*)a2);
}

}
}   // namespace f3m_00951850

// @f3 0x00951900 (community match, verified in this file)
#include <intrin.h>
#pragma intrinsic(_byteswap_ulong)
#pragma intrinsic(_ReadWriteBarrier)
namespace f3m_00951900 {

struct Stream951900 {
    char pad[0x1e5];
    unsigned char flag;
    void FUN_0082b560();
};
struct Result951900 {
    int unk00, unk04, count08, unk0c;
};
void __cdecl FUN_008fdad0(unsigned int* data);
struct Obj951900 {
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
    virtual void v43();
    virtual void v44();
    virtual Result951900* FUN_v45(Stream951900** stream);
    void FUN_0090c4f0(Stream951900* stream);
    void FUN_00951900(Stream951900* stream);
};

// pdb: bhkConvexTransformShape::LoadBinary | bhkConvexTransformShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Obj951900::FUN_00951900(Stream951900* stream)
{
    Stream951900* saved = stream;
    _ReadWriteBarrier();
    saved->FUN_0082b560();
    FUN_0090c4f0(saved);
    Result951900* result = FUN_v45(&stream);
    if (result) {
        result->count08 = 0;
        if (saved->flag != 1) {
            unsigned int* block = (unsigned int*)(result + 1);
            block[12] = _byteswap_ulong(block[12]);
            _ReadWriteBarrier();
            block[13] = _byteswap_ulong(block[13]);
            _ReadWriteBarrier();
            block[14] = _byteswap_ulong(block[14]);
            _ReadWriteBarrier();
            block[15] = _byteswap_ulong(block[15]);
            FUN_008fdad0(block);
        }
    }
}
}   // namespace f3m_00951900

// @f3 0x0094d280 (community match, verified in this file)
#include <intrin.h>
namespace f3m_0094d280 {

extern "C" void _ReadWriteBarrier(void);

struct BCA9D50Stream;

class BCA9D50Base
{
  public:
    void SaveBinary(BCA9D50Stream& kStream);
};

struct NiBinaryStreamB
{
    void* m_vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamB*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamB*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
        unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiAbsoluteCurrentPos += uiBytesWritten;
        return uiBytesWritten;
    }
};

struct BCA9D50Stream
{
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
    unsigned char m_ucEndian;
    unsigned char unk1e5;
    unsigned char unk1e6;
    unsigned char unk1e7;
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
    NiBinaryStreamB* m_pkOstr;
};

template <class T> inline void NiBinaryStreamSave(NiBinaryStreamB& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

struct Vector4B
{
    unsigned long m_ui0, m_ui4, m_ui8, m_uiC;

    void Swap()
    {
        m_ui0 = _byteswap_ulong(m_ui0); _ReadWriteBarrier();
        m_ui4 = _byteswap_ulong(m_ui4); _ReadWriteBarrier();
        m_ui8 = _byteswap_ulong(m_ui8); _ReadWriteBarrier();
        m_uiC = _byteswap_ulong(m_uiC);
    }
};

struct FrameB
{
    unsigned long m_ui00, m_ui04, m_ui08, m_ui0C, m_ui10, m_ui14, m_ui18, m_ui1C;

    void Swap()
    {
        m_ui00 = _byteswap_ulong(m_ui00); _ReadWriteBarrier();
        m_ui04 = _byteswap_ulong(m_ui04); _ReadWriteBarrier();
        m_ui08 = _byteswap_ulong(m_ui08); _ReadWriteBarrier();
        m_ui0C = _byteswap_ulong(m_ui0C); _ReadWriteBarrier();
        m_ui10 = _byteswap_ulong(m_ui10); _ReadWriteBarrier();
        m_ui14 = _byteswap_ulong(m_ui14); _ReadWriteBarrier();
        m_ui18 = _byteswap_ulong(m_ui18); _ReadWriteBarrier();
        m_ui1C = _byteswap_ulong(m_ui1C);
    }
};

struct DataB
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    FrameB m_kPair;
};

class SaveOwner : public BCA9D50Base
{
  public:
    int unk00;
    DataB* m_pkData;
    void FUN_0094d280(BCA9D50Stream& kStream);
};

void SaveOwner::FUN_0094d280(BCA9D50Stream& kStream)
{
    SaveBinary(kStream);
    DataB* pkData = m_pkData;
    if (kStream.m_ucEndian != 1)
    {
        pkData->m_kPair.Swap();
    }
    NiBinaryStreamSave(*kStream.m_pkOstr, (Vector4B*)&pkData->m_kPair.m_ui00, 1);
    NiBinaryStreamSave(*kStream.m_pkOstr, (Vector4B*)&pkData->m_kPair.m_ui10, 1);
    if (kStream.m_ucEndian != 1)
    {
        ((Vector4B*)&pkData->m_kPair.m_ui00)->Swap();
        ((Vector4B*)&pkData->m_kPair.m_ui10)->Swap();
    }
}
}   // namespace f3m_0094d280

// @f3 0x00950a60 (community match, verified in this file)
namespace f3m_00950a60 {
// FUN_00950a60: takes the shape lock, creates a RefObject20_b9084 (CDC40LevelB,
// ctor 0x00950990) and hands it to the host's virtual slot 0x00c0, then unlocks.
// The lock pair are the IAT slots 0x00d9b09c / 0x00d9b0a0 (Enter/LeaveCriticalSection).

struct CritSec {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

extern CritSec DAT_010f3194;                        // 0x010f3194 : the shape lock

extern void (__stdcall *DAT_00d9b09c)(void* pcs);   // 0x00d9b09c : EnterCriticalSection
extern void (__stdcall *DAT_00d9b0a0)(void* pcs);   // 0x00d9b0a0 : LeaveCriticalSection

class NiMemObject {
public:
    static void* operator new(unsigned int size);   // 0x0089eb90
};

class RefObject20_b9084 : public NiMemObject {
public:
    RefObject20_b9084();                            // 0x00950990
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class Host {
public:
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
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(RefObject20_b9084* obj, int arg);
    RefObject20_b9084* FUN_00950a60(int arg);
};

// pdb: bhkConvexVerticesShape::CreateObject | bhkConvexVerticesShape.obj | fnv360_0822_retail, objopen_prop, low, conflict (bridge: bhkConvexVerticesShape::CreateClone)
RefObject20_b9084* Host::FUN_00950a60(int arg)
{
    DAT_00d9b09c(&DAT_010f3194);
    RefObject20_b9084* p = new RefObject20_b9084();
    vC0(p, arg);
    DAT_00d9b0a0(&DAT_010f3194);
    return p;
}
}   // namespace f3m_00950a60

// @f3 0x00952410 (community match, verified in this file)
extern class _RTL_CRITICAL_SECTION DAT_010f3194;
namespace f3m_00952410 {
extern void (__stdcall* DAT_00d9b09c)(_RTL_CRITICAL_SECTION* pSection);
extern void (__stdcall* DAT_00d9b0a0)(_RTL_CRITICAL_SECTION* pSection);


namespace f3m_00952410 {

class FUN_00ccf890_t {
public:
    static void* operator new(unsigned int size);
    FUN_00ccf890_t();
    int m_00; int m_04; int m_08; int m_0c; int m_10;
};

struct Owner952410 {
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
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void Notify(FUN_00ccf890_t* pObject, int arg);
    FUN_00ccf890_t* FUN_00952410(int arg);
};

// pdb: bhkConvexListShape::CreateClone | bhkConvexListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
FUN_00ccf890_t* Owner952410::FUN_00952410(int arg)
{
    DAT_00d9b09c(&DAT_010f3194);
    FUN_00ccf890_t* p = new FUN_00ccf890_t();
    Notify(p, arg);
    DAT_00d9b0a0(&DAT_010f3194);
    return p;
}
}
}   // namespace f3m_00952410

// @f3 0x00952210 (community match, verified in this file)
namespace f3m_00952210 {
struct GuardObj {
    void __thiscall FUN_0086ba60(int value);
};

struct FUN_00952210_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void __thiscall FUN_00952210(char value);
};

// pdb: bhkConvexSweepShape::bhkConvexSweepShape | bhkConvexSweepShape.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: bhkAngularDashpotAction::KillCinfo)
void __thiscall FUN_00952210_cls::FUN_00952210(char value)
{
    if (value != 0) {
        ((GuardObj*)&DAT_01090a78)->FUN_0086ba60(unk0C);
        unk0C = 0;
    }
}
}   // namespace f3m_00952210

// @f3 0x0094df30 (community match, verified in this file)
namespace f3m_0094df30 {
namespace f3m_0094df30 {
struct Mat { float m[12]; };
struct Impl {
    int unk00, unk04, unk08, unk0c;
    float m_f10, m_f14, m_f18, m_f1c;
    Mat m_rot;
};
struct Out {
    int unk00;
    float m_f04;
    int unk08, unk0c;
    float m_f10, m_f14, m_f18, m_f1c;
    float m_f20, m_f24, m_f28, m_f2c;
    float m_f30, m_f34, m_f38, m_f3c;
};
struct Cls {
    int unk00, unk04;
    Impl* m08;
    void FUN_0090c4a0(Out* out);
    Mat* GetRot() { return (this && m08) ? &m08->m_rot : 0; }
    void FUN_0094df30(Out* out);
};
// pdb: bhkConvexTransformShape::CopyCinfo | bhkConvexTransformShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void Cls::FUN_0094df30(Out* out)
{
    FUN_0090c4a0(out);
    Mat* r = GetRot();
    if (!r) return;
    out->m_f10 = r->m[0];
    out->m_f14 = r->m[1];
    out->m_f18 = r->m[2];
    out->m_f1c = r->m[3];
    out->m_f20 = r->m[4];
    out->m_f24 = r->m[5];
    out->m_f28 = r->m[6];
    out->m_f2c = r->m[7];
    out->m_f30 = r->m[8];
    out->m_f34 = r->m[9];
    out->m_f38 = r->m[10];
    out->m_f3c = r->m[11];
}
}
}   // namespace f3m_0094df30

// @f3 0x0094d200 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094d200 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct MemoryContext94
{
    void* FUN_008f6d30(int iSize, int iCategory);
};

struct FUN_009e1b50
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08; int m_0c; int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c; int m_30; int m_34;
    int m_38; int m_3c; int m_40; int m_44; int m_48; int m_4c;
    static void* operator new(unsigned int uiSize)
    {
        MemoryContext94* pkContext = (MemoryContext94*)TlsGetValue(DAT_010f3170);
        void* pBlock = pkContext->FUN_008f6d30(uiSize, 0x2c);
        *(unsigned short*)((char*)pBlock + 4) = (unsigned short)uiSize;
        return pBlock;
    }
    FUN_009e1b50();
};

class C94D200
{
  public:
    void* m_00;
    void* m_04;

    int FUN_0094d200();
};

// pdb: hkBallAndSocketConstraintCinfo::CreateData | bhkBallAndSocketConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
int C94D200::FUN_0094d200()
{
    if (!m_04)
        m_04 = new FUN_009e1b50();
    return 0x50;
}
}   // namespace f3m_0094d200

// @f3 0x00951bb0 (community match, verified in this file)
#include <intrin.h>
#pragma intrinsic(_ReadWriteBarrier)
extern float DAT_010c72bc;
namespace f3m_00951bb0 {


struct FUN_00951bb0 {
    int unk00;
    float unk04;
    int unk08;
    int unk0c;
    float f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
    float f40, f44, f48, f4c;
    FUN_00951bb0();
};

// pdb: bhkConvexTransformShape::Init | bhkConvexTransformShape.obj | fnv360_0721_retail, objrun, medium
// pdb params: arInfo
FUN_00951bb0::FUN_00951bb0()
{
    unk00 = 0;
    unk04 = DAT_010c72bc;
    unk08 = 0;
    float z = 0.0f;
    f3c = f38 = f34 = f30 = f2c = f28 = f24 = f20 = f1c = f18 = f14 = f10 = z;
    _ReadWriteBarrier();
    float one = 1.0f;
    f38 = f24 = f10 = one;
    f40 = f44 = f48 = f4c = z;
}
}   // namespace f3m_00951bb0

// @f3 0x00942870 (community match, verified in this file)
// 0x00942870 -- pool allocation with a virtual fallback, under the global critical section.

extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(void* pcs);
extern "C" __declspec(dllimport) void __stdcall fnv_LeaveCriticalSection(void* pcs);

struct CriticalSection01169120 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

extern CriticalSection01169120 DAT_01169120;

struct FUN_00aa54a0_s {
    void* Allocate(unsigned int uiSize, unsigned int uiAlign);
};

struct Owner_942870 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void* vf0c(unsigned int a, unsigned int b);
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    int unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0;
    int unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
    int unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0;
    int unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100;
    int unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120;
    int unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140;
    int unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160;
    int unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180;
    int unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0;
    int unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0;
    int unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0;
    int unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200;
    int unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220;
    int unk224, unk228, unk22c, unk230, unk234, unk238, unk23c, unk240;
    int unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260;
    int unk264, unk268, unk26c, unk270, unk274, unk278, unk27c, unk280;
    int unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0;
    int unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc, unk2c0;
    int unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0;
    int unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc, unk300;
    int unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320;
    int unk324, unk328, unk32c, unk330, unk334, unk338, unk33c, unk340;
    int unk344, unk348, unk34c, unk350, unk354, unk358, unk35c, unk360;
    int unk364, unk368, unk36c, unk370, unk374, unk378, unk37c, unk380;
    int unk384, unk388, unk38c, unk390, unk394, unk398, unk39c, unk3a0;
    int unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc, unk3c0;
    int unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0;
    int unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc, unk400;
    int unk404, unk408, unk40c, unk410, unk414, unk418, unk41c, unk420;
    int unk424, unk428, unk42c, unk430, unk434, unk438, unk43c, unk440;
    int unk444, unk448, unk44c, unk450, unk454, unk458, unk45c, unk460;
    int unk464, unk468, unk46c, unk470, unk474, unk478, unk47c, unk480;
    int unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0;
    int unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc, unk4c0;
    int unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc, unk4e0;
    int unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc, unk500;
    int unk504, unk508, unk50c, unk510, unk514, unk518, unk51c, unk520;
    int unk524, unk528, unk52c, unk530, unk534, unk538, unk53c, unk540;
    int unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560;
    int unk564, unk568, unk56c, unk570, unk574, unk578, unk57c, unk580;
    int unk584, unk588, unk58c, unk590, unk594, unk598, unk59c, unk5a0;
    int unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc, unk5c0;
    int unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc, unk5e0;
    int unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc, unk600;
    int unk604, unk608, unk60c, unk610, unk614, unk618, unk61c, unk620;
    int unk624, unk628, unk62c, unk630, unk634, unk638, unk63c, unk640;
    int unk644, unk648, unk64c, unk650, unk654, unk658, unk65c, unk660;
    int unk664, unk668, unk66c, unk670, unk674, unk678, unk67c, unk680;
    int unk684, unk688, unk68c, unk690, unk694, unk698, unk69c, unk6a0;
    int unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc, unk6c0;
    int unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc, unk6e0;
    int unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc, unk700;
    int unk704, unk708, unk70c, unk710, unk714, unk718, unk71c, unk720;
    int unk724, unk728, unk72c, unk730, unk734, unk738, unk73c, unk740;
    int unk744, unk748, unk74c, unk750, unk754, unk758, unk75c, unk760;
    int unk764, unk768, unk76c, unk770, unk774, unk778, unk77c, unk780;
    int unk784, unk788, unk78c, unk790, unk794, unk798, unk79c, unk7a0;
    int unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc, unk7c0;
    int unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc, unk7e0;
    int unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc, unk800;
    int unk804, unk808, unk80c, unk810, unk814, unk818, unk81c, unk820;
    int unk824, unk828, unk82c, unk830, unk834, unk838, unk83c, unk840;
    int unk844, unk848, unk84c, unk850, unk854, unk858, unk85c, unk860;
    int unk864, unk868, unk86c, unk870, unk874, unk878, unk87c, unk880;
    int unk884, unk888, unk88c, unk890, unk894, unk898, unk89c, unk8a0;
    int unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc, unk8c0;
    int unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc, unk8e0;
    int unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc, unk900;
    int unk904, unk908, unk90c, unk910, unk914, unk918, unk91c, unk920;
    int unk924, unk928, unk92c, unk930, unk934, unk938, unk93c, unk940;
    int unk944, unk948, unk94c, unk950, unk954, unk958, unk95c, unk960;
    int unk964, unk968, unk96c, unk970, unk974, unk978, unk97c, unk980;
    int unk984, unk988, unk98c, unk990, unk994, unk998, unk99c, unk9a0;
    int unk9a4, unk9a8, unk9ac, unk9b0, unk9b4, unk9b8, unk9bc, unk9c0;
    int unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc, unk9e0;
    int unk9e4, unk9e8, unk9ec, unk9f0, unk9f4, unk9f8, unk9fc, unka00;
    int unka04, unka08, unka0c, unka10, unka14;
    FUN_00aa54a0_s m_alloc;

    void* FUN_00942870(unsigned int a, unsigned int b);
};

// pdb: ScrapMultiMap::AddAt | BSFaceGenMorph.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aiVertex, aiBaseIndex
void* Owner_942870::FUN_00942870(unsigned int a, unsigned int b)
{
    fnv_EnterCriticalSection(&DAT_01169120);
    void* p = m_alloc.Allocate(a, 4);
    if (!p)
        p = vf0c(a, b);
    fnv_LeaveCriticalSection(&DAT_01169120);
    return p;
}

// @f3 0x0095b9c0 (community match, verified in this file)
namespace f3m_0095b9c0 {
struct Vec4 { float x, y, z, w; };
struct Block128 {
    unsigned int word00;
    unsigned int word01;
    unsigned int word02;
    unsigned int word03;
    unsigned int word04;
    unsigned int word05;
    unsigned int word06;
    unsigned int word07;
    unsigned int word08;
    unsigned int word09;
    unsigned int word0a;
    unsigned int word0b;
    unsigned int word0c;
    unsigned int word0d;
    unsigned int word0e;
    unsigned int word0f;
    unsigned int word10;
    unsigned int word11;
    unsigned int word12;
    unsigned int word13;
    unsigned int word14;
    unsigned int word15;
    unsigned int word16;
    unsigned int word17;
    unsigned int word18;
    unsigned int word19;
    unsigned int word1a;
    unsigned int word1b;
    unsigned int word1c;
    unsigned int word1d;
    unsigned int word1e;
    unsigned int word1f;
};
extern unsigned char DAT_00e7c15c;
extern Vec4 DAT_01092a50;
struct Candidate {
    void* vtable;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08, unk0c;
    Block128 block;
    float value90, value94;
    unsigned int unk98, unk9c;
    Vec4 valuea0;
    float valueb0;
    unsigned char valueb4;
    unsigned char unkb5;
    unsigned short unkb6;
    unsigned int unkb8, unkbc;
    Vec4 valuec0, valued0, valuee0;
    Candidate(const Block128* source);
};
// pdb: hkaFootPlacementIkSolver::hkaFootPlacementIkSolver | hkaFootPlacementIkSolver.obj | fnv360_0822_retail, uvref, high
// pdb params: setup
Candidate::Candidate(const Block128* source) {
    unk06 = 1;
    vtable = &DAT_00e7c15c;
    block = *source;
    value90 = 0.0f;
    value94 = 0.0f;
    valuea0 = *(const Vec4*)((const char*)source + 0x30);
    valueb0 = 0.0f;
    valueb4 = 0;
    valuec0 = DAT_01092a50;
    valued0 = DAT_01092a50;
    valuee0 = DAT_01092a50;
}
}   // namespace f3m_0095b9c0

// @f3 0x00944de0 (community match, verified in this file)
namespace f3m_00944de0 {
struct NiObject {
    virtual ~NiObject();
    int m_uiRefCount;
};

struct MemoryManager {
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;

class NiFixedString {
public:
    void* m_kHandle;
    ~NiFixedString();
    void operator delete[](void* p) {
        g_memoryManager.Deallocate(p);
    }
};

struct PoseEntry {
    int unk00;
    void* unk04;
};

struct TlsManager {
    void FUN_008f6f90(void* p);
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;

struct FUN_00944de0 : public NiObject {
    unsigned int unk08;
    NiFixedString* m_pBoneNames;
    unsigned int m_uiCount;
    PoseEntry** m_pEntryData;

    virtual ~FUN_00944de0();
};

// pdb: bhkPoseArray::`scalar deleting destructor' | bhkPoseArray.obj | fnv360_0822_retail, objrun, medium
FUN_00944de0::~FUN_00944de0() {
    delete[] m_pBoneNames;
    if (m_pEntryData) {
        for (unsigned int i = 0; i < m_uiCount; ++i) {
            PoseEntry* item = m_pEntryData[i];
            if (item) {
                void* buffer = item->unk04;
                if (buffer) {
                    void* tls = TlsGetValue(DAT_010f3170);
                    ((TlsManager*)tls)->FUN_008f6f90(buffer);
                }
                g_memoryManager.Deallocate(item);
            }
        }
        void* releaseArray = m_pEntryData;
        g_memoryManager.Deallocate(releaseArray);
    }
}
}   // namespace f3m_00944de0

// @f3 0x0094bba0 (community match, verified in this file)
namespace f3m_0094bba0 {
struct Name { int unk00; };
struct Key { int unk00; int unk04; int unk08; int unk0c; };
struct Src { int unk00; int unk04; int unk08; Key* unk0c; };

struct Obj {
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
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
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
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
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual Src* GetSrcC8();
    virtual Src* GetSrcCC();
};

struct Hold {
    int unk04; int unk08; int unk0c; int unk10;
    Hold() : unk04(0), unk0c(0), unk10(0) { unk08 = 1; }
    virtual ~Hold() { Release(0); }
    void Release(int flag);
};
struct HoldA : Hold {
    int unk14; int unk18;
    HoldA() {}
    void FUN_0094bab0(const Name& p);
};
struct HoldB : Hold {
    HoldB() {}
    void FUN_0091be20();
    void FUN_0091b8c0(int v);
    void FUN_0091b6d0(float f);
};
struct Result { int unk04; int unk08; int unk0c; virtual void rv(); };
struct ResultB : Result {
    ResultB(HoldB& b);
    static void* operator new(unsigned int n);
    static void operator delete(void* p);
};
struct ResultA : Result {
    ResultA(HoldA& a);
    static void* operator new(unsigned int n);
    static void operator delete(void* p);
};
extern Name DAT_010f3370;

// pdb: bhkFixedConstraint::FixConstraint | bhkFixedConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apConstraint, afStrength
Result* FUN_0094bba0(Obj* obj, float x)
{
    HoldA a;
    Src* s = obj->GetSrcCC();
    Key* k = s ? s->unk0c : 0;
    Src* t = obj->GetSrcC8();
    if (t && t->unk0c) a.unk0c = t->unk0c->unk08; else a.unk0c = 0;
    if (k) a.unk10 = k->unk08; else a.unk10 = 0;
    Src* u = obj->GetSrcC8();
    if (u) a.FUN_0094bab0(*(const Name*)((char*)u + 0xe0)); else a.FUN_0094bab0(DAT_010f3370);
    Result* r;
    if (x < 1.0f) {
        HoldB b;
        b.FUN_0091be20();
        b.FUN_0091b8c0(a.unk04);
        b.unk0c = a.unk0c;
        b.unk10 = a.unk10;
        b.FUN_0091b6d0(x);
        r = new ResultB(b);
    } else {
        r = new ResultA(a);
    }
    return r;
}
}   // namespace f3m_0094bba0

// @f3 0x009468e0 (community match, verified in this file)
namespace f3m_009468e0 {
struct HeapMgr { void* Alloc(unsigned int n); };
extern HeapMgr DAT_01090a78;
extern float FUN_00dbcbd0;

struct Blk {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    unsigned char unk28;
};

struct Owner {
    int unk0;
    int unk4;
    int unk8;
    Blk* unkC;
    void Attach(Blk* b);
    Blk* FUN_009468e0(bool* ok);
};

// pdb: bhkMotorAction::CreateCinfo | bhkMotorAction.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: arCreated
Blk* Owner::FUN_009468e0(bool* ok) {
    if (unkC == 0) {
        char* raw = (char*)DAT_01090a78.Alloc(0x40);
        float z = 0.0f;
        unsigned char pad = (unsigned char)(0x10 - ((unsigned char)raw & 0xf));
        raw += pad;
        ((unsigned char*)raw)[-1] = pad;
        Blk* b = (Blk*)raw;
        b->unk0 = 0;
        b->unk4 = 0;
        *(volatile float*)&b->unk10 = z;
        *(volatile float*)&b->unk14 = z;
        *(volatile float*)&b->unk18 = z;
        *(volatile float*)&b->unk1c = z;
        *(volatile float*)&b->unk10 = z;
        *(volatile float*)&b->unk14 = z;
        *(volatile float*)&b->unk18 = z;
        *(volatile float*)&b->unk1c = z;
        b->unk20 = z;
        b->unk24 = FUN_00dbcbd0;
        *(volatile unsigned char*)&b->unk28 = 1;
        bool has = unk8 != 0;
        unkC = b;
        if (has) {
            Attach(b);
        }
        *ok = true;
        return unkC;
    }
    *ok = false;
    return unkC;
}
}   // namespace f3m_009468e0

// @f3 0x00953940 (community match, verified in this file)
namespace f3m_00953940 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Item { Item* next; int unk04; int size; };
struct Elem { Item* key; };

struct Pool {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    int cap;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    Item* head;
    int count;
    void FreeBig(int mode, Item* p, int a) throw();
    void FreeSized(Item* key, unsigned int size, int a) throw();
};

struct Logger {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void Report(int a, int b, const char* msg, const char* file, int line) throw();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void Begin(unsigned int tag, const char* s) throw();
    virtual void End() throw();
};

struct Stream {
    unsigned int* unk00; int unk04; int unk08;
    Stream(unsigned int* buf, int n) throw();
    void Close();
    Stream& operator<<(const char* s) throw();
};

extern Logger* DAT_010f3364;
extern unsigned long DAT_010f3170;
int hkString_strCmp(Item* a, const char* b) throw();

static __forceinline void FreeItem(Item* it)
{
    if ((it->size & 0x80000000u) == 0) {
        unsigned int m = it->size & 0x3fffffff;
        Pool* p = (Pool*)TlsGetValue(DAT_010f3170);
        p->FreeSized(it->next, m, 0x17);
    }
    Pool* q = (Pool*)TlsGetValue(DAT_010f3170);
    if (*(volatile int*)&q->count >= q->cap) {
        q->FreeBig(2, it, 0x16);
    } else {
        Item* h = q->head;
        q->count++;
        it->next = h;
        q->head = it;
    }
}

struct FUN_00953940_cls {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    Item** unk4c;
    int unk50;
    void FUN_00953940(const char* key);
};

// pdb: hkVisualDebugger::removeDefaultProcess | hkVisualDebugger.obj | fnv360_0822_retail, ustr, medium
// pdb params: processName
void FUN_00953940_cls::FUN_00953940(const char* key)
{
    int i = 0;
    if (unk50 > 0) {
        do {
            Item* c = unk4c[i];
            Item* n = c->next;
            if (hkString_strCmp(n, key) == 0) {
                Item* it = unk4c[i];
                if (it != 0) {
                    FreeItem(it);
                }
                unk50--;
                unk4c[i] = unk4c[unk50];
                return;
            }
            i++;
        } while (i < unk50);
    }
    unsigned int buf[128];
    DAT_010f3364->Begin(0x76565454, "removeDefaultProcess");
    Stream s(buf, 0x200);
    s << "The default Process'" << key << "', cannot not be removed from the default process list as it cannot be found!";
    DAT_010f3364->Report(0, -1, (const char*)buf, ".\\hkVisualDebugger.cpp", 0x13c);
    s.Close();
    DAT_010f3364->End();
}
}   // namespace f3m_00953940

// @f3 0x0094b810 (community match, verified in this file)
extern int DAT_010f31f8;
extern int DAT_011697b4;
extern int DAT_011691d4;
namespace f3m_0094b810 {
struct S_00cc7dc0_Arg { int unk00; int unk04; };
struct __declspec(novtable) S_00cc7dc0_Root {
    unsigned int unk04;
    unsigned int unk08;
    int unk0c;
    S_00cc7dc0_Root() { FUN_008f7c10(); unk0c = 0; }
    virtual ~S_00cc7dc0_Root();
    void FUN_008f7c10();
};
struct S_00cc7dc0_A : S_00cc7dc0_Root {
    S_00cc7dc0_A() { DAT_010f31f8++; }
    virtual ~S_00cc7dc0_A();
};
struct S_00cc7dc0_B : S_00cc7dc0_A {
    S_00cc7dc0_B() { DAT_011697b4++; }
    virtual ~S_00cc7dc0_B();
};
struct FUN_00cc7dc0 : S_00cc7dc0_B {
    FUN_00cc7dc0(S_00cc7dc0_Arg* a);
    void FUN_008fc4a0(S_00cc7dc0_Arg* a);
    virtual ~FUN_00cc7dc0();
};
// @fnv 0x00cc7dc0
// pdb: bhkFixedConstraint::bhkFixedConstraint | bhkFixedConstraint.obj | fnv360_0721_beta, objrun, medium
// pdb params: arInfo
FUN_00cc7dc0::FUN_00cc7dc0(S_00cc7dc0_Arg* a) {
    FUN_008fc4a0(a ? (S_00cc7dc0_Arg*)&a->unk04 : 0);
    DAT_011691d4++;
}
}   // namespace f3m_0094b810

// @f3 0x00941c20 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00941c20 {
namespace n941c20 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern Heap* (__stdcall* const FUN_00d9b080)(unsigned long);
class RefObj {
public:
    virtual ~RefObj() throw() {}
    unsigned short memSizeAndFlags;
    short refCount;
    void RemoveReference() {
        if (memSizeAndFlags != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
struct Member { int a, b, c, d; ~Member() throw(); };
}
struct FUN_00941c20 : n941c20::RefObj {
    n941c20::Member m;
    n941c20::RefObj* ref;
    virtual ~FUN_00941c20() throw();
    static void* operator new(unsigned int n);
    static void operator delete(void* p) {
        FUN_00941c20* o = static_cast<FUN_00941c20*>(p);
        n941c20::Heap* h = n941c20::FUN_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(p, o->memSizeAndFlags, 0x15);
    }
};
FUN_00941c20::~FUN_00941c20() throw()
{
    if (ref) ref->RemoveReference();
}
void* Make941c20() { return new FUN_00941c20; }
}   // namespace f3m_00941c20

// @f3 0x0094cb60 (community match, verified in this file)
extern unsigned long DAT_010f3170;extern int DAT_00e1c2e4;
namespace f3m_0094cb60 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Destroy325{
struct Heap325{void FUN_008f6d90(void*,unsigned int,int);};
struct Base325{void*vtable;unsigned int unk04,unk08,unk0c,unk10;void*data;unsigned int size;int capacityFlags;~Base325(){vtable=&DAT_00e1c2e4;FUN_008fbbb0(0);}void FUN_008fbbb0(int);};
struct Owner325:Base325{~Owner325();};
Owner325::~Owner325(){if(!(capacityFlags&0x80000000)){unsigned int capacity=capacityFlags&0x3fffffff;Heap325*heap=(Heap325*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(data,capacity*4,23);}}
}
}   // namespace f3m_0094cb60

// @f3 0x00943e20 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00943e20 {
namespace n943e20 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag); };
extern Heap* (__stdcall* const FUN_00d9b080)(unsigned long);
class RefObj {
public:
    virtual ~RefObj() throw() {}
    unsigned short memSizeAndFlags;
    short refCount;
};
struct Inner {
    void* FUN_00943db0(unsigned int flags) throw();  // scalar deleting destructor
};
}
struct FUN_00943e20 : n943e20::RefObj {
    n943e20::Inner* m_inner;
    int m_c;
    int m_owned;
    __forceinline ~FUN_00943e20() throw() {
        if (!m_owned && m_inner)
            m_inner->FUN_00943db0(1);
    }
    static void* operator new(unsigned int n);
    // pdb: hkArrayStreamWriter::`scalar deleting destructor' | hkOStream.obj | fnv360_0822_retail, vtable, high
    static void operator delete(void* p) {
        FUN_00943e20* o = static_cast<FUN_00943e20*>(p);
        n943e20::Heap* h = n943e20::FUN_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(p, o->memSizeAndFlags, 0x1a);
    }
};
void* Make943e20() { return new FUN_00943e20; }
}   // namespace f3m_00943e20

// @f3 0x0094b090 (community match, verified in this file)
namespace f3m_0094b090 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
namespace n94b090 {
struct CritSec { int cs[6]; };
extern CritSec DAT_010f3194;
extern unsigned int DAT_010f31f8;
extern unsigned int DAT_011691c8;
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ebc0(void* p);
struct Base {
    virtual ~Base();
    int a, b;
    Base();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0089ebc0(p); }
};
struct Mid : Base {
    int m0c;
    Mid() : m0c(0) { ++DAT_010f31f8; }
    virtual ~Mid();
};
struct Obj : Mid {
    Obj() { ++DAT_011691c8; }
    virtual ~Obj();
};
}
struct FUN_0094b090_t {
    void FUN_008fbc00(n94b090::Obj* o, int arg);
    n94b090::Obj* FUN_0094b090(int arg);
};
n94b090::Obj* FUN_0094b090_t::FUN_0094b090(int arg) {
    EnterCriticalSection(&n94b090::DAT_010f3194);
    n94b090::Obj* o = new n94b090::Obj;
    FUN_008fbc00(o, arg);
    LeaveCriticalSection(&n94b090::DAT_010f3194);
    return o;
}
}   // namespace f3m_0094b090

// @f3 0x0094af60 (community match, verified in this file)
extern int DAT_011691c8;
namespace f3m_0094af60 {
class FUN_00cc7d00_base {
public:
    virtual void unk00();
    ~FUN_00cc7d00_base();
    int unk04;
};
class FUN_00cc7d00 : public FUN_00cc7d00_base {
public:
    virtual ~FUN_00cc7d00();
    void unk08();
};
// pdb: bhkPrismaticConstraint::~bhkPrismaticConstraint | bhkPrismaticConstraint.obj | tesv_win, call_seq, medium
FUN_00cc7d00::~FUN_00cc7d00()
{
    unk08();
    --DAT_011691c8;
}
}   // namespace f3m_0094af60

// @f3 0x00941c90 (community match, verified in this file)
namespace f3m_00941c90 {
namespace n941c90 {
struct RefObj {
    virtual ~RefObj() throw();
    unsigned short m4;
    short refs;
};
struct Ptr {
    RefObj* p;
    static __forceinline void Dec(RefObj* q) { if (q && q->m4) { --q->refs; if (q->refs == 0) delete q; } }
    Ptr() : p(0) {}
    Ptr& operator=(RefObj* o)
    {
        if (o && o->m4)
            ++o->refs;
        Dec(p);
        p = o;
        return *this;
    }
};
struct Entry { const char* name; int value; };
}
struct __declspec(novtable) Base941c90 {
    virtual ~Base941c90() throw();
    unsigned short m4;
    unsigned short refs;
    Base941c90() throw() { refs = 1; }
};
struct C941c90 : Base941c90 {
    virtual ~C941c90() throw();
    f3m_00940870::NameMap names;
    n941c90::Ptr ptr;
    C941c90(const n941c90::Entry* entries, n941c90::RefObj* o) throw();
};
C941c90::C941c90(const n941c90::Entry* entries, n941c90::RefObj* o) throw()
    : names(f3m_00940870::MapFlag(0))
{
    ptr = o;
    if (entries) {
        for (; entries->name; ++entries)
            names.FUN_009b0e60(entries->name, entries->value);
    }
}
}   // namespace f3m_00941c90

// @f3 0x0094eea0 (community match, verified in this file)
extern unsigned int DAT_01169228;
namespace f3m_0094eea0 {
namespace Task1207 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Ref {virtual void Slot0();virtual void DeleteThis();long references;};
struct SmartReference {
 Ref* object;
 static void Release(Ref* p){if(InterlockedDecrement(&p->references)==0)p->DeleteThis();}
 SmartReference& operator=(Ref* replacement){if(object!=replacement){if(object)Release(object);object=replacement;}return *this;}
 ~SmartReference(){if(object)Release(object);}
};
struct FUN_0096ab10 {
 virtual ~FUN_0096ab10();
 unsigned int unk04,unk08,unk0c,unk10;
};
struct Resource:FUN_0096ab10 {
 SmartReference reference;
 void FUN_008f7ef0();
 virtual ~Resource();
};
// pdb: bhkExtendedMeshShape::~bhkExtendedMeshShape | bhkExtendedMeshShape.obj | fnv360_0822_retail, caller_sim, medium
Resource::~Resource() {
 FUN_008f7ef0();
 --DAT_01169228;
 reference=static_cast<Ref*>(0);
}
}
}   // namespace f3m_0094eea0

// @f3 0x009474b0 (community match, verified in this file)
namespace f3m_009474b0 {

// ---- stand-in declarations (this unit's staging file declares nothing for this address) ----

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* pkSection);

struct RTL_CS_9474b0 { int m_auiData[6]; };
extern RTL_CS_9474b0 DAT_010f3194;

extern int DAT_01268154;
extern int DAT_01268194;

struct NiMemObject {
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int uiSize);
};

struct BaseObject : public NiMemObject {
    virtual void vf_base();
    int m_04;
    int m_08;
    BaseObject();
};

struct FUN_00c85790 : public BaseObject {
    virtual void vf00();
    int m_0c;
    FUN_00c85790() { m_0c = 0; ++DAT_01268154; }
};

struct FUN_00c8a720 : public FUN_00c85790 {
    virtual void vf10();
    FUN_00c8a720() { ++DAT_01268194; }
};

struct FUN_00cc4180 : public FUN_00c8a720 {
    virtual void vf20();
    static unsigned int ms_uiInstances;
    FUN_00cc4180() { ++ms_uiInstances; }
};

struct Owner9474b0 {
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void Attach(FUN_00cc4180* pkObject, int iArg);
    FUN_00cc4180* FUN_009474b0(int iArg);
};

// pdb: bhkAngularDashpotAction::CreateClone | bhkAngularDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: arCloneData
FUN_00cc4180* Owner9474b0::FUN_009474b0(int iArg)
{
    EnterCriticalSection(&DAT_010f3194);
    FUN_00cc4180* pkObject = new FUN_00cc4180();
    Attach(pkObject, iArg);
    LeaveCriticalSection(&DAT_010f3194);
    return pkObject;
}
}   // namespace f3m_009474b0

// @f3 0x009517c0 (community match, verified in this file)
namespace f3m_009517c0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
extern "C" void* __cdecl FUN_0089eb90(unsigned int size);

struct FUN_00951690;



struct FUN_00951690 {
    int m_00, m_04, m_08, m_0c, m_10;
    FUN_00951690();
};

inline void* operator new(unsigned int n) { return FUN_0089eb90(n); }

extern unsigned int DAT_010f3194;

struct CX517 {
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
    virtual void vC0(FUN_00951690* p, int arg);
    FUN_00951690* FUN_009517c0(int arg);
};

// pdb: bhkConvexTransformShape::CreateClone | bhkConvexTransformShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
FUN_00951690* CX517::FUN_009517c0(int arg)
{
    EnterCriticalSection(&DAT_010f3194);
    FUN_00951690* p = new FUN_00951690();
    vC0(p, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return p;
}
}   // namespace f3m_009517c0

// @f3 0x00944810 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern unsigned long DAT_0116913c;
namespace f3m_00944810 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern void (__stdcall* DAT_00d9b084)(unsigned long index, void* value);

struct Free944810 {
    Free944810* next;
};

struct Pool944810 {
    void* u00; void* u04; void* u08; void* u0c;
    void* u10; void* u14; void* u18; void* u1c;
    void* u20; void* u24; void* u28; void* u2c;
    void* u30; void* u34; void* u38; void* u3c;
    void* u40; void* u44; void* u48; void* u4c;
    Free944810* head;
    int count;
    void* FUN_008f6800(unsigned int a, unsigned int b);
};

struct Block944810 {
    int f00;
    int f04;
    int f08;
    int f0c;
    char f10;
};

// pdb: hkMonitorStream::init | hkMonitorStream.obj | fnv360_0822_debug, call_seq + bridge(call_seq|call_seq) + skyrim(objrun_prop), high
void __cdecl hkMonitorStream_init()
{
    Pool944810* pool = (Pool944810*)TlsGetValue(DAT_010f3170);
    Free944810* node = pool->head;
    if (node) {
        pool->count += -1;
        pool->head = node->next;
    } else {
        node = (Free944810*)pool->FUN_008f6800(3, 0x1b);
    }
    DAT_00d9b084(DAT_0116913c, node);
    Block944810* block = (Block944810*)node;
    block->f10 = 0;
    block->f00 = 0;
    block->f08 = 0;
    block->f04 = 0;
    block->f0c = 0;
}
}   // namespace f3m_00944810

// @f3 0x00942770 (community match, verified in this file)
namespace f3m_00942770 {
struct P_942770 { int a0, a4, a8; char bc; char pad[3]; int a10, a14; };
struct B_942770 { char pad[0x14c]; B_942770(); };
class FUN_00942770 : public B_942770 {
public:
    int a14c; char b150; char pad[3]; int a154; int pad2; int a15c;
    void FUN_00942690(int a, int b);
    FUN_00942770(const P_942770* p);
};
FUN_00942770::FUN_00942770(const P_942770* p) {
    a14c = p->a8; a154 = p->a10; b150 = p->bc; a15c = p->a14;
    FUN_00942690(p->a0, p->a4);
}
}   // namespace f3m_00942770

// @f3 0x00951700 (community match, verified in this file)
struct S20_951700 { int u; };
struct M_951700 { char pad[0x18]; int v18; int u1c; S20_951700 s20; };
extern S20_951700 DAT_010f3370;
struct Sub10_951700 { void FUN_008fda60(S20_951700* s); };
struct Dst_951700 { char pad[8]; int v8; int uc; Sub10_951700 s10; };
struct O_951700 {
    int u0, u4; M_951700* p8;
    void FUN_0090c4a0(Dst_951700* d);
    void FUN_00951700(Dst_951700* d);
};
void O_951700::FUN_00951700(Dst_951700* d) {
    FUN_0090c4a0(d);
    d->v8 = (this && p8) ? p8->v18 : 0;
    S20_951700* s = (this && p8) ? &p8->s20 : &DAT_010f3370;
    d->s10.FUN_008fda60(s);
}

// @f3 0x0095b110 (community match, verified in this file)
namespace f3m_0095b110 {
struct Ref_95b110 { virtual void Del(int f); unsigned short w4; short w6; };
struct O_95b110 {
    int u0, u4, u8; Ref_95b110* p;
    void FUN_0095b110(Ref_95b110* r);
};
// pdb: hkpMalleableConstraintData::SetWrappedConstraintData | hkpMalleableConstraintData.obj | fnv360_0822_retail, objrun, medium
// pdb params: apData
void O_95b110::FUN_0095b110(Ref_95b110* r) {
    if (r && r->w4) r->w6++;
    Ref_95b110* old = p;
    if (old && old->w4) {
        --old->w6;
        if ((unsigned short)old->w6 == 0) old->Del(1);
    }
    p = r;
}
}   // namespace f3m_0095b110

// @f3 0x00941fc0 (community match, verified in this file)
namespace f3m_00941fc0 {
struct Ref_941fc0 { virtual void Del(int f); unsigned short w4; short w6; };
struct O_941fc0 { Ref_941fc0* p; void FUN_00941fc0(); };
void O_941fc0::FUN_00941fc0() { Ref_941fc0* r = p; if (r->w4) { --r->w6; if ((unsigned short)r->w6 == 0) r->Del(1); } p = 0; }
}   // namespace f3m_00941fc0

// @f3 0x00950490 (community match, verified in this file)
namespace f3m_00950490 {

struct Allocated_950490 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    Allocated_950490* FUN_00950440();
};

struct Object_950490 {
    int unk00;
    int unk04;
    int* unk08;
    Allocated_950490* unk0C;

    void bhkCylinderShape_CopyCinfo(Allocated_950490* object);
    int FUN_00950490(unsigned char* result);
};

// pdb: bhkCylinderShape::SaveBinary | bhkCylinderShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: arStream
int Object_950490::FUN_00950490(unsigned char* result)
{
    if (unk0C == 0) {
        unsigned char* allocation = static_cast<unsigned char*>(
            DAT_01090a78.FUN_0086b930(0x50));

        unsigned int address = reinterpret_cast<unsigned int>(allocation);
        unsigned char alignment =
            static_cast<unsigned char>(0x10 - (address & 0x0F));

        allocation += alignment;
        allocation[-1] = alignment;

        Allocated_950490* object =
            reinterpret_cast<Allocated_950490*>(allocation);
        object = object->FUN_00950440();

        unk0C = object;

        if (unk08 != 0) {
            bhkCylinderShape_CopyCinfo(object);
        }

        *result = 1;
        return reinterpret_cast<int>(unk0C);
    }

    *result = 0;
    return reinterpret_cast<int>(unk0C);
}
}   // namespace f3m_00950490

// @f3 0x00949150 (community match, verified in this file)
namespace w949150 {
struct Heap { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
extern void* DAT_00e33978;
struct Data { int unk00,unk04,unk08,unk0c; };
struct Impl {
 void* table; Data data;
 static void* operator new(unsigned n) { return DAT_01090a78.FUN_0086b930(n); }
 static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
 Impl() { data.unk00=0; data.unk08=0; data.unk0c=0; data.unk04=1; table=&DAT_00e33978; }
};
struct Owner {
 int unk00,unk04,unk08; Data* unk0c;
 void FUN_008fc420(Impl*);
 Data* FUN_00949150(bool*);
};
// pdb: bhkStiffSpringConstraint::CreateCinfo | bhkStiffSpringConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCreated
Data* Owner::FUN_00949150(bool* created) {
 if (!unk0c) {
  Impl* p=new Impl;
  unk0c=p ? &p->data : 0;
  if (unk08) FUN_008fc420(unk0c ? reinterpret_cast<Impl*>(reinterpret_cast<char*>(unk0c)-4) : 0);
  *created=true;
 } else *created=false;
 return unk0c;
}
}

// @f3 0x009501f0 (community match, verified in this file)
namespace f3m_009501f0 {
struct HingeVec { float x,y,z,w; void Copy(const HingeVec& q) { x=q.x; y=q.y; z=q.z; w=q.w; } };

struct HingeData { int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C; HingeVec a,b; float FUN_009e5240(); };
struct HingeOutput { int unk00,unk04,unk08,unk0C; HingeVec a,b; float value; };
struct HingeOwner { int unk00,unk04; HingeData* data;
void FUN_0090c4a0(HingeOutput*);
float Value() { if (this && data) return data->FUN_009e5240(); return 0.0f; }
void bhkCylinderShape_CopyCinfo(HingeOutput* out);
};
// pdb: bhkCylinderShape::CopyCinfo | bhkCylinderShape.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void HingeOwner::bhkCylinderShape_CopyCinfo(HingeOutput* out) { FUN_0090c4a0(out); out->a.Copy(this && data ? data->a : *(HingeVec*)&DAT_01092a50); out->b.Copy(this && data ? data->b : *(HingeVec*)&DAT_01092a50); out->value=Value(); }
}   // namespace f3m_009501f0

// @f3 0x00943c20 (community match, verified in this file)
namespace f3m_00943c20 {
namespace clear943 {
struct Array {char* data;int count;int capacity;};
void __cdecl FUN_00901e90(Array*,int,int);
struct Owner {int unk00;int unk04;Array* array;int unk0C;void FUN_00943c20();};
// pdb: hkArrayStreamWriter::clear | hkArrayStreamWriter.obj | tesv_win, vtable, medium
void Owner::FUN_00943c20(){array->count=0;unk0C=0;Array* a=array;int n=a->count+1;int capacity=a->capacity&0x3fffffff;if(capacity<n){int grown=capacity*2;if(n<grown)n=grown;FUN_00901e90(a,n,1);}Array* target=array;target->data[target->count]=0;}
}
}   // namespace f3m_00943c20

// @f3 0x00945930 (community match, verified in this file)
namespace f3m_00945930 {
extern "C" void* __cdecl FUN_0089eb90(unsigned int);
extern "C" void __cdecl FUN_0089ec10(void*, unsigned int);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern int DAT_010f3194;
struct FUN_00945870 {
 int unk00, unk04, unk08, unk0c, unk10, unk14;
 FUN_00945870();
 static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
 static void operator delete(void* p, unsigned int n) { FUN_0089ec10(p, n); }
};
struct Owner945930 {
 void FUN_008f9990(FUN_00945870*, int);
 FUN_00945870* FUN_00945930(int);
};
// pdb: bhkCachingShapePhantom::CreateClone | bhkCachingShapePhantom.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCloneData
FUN_00945870* Owner945930::FUN_00945930(int value) {
 EnterCriticalSection(&DAT_010f3194);
 FUN_00945870* node = new FUN_00945870;
 FUN_008f9990(node, value);
 LeaveCriticalSection(&DAT_010f3194);
 return node;
}
}   // namespace f3m_00945930

// @f3 0x00949310 (community match, verified in this file)
namespace f3m_00949310 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern int DAT_010f3194, DAT_010f31f8, DAT_011691b0;
extern void* DAT_00e1c304; extern void* DAT_00e7a9e4;
extern void* __cdecl FUN_0089eb90(unsigned int);
extern void __cdecl FUN_0089ec10(void*,unsigned int);
struct Created949 { void* table; int unk04; int unk08; int unk0c; void FUN_008f7c10(); static void* operator new(unsigned int n) { return FUN_0089eb90(n); } static void operator delete(void* p,unsigned int n) { FUN_0089ec10(p,n); } Created949() { FUN_008f7c10(); table=&DAT_00e1c304; unk0c=0; ++DAT_010f31f8; table=&DAT_00e7a9e4; ++DAT_011691b0; } };
struct Owner949 { void FUN_008fbc00(Created949*,int); Created949* FUN_00949310(int); };
// pdb: bhkRagdollLimitsConstraint::CreateClone | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
Created949* Owner949::FUN_00949310(int arg) { EnterCriticalSection(&DAT_010f3194); Created949* result=new Created949; FUN_008fbc00(result,arg); LeaveCriticalSection(&DAT_010f3194); return result; }
}   // namespace f3m_00949310

// @f3 0x0094b960 (community match, verified in this file)
namespace f3m_0094b960 {
extern int DAT_010f31f8;
extern int DAT_011697b4;
extern int DAT_011691d4;
extern char DAT_010f3194[24];
namespace f3m_0094b960 {
__declspec(dllimport) void __stdcall FUN_00d9b09c(void* cs);
__declspec(dllimport) void __stdcall FUN_00d9b0a0(void* cs);
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ec00(void* p);

class FUN_008f7c10 {
public:
    FUN_008f7c10();
    virtual ~FUN_008f7c10();
    int unk04;
    int unk08;
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0089ec00(p); }
};
class Mid1_b960 : public FUN_008f7c10 {
public:
    int unk0C;
    Mid1_b960() : unk0C(0) { ++DAT_010f31f8; }
    virtual ~Mid1_b960();
};
class Mid2_b960 : public Mid1_b960 {
public:
    Mid2_b960() { ++DAT_011697b4; }
    virtual ~Mid2_b960();
};
class Obj_b960 : public Mid2_b960 {
public:
    Obj_b960() { ++DAT_011691d4; }
    virtual ~Obj_b960();
};
struct Owner_b960 {
    void FUN_008fbc00(FUN_008f7c10* obj, int arg);
    Obj_b960* FUN_0094b960(int arg);
};
}
using namespace f3m_0094b960;

Obj_b960* Owner_b960::FUN_0094b960(int arg)
{
    FUN_00d9b09c(DAT_010f3194);
    Obj_b960* obj = new Obj_b960();
    FUN_008fbc00(obj, arg);
    FUN_00d9b0a0(DAT_010f3194);
    return obj;
}
}   // namespace f3m_0094b960

// @f3 0x0094da10 (community match, verified in this file)
namespace f3m_0094da10 {
namespace w94da10 {
struct Rotation { int unk00,unk04,unk08; float w; Rotation():unk00(0),unk04(0),unk08(0),w(1) {} };
struct Owner { bool FUN_009522b0(Owner*); void FUN_0094d4e0(Rotation*); bool FUN_0094da10(Owner*); };
// pdb: bhkMoppBvTreeShape::LinkObject | bhkMoppBvTreeShape.obj | fnv360_0822_debug, objrun, low, conflict (skyrim: bhkMoppBvTreeShape::LoadCInfo)
// pdb params: arStream
bool Owner::FUN_0094da10(Owner* other) {
 bool result=FUN_009522b0(other);
 if(result) { Rotation a,b; FUN_0094d4e0(&a); other->FUN_0094d4e0(&b); }
 return result;
}
}
}   // namespace f3m_0094da10

// @f3 0x00950070 (community match, verified in this file)
namespace f3m_00950070 {
namespace workerB950070 {
struct Heap {void FUN_0086ba60(void*);}; extern Heap DAT_01090a78;
struct Member {void FUN_00911510();};
struct Owner {int unk00,unk04,unk08; Member* value;void FUN_00950070(bool);};
// pdb: bhkExtendedMeshShape::KillCinfo | bhkExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: abCreated
void Owner::FUN_00950070(bool release){if(release){Member* p=value;if(p){p->FUN_00911510();unsigned char* raw=(unsigned char*)p; DAT_01090a78.FUN_0086ba60(raw-raw[-1]);}value=0;}}
}
}   // namespace f3m_00950070

// @f3 0x009428c0 (community match, verified in this file)
namespace f3m_009428c0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern int DAT_01169120;
struct Range9428 { unsigned int first,unk04,last; void ScrapHeap_Deallocate(unsigned int); };
struct Owner9428 {
 void** vtable;
 void FUN_009428c0(unsigned int,void*,void*);
};
void Owner9428::FUN_009428c0(unsigned int a,void* b,void* c) {
 EnterCriticalSection(&DAT_01169120);
 Range9428* range=(Range9428*)((char*)this+0xa18);
 if(a>=range->first && a<range->last) range->ScrapHeap_Deallocate(a);
 else {
  typedef void (__thiscall* Fallback)(Owner9428*,unsigned int,void*,void*);
  ((Fallback)vtable[4])(this,a,b,c);
 }
 LeaveCriticalSection(&DAT_01169120);
}
}   // namespace f3m_009428c0

// @f3 0x00947030 (community match, verified in this file)
namespace f3m_00947030 {
namespace constructor947 {extern float DAT_00dbe8fc,DAT_00db75c8;
struct Values947 {float x0,x1,x2,x3,x4,x5,x6,x7;Values947(){x0=0;x1=0;x2=0;x3=0;x4=0;x5=0;x6=0;x7=0;}void Clear(){x0=0;x1=0;x2=0;x3=0;x4=0;x5=0;x6=0;x7=0;}};
struct Owner947 {int unk00,unk04,unk08,unk0C;Values947 values;float unk30,unk34;Owner947();};
Owner947::Owner947():unk00(0),unk04(0),unk08(0){values.Clear();unk30=DAT_00dbe8fc;unk34=DAT_00db75c8;}

}
}   // namespace f3m_00947030

// @f3 0x00957eb0 (community match, verified in this file)
namespace f3m_00957eb0 {
namespace w957eb0 {
struct Transform { float unk00; float unk04; float unk08; float unk0c; float unk10; float unk14; float unk18; float unk1c; float unk20; float unk24; float unk28; float unk2c; };
void blendTwoTransforms(Transform*,Transform*,float,Transform*);
// pdb: hkaSkeletonUtils::blendPoses | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: numBones, poseA, poseB, weights, poseOut
void FUN_00957eb0(unsigned n,Transform* a,Transform* b,float* weights,Transform* c) {
 for(unsigned i=0;i<n;++i) blendTwoTransforms(a+i,b+i,weights[i],c+i);
}
}
}   // namespace f3m_00957eb0

// @f3 0x00952990 (community match, verified in this file)
namespace f3m_00952990 {
struct CountObject952; struct CountTable952 { void* unk00; unsigned int (__thiscall* count)(CountObject952*); }; struct CountObject952 { CountTable952* table; unsigned int Count(){return table->count(this);} };
struct Entry952 { int unk00; int unk04; struct FlagOwner95299* object; };
struct Data952 { int unk00; int unk04; int unk08; int unk0c; int unk10; CountObject952 countObject; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; Entry952** entries; };
struct FlagOwner95299 { int unk00; int unk04; Data952* data; int unk0c; unsigned int flags; unsigned int Count(){if(this && data) return data->countObject.Count();return 0;} FlagOwner95299* Get(unsigned int index){if(this && data){Entry952* entry=data->entries[index];if(entry)return entry->object;}return 0;} char Has(unsigned int mask){return (flags & mask)!=0;} char ChildHas(unsigned int index,unsigned int mask){FlagOwner95299* child=Get(index);if(child)return child->Has(mask);return Has(mask);} char FUN_00952990(unsigned int,unsigned int); };
// pdb: bhkConvexListShape::QSubMaterial | bhkConvexListShape.obj | fnv360_0721_beta, objrun_open, low
// pdb params: aiKey
char FlagOwner95299::FUN_00952990(unsigned int index,unsigned int mask){ if(index!=~0u && index<=Count()) return ChildHas(index,mask); return Has(mask); }
}   // namespace f3m_00952990

// @f3 0x0094cf30 (community match, verified in this file)
namespace workerA94cf {
extern "C" void* __cdecl FUN_0089eb90(unsigned int);
extern "C" void __cdecl FUN_0089ec10(void*,unsigned int);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern int DAT_010f3194,DAT_00e1c304,DAT_00e36ee4;
extern int DAT_010f31f8,DAT_011691f8;
struct Node {
 void* vtable; int unk04,unk08,unk0c;
 void FUN_008f7c10();
 Node() {
  FUN_008f7c10();
  vtable=&DAT_00e1c304;
  unk0c=0;
  ++DAT_010f31f8;
  vtable=&DAT_00e36ee4;
  ++DAT_011691f8;
 }
 static void* operator new(unsigned int n) {return FUN_0089eb90(n);}
 static void operator delete(void*p,unsigned int n) {FUN_0089ec10(p,n);}
};
struct Owner {
 Node* FUN_0094cf30(int);
 void FUN_008fbc00(Node*,int);
};
// pdb: bhkBallAndSocketConstraint::CreateClone | bhkBallAndSocketConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCloneData
Node* Owner::FUN_0094cf30(int x) {
 EnterCriticalSection(&DAT_010f3194);
 Node* node=new Node;
 FUN_008fbc00(node,x);
 LeaveCriticalSection(&DAT_010f3194);
 return node;
}
}

// @f3 0x00949650 (community match, verified in this file)
namespace f3m_00949650 {
// pdb: bhkRagdollLimitsConstraint::CreateCinfo | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail, objrun, medium
// pdb params: arCreated
namespace Task9496{struct Memory{void* FUN_008f6d30(unsigned,int);};extern unsigned DAT_010f3170;typedef Memory* (__stdcall* TlsLookup)(unsigned);extern TlsLookup DAT_00d9b080;struct Object{void* methods;unsigned short size;unsigned short refs;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;int unka0;int unka4;int unka8;int unkac;int unkb0;int unkb4;int unkb8;int unkbc;Object();static void*operator new(unsigned n){Memory*memory=DAT_00d9b080(DAT_010f3170);Object*p=(Object*)memory->FUN_008f6d30(n,44);p->size=(unsigned short)n;return p;}static void operator delete(void*);};struct Owner{int unk00;Object* object;int FUN_00949650();};int Owner::FUN_00949650(){if(!object)object=new Object;return 192;}}
}   // namespace f3m_00949650

// @f3 0x00953850 (community match, verified in this file)
namespace f3m_00953850 {
namespace f3m_00953850 {
struct FreeNode_3850 {
    FreeNode_3850* next;
};
struct Pool_3850 {
    char pad[0x48];
    FreeNode_3850* freeList;
    int freeCount;
    void* FUN_008f6800(int row, int size) throw();
};
__declspec(dllimport) Pool_3850* __stdcall FUN_00d9b080(unsigned long) throw();
void __cdecl FUN_00901f10(void* array, int elementSize) throw();

struct String_3850 : f3m_00940870::Text {
    __forceinline String_3850(const char* s) throw() : f3m_00940870::Text(s) {}
    static void* operator new(unsigned int) throw()
    {
        Pool_3850* pool = FUN_00d9b080(DAT_010f3170);
        void* p = pool->freeList;
        if (p) {
            pool->freeCount--;
            pool->freeList = ((FreeNode_3850*)p)->next;
        } else {
            p = pool->FUN_008f6800(2, 0x16);
        }
        return p;
    }
    static void operator delete(void*) throw();
};
struct Array_3850 {
    String_3850** data;
    int size;
    int capacityAndFlags;
    void PushBack(String_3850* s)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        data[size] = s;
        size++;
    }
};
struct Cls_3850 {
    char pad[0x4c];
    Array_3850 strings;
    void FUN_00953850(const char* s);
};
}
using namespace f3m_00953850;

void Cls_3850::FUN_00953850(const char* s)
{
    strings.PushBack(new String_3850(s));
}
}   // namespace f3m_00953850

// @f3 0x0094bf20 (community match, verified in this file)
namespace f3m_0094bf20 {

extern int DAT_010f3194;extern int DAT_010f31f8;extern int DAT_011691e0;extern int DAT_00e1c304;extern int DAT_00e7ae44;
typedef void (__stdcall* Lockbf)(void*);extern Lockbf DAT_00d9b09c;extern Lockbf DAT_00d9b0a0;
void* __cdecl FUN_0089eb90(unsigned);
struct Nodebf20 {static void* operator new(size_t size){return FUN_0089eb90(size);}void* table;int unk04;int unk08;int unk0c;void FUN_008f7c10();__forceinline Nodebf20(){FUN_008f7c10();table=&DAT_00e1c304;unk0c=0;++DAT_010f31f8;table=&DAT_00e7ae44;++DAT_011691e0;}};
struct Ownerbf20 {void FUN_008fbc00(Nodebf20*,int);Nodebf20* FUN_0094bf20(int);};
// pdb: hkHingeLimitsConstraintCinfo::CreateData | bhkHingeLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
Nodebf20* Ownerbf20::FUN_0094bf20(int value){DAT_00d9b09c(&DAT_010f3194);Nodebf20* node=new Nodebf20;FUN_008fbc00(node,value);DAT_00d9b0a0(&DAT_010f3194);return node;}
}   // namespace f3m_0094bf20

// @f3 0x0094b6a0 (community match, verified in this file)
#include <cstddef>
namespace f3m_0094b6a0 {
// pdb: bhkPrismaticConstraint::CreateCinfo | bhkPrismaticConstraint.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arCreated
namespace Task94b6{struct Heap{void*FUN_0086b930(unsigned);};extern Heap DAT_01090a78;extern int DAT_00e7ac34;struct Serializable{int value;int refs;};struct Object{void*methods;Serializable base;int unk0c;int unk10;Object(){base.value=0;unk0c=0;unk10=0;base.refs=1;methods=&DAT_00e7ac34;}static void*operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}static Serializable* Create(){Object*p=new Object;return p?&p->base:0;}static Object*From(Serializable*p){return p?(Object*)((char*)p - offsetof(Object,base)):0;}};struct Owner{int unk00;int unk04;int active;Serializable*cached;void FUN_008fc420(Object*);Serializable*FUN_0094b6a0(bool*);};Serializable* Owner::FUN_0094b6a0(bool*created){if(!cached){cached=Object::Create();if(active)FUN_008fc420(Object::From(cached));*created=true;}else *created=false;return cached;}}
}   // namespace f3m_0094b6a0

// @f3 0x00952e20 (community match, verified in this file)
namespace f3m_00952e20 {
namespace Q952 {extern void* DAT_0116926c;extern char DAT_00e32750;extern char DAT_00e347d0;int __cdecl FUN_00847b50(void*);int __cdecl FUN_00847d30(const char*,int);int __cdecl FUN_00403230(char*,unsigned,const char*,...);struct Output {void* data;int unk04;unsigned short capacity;unsigned short count;unsigned short unk0c;unsigned short grow;void FUN_00555790(int);void FUN_005b3880(int,int*);__forceinline void Append(int value){unsigned i=count;if(i>=capacity)FUN_00555790(i+grow);FUN_005b3880(i,&value);}};struct CountMember;struct CountOps{void* unk00;int (__thiscall *count)(CountMember*);};struct CountMember{CountOps* ops;int Get(){return ops->count(this);}};struct Link {int unk00;int unk04;int unk08;int unk0c;int unk10;CountMember sub;};struct Owner{int unk00;int unk04;Link* link;void FUN_0090c5a0(Output*);void FUN_00952e20(Output*);__forceinline int Number(){if(this && link)return link->sub.Get();return 0;}};
// pdb: bhkConvexListShape::GetViewerStrings | bhkConvexListShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Owner::FUN_00952e20(Output* out){FUN_0090c5a0(out);out->Append(FUN_00847b50(DAT_0116926c));int count=Number();out->Append(FUN_00847d30(&DAT_00e32750,count));char buffer[32];for(int i=0;i<count;++i)FUN_00403230(buffer,32,&DAT_00e347d0,i);} }
}   // namespace f3m_00952e20

// @f3 0x00947af0 (community match, verified in this file)
namespace f3m_00947af0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace Task1370 {
struct Lock{unsigned int debug,lockCount,recursion,owner,semaphore,spin;};
extern Lock DAT_010f3194;
extern int DAT_010f31f8,DAT_0116918c,DAT_00e1c304,DAT_00e7a774;
void* FUN_0089eb90(unsigned int);
struct Obj {
 void* table;unsigned int refs,value,data;
 void* FUN_008f7c10();
 static void* operator new(unsigned int n){return FUN_0089eb90(n);}
 static void operator delete(void*);
 Obj(){
  FUN_008f7c10();
  table=&DAT_00e1c304;
  int one=1;
  data=0;
  DAT_010f31f8+=one;
  table=&DAT_00e7a774;
  DAT_0116918c+=one;
 }
};
struct Owner {
 void FUN_008fbc00(Obj*,int);
 Obj* FUN_00947af0(int);
};
// pdb: bhkBreakableConstraint::CreateClone | bhkBreakableConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCloneData
Obj* Owner::FUN_00947af0(int arg){
 EnterCriticalSection(&DAT_010f3194);
 Obj* obj=new Obj();
 FUN_008fbc00(obj,arg);
 LeaveCriticalSection(&DAT_010f3194);
 return obj;
}
}
}   // namespace f3m_00947af0

// @f3 0x009482d0 (community match, verified in this file)
struct _RTL_CRITICAL_SECTION;
typedef _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
namespace task1371 {
extern CRITICAL_SECTION DAT_010f3194;
extern int DAT_010f31f8, DAT_01169198;
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_008f7c10 {
    virtual void slot0();
    unsigned int refCount, unk08;
    FUN_008f7c10();
};
struct bhkConstraint : FUN_008f7c10 {
    unsigned int data;
    virtual void slot1();
    bhkConstraint() { data=0; DAT_010f31f8+=1; }
};
struct bhkWheelConstraint : bhkConstraint {
    virtual void slot2();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    bhkWheelConstraint() { DAT_01169198+=1; }
};
struct Factory {
    void FUN_008fbc00(void*, int);
    void* FUN_009482d0(int);
};
// pdb: bhkWheelConstraint::CreateClone | bhkWheelConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
void* Factory::FUN_009482d0(int arg) {
    EnterCriticalSection(&DAT_010f3194);
    bhkWheelConstraint* obj = new bhkWheelConstraint();
    FUN_008fbc00(obj, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return obj;
}
}

// @f3 0x0094e010 (community match, verified in this file)
namespace f3m_0094e010 {
extern char DAT_010f3194[24];
namespace f3m_0094e010 {
__declspec(dllimport) void __stdcall FUN_00d9b09c(void* cs);
__declspec(dllimport) void __stdcall FUN_00d9b0a0(void* cs);
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ec00(void* p);

class FUN_0094deb0 {
public:
    FUN_0094deb0();
    int unk00[5];
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0089ec00(p); }
};
class Owner_e010 {
public:
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
    virtual void Add(FUN_0094deb0* obj, int arg);
    FUN_0094deb0* FUN_0094e010(int arg);
};
}
using namespace f3m_0094e010;

// pdb: bhkTriangleShape::CreateClone | bhkTriangleShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCloneData
FUN_0094deb0* Owner_e010::FUN_0094e010(int arg)
{
    FUN_00d9b09c(DAT_010f3194);
    FUN_0094deb0* obj = new FUN_0094deb0();
    Add(obj, arg);
    FUN_00d9b0a0(DAT_010f3194);
    return obj;
}
}   // namespace f3m_0094e010

// @f3 0x00949b30 (community match, verified in this file)
extern _RTL_CRITICAL_SECTION DAT_010f3194;
extern int DAT_010f31f8,DAT_011691bc;
extern int DAT_00e1c304,DAT_00e36fbc;
namespace f3m_00949b30 {
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
namespace factory1372 {
void* __cdecl FUN_0089eb90(unsigned);
struct Object {
 void* vtable;unsigned refs,value,data;
 static void* operator new(unsigned n){return FUN_0089eb90(n);}
 void* FUN_008f7c10();
 Object() {FUN_008f7c10();vtable=&DAT_00e1c304;int one=1;data=0;DAT_010f31f8+=one;vtable=&DAT_00e36fbc;DAT_011691bc+=one;}
};
struct Owner {void FUN_008fbc00(void*,int);void* FUN_00949b30(int);};
// pdb: bhkRagdollConstraint::CreateClone | bhkRagdollConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
void* Owner::FUN_00949b30(int arg) {
 EnterCriticalSection(&DAT_010f3194);
 Object* object=new Object();
 FUN_008fbc00(object,arg);
 LeaveCriticalSection(&DAT_010f3194);
 return object;
}
}
}   // namespace f3m_00949b30

// @f3 0x0094bd60 (community match, verified in this file)
namespace workerA94bdRecovery {
struct Heap { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
extern void* DAT_00e7ae24;
struct Data { int unk00,unk04,unk08,unk0c,unk10,unk14; };
struct Impl {
 void* table; Data data;
 static void* operator new(unsigned n) { return DAT_01090a78.FUN_0086b930(n); }
 static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
 Impl() { data.unk00=0; data.unk08=0; data.unk0c=0; data.unk04=1; table=&DAT_00e7ae24; }
};
struct Owner {
 int unk00,unk04,unk08; Data* unk0c;
 void FUN_008fc420(Impl*);
 Data* FUN_0094bd60(bool*);
};
// pdb: bhkFixedConstraint::CreateCinfo | bhkFixedConstraint.obj | fnv360_0721_beta, objrun_open, medium
// pdb params: arCreated
Data* Owner::FUN_0094bd60(bool* created) {
 if (!unk0c) {
  Impl* p=new Impl;
  unk0c=p ? &p->data : 0;
  if (unk08) FUN_008fc420(unk0c ? reinterpret_cast<Impl*>(reinterpret_cast<char*>(unk0c)-4) : 0);
  *created=true;
 } else *created=false;
 return unk0c;
}
}

// @f3 0x00957fb0 (community match, verified in this file)
namespace f3m_00957fb0 {
struct Vec4_7fb0 {
    float x, y, z, w;
};
struct QsTransform_7fb0 {
    Vec4_7fb0 translation;
    Vec4_7fb0 rotation;
    Vec4_7fb0 scale;
};
struct Skeleton_7fb0 {
    int unk00;
    short* parentIndices;
};
}
extern const f3m_00957fb0::Vec4_7fb0 FUN_00e375a0;
using namespace f3m_00957fb0;

// pdb: hkaSkeletonUtils::getModelSpaceScale | hkaSkeletonUtils.obj | fnv360_0822_debug, objrun_sim, medium
// pdb params: skeleton, poseLocal, boneId, scaleOut
void __cdecl FUN_00957fb0(const Skeleton_7fb0* skeleton, const QsTransform_7fb0* pose, int bone, Vec4_7fb0* out)
{
    *out = FUN_00e375a0;
    while (bone != -1) {
        const Vec4_7fb0& s = pose[bone].scale;
        out->x = s.x * out->x;
        out->y = s.y * out->y;
        out->z = s.z * out->z;
        out->w = s.w * out->w;
        bone = skeleton->parentIndices[bone];
    }
}

// @f3 0x00951a30 (community match, verified in this file)
namespace f3m_00951a30 {
namespace f3m_00951a30 {
struct Data_1a30 {
    char pad[8];
    void* unk08;
};
struct Obj_1a30 {
    Data_1a30* FUN_0082a280();
};
class Cls_1a30 {
public:
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
    virtual Data_1a30* GetData(unsigned char* created);
    void FUN_008f7450(Obj_1a30* obj);
    void FUN_00951a30(Obj_1a30* obj);
};
}
using namespace f3m_00951a30;

// pdb: bhkConvexTransformShape::LinkObject | bhkConvexTransformShape.obj | fnv360_0721_retail, objrun, medium
// pdb params: arStream
void Cls_1a30::FUN_00951a30(Obj_1a30* obj)
{
    unsigned char created;
    Data_1a30* data = GetData(&created);
    if (data) {
        Data_1a30* src = obj->FUN_0082a280();
        data->unk08 = src ? src->unk08 : 0;
    }
    FUN_008f7450(obj);
}
}   // namespace f3m_00951a30

// @f3 0x00943db0 (community match, verified in this file)
namespace f3m_00943db0 {
namespace f3m_00943db0 {
struct FreeNode_3db0 {
    FreeNode_3db0* next;
};
struct FreeList_3db0 {
    FreeNode_3db0* head;
    int count;
    void Push(FreeNode_3db0* b) { ++count; b->next = head; head = b; }
};
struct Pool_3db0 {
    char pad[0x34];
    int limit;
    char pad38[0x10];
    FreeList_3db0 row2;
    void FUN_008f6890(int row, void* p, int tag);
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Pool_3db0* __stdcall FUN_00d9b080(unsigned long);
struct String_3db0 {
    char* data;
    int size;
    int capacityAndFlags;
    String_3db0* FUN_00943db0(unsigned int flags);
};
}
using namespace f3m_00943db0;

// pdb: hkArray<char,hkContainerHeapAllocator>::`scalar deleting destructor' | hkOStream.obj | fnv360_0822_retail, call_seq, medium
String_3db0* String_3db0::FUN_00943db0(unsigned int flags)
{
    if ((capacityAndFlags & 0x80000000) == 0) {
        int cap = capacityAndFlags & 0x3fffffff;
        Pool_3db0* mem = FUN_00d9b080(DAT_010f3170);
        mem->FUN_008f6d90(data, cap, 0x17);
    }
    if (flags & 1) {
        Pool_3db0* pool = FUN_00d9b080(DAT_010f3170);
        FreeList_3db0* bucket = &pool->row2;
        if (*(volatile int*)&bucket->count >= pool->limit)
            pool->FUN_008f6890(2, this, 0x17);
        else
            bucket->Push((FreeNode_3db0*)this);
    }
    return this;
}
}   // namespace f3m_00943db0

// @f3 0x00957f50 (community match, verified in this file)
namespace f3m_00957f50 {
extern "C" void __cdecl blendTwoTransforms(char*, char*, float, char*);
// pdb: hkaSkeletonUtils::blendPartialPoses | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: numBones, bones, poseA, poseB, weight, poseOut
void FUN_00957f50(unsigned int count, short* indices, char* p3, char* p4, float scale, char* p6) {
    for (unsigned int i = 0; i < count; ++i) {
        int offset = (int)indices[i] * 48;
        blendTwoTransforms(p3 + offset, p4 + offset, scale, p6 + offset);
    }
}
}   // namespace f3m_00957f50

// @f3 0x0094f3a0 (community match, verified in this file)
namespace f3m_0094f3a0 {
namespace task94f3a0 {
struct Heap { void* FUN_0086b930(unsigned); }; extern Heap DAT_01090a78;
struct Entry { int unk00,unk04; float unk08; int unk0c; float unk10,unk14,unk18,unk1c; };
struct Owner { int unk00,unk04; void* unk08; Entry* unk0c; void FUN_0094f130(Entry*); Entry* FUN_0094f3a0(bool*); };
Entry* Owner::FUN_0094f3a0(bool* made) {
 if (!unk0c) {
  char* mem=(char*)DAT_01090a78.FUN_0086b930(0x30);
  unsigned char shift=0x10-((unsigned char)(size_t)mem & 15);
  mem+=shift; *((unsigned char*)mem-1)=shift;
  Entry* p=(Entry*)mem;
  p->unk00=0; p->unk04=0; *(volatile float*)&p->unk08=0.0f;
  p->unk1c=p->unk18=p->unk14=p->unk10=1.0f;
  unk0c=p; if (unk08) FUN_0094f130(p);
  *made=true;
 } else *made=false;
 return unk0c;
}
}
}   // namespace f3m_0094f3a0

// @f3 0x00943a60 (community match, verified in this file)
namespace f3m_00943a60 {
struct Ref0943a60 {
    virtual void Destroy(int flag) throw();
    unsigned short m_flag04;
    short m_count06;
};
struct Base0943a60 {
    virtual void v00() throw();
    ~Base0943a60() throw() { }
};
struct FUN_00943a60 : Base0943a60 {
    int unk04;
    Ref0943a60* m_ref08;
    virtual ~FUN_00943a60() throw();
};
// pdb: hkOstream::~hkOstream | hkOStream.obj | fnv360_0822_retail, call_seq, high
FUN_00943a60::~FUN_00943a60()
{
    if (Ref0943a60* p = m_ref08) {
        if (p->m_flag04 != 0) {
            short n = --p->m_count06;
            if (n == 0)
                p->Destroy(1);
        }
    }
}
}   // namespace f3m_00943a60

// @f3 0x00959f00 (community match, verified in this file)
namespace f3m_00959f00 {
namespace f3m_00959f00 {
struct Vec4_9f00 {
    float x, y, z, w;
    Vec4_9f00& operator=(const Vec4_9f00& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
};
struct Matrix3_9f00 {
    Vec4_9f00 col0;
    Vec4_9f00 col1;
    Vec4_9f00 col2;
};
struct Cls_9f00 {
    char pad[0xb0];
    Matrix3_9f00 rotation;
    void FUN_00959f00(Matrix3_9f00& out) const;
};
}
using namespace f3m_00959f00;

void Cls_9f00::FUN_00959f00(Matrix3_9f00& out) const
{
    out = rotation;
}
}   // namespace f3m_00959f00

// @f3 0x0095b1b0 (community match, verified in this file)
namespace f3m_0095b1b0 {
struct FinishLoaded {int finishing;};
struct hkBaseObject {virtual ~hkBaseObject(){}};
struct hkReferencedObject:hkBaseObject {unsigned short memoryFlags;short refCount;hkReferencedObject(FinishLoaded){refCount=1;}};
struct FUN_00d50c90:hkReferencedObject {FUN_00d50c90(FinishLoaded flag):hkReferencedObject(flag){}virtual ~FUN_00d50c90(){}};
struct BridgeAtom {unsigned short type,unk02;void* function;FUN_00d50c90* owner;BridgeAtom(FinishLoaded){FUN_00d21ce0(owner);}void FUN_00d21ce0(FUN_00d50c90*) throw();};
struct hkpMalleableConstraintData:FUN_00d50c90 {FUN_00d50c90* child;float strength; BridgeAtom bridge;hkpMalleableConstraintData(FinishLoaded flag);virtual ~hkpMalleableConstraintData();};
// pdb: hkpMalleableConstraintData::hkpMalleableConstraintData | hkpMalleableConstraintData.obj | fnv360_0822_retail, caller_sim, high
// pdb params: f
hkpMalleableConstraintData::hkpMalleableConstraintData(FinishLoaded flag):FUN_00d50c90(flag),bridge(flag){bridge.FUN_00d21ce0(this);}
}   // namespace f3m_0095b1b0

// @f3 0x00952f10 (community match, verified in this file)
namespace f3m_00952f10 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct FUN_008f6d90_heap
{
    void FUN_008f6d90(void* p, unsigned int bytes, int tag);
};

struct Alloc_01090a78
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Alloc_01090a78 DAT_01090a78;

struct Sub_952f10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pBuffer;
    int unk14;
    unsigned int unk18;
};

struct Owner_952f10
{
    int unk00;
    int unk04;
    int unk08;
    Sub_952f10* m_pSub;
    void FUN_00952f10(bool free);
};

void Owner_952f10::FUN_00952f10(bool free)
{
    if (free)
    {
        Sub_952f10* p = m_pSub;
        if (p)
        {
            if ((p->unk18 & 0x80000000) == 0)
            {
                unsigned int count = p->unk18 & 0x3fffffff;
                FUN_008f6d90_heap* heap = (FUN_008f6d90_heap*)DAT_00d9b080(DAT_010f3170);
                heap->FUN_008f6d90(p->m_pBuffer, count * 4, 0x17);
            }
            DAT_01090a78.FUN_0086ba60(p);
        }
        m_pSub = 0;
    }
}
}   // namespace f3m_00952f10

// @f3 0x009420a0 (community match, verified in this file)
namespace f3m_009420a0 {
namespace f3m_009420a0 {

struct Container9420a0_0C {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    unsigned int FUN_009b4a40();
};

struct Container9420a0_20 {
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

    int FUN_009b4a50(int value);
};

struct Element9420a0 {
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

    int FUN_009b4a50(int value);
};

struct Object9420a0 {
    int unk00;
    int unk04;
    int unk08;
    Container9420a0_0C unk0C;
    Container9420a0_20 unk20;
    Element9420a0 elems[5];
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int count;
    int unk14C;
    int unk150;
    int unk154;
    unsigned char flag158;
    int unk15C;
    int unk160;
    unsigned char flag164;

    void FUN_009420a0(int a0, int a1, char a2);
};

void Object9420a0::FUN_009420a0(int a0, int a1, char a2)
{
    unk15C = a1;
    flag158 = 0;
    *(int volatile*)&unk160 = a0;
    *(unsigned char volatile*)&flag164 = a2;

    for (int i = 0; i < count; i++) {
        elems[i].FUN_009b4a50(1);
    }

    unk20.FUN_009b4a50(count);

    for (int j = 0; j < count; j++) {
        unk0C.FUN_009b4a40();
    }
}
}
}   // namespace f3m_009420a0

// @f3 0x00947dd0 (community match, verified in this file)
namespace f3m_00947dd0 {
namespace f3m_00947dd0 {

using f3m_0094b3d0::NiStreamB3D;
using f3m_0094b3d0::hkReferencedObjectB3D;
using f3m_0094b3d0::NiStreamLoadBinaryB3D;

struct ConstraintData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    hkReferencedObjectB3D* m_pMotor;
    unsigned short m_usState;
    unsigned short m_usSubState;
    int m_iValue;
    bool m_bFlag;
    void FUN_009479e0(hkReferencedObjectB3D* pkOwner);
};

struct Constraint
{
    int unk000;
    ConstraintData* m_pData;
    int unk008;
    void LoadBinaryBase(NiStreamB3D& kStream);
    void FUN_00947dd0(NiStreamB3D& kStream);
};

hkReferencedObjectB3D* FUN_0097a9e0(NiStreamB3D* pkStream);

// pdb: hkBreakableConstraintCinfo::LoadBinary | bhkBreakableConstraint.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: hkHingeConstraintCinfo::LoadBinary)
// pdb params: arStream
void Constraint::FUN_00947dd0(NiStreamB3D& kStream)
{
    LoadBinaryBase(kStream);
    ConstraintData* pData = m_pData;
    hkReferencedObjectB3D* pMotor = FUN_0097a9e0(&kStream);
    pData->FUN_009479e0(pMotor);
    pMotor->removeReference();
    NiStreamLoadBinaryB3D(*kStream.m_pkIstr, pData->m_iValue);
    NiStreamLoadBinaryB3D(*kStream.m_pkIstr, pData->m_bFlag);
}

}
}   // namespace f3m_00947dd0

// @f3 0x00954840 (community match, verified in this file)
namespace f3m_00953550 {

struct IntArr_954840 {
    int* data;
    int count;
    int capacityAndFlags;
    int IndexOf(int value) const {
        int n = count;
        int i = 0;
        if (n > 0) {
            const int* p = data;
            do {
                if (*p == value)
                    return i;
                ++i;
                ++p;
            } while (i < n);
        }
        return -1;
    }
};

struct Owner_954840 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    IntArr_954840 items;
    void FUN_00954840(int value);
};

// pdb: hkpPhysicsContext::addWorldAddedListener | hkpPhysicsContext.obj | fnv360_0721_beta, call_gap, low
// pdb params: cb
void Owner_954840::FUN_00954840(int value)
{
    IntArr_954840* arr = &items;
    if (arr->IndexOf(value) >= 0)
        return;
    if (arr->count == (arr->capacityAndFlags & 0x3fffffff))
        FUN_00901f10(arr, 4);
    arr->data[arr->count] = value;
    arr->count = arr->count + 1;
}
}

// @f3 0x00942160 (community match, verified in this file)
namespace f3m_00942160 {

namespace f3m_00942160 {
struct QHandle {
    void* m_handle;
    void FUN_009b4a40();
    void FUN_009b4a50(int arg);
};
struct QSlot {
    bool m_bFlag;
    QHandle m_handle;
    int unk08; int unk0c; int unk10; int unk14; int unk18;
    int unk1c; int unk20; int unk24; int unk28; int unk2c;
};
struct QObj {
    int unk00; int unk04; int unk08;
    QHandle m_handle0c;
    int unk10; int unk14; int unk18; int unk1c; int unk20;
    bool m_b24;
    int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    QSlot m_slots[5];
    int unk134; int unk138; int unk13c; int unk140; int unk144;
    int m_count;
    void FUN_00942060();
    void FUN_00942160();
};

void QObj::FUN_00942160()
{
    FUN_00942060();
    for (int i = 0; i < m_count; i++) {
        m_slots[i].m_bFlag = true;
        m_slots[i].m_handle.FUN_009b4a50(1);
    }
    for (int i = 0; i < m_count; i++) {
        m_handle0c.FUN_009b4a40();
    }
}
}
}   // namespace f3m_00942160

// @f3 0x0094d600 (community match, verified in this file)
namespace f3m_0094d600 {

extern int DAT_010f3174;
extern int DAT_010f32c0;
extern int DAT_01169204;

struct F3CritSec {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
extern F3CritSec DAT_010f3194;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(F3CritSec* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(F3CritSec* cs);

struct NiMemObject {
    static void* operator new(unsigned int size);
};

struct BaseObject : NiMemObject {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    int unk04;
    int unk08;
    BaseObject();
};

struct ShapeA : BaseObject {
    int m0c;
    int m10;
    ShapeA() : m0c(0), m10(0) { ++DAT_010f3174; }
    virtual void r0();
    virtual void r2();
};

struct ShapeB : ShapeA {
    ShapeB() { ++DAT_010f32c0; }
    virtual void r0();
    virtual void r2();
};

struct ShapeC : ShapeB {
    ShapeC() { ++DAT_01169204; }
    virtual void r0();
    virtual void r2();
};

class Owner {
public:
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void s040();
    virtual void s044();
    virtual void s048();
    virtual void s04c();
    virtual void s050();
    virtual void s054();
    virtual void s058();
    virtual void s05c();
    virtual void s060();
    virtual void s064();
    virtual void s068();
    virtual void s06c();
    virtual void s070();
    virtual void s074();
    virtual void s078();
    virtual void s07c();
    virtual void s080();
    virtual void s084();
    virtual void s088();
    virtual void s08c();
    virtual void s090();
    virtual void s094();
    virtual void s098();
    virtual void s09c();
    virtual void s0a0();
    virtual void s0a4();
    virtual void s0a8();
    virtual void s0ac();
    virtual void s0b0();
    virtual void s0b4();
    virtual void s0b8();
    virtual void s0bc();
    virtual void Attach(ShapeC* p, int arg);
    ShapeC* FUN_0094d600(int arg);
};

// pdb: bhkMoppBvTreeShape::CreateClone | bhkMoppBvTreeShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
ShapeC* Owner::FUN_0094d600(int arg)
{
    EnterCriticalSection(&DAT_010f3194);
    ShapeC* p = new ShapeC;
    this->Attach(p, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return p;
}

}

// @f3 0x00954a30 (community match, verified in this file)
namespace f3m_00954a30 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
// pdb: hkProcessContext::~hkProcessContext | hkpPhysicsContext.obj | fnv360_0822_retail, call_seq, medium
namespace Clear364{extern unsigned long DAT_010f3170;extern int DAT_00e7bf2c;struct Heap{void FUN_008f6d90(void*,unsigned int,int);};struct Array{void*data;unsigned int size,capacityFlags;void Free(){if(!(capacityFlags&0x80000000)){unsigned int capacity=capacityFlags&0x3fffffff;Heap*heap=(Heap*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(data,capacity*4,23);}}};struct Owner{void*vtable;unsigned int unk04;Array first;unsigned int unk14,unk18,unk1c,unk20,unk24,unk28;Array second;~Owner();};Owner::~Owner(){vtable=&DAT_00e7bf2c;second.Free();first.Free();}}



}   // namespace f3m_00954a30

// @f3 0x00951ad0 (community match, verified in this file)
namespace f3m_00951ad0 {
namespace f3m_00951ad0 {

struct RefObj
{
    virtual void vf00();
    virtual void vf04();
    long m_ref;   // +0x04
};

struct MidObj
{
    int unk00;
    int unk04;
    RefObj* m_pRef;   // +0x08
};

struct OuterObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MidObj* m_pMid;   // +0x18
};

struct BaseObj
{
    void FUN_8f75e0(bool b);
};

struct Cls : BaseObj
{
    int unk00;
    int unk04;
    OuterObj* m_pOuter;   // +0x08
    void FUN_00951ad0(bool b);
};

// pdb: bhkConvexTransformShape::CanShare | bhkConvexTransformShape.obj | fnv360_0721_retail, objrun, low, conflict (bridge: bhkConvexTransformShape::Link)
// pdb params: arCloneData
void Cls::FUN_00951ad0(bool b)
{
    if (b) {
        if (this && m_pOuter && m_pOuter->m_pMid && m_pOuter->m_pMid->m_pRef)
            InterlockedIncrement(&m_pOuter->m_pMid->m_pRef->m_ref);
    } else {
        RefObj* p;
        if (this && m_pOuter && m_pOuter->m_pMid && (p = m_pOuter->m_pMid->m_pRef)) {
            if (InterlockedDecrement(&p->m_ref) == 0)
                p->vf04();
        }
    }
    FUN_8f75e0(b);
}

}
}   // namespace f3m_00951ad0

// @f3 0x0094e730 (community match, verified in this file)
#include <new>
extern int DAT_010f3174;
extern int DAT_011697cc;
extern int DAT_0116921c;
namespace f3m_0094e730 {

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* cs);

void* __cdecl FUN_0089eb90(unsigned int size);

struct FUN_008f7c10 {
    FUN_008f7c10();
    virtual ~FUN_008f7c10();
};
struct FUN_00dcdbac : FUN_008f7c10 {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dcdbac() { unk0C = 0; unk10 = 0; ++DAT_010f3174; }
    virtual ~FUN_00dcdbac();
};
struct FUN_00e7b47c : FUN_00dcdbac {
    FUN_00e7b47c() { ++DAT_011697cc; }
    virtual ~FUN_00e7b47c();
};
struct FUN_00e7b39c : FUN_00e7b47c {
    FUN_00e7b39c() { ++DAT_0116921c; }
    virtual ~FUN_00e7b39c();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { }
};

struct Mgr94e730 {
    virtual void vt00();
    virtual void vt01();
    virtual void vt02();
    virtual void vt03();
    virtual void vt04();
    virtual void vt05();
    virtual void vt06();
    virtual void vt07();
    virtual void vt08();
    virtual void vt09();
    virtual void vt0A();
    virtual void vt0B();
    virtual void vt0C();
    virtual void vt0D();
    virtual void vt0E();
    virtual void vt0F();
    virtual void vt10();
    virtual void vt11();
    virtual void vt12();
    virtual void vt13();
    virtual void vt14();
    virtual void vt15();
    virtual void vt16();
    virtual void vt17();
    virtual void vt18();
    virtual void vt19();
    virtual void vt1A();
    virtual void vt1B();
    virtual void vt1C();
    virtual void vt1D();
    virtual void vt1E();
    virtual void vt1F();
    virtual void vt20();
    virtual void vt21();
    virtual void vt22();
    virtual void vt23();
    virtual void vt24();
    virtual void vt25();
    virtual void vt26();
    virtual void vt27();
    virtual void vt28();
    virtual void vt29();
    virtual void vt2A();
    virtual void vt2B();
    virtual void vt2C();
    virtual void vt2D();
    virtual void vt2E();
    virtual void vt2F();
    virtual void vt30(void* obj, int a1);
    FUN_00e7b39c* FUN_0094e730(int a1);
};

// pdb: bhkPlaneShape::CreateObject | bhkPlaneShape.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkPlaneShape::CreateClone)
FUN_00e7b39c* Mgr94e730::FUN_0094e730(int a1)
{
    EnterCriticalSection((_RTL_CRITICAL_SECTION*)&DAT_010f3194);
    FUN_00e7b39c* p = new FUN_00e7b39c();
    this->vt30(p, a1);
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)&DAT_010f3194);
    return p;
}
}   // namespace f3m_0094e730

// @f3 0x0094e610 (community match, verified in this file)
// 0x0094e610
struct E610Helper {
    void FUN_008f75b0(f3m_0094ebf0::Child_ebf0* p);
};

// pdb: bhkPlaneShape::`scalar deleting destructor' | bhkPlaneShape.obj | fnv360_0822_retail, objrun, medium
void FUN_0094ebf0_Owner::FUN_0094e610(f3m_0094ebf0::Child_ebf0* c)
{
    ((E610Helper*)this)->FUN_008f75b0(c);
    if (!this)
        return;
    f3m_0094ebf0::Child_ebf0* p = (f3m_0094ebf0::Child_ebf0*)parent08;
    if (!p)
        return;

    c->f30 = p->f20;
    c->f34 = p->f24;
    c->f38 = p->f28;
    c->f3C = p->f2C;
    c->f20 = p->f30;
    c->f24 = p->f34;
    c->f28 = p->f38;
    c->f2C = p->f3C;
    c->f10 = p->f10;
    c->f14 = p->f14;
    c->f18 = p->f18;
    c->f1C = p->f1C;
}

// @f3 0x00948ed0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00948ed0 {
struct Stream948 {
    int unk00;
    int unk04;
    int (__cdecl *fn08)(Stream948*, void*, int, int*, int);
    static inline void Load(Stream948* s, void* p, int n) { int sz = n; s->unk04 += s->fn08(s, p, n, &sz, 1); }
};
struct Owner948 {
    int unk00;
    unsigned char* m04;
    void FUN_008fc580(void* stream);
    void FUN_00948ed0(void* stream);
};
static inline void Sw948(unsigned int* p) { *p = _byteswap_ulong(*p); }
void Owner948::FUN_00948ed0(void* stream_) {
    unsigned char* stream = (unsigned char*)stream_;
    FUN_008fc580(stream);
    unsigned char* base = m04;
    Stream948* s = *(Stream948**)(stream + 0x24c);
    s->unk04 += s->fn08(s, base + 0x20, 0x10, 0, 0);
    unsigned int* b = (unsigned int*)(base + 0x30);
    s = *(Stream948**)(stream + 0x24c);
    s->unk04 += s->fn08(s, b, 0x10, 0, 0);
    Stream948::Load(*(Stream948**)(stream + 0x24c), base + 0x44, 4);
    if (stream[0x1e5] != 1) {
        unsigned int* a = (unsigned int*)(base + 0x20);
        Sw948(a + 0); Sw948(a + 1); Sw948(a + 2); Sw948(a + 3);
        Sw948(b + 0); Sw948(b + 1); Sw948(b + 2); Sw948(b + 3);
    }
}
}   // namespace f3m_00948ed0

// @f3 0x0094c710 (community match, verified in this file)
namespace f3m_0094c710 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace Factory382{
extern int DAT_010f3194,DAT_00e1c304,DAT_00e7b01c,DAT_00e7af3c;extern unsigned int DAT_010f31f8,DAT_011697c0,DAT_011691ec;void*__cdecl FUN_0089eb90(unsigned int);
struct FUN_008f7c10{void*vtable;unsigned int unk04,unk08;void*data;FUN_008f7c10();};
struct First:FUN_008f7c10{First(){vtable=&DAT_00e1c304;data=0;++DAT_010f31f8;}};
struct Second:First{Second(){vtable=&DAT_00e7b01c;++DAT_011697c0;}};
struct Object:Second{Object(){vtable=&DAT_00e7af3c;++DAT_011691ec;}static void*operator new(unsigned int size){return FUN_0089eb90(size);}};
struct Owner{void FUN_009e1350(Object*,void*);Object*FUN_0094c710(void*);};
// pdb: bhkBallSocketConstraintChain::CreateClone | bhkBallSocketConstraintChain.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
Object*Owner::FUN_0094c710(void*input){EnterCriticalSection(&DAT_010f3194);Object*object=new Object;FUN_009e1350(object,input);LeaveCriticalSection(&DAT_010f3194);return object;}
}
}   // namespace f3m_0094c710

// @f3 0x0094c260 (community match, verified in this file)
namespace f3m_0094c260 {
namespace f3m_0094c260 {

struct NiBinaryStreamW {
    void* m_vtbl;
    unsigned int m_uiPosition;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamW*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamW*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiPosition += uiBytesWritten;
        return uiBytesWritten;
    }
};

struct NiStreamW {
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
    unsigned char unk1E4;
    unsigned char m_ucEndian;
    unsigned char unk1E6;
    unsigned char unk1E7;
    int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C;
    NiBinaryStreamW* m_pBackingStream;
};

template <class T>
inline void NiBinaryStreamSave(NiBinaryStreamW& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

struct ConstraintDataW {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    f3m_0094b3d0::hkRotationB3D m_kFrameA;
    f3m_0094b3d0::hkRotationB3D m_kFrameB;
    int unk80;
    float m_f84;
    float m_f88;
};

struct ConstraintW {
    int unk00;
    ConstraintDataW* m_pData;
    void SaveBinaryBase(NiStreamW& kStream);
    void FUN_0094c260(NiStreamW& kStream);
};

void ConstraintW::FUN_0094c260(NiStreamW& kStream)
{
    ConstraintDataW* pData = m_pData;
    if (kStream.m_ucEndian != 1)
    {
        f3m_0094b3d0::SwapRotationB3D(&pData->m_kFrameA);
        f3m_0094b3d0::SwapRotationB3D(&pData->m_kFrameB);
    }
    NiBinaryStreamSave(*kStream.m_pBackingStream, &pData->m_kFrameA);
    NiBinaryStreamSave(*kStream.m_pBackingStream, &pData->m_kFrameB);
    NiBinaryStreamSave(*kStream.m_pBackingStream, &pData->m_f84);
    NiBinaryStreamSave(*kStream.m_pBackingStream, &pData->m_f88);
    SaveBinaryBase(kStream);
    if (kStream.m_ucEndian != 1)
    {
        f3m_0094b3d0::SwapRotationB3D(&pData->m_kFrameA);
        f3m_0094b3d0::SwapRotationB3D(&pData->m_kFrameB);
    }
}

}
}   // namespace f3m_0094c260

// @f3 0x009527b0 (community match, verified in this file)
namespace f3m_009527b0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace Release388{struct Ref{virtual void v0();virtual void Destroy();long refs;};struct Node{unsigned int unk00,unk04;Ref*object;};struct Collection{virtual void v0();virtual unsigned int Count();};struct Holder{
unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
Collection collection;
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
Node**data;};struct Owner{unsigned int unk00,unk04;Holder*holder;Node*Get(unsigned int i){return holder?holder->data[i]:0;}void FUN_009527b0();};
// pdb: bhkConvexListShape::AddbhkShapeRef | bhkConvexListShape.obj | fnv360_0721_beta, objrun_sim, low, conflict (bridge: bhkConvexListShape::RembhkShapeRef)
void Owner::FUN_009527b0(){if(!this)return;Holder*h=holder;if(h){unsigned int count=h->collection.Count();while(count){--count;Node*node=Get(count);if(node){Ref*object=node->object;if(object&&!InterlockedDecrement(&object->refs))object->Destroy();}}}}
}

}   // namespace f3m_009527b0

// @f3 0x00959db0 (community match, verified in this file)
namespace f3m_00959db0 {
namespace Copy392{struct Matrix{float values[12];};struct Owner{unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;float values[12];void FUN_00959db0(float*);};void Owner::FUN_00959db0(float*output){
output[0]=values[0];
output[1]=values[1];
output[2]=values[2];
output[3]=values[3];
output[4]=values[4];
output[5]=values[5];
output[6]=values[6];
output[7]=values[7];
output[8]=values[8];
output[9]=values[9];
output[10]=values[10];
output[11]=values[11];
}}

}   // namespace f3m_00959db0

// @f3 0x00953070 (community match, verified in this file)
namespace f3m_00953070 {
// pdb: hkVisualDebugger::deleteClient | hkVisualDebugger.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
namespace Erase412{struct Ref{virtual ~Ref();unsigned short memory;short refs;unsigned int Count()const{return refs;}void Release(){if(memory){--refs;if((unsigned short)Count()==0)delete this;}}};struct Pair{Ref*first;Ref*second;~Pair(){if(second)second->Release();if(first)first->Release();}};struct Owner{unsigned int unk00,unk04,unk08;Pair*data;unsigned int count;void hkVisualDebugger_deleteClient(unsigned int);};void Owner::hkVisualDebugger_deleteClient(unsigned int index){Pair*pair=data+index;pair->~Pair();--count;data[index]=data[count];}}
}   // namespace f3m_00953070

// @f3 0x00947710 (community match, verified in this file)
namespace f3m_00947710 {
namespace Lazy423{struct Heap{void*FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;struct FUN_009476b0{
unsigned int unk00;
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
// pdb: bhkAngularDashpotAction::KillCinfo | bhkAngularDashpotAction.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: abCreated
FUN_009476b0()throw();static void*operator new(unsigned int size){return DAT_01090a78.FUN_0086b930(size);}};struct Owner{unsigned int unk00,unk04;void*source;FUN_009476b0*object;void FUN_00947390(FUN_009476b0*);FUN_009476b0*FUN_00947710(bool*);};FUN_009476b0*Owner::FUN_00947710(bool*created){if(!object){object=new FUN_009476b0;if(source)FUN_00947390(object);*created=true;}else *created=false;return object;}}
}   // namespace f3m_00947710

// @f3 0x0094ca20 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094ca20 {
// FUN_0094ca20 -- lazy creation of an object from the TLS memory pool.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct MemPool_ca20 {
    void* FUN_008f6d30(unsigned int uiSize, unsigned int uiType);
    void FUN_008f6d90(void* p, unsigned int uiSize, unsigned int uiType);
};

struct FUN_00d53d90 {
    virtual void v00();
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;

    FUN_00d53d90();

    static void* operator new(unsigned int uiSize) {
        MemPool_ca20* pool = (MemPool_ca20*)TlsGetValue(DAT_010f3170);
        void* p = pool->FUN_008f6d30(uiSize, 0x2c);
        *(unsigned short*)((char*)p + 4) = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) {
        MemPool_ca20* pool = (MemPool_ca20*)TlsGetValue(DAT_010f3170);
        unsigned int size = *(unsigned short*)((char*)p + 4);
        pool->FUN_008f6d90(p, size, 0x2c);
    }
};

struct Owner_ca20 {
    int unk00;
    FUN_00d53d90* unk04;
    unsigned int FUN_0094ca20();
};

// pdb: hkBallSocketChainCinfo::CreateData | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, caller_sim, medium
unsigned int Owner_ca20::FUN_0094ca20()
{
    if (!unk04)
        unk04 = new FUN_00d53d90;
    return 0x34;
}
}   // namespace f3m_0094ca20

// @f3 0x0094d380 (community match, verified in this file)
extern const void* DAT_00e37160[];
namespace f3m_0094d380 {
namespace f3m_0094d380 {


class CinfoBase {
public:
    const void** m_vtbl;
};

class CinfoRef {
public:
    void* m_pRef;
    int m_refCount;
};

class CinfoConf {
public:
    int unk0C;
    int unk10;
};

class Cinfo : public CinfoBase, public CinfoRef, public CinfoConf {
public:
    static void* operator new(unsigned int n) throw() { return DAT_01090a78.FUN_0086b930(n); }
    Cinfo();
};

Cinfo::Cinfo()
{
    m_pRef = 0;
    unk0C = 0;
    unk10 = 0;
    m_refCount = 1;
    m_vtbl = DAT_00e37160;
}

class Owner {
public:
    int unk00;
    int unk04;
    void* m_pSource;
    CinfoRef* m_pChild;
    void FUN_008fc420(Cinfo* p);
    CinfoRef* FUN_0094d380(bool* pbCreated);
};

// pdb: bhkBallAndSocketConstraint::CreateCinfo | bhkBallAndSocketConstraint.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arCreated
CinfoRef* Owner::FUN_0094d380(bool* pbCreated)
{
    if (m_pChild == 0) {
        Cinfo* p = new Cinfo();
        m_pChild = p;
        if (m_pSource != 0)
            FUN_008fc420((Cinfo*)m_pChild);
        *pbCreated = true;
        return m_pChild;
    }
    *pbCreated = false;
    return m_pChild;
}

}
}   // namespace f3m_0094d380

// @f3 0x00944310 (community match, verified in this file)
extern const unsigned char DAT_01169784[];
namespace f3m_00944310 {
struct FUN_00d46d40_s {const char* name;const char* FUN_00d46d40();};
namespace named_variant_save {
struct FUN_009d7150 {const char* name;const char* className;void* object;FUN_00d46d40_s* type;FUN_009d7150(const char*,void*,FUN_00d46d40_s*);};
struct Array {FUN_009d7150* data;int count;};
void __cdecl FUN_009441c0(void*,Array*,const void*,void*,unsigned int,void*,int);
void* __cdecl FUN_00944310(void* result,void* object,FUN_00d46d40_s* type,void* output,unsigned int flags,void* options){FUN_009d7150 item(type->FUN_00d46d40(),object,type);Array array;array.data=&item;array.count=1;FUN_009441c0(result,&array,DAT_01169784,output,flags,options,0);return result;}
}
}   // namespace f3m_00944310

// @f3 0x00946f30 (community match, verified in this file)
namespace f3m_00946f30 {
namespace M46 = f3m_009461b0::f3m_009461b0;
struct Data10_46 : M46::Data {
    __forceinline void Swap10() volatile {
        value10 = _byteswap_ulong(value10);
        value14 = _byteswap_ulong(value14);
        value18 = _byteswap_ulong(value18);
        value1c = _byteswap_ulong(value1c);
        value20 = _byteswap_ulong(value20);
        value24 = _byteswap_ulong(value24);
        value28 = _byteswap_ulong(value28);
        value2c = _byteswap_ulong(value2c);
        value30 = _byteswap_ulong(value30);
        value34 = _byteswap_ulong(value34);
    }
};
struct FUN_00946f30_cls : M46::Owner {
    void FUN_00946f30(M46::Stream* stream);
};
// pdb: bhkDashpotAction::SaveBinary | bhkDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: arStream
void FUN_00946f30_cls::FUN_00946f30(M46::Stream* stream)
{
    int state;
    if (stream->unk1e4 != 1) {
        Data10_46* data = (Data10_46*)GetData(&state);
        if (data)
            data->Swap10();
    }
    FUN_008fb9a0(stream);
    if (stream->unk1e4 != 1) {
        Data10_46* data = (Data10_46*)GetData(&state);
        if (data)
            data->Swap10();
    }
}
}   // namespace f3m_00946f30

// @f3 0x00959f90 (community match, verified in this file)
namespace f3m_00959f90 {
namespace HK59 = f3m_0094b3d0;
struct FUN_00959f90_cls {
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
    HK59::hkReferencedObjectB3D* firstSlot;
    void FUN_00959f90(unsigned int index, HK59::hkReferencedObjectB3D* replacement);
};
// pdb: hkpRagdollConstraintData::setMotor | hkpRagdollConstraintData.obj | fnv360_0822_retail, objrun, medium
// pdb params: index, newMotor
void FUN_00959f90_cls::FUN_00959f90(unsigned int index, HK59::hkReferencedObjectB3D* replacement)
{
    if (replacement && replacement->m_memSizeAndFlags != 0)
        replacement->m_referenceCount++;
    HK59::hkReferencedObjectB3D* old = ((HK59::hkReferencedObjectB3D**)&firstSlot)[index];
    if (old)
        old->removeReference();
    ((HK59::hkReferencedObjectB3D**)&firstSlot)[index] = replacement;
}
}   // namespace f3m_00959f90

// @f3 0x0095d210 (community match, verified in this file)
extern const void* const DAT_00dcc494[];
namespace f3m_0095d210 {
namespace deletion_0095d210 {
extern unsigned int DAT_010f3170;extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void FUN_008f6d90(void*,int,int);};
struct Header {const void* const* vtable;unsigned short memorySizeAndFlags;short refCount;Header* FUN_0095d210(unsigned int);};
// pdb: hkaFootPlacementIkSolver::`scalar deleting destructor' | hkaFootPlacementIkSolver.obj | fnv360_0721_beta, vtable, medium
Header* Header::FUN_0095d210(unsigned int flags){bool release=(flags&1)!=0;vtable=DAT_00dcc494;if(release){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(this,memorySizeAndFlags,61);}return this;}
}
}   // namespace f3m_0095d210

// @f3 0x00944410 (community match, verified in this file)
namespace loader_delete {
extern unsigned int DAT_010f3170;
extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void FUN_008f6d90(void*,unsigned int,int);};
struct Loader {void* vtable;unsigned short size,refs;void FUN_009d6ef0();Loader* FUN_00944410(unsigned int);};
// pdb: hkArrayUtil::destruct<hkRootLevelContainer::NamedVariant> | hkpHavokSnapshot.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkLoader::`vector deleting destructor')
// pdb params: t, n, __formal
Loader* Loader::FUN_00944410(unsigned int flags) {
    FUN_009d6ef0();
    if(flags&1){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(this,size,6);}
    return this;
}
}

// @f3 0x0095b1e0 (community match, verified in this file)
namespace f3m_0095b1e0 {
struct RefObject {virtual void* Destroy(unsigned int);unsigned short allocationBytes;short references;
void RemoveReference(){if(allocationBytes!=0){--references;if(references==0)Destroy(1);}}};
extern const void* DAT_00dcc494[];
extern const void* DAT_00e367bc[];
struct MalleableHeader {const void** vtable;unsigned short allocationBytes;short references;void* userData;RefObject* child;void FUN_0095b1e0();};
// pdb: hkpMalleableConstraintData::~hkpMalleableConstraintData | hkpMalleableConstraintData.obj | fnv360_0822_retail, call_seq, high
void MalleableHeader::FUN_0095b1e0(){RefObject* object=child;vtable=DAT_00e367bc;object->RemoveReference();vtable=DAT_00dcc494;}
}   // namespace f3m_0095b1e0

// @f3 0x00947be0 (community match, verified in this file)
namespace f3m_00947be0 {
struct Child {void FUN_009479e0(Child*);};
struct Pair {unsigned int first,second;};
struct Owner {unsigned int unk00;Child* child;unsigned int unk08;Pair value;void FUN_00947be0(const Owner*);};
// pdb: hkRagdollLimitsConstraintCinfo::SetInBodySpace | bhkRagdollLimitsConstraint.obj | fnv360_0822_debug, objrun_open, low
// pdb params: arPlaneInA, arPlaneInB, arTwistInA, arTwistInB
void Owner::FUN_00947be0(const Owner* other){if(other){if(child)child->FUN_009479e0(other->child);unsigned int high=other->value.second;value.first=other->value.first;value.second=high;}}
}   // namespace f3m_00947be0

// @f3 0x009466f0 (community match, verified in this file)
namespace f3m_009466f0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace task1568 {
extern int DAT_010f3194,DAT_010f31ac,DAT_010f31b8,DAT_01169168;
extern int DAT_00dc050c,DAT_00dc05d4,DAT_00e7a4ec;
void* FUN_0089eb90(unsigned);void FUN_0089ebd0(void*);
struct Obj{void* table;unsigned refs,value,data;void FUN_008f7c10();static void* operator new(unsigned n)throw(){return FUN_0089eb90(n);}static void operator delete(void* p){FUN_0089ebd0(p);}Obj(){FUN_008f7c10();table=&DAT_00dc050c;int one=1;data=0;DAT_010f31ac+=one;table=&DAT_00dc05d4;DAT_010f31b8+=one;table=&DAT_00e7a4ec;DAT_01169168+=one;}};
struct C{void FUN_008f8870(Obj*,int);Obj* FUN_009466f0(int);};
// pdb: bhkMotorAction::CreateObject | bhkMotorAction.obj | fnv360_0721_beta, objrun, medium
Obj* C::FUN_009466f0(int arg){EnterCriticalSection(&DAT_010f3194);Obj* result=new Obj;FUN_008f8870(result,arg);LeaveCriticalSection(&DAT_010f3194);return result;}
}
}   // namespace f3m_009466f0

// @f3 0x00943aa0 (community match, verified in this file)
namespace f3m_00943aa0 {
namespace reference_assignment {
struct RefObject {virtual void* Destroy(unsigned int);unsigned short allocationBytes;short references;
void Retain(){if(allocationBytes!=0)++references;}
void Release(){if(allocationBytes!=0){--references;if(references==0)Destroy(1);}}};
struct Owner {unsigned int unk00,unk04;RefObject* child;void FUN_00943aa0(RefObject*);};
void Owner::FUN_00943aa0(RefObject* value){value->Retain();child->Release();child=value;}
}
}   // namespace f3m_00943aa0

// @f3 0x00947090 (community match, verified in this file)
namespace f3m_00947090 {
namespace aligned_lazy_state {
struct Heap {void* FUN_0086b930(unsigned int);};extern Heap DAT_01090a78;
struct State {unsigned int unk00;unsigned int unk04;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2C;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3C;State* FUN_00947030();};
struct Owner {unsigned int unk00,unk04;void* source;State* state;void FUN_00946c30(State*);State* FUN_00947090(bool*);};
State* Owner::FUN_00947090(bool* created){if(!state){unsigned char* raw=(unsigned char*)DAT_01090a78.FUN_0086b930(sizeof(State)+16);unsigned char padding=16-((unsigned int)raw&15);raw+=padding;raw[-1]=padding;state=((State*)raw)->FUN_00947030();if(source)FUN_00946c30(state);*created=true;return state;}*created=false;return state;}
}
}   // namespace f3m_00947090

// @f3 0x009427c0 (community match, verified in this file)
namespace f3m_009427c0 {
namespace count_adjustment {
struct Owner {unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;int count;int FUN_00942700();int FUN_00942210();int FUN_009427c0(int);};
// pdb: hkCpuJobThreadPool::setNumThreads | hkCpuJobThreadPool.obj | tesv_win, objrun_open, low
int Owner::FUN_009427c0(int desired){while(count<desired&&!FUN_00942700()){}while(count>desired&&!FUN_00942210()){}return count;}
}
}   // namespace f3m_009427c0

// @f3 0x00954b60 (community match, verified in this file)
extern unsigned int DAT_01060390;extern const double DAT_00dc2748;
namespace f3m_00954b60 {
namespace random_fraction {
float __cdecl FUN_00954b60(){unsigned int value=(12345u-DAT_01060390*0x3E39B193u)&0x7FFFFFFFu;DAT_01060390=value;float result=(float)value*DAT_00dc2748;return result;}
}
}   // namespace f3m_00954b60

// @f3 0x00950390 (community match, verified in this file)
namespace f3m_00950390 {
namespace f3m_00950390 {

struct Vec4 {
    float x, y, z, w;
    Vec4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
};

struct Vec5 {
    float v0, v1, v2, v3, v4;
    Vec5& operator*=(float s) { v0 *= s; v1 *= s; v2 *= s; v3 *= s; v4 *= s; return *this; }
};

struct Result950390 {
    int unk00, unk04, unk08, unk0C;
    Vec4 m_kVec10;
    Vec5 m_kVec20;
};

class FUN_00c84df0_cls {
public:
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
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0();
    virtual Result950390* vB4(char* out);
    int unk04, unk08, unk0C;
    float m_f10;
    void FUN_00950390(FUN_00c84df0_cls* apArg1, FUN_00c84df0_cls* apArg2);
    void bhkShape_CopyMembers(FUN_00c84df0_cls* apArg1, FUN_00c84df0_cls* apArg2);
};

void FUN_00c84df0_cls::FUN_00950390(FUN_00c84df0_cls* apArg1, FUN_00c84df0_cls* apArg2)
{
    char local;
    Result950390* result = vB4(&local);
    if (result) {
        float scale = apArg2->m_f10;
        if (scale != 1.0f) {
            result->m_kVec10 *= scale;
            result->m_kVec20 *= scale;
        }
    }
    bhkShape_CopyMembers(apArg1, apArg2);
}

}
}   // namespace f3m_00950390

// @f3 0x00948b60 (community match, verified in this file)
extern void* DAT_00e7a9c4;
namespace f3m_00948b60 {
namespace f3m_00948b60 {


struct X948b60 {
    void* m_pDesc;
};

struct Elem948b60 {
};

struct Obj948b60 : X948b60, Elem948b60 {
    int m04;
    int m08;
    int m0C;
    int m10;
    Obj948b60()
    {
        m04 = 0;
        m0C = 0;
        m10 = 0;
        m08 = 1;
        m_pDesc = &DAT_00e7a9c4;
    }
};

struct Owner948b60 {
    int unk00;
    int unk04;
    void* unk08;
    Elem948b60* m_pElem;
    void FUN_008fc420(Obj948b60* p);
    Elem948b60* FUN_00948b60(bool* pb);
};

// pdb: bhkWheelConstraint::CreateCinfo | bhkWheelConstraint.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arCreated
Elem948b60* Owner948b60::FUN_00948b60(bool* pb)
{
    if (!m_pElem) {
        Obj948b60* p = new (f3m_0094ebf0::DAT_01090a78.FUN_0086b930(0x14), 0) Obj948b60();
        m_pElem = p;
        if (unk08)
            FUN_008fc420(static_cast<Obj948b60*>(m_pElem));
        *pb = true;
        return m_pElem;
    }
    *pb = false;
    return m_pElem;
}
}
}   // namespace f3m_00948b60

// @f3 0x00948750 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00948750 {
extern "C" void* (__stdcall* const g_pfnTlsGetValue)(unsigned long);

namespace f3m_00948750 {

struct MemoryContext {
    void* FUN_008f6d30(unsigned int size, unsigned int category);
};

struct Block {
    static void* operator new(unsigned int) {
        MemoryContext* context = (MemoryContext*)g_pfnTlsGetValue(DAT_010f3170);
        char* block = (char*)context->FUN_008f6d30(0x160, 0x2c);
        *(unsigned short*)(block + 4) = 0x160;
        return block;
    }
    static void operator delete(void* block);
    Block();
};

struct Owner {
    int unk00;
    Block* unk04;
    unsigned int FUN_00948750();
};

unsigned int Owner::FUN_00948750()
{
    if (!unk04)
        unk04 = new Block;
    return 0x160;
}
}
}   // namespace f3m_00948750

// @f3 0x00944d50 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00944d50 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace f3m_00944d50 {

struct MemoryContext {
    void* FUN_008f6f60(unsigned int size, int category);
};

struct Reader {
    int unk00;
    unsigned int m_04;
    unsigned int (__cdecl* m_08)(Reader*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p) {
        unsigned int size = 4;
        unsigned int n = m_08(this, p, 4, &size, 1);
        m_04 += n;
        return n;
    }
};

struct Context {
    int unk000[0x24c / 4];
    Reader* m_pReader;
};

struct Elem {
    int unk00[0x30 / 4];
    static void* operator new[](unsigned int size) {
        MemoryContext* context = (MemoryContext*)TlsGetValue(DAT_010f3170);
        return context->FUN_008f6f60(size, 9);
    }
};

void __cdecl FUN_009795b0(Context* ctx, Elem* elem);

struct Obj {
    unsigned int m_count;
    Elem* m_pData;

    void FUN_00944d50(Context* ctx);
};

// pdb: bhkPoseArray::bhkPose::LoadBinary | bhkPoseArray.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkbGeneratorOutput::hkbGeneratorOutput)
// pdb params: arStream
void Obj::FUN_00944d50(Context* ctx)
{
    ctx->m_pReader->Read(this);
    unsigned int count = m_count;
    if (count > 0) {
        m_pData = new Elem[count];
    }
    for (unsigned int i = 0; i < m_count; ++i) {
        FUN_009795b0(ctx, &m_pData[i]);
    }
}
}
}   // namespace f3m_00944d50

// @f3 0x009440c0 (community match, verified in this file)
struct QRegObj;
struct QNameSrc {
    const char* FUN_009b0490() const;
};
extern QNameSrc DAT_01169724;
struct QRefObj {
    virtual void vf00();
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    void addReference() {
        if (m_memSizeAndFlags != 0) ++m_referenceCount;
    }
};
struct QRegObj {
    void* m_entries;
    int m_count;
    void* FUN_009d71d0(const char* name, int key);
    void* FUN_009d7250(const char* name, int key);
};
struct QRefBase {
    virtual void vf00();
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    QRefBase() : m_referenceCount(1) {}
    void FUN_009d6ef0();
};
struct QHolder : QRefBase {
    void** m_data;
    int m_count;
    int m_capacityAndFlags;
    QHolder() : m_data(0), m_count(0), m_capacityAndFlags(0x80000000) {}
    QRegObj* FUN_009d7090(const char* name);
};

// pdb: hkpHavokSnapshot::load | hkpHavokSnapshot.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void* hkpHavokSnapshot_load(const char* name, void** out)
{
    if (!name || !out)
        return 0;
    QHolder holder;
    QRegObj* reg = holder.FUN_009d7090(name);
    if (!reg) {
        holder.FUN_009d6ef0();
        return 0;
    }
    void* found = reg->FUN_009d71d0(DAT_01169724.FUN_009b0490(), 0);
    if (!found) {
        const char* names[3] = { "SnapshotSave", "hkpPhysicsData", 0 };
        int i = 0;
        do {
            found = reg->FUN_009d7250(names[i], 0);
        } while (!found && names[++i]);
    }
    if (found) {
        void* item = holder.m_data[0];
        *out = item;
        ((QRefObj*)item)->addReference();
    }
    holder.FUN_009d6ef0();
    return found;
}

// @f3 0x00944860 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern unsigned long DAT_0116913c;
namespace f3m_00944860 {
namespace f3m_00944860 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);
extern "C" void _ReadWriteBarrier(void);

struct FreeNode {
    FreeNode* m_pNext;
};

struct MemoryContext {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    int unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    FreeNode* m_pFree;
    int m_nFree;
    void FUN_008f6f90(void* p);
    void FUN_008f6890(int index, void* p, int size);
};

struct Buffer {
    void* m_pData;
    void* unk04;
    void* unk08;
    void* unk0C;
    char m_bOwned;
};

// pdb: hkMonitorStream::quit | hkMonitorStream.obj | tesv_win, caller, medium
void __cdecl FUN_00944860(Buffer* pBuffer)
{
    FreeNode* pData = (FreeNode*)pBuffer->m_pData;
    if (pData && pBuffer->m_bOwned) {
        MemoryContext* pCtx = (MemoryContext*)FUN_00d9b080(DAT_010f3170);
        pCtx->FUN_008f6f90(pData);
    }
    FreeNode* pItem = (FreeNode*)FUN_00d9b080(DAT_0116913c);
    if (!pItem)
        return;
    MemoryContext* pPool = (MemoryContext*)FUN_00d9b080(DAT_010f3170);
    if (pPool->m_nFree >= pPool->unk34) {
        pPool->FUN_008f6890(3, pItem, 0x1b);
        return;
    }
    _ReadWriteBarrier();
    pPool->m_nFree++;
    pItem->m_pNext = pPool->m_pFree;
    pPool->m_pFree = pItem;
}
}
}   // namespace f3m_00944860

// @f3 0x00950d10 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00950d10 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();

struct MemoryContext950 {
    void FUN_008f6d90(void* data, int bytes, int category);
};

struct HkArray16 {
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~HkArray16() {
        if ((m_capacityAndFlags & 0x80000000u) == 0) {
            int cap = m_capacityAndFlags & 0x3fffffff;
            MemoryContext950* context = (MemoryContext950*)TlsGetValue(DAT_010f3170);
            context->FUN_008f6d90(m_data, cap << 4, 0x17);
        }
    }
};

struct FUN_00950d10 {
    int unk00;
    float unk04;
    HkArray16 m08;
    HkArray16 m14;
    ~FUN_00950d10();
};

// pdb: bhkConvexVerticesShape::Init | bhkConvexVerticesShape.obj | fnv360_0721_beta, objrun, low, conflict (bridge: hkConvexVerticesShapeCinfo::~hkConvexVerticesShapeCinfo)
// pdb params: arInfo
FUN_00950d10::~FUN_00950d10()
{
}
}   // namespace f3m_00950d10

// @f3 0x00959e60 (community match, verified in this file)
namespace f3m_00959e60 {
namespace f3m_00959e60 {

struct Src12 {
    float f00, f04, f08, f0C;
    float f10, f14, f18, f1C;
    float f20, f24, f28, f2C;
};

struct Owner959E60 {
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    Src12 m_kData;
    void FUN_00959e60(const Src12* src);
};

void Owner959E60::FUN_00959e60(const Src12* src)
{
    m_kData.f00 = src->f00;
    m_kData.f04 = src->f04;
    m_kData.f08 = src->f08;
    m_kData.f0C = src->f0C;
    m_kData.f10 = src->f10;
    m_kData.f14 = src->f14;
    m_kData.f18 = src->f18;
    m_kData.f1C = src->f1C;
    m_kData.f20 = src->f20;
    m_kData.f24 = src->f24;
    m_kData.f28 = src->f28;
    m_kData.f2C = src->f2C;
}

}
}   // namespace f3m_00959e60

// @f3 0x0094c7d0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094c7d0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Pool0094c7d0 {
    void* FUN_008f6d30(unsigned int size, unsigned int tag);
};

class T94c7d0 {
public:
    int unk00;
    unsigned short unk04;
    char pad[0x34 - 6];
    static void* operator new(unsigned int size)
    {
        Pool0094c7d0* pool = (Pool0094c7d0*)TlsGetValue(DAT_010f3170);
        void* p = pool->FUN_008f6d30(size, 0x2c);
        *(unsigned short*)((char*)p + 4) = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
    T94c7d0();
};

struct Owner0094c7d0 {
    void FUN_008fc3f0(T94c7d0* value, int flags);
    void FUN_0094c7d0(T94c7d0* value, int flags);
};

void Owner0094c7d0::FUN_0094c7d0(T94c7d0* value, int flags)
{
    if (!value)
        value = new T94c7d0();
    FUN_008fc3f0(value, flags);
}
}   // namespace f3m_0094c7d0

// @f3 0x00944b30 (community match, verified in this file)
namespace f3m_00944b30 {
namespace f3m_00944b30 {
struct Reader94 { int unk00; int pos; int unk08; int (__cdecl* read)(Reader94* r, void* dst, int size, int* extra, int count); };
struct Ctx94 { char pad[0x250]; Reader94* reader; };
struct Elem94 { char b[0x30]; };
void __cdecl FUN_00979450(Ctx94* ctx, Elem94* e);
static __forceinline void Load94(Reader94* s, void* p, int n)
{
    int sz = n;
    s->pos += s->read(s, p, n, &sz, 1);
}
struct Arr94 { unsigned int count; Elem94* data; void bhkPoseArray_bhkPose_SaveBinary(Ctx94* ctx); };
// pdb: bhkPoseArray::bhkPose::SaveBinary | bhkPoseArray.obj | fnv360_0721_beta, call_seq + skyrim(call_gap), high
void Arr94::bhkPoseArray_bhkPose_SaveBinary(Ctx94* ctx) {
    Reader94* r = ctx->reader;
    Load94(r, this, 4);
    for (unsigned int i = 0; i < count; ++i)
        FUN_00979450(ctx, &data[i]);
}
}
}   // namespace f3m_00944b30

// @f3 0x00942260 (community match, verified in this file)
extern float DAT_00db38b8;
namespace f3m_00942260 {
const float kFloatE32888 = 0.01666666753590107f;

struct Obj4 {
    int m_00;
    void FUN_009b4a10(int, int);
};

struct Sub30 {
    char m_data[0x30];
    void FUN_00941f60();
};

struct FUN_00942260_Object {
    int m_00;
    volatile float m_04;
    volatile float m_08;
    Obj4 m_0c, m_10, m_14, m_18, m_1c, m_20;
    unsigned char m_24;
    char m_pad25[3];
    Sub30 m_arr[6];
    volatile int m_148;
    char m_pad14c[0xc];
    volatile unsigned char m_158;
    char m_pad159[3];
    volatile int m_15c;
    volatile int m_160;
    volatile unsigned char m_164;

    FUN_00942260_Object* FUN_00942260();
};

FUN_00942260_Object* FUN_00942260_Object::FUN_00942260()
{
    m_0c.FUN_009b4a10(0, 0xc);
    m_10.FUN_009b4a10(0, 0xc);
    m_14.FUN_009b4a10(0, 0xc);
    m_18.FUN_009b4a10(0, 0xc);
    m_1c.FUN_009b4a10(0, 0xc);
    m_20.FUN_009b4a10(0, 0xc);
    Sub30* p = m_arr;
    int n = 5;
    do
    {
        p->FUN_00941f60();
        ++p;
    } while (--n >= 0);
    const float f = kFloatE32888;
    m_148 = 0;
    m_24 = 0;
    m_04 = f;
    m_08 = DAT_00db38b8;
    m_00 = 0;
    m_158 = 1;
    m_15c = 0;
    m_160 = 0;
    m_164 = 1;
    return this;
}
}   // namespace f3m_00942260

// @f3 0x00946dd0 (community match, verified in this file)
extern "C" int FUN_0010f31ac;
extern "C" int FUN_0010f31ec;
extern "C" int FUN_001169174;
extern "C" char FUN_00dc050c[];
extern "C" char FUN_00e3454c[];
extern "C" char FUN_00e7a5c4[];
extern "C" char FUN_0010f3194[24];
namespace f3m_00946dd0 {


extern void (__stdcall *FUN_00d9b09c)(void*);
extern void (__stdcall *FUN_00d9b0a0)(void*);

extern "C" void* FUN_0089eb90(unsigned int size);

struct FUN_008f7c10_Base {
    void FUN_008f7c10();
};

struct ZObj_946dd0 {
    void* f0;
    int u4;
    int u8;
    int uc;
    ZObj_946dd0() {
        ((FUN_008f7c10_Base*)this)->FUN_008f7c10();
        f0 = (void*)FUN_00dc050c;
        uc = 0;
        int one = 1;
        FUN_0010f31ac += one;
        f0 = (void*)FUN_00e3454c;
        FUN_0010f31ec += one;
        f0 = (void*)FUN_00e7a5c4;
        FUN_001169174 += one;
    }
    ~ZObj_946dd0() {}
    static void* operator new(unsigned int) throw() { return FUN_0089eb90(0x10); }
    static void operator delete(void*) {}
};

struct FUNOwner {
    void* FUN_00946dd0(int arg);
};

// pdb: bhkDashpotAction::CreateClone | bhkDashpotAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCloneData
void* FUNOwner::FUN_00946dd0(int arg) {
    FUN_00d9b09c(FUN_0010f3194);
    ZObj_946dd0* esi = new ZObj_946dd0();
    int arg2 = arg;
    void* vptr = *(void**)this;
    void (__thiscall *fn)(void*, void*, int) = *(void (__thiscall **)(void*, void*, int))((char*)vptr + 0xcc);
    fn(this, esi, arg2);
    FUN_00d9b0a0(FUN_0010f3194);
    return esi;
}
}   // namespace f3m_00946dd0

// @f3 0x00948510 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00948510 {
namespace wheel_cinfo_load1984 {
struct Binary{unsigned int unk00,position;unsigned int(__cdecl* read)(Binary*,void*,unsigned int,const unsigned int*,unsigned int);};
struct ComponentSize{unsigned int size;__forceinline ComponentSize(unsigned int value):size(value){}__forceinline operator const unsigned int*()const{return &size;}};
struct Stream{unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14C;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15C;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16C;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17C;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18C;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19C;unsigned int unk1A0;unsigned int unk1A4;unsigned int unk1A8;unsigned int unk1AC;unsigned int unk1B0;unsigned int unk1B4;unsigned int unk1B8;unsigned int unk1BC;unsigned int unk1C0;unsigned int unk1C4;unsigned int unk1C8;unsigned int unk1CC;unsigned int unk1D0;unsigned int unk1D4;unsigned int unk1D8;unsigned int unk1DC;unsigned int unk1E0; unsigned char unk1E4,endian,unk1E6,unk1E7;unsigned int unk1E8;unsigned int unk1EC;unsigned int unk1F0;unsigned int unk1F4;unsigned int unk1F8;unsigned int unk1FC;unsigned int unk200;unsigned int unk204;unsigned int unk208;unsigned int unk20C;unsigned int unk210;unsigned int unk214;unsigned int unk218;unsigned int unk21C;unsigned int unk220;unsigned int unk224;unsigned int unk228;unsigned int unk22C;unsigned int unk230;unsigned int unk234;unsigned int unk238;unsigned int unk23C;unsigned int unk240;unsigned int unk244;unsigned int unk248; Binary* binary;__forceinline void Read(void* destination,unsigned int bytes,const unsigned int* sizes=0,unsigned int components=0){Binary* b=binary;b->position+=b->read(b,destination,bytes,sizes,components); }__forceinline void ReadScalar(float& destination){Binary* b=binary;b->position+=b->read(b,&destination,4,ComponentSize(4),1);}};
__forceinline void SwapWord(unsigned long& value){value=_byteswap_ulong(value);}
struct Vector4{unsigned long x,y,z,w;__forceinline void Swap(){SwapWord(x);SwapWord(y);SwapWord(z);SwapWord(w);}};
struct Matrix30{unsigned int m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23;};void __cdecl FUN_008fe580(Matrix30*);
struct Transform40{Matrix30 rotation;Vector4 translation;__forceinline void Swap(){translation.Swap();FUN_008fe580(&rotation);}};
struct WheelData{unsigned int unk00;unsigned int unk04;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C; Transform40 first,second;unsigned int unkA0;float scalarA4,scalarA8;unsigned int unkAC;float scalarB0,scalarB4;unsigned int unkB8;unsigned int unkBC;unsigned int unkC0;unsigned int unkC4;unsigned int unkC8;unsigned int unkCC; Matrix30 firstRotation,secondRotation;unsigned int unk130,unk134,unk138,unk13C;Vector4 firstVector,secondVector;};
struct Loader{void* vtable;WheelData* data;void FUN_008fc580(Stream*);void FUN_00948510(Stream*);};
void Loader::FUN_00948510(Stream* stream){FUN_008fc580(stream);WheelData* value=data;Transform40& first=value->first;stream->Read(&first,64);
 Transform40& second=value->second;stream->Read(&second,64);
 Matrix30& rotationA=value->firstRotation;stream->Read(&rotationA,48);
 Matrix30& rotationB=value->secondRotation;stream->Read(&rotationB,48);
 Vector4& vectorA=value->firstVector;stream->Read(&vectorA,16);
 Vector4& vectorB=value->secondVector;stream->Read(&vectorB,16);
 stream->ReadScalar(value->scalarA4);stream->ReadScalar(value->scalarA8);stream->ReadScalar(value->scalarB0);stream->ReadScalar(value->scalarB4);
 if(stream->endian!=1){first.Swap();second.Swap();FUN_008fe580(&rotationA);FUN_008fe580(&rotationB);vectorA.Swap();vectorB.Swap();}
}
}
}   // namespace f3m_00948510

// @f3 0x009487d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_009487d0 {
namespace f3m_009487d0 {

class QOstr
{
  public:
    typedef unsigned int (__cdecl *WriteFunction)(QOstr* pkThis, const char* pcBuffer, unsigned int uiBytes,
        unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    virtual ~QOstr();
    unsigned int m_uiAbsoluteCurrentPos;
    int unk08;
    WriteFunction m_pfnWrite;

    unsigned int Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, (const char*)pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiAbsoluteCurrentPos += uiBytesWritten;
        return uiBytesWritten;
    }
};

template <class T> inline void QSave(QOstr& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.Write(&kValue, uiSize, &uiSize, 1);
}

struct QStream
{
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
    int unk1e0;
    unsigned char m_ucSaveEndian;
    unsigned char unk1e5; unsigned char unk1e6; unsigned char unk1e7;
    int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c;
    QOstr* m_pkOstr;
};

struct QVec4 { float x, y, z, w; };
struct QRot { QVec4 col0, col1, col2; };
struct QTransform { QRot m_rotation; QVec4 m_translation; };

void __cdecl FUN_008fe580(QRot* pkRotation);

__forceinline void QSwapWord(unsigned long& value){value=_byteswap_ulong(value);}
inline void QSwapVector(QVec4& kVec){unsigned long* puiData=(unsigned long*)&kVec;QSwapWord(puiData[0]);QSwapWord(puiData[1]);QSwapWord(puiData[2]);QSwapWord(puiData[3]);}

inline void QSwapTransform(QTransform& kTransform)
{
    QSwapVector(kTransform.m_translation);
    FUN_008fe580(&kTransform.m_rotation);
}

struct QData
{
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    QTransform m_kFrameA;
    QTransform m_kFrameB;
    int unk0a0;
    float m_fA4;
    float m_fA8;
    int unk0ac;
    float m_fB0;
    float m_fB4;
    int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc;
    QRot m_kRotD0;
    QRot m_kRot100;
    int unk130; int unk134; int unk138; int unk13c;
    QVec4 m_kVec140;
    QVec4 m_kVec150;
};

struct QConstraint
{
    int unk000;
    QData* m_pData;
    void SaveBinaryBase(QStream& kStream);
    void FUN_009487d0(QStream& kStream);
};

void QConstraint::FUN_009487d0(QStream& kStream)
{
    SaveBinaryBase(kStream);
    QData* pData = m_pData;
    if (kStream.m_ucSaveEndian != 1)
    {
        QSwapTransform(pData->m_kFrameA);
        QSwapTransform(pData->m_kFrameB);
        FUN_008fe580(&pData->m_kRotD0);
        FUN_008fe580(&pData->m_kRot100);
        QSwapVector(pData->m_kVec140);
        QSwapVector(pData->m_kVec150);
    }
    QSave(*kStream.m_pkOstr, pData->m_kFrameA);
    QSave(*kStream.m_pkOstr, pData->m_kFrameB);
    QSave(*kStream.m_pkOstr, pData->m_kRotD0);
    QSave(*kStream.m_pkOstr, pData->m_kRot100);
    QSave(*kStream.m_pkOstr, pData->m_kVec140);
    QSave(*kStream.m_pkOstr, pData->m_kVec150);
    QSave(*kStream.m_pkOstr, pData->m_fA4);
    QSave(*kStream.m_pkOstr, pData->m_fA8);
    QSave(*kStream.m_pkOstr, pData->m_fB0);
    QSave(*kStream.m_pkOstr, pData->m_fB4);
    if (kStream.m_ucSaveEndian != 1)
    {
        QSwapTransform(pData->m_kFrameA);
        QSwapTransform(pData->m_kFrameB);
        FUN_008fe580(&pData->m_kRotD0);
        FUN_008fe580(&pData->m_kRot100);
        QSwapVector(pData->m_kVec140);
        QSwapVector(pData->m_kVec150);
    }
}
}

}   // namespace f3m_009487d0

// @f3 0x00949020 (community match, verified in this file)
#include <stdlib.h>
__forceinline void SwapWord1987(unsigned int& value){value=_byteswap_ulong(value);}
struct ComponentSize1987{unsigned int size;__forceinline ComponentSize1987(unsigned int bytes):size(bytes){}__forceinline operator unsigned int*(){return &size;}};
struct FUN_00949020_Vector
{
    unsigned int x, y, z, w;

    void Swap()
    {
        SwapWord1987(x);
        SwapWord1987(y);
        SwapWord1987(z);
        SwapWord1987(w);
    }
};

struct FUN_00949020_Data
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    FUN_00949020_Vector unk20;
    FUN_00949020_Vector unk30;
    unsigned int unk40, unk44;
};

namespace f3m_0094f840 {
struct NiStream;
}

struct FUN_00949020_Class
{
    int unk00;
    FUN_00949020_Data* unk04;
    void FUN_008fc5d0(f3m_0094f840::NiStream* stream);
    void FUN_00949020(f3m_0094f840::NiStream* stream);
};

static __forceinline void FUN_00949020_WriteSized(f3m_0094f840::NiBinaryStream* backing,
    const void* buffer, unsigned int bytes)
{
    backing->BinaryWrite(buffer, bytes, ComponentSize1987(bytes), 1);
}

void FUN_00949020_Class::FUN_00949020(f3m_0094f840::NiStream* stream)
{
    FUN_008fc5d0(stream);
    FUN_00949020_Data* data = unk04;
    if ((unsigned char)stream->unk1E4 != 1) {
        data->unk20.Swap();
        data->unk30.Swap();
    }

    f3m_0094f840::NiBinaryStream* backing = stream->m_pBackingStream;
    FUN_00949020_WriteSized(backing, &data->unk20, 0x10);
    backing = stream->m_pBackingStream;
    FUN_00949020_WriteSized(backing, &data->unk30, 0x10);
    backing = stream->m_pBackingStream;
    FUN_00949020_WriteSized(backing, &data->unk44, 4);

    if ((unsigned char)stream->unk1E4 != 1) {
        data->unk20.Swap();
        data->unk30.Swap();
    }
}

// @f3 0x0094e200 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0094e200 {
__forceinline void SwapWord1989(unsigned int& value){value=_byteswap_ulong(value);}
struct SwapArg { 
  int u000;
  int u004;
  int u008;
  int u00c;
  int u010;
  int u014;
  int u018;
  int u01c;
  int u020;
  int u024;
  int u028;
  int u02c;
  int u030;
  int u034;
  int u038;
  int u03c;
  int u040;
  int u044;
  int u048;
  int u04c;
  int u050;
  int u054;
  int u058;
  int u05c;
  int u060;
  int u064;
  int u068;
  int u06c;
  int u070;
  int u074;
  int u078;
  int u07c;
  int u080;
  int u084;
  int u088;
  int u08c;
  int u090;
  int u094;
  int u098;
  int u09c;
  int u0a0;
  int u0a4;
  int u0a8;
  int u0ac;
  int u0b0;
  int u0b4;
  int u0b8;
  int u0bc;
  int u0c0;
  int u0c4;
  int u0c8;
  int u0cc;
  int u0d0;
  int u0d4;
  int u0d8;
  int u0dc;
  int u0e0;
  int u0e4;
  int u0e8;
  int u0ec;
  int u0f0;
  int u0f4;
  int u0f8;
  int u0fc;
  int u100;
  int u104;
  int u108;
  int u10c;
  int u110;
  int u114;
  int u118;
  int u11c;
  int u120;
  int u124;
  int u128;
  int u12c;
  int u130;
  int u134;
  int u138;
  int u13c;
  int u140;
  int u144;
  int u148;
  int u14c;
  int u150;
  int u154;
  int u158;
  int u15c;
  int u160;
  int u164;
  int u168;
  int u16c;
  int u170;
  int u174;
  int u178;
  int u17c;
  int u180;
  int u184;
  int u188;
  int u18c;
  int u190;
  int u194;
  int u198;
  int u19c;
  int u1a0;
  int u1a4;
  int u1a8;
  int u1ac;
  int u1b0;
  int u1b4;
  int u1b8;
  int u1bc;
  int u1c0;
  int u1c4;
  int u1c8;
  int u1cc;
  int u1d0;
  int u1d4;
  int u1d8;
  int u1dc;
  int u1e0;
  unsigned char flag1e4;
};
struct SwapBlock {
  unsigned int v00;
  unsigned int v04;
  unsigned int v08;
  unsigned int v0c;
  unsigned int v10;
  unsigned int v14;
  unsigned int v18;
  unsigned int v1c;
  unsigned int v20;
  unsigned int v24;
  unsigned int v28;
  unsigned int v2c;
  unsigned int v30;
  unsigned int v34;
  unsigned int v38;
  unsigned int v3c;
};
struct SwapOwner {
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
  virtual SwapBlock* query(bool* created);
  void bhkConvexShape_SaveBinary(SwapArg* a);
  void FUN_0094e200(SwapArg* a);
};
// pdb: bhkTriangleShape::SaveBinary | bhkTriangleShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void SwapOwner::FUN_0094e200(SwapArg* a) {
  if (a->flag1e4 != 1) {
    bool created;
    SwapBlock* data=query(&created);
    if (data) {
      SwapWord1989(data->v10);
      SwapWord1989(data->v14);
      SwapWord1989(data->v18);
      SwapWord1989(data->v1c);
      SwapWord1989(data->v20);
      SwapWord1989(data->v24);
      SwapWord1989(data->v28);
      SwapWord1989(data->v2c);
      SwapWord1989(data->v30);
      SwapWord1989(data->v34);
      SwapWord1989(data->v38);
      SwapWord1989(data->v3c);
    }
  }
  bhkConvexShape_SaveBinary(a);
  if (a->flag1e4 != 1) {
    bool created;
    SwapBlock* data=query(&created);
    if (data) {
      SwapWord1989(data->v10);
      SwapWord1989(data->v14);
      SwapWord1989(data->v18);
      SwapWord1989(data->v1c);
      SwapWord1989(data->v20);
      SwapWord1989(data->v24);
      SwapWord1989(data->v28);
      SwapWord1989(data->v2c);
      SwapWord1989(data->v30);
      SwapWord1989(data->v34);
      SwapWord1989(data->v38);
      SwapWord1989(data->v3c);
    }
  }
}
}   // namespace f3m_0094e200

// @f3 0x009475f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_009475f0 {
__forceinline void SwapWord1991(unsigned int& value){value=_byteswap_ulong(value);}

struct FUN_009475f0_res {
    int unk00; int unk04; int unk08; int unk0c;
    unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c; unsigned int unk20; unsigned int unk24;
};

struct FUN_009475f0_cls {
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_009475f0_res* vf45(bool* created);
    void FUN_008fb9a0(f3m_0094d990::CcaArg* a1);
    void FUN_009475f0(f3m_0094d990::CcaArg* const a1);
};

// pdb: bhkAngularDashpotAction::SaveBinary | bhkAngularDashpotAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_009475f0_cls::FUN_009475f0(f3m_0094d990::CcaArg* const a1)
{
    f3m_0094d990::CcaArg* p = a1;
    if (p->m_b1e4 != 1) {
        bool created;
        FUN_009475f0_res* res = vf45(&created);
        if (res != 0) {
            SwapWord1991(res->unk10);
            SwapWord1991(res->unk14);
            SwapWord1991(res->unk18);
            SwapWord1991(res->unk1c);
            SwapWord1991(res->unk20);
            SwapWord1991(res->unk24);
        }
    }
    FUN_008fb9a0(p);
    if (p->m_b1e4 != 1) {
        bool created;
        FUN_009475f0_res* res = vf45(&created);
        if (res != 0) {
            SwapWord1991(res->unk10);
            SwapWord1991(res->unk14);
            SwapWord1991(res->unk18);
            SwapWord1991(res->unk1c);
            SwapWord1991(res->unk20);
            SwapWord1991(res->unk24);
        }
    }
}

}   // namespace f3m_009475f0

// @f3 0x00946820 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00946820 {
__forceinline void SwapWord1992(unsigned int& value){value=_byteswap_ulong(value);}
namespace task946820 {
struct Stream { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; char unk1e4; };
struct Block{int unk00,unk04,unk08,unk0c;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;void Swap(){SwapWord1992(unk10);SwapWord1992(unk14);SwapWord1992(unk18);SwapWord1992(unk1c);SwapWord1992(unk20);SwapWord1992(unk24);}};
struct Owner { virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4(); virtual void Slot5(); virtual void Slot6(); virtual void Slot7(); virtual void Slot8(); virtual void Slot9(); virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19(); virtual void Slot20(); virtual void Slot21(); virtual void Slot22(); virtual void Slot23(); virtual void Slot24(); virtual void Slot25(); virtual void Slot26(); virtual void Slot27(); virtual void Slot28(); virtual void Slot29(); virtual void Slot30(); virtual void Slot31(); virtual void Slot32(); virtual void Slot33(); virtual void Slot34(); virtual void Slot35(); virtual void Slot36(); virtual void Slot37(); virtual void Slot38(); virtual void Slot39(); virtual void Slot40(); virtual void Slot41(); virtual void Slot42(); virtual void Slot43(); virtual void Slot44(); virtual Block* Get(bool* created); void FUN_008f8970(Stream*); void FUN_00946820(Stream*); };
// pdb: bhkMotorAction::SaveBinary | bhkMotorAction.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Owner::FUN_00946820(Stream* s) {
 Stream* original=s;
 if(original->unk1e4!=1) {bool created;Block* b=Get(&created);if(b) b->Swap();}
 FUN_008f8970(original);
 if(original->unk1e4!=1) {bool created;Block* b=Get(&created);if(b) b->Swap();}
}
}
}   // namespace f3m_00946820

// @f3 0x0094c120 (community match, verified in this file)
namespace f3m_0094c120 {
struct SizeDescriptor1995{int size;__forceinline SizeDescriptor1995(int value):size(value){}__forceinline operator int*(){return &size;}};
struct Blob30 {
    int m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23;
};

struct QStrm94 {
    int unk00;
    int unk04;
    int (__cdecl* read)(QStrm94* self, void* dest, int size, int* count, int flag);
};

struct Data94 {
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    Blob30 at20;
    Blob30 at50;
    int f80;
    int f84;
    int f88;
};

struct Stream94 {
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    unsigned char f1e4; unsigned char f1e5; unsigned char f1e6; unsigned char f1e7;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    int f230;
    int f234;
    int f238;
    int f23c;
    int f240;
    int f244;
    int f248;
    QStrm94* strm;
};

struct Owner94 {
    int unk00;
    Data94* data;
    void FUN_008fc580(Stream94* arg);
    void FUN_0094c120(Stream94* arg);
};

void __cdecl FUN_008fe580(void* block);

void Owner94::FUN_0094c120(Stream94* arg)
{
    FUN_008fc580(arg);
    Data94* d = data;
    QStrm94* s = arg->strm;
    s->unk04 += s->read(s, &d->at20, 0x30, 0, 0);
    void* p50 = &d->at50;
    s = arg->strm;
    s->unk04 += s->read(s, p50, 0x30, 0, 0);
    s = arg->strm;
    s->unk04 += s->read(s, &d->f84, 4, SizeDescriptor1995(4), 1);
    s = arg->strm;
    s->unk04 += s->read(s, &d->f88, 4, SizeDescriptor1995(4), 1);
    if (arg->f1e5 != 1) {
        FUN_008fe580(&d->at20);
        FUN_008fe580(p50);
    }
}

}   // namespace f3m_0094c120

// @f3 0x00944b90 (community match, verified in this file)
namespace f3m_00944b90 {
struct SizeDescriptor1996{int size;__forceinline SizeDescriptor1996(int value):size(value){}__forceinline operator int*(){return &size;}};
namespace n944b90 {
struct P;
struct Reader;
typedef int (*ReaderFn)(Reader* self, void* buffer, int size, int* read, int flag);
struct Reader {
    int m_00;
    int m_04;
    int m_08;
    ReaderFn m_0C;
};
struct P {
    unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14C;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15C;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16C;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17C;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18C;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19C;unsigned int unk1A0;unsigned int unk1A4;unsigned int unk1A8;unsigned int unk1AC;unsigned int unk1B0;unsigned int unk1B4;unsigned int unk1B8;unsigned int unk1BC;unsigned int unk1C0;unsigned int unk1C4;unsigned int unk1C8;unsigned int unk1CC;unsigned int unk1D0;unsigned int unk1D4;unsigned int unk1D8;unsigned int unk1DC;unsigned int unk1E0;unsigned int unk1E4;unsigned int unk1E8;unsigned int unk1EC;unsigned int unk1F0;unsigned int unk1F4;unsigned int unk1F8;unsigned int unk1FC;unsigned int unk200;unsigned int unk204;unsigned int unk208;unsigned int unk20C;unsigned int unk210;unsigned int unk214;unsigned int unk218;unsigned int unk21C;unsigned int unk220;unsigned int unk224;unsigned int unk228;unsigned int unk22C;unsigned int unk230;unsigned int unk234;unsigned int unk238;unsigned int unk23C;unsigned int unk240;unsigned int unk244;unsigned int unk248;unsigned int unk24C;
    Reader* m_250;
    void FUN_0078c030(P* p);
    void FUN_0082b000(void* element);
};
struct El {
    void bhkPoseArray_bhkPose_SaveBinary(P* p);
};
struct C {
    int m_00;
    int m_04;
    unsigned int m_count8;
    int* m_data8;
    unsigned int m_count10;
    El** m_data10;
    void FUN_0078c030(P* p);
    void bhkPoseArray_SaveBinary(P* p);
};
}
namespace n944b90 {
// pdb: bhkPoseArray::SaveBinary | bhkPoseArray.obj | fnv360_0822_retail, objrun_prop + bridge(vtable|caller_sim) + skyrim(caller_sim), high
void C::bhkPoseArray_SaveBinary(P* p)
{
    FUN_0078c030(p);
    Reader* r = p->m_250;
    r->m_04 += r->m_0C(r, &m_count8, 4, SizeDescriptor1996(4), 1);
    for (unsigned int i = 0; i < m_count8; ++i) {
        p->FUN_0082b000(&m_data8[i]);
    }
    r = p->m_250;
    r->m_04 += r->m_0C(r, &m_count10, 4, SizeDescriptor1996(4), 1);
    for (unsigned int i = 0; i < m_count10; ++i) {
        m_data10[i]->bhkPoseArray_bhkPose_SaveBinary(p);
    }
}
}

}   // namespace f3m_00944b90

// @f3 0x009493d0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009493d0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace Copy455
{
struct Heap
{
    void* FUN_008f6d30(unsigned int, int);
};
struct Object
{
    void* vtable;
    unsigned short size, refs;
    unsigned int field8;
    unsigned int fieldc;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    float field20;
    float field24;
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    float field3c;
    float field40;
    float field44;
    float field48;
    float field4c;
    float field50;
    float field54;
    float field58;
    float field5c;
    float field60;
    float field64;
    float field68;
    float field6c;
    float field70;
    float field74;
    float field78;
    float field7c;
    unsigned int field80;
    unsigned int field84;
    float field88;
    float field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    float fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    float fieldb0;
    float fieldb4;
    unsigned int fieldb8;
    unsigned int fieldbc;
    Object();
    static void* operator new(unsigned int bytes)
    {
        Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
        Object* memory = (Object*)heap->FUN_008f6d30(bytes, 44);
        memory->size = (unsigned short)bytes;
        return memory;
    }
    static void operator delete(void*);
};
struct Owner
{
    void* vtable;
    Object* original;
    void FUN_008fc3f0(Object*, void*);
    void FUN_009493d0(Object*, void*);
};
void Owner::FUN_009493d0(Object* dst, void* context)
{
    Object* src = original;
    if (!dst)
        dst = new Object;
    dst->field20 = src->field20;
    dst->field24 = src->field24;
    dst->field28 = src->field28;
    dst->field2c = src->field2c;
    dst->field30 = src->field30;
    dst->field34 = src->field34;
    dst->field38 = src->field38;
    dst->field3c = src->field3c;
    dst->field40 = src->field40;
    dst->field44 = src->field44;
    dst->field48 = src->field48;
    dst->field4c = src->field4c;
    dst->field50 = src->field50;
    dst->field54 = src->field54;
    dst->field58 = src->field58;
    dst->field5c = src->field5c;
    dst->field60 = src->field60;
    dst->field64 = src->field64;
    dst->field68 = src->field68;
    dst->field6c = src->field6c;
    dst->field70 = src->field70;
    dst->field74 = src->field74;
    dst->field78 = src->field78;
    dst->field7c = src->field7c;
    dst->fielda0 = src->fielda0;
    dst->fieldb0 = src->fieldb0;
    dst->fieldb4 = src->fieldb4;
    dst->field88 = src->field88;
    dst->field8c = src->field8c;
    FUN_008fc3f0(dst, context);
}
}
}   // namespace f3m_009493d0

// @f3 0x009441c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern const char DAT_00e7a290;
namespace f3m_009441c0 {
namespace Snapshot2033 {
extern "C" void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Allocator {void* FUN_008f6d30(int bytes,int category);};
struct Listener {
    const void* table;
    unsigned short size,refs;
    void* data;
    int count,capacity;
    Listener() {refs=1;table=&DAT_00e7a290;data=0;count=0;capacity=(int)0x80000000;}
    void FUN_00944050() throw();
};
struct Layout {int value;void FUN_009b2530(); Layout* FUN_009b2540(const char*);};
struct Options {int tag;Layout layout;bool enabled;const char* version;};
struct Writer {
    virtual void Delete(int);
    virtual void v04();virtual void v08();virtual void v0c();
    virtual void SetContents(const void*,const void*,Listener*);
    virtual void v14();virtual void v18();
    virtual int Save(void*,Options*);
    unsigned short size; short refs;
    Writer* FUN_009d7850();
    Writer* FUN_009d7350();
    void RemoveReference() {
        if(size) {refs+=-1;if(refs==0)Delete(1);}
    }
};
struct Result {unsigned char value;Result(){} Result(bool v):value(v){}};
unsigned char* FUN_009441c0(unsigned char* result,const void* object,const void* type,void* stream,bool binary,const char* version,Listener* listener) {
    bool success=false;
    if(stream) {
    Writer* writer;
    if(binary) {
        Allocator* allocator=(Allocator*)DAT_00d9b080(DAT_010f3170);
        Writer* memory=(Writer*)allocator->FUN_008f6d30(0xb8,6);
        memory->size=0xb8;
        writer=memory->FUN_009d7850();
    } else {
        Allocator* allocator=(Allocator*)DAT_00d9b080(DAT_010f3170);
        Writer* memory=(Writer*)allocator->FUN_008f6d30(0xb8,6);
        memory->size=0xb8;
        writer=memory->FUN_009d7350();
    }
    Listener* selected=listener;
    Listener local;
    if(!selected)selected=&local;
    writer->SetContents(object,type,selected);
    Options options;
    options.tag=0;
    options.layout.FUN_009b2530();
    char tag[4]={'s','n','a','p'};
    options.tag=*(int*)tag;
    options.enabled=true;
    options.version=0;
    if(version) {
        Layout parsed;
        options.layout=*parsed.FUN_009b2540(version);
    }
    success=writer->Save(stream,&options)==0;
    writer->RemoveReference();
    local.FUN_00944050();
    }
    *result=success;
    return result;
}
}
}   // namespace f3m_009441c0

// @f3 0x0094cda0 (community match, verified in this file)
namespace f3m_0094cda0 {
namespace n94cda0 {
struct V4 { float f[4]; V4& operator*=(float s) { for (int i = 0; i < 4; i++) f[i] *= s; return *this; } };
struct V2 { float f[2]; V2& operator*=(float s) { for (int i = 0; i < 2; i++) f[i] *= s; return *this; } };
struct Obj { int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C; n94cda0::V2 a; n94cda0::V2 b; n94cda0::V2 c; n94cda0::V2 d; };
}
// pdb: hkBallAndSocketConstraintCinfo::ApplyScale | bhkBallAndSocketConstraint.obj | fnv360_0822_retail, call_seq, medium
// pdb params: afScale, apInfo
void __cdecl FUN_0094cda0(float scale, n94cda0::Obj* o)
{
    if (o && scale != 1.0f) {
o->a *= scale; o->b *= scale; o->c *= scale; o->d *= scale;
    }
}
}   // namespace f3m_0094cda0

// @f3 0x0094caa0 (community match, verified in this file)
namespace f3m_0094caa0 {
namespace f3m_0094caa0 {
void __cdecl FUN_00901e90(void* arr, int capacity, int stride);
struct Vec4_caa0 {
    float x, y, z, w;
    Vec4_caa0& operator=(const Vec4_caa0& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
};
struct Pair_caa0 {
    Vec4_caa0 a;
    Vec4_caa0 b;
};
struct Geom_caa0 {
    char pad[0x18];
    Pair_caa0* pairs;
    int count;
};
struct Shape_caa0 {
    char pad[0xc];
    Geom_caa0* geom;
};
struct VecArray_caa0 {
    Vec4_caa0* data;
    int size;
    int capacityAndFlags;
    void setSize(int n) { reserve(n); size = n; }
    void reserve(int n)
    {
        int cap = capacityAndFlags & 0x3fffffff;
        if (cap < n) {
            cap *= 2;
            if (n >= cap)
                cap = n;
            FUN_00901e90(this, cap, 0x10);
        }
    }
};
struct Out_caa0 {
    char pad[0x20];
    VecArray_caa0 verts;
};
struct Cls_caa0 {
    int unk00;
    int unk04;
    Shape_caa0* shape;
    Shape_caa0* GetShape() { return this ? shape : 0; }
    void FUN_009e1160(Out_caa0* out);
    void FUN_0094caa0(Out_caa0* out);
};
}
using namespace f3m_0094caa0;

// pdb: bhkBallSocketConstraintChain::CopyCinfo | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: arInfo
void Cls_caa0::FUN_0094caa0(Out_caa0* out)
{
    FUN_009e1160(out);
    Shape_caa0* s = GetShape();
    out->verts.size = 0;
    Geom_caa0* g = s->geom;
    out->verts.setSize(g->count * 2);
    int j = 0;
    for (int i = 0; i < g->count; i++) {
        out->verts.data[j++] = g->pairs[i].a;
        out->verts.data[j++] = g->pairs[i].b;
    }
}
}   // namespace f3m_0094caa0

// @f3 0x0094e800 (community match, verified in this file)
namespace f3m_0094e800 {
namespace task94e800 {
struct Input { int unk00,unk04,unk08,unk0c; float scale; };
struct V4 { float v[4]; void operator*=(float s) { for (int i=0;i<4;i++) v[i]*=s; } };
struct Block { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; V4 g0; V4 g1; };
struct Owner { virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4(); virtual void Slot5(); virtual void Slot6(); virtual void Slot7(); virtual void Slot8(); virtual void Slot9(); virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19(); virtual void Slot20(); virtual void Slot21(); virtual void Slot22(); virtual void Slot23(); virtual void Slot24(); virtual void Slot25(); virtual void Slot26(); virtual void Slot27(); virtual void Slot28(); virtual void Slot29(); virtual void Slot30(); virtual void Slot31(); virtual void Slot32(); virtual void Slot33(); virtual void Slot34(); virtual void Slot35(); virtual void Slot36(); virtual void Slot37(); virtual void Slot38(); virtual void Slot39(); virtual void Slot40(); virtual void Slot41(); virtual void Slot42(); virtual void Slot43(); virtual void Slot44(); virtual Block* Get(bool*); void FUN_008f7580(int,Input*); void FUN_0094e800(int,Input*); };
// pdb: bhkPlaneShape::CopyMembers | bhkPlaneShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: apDest, arCloneData
void Owner::FUN_0094e800(int x,Input* in) { bool ok; Block* b=Get(&ok); if(b) {float s=in->scale; if(s!=1.0f) { b->g0*=s;b->g1*=s; }} FUN_008f7580(x,in); }
}
}   // namespace f3m_0094e800

// @f3 0x00948100 (community match, verified in this file)
namespace f3m_00948100 {
namespace f3m_00948100{
// pdb: bhkBreakableConstraint::CreateCinfo | bhkBreakableConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arCreated
struct Heap{void*FUN_0086b930(unsigned);};extern Heap DAT_01090a78;extern int DAT_00e7a8b4;struct Serializable{int value;int refs;};struct Object{void*methods;Serializable base;int unk0c;int unk10;Object(){base.value=0;unk0c=0;unk10=0;base.refs=1;methods=&DAT_00e7a8b4;}static void*operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}static Serializable* Create(){Object*p=new Object;return p?&p->base:0;}static Object*From(Serializable*p){return p?(Object*)((char*)p - offsetof(Object,base)):0;}};struct Owner{int unk00;int unk04;int active;Serializable*cached;void FUN_008fc420(Object*);Serializable*FUN_00948100(bool*);};Serializable* Owner::FUN_00948100(bool*created){if(!cached){cached=Object::Create();if(active)FUN_008fc420(Object::From(cached));*created=true;}else *created=false;return cached;}}
}   // namespace f3m_00948100

// @f3 0x00943ae0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00943ae0 {
namespace f3m_943ae0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
void FUN_00e7a270();

struct Node943 {
    unsigned int unk00;
    unsigned short m_type;
    unsigned int FUN_009a8fd0(unsigned int a, unsigned int b, unsigned int c);
};

struct Pool943 {
    Node943* FUN_008f6d30(unsigned int size, unsigned int tag);
};

struct FUN_00943ae0 {
    void (*unk00)();
    unsigned short unk04;
    unsigned short m6;
    unsigned int m8;
    FUN_00943ae0(unsigned int a, unsigned int b, unsigned int c);
};

// pdb: hkOstream::hkOstream | hkOStream.obj | fnv360_0822_retail, call_gap, medium
// pdb params: mem, memSize, isString
FUN_00943ae0::FUN_00943ae0(unsigned int a, unsigned int b, unsigned int c) {
    m6 = 1;
    unk00 = FUN_00e7a270;
    Pool943* pool = (Pool943*)TlsGetValue(DAT_010f3170);
    Node943* node = pool->FUN_008f6d30(0x1c, 0x1a);
    node->m_type = 0x1c;
    m8 = node->FUN_009a8fd0(a, b, c);
}
}
}   // namespace f3m_00943ae0

// @f3 0x009421d0 (community match, verified in this file)
namespace f3m_009421d0 {
namespace TokenReset2071 {
struct Source {void FUN_009023a0();unsigned int FUN_00902390();};
struct Record {unsigned int value;
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
struct Owner {
    Source* source;
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
    Record records[5];
    unsigned int unk13C,unk140,unk144;
    int count;
    void FUN_009421d0();
};
// pdb: hkCpuJobThreadPool::`scalar deleting destructor' | hkCpuJobThreadPool.obj | fnv360_0822_debug, objrun_open, low
void Owner::FUN_009421d0() {
    source->FUN_009023a0();
    for(int i=0;i<count;++i)records[i].value=source->FUN_00902390();
}
}
}   // namespace f3m_009421d0

// @f3 0x0094e940 (community match, verified in this file)
namespace f3m_0094e940 {

namespace f3m_0094e940 {

using f3m_0094e8a0::task0762::NiStream86;
using f3m_0094e8a0::task0762::Block86;
using f3m_0094e8a0::task0762::Swap86;
using f3m_0094e8a0::task0762::FUN_0094e8a0_t;

struct Owner_0094e940 : FUN_0094e8a0_t {
    void FUN_0094e940(NiStream86* pkStream);
};

struct StreamRead_0094e940 {
    void FUN_008f74e0(NiStream86* pkStream);
};

// pdb: bhkPlaneShape::SaveBinary | bhkPlaneShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void Owner_0094e940::FUN_0094e940(NiStream86* pkStream)
{
    if (pkStream->unk1e4 != 1) {
        int iSize;
        Block86* pkBlock = GetBlock(&iSize);
        if (pkBlock) {
            Swap86(&pkBlock->m_aulData[0]);
            Swap86(&pkBlock->m_aulData[1]);
            Swap86(&pkBlock->m_aulData[2]);
            Swap86(&pkBlock->m_aulData[3]);
            Swap86(&pkBlock->m_aulData[4]);
            Swap86(&pkBlock->m_aulData[5]);
            Swap86(&pkBlock->m_aulData[6]);
            Swap86(&pkBlock->m_aulData[7]);
            Swap86(&pkBlock->m_aulData[8]);
            Swap86(&pkBlock->m_aulData[9]);
            Swap86(&pkBlock->m_aulData[10]);
            Swap86(&pkBlock->m_aulData[11]);
        }
    }

    ((StreamRead_0094e940*)this)->FUN_008f74e0(pkStream);

    if (pkStream->unk1e4 != 1) {
        int iSize;
        Block86* pkBlock = GetBlock(&iSize);
        if (pkBlock) {
            Swap86(&pkBlock->m_aulData[0]);
            Swap86(&pkBlock->m_aulData[1]);
            Swap86(&pkBlock->m_aulData[2]);
            Swap86(&pkBlock->m_aulData[3]);
            Swap86(&pkBlock->m_aulData[4]);
            Swap86(&pkBlock->m_aulData[5]);
            Swap86(&pkBlock->m_aulData[6]);
            Swap86(&pkBlock->m_aulData[7]);
            Swap86(&pkBlock->m_aulData[8]);
            Swap86(&pkBlock->m_aulData[9]);
            Swap86(&pkBlock->m_aulData[10]);
            Swap86(&pkBlock->m_aulData[11]);
        }
    }
}

}
}   // namespace f3m_0094e940

// @f3 0x00941e10 (community match, verified in this file)
extern unsigned long tlsIndex;
namespace f3m_00941e10 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Node { int unk00; void* value; int unk08; Node* next; };
struct Entry { int unk00; struct Item* value; };
struct Items { Entry* data; int size; };
struct IndexArray { int* data; int size; int capacity; };
struct TempArray { void** data; int size; int capacity; void add(int, void**); };
struct Item { int key(); };
struct Option { char flag; };
struct Owner {
 void init(Option);
 int lookup(int, void**);
 void* build(TempArray*, Item*);
 void insert(int, void*);
 Owner* FUN_00941e10(Node*, Items*, IndexArray*);
};
void grow(IndexArray*, int);
struct Heap { void release(void*, int, int); };
Owner* Owner::FUN_00941e10(Node* nodes, Items* items, IndexArray* output) {
 Option opt; opt.flag = 0; init(opt);
 TempArray tmp; tmp.data = 0; tmp.size = 0; tmp.capacity = 0x80000000;
 Node* current = nodes;
 while (current) { if (current->value) tmp.add(0, &current->value); current = current->next; }
 for (int i = 0; i < items->size; ++i) {
  Item* item = items->data[i].value;
  void* result;
  int key = item->key();
  if (!lookup(key, (void**)&nodes)) result = (void*)nodes;
  else { result = build(&tmp, item); int key2 = item->key(); insert(key2, result); }
  if (result) {
   if (output->size == (output->capacity & 0x3fffffff)) grow(output, 4);
   output->data[output->size++] = i;
  }
 }
 if ((tmp.capacity & 0x80000000) == 0) { int cap = tmp.capacity & 0x3fffffff; Heap* heap = (Heap*)TlsGetValue(tlsIndex); heap->release(tmp.data, cap*4, 23); }
 return this;
}
}   // namespace f3m_00941e10

// @f3 0x00945ea0 (community match, verified in this file)
namespace f3m_00945ea0 {
struct DestObj; void __stdcall FUN_008fb630(DestObj* param);

struct SourceObj {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;

    float unk030;
    float unk034;
    float unk038;
    float unk03C;
    float unk040;
    float unk044;
    float unk048;
    float unk04C;

    float unk050;
    float unk054;
    float unk058;

    bool unk05C;
    bool unk05D;
};

struct DestObj {
    int unk00; int unk04; int unk08; int unk0C;

    float unk010;
    float unk014;
    float unk018;
    float unk01C;
    float unk020;
    float unk024;
    float unk028;
    float unk02C;

    float unk030;
    float unk034;
    float unk038;

    bool unk03C;
    bool unk03D;
};

class CopyOwner945e {
public:
    int unk00;
    int unk04;
    SourceObj* unk08;

    void FUN_00945ea0(DestObj* dest_buf);
};

void CopyOwner945e::FUN_00945ea0(DestObj* dest_buf) {
    FUN_008fb630(dest_buf);

    if (this != 0 && unk08 != 0) {
        SourceObj* src = unk08;

        dest_buf->unk030 = src->unk050;
        dest_buf->unk034 = src->unk054;
        dest_buf->unk038 = src->unk058;

        dest_buf->unk010 = src->unk030;
        dest_buf->unk014 = src->unk034;
        dest_buf->unk018 = src->unk038;
        dest_buf->unk01C = src->unk03C;
        dest_buf->unk020 = src->unk040;
        dest_buf->unk024 = src->unk044;
        dest_buf->unk028 = src->unk048;
        dest_buf->unk02C = src->unk04C;

        dest_buf->unk03C = src->unk05C;
        bool val5d = *(volatile bool*)&src->unk05D;
        dest_buf->unk03D = val5d;
    }
}
}   // namespace f3m_00945ea0

// @f3 0x0095a6f0 (community match, verified in this file)
extern const float DAT_00e7c0cc,DAT_00e7c0c8,DAT_00dc3b0c,DAT_00e7c0c4,DAT_00dcf7d8;
namespace f3m_0095a6f0 {
namespace Rag2108 {
struct Vector {float x,y,z,w;__forceinline void ClearFirst(){*static_cast<volatile float*>(&x)=0;y=0;z=0;w=0;}__forceinline void Clear(){x=0;y=0;z=0;w=0;}__forceinline void ClearReverse(){w=0;z=0;y=0;x=0;}};
struct Mat12 {Vector r0,r1,r2;__forceinline void SetIdentity(){r0.ClearFirst();r1.Clear();r2.Clear();r0.x=1;r1.y=1;r2.z=1;}};
typedef Vector Vec4;
struct BoolValue {unsigned char value;BoolValue(bool b):value(b){}operator bool()const{return value!=0;}};
struct Base0 {virtual void vf0();short unk04,unk06;int unk08,unk0C;Base0(){unk06=1;unk08=0;}};
struct Atoms {
 unsigned int unk00,unk04,unk08,unk0C;
    Mat12 fA;
    Vec4 vA;
    Mat12 fB;
    Vec4 vB;
    short unka0;
    char unka2;
    char unka3;
    unsigned short unka4;
    unsigned short unka6;
    int unka8;
    int unkac;
    Mat12 mC;
    int unke0, unke4, unke8, unkec;
    char unkf0, unkf1, unkf2, unkf3, unkf4, unkf5, unkf6, unkf7;
    float unkf8;
    char unkfc, unkfd, unkfe, unkff, unk100, unk101, unk102, unk103;
    float unk104, unk108, unk10c;
    char unk110, unk111, unk112, unk113, unk114, unk115, unk116, unk117;
    float unk118, unk11c, unk120;
    char unk124, unk125, unk126, unk127, unk128, unk129, unk12a, unk12b;
    float unk12c, unk130, unk134;

 void FUN_0095a8e0();Atoms(){FUN_0095a8e0();}
};
struct FUN_0095a6f0:Base0 {Atoms atoms;virtual void vf0();virtual void vf1();FUN_0095a6f0();void FUN_00959c90(BoolValue);};
__declspec(noinline)void FUN_0095a6f0::FUN_00959c90(BoolValue b){unsigned char enabled=b?1:0;atoms.unk116=enabled*0x38;}
// pdb: hkpRagdollConstraintData::hkpRagdollConstraintData | hkpRagdollConstraintData.obj | fnv360_0822_retail, call_gap, high
FUN_0095a6f0::FUN_0095a6f0(){
 atoms.fA.SetIdentity();atoms.vA.ClearReverse();atoms.fB.SetIdentity();atoms.vB.ClearReverse();
 atoms.unkf8=0;atoms.unkf3=0;atoms.unkf4=3;atoms.unka2=0;atoms.unka4=0x60;atoms.unka6=0x64;
 atoms.mC.SetIdentity();
 atoms.unke0=0;atoms.unk104=DAT_00e7c0cc;atoms.unke4=0;atoms.unke8=0;
 double twistMax=*static_cast<const volatile float*>(&DAT_00e7c0c8);atoms.unkff=0;atoms.unk100=1;atoms.unk108=twistMax;atoms.unk10c=0.8f;
 *static_cast<volatile char*>(&atoms.unk113)=0;atoms.unk118=DAT_00dc3b0c;atoms.unk114=0;atoms.unk115=0;atoms.unk11c=1.0f;atoms.unk120=0.8f;
 FUN_00959c90(true);
 atoms.unk12c=DAT_00e7c0c4;atoms.unk127=0;atoms.unk130=DAT_00dcf7d8;atoms.unk128=1;atoms.unk129=1;atoms.unk134=0.8f;
}
}
}   // namespace f3m_0095a6f0

// @f3 0x00944eb0 (community match, verified in this file)
namespace f3m_00944eb0 {
struct Pool { void* Alloc(unsigned int n); };
extern Pool DAT_01090a78;


struct Elem4 {
    unsigned int unk00;
    static void* operator new[](unsigned int n) { return DAT_01090a78.Alloc(n); }
    Elem4();
    ~Elem4();
};

struct Elem8 {
    static void* operator new(unsigned int n) { return DAT_01090a78.Alloc(n); }
    unsigned int unk00;
    unsigned int unk04;
    Elem8() : unk00(0), unk04(0) {}
    void FUN_00944d50(struct Loader* l);
};

struct Elem8Slot {
    Elem8* p;
    static void* operator new[](unsigned int n) { return DAT_01090a78.Alloc(n); }
};

struct Reader {
    int unk00;
    int unk04;
    int (__cdecl* Read)(Reader* self, unsigned int* dst, int size, int* psz, int flag);
};

struct Loader {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    void* unk1A0;
    void* unk1A4;
    void* unk1A8;
    void* unk1AC;
    void* unk1B0;
    void* unk1B4;
    void* unk1B8;
    void* unk1BC;
    void* unk1C0;
    void* unk1C4;
    void* unk1C8;
    void* unk1CC;
    void* unk1D0;
    void* unk1D4;
    void* unk1D8;
    void* unk1DC;
    void* unk1E0;
    void* unk1E4;
    void* unk1E8;
    void* unk1EC;
    void* unk1F0;
    void* unk1F4;
    void* unk1F8;
    void* unk1FC;
    void* unk200;
    void* unk204;
    void* unk208;
    void* unk20C;
    void* unk210;
    void* unk214;
    void* unk218;
    void* unk21C;
    void* unk220;
    void* unk224;
    void* unk228;
    void* unk22C;
    void* unk230;
    void* unk234;
    void* unk238;
    void* unk23C;
    void* unk240;
    void* unk244;
    void* unk248;
    Reader* unk24c;
    void FUN_0082bee0(Elem4* p);
};

void __stdcall FUN_00825ad0(Loader* l);

struct unkCls {
    int unk00;
    int unk04;
    unsigned int count08;
    Elem4* arr0c;
    unsigned int count10;
    Elem8Slot* arr14;
    void FUN_00944eb0(Loader* ld);
};

// pdb: bhkPoseArray::LoadBinary | bhkPoseArray.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void unkCls::FUN_00944eb0(Loader* ld)
{
    FUN_00825ad0(ld);
    Reader* r = ld->unk24c;
    {
        int sz1 = 4;
        r->unk04 += r->Read(r, &count08, 4, &sz1, 1);
    }
    if (count08 > 0)
        arr0c = new Elem4[count08];
    for (unsigned int i = 0; i < count08; i++)
        ld->FUN_0082bee0(&arr0c[i]);

    r = ld->unk24c;
    {
        int sz2 = 4;
        r->unk04 += r->Read(r, &count10, 4, &sz2, 1);
    }
    if (count10 > 0)
        arr14 = new Elem8Slot[count10];
    for (unsigned int j = 0; j < count10; j++) {
        arr14[j].p = new Elem8;
        arr14[j].p->FUN_00944d50(ld);
    }
}
}

// @f3 0x0094bfe0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094bfe0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Copy512
{
struct Heap
{
    void* FUN_008f6d30(unsigned int, int);
    void FUN_008f6d90(void*, unsigned int, int);
};
struct Object
{
    unsigned int tag;
    unsigned short size;
    char pad06[0x1a];
    float value20;
    float value24;
    float value28;
    float value2c;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
    float value48;
    float value4c;
    float value50;
    float value54;
    float value58;
    float value5c;
    float value60;
    float value64;
    float value68;
    float value6c;
    float value70;
    float value74;
    float value78;
    float value7c;
    unsigned int pad80;
    float value84;
    float value88;
    char pad8c[0x14];
    Object();
    static void* operator new(unsigned int size)
    {
        Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
        Object* object = (Object*)heap->FUN_008f6d30(size, 44);
        object->size = (unsigned short)size;
        return object;
    }
    static void operator delete(void* pointer)
    {
        Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(pointer, sizeof(Object), 44);
    }
};
struct Owner
{
    unsigned int tag;
    Object* source;
    void FUN_008fc3f0(Object*, int);
    void FUN_0094bfe0(Object*, int);
};
void Owner::FUN_0094bfe0(Object* destination, int argument)
{
    Object* original = source;
    if (!destination)
        destination = new Object;
    destination->value20 = original->value20;
    destination->value24 = original->value24;
    destination->value28 = original->value28;
    destination->value2c = original->value2c;
    destination->value30 = original->value30;
    destination->value34 = original->value34;
    destination->value38 = original->value38;
    destination->value3c = original->value3c;
    destination->value40 = original->value40;
    destination->value44 = original->value44;
    destination->value48 = original->value48;
    destination->value4c = original->value4c;
    destination->value50 = original->value50;
    destination->value54 = original->value54;
    destination->value58 = original->value58;
    destination->value5c = original->value5c;
    destination->value60 = original->value60;
    destination->value64 = original->value64;
    destination->value68 = original->value68;
    destination->value6c = original->value6c;
    destination->value70 = original->value70;
    destination->value74 = original->value74;
    destination->value78 = original->value78;
    destination->value7c = original->value7c;
    destination->value84 = original->value84;
    destination->value88 = original->value88;
    FUN_008fc3f0(destination, argument);
}
}
}   // namespace f3m_0094bfe0

// @f3 0x00950fe0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00950fe0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Copy517
{

struct Heap
{
    void* FUN_008f6d30(unsigned int, int);
    void FUN_008f6d90(void*, unsigned int, int);
};
struct Vector
{
    float x, y, z, w;
    __forceinline void Copy(const Vector& source)
    {
        x = source.x;
        y = source.y;
        z = source.z;
        w = source.w;
    }
};
struct Array
{
    Vector* data;
    int count, capacityFlags;
};
struct Output
{
    char pad[8];
    char state[12];
    Array vectors;
};
struct Child
{
    void FUN_009e8020(void*);
    const Array* FUN_009e7930();
};
struct Owner
{
    char pad[8];
    Child* child;
    void FUN_0090c4a0(Output*);
    void FUN_00950fe0(Output*);
};
// pdb: bhkConvexVerticesShape::CreateCinfo | bhkConvexVerticesShape.obj | fnv360_0721_beta, objrun, medium
// pdb params: arCreated
void Owner::FUN_00950fe0(Output* output)
{
    FUN_0090c4a0(output);
    if (this)
    {
        Child* current = child;
        if (current)
        {
            current->FUN_009e8020(output->state);
            const Array* source = current->FUN_009e7930();
            int raw = output->vectors.capacityFlags;
            int capacity = raw & 0x3fffffff;
            if (capacity < source->count)
            {
                if (!(raw & 0x80000000))
                {
                    Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
                    heap->FUN_008f6d90(output->vectors.data, capacity * sizeof(Vector), 23);
                }
                Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
                output->vectors.data = (Vector*)heap->FUN_008f6d30(source->count * sizeof(Vector), 23);
                output->vectors.capacityFlags = (output->vectors.capacityFlags & 0x40000000) | source->count;
            }
            int count = source->count;
            output->vectors.count = count;
            const Vector* in = source->data;
            Vector* out = output->vectors.data;
            for (int i = 0; i < count; ++i)
                out[i].Copy(in[i]);
        }
    }
}
}


}   // namespace f3m_00950fe0

// @f3 0x0095bbb0 (community match, verified in this file)
extern float DAT_00dbe620;
namespace f3m_0095bbb0 {

struct O_95bbb0
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
  int unk3C;
  int unk40;
  int unk44;
  int unk48;
  int unk4C;
  int unk50;
  int unk54;
  int unk58;
  int unk5C;
  unsigned char unk60;
  int unk64;
  float f68;
  float f6C;
  float f70;
  float f74;
  float f78;
  float f7C;
  O_95bbb0* FUN_0095bbb0();
};

O_95bbb0* O_95bbb0::FUN_0095bbb0()
{
  double tau=DAT_00dbe620;
  unk60 = 1;
  static_cast<volatile float&>(f68)=tau;
  unk64 = 0;
  f6C = 1.0f;
  f70 = 1.0f;
  f74 = 1.0f;
  f78 = 1.0f;
  f7C = 1.0f;
  return this;
}
}   // namespace f3m_0095bbb0

// @f3 0x00949d70 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00949d70 {
namespace f3m_00949d70 {
struct Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag); void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
inline Heap* GetHeap() { return (Heap*)TlsGetValue(DAT_010f3170); }
struct Block {
  int unk00; unsigned short size;
  Block();
  void* operator new(unsigned int n) { Block* p = (Block*)GetHeap()->FUN_008f6d30(0x140, 0x2c); p->size = 0x140; return p; }
  void operator delete(void* p) { GetHeap()->FUN_008f6d90(p, ((Block*)p)->size, 0x2c); }
};
struct Owner {
  int unk00; Block* block;
  unsigned int FUN_00949d70();
};
// pdb: hkRagdollConstraintCinfo::CreateData | bhkRagdollConstraint.obj | fnv360_0822_retail, caller_sim, medium
unsigned int Owner::FUN_00949d70() {
  if (!block) block = new Block;
  return 0x140;
}
}
}   // namespace f3m_00949d70

// @f3 0x0094aaf0 (community match, verified in this file)
extern double const DAT_00dcd110;
namespace f3m_0094aaf0 {
namespace Task2007 {
struct NiPoint3 {
    float x;
    float y;
    float z;

    char* __thiscall FUN_00823dc0(char const* name);
};

typedef NiPoint3 NiPoint3_local;

struct hkVector4 {
    float x;
    float y;
    float z;
    float w;
};

inline NiPoint3_local& FUN_004a3970(NiPoint3_local& result, hkVector4 const& value) { result.x=value.x; result.y=value.y; result.z=value.z; return result; }

struct StrArr {
    void* m_pVtable;
    void* m_pData;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned char m_pad000C;
    unsigned short m_usIncrement;

    void FUN_00555790(unsigned int size);
    void FUN_005b3880(unsigned int index, char*& value);
};

char* __cdecl FUN_00847dd0(char const* name, float value);


struct FUN_00cc7090_Constraint {
    unsigned char m_pad0000[0x20];
    hkVector4 m_twistAxisA;
    hkVector4 m_planeAxisA;
    unsigned char m_pad0040[0x10];
    hkVector4 m_kPivotInA;
    hkVector4 m_twistAxisB;
    hkVector4 m_planeAxisB;
    unsigned char m_pad0080[0x10];
    hkVector4 m_kPivotInB;
    unsigned char m_pad00A0[0x58];
    float m_fMaxFrictionTrq;
    unsigned char m_pad00FC[0x08];
    float m_fTwistMinAngle;
    float m_fTwistMaxAngle;
    unsigned char m_pad010C[0x10];
    float m_fConeMinAngle;
    unsigned char m_pad0120[0x0C];
    float m_fPlaneMinAngle;
    float m_fPlaneMaxAngle;
};

struct FUN_00cc7090_class {
    void* m_pVtable;
    FUN_00cc7090_Constraint* m_pConstraint;

    void __thiscall FUN_008fc920(StrArr* strArr);
    void __thiscall FUN_0094aaf0(StrArr* strArr);
};

// @fnv 0x00cc7090
// pdb: hkRagdollConstraintCinfo::GetViewerStrings | bhkRagdollConstraint.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void FUN_00cc7090_class::FUN_0094aaf0(StrArr* strArr)
{
    this->FUN_008fc920(strArr);

    FUN_00cc7090_Constraint* constraint = m_pConstraint;
    if (!constraint)
        return;

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        FUN_004a3970(point, constraint->m_kPivotInA);
        value = point.FUN_00823dc0("PivotInA");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        FUN_004a3970(point, constraint->m_planeAxisA);
        value = point.FUN_00823dc0("planeAxisA");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        FUN_004a3970(point, constraint->m_twistAxisA);
        value = point.FUN_00823dc0("twistAxisA");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        FUN_004a3970(point, constraint->m_kPivotInB);
        value = point.FUN_00823dc0("PivotInB");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        FUN_004a3970(point, constraint->m_planeAxisB);
        value = point.FUN_00823dc0("planeAxisB");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        FUN_004a3970(point, constraint->m_twistAxisB);
        value = point.FUN_00823dc0("twistAxisB");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00847dd0("ConeMinAngle", constraint->m_fConeMinAngle * DAT_00dcd110);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00847dd0("PlaneMinAngle", constraint->m_fPlaneMinAngle * DAT_00dcd110);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00847dd0("PlaneMaxAngle", constraint->m_fPlaneMaxAngle * DAT_00dcd110);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00847dd0("TwistMinAngle", constraint->m_fTwistMinAngle * DAT_00dcd110);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00847dd0("TwistMaxAngle", constraint->m_fTwistMaxAngle * DAT_00dcd110);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00847dd0("MaxFrictionTrq", constraint->m_fMaxFrictionTrq);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            strArr->FUN_00555790(strArr->m_usIncrement + index);
        strArr->FUN_005b3880(index, value);
    }
}

}
}   // namespace f3m_0094aaf0

// @f3 0x0095b160 (community match, verified in this file)
extern const volatile float DAT_00db75c8;
extern void* DAT_00e367bc[];
namespace f3m_0095b160 {
namespace Malleable2156 {

struct ChildData {
    void** table;
    unsigned short allocationBytes;
    unsigned short references;
};

struct BridgeAtom {
    unsigned short type, unk02;
    unsigned unk04, unk08;
    void hkpBridgeConstraintAtom_init(void* owner);
};

struct FUN_0095b160 {
    void** table;
    unsigned short allocationBytes;
    unsigned short references;
    void* userData;
    ChildData* volatile child;
    BridgeAtom atom;
    float strength;
    FUN_0095b160(ChildData* data);
};

// pdb: hkpMalleableConstraintData::hkpMalleableConstraintData | hkpMalleableConstraintData.obj | fnv360_0721_beta, objrun, medium
// pdb params: constraintData
FUN_0095b160::FUN_0095b160(ChildData* data)
{
    ChildData* input = static_cast<ChildData* volatile&>(data);
    const double defaultStrength = DAT_00db75c8;
    child = input;
    references = 1;
    userData = 0;
    table = DAT_00e367bc;
    BridgeAtom* bridge = &atom;
    bridge->type = 1;
    strength = static_cast<float>(defaultStrength);
    ChildData* current = child;
    if (current->allocationBytes)
        ++current->references;
    bridge->hkpBridgeConstraintAtom_init(this);
}
}
}   // namespace f3m_0095b160

// @f3 0x00941d30 (community match, verified in this file)
namespace f3m_00941d30 {
namespace f3m_00941d30 {
struct Empty { char v; };
struct Elem { int unk00; int unk04; int unk08; const char* key; int unk10; };
struct Info { const char* FUN_009b0490(); Info* FUN_009b04a0(); };
struct Set {
    int unk00, unk04, unk08, unk0C;
    void FUN_009b1110(Empty e);
    void FUN_009b0e60(const char* name, Info* info);
    int FUN_009b10f0(const char* name, int mode);
    void FUN_009b1160();
};
struct Table { Elem** entries; int count; };

Elem* __stdcall FUN_00941d30(Table* table, Info* info)
{
    Empty e;
    e.v = 0;
    Set set;
    set.FUN_009b1110(e);
    for (; info; info = info->FUN_009b04a0()) {
        const char* name = info->FUN_009b0490();
        set.FUN_009b0e60(name, info);
    }
    for (int i = 0; i < table->count; i++) {
        for (Elem* el = table->entries[i]; el->key; el++) {
            if (set.FUN_009b10f0(el->key, 0)) {
                set.FUN_009b1160();
                return el;
            }
        }
    }
    set.FUN_009b1160();
    return 0;
}
}
}   // namespace f3m_00941d30

// @f3 0x0094c1e0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094c1e0 {
namespace f3m_0094c1e0 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long);
struct FUN_009e09b0 {
    char unk00[4];
    unsigned short memSize;
    char unk06[0xa0 - 6];
    FUN_009e09b0();
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x2c);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x2c);
    }
};
struct Owner {
    int unk00;
    FUN_009e09b0* unk04;
    int FUN_0094c1e0();
};
// pdb: hkHingeLimitsConstraintCinfo::CloneData | bhkHingeLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apData, arCloneData
int Owner::FUN_0094c1e0() {
    if (!unk04)
        unk04 = new FUN_009e09b0;
    return 0xa0;
}
}
}   // namespace f3m_0094c1e0

// @f3 0x0094d910 (community match, verified in this file)
namespace f3m_0094d910 {
namespace C94 = f3m_0094d990;
struct CcaArgView94 {
    int unk00;
    unsigned int version;
};
struct FUN_0094d910_cls : C94::CcaThis {
    void FUN_00910e70(C94::CcaArg* arg);
    void FUN_0094d910(C94::CcaArg* arg);
};
void __cdecl FUN_00979ae0(C94::CcaArg* arg, int* state);
// pdb: bhkMoppBvTreeShape::LoadBinary | bhkMoppBvTreeShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arStream
void FUN_0094d910_cls::FUN_0094d910(C94::CcaArg* arg)
{
    C94::CcaArg* a = *(C94::CcaArg* volatile*)&arg;
    FUN_00910e70(a);
    C94::CcaRes* result = vf45((int*)&arg);
    if (result) {
        int state = 0;
        FUN_00979ae0(a, &state);
        if (((CcaArgView94*)a)->version < 2) {
            f3m_0094b3d0::hkReferencedObjectB3D* object = (f3m_0094b3d0::hkReferencedObjectB3D*)state;
            result->m_08 = 0;
            object->removeReference();
        } else {
            result->m_08 = state;
        }
    }
}
}   // namespace f3m_0094d910

// @f3 0x00950300 (community match, verified in this file)
namespace locked_factory_00950300 {
extern void (__stdcall* const DAT_00d9b09c)(void*);
extern void (__stdcall* const DAT_00d9b0a0)(void*);
struct CriticalSection {
    void* debugInfo;
    long lockCount,recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned int spinCount;
};
extern CriticalSection DAT_010f3194;
void* FUN_0089eb90(unsigned int);
void FUN_0089e890(void*);
struct FUN_00950180 {
    unsigned int unk00,unk04,unk08,unk0c,unk10;
    FUN_00950180();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* object) { FUN_0089e890(object); }
};
struct Owner {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8c();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Attach(FUN_00950180*,unsigned int);
    FUN_00950180* FUN_00950300(unsigned int);
};
FUN_00950180* Owner::FUN_00950300(unsigned int argument) {
    DAT_00d9b09c(&DAT_010f3194);
    FUN_00950180* object=new FUN_00950180;
    Attach(object,argument);
    DAT_00d9b0a0(&DAT_010f3194);
    return object;
}
}

// @f3 0x00957c00 (community match, verified in this file)
namespace f3m_00957c00 {
namespace n957c00 {
struct V4 {
    float x, y, z, w;
    __forceinline void Set(const V4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
};
struct Xf { V4 a; char pad[0x20]; };
struct Bone { int unk00; bool used; };
struct Pose {
    int unk00, unk04, unk08;
    Bone** bones;
    int count;
    Xf* data;
};
}
void __cdecl FUN_00957c00(n957c00::Pose* p, n957c00::Xf* out)
{
    int n = p->count;
    for (int i = 0; i < n; i++)
    {
        if (p->bones[i]->used)
            out[i].a.Set(p->data[i].a);
    }
}
}   // namespace f3m_00957c00

// @f3 0x0094aed0 (community match, verified in this file)
namespace f3m_0094aed0 {

struct Heap {
    void* FUN_0086b930(unsigned int bytes);
};
extern Heap DAT_01090a78;

extern const void* DAT_00e37180[];

class CinfoBase {
public:
    const void** m_vtbl;
};

class CinfoRef {
public:
    void* m_pRef;
    int m_refCount;
};

class CinfoConf {
public:
    int unk0C;
    int unk10;
};

class Cinfo : public CinfoBase, public CinfoRef, public CinfoConf {
public:
    static void* operator new(unsigned int n) throw() { return DAT_01090a78.FUN_0086b930(n); }
    Cinfo();
};

Cinfo::Cinfo()
{
    m_pRef = 0;
    unk0C = 0;
    unk10 = 0;
    m_refCount = 1;
    m_vtbl = DAT_00e37180;
}

class Owner {
public:
    int unk00;
    int unk04;
    void* m_pSource;
    CinfoRef* m_pChild;
    void FUN_008fc420(Cinfo* p);
    CinfoRef* FUN_0094aed0(bool* pbCreated);
};

// pdb: bhkPrismaticConstraint::KillCinfo | bhkPrismaticConstraint.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: bhkRagdollConstraint::CreateCinfo)
// pdb params: abCreated
CinfoRef* Owner::FUN_0094aed0(bool* pbCreated)
{
    if (m_pChild == 0) {
        Cinfo* p = new Cinfo();
        m_pChild = p;
        if (m_pSource != 0)
            FUN_008fc420((Cinfo*)m_pChild);
        *pbCreated = true;
        return m_pChild;
    }
    *pbCreated = false;
    return m_pChild;
}

}

// @f3 0x00951250 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00951250 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Destroy397 {
struct Heap { void FUN_008f6d90(void*, unsigned int, int); };

struct Array16 {
    void* data; unsigned int size, capacityFlags;
    void FUN_00950fb0() {
        if (!(capacityFlags & 0x80000000)) {
            unsigned int capacity = capacityFlags & 0x3fffffff;
            Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * 16, 23);
        }
    }
    ~Array16() { FUN_00950fb0(); }
};

struct Array12 {
    void* data; unsigned int count, capacityFlags;
    void Free() {
        unsigned int raw = capacityFlags;
        if (!(raw & 0x80000000)) {
            unsigned int capacity = raw & 0x3fffffff;
            Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * 12, 23);
        }
    }
};

struct Owner {
    Array16 first;
    Array12 second;
    void FUN_00951250();
};
struct ScopedFirst { Array16* first; ~ScopedFirst() { first->~Array16(); } };
// pdb: hkGeometry::~hkGeometry | bhkConvexVerticesShape.obj | fnv360_0822_retail, call_seq, medium
void Owner::FUN_00951250() { ScopedFirst cleanup = { &first }; second.Free(); }
}
}   // namespace f3m_00951250

// @f3 0x00952630 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00952630 {
namespace f3m_00952630 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned long);
struct Src { int unk00; int unk04; int unk08; int unk0c; int a10; int a14; };
struct Shape {
    virtual ~Shape();
    unsigned short memSize;
    short refCount;
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
    Shape(int a, int b);
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x27);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x27);
    }
    void RemoveReference() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
struct Owner {
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
    virtual void AddChild(struct Shape* p);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void Finish(struct Src* s);
    void FUN_00952630(Src* src);
};
// pdb: bhkConvexListShape::Init | bhkConvexListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void Owner::FUN_00952630(Src* src)
{
    if (src) {
        int a = src->a10;
        int b = src->a14;
        Shape* p = new Shape(a, b);
        AddChild(p);
        p->RemoveReference();
        Finish(src);
    }
}
}
}   // namespace f3m_00952630

// @f3 0x0094b350 (community match, verified in this file)
namespace F3Prismatic2290 {
struct Pool { void* FUN_008f6d30(unsigned, unsigned); };
extern unsigned DAT_010f3170;
extern Pool* (__stdcall* DAT_00d9b080)(unsigned);
extern void __cdecl FUN_009e10c0(void*);
struct FUN_009dd270 {
    void* table;
    unsigned short size, references;
    unsigned unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    FUN_009dd270();
    static void* operator new(unsigned bytes) {
        Pool* pool=DAT_00d9b080(DAT_010f3170);
        FUN_009dd270* object=static_cast<FUN_009dd270*>(pool->FUN_008f6d30(bytes,0x2c));
        object->size=static_cast<unsigned short>(bytes);
        return object;
    }
    static void operator delete(void* object) { FUN_009e10c0(object); }
};
struct Owner {
    void* table;
    FUN_009dd270* constraint;
    unsigned FUN_0094b350();
};
unsigned Owner::FUN_0094b350()
{
    if(!constraint)
        constraint=new FUN_009dd270;
    return sizeof(FUN_009dd270);
}
}

// @f3 0x00948fa0 (community match, verified in this file)
namespace F3StiffSpring2293 {
struct Pool { void* FUN_008f6d30(unsigned, unsigned); };
extern unsigned DAT_010f3170;
extern Pool* (__stdcall* DAT_00d9b080)(unsigned);
extern void __cdecl FUN_009e10c0(void*);
struct FUN_009dc390 {
    void* table;
    unsigned short size, references;
    unsigned unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    FUN_009dc390();
    static void* operator new(unsigned bytes) {
        Pool* pool=DAT_00d9b080(DAT_010f3170);
        FUN_009dc390* object=static_cast<FUN_009dc390*>(pool->FUN_008f6d30(bytes,0x2c));
        object->size=static_cast<unsigned short>(bytes);
        return object;
    }
    static void operator delete(void* object) { FUN_009e10c0(object); }
};
struct Owner {
    void* table;
    FUN_009dc390* constraint;
    unsigned FUN_00948fa0();
};
unsigned Owner::FUN_00948fa0()
{
    if(!constraint)
        constraint=new FUN_009dc390;
    return sizeof(FUN_009dc390);
}
}

// @f3 0x00948390 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00948390 {
namespace n948390 {
struct Alloc { void* FUN_008f6d30(int size, int tag); };
extern Alloc* (__stdcall* DAT_00d9b080)(unsigned long);
extern void __cdecl FUN_009e10c0(void*);
struct V4 { float x, y, z, w; void Mul(float k) { x=k*x; y *= k; z *= k; w *= k; } };
struct Proc { int m0, m4, m8, mc; float scale; };
struct FUN_009dc0f0 {
    void* vtbl;
    unsigned short memSize;
    short refs;
    unsigned unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    V4 v50;
    unsigned unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    V4 v90;
    int pa0;
    float a4, a8;
    int pac;
    float b0, b4;
    unsigned unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    FUN_009dc0f0();
    static void* operator new(unsigned int size) {
        Alloc* a = DAT_00d9b080(DAT_010f3170);
        FUN_009dc0f0* p = (FUN_009dc0f0*)a->FUN_008f6d30(size, 0x2c);
        p->memSize = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p) { FUN_009e10c0(p); }
};
}
struct C948390 {
    int m0;
    n948390::FUN_009dc0f0* src;
    void FUN_008fc3f0(n948390::FUN_009dc0f0* dst, n948390::Proc* proc);
    void FUN_00948390(n948390::FUN_009dc0f0* dst, n948390::Proc* proc);
};
void C948390::FUN_00948390(n948390::FUN_009dc0f0* dst, n948390::Proc* proc)
{
    n948390::FUN_009dc0f0* s = src;
    if (!dst)
        dst = new n948390::FUN_009dc0f0;
    dst->v50.x = s->v50.x;
    dst->v50.y = s->v50.y;
    dst->v50.z = s->v50.z;
    dst->v50.w = s->v50.w;
    dst->v90.x = s->v90.x;
    dst->v90.y = s->v90.y;
    dst->v90.z = s->v90.z;
    dst->v90.w = s->v90.w;
    dst->a4 = s->a4;
    dst->a8 = s->a8;
    dst->b0 = s->b0;
    dst->b4 = s->b4;
    float k = proc->scale;
    if (k != 1.0f) {
        dst->v50.Mul(k);
        dst->v90.x=static_cast<const volatile float&>(dst->v90.x)*k;
        dst->v90.y=dst->v90.y*k;
        dst->v90.z=dst->v90.z*k;
        dst->v90.w=dst->v90.w*k;
    }
    FUN_008fc3f0(dst, proc);
}

}   // namespace f3m_00948390

// @f3 0x00947d70 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern const float DAT_00db8ea4;
extern char DAT_00e7a880;
namespace f3m_00947d70 {
namespace Breakable2302 {


struct Alloc_00947d70 {
    void* __thiscall FUN_008f6d30(int, int);
};

extern Alloc_00947d70* (__stdcall* DAT_00d9b080)(unsigned long);

struct Object_00947d70 {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float unk20;
    unsigned char unk24;
    unsigned char unk25;
    int unk28;
};

struct FUN_00947d70_cls {
    void* unk00;
    Object_00947d70* unk04;

    unsigned int FUN_00947d70();
};

unsigned int FUN_00947d70_cls::FUN_00947d70()
{
    if (!unk04) {
        Alloc_00947d70* allocator = DAT_00d9b080(DAT_010f3170);
        Object_00947d70* object = reinterpret_cast<Object_00947d70*>(
            allocator->FUN_008f6d30(0x2c, 0x2c));

        const double defaultValue = static_cast<const volatile float&>(DAT_00db8ea4);
        static_cast<volatile unsigned short&>(object->unk04) = sizeof(Object_00947d70);
        static_cast<volatile unsigned short&>(object->unk06) = 1;
        object->unk08 = 0;
        object->unk0C = 1;
        static_cast<volatile float&>(object->unk20) = static_cast<float>(defaultValue);
        object->unk18 = 0;
        object->unk00 = &DAT_00e7a880;
        object->unk28 = 0;
        object->unk24 = 0;
        object->unk25 = 0;

        unk04 = object;
    }

    return 0x2c;
}

}

}   // namespace f3m_00947d70

// @f3 0x00948db0 (community match, verified in this file)
namespace SpringCopy2306 {
struct Pool { void* FUN_008f6d30(unsigned,unsigned); };
extern unsigned DAT_010f3170;
extern Pool* (__stdcall* DAT_00d9b080)(unsigned);
extern void __cdecl FUN_009e10c0(void*);
struct Vector {
    float x,y,z,w;
    void Copy(const Vector& rhs) {x=rhs.x;y=rhs.y;z=rhs.z;w=rhs.w;}
    void Scale(float factor) {x*=factor;y*=factor;z*=factor;w*=factor;}
};
struct FUN_009dc390 {
    void* table;
    unsigned short size, references;
    unsigned unk08,unk0c,unk10,unk14,unk18,unk1c;
    Vector first,second;
    unsigned unk40;
    float damping;
    unsigned unk48,unk4c;
    FUN_009dc390();
    static void* operator new(unsigned bytes) {
        Pool* pool=DAT_00d9b080(DAT_010f3170);
        FUN_009dc390* p=static_cast<FUN_009dc390*>(pool->FUN_008f6d30(bytes,0x2c));
        p->size=static_cast<unsigned short>(bytes);
        return p;
    }
    static void operator delete(void* p) {FUN_009e10c0(p);}
};
struct Process {unsigned unk00,unk04,unk08,unk0c; float scale;};
struct Owner {
    void* table;
    FUN_009dc390* source;
    void FUN_008fc3f0(FUN_009dc390*, Process*);
    void FUN_00948db0(FUN_009dc390*, Process*);
};
void Owner::FUN_00948db0(FUN_009dc390* destination,Process* process)
{
    const FUN_009dc390* data=source;
    if(!destination) destination=new FUN_009dc390;
    destination->first.Copy(data->first);
    destination->second.Copy(data->second);
    destination->damping=data->damping;
    float factor=process->scale;
    if(factor!=1.0f) {
        destination->first.Scale(factor);
        destination->second.x=factor*destination->second.x;
        destination->second.y=destination->second.y*factor;
        float& z=destination->second.z;
        z=factor*z;
        destination->second.w=destination->second.w*factor;
    }
    FUN_008fc3f0(destination,process);
}
}

// @f3 0x00950c20 (community match, verified in this file)
namespace F3Convex2310 {
extern unsigned DAT_010f3170;
struct Pool { void* FUN_008f6d30(unsigned,unsigned); };
extern Pool* (__stdcall* DAT_00d9b080)(unsigned);
extern const float DAT_00f7ad9c, DAT_00f7a690;
extern void __cdecl FUN_00951b90(void*);
struct Points { const void* points; int count; int stride; };
struct Input {
    unsigned unk00,unk04;
    const void* points;
    int count;
    unsigned unk10, options;
};
struct FUN_009e8750;
struct ShapeTable {void (__thiscall* destroy)(FUN_009e8750*,int);};
struct FUN_009e8750 {
    ShapeTable* table;
    unsigned short size;
    short references;
    unsigned unk08,unk0c;
    float radius;
    unsigned unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    FUN_009e8750(const Points*,const unsigned*,float);
    static void* operator new(unsigned bytes) {
        Pool* pool=DAT_00d9b080(DAT_010f3170);
        FUN_009e8750* p=static_cast<FUN_009e8750*>(pool->FUN_008f6d30(bytes,0x27));
        p->size=static_cast<unsigned short>(bytes);
        return p;
    }
    static void operator delete(void* p) { FUN_00951b90(p); }
    void ReleaseReference() {
        if(size) {
            --references;
            short remaining=references;
            if(!remaining) table->destroy(this,1);
        }
    }
};
struct Owner;
struct OwnerTable {
    void* unk00, *unk04, *unk08, *unk0c, *unk10, *unk14, *unk18, *unk1c, *unk20, *unk24, *unk28, *unk2c, *unk30, *unk34, *unk38, *unk3c, *unk40, *unk44, *unk48, *unk4c, *unk50, *unk54, *unk58, *unk5c, *unk60, *unk64, *unk68, *unk6c, *unk70, *unk74, *unk78, *unk7c, *unk80, *unk84, *unk88;
    void (__thiscall* attach)(Owner*,FUN_009e8750*);
    void* unk90, *unk94, *unk98, *unk9c, *unka0, *unka4, *unka8, *unkac, *unkb0, *unkb4, *unkb8;
    void (__thiscall* notify)(Owner*,Input*);
};
struct Owner { OwnerTable* table; void FUN_00950c20(Input*); };
// pdb: bhkConvexVerticesShape::CreateClone | bhkConvexVerticesShape.obj | fnv360_0721_beta, objrun, medium
// pdb params: arCloneData
void Owner::FUN_00950c20(Input* input)
{
    if(!input) return;
    Points points;
    points.count=input->count;
    points.stride=0x10;
    points.points=input->points;
    FUN_009e8750* shape=new FUN_009e8750(&points,&input->options,DAT_00f7ad9c);
    shape->radius=DAT_00f7a690;
    table->attach(this,shape);
    shape->ReleaseReference();
    table->notify(this,input);
}
}

// @f3 0x00951ed0 (community match, verified in this file)
namespace f3m_00951ed0 {
struct Value {};
struct Args { int unk00,unk04; unsigned short capacity,count,unk0c,growth; void FUN_00555790(unsigned); void FUN_005b3880(unsigned,Value**); };
struct Vec { float x,y,z; Value* FUN_00823dc0(const char*); };
struct Matrix { float a,b,c,d,e,f,g,h,i; Value* FUN_00823bc0(const char*); };
struct Transform { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; float x,y,z; };
struct Callback { void** vtable; };
struct Chain { int unk00,unk04; Callback* callback; };
struct Node { int unk00,unk04,unk08,unk0c,unk10,unk14; Chain* chain; int unk1c; Transform transform; };
struct Owner { int unk00,unk04; Node* node; void FUN_0090c5a0(Args*); void FUN_00951ed0(Args*); };
extern void* DAT_01169258;
extern Transform DAT_010f3370;
extern char DAT_00e347dc, DAT_00e347d8;
extern double DAT_00db88e8;
struct Local { Matrix m; Vec p; int unk30; };
Value* __cdecl FUN_00847b50(void*);
void __cdecl FUN_0056ac90(Matrix*,Transform*);
// pdb: bhkConvexTransformShape::GetViewerStrings | bhkConvexTransformShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Owner::FUN_00951ed0(Args* a) {
    FUN_0090c5a0(a);
    Value* v=FUN_00847b50(DAT_01169258);
    unsigned int index=a->count;
    if (index>=a->capacity) a->FUN_00555790(index+a->growth);
    a->FUN_005b3880(index,&v);
    Transform* t;
    if (this && node) t=&node->transform; else t=&DAT_010f3370;
    Local local; FUN_0056ac90(&local.m,t); local.p.x=t->x*DAT_00db88e8; local.p.y=t->y*DAT_00db88e8; local.p.z=t->z*DAT_00db88e8;
    v=local.p.FUN_00823dc0(&DAT_00e347dc);
    index=a->count;
    if(index>=a->capacity) a->FUN_00555790(index+a->growth);
    a->FUN_005b3880(index,&v);
    v=local.m.FUN_00823bc0(&DAT_00e347d8);
    index=a->count;
    if(index>=a->capacity) a->FUN_00555790(index+a->growth);
    a->FUN_005b3880(index,&v);
    if(this && node && node->chain && node->chain->callback) {
        Callback* c=node->chain->callback;
        typedef void (__thiscall *Fn)(Callback*,Args*);
        ((Fn)c->vtable[0x60/4])(c,a);
    }
}
}

// @f3 0x00950dc0 (community match, verified in this file)
namespace f3m_00950dc0 {
namespace f3m_00950dc0 {
// FUN_00950dc0 (0x00950dc0, 485 bytes): CE340Obj save-with-arrays shape (draft: CE340Obj::SaveWithArrays).
struct CE340Vec4 { float x, y, z, w; };
struct CE340Array;
struct CE340Heap { void FUN_008f6d90(CE340Vec4* p, unsigned int bytes, int tag); };
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);

struct CE340Array {
    int getCapacity() const { return m_cap & 0x3fffffff; }
    CE340Vec4* m_data;
    unsigned int m_count;
    unsigned int m_cap;   // bit 31 = not owned (empty default)
    CE340Array() : m_data(0), m_count(0), m_cap(0x80000000) {}
    void swap(CE340Array& o) {
        CE340Vec4* d = m_data; m_data = o.m_data; o.m_data = d;
        unsigned int c = m_count; m_count = o.m_count; o.m_count = c;
        unsigned int p = m_cap; m_cap = o.m_cap; o.m_cap = p;
    }
    ~CE340Array() {
        if ((m_cap & 0x80000000) == 0) {
            int n = getCapacity();
            CE340Heap* heap = (CE340Heap*)FUN_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(m_data, n * sizeof(CE340Vec4), 0x17);
        }
    }
};

struct CE340Data {
    int unk00;
    int unk04;
    CE340Array m_arr08;
    CE340Array m_arr14;
};

struct CE340Stream;
struct CE340Data;
struct CE340Array;
void FUN_009793e0(CE340Data* d, void* ctx, CE340Array* a);
void FUN_00979770(CE340Stream* s, CE340Array* a);

struct CE340Obj {
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03(); virtual void vf04();
    virtual void vf05(); virtual void vf06(); virtual void vf07(); virtual void vf08(); virtual void vf09();
    virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13(); virtual void vf14();
    virtual void vf15(); virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23(); virtual void vf24();
    virtual void vf25(); virtual void vf26(); virtual void vf27(); virtual void vf28(); virtual void vf29();
    virtual void vf30(); virtual void vf31(); virtual void vf32(); virtual void vf33(); virtual void vf34();
    virtual void vf35(); virtual void vf36(); virtual void vf37(); virtual void vf38(); virtual void vf39();
    virtual void vf40();
    virtual void SetFlag(bool flag);          // vtbl +0xa4
    virtual void* GetContext();               // vtbl +0xa8
    virtual void vf43();
    virtual void vf44();
    virtual CE340Data* GetData(bool* flag);   // vtbl +0xb4
    void bhkConvexShape_SaveBinary(CE340Stream* stream);
    void FUN_00950dc0(CE340Stream* stream);
};

// pdb: bhkConvexVerticesShape::CopyCinfo | bhkConvexVerticesShape.obj | fnv360_0721_beta, objrun, low, conflict (bridge: bhkConvexVerticesShape::SaveBinary)
// pdb params: arInfo
void CE340Obj::FUN_00950dc0(CE340Stream* stream)
{
    bool flag;
    CE340Data* data = GetData(&flag);
    CE340Array arrFirst;
    CE340Array arrSecond;
    if (data != 0) {
        arrFirst.swap(data->m_arr08);
        arrSecond.swap(data->m_arr14);
        if (*((unsigned char*)stream + 0x1e4) != 1) {
            void* ctx = GetContext();
            FUN_009793e0(data, ctx, &data->m_arr08);
            FUN_009793e0(data, ctx, &data->m_arr14);
        }
    }
    bhkConvexShape_SaveBinary(stream);
    if (data != 0) {
        FUN_00979770(stream, &arrFirst);
        FUN_00979770(stream, &arrSecond);
        SetFlag(flag);
        if (!flag && *((unsigned char*)stream + 0x1e4) != 1) {
            void* ctx = GetContext();
            FUN_009793e0(data, ctx, &data->m_arr08);
            FUN_009793e0(data, ctx, &data->m_arr14);
        }
    }
}

}
}   // namespace f3m_00950dc0

// @f3 0x00955fc0 (community match, verified in this file)
namespace f3m_00955fc0 {
namespace f3m_00955fc0 {
struct Vec4 {
    float x,y,z,w;
    __forceinline void SetAll(float value) { x=value; y=value; z=value; w=value; }
};
struct Bounds { Vec4 minimum,maximum; };
struct Info { unsigned int unk00,unk04,unk08,unk0c; int count; };
struct PointRecord {
    Vec4 position;
    unsigned int unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
};
__forceinline float MinValue(const float& a,const float& b) { return a<b ? a : b; }
__forceinline float MaxValue(const float& a,const float& b) { return a>b ? a : b; }

struct Owner {
    Info* info;
    unsigned int unk04,unk08,unk0c;
    PointRecord* points;
    void hkaPose_syncModelSpace();
    void FUN_00955fc0(Bounds* bounds);
};
void Owner::FUN_00955fc0(Bounds* bounds)
{
    bounds->minimum.SetAll(3.40282e38f);
    bounds->maximum.SetAll(-3.40282e38f);
    int count=info->count;
    hkaPose_syncModelSpace();
    if (count>0) {
        const PointRecord* point=points;
        do {
            bounds->minimum.x=MinValue(bounds->minimum.x,point->position.x);
            bounds->minimum.y=MinValue(bounds->minimum.y,point->position.y);
            bounds->minimum.z=MinValue(bounds->minimum.z,point->position.z);
            bounds->minimum.w=MinValue(bounds->minimum.w,point->position.w);
            bounds->maximum.x=MaxValue(bounds->maximum.x,point->position.x);
            bounds->maximum.y=MaxValue(bounds->maximum.y,point->position.y);
            bounds->maximum.z=MaxValue(bounds->maximum.z,point->position.z);
            bounds->maximum.w=MaxValue(bounds->maximum.w,point->position.w);
            ++point;
        } while (--count);
    }
}
}

}   // namespace f3m_00955fc0

// @f3 0x00953c80 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00953c80 {
namespace n953c80 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
struct FreeNode { FreeNode* next; };
struct FreeList {
    FreeNode* head;
    int count;
    void Push(FreeNode* b) throw() { ++count; b->next = head; head = b; }
};
struct ThreadMemory {
    char pad[0x34];
    int limit;
    char pad38[0x10];
    FreeList row2;
    void FUN_008f6890(int row, void* p, int tag) throw();
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
inline ThreadMemory* Mem() throw() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> struct hkArray {
    T* data;
    int size;
    int capAndFlags;
    ~hkArray() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Mem()->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct hkString {
    char* data;
    int size;
    int capacityAndFlags;
    ~hkString() throw() {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int cap = capacityAndFlags & 0x3fffffff;
            Mem()->FUN_008f6d90(data, cap, 0x17);
        }
    }
    static void operator delete(void* p) throw() {
        ThreadMemory* pool = Mem();
        FreeList* bucket = &pool->row2;
        if (*(volatile int*)&bucket->count >= pool->limit)
            pool->FUN_008f6890(2, p, 0x16);
        else
            bucket->Push((FreeNode*)p);
    }
};
struct Pair8 { int a, b; };
}
class hkBaseObject {
public:
    virtual ~hkBaseObject() throw() {}
};
class hkReferencedObject : public hkBaseObject {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void removeReference() throw() {
        if (m_memSizeAndFlags != 0) {
            --m_referenceCount;
            if (m_referenceCount == 0) delete this;
        }
    }
};
struct Context953 { virtual void v00() throw(); virtual void v04() throw(); virtual void v08(int) throw(); };
class FUN_00953c80 : public hkReferencedObject {
public:
    int unk08;
    n953c80::hkArray<n953c80::Pair8> m_0c;
    n953c80::hkArray<Context953*> m_contexts;
    n953c80::hkArray<n953c80::Pair8> m_24;
    n953c80::hkArray<void*> m_30;
    n953c80::hkArray<void*> m_3c;
    hkReferencedObject* m_server;
    n953c80::hkArray<n953c80::hkString*> m_strings;
    int FUN_00953410() throw();
    virtual ~FUN_00953c80() throw();
};
// pdb: hkVisualDebugger::~hkVisualDebugger | hkVisualDebugger.obj | fnv360_0822_retail, call_seq, medium
FUN_00953c80::~FUN_00953c80() throw()
{
    FUN_00953410();
    for (int i = 0; i < m_contexts.size; i++)
        m_contexts.data[i]->v08(0);
    for (int i = 0; i < m_strings.size; i++)
        delete m_strings.data[i];
    m_strings.size = 0;
    if (m_server)
        m_server->removeReference();
}
}   // namespace f3m_00953c80

// @f3 0x00959300 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00959300 {
namespace n959300 {
struct hkThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* AllocateStackSlow(int nbytes) throw();
    virtual void PopStack(void* p) throw();
    int unk04[7];
    char* m_current;
    int unk24;
    char* m_previous;
    char* m_end;
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    void* AllocateStack(int nbytes)
    {
        int aligned = (nbytes + 16) & ~15;
        char* current = m_current;
        char* next = current + aligned;
        if (next <= m_end)
        {
            m_current = next;
            return current;
        }
        return AllocateStackSlow(aligned);
    }
    void DeallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_previous)
            PopStack(p);
    }
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
inline hkThreadMemory* GetThreadMemory() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
__forceinline void DeallocateChunk(void* p, int n, int cls) { GetThreadMemory()->FUN_008f6d90(p, n, cls); }
void __cdecl FUN_00901e90(void* arr, int capacity, int stride) throw();
void __cdecl FUN_00901f10(void* arr, int stride) throw();
struct ShortArray {
    short* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline void PushBack(short v)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 2);
        m_data[m_size] = v;
        m_size++;
    }
};
struct CharArray {
    char* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline CharArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline int GetCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline void Free()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int size = GetCapacity(); GetThreadMemory()->FUN_008f6d90(m_data, size, 0x17);
        }
    }
};
struct LocalCharArray : CharArray {
    char* m_localMemory;
    __forceinline LocalCharArray(int n)
    {
        m_data = (char*)GetThreadMemory()->AllocateStack(n);
        m_capacityAndFlags = n | 0x80000000;
        m_localMemory = m_data;
    }
    __forceinline ~LocalCharArray()
    {
        char* mem = m_localMemory; GetThreadMemory()->DeallocateStack(mem);
        Free();
    }
    __forceinline void SetSize(int n, char fill)
    {
        if (n > m_size)
        {
            int old = m_size;
            int cap = m_capacityAndFlags & 0x3fffffff;
            if (cap < n)
            {
                int c2 = cap * 2;
                FUN_00901e90(this, n < c2 ? c2 : n, 1);
            }
            for (int i = old; i < n; i++)
                m_data[i] = fill;
        }
        m_size = n;
    }
};
struct Graph {
    int unk00;
    short* m_parents;
    int unk08;
    int unk0c;
    int m_count;
};
}


// pdb: hkaSkeletonUtils::getDescendants | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun, medium
// pdb params: skeleton, startBone, bonesOut, includeStart
void __cdecl FUN_00959300(n959300::Graph* graph, short start, n959300::ShortArray* out)
{
    n959300::LocalCharArray visited(graph->m_count);
    visited.SetSize(graph->m_count, 0);
    visited.m_data[start] = 1;
    for (short i = start + 1; i < graph->m_count; i++)
    {
        if (visited.m_data[graph->m_parents[i]])
        {
            visited.m_data[i] = 1;
            out->PushBack(i);
        }
    }
}
}   // namespace f3m_00959300

// @f3 0x0094cc90 (community match, verified in this file)
#include <new>
namespace f3m_0094cc90 {

struct Heap94cc90 { void* FUN_0086b930(unsigned int bytes); };

class hkSerializableCinfo {
public:
    int unk04;
    hkSerializableCinfo() throw() : unk04(0) {}
};
struct __declspec(novtable) hkConstraintCinfo : hkSerializableCinfo {
    virtual ~hkConstraintCinfo() throw();
    int unk08, unk0c, unk10;
    hkConstraintCinfo() throw()
    {
        unk0c = 0;
        unk10 = 0;
        unk08 = 1;
    }
};
struct ChainArray94cc90 {
    void* data;
    int size;
    unsigned capacity;
    ChainArray94cc90() throw() : data(0), size(0), capacity(0x80000000u) {}
};
struct __declspec(novtable) hkConstraintChainCinfo : hkConstraintCinfo {
    ChainArray94cc90 links;
    hkConstraintChainCinfo() throw() {}
};
struct hkBallSocketChainCinfo : hkConstraintChainCinfo {
    ChainArray94cc90 anchors;
    hkBallSocketChainCinfo() throw() {}
    virtual ~hkBallSocketChainCinfo() throw();
    static void* operator new(size_t bytes) throw() { return reinterpret_cast<Heap94cc90*>(&::DAT_01090a78)->FUN_0086b930(bytes); }
};
struct Owner94cc90 {
    int unk00, unk04;
    void* pending;
    hkSerializableCinfo* info;
    void FUN_0094caa0(hkBallSocketChainCinfo*);
    hkSerializableCinfo* FUN_0094cc90(bool* created);
};
// pdb: bhkBallSocketConstraintChain::CreateCinfo | bhkBallSocketConstraintChain.obj | fnv360_0822_retail, objrun_open, low
// pdb params: arCreated
hkSerializableCinfo* Owner94cc90::FUN_0094cc90(bool* created)
{
    if (info == 0) {
        hkSerializableCinfo* base = new hkBallSocketChainCinfo;
        info = base;
        if (pending)
            FUN_0094caa0(static_cast<hkBallSocketChainCinfo*>(base));
        *created = true;
    } else {
        *created = false;
    }
    return info;
}

}   // namespace f3m_0094cc90

// @f3 0x0095a8e0 (community match, verified in this file)
namespace f3m_0095a8e0 {
extern "C" void _WriteBarrier();
namespace constraint_atom_defaults {
struct __declspec(align(16)) Vector4 { float x,y,z,w; };
struct __declspec(align(16)) Matrix3 { Vector4 column0,column1,column2; };
struct __declspec(align(16)) Transform { Matrix3 rotation;Vector4 translation; };
struct __declspec(align(16)) LocalTransformsAtom {
 unsigned short type,unk02;unsigned int unk04,unk08,unk0C;
 Transform transformA,transformB;
 __forceinline LocalTransformsAtom() : type(2) {}
};
struct ConstraintAtom { unsigned short type;__forceinline ConstraintAtom(unsigned short value):type(value){} };
struct Enabled { bool value;__forceinline Enabled(bool initial) { _WriteBarrier(); value = initial; } };
struct ControlAtom : ConstraintAtom {

 Enabled enabled;
 unsigned char unk03;
 unsigned short unk04;
 unsigned short unk06;
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
 __forceinline ControlAtom() : ConstraintAtom(19),enabled(true) { unk04=0;unk06=0; }
};
struct ConstraintAtoms {
 LocalTransformsAtom transforms;
 ControlAtom control;
 unsigned short unk0E0;
 unsigned char unk0E2;
 unsigned char unk0E3;
 unsigned char unk0E4;
 unsigned char unk0E5;
 unsigned short unk0E6;
 unsigned int unk0E8;
 unsigned short unk0EC;
 unsigned char unk0EE;
 unsigned char unk0EF;
 unsigned int unk0F0;
 unsigned int unk0F4;
 unsigned int unk0F8;
 unsigned int unk0FC;
 unsigned short unk100;
 unsigned char unk102;
 unsigned char unk103;
 unsigned short unk104;
 unsigned char unk106;
 unsigned char unk107;
 unsigned int unk108;
 unsigned int unk10C;
 unsigned int unk110;
 unsigned short unk114;
 unsigned char unk116;
 unsigned char unk117;
 unsigned short unk118;
 unsigned char unk11A;
 unsigned char unk11B;
 unsigned int unk11C;
 unsigned int unk120;
 unsigned int unk124;
 unsigned short unk128;
 ConstraintAtoms();
};
// pdb: hkpRagdollConstraintData::Atoms::Atoms | hkpRagdollConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
ConstraintAtoms::ConstraintAtoms() {
 unk0E0=17;
 unk0E2=1;
 unk0E4=1;
 unk0EC=15;
 unk0EE=1;
 unk100=16;
 unk102=1;
 unk106=0;
 unk114=16;
 unk116=1;
 unk11A=0;
 unk128=5;
}
}

}   // namespace f3m_0095a8e0

// @f3 0x009499a0 (community match, verified in this file)
extern "C" void _WriteBarrier();
namespace NativeRagdollInfo {
struct Heap { void* FUN_0086b930(unsigned int size); };
extern Heap DAT_01090a78;
extern const void* DAT_00e7aabc[];
struct Item {
    int unk00;
    int kind;
    int unk08, unk0c;
};
struct InfoHeader { const void* table; };
struct ConstraintInfo : InfoHeader, Item {};
struct Owner {
    int unk00, unk04;
    void* constraint;
    Item* cached;
    void FUN_008fc420(ConstraintInfo* info);
    Item* FUN_009499a0(unsigned char* created);
};
// pdb: bhkRagdollLimitsConstraint::CreateCinfo | bhkRagdollLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCreated
Item* Owner::FUN_009499a0(unsigned char* created)
{
    if (!cached) {
        ConstraintInfo* object = static_cast<ConstraintInfo*>(DAT_01090a78.FUN_0086b930(sizeof(ConstraintInfo)));
        Item* item;
        if (object) {
            item = object;
            item->unk00 = 0;
            _WriteBarrier();
            object->unk08 = 0;
            object->unk0c = 0;
            object->kind = 1;
            object->table = DAT_00e7aabc;
        } else {
            item = 0;
        }
        cached = item;
        if (constraint) {
            FUN_008fc420(static_cast<ConstraintInfo*>(item));
        }
        *created = 1;
        return cached;
    }
    *created = 0;
    return cached;
}
}

// @f3 0x0095a060 (community match, verified in this file)
#include <math.h>
namespace f3m_0095a060 {
struct Matrix95;
struct SR { float m_real; SR(){} SR(float r):m_real(r){} operator float() const { return m_real; } };
struct SP { float m_real; };
__forceinline float hkSqrt(float r) { return (float)sqrt(r); }
__forceinline float hkSqrtInv(float r) { return 1.0f/hkSqrt(r); }
struct __declspec(align(16)) Axis95 {
 __forceinline void Rotated(const Matrix95&,const Axis95&);
 float x,y,z,w;
 Axis95() {}
 Axis95(const Axis95& a) { x=a.x;y=a.y;z=a.z;w=a.w; }
 Axis95& operator=(const Axis95& a) { x=a.x;y=a.y;z=a.z;w=a.w;return *this; }
 __forceinline void mul4(const SR& s) { x*=s.m_real;y*=s.m_real;z*=s.m_real;w*=s.m_real; }
 __forceinline void mul4v(SR s) { x*=s.m_real;y*=s.m_real;z*=s.m_real;w*=s.m_real; }
 __forceinline void mul4p(const SP& s) { x*=s.m_real;y*=s.m_real;z*=s.m_real;w*=s.m_real; }
 __forceinline SR lenInv() const { float l2=x*x+y*y+z*z; return l2!=0.0f ? SR(hkSqrtInv(l2)) : SR(0.0f); }
 __forceinline SR lenInv2() const { float l2=x*x+y*y+z*z; if(l2!=0.0f) { l2=(float)sqrt(l2); l2=1.0f/l2; } else l2=0.0f; return SR(l2); }
 __forceinline float lenInvF() const { float l2=x*x+y*y+z*z; if(l2!=0.0f) { l2=(float)sqrt(l2); l2=1.0f/l2; } else l2=0.0f; return l2; }
 __forceinline void Normalize() {
  mul4(SR(lenInvF()));
 }
 __forceinline void Cross(const Axis95& a,const Axis95& b) {
  float crossX=a.y*b.z-a.z*b.y;
  float crossY=a.z*b.x-a.x*b.z;
  float crossZ=a.x*b.y-a.y*b.x;
  x=crossX;y=crossY;z=crossZ;w=0;
 }
};
struct __declspec(align(16)) Matrix95 {
 Axis95 row[3];
 __forceinline void Rotate(const Matrix95& m,const Matrix95& source) {
  Matrix95 copy=m;
  int i=2; do {
   row[i].Rotated(copy,source.row[i]);
  } while(--i>=0);
 }
};
__forceinline void Axis95::Rotated(const Matrix95& copy,const Axis95& input) {
 float a=input.x,b=input.y,c=input.z;
 x=copy.row[0].x*a+copy.row[0].y*b+copy.row[0].z*c;
 y=copy.row[1].x*a+copy.row[1].y*b+copy.row[1].z*c;
 z=copy.row[2].x*a+copy.row[2].y*b+copy.row[2].z*c;
 w=0;
}
struct Transform95 { Matrix95 rotation; Axis95 translation; };
struct Point95 : Axis95 { void FUN_008d2970(const Transform95&,const Axis95&); };
struct Owner95 {
 int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C;
 Matrix95 unk20;
 Point95 unk50;
 Matrix95 unk60;
 Point95 unk90;
 Axis95 unkA0;
 Matrix95 unkB0;
 void FUN_0095a060(const Transform95&,const Transform95&,const Axis95&,const Axis95&,const Axis95&);
};
void Owner95::FUN_0095a060(const Transform95& a,const Transform95& b,const Axis95& pivot,const Axis95& axis1,const Axis95& axis2)
{
 Matrix95 basis;
 basis.row[0]=axis1;basis.row[0].Normalize();
 basis.row[1]=axis2;basis.row[1].Normalize();
 basis.row[2].Cross(basis.row[0],basis.row[1]);
 unk20.Rotate(a.rotation,basis);
 unk60.Rotate(b.rotation,basis);
 unk50.FUN_008d2970(a,pivot);
 unk90.FUN_008d2970(b,pivot);
 unkB0=unk60;
}
}   // namespace f3m_0095a060

// @f3 0x0094f420 (community match, verified in this file)
#include <new>
extern unsigned long DAT_010f3170;
extern float DAT_00f7ad9c;
namespace f3m_0094f420 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);


struct Allocator {
    void* FUN_008f6d30(unsigned int size, unsigned int tag);
};

struct Chunk {
    virtual void v0();
    virtual void release();
    long rc;
    unsigned int count;
    char* data;
};

struct __declspec(align(16)) Desc {
    unsigned char b24;
    bool b25;
    unsigned short w26;
    int d28;
    unsigned short w2c;
    unsigned short w2e;
    int d30;
    int d34;
    int d38;
    int d3c;
    int d40;
    float f44;
    float f48;
    float f4c;
    float f50;
    int d54;
    int d58;
    unsigned char b5c;
    unsigned char b5d;
};

struct Source {
    int unk00;
    Chunk* unk04;
    float unk08;
    int unk0c;
    int unk10;
};

struct Obj {
    unsigned short unk04;
    short unk06;
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
    float unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    Obj(float f, int n);
    static void* operator new(unsigned int size, int tag)
    {
        Allocator* al = (Allocator*)TlsGetValue(DAT_010f3170);
        Obj* p = (Obj*)al->FUN_008f6d30(size, tag);
        p->unk04 = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p, int tag) {}
    void FUN_009e3370(int* p);
    virtual void d(unsigned char del);
    virtual void ov1();
    virtual void ov2();
    virtual void ov3();
    virtual void ov4();
    virtual void ov5();
    virtual void ov6();
    virtual void ov7();
    virtual void ov8();
    virtual void add(Desc* dd);
};


struct Target {
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Chunk* unk14;
    virtual void tv0();
    virtual void tv1();
    virtual void tv2();
    virtual void tv3();
    virtual void tv4();
    virtual void tv5();
    virtual void tv6();
    virtual void tv7();
    virtual void tv8();
    virtual void tv9();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35(Obj* o);
    virtual void tw36();
    virtual void tw37();
    virtual void tw38();
    virtual void tw39();
    virtual void tw40();
    virtual void tw41();
    virtual void tw42();
    virtual void tw43();
    virtual void tw44();
    virtual void tw45();
    virtual void tw46();
    virtual void tw47(Source* s);
    void FUN_0094f420(Source* src);
};

void Target::FUN_0094f420(Source* src)
{
    if (src != 0) {
        Obj* o = new (0x27) Obj(DAT_00f7ad9c, 12);
        o->unk18 = 0xf;
        o->unkb0 = src->unk08;
        o->FUN_009e3370(&src->unk10);
        Chunk* c = src->unk04;
        for (unsigned int i = 0; i < c->count; i++) {
            Desc dd;
            dd.b25 = true;
            dd.w2e = 1;
            dd.f44 = dd.f48 = dd.f4c = dd.f50 = 0.0f;
            dd.w2c = 0;
            dd.w26 = 0;
            dd.d30 = 0;
            dd.b24 = 0;
            dd.d28 = 0;
            dd.b5d = 0;
            dd.d3c = 12;
            const int* e = (const int*)(c->data + i * 0x14);
            dd.d38 = e[1];
            dd.d40 = e[0];
            dd.d34 = e[2];
            dd.b5c = 1;
            dd.d58 = 6;
            dd.d54 = e[3];
            dd.w2e = 1;
            dd.d30 = e[4];
            dd.w2c = 1;
            dd.b25 = true;
            dd.w26 = 8;
            o->add(&dd);
        }
        Chunk* old = unk14;
        if (old != src->unk04) {
            if (old != 0) {
                if (InterlockedDecrement(&old->rc) == 0)
                    old->release();
            }
            Chunk* n = src->unk04;
            unk14 = n;
            if (n != 0)
                InterlockedIncrement(&n->rc);
        }
        tv35(o);
        if (o->unk04 != 0) {
            if (--o->unk06 == 0)
                o->d(1);
        }
        tw47(src);
    }
}
}   // namespace f3m_0094f420

// @f3 0x0094e3e0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern float FUN_00f7ad9c;
namespace f3m_0094e3e0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct QThreadMem {
    void* FUN_008f6d30(int size, int cls);
};

struct QRawVec {
    float x, y, z, w;
};

struct __declspec(align(16)) QVec {
    float x, y, z, w;
    QVec() {}
    void setZero4() { x = y = z = w = 0.0f; }
    QVec& operator=(const QVec& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
    QVec(const QRawVec& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
};

struct QRefObj {
    unsigned short memSize;
    short refCount;
    QRefObj() : refCount(1) {}
    virtual ~QRefObj();
    void* operator new(unsigned int size) {
        QThreadMem* m = (QThreadMem*)TlsGetValue(DAT_010f3170);
        QRefObj* o = (QRefObj*)m->FUN_008f6d30(size, 0x27);
        o->memSize = (unsigned short)size;
        return o;
    }
    void operator delete(void*, unsigned int);
    void removeReference() {
        if (memSize != 0) {
            if (--refCount == 0) delete this;
        }
    }
};

struct QShape : QRefObj {
    int userData;
    int type;
    QShape(int t) { userData = 0; type = t; }
};

struct QConvexShape : QShape {
    float radius;
    QConvexShape(int t, float r) : QShape(t) { radius = r; }
};

struct QTriShape : QConvexShape {
    unsigned short weldingInfo;
    unsigned char weldingType;
    unsigned char isExtruded;
    QVec a;
    QVec b;
    QVec c;
    QVec ext;
    __forceinline QTriShape(const QVec& v0, const QVec& v1, const QVec& v2, float r = FUN_00f7ad9c) : QConvexShape(4, r) {
        a = v0; b = v1; c = v2;
        weldingInfo = 0;
        weldingType = 6;
        ext.setZero4();
        isExtruded = 0;
    }
};

struct QTriData {
    int unk00;
    float radius;
    int unk08;
    int unk0C;
    QRawVec v0;
    QRawVec v1;
    QRawVec v2;
};

struct QWorld {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void AddShape(QTriShape* s);
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void AddData(QTriData* d);
    void FUN_0094e3e0(QTriData* d);
};

// pdb: bhkTriangleShape::Init | bhkTriangleShape.obj | fnv360_1110_retail, objopen_prop, low
// pdb params: arInfo
void QWorld::FUN_0094e3e0(QTriData* d) {
    if (d) {
        QTriShape* s = new QTriShape(d->v0, d->v1, d->v2);
        s->radius = d->radius;
        AddShape(s);
        s->removeReference();
        AddData(d);
    }
}
}   // namespace f3m_0094e3e0

// @f3 0x0094d0e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_0094d0e0 {

struct Block16 { int a, b, c, d; };
struct Vec4 { float x, y, z, w; };
struct Destination {
    Block16 head0, head1;
    Vec4 first, second;
};
struct Stream {
    int unk00;
    int position;
    int (__cdecl *read)(Stream *, void *, int, int, int);
};
struct FileContext {
    Block16 p00, p01, p02, p03, p04, p05, p06, p07, p08, p09;
    Block16 p10, p11, p12, p13, p14, p15, p16, p17, p18, p19;
    Block16 p20, p21, p22, p23, p24, p25, p26, p27, p28, p29;
    int unk1e0;
    char unk1e4;
    char endian;
    short unk1e6;
    Block16 p30, p31, p32, p33, p34, p35;
    int unk248;
    Stream *stream;
};
struct __declspec(align(16)) Record {
    int unk00;
    Destination *destination;
    int unk08, unk0c;
    Vec4 first, second;
};
struct Owner {
    int unk00;
    Destination *destination;
    void prepare(FileContext *, Record *);
    void FUN_0094d0e0(FileContext *, Record *);
};

void Owner::FUN_0094d0e0(FileContext *file, Record *record)
{
    Record local;
    local.first.x = local.first.y = local.first.z = local.first.w = 0.0f;
    local.second.x = local.second.y = local.second.z = local.second.w = 0.0f;
    local.unk0c = local.unk08 = 0;
    if (!record) {
        record = &local;
        prepare(file, record);
    }
    Destination *dest = destination;
    Vec4 *first = &record->first;
    Stream *stream = file->stream;
    stream->position += stream->read(stream, first, 16, 0, 0);
    Vec4 *second = &record->second;
    stream = file->stream;
    stream->position += stream->read(stream, second, 16, 0, 0);
    if (file->endian != 1) {
        volatile unsigned long *a = (volatile unsigned long *)first;
        volatile unsigned long *b = (volatile unsigned long *)second;
        a[0] = _byteswap_ulong(a[0]);
        a[1] = _byteswap_ulong(a[1]);
        a[2] = _byteswap_ulong(a[2]);
        a[3] = _byteswap_ulong(a[3]);
        b[0] = _byteswap_ulong(b[0]);
        b[1] = _byteswap_ulong(b[1]);
        b[2] = _byteswap_ulong(b[2]);
        b[3] = _byteswap_ulong(b[3]);
    }
    dest->first.x = first->x;
    dest->first.y = first->y;
    dest->first.z = first->z;
    dest->first.w = first->w;
    dest->second.x = second->x;
    dest->second.y = second->y;
    dest->second.z = second->z;
    dest->second.w = second->w;
}
}   // namespace f3m_0094d0e0

// @f3 0x009464c0 (community match, verified in this file)
namespace f3m_009464c0 {
namespace Append306{
struct __declspec(align(16)) FUN_009462c0{unsigned int unk00,unk04,unk08,unk0c;float first10,first14,first18,first1c,second20,second24,second28,second2c,value30,value34,value38;unsigned char first3c,second3d,unk3e,unk3f;FUN_009462c0();};
struct Array306{void*vtable;void**data;unsigned short capacity,size,unk0c,grow;void FUN_00555790(unsigned int);void FUN_005b3880(unsigned int,void*const&);};
extern void* DAT_01169160;void* __cdecl FUN_00847b50(void*);
struct Owner306{void FUN_008fba80(Array306*);void FUN_00945ea0(const FUN_009462c0&);void FUN_009464c0(Array306*);};
// pdb: bhkSpringAction::GetViewerStrings | bhkSpringAction.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apStrings
void Owner306::FUN_009464c0(Array306*array){FUN_008fba80(array);void*value=FUN_00847b50(DAT_01169160);unsigned int size=array->size;if(size>=array->capacity)array->FUN_00555790(size+array->grow);array->FUN_005b3880(size,value);FUN_009462c0 defaults;FUN_00945ea0(defaults);}
}
}   // namespace f3m_009464c0

// @f3 0x0094ec70 (community match, verified in this file)
extern const char* g_bhkPlaneShapeRTTIName;
namespace f3m_0094ec70 {

class NiViewerStringsArray;

class NiPoint3
{
public:
    float x;
    float y;
    float z;
    char* GetViewerString(const char* pcPrefix);
};

struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;
};

struct hkpPlaneShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_plane;
};

class NiViewerStringsArray : public NiTArray<char*, void*>
{
public:
    void SetSize(unsigned int uiNewSize);
    void SetAt(unsigned int uiIndex, char* const & element);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const & element)
    {
        if (uiIndex >= m_usMaxSize)
        {
            SetSize(uiIndex + m_usGrowBy);
        }
        SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int Add(char* const & element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

extern char* NiGetViewerString(const char* pcStr);
extern char* NiGetViewerString(const char* pcStr, float fVal);

class bhkHeightFieldShape
{
public:
    virtual void GetViewerStrings(NiViewerStringsArray* pStrings);
};

class bhkPlaneShape : public bhkHeightFieldShape
{
public:
    int unk04;
    hkpPlaneShape* m_pShape;

    virtual void FUN_0094ec70(NiViewerStringsArray* pStrings);
};

// pdb: bhkPlaneShape::GetViewerStrings | bhkPlaneShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void bhkPlaneShape::FUN_0094ec70(NiViewerStringsArray* pStrings)
{
    bhkHeightFieldShape::GetViewerStrings(pStrings);
    pStrings->Add(NiGetViewerString(g_bhkPlaneShapeRTTIName));

    hkVector4 plane;
    if (this)
    {
        hkpPlaneShape* pShape = m_pShape;
        if (pShape)
        {
            plane.x = pShape->m_plane.x;
            plane.y = pShape->m_plane.y;
            plane.z = pShape->m_plane.z;
            plane.w = pShape->m_plane.w;
        }
    }

    NiPoint3 kNormal;
    kNormal.x = plane.x * 6.999040126800537;
    kNormal.y = plane.y * 6.999040126800537;
    kNormal.z = plane.z * 6.999040126800537;
    pStrings->Add(kNormal.GetViewerString("Normal"));

    pStrings->Add(NiGetViewerString("Constant", plane.w));
}
}   // namespace f3m_0094ec70

// @f3 0x00950700 (community match, verified in this file)
namespace f3m_00950700 {
struct Vec0700 {__declspec(align(16)) float x;float y;float z;float w;
Vec0700(const Vec0700& v){x=v.x;y=v.y;z=v.z;w=v.w;}};
struct Source0700 {int unk00;int unk04;int unk08;int unk0c;Vec0700 second;Vec0700 first;float value;};
struct Owner0700;struct Table0700 { void* unk00; void* unk04; void* unk08; void* unk0c; void* unk10; void* unk14; void* unk18; void* unk1c; void* unk20; void* unk24; void* unk28; void* unk2c; void* unk30; void* unk34; void* unk38; void* unk3c; void* unk40; void* unk44; void* unk48; void* unk4c; void* unk50; void* unk54; void* unk58; void* unk5c; void* unk60; void* unk64; void* unk68; void* unk6c; void* unk70; void* unk74; void* unk78; void* unk7c; void* unk80; void* unk84; void* unk88; void* unk8c; void* unk90; void* unk94; void* unk98; void* unk9c; void* unka0; void* unka4; void* unka8; void* unkac; void* unkb0; void* unkb4; void* unkb8; void (__thiscall* base)(Owner0700*,Source0700*);};
struct Owner0700 {Table0700* table;void FUN_009504f0(Vec0700*,Vec0700*,float);void FUN_00950700(Source0700*);};
// pdb: bhkCylinderShape::Init | bhkCylinderShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInfo
void Owner0700::FUN_00950700(Source0700* source){if(source){Vec0700 first(source->first);Vec0700 second(source->second);FUN_009504f0(&second,&first,source->value);}table->base(this,source);}
}   // namespace f3m_00950700

// @f3 0x00947880 (community match, verified in this file)
namespace f3m_00947880 {
// pdb: bhkAngularDashpotAction::GetViewerStrings | bhkAngularDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apStrings
namespace params880 {struct Color {float r;float g;float b;float a;Color& operator=(const Color& v){r=v.r;g=v.g;b=v.b;a=v.a;return *this;}};extern Color DAT_00f7b120;extern float DAT_00dbe8fc;extern float DAT_00db75c8;extern int DAT_01169184;int __cdecl FUN_00847b50(int);struct Array {int unk00;int unk04;unsigned short capacity;unsigned short size;unsigned short unk0c;unsigned short grow;void FUN_00555790(unsigned);void FUN_005b3880(unsigned,int*);};struct Params {__declspec(align(16)) int first;int second;int third;int unk0c;Color color;float f20;float f24;};struct Owner {void FUN_008fba80(Array*);void FUN_00947390(Params*);void FUN_00947880(Array*);};void Owner::FUN_00947880(Array* arr){FUN_008fba80(arr);int value=FUN_00847b50(DAT_01169184);unsigned index=arr->size;if(index>=arr->capacity)arr->FUN_00555790(index+arr->grow);arr->FUN_005b3880(index,&value);Params p;p.first=0;p.second=0;p.third=0;p.color=DAT_00f7b120;p.f20=DAT_00dbe8fc;p.f24=DAT_00db75c8;FUN_00947390(&p);}}
}   // namespace f3m_00947880

// @f3 0x00947240 (community match, verified in this file)
namespace f3m_00947240 {
struct F47240Array
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, int* value);
};

struct __declspec(align(16)) F47240Vec
{
    float x, y, z, w;
};

struct F47240Desc
{
    int unk00;
    int unk04;
    int unk08;
    F47240Vec unk10;
    F47240Vec unk20;
    float unk30;
    float unk34;
};

extern int DAT_01169178;
extern const float DAT_00dbe8fc;
extern const float DAT_00db75c8;
int __cdecl FUN_00847b50(int key);

struct FUN_00947240_Owner
{
    void FUN_008fba80(F47240Array* array);
    void FUN_00946c30(F47240Desc* desc);
    void FUN_00947240(F47240Array* array);
};

// pdb: bhkDashpotAction::GetViewerStrings | bhkDashpotAction.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apStrings
void FUN_00947240_Owner::FUN_00947240(F47240Array* array)
{
    FUN_008fba80(array);
    int value = FUN_00847b50(DAT_01169178);
    unsigned int count = array->unk0A;
    if (count >= array->unk08)
        array->FUN_00555790(array->unk0E + count);
    array->FUN_005b3880(count, &value);
    F47240Desc desc;
    desc.unk00 = 0;
    desc.unk04 = 0;
    desc.unk08 = 0;
    desc.unk10.x = 0.0f;
    desc.unk10.y = 0.0f;
    desc.unk10.z = 0.0f;
    desc.unk10.w = 0.0f;
    desc.unk20.x = 0.0f;
    desc.unk20.y = 0.0f;
    desc.unk20.z = 0.0f;
    desc.unk20.w = 0.0f;
    desc.unk30 = DAT_00dbe8fc;
    desc.unk34 = DAT_00db75c8;
    FUN_00946c30(&desc);
}
}   // namespace f3m_00947240

// @f3 0x0095d250 (community match, verified in this file)
namespace f3m_0095d250 {
namespace slot295d250 {
struct Quaternion {
 union { struct {__declspec(align(16)) float x;float y,z,w;};float components[4];};
 Quaternion(){}
 Quaternion(const Quaternion& other):x(other.x),y(other.y),z(other.z),w(other.w){}
 Quaternion& operator=(const Quaternion& value){for(int i=0;i<4;++i)components[i]=value.components[i];return *this;}
 void FUN_0095d250(const Quaternion& other);
};
void Quaternion::FUN_0095d250(const Quaternion& other)
{
 Quaternion result;
 result.x=y*other.z-other.y*z;
 result.y=z*other.x-x*other.z;
 result.z=x*other.y-other.x*y;
 float scalar=w;
 result.x+=scalar*other.x;
 result.y+=scalar*other.y;
 result.z+=scalar*other.z;
 result.w=scalar*other.w+0.0;
 scalar=other.w;
 result.x+=scalar*x;
 result.y+=scalar*y;
 result.z+=scalar*z;
 result.w+=scalar*w;
 float dot=other.x*x+other.y*y+z*other.z;
 scalar=other.w*w-dot;
 *this=result;
 w=scalar;
}
}

}   // namespace f3m_0095d250

// @f3 0x00951d50 (community match, verified in this file)
namespace f3m_00951d50 {
void* __cdecl FUN_0089eb90(unsigned int);
void __cdecl FUN_0089ec10(void*,unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Vec951 { float x,y,z; };
struct Matrix951 { float elements[9]; };
struct NiTransform951 { Matrix951 rotation; Vec951 translation; float scale; };
struct FUN_008fda60 { __declspec(align(16)) float components[16]; FUN_008fda60(const FUN_008fda60*); };
extern FUN_008fda60 DAT_010f3370;
void __cdecl FUN_0056ac90(NiTransform951*,const FUN_008fda60*);
extern const char* DAT_00e207a8;
extern const char DAT_00e32604[];
const char* __cdecl FUN_008242a0(const char*);
struct FixedString951 { const char* text; FixedString951(const char* s):text(FUN_008242a0(s)){} ~FixedString951(){if(text!=DAT_00e207a8)InterlockedDecrement((volatile long*)(text-8));} };
struct FUN_0082ea60 {
    void** table;
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
    Matrix951 rotation;
    Vec951 position;
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
    FUN_0082ea60(int);
    static void* operator new(unsigned int n){return FUN_0089eb90(n);}
    static void operator delete(void* p,unsigned int n){FUN_0089ec10(p,n);}
    void FUN_008245d0(const FixedString951&);
    void SetPosition(Vec951 value){position=value;}
};
struct NodeOwner951 {
    void** table;
    void Attach(FUN_0082ea60* node,bool update){typedef void(__thiscall*F)(NodeOwner951*,FUN_0082ea60*,bool);((F)table[0xdc/4])(this,node,update);}
    void Notify(FUN_0082ea60* node){typedef void(__thiscall*F)(NodeOwner951*,FUN_0082ea60*);((F)table[0xd0/4])(this,node);}
};
struct Link951 {int unk00;int unk04;NodeOwner951* owner;};
struct Body951 {int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;Link951* link;int unk1C;FUN_008fda60 transform;};
struct Wrapper951 {
    int unk00;int unk04;Body951* body;
    void FUN_00951d50(NodeOwner951*);
};
// pdb: bhkConvexTransformShape::BuildDisplayGeometry | bhkConvexTransformShape.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: apNode, arDefColor
void Wrapper951::FUN_00951d50(NodeOwner951* parent)
{
    const FUN_008fda60* source;
    if(this && body) source=&body->transform; else source=&DAT_010f3370;
    FUN_008fda60 transform(source);
    NiTransform951 converted;
    FUN_0056ac90(&converted,&transform);
    converted.translation.x = transform.components[12] * (double)6.999040126800537109375f;
    converted.translation.y = transform.components[13] * (double)6.999040126800537109375f;
    converted.translation.z = transform.components[14] * (double)6.999040126800537109375f;
    FUN_0082ea60* node = new FUN_0082ea60(0);
    {
        FixedString951 name(DAT_00e32604);
        node->FUN_008245d0(name);
    }
    parent->Attach(node,true);
    node->SetPosition(converted.translation);
    node->rotation=converted.rotation;
    if(this && body && body->link && body->link->owner) body->link->owner->Notify(node);
}
}   // namespace f3m_00951d50

// @f3 0x009505b0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern float DAT_010c72bc;
namespace f3m_009505b0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct hkThreadMemory_9505b0 {
    static hkThreadMemory_9505b0& getInstance() {
        return *static_cast<hkThreadMemory_9505b0*>(TlsGetValue(DAT_010f3170));
    }
    void* FUN_008f6d30(int nbytes, int cl);
};

struct hkGeometry_9505b0;

__declspec(align(16)) struct hkVector4_9505b0 {
    float x;
    float y;
    float z;
    float w;
    hkVector4_9505b0() {}
    void set(float a, float b, float c, float d) {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

__declspec(align(16)) class bhkVector4_9505b0 {
public:
    float fX;
    float fY;
    float fZ;
    float fW;
    bhkVector4_9505b0() {
        setZero4();
    }
    void setZero4() {
        fX = 0.0f;
        fY = 0.0f;
        fZ = 0.0f;
        fW = 0.0f;
    }
    void set(float a, float b, float c, float d) {
        fX = a;
        fY = b;
        fZ = c;
        fW = d;
    }
    hkVector4_9505b0& ToHK(hkVector4_9505b0& out) const {
        out.set(fX, fY, fZ, fW);
        return out;
    }
};

struct hkShapeCinfo_9505b0 {
    int m_userData;
    hkShapeCinfo_9505b0() {
        m_userData = 0;
    }
};

struct hkConvexShapeCinfo_9505b0 : public hkShapeCinfo_9505b0 {
    float m_radius;
    hkConvexShapeCinfo_9505b0() {
        m_radius = DAT_010c72bc;
    }
};

struct hkCylinderShapeCinfo_9505b0 : public hkConvexShapeCinfo_9505b0 {
    bhkVector4_9505b0 m_vertexA;
    bhkVector4_9505b0 m_vertexB;
    float fCylinderRadius;
    hkCylinderShapeCinfo_9505b0() {
        fCylinderRadius = 0.0f;
        m_vertexA.set(0.0f, 0.0f, 0.0f, 0.0f);
        m_vertexB.set(1.0f, 0.0f, 0.0f, 0.0f);
    }
};

class hkBaseObject_9505b0 {
public:
    virtual ~hkBaseObject_9505b0();
};

class hkReferencedObject_9505b0 : public hkBaseObject_9505b0 {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    virtual void calcContentStatistics();
};

class hkDisplayGeometry_9505b0 : public hkReferencedObject_9505b0 {
public:
    hkGeometry_9505b0* m_geometry;
    hkVector4_9505b0 m_col0;
    hkVector4_9505b0 m_col1;
    hkVector4_9505b0 m_col2;
    hkVector4_9505b0 m_col3;
    int m_type;

    static void* operator new(size_t nbytes) {
        hkReferencedObject_9505b0* b = static_cast<hkReferencedObject_9505b0*>(
            hkThreadMemory_9505b0::getInstance().FUN_008f6d30(static_cast<int>(nbytes), 8)
        );
        b->m_memSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);

    virtual void vfunc2();
    virtual void vfunc3();
    virtual void buildGeometry();

    hkGeometry_9505b0* getGeometry() {
        return m_geometry;
    }
};

class FUN_009e6e10 : public hkDisplayGeometry_9505b0 {
public:
    hkVector4_9505b0 m_top;
    hkVector4_9505b0 m_bottom;
    float m_radius;
    int m_numSides;
    int m_numHeightSegments;

    FUN_009e6e10(const hkVector4_9505b0& top, const hkVector4_9505b0& bottom, float radius, int numSides, int numHeightSegments);
};

class bhkCylinderShape_9505b0 {
public:
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
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void FUN_009505b0(NiNode* pNode);
    virtual void v52();
    virtual void BuildDisplayFromhkGeometry(NiNode* pNode, hkGeometry_9505b0* pGeom, const char* pName);

    void bhkCylinderShape_CopyCinfo(hkCylinderShapeCinfo_9505b0& cinfo);
};

// pdb: bhkCylinderShape::BuildDisplayGeometry | bhkCylinderShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apNode, arDefColor
void bhkCylinderShape_9505b0::FUN_009505b0(NiNode* pNode) {
    hkCylinderShapeCinfo_9505b0 cinfo;
    bhkCylinderShape_CopyCinfo(cinfo);
    hkVector4_9505b0 vA;
    hkVector4_9505b0 vB;
    FUN_009e6e10* disp = new FUN_009e6e10(
        cinfo.m_vertexA.ToHK(vA),
        cinfo.m_vertexB.ToHK(vB),
        cinfo.fCylinderRadius,
        9,
        1
    );
    disp->buildGeometry();
    hkGeometry_9505b0* geom = disp->getGeometry();
    if (geom) {
        BuildDisplayFromhkGeometry(pNode, geom, "bhkCylinderShape");
    }
}
}   // namespace f3m_009505b0

// @f3 0x0094c500 (community match, verified in this file)
extern const void* DAT_00e7af1c[];
namespace f3m_0094c500 {

namespace NativeCinfo94c500 {
class CinfoBase {
public:
    const void** m_vtbl;
};

class CinfoRef {
public:
    void* m_pRef;
    int m_refCount;
};

class CinfoConf {
public:
    int unk0C;
    int unk10;
};

class Cinfo : public CinfoBase, public CinfoRef, public CinfoConf {
public:
    static void* operator new(unsigned int size) throw()
    {
        return DAT_01090a78.FUN_0086b930(size);
    }
    Cinfo();
};

Cinfo::Cinfo()
{
    m_pRef = 0;
    unk0C = 0;
    unk10 = 0;
    m_refCount = 1;
    m_vtbl = DAT_00e7af1c;
}

class Owner {
public:
    int unk00;
    int unk04;
    void* m_pSource;
    CinfoRef* m_pChild;
    void FUN_008fc420(Cinfo* child);
    CinfoRef* FUN_0094c500(bool* created);
};

// pdb: bhkHingeLimitsConstraint::CreateClone | bhkHingeLimitsConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: arCloneData
CinfoRef* Owner::FUN_0094c500(bool* created)
{
    if (m_pChild == 0) {
        Cinfo* child = new Cinfo();
        m_pChild = child;
        if (m_pSource != 0)
            FUN_008fc420(static_cast<Cinfo*>(m_pChild));
        *created = true;
        return m_pChild;
    }
    *created = false;
    return m_pChild;
}
}
}   // namespace f3m_0094c500

// @f3 0x0094f250 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
namespace Task2208 {
typedef CRITICAL_SECTION Lock;
extern Lock DAT_010f3194;
extern int DAT_010f3174,DAT_011692b0,DAT_01169228,DAT_00dcdbac,DAT_00e3348c,DAT_00e7b5fc;
void* FUN_0089eb90(unsigned int);
struct Obj {
 void* table;unsigned int refs,value,data,extra,last;
 void* FUN_008f7c10();
 static void* operator new(unsigned int n){return FUN_0089eb90(n);}
 static void operator delete(void*);
 Obj(){
  FUN_008f7c10();
  table=&DAT_00dcdbac;
  int one=1;
  data=0;
  extra=0;
  _ReadWriteBarrier();
  DAT_010f3174+=one;
  table=&DAT_00e3348c;
  DAT_011692b0+=one;
  table=&DAT_00e7b5fc;
  last=0;
  DAT_01169228+=one;
 }
};
struct Owner {
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
 virtual void Copy(Obj*,int);
 Obj* FUN_0094f250(int);
};
Obj* Owner::FUN_0094f250(int arg){
 EnterCriticalSection(&DAT_010f3194);
 Obj* obj=new Obj();
 Copy(obj,arg);
 LeaveCriticalSection(&DAT_010f3194);
 return obj;
}
}

// @f3 0x00946c30 (community match, verified in this file)
namespace f3m_00946c30 {
namespace NativeConstraintCopy946c30 {
struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
    __forceinline void Read(const Vector4& other) {
        x=other.x; y=other.y; z=other.z; w=other.w;
    }
    __forceinline void Write(volatile Vector4& other) const {
        other.x=x; other.y=y; other.z=z; other.w=w;
    }
    __forceinline void Clear() { x=0.0f; y=0.0f; z=0.0f; w=0.0f; }
};
struct Data {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    Vector4 first, second;
    float firstLimit, secondLimit;
};
struct Output {
    unsigned int unk00, unk04, unk08, unk0c;
    Vector4 value;
    unsigned int unk20, unk24, unk28, unk2c;
    float firstLimit, secondLimit;
};
struct Owner {
    unsigned int unk00, unk04;
    Data* data;
    void FUN_008fb630(Output*);
    void FUN_00946c30(Output*);
};
// pdb: bhkDashpotAction::CopyCinfo | bhkDashpotAction.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: arInfo
void Owner::FUN_00946c30(Output* output)
{
    FUN_008fb630(output);
    Vector4 first, second;
    first.Clear();
    second.Clear();
    if (this) {
        const Data* source = data;
        if (source) {
            first.Read(source->first);
            second.Read(source->second);
        }
    }
    first.Write(output->value);
    second.Write(output->value);
    float firstLimit = this && data ? data->firstLimit : 0.0f;
    output->firstLimit = firstLimit;
    float secondLimit = this && data ? data->secondLimit : 0.0f;
    output->secondLimit = secondLimit;
}
}
}   // namespace f3m_00946c30

// @f3 0x00956120 (community match, verified in this file)
namespace f3m_00956120 {

void __cdecl FUN_00901e90(void* arr, int capacity, int stride);
namespace f3m_00956120 {
template<class T, int S> struct Arr {
    T* data;
    int size;
    int capacityAndFlags;
    Arr() : data(0), size(0), capacityAndFlags(0x80000000) {}
    __forceinline void reserve(int n)
    {
        int cap = capacityAndFlags & 0x3fffffff;
        if (cap < n) {
            int c2 = cap * 2;
            FUN_00901e90(this, n < c2 ? c2 : n, S);
        }
    }
    void setSize(int n) { reserve(n); size = n; }
    __forceinline void setSize(int n, T fill)
    {
        int old = size;
        if (n > old) {
            reserve(n);
            for (int i = old; i < n; i++) data[i] = fill;
        }
        size = n;
    }
};
struct E30 { char b[0x30]; };
struct Src { char pad[0x10]; int n10; char pad2[0xc]; int n20; };
struct Obj {
    Src* src;
    Arr<E30, 0x30> a04;
    Arr<E30, 0x30> a10;
    Arr<int, 4> a1c;
    int unk28;
    Arr<float, 4> a2c;
    Obj(int mode, Src* s, int arg);
    void FUN_00954ef0(int);
    void FUN_00954f40(int);
};
Obj::Obj(int mode, Src* s, int arg) : src(s)
{
    int n = src->n10;
    a10.setSize(n);
    a04.setSize(n);
    a1c.setSize(n);
    if (mode == 1) FUN_00954ef0(arg);
    else FUN_00954f40(arg);
    a2c.setSize(src->n20, 0.0f);
}
}
}   // namespace f3m_00956120

// @f3 0x00959480 (community match, verified in this file)
namespace f3m_959480 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long) throw();
}
struct W2TM959 {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc(); virtual void v10();
    virtual void* AllocStackSlow(int n) throw();
    virtual void FreeStackSlow(void* p) throw();
    int pad04[7];
    char* m_cur;
    int pad24;
    char* m_base;
    char* m_end;
    void FUN_008f6d90(void* p, int size, int cls) throw();
    __forceinline static W2TM959* Get() { return (W2TM959*)f3m_959480::DAT_00d9b080(f3m_959480::DAT_010f3170); }
    __forceinline void* AllocStack(int n) {
        int a = (n + 0x10) & ~0xf;
        char* c = m_cur;
        char* nx = c + a;
        if (nx <= m_end) { m_cur = nx; return c; }
        return AllocStackSlow(a);
    }
    __forceinline void FreeStack(void* p) {
        char* b = m_base;
        m_cur = (char*)p;
        if (p == b) FreeStackSlow(p);
    }
};
__forceinline void W2FreeStack(void* p) { W2TM959::Get()->FreeStack(p); }
__forceinline void W2Free(void* p, int n, int cls) { W2TM959::Get()->FUN_008f6d90(p, n, cls); }
namespace f3m_959480 {
void __cdecl FUN_00901e90(void* arr, int capacity, int stride) throw();
void __cdecl FUN_00901f10(void* arr, int stride) throw();
template<class T> struct Arr {
    T* m_data;
    int m_size;
    int m_cap;
    __forceinline Arr() : m_data(0), m_size(0), m_cap(0x80000000) {}
    __forceinline ~Arr() {
        if ((m_cap & 0x80000000) == 0)
            W2TM959::Get()->FUN_008f6d90(m_data, (m_cap & 0x3fffffff) * sizeof(T), 0x17);
    }
    __forceinline void SetSize(int n, const T& fill) {
        if (n > m_size) {
            int cap = m_cap & 0x3fffffff;
            if (cap < n) {
                int c2 = cap * 2;
                FUN_00901e90(this, n < c2 ? c2 : n, sizeof(T));
            }
            for (int i = m_size; i < n; i++)
                m_data[i] = fill;
        }
        m_size = n;
    }
    __forceinline void PushBack(const T& v) {
        if (m_size == (m_cap & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = v;
        m_size++;
    }
    __forceinline T& operator[](int i) { return m_data[i]; }
};
template<class T> struct LocalArr {
    T* m_data;
    int m_size;
    int m_cap;
    T* m_local;
    __forceinline LocalArr(int n) : m_data(0), m_size(0), m_cap(0x80000000) {
        m_data = (T*)W2TM959::Get()->AllocStack(n * sizeof(T));
        m_local = m_data;
        m_cap = n | 0x80000000;
    }
    __forceinline ~LocalArr() {
        void* (__stdcall* f)(unsigned long) = DAT_00d9b080;
        ((W2TM959*)f(DAT_010f3170))->FreeStack(m_local);
        if ((m_cap & 0x80000000) == 0) {
            int n = (m_cap & 0x3fffffff) * sizeof(T);
            W2TM959* tm = (W2TM959*)f(DAT_010f3170);
            tm->FUN_008f6d90(m_data, n, 0x17);
        }
    }
    __forceinline void SetSize(int n, const T& fill) {
        if (n > m_size) {
            int cap = m_cap & 0x3fffffff;
            int sz = m_size;
            if (cap < n) {
                int c2 = cap * 2;
                FUN_00901e90(this, n < c2 ? c2 : n, sizeof(T));
            }
            for (int i = sz; i < n; i++)
                m_data[i] = fill;
        }
        m_size = n;
    }
    __forceinline T& operator[](int i) { return m_data[i]; }
};
struct Obj {
    int unk00;
    Arr<short> words;
    int size;
};
}
// pdb: hkaSkeletonUtils::getLeaves | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun, medium
// pdb params: skeleton, leavesOut
void __cdecl FUN_00959480(f3m_959480::Obj* obj, f3m_959480::Arr<short>* out)
{
    f3m_959480::LocalArr<char> used(obj->size);
    used.SetSize(obj->size, 0);
    for (int i = 0; i < obj->words.m_size; i++) {
        if (obj->words.m_data[i] != -1)
            used[obj->words.m_data[i]] = 1;
    }
    for (short i = 0; i < obj->size; i++) {
        if (!used[i])
            out->PushBack(i);
    }
}

// @f3 0x00950af0 (community match, verified in this file)
namespace f3m_00950af0 {
struct ScaleVec4 {
    float x, y, z, w;
    ScaleVec4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
};

struct ScaleArray {
    ScaleVec4* m_pData;
    int m_uiSize;
    int m_uiCapacity;
};

struct ScaleResult {
    int unk00;
    float unk04;
    ScaleArray m_vertices;
    ScaleArray m_planes;
};

__forceinline void ScaleVertices(float s, ScaleArray& verts)
{
    for (int i = verts.m_uiSize; i != 0; ) {
        --i;
        verts.m_pData[i] *= s;
    }
}

__forceinline void ScalePlanes(float s, ScaleArray& planes)
{
    for (int i = planes.m_uiSize; i != 0; ) {
        --i;
        planes.m_pData[i].w *= s;
    }
}

struct Result950390;

class FUN_00c84df0_cls {
public:
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
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0();
    virtual Result950390* vB4(char* out);
    int unk04, unk08, unk0C;
    float m_f10;
    void FUN_00950390(FUN_00c84df0_cls* apArg1, FUN_00c84df0_cls* apArg2);
    void FUN_00950af0(FUN_00c84df0_cls* apArg1, FUN_00c84df0_cls* apArg2);
    void bhkShape_CopyMembers(FUN_00c84df0_cls* apArg1, FUN_00c84df0_cls* apArg2);
};

// pdb: bhkConvexVerticesShape::CopyMembers | bhkConvexVerticesShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apDest, arCloneData
void FUN_00c84df0_cls::FUN_00950af0(FUN_00c84df0_cls* apArg1, FUN_00c84df0_cls* apArg2)
{
    char local;
    // vB4 is typed for the sibling FUN_00950390; this object returns a vertex and plane set
    ScaleResult* result = (ScaleResult*)vB4(&local);
    if (result) {
        float scale = apArg2->m_f10;
        if (scale != 1.0f) {
            ScaleVertices(scale, result->m_vertices);
            ScalePlanes(scale, result->m_planes);
        }
    }
    bhkShape_CopyMembers(apArg1, apArg2);
}
}   // namespace f3m_00950af0

// @f3 0x00952ae0 (community match, verified in this file)
namespace f3m_00952ae0 {
extern "C" void* (__stdcall *DAT_00d9b080)(unsigned long);
namespace task2998 {
struct HkMemory{void FUN_008f6d90(void*,int,int);};extern unsigned long DAT_010f3170;
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
        if ((m_iCapacityState & 0x80000000) == 0) {
            HkMemory* mem=(HkMemory*)DAT_00d9b080(DAT_010f3170);
            mem->FUN_008f6d90(m_data,(m_iCapacityState & 0x3fffffff)*sizeof(T),0x17);
        }
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
        T* d = a.m_data;
        a.m_data = m_data;
        m_data = d;
        int count = a.m_iElementCount;
        a.m_iElementCount = m_iElementCount;
        m_iElementCount = count;
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

template <class T>
inline void SaveBinaryValue(NiBinaryStreamStub* stream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    stream->BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

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

void FUN_009793e0(SavedData* data, void* source, hkArrayStub<LinkedObjStub*>* out);

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
    void bhkConvexShape_SaveBinary(SaveStreamFields* stream);
    void FUN_00952ae0(SaveStreamFields* stream);
};

// pdb: bhkConvexListShape::SaveBinary | bhkConvexListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arStream
void bhkSaveOwner::FUN_00952ae0(SaveStreamFields* stream)
{
    bool bOut;
    SavedData* data = GetData(&bOut);
    hkArrayStub<LinkedObjStub*> arr;
    if(data) {
    arr.swap(data->m_ppData);
    if (stream->m_bUnk1E4 != 1) {
        void* source = GetSource();
        FUN_009793e0(data, source, &data->m_ppData);
    }
    }
    int count = arr.m_iElementCount;
    SaveBinaryValue(stream->m_pOstr, count);
    for (int i = 0; i < GetCount(); i++) {
        LinkedObjStub* obj = arr.m_data[i];
        stream->SaveLinkID(obj ? obj->m_pLinked : 0);
    }
    bhkConvexShape_SaveBinary(stream);
    SaveBinaryValue(stream->m_pOstr, data->m_cUnk08);
    SaveBinaryValue(stream->m_pOstr, data->m_iUnk0C);
}

}
}   // namespace f3m_00952ae0

// @f3 0x009406e0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009406e0 {
namespace f3m_009406e0 {
struct Allocator {
    void FUN_008f6d90(void* data,int bytes,int category) throw();
};
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
const char* __cdecl FUN_0093e470() throw();
struct UpdateDescriptor;
struct TypeRegistry;
void __cdecl FUN_00940060(void* objects,void* tracker,const UpdateDescriptor*,const TypeRegistry*) throw();
struct Updater {
    const char* fromVersion;
    const char* toVersion;
    const UpdateDescriptor* description;
    void (__cdecl *callback)(void* objects,void* tracker);
};
struct Path {
    const Updater** data;
    int size,capacityAndFlags;
    Path() throw():data(0),size(0),capacityAndFlags(0x80000000) {}
    void Release() {
        if((capacityAndFlags&0x80000000u)==0) {
            int capacity=capacityAndFlags&0x3fffffff;
            Allocator* allocator=(Allocator*)DAT_00d9b080(DAT_010f3170);
            allocator->FUN_008f6d90(data,capacity*sizeof(*data),0x17);
        }
    }
    const Updater*& operator[](int index) { return data[index]; }
};
struct VersionRegistry {
    int FUN_009b1490(const char* from,const char* to,Path* path) throw();
    const TypeRegistry* FUN_009b20b0(const char* version) throw();
};
int __cdecl FUN_009406e0(void* objects,void* tracker,VersionRegistry* registry,const char* from,const char* to)
{
    if(!to) to=FUN_0093e470();
    Path path;
    if(registry->FUN_009b1490(from,to,&path)==0) {
        for(int i=0;i<path.size;++i) {
            if(path[i]->callback) path[i]->callback(objects,tracker);
            else {
                const Updater*& entry=path[i];
                const TypeRegistry* types=registry->FUN_009b20b0(entry->toVersion);
                FUN_00940060(objects,tracker,entry->description,types);
            }
        }
        path.Release();
        return 0;
    }
    path.Release();
    return 1;
}
}
}   // namespace f3m_009406e0

// @f3 0x0094e0a0 (community match, verified in this file)
namespace f3m_0094e0a0 {
struct ScaleData_94e0a0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m10;
    float m14;
    float m18;
    float m1c;
    float m20;
    float m24;
    float m28;
    float m2c;
    float m30;
    float m34;
    float m38;
    float m3c;
};

struct ScaleInput_94e0a0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float scale;
};

struct ScaleOwner_94e0a0 {
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
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();

    virtual ScaleData_94e0a0* get(bool* flag);

    void FUN_008f7580(int arg, ScaleInput_94e0a0* input);
    void FUN_0094e0a0(int arg, ScaleInput_94e0a0* input);
};

void ScaleOwner_94e0a0::FUN_0094e0a0(int arg, ScaleInput_94e0a0* input)
{
    bool flag;
    ScaleData_94e0a0* data = get(&flag);

    if (data)
    {
        float n = input->scale;
        if (n != 1.0f)
        {
            data->m10 *= n;
            data->m14 *= n;
            data->m18 *= n;
            data->m1c = (n * data->m1c) * 1;
            data->m20 = (n * data->m20) * 1;
            data->m24 *= n;
            data->m28 *= n;
            data->m2c *= n;
            data->m30 *= n;
            data->m34 *= n;
            data->m38 *= n;
            data->m3c *= n;
        }
    }

    FUN_008f7580(arg, input);
}
}   // namespace f3m_0094e0a0

// @f3 0x00951330 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00951330 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace f3m_00951330 {

struct MemCtx { void FUN_008f6d90(void* p, int size, int tag); };
void __cdecl FUN_00901e90(void* arr, int capacity, int stride);

struct Vec4 {
    float x, y, z, w;
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Tri { int a, b, c; };

template <class T> struct HkArray {
    T* data;
    int size;
    int capFlags;
    HkArray() : data(0), size(0), capFlags(0x80000000) {}
    ~HkArray() {
        if ((capFlags & 0x80000000) == 0) {
            int cap = capFlags & 0x3fffffff;
            MemCtx* ctx = (MemCtx*)TlsGetValue(DAT_010f3170);
            ctx->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
    int GetCapacity() const { return capFlags & 0x3fffffff; }
    void SetSize(int n) {
        int cap = GetCapacity();
        if (cap < n) {
            int c2 = cap * 2;
            FUN_00901e90(this, n < c2 ? c2 : n, sizeof(T));
        }
        size = n;
    }
    T& operator[](int i) { return data[i]; }
};

struct Geometry {
    HkArray<Vec4> vertices;
    HkArray<Tri> triangles;
    ~Geometry();
};

struct StridedVerts {
    Vec4* data;
    int count;
    int stride;
};

void __cdecl FUN_009ec800(StridedVerts* in, Geometry* out, int flag);
void __cdecl FUN_00e325ec();

struct Shape {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20();
    virtual int GetNumVertices();
    virtual Vec4* GetVertices(Vec4* buf);
};


}

using namespace f3m_00951330;

struct ObjVirt {
    virtual void p00(); virtual void p04(); virtual void p08(); virtual void p0c();
    virtual void p10(); virtual void p14(); virtual void p18(); virtual void p1c();
    virtual void p20(); virtual void p24(); virtual void p28(); virtual void p2c();
    virtual void p30(); virtual void p34(); virtual void p38(); virtual void p3c();
    virtual void p40(); virtual void p44(); virtual void p48(); virtual void p4c();
    virtual void p50(); virtual void p54(); virtual void p58(); virtual void p5c();
    virtual void p60(); virtual void p64(); virtual void p68(); virtual void p6c();
    virtual void p70(); virtual void p74(); virtual void p78(); virtual void p7c();
    virtual void p80(); virtual void p84(); virtual void p88(); virtual void p8c();
    virtual void p90(); virtual void p94(); virtual void p98(); virtual void p9c();
    virtual void pa0(); virtual void pa4(); virtual void pa8(); virtual void pac();
    virtual void pb0(); virtual void pb4(); virtual void pb8(); virtual void pbc();
    virtual void pc0(); virtual void pc4(); virtual void pc8(); virtual void pcc();
    virtual void pd0();
    virtual void Build(int arg, Geometry* geom, void (__cdecl* cb)());
};

struct ShapeObj : ObjVirt {
    int unk04;
    Shape* shape;
    void bhkConvexVerticesShape_BuildDisplayGeometry(int arg);
};

// pdb: bhkConvexVerticesShape::BuildDisplayGeometry | bhkConvexVerticesShape.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|caller_sim), high
void ShapeObj::bhkConvexVerticesShape_BuildDisplayGeometry(int arg)
{
    Shape* shape = this ? this->shape : 0;
    int n = shape->GetNumVertices();
    HkArray<Vec4> tmp;
    tmp.SetSize(n);
    Vec4* src = shape->GetVertices(tmp.data);
    HkArray<Vec4> verts;
    verts.SetSize(n);
    for (int i = 0; i < n; i++)
        verts[i] = src[i];
    StridedVerts sv;
    sv.count = verts.size;
    sv.stride = sizeof(Vec4);
    sv.data = verts.data;
    Geometry geom;
    FUN_009ec800(&sv, &geom, 1);
    Build(arg, &geom, FUN_00e325ec);
}
}   // namespace f3m_00951330

// @f3 0x0095ef20 (community match, verified in this file)
namespace f3m_0095ef20 {
// hkaRagdollUtils_reorderForRagdoll: hkaRagdollUtils::reorderForRagdoll(hkArray<hkpRigidBody*>&, hkArray<hkpConstraintInstance*>&)
namespace rg {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct hkThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes) throw();
    virtual void onStackUnderflow(void* p) throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_current;
    int unk24;
    char* m_base;
    char* m_end;
    void* allocateChunk(int nbytes, int cls) throw();             // FUN_008f6d30
    void deallocateChunk(void* p, int nbytes, int cls) throw();   // FUN_008f6d90

    __forceinline static hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }

    __forceinline void* allocateStack(int nbytesIn)
    {
        int nbytes = (nbytesIn + 16) & ~15;
        char* current = m_current;
        if (current + nbytes <= m_end)
        {
            m_current = current + nbytes;
            return current;
        }
        return onStackOverflow(nbytes);
    }
    __forceinline void deallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_base)
            onStackUnderflow(p);
    }
};

__forceinline void hkDeallocateStack(void* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

template <class T> __forceinline void hkArray_copy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> __forceinline void hkAlgorithm_swap(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}

void __cdecl hkArrayUtil_reserve(void* arr, int n, int elemSize) throw();   // FUN_00901e90

template <class T> struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline ~hkArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            hkThreadMemory::getInstance().deallocateChunk(m_data, getCapacity() * sizeof(T), 0x17);
    }
    __forceinline int getSize() const { return m_size; }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }

    __forceinline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil_reserve(this, newSize, sizeof(T));
        }
    }
    __forceinline void setSize(int n, const T& fill)
    {
        if (n > m_size)
        {
            int oldSize = m_size;
            reserve(n);
            for (int i = oldSize; i < n; i++)
                m_data[i] = fill;
        }
        m_size = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        m_size = n;
    }
    __forceinline int indexOf(const T& t) const
    {
        for (int i = 0; i < m_size; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    __forceinline hkArray& operator=(const hkArray& a)
    {
        if (getCapacity() < a.m_size)
        {
            if ((m_capacityAndFlags & 0x80000000) == 0)
                hkThreadMemory::getInstance().deallocateChunk(m_data, getCapacity() * sizeof(T), 0x17);
            int n = a.m_size;
            m_data = (T*)hkThreadMemory::getInstance().allocateChunk(n * sizeof(T), 0x17);
            m_capacityAndFlags = (m_capacityAndFlags & 0x40000000) | n;
        }
        m_size = a.m_size;
        hkArray_copy(m_data, a.m_data, m_size);
        return *this;
    }
};

template <class T> struct hkLocalArray : public hkArray<T> {
    T* m_localMemory;
    __forceinline hkLocalArray(int n)
    {
        this->m_data = (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
        this->m_capacityAndFlags = n | 0x80000000;
        m_localMemory = this->m_data;
    }
    __forceinline ~hkLocalArray()
    {
        hkDeallocateStack(m_localMemory);
    }
};

struct hkOstream {
    int unk0, unk4, unk8;
    hkOstream& operator<<(const char* s);   // FUN_00943710
    hkOstream& operator<<(int i);           // FUN_009437d0
};
struct hkErrStream : public hkOstream {
    void init(char* buf, int size);   // FUN_00923070
    void destroy();                   // FUN_00943a60
};

struct hkpEntity;
struct hkpConstraintInstance {
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkpEntity* m_entities[2];
};

}


// pdb: hkaRagdollUtils::reorderForRagdoll | hkaRagdollUtils.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
int __cdecl hkaRagdollUtils_reorderForRagdoll(rg::hkArray<rg::hkpEntity*>& rigidBodiesInOut, rg::hkArray<rg::hkpConstraintInstance*>& constraintsInOut) throw()
{
    using namespace rg;
    const int numBodies = rigidBodiesInOut.getSize();
    const int numConstraints = constraintsInOut.getSize();

    if (numConstraints != numBodies - 1)
    {
        unsigned int assertBuf[0x80];
        hkErrStream ostr;
        ostr.init((char*)assertBuf, 0x200);
        ostr << "Expecting " << (numBodies - 1) << " constraints, not " << numConstraints << ". Can't create rag doll";
        DAT_010f3364->v03(1, 0xabba54bb, (const char*)assertBuf, ".\\Utils\\hkaRagdollUtils.cpp", 0x144);
        ostr.destroy();
        return 1;
    }

    hkLocalArray<int> constraintOfBody(numBodies);
    constraintOfBody.setSize(numBodies, 0);
    hkLocalArray<int> order(numBodies);
    hkLocalArray<int> parentOfBody(numBodies);
    parentOfBody.setSize(numBodies, -1);

    for (int i = 0; i < numConstraints; i++)
    {
        hkpConstraintInstance* c = constraintsInOut[i];
        hkpEntity* entA = c->m_entities[0];
        hkpEntity* entB = c->m_entities[1];
        int a = rigidBodiesInOut.indexOf(entA);
        int b = rigidBodiesInOut.indexOf(entB);
        if (a < 0 || b < 0)
            return 1;
        if (parentOfBody[a] != -1 || constraintOfBody[a] != 0)
            return 1;
        constraintOfBody[a] = i;
        parentOfBody[a] = b;
    }

    {
        hkLocalArray<int> depth(numBodies);
        depth.setSize(numBodies, 0);
        for (int i = 0; i < numBodies; i++)
        {
            int p = parentOfBody[i];
            while (p != -1)
            {
                depth[i]++;
                p = parentOfBody[p];
            }
        }
        order.setSizeUnchecked(numBodies);
        for (int i = 0; i < numBodies; i++)
            order[i] = i;
        for (int i = 0; i < numBodies - 1; i++)
        {
            for (int j = i + 1; j < numBodies; j++)
            {
                if (depth[i] > depth[j])
                {
                    hkAlgorithm_swap(depth[i], depth[j]);
                    hkAlgorithm_swap(order[i], order[j]);
                }
            }
        }
    }

    hkLocalArray<hkpEntity*> newBodies(numBodies);
    newBodies.setSizeUnchecked(numBodies);
    hkLocalArray<hkpConstraintInstance*> newConstraints(numConstraints);
    newConstraints.setSizeUnchecked(numConstraints);

    for (int i = 0; i < numBodies; i++)
    {
        int bi = order[i];
        newBodies[i] = rigidBodiesInOut[bi];
        if (i > 0)
        {
            int ci = constraintOfBody[bi];
            if (ci >= 0)
                newConstraints[i - 1] = constraintsInOut[ci];
            else
                newConstraints[i - 1] = 0;
        }
    }

    rigidBodiesInOut = newBodies;
    constraintsInOut = newConstraints;

    return 0;
}
}   // namespace f3m_0095ef20

// @f3 0x00949df0 (community match, verified in this file)
#include <math.h>
namespace f3m_00949df0 {

struct CC61F0Stream;
struct NFRef;

struct ReaderImpl {
    int unk00;
    int pos;
    int (__cdecl* pfnRead)(ReaderImpl*, void*, int, int*, int);
    __forceinline void Read(void* dst, int nbytes, int count)
    {
        int n = nbytes;
        int got = pfnRead(this, dst, nbytes, &n, count);
        pos += got;
    }
};

struct CC61F0Stream {
    int unk00;
    unsigned int unk04;
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
    ReaderImpl* impl;
};

struct CC61F0ConstraintBase {
    void LoadBinaryBase(CC61F0Stream& stream);
    int unk00;
    void* m_pData;
};

struct FUN_00949df0_cls : CC61F0ConstraintBase {
    void FUN_00949df0(CC61F0Stream& stream);
    NFRef* FUN_008fc6d0(CC61F0Stream& stream);
};

struct NFRef {
    virtual ~NFRef();
    short w04;
    short w06;
};

struct NFVec4 {
    float x, y, z, w;
};
__forceinline float hkSqrt(float r) { return sqrtf(r); }
__forceinline float hkSqrtInv(float r) { return 1.0f / sqrtf(r); }
__forceinline void Normalize(NFVec4& v)
{
    float len2 = v.x * v.x + v.y * v.y + v.z * v.z;
    float inv;
    if (len2 != 0.0f)
        inv = 1.0f / sqrtf(len2);
    else
        inv = 0.0f;
    v.x *= inv;
    v.y *= inv;
    v.z *= inv;
    v.w *= inv;
}

struct NFMatrix3 {
    NFVec4 m_col0;
    NFVec4 m_col1;
    NFVec4 m_col2;
    __forceinline NFVec4& getColumn(int i) { return (&m_col0)[i]; }
};
struct NFTransform {
    NFMatrix3 m_rotation;
    NFVec4 m_translation;
    __forceinline NFMatrix3& getRotation() { return m_rotation; }
};


struct NFObj {
    int unk00;
    unsigned int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NFTransform tA;
    NFTransform tB;
    unsigned char c_a0;
    unsigned char c_a1;
    unsigned char c_a2;
    unsigned char c_a3;
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    float f_f8;
    int unkfc;
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
    void FUN_00959ff0(NFRef* r);
    void FUN_0095a030(NFRef* r);
    void FUN_0095a010(NFRef* r);
};

// @fnv 0x949df0
void FUN_00949df0_cls::FUN_00949df0(CC61F0Stream& stream)
{
    LoadBinaryBase(stream);

    NFObj* o = (NFObj*)m_pData;

    stream.impl->Read(&o->tA, 0x40, 1);
    stream.impl->Read(&o->tB, 0x40, 1);
    stream.impl->Read(&o->unk11c, 4, 1);
    stream.impl->Read(&o->unk12c, 4, 1);
    stream.impl->Read(&o->unk130, 4, 1);
    stream.impl->Read(&o->unk104, 4, 1);
    stream.impl->Read(&o->unk108, 4, 1);
    stream.impl->Read(&o->f_f8, 4, 1);

    if (o->f_f8 == 0.0f)
        o->f_f8 = 100.0f;

    const NFVec4& dmy0 = o->tA.m_rotation.m_col1;
    const NFVec4& dmy1 = o->tA.m_rotation.m_col1;
    NFVec4& a1 = o->tA.m_rotation.m_col1;
    NFVec4& a0 = o->tA.m_rotation.m_col0;
    NFVec4& b1 = o->tB.m_rotation.m_col1;
    Normalize(a1);
    Normalize(a0);
    Normalize(b1);
    Normalize(o->tB.m_rotation.m_col0);

    if (stream.unk04 > 0x1d) {
        NFRef* r = FUN_008fc6d0(stream);
        o->FUN_00959ff0(r);
        o->FUN_0095a030(r);
        o->FUN_0095a010(r);
        if (r) {
            stream.impl->Read(&o->c_a2, 1, 1);
            if (r->w04 != 0) {
                --r->w06;
                if (r->w06 == 0)
                    delete r;
            }
        }
    }
}
}   // namespace f3m_00949df0

// @f3 0x0095b330 (community match, verified in this file)
namespace f3m_0095b330 {
namespace W8 {
void __cdecl FUN_00901e90(void* arr, int nelem, unsigned int elemsize);
struct Pose97 { int count; char* name; short* parents; };
void __cdecl FUN_00a029e0(Pose97* pose, void* data);

struct Skeleton97 { int unk00; short* parents; int unk08; int unk0c; int count; };
struct Bind97 {
    int unk00;
    unsigned short f04;
    unsigned short f06;
    char* name;
    int boneCount;
    int unk10, unk14, unk18, unk1c;
    int* remapping;
    int unk24, unk28;
    Skeleton97* skeleton;
};
struct Def97 { float f00,f04,f08,f0c,f10,f14,f18,f1c,f20,f24,f28,f2c; Def97* FUN_0095b2b0(); };
struct Tran97 { float f00,f04,f08,f0c,f10,f14,f18,f1c,f20,f24,f28,f2c,f30,f34,f38,f3c; };

struct Arr30 {
    Def97* data; int count; unsigned int cap;
    Arr30() : data(0), count(0), cap(0x80000000) {}
};
struct ArrUnk {
    void* data; int count; unsigned int cap;
    ArrUnk() : data(0), count(0), cap(0x80000000) {}
};
struct Arr40 {
    Tran97* data; int count; unsigned int cap;
    Arr40() : data(0), count(0), cap(0x80000000) {}
    void resize(int n) {
        int c = (int)(cap & 0x3fffffff);
        if (c < n) { int nc = c + c; if (n >= nc) nc = n; FUN_00901e90(this, nc, 0x40); }
        count = n;
    }
};
struct ArrS {
    short* data; int count; unsigned int cap;
    ArrS() : data(0), count(0), cap(0x80000000) {}
};

struct Obj97 {
    Arr30 defaults;
    ArrUnk u0c;
    Pose97 pose;
    int u24;
    Arr40 transforms;
    Bind97* binding;
    ArrS parents;
    Obj97(Bind97* p) : u24(0), binding(p) {}
};
struct FUN_0095b330 : Obj97 { FUN_0095b330(Bind97* p); };

FUN_0095b330::FUN_0095b330(Bind97* p) : Obj97(p) {
    ArrS* par = &parents;
    if (p->f04 != 0) p->f06 += 1;
    {
        int c = (int)(defaults.cap & 0x3fffffff);
        if (c < 1) { int nc = c + c; if (nc <= 1) nc = 1; FUN_00901e90(this, nc, 0x30); }
        defaults.count = 1;
    }
    Def97 temp;
    defaults.data[0] = *temp.FUN_0095b2b0();
    int n = p->boneCount;
    if (n != p->skeleton->count) {
        int old = par->count;
        if (n > old) {
            int c = (int)(par->cap & 0x3fffffff);
            if (c < n) { int nc = c + c; if (n >= nc) nc = n; FUN_00901e90(par, nc, 2); }
            for (int i = old; i < n; i++) par->data[i] = -1;
        }
        par->count = n;
        for (int i = 0; i < p->skeleton->count; i++) {
            int* remap = p->remapping;
            int mapped = remap[i];
            if (mapped >= 0) {
                int ancestor = i;
                int parent = -1;
                do {
                    ancestor = p->skeleton->parents[ancestor];
                    if (ancestor < 0) break;
                    parent = remap[ancestor];
                } while (parent < 0);
                par->data[mapped] = (short)parent;
            }
        }
    } else {
        int old = par->count;
        if (n > old) {
            int c = (int)(par->cap & 0x3fffffff);
            if (c < n) { int nc = c + c; if (n >= nc) nc = n; FUN_00901e90(par, nc, 2); }
            for (int i = old; i < n; i++) par->data[i] = -1;
        }
        par->count = n;
        for (int i = 0; i < p->skeleton->count; i++) par->data[i] = p->skeleton->parents[i];
    }
    pose.count = n;
    pose.name = p->name;
    pose.parents = parents.data;
    transforms.resize(n);
    FUN_00a029e0(&pose, transforms.data);
}
}
}   // namespace f3m_0095b330

// @f3 0x00959600 (community match, verified in this file)
extern double DAT_00dc0438;
namespace f3m_00959600 {
namespace Interpolate431 {

struct __declspec(align(16)) Vector {
    float x, y, z, w;

    void Lerp(const Vector& a, const Vector& b, float t) {
        float other = 1.0f - t;
        x = a.x * other + b.x * t;
        y = a.y * other + b.y * t;
        z = a.z * other + b.z * t;
        w = a.w * other + b.w * t;
    }

    float Dot(const Vector& b) const {
        return x * b.x + y * b.y + z * b.z + w * b.w;
    }

    Vector operator*(double s) const {
        Vector v;
        v.x = static_cast<float>(x * s);
        v.y = static_cast<float>(y * s);
        v.z = static_cast<float>(z * s);
        v.w = static_cast<float>(w * s);
        return v;
    }

    void Scale(double s) {
        x = static_cast<float>(x * s);
        y = static_cast<float>(y * s);
        z = static_cast<float>(z * s);
        w = static_cast<float>(w * s);
    }

    void FUN_004e5c20();
};

struct Transform {
    Vector first, rotation, last;
};

// pdb: blendTwoTransforms | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun_prop + skyrim(objrun_prop), high
void __cdecl blendTwoTransforms(const Transform* a, const Transform* b, float t, Transform* out) {
    out->first.Lerp(a->first, b->first, t);
    Vector rotation = b->rotation;
    float dot = a->rotation.Dot(b->rotation);
    float zero = 0.0f;
    if (dot < zero)
        rotation.Scale(DAT_00dc0438);
    Vector& destinationRotation = out->rotation;
    destinationRotation.Lerp(a->rotation, rotation, t);
    out->last.Lerp(a->last, b->last, t);
    float length = destinationRotation.Dot(destinationRotation);
    if (length < 1.1920928955078125e-7f) {
        destinationRotation.x = zero;
        destinationRotation.y = zero;
        destinationRotation.z = zero;
        destinationRotation.w = 1;
    } else {
        destinationRotation.FUN_004e5c20();
    }
}
}
}   // namespace f3m_00959600

// @f3 0x00952d10 (community match, verified in this file)
namespace f3m_00952d10 {
struct ArrayEntry {
    int unk00;
    int unk04;
    void* unk08;
};
struct LoadStream {
    unsigned int FUN_0082a2b0();
    ArrayEntry* FUN_0082a280();
};
struct ArrayAllocator {
    void FUN_008f6d90(void* data, int bytes, int tag);
};
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
void __cdecl FUN_00901e90(void* array, int capacity, int stride);
void __cdecl FUN_00901f10(void* array, int stride);
struct LoadArray {
    void** data;
    int size;
    int capacityAndFlags;
    __forceinline void clearAndDeallocate()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            ArrayAllocator* allocator = (ArrayAllocator*)DAT_00d9b080(DAT_010f3170);
            allocator->FUN_008f6d90(data, capacity * 4, 0x17);
        }
        capacityAndFlags = (capacityAndFlags & 0xc0000000) | 0x80000000;
        data = 0;
        size = 0;
    }
    __forceinline void reserve(int n)
    {
        int capacity = capacityAndFlags & 0x3fffffff;
        if (capacity < n) {
            int doubled = capacity * 2;
            FUN_00901e90(this, n < doubled ? doubled : n, 4);
        }
    }
    __forceinline void pushBack(void* const& value)
    {
        int capacity = capacityAndFlags & 0x3fffffff;
        void* item = value;
        if (size == capacity)
            FUN_00901f10(this, 4);
        data[size++] = item;
    }
};
struct LoadedArrayObject {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LoadArray array;
};
struct ArrayLoadOwner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual LoadedArrayObject* vB4(char* out);
    void FUN_008f7450(LoadStream* stream);
    void FUN_00952d10(LoadStream* stream);
};
// pdb: bhkConvexListShape::LinkObject | bhkConvexListShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void ArrayLoadOwner::FUN_00952d10(LoadStream* stream)
{
    char local;
    LoadedArrayObject* object = vB4(&local);
    unsigned int count = stream->FUN_0082a2b0();
    if (object) {
        object->array.clearAndDeallocate();
        object->array.reserve((int)count);
        for (unsigned int i = 0; i < count; ++i) {
            ArrayEntry* entry = stream->FUN_0082a280();
            if (entry)
                object->array.pushBack(entry->unk08);
        }
    }
    FUN_008f7450(stream);
}
}   // namespace f3m_00952d10

// @f3 0x00947ce0 (community match, verified in this file)
#include <math.h>
extern const float DAT_00dc0bc8;
namespace f3m_00947ce0 {
namespace breakable_apply1997 {
struct Binary{unsigned int unk00,position;unsigned int(__cdecl* read)(Binary*,void*,unsigned int,const unsigned int*,unsigned int);};
struct Stream{unsigned int unk000;unsigned int unk004;unsigned int unk008;unsigned int unk00C;unsigned int unk010;unsigned int unk014;unsigned int unk018;unsigned int unk01C;unsigned int unk020;unsigned int unk024;unsigned int unk028;unsigned int unk02C;unsigned int unk030;unsigned int unk034;unsigned int unk038;unsigned int unk03C;unsigned int unk040;unsigned int unk044;unsigned int unk048;unsigned int unk04C;unsigned int unk050;unsigned int unk054;unsigned int unk058;unsigned int unk05C;unsigned int unk060;unsigned int unk064;unsigned int unk068;unsigned int unk06C;unsigned int unk070;unsigned int unk074;unsigned int unk078;unsigned int unk07C;unsigned int unk080;unsigned int unk084;unsigned int unk088;unsigned int unk08C;unsigned int unk090;unsigned int unk094;unsigned int unk098;unsigned int unk09C;unsigned int unk0A0;unsigned int unk0A4;unsigned int unk0A8;unsigned int unk0AC;unsigned int unk0B0;unsigned int unk0B4;unsigned int unk0B8;unsigned int unk0BC;unsigned int unk0C0;unsigned int unk0C4;unsigned int unk0C8;unsigned int unk0CC;unsigned int unk0D0;unsigned int unk0D4;unsigned int unk0D8;unsigned int unk0DC;unsigned int unk0E0;unsigned int unk0E4;unsigned int unk0E8;unsigned int unk0EC;unsigned int unk0F0;unsigned int unk0F4;unsigned int unk0F8;unsigned int unk0FC;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10C;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11C;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12C;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13C;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14C;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15C;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16C;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17C;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18C;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19C;unsigned int unk1A0;unsigned int unk1A4;unsigned int unk1A8;unsigned int unk1AC;unsigned int unk1B0;unsigned int unk1B4;unsigned int unk1B8;unsigned int unk1BC;unsigned int unk1C0;unsigned int unk1C4;unsigned int unk1C8;unsigned int unk1CC;unsigned int unk1D0;unsigned int unk1D4;unsigned int unk1D8;unsigned int unk1DC;unsigned int unk1E0;unsigned int unk1E4;unsigned int unk1E8;unsigned int unk1EC;unsigned int unk1F0;unsigned int unk1F4;unsigned int unk1F8;unsigned int unk1FC;unsigned int unk200;unsigned int unk204;unsigned int unk208;unsigned int unk20C;unsigned int unk210;unsigned int unk214;unsigned int unk218;unsigned int unk21C;unsigned int unk220;unsigned int unk224;unsigned int unk228;unsigned int unk22C;unsigned int unk230;unsigned int unk234;unsigned int unk238;unsigned int unk23C;unsigned int unk240;unsigned int unk244;unsigned int unk248; Binary* binary;};
struct Record{unsigned int unk00,unk04,unk08,unk0C;unsigned char flag10,unk11,unk12,unk13;float thresholdSquared;bool flag18;unsigned char unk19,unk1A,unk1B;unsigned int unk1C,unk20;__forceinline Record(){thresholdSquared=DAT_00dc0bc8;unk08=0;unk0C=0;flag10=0;flag18=0;unk1C=0;unk20=0;}};
struct Child{unsigned int unk00;unsigned int unk04;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C; float threshold;bool flag24;unsigned char unk25,unk26,unk27;__forceinline void SetThreshold(float value){threshold=value;}};
struct Loader{virtual void Slot000();virtual void Slot004();virtual void Slot008();virtual void Slot00C();virtual void Slot010();virtual unsigned int Initialize();Child* data;void FUN_00947ce0(Stream*,Record*);};
typedef char RecordSize[(sizeof(Record)==0x24)?1:-1];
void Loader::FUN_00947ce0(Stream* stream,Record* supplied){Record local;Record* record=supplied;if(!record){Binary* binary=stream->binary;record=&local;binary->position+=binary->read(binary,record,sizeof(Record),0,0);}Initialize();bool f=*(volatile bool*)&record->flag18;Child* target=data;target->flag24=f;target->SetThreshold((float)sqrt(record->thresholdSquared));}
}
}   // namespace f3m_00947ce0

// @f3 0x009470f0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009470f0 {
namespace m9470f0 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);

struct S9470f0_Heap {
    void* FUN_008f6d30(unsigned size, unsigned tag);
};

struct __declspec(align(16)) S9470f0_Vec {
    float x, y, z, w;
    S9470f0_Vec() {}
    S9470f0_Vec(const S9470f0_Vec& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    S9470f0_Vec& operator=(const S9470f0_Vec& o)
    {
        x = o.x; y = o.y; z = o.z; w = o.w;
        return *this;
    }
};

struct S9470f0_Bound {
    S9470f0_Vec a;
    S9470f0_Vec b;
    S9470f0_Bound() {}
    S9470f0_Bound(const S9470f0_Vec& va, const S9470f0_Vec& vb) 
    {
        b = vb;
        a = va;
    }
};

struct __declspec(align(16)) S9470f0_Src {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S9470f0_Vec v1;
    S9470f0_Vec v2;
    float unk30;
    float unk34;
};

struct __declspec(align(16)) S9470f0_Item {
    void** vtbl;
    unsigned short size;
    short refs;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S9470f0_Bound bound;
    float unk40;
    float unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;

    S9470f0_Item(int a, int b, int c);
    static void* operator new(unsigned n)
    {
        S9470f0_Heap* heap = (S9470f0_Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x29);
        ((S9470f0_Item*)p)->size = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p);
    void Release()
    {
        if (size && --refs == 0) {
            typedef void (__thiscall *Fn)(S9470f0_Item*, int);
            ((Fn)vtbl[0])(this, 1);
        }
    }
};

struct S9470f0_Owner {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void Add(S9470f0_Item*);
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46();
    virtual void Finish(S9470f0_Src*);
    void FUN_009470f0(S9470f0_Src* src);
};

// pdb: bhkDashpotAction::Init | bhkDashpotAction.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInfo
void S9470f0_Owner::FUN_009470f0(S9470f0_Src* src)
{
    if (src) {
        S9470f0_Item* item = new S9470f0_Item(src->unk4, src->unk8, 0);
        S9470f0_Bound b(src->v1, src->v2);
        item->bound = b;
        item->unk40 = src->unk30;
        item->unk44 = src->unk34;
        Add(item);
        item->Release();
        Finish(src);
    }
}
}
}   // namespace f3m_009470f0

// @f3 0x0095ee30 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0095ee30 {
namespace f3m_0095ee30 {

struct FreeNode {
    FreeNode* next;
};

struct FreeList {
    FreeNode* head;
    int count;
    void Push(FreeNode* b) {
        ++count;
        b->next = head;
        head = b;
    }
};

struct Pool {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    int limit;
    FreeList row0;
    FreeList row1;
    FreeList row2;
    FreeList row3;
    FreeList row4;

    void FUN_008f6890(int row, void* p, int tag);
    void FUN_008f6f90(void* p);
};

__declspec(dllimport) Pool* __stdcall FUN_00d9b080(unsigned long);

inline void Deallocate(void* p) {
    Pool* pool = FUN_00d9b080(DAT_010f3170);
    pool->FUN_008f6f90(p);
}

inline void FreeRow1(void* p) {
    Pool* pool = FUN_00d9b080(DAT_010f3170);
    if (pool->row1.count >= pool->limit)
        pool->FUN_008f6890(1, p, 0x3b);
    else
        pool->row1.Push((FreeNode*)p);
}

inline void FreeRow4(void* p) {
    Pool* pool = FUN_00d9b080(DAT_010f3170);
    if (pool->row4.count >= pool->limit)
        pool->FUN_008f6890(4, p, 0x3b);
    else
        pool->row4.Push((FreeNode*)p);
}

struct SubItem {
    void* data;
};

struct Obj95ee30 {
    int unk00;
    void* unk04;
    int unk08;
    SubItem** items;
    int count;
    void* unk14;
};

// pdb: hkaRagdollUtils::copyRagdollInstanceShallow | hkaRagdollUtils.obj | fnv360_0822_debug, objrun, medium
// pdb params: original
extern "C" void __cdecl FUN_0095ee30(Obj95ee30* p) {
    int n = p->count;
    Deallocate(p->unk04);
    for (int i = 0; i < n; ++i) {
        SubItem* item = p->items[i];
        if (item->data) {
            Deallocate(item->data);
        }
        FreeRow1(item);
    }
    Deallocate(p->items);
    Deallocate(p->unk14);
    FreeRow4(p);
}
}
}   // namespace f3m_0095ee30

// @f3 0x00950440 (community match, verified in this file)
extern float DAT_00f7a690;
namespace f3m_00950440 {
namespace Init950440 {
struct Matrix {
 float a,b,c,d,e,f,g,h,i;
 Matrix():a(0),b(0),c(0),d(0),e(0),f(0),g(0),h(0),i(0){}
};
struct FUN_00950440 {
 void* object;float scalar;int unk08,unk0c;Matrix matrix;
 FUN_00950440();
};
FUN_00950440::FUN_00950440():object(0),scalar(DAT_00f7a690) {
 matrix.a=0;matrix.b=0;matrix.c=0;matrix.d=0;
 matrix.e=1;matrix.f=0;matrix.g=0;matrix.h=0;
}
}
}   // namespace f3m_00950440

// @f3 0x0094e320 (community match, verified in this file)
extern float DAT_00f7a690;
namespace f3m_0094e320 {
namespace Init94e320 {
struct Matrix {float a,b,c,d,e,f,g,h,i,j,k,l;Matrix():a(0),b(0),c(0),d(0),e(0),f(0),g(0),h(0),i(0),j(0),k(0),l(0){}};
struct FUN_0094e320 {void* object;float scalar;int unk08,unk0c;Matrix matrix;FUN_0094e320();};
// pdb: bhkTriangleShape::CreateClone | bhkTriangleShape.obj | fnv360_1110_retail, objopen_prop, low
// pdb params: arCloneData
FUN_0094e320::FUN_0094e320():object(0),scalar(DAT_00f7a690){matrix.a=0;matrix.b=0;matrix.c=0;matrix.d=0;matrix.e=0;matrix.f=0;matrix.g=0;matrix.h=0;matrix.i=0;matrix.j=0;matrix.k=0;matrix.l=0;}
}
}   // namespace f3m_0094e320

// @f3 0x00945da0 (community match, verified in this file)
namespace f3m_00945da0 {
namespace Create945da0 {
struct Item {void FUN_004f64e0();};struct Heap {unsigned char* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;
struct Object {int unk00,unk04;void* parent;Item* item;void FUN_0090daf0(Item*);Item* FUN_00945da0(bool*);};
// pdb: bhkCachingShapePhantom::CreateCinfo | bhkCachingShapePhantom.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arCreated
Item* Object::FUN_00945da0(bool* created){if(!item){unsigned char* memory=DAT_01090a78.FUN_0086b930(0x70);unsigned char adjustment=(unsigned char)(0x10-((unsigned char)(unsigned)memory&0xf));memory+=adjustment;memory[-1]=adjustment;Item* value=(Item*)memory;value->FUN_004f64e0();item=value;if(parent)FUN_0090daf0(value);*created=true;}else *created=false;return item;}
}
}   // namespace f3m_00945da0

// @f3 0x0094d720 (community match, verified in this file)
namespace f3m_0094d720 {
namespace Create94d720 {
struct Heap {void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;
struct Vec4 {unsigned x,y,z;float w;Vec4():x(0),y(0),z(0),w(1){}void* operator new(unsigned size){return DAT_01090a78.FUN_0086b930(size);}};
struct Object {int unk00,unk04;void* parent;Vec4* item;void FUN_0094d4e0(Vec4*);Vec4* FUN_0094d720(bool*);};
// pdb: bhkMoppBvTreeShape::CreateCinfo | bhkMoppBvTreeShape.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arCreated
Vec4* Object::FUN_0094d720(bool* created){if(!item){item=new Vec4;if(parent)FUN_0094d4e0(item);*created=true;}else *created=false;return item;}
}
}   // namespace f3m_0094d720

// @f3 0x0094cff0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0094cff0 {
namespace f3m_0094cff0 {

struct MemoryContext94cff0 {
    void* FUN_008f6d30(int iSize, int iCategory);
};

extern MemoryContext94cff0* (__stdcall* const FUN_00d9b080)(unsigned long);

struct FUN_009e1b50 {
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08, m_0c, m_10, m_14, m_18, m_1c;
    float f20, f24, f28, f2c, f30, f34, f38, f3c;
    int m_40, m_44, m_48, m_4c;
    static void* operator new(unsigned int uiSize) {
        MemoryContext94cff0* pkContext = FUN_00d9b080(DAT_010f3170);
        void* pBlock = pkContext->FUN_008f6d30(uiSize, 0x2c);
        *(unsigned short*)((char*)pBlock + 4) = (unsigned short)uiSize;
        return pBlock;
    }
    FUN_009e1b50();
};

struct Param2_94cff0 {
    int u00, u04, u08, u0c;
    float f10;
};

__declspec(noinline) void __cdecl FUN_0094cda0(float scale, FUN_009e1b50* dst) {
    dst->m_00 <<= dst->m_08;
}

struct Owner94cff0 {
    int m_00;
    FUN_009e1b50* m_04;
    void FUN_008fc3f0(FUN_009e1b50* dst, Param2_94cff0* p2);
    void FUN_0094cff0(FUN_009e1b50* dst, Param2_94cff0* p2);
};

void Owner94cff0::FUN_0094cff0(FUN_009e1b50* dst, Param2_94cff0* p2) {
    FUN_009e1b50* src = m_04;
    if (!dst) {
        dst = new FUN_009e1b50();
    }
    dst->f20 = src->f20;
    dst->f24 = src->f24;
    dst->f28 = src->f28;
    dst->f2c = src->f2c;
    dst->f30 = src->f30;
    dst->f34 = src->f34;
    dst->f38 = src->f38;
    dst->f3c = src->f3c;
    float s = p2->f10;
    if (s != 1.0f) {
        FUN_0094cda0(s, dst);
    }
    FUN_008fc3f0(dst, p2);
}
}
}   // namespace f3m_0094cff0

// @f3 0x00942000 (community match, verified in this file)
namespace f3m_00942000 {
namespace c942000 {
struct Container20 {
    int unk00;
    bool active04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    int FUN_009b4a50(int value);
};

struct Element {
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

    int FUN_009b4a50(int value);
};

struct Object {
    int unk00;
    float value04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Container20 unk20;
    Element elems[5];
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int count;
    int unk14C;
    int unk150;
    int unk154;
    bool flag158;
    int unk15C;
    int unk160;
    bool flag164;

    void FUN_00942000(float value, bool flag);
};

void Object::FUN_00942000(float value, bool flag)
{
    *(volatile bool*)&unk20.active04 = true;
    value04 = value;
    *(volatile bool*)&flag158 = true;
    flag164 = flag;
    for (int i = *(volatile int*)&count - 1; i >= 0; i--) {
        elems[i].FUN_009b4a50(1);
    }
    unk20.FUN_009b4a50(count);
}
}
}   // namespace f3m_00942000

// @f3 0x00944650 (community match, verified in this file)
namespace f3m_00944650 {
namespace f3m_00944650 {

struct Collidable944650;
struct CollisionInput944650;

class AgentFactory {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* v0c(Collidable944650* a, Collidable944650* b, CollisionInput944650* input);
};

struct Dispatcher944650 {
    int unk00, unk04, unk08;
    AgentFactory* table0c[8][8];
};

struct CollisionInput944650 {
    Dispatcher944650* dispatcher00;
};

struct Island944650 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short flag20;
    unsigned short unk22;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    int agentTrack58;
};

struct Body944650 {
    int unk00, unk04;
    void* world08;
    int unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    signed char quality80;
    int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4;
    Island944650* islandB8;
    int unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
    unsigned char motionTypeD8;
};

struct Collidable944650 {
    int unk00, unk04, unk08, unk0c;
    signed char ownerOffset10;

    Body944650* GetOwner() const {
        return (Body944650*)((char*)this + ownerOffset10);
    }
};

void __cdecl FUN_00928630(void* world, Body944650* a, Body944650* b);
void __cdecl FUN_00998970(Collidable944650* a, Collidable944650* b, CollisionInput944650* input, void** outMgr, int* outFlipped);
void __cdecl hkAgentNnMachine_CreateAgent(int* track, Collidable944650* a, Collidable944650* b, void* mgr, CollisionInput944650* input, void* agent);

// pdb: hkpWorldAgentUtil::addAgent | hkpWorldAgentUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpWorldAgentUtil_addAgent(Collidable944650* collA, Collidable944650* collB, CollisionInput944650* input)
{
    Body944650* bodyA = collA->GetOwner();
    Body944650* bodyB = collB->GetOwner();
    if (bodyA->motionTypeD8 != 7 && bodyB->motionTypeD8 != 7 && bodyA->islandB8 != bodyB->islandB8)
        FUN_00928630(bodyA->world08, bodyA, bodyB);

    Island944650* islandA = bodyA->islandB8;
    Island944650* islandB = bodyB->islandB8;
    Island944650* island = (islandA->flag20 == 0xffff && islandB->flag20 != 0xffff) ? islandB : islandA;

    void* mgr;
    int flipped;
    FUN_00998970(collA, collB, input, &mgr, &flipped);
    if (flipped) {
        Collidable944650* tmp = collA;
        collA = collB;
        collB = tmp;
    }

    void* agent = input->dispatcher00->table0c[bodyA->quality80][bodyB->quality80]->v0c(collA, collB, input);
    hkAgentNnMachine_CreateAgent(&island->agentTrack58, collA, collB, mgr, input, agent);
}

}
}   // namespace f3m_00944650

// @f3 0x009455c0 (community match, verified in this file)
extern void* DAT_01169148;
namespace f3m_009455c0 {
typedef void (__thiscall* Vfn9455c0)(void*, void*);

unsigned int FUN_00847b50(void* table);
struct Info9455c0 {
    unsigned unk00,unk04;
    unsigned short m_f08;
    unsigned short m_f0a;
    unsigned short m_f0c;
    unsigned short m_f0e;
    void FUN_00555790(unsigned int x);
    void FUN_005b3880(unsigned int index, unsigned int* out);
};
struct Class9455c0 {
    unsigned unk00,unk04,unk08,unk0c;
    void** m_pArray10;
    unsigned unk14,unk18;
    unsigned int m_iCount1c;
    void FUN_00845ca0(Info9455c0* info);
    void FUN_009455c0(Info9455c0* info);
};
// pdb: bhkExtraData::GetViewerStrings | bhkExtraData.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Class9455c0::FUN_009455c0(Info9455c0* info)
{
    FUN_00845ca0(info);
    unsigned int value = FUN_00847b50(DAT_01169148);
    unsigned int index = info->m_f0a;
    if (index >= info->m_f08)
        info->FUN_00555790(info->m_f0e + index);
    info->FUN_005b3880(index, &value);
    unsigned int count = m_iCount1c;
    for (unsigned int i = 0; i < count; ++i)
    {
        void* item = m_pArray10[i];
        if (item != 0)
            ((Vfn9455c0)(*(void***)item)[0x60 / 4])(item, info);
    }
}


}   // namespace f3m_009455c0

// @f3 0x00943340 (community match, verified in this file)
namespace f3m_00943340 {
namespace f3m_00943340 {
struct Format { unsigned FUN_0093dac0(); void* FUN_0093d890(); };
struct Buffer { char* data; int count; };
struct Source { Format* FUN_0093d790(); Buffer* FUN_0093d660(); };
struct __declspec(align(8)) Element { char* data; void* format; };
typedef void (__cdecl *Callback)(Element*,Element*,void*);
void __cdecl FUN_00943340(Source* left,Source* right,Callback callback,void* context) {
    unsigned leftStride=left->FUN_0093d790()->FUN_0093dac0();
    unsigned rightStride=right->FUN_0093d790()->FUN_0093dac0();
    Buffer* leftBuffer=left->FUN_0093d660();
    Buffer* rightBuffer=right->FUN_0093d660();
    int count=leftBuffer->count;
    Element first,second;
    first.format=left->FUN_0093d790()->FUN_0093d890();
    second.format=right->FUN_0093d790()->FUN_0093d890();
    char* leftData=leftBuffer->data;
    char* rightData=rightBuffer->data;
    for(int i=0;i<count;++i) {
        first.data=leftData;
        second.data=rightData;
        callback(&first,&second,context);
        leftData+=leftStride;
        rightData+=rightStride;
    }
}
}
}   // namespace f3m_00943340

// @f3 0x00947f00 (community match, verified in this file)
extern int DAT_00e1c2e4;
namespace f3m_00947f00 {
namespace f3m_00947f00 {

struct hkConstraintCinfo {
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkConstraintCinfo()
    {
        vtable = &DAT_00e1c2e4;
        unk04 = 0;
        unk0c = 0;
        unk10 = 0;
        unk08 = 1;
    }
    ~hkConstraintCinfo() { vtable = &DAT_00e1c2e4; FUN_008fbbb0(0); }
    void FUN_008fbbb0(int data);
};

struct Source {
    int unk00;
    unsigned unk04;
    Source* FUN_0082a280();
    void FUN_0082a2b0();
    void FUN_008fc420(hkConstraintCinfo* info);
};

struct Holder {
    int unk00;
    void FUN_00947be0(hkConstraintCinfo* info);
};

struct Base2 { int unk00; };

struct Obj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0();
    virtual Base2* GetLink(bool* flag);
    void FUN_008f7ec0(Source* s);
    void FUN_008fbe70(Source* s);
    void FUN_00947f00(Source* s);
};

struct Link : Holder, Base2 {};

void Obj::FUN_00947f00(Source* s)
{
    bool flag;
    Base2* b = GetLink(&flag);
    Link* link = static_cast<Link*>(b);
    if (s->unk04 < 6) {
        if (link) {
            Source* src = s->FUN_0082a280();
            if (src) {
                hkConstraintCinfo info;
                src->FUN_008fc420(&info);
                link->FUN_00947be0(&info);
            }
            FUN_008f7ec0(s);
        }
    } else {
        FUN_008fbe70(s);
        s->FUN_0082a2b0();
        s->FUN_0082a280();
        s->FUN_0082a280();
    }
}

}
}   // namespace f3m_00947f00

// @f3 0x0095b610 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0095b610 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct V4 {
    float x, y, z, w;
    __forceinline void operator=(const V4& s) { x = s.x; y = s.y; z = s.z; w = s.w; }
};
struct Xf12 { V4 a, b, c;
    __forceinline void operator=(const Xf12& s) { a = s.a; b = s.b; c = s.c; } };
struct __declspec(align(16)) Loc { Xf12 x; Xf12* p; int q; };

struct Alloc {
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* cur;
    int unk24;
    char* last;
    char* end;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* Alloc_(unsigned int n);
    virtual void Free_(void* p);
    void FUN_008f6d90(void* p, unsigned int size, int tag);
};

struct ScratchBuf {
    Xf12* data;
    unsigned flags;
    __forceinline ScratchBuf(unsigned n)
    {
        Alloc* al = (Alloc*)TlsGetValue(DAT_010f3170);
        unsigned size = (n * sizeof(Xf12) + 0x10) & 0xfffffff0;
        char* buf = al->cur;
        if (buf + size <= al->end)
            al->cur = buf + size;
        else
            buf = (char*)al->Alloc_(size);
        data = (Xf12*)buf;
        flags = n | 0x80000000;
    }
    __forceinline void Release()
    {
        Alloc* al = (Alloc*)TlsGetValue(DAT_010f3170);
        al->cur = (char*)data;
        if ((char*)data == al->last)
            al->Free_(data);
        if ((flags & 0x80000000) == 0) {
            al = (Alloc*)TlsGetValue(DAT_010f3170);
            al->FUN_008f6d90(data, (flags & 0x3fffffff) * sizeof(Xf12), 0x17);
        }
    }
};

struct Inner { int unk00; int unk04; int unk08; int unk0c; int count; };
struct Mid { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int* map; int unk24; int unk28; Inner* inner; };

struct Sub { unsigned n; };

struct Cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned unk10;
    int unk14;
    Sub sub18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    Mid* unk34;
    void FUN_0095b610(float a, Xf12* src, const Xf12& xf, int d);
};

void FUN_00a033a0(float a, Loc* m, Sub* list, int p0, int d);

// pdb: hkaRagdollRigidBodyController::driveToPose | hkaRagdollRigidBodyController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: deltaTime, poseLocal, worldFromModel, stressOut
void Cls::FUN_0095b610(float a, Xf12* src, const Xf12& xf, int d)
{
    Loc m;
    m.q = unk28;
    m.x = xf;
    unk24 = (unk10 == sub18.n) ? unk0c : 0;
    if (unk34->unk0c != unk34->inner->count) {
        ScratchBuf buf(sub18.n);
        for (int i = 0; i < unk34->inner->count; i++) {
            int k = unk34->map[i];
            if (k >= 0)
                buf.data[k] = src[i];
        }
        m.p = buf.data;
        FUN_00a033a0(a, &m, &sub18, unk00, d);
        buf.Release();
    } else {
        m.p = src;
        FUN_00a033a0(a, &m, &sub18, unk00, d);
    }
}
}   // namespace f3m_0095b610

// @f3 0x00947770 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00947770 {
// Reconstruction of FUN_00947770 (0x00947770), __thiscall, 1 stack parameter.
//
// Shape read from the original:
//   * /GS + SEH frame, scope table 0xc754db, and a trylevel pair (0 -> -1) around
//     the constructor call, i.e. a real `new` expression whose memory must be
//     released if the constructor throws.
//   * the allocator is the thread memory block reached through TlsGetValue of
//     DAT_010f3170 (same idiom as the other matched functions in this workspace),
//     and it records the block size in the object before the constructor runs.
//   * four floats of the source are copied through a stack temporary into the
//     object at +0x20, and two more land at +0x30 / +0x34.
//   * a reference-count release of the new object is inlined at +4 / +6.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct S00cc4610_TlsMem
{
    void* FUN_008f6d30(int iNumBytes, int iMemoryClass);
};

struct S00cc4610_In
{
    int   m_00;
    int   m_04;
    int   m_08;
    int   m_0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
};

struct __declspec(align(16)) S00cc4610_V16
{
    float f[4];
};

class FUN_009da8b0
{
  public:
    void* operator new(unsigned int uiSize)
    {
        S00cc4610_TlsMem* tm = (S00cc4610_TlsMem*)TlsGetValue(DAT_010f3170);
        FUN_009da8b0* p = (FUN_009da8b0*)tm->FUN_008f6d30(uiSize, 0x29);
        p->m_us04 = (unsigned short)uiSize;
        return p;
    }

    FUN_009da8b0(int a1, int a2, int a3);

    virtual void v00(int iFlag);   // slot 0 (0x00)

    unsigned short m_us04;    // 0x04
    short          m_us06;    // 0x06
    int            m_08;      // 0x08
    int            m_0c;      // 0x0c
    int            m_10;      // 0x10
    int            m_14;      // 0x14
    int            m_18;      // 0x18
    int            m_1c;      // 0x1c
    float          m_f20;     // 0x20
    float          m_f24;     // 0x24
    float          m_f28;     // 0x28
    float          m_f2c;     // 0x2c
    float          m_f30;     // 0x30
    float          m_f34;     // 0x34
    float          m_f38;     // 0x38
    float          m_f3c;     // 0x3c
};

class S00cc4610_Self
{
  public:
    void FUN_00947770(S00cc4610_In* in);

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
    virtual void v35(FUN_009da8b0* p);   // slot 35 (0x8c)
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
    virtual void v47(S00cc4610_In* p);   // slot 47 (0xbc)
};

// pdb: bhkAngularDashpotAction::Init | bhkAngularDashpotAction.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: arInfo
void S00cc4610_Self::FUN_00947770(S00cc4610_In* in)
{
    if (in)
    {
        FUN_009da8b0* r = new FUN_009da8b0(in->m_04, in->m_08, 0);
        r->m_f30 = in->m_f20;
        r->m_f34 = in->m_f24;
        S00cc4610_V16 v;
        v.f[0] = in->m_f10;
        v.f[1] = in->m_f14;
        v.f[2] = in->m_f18;
        v.f[3] = in->m_f1c;
        FUN_009da8b0* __restrict q = r;
        q->m_f20 = v.f[0];
        q->m_f24 = v.f[1];
        q->m_f28 = v.f[2];
        q->m_f2c = v.f[3];
        v35(r);
        if (r->m_us04 != 0)
        {
            if (--r->m_us06 == 0)
                r->v00(1);
        }
        v47(in);
    }
}
}   // namespace f3m_00947770

// @f3 0x00954940 (community match, verified in this file)
namespace c4_00954940 {

extern unsigned long DAT_010f3170;
extern void* DAT_00e7bfa8[];
extern void* DAT_00e7bf98[];
extern void* DAT_00e7bf8c[];
extern void* DAT_00e7bf74[];
extern void* DAT_00e7bf5c[];
extern void* DAT_00e7bf4c[];
extern void* DAT_00e7bf3c[];
extern void* DAT_00e7bf00[];
extern void* DAT_00e7bf10[];
extern void* DAT_00de7434[];
extern void* DAT_00dcd094[];
extern void* DAT_00e7bef4[];
extern void* DAT_00dcc494[];

struct ThreadMemory
{
    void FUN_008f6d90(void* data, int bytes, int category) throw();
};
typedef ThreadMemory* (__stdcall* GetThreadMemoryFn)(unsigned long index);
extern GetThreadMemoryFn const DAT_00d9b080;

struct Entity;

template <class T>
struct Array
{
    T* data;
    int size;
    int capacityAndFlags;
    ~Array() throw() { Free(); }
    void Free()
    {
        if ((capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = capacityAndFlags & 0x3fffffff;
            ThreadMemory* memory = (ThreadMemory*)f3m_0095aac0::TlsGetValue(DAT_010f3170);
            memory->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};

struct ReferencedObject
{
    void** vtable;
    unsigned short memSize;
    short referenceCount;
    ~ReferencedObject() throw() { vtable = DAT_00dcc494; }
};

struct FUN_00954a30
{
    void** vtable;
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
    ~FUN_00954a30() throw();
};

struct Listener58 { void** vtable; ~Listener58() throw() { vtable = DAT_00e7bef4; } };
struct Listener5c { void** vtable; ~Listener5c() throw() { vtable = DAT_00dcd094; } };
struct Listener60 { void** vtable; ~Listener60() throw() { vtable = DAT_00de7434; } };
struct Listener64 { void** vtable; ~Listener64() throw() { vtable = DAT_00e7bf10; } };
struct Listener68 { void** vtable; ~Listener68() throw() { vtable = DAT_00e7bf00; } };

struct FUN_00954940 : ReferencedObject, FUN_00954a30, Listener58, Listener5c, Listener60, Listener64, Listener68
{
    Array<Entity*> m_entities;
    Array<Entity*> m_others;
    void FUN_00954710(Entity* entity) throw();
    ~FUN_00954940() throw();
};

// pdb: hkpPhysicsContext::~hkpPhysicsContext | hkpPhysicsContext.obj | fnv360_0822_retail, call_seq, medium
FUN_00954940::~FUN_00954940() throw()
{
    ReferencedObject::vtable = DAT_00e7bfa8;
    FUN_00954a30::vtable = DAT_00e7bf98;
    Listener58::vtable = DAT_00e7bf8c;
    Listener5c::vtable = DAT_00e7bf74;
    Listener60::vtable = DAT_00e7bf5c;
    Listener64::vtable = DAT_00e7bf4c;
    Listener68::vtable = DAT_00e7bf3c;
    for (int i = m_entities.size - 1; i >= 0; i--)
        FUN_00954710(m_entities.data[i]);
}

}

// @f3 0x00947c10 (community match, verified in this file)
namespace n947c10 {
extern unsigned long DAT_010f3170;
extern float DAT_00db8ea4;
extern char DAT_00e7a880;
struct Alloc { void* FUN_008f6d30(int size, int tag) throw(); };
extern Alloc* (__stdcall* DAT_00d9b080)(unsigned long);
using f3m_009479e0::RefObj_9479e0;
RefObj_9479e0* __cdecl FUN_0097a980(RefObj_9479e0* src, int arg) throw();
struct __declspec(novtable) Base {
    void* table;
    short m4;
    short refs;
    int m8;
    short mC;
    int m10;
    int m14;
    Base() throw() : refs(1), m8(0), mC(1) {}
};
struct Scale { float v; Scale() throw() : v(10.0f) {} };
struct __declspec(novtable) Mid : Base {
    RefObj_9479e0* owner;
    int m1c;
    Scale m20;
    char m24;
    char m25;
    int m28;
    Mid() throw() { owner = 0; }
};
struct Obj : Mid {
    Obj() throw() { table = &DAT_00e7a880; m28 = 0; m24 = 0; m25 = 0; }
    static void* operator new(unsigned int size) {
        Alloc* a = DAT_00d9b080(DAT_010f3170);
        Obj* p = (Obj*)a->FUN_008f6d30(size, 0x2c);
        p->m4 = (short)size;
        return p;
    }
    void FUN_009479e0(RefObj_9479e0* o) throw();
};
}

struct C947c10 {
    int m0;
    n947c10::Obj* src;
    void* FUN_008fc3f0(n947c10::Obj* dst, int arg) throw();
    void* FUN_00947c10(n947c10::Obj* dst, int arg) throw();
};

// pdb: hkBreakableConstraintCinfo::CloneData | bhkBreakableConstraint.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apData, arCloneData
void* C947c10::FUN_00947c10(n947c10::Obj* dst, int arg) throw() {
    n947c10::Obj* s = src;
    if (!dst)
        dst = new n947c10::Obj;
    if (s->owner) {
        f3m_009479e0::RefObj_9479e0* r = n947c10::FUN_0097a980(s->owner, arg);
        if (r) {
            dst->FUN_009479e0(r);
            r->DecRef();
        }
    }
    float f = s->m20.v;
    dst->m20.v = f;
    char c = *(volatile char*)&s->m24;
    dst->m24 = c;
    return FUN_008fc3f0(dst, arg);
}

// @f3 0x009550e0 (community match, verified in this file)
namespace f3m_009550e0 {
// 0x009550e0: returns a bone's model space transform in a pose that keeps local and model space transforms with
// dirty flags per bone (hkaPose::calculateBoneModelSpace in Havok terms). Going up from the bone, every ancestor whose
// model transform is out of date is marked; a root that is out of date takes its local transform. Then, going back
// down, each marked bone gets its parent's model transform times its own local transform, and the marks are cleared.

namespace f3m_009550e0 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = v.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.w; }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);      // setMul
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    void FUN_008dbcd0(const hkQsTransform& other);     // assignment
    // this = t1 * t2
    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        // rotation and position go together
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);

        // scale goes apart
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
};

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline T& operator[](int i) { return m_data[i]; }
};

struct hkaSkeleton
{
    char* m_name;
    short* m_parentIndices;
};

class hkaPose
{
public:
    // per-bone flags
    enum
    {
        F_BONE_LOCAL_DIRTY = 0x1,
        F_BONE_MODEL_DIRTY = 0x2,
        F_BONE_INTERNAL_FLAG1 = 0x4,
        F_BONE_INTERNAL_FLAG2 = 0x8
    };

    __forceinline int isFlagOn(int boneIdx, unsigned int enumToCheck) const { return m_boneFlags[boneIdx] & enumToCheck; }
    __forceinline void setFlag(int boneIdx, unsigned int enumToCheck) const { m_boneFlags[boneIdx] |= enumToCheck; }
    __forceinline void clearFlag(int boneIdx, unsigned int enumToCheck) const { m_boneFlags[boneIdx] &= ~enumToCheck; }

    const hkQsTransform& hkaPose_calculateBoneModelSpace(int theBoneIdx) const;

    const hkaSkeleton* m_skeleton;
    mutable hkArray<hkQsTransform> m_localPose;
    mutable hkArray<hkQsTransform> m_modelPose;
    mutable hkArray<unsigned int> m_boneFlags;
};

// pdb: hkaPose::calculateBoneModelSpace | hkaPose.obj | fnv360_0822_retail, caller + bridge(call_gap|caller) + skyrim(objrun_prop), high
const hkQsTransform& hkaPose::hkaPose_calculateBoneModelSpace(int theBoneIdx) const
{
    // go up the chain until a bone with a valid model transform, marking the bones on the way
    int firstBoneInChain = theBoneIdx;

    while (isFlagOn(firstBoneInChain, F_BONE_MODEL_DIRTY))
    {
        const short parentIdx = m_skeleton->m_parentIndices[firstBoneInChain];

        if (parentIdx == -1)
        {
            // a root: model space is local space
            const hkQsTransform& rootLocal = m_localPose[firstBoneInChain];
            m_modelPose[firstBoneInChain].FUN_008dbcd0(rootLocal);
            clearFlag(firstBoneInChain, F_BONE_MODEL_DIRTY);
            break;
        }

        setFlag(firstBoneInChain, F_BONE_INTERNAL_FLAG2);
        firstBoneInChain = parentIdx;
    }

    // go back down, accumulating the transforms of the marked bones
    for (int boneIdx = firstBoneInChain + 1; boneIdx <= theBoneIdx; boneIdx++)
    {
        if (isFlagOn(boneIdx, F_BONE_INTERNAL_FLAG2))
        {
            const short parentIdx = m_skeleton->m_parentIndices[boneIdx];
            m_modelPose[boneIdx].setMul(m_modelPose[parentIdx], m_localPose[boneIdx]);
            clearFlag(boneIdx, F_BONE_INTERNAL_FLAG2 | F_BONE_MODEL_DIRTY);
        }
    }

    return m_modelPose[theBoneIdx];
}

}
}   // namespace f3m_009550e0

// @f3 0x00955d90 (community match, verified in this file)
namespace f3m_00955d90 {
// 0x00955d90: applies the skeleton's translation locks to a pose in model space (hkaPose::
// enforceSkeletonConstraintsModelSpace in Havok terms). After bringing the model space up to date, every bone with
// a locked translation is put back at its reference offset from its parent; its local transform is flagged as out of
// date, and so is the local transform of every bone whose parent was moved this way.

namespace f3m_00955d90 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = v.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.w; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline int getSize() const { return m_size; }
};

struct hkaBone
{
    char* m_name;
    bool m_lockTranslation;
};

struct hkaSkeleton
{
    char* m_name;
    short* m_parentIndices;
    int m_numParentIndices;
    hkaBone** m_bones;
    int m_numBones;
    hkQsTransform* m_referencePose;
    int m_numReferencePose;
};

class hkaPose
{
public:
    // per-bone flags
    enum
    {
        F_BONE_LOCAL_DIRTY = 0x1,
        F_BONE_MODEL_DIRTY = 0x2,
        F_BONE_INTERNAL_FLAG1 = 0x4,
        F_BONE_INTERNAL_FLAG2 = 0x8,
        F_BONE_INTERNAL_FLAG3 = 0x10,
        M_BONE_INTERNAL_FLAGS = F_BONE_INTERNAL_FLAG1 | F_BONE_INTERNAL_FLAG2 | F_BONE_INTERNAL_FLAG3
    };

    __forceinline int isFlagOn(int boneIdx, unsigned int enumToCheck) const { return m_boneFlags[boneIdx] & enumToCheck; }
    __forceinline void setFlag(int boneIdx, unsigned int enumToCheck) const { m_boneFlags[boneIdx] |= enumToCheck; }
    __forceinline void clearFlag(int boneIdx, unsigned int enumToCheck) const { m_boneFlags[boneIdx] &= ~enumToCheck; }
    __forceinline void clearInternalFlags() const
    {
        const int numBones = m_boneFlags.getSize();
        for (int i = 0; i < numBones; i++)
        {
            clearFlag(i, M_BONE_INTERNAL_FLAGS);
        }
    }

    void hkaPose_syncModelSpace() const;      // syncModelSpace
    void FUN_00955d90();

    const hkaSkeleton* m_skeleton;
    mutable hkArray<hkQsTransform> m_localPose;
    mutable hkArray<hkQsTransform> m_modelPose;
    mutable hkArray<unsigned int> m_boneFlags;
    mutable bool m_modelInSync;
    mutable bool m_localInSync;
};

void hkaPose::FUN_00955d90()
{
    const int numBones = m_skeleton->m_numBones;

    hkaPose_syncModelSpace();

    for (int boneIdx = 0; boneIdx < numBones; boneIdx++)
    {
        const short parentIdx = m_skeleton->m_parentIndices[boneIdx];
        const hkaBone* bone = m_skeleton->m_bones[boneIdx];

        if (bone->m_lockTranslation)
        {
            const hkVector4& localTranslation = m_skeleton->m_referencePose[boneIdx].m_translation;

            if (parentIdx != -1)
            {
                const hkQsTransform& parentModelSpace = m_modelPose[parentIdx];
                m_modelPose[boneIdx].m_translation.setRotatedDir(parentModelSpace.m_rotation, localTranslation);
                m_modelPose[boneIdx].m_translation.add4(parentModelSpace.m_translation);
            }
            else
            {
                m_modelPose[boneIdx].m_translation = localTranslation;
            }

            // the bone moved: its local transform is out of date, and so will its children's be
            setFlag(boneIdx, F_BONE_LOCAL_DIRTY);
            setFlag(boneIdx, F_BONE_INTERNAL_FLAG1);
        }
        else
        {
            if (parentIdx != -1 && isFlagOn(parentIdx, F_BONE_INTERNAL_FLAG1))
            {
                setFlag(boneIdx, F_BONE_LOCAL_DIRTY);
            }
        }
    }

    clearInternalFlags();
}

}
}   // namespace f3m_00955d90

// @f3 0x00955370 (community match, verified in this file)
namespace f3m_00955370 {
// 0x00955370: brings every bone's local space transform up to date in a pose that keeps local and model space
// transforms with dirty flags per bone (hkaPose::syncLocalSpace in Havok terms): a bone whose local transform is out
// of date gets the inverse of its parent's model transform times its own model transform, or its model transform
// when it has no parent.
//
// The quaternion product (0x008d3290) is written out here as well: it is an inline function the compiler chose not
// to expand, and the code of this function depends on the compiler having seen its body (it knows the call leaves
// the inverse transform untouched and keeps using the inverse scale it computed before the call).

namespace f3m_00955370 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = v.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    // this = direction rotated by the inverse of quat
    __forceinline void setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.w; }
    __forceinline void setInverse(const hkQuaternion& q) { m_vec.setNeg3(q.getImag()); }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);      // setMul
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// this = q0 * q1 (0x008d3290)
inline void hkQuaternion::FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1)
{
    hkVector4 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.getReal(), q1.getImag());
    vec.addMul4(q1.getReal(), q0.getImag());
    hkReal w = q0.getReal() * q1.getReal() - q0.getImag().dot3(q1.getImag());
    m_vec = vec;
    m_vec(3) = w;
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    // this = t^-1
    __forceinline void setInverse(const hkQsTransform& t)
    {
        m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
        m_translation.setNeg4(m_translation);
        m_rotation.setInverse(t.m_rotation);
        hkVector4 invScale;
        invScale.set(1.0f / t.m_scale(0), 1.0f / t.m_scale(1), 1.0f / t.m_scale(2));
        m_scale = invScale;
    }
    // this = t1 * t2
    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        // rotation and position go together
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);

        // scale goes apart
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
    // this = t1^-1 * t2
    __forceinline void setMulInverseMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkQsTransform h;
        h.setInverse(t1);
        setMul(h, t2);
    }
};

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline T& operator[](int i) { return m_data[i]; }
};

struct hkaSkeleton
{
    char* m_name;
    short* m_parentIndices;
    int m_numParentIndices;
    struct hkaBone** m_bones;
    int m_numBones;
};

class hkaPose
{
public:
    // per-bone flags
    enum
    {
        F_BONE_LOCAL_DIRTY = 0x1,
        F_BONE_MODEL_DIRTY = 0x2
    };

    __forceinline int isFlagOn(int boneIdx, unsigned int enumToCheck) const { return m_boneFlags[boneIdx] & enumToCheck; }
    __forceinline void clearFlag(int boneIdx, unsigned int enumToCheck) const { m_boneFlags[boneIdx] &= ~enumToCheck; }

    void hkaPose_syncLocalSpace() const;

    const hkaSkeleton* m_skeleton;
    mutable hkArray<hkQsTransform> m_localPose;
    mutable hkArray<hkQsTransform> m_modelPose;
    mutable hkArray<unsigned int> m_boneFlags;
    mutable bool m_modelInSync;
    mutable bool m_localInSync;
};

// pdb: hkaPose::syncLocalSpace | hkaPose.obj | fnv360_0822_retail, call_gap + bridge(call_gap|caller_sim) + skyrim(objopen_prop), high
void hkaPose::hkaPose_syncLocalSpace() const
{
    if (m_localInSync)
    {
        return;
    }

    const int numBones = m_skeleton->m_numBones;

    for (int b = 0; b < numBones; b++)
    {
        if (isFlagOn(b, F_BONE_LOCAL_DIRTY))
        {
            const hkQsTransform& model = m_modelPose[b];
            const short parentIdx = m_skeleton->m_parentIndices[b];

            if (parentIdx != -1)
            {
                const hkQsTransform& parentModel = m_modelPose[parentIdx];
                m_localPose[b].setMulInverseMul(parentModel, model);
            }
            else
            {
                m_localPose[b] = model;
            }

            clearFlag(b, F_BONE_LOCAL_DIRTY);
        }
    }

    m_localInSync = true;
}

}
}   // namespace f3m_00955370

// @f3 0x009598b0 (community match, verified in this file)
#include <math.h>
namespace f3m_009598b0 {

// 0x009598b0: sets up the two body frames of a ragdoll constraint from pivots and axes given in the space of each
// body (hkpRagdollConstraintData::setInBodySpace in Havok terms). For each body the twist axis and the plane axis
// are copied and normalized, their cross product completes the frame, and the pivot becomes the frame's origin.
// The motors' target frame starts out as the rotation of body B's frame.

namespace f3m_009598b0 {

typedef float hkReal;

inline hkReal hkSqrt(hkReal r) { return sqrtf(r); }
inline hkReal hkSqrtInverse(hkReal r) { return 1.0f / hkSqrt(r); }

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkReal lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }
    // 1 / length, or 0 for a zero vector
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 ? hkSqrtInverse(l2) : 0;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline hkVector4& getColumn(int i) { return (&m_rotation.m_col0)[i]; }
    __forceinline hkRotation& getRotation() { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }
};

// constraint atom holding one frame per body
struct hkpSetLocalTransformsConstraintAtom
{
    unsigned short m_type;
    hkTransform m_transformA;
    hkTransform m_transformB;
};

// constraint atom driving the three ragdoll motors towards a target frame
struct hkpRagdollMotorConstraintAtom
{
    unsigned short m_type;
    unsigned char m_isEnabled;
    short m_initializedOffset;
    short m_previousTargetAnglesOffset;
    hkRotation m_target_bRca;
};

struct hkpRagdollConstraintData
{
    // columns of each frame
    enum Axis
    {
        AXIS_TWIST = 0,
        AXIS_PLANES = 1,
        AXIS_CROSS_PRODUCT = 2
    };

    void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_userData;
    hkpSetLocalTransformsConstraintAtom m_transforms;
    hkpRagdollMotorConstraintAtom m_ragdollMotors;

    void FUN_009598b0(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& planeAxisA, const hkVector4& planeAxisB, const hkVector4& twistAxisA, const hkVector4& twistAxisB);
};

void hkpRagdollConstraintData::FUN_009598b0(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& planeAxisA, const hkVector4& planeAxisB, const hkVector4& twistAxisA, const hkVector4& twistAxisB)
{
    hkVector4* baseA = &m_transforms.m_transformA.getColumn(0);
    baseA[AXIS_TWIST] = twistAxisA; baseA[AXIS_TWIST].normalize3();
    baseA[AXIS_PLANES] = planeAxisA; baseA[AXIS_PLANES].normalize3();
    baseA[AXIS_CROSS_PRODUCT].setCross(baseA[AXIS_TWIST], baseA[AXIS_PLANES]);
    m_transforms.m_transformA.getTranslation() = pivotA;

    hkVector4* baseB = &m_transforms.m_transformB.getColumn(0);
    baseB[AXIS_TWIST] = twistAxisB; baseB[AXIS_TWIST].normalize3();
    baseB[AXIS_PLANES] = planeAxisB; baseB[AXIS_PLANES].normalize3();
    baseB[AXIS_CROSS_PRODUCT].setCross(baseB[AXIS_TWIST], baseB[AXIS_PLANES]);
    m_transforms.m_transformB.getTranslation() = pivotB;

    m_ragdollMotors.m_target_bRca = m_transforms.m_transformB.getRotation();
}

}
}   // namespace f3m_009598b0

// @f3 0x0095bbe0 (community match, verified in this file)
#include <math.h>
extern float DAT_00de6e60;
namespace f3m_0095bbe0 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace z95bbe0 {
struct B {bool value;B(){} B(bool b):value(b){} operator bool()const{return value;}};
// Fake match: the scalar wrapper preserves the original compiler's temporary rounding and numbering.
struct Scalar {float value;Scalar(float f):value(f){}};
struct __declspec(align(16)) V {
 float x,y,z,w;
 V(){} __forceinline V& operator=(const V& b){x=b.x;y=b.y;z=b.z;w=b.w;return *this;} V(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
 // Fake match: these equivalent scale parameter forms and the a/scale/b order steer x87 operand selection.
 __forceinline void SetAddMul(const V& a,const Scalar& s,const V& b){x=a.x+b.x*s.value;y=a.y+b.y*s.value;z=a.z+b.z*s.value;w=a.w+b.w*s.value;} __forceinline void SetAddMulV(const V& a,const V& b,Scalar s){x=a.x+b.x*s.value;y=a.y+b.y*s.value;z=a.z+b.z*s.value;w=a.w+b.w*s.value;} __forceinline void SetAddMulF(const V& a,const V& b,float s){x=a.x+b.x*s;y=a.y+b.y*s;z=a.z+b.z*s;w=a.w+b.w*s;}
 __forceinline void SetSub(const V& a,const V& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
 __forceinline void SetAbs(const V& a){x=(float)fabs(a.x);y=(float)fabs(a.y);z=(float)fabs(a.z);w=(float)fabs(a.w);}
 // Fake match: y precedes x to preserve the measured x87 dot-product ordering.
 __forceinline float Dot3(const V& b)const{return y*b.y+x*b.x+z*b.z;}
 __forceinline unsigned LessEqual(float e)const{return (x<=e?8:0)|(y<=e?4:0)|(z<=e?2:0)|(w<=e?1:0);}
};
struct Shape {virtual void V00();virtual B Cast(const V&,const V&,float&,V&);};
struct Owner {
 int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
 V direction;
 int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78;
 float radius,depth;
 B FUN_0095bbe0(Shape*,const V&,const V&,V&,V&);
};
B Owner::FUN_0095bbe0(Shape* shape,const V& from,const V& to,V& point,V& normal) {
 float r=radius;
 float d=depth;
 float extent=r+d;
 float firstFraction=DAT_00de6e60;
 V firstNormal;
 B first;
 {
  V fromPositive,fromNegative;
  fromNegative.SetAddMulF(from,direction,-d);
  fromPositive.SetAddMul(from,r,direction);
  first=shape->Cast(fromPositive,fromNegative,firstFraction,firstNormal);
 }
 float secondFraction=DAT_00de6e60;
 B second=false;
 V delta;
 delta.SetSub(to,from);
 delta.SetAbs(delta);
 V secondNormal;
 if((delta.LessEqual(0.001f)&14)!=14) {
  V toPositive,toNegative;
  toNegative.SetAddMulV(to,direction,-d);
  toPositive.SetAddMul(to,r,direction);
  float castFraction;
  second=shape->Cast(toPositive,toNegative,castFraction,secondNormal);
  if(second) {
   float dot=direction.Dot3(secondNormal);
   if(dot<=0.0f) second=false;
   else {
    V segment,intersection;
    segment.SetSub(toNegative,toPositive);
    intersection.SetAddMul(toPositive,castFraction,segment);
    V startPositive;
    startPositive.SetAddMul(from,r,direction);
    float plane=-intersection.Dot3(secondNormal);
    float numerator=-(startPositive.Dot3(secondNormal)+plane);
    float denominator=-extent*dot;
    float quotient=numerator/denominator;
    secondFraction=quotient;
   }
  }
 }
 if(!first && !second) return B(false);
 float fraction;
 if(first && !(firstFraction>secondFraction)) {fraction=firstFraction;normal=firstNormal;}
 else {fraction=secondFraction;normal=secondNormal;}
 float scaled=fraction*extent-r;
 float displacement=-scaled;
 point.SetAddMulF(from,direction,displacement);
 return B(true);
}
}
}   // namespace f3m_0095bbe0

// @f3 0x00956b90 (community match, verified in this file)
namespace f3m_00956b90 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_00956b90 {

typedef float hkReal;

struct hkQuaternion;

struct __declspec(align(16)) hkVector4 {
    hkReal x, y, z, w;

    hkVector4& operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
    void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f) { x = a; y = b; z = c; w = d; }
    void setAdd4(const hkVector4& a, const hkVector4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    // Fake match: six optimized-away scalar locals adjust operand-symbol ranks for the second product.
    void setMul4(hkReal s, const hkVector4& v) { hkReal unused0 = 0.0f; hkReal unused1 = 0.0f; hkReal unused2 = 0.0f; hkReal unused3 = 0.0f; hkReal unused4 = 0.0f; hkReal unused5 = 0.0f; hkReal factor = s; x = factor * v.x; y = factor * v.y; z = factor * v.z; w = factor * v.w; }
    void addMul4(hkReal s, const hkVector4& v) { hkReal factor = s; x += factor * v.x; y += factor * v.y; z += factor * v.z; w += factor * v.w; }
    void setNeg4(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
    // Fake match: component accessor layers select the floating operand ranks.
    hkReal dot3(const hkVector4& a) const { return (*this)(0) * a(0) + (*this)(1) * a(1) + (*this)(2) * a(2); }
    const hkReal& operator()(int component) const { return (&x)[component]; }
    void setCross(const hkVector4& a, const hkVector4& b) {
        const hkReal nx = a(1) * b(2) - a(2) * b(1);
        const hkReal ny = a(2) * b(0) - a(0) * b(2);
        const hkReal nz = a(0) * b(1) - a(1) * b(0);
        set(nx, ny, nz, 0.0f);
    }
    void setReciprocal3(const hkVector4& v) {
        x = 1.0f / v.x;
        y = 1.0f / v.y;
        z = 1.0f / v.z;
        w = 1.0f;
    }
    __forceinline void copyXYZ0(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = 0.0f; }
    void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    void setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion {
    hkVector4 m_vec;
    const hkVector4& getImag() const { return m_vec; }
    hkReal getReal() const { return m_vec.w; }
    void setInverse(const hkQuaternion& q) { m_vec.x = -q.m_vec.x; m_vec.y = -q.m_vec.y; m_vec.z = -q.m_vec.z; m_vec.w = q.m_vec.w; }
    __declspec(noinline) void FUN_008d3290(const hkQuaternion& a, const hkQuaternion& b) {
        hkVector4 imaginary;
        imaginary.setCross(a.m_vec, b.m_vec);
        imaginary.addMul4(a.m_vec.w, b.m_vec);
        imaginary.addMul4(b.m_vec.w, a.m_vec);
        const float real = a.m_vec.w * b.m_vec.w - a.m_vec.dot3(b.m_vec);
        m_vec.x = imaginary.x;
        m_vec.y = imaginary.y;
        m_vec.z = imaginary.z;
        m_vec.w = real;
    }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction) {
    const hkVector4& qv = quat.getImag();
    hkReal qreal = quat.getReal();
    hkReal q2minus1 = qreal * qreal - 0.5f;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    hkReal imagDotDir = qv.dot3(direction);
    ret.addMul4(imagDotDir, qv);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(qv, direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction) {
    hkReal qreal = quat.getReal();
    hkReal q2minus1 = qreal * qreal - 0.5f;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    hkReal imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

struct hkQsTransform {
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    __forceinline void setInverse(const hkQsTransform& t) {
        m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
        m_translation.setNeg4(m_translation);
        m_rotation.setInverse(t.m_rotation);
        hkVector4 reciprocal;
        reciprocal.setReciprocal3(t.m_scale);
        m_scale.copyXYZ0(reciprocal);
    }
    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2) {
        hkVector4 temp;
        temp.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(temp, t1.m_translation);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
    __forceinline void setMulInverseMul(const hkQsTransform& a, const hkQsTransform& b) {
        hkQsTransform h;
        h.setInverse(a);
        setMul(h, b);
    }
};

struct hkaSkeleton {
    const char* m_name;
    const short* m_parentIndices;
    int m_numParentIndices;
    int* m_bones;
    int m_numBones;
};

enum {
    F_BONE_LOCAL_DIRTY = 1,
    F_BONE_MODEL_DIRTY = 2,
    F_BONE_INTERNAL_FLAG1 = 4
};

template<class T> struct PoseArray {
        T* data;
        int size;
        int capacity;
        __forceinline T& operator[](int i) { return data[i]; }
        __forceinline const T& operator[](int i) const { return data[i]; }
    };
    
struct PoseBool {
        char value;
        PoseBool& operator=(bool b) { value = static_cast<char>(b); return *this; }
    };
    
struct hkaPose {
    const hkaSkeleton* m_skeleton;
    PoseArray<hkQsTransform> m_localPose;
    PoseArray<hkQsTransform> m_modelPose;
    PoseArray<unsigned int> m_boneFlags;
    PoseBool m_modelInSync;
    PoseBool m_localInSync;

    const hkQsTransform& hkaPose_calculateBoneModelSpace(int boneIdx);

    unsigned int isFlagOn(int i, unsigned int f) const { return m_boneFlags[i] & f; }
    __forceinline const hkQsTransform& getBoneModelSpace(int i) {
        if (!(m_boneFlags[i] & F_BONE_MODEL_DIRTY)) {
            return m_modelPose[i];
        } else {
            return hkaPose_calculateBoneModelSpace(i);
        }
    }

    __forceinline const hkQsTransform& localTransform(int i) {
        if (!(m_boneFlags[i] & F_BONE_LOCAL_DIRTY)) return m_localPose[i];
        const hkQsTransform& model = m_modelPose[i];
        const short parent = m_skeleton->m_parentIndices[i];
        if (parent != -1) {
            const hkQsTransform& parentModel = getBoneModelSpace(parent);
            m_localPose[i].setMulInverseMul(parentModel, model);
        } else {
            m_localPose[i] = model;
        }
        m_boneFlags[i] &= ~F_BONE_LOCAL_DIRTY;
        return m_localPose[i];
    }

    __forceinline void makeFirstChildrenModelSpace(int boneIdx) {
        int numBones = m_skeleton->m_numBones;
        for (int i = boneIdx + 1; i < numBones; ++i) {
            short parentId = m_skeleton->m_parentIndices[i];
            if (parentId == boneIdx) {
                getBoneModelSpace(i);
                m_boneFlags[i] = F_BONE_LOCAL_DIRTY;
                m_localInSync = 0;
            }
        }
    }

    __forceinline void makeAllChildrenLocalSpace(int boneIdx) {
        int numBones = m_skeleton->m_numBones;
        m_boneFlags[boneIdx] |= F_BONE_INTERNAL_FLAG1;
        for (int i = boneIdx + 1; i < numBones; ++i) {
            short parentId = m_skeleton->m_parentIndices[i];
            if (m_boneFlags[parentId] & F_BONE_INTERNAL_FLAG1) {
                localTransform(i);
                m_boneFlags[i] |= F_BONE_INTERNAL_FLAG1;
                m_modelInSync = 0;
            }
        }
        for (int i = boneIdx + 1; i < numBones; ++i) {
            unsigned int& f = m_boneFlags[i];
            if (f & F_BONE_INTERNAL_FLAG1) {
                f = (f & ~F_BONE_INTERNAL_FLAG1) | F_BONE_MODEL_DIRTY;
            }
        }
    }

    hkQsTransform& FUN_00956b90(int boneIdx, int propagate);
};

hkQsTransform& hkaPose::FUN_00956b90(int boneIdx, int propagate) {
    if (propagate == 0) {
        makeFirstChildrenModelSpace(boneIdx);
    } else {
        makeAllChildrenLocalSpace(boneIdx);
    }
    getBoneModelSpace(boneIdx);
    m_boneFlags[boneIdx] = F_BONE_LOCAL_DIRTY;
    m_localInSync = false;
    return m_modelPose[boneIdx];
}

}
}   // namespace f3m_00956b90

// @f3 0x0094dae0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern int FUN_00dcc864;
extern int DAT_00e7b1fc;
namespace f3m_0094dae0 {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
namespace s94d {

struct S0094dae0_Mem {
    void* FUN_008f6d30(unsigned int size, int cls);
    static S0094dae0_Mem& getInstance() { return *(S0094dae0_Mem*)FUN_00d9b080(DAT_010f3170); }
};

struct S0094dae0_Scale {
    float x, y, z, w;
    S0094dae0_Scale(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

struct __declspec(align(16)) S0094dae0_Vec4 {
    float x, y, z, w;
    S0094dae0_Vec4() {}
    S0094dae0_Vec4(const S0094dae0_Vec4& o) { float* d = &x; const float* s = &o.x; d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3]; }
    void operator=(const S0094dae0_Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    void mul4(const S0094dae0_Scale& o) { x *= o.x; y *= o.y; z *= o.z; w *= o.w; }
};

struct S0094dae0_Ref {
    void** vtbl;
    unsigned short memSize04;
    short refs06;
    S0094dae0_Ref() { refs06 = 1; }
    void addReference() { if (memSize04 != 0) ++refs06; }
    void removeReference() {
        if (memSize04 != 0) {
            --refs06;
            if (refs06 == 0) ((void (__thiscall*)(void*, int))vtbl[0])(this, 1);
        }
    }
};

struct S0094dae0_Shape : S0094dae0_Ref {
    int unk08;
    int unk0c;
    S0094dae0_Vec4 v10;
    int unk20;
    int unk24;
    int unk28;
};

struct S0094dae0_A : S0094dae0_Ref {
    int unk08;
    int unk0c;
    S0094dae0_Vec4 v10;
    int unk20;
    int unk24;
    int unk28;
    static void* operator new(unsigned int n) {
        S0094dae0_Ref* b = (S0094dae0_Ref*)S0094dae0_Mem::getInstance().FUN_008f6d30(n, 0x28);
        b->memSize04 = (unsigned short)n;
        return b;
    }
    S0094dae0_A(const S0094dae0_Vec4& v, int a, int b);
};

struct S0094dae0_Name { int unk00; int unk04; int unk08; int type0c; };
struct S0094dae0_Name2 { int unk00; };
struct S0094dae0_Thing : S0094dae0_Name, S0094dae0_Name2 { };

struct S0094dae0_BBase : S0094dae0_Ref {
    int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    S0094dae0_BBase(S0094dae0_Thing* t, S0094dae0_A* a);
};

struct S0094dae0_B : S0094dae0_BBase {
    S0094dae0_Shape* ref40;
    int unk44; int unk48; int unk4c;
    static void* operator new(unsigned int n) {
        S0094dae0_Ref* b = (S0094dae0_Ref*)S0094dae0_Mem::getInstance().FUN_008f6d30(n, 0x27);
        b->memSize04 = (unsigned short)n;
        return b;
    }
    static void operator delete(void* p);
    S0094dae0_B(S0094dae0_Thing* t, S0094dae0_A* a, S0094dae0_Shape* s);
};

struct S0094dae0_Tmp {
    S0094dae0_Vec4 v00;
    int unk10; int unk14; int unk18;
    unsigned short unk1c; unsigned char flag1e; unsigned char unk1f;
    int unk20; int unk24; int unk28; int unk2c;
    S0094dae0_Tmp();
};

struct S0094dae0_Param {
    int unk00;
    S0094dae0_Thing* name04;
    S0094dae0_Shape* node08;
    float scale0c;
};

S0094dae0_Shape* __cdecl FUN_009e2740(S0094dae0_Name2* nm, S0094dae0_Tmp* t, int z);


inline S0094dae0_A::S0094dae0_A(const S0094dae0_Vec4& v, int a, int b)
{
    vtbl = (void**)&FUN_00dcc864;
    v10 = v;
    unk24 = b;
    unk20 = a;
    unk28 = b | 0x80000000;
}

inline S0094dae0_B::S0094dae0_B(S0094dae0_Thing* t, S0094dae0_A* a, S0094dae0_Shape* s)
    : S0094dae0_BBase(t, a)
{
    vtbl = (void**)&DAT_00e7b1fc;
    ref40 = s;
    if (s) s->addReference();
}

struct S0094dae0_Owner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void AddB(S0094dae0_B* b);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8();
    virtual void Finish(S0094dae0_Param* p);
    void FUN_0094dae0(S0094dae0_Param* p);
};
}
using namespace s94d;

void S0094dae0_Owner::FUN_0094dae0(S0094dae0_Param* p)
{
    if (p) {
        if (p->node08 == 0) {
            S0094dae0_Tmp tmp;
            if (p->name04->type0c == 0xf) tmp.flag1e = 1;
            p->node08 = FUN_009e2740(p->name04, &tmp, 0);
        }
        S0094dae0_Vec4 v = p->node08->v10;
        v.mul4(S0094dae0_Scale(p->scale0c, p->scale0c, p->scale0c, 1.0f / p->scale0c));
        S0094dae0_A* a = new S0094dae0_A(v, p->node08->unk20, p->node08->unk24);
        S0094dae0_B* b = new S0094dae0_B(p->name04, a, p->node08);
        a->removeReference();
        AddB(b);
        b->removeReference();
        Finish(p);
    }
}
}   // namespace f3m_0094dae0

// @f3 0x0094faa0 (community match, verified in this file)
namespace S94faa0 {
struct Heap {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
}
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089e890(void* p);

inline void* operator new[](unsigned int size, S94faa0::Heap& heap) { return heap.FUN_0086b930(size); }
inline void operator delete[](void* p, S94faa0::Heap& heap) { heap.FUN_0086ba60(p); }

inline void* S94faa0_AlignedAlloc(unsigned int size)
{
    unsigned char* memory = (unsigned char*)S94faa0::DAT_01090a78.FUN_0086b930(size + 16);
    unsigned char pad = (unsigned char)(16 - ((unsigned char)(unsigned int)memory & 0xf));
    memory += pad;
    memory[-1] = pad;
    return memory;
}
inline void S94faa0_AlignedFree(void* p)
{
    unsigned char* q = (unsigned char*)p;
    if (q) S94faa0::DAT_01090a78.FUN_0086ba60(q - q[-1]);
}

struct S94faa0_RefObject {
    unsigned int m_uiRefCount;
    S94faa0_RefObject();
    virtual ~S94faa0_RefObject();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p) { FUN_0089e890(p); }
};

struct S94faa0_Extra {
    int unk00;
    int unk04;
    void Init(int first, int second) { unk04 = second; unk00 = first; }
    static void* operator new(unsigned int size) { return S94faa0_AlignedAlloc(size); }
    static void operator delete(void* p) { S94faa0_AlignedFree(p); }
};

struct S94faa0_Strip {
    unsigned int m_uiNumVerts;
    float* m_pVerts;
    unsigned int m_uiNumTris;
    unsigned short* m_pIndices;
    S94faa0_Extra* m_pExtra;
    S94faa0_Strip();
    ~S94faa0_Strip();
    static void* operator new[](unsigned int size) { return S94faa0::DAT_01090a78.FUN_0086b930(size); }
    static void operator delete[](void* p) { S94faa0::DAT_01090a78.FUN_0086ba60(p); }
};

struct S94faa0_StripSet : S94faa0_RefObject {
    unsigned int m_uiCount;
    S94faa0_Strip* m_pStrips;
    S94faa0_StripSet() { m_uiCount = 0; m_pStrips = 0; }
    virtual ~S94faa0_StripSet();
};

struct S94faa0_Shape {
    int unk00;
    int unk04;
    float f08;
    int unk0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    S94faa0_Shape(S94faa0_StripSet* set);
    static void* operator new(unsigned int size) { return S94faa0_AlignedAlloc(size); }
    static void operator delete(void* p) { S94faa0_AlignedFree(p); }
};

struct S94faa0_Tri {
    unsigned short v0;
    unsigned short v1;
    unsigned short v2;
    unsigned short unk06;
};

struct S94faa0_Item {
    int unk00;
    unsigned int m_uiNumVerts;
    int unk08;
};

struct S94faa0_Point3 {
    float x;
    float y;
    float z;
};

struct S94faa0_Data {
    int unk00;
    int unk04;
    unsigned short m_usNumTris;
    unsigned short unk0A;
    int unk0C;
    unsigned short m_usNumItems;
    unsigned short unk12;
    S94faa0_Tri* m_pTris;
    S94faa0_Point3* m_pVerts;
    int unk1C;
    int unk20;
    S94faa0_Item* m_pItems;
};

struct S94faa0_Source {
    int unk00;
    S94faa0_Data* m_pData;
    float f08;
    int unk0C;
    float f10;
    float f14;
    float f18;
    float f1C;
};

class S94faa0_UShortArrayData {
public:
    S94faa0_UShortArrayData(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = (unsigned short*)FUN_0089eb90(sizeof(unsigned short) * m_usMaxSize);
        else
            m_pBase = 0;
    }
    ~S94faa0_UShortArrayData() { FUN_0089e890(m_pBase); }

    unsigned short* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class S94faa0_UShortArray : public S94faa0_UShortArrayData {
public:
    S94faa0_UShortArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : S94faa0_UShortArrayData(uiMaxSize, uiGrowBy) {}
    virtual unsigned int GetAllocatedSize() const;
    unsigned int GetSize() const { return m_usSize; }
    __declspec(noinline) void FUN_008243d0(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const unsigned short& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const unsigned short& element)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_008243d0(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const unsigned short& element) { return SetAtGrow(m_usSize, element); }
    void RemoveAll()
    {
        unsigned short* pBase = m_pBase;
        unsigned short usSize = m_usSize;
        for (unsigned short i = 0; i < usSize; i++)
            pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }

};

void* __cdecl FUN_0089e810(unsigned int size);
__declspec(noinline) void S94faa0_UShortArray::FUN_008243d0(unsigned int uiSize)
{
    if (uiSize == m_usMaxSize) return;
    if (uiSize < m_usSize) {
        for (unsigned short i = (unsigned short)uiSize; i < m_usSize; ++i) {
            if (m_pBase[i] != 0) {
                m_pBase[i] = 0;
                --m_usESize;
            }
        }
        m_usSize = (unsigned short)uiSize;
    }
    unsigned short* old = m_pBase;
    m_usMaxSize = (unsigned short)uiSize;
    if (uiSize > 0) {
        m_pBase = (unsigned short*)FUN_0089e810(2 * m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; ++i)
            m_pBase[i] = old[i];
        for (unsigned short i = m_usSize; i < m_usMaxSize; ++i)
            m_pBase[i] = 0;
    } else {
        m_pBase = 0;
    }
    FUN_0089e890(old);
}

extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int n);

struct S94faa0_Owner {
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
    virtual void v2a();
    virtual void v2b();
    virtual void SetShape(S94faa0_Shape* shape);
    void FUN_0094faa0(S94faa0_Source* src);
};

void S94faa0_Owner::FUN_0094faa0(S94faa0_Source* src)
{
    if (!src)
        return;

    S94faa0_Data* data = src->m_pData;
    unsigned short usVertBase = 0;
    unsigned short usTri = 0;

    S94faa0_StripSet* set = new S94faa0_StripSet;
    S94faa0_Strip* strips = new S94faa0_Strip[data->m_usNumItems];
    set->m_pStrips = strips;
    set->m_uiCount = data->m_usNumItems;

    S94faa0_UShortArray indices;
    for (int i = 0; i < data->m_usNumItems; i++)
    {
        unsigned int uiTris = 0;
        S94faa0_Item* item = &data->m_pItems[i];
        S94faa0_Tri* tri = &data->m_pTris[usTri];
        bool bDone = usTri >= data->m_usNumTris;
        while (!bDone)
        {
            if (tri->v0 >= item->m_uiNumVerts + usVertBase)
                break;
            unsigned short a = tri->v0;
            unsigned short b = tri->v1;
            unsigned short c = tri->v2;
            indices.Add((unsigned short)(a - usVertBase));
            indices.Add((unsigned short)(b - usVertBase));
            indices.Add((unsigned short)(c - usVertBase));
            usTri++;
            uiTris++;
            tri = &data->m_pTris[usTri];
            bDone = usTri >= data->m_usNumTris;
        }

        unsigned short usNumVerts = 0;
        if (uiTris > 0)
        {
            usNumVerts = (unsigned short)item->m_uiNumVerts;
            S94faa0_Point3* verts = (S94faa0_Point3*)new (S94faa0::DAT_01090a78) float[usNumVerts * 3 + 3];
            for (unsigned short k = usVertBase; k < usVertBase + usNumVerts; k++)
            {
                verts[k - usVertBase].x = data->m_pVerts[k].x;
                verts[k - usVertBase].y = data->m_pVerts[k].y;
                verts[k - usVertBase].z = data->m_pVerts[k].z;
            }
            unsigned short* idx = new (S94faa0::DAT_01090a78) unsigned short[indices.GetSize()];
            unsigned int byteCount = indices.GetSize() * sizeof(unsigned short);
            memcpy(idx, indices.m_pBase, byteCount);
            S94faa0_Extra* extra = (S94faa0_Extra*)S94faa0_AlignedAlloc(sizeof(S94faa0_Extra));
            extra->Init(data->m_pItems[i].unk00, data->m_pItems[i].unk08);
            S94faa0_Strip& strip = strips[i];
            strip.m_pExtra = extra;
            strip.m_pVerts = (float*)verts;
            strip.m_pIndices = idx;
            strip.m_uiNumTris = uiTris;
            strip.m_uiNumVerts = usNumVerts;
        }
        else
        {
            set->m_uiCount--;
        }
        indices.RemoveAll();
        usVertBase += usNumVerts;
    }

    S94faa0_Shape* shape = new S94faa0_Shape(set);
    shape->f08 = src->f08;
    shape->f10 = src->f10;
    shape->f14 = src->f14;
    shape->f18 = src->f18;
    shape->f1C = src->f1C;
    SetShape(shape);
}

// @f3 0x0095de50 (community match, verified in this file)
namespace f3m_0095de50 {
// Matches under /MT /O2 /GS /EHsc /Gy: the pack lists /Od, but the target is optimised code
// (aligned frame, values kept in ebx/esi/edi across calls).
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
extern int DAT_010f3170;

typedef float hkReal;

// Havok's FPU scalar type: a one-float wrapper. Its temporaries are what store and reload
// qreal and q2minus1 as floats in the inlined rotations.
struct hkSimdReal
{
    hkReal m_real;
    __forceinline hkSimdReal(hkReal x) { m_real = x; }
    __forceinline operator hkReal() const { return m_real; }
};
typedef const hkSimdReal& hkSimdRealParameter;

struct __declspec(align(16)) hkQuadReal
{
    hkReal v[4];
};

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = rs;
        (*this)(0) = r * a(0);
        (*this)(1) = r * a(1);
        (*this)(2) = r * a(2);
        (*this)(3) = r * a(3);
    }
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        x += rs * a.x;
        y += rs * a.y;
        z += rs * a.z;
        w += rs * a.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline hkSimdReal dot3(const hkVector4& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
};


// The cross product is accumulated through references to its three named components. Havok's
// setCross into a vector temporary gives the same instructions but puts the components into one
// 16-byte slot, where the target keeps three separate float slots (a guess at the source).
struct CrossView { const float& a; const float& b; const float& c; };
__forceinline void accumulateView(hkVector4& v, CrossView view, hkReal r) {
    float cx=view.a; float cy=view.b; float cz=view.c; float f=r; v.x += f*cx; v.y += f*cy; v.z += f*cz; v.w += f*0.0f;
}

struct hkQuaternion
{
    hkVector4 m_vec;
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec(3); }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);
    __forceinline void setInverse(const hkQuaternion& q)
    {
        m_vec.set(-q.m_vec(0), -q.m_vec(1), -q.m_vec(2), q.m_vec(3));
    }
};

struct hkTransform
{
    hkVector4 m_col0, m_col1, m_col2, m_translation;
};

__forceinline void setRotatedDir(hkVector4& out, const hkQuaternion& quat, const hkVector4& direction)
{
    hkSimdReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    hkReal imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());
    const float crossX = quat.getImag()(1)*direction(2)-quat.getImag()(2)*direction(1);
    const float crossY = quat.getImag()(2)*direction(0)-quat.getImag()(0)*direction(2);
    const float crossZ = quat.getImag()(0)*direction(1)-quat.getImag()(1)*direction(0);
    CrossView view = { crossX, crossY, crossZ };
    accumulateView(ret, view, qreal);
    out.setAdd4(ret, ret);
}

// Lane operations of the inverse rotation (hkVector4::setRotatedInverseDir), as free functions.
__forceinline void setMul4Lanes(hkVector4& o, hkReal r, const hkVector4& a)
{ o(0) = r * a(0); o(1) = r * a(1); o(2) = r * a(2); o(3) = r * a(3); }
__forceinline void addMul4Lanes(hkVector4& o, hkSimdRealParameter rs, const hkVector4& a)
{ hkReal r = rs; o.x += r * a.x; o.y += r * a.y; o.z += r * a.z; o.w += r * a.w; }
__forceinline hkSimdReal dot3Lanes(const hkVector4& a, const hkVector4& v) { return (a.x * v.x) + (a.y * v.y) + (a.z * v.z); }

__forceinline void setRotatedInverseDir(hkVector4& out, const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;
    hkVector4 ret;
    setMul4Lanes(ret, q2minus1, direction);
    hkReal imagDotDir = dot3Lanes(quat.getImag(), direction);
    addMul4Lanes(ret, imagDotDir, quat.getImag());
    const float crossX = direction(1)*quat.getImag()(2)-direction(2)*quat.getImag()(1);
    const float crossY = direction(2)*quat.getImag()(0)-direction(0)*quat.getImag()(2);
    const float crossZ = direction(0)*quat.getImag()(1)-direction(1)*quat.getImag()(0);
    CrossView view = { crossX, crossY, crossZ };
    accumulateView(ret, view, qreal);
    out.setAdd4(ret, ret);
}

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    bool* FUN_009644a0(bool* result, const hkQsTransform& other, float epsilon) const;
    void FUN_009643d0(const hkTransform& t);
    void FUN_00964420(hkTransform& t) const;

    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkVector4 extraTrans;
        setRotatedDir(extraTrans, t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);
        m_scale.setMul4(t2.m_scale, t1.m_scale);
    }
    __forceinline void setInverse(const hkQsTransform& t)
    {
        setRotatedInverseDir(m_translation, t.m_rotation, t.m_translation);
        m_translation.setNeg4(m_translation);
        m_rotation.setInverse(t.m_rotation);
        hkVector4 invScale;
        invScale(0) = 1.0f / t.m_scale(0);
        invScale(1) = 1.0f / t.m_scale(1);
        invScale(2) = 1.0f / t.m_scale(2);
        m_scale.set(invScale(0), invScale(1), invScale(2), 0.0f);
    }
};

extern int DAT_01268700;

struct hkBool
{
    char m_bool;
    hkBool() {}
    hkBool(bool b) : m_bool(b) {}
};

class hkErrorD734
{
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setEnabled(int id, hkBool enabled);
    virtual hkBool isEnabled(int id);
};
extern hkErrorD734* DAT_01268360;
__forceinline hkErrorD734& getInstance() { return *DAT_01268360; }

struct hkReferencedObjectD
{
    virtual void destroy(int);
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    __forceinline void removeReference()
    {
        if (m_memSizeAndFlags != 0 && --m_referenceCount == 0)
            destroy(1);
    }
};
struct TransformShapeD : hkReferencedObjectD
{
    TransformShapeD* FUN_0097dd70(void* shape, const hkTransform* transform);
};
struct ThreadMemoryD
{
    void* FUN_008f6d30(int size, int cls);
};
struct MassPropertiesD
{
    int unk00, unk04;
    char unk08;
    void FUN_00a040c0();
};
struct InertiaD
{
    int unk00, unk04, unk08, unk0c;
    void FUN_00a040f0();
};
struct RigidBodyD
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void setShape(hkReferencedObjectD* shape);
    void hkpRigidBody_setTransform(const hkTransform& t);
    void FUN_0090cdb0(const hkVector4& com);
};
extern void __cdecl hkpTransformCollapseUtil_collapseTransforms(RigidBodyD* body, MassPropertiesD* a, InertiaD* b);
struct TranslateD : hkVector4
{
    void FUN_008d2970(const hkTransform* t, const hkVector4* v);
};

// pdb: moveRigidBodyPivot | hkaRagdollUtils.obj | fnv360_0822_retail, call_seq + skyrim(call_gap), high
static __declspec(noinline) int moveRigidBodyPivot(RigidBodyD* rigidBody, const hkQsTransform& newPivotFromOldPivot)
{
    bool same;
    if (!*newPivotFromOldPivot.FUN_009644a0(&same, *(const hkQsTransform*)&DAT_01268700, 0.001f))
    {
        hkQsTransform rbTransform;
        rbTransform.FUN_009643d0(*(const hkTransform*)((char*)rigidBody + 0xe0));
        hkQsTransform newRbTransform;
        newRbTransform.setMul(rbTransform, newPivotFromOldPivot);
        hkQsTransform oldPivotFromNewPivot;
        oldPivotFromNewPivot.setInverse(newPivotFromOldPivot);
        hkVector4 comLocal = *(const hkVector4*)((char*)rigidBody + 0x130);
        {
        hkBool wasEnabled = getInstance().isEnabled(0x2ff8c16f);
        {
            // named reference: the target loads the instance before it builds the hkBool argument
            hkErrorD734& err = *DAT_01268360;
            err.setEnabled(0x2ff8c16f, false);
        }
        void* oldShape = *(void**)((char*)rigidBody + 0x10);
        hkTransform transform;
        oldPivotFromNewPivot.FUN_00964420(transform);
        ThreadMemoryD* mem = (ThreadMemoryD*)DAT_00d9b080(DAT_010f3170);
        TransformShapeD* newShape = (TransformShapeD*)mem->FUN_008f6d30(0x70, 0x27);
        newShape->m_memSizeAndFlags = 0x70;
        newShape = newShape->FUN_0097dd70(oldShape, &transform);
        rigidBody->setShape(newShape);
        newShape->removeReference();
        {
            MassPropertiesD massProperties;
            InertiaD inertia;
            massProperties.FUN_00a040c0();
            inertia.FUN_00a040f0();
            hkpTransformCollapseUtil_collapseTransforms(rigidBody, &massProperties, &inertia);
        }
        getInstance().setEnabled(0x2ff8c16f, wasEnabled);
        }
        {
        hkTransform transform;
        newRbTransform.FUN_00964420(transform);
        rigidBody->hkpRigidBody_setTransform(transform);
        if (*((char*)rigidBody + 0xd8) != 7)
        {
            TranslateD newCom;
            newCom.FUN_008d2970(&transform, &comLocal);
            rigidBody->FUN_0090cdb0(newCom);
        }
        }
    }
    return 0;
}

// moveRigidBodyPivot is file-static with a private convention (the transform arrives in eax, the body on
// the stack); this caller makes the compiler emit it with that convention.
const hkQsTransform* volatile transform_input;
RigidBodyD* volatile body_input;
volatile int result_output;
void caller_transform() { result_output = moveRigidBodyPivot(body_input, *transform_input); }

}   // namespace f3m_0095de50

// @f3 0x0095d370 (community match, verified in this file)
#include <math.h>
namespace f3m_0095d370 {
// FUN_0095d370: Havok-style FPU code (hkVector4 / hkQuaternion helpers, all inlined): aim a bone at a target,
// clamp the direction to a cone, rotate the forward axis onto it (scaled by gain), optionally twist about the
// rotated up axis, then pre-multiply the bone rotation.
// The pack lists /Od, but the target is optimised code (aligned esp frame, ebx/esi/edi held across calls):
// it is built with /MT /O2 /GS /EHsc /Gy, as the same-file sibling 0x0095de50.

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return hkReal(::sqrt(r)); }
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
    __forceinline hkReal cos(hkReal r) { return hkReal(::cos(r)); }
    __forceinline hkReal acos(hkReal r)
    {
        if (fabs(r) >= 1.0f)
        {
            r = (r > 0) ? 0 : 3.14159265358979f;
            return r;
        }
        return hkReal(::acos(r));
    }
}

// Havok's FPU scalar: a one-float wrapper, taken by const reference.
struct hkSimdReal
{
    hkReal m_real;
    __forceinline hkSimdReal(hkReal v) { m_real = v; }
    __forceinline operator hkReal() const { return m_real; }
};
typedef const hkSimdReal& hkSimdRealParameter;

struct hkQuaternion;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a; y = b; z = c; w = d;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x; y = v.y; z = v.z; w = v.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w;
    }
    __forceinline void setMul4(hkReal r, const hkVector4& a)
    {
        x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w;
    }
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    __forceinline void addMul4Real(hkReal r, const hkVector4& a)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    __forceinline void mul4(hkReal r)
    {
        x *= r; y *= r; z *= r; w *= r;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return x * a.x + y * a.y + z * a.z;
    }
    // Lane-indexed forms, used only for the up block's side and up vectors: they read the lanes through
    // operator() and emit the same code as the field forms above. The extra inline layering is a numbering
    // lever of the x87 code generator (it decides the operand order of the cone axis length at +0x146);
    // a guess at the source, see the notes.
    __forceinline hkReal dot3o(const hkVector4& a) const
    {
        return (*this)(0) * a(0) + (*this)(1) * a(1) + (*this)(2) * a(2);
    }
    __forceinline hkReal lengthSquared3o() const
    {
        return (*this)(0) * (*this)(0) + (*this)(1) * (*this)(1) + (*this)(2) * (*this)(2);
    }
    __forceinline hkReal length3o() const
    {
        return hkMath::sqrt(lengthSquared3o());
    }
    __forceinline hkSimdReal lengthInverse3o() const
    {
        hkReal l2 = lengthSquared3o();
        return l2 ? hkMath::sqrtInverse(l2) : 0;
    }
    __forceinline void normalize3o() { mul4(lengthInverse3o()); }
    __forceinline hkReal lengthSquared3() const
    {
        return x * x + y * y + z * z;
    }
    __forceinline hkReal length3() const
    {
        return hkMath::sqrt(lengthSquared3());
    }
    __forceinline hkSimdReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 ? hkMath::sqrtInverse(l2) : 0;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }

    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setRotatedDirFwd(const hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setRotatedDirUp(const hkVector4& direction, const hkQuaternion& quat);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void operator=(const hkQuaternion& q) { m_vec = q.m_vec; }

    void FUN_009240d0(const hkVector4& axis, hkReal angle);          // setAxisAngle
    void FUN_0095d250(const hkQuaternion& q);                        // this = this * q
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1); // this = q0 * q1
};

// The three rotations differ only in grouping parentheses, in which operand the dot product is written on, in
// whether q2minus1 is named, and in the up rotation's parameter order (direction first): all of these are
// numbering levers of the x87 code generator that emit nothing themselves (guesses at the source, see the notes).
__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkReal qreal = quat.m_vec.w;
    hkReal q2minus1 = ((qreal * qreal)) - 0.5f;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    const hkReal imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedDirFwd(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkReal qreal = quat.m_vec.w;
    hkVector4 ret;
    ret.setMul4((((qreal * qreal))) - 0.5f, direction);
    const hkReal imagDotDir = direction.x * quat.m_vec.x + ((direction.y * quat.m_vec.y)) + direction.z * quat.m_vec.z;
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedDirUp(const hkVector4& direction, const hkQuaternion& quat)
{
    const hkReal qreal = quat.m_vec.w;
    hkReal q2minus1 = qreal * qreal - 0.5f;
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    const hkReal imagDotDir = direction.x * quat.m_vec.x + (direction.y * quat.m_vec.y) + direction.z * quat.m_vec.z;
    ret.addMul4Real(imagDotDir, quat.m_vec);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

struct hkBool
{
    char m_bool;
    hkBool() {}
    hkBool(bool b) { m_bool = (char)b; }
    hkBool& operator=(bool b) { m_bool = (char)b; return *this; }
};

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
};

struct Limits
{
    hkVector4 m_forward;
    hkVector4 m_up;
    hkVector4 m_coneAxis;
    hkReal m_coneAngle;
};

hkReal FUN_008d3240(hkReal x);

hkBool FUN_0095d370(const Limits* limits, const hkVector4& target, hkReal gain, hkQsTransform* t)
{
    hkVector4 dir;
    dir.setSub4(target, t->m_translation);
    hkReal dist = dir.length3();
    dir.normalize3();

    hkBool result = true;

    const hkReal cosDot = limits->m_coneAxis.dot3(dir);
    if (cosDot < hkMath::cos(limits->m_coneAngle))
    {
        hkVector4 axis;
        axis.setCross(limits->m_coneAxis, dir);
        axis.normalize3();
        hkQuaternion q;
        q.FUN_009240d0(axis, limits->m_coneAngle);
        dir.setRotatedDir(q, limits->m_coneAxis);
        result = false;
    }

    hkVector4 fwd;
    fwd.setRotatedDirFwd(t->m_rotation, limits->m_forward);
    hkVector4 axis2;
    axis2.setCross(fwd, dir);
    axis2.normalize3();
    hkQuaternion rot;
    rot.FUN_009240d0(axis2, hkMath::acos(dir.dot3(fwd)) * gain);

    // Guess: the nested parentheses are a numbering lever (they emit nothing).
    if ((((limits->m_up.length3()))) > 0)
    {
        hkVector4 side;
        side.setCross(limits->m_forward, limits->m_up);
        side.normalize3o();
        hkVector4 up;
        up.setCross(side, limits->m_forward);
        up.normalize3o();
        hkReal c = up.dot3o(limits->m_up) / up.length3o();
        hkReal a = dist * dist;
        hkReal cc = c * c;
        hkReal s = hkMath::sqrt(a - cc);
        hkReal b = s * s;
        hkReal r = hkMath::sqrt(a * a + (2.0 * b * cc - 2.0 * a * b) + 2.0 * a * cc + b * b + cc * cc) * 0.5 / s;
        hkReal twist = 0;
        if (r != 0)
        {
            twist = FUN_008d3240(c / r);
        }
        hkVector4 upW;
        upW.setRotatedDirUp(limits->m_up, t->m_rotation);
        {
            hkVector4 axis3;
            axis3.setCross(fwd, upW);
            axis3.normalize3();
            hkQuaternion q3;
            q3.FUN_009240d0(axis3, -twist);
            rot.FUN_0095d250(q3);
        }
    }

    {
        hkQuaternion res;
        res.FUN_008d3290(rot, t->m_rotation);
        t->m_rotation = res;
    }
    return result;
}
}   // namespace f3m_0095d370

// @f3 0x00958ec0 (community match, verified in this file)
namespace f3m_00958ec0 {
// 0x00958ec0: puts the bones whose translation is locked back at their reference offset from the parent, in a pose
// given in model space (hkaSkeletonUtils::enforceSkeletonConstraintsModelSpace in Havok terms).

namespace f3m_00958ec0 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

struct hkaBone
{
    char* m_name;
    bool m_lockTranslation;
};

struct hkaSkeleton
{
    char* m_name;
    short* m_parentIndices;
    int m_numParentIndices;
    hkaBone** m_bones;
    int m_numBones;
    hkQsTransform* m_referencePose;
    int m_numReferencePose;
};

// pdb: hkaSkeletonUtils::enforceSkeletonConstraintsModelSpace | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun, medium
// pdb params: skeleton, poseModelInOut
void __cdecl FUN_00958ec0(const hkaSkeleton& skeleton, hkQsTransform* poseModelSpaceInOut)
{
    const int numBones = skeleton.m_numBones;

    for (int boneIdx = 0; boneIdx < numBones; boneIdx++)
    {
        const hkaBone* bone = skeleton.m_bones[boneIdx];
        const short parentIdx = skeleton.m_parentIndices[boneIdx];

        if (bone->m_lockTranslation)
        {
            const hkVector4& localTranslation = skeleton.m_referencePose[boneIdx].m_translation;

            if (parentIdx != -1)
            {
                const hkQsTransform& parentModelSpace = poseModelSpaceInOut[parentIdx];
                poseModelSpaceInOut[boneIdx].m_translation.setRotatedDir(parentModelSpace.m_rotation, localTranslation);
                poseModelSpaceInOut[boneIdx].m_translation.add4(parentModelSpace.m_translation);
            }
            else
            {
                poseModelSpaceInOut[boneIdx].m_translation = localTranslation;
            }
        }
    }
}

}
}   // namespace f3m_00958ec0

// @f3 0x009584e0 (community match, verified in this file)
namespace f3m_009584e0 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_009584e0 {

typedef float SReal;
struct SQuat;

struct __declspec(align(16)) SVec
{
    SReal m_quad[4];
    __forceinline void operator=(const SVec& v)
    {
        m_quad[0] = v.m_quad[0]; m_quad[1] = v.m_quad[1]; m_quad[2] = v.m_quad[2]; m_quad[3] = v.m_quad[3];
    }
    __forceinline SReal& operator()(int i) { return m_quad[i]; }
    __forceinline const SReal& operator()(int i) const { return m_quad[i]; }
    __forceinline void set(SReal a, SReal b, SReal c, SReal d = 0)
    {
        m_quad[0] = a; m_quad[1] = b; m_quad[2] = c; m_quad[3] = d;
    }
    __forceinline void setNeg3(const SVec& v)
    {
        m_quad[0] = -v.m_quad[0]; m_quad[1] = -v.m_quad[1]; m_quad[2] = -v.m_quad[2]; m_quad[3] = v.m_quad[3];
    }
    __forceinline void setNeg4(const SVec& v)
    {
        m_quad[0] = -v.m_quad[0]; m_quad[1] = -v.m_quad[1]; m_quad[2] = -v.m_quad[2]; m_quad[3] = -v.m_quad[3];
    }
    __forceinline void setMul4(SReal rs, const SVec& a)
    {
        SReal r = rs;
        m_quad[0] = r * a.m_quad[0]; m_quad[1] = r * a.m_quad[1]; m_quad[2] = r * a.m_quad[2]; m_quad[3] = r * a.m_quad[3];
    }
    __forceinline void setMul4(const SVec& a, const SVec& b)
    {
        m_quad[0] = a.m_quad[0] * b.m_quad[0]; m_quad[1] = a.m_quad[1] * b.m_quad[1]; m_quad[2] = a.m_quad[2] * b.m_quad[2]; m_quad[3] = a.m_quad[3] * b.m_quad[3];
    }
    __forceinline void addMul4(SReal rs, const SVec& a)
    {
        SReal r = rs;
        m_quad[0] += r * a.m_quad[0]; m_quad[1] += r * a.m_quad[1]; m_quad[2] += r * a.m_quad[2]; m_quad[3] += r * a.m_quad[3];
    }
    __forceinline void setAdd4(const SVec& a, const SVec& b)
    {
        m_quad[0] = a.m_quad[0] + b.m_quad[0]; m_quad[1] = a.m_quad[1] + b.m_quad[1]; m_quad[2] = a.m_quad[2] + b.m_quad[2]; m_quad[3] = a.m_quad[3] + b.m_quad[3];
    }
    __forceinline SReal dot3(const SVec& a) const
    {
        return (m_quad[0] * a.m_quad[0]) + (m_quad[1] * a.m_quad[1]) + (m_quad[2] * a.m_quad[2]);
    }
    __forceinline void setCross(const SVec& v1, const SVec& v2)
    {
        const SReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const SReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const SReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    __forceinline void setRotatedDir(const SQuat& quat, const SVec& direction);
    __forceinline void setRotatedInverseDir(const SQuat& quat, const SVec& direction);
};

struct SQuat
{
    SVec m_vec;
    __forceinline const SVec& getImag() const { return m_vec; }
    __forceinline SReal getReal() const { return m_vec.m_quad[3]; }
    __forceinline void setInverse(const SQuat& q) { m_vec.setNeg3(q.getImag()); }
    void FUN_008d3290(const SQuat& q0, const SQuat& q1);
};

__forceinline void SVec::setRotatedDir(const SQuat& quat, const SVec& direction)
{
    SReal qreal = quat.m_vec(3);
    SReal q2minus1 = qreal * qreal - 0.5f;
    SVec ret;
    ret.setMul4(q2minus1, direction);
    SReal imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());
    SVec imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

__forceinline void SVec::setRotatedInverseDir(const SQuat& quat, const SVec& direction)
{
    // Name the imaginary quaternion and direction operands explicitly.
    const SVec& imag = quat.getImag();
    const SVec& dir = direction;
    SReal qreal = quat.m_vec(3);
    SReal q2minus1 = qreal * qreal - 0.5f;
    SVec ret;
    ret.setMul4(q2minus1, dir);
    SReal imagDotDir = imag.dot3(direction);
    ret.addMul4(imagDotDir, imag);
    SVec imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

inline void SQuat::FUN_008d3290(const SQuat& q0, const SQuat& q1)
{
    SVec vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.getReal(), q1.getImag());
    vec.addMul4(q1.getReal(), q0.getImag());
    SReal w = q0.getReal() * q1.getReal() - q0.getImag().dot3(q1.getImag());
    m_vec = vec;
    m_vec(3) = w;
}

struct STransform
{
    SVec m_translation;
    SQuat m_rotation;
    SVec m_scale;
    __forceinline void setInverse(const STransform& t)
    {
        m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
        m_translation.setNeg4(m_translation);
        m_rotation.setInverse(t.m_rotation);
        // Materialize the reciprocal scale before assigning the destination vector.
        SVec invScale;
        invScale.set(1.0f / t.m_scale(0), 1.0f / t.m_scale(1), 1.0f / t.m_scale(2));
        m_scale = invScale;
    }
    __forceinline void setMul(const STransform& t1, const STransform& t2)
    {
        SVec extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
    __forceinline void setMulInverseMul(const STransform& t1, const STransform& t2)
    {
        STransform h;
        h.setInverse(t1);
        setMul(h, t2);
    }
};

// pdb: hkaSkeletonUtils::transformWorldPoseToLocalPose | hkaSkeletonUtils.obj | fnv360_0822_retail, call_seq + skyrim(objrun), high
void __cdecl hkaSkeletonUtils_transformWorldPoseToLocalPose(int numTransforms, const short* parentIndices,
    const STransform& worldFromModel, const STransform* poseWorld, STransform* poseLocalOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = parentIndices[i];
        const STransform& worldFromParent = (-1 != parentId) ? poseWorld[parentId] : worldFromModel;
        poseLocalOut[i].setMulInverseMul(worldFromParent, poseWorld[i]);
    }
}
}
}   // namespace f3m_009584e0

// @f3 0x00958ae0 (community match, verified in this file)
namespace f3m_00958ae0 {
// 0x00958ae0: moves a pose from world space to model space (hkaSkeletonUtils::transformWorldPoseToModelPose in Havok
// terms): every bone transform is multiplied on the left by the inverse of the world-from-model transform.
//
// The quaternion product (0x008d3290) is written out here as well: it is an inline function the compiler chose not
// to expand, and the code of this function depends on the compiler having seen its body (it knows the call leaves
// the inverse transform untouched and keeps using the inverse scale it computed before the call).

namespace f3m_00958ae0 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline void operator=(const hkVector4& v)
    {
        m_quad[0] = v.m_quad[0];
        m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2];
        m_quad[3] = v.m_quad[3];
    }
    __forceinline hkReal& operator()(int i) { return m_quad[i]; }
    __forceinline const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0)
    {
        m_quad[0] = a;
        m_quad[1] = b;
        m_quad[2] = c;
        m_quad[3] = d;
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        m_quad[0] = -v.m_quad[0];
        m_quad[1] = -v.m_quad[1];
        m_quad[2] = -v.m_quad[2];
        m_quad[3] = v.m_quad[3];
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        m_quad[0] = -v.m_quad[0];
        m_quad[1] = -v.m_quad[1];
        m_quad[2] = -v.m_quad[2];
        m_quad[3] = -v.m_quad[3];
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        m_quad[0] = r * a.m_quad[0];
        m_quad[1] = r * a.m_quad[1];
        m_quad[2] = r * a.m_quad[2];
        m_quad[3] = r * a.m_quad[3];
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] * b.m_quad[0];
        m_quad[1] = a.m_quad[1] * b.m_quad[1];
        m_quad[2] = a.m_quad[2] * b.m_quad[2];
        m_quad[3] = a.m_quad[3] * b.m_quad[3];
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        m_quad[0] += r * a.m_quad[0];
        m_quad[1] += r * a.m_quad[1];
        m_quad[2] += r * a.m_quad[2];
        m_quad[3] += r * a.m_quad[3];
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] + b.m_quad[0];
        m_quad[1] = a.m_quad[1] + b.m_quad[1];
        m_quad[2] = a.m_quad[2] + b.m_quad[2];
        m_quad[3] = a.m_quad[3] + b.m_quad[3];
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (m_quad[0] * a.m_quad[0]) + (m_quad[1] * a.m_quad[1]) + (m_quad[2] * a.m_quad[2]);
    }
    // this = v1 m_quad[0] v2, m_quad[3] = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    // this = direction rotated by the inverse of quat
    __forceinline void setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.m_quad[3]; }
    __forceinline void setInverse(const hkQuaternion& q) { m_vec.setNeg3(q.getImag()); }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);      // setMul
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkVector4& dir = direction;

    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    const hkVector4& imag = quat.getImag();
    ret.addMul4(imagDotDir, imag);

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(dir, imag);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// this = q0 * q1 (0x008d3290)
inline void hkQuaternion::FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1)
{
    hkVector4 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.getReal(), q1.getImag());
    vec.addMul4(q1.getReal(), q0.getImag());
    hkReal w = q0.getReal() * q1.getReal() - q0.getImag().dot3(q1.getImag());
    m_vec = vec;
    m_vec(3) = w;
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    // this = t^-1
    __forceinline void setInverse(const hkQsTransform& t)
    {
        m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
        m_translation.setNeg4(m_translation);
        m_rotation.setInverse(t.m_rotation);
        hkVector4 invScale;
        invScale.set(1.0f / t.m_scale(0), 1.0f / t.m_scale(1), 1.0f / t.m_scale(2));
        m_scale = invScale;
    }
    // this = t1 * t2
    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        // rotation and position go together
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);

        // scale goes apart
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
    // this = t1^-1 * t2
    __forceinline void setMulInverseMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkQsTransform h;
        h.setInverse(t1);
        setMul(h, t2);
    }
};

// pdb: hkaSkeletonUtils::transformWorldPoseToModelPose | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void __cdecl hkaSkeletonUtils_transformWorldPoseToModelPose(int numTransforms, const hkQsTransform& worldFromModel, const hkQsTransform* poseWorld, hkQsTransform* poseModelOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        poseModelOut[i].setMulInverseMul(worldFromModel, poseWorld[i]);
    }
}

}
}   // namespace f3m_00958ae0

// @f3 0x0094bab0 (community match, verified in this file)
extern float DAT_00dbe8fc;
namespace f3m_0094bab0 {

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) Out
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
    Vec4 translation;

    void FUN_00cb22f0(char* p, void* arg);
};

struct Kit
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    void InitFromHelper(void* p);
    void hkpConstraintConstructionKit_setPivotA(Vec4* p);
    void FUN_009df980(Out* p);
    int  FUN_009dfc50(Vec4* p);
    int  FUN_009dfaa0(Out* p);
    void FUN_009df390();
    void FUN_009df510();
    void FUN_009e0500(float value);
    void FUN_009df580();
    void FUN_009df5c0();
};

struct FUN_0094bab0_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();

    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;

    void FUN_0094bab0(void* arg);
};

// pdb: hkFixedConstraintCinfo::Fix | bhkFixedConstraint.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arPoint
void FUN_0094bab0_Obj::FUN_0094bab0(void* arg)
{
    Kit kit;
    Out first;
    Out second;

    v14();
    kit.InitFromHelper((void*)(m04 ? m04 : m04));

    char* base = (char*)m10;
    first.FUN_00cb22f0((char*)m0C + 0xE0, arg);
    second.FUN_00cb22f0(base + 0xE0, arg);

    kit.hkpConstraintConstructionKit_setPivotA(&first.translation);
    kit.FUN_009df980(&first);
    m14 = kit.FUN_009dfc50(&second.translation);
    m18 = kit.FUN_009dfaa0(&second);
    kit.FUN_009df390();
    kit.FUN_009df510();
    kit.FUN_009e0500(DAT_00dbe8fc);
    kit.FUN_009df580();
    kit.FUN_009df5c0();
}
}   // namespace f3m_0094bab0

// @f3 0x00956290 (community match, verified in this file)
namespace f3m_00956290 {
// FUN_00956290 = Havok 5.5.0 hkaPose::accessBoneLocalSpace (hkaAnimation.lib, hkaPose.obj; the stock release
// object is byte-exact against the game). Syncs the local transform of every descendant, then the bone's own
// local transform, marks the bone's model transform dirty and returns its local transform for writing.
// Source: the Havok 5.5.0 SDK (approved source). Types and inline bodies are the SDK's own text from hkBaseTypes.h,
// hkArray.h/.inl, hkFpuVector4.inl, hkQuaternion.inl, hkQsTransform.inl, hkaSkeleton.h, hkaBone.h, hkaPose.h and
// hkaPose.inl (getBoneLocalSpace, getBoneModelSpace, makeAllChildrenLocalSpace, the flag helpers), reduced to what
// this function uses. The body of accessBoneLocalSpace is reconstructed from the hybrid library object's line
// records 264-277 (hkaPose.cpp is not shipped). Release-build assert and invariant macros expand to nothing.
namespace f3m_00956290 {

typedef float hkReal;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned int hkUint32;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

class hkBool
{
	public:
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
};

template <typename T>
class hkArray
{
	public:
		__forceinline T& operator[] (int i);
	protected:
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkQuaternion;

class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		inline void operator= (const hkQuaternion& q);
		inline void setInverse( const hkQuaternion &q );
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline hkReal getReal() const;
		__forceinline const hkVector4& getImag() const;
	public:
		hkVector4 m_vec;
};

class hkQsTransform
{
	public:
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

__forceinline void hkVector4::setXYZ0(const hkVector4& xyz)
{
	x = xyz.x;
	y = xyz.y;
	z = xyz.z;
	w = 0;
}

inline void hkVector4::setReciprocal3(const hkVector4& v)
{
	x = 1.0f / v.x;
	y = 1.0f / v.y;
	z = 1.0f / v.z;
	w = 1.0f;
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}

inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
	const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
	const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
	const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
	this->set( nx, ny, nz , 0.0f );
}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( direction, quat.getImag() );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}

inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}

inline hkReal hkQuaternion::getReal() const
{
	return m_vec(3);
}

inline void hkQuaternion::operator= (const hkQuaternion& q)
{
	m_vec = q.m_vec;
}

inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
	hkVector4 vec;
	vec.setCross(q0.getImag(), q1.getImag());
	vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
	vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
	hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.m_vec.dot3( q1.m_vec ) );
	m_vec = vec;
	m_vec(3) = real;
}

void hkQuaternion::setInverse( const hkQuaternion &q )
{
	m_vec.setNeg3( q.getImag() );
}

void hkQsTransform::setInverse( const hkQsTransform& t )
{
	m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
	m_translation.setNeg4(m_translation);
	m_rotation.setInverse(t.m_rotation);
	hkVector4 invScale; invScale.setReciprocal3( t.m_scale );
	m_scale.setXYZ0( invScale );
}

void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);
	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}

void hkQsTransform::setMulInverseMul( const hkQsTransform& a, const hkQsTransform &b )
{
	hkQsTransform h;
	h.setInverse( a );
	setMul(h, b);
}

class hkaBone
{
	public:
		char * m_name;
		hkBool m_lockTranslation;
};

class hkaSkeleton
{
	public:
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int m_numReferencePose;
		char** m_floatSlots;
		hkInt32 m_numFloatSlots;
};

class hkaPose
{
public:
	__forceinline const hkQsTransform& getBoneLocalSpace (int boneIdx) const;
	__forceinline const hkQsTransform& getBoneModelSpace (int boneIdx) const;
	// hkaPose::accessBoneLocalSpace under the pack's symbol
	hkQsTransform& FUN_00956290 (int boneIdx);
private:
	typedef hkUint32 hkaPoseFlag;
	const hkaSkeleton* m_skeleton;
	mutable hkArray<hkQsTransform> m_localPose;
	mutable hkArray<hkQsTransform> m_modelPose;
	mutable hkArray<hkaPoseFlag> m_boneFlags;
	mutable hkBool m_modelInSync;
	mutable hkBool m_localInSync;
	hkArray<hkReal> m_floatSlotValues;
	enum
	{
		F_BONE_LOCAL_DIRTY = 0x1,
		F_BONE_MODEL_DIRTY = 0x2,
		F_BONE_INTERNAL_FLAG1 = 0x4,
		F_BONE_INTERNAL_FLAG2 = 0x8,
		F_BONE_INTERNAL_FLAG3 = 0x10,
	};
	__forceinline int isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const;
	__forceinline void setFlag (int boneIdx, hkaPoseFlag enumToCheck) const;
	__forceinline void clearFlag (int boneIdx, hkaPoseFlag enumToCheck) const;
	__forceinline int isFlagOnExplicit (hkaPoseFlag flag, hkaPoseFlag enumToCheck) const;
	__forceinline void setFlagExplicit (hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const;
	__forceinline void clearFlagExplicit (hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const;
	__forceinline void makeAllChildrenLocalSpace (int boneIdx) const;
	const hkQsTransform& calculateBoneModelSpace (int boneIdx) const;
};

int hkaPose::isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const
{
	return m_boneFlags[boneIdx] & enumToCheck;
}

void hkaPose::setFlag (int boneIdx, hkaPoseFlag enumToCheck) const
{
	m_boneFlags[boneIdx] |= enumToCheck;
}

void hkaPose::clearFlag (int boneIdx, hkaPoseFlag enumToCheck) const
{
	m_boneFlags[boneIdx] &= static_cast<hkaPoseFlag>(~enumToCheck);
}

int hkaPose::isFlagOnExplicit (hkaPoseFlag flag, hkaPoseFlag enumToCheck) const
{
	return flag & enumToCheck;
}

void hkaPose::setFlagExplicit (hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const
{
	flag |= enumToCheck;
}

void hkaPose::clearFlagExplicit (hkaPoseFlag& flag, hkaPoseFlag enumToCheck) const
{
	flag &= static_cast<hkaPoseFlag>(~enumToCheck);
}

const hkQsTransform& hkaPose::getBoneModelSpace (int boneIdx) const
{
	if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY))
	{
		return m_modelPose[boneIdx];
	}
	else
	{
		return calculateBoneModelSpace(boneIdx);
	}
}

const hkQsTransform& hkaPose::getBoneLocalSpace (int boneIdx) const
{
	if (! isFlagOn (boneIdx, F_BONE_LOCAL_DIRTY))
	{
		return m_localPose[boneIdx];
	}
	else
	{
		const hkQsTransform& modelFromBone = m_modelPose[boneIdx];

		const hkInt16 parentIdx = m_skeleton->m_parentIndices[boneIdx];

		if (parentIdx != -1)
		{
			// ask for parent model (may be dirty)
			const hkQsTransform& modelFromParent = getBoneModelSpace(parentIdx);

			// parentfrombone = inv(modelfromparent) * modelfrombone
			m_localPose[boneIdx].setMulInverseMul(modelFromParent, modelFromBone);
		}
		else
		{
			m_localPose[boneIdx] = modelFromBone;
		}

		clearFlag (boneIdx, F_BONE_LOCAL_DIRTY);

		return m_localPose[boneIdx];
	}
}

void hkaPose::makeAllChildrenLocalSpace(int boneIdx) const
{
	const int numBones = m_skeleton->m_numBones;

	setFlag(boneIdx, F_BONE_INTERNAL_FLAG1);

	// Synchronize all descendants local representation
	{
		for (int i= boneIdx+1; i<numBones; ++i)
		{
			const hkInt16 parentId = m_skeleton->m_parentIndices[i];
			if (isFlagOn(parentId, F_BONE_INTERNAL_FLAG1))
			{
				getBoneLocalSpace( i ); // sync local
				setFlag( i, F_BONE_INTERNAL_FLAG1);
				m_modelInSync = false;
			}
		}
	}

	// Dirty all descendants model representation
	{
		for (int i= boneIdx+1; i < numBones; ++i)
		{
			hkaPoseFlag f = m_boneFlags[i];
			if (isFlagOnExplicit( f, F_BONE_INTERNAL_FLAG1))
			{
				setFlagExplicit( f, F_BONE_MODEL_DIRTY);
				clearFlagExplicit( f, F_BONE_INTERNAL_FLAG1);
				m_boneFlags[i] = f;
			}
		}
	}
}

// hkaPose::accessBoneLocalSpace (reconstructed from the hybrid object's line records 267, 269, 271, 272, 276)
// pdb: hkaPose::accessBoneLocalSpace | hkaPose.obj | fnv360_0822_retail, call_gap, medium
// pdb params: boneIdx
hkQsTransform& hkaPose::FUN_00956290 (int boneIdx)
{
	// The model transform will be invalidated for all descendants
	// Make also sure the local transform for those is in sync
	makeAllChildrenLocalSpace(boneIdx);

	getBoneLocalSpace(boneIdx);

	m_boneFlags[boneIdx] = F_BONE_MODEL_DIRTY;
	m_modelInSync = false;

	return m_localPose[boneIdx];
}

} // namespace f3m_00956290
}   // namespace f3m_00956290

// @f3 0x00957310 (community match, verified in this file)
// FUN_00957310 = Havok 5.5.0 hkaTwoJointsIkSolver::solve (hkaAnimation.lib, hkaTwoJointsIkSolver.obj).
// Written from the Havok 5.5.0 SDK headers (hkaTwoJointsIkSolver.h, hkaPose.h/.inl, FPU hkFpuVector4.inl,
// hkVector4.inl, hkQuaternion.inl, hkFpuMathFuncs.inl, hkMonitorStream.h) and the hybrid library object's debug
// records; cut to one file with hktrim.py.
		extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}
namespace f3m_00957310 {
typedef float  hkReal;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
class hkClass;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
	private:
		TYPE m_storage;
};

		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
	public:
		__forceinline T& operator[] (int i);
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

extern "C" {
        double  __cdecl acos(     double _X);
 double  __cdecl fabs(     double _X);
        double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float acosf(     float _X)
        {return ((float)acos((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	inline hkReal __cdecl acos(hkReal r)
	{
		if( hkMath::fabs(r) >= 1.0f )
		{
			r = ( r>0 )	? 0 : 3.14159265358979f;
			return r;
		}
		return ::acosf(r);
	}
	template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
	template <typename T>
	inline T __cdecl min2( T x, T y)
	{
		return x < y ? x : y;
	}
}

class hkQuaternion;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		                class MustEndWithSemiColon;
		inline hkQuaternion() { }
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void normalize();
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		inline hkReal getReal() const;
		__forceinline const hkVector4& getImag() const;
	public:
		hkVector4 m_vec;
};

class hkQsTransform
{
	public:
		                class MustEndWithSemiColon;
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline const hkVector4& getTranslation() const;
		__forceinline const hkQuaternion& getRotation() const;
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
	}

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}

inline hkQuaternion::hkQuaternion(const hkVector4& axis, hkReal angle)
{
	setAxisAngle(axis,angle);
}

inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}

inline hkReal hkQuaternion::getReal() const
{
	return m_vec(3);
}

inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
	hkVector4 vec;
	vec.setCross(q0.getImag(), q1.getImag());
	vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
	vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
	hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.m_vec.dot3( q1.m_vec ) );
	m_vec = vec;
	m_vec(3) = real;
}

const hkVector4& hkQsTransform::getTranslation() const
{
	return m_translation;
}

const hkQuaternion& hkQsTransform::getRotation() const
{
	return m_rotation;
}

class hkaPose;

class hkaTwoJointsIkSolver : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		struct Setup
		{
			                class MustEndWithSemiColon;
			hkInt16 m_firstJointIdx;
			hkInt16 m_secondJointIdx;
			hkInt16 m_endBoneIdx;
			hkVector4 m_hingeAxisLS;
			hkReal m_cosineMaxHingeAngle;
			hkReal m_cosineMinHingeAngle;
			hkReal m_firstJointIkGain;
			hkReal m_secondJointIkGain;
			hkVector4 m_endTargetMS;
		};
};

class hkaBone
{
	public:
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		char * m_name;
		hkBool m_lockTranslation;
};

class hkaSkeleton
{
	public:
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int		m_numReferencePose;
		char**	m_floatSlots;
		hkInt32 m_numFloatSlots;
};

class hkaPose
{
public:
	                class MustEndWithSemiColon;
	enum PoseSpace
	{
		MODEL_SPACE,
		LOCAL_SPACE
	};
	enum PropagateOrNot
	{
		DONT_PROPAGATE = 0,
		PROPAGATE = 1
	};
	__forceinline const hkQsTransform& getBoneModelSpace (int boneIdx) const;
	hkQsTransform& accessBoneModelSpace (int boneIdx, PropagateOrNot propagateOrNot = DONT_PROPAGATE);
private:
	typedef hkUint32 hkaPoseFlag;
	const hkaSkeleton* m_skeleton;
	mutable hkArray<hkQsTransform> m_localPose;
	mutable hkArray<hkQsTransform> m_modelPose;
	mutable hkArray<hkaPoseFlag> m_boneFlags;
	mutable hkBool m_modelInSync;
	mutable hkBool m_localInSync;
	hkArray<hkReal> m_floatSlotValues;
	enum
	{
		F_BONE_LOCAL_DIRTY = 0x1,
		F_BONE_MODEL_DIRTY = 0x2,
		F_BONE_INTERNAL_FLAG1 = 0x4,
		F_BONE_INTERNAL_FLAG2 = 0x8,
		F_BONE_INTERNAL_FLAG3 = 0x10,
	};
	enum
	{
		M_BONE_INTERNAL_FLAGS = F_BONE_INTERNAL_FLAG1 | F_BONE_INTERNAL_FLAG2 | F_BONE_INTERNAL_FLAG3
	};
	__forceinline int isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const;
	const hkQsTransform& calculateBoneModelSpace (int boneIdx) const;
};

int hkaPose::isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const
{
	return m_boneFlags[boneIdx] & enumToCheck;
}

const hkQsTransform& hkaPose::getBoneModelSpace (int boneIdx) const
{
	if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY))
	{
		return m_modelPose[boneIdx];
	}
	else
	{
		return calculateBoneModelSpace(boneIdx);
	}
}

class hkMonitorStream
{
	public:
		                class MustEndWithSemiColon;
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
	public:
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			                class MustEndWithSemiColon;
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			                class MustEndWithSemiColon;
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			                class MustEndWithSemiColon;
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			                class MustEndWithSemiColon;
			const char* m_nameOfFirstSplit;
		};
};

void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
			rdtsc
			mov dword ptr[ticks], eax
		}
		m_time0 = ticks;
}

hkBool __cdecl FUN_00957310 ( const hkaTwoJointsIkSolver::Setup& setup, hkaPose& poseInOut )
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "L" "t" "TWOJOINTSOLVER"; h->m_nameOfFirstSplit = "S" "t" "INIT"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "FIXLENGTH"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{
		const hkVector4& firstJointPosMS = poseInOut.getBoneModelSpace(setup.m_firstJointIdx).getTranslation();
		const hkVector4& secondJointPosMS = poseInOut.getBoneModelSpace(setup.m_secondJointIdx).getTranslation();
		const hkVector4& endPosMS = poseInOut.getBoneModelSpace(setup.m_endBoneIdx).getTranslation();
		hkVector4 v1; v1.setSub4(secondJointPosMS, firstJointPosMS);
		hkVector4 v2; v2.setSub4(endPosMS, secondJointPosMS);
		hkVector4 iToG; iToG.setSub4(setup.m_endTargetMS, firstJointPosMS);
		const hkReal D_sqr = iToG.lengthSquared3();
		const hkReal l1_sqr = v1.lengthSquared3();
		const hkReal l2_sqr = v2.lengthSquared3();
		const hkReal l1 = hkMath::sqrt(l1_sqr);
		const hkReal l2 = hkMath::sqrt(l2_sqr);
		const hkReal cosAngle = hkMath::max2( setup.m_cosineMaxHingeAngle, hkMath::min2( setup.m_cosineMinHingeAngle, (D_sqr - l1_sqr - l2_sqr) / (-2.0f * l1 * l2) ) );
		const hkReal desiredHingeAngle = hkMath::acos(cosAngle);
		v1.normalize3(); v1.setNeg3(v1);
		v2.normalize3();
		const hkReal currentHingeAngle = hkMath::acos( v1.dot3(v2) );
		const hkReal diffAngle = desiredHingeAngle - currentHingeAngle;
		{
			hkQsTransform& refHingeMS = poseInOut.accessBoneModelSpace(setup.m_secondJointIdx, hkaPose::PROPAGATE);
			hkQuaternion currentRot = refHingeMS.getRotation();
			hkVector4 axis; axis.setRotatedDir(currentRot, setup.m_hingeAxisLS);
			hkQuaternion extra(axis, setup.m_secondJointIkGain * diffAngle);
			refHingeMS.m_rotation.setMul(extra, currentRot);
			refHingeMS.m_rotation.normalize();
		}
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "FIXDIRECTION"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{
		const hkVector4& initMS = poseInOut.getBoneModelSpace(setup.m_firstJointIdx).getTranslation();
		const hkVector4& endMS = poseInOut.getBoneModelSpace(setup.m_endBoneIdx).getTranslation();
		const hkVector4& goalMS = setup.m_endTargetMS;
		hkVector4 iToE_n; iToE_n.setSub4(endMS, initMS); iToE_n.normalize3();
		hkVector4 iToG_n; iToG_n.setSub4(goalMS, initMS); iToG_n.normalize3();
		hkQuaternion extra;
		extra.setShortestRotationDamped(setup.m_firstJointIkGain, iToE_n, iToG_n);
		{
			hkQsTransform& refFirstJointMS = poseInOut.accessBoneModelSpace(setup.m_firstJointIdx, hkaPose::PROPAGATE);
			hkQuaternion currentRot = refFirstJointMS.getRotation();
			refFirstJointMS.m_rotation.setMul(extra, currentRot);
			refFirstJointMS.m_rotation.normalize();
		}
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "l" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	return true;
}
}

// @f3 0x00944470 (community match, verified in this file)
namespace f3m_00944470 {
struct Island944470
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short flag20;
};

// pdb: getAnyNonFixedIsland | hkpWorldAgentUtil.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) Island944470* FUN_00944470(Island944470* a, Island944470* b)
{
    if (a->flag20 != 0xffff)
        return a;
    if (b->flag20 != 0xffff)
        return b;
    return a;
}

volatile Island944470* g_islandIn1;
volatile Island944470* g_islandIn2;
volatile Island944470* g_islandOut;

void call_pick_island()
{
    g_islandOut = FUN_00944470((Island944470*)g_islandIn1, (Island944470*)g_islandIn2);
}
}   // namespace f3m_00944470

// @f3 0x00943910 (community match, verified in this file)
extern const char f3c_fmt943910[];
extern const char f3c_nullstr[];
namespace f3m_00943910 {

int hkString_snprintf(char* buffer, unsigned int size, const char* format, ...);
int StrLen(const char* text);

struct HkWriterC0280 {
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0c();
    virtual void Write(const char* text, int length);
};

struct FmtBuf { __int64 w[0x2728 / 8]; };

static __declspec(noinline) void CC0280WriteString(HkWriterC0280* writer, const char* text)
{
    if (text)
        writer->Write(text, StrLen(text));
    else
        writer->Write(f3c_nullstr, 6);
}

struct HkOstream {
    int unk00;
    int unk04;
    HkWriterC0280* m_writer;
    HkOstream* FUN_00943910(unsigned __int64 value);
};

// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, objrun, high
// pdb params: i
HkOstream* HkOstream::FUN_00943910(unsigned __int64 value)
{
    FmtBuf buffer;
    hkString_snprintf((char*)buffer.w, 0x2728, f3c_fmt943910, value);
    CC0280WriteString(m_writer, (const char*)buffer.w);
    return this;
}
}   // namespace f3m_00943910

// @f3 0x00953630 (community match, verified in this file)
namespace f3m_00953630 {
// w505 - 0x00953630

class C953630_Inner
{
public:
    char pad_00[0x38];
    int  field_38;
    int  field_3c;
};

struct C953630_Elem
{
    int            unk_00;
    C953630_Inner* ptr_04;
};

class C953630_Arg
{
public:
    char pad_00[4];
    int  field_04;
    void Notify(int a, int b, int c);
};

class C953630_Outer
{
public:
    char           pad_00[0xc];
    C953630_Elem*  arr_0c;
    int            count_10;

    void FUN_00953630(C953630_Arg* arg);
};

// pdb: hkVisualDebugger::getCurrentProcesses | hkVisualDebugger.obj | fnv360_0822_retail, caller_sim, low
// pdb params: process
void C953630_Outer::FUN_00953630(C953630_Arg* arg)
{
    int n = count_10;
    for (int i = 0; i < n; ++i)
    {
        C953630_Elem* e = &arr_0c[i];
        C953630_Inner* p = e->ptr_04;
        if (e->ptr_04)
            arg->Notify(arg->field_04, p->field_38, p->field_3c);
    }
}
}   // namespace f3m_00953630

// @f3 0x0095a470 (community match, verified in this file)
#include <math.h>
namespace f3m_0095a470 {

// 0x0095a470: gives a ragdoll constraint a cone limit that is not symmetric about the twist axis
// (hkpRagdollConstraintData::setAsymmetricConeAngle in Havok terms). Body B's twist axis is turned about the plane
// axis by minus the centre of the two angles, the third axis of the frame is rebuilt from the cross product, and the
// cone limit gets half the difference of the two angles.

namespace f3m_0095a470 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    void FUN_009240d0(const hkVector4& axis, hkReal angle);     // setAxisAngle
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline hkRotation& getRotation() { return m_rotation; }
};

// constraint atoms of a ragdoll constraint, in the order they are laid out
struct hkpSetLocalTransformsConstraintAtom
{
    unsigned short m_type;
    hkTransform m_transformA;
    hkTransform m_transformB;
};

struct hkpRagdollMotorConstraintAtom
{
    unsigned short m_type;
    unsigned char m_isEnabled;
    short m_initializedOffset;
    short m_previousTargetAnglesOffset;
    hkRotation m_target_bRca;
    void* m_motors[3];
};

struct hkpAngFrictionConstraintAtom
{
    unsigned short m_type;
    unsigned char m_isEnabled;
    unsigned char m_firstFrictionAxis;
    unsigned char m_numFrictionAxes;
    hkReal m_maxFrictionTorque;
};

struct hkpTwistLimitConstraintAtom
{
    unsigned short m_type;
    unsigned char m_isEnabled;
    unsigned char m_twistAxis;
    unsigned char m_refAxis;
    hkReal m_minAngle;
    hkReal m_maxAngle;
    hkReal m_angularLimitsTauFactor;
};

struct hkpConeLimitConstraintAtom
{
    unsigned short m_type;
    unsigned char m_isEnabled;
    unsigned char m_twistAxisInA;
    unsigned char m_refAxisInB;
    unsigned char m_angleMeasurementMode;
    unsigned char m_memOffsetToAngleOffset;
    hkReal m_minAngle;
    hkReal m_maxAngle;
    hkReal m_angularLimitsTauFactor;
};

struct hkpRagdollConstraintData
{
    // columns of each frame
    enum Axis
    {
        AXIS_TWIST = 0,
        AXIS_PLANES = 1,
        AXIS_CROSS_PRODUCT = 2
    };

    void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_userData;
    hkpSetLocalTransformsConstraintAtom m_transforms;
    hkpRagdollMotorConstraintAtom m_ragdollMotors;
    hkpAngFrictionConstraintAtom m_angFriction;
    hkpTwistLimitConstraintAtom m_twistLimit;
    hkpConeLimitConstraintAtom m_coneLimit;

    __forceinline void setConeAngularLimit(hkReal angle) { m_coneLimit.m_maxAngle = angle; }
    void FUN_0095a470(hkReal cone_min, hkReal cone_max);
};

void hkpRagdollConstraintData::FUN_0095a470(hkReal cone_min, hkReal cone_max)
{
    hkReal center_cone = (cone_max + cone_min) * 0.5f;
    hkReal diff_cone = (cone_max - cone_min) * 0.5f;

    hkRotation& baseB = m_transforms.m_transformB.getRotation();

    hkQuaternion baseModificationB; baseModificationB.FUN_009240d0(baseB.getColumn(AXIS_PLANES), -center_cone);
    baseB.getColumn(AXIS_TWIST).setRotatedDir(baseModificationB, baseB.getColumn(AXIS_TWIST));
    baseB.getColumn(AXIS_CROSS_PRODUCT).setCross(baseB.getColumn(AXIS_TWIST), baseB.getColumn(AXIS_PLANES));

    setConeAngularLimit(diff_cone);
}

}
}   // namespace f3m_0095a470

// @f3 0x00958900 (community match, verified in this file)
namespace f3m_00958900 {
// 0x00958900: moves a pose from model space to world space (hkaSkeletonUtils::transformModelPoseToWorldPose in Havok
// terms): every bone transform is multiplied on the left by the world-from-model transform. Translation and
// rotation combine as a rigid transform, the scales multiply component by component.

namespace f3m_00958900 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);      // setMul
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    // this = t1 * t2
    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        // rotation and position go together
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);

        // scale goes apart
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
};

// pdb: hkaSkeletonUtils::transformModelPoseToWorldPose | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void __cdecl hkaSkeletonUtils_transformModelPoseToWorldPose(int numTransforms, const hkQsTransform& worldFromModel, const hkQsTransform* poseModelIn, hkQsTransform* poseWorldOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        poseWorldOut[i].setMul(worldFromModel, poseModelIn[i]);
    }
}

}
}   // namespace f3m_00958900

// @f3 0x009590a0 (community match, verified in this file)
namespace f3m_009590a0 {
// 0x009590a0: puts the bones whose translation is locked at the offset from the parent given by a set of local
// space constraints, in a pose given in model space (hkaSkeletonUtils::enforcePoseConstraintsModelSpace in Havok
// terms).

namespace f3m_009590a0 {

typedef float hkReal;

struct hkQuaternion;

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    // this = direction rotated by quat
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// translation, rotation and scale
struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

struct hkaBone
{
    char* m_name;
    bool m_lockTranslation;
};

struct hkaSkeleton
{
    char* m_name;
    short* m_parentIndices;
    int m_numParentIndices;
    hkaBone** m_bones;
    int m_numBones;
    hkQsTransform* m_referencePose;
    int m_numReferencePose;
};

// pdb: hkaSkeletonUtils::enforcePoseConstraintsModelSpace | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun, medium
// pdb params: skeleton, constraintsLocal, poseModelInOut
void __cdecl FUN_009590a0(const hkaSkeleton& skeleton, const hkQsTransform* constraintsLocalSpace, hkQsTransform* poseModelSpaceInOut)
{
    const int numBones = skeleton.m_numBones;

    for (int boneIdx = 0; boneIdx < numBones; boneIdx++)
    {
        const hkaBone* bone = skeleton.m_bones[boneIdx];
        const short parentIdx = skeleton.m_parentIndices[boneIdx];

        if (bone->m_lockTranslation)
        {
            const hkVector4& localTranslation = constraintsLocalSpace[boneIdx].m_translation;

            if (parentIdx != -1)
            {
                const hkQsTransform& parentModelSpace = poseModelSpaceInOut[parentIdx];
                hkVector4 rotated;
                rotated.setRotatedDir(parentModelSpace.m_rotation, localTranslation);
                poseModelSpaceInOut[boneIdx].m_translation.setAdd4(rotated, parentModelSpace.m_translation);
            }
            else
            {
                poseModelSpaceInOut[boneIdx].m_translation = localTranslation;
            }
        }
    }
}

}
}   // namespace f3m_009590a0

// @f3 0x00955810 (community match, verified in this file)
namespace f3m_00955810 {
namespace f3m_00955810 {

typedef float hkReal;

struct hkQuaternion;

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline void operator=(const hkVector4& v)
    {
        m_quad[0] = v.m_quad[0];
        m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2];
        m_quad[3] = v.m_quad[3];
    }

    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setMul4(hkReal r, const hkVector4& v)
    { m_quad[0] = r * v.m_quad[0]; m_quad[1] = r * v.m_quad[1]; m_quad[2] = r * v.m_quad[2]; m_quad[3] = r * v.m_quad[3]; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] * b.m_quad[0];
        m_quad[1] = a.m_quad[1] * b.m_quad[1];
        m_quad[2] = a.m_quad[2] * b.m_quad[2];
        m_quad[3] = a.m_quad[3] * b.m_quad[3];
    }
    __forceinline void addMul4(hkReal r, const hkVector4& v)
    { m_quad[0] += r * v.m_quad[0]; m_quad[1] += r * v.m_quad[1]; m_quad[2] += r * v.m_quad[2]; m_quad[3] += r * v.m_quad[3]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] + b.m_quad[0];
        m_quad[1] = a.m_quad[1] + b.m_quad[1];
        m_quad[2] = a.m_quad[2] + b.m_quad[2];
        m_quad[3] = a.m_quad[3] + b.m_quad[3];
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    { return (m_quad[0] * v.m_quad[0]) + (m_quad[1] * v.m_quad[1]) + (m_quad[2] * v.m_quad[2]); }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    { const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1); const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2); const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0); set(nx, ny, nz, 0.0f); }
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void operator=(const hkQuaternion& q) { m_vec = q.m_vec; }
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.m_quad[3]; }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
};

struct hkaSkeleton
{
    int m_unk00;
    const short* m_parentIndices;
    int m_unk08;
    int m_unk0c;
    int m_numBones;
};

}

struct SkeletonPoseData
{
    f3m_00955810::hkaSkeleton* m_pSkeleton;
    f3m_00955810::hkQsTransform* m_pLocalPose;
    int m_localPoseSize;
    int m_localPoseCapacity;
    f3m_00955810::hkQsTransform* m_pModelPose;
    int m_modelPoseSize;
    int m_modelPoseCapacity;
    unsigned int* m_pBoneFlags;
    int m_boneFlagsSize;
    int m_boneFlagsCapacity;
    bool m_bPoseFlag;

    void hkaPose_syncModelSpace();
};

// pdb: hkaPose::syncModelSpace | hkaPose.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq) + skyrim(objopen_prop), high
void SkeletonPoseData::hkaPose_syncModelSpace()
{
    using namespace f3m_00955810;
    if (m_bPoseFlag)
        return;

    const int numBones = m_pSkeleton->m_numBones;
    for (int b = 0; b < numBones; b++)
    {
        if (m_pBoneFlags[b] & 2)
        {
            const short parentId = m_pSkeleton->m_parentIndices[b];
            const hkQsTransform& local = m_pLocalPose[b];
            if (parentId != -1)
            {
                const hkQsTransform& parent = m_pModelPose[parentId];
                m_pModelPose[b].setMul(parent, local);
            }
            else
            {
                m_pModelPose[b] = local;
            }
            m_pBoneFlags[b] &= ~2;
        }
    }
    m_bPoseFlag = true;
}
}   // namespace f3m_00955810

// @f3 0x00944440 (community match, verified in this file)
namespace f3m_00944440 {
extern int DAT_010f3170;
namespace d944440 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct MemoryContext { void FUN_008f6d90(void* data, unsigned int bytes, unsigned int category); };
}
struct Obj944440 {
    int unk00;
    unsigned short size;
    void FUN_00944050();
    Obj944440* FUN_00944440(unsigned int flags);
};
// pdb: hkpHavokSnapshot::ConvertListener::`scalar deleting destructor' | hkpHavokSnapshot.obj | fnv360_0822_retail, vtable, high
Obj944440* Obj944440::FUN_00944440(unsigned int flags)
{
    FUN_00944050();
    if (flags & 1) {
        d944440::MemoryContext* context = (d944440::MemoryContext*)d944440::TlsGetValue(*(unsigned long*)&DAT_010f3170);
        context->FUN_008f6d90(this, size, 0x15);
    }
    return this;
}
}

// @f3 0x009438c0 (community match, verified in this file)
extern int DAT_00e7a098;
extern int DAT_00e7a230;
namespace f3m_009438c0 {
namespace f3m_009438c0 {
namespace n9438c0 {
int __cdecl FUN_00923280(char* buffer, unsigned int size, const char* format, ...);
unsigned int __cdecl FUN_009233f0(const char* text);
struct Writer {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Write(const char* text, unsigned int length);
};
// 0x00943620: writes a string, or the 6-character null text; private register convention (text in esi, writer in edi)
static void __declspec(noinline) FUN_00943620(Writer* writer, const char* text)
{
    if (text)
        writer->Write(text, FUN_009233f0(text));
    else
        writer->Write((const char*)&DAT_00e7a230, 6);
}
}
struct Format943 {
    int unk00;
    int unk04;
    n9438c0::Writer* writer;
    Format943* FUN_009438c0(int a, int b);
};
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, objrun, high
// pdb params: i
Format943* Format943::FUN_009438c0(int a, int b)
{
    int text[2506];
    n9438c0::FUN_00923280((char*)text, sizeof(text), (const char*)&DAT_00e7a098, a, b);
    n9438c0::FUN_00943620(writer, (const char*)text);
    return this;
}
}
}   // namespace f3m_009438c0

// @f3 0x009535d0 (community match, verified in this file)
namespace f3m_009535d0 {
namespace f3m_009535d0 {
namespace n9535d0 {
void __cdecl FUN_00901f10(void* array, int elementSize) throw();
template <class T> struct Array {
    T* data;
    int size;
    int capacityAndFlags;
    void PushBack(const T& t)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = t;
        size++;
    }
};
}
struct Owner9535d0 {
    char pad[0x30];
    n9535d0::Array<void*> first;
    n9535d0::Array<void*> second;
    void FUN_009535d0(void* a, void* b);
};
// pdb: hkVisualDebugger::addTrackedObjectCallback | hkVisualDebugger.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: callback, userHandle
void Owner9535d0::FUN_009535d0(void* a, void* b)
{
    first.PushBack(a);
    second.PushBack(b);
}
}
}   // namespace f3m_009535d0

// @f3 0x0095a960 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0095a960 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
namespace task3373 {
struct Heap { void FUN_008f6d90(void*, unsigned int, int); };
struct Object {
    unsigned int vtable;
    unsigned short allocationSize;
    unsigned short flags;
    void FUN_0095a640();
    Object* FUN_0095a960(unsigned int deletionFlags);
};
// pdb: hkpRagdollConstraintData::`scalar deleting destructor' | hkpRagdollConstraintData.obj | fnv360_0822_retail, vtable_prefix, high
Object* Object::FUN_0095a960(unsigned int deletionFlags) {
    FUN_0095a640();
    if (deletionFlags & 1) {
        Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, allocationSize, 0x2c);
    }
    return this;
}
}
}   // namespace f3m_0095a960

// @f3 0x0094bb80 (community match, verified in this file)
extern int DAT_00e7ae04;
namespace f3m_0094bb80 {
namespace f3m_0094bb80 {
struct Obj0094bb80
{
    void* m_vtbl;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    Obj0094bb80* FUN_0094bb80();
};
// 0x0094bb80: initialiser written out (the vtable at 0x00e7ae04 has no symbol to bind a real class to)
Obj0094bb80* Obj0094bb80::FUN_0094bb80()
{
    m_f04 = 0;
    m_f0c = 0;
    m_f10 = 0;
    m_f08 = 1;
    m_vtbl = &DAT_00e7ae04;
    return this;
}
}
}   // namespace f3m_0094bb80

// @f3 0x0094a330 (community match, verified in this file)
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
namespace f3m_0094a330 {

namespace f3m_0094a330 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(const hkReal r) { return ::sqrtf(r); }
    __forceinline hkReal sqrtInverse(const hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline void operator=(const hkVector4& v)
    {
        m_quad[0] = v.m_quad[0];
        m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2];
        m_quad[3] = v.m_quad[3];
    }
    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        m_quad[0] = nx;
        m_quad[1] = ny;
        m_quad[2] = nz;
        m_quad[3] = 0.0f;
    }
    struct SimdS { hkReal r; SimdS(hkReal f) : r(f) {} operator hkReal() const { return r; } };
    __forceinline void mul4(const SimdS& s)
    {
        hkReal f = s;
        m_quad[0] *= f;
        m_quad[1] *= f;
        m_quad[2] *= f;
        m_quad[3] *= f;
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    {
        return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2];
    }
    __forceinline hkReal lengthSquared3() const { return (m_quad[0] * m_quad[0]) + (m_quad[1] * m_quad[1]) + (m_quad[2] * m_quad[2]); }
    __forceinline hkReal lengthInverse3() const
    {
        const hkReal l2 = lengthSquared3();
        return (l2 != 0.0f) ? hkMath::sqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
};

struct hkRotation
{
    hkVector4 m_columns[3];
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
};

// Consumed native view of the SDK set-local-transforms atom: 16-bit type,
// followed by two aligned transforms. No atom lifetime is created here.
struct S0094a330_TransformAtom
{
    unsigned short m_type;
    hkTransform m_transformA;
    hkTransform m_transformB;
};

struct S0094a330_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S0094a330_TransformAtom m_transforms; // atom starts at 0x10
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
    float m_maxFrictionTorque;  // 0xf8
    int unkFC;
    int unk100;
    float m_twistMinAngle;      // 0x104
    float m_twistMaxAngle;      // 0x108
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    float m_coneMaxAngle;       // 0x11c
    int unk120;
    int unk124;
    int unk128;
    float m_planeMinAngle;      // 0x12c
    float m_planeMaxAngle;      // 0x130
};

typedef char AtomSizeCheck[(sizeof(S0094a330_TransformAtom) == 0x90) ? 1 : -1];
typedef char AtomOffsetCheck[(offsetof(S0094a330_Data, m_transforms) == 0x10) ? 1 : -1];
typedef char TransformAOffsetCheck[(offsetof(S0094a330_Data, m_transforms) + offsetof(S0094a330_TransformAtom, m_transformA) == 0x20) ? 1 : -1];
typedef char TransformBOffsetCheck[(offsetof(S0094a330_Data, m_transforms) + offsetof(S0094a330_TransformAtom, m_transformB) == 0x60) ? 1 : -1];

struct S0094a330_BinaryStream;
typedef unsigned int (__cdecl *S0094a330_ReadFn)(S0094a330_BinaryStream* pThis, void* pvBuffer,
    unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct S0094a330_BinaryStream
{
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    S0094a330_ReadFn m_pfnRead;

    __forceinline unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        unsigned int uiNewPos = m_uiAbsoluteCurrentPos + uiBytesRead;
        m_uiAbsoluteCurrentPos = uiNewPos;
        return uiBytesRead;
    }
    __forceinline unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
        unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiAbsoluteCurrentPos += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> __forceinline void S0094a330_LoadBinary(S0094a330_BinaryStream& s, T& v)
{
    unsigned int uiSize = sizeof(T);
    s.BinaryRead(&v, sizeof(T), &uiSize, 1);
}

struct S0094a330_NiStream
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
    unsigned char unk1e4;
    unsigned char endian1e5;
    unsigned char unk1e6;
    unsigned char unk1e7;
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
    S0094a330_BinaryStream* input24c;
    S0094a330_BinaryStream* GetIstr() { return input24c; }
    unsigned char GetEndian() { return endian1e5; }
};

struct S0094a330_CInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_pivotA;     // 0x10
    hkVector4 m_pivotB;     // 0x20
    hkVector4 m_planeA;     // 0x30
    hkVector4 m_planeB;     // 0x40
    hkVector4 m_twistA;     // 0x50
    hkVector4 m_twistB;     // 0x60
    float m_coneMaxAngle;   // 0x70
    float m_planeMinAngle;  // 0x74
    float m_planeMaxAngle;  // 0x78
    float m_twistMinAngle;  // 0x7c
    float m_twistMaxAngle;  // 0x80
    float m_maxFriction;    // 0x84

    S0094a330_CInfo() : unk08(0), unk0C(0) {}
};

static __forceinline void S0094a330_Swap32(hkReal& f)
{
    unsigned int& u = *(unsigned int*)&f;
    u = _byteswap_ulong(u);
}

static __forceinline void S0094a330_Swap(hkVector4& v)
{
    S0094a330_Swap32(v.m_quad[0]);
    S0094a330_Swap32(v.m_quad[1]);
    S0094a330_Swap32(v.m_quad[2]);
    S0094a330_Swap32(v.m_quad[3]);
}

struct S0094a330_Constraint
{
    void* vtbl;
    S0094a330_Data* m_pData;

    void FUN_008fc680(S0094a330_NiStream* pStream, S0094a330_CInfo* pInfo);
    void FUN_0094a330(S0094a330_NiStream* pStream, S0094a330_CInfo* pInfo);
};

}


void f3m_0094a330::S0094a330_Constraint::FUN_0094a330(f3m_0094a330::S0094a330_NiStream* pStream, f3m_0094a330::S0094a330_CInfo* pInfo)
{
    S0094a330_CInfo kInfo;
    if (!pInfo)
    {
        pInfo = &kInfo;
        FUN_008fc680(pStream, pInfo);
    }
    S0094a330_Data* pData = m_pData;

    pStream->GetIstr()->Read(&pInfo->m_pivotA, 0x10);
    pStream->GetIstr()->Read(&pInfo->m_planeA, 0x10);
    pStream->GetIstr()->Read(&pInfo->m_twistA, 0x10);
    pStream->GetIstr()->Read(&pInfo->m_pivotB, 0x10);
    pStream->GetIstr()->Read(&pInfo->m_planeB, 0x10);
    pStream->GetIstr()->Read(&pInfo->m_twistB, 0x10);
    S0094a330_LoadBinary(*pStream->GetIstr(), pInfo->m_coneMaxAngle);
    S0094a330_LoadBinary(*pStream->GetIstr(), pInfo->m_planeMinAngle);
    S0094a330_LoadBinary(*pStream->GetIstr(), pInfo->m_planeMaxAngle);
    S0094a330_LoadBinary(*pStream->GetIstr(), pInfo->m_twistMinAngle);
    S0094a330_LoadBinary(*pStream->GetIstr(), pInfo->m_twistMaxAngle);
    S0094a330_LoadBinary(*pStream->GetIstr(), pInfo->m_maxFriction);

    if (pStream->GetEndian() != 1)
    {
        S0094a330_Swap(pInfo->m_pivotA);
        S0094a330_Swap(pInfo->m_planeA);
        S0094a330_Swap(pInfo->m_twistA);
        S0094a330_Swap(pInfo->m_pivotB);
        S0094a330_Swap(pInfo->m_planeB);
        S0094a330_Swap(pInfo->m_twistB);
    }

    hkVector4 perpA; perpA.setCross(pInfo->m_planeA, pInfo->m_twistA);
    hkVector4 perpB; perpB.setCross(pInfo->m_planeB, pInfo->m_twistB);

    pData->m_transforms.m_transformA.m_translation = pInfo->m_pivotA;
    pData->m_transforms.m_transformA.m_rotation.m_columns[1] = pInfo->m_planeA;
    pData->m_transforms.m_transformA.m_rotation.m_columns[0] = pInfo->m_twistA;
    pData->m_transforms.m_transformA.m_rotation.m_columns[2] = perpA;
    pData->m_transforms.m_transformB.m_translation = pInfo->m_pivotB;
    pData->m_transforms.m_transformB.m_rotation.m_columns[1] = pInfo->m_planeB;
    pData->m_transforms.m_transformB.m_rotation.m_columns[0] = pInfo->m_twistB;
    pData->m_transforms.m_transformB.m_rotation.m_columns[2] = perpB;

    pData->m_coneMaxAngle = pInfo->m_coneMaxAngle;
    pData->m_planeMinAngle = pInfo->m_planeMinAngle;
    pData->m_planeMaxAngle = pInfo->m_planeMaxAngle;
    pData->m_twistMinAngle = pInfo->m_twistMinAngle;
    pData->m_twistMaxAngle = pInfo->m_twistMaxAngle;
    pData->m_maxFrictionTorque = pInfo->m_maxFriction;
    if (pData->m_maxFrictionTorque == 0.0f)
        pData->m_maxFrictionTorque = 100.0f;

    pData->m_transforms.m_transformA.m_rotation.m_columns[1].normalize3();
    pData->m_transforms.m_transformA.m_rotation.m_columns[0].normalize3();
    pData->m_transforms.m_transformA.m_rotation.m_columns[2].normalize3();
    pData->m_transforms.m_transformB.m_rotation.m_columns[1].normalize3();
    pData->m_transforms.m_transformB.m_rotation.m_columns[0].normalize3();
    pData->m_transforms.m_transformB.m_rotation.m_columns[2].normalize3();
}


}   // namespace f3m_0094a330

// @f3 0x0095a990 (community match, verified in this file)
#include <intrin.h>
extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
namespace f3m_0095a990 {
// claim clm_e75c1201796f49d0a62d -- FUN_0095a990 at 0x0095a990, 291 bytes
// Physics timer around a "set effect" helper: monitor-stream tags (Tt.../Et) plus an
// effect node taken from (or pushed into) the effect list.


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);

namespace f3m_0095a990 {

struct ProfRec { const char* m_pName; unsigned int m_iTick; unsigned int unk08; };
struct ProfBuf { unsigned int unk00; ProfRec* m_pCur; unsigned int unk08; ProfRec* m_pEnd; };

struct FreeNode { FreeNode* m_pNext; };
struct NodePool {
    void* unk00; void* unk04; void* unk08; void* unk0C;
    void* unk10; void* unk14; void* unk18; void* unk1C;
    void* unk20; void* unk24; void* unk28; void* unk2C;
    void* unk30; void* unk34; void* unk38; void* unk3C;
    void* unk40; void* unk44; void* unk48; void* unk4C;
    void* unk50; void* unk54;
    FreeNode* m_pFree;
    int m_nFree;
    void* FUN_008f6800(unsigned int a, unsigned int b);
};

struct Holder {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18;
};

struct Target {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
};

struct Owner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual Holder* v40();
};

struct Effect {
    unsigned short m_type;
    unsigned int unk04, unk08, unk0C;
    unsigned short unk10;
    unsigned int unk14, unk18, unk1C;
    float m_f20;
    float m_f24;
    unsigned int unk28;
    static void* operator new(unsigned int) {
        NodePool* pool = (NodePool*)TlsGetValue(DAT_010f3170);
        FreeNode* node = pool->m_pFree;
        if (node) {
            pool->m_nFree--;
            pool->m_pFree = node->m_pNext;
            return node;
        }
        return pool->FUN_008f6800(4, 0x2c);
    }
    Effect() {
        m_type = 0x18;
        unk10 = 0x30;
    }
};

Effect* __cdecl FUN_009a94f0(Holder* h, int type);
void __cdecl FUN_009a9550(Holder* h, Target* t, Effect* e);

// pdb: hkpResponseModifier::setInvMassScalingForContact | hkpResponseModifier.obj | fnv360_0822_retail, objrun_open, low
// pdb params: manager, bodyA, bodyB, constraintOwner, factorA, factorB
void __cdecl FUN_0095a990(Owner* a1, int a2, int a3, Target* a4, float f1, float f2)
{
    volatile unsigned int ticks;
    Holder* h = a1->v40();
    if (h) {
        a4->v18();
        ProfBuf* pb = (ProfBuf*)TlsGetValue(DAT_0116913c);
        ProfRec* r = pb->m_pCur;
        if (r < pb->m_pEnd) {
            r->m_pName = "TtSetMassChang";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            r->m_iTick = ticks;
            pb->m_pCur = r + 1;
        }
        float t1 = f1;
        float t2 = f2;
        if (a2 == h->unk18) {
            t1 = f2;
            t2 = f1;
        }
        Effect* e = FUN_009a94f0(h, 0x18);
        if (e) {
            e->m_f20 = t1;
            e->m_f24 = t2;
        } else {
            e = new Effect;
            e->m_f20 = t1;
            e->m_f24 = t2;
            FUN_009a9550(h, a4, e);
        }
        pb = (ProfBuf*)TlsGetValue(DAT_0116913c);
        ProfRec* r2 = pb->m_pCur;
        if (r2 < pb->m_pEnd) {
            r2->m_pName = "Et";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            r2->m_iTick = ticks;
            pb->m_pCur = r2 + 1;
        }
    }
}

}
}   // namespace f3m_0095a990

// @f3 0x0095c070 (community match, verified in this file)
// FUN_0095c070 = Havok 5.5.0 hkaFootPlacementIkSolver::doFootPlacement (hkaAnimation.lib, hkaFootPlacementIkSolver.obj).
// Reduced from sdk_noparen.cpp with hktrim.py; SDK inline bodies hktrim left out were added back as SDK text;
// castFoot (record lines 416-511) kept after the target as in the .cpp. See note.txt.
namespace f3m_0095c070 {
typedef float  hkReal;
typedef signed short	hkInt16;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
class hkClass;
typedef int hkBool32;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
};

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
	public:
		__forceinline T& operator[] (int i);
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
	private:
		int m_mask;
		friend class hkVector4;
};

struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
extern const hkQuadReal hkQuadReal0000;

extern "C" {
 double  __cdecl fabs(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
}

extern "C" {
        double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

class hkQuaternion;
class hkQsTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize4();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline static const hkVector4& __cdecl getZero();
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		                class MustEndWithSemiColon;
		inline void operator= (const hkQuaternion& q);
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline hkReal getReal() const;
		__forceinline const hkVector4& getImag() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};

class hkQsTransform
{
	public:
		                class MustEndWithSemiColon;
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline const hkVector4& getTranslation() const;
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setInverse( const hkQsTransform &t );
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

__forceinline void hkVector4::setXYZ0(const hkVector4& xyz)
{
	x = xyz.x;
	y = xyz.y;
	z = xyz.z;
	w = 0;
}

inline void hkVector4::setReciprocal3(const hkVector4& v)
{
	x = 1.0f / v.x;
	y = 1.0f / v.y;
	z = 1.0f / v.z;
	w = 1.0f;
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	return (&x)[i];
}

inline void hkVector4::setAll3(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}

inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}

inline void hkVector4::subMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x -= r * a.x;
	y -= r * a.y;
	z -= r * a.z;
	w -= r * a.w;
}

inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}

inline hkVector4Comparison hkVector4::compareLessThanEqual4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<=a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<=a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<=a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<=a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}

inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

	inline hkSimdReal hkVector4::lengthInverse4() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z) + (w*w);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize4()
	{
		this->mul4( this->lengthInverse4() );
	}

inline hkBool32 hkVector4::equals3(const hkVector4 &v, hkReal epsilon) const
{
	hkVector4 t;
	t.setSub4(*this, v);
	t.setAbs4( t );
	hkVector4 epsilon_v;
	epsilon_v.setAll3( epsilon );
	return t.compareLessThanEqual4( epsilon_v ).allAreSet( hkVector4Comparison::MASK_XYZ );
}

inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&hkQuadReal0000);
	return zero;
}

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( direction, quat.getImag() );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}

inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}

inline hkReal hkQuaternion::getReal() const
{
	return m_vec(3);
}

inline void hkQuaternion::setIdentity()
{
	m_vec.set(0,0,0,1);
}

inline void hkQuaternion::normalize()
{
	m_vec.normalize4();
}

inline void hkQuaternion::operator= (const hkQuaternion& q)
{
	m_vec = q.m_vec;
}

inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
	hkVector4 vec;
	vec.setCross(q0.getImag(), q1.getImag());
	vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
	vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
	hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.m_vec.dot3( q1.m_vec ) );
	m_vec = vec;
	m_vec(3) = real;
}

void hkQuaternion::setInverse( const hkQuaternion &q )
{
	m_vec.setNeg3( q.getImag() );
}

inline void hkQuaternion::setShortestRotation(const hkVector4& from, const hkVector4& to)
{
	const hkReal dotProd = from.dot3( to );
	const hkReal nearlyOne = 1.0f - 1e-5f;
	const hkReal somewhatNearlyOne = 1.0f - 1e-3f;
	if( dotProd > nearlyOne )
	{
		setIdentity();
	}
	else if( dotProd < -nearlyOne )
	{
		setFlippedRotation( from );
	}
	else
	{
		const hkReal c = (dotProd + 1.0f) * 0.5f;
		const hkReal cosT2 = hkMath::sqrt( c );
		hkVector4 cross;
		cross.setCross( from, to );
		hkReal rescaleSin  = 0.5f / cosT2;
		if (dotProd < -somewhatNearlyOne)
		{
			const hkReal sinT2 = hkMath::sqrt( cosT2 * cosT2 - dotProd );
			const hkReal approxSinT = cross.length3();
			const hkReal sinT = 2 * sinT2 * cosT2;
			rescaleSin *= (sinT / approxSinT);
		}
		cross.mul4( rescaleSin );
		cross(3) = cosT2;
		m_vec = cross;
	}
}

const hkVector4& hkQsTransform::getTranslation() const
{
	return m_translation;
}

const hkQuaternion& hkQsTransform::getRotation() const
{
	return m_rotation;
}

void hkQsTransform::setRotation(const hkQuaternion& rotation)
{
	m_rotation = rotation;
}

hkQsTransform::hkQsTransform(const hkQsTransform& t)
{
	m_translation = t.m_translation;
	m_rotation = t.m_rotation;
	m_scale = t.m_scale;
}

void hkQsTransform::setInverse( const hkQsTransform& t )
{
	m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
	m_translation.setNeg4(m_translation);
	m_rotation.setInverse(t.m_rotation);
	hkVector4 invScale; invScale.setReciprocal3( t.m_scale );
	m_scale.setXYZ0( invScale );
}

class hkaSkeleton;
class hkaPose;

class hkaRaycastInterface
{
	public:
		virtual ~hkaRaycastInterface() { }
		virtual hkBool castRay ( const hkVector4& fromWS, const hkVector4& toWS, hkReal& hitFractionOut, hkVector4& normalWSOut ) = 0;
};

class hkaFootPlacementIkSolver : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		struct Setup
		{
			                class MustEndWithSemiColon;
			const hkaSkeleton* m_skeleton;
			hkInt16 m_hipIndex;
			hkInt16 m_kneeIndex;
			hkInt16 m_ankleIndex;
			hkVector4 m_kneeAxisLS;
			hkVector4 m_footEndLS;
			hkVector4 m_worldUpDirectionWS;
			hkVector4 m_modelUpDirectionMS;
			hkReal m_originalGroundHeightMS;
			hkReal m_footPlantedAnkleHeightMS;
			hkReal m_footRaisedAnkleHeightMS;
			hkReal m_maxAnkleHeightMS;
			hkReal m_minAnkleHeightMS;
			hkReal m_cosineMaxKneeAngle;
			hkReal m_cosineMinKneeAngle;
			hkReal m_raycastDistanceUp;
			hkReal m_raycastDistanceDown;
			hkBool m_useFootLocking;
		};
		struct Input
		{
			                class MustEndWithSemiColon;
			hkQsTransform m_originalAnkleTransformMS;
			hkQsTransform m_worldFromModel;
			hkBool m_footPlacementOn;
			hkaRaycastInterface* m_raycastInterface;
			hkReal m_onOffGain;
			hkReal m_groundAscendingGain;
			hkReal m_groundDescendingGain;
			hkReal m_footPlantedGain;
			hkReal m_footRaisedGain;
			hkReal m_footUnlockGain;
		};
		struct Output
		{
			                class MustEndWithSemiColon;
			hkReal m_verticalError;
			hkBool m_hitSomething;
		};
		void FUN_0095c070 (const Input& input, Output& output, hkaPose& poseInOut);
		Setup m_setup;
	private:
		hkReal m_currentWeight;
		hkReal m_previousGroundHeightWS;
		hkVector4 m_previousGroundNormalWS;
		hkReal m_previousVerticalDisplacement;
		hkBool m_isFootLocked;
		hkVector4 m_lockedFootPositionInWS;
		hkVector4 m_lockedFootEndPositionInWS;
		hkVector4 m_footUnlockingOffset;
		hkBool castFoot( hkaRaycastInterface* raycastInterface, const hkVector4& footWS, const hkVector4& footEndWS, hkVector4& projectedFootWSOut, hkVector4& groundNormalWSOut ) const;
};

class hkaTwoJointsIkSolver : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		struct Setup
		{
			                class MustEndWithSemiColon;
			hkInt16 m_firstJointIdx;
			hkInt16 m_secondJointIdx;
			hkInt16 m_endBoneIdx;
			hkVector4 m_hingeAxisLS;
			hkReal m_cosineMaxHingeAngle;
			hkReal m_cosineMinHingeAngle;
			hkReal m_firstJointIkGain;
			hkReal m_secondJointIkGain;
			hkVector4 m_endTargetMS;
			Setup() ;
		};
		static hkBool __cdecl solve ( const Setup& setup, hkaPose& poseInOut );
};

class hkaPose
{
public:
	                class MustEndWithSemiColon;
	enum PoseSpace
	{
		MODEL_SPACE,
		LOCAL_SPACE
	};
	enum PropagateOrNot
	{
		DONT_PROPAGATE = 0,
		PROPAGATE = 1
	};
	__forceinline const hkQsTransform& getBoneModelSpace (int boneIdx) const;
	hkQsTransform& accessBoneModelSpace (int boneIdx, PropagateOrNot propagateOrNot = DONT_PROPAGATE);
private:
	typedef hkUint32 hkaPoseFlag;
	const hkaSkeleton* m_skeleton;
	mutable hkArray<hkQsTransform> m_localPose;
	mutable hkArray<hkQsTransform> m_modelPose;
	mutable hkArray<hkaPoseFlag> m_boneFlags;
	mutable hkBool m_modelInSync;
	mutable hkBool m_localInSync;
	hkArray<hkReal> m_floatSlotValues;
	enum
	{
		F_BONE_LOCAL_DIRTY = 0x1,
		F_BONE_MODEL_DIRTY = 0x2,
		F_BONE_INTERNAL_FLAG1 = 0x4,
		F_BONE_INTERNAL_FLAG2 = 0x8,
		F_BONE_INTERNAL_FLAG3 = 0x10,
	};
	enum
	{
		M_BONE_INTERNAL_FLAGS = F_BONE_INTERNAL_FLAG1 | F_BONE_INTERNAL_FLAG2 | F_BONE_INTERNAL_FLAG3
	};
	__forceinline int isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const;
	const hkQsTransform& calculateBoneModelSpace (int boneIdx) const;
};

int hkaPose::isFlagOn (int boneIdx, hkaPoseFlag enumToCheck) const
{
	return m_boneFlags[boneIdx] & enumToCheck;
}

const hkQsTransform& hkaPose::getBoneModelSpace (int boneIdx) const
{
	if (!isFlagOn (boneIdx, F_BONE_MODEL_DIRTY))
	{
		return m_modelPose[boneIdx];
	}
	else
	{
		return calculateBoneModelSpace(boneIdx);
	}
}

void hkaFootPlacementIkSolver::FUN_0095c070 (const Input& input, Output& output, hkaPose& poseInOut)
{
	const hkQsTransform& worldFromModel = input.m_worldFromModel;
	hkQsTransform modelFromWorld; modelFromWorld.setInverse(worldFromModel);
	hkVector4 worldUpMS; worldUpMS.setRotatedDir(modelFromWorld.getRotation(), m_setup.m_worldUpDirectionWS);
	output.m_hitSomething = true;
	const hkReal desiredFootHeightMS = input.m_originalAnkleTransformMS.getTranslation().dot3(m_setup.m_modelUpDirectionMS);
	const hkQuaternion& originalFootRotationMS = input.m_originalAnkleTransformMS.getRotation();
	hkQuaternion inputAnkleOrientationMS = poseInOut.getBoneModelSpace(m_setup.m_ankleIndex).getRotation();
	hkQsTransform footCurrentMS = poseInOut.getBoneModelSpace(m_setup.m_ankleIndex);
	hkVector4 footCurrentPosWS; footCurrentPosWS.setTransformedPos(worldFromModel, footCurrentMS.getTranslation());
	bool footPlacementOn = input.m_footPlacementOn;
	hkVector4 groundNormalWS;
	hkVector4 footTargetPosMS;
	hkReal actualGroundHeightWS;
	hkReal blendedGroundHeightWS;
	if (!footPlacementOn)
	{
		output.m_hitSomething = false;
		groundNormalWS = m_previousGroundNormalWS;
		footTargetPosMS.setAddMul4(footCurrentMS.getTranslation(), worldUpMS, m_previousVerticalDisplacement);
		actualGroundHeightWS = footCurrentPosWS.dot3(m_setup.m_worldUpDirectionWS) + m_previousVerticalDisplacement - desiredFootHeightMS;
		blendedGroundHeightWS = actualGroundHeightWS;
		output.m_verticalError = 0.0f;
		m_isFootLocked = false;
	}
	else
	{
		bool wasLocked = m_isFootLocked;
		if (m_setup.m_useFootLocking)
		{
			m_isFootLocked = false;
			if (desiredFootHeightMS < m_setup.m_footPlantedAnkleHeightMS)
			{
				if (wasLocked)
				{
					footCurrentPosWS = m_lockedFootPositionInWS;
					footCurrentMS.m_translation.setTransformedPos(modelFromWorld, footCurrentPosWS);
				}
				else
				{
					m_lockedFootPositionInWS = footCurrentPosWS;
					hkVector4 footEndCurrentPosMS; footEndCurrentPosMS.setTransformedPos(footCurrentMS, m_setup.m_footEndLS);
					m_lockedFootEndPositionInWS.setTransformedPos(worldFromModel, footEndCurrentPosMS);
				}
				m_isFootLocked = true;
			}
		}
		hkVector4 footEndCurrentPosWS;
		{
			hkVector4 footEndCurrentPosMS; footEndCurrentPosMS.setTransformedPos(footCurrentMS, m_setup.m_footEndLS);
			if (m_setup.m_useFootLocking && m_isFootLocked)
			{
				footEndCurrentPosWS = m_lockedFootEndPositionInWS;
			}
			else
			{
				footEndCurrentPosWS.setTransformedPos(worldFromModel, footEndCurrentPosMS);
			}
		}
		hkVector4 projectedFootPosWS;
		bool hit = castFoot(input.m_raycastInterface, footCurrentPosWS, footEndCurrentPosWS, projectedFootPosWS, groundNormalWS);
		if (!hit)
		{
			output.m_hitSomething = false;
			footPlacementOn = false;
			groundNormalWS = m_previousGroundNormalWS;
			footTargetPosMS.setAddMul4(footCurrentMS.getTranslation(), worldUpMS, m_previousVerticalDisplacement);
			actualGroundHeightWS = footCurrentPosWS.dot3(m_setup.m_worldUpDirectionWS) + m_previousVerticalDisplacement - desiredFootHeightMS;
			blendedGroundHeightWS = actualGroundHeightWS;
			output.m_verticalError = 0.0f;
			m_isFootLocked = false;
		}
		else
		{
			if (m_isFootLocked)
			{
				m_lockedFootPositionInWS = projectedFootPosWS;
				footCurrentPosWS = projectedFootPosWS;
				footCurrentMS.m_translation.setTransformedPos(modelFromWorld, footCurrentPosWS);
				hkVector4 footEndCurrentPosMS; footEndCurrentPosMS.setTransformedPos(footCurrentMS, m_setup.m_footEndLS);
				m_lockedFootEndPositionInWS.setTransformedPos(worldFromModel, footEndCurrentPosMS);
			}
			output.m_hitSomething = true;
			actualGroundHeightWS = projectedFootPosWS.dot3(m_setup.m_worldUpDirectionWS);
			output.m_verticalError = actualGroundHeightWS - (worldFromModel.getTranslation().dot3(m_setup.m_worldUpDirectionWS) + m_setup.m_originalGroundHeightMS);
			groundNormalWS(3) = 0.0f;
			hkVector4 nonVerticalHitPointWS; nonVerticalHitPointWS.setAddMul4(projectedFootPosWS, m_setup.m_worldUpDirectionWS, -actualGroundHeightWS);
			// Fake match: the cast to double (and the hkReal() around it) is a steering device with no evidence in the SDK or its debug records; it adds a compiler temporary. Natural form: 1.0f - (a - b) / (c - b).
			hkReal footPlantWeight = hkReal(1.0f - (double)((desiredFootHeightMS - m_setup.m_footPlantedAnkleHeightMS) / (m_setup.m_footRaisedAnkleHeightMS - m_setup.m_footPlantedAnkleHeightMS)));
			if (footPlantWeight < input.m_footRaisedGain) footPlantWeight = input.m_footRaisedGain;
			if (footPlantWeight > input.m_footPlantedGain) footPlantWeight = input.m_footPlantedGain;
			if (m_currentWeight == 0.0f)
			{
				blendedGroundHeightWS = actualGroundHeightWS;
			}
			else
			{
				hkReal gain;
				{
					const hkReal factor = (actualGroundHeightWS < m_previousGroundHeightWS) ? input.m_groundDescendingGain : input.m_groundAscendingGain;
					gain = footPlantWeight * factor;
				}
				// Fake match: the cast to double, the hkReal() and the swapped addition order are a steering device with no evidence; natural form: m_previousGroundHeightWS + (actual - prev) * gain.
				blendedGroundHeightWS = hkReal((double)((actualGroundHeightWS - m_previousGroundHeightWS) * gain) + m_previousGroundHeightWS);
			}
			if (m_setup.m_useFootLocking)
			{
				if (m_isFootLocked)
				{
					m_footUnlockingOffset.setZero4();
				}
				else
				{
					if (wasLocked)
					{
						m_footUnlockingOffset.setSub4(m_lockedFootPositionInWS, nonVerticalHitPointWS);
						m_footUnlockingOffset.subMul4(m_footUnlockingOffset.dot3(m_setup.m_worldUpDirectionWS), m_setup.m_worldUpDirectionWS);
					}
					nonVerticalHitPointWS.add4(m_footUnlockingOffset);
					m_footUnlockingOffset.mul4(1.0f - input.m_footUnlockGain);
				}
			}
			hkVector4 dampedHitPointWS; dampedHitPointWS.setAddMul4(nonVerticalHitPointWS, m_setup.m_worldUpDirectionWS, blendedGroundHeightWS);
			hkVector4 dampedHitPointMS; dampedHitPointMS.setTransformedPos(modelFromWorld, dampedHitPointWS);
			footTargetPosMS.setAddMul4(dampedHitPointMS, worldUpMS, desiredFootHeightMS - m_setup.m_originalGroundHeightMS);
			{
				const hkReal maxFootHeightMS = m_setup.m_maxAnkleHeightMS;
				const hkReal minFootHeightMS = m_setup.m_minAnkleHeightMS;
				const hkReal footHeightMS = footTargetPosMS.dot3(m_setup.m_modelUpDirectionMS);
				if (footHeightMS > maxFootHeightMS)
				{
					footTargetPosMS.addMul4(maxFootHeightMS - footHeightMS, m_setup.m_modelUpDirectionMS);
				}
				if (footHeightMS < minFootHeightMS)
				{
					output.m_hitSomething = false;
					footPlacementOn = false;
					groundNormalWS = m_previousGroundNormalWS;
					footTargetPosMS.setAddMul4(footCurrentMS.getTranslation(), worldUpMS, m_previousVerticalDisplacement);
					actualGroundHeightWS = footCurrentPosWS.dot3(m_setup.m_worldUpDirectionWS) + m_previousVerticalDisplacement - desiredFootHeightMS;
					blendedGroundHeightWS = actualGroundHeightWS;
					output.m_verticalError = 0.0f;
				}
				hkVector4 diffMS; diffMS.setSub4(footTargetPosMS, footCurrentMS.getTranslation());
				hkReal verticalDisplacement = diffMS.dot3(m_setup.m_modelUpDirectionMS);
				m_previousVerticalDisplacement = verticalDisplacement;
			}
		}
	}
	const hkReal targetWeight = footPlacementOn ? 1.0f : 0.0f;
	m_currentWeight += (targetWeight - m_currentWeight) * input.m_onOffGain;
	if (m_currentWeight < 0.01f)
	{
		m_currentWeight = 0.0f;
	}
	if (m_currentWeight > 0.0f)
	{
		{
			hkaTwoJointsIkSolver::Setup ikSetup;
			ikSetup.m_firstJointIdx = m_setup.m_hipIndex;
			ikSetup.m_secondJointIdx = m_setup.m_kneeIndex;
			ikSetup.m_endBoneIdx = m_setup.m_ankleIndex;
			ikSetup.m_hingeAxisLS = m_setup.m_kneeAxisLS;
			ikSetup.m_endTargetMS = footTargetPosMS;
			ikSetup.m_cosineMinHingeAngle = m_setup.m_cosineMinKneeAngle;
			ikSetup.m_cosineMaxHingeAngle = m_setup.m_cosineMaxKneeAngle;
			ikSetup.m_firstJointIkGain = m_currentWeight;
			ikSetup.m_secondJointIkGain = m_currentWeight;
			hkaTwoJointsIkSolver::solve(ikSetup, poseInOut);
		}
		{
			const hkVector4& desiredUpWS = groundNormalWS;
			hkVector4 worldUpDirectionMS; worldUpDirectionMS.setRotatedDir(modelFromWorld.getRotation(), m_setup.m_worldUpDirectionWS);
			hkVector4 desiredUpMS; desiredUpMS.setRotatedDir(modelFromWorld.getRotation(), desiredUpWS);
			hkQuaternion extraRotation; extraRotation.setShortestRotation(worldUpDirectionMS, desiredUpMS);
			hkQuaternion newRotationMS; newRotationMS.setMul(extraRotation, originalFootRotationMS);
			hkQuaternion blendedRotation;
			blendedRotation.m_vec.setInterpolate4(originalFootRotationMS.m_vec, newRotationMS.m_vec, m_currentWeight);
			blendedRotation.normalize();
			poseInOut.accessBoneModelSpace(m_setup.m_ankleIndex, hkaPose::PROPAGATE).setRotation(blendedRotation);
		}
	}
	else
	{
		output.m_verticalError = 0.0f;
	}
	m_previousGroundNormalWS = groundNormalWS;
	m_previousGroundHeightWS = blendedGroundHeightWS;
}

hkBool hkaFootPlacementIkSolver::castFoot( hkaRaycastInterface* raycastInterface, const hkVector4& footWS, const hkVector4& footEndWS, hkVector4& projectedFootWSOut, hkVector4& groundNormalWSOut ) const
{
	const hkReal rayUpDistance = m_setup.m_raycastDistanceUp;
	const hkReal rayDownDistance = m_setup.m_raycastDistanceDown;
	const hkReal rayLength = rayUpDistance + rayDownDistance;
	hkBool firstRayHit = false;
	hkReal firstRayFraction = 3.40282e+38f;
	hkVector4 firstRayNormalWS;
	{
		hkVector4 footToWS; footToWS.setAddMul4(footWS, m_setup.m_worldUpDirectionWS, -rayDownDistance);
		hkVector4 footFromWS; footFromWS.setAddMul4(footWS, m_setup.m_worldUpDirectionWS, rayUpDistance);
		firstRayHit = raycastInterface->castRay(footFromWS, footToWS, firstRayFraction, firstRayNormalWS);
	}
	hkBool secondRayHit = false;
	hkReal secondRayFraction = 3.40282e+38f;
	hkVector4 secondRayNormalWS;
	if (!footEndWS.equals3(footWS))
	{
		hkVector4 footEndToWS; footEndToWS.setAddMul4(footEndWS, m_setup.m_worldUpDirectionWS, -rayDownDistance);
		hkVector4 footEndFromWS; footEndFromWS.setAddMul4(footEndWS, m_setup.m_worldUpDirectionWS, rayUpDistance);
		hkReal footEndRayFraction;
		secondRayHit = raycastInterface->castRay(footEndFromWS, footEndToWS, footEndRayFraction, secondRayNormalWS);
		if (secondRayHit)
		{
			const hkReal cosAngle = secondRayNormalWS.dot3(m_setup.m_worldUpDirectionWS);
			if (cosAngle <= 0.0f)
			{
				secondRayHit = false;
			}
			else
			{
				hkVector4 ray; ray.setSub4(footEndToWS, footEndFromWS);
				hkVector4 footEndHitPointWS; footEndHitPointWS.setAddMul4(footEndFromWS, ray, footEndRayFraction);
				const hkReal d = -footEndHitPointWS.dot3(secondRayNormalWS);
				hkVector4 footFromWS; footFromWS.setAddMul4(footWS, m_setup.m_worldUpDirectionWS, rayUpDistance);
				const hkReal Vd = -rayLength * cosAngle;
				const hkReal Vo = -(secondRayNormalWS.dot3(footFromWS) + d);
				const hkReal t = Vo / Vd;
				secondRayFraction = t;
			}
		}
	}
	if (!firstRayHit && !secondRayHit)
	{
		return false;
	}
	else
	{
		hkReal shortestFraction;
		if (!firstRayHit || (firstRayFraction > secondRayFraction))
		{
			shortestFraction = secondRayFraction;
			groundNormalWSOut = secondRayNormalWS;
		}
		else
		{
			shortestFraction = firstRayFraction;
			groundNormalWSOut = firstRayNormalWS;
		}
		const hkReal verticalDistanceOut = shortestFraction * rayLength - rayUpDistance;
		projectedFootWSOut.setAddMul4(footWS, m_setup.m_worldUpDirectionWS, -verticalDistanceOut);
		return true;
	}
}

} // namespace f3m_0095c070

// @f3 0x00955ab0 (community match, verified in this file)
namespace f3m_00955ab0 {
namespace pose_constraints {
using f3m_00955d90::f3m_00955d90::hkaSkeleton;
using f3m_00955d90::f3m_00955d90::hkaBone;
using f3m_00955d90::f3m_00955d90::hkQsTransform;
using f3m_00955d90::f3m_00955d90::hkArray;

class hkaPose {
public:
    enum { BoneModelDirty = 2, BoneChanged = 4, InternalFlags = 0x1c };

    const hkaSkeleton* m_skeleton;
    mutable hkArray<hkQsTransform> m_localPose;
    mutable hkArray<hkQsTransform> m_modelPose;
    mutable hkArray<unsigned> m_boneFlags;
    mutable bool m_modelInSync, m_localInSync;

    void hkaPose_syncLocalSpace() const;
    void hkaPose_syncModelSpace() const;
    hkArray<hkQsTransform>& FUN_00954fc0();
    hkArray<hkQsTransform>& FUN_00955ab0();
    void FUN_00955ac0();

    inline unsigned flagged(int index, unsigned flag) const {
        return m_boneFlags[index] & flag;
    }
    inline void setFlag(int index, unsigned flag) const {
        m_boneFlags[index] |= flag;
    }
    inline void clearInternalFlags() const {
        const int count = m_boneFlags.getSize();
        for (int i = 0; i < count; ++i)
            m_boneFlags[i] &= ~InternalFlags;
    }
};

// accessSyncedPoseModelSpace
// pdb: hkaPose::accessSyncedPoseModelSpace | hkaPose.obj | tesv_win, objrun_open, low
hkArray<hkQsTransform>& hkaPose::FUN_00955ab0()
{
    hkaPose_syncModelSpace();
    return FUN_00954fc0();
}

}
}   // namespace f3m_00955ab0

// @f3 0x00942310 (community match, verified in this file)
namespace f3m_00942310 {
namespace f3m_00942310 {
struct Ref {
    virtual void Destroy(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
};
struct Obj {
    Ref* unk00;
    void FUN_00942160();
    void FUN_00942800();
    void FUN_00942310();
};
// pdb: hkCpuJobThreadPool::waitForCompletion | hkCpuJobThreadPool.obj | tesv_win, objrun_open, low
void Obj::FUN_00942310() {
    Ref* r = unk00;
    if (r && r->memSizeAndFlags != 0) {
        --r->referenceCount;
        if (r->referenceCount == 0) r->Destroy(1);
    }
    FUN_00942160();
    FUN_00942800();
}
}
}   // namespace f3m_00942310
