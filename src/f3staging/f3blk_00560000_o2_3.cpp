// src/f3staging/f3blk_00560000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0056bf20 (community match, verified in this file)
namespace f3m_0056bf20 {
struct Flag56bf20 { char enabled; Flag56bf20(const Flag56bf20& other); };
class Reporter56bf20 {
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual Flag56bf20 IsEnabled(int id);
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0A();
    virtual void Assert(const char* type, int id, const char* message, const char* file, int line);
    virtual void Error(const char* type, int id, const char* message, const char* file, int line);
    virtual void Warning(const char* type, int id, const char* message, const char* file, int line);
    virtual void Report(const char* type, int id, const char* message, const char* file, int line);
    bool FUN_0056be60(const char* file, int line);
    int HavokError_message(int level, int id, const char* message, const char* file, int line);
};
// pdb: HavokError::message | HavokStream.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int Reporter56bf20::HavokError_message(int level, int id, const char* message, const char* file, int line) {
    if (id == -1) {
        if (!FUN_0056be60(file, line)) {
            return 0;
        }
    } else if (!IsEnabled(id).enabled) {
        return 0;
    }
    switch (level) {
    case 0:
        Report("Report", id, message, file, line);
        return 1;
    case 1:
        Warning("Warning", id, message, file, line);
        return 1;
    case 2:
    case 3:
        Assert("Assert", id, message, file, line);
        return 1;
    default:
        Error("Error", id, message, file, line);
        return 1;
    }
}
}   // namespace f3m_0056bf20

// @f3 0x00578350 (community match, verified in this file)
namespace f3m_00578350 {
// 0x00578350: builds the precipitation geometry (a tri shape with one quad or mesh copy per particle) from a
// particle system: finds the emitter and its birth rate, copies or generates the vertices, places the copies in
// the emitter's volume and attaches the controller that moves them.
namespace f3m_00578350 {

struct Heap
{
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;

void* __cdecl FUN_0089e810(unsigned int size);
int __cdecl FUN_00c04d9a();

extern float DAT_00f5df10;
extern float DAT_0108fce0[512];
extern float DAT_0108f4e0[512];

inline float NiUnitRandom()
{
    return float(FUN_00c04d9a()) / float(32767);
}

inline float NiSymmetricRandom()
{
    return 2.0f * float(FUN_00c04d9a()) / float(32767) - 1.0f;
}

inline void NiFastSinCos(float fAngle, float* pfSin, float* pfCos)
{
    int i = (int)(fAngle * (512.0 / DAT_00f5df10)) & 0x1ff;
    *pfSin = DAT_0108fce0[i];
    *pfCos = DAT_0108f4e0[i];
}

inline float NiMin(float a, float b)
{
    return a < b ? a : b;
}

inline float NiMax(float a, float b)
{
    return a > b ? a : b;
}

inline unsigned short NiMin(unsigned short a, unsigned short b)
{
    return a < b ? a : b;
}

struct NiPoint2
{
    float x, y;
    NiPoint2() {}
    NiPoint2(float fX, float fY)
    {
        x = fX;
        y = fY;
    }
    static void* operator new[](unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct NiPoint3
{
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator+(const NiPoint3& pt) const { return NiPoint3(x + pt.x, y + pt.y, z + pt.z); }
    NiPoint3 operator-() const { return NiPoint3(-x, -y, -z); }
    NiPoint3 operator*(float fScalar) const { return NiPoint3(fScalar * x, fScalar * y, fScalar * z); }
    static void* operator new[](unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

inline NiPoint3 operator*(float fScalar, const NiPoint3& pt)
{
    return NiPoint3(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z);
}

struct NiMatrix3
{
    float m_pEntry[3][3];
    NiMatrix3 Transpose() const
    {
        NiMatrix3 kTranspose;
        for (int iRow = 0; iRow < 3; iRow++)
        {
            for (int iCol = 0; iCol < 3; iCol++)
                kTranspose.m_pEntry[iRow][iCol] = m_pEntry[iCol][iRow];
        }
        return kTranspose;
    }
    NiMatrix3 operator*(const NiMatrix3& mat) const
    {
        NiMatrix3 prd;
        for (int iRow = 0; iRow < 3; iRow++)
        {
            for (int iCol = 0; iCol < 3; iCol++)
            {
                prd.m_pEntry[iRow][iCol] = m_pEntry[iRow][0] * mat.m_pEntry[0][iCol] +
                                           m_pEntry[iRow][1] * mat.m_pEntry[1][iCol] +
                                           m_pEntry[iRow][2] * mat.m_pEntry[2][iCol];
            }
        }
        return prd;
    }
    NiPoint3 operator*(const NiPoint3& pt) const
    {
        return NiPoint3(m_pEntry[0][0] * pt.x + m_pEntry[0][1] * pt.y + m_pEntry[0][2] * pt.z,
                        m_pEntry[1][0] * pt.x + m_pEntry[1][1] * pt.y + m_pEntry[1][2] * pt.z,
                        m_pEntry[2][0] * pt.x + m_pEntry[2][1] * pt.y + m_pEntry[2][2] * pt.z);
    }
};

struct NiTransform
{
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;
    void FUN_00477790(NiTransform& kDest) const
    {
        kDest.m_Rotate = m_Rotate.Transpose();
        kDest.m_fScale = 1.0f / m_fScale;
        kDest.m_Translate = kDest.m_fScale * (kDest.m_Rotate * -m_Translate);
    }
    NiTransform operator*(const NiTransform& xform) const
    {
        NiTransform res;
        res.m_fScale = m_fScale * xform.m_fScale;
        res.m_Rotate = m_Rotate * xform.m_Rotate;
        res.m_Translate = m_Translate + m_fScale * (m_Rotate * xform.m_Translate);
        return res;
    }
    NiPoint3 operator*(const NiPoint3& kPoint) const { return m_Translate + m_fScale * (m_Rotate * kPoint); }
};

struct NiBound
{
    NiPoint3 m_kCenter;
    float m_fRadius;
    const NiPoint3& GetCenter() const { return m_kCenter; }
    float GetRadius() const { return m_fRadius; }
    void SetCenter(const NiPoint3& kCenter) { m_kCenter = kCenter; }
    void SetRadius(float fRadius) { m_fRadius = fRadius; }
    NiBound& operator=(const NiBound& kBound)
    {
        m_kCenter = kBound.m_kCenter;
        m_fRadius = kBound.m_fRadius;
        return *this;
    }
};

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pkBaseRTTI;
    const NiRTTI* GetBaseRTTI() const { return m_pkBaseRTTI; }
};

extern NiRTTI DAT_0116ebe0;
extern NiRTTI DAT_0116ec38;
extern NiRTTI DAT_0116ec30;
extern NiRTTI DAT_0116ec28;
extern NiRTTI DAT_0116ec18;
extern NiRTTI DAT_0108f4d4;
extern NiRTTI DAT_0108f414;
extern NiRTTI DAT_0108f488;
extern NiRTTI DAT_0116ec10;
extern NiRTTI DAT_0116ec08;
extern NiRTTI DAT_0116ec00;
extern NiRTTI DAT_0116ebf8;
extern NiRTTI DAT_0108f4a0;

template <class T> struct NiPointer
{
    T* m_pObject;
    operator T*() const { return m_pObject; }
    T* operator->() const { return m_pObject; }
};

struct NiNode;
struct NiTimeController;
struct NiGeometryData;
struct NiAVObject;
struct NiObject
{
    virtual ~NiObject();
    virtual void v01();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsNode();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual bool Update(float fTime, NiObject* pkInterpTarget, float& fValue);
    virtual void v40();
    virtual void v41();
    virtual void ComputeInitialPositionAndVelocity(NiPoint3& kPosition, NiPoint3& kVelocity);

    bool IsKindOf(const NiRTTI* pkRTTI) const
    {
        const NiRTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->GetBaseRTTI();
        }
        return false;
    }
    bool IsExactKindOf(const NiRTTI* pkRTTI) const { return GetRTTI() == pkRTTI; }
    static bool IsKindOf(const NiRTTI* pkRTTI, const NiObject* pkObject)
    {
        return pkObject && pkObject->IsKindOf(pkRTTI);
    }
    static bool IsExactKindOf(const NiRTTI* pkRTTI, const NiObject* pkObject)
    {
        if (!pkObject)
            return false;
        return pkObject->IsExactKindOf(pkRTTI);
    }
    NiObject* DynamicCast(const NiRTTI* pkRTTI) const { return IsKindOf(pkRTTI) ? (NiObject*)this : 0; }
    static NiObject* FUN_00424d50(const NiRTTI* pkRTTI, const NiObject* pkObject)
    {
        if (!pkObject)
            return 0;
        return pkObject->DynamicCast(pkRTTI);
    }
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
};

template <class T> struct NiTArray
{
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int GetSize() const { return m_usSize; }
    unsigned int GetEffectiveSize() const { return m_usESize; }
    T& GetAt(unsigned short usIndex) const { return m_pBase[usIndex]; }
};

struct NiTListItem
{
    NiTListItem* m_pkNext;
    NiTListItem* m_pkPrev;
    NiPointer<NiObject> m_element;
};

struct NiTList
{
    virtual ~NiTList();
    NiTListItem* m_pkHead;
    NiTListItem* m_pkTail;
    unsigned int m_uiCount;
    unsigned int GetSize() const { return m_uiCount; }
    NiTListItem* GetHeadPos() const { return m_pkHead; }
    const NiPointer<NiObject>& GetNext(NiTListItem*& kPos) const
    {
        const NiPointer<NiObject>& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct NiGeometryData : NiObject
{
    int unk04;
    unsigned short m_usVertices;
    unsigned short unk0a;
    int unk0c;
    NiBound m_kBound;
    NiPoint3* m_pkVertex;
    int unk24;
    int unk28;
    NiPoint2* m_pkTexture;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned int m_uiTriListLength;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    unsigned short GetVertexCount() const { return m_usVertices; }
    NiPoint3* GetVertices() const { return m_pkVertex; }
    NiPoint2* GetTextures() const { return m_pkTexture; }
    unsigned int GetTriListLength() const { return m_uiTriListLength; }
    unsigned short* FUN_006a05c0();
    NiBound& GetBound() { return m_kBound; }
    const NiBound& GetBound() const { return m_kBound; }
    void SetBound(const NiBound& kBound) { m_kBound = kBound; }
    void FUN_00831580(NiObject* pkData);
    NiGeometryData(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, void* pkColor,
                   NiPoint2* pkTexture, unsigned short usNumTextureSets, int eNBTMethod, unsigned short usTriangles,
                   unsigned short* pusTriList, int a, int b);
};

struct NiAVObject : NiObject
{
    int unk04;
    int unk08;
    NiPointer<NiTimeController> m_spControllers;
    int unk10;
    int unk14;
    NiAVObject* m_pkParent;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    NiTransform m_kWorld;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    unsigned short m_usFlags;
    unsigned short unkae;
    int unkb0;
    int unkb4;
    NiPointer<NiGeometryData> m_spModelData;
    NiAVObject* GetParent() const { return m_pkParent; }
    const NiTransform& GetWorldTransform() const { return m_kWorld; }
    NiGeometryData* GetModelData() const { return m_spModelData; }
    NiBound& GetModelBound() const { return m_spModelData->GetBound(); }
    void SetModelBound(const NiBound& kBound) { m_spModelData->SetBound(kBound); }
    int GetMode() const { return m_usFlags & 7; }
    NiObject* FUN_00826590(int iType);
    void FUN_004236f0(NiObject* pkProperty);
    void FUN_00827ac0(int i);
};

struct NiNode : NiAVObject
{
    NiAVObject* FUN_00434470(unsigned int i);
};

struct NiTriShape : NiAVObject
{
    int unkbc;
    int unkc0;
    NiTriShape(NiGeometryData* pkModelData);
};

struct NiParticleSystem : NiAVObject
{
    int unkbc;
    int unkc0;
    NiTList m_kModifierList;
    NiTimeController* GetControllers() const { return m_spControllers; }
    NiObject* GetModifierAt(unsigned int uiIndex)
    {
        if (uiIndex >= m_kModifierList.GetSize())
            return 0;
        NiTListItem* kIter = m_kModifierList.GetHeadPos();
        unsigned int ui = 0;
        while (kIter)
        {
            NiObject* pkModifier = m_kModifierList.GetNext(kIter);
            if (ui++ == uiIndex)
                return pkModifier;
        }
        return 0;
    }
};

struct NiTimeController : NiObject
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NiPointer<NiTimeController> m_spNext;
    int unk34;
    int unk38;
    NiObject* m_pkModifier;
    NiTimeController* GetNext() const { return m_spNext; }
    NiObject* GetModifierPointer() const { return m_pkModifier; }
    NiObject* NiPSysEmitterCtlr_GetBirthRateInterpolator();
};

struct NiPSysModifier : NiObject
{
    int unk04;
    int unk08;
    int unk0c;
    NiAVObject* m_pkTarget;
    int unk14;
    NiAVObject* GetSystemPointer() const { return m_pkTarget; }
};

struct BSPSysModifier18 : NiPSysModifier
{
    float m_fValue;
    float GetValue() const { return m_fValue; }
};

struct NiPSysMeshUpdateModifier : NiPSysModifier
{
    NiTArray<NiPointer<NiAVObject> > m_kMeshes;
    NiAVObject* GetMeshAt(unsigned short usIndex)
    {
        return m_kMeshes.GetSize() > usIndex ? (NiAVObject*)m_kMeshes.GetAt(usIndex) : 0;
    }
};

struct NiPSysEmitter : NiPSysModifier
{
    float m_fSpeed;
    float m_fSpeedVar;
    float m_fDeclination;
    float m_fDeclinationVar;
    float m_fPlanarAngle;
    float m_fPlanarAngleVar;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float m_fInitRadius;
    float m_fRadiusVar;
    float m_fLifeSpan;
    float m_fLifeSpanVar;
    int unk50;
    float GetSpeed() const { return m_fSpeed; }
    float GetSpeedVar() const { return m_fSpeedVar; }
    float GetDeclination() const { return m_fDeclination; }
    float GetDeclinationVar() const { return m_fDeclinationVar; }
    float GetPlanarAngle() const { return m_fPlanarAngle; }
    float GetPlanarAngleVar() const { return m_fPlanarAngleVar; }
    float GetInitialRadius() const { return m_fInitRadius; }
    float GetLifeSpan() const { return m_fLifeSpan; }
};

struct NiPSysVolumeEmitter : NiPSysEmitter
{
    NiAVObject* m_pkEmitterObj;
    NiAVObject* GetEmitterObj() const { return m_pkEmitterObj; }
};

struct NiPSysBoxEmitter : NiPSysVolumeEmitter
{
    float m_fEmitterWidth;
    float m_fEmitterHeight;
    float GetEmitterWidth() const { return m_fEmitterWidth; }
    float GetEmitterHeight() const { return m_fEmitterHeight; }
};

struct NiPSysSphereEmitter : NiPSysVolumeEmitter
{
    float m_fEmitterRadius;
    float GetEmitterRadius() const { return m_fEmitterRadius; }
};

struct NiPSysCylinderEmitter : NiPSysVolumeEmitter
{
    float m_fEmitterRadius;
    float m_fEmitterHeight;
    float GetEmitterRadius() const { return m_fEmitterRadius; }
    float GetEmitterHeight() const { return m_fEmitterHeight; }
};

struct NiPSysMeshEmitter : NiPSysEmitter
{
    NiTArray<NiPointer<NiAVObject> > m_kGeomEmitterArray;
    NiAVObject* GetGeometryEmitter(unsigned short usIndex)
    {
        if (m_kGeomEmitterArray.GetEffectiveSize() > usIndex)
            return m_kGeomEmitterArray.GetAt(usIndex);
        else
            return 0;
    }
};

struct PrecipData : NiObject
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    PrecipData(unsigned short usVertices, int a, int b);
    void FUN_0083d070(unsigned int a);
    bool FUN_0083cf80(unsigned int a, void* p, unsigned int size, bool b);
    bool FUN_0083ca40(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned short n, unsigned int e,
                      unsigned int f);
};

struct PrecipCtrl : NiObject
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int m_iFrames;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    PrecipCtrl(int iCount, float fValue, NiPoint3* pkDir, NiPoint3* pkMin, NiPoint3* pkMax, int iSnow, int iMode);
    void SetFrames(int i) { m_iFrames = i; }
};

void __cdecl FUN_00ade300(NiAVObject* pkObject, int a, int b);

struct Precip
{
    NiTriShape* FUN_00578350(NiParticleSystem* pkPSys, const NiMatrix3& kRotate, unsigned char ucSnow);
};

// pdb: Precipitation::CreateShaderGeometry | Precipitation.obj | fnv360_0822_retail, call_gap, low
// pdb params: apParticleSystem, akWorldTransform, abSnow
NiTriShape* Precip::FUN_00578350(NiParticleSystem* pkPSys, const NiMatrix3& kRotate, unsigned char ucSnow)
{
    NiObject* pkMeshUpdate;
    NiAVObject* pkSource;
    NiPSysEmitter* pkEmitter;
    NiObject* pkSizeMod;
    NiTimeController* pkCtlr;
    NiTriShape* pkShape;
    float fCount;
    fCount = 0.0f;
    pkEmitter = 0;
    pkMeshUpdate = 0;
    pkSizeMod = 0;
    pkSource = 0;
    pkShape = 0;
    pkCtlr = pkPSys->GetControllers();
    while (pkCtlr)
    {
        if (NiObject::IsKindOf(&DAT_0116ebe0, pkCtlr))
        {
            NiTimeController* pkEmitterCtlr = pkCtlr;
            pkEmitter = (NiPSysEmitter*)NiObject::FUN_00424d50(&DAT_0116ec38, pkEmitterCtlr->GetModifierPointer());
            NiObject* pkInterp = pkEmitterCtlr->NiPSysEmitterCtlr_GetBirthRateInterpolator();
            pkInterp->Update(0.0f, 0, fCount);
            fCount = pkEmitter->GetLifeSpan() * fCount;
            break;
        }
        else
        {
            pkCtlr = pkCtlr->GetNext();
        }
    }
    if (pkEmitter)
    {
        float fSinDecl;
        float fPlanar;
        float fDecl;
        float fLife;
        float fSize;
        float fCosPlanar;
        unsigned short usCount;
        unsigned short usVerts;
        usVerts = 0;
        usCount = (unsigned short)fCount;
        fSize = 0.0f;
        NiTransform kXform;
        NiPoint3 kMin;
        NiPoint3 kMax;
        if (NiObject::IsKindOf(&DAT_0116ec30, pkPSys))
        {
            int i;
            NiObject* pkTriData;
            i = 0;
            while (1)
            {
                NiObject* pkModifier = pkPSys->GetModifierAt(i++);
                if (pkModifier == 0)
                {
                    break;
                }
                if (!pkMeshUpdate && NiObject::IsKindOf(&DAT_0116ec18, pkModifier))
                {
                    pkMeshUpdate = pkModifier;
                }
                if (!pkSizeMod && NiObject::IsKindOf(&DAT_0116ec28, pkModifier))
                {
                    pkSizeMod = pkModifier;
                }
            }
            if (pkMeshUpdate)
            {
                NiNode* pkNode = ((NiPSysMeshUpdateModifier*)pkMeshUpdate)->GetMeshAt(0)->IsNode();
                if (pkNode)
                {
                    pkSource = (NiAVObject*)NiObject::FUN_00424d50(&DAT_0108f4d4, pkNode->FUN_00434470(0));
                }
            }
            if (pkSizeMod)
            {
                fSize = ((BSPSysModifier18*)pkSizeMod)->GetValue();
            }
            pkTriData = NiObject::FUN_00424d50(&DAT_0108f414, pkSource);
            if (pkTriData == 0)
            {
                unsigned short* pusTris;
                NiPoint2* pkUVs;
                int iTri;
                NiPoint3* pkSrcVerts;
                unsigned short* pusSrcTris;
                NiPoint3* pkVerts;
                NiObject* pkData;
                NiPoint2* pkSrcUVs;
                NiGeometryData* pkGeomData;
                unsigned short usTris;
                pkData = pkSource->GetModelData();
                pkGeomData = 0;
                pkGeomData = (NiGeometryData*)NiObject::FUN_00424d50(&DAT_0108f488, pkData);
                usVerts = pkGeomData->GetVertexCount();
                usTris = pkGeomData->GetTriListLength();
                pkSrcVerts = pkGeomData->GetVertices();
                pkSrcUVs = pkGeomData->GetTextures();
                pusSrcTris = pkGeomData->FUN_006a05c0();
                usCount = NiMin(usCount, (unsigned short)(0xffff / usVerts));
                pkVerts = new NiPoint3[usVerts * usCount];
                pkUVs = new NiPoint2[usVerts * usCount];
                pusTris = (unsigned short*)FUN_0089e810(usCount * usTris * 2);
                iTri = 0;
                for (int j = 0; j < usCount; j++)
                {
                    int iBase = usVerts * j;
                    for (int k = 0; k < usVerts; k++)
                    {
                        int iVert = iBase + k;
                        pkVerts[iVert] = pkSrcVerts[k];
                        pkUVs[iVert] = pkSrcUVs[k];
                    }
                    for (int m = 0; m < usTris; m++)
                    {
                        pusTris[iTri] = pusSrcTris[m] + iBase;
                        iTri++;
                    }
                }
                pkShape = new NiTriShape(
                    new NiGeometryData(usVerts * usCount, pkVerts, 0, 0, pkUVs, 1, 0, usTris / 3 * usCount, pusTris, 0, 0));
            }
        }
        else
        {
            NiPoint2* pkUVs;
            unsigned short* pusTris;
            int i;
            NiPoint3* pkVerts;
            int iTris;
            int iVerts;
            i = 0;
            while (1)
            {
                NiObject* pkModifier = pkPSys->GetModifierAt(i++);
                if (pkModifier == 0)
                {
                    break;
                }
                if (NiObject::IsKindOf(&DAT_0116ec28, pkModifier))
                {
                    pkSizeMod = pkModifier;
                    break;
                }
            }
            if (pkSizeMod)
            {
                fSize = ((BSPSysModifier18*)pkSizeMod)->GetValue();
            }
            pkSource = pkPSys;
            usVerts = 4;
            usCount = NiMin(usCount, (unsigned short)(0xffff / usVerts));
            iTris = usCount * 2;
            iVerts = usCount * 4;
            pkVerts = new NiPoint3[iVerts];
            pkUVs = new NiPoint2[iVerts];
            pusTris = (unsigned short*)FUN_0089e810(iTris * 3 * 2);
            for (unsigned int q = 0; q < usCount; q++)
            {
                float fRadius;
                int iVert;
                int iIndex;
                fRadius = pkEmitter->GetInitialRadius();
                iVert = q * 4;
                pkVerts[iVert] = fRadius * NiPoint3(-1.0f, 0.0f, -1.0f);
                pkVerts[iVert + 1] = fRadius * NiPoint3(1.0f, 0.0f, -1.0f);
                pkVerts[iVert + 2] = fRadius * NiPoint3(1.0f, 0.0f, 1.0f);
                pkVerts[iVert + 3] = fRadius * NiPoint3(-1.0f, 0.0f, 1.0f);
                pkUVs[iVert] = NiPoint2(0.0f, 1.0f);
                pkUVs[iVert + 1] = NiPoint2(1.0f, 1.0f);
                pkUVs[iVert + 2] = NiPoint2(1.0f, 0.0f);
                pkUVs[iVert + 3] = NiPoint2(0.0f, 0.0f);
                iIndex = q * 6;
                pusTris[iIndex] = iVert;
                pusTris[iIndex + 1] = iVert + 1;
                pusTris[iIndex + 2] = iVert + 2;
                pusTris[iIndex + 3] = iVert + 3;
                pusTris[iIndex + 4] = iVert;
                pusTris[iIndex + 5] = iVert + 2;
            }
            pkShape = new NiTriShape(new NiGeometryData(iVerts, pkVerts, 0, 0, pkUVs, 1, 0, iTris, pusTris, 0, 0));
        }
        if (pkShape == 0)
        {
            return 0;
        }
        float fSpeed;
        float fCosDecl;
        float fSinPlanar;
        fSpeed = pkEmitter->GetSpeed() + pkEmitter->GetSpeedVar() * (NiUnitRandom() - 0.5f);
        fDecl = pkEmitter->GetDeclination() + pkEmitter->GetDeclinationVar() * NiSymmetricRandom();
        fPlanar = pkEmitter->GetPlanarAngle() + pkEmitter->GetPlanarAngleVar() * NiSymmetricRandom();
        NiFastSinCos(fPlanar, &fSinPlanar, &fCosPlanar);
        NiFastSinCos(fDecl, &fSinDecl, &fCosDecl);
        NiPoint3 kDir(fSinDecl * fCosPlanar, fSinDecl * fSinPlanar, fCosDecl);
        NiPoint3 kVelocity = fSpeed * kDir;
        fLife = pkEmitter->GetLifeSpan();
        NiPSysBoxEmitter* pkBox;
        NiPSysMeshEmitter* pkMesh;
        PrecipData* pkExtra;
        NiPSysSphereEmitter* pkSphere;
        NiPoint3* pkPos;
        PrecipCtrl* pkCtrl;
        NiPoint3 kLocal;
        int iMode;
        NiPSysCylinderEmitter* pkCylinder;
        pkBox = 0;
        pkCylinder = 0;
        pkSphere = 0;
        pkMesh = 0;
        if (NiObject::IsKindOf(&DAT_0116ec10, pkEmitter))
        {
            pkBox = (NiPSysBoxEmitter*)NiObject::FUN_00424d50(&DAT_0116ec10, pkEmitter);
            NiTransform kEmitterWorld = pkBox->GetEmitterObj()->GetWorldTransform();
            NiTransform kSystemWorld = pkBox->GetSystemPointer()->GetWorldTransform();
            NiTransform kInverse;
            kSystemWorld.FUN_00477790(kInverse);
            kXform = kInverse * kEmitterWorld;
            kLocal = kXform.m_Rotate * kVelocity;
            kMin = NiPoint3(-(pkBox->GetEmitterWidth() / 2.0), -(pkBox->GetEmitterHeight() / 2.0),
                            NiMin(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
            kMax = NiPoint3(pkBox->GetEmitterWidth() / 2.0, pkBox->GetEmitterHeight() / 2.0,
                            NiMax(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
        }
        else if (NiObject::IsKindOf(&DAT_0116ec08, pkEmitter))
        {
            pkSphere = (NiPSysSphereEmitter*)NiObject::FUN_00424d50(&DAT_0116ec08, pkEmitter);
            NiTransform kEmitterWorld = pkSphere->GetEmitterObj()->GetWorldTransform();
            NiTransform kSystemWorld = pkSphere->GetSystemPointer()->GetWorldTransform();
            NiTransform kInverse;
            kSystemWorld.FUN_00477790(kInverse);
            kXform = kInverse * kEmitterWorld;
            kLocal = kXform.m_Rotate * kVelocity;
            kMin = NiPoint3(-pkSphere->GetEmitterRadius(), -pkSphere->GetEmitterRadius(),
                            NiMin(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
            kMax = NiPoint3(pkSphere->GetEmitterRadius(), pkSphere->GetEmitterRadius(),
                            NiMax(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
        }
        else if (NiObject::IsKindOf(&DAT_0116ec00, pkEmitter))
        {
            pkCylinder = (NiPSysCylinderEmitter*)NiObject::FUN_00424d50(&DAT_0116ec00, pkEmitter);
            NiTransform kEmitterWorld = pkCylinder->GetEmitterObj()->GetWorldTransform();
            NiTransform kSystemWorld = pkCylinder->GetSystemPointer()->GetWorldTransform();
            NiTransform kInverse;
            kSystemWorld.FUN_00477790(kInverse);
            kXform = kInverse * kEmitterWorld;
            kLocal = kXform.m_Rotate * kVelocity;
            kMin = NiPoint3(-pkCylinder->GetEmitterRadius(), -pkCylinder->GetEmitterRadius(),
                            NiMin(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
            kMax = NiPoint3(pkCylinder->GetEmitterRadius(), pkCylinder->GetEmitterRadius(),
                            NiMax(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
        }
        else if (NiObject::IsKindOf(&DAT_0116ebf8, pkEmitter))
        {
            pkMesh = (NiPSysMeshEmitter*)NiObject::FUN_00424d50(&DAT_0116ebf8, pkEmitter);
            NiTransform kMeshWorld = pkMesh->GetGeometryEmitter(0)->GetWorldTransform();
            NiTransform kSystemWorld = pkPSys->GetWorldTransform();
            float fRadius;
            NiTransform kInverse;
            kSystemWorld.FUN_00477790(kInverse);
            kXform = kInverse * kMeshWorld;
            kLocal = kXform.m_Rotate * kVelocity;
            NiBound kBound = pkMesh->GetGeometryEmitter(0)->GetModelData()->GetBound();
            NiPoint3 kCenter = kBound.GetCenter();
            fRadius = kBound.GetRadius();
            kMin = NiPoint3(kCenter.x - fRadius, kCenter.y - fRadius,
                            NiMin(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
            kMax = NiPoint3(kCenter.x + fRadius, kCenter.y + fRadius,
                            NiMax(kXform.m_Translate.z, fLife * kLocal.z + kXform.m_Translate.z));
        }
        else
        {
            delete pkShape;
            return 0;
        }
        int iTotal;
        iTotal = usVerts * usCount;
        pkPos = new NiPoint3[iTotal];
        NiPoint3 kUnused;
        NiPoint3 kTravel = fLife * kLocal;
        for (int p = 0; p < usCount; p++)
        {
            NiPoint3 kPoint;
            if (pkBox)
            {
                kPoint = NiPoint3(pkBox->GetEmitterWidth() * (NiUnitRandom() - 0.5f),
                                  pkBox->GetEmitterHeight() * (NiUnitRandom() - 0.5f), 0.0f);
                kPoint = kXform * kPoint;
                kPoint = kTravel * NiUnitRandom() + kPoint;
            }
            else if (pkCylinder)
            {
                float fCos;
                float fAngle;
                float fSin;
                float fDist;
                fDist = pkCylinder->GetEmitterRadius() * NiUnitRandom();
                fAngle = NiUnitRandom() * DAT_00f5df10;
                fnv_SinCos(fAngle, fSin, fCos);
                kPoint.x = fDist * fCos;
                kPoint.y = fDist * fSin;
                kPoint.z = (NiUnitRandom() - 0.5f) * pkCylinder->GetEmitterHeight();
                kPoint = kXform * kPoint;
                kPoint = kTravel * NiUnitRandom() + kPoint;
            }
            else if (pkSphere)
            {
                float fPhi;
                float fCosPhi;
                float fSinPhi;
                float fCosTheta;
                float fTheta;
                float fSinTheta;
                float fDist;
                fDist = pkSphere->GetEmitterRadius() * NiUnitRandom();
                fTheta = NiUnitRandom() * DAT_00f5df10;
                fPhi = NiUnitRandom() * DAT_00f5df10;
                fnv_SinCos(fTheta, fSinTheta, fCosTheta);
                fnv_SinCos(fPhi, fSinPhi, fCosPhi);
                kPoint.x = fDist * fSinPhi * fCosTheta;
                kPoint.y = fDist * fSinPhi * fSinTheta;
                kPoint.z = fDist * fCosPhi;
                kPoint = kXform * kPoint;
                kPoint = kTravel * NiUnitRandom() + kPoint;
            }
            else
            {
                pkMesh->ComputeInitialPositionAndVelocity(kPoint, kUnused);
                kPoint = kTravel * NiUnitRandom() + kPoint;
            }
            for (int v = 0; v < usVerts; v++)
            {
                pkPos[usVerts * p + v] = kPoint;
            }
        }
        pkExtra = new PrecipData(iTotal, 1, 1);
        pkExtra->FUN_0083d070(1);
        pkExtra->FUN_0083cf80(0, pkPos, iTotal * 0xc, 1);
        delete[] pkPos;
        pkExtra->FUN_0083ca40(0, 0, 0, 3, iTotal, 0xc, 0xc);
        pkShape->GetModelData()->FUN_00831580(pkExtra);
        NiBound kShapeBound = pkShape->GetModelBound();
        kShapeBound.SetRadius((kMax.x - kMin.x) / 2.0);
        kShapeBound.SetCenter(NiPoint3(0.0f, 0.0f, 0.0f));
        pkShape->SetModelBound(kShapeBound);
        iMode = 1;
        if (NiObject::IsExactKindOf(&DAT_0108f4a0, pkPSys->GetParent()))
        {
            NiAVObject* pkParent = pkPSys->GetParent();
            iMode = pkParent->GetMode();
        }
        if (pkSource->FUN_00826590(5))
        {
            pkShape->FUN_004236f0(pkSource->FUN_00826590(5));
        }
        if (pkSource->FUN_00826590(0))
        {
            pkShape->FUN_004236f0(pkSource->FUN_00826590(0));
        }
        pkShape->FUN_00827ac0(3);
        int iSnow;
        iSnow = ucSnow != 0;
        pkCtrl = new PrecipCtrl(usCount, fSize, &kLocal, &kMin, &kMax, iSnow, iMode);
        pkShape->FUN_004236f0(pkCtrl);
        pkCtrl->SetFrames(0x1e);
        FUN_00ade300(pkShape, 0, 0);
        return pkShape;
    }
    return 0;
}
}  // namespace f3m_00578350
}   // namespace f3m_00578350
