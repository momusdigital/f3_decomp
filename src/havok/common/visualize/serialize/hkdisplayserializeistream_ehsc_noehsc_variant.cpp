#include "f3_common.h"
// src/havok/common/visualize/serialize/hkdisplayserializeistream_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct DdabeTag
{
    bool b;
    DdabeTag() : b(false)
    {}
    DdabeTag(const DdabeTag& o) : b(o.b)
    {}
};
struct DdabeBase
{
    DdabeBase(int a, DdabeTag t);
    virtual void unk00();
};
struct FUN_00ddabe0 : DdabeBase
{
    FUN_00ddabe0(int a);
    virtual void unk00();
};
struct FUN_00ddac60_Obj
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};
void __stdcall FUN_00dd8fe0(FUN_00ddac60_Obj* obj, int a, int b);
void __stdcall FUN_00ddac60(FUN_00ddac60_Obj* obj);
struct ArrayRecord
{
    void* data;
    int size;
    int capacity;
};
struct ArrayPair
{
    ArrayRecord first;
    ArrayRecord second;
};
struct BSAudio
{
};
BSAudio* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(void*, void*, int, int);
struct FUN_00ddacd0_shell
{
    void __thiscall FUN_00dd8fe0(void* output, int elementSize, int count);
    void __thiscall FUN_00ddac60(void* output);
    void __thiscall hkDisplaySerializeIStream_readTriangle(void* output);
    void __thiscall FUN_00ddacd0(ArrayPair* arrays);
};
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
struct FUN_00dd9210_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00dd91f0();

    FUN_00dd9210_cls* FUN_00dd9210(unsigned char acFlags);
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_set_ps1(float a);
extern "C" __m128 _mm_load_ps1(float const* p);

typedef float hkReal;
typedef signed char hkInt8;

struct hkVector4Q
{
    __m128 m_vComponents;
    void operator=(const hkVector4Q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
};

struct hkTransformQ
{
    hkVector4Q m_kColumn0;
    hkVector4Q m_kColumn1;
    hkVector4Q m_kColumn2;
    hkVector4Q m_vTranslation;
    void FUN_00c6cd60(const hkTransformQ& t);
};

struct hkSphereQ
{
    hkVector4Q m_pos;
    hkSphereQ(const hkVector4Q& pos, hkReal radius)
    {
        m_pos = pos;
        m_pos.m_vComponents.m128_f32[3] = radius;
    }
};

struct hkMemoryAllocatorQ
{
    virtual void vf00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct hkMemoryRouterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorQ* m_pStreamAllocator;
    hkMemoryAllocatorQ& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline hkMemoryRouterQ* getRouterQ()
{
    return (hkMemoryRouterQ*)FUN_00c85750();
}

struct hkGeometryQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkGeometryQ();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        return getRouterQ()->heap().AllocateMemoryBlock(nbytes);
    }
    __forceinline static void operator delete(void* p)
    {}
};

struct hkDisplayGeometryQ
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_type;
    int unk0C;
    hkTransformQ m_kMotionTransform;

    __forceinline static void* operator new(unsigned int nbytes)
    {
        void* b = getRouterQ()->heap().AllocateMemoryBlock(nbytes);
        static_cast<hkDisplayGeometryQ*>(b)->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void operator delete(void* p)
    {}
    __forceinline void SetGeometryTransform(const hkTransformQ& t)
    {
        m_kMotionTransform.FUN_00c6cd60(t);
    }
};

struct hkDisplayConvexQ : hkDisplayGeometryQ
{
    hkGeometryQ* m_pSourceGeometry;
    hkDisplayConvexQ(hkGeometryQ* geom);
};

struct hkDisplaySphereQ : hkDisplayGeometryQ
{
    hkSphereQ m_pSphere;
    int m_iXResolution;
    int m_iYResolution;
    int unk68;
    int unk6C;
    int unk70;
    hkDisplaySphereQ(const hkSphereQ& sphere, int xRes, int yRes);
};

struct hkDisplayBoxQ : hkDisplayGeometryQ
{
    hkVector4Q m_vHalfExtents;
    int unk60;
    hkDisplayBoxQ(const hkVector4Q& halfExtents);
};

struct hkDisplayAABBQ : hkDisplayGeometryQ
{
    hkVector4Q m_kMinimumCorner;
    hkVector4Q m_kMaximumCorner;
    int unk70;
    hkDisplayAABBQ(const hkVector4Q& min, const hkVector4Q& max);
};

struct hkDisplayConeQ : hkDisplayGeometryQ
{
    hkVector4Q m_kStartPosition;
    hkVector4Q m_kAxisEndPoints;
    hkReal m_fConeAngle;
    hkReal m_height;
    int m_iNumSegments;
    int unk7C;
    int unk80;
    hkDisplayConeQ(hkReal coneAngle, hkReal coneHeight, int numSegments, const hkVector4Q& coneAxis,
                   const hkVector4Q& startPos);
};

struct hkDisplaySemiCircleQ : hkDisplayGeometryQ
{
    hkVector4Q m_kCenterPosition;
    hkVector4Q m_vHitNormal;
    hkVector4Q m_kStartPerpendicular;
    hkReal m_fThetaMin;
    hkReal m_fThetaMax;
    hkReal m_fSphereRadius;
    int m_iNumSegments;
    int unk90;
    hkDisplaySemiCircleQ(const hkVector4Q& center, const hkVector4Q& normal, const hkVector4Q& startPerp,
                         hkReal thetaMin, hkReal thetaMax, hkReal radius, int numSegments);
};

struct hkDisplayPlaneQ : hkDisplayGeometryQ
{
    hkVector4Q m_vHitNormal;
    hkVector4Q m_kPerpendicularToNormal;
    hkVector4Q m_kCenterPosition;
    hkVector4Q m_fExtents;
    int unk90;
    hkDisplayPlaneQ(const hkVector4Q& normal, const hkVector4Q& perpToNormal, const hkVector4Q& center,
                    const hkVector4Q& extent);
};

struct hkDisplayCapsuleQ : hkDisplayGeometryQ
{
    hkVector4Q m_fMinimumV;
    hkVector4Q m_fMaximumV;
    hkReal m_fSphereRadius;
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int unk80;
    hkDisplayCapsuleQ(const hkVector4Q& top, const hkVector4Q& bottom, hkReal radius, int numSides,
                      int numHeightSegments);
};

struct hkDisplayCylinderQ : hkDisplayGeometryQ
{
    hkVector4Q m_fMinimumV;
    hkVector4Q m_fMaximumV;
    hkReal m_fSphereRadius;
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int unk80;
    hkDisplayCylinderQ(const hkVector4Q& top, const hkVector4Q& bottom, hkReal radius, int numSides,
                       int numHeightSegments);
};

struct hkDisplaySerializeIStreamQ
{
    int unk00;
    void FUN_00dd8fe0(void* buf, int elemSize, int numElems);
    void FUN_00ddac60(hkVector4Q& v);
    void FUN_00ddac80(hkTransformQ& t);
    void FUN_00ddacd0(hkGeometryQ* geom);

    __forceinline hkInt8 readInt8()
    {
        hkInt8 c;
        FUN_00dd8fe0(&c, 1, 1);
        return c;
    }
    __forceinline int readInt32()
    {
        int i;
        FUN_00dd8fe0(&i, 4, 1);
        return i;
    }
    __forceinline hkReal readFloat32()
    {
        hkReal f;
        FUN_00dd8fe0(&f, 4, 1);
        return f;
    }
    __forceinline void ReadVector4(hkVector4Q& v)
    {
        FUN_00ddac60(v);
    }
    __forceinline void ReadTransform(hkTransformQ& t)
    {
        FUN_00ddac80(t);
    }
    __forceinline void ReadGeometry(hkGeometryQ* g)
    {
        FUN_00ddacd0(g);
    }

    void FUN_00ddada0(hkDisplayGeometryQ*& geometry);
};

// @f3 0x00a62ad0 (community match, verified in this file)
struct __declspec(align(16)) VecS
{
    float x, y, z, w;
    void setAll(float f) { x=f; y=f; z=f; w=f; }
};
struct __declspec(align(16)) TransformS
{
    VecS c0, c1, c2, position;
    void FUN_008fda60(const TransformS&);
};
struct PoolNode { PoolNode* next; };
struct SmallPool { PoolNode* head; int count; };
struct ThreadAllocatorS
{
    int unk00,unk04,unk08,unk0c;
    void* allocator;
    int unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
    int batchSize;
    SmallPool pools[17];
    void* FUN_008f6800(int index, int category);
    void* FUN_008f6d30(int size, int category);
    __forceinline void* small()
    {
        PoolNode* result=pools[3].head;
        if(result) { --pools[3].count; pools[3].head=result->next; return result; }
        return FUN_008f6800(3,0x27);
    }
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
__forceinline ThreadAllocatorS* threadAllocator() { return (ThreadAllocatorS*)TlsGetValue(DAT_010f3170); }
struct GeometryS { GeometryS* FUN_00951230(); };
struct DisplayS
{
    void* vtbl;
    unsigned short size;
    short referenceCount;
    int type, unk0c;
    TransformS transform;
    DisplayS* FUN_00a67b10(GeometryS*);
    DisplayS* FUN_00a8ad20(const VecS&,int,int);
    DisplayS* FUN_009a30a0(const VecS&,const VecS&,float,int,int);
    DisplayS* FUN_009e6e10(const VecS&,const VecS&,float,int,int);
    DisplayS* FUN_00a67d60(const VecS&);
    DisplayS* FUN_00a66fa0(const VecS&,const VecS&);
    DisplayS* FUN_00a6baa0(float,float,int,const VecS&,const VecS&);
    DisplayS* FUN_00a6ac90(const VecS&,const VecS&,const VecS&,float,float,float,int);
    DisplayS* FUN_00a6b500(const VecS&,const VecS&,const VecS&,const VecS&);
    static __forceinline DisplayS* allocate(int bytes)
    {
        DisplayS* p=(DisplayS*)threadAllocator()->FUN_008f6d30(bytes,8);
        p->size=(unsigned short)bytes;
        return p;
    }
};
struct StreamS
{
    void FUN_00a60ca0(void*,int,int);
    void FUN_00a62980(VecS&);
    void FUN_00a629a0(TransformS&);
    void FUN_00a62a00(GeometryS*);
    signed char read8() { signed char c; FUN_00a60ca0(&c,1,1); return c; }
    int read32() { int i; FUN_00a60ca0(&i,4,1); return i; }
    float readFloat() { float f; FUN_00a60ca0(&f,4,1); return f; }
    void FUN_00a62ad0(DisplayS*& out);
};
// pdb: hkDisplaySerializeIStream::readDisplayGeometry | hkDisplaySerializeIStream.obj | fnv360_0822_retail, objrun, medium
// pdb params: dg
void hkDisplaySerializeIStreamQ::FUN_00ddada0(hkDisplayGeometryQ*& geometry)
{
    StreamS* self=(StreamS*)this;
    DisplayS*& out=(DisplayS*&)geometry;
    signed char type=self->read8();
    TransformS transform;
    switch(type)
    {
    case 6: {
        self->FUN_00a629a0(transform);
        GeometryS* geom=(GeometryS*)threadAllocator()->small();
        geom=geom ? geom->FUN_00951230() : 0;
        self->FUN_00a62a00(geom);
        out=DisplayS::allocate(0x60)->FUN_00a67b10(geom);
        out->transform.FUN_008fda60(transform);
        break;
    }
    case 1: {
        self->FUN_00a629a0(transform);
        float radius=self->readFloat();
        VecS position; self->FUN_00a62980(position);
        VecS sphere;
        sphere.x=position.x; sphere.y=position.y; sphere.z=position.z; sphere.w=radius;
        int xRes=self->read32(); int yRes=self->read32();
        out=DisplayS::allocate(0x80)->FUN_00a8ad20(sphere,xRes,yRes);
        out->transform.FUN_008fda60(transform);
        break;
    }
    case 8: {
        self->FUN_00a629a0(transform);
        float radius=self->readFloat();
        VecS top; self->FUN_00a62980(top);
        VecS bottom; self->FUN_00a62980(bottom);
        int sides=self->read32(); int segments=self->read32();
        out=DisplayS::allocate(0x90)->FUN_009a30a0(top,bottom,radius,sides,segments);
        out->transform.FUN_008fda60(transform);
        break;
    }
    case 9: {
        self->FUN_00a629a0(transform);
        float radius=self->readFloat();
        VecS top; self->FUN_00a62980(top);
        VecS bottom; self->FUN_00a62980(bottom);
        int sides=self->read32(); int segments=self->read32();
        out=DisplayS::allocate(0x90)->FUN_009e6e10(top,bottom,radius,sides,segments);
        out->transform.FUN_008fda60(transform);
        break;
    }
    case 2: {
        self->FUN_00a629a0(transform);
        VecS halfExtents; self->FUN_00a62980(halfExtents);
        out=DisplayS::allocate(0x70)->FUN_00a67d60(halfExtents);
        out->transform.FUN_008fda60(transform);
        break;
    }
    case 3: {
        VecS minExtent; self->FUN_00a62980(minExtent);
        VecS maxExtent; self->FUN_00a62980(maxExtent);
        out=DisplayS::allocate(0x80)->FUN_00a66fa0(minExtent,maxExtent);
        break;
    }
    case 4: {
        VecS start; self->FUN_00a62980(start);
        VecS axis; self->FUN_00a62980(axis);
        float angle=self->readFloat(); float height=self->readFloat(); int segments=self->read32();
        out=DisplayS::allocate(0x90)->FUN_00a6baa0(angle,height,segments,axis,start);
        break;
    }
    case 5: {
        VecS center; self->FUN_00a62980(center);
        VecS normal; self->FUN_00a62980(normal);
        VecS perp; self->FUN_00a62980(perp);
        float radius=self->readFloat(); float thetaMin=self->readFloat(); float thetaMax=self->readFloat(); int segments=self->read32();
        out=DisplayS::allocate(0xa0)->FUN_00a6ac90(center,normal,perp,thetaMin,thetaMax,radius,segments);
        break;
    }
    case 7: {
        VecS center; self->FUN_00a62980(center);
        VecS normal; self->FUN_00a62980(normal);
        VecS perp; self->FUN_00a62980(perp);
        float e=self->readFloat(); VecS extent; extent.setAll(e);
        out=DisplayS::allocate(0xa0)->FUN_00a6b500(normal,perp,center,extent);
        break;
    }
    }
}

