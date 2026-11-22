// bscore/memorymanager.cpp: MemoryManager, TESQuest, TESActorBaseData, Actor and more (1 function)
#include "f3_common.h"
#include "memorymanager_identity.h"
#include "memorymanager_memory.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct FUN_00473960_shell : public TESFile
{
    void FUN_00473960(void*);
};

void __cdecl Deallocate(void*);

// If the pointer at offset 0x420 is non-null, deallocates it and clears the pointer and the count at offset 0x424.
// @f3 0x00989ef0 (community match, verified in this file)
struct FUN_00473960_elem
{
    virtual void vf00(int flags);
    unsigned short unk04;
    short unk06;
};

// pdb: hkpPhysicsSystem::removeAction | hkpPhysicsSystem.obj | fnv360_0822_retail, callee_sim, low, conflict (skyrim: tryMoveEntity)
// pdb params: i
void FUN_00473960_shell::FUN_00473960(void* aArg)
{
    unsigned int index = (unsigned int)aArg;
    FUN_00473960_elem** items = *(FUN_00473960_elem***)((char*)this + 0x14);
    FUN_00473960_elem* elem = items[index];
    if (elem->unk04 != 0)
    {
        elem->unk06--;
        if (elem->unk06 == 0)
            elem->vf00(1);
    }
    unsigned int count = --*(unsigned int*)((char*)this + 0x18);
    items = *(FUN_00473960_elem***)((char*)this + 0x14);
    items[index] = items[count];
}


struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];

extern __declspec(thread) int g_tlsMemContext;
struct MemCtxGuard
{
    int iOld;
    static int GetCtx()
    {
        return g_tlsMemContext;
    }
    static void SetCtx(int c)
    {
        g_tlsMemContext = c;
    }
    MemCtxGuard(int c)
    {
        iOld = GetCtx();
        SetCtx(c);
    }
    ~MemCtxGuard()
    {
        SetCtx(iOld);
    }
};
struct MemoryPoolView : public MemoryPool
{
    bool HasMemory()
    {
        return *(void**)((char*)this + 4) != 0;
    }
};

struct FUN_00aa3a10_tls_struct
{
    unsigned char pad[0x2b4];
    unsigned int flag;
};

__declspec(thread) FUN_00aa3a10_tls_struct g_fun_tls;

struct _RTL_CRITICAL_SECTION;
__declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern _RTL_CRITICAL_SECTION DAT_011f6234;

struct _RTL_CRITICAL_SECTION;
__declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
extern _RTL_CRITICAL_SECTION DAT_011f6234;

extern char DAT_011f6230;

namespace fnv_00aa4490 {
extern unsigned int DAT_011f6234;

}  // namespace fnv_00aa4490

extern char DAT_011f6230;

struct FUN_00aa46a0_holder
{
    char pad0[2];
    unsigned short countA;
    unsigned short countB;
    char pad1[2];
    void** tableA;
    char pad2[0x118];
    void** tableB;
    void* GetEntryAt(unsigned int index);
};

struct FUN_00aa39c0_tls
{
    unsigned char unk0000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00aa39c0_tls g_tls;

inline int S_Sum(int a, int b)
{
    return a + b;
}

__forceinline void operator delete[](void* p)
{
    g_memoryManager.Deallocate(p);
}
struct ScrapView
{
    ~ScrapView();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct WeightedMapNode
{
    WeightedMapNode* unk00;
};
struct MapView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(WeightedMapNode*);
    virtual void slot5();
    virtual void slot6(WeightedMapNode*);
    unsigned int unk04;
    WeightedMapNode** unk08;
    void* unk0C;
    ~MapView();
    __forceinline WeightedMapNode* First()
    {
        for (unsigned int i = 0; i < unk04; ++i)
        {
            if (unk08[i])
                return unk08[i];
        }
        return 0;
    }
    void FUN_00a0c850(WeightedMapNode*&, unsigned long&, ScrapView*&);
    inline void ClearAll()
    {
        for (unsigned int bucket = 0; bucket < unk04; ++bucket)
        {
            while (unk08[bucket])
            {
                WeightedMapNode* node = unk08[bucket];
                unk08[bucket] = unk08[bucket]->unk00;
                slot4(node);
                slot6(node);
            }
        }
        unk0C = 0;
    }
};
inline void FreeArray(void* p)
{
    g_memoryManager.Deallocate(p);
}
struct FUN_00aa5950_s
{
    ~FUN_00aa5950_s();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct PoolView
{
    ~PoolView();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

namespace fnv_00aa43a0 {

class FUN_00aa46a0_holder
{
  public:
    short unk00;
    unsigned short m_count2;
    unsigned short m_count4;

    int GetCount()
    {
        return m_count2 + m_count4;
    }
    void* GetEntryAt(unsigned int index);
    void FUN_00aa43a0(int unused);
};

}  // namespace fnv_00aa43a0
