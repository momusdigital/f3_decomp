// src/havok/physics/internal/collide/gjk/hkpgsk_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/gjk/hkpgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/hkpgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/hkpgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Entry
{
    char pad[12];
    unsigned short val;
    char pad2[2];
};
struct Dest
{
    unsigned short words[4];
    unsigned char count1;
    unsigned char count2;
};
struct ThisClass
{
    int count1;
    int count2;
    char pad[0x18];
    Entry entries1[3];
    char pad2[0x90];
    Entry entries2[3];

    void FUN_00da9790(Dest* out);
};

#include <xmmintrin.h>
struct __declspec(align(16)) Vector
{
    __m128 quad;
    Vector()
    {}
    Vector(__m128 q) : quad(q)
    {}
    Vector& operator=(const Vector& rhs)
    {
        quad = rhs.quad;
        return *this;
    }
};
struct __declspec(align(16)) SegmentClosestResult
{
    Vector pointA, pointB;
    float distanceSquared;
};
struct Simplex
{
    int countA, countB, unk08, unk0c;
    Vector unk10;
    Vector verticesA[4];
    Vector unk60, unk70, unk80, unk90;
    Vector verticesB[4];
    Vector supportB[4];
    int FUN_00da8500(const Vector*, const Vector*, int);
    void hkpGsk_reduceDimensionExtended();
};
// @f3 0x00a30ca0 (community match, verified in this file)
extern const signed char DAT_00e7c778[];
extern const float DAT_00de6e60;
extern void __cdecl FUN_0096f780(const Vector*,const Vector*,const Vector*,const Vector*,SegmentClosestResult*);
inline void subtractVector(Vector& d,const Vector& a,const Vector& b) {d.quad.m128_f32[0]=a.quad.m128_f32[0]-b.quad.m128_f32[0];d.quad.m128_f32[1]=a.quad.m128_f32[1]-b.quad.m128_f32[1];d.quad.m128_f32[2]=a.quad.m128_f32[2]-b.quad.m128_f32[2];d.quad.m128_f32[3]=a.quad.m128_f32[3]-b.quad.m128_f32[3];}
inline void copyVector(Vector& a, const Vector& b) { a.quad.m128_f32[0]=b.quad.m128_f32[0]; a.quad.m128_f32[1]=b.quad.m128_f32[1]; a.quad.m128_f32[2]=b.quad.m128_f32[2]; a.quad.m128_f32[3]=b.quad.m128_f32[3]; }
namespace f3m_00a30ca0 {
struct SimplexView_a30ca0
{
    int countA, countB, unk08, unk0c;
    Vector unk10;
    Vector verticesA[4];
    Vector unk60, unk70, unk80, unk90;
    Vector verticesB[4];
    Vector supportB[4];
    int FUN_00a2ee70(const Vector*, const Vector*, int);
    __forceinline void hkpGsk_reduceDimensionExtended()
    {
    if (countB == 3)
    {
        for (int i = 0; i < countA; ++i)
        {
            if (FUN_00a2ee70(&verticesA[i], verticesB, 0) == 14)
            {
                copyVector(verticesA[0], verticesA[i]);
                countA = 1;
                return;
            }
        }
    }
    if (countA == 3)
    {
        for (int j = 0; j < countB; ++j)
        {
            if (FUN_00a2ee70(&verticesB[j], verticesA, 0) == 14)
            {
                copyVector(supportB[0], supportB[j]);
                copyVector(verticesB[0], verticesB[j]);
                countB = 1;
                return;
            }
        }
    }
    float bestDistance = DAT_00de6e60;
    int edgesA = 1 + 2 * (countA == 3), edgesB = 1 + 2 * (countB == 3);
    int bestA = 0, bestB = 0;
    for (int i = 0; i < edgesA; ++i)
    {
        for (int j = 0; j < edgesB; ++j)
        {
            Vector directionA; subtractVector(directionA, verticesA[DAT_00e7c778[i+2]], verticesA[i]);
            Vector directionB; subtractVector(directionB, verticesB[DAT_00e7c778[j+2]], verticesB[j]);
            SegmentClosestResult result;
            FUN_0096f780(&verticesA[i], &directionA, &verticesB[j], &directionB, &result);
            if (result.distanceSquared < bestDistance)
            {
                bestDistance = result.distanceSquared;
                bestA = i;
                bestB = j;
            }
        }
    }
    if (edgesA == 3)
    {
        --countA;
        copyVector(verticesA[DAT_00e7c778[bestA]], verticesA[countA]);
    }
    if (edgesB == 3)
    {
        --countB;
        int destination = DAT_00e7c778[bestB];
        copyVector(supportB[destination], supportB[countB]);
        copyVector(verticesB[destination], verticesB[countB]);
    }
}
};
}

// pdb: hkpGsk::reduceDimensionExtended | hkpGsk.obj | fnv360_0822_retail, objrun + bridge(udata|objrun) + skyrim(udata), high
void Simplex::hkpGsk_reduceDimensionExtended()
{
    reinterpret_cast<f3m_00a30ca0::SimplexView_a30ca0*>(this)->hkpGsk_reduceDimensionExtended();
}


union Collision_vector
{
    __m128 value;
    float component[4];
};

struct Collision_vcls
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f(void* a, int b, void* out);
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
};

struct Collision_in
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char m_08;
    unsigned char m_09;
    unsigned char m_0a;
};

struct Collision_mat
{
    __m128 m_00;
    __m128 m_10;
    __m128 m_20;
    __m128 m_30;
};

struct Collision_ctx
{
    void* m_vptr;
    Collision_mat* m_04;
    Collision_vcls* m_08;
    Collision_vcls* m_0c;
    float m_10;
};

struct Collision_workspace
{
    unsigned int countA;
    unsigned int countB;
    unsigned int low;
    unsigned int high;
    unsigned int unk10;
    unsigned int changed;
    unsigned int unk18;
    unsigned int unk1c;
    __m128 vector20;
    __m128 vector30;
    __m128 vector40;
    __m128 vector50;
    __m128 vector60;
    __m128 vector70;
    __m128 vector80;
    __m128 vector90;
    __m128 vectora0;
    __m128 vectorb0;
    __m128 vectorc0;
    __m128 vectord0;
    __m128 vectore0;
    __m128 vectorf0;
    __m128 vector100;
    __m128 vector110;
    __m128 vector120;
    __m128 vector130;
    __m128 vector140;
    __m128 vector150;
    __m128 vector160;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    int FUN_00daad40(Collision_vcls*, Collision_vcls*, void*, Collision_vector*);
};

// @f3 0x00a345e0 (community match, verified in this file)
// pdb: hkpGsk::getClosestPoint | hkpGsk.obj | fnv360_0822_retail, caller + bridge(call_seq|call_gap) + skyrim(call_seq), high
int hkpGsk_getClosestPoint(Collision_ctx* self, Collision_in* in, Collision_vector* out, Collision_vector* out2)
{
    struct Collision_shape_view
    {
        virtual void v00() = 0;
        virtual void v01() = 0;
        virtual void v02() = 0;
        virtual void v03() = 0;
        virtual void v04() = 0;
        virtual void v05() = 0;
        virtual void v06() = 0;
        virtual void v07() = 0;
        virtual void v08() = 0;
        virtual void v09() = 0;
        virtual void v0a() = 0;
        virtual void v0b() = 0;
        virtual void v0c() = 0;
        virtual void v0d(const unsigned short* indices, int count, Collision_vector* out) = 0;
    };
    struct Collision_mat_view
    {
        Collision_vector m_00, m_10, m_20, m_30;
        __forceinline void Rotate3(const Collision_vector& v, Collision_vector& dst) const
        {
            dst.component[0] = m_20.component[0] * v.component[2] + (m_00.component[0] * v.component[0] + m_10.component[0] * v.component[1]);
            dst.component[1] = m_20.component[1] * v.component[2] + (m_00.component[1] * v.component[0] + m_10.component[1] * v.component[1]);
            dst.component[2] = m_20.component[2] * v.component[2] + (m_00.component[2] * v.component[0] + m_10.component[2] * v.component[1]);
            *(volatile float*)&dst.component[3] = 0;
        }
        __forceinline void TransformPosition3(const Collision_vector& v, Collision_vector& dst) const
        {
            dst.component[0] = (m_20.component[0] * v.component[2] + (m_00.component[0] * v.component[0] + m_10.component[0] * v.component[1])) + m_30.component[0];
            dst.component[1] = (m_20.component[1] * v.component[2] + (m_00.component[1] * v.component[0] + m_10.component[1] * v.component[1])) + m_30.component[1];
            dst.component[2] = (m_20.component[2] * v.component[2] + (m_00.component[2] * v.component[0] + m_10.component[2] * v.component[1])) + m_30.component[2];
            dst.component[3] = 0;
        }
    };
    Collision_vector normal;
    Collision_workspace scratch;
    float d;

    Collision_vcls* shapeA = self->m_08;
    Collision_vcls* shapeB = self->m_0c;

    scratch.countA = in->m_08;
    scratch.countB = in->m_09;
    scratch.unk10 = 0;
    scratch.low = in->m_0a & 0xf;
    scratch.high = in->m_0a >> 4;
    scratch.changed = 0;

    ((Collision_shape_view*)shapeA)->v0d((const unsigned short*)in, (int)scratch.countA, (Collision_vector*)&scratch.vector20);
    ((Collision_shape_view*)shapeB)->v0d((const unsigned short*)in + scratch.countA, (int)scratch.countB, (Collision_vector*)&scratch.vectore0);

    scratch.FUN_00daad40(self->m_08, self->m_0c, self->m_vptr, &normal);
    if (scratch.changed != 0)
    {
        ((ThisClass*)&scratch)->FUN_00da9790((Dest*)in);
    }

    float w = normal.component[3];
    d = (w - self->m_08->m_10) - self->m_0c->m_10;

    ((Collision_mat_view*)self->m_04)->Rotate3(normal, *out);
    out->component[3] = d;

    if (self->m_10 > d)
    {
        if (scratch.countA == 1)
        {
            float bb = self->m_0c->m_10 - w;
            Collision_vector& support = *(Collision_vector*)&scratch.vector20;
            normal.component[0] = normal.component[0] * bb + support.component[0];
            normal.component[1] = normal.component[1] * bb + support.component[1];
            normal.component[2] = normal.component[2] * bb + support.component[2];
        }
        else if (scratch.countB == 1)
        {
            float bb = self->m_0c->m_10;
            Collision_vector& support = *(Collision_vector*)&scratch.vectora0;
            normal.component[0] = normal.component[0] * bb + support.component[0];
            normal.component[1] = normal.component[1] * bb + support.component[1];
            normal.component[2] = normal.component[2] * bb + support.component[2];
        }
        else
        {
            float bb = self->m_0c->m_10 - w;
            Collision_vector& support = *(Collision_vector*)&scratch.vector130;
            normal.component[0] = normal.component[0] * bb + support.component[0];
            normal.component[1] = normal.component[1] * bb + support.component[1];
            normal.component[2] = normal.component[2] * bb + support.component[2];
        }

        ((Collision_mat_view*)self->m_04)->TransformPosition3(normal, *out2);
        return 0;
    }
    return 1;
}


// @fnv 0x00da8350
__m128* volatile gP;
__m128* volatile gO;
__m128* volatile gN;
__m128* volatile gOut;
__m128* volatile gD;
