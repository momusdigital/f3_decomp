#include "f3_common.h"
// src/havok/animation/animation/animation/hkaanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/hkaanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaAnimation.h"

// @fnv 0x00e2f270
// pdb: hkDisplaySphere::getWireframeGeometry | hkDisplaySphere.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void __stdcall FUN_00e2f270(int)
{}

struct FUN_00cb0c30_s
{
    char* m_pcString;
    void FUN_00cb0c30(const FUN_00cb0c30_s& kOther) throw();
};
class hkaAnnotationTrack
{
  public:
    struct Annotation
    {
        hkReal m_uiCommandId;
        FUN_00cb0c30_s m_pText;

        Annotation& operator=(const Annotation& kOther)
        {
            m_uiCommandId = kOther.m_uiCommandId;
            m_pText.FUN_00cb0c30(kOther.m_pText);
            return *this;
        }
    };
    FUN_00cb0c30_s m_kTrackName;
    hkArray<Annotation> m_kAnnotations;
};

static const double kNegOne = -3.402820018375656e+38;

class hkMemoryAllocatorE2F;

struct hkMemoryRouterE2F
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE2F* m_pStreamAllocator;

    hkMemoryAllocatorE2F& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE2F {
extern "C" hkMemoryRouterE2F& __cdecl FUN_00c85750() throw();
}

void __cdecl FUN_00c908c0(hkMemoryAllocatorE2F& kAlloc, void* pArray, int iNumElements, int iSizeElem);

inline void* operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}
struct TrackE2F
{
    int unk00, unk04, unk08, unk0C;

    TrackE2F(const TrackE2F& other);
    ~TrackE2F();
    TrackE2F& operator=(const TrackE2F& other);
};

struct RefFrameE2F
{
    void FUN_00c90510();
    void FUN_00c905b0();
};

template <class T> __forceinline void destructE2F(T* pArr, int n)
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}

template <class T> __forceinline void copyE2F(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <class T> __forceinline void constructWithArrayE2F(T* pDst, int n, const T* pSrc)
{
    for (int i = 0; i < n; i++)
        ::new (static_cast<void*>(pDst + i)) T(pSrc[i]);
}

template <class T> class hkArrayE2F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE2F() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void reserve(hkMemoryAllocatorE2F& kAlloc, int n)
    {
        if (getCapacity() < n)
        {
            int iCap2 = 2 * getCapacity();
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }

    __forceinline hkArrayE2F& operator=(const hkArrayE2F& a)
    {
        hkMemoryAllocatorE2F& kAlloc = hkRouterE2F::FUN_00c85750().heap();
        const int iOldSize = m_iElementCount;
        const int iNewSize = a.m_iElementCount;
        int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
        reserve(kAlloc, iNewSize);
        destructE2F(m_data + iNewSize, iOldSize - iNewSize);
        copyE2F(m_data, a.m_data, iCopiedSize);
        constructWithArrayE2F(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
        m_iElementCount = iNewSize;
        return *this;
    }
};

struct RefPtrE2F
{
    RefFrameE2F* m_pRetainedObject;

    RefPtrE2F() : m_pRetainedObject(0)
    {}
    __forceinline void operator=(const RefPtrE2F& other)
    {
        if (other.m_pRetainedObject)
            other.m_pRetainedObject->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = other.m_pRetainedObject;
    }
};

class ReferencedObjectE2F
{
  public:
    ReferencedObjectE2F()
    {
        m_sReferenceCount = 1;
    }
    virtual ~ReferencedObjectE2F();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
