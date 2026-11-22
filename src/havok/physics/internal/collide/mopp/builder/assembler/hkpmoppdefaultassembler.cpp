#include "f3_common.h"
// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl hkpMoppCodeGenerator_resize();

// hkpMoppCodeGenerator: the code buffer is filled from its end backwards (New Vegas Xbox 360 PDB names).
struct FUN_00e06780_class
{
    int unk00, unk04;
    int m_size;           // +0x08
    int m_pos;            // +0x0C
    char* m_code;         // +0x10
    void __thiscall AppendChar(char b);
};

// Writes character b at the current write position, advances the offset, and calls hkpMoppCodeGenerator_resize when the offset reaches the capacity.
// @fnv 0x00e06780
// pdb: hkpMoppCodeGenerator::addCode | hkpMoppDefaultAssembler.obj | tesv_win, call_dedup, low
void __thiscall FUN_00e06780_class::AppendChar(char acValue)
{
        char* p = m_code - m_pos;
    int base = m_size;
    *(p + base - 1) = acValue;
    ++m_pos;
    if (m_pos >= m_size)
        hkpMoppCodeGenerator_resize();
}

struct S_00e066f0_Src
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_pRayStart;
    int m_kRayEnd;
    int m_uiItemCount;
    int m_offsets[8];
};

struct S_00e066f0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_iElementCount;
    int m_uiItemCount;
    int m_entries[8];

    void CopyOffsets(const S_00e066f0_Src* src);
};

// @fnv 0x00e066f0
// pdb: hkpMoppAssemblerNodeInfo::updateOffsetAndSpread | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, low
// pdb params: node
void S_00e066f0::CopyOffsets(const S_00e066f0_Src* src)
{
    m_iElementCount = src->m_kRayEnd - src->m_pRayStart;
    m_uiItemCount = src->m_uiItemCount;
    for (int i = 0; i < src->m_uiItemCount; i++)
    {
        m_entries[i] = src->m_offsets[i];
        m_entries[i + 1] = src->m_offsets[i + 1] - src->m_offsets[i];
    }
}

struct AlignRange
{
    volatile int m_iMinControlPoint;
    volatile int m_iMaxControlPoint;
};

struct FUN_00e06730_cls
{
    int unk00;
    int unk04;
    int unk08;
    AlignRange m_akRange[3];
    volatile int m_iShift;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    volatile int m_aiAlignedMin[3];
    volatile int m_aiAlignedMax[3];
    void AlignRanges();
};

// @fnv 0x00e06730
// pdb: hkpMoppAssemblerCutInfo::calcPossibleCutPlanes | hkpMoppDefaultAssembler.obj | tesv_win, call_gap, low
void FUN_00e06730_cls::AlignRanges()
{
    int iShift0 = m_iShift;
    int iMax0 = ((m_akRange[0].m_iMaxControlPoint >> iShift0) + 1) << iShift0;
    int iMin0 = (m_akRange[0].m_iMinControlPoint >> iShift0) << iShift0;
    m_aiAlignedMax[0] = iMax0;
    m_aiAlignedMin[0] = iMin0;

    int iShift1 = m_iShift;
    int iMax1 = ((m_akRange[1].m_iMaxControlPoint >> iShift1) + 1) << iShift1;
    int iMin1 = (m_akRange[1].m_iMinControlPoint >> iShift1) << iShift1;
    m_aiAlignedMin[1] = iMin1;
    m_aiAlignedMax[1] = iMax1;

    int iShift2 = m_iShift;
    int iMax2 = ((m_akRange[2].m_iMaxControlPoint >> iShift2) + 1) << iShift2;
    int iMin2 = (m_akRange[2].m_iMinControlPoint >> iShift2) << iShift2;
    m_aiAlignedMin[2] = iMin2;
    m_aiAlignedMax[2] = iMax2;
}

struct ByteSink
{
    int unk00;
    int unk04;
    int m_uiLogicalSize;
    int m_iUsed;
    char* m_pBuffer;

    void hkpMoppCodeGenerator_resize();

    void PutByte(char acValue)
    {
        m_pBuffer[m_uiLogicalSize - m_iUsed - 1] = acValue;
        m_iUsed++;
        if (m_iUsed >= m_uiLogicalSize)
            hkpMoppCodeGenerator_resize();
    }

    void hkpMoppCodeGenerator_addCommand8(char acFirst, char acSecond);
};

// Writes acSecond then acFirst to the sink via PutByte, in that order.
// @fnv 0x00e067b0
// pdb: hkpMoppCodeGenerator::addCommand8 | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap, high
// pdb params: code, param
// pdb: hkpMoppCodeGenerator::addCommand8 | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap, high (was: PutBytePair)
void ByteSink::hkpMoppCodeGenerator_addCommand8(char acFirst, char acSecond)
{
    PutByte(acSecond);
    PutByte(acFirst);
}

typedef void(__thiscall* FlushFunction)(void*);
struct BufferWriter
{
    int unknown00;
    int unknown04;
    int capacity;
    int position;
    unsigned char* data;
    void WriteInt24(int value);
};
// Writes the low three bytes of value into the buffer from the end, advancing position and flushing when it reaches capacity.
// @fnv 0x00e06920
// pdb: hkpMoppCodeGenerator::addParam24 | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_seq, medium
// pdb params: param
void BufferWriter::WriteInt24(int value)
{
    data[capacity - position - 1] = (unsigned char)value;
    ++position;
    if (position >= capacity)
        ((FlushFunction)hkpMoppCodeGenerator_resize)(this);
    data[capacity - position - 1] = (unsigned char)(value >> 8);
    ++position;
    if (position >= capacity)
        ((FlushFunction)hkpMoppCodeGenerator_resize)(this);
    data[capacity - position - 1] = (unsigned char)(value >> 16);
    ++position;
    if (position >= capacity)
        ((FlushFunction)hkpMoppCodeGenerator_resize)(this);
}

struct S_00e06aa0_Pool
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void Free(void* p);
};
struct S_00e06aa0_Item
{
    int unk00;
    bool m_flag;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    void* m_p70;
    void* m_p74;
};
struct S_00e06aa0
{
    int unk00;
    int unk04;
    int unk08;
    S_00e06aa0_Pool* m_kNodePool;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    bool m_enabled;
    void hkpMoppDefaultAssembler_releaseNode(S_00e06aa0_Item* item);
};
// If the item is not flagged and this object is enabled, frees the item's two pointers through the pool and nulls them.
// @f3 0x00a86210 (community match, verified in this file)
struct R2_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00e06aa0_Pool* m_kNodePool;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    bool m_enabled;
};
// pdb: hkpMoppDefaultAssembler::releaseNode | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(call_gap), high
void S_00e06aa0::hkpMoppDefaultAssembler_releaseNode(S_00e06aa0_Item* item)
{
    if (!item->m_flag && ((R2_Obj*)this)->m_enabled)
    {
        m_kNodePool->Free(item->m_p70);
        m_kNodePool->Free(item->m_p74);
        item->m_p70 = 0;
        item->m_p74 = 0;
    }
}


struct Node
{
    Node* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    char unk38;
    char unk39;
};
// Walks the linked list from node, marking each node's unk39 flag until one is already set or the list ends.
// @fnv 0x00e06b20
// pdb: hkpMoppDefaultAssembler::fixScale | hkpMoppDefaultAssembler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: currentNode
void __stdcall FUN_00e06b20(Node* node)
{
    while (node)
    {
        if (node->unk39)
            return;
        node->unk39 = 1;
        node = node->next;
    }
}

struct Limits
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
};
// Copies second->unk34 into third->unk34, then compares unk38/unk24 thresholds and may overwrite third->unk34 with first->unk24.
// @fnv 0x00e06b50
// pdb: hkpMoppDefaultAssembler::calcReoffset | hkpMoppDefaultAssembler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: currentNode, parentInfo, currentInfo
void __stdcall AdjustLimits(Limits* first, Limits* second, Limits* third)
{
    third->unk34 = second->unk34;
    unsigned int value = third->unk38 - second->unk34 + first->unk24;
    if (value < 0x20)
        return;
    if (third->unk38 <= 2 && value < 0x100)
        return;
    if (third->unk38 < 0x20 && second->unk38 >= 0x20)
    {
        third->unk34 = first->unk24;
        return;
    }
    if (third->unk38 < 0x100 && second->unk38 >= 0x100)
    {
        third->unk34 = first->unk24;
        return;
    }
    if (third->unk38 >= 0x10000)
        return;
    if (second->unk38 >= 0x10000)
        third->unk34 = first->unk24;
}

namespace fnv_00e06db0 {
struct Node
{
    char pad[0x40];
    void* m_40;
    int m_44;
};

struct FUN_00e06db0_class
{
    __declspec(nothrow) void WriteOp(int a, void* p);
    void FUN_00e06db0(int* flag, Node* b, Node* c);
};

// If *flag is set, calls WriteOp(0, c->m_40) when c->m_44 is 0 and b->m_44 is nonzero; otherwise when c->m_44 is 0 and c->m_40 is set.
// @fnv 0x00e06db0
// pdb: hkpMoppDefaultAssembler::checkAndAddProperties | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap, medium
// pdb params: currentNode, parentInfo, currentInfo
void FUN_00e06db0_class::FUN_00e06db0(int* piFlag, Node* pNodeB, Node* pNodeC)
{
    if (*piFlag)
    {
        if (pNodeC->m_44 == 0 && pNodeB->m_44 != 0)
            WriteOp(0, pNodeC->m_40);
    }
    else
    {
        if (pNodeC->m_44 == 0 && pNodeC->m_40)
            WriteOp(0, pNodeC->m_40);
    }
}
}  // namespace fnv_00e06db0

struct S_00e07040_A
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};
struct S_00e07040_B
{
    int unk00;
    int unk04;
    int unk08;
};
template <class T> inline T S_00e07040_Max(T a, T b)
{
    return a > b ? a : b;
}
// Returns the smaller of two values.
// @fnv 0x00e07040
template <class T> inline T S_00e07040_Min(T a, T b)
{
    return a < b ? a : b;
}
// pdb: hkpMoppDefaultAssembler::calcRescaleBits | hkpMoppDefaultAssembler.obj | tesv_win, hash, low
int __stdcall FUN_00e07040(S_00e07040_A* a, S_00e07040_B* b)
{
    int n = b->unk08 - 8;
    if (n <= 0)
        n = 0;
    int r = a->unk24 - n;
    if (r > a->unk24)
        r = a->unk24;
    return r;
}

struct E07510Input
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char m_type;
};

struct E07510Solver
{
    void FUN_00e07070(void* b, void* c, void* d);
    void AdjustLimits(E07510Input* a, void* b, void* c);
    void FUN_00e07510(E07510Input* a, void* b, void* c, void* d);
};

// If the input's m_type is 1, calls FUN_00e07070 with b, c and d, then always calls AdjustLimits with a, b and c.
// @fnv 0x00e07510
// pdb: hkpMoppDefaultAssembler::calcReoffset | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkpMoppDefaultAssembler::initTopDown)
// pdb params: currentNode, parentInfo, currentInfo
void E07510Solver::FUN_00e07510(E07510Input* pInput, void* b, void* c, void* d)
{
    if (pInput->m_type == 1)
        FUN_00e07070(b, c, d);
    AdjustLimits(pInput, b, c);
}

struct S_e07c50_Buf
{
    int unk0;
    int unk4;
    int unk8;
    int m_iElementCount;
};
struct S_e07c50_Item;
struct S_e07c50
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_e07c50_Buf* m_buf;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_uiItemCount;
    void FUN_00e06b20(S_e07c50_Item* item);
    void hkpMoppDefaultAssembler_addTerminals(S_e07c50_Item* item, int b, int c);
    void hkpMoppDefaultAssembler_addCut(S_e07c50_Item* item, int c);
    int hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(S_e07c50_Item* item, int b, int c);
};
struct S_e07c50_Item
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    char m_flag38;
    char m_flag39;
    char unk3A;
    char unk3B;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_kRayEnd;
};
// @fnv 0x00e07c50
// pdb: hkpMoppDefaultAssembler::assembleCutAndTerminalCommand | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, caller + bridge(call_gap_sim|call_gap) + skyrim(call_gap), high
int S_e07c50::hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(S_e07c50_Item* item, int b, int c)
{
    FUN_00e06b20(item);
    m_uiItemCount++;
    int start = m_buf->m_iElementCount;
    hkpMoppDefaultAssembler_addTerminals(item, b, c);
    hkpMoppDefaultAssembler_addCut(item, c);
    item->m_kRayEnd = m_buf->m_iElementCount;
    int r = m_buf->m_iElementCount - start;
    item->m_flag38 = 1;
    return r;
}

namespace fnv_00e08040 {
struct Node
{
    int unk00;
    unsigned char leaf;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    unsigned char complete;
    int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    Node* left;
    Node* right;
};
struct __declspec(align(8)) State
{
    int depth;
    bool retrying;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    State()
    {}
    State(const State&, Node*, float*);
    void FUN_00e095d0(const State*, Node*, float*);
};
struct MergeInfo
{
    bool changed;
    int index;
    int unk08, unk0C, unk10;
};
struct CheckResult
{
    bool value;
    CheckResult(bool v) : value(v)
    {}
    operator bool() const
    {
        return value;
    }
};
void __stdcall FUN_00e06b20(Node*);
void __stdcall FUN_00e07510(Node*, void*, State*, MergeInfo*);
}  // namespace fnv_00e08040

struct Allocator
{
    virtual void* unk00(void* p);
    virtual void* unk04(void* p);
    virtual void __thiscall ReleaseBlock(void* p, unsigned short size);
};
struct Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* allocator;
};
extern "C" Router* __cdecl FUN_00c85750();
struct FUN_00e09640_class
{
    virtual void unknownVirtual();
    unsigned short unk04;
    void __thiscall DestroyAudioBuffer();
    FUN_00e09640_class* __thiscall FUN_00e09640(int flags);
};

struct FUN_00e06800_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void __thiscall Flush();
    void __thiscall hkpMoppCodeGenerator_addCommand16(char a, int v);
};

// @fnv 0x00e06800
// pdb: hkpMoppCodeGenerator::addCommand16 | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __thiscall FUN_00e06800_cls::hkpMoppCodeGenerator_addCommand16(char acByte, int aiValue)
{
    m_buf[m_cap - m_uiItemCount - 1] = (char)aiValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    aiValue = aiValue >> 8;
    m_buf[m_cap - m_uiItemCount - 1] = (char)aiValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = acByte;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();
}

struct FUN_00e06880_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void __thiscall Flush();
    void __thiscall FUN_00e06880(char a, int v);
};

// Writes the low three bytes of v and then a into the buffer from the end, flushing whenever the buffer fills.
// @fnv 0x00e06880
// pdb: hkpMoppCodeGenerator::addCommand24 | hkpMoppDefaultAssembler.obj | tesv_win, hash, low
void __thiscall FUN_00e06880_cls::FUN_00e06880(char acTrailingByte, int aiValue)
{
    m_buf[m_cap - m_uiItemCount - 1] = (char)aiValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(aiValue >> 8);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(aiValue >> 16);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = acTrailingByte;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();
}

struct FUN_00e069a0_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void __thiscall Flush();
    void __thiscall FUN_00e069a0(char a, unsigned int v);
};

// Writes the four bytes of v and then a into m_buf from the end backwards, flushing whenever the buffer fills.
// @fnv 0x00e069a0
// pdb: hkpMoppCodeGenerator::addCommand24 | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkpMoppCodeGenerator::addCommand32)
// pdb params: code, param
void __thiscall FUN_00e069a0_cls::FUN_00e069a0(char a, unsigned int auValue)
{
    m_buf[m_cap - m_uiItemCount - 1] = (char)auValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(auValue >> 8);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(auValue >> 16);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(auValue >> 24);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();

    m_buf[m_cap - m_uiItemCount - 1] = a;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        Flush();
}

struct FUN_00e06490_cls
{
    void __thiscall hkpMoppCodeGenerator_resize();
};

struct FUN_00e06a60_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    void __thiscall FillWithPattern(int count);
};

// @fnv 0x00e06a60
// pdb: hkpMoppCodeGenerator::pad | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: size
void __thiscall FUN_00e06a60_cls::FillWithPattern(int count)
{
    if (count <= 0)
        return;
    int n = count;
    do
    {
        char* base = (char*)unk08;
        base[unk10 - unk0c - 1] = (char)0xcd;
        unk0c++;
        if (unk0c >= unk08)
        {
            ((FUN_00e06490_cls*)this)->hkpMoppCodeGenerator_resize();
        }
        n--;
    } while (n != 0);
}

// FUN_00e06af0 - a small __thiscall member that fills in a result flag.
//
// The original code is exactly:
//     00e06af0  8b 44 24 08        mov eax, dword ptr [esp + 8]
//     00e06af4  83 78 08 16        cmp dword ptr [eax + 8], 16h
//     00e06af8  7d 0a              jge 0x00e06b04
//     00e06afa  8b 44 24 04        mov eax, dword ptr [esp + 4]
//     00e06afe  c6 00 01           mov byte ptr [eax], 1
//     00e06b01  c2 0c 00           ret 0ch
//     00e06b04  8b 54 24 0c        mov edx, dword ptr [esp + 0ch]
//     00e06b08  8b 02              mov eax, dword ptr [edx]
//     00e06b0a  3b 41 18           cmp eax, dword ptr [ecx + 18h]
//     00e06b0d  8b 44 24 04        mov eax, dword ptr [esp + 4]
//     00e06b11  7f eb              jg 0x00e06afe
//     00e06b13  c6 00 00           mov byte ptr [eax], 0
//     00e06b16  c2 0c 00           ret 0ch
//
// so the member is
//     char* FUN_00e06af0(char* out, Actor* actor, int* value)
// and it returns the flag pointer it was given:
//
//   * if actor->unk08 is below 0x16 the flag is set to 1 unconditionally;
//   * otherwise the flag is 1 when *value is greater than the member
//     field at +0x18 and 0 when it is not.
//
// The "return out;" in every branch matters for the code generation: the
// returned pointer is already in EAX, and because the branches are not
// plain assignments MSVC 2008 keeps the two stores as real branches
// instead of folding them into a single conditional store.

// The "actor" the first flag argument points at.
struct FUN_00e06780_actor
{
    int unk00;
    int unk04;
    int unk08;
};

// The class the member belongs to.  The unit's FUN_00e06780_class carries
// no data members, so the flag field lives in the derived stand-in.
struct FUN_00e06780_owner : public FUN_00e06780_class
{
    int unk14;
    int unk18;  // +0x18
    char* __thiscall FUN_00e06af0(char* out, FUN_00e06780_actor* actor, int* value);
};

// Writes 1 to out if actor->unk08 is below 0x16 or *value exceeds this->unk18, otherwise writes 0, and returns out.
// @fnv 0x00e06af0
// pdb: hkpMoppDefaultAssembler::shouldAssemble | hkpMoppDefaultAssembler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: currentNode, currentInfo
char* FUN_00e06780_owner::FUN_00e06af0(char* pResult, FUN_00e06780_actor* actor, int* piValue)
{
    if (actor->unk08 < 0x16)
    {
        *pResult = 1;
        return pResult;
    }
    else
    {
        if (*piValue > this->unk18)
        {
            *pResult = 1;
            return pResult;
        }
        *pResult = 0;
        return pResult;
    }
}

struct Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char* unk10;

    void hkpMoppCodeGenerator_resize();

    void AppendChar(char b)
    {
        unk10[unk08 - unk0c - 1] = b;
        unk0c++;
        if (unk0c >= unk08)
        {
            hkpMoppCodeGenerator_resize();
        }
    }

    void hkpMoppCodeGenerator_addCommand16(int a, int b);
};

struct FUN_00e06c40_class
{
    char pad[0x10];
    Stream* m_stream;

    int __thiscall FUN_00e06c40(int a1, int a2);
};

// @fnv 0x00e06c40
// pdb: hkpMoppDefaultAssembler::addDataOffset | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, medium, conflict (bridge: copyCodeAndEmbedTerminals)
// pdb params: offset, numTerminals
int __thiscall FUN_00e06c40_class::FUN_00e06c40(int a1, int a2)
{
    m_stream->AppendChar((char)a2);
    m_stream->AppendChar((char)(a2 >> 8));
    m_stream->hkpMoppCodeGenerator_addCommand16(0xd, a1);
    return 5;
}

extern "C" void __cdecl hkpMoppCodeGenerator_resize();

struct Sink
{
    int unk00;
    int unk04;
    int m_iCap;
    int m_iArrayLength;
    int m_iEnd;
    void __thiscall Flush();
};

struct Pkt
{
    int unk00;
    char m_b04;
    char unk05;
    char unk06;
    char unk07;
    char m_b08;
    char unk09;
    char unk0a;
    char unk0b;
    char m_b0c;
    char unk0d;
    char unk0e;
    char unk0f;
    char m_b10;
};

class FUN_00e06cb0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Sink* m_pSink;

    void __thiscall WritePacket(const Pkt* p);
};

// Writes four bytes of the packet (m_b10, m_b0c, m_b08, m_b04) into the sink buffer, flushing when it fills.
// @fnv 0x00e06cb0
// pdb: hkpMoppDefaultAssembler::addRescale | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: cmd
void __thiscall FUN_00e06cb0_cls::WritePacket(const Pkt* p)
{
    {
        Sink* s = m_pSink;
        char v = p->m_b10;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            s->Flush();
    }
    {
        Sink* s = m_pSink;
        char v = p->m_b0c;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            s->Flush();
    }
    {
        Sink* s = m_pSink;
        char v = p->m_b08;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            s->Flush();
    }
    {
        Sink* s = m_pSink;
        char v = p->m_b04;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            s->Flush();
    }
}

extern char DAT_01000000;

struct S_00e06e00_Item
{
    int unk0;
};

struct S_00e06e00_Buf
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    void hkpMoppCodeGenerator_addCommand8(int tag, unsigned int v);
    void hkpMoppCodeGenerator_addCommand16(int tag, unsigned int v);
    void FUN_00e06880(int tag, unsigned int v);
    void FUN_00e069a0(int tag, unsigned int v);
};

struct S_00e06e00_A0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00e06e00_Item* unk30[12];
    unsigned int* unk60;
};

struct S_00e06e00_A1
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44[16];
};

struct S_00e06e00_A2
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned int unk34;
};

struct S_00e06e00_Cls
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e06e00_Buf* unk10;
    int hkpMoppDefaultAssembler_addTerminals(S_00e06e00_A0* a, S_00e06e00_A1* b, S_00e06e00_A2* c);
    void WriteOp(int idx, S_00e06e00_Item* item);
};

// @fnv 0x00e06e00
// pdb: hkpMoppDefaultAssembler::addTerminals | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap_sim + bridge(call_seq|objrun) + skyrim(call_seq), high
int S_00e06e00_Cls::hkpMoppDefaultAssembler_addTerminals(S_00e06e00_A0* a, S_00e06e00_A1* b, S_00e06e00_A2* c)
{
    int start = unk10->unkC;
    unsigned int v = *a->unk60 - c->unk34;
    S_00e06e00_Buf* buf = unk10;
    if (v < 0x20)
    {
        *(char*)(buf->unk10 - buf->unkC + buf->unk8 - 1) = (char)(v + 0x30);
        buf->unkC++;
        if (buf->unkC >= buf->unk8)
        {
            hkpMoppCodeGenerator_resize();
        }
    }
    else if (v < 0x100)
    {
        buf->hkpMoppCodeGenerator_addCommand8(0x50, v);
    }
    else if (v < 0x10000)
    {
        buf->hkpMoppCodeGenerator_addCommand16(0x51, v);
    }
    else if (v < (unsigned int)&DAT_01000000)
    {
        buf->FUN_00e06880(0x52, v);
    }
    else
    {
        buf->FUN_00e069a0(0x53, v);
    }
    for (int i = 0; i < a->unk2C; i++)
    {
        if (a->unk30[i] && b->unk44[i])
        {
            WriteOp(i, a->unk30[i]);
        }
    }
    return unk10->unkC - start;
}

struct Vec3
{
    float x;
    float y;
    float z;
};

extern const double g_thresholdA;
extern const double g_thresholdB;

// Compares the x, y and z components of a Vec3 against g_thresholdA and g_thresholdB and returns a code from 0 to 12 identifying the region.
// @fnv 0x00e06f20
// pdb: hkpMoppDefaultAssembler::getSplitCode | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, caller, high
// pdb params: norm
// pdb: hkpMoppDefaultAssembler::getSplitCode | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, caller, high (was: ClassifyVec3Region)
int __stdcall hkpMoppDefaultAssembler_getSplitCode(const Vec3* pVec)
{
    int r;
    if ((double)pVec->x > g_thresholdA)
    {
        r = 0;
        if ((double)pVec->z > g_thresholdA)
        {
            r = 5;
            if ((double)pVec->y > g_thresholdA)
            {
                r = 9;
            }
            else if ((double)pVec->y < g_thresholdB)
            {
                r = 11;
            }
        }
        else if ((double)pVec->z < g_thresholdB)
        {
            r = 6;
            if ((double)pVec->y > g_thresholdA)
            {
                r = 10;
            }
            else if ((double)pVec->y < g_thresholdB)
            {
                r = 12;
            }
        }
        else
        {
            if ((double)pVec->y > g_thresholdA)
            {
                r = 7;
            }
            else if ((double)pVec->y < g_thresholdB)
            {
                r = 8;
            }
        }
    }
    else
    {
        if ((double)pVec->y > g_thresholdA)
        {
            r = 1;
            if ((double)pVec->z > g_thresholdA)
            {
                r = 3;
            }
            else if ((double)pVec->z < g_thresholdB)
            {
                r = 4;
            }
        }
        else
        {
            r = 2;
        }
    }
    return r;
}

struct S_00e07070_Pair
{
    int unk00;
    int unk04;
};
struct S_00e07070_Object
{
    int unk00;
    int unk04;
    int unk08;
    S_00e07070_Pair r[3];
    int m_24;
    int v[3];
};

struct S_00e07070_Result
{
    char ok;
    int count;
    int q[3];
};

extern "C" int __stdcall FUN_00e07040(S_00e07070_Object* a, S_00e07070_Object* b);

// @fnv 0x00e07070
// pdb: hkpMoppDefaultAssembler::recalcRescale | hkpMoppDefaultAssembler.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: parent, info, cmd
void __stdcall FUN_00e07070(S_00e07070_Object* a, S_00e07070_Object* b, S_00e07070_Result* out)
{
    int n = FUN_00e07040(a, b);
    out->ok = 0;
    if (n > 0)
    {
        if (n >= 4)
            n = 4;
        for (;;)
        {
            b->m_24 = a->m_24 - n;
            int i = 0;
            while (i < 3)
            {
                int s = a->m_24;
                int q = (b->r[i].unk00 - a->v[i]) >> s;
                b->v[i] = (q << s) + a->v[i];
                out->q[i] = q;
                if (((b->r[i].unk04 - b->v[i]) >> b->m_24) >= 255)
                    goto retry;
                i++;
            }
            break;
        retry:
            n--;
        }
        out->count = n;
        out->ok = 1;
    }
    else
    {
        b->m_24 = a->m_24;
        b->v[0] = a->v[0];
        b->v[1] = a->v[1];
        b->v[2] = a->v[2];
    }
}

struct S_00e07680_Writer
{
    int unk0;
    int unk4;
    int m_cap;
    int m_pos;
    unsigned char* m_buf;
    void AppendChar(int b);
    void hkpMoppCodeGenerator_resize();
    __forceinline void put(unsigned char b)
    {
        m_buf[m_cap - m_pos - 1] = b;
        m_pos++;
        if (m_pos >= m_cap)
            hkpMoppCodeGenerator_resize();
    }
};
struct S_00e07680
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00e07680_Writer* w;
    void WriteOffsetDelta(int);
    void hkpMoppDefaultAssembler_addSplit(int a1, int a2, int a3, int a4, int a5);
};

// @fnv 0x00e07680
// pdb: hkpMoppDefaultAssembler::addSplit | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(call_seq), high
void S_00e07680::hkpMoppDefaultAssembler_addSplit(int a1, int a2, int a3, int a4, int a5)
{
    int e = w->m_pos;
    int d = e - a5;
    if (a3 < 3)
    {
        e -= a4;
        if ((e > 0 || d > 0xf8) && e < 0x10000 && d < 0x10000)
        {
            w->AppendChar(d & 0xff);
            w->AppendChar((d >> 8) & 0xff);
            w->AppendChar(e & 0xff);
            w->AppendChar((e >> 8) & 0xff);
            w->AppendChar(a1);
            w->AppendChar(a2);
            w->AppendChar(a3 + 0x23);
            return;
        }
        if (a2 - a1 == 1)
        {
            if (d > 0xfb)
            {
                WriteOffsetDelta(a5);
                a5 = w->m_pos;
            }
            WriteOffsetDelta(a4);
            w->put(w->m_pos - a5);
            w->put(a1);
            w->put(a3 + 0x20);
            return;
        }
    }
    if (d > 0xfb)
    {
        WriteOffsetDelta(a5);
        a5 = w->m_pos;
    }
    WriteOffsetDelta(a4);
    w->put(w->m_pos - a5);
    w->put(a1);
    w->put(a2);
    w->put(a3 + 0x10);
}

struct Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Entry* unk70;
    Entry* unk74;
};
struct Handler
{
    int unk00, unk04, unk08, unk0c;
    Entry* unk10;
    void __thiscall FUN_00e06b20(Entry*);
    int __thiscall hkpMoppDefaultAssembler_getSplitCode(int);
    void __thiscall hkpMoppDefaultAssembler_findPlanes(Entry*, Entry*, Entry**, Entry**);
    void __thiscall hkpMoppDefaultAssembler_addSplit(Entry*, Entry*, int, int, int);
    void __thiscall WriteSize(int);
    void __thiscall FUN_00e06db0(Entry*, Entry*, Entry*);
    void __thiscall hkpMoppDefaultAssembler_addCut(Entry*, Entry*);
    void __thiscall WritePacket(char*);
    int __thiscall FUN_00e07ca0(Entry*, Entry*, Entry*, char*);
};
// @fnv 0x00e07ca0
// pdb: hkpMoppDefaultAssembler::assembleNonTerminalCommand | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap, medium
// pdb params: currentNode, parentInfo, currentInfo, rescaleCommandInfo
int __thiscall Handler::FUN_00e07ca0(Entry* first, Entry* second, Entry* third, char* flag)
{
    Entry* originalFirst = first;
    FUN_00e06b20(originalFirst);
    int previous = unk10->unk0c;
    int value = hkpMoppDefaultAssembler_getSplitCode(originalFirst->unk60);
    Entry* originalThird = third;
    hkpMoppDefaultAssembler_findPlanes(originalFirst, originalThird, &first, &third);
    hkpMoppDefaultAssembler_addSplit(third, first, value, originalFirst->unk70->unk5c, originalFirst->unk74->unk5c);
    int difference = originalThird->unk34 - second->unk34;
    if (difference != 0)
        WriteSize(difference);
    FUN_00e06db0(originalFirst, second, originalThird);
    hkpMoppDefaultAssembler_addCut(originalFirst, originalThird);
    if (*flag)
        WritePacket(flag);
    originalFirst->unk5c = unk10->unk0c;
    originalFirst->unk38 = 1;
    return unk10->unk0c - previous;
}

extern int __cdecl hkMath_hkFloatToInt(float f);

struct S_00e07da0_Bounds
{
    int unk0;
    char b4;
    int unk8;
    struct Range
    {
        int lo;
        int hi;
    } ranges[3];  // 0x0C
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40[1];
    int unk44[1];

    void AlignRanges();
};

struct S_00e07da0_Region : S_00e07da0_Bounds
{
    int lo48[3];
    int hi54[3];

    void BuildScaledRanges(struct S_00e07da0_Node* node, void* p);
    void FUN_00e09540();
};

struct S_00e07da0_Result
{
    bool valid;
    int value;
    int unk8;
    int unkC;
    int unk10;
};

struct S_00e07da0_Info
{
    char b0;
    char b1;
    char b2;
    char state[3];
    char pad6[2];
    int unk8;
    int mins[3];  // 0x0C
    int maxs[3];  // 0x18
};

struct S_00e07da0_Node
{
    int unk0;
    char b4;
    char pad5[3];
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int count2C;
    int offsets[2];        // 0x30
    S_00e07da0_Info info;  // 0x38
    void* unk5C;
    void* unk60;
    int unk64;
    int unk68;
    int unk6C;
    S_00e07da0_Node* child70;
    S_00e07da0_Node* child74;
};

struct S_00e07da0_Tree
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    float unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    float unk54;

    void BuildRegion(S_00e07da0_Node* node, S_00e07da0_Region* parent, S_00e07da0_Region* region);
    void hkpMoppDefaultAssembler_calcTermCut(S_00e07da0_Node* node, S_00e07da0_Region* region);
    void FUN_00e07070(S_00e07da0_Region* parent, S_00e07da0_Region* region, S_00e07da0_Result* out);
    int hkpMoppDefaultAssembler_getSplitCode(void* p);
    void hkpMoppDefaultAssembler_findPlanes(S_00e07da0_Node* node, S_00e07da0_Region* region, int* lo, int* hi);
};

// Recursively builds a region for node from parent and region, merging child bounds and states into node->info.
// @f3 0x00a87830 (community match, verified in this file)
namespace n_a87830
{
struct Node;
struct Bounds
{
    int unk0;
    char b4;
    int unk8;
    struct Range
    {
        int lo;
        int hi;
    } ranges[3];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40[1];
    int unk44[1];

    void AlignRanges();
};
struct Region : Bounds
{
    int lo48[3];
    int hi54[3];

    void BuildScaledRanges(Node* node, void* p);
    void FUN_00e09540();
};
struct Result
{
    bool valid;
    int value;
    int unk8;
    int unkC;
    int unk10;
};
struct Info
{
    char b0;
    char b1;
    char b2;
    char state[3];
    char b6;
    char b7;
    int unk8;
    int mins[3];
    int maxs[3];
};
struct Node
{
    int unk0;
    char b4;
    char b5;
    char b6;
    char b7;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int count2C;
    int offsets[2];
    Info info;
    void* unk5C;
    void* unk60;
    int unk64;
    int unk68;
    int unk6C;
    Node* child70;
    Node* child74;
};
struct Tree
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    float unk3C;
    int unk40;
    float unk44;

    void hkpMoppDefaultAssembler_calcTermCut(Node* node, Region* region);
    void Solve(Region* parent, Region* region, Result* out);
    int hkpMoppDefaultAssembler_getSplitCode(void* p);
    void EdgeRange(Node* node, Region* region, int* lo, int* hi);
};
}
extern int __cdecl hkMath_hkFloatToInt(float);

// pdb: hkpMoppDefaultAssembler::preCalcCutPositions | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap, low
// pdb params: currentNode, parentInfo, currentInfo
void S_00e07da0_Tree::BuildRegion(S_00e07da0_Node* pNode, S_00e07da0_Region* pParent, S_00e07da0_Region* pRegion)
{
    n_a87830::Tree* self = (n_a87830::Tree*)this;
    n_a87830::Node* node = (n_a87830::Node*)pNode;
    n_a87830::Region* parent = (n_a87830::Region*)pParent;
    n_a87830::Region* region = (n_a87830::Region*)pRegion;

    n_a87830::Info* info = &node->info;
    if (info->b0 != 0)
        return;

    if (node->b4 != 0)
    {
        region->AlignRanges();
        self->hkpMoppDefaultAssembler_calcTermCut(node, region);
        return;
    }

    n_a87830::Result out;
    if (info->b2 == 1)
        self->Solve(parent, region, &out);
    region->AlignRanges();
    int axis = self->hkpMoppDefaultAssembler_getSplitCode(node->unk60);
    {
        int lo, hi;
        self->EdgeRange(node, region, &lo, &hi);
    }

    n_a87830::Node* first = node->child74;
    n_a87830::Node* apChildren[2];
    apChildren[0] = first;
    apChildren[1] = node->child70;

    for (int k = 0; k < 3; k++)
    {
        float sc = self->unk3C;
        float* ps = &sc;
        hkMath_hkFloatToInt(self->unk44 * *ps);
        info->mins[k] = 0;
        info->maxs[k] = 0x7fffffff;
    }

    for (int i = 0; i < 2; i++)
    {
        n_a87830::Node* child = apChildren[i];
        n_a87830::Info* pChildInfo = &child->info;
        if (child == 0)
            continue;

        n_a87830::Region childRegion;
        static_cast<n_a87830::Bounds&>(childRegion) = *region;
        childRegion.unk38 = child->unk28 - child->unk24;
        childRegion.unk3C = child->count2C;
        for (int iIndex = 0; iIndex < child->count2C; iIndex++)
        {
            childRegion.unk40[iIndex] = child->offsets[iIndex];
            childRegion.unk44[iIndex] = child->offsets[iIndex + 1] - child->offsets[iIndex];
        }
        childRegion.BuildScaledRanges(child, &self->unk30);
        childRegion.unk0 = region->unk0 + 1;
        childRegion.b4 = 0;
        childRegion.FUN_00e09540();
        BuildRegion((S_00e07da0_Node*)child, (S_00e07da0_Region*)region, (S_00e07da0_Region*)&childRegion);

        if (child == first)
        {
            if (axis <= 2)
                child->info.mins[axis] = 0;
        }
        else
        {
            if (axis <= 2)
                child->info.maxs[axis] = 0x7fffffff;
        }

        for (int iIndex = 0; iIndex < 3; iIndex++)
        {
            int s = pChildInfo->state[iIndex];
            if (s == 1)
            {
                if (pChildInfo->mins[iIndex] <= region->lo48[iIndex] &&
                    pChildInfo->maxs[iIndex] >= region->hi54[iIndex])
                {
                    int t = info->state[iIndex];
                    info->state[iIndex] = t < 1 ? 1 : t;
                    pChildInfo->state[iIndex] = 0;
                }
            }
            else if (s == 2)
            {
                if (pChildInfo->mins[iIndex] <= region->ranges[iIndex].lo &&
                    pChildInfo->maxs[iIndex] >= region->ranges[iIndex].hi)
                {
                    info->state[iIndex] = 2;
                    pChildInfo->state[iIndex] = 0;
                }
            }
            if (pChildInfo->state[iIndex] == 0)
            {
                {
                    int c = pChildInfo->mins[iIndex];
                    int n = info->mins[iIndex];
                    info->mins[iIndex] = n > c ? n : c;
                }
                {
                    int c = pChildInfo->maxs[iIndex];
                    int n = info->maxs[iIndex];
                    info->maxs[iIndex] = n < c ? n : c;
                }
            }
        }
    }
}


struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

int __cdecl FUN_00cbfe20(float v);

struct FUN_00e094a0_floatpair
{
    float lo;
    float hi;
};

struct FUN_00e094a0_intpair
{
    int lo;
    int hi;
};

struct FUN_00e094a0_floatset
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00e094a0_floatpair pairs[3];
};

struct FUN_00e094a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00e094a0_intpair m_0c[3];

    void BuildScaledRanges(FUN_00e094a0_floatset* a1, float* a2);
};

// @fnv 0x00e094a0
// pdb: hkpMoppAssemblerNodeInfo::updateExtents | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_seq, medium
// pdb params: node, codeInfo
void FUN_00e094a0_cls::BuildScaledRanges(FUN_00e094a0_floatset* pFloatSet, float* pValues)
{
    int best = 0;
    for (int i = 0; i < 3; i++)
    {
        volatile float s = pValues[3];
        float v = (pFloatSet->pairs[i].lo - pValues[i]) * s;
        this->m_0c[i].lo = FUN_00cbfe20(v);
        volatile float fScale2 = pValues[3];
        float w = (pFloatSet->pairs[i].hi - pValues[i]) * fScale2;
        this->m_0c[i].hi = FUN_00cbfe20(w) + 1;
        int iSpan = this->m_0c[i].hi - this->m_0c[i].lo;
        if (best <= iSpan)
            best = iSpan;
    }
}

// FUN_00e09540 - compute the level of an object from its bounding box.
//
// this : the object
//   +0x08 : the resulting level (a byte-sized value in the original)
//   +0x0c/+0x10, +0x14/+0x18, +0x1c/+0x20 : the three axis bounds
//
// The largest of the three axis extents is taken, the number of bits it
// needs is counted and the level is derived from that; the result is
// clamped to 0x18.

struct FUN_00e09540_Self
{
    void* unk00;
    int unk04;
    int unk08;  // the level
    int unk0c;  // x min
    int unk10;  // x max
    int unk14;  // y min
    int unk18;  // y max
    int unk1c;  // z min
    int unk20;  // z max
    void FUN_00e09540();
};

// @fnv 0x00e09540
// pdb: hkpMoppAssemblerNodeInfo::calcMaxExtentsSignificantBits | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, low
void FUN_00e09540_Self::FUN_00e09540()
{
    int size = this->unk10 - this->unk0c;
    int other = this->unk18 - this->unk14;
    if (size <= other)
        size = other;
    other = this->unk20 - this->unk1c;
    if (size <= other)
        size = other;

    int iBitCount = 0;
    unsigned int shifted = size;
    while (shifted)
    {
        shifted >>= 1;
        iBitCount++;
    }

    int level = -1;
    for (int i = 0; i < 3; i++)
    {
        int scaled = size + (1 << (iBitCount - 4));
        int count = 0;
        unsigned int value = scaled;
        while (value)
        {
            value >>= 1;
            count++;
        }
        if (count > level)
            level = count;
    }

    this->unk08 = (level > 0x18) ? 0x18 : level;
}

class FUN_00e095d0_cls
{
  public:
    unsigned int m_00;
    unsigned char m_04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;

    FUN_00e095d0_cls* __thiscall FUN_00e095d0(FUN_00e095d0_cls* src, unsigned int a2, unsigned int a3);
    void __thiscall CopyOffsets(unsigned int a);
    void __thiscall BuildScaledRanges(unsigned int a, unsigned int b);
    void __thiscall FUN_00e09540();
};

// @fnv 0x00e095d0
// pdb: hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: parentInfo, node, codeInfo
FUN_00e095d0_cls* FUN_00e095d0_cls::FUN_00e095d0(FUN_00e095d0_cls* pSource, unsigned int a2, unsigned int a3)
{
    *this = *pSource;
    CopyOffsets(a2);
    BuildScaledRanges(a2, a3);
    m_00 = pSource->m_00 + 1;
    m_04 = 0;
    FUN_00e09540();
    return this;
}

// Emit an opcode with an immediate, choosing the byte, short or int form (and its opcode offset) by value range.

class E6BC0Writer
{
  public:
    void WriteByteOp(int iOpcode, int iValue);
    void WriteShortOp(int iOpcode, int iValue);
    void WriteIntOp(int iOpcode, int iValue);
};

class E6BC0Encoder
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E6BC0Writer* m_pkWriter;

    void WriteOp(int iOpcode, int iValue);
};

// Writes iValue to the writer using a byte, short or int opcode chosen by the value's magnitude, offset from iOpcode.
// @fnv 0x00e06bc0
// pdb: hkpMoppCodeGenerator::addCode | hkpMoppDefaultAssembler.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: hkpMoppDefaultAssembler::addProperty)
// pdb params: code
void E6BC0Encoder::WriteOp(int iBaseOpcode, int iValue)
{
    E6BC0Writer* pkWriter = m_pkWriter;
    if (iValue < 0)
        pkWriter->WriteIntOp(iBaseOpcode + 0x68, iValue);
    else if (iValue < 0x100)
        pkWriter->WriteByteOp(iBaseOpcode + 0x60, iValue);
    else if (iValue < 0x10000)
        pkWriter->WriteShortOp(iBaseOpcode + 0x64, iValue);
    else
        pkWriter->WriteIntOp(iBaseOpcode + 0x68, iValue);
}

struct FUN_00e06ed0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e06e00_Buf* m_pStreamWriter;
    void WriteOffsetDelta(int iTarget);
};

// Computes the difference between the buffer's field at offset 12 and iTarget, then writes it with a width code (5-8) chosen by its magnitude if positive.
// @fnv 0x00e06ed0
// pdb: hkpMoppDefaultAssembler::addJump | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: jumpPos
void FUN_00e06ed0_Class::WriteOffsetDelta(int iTargetValue)
{
    int iOffset = ((int*)m_pStreamWriter)[3] - iTargetValue;
    if (iOffset > 0)
    {
        if (iOffset < 0xff)
            m_pStreamWriter->hkpMoppCodeGenerator_addCommand8(5, iOffset);
        else if (iOffset < 0xffff)
            m_pStreamWriter->hkpMoppCodeGenerator_addCommand16(6, iOffset);
        else if (iOffset < 0xffffff)
            m_pStreamWriter->FUN_00e06880(7, iOffset);
        else
            m_pStreamWriter->FUN_00e069a0(8, iOffset);
    }
}

extern int __cdecl hkMath_hkFloatToInt(float f);

struct Node07400
{
    int unk00;
    char b04;
    int unk08;
    struct Range
    {
        float fLo;
        float fHi;
    } ranges[3];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int mins[3];
    int maxs[3];
};

struct Region07400
{
    int unk00;
    char b04;
    int unk08;
    struct Range
    {
        int lo;
        int hi;
    } ranges[3];
    int m_iShift;
};

template <class T> inline T Min07400(T a, T b)
{
    return a < b ? a : b;
}
template <class T> inline T Max07400(T a, T b)
{
    return a > b ? a : b;
}

struct Tree07400
{
    int unk00[15];
    float m_fScale;
    int unk40[6];
    float m_fMinCount;
    int unk5C;
    float m_afMaxCount[3];

    void hkpMoppDefaultAssembler_calcTermCut(Node07400* node, Region07400* region);
};

// @f3 0x00a86eb0 (community match, verified in this file)
// pdb: hkpMoppDefaultAssembler::calcTermCut | hkpMoppDefaultAssembler.obj | fnv360_0822_debug, call_gap_sim, high
// pdb params: currentNode, currentInfo
// pdb: hkpMoppDefaultAssembler::calcTermCut | hkpMoppDefaultAssembler.obj | fnv360_0822_debug, call_gap_sim, high (was: ComputeNodeBounds)
void Tree07400::hkpMoppDefaultAssembler_calcTermCut(Node07400* node, Region07400* region)
{
    Node07400* pNode = *(Node07400* volatile*)&node;
    Region07400* pRegion = *(Region07400* volatile*)&region;
    float* pMaxCount = (float*)((char*)this + 0x50);
    (void)pRegion;
    for (int i = 0; i < 3; i++)
    {
        float fExtent = pNode->ranges[i].fHi - pNode->ranges[i].fLo;
        float fCount = (float)(1 << region->m_iShift) / *(float*)((char*)this + 0x3c);
        fCount = Max07400(fCount, *(float*)((char*)this + 0x48));
        float fMaxCount = *pMaxCount;
        if (fExtent < fMaxCount)
            fCount = Min07400(fCount, fMaxCount);
        float fScale = *(float*)((char*)this + 0x3c);
        int iMargin = hkMath_hkFloatToInt(fScale * fCount);
        int iHi = region->ranges[i].hi;
        pNode->mins[i] = region->ranges[i].lo - iMargin;
        pNode->maxs[i] = iHi + iMargin + 1;
        pMaxCount++;
    }
}


struct Arg1Flags
{
    unsigned char unk00[0x3b];
    unsigned char m_3b[3];
};

struct Pair
{
    int m_ucLowNibble;
    int m_ucHighNibble;
};

struct Arg2Layout
{
    int unk00;
    int unk04;
    int unk08;
    Pair m_0c[3];
    int m_24;
    int m_28[3];
};

struct BufWriter
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int m_10;
    void __thiscall Flush();
    void __thiscall WriteInt24(int v);
};

inline void EmitByte(BufWriter* w, unsigned char v)
{
    ((char*)(w->m_10 - w->m_0c))[w->m_08 - 1] = v;
    w->m_0c++;
    if (w->m_0c >= w->m_08)
    {
        w->Flush();
    }
}

struct FUN_00e07550_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BufWriter* m_10;
    void __thiscall hkpMoppDefaultAssembler_addCut(Arg1Flags* a1, Arg2Layout* a2);
};

// @fnv 0x00e07550
// pdb: hkpMoppDefaultAssembler::addCut | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap_sim + bridge(call_seq|call_gap_sim) + skyrim(call_seq), high
void FUN_00e07550_cls::hkpMoppDefaultAssembler_addCut(Arg1Flags* apFlags, Arg2Layout* apLayout)
{
    int i = 0;
    int* pHighValue = &apLayout->m_0c[0].m_ucHighNibble;
    int* volatile pBaseValue = apLayout->m_28;
    for (; i < 3; i++)
    {
        if (apFlags->m_3b[i] == 1)
        {
            int base = *pBaseValue;
            int shift = apLayout->m_24;
            unsigned char ucHighDelta = (unsigned char)(((pHighValue[0] - base) >> shift) + 1);
            unsigned char ucLowDelta = (unsigned char)((pHighValue[-1] - base) >> shift);
            EmitByte(m_10, ucHighDelta);
            EmitByte(m_10, ucLowDelta);
            EmitByte(m_10, (unsigned char)(i + 0x26));
        }
        if (apFlags->m_3b[i] == 2)
        {
            int hi = pHighValue[0];
            int lo = pHighValue[-1];
            m_10->WriteInt24(hi + 1);
            m_10->WriteInt24(lo);
            EmitByte(m_10, (unsigned char)(i + 0x29));
        }
        pHighValue += 2;
        pBaseValue++;
    }
}

struct KdNode;
struct KdCtx;

struct KdCtx
{
    int level;
    char flag;
    char unk05;
    char unk06;
    char unk07;
    int shift;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;

    void __thiscall CopyOffsets(KdNode* k);
    void __thiscall BuildScaledRanges(KdNode* k, float* p);
    void __thiscall FUN_00e09540();
};

struct KdNode
{
    int unk00;
    char leaf;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    float b[6];
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    char unk38;
    char a;
    char bb;
    char cc[3];
    char unk3e;
    char unk3f;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    KdNode* ch[2];
};

struct MyTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int lim;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    float f3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float f58;
    int unk5c;
    float f60[3];

    int __thiscall FUN_00e07040(KdCtx* a, KdCtx* c);
    void __thiscall FUN_00e07070(KdCtx* a, KdCtx* c, S_00e07070_Result* o);
    int __thiscall Recurse(KdNode* n, KdCtx* a, KdCtx* c);
};

// Recursively returns a shift level for n: a value from f3c, f58 and f60 for a leaf, else the minimum over its children, setting bb on some nodes.
// @f3 0x00a86c10 (community match, verified in this file)
struct __declspec(align(8)) NativeKdCtx : KdCtx {
    explicit NativeKdCtx(const KdCtx& source):KdCtx(source) {}
    void FUN_00a85e30(KdNode*);
    void FUN_00a88a60(KdNode*,void*);
    void FUN_00a88b00();
};
extern int __cdecl FUN_00954d20(float);

struct NativeTree1921
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int lim;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    float unk30;
    float unk34;
    float unk38;
    float f3c;
    int unk40;
    int unk44;
    float f48;
    int unk4c;
    float f50[3];
    int unk5c;
    float f60[3];

    int __thiscall FUN_00e07040(KdCtx* a, KdCtx* c);
    void __thiscall FUN_00e07070(KdCtx* a, KdCtx* c, S_00e07070_Result* o);
    int __thiscall Recurse(KdNode* n, KdCtx* a, KdCtx* c);
    int __thiscall FUN_00a86af0(KdCtx*,KdCtx*);
    void __thiscall FUN_00a86b20(KdCtx*,KdCtx*,S_00e07070_Result*);
};
// pdb: hkpMoppDefaultAssembler::preCalcScale | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, call_gap, low
// pdb params: currentNode, parentInfo, currentInfo
int __thiscall MyTree::Recurse(KdNode* apNode, KdCtx* a, KdCtx* c)
{
    NativeTree1921* tree = reinterpret_cast<NativeTree1921*>(this);
    int lo = c->shift;
    if (apNode->leaf)
    {
        float prev = tree->f48;
        int i = 0;
        float* pBounds = &apNode->b[0];
        float* p = tree->f50;
        float q;
        for (; i < 3; i++, p++, pBounds += 2)
        {
            if (!apNode->a)
                apNode->cc[i] = 1;
            q = *p;
            float d = pBounds[1] - pBounds[0];
            if (d < q && q < prev)
            {
                d = tree->f3c;
                int cp;
                cp = FUN_00954d20(d * q);
                int pObj = 1 << lo;
                if ((cp << 7) >= pObj)
                {
                    prev = q;
                }
                else if (!apNode->a)
                {
                    apNode->cc[i] = 2;
                }
            }
        }
        unsigned int cp = (unsigned int)FUN_00954d20(tree->f3c * double(0.9f) * prev);
        int k = 0;
        while (cp)
        {
            cp >>= 1;
            ++k;
        }
        int v = k + 6;
        return v > lo ? v : lo;
    }
    if (!apNode->a && c->level < tree->lim && tree->FUN_00a86af0(a, c) > 2)
    {
        apNode->bb = 1;
    }
    S_00e07070_Result buf;
    if (apNode->bb == 1)
    {
        tree->FUN_00a86b20(a, c, &buf);
    }
    long r[2] = {-1, -1};
    long t = 0x7fffffff;
    KdNode* apChildren[2] = {apNode->ch[0], apNode->ch[1]};
    for (int i = 1; i >= 0; i--)
    {
        KdNode* k = apChildren[i];
        if (k)
        {
            NativeKdCtx stCtx(*c);
            stCtx.FUN_00a85e30(k);
            stCtx.FUN_00a88a60(k, &tree->unk30);
            stCtx.level = c->level + 1;
            stCtx.flag = 0;
            stCtx.FUN_00a88b00();
            r[i] = Recurse(k, c, &stCtx);
            if (t >= stCtx.shift)
                t = stCtx.shift;
        }
    }
    int iMin = lo + 2 < t + 2 ? lo + 2 : t + 2;
    int v;
    KdNode* best = apChildren[0];
    if (best)
    {
        v = r[0];
        if (apNode->a)
        {
            if (!best->a && v < iMin)
                best->bb = 1;
        }
        else if (v < lo)
        {
            best->bb = 1;
        }
        if (!best->bb && iMin >= v)
            iMin = v;
    }
    KdNode* pSecond = apChildren[1];
    if (pSecond)
    {
        v = r[1];
        if (apNode->a)
        {
            if (!pSecond->a && v < iMin)
                pSecond->bb = 1;
        }
        else if (v < lo)
        {
            pSecond->bb = 1;
        }
        if (!pSecond->bb && iMin >= v)
            iMin = v;
    }
    return iMin;
}


#include <xmmintrin.h>
extern double _gModifierZero;
struct FUN_00e07b90_bounds
{
    float unk00, unk04, unk08, minimumX, maximumX, minimumY, maximumY, minimumZ, maximumZ;
};
struct FUN_00e07b90_vector
{
    float x, y, z, w;
};
// Stores the minimum corner of bounds into result and sets result->w to a scale factor derived from the largest axis extent.
// @f3 0x00a87650 (community match, verified in this file)
static __forceinline void SetVecF3(FUN_00e07b90_vector* v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}
// pdb: hkpMoppDefaultAssembler::getScaleInfo | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpMoppDefaultAssembler_getScaleInfo(const FUN_00e07b90_bounds* bounds, FUN_00e07b90_vector* result)
{
    SetVecF3(result, bounds->minimumX, bounds->minimumY, bounds->minimumZ, 0.0f);
    float fLargestExtent = 0.0f;
    float extent = bounds->maximumX - bounds->minimumX;
    if (!(extent < _gModifierZero))
        fLargestExtent = extent;
    extent = bounds->maximumY - bounds->minimumY;
    if (!(fLargestExtent > extent))
        fLargestExtent = extent;
    extent = bounds->maximumZ - bounds->minimumZ;
    if (!(fLargestExtent > extent))
        fLargestExtent = extent;
    result->w = 65536.0 * (254.0 / fLargestExtent);
}


namespace e083 {
struct Alloc;
struct Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    Alloc* unk10;
};
struct Pair
{
    int a;
    int b;
};
struct PairArray
{
    Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
}

void __cdecl ResizeAudioStream(e083::Alloc* a, void* arr, int elemSize);

// Copies all pairs from srcp to dst, adding delta to each pair's a field, growing dst when full.
// @fnv 0x00e08320
static __declspec(noinline) void FUN_00e08320(e083::PairArray* srcp, e083::PairArray* dst, int delta)
{
    e083::PairArray* const* pp = &srcp;
    e083::PairArray* src = *pp;
    for (int i = 0; i < src->m_iElementCount; i++)
    {
        e083::Router* h = (e083::Router*)FUN_00c85750();
        if (dst->m_iElementCount == (dst->m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(h->unk10, dst, 8);
        int n = dst->m_iElementCount;
        e083::Pair* out = dst->m_data + n;
        dst->m_iElementCount = n + 1;
        out->b = src->m_data[i].b;
        out->a = src->m_data[i].a + delta;
    }
}

struct BvAllocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(unsigned int);
    virtual void v8();
    virtual void vc();
    virtual void ReleaseBlock(void*, int);
};
void __cdecl ResizeAudioStream(void*, void*, int);
inline BvAllocator& GetHeap()
{
    return *(BvAllocator*)FUN_00c85750()->allocator;
}
struct BvHeapRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    BvAllocator* allocator;
};
inline BvHeapRouter* GetBvRouter()
{
    return (BvHeapRouter*)FUN_00c85750();
}
template <class T> struct BvArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void clear()
    {
        for (int i = 0; i < m_iElementCount; ++i)
            m_data[i].~T();
        m_iElementCount = 0;
    }
    void ClearAndRelease(BvAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000u) == 0)
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void AddBack(Router& router, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.allocator, this, sizeof(T));
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < 1; i++)
            p[i] = t;
        m_iElementCount++;
    }
};

struct BvFixup
{
    int offset;
    int value;
};
struct FUN_00e065f0
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_pRayCursor;
    int m_offset;
    unsigned char* m_data;
    BvArray<BvFixup> m_buffer;

    void FillWithPattern(int);
    void FUN_00e06480();
    FUN_00e065f0(unsigned int id) throw();
    void Destroy();
    void* operator new(unsigned int n)
    {
        FUN_00e065f0* p = static_cast<FUN_00e065f0*>(GetBvRouter()->allocator->AllocateMemoryBlock(n));
        p->m_usMemSizeAndFlags = (unsigned short)n;
        return p;
    }
};

struct WriterEntry
{
    FUN_00e065f0* m_pStreamWriter;
    unsigned int m_iOwnerObjectOffset;
};

struct BvReferenceConverter
{
    virtual void v0();
    virtual int ConvertReferences(int*, int);
    virtual void writeBuffer(int*, int, unsigned char*);
};
struct BvTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    WriterEntry* m_entries;
    int unk14;
    int unk18;
    BvReferenceConverter* m_converter;
};

struct BvNode;

struct BvInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_uiEdgeIndex;
};

struct BvNode
{
    int unk00;
    bool m_isLeaf;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int m_depth;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    BvInfo* m_info;
    int unk64;
    int unk68;
    int unk6c;
    BvNode* m_fMinimumU;
    BvNode* m_fMaximumU;
};

struct BvRange
{
    bool m_valid;
    int m_uiEdgeIndex;
    int unk08;
    int unk0c;
    int unk10;
};

void __stdcall hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(struct BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack);
void* __cdecl FUN_00cb1260(void*, const void*, int);
static void FUN_00e08320(BvArray<BvFixup>* destination, BvArray<BvFixup>* source, int adjustment)
{
    for (int i = 0; i < source->m_iElementCount; ++i)
    {
        BvAllocator& heap = GetHeap();
        if (destination->m_iElementCount == destination->getCapacity())
            ResizeAudioStream(&heap, destination, sizeof(BvFixup));
        BvFixup* out = destination->m_data + destination->m_iElementCount;
        ++destination->m_iElementCount;
        out->value = source->m_data[i].value;
        out->offset = source->m_data[i].offset + adjustment;
    }
}
static int FUN_00e08380(BvTree* tree, FUN_00e065f0* source, BvArray<int>* refs, FUN_00e065f0* destination)
{
    int padding = (-source->m_offset) & 3;
    if (!tree->m_converter)
        refs->m_iElementCount = 0;
    if (refs->m_iElementCount)
    {
        int bytes = tree->m_converter->ConvertReferences(refs->m_data, refs->m_iElementCount);
        destination->FillWithPattern(bytes);
        Router* router = FUN_00c85750();
        unsigned char* temporary = static_cast<unsigned char*>(router->unk00);
        router->unk00 = temporary + ((bytes + 127) & ~127);
        tree->m_converter->writeBuffer(refs->m_data, refs->m_iElementCount, temporary);
        FUN_00cb1260(destination->m_data + destination->m_pRayCursor - destination->m_offset, temporary, bytes);
        FUN_00c85750()->unk00 = temporary;
    }
    int before = destination->m_offset;
    destination->FillWithPattern(source->m_offset + padding);
    FUN_00cb1260(destination->m_data + destination->m_pRayCursor - destination->m_offset,
                 source->m_data + source->m_pRayCursor - source->m_offset, source->m_offset);
    source->FUN_00e06480();
    FUN_00e08320(&destination->m_buffer, &source->m_buffer, destination->m_offset - source->m_offset);
    destination->FUN_00e06480();
    return destination->m_offset - before;
}

struct BvBuilder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00e065f0* m_pStreamWriter;
    BvTree* m_iValueAt40;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_info30;

    void FUN_00e06c40(int offset, int count);
    void FUN_00e08470(BvNode* node);
    void FUN_00e07510(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, BvRange* range);
    void FUN_00e07ca0(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, BvRange* range);
    void FUN_00e08a60(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, int depth, BvArray<int>* refs);
};

// Recursively walks a BvNode: deep nodes go to a separate writer, leaves add their edge index to refs, other nodes recurse into both children.
// @fnv 0x00e08a60
void BvBuilder::FUN_00e08a60(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, int depth,
                             BvArray<int>* refs)
{
    if (node->m_depth > 0 && !stack->m_04)
    {
        int depthValue = node->m_depth;
        FUN_00e065f0* saved = m_pStreamWriter;
        WriterEntry& entry = m_iValueAt40->m_entries[depthValue];
        {
            FUN_00e065f0 writer(entry.m_iOwnerObjectOffset);
            m_pStreamWriter = &writer;
            stack->m_04 = true;
            BvArray<int> subRefs;
            subRefs.m_data = 0;
            subRefs.m_iElementCount = 0;
            subRefs.m_iCapacityState = 0x80000000;
            FUN_00e08a60(node, parent, stack, depthValue, &subRefs);
            if (m_iValueAt40->m_converter != 0)
            {
                int offset = m_pStreamWriter->m_offset + 5;
                FUN_00e06c40(offset + ((-offset) & 3), subRefs.m_iElementCount);
            }
            entry.m_pStreamWriter = new FUN_00e065f0(entry.m_iOwnerObjectOffset);
            FUN_00e08380(m_iValueAt40, m_pStreamWriter, &subRefs, entry.m_pStreamWriter);
            m_pStreamWriter->m_buffer.clear();
            subRefs.ClearAndRelease(GetHeap());
            writer.Destroy();
        }
        m_pStreamWriter = saved;
        FUN_00e08470(node);
        return;
    }

    if (node->m_isLeaf)
    {
        hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(node, parent, stack);
        const int& index = node->m_info->m_uiEdgeIndex;
        refs->AddBack(*FUN_00c85750(), index);
        return;
    }

    {
        BvRange range;
        FUN_00e095d0_cls child;
        range.m_valid = false;
        range.m_uiEdgeIndex = -1;
        FUN_00e07510(node, parent, stack, &range);
        BvNode* right = node->m_fMaximumU;
        child.FUN_00e095d0(stack, (unsigned int)right, (unsigned int)&m_info30);
        FUN_00e08a60(right, stack, &child, depth, refs);
        BvNode* left = node->m_fMinimumU;
        child.FUN_00e095d0(stack, (unsigned int)left, (unsigned int)&m_info30);
        FUN_00e08a60(left, stack, &child, depth, refs);
        FUN_00e07ca0(node, parent, stack, &range);
    }
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
template <class T> __forceinline void constructCopy(T* p, int n, const T& value)
{
    for (int i = 0; i < n; ++i)
        p[i] = value;
}
struct P154Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, unsigned);
};
struct P154System
{
    int unk00, unk04, unk08, unk0c;
    P154Allocator* allocator;
};
struct P154Memory
{
    static P154System* FUN_00c85750();
};

void __cdecl ResizeAudioStream(P154Allocator*, void*, int);
struct P154Array
{
    int* data;
    int count;
    unsigned capacity;
    P154Array() : data(0), count(0), capacity(0x80000000)
    {}
    void Search(P154Allocator*, int, int*, int);
    void append(const int& v)
    {
        P154System* s = P154Memory::FUN_00c85750();
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream(s->allocator, this, 4);
        constructCopy(data + count, 1, v);
        ++count;
    }
    void insert(int* src, int pos, int n)
    {
        P154System* r = P154Memory::FUN_00c85750();
        P154Allocator* a = r->allocator;
        Search(a, pos, src, n);
    }
    void clear()
    {
        P154System* r = P154Memory::FUN_00c85750();
        P154Allocator* a = r->allocator;
        count = 0;
        if (!(capacity & 0x80000000))
            a->Free(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};
struct P154Pair
{
    int first, second;
};
struct P154PairArray
{
    P154Pair* data;
    int count;
    unsigned capacity;
    P154Pair& grow()
    {
        P154System* s = P154Memory::FUN_00c85750();
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream(s->allocator, this, 8);
        for (int i = 0; i < 1; ++i)
            new (data + count + i) P154Pair;
        return data[count++];
    }
};
struct P154Cost
{
    virtual void v00();
    virtual int cost(int*, int);
};
struct P154Settings
{
    int limit, unk04, unk08, unk0c;
    P154PairArray pairs;
    P154Cost* metric;
    int base;
};
struct P154Writer
{
    int unk00, unk04, unk08, count;
};
struct P154Region
{
    int depth;
    char leaf;
    int unk08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, context, unk38, unk3c, unk40, unk44;
    void CopyOffsets(struct P154Node*);
    void BuildScaledRanges(struct P154Node*, float*);
    void FUN_00e09540();
};
struct P154Node
{
    int unk00;
    char leaf;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, index, unk44,
        unk48, unk4c, unk50, unk54, unk58, offset;
    int* values;
    int unk64, unk68, unk6c;
    P154Node* high;
    P154Node* low;
    __forceinline void shift(int amount, bool change)
    {
        if (change)
            offset += amount;
    }
};
__forceinline void adjustOffset(P154Node* node, int amount, bool change)
{
    if (change)
        node->offset += amount;
}
struct P154Result
{
    bool valid;
    int value;
    int unk08, unk0c, unk10;
};
struct P154Tree
{
    int unk00, unk04, unk08, unk0c;
    P154Writer* writer;
    P154Settings* settings;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int scale30, scale34, scale38;
    void hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(P154Node*, P154Region*, P154Region*);
    void FUN_00e07510(P154Node*, P154Region*, P154Region*, P154Result*);
    void FUN_00e07ca0(P154Node*, P154Region*, P154Region*, P154Result*);
    __forceinline int getCost(P154Array& a, int size)
    {
        int result = size;
        if (settings->metric && a.count)
            result += settings->metric->cost(a.data, a.count);
        return result;
    }
    int FUN_00e084f0(P154Node*, P154Region*, P154Region*, P154Array*);
};

namespace fnv_00e08240 {
struct PairEntry
{
    void* m_pHeadNode;
    void* m_iSecondInteger;
};

struct PairList
{
    PairEntry* m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

AllocHolder* FUN_00c85750();
void ResizeAudioStream(void* allocator, PairList* list, unsigned int elemSize);

struct SlotPair
{
    int m_00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
};

struct Node
{
    int unk00;
    unsigned char m_04;
    unsigned char unk05;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    int m_28;
    int unk2C;
    int unk30;
    int unk34;
    unsigned char m_38;
    unsigned char unk39;
    unsigned short unk3A;
    int unk3C;
    int m_40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    SlotPair* m_60;
    int unk64;
    int unk68;
    int unk6C;
    Node* m_70;
    Node* m_74;
};

}  // namespace fnv_00e08240

namespace fnv_00e08470 {

struct S_00e08470_Entry
{
    void* unk00;
    int unk04;
};

struct S_00e08470_Vector
{
    S_00e08470_Entry* unk00;
    int unk04;
    int unk08;
};

struct S_00e08470_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
};

extern "C" S_00e08470_Holder* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(void*, S_00e08470_Vector*, int);

}  // namespace fnv_00e08470

struct CodeCopySource : FUN_00e065f0
{
};

// Writes converter-produced reference data and then source's data into destination, adjusts fixups, and returns how far destination's offset grew.
// @f3 0x00a882d0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
void* __cdecl FUN_009234e0(void*, const void*, int);
struct BvScratch
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual unsigned char* AllocSlow(int size);
    virtual void FreeSlow(unsigned char* p);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned char* m_cur;
    int unk24;
    unsigned char* m_base;
    unsigned char* m_end;
    __forceinline unsigned char* Alloc(int n)
    {
        int size = (n + 15) & ~15;
        unsigned char* p = m_cur;
        unsigned char* e = p + size;
        if (e <= m_end)
        {
            m_cur = e;
            return p;
        }
        return AllocSlow(size);
    }
    __forceinline void Free(unsigned char* p)
    {
        m_cur = p;
        if (p == m_base)
            FreeSlow(p);
    }
};
// pdb: copyCodeAndEmbedTerminals | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, callee_sim, low, conflict (skyrim: hkReferencedObject::addReference)
static __declspec(noinline) int FUN_00e08380(BvTree* tree, CodeCopySource* source, BvArray<int>* refs,
                                             FUN_00e065f0* destination)
{
    int padding = (-source->m_offset) & 3;
    if (!tree->m_converter)
        refs->m_iElementCount = 0;
    if (refs->m_iElementCount)
    {
        int* data = refs->m_data; int bytes = tree->m_converter->ConvertReferences(data, refs->m_iElementCount);
        destination->FillWithPattern(bytes);
        unsigned char* temporary = ((BvScratch*)TlsGetValue(DAT_010f3170))->Alloc(bytes + 1);
        tree->m_converter->writeBuffer(refs->m_data, refs->m_iElementCount, temporary);
        FUN_009234e0(destination->m_data + destination->m_pRayCursor - destination->m_offset, temporary, bytes);
        ((BvScratch*)TlsGetValue(DAT_010f3170))->Free(temporary);
    }
    int before = destination->m_offset;
    destination->FillWithPattern(source->m_offset + padding);
    FUN_009234e0(destination->m_data + destination->m_pRayCursor - destination->m_offset,
                 source->m_data + source->m_pRayCursor - source->m_offset, source->m_offset);
    return destination->m_offset - before;
}
int copy_code_caller_a882d0(BvTree* tree, CodeCopySource* source, BvArray<int>* refs, FUN_00e065f0* destination)
{
    return FUN_00e08380(tree, source, refs, destination);
}


int copy_code_caller(BvTree* tree, CodeCopySource* source, BvArray<int>* refs, FUN_00e065f0* destination)
{
    return FUN_00e08380(tree, source, refs, destination);
}

extern "C" void* __cdecl memset(void*, int, unsigned int);

struct ObjectWriter
{
    int unk00;
    int unk04;
    int m_cap;
    int m_pos;
    char* m_data;
    int unk14;
    int unk18;
    int unk1c;

    void FUN_00e065f0(int size) throw();
    ObjectWriter(int size) throw()
    {
        FUN_00e065f0(size);
    }
    void Destroy() throw();
    ~ObjectWriter() throw()
    {
        Destroy();
    }
    void FUN_00c90510() throw();
};

struct HelperEntry
{
    ObjectWriter* ptr;
    int pos;
};

struct EntryArray
{
    HelperEntry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct AssemblerHelper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryArray m_entries;
    int unk1C;
};

template <typename T> struct MyArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline MyArray() throw()
    {
        memset(this, 0, 8);
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~MyArray() throw()
    {
        AudioHolder* holder = (AudioHolder*)FUN_00c85750();
        AudioAllocator* alloc = holder->m_pAllocator;
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            alloc->FreeArray(m_data, (m_iCapacityState & 0x3fffffff) * 4);
    }
    __forceinline void ClearAndRelease() throw()
    {
        AudioAllocator* alloc = ((AudioHolder*)FUN_00c85750())->m_pAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & 0x80000000))
        {
            int bytes = (cap & 0x3fffffff) * 4;
            alloc->FreeArray(m_data, bytes);
        }
        m_data = 0;
        m_iElementCount = 0;
    }
};

struct __declspec(align(8)) MyBounds
{
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;

    void BuildScaledRanges(S_00e07da0_Node* node, void* p) throw();
    void CopyOffsets(S_00e07da0_Node* node) throw();
    void FUN_00e09540() throw();
};

struct __declspec(align(8)) MyRegion : public MyBounds
{
    int lo48_0;
    int lo48_1;
    int lo48_2;
    int hi54_0;
    int hi54_1;
    int hi54_2;

    void CopyOffsets(S_00e07da0_Node* node) throw();
    void BuildScaledRanges(S_00e07da0_Node* node, void* p) throw();
    void FUN_00e09540() throw();
    void FUN_00e095d0(MyBounds* src, S_00e07da0_Node* node, void* p) throw();
};

extern "C" void __cdecl FUN_00e08380(AssemblerHelper*, ObjectWriter*, void*) throw();

struct Tree : public FUN_00e09640_class
{
    virtual void vf04() throw();
    virtual void vf08() throw();
    virtual void vf0c() throw();
    virtual void vf10() throw();
    virtual void hkpMoppDefaultAssembler_assemble(S_00e07da0_Node* node, int arg2, int arg3);
    virtual void vf18(S_00e07da0_Node* node, void* p) throw();

    int unk08;
    int unkC;
    ObjectWriter* m_stream;
    AssemblerHelper* m_pAssemblerHelper;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;

    void Recurse(S_00e07da0_Node* node, MyBounds* b, MyRegion* r) throw();
    void BuildRegion(S_00e07da0_Node* node, MyRegion* r1, MyRegion* r2) throw();
    void OptimizeTree(S_00e07da0_Node* node, MyBounds* b1, MyBounds* b2) throw();
    void FUN_00e084f0(S_00e07da0_Node* node, MyBounds* b, MyRegion* r, void* arr) throw();
    void FUN_00e08240(S_00e07da0_Node* node, int a, int b) throw();
    void FUN_00e08a60(S_00e07da0_Node* node, MyBounds* b1, MyBounds* b2, int a, void* arr) throw();
    void FUN_00e06c40(int a, int b) throw();
};

typedef void(__thiscall* Vf18Fn)(Tree*, S_00e07da0_Node*, void*) throw();

// Sets up MyBounds and MyRegion state for node, then writes node data into streams via m_pAssemblerHelper if present, else calls OptimizeTree.
// @f3 0x00a88610 (community match, verified in this file)
// Game function 00a88610 = hkpMoppDefaultAssembler::assemble (Havok 5.5.0, hkpInternal.lib, hkpMoppDefaultAssembler.obj),
// defined under the unit's stand-in symbol Tree::hkpMoppDefaultAssembler_assemble, with the file-static function it calls,
// copyCodeAndEmbedTerminals (FUN_00a882d0). The call at +0x3d7 passes that function's second parameter in esi:
// a static function whose callers are all in its file gets its own register convention, so its body is here.
//
// Self-contained: the declarations down to hkpMoppCode are the Havok 5.5.0 SDK's own (preprocessed and cut to
// what these two functions use; data members and virtual functions are all kept). The Mopp assembler classes
// after them are not shipped as headers; their layout, member order and signatures are the library's type
// records, and the inline bodies follow the unoptimized library build statement by statement.
// Callees are named by game address (the SDK name is in the comment beside each).
// The unit is compiled with /EHsc, the library was not, so the callees declared here carry throw(). The match
// needs it on seven of them: the code generator's constructor and destructor, FUN_00a87db0, FUN_00a87cd0,
// hkpMoppDefaultAssembler_assembleSubNodeIntoChunks, FUN_00a863b0 and the static FUN_00a882d0 (each is called while a local with a destructor lives).

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;

class hkClass;
class hkStatisticsCollector;

class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

// hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance: one member, the slot index.
extern unsigned long DAT_010f3170;

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		void FUN_008f6d90(void*, int nbytes, HK_MEMORY_CLASS ) throw();	// deallocateChunk
		__forceinline void* allocateStack(int nbytes);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes) throw();
		virtual void onStackUnderflow(void* p) throw();
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	return (hkThreadMemory*)(hkUlong)TlsGetValue(DAT_010f3170) ;
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0 )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}

class hkBaseObject
{
	public:
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
};
class hkReferencedObject : public hkBaseObject
{
	public:
		__forceinline hkReferencedObject();
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};
__forceinline hkReferencedObject::hkReferencedObject()
: m_referenceCount(1)
{
}
__forceinline void hkReferencedObject::addReference() const
{
	if ( m_memSizeAndFlags != 0 )
	{
		++m_referenceCount;
	}
}

namespace hkArrayUtil
{
	void __cdecl FUN_00901f10(void* array, int sizeElem) throw();	// _reserveMore
}
template <typename T>
class hkArray
{
	public:
		__forceinline hkArray();
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void clear();
		__forceinline T& expandOne( );
		typedef T* iterator;
		__forceinline iterator begin();
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}
template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().FUN_008f6d90( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}
template <typename T>
__forceinline T& hkArray<T>::expandOne( )
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::FUN_00901f10( this, sizeof(T) );
	}
	return m_data[m_size++];
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

class hkVector4
{
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkString
{
	public:
		static void __cdecl FUN_009234e0(void* dst, const void* src, int n) throw();	// memCpy
	private:
		hkArray<char> m_string;
};

template <typename T>
class hkFixedArray
{
	public:
		__forceinline T* begin();
	protected:
		__forceinline	hkFixedArray(){}
		hkPadSpu<T*> m_data;
		int m_debugSize;
};
template <typename T>
class hkLocalBuffer: public hkFixedArray<T>
{
	public:
		__forceinline hkLocalBuffer(int n, const char* what = 0 );
		__forceinline ~hkLocalBuffer();
};
template <typename T>
__forceinline hkLocalBuffer<T>::hkLocalBuffer( int capacity, const char* what )
{
	this->m_data = hkAllocateStack<T>(capacity);
	;
}
template <typename T>
__forceinline hkLocalBuffer<T>::~hkLocalBuffer()
{
	hkDeallocateStack( this->m_data.val() );
}
template <typename T>
T* hkFixedArray<T>::begin()
{
	return m_data;
}

struct hkpMoppCodeReindexedTerminal
{
	hkUint32 m_origShapeKey;
	hkUint32 m_reindexedShapeKey;
};
class hkpMoppCode : public hkReferencedObject
{
	public:
		enum BuildType
		{
			BUILT_WITH_CHUNK_SUBDIVISION,
			BUILT_WITHOUT_CHUNK_SUBDIVISION,
		};
		struct CodeInfo
		{
			hkVector4 m_offset;
		};
	public:
		virtual ~hkpMoppCode() {}
		void calcStatistics( hkStatisticsCollector* collector ) const;
	public:
		struct CodeInfo m_info;
		hkArray<hkUint8> m_data;
		hkEnum<BuildType, hkInt8> m_buildType;
};

// ---- classes whose headers the SDK does not ship (layout and signatures from the library's type records) ----

class hkpMoppTreeInternalNode;
class hkpMoppMediator;
class hkpMoppNodeMgr;
struct hkpMoppSplittingPlaneDirection;

struct hkpMoppExtent
{
	hkReal m_min;
	hkReal m_max;
};

class hkpMoppAssemblerData
{
	public:
		enum hkpRescaleCommandType { HK_MOPP_NO_RESCALE, HK_MOPP_RESCALE };
		enum hkpCutCommandType { HK_MOPP_NO_CUT, HK_MOPP_CUT8, HK_MOPP_CUT24 };

		hkBool m_isAssembled;
		hkBool m_scaleIsValid;
		hkEnum<hkpRescaleCommandType, hkInt8> m_rescaleCommandType;
		hkEnum<hkpCutCommandType, hkInt8> m_cutCommandType[3];
		int m_chunkId;
		int m_minCutPlanePosition[3];
		int m_maxCutPlanePosition[3];
		int m_assembledAddress;
};

class hkpMoppTreeNode
{
	public:
		struct hkpMopp3DOPExtents
		{
			hkpMoppExtent m_extent[3];
		};

		hkpMoppTreeInternalNode* m_parent;
		hkBool m_isTerminal;
		int m_numPrimitives;
		hkpMopp3DOPExtents m_extents;
		unsigned int m_minPrimitiveId;
		unsigned int m_maxPrimitiveId;
		int m_numProperties;
		unsigned int m_minPropertyValue[1];
		unsigned int m_maxPropertyValue[1];
		hkpMoppAssemblerData m_assemblerData;
};

class hkpMoppCodeGenerator : public hkReferencedObject
{
	public:
		hkpMoppCodeGenerator(int size) throw();		// FUN_00a85c40
		virtual ~hkpMoppCodeGenerator() throw();	// FUN_00a85c80

		inline void addCode(int code);
		inline void pad(int size);		// its out-of-line copy is FUN_00a861c0

		inline int getPos() { return m_pos; }
		inline int getSize() { return m_size; }

	protected:
		void FUN_00a85cb0() throw();	// resize

	public:
		int m_size;
		int m_pos;
		unsigned char* m_code;
};

inline void hkpMoppCodeGenerator::addCode(int code)
{
	m_code[m_size - m_pos - 1] = (unsigned char)code;

	m_pos++;
	if (m_pos >= m_size)
	{
		FUN_00a85cb0();
	}
}

inline void hkpMoppCodeGenerator::pad(int size)
{
	for (int i = 0; i < size; i++)
	{
		addCode(0xcd);
	}
}

class hkpPrimitiveCompressor
{
	public:
		virtual ~hkpPrimitiveCompressor();
		virtual int calcPrimitivesSize(const unsigned int* prims, int numPrims) const throw() = 0;
		virtual void storePrimitives(const unsigned int* prims, int numPrims, unsigned char* dst) const throw() = 0;
};

struct hkpMoppCompilerChunkInfo
{
	struct Chunk
	{
		hkpMoppCodeGenerator* m_code;
		int m_codeSize;
	};

	int m_maxChunkSize;
	hkArray<hkpMoppCodeReindexedTerminal> m_reindexInfo;
	hkArray<Chunk> m_chunks;
	hkpPrimitiveCompressor* m_compressor;
	int m_safetySize;
};

class hkpMoppAssemblerNodeInfo
{
	public:
		inline hkpMoppAssemblerNodeInfo(const hkpMoppTreeNode* node, const hkpMoppCode::CodeInfo& codeInfo);
		// its out-of-line copy is FUN_00a88b90
		inline hkpMoppAssemblerNodeInfo(const hkpMoppAssemblerNodeInfo& parentInfo, const hkpMoppTreeNode* node, const hkpMoppCode::CodeInfo& codeInfo);

		void FUN_00a88b00() throw();	// calcMaxExtentsSignificantBits

	protected:
		hkpMoppAssemblerNodeInfo() {}
		void FUN_00a85e30(const hkpMoppTreeNode* node) throw();	// updateOffsetAndSpread
		void FUN_00a88a60(const hkpMoppTreeNode* node, const hkpMoppCode::CodeInfo& codeInfo) throw();	// updateExtents

	public:
		int m_level;
		hkBool m_ignoreBandControlCode;
		int m_maxExtentsSignificantBits;
		int m_extents[3][2];
		int m_currentBitsResolution;
		int m_accumOffset[3];
		unsigned int m_terminalOffset;
		unsigned int m_terminalSpread;
		int m_numProperties;
		unsigned int m_propertiesOffset[1];
		unsigned int m_propertiesSpread[1];
};

inline hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(const hkpMoppAssemblerNodeInfo& parentInfo, const hkpMoppTreeNode* node, const hkpMoppCode::CodeInfo& codeInfo)
{
	*this = parentInfo;
	FUN_00a85e30(node);
	FUN_00a88a60(node, codeInfo);

	m_level = parentInfo.m_level + 1;
	m_ignoreBandControlCode = false;
	FUN_00a88b00();
}

inline hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(const hkpMoppTreeNode* node, const hkpMoppCode::CodeInfo& codeInfo)
{
	FUN_00a88a60(node, codeInfo);
	m_currentBitsResolution = 16;
	m_accumOffset[0] = m_accumOffset[1] = m_accumOffset[2] = 0;
	m_level = -1;
	m_terminalOffset = 0;
	m_ignoreBandControlCode = false;

	FUN_00a85e30(node);
	FUN_00a88b00();
}

class hkpMoppAssemblerCutInfo : public hkpMoppAssemblerNodeInfo
{
	public:
		hkpMoppAssemblerCutInfo() {}

		inline hkpMoppAssemblerCutInfo(const hkpMoppTreeNode* node, const hkpMoppCode::CodeInfo& codeInfo)
			: hkpMoppAssemblerNodeInfo(node, codeInfo)
		{
		}

		inline hkpMoppAssemblerCutInfo(const hkpMoppAssemblerCutInfo& parentInfo, const hkpMoppTreeNode* node, const hkpMoppCode::CodeInfo& codeInfo)
			: hkpMoppAssemblerNodeInfo(parentInfo, node, codeInfo)
		{
		}

	public:
		int m_lowCutPlanePosition[3];
		int m_highCutPlanePosition[3];
};

class hkpMoppAssembler : public hkReferencedObject
{
	public:
		struct hkpMoppAssemblerParams
		{
			float m_relativeFitToleranceOfInternalNodes;
			float m_absoluteFitToleranceOfInternalNodes;
			float m_absoluteFitToleranceOfTriangles;
			hkVector4 m_absoluteFitToleranceOfAxisAlignedTriangles;
			int m_groupLevels;
			hkBool m_interleavedBuildingEnabled;
		};

		hkpMoppAssembler() {}
		virtual ~hkpMoppAssembler() {}

		virtual int getNumSplittingPlaneDirections() const = 0;
		virtual const hkpMoppSplittingPlaneDirection* getSplittingPlaneDirections() const = 0;
		virtual void assemble(hkpMoppTreeNode* rootNode, hkpMoppNodeMgr* mgr, int minAssembledElems) = 0;
		virtual void getScaleInfo(hkpMoppTreeNode* rootNode, hkpMoppCode::CodeInfo* scaleInfo) = 0;
};

class hkpMoppDefaultAssembler : public hkpMoppAssembler
{
	public:
		virtual ~hkpMoppDefaultAssembler();

		virtual void assemble(hkpMoppTreeNode* rootNode, hkpMoppNodeMgr* mgr, int minAssembledElems);
		virtual void getScaleInfo(hkpMoppTreeNode* rootNode, hkpMoppCode::CodeInfo* scaleInfo);
		virtual int getNumSplittingPlaneDirections() const;
		virtual const hkpMoppSplittingPlaneDirection* getSplittingPlaneDirections() const;

		int FUN_00a87db0(hkpMoppTreeNode* node, const hkpMoppAssemblerNodeInfo& parentInfo, hkpMoppAssemblerNodeInfo& currentInfo, hkArray<unsigned int>& chunkPrims) throw();	// calcChunkPoints
		int FUN_00a87cd0(hkpMoppTreeNode* node, int chunkId, int idx) throw();	// calcTerminalIdsForChunks
		void hkpMoppDefaultAssembler_assembleSubNodeIntoChunks(hkpMoppTreeNode* node, const hkpMoppAssemblerNodeInfo& parentInfo, hkpMoppAssemblerNodeInfo& currentInfo, int chunkId, hkArray<unsigned int>& terminals) throw();	// assembleSubNodeIntoChunks

	protected:
		friend struct Tree;	// the unit's stand-in class, under whose symbol assemble() is defined below
		int FUN_00a86c10(hkpMoppTreeNode* node, const hkpMoppAssemblerNodeInfo& parentInfo, hkpMoppAssemblerNodeInfo& currentInfo) throw();	// preCalcScale
		void FUN_00a87830(hkpMoppTreeNode* node, const hkpMoppAssemblerCutInfo& parentInfo, hkpMoppAssemblerCutInfo& currentInfo) throw();	// preCalcCutPositions
		int FUN_00a87ae0(hkpMoppTreeNode* node, const hkpMoppAssemblerNodeInfo& parentInfo, hkpMoppAssemblerNodeInfo& currentInfo) throw();	// assemblesubNode
		int FUN_00a863b0(int offset, int numTerminals) throw();	// addDataOffset

	public:
		hkpMoppMediator* m_mediator;
		hkpMoppNodeMgr* m_nodeMgr;
		hkpMoppCodeGenerator* m_code;
		hkpMoppCompilerChunkInfo* m_chunkInfo;
		int m_minDepthToBuild;
		int m_halfTreeDepth;
		int m_depthTopDownScale;
		int m_minAssembledElems;
		int m_numNodesAssembled;
		hkpMoppCode::CodeInfo m_codeInfo;
		hkpMoppAssemblerParams m_params;
};

// ---- copyCodeAndEmbedTerminals (FUN_00a882d0): static in the same source file as assemble() ----

static int FUN_00a882d0(hkpMoppCompilerChunkInfo* chunkInfo, hkpMoppCodeGenerator* codeWithTerminals, hkpMoppCodeGenerator* codeWithoutTerminals, hkArray<unsigned int>& terminals) throw()
{
	const int padBytesToAlign = (4 - codeWithoutTerminals->getPos()) & 3;

	if ( !chunkInfo->m_compressor )
	{
		terminals.clear();
	}

	if ( terminals.getSize() )
	{
		int primsSize = chunkInfo->m_compressor->calcPrimitivesSize( terminals.begin(), terminals.getSize() );

		codeWithTerminals->pad( primsSize );

		hkLocalBuffer<unsigned char> alignedBuffer( primsSize );
		chunkInfo->m_compressor->storePrimitives( terminals.begin(), terminals.getSize(), alignedBuffer.begin() );

		unsigned char* codeWithTerminalsPrimBase = &codeWithTerminals->m_code[ codeWithTerminals->getSize() - codeWithTerminals->getPos() ];
		hkString::FUN_009234e0( codeWithTerminalsPrimBase, alignedBuffer.begin(), primsSize );
	}

	int oldCodeSize = codeWithTerminals->getPos();

	{
		codeWithTerminals->pad( codeWithoutTerminals->getPos() + padBytesToAlign );

		unsigned char* codeWithoutTerminalsBase = &codeWithoutTerminals->m_code[ codeWithoutTerminals->getSize() - codeWithoutTerminals->getPos() ];
		unsigned char* codeWithTerminalsBase = &codeWithTerminals->m_code[ codeWithTerminals->getSize() - codeWithTerminals->getPos() ];
		hkString::FUN_009234e0( codeWithTerminalsBase, codeWithoutTerminalsBase, codeWithoutTerminals->getPos() );
	}

	return codeWithTerminals->getPos() - oldCodeSize;
}

// ---- hkpMoppDefaultAssembler::assemble(rootNode, mgr, minAssembledElems) ----

// pdb: hkpMoppDefaultAssembler::assemble | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Tree::hkpMoppDefaultAssembler_assemble(S_00e07da0_Node* node, int arg2, int arg3)
{
	hkpMoppDefaultAssembler* const self = reinterpret_cast<hkpMoppDefaultAssembler*>(this);
	hkpMoppTreeNode* const rootNode = reinterpret_cast<hkpMoppTreeNode*>(node);
	hkpMoppNodeMgr* const mgr = reinterpret_cast<hkpMoppNodeMgr*>(arg2);
	const int minAssembledElems = arg3;

	self->m_nodeMgr = mgr;
	self->m_numNodesAssembled = 0;
	self->m_minAssembledElems = minAssembledElems;

	self->getScaleInfo( rootNode, &self->m_codeInfo );

	if ( rootNode == 0 )
	{
		return;
	}

	{
		self->m_minDepthToBuild = 0;
		unsigned int s = rootNode->m_maxPrimitiveId;
		while ( s )
		{
			s = s >> 1;
			self->m_minDepthToBuild++;
		}
	}

	self->m_halfTreeDepth = self->m_minDepthToBuild >> 1;
	self->m_minDepthToBuild = ( self->m_minDepthToBuild / self->m_params.m_groupLevels ) * self->m_params.m_groupLevels;
	self->m_minDepthToBuild = self->m_params.m_groupLevels + self->m_params.m_groupLevels + self->m_minDepthToBuild - 1;

	hkpMoppAssemblerNodeInfo parentInfo( rootNode, self->m_codeInfo );

	{
		hkpMoppAssemblerNodeInfo currentInfo( parentInfo, rootNode, self->m_codeInfo );
		self->FUN_00a86c10( rootNode, parentInfo, currentInfo );
	}

	{
		hkpMoppAssemblerCutInfo parentCutInfo( rootNode, self->m_codeInfo );
		hkpMoppAssemblerCutInfo currentInfo( parentCutInfo, rootNode, self->m_codeInfo );
		self->FUN_00a87830( rootNode, parentCutInfo, currentInfo );
	}

	hkpMoppAssemblerNodeInfo currentInfo( parentInfo, rootNode, self->m_codeInfo );

	if ( !self->m_chunkInfo )
	{
		self->FUN_00a87ae0( rootNode, parentInfo, currentInfo );
	}
	else
	{
		rootNode->m_assemblerData.m_chunkId = 0;
		self->m_chunkInfo->m_chunks.expandOne();

		hkpMoppCodeGenerator* oldCode = self->m_code;
		{
			hkpMoppAssemblerNodeInfo dummyInfo( parentInfo, rootNode, self->m_codeInfo );
			hkArray<unsigned int> dummyPrims;
			hkpMoppCodeGenerator dummyCode( 0x100000 );
			self->m_code = &dummyCode;

			self->FUN_00a87db0( rootNode, parentInfo, dummyInfo, dummyPrims );
			self->FUN_00a87cd0( rootNode, rootNode->m_assemblerData.m_chunkId, 0 );
		}

		{
			hkArray<unsigned int> rootTerminals;
			hkpMoppCodeGenerator rootChunkCode( 0x100000 );
			self->m_code = &rootChunkCode;
			self->hkpMoppDefaultAssembler_assembleSubNodeIntoChunks( rootNode, parentInfo, currentInfo, rootNode->m_assemblerData.m_chunkId, rootTerminals );

			if ( self->m_chunkInfo->m_compressor )
			{
				const int codeSize = self->m_code->getPos() + 5;
				const int padBytesToAlign = ( 4 - codeSize ) & 3;
				int offset = codeSize + padBytesToAlign;
				self->FUN_00a863b0( offset, rootTerminals.getSize() );
			}

			self->m_code = oldCode;
			FUN_00a882d0( self->m_chunkInfo, self->m_code, &rootChunkCode, rootTerminals );

			hkpMoppCompilerChunkInfo::Chunk& rootChunk = self->m_chunkInfo->m_chunks[ rootNode->m_assemblerData.m_chunkId ];
			rootChunk.m_code = self->m_code;
			rootChunk.m_code->addReference();
			rootChunk.m_codeSize = self->m_code->getPos();
		}
	}
}

