// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct State
{
    int first;
    int count;
    int context;
};
static inline float S_MaxGT(float x, float y)
{
    return (x > y) ? x : y;
}
static inline float S_MaxLT(float x, float y)
{
    return (x < y) ? y : x;
}
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
extern "C" void _mm_store_ps(float*, __m128);
struct __declspec(align(16)) CE50Vector
{
    float x, y, z, w;
};
struct CE50Matrix
{
    CE50Vector row0, row1, row2;
    void FUN_00c6cd00(const CE50Matrix* source);
    void Subtract(const CE50Matrix* source);
};
struct CE50Body
{
    float volume, mass;
    CE50Vector center;
    CE50Matrix inertia;
    CE50Body() : volume(0.0f), mass(0.0f)
    {
        _mm_store_ps(&center.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row0.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row1.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row2.x, _mm_setzero_ps());
    }
};
static __declspec(noinline) void FUN_00cebfd0(CE50Body* body, float scale)
{
    body->mass *= scale;
    body->inertia.row0.x *= scale;
    body->inertia.row0.y *= scale;
    body->inertia.row0.z *= scale;
    body->inertia.row1.x *= scale;
    body->inertia.row1.y *= scale;
    body->inertia.row1.z *= scale;
    body->inertia.row2.x *= scale;
    body->inertia.row2.y *= scale;
    body->inertia.row2.z *= scale;
}
extern "C"
{
    void _mm_store_ps(float*, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}
__declspec(align(16)) struct Vec4F
{
    float x;
    float y;
    float z;
    float w;
};
__declspec(align(16)) struct Pair
{
    float x;
    float y;
};
// Plain float fields (no __m128 members, no arrays): keeps /GS from adding a cookie.
__declspec(align(16)) struct Mat4
{
    float unk00_0;
    float unk00_1;
    float unk00_2;
    float unk00_3;
    float row0_0;
    float row0_1;
    float row0_2;
    float row0_3;
    float row1_0;
    float row1_1;
    float row1_2;
    float row1_3;
    float row2_0;
    float row2_1;
    float row2_2;
    float row2_3;
};
__declspec(align(16)) struct Solver
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    void __thiscall FUN_00ced390(State* self, float* a);
    void __thiscall FUN_00cec6b0(float value, float ratio, float* vec, float* mat);
};
__declspec(align(16)) struct Work
{
    Pair pair;
    Mat4 mat;
    Solver solver;
};
inline float MaxVal(float a, float b)
{
    return a > b ? a : b;
}
extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_set_ps1(float _A);
struct __declspec(align(16)) S00cf0690_Vec
{
    float x, y, z, w;
};
struct S00cf0690_Mass
{
    float volume;
    float mass;
    S00cf0690_Vec center;
    S00cf0690_Vec row0, row1, row2;
};
static __declspec(noinline) void FUN_00cebfd0(S00cf0690_Mass* p, float density)
{
    float newMass = density * p->volume;
    float k = newMass / p->mass;
    p->mass = newMass;
    __m128 f = _mm_set_ps1(k);
    *(__m128*)&p->row0 = _mm_mul_ps(*(__m128*)&p->row0, f);
    *(__m128*)&p->row1 = _mm_mul_ps(*(__m128*)&p->row1, f);
    *(__m128*)&p->row2 = _mm_mul_ps(*(__m128*)&p->row2, f);
}

#include <math.h>
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_load_ss(const float*);
}
struct __declspec(align(16)) IntegralVector159
{
    float x, y, z, w;
    IntegralVector159()
    {}
    __forceinline void SetProduct(const float& scalar, __m128 v)
    {
        quad() = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&scalar), _mm_load_ss(&scalar), 0), v);
    }
    __forceinline __m128& quad()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    __forceinline const __m128& quad() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
    float operator[](int i) const
    {
        return (&x)[i];
    }
};
struct Triangle159
{
    int a, b, c, material;
};
struct Mesh159
{
    IntegralVector159* vertices;
    int unk04, unk08;
    Triangle159* triangles;
    int count;
};
struct Integrals159
{
    int axisA, axisB, axisC;
    float P1, Pa, Pb, m_fComponent0, m_fComponent1, m_fComponent2, m_fComponent3, m_fComponent4, m_fComponent5,
        m_fComponent6;
    float face[12];
    float volume;
    float first[3];
    float second[3];
    float products[3];
    void FUN_00cec000(const IntegralVector159* triangle);
    void FUN_00cec3d0(const IntegralVector159* triangle, const IntegralVector159* normal);
    void FUN_00ced390(Mesh159* mesh, const IntegralVector159* offset);
};
__declspec(noinline) void Integrals159::FUN_00cec000(const IntegralVector159* triangle)
{
    P1 = Pa = Pb = m_fComponent0 = m_fComponent1 = m_fComponent2 = m_fComponent3 = m_fComponent4 = m_fComponent5 =
        m_fComponent6 = 0.0f;
    for (int i = 0; i < 3; ++i)
    {
        const IntegralVector159& p = triangle[i];
        const IntegralVector159& q = triangle[(i + 1) % 3];
        float a0 = p[axisA], b0 = p[axisB], a1 = q[axisA], b1 = q[axisB];
        float da = a1 - a0, db = b1 - b0;
        float a02 = a0 * a0, a03 = a02 * a0, a04 = a03 * a0;
        float b02 = b0 * b0, b03 = b02 * b0, b04 = b03 * b0;
        float a12 = a1 * a1, a13 = a12 * a1;
        float b12 = b1 * b1, b13 = b12 * b1;
        float c1 = a1 + a0;
        float ca = a1 * c1 + a02, caa = a1 * ca + a03, caaa = a1 * caa + a04;
        float cb = b1 * (b1 + b0) + b02, cbb = b1 * cb + b03, cbbb = b1 * cbb + b04;
        float cab = 3 * a12 + 2 * a1 * a0 + a02;
        float kab = a12 + 2 * a1 * a0 + 3 * a02;
        float caab = a0 * cab + 4 * a13, kaab = a1 * kab + 4 * a03;
        float cabb = 4 * b13 + 3 * b12 * b0 + 2 * b1 * b02 + b03;
        float kabb = b13 + 2 * b12 * b0 + 3 * b1 * b02 + 4 * b03;
        P1 += db * c1;
        Pa += db * ca;
        m_fComponent0 += db * caa;
        m_fComponent3 += db * caaa;
        Pb += da * cb;
        m_fComponent2 += da * cbb;
        m_fComponent6 += da * cbbb;
        m_fComponent1 += db * (b1 * cab + b0 * kab);
        m_fComponent4 += db * (b1 * caab + b0 * kaab);
        m_fComponent5 += da * (a1 * cabb + a0 * kabb);
    }
    P1 /= 2.0f;
    Pa /= 6.0f;
    m_fComponent0 /= 12.0f;
    m_fComponent3 /= 20.0f;
    Pb /= -6.0f;
    m_fComponent2 /= -12.0f;
    m_fComponent6 /= -20.0f;
    m_fComponent1 /= 24.0f;
    m_fComponent4 /= 60.0f;
    m_fComponent5 /= -60.0f;
}
__declspec(noinline) void Integrals159::FUN_00cec3d0(const IntegralVector159* triangle, const IntegralVector159* normal)
{
    FUN_00cec000(triangle);
    float w = -normal->x * triangle[0].x - normal->y * triangle[0].y - normal->z * triangle[0].z;
    float na = (*normal)[axisA], nb = (*normal)[axisB];
    float k1 = 1.0f / (*normal)[axisC], k2 = k1 * k1, k3 = k2 * k1, k4 = k3 * k1;
    face[0] = k1 * Pa;
    face[1] = k1 * Pb;
    face[2] = -k2 * (na * Pa + nb * Pb + w * P1);
    face[3] = k1 * m_fComponent0;
    face[4] = k1 * m_fComponent2;
    face[5] = k3 * (na * na * m_fComponent0 + 2 * na * nb * m_fComponent1 + nb * nb * m_fComponent2 +
                    w * (2 * (na * Pa + nb * Pb) + w * P1));
    face[6] = k1 * m_fComponent3;
    face[7] = k1 * m_fComponent6;
    face[8] = -k4 * (na * na * na * m_fComponent3 + 3 * na * na * nb * m_fComponent4 +
                     3 * na * nb * nb * m_fComponent5 + nb * nb * nb * m_fComponent6 +
                     3 * w * (na * na * m_fComponent0 + 2 * na * nb * m_fComponent1 + nb * nb * m_fComponent2) +
                     w * w * (3 * (na * Pa + nb * Pb) + w * P1));
    face[9] = k1 * m_fComponent4;
    face[10] = -k2 * (na * m_fComponent5 + nb * m_fComponent6 + w * m_fComponent2);
    face[11] = k3 * (na * na * m_fComponent3 + 2 * na * nb * m_fComponent4 + nb * nb * m_fComponent5 +
                     w * (2 * (na * m_fComponent0 + nb * m_fComponent1) + w * Pa));
}
// @f3 0x00972d20 (community match, verified in this file)
static __forceinline void ScaleNormal159(IntegralVector159& v, const float& s)
{
    v.x = static_cast<volatile float&>(v.x) * s;
    v.y = static_cast<volatile float&>(v.y) * s;
    v.z = static_cast<volatile float&>(v.z) * s;
    v.w = (float)(s * 0.0);
}
// pdb: InternalInertiaTensorComputer::compVolumeIntegrals | hkInertiaTensorComputer.obj | tesv_win, caller_sim, low
void Integrals159::FUN_00ced390(Mesh159* mesh, const IntegralVector159* offset)
{
    int triangleCount = mesh->count;
    volume = first[0] = first[1] = first[2] = second[0] = second[1] = second[2] = products[0] = products[1] =
        products[2] = 0.0f;
    if (triangleCount > 0)
    {
        int byteOff = 0;
        int remaining = triangleCount;
        do
        {
            struct PackedTriangleIndices { int a, b, c; };
            const PackedTriangleIndices tri = *reinterpret_cast<const PackedTriangleIndices*>(
                reinterpret_cast<const char*>(mesh->triangles) + byteOff);
            IntegralVector159 points[3];
            const IntegralVector159* va = &mesh->vertices[tri.a];
            const IntegralVector159* vb = &mesh->vertices[tri.b];
            const IntegralVector159* vc = &mesh->vertices[tri.c];
            points[0].x = offset->x + va->x;
            points[0].y = va->y + offset->y;
            points[0].z = va->z + offset->z;
            points[0].w = va->w + offset->w;
            points[1].x = vb->x + offset->x;
            points[1].y = vb->y + offset->y;
            points[1].z = vb->z + offset->z;
            points[1].w = vb->w + offset->w;
            points[2].x = vc->x + offset->x;
            points[2].y = vc->y + offset->y;
            points[2].z = vc->z + offset->z;
            points[2].w = vc->w + offset->w;
            IntegralVector159 e0, e1, normal;
            e0.x = points[1].x - points[0].x;
            e0.y = points[1].y - points[0].y;
            e0.z = points[1].z - points[0].z;
            e1.x = points[2].x - points[0].x;
            e1.y = points[2].y - points[0].y;
            e1.z = points[2].z - points[0].z;
            normal.x = e0.y * e1.z - e0.z * e1.y;
            normal.y = e0.z * e1.x - e0.x * e1.z;
            normal.z = e0.x * e1.y - e0.y * e1.x;
            normal.w = 0.0f;
            float length = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
            if (length > 0.0f)
            {
                float inverse = 1.0f / length;
                ScaleNormal159(normal, inverse);
                float nx = fabsf(normal.x), ny = fabsf(normal.y), nz = fabsf(normal.z);
                if (nx > ny && nx > nz)
                    axisC = 0;
                else
                    axisC = (ny > nz) ? 1 : 2;
                axisA = (axisC + 1) % 3;
                axisB = (axisA + 1) % 3;
                FUN_00cec3d0(points, &normal);
                int a = axisA;
                float projected = (a == 0) ? face[0] : ((axisB == 0) ? face[1] : face[2]);
                volume += static_cast<volatile float&>(normal.x) * projected;
                first[a] += normal[a] * face[3];
                first[axisB] += normal[axisB] * face[4];
                first[axisC] += normal[axisC] * face[5];
                second[axisA] += normal[axisA] * face[6];
                second[axisB] += normal[axisB] * face[7];
                second[axisC] += normal[axisC] * face[8];
                products[axisA] += normal[axisA] * face[9];
                products[axisB] += normal[axisB] * face[10];
                products[axisC] += normal[axisC] * face[11];
            }
            byteOff += sizeof(PackedTriangleIndices);
        } while (--remaining);
    }
    for (int i = 0; i < 3; ++i)
        first[i] = (float)(first[i] * 0.5);
    for (int i = 0; i < 3; ++i)
        second[i] = (float)(second[i] / 3.0);
    for (int i = 0; i < 3; ++i)
        products[i] = (float)(products[i] * 0.5);
}

