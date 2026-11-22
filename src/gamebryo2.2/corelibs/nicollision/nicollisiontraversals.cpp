#include "f3_common.h"
// src/gamebryo2.2/corelibs/nicollision/nicollisiontraversals.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicollisiontraversals.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_0126fa68;
extern int DAT_0126fa6c;
extern int DAT_0126fa70;
extern int DAT_0126fa74;
extern float DAT_0126fa78;

// Stores f and the three components of p into globals and returns a pointer to DAT_0126fa68.
// @fnv 0x00e9c7d0
// pdb: NiHalfSpaceBV::operator!= | NiHalfSpaceBV.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: NiCollisionConvert::ConvertToSphereBV_Fast)
// pdb params: kABV
int* __cdecl FUN_00e9c7d0(float afValue, int* apComponents)
{
    DAT_0126fa78 = afValue;
    DAT_0126fa6c = apComponents[0];
    DAT_0126fa70 = apComponents[1];
    DAT_0126fa74 = apComponents[2];
    return &DAT_0126fa68;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern int _NiPoint3_ZERO;
struct Obj
{
    int f0;
    int f4;
    int f8;
    int fC;
    float f10;
    Obj* InitFromParams(float, int*);
};
// @fnv 0x00e9c800
// pdb: NiHalfSpaceBV::Clone | NiHalfSpaceBV.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: NiCollisionConvert::ConvertToSphereBV_Safe)
Obj* FUN_00e9c800(float afValue, int* p)
{
    void* pMemory = g_memoryManager.Allocate(20);
    Obj* pObj;
    if (pMemory)
        pObj = ((Obj*)pMemory)->InitFromParams(1.0f, &_NiPoint3_ZERO);
    else
        pObj = 0;
    pObj->f10 = afValue;
    pObj->f4 = p[0];
    pObj->f8 = p[1];
    pObj->fC = p[2];
    return pObj;
}

struct SpawnParam
{
    int m_iType;
    int m_iSub;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

struct ItemOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int* m_pItems;
    unsigned short unkA4;
    unsigned short m_uiItemCount;
    int unkA8;
    int unkAC;
    int m_uiEdgeIndex;
};

bool __cdecl FUN_00e9c490(int a1, int a2, SpawnParam* p, int item);

// @fnv 0x00e9c680
// pdb: NiCollisionTraversals::FindIntersectionsSwitchNode | NiCollisionTraversals.obj | fnv360_0721_beta, caller, medium
// pdb params: kOrigin, kDir, kPick, pkSwitch
bool __cdecl FUN_00e9c680(int a1, int a2, SpawnParam* p, ItemOwner* owner)
{
    bool result = false;
    int idx = owner->m_uiEdgeIndex;
    if (idx < 0)
    {
        goto done;
    }
    if (p->m_iType == 1 && p->m_iSub == 1 && p->unk28 != 0)
    {
        return true;
    }
    if (owner->m_uiEdgeIndex < 0)
    {
        goto done;
    }
    if (idx >= owner->m_uiItemCount)
    {
        goto done;
    }
    {
        int item = owner->m_pItems[idx];
        if (item == 0)
        {
            goto done;
        }
        if (FUN_00e9c490(a1, a2, p, item))
        {
            result = true;
        }
    }
done:
    return result;
}

namespace fnv_00e9c6f0 {
extern int DAT_011f5eb4;

struct ListNode
{
    int unk00;
    ListNode* m_pNext;
};

struct ItemOwner
{
    virtual void v00();
    virtual void v04();
    virtual ListNode* v08();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int* m_pItems;
    unsigned short unkA4;
    unsigned short m_uiItemCount;
};

struct Dispatch
{
    void Run(ItemOwner* owner);
};

struct SpawnParam
{
    int m_iType;
    int m_iSub;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Dispatch m_sub;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

bool __cdecl FUN_00e9c490(int a1, int a2, SpawnParam* p, int item);
bool __cdecl FUN_00e9c680(int a1, int a2, SpawnParam* p, ItemOwner* owner);

// @fnv 0x00e9c6f0
// pdb: NiCollisionTraversals::FindIntersectionsNode | NiCollisionTraversals.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: kOrigin, kDir, kPick, pkNode
bool __cdecl FUN_00e9c6f0(int a1, int a2, SpawnParam* pSpawnParam, ItemOwner* owner)
{
    if (pSpawnParam->unk08 == 0 && pSpawnParam->m_iType == 1)
    {
        pSpawnParam->m_sub.Run(owner);
        return true;
    }

    if (owner != 0)
    {
        ListNode* node = owner->v08();
        if (node != 0)
        {
            do
            {
                if (node == (ListNode*)&DAT_011f5eb4)
                {
                    return FUN_00e9c680(a1, a2, pSpawnParam, owner);
                }
                node = node->m_pNext;
            } while (node != 0);
        }
    }

    bool result = false;
    for (unsigned int i = 0; i < owner->m_uiItemCount; ++i)
    {
        if (pSpawnParam->m_iType == 1 && pSpawnParam->m_iSub == 1 && pSpawnParam->unk28 != 0)
        {
            return true;
        }
        int item = owner->m_pItems[i];
        if (item != 0)
        {
            if (FUN_00e9c490(a1, a2, pSpawnParam, item))
            {
                result = true;
            }
        }
    }
    return result;
}
}  // namespace fnv_00e9c6f0

struct S_00e9c490_Pt
{
    float x, y, z;
    S_00e9c490_Pt FUN_00439ef0(const S_00e9c490_Pt& o) const;
    S_00e9c490_Pt FUN_00439e90(const S_00e9c490_Pt& o) const;
    S_00e9c490_Pt* ApplyScaled(S_00e9c490_Pt* out, float s) const;
    float DotProduct(const S_00e9c490_Pt& o) const;
    float FUN_00457990() const;
};
struct S_00e9c490_Entry
{
    int unk00;
    int unk04;
    S_00e9c490_Pt unk08;
    float unk14;
};
struct S_00e9c490_Pool
{
    int unk00;
    S_00e9c490_Entry* GetTexture(void* node);
};
struct S_00e9c490_Ctx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    short unk12;
    int unk14;
    S_00e9c490_Pool unk18;
};
struct S_00e9c490_Ref
{
    int unk00;
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
    unsigned int unk30;
};
struct S_00e9c490_Node
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00e9c490_Ref* v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
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
    unsigned int unk30;
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    S_00e9c490_Pt unk8c;
};
extern char DAT_0126fa64;
extern char DAT_0126fa65;
extern int DAT_011f4a48;
extern int DAT_011f5f64;
static const float DAT_01011d78 = 0.0f;
bool __cdecl RayIntersectsBound(S_00e9c490_Node* node, S_00e9c490_Pt* p1, S_00e9c490_Pt* p2);
bool __cdecl FUN_00e9c6f0(S_00e9c490_Pt* p1, S_00e9c490_Pt* p2, S_00e9c490_Ctx* ctx, S_00e9c490_Node* node);
namespace fnv_00e9b4f0 { class NiPoint3; struct Options; struct Shape; bool __cdecl RaycastShape(const NiPoint3* rayStart, const NiPoint3* rayDirection, Options* options, Shape* shape); }
bool __cdecl RaycastShape(S_00e9c490_Pt* p1, S_00e9c490_Pt* p2, S_00e9c490_Ctx* ctx, S_00e9c490_Node* node);
bool __cdecl FUN_0043b300(const void* rtti, S_00e9c490_Node* node);

// @fnv 0x00e9c490
// pdb: NiCollisionTraversals::FindIntersections | NiCollisionTraversals.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: kOrigin, kDir, kPick, pkRoot
bool __cdecl FUN_00e9c490(S_00e9c490_Pt* pPoint1, S_00e9c490_Pt* pPoint2, S_00e9c490_Ctx* pContext,
                          S_00e9c490_Node* node)
{
    if (!node)
        return false;
    if (pContext->unk11 && (node->unk30 & 1))
        return false;
    S_00e9c490_Ref* ref = node->v3();
    if (ref && (unsigned char)(ref->unk30 >> 21) & 1)
        return false;
    if (RayIntersectsBound(node, pPoint1, pPoint2) || (ref && (unsigned char)(ref->unk30 >> 13) & 1))
    {
        if (ref)
            return FUN_00e9c6f0(pPoint1, pPoint2, pContext, node);
        if (node->v7())
            return RaycastShape(pPoint1, pPoint2, pContext, node);
        if (DAT_0126fa65 && FUN_0043b300(&DAT_011f4a48, node))
        {
            S_00e9c490_Pt d = node->unk8c.FUN_00439ef0(*pPoint1);
            if (pPoint2->DotProduct(d) < DAT_01011d78)
                return false;
            float len = d.FUN_00457990();
            pContext->unk18.GetTexture(node)->unk14 = len;
            return false;
        }
        if (DAT_0126fa64 && FUN_0043b300(&DAT_011f5f64, node))
        {
            S_00e9c490_Pt d = node->unk8c.FUN_00439ef0(*pPoint1);
            if (pPoint2->DotProduct(d) < DAT_01011d78)
                return false;
            S_00e9c490_Entry* pEntry = pContext->unk18.GetTexture(node);
            float len = d.FUN_00457990();
            pEntry->unk14 = len;
            if (pContext->unk08 == 1)
            {
                pEntry->unk08 = pPoint1->FUN_00439e90(*pPoint2->ApplyScaled(&d, len));
            }
            return false;
        }
    }
    return false;
}

// @fnv 0x00e9c7c0
// pdb: hkStreamReader::tell | hkStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int hkStreamReader_tell()
{
    return -1;
}

#include <math.h>
class NiPoint2
{
  public:
    float x, y;
    NiPoint2 operator*(float f) const
    {
        NiPoint2 r = *this;
        r.x *= f;
        r.y *= f;
        return r;
    }
    NiPoint2 operator+(const NiPoint2& b) const
    {
        NiPoint2 r = *this;
        r.x += b.x;
        r.y += b.y;
        return r;
    }
};
struct P3
{
    float x, y, z;
    P3 operator*(float f) const
    {
        P3 r;
        r.x = x * f;
        r.y = y * f;
        r.z = z * f;
        return r;
    }
    P3 operator+(const P3& b) const
    {
        P3 r;
        r.x = x + b.x;
        r.y = y + b.y;
        r.z = z + b.z;
        return r;
    }
    P3 operator-(const P3& b) const
    {
        P3 r;
        r.x = x - b.x;
        r.y = y - b.y;
        r.z = z - b.z;
        return r;
    }
    P3 Cross(const P3& b) const
    {
        P3 r;
        r.x = y * b.z - z * b.y;
        r.y = z * b.x - x * b.z;
        r.z = x * b.y - y * b.x;
        return r;
    }
    __declspec(noalias) void FUN_004a0c10();
};
P3 operator*(float f, const P3& p)
{
    P3 r;
    r.x = f * p.x;
    r.y = f * p.y;
    r.z = f * p.z;
    return r;
}
struct P4
{
    float r, g, b, a;
    P4() : r(0), g(0), b(0), a(0)
    {}
    P4 operator*(float f) const
    {
        P4 c = *this;
        c.r *= f;
        c.g *= f;
        c.b *= f;
        c.a *= f;
        return c;
    }
    P4 operator+(const P4& d) const
    {
        P4 c = *this;
        c.r += d.r;
        c.g += d.g;
        c.b += d.b;
        c.a += d.a;
        return c;
    }
    P4 AddDelta(const P4&);
};
P4 __cdecl FUN_00532f40(float, const P4&);
extern NiPoint2 DAT_011f4980;
extern P4 DAT_011a9be0;
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    P3 Apply(const P3& p) const
    {
        P3 r;
        r.x = m00 * p.x + (m01 * p.y) + m02 * p.z;
        r.y = (((m10 * p.x) + m11 * p.y) + (p.z * m12));
        r.z = m20 * p.x + m21 * p.y + p.z * m22;
        return r;
    }
    P3 InverseRotatePoint(const P3& p) const
    {
        P3 r;
        r.x = m00 * p.x + p.y * m10 + (m20 * p.z);
        r.y = ((m01 * p.x + p.y * m11) + (m21 * p.z));
        r.z = m02 * p.x + m12 * p.y + (m22 * p.z);
        return r;
    }
    P3 InverseRotateVector(const P3& p) const
    {
        P3 r;
        r.x = m00 * p.x + m10 * p.y + m20 * p.z;
        r.y = p.x * m01 + m11 * p.y + m21 * p.z;
        r.z = (m02 * p.x + m12 * p.y + m22 * p.z);
        return r;
    }
    __declspec(noalias) P3 FUN_004b4500(const P3*);
};
struct Transform
{
    Matrix rotation;
    P3 translation;
    float scale;
};
struct Buffer
{
    char* data;
    unsigned stride;
    bool owned;
    Buffer() : data(0), stride(0), owned(false)
    {}
    ~Buffer()
    {}
    P3& Point(unsigned i) const
    {
        return *reinterpret_cast<P3*>(data + stride * i);
    }
    NiPoint2& UV(unsigned i) const
    {
        return *reinterpret_cast<NiPoint2*>(data + stride * i);
    }
    void FUN_00534780(unsigned, P4*);
};
struct GeometryData
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
    virtual unsigned short GetTriangleTotal();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    P3* positions;
    P3* normals;
    P4* colors;
    NiPoint2* texcoords;
    struct Provider* provider;
    bool FUN_00a67360(bool);
    void NiGeometryData_UnlockPackedVertexData();
    void NiGeometryData_GetVerticesIterator(Buffer*);
    void NiGeometryData_GetNormalsIterator(Buffer*);
    void FUN_00a67660(Buffer*);
    void GetKeyAndMode(unsigned, Buffer*);
    unsigned short* FUN_00a7b850();
};
struct Provider
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
    virtual bool Available();
};
struct Geometry
{
    int unk00;
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
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    Transform world;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryData* data;
};
struct Hit
{
    int unk00, unk04;
    P3 point;
    float distance;
    unsigned short triangle, i0, i1, i2;
    NiPoint2 uv;
    P3 normal;
    P4 color;
};
struct HitList
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Hit* GetTexture(Geometry*);
};
struct Pick
{
    int mode;
    int sort;
    int unk08;
    int coordinates;
    bool GetFrontOnly() const
    {
        return frontOnly;
    }
    bool frontOnly;
    char unk11;
    short unk12;
    int unk14;
    HitList hits;
    bool wantUV, wantNormal, interpolateNormal, wantColor;
    bool GetUV() const
    {
        return wantUV;
    }
    bool GetPlaneNormal() const
    {
        return wantNormal;
    }
    bool GetColor() const
    {
        return wantColor;
    }
};
bool __cdecl FUN_00eadb90(const P3*, const P3*, const P3*, const P3*, const P3*, bool, P3*, float*, float*, float*);
// Tests a ray against geometry triangles when available and fills hit data, including optional interpolated attributes.
// @f3 0x007fcea0 (community match, verified in this file)
struct RayPointCalls : P3 { __declspec(noalias) void FUN_00468d00(); };
struct RayMatrixCalls : Matrix { __declspec(noalias) P3 FUN_004752c0(const P3*); };
struct RayStreamCalls : Buffer { void FUN_004ca450(unsigned, P4*); };
struct RayDataCalls : GeometryData {
    bool FUN_00831680(bool);
    void FUN_008316f0();
    void FUN_00831730(Buffer*);
    void FUN_00831980(Buffer*);
    unsigned short* FUN_006a05c0();
};
bool __cdecl FUN_008108d0(const P3*, const P3*, const P3*, const P3*, const P3*, bool, P3*, float*, float*, float*);
P4 __cdecl FUN_004c3830(float, const P4&);
extern NiPoint2 DAT_0108f390;
extern P4 DAT_00f73220;

struct RayOriginMatrix : Matrix
{
    P3 InverseForRay(const P3& p) const
    {
        P3 r;
        r.x = (((m00 * p.x + (p.y * m10)) + m20 * p.z));
        r.y = m01 * p.x + p.y * m11 + m21 * p.z;
        r.z = (m02 * p.x + p.y * m12 + m22 * p.z);
        return r;
    }
};

// pdb: NiCollisionTraversals::FindIntersectionsTriShapeFastPath | NiCollisionTraversals.obj | fnv360_0822_retail, objrun, high
// pdb params: kOrigin, kDir, kPick, pkTBG
// pdb: NiCollisionTraversals::FindIntersectionsTriShapeFastPath | NiCollisionTraversals.obj | fnv360_0822_retail, objrun, high (was: RaycastGeometry)
bool __cdecl NiCollisionTraversals_FindIntersectionsTriShapeFastPath(const P3* origin, const P3* direction, Pick* pick, Geometry* geometry)
{
    Transform& worldTransform = geometry->world;
    P3 delta;
    delta = *origin - worldTransform.translation;
    float inverseScale;
    inverseScale = 1.0f / worldTransform.scale;
    P3 localOrigin = static_cast<const RayOriginMatrix&>(worldTransform.rotation).InverseForRay(delta) * inverseScale;
    const Matrix& rotation = worldTransform.rotation;
    P3 localDirection = rotation.InverseRotateVector(*direction) * inverseScale;
    bool found = false;
    unsigned short count;
    count = geometry->data->GetTriangleTotal();
    bool locked = false;
    RayDataCalls* data = static_cast<RayDataCalls*>(geometry->data);
    Buffer positionBuffer;
    P3 p0, p1, p2;
    P3 normal;
    P3* positions = geometry->data->positions;
    if (!positions)
    {
        Provider* provider = data->provider;
        if (provider && provider->Available())
        {
            locked = data->FUN_00831680(true);
            data->FUN_00831730(&positionBuffer);
        }
    }
    unsigned short* triangles = data->FUN_006a05c0();
    if (!triangles || (!positions && !positionBuffer.data))
    {
        Hit* hit;
        hit = pick->hits.GetTexture(geometry);
        P3 offset = geometry->world.translation - *origin;
        float distance;
        float squared = offset.x * offset.x + offset.y * offset.y + offset.z * offset.z;
        distance = (float)sqrt(squared);
        hit->distance = distance;
        return true;
    }
    for (unsigned short triangle = 0; triangle < count; ++triangle)
    {
        unsigned short i0, i1, i2;
        {
            unsigned index = 3 * triangle;
            i0 = triangles[index];
            i1 = triangles[index + 1];
            i2 = triangles[index + 2];
        }
        if (locked)
        {
            p0 = positionBuffer.Point(i0);
            p1 = positionBuffer.Point(i1);
            p2 = positionBuffer.Point(i2);
        }
        else
        {
            p0 = positions[i0];
            p1 = positions[i1];
            p2 = positions[i2];
        }
        P3 intersection;
        float distance, b1, b2;
        if (!FUN_008108d0(&localOrigin, &localDirection, &p0, &p1, &p2, pick->GetFrontOnly(), &intersection, &distance,
                          &b1, &b2))
            continue;
        found = true;
        Hit* hit = pick->hits.GetTexture(geometry);
        if (pick->coordinates == 1)
            intersection =
                worldTransform.translation + worldTransform.rotation.Apply(intersection) * worldTransform.scale;
        hit->point = intersection;
        hit->distance = distance;
        hit->triangle = triangle;
        hit->i0 = i0;
        hit->i1 = i1;
        hit->i2 = i2;
        float b0;
        b0 = 1.0f - (b1 + b2);
        if (pick->GetUV())
        {
            Buffer uv;
            data->GetKeyAndMode(0, &uv);
            if (uv.data)
            {
                const NiPoint2& uv0 = uv.UV(i0);
                const NiPoint2& uv1 = uv.UV(i1);
                const NiPoint2& uv2 = uv.UV(i2);
                hit->uv = uv0 * b0 + uv1 * b1 + uv2 * b2;
            }
            else
            {
                NiPoint2* coords = geometry->data->texcoords;
                if (coords)
                    hit->uv = coords[i0] * b0 + coords[i1] * b1 + coords[i2] * b2;
                else
                    hit->uv = DAT_0108f390;
            }
        }
        else
            hit->uv = DAT_0108f390;
        if (pick->GetPlaneNormal())
        {
            Buffer normalBuffer;
            data->NiGeometryData_GetNormalsIterator(&normalBuffer);
            if (normalBuffer.data)
            {
                P3 n0 = normalBuffer.Point(i0), n1 = normalBuffer.Point(i1), n2 = normalBuffer.Point(i2);
                normal = n0 * b0 + n1 * b1 + n2 * b2;
            }
            else if (pick->interpolateNormal && geometry->data->normals)
            {
                P3* normals;
                normals = geometry->data->normals;
                normal = normals[i0] * b0 + normals[i1] * b1 + normals[i2] * b2;
            }
            else
            {
                P3 edge2;
                P3 edge1;
                edge1 = p1 - p0;
                edge2 = p2 - p0;
                normal = edge1.Cross(edge2);
            }
            static_cast<RayPointCalls*>(&normal)->FUN_00468d00();
            if (pick->coordinates == 1)
                normal = static_cast<RayMatrixCalls*>(&worldTransform.rotation)->FUN_004752c0(&normal);
            hit->normal = normal;
        }
        else
            hit->normal = *reinterpret_cast<const P3*>(&_NiPoint3_ZERO);
        if (pick->GetColor())
        {
            Buffer colorBuffer;
            data->FUN_00831980(&colorBuffer);
            if (colorBuffer.data)
            {
                P4 c0, c1, c2;
                static_cast<RayStreamCalls*>(&colorBuffer)->FUN_004ca450(i0, &c0);
                static_cast<RayStreamCalls*>(&colorBuffer)->FUN_004ca450(i1, &c1);
                static_cast<RayStreamCalls*>(&colorBuffer)->FUN_004ca450(i2, &c2);
                hit->color = c0 * b0 + c1 * b1 + c2 * b2;
            }
            else
            {
                P4* colors = geometry->data->colors;
                if (colors)
                {
                    P4 blended = FUN_004c3830(b0, colors[i0])
                                     .AddDelta(FUN_004c3830(b1, colors[i1]))
                                     .AddDelta(FUN_004c3830(b2, colors[i2]));
                    hit->color = blended;
                }
                else
                    hit->color = DAT_00f73220;
            }
        }
        else
            hit->color = DAT_00f73220;
        if (1 == pick->mode && pick->sort == 1)
        {
            if (locked)
                data->FUN_008316f0();
            return true;
        }
    }
    if (locked)
        data->FUN_008316f0();
    return found;
}


extern char DAT_011f4248;
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
struct NiPoint3
{
    float x, y, z;
    __forceinline NiPoint3()
    {}
    __forceinline NiPoint3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    __forceinline NiPoint3 operator-(const NiPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    __forceinline NiPoint3 operator*(float f) const
    {
        return NiPoint3(x * f, y * f, z * f);
    }
    __forceinline NiPoint3& operator+=(const NiPoint3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
    __forceinline float Dot(const NiPoint3& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

__forceinline void ScaleOut(float f, NiPoint3& o, const NiPoint3& v)
{
    o.x = (((f * v.x)));
    o.y = f * v.y;
    o.z = f * v.z;
}

__forceinline void DotOut(const NiPoint3& a, const NiPoint3& b, float& o)
{
    o = a.x * b.x + a.y * b.y + a.z * b.z;
}
__forceinline void Dot0(const NiPoint3& a, const float& by, const float& bx, const float& bz, float& o)
{
    o = (((a.x * bx)) + (a.y * by) + (a.z) * bz);
}
__forceinline void Dot1(const NiPoint3& a, float bz, float bx, float by, float& o)
{
    o = (a.x * bx + a.y * (float)by) + a.z * (float)bz;
}
__forceinline void Dot2(const NiPoint3& a, float bx, float by, float bz, float& o)
{
    o = ((a.x * bx) + (a.y) * by) + a.z * (float)bz;
}

struct ThreeByThreeMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    void GetMatrix(float* a, float* b);
};
struct OrientedBoxBound
{
    NiPoint3 m_kCenter;
    NiPoint3 m_akAxis0;
    NiPoint3 m_akAxis1;
    NiPoint3 m_akAxis2;
    float m_afExtent0;
    float m_afExtent1;
    float m_afExtent2;
    void ComputeFromPoints(unsigned short count, const NiPoint3* pts);
};
// Computes the box center, axes, and extents from points, with an axis-aligned fallback for degenerate dimensions.
// @fnv 0x00eadf30
// pdb: NiBox::CreateFromData | NiBox.obj | fnv360_0822_retail, udata, high
// pdb params: usQuantity, pkVertex
void OrientedBoxBound::ComputeFromPoints(unsigned short count, const NiPoint3* apPoints)
{
    const NiPoint3* points = apPoints;
    float minZ, minY, minX;
    float afMin[3];
    float afMax[3];
    float afEigenvalue[3];
    float mat[9];
    float maxX = points[0].x;
    minX = maxX;
    float maxY = points[0].y;
    minY = maxY;
    float maxZ = points[0].z;
    minZ = maxZ;
    m_kCenter = points[0];
    for (unsigned short i = 1; i < count; ++i)
    {
        m_kCenter += points[i];
        if (points[i].x < minX)
            minX = points[i].x;
        else if (maxX < points[i].x)
            maxX = points[i].x;
        if (points[i].y < minY)
            minY = points[i].y;
        else if (maxY < points[i].y)
            maxY = points[i].y;
        if (points[i].z < minZ)
            minZ = points[i].z;
        else if (maxZ < points[i].z)
            maxZ = points[i].z;
    }
    NiPoint3 ptScaled;
    ScaleOut((float)(1.0f / (float)count), ptScaled, m_kCenter);
    m_kCenter = ptScaled;
    if (minX != maxX && minY != maxY && minZ != maxZ)
    {
        memcpy(mat, &DAT_011f4248, 36);
        for (unsigned short i = 0; i < count; ++i)
        {
            mat[0] += m_kCenter.x * m_kCenter.x;
            mat[1] += m_kCenter.y * m_kCenter.x;
            mat[2] += m_kCenter.z * m_kCenter.x;
            mat[4] += m_kCenter.y * m_kCenter.y;
            mat[5] += m_kCenter.z * m_kCenter.y;
            mat[8] += m_kCenter.z * m_kCenter.z;
        }
        mat[3] = mat[1];
        mat[6] = mat[2];
        mat[7] = mat[5];
        ((ThreeByThreeMatrix*)mat)->GetMatrix(afEigenvalue, (float*)&m_akAxis0);
        afMin[0] = points[0].x - m_kCenter.x;
        afMin[1] = points[0].y - m_kCenter.y;
        afMin[2] = points[0].z - m_kCenter.z;
        memcpy(afMax, afMin, sizeof(afMax));
        for (unsigned short i = 1; i < count; ++i)
        {
            NiPoint3 ptDiff = points[i] - m_kCenter;
            float p0;
            Dot0(m_akAxis0, ptDiff.y, ptDiff.x, ptDiff.z, p0);
            if (p0 < afMin[0])
                afMin[0] = p0;
            else if (p0 > afMax[0])
                afMax[0] = p0;
            float p1;
            Dot1(ptDiff, m_akAxis1.z, m_akAxis1.x, m_akAxis1.y, p1);
            if (p1 < afMin[1])
                afMin[1] = p1;
            else if (p1 > afMax[1])
                afMax[1] = p1;
            float y;
            Dot2(ptDiff, m_akAxis2.x, m_akAxis2.y, m_akAxis2.z, y);
            if (y < afMin[2])
                afMin[2] = y;
            else if (y > afMax[2])
                afMax[2] = y;
        }
        float mid0 = (afMax[0] + afMin[0]) * 0.5;
        {
            NiPoint3 offset;
            ScaleOut(mid0, offset, m_akAxis0);
            m_kCenter += offset;
        }
        float mid1 = (afMax[1] + afMin[1]) * 0.5;
        {
            NiPoint3 offset;
            ScaleOut(mid1, offset, m_akAxis1);
            m_kCenter += offset;
        }
        float mid2 = (afMax[2] + afMin[2]) * 0.5;
        {
            NiPoint3 offset;
            ScaleOut(mid2, offset, m_akAxis2);
            m_kCenter += offset;
        }
        m_afExtent0 = (afMax[0] - afMin[0]) * 0.5;
        m_afExtent1 = (afMax[1] - afMin[1]) * 0.5;
        m_afExtent2 = (afMax[2] - afMin[2]) * 0.5;
    }
    else
    {
        m_akAxis0 = NiPoint3(1.0f, 0.0f, 0.0f);
        m_akAxis1 = NiPoint3(0.0f, 1.0f, 0.0f);
        m_akAxis2 = NiPoint3(0.0f, 0.0f, 1.0f);
        float fExtentX = (maxX - minX) * 0.5;
        float fExtentY = (maxY - minY) * 0.5;
        float fExtentZ = (maxZ - minZ) * 0.5;
        if (fExtentX <= 0.0f)
            fExtentX = 0.1f;
        if (fExtentY <= 0.0f)
            fExtentY = 0.1f;
        if (fExtentZ <= 0.0f)
            fExtentZ = 0.1f;
        m_afExtent0 = fExtentX;
        m_afExtent1 = fExtentY;
        m_afExtent2 = fExtentZ;
    }
}

#include <math.h>
namespace fnv_00e993d0 {
struct Vec3
{

    float x, y, z;
    Vec3()
    {}
    void AssignOutput(const Vec3& v)
    {
        Vec3 copy(v);
        memcpy(this, &copy, 12);
    }
    Vec3& operator=(const Vec3& v)
    {
        memcpy(this, &v, sizeof(v));
        return *this;
    }
    Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec3 operator+(const Vec3&) const;
    Vec3 FUN_004b3800(const Vec3&) const;
    __declspec(noalias) void FUN_004a0c10();
    Vec3 operator-(const Vec3& v) const
    {
        Vec3 r(x - v.x, y - v.y, z - v.z);
        return r;
    }
    Vec3 operator*(float f) const
    {
        Vec3 r(x * f, y * f, z * f);
        return r;
    }
    Vec3 Added(const Vec3& v) const
    {
        Vec3 r(x + v.x, v.y + y, v.z + z);
        return r;
    }
};

struct Vec2
{
    float x, y;
    Vec2()
    {}
    Vec2& operator*=(float f)
    {
        x *= f;
        y *= f;
        return *this;
    }
    Vec2& operator+=(const Vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    Vec2 operator+(const Vec2&) const;
};
struct Vec4
{
    float x, y, z, w;
    Vec4() : x(0), y(0), z(0), w(0)
    {}
    Vec4 operator+(const Vec4&) const;
};
extern Vec2 __cdecl FUN_00532fd0(float, const Vec2&);
extern Vec3 __cdecl FUN_004a3760(float, const Vec3&);
extern Vec4 __cdecl FUN_00532f40(float, const Vec4&);

struct Mat3
{

    float m00, m01, m02;

    float m10, m11, m12;

    float m20, m21, m22;
    __declspec(noalias) Vec3 FUN_004b4500(const Vec3&) const;
    Vec3 RotateCaptured(const Vec3& v, const float& cachedm01, const float& cachedm02, const float& cachedm10) const
    {
        Vec3 r;
        r.x = v.y * cachedm10 + m00 * v.x + m20 * v.z;
        r.y = v.x * cachedm01 + v.y * m11 + m21 * v.z;
        r.z = cachedm02 * v.x + m12 * v.y + v.z * m22;
        return r;
    }
    Vec3 InverseRotate(const float& vx, const float& vy, const float& vz) const
    {
        Vec3 r;
        r.x = vy * m10 + m00 * vx + m20 * vz;
        r.y = vx * m01 + vy * m11 + m21 * vz;
        r.z = m02 * vx + m12 * vy + vz * m22;
        return r;
    }
};

struct Transform
{

    Mat3 rotation;

    Vec3 translation;

    float scale;
};

struct Normal : Vec3
{
    Normal()
    {}
    Normal(const Vec3& v) : Vec3(v)
    {}
};

struct QueryResult
{

    int unk00, unk04;

    Vec3 point;

    float distance;

    unsigned short triangle, a, b, c;

    Vec2 uv;

    Vec3 normal;

    Vec4 tangent;
};

struct Output
{

    int unk00;

    QueryResult* GetTexture(void*);
};

struct Options
{

    int mode, stopAtFirst, unk08, coordinateMode;

    bool unk10;
    unsigned char unk11, unk12, unk13;

    int unk14;

    Output output;

    int unk1C, unk20, unk24, unk28, unk2C;

    unsigned char needsUV, needsNormal, needsTangent, needsColor;
};

struct BufferView
{

    Vec3* data;

    int stride;

    bool owned;
    void FUN_00534780(unsigned int, Vec4*);
};

struct Stream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual bool Available();
};
struct Mesh
{

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();

    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();

    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();

    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();

    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();

    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();

    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();

    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();

    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();

    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();

    virtual void vA0();
    virtual void vA4();

    virtual unsigned short GetTriangleTotal();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;

    Vec3* vertices;

    Vec3* normals;

    Vec4* colors;

    Vec2* texcoords;

    Stream* stream;

    bool FUN_00a67360(int);

    void NiGeometryData_GetVerticesIterator(BufferView*);

    unsigned short* FUN_00a75f10();

    void NiGeometryData_UnlockPackedVertexData();

    void GetKeyAndMode(int, BufferView*);

    void NiGeometryData_GetNormalsIterator(BufferView*);

    void FUN_00a67660(BufferView*);
};

struct Shape
{

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;

    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;

    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;

    int unk60, unk64;

    Transform world;

    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;

    Mesh* mesh;
};

extern bool __cdecl FUN_00eadb90(const Vec3*, const Vec3*, const Vec3*, const Vec3*, const Vec3*, bool, Vec3*, float*,
                                 float*, float*);

extern Vec4 DAT_011a9be0;
extern Vec3 DAT_011f426c;
extern Vec2 DAT_011f4980;
}  // namespace fnv_00e993d0

#include <math.h>
namespace fnv_00e9b4f0 {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    void AssignOutput(const NiPoint3& v)
    {
        NiPoint3 copy(v);
        memcpy(this, &copy, 12);
    }
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    NiPoint3 FUN_00439ef0(const NiPoint3&) const;
    NiPoint3 FUN_00439e90(const NiPoint3&) const;
    float FUN_00457990() const;
    NiPoint3 FUN_004b3800(const NiPoint3&) const;
    __declspec(noalias) void FUN_004a0c10();
    NiPoint3 operator-(const NiPoint3& v) const
    {
        NiPoint3 r(x - v.x, y - v.y, z - v.z);
        return r;
    }
    NiPoint3 operator*(float f) const
    {
        return NiPoint3(x * f, y * f, z * f);
    }
    NiPoint3 Sum(const NiPoint3& v) const
    {
        return NiPoint3(x + v.x, y + v.y, z + v.z);
    }
    NiPoint3 Added(const NiPoint3& v) const
    {
        return NiPoint3(x + v.x, v.y + y, v.z + z);
    }
    float Dot(const NiPoint3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
};

inline NiPoint3 ScalePoint(float f, const NiPoint3& v)
{
    return v * f;
}

struct Vec2
{
    float x, y;
    Vec2()
    {}
    Vec2& operator*=(float f)
    {
        x *= f;
        y *= f;
        return *this;
    }
    Vec2& operator+=(const Vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    Vec2 operator+(const Vec2&) const;
};
struct Vec4
{
    float x, y, z, w;
    Vec4() : x(0), y(0), z(0), w(0)
    {}
    Vec4 operator+(const Vec4&) const;
};
extern Vec2 __cdecl FUN_00532fd0(float, const Vec2&);
extern NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
extern Vec4 __cdecl FUN_00532f40(float, const Vec4&);
extern __declspec(noalias) NiPoint3 __cdecl FUN_004b3ae0(const NiPoint3&, const float*);

struct Mat3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    __declspec(noalias) NiPoint3 FUN_004b4500(const NiPoint3*) const;
};

struct Transform
{
    Mat3 rotation;
    NiPoint3 translation;
    float scale;
};

struct Bound
{
    NiPoint3 center;
    float radius;
};

struct QueryResult
{
    int unk00, unk04;
    NiPoint3 point;
    float distance;
    unsigned short triangle, a, b, c;
    void SetVertices(unsigned short i0, unsigned short i1, unsigned short i2)
    {
        a = i0;
        b = i1;
        c = i2;
    }
    Vec2 uv;
    NiPoint3 normal;
    Vec4 tangent;
};

struct Output
{
    int unk00;
    QueryResult* GetTexture(void*);
};

struct Options
{
    int mode, stopAtFirst, unk08, coordinateMode;
    bool unk10;
    unsigned char unk11, unk12, unk13;
    int unk14;
    Output output;
    int unk1C, unk20, unk24, unk28, unk2C;
    unsigned char needsUV, needsNormal, needsTangent, needsColor;
};

struct BufferView
{
    NiPoint3* data;
    int stride;
    bool owned;
    void FUN_00534780(unsigned int, Vec4*);
};

struct Stream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual bool Available();
};
struct Mesh
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual unsigned short GetTriangleTotal();
    virtual void GetTriangle(unsigned short, unsigned short*, unsigned short*, unsigned short*);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    NiPoint3* vertices;
    NiPoint3* normals;
    Vec4* colors;
    Vec2* texcoords;
    Stream* stream;
    int unk34, unk38, unk3C, unk40;
    unsigned short unk44;
    bool FUN_00a67360(int);
    void NiGeometryData_GetVerticesIterator(BufferView*);
    void NiGeometryData_UnlockPackedVertexData();
    void GetKeyAndMode(int, BufferView*);
    void NiGeometryData_GetNormalsIterator(BufferView*);
    void FUN_00a67660(BufferView*);
};

struct RTTI
{
    const char* name;
    const RTTI* parent;
};

struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual const RTTI* GetRTTI();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Bound* bound;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64;
    Transform world;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;
    Mesh* mesh;
    int unkBC;
};

bool FUN_0043b300(const void*, Shape*);
bool __cdecl NiCollisionTraversals_FindIntersectionsTriShapeFastPath(const NiPoint3*, const NiPoint3*, Options*, Shape*);

extern bool __cdecl FUN_00eadb90(const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*,
                                 bool, NiPoint3*, float*, float*, float*);

extern Vec4 DAT_011a9be0;
extern NiPoint3 DAT_011f426c;
extern Vec2 DAT_011f4980;

inline bool IsKindOfType(const void* rtti, Shape* shape)
{
    for (const RTTI* r = shape->GetRTTI(); r; r = r->parent)
        if (r == rtti)
            return true;
    return false;
}

// Tests the ray against a shape's mesh or bound data and writes distance plus mesh hit attributes when available.
// @f3 0x007fe110 (community match, verified in this file)
// RaycastShape (0x007fe110) -- byte-exact body from the saved draft.
//
// Integration shape: the project's file already owns namespace fnv_00e9b4f0 and its
// parameter types (only forward declarations here, which every TU may repeat); the
// function is defined in that namespace so it keeps the required mangled symbol.
// Its private layout twins live in namespace w324, so nothing the unit defines is
// redeclared and every member access keeps the offsets the code proves.
namespace fnv_00e9b4f0 { class NiPoint3; struct Options; struct Shape;
bool __cdecl RaycastShape(const NiPoint3* rayStart, const NiPoint3* rayDirection, Options* options, Shape* shape); }

namespace w324 {
struct Provider;
class NiPoint2
{
  public:
    NiPoint2 FUN_004916d0(const NiPoint2&);
    float x, y;
    NiPoint2() {}
    NiPoint2(float a,float b):x(a),y(b){}
    NiPoint2 operator*(float f) const
    {
        NiPoint2 r = *this;
        r.x *= f;
        r.y *= f;
        return r;
    }
    NiPoint2 operator+(const NiPoint2& b) const
    {
        NiPoint2 r = *this;
        r.x += b.x;
        r.y += b.y;
        return r;
    }
};
class NiPoint3 : public ::P3
{
public:
    NiPoint3 FUN_00422970(const NiPoint3&) const;
    __forceinline float X() const { return x; }
    __forceinline float Z() const { return z; }
    __forceinline float Y() const { return y; }
    __forceinline NiPoint3() {}
    __forceinline NiPoint3(float a,float b,float c) { x=a; y=b; z=c; }
    __forceinline NiPoint3 operator*(float f) const
    {
        return NiPoint3(f*x,f*y,f*z);
    }
    __forceinline NiPoint3 operator+(const NiPoint3& b) const
    {
        return NiPoint3(x+b.x,y+b.y,z+b.z);
    }
    __forceinline NiPoint3 operator-(const NiPoint3& b) const
    {
        NiPoint3 r;
        r.x = x - b.x;
        r.y = y - b.y;
        r.z = z - b.z;
        return r;
    }


 __declspec(noalias) void FUN_00468d00();

    NiPoint3 FUN_00475280(const NiPoint3&);
    NiPoint3 FUN_004229a0(const NiPoint3&);
    float FUN_00432bd0();

};

struct P4
{
    float r, g, b, a;
    P4() : r(0), g(0), b(0), a(0)
    {}


    P4 FUN_004c3790(const P4&);
};



struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;



 __declspec(noalias) NiPoint3 FUN_004752c0(const NiPoint3* p) const;


};
struct Transform
{
    Matrix rotation;
    NiPoint3 translation;
    float scale;
};
struct Buffer
{
    char* data;
    unsigned stride;
    bool owned;
    Buffer() : data(0), stride(0), owned(false)
    {}
    ~Buffer()
    {}



    void FUN_004ca450(unsigned, P4*);
};
struct GeometryData
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
    virtual unsigned short GetTriangleTotal();
    virtual void GetTriangle(unsigned short,unsigned short*,unsigned short*,unsigned short*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* positions;
    NiPoint3* normals;
    P4* colors;
    NiPoint2* texcoords;
    struct Provider* provider;
    int unk34,unk38,unk3c,unk40;
    unsigned short unk44;
    bool FUN_00831680(bool);
    void FUN_008316f0();
    void FUN_00831730(Buffer*);
    void FUN_00831980(Buffer*);
    void FUN_008318d0(Buffer*);
    void FUN_00831a40(unsigned,Buffer*);







};
struct Provider
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
    virtual bool Available();
};
struct Bound;
struct ZType;
struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual ZType* GetType();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Bound* bound;
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
    Transform world;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryData* data;
    int unkBC;
};
struct Hit
{
    int unk00, unk04;
    ::P3 point;
    float distance;
    unsigned short triangle, i0, i1, i2;
    __forceinline void SetVertices(unsigned short a,unsigned short b,unsigned short c) { i0=a; i1=b; i2=c; }
    NiPoint2 uv;
    ::P3 normal;
    P4 color;
};
struct HitList
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;

    Hit* FUN_007fbf40(Shape*);
};
struct Options
{
    int mode;
    int sort;
    int unk08;
    int coordinates;
    bool GetFrontOnly() const
    {
        return frontOnly;
    }
    bool frontOnly;
    char unk11;
    short unk12;
    int unk14;
    HitList hits;
    bool wantUV, wantNormal, interpolateNormal, wantColor;
    bool GetUV() const
    {
        return wantUV;
    }
    bool GetPlaneNormal() const
    {
        return wantNormal;
    }
    bool GetColor() const
    {
        return wantColor;
    }
};







bool __cdecl FUN_008108d0(const NiPoint3*,const NiPoint3*,const NiPoint3*,const NiPoint3*,const NiPoint3*,bool,NiPoint3*,float*,float*,float*);
P4 __cdecl FUN_004c3830(float,const P4&);
extern NiPoint2 DAT_0108f390;
extern P4 DAT_00f73220;
extern const NiPoint3 DAT_0108ec68;



bool __cdecl NiCollisionTraversals_FindIntersectionsTriShapeFastPath(const NiPoint3*,const NiPoint3*,Options*,Shape*);


struct ZType { int unk00; ZType* parent; };

extern ZType DAT_0108f414;
extern int DAT_0108f440;
inline bool ZIsKindOfType(const ZType* wanted, Shape* shape) { ZType* t=shape->GetType(); while(t) {if(t==wanted)return true; t=t->parent;}return false; }
extern bool __cdecl FUN_00424d20(const void*,Shape*);
extern bool __cdecl NiCollisionTraversals_FindIntersectionsOneStripFastPath(const NiPoint3*,const NiPoint3*,Options*,Shape*);
extern NiPoint3 __cdecl FUN_00475320(const NiPoint3&,const Matrix*);
struct Bound { NiPoint3 center; float radius; };
extern Bound DAT_0108edc8;
inline NiPoint3 ZScalePoint(float f,const NiPoint3& p) {return p*f;}

NiPoint2 __cdecl FUN_004c3880(float,const NiPoint2&);
NiPoint3 __cdecl FUN_00468cd0(float,const NiPoint3&);



__forceinline NiPoint3 ZLocalStart(const NiPoint3& start,const Transform& xform,float& invScale) {
 NiPoint3 difference = start - xform.translation;
 invScale = 1.0f / xform.scale;
 return FUN_00475320(difference,&xform.rotation) * invScale;
}
} // namespace w324

// pdb: NiCollisionTraversals::FindIntersectionsTriBasedGeom | NiCollisionTraversals.obj | fnv360_0822_retail, objrun, medium
// pdb params: kOrigin, kDir, kPick, pkTBG
bool __cdecl ::fnv_00e9b4f0::RaycastShape(const ::fnv_00e9b4f0::NiPoint3* startArg,const ::fnv_00e9b4f0::NiPoint3* dirArg,::fnv_00e9b4f0::Options* optArg,::fnv_00e9b4f0::Shape* shapeArg)
{
    const w324::NiPoint3* rayStart = reinterpret_cast<const w324::NiPoint3*>(startArg);
    const w324::NiPoint3* rayDirection = reinterpret_cast<const w324::NiPoint3*>(dirArg);
    w324::Options* options = reinterpret_cast<w324::Options*>(optArg);
    w324::Shape* shape = reinterpret_cast<w324::Shape*>(shapeArg);
    w324::NiPoint3 va, vb, vc;
    w324::NiPoint3 normal;
    if (options->unk08 && !shape->unkBC)
    {
        if (w324::ZIsKindOfType(&w324::DAT_0108f414, shape))
        {
            if (shape->data->unk44 == 1)
                return w324::NiCollisionTraversals_FindIntersectionsOneStripFastPath(rayStart, rayDirection, options, shape);
        }
        else if (w324::FUN_00424d20(&w324::DAT_0108f440, shape))
            return w324::NiCollisionTraversals_FindIntersectionsTriShapeFastPath(rayStart, rayDirection, options, shape);
        const w324::Transform& xform = shape->world;
        float invScale;
        w324::NiPoint3 localStart = w324::ZLocalStart(*rayStart,xform,invScale);
        w324::NiPoint3 localDirection = w324::FUN_00475320(*rayDirection, &xform.rotation) * invScale;
        bool anyHit = false;
        const unsigned short triangleCount = shape->data->GetTriangleTotal();
        bool ownsPositions = false;
        w324::GeometryData* mesh = shape->data;
        w324::Buffer positions;
        w324::NiPoint3* directVertices = mesh->positions;
        if (!directVertices)
        {
            w324::Provider* stream = mesh->provider;
            if (stream && stream->Available())
            {
                ownsPositions = mesh->FUN_00831680(1);
                mesh->FUN_00831730(&positions);
            }
            if (!positions.data)
            {
                w324::Hit* result = options->hits.FUN_007fbf40(shape);
                w324::NiPoint3 offset = shape->world.translation.FUN_004229a0(*rayStart);
                result->distance = offset.FUN_00432bd0();
                return true;
            }
        }
        for (unsigned short tri = 0; tri < triangleCount; ++tri)
        {
            unsigned short a, b, c;
            shape->data->GetTriangle(tri, &a, &b, &c);
            if (!directVertices)
            {
                va = *(w324::NiPoint3*)((unsigned char*)positions.data + a * positions.stride);
                vb = *(w324::NiPoint3*)((unsigned char*)positions.data + b * positions.stride);
                vc = *(w324::NiPoint3*)((unsigned char*)positions.data + c * positions.stride);
            }
            else
            {
                va = directVertices[a];
                vb = directVertices[b];
                vc = directVertices[c];
            }
            w324::NiPoint3 point;
            float distance, u, v;
            bool frontOnly = options->frontOnly;
            if (w324::FUN_008108d0(&localStart, &localDirection, &va, &vb, &vc, frontOnly, &point, &distance, &u, &v))
            {
                anyHit = true;
                w324::Hit* result = options->hits.FUN_007fbf40(shape);
                if (options->coordinates == 1)
                {
                    point = xform.translation + w324::ZScalePoint(xform.scale, xform.rotation.FUN_004752c0(&point));
                }
                result->point = point;
                result->distance = distance;
                result->triangle = tri;
                result->SetVertices(a,b,c);
                float weight = 1.0f - (u + v);
                if (options->wantUV)
                {
                    w324::Buffer uv;
                    mesh->FUN_00831a40(0, &uv);
                    if (uv.data)
                    {
                        const w324::NiPoint2* pa = (w324::NiPoint2*)((unsigned char*)uv.data + a * uv.stride);
                        const w324::NiPoint2* pb = (w324::NiPoint2*)((unsigned char*)uv.data + b * uv.stride);
                        const w324::NiPoint2* pc = (w324::NiPoint2*)((unsigned char*)uv.data + c * uv.stride);
                        w324::NiPoint2 tc = *pc;
                        tc = tc * v;
                        w324::NiPoint2 tb = *pb;
                        tb = tb * u;
                        w324::NiPoint2 ta = *pa;
                        ta = ta * weight;
                        w324::NiPoint2 sum = ta;
                        sum = sum + tb;
                        w324::NiPoint2 value = sum;
                        value = value + tc;
                        result->uv = value;
                    }
                    else
                    {
                        w324::NiPoint2* texcoords = shape->data->texcoords;
                        if (texcoords)
                        {
                            w324::NiPoint2 sum = w324::FUN_004c3880(weight, texcoords[a]).FUN_004916d0(w324::FUN_004c3880(u, texcoords[b])).FUN_004916d0(w324::FUN_004c3880(v, texcoords[c]));
                            result->uv = sum;
                        }
                        else
                            result->uv = w324::DAT_0108f390;
                    }
                }
                else
                {
                    result->uv = w324::DAT_0108f390;
                }
                if (options->wantNormal)
                {
                    w324::Buffer normals;
                    mesh->FUN_008318d0(&normals);
                    if (normals.data)
                    {
                        w324::NiPoint3 na = *(w324::NiPoint3*)((unsigned char*)normals.data + a * normals.stride);
                        w324::NiPoint3 nb = *(w324::NiPoint3*)((unsigned char*)normals.data + b * normals.stride);
                        w324::NiPoint3 nc = *(w324::NiPoint3*)((unsigned char*)normals.data + c * normals.stride);
                        normal = (na * weight) + (nb * u) + (nc * v);
                    }
                    else
                    {
                        w324::NiPoint3* directNormals;
                        if (options->interpolateNormal && (directNormals = shape->data->normals) != 0)
                            normal = w324::FUN_00468cd0(weight, directNormals[a]).FUN_00422970(w324::FUN_00468cd0(u, directNormals[b])).FUN_00422970(w324::FUN_00468cd0(v, directNormals[c]));
                        else
                        {
                            w324::NiPoint3 edge1, edge2;
                            edge1 = vb - va;
                            edge2 = vc - va;
                            normal = edge1.FUN_00475280(edge2);
                        }
                    }
                    normal.FUN_00468d00();
                    if (options->coordinates == 1)
                        normal = xform.rotation.FUN_004752c0(&normal);
                    result->normal = normal;
                }
                else
                    result->normal = w324::DAT_0108ec68;
                if (options->wantColor)
                {
                    w324::Buffer colors;
                    mesh->FUN_00831980(&colors);
                    if (colors.data)
                    {
                        w324::P4 ca, cb, cc;
                        colors.FUN_004ca450(a, &ca);
                        colors.FUN_004ca450(b, &cb);
                        colors.FUN_004ca450(c, &cc);
                        w324::P4 sum = w324::FUN_004c3830(weight, ca).FUN_004c3790(w324::FUN_004c3830(u, cb)).FUN_004c3790(w324::FUN_004c3830(v, cc));
                        result->color = sum;
                    }
                    else
                    {
                        w324::P4* directColors = shape->data->colors;
                        if (directColors)
                        {
                            w324::P4 sum = w324::FUN_004c3830(weight, directColors[a]).FUN_004c3790(w324::FUN_004c3830(u, directColors[b])).FUN_004c3790(w324::FUN_004c3830(v, directColors[c]));
                            result->color = sum;
                        }
                    }
                }
                else
                    result->color = w324::DAT_00f73220;
                if (options->mode == 1 && options->sort == 1)
                {
                    if (ownsPositions)
                        mesh->FUN_008316f0();
                    return true;
                }
            }
        }
        if (ownsPositions)
            mesh->FUN_008316f0();
        return anyHit;
    }

    w324::Bound sphere = shape->bound ? *shape->bound : w324::DAT_0108edc8;
    w324::NiPoint3 diff = sphere.center - *rayStart;
    float along = (((((const w324::NiPoint3*)dirArg)->y * diff.y))) + ((const w324::NiPoint3*)dirArg)->x * diff.x + ((const w324::NiPoint3*)dirArg)->z * diff.z;
    if (along < 0.0f)
        return false;
    w324::Hit* result = options->hits.FUN_007fbf40(shape);
    float ny = diff.y;
    along = diff.x * diff.x + ny * ny + diff.z * diff.z;
    result->distance = (float)sqrt((double)along);
    if (options->unk08 == 1)
    {
        float distance = result->distance;
        w324::NiPoint3 offset = *rayDirection * distance;
        w324::NiPoint3 hit;
        hit.x = rayStart->x + offset.x;
        hit.y = rayStart->y + offset.y;
        hit.z = offset.Z() + rayStart->z;
        result->point = hit;
    }
    return true;
}

}  // namespace fnv_00e9b4f0

extern int DAT_011a946c;
extern int DAT_011a9478;
extern int DAT_011a9484;
extern int DAT_011a9490;
extern int DAT_011f426c;
struct TempBounds
{
    int unk00;
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
    void ComputeFromPoints(unsigned int code, int* point);
};

struct NiBoundingVolume
{
    int vtable;
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
};
struct Helper
{
    NiBoundingVolume* FUN_00ea0820(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);
};
// Builds temporary bounds from code and point, allocates a NiBoundingVolume, then copies the bounds into it.
// @fnv 0x00e9c850
// pdb: NiCollisionConvert::ConvertToBoxBV | NiCollision.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: usQuantity, pkVertex
NiBoundingVolume* __cdecl FUN_00e9c850(unsigned int code, int* point)
{
    if ((unsigned short)code == 0 || point == 0)
        return 0;
    TempBounds stBounds;
    stBounds.ComputeFromPoints(code, point);
    NiBoundingVolume* result = (NiBoundingVolume*)g_memoryManager.Allocate(0x40);
    if (result != 0)
        result = ((Helper*)result)
                     ->FUN_00ea0820(*(NiPoint3*)&DAT_011a9490, *(NiPoint3*)&DAT_011f426c, *(NiPoint3*)&DAT_011a946c,
                                    *(NiPoint3*)&DAT_011a9478, *(NiPoint3*)&DAT_011a9484);
    else
        result = 0;
    memcpy((char*)result + 4, &stBounds, 60);
    return result;
}
