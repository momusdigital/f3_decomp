#include "f3_common.h"
// src/havok/physics/vehicle/hkpvehicleinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleInstance.h"

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
void* FUN_00c85750() throw();

struct VUC_Mon
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cap;
    char* m_capMinus16;
};
struct VUC_Timer
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};
struct VUC_StepInfo
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};
struct VUC_RealArray
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct VUC_WheelParams
{
    float m_fSphereRadius;
    float m_fViscosityFriction;
    float m_fMaxFriction;
    float m_fSlipAngle;
    float m_fSlipVelocity;
    float m_fMaxContactBodyAcceleration;
    float m_fForceFeedbackMultiplier;
    float m_fMaxFrictionForce;
    float m_fFrictionEqualizer;
    signed char m_iAxle;
};
struct VUC_WPArray
{
    VUC_WheelParams* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    const VUC_WheelParams& operator[](int i) const
    {
        return m_data[i];
    }
};
struct __declspec(align(16)) VUC_Vector4
{
    float x;
    float y;
    float z;
    float w;
};
struct VUC_Data
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    VUC_Vector4 m_kGravity;
    signed char m_iWheelCount;
    VUC_Vector4 m_kChassisOrientation[3];
    float m_fChassisMass;
    float m_fTorqueMax;
    float m_fTorqueMin;
    float m_fTorqueFactor;
    float m_fTorquePitchFactor;
    float m_fTorqueRollFactor;
    float m_fTorqueYawFactor;
    float m_fExtraTorqueFactor;
    float m_fChassisUnitInertiaRoll;
    float m_fChassisUnitInertiaPitch;
    float m_fChassisUnitInertiaYaw;
    VUC_WPArray m_kWheelParams;
};
struct VUC_Filtered
{
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct VUC_Transmission
{
    float m_engineRpm;
    float m_fCurrentGearRatio;
    float* m_pGearRatios;
    int m_iGearCount;
    int m_iGearCapacity;
};
struct FUN_00e39400
{
    VUC_RealArray m_kFirstRealArray;
    VUC_RealArray m_kSecondRealArray;
    float m_unk18;
    FUN_00e39400()
    {
        m_kFirstRealArray.m_data = 0;
        m_kFirstRealArray.m_iElementCount = 0;
        m_kFirstRealArray.m_iCapacityState = 0x80000000;
        m_kSecondRealArray.m_data = 0;
        m_kSecondRealArray.m_iElementCount = 0;
        m_kSecondRealArray.m_iCapacityState = 0x80000000;
    }
    ~FUN_00e39400() throw();
};

struct VUC_Instance
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    VUC_Data* m_data;
    void FUN_00e37aa0(float dt, void* det) throw();
    void FUN_00e36f60(float dt, VUC_Filtered& f) throw();
    void UpdateSteering(float dt, const VUC_Filtered& f) throw();
    void FUN_00e36fa0(float dt, VUC_Transmission& t) throw();
    void FUN_00e37020(float dt, const VUC_Filtered& f, VUC_Transmission& t) throw();
    void UpdateVehicleState(float dt, const VUC_Filtered& f, FUN_00e39400& b) throw();
    void NotifyListener(float dt, void* det, VUC_RealArray& s) throw();
    void FUN_00e37080(float dt, void* aero) throw();
    void UpdateVehicleComponents(const VUC_StepInfo& stepInfo, void* det, void* aero,
                                 VUC_RealArray& suspensionForceAtWheel, VUC_RealArray& totalLinearForceAtWheel);
};

// @fnv 0x00e38e60
void VUC_Instance::UpdateVehicleComponents(const VUC_StepInfo& stepInfo, void* det, void* aero,
                                           VUC_RealArray& suspensionForceAtWheel,
                                           VUC_RealArray& totalLinearForceAtWheel)
{
    {
        VUC_Mon* m = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        if (m->m_kRayEnd < m->m_capMinus16)
        {
            VUC_Timer* pTimer = (VUC_Timer*)m->m_kRayEnd;
            pTimer->m_name = "TtUpdateComponents";
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            pTimer->m_ticks = ticks;
            m->m_kRayEnd = (char*)(pTimer + 1);
        }
    }

    VUC_Filtered filteredInput;
    VUC_Transmission transmission;
    FUN_00e39400 breakingInfo;
    {
        int n = m_data->m_iWheelCount;
        char** cur = (char**)FUN_00c85750();
        char* p = *cur;
        *cur = p + ((n * 4 + 0x7f) & ~0x7f);
        transmission.m_pGearRatios = (float*)p;
    }

    const float deltaTime = stepInfo.m_fTimeStep;

    FUN_00e37aa0(deltaTime, det);
    FUN_00e36f60(deltaTime, filteredInput);
    UpdateSteering(deltaTime, filteredInput);
    FUN_00e36fa0(deltaTime, transmission);
    FUN_00e37020(deltaTime, filteredInput, transmission);
    UpdateVehicleState(deltaTime, filteredInput, breakingInfo);
    NotifyListener(deltaTime, det, suspensionForceAtWheel);
    FUN_00e37080(deltaTime, aero);

    for (int w = 0; w < m_data->m_iWheelCount; w++)
    {
        const float total_torque = breakingInfo.m_kFirstRealArray.m_data[w] + transmission.m_pGearRatios[w];
        totalLinearForceAtWheel.m_data[w] = total_torque / m_data->m_kWheelParams[w].m_fSphereRadius;
    }

    {
        char* p = (char*)transmission.m_pGearRatios;
        *(char**)FUN_00c85750() = p;
    }

    {
        VUC_Mon* m = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        if (m->m_kRayEnd < m->m_capMinus16)
        {
            VUC_Timer* pTimer = (VUC_Timer*)m->m_kRayEnd;
            pTimer->m_name = "Et";
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            pTimer->m_ticks = ticks;
            m->m_kRayEnd = (char*)(pTimer + 1);
        }
    }
}

struct VUC_VehicleTarget
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void FUN_00e378e0(void* world) = 0;
};

struct VUC_VehicleInstance
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    void* m_data;
    unsigned char m_auiShapeKeys[0x1c];
    VUC_VehicleTarget* m_target;

    void __thiscall FUN_00e378e0(void* world, void* param2);
};

// @f3 0x00748fa0 (community match, verified in this file)
struct Obj38_7988 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vf(void* arg);
};
extern "C" void __stdcall FUN_00aa5a60(void* world, void* param2);
// pdb: LipTask::Cancel | LipSyncBackgroundManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aePreviousState, apTaskOwner
void __thiscall VUC_VehicleInstance::FUN_00e378e0(void* world, void* param2)
{
    FUN_00aa5a60(world, param2);
    if ((int)world != 5)
    {
        Obj38_7988* o = *(Obj38_7988**)(m_auiShapeKeys + 0x18);
        o->vf(*(void**)(m_auiShapeKeys + 0x10));
    }
}


struct VUC_DeltaTime
{
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

void __cdecl FUN_00e59a40(void* a, void* b, void* c, void* d);

struct FUN_00e38080StandIn
{
    unsigned char m_unknown00[0x1c];
    unsigned char* m_data;
    unsigned char m_unknown20[0x34];
    void* m_object54;

    void FUN_00e38080(const VUC_StepInfo& stepInfo, void* arg2);
};

// @fnv 0x00e38080
void FUN_00e38080StandIn::FUN_00e38080(const VUC_StepInfo& stepInfo, void* apArg)
{
    VUC_DeltaTime deltaTime;
    deltaTime.m_fTimeStep = stepInfo.m_fTimeStep;
    deltaTime.m_fInverseDeltaTime = stepInfo.m_fInverseDeltaTime;

    FUN_00e59a40(&deltaTime, m_data + 0xa4, apArg, &m_object54);
}

struct VUC_Allocator
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void* ptr, unsigned int size);
};

struct VUC_Router
{
    char m_auiShapeKeys[0x10];
    VUC_Allocator* m_pThreadAllocator;
};

struct Filtered
{
    float a, b, c, d;
};
struct Transmission
{
    float engineRpm;
    float mainTorque;
    float* wheels;
    int reversing;
    int gear;
};
struct Pair
{
    float m_kPointA;
    float m_kPointB;
};
struct Instance;
struct Target
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(float dt, Instance* inst, const Filtered* f, Transmission* t, Pair* out);
};
struct Instance
{
    void* m_vtbl;
    char m_auiShapeKeys[0x24];
    Target* m_target;
    char m_pAuxiliaryObject[0xb4 - 0x2c];
    float m_b4;
    float m_b8;
    void FUN_00e37020(float dt, const Filtered& f, Transmission& t) throw();
};
// Passes dt, this, f, t and a Pair built from m_b4/m_b8 to m_target->s3, then stores the returned Pair back into m_b4/m_b8.
// @fnv 0x00e37020
void Instance::FUN_00e37020(float afDeltaTime, const Filtered& f, Transmission& t) throw()
{
    Pair p;
    p.m_kPointB = m_b8;
    p.m_kPointA = m_b4;
    m_target->s3(afDeltaTime, this, &f, &t, &p);
    m_b8 = p.m_kPointB;
    m_b4 = p.m_kPointA;
}

class hkListenerE371
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void notify(float f, void* pvSource, void* a, void* b);
};

class hkObjE371
{
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
    int unk28;
    int unk2C;
    int unk30;
    hkListenerE371* m_kListener;

    void NotifyListener(float f, void* a, void** pb);
};

// Forwards the float and the two pointers to the listener stored in the object, passing this as the source.
// @fnv 0x00e371a0
void hkObjE371::NotifyListener(float f, void* a, void** pb)
{
    m_kListener->notify(f, this, a, *pb);
}

struct hkBoolE379
{
    char m_cBooleanValue;
    hkBoolE379(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkpWorldE379;

class hkpEntityE379
{
  public:
    int m_00;
    int m_04;
    hkpWorldE379* m_pOwningWorld;

    hkpWorldE379* getWorld() const
    {
        return m_pOwningWorld;
    }
};

class hkpWorldE379
{
  public:
    hkBoolE379 ProcessTarget(hkpEntityE379* pkEntity);
};

class hkActionE379
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
};

class FUN_00e37910_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    hkpEntityE379* m_pEntity;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    hkActionE379* m_pAction;

    void FUN_00e37910();
};

// Calls V9 on the stored action, then calls ProcessTarget on the entity's world with the stored entity.
// @f3 0x00423be0 (community match, verified in this file)
class SaveWriter_423be0
{
  public:
    void FUN_006db460(void* data, int size);
    void FUN_006defa0(void* data, int size);
};
extern SaveWriter_423be0* DAT_01079ca4;

struct RefTarget_423be0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int refID;
};

// pdb: DoorTeleportData::SaveGame | TeleportData.obj | fnv360_0822_retail, call_gap, low
void FUN_00e37910_cls::FUN_00e37910()
{
    DAT_01079ca4->FUN_006db460(&m_04, 12);
    DAT_01079ca4->FUN_006db460(&m_10, 12);
    RefTarget_423be0* target = (RefTarget_423be0*)m_00;
    unsigned int refID = 0;
    if (target)
        refID = target->refID;
    DAT_01079ca4->FUN_006defa0(&refID, 4);
}


void __cdecl FUN_00c908c0(VUC_Allocator* allocator, VUC_RealArray* array, int capacity, int stride);
struct VUC_BrakingStrategy
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void calculate(float dt, VUC_Instance* vehicle, const VUC_Filtered& input, FUN_00e39400& output);
};
// @fnv 0x00e38a30
void VUC_Instance::UpdateVehicleState(float afDeltaTime, const VUC_Filtered& input, FUN_00e39400& output) throw()
{
    hkpVehicleInstance* vehicle = reinterpret_cast<hkpVehicleInstance*>(this);
    VUC_RealArray& rFixedArray = output.m_kSecondRealArray;
    int count = vehicle->m_kSecondRealArray.m_iElementCount;
    VUC_Router* router = reinterpret_cast<VUC_Router*>(FUN_00c85750());
    VUC_Allocator* alloc = router->m_pThreadAllocator;
    int capacity = rFixedArray.m_iCapacityState & 0x3fffffff;
    if (capacity < count)
    {
        capacity *= 2;
        if (count >= capacity)
            capacity = count;
        FUN_00c908c0(alloc, &rFixedArray, capacity, 1);
    }
    rFixedArray.m_iElementCount = count;
    count = vehicle->m_kSecondRealArray.m_iElementCount;
    router = reinterpret_cast<VUC_Router*>(FUN_00c85750());
    alloc = router->m_pThreadAllocator;
    capacity = output.m_kFirstRealArray.m_iCapacityState & 0x3fffffff;
    if (capacity < count)
    {
        capacity *= 2;
        if (count >= capacity)
            capacity = count;
        FUN_00c908c0(alloc, &output.m_kFirstRealArray, capacity, 4);
    }
    output.m_kFirstRealArray.m_iElementCount = count;
    for (int i = 0; i < vehicle->m_kSecondRealArray.m_iElementCount; ++i)
        reinterpret_cast<char*>(rFixedArray.m_data)[i] = vehicle->m_kSecondRealArray.m_data[i];
    output.m_unk18 = vehicle->m_fBrakeState;
    reinterpret_cast<VUC_BrakingStrategy*>(vehicle->m_pBrake)->calculate(afDeltaTime, this, input, output);
    for (int i = 0; i < output.m_kSecondRealArray.m_iElementCount; ++i)
        vehicle->m_kSecondRealArray.m_data[i] = reinterpret_cast<char*>(output.m_kSecondRealArray.m_data)[i];
    vehicle->m_fBrakeState = output.m_unk18;
}

struct hkAllocatorE38D
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE38D
{
    void* m_apvUnk00[4];
    hkAllocatorE38D* m_pkHeap;
    hkAllocatorE38D& heap()
    {
        return *m_pkHeap;
    }
};

void __cdecl FUN_00c908c0(hkAllocatorE38D& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> struct hkArrayE38D
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE38D() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayE38D() throw()
    {
        hkAllocatorE38D& kAlloc = ((hkMemoryRouterE38D*)FUN_00c85750())->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(hkAllocatorE38D& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(((hkMemoryRouterE38D*)FUN_00c85750())->heap(), n);
        m_iElementCount = n;
    }
};

struct hkpVehicleSteeringAnglesOutputE38D
{
    hkReal m_fMainSteeringAngle;
    hkArrayE38D<hkReal> m_kWheelSteeringAngles;
};

struct hkpFilteredDriverInputOutputE38D;

class hkpVehicleSteering
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void CalcSteering(const hkReal fMoveElapsedTime, const hkpVehicleInstance* pkVehicle,
                              const hkpFilteredDriverInputOutputE38D& kFilteredInfo,
                              hkpVehicleSteeringAnglesOutputE38D& kSteeringOutput) throw();
};

class hkpVehicleInstanceE38D : public hkpVehicleInstance
{
  public:
    void UpdateSteering(hkReal fMoveElapsedTime, const hkpFilteredDriverInputOutputE38D& kFilteredInfo) throw();
};

// Copies the steering angles into a temporary output, runs the steering component's update, then writes the resulting angle and array back.
// @fnv 0x00e38d50
void hkpVehicleInstanceE38D::UpdateSteering(hkReal fMoveElapsedTime,
                                            const hkpFilteredDriverInputOutputE38D& kFilteredInfo) throw()
{
    hkpVehicleSteeringAnglesOutputE38D kSteeringOutput;
    kSteeringOutput.m_fMainSteeringAngle = m_fMainSteeringAngle;
    kSteeringOutput.m_kWheelSteeringAngles.SetSizeAndGrow(m_kWheelSteeringAngles.m_iElementCount);
    for (int i = 0; i < m_kWheelSteeringAngles.m_iElementCount; i++)
        kSteeringOutput.m_kWheelSteeringAngles.m_data[i] = m_kWheelSteeringAngles.m_data[i];
    m_pSteering->CalcSteering(fMoveElapsedTime, this, kFilteredInfo, kSteeringOutput);
    m_fMainSteeringAngle = kSteeringOutput.m_fMainSteeringAngle;
    for (int i = 0; i < m_kWheelSteeringAngles.m_iElementCount; i++)
        m_kWheelSteeringAngles.m_data[i] = kSteeringOutput.m_kWheelSteeringAngles.m_data[i];
}

struct VUC_InplaceRealArray16 : VUC_RealArray
{
    float m_kStorage[16];
};

struct VUC_AeroOutput
{
    VUC_Vector4 m_kForce;
    VUC_Vector4 m_kTorque;
};

static inline void VUC_ReleaseArray(VUC_RealArray& a)
{
    VUC_Router* router = (VUC_Router*)FUN_00c85750();
    VUC_Allocator* allocator = router->m_pThreadAllocator;
    a.m_iElementCount = 0;
    if ((a.m_iCapacityState & 0x80000000) == 0)
        allocator->free(a.m_data, (a.m_iCapacityState & 0x3fffffff) * sizeof(float));
    a.m_data = 0;
    a.m_iCapacityState = 0x80000000;
}

struct VUC_StepLocals
{
    VUC_AeroOutput aerodynamicsInfo;
    VUC_InplaceRealArray16 suspensionForceAtWheel;
};

struct VUC_StepInstance : VUC_Instance
{
    void FUN_00e385e0(const VUC_StepInfo& stepInfo, const VUC_AeroOutput& aero,
                      const VUC_RealArray& suspensionForceAtWheel,
                      const VUC_RealArray& totalLinearForceAtWheel) throw();
    void FUN_00e39030(const VUC_StepInfo& stepInfo, void* det);
};

// Times a vehicle step: starts a "TtDoVehicle" timer, runs UpdateVehicleComponents and FUN_00e385e0 with in-place force arrays, stops the "Et" timer and releases the arrays.
// @fnv 0x00e39030
void VUC_StepInstance::FUN_00e39030(const VUC_StepInfo& stepInfo, void* det)
{
    VUC_Mon* mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
    if (mon->m_kRayEnd < mon->m_capMinus16)
    {
        VUC_Timer* t = (VUC_Timer*)mon->m_kRayEnd;
        t->m_name = "TtDoVehicle";
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        t->m_ticks = ticks;
        mon->m_kRayEnd = (char*)(t + 1);
    }

    VUC_StepLocals stepLocals;
    stepLocals.suspensionForceAtWheel.m_iElementCount = m_data->m_iWheelCount;
    stepLocals.suspensionForceAtWheel.m_data = stepLocals.suspensionForceAtWheel.m_kStorage;
    stepLocals.suspensionForceAtWheel.m_iCapacityState = 0x80000010;
    VUC_InplaceRealArray16 totalLinearForceAtWheel;
    totalLinearForceAtWheel.m_iElementCount = m_data->m_iWheelCount;
    totalLinearForceAtWheel.m_data = totalLinearForceAtWheel.m_kStorage;
    totalLinearForceAtWheel.m_iCapacityState = 0x80000010;

    UpdateVehicleComponents(stepInfo, det, &stepLocals.aerodynamicsInfo, stepLocals.suspensionForceAtWheel,
                            totalLinearForceAtWheel);
    FUN_00e385e0(stepInfo, stepLocals.aerodynamicsInfo, stepLocals.suspensionForceAtWheel, totalLinearForceAtWheel);

    mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
    if (mon->m_kRayEnd < mon->m_capMinus16)
    {
        VUC_Timer* t = (VUC_Timer*)mon->m_kRayEnd;
        t->m_name = "Et";
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        t->m_ticks = ticks;
        mon->m_kRayEnd = (char*)(t + 1);
    }

    VUC_ReleaseArray(totalLinearForceAtWheel);
    VUC_ReleaseArray(stepLocals.suspensionForceAtWheel);
}

void* FUN_00c85750() throw();

struct VehicleStepInfo
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};
struct __declspec(align(16)) VehicleVector4
{
    float x, y, z, w;
};
struct VehicleData
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    VehicleVector4 m_kGravity;
    signed char m_iWheelCount;
};
struct VehicleScratchAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void free(void* memory, unsigned int bytes);
};
struct VehicleMemoryRouter
{
    char* m_stackTop;
    void* m_stackEnd;
    void* m_stackCapacity;
    void* m_heapFallback;
    VehicleScratchAllocator* m_pThreadAllocator;
};
struct VehicleWheelCollide
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void CollideWheels(float deltaTime, void* vehicle, void* scratch);
};
struct VehicleInstance
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    VehicleData* m_data;
    void* m_pDriverInput;
    void* m_pSteering;
    void* m_pVehicleEngine;
    void* m_pTransmission;
    void* m_pBrake;
    void* m_pSuspension;
    void* m_pAerodynamics;
    VehicleWheelCollide* m_pWheelCollide;
    void FUN_00e37940();
    void FUN_00e39030(const VehicleStepInfo* stepInfo, void* scratch);
    void FUN_00e39190(const VehicleStepInfo* stepInfo);
};

// @fnv 0x00e39190
void VehicleInstance::FUN_00e39190(const VehicleStepInfo* stepInfo)
{
    FUN_00e37940();
    int wheelCount = m_data->m_iWheelCount;
    VehicleMemoryRouter* router = (VehicleMemoryRouter*)FUN_00c85750();
    char* originalTop = router->m_stackTop;
    float deltaTime = stepInfo->m_fTimeStep;
    router->m_stackTop = originalTop + (((wheelCount * 3 << 5) + 127) & ~127);
    int capacityAndFlags = wheelCount | 0x80000000;

    m_pWheelCollide->CollideWheels(deltaTime, this, originalTop);
    FUN_00e39030(stepInfo, originalTop);
    ((VehicleMemoryRouter*)FUN_00c85750())->m_stackTop = originalTop;
    VehicleScratchAllocator* allocator = ((VehicleMemoryRouter*)FUN_00c85750())->m_pThreadAllocator;
    if (!(capacityAndFlags & 0x80000000))
    {
        allocator->free(originalTop, (capacityAndFlags & 0x3fffffff) * 3 << 5);
    }
}

class hkMemoryAllocatorE392
{
  public:
    virtual ~hkMemoryAllocatorE392() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterE392
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE392* m_pStreamAllocator;
    hkMemoryAllocatorE392& heap()
    {
        return *m_pStreamAllocator;
    }
};

class hkRefObjectE392
{
  public:
    virtual ~hkRefObjectE392() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c90510() throw();
};

class hkShapeE392;

struct hkInputInfoE392
{
    const hkShapeE392* m_pCollisionShape;
};

struct hkInputE392
{
    const hkInputInfoE392* m_info;
};

struct hkAgentDataE392
{
    int unk00;
    int unk04;
    unsigned char m_sState;
};

class hkAgentFactoryE392
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual hkAgentDataE392* createAgent(const hkShapeE392* pkShape, int iFlags) throw();
};

class hkClonableE392
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual hkClonableE392* clone() throw();
};

class hkSourceE392;

class FUN_00e38b20
{
  public:
    virtual ~FUN_00e38b20() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_08;
    int m_0c;
    int unk10;
    int unk14;
    const hkShapeE392* m_pCollisionShape;
    hkRefObjectE392* m_1c;
    hkRefObjectE392* m_20;
    hkRefObjectE392* m_24;
    hkRefObjectE392* m_28;
    hkRefObjectE392* m_2c;
    hkRefObjectE392* m_30;
    hkRefObjectE392* m_34;
    hkRefObjectE392* m_38;
    hkAgentDataE392* m_pCollisionAgent;
    hkRefObjectE392* m_40;
    hkRefObjectE392* m_44;
    char unk48[0x54];
    hkClonableE392* m_9c;
    char unkA0[0x34];

    void* operator new(unsigned int nbytes)
    {
        FUN_00e38b20* b = static_cast<FUN_00e38b20*>(
            static_cast<hkMemoryRouterE392*>(FUN_00c85750())->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    FUN_00e38b20(const hkShapeE392* pkShape) throw();
    void FUN_00e39480(const hkSourceE392* pkOther) throw();
};

typedef char fnv_check_e39210[(sizeof(FUN_00e38b20) == 0xd4) ? 1 : -1];

class hkSourceE392
{
  public:
    char unk00[0x3c];
    hkAgentFactoryE392* m_factory;
    hkRefObjectE392* m_40;
    char unk44[0x58];
    hkClonableE392* m_9c;

    FUN_00e38b20* FUN_00e39210(const hkInputE392* pkInput, int iFlags) throw();
};

void __cdecl FUN_00e39190();

// @fnv 0x00e392f0
// pdb: hkString::memMove | hkString.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkString_memMove()
{
    FUN_00e39190();
}

struct VUC_TransmissionTarget10
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void FUN_00e378e0(float dt, void* instance, void* transmission) = 0;
};

struct VUC_Transmission8
{
    float m_engineRpm;
    float m_fCurrentGearRatio;
    float* m_pGearRatios;
    signed char m_iGearCount;
    signed char m_iGearCapacity;
    signed char m_gear2;
    signed char m_gear3;
    float m_extra;
};

// Copies gear fields into the transmission, calls the target's FUN_00e378e0 with dt, this and the transmission, then copies four fields back.
// @fnv 0x00e36fa0
void VUC_Instance::FUN_00e36fa0(float dt, VUC_Transmission& t) throw()
{
    unsigned char* base = reinterpret_cast<unsigned char*>(this);
    VUC_Transmission8& s = reinterpret_cast<VUC_Transmission8&>(t);

    unsigned char* data = *reinterpret_cast<unsigned char**>(base + 0x1c);
    s.m_iGearCount = static_cast<signed char>(data[0x20]);
    s.m_iGearCapacity = *reinterpret_cast<signed char*>(base + 0xcc);
    s.m_gear2 = *reinterpret_cast<signed char*>(base + 0xcd);
    s.m_gear3 = *reinterpret_cast<signed char*>(base + 0xce);
    s.m_extra = *reinterpret_cast<float*>(base + 0xd0);

    VUC_TransmissionTarget10* target = *reinterpret_cast<VUC_TransmissionTarget10**>(base + 0x2c);
    target->FUN_00e378e0(dt, this, &t);

    *reinterpret_cast<signed char*>(base + 0xcc) = s.m_iGearCapacity;
    *reinterpret_cast<signed char*>(base + 0xcd) = s.m_gear2;
    *reinterpret_cast<signed char*>(base + 0xce) = s.m_gear3;
    *reinterpret_cast<float*>(base + 0xd0) = s.m_extra;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
struct Q_e380c0_Vec
{
    __m128 q;
};
struct Q_e380c0_Sub
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
    virtual void v40(const Q_e380c0_Vec* p);
    virtual void v44(const Q_e380c0_Vec* p);
    __m128 c0;
    __m128 c1;
    __m128 c2;
};
struct Q_e380c0_A
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    int uc0;
    int uc4;
    int uc8;
    int ucc;
    int ud0;
    int ud4;
    int ud8;
    int udc;
    Q_e380c0_Sub sub;
};
struct Q_e380c0_cls
{
    int u00, u04, u08, u0c, u10, u14;
    Q_e380c0_A* a;
    void FUN_00e380c0(const Q_e380c0_Vec* in);
};
// Combines the components of in[2] with the sub object's c0, c1, c2 columns, passes the result to v44, then passes in+1 to v40.
// @fnv 0x00e380c0
void Q_e380c0_cls::FUN_00e380c0(const Q_e380c0_Vec* in)
{
    Q_e380c0_Sub& s = a->sub;
    __m128 v = in[2].q;
    __m128 vResult =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), s.c1), _mm_mul_ps(_mm_shuffle_ps(v, v, 0), s.c0)),
                   _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), s.c2));
    Q_e380c0_Vec t;
    t.q = vResult;
    s.v44(&t);
    s.v40(in + 1);
}

namespace fnv_00e385e0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);

extern const char str_010eb844[];
extern const char str_010c41f8[];

struct VehStep_Vector4
{
    __m128 m_vComponents;
};

struct VehStep_Output
{
    VehStep_Vector4 m_transform0;
    VehStep_Vector4 m_transform1;
};

struct VehStep_Motion
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c(float dt, VehStep_Vector4* out);
    virtual void slot60(float dt, VehStep_Vector4* out);
};

struct VehStep_Entity
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
    VehStep_Motion m_pMotionState;
    void FUN_00c9c1d0();
    VehStep_Motion* getMotion()
    {
        FUN_00c9c1d0();
        return &m_pMotionState;
    }
};

struct VehStep_AxleParams
{
    VehStep_Vector4 m_kFirstVector;
    VehStep_Vector4 m_kSecondAxleVector;
    VehStep_Vector4 m_kThirdVector;
    void* m_pFirstPointer;
    void* m_pSecondPointer;
    float m_fFirstScalar;
    float m_fSecondScalar;
    float m_fThirdValue;
    float m_fFourthValue;
    float m_fFifthScalar;
    float m_fSixthValue;
    unsigned char m_ucValue;

    void initialize()
    {
        m_kFirstVector.m_vComponents = _mm_setzero_ps();
        m_kSecondAxleVector.m_vComponents = _mm_setzero_ps();
        m_kThirdVector.m_vComponents = _mm_setzero_ps();
        m_fFirstScalar = 0.0f;
        m_fSecondScalar = 0.0f;
        m_fThirdValue = 0.0f;
        m_fFourthValue = 0.0f;
        m_fFifthScalar = 0.0f;
        m_fSixthValue = 0.0f;
        m_ucValue = 0;
        m_pFirstPointer = 0;
        m_pSecondPointer = 0;
    }
};

struct VehStep_Accumulator
{
    VehStep_Vector4 m_vLinearVelocity;
    VehStep_Vector4 m_vAngularVelocity;
    VehStep_Vector4 m_vInverseInertiaAndMass;
    VehStep_Vector4 m_vCenterOfMass;
    VehStep_Vector4 m_scratch1;
    VehStep_Vector4 m_scratch2;
    VehStep_Vector4 m_scratch3;
    VehStep_Vector4 m_coreFromWorld0;
    VehStep_Vector4 m_coreFromWorld1;
    VehStep_Vector4 m_coreFromWorld2;
    VehStep_Vector4 m_centerOfMassInWorld;
    VehStep_Vector4 m_unkB0;
    VehStep_Vector4 m_unkC0;
    VehStep_Vector4 m_unkD0;
    VehStep_Vector4 m_unkE0;
    VehStep_Vector4 m_unkF0;
};

struct VehStep_FrictionParams
{
    VehStep_AxleParams m_akAxleParams[2];
    float m_fTorquePitchFactor;
    VehStep_Accumulator m_pChassisCollidable;
    VehStep_Accumulator m_kSecondAccumulator;
};

struct VehStep_Ground
{
    void* m_kPointA;
    void* m_kPointB;
};

struct VehStep_Accumulators
{
    VehStep_Accumulator m_ground0;
};

struct VehStep_Damper
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void ApplyVelocityDamping(float dt, struct VehStep_Vehicle& vehicle);
};

void __stdcall FUN_00e38080(const VUC_StepInfo& stepInfo, VehStep_FrictionParams& params);

struct VehStep_Vehicle
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    VehStep_Entity* m_pEntity;
    VUC_Data* m_data;
    void* m_pDriverInput;
    void* m_pSteering;
    void* m_pVehicleEngine;
    void* m_pTransmission;
    void* m_pBrake;
    void* m_pSuspension;
    void* m_pAerodynamics;
    void* m_pWheelCollide;
    void* m_pTyremarksInfo;
    VehStep_Damper* m_pVelocityDamper;

    void FUN_00e375a0(float dt, void* a2, void* a3, VehStep_Ground& ground, VehStep_FrictionParams& params);
    void FUN_00e37d60(const VUC_StepInfo& stepInfo, VehStep_Ground& ground, VehStep_Accumulator& atLast,
                      VehStep_Accumulators& accs, VehStep_FrictionParams& params);
    void FUN_00e37740(const VUC_StepInfo& stepInfo, VehStep_FrictionParams& params);
    void FUN_00e376e0(float dt, VehStep_Accumulator& chassis);
    void FUN_00e380c0(VehStep_Accumulator& chassis);
    void FUN_00e38140(float dt, VehStep_FrictionParams& params, VehStep_Ground& ground);
    void FUN_00e38310(float dt, VehStep_Ground& ground, VehStep_FrictionParams& params);
    void FUN_00e385e0(const VUC_StepInfo& stepInfo, VehStep_Output* out, void* a2, void* a3);
};

// Calls motion slots 5c and 60 with out's transforms, applies velocity damping, then runs the axle and friction helpers between two timer samples.
// @fnv 0x00e385e0
void VehStep_Vehicle::FUN_00e385e0(const VUC_StepInfo& stepInfo, VehStep_Output* out, void* a2, void* a3)
{
    volatile unsigned int ticks;
    {
        VUC_Mon* mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16)
        {
            VUC_Timer* t = (VUC_Timer*)pos;
            t->m_name = str_010eb844;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_kRayEnd = pos + sizeof(VUC_Timer);
        }
    }

    float dt = stepInfo.m_fTimeStep;
    m_pEntity->getMotion()->slot5c(dt, &out->m_transform0);
    m_pEntity->getMotion()->slot60(dt, &out->m_transform1);

    if (m_pVelocityDamper)
        m_pVelocityDamper->ApplyVelocityDamping(dt, *this);

    VehStep_FrictionParams frictionParams;
    for (int i = 0; i < 2; i++)
        frictionParams.m_akAxleParams[i].initialize();
    VehStep_Ground ground;
    VehStep_Accumulators accumulators;
    ground.m_kPointA = 0;
    ground.m_kPointB = 0;

    FUN_00e375a0(dt, a2, a3, ground, frictionParams);
    frictionParams.m_fTorquePitchFactor = m_data->m_fTorquePitchFactor;
    FUN_00e37d60(stepInfo, ground, frictionParams.m_kSecondAccumulator, accumulators, frictionParams);
    FUN_00e37740(stepInfo, frictionParams);
    FUN_00e376e0(dt, frictionParams.m_pChassisCollidable);
    FUN_00e38080(stepInfo, frictionParams);
    FUN_00e380c0(frictionParams.m_pChassisCollidable);
    FUN_00e38140(dt, frictionParams, ground);
    FUN_00e38310(dt, ground, frictionParams);

    {
        VUC_Mon* mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16)
        {
            VUC_Timer* t = (VUC_Timer*)pos;
            t->m_name = str_010c41f8;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_kRayEnd = pos + sizeof(VUC_Timer);
        }
    }
}
}  // namespace fnv_00e385e0

inline void* operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}
class hkMemoryAllocatorE39
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterE39
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE39* m_pStreamAllocator;
    hkMemoryAllocatorE39& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterE39& __cdecl GetMemoryRouterE39() throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorE39& kAlloc, void* pArray, int iNumElements, int iSizeElem);

template <class T> __forceinline void destructE39(T* pArr, int n)
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}
template <class T> __forceinline void copyE39(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}
template <class T> __forceinline void constructWithArrayE39(T* pDst, int n, const T* pSrc)
{
    for (int i = 0; i < n; i++)
        ::new (static_cast<void*>(pDst + i)) T(pSrc[i]);
}
template <class T> class hkClassArrayE39
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorE39& kAlloc, int n)
    {
        if (getCapacity() < n)
        {
            int iCap2 = 2 * getCapacity();
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline hkClassArrayE39& operator=(const hkClassArrayE39& a)
    {
        hkMemoryAllocatorE39& kAlloc = GetMemoryRouterE39().heap();
        const int iOldSize = m_iElementCount;
        const int iNewSize = a.m_iElementCount;
        int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
        reserve(kAlloc, iNewSize);
        destructE39(m_data + iNewSize, iOldSize - iNewSize);
        copyE39(m_data, a.m_data, iCopiedSize);
        constructWithArrayE39(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
        m_iElementCount = iNewSize;
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <class T> class hkPodArrayE39
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline hkPodArrayE39& operator=(const hkPodArrayE39& a)
    {
        hkMemoryAllocatorE39& kAlloc = GetMemoryRouterE39().heap();
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = a.m_iElementCount;
        copyE39(m_data, a.m_data, m_iElementCount);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkStringPtrE39
{
    hkStringPtrE39& operator=(const hkStringPtrE39& kOther);
    const char* m_pcText;
};
struct WheelE39
{
    WheelE39& operator=(const WheelE39& kOther);
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8C;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9C;
    int m_iA0;
    int m_iA4;
    int m_iA8;
    int m_iAC;
    int m_iB0;
    int m_iB4;
    int m_iB8;
    int m_iBC;
    int m_iC0;
    int m_iC4;
    int m_iC8;
    int m_iCC;
    int m_iD0;
    int m_iD4;
    int m_iD8;
    int m_iDC;
};

extern "C" __m128 _mm_setzero_ps();

struct FUN_00e39400_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    VUC_Allocator* m_pThreadAllocator;
};

// Frees the backing buffers of m_kSecondRealArray and m_kFirstRealArray via the thread allocator and resets their state to empty.
// @fnv 0x00e39400
FUN_00e39400::~FUN_00e39400() throw()
{
    FUN_00e39400_Router* m = (FUN_00e39400_Router*)FUN_00c85750();
    VUC_Allocator* alloc = m->m_pThreadAllocator;
    int c = m_kSecondRealArray.m_iCapacityState;
    m_kSecondRealArray.m_iElementCount = 0;
    if (!(c & 0x80000000))
        alloc->free(m_kSecondRealArray.m_data, c & 0x3fffffff);
    m_kSecondRealArray.m_data = 0;
    m_kSecondRealArray.m_iCapacityState = 0x80000000;
    m = (FUN_00e39400_Router*)FUN_00c85750();
    alloc = m->m_pThreadAllocator;
    c = m_kFirstRealArray.m_iCapacityState;
    m_kFirstRealArray.m_iElementCount = 0;
    if (!(c & 0x80000000))
        alloc->free(m_kFirstRealArray.m_data, (c & 0x3fffffff) * 4);
    m_kFirstRealArray.m_data = 0;
    m_kFirstRealArray.m_iCapacityState = 0x80000000;
}

extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);

extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);

extern "C" __m128 _mm_movelh_ps(__m128, __m128);

extern "C" __m128 _mm_movehl_ps(__m128, __m128);

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

extern "C" __m128 _mm_mul_ps(__m128, __m128);

extern "C" __m128 _mm_add_ps(__m128, __m128);

extern "C" __m128 _mm_sub_ps(__m128, __m128);

extern "C" __m128 _mm_min_ps(__m128, __m128);

extern "C" __m128 _mm_max_ps(__m128, __m128);

extern "C" __m128 _mm_xor_ps(__m128, __m128);

extern "C" __m128 _mm_set_ps1(float);

extern const __m128 DAT_010c44d0;

struct VehFr_Vector4
{

    __m128 m_vComponents;

    void SetAllComponents(float a)

    {

        m_vComponents = _mm_set_ps1(a);
    }
};

struct VehFr_Accumulator
{

    int m_type;

    int unk04;

    int unk08;

    int unk0C;

    VehFr_Vector4 m_vLinearVelocity;

    VehFr_Vector4 m_vAngularVelocity;

    VehFr_Vector4 m_vInverseInertiaAndMass;

    VehFr_Vector4 m_vCenterOfMass;

    VehFr_Vector4 m_coreFromWorld0;

    VehFr_Vector4 m_coreFromWorld1;

    VehFr_Vector4 m_coreFromWorld2;
};

struct VehFr_AxleParams
{

    VehFr_Vector4 m_kFirstVector;

    VehFr_Vector4 m_kSecondAxleVector;

    VehFr_Vector4 m_kThirdVector;

    VehFr_Accumulator* m_pFirstPointer;

    VehFr_Accumulator* m_pSecondPointer;

    float m_fFirstScalar;

    float m_fSecondScalar;

    float m_fThirdValue;

    float m_fFourthValue;

    float m_fFifthScalar;

    float m_fSixthValue;

    unsigned char m_ucValue;
};

struct VehFr_FrictionParams
{

    VehFr_AxleParams m_akAxleParams[2];
};

struct VehFr_Motion
{

    virtual void slot00();

    virtual void slot04();

    virtual void slot08();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void SetTranslationalVelocity(const VehFr_Vector4& v);

    virtual void SetRotationalVelocity(const VehFr_Vector4& v);
};

struct VehFr_MotionData
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

    VehFr_Vector4 m_kTranslationalVelocity;

    VehFr_Vector4 m_kAngularVelocity;
};

struct VehFr_Entity
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

    VehFr_Motion m_pMotionState;

    int unkE4;

    unsigned char m_bFlag;

    unsigned char unkE9;

    unsigned char unkEA;

    unsigned char unkEB;

    int unkEC;
};

struct VehFr_Ground
{

    VehFr_Entity* m_apEntities[2];
};

struct VehFr_Data
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

    int m_iWheelCount;
};

struct VehFr_Vehicle
{

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    VehFr_Data* m_data;

    void FUN_00e38140(float dt, VehFr_FrictionParams& params, VehFr_Ground& ground);
};

// For each wheel with a ground body, moves its angular and linear velocity toward the axle accumulator's, changing each by at most dt*10.
// @fnv 0x00e38140
void VehFr_Vehicle::FUN_00e38140(float dt, VehFr_FrictionParams& params, VehFr_Ground& ground)

{

    VehFr_AxleParams* axle = params.m_akAxleParams;
    for (int i = 0; i < m_data->m_iWheelCount; i++)

    {

        VehFr_Entity* groundBody = ground.m_apEntities[i];

        if (!groundBody || groundBody->m_bFlag == 5)

        {
            ++axle;
            continue;
        }

        if (i != 0 && ground.m_apEntities[0] == ground.m_apEntities[1])

        {
            ++axle;
            continue;
        }

        VehFr_Motion* motion = &groundBody->m_pMotionState;

        VehFr_Accumulator* acc = axle->m_pFirstPointer;

        VehFr_Vector4 angVel;

        {

            __m128 c0 = acc->m_coreFromWorld0.m_vComponents;

            __m128 c1 = acc->m_coreFromWorld1.m_vComponents;

            __m128 c2 = acc->m_coreFromWorld2.m_vComponents;

            __m128 tmp = _mm_unpacklo_ps(c0, c1);

            __m128 ctmp = _mm_unpackhi_ps(c0, c1);

            c0 = _mm_movelh_ps(tmp, c2);

            tmp = _mm_movehl_ps(c0, tmp);

            c1 = _mm_shuffle_ps(tmp, c2, 0xd4);

            c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);

            const __m128 b = acc->m_vAngularVelocity.m_vComponents;

            const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);

            const __m128 r0 = _mm_mul_ps(c0, b0);

            const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);

            const __m128 r1 = _mm_mul_ps(c1, b1);

            const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);

            const __m128 r2 = _mm_mul_ps(c2, b2);

            angVel.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
        }

        acc = (VehFr_Accumulator*)&acc->m_vLinearVelocity;

        VehFr_Vector4 linVel = *(const VehFr_Vector4*)&acc->m_type;

        {

            VehFr_Vector4 cur = ((VehFr_MotionData*)motion)->m_kAngularVelocity;

            VehFr_Vector4 kMaxDelta;
            kMaxDelta.SetAllComponents(dt * 10.0);

            __m128 d = _mm_sub_ps(angVel.m_vComponents, cur.m_vComponents);

            d = _mm_min_ps(d, kMaxDelta.m_vComponents);

            d = _mm_max_ps(d, _mm_xor_ps(kMaxDelta.m_vComponents, DAT_010c44d0));

            angVel.m_vComponents = _mm_add_ps(d, cur.m_vComponents);
        }

        {

            VehFr_Vector4 cur = ((VehFr_MotionData*)motion)->m_kTranslationalVelocity;

            VehFr_Vector4 kMaxDelta;
            kMaxDelta.SetAllComponents(dt * 10.0);

            __m128 d = _mm_sub_ps(linVel.m_vComponents, cur.m_vComponents);

            d = _mm_min_ps(d, kMaxDelta.m_vComponents);

            d = _mm_max_ps(d, _mm_xor_ps(kMaxDelta.m_vComponents, DAT_010c44d0));

            linVel.m_vComponents = _mm_add_ps(d, cur.m_vComponents);
        }

        motion->SetRotationalVelocity(angVel);

        motion->SetTranslationalVelocity(linVel);
        ++axle;
    }
}

namespace fnv_00e38b20 {
class FUN_00d2b260
{
  public:
    FUN_00d2b260(void* pkEntity, unsigned long ulUserData) throw();
    virtual ~FUN_00d2b260() throw();

    int unk04, unk08, unk0C, unk10, unk14, unk18;
};

template <class T> class hkArrayE38B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE38B() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct AxisStatusE38B
{
    float m_fAxisStatusMetric1;
    float m_fAxisStatusMetric2;
    float m_fAxisStatusMetric3;
    float m_fAxisStatusMetric4;
    float m_fAxisStatusMetric5;
    float m_fAxisStatusMetric6;
    float m_fAxisStatusMetric7;
    float m_fAxisStatusMetric8;
    float m_fAxisStatusMetric9;

    AxisStatusE38B()
    {
        m_fAxisStatusMetric1 = 0.0f;
        m_fAxisStatusMetric2 = 0.0f;
        m_fAxisStatusMetric3 = 0.0f;
        m_fAxisStatusMetric4 = 0.0f;
        m_fAxisStatusMetric5 = 0.0f;
        m_fAxisStatusMetric6 = 0.0f;
        m_fAxisStatusMetric7 = 0.0f;
        m_fAxisStatusMetric8 = 0.0f;
        m_fAxisStatusMetric9 = 0.0f;
    }
};

struct FrictionStatusE38B
{
    AxisStatusE38B m_kAxisEndPoints[2];
};

struct WheelInfoE38B
{
    int unk00[0x40];
};

class FUN_00e38b20 : public FUN_00d2b260
{
  public:
    void* m_data;
    void* m_pDriverInput;
    void* m_pSteering;
    void* m_pVehicleEngine;
    void* m_pTransmission;
    void* m_pBrake;
    void* m_pSuspension;
    void* m_pAerodynamics;
    void* m_pWheelCollide;
    void* m_pTyremarksInfo;
    void* m_pVelocityDamper;
    hkArrayE38B<WheelInfoE38B> m_kWheelInfoArray;
    FrictionStatusE38B m_kFrictionStatus;
    void* m_pDriverInputStatus;
    hkArrayE38B<bool> m_kSecondRealArray;
    float m_fBrakeState;
    bool m_bIsReversing;
    float m_fFirstValueBeforeSteeringAngle;
    float m_fSecondValueBeforeSteeringAngle;
    float m_fMainSteeringAngle;
    hkArrayE38B<float> m_kWheelSteeringAngles;

    FUN_00e38b20(void* pkChassis) throw();
    virtual ~FUN_00e38b20() throw();
};

// Passes pkChassis and 0 to the base constructor and zeroes m_data and the subsystem pointer members.
// @fnv 0x00e38b20
FUN_00e38b20::FUN_00e38b20(void* pkChassis) throw() : FUN_00d2b260(pkChassis, 0)
{
    m_data = 0;
    m_pDriverInput = 0;
    m_pSteering = 0;
    m_pVehicleEngine = 0;
    m_pTransmission = 0;
    m_pBrake = 0;
    m_pSuspension = 0;
    m_pAerodynamics = 0;
    m_pWheelCollide = 0;
    m_pTyremarksInfo = 0;
    m_pVelocityDamper = 0;
    m_pDriverInputStatus = 0;
}
}  // namespace fnv_00e38b20

extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" float _mm_cvtss_f32(__m128 _A);
extern "C" __m128 _mm_sqrt_ss(__m128 _A);
struct S00e37880_Vec
{
    __m128 m_vComponents;

    __m128 squared() const
    {
        return _mm_mul_ps(m_vComponents, m_vComponents);
    }
};

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" float _mm_cvtss_f32(__m128);

struct SpeedVectorE378
{
    __m128 m_vComponents;
    float length3() const
    {
        __m128 squares = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(squares, squares, 0x55);
        __m128 z = _mm_shuffle_ps(squares, squares, 0xaa);
        return _mm_cvtss_f32(_mm_sqrt_ss(_mm_add_ss(z, _mm_add_ss(y, squares))));
    }
};
struct SpeedBodyE378
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
    SpeedVectorE378 m_kTranslationalVelocity;
    const SpeedVectorE378& linearVelocity() const
    {
        return m_kTranslationalVelocity;
    }
};

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" float _mm_cvtss_f32(__m128);

struct S00e375a0_AxleData
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
};

struct __declspec(align(16)) FourFloatVector
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        __m128 m_vComponents;
    };
    __forceinline __m128 length3() const
    {
        __m128 v2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 v1 = _mm_shuffle_ps(v2, v2, 0x55);
        __m128 v0 = _mm_shuffle_ps(v2, v2, 0xaa);
        v1 = _mm_add_ss(v1, v2);
        v0 = _mm_add_ss(v0, v1);
        return _mm_sqrt_ss(v0);
    }
    __forceinline float getW() const
    {
        float w;
        _mm_store_ss(&w, _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
        return w;
    }
};

class S00e375a0_hkpRigidBody
{
  public:
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
    FourFloatVector m_kInertiaAndMassInv;
    FourFloatVector m_kTranslationalVelocity;
};

class hkpVehicleInstanceWheelInfo
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S00e375a0_hkpRigidBody* m_pUserData;
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
};

class S00e375a0_VehicleInstance : public VUC_Instance
{
  public:
    int unk_veh20;
    int unk_veh24;
    int unk_veh28;
    int unk_veh2c;
    int unk_veh30;
    int unk_veh34;
    int unk_veh38;
    int unk_veh3c;
    int unk_veh40;
    int unk_veh44;
    hkArray<hkpVehicleInstanceWheelInfo> m_kWheelInfoArray;

    void FUN_00e371d0(float deltaTime, int wheelIndex, float suspensionForce) throw();
    void FUN_00e37350(int wheelIndex, float totalLinearForce, float suspensionForce, float linearVelocity,
                      S00e375a0_AxleData* axleData) throw();
    void FUN_00e375a0(float deltaTime, VUC_RealArray& suspensionForceAtWheel, VUC_RealArray& totalLinearForceAtWheel,
                      S00e375a0_hkpRigidBody* maxMassBodyPerAxle[2], S00e375a0_AxleData* axleData);
};

// Iterates wheels, calls FUN_00e371d0 and FUN_00e37350, and tracks the max-mass contact body per axle in maxMassBodyPerAxle.
// @fnv 0x00e375a0
void S00e375a0_VehicleInstance::FUN_00e375a0(float deltaTime, VUC_RealArray& suspensionForceAtWheel,
                                             VUC_RealArray& totalLinearForceAtWheel,
                                             S00e375a0_hkpRigidBody* maxMassBodyPerAxle[2],
                                             S00e375a0_AxleData* axleData)
{
    S00e375a0_hkpRigidBody* chassis = (S00e375a0_hkpRigidBody*)m_pEntity;
    float linearVelocity;
    _mm_store_ss(&linearVelocity, chassis->m_kTranslationalVelocity.length3());

    for (int i = 0; i < (int)m_data->m_iWheelCount; ++i)
    {
        int axle = m_data->m_kWheelParams[i].m_iAxle;
        hkpVehicleInstanceWheelInfo* wheelInfo = &m_kWheelInfoArray.m_data[i];

        FUN_00e371d0(deltaTime, i, suspensionForceAtWheel.m_data[i]);

        S00e375a0_hkpRigidBody* contactBody = wheelInfo->m_pUserData;
        if (contactBody)
        {
            S00e375a0_hkpRigidBody* curMaxBody = maxMassBodyPerAxle[axle];
            if (!curMaxBody || contactBody->m_kInertiaAndMassInv.getW() < curMaxBody->m_kInertiaAndMassInv.getW())
            {
                maxMassBodyPerAxle[axle] = contactBody;
            }
        }

        FUN_00e37350(i, totalLinearForceAtWheel.m_data[i], suspensionForceAtWheel.m_data[i], linearVelocity,
                     &axleData[axle]);
    }
}

struct VUC_DriverInputStandIn
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void UpdateDriverInput(float dt, VUC_Instance* instance, unsigned int deviceStatus, VUC_Filtered& f);
};

// Reads a byte from the instance, copies it into the filtered data, then calls the driver input update and writes the filtered byte back.
// @fnv 0x00e36f60
__declspec(noinline) void VUC_Instance::FUN_00e36f60(float dt, VUC_Filtered& f) throw()
{
    unsigned char* instanceByte = reinterpret_cast<unsigned char*>(this) + 0xb0;
    unsigned char* filteredByte = reinterpret_cast<unsigned char*>(&f) + 0x0d;

    unsigned int value = *instanceByte;
    *filteredByte = static_cast<unsigned char>(value);

    unsigned int deviceStatus = *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x9c);

    VUC_DriverInputStandIn* driverInput =
        *reinterpret_cast<VUC_DriverInputStandIn**>(reinterpret_cast<unsigned char*>(this) + 0x20);

    driverInput->UpdateDriverInput(dt, this, deviceStatus, f);

    *instanceByte = *filteredByte;
}

struct VehicleAeroDispatch
{
    virtual void slot00() throw() = 0;
    virtual void slot04() throw() = 0;
    virtual void slot08() throw() = 0;
    virtual void calculate(float deltaTime, const hkpVehicleInstance* vehicle, void* output) throw() = 0;
};

class VehicleAeroInstance : public hkpVehicleInstance
{
  public:
    void FUN_00e37080(float deltaTime, void* output) throw();
};

// @fnv 0x00e37080
void VehicleAeroInstance::FUN_00e37080(float deltaTime, void* output) throw()
{
    VehicleAeroDispatch* aerodynamics = reinterpret_cast<VehicleAeroDispatch*>(m_pAerodynamics);
    aerodynamics->calculate(deltaTime, this, output);
}
