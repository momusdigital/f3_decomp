// src/f3staging/f3blk_00800000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00817d90 (community match, verified in this file)
namespace f3m_00817d90 {
struct AxisValues { float value[3]; };
struct ExtentBox { char pad[0x30]; float extent[3]; };

// pdb: CaseNoZeros | NiDistSegBox.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: Case000)
static __declspec(noinline) void FUN_00817d90(const ExtentBox* box, const AxisValues* direction,
                                              float* pfParam, float* pfSqrDistance,
                                              int axis0, AxisValues* point, int axis1, int axis2)
{
    float dir = direction->value[axis0];
    *pfParam = (box->extent[axis0] - point->value[axis0]) / dir;
    point->value[axis0] = box->extent[axis0];
    float delta;
    if (point->value[axis1] < -box->extent[axis1])
    {
        delta = point->value[axis1];
        delta += box->extent[axis1];
        *pfSqrDistance += delta * delta;
        point->value[axis1] = -box->extent[axis1];
    }
    else if (point->value[axis1] > box->extent[axis1])
    {
        delta = point->value[axis1] - box->extent[axis1];
        *pfSqrDistance += delta * delta;
        point->value[axis1] = box->extent[axis1];
    }
    if (point->value[axis2] < -box->extent[axis2])
    {
        delta = point->value[axis2];
        delta += box->extent[axis2];
        *pfSqrDistance += delta * delta;
        point->value[axis2] = -box->extent[axis2];
        return;
    }
    if (point->value[axis2] > box->extent[axis2])
    {
        delta = point->value[axis2] - box->extent[axis2];
        *pfSqrDistance += delta * delta;
        point->value[axis2] = box->extent[axis2];
    }
}

void caller(AxisValues* point, const ExtentBox* box, const AxisValues* direction, float* pfParam, float* pfSqrDistance, int case_idx)
{
    if (case_idx == 0)
        FUN_00817d90(box, direction, pfParam, pfSqrDistance, 0, point, 1, 2);
    else if (case_idx == 1)
        FUN_00817d90(box, direction, pfParam, pfSqrDistance, 1, point, 0, 2);
    else
        FUN_00817d90(box, direction, pfParam, pfSqrDistance, 2, point, 0, 1);
}
}   // namespace f3m_00817d90

// @f3 0x00817e80 (community match, verified in this file)
extern double DAT_01012060;
namespace f3m_00817e80 {
struct PointArg {struct BoxVec3* p; operator BoxVec3&() const { return *p; }};
struct DirArg {const struct BoxVec3* p;};
struct BoxVec3 {float x,y,z;};
struct OrientedBox {BoxVec3 center,axis0,axis1,axis2; float extent[3];};
struct S00eb50f0_Seg {BoxVec3 origin,dir;};
inline BoxVec3 S00eb50f0_Sub(const BoxVec3& a,const BoxVec3& b) {BoxVec3 r={a.x-b.x,a.y-b.y,a.z-b.z};return r;}
inline float S00eb50f0_Dot(const BoxVec3& a,const BoxVec3& b) {return a.x*b.x+a.y*b.y+a.z*b.z;}
inline float& S00eb50f0_At(BoxVec3& a,int i) {return (&a.x)[i];}
float GetSqrDistanceToOrientedBox(const BoxVec3*,const OrientedBox*,float*,float*,float*);
struct FloatArg {float* p;};
struct FaceBoxArg {const OrientedBox* p;}; struct FacePointArg {BoxVec3* p;}; struct FacePmArg {const BoxVec3* p;};
static __declspec(noinline) void FUN_00817310(int i0,int i1,int i2,FaceBoxArg ba,FacePointArg pa,const BoxVec3& dir,FacePmArg ma,FloatArg ta,FloatArg sa) {
 const OrientedBox& box=*ba.p; BoxVec3& pt=*pa.p; const BoxVec3& pm=*ma.p; float* t=ta.p;float* sq=sa.p;
 const float* d=&dir.x; float* p=&pt.x;
 int axes[3]={i0,i1,i2}; float cuts[6]; int i,j;
 for(i=0;i<3;i++) {int axis=axes[i]; cuts[2*i]=(-box.extent[axis]-p[axis])/d[axis];cuts[2*i+1]=(box.extent[axis]-p[axis])/d[axis];}
 for(i=1;i<6;i++) {float v=cuts[i];j=i;while(j>0 && cuts[j-1]>v){cuts[j]=cuts[j-1];--j;} cuts[j]=v;}
 float best=0,bt=-(&pm.x)[i0]/d[i0]; for(j=0;j<3;j++){float q=p[j]+bt*d[j];if(q<-box.extent[j])q+=box.extent[j];else if(q>box.extent[j])q-=box.extent[j];else q=0;best+=q*q;}
 for(i=0;i<7;i++) {
  float sample=i==0?cuts[0]-1.0f:i==6?cuts[5]+1.0f:(cuts[i-1]+cuts[i])*0.5f;
  float sum=0,den=0;
  for(j=0;j<3;j++){float v=p[j]+sample*d[j];if(v<-box.extent[j]) {sum+=d[j]*(p[j]+box.extent[j]);den+=d[j]*d[j];}else if(v>box.extent[j]){sum+=d[j]*(p[j]-box.extent[j]);den+=d[j]*d[j];}}
  float v=den>0?-sum/den:sample;
  if(i>0 && v<cuts[i-1])v=cuts[i-1];if(i<6 && v>cuts[i])v=cuts[i];
  float value=0;for(j=0;j<3;j++){float q=p[j]+v*d[j];if(q<-box.extent[j])q+=box.extent[j];else if(q>box.extent[j])q-=box.extent[j];else q=0;value+=q*q;}
  if(value<best){best=value;bt=v;}
 }
 *t=bt;*sq=best;
 for(i=0;i<3;i++){p[i]+=bt*d[i];if(p[i]<-box.extent[i])p[i]=-box.extent[i];else if(p[i]>box.extent[i])p[i]=box.extent[i];}
}
static __declspec(noinline) void FUN_00817a50(const OrientedBox& b,BoxVec3& p,DirArg da,FloatArg ta,FloatArg sa) {
 float* t=ta.p; float* sq=sa.p;
 const BoxVec3& d=*da.p;
 BoxVec3 pm={p.x-b.extent[0],p.y-b.extent[1],p.z-b.extent[2]};
 FaceBoxArg ba={&b};FacePointArg pa={&p};FacePmArg ma={&pm};
 if(d.y*pm.x >= d.x*pm.y) {
  if(d.z*pm.x >= d.x*pm.z) FUN_00817310(0,1,2,ba,pa,d,ma,ta,sa);
  else FUN_00817310(2,0,1,ba,pa,d,ma,ta,sa);
 } else {
  if(d.z*pm.y >= d.y*pm.z) FUN_00817310(1,2,0,ba,pa,d,ma,ta,sa);
  else FUN_00817310(2,0,1,ba,pa,d,ma,ta,sa);
 }
}
static __declspec(noinline) void FUN_00817b60(const OrientedBox& b,int i0,int i1,int i2,BoxVec3& pp,const BoxVec3& dd,float* t,float& sq) {
 float* p=&pp.x; const float* d=&dd.x;
 float pm0=p[i0]-b.extent[i0],pm1=p[i1]-b.extent[i1];
 float prod0=d[i1]*pm0,prod1=d[i0]*pm1;
 float delta,inv;
 if(prod0>=prod1) {
  p[i0]=b.extent[i0];
  float plus1=p[i1]+b.extent[i1]; delta=prod0-d[i0]*plus1;
  if(delta>=0) {
   inv=1.0f/(d[i0]*d[i0]+d[i1]*d[i1]); sq+=delta*delta*inv;
   p[i1]=-b.extent[i1]; *t=-(d[i0]*pm0+d[i1]*plus1)*inv;
  } else {inv=1.0f/d[i0];p[i1]-=prod0*inv;*t=-pm0*inv;}
 } else {
  p[i1]=b.extent[i1];
  float plus0=p[i0]+b.extent[i0]; delta=prod1-d[i1]*plus0;
  if(delta>=0) {
   inv=1.0f/(d[i0]*d[i0]+d[i1]*d[i1]); sq+=delta*delta*inv;
   p[i0]=-b.extent[i0]; *t=-(d[i0]*plus0+d[i1]*pm1)*inv;
  } else {inv=1.0f/d[i1];p[i0]-=prod1*inv;*t=-pm1*inv;}
 }
 if(p[i2]<-b.extent[i2]) {delta=p[i2]+b.extent[i2];sq+=delta*delta;p[i2]=-b.extent[i2];}
 else if(p[i2]>b.extent[i2]) {delta=p[i2]-b.extent[i2];sq+=delta*delta;p[i2]=b.extent[i2];}
}
static __declspec(noinline) void FUN_00817210(const OrientedBox* b,BoxVec3* pp,float* sq) {
 float* p=&pp->x; float delta;
 for(int i=0;i<3;i++) {
  if(p[i]<-b->extent[i]) {delta=p[i]+b->extent[i];*sq+=delta*delta;p[i]=-b->extent[i];}
  else if(p[i]>b->extent[i]) {delta=p[i]-b->extent[i];*sq+=delta*delta;p[i]=b->extent[i];}
 }
}

static __declspec(noinline) void FUN_00817d90(const OrientedBox* box, const BoxVec3* direction, float* pfParam, float* pfSqrDistance, int axis0, int axis1, int axis2, BoxVec3* point)
{
    float dir = (&direction->x)[axis0];
    *pfParam = (box->extent[axis0] - (&point->x)[axis0]) / dir;
    (&point->x)[axis0] = box->extent[axis0];
    float delta;
    if ((&point->x)[axis1] < -box->extent[axis1])
    {
        delta = (&point->x)[axis1];
        delta += box->extent[axis1];
        *pfSqrDistance += delta * delta;
        (&point->x)[axis1] = -box->extent[axis1];
    }
    else if ((&point->x)[axis1] > box->extent[axis1])
    {
        delta = (&point->x)[axis1] - box->extent[axis1];
        *pfSqrDistance += delta * delta;
        (&point->x)[axis1] = box->extent[axis1];
    }
    if ((&point->x)[axis2] < -box->extent[axis2])
    {
        delta = (&point->x)[axis2];
        delta += box->extent[axis2];
        *pfSqrDistance += delta * delta;
        (&point->x)[axis2] = -box->extent[axis2];
        return;
    }
    if ((&point->x)[axis2] > box->extent[axis2])
    {
        delta = (&point->x)[axis2] - box->extent[axis2];
        *pfSqrDistance += delta * delta;
        (&point->x)[axis2] = box->extent[axis2];
    }
}

// pdb: NiSqrDistance::Compute | NiDistSegBox.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: kSeg, kBox, fSegParam, fBoxParam0, fBoxParam1, fBoxParam2
float __cdecl FUN_00817e80(const S00eb50f0_Seg* apSegment, const OrientedBox* box, float* pfLParam, float* pfBParam0,
                           float* pfBParam1, float* pfBParam2)
{
    BoxVec3 kDiff = S00eb50f0_Sub(apSegment->origin, box->center);
    BoxVec3 kPnt;
    kPnt.x = S00eb50f0_Dot(box->axis0, kDiff);
    kPnt.y = S00eb50f0_Dot(box->axis1, kDiff);
    kPnt.z = S00eb50f0_Dot(kDiff, box->axis2);
    bool bReflect[3];
    int i;
    float fSqrDistance;
    {
        BoxVec3 kWorldPosition;
        kWorldPosition.x = S00eb50f0_Dot(box->axis0, apSegment->dir);
        kWorldPosition.y = S00eb50f0_Dot(box->axis1, apSegment->dir);
        kWorldPosition.z = S00eb50f0_Dot(box->axis2, apSegment->dir);

        for (i = 0; i < 3; i++)
        {
            if (S00eb50f0_At(kWorldPosition, i) < 0.0f)
            {
                S00eb50f0_At(kPnt, i) = -S00eb50f0_At(kPnt, i);
                S00eb50f0_At(kWorldPosition, i) = -S00eb50f0_At(kWorldPosition, i);
                bReflect[i] = true;
            }
            else
            {
                bReflect[i] = false;
            }
        }

        fSqrDistance = 0.0f;
        *pfLParam = 0.0f;

        if (kWorldPosition.x > 0.0f)
        {
            if (kWorldPosition.y > 0.0f)
            {
                if (kWorldPosition.z > 0.0f)
                {
                    PointArg pa={&kPnt}; DirArg da={&kWorldPosition}; FloatArg ta={pfLParam},sa={&fSqrDistance}; FUN_00817a50(*box, pa, da, ta, sa);
                }
                else
                    FUN_00817b60(*box, 0, 1, 2, kPnt, kWorldPosition, pfLParam, fSqrDistance);
            }
            else
            {
                if (kWorldPosition.z > 0.0f)
                    FUN_00817b60(*box, 0, 2, 1, kPnt, kWorldPosition, pfLParam, fSqrDistance);
                else
                    FUN_00817d90(box, &kWorldPosition, pfLParam, &fSqrDistance, 0, 1, 2, &kPnt);
            }
        }
        else
        {
            if (kWorldPosition.y > 0.0f)
            {
                if (kWorldPosition.z > 0.0f)
                    FUN_00817b60(*box, 1, 2, 0, kPnt, kWorldPosition, pfLParam, fSqrDistance);
                else
                    FUN_00817d90(box, &kWorldPosition, pfLParam, &fSqrDistance, 1, 0, 2, &kPnt);
            }
            else
            {
                if (kWorldPosition.z > 0.0f)
                    FUN_00817d90(box, &kWorldPosition, pfLParam, &fSqrDistance, 2, 0, 1, &kPnt);
                else
                    FUN_00817210(box, &kPnt, &fSqrDistance);
            }
        }
    }

    if (*pfLParam >= DAT_01012060)
    {
        if (*pfLParam <= 1.0f)
        {
            for (i = 0; i < 3; i++)
            {
                if (bReflect[i])
                    S00eb50f0_At(kPnt, i) = -S00eb50f0_At(kPnt, i);
            }
            *pfBParam0 = kPnt.x;
            *pfBParam1 = kPnt.y;
            *pfBParam2 = kPnt.z;
        }
        else
        {
            *pfLParam = 1.0f;
            BoxVec3 kEnd;
            kEnd.x = apSegment->origin.x + apSegment->dir.x;
            kEnd.y = apSegment->origin.y + apSegment->dir.y;
            kEnd.z = apSegment->origin.z + apSegment->dir.z;
            fSqrDistance = GetSqrDistanceToOrientedBox(&kEnd, box, pfBParam0, pfBParam1, pfBParam2);
        }
    }
    else
    {
        *pfLParam = 0.0f;
        fSqrDistance = GetSqrDistanceToOrientedBox(&apSegment->origin, box, pfBParam0, pfBParam1, pfBParam2);
    }
    return fSqrDistance;
}
}   // namespace f3m_00817e80

// @f3 0x0080a1f0 (community match, verified in this file)
namespace Task0893 {
struct Point3 {float x,y,z;};
extern Point3 DAT_00f725bc,DAT_0108ec68,DAT_00f72598,DAT_00f725a4,DAT_00f725b0;
struct Volume {virtual void LoadBinary(void*);};
struct Helper {Volume* FUN_00803570(const Point3&,const Point3&,const Point3&,const Point3&,const Point3&);};
struct Manager {void* FUN_0086b930(unsigned int);};
extern Manager DAT_01090a78;
Volume* FUN_0080a1f0(void* stream) {
 Helper* helper=(Helper*)DAT_01090a78.FUN_0086b930(0x40);
 Volume* volume=helper ? helper->FUN_00803570(DAT_00f725bc,DAT_0108ec68,DAT_00f72598,DAT_00f725a4,DAT_00f725b0):0;
 volume->LoadBinary(stream);
 return volume;
}
}
