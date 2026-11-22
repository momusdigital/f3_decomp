// src/f3staging/f3blk_00480000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00494aa0 (community match, verified in this file)
#include <xmmintrin.h>
struct D3DXMATRIX { float _11,_12,_13,_14,_21,_22,_23,_24,_31,_32,_33,_34,_41,_42,_43,_44; };
struct D3DXPLANE { float a,b,c,d; };
struct Big { char _pad[0x980]; D3DXMATRIX matA; D3DXMATRIX matB; };
extern Big* DAT_0116f2f8;
struct S108 { void* p; float x; float y; float z; };
extern S108 DAT_0108f048;
extern "C" D3DXMATRIX* __stdcall D3DXMatrixMultiply(D3DXMATRIX* pOut, const D3DXMATRIX* pM1, const D3DXMATRIX* pM2);
extern "C" D3DXMATRIX* __stdcall D3DXMatrixInverse(D3DXMATRIX* pOut, float* pfDet, const D3DXMATRIX* pM);
extern "C" D3DXMATRIX* __stdcall D3DXMatrixTranspose(D3DXMATRIX* pOut, const D3DXMATRIX* pM);
extern "C" D3DXPLANE* __stdcall D3DXPlaneNormalize(D3DXPLANE* pOut, const D3DXPLANE* pP);
extern "C" D3DXPLANE* __stdcall D3DXPlaneTransform(D3DXPLANE* pOut, const D3DXPLANE* pP, const D3DXMATRIX* pM);
struct Virt55 {
    virtual void __stdcall v0();
    virtual void __stdcall v1();
    virtual void __stdcall v2();
    virtual void __stdcall v3();
    virtual void __stdcall v4();
    virtual void __stdcall v5();
    virtual void __stdcall v6();
    virtual void __stdcall v7();
    virtual void __stdcall v8();
    virtual void __stdcall v9();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual void __stdcall v23();
    virtual void __stdcall v24();
    virtual void __stdcall v25();
    virtual void __stdcall v26();
    virtual void __stdcall v27();
    virtual void __stdcall v28();
    virtual void __stdcall v29();
    virtual void __stdcall v30();
    virtual void __stdcall v31();
    virtual void __stdcall v32();
    virtual void __stdcall v33();
    virtual void __stdcall v34();
    virtual void __stdcall v35();
    virtual void __stdcall v36();
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual void __stdcall v43();
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual void __stdcall v47();
    virtual void __stdcall v48();
    virtual void __stdcall v49();
    virtual void __stdcall v50();
    virtual void __stdcall v51();
    virtual void __stdcall v52();
    virtual void __stdcall v53();
    virtual void __stdcall v54();
    virtual void __stdcall v55(int zero, D3DXPLANE* plane);
};
// pdb: TESWaterSystem::SetClipPlane | TESWater.obj | fnv360_0822_retail, call_gap, low
// pdb params: afData, aiPlane
void __stdcall FUN_00494aa0(float a, float b, float c, float d, int unused)
{
    D3DXMATRIX mat1;
    D3DXMATRIX mat2;
    __m128 tmpRows[4];
    D3DXMATRIX inv;
    D3DXPLANE plane;
    D3DXPLANE outPlane;
    D3DXPLANE copyPlane;
    float temp;
    mat1 = DAT_0116f2f8->matA;
    temp = DAT_0108f048.x * mat1._11 + DAT_0108f048.y * mat1._21 + DAT_0108f048.z * mat1._31;
    mat1._41 = -temp;
    temp = DAT_0108f048.y * mat1._22 + DAT_0108f048.x * mat1._12 + DAT_0108f048.z * mat1._32;
    mat1._42 = -temp;
    temp = DAT_0108f048.y * mat1._23 + DAT_0108f048.x * mat1._13 + DAT_0108f048.z * mat1._33;
    mat1._43 = -temp;
    mat2 = DAT_0116f2f8->matB;
    D3DXMatrixMultiply((D3DXMATRIX*)tmpRows, &mat1, &mat2);
    D3DXMatrixInverse(&inv, 0, (D3DXMATRIX*)tmpRows);
    D3DXMatrixTranspose((D3DXMATRIX*)tmpRows, &inv);
    plane.a = a; plane.b = b; plane.c = c; plane.d = d;
    D3DXPlaneNormalize(&plane, &plane);
    D3DXPlaneTransform(&outPlane, &plane, (D3DXMATRIX*)tmpRows);
    copyPlane.a = outPlane.a; copyPlane.b = outPlane.b; copyPlane.c = outPlane.c; copyPlane.d = outPlane.d;
    Virt55* obj = *(Virt55**)((char*)DAT_0108f048.p + 0x288);
    obj->v55(0, &copyPlane);
}
