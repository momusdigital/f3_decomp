#include "f3_common.h"
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexTranslateShape.h"

class hkpShapeCollectionDD5E
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual int getChildShapes(int iKey, int iBufferSize) throw();
};

class hkpShapeBufferDD5E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkpShapeCollectionDD5E* m_pShapeCollection;
    int m_offset;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkpShapeCollectionDD5E m_inlineCollection;

    int GetChildShapes(int iKey, int iBufferSize);
};

// @fnv 0x00dd5e10
// pdb: hkpConvexTranslateShape::calcSizeForSpu | hkpConvexTranslateShape.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: input, spuBufferSizeLeft
int hkpShapeBufferDD5E::GetChildShapes(int iKey, int iBufferSize)
{
    const int iMax = iBufferSize - 0x30;
    int iResult = m_pShapeCollection->getChildShapes(iKey, iMax);
    if (iResult < 0)
        return -1;
    if (iResult > iMax)
        return -1;
    if (m_pShapeCollection == &m_inlineCollection)
    {
        m_offset = 0;
        return iResult + 0x30;
    }
    m_offset = iResult;
    return 0x30;
}

struct FUN_00dd5ea0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* FUN_00dd5ea0();
};
// @fnv 0x00dd5ea0
void* FUN_00dd5ea0_class::FUN_00dd5ea0()
{
    return &unk14;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct hkVector4D5F
{
    __m128 m_vComponents;
    void add4(const hkVector4D5F& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void setAdd4(const hkVector4D5F& a, const hkVector4D5F& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
};

namespace fnv_00dd60e0 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static MonitorStream* GetMonitorStream()
    {
        return (MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};

static const char s_kEndTimer[] = "Et";

class HkBoolDD
{
  public:
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class Vec4DD
{
  public:
    __m128 m_vComponents;
    void setSub4(const Vec4DD& a, const Vec4DD& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct RayOutputDD60
{
    Vec4DD m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int pad[2];
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void changeLevel(int delta)
    {
        m_uiShapeKeyIndex += delta;
    }
    void setKey(unsigned int key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

}  // namespace fnv_00dd60e0
