#include "f3_common.h"
// src/havok/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dd51f0
// pdb: hkpMoppShapeMediator::getPrimitiveProperties | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable, high
// pdb params: primitiveIn, cid
// pdb: hkpMoppShapeMediator::getPrimitiveProperties | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable, high (was: ReadIntField)
int __stdcall hkpMoppShapeMediator_getPrimitiveProperties(const void* a, int* piValue)
{
    *piValue = *(const int*)((const char*)a + 4);
    return 1;
}

struct FUN_00dd5260_T
{
    int a;
    int b;
    int c;
    int d;
    int e;
};

// Copies the five-int struct pointed to by pSrc into the struct pointed to by pDst.
// @fnv 0x00dd5260
// pdb: hkpMoppShapeMediator::splitPrimitive | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpMoppShapeMediator_splitPrimitive(FUN_00dd5260_T* pSrc, int a1, int a2, int a3, FUN_00dd5260_T* pDst)
{
    *pDst = *pSrc;
}

struct FUN_00dd5210_Interface
{
    virtual void First();
    virtual void Second();
    virtual int GetValue();
    virtual int UseValue(int value);
};

struct FUN_00dd5210_Record
{
    int value;
    int reserved;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00dd5210_Object
{
    int unk00;
    int unk04;
    FUN_00dd5210_Interface* unk08;
    int unk0c;
    void hkpMoppShapeMediator_getPrimitives(FUN_00dd5210_Record* records);
};

// Fills count records with successive values from unk08, starting at GetValue() and advancing via UseValue().
// @fnv 0x00dd5210
// pdb: hkpMoppShapeMediator::getPrimitives | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable, high
// pdb params: primitives
// pdb: hkpMoppShapeMediator::getPrimitives | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable, high (was: FillRecords)
void FUN_00dd5210_Object::hkpMoppShapeMediator_getPrimitives(FUN_00dd5210_Record* records)
{
    int count = unk0c;
    int value = unk08->GetValue();
    if (count > 0)
    {
        do
        {
            records->value = value;
            records->reserved = 0;
            ++records;
            value = unk08->UseValue(value);
            --count;
        } while (count != 0);
    }
}

struct SpawnedSource
{
    virtual void First();
    virtual int Second();
};

struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};

class FUN_00dd52a0_cls : public SpawnedBase
{
  public:
    short unk04;
    unsigned short m_flag06;
    SpawnedSource* m_src08;
    int m_result0c;

    FUN_00dd52a0_cls* InitFromSource(SpawnedSource* src);
};

// Sets m_flag06 to 1, destroys the base, stores src in m_src08, stores src->Second() in m_result0c and returns this.
// @fnv 0x00dd52a0
// pdb: hkpMoppShapeMediator::hkpMoppShapeMediator | hkpMoppShapeMediator.obj | fnv360_0822_retail, uvref, high
// pdb params: shapeArray
FUN_00dd52a0_cls* FUN_00dd52a0_cls::InitFromSource(SpawnedSource* pSource)
{
    m_flag06 = 1;
    this->SpawnedBase::~SpawnedBase();
    m_src08 = pSource;
    m_result0c = pSource->Second();
    return this;
}

struct FnvCpu_FUN_00dd5290_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int value;
    int hkMemoryStreamReader_tell();
};
// @fnv 0x00dd5290
// pdb: hkMemoryStreamReader::tell | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int FnvCpu_FUN_00dd5290_CpuObject::hkMemoryStreamReader_tell()
{
    return value;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c44d0;

typedef float hkReal;
typedef unsigned int hkpShapeKey;

struct __declspec(align(16)) hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
};

struct __declspec(align(16)) hkpShapeBuffer
{
    int m_data[128];
};

struct hkpShape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual hkReal getMaximumProjection(const hkVector4& direction) const;
};

struct hkpShapeContainer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const;
};

struct ProjectionSample
{
    hkpShapeKey m_key;
    int m_unk04;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
    int m_unk10;
};

struct ProjectionShape
{
    int unk00;
    int unk04;
    hkpShapeContainer* m_container;

    void hkpMoppShapeMediator_projectPrimitives(const hkVector4& direction, int unused, ProjectionSample* samples, int numSamples,
                                hkReal* minOut, hkReal* maxOut);
};

// @f3 0x00a54c10 (community match, verified in this file)
// pdb: hkpMoppShapeMediator::projectPrimitives | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable, high
// pdb params: direction, directionIndex, primitives, numPrimitives, absMinOut, absMaxOut
// pdb: hkpMoppShapeMediator::projectPrimitives | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable, high (was: ComputeProjectionRange)
void ProjectionShape::hkpMoppShapeMediator_projectPrimitives(const hkVector4& direction, int unused, ProjectionSample* samples,
                                             int numSamples, hkReal* minOut, hkReal* maxOut)
{
    hkpShapeBuffer buffer;
    hkReal fMinCorner;
    hkReal fMaxCorner;
    hkReal minProj;
    hkReal maxProj;
    {
        hkpShapeKey key = samples[0].m_key;
        const hkpShape* pShape = m_container->GetShapeForKey(key, buffer);
        if (pShape)
        {
            fMaxCorner = pShape->getMaximumProjection(direction);
            hkVector4 negDirection;
            ((float*)&negDirection)[0] = -((const float*)&direction)[0];
            ((float*)&negDirection)[1] = -((const float*)&direction)[1];
            ((float*)&negDirection)[2] = -((const float*)&direction)[2];
            ((float*)&negDirection)[3] = -((const float*)&direction)[3];
            fMinCorner = -pShape->getMaximumProjection(negDirection);
        }
        else
        {
            fMinCorner = 0.0f;
            fMaxCorner = 0.0f;
        }
        samples[0].m_kMinimumCorner = fMinCorner;
        samples[0].m_kMaximumCorner = fMaxCorner;
        maxProj = fMaxCorner;
        minProj = fMinCorner;
    }
    for (int i = 1; i < numSamples; i++)
    {
        hkpShapeKey key = samples[i].m_key;
        const hkpShape* pShape = m_container->GetShapeForKey(key, buffer);
        if (pShape)
        {
            fMaxCorner = pShape->getMaximumProjection(direction);
            hkVector4 negDirection;
            ((float*)&negDirection)[0] = -((const float*)&direction)[0];
            ((float*)&negDirection)[1] = -((const float*)&direction)[1];
            ((float*)&negDirection)[2] = -((const float*)&direction)[2];
            ((float*)&negDirection)[3] = -((const float*)&direction)[3];
            fMinCorner = -pShape->getMaximumProjection(negDirection);
        }
        else
        {
            fMinCorner = 0.0f;
            fMaxCorner = 0.0f;
        }
        samples[i].m_kMinimumCorner = fMinCorner;
        samples[i].m_kMaximumCorner = fMaxCorner;
        if (fMinCorner < minProj)
        {
            minProj = fMinCorner;
        }
        if (fMaxCorner > maxProj)
        {
            maxProj = fMaxCorner;
        }
    }
    *minOut = minProj;
    *maxOut = maxProj;
}

