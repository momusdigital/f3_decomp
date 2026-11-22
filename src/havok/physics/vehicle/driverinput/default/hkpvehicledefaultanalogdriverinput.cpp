#include "f3_common.h"
// src/havok/physics/vehicle/driverinput/default/hkpvehicledefaultanalogdriverinput.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/driverinput/default/hkpvehicledefaultanalogdriverinput.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleDefaultAnalogDriverInput.h"

// Fills output with the results of calculateX, calculateY, calculateZ and calculateButton, and copies status->unk10 into output->autoReverse.
// @f3 0x007fa880 (community match, verified in this file)
struct PlaybackSource1188
{
    int first;
    int second;
};
struct PlaybackManager1188
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void* GetReader();

    float FUN_007fb000(int, int, bool);
    float FUN_007fb080(float, int, bool);
    float FUN_007fb0d0(float, int, bool);
};

extern PlaybackManager1188* DAT_0108ebbc;
extern const char DAT_00e20140[];
void* __cdecl FUN_007fa220(void*, int, int, int, int, int);
void __cdecl FUN_00887da0(const char*, const char*);

struct NiPlaybackFile
{
    PlaybackSource1188* source;
    void* reader;
    void* buffer;
    int unk0c, unk10;
    float first, second, third;
    int active;

    bool FUN_007fa6c0(const char*, bool, bool, bool);
    bool FUN_007fa880(const char* path, bool quiet, bool option, bool sample);
};

// pdb: Movie::LoadBink | MoviePlayer_Xenon.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apFileName, abSkipWarning, abPreloadBink, abLetterBoxed
bool NiPlaybackFile::FUN_007fa880(const char* path, bool quiet, bool option, bool sample)
{
    if (!source && !FUN_007fa6c0(path, quiet, option, false))
        return false;

    reader = DAT_0108ebbc->GetReader();
    float value = DAT_0108ebbc->FUN_007fb000(source->first, source->second, sample);
    first = value;
    second = DAT_0108ebbc->FUN_007fb080(value, source->first, sample);
    third = DAT_0108ebbc->FUN_007fb0d0(first, source->second, sample);
    buffer = FUN_007fa220(reader, source->first, source->second, 4, 256, 22);
    if (!buffer)
    {
        if (!quiet)
            FUN_00887da0(DAT_00e20140, path);
        active = 0;
        return false;
    }
    return true;
}


struct hkBoolE436
{
    char m_cBooleanValue;
    void operator=(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkReferencedObjectE436
{
  public:
    hkReferencedObjectE436() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE436()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpVehicleDriverInputE436 : public hkReferencedObjectE436
{
  public:
    hkpVehicleDriverInputE436()
    {}
};

typedef char hkBool;
typedef float hkReal;

// hkpVehicleDriverInputAnalogStatus: m_iGearCount sits at offset 0xcc.
struct hkpVehicleDriverInputAnalogStatus
{
    char pad0[0xcc];
    hkBool m_iGearCount;
};

struct hkpVehicleDriverInputFilteredInput
{
    char pad0[0xc];
    hkReal m_uiFilterValue;
};

// this-call wrapper with the layout of hkpVehicleDefaultAnalogDriverInput
struct AnalogDriverInput
{
    char pad0[0x14];
    hkBool m_bAutoReverse;

    hkReal FUN_00e435a0(hkReal deltaTime, const hkpVehicleDriverInputAnalogStatus* status,
                        const hkpVehicleDriverInputFilteredInput* input, int wheel);
};

class hkMemoryAllocatorE43A
{
  public:
    virtual ~hkMemoryAllocatorE43A() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE43A
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE43A* m_pStreamAllocator;

    hkMemoryAllocatorE43A& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE43A {
extern "C" hkMemoryRouterE43A& __cdecl FUN_00c85750() throw();
}

class hkRefObjE43A
{
  public:
    virtual ~hkRefObjE43A();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjE43A* b = static_cast<hkRefObjE43A*>(hkRouterE43A::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
    hkRefObjE43A()
    {
        m_sReferenceCount = 1;
    }
};

#include <math.h>
namespace fnv_00e436b0 {
typedef float hkReal;

struct AnalogStatus
{
    void* vtable;
    int refCount;
    hkReal m_fPositionX;
    hkReal m_fPositionY;
};

class AnalogDriverInput
{
  public:
    void* vtable;
    int refCount;
    hkReal m_fSlopeUp;
    hkReal m_fDeadZone;
    hkReal m_fSlopeDown;
    bool m_bAutoReverse;

    hkReal GetOutput(hkReal deltaTime, const void* vehicle, const AnalogStatus* status, void* out) const;
};

}  // namespace fnv_00e436b0

struct __declspec(intrin_type) __declspec(align(16)) __m128
{
    float f0, f1, f2, f3;
};
extern "C"
{
    float _mm_cvtss_f32(__m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}

extern const float DAT_01011d78 = 0.0f;
extern const float DAT_01016248 = 0.5f;
extern const float DAT_01017718 = 3.0f;
extern const float DAT_0104da4c = 1.1920928955078125e-07f;
extern const float DAT_010ebf10 = 1.38888896f;
extern const double DAT_0101ffa0 = 0.10000000149011612;

namespace e43780 {
struct HkVec
{
    float x, y, z, w;
    __forceinline const __m128& quad() const
    {
        return *(const __m128*)&x;
    }
};

}
