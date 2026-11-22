#include "f3_common.h"
// src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// The .rdata double added to the first matrix element (0.25) lives in the
// original image, so it is only declared here.
extern const double DAT_010c9300;
// arg1: the six float vector
// arg2: the scale struct, the two floats at +4 and +8 are read
// arg3: the destination struct, the product is stored at +0x1c
// the 0x40 byte matrix block the cursor walks over
// arg4: the cursor pointing at the next matrix block
extern double _DAT_010c9300;
extern double _DAT_010c9300;

#include <xmmintrin.h>
struct S00d6e280_Obj
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char m_flag2;
    unsigned char m_flag3;
    float m_f4;
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
    int m_64;
};

struct S00d6e280_Other
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
    int m_64;
};

struct S00d6e280_Arg
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
    __m128 m_30;
};

struct __declspec(align(16)) S00d6e280_Call
{
    unsigned int va[4];
    unsigned int vb[4];
    float c;
    int d;
};

struct S00d6e280_Rec
{
    union
    {
        float f00;
        unsigned char type00;
    };
    unsigned char b04;
    unsigned char b05;
    unsigned short s06;
    int i08;
    int i0c;
};

// @f3 0x009fb410 (community match, verified in this file)
extern "C" void FUN_00a4e900(S00d6e280_Call* p, S00d6e280_Other* o, S00d6e280_Rec** cursor);
extern const double FUN_00e20408;
// pdb: buildJacobianFromLinFrictionAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_00d6e280(S00d6e280_Rec** cursor, __m128* table, S00d6e280_Obj* self,
                                              S00d6e280_Other* other, const S00d6e280_Arg* a1)
{
    if (self->m_flag2 != 0)
    {
        if (self->m_f4 > 0.0f)
        {
            S00d6e280_Call c;
            const float* src = (const float*)&a1->m_30;
            float* dst = (float*)&c.va;
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
            const float* vbp = (const float*)&table[self->m_flag3];
            float* vbd = (float*)&c.vb;
            vbd[0] = vbp[0];
            vbd[1] = vbp[1];
            vbd[2] = vbp[2];
            vbd[3] = vbp[3];
            c.c = self->m_f4;
            c.d = other->unk4c;
            FUN_00a4e900(&c, other, cursor);
            return;
        }
    }
    S00d6e280_Rec* rec = *cursor;
    double v = rec->f00;
    rec->b04 = 1;
    rec = rec + 1;
    (rec - 1)->f00 = (float)(v + FUN_00e20408);
    (rec - 1)->type00 = 3;
    *cursor = rec;
}

volatile int g_in2; volatile int g_out2;
S00d6e280_Rec** g_c; __m128* g_t; S00d6e280_Obj* g_s; S00d6e280_Other* g_o; const S00d6e280_Arg* g_a;
void caller_of_FUN_00d6e280()
{
    FUN_00d6e280(g_c, g_t, g_s, g_o, g_a); g_out2 = g_in2;
}


void __fastcall S00d6e280_Wrap(S00d6e280_Obj* self, S00d6e280_Other* other, S00d6e280_Arg* a1)
{
    S00d6e280_Rec* cur = 0;
    __m128* tab = 0;
    FUN_00d6e280(&cur, tab, self, other, a1);
}

struct FourFloatVector
{
    float x, y, z, w;
};
struct FnvSubObject
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
    union
    {
        __m128 vec;
        FourFloatVector components;
    };
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
    void FUN_00d71f90(FnvSubObject* src);
};
struct FnvPacket
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
    FnvSubObject* unk30;
    FnvSubObject* unk34;
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
};

// @fnv 0x00d6ecb0
FnvPacket* volatile sourcePacket;
void* volatile sourceDest;

extern "C" float __cdecl Atan2(float a, float b);
extern const unsigned char DAT_010d33c1[];
extern const unsigned char DAT_010d33c2[];

struct Child
{
    float unk00;
    float f04;
};
struct Src
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    float f40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    Child* child;
};
struct Mat
{
    __m128 rows[4];
};
struct Out
{
    __m128 row;
    float f10, f14, f18, f1c;
};
struct Obj
{
    unsigned char unk00, unk01, flag, axis;
    float f04, f08, f0c;
};

static __m128 cross_uv(__m128 u, __m128 v)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xD2), _mm_shuffle_ps(u, u, 0xC9)),
                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xC9), _mm_shuffle_ps(u, u, 0xD2)));
}

static float sum3(__m128 v)
{
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    s = _mm_add_ss(_mm_shuffle_ps(v, v, 0xAA), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}

// @fnv 0x00d6d2e0
static __declspec(noinline) int FUN_00d6d2e0(Obj* self, Src* src, Mat* a2, Mat* a3, Out* out)
{
    if (self->flag != 0)
    {
        unsigned axis = self->axis;
        unsigned offW = DAT_010d33c1[axis];
        unsigned offU = DAT_010d33c2[axis];
        out->f1c = src->f40 * self->f0c;
        out->row = a2->rows[axis];
        __m128 W = *(__m128*)((unsigned char*)a2 + offW);
        __m128 U = *(__m128*)((unsigned char*)a3 + offU);
        __m128 V = a3->rows[axis];
        out->f10 = self->f04;
        out->f14 = self->f08;
        float dot = sum3(_mm_mul_ps(U, W));
        float triple = sum3(_mm_mul_ps(cross_uv(U, V), W));
        out->f18 = Atan2(dot, triple);
        float n = src->child->f04 * -1.0;
        const double kPi = 3.14159265358979323846f;
        const double kTwo = 6.28318530717958647692f;
        while (n - out->f18 > kPi)
            out->f18 = (float)(out->f18 + kTwo);
        while (out->f18 - n > kPi)
            out->f18 = (float)(out->f18 - kTwo);
        return 0;
    }
    return 1;
}

int g_sink;

struct S00d6f300_A
{
    short m_00;
    unsigned char m_02;
    unsigned char m_03;
    short m_04;
    short m_06;
    float m_08;
    void* m_0c;
};
struct S00d6f300_O
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
    __m128 m_30;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    unsigned char* m_64;
};
struct S00d6f300_Cmd
{
    float f;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    int u8;
    int uc;
};
struct __declspec(align(16)) S00d6f300_Real
{
    float r;
};
struct S00d6f300_V4
{
    __m128 q;
    void setSub4(const S00d6f300_V4& a, const S00d6f300_V4& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    float dot3(const S00d6f300_V4& b) const
    {
        __m128 m = _mm_mul_ps(q, b.q);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m)));
        return r;
    }
};
struct S00d6f300_B
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
    S00d6f300_V4 m_30;
};
struct S00d6f300_Pair
{
    float a;
    float b;
};
struct S00d6f300_Out
{
    float x;
    float y;
    float z;
    float w;
};
struct __declspec(align(16)) S00d6f300_Info
{
    float res;
    S00d6f300_O* o;
    S00d6f300_Pair ab;
    float c;
    float d;
    S00d6f300_Out out;
};
void ComputeJacobian(const __m128* n, const __m128* pos, S00d6f300_O* o, S00d6f300_Cmd* cur, S00d6f300_Info* info);
void FUN_00dcfff0(void* h, S00d6f300_Info* info, S00d6f300_Out* out);
void FUN_00dd03c0(S00d6f300_Out* out, S00d6f300_O* o, S00d6f300_Cmd* cur, S00d6f300_Cmd** p);
extern const double DAT_010c9300;

// @f3 0x009fcb60 (community match, verified in this file)
namespace f3m_009fcb60 {
struct S00d6f300_OView
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
    unsigned char* m_4c;
};
struct S00d6f300_Vec
{
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;

    void setSub3(const __m128& a, const __m128& b)
    {
        x = a.m128_f32[0] - b.m128_f32[0];
        y = a.m128_f32[1] - b.m128_f32[1];
        z = a.m128_f32[2] - b.m128_f32[2];
    }
    float dot3(const __m128& n) const
    {
        return n.m128_f32[0] * x + n.m128_f32[1] * y + n.m128_f32[2] * z;
    }
};
}


// pdb: buildJacobianFromLinMotorAtom | hkpBuildJacobianFromAtoms.obj | tesv_win, caller_sim, low
static __declspec(noinline) void FUN_00d6f300(S00d6f300_A* s, S00d6f300_O* o, S00d6f300_B* a2, __m128* a3,
                                              S00d6f300_Cmd** p)
{
    unsigned char* base = reinterpret_cast<f3m_009fcb60::S00d6f300_OView*>(o)->m_4c;
    unsigned char* a = base + s->m_04;
    float* b = (float*)(base + s->m_06);
    if (s->m_02)
    {
        void* h = s->m_0c;
        if (h)
        {
            if (*a == 0)
                *b = s->m_08;
            S00d6f300_Cmd* cur = *p;
            S00d6f300_Info info;
            info.ab.a = 0.0f;
            info.ab.b = 0.0f;
            ComputeJacobian(&a3[s->m_03], &a2->m_30.q, o, cur, &info);
            f3m_009fcb60::S00d6f300_Vec d;
            d.setSub3(a2->m_30.q, a3[3]);
            info.o = o;
            info.ab = *(S00d6f300_Pair*)reinterpret_cast<f3m_009fcb60::S00d6f300_OView*>(o)->m_4c;
            info.c = s->m_08 - *b;
            info.d = *b - d.dot3(a3[s->m_03]);
            FUN_00dcfff0(h, &info, &info.out);
            FUN_00dd03c0(&info.out, o, cur, p);
            if (*b != s->m_08 || *a == 0)
            {
                *b = s->m_08;
                *a = 1;
            }
            return;
        }
    }
    S00d6f300_Cmd* q = *p;
    q->b4 = 1;
    q->f = (float)(q->f + DAT_010c9300);
    *(unsigned char*)q = 3;
    *p = q + 1;
}


void S00d6f300_caller(S00d6f300_A* s, S00d6f300_O* o, S00d6f300_B* a2, __m128* a3, S00d6f300_Cmd** p)
{
    FUN_00d6f300(s, o, a2, a3, p);
    FUN_00d6f300(s + 1, o, a2, a3, p);
}
