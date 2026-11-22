// src/f3staging/f3blk_00920000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009360c0 (community match, verified in this file)
extern const char key0[], key1[], key2[], key3[], key4[];
namespace f3m_009360c0 {
struct Obj { int a; Obj* parent; };
struct Lookup { void* value(); };
struct Wrapper {
    int a; int b;
    Wrapper(void*, const char*);
    void* get();
    float* item(int);
};
struct Parent { Lookup* find(const char*); };
void FUN_009360c0(void* dst, Obj* src) {
    Wrapper w(src, key0);
    __declspec(align(8)) struct Pair { void* p; void* v; } pair;
    pair.v = ((Parent*)src->parent)->find(key0)->value();
    pair.p = w.get();
    Wrapper a(&pair, key1); Wrapper b(dst, key1);
    *a.item(0) = *b.item(0);
    Wrapper c(&pair, key2); Wrapper d(dst, key2);
    *c.item(0) = *d.item(0);
    Wrapper e(&pair, key3); Wrapper f(dst, key3);
    *e.item(0) = *f.item(0);
    Wrapper g(&pair, key4); Wrapper h(dst, key4);
    *g.item(0) = *h.item(0);
}
}   // namespace f3m_009360c0

// @f3 0x00934030 (community match, verified in this file)
namespace f3m_00934030 {
struct Node { int FUN_0093d900(); };
struct __declspec(align(8)) Key {
    void *data;
    Node *node;
    void FUN_0093d600(void *, const char *);
    int *FUN_0093d6b0(int);
    char *FUN_0093d690(int);
    char *FUN_0093d700(int);
    Node *FUN_0093d790();
    void *FUN_0093d660();
};
void FUN_009234e0(void *, void *, int);
// pdb: hkDataObjectNative::asInt | hkDataObjectNative.obj | tesv_win, caller_sim, low
void FUN_00934030(void *a, void *b)
{
    Key x, y, z;
    void *first = *(void * volatile *)&a;
    x.FUN_0093d600(first, "startState");
    void *other = *(void * volatile *)&b;
    y.FUN_0093d600(other, "startStateId");
    int *src = x.FUN_0093d6b0(0);
    int *dst = y.FUN_0093d6b0(0);
    *dst = *src;
    y.FUN_0093d600(first, "randomStartState");
    x.FUN_0093d600(other, "startStateMode");
    if (*y.FUN_0093d690(0))
        *x.FUN_0093d700(0) = 3;
    else {
        z.FUN_0093d600(first, "enterStartStateOnActivate");
        if (!*z.FUN_0093d690(0))
            *x.FUN_0093d700(0) = 1;
    }
    x.FUN_0093d600(first, "globalTransitions");
    z.FUN_0093d600(other, "globalTransitions");
    FUN_009234e0(z.FUN_0093d660(), x.FUN_0093d660(), x.FUN_0093d790()->FUN_0093d900());
}
}   // namespace f3m_00934030

// @f3 0x00925970 (community match, verified in this file)
namespace f3m_00925970 {
typedef float hkReal;

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setMul4(hkReal r, const hkVector4& v)
    { for (int i = 0; i < 4; i++) m_quad[i] = r * v.m_quad[i]; }
    __forceinline void addMul4(hkReal rr, const hkVector4& v)
    { hkReal r = rr; m_quad[0] += r * v.m_quad[0]; m_quad[1] += r * v.m_quad[1]; m_quad[2] += r * v.m_quad[2]; m_quad[3] += r * v.m_quad[3]; }
    __forceinline void addMul4b(hkReal r, const hkVector4& v)
    { m_quad[0] += r * v.m_quad[0]; m_quad[1] += r * v.m_quad[1]; m_quad[2] += r * v.m_quad[2]; m_quad[3] += r * v.m_quad[3]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        for (int i = 0; i < 4; i++) m_quad[i] = a.m_quad[i] + b.m_quad[i];
    }
    __forceinline void add4l(const hkVector4& a)
    { for (int i = 0; i < 4; i++) m_quad[i] += a.m_quad[i]; }
    __forceinline void add4(const hkVector4& a)
    {
        m_quad[0] += a.m_quad[0]; m_quad[1] += a.m_quad[1]; m_quad[2] += a.m_quad[2]; m_quad[3] += a.m_quad[3];
    }
    __forceinline void sub4(const hkVector4& a)
    { m_quad[0] -= a.m_quad[0]; m_quad[1] -= a.m_quad[1]; m_quad[2] -= a.m_quad[2]; m_quad[3] -= a.m_quad[3]; }
    __forceinline hkReal dot3(const hkVector4& v) const
    { return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2]; }
    __forceinline void setRotatedDir(const struct hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    { const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1); const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2); const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0); set(nx, ny, nz, 0.0f); }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.m_quad[3]; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4b(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

extern hkVector4 DAT_01092a50;

class BodyBase
{
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void getRotation(hkQuaternion& q);

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
};

class Body : public BodyBase
{
public:
    hkVector4 m_offset;

    void FUN_008fe910(hkVector4& p);
    hkVector4& FUN_00925970(hkVector4& p);
};

// pdb: bhkRigidBodyT::GetPosition | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium
// pdb params: arPos
hkVector4& Body::FUN_00925970(hkVector4& p)
{
    if (this && unk08)
    {
        hkQuaternion q;
        getRotation(q);
        hkVector4 v;
        v.setRotatedDir(q, m_offset);
        FUN_008fe910(p);
        p.sub4(v);
    }
    else
    {
        p.m_quad[0] = DAT_01092a50.m_quad[0];
        p.m_quad[1] = DAT_01092a50.m_quad[1];
        p.m_quad[2] = DAT_01092a50.m_quad[2];
        p.m_quad[3] = DAT_01092a50.m_quad[3];
    }
    return p;
}
}   // namespace f3m_00925970
