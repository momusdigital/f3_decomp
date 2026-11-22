#include "f3_common.h"
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

struct FUN_00e49100_t
{
    int GetNextKey(int key);
};

// @fnv 0x00e49100
// pdb: hkpConvexPieceMeshShape::getNextKey | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: oldKey
int FUN_00e49100_t::GetNextKey(int key)
{
    void* shape = *(void**)((char*)this + 8);
    int iMaxKey = *(int*)((char*)shape + 0x24) + *(int*)((char*)shape + 0x18);
    int iNextKey = key + 1;
    if (iNextKey >= iMaxKey)
        iNextKey = -1;
    return iNextKey;
}

struct FUN_00e49290_Target
{
    // Virtual stub that returns 0 for the given int argument.
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

struct FUN_00e49290_Owner
{
    unsigned char pad[0x10];
    FUN_00e49290_Target target;
};

struct FUN_00e49290_Data
{
    unsigned char pad0[8];
    int* p8;
    unsigned char pad1[8];
    int* p14;
    unsigned int count;
    unsigned char pad2[4];
    int* p20;
};

struct FUN_00e49290_Class
{
    unsigned char pad[8];
    FUN_00e49290_Data* data;
    FUN_00e49290_Owner* owner;

    int hkpConvexPieceMeshShape_getCollisionFilterInfo(unsigned int index);
};

// pdb: hkpConvexPieceMeshShape::getCollisionFilterInfo | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, objrun + bridge(hash|vtable), high
int FUN_00e49290_Class::hkpConvexPieceMeshShape_getCollisionFilterInfo(unsigned int index)
{
    int result;

    if (index < this->data->count)
    {
        int i = this->data->p14[index];
        result = this->data->p8[i + 1];
    }
    else
    {
        result = this->data->p20[index - this->data->count];
    }

    return this->owner->target.FUN_00e49290_f4(result);
}

// @fnv 0x00e49030
// pdb: hkpConvexPieceShape::getFirstKey | hkpConvexPieceShape.obj | fnv360_0822_retail, objrun_open, low
int FUN_00e49030()
{
    return 0;
}

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

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual declared by both bases.
struct PrimaryBase
{
    virtual void FUN_00e01040();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00e01040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e01040
    virtual void FUN_00e01040();
};

Derived::Derived()
{}
