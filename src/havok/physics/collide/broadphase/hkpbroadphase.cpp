// src/havok/physics/collide/broadphase/hkpbroadphase.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/hkpbroadphase.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char DAT_010d3f7c[];

struct SpawnedObject
{
    unsigned int m_i00;
    unsigned short m_w04;
    void Init();
};

struct InitObject
{
    void* m_pGlobal;
    unsigned short unk04;
    unsigned short m_w06;
    SpawnedObject m_sub;
    unsigned int m_i10;
    InitObject* FUN_00d97010();
};

// @fnv 0x00d97010
InitObject* InitObject::FUN_00d97010()
{
    m_w06 = 1;
    m_pGlobal = DAT_010d3f7c;
    SpawnedObject* pSubObject = &m_sub;
    pSubObject->m_i00 = 0xfffffff1u;
    pSubObject->m_w04 = 0x8000;
    m_i10 = 0;
    pSubObject->Init();
    return this;
}

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* apSection);

// FUN_00d97070: thiscall, one stack parameter, /MT /O2 /GS /EHsc /Gy

class Spawned
{
  public:
    virtual void v00();
    Spawned* Init(void* a1);
};

class Obj
{
  public:
    virtual void v00();
    virtual Spawned* v04(unsigned int size);
};

struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Obj* m_10;
};

Holder* FUN_00c85750();

namespace fnv_00d97100 {
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d97100

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* apSection);

struct FUN_00d97050_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pSection;

    void FUN_00d97050();
};

// @fnv 0x00d97050
void FUN_00d97050_cls::FUN_00d97050()
{
    EnterCriticalSection(m_pSection);
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* apSection);

struct FUN_00d970c0_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pCs;

    void FUN_00d970c0(void*, void*);
};

// Deletes the critical section m_pCs, frees it via the holder's allocator, clears m_pCs, and sets the vtable pointer to DAT_0102e388.
// @f3 0x0066afb0 (community match, verified in this file)
struct Obj66AFB0_fit
{
    float FUN_00becf40(int aiKey);
};

// pdb: RaceSexMenu::MenuOption::GetRange | RaceSexMenu.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiLow, aiHigh
void FUN_00d970c0_cls::FUN_00d970c0(void* apArg1, void* apArg2)
{
    if (m_vptr)
    {
        *(int*)apArg1 = (int)((Obj66AFB0_fit*)m_vptr)->FUN_00becf40(0x1006);
        *(int*)apArg2 = (int)((Obj66AFB0_fit*)m_vptr)->FUN_00becf40(0x1007);
    }
}

