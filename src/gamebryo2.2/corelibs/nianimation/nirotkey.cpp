// gamebryo2.2/corelibs/nianimation/nirotkey.cpp: TimedRotationKey (4 functions)
#include "f3_common.h"
#include "nirotkey_decls.h"

#define KEY_TIME(keys, index, size)                                                                                    \
    (*reinterpret_cast<const float*>(reinterpret_cast<const char*>(keys) + (index) * (size)))
#define KEY_AT(keys, index, size)                                                                                      \
    reinterpret_cast<const TimedRotationKey*>(reinterpret_cast<const char*>(keys) + (index) * (size))

// @fnv 0x00a28740
// pdb: NiRotKey::GenInterp | NiRotKey.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: fTime, pkKeys, eType, uiNumKeys, uiLastIdx, ucSize
NiQuaternion __cdecl TimedRotationKey::InterpolatePosition(float fTime, TimedRotationKey* pkKeys,
                                                           AnimationKey::KeyType eType, unsigned int uiNumKeys,
                                                           unsigned int& ruiLastIndex, unsigned char ucKeySize)
{
    NiQuaternion kEulerResult;
    NiQuaternion kResult;
    if (uiNumKeys == 1 || fTime == DAT_010241b0)
    {
        if (eType != AnimationKey::EULERKEY)
            return pkKeys[0].m_kRotationValue;
    }
    if (eType == AnimationKey::EULERKEY)
    {
        DAT_011f3cc0[eType](fTime, pkKeys, 0, &kEulerResult);
        return kEulerResult;
    }
    {
        unsigned int uiLowerIndex = ruiLastIndex;
        unsigned int uiLastKey = uiNumKeys - 1;
        float fLowerTime = KEY_TIME(pkKeys, uiLowerIndex, ucKeySize);
        if (fLowerTime > fTime)
        {
            uiLowerIndex = 0;
            fLowerTime = KEY_TIME(pkKeys, 0, ucKeySize);
        }

        unsigned int uiUpperIndex = uiLowerIndex + 1;
        float fNextTime = 0.0f;
        // Interpolation requires a key following the cached lower key.
        __assume(uiUpperIndex <= uiLastKey);
        while (uiUpperIndex <= uiLastKey)
        {
            fNextTime = KEY_TIME(pkKeys, uiUpperIndex, ucKeySize);
            if (fTime <= fNextTime)
                break;
            fLowerTime = fNextTime;
            ++uiLowerIndex;
            ++uiUpperIndex;
        }

        const TimedRotationKey* pkLower = KEY_AT(pkKeys, uiLowerIndex, ucKeySize);
        const TimedRotationKey* pkUpper = KEY_AT(pkKeys, uiUpperIndex, ucKeySize);
        float fInterpFactor = (fTime - fLowerTime) / (fNextTime - fLowerTime);
        DAT_011f3cc0[eType](fInterpFactor, pkLower, pkUpper, &kResult);
        ruiLastIndex = uiLowerIndex;
        return kResult;
    }
}

// Compares the four floats of pThis with those of q and returns 1 only if all four are exactly equal.
// @fnv 0x00a92660
// pdb: NiColorA::operator== | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
// pdb params: c
int __fastcall FUN_00a92660(const float* pThis, int, const float* q)
{
    return pThis[0] == q[0] && pThis[1] == q[1] && pThis[2] == q[2] && pThis[3] == q[3];
}

void __cdecl FUN_00a57010();

extern void* _DAT_011f3740;

// @fnv 0x00a3ca40
// pdb: BSMultiBoundOBB::GetRTTI | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00a3ca40()
{
    return &_DAT_011f3740;
}

struct FUN_00a3e9a0_src
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class FUN_00a3e9a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00a3e9a0_src* m_18;
    unsigned int unk1C;
    float* m_20;
    float m_24;

    float NiPathInterpolator_PathLength(unsigned int a, unsigned int b, float c);
    float NiPathInterpolator_GetTotalPathLength();
};

void __cdecl FUN_00aa10f0(float* p);
void* __cdecl FUN_00aa1070(unsigned int n);

// If m_24 is negative, allocates a float array sized from m_18->m_08, fills running sums via NiPathInterpolator_PathLength, stores the last value in m_24, and returns m_24.
// @fnv 0x00a3e9a0
// pdb: NiPathInterpolator::GetTotalPathLength | NiPathInterpolator.obj | fnv360_0822_retail, call_seq, high
// pdb: NiPathInterpolator::GetTotalPathLength | NiPathInterpolator.obj | fnv360_0822_retail, call_seq, high (was: GetAccumulatedValue)
float FUN_00a3e9a0_cls::NiPathInterpolator_GetTotalPathLength()
{
    if (m_24 < 0.0f)
    {
        unsigned int count = m_18 ? m_18->m_08 : 0;
        unsigned int bytes = count * 4;
        FUN_00aa10f0(m_20);
        m_20 = (float*)FUN_00aa1070(bytes);
        m_20[0] = 0.0f;
        unsigned int uiIndex = 0;
        unsigned int last = count - 1;
        if (last != 0)
        {
            do
            {
                volatile float t = NiPathInterpolator_PathLength(uiIndex, uiIndex + 1, 1.0f);
                float* p = m_20;
                p[uiIndex + 1] = p[uiIndex] + t;
                uiIndex = uiIndex + 1;
            } while (uiIndex < last);
        }
        *(volatile float*)&m_24 = m_20[count - 1];
    }
    return m_24;
}
