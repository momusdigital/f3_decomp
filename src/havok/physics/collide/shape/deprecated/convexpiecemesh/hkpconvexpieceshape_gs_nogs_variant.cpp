#include "f3_common.h"
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_010c6fb0;
extern int DAT_010c6fb0;
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
AudioHolder* __cdecl FUN_00c85750() throw();
struct FUN_00e60c30_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    void* volatile m_p14;

    FUN_00e60c30_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

#include <xmmintrin.h>
extern float DAT_0104e148;

struct __declspec(align(16)) FNV_V4
{
    float x;
    float y;
    float z;
    int w;
};

union __declspec(align(16)) ShapeBuffer338
{
    __m128 alignment;
    char bytes[512];
};

struct FNV_Res
{
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
    virtual void v34();
    virtual void calc(__m128* a, __m128* out);
};

struct FNV_Inner
{
    virtual void i00();
    virtual void i04();
    virtual void i08();
    virtual void i0c();
    virtual void i10();
    virtual FNV_Res* run(int index, ShapeBuffer338* out);
};

struct FNV_Disp
{
    int d00;
    int d04;
    int d08;
    int d0c;
    FNV_Inner inner;
};

struct FNV_Owner
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    FNV_Disp* p20;
    int* p24;
    int n28;
    void FUN_00e608d0(FNV_V4* pA, FNV_V4* pOut);
};

// @f3 0x00a97bc0 (community match, verified in this file)
struct NativeSupportResult16
{
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
    virtual void calc(FNV_V4* a, FNV_V4* out);
};

// pdb: hkpConvexPieceShape::getSupportingVertexImpl | hkpConvexPieceShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: dir, supportingVertex
void FNV_Owner::FUN_00e608d0(FNV_V4* pA, FNV_V4* pOut)
{
    ShapeBuffer338 big;
    FNV_V4 support;
    float best = DAT_0104e148;
    int vertexId = 0;
    for (int i = 0; i < n28; i++)
    {
        NativeSupportResult16* r = reinterpret_cast<NativeSupportResult16*>(p20->inner.run(p24[i], &big));
        r->calc(pA, &support);
        float dot = pA->x * support.x + pA->y * support.y + pA->z * support.z;
        if (dot > best)
        {
            best = dot;
            pOut->x = support.x;
            pOut->y = support.y;
            pOut->z = support.z;
            *(float*)&pOut->w = *(const float*)&support.w;
            vertexId = (int)(support.w & 0xc0ffffff) / 16 + i * 3;
        }
    }
    *(int*)&pOut->w = vertexId | 0x3f000000;
}


extern const unsigned int DAT_01017d10[4];
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

class S5fb50_SimdReal
{
  public:
    S5fb50_SimdReal(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    __m128 m_vValue;
};

// hkVector4
class S5fb50_Vector4
{
  public:
    __m128 m_vComponents;
    inline void operator=(const S5fb50_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    inline void setAdd4(const S5fb50_Vector4& v0, const S5fb50_Vector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void sub4(const S5fb50_Vector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    inline void setSub4(const S5fb50_Vector4& v0, const S5fb50_Vector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setAbs4(const S5fb50_Vector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, *(const __m128*)&DAT_01017d10);
    }
    inline void setMin4(const S5fb50_Vector4& a, const S5fb50_Vector4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    inline S5fb50_SimdReal dot3(const S5fb50_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
    }
    inline S5fb50_SimdReal lengthSquared3() const
    {
        return this->dot3(*this);
    }
    inline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    inline const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[a];
    }
};

// hkSphere
class S5fb50_Sphere
{
  public:
    inline float getRadius() const
    {
        return m_pos(3);
    }
    inline const S5fb50_Vector4& getPosition() const
    {
        return m_pos;
    }
    S5fb50_Vector4 m_pos;
};

// hkAabb
class S5fb50_Aabb
{
  public:
    S5fb50_Vector4 m_kMinimumCorner;
    S5fb50_Vector4 m_kMaximumCorner;
};

class S5fb50_PrimitiveInfo
{
  public:
    unsigned int ID;
};

struct S5fb50_Array
{
    S5fb50_PrimitiveInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    inline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    inline S5fb50_PrimitiveInfo& _expandOne(AudioHolder* router)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(router->m_pAllocator, this, sizeof(S5fb50_PrimitiveInfo));
        }
        for (int i = 0; i < 1; i++)
            ::new (m_data + m_iElementCount + i) S5fb50_PrimitiveInfo;
        return m_data[m_iElementCount++];
    }
    inline S5fb50_PrimitiveInfo& AllocatePair()
    {
        return _expandOne(FUN_00c85750());
    }
};

struct S5fb50_Query
{
    unsigned int m_uiPropertyCount;
    unsigned int m_kProperties[1];
    int m_offset[3];
    int m_iIndex;
};

class S5fb50_MoppVm
{
  public:
    S5fb50_Array* m_pPrimitiveInfoArray;
    int unk04;
    int unk08;
    int unk0c;
    static inline int read24(const unsigned char* PC)
    {
        int v = (PC[0] << 16) + (PC[1] << 8) + PC[2];
        return v;
    }
    inline void AddHit(unsigned int key, const unsigned int properties[1])
    {
        m_pPrimitiveInfoArray->AllocatePair().ID = key;
    }
};

class S5fb50_SphereQueryObject : public S5fb50_MoppVm
{
  public:
    S5fb50_Sphere m_pSphere;
    void FUN_00e66600(const S5fb50_Query* query, const unsigned char* PC);
    void FUN_00e66290(const S5fb50_Query* query, const unsigned char* PC);
    __forceinline int checkCollision(const S5fb50_Aabb& aabb, const S5fb50_Query* query, const unsigned char* PC)
    {
        S5fb50_Vector4 center;
        center.setAdd4(aabb.m_kMinimumCorner, aabb.m_kMaximumCorner);
        S5fb50_Vector4 extent;
        extent.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
        center.sub4(m_pSphere.getPosition());
        center.setAbs4(center);
        S5fb50_Vector4 nearest;
        nearest.setMin4(center, extent);
        S5fb50_Vector4 diff;
        diff.setSub4(nearest, center);
        float distance = diff.lengthSquared3();
        float radius2 = m_pSphere.getRadius() * m_pSphere.getRadius();
        if (distance > radius2)
        {
            return 0;
        }
        S5fb50_Vector4 farthest;
        farthest.setAdd4(center, extent);
        if (farthest.lengthSquared3() < radius2)
        {
            FUN_00e66600(query, PC);
            FUN_00e66290(query, PC);
            return 1;
        }
        return 2;
    }
};

class S5fb50_FloatAabbVm : public S5fb50_MoppVm
{
  public:
    struct TempAabb : public S5fb50_Aabb
    {
        TempAabb()
        {}
    };
    float m_vRayDirectionVector;
    int unk14;
    int unk18;
    int unk1c;
    S5fb50_SphereQueryObject m_kSphereQueryObject;

    void FUN_00e5fb50(const S5fb50_Query* query, const unsigned char* PC, TempAabb& aabb);
};
