#include <new>
// src/f3staging/f3iso_00a77940_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a77940 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a77940 (community match, verified in this file)
struct hkBoolRet
{
    char b;
    hkBoolRet(bool val) : b(val)
    {}
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
namespace na77840 {
struct ThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};
inline ThreadMemory* GetThreadMemory() { return (ThreadMemory*)TlsGetValue(DAT_010f3170); }
}
struct InterfaceHeap { void FUN_0086ba60(void*); };
extern InterfaceHeap DAT_01090a78;
struct FilterRefE4
{
    FilterRefE4() throw() : references(1) {}
    virtual ~FilterRefE4() throw()
    {}
    unsigned short sizeFlags;
    short references;
    void RemoveReference() throw();
};
struct CollectionFilterE4
{
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }

    virtual ~CollectionFilterE4() throw()
    {}
    virtual hkBoolRet TestCollection(void* a, void* b) = 0;
};
struct RayCollectionFilterE4 {
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }

    virtual hkBoolRet IsRayCollectionEnabled(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6) = 0;
    virtual hkBoolRet FilterRayCollection1(void* a0, void* a1, void* a2, void* a3, void* a4) = 0;
    virtual unsigned int FilterRayCollection2(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6) = 0;
    virtual ~RayCollectionFilterE4() throw() {}
};
struct RayCollidableFilterE4 {
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }

    virtual hkBoolRet FilterRayCollidable(void* a0, void* a1, void* a2, void* a3) = 0;
    virtual ~RayCollidableFilterE4() throw() {}
};
struct BorderFilterE4
{
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }

    virtual ~BorderFilterE4() throw()
    {}
    virtual hkBoolRet TestBorder(void* a, void* b) = 0;
};
struct CollisionFilterE4 : FilterRefE4, CollectionFilterE4, RayCollectionFilterE4, RayCollidableFilterE4, BorderFilterE4
{
    virtual unsigned int FilterRayCollection2(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6);
    CollisionFilterE4() throw();
    
    static void operator delete(void* p) {
        na77840::GetThreadMemory()->FUN_008f6d90(p, static_cast<CollisionFilterE4*>(p)->sizeFlags, 0x27);
    }
    int unk18, unk1c;
    unsigned int type;
    int unk24, unk28, unk2c;
};


struct FilterArrayE4
{
    CollisionFilterE4** data;
    int size;
    int capacityAndFlags;
    FilterArrayE4() throw() : data(0), size(0), capacityAndFlags(0x80000000) {}
    static __forceinline void CopyItems(CollisionFilterE4** dst, CollisionFilterE4* const* src, int n) {
        for(int i=0;i<n;++i) dst[i]=src[i];
    }
    ~FilterArrayE4() throw()
    {
        if ((capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = capacityAndFlags & 0x3fffffff;
            na77840::GetThreadMemory()->FUN_008f6d90(data, capacity * 4, 0x17);
        }
    }
};

struct FUN_00a77940 : CollisionFilterE4
{
    virtual hkBoolRet IsRayCollectionEnabled(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6);
    virtual hkBoolRet FilterRayCollection1(void* a0, void* a1, void* a2, void* a3, void* a4);
    virtual hkBoolRet FilterRayCollidable(void* a0, void* a1, void* a2, void* a3);
    virtual hkBoolRet TestCollection(void* a, void* b);
    virtual hkBoolRet TestBorder(void* a, void* b);
    FUN_00a77940(const FilterArrayE4& source) throw();
    FUN_00a77940() throw();
    FilterArrayE4 filters;
    static __forceinline void operator delete(void* memory) {
        na77840::GetThreadMemory()->FUN_008f6d90(memory, static_cast<FUN_00a77940*>(memory)->sizeFlags, 0x27);
    }
    virtual ~FUN_00a77940() throw();
};
// pdb: hkpCollisionFilterList::~hkpCollisionFilterList | hkpCollisionFilterList.obj | fnv360_0822_retail, call_seq, high
FUN_00a77940::~FUN_00a77940() throw()
{
    for (int i = 0; i < filters.size; ++i)
    {
        CollisionFilterE4* f = filters.data[i];
        if (f->sizeFlags != 0)
        {
            if (--f->references == 0)
                delete f;
        }
    }
}
