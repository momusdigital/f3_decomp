// staging/blk_00e20000_od_o2_nood_variant.cpp: Face, Hull (1 function)
#include <windows.h>
#include "f3_common.h"
// src/staging/blk_00e20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

typedef union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; } __m128;
extern "C" {
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_mul_ss(__m128,__m128);
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_sub_ss(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,int);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_cmpeq_ss(__m128,__m128);
__m128 _mm_andnot_ps(__m128,__m128);
void _ReadWriteBarrier();
}
struct Vertex { __m128 position; __m128 supportA; __m128 supportB; int flags; int unk34; int unk38; int unk3c; };
struct Face;
struct Edge {
    Vertex* vertex;
    Edge* next;
    Edge* opposite;
    Face* face;
};
struct Face {
    __m128 normal;
    Edge edges[3];
    float distance;
    int flags;
    int unk48;
    int unk4c;
    __declspec(noinline) Vertex* ComputePlane();
};
struct InitEntry { int vertexOffset; int faceOffset; int edgeOffset; };
struct Hull {
    int unk00; int unk04; int unk08; int unk0c;
    int faceCount; int unk14; int unk18; int unk1c;
    Vertex vertices[55];
    Face* freeFaces[100];
    Face faces[4];
    void FUN_00e2d440();
};
// @f3 0x00a994b0 (community match, verified in this file)
struct FaceCall {
    void FUN_00a98f70();
};

struct __declspec(align(16)) Delta48 {
    float x, y, z, w;
    Delta48(const __m128& a, const __m128& b) {
        x = a.m128_f32[0] - b.m128_f32[0];
        y = a.m128_f32[1] - b.m128_f32[1];
        z = a.m128_f32[2] - b.m128_f32[2];
    }
    __forceinline float Dot(const __m128& n) const {
        return n.m128_f32[0] * x + n.m128_f32[1] * y + n.m128_f32[2] * z;
    }
};

// pdb: hkpWingedEdge::addTetrahedron | hkpWingedEdge.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkWingedEdge::addTetrahedron)
void Hull::FUN_00e2d440() {
    faceCount = 4;
    const InitEntry* init = (const InitEntry*)0x00e88e68;
    Face* end = faces + 4;
    for (Face* face = faces; face != end; ++face) {
        face->edges[0].next = &face->edges[1];
        face->edges[1].next = &face->edges[2];
        face->flags = 0;
        face->edges[2].next = &face->edges[0];
        for (Edge* edge = face->edges; edge < face->edges + 3; ++edge) {
            edge->face = face;
            edge->vertex = (Vertex*)((char*)vertices + init->vertexOffset);
            edge->opposite = (Edge*)((char*)&faces[0].edges[0] + init->faceOffset + init->edgeOffset);
            ++init;
        }
    }
    Face* firstFace = faces;
    Face* last = &faces[3];
    ((FaceCall*)last)->FUN_00a98f70();
    Delta48 delta(vertices[0].position, vertices[1].position);
    float d = delta.Dot(last->normal);
    if (d > 0.0f) {
        faces[2].edges[0].vertex = &vertices[1];
        faces[1].edges[0].vertex = &vertices[1];
        firstFace->edges[0].vertex = &vertices[1];
        last->edges[0].vertex = &vertices[0];
        faces[1].edges[1].vertex = &vertices[0];
        firstFace->edges[2].vertex = &vertices[0];
    }
    Face* face = firstFace;
    int i = 3;
    do { ((FaceCall*)face)->FUN_00a98f70(); ++face; } while (--i >= 0);
}


namespace fnv_00e2ab00 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; } __m128;
extern "C" { __m128 _mm_load_ps(const __m128*); void _mm_store_ps(__m128*,__m128); __m128 _mm_shuffle_ps(__m128,__m128,int); void _ReadWriteBarrier(); }

}  // namespace fnv_00e2ab00

inline void* operator new(unsigned int, void* p) { return p; }

struct Router_e3a1 {
    int unk00, unk04, unk08, unk0C;
    void* m_pStreamAllocator;
};
Router_e3a1* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement);

struct __declspec(align(16)) Key_e3a1 {
    float m_ax, m_ay, m_az, m_aw;
    float m_bx, m_by, m_bz, m_bw;
    Key_e3a1* FUN_00e39e50();
};

template <class T> struct hkArray_e3a1 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        Router_e3a1* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
};

extern "C" void _mm_store_ps(float*, __m128);

extern int DAT_010dbacc, DAT_010dbad8, DAT_010dbae4, DAT_010dbaf8;
extern int DAT_010ccfac, DAT_010ccfa0, DAT_010ccf8c, DAT_010c3bb8;
typedef __m128 FourFloatVector;
__forceinline FourFloatVector packFractions(float x,float y,float z,float w) { FourFloatVector v; v.m128_f32[0]=x; v.m128_f32[1]=y; v.m128_f32[2]=z; v.m128_f32[3]=w; return v; }
struct RaySource {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
};
struct LocalRay {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
    void* userFilter;
    int one; void* zero;
    unsigned char hit, flag; unsigned short unk3e;
    __forceinline void assign(const RaySource& s) { from=s.from; to=s.to; enable=s.enable; filter=s.filter; }
};
struct RayCollectorBase {
    void* vtable;
    int mode;
    float fraction;
    unsigned char hit; unsigned char unk0d; unsigned short unk0e;
};
struct Collector {
    void* vt0; void* vt1; void* vt2;
    RayCollectorBase ray;
    LocalRay* input; LocalRay* input2;
    void* filter; void* filter2;
    unsigned unk2c;
    FourFloatVector normal;
    FourFloatVector point;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    __forceinline LocalRay* setup(LocalRay* r, const RaySource& source, void* f, int m, unsigned char flag) {
        r->userFilter=f; filter=f; filter2=f;
        r->from=source.from; r->to=source.to;
        r->enable=source.enable; r->filter=source.filter;
        r->flag=flag; r->one=1; r->zero=0;
        input2=r; input=r;
ray.mode=m;         return r;
    }
    __forceinline void init() {
        ray.fraction = 1.0f; vt0 = &DAT_010dbaf8; vt1 = &DAT_010dbae4; vt2 = &DAT_010dbad8; ray.vtable = &DAT_010dbacc;
        unk50 = 0; unk54 = 0; unk60 = 0; ray.hit = 0;
    }
};

extern "C" void _ReadWriteBarrier(void);

template <class T> struct ScrapArr
{
    T* m_pData;
    int m_uiLogicalSize;
    unsigned int m_uiCap;
};

class JobTarget
{
public:
    void FUN_00d04380();
};

struct __declspec(align(16)) AutoJob
{
    unsigned char m_cType;
    unsigned char m_c01;
    unsigned char m_c02;
    unsigned char m_c03;
    unsigned short m_sSize;
    short m_s06;
    int unk08;
    int unk0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int unk1C;
    int* m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    float m_f38;
    float m_f3C;
    int m_i40;
    int m_i44;
    int unk48;
    int m_i4C;
    int unk50;
    int m_i54;
    int m_i58;
    JobTarget* m_p5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
};

namespace SplineMax {
}

namespace S31470_Intrinsics {
extern "C" ::__m128 (_mm_min_ps)(::__m128, ::__m128);
}

struct MinVec4 {
    __m128 m_vComponents;
    void setMin4(const MinVec4& a, const MinVec4& b) { m_vComponents = (S31470_Intrinsics::_mm_min_ps)(a.m_vComponents, b.m_vComponents); }
};
