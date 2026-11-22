#include "f3_common.h"
// src/havok/physics/collide/shape/deprecated/fastmesh/hkpfastmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/fastmesh/hkpfastmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpFastMeshShape.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_mul_ps(__m128 kA, __m128 kB);
extern "C" __m128 _mm_load_ps(const float*);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct hkVector4E48C
{
    __m128 m_vComponents;

    hkVector4E48C()
    {}
    hkVector4E48C(const hkVector4E48C& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4E48C& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void setMul4(const hkVector4E48C& kA, const hkVector4E48C& kB)
    {
        m_vComponents = _mm_mul_ps(kA.m_vComponents, kB.m_vComponents);
    }
};

template <class T> struct hkArrayE48C
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBaseObjectE48C
{
  public:
    virtual ~hkBaseObjectE48C() throw();
};

class hkReferencedObjectE48C : public hkBaseObjectE48C
{
  public:
    hkReferencedObjectE48C() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE48C() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeE48C : public hkReferencedObjectE48C
{
  public:
    hkpShapeE48C(unsigned int uiType) throw() : m_ulUserData(0), m_type(uiType)
    {}
    virtual ~hkpShapeE48C() throw();

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpSphereRepShapeE48C : public hkpShapeE48C
{
  public:
    hkpSphereRepShapeE48C(unsigned int uiType) throw() : hkpShapeE48C(uiType)
    {}
    virtual ~hkpSphereRepShapeE48C() throw();
};

class hkpConvexShapeE48C : public hkpSphereRepShapeE48C
{
  public:
    hkpConvexShapeE48C(unsigned int uiType, float fRadius) throw()
        : hkpSphereRepShapeE48C(uiType), m_fSphereRadius(fRadius)
    {}
    virtual ~hkpConvexShapeE48C() throw();

    float m_fSphereRadius;
};

class FUN_00de10b0 : public hkpConvexShapeE48C
{
  public:
    FUN_00de10b0(float fRadius, unsigned short usWeldingInfo, int eWeldingType) throw() : hkpConvexShapeE48C(3, fRadius)
    {
        m_kWeldingInfo = usWeldingInfo;
        m_eWeldingType = static_cast<unsigned char>(eWeldingType);
        m_kVertexTransform.setZero4();
        m_ucWeldingPadding = 0;
    }
    virtual ~FUN_00de10b0() throw();

    void setVertex(int i, const hkVector4E48C& kVertexDelta)
    {
        (&m_kVertexA)[i] = kVertexDelta;
    }

    unsigned short m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned char m_ucWeldingPadding;
    hkVector4E48C m_kVertexA;
    hkVector4E48C m_kVertexB;
    hkVector4E48C m_kVertexC;
    hkVector4E48C m_kVertexTransform;
};

class hkpShapeContainerE48C
{
  public:
    virtual ~hkpShapeContainerE48C() throw();
    virtual const hkpShapeE48C* FUN_00e48cb0(unsigned int uiKey, unsigned char* pucBuffer) const = 0;
};

class hkpShapeCollectionE48C : public hkpShapeE48C, public hkpShapeContainerE48C
{
  public:
    virtual ~hkpShapeCollectionE48C() throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct hkpMeshShapeSubpartE48C
{
    const void* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    int m_ucIndexStridingType;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    unsigned int unk20, unk24, unk28, unk2C, unk30;
    int m_iTriangleOffset;
};

class hkpMeshShapeE48C : public hkpShapeCollectionE48C
{
  public:
    virtual ~hkpMeshShapeE48C() throw();
    virtual const hkpShapeE48C* FUN_00e48cb0(unsigned int uiKey, unsigned char* pucBuffer) const;

    unsigned int unk18, unk1C;
    hkVector4E48C m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArrayE48C<hkpMeshShapeSubpartE48C> m_kSubparts;
    hkArrayE48C<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    float m_fSphereRadius;
};

// Builds a FUN_00de10b0 triangle in pucBuffer from subpart 0 vertex data, scaling, and welding info for the given uiKey.
// @f3 0x00a76c20 (community match, verified in this file)
extern unsigned char DAT_00e35ff4;
struct ShapeBaseE48C
{
    void* vptr;
    unsigned short memoryFlags;
    short references;
    unsigned int userData;
    unsigned int type;
    ShapeBaseE48C(unsigned int t) { references = 1; userData = 0; type = t; vptr = &DAT_00e35ff4; }
};
struct ConvexE48C : ShapeBaseE48C
{
    float radius;
    ConvexE48C(unsigned int t, float r) : ShapeBaseE48C(t) { radius = r; }
};
struct TriangleOutE48C : ConvexE48C
{
    unsigned short welding;
    unsigned char weldingType;
    unsigned char padding;
    unsigned int unk18;
    unsigned int unk1c;
    float vertexA[4];
    float vertexB[4];
    float vertexC[4];
    float transform[4];
    TriangleOutE48C(float r, unsigned short w, unsigned int wt) : ConvexE48C(4, r)
    {
        welding = w; weldingType = (unsigned char)wt;
        for (int k = 3; k >= 0; k--) transform[k] = 0.0f;
        padding = 0;
    }
};
// pdb: hkpFastMeshShape::getChildShape | hkpFastMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: key, buffer
const hkpShapeE48C* hkpMeshShapeE48C::FUN_00e48cb0(unsigned int uiKey, unsigned char* pucBuffer) const
{
    const hkpMeshShapeSubpartE48C* sub = m_kSubparts.m_data;
    const unsigned char* tri = (const unsigned char*)sub->m_pMaterialDataBase + sub->m_iMaterialStriding * uiKey;
    unsigned int odd = sub->m_bFlipAlternateTriangles & uiKey;
    unsigned int i0 = *(const unsigned short*)tri;
    unsigned int i1 = *(const unsigned short*)(tri + 2 + 2 * odd);
    unsigned int i2 = *(const unsigned short*)(tri + 2 + 2 * (odd ^ 1));
    const float* v0 = (const float*)((const char*)sub->m_pMaterialIndexBase + i0 * sub->m_iTriangleIndexStride);
    const float* v1 = (const float*)((const char*)sub->m_pMaterialIndexBase + i1 * sub->m_iTriangleIndexStride);
    const float* v2 = (const float*)((const char*)sub->m_pMaterialIndexBase + i2 * sub->m_iTriangleIndexStride);
    unsigned short welding;
    if (m_kWeldingInfo.m_iElementCount == 0)
        welding = 0;
    else
        welding = m_kWeldingInfo.m_data[sub->m_iTriangleOffset + uiKey];
    const float* scale = m_kScaling.m_vComponents.m128_f32;
    const float* a0 = v0;
    TriangleOutE48C* out = pucBuffer ? new (pucBuffer) TriangleOutE48C(m_fSphereRadius, welding, m_eWeldingType) : 0;
    const float* a1 = v0 + 1;
    const float* a2 = v0 + 2;
    const float* a3 = v0 + 3;
    const float* b1 = v1 + 1;
    const float* b2 = v1 + 2;
    const float* b3 = v1 + 3;
    const float* c1 = v2 + 1;
    const float* c2 = v2 + 2;
    const float* c3 = v2 + 3;
    out->vertexA[0] = ((const volatile float*)scale)[0]**a0; out->vertexA[1] = ((const volatile float*)scale)[1]**a1; out->vertexA[2] = ((const volatile float*)scale)[2]**a2; out->vertexA[3] = ((const volatile float*)scale)[3]**a3;
    out->vertexB[0] = ((const volatile float*)scale)[0]*v1[0]; out->vertexB[1] = ((const volatile float*)scale)[1]**b1; out->vertexB[2] = ((const volatile float*)scale)[2]**b2; out->vertexB[3] = ((const volatile float*)scale)[3]**b3;
    out->vertexC[0] = ((const volatile float*)scale)[0]*v2[0]; out->vertexC[1] = ((const volatile float*)scale)[1]**c1; out->vertexC[2] = ((const volatile float*)scale)[2]**c2; out->vertexC[3] = ((const volatile float*)scale)[3]**c3;
    return (const hkpShapeE48C*)out;
}

