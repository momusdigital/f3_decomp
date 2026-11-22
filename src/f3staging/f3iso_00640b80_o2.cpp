#include <new>
// src/f3staging/f3iso_00640b80_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00640b80 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00640b80 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);

class RecursiveSpinLock
{
public:
    void FUN_00409a80(int spin);
    void Unlock()
    {
        if (--m_lCount == 0)
        {
            long owner = m_lOwner;
            InterlockedCompareExchange(&m_lOwner, 0, owner);
        }
    }
    volatile long m_lOwner;
    long m_lCount;
};

void FUN_00422ab0();

extern char DAT_00e05280[];

struct Tile
{
    float FUN_00becf40(int trait);
    void FUN_00bee190(int trait, float value, int update);
    void FUN_00bf11a0(int trait, char* text, int update);
};

struct Node
{
    Node* next;
    Node* prev;
    Tile* tile;
};

struct Iterator
{
    Node* node;
    Iterator(Node* p) : node(p) {}
    Tile*& operator*() { return node->tile; }
    Tile*& Next() { Tile*& value = node->tile; node = node->next; return value; }
};

struct MenuOwner
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114;
    void* unk118;
    int unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138;
    int unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158;
    int unk15c, unk160, unk164;
    Node* m_pkHead;
    Node* m_pkTail;
    unsigned int m_uiCount;
    Tile* Menu_RenderTemplate(void* parent, char* name, int flags);
    void FUN_00640b80(unsigned int count, char** texts);
};

typedef PoolAllocatorBase<unsigned int> Pool;

static __forceinline Node* NewNode()
{
    Pool::ms_kPoolState.FUN_00409a80(0);
    Pool::LinkedListEntry* entry;
    if (Pool::ms_pFreeList)
        entry = Pool::ms_pFreeList;
    else
    {
        FUN_00422ab0();
        entry = Pool::ms_pFreeList;
    }
    Pool::ms_pFreeList = entry->m_pkNext;
    entry->m_element = 0;
    entry->m_pkNext = 0;
    entry->m_pUserData = 0;
    Pool::ms_kPoolState.Unlock();
    return (Node*)entry;
}

static __forceinline void AddTail(MenuOwner* list, Tile* tile)
{
    Node* item = NewNode();
    item->tile = tile;
    item->next = 0;
    item->prev = list->m_pkTail;
    if (list->m_pkTail) list->m_pkTail->next = item;
    else list->m_pkHead = item;
    list->m_uiCount++;
    list->m_pkTail = item;
}

// pdb: HackingMenu::ScrollLog | HackingMenu.obj | fnv360_0822_retail, ustr, medium
// pdb params: aiTicks, pNewEntries
void MenuOwner::FUN_00640b80(unsigned int count, char** texts)
{
    Iterator it(this->m_pkHead);
    if (it.node)
    {
        float acc = (float)count;
        do
        {
            Tile* tile = it.Next();
            tile->FUN_00bee190(0xfac, acc + tile->FUN_00becf40(0xfac), 1);
        } while (it.node);
    }

    for (unsigned int i = 0; i < count; i++)
    {
        Tile* tile = Menu_RenderTemplate(this->unk118, DAT_00e05280, 0);
        tile->FUN_00bee190(0xfac, (float)(count - i - 1), 1);
        tile->FUN_00bf11a0(0xfc4, texts[i], 1);
        AddTail(this, tile);
    }
}
