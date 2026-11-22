#include <math.h>
// src/f3staging/f3blk_009c0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x009c47e0 (community match, verified in this file)
#include <intrin.h>
extern unsigned int DAT_0116913c;
extern const char DAT_00e7f134[], DAT_00e32798[];
namespace f3m_009c47e0 {
namespace Sol47 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Transform47;
struct __declspec(align(16)) Vec47 {
    float m_quad[4];
    __forceinline Vec47() {}
    __forceinline void operator=(const Vec47& v) { m_quad[0]=v.m_quad[0]; m_quad[1]=v.m_quad[1]; m_quad[2]=v.m_quad[2]; m_quad[3]=v.m_quad[3]; }
    __forceinline float& operator()(int index) { return m_quad[index]; }
    __forceinline const float& operator()(int index) const { return m_quad[index]; }
    __forceinline void transform(const Transform47&, const Vec47&);
    __forceinline void subtract(const Vec47& a, const Vec47& b) { m_quad[0]=a.m_quad[0]-b.m_quad[0]; m_quad[1]=a.m_quad[1]-b.m_quad[1]; m_quad[2]=a.m_quad[2]-b.m_quad[2]; m_quad[3]=a.m_quad[3]-b.m_quad[3]; }
};
// Rotation and translation use genuine four-column array storage.
struct Transform47 {
    Vec47 columns[4];
    __forceinline Transform47() {}
    __forceinline Vec47& column(int i) { return columns[i]; }
    __forceinline const Vec47& column(int i) const { return columns[i]; }
    __forceinline const float& operator()(int r,int c) const { return column(c)(r); }
    __forceinline Transform47(const Transform47& t) {
        const Vec47 a=t.column(0);
        const Vec47 b=t.column(1);
        const Vec47 c=t.column(2);
        const Vec47 d=t.column(3);
        column(0)=a; column(1)=b; column(2)=c; column(3)=d;
    }
};
__forceinline void Vec47::transform(const Transform47& m, const Vec47& v) {
    float a=v(0);
    float b=v(1);
    float c=v(2);
    Vec47& dst=*this;
    dst(0)=m(0,0)*a+m(0,1)*b+m(0,2)*c+m(0,3);
    dst(1)=m(1,0)*a+m(1,1)*b+m(1,2)*c+m(1,3);
    dst(2)=m(2,0)*a+m(2,1)*b+m(2,2)*c+m(2,3);
    dst(3)=0;
}
__forceinline void TransformPoints47(const Transform47& t,const Vec47* in,int count,Vec47* out) {
    Transform47 copy(t);
    int index=count-1;
    do { out[index].transform(copy,in[index]); } while (--index>=0);
}
struct Shape47 { void* vtable; unsigned short unk04; short unk06; unsigned unk08,unk0c; float radius; };
struct Capsule47 : Shape47 {
    Vec47 m_vertices[2];
    __forceinline float getRadius() const { return radius; }
};
struct Body47 { const Shape47* m_shape; unsigned m_shapeKey; const Transform47* m_motion; const Body47* m_parent;
    __forceinline const Shape47* getShape() const { return m_shape; }
    __forceinline const Transform47& getTransform() const { return *m_motion; }
};
struct Input47;
struct Collector47 { virtual void v00(); virtual void AddPair(const Body47&, const Body47&); };
struct ClosestOut47 { Vec47 a,b; float distSq; };
extern "C" int __cdecl FUN_0096f780(const Vec47&,const Vec47&,const Vec47&,const Vec47&,ClosestOut47&);
struct Record47 { const char* tag; unsigned time,extra; 
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov ticks, eax } time = ticks; }
};
struct Monitor47 { Record47* start; Record47* next; Record47* capacity; Record47* limit; };
// pdb: hkpCapsuleCapsuleAgent::staticGetPenetrations | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, call_seq + bridge(caller_sim|objrun_prop) + skyrim(call_seq), high
void __cdecl hkpCapsuleCapsuleAgent_staticGetPenetrations(const Body47& bodyA,const Body47& bodyB,const Input47& input,Collector47& collector) {
    {
        Monitor47* mon=(Monitor47*)DAT_00d9b080(DAT_0116913c);
        if(mon->next<mon->limit) {
            Record47* rec=mon->next;
            rec->tag=DAT_00e7f134;
            rec->setTime();
            mon->next=rec+1;
        }
    }
    const Capsule47* capA=static_cast<const Capsule47*>(bodyA.getShape());
    const Capsule47* capB=static_cast<const Capsule47*>(bodyB.getShape());
    Vec47 worldA[2];
    Vec47 worldB[2];
    TransformPoints47(bodyA.getTransform(),capA->m_vertices,2,worldA);
    TransformPoints47(bodyB.getTransform(),capB->m_vertices,2,worldB);
    Vec47 dirA; dirA.subtract(worldA[1],worldA[0]);
    Vec47 dirB; dirB.subtract(worldB[1],worldB[0]);
    ClosestOut47 result;
    FUN_0096f780(worldA[0],dirA,worldB[0],dirB,result);
    float radius=capA->getRadius()+capB->getRadius();
    if(result.distSq<radius*radius) collector.AddPair(bodyA,bodyB);
    {
        Monitor47* mon=(Monitor47*)DAT_00d9b080(DAT_0116913c);
        if(mon->next<mon->limit) {
            Record47* rec=mon->next;
            rec->tag=DAT_00e32798;
            rec->setTime();
            mon->next=rec+1;
        }
    }
}
}
}   // namespace f3m_009c47e0

// @f3 0x009d4b00 (community match, verified in this file)
namespace f3m_009d4b00 {


extern float g_D2E9B0MaxDistance;

namespace f3m_009d4b00 {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
}
extern f3m_009d4b00::hkVector4 DAT_00f7b0c0;
namespace f3m_009d4b00 {

class hkVector4
{
	public:
		__forceinline hkVector4() { }
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(const hkVector4& a, const hkVector4& b);
		__forceinline void add4(const hkVector4& a);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
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
	for (int i = 0; i < 4; i++) (*this)(i) = v0(i) - v1(i);
}
inline void hkVector4::setMul4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x * v1.x;
	y = v0.y * v1.y;
	z = v0.z * v1.z;
	w = v0.w * v1.w;
}
inline void hkVector4::add4(const hkVector4& a)
{
	x += a.x;
	y += a.y;
	z += a.z;
	w += a.w;
}
inline void hkVector4::sub4(const hkVector4& a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
	w -= a.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal r = hkReal(rs);
	x *= r;
	y *= r;
	z *= r;
	w *= r;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return (x * x) + ( y * y ) + ( z * z );
}
inline void hkVector4::normalize3()
{
	hkReal lengthSquared = this->dot3(*this);
	hkReal invLength;
	if (lengthSquared != 0.0f) { invLength = 1.0f / sqrtf(lengthSquared); } else { invLength = 0.0f; }
	this->mul4(invLength);
}

class hkSphere
{
	public:
		__forceinline const hkVector4& getPosition() const { return m_pos; }
		__forceinline hkReal getRadius() const { return m_pos(3); }
	public:
		hkVector4 m_pos;
};

struct CollideSpheresInput
{
	hkSphere* m_spheres;
	int m_numSpheres;
};


union hkIntUnion64
{
	unsigned short i16[4];
	unsigned int i32[2];
};

static __forceinline void convertToUint16(const hkVector4& in, const hkVector4& offset, const hkVector4& scale, hkIntUnion64& out)
{
	hkVector4 base = DAT_00f7b0c0;
	hkVector4 x;
	x.setAdd4(in, offset);
	x.mul4(scale);
	x.add4(base);
	const unsigned int* i = (const unsigned int*)&x;
	out.i16[0] = (unsigned short)(i[0] >> 6);
	out.i16[1] = (unsigned short)(i[1] >> 6);
	out.i16[2] = (unsigned short)(i[2] >> 6);
	out.i16[3] = (unsigned short)(i[3] >> 6);
}

struct hkpStorageSampledHeightFieldShape
{
	void* vtable;
	unsigned short m_memSizeAndFlags;
	short m_referenceCount;
	unsigned int m_userData;
	int m_type;
	int m_xRes;
	int m_zRes;
	hkReal m_heightCenter;
	bool m_useProjectionBasedHeight;
	unsigned char m_heightfieldType;
	hkVector4 m_intToFloatScale;
	hkVector4 m_floatToIntScale;
	hkVector4 m_floatToIntOffsetFloorCorrected;
	hkVector4 m_extents;
	hkReal* m_storage;
	int m_storageSize;
	int m_storageCapacity;
	bool m_triangleFlip;

	__forceinline hkReal getHeightAt(int x, int z) const { return m_storage[z * m_xRes + x]; }

	__forceinline void _getHeightAndNormalAt(int x, int z, hkReal subX, hkReal subZ, hkVector4& normalOut, hkReal& heightOut, int& px, hkReal& ph) const
	{
        if (m_triangleFlip)
    {
        hkReal h00 = getHeightAt(x, z);
        ph = h00;
        px = x;
        hkReal h11 = getHeightAt(x + 1, z + 1);
        if (subX > subZ)
        {
            hkReal h10 = getHeightAt(x + 1, z);
            hkReal dx = h10 - h00;
            hkReal dz = h11 - h10;
            heightOut = h00 + subZ * dz + subX * dx;
            normalOut(0) = -dx;
            normalOut(2) = -dz;
        }
        else
        {
            hkReal h01 = getHeightAt(x, z + 1);
            hkReal dx = h11 - h01;
            hkReal dz = h01 - h00;
            heightOut = h00 + subZ * dz + subX * dx;
            normalOut(0) = -dx;
            normalOut(2) = -dz;
        }
    }
    else
    {
        hkReal h10 = getHeightAt(x + 1, z);
        px = x + 1;
        ph = h10;
        hkReal h01 = getHeightAt(x, z + 1);
        if (subX + subZ > 1.0f)
        {
            hkReal h11 = getHeightAt(x + 1, z + 1);
            hkReal dx = h11 - h01;
            hkReal dz = h11 - h10;
            heightOut = h10 + subZ * dz + (subX - 1.0f) * dx;
            normalOut(0) = -dx;
            normalOut(2) = -dz;
        }
        else
        {
            hkReal h00 = getHeightAt(x, z);
            hkReal dx = h10 - h00;
            hkReal dz = h01 - h00;
            heightOut = h00 + subZ * dz + subX * dx;
            normalOut(0) = -dx;
            normalOut(2) = -dz;
        }
    }

	}

	void FUN_009d4b00(const CollideSpheresInput& input, hkVector4* outputArray) const;
};

void hkpStorageSampledHeightFieldShape::FUN_009d4b00(const CollideSpheresInput& input, hkVector4* outputArray) const
{
    const hkSphere* sphere = input.m_spheres;
    int j = 0;
    for (int i = input.m_numSpheres - 1; i >= 0; sphere++, j++, i--)
    {
        hkVector4& output = outputArray[j];
        output(0) = 0.0f;
        output(1) = 1.0f;
        output(2) = 0.0f;
        output(3) = g_D2E9B0MaxDistance;

        hkVector4 pos; pos.setMul4(m_floatToIntScale, sphere->m_pos);
        hkIntUnion64 out;
        convertToUint16(sphere->m_pos, m_floatToIntOffsetFloorCorrected, m_floatToIntScale, out);
        int x = out.i16[0];
        int z = out.i16[2];

        if (x >= m_xRes - 1 || z >= m_zRes - 1)
        {
            continue;
        }

        hkReal subX = pos(0) - hkReal(x);
        hkReal subZ = pos(2) - hkReal(z);

        int px;
        hkReal ph;
        hkReal height;
        _getHeightAndNormalAt(x, z, subX, subZ, output, height, px, ph);

        output.mul4(m_floatToIntScale);
        output.normalize3();

        hkReal dist;
        if (!m_useProjectionBasedHeight)
        {
            dist = (pos(1) - height) * m_intToFloatScale(1) - sphere->m_pos(3);
        }
        else
        {
            hkVector4 vertex; vertex.set(hkReal(px), ph, hkReal(z), 0.0f);
            hkVector4 d; d.setSub4(pos, vertex);
            d.setMul4(d, m_intToFloatScale);
            hkReal proj = output.dot3(d); dist = proj - sphere->m_pos(3);
        }
        output(3) = dist;
    }
}

}

}   // namespace f3m_009d4b00
