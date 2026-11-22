// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMDATA_H
#define FNV_NITRANSFORMDATA_H
#include "f3_common.h"
#include "layout_support.h"
#include "NiObject.h"
class TimedAnimationKey;
class PositionKeyInterpolator;
class TimedRotationKey;
class NiTransformData;
enum NiAnimationKey__KeyType
{
    NiAnimationKey__KeyType_NOINTERP = 0,
    NiAnimationKey__KeyType_LINKEY = 1,
    NiAnimationKey__KeyType_BEZKEY = 2,
    NiAnimationKey__KeyType_TCBKEY = 3,
    NiAnimationKey__KeyType_EULERKEY = 4,
    NiAnimationKey__KeyType_STEPKEY = 5,
    NiAnimationKey__KeyType_NUMKEYTYPES = 6
};
#pragma pack(push, 4)
class NiTransformData : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned short m_usNumRotKeys;    // +0x8, 2 bytes
    unsigned short m_usNumPosKeys;    // +0xA, 2 bytes
    unsigned short m_usNumScaleKeys;  // +0xC, 2 bytes
    unsigned char layoutPaddingE[2];
    NiAnimationKey__KeyType m_eRotType;  // +0x10, 4 bytes  // src: FNV360_PDB +0x10 (old: m_eRotationKeyType)
    NiAnimationKey__KeyType m_ePosType;  // +0x14, 4 bytes  // src: FNV360_PDB +0x14 (old: m_ePositionKeyType)
    NiAnimationKey__KeyType m_eScaleType;     // +0x18, 4 bytes  // src: FNV360_PDB +0x18 (old: m_eScaleKeyType)
    unsigned char m_ucRotSize;           // +0x1C, 1 bytes  // src: FNV360_PDB +0x1C (old: m_ucRotationKeySize)
    unsigned char m_ucPosSize;           // +0x1D, 1 bytes  // src: FNV360_PDB +0x1D (old: m_ucPositionKeySize)
    unsigned char m_ucScaleSize;              // +0x1E, 1 bytes  // src: FNV360_PDB +0x1E (old: m_ucScaleKeySize)
    unsigned char layoutPadding1F[1];
    TimedRotationKey* m_pkRotKeys;         // +0x20, 4 bytes  // src: FNV360_PDB +0x20 (old: m_pkRotationKeys)
    PositionKeyInterpolator* m_pkPosKeys;  // +0x24, 4 bytes  // src: FNV360_PDB +0x24 (old: m_pkPositionKeys)
    TimedAnimationKey* m_pkScaleKeys;       // +0x28, 4 bytes  // src: FNV360_PDB +0x28 (old: m_pkScaleKeyArray)
    // const NiRTTI* __cdecl NiTransformData::*()
    // void __cdecl NiTransformData::*(NiStream&)
    // void __cdecl NiTransformData::*(NiStream&)
    // bool __cdecl NiTransformData::*(NiStream&)
    // void __cdecl NiTransformData::*(NiStream&)
    // bool __cdecl NiTransformData::*(NiObject*)
    // NiObject* __cdecl NiTransformData::*()
    // void __cdecl NiTransformData::*(NiTPrimitiveArray<char *>*)
    // NiTransformData
    // void __cdecl NiTransformData::*()
    // unsigned int __cdecl NiTransformData::*()
    // unsigned int __cdecl NiTransformData::*()
    // unsigned int __cdecl NiTransformData::*()
    // void __cdecl NiTransformData::*(float, float)
    // void __cdecl NiTransformData::*(float, float, NiPointer<NiTransformData>&)
    // NiTransformData& __cdecl NiTransformData::*(const NiTransformData&)
    // void __cdecl NiTransformData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTransformData) == 44);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_usNumRotKeys) == 8);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_usNumPosKeys) == 10);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_usNumScaleKeys) == 12);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_eRotType) == 16);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_ePosType) == 20);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_eScaleType) == 24);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_ucRotSize) == 28);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_ucPosSize) == 29);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_ucScaleSize) == 30);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkRotKeys) == 32);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkPosKeys) == 36);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkScaleKeys) == 40);
#endif
