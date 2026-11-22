#include <new>
// src/f3staging/f3iso_00893d10_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00893d10 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00893d10 (community match, verified in this file)
#include <math.h>
namespace Light00893d10 {
struct NiPoint3 {float x,y,z;};
struct NiPoint3_ext : NiPoint3 {NiPoint3_ext& FUN_006b1f50(float);};
struct ThreeByThreeMatrix { float m[3][3]; };
struct NiTransform {ThreeByThreeMatrix m_kOrientation; NiPoint3 m_kTranslation; float m_fScale; void FUN_00477790(NiTransform&) const;};
struct LightPlane {NiPoint3 normal;float distance;};
struct NiD3DMatrix4 {float m[4][4];};
struct NiRTTI; struct NiBound {NiPoint3 m_kCenter;float radius;};
struct NiGeometry;struct NiSkinInstance;struct NiSkinPartition {struct Partition;};
struct NiGeometryBufferData;struct NiPropertyState;struct NiDynamicEffectState;
struct StandinLight {
    char prefix[0x68]; NiTransform m_kWorldSpaceTransform;char pad9c; unsigned char m_ucLightType;char pad9e[0x26];
    float m_fDimmer;NiPoint3 m_kAmbient,m_kDiffuse,m_kSpecular;int padec;
    union {
        struct {NiPoint3 m_kWorldLocation,m_kSpotDirection;float m_fOuterAngle,m_fInnerAngle,m_fSpotExponent;};
        struct {char intensityPrefix[0x5c];float m_fConstantAtten,m_fLinearAtten,m_fQuadAtten;};
        struct {int padf0;ThreeByThreeMatrix m_kLightRotate;NiPoint3 m_kWorldDirection;char pad124[0x10];unsigned m_uiSubtype;unsigned char m_bAtten;char pad139[0x13];NiPoint3 m_kPlaneNormal;float m_fDistanceLimit;};
    };
};
extern NiPoint3 DAT_0108ec68;
void* __cdecl FUN_00c00610(void*,int,unsigned);
void __cdecl FUN_00870a80(float*,const ThreeByThreeMatrix&,const NiPoint3&,float);
inline void CopyPointValue(NiPoint3& d,const NiPoint3& s){const volatile unsigned* a=(const volatile unsigned*)&s;unsigned x=a[0],y=a[1],z=a[2];unsigned* b=(unsigned*)&d;b[0]=x;b[1]=y;b[2]=z;}
inline void CopyPoint24(NiPoint3& d,const NiPoint3& s){
    const unsigned* source = reinterpret_cast<const unsigned*>(&s);
    unsigned* dest = reinterpret_cast<unsigned*>(&d);
    unsigned x = source[0];
    unsigned y = source[1];
    unsigned z = source[2];
    dest[2] = z;
    dest[0] = x;
    dest[1] = y;
}

static __declspec(noinline) void FUN_00890940(void* output,const NiD3DMatrix4* src){float* dst=(float*)output;
dst[0]=src->m[0][0];
dst[1]=src->m[0][1];
dst[2]=src->m[0][2];
dst[3]=src->m[0][3];
dst[4]=src->m[1][0];
dst[5]=src->m[1][1];
dst[6]=src->m[1][2];
dst[7]=src->m[1][3];
dst[8]=src->m[2][0];
dst[9]=src->m[2][1];
dst[10]=src->m[2][2];
dst[11]=src->m[2][3];
dst[12]=src->m[3][0];
dst[13]=src->m[3][1];
dst[14]=src->m[3][2];
dst[15]=src->m[3][3];
}

class LightPointOps : public NiPoint3
{
public:
    NiPoint3* FUN_004229a0(NiPoint3*, const NiPoint3&) const;
    void FUN_00468d00();
    float FUN_00475250(const NiPoint3&) const;
};
class LightRotationOps : public ThreeByThreeMatrix
{
public:
    LightRotationOps* FUN_0044af40(LightRotationOps*) const;
    ThreeByThreeMatrix* FUN_00424020(ThreeByThreeMatrix*, const ThreeByThreeMatrix&) const;
    NiPoint3* FUN_004752c0(NiPoint3*, const NiPoint3&) const;
};
class LightTransformOps : public NiTransform
{
public:
    NiPoint3* FUN_004bbdf0(NiPoint3*, const NiPoint3&) const;
    NiTransform* FUN_0056fe20(NiTransform*, const NiTransform&) const;
};
extern "C" void __cdecl FUN_00873cd0(float*, const char*);
extern "C" bool __cdecl FUN_00424d20(const NiRTTI*, void*);
extern const NiRTTI DAT_0108f498;
extern double DAT_00e2b598;
extern double DAT_00de7c28;
extern float DAT_00db886c;
struct LightScratch
{
    LightPlane plane;
    NiD3DMatrix4 matrix;
    NiPoint3 scaledAtten;
    NiD3DMatrix4 identity;
    NiTransform inverse;
    NiTransform lightWorld;
    NiPoint3 modelWorldDirection;
    NiPoint3 modelDirection;
    NiPoint3 modelPosition;
    NiPoint3 distantModelPosition;
    NiPoint3 pointLightDirection;
    NiPoint3 modelLightDirection;
    NiPoint3 pointLightModelDirection;
    ThreeByThreeMatrix modelWorldRotation;
    LightRotationOps inverseEffectRotation;
    ThreeByThreeMatrix modelEffectRotation;
    LightRotationOps inverseWorldRotation;
    LightRotationOps inverseLightRotation;
    NiTransform modelLightWorld;
};
// pdb: NiD3DShaderConstantMap::GetDynamicEffectData | NiD3DShaderConstantMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pvData, uiDataSize, eMapping, pkDynEffect, pkGeometry, pkSkin, pkPartition, pkBuffData, pkState, pkEffects, kWorld, kWorldBound, uiPass
bool __cdecl FUN_00893d10(void* apConstantData, unsigned int uiConstantDataSize, unsigned int uiMapping,
                                   void* pSource, NiGeometry* m_pShaderGeometry, const NiSkinInstance* pSkinInstance,
                                   const NiSkinPartition::Partition* pPartition, NiGeometryBufferData* pBuffData,
                                   const NiPropertyState* pState, const NiDynamicEffectState* apDynamicEffectState,
                                   const NiTransform& kWorld, const NiBound& kWorldBound, unsigned int uiPass)
{
    NiPoint3 point;
    LightScratch work;
    FUN_00c00610(&work.identity, 0, sizeof(work.identity));
    work.identity.m[3][3] = 1.0f;
    work.identity.m[2][2] = 1.0f;
    work.identity.m[1][1] = 1.0f;
    work.identity.m[0][0] = 1.0f;

    StandinLight* apTargetLight = (StandinLight*)pSource;

    switch (uiMapping)
    {
    case 1: {
        float* fData = (float*)apConstantData;
        if (!apTargetLight)
        {
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return false;
        }
        fData[0] = apTargetLight->m_fDimmer;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return true;
    }
    case 2: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            fData[0] = apTargetLight->m_kAmbient.x;
            fData[1] = apTargetLight->m_kAmbient.y;
            fData[2] = apTargetLight->m_kAmbient.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 3: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            fData[0] = apTargetLight->m_kDiffuse.x;
            fData[1] = apTargetLight->m_kDiffuse.y;
            fData[2] = apTargetLight->m_kDiffuse.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 4: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            fData[0] = apTargetLight->m_kSpecular.x;
            fData[1] = apTargetLight->m_kSpecular.y;
            fData[2] = apTargetLight->m_kSpecular.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 5: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            point = apTargetLight->m_kAmbient;
            ((NiPoint3_ext*)&point)->FUN_006b1f50(apTargetLight->m_fDimmer);
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 6: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            point = apTargetLight->m_kDiffuse;
            ((NiPoint3_ext*)&point)->FUN_006b1f50(apTargetLight->m_fDimmer);
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 7: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            point = apTargetLight->m_kSpecular;
            ((NiPoint3_ext*)&point)->FUN_006b1f50(apTargetLight->m_fDimmer);
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 8: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 3)
            {
                point.x = (float)(apTargetLight->m_kWorldLocation.x * DAT_00e2b598);
                point.y = (float)(apTargetLight->m_kWorldLocation.y * DAT_00e2b598);
                point.z = (float)(apTargetLight->m_kWorldLocation.z * DAT_00e2b598);
                fData[0] = point.x;
                fData[1] = point.y;
                fData[2] = point.z;
                fData[3] = 1.0f;
            }
            else
            {
                fData[0] = apTargetLight->m_kWorldSpaceTransform.m_kTranslation.x;
                fData[1] = apTargetLight->m_kWorldSpaceTransform.m_kTranslation.y;
                fData[2] = apTargetLight->m_kWorldSpaceTransform.m_kTranslation.z;
                fData[3] = 1.0f;
            }
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 9: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            kWorld.FUN_00477790(work.lightWorld);
            if (apTargetLight->m_ucLightType == 3)
            {
                point.x = (float)(apTargetLight->m_kWorldLocation.x * DAT_00e2b598);
                point.y = (float)(apTargetLight->m_kWorldLocation.y * DAT_00e2b598);
                point.z = (float)(apTargetLight->m_kWorldLocation.z * DAT_00e2b598);
                {
                    NiPoint3* __restrict r = ((LightTransformOps*)&work.lightWorld)->FUN_004bbdf0(&work.distantModelPosition, point);
                    point = *r;
                }
            }
            else
            {
                CopyPointValue(point,
                               *((LightTransformOps*)&work.lightWorld)->FUN_004bbdf0(&work.modelPosition, apTargetLight->m_kWorldSpaceTransform.m_kTranslation));
            }
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 10: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 2)
            {
                {
                    NiPoint3* __restrict r =
                        ((LightPointOps*)&kWorldBound.m_kCenter)
                            ->FUN_004229a0(&work.pointLightDirection, apTargetLight->m_kWorldSpaceTransform.m_kTranslation);
                    point = *r;
                }
                ((LightPointOps*)&point)->FUN_00468d00();
            }
            else if (apTargetLight->m_ucLightType == 3)
            {
                point = apTargetLight->m_kWorldLocation;
            }
            else
            {
                point = apTargetLight->m_kSpotDirection;
            }
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 11: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 2)
            {
                {
                    NiPoint3* __restrict r =
                        ((LightPointOps*)&kWorldBound.m_kCenter)
                            ->FUN_004229a0(&work.pointLightModelDirection, apTargetLight->m_kWorldSpaceTransform.m_kTranslation);
                    point = *r;
                }
                ((LightPointOps*)&point)->FUN_00468d00();
            }
            else if (apTargetLight->m_ucLightType == 3)
            {
                point = apTargetLight->m_kWorldLocation;
            }
            else
            {
                point = apTargetLight->m_kSpotDirection;
            }
            CopyPointValue(point, *((LightRotationOps*)&kWorld.m_kOrientation)
                                       ->FUN_0044af40(&work.inverseLightRotation)
                                       ->FUN_004752c0(&work.modelLightDirection, point));
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 12: {
        if (apTargetLight)
        {
            work.identity.m[0][3] = work.identity.m[1][3] = work.identity.m[2][3] = 0.0f;
            work.identity.m[3][3] = 1.0f;
            if (apTargetLight->m_ucLightType == 3)
            {
                point.x = (float)(apTargetLight->m_kWorldLocation.x * DAT_00e2b598);
                point.y = (float)(apTargetLight->m_kWorldLocation.y * DAT_00e2b598);
                point.z = (float)(apTargetLight->m_kWorldLocation.z * DAT_00e2b598);
                FUN_00870a80((float*)&work.identity, apTargetLight->m_kWorldSpaceTransform.m_kOrientation, point, apTargetLight->m_kWorldSpaceTransform.m_fScale);
            }
            else
            {
                FUN_00873cd0((float*)&work.identity, (const char*)&apTargetLight->m_kWorldSpaceTransform);
            }
            FUN_00890940(apConstantData, &work.identity);
            return true;
        }
        FUN_00890940(apConstantData, &work.identity);
        return false;
    }
    case 13: {
        if (apTargetLight)
        {
            kWorld.FUN_00477790(work.inverse);
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            if (apTargetLight->m_ucLightType == 3)
            {
                work.lightWorld = apTargetLight->m_kWorldSpaceTransform;
                point.x = (float)(DAT_00e2b598 * apTargetLight->m_kWorldLocation.x);
                point.y = (float)(DAT_00e2b598 * apTargetLight->m_kWorldLocation.y);
                point.z = (float)(DAT_00e2b598 * apTargetLight->m_kWorldLocation.z);
                work.lightWorld.m_kTranslation = point;
                FUN_00873cd0((float*)&work.matrix,
                             (const char*)((LightTransformOps*)&work.inverse)->FUN_0056fe20(&work.modelLightWorld, work.lightWorld));
            }
            else
            {
                FUN_00873cd0((float*)&work.matrix,
                             (const char*)((LightTransformOps*)&work.inverse)->FUN_0056fe20((NiTransform*)&work.identity, apTargetLight->m_kWorldSpaceTransform));
            }
            FUN_00890940(apConstantData, &work.matrix);
            return true;
        }
        FUN_00890940(apConstantData, &work.identity);
        return false;
    }
    case 14: {
        float* fData = (float*)apConstantData;
        float angle;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 4)
            {
                angle = (float)(apTargetLight->m_fInnerAngle * 3.1415927410125732 / DAT_00de7c28);
                angle = (float)cos(angle);
                fData[0] = angle;
                angle = (float)(apTargetLight->m_fOuterAngle * 3.1415927410125732 / DAT_00de7c28);
                angle = (float)cos(angle);
                fData[1] = angle;
                fData[2] = apTargetLight->m_fSpotExponent;
                fData[3] = 0.0f;
            }
            else
            {
                fData[0] = -1.0f;
                fData[1] = -1.0f;
                fData[2] = 0.0f;
                fData[3] = 0.0f;
            }
            return true;
        }
        fData[0] = -1.0f;
        fData[1] = -1.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 15: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (FUN_00424d20(&DAT_0108f498, apTargetLight))
            {
                fData[0] = apTargetLight->m_kWorldLocation.x;
                fData[1] = apTargetLight->m_kWorldLocation.y;
                fData[2] = apTargetLight->m_kWorldLocation.z;
                fData[3] = 0.0f;
            }
            else
            {
                fData[0] = 1.0f;
                fData[1] = 0.0f;
                fData[2] = 0.0f;
                fData[3] = 0.0f;
            }
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 16: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            FUN_00870a80((float*)&work.matrix, apTargetLight->m_kLightRotate, DAT_0108ec68, 1.0f);
            FUN_00890940(apConstantData, &work.matrix);
            return true;
        }
        FUN_00890940(apConstantData, &work.identity);
        return false;
    }
    case 17: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            FUN_00870a80((float*)&work.matrix,
                         *((LightRotationOps*)&kWorld.m_kOrientation)
                              ->FUN_0044af40(&work.inverseEffectRotation)
                              ->FUN_00424020(&work.modelEffectRotation, apTargetLight->m_kLightRotate),
                         DAT_0108ec68, 1.0f);
            FUN_00890940(apConstantData, &work.matrix);
            return true;
        }
        FUN_00890940(apConstantData, &work.identity);
        return false;
    }
    case 18: {
        float* fData = (float*)apConstantData;
        if (!apTargetLight)
        {
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 1.0f;
            return false;
        }
        fData[0] = apTargetLight->m_kWorldDirection.x;
        fData[1] = apTargetLight->m_kWorldDirection.y;
        fData[2] = apTargetLight->m_kWorldDirection.z;
        fData[3] = 1.0f;
        return true;
    }
    case 19: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            kWorld.FUN_00477790(work.inverse);
            point = apTargetLight->m_kWorldDirection;
            {
                NiPoint3* __restrict r = ((LightTransformOps*)&work.inverse)->FUN_004bbdf0(&work.modelDirection, point);
                point = *r;
            }
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 20: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_bAtten)
            {
                fData[0] = apTargetLight->m_fConstantAtten;
                fData[1] = apTargetLight->m_fLinearAtten;
                fData[2] = apTargetLight->m_fQuadAtten;
                fData[3] = apTargetLight->m_fDistanceLimit;
                return true;
            }
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 21: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_bAtten)
            {
                kWorld.FUN_00477790(work.inverse);

                work.plane = *(LightPlane*)&apTargetLight->m_kPlaneNormal;
                ((LightRotationOps*)&work.inverse.m_kOrientation)->FUN_004752c0(&point, work.plane.normal);
                work.scaledAtten.x = work.plane.normal.x * work.plane.distance;
                work.scaledAtten.y = work.plane.normal.y * work.plane.distance;
                work.scaledAtten.z = work.plane.normal.z * work.plane.distance;
                ((LightTransformOps*)&work.inverse)->FUN_004bbdf0(&work.plane.normal, work.scaledAtten);
                fData[0] = point.x;
                fData[1] = point.y;
                fData[2] = point.z;
                fData[3] = ((LightPointOps*)&point)->FUN_00475250(work.plane.normal);
                return true;
            }
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 22: {
        float* fData = (float*)apConstantData;
        float subtype;
        if (apTargetLight)
        {
            subtype = 0.0f;
            switch (apTargetLight->m_uiSubtype)
            {
            case 0:
            case 1:
                subtype = 2.0f;
                break;
            case 2:
            case 3:
                subtype = DAT_00db886c;
                break;
            case 4:
                subtype = 1.0f;
                break;
            }
            fData[0] = subtype;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 23: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            FUN_00870a80((float*)&work.matrix, apTargetLight->m_kLightRotate, apTargetLight->m_kWorldDirection, 1.0f);
            FUN_00890940(apConstantData, &work.matrix);
            return true;
        }
        FUN_00890940(apConstantData, &work.identity);
        return false;
    }
    case 24: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            kWorld.FUN_00477790(work.inverse);
            point = apTargetLight->m_kWorldDirection;
            CopyPoint24(point, *((LightTransformOps*)&work.inverse)->FUN_004bbdf0(&work.modelWorldDirection, point));
            FUN_00870a80((float*)&work.matrix,
                         *((LightRotationOps*)&kWorld.m_kOrientation)
                              ->FUN_0044af40(&work.inverseWorldRotation)
                              ->FUN_00424020(&work.modelWorldRotation, apTargetLight->m_kLightRotate),
                         point, 1.0f);
            FUN_00890940(apConstantData, &work.matrix);
            return true;
        }
        FUN_00890940(apConstantData, &work.identity);
        return false;
    }
    default:
        FUN_00c00610(apConstantData, 0, uiConstantDataSize);
        return false;
    }
}

}
