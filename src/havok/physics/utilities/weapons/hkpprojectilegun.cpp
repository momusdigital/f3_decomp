#include "f3_common.h"
// src/havok/physics/utilities/weapons/hkpprojectilegun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpprojectilegun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpProjectileGun.h"

struct FUN_00e44c70_cls
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    unsigned char flags;
    unsigned char pad1;
    unsigned char pad2;
    unsigned char pad3;
    unsigned char pad4;
    unsigned char pad5;
    unsigned char pad6;
    unsigned char pad7;
    unsigned char pad8;
    unsigned char pad9;
    unsigned char padA;
    unsigned char padB;
    unsigned char padC;
    void InitOnce();
};

// @fnv 0x00e44c70
void FUN_00e44c70_cls::InitOnce()
{
    if (!(reinterpret_cast<unsigned char*>(this)[0xc] & 1))
    {
        vC();
        reinterpret_cast<unsigned char*>(this)[0xc] |= 1;
    }
}

struct DDCC60World
{
    void removeReference();
};
struct hkpGunProjectile
{
    void FUN_00e44cc0();
    void ReleaseWorld();
};
// If the world pointer at offset 0x10 is set, calls FUN_00e44cc0 when its field at +8 is nonzero, then calls removeReference and clears the pointer.
// @fnv 0x00e44cf0
void hkpGunProjectile::ReleaseWorld()
{
    if (*(DDCC60World**)((char*)this + 0x10))
    {
        if (*(int*)((char*)*(void**)((char*)this + 0x10) + 8))
            FUN_00e44cc0();
        (*(DDCC60World**)((char*)this + 0x10))->removeReference();
        *(void**)((char*)this + 0x10) = 0;
    }
}

void __cdecl FUN_00e44ef0();

extern void __cdecl FUN_00e45040();

struct CallTarget_00e44eb0
{
    int FUN_00e44eb0();
};
struct SearchObject
{
    int GetCallResult(unsigned int arg0);
};
// Calls FUN_00e44eb0 on this object and returns its result as an int.
// @fnv 0x00e44f50
// pdb: ActorPackage::Revert | ActorPackage.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apLoadGameBuffer
int SearchObject::GetCallResult(unsigned int auiUnused)
{
    unsigned int callResult0 = (unsigned int)((CallTarget_00e44eb0*)this)->FUN_00e44eb0();
    return (int)callResult0;
}

struct V
{
    virtual void __fastcall f0(int);
    virtual void __fastcall f1(int);
    virtual void __fastcall f2(int);
    virtual void __fastcall f3(int);
    virtual void __fastcall f4(int);
};
struct C
{
    void __fastcall FUN_00e45090(int);
};
// @fnv 0x00e45090
void __fastcall C::FUN_00e45090(int x)
{
    V* base = reinterpret_cast<V*>(reinterpret_cast<char*>(this) - 8);
    base->f4(x);
}

struct hkBoolE44C
{
    char m_cBooleanValue;
    hkBoolE44C()
    {}
    hkBoolE44C(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkpEntityE44C;
struct hkpEntityListenerE44C;

struct hkpWorldE44C
{
    hkBoolE44C ProcessTarget(hkpEntityE44C* entity);
};

struct hkpEntityE44C
{
    int unk00;
    int unk04;
    hkpWorldE44C* m_pOwningWorld;
    void FUN_00c9c140(hkpEntityListenerE44C* listener);
};

struct hkBaseAE44C
{
    int unk00;
    int unk04;
};

struct hkpEntityListenerE44C
{
    int unk08;
};

struct hkObjE44C : public hkBaseAE44C, public hkpEntityListenerE44C
{
    unsigned char m_flags;
    char unk0D;
    char unk0E;
    char unk0F;
    hkpEntityE44C* m_pEntity;

    void FUN_00e44cc0();
};

// @fnv 0x00e44cc0
void hkObjE44C::FUN_00e44cc0()
{
    if (m_pEntity)
    {
        m_pEntity->m_pOwningWorld->ProcessTarget(m_pEntity);
        if (m_flags & 4)
            m_pEntity->FUN_00c9c140(this);
    }
}

struct hkFlagsE44E
{
    unsigned char m_kStorage;

    void clear(unsigned char mask)
    {
        m_kStorage &= ~mask;
    }
};

template <class T> struct hkArrayE44E
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
};

void __cdecl ReleaseWorld();

// @fnv 0x00e44ea0
void __cdecl FUN_00e44ea0()
{
    ReleaseWorld();
}

extern float DAT_01017870;

class hkRangeE44F
{
  public:
    float m_24;
    float m_28;

    hkRangeE44F() throw() : m_24(DAT_01017870), m_28(0.0f)
    {}
};

template <class T> class hkArrayE44F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct FnvCpu_FUN_00e450c0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00e450c0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00e450c0_CpuAllocator* allocator;
};
FnvCpu_FUN_00e450c0_CpuAllocatorHolder* __cdecl FUN_00c85750();

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
    float _mm_cvtss_f32(__m128);
}

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline __m128 dot3(const hkVector4q& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }

    __forceinline hkReal length3() const
    {
        hkReal len;
        _mm_store_ss(&len, _mm_sqrt_ss(dot3(*this)));
        return len;
    }

    __forceinline void normalize3()
    {
        __m128 len2 = dot3(*this);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }

    __forceinline void setCross(const hkVector4q& v0, const hkVector4q& v1)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9)));
    }
};

struct hkRotationq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline void operator=(const hkRotationq& r)
    {
        m_kColumn0 = r.m_kColumn0;
        m_kColumn1 = r.m_kColumn1;
        m_kColumn2 = r.m_kColumn2;
    }

    void SetAxisAngle(const hkVector4q& axis, hkReal angle);
    void SetProduct(const hkRotationq& a, const hkRotationq& b);
};

struct hkTransformq
{
    hkRotationq m_rotation;
    hkVector4q m_vTranslation;
};

class hkpRigidBodyq
{
  public:
    __forceinline const hkTransformq& getTransform() const
    {
        return *reinterpret_cast<const hkTransformq*>(reinterpret_cast<const char*>(this) + 0xf0);
    }

    __forceinline const hkVector4q& getLinearVelocity() const
    {
        return *reinterpret_cast<const hkVector4q*>(reinterpret_cast<const char*>(this) + 0x1b0);
    }

    void SetGeometryTransform(const hkTransformq& transform);
};

class hkRefObjE44
{
  public:
    hkRefObjE44()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjE44();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c90510() const throw();
};

class hkpContactListenerE44
{
  public:
    virtual void HandleContactPointEvent(void* event)
    {}
    virtual void collisionAddedCallback(void* event)
    {}
    virtual void collisionRemovedCallback(void* event)
    {}
    virtual ~hkpContactListenerE44()
    {}
};

template <class BITS, class STORAGE> class hkFlagsE44
{
  public:
    hkFlagsE44(STORAGE s)
    {
        m_kStorage = s;
    }
    STORAGE m_kStorage;
};

enum ProjectileFlagsE44
{
    PROJECTILE_FLAG_NONE
};

namespace fnv_00e44f60 {
template <int SIZE> __forceinline void memCpyOneAlignedE44F(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterE44F
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterE44F {
extern "C" hkMemoryRouterE44F& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayE44F
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
        hkMemoryRouterE44F& router = hkRouterE44F::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedE44F<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

}  // namespace fnv_00e44f60

class hkMemoryAllocatorE450
{
  public:
    virtual ~hkMemoryAllocatorE450() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
    virtual void* AllocateBufferWithSize(int& n) throw();
    virtual void ReturnMemory(void* p, int n) throw();
};

struct hkMemoryRouterE450
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE450* m_pStreamAllocator;
    hkMemoryAllocatorE450& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE450 {
extern "C" hkMemoryRouterE450& __cdecl FUN_00c85750() throw();
}

template <class T> struct hkArrayE450
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayE450() throw()
    {
        hkMemoryAllocatorE450& alloc = hkRouterE450::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00e466e0
{
  public:
    virtual ~FUN_00e466e0() throw();
    int unk04[10];
};

class FUN_00e45040 : public FUN_00e466e0
{
  public:
    hkArrayE450<void*> m_items;

    void FUN_00e44eb0() throw();
    virtual ~FUN_00e45040() throw();
};

// @fnv 0x00e45040
FUN_00e45040::~FUN_00e45040() throw()
{
    FUN_00e44eb0();
}

struct hkFinishLoadedObjectFlagE46F
{
    int m_bFinishing;
};

class hkMemoryAllocatorE46F
{
  public:
    virtual ~hkMemoryAllocatorE46F() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
};

struct hkMemoryRouterE46F
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE46F* m_pStreamAllocator;
    hkMemoryAllocatorE46F& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE46F {
extern "C" hkMemoryRouterE46F& __cdecl FUN_00c85750() throw();
}

class FUN_00e46e80
{
  public:
    FUN_00e46e80() throw();
    void FUN_00e45460(void* world) throw();

    static void* operator new(unsigned int n)
    {
        return hkRouterE46F::FUN_00c85750().heap().AllocateMemoryBlock(n);
    }
    static void operator delete(void* p);

    int unk00[5];
};

class FUN_00e466a0
{
  public:
    FUN_00e466a0(hkFinishLoadedObjectFlagE46F flag) throw();
    virtual ~FUN_00e466a0() throw();
    int unk04;
    char unk08;
};

namespace fnv_00e45010 {
namespace FUN_00e466a0 {
class hkpFirstPersonGun
{
  public:
    hkpFirstPersonGun(void* pkWorld);
    virtual ~hkpFirstPersonGun();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
};
}

template <class T> class hkArrayE450
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE450() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

namespace FUN_00e45010 {
class hkpProjectileGun : public FUN_00e466a0::hkpFirstPersonGun
{
  public:
    hkpProjectileGun(void* pkWorld);
    virtual ~hkpProjectileGun();

    hkArrayE450<void*> m_kProjectiles;
};

}
}  // namespace fnv_00e45010

// sub ecx,8; jmp target  ==  MSVC adjustor thunk
struct PrimaryBase
{
    virtual void FUN_00e450a0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00e450a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e450a0
    virtual void FUN_00e450a0();
};

Derived::Derived()
{}

struct ProjQ
{
    void InitOnce();
};
struct FUN_00e44eb0_cls
{
    char m_auiShapeKeys[0x2c];
    void* m_pProjectiles;
    int m_iProjectileCount;
    void FUN_00e44eb0();
};

// Calls InitOnce and removeReference on each projectile in m_pProjectiles, then resets m_iProjectileCount to 0.
// @fnv 0x00e44eb0
void FUN_00e44eb0_cls::FUN_00e44eb0()
{
    int count = m_iProjectileCount;
    for (int i = 0; i < count; ++i)
    {
        ProjQ* p = (ProjQ*)((char**)m_pProjectiles)[i];
        p->InitOnce();
        ((DDCC60World*)p)->removeReference();
    }
    m_iProjectileCount = 0;
}

struct ProjectileRelease
{
    int m_00;
    int m_04;
    int m_08;
    unsigned char m_flags;
    void FUN_00c905b0();
    __forceinline bool destroyed() const
    {
        return (m_flags & 1) != 0;
    }
};
