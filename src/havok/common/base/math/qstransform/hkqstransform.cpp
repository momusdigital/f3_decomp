#include "f3_common.h"
// src/havok/common/base/math/qstransform/hkqstransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/qstransform/hkqstransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Matrix
{
    float values[12];
    bool* HasFiniteValues(bool* output);
};

// Checks the 12 matrix values (skipping indices 3 and 11) for infinite/NaN exponents and writes the result to output.
// @fnv 0x00ce50e0
// pdb: hkQsTransform::isOk | hkQsTransform.obj | fnv360_0822_retail, objrun_open, low
bool* Matrix::HasFiniteValues(bool* pbFinite)
{
    for (int index = 0; index < 12; ++index)
    {
        if (index != 3 && index != 11)
        {
            union FloatBits
            {
                float value;
                unsigned int bits;
            } valueBits;
            valueBits.value = values[index];
            if ((valueBits.bits & 0x7f800000) == 0x7f800000)
            {
                *pbFinite = false;
                return pbFinite;
            }
        }
    }
    *pbFinite = true;
    return pbFinite;
}

#include <xmmintrin.h>

class CB2FC0Object
{
  public:
    void FUN_00cb2d90(void* snapshot);
};

class FUN_00ce50b0_cls
{
  public:
    void FUN_00ce50b0(CB2FC0Object* target);
};

// @f3 0x00964420 (community match, verified in this file)
// pdb: hkQsTransform::copyToTransformNoScale | hkQsTransform.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: transformOut
void FUN_00ce50b0_cls::FUN_00ce50b0(CB2FC0Object* target)
{
    Matrix* self = (Matrix*)this;
    target->FUN_00cb2d90(&self->values[4]);
    float* dst = (float*)((char*)target + 0x30);
    dst[0] = self->values[0];
    dst[1] = self->values[1];
    dst[2] = self->values[2];
    dst[3] = self->values[3];
}


struct S_00ce5290_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};

struct S_00ce5290_Bool
{
    char m_cBooleanValue;
    S_00ce5290_Bool(bool b)
    {
        m_cBooleanValue = b;
    }
};
