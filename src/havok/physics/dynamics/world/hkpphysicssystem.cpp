#include "f3_common.h"
// src/havok/physics/dynamics/world/hkpphysicssystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpphysicssystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPhysicsSystem.h"

// @fnv 0x00cb0020
// pdb: hkpConstraintData::isBuildJacobianCallbackRequired | bhkMalleableConstraint.obj | fnv360_0822_retail, vtable, high
void __stdcall FUN_00cb0020(unsigned char* output)
{
    *output = 0;
}

inline void memMoveD062(void* pvDst, const void* pvSrc, int iNumBytes)
{
    for (int i = 0; i < iNumBytes; i += 4)
        *(int*)((char*)pvDst + i) = *(const int*)((const char*)pvSrc + i);
}

template <typename T> struct hkArrayD062
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAtAndCopy(int iIndex)
    {
        m_iElementCount--;
        memMoveD062(m_data + iIndex, m_data + iIndex + 1, (m_iElementCount - iIndex) * sizeof(T));
    }
};

typedef unsigned int Size64;
inline void* __cdecl operator new(Size64, void* p)
{
    return p;
}
struct Shape64
{
    void __thiscall FUN_00c90510();
};
typedef Shape64* ShapePtr64;
struct Array64
{
    ShapePtr64* items;
    int size;
    unsigned int capacityAndFlags;
};
struct Router64
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};
Router64* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, Array64* array, int elementSize);

struct FUN_00cb0b80
{
    char* m_kStringBuffer;
    FUN_00cb0b80(const char* s) throw();
};

template <class T> struct hkArrayD065
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayD065() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkRefObjD065
{
  public:
    virtual ~hkRefObjD065() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjD065()
    {
        m_sReferenceCount = 1;
    }
};

class FUN_00d065e0 : public hkRefObjD065
{
  public:
    hkArrayD065<void*> m_kPointA;
    hkArrayD065<void*> m_kPointB;
    hkArrayD065<void*> m_iThirdValue;
    hkArrayD065<void*> m_iFourthElementInteger;
    FUN_00cb0b80 m_name;
    int m_3c;
    bool m_40;

    FUN_00d065e0() throw();
    virtual ~FUN_00d065e0() throw();
};

// Initializes the object's name, m_3c to 0 and m_40 to true, leaving the four arrays default-constructed.
// @f3 0x009b02d0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009b02d0 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long index);
struct ThreadMemory9b {
    void* FUN_008f6d30(int bytes, int memClass);
    static ThreadMemory9b& getInstance() { return *(ThreadMemory9b*)DAT_00d9b080(DAT_010f3170); }
};
struct Flag9b {
    char m_value;
    Flag9b(bool b) : m_value(b) {}
};
struct Member9b {
    int unk00, unk04, unk08, unk0c;
    Member9b(Flag9b flag) throw();
};
class Object9b : public hkRefObjD065 {
  public:
    Member9b m_member;
    static void* operator new(Size64 bytes) {
        hkRefObjD065* p = static_cast<hkRefObjD065*>(ThreadMemory9b::getInstance().FUN_008f6d30(bytes, 0x15));
        p->m_usMemSizeAndFlags = (unsigned short)bytes;
        return p;
    }
    __forceinline Object9b(Flag9b flag) throw() : m_member(flag) {}
    virtual ~Object9b() throw();
};

// pdb: hkTypeInfoRegistry::hkTypeInfoRegistry | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, caller_sim, low
// pdb params: finishFlag
Object9b* __cdecl FUN_009b02d0() {
    Flag9b flag(false);
    return new Object9b(flag);
}
}   // namespace f3m_009b02d0


namespace fnv_00d06c00 {
struct FnvCpu_FUN_00d06c00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d06c00_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d06c00_CpuAllocator* allocator;
};
FnvCpu_FUN_00d06c00_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d06c00

class hkMemoryAllocatorD29
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterD29
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD29* m_pStreamAllocator;
    hkMemoryAllocatorD29& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterD29& __cdecl GetMemoryRouterD29() throw();

template <class T> __forceinline void copyD29(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}
template <class T> class hkArrayD29
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline hkArrayD29& operator=(const hkArrayD29& a)
    {
        hkMemoryAllocatorD29& kAlloc = GetMemoryRouterD29().heap();
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = a.m_iElementCount;
        copyD29(m_data, a.m_data, m_iElementCount);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkStringPtrD29
{
  public:
    hkStringPtrD29& operator=(const hkStringPtrD29& kOther);
    const char* m_pcText;
};

template <int SIZE> __forceinline void memCpyOneAlignedD064(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterD064
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterD064 {
extern "C" hkMemoryRouterD064& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayD064
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterD064& router = hkRouterD064::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedD064<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

template <int SIZE> __forceinline void memCpyOneAlignedXd06540(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd06540
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd06540 {
extern "C" hkMemoryRouterXd06540& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXd06540
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXd06540& router = hkRouterXd06540::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd06540<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

template <int SIZE> __forceinline void memCpyOneAlignedXd06590(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd06590
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd06590 {
extern "C" hkMemoryRouterXd06590& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXd06590
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXd06590& router = hkRouterXd06590::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd06590<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

#include <xmmintrin.h>
__declspec(align(16)) struct AlignedVector4
{
    float x, y, z, w;
    __forceinline AlignedVector4& operator=(const AlignedVector4& o)
    {
        *(__m128*)this = *(__m128*)&o;
        return *this;
    }
};

__declspec(align(16)) struct AlignedTransform
{
    AlignedVector4 m_kColumn0;
    AlignedVector4 m_kColumn1;
    AlignedVector4 m_kColumn2;
    AlignedVector4 m_vTranslation;

    AlignedTransform()
    {}
    AlignedTransform(const AlignedTransform& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_vTranslation = o.m_vTranslation;
    }

    void FUN_00cb23e0(const hkTransform* other);
};

struct RefObj
{
    void __thiscall FUN_00c905b0();
};

inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d061
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

namespace fnv_00d061f0 {
struct RefObj
{
    void __thiscall FUN_00c905b0();
};

inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d061
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

}  // namespace fnv_00d061f0

struct __declspec(align(16)) TerrainVec
{
    __m128 q;
    float& lane(int i)
    {
        return reinterpret_cast<float*>(&q)[i];
    }
    const float& lane(int i) const
    {
        return reinterpret_cast<const float*>(&q)[i];
    }
    TerrainVec& operator=(const TerrainVec& b)
    {
        q = b.q;
        return *this;
    }
    void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
    void multiply(const TerrainVec& a, const TerrainVec& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    void add(const TerrainVec& a, const TerrainVec& b)
    {
        q = _mm_add_ps(a.q, b.q);
    }
    void multiply(const TerrainVec& b)
    {
        q = _mm_mul_ps(q, b.q);
    }
    void add(const TerrainVec& b)
    {
        q = _mm_add_ps(q, b.q);
    }
    __m128 sum3() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
        return _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), xy);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        TerrainVec square;
        square.q = _mm_mul_ps(q, q);
        __m128 len = square.sum3();
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 estimate = _mm_rsqrt_ss(len);
        __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, estimate), estimate)));
        __m128 inv = _mm_andnot_ps(eq, refined);
        q = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), q);
    }
};
struct TerrainFlip
{
    char value;
    TerrainFlip()
    {}
    TerrainFlip(bool b) : value(b)
    {}
};

namespace fnv_00d06720 {
#include <intrin.h>

class hkMemoryAllocatorD
{
  public:
    virtual ~hkMemoryAllocatorD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD
{
    void* m_pvStack;
    void* m_pvStackStart;
    void* m_pvStackEnd;
    hkMemoryAllocatorD* m_pkTemp;
    hkMemoryAllocatorD* m_pkHeap;
    hkMemoryAllocatorD& heap() throw()
    {
        return *m_pkHeap;
    }
};
hkMemoryRouterD& __cdecl FUN_00c85750() throw();

struct hkArrayUtilD
{
    static void __cdecl FUN_00c908c0(hkMemoryAllocatorD& kAlloc, void* apvArray, int iNumElements,
                                     int iSizeElement) throw();
};

template <typename T> class hkArrayBaseD
{
  public:
    hkArrayBaseD() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    const T& operator[](int i) const throw()
    {
        return m_data[i];
    }
    int indexOf(const T& t, int iStart = 0, int iEnd = -1) const throw()
    {
        if (iEnd < 0)
            iEnd = m_iElementCount;
        for (int i = iStart; i < iEnd; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void GrowArrayCapacity(hkMemoryAllocatorD& kAlloc, int n) throw()
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCapCur = 2 * iCap;
            int iNewSize = (n < iCapCur) ? iCapCur : n;
            hkArrayUtilD::FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    void _setSize(hkMemoryAllocatorD& kAlloc, int n) throw()
    {
        GrowArrayCapacity(kAlloc, n);
        m_iElementCount = n;
    }
    void _clearAndDeallocate(hkMemoryAllocatorD& kAlloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct hkContainerHeapAllocatorD
{
    struct Allocator
    {
        hkMemoryAllocatorD* get(const void*) const throw()
        {
            return &FUN_00c85750().heap();
        }
    };
};

template <typename T> class hkArrayD : public hkArrayBaseD<T>
{
  public:
    typedef hkContainerHeapAllocatorD::Allocator AllocatorType;
    hkArrayD() throw()
    {}
    ~hkArrayD() throw()
    {
        releaseMemory();
    }
    void releaseMemory() throw()
    {
        this->_clearAndDeallocate(*AllocatorType().get(this));
    }
    void SetSizeAndGrow(int n) throw()
    {
        this->_setSize(*AllocatorType().get(this), n);
    }
};

class hkBaseObjectD
{
  public:
    virtual ~hkBaseObjectD() throw();
};
class hkReferencedObjectD : public hkBaseObjectD
{
  public:
    void* operator new(unsigned int uiBytes) throw()
    {
        hkReferencedObjectD* b = static_cast<hkReferencedObjectD*>(FUN_00c85750().heap().AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpEntityD : public hkReferencedObjectD
{
};
class hkpRigidBodyD : public hkpEntityD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual hkpRigidBodyD* clone() const throw();
};
class hkpPhantomD : public hkReferencedObjectD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual hkpPhantomD* clone() const throw();
};

class hkBoolD
{
  public:
    hkBoolD(bool b) throw()
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkpConstraintInstanceD : public hkReferencedObjectD
{
  public:
    hkpRigidBodyD* getRigidBody() const throw()
    {
        return m_pEntityA;
    }
    hkpRigidBodyD* getRigidBodyB() const throw()
    {
        return m_pEntityB;
    }
    hkBoolD FUN_00cf2fb0() const throw();
    hkpConstraintInstanceD* FUN_00cf3fa0(hkpRigidBodyD* pk, hkpRigidBodyD* pkB, int eMode) const throw();

    void* m_pOwnerObject;
    void* m_data;
    void* m_pConstraintModifier;
    hkpRigidBodyD* m_pEntityA;
    hkpRigidBodyD* m_pEntityB;
};

class hkpActionD : public hkReferencedObjectD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void GetEntities(hkArrayD<hkpEntityD*>& kEntitiesOut) throw();
    virtual void getPhantomArray(hkArrayD<hkpPhantomD*>& kPhantomsOut) throw();
    virtual void v18() throw();
    virtual hkpActionD* clone(const hkArrayD<hkpEntityD*>& kNewEntities,
                              const hkArrayD<hkpPhantomD*>& kNewPhantoms) const throw();
};

class FUN_00cb0c30
{
  public:
    FUN_00cb0c30& operator=(const FUN_00cb0c30& kOther) throw();
    const char* m_pcText;
};

class FUN_00d065e0 : public hkReferencedObjectD
{
  public:
    FUN_00d065e0() throw();
    FUN_00d065e0* FUN_00d06720() const throw();

    hkArrayD<hkpRigidBodyD*> m_ppRigidBodies;
    hkArrayD<hkpConstraintInstanceD*> m_ppConstraints;
    hkArrayD<hkpActionD*> m_ppActions;
    hkArrayD<hkpPhantomD*> m_kPhantoms;
    FUN_00cb0c30 m_name;
    unsigned long m_ulUserData;
    hkBoolD m_bSlotEnabled;
};

}  // namespace fnv_00d06720
