// gamebryo2.2/corelibs/nianimation/nibsplinedata.cpp: NiBSplineData, SplData (7 functions)
#include "f3_common.h"
#include "nibsplinedata_decls.h"

// MATCH-PENDING stand-in: the game reads the count through a pointer and computes the byte count after the allocation,
// which neither NiStreamLoadBinary nor a reference helper reproduces.
class BSDBinaryView
{
  public:
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BSDBinaryView*, void*, unsigned int, const unsigned int&, unsigned int);
};
class BSDStreamView
{
  public:
    unsigned char m_opaque000[0x24c];
    BSDBinaryView* m_pUnderlyingStream;
};
struct FUN_00a52870_shell : public NiBSplineData
{
    void LoadBinary(BSDStreamView& stream);
};
// Reads the control point count and compact control point count from the stream, allocating and reading the corresponding float and short arrays.
// @fnv 0x00a52870
// pdb: NiBSplineData::LoadBinary | NiBSplineData.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream
void FUN_00a52870_shell::LoadBinary(BSDStreamView& stream)
{
    ((NiObject*)this)->NiObject::LoadBinary((NiStream&)stream);

    BSDBinaryView* pStream = stream.m_pUnderlyingStream;
    unsigned int* puiControlPointCount = &m_uiControlPointCount;
    pStream->m_uiStreamFlags += pStream->m_pfnRead(pStream, puiControlPointCount, 4, 4, 1);
    if (*puiControlPointCount)
    {
        float* pfControlPoints = (float*)_NiMalloc(*puiControlPointCount * 4);
        unsigned int controlPointBytes = *puiControlPointCount * 4;
        m_pafControlPoints = pfControlPoints;
        pStream = stream.m_pUnderlyingStream;
        pStream->m_uiStreamFlags += pStream->m_pfnRead(pStream, pfControlPoints, controlPointBytes, 4, 1);
    }

    pStream = stream.m_pUnderlyingStream;
    puiControlPointCount = &m_uiCompactControlPointCount;
    pStream->m_uiStreamFlags += pStream->m_pfnRead(pStream, puiControlPointCount, 4, 4, 1);
    if (*puiControlPointCount)
    {
        short* psCompactControlPoints = (short*)_NiMalloc(*puiControlPointCount * 2);
        unsigned int compactControlPointBytes = *puiControlPointCount * 2;
        m_pasCompactControlPoints = psCompactControlPoints;
        pStream = stream.m_pUnderlyingStream;
        pStream->m_uiStreamFlags += pStream->m_pfnRead(pStream, psCompactControlPoints, compactControlPointBytes, 2, 1);
    }
}

// Evaluates the B-spline at the given time using the basis weights and control points, accumulating the weighted result into value.
// @fnv 0x00a526b0
// pdb: NiBSplineData::GetCompactedValueDegree3 | NiBSplineData.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: fTime, afPos, uiDimension, pkBasisData, kControlPointHandle, fOffset, fHalfRange
void FUN_00a526b0_shell::CalculateSplineValue(float time, float* value, unsigned int dimension,
                                         NiBSplineBasisData* basisData, unsigned int handle, float offset,
                                         float halfRange)
{
    NiBSplineBasis<float, 3>& basis = basisData->GetDegree3Basis();
    int iCount, max;
    basis.Compute(time, iCount, max);
    float points[16];
    NiCompUtility_DecompressFloatArray(m_pasCompactControlPoints + dimension * iCount + handle, dimension * 4, offset, halfRange, points,
                 dimension * 4);
    unsigned int index = 0;
    time = basis.m_afValue[0];
    for (unsigned int j = 0; j < dimension; ++j)
        value[j] = points[index++] * time;
    int i = iCount + 1;
    if (i <= max)
    {
        float* pfNextWeight = &basis.m_afValue[i - iCount];
        iCount = max - i + 1;
        do
        {
            time = *pfNextWeight;
            for (unsigned int j = 0; j < dimension; ++j)
                value[j] += points[index++] * time;
            ++pfNextWeight;
        } while (--iCount);
    }
}

extern int DAT_01099e54;
void __cdecl _NiFreeAlias(void*);
void __fastcall FUN_00a5d3d0(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);

// @fnv 0x00a52510
// pdb: NiBSplineData::`scalar deleting destructor' | NiBSplineData.obj | fnv360_0822_retail, objrun, high
void* __fastcall FUN_00a52510(void** pThis, int, unsigned int flags)
{
    *pThis = &DAT_01099e54;
    _NiFreeAlias(pThis[2]);
    _NiFreeAlias(pThis[3]);
    FUN_00a5d3d0(pThis);
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x18);
    }
    return pThis;
}

extern "C" bool __stdcall IsSameAs(NiObject*);

struct NiBSplineData_shell : NiBSplineData
{
    bool FUN_00a51e50(NiObject* pkObject);
};

// @fnv 0x00a51e50
// pdb: NiBSplineData::IsEqual | NiBSplineData.obj | fnv360_0822_retail, objrun_open, low
// F3_EXE: NiBSplineData vtable slot 23 (IsEqual)
// pdb params: pkObject
bool NiBSplineData::IsEqual(NiObject* pkObject)
{
    if (NiObject::IsEqual(pkObject))
    {
        NiBSplineData* pkData = (NiBSplineData*)pkObject;
        if (pkData->m_uiControlPointCount == m_uiControlPointCount &&
            pkData->m_uiCompactControlPointCount == m_uiCompactControlPointCount)
            return true;
    }
    return false;
}

struct NiBSplineBaseStand
{
    void* vtable;
    unsigned int refCount;
    void LoadStream(NiStream& stream);
};

struct NiBSplineBinaryView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(NiBSplineBinaryView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }

    void LoadArray(void* buffer, unsigned int totalBytes, unsigned int elementSize)
    {
        unsigned int size = elementSize;
        absolutePosition += read(this, buffer, totalBytes, &size, 1);
    }
};

struct NiBSplineStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    NiBSplineBinaryView* m_pUnderlyingStream;
};

struct FUN_00a52950_cls : NiBSplineData
{
    void LoadControlPoints(NiStream& stream);
};

// Loads the base spline data, then reads the control point count and its array, followed by the compact control point count and its array.
// @fnv 0x00a52950
// pdb: NiBSplineData::SaveBinary | NiBSplineData.obj | fnv360_0822_retail, objrun, medium
// pdb params: kStream
void FUN_00a52950_cls::LoadControlPoints(NiStream& stream)
{
    reinterpret_cast<NiBSplineBaseStand*>(this)->LoadStream(stream);
    NiBSplineStreamView* pStreamView = reinterpret_cast<NiBSplineStreamView*>(&stream);
    pStreamView->m_pUnderlyingStream->Load(&m_uiControlPointCount);
    if (m_uiControlPointCount != 0)
    {
        void* buf = m_pafControlPoints;
        unsigned int bytes = m_uiControlPointCount * 4;
        pStreamView->m_pUnderlyingStream->LoadArray(buf, bytes, 4);
    }
    pStreamView->m_pUnderlyingStream->Load(&m_uiCompactControlPointCount);
    if (m_uiCompactControlPointCount != 0)
    {
        pStreamView->m_pUnderlyingStream->LoadArray(m_pasCompactControlPoints, m_uiCompactControlPointCount * 2, 2);
    }
}

extern void* g_011f4034;
extern const char str_01099f08[];
extern const char str_01099ee8[];

void* __cdecl FUN_00a7d330(void* pv);
void* __cdecl FUN_00a7d510(const char* pcName, unsigned int uiValue);

struct ArrayArg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int uiNewEnd);
    void FUN_0096ae90(unsigned int uiPos, void* pvData);
};

struct NiBase_stand
{
    void* vtable;
    unsigned int refcount;
    void LoadStream(ArrayArg& kStream);
};

class FUN_00a52a20_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_10;
    unsigned int m_14;
    void LoadFromStream(ArrayArg& kStream);
};

// @fnv 0x00a52a20
// pdb: NiBSplineData::GetViewerStrings | NiBSplineData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pStrings
void FUN_00a52a20_cls::LoadFromStream(ArrayArg& kStream)
{
    reinterpret_cast<NiBase_stand*>(this)->LoadStream(kStream);
    {
        void* p = FUN_00a7d330(g_011f4034);
        unsigned int uiPos = kStream.m_0a;
        if (uiPos >= kStream.m_08)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_0e);
        }
        kStream.FUN_0096ae90(uiPos, &p);
    }
    {
        void* q = FUN_00a7d510(str_01099f08, m_10);
        unsigned int uiPos = kStream.m_0a;
        if (uiPos >= kStream.m_08)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_0e);
        }
        kStream.FUN_0096ae90(uiPos, &q);
    }
    {
        void* r = FUN_00a7d510(str_01099ee8, m_14);
        unsigned int uiPos = kStream.m_0a;
        if (uiPos >= kStream.m_08)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_0e);
        }
        kStream.FUN_0096ae90(uiPos, &r);
    }
}

class SplData : public NiBSplineData
{
  public:
    void FUN_00a52550(float fTime, float* afPos, unsigned int uiDimension, NiBSplineBasisData* pkBasisData,
                      unsigned int uiControlPointOffset);
};

// Evaluates a B-spline at fTime by accumulating weighted control points into afPos using basis weights and uiDimension.
// @fnv 0x00a52550
// pdb: NiBSplineData::GetValueDegree3 | NiBSplineData.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: fTime, afPos, uiDimension, pkBasisData, kControlPointHandle
void SplData::FUN_00a52550(float fTime, float* afPos, unsigned int uiDimension, NiBSplineBasisData* pkBasisData,
                           unsigned int uiControlPointOffset)
{
    NiBSplineBasis<float, 3>& kBasis = pkBasisData->GetDegree3Basis();
    int iMax;
    int& iMin = (int&)fTime;
    kBasis.Compute(fTime, iMin, iMax);

    const int iFirst = iMin;
    const float* pkSource = &m_pafControlPoints[uiControlPointOffset + iFirst * uiDimension];
    float fBasisValue = kBasis.m_afValue[0];
    unsigned int j;
    for (j = 0; j < uiDimension; j++)
        afPos[j] = fBasisValue * (*pkSource++);

    int i = iFirst + 1;
    if (i <= iMax)
    {
        const float* pfW = &kBasis.m_afValue[i - iFirst];
        int& n = iMin;
        n = iMax - i + 1;
        do
        {
            fBasisValue = *pfW;
            for (j = 0; j < uiDimension; j++)
                afPos[j] += fBasisValue * (*pkSource++);
            pfW++;
        } while (--n);
    }
}
