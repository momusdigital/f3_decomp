#include "f3_common.h"
// src/havok/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpDefaultToiResourceMgr.h"

struct MemoryManager
{
    virtual void* Function0() = 0;
    virtual void* Function1() = 0;
    virtual void* Function2() = 0;
    virtual void* Function3() = 0;
    virtual void* Function4(int, int) = 0;
};

struct MemoryRouter
{
    unsigned char pad_00[0x18];
    MemoryManager* pMemoryManager;
};

MemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

namespace fnv_00d9fc70 {
struct FUN_00d9fc70_MemoryManager;

typedef void(__thiscall* FUN_00d9fc70_Callback)(FUN_00d9fc70_MemoryManager*, void*, unsigned short);

struct FUN_00d9fc70_MemoryManager
{
    FUN_00d9fc70_Callback* vtable;
};

struct FUN_00d9fc70_Router
{
    void* vtable;
    unsigned char padding[12];
    FUN_00d9fc70_MemoryManager* memoryManager;
};

FUN_00d9fc70_Router* _D1A0E0GetMemoryRouter();

}  // namespace fnv_00d9fc70

// @fnv 0x00d9fb70
// pdb: hkpSimpleShapePhantom::getType | hkpSimpleShapePhantom.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00d9fb70()
{
    return 1;
}

// FUN_00d9fc60
// Returns the address of the global registration object that lives at
// DAT_0126955c.  The startup code fills that object (13 dwords) through a
// constructor call, and this getter hands out its address.
extern int DAT_0126955c;

// @fnv 0x00d9fc60
// pdb: getVtablehkpSerializedDisplayMarker | hkpSerializedDisplayMarkerClass.obj | fnv360_0721_beta, objrun_open, low
int* __cdecl FUN_00d9fc60()
{
    return &DAT_0126955c;
}

class hkMemoryAllocatorD9FB
{
  public:
    virtual ~hkMemoryAllocatorD9FB() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
};

struct hkMemoryRouterD9FB
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    hkMemoryAllocatorD9FB* m_pSolver;

    hkMemoryAllocatorD9FB& solver()
    {
        return *m_pSolver;
    }
};

struct hkBoolD9FB
{
    char m_cBooleanValue;
    hkBoolD9FB()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

enum hkResultD9FB
{
    HK_SUCCESS_D9FB = 0,
    HK_FAILURE_D9FB = 1
};

template <class T> struct hkArrayD9FB
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
