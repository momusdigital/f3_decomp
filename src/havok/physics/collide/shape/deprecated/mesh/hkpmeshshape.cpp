#include "f3_common.h"
// src/havok/physics/collide/shape/deprecated/mesh/hkpmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/mesh/hkpmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMeshShape.h"

struct MeshShapeTriangle
{
    void* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    hkVector4 vertex0, vertex1, vertex2;
};
struct __declspec(align(16)) MeshShapeBuffer
{
    hkVector4 storage[32];
};
// hkpShapeContainer: the slots of hkpMeshShape's Fallout 3 container vtable (0x00e861b8) up to getChildShape, named
// as the New Vegas Xbox 360 PDB names them.
struct MeshShapeVTable
{
    virtual ~MeshShapeVTable();
    virtual int getNumChildShapes() const;
    virtual unsigned int getFirstKey() const;
    virtual int getNextKey(unsigned int key) const;
    virtual unsigned int getCollisionFilterInfo(unsigned int key) const;
    virtual MeshShapeTriangle* getChildShape(unsigned int key, MeshShapeBuffer* storage) const;
};
extern float DAT_011b2e90;
extern "C" hkBool* __cdecl IsDegenerateTriangle(hkBool* result, const hkVector4* v0, const hkVector4* v1,
                                                const hkVector4* v2, float tolerance);
struct MeshShapeDCCBC0 : public hkpMeshShape
{
    int FUN_00dccbc0();
};
// @fnv 0x00dccbc0
// pdb: hkpMeshShape::getFirstKey | hkpMeshShape.obj | fnv360_0822_retail, objrun_open, medium
int MeshShapeDCCBC0::FUN_00dccbc0()
{
    if (*reinterpret_cast<unsigned int*>(&m_kScaling.z) == 0)
        return -1;
    MeshShapeBuffer buffer;
    MeshShapeTriangle* triangle = ((MeshShapeVTable*)this)->getChildShape(0, &buffer);
    hkBool result;
    if (!*IsDegenerateTriangle(&result, &triangle->vertex0, &triangle->vertex1, &triangle->vertex2, DAT_011b2e90))
        return 0;
    return ((MeshShapeVTable*)this)->getNextKey(0);
}

struct hkBoolDCC
{
    char m_cBooleanValue;
    hkBoolDCC(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

hkBoolDCC __cdecl IsDegenerateTriangle(const hkVector4& kA, const hkVector4& kB, const hkVector4& kC,
                                       hkReal fTolerance) throw();

struct hkpMeshShapeSubpartDCC
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iTriangleCount;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
};

struct __declspec(align(16)) hkpShapeBufferDCC
{
    hkVector4 m_kStorage[32];
};

class hkpTriangleShapeDCC
{
  public:
    int unk00[8];
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
    hkVector4 m_kVertexC;
};

class hkpMeshShapeDCC : public hkpShapeCollection
{
  public:
    virtual void V1() const throw();
    virtual void V2() const throw();
    virtual void V3() const throw();
    virtual void V4() const throw();
    virtual const hkpShape* GetShapeForKey(hkUint32 key, hkpShapeBufferDCC* buffer) const throw();

    int unk18;
    int unk1C;
    int m_iNumBitsForSubpartIndex;
    hkArray<hkpMeshShapeSubpartDCC> m_kSubparts;

    hkUint32 hkpMeshShape_getNextKey(hkUint32 oldKey) const throw();
};

// @f3 0x00a45530 (community match, verified in this file)
// pdb: hkpMeshShape::getNextKey | hkpMeshShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: initialKey
// pdb: hkpMeshShape::getNextKey | hkpMeshShape.obj | fnv360_0822_retail, bridge_fnvpc, high (was: GetNextNonDegenerateTriangleKey)
hkUint32 hkpMeshShapeDCC::hkpMeshShape_getNextKey(hkUint32 auiKey) const throw()
{
    hkpShapeBufferDCC buffer;

    hkUint32 subPart = auiKey >> (32 - m_iNumBitsForSubpartIndex);
    int triIndex = auiKey & (0xffffffff >> m_iNumBitsForSubpartIndex);

    while (true)
    {
        if (++triIndex >= m_kSubparts.m_data[subPart].m_iTriangleCount)
        {
            if (++subPart >= static_cast<hkUint32>(m_kSubparts.m_iElementCount))
                return 0xffffffff;
            triIndex = 0;
        }
        hkUint32 key = (subPart << (32 - m_iNumBitsForSubpartIndex)) | triIndex;
        const hkpTriangleShapeDCC* pkTri = reinterpret_cast<const hkpTriangleShapeDCC*>(GetShapeForKey(key, &buffer));
        if (!IsDegenerateTriangle(pkTri->m_kVertexA, pkTri->m_kVertexB, pkTri->m_kVertexC, 1e-7f))
            return key;
    }
}


int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayDCD1
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
};

class hkStatisticsCollectorDCD1
{
  public:
    virtual ~hkStatisticsCollectorDCD1() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    bool m_countDontDeallocate;

    template <class T> __forceinline void addArray(const char* pcName, const hkArrayDCD1<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

struct PageDCCD
{
    char unk00[0x20];
    unsigned char* m_pIndexData;
    int m_iIndexStride;
    void** m_ppValues;
    int m_iValueStride;
    char unk30[8];
};

class Base0DCCD
{
  public:
    virtual ~Base0DCCD();
    int unk04[3];
};

// hkpShapeContainer (the hkpMeshShape subobject at +0x10)
class Base1DCCD
{
  public:
    virtual ~Base1DCCD();
    void* FindValue(unsigned int uiKey);
};

class FUN_00dccd00_C : public Base0DCCD, public Base1DCCD
{
  public:
    char unk14[0x1c];
    int m_iShift;
    PageDCCD* m_pkPages;

    int GetElement(unsigned int uiKey);
};

// Gets an index for uiKey from GetElement on the owner; if found, returns the pointer stored in that page's value array, otherwise null.
// @fnv 0x00dccd00
// pdb: hkpMeshShape::getCollisionFilterInfo | hkpMeshShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: key
void* Base1DCCD::FindValue(unsigned int uiKey)
{
    FUN_00dccd00_C* pkOwner = (FUN_00dccd00_C*)((char*)this - 0x10);
    int iIndex = pkOwner->GetElement(uiKey);
    if (iIndex != -1)
    {
        PageDCCD* pkPage = &pkOwner->m_pkPages[uiKey >> (32 - pkOwner->m_iShift)];
        void** ppValue = (void**)((char*)pkPage->m_ppValues + pkPage->m_iValueStride * iIndex);
        if (ppValue)
            return *ppValue;
    }
    return 0;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_setr_ps(float, float, float, float);

struct Msh_dccf60_Subpart
{
    const char* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const char* m_pMaterialDataBase;
    char m_ucIndexStridingType;
    char m_pad11;
    char m_pad12;
    char m_pad13;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_weldingInfoOffset;
};

struct Msh_dccf60_V
{
    __m128 m_vComponents;
    inline void set(float a, float b, float c, float d = 0.0f)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
};

struct Msh_dccf60_Ref
{
    virtual ~Msh_dccf60_Ref();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    Msh_dccf60_Ref()
    {
        m_sReferenceCount = 1;
    }
};

struct Msh_dccf60_Shape : public Msh_dccf60_Ref
{
    hkUlong m_ulUserData;
    hkUint32 m_type;
    Msh_dccf60_Shape(hkUint32 type)
    {
        m_ulUserData = 0;
        m_type = type;
    }
};

class Msh_dccf60_Tri : public Msh_dccf60_Shape
{
  public:
    inline void* operator new(size_t, void* p)
    {
        return p;
    }
    hkReal m_fSphereRadius;
    hkUint16 m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    hkUint8 m_ucWeldingPadding;
    int m_unk18;
    int m_unk1c;
    __m128 m_kVertexA;
    __m128 m_kVertexB;
    __m128 m_kVertexC;
    __m128 m_kVertexTransform;

    Msh_dccf60_Tri(hkReal radius, hkUint16 weldingInfo, int weldingType) : Msh_dccf60_Shape(3)
    {
        m_fSphereRadius = radius;
        m_kWeldingInfo = weldingInfo;
        m_eWeldingType = weldingType;
        m_kVertexTransform = _mm_setzero_ps();
        m_ucWeldingPadding = 0;
    }
    virtual ~Msh_dccf60_Tri();
};

class Msh_dccf60_Mesh
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArray<Msh_dccf60_Subpart> m_kSubparts;
    hkArray<hkUint16> m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    char m_pad3d;
    char m_pad3e;
    char m_pad3f;
    hkReal m_fSphereRadius;

    const void* CreateTriangle(unsigned int key, void* buffer) const;
};

// Extracts a triangle's vertex data from subpart index arrays, scales it, and constructs a Msh_dccf60_Tri in the provided buffer.
// @f3 0x00a45a70 (community match, verified in this file)
struct __declspec(align(16)) Msh_dccf60_VF3
{
    float x, y, z, w;
};

extern int DAT_01269b28;

struct __declspec(novtable) RefPrefix2129 {
    virtual ~RefPrefix2129();
    hkUint16 m_usMemSizeAndFlags;
    volatile hkInt16 m_sReferenceCount;
    RefPrefix2129(){m_sReferenceCount=1;}
};
struct __declspec(novtable) ShapePrefix2129:RefPrefix2129 {
    hkUlong m_ulUserData;
    hkUint32 m_type;
    ShapePrefix2129(){}
};
class __declspec(novtable) Msh_dccf60_TriF3 : public ShapePrefix2129
{
  public:
    hkReal m_fSphereRadius;
    hkUint16 m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    hkUint8 m_ucWeldingPadding;
    int m_unk18;
    int m_unk1c;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
    hkVector4 m_kVertexC;
    hkVector4 m_kVertexTransform;

    inline void* operator new(size_t, void* p)
    {
        return p;
    }
    Msh_dccf60_TriF3(const volatile hkReal& radius, hkUint16 weldingInfo, int weldingType) : ShapePrefix2129()
    {
        m_fSphereRadius = radius;
        m_ulUserData=0;
        m_type=4;
        *(void**)this = &DAT_01269b28;
        static_cast<volatile hkUint16&>(m_kWeldingInfo) = weldingInfo;
        static_cast<volatile hkUint8&>(m_eWeldingType) = weldingType;
        static_cast<volatile hkReal&>(m_kVertexTransform.w) = 0.0f;
        static_cast<volatile hkReal&>(m_kVertexTransform.z) = 0.0f;
        static_cast<volatile hkReal&>(m_kVertexTransform.y) = 0.0f;
        static_cast<volatile hkReal&>(m_kVertexTransform.x) = 0.0f;
        static_cast<volatile hkUint8&>(m_ucWeldingPadding) = 0;
    }
    virtual ~Msh_dccf60_TriF3();
};

// pdb: hkpMeshShape::getChildShape | hkpMeshShape.obj | tesv_win, objrun_sim, low
const void* Msh_dccf60_Mesh::CreateTriangle(unsigned int key, void* buffer) const
{
    unsigned int triangleIndex = key & (~0U >> m_iNumBitsForSubpartIndex);
    const Msh_dccf60_Subpart& subpart = m_kSubparts.m_data[key >> (32 - m_iNumBitsForSubpartIndex)];

    int flip = subpart.m_bFlipAlternateTriangles & triangleIndex;
    const float *v0 = 0, *v1, *v2;
    if (subpart.m_ucIndexStridingType == 1)
    {
        const unsigned short* pIndices16 =
            (const unsigned short*)(subpart.m_pMaterialDataBase + subpart.m_iMaterialStriding * triangleIndex);
        v0 = (const float*)(subpart.m_pMaterialIndexBase + pIndices16[0] * subpart.m_iTriangleIndexStride);
        v1 = (const float*)(subpart.m_pMaterialIndexBase + pIndices16[1 + flip] * subpart.m_iTriangleIndexStride);
        v2 = (const float*)(subpart.m_pMaterialIndexBase + pIndices16[1 + (flip ^ 1)] * subpart.m_iTriangleIndexStride);
    }
    else
    {
        const unsigned int* pIndices32 =
            (const unsigned int*)(subpart.m_pMaterialDataBase + subpart.m_iMaterialStriding * triangleIndex);
        v0 = (const float*)(subpart.m_pMaterialIndexBase + pIndices32[0] * subpart.m_iTriangleIndexStride);
        v1 = (const float*)(subpart.m_pMaterialIndexBase + pIndices32[1 + flip] * subpart.m_iTriangleIndexStride);
        v2 = (const float*)(subpart.m_pMaterialIndexBase + pIndices32[1 + (flip ^ 1)] * subpart.m_iTriangleIndexStride);
    }

    Msh_dccf60_VF3 vVertexA;
    vVertexA.x = v0[0] * m_kScaling.x;
    vVertexA.y = v0[1] * m_kScaling.y;
    vVertexA.z = v0[2] * m_kScaling.z;
    Msh_dccf60_VF3 vVertexB;
    vVertexB.x = v1[0] * m_kScaling.x;
    vVertexB.y = v1[1] * m_kScaling.y;
    vVertexB.z = v1[2] * m_kScaling.z;
    Msh_dccf60_VF3 vVertexC;
    vVertexC.x = v2[0] * m_kScaling.x;
    vVertexC.y = v2[1] * m_kScaling.y;
    vVertexC.z = v2[2] * m_kScaling.z;

    hkUint16 weldingInfo;
    if (m_kWeldingInfo.m_iElementCount == 0)
    {
        weldingInfo = 0;
    }
    else
    {
        weldingInfo = m_kWeldingInfo.m_data[subpart.m_weldingInfoOffset + triangleIndex];
    }

    Msh_dccf60_TriF3* pTriangle;
    if(buffer) {
        volatile hkReal radiusValue=m_fSphereRadius;
        pTriangle=new(buffer)Msh_dccf60_TriF3(radiusValue,weldingInfo,m_eWeldingType);
    } else pTriangle=0;
    pTriangle->m_kVertexA.x = vVertexA.x;
    pTriangle->m_kVertexA.y = vVertexA.y;
    pTriangle->m_kVertexA.z = vVertexA.z;
    pTriangle->m_kVertexA.w = 0.0f;
    pTriangle->m_kVertexB.x = vVertexB.x;
    pTriangle->m_kVertexB.y = vVertexB.y;
    pTriangle->m_kVertexB.z = vVertexB.z;
    pTriangle->m_kVertexB.w = 0.0f;
    pTriangle->m_kVertexC.x = vVertexC.x;
    pTriangle->m_kVertexC.y = vVertexC.y;
    pTriangle->m_kVertexC.z = vVertexC.z;
    pTriangle->m_kVertexC.w = 0.0f;
    return pTriangle;
}


namespace fnv_00dcd310 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_set_ps1(float fA);

struct hkVector4DCD3
{
    __m128 m_vComponents;

    hkVector4DCD3()
    {}
    hkVector4DCD3(const hkVector4DCD3& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4DCD3& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void SetAllComponents(float fA)
    {
        m_vComponents = _mm_set_ps1(fA);
    }
};

template <class T> struct hkArrayDCD3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayDCD3() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

}  // namespace fnv_00dcd310

struct PageDCD4
{
    char unk00[0x11];
    unsigned char m_ucElemSize;
    char unk12[0xe];
    unsigned char* m_pData;
    int m_iArrayCapacity;
    char unk28[0x10];
};

class FUN_00dcd410_C
{
  public:
    char unk00[0x30];
    int m_iShift;
    PageDCD4* m_pkPages;

    int GetElement(unsigned int uiKey);
};

// Looks up the element at uiKey in the paged array, returning its byte or short value, or -1 if the page is not allocated.
// @fnv 0x00dcd410
// pdb: hkpMeshShape::getMeshMaterial | hkpMeshShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkpMeshShape::getMaterialIndex)
// pdb params: key
int FUN_00dcd410_C::GetElement(unsigned int uiKey)
{
    unsigned int uiPage = uiKey >> (32 - m_iShift);
    PageDCD4* pkPage = &m_pkPages[uiPage];
    if (pkPage->m_pData)
    {
        unsigned char* p = pkPage->m_pData + (uiKey & (0xffffffff >> m_iShift)) * pkPage->m_iArrayCapacity;
        if (pkPage->m_ucElemSize == 1)
            return *p;
        return *(unsigned short*)p;
    }
    return -1;
}

extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
struct MeshVec
{
    __m128 m_vComponents;
    inline void set(float a, float b, float c, float d = 0.0f)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    void FUN_00c7f640(const hkTransform& t, const MeshVec& v);
};
struct MeshAabb
{
    MeshVec m_kMinimumCorner;
    MeshVec m_kMaximumCorner;
};
// Scales a vertex, transforms it to world space, and expands the AABB's min and max corners to include it.
// @fnv 0x00dccd50
static __declspec(noinline) void ExpandAabbWithVertex(const MeshVec& vertex, const hkTransform& localToWorld,
                                                      const MeshVec& scaling, MeshAabb& aabb)
{
    MeshVec scaled;
    scaled.set(vertex.m_vComponents.m128_f32[0] * scaling.m_vComponents.m128_f32[0],
               vertex.m_vComponents.m128_f32[1] * scaling.m_vComponents.m128_f32[1],
               vertex.m_vComponents.m128_f32[2] * scaling.m_vComponents.m128_f32[2]);
    MeshVec v;
    v.FUN_00c7f640(localToWorld, scaled);
    aabb.m_kMinimumCorner.m_vComponents = _mm_min_ps(aabb.m_kMinimumCorner.m_vComponents, v.m_vComponents);
    aabb.m_kMaximumCorner.m_vComponents = _mm_max_ps(aabb.m_kMaximumCorner.m_vComponents, v.m_vComponents);
}
volatile int g_meshIn0, g_meshIn1, g_meshIn2, g_meshIn3;

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S00dcd380_Flag
{
    int m_bFinishing;
};

class S00dcd380_Shape
{
  public:
    __forceinline S00dcd380_Shape(S00dcd380_Flag flag)
    {
        if (flag.m_bFinishing)
            m_type = 0;
    }
    virtual ~S00dcd380_Shape();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};

class S00dcd380_Container
{
  public:
    __forceinline S00dcd380_Container()
    {}
    virtual ~S00dcd380_Container();
};

class S00dcd380_Collection : public S00dcd380_Shape, public S00dcd380_Container
{
  public:
    __forceinline S00dcd380_Collection(S00dcd380_Flag flag) : S00dcd380_Shape(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_eCollectionType = 3;
        }
    }
    virtual ~S00dcd380_Collection();
    bool m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct S00dcd380_Sub
{
    const float* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    unsigned char m_ucIndexStridingType;
    unsigned char m_iMaterialIndexType;
    short unk12;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iNumTriangles;
    int m_iIndexStriding;
    int m_iTriangleOffset;
};

class S00dcd380_Mesh : public S00dcd380_Collection
{
  public:
    __forceinline S00dcd380_Mesh(S00dcd380_Flag flag) : S00dcd380_Collection(flag)
    {
        if (flag.m_bFinishing)
        {
            for (int i = 0; i < m_iElementCount; i++)
            {
                unsigned char& type = m_data[i].m_iMaterialIndexType;
                if (type == 0)
                    type = 1;
            }
            m_type = 0x17;
            m_eCollectionType = 5;
        }
    }
    virtual ~S00dcd380_Mesh();
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    S00dcd380_Sub* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct MeshAabb;

extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
struct hkpMeshShapeSubpart
{
    const float* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    hkUint8 m_ucIndexStridingType;
    hkUint8 m_iMaterialIndexType;
    hkUint16 unk12;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iNumTriangles;
    int m_iIndexStriding;
    int m_iTriangleOffset;
};
static const float kRealMax = 3.402820018375656e+38f;
static const float kRealMin = -3.402820018375656e+38f;
__forceinline void setSplat(MeshVec& v, float f)
{
    v.m_vComponents = _mm_set_ps1(f);
}
__forceinline void subtract(MeshVec& a, const MeshVec& b)
{
    a.m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void add(const MeshVec& b, MeshVec& a)
{
    a.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
class MeshShapeHelper : public hkpMeshShape
{
  public:
    void FUN_00dccdd0(const hkTransform& transform, hkReal tolerance, MeshAabb& out) const;
};
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* p, long n)
{
    return (const T*)((const char*)p + n);
}
static __declspec(noinline) void ExpandAabbWithVertex(MeshAabb& b, const hkTransform& t, const float* p,
                                                      const hkVector4& s)
{
    MeshVec local;
    local.set(p[0] * s.x, p[1] * s.y, p[2] * s.z);
    MeshVec world;
    world.FUN_00c7f640(t, local);
    b.m_kMinimumCorner.m_vComponents = _mm_min_ps(b.m_kMinimumCorner.m_vComponents, world.m_vComponents);
    b.m_kMaximumCorner.m_vComponents = _mm_max_ps(b.m_kMaximumCorner.m_vComponents, world.m_vComponents);
}
// Computes the world-space AABB of all subpart triangles, then expands it by margin plus m_fSphereRadius.
// @f3 0x00a457b0 (community match, verified in this file)
// pdb: hkpMeshShape::getAabbImpl | hkpMeshShape.obj | tesv_win, objrun_sim, low
void MeshShapeHelper::FUN_00dccdd0(const hkTransform& transform, hkReal tolerance, MeshAabb& out) const
{
    out.m_kMinimumCorner.m_vComponents.m128_f32[0] = kRealMax;
    out.m_kMinimumCorner.m_vComponents.m128_f32[1] = kRealMax;
    out.m_kMinimumCorner.m_vComponents.m128_f32[2] = kRealMax;
    out.m_kMinimumCorner.m_vComponents.m128_f32[3] = 0.0f;
    out.m_kMaximumCorner.m_vComponents.m128_f32[0] = kRealMin;
    out.m_kMaximumCorner.m_vComponents.m128_f32[1] = kRealMin;
    out.m_kMaximumCorner.m_vComponents.m128_f32[2] = kRealMin;
    out.m_kMaximumCorner.m_vComponents.m128_f32[3] = 0.0f;
    for (int i = 0; i < m_kSubparts.m_iElementCount; ++i)
    {
        const hkpMeshShapeSubpart& part = m_kSubparts.m_data[i];
        for (int j = 0; j < part.m_iTriangleCount; ++j)
        {
            const float* a;
            const float* b;
            const float* c;
            if (part.m_ucIndexStridingType == 1)
            {
                const hkUint16* indices =
                    hkAddByteOffsetConst((const hkUint16*)part.m_pMaterialDataBase, part.m_iMaterialStriding * j);
                a = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[0] * part.m_iTriangleIndexStride);
                b = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[1] * part.m_iTriangleIndexStride);
                c = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[2] * part.m_iTriangleIndexStride);
            }
            else
            {
                const hkUint32* indices =
                    hkAddByteOffsetConst((const hkUint32*)part.m_pMaterialDataBase, part.m_iMaterialStriding * j);
                a = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[0] * part.m_iTriangleIndexStride);
                b = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[1] * part.m_iTriangleIndexStride);
                c = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[2] * part.m_iTriangleIndexStride);
            }
            ExpandAabbWithVertex(out, transform, a, m_kScaling);
            ExpandAabbWithVertex(out, transform, b, m_kScaling);
            ExpandAabbWithVertex(out, transform, c, m_kScaling);
        }
    }
    __declspec(align(16)) float aligner;
    aligner = m_fSphereRadius + tolerance;
    const float pad = aligner;
    out.m_kMinimumCorner.m_vComponents.m128_f32[0] -= pad;
    out.m_kMinimumCorner.m_vComponents.m128_f32[1] -= pad;
    out.m_kMinimumCorner.m_vComponents.m128_f32[2] -= pad;
    out.m_kMinimumCorner.m_vComponents.m128_f32[3] -= pad;
    out.m_kMaximumCorner.m_vComponents.m128_f32[0] += pad;
    out.m_kMaximumCorner.m_vComponents.m128_f32[1] += pad;
    out.m_kMaximumCorner.m_vComponents.m128_f32[2] += pad;
    out.m_kMaximumCorner.m_vComponents.m128_f32[3] += pad;
}
