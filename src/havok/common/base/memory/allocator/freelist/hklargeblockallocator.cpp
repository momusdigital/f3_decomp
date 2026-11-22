#include "f3_common.h"
// src/havok/common/base/memory/allocator/freelist/hklargeblockallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hklargeblockallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

int __cdecl FUN_00dd7e00(unsigned int size);

struct DD89B0MemChunk
{
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;

    unsigned int getChunkSize() const
    {
        return head & ~3u;
    }
    bool isPinuse() const
    {
        return (head & 1) != 0;
    }
    bool isCinuse() const
    {
        return (head & 2) != 0;
    }
    DD89B0MemChunk* chunkPlusOffset(unsigned int s)
    {
        return (DD89B0MemChunk*)((char*)this + s);
    }
    DD89B0MemChunk* chunkMinusOffset(unsigned int s)
    {
        return (DD89B0MemChunk*)((char*)this - s);
    }
    void setSizeAndPinuseOfFreeChunk(unsigned int s)
    {
        head = s | 1;
        chunkPlusOffset(s)->m_uiPreviousChunkSize = s;
    }
    void setFreeWithPinuse(unsigned int s, DD89B0MemChunk* n)
    {
        n->head &= ~1u;
        setSizeAndPinuseOfFreeChunk(s);
    }
};

typedef void(__cdecl* S_00dd8aa0_Callback)(void* start, unsigned int size, void* param);

struct S_00dd8aa0_Chunk
{
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;
    S_00dd8aa0_Chunk* fd;
    S_00dd8aa0_Chunk* bk;
    unsigned int getChunkSize() const
    {
        return head & ~3u;
    }
    bool isInuse() const
    {
        return ((head >> 1) & 1) != 0;
    }
    void* getPayload()
    {
        return (void*)(this + 1);
    }
    unsigned int getPayloadSize() const
    {
        return getChunkSize() - sizeof(S_00dd8aa0_Chunk);
    }
    S_00dd8aa0_Chunk* nextChunk()
    {
        return (S_00dd8aa0_Chunk*)((char*)this + getChunkSize());
    }
};

struct S_00dd8aa0_Page
{
    S_00dd8aa0_Page* m_pSecondNode;
    S_00dd8aa0_Page* m_next;
    int unk8;
    int unkC;
    char* m_kRayStart;
    char* m_kRayEnd;
    S_00dd8aa0_Chunk* getFirstChunk()
    {
        return (S_00dd8aa0_Chunk*)m_kRayStart;
    }
    S_00dd8aa0_Chunk* getFooter()
    {
        return (S_00dd8aa0_Chunk*)(m_kRayEnd - sizeof(S_00dd8aa0_Chunk));
    }
};

int __cdecl FUN_00dd7e00(int size);

struct FUN_00dd80d0_node
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00dd80d0_node* m_pSecondNode;  // +0x08
    FUN_00dd80d0_node* m_next;         // +0x0c
    FUN_00dd80d0_node* m_fMinimumU;    // +0x10
    FUN_00dd80d0_node* m_fMaximumU;    // +0x14
    FUN_00dd80d0_node* m_parent;       // +0x18
    unsigned int m_bin;                // +0x1c
};

struct FUN_00dd80d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_freeMask;  // +0x08
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00dd80d0_node* m_bins[32];  // +0x18
    void RemoveNode(FUN_00dd80d0_node* node);
};

struct FUN_00dd83a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char* m_10;
    unsigned int m_14;
    void FUN_00dd83a0();
};

class hkClass;
class hkStatisticsCollector;
// hkStringMap<const hkClass*>: only getWithDefault is called here.
struct FUN_00dd8480_sub
{
    void* m_elem;
    int m_numElems;
    int m_hashMod;
    int unk0C;
    int FUN_009b10f0(int a, int b);
};

// hkClassNameRegistry: the slots of the Fallout 3 hkChainedClassNameRegistry vtable (0x00e87e30) up to getClassByName,
// named as the New Vegas Xbox 360 PDB names them.
struct FUN_00dd8480_iface
{
    virtual ~FUN_00dd8480_iface();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual const char* getName() const;
    virtual int getClassByName(int className) const;
};

// hkChainedClassNameRegistry (slot 4 of its Fallout 3 vtable is this getClassByName): the hkDynamicClassNameRegistry
// part (vtable, reference count, m_name, m_map) and the registry it chains to.
struct FUN_00dd8480_cls
{
    int unk00;
    int unk04;
    int m_08;                                // m_name
    FUN_00dd8480_sub m_map;                  // +0x0C
    FUN_00dd8480_iface* m_nextRegistry;      // +0x1C
    int Allocate(int a);
};

// Looks the name up in this registry's map, then in the next registry of the chain.
// @f3 0x00a7df80 (community match, verified in this file)
int FUN_00dd8480_cls::Allocate(int aiSize)
{
    int r = m_map.FUN_009b10f0(aiSize, 0);
    if (r != 0)
    {
        return r;
    }
    if (m_nextRegistry != (FUN_00dd8480_iface*)r)
    {
        return m_nextRegistry->getClassByName(aiSize);
    }
    return 0;
}


struct Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void V28(void* apBlock, unsigned int auiSize);
};

struct FUN_00dd8750_cls
{
    virtual void v00();
    virtual void v04();
    virtual void V08(void* apBlock);
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
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    Heap* m_pHeap;

    void FUN_00dd8750(void* apBlock, unsigned int auiSize);
};

// @f3 0x00aae990 (community match, verified in this file)
namespace f3m_00aae990 {
struct Emitter_e990 {
    int unk00;
    int unk04;
    const char* name;
};
struct System_e990 {
    void FUN_00ab7320(Emitter_e990* emitter);
};
void FUN_00887da0(const char* fmt, ...);
}

// pdb: BSParticleSystemManager::AddEmitter | BSParticleSystemManager.obj | fnv360_0822_retail, ustr, medium
// pdb params: auiMasterParticleSystemIndex, apEmitter
void FUN_00dd8750_cls::FUN_00dd8750(void* apBlock, unsigned int auiSize)
{
    unsigned int index = (unsigned int)apBlock;
    f3m_00aae990::Emitter_e990* emitter = (f3m_00aae990::Emitter_e990*)auiSize;
    if (index < *(unsigned int*)((char*)this + 0xb0)) {
        int slot = (*(int**)((char*)this + 0xac))[index];
        if (slot != -1) {
            f3m_00aae990::System_e990* sys = (*(f3m_00aae990::System_e990***)((char*)this + 0xa0))[slot];
            if (sys) {
                sys->FUN_00ab7320(emitter);
                return;
            }
        }
    }
    f3m_00aae990::FUN_00887da0("DEFAULT: Trying to add an emitter (%s) to a master particle system (idx: %d) that hasn't been loaded.", emitter->name, index);
}


namespace fnv_00dd8790 {
struct FUN_00dd8790_hdr
{
    unsigned int m_00;
    unsigned int m_04;
};

struct FUN_00dd83a0_cls
{
    void FUN_00dd83a0();
};
struct FUN_00dd80d0_cls
{
    void RemoveNode(FUN_00dd8790_hdr* h);
};
struct FUN_00dd8400_cls
{
    void ResizeSegment(unsigned char* p, unsigned int n);
};

}  // namespace fnv_00dd8790

struct S_00dd8b20_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int key;
    int size;
};
struct S_00dd8b20_Ret
{
    int key;
    S_00dd8b20_Node* node;
    int size;
    S_00dd8b20_Ret()
    {}
};

struct SpanSegment
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_kRayEnd;
    unsigned int unk10;
    unsigned int m_iElementCount;
};

struct SpanServer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual unsigned char* resize(unsigned int* sizePtr, SpanSegment* seg, unsigned int end, unsigned int size,
                                  unsigned int* newEnd);
};

struct hkBool
{
    bool m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
};

struct FUN_00dd8400_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char* m_base;
    unsigned int m_fMinimumV;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    SpanServer* m_pServer;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    SpanSegment* m_seg;
    hkBool ResizeSegment(unsigned int size);
};

inline void alignEnd(char*& p)
{
    *(unsigned int*)&p &= ~15;
}

int __cdecl FUN_00dd7e00(unsigned int size);

struct FUN_00dd7de0
{
    virtual ~FUN_00dd7de0();
};
// @fnv 0x00dd7de0
FUN_00dd7de0::~FUN_00dd7de0()
{}

namespace fnv_00dd7e00 {
// FUN_00dd7e00: fast 2*log2-style bit scan of (x >> 8).

}  // namespace fnv_00dd7e00

// @f3 0x00594fb0 (community match, verified in this file)
namespace f3m_00594fb0 {
// 0x00594fb0: the secure-SCL std::copy_backward over 64-byte records (random-access overload):
// result = dest - (last - first) computed first, then the arbitrary-iterator loop is inlined.
// Element assignment is the out-of-line operator= at 0x5949c0.
struct Rec594 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    Rec594& operator=(const Rec594& src);
};
__forceinline Rec594* CopyBack594(Rec594* first, Rec594* last, Rec594* dest)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
Rec594* FUN_00594fb0(Rec594* first, Rec594* last, Rec594* dest)
{
    Rec594* result = dest - (last - first);
    CopyBack594(first, last, dest);
    return result;
}
}   // namespace f3m_00594fb0
