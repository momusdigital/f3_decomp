#include "f3_common.h"
// src/havok/physics/dynamics/action/hkpbinaryaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/action/hkpbinaryaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBinaryAction.h"

struct FUN_00c97510
{
    void ProcessPointer(void*);
};

struct FUN_00cf4cc0_class
{
    void FUN_00cf4cc0(void* arg);
};

// @fnv 0x00cf4cc0
void FUN_00cf4cc0_class::FUN_00cf4cc0(void* arg)
{
    void* p = *(void**)((char*)this + 8);
    if (p)
        ((FUN_00c97510*)p)->ProcessPointer(this);
}

struct RefObj
{
    void RetainReference(void);
};

namespace fnv_00d4f850 {
struct RefObj
{
    void RetainReference(void);
};

}  // namespace fnv_00d4f850

struct NameStr
{
    NameStr() throw();
    char* p;
};
struct Ref
{
    virtual ~Ref();
    unsigned short flags;
    short refs;
    Ref() : refs(1)
    {}
};
struct Act : Ref
{
    void* world;
    void* island;
    unsigned long userData;
    NameStr name;
    Act(unsigned long u) : world(0), island(0), userData(u)
    {}
};

template <int SIZE> __forceinline void memCpyOneAlignedXcf4e30(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXcf4e30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXcf4e30 {
extern "C" hkMemoryRouterXcf4e30& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXcf4e30
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
        hkMemoryRouterXcf4e30& router = hkRouterXcf4e30::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXcf4e30<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};
