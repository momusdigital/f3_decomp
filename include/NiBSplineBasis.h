// NiBSplineBasis: the basis function values of a B-spline of a given degree at the last time evaluated.
// Names: FNV360_PDB (NiBSplineBasis<float,3>: m_iQuantity, m_afValue[4], m_fLastTime, m_iMin, m_iMax).
#ifndef FNV_NIBSPLINEBASIS_H
#define FNV_NIBSPLINEBASIS_H
#include "layout_support.h"
class NiStream;
#pragma pack(push, 4)
template <class TYPE, int DEGREE> class NiBSplineBasis
{
  public:
    int GetQuantity() const
    {
        return m_iQuantity;
    }
    TYPE GetValue(int i) const
    {
        return m_afValue[i];
    }
    void Compute(TYPE fTime, int& iMin, int& iMax) const;
    bool IsEqual(const NiBSplineBasis* pkOther) const;
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);

    int m_iQuantity;              // +0x0
    TYPE m_afValue[DEGREE + 1];   // +0x4
    TYPE m_fLastTime;             // +0x14 (degree 3)
    int m_iMin;                   // +0x18 (degree 3)
    int m_iMax;                   // +0x1C (degree 3)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineBasis<float, 3>) == 0x20);
#endif
