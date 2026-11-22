#include "f3_common.h"
// src/havok/common/visualize/shape/hkdisplaycapsule.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycapsule.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
    double sqrt(double);
}
extern float DAT_0104da4c;
extern double DAT_01016978;
struct Vector
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
    Vector()
    {}
    Vector(const Vector& v)
    {
        quad = v.quad;
    }
    void operator=(const Vector& v)
    {
        quad = v.quad;
    }
};
struct Matrix
{
    Vector c0, c1, c2, c3;
};
struct Other
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Matrix* transform;
};
struct Limit
{
    Vector axis, origin;
    float slope, positive, negative, scale;
};
static __forceinline __m128 dot3(const Vector& a, const Vector& b)
{
    __m128 p = _mm_mul_ps(a.quad, b.quad);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
}
static __forceinline __m128 broadcast(__m128 a)
{
    return _mm_shuffle_ps(a, a, 0);
}
static __forceinline __m128 scalar(float a)
{
    return broadcast(_mm_load_ss(&a));
}
static __forceinline float value(__m128 a)
{
    float r;
    _mm_store_ss(&r, a);
    return r;
}
static __forceinline void crossProduct(Vector& result, const Vector& a, const Vector& b)
{
    __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xc9), _mm_shuffle_ps(b.quad, b.quad, 0xd2));
    __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xd2), _mm_shuffle_ps(b.quad, b.quad, 0xc9));
    result.quad = _mm_sub_ps(p, q);
}
// Projects a point onto a Limit cone defined by axis, origin, slope, and positive/negative limits, applying scale and transform constraints.
// @fnv 0x00d234e0
static __declspec(noinline) void FUN_00d234e0(Limit* apLimit, const Vector* point, Vector* out, Other* other)
{
    float slope = apLimit->slope;
    float scale = apLimit->scale;
    Vector offset;
    offset.quad = _mm_sub_ps(point->quad, apLimit->origin.quad);
    Vector origin = apLimit->origin;
    Vector axis = apLimit->axis;
    __m128 axial = dot3(axis, offset);
    float distance2;
    _mm_store_ss(&distance2, dot3(offset, offset));
    offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(axial), axis.quad));
    float axial2;
    _mm_store_ss(&axial2, _mm_mul_ss(axial, axial));
    Matrix* transform = other->transform;
    float facing;
    _mm_store_ss(&facing, dot3(transform->c3, offset));
    float limit = facing > 0.0f ? apLimit->positive : apLimit->negative;
    if (limit > 0.0f)
    {
        float side = 0.0f;
        Vector cross;
        crossProduct(cross, transform->c3, axis);
        float cross2;
        _mm_store_ss(&cross2, dot3(cross, cross));
        if (DAT_0104da4c < cross2)
        {
            float len = (float)sqrt(cross2);
            float inv = 1.0f / len;
            cross.quad = _mm_mul_ps(scalar(inv), cross.quad);
            side = value(dot3(cross, offset));
            float slope2 = slope * slope;
            float side2 = side * side;
            if (slope2 * axial2 >= side2)
            {
                offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(scalar(side), cross.quad));
                side = 0.0f;
            }
        }
        float cone2 = (limit + slope) * (limit + slope);
        float residual2 = distance2 - side * side - axial2;
        if (cone2 * axial2 >= residual2)
        {
            if (side == 0.0f)
            {
                out->quad = origin.quad;
                return;
            }
            offset.quad = _mm_mul_ps(scalar(side), cross.quad);
        }
    }
    else
    {
        float slope2 = slope * slope;
        if ((slope2 + 1.0) * axial2 >= distance2)
        {
            out->quad = origin.quad;
            return;
        }
    }
    if (scale < 1.0f)
    {
        float projected2;
        _mm_store_ss(&projected2, dot3(offset, offset));
        if (DAT_0104da4c <= projected2 && distance2 * DAT_01016978 < projected2)
        {
            float ratio = distance2 / projected2;
            float root = (float)sqrt(ratio);
            float factor = scale + (1.0f - scale) * root;
            offset.quad = _mm_mul_ps(scalar(factor), offset.quad);
            __m128 component = dot3(axis, offset);
            offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(component), axis.quad));
        }
    }
    origin.quad = _mm_add_ps(origin.quad, offset.quad);
    out->quad = origin.quad;
}
Limit* volatile inputLimit;
const Vector* volatile inputPoint;
Vector* volatile outputPoint;
Other* volatile inputOther;

extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    double fabs(double);
}
static __forceinline float root(float f)
{
    return (float)sqrt(f);
}
static __forceinline float absoluteValue(float f)
{
    return (float)fabs(f);
}
extern float DAT_0104da4c;
extern const __m128 DAT_01017d10;
extern const float DAT_01011d78;

static __forceinline __m128 scalarParam(float f)
{
    return _mm_load_ss(&f);
}
static __forceinline float scalar(__m128 q)
{
    float f;
    _mm_store_ss(&f, q);
    return f;
}

struct Basis
{
    Vector first, second, third;
};
struct Record : Limit
{
    int priority, unk34, unk38, unk3c;
};
struct State
{
    int unk00, unk04, unk08;
    int state;
};
struct Shape : Matrix
{
    int unk40, unk44;
    Record* records;
};
struct Working
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    State* states;
};
struct Context
{
    Other base;
    Working* working;
};
struct ContextArg
{
    Context* p;
};
struct VecArg
{
    Vector* p;
    VecArg(Vector* v) : p(v)
    {}
};

static __forceinline __m128 prefixColumns(Context* context, Record* a, Record* b, const Vector& raw, const Vector& unit,
                                          const Basis& basis, float inv, Vector& base, __m128& first, __m128& second)
{
    float bDot = scalar(dot3(b->origin, b->axis));
    float aDot = scalar(dot3(a->origin, a->axis));
    Vector centerSum;
    centerSum.quad = _mm_add_ps(a->origin.quad, b->origin.quad);
    float midpointDot = scalar(dot3(centerSum, unit)) * 0.5;
    __m128 weights = _mm_setr_ps(midpointDot, aDot, bDot, DAT_01011d78);
    first = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0), basis.first.quad);
    second = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0x55), basis.second.quad);
    __m128 third = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0xaa), basis.third.quad);
    return third;
}
// Uses the cross product of a and b's axes to compute a point written to out; if that is degenerate or out of bounds, calls FUN_00d234e0 on both records.
// @fnv 0x00d23850
static __declspec(noinline) void FUN_00d23850(Context* context, Record* a, Record* b, VecArg point, Vector* out)
{
    float threshold = DAT_0104da4c;
    Vector raw;
    crossProduct(raw, a->axis, b->axis);
    float fLengthSq = scalar(dot3(raw, raw));
    if (threshold >= fLengthSq)
        goto fallback;
    {
        float inv = 1.0f / root(fLengthSq);
        __m128 scale = scalarParam(inv);
        Vector unit;
        unit.quad = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), raw.quad);
        Basis basis;
        basis.first.quad = raw.quad;
        crossProduct(basis.second, b->axis, unit);
        crossProduct(basis.third, unit, a->axis);
        Vector base;
        __m128 first;
        __m128 second;
        __m128 third = prefixColumns(context, a, b, raw, unit, basis, inv, base, first, second);
        base.quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(first, second), third),
                               _mm_shuffle_ps(scalarParam(inv), scalarParam(inv), 0));
        __m128 absolute = _mm_and_ps(base.quad, DAT_01017d10);
        if (_mm_movemask_ps(_mm_cmplt_ps(context->base.transform->c2.quad, absolute)) & 7)
            goto fallback;

        Vector delta;
        delta.quad = _mm_sub_ps(point.p->quad, base.quad);
        float distance2 = scalar(dot3(delta, delta));
        float preferred = scalar(dot3(context->base.transform->c3, unit));
        float axial = scalar(dot3(delta, unit));
        float displacement = axial;
        float radius = a->slope + b->slope;
        if (axial * preferred > 0.0)
            radius += preferred * (a->positive + b->positive);
        else
            radius += preferred * (a->negative + b->negative);
        radius = radius * 0.5;
        float blend = (a->scale + b->scale) * 0.5;
        float axial2 = axial * axial;
        if ((distance2 - axial2) * float(radius * radius) >= axial2)
        {
            out->quad = base.quad;
            return;
        }
        if (blend < 1.0f && distance2 * DAT_01016978 < axial * axial)
        {
            float invAxial = 1.0f / axial;
            invAxial = absoluteValue(invAxial);
            float ratio = root(distance2);
            ratio = ratio * invAxial;
            ratio = blend + (1.0f - blend) * ratio;
            displacement = ratio * axial;
        }
        out->quad =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&displacement), _mm_load_ss(&displacement), 0), unit.quad),
                       base.quad);
        return;
    }
fallback:
    context->working->states[a - static_cast<Shape*>(context->base.transform)->records].state = 2;
    context->working->states[b - static_cast<Shape*>(context->base.transform)->records].state = 2;
    ContextArg ca = {context};
    Vector* dst = out;
    Vector* src = point.p;
    if (a->priority > b->priority)
    {
        FUN_00d234e0(b, src, dst, &ca.p->base);
        FUN_00d234e0(a, dst, dst, &ca.p->base);
    }
    else
    {
        FUN_00d234e0(a, src, dst, &ca.p->base);
        FUN_00d234e0(b, dst, dst, &ca.p->base);
    }
}

struct V
{
    union
    {
        __m128 v;
        float f[4];
    };
    V()
    {}
    V(const V& r)
    {
        v = r.v;
    }
    void operator=(const V& r)
    {
        v = r.v;
    }
    void cross(const V& a, const V& b);
};
struct CrossBasis
{
    V bc;
    V ca;
    V ab;
    CrossBasis()
    {}
    V& column(int n)
    {
        return (&bc)[n];
    }
    const V& column(int n) const
    {
        return (&bc)[n];
    }
};
struct PlaneMeta
{
    int priority, unk34, unk38, unk3c;
};
struct PlaneRecord
{

    V normal;

    V point;

    __m128 auxiliary;

    PlaneMeta metadata;
};

struct PlaneStatus
{
    int unk00;
    int unk04;
    int unk08;
    int marked;
};

struct PlaneGeometry
{

    __m128 unk00;

    __m128 unk10;

    __m128 bounds;

    __m128 unk30;

    int unk40;

    int unk44;

    PlaneRecord* planes;
};

struct PlaneStatusStore
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

    PlaneStatus* entries;
};

struct IntersectionContext
{

    int unk00;

    PlaneRecord* first;

    int unk08;
    int unk0c;

    PlaneRecord* second;

    int unk14;
    int unk18;

    PlaneRecord* third;

    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    int count;

    int unk34;

    PlaneGeometry* geometry;

    PlaneStatusStore* status;
};

extern void __cdecl FUN_00d23380(IntersectionContext* context);

inline void V::cross(const V& a, const V& b)
{

    __m128 lhs = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xc9), _mm_shuffle_ps(b.v, b.v, 0xd2));

    __m128 rhs = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xd2), _mm_shuffle_ps(b.v, b.v, 0xc9));

    v = _mm_sub_ps(lhs, rhs);
}

inline float dot(const __m128& a, const __m128& b)
{

    __m128 p = _mm_mul_ps(a, b);

    __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);

    __m128 total = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);

    float result;
    _mm_store_ss(&result, total);
    return result;
}

inline __m128 distances3(float a, float b, float c)
{
    return _mm_setr_ps(a, b, c, DAT_01011d78);
}

extern void __cdecl FUN_00d234e0(IntersectionContext*, PlaneRecord*, const __m128*);

extern const double DAT_01011588 = 0.5;

struct PairPlane
{
    PlaneRecord* p;
};

struct PairRead
{
    const __m128* p;
};

struct PairWrite
{
    __m128* p;
};

static __declspec(noinline) void FUN_00d23850(IntersectionContext* ctx, PairPlane aw, PairPlane bw, PairRead fw,
                                              PairWrite rw)

{

    PlaneRecord* a = aw.p;
    PlaneRecord* b = bw.p;

    const V& na = a->normal;
    const V& nb = b->normal;

    V direction;
    direction.cross(na, nb);

    float squaredLength = dot(direction.v, direction.v);

    if (!(squaredLength < DAT_0104da4c))
    {

        float inverse = 1.0f / root(squaredLength);

        direction.v = _mm_mul_ps(direction.v, scalar(inverse));

        V right, left;
        right.cross(nb, direction);
        left.cross(direction, na);

        float db = dot(b->point.v, nb.v);

        float da = dot(a->point.v, na.v);

        float average = (float)(dot(_mm_add_ps(a->point.v, b->point.v), direction.v) * DAT_01011588);

        __m128 distances = distances3(average, db, da);

        __m128 sum = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0),
                       _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xd2), _mm_shuffle_ps(na.v, na.v, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xc9), _mm_shuffle_ps(na.v, na.v, 0xd2)))),
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0x55), left.v));

        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0xaa), right.v));

        __m128 position = _mm_mul_ps(sum, scalar(inverse));

        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(position, DAT_01017d10))) & 7))
        {

            __m128 difference = _mm_sub_ps(*fw.p, position);

            float squared = dot(difference, difference);

            float radius = dot(ctx->geometry->unk30, direction.v);

            float projection = dot(difference, direction.v);

            float threshold = (float)((a->auxiliary.m128_f32[0] + b->auxiliary.m128_f32[0] +
                                       radius * ((projection * radius > 0.0f)
                                                     ? a->auxiliary.m128_f32[1] + b->auxiliary.m128_f32[1]
                                                     : a->auxiliary.m128_f32[2] + b->auxiliary.m128_f32[2])) *
                                      DAT_01011588);

            float blend = (float)((a->auxiliary.m128_f32[3] + b->auxiliary.m128_f32[3]) * DAT_01011588);

            if ((squared - projection * projection) * threshold * threshold >= projection * projection)
            {
                *rw.p = position;
                return;
            }

            float adjustment = projection;

            if (blend < 1.0f && !(0.001f * squared < projection * projection))

                adjustment = projection * (blend + root(squared) * absoluteValue(1.0f / projection) * (1.0f - blend));

            *rw.p = _mm_add_ps(position, _mm_mul_ps(scalar(adjustment), direction.v));

            return;
        }
    }

    ctx->status->entries[a - ctx->geometry->planes].marked = 2;

    ctx->status->entries[b - ctx->geometry->planes].marked = 2;

    if (a->metadata.priority > b->metadata.priority)
    {

        FUN_00d234e0(ctx, b, fw.p);
        FUN_00d234e0(ctx, a, rw.p);
    }
    else
    {
        FUN_00d234e0(ctx, a, fw.p);
        FUN_00d234e0(ctx, b, rw.p);
    }
}

struct Wrap_reorder
{
    int p;
};

struct Wrap_fallback
{
    const __m128* p;
};

struct Wrap_result
{
    __m128* p;
};

// Computes the intersection point of three planes using a cross-product basis, falling back to sequential pairwise intersection if the determinant is near zero.
// @fnv 0x00d23ca0
static __declspec(noinline) void FUN_00d23ca0(IntersectionContext* ctx, PlaneRecord* apPlaneA, PlaneRecord* apPlaneB,
                                              PlaneRecord* apPlaneC, Wrap_reorder reorder, Wrap_fallback fallback,
                                              Wrap_result result)
{
    V point;
    CrossBasis basis;
    V& bc = basis.column(0);
    V& ca = basis.column(1);
    V& ab = basis.column(2);
    bc.cross(apPlaneB->normal, apPlaneC->normal);
    ca.cross(apPlaneC->normal, apPlaneA->normal);
    ab.cross(apPlaneA->normal, apPlaneB->normal);
    float determinant = dot(bc.v, apPlaneA->normal.v);
    if (absoluteValue(determinant) < 0.00000011920928955078125f)
        goto sequential;
    {
        V weights;
        float dc = dot(apPlaneC->normal.v, apPlaneC->point.v);
        float db = dot(apPlaneB->normal.v, apPlaneB->point.v);
        weights.v = distances3(dot(apPlaneA->normal.v, apPlaneA->point.v), db, dc);
        __m128 wx = _mm_shuffle_ps(weights.v, weights.v, 0);
        __m128 first = _mm_mul_ps(basis.column(0).v, wx);
        __m128 wy = _mm_shuffle_ps(weights.v, weights.v, 0x55);
        __m128 second = _mm_mul_ps(basis.column(1).v, wy);
        __m128 wz = _mm_shuffle_ps(weights.v, weights.v, 0xaa);
        __m128 third = _mm_mul_ps(basis.column(2).v, wz);
        point.v = _mm_add_ps(_mm_add_ps(first, second), third);
        float inverse = 1.0f / determinant;
        point.v = _mm_mul_ps(point.v, _mm_shuffle_ps(_mm_load_ss(&inverse), _mm_load_ss(&inverse), 0));
        V absolute;
        absolute.v = _mm_and_ps(point.v, DAT_01017d10);
        if (_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, absolute.v)) & 7)
            goto sequential;
        *result.p = point.v;
        return;
    }
sequential:
    if (reorder.p)
    {
        FUN_00d23380(ctx);
        apPlaneA = ctx->first;
        apPlaneB = ctx->second;
        apPlaneC = ctx->third;
    }
    ctx->status->entries[apPlaneA - ctx->geometry->planes].marked = 1;
    ctx->status->entries[apPlaneB - ctx->geometry->planes].marked = 1;
    ctx->status->entries[apPlaneC - ctx->geometry->planes].marked = 1;
    int oldCount = ctx->count;
    {
        PairPlane pa = {apPlaneA}, pb = {apPlaneB};
        PairRead pf = {fallback.p};
        PairWrite pr = {result.p};
        FUN_00d23850(ctx, pa, pb, pf, pr);
    }
    if (oldCount == ctx->count)
    {
        PairPlane pa = {apPlaneA}, pc = {apPlaneC};
        PairRead pf = {result.p};
        PairWrite pr = {result.p};
        FUN_00d23850(ctx, pa, pc, pf, pr);
    }
    if (oldCount == ctx->count)
    {
        PairPlane pb = {apPlaneB}, pc = {apPlaneC};
        PairRead pf = {result.p};
        PairWrite pr = {result.p};
        FUN_00d23850(ctx, pb, pc, pf, pr);
    }
}

extern float runtimeFloatSettingDefault166;

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b ? 1 : 0)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Vec4
{
    union
    {
        __m128 m_vComponents;
        struct
        {
            float x, y, z, w;
        };
    };
    void operator=(const Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct ActivePlane
{
    int m_uiEdgeIndex;
    PlaneRecord* m_pHavokConstraint;
    PlaneStatus* m_pPlaneStatus;
};

struct SimplexInput
{
    Vec4 m_vContactPosition;
    Vec4 m_fVelocity;
    Vec4 m_vThirdInputVector;
    Vec4 m_vFourthInputVector;
    float m_fTimeStep;
    float m_fConstraintParameter;
    PlaneRecord* m_ppConstraints;
    int m_iConstraintCount;
};

struct SimplexOutput
{
    Vec4 m_vContactPosition;
    Vec4 m_fVelocity;
    float m_fTimeStep;
    PlaneStatus* m_pPlaneStatuses;
};

struct SimplexInfo
{
    ActivePlane m_kActivePlanes[4];
    int m_iActivePlaneCount;
    float m_fElapsedSimulationTime;
    const SimplexInput* m_pRayCastInput;
    SimplexOutput* m_pRayCastOutput;
};

static __declspec(noinline) void FUN_00d234e0(const SimplexInfo& other_, const PlaneRecord& self_, const Vec4& point_,
                                              Vec4& out_)
{
    const Limit* self = (const Limit*)&self_;
    const Vector* point = (const Vector*)&point_;
    Vector* out = (Vector*)&out_;
    const Other* other = (const Other*)&other_;
    float slope = self->slope;
    float scale = self->scale;
    Vector offset;
    offset.quad = _mm_sub_ps(point->quad, self->origin.quad);
    Vector origin = self->origin;
    Vector axis = self->axis;
    __m128 axial = dot3(axis, offset);
    float distance2;
    _mm_store_ss(&distance2, dot3(offset, offset));
    offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(axial), axis.quad));
    float axial2;
    _mm_store_ss(&axial2, _mm_mul_ss(axial, axial));
    Matrix* transform = other->transform;
    float facing;
    _mm_store_ss(&facing, dot3(transform->c3, offset));
    float limit = facing > 0.0f ? self->positive : self->negative;
    if (limit > 0.0f)
    {
        float side = 0.0f;
        Vector cross;
        crossProduct(cross, transform->c3, axis);
        float cross2;
        _mm_store_ss(&cross2, dot3(cross, cross));
        if (DAT_0104da4c < cross2)
        {
            float len = (float)sqrt(cross2);
            float inv = 1.0f / len;
            cross.quad = _mm_mul_ps(scalar(inv), cross.quad);
            side = value(dot3(cross, offset));
            float slope2 = slope * slope;
            float side2 = side * side;
            if (slope2 * axial2 >= side2)
            {
                offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(scalar(side), cross.quad));
                side = 0.0f;
            }
        }
        float cone2 = (limit + slope) * (limit + slope);
        float residual2 = distance2 - side * side - axial2;
        if (cone2 * axial2 >= residual2)
        {
            if (side == 0.0f)
            {
                out->quad = origin.quad;
                return;
            }
            offset.quad = _mm_mul_ps(scalar(side), cross.quad);
        }
    }
    else
    {
        float slope2 = slope * slope;
        if ((slope2 + 1.0) * axial2 >= distance2)
        {
            out->quad = origin.quad;
            return;
        }
    }
    if (scale < 1.0f)
    {
        float projected2;
        _mm_store_ss(&projected2, dot3(offset, offset));
        if (DAT_0104da4c <= projected2 && distance2 * DAT_01016978 < projected2)
        {
            float ratio = distance2 / projected2;
            float root = (float)sqrt(ratio);
            float factor = scale + (1.0f - scale) * root;
            offset.quad = _mm_mul_ps(scalar(factor), offset.quad);
            __m128 component = dot3(axis, offset);
            offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(component), axis.quad));
        }
    }
    origin.quad = _mm_add_ps(origin.quad, offset.quad);
    out->quad = origin.quad;
}

static __declspec(noinline) hkBool FUN_00d23480(const PlaneRecord& sci, const Vec4& velocityIn)
{
    V relativeVelocity;
    relativeVelocity.v = _mm_sub_ps(velocityIn.m_vComponents, sci.point.v);
    float planeVel = dot(relativeVelocity.v, sci.normal.v);
    if (planeVel < runtimeFloatSettingDefault166)
    {
        return false;
    }
    return true;
}

static __declspec(noinline) void FUN_00d23850(SimplexInfo& ctx_, const PlaneRecord* a_, const PlaneRecord* b_,
                                              const Vec4* fw_, Vec4* rw_)
{
    IntersectionContext* ctx = (IntersectionContext*)&ctx_;
    const PlaneRecord* a = *(const PlaneRecord* const volatile*)&a_;
    const PlaneRecord* b = *(const PlaneRecord* const volatile*)&b_;
    const Vec4& fw = **(const Vec4* const volatile*)&fw_;
    Vec4& rw = **(Vec4* const volatile*)&rw_;
    const V& na = a->normal;
    const V& nb = b->normal;
    V direction;
    direction.cross(na, nb);
    float squaredLength = dot(direction.v, direction.v);
    if (!(squaredLength < DAT_0104da4c))
    {
        float inverse = 1.0f / root(squaredLength);
        direction.v = _mm_mul_ps(direction.v, scalar(inverse));
        V right, left;
        right.cross(nb, direction);
        left.cross(direction, na);
        float db = dot(b->point.v, nb.v);
        float da = dot(a->point.v, na.v);
        float average = (float)(dot(_mm_add_ps(a->point.v, b->point.v), direction.v) * DAT_01011588);
        __m128 distances = distances3(average, db, da);
        __m128 sum = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0),
                       _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xd2), _mm_shuffle_ps(na.v, na.v, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xc9), _mm_shuffle_ps(na.v, na.v, 0xd2)))),
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0x55), left.v));
        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0xaa), right.v));
        __m128 position = _mm_mul_ps(sum, scalar(inverse));
        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(position, DAT_01017d10))) & 7))
        {
            __m128 difference = _mm_sub_ps(fw.m_vComponents, position);
            float squared = dot(difference, difference);
            float radius = dot(ctx->geometry->unk30, direction.v);
            float projection = dot(difference, direction.v);
            float threshold = (float)((a->auxiliary.m128_f32[0] + b->auxiliary.m128_f32[0] +
                                       radius * ((projection * radius > 0.0f)
                                                     ? a->auxiliary.m128_f32[1] + b->auxiliary.m128_f32[1]
                                                     : a->auxiliary.m128_f32[2] + b->auxiliary.m128_f32[2])) *
                                      DAT_01011588);
            float blend = (float)((a->auxiliary.m128_f32[3] + b->auxiliary.m128_f32[3]) * DAT_01011588);
            if ((squared - projection * projection) * threshold * threshold >= projection * projection)
            {
                rw.m_vComponents = position;
                return;
            }
            float adjustment = projection;
            if (blend < 1.0f && !(0.001f * squared < projection * projection))
            {
                adjustment = projection * (blend + root(squared) * absoluteValue(1.0f / projection) * (1.0f - blend));
            }
            rw.m_vComponents = _mm_add_ps(position, _mm_mul_ps(scalar(adjustment), direction.v));
            return;
        }
    }
    ctx->status->entries[a - ctx->geometry->planes].marked = 2;
    ctx->status->entries[b - ctx->geometry->planes].marked = 2;
    *(const PlaneRecord* const volatile*)&b_;
    if (a->metadata.priority > b->metadata.priority)
    {
        FUN_00d234e0(ctx_, *b, fw, rw);
        FUN_00d234e0(ctx_, *a, rw, rw);
    }
    else
    {
        FUN_00d234e0(ctx_, *a, fw, rw);
        FUN_00d234e0(ctx_, *b, rw, rw);
    }
}

static __declspec(noinline) void FUN_00d23ca0(SimplexInfo& ctx_, const PlaneRecord* a, const PlaneRecord* b,
                                              const PlaneRecord* c, int allowResort, const Vec4& fallback, Vec4& result)
{
    IntersectionContext* ctx = (IntersectionContext*)&ctx_;
    CrossBasis m;
    V& r0 = m.column(0);
    V& r1 = m.column(1);
    V& r2 = m.column(2);
    r0.cross(b->normal, c->normal);
    r1.cross(c->normal, a->normal);
    r2.cross(a->normal, b->normal);
    float det = dot(r0.v, a->normal.v);
    if (!(absoluteValue(det) < DAT_0104da4c))
    {
        float dc = dot(c->point.v, c->normal.v);
        float db = dot(b->point.v, b->normal.v);
        float da = dot(a->point.v, a->normal.v);
        __m128 t = distances3(da, db, dc);
        float invDet = 1.0f / det;
        __m128 sVel = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), r0.v), _mm_mul_ps(_mm_shuffle_ps(t, t, 0x55), r1.v)),
            _mm_mul_ps(_mm_shuffle_ps(t, t, 0xaa), r2.v));
        sVel = _mm_mul_ps(sVel, scalar(invDet));
        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(sVel, DAT_01017d10))) & 7))
        {
            result.m_vComponents = sVel;
            return;
        }
    }
    if (allowResort)
    {
        FUN_00d23380(ctx);
        a = ctx->first;
        b = ctx->second;
        c = ctx->third;
    }
    ctx->status->entries[a - ctx->geometry->planes].marked = 1;
    ctx->status->entries[b - ctx->geometry->planes].marked = 1;
    ctx->status->entries[c - ctx->geometry->planes].marked = 1;
    int oldNum = ctx->count;
    FUN_00d23850(ctx_, a, b, &fallback, &result);
    if (ctx->count == oldNum)
    {
        FUN_00d23850(ctx_, a, c, &result, &result);
    }
    if (ctx->count == oldNum)
    {
        FUN_00d23850(ctx_, b, c, &result, &result);
    }
}

template <typename T> static __forceinline T hkMax2(T a, T b)
{
    return a > b ? a : b;
}

// Iteratively reduces the active plane set by testing velocity against planes and resolving intersections until a stable result is written to the ray-cast output.
// @f3 0x009a5680 (community match, verified in this file)
struct SimplexInfo;
extern void* g_simplexAnchor_009a5680;
// Havok 5.5.0 hkSimplexSolverExamineActivePlanes (hkpConstraintSolver.lib, hkpSimplexSolver.obj; game 0x009a5680).
// The classes and inline definitions in the namespace are the SDK's own (FPU hkVector4, hkMatrix3, hkMath, hkBool,
// the simplex structures), cut down to what this function and its file-local callees use.
#include <math.h>
namespace hk_009a5680 {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUint8;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
}
class hkMatrix3;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::subMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x -= r * a.x;
	y -= r * a.y;
	z -= r * a.z;
	w -= r * a.w;
}
inline void hkVector4::subMul4(const hkVector4& a, const hkVector4& b)
{
	x -= a.x * b.x;
	y -= a.y * b.y;
	z -= a.z * b.z;
	w -= a.w * b.w;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& m0, const hkVector4& m1)
{
	x = a.x + m0.x * m1.x;
	y = a.y + m0.y * m1.y;
	z = a.z + m0.z * m1.z;
	w = a.w + m0.w * m1.w;
}
	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkVector4Comparison hkVector4::compareLessThan4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
	inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}
struct hkpSurfaceConstraintInfo
{
	hkVector4 m_plane;
	hkVector4 m_velocity;
	hkReal m_staticFriction;
	hkReal m_extraUpStaticFriction;
	hkReal m_extraDownStaticFriction;
	hkReal    m_dynamicFriction;
	int		  m_priority;
};
struct hkpSimplexSolverInput
{
	hkVector4 m_position;
	hkVector4 m_velocity;
	hkVector4 m_maxSurfaceVelocity;
	hkVector4 m_upVector;
	hkReal	  m_deltaTime;
	hkReal	  m_minDeltaTime;
	hkpSurfaceConstraintInfo* m_constraints;
	int	m_numConstraints;
};
struct hkpSurfaceConstraintInteraction
{
	enum hkpStatus
	{
		HK_STATUS_OK = 0,
		HK_STATUS_3D_FAILURE = 1,
		HK_STATUS_2D_FAILURE = 2
	};
	hkUint8      m_touched;
	hkUint8      m_stopped;
	hkReal    m_surfaceTime;
	hkReal    m_penaltyDistance;
	hkpStatus  m_status;
};
struct hkpSimplexSolverOutput
{
	hkVector4		  m_position;
	hkVector4		  m_velocity;
	hkReal			  m_deltaTime;
	hkpSurfaceConstraintInteraction* m_planeInteractions;
};
struct hkSimplexSolverActivePlanes
{
	int m_index;
	const hkpSurfaceConstraintInfo* m_constraint;
	hkpSurfaceConstraintInteraction* m_interaction;
};
struct hkSimplexSolverInfo
{
	hkpSurfaceConstraintInteraction& getOutput( const hkpSurfaceConstraintInfo* sci )
	{
		return m_output->m_planeInteractions[ sci - m_input->m_constraints ];
	}
	hkSimplexSolverActivePlanes m_supportPlanes[4];
	int m_numSupportPlanes;
	hkReal m_currentTime;
	const hkpSimplexSolverInput* m_input;
	hkpSimplexSolverOutput* m_output;
};
static void hkSimplexSolverSortInfo( hkSimplexSolverInfo& info )
{
	for ( int i = 0; i < info.m_numSupportPlanes - 1; i++ )
	{
		for ( int j = i + 1; j < info.m_numSupportPlanes; j++ )
		{
			hkSimplexSolverActivePlanes& p0 = info.m_supportPlanes[i];
			hkSimplexSolverActivePlanes& p1 = info.m_supportPlanes[j];
			if ( p0.m_constraint->m_priority < p1.m_constraint->m_priority )
			{
				continue;
			}
			if ( p0.m_constraint->m_priority == p1.m_constraint->m_priority )
			{
				hkReal vel0 = p0.m_constraint->m_velocity.lengthSquared3();
				hkReal vel1 = p1.m_constraint->m_velocity.lengthSquared3();
				if ( vel0 < vel1 )
				{
					continue;
				}
			}
			hkSimplexSolverActivePlanes h = p0; p0 = p1; p1 = h;
		}
	}
}
static hkBool hkSimplexSolverSolveTest1d( const hkpSurfaceConstraintInfo& sci, const hkVector4& velocityIn )
{
	hkVector4 relativeVelocity; relativeVelocity.setSub4( velocityIn, sci.m_velocity );
	hkReal planeVel = relativeVelocity.dot3( sci.m_plane );
	if ( planeVel >= -0.001f )
	{
		return false;
	}
	return true;
}
static void hkSimplexSolverSolve1d( const hkSimplexSolverInfo& info, const hkpSurfaceConstraintInfo& sci, const hkVector4& velocityIn, hkVector4& velocityOut )
{
	const hkVector4& groundVelocity = sci.m_velocity;
	const hkReal staticFriction = sci.m_staticFriction;
	const hkReal dynamicFriction = sci.m_dynamicFriction;
	hkVector4 relativeVelocity; relativeVelocity.setSub4( velocityIn, groundVelocity );
	hkReal planeVel = relativeVelocity.dot3( sci.m_plane );
	const hkReal origVelocity2 = relativeVelocity.lengthSquared3();
	relativeVelocity.subMul4( planeVel, sci.m_plane );
	{
		const hkReal vp2 = planeVel * planeVel;
		hkReal extraStaticFriction = ( relativeVelocity.dot3( info.m_input->m_upVector ) > 0 ) ? sci.m_extraUpStaticFriction : sci.m_extraDownStaticFriction;
		if ( extraStaticFriction > 0 )
		{
			hkVector4 horizontal; horizontal.setCross( info.m_input->m_upVector, sci.m_plane );
			hkReal hor2 = horizontal.lengthSquared3();
			hkReal horVel = 0.0f;
			if ( hor2 > 1.192092896e-07F )
			{
				horizontal.mul4( hkMath::sqrtInverse( hor2 ) );
				horVel = relativeVelocity.dot3( horizontal );
				hkReal horVel2 = horVel * horVel;
				const hkReal f2 = staticFriction * staticFriction;
				if ( vp2 * f2 >= horVel2 )
				{
					relativeVelocity.subMul4( horVel, horizontal );
					horVel = 0.0f;
				}
			}
			{
				hkReal vertVel2 = origVelocity2 - horVel * horVel - vp2;
				const hkReal f2 = ( staticFriction + extraStaticFriction ) * ( staticFriction + extraStaticFriction );
				if ( vp2 * f2 >= vertVel2 )
				{
					if ( horVel == 0.0f )
					{
						velocityOut = groundVelocity;
						return;
					}
					relativeVelocity.setMul4( horVel, horizontal );
				}
			}
		}
		else
		{
			const hkReal f2 = staticFriction * staticFriction;
			if ( ( 1.0f + f2 ) * vp2 >= origVelocity2 )
			{
				velocityOut = groundVelocity;
				return;
			}
		}
	}
	if ( dynamicFriction < 1.0f )
	{
		hkReal velOut2 = relativeVelocity.lengthSquared3();
		if ( velOut2 >= 1.192092896e-07F )
		{
			if ( origVelocity2 * 0.001f < velOut2 )
			{
				hkReal f = hkMath::sqrt( origVelocity2 / velOut2 );
				f = dynamicFriction + ( 1.0f - dynamicFriction ) * f;
				relativeVelocity.mul4( f );
				hkReal p = sci.m_plane.dot3( relativeVelocity );
				relativeVelocity.subMul4( p, sci.m_plane );
			}
		}
	}
	velocityOut.setAdd4( relativeVelocity, groundVelocity );
}
static void hkSimplexSolverSolve2d( hkSimplexSolverInfo& info, const hkpSurfaceConstraintInfo& sci0, const hkpSurfaceConstraintInfo& sci1, const hkVector4& velocityIn, hkVector4& velocityOut )
{
	hkVector4 axis; axis.setCross( sci0.m_plane, sci1.m_plane );
	hkReal axisLen2 = axis.lengthSquared3();
	if ( axisLen2 <= 1.192092896e-07F )
	{
hkSimplexSolverSolve2dSolveSequentually:
		info.getOutput( &sci0 ).m_status = hkpSurfaceConstraintInteraction::HK_STATUS_2D_FAILURE;
		info.getOutput( &sci1 ).m_status = hkpSurfaceConstraintInteraction::HK_STATUS_2D_FAILURE;
		if ( sci0.m_priority > sci1.m_priority )
		{
			hkSimplexSolverSolve1d( info, sci1, velocityIn, velocityOut );
			hkSimplexSolverSolve1d( info, sci0, velocityOut, velocityOut );
		}
		else
		{
			hkSimplexSolverSolve1d( info, sci0, velocityIn, velocityOut );
			hkSimplexSolverSolve1d( info, sci1, velocityOut, velocityOut );
		}
		return;
	}
	hkReal invAxisLen = hkMath::sqrtInverse( axisLen2 );
	axis.mul4( invAxisLen );
	hkVector4 axisVel;
	{
		hkMatrix3 m;
		hkVector4& r0 = m.getColumn(0);
		hkVector4& r1 = m.getColumn(1);
		hkVector4& r2 = m.getColumn(2);
		r0.setCross( sci0.m_plane, sci1.m_plane );
		r1.setCross( sci1.m_plane, axis );
		r2.setCross( axis, sci0.m_plane );
		hkVector4 sVel; sVel.setAdd4( sci0.m_velocity, sci1.m_velocity );
		hkVector4 t; t.set( 0.5f * axis.dot3( sVel ), sci0.m_plane.dot3( sci0.m_velocity ), sci1.m_plane.dot3( sci1.m_velocity ) );
		axisVel._setMul3( m, t );
		axisVel.mul4( invAxisLen );
		hkVector4 absVel; absVel.setAbs4( axisVel );
		if ( info.m_input->m_maxSurfaceVelocity.compareLessThan4( absVel ).getMask() & hkVector4Comparison::MASK_XYZ )
		{
			goto hkSimplexSolverSolve2dSolveSequentually;
		}
	}
	const hkVector4& groundVelocity = axisVel;
	hkVector4 relativeVelocity; relativeVelocity.setSub4( velocityIn, groundVelocity );
	const hkReal vel2 = relativeVelocity.lengthSquared3();
	const hkReal axisVert = info.m_input->m_upVector.dot3( axis );
	hkReal axisProjVelocity = relativeVelocity.dot3( axis );
	hkReal staticFriction = sci0.m_staticFriction + sci1.m_staticFriction;
	if ( axisVert * axisProjVelocity > 0 )
	{
		staticFriction += ( sci0.m_extraUpStaticFriction + sci1.m_extraUpStaticFriction ) * axisVert;
	}
	else
	{
		staticFriction += ( sci0.m_extraDownStaticFriction + sci1.m_extraDownStaticFriction ) * axisVert;
	}
	staticFriction *= 0.5f;
	const hkReal dynamicFriction = ( sci0.m_dynamicFriction + sci1.m_dynamicFriction ) * 0.5f;
	{
		const hkReal f2 = staticFriction * staticFriction;
		const hkReal av2 = axisProjVelocity * axisProjVelocity;
		if ( ( vel2 - av2 ) * f2 >= av2 )
		{
			velocityOut = groundVelocity;
			return;
		}
	}
	if ( dynamicFriction < 1.0f )
	{
		if ( axisProjVelocity * axisProjVelocity > 0.001f * vel2 )
		{
			hkReal f = hkMath::sqrt( vel2 ) * hkMath::fabs( 1.0f / axisProjVelocity );
			f = dynamicFriction + ( 1.0f - dynamicFriction ) * f;
			axisProjVelocity *= f;
		}
	}
	velocityOut.setAddMul4( groundVelocity, axis, axisProjVelocity );
}
static void hkSimplexSolverSolve3d( hkSimplexSolverInfo& info, const hkpSurfaceConstraintInfo* sci0, const hkpSurfaceConstraintInfo* sci1, const hkpSurfaceConstraintInfo* sci2, int allowResort, const hkVector4& velocityIn, hkVector4& velocityOut )
{
	hkVector4 pointVel;
	{
		hkMatrix3 m;
		hkVector4& r0 = m.getColumn(0);
		hkVector4& r1 = m.getColumn(1);
		hkVector4& r2 = m.getColumn(2);
		r0.setCross( sci1->m_plane, sci2->m_plane );
		r1.setCross( sci2->m_plane, sci0->m_plane );
		r2.setCross( sci0->m_plane, sci1->m_plane );
		hkReal det = r0.dot3( sci0->m_plane );
		if ( hkMath::fabs( det ) < 1.192092896e-07F )
		{
hkSimplexSolverSolve3dSolveSequentually:
			if ( allowResort )
			{
				hkSimplexSolverSortInfo( info );
				sci0 = info.m_supportPlanes[0].m_constraint;
				sci1 = info.m_supportPlanes[1].m_constraint;
				sci2 = info.m_supportPlanes[2].m_constraint;
			}
			info.getOutput( sci0 ).m_status = hkpSurfaceConstraintInteraction::HK_STATUS_3D_FAILURE;
			info.getOutput( sci1 ).m_status = hkpSurfaceConstraintInteraction::HK_STATUS_3D_FAILURE;
			info.getOutput( sci2 ).m_status = hkpSurfaceConstraintInteraction::HK_STATUS_3D_FAILURE;
			int oldNum = info.m_numSupportPlanes;
			hkSimplexSolverSolve2d( info, *sci0, *sci1, velocityIn, velocityOut );
			if ( oldNum == info.m_numSupportPlanes )
			{
				hkSimplexSolverSolve2d( info, *sci0, *sci2, velocityOut, velocityOut );
			}
			if ( oldNum == info.m_numSupportPlanes )
			{
				hkSimplexSolverSolve2d( info, *sci1, *sci2, velocityOut, velocityOut );
			}
			return;
		}
		hkVector4 sVel; sVel.setAdd4( sci0->m_velocity, sci1->m_velocity );
		hkVector4 t; t.set( sci0->m_plane.dot3( sci0->m_velocity ), sci1->m_plane.dot3( sci1->m_velocity ), sci2->m_plane.dot3( sci2->m_velocity ) );
		pointVel._setMul3( m, t );
		pointVel.mul4( 1.0f / det );
		hkVector4 absVel; absVel.setAbs4( pointVel );
		if ( info.m_input->m_maxSurfaceVelocity.compareLessThan4( absVel ).anyIsSet( hkVector4Comparison::MASK_XYZ ) )
		{
			goto hkSimplexSolverSolve3dSolveSequentually;
		}
	}
	velocityOut = pointVel;
}
}
// pdb: hkSimplexSolverExamineActivePlanes | hkpSimplexSolver.obj | tesv_win, call_seq, medium
static inline void FUN_00d23f50( SimplexInfo& simplexInfo )
{
	using namespace hk_009a5680;
	typedef hk_009a5680::hkBool hkBool;
	hkSimplexSolverInfo& info = reinterpret_cast<hkSimplexSolverInfo&>( simplexInfo );
	while ( 1 )
	{
		switch ( info.m_numSupportPlanes )
		{
			case 1:
			{
				const hkpSurfaceConstraintInfo& sci = *info.m_supportPlanes[0].m_constraint;
				hkSimplexSolverSolve1d( info, sci, info.m_input->m_velocity, info.m_output->m_velocity );
				return;
			}
			case 2:
			{
				hkVector4 velocity;
				hkSimplexSolverSolve1d( info, *info.m_supportPlanes[1].m_constraint, info.m_input->m_velocity, velocity );
				hkBool plane0Used = hkSimplexSolverSolveTest1d( *info.m_supportPlanes[0].m_constraint, velocity );
				if ( !plane0Used )
				{
					info.m_output->m_velocity = velocity;
					info.m_supportPlanes[0] = info.m_supportPlanes[1];
					info.m_numSupportPlanes = 1;
				}
				else
				{
					hkSimplexSolverSolve2d( info, *info.m_supportPlanes[0].m_constraint, *info.m_supportPlanes[1].m_constraint, info.m_input->m_velocity, info.m_output->m_velocity );
				}
				return;
			}
			case 3:
			{
				{
					hkVector4 velocity;
					hkSimplexSolverSolve1d( info, *info.m_supportPlanes[2].m_constraint, info.m_input->m_velocity, velocity );
					hkBool plane0Used = hkSimplexSolverSolveTest1d( *info.m_supportPlanes[0].m_constraint, velocity );
					if ( !plane0Used )
					{
						hkBool plane1Used = hkSimplexSolverSolveTest1d( *info.m_supportPlanes[1].m_constraint, velocity );
						if ( !plane1Used )
						{
							info.m_output->m_velocity = velocity;
							info.m_supportPlanes[0] = info.m_supportPlanes[2];
							info.m_numSupportPlanes = 1;
							return;
						}
					}
				}
				{
					for ( int testPlane = 0; testPlane < 2; testPlane++ )
					{
						if ( info.m_numSupportPlanes < 3 )
						{
							break;
						}
						hkVector4 velocity;
						hkSimplexSolverSolve2d( info, *info.m_supportPlanes[testPlane].m_constraint, *info.m_supportPlanes[2].m_constraint, info.m_input->m_velocity, velocity );
						hkBool planeUsed = hkSimplexSolverSolveTest1d( *info.m_supportPlanes[1 - testPlane].m_constraint, velocity );
						if ( !planeUsed )
						{
							info.m_supportPlanes[1 - testPlane] = info.m_supportPlanes[1];
							info.m_supportPlanes[1] = info.m_supportPlanes[2];
							info.m_numSupportPlanes = 2;
							break;
						}
					}
					if ( info.m_numSupportPlanes < 3 )
					{
						continue;
					}
				}
				hkSimplexSolverSolve3d( info, info.m_supportPlanes[0].m_constraint, info.m_supportPlanes[1].m_constraint, info.m_supportPlanes[2].m_constraint, true, info.m_input->m_velocity, info.m_output->m_velocity );
				return;
			}
			case 4:
			{
				hkSimplexSolverSortInfo( info );
				int i;
				for ( i = 0; i < 3; i++ )
				{
					hkVector4 velocity;
					hkSimplexSolverSolve3d( info, info.m_supportPlanes[(i + 1) % 3].m_constraint, info.m_supportPlanes[(i + 2) % 3].m_constraint, info.m_supportPlanes[3].m_constraint, false, info.m_input->m_velocity, velocity );
					hkBool planeUsed = hkSimplexSolverSolveTest1d( *info.m_supportPlanes[i].m_constraint, velocity );
					if ( !planeUsed )
					{
						info.m_supportPlanes[i] = info.m_supportPlanes[2];
						info.m_supportPlanes[2] = info.m_supportPlanes[3];
						info.m_numSupportPlanes = 3;
						i = 10;
					}
				}
				if ( i >= 10 ) continue;
				{
					hkVector4 velocity = info.m_input->m_velocity;
					const hkpSurfaceConstraintInfo* sci0 = info.m_supportPlanes[0].m_constraint;
					const hkpSurfaceConstraintInfo* sci1 = info.m_supportPlanes[1].m_constraint;
					const hkpSurfaceConstraintInfo* sci2 = info.m_supportPlanes[2].m_constraint;
					const hkpSurfaceConstraintInfo* sci3 = info.m_supportPlanes[3].m_constraint;
					int oldNum = info.m_numSupportPlanes;
					if ( oldNum == info.m_numSupportPlanes ) hkSimplexSolverSolve3d( info, sci0, sci1, sci2, false, velocity, velocity );
					if ( oldNum == info.m_numSupportPlanes ) hkSimplexSolverSolve3d( info, sci0, sci1, sci3, false, velocity, velocity );
					if ( oldNum == info.m_numSupportPlanes ) hkSimplexSolverSolve3d( info, sci0, sci2, sci3, false, velocity, velocity );
					if ( oldNum == info.m_numSupportPlanes ) hkSimplexSolverSolve3d( info, sci1, sci2, sci3, false, velocity, velocity );
					info.m_output->m_velocity = velocity;
				}
				{
					int maxStatus = hkpSurfaceConstraintInteraction::HK_STATUS_OK;
					for ( int j = 0; j < 4; j++ )
					{
						maxStatus = hkMath::max2( maxStatus, int( info.m_supportPlanes[j].m_interaction->m_status ) );
					}
					int k;
					for ( k = 0; k < 4; k++ )
					{
						if ( maxStatus == info.m_supportPlanes[k].m_interaction->m_status )
						{
							info.m_supportPlanes[k] = info.m_supportPlanes[3];
							break;
						}
					}
					info.m_numSupportPlanes--;
					for ( int l = 0; l < 3; l++ )
					{
						info.m_supportPlanes[l].m_interaction->m_status = hkpSurfaceConstraintInteraction::HK_STATUS_OK;
					}
				}
				return;
			}
			default:
				return;
		}
	}
}
void runSimplexAnchor_009a5680()
{
	FUN_00d23f50(*reinterpret_cast<SimplexInfo*>(g_simplexAnchor_009a5680));
}


SimplexInfo* volatile g_simplexInfo;
void invokeExamineActivePlanes()
{
    FUN_00d23f50(*g_simplexInfo);
}
