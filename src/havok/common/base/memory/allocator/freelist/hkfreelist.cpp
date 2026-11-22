#include "f3_common.h"
// src/havok/common/base/memory/allocator/freelist/hkfreelist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hkfreelist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkFreeListNode
{
    hkFreeListNode* next;
    int a;
    int b;
    int size;
};

struct PointerChainNode
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    void* m_pSecondNode;
    void* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    void AttachPointer(void*);
    void FUN_00dd7360();
};

namespace fnv_00dd7510 {
struct PointerChainNode
{
    void FUN_00dd7200();
    void FUN_00dd74b0(int, int, int, int);
    void FUN_00dd7510(int a, int b, int c, int d);
};

}  // namespace fnv_00dd7510

struct hkFreeListAllocator
{
    virtual void unused1()
    {}
    virtual void unused2()
    {}
    virtual void freeBlock(hkFreeListNode* node)
    {
        (void)node;
    }
};

struct FUN_00dd7200_hkFreeList : PointerChainNode
{
    void FUN_00dd7200();
};

// @f3 0x00ba1250 (community match, verified in this file)
struct FreeReceiver {
    void FUN_0086ba60(void* memory);
};
extern FreeReceiver DAT_01090a78;
// pdb: CSpeedTreeRT::STextures::~STextures | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, medium
void FUN_00dd7200_hkFreeList::FUN_00dd7200() {
    DAT_01090a78.FUN_0086ba60(m_next);
    m_next = 0;
    DAT_01090a78.FUN_0086ba60(m_pFreeBlocks);
    m_pFreeBlocks = 0;
    m_data = 0;
    m_field5 = 0;
    m_field6 = 0;
}


struct hkFreeListStandIn
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    void* m_pSecondNode;
    void* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    unsigned int m_field8;
    unsigned int m_field9;

    unsigned int FUN_00dd7240();
};

namespace fnv_00dd73f0 {
struct hkFreeListStandIn
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    hkFreeListNode* m_pSecondNode;
    hkFreeListNode* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    void* m_field8;
    void* m_field9;
    int m_field10;
    int m_field11;

    void ResetFreeList();
};

}  // namespace fnv_00dd73f0

struct HavokBool
{
    unsigned char value;
    HavokBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};

// Walks the linked list from pNode and sums the counter's count for each node, returning the total.
// @f3 0x0050a800 (community match, verified in this file)
namespace f3m_0050a800 {
void __cdecl FUN_00454890(unsigned int tag, int value);

struct hkItem50a800 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkListNode50a800 {
    hkItem50a800* item;
    hkListNode50a800* next;
};

struct Shader447 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkListNode50a800 list18;

    void FUN_00b874f0();
    bool InitPasses();
    bool FUN_0050a800();
};

// pdb: BGSListForm::Save | BGSListForm.obj | fnv360_0822_retail, vtable, medium
bool Shader447::FUN_0050a800()
{
    FUN_00b874f0();
    hkListNode50a800* node = &list18;
    while (node) {
        if (node->next == 0 && node->item == 0)
            break;
        FUN_00454890(0x4d414e4c, node->item->unk0C);
        node = node->next;
    }
    return InitPasses();
}
}   // namespace f3m_0050a800


class hkBoolDD72
{
  public:
    hkBoolDD72(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    hkBoolDD72(const hkBoolDD72& o)
    {
        m_cBooleanValue = o.m_cBooleanValue;
    }
    char m_cBooleanValue;
};

typedef void(__cdecl* hkMemoryWalkCallbackDD72)(void* start, int size, hkBoolDD72 allocated, int pool, void* param);

bool __cdecl CompareLessThan(const hkFreeListNode* pkA, const hkFreeListNode* pkB);
void __cdecl FUN_00dd7d00(hkFreeListNode** ppArray, int iLow, int iHigh,
                          bool(__cdecl* pfnLess)(const hkFreeListNode*, const hkFreeListNode*));

struct hkBoolDD7C
{
    char m_cBooleanValue;
    hkBoolDD7C(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

typedef void(__cdecl* hkMemoryWalkCallback)(void* start, unsigned int size, hkBool allocated, int pool, void* param);

bool __cdecl CompareLessThan(void* a, void* b);
void __cdecl FUN_00dd7d00(void** arr, int lo, int hi, bool(__cdecl* cmpLess)(void*, void*));

namespace fnv_00dd74b0 {

}  // namespace fnv_00dd74b0
