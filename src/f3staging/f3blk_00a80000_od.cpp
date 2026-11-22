// src/f3staging/f3blk_00a80000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a9cb50 (community match, verified in this file)
extern int DAT_010f3364;
namespace f3m_00a9cb50 {
namespace Mopp1964 {extern char str_00e85ef0[],str_00e8918c[];
struct __declspec(align(8)) MoppState
{

    unsigned int primitiveOffset;

    unsigned int properties[1];
};

struct MoppResults
{

    unsigned int* data;

    int size;

    int capacityAndFlags;
};

struct HavokMemory
{

    void* router;

    void* temporary;

    void* heap;

    void* debug;

    void* allocator;
};

extern void __cdecl FUN_00901f10(void*, int);

struct MoppErrorStream
{

    void* vtable;

    unsigned short memorySizeAndFlags;

    unsigned short referenceCount;

    void* writer;

    void FUN_00923070(char*, int);

    void FUN_00943710(const char*);

    void FUN_00943a60();
};

struct MoppError
{

    virtual void destroy();

    virtual void SetErrorCodeEnabled(int, bool);

    virtual bool isEnabled(int);

    virtual int message(int, int, const char*, const char*, int);
};


struct MoppFindAllVirtualMachine
{

    MoppResults* results;

    void FUN_00a9cb50(const MoppState* state, const unsigned char* code);
};

// @fnv 0x00e66600
// pdb: hkpMoppFindAllVirtualMachine::queryOnTreeLeft | hkpMoppFindAllVirtualMachine.obj | tesv_win, objopen_prop, low
void MoppFindAllVirtualMachine::FUN_00a9cb50(const MoppState* state, const unsigned char* code)

{

    MoppState localState;

    unsigned int primitive;

    for (;;)
    {

        unsigned int command = *code;

        switch (command)
        {

        case 0:
            return;

        case 1:
        case 2:
        case 3:
        case 4:

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

            code += 4;
            continue;

        case 0x23:
        case 0x24:
        case 0x25:

            code += (code[3] << 8) + code[4] + 7;
            continue;

        case 0x29:
        case 0x2a:
        case 0x2b:

            code += 7;
            continue;

        case 5:

            code += code[1] + 2;
            continue;

        case 6:

            code += (code[1] << 8) + code[2] + 3;
            continue;

        case 7:

            code += ((code[1] << 8) + code[2] << 8) + code[3] + 4;
            continue;

        case 9:

        {

            unsigned int offset = code[1];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.primitiveOffset += offset;

            code += 2;
            continue;
        }

        case 10:

        {

            unsigned int offset = (code[1] << 8) + code[2];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.primitiveOffset += offset;

            code += 3;
            continue;
        }

        case 11:

        {

            unsigned int offset = ((((code[1] << 8) + code[2]) << 8) + code[3] << 8) + code[4];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.primitiveOffset = offset;

            code += 5;
            continue;
        }

        case 0x20:
        case 0x21:
        case 0x22:
        case 0x26:
        case 0x27:
        case 0x28:

            code += 3;
            continue;

        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:

        {

            unsigned int value = code[1];

            code += 2;

            localState.properties[command - 0x60] = value;

            goto property;
        }

        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:

            localState.properties[command - 0x64] = (code[1] << 8) + code[2];

            code += 3;
            goto property;

        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:

            localState.properties[command - 0x68] = ((((code[1] << 8) + code[2]) << 8) + code[3] << 8) + code[4];

            code += 5;

        property:

        {

            unsigned int propertyValue = localState.properties[0];

            if (state != &localState)
            {
                localState = *state;
                state = &localState;
            }

            localState.properties[0] = propertyValue;

            continue;
        }

        default:

        {

            char buffer[512];

            MoppErrorStream stream;

            stream.FUN_00923070(buffer, sizeof(buffer));

            stream.FUN_00943710(
                str_00e85ef0);

            reinterpret_cast<MoppError*>(DAT_010f3364)->message(3,0x1298fedd,buffer,str_00e8918c,305);

            stream.FUN_00943a60();

            continue;
        }

        case 0x50:

            primitive = code[1];
            goto append;

        case 0x51:

            primitive = (code[1] << 8) + code[2];
            goto append;

        case 0x52:

            primitive = ((code[1] << 8) + code[2] << 8) + code[3];
            goto append;

        case 0x53: {
            primitive = code[1] << 24;
            unsigned int part = code[2] << 16;
            primitive += part;
            part = code[3];
            primitive = code[4] + primitive;
            part <<= 8;
            primitive += part;
            goto append;
        }
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

            primitive = command - 0x30;
            goto append;
        }
    }

append:

    primitive += state->primitiveOffset;

    MoppResults* output = results;



    if (output->size == (output->capacityAndFlags & 0x3fffffff))

        FUN_00901f10(output, sizeof(unsigned int));

    unsigned int* dest = output->data + output->size;

    ++output->size;

    *dest = primitive;
}

}
}   // namespace f3m_00a9cb50

// @f3 0x00a92560 (community match, verified in this file)
#include <math.h>
extern const double DAT_00e80570;
namespace f3m_00a92560 {
struct __declspec(align(16)) V925 { float x,y,z,w; void setAbs(const V925& a) {x=(float)fabs(a.x);y=(float)fabs(a.y);z=(float)fabs(a.z);w=(float)fabs(a.w);} void setAdd(const V925& a,const V925& b) {x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;} void add(const V925& a) {x=a.x+x;y=a.y+y;z=a.z+z;w=a.w+w;} void setAll(float a) {x=a;y=a;z=a;w=a;} void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;} void FUN_00a93000(const void*,const V925*); };
struct __declspec(align(16)) M925 { V925 x,y,z,w;
__forceinline void transpose(const V925& a,const V925& b,const V925& c,const V925& d) {
x.set(a.x,b.x,c.x,d.x);y.set(a.y,b.y,c.y,d.y);z.set(a.z,b.z,c.z,d.z);w.set(a.w,b.w,c.w,d.w);
} };
struct Pair925 { V925 zero,radius; };
struct C925 { int unk00,unk04,unk08,unk0c; V925 unk10; const unsigned char* unk20; };
struct In925 { int count; const V925* vertices; };
struct Out925 { int unk00,unk04,unk08,unk0c,unk10,unk14; Out925() {unk08=0;unk0c=0;unk10=0;unk14=16;unk00=0;unk04=0;} };
struct __declspec(align(16)) State925 {
 void* unk00; int unk04,unk08,unk0c; float unk10; int unk14,unk18,unk1c;
 void* unk20; int unk24,unk28,unk2c; int count; int unk34,unk38,unk3c;
 M925 blocks[8]; M925 absolute[8];
 void FUN_00a93090(Out925*,const unsigned char*,const Pair925*);
};
// pdb: hkMoppUsingFloatAabbVirtualMachine_queryPlanes | hkpMoppMachine.obj | tesv_win, objopen_prop, low
void FUN_00a92560(C925* context,In925* input,void* output,void* work) {
 const unsigned char* program=context->unk20;
 State925 state;
 state.unk00=output;
 state.unk10=1.0f/context->unk10.w;
 Out925 result;
 int n=input->count;
 const V925* src=input->vertices;
 M925* dst=state.blocks;
 state.count=0;
 Pair925 bounds; bounds.zero.x=bounds.zero.y=bounds.zero.z=bounds.zero.w=0.0f;
 bounds.radius.setAll((float)(state.unk10*DAT_00e80570));
 int bulk=n&~3;
 int i=0;
 for(; i<bulk; i+=4,++dst,src+=4) {
  dst->transpose(src[0],src[1],src[2],src[3]);
  ++state.count;
 }
 const V925* b=src+1; const V925* c=src+2; const V925* d=src+3;
 switch(n-i) {case 1:b=src; case 2:c=src; case 3:d=src;
  dst->transpose(*src,*b,*c,*d);
  ++dst;++state.count;
 }
 M925* abs=state.absolute+state.count-1;
 --dst;
 for(;dst>=state.blocks;--dst,--abs) {
  abs->x.setAbs(dst->x);
  abs->y.setAbs(dst->y);
  abs->z.setAbs(dst->z);
  abs->w.x=abs->w.y=abs->w.z=abs->w.w=0.0f;
  V925 adjustment; adjustment.FUN_00a93000(dst,&context->unk10);
  dst->w.setAdd(dst->w,adjustment);
  dst->w.add(dst->w);
 }
 state.unk20=work;
 state.FUN_00a93090(&result,program,&bounds);
}
}   // namespace f3m_00a92560

// @f3 0x00a93090 (community match, verified in this file)
extern "C" void __cdecl FUN_00901f10(void* arr, int elemSize);

class hkOstreamD734
{
public:
    void* m_vftable;
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    void* m_writer;

    void FUN_00cb1600(void* buf, int size);
    hkOstreamD734& FUN_00cc01c0(const char* str);
    void FUN_00cc00e0();
};

class hkErrorD734
{
public:
    virtual ~hkErrorD734();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int message(int m, int id, const char* description, const char* file, int line);
};

extern hkErrorD734* DAT_01268360;

class Vector4Comparison
{
public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_ZW = 3,
        MASK_Y = 4,
        MASK_YW = 5,
        MASK_YZ = 6,
        MASK_YZW = 7,
        MASK_X = 8,
        MASK_XW = 9,
        MASK_XZ = 10,
        MASK_XZW = 11,
        MASK_XY = 12,
        MASK_XYW = 13,
        MASK_XYZ = 14,
        MASK_XYZW = 15
    };

    __forceinline int getMask() const { return m_mask; }

    int m_mask;
};

class Matrix3;
class Transform;

__declspec(align(16)) class Vector4
{
public:
    float x;
    float y;
    float z;
    float w;

    Vector4() {}

    __forceinline float& operator()(int i)
    {
        return (&x)[i];
    }

    __forceinline const float& operator()(int i) const
    {
        return (&x)[i];
    }

    __forceinline void operator=(const Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline void setAdd4(const Vector4& v0, const Vector4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    __forceinline void setSub4(const Vector4& v0, const Vector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline Vector4Comparison compareLessThanZero4() const
    {
        Vector4Comparison ret;
        ret.m_mask =
            ((x < 0) ? Vector4Comparison::MASK_X : 0) |
            ((y < 0) ? Vector4Comparison::MASK_Y : 0) |
            ((z < 0) ? Vector4Comparison::MASK_Z : 0) |
            ((w < 0) ? Vector4Comparison::MASK_W : 0);
        return ret;
    }

    void FUN_00a93000(const Matrix3& t, const Vector4& v);
    __forceinline void _setMul4xyz1(const Transform& t, const Vector4& v);
};

class Matrix3
{
public:
    Vector4 m_col0;
    Vector4 m_col1;
    Vector4 m_col2;

    __forceinline Vector4& getColumn(int x)
    {
        return (&m_col0)[x];
    }

    __forceinline const Vector4& getColumn(int x) const
    {
        return (&m_col0)[x];
    }

    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }

    __forceinline const float& operator()(int r, int c) const
    {
        return getColumn(c)(r);
    }
};

class Rotation : public Matrix3
{
};

class Transform
{
public:
    Rotation m_rotation;
    Vector4 m_translation;

    __forceinline const Rotation& getRotation() const
    {
        return m_rotation;
    }

    __forceinline float& operator()(int r, int c)
    {
        return m_rotation(r, c);
    }

    __forceinline const float& operator()(int r, int c) const
    {
        return m_rotation(r, c);
    }
};

__forceinline void Vector4::_setMul4xyz1(const Transform& t, const Vector4& v)
{
    float v0 = v(0);
    float v1 = v(1);
    float v2 = v(2);
    Vector4& d = *this;
    d(0) = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    d(1) = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    d(2) = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    d(3) = t(3, 0) * v0 + t(3, 1) * v1 + t(3, 2) * v2 + t(3, 3);
}

class Aabb
{
public:
    Aabb() {}
    Vector4 m_min;
    Vector4 m_max;
};

struct PrimitiveInfo
{
    unsigned int ID;
};

struct PrimitiveArray
{
    PrimitiveInfo* m_data;
    int m_size;
    int m_capacityAndFlags;

    PrimitiveInfo& expandOne()
    {
        if (m_size == (m_capacityAndFlags & 0x3FFFFFFF))
        {
            FUN_00901f10(this, sizeof(PrimitiveInfo));
        }
        PrimitiveInfo& result = m_data[m_size];
        m_size++;
        return result;
    }
};

class MoppVirtualMachine
{
public:
    PrimitiveArray* m_primitives_out;
    int m_pad0;
    int m_pad1;
    int m_pad2;

    void addHit(unsigned int id, const unsigned int* properties)
    {
        m_primitives_out->expandOne().ID = id;
    }

    static int read24(const unsigned char* PC)
    {
        return (PC[0] << 16) + (PC[1] << 8) + PC[2];
    }
};

struct FindAllQuery
{
    unsigned int m_primitiveOffset;
    unsigned int m_properties[1];
};

class S_00e65ee0_Class : public MoppVirtualMachine
{
public:
    void FUN_00e65ee0(int* query, int PC);
};

class MoppQueryObject : public S_00e65ee0_Class
{
public:
    enum CheckCollisionResult
    {
        HK_NO_HIT = 0,
        HK_INCLUDED = 1,
        HK_HIT = 2
    };
};

class PlanesQueryObject : public MoppQueryObject
{
public:
    int m_numTransforms;
    int m_align0;
    int m_align1;
    int m_align2;
    Transform m_rotatedPlanes0;
    Transform m_rotatedPlanes1;
    Transform m_rotatedPlanes2;
    Transform m_rotatedPlanes3;
    Transform m_rotatedPlanes4;
    Transform m_rotatedPlanes5;
    Transform m_rotatedPlanes6;
    Transform m_rotatedPlanes7;
    Transform m_absRotPlanes0;
    Transform m_absRotPlanes1;
    Transform m_absRotPlanes2;
    Transform m_absRotPlanes3;
    Transform m_absRotPlanes4;
    Transform m_absRotPlanes5;
    Transform m_absRotPlanes6;
    Transform m_absRotPlanes7;

    __forceinline CheckCollisionResult checkCollision(const Aabb& aabb, const FindAllQuery* query, const unsigned char* commands)
    {
        int inBits = 0x0f;
        const Transform* rotPlanes = &m_rotatedPlanes0;
        const Transform* absPlanes = &m_absRotPlanes0;

        Vector4 center2;
        center2.setAdd4(aabb.m_min, aabb.m_max);
        Vector4 extents2;
        extents2.setSub4(aabb.m_max, aabb.m_min);

        for (int i = m_numTransforms - 1; i >= 0; i--)
        {
            Vector4 absDiagDist;
            absDiagDist.FUN_00a93000(absPlanes->getRotation(), extents2);
            Vector4 centerDistToPlanes;
            centerDistToPlanes._setMul4xyz1(*rotPlanes, center2);
            Vector4 outDist;
            outDist.setSub4(centerDistToPlanes, absDiagDist);
            Vector4 inDist;
            inDist.setAdd4(centerDistToPlanes, absDiagDist);

            int outBits = outDist.compareLessThanZero4().getMask();
            if (outBits != 0x0f)
            {
                return HK_NO_HIT;
            }
            inBits &= inDist.compareLessThanZero4().getMask();

            rotPlanes++;
            absPlanes++;
        }

        if (inBits == 0x0f)
        {
            FUN_00e65ee0((int*)query, (int)commands);
            return HK_INCLUDED;
        }
        return HK_HIT;
    }
};

struct FloatAabbQueryInt : public FindAllQuery
{
    int m_offset_x;
    int m_offset_y;
    int m_offset_z;
    int m_shift;
};

struct TempAabb
{
    Aabb m_aabb;
};

class FloatAabbVirtualMachine : public MoppVirtualMachine
{
public:
    float m_ItoFScale;
    int m_align0;
    int m_align1;
    int m_align2;
    PlanesQueryObject m_queryObject;

    void FUN_00a93090(const FloatAabbQueryInt* query, const unsigned char* PC, TempAabb& fQueryL);
};

void FloatAabbVirtualMachine::FUN_00a93090(const FloatAabbQueryInt* query, const unsigned char* PC, TempAabb& fQueryL)
{
    FloatAabbQueryInt scaledQuery;
    while (true)
    {
        int command = *PC;
        TempAabb fQueryR;
        int offseth;
        int offsetl;

        switch (command)
        {
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
            offseth = PC[3];
            PC += 4;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            FUN_00a93090(query, PC, fQueryR);
            PC += offseth;
            break;

        case 0x10:
        case 0x11:
        case 0x12:
        {
            int tdir = command - 0x10;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offseth = PC[1];
            offsetl = PC[2];
            fQueryL.m_aabb.m_max(tdir) = ((offseth << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryR.m_aabb.m_min(tdir) = ((offsetl << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            offsetl = 0;
            offseth = PC[3];
            PC += 4;
            goto do_compare;
        }

        case 0x20:
        case 0x21:
        case 0x22:
        {
            int tdir = command - 0x20;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offsetl = PC[1];
            offseth = offsetl + 1;
            offsetl <<= query->m_shift;
            offseth <<= query->m_shift;
            offsetl += (&query->m_offset_x)[tdir];
            offseth += (&query->m_offset_x)[tdir];
            fQueryR.m_aabb.m_min(tdir) = offsetl * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = offseth * m_ItoFScale;
            offsetl = 0;
            offseth = PC[2];
            PC += 3;
            goto do_compare;
        }

        case 0x23:
        case 0x24:
        case 0x25:
        {
            int tdir = command - 0x23;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offseth = PC[1];
            offsetl = PC[2];
            fQueryL.m_aabb.m_max(tdir) = ((offseth << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryR.m_aabb.m_min(tdir) = ((offsetl << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            offsetl = (PC[3] << 8) + PC[4];
            offseth = (PC[5] << 8) + PC[6];
            PC += 7;
        do_compare:
            while (true)
            {
                int c = PC[offsetl];
                if (c < 0x26 || c > 0x2b)
                {
                    break;
                }
                if (c >= 0x29)
                {
                    int tdir = c - 0x29;
                    fQueryL.m_aabb.m_min(tdir) = read24(PC + offsetl + 1) * m_ItoFScale;
                    fQueryL.m_aabb.m_max(tdir) = read24(PC + offsetl + 4) * m_ItoFScale;
                    offsetl += 7;
                }
                else
                {
                    int tdir = c - 0x26;
                    fQueryL.m_aabb.m_min(tdir) = ((PC[offsetl + 1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    fQueryL.m_aabb.m_max(tdir) = ((PC[offsetl + 2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    offsetl += 3;
                }
            }
            while (true)
            {
                int c = PC[offseth];
                if (c < 0x26 || c > 0x2b)
                {
                    break;
                }
                if (c >= 0x29)
                {
                    int tdir = c - 0x29;
                    fQueryR.m_aabb.m_min(tdir) = read24(PC + offseth + 1) * m_ItoFScale;
                    fQueryR.m_aabb.m_max(tdir) = read24(PC + offseth + 4) * m_ItoFScale;
                    offseth += 7;
                }
                else
                {
                    int tdir = c - 0x26;
                    fQueryR.m_aabb.m_min(tdir) = ((PC[offseth + 1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    fQueryR.m_aabb.m_max(tdir) = ((PC[offseth + 2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    offseth += 3;
                }
            }
            {
                MoppQueryObject::CheckCollisionResult checkRight = m_queryObject.checkCollision(fQueryR.m_aabb, query, PC + offseth);
                MoppQueryObject::CheckCollisionResult checkLeft = m_queryObject.checkCollision(fQueryL.m_aabb, query, PC + offsetl);
                if (checkRight != MoppQueryObject::HK_HIT)
                {
                    if (checkLeft != MoppQueryObject::HK_HIT)
                    {
                        goto end_of_function;
                    }
                    PC += offsetl;
                    break;
                }
                if (checkLeft != MoppQueryObject::HK_HIT)
                {
                    fQueryL.m_aabb.m_min = fQueryR.m_aabb.m_min;
                    fQueryL.m_aabb.m_max = fQueryR.m_aabb.m_max;
                    PC += offseth;
                    break;
                }
                FUN_00a93090(query, PC + offseth, fQueryR);
                PC += offsetl;
                break;
            }
        }

        case 0x29:
        case 0x2a:
        case 0x2b:
        {
            int tdir = command - 0x29;
            fQueryL.m_aabb.m_min(tdir) = read24(PC + 1) * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = read24(PC + 4) * m_ItoFScale;
            PC += 7;
            goto doCut;
        }

        case 0x26:
        case 0x27:
        case 0x28:
        {
            int tdir = command - 0x26;
            fQueryL.m_aabb.m_min(tdir) = ((PC[1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = ((PC[2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            PC += 3;
        doCut:
            if (PC[0] >= 0x26 && PC[0] <= 0x2b)
            {
                continue;
            }
            {
                MoppQueryObject::CheckCollisionResult result = m_queryObject.checkCollision(fQueryL.m_aabb, query, PC);
                if (result == MoppQueryObject::HK_HIT)
                {
                    continue;
                }
                else
                {
                    goto end_of_function;
                }
            }
        }

        case 0x05:
            offsetl = PC[1];
            PC += 2;
            PC += offsetl;
            break;

        case 0x06:
            offseth = PC[1];
            offsetl = PC[2];
            PC += 3;
            PC += (offseth << 8) + offsetl;
            break;

        case 0x07:
        {
            offseth = PC[1];
            const int offsetm = PC[2];
            offsetl = PC[3];
            PC += 4;
            PC += (offseth << 16) + (offsetm << 8) + offsetl;
            break;
        }

        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
        {
            const int shift = command;
            scaledQuery.m_offset_x = (PC[1] << query->m_shift) + query->m_offset_x;
            scaledQuery.m_offset_y = (PC[2] << query->m_shift) + query->m_offset_y;
            scaledQuery.m_offset_z = (PC[3] << query->m_shift) + query->m_offset_z;
            scaledQuery.m_shift = query->m_shift - shift;
            for (int p = 0; p < 1; p++)
            {
                scaledQuery.m_properties[p] = query->m_properties[p];
            }
            scaledQuery.m_primitiveOffset = query->m_primitiveOffset;
            query = &scaledQuery;
            PC += 4;
            break;
        }

        case 0x09:
        {
            const int offset = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset += offset;
            PC += 2;
            break;
        }

        case 0x0a:
        {
            const int offset = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset += offset;
            PC += 3;
            break;
        }

        case 0x0b:
        {
            const int offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset = offset;
            PC += 5;
            break;
        }

        case 0x00:
            goto end_of_function;

        case 0x50:
            offsetl = PC[1];
            goto add_Terminal;

        case 0x51:
            offseth = PC[1];
            offseth <<= 8;
            offsetl = PC[2];
            offsetl += offseth;
            goto add_Terminal;

        case 0x52:
            offsetl = PC[1];
            offsetl <<= 16;
            offseth = PC[2];
            offseth <<= 8;
            offseth += PC[3];
            offsetl += offseth;
            goto add_Terminal;

        case 0x53:
            offsetl = PC[1];
            offsetl <<= 24;
            offseth = PC[2];
            offseth <<= 16;
            offsetl += offseth;
            offseth = PC[3];
            offsetl += PC[4];
            offseth <<= 8;
            offsetl += offseth;
            goto add_Terminal;

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
            offsetl = command - 0x30;
        add_Terminal:
            offsetl += query->m_primitiveOffset;
            addHit(offsetl, query->m_properties);
            goto end_of_function;

        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        {
            unsigned int property = PC[0] - 0x60;
            unsigned int value = PC[1];
            PC += 2;
            scaledQuery.m_properties[property] = value;
        propertyCopy:
            const int v = scaledQuery.m_properties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_properties[0] = v;
            break;
        }

        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        {
            const int property = PC[0] - 0x64;
            const int value = (PC[1] << 8) + PC[2];
            scaledQuery.m_properties[property] = value;
            PC += 3;
            goto propertyCopy;
        }

        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
        {
            const int property = PC[0] - 0x68;
            const int value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            scaledQuery.m_properties[property] = value;
            PC += 5;
            goto propertyCopy;
        }

        default:
        {
            char assertBuf[512];
            hkOstreamD734 ostr;
            ostr.FUN_00cb1600(assertBuf, 512);
            ostr.FUN_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
            DAT_01268360->message(3, 0x1298fedd, assertBuf, "s:\\Build\\code\\Complete\\Source\\Physics/Internal/Collide/Mopp/Machine/hkpMoppUsingFloatAabbVirtualMachine.inl", 0x12d);
            ostr.FUN_00cc00e0();
            break;
        }
        }
    }
end_of_function:
    ;
}

// @f3 0x00a96780 (community match, verified in this file)
extern char str_00e85ef0[], str_00e88d78[];
#include <string.h>
#include <math.h>
namespace f3m_00a96780 {

struct __declspec(align(8)) MoppState {
    unsigned int terminalBase;
    unsigned int properties[1];
    int origin[3];
    int shift;
    void SetProperty(unsigned int index, int value) {
        unsigned char* const base = reinterpret_cast<unsigned char*>(this);
        memcpy(base + sizeof(int) * (1 + index), &value, sizeof(value));
    }
};

struct __declspec(align(16)) MoppVector {
    float v[4];
    __forceinline void setAdd(const MoppVector& a, const MoppVector& b) {
        v[0] = a.v[0] + b.v[0];
        v[1] = a.v[1] + b.v[1];
        v[2] = a.v[2] + b.v[2];
        v[3] = a.v[3] + b.v[3];
    }
    __forceinline void setSub(const MoppVector& a, const MoppVector& b) {
        v[0] = a.v[0] - b.v[0];
        v[1] = a.v[1] - b.v[1];
        v[2] = a.v[2] - b.v[2];
        v[3] = a.v[3] - b.v[3];
    }
    __forceinline void sub(const MoppVector& a) {
        v[0] -= a.v[0]; v[1] -= a.v[1]; v[2] -= a.v[2]; v[3] -= a.v[3];
    }
    __forceinline void setAbs(const MoppVector& a) {
        v[0] = (float)fabs(a.v[0]);
        v[1] = (float)fabs(a.v[1]);
        v[2] = (float)fabs(a.v[2]);
        v[3] = (float)fabs(a.v[3]);
    }
    __forceinline void setMin(const MoppVector& a, const MoppVector& b) {
        v[0] = a.v[0] < b.v[0] ? a.v[0] : b.v[0];
        v[1] = a.v[1] < b.v[1] ? a.v[1] : b.v[1];
        v[2] = a.v[2] < b.v[2] ? a.v[2] : b.v[2];
        v[3] = a.v[3] < b.v[3] ? a.v[3] : b.v[3];
    }
    __forceinline float lengthSquared() const {
        return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
    }
};

struct __declspec(align(16)) MoppBox {
    float low[4];
    float high[4];
    __forceinline MoppBox& operator=(const MoppBox& a) {
        low[0]=a.low[0]; low[1]=a.low[1]; low[2]=a.low[2]; low[3]=a.low[3];
        high[0]=a.high[0]; high[1]=a.high[1]; high[2]=a.high[2]; high[3]=a.high[3];
        return *this;
    }
};

struct MoppOutput;
struct MoppFindAllBase {
    MoppOutput* output;
    void FUN_00a9cb50(const MoppState*, const unsigned char*);
    void FUN_00a9c7f0(const MoppState*, const unsigned char*);
};
struct MoppSphere : MoppFindAllBase {
    int unk04; int unk08; int unk0c;
    MoppVector centerRadius;

    __forceinline int test(const MoppBox& box, const MoppState* state, const unsigned char* code) {
        MoppVector center, extent, minimum, nearest, farthest;
        center.setAdd(*(const MoppVector*)box.low, *(const MoppVector*)box.high);
        extent.setSub(*(const MoppVector*)box.high, *(const MoppVector*)box.low);
        center.sub(centerRadius);
        center.setAbs(center);
        minimum.setMin(center, extent);
        nearest.setSub(minimum, center);
        float radiusSquared = centerRadius.v[3] * centerRadius.v[3];
        if (nearest.lengthSquared() > radiusSquared) return 0;
        farthest.setAdd(center, extent);
        if (farthest.lengthSquared() < radiusSquared) {
            FUN_00a9cb50(state, code);
            FUN_00a9c7f0(state, code);
            return 1;
        }
        return 2;
    }
};

struct MoppOutput { int* data; int size; int capacity; };


struct MoppMachine {
    MoppOutput* output;
    int unk04; int unk08; int unk0c;
    float scale;
    int unk14; int unk18; int unk1c;
    MoppSphere planeSet;
    void FUN_00a96780(const MoppState*, const unsigned char*, MoppBox*);
};

__forceinline int keep(int x, MoppBox* b) { int y = x; b->low[0] = b->low[0]; return y; }
__forceinline float& boxAt(float* p, int i) { return p[i]; }
__forceinline int moppRead24(const unsigned char* p) {
    return (((p[0] << 8) + p[1]) << 8) + p[2];
}
__forceinline int moppHighLast(int following, int leading, int last) {
    return ((following + (leading << 8)) << 8) + last;
}

// pdb: hkpMoppUsingFloatAabbVirtualMachine<class hkSphere,class hkMoppSphereQueryObjectOptimized>::queryMoppTree | hkpMoppMachine.obj | tesv_win, objopen_prop, low
void MoppMachine::FUN_00a96780(const MoppState* state, const unsigned char* code, MoppBox* box)
{
    MoppState localState;
    MoppBox other;

    int firstOffset, secondOffset;
    int terminalId;
    int opcode;
    for (;;) {
        opcode = *code;
        switch (opcode) {
        case 0: return;
        case 0x13: case 0x14: case 0x15: case 0x16: case 0x17:
        case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c:
            {
                secondOffset = code[3];
                other = *box;
                code += 4;
                FUN_00a96780(state, code, &other);
                code += secondOffset;
                break;
            }
        case 0x10: case 0x11: case 0x12:
            other = *box;
            {
            firstOffset = code[2];
            box->high[opcode - 0x10] = float((code[1] << state->shift) + state->origin[opcode - 0x10]) * scale;
            other.low[opcode - 0x10] = float((firstOffset << state->shift) + state->origin[opcode - 0x10]) * scale;
            }
            firstOffset = 0;
            secondOffset = code[3];
            code += 4;
            goto split;
        case 0x20: case 0x21: case 0x22:
            other = *box;
            {
            secondOffset = code[1] + 1;
            other.low[opcode - 0x20] = float((code[1] << state->shift) + state->origin[opcode - 0x20]) * scale;
            box->high[opcode - 0x20] = float((secondOffset << state->shift) + state->origin[opcode - 0x20]) * scale;
            }
            firstOffset = 0;
            secondOffset = code[2];
            code += 3;
            goto split;
        case 0x23: case 0x24: case 0x25:
            other = *box;
            {
            firstOffset = code[2];
            box->high[opcode - 0x23] = float((code[1] << state->shift) + state->origin[opcode - 0x23]) * scale;
            other.low[opcode - 0x23] = float((firstOffset << state->shift) + state->origin[opcode - 0x23]) * scale;
            }
            firstOffset = code[3];
            secondOffset = code[5];
            firstOffset = (firstOffset << 8) + code[4];
            secondOffset = (secondOffset << 8) + code[6];
            code += 7;
        split:
            {

                for (;;) { const int op = code[firstOffset]; if (op < 0x26 || op > 0x2b) break;
                    if (op >= 0x29) {
                        int tdir = op - 0x29;
                        boxAt(box->low, tdir) = float(moppRead24(code + firstOffset + 1)) * scale;
                        box->high[op - 0x29] = float((((code[firstOffset+4] << 8) + code[firstOffset+5]) << 8) + code[firstOffset+6]) * scale;
                        firstOffset += 7;
                    } else {
                        box->low[op - 0x26] = float((code[firstOffset+1] << state->shift) + state->origin[op-0x26]) * scale;
                        box->high[op - 0x26] = float((code[firstOffset+2] << state->shift) + state->origin[op-0x26]) * scale;
                        firstOffset += 3;
                    }

                }

                for (;;) { const int op = code[secondOffset]; if (op < 0x26 || op > 0x2b) break;
                    if (op >= 0x29) {
                        other.low[op - 0x29] = float((((code[secondOffset+1] << 8) + code[secondOffset+2]) << 8) + code[secondOffset+3]) * scale;
                        other.high[op - 0x29] = float(moppHighLast(code[secondOffset+5],code[secondOffset+4],code[secondOffset+6])) * scale;
                        secondOffset += 7;
                    } else {
                        other.low[op - 0x26] = float((code[secondOffset+1] << state->shift) + state->origin[op-0x26]) * scale;
                        other.high[op - 0x26] = float((code[secondOffset+2] << state->shift) + state->origin[op-0x26]) * scale;
                        secondOffset += 3;
                    }

                }
                int secondResult = planeSet.test(other, state, code + secondOffset);
                int firstResult = planeSet.test(*box, state, code + firstOffset);
                if (secondResult != 2) {
                    if (firstResult != 2) return;
                    code += firstOffset;
                } else if (firstResult != 2) {
                    *box = other;
                    code += secondOffset;
                } else {
                    FUN_00a96780(state, code + secondOffset, &other);
                    code += firstOffset;
                }
                break;
            }
        case 0x29: case 0x2a: case 0x2b:
            box->low[opcode - 0x29] = float((keep(code[2] + (keep(code[1], box) << 8), box) << 8) + keep(code[3], box)) * scale;
            {
                int leading = code[4];
                int following = code[5];
                box->high[opcode - 0x29] = float(((following + (leading << 8)) << 8) + code[6]) * scale;
            }
            code += 7;
            goto clip;
        case 0x26: case 0x27: case 0x28:
            box->low[opcode - 0x26] = float((code[1] << state->shift) + state->origin[opcode - 0x26]) * scale;
            box->high[opcode - 0x26] = float((code[2] << state->shift) + state->origin[opcode - 0x26]) * scale;
            code += 3;
        clip:
            if (code[0] >= 0x26 && code[0] <= 0x2b) break;
            {
                int result = planeSet.test(*box, state, code);
                if (result != 2) return;
                break;
            }
        case 5: code += code[1] + 2; break;
        case 6: code += (code[1] << 8) + code[2] + 3; break;
        case 7: code += (((code[1] << 8) + code[2]) << 8) + code[3] + 4; break;
        case 1: case 2: case 3: case 4:
            localState.origin[0] = (code[1] << state->shift) + state->origin[0];
            localState.origin[1] = (code[2] << state->shift) + state->origin[1];
            localState.origin[2] = (code[3] << state->shift) + state->origin[2];
            localState.shift = state->shift - opcode;
            localState.properties[0] = state->properties[0];
            localState.terminalBase = state->terminalBase;
            state = &localState;
            code += 4;
            break;
        case 9:
            {
                int value = code[1];
                if (state != &localState) { localState = *state; state = &localState; }
                localState.terminalBase += value;
                code += 2;
                break;
            }
        case 10:
            {
                int value = (code[1] << 8) + code[2];
                if (state != &localState) { localState = *state; state = &localState; }
                localState.terminalBase += value;
                code += 3;
                break;
            }
        case 11:
            {
                int value = (((((code[1] << 8) + code[2]) << 8) + code[3]) << 8) + code[4];
                if (state != &localState) { localState = *state; state = &localState; }
                localState.terminalBase = value;
                code += 5;
                break;
            }
        case 0x60: case 0x61: case 0x62: case 0x63: {
            int propertyByte = code[1];
            code += 2;
            localState.SetProperty(opcode-0x60, propertyByte);
            goto property; }
        case 0x64: case 0x65: case 0x66: case 0x67:
            localState.SetProperty(opcode-0x64, (code[1] << 8) + code[2]);
            code += 3;
            goto property;
        case 0x68: case 0x69: case 0x6a: case 0x6b:
            localState.SetProperty(opcode-0x68, (((((code[1] << 8) + code[2]) << 8) + code[3]) << 8) + code[4]);
            code += 5;
        property:
            {
                const int& propertyValue = localState.properties[0];
                int value = propertyValue;
                if (state != &localState) { localState = *state; state = &localState; }
                localState.properties[0] = value;
                break;
            }
        case 0x50: terminalId = code[1]; goto terminal;
        case 0x51: terminalId = (code[1] << 8) + code[2]; goto terminal;
        case 0x52: terminalId = (((code[1] << 8) + code[2]) << 8) + code[3]; goto terminal;
        case 0x53: terminalId = (((((code[1] << 8) + code[2]) << 8) + code[3]) << 8) + code[4]; goto terminal;
        case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
        case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f:
        case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
        case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f:
            terminalId = opcode - 0x30;
        terminal:
            {
                MoppOutput* out = output;
                terminalId += state->terminalBase;

                if (out->size == (out->capacity & 0x3fffffff))
                    FUN_00901f10(out, 4);
                int* next = out->data + out->size;
                ++out->size;
                *next = terminalId;
                return;
            }
        default:
            {
                char buffer[512];
                hkOstreamD734 stream;
                stream.FUN_00cb1600(buffer, 512);
                stream.FUN_00cc01c0(str_00e85ef0);
                DAT_01268360->message(3, 0x1298fedd, buffer, str_00e88d78, 301);
                stream.FUN_00cc00e0();
                break;
            }
        }
    }
}
}   // namespace f3m_00a96780

// @f3 0x00a8fe00 (community match, verified in this file)
#include <math.h>
extern const double DAT_00e889a0;
extern const float DAT_00dc076c;
extern const float DAT_00de707c;
namespace f3m_00a8fe00 {


namespace f3_a8fe00 {

static inline float Sqrt(float r) { return sqrtf(r); }
static inline float InverseSqrt(float r) { return 1.0f / Sqrt(r); }

class Quat;

class __declspec(align(16)) Vec4
{
public:
    float x, y, z, w;

    inline Vec4() {}
    inline Vec4(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    inline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    inline void set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    inline void setScaled(float rs, const Vec4& a)
    {
        float r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    inline void addScaled(float rs, const Vec4& a)
    {
        float r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    inline void scale(float rs)
    {
        x *= rs;
        y *= rs;
        z *= rs;
        w *= rs;
    }
    inline void add(const Vec4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    inline void setSum(const Vec4& a, const Vec4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    inline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const float nx = v1.y * v2.z - v1.z * v2.y;
        const float ny = v1.z * v2.x - v1.x * v2.z;
        const float nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
    inline float dot3(const Vec4& a) const
    {
        const float d = x * a.x + y * a.y + z * a.z;
        return d;
    }
    inline float inverseLength3() const
    {
        float lengthSq = (x * x) + (y * y) + (z * z);
        return lengthSq ? InverseSqrt(lengthSq) : 0;
    }
    inline void normalize3()
    {
        scale(inverseLength3());
    }
    __forceinline void setRotated(const Quat& q, const Vec4& dir);
};

class __declspec(align(16)) Quat
{
public:
    Vec4 m_vec;
    inline const Vec4& imag() const { return m_vec; }
};

__forceinline void Vec4::setRotated(const Quat& q, const Vec4& dir)
{
    float real = q.m_vec.w;
    float realTerm = real * real - 0.5f;

    Vec4 sum;
    sum.setScaled(realTerm, dir);

    float dotDir = q.imag().dot3(dir);

    sum.addScaled(dotDir, q.imag());

    Vec4 crossDir;
    crossDir.setCross(q.imag(), dir);
    sum.addScaled(real, crossDir);

    this->setSum(sum, sum);
}

}

class __declspec(align(16)) SpawnedSnap
{
public:
    float unk00, unk04, unk08, unk0C;
    SpawnedSnap(int value, float scale);
};

class DbgHandler
{
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void DisplayLine(const f3_a8fe00::Vec4& start, const f3_a8fe00::Vec4& end, int id, int tag);
};

class PlaneDrawObject
{
public:
    DbgHandler* value;
    void FUN_00a8fe00(const f3_a8fe00::Vec4* p1, int p2, const f3_a8fe00::Vec4* p3, int p4, float p5, int p6);
    void FUN_00a8f9c0(const f3_a8fe00::Vec4* p1, int p2, const f3_a8fe00::Vec4* p3, int p4, float p5, int p6);
};

void PlaneDrawObject::FUN_00a8fe00(const f3_a8fe00::Vec4* p1, int p2, const f3_a8fe00::Vec4* p3, int p4, float p5, int p6)
{
    using namespace f3_a8fe00;
    Vec4 edge;
    edge.setScaled((float)(p5 * DAT_00e889a0), *p3);
    SpawnedSnap quarterTurn(p2, DAT_00dc076c);
    SpawnedSnap eighthTurn(p2, DAT_00de707c);
    Vec4 corners[4];
    edge.setRotated(*(const Quat*)&eighthTurn, edge);
    for (int i = 0; i < 4; i++)
    {
        corners[i] = *p1;
        corners[i].add(edge);
        edge.setRotated(*(const Quat*)&quarterTurn, edge);
    }
    value->DisplayLine(corners[0], corners[1], p4, p6);
    value->DisplayLine(corners[1], corners[2], p4, p6);
    value->DisplayLine(corners[2], corners[3], p4, p6);
    value->DisplayLine(corners[3], corners[0], p4, p6);
    value->DisplayLine(corners[0], corners[2], p4, p6);
    value->DisplayLine(corners[1], corners[3], p4, p6);
    edge.normalize3();
    FUN_00a8f9c0(p1, p2, &edge, p4, p5, p6);
}
}   // namespace f3m_00a8fe00

// @f3 0x00a95770 (community match, verified in this file)
#include <math.h>
namespace f3m_00a95770 {
__forceinline float SphereFabs(float r) { return fabsf(r); }
__forceinline float SphereMin2(float a, float b) { return a < b ? a : b; }
__declspec(align(16)) class SphereVector4
{
public:
    float x;
    float y;
    float z;
    float w;

    SphereVector4() {}

    __forceinline float& operator()(int i)
    {
        return (&x)[i];
    }

    __forceinline const float& operator()(int i) const
    {
        return (&x)[i];
    }

    __forceinline void operator=(const SphereVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setAdd4(const SphereVector4& v0, const SphereVector4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }
    __forceinline void setSub4(const SphereVector4& v0, const SphereVector4& v1)
    {
        (*this)(0) = v0(0) - v1(0);
        (*this)(1) = v0(1) - v1(1);
        (*this)(2) = v0(2) - v1(2);
        (*this)(3) = v0(3) - v1(3);
    }
    __forceinline void sub4(const SphereVector4& v0)
    {
        x -= v0.x;
        y -= v0.y;
        z -= v0.z;
        w -= v0.w;
    }
    __forceinline void setAbs4(const SphereVector4& v0)
    {
        x = SphereFabs(v0.x);
        y = SphereFabs(v0.y);
        z = SphereFabs(v0.z);
        w = SphereFabs(v0.w);
    }
    __forceinline void setMin4(const SphereVector4& v0, const SphereVector4& v1)
    {
        x = SphereMin2(v0.x, v1.x);
        y = SphereMin2(v0.y, v1.y);
        z = SphereMin2(v0.z, v1.z);
        w = SphereMin2(v0.w, v1.w);
    }
    __forceinline float dot3(const SphereVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline float lengthSquared3() const
    {
        return dot3(*this);
    }
};
class SphereAabb
{
public:
    SphereAabb() {}
    SphereVector4 m_min;
    SphereVector4 m_max;
};
struct SphereTempAabb
{
    SphereAabb m_aabb;
};
class Sphere
{
public:
    SphereVector4 m_pos;

    __forceinline const SphereVector4& getPosition() const { return m_pos; }
    __forceinline const float& getRadius() const { return m_pos(3); }
};
class SphereQueryObject : public MoppQueryObject
{
public:
    Sphere m_sphere;

    __forceinline CheckCollisionResult checkCollision(const SphereAabb& aabb, const FindAllQuery* query, const unsigned char* commands)
    {
        SphereVector4 center2;
        center2.setAdd4(aabb.m_min, aabb.m_max);
        SphereVector4 extents2;
        extents2.setSub4(aabb.m_max, aabb.m_min);
        center2.sub4(m_sphere.getPosition());
        center2.setAbs4(center2);
        SphereVector4 nearest;
        nearest.setMin4(center2, extents2);
        SphereVector4 nearDist;
        nearDist.setSub4(nearest, center2);
        float radius2 = m_sphere.getRadius() * m_sphere.getRadius();
        if (nearDist.lengthSquared3() > radius2)
        {
            return HK_NO_HIT;
        }
        SphereVector4 farDist;
        farDist.setAdd4(center2, extents2);
        if (farDist.lengthSquared3() < radius2)
        {
            FUN_00e65ee0((int*)query, (int)commands);
            return HK_INCLUDED;
        }
        return HK_HIT;
    }
};
class SphereFloatAabbVirtualMachine : public MoppVirtualMachine
{
public:
    float m_ItoFScale;
    int m_align0;
    int m_align1;
    int m_align2;
    SphereQueryObject m_queryObject;

    void FUN_00a95770(const FloatAabbQueryInt* query, const unsigned char* PC, SphereTempAabb& fQueryL);
};
// pdb: hkpMoppUsingFloatAabbVirtualMachine<class hkSphere,class hkMoppSphereQueryObject>::queryMoppTree | hkpMoppMachine.obj | tesv_win, objopen_prop, low
void SphereFloatAabbVirtualMachine::FUN_00a95770(const FloatAabbQueryInt* query, const unsigned char* PC, SphereTempAabb& fQueryL)
{
    FloatAabbQueryInt scaledQuery;
    while (true)
    {
        int command = *PC;
        SphereTempAabb fQueryR;
        int offseth;
        int offsetl;

        switch (command)
        {
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
            offseth = PC[3];
            PC += 4;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            FUN_00a95770(query, PC, fQueryR);
            PC += offseth;
            break;

        case 0x10:
        case 0x11:
        case 0x12:
        {
            int tdir = command - 0x10;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offseth = PC[1];
            offsetl = PC[2];
            fQueryL.m_aabb.m_max(tdir) = ((offseth << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryR.m_aabb.m_min(tdir) = ((offsetl << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            offsetl = 0;
            offseth = PC[3];
            PC += 4;
            goto do_compare;
        }

        case 0x20:
        case 0x21:
        case 0x22:
        {
            int tdir = command - 0x20;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offsetl = PC[1];
            offseth = offsetl + 1;
            offsetl <<= query->m_shift;
            offseth <<= query->m_shift;
            offsetl += (&query->m_offset_x)[tdir];
            offseth += (&query->m_offset_x)[tdir];
            fQueryR.m_aabb.m_min(tdir) = offsetl * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = offseth * m_ItoFScale;
            offsetl = 0;
            offseth = PC[2];
            PC += 3;
            goto do_compare;
        }

        case 0x23:
        case 0x24:
        case 0x25:
        {
            int tdir = command - 0x23;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offseth = PC[1];
            offsetl = PC[2];
            fQueryL.m_aabb.m_max(tdir) = ((offseth << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryR.m_aabb.m_min(tdir) = ((offsetl << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            offsetl = (PC[3] << 8) + PC[4];
            offseth = (PC[5] << 8) + PC[6];
            PC += 7;
        do_compare:
            while (true)
            {
                int c = PC[offsetl];
                if (c < 0x26 || c > 0x2b)
                {
                    break;
                }
                if (c >= 0x29)
                {
                    int tdir = c - 0x29;
                    fQueryL.m_aabb.m_min(tdir) = read24(PC + offsetl + 1) * m_ItoFScale;
                    fQueryL.m_aabb.m_max(tdir) = read24(PC + offsetl + 4) * m_ItoFScale;
                    offsetl += 7;
                }
                else
                {
                    int tdir = c - 0x26;
                    fQueryL.m_aabb.m_min(tdir) = ((PC[offsetl + 1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    fQueryL.m_aabb.m_max(tdir) = ((PC[offsetl + 2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    offsetl += 3;
                }
            }
            while (true)
            {
                int c = PC[offseth];
                if (c < 0x26 || c > 0x2b)
                {
                    break;
                }
                if (c >= 0x29)
                {
                    int tdir = c - 0x29;
                    fQueryR.m_aabb.m_min(tdir) = read24(PC + offseth + 1) * m_ItoFScale;
                    fQueryR.m_aabb.m_max(tdir) = read24(PC + offseth + 4) * m_ItoFScale;
                    offseth += 7;
                }
                else
                {
                    int tdir = c - 0x26;
                    fQueryR.m_aabb.m_min(tdir) = ((PC[offseth + 1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    fQueryR.m_aabb.m_max(tdir) = ((PC[offseth + 2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    offseth += 3;
                }
            }
            {
                MoppQueryObject::CheckCollisionResult checkRight = m_queryObject.checkCollision(fQueryR.m_aabb, query, PC + offseth);
                MoppQueryObject::CheckCollisionResult checkLeft = m_queryObject.checkCollision(fQueryL.m_aabb, query, PC + offsetl);
                if (checkRight != MoppQueryObject::HK_HIT)
                {
                    if (checkLeft != MoppQueryObject::HK_HIT)
                    {
                        goto end_of_function;
                    }
                    PC += offsetl;
                    break;
                }
                if (checkLeft != MoppQueryObject::HK_HIT)
                {
                    fQueryL.m_aabb.m_min = fQueryR.m_aabb.m_min;
                    fQueryL.m_aabb.m_max = fQueryR.m_aabb.m_max;
                    PC += offseth;
                    break;
                }
                FUN_00a95770(query, PC + offseth, fQueryR);
                PC += offsetl;
                break;
            }
        }

        case 0x29:
        case 0x2a:
        case 0x2b:
        {
            int tdir = command - 0x29;
            fQueryL.m_aabb.m_min(tdir) = read24(PC + 1) * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = read24(PC + 4) * m_ItoFScale;
            PC += 7;
            goto doCut;
        }

        case 0x26:
        case 0x27:
        case 0x28:
        {
            int tdir = command - 0x26;
            fQueryL.m_aabb.m_min(tdir) = ((PC[1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = ((PC[2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            PC += 3;
        doCut:
            if (PC[0] >= 0x26 && PC[0] <= 0x2b)
            {
                continue;
            }
            {
                MoppQueryObject::CheckCollisionResult result = m_queryObject.checkCollision(fQueryL.m_aabb, query, PC);
                if (result == MoppQueryObject::HK_HIT)
                {
                    continue;
                }
                else
                {
                    goto end_of_function;
                }
            }
        }

        case 0x05:
            offsetl = PC[1];
            PC += 2;
            PC += offsetl;
            break;

        case 0x06:
            offseth = PC[1];
            offsetl = PC[2];
            PC += 3;
            PC += (offseth << 8) + offsetl;
            break;

        case 0x07:
        {
            offseth = PC[1];
            const int offsetm = PC[2];
            offsetl = PC[3];
            PC += 4;
            PC += (offseth << 16) + (offsetm << 8) + offsetl;
            break;
        }

        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
        {
            const int shift = command;
            scaledQuery.m_offset_x = (PC[1] << query->m_shift) + query->m_offset_x;
            scaledQuery.m_offset_y = (PC[2] << query->m_shift) + query->m_offset_y;
            scaledQuery.m_offset_z = (PC[3] << query->m_shift) + query->m_offset_z;
            scaledQuery.m_shift = query->m_shift - shift;
            for (int p = 0; p < 1; p++)
            {
                scaledQuery.m_properties[p] = query->m_properties[p];
            }
            scaledQuery.m_primitiveOffset = query->m_primitiveOffset;
            query = &scaledQuery;
            PC += 4;
            break;
        }

        case 0x09:
        {
            const int offset = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset += offset;
            PC += 2;
            break;
        }

        case 0x0a:
        {
            const int offset = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset += offset;
            PC += 3;
            break;
        }

        case 0x0b:
        {
            const int offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset = offset;
            PC += 5;
            break;
        }

        case 0x00:
            goto end_of_function;

        case 0x50:
            offsetl = PC[1];
            goto add_Terminal;

        case 0x51:
            offseth = PC[1];
            offseth <<= 8;
            offsetl = PC[2];
            offsetl += offseth;
            goto add_Terminal;

        case 0x52:
            offsetl = PC[1];
            offsetl <<= 16;
            offseth = PC[2];
            offseth <<= 8;
            offseth += PC[3];
            offsetl += offseth;
            goto add_Terminal;

        case 0x53:
            offsetl = PC[1];
            offsetl <<= 24;
            offseth = PC[2];
            offseth <<= 16;
            offsetl += offseth;
            offseth = PC[3];
            offsetl += PC[4];
            offseth <<= 8;
            offsetl += offseth;
            goto add_Terminal;

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
            offsetl = command - 0x30;
        add_Terminal:
            offsetl += query->m_primitiveOffset;
            addHit(offsetl, query->m_properties);
            goto end_of_function;

        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        {
            unsigned int property = PC[0] - 0x60;
            unsigned int value = PC[1];
            PC += 2;
            scaledQuery.m_properties[property] = value;
        propertyCopy:
            const int v = scaledQuery.m_properties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_properties[0] = v;
            break;
        }

        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        {
            const int property = PC[0] - 0x64;
            const int value = (PC[1] << 8) + PC[2];
            scaledQuery.m_properties[property] = value;
            PC += 3;
            goto propertyCopy;
        }

        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
        {
            const int property = PC[0] - 0x68;
            const int value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            scaledQuery.m_properties[property] = value;
            PC += 5;
            goto propertyCopy;
        }

        default:
        {
            char assertBuf[512];
            hkOstreamD734 ostr;
            ostr.FUN_00cb1600(assertBuf, 512);
            ostr.FUN_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
            DAT_01268360->message(3, 0x1298fedd, assertBuf, "s:\\Build\\code\\Complete\\Source\\Physics/Internal/Collide/Mopp/Machine/hkpMoppUsingFloatAabbVirtualMachine.inl", 0x12d);
            ostr.FUN_00cc00e0();
            break;
        }
        }
    }
end_of_function:
    ;
}
}   // namespace f3m_00a95770

// @f3 0x00a987c0 (community match, verified in this file)
namespace f3m_00a987c0 {
struct __declspec(align(16)) S00a987c0_Vector4
{
    float values[4];
    __forceinline void operator=(const S00a987c0_Vector4& v) { values[0] = v.values[0]; values[1] = v.values[1]; values[2] = v.values[2]; values[3] = v.values[3]; }
    __forceinline float& operator()(int i) { return values[i]; }
    __forceinline void setZero4() { values[0] = 0.0f; values[1] = 0.0f; values[2] = 0.0f; values[3] = 0.0f; }
    __forceinline void mul4(const float& s) { values[0] *= s; values[1] *= s; values[2] *= s; values[3] *= s; }
    __forceinline void addMul4(const float& s, const S00a987c0_Vector4& a) { values[0] += s * a.values[0]; values[1] += s * a.values[1]; values[2] += s * a.values[2]; values[3] += s * a.values[3]; }
};

struct S00a987c0_Matrix3
{
    S00a987c0_Vector4 m_col[3];
    __forceinline void operator=(const S00a987c0_Matrix3& o) { m_col[0] = o.m_col[0]; m_col[1] = o.m_col[1]; m_col[2] = o.m_col[2]; }
    __forceinline float& operator()(int r, int c) { return m_col[c](r); }
    __forceinline void setZero() { m_col[0].setZero4(); m_col[1].setZero4(); m_col[2].setZero4(); }
    __forceinline void setIdentity() { setZero(); (*this)(0, 0) = 1.0f; (*this)(1, 1) = 1.0f; (*this)(2, 2) = 1.0f; }
};

struct S00a987c0_Matrix6
{
    S00a987c0_Matrix3 m_m[2][2];
    __forceinline S00a987c0_Matrix6() {}
    __forceinline S00a987c0_Matrix6(const S00a987c0_Matrix6& o)
    {
        m_m[0][0] = o.m_m[0][0]; m_m[0][1] = o.m_m[0][1];
        m_m[1][0] = o.m_m[1][0]; m_m[1][1] = o.m_m[1][1];
    }
    __forceinline void setIdentity()
    {
        m_m[0][0].setIdentity();
        m_m[0][1].setZero();
        m_m[1][0].setZero();
        m_m[1][1].setIdentity();
    }
    void FUN_00a987c0(const S00a987c0_Matrix6& in);
};

// pdb: hkMatrix6::setInvert | hkMatrix6.obj | tesv_win, call_seq, medium
void S00a987c0_Matrix6::FUN_00a987c0(const S00a987c0_Matrix6& in)
{
    S00a987c0_Matrix6 tmp = in;
    setIdentity();
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float inv = 1.0f / tmp.m_m[i][i](j, j);
            tmp.m_m[0][i].m_col[j].mul4(inv);
            tmp.m_m[1][i].m_col[j].mul4(inv);
            m_m[0][i].m_col[j].mul4(inv);
            m_m[1][i].m_col[j].mul4(inv);
            float f;
            for (int k = 0; k < 2; k++)
            {
                if (k != i || j != 0)
                {
                    f = -tmp.m_m[i][k](j, 0);
                    tmp.m_m[0][k].m_col[0].addMul4(f, tmp.m_m[0][i].m_col[j]);
                    tmp.m_m[1][k].m_col[0].addMul4(f, tmp.m_m[1][i].m_col[j]);
                    m_m[0][k].m_col[0].addMul4(f, m_m[0][i].m_col[j]);
                    m_m[1][k].m_col[0].addMul4(f, m_m[1][i].m_col[j]);
                }
                if (k != i || j != 1)
                {
                    f = -tmp.m_m[i][k](j, 1);
                    tmp.m_m[0][k].m_col[1].addMul4(f, tmp.m_m[0][i].m_col[j]);
                    tmp.m_m[1][k].m_col[1].addMul4(f, tmp.m_m[1][i].m_col[j]);
                    m_m[0][k].m_col[1].addMul4(f, m_m[0][i].m_col[j]);
                    m_m[1][k].m_col[1].addMul4(f, m_m[1][i].m_col[j]);
                }
                if (k != i || j != 2)
                {
                    f = -tmp.m_m[i][k](j, 2);
                    tmp.m_m[0][k].m_col[2].addMul4(f, tmp.m_m[0][i].m_col[j]);
                    tmp.m_m[1][k].m_col[2].addMul4(f, tmp.m_m[1][i].m_col[j]);
                    m_m[0][k].m_col[2].addMul4(f, m_m[0][i].m_col[j]);
                    m_m[1][k].m_col[2].addMul4(f, m_m[1][i].m_col[j]);
                }
            }
        }
    }
}


}   // namespace f3m_00a987c0

// @f3 0x00a99b30 (community match, verified in this file)
namespace f3m_00a99b30 {
// 0x00a99b30: hkCvxCvxDistByHeuristicSamplingPerformSample(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB,
// const hkTransform& aTb, const hkVector4& direction, hkCvxCvxDistByHeuristicSamplingSample& sampleOut) of Havok
// 5.5.0 (hkpInternal, hkpCvxCvxDistByHeuristicSampling.cpp; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-), a
// file-local (static) function: one sample of the heuristic convex-convex distance search. It takes A's supporting
// vertex against the direction and B's along it (the direction rotated into B's space), brings B's vertex into A's
// space, and keeps the sample (both vertices, the direction and the distance in its w) when the separation along the
// direction beats the best one so far.
// The function takes shapeA in ecx, aTb in esi and direction in edi (shapeB and sampleOut on the stack): Visual C++
// 2005 gives a static function whose address is never taken a register convention of its own when it sees every
// call to it in the same file, without whole-program optimization. Its caller from the same source file, the C
// function hkCvxCvxDistByHeuristicSampling (0x00a99d10, six calls), is therefore defined here as well; without it
// the function is not emitted at all. hkCvxCvxDistByHeuristicSamplingSample and hkpGskOut are not in the SDK's
// shipped headers: they are written from the SDK library's own debug records (members, offsets, sizes, getDistance
// from its own unoptimized procedure).
// This file is built from the Havok 5.5.0 SDK's own headers: the functions were compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library object); those
// declarations are the SDK's text with its names. The bodies follow the SDK's unoptimized (hybrid) library object
// statement by statement and reproduce the release object. Only the function carries the packet's name.
namespace f3m_00a99b30 {

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
class hkClass;
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
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){  return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) {  } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
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
class hkQuaternion
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQuaternion), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
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
class hkQsTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQsTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
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
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(1,0)*v1 + r(2,0)*v2;
		t(1) = r(0,1)*v0 + r(1,1)*v1 + r(2,1)*v2;
		t(2) = r(0,2)*v0 + r(1,2)*v1 + r(2,2)*v2;
		t(3) = 0;
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
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
class hkAabb;
class hkSphere;
class hkpCdVertex: public hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCdVertex), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		int getId() const { return getInt24W(); }
};
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
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){  return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) {  } class MustEndWithSemiColon;
		__forceinline hkpShape( hkpShapeType type );
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShape::CalcSizeForSpuInput), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			static void __cdecl resetShapeFunctions();
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
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShape::ShapeFuncs), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
				__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpShape::ShapeFuncs2), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
	public:
		hkUlong m_userData;
	public:
		hkEnum<hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline int getNumCollisionSpheres( )  const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
	public:
		hkpSphereRepShape( hkpShapeType type ) : hkpShape( type ) {}
		hkpSphereRepShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_SPHERE_REP; }
};
class hkpConvexShape : public hkpSphereRepShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		inline void setRadius(hkReal radius);
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		__forceinline hkpConvexShape::WeldResult weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
																	hkVector4& contactPointWs, const hkTransform* thisObjTransform,
																	const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		__forceinline void getCentre( hkVector4& centreOut ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		inline hkpConvexShape( hkpShapeType type, hkReal radius );
		hkReal m_radius;
	public:
		hkpConvexShape( hkFinishLoadedObjectFlag flag ) : hkpSphereRepShape(flag) { m_type = HK_SHAPE_CONVEX; }
};
void hkpConvexShape::getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const
{
	this->getSupportingVertexImpl( direction, supportingVertexOut );
}
namespace hkVector4Util
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut);
}
struct hkpGskOut
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpGskOut), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkVector4 m_normalInA;
	hkVector4 m_pointAinA;
	hkPadSpu<hkReal> m_distance;
};
struct hkCvxCvxDistByHeuristicSamplingSample
{
	hkpCdVertex m_vertexAinA;
	hkpCdVertex m_vertexBinB;
	hkVector4 m_separatingNormalA;
	hkReal& getDistance() { return m_separatingNormalA(3); }
};
static void FUN_00a99b30( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb, const hkVector4& direction, hkCvxCvxDistByHeuristicSamplingSample& sampleOut )
{
	hkVector4 negDir; negDir.setNeg4( direction );
	hkpCdVertex vertexAinA; shapeA->getSupportingVertex( negDir, vertexAinA );
	hkVector4 dirB; dirB._setRotatedInverseDir( aTb.getRotation(), direction );
	hkpCdVertex vertexBinB; shapeB->getSupportingVertex( dirB, vertexBinB );
	hkVector4 vertexBinA; vertexBinA._setTransformedPos( aTb, vertexBinB );
	hkVector4 diffInA; diffInA.setSub4( vertexAinA, vertexBinA );
	hkReal dist = diffInA.dot3( direction );
	if ( dist > sampleOut.m_separatingNormalA(3) )
	{
		sampleOut.m_separatingNormalA = direction;
		sampleOut.m_vertexAinA = vertexAinA;
		sampleOut.m_vertexBinB = vertexBinB;
		sampleOut.m_separatingNormalA(3) = dist;
	}
}
extern "C" void hkCvxCvxDistByHeuristicSampling( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& btoa, hkpCdVertex* pointAinAOut, hkpCdVertex* pointBinBOut, hkpGskOut& output )
{
	hkCvxCvxDistByHeuristicSamplingSample bestSample; bestSample.getDistance() = -3.40282e+38f;
	{
		const hkVector4* p = &hkTransform::getIdentity().getColumn(0);
		for ( int a = 0; a < 3; a++ )
		{
			hkVector4 dir = p[0]; p++;
			FUN_00a99b30( shapeA, shapeB, btoa, dir, bestSample );
			dir.setNeg4( dir );
			FUN_00a99b30( shapeA, shapeB, btoa, dir, bestSample );
		}
	}
	hkReal angle = 1.0f;
	while ( angle > 0.001f )
	{
		{
			angle *= 0.99f;
			hkVector4 orthonormal0; hkVector4Util::calculatePerpendicularVector( bestSample.m_separatingNormalA, orthonormal0 );
			orthonormal0.normalize3();
			hkVector4 orthonormal1; orthonormal1.setCross( bestSample.m_separatingNormalA, orthonormal0 );
			orthonormal0.mul4( angle );
			orthonormal1.mul4( angle );
			hkVector4 dir0p; dir0p.setAdd4( bestSample.m_separatingNormalA, orthonormal0 );
			hkVector4 dir0n; dir0n.setSub4( bestSample.m_separatingNormalA, orthonormal0 );
			hkVector4 dir1p; dir1p.setAdd4( bestSample.m_separatingNormalA, orthonormal1 );
			hkVector4 dir1n; dir1n.setSub4( bestSample.m_separatingNormalA, orthonormal1 );
			hkReal normalizeInv = dir0p.lengthInverse3();
			dir0p.mul4( normalizeInv );
			dir0n.mul4( normalizeInv );
			dir1p.mul4( normalizeInv );
			dir1n.mul4( normalizeInv );
			FUN_00a99b30( shapeA, shapeB, btoa, dir0p, bestSample );
			FUN_00a99b30( shapeA, shapeB, btoa, dir0n, bestSample );
			FUN_00a99b30( shapeA, shapeB, btoa, dir1p, bestSample );
			FUN_00a99b30( shapeA, shapeB, btoa, dir1n, bestSample );
		}
		angle *= 0.5f;
	}
	*pointAinAOut = bestSample.m_vertexAinA;
	*pointBinBOut = bestSample.m_vertexBinB;
	output.m_distance = bestSample.getDistance();
	output.m_normalInA = bestSample.m_separatingNormalA;
	output.m_pointAinA = bestSample.m_vertexAinA;
}

}  // namespace f3m_00a99b30
}   // namespace f3m_00a99b30

// @f3 0x00a942b0 (community match, verified in this file)
extern const char DAT_00e85ef0[];
extern const char DAT_00e88d78[];
namespace f3m_00a942b0 {
namespace f3m_00a942b0 {

class Vector4Comparison
{
public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_ZW = 3,
        MASK_Y = 4,
        MASK_YW = 5,
        MASK_YZ = 6,
        MASK_YZW = 7,
        MASK_X = 8,
        MASK_XW = 9,
        MASK_XZ = 10,
        MASK_XZW = 11,
        MASK_XY = 12,
        MASK_XYW = 13,
        MASK_XYZ = 14,
        MASK_XYZW = 15
    };

    __forceinline int getMask() const { return m_mask; }

    int m_mask;
};
class Matrix3;
class Transform;
__declspec(align(16)) class Vector4
{
public:
    float x;
    float y;
    float z;
    float w;

    Vector4() {}

    __forceinline float& operator()(int i)
    {
        return (&x)[i];
    }

    __forceinline const float& operator()(int i) const
    {
        return (&x)[i];
    }

    __forceinline void operator=(const Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline void setAdd4(const Vector4& v0, const Vector4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    __forceinline void setAdd4Q(const Vector4& v0, const Vector4& v1)
    {
        (*this)(0) = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    __forceinline void setSub4(const Vector4& v0, const Vector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void setZero4() { x = 0; y = 0; z = 0; w = 0; }

    __forceinline Vector4Comparison compareLessThan4(const Vector4& a) const
    {
        Vector4Comparison ret;
        ret.m_mask =
            ((x < a.x) ? Vector4Comparison::MASK_X : 0) |
            ((y < a.y) ? Vector4Comparison::MASK_Y : 0) |
            ((z < a.z) ? Vector4Comparison::MASK_Z : 0) |
            ((w < a.w) ? Vector4Comparison::MASK_W : 0);
        return ret;
    }

    __forceinline Vector4Comparison compareGreaterThan4(const Vector4& a) const
    {
        Vector4Comparison ret;
        ret.m_mask =
            ((x > a.x) ? Vector4Comparison::MASK_X : 0) |
            ((y > a.y) ? Vector4Comparison::MASK_Y : 0) |
            ((z > a.z) ? Vector4Comparison::MASK_Z : 0) |
            ((w > a.w) ? Vector4Comparison::MASK_W : 0);
        return ret;
    }

    __forceinline Vector4Comparison compareLessThanZero4() const
    {
        Vector4Comparison ret;
        ret.m_mask =
            ((x < 0) ? Vector4Comparison::MASK_X : 0) |
            ((y < 0) ? Vector4Comparison::MASK_Y : 0) |
            ((z < 0) ? Vector4Comparison::MASK_Z : 0) |
            ((w < 0) ? Vector4Comparison::MASK_W : 0);
        return ret;
    }

    __forceinline void _setMul4xyz1(const Transform& t, const Vector4& v);
    __forceinline void _setMul4xyz1Direct(const Transform& t, const Vector4& v);
};
class Matrix4 { public: Vector4 m_columns[4]; __forceinline Vector4& getColumn(int x) { return m_columns[x]; } __forceinline const Vector4& getColumn(int x) const { return m_columns[x]; } __forceinline float& operator()(int r,int c) { return getColumn(c)(r); } __forceinline const float& operator()(int r,int c) const { return getColumn(c)(r); } };
class Transform  { public: Matrix4 m_matrix; __forceinline float& operator()(int r,int c) { return m_matrix(r,c); } __forceinline const float& operator()(int r,int c) const { return m_matrix(r,c); } };
__forceinline void Vector4::_setMul4xyz1(const Transform& t, const Vector4& v)
{
    float v0 = v(0);
    float v1 = v(1);
    float v2 = v(2);
    Vector4& d = *this;
    d(0) = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    d(1) = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    d(2) = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    d(3) = t(3, 0) * v0 + t(3, 1) * v1 + t(3, 2) * v2 + t(3, 3);
}
__forceinline void Vector4::_setMul4xyz1Direct(const Transform& t, const Vector4& v)
{
    Vector4& d = *this;
    d(0) = t(0, 0) * v.x + t(0, 1) * v.y + t(0, 2) * v.z + t(0, 3);
    d(1) = t(1, 0) * v.x + t(1, 1) * v.y + t(1, 2) * v.z + t(1, 3);
    d(2) = t(2, 0) * v.x + t(2, 1) * v.y + t(2, 2) * v.z + t(2, 3);
    d(3) = t(3, 0) * v.x + t(3, 1) * v.y + t(3, 2) * v.z + t(3, 3);
}
class Aabb
{
public:
    Aabb() {}
    Vector4 m_min;
    Vector4 m_max;
};
struct TempAabb
{
    Aabb m_aabb;
};

class PlanesQuery : public MoppVirtualMachine
{
public:
    enum CheckCollisionResult
    {
        HK_NO_HIT = 0,
        HK_INCLUDED = 1,
        HK_HIT = 2
    };

    int m_numTransforms;
    int m_align0;
    int m_align1;
    int m_align2;
    Transform m_rotatedPlanes0;
    Transform m_rotatedPlanes1;
    Transform m_rotatedPlanes2;
    Transform m_rotatedPlanes3;
    Transform m_rotatedPlanes4;
    Transform m_rotatedPlanes5;
    Transform m_rotatedPlanes6;
    Transform m_rotatedPlanes7;
    Transform m_absRotPlanes0;
    Transform m_absRotPlanes1;
    Transform m_absRotPlanes2;
    Transform m_absRotPlanes3;
    Transform m_absRotPlanes4;
    Transform m_absRotPlanes5;
    Transform m_absRotPlanes6;
    Transform m_absRotPlanes7;

    void FUN_00a9cb50(const FindAllQuery* query, const unsigned char* commands);
    void FUN_00a9c7f0(const FindAllQuery* query, const unsigned char* commands);
};

// The optimised planes query: same plane sets, the absolute-plane product takes the fourth column, and a fully
// included node is collected through both tree walks.
class PlanesQueryOptimized : public PlanesQuery
{
public:
    __forceinline CheckCollisionResult checkCollision(const Aabb& aabb, const FindAllQuery* query, const unsigned char* commands)
    {
        int inBits = 0x0f;
        const Transform* rotPlanes = &m_rotatedPlanes0;
        const Transform* absPlanes = &m_absRotPlanes0;

        Vector4 center2;
        center2.setAdd4(aabb.m_max, aabb.m_min);
        Vector4 extents2;
        extents2.setSub4(aabb.m_max, aabb.m_min);

        for (int i = m_numTransforms - 1; i >= 0; i--)
        {
            Vector4 absDiagDist;
            absDiagDist._setMul4xyz1Direct(*absPlanes, extents2);
            Vector4 centerDistToPlanes;
            centerDistToPlanes._setMul4xyz1(*rotPlanes, center2);
            Vector4 outDist;
            // Fake match: dead store, overwritten by the next statement. It only changes how the compiler numbers
            // its temporaries, which decides commutative operand order later in the function.
            outDist(0) = 0;
            outDist.setSub4(centerDistToPlanes, absDiagDist);
            Vector4 inDist;
            inDist.setAdd4(centerDistToPlanes, absDiagDist);

            int outBits = outDist.compareLessThanZero4().getMask();
            if (outBits != 0x0f)
            {
                return HK_NO_HIT;
            }
            int inMask = inDist.compareLessThanZero4().getMask();
            inBits &= inMask;

            rotPlanes++;
            absPlanes++;
        }

        if (inBits == 0x0f)
        {
            FUN_00a9cb50(query, commands);
            FUN_00a9c7f0(query, commands);
            return HK_INCLUDED;
        }
        return HK_HIT;
    }
    __forceinline CheckCollisionResult checkCollision2(const Aabb& aabb, const FindAllQuery* query, const unsigned char* commands)
    {
        int inBits = 0x0f;
        const Transform* rotPlanes = &m_rotatedPlanes0;
        const Transform* absPlanes = &m_absRotPlanes0;

        Vector4 center2;
        center2.setAdd4Q(aabb.m_max, aabb.m_min);
        Vector4 extents2;
        extents2.setSub4(aabb.m_max, aabb.m_min);

        for (int i = m_numTransforms - 1; i >= 0; i--)
        {
            Vector4 absDiagDist;
            absDiagDist._setMul4xyz1Direct(*absPlanes, extents2);
            Vector4 centerDistToPlanes;
            centerDistToPlanes._setMul4xyz1(*rotPlanes, center2);
            Vector4 outDist;
            outDist.setSub4(centerDistToPlanes, absDiagDist);
            Vector4 inDist;
            inDist.setAdd4(centerDistToPlanes, absDiagDist);

            int outBits = outDist.compareLessThanZero4().getMask();
            if (outBits != 0x0f)
            {
                return HK_NO_HIT;
            }
            int inMask = inDist.compareLessThanZero4().getMask();
            inBits &= inMask;

            rotPlanes++;
            absPlanes++;
        }

        if (inBits == 0x0f)
        {
            FUN_00a9cb50(query, commands);
            FUN_00a9c7f0(query, commands);
            return HK_INCLUDED;
        }
        return HK_HIT;
    }
};

class PlanesAabbVirtualMachine : public MoppVirtualMachine
{
public:
    float m_ItoFScale;
    int m_align0;
    int m_align1;
    int m_align2;
    PlanesQueryOptimized m_queryObject;

    void FUN_00a942b0(const FloatAabbQueryInt* query, const unsigned char* PC, TempAabb& fQueryL);
};

void PlanesAabbVirtualMachine::FUN_00a942b0(const FloatAabbQueryInt* query, const unsigned char* PC, TempAabb& fQueryL)
{
    FloatAabbQueryInt scaledQuery;
    while (true)
    {
        int command = *PC;
        TempAabb fQueryR;
        int offseth;
        int offsetl;

        switch (command)
        {
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
            offseth = PC[3];
            PC += 4;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            FUN_00a942b0(query, PC, fQueryR);
            PC += offseth;
            break;

        case 0x10:
        case 0x11:
        case 0x12:
        {
            int tdir = command - 0x10;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offseth = PC[1];
            offsetl = PC[2];
            fQueryL.m_aabb.m_max(tdir) = ((offseth << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryR.m_aabb.m_min(tdir) = ((offsetl << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            offsetl = 0;
            offseth = PC[3];
            PC += 4;
            goto do_compare;
        }

        case 0x20:
        case 0x21:
        case 0x22:
        {
            int tdir = command - 0x20;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offsetl = PC[1];
            offseth = offsetl + 1;
            offsetl <<= query->m_shift;
            offseth <<= query->m_shift;
            offsetl += (&query->m_offset_x)[tdir];
            offseth += (&query->m_offset_x)[tdir];
            fQueryR.m_aabb.m_min(tdir) = offsetl * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = offseth * m_ItoFScale;
            offsetl = 0;
            offseth = PC[2];
            PC += 3;
            goto do_compare;
        }

        case 0x23:
        case 0x24:
        case 0x25:
        {
            int tdir = command - 0x23;
            fQueryR.m_aabb.m_min = fQueryL.m_aabb.m_min;
            fQueryR.m_aabb.m_max = fQueryL.m_aabb.m_max;
            offseth = PC[1];
            offsetl = PC[2];
            fQueryL.m_aabb.m_max(tdir) = ((offseth << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryR.m_aabb.m_min(tdir) = ((offsetl << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            offsetl = (PC[3] << 8) + PC[4];
            offseth = (PC[5] << 8) + PC[6];
            PC += 7;
        do_compare:
            while (true)
            {
                int c = PC[offsetl];
                if (c < 0x26 || c > 0x2b)
                {
                    break;
                }
                if (c >= 0x29)
                {
                    int tdir = c - 0x29;
                    fQueryL.m_aabb.m_min(tdir) = read24(PC + offsetl + 1) * m_ItoFScale;
                    fQueryL.m_aabb.m_max(tdir) = read24(PC + offsetl + 4) * m_ItoFScale;
                    offsetl += 7;
                }
                else
                {
                    int tdir = c - 0x26;
                    fQueryL.m_aabb.m_min(tdir) = ((PC[offsetl + 1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    fQueryL.m_aabb.m_max(tdir) = ((PC[offsetl + 2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    offsetl += 3;
                }
            }
            while (true)
            {
                int c = PC[offseth];
                if (c < 0x26 || c > 0x2b)
                {
                    break;
                }
                if (c >= 0x29)
                {
                    int tdir = c - 0x29;
                    fQueryR.m_aabb.m_min(tdir) = read24(PC + offseth + 1) * m_ItoFScale;
                    fQueryR.m_aabb.m_max(tdir) = read24(PC + offseth + 4) * m_ItoFScale;
                    offseth += 7;
                }
                else
                {
                    int tdir = c - 0x26;
                    fQueryR.m_aabb.m_min(tdir) = ((PC[offseth + 1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    fQueryR.m_aabb.m_max(tdir) = ((PC[offseth + 2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
                    offseth += 3;
                }
            }
            {
                PlanesQuery::CheckCollisionResult checkRight = m_queryObject.checkCollision(fQueryR.m_aabb, query, PC + offseth);
                PlanesQuery::CheckCollisionResult checkLeft = m_queryObject.checkCollision(fQueryL.m_aabb, query, PC + offsetl);
                if (checkRight != PlanesQuery::HK_HIT)
                {
                    if (checkLeft != PlanesQuery::HK_HIT)
                    {
                        goto end_of_function;
                    }
                    PC += offsetl;
                    break;
                }
                if (checkLeft != PlanesQuery::HK_HIT)
                {
                    fQueryL.m_aabb.m_min = fQueryR.m_aabb.m_min;
                    fQueryL.m_aabb.m_max = fQueryR.m_aabb.m_max;
                    PC += offseth;
                    break;
                }
                FUN_00a942b0(query, PC + offseth, fQueryR);
                PC += offsetl;
                break;
            }
        }

        case 0x29:
        case 0x2a:
        case 0x2b:
        {
            int tdir = command - 0x29;
            fQueryL.m_aabb.m_min(tdir) = read24(PC + 1) * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = read24(PC + 4) * m_ItoFScale;
            PC += 7;
            goto doCut;
        }

        case 0x26:
        case 0x27:
        case 0x28:
        {
            int tdir = command - 0x26;
            fQueryL.m_aabb.m_min(tdir) = ((PC[1] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            fQueryL.m_aabb.m_max(tdir) = ((PC[2] << query->m_shift) + (&query->m_offset_x)[tdir]) * m_ItoFScale;
            PC += 3;
        doCut:
            if (PC[0] >= 0x26 && PC[0] <= 0x2b)
            {
                continue;
            }
            {
                PlanesQuery::CheckCollisionResult result = m_queryObject.checkCollision2(fQueryL.m_aabb, query, PC);
                if (result == PlanesQuery::HK_HIT)
                {
                    continue;
                }
                else
                {
                    goto end_of_function;
                }
            }
        }

        case 0x05:
            offsetl = PC[1];
            PC += 2;
            PC += offsetl;
            break;

        case 0x06:
            offseth = PC[1];
            offsetl = PC[2];
            PC += 3;
            PC += (offseth << 8) + offsetl;
            break;

        case 0x07:
        {
            offseth = PC[1];
            const int offsetm = PC[2];
            offsetl = PC[3];
            PC += 4;
            PC += (offseth << 16) + (offsetm << 8) + offsetl;
            break;
        }

        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
        {
            const int shift = command;
            scaledQuery.m_offset_x = (PC[1] << query->m_shift) + query->m_offset_x;
            scaledQuery.m_offset_y = (PC[2] << query->m_shift) + query->m_offset_y;
            scaledQuery.m_offset_z = (PC[3] << query->m_shift) + query->m_offset_z;
            scaledQuery.m_shift = query->m_shift - shift;
            for (int p = 0; p < 1; p++)
            {
                scaledQuery.m_properties[p] = query->m_properties[p];
            }
            scaledQuery.m_primitiveOffset = query->m_primitiveOffset;
            query = &scaledQuery;
            PC += 4;
            break;
        }

        case 0x09:
        {
            const int offset = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset += offset;
            PC += 2;
            break;
        }

        case 0x0a:
        {
            const int offset = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset += offset;
            PC += 3;
            break;
        }

        case 0x0b:
        {
            const int offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_primitiveOffset = offset;
            PC += 5;
            break;
        }

        case 0x00:
            goto end_of_function;

        case 0x50:
            offsetl = PC[1];
            goto add_Terminal;

        case 0x51:
            offseth = PC[1];
            offseth <<= 8;
            offsetl = PC[2];
            offsetl += offseth;
            goto add_Terminal;

        case 0x52:
            offsetl = PC[1];
            offsetl <<= 16;
            offseth = PC[2];
            offseth <<= 8;
            offseth += PC[3];
            offsetl += offseth;
            goto add_Terminal;

        case 0x53:
            offsetl = PC[1];
            offsetl <<= 24;
            offseth = PC[2];
            offseth <<= 16;
            offsetl += offseth;
            offseth = PC[3];
            offsetl += PC[4];
            offseth <<= 8;
            offsetl += offseth;
            goto add_Terminal;

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
            offsetl = command - 0x30;
        add_Terminal:
            offsetl += query->m_primitiveOffset;
            addHit(offsetl, query->m_properties);
            goto end_of_function;

        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        {
            unsigned int property = PC[0] - 0x60;
            unsigned int value = PC[1];
            PC += 2;
            scaledQuery.m_properties[property] = value;
        propertyCopy:
            const int v = scaledQuery.m_properties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_properties[0] = v;
            break;
        }

        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        {
            const int property = PC[0] - 0x64;
            const int value = (PC[1] << 8) + PC[2];
            scaledQuery.m_properties[property] = value;
            PC += 3;
            goto propertyCopy;
        }

        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
        {
            const int property = PC[0] - 0x68;
            const int value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            scaledQuery.m_properties[property] = value;
            PC += 5;
            goto propertyCopy;
        }

        default:
        {
            char assertBuf[512];
            hkOstreamD734 ostr;
            ostr.FUN_00cb1600(assertBuf, 512);
            ostr.FUN_00cc01c0(DAT_00e85ef0);
            DAT_01268360->message(3, 0x1298fedd, assertBuf, DAT_00e88d78, 0x12d);
            ostr.FUN_00cc00e0();
            break;
        }
        }
    }
end_of_function:
    ;
}

}
}   // namespace f3m_00a942b0
