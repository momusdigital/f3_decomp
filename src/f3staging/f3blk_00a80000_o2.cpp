#include <windows.h>
// src/f3staging/f3blk_00a80000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a800c0 (community match, verified in this file)
namespace f3m_00a800c0 {
struct Entry_a800c0
{
    int key;
    void* value;
};

struct Array_a800c0
{
    Entry_a800c0* m_data;
    int m_size;
    int m_capacity;
    void removeAt(int index)
    {
        m_size--;
        m_data[index] = m_data[m_size];
    }
};

struct FUN_00a800c0_cls
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    Array_a800c0 m_entries;

    void FUN_00a800c0(void* value);
};

// pdb: hkpConvexPenetrationUtil::init | hkpConvexPenetrationUtil.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkPackfileData::removeExport)
// pdb params: shapeA, shapeB, aTb, epsTolerance, pointsAinA, pointsBinB, simplex, simplexSize
void FUN_00a800c0_cls::FUN_00a800c0(void* value)
{
    for (int i = m_entries.m_size - 1; i >= 0; i--)
    {
        if (m_entries.m_data[i].value == value)
        {
            m_entries.removeAt(i);
            return;
        }
    }
}
}   // namespace f3m_00a800c0

// @f3 0x00a8f350 (community match, verified in this file)
extern float DAT_010660c0;
namespace f3m_00a8f350 {
void __cdecl FUN_00901e90(void* arr, int capacity, int stride);
namespace f3m_00a8f350 {
struct ByteArray {
    char* m_data;
    int m_size;
    int m_capacityAndFlags;
    ByteArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    void reserve(int n)
    {
        int cap = m_capacityAndFlags & 0x3fffffff;
        if (cap < n) {
            int c2 = cap * 2;
            FUN_00901e90(this, n < c2 ? c2 : n, 1);
        }
    }
};
}
using namespace f3m_00a8f350;
struct FUN_00a8f350 {
    ByteArray m00;
    ByteArray m0c;
    int unk18;
    int unk1c;
    const char* m20;
    FUN_00a8f350(int capacity, int a, int b);
    void FUN_00a8f110(int a, int b);
};
// pdb: hkMonitorStreamAnalyzer::hkMonitorStreamAnalyzer | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, uconst, low
// pdb params: memorySize, numThreads, numSpus
FUN_00a8f350::FUN_00a8f350(int capacity, int a, int b)
{
    DAT_010660c0 = 16666.6f;
    m0c.reserve(capacity);
    m20 = "Simulate";
    FUN_00a8f110(a, b);
}
}   // namespace f3m_00a8f350

// @f3 0x00a833a0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a833a0 {
struct Q8Str
{
    char* m_data;
    int m_len;
    unsigned int m_capFlags;
};

struct Q8Val;

struct Q8Val
{
    virtual ~Q8Val();
    virtual void v04();
    virtual void v08();
    virtual void* v0c(void** out, int arg);
    virtual void v10(void* v);
    void AppendStr(const char* s);
    int m_unk04;
    int m_type;
    Q8Str m_str;
};

struct Q8Obj
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void* s0c(void** out, int arg);
    virtual void s10(void* v);
};

struct Q8MemMgr
{
    void* Allocate(int size, int type);
};

extern "C" unsigned long (__stdcall* const DAT_00d9b080)(unsigned long);
extern "C" void FUN_00901e90(Q8Str* s, int newCap, int elemSize);
extern "C" void _ReadWriteBarrier();
extern "C" void q8_memcpy(void* dst, const void* src, unsigned int n);

static __declspec(noinline) Q8Str* FUN_00a833a0(Q8Obj* obj, Q8Str* out, int arg, char flag)
{
    Q8MemMgr* mm = (Q8MemMgr*)DAT_00d9b080(DAT_010f3170);
    char* p = (char*)mm->Allocate(1, 0x17);
    out->m_data = p;
    out->m_len = 1;
    out->m_capFlags = 1;
    p[0] = 0;

    Q8Val* v = 0;
    obj->s0c((void**)&v, arg);

    Q8Val* pv = (v->m_type == 3) ? v : 0;
    if (pv)
    {
        if (flag)
        {
            pv->AppendStr("(),");
        }
        int need = pv->m_str.m_len;
        int cap = (int)(out->m_capFlags & 0x3FFFFFFF);
        if (cap < need)
        {
            int nc = cap * 2;
            if (need >= nc)
                nc = need;
            FUN_00901e90(out, nc, 1);
        }
        char* dst = out->m_data;
        out->m_len = need;
        _ReadWriteBarrier();
        const char* src = pv->m_str.m_data;
        _ReadWriteBarrier();
        q8_memcpy(dst, src, need);
        if (v)
            delete v;
    }
    else if ((v->m_type == 2) ? v : 0)
    {
        obj->s10(v);
    }
    return out;
}

volatile void* g_q8_obj;
volatile void* g_q8_out;
volatile int g_q8_arg;
volatile char g_q8_flag;

void q8_probe_caller()
{
    FUN_00a833a0((Q8Obj*)g_q8_obj, (Q8Str*)g_q8_out, g_q8_arg, g_q8_flag);
}
}   // namespace f3m_00a833a0

// @f3 0x00a90a10 (community match, verified in this file)
struct StrBuf { int unk00; int unk04; int unk08;
  StrBuf(void** b, int n) throw(); void FUN_00943710(const char* s) throw(); void FUN_00943a60() throw(); };
struct Logger { virtual void v0(); virtual void v1(); virtual void v2(); virtual void Log(int a, unsigned int h, const char* m, const char* f, int line) throw(); };
extern Logger* DAT_010f3364;
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int GetKind() throw();
  int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkb0; int FUN_00959f80() throw(); int FUN_0095a000() throw(); int FUN_0095a020() throw(); };
// pdb: hkpConstraintUtils::getConstraintMotors | hkpConstraintUtils.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
int hkpConstraintUtils_getConstraintMotors(Obj* o, int* a, int* b, int* c)
{
    switch (o->GetKind()) {
    case 2: *a = o->unkb0; *b = 0; *c = 0; return 0;
    case 7: *a = o->FUN_00959f80(); *b = o->FUN_0095a000(); *c = o->FUN_0095a020(); return 0;
    default: break;
    }
    *c = 0; *b = 0; *a = 0;
    void* buf[128];
    StrBuf s(buf, 0x200);
    s.FUN_00943710("This type of constraint does not have motors");
    DAT_010f3364->Log(1, 0xabbae233, (const char*)buf, ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 0xec);
    s.FUN_00943a60();
    return 1;
}

// @f3 0x00a8ccf0 (community match, verified in this file)
namespace f3m_00a8ccf0 {
struct TextBuf {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    unsigned int unk14;
    void Init(int* p);
    void Pad(char c);
    void Done();
};
struct Info {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    unsigned char unk10;
};
struct Stream {
    void Put(int p);
};
int FUN_00a8c4d0(int a, int b, int c, int d);
void FUN_00943960(void* o, const char* fmt, ...);
void FUN_00a8c9e0(Stream* s, int a, int b, int c, int d, Info* i);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Heap { void Free(int p, unsigned int n, int k); };
static inline void Indent(TextBuf& t, int n)
{
    for (int k = 0; k < n; k++) t.Pad(' ');
}
// pdb: hkMonitorStreamAnalyzer::showCombinedThreadSummaryForSingleFrame | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, ustr, medium
// pdb params: node, numThreads, numSpus, os, options
void FUN_00a8ccf0(int a0, int rows, int cols, Stream* s, Info* info)
{
    TextBuf t;
    info->unk0 = FUN_00a8c4d0(a0, 0, info->unk8, info->unk10);
    t.unkC = 0;
    t.unk10 = 0;
    t.unk14 = 0x80000000;
    t.Init(&t.unkC);
    FUN_00943960(&t, "Timer Name");
    int i;
    if (rows > 1 || cols > 0) {
        for (int i = 0; i < rows; i++) {
            Indent(t, info->unk4 * i - t.unk10 + info->unk0);
            FUN_00943960(&t, "Thread %d", i);
        }
        for (int j = 0; j < cols; j++) {
            Indent(t, (j + rows) * info->unk4 - t.unk10 + info->unk0);
            FUN_00943960(&t, "Spu %d", j);
        }
        i = cols + rows;
        if (rows > 1) {
            Indent(t, info->unk4 * i - t.unk10 + info->unk0);
            i++;
            FUN_00943960(&t, "Average Cpu");
        }
        if (cols > 1) {
            Indent(t, info->unk4 * i - t.unk10 + info->unk0);
            FUN_00943960(&t, "Average Spu");
        }
    }
    s->Put(t.unkC);
    FUN_00943960(s, "\n\n");
    FUN_00a8c9e0(s, a0, 0, rows, cols, info);
    t.Done();
    if ((t.unk14 & 0x80000000u) == 0) {
        unsigned int n = t.unk14 & 0x3fffffff;
        Heap* h = (Heap*)TlsGetValue(DAT_010f3170);
        h->Free(t.unkC, n, 0x17);
    }
}
}   // namespace f3m_00a8ccf0

// @f3 0x00a80eb0 (community match, verified in this file)
namespace f3m_00a80eb0 {

struct FUN_00a80eb0_Entry {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int Key()const{return unk00;}
    int Value()const{return unk0C;}
};

struct FUN_00a80eb0_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00a80eb0_Entry* unk18;
    int unk1C;

    int __thiscall FUN_00a80eb0(int value, int fallback);
};

int __cdecl hkString_strCmp(int object, int value);

int __thiscall FUN_00a80eb0_Object::FUN_00a80eb0(int value, int fallback) {
    int index = 0;
    if (unk1C > 0) {
        do {
            if (hkString_strCmp(unk18[index].Key(), value) == 0) {
                return unk18[index].Value();
            }
            ++index;
        } while (index < unk1C);
    }
    return fallback;
}
}   // namespace f3m_00a80eb0

// @f3 0x00a9ea90 (community match, verified in this file)
#include <math.h>
extern "C" void* __cdecl memcpy(void*, const void*, unsigned);

class NiPoint3
{
  public:
    float x, y, z;
    __forceinline NiPoint3()
    {}
    NiPoint3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
    {}
    NiPoint3 operator-(const NiPoint3& other) const;
    NiPoint3 operator+(const NiPoint3&) const;
    inline float Dot(const NiPoint3& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }
};
extern const NiPoint3 NiPoint3_ZERO;
struct ClipMatrix
{
    float values[3][3];
    inline NiPoint3 operator*(const NiPoint3& point) const
    {
        return NiPoint3(values[0][0] * point.x + values[0][1] * point.y + values[0][2] * point.z,
                        values[1][0] * point.x + values[1][1] * point.y + values[1][2] * point.z,
                        values[2][0] * point.x + values[2][1] * point.y + values[2][2] * point.z);
    }
    __forceinline void GetRow(unsigned row, NiPoint3& out) const
    {
        out.x = values[row][0];
        out.y = values[row][1];
        out.z = values[row][2];
    }
};
struct NiCamera
{
    float x, y, z, w;
    inline int ClassifyPoint(const NiPoint3* point)
    {
        float distance = x * point->x + y * point->y + z * point->z - w;
        if (distance < 0.0)
            return 2;
        else if (distance > 0.0)
            return 1;
        else
            return 0;
    }
};
struct ClipVolume
{
    NiCamera planes[6];
    unsigned mask;
};
struct RectangleClip
{
    int unk00, unk04;
    NiPoint3 center;
    float halfWidth, halfHeight;
    ClipMatrix rotation;
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
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    NiPoint3 cached[4];
    int unkd8;
    int unkdc;
    int unke0;
    bool dirty, unkE5, edge0, edge1, edge2, edge3;
    // pdb: BSOcclusionPlane::GetVertices | BSOcclusionPlane.obj | fnv360_0721_beta, call_seq + bridge(call_gap|caller), high
    inline void BSOcclusionPlane_GetVertices(NiPoint3* out)
    {
        if (!dirty)
        {
            memcpy(out, cached, sizeof(cached));
            return;
        }
        NiPoint3 horizontal(halfWidth, 0, 0);
        NiPoint3 vertical(0, 0, halfHeight);
        horizontal = rotation * horizontal;
        vertical = rotation * vertical;
        out[3] = center - horizontal + vertical;
        out[2] = center - horizontal - vertical;
        out[1] = center + horizontal - vertical;
        out[0] = center + horizontal + vertical;
        memcpy(cached, out, sizeof(cached));
        dirty = false;
    }
    bool FUN_00a9e870(NiPoint3*, NiPoint3*, void*, void*);
    bool BSOcclusionPlane_WithinFrustum(ClipVolume* volume, bool testCenter, NiPoint3 point);
};
inline NiPoint3 NiPoint3::operator-(const NiPoint3& other) const
{
    return NiPoint3(x - other.x, y - other.y, z - other.z);
}
// @fnv 0x00c33cf0
// pdb: BSOcclusionPlane::WithinFrustum | BSOcclusionPlane.obj | fnv360_0822_retail, call_seq + bridge(call_gap|caller), high
bool RectangleClip::BSOcclusionPlane_WithinFrustum(ClipVolume* volume, bool testCenter, NiPoint3 point)
{
    NiPoint3 corners[4];
    BSOcclusionPlane_GetVertices(corners);
    int masks[4];
    masks[0] = masks[1] = masks[2] = masks[3] = 0;
    for (int plane = 0; plane < 6; plane++)
    {
        if (bool(volume->mask & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 4; vertex++)
            {
                if (volume->planes[plane].ClassifyPoint(&corners[vertex]) != 2)
                {
                    outside = false;
                }
                else
                {
                    masks[vertex] |= 1 << plane;
                }
            }
            if (outside)
                return false;
        }
    }
    edge0 = (masks[0] & masks[1]) != 0;
    edge1 = (masks[3] & masks[2]) != 0;
    edge2 = (masks[0] & masks[3]) != 0;
    edge3 = (masks[2] & masks[1]) != 0;
    bool needsTest = false;
    if (edge0 && edge1 && edge2 && edge3)
        needsTest = true;
    else if (!edge0 && edge1 && edge2 && edge3)
    {
        bool hit0 = false;
        for (int plane0 = 2; plane0 < 6; plane0++)
        {
            if (FUN_00a9e870(&corners[0], &corners[1], &volume->planes[plane0], volume))
            {
                hit0 = true;
                break;
            }
        }
        if (!hit0)
            needsTest = true;
    }
    else if (edge0 && !edge1 && edge2 && edge3)
    {
        bool hit1 = false;
        for (int plane1 = 2; plane1 < 6; plane1++)
        {
            if (FUN_00a9e870(&corners[3], &corners[2], &volume->planes[plane1], volume))
            {
                hit1 = true;
                break;
            }
        }
        if (!hit1)
            needsTest = true;
    }
    else if (edge0 && edge1 && !edge2 && edge3)
    {
        bool hit2 = false;
        for (int plane2 = 2; plane2 < 6; plane2++)
        {
            if (FUN_00a9e870(&corners[0], &corners[3], &volume->planes[plane2], volume))
            {
                hit2 = true;
                break;
            }
        }
        if (!hit2)
            needsTest = true;
    }
    else if (edge0 && edge1 && edge2 && !edge3)
    {
        bool hit3 = false;
        for (int plane3 = 2; plane3 < 6; plane3++)
        {
            if (FUN_00a9e870(&corners[2], &corners[1], &volume->planes[plane3], volume))
            {
                hit3 = true;
                break;
            }
        }
        if (!hit3)
            needsTest = true;
    }
    if (needsTest)
    {
        for (int planeLast = 2; planeLast < 6; planeLast++)
        {
            if (FUN_00a9e870(&corners[0], &corners[2], &volume->planes[planeLast], volume) ||
                FUN_00a9e870(&corners[1], &corners[3], &volume->planes[planeLast], volume))
                return true;
        }
        if (testCenter)
        {
            NiPoint3 delta = point - center;
            NiPoint3 axis = NiPoint3_ZERO;
            rotation.GetRow(0, axis);
            float vec = fabsf(delta.Dot(axis));
            rotation.GetRow(1, axis);
            float height = fabsf(delta.Dot(axis));
            if (vec <= halfWidth && height <= halfHeight)
                return true;
        }
        return false;
    }
    return true;
}

// @f3 0x00a9f590 (community match, verified in this file)
namespace f3m_00a9f590 {
class NiPoint3OB
{
  public:
    NiPoint3OB()
    {}
    NiPoint3OB(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3OB operator+(const NiPoint3OB& kPt) const
    {
        return NiPoint3OB(x + kPt.x, y + kPt.y, z + kPt.z);
    }
    NiPoint3OB operator-(const NiPoint3OB& kPt) const
    {
        return NiPoint3OB(x - kPt.x, y - kPt.y, z - kPt.z);
    }
    NiPoint3OB& operator*=(float fScale)
    {
        x *= fScale;
        y *= fScale;
        z *= fScale;
        return *this;
    }
    float x;
    float y;
    float z;
    static const NiPoint3OB ZERO;
};

class NiMatrix3OB
{
  public:
    void GetCol(unsigned int uiCol, NiPoint3OB& kCol) const
    {
        kCol.x = m_afEntries[0][uiCol];
        kCol.y = m_afEntries[1][uiCol];
        kCol.z = m_afEntries[2][uiCol];
    }
    float m_afEntries[3][3];
};

class NiOBBOB
{
  public:
    void BSMultiBoundOBB_GetVertices(NiPoint3OB* pkVerts);
    int unk00;
    int unk04;
    int unk08;
    NiPoint3OB m_kCenter;
    float m_afExtents[3];
    NiMatrix3OB m_kBasis;
};

// Fallout 3: output the eight oriented-box corners.
// pdb: BSMultiBoundOBB::GetVertices | BSMultiBoundOBB.obj | fnv360_0822_retail, call_seq + bridge(call_gap|caller), high
void NiOBBOB::BSMultiBoundOBB_GetVertices(NiPoint3OB* pkVerts)
{
    NiPoint3OB kX = NiPoint3OB::ZERO;
    NiPoint3OB kY = NiPoint3OB::ZERO;
    NiPoint3OB kZ = NiPoint3OB::ZERO;
    m_kBasis.GetCol(0, kX);
    kX *= m_afExtents[0];
    m_kBasis.GetCol(1, kY);
    kY *= m_afExtents[1];
    m_kBasis.GetCol(2, kZ);
    kZ *= m_afExtents[2];
    pkVerts[0] = m_kCenter + kX + kY + kZ;
    pkVerts[1] = m_kCenter + kX + kY - kZ;
    pkVerts[2] = m_kCenter + kX - kY + kZ;
    pkVerts[3] = m_kCenter + kX - kY - kZ;
    pkVerts[4] = m_kCenter - kX + kY + kZ;
    pkVerts[5] = m_kCenter - kX + kY - kZ;
    pkVerts[6] = m_kCenter - kX - kY + kZ;
    pkVerts[7] = m_kCenter - kX - kY - kZ;
}
}   // namespace f3m_00a9f590

// @f3 0x00a9dde0 (community match, verified in this file)
namespace f3m_00a9dde0 {
// Stand-in layout for the object at 0x00a9dde0: a three-float point at 0x08,
// a two-float point at 0x14, a 3x3 float matrix at 0x1C, one dword at 0x40 and
// two "dirty" bytes at 0xE4/0xE5.

struct A9DDE0_Point3 {
    float x, y, z;
};

struct A9DDE0_Point2 {
    float u, v;
};

struct A9DDE0_Matrix3 {
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;
};

struct A9DDE0_Obj {
    int unk00;
    int unk04;
    A9DDE0_Point3 pos;      // 0x08
    A9DDE0_Point2 uv;       // 0x14
    A9DDE0_Matrix3 rot;     // 0x1C
    int unk40;              // 0x40
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    unsigned char dirtyA;   // 0xE4
    unsigned char dirtyB;   // 0xE5

    void FUN_00a9dde0(A9DDE0_Obj* dst, int unused);
};

// pdb: BSOcclusionPlane::CopyMembers | BSOcclusionPlane.obj | fnv360_0822_debug, call_seq, medium
// pdb params: pDest, arCloneData
void A9DDE0_Obj::FUN_00a9dde0(A9DDE0_Obj* dst, int unused)
{
    dst->pos = pos;
    dst->dirtyA = 1;
    dst->dirtyB = 1;
    dst->uv = uv;
    dst->dirtyA = 1;
    dst->dirtyB = 1;
    dst->rot = rot;
    dst->dirtyA = 1;
    dst->dirtyB = 1;
    dst->unk40 = unk40;
}
}   // namespace f3m_00a9dde0

// @f3 0x00a9e3b0 (community match, verified in this file)
namespace f3m_00a9e3b0 {
namespace fo3_00a9e3b0 {
extern "C" void* __cdecl memcpy(void*, const void*, unsigned);
class NiPoint3
{
  public:
    float x, y, z;
    __forceinline NiPoint3()
    {}
    NiPoint3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
    {}
    NiPoint3 operator-(const NiPoint3& other) const;
    NiPoint3 operator+(const NiPoint3&) const;
};
inline NiPoint3 NiPoint3::operator-(const NiPoint3& other) const
{
    return NiPoint3(x - other.x, y - other.y, z - other.z);
}
struct ClipMatrix
{
    float values[3][3];
    inline NiPoint3 operator*(const NiPoint3& point) const
    {
        return NiPoint3(values[0][0] * point.x + values[0][1] * point.y + values[0][2] * point.z,
                        values[1][0] * point.x + values[1][1] * point.y + values[1][2] * point.z,
                        values[2][0] * point.x + values[2][1] * point.y + values[2][2] * point.z);
    }
};
struct NiCamera
{
    float x, y, z, w;
    inline int ClassifyPoint(const NiPoint3* point)
    {
        float distance = x * point->x + y * point->y + z * point->z - w;
        if (distance < 0.0)
            return 2;
        else if (distance > 0.0)
            return 1;
        else
            return 0;
    }
};
struct ClipVolume
{
    NiCamera planes[6];
    unsigned mask;
};
struct RectangleClip
{
    int unk00, unk04;
    NiPoint3 center;
    float halfWidth, halfHeight;
    ClipMatrix rotation;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4;
    NiPoint3 cached[4];
    int unkd8, unkdc, unke0;
    bool dirty, unkE5, edge0, edge1, edge2, edge3;
    // pdb: BSOcclusionPlane::GetVertices | BSOcclusionPlane.obj | fnv360_0721_beta, call_seq + bridge(call_gap|caller), high
    inline void BSOcclusionPlane_GetVertices(NiPoint3* out)
    {
        if (!dirty)
        {
            memcpy(out, cached, sizeof(cached));
            return;
        }
        NiPoint3 horizontal(halfWidth, 0, 0);
        NiPoint3 vertical(0, 0, halfHeight);
        horizontal = rotation * horizontal;
        vertical = rotation * vertical;
        out[3] = center - horizontal + vertical;
        out[2] = center - horizontal - vertical;
        out[1] = center + horizontal - vertical;
        memcpy(cached, out, sizeof(cached));
        dirty = false;
    }
    unsigned char FUN_00a9e3b0(ClipVolume* volume);
};
// @fnv 0x00c34350
// pdb: BSOcclusionPlane::WithinFrustumFullTest | BSOcclusionPlane.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aPlanes
unsigned char RectangleClip::FUN_00a9e3b0(ClipVolume* volume)
{
    NiPoint3 corners[4];
    BSOcclusionPlane_GetVertices(corners);
    int masks[4];
    masks[0] = masks[1] = masks[2] = masks[3] = 0;
    unsigned char needsTest = 1;
    for (int plane = 0; plane < 6; plane++)
    {
        if (bool(volume->mask & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 4; vertex++)
            {
                if (volume->planes[plane].ClassifyPoint(&corners[vertex]) != 2)
                    outside = false;
                else
                    masks[vertex] |= 1 << plane;
            }
            if (outside)
                needsTest = 0;
        }
    }
    edge0 = (masks[0] & masks[1]) != 0;
    edge1 = (masks[3] & masks[2]) != 0;
    edge2 = (masks[0] & masks[3]) != 0;
    edge3 = (masks[2] & masks[1]) != 0;
    return needsTest;
}
}  // namespace fo3_00a9e3b0
}   // namespace f3m_00a9e3b0

// @f3 0x00a9fe10 (community match, verified in this file)
namespace f3m_00a9fe10 {
namespace fo3_a9fe10 {
struct Pt3
{
    float x, y, z;
    Pt3()
    {}
    Pt3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    Pt3 operator*(float f) const
    {
        return Pt3(x * f, y * f, z * f);
    }
    Pt3 operator+(const Pt3& r) const;
    Pt3 operator-(const Pt3& r) const;
    static const Pt3 ms_kFirstPoint;
    static const Pt3 ms_kSecondPoint;
    static const Pt3 ms_kThirdPoint;
};

struct Plane4
{
    float nx, ny, nz, d;
    int WhichSide(const Pt3* p) const
    {
        float fDist = nx * p->x + ny * p->y + nz * p->z - d;
        if (fDist < 0.0)
            return 2;
        if (fDist > 0.0)
            return 1;
        return 0;
    }
};

struct Frustum6
{
    Plane4 m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};

struct OccShape
{
    int unk00, unk04, unk08;
    Pt3 kTargetCenter;
    float fScaleMultiplier, m_fGlyphExtent, m_fGlyphWidthInPixels;
    void BSMultiBoundOBB_GetVertices(Pt3* m_pkDeltas)
    {
        Pt3 vX = Pt3::ms_kFirstPoint * fScaleMultiplier;
        Pt3 vY = Pt3::ms_kSecondPoint * m_fGlyphExtent;
        Pt3 vZ = Pt3::ms_kThirdPoint * m_fGlyphWidthInPixels;
        m_pkDeltas[0] = kTargetCenter + vX + vY + vZ;
        m_pkDeltas[1] = kTargetCenter + vX + vY - vZ;
        m_pkDeltas[2] = kTargetCenter + vX - vY + vZ;
        m_pkDeltas[3] = kTargetCenter + vX - vY - vZ;
        m_pkDeltas[4] = kTargetCenter - vX + vY + vZ;
        m_pkDeltas[5] = kTargetCenter - vX + vY - vZ;
        m_pkDeltas[6] = kTargetCenter - vX - vY + vZ;
        m_pkDeltas[7] = kTargetCenter - vX - vY - vZ;
    }
    bool FUN_00a9fe10(Frustum6* pkPlanes);
};

// @fnv 0x00c387f0
// pdb: BSMultiBoundOBB::WithinFrustum | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: aPlanes
bool OccShape::FUN_00a9fe10(Frustum6* pkPlanes)
{
    Pt3 kVerts[8];
    bool bFlat = (m_fGlyphWidthInPixels == 0.0);
    BSMultiBoundOBB_GetVertices(kVerts);
    for (int i = 0; i < 6; i++)
    {
        if (bool(pkPlanes->m_uiActivePlaneMask & (1 << i)))
        {
            bool bAllOut = true;
            for (int j = 0; j < 8; j++)
            {
                if (!bFlat || (j % 2) != 0)
                {
                    if (pkPlanes->m_akPlanes[i].WhichSide(&kVerts[j]) != 2)
                        bAllOut = false;
                }
            }
            if (bAllOut)
                return false;
        }
    }
    return true;
}


}
}   // namespace f3m_00a9fe10

// @f3 0x00a9e870 (community match, verified in this file)
extern const double FUN_00e89398;
namespace f3m_00a9e870 {
namespace f3m_00a9e870 {
struct QP3
{
    float x, y, z;
    QP3()
    {}
    QP3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
    {}
    QP3 operator-(const QP3& o) const
    {
        return QP3(x - o.x, y - o.y, z - o.z);
    }
    QP3 operator+(const QP3& o) const
    {
        return QP3(x + o.x, y + o.y, z + o.z);
    }
    QP3 operator*(float f) const
    {
        return QP3(x * f, y * f, z * f);
    }
    float Dot(const QP3& o) const
    {
        return x * o.x + y * o.y + z * o.z;
    }
};
struct QPlane
{
    QP3 normal;
    float d;
    float Distance(const QP3& p) const
    {
        return p.Dot(normal) - d;
    }
};
struct QFrustum
{
    QPlane planes[6];
    unsigned int mask;
};

// pdb: BSOcclusionPlane::TestLineSegmentAllPlanes | BSOcclusionPlane.obj | fnv360_0822_retail, uconst, low, conflict (skyrim: BSOcclusionShape::TestLineSegment)
// pdb params: akPoint0, akPoint1, akPlane0, akPlanes
bool __stdcall FUN_00a9e870(QP3* a, QP3* b, QPlane* plane, QFrustum* vol)
{
    QP3 dir = *b - *a;
    QP3 n = plane->normal;
    float denom = n.Dot(dir);
    if (denom == 0.0f)
        return false;
    float t = (plane->d - n.Dot(*a)) / denom;
    if (!(t >= 0.0f) || !(t <= 1.0f))
        return false;
    QP3 p = *a + dir * t;
    for (int i = 0; i < 6; i++)
    {
        if (vol->mask & (1 << i))
        {
            if (p.Dot(vol->planes[i].normal) - vol->planes[i].d <= FUN_00e89398)
                return false;
        }
    }
    return true;
}
}
}   // namespace f3m_00a9e870

// @f3 0x00a98230 (community match, verified in this file)
namespace f3m_00a98230 {
namespace matrix6_component_arithmetic {
struct __declspec(align(16)) Vector4 {
 float x,y,z,w;
 __forceinline void Apply(const Vector4& v) { x -= v.x;y -= v.y;z -= v.z;w -= v.w; }
};
struct __declspec(align(16)) Matrix3 {
 Vector4 column0,column1,column2;
 __forceinline void Apply(const Matrix3& v) { column0.Apply(v.column0);column1.Apply(v.column1);column2.Apply(v.column2); }
};
struct __declspec(align(16)) Matrix6 {
 Matrix3 block00,block01,block10,block11;
 __forceinline void Apply(const Matrix6& v) { block00.Apply(v.block00);block01.Apply(v.block01);block10.Apply(v.block10);block11.Apply(v.block11); }
};
// pdb: hkMatrix6Sub | hkMatrix6.obj | fnv360_0822_retail, objrun, medium
// pdb params: aOut, b
void FUN_00a98230(Matrix6* destination,const Matrix6* source) { destination->Apply(*source); }
}
}   // namespace f3m_00a98230

// @f3 0x00a80240 (community match, verified in this file)
namespace f3m_00a80240 {
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};

class hkReferencedObject : public hkBaseObject {
public:
    hkReferencedObject() : m_referenceCount(1) {}
    virtual ~hkReferencedObject() {}

    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};

template <class T>
struct hkArray
{
    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

}   // namespace f3m_00a80240

// @f3 0x00a84ab0 (community match, verified in this file)
namespace f3m_00a84ab0 {
namespace f3m_00a84ab0 {

struct XmlNodeA84 {
    virtual ~XmlNodeA84();
    int unk04;
    int m_type;
    const char* m_name;
    void FUN_00a81200(int a) throw();
};

struct XmlParserA84 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int nextNode(XmlNodeA84** out, void* stream) throw();
};

struct HkClassA84 {
    int FUN_009b0760() throw();
    const char* FUN_009b0490() throw();
};

struct RelocA84 {
    void FUN_009b49d0(void* obj, const char* name) throw();
};

struct BufStateA84 {
    int m_data;
    int m_size;
};

struct BufWrapA84 {
    BufStateA84* m_state;
    BufWrapA84(BufStateA84* s) : m_state(s) {}
    void* FUN_00a84d20(int size, int align) throw();
};

struct ErrBufA84 {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00923070(void** b, int n) throw();
    void FUN_00943710(const char* s) throw();
    void FUN_00943a60() throw();
};

int __cdecl hkString_strCmp(const char* a, const char* b) throw();
int __cdecl FUN_00a83750(HkClassA84* cls, void* obj, BufWrapA84* wrap, XmlNodeA84* elem, XmlParserA84* parser, void* stream, RelocA84* reloc) throw();

struct XmlReaderA84 {
    int unk00;
    int unk04;
    XmlParserA84* m_parser;
    int FUN_00a84ab0(void* stream, BufStateA84* buf, HkClassA84* cls, RelocA84* reloc) throw();
};

int XmlReaderA84::FUN_00a84ab0(void* stream, BufStateA84* buf, HkClassA84* cls, RelocA84* reloc) throw()
{
    XmlNodeA84* elem;
    BufWrapA84 wrap(buf);
    int res = 1;
    if (m_parser->nextNode(&elem, stream) == 0) {
        XmlNodeA84* startElem = (elem->m_type == 1) ? elem : 0;
        if (startElem) {
            if (hkString_strCmp(startElem->m_name, "hkobject") == 0) {
                void* obj = wrap.FUN_00a84d20(cls->FUN_009b0760(), 16);
                int sz = cls->FUN_009b0760();
                wrap.m_state->m_size = (wrap.m_state->m_size + sz + 15) & ~15;
                reloc->FUN_009b49d0(obj, cls->FUN_009b0490());
                res = FUN_00a83750(cls, obj, &wrap, startElem, m_parser, stream, reloc);
            }
        } else {
            XmlNodeA84* bodyElem = (elem->m_type == 3) ? elem : 0;
            if (bodyElem) {
                bodyElem->FUN_00a81200(0);
            } else if (!((elem->m_type == 2) ? elem : 0)) {
                void* sbuf[128];
                ErrBufA84 s;
                s.FUN_00923070(sbuf, 0x200);
                s.FUN_00943710("Unknown element type returned from XML parser.");
                DAT_010f3364->Log(3, 0x6a858ec3, (const char*)sbuf, ".\\Serialize\\Xml\\hkXmlObjectReader.cpp", 0x3cf);
                s.FUN_00943a60();
            }
        }
        if (elem) {
            delete elem;
        }
    }
    return res;
}

}
}   // namespace f3m_00a84ab0

// @f3 0x00a8df20 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace task1586 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
struct Heap{void FUN_008f6d90(void*,unsigned,int);};
struct Node{int unk0;int unk4;int unk8;int unkc;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int children;};
struct NodeArray{Node** data;int size;int GetLogicalSize(){return size;}};
struct Layout{int unk00,pages,width0,width1,extra,height;};
struct Info;
struct Entry{Info* info;int unk04,unk08;};struct EntryList{Entry* data;};
struct FloatArray{float* data;int size,capacity;};
void FUN_00a8d760(NodeArray&,Layout*,EntryList*,float*,FloatArray*);
int FUN_00a8d480(Info*,int,int,int*,int,float,float);
// pdb: hkMonitorStreamAnalyzer::reverseLookupNodeAtTgaSample | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, caller_sim, low
// pdb params: x, y, nodeList, input, frameInfos
int FUN_00a8df20(int x,int y,NodeArray& img,Layout* lay,EntryList* list){
 int levels=img.GetLogicalSize();int pages=lay->pages;if(levels<1)return 0;
 int border=pages>1?0x20:0;if(x<border||x>=lay->height)return 0;
 int w=lay->width1+lay->width0;int h=lay->height-border;int stride=w*levels+lay->extra;int total=stride*pages;if(y<0||y>=total)return 0;
 int idx=total-y-1;int row=idx/stride;int level=idx%stride/w;
 float range;FloatArray arr;arr.data=0;arr.size=0;arr.capacity=0x80000000;
 FUN_00a8d760(img,lay,list,&range,&arr);
 Node** slot=&img.data[level];Info* info=list->data[level].info;
 int result=FUN_00a8d480(info,row,x-border,&(*slot)->children,h,range,arr.data[row]);
 if((arr.capacity&0x80000000u)==0){int cap=arr.capacity&0x3fffffff;Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(arr.data,cap*4,0x17);}return result;
}
}

// @f3 0x00a80290 (community match, verified in this file)
extern const char DAT_00e87e80;
extern const char DAT_00dcc494;
namespace f3m_00a80290 {
namespace PackfileCleanup2032 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);
struct Allocator {
    void FUN_008f6f90(void* memory);
    void FUN_008f6d90(void* memory, int bytes, int category);
};
struct Map12 { void* data; int size; int capacity; void FUN_00922cf0(); };
template<class T> struct Array {
    T* data;
    int size;
    unsigned int capacity;
    void Release() {
        if(!(capacity & 0x80000000u)) {
            int count=capacity & 0x3fffffff;
            Allocator* allocator=(Allocator*)FUN_00d9b080(DAT_010f3170);
            allocator->FUN_008f6d90(data, count*sizeof(T), 0x17);
        }
    }
};
struct Chunk { void* data; int bytes; int category; };
struct Pair { void* first; void* second; };
struct Packfile {
    const void* vtable;
    int unk04;
    void* owned08;
    int unk0C;
    Map12 map10;
    Array<void*> allocations;
    Array<Chunk> chunks;
    Array<Pair> exports;
    Array<Pair> imports;
    void FUN_00a80110();
    void FUN_00a80290();
};
// pdb: hkPackfileData::~hkPackfileData | hkPackfileData.obj | fnv360_0822_retail, call_seq, high
void Packfile::FUN_00a80290() {
    vtable=&DAT_00e87e80;
    FUN_00a80110();
    Allocator* allocator=(Allocator*)FUN_00d9b080(DAT_010f3170);
    for(int i=0;i<allocations.size;++i)
        allocator->FUN_008f6f90(allocations.data[i]);
    for(int i=0;i<chunks.size;++i)
        allocator->FUN_008f6d90(chunks.data[i].data,chunks.data[i].bytes,chunks.data[i].category);
    void* owned=owned08;
    Allocator* ownedAllocator=(Allocator*)FUN_00d9b080(DAT_010f3170);
    ownedAllocator->FUN_008f6f90(owned);
    imports.Release();
    exports.Release();
    chunks.Release();
    allocations.Release();
    map10.FUN_00922cf0();
    vtable=&DAT_00dcc494;
}
}
}   // namespace f3m_00a80290

// @f3 0x00a9e7b0 (community match, verified in this file)
namespace f3m_00a9e7b0 {
namespace f3m_00a9e7b0 {
struct QPt { float x, y, z; };
struct QPlane
{
    float nx, ny, nz, d;
    QPlane();
    QPlane(const QPt& p0, const QPt& p1, const QPt& p2);
    int ClassifyPoint(const QPt* point);
};
struct QFrustum
{
    QPlane planes[6];
    unsigned int mask;
    QFrustum() { mask = 0x3f; }
};
struct QRectClip
{
    int unk00, unk04;
    QPt center;
    float halfWidth, halfHeight;
    float rot[9];
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4;
    QPt cached[4];
    int unkd8, unkdc, unke0;
    bool dirty, unkE5, edge0, edge1, edge2, edge3;
    bool unkEA;
    void FUN_00a9e0b0(QPt point, QFrustum* frustum);
    void BSOcclusionPlane_GetVertices(QPt* out);
    bool FUN_00a9e7b0(QPt point);
};
// pdb: BSOcclusionPlane::ViewerOnCorrectSide | BSOcclusionPlane.obj | fnv360_0822_retail, call_seq, medium
// pdb params: akViewPoint
bool QRectClip::FUN_00a9e7b0(QPt point)
{
    if (unkEA)
        return true;
    QFrustum frustum;
    FUN_00a9e0b0(point, &frustum);
    QPt verts[4];
    BSOcclusionPlane_GetVertices(verts);
    QPlane plane(verts[0], verts[1], verts[2]);
    if (plane.ClassifyPoint(&point) != 2)
        return false;
    else
        return true;
}
}
}   // namespace f3m_00a9e7b0

// @f3 0x00a86830 (community match, verified in this file)
#include <math.h>
namespace MoppConstruction2046 {
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    Vector4(){}
    void Set(float a,float b,float c,float d){x=a;y=b;z=c;w=d;}
    __forceinline void Normalize3() {
        float squared=x*x+y*y+z*z;
        float inverse;
        if(squared!=0.0f) {
            float length=(float)sqrt((double)squared);
            inverse=1.0f/length;
        } else inverse=0.0f;
        x*=inverse;y*=inverse;float originalZ=z;z=originalZ*inverse;w*=inverse;
    }
};
struct Direction {
    Vector4 vector;
    float splitOffset;
    int index;
};
extern Direction DAT_0116ccc0[13];
struct Settings {
    float primary,secondary,tertiary;
    Vector4 limits;
    int depth;
    unsigned char enabled;
    Settings():primary(0.5f),secondary(0.2f),tertiary(1.0f),depth(5){limits.Set(0.2f,0.2f,0.05f,0);enabled=1;}
};
struct RefBase {
    virtual ~RefBase() throw(){}
    unsigned short memorySize,refs;
    RefBase():refs(1){}
};
struct CodeGenerator;struct Mediator;
struct Assembler:RefBase {
    Mediator* mediator;
    void* nodeManager;
    CodeGenerator* codeGenerator;
    void* additional;
    int unk18,unk1C,unk20;
    Vector4 codeInfo;
    Settings parameters;
    Assembler(const Settings&,CodeGenerator*,Mediator*);
    virtual ~Assembler() throw();
    void hkpMoppDefaultAssembler_updateParams(const Settings&) throw();
};
typedef char DirectionStride2046[(sizeof(Direction)==0x20)?1:-1];
typedef char SettingsSize2046[(sizeof(Settings)==0x30)?1:-1];
typedef char AssemblerSize2046[(sizeof(Assembler)==0x70)?1:-1];
__forceinline void SeedDirections() {
    DAT_0116ccc0[0].vector.Set(1,0,0,0);
    DAT_0116ccc0[1].vector.Set(0,1,0,0);
    DAT_0116ccc0[2].vector.Set(0,0,1,0);
    DAT_0116ccc0[0].splitOffset=0;
    DAT_0116ccc0[1].splitOffset=0;
    DAT_0116ccc0[2].splitOffset=0;
    DAT_0116ccc0[3].vector.Set(0,1,1,0);
    DAT_0116ccc0[4].vector.Set(1,0,1,0);
    DAT_0116ccc0[5].vector.Set(1,1,0,0);
    DAT_0116ccc0[3].splitOffset=0.2f;
    DAT_0116ccc0[4].splitOffset=0.2f;
    DAT_0116ccc0[5].splitOffset=0.2f;
    DAT_0116ccc0[6].vector.Set(0,1,-1,0);
    DAT_0116ccc0[7].vector.Set(1,0,-1,0);
    DAT_0116ccc0[8].vector.Set(1,-1,0,0);
    DAT_0116ccc0[6].splitOffset=0.25f;
    DAT_0116ccc0[7].splitOffset=0.25f;
    DAT_0116ccc0[8].splitOffset=0.25f;
    DAT_0116ccc0[9].vector.Set(1,1,1,0);
    DAT_0116ccc0[10].vector.Set(1,1,-1,0);
    DAT_0116ccc0[11].vector.Set(1,-1,1,0);
    DAT_0116ccc0[12].vector.Set(1,-1,-1,0);
    DAT_0116ccc0[9].splitOffset=0.3f;
    DAT_0116ccc0[10].splitOffset=0.32f;
    DAT_0116ccc0[11].splitOffset=0.32f;
    DAT_0116ccc0[12].splitOffset=0.34f;
}
// pdb: hkpMoppDefaultAssembler::hkpMoppDefaultAssembler | hkpMoppDefaultAssembler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: ap, code, mediator
Assembler::Assembler(const Settings& settings,CodeGenerator* code,Mediator* source) {
    SeedDirections();
    for(int i=0;i<13;++i) {
        DAT_0116ccc0[i].vector.Normalize3();
        DAT_0116ccc0[i].index=i;
    }
    hkpMoppDefaultAssembler_updateParams(settings);
    codeGenerator=code;
    mediator=source;
    nodeManager=0;
}
}

// @f3 0x00a81010 (community match, verified in this file)
namespace f3m_00a81010 {
namespace na81010 {
struct Token { virtual ~Token(); int f4; int type; const char* name; };
struct Node;
struct Tree {
    Node* FUN_00a82700();
    Node* FUN_00a82830(Node* n, int k);
    Node* FUN_00a82770(Node* n, void* data, int size);
    Token** FUN_00a826f0(Node* n);
    Node* FUN_00a82750(Node* n);
};
struct Doc { int f0; Tree tree; };
struct Stream;
struct Reader {
    int f0, f4, f8;
    Reader(Stream* s);
    void FUN_00a49be0();
};
int __cdecl hkString_strCmp(const char* a, const char* b);
void __cdecl FUN_009236d0(void* buf, const char* fmt, ...);
struct Parser {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Next(Token** out, Stream* s);
    char pad04[0x10];
    char err[4];
    int FUN_00a81010(int a1, Doc* doc, Stream* s);
};
int Parser::FUN_00a81010(int a1, Doc* doc, Stream* s)
{
    Reader r(s);
    Tree* t = &doc->tree;
    for (Node* n = t->FUN_00a82700(); n; n = t->FUN_00a82830(n, doc->f0))
        ;
    Node* cur;
    {
        int root = a1;
        Node* f = t->FUN_00a82700();
        cur = t->FUN_00a82770(f, &root, 4);
    }
    Token* tok = 0;
    while (!Next(&tok, s))
    {
        if (!tok)
        {
            r.FUN_00a49be0();
            return 0;
        }
        switch (tok->type)
        {
        case 1:
            cur = t->FUN_00a82770(cur, &tok, 4);
            break;
        case 2:
        {
            Token* open = *t->FUN_00a826f0(cur);
            Token* end = tok;
            if (open->type == 1)
            {
                const char* en = end->name;
                if (hkString_strCmp(open->name, en))
                {
                    FUN_009236d0(err, "Expected tag to end '%s' but got '%s'", open->name, end->name);
                    r.FUN_00a49be0();
                    return 1;
                }
            }
            if (open->type != 1)
            {
                FUN_009236d0(err, "Unexpected end tag '%s'", end->name);
                r.FUN_00a49be0();
                return 1;
            }
            cur = t->FUN_00a82750(cur);
            delete tok;
            if (!cur)
            {
                r.FUN_00a49be0();
                return 0;
            }
            break;
        }
        case 3:
            t->FUN_00a82770(cur, &tok, 4);
            break;
        }
    }
    if (cur)
    {
        Token* o = *t->FUN_00a826f0(cur);
        FUN_009236d0(err, "Missing closing tag of '%s'", (o->type == 1 ? o : 0)->name);
    }
    r.FUN_00a49be0();
    return 1;
}
}
}   // namespace f3m_00a81010

// @f3 0x00a9eea0 (community match, verified in this file)
#include <math.h>
extern int DAT_0116d9a0;
namespace f3m_00a9eea0 {
namespace task2112 {
struct NiPoint3 {float x,y,z;NiPoint3(){}NiPoint3(float a,float b,float c):x(a),y(b),z(c){}float Dot(const NiPoint3& p)const{return x*p.x+y*p.y+z*p.z;}NiPoint3 operator+(const NiPoint3& p)const{return NiPoint3(x+p.x,y+p.y,z+p.z);}};
inline NiPoint3 operator*(float s,const NiPoint3& p){return NiPoint3(s*p.x,s*p.y,s*p.z);}
const NiPoint3 NiPoint3_ZERO(0,0,0);
struct ClipPlane {NiPoint3 normal;float constant;void FUN_00832fb0(const NiPoint3*,const NiPoint3*,const NiPoint3*);ClipPlane(const NiPoint3&a,const NiPoint3&b,const NiPoint3&c){FUN_00832fb0(&a,&b,&c);}float Distance(const NiPoint3&p)const{return normal.Dot(p)-constant;}};
struct ClipMatrix {float entries[3][3];void GetColumn(unsigned col,NiPoint3&out)const{out.x=entries[col][0];out.y=entries[col][1];out.z=entries[col][2];}};
struct SSNode {virtual void v0();virtual void v1();virtual const void* GetType();int unk04;NiPoint3 center;float extentX,extentY;ClipMatrix orientation;void BSOcclusionPlane_GetVertices(NiPoint3*);bool BSOcclusionPlane_WithinFrustum(void*,int,NiPoint3);bool BSOcclusionPlane_WithinFrustumDistFirst(void*,const NiPoint3&);__forceinline bool IsExactType(){if(!this)return false;return GetType()==&DAT_0116d9a0;}};
inline float ClipAbs(float f){return (double)(float)fabs((double)f);}
inline float DistanceFromFirst(void*data,int index,const NiPoint3&p){return ((ClipPlane*)data)[index].Distance(p);}
// @fnv 0x00c344c0
// pdb: BSOcclusionPlane::WithinFrustumDistFirst | BSOcclusionPlane.obj | fnv360_0822_retail, udata + bridge(call_seq|call_gap), high
bool SSNode::BSOcclusionPlane_WithinFrustumDistFirst(void* planes, const NiPoint3& point)
{
    NiPoint3 verticesTmp[4];
    BSOcclusionPlane_GetVertices(verticesTmp);
    ClipPlane plane3(verticesTmp[0], verticesTmp[1], verticesTmp[2]);
    float distance2 = plane3.Distance(point);
    NiPoint3 projected8 = point + (-distance2 * plane3.normal);
    distance2 += DistanceFromFirst(planes, 0, point);
    if (distance2 >= -5.0 && distance2 < 5.0)
    {
        NiPoint3 axisX = NiPoint3_ZERO;
        NiPoint3 axisY4 = NiPoint3_ZERO;
        orientation.GetColumn(0, axisX);
        orientation.GetColumn(1, axisY4);
        float x5 = projected8.Dot(axisX) - center.x;
        float y4 = projected8.Dot(axisY4) - center.y;
        if (ClipAbs(x5) <= extentX && ClipAbs(y4) <= extentY)
        {
            if (IsExactType())
                return true;
            else
                return false;
        }
    }
    return BSOcclusionPlane_WithinFrustum(planes, 1, projected8);
}

}
}   // namespace f3m_00a9eea0

// @f3 0x00a9e5d0 (community match, verified in this file)
#include <math.h>
namespace f3m_00a9e5d0 {
namespace task2136 {
inline double NiAbs(float fValue)
{
    return (float)fabs(fValue);
}
inline float NiFunc(float fValue)
{
    return (float)cos(fValue);
}

__forceinline double AbsRef(const float& value)
{
    return (float)fabs(value);
}
__forceinline float ComputeAbs(const float& y)
{
    float arg1 = y;
    float context = AbsRef(arg1);
    return context;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    void Set(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator-(float f) const
    {
        return NiPoint3(x - f, y - f, z - f);
    }
};
struct NiPoint3Ex : NiPoint3
{
    NiPoint3Ex operator-(const NiPoint3& b) const
    {
        NiPoint3Ex result;
        result.x = x - b.x;
        result.y = y - b.y;
        result.z = z - b.z;
        return result;
    }
};

struct FUN_004b4600_Class
{
    void FUN_004b4600();
};
struct M_004b4500 : FUN_004b4600_Class
{
    union
    {
        struct
        {
            float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        };
        float entry[3][3];
    };
    bool NiMatrix3_Inverse(M_004b4500*);
    M_004b4500 Inverse()
    {
        M_004b4500 inverse;
        if (!NiMatrix3_Inverse(&inverse))
            inverse.FUN_004b4600();
        return inverse;
    }
    NiPoint3 FUN_004b4500(const NiPoint3* p)
    {
        NiPoint3 result;
        result.x = m00 * p->x + m01 * p->y + m02 * p->z;
        result.y = m10 * p->x + m11 * p->y + m12 * p->z;
        result.z = m20 * p->x + m21 * p->y + m22 * p->z;
        return result;
    }
};
inline void FUN_004b4600_Class::FUN_004b4600(){ M_004b4500* p=static_cast<M_004b4500*>(this); p->m00=0;p->m10=0;p->m20=0;p->m01=0;p->m11=0;p->m21=0;p->m02=0;p->m12=0;p->m22=0; }
struct SphereInput : NiPoint3Ex
{
    float radius;
};
struct BoxInput
{
    unsigned int kind;
    unsigned int flags;
    NiPoint3 center;
    float halfWidth;
    float halfDepth;
    M_004b4500 rotation;
    unsigned char FUN_00a9e5d0(const SphereInput* sphere);
};

// @fnv 0x00c34890
unsigned char BoxInput::FUN_00a9e5d0(const SphereInput* sphere)
{
    float halfA;
    M_004b4500 rotationB = rotation.Inverse();
    NiPoint3 point7 = rotationB.FUN_004b4500(&(*sphere - center));
    NiPoint3 bound;
    float radius6;
    {
        point7.x = NiAbs(point7.x);
        point7.y = NiAbs(point7.y);
        point7.z = NiAbs(point7.z);
        radius6 = sphere->radius;
        bound.Set(point7.x - radius6, point7.y - radius6, point7.z - radius6);
    }
    if (!(bound.x <= halfWidth) || !(bound.z <= halfDepth) || !(bound.y <= 0.0))
        return false;
    halfA = radius6 * NiFunc(ComputeAbs(bound.y) / radius6);
    return (point7.x - halfA <= halfWidth && point7.y - halfA <= halfDepth) ? 1 : 0;
}

}
}   // namespace f3m_00a9e5d0

// @f3 0x00a81200 (community match, verified in this file)
namespace f3m_00a81200 {
namespace na81200 {
struct hkThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* AllocateStackSlow(int nbytes) throw();
    virtual void PopStack(void* p) throw();
    int unk04[7];
    char* m_current;
    int unk24;
    char* m_previous;
    char* m_end;
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    void* AllocateStack(int nbytes)
    {
        int aligned = (nbytes + 16) & ~15;
        char* current = m_current;
        char* next = current + aligned;
        if (next <= m_end)
        {
            m_current = next;
            return current;
        }
        return AllocateStackSlow(aligned);
    }
    void DeallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_previous)
            PopStack(p);
    }
};
inline hkThreadMemory* GetThreadMemory() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
extern "C" int __cdecl FUN_009233f0(const char* s);
extern "C" void __cdecl FUN_009234e0(void* dst, const void* src, int n);
extern "C" void __cdecl FUN_00901e90(void* arr, int capacity, int stride);
struct CharArray {
    char* m_data;
    int m_size;
    int m_capacityAndFlags;
    void Free()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            GetThreadMemory()->FUN_008f6d90(m_data, m_capacityAndFlags & 0x3fffffff, 0x17);
    }
    __forceinline void SetSize(int n)
    {
        Reserve(n);
        m_size = n;
    }
    __forceinline void Reserve(int n)
    {
        int cap = m_capacityAndFlags & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap * 2;
            FUN_00901e90(this, n < c2 ? c2 : n, 1);
        }
    }
};
struct LocalCharArray : CharArray {
    void Init(int n)
    {
        m_data = (char*)GetThreadMemory()->AllocateStack(n);
        m_size = 0;
        m_capacityAndFlags = n | 0x80000000;
    }
    void Release()
    {
        GetThreadMemory()->DeallocateStack(m_data);
        Free();
    }
};
struct String : CharArray {
    __forceinline void operator=(const char* s)
    {
        if (s && *s)
        {
            int len = FUN_009233f0(s);
            SetSize(len + 1);
            FUN_009234e0(m_data, s, len + 1);
        }
        else
        {
            SetSize(1);
            m_data[0] = 0;
        }
    }
};
extern "C" int __cdecl FUN_00a80d00(char* out, const char* in, int arg);
__forceinline void FreeLocal(char* data, int capacityAndFlags)
{
    GetThreadMemory()->DeallocateStack(data);
    if ((capacityAndFlags & (int)0x80000000) == 0)
    {
        hkThreadMemory* mem = GetThreadMemory();
        mem->FUN_008f6d90(data, capacityAndFlags & 0x3fffffff, 0x17);
    }
}
struct Owner {
    int unk00;
    int unk04;
    int unk08;
    String m_string;
    int FUN_00a81200(int arg);
};
}
int na81200::Owner::FUN_00a81200(int arg)
{
    int capacity = m_string.m_size;
    char* buffer = (char*)GetThreadMemory()->AllocateStack(capacity);
    int flags = capacity | 0x80000000;
    const char* text = m_string.m_data;
    if (FUN_00a80d00(buffer, text, arg) != -1)
    {
        m_string = buffer;
        FreeLocal(buffer, flags);
        return 0;
    }
    FreeLocal(buffer, flags);
    return 1;
}
}   // namespace f3m_00a81200

// @f3 0x00a803e0 (community match, verified in this file)
namespace Arrays601
{
struct Pair { unsigned first, second; };
struct Pool
{
    void FUN_008f6d90(void*, unsigned, int);
    Pair* FUN_008f6d30(unsigned, int);
};
typedef Pool* (__stdcall* GetPool)(unsigned long);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
struct Array
{
    Pair* data;
    int count;
    unsigned capacity;
    __forceinline void Copy(const Array& source, GetPool getPool)
    {
        unsigned flags = capacity;
        int available = flags & 0x3fffffffu;
        if (available < source.count)
        {
            if (!(flags & 0x80000000u))
            {
                Pool* pool = getPool(DAT_010f3170);
                pool->FUN_008f6d90(data, available * sizeof(Pair), 23);
            }
            Pool* pool = getPool(DAT_010f3170);
            data = pool->FUN_008f6d30(source.count * sizeof(Pair), 23);
            capacity = (capacity & 0x40000000u) | source.count;
        }
        int remaining = source.count;
        Pair* out = data;
        count = remaining;
        const Pair* in = source.data;
        if (remaining > 0)
        {
            for (int idx = 0; idx < remaining; idx++)
                out[idx] = in[idx];
        }
    }
};
struct Owner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    Array second;
    Array first;
    void FUN_00a803e0(Array&, Array&) const;
};
void Owner::FUN_00a803e0(Array& a, Array& b) const
{
    GetPool getPool = (GetPool)TlsGetValue;
    a.Copy(first, getPool);
    b.Copy(second, getPool);
}
}

// @f3 0x00a9c7f0 (community match, verified in this file)
namespace Task1963 {
extern char str_00e85ef0[], str_00e8918c[];
struct MoppQueryState
{
    unsigned int primitiveOffset;
    unsigned int properties[1];
};
struct MoppResults
{
    unsigned int* data;
    int count, capacity;
};
void __cdecl FUN_00901f10(MoppResults* array, int elementSize);
struct MoppErrorSink
{
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual int Report(int severity, unsigned int id, const char* message, const char* file, int line);
};
extern MoppErrorSink* DAT_010f3364;
struct MoppFormatter
{
    void* vtable;
    unsigned short memorySize, referenceCount;
    void* writer;
    void FUN_00923070(char* buffer, int length);
    void FUN_00943710(const char* text);
    void FUN_00943a60();
};
struct MoppFindAllVM
{
    MoppResults* results;
    void FUN_00a9c7f0(const MoppQueryState* current, const unsigned char* program);
};
static __forceinline void decodeWord(const unsigned char* __restrict p, unsigned int* __restrict out,
                                     unsigned int index)
{
    out[index] = p[0];
    out[index] <<= 8;
    out[index] += p[1];
}
extern "C" void _ReadWriteBarrier();
static __forceinline void decodeDword(const unsigned char* __restrict p, unsigned int* __restrict out, unsigned index) {
 out[index]=p[0]; out[index]<<=8; out[index]+=p[1]; out[index]<<=8; out[index]+=p[2]; out[index]<<=8; out[index]+=p[3];
}
static unsigned int readBig16(const unsigned char* p)
{
    return (unsigned(p[0]) << 8) + p[1];
}
static unsigned int readBig24(const unsigned char* p)
{
    return (readBig16(p) << 8) + p[2];
}
static unsigned int readBig32(const unsigned char* p)
{
    return (readBig24(p) << 8) + p[3];
}
// @fnv 0x00e66290
// pdb: hkpMoppFindAllVirtualMachine::queryOnTreeRight | hkpMoppFindAllVirtualMachine.obj | tesv_win, objopen_prop, low
void MoppFindAllVM::FUN_00a9c7f0(const MoppQueryState* current, const unsigned char* program)
{
    MoppQueryState local;
    unsigned int primitive;
    for (;;)
    {
        unsigned int op = *program;
        switch (op)
        {
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
            program += program[3] + 4;
            break;
        case 0x20:
        case 0x21:
        case 0x22:
            program += program[2] + 3;
            break;
        case 0x23:
        case 0x24:
        case 0x25:
            program += readBig16(program + 5) + 7;
            break;
        case 0x29:
        case 0x2a:
        case 0x2b:
            program += 7;
            break;
        case 5:
            program += program[1] + 2;
            break;
        case 6:
            program += readBig16(program + 1) + 3;
            break;
        case 7:
            program += readBig24(program + 1) + 4;
            break;
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
            program += 4;
            break;
        case 9: {
            unsigned int offset = program[1];
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.primitiveOffset += offset;
            program += 2;
            break;
        }
        case 10: {
            unsigned int offset = readBig16(program + 1);
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.primitiveOffset += offset;
            program += 3;
            break;
        }
        case 11: {
            unsigned int offset = readBig32(program + 1);
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.primitiveOffset = offset;
            program += 5;
            break;
        }
        case 0x26:
        case 0x27:
        case 0x28:
            program += 3;
            break;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            unsigned int property = program[1];
            program += 2;
            local.properties[op - 96] = property;
            goto propertiesUpdated;
        }
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
            decodeWord(program + 1, local.properties, op - 100);
            program += 3;
            goto propertiesUpdated;
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
            decodeDword(program+1,local.properties,op-104);
            program += 5;
        propertiesUpdated: {
            unsigned int value = local.properties[0];
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.properties[0] = value;
            break;
        }
        case 0:
            return;
        default: {
            MoppFormatter formatter;
            unsigned __int64 buffer[64];
            char* text = reinterpret_cast<char*>(buffer);
            formatter.FUN_00923070(text, 512);
            formatter.FUN_00943710(
                str_00e85ef0);
            DAT_010f3364->Report(3, 0x1298fedd, text, str_00e8918c,
                                     211);
            formatter.FUN_00943a60();
            break;
        }
        case 0x50:
            primitive = program[1];
            goto terminal;
        case 0x51:
            primitive = readBig16(program + 1);
            goto terminal;
        case 0x52:
            primitive = readBig24(program + 1);
            goto terminal;
        case 0x53: {
            struct
            {
                unsigned hi, b3, b4;
            } t;
            t.b3 = program[3];
            t.hi = readBig16(program + 1) << 16;
            t.b3 <<= 8;
            t.b4 = program[4] + t.hi;
            primitive = t.b4 + t.b3;
        }
            goto terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            primitive = op - 0x30;
        terminal:
            primitive += current->primitiveOffset;
            MoppResults* array = results;
            if (array->count == (array->capacity & 0x3fffffff))
                FUN_00901f10(array, 4);
            unsigned int* dest = &array->data[array->count++];
            *dest = primitive;
            return;
        }
    }
}

}

// @f3 0x00a8b1a0 (community match, verified in this file)
extern const double DAT_00e88690;
extern const double DAT_00e88688;
#include <new>
namespace f3m_00a8b1a0 {
extern "C" void _ReadWriteBarrier();
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
extern int (__stdcall* const DAT_00d9b084)(unsigned int, void*);
extern void FUN_00901e90(void* array, int capacity, int elementSize);

struct GeometryPool1561
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    void* freeList50;
    int freeCount54;
    void* FUN_008f6800(int units, int category);
};

template<class T> struct GeometryArray1561
{
    T* data00;
    int size04;
    int capacityAndFlags08;
    GeometryArray1561() : data00(0), size04(0), capacityAndFlags08(0x80000000) {}
    __forceinline void SetSize(int newSize)
    {
        int capacity = capacityAndFlags08 & 0x3fffffff;
        if (capacity < newSize)
        {
            int doubled = capacity + capacity;
            FUN_00901e90(this, doubled > newSize ? doubled : newSize, sizeof(T));
        }
        size04 = newSize;
    }
    __forceinline T& ExpandOne()
    {
        int oldSize = size04;
        int newSize = oldSize + 1;
        int capacity = capacityAndFlags08 & 0x3fffffff;
        if (capacity < newSize)
        {
            int doubled = capacity + capacity;
            FUN_00901e90(this, newSize < doubled ? doubled : newSize, sizeof(T));
        }
        size04 = newSize;
        return data00[oldSize];
    }
};

struct GeometryVector1561
{
    float x;
    float y;
    float z;
    float w;
    void Set(float newX, float newY, float newZ)
    {
        x = newX;
        y = newY;
        z = newZ;
        w = 0.0f;
    }
};

struct GeometryTriangle1561
{
    int a;
    int b;
    int c;
    void Set(int first, int second, int third) { a = first; b = second; c = third; }
};

struct DisplayGeometry1561
{
    GeometryArray1561<GeometryVector1561> vertices00;
    GeometryArray1561<GeometryTriangle1561> triangles0c;
    static void* operator new(size_t)
    {
        GeometryPool1561* pool = static_cast<GeometryPool1561*>(DAT_00d9b080(::DAT_010f3170));
        void* result = pool->freeList50;
        if (result)
        {
            --pool->freeCount54;
            pool->freeList50 = *static_cast<void**>(result);
            return result;
        }
        return pool->FUN_008f6800(3, 0x27);
    }
};


extern void FUN_00a8ad60(DisplayGeometry1561* geometry, int triangle, float radius, float detail);

class IcosphereShape1561
{
public:
    unsigned int unk00;
    unsigned int unk04;
    DisplayGeometry1561* geometry08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float radius6c;
    void FUN_00a8b1a0();
};

// pdb: hkDisplaySphere::buildGeometry | hkDisplaySphere.obj | fnv360_0822_retail, vtable, medium
void IcosphereShape1561::FUN_00a8b1a0()
{
    DisplayGeometry1561* created = new DisplayGeometry1561;
    geometry08 = created;
    _ReadWriteBarrier();
    float radius = radius6c;
    float a = (float)((double)radius * DAT_00e88690);
    float b = (float)((double)radius * DAT_00e88688);
    {
        GeometryArray1561<GeometryVector1561>& vertices = created->vertices00;
        vertices.SetSize(12);
        vertices.data00[0].Set(-a, 0.0f, b);
        vertices.data00[1].Set(a, 0.0f, b);
        vertices.data00[2].Set(-a, 0.0f, -b);
        vertices.data00[3].Set(a, 0.0f, -b);
        vertices.data00[4].Set(0.0f, b, a);
        vertices.data00[5].Set(0.0f, b, -a);
        vertices.data00[6].Set(0.0f, -b, a);
        vertices.data00[7].Set(0.0f, -b, -a);
        vertices.data00[8].Set(b, a, 0.0f);
        vertices.data00[9].Set(-b, a, 0.0f);
        vertices.data00[10].Set(b, -a, 0.0f);
        vertices.data00[11].Set(-b, -a, 0.0f);
    }
    {
        GeometryArray1561<GeometryTriangle1561>& triangles = geometry08->triangles0c;
        triangles.SetSize(20);
        triangles.data00[0].Set(1, 4, 0);
        triangles.data00[1].Set(4, 9, 0);
        triangles.data00[2].Set(4, 5, 9);
        triangles.data00[3].Set(8, 5, 4);
        triangles.data00[4].Set(1, 8, 4);
        triangles.data00[5].Set(1, 10, 8);
        triangles.data00[6].Set(10, 3, 8);
        triangles.data00[7].Set(8, 3, 5);
        triangles.data00[8].Set(3, 2, 5);
        triangles.data00[9].Set(3, 7, 2);
        triangles.data00[10].Set(3, 10, 7);
        triangles.data00[11].Set(10, 6, 7);
        triangles.data00[12].Set(6, 11, 7);
        triangles.data00[13].Set(6, 0, 11);
        triangles.data00[14].Set(6, 1, 0);
        triangles.data00[15].Set(10, 1, 6);
        triangles.data00[16].Set(11, 0, 9);
        triangles.data00[17].Set(2, 11, 9);
        triangles.data00[18].Set(5, 2, 9);
        triangles.data00[19].Set(11, 2, 7);
    }
    for (int i = 0; i < 20; ++i)
        FUN_00a8ad60(geometry08, i, radius, 2.0f);
}
}   // namespace f3m_00a8b1a0

// @f3 0x00a88bf0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a88bf0 {


extern "C" void __cdecl FUN_00a86200();


extern "C" unsigned long (__stdcall* const DAT_00d9b080)(unsigned long);

struct FUN_008f6d90_Obj {
    int unk00;
    int unk04;
    int unk08;

    void FUN_008f6d90(void* arg1, int arg2, int arg3);
};

class FUN_00a88bf0_Class {
public:
    int unk00;
    int unk04;

    int FUN_00a88bf0(unsigned char flag);
};

// pdb: hkpMoppDefaultAssembler::`scalar deleting destructor' | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, vtable, high
int FUN_00a88bf0_Class::FUN_00a88bf0(unsigned char flag)
{
    FUN_00a86200();

    if (flag & 1) {

        unsigned long tlsResult = DAT_00d9b080(DAT_010f3170);

        unsigned short sizeWord = *(unsigned short*)((char*)this + 4);

        ((FUN_008f6d90_Obj*)tlsResult)->FUN_008f6d90(this, sizeWord, 0x28);
    }

    return (int)this;
}
}   // namespace f3m_00a88bf0

// @f3 0x00a80190 (community match, verified in this file)
namespace f3m_00a80190 {
struct FUN_00a80190_TlsObject
{
    int unk00;
    int unk04;
    int unk08;

    void __thiscall FUN_008f6f90(int value);
};

int __cdecl FUN_00923640(int value);

struct FUN_00a80190_Object
{
    int unk00;
    int unk04;
    int unk08;

    void __thiscall FUN_00a80190(int value);
};

void __thiscall FUN_00a80190_Object::FUN_00a80190(int value)
{
    int oldValue = unk08;
    unsigned long tlsValue = f3m_00a833a0::DAT_00d9b080(DAT_010f3170);
    FUN_00a80190_TlsObject* tlsObject =
        reinterpret_cast<FUN_00a80190_TlsObject*>(tlsValue);

    tlsObject->FUN_008f6f90(oldValue);

    unk08 = FUN_00923640(value);
}
}   // namespace f3m_00a80190

// @f3 0x00a82710 (community match, verified in this file)
namespace f3m_00a82710 {
struct FUN_00a82710_Object
{
    int unk00;
    int unk04;
    int unk08;
};

int __stdcall FUN_00a82710(FUN_00a82710_Object* object)
{
    return object->unk08;
}
}   // namespace f3m_00a82710

// @f3 0x00a82c10 (community match, verified in this file)
namespace f3m_00a82c10 {
struct A82C10_Stream {
    int FUN_00922ff0();
};

volatile int A82C10_dummy0;
volatile int A82C10_dummy1;
volatile int A82C10_dummy2;
volatile int A82C10_dummy3;
volatile A82C10_Stream* A82C10_stream;
volatile int A82C10_param;

static __declspec(noinline) void FUN_00a82c10(
    int dummy0,
    int dummy1,
    int dummy2,
    int dummy3,
    A82C10_Stream* stream,
    int param_1)
{
    int ch;
    do {
        ch = stream->FUN_00922ff0();
    } while (ch == 0x20 || ch == 9 || ch == 0x0A || ch == 0x0D);

    char* text = (char*)param_1 + 1;
    while (*text != 0) {
        stream->FUN_00922ff0();
        ++text;
    }
}

void A82C10_probe()
{
    FUN_00a82c10(
        A82C10_dummy0,
        A82C10_dummy1,
        A82C10_dummy2,
        A82C10_dummy3,
        (A82C10_Stream*)A82C10_stream,
        A82C10_param);
}
}   // namespace f3m_00a82c10

// @f3 0x00a9f480 (community match, verified in this file)
namespace f3m_00a9f480 {
struct A9F480_SubObject
{
    void __thiscall FUN_00823d00(int value);
};

struct A9F480_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    A9F480_SubObject unk24;

    void __thiscall BSMultiBoundOBB_LoadBinary(int value);
};

void __stdcall FUN_00aa0a90(int value);

// pdb: BSMultiBoundOBB::LoadBinary | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void __thiscall A9F480_Object::BSMultiBoundOBB_LoadBinary(int value)
{
    FUN_00aa0a90(value);
    unk24.FUN_00823d00(value);
}
}   // namespace f3m_00a9f480

// @f3 0x00a9dcb0 (community match, verified in this file)
namespace f3m_00a9dcb0 {
namespace f3m_00a9dcb0 {
struct Owner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int firstPrimary, firstSecondary, secondPrimary, secondSecondary;
    int FUN_00a9dcb0();
};
// pdb: BSOcclusionPlane::GetJoinedPlaneType | BSOcclusionPlane.obj | fnv360_0822_retail, call_gap, low
int Owner::FUN_00a9dcb0() {
    if (firstPrimary || secondPrimary) return 2;
    if (firstSecondary || secondSecondary) return 1;
    return 0;
}
}
}   // namespace f3m_00a9dcb0

// @f3 0x00a9f190 (community match, verified in this file)
namespace f3m_00a9f190 {
namespace f3m_00a9f190 {
struct Owner {
    unsigned int unk00, unk04, first, second;
    void FUN_008258d0(const Owner* other);
    bool FUN_00a9f190(const Owner* other);
};
// pdb: BSMultiBound::IsEqual | BSMultiBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
bool Owner::FUN_00a9f190(const Owner* other) {
    FUN_008258d0(other);
    if (second == other->second && first == other->first) return true;
    return false;
}
}
}   // namespace f3m_00a9f190

// @f3 0x00a9f170 (community match, verified in this file)
namespace f3m_00a9f170 {
namespace f3m_00a9f170 {

struct Stream {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void SaveLink(void* object);
};

struct Base {
    void* vtable;
    int unk04, unk08;
    void FUN_0078c030(Stream* stream);
};

struct Obj : Base {
    void* link;
    void FUN_00a9f170(Stream* stream);
};

// pdb: BSMultiBound::SaveBinary | BSMultiBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Obj::FUN_00a9f170(Stream* stream)
{
    FUN_0078c030(stream);
    stream->SaveLink(link);
}

}
}   // namespace f3m_00a9f170

// @f3 0x00a80fe0 (community match, verified in this file)
namespace f3m_00a80fe0 {
namespace f3m_00a80fe0 {

extern void __cdecl FUN_00901f10(void*, int);

template<class T> struct Array {
    T* data;
    int size;
    int capacity;
    void append(const T& value)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = value;
        ++size;
    }
};

struct Owner {
    void* vtable;
    int unk04;
    Array<void*> items;
    void FUN_00a80fe0(void* item);
};

void Owner::FUN_00a80fe0(void* item)
{
    items.append(item);
}

}
}   // namespace f3m_00a80fe0

// @f3 0x00a82290 (community match, verified in this file)
extern void* const DAT_00e8839c[];
namespace f3m_00a82290 {
namespace f3m_00a82290 {
void __cdecl FUN_00901e90(void* array, int numElements, int sizeOfElement);
void __cdecl FUN_009234e0(void* dst, const void* src, int n);
struct Blob { const char* data; int size; };
struct hkArray {
    char* data;
    int size;
    int capacityAndFlags;
    hkArray() : data(0), size(0), capacityAndFlags(0x80000000) {}
    __forceinline hkArray(const Blob& blob) : data(0), size(0), capacityAndFlags(0x80000000) { setSize(blob.size); FUN_009234e0(data, blob.data, blob.size); }
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void setSize(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(char));
        }
        size = n;
    }
};
struct hkReferencedObject {
    void* const* vptr;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    hkReferencedObject() : referenceCount(1) {}
};
struct TypedObject : hkReferencedObject {
    int type;
    TypedObject() { type = 2; vptr = DAT_00e8839c; }
};
struct Data : TypedObject {
    hkArray bytes;
    Data(const Blob& blob);
};
Data::Data(const Blob& blob) : bytes(blob)
{
}
}
}   // namespace f3m_00a82290

// @f3 0x00a8d060 (community match, verified in this file)
namespace f3m_00a8d060 {
class A8D060;

struct A8D060_Array {
    A8D060** m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
};

struct A8D060_Owner {
    int unk00;
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
    A8D060_Array unk30;
};

void __cdecl FUN_00901f10(void* array, int elementSize);

class A8D060 {
public:
    float unk00[8];
    unsigned short unk20[8];
    A8D060_Array unk30;
    double unk40;
    A8D060_Owner* unk48;
    int unk4C;
    int unk50;
    int unk54;

    A8D060* __thiscall FUN_00a8d060(A8D060_Owner* owner, int value3, int value4);
};

// pdb: hkMonitorStreamAnalyzer::Node::Node | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_seq, low, conflict (bridge: hkMonitorStreamAnalyzerPrintByTypeInfo::hkMonitorStreamAnalyzerPrintByTypeInfo)
// pdb params: parent, name, type
A8D060* __thiscall A8D060::FUN_00a8d060(A8D060_Owner* owner, int value3, int value4)
{
    unk30.m_data = 0;
    unk30.m_size = 0;
    unk30.m_capacityAndFlags = 0x80000000;
    unk48 = owner;
    unk4C = value3;
    unk50 = 0;
    unk54 = value4;

    if (owner) {
        A8D060_Array* array = &owner->unk30;
        if (array->m_size == (array->m_capacityAndFlags & 0x3FFFFFFF)) {
            FUN_00901f10(array, 4);
        }
        array->m_data[array->m_size] = this;
        array->m_size++;
    }

    for (int i = 0; i < 8; i++) {
        unk00[i] = 0.0f;
        unk20[i] = 0;
    }

    unk40 = 0.0;
    return this;
}
}   // namespace f3m_00a8d060

// @f3 0x00a867c0 (community match, verified in this file)
namespace f3m_00a867c0 {
struct FUN_00a867c0_Inner
{
    int unk00, unk04, unk08;
    int unk0C;
};

struct FUN_00a867c0_Arg
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34;
    unsigned char unk38;
    unsigned char unk39, unk3A, unk3B;
    int unk3C;
    int unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58;
    int unk5C;
};

struct FUN_00a867c0_cls
{
    int unk00, unk04, unk08, unk0C;
    FUN_00a867c0_Inner* unk10;

    int FUN_00a86390(int value);
    int FUN_00a867c0(FUN_00a867c0_Arg* arg);
};

// pdb: hkpMoppDefaultAssembler::assembleJumpChunkCommand | hkpMoppDefaultAssembler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: currentNode
int FUN_00a867c0_cls::FUN_00a867c0(FUN_00a867c0_Arg* arg)
{
    int value = arg->unk40;
    int before = unk10->unk0C;
    FUN_00a86390(value);
    int after = unk10->unk0C;
    arg->unk5C = after;
    arg->unk38 = 1;
    return after - before;
}
}   // namespace f3m_00a867c0

// @f3 0x00a84c30 (community match, verified in this file)
namespace f3m_00a84c30 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long index);
extern unsigned long DAT_010f3170;
void __cdecl FUN_00901e90(void* array, int numElements, int sizeOfElement) throw();
void __cdecl FUN_009234e0(void* dst, const void* src, int n) throw();
struct hkArray {
    char* data;
    int size;
    int capacityAndFlags;
    hkArray() : data(0), size(0), capacityAndFlags(0x80000000) {}
    ~hkArray() throw()
    {
        if (((unsigned)capacityAndFlags & 0x80000000u) == 0) {
            int capacity = capacityAndFlags & 0x3fffffff;
            Heap* heap = FUN_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity, 0x17);
        }
    }
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void reserve(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(char));
        }
    }
};
struct Store {
    int FUN_00a84ab0(int key, hkArray& out, int a, int b) throw();
    int FUN_00a84c30(int key, void* out, int capacity, int a, int b);
};
int Store::FUN_00a84c30(int key, void* out, int capacity, int a, int b)
{
    hkArray buffer;
    buffer.reserve(capacity);
    if (FUN_00a84ab0(key, buffer, a, b) == 0 && buffer.size <= capacity) {
        FUN_009234e0(out, buffer.data, buffer.size);
        return buffer.size;
    }
    return -1;
}
}

// @f3 0x00a9f500 (community match, verified in this file)
namespace f3m_00a9f500 {
namespace f3m_00a9f500 {
struct Point3 {
    float x, y, z;
    bool FUN_0048eb70(const Point3& other) const;   // operator==
};
struct BaseData {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    bool FUN_00aa0b70(const BaseData* other);   // base IsEqual
};
struct Data : BaseData {
    Point3 point24;
    bool FUN_00a9f500(const Data* other);
};
}

// pdb: BSMultiBoundOBB::IsEqual | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
bool f3m_00a9f500::Data::FUN_00a9f500(const Data* other)
{
    bool equal = FUN_00aa0b70(other);
    if (equal)
        equal = point24.FUN_0048eb70(other->point24);
    return equal;
}
}   // namespace f3m_00a9f500

// @f3 0x00a9f140 (community match, verified in this file)
namespace f3m_00a9f140 {
namespace f3m_00a9f140 {
struct BaseData {
    bool FUN_008257d0(const void* other);   // base-class compare/copy
};
struct Target {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(const void* other);
};
struct Data : BaseData {
    int unk00; int unk04; int unk08;
    Target* target;
    bool FUN_00a9f140(const void* other);
};
}

// pdb: BSMultiBound::RegisterStreamables | BSMultiBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
bool f3m_00a9f140::Data::FUN_00a9f140(const void* other)
{
    if (!FUN_008257d0(other))
        return false;
    target->v54(other);
    return true;
}
}   // namespace f3m_00a9f140

// @f3 0x00a9f370 (community match, verified in this file)
namespace f3m_00a9f370 {
namespace f3m_00a9f370 {
void* __cdecl FUN_0089eb90(unsigned int bytes);   // NiMemObject operator new
void __cdecl FUN_0089ebb0(void* p);               // NiMemObject operator delete
class FUN_00a9f1e0 {
public:
    FUN_00a9f1e0();
    static void* operator new(unsigned int bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* p) { FUN_0089ebb0(p); }
    int unk00, unk04, unk08, unk0c;
};
}

f3m_00a9f370::FUN_00a9f1e0* __cdecl FUN_00a9f370()
{
    return new f3m_00a9f370::FUN_00a9f1e0;
}
}   // namespace f3m_00a9f370

// @f3 0x00a82ad0 (community match, verified in this file)
namespace f3m_00a82ad0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a82ad0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a82ad0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a82a90();
    D00a82ad0* FUN_00a82ad0(unsigned int flags);
};
D00a82ad0* D00a82ad0::FUN_00a82ad0(unsigned int flags)
{
    FUN_00a82a90();
    if (flags & 1) {
        D00a82ad0Heap* heap = (D00a82ad0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x1a);
    }
    return this;
}
}

// @f3 0x00a85020 (community match, verified in this file)
namespace f3m_00a85020 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a85020Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a85020 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a84fe0();
    D00a85020* FUN_00a85020(unsigned int flags);
};
// pdb: hkMemoryStreamReader::`scalar deleting destructor' | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high
D00a85020* D00a85020::FUN_00a85020(unsigned int flags)
{
    FUN_00a84fe0();
    if (flags & 1) {
        D00a85020Heap* heap = (D00a85020Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x1a);
    }
    return this;
}
}

// @f3 0x00a85e00 (community match, verified in this file)
namespace f3m_00a85e00 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a85e00Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a85e00 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a85c80();
    D00a85e00* FUN_00a85e00(unsigned int flags);
};
// pdb: hkpMoppCodeGenerator::`scalar deleting destructor' | hkpMoppCodeGenerator.obj | fnv360_0822_retail, vtable, high
D00a85e00* D00a85e00::FUN_00a85e00(unsigned int flags)
{
    FUN_00a85c80();
    if (flags & 1) {
        D00a85e00Heap* heap = (D00a85e00Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x28);
    }
    return this;
}
}

// @f3 0x00a8a290 (community match, verified in this file)
namespace f3m_00a8a290 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a8a290Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a8a290 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a89190();
    D00a8a290* FUN_00a8a290(unsigned int flags);
};
// pdb: hkpMoppDefaultSplitter::`scalar deleting destructor' | hkpMoppDefaultSplitter.obj | fnv360_0721_beta, vtable, high
D00a8a290* D00a8a290::FUN_00a8a290(unsigned int flags)
{
    FUN_00a89190();
    if (flags & 1) {
        D00a8a290Heap* heap = (D00a8a290Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x1e);
    }
    return this;
}
}

// @f3 0x00a84da0 (community match, verified in this file)
namespace f3m_00a84da0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a84da0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a84da0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a82b10();
    D00a84da0* FUN_00a84da0(unsigned int flags);
};
D00a84da0* D00a84da0::FUN_00a84da0(unsigned int flags)
{
    FUN_00a82b10();
    if (flags & 1) {
        D00a84da0Heap* heap = (D00a84da0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 6);
    }
    return this;
}
}

// @f3 0x00a82650 (community match, verified in this file)
namespace f3m_00a82650 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a82650Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a82650 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a82570();
    D00a82650* FUN_00a82650(unsigned int flags);
};
D00a82650* D00a82650::FUN_00a82650(unsigned int flags)
{
    FUN_00a82570();
    if (flags & 1) {
        D00a82650Heap* heap = (D00a82650Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 1);
    }
    return this;
}
}

// @f3 0x00a9da00 (community match, verified in this file)
#include <string.h>
namespace f3m_00a9da00 {

struct FUN_00a9da00_cls {
    int unk00;
    const char* unk04;
    const char* unk08;
    int FUN_00a9da00();
};

int FUN_00a9da00_cls::FUN_00a9da00() {
    int result = 0;
    if (unk08 != 0) {
        switch (*unk08) {
        case 'b':
        case 'c':
        case 'h':
            result = 1;
            break;
        case 'a':
        case 'f':
        case 'i':
        case 'r':
        case 'u':
            result = 4;
            break;
        case 'S':
        case 's':
            if (unk04 != 0)
                result = (int)strlen(unk04) + 1;
            break;
        }
    }
    return result;
}
}   // namespace f3m_00a9da00

// @f3 0x00a82b50 (community match, verified in this file)
namespace f3m_00a82b50 {
struct hkBool {
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
};
static __declspec(noinline) hkBool FUN_00a82b50(int c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
extern int volatile g_char;
extern hkBool g_result;
void caller_of_FUN_00a82b50() { g_result = FUN_00a82b50(g_char); }
}

// @f3 0x00a826f0 (community match, verified in this file)
namespace f3m_00a826f0 {
namespace f3m_00a826f0 {
struct A826Node { int unk00[5]; int unk14; };
int* __stdcall FUN_00a826f0(A826Node* node)
{
    return &node->unk14;
}
}
}   // namespace f3m_00a826f0

// @f3 0x00a82b00 (community match, verified in this file)
namespace f3m_00a82b00 {
namespace f3m_00a82b00 {
int FUN_00a82b00(int a, int b)
{
    return a + b;
}
}
}   // namespace f3m_00a82b00

// @f3 0x00a9d9e0 (community match, verified in this file)
#include <stdarg.h>
namespace f3m_00a9d9e0 {
namespace f3m_00a9d9e0 {
void FUN_00887da0(int level, const char* fmt, va_list args);
void FUN_00a9d9e0(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    FUN_00887da0(1, fmt, args);
}
}
}   // namespace f3m_00a9d9e0

// @f3 0x00a86390 (community match, verified in this file)
namespace f3m_00a86390 {
namespace f3m_00a86390 {
struct A8639Sub { void FUN_00a85f60(int kind, int value); };
struct A8639Owner {
    int unk00[4];
    A8639Sub* unk10;
    int FUN_00a86390(int value);
};
// pdb: hkpMoppDefaultAssembler::addJumpChunk | hkpMoppDefaultAssembler.obj | tesv_win, objrun, medium
int A8639Owner::FUN_00a86390(int value)
{
    unk10->FUN_00a85f60(0xc, value);
    return 3;
}
}
}   // namespace f3m_00a86390

// @f3 0x00a82680 (community match, verified in this file)
namespace f3m_00a82680 {
namespace f3m_00a82680 {
struct A8268Obj {
    int unk00;
    int unk04;
    int unk08;
    A8268Obj* FUN_00a82680(int value);
};
// pdb: hkLifoAllocator::hkLifoAllocator | hkLifoAllocator.obj | tesv_win, hash, low
A8268Obj* A8268Obj::FUN_00a82680(int value)
{
    unk00 = 0;
    unk04 = 0;
    unk08 = value;
    return this;
}
}
}   // namespace f3m_00a82680

// @f3 0x00a923a0 (community match, verified in this file)
namespace f3m_00a923a0 {
namespace f3m_00a923a0 {
struct A923Item { void FUN_009316e0(); };
struct A923List { void FUN_009b2b40(int index, A923Item** item); };
struct A923Owner {
    int unk00[11];
    A923List unk2c;
    void FUN_00a923a0(A923Item* item);
};
// pdb: hkPointerMap<hkpEntity *,int,hkContainerHeapAllocator>::insert | hkpConstraintChainUtil.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpConstraintChainInstance::insertEntityAtFront)
// pdb params: key, val
void A923Owner::FUN_00a923a0(A923Item* item)
{
    unk2c.FUN_009b2b40(0, &item);
    item->FUN_009316e0();
}
}
}   // namespace f3m_00a923a0

// @f3 0x00a9f1c0 (community match, verified in this file)
namespace f3m_00a9f1c0 {
namespace f3m_00a9f1c0 {
struct A9f1Target {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0a();
    virtual void V0b();
    virtual void V0c();
    virtual void V0d();
    virtual void V0e();
    virtual void V0f();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V1a();
    virtual void V1b();
    virtual void V1c();
    virtual void V1d();
    virtual void V1e();
    virtual void V1f();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V2a();
    virtual void V2b();
    virtual void V2c();
    virtual char Vb4(int a);
};
struct A9f1Owner {
    int unk00[3];
    A9f1Target* unk0c;
    char FUN_00a9f1c0(int a);
};
// pdb: BSMultiBound::QPointWithin | BSMultiBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: aPoint
char A9f1Owner::FUN_00a9f1c0(int a)
{
    A9f1Target* t = unk0c;
    if (t)
        return t->Vb4(a);
    return 0;
}
}
}   // namespace f3m_00a9f1c0

// @f3 0x00a82a40 (community match, verified in this file)
namespace f3m_00a82a40 {
namespace f3m_00a82a40 {
struct A82aSrc {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual int V20();
};
struct A82aOwner {
    int unk00;
    int unk04;
    A82aSrc* unk08;
    int unk0c;
    int unk10;
    int FUN_00a82a40();
};
int A82aOwner::FUN_00a82a40()
{
    int r = unk08->V20();
    if (!r)
        unk0c = unk10;
    return r;
}
}
}   // namespace f3m_00a82a40

// @f3 0x00a9f4c0 (community match, verified in this file)
namespace f3m_00a9f4c0 {
namespace f3m_00a9f4c0 {
struct A9f4Sub { void FUN_00823d60(int value); };
struct A9f4Obj {
    int unk00[9];
    A9f4Sub unk24;
    void FUN_00aa0ae0(int value);
    void BSMultiBoundOBB_SaveBinary(int value);
};
// pdb: BSMultiBoundOBB::SaveBinary | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void A9f4Obj::BSMultiBoundOBB_SaveBinary(int value)
{
    FUN_00aa0ae0(value);
    unk24.FUN_00823d60(value);
}
}
}   // namespace f3m_00a9f4c0

// @f3 0x00a826b0 (community match, verified in this file)
namespace f3m_00a826b0 {
namespace f3m_00a826b0 {
struct A826bNode { int unk00[4]; A826bNode* unk10; };
int __stdcall FUN_00a826b0(A826bNode* node)
{
    int count = -1;
    while (node) {
        node = node->unk10;
        ++count;
    }
    return count;
}
}
}   // namespace f3m_00a826b0

// @f3 0x00a82a20 (community match, verified in this file)
namespace f3m_00a82a20 {
namespace f3m_00a82a20 {
struct A82a2Src {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual int V1c(int value);
};
struct A82a2Owner {
    int unk00;
    int unk04;
    A82a2Src* unk08;
    int unk0c;
    int unk10;
    int FUN_00a82a20(int value);
};
int A82a2Owner::FUN_00a82a20(int value)
{
    int r = unk08->V1c(value);
    if (!r)
        unk10 = unk0c;
    return r;
}
}
}   // namespace f3m_00a82a20

// @f3 0x00a97840 (community match, verified in this file)
namespace f3m_00a97840 {
namespace f3m_00a97840 {
struct A9784Vec { float x, y, z, w; };
struct A9784Obj {
    int unk00[6];
    A9784Vec* unk18;
    void FUN_00a97840(A9784Vec* out);
};
// pdb: hkpConvexPieceShape::getFirstVertex | hkpConvexPieceShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: v
void A9784Obj::FUN_00a97840(A9784Vec* out)
{
    const A9784Vec* v = unk18;
    out->x = v->x;
    out->y = v->y;
    out->z = v->z;
    out->w = v->w;
}
}
}   // namespace f3m_00a97840

// @f3 0x00a826d0 (community match, verified in this file)
namespace f3m_00a826d0 {
namespace f3m_00a826d0 {
struct A826dNode { int unk00[2]; A826dNode* unk08; };
struct A826dList { A826dNode* head; };
// pdb: hkLifoAllocator::isEmpty | hkLifoAllocator.obj | tesv_win, objrun_open, low
int __stdcall FUN_00a826d0(A826dList* list)
{
    int count = 0;
    A826dNode* node = list->head;
    while (node) {
        node = node->unk08;
        ++count;
    }
    return count;
}
}
}   // namespace f3m_00a826d0

// @f3 0x00a82a90 (community match, verified in this file)
namespace f3m_00a82a90 {
extern void* DAT_00e88428[];
extern void* DAT_00dcc494[];
struct A82a9Ref {
    virtual void Del(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if ((unsigned short)referenceCount == 0)
                Del(1);
        }
    }
};
struct A82a9Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A82a9Ref* unk08;
    void FUN_00a82a90();
};
void A82a9Obj::FUN_00a82a90()
{
    vtable = DAT_00e88428;
    unk08->removeReference();
    vtable = DAT_00dcc494;
}
}

// @f3 0x00a82b10 (community match, verified in this file)
namespace f3m_00a82b10 {
extern void* DAT_00e8845c[];
extern void* DAT_00dcc494[];
struct A82b1Ref {
    virtual void Del(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if ((unsigned short)referenceCount == 0)
                Del(1);
        }
    }
};
struct A82b1Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A82b1Ref* unk08;
    void FUN_00a82b10();
};
void A82b1Obj::FUN_00a82b10()
{
    vtable = DAT_00e8845c;
    unk08->removeReference();
    vtable = DAT_00dcc494;
}
}

// @f3 0x00a85c80 (community match, verified in this file)
namespace f3m_00a85c80 {
extern void* DAT_00e885ec[];
extern void* DAT_00dcc494[];
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A85c8Heap { void FUN_008f6f90(void* p); };
struct A85c8Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08;
    int unk0c;
    void* unk10;
    void FUN_00a85c80();
};
// pdb: hkpMoppCodeGenerator::~hkpMoppCodeGenerator | hkpMoppCodeGenerator.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void A85c8Obj::FUN_00a85c80()
{
    vtable = DAT_00e885ec;
    void* p = unk10;
    if (p) {
        A85c8Heap* heap = (A85c8Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6f90(p);
    }
    vtable = DAT_00dcc494;
}
}

// @f3 0x00a8c900 (community match, verified in this file)
namespace f3m_00a8c900 {
namespace f3m_00a8c900 {
struct A8c9Item { int unk00; int unk04; int unk08; };
struct A8c9Obj {
    A8c9Item* data;
    int count;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00a8c900();
};
// pdb: hkMonitorStreamAnalyzer::reset | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap, low
void A8c9Obj::FUN_00a8c900()
{
    unk10 = 0;
    for (int i = 0; i < count; ++i)
        data[i].unk04 = 0;
}
}
}   // namespace f3m_00a8c900

// @f3 0x00a82720 (community match, verified in this file)
namespace f3m_00a82720 {
namespace f3m_00a82720 {
struct A8272Node { int unk00; int unk04; int unk08; int unk0c; A8272Node* unk10; };
int __stdcall FUN_00a82720(A8272Node* node)
{
    if (node->unk00)
        return node->unk00;
    while (!node->unk08) {
        node = node->unk10;
        if (!node)
            return 0;
    }
    return node->unk08;
}
}
}   // namespace f3m_00a82720

// @f3 0x00a9c320 (community match, verified in this file)
namespace f3m_00a9c320 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A9c32Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A9c32Obj {
    int unk00[13];
    int* data;
    int size;
    int capacityAndFlags;
    void FUN_00a9c320();
};
// pdb: hkpMoppKDopGeometriesVirtualMachine::~hkpMoppKDopGeometriesVirtualMachine | hkpMoppKDopGeometriesVirtualMachine.obj | fnv360_0822_retail, objrun_prop, low
void A9c32Obj::FUN_00a9c320()
{
    if (!(capacityAndFlags & 0x80000000)) {
        int capacity = capacityAndFlags & 0x3fffffff;
        A9c32Heap* heap = (A9c32Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(data, capacity * sizeof(int), 0x17);
    }
}
}

// @f3 0x00a829a0 (community match, verified in this file)
namespace f3m_00a829a0 {
namespace f3m_00a829a0 {
struct A829Src {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual int V10(char* buf, int size);
};
struct A829Obj {
    int unk00, unk04;
    A829Src* unk08;
    int unk0c;
    int FUN_00a829a0(char* buf, int size);
};
int A829Obj::FUN_00a829a0(char* buf, int size)
{
    int n = unk08->V10(buf, size);
    for (int i = 0; i < n; ++i)
        unk0c += buf[i] == 10;
    return n;
}
}
}   // namespace f3m_00a829a0

// @f3 0x00a84fe0 (community match, verified in this file)
namespace f3m_00a84fe0 {
extern void* DAT_00e88590[];
extern void* DAT_00dcc494[];
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct A84feHeap { void FUN_008f6f90(void* p); };
inline void A84feFree(void* p)
{
    A84feHeap* heap = (A84feHeap*)DAT_00d9b080(DAT_010f3170);
    heap->FUN_008f6f90(p);
}
struct A84feObj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void* unk08;
    int unk0c, unk10, unk14;
    int unk18;
    void FUN_00a84fe0();
};
// pdb: hkMemoryStreamReader::~hkMemoryStreamReader | hkMemoryStreamReader.obj | fnv360_0822_retail, call_seq, high
void A84feObj::FUN_00a84fe0()
{
    vtable = DAT_00e88590;
    if (unk18 == 0 || unk18 == 1) {
        A84feFree(unk08);
    }
    vtable = DAT_00dcc494;
}
}

// @f3 0x00a801c0 (community match, verified in this file)
namespace f3m_00a801c0 {
namespace f3m_00a801c0 {
struct P00a801c0 { int a, b; };
void FUN_00901f10(void* array, int elemSize);
struct A00a801c0 {
    P00a801c0* data;
    int size;
    int capacityAndFlags;
    void pushBack(const P00a801c0& p)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(P00a801c0));
        P00a801c0& e = data[size];
        ++size;
        e = p;
    }
};
struct O00a801c0 {
    int unk00[13];
    A00a801c0 arr;
    void FUN_00a801c0(P00a801c0 p);
};
// pdb: hkPackfileData::addExport | hkPackfileData.obj | tesv_win, objrun_sim, low
void O00a801c0::FUN_00a801c0(P00a801c0 p)
{
    arr.pushBack(p);
}
}
}   // namespace f3m_00a801c0

// @f3 0x00a80200 (community match, verified in this file)
namespace f3m_00a80200 {
namespace f3m_00a80200 {
struct P00a80200 { int a, b; };
void FUN_00901f10(void* array, int elemSize);
struct A00a80200 {
    P00a80200* data;
    int size;
    int capacityAndFlags;
    void pushBack(const P00a80200& p)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(P00a80200));
        P00a80200& e = data[size];
        ++size;
        e = p;
    }
};
struct O00a80200 {
    int unk00[16];
    A00a80200 arr;
    void FUN_00a80200(P00a80200 p);
};
// pdb: hkPackfileData::addImport | hkPackfileData.obj | tesv_win, objrun_sim, low
void O00a80200::FUN_00a80200(P00a80200 p)
{
    arr.pushBack(p);
}
}
}   // namespace f3m_00a80200

// @f3 0x00a867f0 (community match, verified in this file)
namespace f3m_00a867f0 {
namespace f3m_00a867f0 {
struct C00a867f0Src { float x, y, z, w; float a0, a1, a2, a3; int i20; char b24; };
struct C00a867f0Obj {
    int unk00[16];
    float x, y, z, w;
    float a0, a1, a2, a3;
    int i60;
    char b64;
    void hkpMoppDefaultAssembler_updateParams(const C00a867f0Src* s);
};
// pdb: hkpMoppDefaultAssembler::updateParams | hkpMoppDefaultAssembler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(callee_sim), high
void C00a867f0Obj::hkpMoppDefaultAssembler_updateParams(const C00a867f0Src* s)
{
    x = s->x;
    y = s->y;
    z = s->z;
    a0 = s->a0;
    a1 = s->a1;
    a2 = s->a2;
    a3 = s->a3;
    i60 = s->i20;
    b64 = s->b24;
}
}
}   // namespace f3m_00a867f0

// @f3 0x00a82390 (community match, verified in this file)
namespace f3m_00a82390 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
struct A8239Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A8239Array {
    char* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            A8239Heap* heap = (A8239Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity, 0x17);
        }
    }
};
struct A8239Obj {
    A8239Array a;
    A8239Array b;
    void FUN_00a82390();
};
void A8239Obj::FUN_00a82390()
{
    b.Free();
    a.Free();
}
}

// @f3 0x00a9f310 (community match, verified in this file)
namespace f3m_00a9f310 {
namespace f3m_00a9f310 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
struct A9f31Ref {
    virtual void V00();
    virtual void DeleteThis();
    long volatile refCount;
};
struct A9f31Src {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0a();
    virtual void V0b();
    virtual void V0c();
    virtual void V0d();
    virtual void V0e();
    virtual void V0f();
    virtual void V10();
    virtual void V11();
    virtual A9f31Ref* V48(int b);
};
struct A9f31Target { int unk00[3]; A9f31Ref* unk0c; };
struct A9f31Obj {
    int unk00[3];
    A9f31Src* unk0c;
    void FUN_008258b0(A9f31Target* a, int b);
    void FUN_00a9f310(A9f31Target* a, int b);
};
// pdb: BSMultiBound::CopyMembers | BSMultiBound.obj | fnv360_0822_debug, call_seq, medium
// pdb params: pDest, arCloneData
void A9f31Obj::FUN_00a9f310(A9f31Target* a, int b)
{
    FUN_008258b0(a, b);
    A9f31Ref* r = unk0c->V48(b);
    A9f31Ref* old = a->unk0c;
    if (old != r) {
        if (old && InterlockedDecrement(&old->refCount) == 0)
            old->DeleteThis();
        a->unk0c = r;
        if (r)
            InterlockedIncrement(&r->refCount);
    }
}
}
}   // namespace f3m_00a9f310

// @f3 0x00a82e30 (community match, verified in this file)
namespace f3m_00a82e30 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void* DAT_00e8845c[];
struct A82e3Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct FUN_00a81370 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08[6];
    FUN_00a81370() throw();
    static void* operator new(unsigned int n)
    {
        A82e3Heap* heap = (A82e3Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 6);
        ((FUN_00a81370*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
struct A82e3Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    FUN_00a81370* unk08;
    A82e3Obj* FUN_00a82e30(FUN_00a81370* r);
};
A82e3Obj* A82e3Obj::FUN_00a82e30(FUN_00a81370* r)
{
    referenceCount = 1;
    vtable = DAT_00e8845c;
    unk08 = r;
    if (r) {
        if (r->memSizeAndFlags != 0)
            r->referenceCount++;
    } else {
        unk08 = new FUN_00a81370();
    }
    return this;
}
}

// @f3 0x00a82490 (community match, verified in this file)
namespace f3m_00a82490 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
extern void* DAT_00dcc494[];
struct D00a82490Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct D00a82490Array {
    char* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            D00a82490Heap* heap = (D00a82490Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity, 0x17);
        }
    }
};
struct D00a82490Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08[1];
    D00a82490Array arr;
    D00a82490Obj* FUN_00a82490(unsigned int flags);
};
D00a82490Obj* D00a82490Obj::FUN_00a82490(unsigned int flags)
{
    arr.Free();
    vtable = DAT_00dcc494;
    if (flags & 1) {
        D00a82490Heap* heap = (D00a82490Heap*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 1);
    }
    return this;
}
}

// @f3 0x00a9f530 (community match, verified in this file)
namespace f3m_00a9f530 {
namespace f3m_00a9f530 {
void* FUN_0089eb90(unsigned int size);
void FUN_0089ebd0(void* p);
struct FUN_00aa0b10 {
    virtual ~FUN_00aa0b10();
    int unk04[17];
    FUN_00aa0b10();
};
struct A9f53Obj : FUN_00aa0b10 {
    A9f53Obj() {}
    virtual ~A9f53Obj();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ebd0(p); }
};
FUN_00aa0b10* FUN_00a9f530()
{
    return new A9f53Obj();
}
}
}   // namespace f3m_00a9f530

// @f3 0x00a9ea20 (community match, verified in this file)
namespace f3m_00a9ea20 {
namespace f3m_00a9ea20 {
void* FUN_0089eb90(unsigned int size);
void FUN_0089ebd0(void* p);
struct FUN_00a9dcf0 {
    int unk00[63];
    FUN_00a9dcf0();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ebd0(p); }
};
struct A9ea2Obj {
    void FUN_00a9dde0(FUN_00a9dcf0* item, int arg) throw();
    FUN_00a9dcf0* FUN_00a9ea20(int arg);
};
// pdb: BSOcclusionPlane::CreateClone | BSOcclusionPlane.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
FUN_00a9dcf0* A9ea2Obj::FUN_00a9ea20(int arg)
{
    FUN_00a9dcf0* item = new FUN_00a9dcf0();
    FUN_00a9dde0(item, arg);
    return item;
}
}
}   // namespace f3m_00a9ea20

// @f3 0x00a9f400 (community match, verified in this file)
namespace f3m_00a9f400 {
namespace f3m_00a9f400 {
void* FUN_0089eb90(unsigned int size);
void FUN_0089ebd0(void* p);
struct FUN_00a9f1e0 {
    int unk00[4];
    FUN_00a9f1e0();
    static void* operator new(unsigned int n) { return FUN_0089eb90(n); }
    static void operator delete(void* p) { FUN_0089ebd0(p); }
};
struct A9f40Obj {
    void FUN_00a9f310(FUN_00a9f1e0* item, int arg);
    FUN_00a9f1e0* FUN_00a9f400(int arg);
};
// pdb: BSMultiBound::CreateClone | BSMultiBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: arCloneData
FUN_00a9f1e0* A9f40Obj::FUN_00a9f400(int arg)
{
    FUN_00a9f1e0* item = new FUN_00a9f1e0();
    FUN_00a9f310(item, arg);
    return item;
}
}
}   // namespace f3m_00a9f400

// @f3 0x00a80ad0 (community match, verified in this file)
namespace f3m_00a80ad0 {
struct Record2380
{
    const char* name;
    int offset;
};
struct RecordArray2380;
void __cdecl FUN_00901f10(RecordArray2380* array, int elementSize);

struct RecordArray2380
{
    Record2380* data;
    int count, capacityFlags;

    int Capacity() const { return capacityFlags & 0x3fffffff; }
    __forceinline Record2380& Append()
    {
        if (count == Capacity())
            FUN_00901f10(this, sizeof(Record2380));
        return data[count++];
    }
};
int __cdecl FUN_00a80b80(const char* data, int* position);
const char* __cdecl FUN_00a809e0(const char* data, int* position);

struct Parser2380
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    const char* begin;
    const char* end;
    void FUN_00a80ad0(int sectionOffset, RecordArray2380& records);
};

void Parser2380::FUN_00a80ad0(int sectionOffset, RecordArray2380& records)
{
    const char* data = begin + sectionOffset;
    int position = 0;
    while (position < end - begin)
    {
        int offset = FUN_00a80b80(data, &position);
        if (offset == -1)
            break;
        const char* name = FUN_00a809e0(data, &position);
        Record2380& record = records.Append();
        record.name = name;
        record.offset = offset + sectionOffset;
    }
}
}   // namespace f3m_00a80ad0

// @f3 0x00a9d930 (community match, verified in this file)
namespace f3m_00a9d930 {
// @fnv 0x00c33090
int __cdecl FUN_00a9d930(const char* p)
{
    int result = 9;
    if (p)
    {
        switch (*p)
        {
        case 'b':
            result = 0;
            break;
        case 'c':
            result = 1;
            break;
        case 'f':
            result = 5;
            break;
        case 'h':
            result = 2;
            break;
        case 'i':
            result = 3;
            break;
        case 'u':
            result = 4;
            break;
        case 'S':
        case 's':
            result = 6;
            break;
        case 'r':
            result = 7;
            break;
        case 'a':
            result = 8;
            break;
        }
    }
    return result;
}

}   // namespace f3m_00a9d930

// @f3 0x00a9f270 (community match, verified in this file)
namespace f3m_00a9f270 {
namespace fo3_00a9f270 {
class RefObject
{
public:
    virtual void v00();
    virtual void DeleteThis();
    virtual ~RefObject();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class TransformData : public RefObject {};
class FUN_00a9f270 : public RefObject
{
public:
    unsigned int unk08;
    NiPointer<TransformData> m_spTransformData;
    virtual ~FUN_00a9f270();
};

// pdb: BSMultiBound::~BSMultiBound | BSMultiBound.obj | fnv360_0822_retail, call_seq, medium
FUN_00a9f270::~FUN_00a9f270()
{
    m_spTransformData = 0;
}
}
}   // namespace f3m_00a9f270

// @f3 0x00a9dcf0 (community match, verified in this file)
namespace f3m_00a9dcf0 {
struct NiObject
{
    NiObject();
    virtual ~NiObject();
    unsigned int m_uiRefCount;
};
struct NiPoint2
{
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float fX, float fY)
    {
        x = fX;
        y = fY;
    }
};
struct Mat3
{
    float m_afEntries[3][3];
    static const Mat3 IDENTITY;
};
struct NiPlane
{
    NiPlane();
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
};
struct NiFrustumPlanes
{
    NiFrustumPlanes()
    {
        m_uiActivePlaneMask = 0x3f;
    }
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};
struct FUN_00a9dcf0 : NiObject
{
    NiPoint3 kTargetCenter;
    NiPoint2 m_kPoint2;
    Mat3 kRotationBasis;
    int m_uiShapeType;
    NiFrustumPlanes m_kFrustumPlanes;
    NiPoint3 m_kCornerPoints[4];
    NiPoint3 m_kReferencePoint;
    bool m_bIsInFrustum;
    bool m_bIsVisible;
    bool m_bCornerVisible[4];
    bool m_bDecalTextureCreated;
    FUN_00a9dcf0* m_apDecalObjects[4];
    FUN_00a9dcf0();
    virtual ~FUN_00a9dcf0();
};

// @fnv 0x00c335d0
// pdb: BSOcclusionPlane::BSOcclusionPlane | BSOcclusionPlane.obj | fnv360_0822_retail, call_seq, medium
FUN_00a9dcf0::FUN_00a9dcf0()
{
    kTargetCenter = NiPoint3_ZERO;
    m_kPoint2 = NiPoint2(50.0f, 50.0f);
    kRotationBasis = Mat3::IDENTITY;
    m_uiShapeType = 0;
    m_bDecalTextureCreated = true;
    for (int i = 0; i < 4; i++)
        m_apDecalObjects[i] = 0;
}
}   // namespace f3m_00a9dcf0

// @f3 0x00a9f1e0 (community match, verified in this file)
namespace f3m_00a9f1e0 {
namespace task2378 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
};
class A43FF0Object : public NiRefObject
{
  public:
    A43FF0Object();
};
class Shape2378 : public A43FF0Object
{
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
    __forceinline NiPointer(T* object = 0) : m_pObject(object)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class FUN_00a9f1e0 : public A43FF0Object
{
  public:
    FUN_00a9f1e0();
    virtual ~FUN_00a9f1e0();
    unsigned int m_uiBoundFlags;
    NiPointer<Shape2378> pShape;
};

// pdb: BSMultiBound::BSMultiBound | BSMultiBound.obj | fnv360_0822_debug, call_seq, medium
FUN_00a9f1e0::FUN_00a9f1e0(){m_uiBoundFlags=0;pShape=0;}
}
}   // namespace f3m_00a9f1e0

// @f3 0x00a9f0e0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00a9f0e0 {
namespace task2395 {
struct Object {
    virtual void Slot0();
    virtual void DeleteThis();
    long references;
};
struct Stream { Object* FUN_0082a280(); };
struct Owner {
    unsigned int unk00,unk04,unk08;
    Object* object;
    void FUN_0078c030(Stream&);
    void FUN_00a9f0e0(Stream&);
};
// pdb: BSMultiBound::LinkObject | BSMultiBound.obj | fnv360_0822_retail, vtable, medium
// pdb params: arStream
void Owner::FUN_00a9f0e0(Stream& stream) {
    FUN_0078c030(stream);
    Object* replacement=stream.FUN_0082a280();
    Object* previous=object;
    if(previous!=replacement) {
        if(previous) {
            if(InterlockedDecrement(&previous->references)==0)
                previous->DeleteThis();
        }
        object=replacement;
        if(replacement) InterlockedIncrement(&replacement->references);
    }
}
}
}   // namespace f3m_00a9f0e0

// @f3 0x00a80080 (community match, verified in this file)
namespace f3m_00a80080 {
namespace f3m_00a80080 {
struct Pair { int a; int b; };
template <class T> struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    void removeAt(int i) { --size; data[i] = data[size]; }
};
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    hkArray<Pair> pairs;
    void FUN_00a80080(int value);
};
// pdb: hkpWingedEdge::allocateVertex | hkpConvexPenetrationUtil.obj | fnv360_0822_debug, objrun_open, low
void Owner::FUN_00a80080(int value)
{
    for (int i = pairs.size - 1; i >= 0; --i)
        if (pairs.data[i].b == value)
            pairs.removeAt(i);
}
}
}   // namespace f3m_00a80080

// @f3 0x00a8d010 (community match, verified in this file)
namespace f3m_00a8d010 {
struct Pair8d010 {
    int first;
    int second;
};

struct Vec8d010 {
    Pair8d010* data;
    int size;
    int capFlags;
    void __thiscall FUN_00a8d010(int first, int second);
};

void __thiscall Vec8d010::FUN_00a8d010(int first, int second)
{
    Pair8d010 pair;
    pair.first = first;
    pair.second = second;
    if (size == (capFlags & 0x3fffffff))
        Task1963::FUN_00901f10((Task1963::MoppResults*)this, 8);
    data[size] = pair;
    size++;
}
}   // namespace f3m_00a8d010

// @f3 0x00a80db0 (community match, verified in this file)
namespace f3m_00a80db0 {
static __declspec(noinline) char* FUN_00a80db0(char* p)
{
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
        p++;
    return p;
}
volatile char* g_in80db0;
volatile char* g_out80db0;
void caller_of_FUN_00a80db0() { g_out80db0 = FUN_00a80db0((char*)g_in80db0); }
}   // namespace f3m_00a80db0

// @f3 0x00a80cd0 (community match, verified in this file)
namespace f3m_00a80cd0 {
bool __fastcall FUN_00a80cd0(char* s, int c)
{
    if (!s)
        return false;
    char cur = *s;
    if (cur == 0)
        return false;
    do {
        s++;
        if ((char)c == cur)
            return true;
        cur = *s;
    } while (cur != 0);
    return false;
}
}   // namespace f3m_00a80cd0

// @f3 0x00a83270 (community match, verified in this file)
extern const char DAT_00e88540[];
extern const char DAT_00e8853c[];
namespace f3m_00a83270 {
struct Reader83270 {
    int __thiscall FUN_00922ff0();
};
static __declspec(noinline) void FUN_00a82c10(Reader83270* reader, char* text)
{
    for (;;) {
        int c = reader->FUN_00922ff0();
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
            break;
    }
    char* p = text + 1;
    if (*p) {
        do {
            reader->FUN_00922ff0();
            p++;
        } while (*p);
    }
}
int __cdecl FUN_00a82c50(void* stream, const char* data, int length);
int __stdcall FUN_00a83270(void* stream, const char* data, int length)
{
    FUN_00a82c10((Reader83270*)stream, (char*)DAT_00e88540);
    int result = FUN_00a82c50(stream, data, length);
    if (result == 0)
        FUN_00a82c10((Reader83270*)stream, (char*)DAT_00e8853c);
    return result;
}
}   // namespace f3m_00a83270

// @f3 0x00a93000 (community match, verified in this file)
namespace f3m_00a93000 {
struct A93000_StandIn
{
    float value[4];

    void FUN_00a93000(float* matrix, float* vector);
};

void A93000_StandIn::FUN_00a93000(float* matrix, float* vector)
{
    float x = vector[0];
    float y = vector[1];
    float z = vector[2];

    value[0] = y * matrix[4] + x * matrix[0] + z * matrix[8];
    value[1] = y * matrix[5] + x * matrix[1] + z * matrix[9];
    value[2] = y * matrix[6] + x * matrix[2] + z * matrix[10];
    value[3] = y * matrix[7] + x * matrix[3] + z * matrix[11];
}
}   // namespace f3m_00a93000

// @f3 0x00a805a0 (community match, verified in this file)
namespace f3m_00a805a0 {
namespace f3m_00a805a0 {

struct Entry_a805a0
{
    const int* p;
    int v;
};

struct Array_a805a0
{
    Entry_a805a0* m_data;
    int m_size;
    int m_capacityAndFlags;
};

void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);

static __declspec(noinline) void FUN_00a805a0(Array_a805a0* a, int count, const int* src, int value)
{
    int oldSize = a->m_size;
    int newSize = oldSize + count;
    int capacity = a->m_capacityAndFlags & 0x3fffffff;
    if (capacity < newSize)
    {
        int doubled = capacity * 2;
        FUN_00901e90(a, newSize < doubled ? doubled : newSize, 8);
    }
    Entry_a805a0* dst = a->m_data + oldSize;
    a->m_size = newSize;
    for (int i = 0; i < count; i++)
    {
        dst[i].p = src + i;
        dst[i].v = value;
    }
}

Array_a805a0 g_array_a805a0;
int g_values_a805a0[8];
int g_value_a805a0;

void keep_alive_00a805a0()
{
    FUN_00a805a0(&g_array_a805a0, 4, g_values_a805a0, g_value_a805a0);
}

}
}   // namespace f3m_00a805a0

// @f3 0x00a8ad20 (community match, verified in this file)
namespace f3m_00a8ad20 {
namespace f3_2957 {
struct FUN_009a4660 {
 virtual ~FUN_009a4660();
 unsigned int unk04;
 unsigned int unk08;
 unsigned int unk0c;
 unsigned int unk10;
 unsigned int unk14;
 unsigned int unk18;
 unsigned int unk1c;
 unsigned int unk20;
 unsigned int unk24;
 unsigned int unk28;
 unsigned int unk2c;
 unsigned int unk30;
 unsigned int unk34;
 unsigned int unk38;
 unsigned int unk3c;
 unsigned int unk40;
 unsigned int unk44;
 unsigned int unk48;
 unsigned int unk4c;
 unsigned int unk50;
 unsigned int unk54;
 unsigned int unk58;
 unsigned int unk5c;
 FUN_009a4660(int);
};
struct Quaternion { float x,y,z,w; };
struct FUN_00a8ad20 : FUN_009a4660 {
 Quaternion value;
 unsigned int value70,value74;
 FUN_00a8ad20(const Quaternion&,unsigned int,unsigned int);
 virtual ~FUN_00a8ad20();
};
// pdb: hkDisplaySphere::hkDisplaySphere | hkDisplaySphere.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: sphere, xRes, yRes
FUN_00a8ad20::FUN_00a8ad20(const Quaternion& source,unsigned int first,unsigned int second):FUN_009a4660(1),value(source),value70(first),value74(second){}
}
}   // namespace f3m_00a8ad20

// @f3 0x00a80e50 (community match, verified in this file)
namespace f3m_00a80e50 {
struct A80e5Str { int unk00; };
void FUN_009236d0(A80e5Str* s, const char* msg);
struct A80e5Item { int unk00, unk04, unk08; };
struct A80e5Obj {
    virtual void V00(); virtual void V04(); virtual void V08();
    virtual int V0c(A80e5Item** out, A80e5Item* in);
    virtual void V10();
    virtual int V14(A80e5Item* item, int a, A80e5Item* orig);
    int unk04[4];
    A80e5Str unk14;
    int FUN_00a80e50(int a, A80e5Item* b);
};
int A80e5Obj::FUN_00a80e50(int a, A80e5Item* b)
{
    A80e5Item* orig = *(A80e5Item* volatile*)&b;
    if (V0c(&b, orig))
        return 1;
    if (!b)
        return 0;
    if (b->unk08 != 1) {
        FUN_009236d0(&unk14, "Document does not start with an element.");
        return 1;
    }
    return V14(b, a, orig);
}
}   // namespace f3m_00a80e50

// @f3 0x00a9da90 (community match, verified in this file)
#include <string.h>

class MemoryManager
{
public:
    void* Allocate(unsigned int size);
    void Deallocate(void* pointer);
};

extern MemoryManager _g_memoryManager;

struct SettingS
{
    void* pVtbl;
    char* pValue;
    char* pKey;

    SettingS* FUN_00a9da90(const char* apString);
};

extern "C" void FUN_00401e50(char* dst, const char* src);

// pdb: Setting::operator= | Setting.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apString
SettingS* SettingS::FUN_00a9da90(const char* apString)
{
    if (this)
    {
        unsigned int keyLen = pKey ? (unsigned int)strlen(pKey) + 1 : 0;
        if (apString)
        {
            unsigned int len = (unsigned int)strlen(apString);
            char* p = (char*)_g_memoryManager.Allocate(len + keyLen + 1);
            if (p)
            {
                char* value = p + keyLen;
                FUN_00401e50(value, apString);
                pValue = value;
                if (keyLen)
                {
                    strcpy_s(p, keyLen, pKey);
                    *p = 'S';
                    if (*pKey == 'S')
                        _g_memoryManager.Deallocate(pKey);
                    pKey = p;
                }
            }
        }
        else
        {
            pValue = 0;
        }
    }
    return this;
}

// @f3 0x00a82a60 (community match, verified in this file)
namespace f3m_00a82a60 {
namespace f3m_00a82a60 {
struct Shared
{
    int unk00;
    unsigned short m_usActive;
    unsigned short m_usUsers;
};
struct Base
{
    Base() : m_usRefCount(1) {}
    virtual ~Base();
    unsigned short unk04;
    unsigned short m_usRefCount;
};
}

struct FUN_00a82a60 : f3m_00a82a60::Base
{
    FUN_00a82a60(f3m_00a82a60::Shared* shared);
    virtual ~FUN_00a82a60();
    f3m_00a82a60::Shared* m_pShared;
    int m_i0c;
    int m_i10;
};

FUN_00a82a60::FUN_00a82a60(f3m_00a82a60::Shared* shared)
    : m_pShared(shared), m_i0c(0), m_i10(0)
{
    if (shared->m_usActive != 0)
        shared->m_usUsers++;
}
}   // namespace f3m_00a82a60

// @f3 0x00a81370 (community match, verified in this file)
namespace f3m_00a81370 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;

struct Heap
{
    void* FUN_008f6d30(int size, int memClass) throw();
};
struct Base
{
    Base() : m_usRefCount(1) {}
    virtual ~Base();
    unsigned short unk04;
    unsigned short m_usRefCount;
};
struct Array
{
    Array() : m_pData(0), m_iSize(0), m_iCapacityAndFlags(0x80000000) {}
    void* m_pData;
    int m_iSize;
    int m_iCapacityAndFlags;
};
struct String
{
    String()
    {
        Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
        m_pData = (char*)heap->FUN_008f6d30(1, 0x17);
        m_iSize = 1;
        m_iCapacityAndFlags = 1;
        m_pData[0] = 0;
    }
    char* m_pData;
    int m_iSize;
    int m_iCapacityAndFlags;
};
}

struct FUN_00a81370 : f3m_00a81370::Base
{
    FUN_00a81370();
    virtual ~FUN_00a81370();
    f3m_00a81370::Array m_kArray;
    f3m_00a81370::String m_kName;
};

FUN_00a81370::FUN_00a81370()
{
}

// @f3 0x00a80d90 (community match, verified in this file)
namespace f3m_00a80d90 {
static __declspec(noinline) char* FUN_00a80d90(char* result, char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        c = 1;
    else
        c = 0;
    *result = c;
    return result;
}
volatile char input_a80d90;
char* volatile output_a80d90;
void caller_a80d90()
{
    output_a80d90 = FUN_00a80d90(output_a80d90, input_a80d90);
}
}   // namespace f3m_00a80d90

// @f3 0x00a83310 (community match, verified in this file)
namespace f3m_00a83310 {
struct Text83310 { char* data; int length; int capacity; };
struct Entry83310 { int key; int offset; };
struct Entries83310 { Entry83310* data; int size; unsigned int capacity; };
struct Buffer83310 {
    Text83310* text;
    int __thiscall FUN_00a84d20(int length, int alignment);
};
void __cdecl FUN_009234e0(void* dst, const void* src, unsigned int size);
void __cdecl FUN_00901f10(Entries83310* entries, int stride);
static __declspec(noinline) int FUN_00a83310(Entries83310* entries, int key, Text83310* str, Buffer83310* buffer)
{
    int length = str->length;
    if (length - 1 == 1 && str->data[0] == 0)
        return 1;
    int offset = buffer->FUN_00a84d20(length, 16);
    Text83310* output = buffer->text;
    char* source = str->data;
    FUN_009234e0(output->data + offset, source, length);
    if (entries->size == (entries->capacity & 0x3fffffff))
        FUN_00901f10(entries, 8);
    Entry83310* data = entries->data;
    int index = entries->size;
    data[index].key = key;
    data[index].offset = offset;
    ++entries->size;
    buffer->text->length = (buffer->text->length + length + 15) & ~15;
    return 0;
}
Entries83310* volatile inputEntries83310;
Text83310* volatile inputText83310;
Buffer83310* volatile inputBuffer83310;
volatile int inputKey83310;
volatile int output83310;
void caller83310() {
    output83310 = FUN_00a83310(inputEntries83310, inputKey83310, inputText83310, inputBuffer83310);
}
}   // namespace f3m_00a83310

// @f3 0x00a9e540 (community match, verified in this file)
namespace f3m_00a9e540 {

struct RectangleClip {
    void BSOcclusionPlane_GetVertices(NiPoint3* out);
    bool FUN_00a9e540(ClipVolume* volume);
};

struct PlaneOrder32 {
    float x, y, z, w;

    __forceinline int classify(const NiPoint3* point) const {
        double planeZ = z;
        double first = (double)point->x * x;
        float distance = (float)(first + point->y * y + planeZ * point->z - w);
        if (distance < 0.0)
            return 2;
        else if (distance > 0.0)
            return 1;
        else
            return 0;
    }
};

// pdb: BSOcclusionPlane::CompletelyWithinFrustum | BSOcclusionPlane.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aPlanes
bool RectangleClip::FUN_00a9e540(ClipVolume* volume) {
    NiPoint3 corners[4];
    BSOcclusionPlane_GetVertices(corners);
    for (int i = 0; i < 6; i++) {
        if (volume->mask & (1 << i)) {
            NiCamera& plane = volume->planes[i];
            for (int j = 0; j < 4; j++) {
                if (((const PlaneOrder32&)plane).classify(&corners[j]) == 2)
                    return false;
            }
        }
    }
    return true;
}
}   // namespace f3m_00a9e540

// @f3 0x00a9ff80 (community match, verified in this file)
namespace f3m_00a9ff80 {

struct BoxClip33 {
    void BSMultiBoundOBB_GetVertices(NiPoint3* out);
    bool FUN_00a9ff80(ClipVolume* volume);
};

struct PlaneOrder33 {
    float x, y, z, w;

    __forceinline int classify(const NiPoint3* point) const {
        double planeZ = z;
        double first = (double)point->x * x;
        float distance = (float)(first + point->y * y + planeZ * point->z - w);
        if (distance < 0.0)
            return 2;
        else if (distance > 0.0)
            return 1;
        else
            return 0;
    }
};

// pdb: BSMultiBoundOBB::CompletelyWithinFrustum | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: aPlanes
bool BoxClip33::FUN_00a9ff80(ClipVolume* volume) {
    NiPoint3 corners[8];
    BSMultiBoundOBB_GetVertices(corners);
    for (int i = 0; i < 6; i++) {
        if (volume->mask & (1 << i)) {
            NiCamera& plane = volume->planes[i];
            for (int j = 0; j < 8; j++) {
                if (((const PlaneOrder33&)plane).classify(&corners[j]) == 2)
                    return false;
            }
        }
    }
    return true;
}
}   // namespace f3m_00a9ff80

// @f3 0x00a82b80 (community match, verified in this file)
namespace f3m_00a82b80 {
struct Token34 {
    virtual void Destroy(int);
    int unk04;
    int type;
};
struct Parser34 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int Next(Token34** out, void* stream);
    virtual void Remove(Token34* token);
    void Skip(void* stream);
};

static __declspec(noinline) void FUN_00a82b80(Parser34* parser, void* stream) {
    int depth = 1;
    Token34* token = 0;
    int seen = 0;
    while (parser->Next(&token, stream) == 0) {
        if (!token)
            return;
        switch (token->type) {
        case 1:
            ++depth;
            break;
        case 2:
            if (--depth == 0) {
                parser->Remove(token);
                return;
            }
            break;
        case 3:
            if (!seen)
                seen = 1;
            break;
        }
        token->Destroy(1);
        token = 0;
    }
}
void Parser34::Skip(void* stream) {
    FUN_00a82b80(this, stream);
}
}   // namespace f3m_00a82b80

// @f3 0x00a813d0 (community match, verified in this file)
#include <windows.h>
extern const char DAT_00e883bc;
extern const char DAT_00dcc494;
namespace f3m_00a813d0 {
struct Token36 {
    virtual void Destroy(int);
};
struct Pool36 {
    void FUN_008f6d90(void* data, int bytes, int category);
};
typedef Pool36* (__stdcall *GetPool36)(unsigned long);
struct ParserStorage36 {
    const void* vtable;
    int unk04;
    Token36** tokens;
    int count;
    int capacity;
    char* bytes;
    int byteCount;
    int byteCapacity;
    void FUN_00a813d0();
};
void ParserStorage36::FUN_00a813d0() {
    int i = 0;
    vtable = &DAT_00e883bc;
    for (; i < count; ++i) {
        Token36* token = tokens[i];
        if (token)
            token->Destroy(1);
    }
    GetPool36 getPool = (GetPool36)TlsGetValue;
    if (!(byteCapacity & 0x80000000u)) {
        int available = byteCapacity & 0x3fffffff;
        Pool36* pool = getPool(DAT_010f3170);
        pool->FUN_008f6d90(bytes, available, 0x17);
    }
    if (!(capacity & 0x80000000u)) {
        int available = capacity & 0x3fffffff;
        Pool36* pool = getPool(DAT_010f3170);
        pool->FUN_008f6d90(tokens, available * sizeof(Token36*), 0x17);
    }
    vtable = &DAT_00dcc494;
}
}   // namespace f3m_00a813d0

// @f3 0x00a82570 (community match, verified in this file)
#include <windows.h>
extern const char DAT_00dcc494;
namespace f3m_00a82570 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);
struct Pool37 {
    void FUN_008f6d90(void* data, int bytes, int category);
};
typedef Pool37* (__stdcall *GetPool37)(unsigned long);
template<class T> struct Array37 {
    T* data;
    int count;
    unsigned capacity;
    __forceinline void Release(GetPool37 getPool) {
        if (!(capacity & 0x80000000u)) {
            int available = capacity & 0x3fffffff;
            Pool37* pool = getPool(DAT_010f3170);
            pool->FUN_008f6d90(data, available * sizeof(T), 0x17);
        }
    }
};
struct Entry37 {
    Array37<char> first;
    Array37<char> second;
};
struct Storage37 {
    const void* vtable;
    int unk04;
    int unk08;
    Array37<char> bytes;
    Array37<Entry37> entries;
    void FUN_00a82570();
};
void Storage37::FUN_00a82570() {
    GetPool37 getPool = (GetPool37)FUN_00d9b080;
    if (entries.count > 0) {
        int offset = 0;
        int remaining = entries.count;
        do {
            Entry37* entry = (Entry37*)((char*)entries.data + offset);
            entry->second.Release(getPool);
            entry->first.Release(getPool);
            offset += sizeof(Entry37);
        } while (--remaining != 0);
    }
    entries.Release(getPool);
    bytes.Release(getPool);
    vtable = &DAT_00dcc494;
}
}   // namespace f3m_00a82570

// @f3 0x00a82830 (community match, verified in this file)
namespace f3m_00a82830 {
extern "C" __declspec(dllimport) __declspec(nothrow) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
void __cdecl FUN_00901f10(void* array, int elementSize) throw();

struct hkThreadMemory
{
    void FUN_008f6d90(void* p, int size, int memoryClass) throw();
    static hkThreadMemory* get() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    void freeBuffer()
    {
        if ((m_capacityAndFlags & 0x80000000u) == 0) {
            int n = m_capacityAndFlags & 0x3FFFFFFF;
            hkThreadMemory* mem = hkThreadMemory::get();
            mem->FUN_008f6d90(m_data, n * (int)sizeof(T), 0x17);
        }
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3FFFFFFF; }
    void pushBack(const T& item)
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = item;
        m_size++;
    }
};

struct TreeNode
{
    TreeNode* firstChild;
    TreeNode* lastChild;
    TreeNode* next;
    TreeNode* prev;
    TreeNode* parent;
    int payload;
};

struct Tree
{
    TreeNode* root;
    TreeNode* tail;
    int payloadSize;

    TreeNode* FUN_00a82830(TreeNode* node, void (__cdecl* callback)(void*) throw());
};

TreeNode* Tree::FUN_00a82830(TreeNode* node, void (__cdecl* callback)(void*) throw())
{
    TreeNode* replacement = node->next ? node->next : node->prev;
    if (node->prev)
        node->prev->next = node->next;
    else if (node->parent)
        node->parent->firstChild = node->next;
    else if (node == root)
        root = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else if (node->parent)
        node->parent->lastChild = node->prev;
    else if (node == tail)
        tail = node->prev;
    node->parent = 0;

    hkArray<TreeNode*> stack;
    stack.pushBack(node);
    while (stack.m_size) {
        TreeNode* current = stack.m_data[stack.m_size - 1];
        TreeNode* child = current->firstChild;
        stack.m_size--;
        callback(&current->payload);
        int bytes = payloadSize;
        hkThreadMemory* memory = hkThreadMemory::get();
        memory->FUN_008f6d90(current, bytes + 0x14, 0x17);
        for (; child; child = child->next)
            stack.pushBack(child);
    }
    stack.freeBuffer();
    return replacement;
}
}

// @f3 0x00a80240 (community match, verified in this file)
namespace f3m_00a80240 {
struct SubA80240 {
    int a, b, c;
    SubA80240();
};
struct ArrA80240 {
    void* data;
    int size;
    int cap;
    ArrA80240() : data(0), size(0), cap(0x80000000) {}
};
struct BaseA80240 {
    virtual void v0();
    unsigned short memSize;
    short refCount;
    BaseA80240() : refCount(1) {}
};
struct FUN_00a80240 : BaseA80240 {
    int unk08;
    int unk0c;
    SubA80240 sub10;
    ArrA80240 arr1c;
    ArrA80240 arr28;
    ArrA80240 arr34;
    ArrA80240 arr40;
    FUN_00a80240();
};

FUN_00a80240::FUN_00a80240()
    : unk08(0), unk0c(0)
{
}
}   // namespace f3m_00a80240

// @f3 0x00a9e0b0 (community match, verified in this file)
namespace f3m_00a9e0b0 {

struct RcPt
{
    float x, y, z;
    bool operator==(const RcPt& p) const { return x == p.x && y == p.y && z == p.z; }
};

struct RcPlane
{
    RcPt normal;
    float constant;
    RcPlane(const RcPt& a, const RcPt& b, const RcPt& c);
    float Distance(const RcPt& p) const
    {
        return normal.x * p.x + normal.y * p.y + normal.z * p.z - constant;
    }
    int WhichSide(const RcPt& p) const
    {
        float d = Distance(p);
        if (d < 0.0f)
            return 2;
        else if (d > 0.0f)
            return 1;
        else
            return 0;
    }
};

struct RcFrustum
{
    RcPlane planes[6];
    void SetPlane(int i, const RcPlane& p) { planes[i] = p; }
    unsigned int activePlanes;
};

struct RcClip
{
    int unk00, unk04;
    RcPt center;
    float halfWidth, halfHeight;
    float rot[9];
    int unk40;
    RcFrustum cachedFrustum;
    RcPt cached[4];
    RcPt cachedPos;
    bool unkE4, dirty, edge0, edge1, edge2, edge3;
    bool unkEA;
    void FUN_00a9e0b0(RcPt point, RcFrustum* frustum);
    void GetCorners(RcPt* out);
};

// pdb: BSOcclusionPlane::GetFrustumPlanes | BSOcclusionPlane.obj | fnv360_0822_retail, call_gap, medium
// pdb params: akViewPoint, akPlanes
void RcClip::FUN_00a9e0b0(RcPt point, RcFrustum* frustum)
{
    if (!dirty && point == cachedPos)
    {
        *frustum = cachedFrustum;
        return;
    }
    RcPt corners[4];
    GetCorners(corners);
    frustum->activePlanes = 0x3f;
    RcPlane plane(corners[0], corners[1], corners[2]);
    if (plane.WhichSide(point) != 1)
    {
        frustum->SetPlane(0, RcPlane(corners[0], corners[1], corners[2]));
        frustum->activePlanes &= ~2;
        frustum->SetPlane(2, RcPlane(corners[0], corners[1], point));
        frustum->SetPlane(3, RcPlane(corners[2], corners[3], point));
        frustum->SetPlane(4, RcPlane(corners[3], corners[0], point));
        frustum->SetPlane(5, RcPlane(corners[1], corners[2], point));
    }
    else
{
        frustum->SetPlane(0, RcPlane(corners[1], corners[0], corners[2]));
        frustum->activePlanes &= ~2;
        frustum->SetPlane(2, RcPlane(corners[1], corners[0], point));
        frustum->SetPlane(3, RcPlane(corners[3], corners[2], point));
        frustum->SetPlane(4, RcPlane(corners[0], corners[3], point));
        frustum->SetPlane(5, RcPlane(corners[2], corners[1], point));
    }
    if (edge0 == 1)
        frustum->activePlanes &= ~4;
    if (edge1 == 1)
        frustum->activePlanes &= ~8;
    if (edge2 == 1)
        frustum->activePlanes &= ~0x10;
    if (edge3 == 1)
        frustum->activePlanes &= ~0x20;
    cachedPos = point;
    cachedFrustum = *frustum;
    dirty = false;
}
}   // namespace f3m_00a9e0b0

// @f3 0x00a97f50 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern void* DAT_00e35eec;
extern void* FUN_00dcc494;
namespace f3m_00a97f50 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Heap_a97f50 { void FUN_008f6d90(void* p, unsigned int size, int kind); };

struct FUN_00a97f50_cls {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* unk14;
    FUN_00a97f50_cls* FUN_00a97f50(int flags);
};

// pdb: hkpConvexPieceShape::`scalar deleting destructor' | hkpConvexPieceShape.obj | fnv360_0822_retail, vtable_prefix, high
FUN_00a97f50_cls* FUN_00a97f50_cls::FUN_00a97f50(int flags) {
    void** sub = this ? &unk14 : 0;
    *sub = &DAT_00e35eec;
    unk00 = &FUN_00dcc494;
    if (flags & 1) {
        Heap_a97f50* heap = (Heap_a97f50*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(this, unk04, 0x27);
    }
    return this;
}
}   // namespace f3m_00a97f50

// @f3 0x00a82310 (community match, verified in this file)
namespace f3m_00a82310 {
namespace f3m_00a82310 {
void FUN_00901e90(void* array, int n, int elemSize);
void* FUN_009234e0(void* dst, const void* src, unsigned int n);
struct A8231Array {
    char* data;
    int size;
    int capacityAndFlags;
    A8231Array() : data(0), size(0), capacityAndFlags(0x80000000) {}
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void setSizeEmpty(int n)
    {
        if (0 < n)
            FUN_00901e90(this, n < 0 ? 0 : n, 1);
    }
    void fill(const char* s, int len)
    {
        if (0 < len + 1)
            FUN_00901e90(this, len + 1 < 0 ? 0 : len + 1, 1);
        FUN_009234e0(data, s, (size = len + 1, len));
        data[len] = 0;
    }
    void setSize(int n)
    {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = cap * 2;
            int newSize = n < cap2 ? cap2 : n;
            FUN_00901e90(this, newSize, 1);
        }
        size = n;
    }
};
class A8231Base {
public:
    virtual ~A8231Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08;
    A8231Base() throw() { referenceCount = 1; unk08 = 3; }
};
class FUN_00a82310 : public A8231Base {
public:
    A8231Array arr;
    FUN_00a82310(const char* s, int len) throw();
    virtual ~FUN_00a82310();
};
FUN_00a82310::FUN_00a82310(const char* s, int len) throw()
{
    arr.fill(s, len);
}
}
}   // namespace f3m_00a82310

// @f3 0x00a80d00 (community match, verified in this file)
namespace f3m_00a80d00 {
extern "C" int __cdecl FUN_00a80d00(char* out, const char* in, int arg)
{
    char* p = out;
    const char* s = in;
    const char* sep = (const char*)arg;
    bool pending = true;
    if (*s)
    {
        do
        {
            char c = *s++;
            if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
                goto space;
            const char* q = sep;
            if (sep && *sep)
            {
                do
                {
                    if (c == *q++)
                        goto space;
                } while (*q);
            }
            pending = false;
            *p++ = c;
            continue;
        space:
            if (pending)
                continue;
            *p = ' ';
            pending = true;
            p++;
        } while (*s);
    }
    if (p != out && pending)
        p[-1] = 0;
    else
        *p = 0;
    return (int)(p - out);
}
}   // namespace f3m_00a80d00

// @f3 0x00a84d20 (community match, verified in this file)
namespace f3m_00a84d20 {
void __cdecl FUN_00901e90(void* array, int capacity, int elemSize);

struct BufStateA84 {
    char* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline void reserve(int n)
    {
        int cap = m_capacityAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = cap * 2;
            FUN_00901e90(this, n < cap2 ? cap2 : n, 1);
        }
    }
    __forceinline void setSize(int n)
    {
        int oldSize = m_size;
        if (n > oldSize) {
            reserve(n);
            for (int i = oldSize; i < n; i++)
                m_data[i] = 0;
        }
        m_size = n;
    }
};

struct BufWrapA84 {
    BufStateA84* m_state;
    BufWrapA84(BufStateA84* s) : m_state(s) {}
    void* FUN_00a84d20(int size, int align) throw();
};

void* BufWrapA84::FUN_00a84d20(int size, int align) throw()
{
    int old = m_state->m_size;
    m_state->setSize((old + size + align - 1) & ~(align - 1));
    m_state->m_size = old;
    return (void*)old;
}
}   // namespace f3m_00a84d20

// @f3 0x00a824f0 (community match, verified in this file)
extern void* const DAT_00e883d8[];
namespace f3m_00a824f0 {
void __cdecl FUN_00901e90(void* array, int numElements, int sizeOfElement);
void __cdecl FUN_009234e0(void* dst, const void* src, int n);
struct Blob00a824f0 { const char* data; int size; };
struct hkArray00a824f0 {
    char* data;
    int size;
    int capacityAndFlags;
    hkArray00a824f0() : data(0), size(0), capacityAndFlags(0x80000000) {}
    __forceinline hkArray00a824f0(const Blob00a824f0& blob) : data(0), size(0), capacityAndFlags(0x80000000) { setSize(blob.size); FUN_009234e0(data, blob.data, blob.size); }
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void setSize(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(char));
        }
        size = n;
    }
};
struct hkReferencedObject00a824f0 {
    void* const* vptr;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    hkReferencedObject00a824f0() : referenceCount(1) {}
};
struct TypedObject00a824f0 : hkReferencedObject00a824f0 {
    int type;
    TypedObject00a824f0() { type = 1; vptr = DAT_00e883d8; }
};
struct FUN_00a824f0 : TypedObject00a824f0 {
    hkArray00a824f0 bytes;
    hkArray00a824f0 extra;
    FUN_00a824f0(const Blob00a824f0& blob);
};
FUN_00a824f0::FUN_00a824f0(const Blob00a824f0& blob) : bytes(blob)
{
}
}   // namespace f3m_00a824f0

// @f3 0x00a82e90 (community match, verified in this file)
namespace f3m_00a82e90 {
namespace b1821 {

struct XBool {
    char m_bool;
    XBool() {}
    operator bool() const { return m_bool != 0; }
};

struct XIstream {
    XBool FUN_00a49c20() const throw();          // isOk
    XIstream& FUN_00a49f40(bool& v) throw();
    XIstream& FUN_00a4a100(char* v, int n) throw();
    XIstream& FUN_00a4a170(short& v) throw();
    XIstream& FUN_00a4a1c0(unsigned short& v) throw();
    XIstream& FUN_00a4a210(int& v) throw();
    XIstream& FUN_00a4a250(unsigned int& v) throw();
    XIstream& FUN_00a4a290(__int64& v) throw();
    XIstream& FUN_00a4a2d0(unsigned __int64& v) throw();
    XIstream& operator>>(float& v) throw();       // FUN_00a4a060
    XIstream& operator>>(bool& v) throw() { return FUN_00a49f40(v); }
    XIstream& operator>>(short& v) throw() { return FUN_00a4a170(v); }
    XIstream& operator>>(unsigned short& v) throw() { return FUN_00a4a1c0(v); }
    XIstream& operator>>(int& v) throw() { return FUN_00a4a210(v); }
    XIstream& operator>>(unsigned int& v) throw() { return FUN_00a4a250(v); }
    XIstream& operator>>(__int64& v) throw() { return FUN_00a4a290(v); }
    XIstream& operator>>(unsigned __int64& v) throw() { return FUN_00a4a2d0(v); }
};

struct XOstream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00923070(void** b, int n) throw();
    XOstream& operator<<(const char* s) throw();  // FUN_00943710
    XOstream& operator<<(int v) throw();          // FUN_009437d0
    void FUN_00943a60() throw();
};

void __cdecl FUN_00923500(void* p, int v, int n) throw();

}

using namespace b1821;



static __declspec(noinline) int FUN_00a82e90(void* addr, XIstream* is, int type)
{
    float* f = (float*)addr;
    switch (type) {
    case 1: *is >> *(bool*)addr; break;
    case 2: is->FUN_00a4a100((char*)addr, 1); break;
    case 3: { int t; *is >> t; *(char*)addr = (char)t; break; }
    case 4: { int t; *is >> t; *(unsigned char*)addr = (unsigned char)t; break; }
    case 5: *is >> *(short*)addr; break;
    case 6: *is >> *(unsigned short*)addr; break;
    case 7: *is >> *(int*)addr; break;
    case 8: *is >> *(unsigned int*)addr; break;
    case 9: *is >> *(__int64*)addr; break;
    case 10: *is >> *(unsigned __int64*)addr; break;
    case 30: { unsigned __int64 t; *is >> t; *(unsigned int*)addr = (unsigned int)t; break; }
    case 11: *is >> f[0]; break;
    case 12:
    case 13:
        *is >> f[0] >> f[1] >> f[2] >> f[3];
        break;
    case 14:
    case 15:
        FUN_00923500(addr, 0, 0x30);
        *is >> f[0] >> f[1] >> f[2];
        *is >> f[4] >> f[5] >> f[6];
        *is >> f[8] >> f[9] >> f[10];
        break;
    case 16:
        *is >> f[0] >> f[1] >> f[2];
        *is >> f[4] >> f[5] >> f[6] >> f[7];
        *is >> f[8] >> f[9] >> f[10];
        f[3] = f[11] = 0.0f;
        break;
    case 17:
        *is >> f[0] >> f[1] >> f[2] >> f[3];
        *is >> f[4] >> f[5] >> f[6] >> f[7];
        *is >> f[8] >> f[9] >> f[10] >> f[11];
        *is >> f[12] >> f[13] >> f[14] >> f[15];
        break;
    case 18:
        *is >> f[0] >> f[1] >> f[2];
        *is >> f[4] >> f[5] >> f[6];
        *is >> f[8] >> f[9] >> f[10];
        *is >> f[12] >> f[13] >> f[14];
        f[3] = f[7] = f[11] = 0.0f;
        f[15] = 1.0f;
        break;
    default: {
        void* buf[128];
        XOstream s;
        s.FUN_00923070(buf, 0x200);
        s << "Class member unknown / unhandled: " << type;
        DAT_010f3364->Log(3, 0x19fca9ad, (const char*)buf, ".\\Serialize\\Xml\\hkXmlObjectReader.cpp", 0x103);
        s.FUN_00943a60();
        break;
    }
    }
    return is->FUN_00a49c20() ? 0 : 1;
}

volatile int g_b1821_type;
void* volatile g_b1821_addr;
XIstream* volatile g_b1821_is;
volatile int g_b1821_out;

void b1821_caller()
{
    g_b1821_out = FUN_00a82e90(g_b1821_addr, g_b1821_is, g_b1821_type);
}
}   // namespace f3m_00a82e90

// @f3 0x00a80f00 (community match, verified in this file)
namespace f3m_00a80f00 {
struct Holder { int unk00; int unk04; void FUN_00a821d0(int a, char* b, int n); };
struct Reader {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual int v10(char* buf, int a);
    virtual void v14(int n);
    virtual void v18();
    virtual void v1C(int a);
    virtual void v20();
};


// pdb: hkXmlLexAnalyzer::_lexQuotedString | hkXmlLexAnalyzer.obj | tesv_win, objrun_open, low
static __declspec(noinline) void FUN_00a80f00(int count, Reader* self, char* buf, int arg, Holder* h) {
    int i;
    for (i = 0; ; i = 0) {
        if (count > 0) { do { if (buf[i] == '>') break; i++; } while (i < count); }
        if (h) h->FUN_00a821d0(h->unk04, buf, i);
        if (i != count) { self->v20(); self->v14(i + 1); return; }
        self->v1C(arg);
        count = self->v10(buf, arg);
        if (count == 0) return;
    }
}

volatile int g_c; volatile char* g_b; volatile Reader* g_r; volatile int g_a; volatile Holder* g_h;
void caller_of_FUN_00a80f00() {
    FUN_00a80f00(g_c, (Reader*)g_r, (char*)g_b, g_a, (Holder*)g_h);
}
}   // namespace f3m_00a80f00

// @f3 0x00a8d0f0 (community match, verified in this file)
namespace f3m_00a8d0f0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);   // TlsGetValue
struct ThreadMemory { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };
template <class T> struct Array {
    T* data;
    int size;
    int capacityAndFlags;
    __forceinline void Release()
    {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int capacity = capacityAndFlags & 0x3fffffff;
            ThreadMemory* memory = (ThreadMemory*)DAT_00d9b080(DAT_010f3170);
            memory->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};
struct Child { Child* FUN_00a65510(unsigned int flags); };   // deleting destructor
struct Object {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Array<Child*> children;   // 0x30
    void FUN_00a8d0f0();
};
}

// destructor body (called by the deleting wrapper 0xa65510)
// pdb: hkMonitorStreamAnalyzer::Node::~Node | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap_sim, low
void f3m_00a8d0f0::Object::FUN_00a8d0f0()
{
    for (int i = 0; i < children.size; i++) {
        Child* child = children.data[i];
        if (child)
            child->FUN_00a65510(1);
    }
    children.size = 0;
    children.Release();
}

// @f3 0x00a80f70 (community match, verified in this file)
namespace f3m_00a80f70 {

namespace f3m_00a80f70 {
struct Holder { int unk00; int unk04; void FUN_00a821d0(int a, char* b, int n); };
struct Reader {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual int v10(char* buf, int a);
    virtual void v14(int n);
    virtual void v18();
    virtual void v1C(int a);
    virtual void v20();
};

// pdb: hkXmlLexAnalyzer::_lexIdentifier | hkXmlLexAnalyzer.obj | tesv_win, objrun_open, low
static __declspec(noinline) void FUN_00a80f70(int count, Reader* self, char* buf, int arg, Holder* h) {
    int i;
    for (i = 0; ; i = 0) {
        if (count > 0) { do { if (buf[i] == '<') break; i++; } while (i < count); }
        h->FUN_00a821d0(h->unk04, buf, i);
        if (i != count) { self->v20(); self->v14(i); return; }
        self->v1C(arg);
        count = self->v10(buf, arg);
        if (count == 0) return;
    }
}

volatile int g_c; volatile char* g_b; volatile Reader* g_r; volatile int g_a; volatile Holder* g_h;
void caller_of_FUN_00a80f70() {
    FUN_00a80f70(g_c, (Reader*)g_r, (char*)g_b, g_a, (Holder*)g_h);
}
}
}   // namespace f3m_00a80f70

// @f3 0x00a80600 (community match, verified in this file)
namespace f3m_00a80600 {

namespace f3m_00a80600 {
struct Entry_a80600 { const void* key; int value; };
struct Array_a80600 { Entry_a80600* m_data; int m_size; int m_capacityAndFlags; };
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);

static __declspec(noinline) void FUN_00a80600(Array_a80600* a, int count, const Entry_a80600* src)
{
    int n = count;
    int oldSize = a->m_size;
    int newSize = oldSize + n;
    int capacity = a->m_capacityAndFlags & 0x3fffffff;
    if (capacity < newSize)
    {
        int doubled = capacity * 2;
        FUN_00901e90(a, newSize < doubled ? doubled : newSize, 8);
    }
    a->m_size = newSize;
    Entry_a80600* dst = a->m_data + oldSize;
    for (int i = 0; i < n; i++)
    {
        dst[i].key = src + i;
        dst[i].value = src[i].value;
    }
}
Array_a80600 g_array_a80600;
Entry_a80600 g_entries_a80600[8];
void keep_alive_00a80600()
{
    FUN_00a80600(&g_array_a80600, 4, g_entries_a80600);
}

}
}   // namespace f3m_00a80600

// @f3 0x00a832b0 (community match, verified in this file)
namespace f3m_00a832b0 {
struct A832B0_Obj
{
    virtual void vf00(int value);
    int unk04;
    int unk08;
    int unk0c;

    __forceinline A832B0_Obj* asKind2() { return unk08 == 2 ? this : 0; }
};

struct A832B0_Owner
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c(A832B0_Obj** out, A832B0_Obj* item);
};

int __cdecl hkString_strCmp(int a, int b);

static __declspec(noinline) int FUN_00a832b0(A832B0_Owner* owner, A832B0_Obj* item, A832B0_Obj* other)
{
    int result = 0;
    A832B0_Obj* found = 0;

    owner->vf0c(&found, item);

    A832B0_Obj* kind2 = found->asKind2();
    if (kind2) {
        int b = other->unk0c;
        int a = kind2->unk0c;
        if (hkString_strCmp(a, b) != 0)
            result = 1;
    } else {
        result = 1;
    }

    if (found)
        found->vf00(1);

    return result;
}

volatile int g_o; volatile int g_i; volatile int g_x; volatile int g_out;
void caller_of_FUN_00a832b0()
{
    g_out = FUN_00a832b0((A832B0_Owner*)g_o, (A832B0_Obj*)g_i, (A832B0_Obj*)g_x);
}
}   // namespace f3m_00a832b0

// @f3 0x00a85d20 (community match, verified in this file)
extern int DAT_01268b9c;
namespace f3m_00a85d20 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct FUN_00a85d20_Arr {
    void* data;
    int size;
    volatile unsigned int capacity;
};
struct FUN_00a85d20_Obj {
    void* vptr;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    volatile float unk10;
    volatile float unk14;
    volatile float unk18;
    volatile float unk1c;
    FUN_00a85d20_Arr arr;
};
struct FUN_00a85d20_Heap {
    void* FUN_008f6d30(int bytes, int align);
    void FUN_008f6f90(void* memory);
};
struct FUN_00a85d20_Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00a85d20_Obj* FUN_00a85d20();
};

void FUN_00cb1260(void* dst, const void* src, int bytes);
void __cdecl FUN_00901e90(void* arr, int capacity, int stride);

// pdb: hkpMoppCodeGenerator::compileCode | hkpMoppCodeGenerator.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_00a85d20_Obj* FUN_00a85d20_Owner::FUN_00a85d20()
{
    FUN_00a85d20_Heap* heap;
    long array = unk0c;
    heap = (FUN_00a85d20_Heap*)TlsGetValue(DAT_010f3170);
    FUN_00a85d20_Obj* obj = (FUN_00a85d20_Obj*)heap->FUN_008f6d30(0x30, 0x28);
    FUN_00a85d20_Arr& released = obj->arr;
    obj->unk04 = 0x30;
    obj->unk06 = 1;
    obj->vptr = &DAT_01268b9c;
    released.data = 0;
    released.size = 0;
    released.capacity = 0x80000000;
    obj->unk10 = obj->unk14 = obj->unk18 = obj->unk1c = 0.0f;
    if ((int)(released.capacity & 0x3fffffff) < array)
        FUN_00901e90(&released, array, 1);
    int source = (0x3fffffff & released.capacity);
    if (source < array) {
        long heap2 = 2 * source;
        if ((int)(unsigned int)array >= heap2)
            heap2 = array;
        FUN_00901e90(&released, heap2, 1);
    }
    released.size = array;
    FUN_00cb1260(obj->arr.data, (const void*)(unk10 - unk0c + unk08), array);
    void* s;
    s = (void*)unk10;
    FUN_00a85d20_Heap* nc = (FUN_00a85d20_Heap*)TlsGetValue(DAT_010f3170);
    nc->FUN_008f6f90(s);
    unk10 = 0;
    unk0c = 0;
    unk08 = array;
    return obj;
}
}   // namespace f3m_00a85d20

// @f3 0x00a97860 (community match, verified in this file)
namespace f3m_00a97860 {
namespace f3m_00a97860 {
struct Vec4_7860 { float x, y, z, w; };

struct Obj7860 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    Vec4_7860* data;
    int count;
    Vec4_7860* FUN_00a97860(Vec4_7860* out);
};

// pdb: hkpConvexPieceShape::getCollisionSpheresImpl | hkpConvexPieceShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: sphereBuffer
Vec4_7860* Obj7860::FUN_00a97860(Vec4_7860* out)
{
    int i = 0;
    if (count > 0) {
        float* dst = &out->w;
        unsigned int off = 0;
        do {
            const float* src = (const float*)((const char*)data + off);
            dst[-3] = src[0];
            dst[-2] = src[1];
            dst[-1] = src[2];
            dst[0] = src[3];
            dst[0] = unk10;
            ++i;
            dst += 4;
            off += 16;
        } while (i < count);
    }
    return out;
}
}
}   // namespace f3m_00a97860

// @f3 0x00a8bd50 (community match, verified in this file)
namespace N {
extern unsigned int DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
}
struct Heap {
    void __thiscall FUN_008f6d90(void* data, int size, int type);
};
struct Array { void* data; int length; unsigned int capacity:30; unsigned int locked:1; unsigned int borrowed:1; };
void __cdecl FUN_00a8bd50(Array* param)
{
    if (param->borrowed)
        return;
    unsigned int size = param->capacity;
    unsigned long heap = (unsigned long)N::DAT_00d9b080(N::DAT_010f3170);
    void* data = param->data;
    size = size * 16;
    ((Heap*)heap)->FUN_008f6d90(data, (int)size, 0x17);
}

// @f3 0x00a9fb50 (community match, verified in this file)
namespace f3m_00a9fb50 {
struct S00a9fb50_Bound
{
    NiPoint3 m_kCenter;
    float m_fRadius;
};

struct S00a9fb50_Matrix3
{
    void GetCol(unsigned int uiCol, NiPoint3& kCol) const
    {
        kCol.x = m_afEntries[0][uiCol];
        kCol.y = m_afEntries[1][uiCol];
        kCol.z = m_afEntries[2][uiCol];
    }
    float m_afEntries[3][3];
};

inline float S00a9fb50_Abs(float f)
{
    return (float)fabs(f);
}

class S00a9fb50_OBB
{
  public:
    int FUN_00a9fb50(const S00a9fb50_Bound& kBound);
    int unk00;
    int unk04;
    int unk08;
    NiPoint3 m_kCenter;
    float m_afExtents[3];
    S00a9fb50_Matrix3 m_kBasis;
};

// pdb: BSMultiBoundOBB::CheckBound | BSMultiBoundOBB.obj | fnv360_0822_retail, vtable, medium
// pdb params: aTargetBound
int S00a9fb50_OBB::FUN_00a9fb50(const S00a9fb50_Bound& kBound)
{
    NiPoint3 kCenter = kBound.m_kCenter;
    float fRadius = kBound.m_fRadius;
    bool bInside = true;
    bool bTouch = true;

    NiPoint3 kAxis0;
    m_kBasis.GetCol(0, kAxis0);
    float fDist = S00a9fb50_Abs(kCenter.Dot(kAxis0) - m_kCenter.Dot(kAxis0));
    if (bInside)
        bInside &= fDist - (m_afExtents[0] - fRadius) <= 0.0f;
    bTouch &= fDist - (m_afExtents[0] + fRadius) <= 0.0f;
    if (bInside || bTouch)
    {
        NiPoint3 kAxis1;
        m_kBasis.GetCol(1, kAxis1);
        fDist = S00a9fb50_Abs(kCenter.Dot(kAxis1) - m_kCenter.Dot(kAxis1));
        if (bInside)
            bInside &= fDist - (m_afExtents[1] - fRadius) <= 0.0f;
        bTouch &= fDist - (m_afExtents[1] + fRadius) <= 0.0f;
        if (bInside || bTouch)
        {
            NiPoint3 kAxis2;
            m_kBasis.GetCol(2, kAxis2);
            fDist = S00a9fb50_Abs(kCenter.Dot(kAxis2) - m_kCenter.Dot(kAxis2));
            if (bInside)
                bInside &= fDist - (m_afExtents[2] - fRadius) <= 0.0f;
            bTouch &= fDist - (m_afExtents[2] + fRadius) <= 0.0f;
        }
    }
    if (bInside)
        return 2;
    return bTouch ? 1 : 0;
}
}   // namespace f3m_00a9fb50

// @f3 0x00a91fc0 (community match, verified in this file)
namespace f3m_00a91fc0 {
namespace ArrayInsertA91fc0 {
typedef f3m_00a8b1a0::GeometryVector1561 Vector4;

__forceinline void CopyVector(Vector4& target, const Vector4& source) {
    target.x = source.x;
    target.y = source.y;
    target.z = source.z;
    target.w = source.w;
}

struct Record {
    Vector4 first;
    Vector4 second;

    __forceinline Record& operator=(const Record& other) {
        CopyVector(first, other.first);
        CopyVector(second, other.second);
        return *this;
    }
};

struct Array {
    Record* data;
    int size;
    int capacityAndFlags;

    __forceinline void Reserve(int requested) {
        int capacity = capacityAndFlags & 0x3fffffff;
        if (capacity < requested) {
            int doubled = capacity + capacity;
            f3m_00a8b1a0::FUN_00901e90(this, requested < doubled ? doubled : requested, sizeof(Record));
        }
    }

    void FUN_00a91fc0(int index, const Record* records, int count);
};

void Array::FUN_00a91fc0(int index, const Record* records, int count) {
    int newSize = size + count;
    int tailCount = size - index;
    Reserve(newSize);
    Record* source = data + index;
    Record* destination = data + index + count;
    for (int i = tailCount - 1; i >= 0; --i)
        destination[i] = source[i];

    Record* insertion = data + index;
    for (int i = count - 1; i >= 0; --i)
        insertion[i] = records[i];
    size = newSize;
}
}
}   // namespace f3m_00a91fc0

// @f3 0x00a8ad60 (community match, verified in this file)
#include <math.h>
namespace f3m_00a8ad60 {

namespace f3m_00a8ad60 {

extern void FUN_00901e90(void* array, int capacity, int elementSize);

template<class T> struct GeometryArray1561
{
    T* data00;
    int size04;
    int capacityAndFlags08;
    __forceinline void SetSize(int newSize)
    {
        int capacity = capacityAndFlags08 & 0x3fffffff;
        if (capacity < newSize)
        {
            int doubled = capacity + capacity;
            FUN_00901e90(this, newSize < doubled ? doubled : newSize, sizeof(T));
        }
        size04 = newSize;
    }
};

struct GeometryVector1561
{
    float x;
    float y;
    float z;
    float w;
    __forceinline void SetSum(const GeometryVector1561& a, const GeometryVector1561& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void NormalizeTo(float radius)
    {
        float lengthSquared = x * x + y * y + z * z;
        float inverse;
        if (lengthSquared != 0.0f)
            inverse = 1.0f / sqrtf(lengthSquared);
        else
            inverse = 0.0f;
        float t;
        t = x * inverse; x = t * radius;
        t = y * inverse; y = t * radius;
        t = z * inverse; z = t * radius;
        t = w * inverse; w = t * radius;
    }
};

struct GeometryTriangle1561
{
    int a;
    int b;
    int c;
    void Set(int first, int second, int third) { a = first; b = second; c = third; }
};

struct DisplayGeometry1561
{
    GeometryArray1561<GeometryVector1561> vertices00;
    GeometryArray1561<GeometryTriangle1561> triangles0c;
};

// pdb: _subdivideRecursive | hkDisplaySphere.obj | fnv360_0822_retail, call_dedup, low
void FUN_00a8ad60(DisplayGeometry1561* geometry, int triangle, float radius, float detail)
{
    if (detail == 0.0f)
        return;
    int firstTriangle = geometry->triangles0c.size04;
    int firstVertex = geometry->vertices00.size04;
    geometry->vertices00.SetSize(geometry->vertices00.size04 + 3);
    geometry->triangles0c.SetSize(geometry->triangles0c.size04 + 3);

    GeometryTriangle1561& tri = geometry->triangles0c.data00[triangle];
    GeometryVector1561* v = geometry->vertices00.data00;
    GeometryVector1561& a = v[tri.a];
    GeometryVector1561& b = v[tri.b];
    GeometryVector1561& c = v[tri.c];
    GeometryVector1561* added = &v[firstVertex];
    GeometryVector1561& ab = added[0];
    GeometryVector1561& bc = added[1];
    GeometryVector1561& ca = v[firstVertex + 2];

    ab.SetSum(b, a);
    ab.NormalizeTo(radius);
    bc.SetSum(c, b);
    bc.NormalizeTo(radius);
    ca.SetSum(c, a);
    ca.NormalizeTo(radius);

    GeometryTriangle1561* split = &geometry->triangles0c.data00[firstTriangle];
    GeometryTriangle1561& t0 = split[0];
    GeometryTriangle1561& t1 = split[1];
    GeometryTriangle1561& t2 = geometry->triangles0c.data00[firstTriangle + 2];
    t0.a = tri.a;
    t0.b = firstVertex;
    t0.c = firstVertex + 2;
    t1.a = firstVertex;
    t1.b = tri.b;
    t1.c = firstVertex + 1;
    t2.a = firstVertex + 2;
    t2.b = firstVertex + 1;
    t2.c = tri.c;
    tri.a = firstVertex;
    tri.b = firstVertex + 1;
    tri.c = firstVertex + 2;

    FUN_00a8ad60(geometry, firstTriangle, radius, detail - 1.0);
    FUN_00a8ad60(geometry, firstTriangle + 1, radius, detail - 1.0);
    FUN_00a8ad60(geometry, firstTriangle + 2, radius, detail - 1.0);
    FUN_00a8ad60(geometry, triangle, radius, detail - 1.0);
}

}
}   // namespace f3m_00a8ad60

// @f3 0x00a8d1f0 (community match, verified in this file)
#include <new>
namespace f3m_00a8d1f0 {

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
extern unsigned long DAT_010f3170;
int __cdecl hkString_strCmp(const char* a, const char* b);

struct S00a8d1f0_Pool {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64;
    void* freeList68;
    int freeCount6c;
    void* FUN_008f6800(int units, int category);
};

struct S00a8d1f0_Node;

struct S00a8d1f0_Array {
    S00a8d1f0_Node** m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
    S00a8d1f0_Node*& operator[](int i) { return m_data[i]; }
};

struct S00a8d1f0_Node {
    float values[8];
    unsigned short counts[8];
    S00a8d1f0_Array children;
    double unk40;
    S00a8d1f0_Node* unk48;
    const char* name;
    int unk50;
    int unk54;

    S00a8d1f0_Node(S00a8d1f0_Node* owner, const char* aName, int value4) throw();

    static void* operator new(unsigned int)
    {
        S00a8d1f0_Pool* pool = (S00a8d1f0_Pool*)FUN_00d9b080(DAT_010f3170);
        void* result = pool->freeList68;
        if (result) {
            --pool->freeCount6c;
            pool->freeList68 = *(void**)result;
            return result;
        }
        return pool->FUN_008f6800(6, 0x1b);
    }
    static void operator delete(void*) {}
};

static __declspec(noinline) bool FUN_00a8c2f0(const char* name, int* index, S00a8d1f0_Node* owner)
{
    if (*index < owner->children.m_size &&
        hkString_strCmp(owner->children.m_data[*index]->name, name) == 0)
        return true;
    for (int i = 0; i < owner->children.m_size; i++) {
        if (hkString_strCmp(owner->children.m_data[i]->name, name) == 0) {
            *index = i;
            return true;
        }
    }
    return false;
}

// pdb: mergeSubTree | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void __cdecl FUN_00a8d1f0(S00a8d1f0_Node* apDestNode, S00a8d1f0_Node* apSrcNode, int index, int aiSrcLevel, float afBlendAmount)
{
    int lvl = index;
    if (lvl > 6)
        lvl = 6;
    index = 0;
    int i = 0;
    if (apSrcNode->children.m_size > 0) {
        double d = 1.0f - afBlendAmount;
        int n;
        do {
            S00a8d1f0_Node* src = apSrcNode->children[i];
            S00a8d1f0_Node* dst;
            if (!FUN_00a8c2f0(apSrcNode->children[i]->name, &index, apDestNode)) {
                void* slot = S00a8d1f0_Node::operator new(sizeof(S00a8d1f0_Node));
                if (slot) {
                    int f = src->unk54;
                    dst = ::new (slot) S00a8d1f0_Node(apDestNode, src->name, f);
                } else
                    dst = 0;
            } else {
                dst = apDestNode->children[index];
            }
            dst->values[lvl] = (float)(src->values[aiSrcLevel] * d + dst->values[lvl]);
            dst->counts[lvl] = src->counts[aiSrcLevel];
            FUN_00a8d1f0(dst, src, lvl, aiSrcLevel, afBlendAmount);
            n = apSrcNode->children.m_size;
            if (index < n - 1)
                ++index;
            ++i;
        } while (i < n);
    }
}

}

// @f3 0x00a9db40 (community match, verified in this file)
#include <string.h>
extern const char DAT_00e0f6e0[];
namespace f3m_00a9db40 {
namespace da9db40 {
int __cdecl FUN_00a9d930(const char* name);
char* __cdecl FUN_00847b90(const char* label, bool value);
char* __cdecl FUN_00847bf0(const char* label, unsigned char value);
char* __cdecl FUN_00847d30(const char* label, int value);
char* __cdecl FUN_00847d80(const char* label, unsigned int value);
char* __cdecl FUN_00847dd0(const char* label, float value);
char* __cdecl FUN_00847e70(const char* label, const char* value);

struct StringArray {
    void* vtable;
    char** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short used;
    unsigned short growBy;
    void FUN_00555790(unsigned int newSize);
    void FUN_005b3880(unsigned int index, char* const& item);
    unsigned int FUN_00ab9e10(char* const& item);
    __forceinline void Append(char* const& item) {
        unsigned int index = size;
        if (index >= capacity) FUN_00555790(index + growBy);
        FUN_005b3880(index, item);
    }
};

struct Setting {
    void* vtable;
    union {
        bool b;
        unsigned char c;
        int i;
        unsigned int u;
        float f;
        const char* s;
    } value;
    const char* name;
    void FUN_00a9db40(StringArray* out);
};

// pdb: Setting::GetViewerStrings | Setting.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apStringsA
void Setting::FUN_00a9db40(StringArray* out)
{
    char buffer[256];
    strcpy_s(buffer, 256, DAT_00e0f6e0);
    strcat_s(buffer, 256, name);
    char* text;
    switch (FUN_00a9d930(name)) {
    case 0:
        out->FUN_00ab9e10(text = FUN_00847b90(buffer, value.b));
        return;
    case 1:
    case 2:
        out->FUN_00ab9e10(text = FUN_00847bf0(buffer, value.c));
    case 3:
        text = FUN_00847d30(buffer, value.i);
        out->Append(text);
        return;
    case 5:
        out->FUN_00ab9e10(text = FUN_00847dd0(buffer, value.f));
        return;
    case 6: {
        const char* str = value.s;
        out->FUN_00ab9e10(text = FUN_00847e70(buffer, str));
        }
        return;
    default:
        text = FUN_00847d80(buffer, value.u);
        break;
    }
    out->Append(text);
}
}
}   // namespace f3m_00a9db40

// @f3 0x00a97fe0 (community match, verified in this file)
namespace f3m_00a97fe0 {
namespace f3m_00a97fe0 {
// A 16-byte-aligned 4-float row; the whole object is 12 rows = 0xc0 bytes of floats.
struct __declspec(align(16)) Vector4 {
 float x,y,z,w;
 __forceinline void add4(const Vector4& a) { x = x + a.x; y = y + a.y; z = z + a.z; w = w + a.w; }
};
struct __declspec(align(16)) G1 { Vector4 c[1]; __forceinline void add(const G1& a) { c[0].add4(a.c[0]); } };
struct __declspec(align(16)) G2 { Vector4 c[2]; __forceinline void add(const G2& a) { c[0].add4(a.c[0]); c[1].add4(a.c[1]); } };
struct __declspec(align(16)) G3 { Vector4 c[3]; __forceinline void add(const G3& a) { c[0].add4(a.c[0]); c[1].add4(a.c[1]); c[2].add4(a.c[2]); } };
struct __declspec(align(16)) G6 { Vector4 c[6]; __forceinline void add(const G6& a) { c[0].add4(a.c[0]); c[1].add4(a.c[1]); c[2].add4(a.c[2]); c[3].add4(a.c[3]); c[4].add4(a.c[4]); c[5].add4(a.c[5]); } };
// Fake match: the 3+2+1+6 grouping of the twelve rows is only there to steer MSVC 2005 /O2's
// x87 operand selection (which memory operand it folds into fld vs fadd) at rows 0x60 and 0xa0.
// The layout is still twelve consecutive Vector4 rows and the operation is still the row-wise sum.
struct __declspec(align(16)) Matrix6 {
 G3 m0; G2 m1; G1 m2; G6 m3;
 __forceinline void add(const Matrix6& a) { m0.add(a.m0); m1.add(a.m1); m2.add(a.m2); m3.add(a.m3); }
};
// pdb: hkMatrix6Add | hkMatrix6.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void hkMatrix6Add(Matrix6* d, const Matrix6* s) { d->add(*s); }
}
}   // namespace f3m_00a97fe0

// @f3 0x00a823f0 (community match, verified in this file)
namespace f3m_00a823f0 {
namespace Copy329 {
void FUN_00901e90(void*,int,int);void FUN_009234e0(void*,const void*,int);
struct Array{char* data;int size;int capacity;__forceinline Array(const Array& a):data(0),size(0),capacity(0x80000000){setSize(a.size);FUN_009234e0(data,a.data,a.size);}int getCapacity()const{return capacity&0x3fffffff;}void setSize(int n){if(getCapacity()<n){int doubled=2*getCapacity();FUN_00901e90(this,n<doubled?doubled:n,1);}size=n;}};
struct FUN_00a823f0{Array a,b;FUN_00a823f0(const FUN_00a823f0&);};FUN_00a823f0::FUN_00a823f0(const FUN_00a823f0& o):a(o.a),b(o.b){}

}
}   // namespace f3m_00a823f0

// @f3 0x00a821d0 (community match, verified in this file)
namespace f3m_00a821d0 {
namespace f3m_00a821d0 {
void __cdecl FUN_00901e90(void* arr, int capacity, int stride);

struct ByteArray
{
    char* m_data;
    int m_size;
    int m_capacityAndFlags;

    void reserve(int n)
    {
        int cap = m_capacityAndFlags & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap * 2;
            FUN_00901e90(this, n < c2 ? c2 : n, 1);
        }
    }

    static void CopyBackwards(char* dst, const char* src, int n)
    {
        for (int i = n - 1; i >= 0; --i)
            dst[i] = src[i];
    }

    void FUN_00a821d0(int index, const char* p, int numToInsert);
};

// pdb: hkParserBuffer::read | hkParserBuffer.obj | tesv_win, objopen_prop, low
void ByteArray::FUN_00a821d0(int index, const char* p, int numToInsert)
{
    const int newSize = m_size + numToInsert;
    const int numToMove = m_size - index;
    reserve(newSize);
    CopyBackwards(m_data + index + numToInsert, m_data + index, numToMove);
    CopyBackwards(m_data + index, p, numToInsert);
    m_size = newSize;
}
}
}   // namespace f3m_00a821d0

// @f3 0x00a8a550 (community match, verified in this file)
namespace f3m_00a8a550 {
namespace c3_00a8a550 {

struct Tri
{
    int unk00, unk04, unk08, unk0c;
    unsigned short* v0;
    unsigned short* v1;
    unsigned short* v2;
};

__forceinline void Mark(bool* unique, bool* flag)
{
    if (*flag)
        *unique = false;
    *flag = true;
}

// pdb: hkGeomConvexHullTester::findSameEdges | hkGeomConvexHullTester.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a8a550(bool* unique, Tri* a, Tri* b, bool* e0, bool* e1, bool* e2)
{
    unsigned int a0 = *a->v0;
    unsigned int a1 = *a->v1;
    unsigned int a2 = *a->v2;
    unsigned int b0 = *b->v0;
    unsigned int b1 = *b->v1;
    unsigned int b2 = *b->v2;
    bool* result = *(bool* volatile*)&unique;
    *result = true;
    if (a0 == b0)
    {
        if (a1 == b1 || a1 == b2)
            Mark(result, e0);
        if (a2 == b1 || a2 == b2)
            Mark(result, e1);
    }
    if (a0 == b1)
    {
        if (a1 == b2)
            Mark(result, e0);
        if (a2 == b2)
            Mark(result, e1);
    }
    if ((a1 == b0 && (a2 == b1 || a2 == b2)) || (a1 == b1 && a2 == b2))
        Mark(result, e2);
}

}
}   // namespace f3m_00a8a550

// @f3 0x00a80dd0 (community match, verified in this file)
namespace f3m_00a80dd0 {
namespace ns_a80dd0 {
struct Stream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(char* buf, int size);
    virtual void v14(int pos);
    virtual void v18();
    virtual void v1c(int size);
    virtual void v20();
};
// pdb: hkXmlLexAnalyzer::_lexComment | hkXmlLexAnalyzer.obj | tesv_win, uconst, low
static __declspec(noinline) void FUN_00a80dd0(Stream* s, char* buf, int size, int n)
{
    const char end[] = "-->";
    int i = 0;
    int m = 0;
    for (;;)
    {
        for (; i < n; ++i)
        {
            char c = buf[i];
            if (c == end[m])
            {
                ++m;
                if (end[m] == 0)
                    break;
            }
            else if (c != '-')
            {
                m = 0;
            }
        }
        if (i != n)
        {
            s->v20();
            s->v14(i + 1);
            return;
        }
        s->v1c(size);
        n = s->v10(buf, size);
        if (n == 0)
            return;
        i = 0;
    }
}
volatile int g_in_a80dd0;
void caller_of_FUN_00a80dd0()
{
    FUN_00a80dd0((Stream*)g_in_a80dd0, (char*)g_in_a80dd0, g_in_a80dd0, g_in_a80dd0);
}
}
}   // namespace f3m_00a80dd0

// @f3 0x00a82770 (community match, verified in this file)
namespace F82770 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag); };
void __cdecl FUN_009234e0(void* dst, const void* src, int n);
struct Node {
    Node* first;
    Node* last;
    Node* next;
    Node* prev;
    Node* parent;
    Node() : first(0), last(0), next(0), prev(0), parent(0) {}
    static void* operator new(unsigned int n, int extra)
    {
        Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
        return heap->FUN_008f6d30(n + extra, 0x17);
    }
    static void operator delete(void*, int) {}
};
struct Tree {
    Node* first;
    Node* last;
    Node* FUN_00a82770(Node* parent, const void* data, int size);
};
Node* Tree::FUN_00a82770(Node* parent, const void* data, int size)
{
    Node* node = new (size) Node;
    FUN_009234e0(node + 1, data, size);
    if (parent) {
        if (parent->last) {
            parent->last->next = node;
            node->prev = parent->last;
            node->parent = parent;
            parent->last = node;
        }
        else {
            parent->last = node;
            parent->first = node;
            node->parent = parent;
        }
    }
    else if (last) {
        node->prev = last;
        last->next = node;
        last = node;
    }
    else {
        first = node;
        last = node;
    }
    return node;
}
}

// @f3 0x00a97950 (community match, verified in this file)
extern void* DAT_00e35eec;extern void* DAT_00e88e0c;extern void* DAT_00e88de8;
namespace f3m_00a97950 {
namespace match655 {
struct Base {
 void* table; unsigned short size,refs;unsigned user,kind;float radius;
 Base(float value):refs(1),user(0),kind(0x13),radius(value){}
};
struct Secondary {void* table;Secondary():table(&DAT_00e35eec){}};
struct FUN_00a97950:Base,Secondary {FUN_00a97950(float value);};
// pdb: hkpConvexPieceShape::hkpConvexPieceShape | hkpConvexPieceShape.obj | fnv360_0822_retail, uvref, medium
// pdb params: radius
FUN_00a97950::FUN_00a97950(float value):Base(value){Base::table=&DAT_00e88e0c;Secondary::table=&DAT_00e88de8;}
}
}   // namespace f3m_00a97950

// @f3 0x00a8a740 (community match, verified in this file)
namespace f3m_00a8a740 {
namespace f3ns_00a8a740 {
struct Bool {
    char value;
    Bool(bool b) : value(b) {}
    operator bool() const { return value != 0; }
    void operator=(bool b) { value = b; }
};
struct Record {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
};
struct Records {
    Record* data;
    int count;
    int capacity;
};
Bool __cdecl FUN_00a8a620(void* a, void* c, void* d, float time);
Bool __cdecl FUN_00a8a550(Record* lhs, Record* rhs, Bool& first, Bool& second, Bool& third);

// pdb: hkGeomConvexHullTester::isValidPlanarHull | hkGeomConvexHullTester.obj | tesv_win, call_gap, low
Bool __cdecl FUN_00a8a740(void* a, void* b, void* c, void* d, Records* items, float time)
{
    Bool result(true);
    result = bool(result) && bool(FUN_00a8a620(a, c, d, time));
    int count = items->count;
    for (int i = 0; count > i; ++i) {
        Bool first(false), second(false), third(false);
        for (int j = 0; j < count; ++j) {
            if (j != i) {
                FUN_00a8a550(&items->data[i], &items->data[j], first, second, third);
            }
        }
        result = bool(result) && bool(first) && bool(second) && bool(third);
    }
    return result;
}
}
}   // namespace f3m_00a8a740

// @f3 0x00a80550 (community match, verified in this file)
namespace f3m_00a80550 {

namespace f3m_00a80550 {
struct HkClass { int FUN_009b0760() throw(); };
int __cdecl FUN_00a808a0(void* obj, const HkClass* cls, void* ctx);
static __declspec(noinline) int FUN_00a80550(char* p, HkClass* cls, void* ctx, int count)
{
    int stride = cls->FUN_009b0760();
    for (int i = 0; i < count; ++i) {
        if (FUN_00a808a0(p + i * stride, cls, ctx) == 1)
            return 1;
    }
    return 0;
}
volatile int g_cnt; void* volatile g_p; HkClass* volatile g_cls; void* volatile g_ctx;
int Caller_00a80550() { return FUN_00a80550((char*)g_p, g_cls, g_ctx, g_cnt); }
}
}   // namespace f3m_00a80550

// @f3 0x00a87cd0 (community match, verified in this file)
namespace f3m_00a87cd0 {
namespace NativeMoppAssembly {
struct Ec8Elem { int first; int second; };

struct Ec8Vec {
    Ec8Elem* data;        // +0
    int size;             // +4
    unsigned int cap;     // +8 (top bits are flags)
};

struct Ec8Table {
    int unk00;
    Ec8Vec v;             // +4
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct Ec8Counter {
    int next;             // +0
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct Ec8Src {
    int unk00;
    unsigned char flag4;  // +4
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m24;
    int m28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char flag38;
    int unk3c;
    int m40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    Ec8Counter* m60;
    int unk64;
    int unk68;
    int unk6c;
    Ec8Src* m70;
    Ec8Src* m74;
};

class Ec8Ctx {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Ec8Table* m14;        // +0x14
    int FUN_00a87cd0(Ec8Src* s, int a2, int a3);
};

void __cdecl FUN_00901f10(Ec8Vec* values, int bytes);

// pdb: hkpMoppDefaultAssembler::calcTerminalIdsForChunks | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: currentNode, chunkId, currentId
int Ec8Ctx::FUN_00a87cd0(Ec8Src* node, int group, int a3)
{
    int g = node->m40;
    int index = *(volatile int*)&a3;
    a3 = index;
    node->flag38 = 0;
    if (g >= 0) {
        group = g;
        index = 0;
    }

    if (m14->unk1c)
        node->m24 = index;
    if (node->flag4) {
        if (m14->unk1c) {
            Ec8Counter* counter = node->m60;
            counter->unk10 = counter->next;
            Ec8Vec* output = &m14->v;
            if (output->size == static_cast<int>(output->cap & 0x3fffffffu))
                FUN_00901f10(output, sizeof(Ec8Elem));
            Ec8Elem* next = &output->data[output->size++];
            next->second = (group << 8) | index;
            next->first = node->m60->next;
            node->m60->next = index;
            ++index;
        }
    } else {
        Ec8Src* right = node->m74;
        index = FUN_00a87cd0(right, group, index);
        Ec8Src* left = node->m70;
        index = FUN_00a87cd0(left, group, index);
    }
    if (m14->unk1c) {
        node->m24 = 0;
        node->m28 = index;
    }
    if (node->m40 < 0)
        return index;
    return a3;
}
}

}   // namespace f3m_00a87cd0

// @f3 0x00a80660 (community match, verified in this file)
extern const char DAT_00e7e934[];
extern const char DAT_00e87e98[];
namespace f3m_00a80660 {
namespace f3m_00a80660 {

struct hkClass;

struct hkClassMember
{
    const char* m_name;
    const hkClass* m_class;
    const void* m_enum;
    unsigned char m_type;
    unsigned char m_subtype;
    short m_cArraySize;
    unsigned short m_flags;
    unsigned short m_offset;

    const hkClass& getStructClass() const throw();
    int getCstyleArraySize() const throw();
    int getArrayType() const throw();
};

struct hkClass
{
    int FUN_009b0630() const throw();
    const hkClassMember& getMember(int i) const throw();
    int getObjectSize() const throw();
};

struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};

struct hkArrayHeader
{
    void* m_data;
    int m_size;
};

struct hkHomogeneousArray
{
    const hkClass* m_class;
    void* m_data;
    int m_size;
};

typedef f3m_00a805a0::f3m_00a805a0::Array_a805a0 PointerArray;

int __cdecl FUN_00a808a0(const void* object, const hkClass& klass, PointerArray& pointers);

static __declspec(noinline) void addVariants(const hkVariant* v, int count, PointerArray* a)
{
    int oldSize = a->m_size;
    int newSize = oldSize + count;
    int capacity = a->m_capacityAndFlags & 0x3fffffff;
    if (capacity < newSize)
    {
        int doubled = capacity * 2;
        f3m_00a805a0::f3m_00a805a0::FUN_00901e90(a, newSize < doubled ? doubled : newSize, 8);
    }
    a->m_size = newSize;
    f3m_00a805a0::f3m_00a805a0::Entry_a805a0* dst = a->m_data + oldSize;
    for (int i = 0; i < count; i++)
    {
        dst[i].p = reinterpret_cast<const int*>(&v[i].m_object);
        dst[i].v = reinterpret_cast<int>(v[i].m_class);
    }
}

static __declspec(noinline) int addStructs(const void* data, const hkClass& klass, PointerArray& pointers, int count)
{
    int size = klass.getObjectSize();
    const char* p = static_cast<const char*>(data);
    for (int i = 0; i < count; i++)
    {
        if (FUN_00a808a0(p, klass, pointers) == 1)
            return 1;
        p += size;
    }
    return 0;
}

}

int __cdecl FUN_00a80660(const void* object, const f3m_00a80660::hkClass& klass, f3m_00a80660::PointerArray* pointers)
{
    using namespace f3m_00a80660;
    // Fake match: the output array pointer is copied once through a volatile view of its
    // parameter slot. This puts its load into ebp at function entry (+0x08), where the target
    // has it; a plain reference or pointer parameter is loaded after the first count test
    // instead. The parameter is declared as a pointer (same calling sequence as a reference)
    // only so that its slot can be read this way.
    PointerArray* outp = *(PointerArray* volatile*)&pointers;
    for (int i = 0; i < klass.FUN_009b0630(); i++)
    {
        const hkClassMember& member = klass.getMember(i);
        void* addr = (char*)object + member.m_offset;
        switch (member.m_type)
        {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 21: case 24: case 29: case 30: case 31:
            break;
        case 20:
            if (member.m_subtype == 25)
            {
                int n = member.getCstyleArraySize() ? member.getCstyleArraySize() : 1;
                f3m_00a805a0::f3m_00a805a0::FUN_00a805a0(outp, n, (const int*)addr,
                                                         (int)&member.getStructClass());
            }
            break;
        case 22: case 23: case 26:
        {
            int subType = member.getArrayType();
            hkArrayHeader* arr = (hkArrayHeader*)addr;
            if (arr->m_data)
            {
                if (subType == 20)
                {
                    f3m_00a805a0::f3m_00a805a0::FUN_00a805a0(outp, arr->m_size, (const int*)arr->m_data,
                                                             (int)&member.getStructClass());
                }
                else if (subType == 25)
                {
                    if (addStructs(arr->m_data, member.getStructClass(), *outp, arr->m_size) == 1)
                        return 1;
                }
                else if (subType == 28)
                {
                    addVariants((const hkVariant*)arr->m_data, arr->m_size, outp);
                }
            }
            break;
        }
        case 27:
        {
            hkHomogeneousArray* ha = (hkHomogeneousArray*)addr;
            if (ha->m_data && ha->m_class)
            {
                if (addStructs(ha->m_data, *ha->m_class, *outp, ha->m_size) == 1)
                    return 1;
            }
            break;
        }
        case 25:
        {
            const hkClass& sc = member.getStructClass();
            int n = member.getCstyleArraySize() ? member.getCstyleArraySize() : 1;
            if (addStructs(addr, sc, *outp, n) == 1)
                return 1;
            break;
        }
        case 28:
        {
            int n = member.getCstyleArraySize() ? member.getCstyleArraySize() : 1;
            addVariants((const hkVariant*)addr, n, outp);
            break;
        }
        default:
        {
            void* buf[0x80];
            StrBuf os(buf, 0x200);
            os.FUN_00943710(::DAT_00e7e934);
            DAT_010f3364->Log(3, 0x641e3e03, (const char*)buf, ::DAT_00e87e98, 0xfe);
            os.FUN_00943a60();
            return 1;
        }
        }
    }
    return 0;
}
}   // namespace f3m_00a80660

// @f3 0x00a8a620 (community match, verified in this file)
namespace f3m_00a8a620 {
namespace na8a620 {
struct Point { float x, y, z, w; };
struct Plane {
    float x, y, z, d;
    float Distance(const Point& p) const { return p.x * x + p.y * y + p.z * z + d; }
};
struct PointArray { Point* data; int count; };
struct PlaneArray { Plane* data; int count; };
// Fake match: the result is a one-byte struct returned through a hidden pointer; the pointer is written out
// as the first parameter (as in the earlier draft).
// pdb: hkGeomConvexHullTester::checkPlaneEquations | hkGeomConvexHullTester.obj | tesv_win, call_seq, medium
bool* FUN_00a8a620(bool* result, PointArray* first, PointArray* second, PlaneArray* planes, float epsilon)
{
    *result = true;
    for (int i = 0; *result && i < planes->count; i++) {
        int j = 0;
        if (*result) {
            int n = first->count;
            for (; *result && j < n; j++)
            {
                // Fake match: the null initialisation is dead. It makes the plane pointer the earlier symbol while the
                // point address is still evaluated first, which sets the load order and the operand order of the
                // three products.
                const Plane* plane = 0;
                const Point* point = &first->data[j];
                plane = &planes->data[i];
                // Fake match: the named bool (here and in the second loop) and the separate counter k only shift the
                // numbering of the second loop's pointers; that numbering decides which operand of the x product is
                // loaded first there.
                bool below = (*result && plane->Distance(*point) < epsilon) ? true : false;
                *result = below;
            }
        }
        int k = 0;
        if (*result) {
            int m = second->count;
            for (; *result && k < m; k++)
            {
                // Fake match: same dead initialisation as above; the pointers are assigned inside the condition so
                // that both addresses are formed after the test of the result byte.
                const Plane* plane = 0;
                const Point* point;
                bool below = (*result && (point = &second->data[k], plane = &planes->data[i], plane->Distance(*point) < epsilon)) ? true : false;
                *result = below;
            }
        }
    }
    return result;
}
}
}   // namespace f3m_00a8a620

// @f3 0x00a8f110 (community match, verified in this file)
// 0x00a8f110: monitor stream analyzer, set the number of threads and SPUs.
// Resizes the per-thread array of frame-info arrays (object array of arrays
// of 36-byte records), stores both counts and resets.
// The two swap helpers have their real bodies so the compiler can see that the
// temporary's address does not escape (0x00a82280 forwards to 0x00929ad0).
namespace cand_a8f110 {

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
extern "C" void __cdecl FUN_00901e90(void* arr, int capacity, int stride);

struct ThreadMemory
{
    void* FUN_008f6d30(int nbytes, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    static ThreadMemory* getInstance()
    {
        return (ThreadMemory*)TlsGetValue(DAT_010f3170);
    }
};

template <class T> inline T* allocateChunk(int n, int cls)
{
    return (T*)ThreadMemory::getInstance()->FUN_008f6d30(n * sizeof(T), cls);
}

struct FrameInfo
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
};

template <class T> struct Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline Array(const Array& a)
        : m_data(allocateChunk<T>(a.m_size, 0x17)), m_size(a.m_size), m_capacityAndFlags(a.m_size)
    {
        copy(m_data, a.m_data, a.m_size);
    }
    ~Array()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            ThreadMemory::getInstance()->FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
    }
    static void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i)
            dst[i] = src[i];
    }
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T* begin() { return m_data; }
    T& operator[](int i) { return m_data[i]; }
    void setSizeUnchecked(int n) { m_size = n; }
    void reserve(int n)
    {
        if (getCapacity() < n)
        {
            int c2 = 2 * getCapacity();
            FUN_00901e90(this, n < c2 ? c2 : n, sizeof(T));
        }
    }
    __declspec(noinline) void FUN_00929ad0(Array& a)
    {
        T* d = m_data;
        m_data = a.m_data;
        a.m_data = d;
        int s = m_size;
        m_size = a.m_size;
        a.m_size = s;
        int c = m_capacityAndFlags;
        m_capacityAndFlags = a.m_capacityAndFlags;
        a.m_capacityAndFlags = c;
    }
};

template <class T> struct ObjectArray
{
    Array<T> m_array;

    static __forceinline void construct(T* t, int n, const T* src)
    {
        for (int i = 0; i < n; ++i)
            new (t + i) T(src[i]);
    }
    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            t[i].~T();
    }
    ObjectArray() {}
    __declspec(noinline) void FUN_00a82280(ObjectArray& a)
    {
        m_array.FUN_00929ad0(a.m_array);
    }
    __forceinline ~ObjectArray()
    {
        destruct(m_array.begin(), m_array.getSize());
    }
    __forceinline void reserve(int n)
    {
        int mysize = m_array.getSize();
        ObjectArray<T> old;
        old.FUN_00a82280(*this);
        m_array.reserve(n);
        construct(m_array.begin(), mysize, old.m_array.begin());
        m_array.setSizeUnchecked(mysize);
    }
    __forceinline void setSize(int n)
    {
        int mysize = m_array.getSize();
        if (n < mysize)
        {
            for (int i = n; i < mysize; ++i)
                m_array[i].~T();
        }
        else
        {
            if (n > m_array.getCapacity())
            {
                int c2 = 2 * m_array.getCapacity();
                reserve(n < c2 ? c2 : n);
            }
            T* p = m_array.begin();
            for (int i = mysize; i < n; ++i)
                new (p + i) T;
        }
        m_array.setSizeUnchecked(n);
    }
};

struct Analyzer
{
    ObjectArray<Array<FrameInfo> > m_frameInfos;
    Array<char> m_data;
    int m_numThreads;
    int m_numSpus;
    const char* m_nodeIdForFrameOverview;
    void FUN_00a8f110(int numThreads, int numSpus);
    void FUN_00a8c900() throw();
};

// pdb: hkMonitorStreamAnalyzer::resetNumThreads | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap, low
// pdb params: numThreads, numSpus
void Analyzer::FUN_00a8f110(int numThreads, int numSpus)
{
    m_frameInfos.setSize(numThreads + numSpus);
    m_numSpus = numSpus;
    m_numThreads = numThreads;
    FUN_00a8c900();
}

}

// @f3 0x00a883e0 (community match, verified in this file)
namespace f3m_00a883e0 {

extern unsigned long DAT_010f3170;
extern "C" void __cdecl FUN_009234e0(void* dst, const void* src, int n);

struct KThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* AllocateStackSlow(int nbytes);
    virtual void PopStack(void* p);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* m_current;
    int unk24;
    char* m_previous;
    char* m_end;
    void* FUN_008f6d30(unsigned int size, int tag);
    void FUN_008f6d90(void* p, unsigned int size, int tag);
    void* AllocateStack(int nbytes)
    {
        int aligned = (nbytes + 16) & ~15;
        char* current = m_current;
        char* next = current + aligned;
        if (next <= m_end)
        {
            m_current = next;
            return current;
        }
        return AllocateStackSlow(aligned);
    }
    void DeallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_previous)
            PopStack(p);
    }
};
inline KThreadMemory* GetThreadMemory() { return (KThreadMemory*)TlsGetValue(DAT_010f3170); }

struct KIntVec {
    int* data;
    int size;
    int cap;
    int* begin() { return data; }
    int getSize() const { return size; }
};
void __cdecl FUN_00901f10(KIntVec* v, int n);

struct KObj {
    int unk00;
    unsigned short unk04;
    short unk06;
    char* unk08;
    int unk0c;
    int unk10;
    KObj* FUN_00a85c40(int v);
    void FUN_00a85c80();
    void FUN_00a861c0(int n);
};
struct KEntry { KObj* first; int second; };
struct KConverter {
    virtual void v00();
    virtual int Measure(int* data, int n);
    virtual void Write(int* data, int n, void* out);
};
struct KTbl {
    int unk00, unk04, unk08, unk0c;
    KEntry* unk10;
    int unk14, unk18;
    KConverter* unk1c;
};
struct KPtr10 { int unk00, unk04, unk08, unk0c, unk10; };
struct KNode;
struct KCtx {
    int unk00;
    char unk04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    KCtx* FUN_00a88b90(KCtx* parent, KNode* child, int* p);
};
struct KNode {
    int unk00;
    char unk04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    KPtr10* unk60;
    int unk64, unk68, unk6c;
    KNode* unk70;
    KNode* unk74;
};
struct KRes { char unk00; int unk04, unk08, unk0c, unk10; };

static __declspec(noinline) int FUN_00a882d0(KTbl* tree, KObj* source, KIntVec* refs, KObj* destination)
{
    int padding = (-source->unk0c) & 3;
    if (!tree->unk1c)
        refs->size = 0;
    if (refs->size)
    {
        int bytes = tree->unk1c->Measure(refs->begin(), refs->getSize());
        destination->FUN_00a861c0(bytes);
        void* temporary = GetThreadMemory()->AllocateStack(bytes);
        tree->unk1c->Write(refs->data, refs->size, temporary);
        FUN_009234e0(destination->unk08 + destination->unk10 - destination->unk0c, temporary, bytes);
        GetThreadMemory()->DeallocateStack(temporary);
    }
    int before = destination->unk0c;
    destination->FUN_00a861c0(source->unk0c + padding);
    FUN_009234e0(destination->unk08 + destination->unk10 - destination->unk0c,
                 source->unk08 + source->unk10 - source->unk0c, source->unk0c);
    return destination->unk0c - before;
}

struct KWalker {
    int unk00, unk04, unk08, unk0c;
    KObj* unk10;
    KTbl* unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30;
    void hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(KNode* n, KCtx* c2, KCtx* c3, int idx, KIntVec* out);
    void FUN_00a863b0(int a, int b);
    void FUN_00a867c0(KNode* n);
    void FUN_00a87710(KNode* n, KCtx* c2, KCtx* c3);
    void FUN_00a86fc0(KNode* n, KCtx* c2, KCtx* c3, KRes* r);
    void FUN_00a87770(KNode* n, KCtx* c2, KCtx* c3, KRes* r);
};

// pdb: hkpMoppDefaultAssembler::assembleSubNodeIntoChunks | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap_sim|call_gap) + skyrim(call_gap_sim), high
void KWalker::hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(KNode* n, KCtx* c2, KCtx* c3, int idx, KIntVec* out)
{
    int cnt = n->unk40;
    if (cnt > 0 && !c3->unk04) {
        KObj* saved = unk10;
        KEntry* e = &unk14->unk10[cnt];
        KObj cur;
        cur.FUN_00a85c40(e->second);
        unk10 = &cur;
        KIntVec vec;
        vec.data = 0;
        vec.size = 0;
        c3->unk04 = 1;
        vec.cap = 0x80000000;
        hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(n, c2, c3, cnt, &vec);
        if (unk14->unk1c != 0) {
            int s = unk10->unk0c + 5;
            FUN_00a863b0(s + ((-s) & 3), vec.size);
        }
        KObj* it = (KObj*)GetThreadMemory()->FUN_008f6d30(0x14, 0x28);
        it->unk04 = 0x14;
        e->first = it->FUN_00a85c40(e->second);
        FUN_00a882d0(unk14, unk10, &vec, e->first);
        if ((vec.cap & 0x80000000u) == 0) {
            int cap = vec.cap & 0x3fffffff;
            GetThreadMemory()->FUN_008f6d90(vec.data, cap * 4, 0x17);
        }
        cur.FUN_00a85c80();
        unk10 = saved;
        FUN_00a867c0(n);
    } else if (n->unk04) {
        FUN_00a87710(n, c2, c3);
        int* pv = &n->unk60->unk10;
        if (out->size == (out->cap & 0x3fffffff))
            FUN_00901f10(out, 4);
        out->data[out->size] = *pv;
        out->size++;
    } else {
        KRes r;
        r.unk00 = 0;
        FUN_00a86fc0(n, c2, c3, &r);
        {
            KNode* right = n->unk74;
            KCtx a;
            a.FUN_00a88b90(c3, right, &unk30);
            hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(right, c3, &a, idx, out);
        }
        {
            KNode* left = n->unk70;
            KCtx a;
            a.FUN_00a88b90(c3, left, &unk30);
            hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(left, c3, &a, idx, out);
        }
        FUN_00a87770(n, c2, c3, &r);
    }
}

}

// @f3 0x00a81460 (community match, verified in this file)
extern const char* volatile g_in81460;
extern volatile int g_out81460;
namespace f3m_00a81460 {
// Splits the inside of a markup tag into name="value" pairs and appends each pair to an array.
// The string and array helpers below are the inline container code this function was built from.
namespace xml81460 {
extern unsigned long DAT_010f3170; // thread-local slot of the per-thread memory manager
extern "C" void __cdecl FUN_009234e0(void* dst, const void* src, int n);
extern "C" void __cdecl FUN_00901e90(void* arr, int capacity, int stride);
struct ThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};
inline ThreadMemory* GetThreadMemory() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
enum Result { RESULT_SUCCESS = 0, RESULT_FAILURE = 1 };

// Untyped view of an array header; FUN_00929ad0 exchanges two headers.
struct ArrayBase {
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    void FUN_00929ad0(ArrayBase& other);
};
__declspec(noinline) void ArrayBase::FUN_00929ad0(ArrayBase& other)
{
    void* data = m_data;
    m_data = other.m_data;
    other.m_data = data;
    int size = m_size;
    m_size = other.m_size;
    other.m_size = size;
    int capacityAndFlags = m_capacityAndFlags;
    m_capacityAndFlags = other.m_capacityAndFlags;
    other.m_capacityAndFlags = capacityAndFlags;
}

// Growable array: data, size, and a capacity whose top bit means "storage not owned".
template <class T> struct Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    explicit Array(int n) : m_data((T*)GetThreadMemory()->FUN_008f6d30(n * sizeof(T), 0x17)), m_size(n), m_capacityAndFlags(n) {}
    ~Array() { releaseMemory(); }
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T* begin() { return m_data; }
    const T* begin() const { return m_data; }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int capacity = getCapacity();
            ThreadMemory* memory = GetThreadMemory();
            memory->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
    void reserve(int n)
    {
        if (getCapacity() < n) {
            int doubled = 2 * getCapacity();
            FUN_00901e90(this, n < doubled ? doubled : n, sizeof(T));
        }
    }
    void setSize(int n) { reserve(n); m_size = n; }
    void setSizeUnchecked(int n) { m_size = n; }
    // Forwarding wrapper (a tail jump in the image) to the untyped exchange.
    __declspec(noinline) void FUN_00a82280(Array& other) { ((ArrayBase*)this)->FUN_00929ad0(*(ArrayBase*)&other); }
};

// String stored as a character array that includes the terminator.
struct String {
    Array<char> m_string;
    String() : m_string(1) { m_string.m_data[0] = 0; }
    String(const char* s, int len)
    {
        m_string.setSize(len + 1);
        FUN_009234e0(m_string.begin(), s, len);
        m_string.m_data[len] = 0;
    }
    String& operator=(const String& s)
    {
        int n = s.m_string.getSize();
        m_string.setSize(n);
        FUN_009234e0(m_string.begin(), s.m_string.begin(), n);
        return *this;
    }
};

struct Attribute {
    String name;
    String value;
    Attribute() {}
    Attribute(const Attribute& other) throw();
    void* operator new(size_t, void* p) { return p; }
    void operator delete(void*, void*) {}
};
// Array of objects with constructors: growth copy-constructs into new storage and destroys the old elements.
template <class T> struct ObjectArray {
    Array<T> m_array;
    __forceinline void reserve(int n)
    {
        int capacity = m_array.getCapacity();
        if (n > capacity) {
            int doubled = 2 * capacity;
            int newSize = n < doubled ? doubled : n;
            int size = m_array.getSize();
            Array<T> old;
            old.FUN_00a82280(m_array);
            m_array.reserve(newSize);
            construct(m_array.begin(), size, old.begin());
            m_array.setSizeUnchecked(size);
            destruct(old.begin(), old.getSize());
        }
    }
    static __forceinline void construct(T* dst, int n, const T* src)
    {
        for (int i = 0; i < n; ++i)
            new (&dst[i]) T(src[i]);
    }
    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            t[i].~T();
    }
    __forceinline void pushBack(const T& t)
    {
        int size = m_array.getSize();
        if (size == m_array.getCapacity())
            reserve(size ? size * 2 : 1);
        T* slot = m_array.begin() + size;
        m_array.setSizeUnchecked(size + 1);
        new (slot) T(t);
    }
};

inline bool IsSpace(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
// Skips blanks, tabs and line ends.
static __declspec(noinline) const char* FUN_00a80db0(const char* p)
{
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
        ++p;
    return p;
}

static __declspec(noinline) Result FUN_00a81460(const char* buffer, ObjectArray<Attribute>& attributes)
{
    const char* p = FUN_00a80db0(buffer);
    while (*p) {
        {
            // The block ends the pair's lifetime before the next whitespace skip, as the original orders them.
            Attribute attr;
            const char* start = p;
            while (!IsSpace(*p) && *p != '=') {
                if (*p++ == 0)
                    return RESULT_FAILURE;
            }
            attr.name = String(start, (int)(p - start));
            p = FUN_00a80db0(p);
            if (*p != '=')
                return RESULT_FAILURE;
            p = FUN_00a80db0(p + 1);
            if (*p != '"')
                return RESULT_FAILURE;
            ++p;
            start = p;
            while (*p != '"') {
                if (*p++ == 0)
                    return RESULT_FAILURE;
            }
            attr.value = String(start, (int)(p - start));
            attributes.pushBack(attr);
            ++p;
        }
        p = FUN_00a80db0(p);
    }
    return RESULT_SUCCESS;
}

// FUN_00a81460 is a file-local function with a register argument; this caller makes the compiler emit it.
void Caller00a81460(ObjectArray<Attribute>& attributes)
{
    g_out81460 = FUN_00a81460(g_in81460, attributes);
}
}
}   // namespace f3m_00a81460

// @f3 0x00a83480 (community match, verified in this file)
#pragma intrinsic(_ReadWriteBarrier)
extern unsigned int DAT_010f3170;
namespace f3m_00a83480 {
extern "C" void _ReadWriteBarrier(void);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

namespace f3_00a83480 {

struct HkThreadMemory {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual char* onStackOverflow(int size) throw();
    virtual void onStackUnderflow(void* ptr) throw();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_stackCurrent;
    int unk24;
    char* m_stackBase;
    char* m_stackEnd;

    __forceinline char* allocateStack(int nbytes) throw() {
        char* cur = m_stackCurrent;
        int pad = (nbytes + 16) & ~15;
        char* next = cur + pad;
        if (next <= m_stackEnd) {
            m_stackCurrent = next;
            return cur;
        }
        return onStackOverflow(pad);
    }

    __forceinline void deallocateStack(void* p) throw() {
        m_stackCurrent = (char*)p;
        if (p == m_stackBase) {
            onStackUnderflow(p);
        }
    }

    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};

void __cdecl FUN_00901e90(void* arr, int capacity, int stride) throw();
void __cdecl FUN_009234e0(void* dst, const void* src, int n) throw();

struct HkString {
    char* m_data;
    int m_len;
    unsigned int m_capFlags;
};

struct LocalCharArray {
    char* m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
    char* m_localMemory;

    __forceinline LocalCharArray(int capacity) throw()
        : m_data(0), m_size(0), m_capacityAndFlags(0x80000000u)
    {
        HkThreadMemory* mem = (HkThreadMemory*)TlsGetValue(DAT_010f3170);
        char* p = mem->allocateStack(capacity);
        m_data = p;
        m_localMemory = p;
        m_capacityAndFlags = capacity | 0x80000000u;
    }

    __forceinline void setSize(int n) throw() {
        int cap = m_capacityAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = cap * 2;
            FUN_00901e90(this, n < cap2 ? cap2 : n, 1);
        }
        m_size = n;
    }

    __forceinline ~LocalCharArray() throw() {
        char* local = m_localMemory;
        ((HkThreadMemory*)TlsGetValue(DAT_010f3170))->deallocateStack(local);
        if ((m_capacityAndFlags & 0x80000000u) == 0) {
            int cap = m_capacityAndFlags & 0x3fffffff;
            HkThreadMemory* mem = (HkThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, cap, 0x17);
        }
    }
};

struct HkClassMember {
    int FUN_0093dab0() throw();
    int FUN_0093dac0() throw();
};

struct BufState {
    char* m_data;
    int m_size;
};

struct BufWrap {
    BufState* m_state;
    int FUN_00a84d20(int size, int align) throw();
    __forceinline void* allocPtr(int size, int align) throw() {
        int off = FUN_00a84d20(size, align);
        char* base = m_state->m_data;
        _ReadWriteBarrier();
        return base + off;
    }
};

struct Reloc {
    void FUN_009b2f10(int offset, const char* name) throw();
};

struct MemStream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00a4a310(const void* mem, int size) throw();
    void FUN_00a49be0() throw();
    void read1(void* dst) throw();
    void read2(void* dst, int a) throw();
};

static __forceinline bool isSpace(int c) throw() {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void* __cdecl ext_use(void* p) throw();

static __declspec(noinline) int FUN_00a82e90(void* dst, MemStream* stream, int type) throw()
{
    void* s = ext_use(dst);
    if (type == 1) {
        stream->read1(s);
        stream->read1(s);
        stream->read1(s);
    } else if (type == 2) {
        stream->read1(s);
        stream->read2(s, type);
    }
    return (int)s;
}

static __declspec(noinline) int FUN_00a83480(HkClassMember* member, HkString* str, BufWrap* wrap, Reloc* reloc) throw()
{
    int count = 0;
    int subType = member->FUN_0093dab0();
    switch (subType) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 30:
    {
        int elemSize = member->FUN_0093dac0();
        MemStream is;
        is.FUN_00a4a310(str->m_data, str->m_len - 1);
        while (FUN_00a82e90(wrap->allocPtr(elemSize, 1), &is, subType) == 0) {
            count++;
            wrap->m_state->m_size += elemSize;
        }
        is.FUN_00a49be0();
        break;
    }
    case 20:
    case 21:
    case 28:
    {
        int start = 0;
        for (int i = 0; i < str->m_len - 1; ++i) {
            if (isSpace(str->m_data[i])) {
                if (start != i) {
                    int len = i - start;
                    LocalCharArray buf(len + 1);
                    FUN_009234e0(buf.m_data, str->m_data + start, len);
                    buf.setSize(len + 1);
                    buf.m_data[i - start] = 0;
                    int off = wrap->FUN_00a84d20(4, 1);
                    reloc->FUN_009b2f10(off, buf.m_data);
                    wrap->m_state->m_size += 4;
                    count++;
                }
                start = i + 1;
            }
        }
        if (start != str->m_len - 1) {
            int off = wrap->FUN_00a84d20(4, 1);
            reloc->FUN_009b2f10(off, str->m_data + start);
            wrap->m_state->m_size += 4;
            count++;
        }
        if (subType == 28) {
            count /= 2;
        }
        break;
    }
    default:
        break;
    }
    wrap->FUN_00a84d20(0, 16);
    wrap->m_state->m_size = (wrap->m_state->m_size + 15) & ~15;
    return count;
}

HkString* __cdecl get_s();
BufWrap* __cdecl get_w();
Reloc* __cdecl get_r();
volatile HkClassMember* g_member;
volatile int g_res;

void probe_caller_00a83480()
{
    HkClassMember* m = (HkClassMember*)g_member;
    g_res = FUN_00a83480(m, get_s(), get_w(), get_r());
}

}
}   // namespace f3m_00a83480

// @f3 0x00a8d160 (community match, verified in this file)
namespace f3m_00a8d160 {
namespace na8d160 {
struct FUN_00a8d060;
struct NodeArray {
    FUN_00a8d060** m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
    FUN_00a8d060*& operator[](int i) { return m_data[i]; }
};
struct Pool {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64;
    void* freeList68;
    int freeCount6c;
    void* FUN_008f6800(int units, int category);
};
struct FUN_00a8d060 {
    float values[8];
    unsigned short counts[8];
    NodeArray children;
    double unk40;
    FUN_00a8d060* unk48;
    const char* name;
    int unk50;
    int unk54;
    FUN_00a8d060(FUN_00a8d060* owner, const char* aName, int value4) throw();
    static void* operator new(unsigned int)
    {
        Pool* pool = (Pool*)f3m_00a8d1f0::FUN_00d9b080(DAT_010f3170);
        void* result = pool->freeList68;
        if (result) {
            --pool->freeCount6c;
            pool->freeList68 = *(void**)result;
            return result;
        }
        return pool->FUN_008f6800(6, 0x1b);
    }
    static void operator delete(void*) {}
};
// pdb: createNewNode | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: hkVersionPatchManager::findLastPatchIndexForUid)
static __declspec(noinline) FUN_00a8d060* FUN_00a8d160(FUN_00a8d060* parent, const char* name, int extra, bool findExisting)
{
    if (findExisting)
    {
        int i = 0;
        while (parent && name && i < parent->children.m_size)
        {
            if (parent->children[i]->name && f3m_00a8d1f0::hkString_strCmp(parent->children[i]->name, name) == 0)
                return parent->children[i];
            ++i;
        }
    }
    return new FUN_00a8d060(parent, name, extra);
}
FUN_00a8d060* Caller(FUN_00a8d060* parent, const char* name, int extra, bool findExisting)
{
    return FUN_00a8d160(parent, name, extra, findExisting);
}
}
}   // namespace f3m_00a8d160

// @f3 0x00a80ba0 (community match, verified in this file)
namespace f3m_00a80ba0 {
void CopyIfNonEmpty(char* dst, const char* src, int n);
int hkString_strLen(const char* s);
int hkString_strNcmp(const char* a, const char* b, unsigned int n);
int hkString_atoi(const char* s);

// Decodes XML character entities (&lt; &gt; &amp; &quot; &apos; and &#n;) from src into dst.
// Returns the decoded length, or -1 on a malformed entity.
int FUN_00a80ba0(char* dst, const char* source)
{
    char* out = dst;
    const char* src = source;
    while (*src) {
        char c = *src++;
        if (c == '&') {
            const char* start = src;
            while (*src != ';') {
                if (*src == 0)
                    return -1;
                src++;
            }
            src++;
            if (*start == '#') {
                int len = (int)(src - start) - 2;
                if (len >= 10)
                    return -1;
                int buf[3];
                CopyIfNonEmpty((char*)buf, start + 1, len);
                ((char*)buf)[len] = 0;
                *out++ = (char)hkString_atoi((char*)buf);
            } else {
                const char* entities[6];
                entities[0] = "<lt";
                entities[1] = ">gt";
                entities[2] = "&amp";
                entities[3] = "\"quot";
                entities[4] = "'apos";
                entities[5] = 0;
                int i;
                for (i = 0; entities[i]; i++) {
                    char ch = entities[i][0];
                    const char* name = entities[i] + 1;
                    if (hkString_strNcmp(start, name, hkString_strLen(name)) == 0) {
                        *out++ = ch;
                        break;
                    }
                }
                if (entities[i] == 0)
                    return -1;
            }
        } else {
            *out++ = c;
        }
    }
    *out = 0;
    return (int)(out - dst);
}
}   // namespace f3m_00a80ba0

// @f3 0x00a8db20 (community match, verified in this file)
namespace f3m_00a8db20 {
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
extern const unsigned int* DAT_010661dc[];
struct Heap {
    void* FUN_008f6f60(unsigned int bytes, int category);
    void FUN_008f6d90(void* memory, int bytes, int category);
};
struct ChildArray { void* data; int size; };
struct Node { int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c; ChildArray children; };
struct NodeArray { Node** data; int size; int GetLogicalSize() const { return size; } };
struct Layout {
    int first;
    int pages;
    int width0;
    int width1;
    int extra;
    int width;
    int unk18;
    float time;
    bool showTimers;
    unsigned int* colors;
};
struct Info { int unk00; int unk04; int unk08; int unk0c; };
struct Entry { Info* info; int unk04; int unk08; };
struct EntryList { Entry* data; };
struct FloatArray { float* data; int size; unsigned int capacity; };
struct SampleInfo { float range; };
struct Map12 {
    int* keys;
    int unk04;
    int hashMod;
    Map12() throw();
    void FUN_00922cf0();
    int First() const { int i = 0; for (; i <= hashMod; i++) if (keys[i] != -1) break; return i; }
    bool IsValid(int i) const { return i <= hashMod; }
    int Next(int i) const { for (i++; i <= hashMod; i++) if (keys[i] != -1) break; return i; }
};
void FUN_00901e90(FloatArray* array, int capacity, int elementSize);
// getTimerLimits lives in the same source file as FUN_00a8db20, so its body was visible there. This is a short
// stand-in (the real body is matched elsewhere): what matters to the caller is that it only writes through `range`
// (so the caller keeps range on the x87 stack later) and hands `arr` on to the array reserve FUN_00901e90.
__declspec(noinline) void FUN_00a8d760(NodeArray& nodes, Layout* lay, EntryList* list, float* range, FloatArray* arr)
{
    if (arr->size < lay->pages)
        FUN_00901e90(arr, lay->pages, 4);
    arr->size = lay->pages;
    *range = 0.0f;
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] > *range)
            *range = arr->data[i];
}
void FUN_00923500(void* dest, int value, unsigned int bytes);

static __declspec(noinline) void FUN_00a8be00(int digit, int width, int* dest)
{
    const unsigned int* glyph = DAT_010661dc[digit];
    for (int shift = 0; shift < 32; shift += 4) {
        int* p = (int*)((char*)dest + shift);
        const unsigned int* row = glyph + 6;
        for (int n = 7; n; --n) {
            if ((*row << shift) & 0xf0000000)
                *p = 0xff000000;
            row--;
            p += width;
        }
    }
}

static __declspec(noinline) void FUN_00a8be50(int frame, int* dest, int width)
{
    for (int div = 1000; div >= 1; div /= 10) {
        FUN_00a8be00(frame / div % 10, width, dest);
        dest += 7;
    }
}

static __declspec(noinline) void FUN_00a8d560(Info* info, int frame, ChildArray* children, int* row, int spacing,
    unsigned int* colors, int width, int drawWidth, float range, float start, Map12& timers)
{
    Map12 local;
    float scale = range / drawWidth;
    int count = info->unk0c == 0 ? info->unk04 : info->unk08;
    for (int i = 0; i < count; i++) {
        int* p = row + i;
        for (int n = spacing; n; --n) {
            *p = colors[((int*)children->data)[frame] & 7] + (int)(scale * start) + timers.hashMod;
            p += width;
        }
    }
    local.FUN_00922cf0();
}

// pdb: hkMonitorStreamAnalyzer::writeStatisticsDetailsToTexture | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, uconst, low
// pdb params: nodeList, input, frameInfos, texture, height, sampleInfo
void FUN_00a8db20(NodeArray& nodes, Layout* lay, EntryList* list, int** texture, int* height, SampleInfo* sampleInfo)
{
    int pages = lay->pages;
    int levels = nodes.GetLogicalSize();
    if (levels < 1)
        return;
    float range;
    FloatArray arr;
    arr.data = 0;
    arr.size = 0;
    arr.capacity = 0x80000000;
    FUN_00a8d760(nodes, lay, list, &range, &arr);
    int spacing = lay->width1 + lay->width0;
    int endFrame = lay->first + lay->pages;
    int total = (spacing * levels + lay->extra) * pages;
    int y = total;
    int border = pages > 1 ? 32 : 0;
    int drawWidth = lay->width - border;
    int numPixels = lay->width * total;
    Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
    unsigned int bytes = numPixels * 4;
    *texture = (int*)heap->FUN_008f6f60(bytes, 0x13);
    *height = total;
    FUN_00923500(*texture, 0, bytes);
    if (sampleInfo)
        sampleInfo->range = range;
    Map12 timers;
    for (int frame = lay->first; frame < endFrame; frame++) {
        y -= lay->extra;
        if (pages > 1)
            FUN_00a8be50(frame, *texture + (y - spacing) * lay->width, lay->width);
        for (int t = 0; t < levels; t++) {
            y -= spacing;
            // The original re-reads `texture` from its stack slot here. Reading it through a volatile view keeps
            // this read out of the parameter's register uses; that is what gives total edi and texture ebx as in
            // the original (a guess at the source: it reproduces the code, nothing else here did).
            FUN_00a8d560(list->data[t].info, frame, &nodes.data[t]->children,
                *(*(int** volatile*)&texture) + lay->width * y + border, lay->width0, lay->colors, lay->width, drawWidth,
                range, arr.data[frame - lay->first], timers);
        }
    }
    float pps = (drawWidth * 1000) / range;
    int offset = (int)(((int)lay->time % 1000) * 0.001f * pps);
    if (pps > 5.0f) {
        int x = border - offset;
        int i = 0;
        while (x < lay->width) {
            if (x >= 0) {
                for (int r = 0; r < total; r++)
                    (*texture)[lay->width * r + x] = 0xff0000ff;
            }
            i++;
            x = (int)(i * pps) - offset + border;
        }
    }
    int step = (int)((drawWidth * 16666) / range);
    if (step > 0) {
        for (int x = border - offset; x < lay->width; x += step) {
            if (x >= 0) {
                for (int r = 0; r < total; r++) {
                    (*texture)[lay->width * r + x] = 0xff00ff00;
                    (*texture)[lay->width * r + x + 1] = 0xff00ff00;
                }
            }
        }
    }
    if (lay->showTimers) {
        for (int it = timers.First(); timers.IsValid(it); it = timers.Next(it)) {
        }
    }
    timers.FUN_00922cf0();
    if ((arr.capacity & 0x80000000u) == 0) {
        int cap = arr.capacity & 0x3fffffff;
        Heap* h = (Heap*)DAT_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(arr.data, cap * 4, 0x17);
    }
}
}

// @f3 0x00a8e070 (community match, verified in this file)
// 0x00a8e070: Havok 5.5.0 hkMonitorStreamAnalyzer::makeStatisticsTreeForSingleFrame (hkBase, hkMonitorStreamAnalyzer.cpp),
// written from the SDK headers and the library's debug records. Callees carry the game's addresses:
//   FUN_00a8d160 createNewNode (static helper of the same file), FUN_00a8d060 Node::Node, FUN_00a8c240 Node::setTimers,
//   hkString_strCmp hkString::strCmp, FUN_00901f10 hkArrayUtil::_reserveMore, FUN_00901e90 hkArrayUtil::_reserve,
//   FUN_008f6800 hkThreadMemory::onRowEmpty (the game's build passes the memory class too), FUN_008f6d90
//   hkThreadMemory::deallocateChunk, FUN_00d9b080 TlsGetValue, DAT_010f3170 hkThreadMemory__s_threadMemoryInstance.
namespace hk550_a8e070 {

typedef unsigned int hkUint32;
typedef unsigned short hkUint16;
typedef unsigned long hkUlong;
typedef float hkReal;

enum HK_MEMORY_CLASS
{
	HK_MEMORY_CLASS_ARRAY = 0x17,
	HK_MEMORY_CLASS_MONITOR = 0x1b
};

class hkBool
{
	public:
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

__declspec(dllimport) void* __stdcall FUN_00d9b080( unsigned long dwTlsIndex ) throw();

template<typename T>
class hkThreadLocalData
{
	public:
		__forceinline T getData() const
		{
			return (T)(hkUlong)FUN_00d9b080(m_slotID);
		}
		unsigned long m_slotID;
};

class hkMemory;

class hkThreadMemory
{
	public:
		void FUN_008f6d90( void*, int nbytes, HK_MEMORY_CLASS ) throw();

		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );

		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);

		static inline hkThreadMemory* getInstancePtr();
		static inline hkThreadMemory& getInstance();

		virtual void releaseCachedMemory();
		virtual ~hkThreadMemory();

	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);

	public:
		enum
		{
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10
		};

		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};

		static __forceinline int constSizeToRow( int size );

	protected:
		void* FUN_008f6800( int row, HK_MEMORY_CLASS cl ) throw();

	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;

		struct FreeList
		{
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}

			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};

		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

extern hkThreadLocalData<hkThreadMemory*> DAT_010f3170;

hkThreadMemory* hkThreadMemory::getInstancePtr()
{
	return DAT_010f3170.getData();
}

hkThreadMemory& hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

int hkThreadMemory::constSizeToRow( int size )
{
	if (size <= 8 )	return 1;
	else if (size <= 16 )	return 2;
	else if (size <= 32 )	return 3;
	else if (size <= 48 )	return 4;
	else if (size <= 64 )	return 5;
	else if (size <= 96 )	return 6;
	else if (size <= 128 )	return 7;
	else if (size <= 160 )	return 8;
	else if (size <= 192 )	return 9;
	else if (size <= 256 )	return 10;
	else if (size <= 320 )	return 11;
	else if (size <= 512 )	return 12;
	else if (size <= 1024)	return 13;
	else if (size <= 2048)	return 14;
	else if (size <= 4096)	return 15;
	else if (size <= 8192)	return 16;
	else
	{
		return -1;
	}
}

void* hkThreadMemory::allocateChunkConstSize(int nbytes, HK_MEMORY_CLASS cl)
{
	int row = constSizeToRow(nbytes);
	if( void* p = m_free_list[row].get() )
	{
		return p;
	}
	return FUN_008f6800(row, cl);
}

void FUN_00901e90( void*, int numElem, int sizeElem ) throw();
void FUN_00901f10( void* array, int sizeElem ) throw();

template <typename T>
class hkArray
{
	public:
		__forceinline hkArray(T* ptr, int size, int capacity);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		__forceinline void pushBack(const T& e);
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);

		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};

	protected:
		void releaseMemory();

		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		__forceinline hkInplaceArray(int size = 0);
		__forceinline ~hkInplaceArray(){}

	public:
		T m_storage[N];
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().FUN_008f6d90( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::popBack( int numRemove )
{
	m_size -= numRemove;
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		FUN_00901e90(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		FUN_00901f10( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}

class hkString
{
	public:
		static int hkString_strCmp( const char* s1, const char* s2 ) throw();
};

class hkMonitorStream
{
	public:
		struct Command
		{
			const char* m_commandAndMonitor;
		};

		struct AddValueCommand : public hkMonitorStream::Command
		{
			float m_value;
		};

		struct TimerCommand : public hkMonitorStream::Command
		{
			hkUint32	m_time0;
			hkUint32	m_time1;
		};

		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};

struct hkMonitorStreamFrameInfo;

// hkMonitorStreamAnalyzer::Node
struct FUN_00a8d060
{
	__forceinline void* operator new(unsigned int nbytes)	{ return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); }
	void operator delete(void* p);

	enum NodeType
	{
		NODE_TYPE_TIMER,
		NODE_TYPE_DIRECTORY,
		NODE_TYPE_SINGLE,
	};

	hkReal			m_value[8];
	hkUint16		m_count[8];
	hkArray<struct FUN_00a8d060*> m_children;
	double			m_absoluteStartTime;
	FUN_00a8d060*	m_parent;
	const char*		m_name;
	hkUint32		m_userFlags;
	hkUint32		m_type;

	FUN_00a8d060(FUN_00a8d060* parent, const char* name, NodeType type ) throw();

	void FUN_00a8c240( const hkMonitorStreamFrameInfo& frameInfo, const hkMonitorStream::TimerCommand& start, const hkMonitorStream::TimerCommand& end) throw();

	~FUN_00a8d060();
};

class hkMonitorStreamAnalyzer
{
	public:
		typedef FUN_00a8d060 Node;

		static Node* FUN_00a8e070( const char* frameStart, const char* frameEnd, const hkMonitorStreamFrameInfo& info, const char* rootNodeName, hkBool reuseNodesIfPossible );
};

// createNewNode
static hkMonitorStreamAnalyzer::Node* FUN_00a8d160( hkMonitorStreamAnalyzer::Node* parent, const char* name, hkMonitorStreamAnalyzer::Node::NodeType type, bool wantNodeReuse )
{
	if ( wantNodeReuse )
	{
		for ( int c = 0; parent && name && c < parent->m_children.getSize(); c++ )
		{
			if ( parent->m_children[c]->m_name && hkString::hkString_strCmp( parent->m_children[c]->m_name, name ) == 0 )
			{
				return parent->m_children[c];
			}
		}
	}
	return new hkMonitorStreamAnalyzer::Node( parent, name, type );
}

// pdb: hkMonitorStreamAnalyzer::makeStatisticsTreeForSingleFrame | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, caller_sim, low
// pdb params: frameStart, frameEnd, frameInfo, rootNodeName, reuseNodesIfPossible
hkMonitorStreamAnalyzer::Node* hkMonitorStreamAnalyzer::FUN_00a8e070( const char* frameStart, const char* frameEnd, const hkMonitorStreamFrameInfo& frameInfo, const char* rootNodeName, hkBool reuseNodesIfPossible )
{
	const char* currentStreamPtr = frameStart;
	Node* currentNode = new Node( 0, rootNodeName, Node::NODE_TYPE_DIRECTORY );
	Node* rootNode = currentNode;
	hkInplaceArray<hkMonitorStream::TimerCommand,16> timerStack;

	hkInplaceArray<hkMonitorStream::TimerCommand,16> debugMismatchCheckerTimerStack;

	while( currentStreamPtr < frameEnd )
	{
		{
			const hkMonitorStream::TimerCommand* com = reinterpret_cast<const hkMonitorStream::TimerCommand*>( currentStreamPtr );
			if ( hkUlong(com->m_commandAndMonitor) < 10 )
			{
				int* elfId = (int*)com;
				currentStreamPtr = (const char*)&elfId[1];
				continue;
			}
		}
		const char* string = *(const char**)currentStreamPtr;

		switch( string[0] )
		{
		case 'T':
			{
				currentNode = FUN_00a8d160( currentNode, &string[2], Node::NODE_TYPE_TIMER, reuseNodesIfPossible );
				const hkMonitorStream::TimerCommand* com = reinterpret_cast<const hkMonitorStream::TimerCommand*>( currentStreamPtr );
				timerStack.pushBack( *com );
				debugMismatchCheckerTimerStack.pushBack( *com );
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'E':
			{
				if ( timerStack.getSize() == 0 )
				{
					return rootNode;
				}
				const hkMonitorStream::TimerCommand& start = timerStack[ timerStack.getSize() - 1 ];
				const hkMonitorStream::TimerCommand* com = reinterpret_cast<const hkMonitorStream::TimerCommand*>( currentStreamPtr );

				if ( string[2] && hkString::hkString_strCmp( &start.m_commandAndMonitor[2], &string[2] ) )
				{
					return rootNode;
				}

				currentNode->FUN_00a8c240( frameInfo, start, *com );
				currentNode = currentNode->m_parent;
				timerStack.popBack();
				debugMismatchCheckerTimerStack.setSize( debugMismatchCheckerTimerStack.getSize() - 1 );
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'L':
			{
				const hkMonitorStream::TimerBeginListCommand* com = reinterpret_cast<const hkMonitorStream::TimerBeginListCommand*>( currentStreamPtr );

				timerStack.pushBack( *com );
				debugMismatchCheckerTimerStack.pushBack( *com );
				currentNode = FUN_00a8d160( currentNode, &string[2], Node::NODE_TYPE_TIMER, reuseNodesIfPossible );

				{
					hkMonitorStream::TimerCommand com2 = *com;
					com2.m_commandAndMonitor = com->m_nameOfFirstSplit;
					timerStack.pushBack( com2 );
					debugMismatchCheckerTimerStack.pushBack( com2 );
					currentNode = FUN_00a8d160( currentNode, &com2.m_commandAndMonitor[2], Node::NODE_TYPE_TIMER, reuseNodesIfPossible );
				}
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'S':
			{
				if ( timerStack.getSize() == 0 )
				{
					return rootNode;
				}
				hkMonitorStream::TimerCommand& start = timerStack[ timerStack.getSize() - 1 ];
				const hkMonitorStream::TimerCommand* com = reinterpret_cast<const hkMonitorStream::TimerCommand*>( currentStreamPtr );
				currentNode->FUN_00a8c240( frameInfo, start, *com );
				currentNode = FUN_00a8d160( currentNode->m_parent, &string[2], Node::NODE_TYPE_TIMER, reuseNodesIfPossible );
				start = *com;
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'l':
			{
				const hkMonitorStream::TimerCommand* com = reinterpret_cast<const hkMonitorStream::TimerCommand*>( currentStreamPtr );

				if ( timerStack.getSize() <= 1 )
				{
					return rootNode;
				}
				{
					const hkMonitorStream::TimerCommand& start = timerStack[ timerStack.getSize() - 1 ];
					if ( start.m_commandAndMonitor[0] != 'S' )
					{
						return rootNode;
					}
					currentNode->FUN_00a8c240( frameInfo, start, *com );
					currentNode = currentNode->m_parent;
					timerStack.popBack();
					debugMismatchCheckerTimerStack.setSize( debugMismatchCheckerTimerStack.getSize() - 1 );
				}
				{
					const hkMonitorStream::TimerCommand& start = timerStack[ timerStack.getSize() - 1 ];
					currentNode->FUN_00a8c240( frameInfo, start, *com );
					currentNode = currentNode->m_parent;
					timerStack.popBack();
					debugMismatchCheckerTimerStack.setSize( debugMismatchCheckerTimerStack.getSize() - 1 );
				}
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'M':
			{
				const hkMonitorStream::AddValueCommand* com = reinterpret_cast<const hkMonitorStream::AddValueCommand*>( currentStreamPtr );
				Node* node = FUN_00a8d160( currentNode, &string[2], Node::NODE_TYPE_SINGLE, reuseNodesIfPossible );
				node->m_value[0] += com->m_value;
				node->m_count[0] += 1;
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'P':
			{
				const hkMonitorStream::Command* com = reinterpret_cast<const hkMonitorStream::Command*>( currentStreamPtr );
				currentNode = FUN_00a8d160( currentNode, &string[2], Node::NODE_TYPE_DIRECTORY, reuseNodesIfPossible );
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'p':
			{
				const hkMonitorStream::Command* com = reinterpret_cast<const hkMonitorStream::Command*>( currentStreamPtr );
				currentNode = currentNode->m_parent;
				if ( currentNode == 0 )
				{
					return rootNode;
				}
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		case 'F':
			{
				break;
			}
		case 'N':
			{
				const hkMonitorStream::Command* com = reinterpret_cast<const hkMonitorStream::Command*>( currentStreamPtr );
				currentStreamPtr = (const char*)(com + 1);
				break;
			}
		default:
			return rootNode;
		}
	}

	return rootNode;
}

}

// @f3 0x00a87ae0 (community match, verified in this file)
namespace f3m_00a87ae0 {
struct Node
{
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
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
    char unk38;
    char unk39;
    char unk3a;
    char unk3b;
    char unk3c;
    char unk3d;
    char unk3e;
    char unk3f;
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
    Node* unk70;
    Node* unk74;
};
struct Hdr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct Sub
{
    int unk00;
};
struct State
{
    int pos;
    char flag;
    char unk05;
    short unk06;
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
    double unk40;
    void Init(State* st, Node* n, Sub* sub);
};
struct S1
{
    char flag;
    char unk01;
    short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
void __stdcall FUN_00a86290(Node* n);
void __stdcall FUN_00a86fc0(Node* n, void* b, State* st, S1* s);

struct Walker
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Hdr* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Sub unk30;
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
    char* FUN_00a86260(char* tmp, Node* n, State* st);
    void FUN_00a86210(Node* n);
    int FUN_00a87710(Node* n, void* b, State* st);
    int FUN_00a87770(Node* n, void* b, State* st, S1* s);
    int FUN_00a87ae0(Node* n, void* b, State* st);
};

// pdb: hkpMoppDefaultAssembler::assemblesubNode | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, low
// pdb params: currentNode, parentInfo, currentInfo
int Walker::FUN_00a87ae0(Node* n, void* b, State* st)
{
    State cc;
    if (n->unk38)
        return 3;
    if (st->pos <= unk18 && st->pos % unk60 == 0 && !st->flag)
    {
        st->flag = 1;
        int r = -1;
        int saved = unk18;
        int cur;
        while (!n->unk38)
        {
            cur = unk10->unk0c;
            cc = *st;
            r = FUN_00a87ae0(n, b, &cc);
            if (unk28 > unk24)
                break;
            if (cur == unk10->unk0c)
            {
                if (unk18 < 0)
                    break;
                unk18 -= unk60;
            }
        }
        unk18 = saved;
        st->flag = 0;
        return r;
    }
    char tmp;
    if (n->unk04)
    {
        FUN_00a86290(n);
        if (*FUN_00a86260(&tmp, n, st))
            return FUN_00a87710(n, b, st);
    }
    else
    {
        S1 s1;
        s1.flag = 0;
        FUN_00a86fc0(n, b, st, &s1);
        int r1 = -1;
        Node* c = n->unk74;
        if (c)
        {
            cc.Init(st, c, &unk30);
            r1 = FUN_00a87ae0(c, (void*)st, &cc);
            if (r1 >= 0)
                FUN_00a86210(c);
        }
        Node* c2 = n->unk70;
        if (c2)
        {
            cc.Init(st, c2, &unk30);
            int r2 = FUN_00a87ae0(c2, (void*)st, &cc);
            if (r2 >= 0)
            {
                FUN_00a86210(c2);
                if (r1 >= 0 && *FUN_00a86260(&tmp, n, st))
                {
                    unk28 += 1;
                    return FUN_00a87770(n, b, st, &s1) + r2 + r1;
                }
            }
        }
    }
    return -1;
}
}   // namespace f3m_00a87ae0

// @f3 0x00a80500 (community match, verified in this file)
namespace f3m_00a80500 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
namespace f3m_00a80500 {
struct A80500Alloc { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct A80500Obj {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a80290();
    void* FUN_00a80500(int flags);
};
// pdb: hkPackfileData::`scalar deleting destructor' | hkPackfileData.obj | fnv360_0822_retail, vtable_prefix, high
void* A80500Obj::FUN_00a80500(int flags)
{
    FUN_00a80290();
    if (flags & 1) {
        A80500Alloc* alloc = (A80500Alloc*)DAT_00d9b080(DAT_010f3170);
        alloc->FUN_008f6d90(this, memSizeAndFlags, 0x15);
    }
    return this;
}
}
}   // namespace f3m_00a80500

// @f3 0x00a80530 (community match, verified in this file)
namespace f3m_00a80530 {
// claim clm_3bd1923456c94670b8c3 — FUN_00a80530 @ 0x00a80530 (24 bytes)
// Entry reads esi (the Obj* argument) without writing it, and it lives across the
// call to Obj::m() (0x0093d8c0, ?m@Obj@@QAEHXZ), so /O2 gave this static function a
// private convention with the pointer in esi.  Structure: call m(); if 0 return 1;
// else tail-call m().
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int GetKind() throw();
  int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkb0; int FUN_00959f80() throw(); int FUN_0095a000() throw(); int FUN_0095a020() throw(); int m(); };

volatile void* g_00a80530_in;
volatile int g_00a80530_out;

// pdb: getNumElementsInMember | hkDataObjectUtil.obj | fnv360_0822_retail, caller_sim, low
static __declspec(noinline) int FUN_00a80530(Obj* o)
{
    if (o->m())
        return o->m();
    return 1;
}

void caller_00a80530()
{
    g_00a80530_out = FUN_00a80530((Obj*)g_00a80530_in);
}
}   // namespace f3m_00a80530

// @f3 0x00a8c7a0 (community match, verified in this file)
namespace f3m_00a8c7a0 {
namespace f3m_00a8c7a0
{
struct RecEntry
{
    char unk00[0x4c];
    const char* unk4c;
};
struct RecBox
{
    char unk00[0x30];
    RecEntry** unk30;
    int unk34;
};
int __cdecl hkString_strCmp(const char* a, const char* b);

// pdb: hkFindChildByName | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap_sim, low
static __declspec(noinline) RecEntry* FUN_00a8c7a0(RecBox* box, const char* name, bool abFallbackToFirst)
{
    int i = 0;
    while (i < box->unk34)
    {
        RecEntry** p = &box->unk30[i];
        if (hkString_strCmp(name, (*p)->unk4c) == 0)
            return box->unk30[i];
        i++;
    }
    if (abFallbackToFirst && box->unk34 > 0)
        return box->unk30[0];
    return 0;
}

RecBox* volatile g_box;
const char* volatile g_name;
volatile bool g_fallback;
RecEntry* volatile g_result;
void Caller00a8c7a0()
{
    g_result = FUN_00a8c7a0(g_box, g_name, g_fallback);
}
}
}   // namespace f3m_00a8c7a0

// @f3 0x00a8eee0 (community match, verified in this file)
namespace f3m_00a8eee0 {

struct ReportStream;
struct ThreadMemory;
extern unsigned int DAT_010f3170;
typedef ThreadMemory* (__stdcall *ThreadMemoryLookup)(unsigned int);
extern ThreadMemoryLookup DAT_00d9b080;

struct Node {
    void FUN_00a8d0f0();
};

struct ReuseNodes {
    unsigned char value;
    ReuseNodes(bool reuse) : value(reuse) {}
};

struct NodeArray {
    Node** data;
    int size;
    unsigned int capacityAndFlags;

    NodeArray() : data(0), size(0), capacityAndFlags(0x80000000u) {}

    int capacity() const { return capacityAndFlags & 0x3fffffffu; }
    int getSize() const { return size; }
    Node*& operator[](int index) { return data[index]; }
    void pushBack(Node* const& node);
    void releaseStorage(ThreadMemoryLookup lookup);
};

void __cdecl FUN_00901f10(NodeArray*, int);

void NodeArray::pushBack(Node* const& node) {
    if (size == capacity())
        FUN_00901f10(this, sizeof(Node*));
    data[size++] = node;
}

struct FreeBlock {
    FreeBlock* next;
};

struct FreeList {
    FreeBlock* head;
    int count;

    void put(void* pointer) {
        count += 1;
        FreeBlock* block = static_cast<FreeBlock*>(pointer);
        block->next = head;
        head = block;
    }
};

struct ThreadMemory {
    unsigned int field00, field04, field08, field0c;
    unsigned int field10, field14, field18, field1c;
    char* stackCurrent;
    void* previousStack;
    char* stackBase;
    char* stackEnd;
    int stackSize;
    int maxFreeCount;
    FreeList freeLists[17];

    void FUN_008f6890(int row, void* block, int memoryClass);
    void FUN_008f6d90(void* block, int bytes, int memoryClass);

    void releaseNode(void* node) {
        if (freeLists[6].count >= maxFreeCount)
            FUN_008f6890(6, node, 0x1b);
        else
            freeLists[6].put(node);
    }
};

void NodeArray::releaseStorage(ThreadMemoryLookup lookup) {
    if (!(capacityAndFlags & 0x80000000u)) {
        int ownedCapacity = capacity();
        ThreadMemory* memory = lookup(DAT_010f3170);
        memory->FUN_008f6d90(data, ownedCapacity * sizeof(Node*), 0x17);
    }
}

void __cdecl FUN_00a8e7b0(ReportStream&, NodeArray&, int, int, int, const char*, bool);

struct FrameInfoArrays {
    void* data;
    int size;
    unsigned int capacityAndFlags;
};

struct CaptureBuffer {
    char* data;
    int size;
    unsigned int capacityAndFlags;
};

struct MonitorAnalyzer {
    FrameInfoArrays frameInfos;
    CaptureBuffer capture;
    int numThreads;
    int numSpus;
    const char* overviewNodeName;

    Node* __cdecl FUN_00a8e6b0(int frame, ReuseNodes reuseNodes);
    void FUN_00a8eee0(ReportStream& stream, int reportLevel);
};

// pdb: hkMonitorStreamAnalyzer::writeStatistics | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, caller_sim, low
// pdb params: outStream, reportLevel
void MonitorAnalyzer::FUN_00a8eee0(ReportStream& stream, int reportLevel) {
    NodeArray nodes;
    for (int i = 0; i < frameInfos.size; ++i) {
        Node* node = FUN_00a8e6b0(i, false);
        nodes.pushBack(node);
    }

    FUN_00a8e7b0(stream, nodes, numThreads, numSpus, reportLevel, overviewNodeName, true);

    ThreadMemoryLookup lookup = DAT_00d9b080;
    for (int i = 0; i < nodes.getSize(); ++i) {
        Node* node = nodes[i];
        if (node) {
            node->FUN_00a8d0f0();
            lookup(DAT_010f3170)->releaseNode(node);
        }
    }

    nodes.releaseStorage(lookup);
}

}
