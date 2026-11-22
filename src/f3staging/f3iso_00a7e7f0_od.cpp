#include <new>
// src/f3staging/f3iso_00a7e7f0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a7e7f0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a7e7f0 (community match, verified in this file)
// ABI byte views select actual named float subobjects; source layout stays four named fields.
// Shared exact draft, with scalar global storage and typed vector view for integration.
#include <math.h>
struct V4 { float x,y,z,w; };
extern V4 DAT_01092a50;
void __cdecl hkpCollideTriangleUtil_calcBarycentricCoordinates(const V4*,const V4*,const V4*,const V4*,float*);

// Simplex (GJK-style) step of the convex distance solver: unk68 holds the simplex vertices, unk60 the matching
// support points of the first shape, unk6c the simplex size.
//
// Built with /O2 (the pack's /Od does not fit the aligned, register-allocated original; see the flag report).
// Several helpers below compute the same value and differ only in the named temporaries they use. Under /O2 the
// x87 load order of the y/x products (and of the interpolation factors) follows the compiler's temporary numbers,
// so each call site uses the variant that reproduces the original's order: a guess at the original helper
// boundaries, not a reconstruction of them.
__forceinline float InverseRoot(float r) {if(r!=0.0f)return 1.0f/(float)sqrt(r);return 0.0f;}
struct Scalar { float value; __forceinline Scalar(float f):value(f) {} __forceinline operator float() const {return value;} };
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    __forceinline Vec4() {}
    __forceinline Vec4& operator=(const Vec4& a) {x=a.x;y=a.y;z=a.z;w=a.w;return *this;}
    __forceinline void SetSub(const Vec4&a,const Vec4&b) {x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
    __forceinline void SetCross(const Vec4&a,const Vec4&b) {x=a.y*b.z-a.z*b.y;y=a.z*b.x-a.x*b.z;z=a.x*b.y-a.y*b.x;w=0.0f;}
    __forceinline void SetMul(const Vec4&a,const float& f) {x=a.x*f;y=a.y*f;z=a.z*f;w=a.w*f;}
    __forceinline void AddMul(const Vec4&a,const float& f) {x=a.x*f+x;y=a.y*f+y;z=a.z*f+z;w=a.w*f+w;}
    __forceinline void SetNeg(const Vec4&a) {x=-a.x;y=-a.y;z=-a.z;w=-a.w;}
    __forceinline float Dot(const Vec4&a) const {return (x*a.x+y*a.y)+z*a.z;}
    __forceinline Scalar Length2() const {return (x*x+y*y)+z*z;}
    __forceinline float LengthSquared() const {return (x*x+y*y)+z*z;}
    __forceinline Scalar LengthSquaredOf() const {const Vec4& v=*this; return (v.x*v.x+v.y*v.y)+v.z*v.z;}
    __forceinline Scalar Length2Copy() const {float sum=(x*x+y*y)+z*z; float result=sum; return result;}
    __forceinline Scalar Length2Copy2() const {float sum=(x*x+y*y)+z*z; float rounded=sum; float result=rounded; return result;}
    __forceinline void Normalize() {float l2=Length2(); float r=InverseRoot(l2);x*=r;y*=r;z*=r;w*=r;}
    __forceinline void NormalizeDirect() {float r=InverseRoot(Length2());x*=r;y*=r;z*=r;w*=r;}
    __forceinline void NormalizeFloat() {float l2=LengthSquared(); float r=InverseRoot(l2);x*=r;y*=r;z*=r;w*=r;}
    __forceinline void SetInterpolate(const Vec4&a,const Vec4&b,const Scalar& t) {const float s=1.0f-t;x=s*a.x+t*b.x;y=s*a.y+t*b.y;z=s*a.z+t*b.z;w=s*a.w+t*b.w;}
    __forceinline float& operator[](int i) {return *reinterpret_cast<float*>(reinterpret_cast<char*>(this)+(i<<2));}
    __forceinline const float& operator[](int i) const {return *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this)+(i<<2));}
};
struct Support {Vec4 c,a,b; int flag;};
struct Result {Vec4 normal,point;float distance;};
extern int DAT_010f3380;
struct Geometry {
    Vec4 unk00,unk10,unk20,unk30;
    float unk40,unk44,unk48,unk4c,unk50;
    void* unk54; void* unk58; int unk5c;
    Vec4* unk60; Vec4* unk64; Vec4* unk68;
    unsigned unk6c;
    void FUN_00a7e0c0(const Vec4*,Support*);
    void FUN_00a7e220(const Support*);
    void FUN_00a7e6e0(const Vec4*,const Vec4*,Support*,float*);
    int FUN_00a7e7f0(Result*,int*);
};
__forceinline void Perpendicular(const Vec4& edge, Vec4& perp) {
    int idx=0, other=1, sel=2;
    float a0=(float)fabs(edge.x), a1=(float)fabs(edge.y), a2=(float)fabs(edge.z);
    if(a1<a0) {other=0; idx=1; a0=a1;}
    if(a2<a0) {sel=idx; idx=2;}
    perp.x=perp.y=perp.z=perp.w=0.0f;
    perp[other]=edge[sel];
    perp[sel]=-edge[other];
}
// pdb: hkpConvexPenetrationUtil::builtTetrahedron | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, objrun, medium
// pdb params: output, gjkStatus
int Geometry::FUN_00a7e7f0(Result* result,int* status) {
    Vec4* point;
    int best=-1;
    Vec4 normal, direction;
    Support support, support2;
    switch(unk6c) {
    case 0: goto stage0;
    case 1: goto stage1;
    case 2: goto stage2;
    case 3: goto stage3;
    case 4: goto stage4;
    default: goto failedDefault;
    }
stage4: {
    Vec4 e1,e2,d;
    e1.SetSub(unk68[0],unk68[1]);
    e2.SetSub(unk68[1],unk68[2]);
    normal.SetCross(e1,e2);
    float len=normal.LengthSquared();
    d.SetSub(unk68[3],unk68[0]);
    float dot=normal.Dot(d);
    float lim=unk50;
    float prod=len*lim;
    if(dot*dot<=prod) {
        if(best<3) {
            unk6c=3;
            goto stage3;
        }
        *status=3;
        return 1;
    }
    *status=0;
    return 0;
}
stage3: {
    Vec4 e1,e2;
    e1.SetSub(unk68[0],unk68[1]);
    e2.SetSub(unk68[1],unk68[2]);
    normal.SetCross(e1,e2);
    float len=normal.LengthSquared();
    if(len==0.0f) {
        int two=2;
        if(best<two) {
            unk6c=two;
            goto stage2;
        }
        goto outLine;
    }
    goto triangleSupport;
}
stage2: {
    Vec4 e;
    e.SetSub(unk68[0],unk68[1]);
    float len=e.LengthSquaredOf();
    if(!(len<=unk50))
        goto lineSupport;
}
    if(best<1) {
        unk6c=1;
        goto stage1;
    }
    *status=3;
    return 1;
stage1: {
    point=unk68;
    float len=point[0].LengthSquared();
    if(!(len<=unk50))
        goto pointSupport;
}
    if(best<0) {
        unk6c=0;
        goto stage0;
    }
    *status=3;
    return 1;
stage0: {
    direction.SetNeg(unk30);
    float lv=unk30.Length2();
    if(lv<=unk50)
        direction=*reinterpret_cast<const Vec4*>(&DAT_010f3380);
    FUN_00a7e0c0(&direction,&support);
    FUN_00a7e220(&support);
    float nextLen=unk68[0].Length2();
    if(nextLen<=unk50)
        goto outPoint;
    best=0;
    goto stage1;
}
pointSupport: {
    point=unk68;
    best=1;
    FUN_00a7e0c0(point,&support);
    Vec4 delta, negative;
    delta.SetSub(support.c,unk68[0]);
    float distance=delta.Length2Copy2();
    negative.SetNeg(*point);
    FUN_00a7e0c0(&negative,&support2);
    Vec4 delta2;
    delta2.SetSub(support2.c,unk68[0]);
    float distance2=delta2.Length2Copy();
    if(distance>=distance2) {
        FUN_00a7e220(&support);
        goto stage2;
    }
    FUN_00a7e220(&support2);
    goto stage2;
}
lineSupport: {
    Vec4 perp, second, scratch;
    scratch.SetSub(unk68[0],unk68[1]);
    best=2;
    Perpendicular(scratch,perp);
    second.SetCross(scratch,perp);
    perp.Normalize();
    second.NormalizeFloat();
    float d1,d2;
    FUN_00a7e6e0(&perp,unk68,&support2,&d1);
    FUN_00a7e6e0(&second,unk68,&support,&d2);
    if(d1>d2) {
        FUN_00a7e220(&support2);
        goto stage3;
    }
    FUN_00a7e220(&support);
    goto stage3;
}
triangleSupport: {
    best=3;
    normal.NormalizeDirect();
    float distance;
    FUN_00a7e6e0(&normal,unk68,&support2,&distance);
    if(distance<unk40)
        goto outTriangle;
    FUN_00a7e220(&support2);
    goto stage4;
}
outPoint: {
    point=unk68;
    float len=(float)sqrt(point[0].Length2Copy2());
    result->distance=len;
    result->normal=direction;
    result->point=support.a;
    *status=0;
    return 1;
}
outLine: {
    result->distance=0.0f;
    Vec4 edge;
    edge.SetSub(unk68[0],unk68[1]);
    Perpendicular(edge,result->normal);
    result->normal.NormalizeDirect();
    Vec4 ab;
    ab.x=(float)fabs(unk68[0].x);
    ab.y=(float)fabs(unk68[0].y);
    ab.z=(float)fabs(unk68[0].z);
    ab.w=0.0f;
    // the original adds the same sum twice (one rounding stored, one kept): two identical sums reproduce it
    float l0=(ab.y+ab.x)+ab.z;
    float l1=(ab.y+ab.x)+ab.z;
    const double eps=1.1920928955078125e-7;
    Scalar t=l0/(l0+l1+eps);
    result->point.SetInterpolate(unk60[0],unk60[1],t);
    *status=0;
    return 1;
}
outTriangle: {
    result->distance=0.0f;
    result->normal=normal;
    float weights[3];
    hkpCollideTriangleUtil_calcBarycentricCoordinates(&DAT_01092a50,reinterpret_cast<const V4*>(unk68),reinterpret_cast<const V4*>(unk68+1),reinterpret_cast<const V4*>(unk68+2),weights);
    Vec4* m=unk60;
    Vec4 tmp;
    tmp.SetMul(m[0],weights[0]);
    tmp.AddMul(m[1],weights[1]);
    tmp.AddMul(m[2],weights[2]);
    result->point=tmp;
    *status=0;
    return 1;
}
failedDefault:
    *status=3;
    return 1;
}
