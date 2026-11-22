// src/f3staging/f3blk_00800000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00817a50 (community match, verified in this file)
namespace f3m_00817a50 {
namespace fn_00817a50 {

struct BoxVec3
{
    float x;
    float y;
    float z;

    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
};

struct OrientedBox
{
    BoxVec3 center;
    BoxVec3 axis0;
    BoxVec3 axis1;
    BoxVec3 axis2;
    float m_afExtents[3];
};

static __declspec(noinline) void FUN_00817310(
    const OrientedBox& rkBox,
    int i0,
    int i1,
    int i2,
    BoxVec3& rkPnt,
    const BoxVec3& rkDir,
    const BoxVec3& rkPmE,
    float* pfLParam,
    float& rfSqrDistance)
{
    BoxVec3 kPpE;
    kPpE[i1] = rkPnt[i1] + rkBox.m_afExtents[i1];
    kPpE[i2] = rkPnt[i2] + rkBox.m_afExtents[i2];
    const float component0 = rkDir[i0];
    float fLSqr;
    float fInv;
    float fTmp;
    float fParam;
    float fT;
    float fDelta;

    const float tangent2 = rkDir[i2];
    if (rkDir[i0] * kPpE[i1] >= rkDir[i1] * rkPmE[i0])
    {
        if (rkDir[i0] * kPpE[i2] >= rkDir[i2] * rkPmE[i0])
        {
            rkPnt[i0] = rkBox.m_afExtents[i0];
            fInv = 1.0f / rkDir[i0];
            rkPnt[i1] -= rkDir[i1] * rkPmE[i0] * fInv;
            rkPnt[i2] -= rkDir[i2] * rkPmE[i0] * fInv;
            *pfLParam = -rkPmE[i0] * fInv;
        }
        else
        {
            fLSqr = rkDir[i0] * rkDir[i0] + rkDir[i2] * rkDir[i2];
            fTmp = fLSqr * kPpE[i1] - rkDir[i1] * (component0 * rkPmE[i0] + rkDir[i2] * kPpE[i2]);
            if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i1])
            {
                fT = fTmp / fLSqr;
                fLSqr += rkDir[i1] * rkDir[i1];
                fTmp = kPpE[i1] - fT;
                fDelta = component0 * rkPmE[i0] + rkDir[i1] * fTmp + tangent2 * kPpE[i2];
                fParam = -fDelta / fLSqr;
                rfSqrDistance += rkPmE[i0] * rkPmE[i0] + fTmp * fTmp + kPpE[i2] * kPpE[i2] + fDelta * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = fT - rkBox.m_afExtents[i1];
                rkPnt[i2] = -rkBox.m_afExtents[i2];
            }
            else
            {
                fLSqr += rkDir[i1] * rkDir[i1];
                fDelta = component0 * rkPmE[i0] + rkDir[i1] * rkPmE[i1] + tangent2 * kPpE[i2];
                fParam = -fDelta / fLSqr;
                rfSqrDistance += rkPmE[i0] * rkPmE[i0] + rkPmE[i1] * rkPmE[i1] + kPpE[i2] * kPpE[i2] + fDelta * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = rkBox.m_afExtents[i1];
                rkPnt[i2] = -rkBox.m_afExtents[i2];
            }
        }
    }
    else
    {
        if (component0 * kPpE[i2] >= rkDir[i2] * rkPmE[i0])
        {
            fLSqr = component0 * component0 + rkDir[i1] * rkDir[i1];
            fTmp = fLSqr * kPpE[i2] - rkDir[i2] * (component0 * rkPmE[i0] + rkDir[i1] * kPpE[i1]);
            if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i2])
            {
                fT = fTmp / fLSqr;
                fLSqr += rkDir[i2] * rkDir[i2];
                fTmp = kPpE[i2] - fT;
                fDelta = component0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + tangent2 * fTmp;
                fParam = -fDelta / fLSqr;
                rfSqrDistance += rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + fTmp * fTmp + fDelta * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = -rkBox.m_afExtents[i1];
                rkPnt[i2] = fT - rkBox.m_afExtents[i2];
            }
            else
            {
                fLSqr += rkDir[i2] * rkDir[i2];
                fDelta = component0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + tangent2 * rkPmE[i2];
                fParam = -fDelta / fLSqr;
                rfSqrDistance += rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + rkPmE[i2] * rkPmE[i2] + fDelta * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = -rkBox.m_afExtents[i1];
                rkPnt[i2] = rkBox.m_afExtents[i2];
            }
        }
        else
        {
            fLSqr = component0 * component0 + rkDir[i2] * rkDir[i2];
            fTmp = fLSqr * kPpE[i1] - rkDir[i1] * (component0 * rkPmE[i0] + rkDir[i2] * kPpE[i2]);
            if (fTmp >= 0.0f)
            {
                if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i1])
                {
                    fT = fTmp / fLSqr;
                    fLSqr += rkDir[i1] * rkDir[i1];
                    fTmp = kPpE[i1] - fT;
                    fDelta = component0 * rkPmE[i0] + rkDir[i1] * fTmp + tangent2 * kPpE[i2];
                    fParam = -fDelta / fLSqr;
                    rfSqrDistance += rkPmE[i0] * rkPmE[i0] + fTmp * fTmp + kPpE[i2] * kPpE[i2] + fDelta * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = fT - rkBox.m_afExtents[i1];
                    rkPnt[i2] = -rkBox.m_afExtents[i2];
                }
                else
                {
                    fLSqr += rkDir[i1] * rkDir[i1];
                    fDelta = component0 * rkPmE[i0] + rkDir[i1] * rkPmE[i1] + tangent2 * kPpE[i2];
                    fParam = -fDelta / fLSqr;
                    rfSqrDistance += rkPmE[i0] * rkPmE[i0] + rkPmE[i1] * rkPmE[i1] + kPpE[i2] * kPpE[i2] + fDelta * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = rkBox.m_afExtents[i1];
                    rkPnt[i2] = -rkBox.m_afExtents[i2];
                }
                return;
            }
            fLSqr = component0 * component0 + rkDir[i1] * rkDir[i1];
            fTmp = fLSqr * kPpE[i2] - rkDir[i2] * (component0 * rkPmE[i0] + rkDir[i1] * kPpE[i1]);
            if (fTmp >= 0.0f)
            {
                if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i2])
                {
                    fT = fTmp / fLSqr;
                    fLSqr += rkDir[i2] * rkDir[i2];
                    fTmp = kPpE[i2] - fT;
                    fDelta = component0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + tangent2 * fTmp;
                    fParam = -fDelta / fLSqr;
                    rfSqrDistance += rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + fTmp * fTmp + fDelta * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = -rkBox.m_afExtents[i1];
                    rkPnt[i2] = fT - rkBox.m_afExtents[i2];
                }
                else
                {
                    fLSqr += rkDir[i2] * rkDir[i2];
                    fDelta = component0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + tangent2 * rkPmE[i2];
                    fParam = -fDelta / fLSqr;
                    rfSqrDistance += rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + rkPmE[i2] * rkPmE[i2] + fDelta * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = -rkBox.m_afExtents[i1];
                    rkPnt[i2] = rkBox.m_afExtents[i2];
                }
                return;
            }
            fLSqr += rkDir[i2] * rkDir[i2];
            fDelta = component0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + tangent2 * kPpE[i2];
            fParam = -fDelta / fLSqr;
            rfSqrDistance += rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + kPpE[i2] * kPpE[i2] + fDelta * fParam;
            *pfLParam = fParam;
            rkPnt[i0] = rkBox.m_afExtents[i0];
            rkPnt[i1] = -rkBox.m_afExtents[i1];
            rkPnt[i2] = -rkBox.m_afExtents[i2];
        }
    }
}

// pdb: CaseNoZeros | NiDistSegBox.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
static __declspec(noinline) void FUN_00817a50(
    const OrientedBox& rkBox,
    BoxVec3& rkPnt,
    const BoxVec3& rkDir,
    float* pfLParam,
    float& rfSqrDistance)
{
    BoxVec3 kPmE;
    kPmE.x = rkPnt.x - rkBox.m_afExtents[0];
    kPmE.y = rkPnt.y - rkBox.m_afExtents[1];
    kPmE.z = rkPnt.z - rkBox.m_afExtents[2];

    float fProdDxPy = rkDir.x * kPmE.y;
    float fProdDyPx = rkDir.y * kPmE.x;
    float fProdDzPx;
    float fProdDxPz;
    float fProdDzPy;
    float fProdDyPz;

    if (fProdDyPx >= fProdDxPy)
    {
        fProdDzPx = rkDir.z * kPmE.x;
        fProdDxPz = rkDir.x * kPmE.z;
        if (fProdDzPx >= fProdDxPz)
            FUN_00817310(rkBox, 0, 1, 2, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
        else
            FUN_00817310(rkBox, 2, 0, 1, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
    }
    else
    {
        fProdDzPy = rkDir.z * kPmE.y;
        fProdDyPz = rkDir.y * kPmE.z;
        if (fProdDzPy >= fProdDyPz)
            FUN_00817310(rkBox, 1, 2, 0, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
        else
            FUN_00817310(rkBox, 2, 0, 1, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
    }
}

void DistLin3Box3_CaseNoZeros_Caller(
    const OrientedBox* pkBox,
    BoxVec3* pkPnt,
    const BoxVec3* pkDir,
    float* pfLParam,
    float* pfSqrDistance)
{
    FUN_00817a50(*pkBox, *pkPnt, *pkDir, pfLParam, *pfSqrDistance);
}

}


namespace AlignmentProbe {
struct __declspec(align(16)) A16 { float v[4]; };
float Use(float f) { A16 a; a.v[0]=f; a.v[1]=f; return a.v[0]+a.v[1]; }
}
}   // namespace f3m_00817a50
