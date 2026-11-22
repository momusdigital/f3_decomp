#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPrismaticConstraintData.h"

extern "C" void* __cdecl FUN_00d21a60(void* self, int a, void* b);

struct FUN_00d4f880_class : public hkpPrismaticConstraintData
{
    void* __thiscall FUN_00d4f880(int a);
};

// @fnv 0x00d4f880
// pdb: hkpPrismaticConstraintData::getConstraintInfo | hkpPrismaticConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: infoOut
void* __thiscall FUN_00d4f880_class::FUN_00d4f880(int a)
{
    return FUN_00d21a60(&m_kBridgeAtoms, m_kBridgeAtoms.getSizeOfAllAtoms(), (void*)a);
}

// @fnv 0x00d4f8a0
// pdb: hkpPrismaticConstraintData::getRuntimeInfo | hkpPrismaticConstraintData.obj | tesv_win, objrun_sim, low
void __stdcall FUN_00d4f8a0(int aiUnused, hkpPrismaticConstraintData* apConstraintData)
{
    *(int*)((char*)apConstraintData + 4) = 8;
    *(int*)((char*)apConstraintData + 0) = 0x48;
}

extern int DAT_010d0b3c;
extern int DAT_0102e388;
struct DDCC60World
{
    void removeReference();
};
struct FUN_00d4f8d0_class
{
    int* vtbl;
    void FUN_00d4f8d0();
};
// Sets the vtable to DAT_010d0b3c, releases the DDCC60World reference at offset 0xac if present, then sets the vtable to DAT_0102e388.
// @fnv 0x00d4f8d0
void FUN_00d4f8d0_class::FUN_00d4f8d0()
{
    DDCC60World* p = *reinterpret_cast<DDCC60World**>(reinterpret_cast<unsigned char*>(this) + 0xac);
    vtbl = &DAT_010d0b3c;
    if (p)
        p->removeReference();
    vtbl = &DAT_0102e388;
}

// FUN_00d4f8c0: cdecl constant-return leaf (mov eax,6; ret)
// @fnv 0x00d4f8c0
// pdb: hkpLinFrictionConstraintAtom::hkpLinFrictionConstraintAtom | hkpPrismaticConstraintData.obj | fnv360_0822_debug, objrun_open, low
int FUN_00d4f8c0()
{
    return 6;
}

class hkBoolD4FD
{
  public:
    hkBoolD4FD(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

extern float DAT_01017d00;

class hkTransformD4FD
{
  public:
    hkBoolD4FD IsOrthonormal(float epsilon) const;
    float m_data[16];
};

class hkObjD4FD
{
  public:
    int unk00[8];
    hkTransformD4FD m_kPointA;
    hkTransformD4FD m_kPointB;
    int unkA0[10];
    float m_kMinimumCorner;
    float m_kMaximumCorner;

    hkBoolD4FD IsValid() const;
};

// @fnv 0x00d4fdd0
// pdb: hkpPrismaticConstraintData::isValid | hkpPrismaticConstraintData.obj | fnv360_0822_retail, objrun_open, low
hkBoolD4FD hkObjD4FD::IsValid() const
{
    return m_kPointA.IsOrthonormal(DAT_01017d00) && m_kPointB.IsOrthonormal(DAT_01017d00) && m_kMinimumCorner <= m_kMaximumCorner;
}

class hkMemoryAllocatorD4FF
{
  public:
    virtual ~hkMemoryAllocatorD4FF() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4FF
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4FF* m_pStreamAllocator;
    hkMemoryAllocatorD4FF& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4FF& __cdecl FUN_00c85750();

class FUN_00d4f8d0
{
  public:
    virtual ~FUN_00d4f8d0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d4f8d0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d4f8d0* FUN_00d4ffd0(unsigned int uiFlags) throw();
};

extern int DAT_0102e388;

struct RefObj
{
    void removeReference();
};

struct Embedded
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
    void Run();
};

struct FUN_00d50c50
{
    int* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Embedded mSub;
    RefObj** mArr;
    int mCount;
    ~FUN_00d50c50();
};

// @f3 0x009ddf00 (community match, verified in this file)
extern int FUN_00e803ac;
extern int FUN_00dcc494;
// pdb: hkpGenericConstraintData::~hkpGenericConstraintData | hkpGenericConstraintData.obj | fnv360_0822_debug, call_seq, medium
FUN_00d50c50::~FUN_00d50c50()
{
    vtbl = &FUN_00e803ac;
    for (int i = 0; i < mCount; ++i)
    {
        FUN_00d4f8d0* obj = reinterpret_cast<FUN_00d4f8d0*>(mArr[i]);
        if (obj->m_usMemSizeAndFlags != 0)
        {
            if (--obj->m_sReferenceCount == 0)
            {
                delete obj;
            }
        }
    }
    mSub.Run();
    vtbl = &FUN_00dcc494;
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

#include <math.h>
