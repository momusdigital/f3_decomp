#ifndef FNV_NIBSPLINEDATA_DECLS_H
#define FNV_NIBSPLINEDATA_DECLS_H
#include "f3_common.h"
#include "NiBSplineBasisData.h"
#include "NiBSplineData.h"
#include "NiMemoryDefines.h"
#include "NiStream.h"

void __cdecl NiCompUtility_DecompressFloatArray(const short*, unsigned int, float, float, float*, unsigned int);

// The degree 3 value evaluation (FNV360_PDB: NiBSplineData::GetCompactedValueDegree3, medium link) on a stand-in.
struct FUN_00a526b0_shell : public NiBSplineData
{
    void CalculateSplineValue(float, float*, unsigned int, NiBSplineBasisData*, unsigned int, float, float);
};
#endif
