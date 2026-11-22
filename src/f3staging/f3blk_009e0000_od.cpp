// src/f3staging/f3blk_009e0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009e1ed0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
namespace f3m_009e1ed0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

struct Mon { unsigned int m_unk00; unsigned int* m_kRayEnd; unsigned int m_unk08; unsigned int* m_capMinus16; };
struct Ctx { unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c; unsigned int slots[8]; int depth; };
struct Box { unsigned int unk00, unk04, unk08, unk0c; float f10, f14, f18, f1c; unsigned int u20, u24, u28; };
struct __declspec(align(16)) VM {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int m_z0, m_z1;
    unsigned int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    void FUN_00a542a0(char* a, char* b, void* c, unsigned int d, Ctx* e);
};
struct Frame { unsigned int m_codeStorage[0x10]; VM m_vm; };
struct FUN_009e1ed0_cls {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float unk20, unk24, unk28, unk2c; char* unk30; char* unk34;
    char* FUN_009e1ed0(char* flag, unsigned int arg2, Ctx* ctx);
};

// pdb: hkpMoppBvTreeShape::castRayImpl | hkpMoppBvTreeShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: input, results
char* FUN_009e1ed0_cls::FUN_009e1ed0(char* flag, unsigned int arg2, Ctx* ctx)
{
    Frame frame;
    Mon* mon = (Mon*)TlsGetValue(DAT_0116913c);
    char* pos = (char*)mon->m_kRayEnd;
    if (pos < (char*)mon->m_capMinus16) {
        *(const char**)pos = "TtrcMopp";
        _ReadWriteBarrier();
        volatile unsigned int ticks;
        ticks = (unsigned int)__rdtsc();
        *(unsigned int*)(pos + 4) = ticks;
        mon->m_kRayEnd = (unsigned int*)(pos + 12);
    }
    ++ctx->depth;
    unsigned int size = this->unk18;
    unsigned int kA = this->unk14;
    Box& box = *(Box*)(((unsigned int)&frame.m_codeStorage[0] + 15) & ~15u);
    box.f10 = this->unk20;
    frame.m_vm.m_z0 = 0;
    frame.m_vm.m_z1 = 0;
    box.f14 = this->unk24;
    box.f18 = this->unk28;
    _ReadWriteBarrier();
    box.f1c = this->unk2c;
    box.u20 = kA;
    box.u24 = size;
    box.u28 = size;
    frame.m_vm.FUN_00a542a0(flag, this->unk34 ? this->unk34 + 0x10 : 0, &box, arg2, ctx);
    --ctx->depth;
    if (*flag != 0)
        ctx->slots[ctx->depth] = 0;
    Mon* mon2 = (Mon*)TlsGetValue(DAT_0116913c);
    char* pos2 = (char*)mon2->m_kRayEnd;
    if (pos2 < (char*)mon2->m_capMinus16) {
        *(const char**)pos2 = "Et";
        _ReadWriteBarrier();
        volatile unsigned int ticks;
        ticks = (unsigned int)__rdtsc();
        *(unsigned int*)(pos2 + 4) = ticks;
        mon2->m_kRayEnd = (unsigned int*)(pos2 + 12);
    }
    return flag;
}
}   // namespace f3m_009e1ed0

// @f3 0x009e0430 (community match, verified in this file)
namespace f3m_009e0430 {
namespace n9e0430 {
void __cdecl FUN_00901f10(void* a, int elemSize);
struct __declspec(align(16)) hkVector4 {
    float x, y, z, w;
    hkVector4() {}
    hkVector4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void operator=(const hkVector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
};
struct IntArray {
    int* m_data;
    int m_size;
    int m_capacityAndFlags;
    void pushBack(const int& v)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        m_data[m_size] = v;
        m_size++;
    }
};
struct VecArray {
    hkVector4* m_data;
    int m_size;
    int m_capacityAndFlags;
    void pushBack(const hkVector4& v)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 0x10);
        m_data[m_size++] = v;
    }
};
struct Writer {
    int unk00;
    int bytes;
    int ops_count;
    int words;
    VecArray consts;
    IntArray ops;
};
struct Obj {
    int unk00;
    Writer* w;
    int FUN_009e0430(unsigned char reg, float value);
};
// pdb: hkpConstraintConstructionKit::setLinearFriction | hkpConstraintConstructionKit.obj | tesv_win, objrun_open, low
int Obj::FUN_009e0430(unsigned char reg, float value)
{
    w->ops.pushBack(0x15);
    int r = reg;
    w->ops.pushBack(r);
    int index = w->consts.m_size;
    w->consts.pushBack(hkVector4(value, 0.0f, 0.0f, 0.0f));
    Writer* wr = w;
    wr->bytes += 0x40;
    wr->ops_count += 1;
    wr->words += 2;
    return index;
}
}
}   // namespace f3m_009e0430

// @f3 0x009f85c0 (community match, verified in this file)
extern unsigned char DAT_00e817d9[];
extern unsigned char DAT_00e817da[];
namespace f3m_009f85c0 {
namespace f3m_009f85c0 {

struct Vec4 {
    float x, y, z, w;
};

struct __declspec(align(16)) Planes {
    Vec4 a;
    Vec4 b;
    Vec4 c;
};

struct Info {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char type;
};


void __cdecl FUN_00a4e410(Planes* planes, int arg1, int arg3);

inline void Copy(Vec4& d, const Vec4& s) { d.x = s.x; d.y = s.y; d.z = s.z; d.w = s.w; }
inline void CopyNeg(Vec4& d, const Vec4& s) { d.x = -s.x; d.y = -s.y; d.z = -s.z; d.w = -s.w; }
inline const Vec4& At(const char* base, unsigned int off) { return *(const Vec4*)(base + off); }

// pdb: buildJacobianFrom2dAngAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objopen_prop, low
static __declspec(noinline) void FUN_009f85c0(const Info* info, const char* base, int arg1, const Vec4* sources, int arg3)
{
    unsigned int idx = info->type;
    unsigned int neg = DAT_00e817d9[idx];
    unsigned int pos = DAT_00e817da[idx];
    Planes planes;
    Copy(planes.a, sources[idx]);
    Copy(planes.c, At(base, neg));
    Copy(planes.b, At(base, pos));
    FUN_00a4e410(&planes, arg1, arg3);
    Copy(planes.c, At(base, pos));
    CopyNeg(planes.b, At(base, neg));
    FUN_00a4e410(&planes, arg1, arg3);
}

const Info* volatile g_info;
const char* volatile g_base;
volatile int g_arg1;
const Vec4* volatile g_sources;
volatile int g_arg3;

void Caller_009f85c0()
{
    FUN_009f85c0(g_info, g_base, g_arg1, g_sources, g_arg3);
}
}
}   // namespace f3m_009f85c0

// @f3 0x009f9e20 (community match, verified in this file)
namespace f3m_009f9e20 {
namespace f3m_009f9e20 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Info {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char index;
    unsigned char unk03;
    float a;
    float b;
};
struct Frame {
    Vec4 entries[3];
    Vec4 base;
};
struct Block {
    Vec4 first;
    Vec4 second;
    Vec4 third;
    float a;
    float b;
};
void __cdecl FUN_00a4fb30(Block* block, int p1, int p2);
// pdb: buildJacobianFromLinLimitAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_009f9e20(Info* info, Frame* self, Frame* other, int p1, int p2)
{
    Block block;
    block.first = other->base;
    block.second = self->base;
    block.a = info->a;
    block.b = info->b;
    block.third = self->entries[info->index];
    FUN_00a4fb30(&block, p1, p2);
}
void Caller(Frame* o, Frame* s, Info* i, int p1, int p2) { FUN_009f9e20(i, s, o, p1, p2); }
}
}   // namespace f3m_009f9e20

// @f3 0x009f0d00 (community match, verified in this file)
namespace S009f0d00_ns {

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
void __cdecl FUN_00901f10(void* arr, int elemSize);

struct S009f0d00_ThreadMemory {
    void FUN_008f6d90(void* p, int nbytes, int cls);
};

}

extern unsigned long DAT_010f3170;

namespace S009f0d00_ns {


template <class T>
struct S009f0d00_Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    void pushBack(const T& v)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = v;
        m_size++;
    }
    void removeAt(int i)
    {
        m_size--;
        m_data[i] = m_data[m_size];
    }
};

struct S009f0d00_Rotation;

struct __declspec(align(16)) S009f0d00_Vector4 {
    float x, y, z, w;
    __forceinline void setRotatedDir(const S009f0d00_Rotation& a, const S009f0d00_Vector4& b);
    __forceinline void setSub4(const S009f0d00_Vector4& a, const S009f0d00_Vector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
};

struct S009f0d00_Rotation {
    S009f0d00_Vector4 c0, c1, c2;
    __forceinline float operator()(int r, int c) const { return (&(&c0)[c].x)[r]; }
    void hkRotation_set(const S009f0d00_Vector4* q);
};

__forceinline void S009f0d00_Vector4::setRotatedDir(const S009f0d00_Rotation& a, const S009f0d00_Vector4& b)
{
    const float v0 = b.x;
    const float v1 = b.y;
    const float v2 = b.z;
    x = a(0, 0) * v0 + a(0, 1) * v1 + a(0, 2) * v2;
    y = a(1, 0) * v0 + a(1, 1) * v1 + a(1, 2) * v2;
    z = a(2, 0) * v0 + a(2, 1) * v1 + a(2, 2) * v2;
    w = 0.0;
}

struct S009f0d00_Transform {
    S009f0d00_Rotation rot;
    S009f0d00_Vector4 trans;
};

struct S009f0d00_SweptTransform {
    S009f0d00_Vector4 m_centerOfMass0;
    S009f0d00_Vector4 m_centerOfMass1;
    S009f0d00_Vector4 m_rotation0;
    S009f0d00_Vector4 m_rotation1;
    S009f0d00_Vector4 m_centerOfMassLocal;
};

__forceinline void S009f0d00_calcTransAtT0(const S009f0d00_SweptTransform& sweptTrans, S009f0d00_Transform& transformOut)
{
    const S009f0d00_Vector4& q0 = sweptTrans.m_rotation0;
    transformOut.rot.hkRotation_set(&q0);
    S009f0d00_Vector4 centerShift;
    centerShift.setRotatedDir(transformOut.rot, sweptTrans.m_centerOfMassLocal);
    transformOut.trans.setSub4(sweptTrans.m_centerOfMass0, centerShift);
}

__forceinline void S009f0d00_calcTransAtT1(const S009f0d00_SweptTransform& sweptTrans, S009f0d00_Transform& transformOut)
{
    const S009f0d00_Vector4& q1 = sweptTrans.m_rotation1;
    transformOut.rot.hkRotation_set(&q1);
    S009f0d00_Vector4 centerShift;
    centerShift.setRotatedDir(transformOut.rot, sweptTrans.m_centerOfMassLocal);
    transformOut.trans.setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

struct S009f0d00_DisplayGeometry {
    virtual ~S009f0d00_DisplayGeometry();
    int unk04;
    void* m_geometry;
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
    int m_type;
};

struct S009f0d00_Entity {
    int unk00;
    int unk04;
    void* m_world;
    int unk0c;
    void* m_shape;
    char unk14;
};

struct S009f0d00_Collidable {
    void* m_shape;
};

struct S009f0d00_WorldData {
    void* m_world;
    S009f0d00_Array<unsigned long> m_entitiesCreated;
};

struct S009f0d00_DisplayHandler {
    virtual void unk00();
    virtual void addGeometry(S009f0d00_Array<S009f0d00_DisplayGeometry*>& geoms, const S009f0d00_Transform& t, unsigned long id, int tag, int style);
    virtual void unk08();
    virtual void setGeometryColor(int color, unsigned long id, int tag);
};

struct S009f0d00_Error {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void message(int type, int id, const char* desc, const char* file, int line);
};

struct S009f0d00_Ostream {
    int unk00;
    int unk04;
    int unk08;
    S009f0d00_Ostream& FUN_00943710(const char* s);
    void FUN_00923070(void* buf, int size);
    void FUN_00943a60();
};

struct S009f0d00_BuilderEnv {
    int unk00;
    int unk04;
    void FUN_00a655a0();
};

struct S009f0d00_Builder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00a655b0(S009f0d00_BuilderEnv* env);
    void FUN_00a66d50(void* shape, S009f0d00_Array<S009f0d00_DisplayGeometry*>* out);
};

struct S009f0d00_ViewerBase {
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S009f0d00_DisplayHandler* m_displayHandler;
    int unk1c;
    int unk20;
    int unk24;
};

struct S009f0d00_EntityListener {
    virtual void FUN_009f0d00(char* entity);
};

struct S009f0d00_Viewer : S009f0d00_ViewerBase, S009f0d00_EntityListener {
    int unk2c;
    S009f0d00_WorldData** m_worldEntities;
    int m_worldEntitiesSize;
    int FUN_009f0940(void* world);
    void FUN_009f0d00(char* entity);
};

}

extern S009f0d00_ns::S009f0d00_Error* DAT_010f3364;
extern int DAT_011697ec;
extern int DAT_011697f0;
extern int DAT_011697f4;

namespace S009f0d00_ns {

// pdb: hkpSweptTransformDisplayViewer::entityAddedCallback | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: entity
void S009f0d00_Viewer::FUN_009f0d00(char* entity)
{
    if (*(void**)(entity + 0x10) == 0)
        return;
    int index = FUN_009f0940(*(void**)(entity + 8));
    if (index < 0)
        return;
    S009f0d00_WorldData* data = m_worldEntities[index];
    S009f0d00_Array<S009f0d00_DisplayGeometry*> displayGeometries;
    displayGeometries.m_data = 0;
    displayGeometries.m_size = 0;
    displayGeometries.m_capacityAndFlags = 0x80000000;
    {
        S009f0d00_BuilderEnv env;
        env.FUN_00a655a0();
        S009f0d00_Builder shapeBuilder;
        shapeBuilder.FUN_00a655b0(&env);
        shapeBuilder.FUN_00a66d50(*(void**)(entity + 0x10), &displayGeometries);

        for (int i = displayGeometries.m_size - 1; i >= 0; i--) {
            if (displayGeometries.m_data[i]->m_type == 6 && displayGeometries.m_data[i]->m_geometry == 0) {
                char reportBuf[512];
                S009f0d00_Ostream reportStream;
                reportStream.FUN_00923070(reportBuf, sizeof(reportBuf));
                reportStream.FUN_00943710("Unable to build display geometry from hkpShape geometry data");
                DAT_010f3364->message(0, -1, reportBuf, ".\\VisualDebugger\\Viewer\\Dynamics\\hkpSweptTransformDisplayViewer.cpp", 168);
                reportStream.FUN_00943a60();
                displayGeometries.removeAt(i);
            }
        }
    }

    if (displayGeometries.m_size > 0 && *(unsigned char*)(entity + 0xd8) != 7) {
        unsigned long id = (unsigned long)(entity + 0x10) + 1;
        data->m_entitiesCreated.pushBack(id);
        const S009f0d00_SweptTransform& swept = *(const S009f0d00_SweptTransform*)(entity + 0x120);
        S009f0d00_Transform t0;
        S009f0d00_calcTransAtT0(swept, t0);
        S009f0d00_Transform t1;
        S009f0d00_calcTransAtT1(swept, t1);
        m_displayHandler->addGeometry(displayGeometries, t0, id, DAT_011697ec, 0);
        m_displayHandler->setGeometryColor(DAT_011697f4, id, DAT_011697ec);
        unsigned long id2 = (unsigned long)(entity + 0x10) + 2;
        data->m_entitiesCreated.pushBack(id2);
        m_displayHandler->addGeometry(displayGeometries, t1, id2, DAT_011697ec, 0);
        m_displayHandler->setGeometryColor(DAT_011697f0, id2, DAT_011697ec);
    }

    for (int j = 0; j < displayGeometries.m_size; j++)
        delete displayGeometries.m_data[j];

    if ((displayGeometries.m_capacityAndFlags & 0x80000000) == 0)
    {
        int n = displayGeometries.m_capacityAndFlags & 0x3fffffff;
        S009f0d00_ThreadMemory* mem = (S009f0d00_ThreadMemory*)FUN_00d9b080(DAT_010f3170);
        mem->FUN_008f6d90(displayGeometries.m_data, n * sizeof(S009f0d00_DisplayGeometry*), 0x17);
    }
}

}

// @f3 0x009e5870 (community match, verified in this file)
#include <math.h>
extern float DAT_01062ec4;
namespace f3m_009e5870 {
namespace f3m_009e5870 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(const hkReal r) { return ::sqrtf(r); }
}

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline void setMul4(hkReal r, const hkVector4& v)
    {
        m_quad[0] = r * v.m_quad[0];
        m_quad[1] = r * v.m_quad[1];
        m_quad[2] = r * v.m_quad[2];
        m_quad[3] = r * v.m_quad[3];
    }
    __forceinline void mul4(hkReal r)
    {
        m_quad[0] *= r;
        m_quad[1] *= r;
        m_quad[2] *= r;
        m_quad[3] *= r;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] + b.m_quad[0];
        m_quad[1] = a.m_quad[1] + b.m_quad[1];
        m_quad[2] = a.m_quad[2] + b.m_quad[2];
        m_quad[3] = a.m_quad[3] + b.m_quad[3];
    }
    __forceinline void setInt24W(int value)
    {
        reinterpret_cast<int*>(m_quad)[3] = value | 0x3f000000;
    }
};

class hkpCylinderShape
{
public:
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkReal m_cylRadius;
    int unk18;
    int unk1c;
    hkVector4 m_vertices[2];
    hkVector4 m_perpendicular1;
    hkVector4 m_perpendicular2;

    __forceinline const hkVector4& getVertex(int i) const { return m_vertices[i]; }
    void FUN_009e5870(const unsigned short* ids, int numIds, hkVector4* verticesOut) const;
};

// pdb: hkpCylinderShape::convertVertexIdsToVerticesImpl | hkpCylinderShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: ids, numIds, verticesOut
void hkpCylinderShape::FUN_009e5870(const unsigned short* ids, int numIds, hkVector4* verticesOut) const
{
    int i = numIds - 1;
    if (i >= 0) do {
        unsigned int id = ids[0]; int baseIndex = (id >> 7) & 1; int sign0 = (id >> 6) & 1; int sign1 = (id >> 5) & 1;
        hkReal f = hkReal((ids[0] & 0xf) + 0.5f) * DAT_01062ec4;
        hkReal c = hkMath::sqrt(1.0f - f * f);

        hkReal a, b;
        if (ids[0] & 0x10)
        {
            a = f;
            b = c;
        }
        else
        {
            b = f;
            a = c;
        }
        if (!sign0) a = -a;
        if (!sign1) b = -b;

        hkVector4 vec1; vec1.setMul4(b, m_perpendicular1);
        hkVector4 vec2; vec2.setMul4(a, m_perpendicular2);
        hkVector4 vec3; vec3.setAdd4(vec2, vec1);
        vec3.mul4(m_cylRadius);
        verticesOut[0].setAdd4(getVertex(1 - baseIndex), vec3);
        verticesOut[0].setInt24W(id);
        i--; ids++;
        verticesOut++;
    } while (i >= 0);
}

}
}   // namespace f3m_009e5870

// @f3 0x009ed620 (community match, verified in this file)
namespace f3m_009ed620 {
namespace f3m_009ed620 {

struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline hkVector4() {}
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};

struct hkTransform
{
    hkVector4 c0, c1, c2, c3;
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t) : c0(t.c0), c1(t.c1), c2(t.c2), c3(t.c3) {}
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    float v0 = b.x;
    float v1 = b.y;
    float v2 = b.z;
    x = t.c0.x * v0 + t.c1.x * v1 + t.c2.x * v2 + t.c3.x;
    y = t.c0.y * v0 + t.c1.y * v1 + t.c2.y * v2 + t.c3.y;
    z = t.c0.z * v0 + t.c1.z * v1 + t.c2.z * v2 + t.c3.z;
    w = 0.0f;
}

static __forceinline void xformPos(hkVector4& o, const hkVector4& c0, const hkVector4& c1, const hkVector4& c2, const hkVector4& c3, const hkVector4& b)
{
 const float* p0 = &c0.x; const float* p1 = &c1.x; const float* p2 = &c2.x; const float* p3 = &c3.x;
 const float v0 = b.x; const float v1 = b.y; const float v2 = b.z;
 o.x = p0[0] * v0 + p1[0] * v1 + p2[0] * v2 + p3[0];
 o.y = c0.y * v0 + c1.y * v1 + p2[1] * v2 + p3[1];
 o.z = p0[2] * v0 + p1[2] * v1 + p2[2] * v2 + p3[2];
 o.w = 0.0f;
}
static __forceinline void transformSpheres(const hkTransform& t, const hkVector4* in, int num, hkVector4* out)
{
    const hkVector4 c0 = t.c0;
    const hkVector4 c1 = t.c1;
    const hkVector4 c2 = t.c2;
    const hkVector4 c3 = t.c3;
    int i = num - 1;
    do
    {
        hkVector4 v;
        xformPos(v, c0, c1, c2, c3, in[i]);
        v.w = in[i].w;
        out[i] = v;
    } while (--i >= 0);
}

class hkpShape
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void convertVertexIdsToVertices(const unsigned short* ids, int numIds, hkVector4* verticesOut) const;
};

class hkpTransformShape
{
public:
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_childShapeVtbl;
    const hkpShape* m_childShape;
    int unk1c;
    hkTransform m_transform;

    void FUN_009ed620(const unsigned short* ids, int numIds, hkVector4* verticesOut) const;
};

void hkpTransformShape::FUN_009ed620(const unsigned short* ids, int numIds, hkVector4* verticesOut) const
{
    m_childShape->convertVertexIdsToVertices(ids, numIds, verticesOut);
    transformSpheres(m_transform, verticesOut, numIds, verticesOut);
}

}
}   // namespace f3m_009ed620

// @f3 0x009e3e00 (community match, verified in this file)
#include <stddef.h>
extern float DAT_00f7ad9c;
extern int DAT_00e35ff4;
namespace f3m_009e3e00 {

struct __declspec(align(16)) EmsVector4
{
    float x;
    float y;
    float z;
    float w;

    void operator=(const EmsVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void setZero4() { x = y = z = w = 0.0f; }
    void load3(const float* p)
    {
        x = p[0];
        y = p[1];
        z = p[2];
    }
    void mul4(const EmsVector4& v)
    {
        x *= v.x; y *= v.y; z *= v.z; w *= v.w;
    }
    float lengthSquared3() const { return x * x + y * y + z * z; }
};

struct EmsReferencedObject
{
    virtual ~EmsReferencedObject();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;

    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            --m_referenceCount;
            if (m_referenceCount == 0)
                delete this;
        }
    }
};

struct EmsShape : EmsReferencedObject
{
    unsigned int m_userData;
    int m_type;
};


struct EmsTriangleShape
{
    int m_vtable;
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    unsigned int m_userData;
    int m_type;
    float m_radius;
    unsigned short m_weldingInfo;
    char m_weldingType;
    char m_isExtruded;
    int m_pad18;
    int m_pad1c;
    EmsVector4 m_vertices[3];
    EmsVector4 m_extrusion;

    void* operator new(size_t, void* p) throw() { return p; }
    EmsTriangleShape(float radius = DAT_00f7ad9c, unsigned short weldingInfo = 0, char weldingType = 6)
    {
        m_referenceCount = 1;
        m_userData = 0;
        m_type = 4;
        m_radius = radius;
        m_vtable = (int)&DAT_00e35ff4;
        m_weldingInfo = weldingInfo;
        m_weldingType = weldingType;
        m_extrusion.setZero4();
        m_isExtruded = 0;
    }
};

struct EmsTrianglesSubpart
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    const char* m_vertexBase;  // 14
    int m_vertexStriding;      // 18
    int m_numVertices;         // 1c
    EmsVector4 m_extrusion;    // 20
    const char* m_indexBase;   // 30
    int m_indexStriding;       // 34
    char m_stridingType;       // 38
    char m_flipAlternateTriangles;  // 39
    short m_pad3a;
    int m_triangleOffset;      // 3c
};

struct EmsShapesSubpart
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    EmsShape** m_childShapes;  // 10
    int m_numChildShapes;      // 14
    char m_hasTranslation;     // 18
    char m_hasRotation;        // 19
    short m_pad1a;
    int m_unk1c;
    EmsVector4 m_rotation;     // 20
    EmsVector4 m_translation;  // 30
};

void __cdecl FUN_009e5170(int* dst, const int* src);

struct CB2FC0Object
{
    void hkRotation_set(void* q);
};

struct EmsTransform
{
    EmsVector4 m_rotation[3];
    EmsVector4 m_translation;

    EmsTransform(const EmsVector4& q, const EmsVector4& t) : m_translation(t)
    {
        ((CB2FC0Object*)this)->hkRotation_set((void*)&q);
    }
};

struct EmsConvexTranslateShape
{
    void* operator new(size_t, void* p) throw() { return p; }
    EmsConvexTranslateShape(const EmsShape* child, const EmsVector4& translation);
};

struct EmsTransformShape
{
    void* operator new(size_t, void* p) throw() { return p; }
    EmsTransformShape(const EmsShape* child, const EmsTransform& transform);
};

struct ExtendedMeshShape
{
    int m_vtable;
    int m_unk04;
    int m_numBitsForSubpartIndex;  // 08
    int m_unk0c;
    EmsVector4 m_scaling;          // 10
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    EmsTrianglesSubpart* m_trianglesSubparts;  // 40
    int m_numTrianglesSubparts;                // 44
    EmsShapesSubpart* m_shapesSubparts;        // 48
    int m_numShapesSubparts;                   // 4c
    const unsigned short* m_weldingInfo;       // 50
    int m_numWeldingInfo;                      // 54
    int m_unk58;
    char m_weldingType;                        // 5c
    EmsTrianglesSubpart m_embeddedTrianglesSubpart;  // 60
    float m_triangleRadius;                    // a0

    const EmsShape* FUN_009e3e00(unsigned int key, void* buffer) const;
};

static __forceinline void EmsMemCpy16(void* dst, const void* src, int numQuads)
{
    const int* s = (const int*)src;
    int* d = (int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        s += 4;
        d += 4;
    } while (--numQuads > 0);
}

static __forceinline void EmsGetIndices(const EmsTrianglesSubpart* part, unsigned int terminalIndex, int* indices)
{
    const char* tri = part->m_indexBase + part->m_indexStriding * terminalIndex;
    int flip = part->m_flipAlternateTriangles & terminalIndex;
    if (part->m_stridingType == 1)
    {
        const unsigned short* t = (const unsigned short*)tri;
        indices[0] = t[0];
        indices[1] = t[(short)(flip + 1)];
        indices[2] = t[(short)((flip ^ 1) + 1)];
    }
    else
    {
        const int* t = (const int*)tri;
        indices[0] = t[0];
        indices[1] = t[(short)(flip + 1)];
        indices[2] = t[(short)((flip ^ 1) + 1)];
    }
}

const EmsShape* ExtendedMeshShape::FUN_009e3e00(unsigned int key, void* buffer) const
{
    unsigned int numBits = m_numBitsForSubpartIndex;
    unsigned int subpartIndex = (key & 0x7fffffff) >> (32 - numBits);
    unsigned int terminalIndex = key & (~0u >> numBits);

    if (!(key & 0x80000000))
    {
        unsigned int storage[32];
        EmsTrianglesSubpart* local = (EmsTrianglesSubpart*)(((unsigned int)storage + 0x3f) & ~0x3f);
        const EmsTrianglesSubpart* part;
        if (m_numTrianglesSubparts == 1)
        {
            part = &m_embeddedTrianglesSubpart;
        }
        else
        {
            EmsMemCpy16(local, &m_trianglesSubparts[subpartIndex], 4);
            part = local;
        }

        int indices[3];
        EmsGetIndices(part, terminalIndex, indices);
        const char* vertexBase = part->m_vertexBase;
        int vertexStriding = part->m_vertexStriding;

        EmsTriangleShape* __restrict triangle = new (buffer) EmsTriangleShape();
        triangle->m_radius = m_triangleRadius;
        triangle->m_weldingType = m_weldingType;
        triangle->m_type = 4;
        triangle->m_isExtruded = part->m_extrusion.lengthSquared3() > 0.0f;
        triangle->m_extrusion = part->m_extrusion;

        unsigned short weldingInfo;
        if (m_numWeldingInfo == 0)
            weldingInfo = 0;
        else
            weldingInfo = m_weldingInfo[part->m_triangleOffset + terminalIndex];
        triangle->m_weldingInfo = weldingInfo;

        const float* pA = (const float*)(vertexBase + indices[0] * vertexStriding);
        const float* pB = (const float*)(vertexBase + indices[1] * vertexStriding);
        const float* pC = (const float*)(vertexBase + indices[2] * vertexStriding);

        EmsVector4 scale = m_scaling;
        scale.x = scale.x;   // Fake match: a dead self-assignment of the first lane; it turns the x87 operand order of the
                             // x-lane products in the three mul4 expansions (vertex lane loaded before the scale lane).
        EmsVector4 v0;
        v0.load3(pA);
        v0.mul4(scale);
        EmsVector4 v1;
        v1.load3(pB);
        v1.mul4(scale);
        EmsVector4 v2;
        v2.load3(pC);
        v2.mul4(scale);

        triangle->m_vertices[0] = v0;
        triangle->m_vertices[1] = v1;
        triangle->m_vertices[2] = v2;
        return (const EmsShape*)triangle;
    }
    else
    {
        unsigned int storage[32];
        EmsShapesSubpart* part = (EmsShapesSubpart*)(((unsigned int)storage + 0x3f) & ~0x3f);
        FUN_009e5170((int*)part, (const int*)&m_shapesSubparts[subpartIndex]);

        EmsShape* child = part->m_childShapes[terminalIndex];
        if (!part->m_hasTranslation && !part->m_hasRotation)
            return child;

        const EmsShape* result;
        if (!part->m_hasRotation && part->m_hasTranslation)
        {
            result = (const EmsShape*)new (buffer) EmsConvexTranslateShape(child, part->m_translation);
        }
        else
        {
            EmsTransform transform(part->m_rotation, part->m_translation);
            result = (const EmsShape*)new (buffer) EmsTransformShape(child, transform);
        }
        child->removeReference();
        return result;
    }
}
}   // namespace f3m_009e3e00

// @f3 0x009fa0a0 (community match, verified in this file)
#include <math.h>
namespace f3m_009fa0a0 {
// Havok 5.5 bulidJacobianFromTwistLimitAtom (hkpBuildJacobianFromAtoms.cpp, static). Layouts from the Havok 5.5
// headers; the relative-angle helper is hkInternalConstraintUtils_inlineCalcRelativeAngle from hkpInternalConstraintUtils.h.
namespace f3h_009fa0a0 {

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
enum hkResult { HK_SUCCESS = 0, HK_FAILURE = 1 };

extern "C" hkReal __cdecl hkMath_atan2fApproximation(hkReal x, hkReal y);

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_storage;
};

namespace hkMath { __forceinline hkReal sqrt(hkReal r) { return ::sqrtf(r); } }

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = hkReal(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal length3() const { return hkMath::sqrt((x * x) + (y * y) + (z * z)); }
};

class hkMatrix3
{
public:
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3 {};

class hkTransform
{
public:
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpTwistLimitConstraintAtom : public hkpConstraintAtom
{
    hkUint8 m_isEnabled;
    hkUint8 m_twistAxis;
    hkUint8 m_refAxis;
    hkReal m_minAngle;
    hkReal m_maxAngle;
    hkReal m_angularLimitsTauFactor;
};

class hkpConstraintQueryStepInfo
{
public:
    hkPadSpu<float> m_substepDeltaTime;
    hkPadSpu<float> m_microStepDeltaTime;
    hkPadSpu<float> m_substepInvDeltaTime;
    hkPadSpu<float> m_frameDeltaTime;
    hkPadSpu<float> m_frameInvDeltaTime;
    hkPadSpu<float> m_invNumSteps;
    hkPadSpu<float> m_invNumStepsTimesMicroSteps;
    hkPadSpu<float> m_rhsFactor;
    hkPadSpu<float> m_virtMassFactor;
    hkPadSpu<float> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
};

class hkpConstraintQueryIn : public hkpConstraintQueryStepInfo
{
public:
    hkPadSpu<const void*> m_bodyA;
    hkPadSpu<const void*> m_bodyB;
    hkPadSpu<const hkTransform*> m_transformA;
    hkPadSpu<const hkTransform*> m_transformB;
    hkPadSpu<hkReal> m_tau;
    hkPadSpu<hkReal> m_damping;
};

class hkpConstraintQueryOut;

class hkp1dAngularLimitInfo
{
public:
    hkVector4 m_constrainedDofW;
    hkPadSpu<hkReal> m_min;
    hkPadSpu<hkReal> m_max;
    hkPadSpu<hkReal> m_computedAngle;
    hkPadSpu<hkReal> m_tau;
};

__forceinline void hkInternalConstraintUtils_inlineCalcRelativeAngle(
    const hkVector4& twistAxisAinWorld, const hkVector4& twistAxisBinWorld,
    const hkVector4& planeAxisAinWorld, const hkVector4& planeAxisBinWorld,
    hkVector4& axisOut, hkPadSpu<hkReal>& angleOut, hkPadSpu<hkReal>& tauMaxOut)
{
    hkVector4 twist_axis_ws;
    twist_axis_ws.setAdd4(twistAxisBinWorld, twistAxisAinWorld);
    const hkReal twist_axis_ws_length3 = twist_axis_ws.length3();
    if (twist_axis_ws_length3 > 1e-16f)
    {
        tauMaxOut = twist_axis_ws_length3 * 0.5f;
        twist_axis_ws.mul4(1.0f / twist_axis_ws_length3);
    }
    else
    {
        tauMaxOut = 0.0f;
        twist_axis_ws = twistAxisBinWorld;
    }

    hkRotation m_ws_us;
    {
        hkVector4& c0 = m_ws_us.getColumn(0);
        hkVector4& c1 = m_ws_us.getColumn(1);
        hkVector4& c2 = m_ws_us.getColumn(2);
        c0 = twist_axis_ws;
        c1.setCross(twist_axis_ws, planeAxisBinWorld);
        c2.setCross(c1, c0);
    }

    hkReal d1 = m_ws_us.getColumn(1).dot3(planeAxisAinWorld);
    hkReal d2 = m_ws_us.getColumn(2).dot3(planeAxisAinWorld);
    hkReal currentTwistAngle = hkMath_atan2fApproximation(d1, d2);
    angleOut = currentTwistAngle;
    axisOut = twist_axis_ws;
}

static hkResult FUN_009fa0a0(const hkpTwistLimitConstraintAtom& atom, const hkpConstraintQueryIn& in,
                             const hkTransform& baseA, const hkTransform& baseB,
                             hkp1dAngularLimitInfo& info, hkpConstraintQueryOut& out)
{
    info.m_constrainedDofW = baseA.getRotation().getColumn(atom.m_twistAxis);
    info.m_min = atom.m_minAngle;
    info.m_max = atom.m_maxAngle;

    hkPadSpu<hkReal> tauMax;
    hkInternalConstraintUtils_inlineCalcRelativeAngle(
        baseA.getRotation().getColumn(atom.m_twistAxis), baseB.getRotation().getColumn(atom.m_twistAxis),
        baseA.getRotation().getColumn(atom.m_refAxis), baseB.getRotation().getColumn(atom.m_refAxis),
        info.m_constrainedDofW, info.m_computedAngle, tauMax);

    info.m_tau = in.m_tau * atom.m_angularLimitsTauFactor * tauMax * tauMax;
    return HK_SUCCESS;
}

// Stand-in for the file's caller (the atom loop that builds Jacobians).
hkResult hkSolverBuildJacobianTwistStandIn(const hkpTwistLimitConstraintAtom& atom, const hkpConstraintQueryIn& in,
                                           const hkTransform& baseA, const hkTransform& baseB,
                                           hkp1dAngularLimitInfo& info, hkpConstraintQueryOut& out)
{
    return FUN_009fa0a0(atom, in, baseA, baseB, info, out);
}

} // namespace f3h_009fa0a0
}   // namespace f3m_009fa0a0

// @f3 0x009f6cd0 (community match, verified in this file)
#include <new>
extern unsigned long DAT_010f3170;
extern int DAT_0116983c;
extern const char DAT_00e8132c[];
extern const char DAT_00e32798[];
namespace f3m_009f6cd0 {
namespace S009f6cd0_ns {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
}
using S009f6cd0_ns::FUN_00d9b080;


void __cdecl FUN_00901e90(void* array, int numElements, int sizeOfElement);

struct S009f6cd0_MonStream {
    int unk00;
    char* m_end;
    int unk08;
    char* m_capacityMinus16;
};

struct S009f6cd0_TimerCmd {
    const char* name;
    unsigned int time;
    int unk08;
};

struct S009f6cd0_ThreadMem {
    void* FUN_008f6d30(int numBytes, int category);
    void FUN_008f6d90(void* p, int numBytes, int category);
};

__forceinline void S009f6cd0_timer(const char* name)
{
    S009f6cd0_MonStream* stream = (S009f6cd0_MonStream*)FUN_00d9b080(DAT_0116913c);
    char* end = stream->m_end;
    if (end < stream->m_capacityMinus16) {
        S009f6cd0_TimerCmd* cmd = (S009f6cd0_TimerCmd*)end;
        cmd->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cmd->time = ticks;
        stream->m_end = end + 0xc;
    }
}

__forceinline S009f6cd0_ThreadMem* S009f6cd0_mem()
{
    return (S009f6cd0_ThreadMem*)FUN_00d9b080(DAT_010f3170);
}

struct __declspec(align(16)) S009f6cd0_Vector4 {
    float x, y, z, w;
    S009f6cd0_Vector4() {}
    S009f6cd0_Vector4(const S009f6cd0_Vector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void mul4(const S009f6cd0_Vector4& v) { x *= v.x; y *= v.y; z *= v.z; w *= v.w; }
    void sub4(const S009f6cd0_Vector4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }
};

struct S009f6cd0_AabbUint32 {
    unsigned int m_min[3];
    unsigned char m_expansionMin[3];
    unsigned char m_expansionShift;
    unsigned int m_max[3];
    unsigned char m_expansionMax[3];
    unsigned char m_shapeKeyByte;
};

__forceinline void S009f6cd0_uncompress(const S009f6cd0_AabbUint32& in, S009f6cd0_AabbUint32& out)
{
    int shift = in.m_expansionShift;
    out.m_min[0] = in.m_min[0] - (in.m_expansionMin[0] << shift);
    out.m_min[1] = in.m_min[1] - (in.m_expansionMin[1] << shift);
    out.m_min[2] = in.m_min[2] - (in.m_expansionMin[2] << shift);
    out.m_max[0] = in.m_max[0] + (in.m_expansionMax[0] << shift);
    out.m_max[1] = in.m_max[1] + (in.m_expansionMax[1] << shift);
    out.m_max[2] = in.m_max[2] + (in.m_expansionMax[2] << shift);
}

struct S009f6cd0_Aabb {
    S009f6cd0_Vector4 m_min;
    S009f6cd0_Vector4 m_max;
};

struct S009f6cd0_ElemBase {
    S009f6cd0_ElemBase(const S009f6cd0_ElemBase& other);
    virtual ~S009f6cd0_ElemBase();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
};

struct S009f6cd0_Elem : S009f6cd0_ElemBase {
    S009f6cd0_Elem();
    virtual ~S009f6cd0_Elem();
    void FUN_00a66f60(const S009f6cd0_Vector4& mn, const S009f6cd0_Vector4& mx);
    S009f6cd0_Vector4 m_min;
    S009f6cd0_Vector4 m_max;
};

struct S009f6cd0_ElemArray {
    S009f6cd0_Elem* m_data;
    int m_size;
    int m_capacityAndFlags;

    S009f6cd0_ElemArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    ~S009f6cd0_ElemArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            S009f6cd0_mem()->FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(S009f6cd0_Elem), 0x17);
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    int getSize() const { return m_size; }
    S009f6cd0_Elem* begin() { return m_data; }
    S009f6cd0_Elem& operator[](int i) { return m_data[i]; }
    void setSizeUnchecked(int n) { m_size = n; }
    void reserve(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(S009f6cd0_Elem));
        }
    }
    __declspec(noinline) void FUN_00a82280(S009f6cd0_ElemArray& other)
    {
        S009f6cd0_Elem* d = m_data;
        m_data = other.m_data;
        other.m_data = d;
        int sz = m_size;
        m_size = other.m_size;
        other.m_size = sz;
        int cap = m_capacityAndFlags;
        m_capacityAndFlags = other.m_capacityAndFlags;
        other.m_capacityAndFlags = cap;
    }
};

__forceinline void S009f6cd0_destruct(S009f6cd0_Elem* p, int n)
{
    for (int i = 0; i < n; i++)
        p[i].~S009f6cd0_Elem();
}

__forceinline void S009f6cd0_copy(S009f6cd0_Elem* dst, const S009f6cd0_Elem* src, int n)
{
    for (int i = 0; i < n; i++)
        new (&dst[i]) S009f6cd0_Elem(src[i]);
}

struct S009f6cd0_ObjectArray {
    S009f6cd0_ElemArray m_array;

    void clear()
    {
        S009f6cd0_destruct(m_array.begin(), m_array.getSize());
        m_array.m_size = 0;
    }
    __forceinline void setSize(int n)
    {
        int size = m_array.m_size;
        if (n < size) {
            for (int i = n; i < size; i++)
                m_array.m_data[i].~S009f6cd0_Elem();
        } else {
            if (n > m_array.getCapacity()) {
                int cap2 = 2 * m_array.getCapacity();
                int newSize = n < cap2 ? cap2 : n;
                S009f6cd0_ElemArray temp;
                temp.FUN_00a82280(m_array);
                m_array.reserve(newSize);
                S009f6cd0_Elem* dst = m_array.m_data;
                for (int i = 0; i < size; i++)
                    new (&dst[i]) S009f6cd0_Elem(temp.m_data[i]);
                m_array.m_size = size;
                S009f6cd0_destruct(temp.m_data, temp.m_size);
            }
            S009f6cd0_Elem* p = m_array.m_data;
            for (int i = size; i < n; i++)
                new (&p[i]) S009f6cd0_Elem();
        }
        m_array.m_size = n;
    }
    __forceinline S009f6cd0_Elem& expandOne()
    {
        int size = m_array.m_size;
        setSize(size + 1);
        return m_array.m_data[size];
    }
};

struct S009f6cd0_PtrArray {
    S009f6cd0_Elem** m_data;
    int m_size;
    int m_capacityAndFlags;

    S009f6cd0_PtrArray(int n)
    {
        m_data = (S009f6cd0_Elem**)S009f6cd0_mem()->FUN_008f6d30(n * sizeof(S009f6cd0_Elem*), 0x17);
        m_size = n;
        m_capacityAndFlags = n;
    }
    ~S009f6cd0_PtrArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int n = m_capacityAndFlags & 0x3fffffff;
            S009f6cd0_ThreadMem* mem = S009f6cd0_mem();
            mem->FUN_008f6d90(m_data, n * sizeof(S009f6cd0_Elem*), 0x17);
        }
    }
};

struct S009f6cd0_AabbSet {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short m_numAabbs;
    S009f6cd0_AabbUint32* m_aabbs;
};

struct S009f6cd0_Z {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S009f6cd0_AabbSet m_set;
};

struct S009f6cd0_ZArray {
    S009f6cd0_Z** m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct S009f6cd0_Y {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    S009f6cd0_ZArray m_zs;
};

struct S009f6cd0_YArray {
    S009f6cd0_Y** m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct S009f6cd0_Conversion {
    S009f6cd0_Vector4 m_offset;
    S009f6cd0_Vector4 unk10;
    S009f6cd0_Vector4 m_scale;
};

struct S009f6cd0_Info {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    S009f6cd0_Conversion m_conv;
};

struct S009f6cd0_Param {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    S009f6cd0_YArray m_list28;
    S009f6cd0_YArray m_list34;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68;
    S009f6cd0_Info* m_info;
};

struct S009f6cd0_Listener {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30(S009f6cd0_PtrArray& elems, int flags, int arg);
};

struct S009f6cd0_OuterBase {
    S009f6cd0_Listener* m_listener;
    int unk04, unk08, unk0c;
};

struct S009f6cd0_Self {
    int unk00;
    S009f6cd0_ObjectArray m_elems;
    void FUN_009f6cd0(S009f6cd0_Param* param);
};

struct S009f6cd0_Outer : S009f6cd0_OuterBase, S009f6cd0_Self {
};

// pdb: hkpMidphaseViewer::postSimulationCallback | hkpMidphaseViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void S009f6cd0_Self::FUN_009f6cd0(S009f6cd0_Param* param)
{
    S009f6cd0_timer(DAT_00e8132c);
    m_elems.clear();
    const S009f6cd0_YArray* list = &param->m_list28;
    for (int pass = 0; pass < 2; pass++) {
        for (int i = 0; i < list->m_size; i++) {
            const S009f6cd0_ZArray& zs = list->m_data[i]->m_zs;
            for (int j = 0; j < zs.m_size; j++) {
                const S009f6cd0_AabbSet& set = zs.m_data[j]->m_set;
                const S009f6cd0_AabbUint32* aabb = set.m_aabbs;
                if (aabb) {
                    for (int k = 0; k < set.m_numAabbs; k++, aabb++) {
                        const S009f6cd0_Conversion& conv = param->m_info->m_conv;
                        S009f6cd0_AabbUint32 expanded;
                        S009f6cd0_uncompress(*aabb, expanded);
                        S009f6cd0_Aabb aabbF;
                        aabbF.m_min.set((float)expanded.m_min[0], (float)expanded.m_min[1], (float)expanded.m_min[2], 0.0f);
                        aabbF.m_max.set((float)expanded.m_max[0], (float)expanded.m_max[1], (float)expanded.m_max[2], 0.0f);
                        S009f6cd0_Vector4 inv;
                        inv.set(1.0f / conv.m_scale.x, 1.0f / conv.m_scale.y, 1.0f / conv.m_scale.z, 1.0f);
                        aabbF.m_min.mul4(inv);
                        aabbF.m_max.mul4(inv);
                        aabbF.m_min.sub4(conv.m_offset);
                        aabbF.m_max.sub4(conv.m_offset);
                        m_elems.expandOne().FUN_00a66f60(aabbF.m_min, aabbF.m_max);
                    }
                }
            }
        }
        list = &param->m_list34;
    }
    int n = m_elems.m_array.m_size;
    S009f6cd0_PtrArray ptrs(n);
    m_elems.setSize(n);
    S009f6cd0_Elem** p = ptrs.m_data;
    S009f6cd0_Elem* e = m_elems.m_array.m_data;
    for (int i = 0; i < n; i++)
        *p++ = e++;
    static_cast<S009f6cd0_Outer&>(*this).m_listener->vf30(ptrs, (int)0xffffa500, DAT_0116983c);
    S009f6cd0_timer(DAT_00e32798);
}
}   // namespace f3m_009f6cd0

// @f3 0x009eaf10 (community match, verified in this file)
// 0x009eaf10: getMeanAndCovariance(const hkReal* vertexArray, int numVertices, int striding, hkMatrix3& cov,
// hkVector4& mu, hkBool perturb) of Havok 5.5.0 (hkpInternal, hkpGeometryUtility.cpp; compiled with /MT /Ox /Ob1
// /Oi /Ot /GF /GS-), a file-local (static) function.
// Area-weighted mean and covariance of a triangle list (vertices in consecutive triples, 'striding' bytes apart):
// per triangle the area (half the length of the edge cross product; with 'perturb' the first edge gets a small
// random offset), the centroid and the second-moment terms; triangles without area add unweighted terms. At the
// end the covariance is divided by 12 and the weighted mean's product taken off; with no area at all the mean is
// zero and the covariance the identity.
// The function takes 'cov' in edi and the other five arguments on the stack: Visual C++ 2005 gives a static
// function whose address is never taken a register convention of its own when it sees every call to it in the
// same file, without whole-program optimization. Its one caller from the same source file,
// hkpGeometryUtility::calcObb (0x009ec920), is therefore defined here as well; without it the function is not
// emitted at all. calcObb's other file-local callees are only declared.
// This file is built from the Havok 5.5.0 SDK's own headers: the functions were compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the full compile); those declarations
// are the SDK's text with its names. The bodies follow the SDK's unoptimized (hybrid) library object statement by
// statement (both match it) and reproduce the release object. The parentheses of the unweighted covariance sum
// (cov( i, j ) += ( p(i) * p(j) + q(i) * q(j) + r(i) * r(j) )) matter: they keep a node the optimizer hashes, which
// numbers the later common subexpressions one higher and so gives the original operand order of the products in the
// two covariance loops. Only the function carries the packet's name.
namespace f3m_009eaf10 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
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
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				__forceinline void setData(T p)
				{
					hkUlong v = hkUlong(p);
					TlsSetValue( m_slotID, (void*)v );
				}
				unsigned long m_slotID;
		};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
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
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
template <typename TYPE>	__forceinline void __cdecl hkDeallocateStack(TYPE* ptr);
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
hkReal __cdecl rand01();
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
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
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
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
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}
class hkSphere;
struct hkStridedVertices;
struct hkGeometry
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkGeometry), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	struct Triangle
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkGeometry::Triangle), HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		int m_a;
		int m_b;
		int m_c;
		void set( int a, int b, int c )
		{
			m_a = a;
			m_b = b;
			m_c = c;
		}
	};
	hkArray<hkVector4> m_vertices;
	hkArray<Triangle> m_triangles;
};
enum hkpGeomConvexHullMode
{
	HK_GEOM_CONVEXHULL_MODE_INVALID,
	HK_GEOM_CONVEXHULL_MODE_FAST,
	HK_GEOM_CONVEXHULL_MODE_ACCURATE_BUT_SLOW,
	HK_GEOM_CONVEXHULL_MODE_MAX_ID
};
enum hkpGeomObbMode
{
	HK_GEOM_OBB_MODE_INVALID,
	HK_GEOM_OBB_MODE_DEFAULT,
	HK_GEOM_OBB_MODE_BETTER_FIT_BUT_SLOWER,
	HK_GEOM_OBB_MODE_MAX_ID
};
class hkpGeometryUtility
{
public:
	static void __cdecl createConvexGeometry( const hkStridedVertices& stridedVertsIn, hkGeometry& geometryOut, hkpGeomConvexHullMode mode = HK_GEOM_CONVEXHULL_MODE_FAST );
	static void __cdecl createConvexGeometry( const hkStridedVertices& stridedVertsIn, hkGeometry& geometryOut, hkArray<hkVector4>& planeEquationsOut, hkpGeomConvexHullMode mode = HK_GEOM_CONVEXHULL_MODE_FAST );
	static void __cdecl createVerticesFromPlaneEquations(  const hkArray<hkVector4>& planeEquationsIn, hkArray<hkVector4>& vertsOut );
	static void __cdecl createGeometryFromPlaneEquations(  const hkArray<hkVector4>& planeEquationsIn, hkGeometry& geometryOut );
    static hkBool __cdecl getAxesFromCovariance(hkMatrix3 &covArray, hkVector4 &axis0, hkVector4 &axis1, hkVector4 &axis2);
	static void __cdecl calcObb( const hkStridedVertices& stridedVertsIn, hkVector4& halfExtents, hkTransform& transform, hkpGeomObbMode mode = HK_GEOM_OBB_MODE_DEFAULT);
	static hkSphere __cdecl createMinBoundingSphere( const hkStridedVertices& stridedVertsIn, const hkReal radiusEpsilon = 1e-5f);
	static void __cdecl expandPlanes(  hkArray<hkVector4>& planeEquations, hkReal byDistance );
};
template <typename T>
class hkLocalArray : public hkArray<T>
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkLocalArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkLocalArray( int capacity )
		{
			this->m_data = hkAllocateStack<T>(capacity);
			this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
			m_localMemory = this->m_data;
		}
		__forceinline void discardAndResize(int newsize)
		{
			;
			hkDeallocateStack<T>( m_localMemory );
			m_localMemory = this->m_data = hkAllocateStack<T>(newsize);
			this->m_size = newsize;
			this->m_capacityAndFlags = newsize | hkArray<T>::DONT_DEALLOCATE_FLAG;
		}
		void assertNotResized()
		{
			;
		}
		hkBool wasReallocated() const
		{
			return m_localMemory != this->m_data;
		}
		__forceinline ~hkLocalArray()
		{
			hkDeallocateStack<T>( m_localMemory );
		}
		T* m_localMemory;
};
static void FUN_009eaf10( const hkReal* vertexArray, int numVertices, int striding, hkMatrix3& cov, hkVector4& mu, hkBool perturb )
{
	hkReal Ah = 0.0f;
	int numTris = numVertices / 3;
	hkVector4 mh;
	mh.setZero4();
	hkVector4* m = new hkVector4[numTris];
	cov.setZero();
	hkReal Ak;
	hkVector4 p;
	hkVector4 q;
	hkVector4 r;
	hkReal* v = (hkReal*)vertexArray;
	for ( int k = 0; k < numTris; k++ )
	{
		p.set( v[0], v[1], v[2] );
		v = (hkReal*)( (char*)v + striding );
		q.set( v[0], v[1], v[2] );
		v = (hkReal*)( (char*)v + striding );
		r.set( v[0], v[1], v[2] );
		v = (hkReal*)( (char*)v + striding );
		if ( perturb )
		{
			hkVector4 randvec; randvec.set( hkMath::rand01(), hkMath::rand01(), hkMath::rand01() );
			hkVector4 vecA; vecA.setMul4( 0.01f, randvec );
			vecA.add4( p );
			vecA.sub4( q );
			hkVector4 vecB; vecB.setSub4( p, r );
			hkVector4 cross; cross.setCross( vecA, vecB );
			Ak = cross.length3() * 0.5;
		}
		else
		{
			hkVector4 vecA; vecA.setSub4( p, q );
			hkVector4 vecB; vecB.setSub4( p, r );
			hkVector4 cross; cross.setCross( vecA, vecB );
			Ak = cross.length3() * 0.5;
		}
		if ( Ak > 0.0 )
		{
			Ah += Ak;
			hkVector4 tmpV; tmpV.setAdd4( p, q );
			tmpV.add4( r );
			tmpV.mul4( 1.0f / 3.0f );
			m[k] = tmpV;
			hkVector4 addVec; addVec.setMul4( Ak, m[k] );
			mh.add4( addVec );
			for ( int i = 0; i < 3; i++ )
				for ( int j = 0; j < 3; j++ )
					cov( i, j ) += ( m[k](i) * 9.0 * m[k](j) + p(i) * p(j) + q(i) * q(j) + r(i) * r(j) ) * Ak;
		}
		else
		{
			m[k].setAdd4( p, q );
			m[k].add4( r );
			m[k].mul4( 1.0f / 3.0f );
			for ( int i = 0; i < 3; i++ )
				for ( int j = 0; j < 3; j++ )
					cov( i, j ) += ( p(i) * p(j) + q(i) * q(j) + r(i) * r(j) );
		}
	}
	if ( Ah <= 0.0 )
	{
		mu.setZero4();
		cov.setIdentity();
	}
	else
	{
		mh.mul4( 1.0f / Ah );
		for ( int i = 0; i < 3; i++ )
			for ( int j = 0; j < 3; j++ )
				cov( i, j ) = cov( i, j ) / 12.0 - mh(i) * mh(j) * Ah;
		mu = mh;
	}
	delete[] m;
}
bool getIsBoxGeometry( const hkArray<hkVector4>& vertices, hkVector4& halfExtents, hkTransform& transform, hkReal tolerance );
void makeOBBUsingAxes( const hkReal* vertexArray, int numVertices, int striding, hkVector4& halfExtents, const hkVector4* axes, hkVector4& position );
hkReal doSteepestDescent( const hkReal* vertexArray, int numVertices, int striding, const hkVector4* axesIn, hkVector4* axesOut, int numIterations );
void hkpGeometryUtility::calcObb( const hkStridedVertices& stridedVertsIn, hkVector4& halfExtents, hkTransform& transform, hkpGeomObbMode mode )
{
	;
	hkGeometry geom;
	hkpGeometryUtility::createConvexGeometry( stridedVertsIn, geom, HK_GEOM_CONVEXHULL_MODE_FAST );
	hkLocalArray<hkVector4> triangleVerts( geom.m_triangles.getSize() * 3 );
	triangleVerts.setSize( geom.m_triangles.getSize() * 3 );
	for ( int t = 0; t < geom.m_triangles.getSize(); t++ )
	{
		triangleVerts[t * 3] = geom.m_vertices[ geom.m_triangles[t].m_a ];
		triangleVerts[t * 3 + 1] = geom.m_vertices[ geom.m_triangles[t].m_b ];
		triangleVerts[t * 3 + 2] = geom.m_vertices[ geom.m_triangles[t].m_c ];
	}
	bool isBox = getIsBoxGeometry( geom.m_vertices, halfExtents, transform, 0.01f );
	if ( isBox )
	{
		return;
	}
	hkReal* vertexArray = (hkReal*)triangleVerts.begin();
	int numVertices = triangleVerts.getSize();
	int striding = sizeof( hkVector4 );
	hkVector4 axesAabb[3];
	hkVector4 positionAabb;
	hkVector4 halfExtentsAabb;
	axesAabb[0].set( 1.0f, 0.0f, 0.0f );
	axesAabb[1].set( 0.0f, 1.0f, 0.0f );
	axesAabb[2].set( 0.0f, 0.0f, 1.0f );
	makeOBBUsingAxes( vertexArray, numVertices, striding, halfExtentsAabb, axesAabb, positionAabb );
	hkReal volAabb = halfExtentsAabb(0) * halfExtentsAabb(1) * halfExtentsAabb(2);
	hkVector4 mu;
	hkMatrix3 cov;
	hkVector4 axesCov[3];
	hkVector4 positionCov;
	hkVector4 halfExtentsCov;
	hkBool perturb = false;
	FUN_009eaf10( vertexArray, numVertices, striding, cov, mu, perturb );
	hkpGeometryUtility::getAxesFromCovariance( cov, axesCov[0], axesCov[1], axesCov[2] );
	makeOBBUsingAxes( vertexArray, numVertices, striding, halfExtentsCov, axesCov, positionCov );
	hkReal volCovariance = halfExtentsCov(0) * halfExtentsCov(1) * halfExtentsCov(2);
	if ( mode == HK_GEOM_OBB_MODE_BETTER_FIT_BUT_SLOWER )
	{
		volAabb = doSteepestDescent( vertexArray, numVertices, striding, axesAabb, axesAabb, 20 );
		makeOBBUsingAxes( vertexArray, numVertices, striding, halfExtentsAabb, axesAabb, positionAabb );
		volCovariance = doSteepestDescent( vertexArray, numVertices, striding, axesCov, axesCov, 20 );
		makeOBBUsingAxes( vertexArray, numVertices, striding, halfExtentsCov, axesCov, positionCov );
	}
	hkVector4* axes;
	hkVector4 position;
	if ( volAabb < volCovariance )
	{
		axes = axesAabb;
		halfExtents = halfExtentsAabb;
		position = positionAabb;
	}
	else
	{
		axes = axesCov;
		halfExtents = halfExtentsCov;
		position = positionCov;
	}
	hkRotation obbRotation;
	obbRotation.setCols( axes[0], axes[1], axes[2] );
	transform = hkTransform( obbRotation, position );
}

}  // namespace f3m_009eaf10

// @f3 0x009f1730 (community match, verified in this file)
#include <new>
extern unsigned long DAT_010f3170;
extern int DAT_011697f8;
extern const char DAT_00e80c90[];
extern const char DAT_00e32798[];
namespace f3m_009f1730 {
// hkpSimulationIslandViewer::postSimulationCallback (Havok 5.5 visual debugger, FPU hkVector4).
// Helper classes as in the matched sibling FUN_009f6cd0 (hkObjectArray<hkDisplayAABB>::setSize, hkArray, timer).
namespace f3m_009f1730 {
namespace S9f1730_ns {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
}
using S9f1730_ns::FUN_00d9b080;

void __cdecl FUN_00901e90(void* array, int numElements, int sizeOfElement);

struct S9f1730_MonStream {
    int unk00;
    char* m_end;
    int unk08;
    char* m_capacityMinus16;
};

struct S9f1730_TimerCmd {
    const char* name;
    unsigned int time;
    int unk08;
};

struct S9f1730_ThreadMem {
    void FUN_008f6d90(void* p, int numBytes, int category);
};

__forceinline void S9f1730_timer(const char* name)
{
    S9f1730_MonStream* stream = (S9f1730_MonStream*)FUN_00d9b080(DAT_0116913c);
    char* end = stream->m_end;
    if (end < stream->m_capacityMinus16) {
        S9f1730_TimerCmd* cmd = (S9f1730_TimerCmd*)end;
        cmd->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cmd->time = ticks;
        stream->m_end = end + 0xc;
    }
}

__forceinline S9f1730_ThreadMem* S9f1730_mem()
{
    return (S9f1730_ThreadMem*)FUN_00d9b080(DAT_010f3170);
}

struct __declspec(align(16)) S9f1730_Vector4 {
    float x, y, z, w;
    S9f1730_Vector4() {}
    S9f1730_Vector4(const S9f1730_Vector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void setAll(float a) { x = a; y = a; z = a; w = a; }
    __forceinline void setMin4(const S9f1730_Vector4& a, const S9f1730_Vector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const S9f1730_Vector4& a, const S9f1730_Vector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
};

struct S9f1730_Aabb {
    S9f1730_Vector4 m_min;
    S9f1730_Vector4 m_max;
};

struct S9f1730_ElemBase {
    S9f1730_ElemBase(const S9f1730_ElemBase& other);
    virtual ~S9f1730_ElemBase();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
};

struct S9f1730_Elem : S9f1730_ElemBase {
    S9f1730_Elem();
    __forceinline S9f1730_Elem(const S9f1730_Elem& o) : S9f1730_ElemBase(o), m_min(o.m_min), m_max(o.m_max) {}
    virtual ~S9f1730_Elem();
    void FUN_00a66f60(const S9f1730_Vector4& mn, const S9f1730_Vector4& mx);
    S9f1730_Vector4 m_min;
    S9f1730_Vector4 m_max;
};

struct S9f1730_ElemArray {
    S9f1730_Elem* m_data;
    int m_size;
    int m_capacityAndFlags;

    S9f1730_ElemArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    ~S9f1730_ElemArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            S9f1730_mem()->FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(S9f1730_Elem), 0x17);
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    int getSize() const { return m_size; }
    S9f1730_Elem* begin() { return m_data; }
    S9f1730_Elem& operator[](int i) { return m_data[i]; }
    void reserve(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(S9f1730_Elem));
        }
    }
    __declspec(noinline) void FUN_00a82280(S9f1730_ElemArray& other)
    {
        S9f1730_Elem* d = m_data;
        m_data = other.m_data;
        other.m_data = d;
        int sz = m_size;
        m_size = other.m_size;
        other.m_size = sz;
        int cap = m_capacityAndFlags;
        m_capacityAndFlags = other.m_capacityAndFlags;
        other.m_capacityAndFlags = cap;
    }
};

__forceinline void S9f1730_destruct(S9f1730_Elem* p, int n)
{
    for (int i = 0; i < n; i++)
        p[i].~S9f1730_Elem();
}

struct S9f1730_ObjectArray {
    S9f1730_ElemArray m_array;

    int getSize() const { return m_array.m_size; }
    S9f1730_Elem& operator[](int i) { return m_array.m_data[i]; }
    __forceinline void setSize(int n)
    {
        int size = m_array.m_size;
        if (n < size) {
            for (int i = n; i < size; i++)
                m_array.m_data[i].~S9f1730_Elem();
        } else {
            if (n > m_array.getCapacity()) {
                int cap2 = 2 * m_array.getCapacity();
                int newSize = n < cap2 ? cap2 : n;
                S9f1730_ElemArray temp;
                temp.FUN_00a82280(m_array);
                m_array.reserve(newSize);
                S9f1730_Elem* dst = m_array.m_data;
                for (int i = 0; i < size; i++)
                    new (&dst[i]) S9f1730_Elem(temp.m_data[i]);
                m_array.m_size = size;
                S9f1730_destruct(temp.m_data, temp.m_size);
            }
            S9f1730_Elem* p = m_array.m_data;
            for (int i = size; i < n; i++)
                new (&p[i]) S9f1730_Elem();
        }
        m_array.m_size = n;
    }
};

template <class T>
struct S9f1730_Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    S9f1730_Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    ~S9f1730_Array()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int n = m_capacityAndFlags & 0x3fffffff;
            S9f1730_ThreadMem* mem = S9f1730_mem();
            mem->FUN_008f6d90(m_data, n * sizeof(T), 0x17);
        }
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    int getSize() const { return m_size; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    void reserve(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
};

struct S9f1730_BroadPhaseHandle {
    int m_id;
};

struct S9f1730_Collidable {
    void* m_shape;
    int unk04, unk08, unk0c, unk10;
    S9f1730_BroadPhaseHandle m_broadPhaseHandle;
};

struct S9f1730_Entity {
    int unk00, unk04, unk08, unk0c;
    S9f1730_Collidable m_collidable;
};

struct S9f1730_Island {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    S9f1730_Array<S9f1730_Entity*> m_entities;
};

struct S9f1730_BroadPhase {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void getAabb(const S9f1730_BroadPhaseHandle* object, S9f1730_Aabb& aabb) const;
};

struct S9f1730_World {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    S9f1730_Array<S9f1730_Island*> m_activeSimulationIslands;
    S9f1730_Array<S9f1730_Island*> m_inactiveSimulationIslands;
    int unk40, unk44, unk48, unk4c, unk50;
    S9f1730_BroadPhase* m_broadPhase;
};

struct S9f1730_DisplayHandler {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void displayGeometry(const S9f1730_Array<S9f1730_Elem*>& geometries, int color, int tag);
};

struct S9f1730_OuterBase {
    S9f1730_DisplayHandler* m_displayHandler;
    int unk04, unk08, unk0c;
};

struct S9f1730_Self {
    int unk00;
    bool m_showActiveIslands;
    bool m_showInactiveIslands;
    S9f1730_ObjectArray m_inactiveIslandDisplayGeometries;
    S9f1730_ObjectArray m_activeIslandDisplayGeometries;
    void FUN_009f1730(S9f1730_World* world);
};

struct S9f1730_Viewer : S9f1730_OuterBase, S9f1730_Self {
};

// pdb: hkpSimulationIslandViewer::postSimulationCallback | hkpSimulationIslandViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void S9f1730_Self::FUN_009f1730(S9f1730_World* world)
{
    S9f1730_timer(DAT_00e80c90);

    if (m_showActiveIslands) {
        const S9f1730_Array<S9f1730_Island*>& islands = world->m_activeSimulationIslands;
        if (islands.getSize() > m_activeIslandDisplayGeometries.getSize())
            m_activeIslandDisplayGeometries.setSize(islands.getSize());

        S9f1730_Array<S9f1730_Elem*> displayGeometries;
        displayGeometries.setSize(islands.getSize());
        // aabbs is sized, written per island and freed but never read: the target does exactly that (guess at the source)
        S9f1730_Array<S9f1730_Aabb> aabbs;
        aabbs.setSize(islands.getSize());

        for (int i = 0; i < islands.getSize(); i++) {
            const S9f1730_Array<S9f1730_Entity*>& entities = islands[i]->m_entities;
            aabbs[i].m_max.setAll(-3.40282e+38f);
            aabbs[i].m_min.setAll(3.40282e+38f);
            S9f1730_Vector4 minExtent;
            minExtent.setAll(3.40282e+38f);
            S9f1730_Vector4 maxExtent;
            maxExtent.setAll(-3.40282e+38f);
            for (int e = 0; e < entities.getSize(); e++) {
                const S9f1730_Collidable* collidable = &entities[e]->m_collidable;
                if (collidable->m_shape) {
                    S9f1730_Aabb aabb;
                    world->m_broadPhase->getAabb(&collidable->m_broadPhaseHandle, aabb);
                    maxExtent.setMax4(maxExtent, aabb.m_max);
                    minExtent.setMin4(minExtent, aabb.m_min);
                }
            }
            m_activeIslandDisplayGeometries[i].FUN_00a66f60(minExtent, maxExtent);
            displayGeometries[i] = &m_activeIslandDisplayGeometries[i];
        }
        static_cast<S9f1730_Viewer&>(*this).m_displayHandler->displayGeometry(displayGeometries, 0xff0000ff, DAT_011697f8);
    }

    if (m_showInactiveIslands) {
        const S9f1730_Array<S9f1730_Island*>& islands = world->m_inactiveSimulationIslands;
        if (islands.getSize() > m_inactiveIslandDisplayGeometries.getSize())
            m_inactiveIslandDisplayGeometries.setSize(islands.getSize());

        S9f1730_Array<S9f1730_Elem*> displayGeometries;
        displayGeometries.setSize(islands.getSize());

        for (int i = 0; i < islands.getSize(); i++) {
            const S9f1730_Array<S9f1730_Entity*>& entities = islands[i]->m_entities;
            // here maxExtent is set first (the target's fxch and store order); the active block sets minExtent first
            S9f1730_Vector4 minExtent;
            S9f1730_Vector4 maxExtent;
            maxExtent.setAll(-3.40282e+38f);
            minExtent.setAll(3.40282e+38f);
            for (int e = 0; e < entities.getSize(); e++) {
                const S9f1730_Collidable* collidable = &entities[e]->m_collidable;
                if (collidable->m_shape) {
                    S9f1730_Aabb aabb;
                    world->m_broadPhase->getAabb(&collidable->m_broadPhaseHandle, aabb);
                    maxExtent.setMax4(maxExtent, aabb.m_max);
                    minExtent.setMin4(minExtent, aabb.m_min);
                }
            }
            m_inactiveIslandDisplayGeometries[i].FUN_00a66f60(minExtent, maxExtent);
            displayGeometries[i] = &m_inactiveIslandDisplayGeometries[i];
        }
        static_cast<S9f1730_Viewer&>(*this).m_displayHandler->displayGeometry(displayGeometries, 0xff008000, DAT_011697f8);
    }

    S9f1730_timer(DAT_00e32798);
}
}
}   // namespace f3m_009f1730

// @f3 0x009fac30 (community match, verified in this file)
namespace f3m_009fac30 {
// 0x009fac30: buildJacobianFromRagdollMotorAtom(const hkpRagdollMotorConstraintAtom& atom, const hkpConstraintQueryIn& in,
// const hkTransform& baseA, const hkTransform& baseB, hkpConstraintQueryOut& out) of Havok 5.5.0 (hkpConstraintSolver,
// hkpBuildJacobianFromAtoms.cpp; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-), a file-local (static) function.
// The ragdoll motor: for each of the three axes with a motor, the current and the target twist angle about the
// bisector of the two bodies' twist axes (hkInternalConstraintUtils_inlineCalcRelativeAngle, once with body A's
// frame and once with the target frame), an angular motor jacobian about that axis, the motor's own force law
// (hkCalcMotorData) on the angle errors, and the motor schema; an axis without a motor, or a disabled atom, skips its
// solver results.
// The function takes 'atom' in eax and 'baseB' in edi, 'in', 'baseA' and 'out' on the stack: Visual C++ 2005 gives a
// static function whose address is never taken a register convention of its own when it sees every call to it in the
// same file, without whole-program optimization.
// THE CALLER IN THIS FILE IS A STAND-IN, not a function of the game: it exists only so that the compiler emits the
// static target (a static function with no call in its file is not emitted at all). The real caller is the atom loop
// hkSolverBuildJacobianFromAtomsNotContact (0x009fccc0), where the SDK's builds expand this function inline; in the
// SDK's release object and in the game nothing calls this out-of-line copy.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the full compile); those declarations
// are the SDK's text with its names. The solver library's schema and jacobian classes that no SDK header ships
// (hkpJacobianSchema, hkpJacobian1dAngularMotorSchema, hkpJacobianShiftSolverResultsPointerSchema, hkp2AngJacobian,
// the hkJacobianBuilder helpers) are rebuilt from the library's debug records and objects. Only the function carries
// the packet's name.
namespace f3m_009fac30 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}
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
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
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
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
extern "C"
{
hkReal __cdecl hkMath_atan2fApproximation( hkReal x, hkReal y );
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
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
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
extern "C"
{
void hkMatrix3_setMulMat3Mat3( hkMatrix3* thisMatrix, const hkMatrix3& aTb, const hkMatrix3& bTc );
}
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
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
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
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
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
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
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
inline void hkMatrix3::_setMul( const hkMatrix3& aTb, const hkMatrix3& bTc )
{
	hkMatrix3_setMulMat3Mat3( this, aTb, bTc );
}
const hkVector4& hkTransform::getColumn(int x) const
{
	return m_rotation.getColumn(x);
}
const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}
class hkpSolverResults
{
	public:
		inline hkReal getImpulseApplied() const;
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
inline void hkpSolverResults::init()
{
	m_impulseApplied = 0.0f;
	m_internalSolverData = 0.0f;
}
inline hkpSolverResults::hkpSolverResults()
{
	init();
}
struct hkpSolverInfo
{
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
struct hkp1dMotorSolverInfo
{
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};
struct hkpConstraintInfo
{
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	inline void clear( ) { m_maxSizeOfSchema = 0; m_sizeOfSchemas = 0; m_numSolverResults = 0; m_numSolverElemTemps = 0; }
	inline void addHeader( ) { m_sizeOfSchemas += 16; }
	inline void add( int schemaSize, int numSolverResults, int numSolverTempElems ) { m_sizeOfSchemas += schemaSize; m_numSolverResults += numSolverResults; m_numSolverElemTemps += numSolverTempElems; }
	inline void add( const hkpConstraintInfo& other);
	inline void sub( const hkpConstraintInfo& other);
	inline void merge( const hkpConstraintInfo& other);
};
struct hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum AtomType
		{
			TYPE_INVALID = 0,
			TYPE_BRIDGE,
			TYPE_SET_LOCAL_TRANSFORMS,
			TYPE_SET_LOCAL_TRANSLATIONS,
			TYPE_SET_LOCAL_ROTATIONS,
			TYPE_BALL_SOCKET,
			TYPE_STIFF_SPRING,
			TYPE_LIN,
			TYPE_LIN_SOFT,
			TYPE_LIN_LIMIT,
			TYPE_LIN_FRICTION,
			TYPE_LIN_MOTOR,
			TYPE_2D_ANG,
			TYPE_ANG,
			TYPE_ANG_LIMIT,
			TYPE_TWIST_LIMIT,
			TYPE_CONE_LIMIT,
			TYPE_ANG_FRICTION,
			TYPE_ANG_MOTOR,
			TYPE_RAGDOLL_MOTOR,
			TYPE_PULLEY,
			TYPE_OVERWRITE_PIVOT,
			TYPE_CONTACT,
			TYPE_MODIFIER_SOFT_CONTACT,
			TYPE_MODIFIER_MASS_CHANGER,
			TYPE_MODIFIER_VISCOUS_SURFACE,
			TYPE_MODIFIER_MOVING_SURFACE,
			TYPE_MODIFIER_IGNORE_CONSTRAINT,
			TYPE_MAX
		};
		enum CallbackRequest
		{
			CALLBACK_REQUEST_NONE = 0,
			CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
			CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
			CALLBACK_REQUEST_SETUP_CALLBACK = 4
		};
	public:
		__forceinline enum AtomType getType() const { return m_type; }
		__forceinline int isModifierType() const { return m_type >= TYPE_MODIFIER_SOFT_CONTACT; }
	protected:
		hkpConstraintAtom(enum AtomType type) : m_type(type) {}
	private:
		hkpConstraintAtom();
	public:
		hkEnum<AtomType,hkUint16> m_type;
		hkpConstraintAtom(hkFinishLoadedObjectFlag f) {}
};
struct hkpRagdollMotorConstraintAtom : public hkpConstraintAtom
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkpRagdollMotorConstraintAtom() : hkpConstraintAtom(TYPE_RAGDOLL_MOTOR) { m_isEnabled = true; m_initializedOffset = 0; m_previousTargetAnglesOffset = 0; }
	__forceinline hkpConstraintAtom* next() const { return const_cast<hkpConstraintAtom*>( static_cast<const hkpConstraintAtom*>(this+1) ); }
	__forceinline int numSolverResults() const    { return 3; }
	__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const { infoOut.add( 3 * 64, 3, (1+2) * 3 ); }
	hkBool m_isEnabled;
	hkInt16 m_initializedOffset;
	hkInt16 m_previousTargetAnglesOffset;
	hkMatrix3 m_targetFrameAinB;
	class hkpConstraintMotor* m_motors[3];
	hkpRagdollMotorConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
class hkpVelocityAccumulator;
class hkpConstraintQueryStepInfo
{
	public:
		__declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
		hkPadSpu<float>		m_microStepDeltaTime;
		hkPadSpu<float>		m_substepInvDeltaTime;
		hkPadSpu<float>		m_frameDeltaTime;
		hkPadSpu<float>		m_frameInvDeltaTime;
		hkPadSpu<float>		m_invNumSteps;
		hkPadSpu<float>		m_invNumStepsTimesMicroSteps;
		hkPadSpu<float>		m_rhsFactor;
		hkPadSpu<float>		m_virtMassFactor;
		hkPadSpu<float> m_frictionRhsFactor;
};
class hkpConstraintQueryIn: public hkpConstraintQueryStepInfo
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintQueryIn), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkpConstraintQueryIn() { }
		__declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
		hkPadSpu<const hkpVelocityAccumulator*>	m_bodyB;
		hkPadSpu<const hkTransform*>	m_transformA;
		hkPadSpu<const hkTransform*>	m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<class hkpConstraintInstance*>	m_constraintInstance;
		hkPadSpu<void*>	m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
		inline void set( const hkpSolverInfo& si, const hkStepInfo& stepInfo )
		{
			m_substepDeltaTime    = si.m_deltaTime;
			m_microStepDeltaTime  = si.m_deltaTime * si.m_invNumMicroSteps;
			m_substepInvDeltaTime = si.m_invDeltaTime;
			m_invNumSteps		  = si.m_invNumSteps;
			m_invNumStepsTimesMicroSteps	  = si.m_invNumSteps * si.m_invNumMicroSteps;
			m_tau			      = si.m_tau;
			m_damping		      = si.m_damping;
			m_rhsFactor			  = si.m_tauDivDamp * si.m_invDeltaTime;
			m_virtMassFactor      = si.m_damping;
			m_frictionRhsFactor   = si.m_frictionTauDivDamp * si.m_invDeltaTime;
			m_frameDeltaTime      = stepInfo.m_deltaTime;
			m_frameInvDeltaTime   = stepInfo.m_invDeltaTime;
		}
};
class hkpJacobianSchema;
class  hkpConstraintQueryOut
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintQueryOut), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkPadSpu<hkpJacobianSchema*> m_jacobianSchemas;
};
class hkpVelocityAccumulator
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulator), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	hkVector4& getCenterOfMassInWorld() { return m_scratch0; }
	const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
	hkRotation& getCoreFromWorldMatrix() { return m_coreFromWorld; }
	const hkRotation& getCoreFromWorldMatrix() const { return m_coreFromWorld; }
	hkVector4& getSumLinearVel() { return m_scratch0; }
	hkVector4& getSumAngularVel() { return reinterpret_cast<hkVector4&>(m_coreFromWorld); }
	const hkVector4& getSumLinearVel() const { return m_scratch0; }
	const hkVector4& getSumAngularVel() const { return reinterpret_cast<const hkVector4&>(m_coreFromWorld); }
public:
	hkVector4 m_scratch0;
	hkRotation m_coreFromWorld;   // 20 Nov 2026: a real hkRotation at +0x50 (0x00a00c20 copies it as floats; mathisto's proof)
public:
	__forceinline void setFixed()
	{
		m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
		m_matrixIsIdentity = true;
		this->m_invMasses.setZero4();
		this->m_linearVel.setZero4();
		this->m_angularVel.setZero4();
		this->getCenterOfMassInWorld().setZero4();
		this->getCoreFromWorldMatrix().setZero();
	}
};
class hkp1dBilateralConstraintStatus
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1dBilateralConstraintStatus), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    hkPadSpu<hkReal>			m_virtualMass;
};
class hkp1dConstraintMotorInfo
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1dConstraintMotorInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    hkPadSpu<hkReal>				m_targetPosition;
	    hkPadSpu<hkReal>				m_targetVelocity;
	    hkPadSpu<hkReal>				m_maxForce;
	    hkPadSpu<hkReal>				m_minForce;
	    hkPadSpu<hkReal>				m_tau;
	    hkPadSpu<hkReal>				m_damping;
};
class hkpConstraintMotorInput: public hkp1dBilateralConstraintStatus
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintMotorInput), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    hkPadSpu<const class hkpConstraintQueryStepInfo*> m_stepInfo;
	    class hkpSolverResults m_lastResults;
	    hkPadSpu<hkReal> m_deltaTarget;
	    hkPadSpu<hkReal> m_positionError;
};
class hkpConstraintMotorOutput: public hkp1dConstraintMotorInfo
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintMotorOutput), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
};
extern "C"
{
void __cdecl hkCalcMotorData(const hkpConstraintMotor* someMotor, const hkpConstraintMotorInput* input, hkpConstraintMotorOutput* output);
}
__forceinline void __cdecl hkInternalConstraintUtils_inlineCalcRelativeAngle(
	const hkVector4& twistAxisAinWorld, const hkVector4& twistAxisBinWorld,
	const hkVector4& planeAxisAinWorld, const hkVector4& planeAxisBinWorld,
	hkVector4& axisOut, hkPadSpu<hkReal>& angleOut, hkPadSpu<hkReal>& tauMaxOut )
{
	hkVector4 twist_axis_ws;
	twist_axis_ws.setAdd4( twistAxisBinWorld , twistAxisAinWorld );
	const hkReal twist_axis_ws_length3 = twist_axis_ws.length3();
	if (twist_axis_ws_length3>1e-16f)
	{
		tauMaxOut = twist_axis_ws_length3 * 0.5f;
		twist_axis_ws.mul4(1.0f / twist_axis_ws_length3);
	}
	else
	{
		tauMaxOut = 0.0f;
		twist_axis_ws = twistAxisBinWorld;
	}
	hkRotation m_ws_us;
	{
		hkVector4& c0 = m_ws_us.getColumn(0);
		hkVector4& c1 = m_ws_us.getColumn(1);
		hkVector4& c2 = m_ws_us.getColumn(2);
		c0 = twist_axis_ws;
		c1.setCross(twist_axis_ws, planeAxisBinWorld);
		c2.setCross(c1, c0);
	}
	hkReal d1 = m_ws_us.getColumn(1).dot3( planeAxisAinWorld );
	hkReal d2 = m_ws_us.getColumn(2).dot3( planeAxisAinWorld );
	hkReal currentTwistAngle  = hkMath_atan2fApproximation( d1, d2);
	angleOut = currentTwistAngle;
	axisOut = twist_axis_ws;
}
namespace hkVector4Util
{
__forceinline void __cdecl reserveRegisters( hkUint32 registerMask );
__forceinline void __cdecl releaseRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::reserveRegisters( hkUint32 registerMask )
{
}
__forceinline void __cdecl hkVector4Util::releaseRegisters( hkUint32 registerMask )
{
}
class hkpJacobianSchema
{
	public:
		enum SchemaType
		{
			SCHEMA_TYPE_END = 0,
			SCHEMA_TYPE_HEADER,
			SCHEMA_TYPE_GOTO,
			SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,
			SCHEMA_TYPE_SIMPLE_BEGIN,
			SCHEMA_TYPE_1D_BILATERAL,
			SCHEMA_TYPE_1D_BILATERAL_USER_TAU,
			SCHEMA_TYPE_1D_LINEAR_LIMITS,
			SCHEMA_TYPE_1D_FRICTION,
			SCHEMA_TYPE_1D_LINEAR_MOTOR,
			SCHEMA_TYPE_1D_PULLEY,
			SCHEMA_TYPE_1D_ANGULAR,
			SCHEMA_TYPE_1D_ANGULAR_LIMITS,
			SCHEMA_TYPE_1D_ANGULAR_FRICTION,
			SCHEMA_TYPE_1D_ANGULAR_MOTOR,
			SCHEMA_TYPE_SINGLE_CONTACT,
			SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_PAIR_CONTACT,
			SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_2D_FRICTION,
			SCHEMA_TYPE_3D_FRICTION,
			SCHEMA_TYPE_SET_MASS,
			SCHEMA_TYPE_ADD_VELOCITY,
			SCHEMA_TYPE_SIMPLE_END,
			SCHEMA_TYPE_STIFF_SPRING_CHAIN,
			SCHEMA_TYPE_BALL_SOCKET_CHAIN,
			SCHEMA_TYPE_POWERED_CHAIN,
			SCHEMA_TYPE_MAX
		};
		static __forceinline void __cdecl setType( hkpJacobianSchema* schema, hkEnum<SchemaType, hkInt8> type )
		{
			*reinterpret_cast<hkReal*>( schema ) += 1.192092896e-07f;
			*reinterpret_cast<hkEnum<SchemaType, hkInt8>*>( schema ) = type;
		}
};
class hkpJacobianShiftSolverResultsPointerSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianShiftSolverResultsPointerSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void initShiftSolverResultsPointer( hkUint8 numSolverResultsToSkip )
		{
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER );
			m_numSolverResultsToSkip = numSolverResultsToSkip;
		}
		__forceinline int getNumSolverResults() const { return m_numSolverResultsToSkip; }
	private:
		unsigned m_padding_1;
		hkUint8 m_numSolverResultsToSkip;
		unsigned m_padding2[2];
};
class hkp2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_angular[2];
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline void setInvJacDiag( hkReal v ) { m_angular[0](3) = v; }
		inline void setAngularRhs( hkReal v ) { m_angular[1](3) = v; }
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		hkReal getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
};
class hkpJacobian1dAngularMotorSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dAngularMotorSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkp1dMotorSolverInfo& init1dAngularMotor( const hkp2AngJacobian& jac )
		{
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR );
			return m_motorSolverInfo;
		}
		hkp2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_padding[3];
};
__forceinline hkReal hkp2AngJacobian::getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const
{
	const hkp2AngJacobian& jac = *this;
	hkVector4 ang0; ang0.setMul4( jac.m_angular[0], jac.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jac.m_angular[1], jac.m_angular[1] );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	ang0.add4( ang1 );
	const hkReal eps = 1.192092896e-07f;
	const hkReal dot = ang0.horizontalAdd3();
	return dot + eps;
}
namespace hkJacobianBuilder
{
__forceinline void __cdecl buildAngularBegin( const hkpVelocityAccumulator* opaA, const hkpVelocityAccumulator* opaB, const hkVector4& direction, hkReal virtMassFactor, hkp2AngJacobian& jac )
	{
		hkVector4Util::reserveRegisters( 0xf0000000 );
		if ( opaA->m_matrixIsIdentity )
		{
			jac.m_angular[0] = direction;
		}
		else
		{
			jac.m_angular[0]._setRotatedDir( opaA->getCoreFromWorldMatrix(), direction );
		}
		if ( opaB->m_matrixIsIdentity )
		{
			jac.m_angular[1].setNeg4( direction );
		}
		else
		{
			hkVector4 negDir; negDir.setNeg4( direction );
			jac.m_angular[1]._setRotatedDir( opaB->getCoreFromWorldMatrix(), negDir );
		}
		hkReal diag = jac.getAngularDiag( *opaA, *opaB );
		jac.setInvJacDiag( virtMassFactor / diag );
	}
__forceinline void __cdecl buildAngularEnd( hkp2AngJacobian& jac, hkReal rhs, hkReal rhsFactor )
	{
		jac.setAngularRhs( rhs * rhsFactor );
		hkVector4Util::releaseRegisters( 0xf0000000 );
	}
}
static __forceinline void __cdecl _hk1dAngularVelocityMotorBeginJacobian( const hkVector4& directionOfConstraint, const hkpConstraintQueryIn &in, hkp2AngJacobian& jac, hkp1dBilateralConstraintStatus& statusOut )
{
	hkJacobianBuilder::buildAngularBegin( in.m_bodyA, in.m_bodyB, directionOfConstraint, 1.0f, jac );
	statusOut.m_virtualMass = jac.getInvJacDiag();
}
__forceinline void __cdecl _hk1dAngularVelocityMotorCommitJacobian( hkp1dConstraintMotorInfo& info, const hkpConstraintQueryIn &in, hkp2AngJacobian& jac, hkpConstraintQueryOut& out )
{
	hkJacobianBuilder::buildAngularEnd( jac, info.m_targetPosition, in.m_substepInvDeltaTime );
	hkpJacobian1dAngularMotorSchema* schema = static_cast<hkpJacobian1dAngularMotorSchema*>( static_cast<void*>( out.m_jacobianSchemas.val() ) );
	hkp1dMotorSolverInfo& motorInfo = schema->init1dAngularMotor( jac );
	motorInfo.m_maxImpulsePerSubstep = info.m_maxForce * in.m_microStepDeltaTime;
	motorInfo.m_minImpulsePerSubstep = info.m_minForce * in.m_microStepDeltaTime;
	motorInfo.m_velocity = info.m_targetVelocity;
	motorInfo.m_tau = info.m_tau;
	motorInfo.m_damping = info.m_damping;
	out.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>( schema + 1 );
}
static __forceinline void __cdecl hkSkipSolverResults( hkUint8 numSolverResultsToSkip, hkpConstraintQueryOut& out )
{
	hkpJacobianShiftSolverResultsPointerSchema* schema = reinterpret_cast<hkpJacobianShiftSolverResultsPointerSchema*>( out.m_jacobianSchemas.val() );
	schema->initShiftSolverResultsPointer( numSolverResultsToSkip );
	out.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>( schema + 1 );
}
static __forceinline void __cdecl FUN_009fac30( const hkpRagdollMotorConstraintAtom& atom, const hkpConstraintQueryIn& in, const hkTransform& baseA, const hkTransform& baseB, hkpConstraintQueryOut& out )
{
	hkUint8* initialized = static_cast<hkUint8*>( hkAddByteOffset( in.m_constraintRuntime.val(), atom.m_initializedOffset ) );
	hkReal* previousTargetAngles = static_cast<hkReal*>( hkAddByteOffset( in.m_constraintRuntime.val(), atom.m_previousTargetAnglesOffset ) );
	if ( atom.m_isEnabled )
	{
		hkMatrix3 targetFrameW;
		targetFrameW._setMul( in.m_transformB->getRotation(), atom.m_targetFrameAinB );
		hkpConstraintMotorInput motorIn;
		motorIn.m_stepInfo = &in;
		const int twistAxisIndex[3] = { 0, 1, 2 };
		const int planeAxisIndex[3] = { 1, 0, 0 };
		for ( int i = 0; i < 3; i++ )
		{
			if ( atom.m_motors[i] )
			{
				hkpConstraintMotor* motor = atom.m_motors[i];
				hkVector4 axis;
				hkPadSpu<hkReal> currentAngle;
				hkPadSpu<hkReal> targetAngle;
				hkPadSpu<hkReal> tauMax;
				hkInternalConstraintUtils_inlineCalcRelativeAngle( baseA.getColumn( twistAxisIndex[i] ), baseB.getColumn( twistAxisIndex[i] ), baseA.getColumn( planeAxisIndex[i] ), baseB.getColumn( planeAxisIndex[i] ), axis, currentAngle, tauMax );
				hkInternalConstraintUtils_inlineCalcRelativeAngle( targetFrameW.getColumn( twistAxisIndex[i] ), baseB.getColumn( twistAxisIndex[i] ), targetFrameW.getColumn( planeAxisIndex[i] ), baseB.getColumn( planeAxisIndex[i] ), axis, targetAngle, tauMax );
				if ( !initialized[i] )
				{
					previousTargetAngles[i] = currentAngle;
					initialized[i] = 1;
				}
				hkp2AngJacobian* jac = reinterpret_cast<hkp2AngJacobian*>( out.m_jacobianSchemas.val() );
				_hk1dAngularVelocityMotorBeginJacobian( axis, in, *jac, motorIn );
				motorIn.m_lastResults = static_cast<hkpSolverResults*>( in.m_constraintRuntime.val() )[i];
				motorIn.m_deltaTarget = targetAngle - previousTargetAngles[i];
				motorIn.m_positionError = previousTargetAngles[i] - currentAngle;
				hkpConstraintMotorOutput motorOut;
				hkCalcMotorData( motor, &motorIn, &motorOut );
				_hk1dAngularVelocityMotorCommitJacobian( motorOut, in, *jac, out );
				if ( previousTargetAngles[i] != targetAngle )
				{
					previousTargetAngles[i] = targetAngle;
				}
			}
			else
			{
				hkSkipSolverResults( 1, out );
			}
		}
	}
	else
	{
		hkSkipSolverResults( 3, out );
	}
}
// A STAND-IN caller, not a function of the game: it only makes the compiler emit the static FUN_009fac30 above (see the head).
void __cdecl standInCallerOfRagdollMotorAtom( const hkpConstraintAtom* atoms, const hkpConstraintQueryIn& tmpIn, hkpConstraintQueryOut& out )
{
	hkpConstraintQueryIn in = tmpIn;
	hkTransform baseA;
	hkTransform baseB;
	FUN_009fac30( *static_cast<const hkpRagdollMotorConstraintAtom*>( atoms ), in, baseA, baseB, out );
}

}  // namespace f3m_009fac30
}   // namespace f3m_009fac30

// @f3 0x009e16f0 (community match, verified in this file)
// virtual void hkpBallSocketChainData::hkpBallSocketChainData_buildJacobian(class hkpConstraintQueryIn const &,class hkpConstraintQueryOut &)  (?buildJacobian@hkpBallSocketChainData@@UAEXABVhkpConstraintQueryIn@@AAVhkpConstraintQueryOut@@@Z; Havok 5.5.0 hkpDynamics.lib / hkpBallSocketChainData.obj)
// reduced by hktrim.py from sdk.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}
namespace f3m_009e16f0 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
typedef hkUint16 hkObjectIndex;

__forceinline hkUlong __cdecl hkGetByteOffset( const void* base, const void* pntr)
{
	return hkUlong(pntr) - hkUlong(base);
}

template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}

class hkClass;

class hkBool
{
	public:
		inline hkBool(bool b)
		;
	private:
		char m_bool;
};

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};


		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void FUN_008f6d90(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> DAT_010f3170;
	return DAT_010f3170.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl FUN_00901f10(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::FUN_00901f10(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
		__forceinline hkArray(T* ptr, int size, int capacity);
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
	public:
		T m_storage[N];
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
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
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::FUN_00901f10( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T>
__forceinline void hkArray<T>::pushBackUnchecked(const T& t)
{
	m_data[m_size++] = t;
}

template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

namespace hkSmallArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
}

template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
	public:
		                class MustEndWithSemiColon;
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
};

class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_vec;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
		__forceinline const hkReal& operator() (int row, int column) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

	inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(0,1)*v1 + t(0,2)*v2 + t(0,3);
		d(1) = t(1,0)*v0 + t(1,1)*v1 + t(1,2)*v2 + t(1,3);
		d(2) = t(2,0)*v0 + t(2,1)*v1 + t(2,2)*v2 + t(2,3);
		d(3) = 0;
	}

inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}

enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};

class hkpCdVertex: public hkVector4
{
	public:
		                class MustEndWithSemiColon;
};

class hkAabb;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;

class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			                class MustEndWithSemiColon;
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				                class MustEndWithSemiColon;
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				                class MustEndWithSemiColon;
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
		hkUlong m_userData;
	public:
		hkEnum< f3m_009e16f0::hkpShapeType, hkUint32> m_type;
};

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};

class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		hkUint32 m_id;
};

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	protected:
		enum { OFFSET_INVALID = 127 };
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};

struct hkAabbUint32;

class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				                class MustEndWithSemiColon;
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};

struct hkpAgentNnEntry;

class hkpLinkedCollidable: public hkpCollidable
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		struct CollisionEntry
		{
			                class MustEndWithSemiColon;
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};

class hkMultiThreadCheck
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};

namespace hkWorldOperation
{
	enum Result
	{
		POSTPONED,
		DONE
	};
}

class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void calcStatistics( hkStatisticsCollector* collector ) const;
		virtual hkWorldOperation::Result setShape( const hkpShape* shape );
	public:
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		virtual class hkMotionState* getMotionState() = 0;
		inline virtual ~hkpWorldObject();
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
};

class hkpMaterial
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
};

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};

class hkpJacobianSchema;
class hkpVelocityAccumulator;
class hkpConstraintInstance;

struct hkpConstraintInfo
{
	                class MustEndWithSemiColon;
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
};

class hkpConstraintQueryIn;
class hkpConstraintQueryOut;
typedef void hkpConstraintRuntime;

class hkpConstraintData : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
        enum ConstraintType
        {
            CONSTRAINT_TYPE_BALLANDSOCKET = 0,
            CONSTRAINT_TYPE_HINGE = 1,
            CONSTRAINT_TYPE_LIMITEDHINGE = 2,
            CONSTRAINT_TYPE_POINTTOPATH = 3,
            CONSTRAINT_TYPE_PRISMATIC = 6,
            CONSTRAINT_TYPE_RAGDOLL = 7,
            CONSTRAINT_TYPE_STIFFSPRING = 8,
            CONSTRAINT_TYPE_WHEEL = 9,
            CONSTRAINT_TYPE_GENERIC = 10,
            CONSTRAINT_TYPE_CONTACT = 11,
            CONSTRAINT_TYPE_BREAKABLE = 12,
            CONSTRAINT_TYPE_MALLEABLE = 13,
            CONSTRAINT_TYPE_POINTTOPLANE = 14,
	        CONSTRAINT_TYPE_PULLEY = 15,
			CONSTRAINT_TYPE_ROTATIONAL = 16,
			CONSTRAINT_TYPE_HINGE_LIMITS = 18,
			CONSTRAINT_TYPE_RAGDOLL_LIMITS = 19,
			CONSTRAINT_TYPE_CUSTOM = 20,
	        BEGIN_CONSTRAINT_CHAIN_TYPES = 100,
	        CONSTRAINT_TYPE_STIFF_SPRING_CHAIN = 100,
	        CONSTRAINT_TYPE_BALL_SOCKET_CHAIN = 101,
	        CONSTRAINT_TYPE_POWERED_CHAIN = 102
        };
		inline virtual ~hkpConstraintData();
		virtual hkBool isValid() const = 0;
		virtual int getType() const = 0;
		struct RuntimeInfo
		{
			                class MustEndWithSemiColon;
			int m_sizeOfExternalRuntime;
			int m_numSolverResults;
		};
		virtual void getRuntimeInfo( hkBool wantRuntime, RuntimeInfo& infoOut ) const = 0;
		virtual hkpSolverResults* getSolverResults( hkpConstraintRuntime* runtime );
		virtual void addInstance( hkpConstraintInstance* constraint, hkpConstraintRuntime* runtime, int sizeOfRuntime ) const;
	protected:
		friend class hkpConstraintSolverSetup;
	public:
		virtual void buildJacobian( const hkpConstraintQueryIn &in, hkpConstraintQueryOut &out ) { }
		virtual hkBool isBuildJacobianCallbackRequired() const { return false; }
		virtual void buildJacobianCallback( const hkpConstraintQueryIn &in ) { }
		struct ConstraintInfo : public hkpConstraintInfo
		{
			                class MustEndWithSemiColon;
			struct hkpConstraintAtom* m_atoms;
			hkUint32		  m_sizeOfAllAtoms;
		};
		virtual void getConstraintInfo( ConstraintInfo& infoOut ) const = 0;
	public:
		hkUlong m_userData;
};

class hkpEntity;

class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
		enum AddReferences
		{
			DO_NOT_ADD_REFERENCES,
			DO_ADD_REFERENCES
		};
		enum CloningMode
		{
			CLONE_INSTANCES_ONLY,
			CLONE_DATAS_WITH_MOTORS
		};
		~hkpConstraintInstance();
	public:
		inline hkpEntity* getEntityA() const;
	public:
		virtual void entityAddedCallback(hkpEntity* entity);
		virtual void entityRemovedCallback(hkpEntity* entity);
		virtual void entityDeletedCallback( hkpEntity* entity );
		virtual InstanceType getType() const { return TYPE_NORMAL; }
	protected:
		friend class hkpSimpleContactConstraintData;
		friend class hkpSimulationIsland;
		class hkpConstraintOwner* m_owner;
		class hkpConstraintData*  m_data;
		struct hkpModifierConstraintAtom* m_constraintModifiers;
		class hkpEntity* m_entities[2];
	public:
		hkEnum<ConstraintPriority,hkUint8> m_priority;
	protected:
		hkBool				m_wantRuntime;
		const char* m_name;
	public:
		hkUlong m_userData;
		struct hkConstraintInternal* m_internal;
	private:
		friend class hkpWorldConstraintUtil;
		friend class hkpSimpleConstraintContactMgr;
		friend class hkpSaveContactPointsUtil;
};

inline hkpEntity* hkpConstraintInstance::getEntityA() const
{
	return m_entities[0];
}

class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		inline const hkTransform& getTransform() const;
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};

const hkTransform& hkMotionState::getTransform() const
{
	return m_transform;
}

class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	                class MustEndWithSemiColon;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	virtual void setPosition(const hkVector4& position);
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline const hkTransform& getTransform() const;
	virtual void setTransform(const hkTransform& transform);
	virtual void setLinearVelocity(const hkVector4& newVel);
	virtual void setAngularVelocity(const hkVector4& newVel);
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
public:
	virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
public:
	enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
};

const hkTransform& hkpMotion::getTransform() const
{
	return m_motionState.getTransform();
}

class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpKeyframedRigidMotion();
		virtual void setMass(hkReal m);
		virtual void setMassInv(hkReal mInv);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
};

class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
};

class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;

class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		virtual ~hkpEntity();
		void calcStatistics( hkStatisticsCollector* collector) const;
	public:
		inline hkpMotion* getMotion();
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				                class MustEndWithSemiColon;
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};

inline hkpMotion* hkpEntity::getMotion()
{
	return &m_motion;
}

struct hkpConstraintAtom
{
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum AtomType
		{
			TYPE_INVALID = 0,
			TYPE_BRIDGE,
			TYPE_SET_LOCAL_TRANSFORMS,
			TYPE_SET_LOCAL_TRANSLATIONS,
			TYPE_SET_LOCAL_ROTATIONS,
			TYPE_BALL_SOCKET,
			TYPE_STIFF_SPRING,
			TYPE_LIN,
			TYPE_LIN_SOFT,
			TYPE_LIN_LIMIT,
			TYPE_LIN_FRICTION,
			TYPE_LIN_MOTOR,
			TYPE_2D_ANG,
			TYPE_ANG,
			TYPE_ANG_LIMIT,
			TYPE_TWIST_LIMIT,
			TYPE_CONE_LIMIT,
			TYPE_ANG_FRICTION,
			TYPE_ANG_MOTOR,
			TYPE_RAGDOLL_MOTOR,
			TYPE_PULLEY,
			TYPE_OVERWRITE_PIVOT,
			TYPE_CONTACT,
			TYPE_MODIFIER_SOFT_CONTACT,
			TYPE_MODIFIER_MASS_CHANGER,
			TYPE_MODIFIER_VISCOUS_SURFACE,
			TYPE_MODIFIER_MOVING_SURFACE,
			TYPE_MODIFIER_IGNORE_CONSTRAINT,
			TYPE_MAX
		};
		enum CallbackRequest
		{
			CALLBACK_REQUEST_NONE = 0,
			CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
			CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
			CALLBACK_REQUEST_SETUP_CALLBACK = 4
		};
	public:
		hkEnum<AtomType,hkUint16> m_type;
};

typedef void (__cdecl *hkConstraintAtomBuildJacobianFunc) ( class hkpConstraintData* m_constraintData, const hkpConstraintQueryIn &in, hkpConstraintQueryOut &out );

struct hkpBridgeConstraintAtom: public hkpConstraintAtom
{
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkConstraintAtomBuildJacobianFunc       m_buildJacobianFunc;
	class hkpConstraintData* m_constraintData;
};

struct hkpBridgeAtoms
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	                class MustEndWithSemiColon;
	struct hkpBridgeConstraintAtom m_bridgeAtom;
};

class hkpConstraintChainData : public hkpConstraintData
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual int getNumConstraintInfos() = 0;
};

class hkpBallSocketChainData : public hkpConstraintChainData
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		~hkpBallSocketChainData();
		hkBool isValid() const { return true; }
 		virtual int getType() const;
		virtual int getNumConstraintInfos() { return m_infos.getSize(); }
	public:
		struct Runtime
		{
		};
	public:
		virtual void hkpBallSocketChainData_buildJacobian( const hkpConstraintQueryIn &in, hkpConstraintQueryOut &out );
		virtual void getConstraintInfo( hkpConstraintData::ConstraintInfo& info ) const;
		virtual void getRuntimeInfo( hkBool wantRuntime, hkpConstraintData::RuntimeInfo& infoOut ) const;
	public:
		struct hkpBridgeAtoms m_atoms;
		struct ConstraintInfo
		{
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkVector4 m_pivotInA;
			hkVector4 m_pivotInB;
		};
		hkArray<struct ConstraintInfo> m_infos;
		hkReal m_tau;
		hkReal m_damping;
		hkReal m_cfm;
		hkReal m_maxErrorDistance;
};

class hkpConstraintChainInstanceAction;

class hkpConstraintChainInstance : public hkpConstraintInstance
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		~hkpConstraintChainInstance();
		virtual void entityRemovedCallback(hkpEntity* entity);
		virtual InstanceType getType() const { return TYPE_CHAIN; }
		hkArray<hkpEntity*> m_chainedEntities;
		hkpConstraintChainInstanceAction* m_action;
};

class hkpConstraintQueryStepInfo
{
	public:
		                class MustEndWithSemiColon;
		__declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
		hkPadSpu<float>		m_microStepDeltaTime;
		hkPadSpu<float>		m_substepInvDeltaTime;
		hkPadSpu<float>		m_frameDeltaTime;
		hkPadSpu<float>		m_frameInvDeltaTime;
		hkPadSpu<float>		m_invNumSteps;
		hkPadSpu<float>		m_invNumStepsTimesMicroSteps;
		hkPadSpu<float>		m_rhsFactor;
		hkPadSpu<float>		m_virtMassFactor;
		hkPadSpu<float> m_frictionRhsFactor;
};

class hkpConstraintQueryIn: public hkpConstraintQueryStepInfo
{
	public:
		                class MustEndWithSemiColon;
		__declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
		hkPadSpu<const hkpVelocityAccumulator*>	m_bodyB;
		hkPadSpu<const hkTransform*>	m_transformA;
		hkPadSpu<const hkTransform*>	m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<class hkpConstraintInstance*>	m_constraintInstance;
		hkPadSpu<void*>	m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
};

class  hkpConstraintQueryOut
{
	public:
		                class MustEndWithSemiColon;
		hkPadSpu<hkpJacobianSchema*> m_jacobianSchemas;
};

class hkp1Lin2AngJacobian;

class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline hkpVelocityAccumulatorOffset() {}
		__forceinline hkpVelocityAccumulatorOffset( const hkpVelocityAccumulator* accum, const hkpVelocityAccumulator* base )
		{
			m_offset = hkGetByteOffset( base, accum );
		}
		hkUint32 m_offset;
};

extern "C"
{
	void __cdecl FUN_009fcb10( const hkpConstraintQueryIn& in, hkpConstraintQueryOut& out, hkpSolverResults* sr, int solverResultStriding );
	hkp1Lin2AngJacobian* __cdecl FUN_00a523e0( hkpJacobianSchema* schema );
	void __cdecl FUN_00a4e400( const hkpConstraintQueryIn& in );
	void __cdecl FUN_00a4fe70( const hkVector4& posA, const hkVector4& posB, hkReal maxAllowedError, const hkpConstraintQueryIn& in, hkp1Lin2AngJacobian* jac );
	void __cdecl FUN_00a51540( int numConstraints, hkReal tau, hkReal damping, hkReal cfm, hkpVelocityAccumulatorOffset* accumulators, const hkpVelocityAccumulator* baseAccum, hkp1Lin2AngJacobian* jacobians, const hkpConstraintQueryIn& in, hkpConstraintQueryOut& out );
}

// pdb: hkpBallSocketChainData::buildJacobian | hkpBallSocketChainData.obj | fnv360_0721_retail, objrun + bridge(caller_sim|vtable) + skyrim(caller_sim), high
void hkpBallSocketChainData::hkpBallSocketChainData_buildJacobian( const hkpConstraintQueryIn &inChain, hkpConstraintQueryOut &out )
{
	hkpSolverResults* solverResults = static_cast<hkpSolverResults*>( inChain.m_constraintRuntime.val() );
	FUN_009fcb10( inChain, out, solverResults, sizeof(hkpSolverResults) );
	hkpConstraintQueryIn newIn = inChain;
	newIn.m_constraintInstance = 0;
	newIn.m_constraintRuntime = 0;
	hkInplaceArray<hkpVelocityAccumulatorOffset,32> accumulators;
	{
		hkpConstraintChainInstance* chainInstance;
		const hkpVelocityAccumulator* baseAccum;
		{
			chainInstance = reinterpret_cast<hkpConstraintChainInstance*>( inChain.m_constraintInstance.val() );
			const hkpEntity* chainCA = chainInstance->getEntityA();
			baseAccum = hkAddByteOffsetConst( inChain.m_bodyA.val(), -int(chainCA->m_solverData) );
		}
		const hkArray<hkpEntity*>& entities = chainInstance->m_chainedEntities;
		int numConstraints = entities.getSize() - 1;
		hkpEntity* rB = entities[0];
		hkpMotion* cB = rB->getMotion();
		newIn.m_bodyB = hkAddByteOffsetConst( baseAccum, rB->m_solverData );
		accumulators.pushBackUnchecked( hkpVelocityAccumulatorOffset( newIn.m_bodyB, baseAccum ) );
		newIn.m_transformB = &cB->getTransform();
		newIn.m_rhsFactor = newIn.m_substepInvDeltaTime;
		newIn.m_virtMassFactor = 1.0f;
		hkp1Lin2AngJacobian* jacobiansBase = FUN_00a523e0( out.m_jacobianSchemas );
		hkp1Lin2AngJacobian* jacobians = jacobiansBase;
		for (int i = 0; i < numConstraints; i++)
		{
			newIn.m_bodyA = newIn.m_bodyB;
			newIn.m_transformA = newIn.m_transformB;
			rB = entities[i+1];
			cB = rB->getMotion();
			newIn.m_bodyB = hkAddByteOffsetConst( baseAccum, rB->m_solverData );
			accumulators.pushBack( hkpVelocityAccumulatorOffset( newIn.m_bodyB, baseAccum ) );
			newIn.m_transformB = &cB->getTransform();
			hkVector4 posA; posA._setTransformedPos( *newIn.m_transformA, m_infos[i].m_pivotInA );
			hkVector4 posB; posB._setTransformedPos( *newIn.m_transformB, m_infos[i].m_pivotInB );
			FUN_00a4e400( newIn );
			FUN_00a4fe70( posA, posB, m_maxErrorDistance, newIn, jacobians );
			jacobians = hkAddByteOffset( jacobians, 0x90 );
		}
		FUN_00a51540( numConstraints, m_tau, m_damping, m_cfm, accumulators.begin(), baseAccum, jacobians, inChain, out );
	}
}
}
