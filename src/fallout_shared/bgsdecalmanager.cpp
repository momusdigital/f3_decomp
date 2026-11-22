// fallout_shared/bgsdecalmanager.cpp: BGSDecalManager, BSA_, PD_, M3_ and more (3 functions)
#include "f3_common.h"
#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"

// @fnv 0x004a0030
void BGSDecalManager::RenderDecals()
{
    if (reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&m_kSimpleDecalList)->GetSize() > 0)
    {
        FUN_0043c4b0()->StartScene();
        struct IteratorState
        {
            unsigned int previous;
            unsigned int position;
        } iterator;
        iterator.position = reinterpret_cast<unsigned int>(static_cast<BSFaceGenAnimationData*>(
            *reinterpret_cast<NiPointer<BSFaceGenAnimationData>*>(&m_kSimpleDecalList)));
        while (iterator.position != 0)
        {
            iterator.previous = iterator.position;
            BSTempEffectSimpleDecal* decal = reinterpret_cast<BSTempEffectSimpleDecal*>(
                static_cast<BSFaceGenAnimationData*>(reinterpret_cast<NiPointer<BSFaceGenAnimationData>&>(
                    reinterpret_cast<NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)
                        ->GetNext(reinterpret_cast<void*&>(iterator.position)))));
            if (decal != 0)
            {
                if (decal->m_bNeedsManagerUpdate)
                {
                    RemoveDecal(decal);
                    decal->m_bNeedsManagerUpdate = false;
                }

                if (decal->m_pRenderQuery != 0)
                {
                    if (decal->ReleaseTextureObject())
                    {
                        if (decal->m_uiTextureReferenceCount > 0)
                        {
                            if (*DAT_011c5904.GetLifeStateControlFlag())
                                Warning(DAT_0101e1c8, decal->FUN_004a0330()->GetLinkToList()->FUN_0043b1b0());
                            reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                        }
                        else
                        {
                            if (*DAT_011c5904.GetLifeStateControlFlag())
                                Warning(DAT_0101e19c, decal->FUN_004a0330()->GetLinkToList()->FUN_0043b1b0());
                            decal->bWasPlaying = true;
                        }
                    }
                }
                else
                {
                    reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                }

                if (decal->m_bTextureDirty && !decal->bWasPlaying)
                    decal->CreateDecalTexture();

                if (decal->bWasPlaying)
                {
                    if (decal->GetByteAt2D())
                    {
                        ++DAT_011c57ec;
                        if (*DAT_011c5904.GetLifeStateControlFlag())
                            Warning(DAT_0101e174, DAT_011c57ec, decal->FUN_004a0330()->GetLinkToList()->FUN_0043b1b0());

                        if (DAT_011c57f4 & 1)
                        {
                            ImageSpaceEffectParam color(0.0f, 1.0f, 0.0f, 1.0f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            ImageSpaceEffectParam color(0.0f, 1.0f, 0.0f, 0.25f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), false);
                        }
                    }
                    else if (DAT_011c57f4 & 0x10)
                    {
                        if (DAT_011c57f4 & 1)
                        {
                            ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 1.0f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 0.25f);
                            decal->SetDecalTint(reinterpret_cast<RgbaColor&>(color), false);
                        }
                    }
                    reinterpret_cast<NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)
                        ->RemovePos(reinterpret_cast<void*&>(iterator.previous));
                }
            }
        }
        FUN_0043c4b0()->FinishScene();
    }
}

struct NiStream;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];

class Date
{
  public:
    ~Date();
};

namespace fnv_004a03c0 {
struct RecursiveLock
{
    void Leave();
};
struct Date
{
    ~Date();
};
}  // namespace fnv_004a03c0

template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer<NiNode>& operator=(NiNode*);
};

struct Fake_FUN_004a2020
{
    char pad[0x20];
    unsigned int ulFlags[2];
    bool GetFlag(unsigned int aiFlag) const;
};

static bool (Fake_FUN_004a2020::*pfn_FUN_004a2020)(unsigned int) const = &Fake_FUN_004a2020::GetFlag;

// Tests whether the bit for aiFlag is set in the ulFlags bit array, indexing by aiFlag>>5 and masking with 1<<(aiFlag%32).
// @fnv 0x004a2020
bool Fake_FUN_004a2020::GetFlag(unsigned int aiFlag) const
{
    unsigned int uiindex = aiFlag >> 5;
    unsigned int uibit = aiFlag % 32;
    unsigned int uimask = 1 << uibit;
    return (ulFlags[uiindex] & uimask) > 0;
}

struct __declspec(align(16)) VectorComponentValue
{
    char pad[16];
    float FUN_004586d0(void) const;
};

struct hkVector4
{
    VectorComponentValue& FUN_00458700(VectorComponentValue&, int) const;
};

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];

namespace fnv_004a3a20 {
struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];

}  // namespace fnv_004a3a20

class TESObjectREFR
{
  public:
    unsigned int GetFlags();
};

namespace fnv_004a3da0 {
struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];

struct __declspec(align(16)) hkVector4
{
    char m_vComponents[16];
    void _ref_006815c0();
};

}  // namespace fnv_004a3da0

void* FUN_00458b20();
struct T_
{
    void FUN_004a3f10(void*);
};

struct Flt
{
    int v;
    operator unsigned int() const;
};
// @f3 0x0043ec40 (community match, verified in this file)
namespace f3m_0043ec40 {

struct Sub168
{
    void Reset();
};

struct Self16c
{
    int* m_pValues;
};

} // namespace f3m_0043ec40

// pdb: TESDataHandler::GetInteriorCellByIndex | TESDataHandler.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: aiIndex
unsigned int __fastcall FUN_004a3f70(char* self, Flt f)
{
    ((f3m_0043ec40::Sub168*)(self + 0x168))->Reset();
    return ((f3m_0043ec40::Self16c*)(self + 0x16c))->m_pValues[*(unsigned int*)&f];
}


struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];

struct NiSourceTexture;
struct ScriptCompiler;
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    static void Release();
    ScriptCompiler* QConsoleCompiler();
    void Init();
    void DoThis(char*);
    bool Idle(int);
    void PrintFormatted(char*, ...);
    void PrintFormatted(char*, char*);
    void ScrollBy(int);
    void ResetOutputState();
    bool GetLastMenuMode();
    int GetConsoleLineSpacing();
    void SetOutputFilename(char*);
    void WriteToOutputFile(char*);
    bool IsOutputFileEnabled();
    bool IsVisible();
    void SetVisible(char);
    void OnEnterMenuMode();
    void OnLeaveMenuMode();
    void DumpTextureList();
    bool ShouldDumpTexture(NiSourceTexture*);
    void* __vecDelDtor(unsigned int);
    ScriptCompiler* m_pScriptCompiler;
    char m_kOutputLines[12];
    char m_kCommandHistory[12];
    int m_iCommandHistoryPosition;
    int m_iScrollPosition;
    int m_iOutputLineCount;
    bool m_bVisible;
    char _pad_29[3];
    int iConsoleLineSpacing;
    int m_iConsoleX;
    int m_iConsoleY;
    char cVisible;
    bool bIsActive;
    bool m_bRecordingBatch;
    char _pad_3b[1];
    int m_iBatchCommandCount;
    char m_aacCommandHistory[2000];
    char m_acOutputFilename[260];
};
typedef char _sizecheck_MenuConsole[sizeof(ConsoleManager) == 2324 ? 1 : -1];

namespace fnv_008cdd90 {
struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];

}  // namespace fnv_008cdd90

struct NiAVObject;
struct NiGeometry;
struct NiNode;

struct GO
{
    GO(int);
};

struct FUN_004a4440
{
    ~FUN_004a4440();
};
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    char pad04[0xc];
};
class FUN_004a3bc0 : public FUN_004a3ae0
{
  public:
    FUN_004a4440 hits;
    virtual ~FUN_004a3bc0();
};

struct GlobalObject_0044f440
{
    float FUN_00450410(void);
};

GlobalObject_0044f440 g_011c77a8;

namespace fnv_004a1a00 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};

GlobalObject_0044f440 g_011c7588;

}  // namespace fnv_004a1a00

extern int DAT_0101e594;

extern int DAT_0101e594;
void __fastcall FUN_004a3b50(void*);

void __fastcall FUN_004a3b50(void* p);

namespace fnv_004a3f90 {
struct T_
{
    void FUN_004a3f10(void*);
    void ForwardToSubObject(void*);
};

}  // namespace fnv_004a3f90

namespace bsrandom_singleton {
struct MersenneTwister
{
    static MersenneTwister* __cdecl GetRandomGenerator(void);
    void __thiscall AddGeometryDecal(void* a, int b, char c);
};
}

void _Deallocate(void*);

void _Deallocate(void*);

namespace fnv_004a3b00 {
void _Deallocate(void*);
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    void* DestroyAndFree(unsigned int);
};
}  // namespace fnv_004a3b00

namespace fnv_004a3b90 {
void __cdecl _Deallocate(void*);
struct FUN_004a3bc0
{
    virtual ~FUN_004a3bc0();
};
}  // namespace fnv_004a3b90

namespace fnv_004a1a50 {
struct bsrandom_singleton
{
    struct MersenneTwister
    {
        static bsrandom_singleton::MersenneTwister* GetRandomGenerator();
    };
};
}  // namespace fnv_004a1a50

namespace fnv_004a0330 {
struct Flt
{
    operator unsigned int() const;
};

}  // namespace fnv_004a0330

struct NiGeometryData
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
};
struct NiGeometry
{
    NiGeometryData* FUN_005495f0();
    void FUN_004a1ff0();
};

namespace fnv_004a2c00 {
struct GO
{
    GO& operator=(void*);
};

}  // namespace fnv_004a2c00

void* __cdecl FUN_00458b20(void);

struct StatefulObject
{
    void FUN_004a2d50();
    bool FUN_004f1540();
    ~StatefulObject();
};

struct DecalEmitterNode
{
    StatefulObject* emitter;
    DecalEmitterNode* next;
};

struct BGSDecalEmitterList
{
    DecalEmitterNode* head;
    DecalEmitterNode* tail;
    unsigned int count;
    DecalEmitterNode* FUN_00559450();
    StatefulObject** FUN_0057cbe0(DecalEmitterNode** cursor);
    void FUN_0049f590(DecalEmitterNode** cursor);
};

namespace CameraPass {
struct Resource
{
    void FUN_004a0dd0();
};
Resource* __stdcall FUN_0043c4b0(void*);
struct Setting
{
    bool* FUN_00408d60();
};
extern Setting DAT_011c5904;
extern unsigned int DAT_011c57f4;
extern float DAT_0101b268, DAT_0101e2bc, DAT_01018f5c;
extern double DAT_01011590, DAT_0101e2c0;
extern char DAT_0101e298, DAT_0101e274, DAT_0101e24c, DAT_0101e1f8;
void FUN_005b5e40(const char*, ...);
}

struct TESForm
{
    unsigned int GetFormType();
};

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* apFrequency);
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* apCounter);

namespace DecalAdd {

struct DecalBoolSetting
{
    unsigned char* FUN_00408d60();
};

extern DecalBoolSetting DAT_011c5904;
extern unsigned int DAT_011c57f0;

int __cdecl FUN_005b5e40(const char* apFormat, ...);

static const char s_szSourceFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSDecalManager.cpp";
static const char s_szSimpleDecal[] = "DECAL: Simple Decal Instantiated";
static const char s_szTiming[] = "AddGeometryDecalRecurse: Ticks: %I64d, Microseconds: %f";
static const char s_szSkinLimit[] = "DECAL: Reached Max Skin Decal Limit! : %d";

}

// 0x004a1a70   /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), bool return.
extern "C" char DAT_011c5874;
extern "C" char DAT_011c7d34[];

int FUN_005b5e40(const char* fmt, ...);

struct XObj
{
    NiPoint3& FUN_004a0d30(NiPoint3& out);
    float FUN_00507b20();
};
struct XItem
{
    XObj* FUN_00559450();
};
struct XList
{
    bool IsEmpty();
    void* FUN_0043b1b0();
    XItem* FUN_006815c0();
    XList* FUN_00726070();
};
struct XObj3D
{
    bool GetFlag(unsigned int flag);
};
struct XNet
{
    XObj3D* GetObject3D();
};
struct XNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    bool FUN_00456610();
    XNet* FUN_0050d100();
    unsigned int FUN_0043b480();
    XNode* GetAt(unsigned int idx);
    unsigned short FUN_004a1ff0();
    XList* GetTESPackageList();
    char pad4[0xac - 4];
    XList* m_ac;
};

struct XRef
{
    char pad00[0x28];
    XNode* m28;
    char pad2c[0x0c];
    float m38;
    float m3c;
    char pad40[8];
    void* m48;
    char pad4c[0x10];
    float m5c;
    char pad60[0x12];
    unsigned char m72;
    char pad73[0x39];
    XList* m_ac;
    NiPoint3 PtOp(const NiPoint3& p) const;
};

struct XDoor;
struct XDoor
{
    XDoor(XObj* p, float f, XRef* r);
    static void* operator new(unsigned int sz);
    static void operator delete(void*, unsigned int);
    char pad0[0x1a];
    unsigned char m1a;
    unsigned char m1b;
    char pad2[0x144 - 0x1c];
};

bool FUN_0043b300(const void* rtti, XNode* obj);
bool FUN_0045bad0(const void* name, XNode* obj);

#include <string.h>
namespace fnv_004a2070 {
struct DObj;
struct DArg;
struct DPtr;
struct DProp;
struct DArray;
struct CStringProvider;
struct DVec
{
    float x, y, z;
    DVec FUN_004a0bd0() const;
};
struct DUpdate
{
    float time;
    bool updateControllers, multithreaded;
    unsigned unk08;
    DUpdate(float, bool, bool);
};
struct DObj
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual DObj* IsSceneNode();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual DObj* IsGeometry();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Virtual8c();
    virtual void Unk24();
    virtual void Unk25();
    virtual DObj* Virtual98(bool);
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2a();
    virtual void Unk2b();
    virtual void Unk2c();
    virtual void Unk2d();
    virtual void Unk2e();
    virtual void Unk2f();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Virtualdc(DObj*, bool);
    CStringProvider* FUN_00413f40();
    bool FUN_00456610();
    DProp* FUN_00a59d30(unsigned);
    void* FUN_004030b0();
    void* FUN_0043fad0();
    DArray* FUN_009611e0();
    unsigned FUN_00453470();
    int FUN_0059e300();
    void AssignGo(DObj*);
    void AssignFixedString(CStringProvider*);
    void FUN_00a59c60(DUpdate&);
};
struct CStringProvider
{
    const char* FUN_0043b1b0();
};
struct DPtr
{
    DObj* ptr;
    DPtr(DObj*);
    ~DPtr();
    DObj* FUN_00559450();
    DPtr& FUN_0066b0d0(DObj*);
};
struct DArray
{
    unsigned FUN_0043b480();
    DObj* FUN_0043b4a0(unsigned);
};
struct DProp
{
};
struct DList
{
    void FUN_00631540(const DPtr&);
};
struct DNode : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    DList* effects;
    unsigned unkb0;
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DNode(DArray*, bool);
};
struct DOneArg
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Virtualdc(DObj*);
    void AssignFixedString(CStringProvider*);
};
struct DSkin : DOneArg
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DSkin(unsigned);
};
struct DEffect : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DEffect(unsigned, float, DArg*, DObj*, DVec, DVec, float, float, unsigned);
};
struct DParentInterface
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Get(unsigned, DPtr&);
};
struct DParent
{
    unsigned unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    DParentInterface interface30;
};
struct DArg
{
    DVec origin, normal;
    unsigned unk18, unk1c, unk20, unk24;
    DObj* object;
    DArray* children;
    DParent* parent;
    int tries;
    float scale;
    unsigned unk3c, unk40;
    float rotation;
    unsigned flags, unk4c;
    DOneArg* skin;
    unsigned unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
struct DSetting
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
    bool* FUN_00408d60();
    float FUN_00450410();
};
extern DSetting DAT_011c5874, DAT_011c5858, DAT_011c589c;
extern int DAT_011c57e8, DAT_011c57f0;
extern unsigned DAT_011f444c, DAT_011c7d34;
bool FUN_0043b300(const void*, DObj*);
bool FUN_0045bad0(const void*, DObj*);
void FUN_005b5e40(const char*, ...);
}  // namespace fnv_004a2070
