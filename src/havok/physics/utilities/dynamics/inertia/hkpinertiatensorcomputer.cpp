#include "f3_common.h"
// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Object
{
};
void __cdecl FUN_00cebdf0(float* source, float value, Object* destination);
// Multiplies the float at source by scale and passes the result to FUN_00cebdf0 along with source and destination.
// @fnv 0x00cebe50
// pdb: hkpInertiaTensorComputer::setAndScaleToDensity | hkpInertiaTensorComputer.obj | tesv_win, hash, low
void __cdecl FUN_00cebe50(float* source, float scale, Object* destination)
{
    float result = *source * scale;
    FUN_00cebdf0(source, result, destination);
}

struct FUN_00cebe80_Struct
{
    float unk00;
    float unk04;
    float unk08;
};

// Subtracts fParam2 times products of pThis's components from the diagonal of pOut and adds the off-diagonal products to its symmetric entries.
// @fnv 0x00cebe80
// pdb: hkpInertiaTensorComputer::shiftInertiaToCom | hkpInertiaTensorComputer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkInertiaTensorComputer::shiftInertiaToCom)
// pdb params: shift, mass, inertia
void __cdecl FUN_00cebe80(FUN_00cebe80_Struct* pThis, float fScale, float* pMatrix)
{
    float fValue;

    fValue = pMatrix[0] - fScale * (pThis->unk08 * pThis->unk08 + pThis->unk04 * pThis->unk04);
    pMatrix[0] = fValue;

    fValue = pMatrix[5] - fScale * (pThis->unk00 * pThis->unk00 + pThis->unk08 * pThis->unk08);
    pMatrix[5] = fValue;

    fValue = pMatrix[10] - fScale * (pThis->unk00 * pThis->unk00 + pThis->unk04 * pThis->unk04);
    pMatrix[10] = fValue;

    fValue = pThis->unk00 * fScale * pThis->unk04 + pMatrix[1];
    pMatrix[1] = fValue;
    pMatrix[4] = fValue;

    fValue = fScale * pThis->unk04 * pThis->unk08 + pMatrix[6];
    pMatrix[6] = fValue;
    pMatrix[9] = fValue;

    fValue = fScale * pThis->unk08 * pThis->unk00 + pMatrix[8];
    pMatrix[8] = fValue;
    pMatrix[2] = fValue;
}

// @fnv 0x00cebf30
// pdb: hkInertiaTensorComputer::shiftInertiaFromCom | hkInertiaTensorComputer.obj | tesv_win, hash, low
void __cdecl AddInertiaTensor(float* param_1, float fScale, float* pMatrix)
{
    float fOffDiag;
    *pMatrix = *pMatrix + fScale * (param_1[1] * param_1[1] + param_1[2] * param_1[2]);
    pMatrix[5] = (param_1[0] * param_1[0] + param_1[2] * param_1[2]) * fScale + pMatrix[5];
    pMatrix[10] = (param_1[0] * param_1[0] + param_1[1] * param_1[1]) * fScale + pMatrix[10];
    fOffDiag = pMatrix[1] - param_1[0] * fScale * param_1[1];
    pMatrix[1] = fOffDiag;
    pMatrix[4] = fOffDiag;
    fOffDiag = pMatrix[6] - param_1[1] * fScale * param_1[2];
    pMatrix[6] = fOffDiag;
    pMatrix[9] = fOffDiag;
    fOffDiag = pMatrix[8] - param_1[0] * (param_1[2] * fScale);
    pMatrix[8] = fOffDiag;
    pMatrix[2] = fOffDiag;
}

struct FUN_00cec6b0_cls
{
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
    float m_64;
    float m_68;
    float m_6C;
    float m_70;
    float m_74;
    float m_78;
    float m_7C;
    float m_80;
    float m_84;
    float m_88;

    void FUN_00cec6b0(float a1, float b, float* p, float* M);
};

// @fnv 0x00cec6b0
// pdb: InternalInertiaTensorComputer::computeInertialTensorInternal | hkpInertiaTensorComputer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: mass, density, r, J
void FUN_00cec6b0_cls::FUN_00cec6b0(float a1, float afScale, float* p, float* pMatrix)
{
    p[0] = m_68 / m_64;
    p[1] = m_6C / m_64;
    p[2] = m_70 / m_64;

    pMatrix[0] = afScale * (m_7C + m_78);
    pMatrix[5] = afScale * (m_7C + m_74);
    pMatrix[10] = afScale * (m_78 + m_74);

    float t = -afScale * m_80;
    float r;
    r = t;
    pMatrix[1] = r;
    pMatrix[4] = r;
    t = -afScale * m_84;
    r = t;
    pMatrix[6] = r;
    pMatrix[9] = r;
    t = -afScale * m_88;
    r = t;
    pMatrix[8] = r;
    pMatrix[2] = r;

    pMatrix[0] = pMatrix[0] - a1 * (p[1] * p[1] + p[2] * p[2]);
    pMatrix[5] = pMatrix[5] - (p[2] * p[2] + p[0] * p[0]) * a1;
    pMatrix[10] = pMatrix[10] - (p[0] * p[0] + p[1] * p[1]) * a1;

    t = (a1 * p[0]) * p[1] + pMatrix[1];
    r = t;
    pMatrix[1] = r;
    pMatrix[4] = r;
    t = (a1 * p[1]) * p[2] + pMatrix[6];
    r = t;
    pMatrix[6] = r;
    pMatrix[9] = r;
    t = (a1 * p[2]) * p[0] + pMatrix[8];
    r = t;
    pMatrix[8] = r;
    pMatrix[2] = r;
}

struct CECCD0Value
{
    float m_uiFilterValue;

    void set(float v);
    void ScaleValue(float scale);
};

// @fnv 0x00ceccd0
// pdb: hkpMassProperties::scaleToDensity | hkInertiaTensorComputer.obj | tesv_win, hash, low
void CECCD0Value::ScaleValue(float scale)
{
    set(m_uiFilterValue * scale);
}

struct S_00ced230_T
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
};
static inline float S_MaxGT(float x, float y)
{
    return (x > y) ? x : y;
}
static inline float S_MaxLT(float x, float y)
{
    return (x < y) ? y : x;
}
// @fnv 0x00ced230
// pdb: hkpInertiaTensorComputer::clipInertia | hkpInertiaTensorComputer.obj | tesv_win, hash, low
void __cdecl FUN_00ced230(float afDivisor, S_00ced230_T* pData)
{
    float a = pData->unk50;
    a = S_MaxGT(a, pData->unk64);
    a = S_MaxGT(a, pData->unk78);
    a = a / afDivisor;
    pData->unk50 = S_MaxGT(pData->unk50, a);
    pData->unk64 = S_MaxLT(a, pData->unk64);
    pData->unk78 = S_MaxLT(a, pData->unk78);
}

struct S_00cee1c0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};

struct S_00cee1c0_Router
{
    unsigned int cursor;
    int unk04;
    int unk08;
    int unk0C;
    S_00cee1c0_Heap* heap;
};

struct S_00cee1c0_Arr
{
    unsigned int* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    unsigned int* m_pTrailingData;
};

S_00cee1c0_Router* FUN_00c85750();
float __cdecl FUN_00cedec0(S_00cee1c0_Arr* arr, int unk, float value);

namespace fnv_anon_00cec3d0 {}
using namespace fnv_anon_00cec3d0;
namespace fnv_anon_00cec3d0 {
struct S00cec3d0_Base
{
    int A;
    int B;
    int C;
    float P1;
    float Pa;
    float Pb;
    float m_fComponent0;
    float m_fComponent1;
    float m_fComponent2;
    float m_fComponent3;
    float m_fComponent4;
    float m_fComponent5;
    float m_fComponent6;

    __declspec(noinline) void FUN_00cec000(const float* v);
};
}

struct S00cec3d0_Face : S00cec3d0_Base
{
    float Fa;
    float Fb;
    float Fc;
    float m_fVertex0X;
    float m_fVertex0Y;
    float m_fVertex0Z;
    float m_fVertex1X;
    float m_fVertex1Y;
    float m_fVertex1Z;
    float m_fVertex2X;
    float m_fVertex2Y;
    float m_fVertex2Z;

    void FUN_00cec3d0(const float* verts, const float* n);
};

static inline float S00cec3d0_Sqr(float x)
{
    return x * x;
}
static inline float S00cec3d0_Cube(float x)
{
    return x * x * x;
}

void S00cec3d0_Base::FUN_00cec000(const float* v)
{
    P1 = v[A] * v[B];
    Pa = v[A];
}

// Calls FUN_00cec000, then fills Fa, Fb, Fc and the m_fVertex fields from verts, normal n and the base fields using polynomials in 1/n[C].
// @fnv 0x00cec3d0
// pdb: InternalInertiaTensorComputer::compFaceIntegrals | hkInertiaTensorComputer.obj | tesv_win, hash, low
void S00cec3d0_Face::FUN_00cec3d0(const float* verts, const float* apNormal)
{
    FUN_00cec000(verts);
    float w = -apNormal[0] * verts[0] - verts[1] * apNormal[1] - verts[2] * apNormal[2];
    float k1 = 1.0f / apNormal[C];
    float k2 = k1 * k1;
    float k3 = k2 * k1;
    float k4 = k3 * k1;

    Fa = k1 * Pa;
    Fb = k1 * Pb;
    Fc = -k2 * (apNormal[A] * Pa + apNormal[B] * Pb + w * P1);

    m_fVertex0X = k1 * m_fComponent0;
    m_fVertex0Y = k1 * m_fComponent2;
    m_fVertex0Z =
        k3 * (S00cec3d0_Sqr(apNormal[A]) * m_fComponent0 + 2.0 * apNormal[A] * apNormal[B] * m_fComponent1 +
              S00cec3d0_Sqr(apNormal[B]) * m_fComponent2 + w * (2.0 * (apNormal[A] * Pa + apNormal[B] * Pb) + w * P1));

    m_fVertex1X = k1 * m_fComponent3;
    m_fVertex1Y = k1 * m_fComponent6;
    m_fVertex1Z =
        -k4 *
        (S00cec3d0_Cube(apNormal[A]) * m_fComponent3 + 3.0 * S00cec3d0_Sqr(apNormal[A]) * apNormal[B] * m_fComponent4 +
         3.0 * apNormal[A] * S00cec3d0_Sqr(apNormal[B]) * m_fComponent5 + S00cec3d0_Cube(apNormal[B]) * m_fComponent6 +
         3.0 * w *
             (S00cec3d0_Sqr(apNormal[A]) * m_fComponent0 + 2.0 * apNormal[A] * apNormal[B] * m_fComponent1 +
              S00cec3d0_Sqr(apNormal[B]) * m_fComponent2) +
         w * w * (3.0 * (apNormal[A] * Pa + apNormal[B] * Pb) + w * P1));

    m_fVertex2X = k1 * m_fComponent4;
    m_fVertex2Y = -k2 * (apNormal[A] * m_fComponent5 + apNormal[B] * m_fComponent6 + w * m_fComponent2);
    m_fVertex2Z = k3 * (S00cec3d0_Sqr(apNormal[A]) * m_fComponent3 + 2.0 * apNormal[A] * apNormal[B] * m_fComponent4 +
                        S00cec3d0_Sqr(apNormal[B]) * m_fComponent5 +
                        w * (2.0 * (apNormal[A] * m_fComponent0 + apNormal[B] * m_fComponent1) + w * Pa));
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps();
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
}
struct Vector
{
    union
    {
        __m128 q;
        struct
        {
            float x, y, z, w;
        };
    };
    Vector()
    {}
    Vector(const Vector& other) : q(other.q)
    {}
    void operator=(const Vector& other)
    {
        q = other.q;
    }
    void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    int maxAxisSecond() const
    {
        if (x < y)
            return y < z ? 2 : 1;
        return x < z ? 2 : 0;
    }
    int maxAxis() const
    {
        if (x < y)
        {
            if (z > y)
                return 2;
            return 1;
        }
        if (z > x)
            return 2;
        return 0;
    }
};
struct Matrix
{
    Vector c0, c1, c2;
};

extern "C" __m128 _mm_load_ss(const float*);
struct Sub
{
    void Multiply(const Vector* p);
};
struct Owner
{
    int unk00;
    float m04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    Sub m20;
};
// Multiplies m04 by value, then calls Multiply on m20 with a Vector broadcast from value.
// @fnv 0x00cebfd0
static __declspec(noinline) void FUN_00cebfd0(Owner* self, float afScale)
{
    self->m04 *= afScale;
    Vector tmp;
    tmp.q = _mm_load_ss(&afScale);
    self->m20.Multiply(&tmp);
}
Owner* volatile g_owner;
volatile float g_value;
Owner* volatile g_sink;

struct __declspec(align(16)) S00ceccf0_Vec
{
    __m128 q;
    void set(__m128 v)
    {
        q = v;
    }
    __m128 get() const
    {
        return q;
    }
    void operator=(const S00ceccf0_Vec& o)
    {
        q = o.q;
    }
};

struct __declspec(align(16)) S00ceccf0_Mat
{
    S00ceccf0_Vec c0;
    S00ceccf0_Vec c1;
    S00ceccf0_Vec c2;
    void Subtract(const S00ceccf0_Mat& o);
    S00ceccf0_Mat& operator=(const S00ceccf0_Mat& o)
    {
        c0 = o.c0;
        c1 = o.c1;
        c2 = o.c2;
        return *this;
    }
};

struct S00ceccf0_Out
{
    float m_00;
    float m_04;
    int unk08;
    int unk0c;
    S00ceccf0_Vec m_10;
    S00ceccf0_Mat m_20;
};

extern const double DAT_010cbf40;

static __declspec(noinline) void __cdecl FUN_00ceba60(float a, float b, S00ceccf0_Out* out)
{
    out->m_10.set(_mm_setzero_ps());
    out->m_00 = a * b;
    out->m_04 = a + b;
}

void(__cdecl* g_S00ceccf0_fp)(float, float, S00ceccf0_Out*) = &FUN_00ceba60;

static __declspec(noinline) void FUN_00cebfd0(S00ceccf0_Out* out, float value)
{
    out->m_00 *= value;
    out->m_04 *= value;
}

// Returns 1 for invalid span, start or t; otherwise combines two FUN_00ceba60 results (for start and start-t) into out, scales by span/(a-b), and returns 0.
// @f3 0x00972680 (community match, verified in this file)
struct __declspec(align(16)) FUN_00971350
{
    float m_00;
    float m_04;
    int unk08;
    int unk0c;
    S00ceccf0_Vec m_10;
    S00ceccf0_Mat m_20;
    FUN_00971350();
};

struct MatrixOps
{
    void __thiscall FUN_008e8a00(const S00ceccf0_Mat* source);
    void __thiscall FUN_0096cca0(const S00ceccf0_Mat* source);
};

// pdb: hkInertiaTensorComputer::computeSphereSurfaceMassProperties | hkInertiaTensorComputer.obj | tesv_win, caller_sim, low
int __cdecl FUN_00ceccf0(float start, float span, float t, S00ceccf0_Out* out)
{
    if (span <= 0.0f)
        return 1;
    if (start <= t)
        return 1;
    if (t <= 0.0f)
        return 1;

    float d = start - t;
    float a = (float)(DAT_010cbf40 * start * start * start);
    float b = (float)(DAT_010cbf40 * d * d * d);

    FUN_00971350 x;
    FUN_00971350 y;
    S00ceccf0_Out* px = (S00ceccf0_Out*)&x;
    S00ceccf0_Out* py = (S00ceccf0_Out*)&y;
    FUN_00ceba60(start, a, px);
    FUN_00ceba60(d, b, py);

    float* center = (float*)&out->m_10;
    center[0] = center[1] = center[2] = center[3] = 0.0f;
    ((MatrixOps*)&out->m_20)->FUN_008e8a00(&px->m_20);
    ((MatrixOps*)&out->m_20)->FUN_0096cca0(&py->m_20);
    out->m_04 = px->m_04 - py->m_04;
    out->m_00 = px->m_00 - py->m_00;
    FUN_00cebfd0(out, span / (a - b));
    return 0;
}


// Incident-edge walk: detach edges touching `unk`, recurse to the other end,
// then fold the node's inertia diagonal with the children's sum and max.
// Local array is an inplace hkArray (cap 16, dont-free flag 0x80000000).

struct Edge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int n14;
    int n18;
};

struct __declspec(align(16)) Mat3
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};

struct ShapeIface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void getInertia(Mat3* out);
};

struct Node
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    ShapeIface shape;
    int unkE4;
    char kind;
    bool isStatic() const
    {
        return kind == 5 || kind == 4;
    }
    ShapeIface* getMotion()
    {
        return &shape;
    }
    void FUN_00ca8920(Mat3* m);
};

struct LocalArr
{
    Edge** m_data;
    int m_iElementCount;
    int m_cap;
    Edge* storage[16];
};

void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize);

__forceinline void releaseArr(LocalArr* a)
{
    S_00cee1c0_Router* router = FUN_00c85750();
    S_00cee1c0_Heap* heap = router->heap;
    int cap = a->m_cap;
    a->m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
        heap->Free(a->m_data, (cap & 0x3fffffff) * 4);
}

__forceinline float fMinimumInputValue(float a, float b)
{
    return a > b ? a : b;
}
__forceinline float fTargetUpperBound(float a, float b)
{
    return a < b ? a : b;
}

// Recurses over arr's edges linked to the node, then for a non-static node limits its inertia diagonal entries and returns a clamped value; static nodes return 0.
// @f3 0x009764b0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
void __cdecl FUN_00901f10(void* p, int size);
struct HeapTls_cedec0
{
    void FUN_008f6d90(void* p, int size, int tag);
};
struct NodeView_cedec0
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
    ShapeIface shape;
    int unkD4;
    unsigned char kind;
    __forceinline bool isFixedOrKeyframed()const{return kind==7 || kind==6;}
    void FUN_0090c770(Mat3* m);
};

static __forceinline int getCapacity_cedec0(const LocalArr& a){return a.m_cap&0x3fffffff;}

float __cdecl FUN_00cedec0(S_00cee1c0_Arr* arr, int aiNode, float value)
{
    LocalArr local;
    local.m_data = &local.storage[0];
    local.m_iElementCount = 0;
    local.m_cap = static_cast<int>(0x80000010u);

    for (int i = arr->m_iElementCount - 1; i >= 0; --i)
    {
        unsigned int* data = arr->m_data;
        Edge* e = reinterpret_cast<Edge*>(data[i]);
        int other;
        if (e->n14 == aiNode)
            other = e->n18;
        else if (e->n18 != aiNode)
            continue;
        else
            other = e->n14;
        if (other == 0)
            continue;

        int n = --arr->m_iElementCount;
        data[i] = data[n];
        if (local.m_iElementCount == (local.m_cap & 0x3fffffff))
            FUN_00901f10(&local.m_data, 4);
        local.m_data[local.m_iElementCount++] = e;
    }

    float sum = 0.0f;
    float best = 0.0f;
    for (int i = local.m_iElementCount - 1; i >= 0; --i)
    {
        Edge* e = local.m_data[i];
        int other = (e->n14 == aiNode) ? e->n18 : e->n14;
        float r = FUN_00cedec0(arr, other, value);
        sum += r;
        if (best < r)
            best = r;
    }

    NodeView_cedec0* body = reinterpret_cast<NodeView_cedec0*>(aiNode);
    if (body->isFixedOrKeyframed()) {
    if ((static_cast<unsigned int>(local.m_cap)&0x80000000u)==0)
    {
        unsigned int cnt = local.m_cap & 0x3fffffff;
        HeapTls_cedec0* heap = static_cast<HeapTls_cedec0*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(local.m_data, cnt * 4, 0x17);
    }
    return 0.0f;
    }

    Mat3 m;
    ShapeIface* motion = &body->shape;
    motion->getInertia(&m);

    float fIyy = m.m11;
    float fIzz = m.m22;
    float fIxx = m.m00;
    float maxDiag = fMinimumInputValue(fIxx, fMinimumInputValue(fIyy, fIzz));

    if (sum == 0.0f)
    {
        int cap = local.m_cap;
        if ((static_cast<unsigned int>(cap)&0x80000000u)==0)
        {
            int cnt = getCapacity_cedec0(local);
            HeapTls_cedec0* heap = static_cast<HeapTls_cedec0*>(TlsGetValue(DAT_010f3170));
            heap->FUN_008f6d90(local.m_data, cnt * 4, 0x17);
        }
        return maxDiag;
    }

    float fClamped = fTargetUpperBound(sum, maxDiag * value);
    fClamped = fMinimumInputValue(fClamped, best);

    if (!(fClamped < fIxx))
        m.m00 = fClamped;
    if (!(fClamped < fIyy))
        m.m11 = fClamped;
    if (!(fClamped < fIzz))
        m.m22 = fClamped;

    body->FUN_0090c770(&m);

    float result = fMinimumInputValue(fTargetUpperBound(maxDiag * value, maxDiag + sum), fClamped);
    int cap = local.m_cap;
    if ((static_cast<unsigned int>(cap)&0x80000000u)==0)
    {
        int cnt = getCapacity_cedec0(local);
        HeapTls_cedec0* heap = static_cast<HeapTls_cedec0*>(TlsGetValue(DAT_010f3170));
        heap->FUN_008f6d90(local.m_data, cnt * 4, 0x17);
    }
    return result;
}


typedef union __declspec(intrin_type) __declspec(align(16)) __m128i
{
    int m128i_i32[4];
} __m128i;
__m128 _mm_castsi128_ps(__m128i);
extern "C" void _mm_store_ps(float*, __m128);

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};
inline __m128 scalarVector(float x)
{
    __m128 result = {x};
    return result;
}
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _ReadWriteBarrier();

struct S_00ced310_V
{
    float x, y, z, w;
};
struct S_00ced310_M
{
    S_00ced310_V c0, c1, c2;
};

static __forceinline float S_Max(float a, float b)
{
    return a > b ? a : b;
}

static __forceinline void S_SetZero(S_00ced310_M* m)
{
    __m128 z = _mm_setzero_ps();
    _ReadWriteBarrier();
    _mm_store_ps(&m->c0.x, z);
    _mm_store_ps(&m->c1.x, z);
    _mm_store_ps(&m->c2.x, z);
}

// Stores the maximum of the three diagonal components of m into all three diagonal slots, zeroing the rest.
// @f3 0x00972c90 (community match, verified in this file)
struct __declspec(align(16)) Zero553 {
    float x,y,z,w;
    __forceinline void Clear(){x=y=z=w=0.0f;}
    __forceinline void Store(volatile float* out)const{out[0]=x;out[1]=y;out[2]=z;out[3]=w;}
};
__forceinline void MaxInto553(float first,float second,volatile float& output){output=first>second?static_cast<double>(first):static_cast<double>(second);}
void __cdecl SetDiagonal(S_00ced310_M* matrix) {
    float selected;
    MaxInto553(matrix->c0.x,matrix->c1.y,selected);
    MaxInto553(selected,matrix->c2.z,selected);
    
    Zero553 zero;zero.Clear();
    volatile float* out=reinterpret_cast<volatile float*>(matrix);
    zero.Store(out);zero.Store(out+4);zero.Store(out+8);
    float finalValue=selected;
    matrix->c0.x=finalValue;matrix->c1.y=finalValue;matrix->c2.z=finalValue;
}


namespace fnv_00cefb90 {
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_load_ss(const float*);
}

// Same-file stand-ins as FUN_00cece50 (hkpMassProperties / hkVector4 / hkMatrix3).
struct __declspec(align(16)) CE50Vector
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct CE50Matrix
{
    CE50Vector row0, row1, row2;
    void FUN_00cd5140(const CE50Matrix* source);
};
struct CE50Body
{
    float volume;
    float mass;
    CE50Vector center;
    CE50Matrix inertia;
};

struct CEFBTri
{
    int a, b, c, material;
};
struct CEFBGeom
{
    CE50Vector* verts;
    int vertCount;
    unsigned vertCap;
    CEFBTri* tris;
    int triCount;
    unsigned triCap;
};

struct CEFBAreas
{
    float* data;
    int size;
    unsigned m_iCapacity;
};

void __cdecl FUN_00c908c0(S_00cee1c0_Heap* heap, CEFBAreas* arr, int count, int elemSize);
int __cdecl FUN_00cee290(const CE50Vector* v0, const CE50Vector* v1, const CE50Vector* v2, float triMass,
                         float thickness, CE50Body* out);
extern "C" void _ReadWriteBarrier(void);

void __cdecl FUN_00ced6b0(const CEFBGeom* geometry, float mass, CE50Body* out);

}  // namespace fnv_00cefb90

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
}

struct __declspec(align(16)) S_00ced090_V4
{
    float x, y, z, w;
};
struct S_00ced090_Mat
{
    S_00ced090_V4 r0, r1, r2;
    void FUN_00cd5880(void* xf);
};
struct S_00ced090_Vec
{
    S_00ced090_V4 v;
    void FUN_00c7f640(void* a, void* b);
};
void __cdecl AddInertiaTensor(S_00ced090_Vec* d, float m, S_00ced090_Mat* mat);

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern __declspec(thread) int DAT_012722b4;

struct S00cf0f40_Guard
{
    int m_saved;
    S00cf0f40_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cf0f40_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};

struct S00cf0f40_Stream
{
    int unk00;
    unsigned int m_pos;
    unsigned int(__cdecl* m_read)(S00cf0f40_Stream* self, void* dst, unsigned int size, unsigned int* comp,
                                  unsigned int n);
    unsigned int BinaryRead(void* p, unsigned int size, unsigned int* comp, unsigned int n)
    {
        unsigned int r = m_read(this, p, size, comp, n);
        m_pos += r;
        return r;
    }
};

inline unsigned int S00cf0f40_Load(S00cf0f40_Stream& s, unsigned int* p, unsigned int n)
{
    unsigned int uiSize = sizeof(unsigned int);
    return s.BinaryRead(p, n * sizeof(unsigned int), &uiSize, 1);
}

struct S00cf0f40_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned char unk1E6;
    unsigned char unk1E7;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    S00cf0f40_Stream* m_stream;
};

struct S00cf0f40_Vec
{
    unsigned int x, y, z, w;
};

struct S00cf0f40_Arr;
inline S_00cee1c0_Heap& S00cf0f40_heap(S_00cee1c0_Router* r)
{
    return *r->heap;
}
void __cdecl FUN_00c908c0(S_00cee1c0_Heap* heap, void* arr, int cap, int elemSize);

struct S00cf0f40_Arr
{
    S00cf0f40_Vec* m_data;
    int m_iElementCount;
    int m_capFlags;

    int getCapacity() const
    {
        return m_capFlags & 0x3fffffff;
    }
    void ClearAndRelease()
    {
        S_00cee1c0_Heap& heap = S00cf0f40_heap(FUN_00c85750());
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            heap.Free(m_data, getCapacity() * sizeof(S00cf0f40_Vec));
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    void reserve(int n)
    {
        S_00cee1c0_Heap& heap = S00cf0f40_heap(FUN_00c85750());
        int cap = getCapacity();
        if (cap < n)
        {
            int nc = cap * 2;
            FUN_00c908c0(&heap, this, n < nc ? nc : n, sizeof(S00cf0f40_Vec));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
inline void S00cf0f40_Swap4(void* p)
{
    unsigned int t;
    memcpy(&t, p, 4);
    t = _byteswap_ulong(t);
    memcpy(p, &t, 4);
}

// @f3 0x009799c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
struct Heap568 {void FUN_008f6d90(void*,unsigned int,int);};
extern Heap568* (__stdcall* DAT_00d9b080)(unsigned long);
void __cdecl FUN_00901e90(void*,int,int);
__forceinline void SetSize568(S00cf0f40_Arr* arr,int size){
    int capacity=arr->m_capFlags & 0x3fffffff;
    if(capacity<size) {
        int requested=size;
        if(requested<capacity*2)requested=capacity*2;
        FUN_00901e90(arr,requested,16);
    }
    arr->m_iElementCount=size;
}
// pdb: bhkStream::LoadBinary | bhkStream.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream, arArray
unsigned int __cdecl FUN_00cf0f40(S00cf0f40_Owner* owner,S00cf0f40_Arr* arr) {
    unsigned int count=0;
    S00cf0f40_Load(*owner->m_stream,&count,1);
    if((arr->m_capFlags & 0x80000000u)==0) {
        unsigned int capacity=arr->m_capFlags & 0x3fffffff;
        Heap568* heap=DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(arr->m_data,capacity*16,23);
    }
    arr->m_capFlags=(arr->m_capFlags & 0xc0000000)|0x80000000;
    arr->m_data=0;arr->m_iElementCount=0;
    SetSize568(arr,(int)count);
    unsigned int bytes=count*16;
    for(unsigned int i=0;i<count;++i) {
        S00cf0f40_Stream* stream=owner->m_stream;
        stream->BinaryRead(&arr->m_data[i],16,0,0);
        if(reinterpret_cast<const unsigned char*>(owner)[0x1e5]!=1) {
            S00cf0f40_Vec* item=&arr->m_data[i];
            S00cf0f40_Swap4(&item->x);S00cf0f40_Swap4(&item->y);
            S00cf0f40_Swap4(&item->z);S00cf0f40_Swap4(&item->w);
        }
    }
    return bytes;
}


extern "C" void _ReadWriteBarrier();

extern const double DAT_010cbf40;

struct Target
{
    float m_f00;
    float m_f04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_v10;
    union
    {
        __m128 m_v20;
        struct
        {
            float m_f20;
            float unk24;
            float unk28;
            float unk2C;
        };
    };
    union
    {
        __m128 m_v30;
        struct
        {
            float unk30;
            float m_f34;
            float unk38;
            float unk3C;
        };
    };
    union
    {
        __m128 m_v40;
        struct
        {
            float unk40;
            float unk44;
            float m_f48;
            float unk4C;
        };
    };
};

// Returns 1 if a or b is not positive; otherwise sets three diagonal entries to a*b*a*DAT_010290c0, m_f00 to a^3*DAT_010cbf40 and m_f04 to b, and returns 0.
// @f3 0x00971390 (community match, verified in this file)
extern const double DAT_00dc8048,DAT_00e7c920;
struct Layout469 {
    float mass,radius; unsigned int unk08,unk0c;
    float zero10,zero14,zero18,zero1c;
    volatile float m20,m24,m28,m2c,m30,m34,m38,m3c,m40,m44,m48,m4c;
};
struct __declspec(align(16)) Scalar469 {
    float x,y,z,value;
    Scalar469(float v):value(v){}
};
// pdb: hkpInertiaTensorComputer::shiftInertiaToCom | hkpInertiaTensorComputer.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkInertiaTensorComputer::computeSphereVolumeMassProperties)
// pdb params: shift, mass, inertia
int __cdecl FUN_00ceba60(float a,float b,Target* target) {
    if(b<=0.0f) return 1;
    if(a<=0.0f) return 1;
    Layout469* out=reinterpret_cast<Layout469*>(target);
    Scalar469 x(static_cast<float>(a*b*a*DAT_00dc8048));
    out->m20=0.0f;out->m24=0.0f;out->m28=0.0f;out->m2c=0.0f;
    out->m30=0.0f;out->m34=0.0f;out->m38=0.0f;out->m3c=0.0f;
    out->m40=0.0f;out->m44=0.0f;out->m48=0.0f;out->m4c=0.0f;
    out->m20=1.0f;out->m34=1.0f;out->m48=1.0f;
    out->m20=x.value;out->m34=x.value;out->m48=x.value;
    out->zero1c=0.0f;out->zero18=0.0f;out->zero14=0.0f;out->zero10=0.0f;
    out->mass=static_cast<float>(a*((a*DAT_00e7c920)*a));
    out->radius=b;
    return 0;
}


extern double DAT_01012638;

struct VertexComponentData
{
    int A;
    int B;
    int C;
    float P1;
    float Pa;
    float Pb;
    float m_fComponent0;
    float m_fComponent1;
    float m_fComponent2;
    float m_fComponent3;
    float m_fComponent4;
    float m_fComponent5;
    float m_fComponent6;

    void FUN_00cec000(const float* verts);
};

// Accumulates polynomial integrals over three segments of verts and stores the scaled results in P1, Pa, Pb and m_fComponent0 through m_fComponent6.
// @fnv 0x00cec000
// pdb: InternalInertiaTensorComputer::compProjectionIntegrals | hkInertiaTensorComputer.obj | tesv_win, uconst, low
void VertexComponentData::FUN_00cec000(const float* verts)
{
    float a0, a1, da;
    float b0, b1, db;
    float a0_2, a0_3, a0_4, b0_2, b0_3, b0_4;
    float a1_2, a1_3, b1_2, b1_3;
    float C1, Ca, Caa, Caaa, Cb, Cbb, Cbbb;
    float Cab, Kab, Caab, Kaab, Cabb, Kabb;
    int i;

    P1 = Pa = Pb = m_fComponent0 = m_fComponent1 = m_fComponent2 = m_fComponent3 = m_fComponent4 = m_fComponent5 =
        m_fComponent6 = 0.0f;

    for (i = 0; i < 3; i++)
    {
        a0 = verts[i * 4 + A];
        b0 = verts[i * 4 + B];
        a1 = verts[((i + 1) % 3) * 4 + A];
        b1 = verts[((i + 1) % 3) * 4 + B];
        da = a1 - a0;
        db = b1 - b0;
        a0_2 = a0 * a0;
        a0_3 = a0_2 * a0;
        a0_4 = a0_3 * a0;
        b0_2 = b0 * b0;
        b0_3 = b0_2 * b0;
        b0_4 = b0_3 * b0;
        a1_2 = a1 * a1;
        a1_3 = a1_2 * a1;
        b1_2 = b1 * b1;
        b1_3 = b1_2 * b1;

        C1 = a1 + a0;
        Ca = a1 * C1 + a0_2;
        Caa = a1 * Ca + a0_3;
        Caaa = a1 * Caa + a0_4;
        Cb = b1 * (b1 + b0) + b0_2;
        Cbb = b1 * Cb + b0_3;
        Cbbb = b1 * Cbb + b0_4;
        Cab = 3 * a1_2 + 2 * a1 * a0 + a0_2;
        Kab = a1_2 + 2 * a1 * a0 + 3 * a0_2;
        Caab = a0 * Cab + 4 * a1_3;
        Kaab = a1 * Kab + 4 * a0_3;
        Cabb = 4 * b1_3 + 3 * b1_2 * b0 + 2 * b1 * b0_2 + b0_3;
        Kabb = b1_3 + 2 * b1_2 * b0 + 3 * b1 * b0_2 + 4 * b0_3;

        P1 += db * C1;
        Pa += db * Ca;
        m_fComponent0 += db * Caa;
        m_fComponent3 += db * Caaa;
        Pb += da * Cb;
        m_fComponent2 += da * Cbb;
        m_fComponent6 += da * Cbbb;
        m_fComponent1 += db * (b1 * Cab + b0 * Kab);
        m_fComponent4 += db * (b1 * Caab + b0 * Kaab);
        m_fComponent5 += da * (a1 * Cabb + a0 * Kabb);
    }

    P1 /= 2.0f;
    Pa /= 6.0f;
    m_fComponent0 /= 12.0f;
    m_fComponent3 /= 20.0f;
    Pb /= -6.0f;
    m_fComponent2 /= -12.0f;
    m_fComponent6 /= -20.0f;
    m_fComponent1 /= 24.0f;
    m_fComponent4 /= DAT_01012638;
    m_fComponent5 /= -60.0f;
}

extern "C"
{
    void _mm_store_ps(float*, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_set_ss(float);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}
inline void* operator new(unsigned int, void* p)
{
    return p;
}
extern const float DAT_01016248;
struct Mat4CE;
struct __declspec(align(16)) Vec4CE
{
    float x, y, z, w;
    void FUN_00c7f640(const Mat4CE*, const Vec4CE*);
    __forceinline void Assign(const Vec4CE& source)
    {
        (__m128&)* this = (const __m128&)source;
    }
};
struct Mat4CE
{
    Vec4CE row0, row1, row2, translation;
    void FUN_00cb2240(const Mat4CE*, const Mat4CE*);
};
struct Inertia
{
    Vec4CE row0, row1, row2;
    void Multiply(const __m128*);
};
struct MassBody
{
    float volume, mass;
    Vec4CE center;
    Inertia inertia;
    MassBody() : volume(0.0f), mass(0.0f)
    {
        _mm_store_ps(&center.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row0.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row1.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row2.x, _mm_setzero_ps());
    }
};
typedef S_00cee1c0_Heap Heap;
typedef S_00cee1c0_Router Router;
struct Handle
{
    Vec4CE* data;
    int count, capacity;
    __forceinline void release(Heap* heap)
    {
        count = 0;
        if ((capacity & 0x80000000) == 0)
            heap->Free(data, (capacity & 0x3fffffff) * 16);
    }
};
struct __declspec(align(16)) Query
{
    unsigned int shapeBuffer[128];
};
struct ShapeVector
{
    float x, y, z, w;
};
struct TranslatedMatrix : Mat4CE
{
    __forceinline TranslatedMatrix(const ShapeVector& offset)
    {
        _mm_store_ps(&row0.x, _mm_setzero_ps());
        row0.x = 1.0f;
        _mm_store_ps(&row1.x, _mm_setzero_ps());
        row1.y = 1.0f;
        _mm_store_ps(&row2.x, _mm_setzero_ps());
        row2.z = 1.0f;
        _mm_store_ps(&translation.x, (const __m128&)offset);
    }
};
struct HkShape
{
    virtual void v00();
    virtual void v04();
    virtual int First();
    virtual int Next(int);
    virtual HkShape* Container();
    virtual HkShape* Find(int, Query*);
    int m04, m08, tag;
    union
    {
        float radius;
        int count;
    };
    HkShape* child14;
    HkShape* child18;
    int m1c;
    ShapeVector v20, v30, v40;
    __forceinline int GetType() const
    {
        return tag;
    }
    float FUN_00d571a0();
    void FUN_00d59200(Handle*);
};
void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl FUN_00cebaf0(Vec4CE*, float, MassBody*);
void __cdecl FUN_00cee290(Vec4CE*, Vec4CE*, Vec4CE*, float, float, MassBody*);
struct RawBody
{
    float volume, mass;
    Vec4CE center;
    Inertia inertia;
};
struct Element
{
    RawBody body;
    Mat4CE transform;
    __forceinline void Initialize()
    {
        body.volume = 0.0f;
        _mm_store_ps(&body.center.x, _mm_setzero_ps());
        body.mass = 0.0f;
        _mm_store_ps(&body.inertia.row0.x, _mm_setzero_ps());
        _mm_store_ps(&body.inertia.row1.x, _mm_setzero_ps());
        _mm_store_ps(&body.inertia.row2.x, _mm_setzero_ps());
        _mm_store_ps(&transform.row0.x, _mm_setzero_ps());
        _mm_store_ps(&transform.row1.x, _mm_setzero_ps());
        _mm_store_ps(&transform.row2.x, _mm_setzero_ps());
        transform.row0.x = 1.0f;
        transform.row1.y = 1.0f;
        transform.row2.z = 1.0f;
        _mm_store_ps(&transform.translation.x, _mm_setzero_ps());
    }
    void FUN_00cf0820(const MassBody*);
};
struct Array
{
    Element* data;
    int count, capacity;
    Element local[2];
    __forceinline void release(Heap* heap)
    {
        count = 0;
        if ((capacity & 0x80000000) == 0)
            heap->Free(data, (capacity & 0x3fffffff) * 0x90);
    }
};

extern "C"
{
    __m128 _mm_set_ps1(float);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
}

extern const float DAT_01016248;

struct V4
{
    __m128 q;
    void setZero4()
    {
        q = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return q.m128_f32[i];
    }
};
struct BoxInertia : Mat3
{
    float& operator()(int r, int c)
    {
        return (&m00)[c * 4 + r];
    }
    void setZero()
    {
        V4 z;
        z.setZero4();
        _mm_store_ps(&m00, z.q);
        _mm_store_ps(&m10, z.q);
        _mm_store_ps(&m20, z.q);
    }
    void setIdentity()
    {
        setZero();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};
struct MassProperties
{
    float m_iBufferSize;
    float m_fViscosityFriction;
    float unk08;
    float unk0C;
    V4 m_kCenterOfMass1;
    BoxInertia m_kInertiaTensor;
};

// Fills result with the inertia tensor, zero center of mass, volume and mass for a box of given halfExtents and mass, returning 1 if mass is not positive.
// @f3 0x00971440 (community match, verified in this file)
extern double FUN_00dd2798;

// pdb: InternalInertiaTensorComputer::computeInertialTensorInternal | hkpInertiaTensorComputer.obj | fnv360_0822_retail, objrun_sim, low, conflict (skyrim: hkInertiaTensorComputer::computeBoxVolumeMassProperties)
// pdb params: mass, density, r, J
int __cdecl FUN_00cebaf0(const V4& halfExtents, float mass, MassProperties& result)
{
    if (mass <= 0.0f)
        return 1;

    V4 pad;
    pad.setZero4();
    float x = halfExtents(0);
    float y = halfExtents(1);
    float z = halfExtents(2);
    float k = mass * (1.0f / 3.0f);
    volatile float* pm = &result.m_kInertiaTensor.m00;
    pm[0] = 0.0f;
    pm[1] = 0.0f;
    pm[2] = 0.0f;
    pm[3] = 0.0f;
    pm[4] = 0.0f;
    pm[5] = 0.0f;
    pm[6] = 0.0f;
    pm[7] = 0.0f;
    pm[8] = 0.0f;
    pm[9] = 0.0f;
    pm[10] = 0.0f;
    pm[11] = 0.0f;

    pm[0] = 1.0f;
    pm[5] = 1.0f;
    pm[10] = 1.0f;

    result.m_kInertiaTensor(0, 0) = (y * y + z * z) * k;
    result.m_kInertiaTensor(1, 1) = (x * x + z * z) * k;
    result.m_kInertiaTensor(2, 2) = (x * x + y * y) * k;

    result.m_kCenterOfMass1(3) = 0.0f;
    result.m_kCenterOfMass1(2) = 0.0f;
    result.m_kCenterOfMass1(1) = 0.0f;
    result.m_kCenterOfMass1(0) = 0.0f;
    result.m_iBufferSize = (float)(x * y * z * FUN_00dd2798);
    result.m_fViscosityFriction = mass;
    return 0;
}


__declspec(align(16)) struct Vec4Q
{
    float x;
    float y;
    float z;
    float w;
};

struct SourceBlock
{
    int unk00;
    float f04;
    int unk08;
    int unk0c;
    __m128 a10;
    __m128 b20;
    __m128 c30;
    __m128 d40;
};

struct DestBlock
{
    __m128 m00;
    __m128 m10;
    __m128 m20;
    __m128 m30;
    float f40;
    void Multiply(Vec4Q* v);
};

// Copies four __m128 blocks from source into destination at offset 0x50, stores value in f40, and calls Multiply with value divided by src->f04.
// @fnv 0x00cebdf0
void __cdecl FUN_00cebdf0(float* source, float value, Object* destination)
{
    SourceBlock* src = (SourceBlock*)source;
    DestBlock* dst = (DestBlock*)((char*)destination + 0x50);
    float q = value / src->f04;
    float* qp = &q;
    dst->f40 = value;
    dst->m30 = src->a10;
    dst->m00 = src->b20;
    dst->m10 = src->c30;
    dst->m20 = src->d40;
    Vec4Q tmp;
    _mm_store_ps((float*)&tmp, _mm_load_ss(qp));
    dst->Multiply(&tmp);
}

extern "C"
{
    __m128 _mm_set_ss(float);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct EigenVector
{
    __m128 q;
    __forceinline float& operator()(int i)
    {
        return ((float*)&q)[i];
    }
    __forceinline void normalize3()
    {
        __m128 m = _mm_mul_ps(q, q);
        __m128 lenSq = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
        __m128 r = _mm_rsqrt_ss(lenSq);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 c3 = _mm_set_ss(3.0f);
        __m128 c05 = _mm_set_ss(0.5f);
        __m128 invLen = _mm_mul_ss(_mm_mul_ss(c05, r), _mm_sub_ss(c3, _mm_mul_ss(_mm_mul_ss(lenSq, r), r)));
        invLen = _mm_andnot_ps(_mm_cmpeq_ss(lenSq, zero), invLen);
        q = _mm_mul_ps(_mm_shuffle_ps(invLen, invLen, 0), q);
    }
    __forceinline void setCross(const EigenVector& a, const EigenVector& b)
    {
        __m128 aq = a.q;
        __m128 bq = b.q;
        q = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xd2), _mm_shuffle_ps(bq, bq, 0xc9)),
                       _mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xc9), _mm_shuffle_ps(bq, bq, 0xd2)));
    }
    __forceinline void setCrossS(const EigenVector& a, const EigenVector& b)
    {
        __m128 aq = a.q;
        __m128 bq = b.q;
        q = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xc9), _mm_shuffle_ps(bq, bq, 0xd2)),
                       _mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xd2), _mm_shuffle_ps(bq, bq, 0xc9)));
    }
};

struct Basis
{
    EigenVector c0, c1, c2;
    __forceinline EigenVector& getColumn(int i)
    {
        return (&c0)[i];
    }
    __forceinline void setIdentityZ(__m128 z)
    {
        getColumn(0).q = z;
        getColumn(1).q = z;
        getColumn(2).q = z;
        getColumn(0)(0) = 1.0f;
        getColumn(1)(1) = 1.0f;
        getColumn(2)(2) = 1.0f;
    }
    __forceinline void setIdentityZ2(__m128 z)
    {
        c0.q = z;
        c1.q = z;
        c2.q = z;
        c0(0) = 1.0f;
        c1(1) = 1.0f;
        c2(2) = 1.0f;
    }
    __forceinline float& at(int r, int c)
    {
        return ((float*)this)[r * 4 + c];
    }
    __forceinline void setIdentityZ3(__m128 z)
    {
        c0.q = z;
        c1.q = z;
        c2.q = z;
        at(0, 0) = 1.0f;
        at(1, 1) = 1.0f;
        at(2, 2) = 1.0f;
    }
    __forceinline void Orthonormalize()
    {
        getColumn(0).normalize3();
        getColumn(1).setCrossS(getColumn(2), getColumn(0));
        getColumn(1).normalize3();
        getColumn(2).setCross(getColumn(1), getColumn(0));
        getColumn(2).normalize3();
    }
    __forceinline void renormalize2()
    {
        c0.normalize3();
        c1.setCross(c2, c0);
        c1.normalize3();
        c2.setCross(c0, c1);
        c2.normalize3();
    }
};

void FUN_00c908c0(S_00cee1c0_Heap* a, void* arr, int n, int sz);
struct __declspec(align(16)) Vec
{
    float x, y, z, w;
};

struct Geometry
{
    Vec4* vertices;
    int vertexCount;
    int vertexCapacity;
    int* triangles;
    int triangleCount;
};
struct MassPropertiesSV
{
    float volume;
    float mass;
    Vector center;
    Matrix inertia;
};
struct Integrator
{
    Vec4 basisX, basisY, basisZ, translation, boundsMin, boundsMax;
    float m_60, m_64, m_68, m_6C, m_70, m_74, m_78, m_7C, m_80, m_84, m_88;
    void FUN_00ced390(Geometry*, Vec4*);
    void FUN_00cec6b0(float, float, float*, float*);
};
static inline float maximum(float a, float b)
{
    return a < b ? b : a;
}
// Computes volume, mass, center of mass, and inertia tensor for a Geometry, falling back to an axis-aligned box when the integrated volume is non-positive.
// @f3 0x00973140 (community match, verified in this file)
static __forceinline float NativeMaximum(float a, float b)
{
    return b > a ? b : a;
}

namespace f3m_00973140 {
struct NativeIntegrator: Integrator { void FUN_00972d20(Geometry*,Vec4*); void FUN_00971e80(float,float,float*,float*); };

namespace NativeScalarMass { void __cdecl FUN_00971fc0(Vec4*,int,Vec4*,Vec4*); int __cdecl FUN_00971440(Vec4*,float,MassPropertiesSV*); }

struct NativeMassProperties { float volume,mass; Vector center; Matrix inertia; void FUN_00976ae0(const MassPropertiesSV&); };

}
void __cdecl FUN_00ced6b0(Geometry* geometry, float mass, MassPropertiesSV* result)
{
    if (mass <= 0.0f)
        mass = 1.0f;
    Vec4 center;
    Vec4 dimensions;
    MassPropertiesSV boxProperties;
    {
        f3m_00973140::NativeScalarMass::FUN_00971fc0(geometry->vertices, geometry->vertexCount, &center, &dimensions);
        boxProperties.volume = 0.0f;
        boxProperties.mass = 0.0f;
        boxProperties.center.w=0.0f; boxProperties.center.z=0.0f; boxProperties.center.y=0.0f; boxProperties.center.x=0.0f;
        boxProperties.inertia.c0.x=0.0f; boxProperties.inertia.c0.y=0.0f; boxProperties.inertia.c0.z=0.0f; boxProperties.inertia.c0.w=0.0f;
        boxProperties.inertia.c1.x=0.0f; boxProperties.inertia.c1.y=0.0f; boxProperties.inertia.c1.z=0.0f; boxProperties.inertia.c1.w=0.0f;
        boxProperties.inertia.c2.x=0.0f; boxProperties.inertia.c2.y=0.0f; boxProperties.inertia.c2.z=0.0f; boxProperties.inertia.c2.w=0.0f;
        f3m_00973140::NativeScalarMass::FUN_00971440(&dimensions, mass, &boxProperties);
    }
    boxProperties.center.x=center.x; boxProperties.center.y=center.y; boxProperties.center.z=center.z; boxProperties.center.w=center.w;
    f3m_00973140::NativeIntegrator integrator;
    {
        dimensions.x=-center.x; dimensions.y=-center.y; dimensions.z=-center.z; dimensions.w=-center.w;
        integrator.FUN_00972d20(geometry, &dimensions);
    }
    if (integrator.m_64 <= 0.0f)
    {
        reinterpret_cast<f3m_00973140::NativeMassProperties*>(result)->FUN_00976ae0(boxProperties);
        return;
    }
    Vector& outputCenter = result->center;

    result->volume = integrator.m_64;
    result->mass = mass;
    float density = mass / integrator.m_64;
    integrator.FUN_00971e80(mass, density, (float*)&outputCenter, (float*)&result->inertia.c0);
    const float* centerValues = reinterpret_cast<const float*>(&center);
    outputCenter(0) = centerValues[0] + outputCenter(0);
    outputCenter(1) = *static_cast<const volatile float*>(&centerValues[1]) + outputCenter(1);
    outputCenter(2) = centerValues[2] + outputCenter(2);
    outputCenter(3) = centerValues[3] + outputCenter(3);
    float* bf = (float*)&center;
    float* u = (float*)&boxProperties.inertia.c0;
    float* M = (float*)&result->inertia.c0;
    double scale = 0.10000000149011612;
    for (int i = 0; i < 3; ++i)
    {
        double t = u[i * 5] * scale;
        if (t > M[i * 5])
        {
            M[i * 5] = t;
            ((float*)&result->center)[i] = bf[i];
            for (int j = 0; j < 3; ++j)
            {
                if (j != i)
                {
                    float temp = NativeMaximum(M[i * 4 + j], 0.0f);
                    float v = temp;
                    M[j * 4 + i] = v;
                    M[i * 4 + j] = v;
                }
            }
        }
    }
}

