// gamebryo2.2/corelibs/nianimation/nipoint3interpolator.cpp: NiPoint3Interpolator, NiPoint3InterpolatorRange, PosInterpEq (23 functions)
#include "f3_common.h"
#include "nipoint3interpolator_unit.h"

// Samples the interpolator's position data at the given time into m_kPoint3Value and returns whether the value differs from the default point.
// @fnv 0x00a49870
// pdb: NiPoint3Interpolator::GetSequenceInterpolator | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: NiPoint3Interpolator::Update)
// pdb params: fStartTime, fEndTime
bool NiPoint3Interpolator::Update(float time, NiObjectNET* target, NiPoint3& value)
{
    if (m_fLastTime == time)
    {
        value = m_kPoint3Value;
        if (m_kPoint3Value.x != DAT_011a9424 || m_kPoint3Value.y != DAT_011a9428 || m_kPoint3Value.z != DAT_011a942c)
            return true;
        return false;
    }

    NiPosData* pData = m_spPoint3Data;
    if (pData)
    {
        unsigned int numKeys = pData->m_uiNumKeys;
        AnimationKey::KeyType type = pData->m_eType;
        unsigned char keySize = pData->m_ucKeySize;
        PositionKeyInterpolator* keys = pData->m_pkKeys;
        if (numKeys > 0)
        {
            m_kPoint3Value =
                PositionKeyInterpolator::InterpolatePosition(time, keys, type, numKeys, m_uiLastIdx, keySize);
        }
    }

    if (m_kPoint3Value.x == DAT_011a9424 && m_kPoint3Value.y == DAT_011a9428 && m_kPoint3Value.z == DAT_011a942c)
        return false;

    value = m_kPoint3Value;
    m_fLastTime = time;
    return true;
}

#include "nipoint3interpolator_create.h"
#pragma optimize("", off)
#pragma optimize("", on)

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a49530_shell : public NiPoint3Interpolator
{
    void NiPoint3Interpolator_LoadBinary(NiStream*);
};

class NiColor
{
  public:
    void LoadBinary(NiStream&);
};

struct NiStream
{
    NiObject* DeserializeObject(void);
};

struct NiKeyBasedInterpolator_LoadBinary_Helper : public NiKeyBasedInterpolator
{
    virtual void LoadBinary(NiStream&);
};

// Loads the base interpolator and a NiColor from the stream, then reads a NiObject and stores it as a ref-counted member.
// @fnv 0x00a49530
// pdb: NiPoint3Interpolator::LoadBinary | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun + bridge(vtable|objrun) + skyrim(caller_sim), high
void FUN_00a49530_shell::NiPoint3Interpolator_LoadBinary(NiStream* pkStream)
{
    reinterpret_cast<NiKeyBasedInterpolator_LoadBinary_Helper*>(this)
        ->NiKeyBasedInterpolator_LoadBinary_Helper::LoadBinary(*pkStream);
    reinterpret_cast<NiColor*>(&m_kPoint3Value)->LoadBinary(*pkStream);
    NiObject* pkData = pkStream->DeserializeObject();
    NiObject*& rspData = *reinterpret_cast<NiObject**>(&m_spPoint3Data);
    if (rspData != pkData)
    {
        if (rspData)
            rspData->DecRefCount();
        rspData = pkData;
        if (pkData)
            pkData->IncRefCount();
    }
}

void __fastcall FUN_00a3ca30(void* pThis);

struct NiMemObject_Delete : public NiMemObject
{
    static void __cdecl operator delete(void* pvMem, size_t stElementSize);
};

// @fnv 0x00a49ae0
// pdb: NiPoint3Interpolator::`scalar deleting destructor' | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, high
NiPoint3Interpolator* __fastcall FUN_00a49ae0(NiPoint3Interpolator* pThis, int, unsigned int uiFlags)
{
    NiPosData* pkData = pThis->m_spPoint3Data;
    if (pkData)
        pkData->DecRefCount();

    FUN_00a3ca30(pThis);

    if (uiFlags & 1)
        NiMemObject_Delete::operator delete(pThis, 0x20);

    return pThis;
}

// @fnv 0x00a49410
// pdb: NiPoint3Interpolator::GetKeyCount | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: usChannel
void* __fastcall FUN_00a49410(char* self, int, int)
{
    NiPosData* pkData = ((NiPoint3Interpolator*)self)->m_spPoint3Data;
    if (!pkData)
        return 0;
    return (void*)pkData->m_uiNumKeys;
}

// @fnv 0x00a49420
// pdb: NiPoint3Interpolator::GetKeyType | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: usChannel
void* __fastcall FUN_00a49420(char* self, int, int)
{
    NiPosData* pkData = ((NiPoint3Interpolator*)self)->m_spPoint3Data;
    if (!pkData)
        return 0;
    return (void*)pkData->m_eType;
}

// @fnv 0x00a49430
// pdb: NiPoint3Interpolator::GetKeyArray | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: usChannel
void* __fastcall FUN_00a49430(char* self, int, int)
{
    NiPosData* pkData = ((NiPoint3Interpolator*)self)->m_spPoint3Data;
    if (!pkData)
        return 0;
    return (void*)pkData->m_pkKeys;
}

// @fnv 0x00a49440
// pdb: NiPoint3Interpolator::GetKeyStride | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: usChannel
unsigned char __fastcall FUN_00a49440(char* self, int, int)
{
    NiPosData* pkData = ((NiPoint3Interpolator*)self)->m_spPoint3Data;
    if (!pkData)
        return 0;
    return pkData->m_ucKeySize;
}

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a49590_shell : public NiPoint3Interpolator
{
    bool NiPoint3Interpolator_RegisterStreamables(NiStream*);
};

struct HC1Base
{
    bool FUN_00aa0ad0(NiStream*);
};
struct HC1Data
{
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
    virtual void RegisterStreamables(NiStream&);
};

// Calls FUN_00aa0ad0 on this as HC1Base; if it succeeds, registers the HC1Data at offset 0x18 with the stream and returns true.
// @fnv 0x00a49590
// pdb: NiPoint3Interpolator::RegisterStreamables | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun + bridge(vtable|objrun) + skyrim(objrun_open), high
bool FUN_00a49590_shell::NiPoint3Interpolator_RegisterStreamables(NiStream* kStream)
{
    if (!reinterpret_cast<HC1Base*>(this)->FUN_00aa0ad0(kStream))
        return false;
    HC1Data* d = reinterpret_cast<HC1Data*>(m_spPoint3Data);
    if (d)
        d->RegisterStreamables(*kStream);
    return true;
}

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a495c0_shell : public NiPoint3Interpolator
{
    void FUN_00a495c0(NiStream*);
};

struct FUN_00a95ca0_helper
{
    void FUN_00a95ca0(NiStream*);
};
struct NiColorSaveHelper
{
    void SaveBinary(NiStream&);
};
struct NiStreamLinkHelper
{
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
    virtual void SaveLinkID(void*);
};
// @fnv 0x00a495c0
// pdb: NiPoint3Interpolator::SaveBinary | NiPoint3Interpolator.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream
void FUN_00a495c0_shell::FUN_00a495c0(NiStream* stream)
{
    ((FUN_00a95ca0_helper*)this)->FUN_00a95ca0(stream);
    ((NiColorSaveHelper*)&m_kPoint3Value)->SaveBinary(*stream);
    ((NiStreamLinkHelper*)stream)->SaveLinkID(m_spPoint3Data);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f70;
// @fnv 0x00a49640
// pdb: bhkCollisionObject::GetRTTI | TESObjectREFR.obj | fnv360_0721_beta, objrun, low, conflict (bridge: hkMemoryAllocator::_bufFree<hkVector4>)
GlobalObjectO2_00a7b610* FUN_00a49640()
{
    return &g_011f3f70;
}

extern float DAT_011a9424;
extern float DAT_011a9428;
extern float DAT_011a942c;

struct NiPoint3Interpolator_shell : public NiPoint3Interpolator
{
    bool __thiscall FUN_00a49460(unsigned short channel);
};

// @fnv 0x00a49460
// pdb: NiPoint3Interpolator::GetChannelPosed | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun_open, low
// pdb params: usChannel
bool NiPoint3Interpolator_shell::FUN_00a49460(unsigned short channel)
{
    if (m_spPoint3Data)
        return false;
    if (m_kPoint3Value.x != DAT_011a9424 || m_kPoint3Value.y != DAT_011a9428 ||
        m_kPoint3Value.z != DAT_011a942c)
        return true;
    return false;
}

struct FUN_00a48f70_shell
{
    void FUN_00a48f70(float m_fStartTime, float m_fMaximumDistance);
};
struct FUN_00a49500_shell : public NiPoint3Interpolator
{
    void FUN_00a49500(float m_fStartTime, float m_fMaximumDistance);
};
// Retrieves the object stored at offset 0x18 and, if non-null, forwards the two float arguments to its FUN_00a48f70 method.
// @fnv 0x00a49500
// pdb: NiPoint3Interpolator::GuaranteeTimeRange | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, low
// pdb params: fStartTime, fEndTime
void FUN_00a49500_shell::FUN_00a49500(float afArg1, float afArg2)
{
    FUN_00a48f70_shell* p = (FUN_00a48f70_shell*)m_spPoint3Data;
    if (p)
        p->FUN_00a48f70(afArg1, afArg2);
}

struct RefObj00
{
    virtual void F0();
    virtual void F1();
    long ref;
};
struct Vec12
{
    int x;
    int y;
    int z;
};
struct Holder00
{
    char _pad[12];
    Vec12 v;
    RefObj00* p;
    void FUN_00a494b0(Vec12 x);
};
// @fnv 0x00a494b0
// pdb: NiPoint3Interpolator::SetPoseValue | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: kPoseValue
void Holder00::FUN_00a494b0(Vec12 aVec)
{
    RefObj00* pRef = p;
    if (pRef)
    {
        if (InterlockedDecrement(&pRef->ref) == 0)
            pRef->F1();
        p = 0;
    }
    v = aVec;
}

class A495F0PosData
{
  public:
    virtual ~A495F0PosData();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

class A495F0KeyBasedInterpolator
{
  public:
    A495F0KeyBasedInterpolator();
    virtual ~A495F0KeyBasedInterpolator();

    int unk04;
    int unk08;
};

extern const NiPoint3 g_kA495F0InvalidPoint;

// NiPoint3Interpolator::NiPoint3Interpolator(NiPosData*)
class FUN_00a495f0 : public A495F0KeyBasedInterpolator
{
  public:
    NiPoint3 m_kPoint3Value;
    NiPointer<A495F0PosData> m_spPoint3Data;
    unsigned int m_uiLastIdx;  // src: FNV360_PDB +0x1C (old: m_uiLastKeyIndex)

    FUN_00a495f0(A495F0PosData* pkPosData);
    virtual ~FUN_00a495f0();
};

// @fnv 0x00a495f0
// pdb: NiPoint3Interpolator::NiPoint3Interpolator | NiPoint3Interpolator.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: pkPoint3Data
FUN_00a495f0::FUN_00a495f0(A495F0PosData* pkPosData)
    : m_kPoint3Value(g_kA495F0InvalidPoint), m_spPoint3Data(pkPosData), m_uiLastIdx(0)
{}

struct NiPosDataRangeHelper : NiPosData
{
    void FUN_00a49140(float startTime, float endTime, NiPosData*& result);
};
NiPoint3Interpolator* __stdcall FUN_00a57050(float startTime, float endTime);

inline void AssignPosData(NiPosData*& destination, NiPosData* nextData)
{
    NiPosData* oldData = destination;
    if (oldData != nextData)
    {
        if (oldData)
            oldData->DecRefCount();
        destination = nextData;
        if (nextData)
            nextData->IncRefCount();
    }
}

struct NiPoint3InterpolatorRange : NiPoint3Interpolator
{
    NiPoint3Interpolator* CreateRangeInterpolator(float startTime, float endTime);
};

// Creates a point3 interpolator for the given time range and copies the extracted position data from m_spPoint3Data into it.
// @fnv 0x00a497b0
// pdb: NiPoint3Interpolator::Collapse | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: NiPoint3Interpolator::GetSequenceInterpolator)
NiPoint3Interpolator* NiPoint3InterpolatorRange::CreateRangeInterpolator(float startTime, float endTime)
{
    NiPoint3Interpolator* result = FUN_00a57050(startTime, endTime);
    if (m_spPoint3Data)
    {
        NiPosData* extractedData = 0;
        static_cast<NiPosDataRangeHelper*>(m_spPoint3Data)->FUN_00a49140(startTime, endTime, extractedData);
        AssignPosData(result->m_spPoint3Data, extractedData);
        result->m_uiLastIdx = 0;
        if (extractedData)
            extractedData->DecRefCount();
    }
    return result;
}

struct A499A0CloningProcess;

struct A499A0Point3
{
    float x;
    float y;
    float z;
};

class A499A0Interpolator
{
  public:
    int unk00;
    int unk04;
    int unk08;

    void CopyMemberData(A499A0Interpolator* pkDest, A499A0CloningProcess& kCloning);
};

class A499A0PointInterpolator : public A499A0Interpolator
{
  public:
    A499A0Point3 m_kPoint3Value;  // src: FNV360_PDB +0xC (old: m_kValue)
    NiPointer<NiRefObject> m_spTransformData;
    unsigned int m_uiLastIdx;  // src: FNV360_PDB +0x1C (old: m_uiLastKeyIndex)

    void CloneTo(A499A0PointInterpolator* pkDest, A499A0CloningProcess& kCloning);
};

// @fnv 0x00a499a0
// pdb: NiPoint3Interpolator::CopyMembers | NiPoint3Interpolator.obj | tesv_win, objopen_prop, low
void A499A0PointInterpolator::CloneTo(A499A0PointInterpolator* pkDest, A499A0CloningProcess& kCloning)
{
    A499A0Interpolator::CopyMemberData(pkDest, kCloning);
    pkDest->m_kPoint3Value = m_kPoint3Value;
    pkDest->m_spTransformData = m_spTransformData;
    pkDest->m_uiLastIdx = m_uiLastIdx;
}

struct A49B30Point3
{
    float x;
    float y;
    float z;
};

extern "C" float DAT_011a9424;

class A49B30DataPtr
{
  public:
    A49B30DataPtr() throw() : m_pObject(0)
    {}

    void* m_pObject;
};

class A49B30KeyBasedInterpolator
{
  public:
    A49B30KeyBasedInterpolator() throw();
    virtual ~A49B30KeyBasedInterpolator();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};

class A49B30Point3Interpolator : public A49B30KeyBasedInterpolator
{
  public:
    A49B30Point3Interpolator() throw()
        : m_kPoint3Value(reinterpret_cast<const A49B30Point3&>(DAT_011a9424)), m_uiLastIdx(0)
    {}
    virtual ~A49B30Point3Interpolator();

    void CopyMemberData(A49B30Point3Interpolator* pkDest, void* pvCloning);
    A49B30Point3Interpolator* FUN_00a49b30(void* pvCloning);

    A49B30Point3 m_kPoint3Value;
    A49B30DataPtr m_spPoint3Data;
    unsigned int m_uiLastIdx;  // src: FNV360_PDB +0x1C (old: m_uiLastKeyIndex)
};

// @fnv 0x00a49b30
// pdb: NiPoint3Interpolator::CreateClone | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, medium, conflict (bridge: NiQuaternionInterpolator::CreateObject)
// pdb params: kCloning
A49B30Point3Interpolator* A49B30Point3Interpolator::FUN_00a49b30(void* pvCloning)
{
    A49B30Point3Interpolator* pkClone = new A49B30Point3Interpolator;
    CopyMemberData(pkClone, pvCloning);
    return pkClone;
}

struct StrArrList
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short cap;
    unsigned short count;
    unsigned short unkC;
    unsigned short growBy;
    void Grow(unsigned int newCount);
    void SetAt(unsigned int index, unsigned int* value);
};

struct Sub0cHelper
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int FUN_00a59af0(const char* name);
};

class FUN_00a49bb0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Sub0cHelper m_sub0c;
    unsigned int m_val18;
    void FUN_00a3cbf0(StrArrList* list);
    void AppendPoint3Fields(StrArrList* list);
};

extern "C" unsigned int DAT_011f3f70;
unsigned int __cdecl FUN_00a7d330(unsigned int v);
unsigned int __cdecl FUN_00a7d5a0(const char* name, unsigned int v);

// Appends three values to list: a value derived from DAT_011f3f70, the result of FUN_00a59af0("m_kPoint3Value"), and FUN_00a7d5a0("m_spPoint3Data", m_val18).
// @fnv 0x00a49bb0
// pdb: NiPoint3Interpolator::GetViewerStrings | NiPoint3Interpolator.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void FUN_00a49bb0_cls::AppendPoint3Fields(StrArrList* list)
{
    unsigned int value;

    FUN_00a3cbf0(list);
    value = FUN_00a7d330(DAT_011f3f70);
    {
        unsigned int count = list->count;
        if (count >= list->cap)
        {
            list->Grow(count + list->growBy);
        }
        list->SetAt(count, &value);
    }

    value = m_sub0c.FUN_00a59af0("m_kPoint3Value");
    {
        unsigned int count = list->count;
        if (count >= list->cap)
        {
            list->Grow(count + list->growBy);
        }
        list->SetAt(count, &value);
    }

    unsigned int v18 = m_val18;
    value = FUN_00a7d5a0("m_spPoint3Data", v18);
    {
        unsigned int count = list->count;
        if (count >= list->cap)
        {
            list->Grow(count + list->growBy);
        }
        list->SetAt(count, &value);
    }
}

// @fnv 0x00d46c90
// pdb: hkpWorldObject::setShape | hkpWorldObject.obj | fnv360_0822_retail, vtable, medium
// pdb params: shape
unsigned int __stdcall FUN_00d46c90(unsigned int a1)
{
    return 1;
}

struct BA49650Point3
{
    float x;
    float y;
    float z;
};

struct BA49650Pointer
{
    BA49650Pointer() : m_pObject(0)
    {}

    void* m_pObject;
};

class BA49650KeyBasedInterpolator
{
  public:
    BA49650KeyBasedInterpolator() throw();
    virtual ~BA49650KeyBasedInterpolator();

    int unk04;
    int unk08;
};

class FUN_00a49650_cls : public BA49650KeyBasedInterpolator
{
  public:
    FUN_00a49650_cls(BA49650Point3 kPoseValue) throw();
    virtual ~FUN_00a49650_cls();

    BA49650Point3 m_kPoseValue;
    BA49650Pointer m_spTransformData;
    unsigned int m_uiLastIdx;  // src: FNV360_PDB +0x1C (old: m_uiLastKeyIndex)
};

// @fnv 0x00a49650
// pdb: NiPoint3Interpolator::~NiPoint3Interpolator | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: NiPoint3Interpolator::NiPoint3Interpolator)
FUN_00a49650_cls::FUN_00a49650_cls(BA49650Point3 kPoseValue) throw() : m_kPoseValue(kPoseValue), m_uiLastIdx(0)
{}

struct PosValue496
{
    float x;
    float y;
    float z;

    bool FUN_00439090(const NiPoint3& kOther);
};

struct PosKeyValue496
{
    float m_fTime;
    PosValue496 m_kPos;
};

__forceinline void ClearPosData(NiPosData*& rpkData)
{
    if (rpkData != 0)
    {
        if (rpkData)
            rpkData->DecRefCount();
        rpkData = 0;
    }
}

struct PosDataView496 : NiPosData
{
    __forceinline PositionKeyInterpolator* ComputePositionAtTime(unsigned int& uiNumKeys, AnimationKey::KeyType& eType,
                                                                 unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eType;
        ucSize = m_ucKeySize;
        return m_pkKeys;
    }
};

struct FUN_00a49690_shell : NiPoint3Interpolator
{
    void CollapseConstantPosData();
};

// If the position data has zero keys, clears it and resets m_kPoint3Value; if all keys share one value, clears the data and stores that value in m_kPoint3Value.
// @fnv 0x00a49690
// pdb: NiPoint3Interpolator::NiPoint3Interpolator | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: NiPoint3Interpolator::Collapse)
// pdb params: kPoseValue
void FUN_00a49690_shell::CollapseConstantPosData()
{
    NiPosData* pkData = m_spPoint3Data;
    if (!pkData)
        return;

    unsigned int uiNumKeys;
    AnimationKey::KeyType eType;
    unsigned char ucSize;
    PositionKeyInterpolator* pkKeys = ((PosDataView496*)pkData)->ComputePositionAtTime(uiNumKeys, eType, ucSize);

    if (uiNumKeys == 0)
    {
        ClearPosData(m_spPoint3Data);
        m_kPoint3Value = reinterpret_cast<const NiPoint3&>(DAT_011a9424);
        return;
    }
    else
    {
        NiPoint3 kValue = (NiPoint3&)((PosKeyValue496*)pkKeys)->m_kPos;
        if (uiNumKeys != 1)
        {
            if (eType != AnimationKey::LINKEY && eType != AnimationKey::STEPKEY)
                return;
            bool bAllEqual = true;
            for (unsigned int i = 1; bAllEqual && i < uiNumKeys; i++)
            {
                if (((PosKeyValue496*)((char*)pkKeys + ucSize * i))->m_kPos.FUN_00439090(kValue))
                    bAllEqual = false;
            }
            if (!bAllEqual)
                return;
        }

        ClearPosData(m_spPoint3Data);
        m_kPoint3Value = kValue;
    }
}

// Allocates and returns a new A49B30Point3Interpolator object.
// @fnv 0x00a49a30
// pdb: NiPoint3Interpolator::CreateObject | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, medium
A49B30Point3Interpolator* __cdecl FUN_00a49a30()
{
    return new A49B30Point3Interpolator();
}

struct NiPosDataVirt
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
    virtual bool v23(NiPosData* other);
};

struct Call_439090_tgt
{
    bool Call_439090(const NiPoint3& other);
};

struct PosInterpEq : public NiPoint3Interpolator
{
    bool FUN_00c85800(NiPoint3Interpolator* other);
    bool FUN_00a49a80(NiPoint3Interpolator* other);
};

// @fnv 0x00a49a80
// pdb: NiPoint3Interpolator::IsEqual | NiPoint3Interpolator.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkObject
bool PosInterpEq::FUN_00a49a80(NiPoint3Interpolator* other)
{
    if (!FUN_00c85800(other))
        return false;
    if (reinterpret_cast<Call_439090_tgt*>(&m_kPoint3Value)->Call_439090(other->m_kPoint3Value))
        return false;
    if ((m_spPoint3Data != 0 && other->m_spPoint3Data == 0) || (m_spPoint3Data == 0 && other->m_spPoint3Data != 0))
        return false;
    NiPosData* pPosData = m_spPoint3Data;
    if (pPosData != 0)
    {
        NiPosData* pOtherPosData = other->m_spPoint3Data;
        if (!reinterpret_cast<NiPosDataVirt*>(pPosData)->v23(pOtherPosData))
            return false;
    }
    return true;
}
