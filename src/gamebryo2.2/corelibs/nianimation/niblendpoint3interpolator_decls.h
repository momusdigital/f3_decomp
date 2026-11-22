// gamebryo2.2/corelibs/nianimation/niblendpoint3interpolator_decls.h: declares NiInterpolator, NiBlendInterpolator, NiBlendPoint3Interpolator
#ifndef FNV_NIBLENDPOINT3INTERPOLATOR_PRIVATE_DECLS_H
#define FNV_NIBLENDPOINT3INTERPOLATOR_PRIVATE_DECLS_H
#include "f3_common.h"

#include "NiInterpolator.h"
#include "NiPoint3.h"

class NiObjectNET;
class NiAVObject;
class NiQuatTransform;
class NiStream;
class NiBlendInterpolator__InterpArrayItem;

class NiBlendInterpolator : public NiInterpolator
{
  public:
    unsigned char m_uFlags;  // src: FNV360_PDB +0xC (old: m_uiObjectFlags)
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    NiBlendInterpolator__InterpArrayItem* m_pkInterpArray;  // src: FNV360_PDB +0x14 (old: m_pInterpArray)
    NiInterpolator* m_pkSingleInterpolator;  // src: FNV360_PDB +0x18 (old: m_pSingleInterpolator)
    float m_fWeightThreshold;
    float m_fSingleTime;  // src: FNV360_PDB +0x20 (old: m_fSingleInterpolatorTime)
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fHighEaseSpinner;  // src: FNV360_PDB +0x2C (old: m_fTrailingValue)

    void NormalizeWeights();
};

class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
  public:
    NiPoint3 m_kPoint3Value;
    bool m_bValidValue;  // src: FNV360_PDB +0x3C (old: m_bValueValid)

    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiPoint3&);
    bool UpdateSingleInterpolator(float, NiObjectNET*, NiPoint3&);
    virtual bool Update(float, NiObjectNET*, NiPoint3&);
};

extern const float DAT_0109696c;
extern const NiPoint3 DAT_011a9424;

FNV_STATIC_ASSERT(sizeof(NiBlendInterpolator) == 48);
FNV_STATIC_ASSERT(sizeof(NiBlendPoint3Interpolator) == 64);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_pkSingleInterpolator) == 24);
FNV_STATIC_ASSERT(offsetof(NiBlendPoint3Interpolator, m_kPoint3Value) == 48);

#endif
