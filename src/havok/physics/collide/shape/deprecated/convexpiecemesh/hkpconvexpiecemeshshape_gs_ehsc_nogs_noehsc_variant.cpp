#include "f3_common.h"
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpConvexPieceMeshShape.h"
struct HkpStandIn;
struct HkpStandIn
{
    virtual void v0() = 0;

    void FUN_00e490d0();
    HkpStandIn* FUN_00e01010(int flags);

    unsigned short value;
};
struct FUN_00e49290_Target
{
// @fnv 0x00e49290
    virtual int FUN_00e49290_f0(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f1(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f2(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f3(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f4(int)
    {
        return 0;
    }
};
struct Ref
{
    void FUN_00c905b0() throw();
};
struct P
{
    virtual ~P()
    {}
    int a, b, c;
};
struct S
{
    virtual ~S()
    {}
    int d;
};
struct Ptr
{
    Ref* p;
    ~Ptr()
    {
        p->FUN_00c905b0();
    }
};
struct D : P, S
{
    Ptr m18;
    Ptr m1c;
    __forceinline ~D()
    {}
    void FUN_00e490d0();
};
int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();
template <class T> class hkArrayE494
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
class hkStatisticsCollectorE494
{
  public:
    virtual ~hkStatisticsCollectorE494() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayE494<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

#include <xmmintrin.h>
inline void* __cdecl operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}

class hkBoolE49
{
  public:
    hkBoolE49(bool b) : m_cBooleanValue((char)b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct hkVector4E49
{
    __m128 m_vComponents;

    inline hkVector4E49& operator=(const hkVector4E49& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct ShapeBufferE49
{
    __declspec(align(16)) unsigned char m_data[0x200];
};

class TriangleShapeE49
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4E49 m_kVertices[3];
};

class ShapeContainerE49
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual const TriangleShapeE49* GetShapeForKey(int iKey, ShapeBufferE49& kBuffer) const;
};

class MeshShapeE49
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShapeContainerE49 m_container;
};

struct FaceTableE49
{
    int unk00;
    int unk04;
    int* m_piFaceData;
    int unk0c;
    int unk10;
    int* m_piFaceStart;
    unsigned int m_uiNumFaces;
    int unk1c;
    int* m_piTriangleKeys;
};

class FUN_00e607c0
{
  public:
    FUN_00e607c0(float fRadius);

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkVector4E49* m_pkVertices;
    int m_iNumVertices;
    MeshShapeE49* m_pkMesh;
    int* m_piKeys;
    int m_iNumKeys;
};

class PieceBaseE49
{
  public:
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
};

class PieceAgentE49
{
  public:
    virtual void unk00();
    int unk04;
    FaceTableE49* m_pkFaces;
    MeshShapeE49* m_pkMesh;
    float m_fBoundRadius;

    FUN_00e607c0* FUN_00e49120(unsigned int uiIndex, void* pvMemory);
};

class PieceSourceE49 : public PieceBaseE49, public PieceAgentE49
{
  public:
    __declspec(noinline) hkBoolE49 FUN_00e49040(const int* piFace, int m_iEdgeNumber) const
    {
        int iWord = m_iEdgeNumber / 31;
        int iBit = m_iEdgeNumber % 31;
        return (piFace[piFace[0] + iWord + 1] & (1 << iBit)) != 0;
    }
};

// @f3 0x00a77090 (community match, verified in this file)
struct VecF49 {
    float x, y, z, w;
    inline VecF49& operator=(const VecF49& v)
    {
        x = v.x; y = v.y; z = v.z; w = v.w;
        return *this;
    }
};
struct KeyEvaluatorE49 {
    hkBoolE49 FUN_00a76f80(const int* face, int edge) const;
};
// pdb: hkpConvexPieceMeshShape::getAabbImpl | hkpConvexPieceMeshShape.obj | fnv360_0822_debug, objrun, low, conflict (bridge: hkpConvexPieceMeshShape::getChildShape)
// pdb params: localToWorld, tolerance, out
FUN_00e607c0* PieceAgentE49::FUN_00e49120(unsigned int index, void* placement)
{
    FUN_00e607c0* result = placement ? new (placement) FUN_00e607c0(m_fBoundRadius) : 0;
    result->m_pkMesh = m_pkMesh;
    VecF49* pv;
    if (index < m_pkFaces->m_uiNumFaces)
    {
        int face = m_pkFaces->m_piFaceStart[index];
        int* keys = m_pkFaces->m_piFaceData + face;
        result->m_iNumKeys = keys[0];
        result->m_piKeys = keys + 1;
        placement = reinterpret_cast<void*>((reinterpret_cast<unsigned long>(placement) + 0x3b) & ~15UL);
        result->m_pkVertices = reinterpret_cast<hkVector4E49*>(placement);
        result->m_iNumVertices = 0;
        for (int i = 0; i < result->m_iNumKeys; ++i)
        {
            int key = result->m_piKeys[i];
            ShapeBufferE49 buffer;
            const TriangleShapeE49* tri = m_pkMesh->m_container.GetShapeForKey(key, buffer);
            for (int j = 0; j < 3; ++j)
            {
                if (((KeyEvaluatorE49*)((char*)this - 0x10))->FUN_00a76f80(keys, 3 * i + j))
                {
                    *reinterpret_cast<VecF49*>(placement) = reinterpret_cast<const VecF49&>(tri->m_kVertices[j]);
                    placement = reinterpret_cast<VecF49*>(placement) + 1;
                    ++result->m_iNumVertices;
                }
            }
        }
    }
    else
    {
        result->m_iNumKeys = 1;
        int* keys = result->m_piKeys = m_pkFaces->m_piTriangleKeys + (index - m_pkFaces->m_uiNumFaces);
        placement = reinterpret_cast<void*>((reinterpret_cast<unsigned long>(placement) + 0x3b) & ~15UL);
        result->m_pkVertices = reinterpret_cast<hkVector4E49*>(placement);
        result->m_iNumVertices = 3;
        int key = keys[0];
        ShapeBufferE49 buffer;
        const TriangleShapeE49* tri = m_pkMesh->m_container.GetShapeForKey(key, buffer);
        pv = reinterpret_cast<VecF49*>(placement);
        pv[0] = reinterpret_cast<const VecF49&>(tri->m_kVertices[0]);
        pv[1] = reinterpret_cast<const VecF49&>(tri->m_kVertices[1]);
        pv[2] = reinterpret_cast<const VecF49&>(tri->m_kVertices[2]);
    }
    return result;
}


struct xVec4
{
    __m128 m_vComponents;
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void setMin4(const xVec4& a, const xVec4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const xVec4& a, const xVec4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};
typedef __declspec(align(16)) int xShapeBuffer[128];
