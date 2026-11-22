#include "f3_common.h"
// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// hkp3AxisSweep: the members getAabbCacheSize reads, at their Fallout 3 offsets (New Vegas Xbox 360 PDB names).
struct hkp3AxisSweepD116 {
    char unk00[0xA0];
    void* m_nodes;           // +0xA0 hkArray<hkpBpNode>
    int m_nodesSize;         // +0xA4 m_nodes.m_size
    int m_nodesCapacity;     // +0xA8
    char m_axis[0x24];       // +0xAC hkpBpAxis[3]
    int m_numMarkers;        // +0xD0
    int FUN_00d11630();
};
// @fnv 0x00d11630
// pdb: hkp3AxisSweep::getAabbCacheSize | hkp3AxisSweep.obj | tesv_win, objrun_sim, low
int hkp3AxisSweepD116::FUN_00d11630()
{
    return 8 * (3 * (m_nodesSize - m_numMarkers)) + 0x24;
}

struct BSAudio { void* p; int a; int b; };
BSAudio* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, void*, int);
struct UnkRet { int x; int y; };
// @f3 0x009919a0 (community match, verified in this file)
void __cdecl FUN_00901f10(void* buf, int n);
// pdb: hkp3AxisSweep::beginOverlap | hkp3AxisSweep.obj | tesv_win, objrun_open, low
void __fastcall AppendPairToBuffer(UnkRet* apFirst, UnkRet* apSecond, void* apBuffer)
{
    int* q = (int*)apBuffer;
    if (q[1] == (q[2] & 0x3fffffff))
        FUN_00901f10(apBuffer, 8);
    int* e = (int*)((char*)q[0] + q[1] * 8);
    q[1] = q[1] + 1;
    e[0] = *(int*)((char*)apFirst + 0xc);
    e[1] = *(int*)((char*)apSecond + 0xc);
}


// @fnv 0x00d10ad0
// pdb: staticFlipBit | hkp3AxisSweep.obj | tesv_win, objrun_open, low
void __fastcall ToggleBit(int aiBitIndex, void* apBits)
{
    int* p = (int*)apBits;
    int idx = aiBitIndex >> 5;
    int mask = 1 << (aiBitIndex & 0x1F);
    p[idx] ^= mask;
}

struct Entry {
    unsigned short key;
    unsigned short value;
};
// Binary-searches a sorted Entry range for the first entry whose key is not less than key, returning that entry pointer.
// @fnv 0x00d10ea0
// pdb: hkp3AxisSweep::hkpBpAxis::find | hkp3AxisSweep.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: start, end, value
Entry* __stdcall LowerBoundEntry(Entry* first, Entry* last, unsigned short key) {
    while ((((char*)last - (char*)first) & ~3) > 0x40) {
        Entry* middle = first + (((char*)last - (char*)first) >> 3);
        if (middle->key < key) first = middle;
        else last = middle;
    }
    while (first->key < key) ++first;
    return first;
}

struct FUN_00d11960_cls {
    int* m_pEntryData;
    int m_iArrayLength;
    void FUN_00d11960(int aiFirst, int aiSecond);
};

// @fnv 0x00d11960
// pdb: hkp3AxisSweep::hkpBpAxis::remove | hkp3AxisSweep.obj | tesv_win, objrun_prop, low
void FUN_00d11960_cls::FUN_00d11960(int aiFirst, int aiSecond)
{
    int* p = m_pEntryData + aiFirst;
    int* pEnd = m_pEntryData + aiSecond - 1;
    while (p < pEnd) {
        p[0] = p[1];
        p++;
    }
    int iCount = m_iArrayLength;
    int* pLast = m_pEntryData + (iCount - 2);
    m_iArrayLength = iCount - 2;
    while (p < pLast) {
        p[0] = p[2];
        p++;
    }
}

namespace fnv_00d1a040 {
struct Entry { unsigned short type; unsigned short index; };
void __cdecl FUN_00c908c0(void*, void*, int, int);
extern unsigned char* DAT_011b37a4[2];
}  // namespace fnv_00d1a040

struct D1A0E0Allocator;

struct D1A0E0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D1A0E0Allocator* m_pStreamAllocator;

    D1A0E0Allocator& heap() { return *m_pStreamAllocator; }
};

void __cdecl FUN_00c908c0(D1A0E0Allocator* alloc, void* array, int numElements, int sizeElem);

struct D1A0E0Entry {
    unsigned short m_flags;
    unsigned short m_uiEdgeIndex;
};

struct D1A0E0IntArray {
    int* m_data;
    int m_iElementCount;
};

struct D1A0E0EntryArray {
    D1A0E0Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void GrowArrayCapacity(D1A0E0Allocator& alloc, int n)
    {
        const int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(D1A0E0Entry));
        }
    }

    void SetSizeAndGrow(D1A0E0Allocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }

    void FUN_00d1a0e0(int offset, const D1A0E0IntArray& remap);
};

struct S_00d1a180_Allocator {
    int unk0;
};

struct S_00d1a180_ArrayUtil {
    static int __cdecl FUN_00c908c0(S_00d1a180_Allocator& alloc, void* arr, int numElem, int elemSize);
};

struct S_00d1a180_Router {
    int unk0; int unk4; int unk8; int unkC;
    S_00d1a180_Allocator* m_pStreamAllocator;

    static S_00d1a180_Router& FUN_00c85750();
    S_00d1a180_Allocator& heap() { return *m_pStreamAllocator; }
};

struct S_00d1a180_HeapAllocator {
    static S_00d1a180_Allocator& get(const void*) { return S_00d1a180_Router::FUN_00c85750().heap(); }
};

struct S_00d1a180_IntArray {
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct S_00d1a180_EndPoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
};

struct S_00d1a180_Axis {
    S_00d1a180_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void GrowArrayCapacity(S_00d1a180_Allocator& a, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            S_00d1a180_ArrayUtil::FUN_00c908c0(a, this, newSize, sizeof(S_00d1a180_EndPoint));
        }
    }

    void _setSize(S_00d1a180_Allocator& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }

    void SetSizeAndGrow(int n)
    {
        _setSize(S_00d1a180_HeapAllocator().get(this), n);
    }

    void RemapEndPoints(char* nodes, const S_00d1a180_IntArray& remap);
};

// @fnv 0x00d10af0
// pdb: staticClearBit | hkp3AxisSweep.obj | tesv_win, objrun_open, low
void __fastcall FUN_00d10af0(int index, unsigned int* apuiBits)
{
    unsigned int mask = 1u << (index & 0x1f);
    unsigned int w = index >> 5;
    apuiBits[w] &= ~mask;
}

struct FUN_00d11620_cls {
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
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int m_iA4;
    int FUN_00d11620();
};

// @fnv 0x00d11620
// pdb: hkp3AxisSweep::getNumObjects | hkp3AxisSweep.obj | tesv_win, objrun_sim, low
int FUN_00d11620_cls::FUN_00d11620()
{
    return m_iA4 - 1;
}

// Reconstructed source for FUN_00d119c0 (forwarding thunk, 24 bytes).
// Target shape:
//   mov edx, [esp+4]            ; handle (first stack arg)
//   mov eax, [edx]              ; handle->unk00 (entry index)
//   shl eax, 4                  ; * 16 (entry stride)
//   add eax, [ecx+0xA0]         ; + &this->entries
//   mov [esp+4], eax            ; forward as first stack arg
//   jmp FUN_00d11650            ; __thiscall tail call, ecx = this preserved

struct UnkHandle {
    int unk00; // entry index read at [handle]
};

struct SweepEntry { // 16-byte entry, matches shl eax,4 stride
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

// Tail-call target observed forwarding (this, handle, entry) with edx = handle kept live:
// __fastcall helper taking (self in ecx, handle in edx, entry on stack).
void __fastcall FUN_00d11650(void* self, UnkHandle* handle, SweepEntry* entry);

// Stand-in owner class for the __thiscall thunk; fnvcheck matches the name FUN_00d119c0.
struct FUN_00d119c0_owner {
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
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    SweepEntry* unkA0; // entry array base pointer at this+0xA0

    void FUN_00d119c0(UnkHandle* handle);
};

// @fnv 0x00d119c0
// pdb: hkp3AxisSweep::getAabb | hkp3AxisSweep.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: object, aabb
void FUN_00d119c0_owner::FUN_00d119c0(UnkHandle* handle) {
    FUN_00d11650(this, handle, this->unkA0 + handle->unk00);
}

struct PairEntry {
    int m_pHeadNode;
    int m_iSecondInteger;
};

struct PairArray {
    PairEntry* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);

BSAudio* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, void*, int);

void __fastcall AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);

struct FnvNode {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};

struct FnvArr {
    void* m_data;
    int m_uiItemCount;
    unsigned int m_cap;
};

struct FnvPair8 {
    unsigned int first;
    unsigned int second;
};

// @f3 0x00991a40 (community match, verified in this file)
// pdb: hkp3AxisSweep::beginOverlapCheckMarker | hkp3AxisSweep.obj | tesv_win, objrun_open, low
void __fastcall FUN_00d11c60(void* base, FnvNode* pNode, unsigned short ausValue, FnvNode* pOther, FnvArr* pPairArr)
{
    if ((pOther->m_0c & 1) == 0) {
        FnvArr* arr = pPairArr;
        if ((int)arr->m_uiItemCount == (int)(arr->m_cap & 0x3fffffff)) {
            FUN_00901f10(arr, 8);
        }
        unsigned int idx = (unsigned int)arr->m_uiItemCount;
        FnvPair8* e = (FnvPair8*)arr->m_data + idx;
        arr->m_uiItemCount = (int)(idx + 1);
        e->first = pNode->m_0c;
        e->second = pOther->m_0c;
    } else {
        FnvArr* arr = (FnvArr*)((char*)base + (pOther->m_0c & 0xfffffffe) + 4);
        if ((int)arr->m_uiItemCount == (int)(arr->m_cap & 0x3fffffff)) {
            FUN_00901f10(arr, 2);
        }
        unsigned int idx = (unsigned int)arr->m_uiItemCount;
        ((unsigned short*)arr->m_data)[idx] = ausValue;
        arr->m_uiItemCount++;
    }
}


namespace fnv_00d11d00 {
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);

BSAudio* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, void*, int);

void __fastcall AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);

struct PairEntry {
    int m_00;
    int m_04;
};

struct PairArray {
    PairEntry* m_00;
    int m_04;
    unsigned int m_08;
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

}  // namespace fnv_00d11d00

struct FUN_00d11da0_cls;

struct FUN_00d11da0_entry {
    unsigned short key;
    unsigned short value;
};

void __cdecl FUN_00c908c0(void* allocator, FUN_00d11da0_cls* self, unsigned int newCap, int elemSize);

struct FUN_00d11da0_cls {
    FUN_00d11da0_entry* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;

    void InsertPair(unsigned int a1, unsigned int a2, unsigned short a3,
                      unsigned short a4, unsigned short* outIndex2, unsigned short* outIndex);
};

// @f3 0x00991c00 (community match, verified in this file)
void __cdecl FUN_00901e90(void* arr, int newCap, int elemSize);
// pdb: hkp3AxisSweep::hkpBpAxis::insert | hkp3AxisSweep.obj | tesv_win, objrun_prop, low
void FUN_00d11da0_cls::InsertPair(unsigned int auiUnused, unsigned int auiValue, unsigned short ausKey2,
                                  unsigned short ausKey1, unsigned short* pausIndex2, unsigned short* pausIndex1)
{
    int n = m_uiItemCount + 2;
    unsigned int cap = m_capFlags & 0x3fffffffu;

    if ((int)cap < n) {
        int newCap = (int)(cap + cap);
        if (n >= newCap) {
            newCap = n;
        }
        FUN_00901e90(this, newCap, 4);
    }

    FUN_00d11da0_entry* p = m_data + (n - 3);
    m_uiItemCount = n;
    while (ausKey1 <= p->key) {
        p[2] = p[0];
        p--;
    }
    p[2].key = ausKey1;
    p[2].value = (unsigned short)auiValue;
    *pausIndex1 = (unsigned short)((p - m_data) + 2);

    FUN_00d11da0_entry* q = p;
    while (ausKey2 < q->key) {
        q[1] = q[0];
        q--;
    }
    q[1].value = (unsigned short)auiValue;
    q[1].key = ausKey2;
    *pausIndex2 = (unsigned short)((q - m_data) + 1);
    (void)auiUnused;
}


struct S_00d138a0_Heap : BSAudio {
    int unk0c;
    void* unk10;
};
struct S_00d138a0_Pair {
    int unk00;
    int unk04;
};
struct S_00d138a0_Array {
    S_00d138a0_Pair* unk00;
    int unk04;
    unsigned int unk08;
};
struct S_00d138a0_Node {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    int unk0c;
};
// @fnv 0x00d138a0
void __cdecl CollectNodePairs(int unused, S_00d138a0_Node* node, int count, S_00d138a0_Array* out)
{
    for (--count; count > 0; --count) {
        unsigned int limit = node->unk0a;
        S_00d138a0_Node* cur = node + 1;
        for (; cur->unk08 < limit; cur++) {
            if (((cur->unk04 - node->unk00) | (node->unk04 - cur->unk00)) & 0x80008000) {
            } else if (!(cur->unk0c & 1)) {
                S_00d138a0_Heap* heap = static_cast<S_00d138a0_Heap*>(FUN_00c85750());
                if (out->unk04 == (int)(out->unk08 & 0x3fffffff))
                    ResizeAudioStream(heap->unk10, out, 8);
                S_00d138a0_Pair* e = &out->unk00[out->unk04++];
                e->unk00 = node->unk0c;
                e->unk04 = cur->unk0c;
            }
        }
        node = node + 1;
    }
}

struct AllocIface {
    virtual void* unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

struct SpawnedObject {
    int unk00;
    unsigned short m_wSize;

    SpawnedObject* Init(int a, int b, int c);
};

// Allocates a 0xe0-byte SpawnedObject from the holder's allocator, sets its size, and initializes it with the three arguments.
// @fnv 0x00d182a0
SpawnedObject* FUN_00d182a0(int a, int b, int c)
{
    AllocHolder* holder = reinterpret_cast<AllocHolder*>(FUN_00c85750());
    SpawnedObject* obj = reinterpret_cast<SpawnedObject*>(holder->m_pAllocator->Alloc(0xe0));
    obj->m_wSize = 0xe0;
    return obj->Init(a, b, c);
}

// Writes the smallest of v[0], v[1], v[2] to out and returns its index (0, 1 or 2).
// @fnv 0x00d19d10
// pdb: hkp3AxisSweep::convertAabbToBroadPhaseResolution | hkp3AxisSweep.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: getMinComponent)
// pdb params: aabbIn, aabbOut
int __cdecl FUN_00d19d10(const float* afValues, float* pfMin) {
    if (afValues[0] < afValues[1]) {
        if (afValues[0] < afValues[2]) {
            *pfMin = afValues[0];
            return 0;
        }
    } else if (afValues[1] < afValues[2]) {
        *pfMin = afValues[1];
        return 1;
    }
    *pfMin = afValues[2];
    return 2;
}

extern int DAT_011b37a4[];

struct hkp3AxisSweep;

struct Endpoint {
    unsigned short value;
    unsigned short handle;
};

// Recursive quicksort partition over 4-byte records keyed by (low16, high16) lexicographically.
// @fnv 0x00d19fa0
void __cdecl FUN_00d19fa0(unsigned int* auiValues, int lo, int hi, int auiUnused)
{
    for (;;) {
        int i = lo;
        int j = hi;
        __declspec(align(16)) struct PivotSlot { unsigned int v; } pivot;
        pivot.v = auiValues[(i + j) >> 1];

        for (;;) {
            while ((unsigned short)auiValues[i] < (unsigned short)pivot.v
                || ((unsigned short)auiValues[i] == (unsigned short)pivot.v
                    && ((unsigned short*)&auiValues[i])[1] < (unsigned short)(pivot.v >> 16))) {
                ++i;
            }
            while ((unsigned short)pivot.v < (unsigned short)auiValues[j]
                || ((unsigned short)pivot.v == (unsigned short)auiValues[j]
                    && *(volatile unsigned short*)((char*)&pivot.v + 2) < ((unsigned short*)&auiValues[j])[1])) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                unsigned int a = auiValues[i];
                unsigned int b = auiValues[j];
                auiValues[j] = a;
                auiValues[i] = b;
            }
            --j;
            ++i;
            if (i > j) {
                break;
            }
        }

        if (lo < j) {
            FUN_00d19fa0(auiValues, lo, j, auiUnused);
        }
        if (i >= hi) {
            return;
        }
        lo = i;
    }
}

// Recursive quicksort partition over 4-byte records keyed by their low 16 bits.
// @fnv 0x00d1a220
// pdb: hkAlgorithm::quickSortRecursive<ValueIntPair<unsigned short>,hkAlgorithm::less<ValueIntPair<unsigned short> > > | hkp3AxisSweep.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: pArr, d, h, cmpLess
void __cdecl QuickSortByLowWord(unsigned int* auiArray, int lo, int hi, int auiUnused)
{
    for (;;) {
        int j = hi;
        int i = lo;
        unsigned int pivot = auiArray[(i + j) >> 1];

        for (;;) {
            while ((unsigned short)auiArray[i] < (unsigned short)pivot) {
                ++i;
            }
            while ((unsigned short)pivot < (unsigned short)auiArray[j]) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                __declspec(align(16)) unsigned int uiLeftValue = auiArray[i];
                unsigned int uiRightValue = auiArray[j];
                auiArray[j] = uiLeftValue;
                auiArray[i] = uiRightValue;
            }
            --j;
            ++i;
            if (i > j) {
                break;
            }
        }

        if (lo < j) {
            QuickSortByLowWord(auiArray, lo, j, auiUnused);
        }
        if (i >= hi) {
            return;
        }
        lo = i;
    }
}

// @fnv 0x00d10b10
// pdb: staticIsBitSet | hkp3AxisSweep.obj | tesv_win, objrun_open, low
static int __declspec(noinline) FUN_00d10b10(void* self, int index, unsigned int* apuiBits)
{
    unsigned int mask = 1u << (index & 31);
    return (int)(mask & apuiBits[index >> 5]);
}

int IsBitmapBitSet(void* table, int index, unsigned int* bits)
{
    return FUN_00d10b10(table, index, bits);
}

extern int DAT_011b37a4[];

class FUN_00d11120_cls {
public:
    Endpoint* m_endpoints;
    void MergeEndpoints(char* cells, int n, int m,
                      unsigned int axis, Endpoint* scratch);
};

// @f3 0x009910a0 (community match, verified in this file)
// pdb: hkp3AxisSweep::hkpBpAxis::mergeBatch | hkp3AxisSweep.obj | tesv_win, objrun_sim, low
void FUN_00d11120_cls::MergeEndpoints(char* cells, int aiCount, int aiExtraCount,
                                    unsigned int axis, Endpoint* scratch)
{
    for (int i = 0; i < aiCount; i++) {
        scratch[i] = m_endpoints[i];
    }

    Endpoint* last = scratch + 1;
    Endpoint* b = m_endpoints + aiCount;
    Endpoint* w = m_endpoints + 1;
    Endpoint* a = scratch + aiCount - 1;
    aiCount += aiExtraCount;
    Endpoint* pRightEnd = m_endpoints + aiCount;

    while (last->value < b->value) {
        last++;
        w++;
    }

    if (last < a && b < pRightEnd) {
        for (;;) {
            if (last->value < b->value) {
                *w = *last;
                unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
                *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
                last++;
                w++;
                if (last >= a) {
                    break;
                }
            } else {
                *w = *b;
                unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
                *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
                b++;
                w++;
                if (b >= pRightEnd) {
                    break;
                }
            }
        }
    }
    while (b < pRightEnd) {
        *w = *b;
        unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
        *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
        b++;
        w++;
    }
    while (last <= a) {
        *w = *last;
        unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
        *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
        last++;
        w++;
    }
}


// Adapted from an unverified prior attempt by another contributor; original author/model unknown.

struct S_d11790_Node { unsigned short m_usValue00, m_usValue02, m_usValue04, m_usValue06, m_usValue08, m_usValue0A; unsigned short unk0c, unk0e; };

typedef unsigned short S_d11790_Node::* S_d11790_Field;

template <typename T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

BSAudio* __cdecl FUN_00c85750() throw();

struct Allocator_00d182e0 {
    virtual void unk00() throw();
    virtual void unk04() throw();
    virtual void unk08() throw();
    virtual void unk0c() throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
};

struct Router_00d182e0 {
    int unk0; int unk4; int unk8; int unkc;
    Allocator_00d182e0* m_pStreamAllocator;
    static Router_00d182e0* get() throw() {
        return (Router_00d182e0*)FUN_00c85750();
    }
};

template <typename T>
struct hkArray_00d182e0 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease(Allocator_00d182e0* alloc) throw() {
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & 0x80000000)) {
            alloc->ReleaseBlock(m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

// Returns 0.
// @fnv 0x00d10ac0
// pdb: hkpTriSampledHeightFieldCollection::getFirstKey | hkpTriSampledHeightFieldCollection.obj | fnv360_1110_retail, objrun_open, low
int __cdecl FUN_00d10ac0() {
    return 0;
}

struct Allocator;

struct MemoryRouter {
    int unk00, unk04, unk08, unk0C;
    Allocator* m_pStreamAllocator;
    static MemoryRouter* GetMonitorStream() { return (MemoryRouter*)FUN_00c85750(); }
    Allocator& heap() { return *m_pStreamAllocator; }
};

template <typename T>
static void constructWithCopy(T* p, int n, const T& t) {
    for (int i = 0; i < n; i++) {
        p[i] = t;
    }
}

template <typename T>
static void construct(T* p, int n) {
    for (int i = 0; i < n; i++) {
    }
}

struct SmallArray {
    unsigned short* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;

    void _pushBack(Allocator& alloc, const unsigned short& val) {
        if (m_iElementCount == (int)(m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(&alloc, this, sizeof(unsigned short));
        }
        constructWithCopy(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }

    void AddBack(const unsigned short& val) {
        _pushBack(MemoryRouter::GetMonitorStream()->heap(), val);
    }

    int indexOf(const unsigned short& val) const {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == val)
                return i;
        }
        return -1;
    }

    void removeAt(int index) {
        m_iElementCount--;
        if (m_iElementCount != index) {
            m_data[index] = m_data[m_iElementCount];
        }
    }
};

struct BroadPhasePairArray : S_00d138a0_Array {
    S_00d138a0_Pair& _expandOne(Allocator& alloc) {
        if (unk04 == (int)(unk08 & 0x3fffffff)) {
            ResizeAudioStream(&alloc, this, sizeof(S_00d138a0_Pair));
            construct(unk00 + unk04, 1);
        }
        return unk00[unk04++];
    }

    S_00d138a0_Pair& AllocatePair() {
        return _expandOne(MemoryRouter::GetMonitorStream()->heap());
    }
};

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

void __cdecl ResizeAudioStream(void*, void*, int);

struct AllocObj {
    void** m_vtbl;
};

#include <xmmintrin.h>

void __cdecl FUN_00c908c0(void* alloc, void* self, int newCap, int elemSize);

extern "C" void _ReadWriteBarrier(void);
struct d11Out {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct d11Node {
    int unk00;
    int unk04;
    int unk08;
    int m_flags;
};
struct d11Pair {
    float minX, minY, minZ, minW;
    float maxX, maxY, maxZ, maxW;
};
struct d11Sweep {
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
    int unk98;
    int unk9c;
    d11Node* m_pNodes;
    int m_iArrayLength;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int m_iBase;

    void FUN_00d11fa0(d11Out& __restrict out);
};

// @f3 0x00991e30 (community match, verified in this file)
void __cdecl FUN_00901e90(d11Out* out, int count, int elementSize);

void d11Sweep::FUN_00d11fa0(d11Out& out)
{
    if ((out.m_iCapacityState & 0x3fffffff) < m_iArrayLength - m_iBase)
        FUN_00901e90(&out, m_iArrayLength - m_iBase, 0x20);
    out.m_iElementCount = m_iArrayLength - m_iBase;
    int iPairIndex = 0;
    for (int i = 0; i < m_iArrayLength; i++) {
        d11Node* node = &m_pNodes[i];
        if (!(node->m_flags & 1))
            ((void (__thiscall*)(d11Sweep*, d11Node*, d11Pair*))FUN_00d11650)(
                this, node, &((d11Pair*)out.m_data)[iPairIndex++]);
    }
}


struct SweepEndpoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
    SweepEndpoint() {}
    SweepEndpoint(unsigned short val, unsigned short idx) : m_uiFilterValue(val), m_usIndex(idx) {}
};

inline void* operator new(unsigned int, void* p) { return p; }

template <typename T>
inline void S00d13950_constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i) {
        new (p + i) T(t);
    }
}

template <typename T>
struct SweepArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    SweepArray(T* data, int size, int cap) {
        m_data = data;
        m_iElementCount = size;
        m_iCapacityState = cap | 0x80000000;
    }

    void pushBackUnchecked(const T& t) {
        S00d13950_constructWithCopy<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct SweepNode {
    unsigned short m_min1;
    unsigned short m_min2;
    unsigned short m_max1;
    unsigned short m_max2;
    unsigned short m_min0;
    unsigned short m_max0;
};



struct S00d13950_Less {};
void __cdecl FUN_00d19fa0(SweepEndpoint* base, int lo, int hi, S00d13950_Less cmp);

template <typename T, typename L>
inline void S00d13950_quickSort(T* pArr, int iSize, L cmpLess)
{
    if (iSize > 1) {
        FUN_00d19fa0(pArr, 0, iSize - 1, cmpLess);
    }
}

struct SweepClass {
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
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    SweepArray<SweepEndpoint> m_kAxisEndPoints[3];

    void FUN_00d13950(const SweepArray<SweepNode*>& nodes, SweepArray<SweepEndpoint>* tempAxes);
};

// Fills three SweepArray<SweepEndpoint> buffers with min/max endpoints from each SweepNode, sorts each axis, and adds sentinel endpoints.
// @fnv 0x00d13950
void SweepClass::FUN_00d13950(const SweepArray<SweepNode*>& nodes, SweepArray<SweepEndpoint>* tempAxes)
{
    SweepEndpoint* buf = (SweepEndpoint*)(tempAxes + 3);
    int cap = 2 * nodes.m_iElementCount + 2;
    new (&tempAxes[0]) SweepArray<SweepEndpoint>(buf, 0, cap);
    new (&tempAxes[1]) SweepArray<SweepEndpoint>(buf + cap, 0, cap);
    new (&tempAxes[2]) SweepArray<SweepEndpoint>(buf + cap * 2, 0, cap);

    SweepEndpoint sentinel;
    sentinel.m_uiFilterValue = 0;
    sentinel.m_usIndex = 0;
    tempAxes[0].pushBackUnchecked(sentinel);
    tempAxes[1].pushBackUnchecked(sentinel);
    tempAxes[2].pushBackUnchecked(sentinel);

    SweepNode* const* nodeIt = nodes.m_data;
    for (int i = nodes.m_iElementCount - 1; i >= 0; --i) {
        tempAxes[0].pushBackUnchecked(m_kAxisEndPoints[0].m_data[(*nodeIt)->m_min0]);
        tempAxes[0].pushBackUnchecked(m_kAxisEndPoints[0].m_data[(*nodeIt)->m_max0]);
        tempAxes[1].pushBackUnchecked(m_kAxisEndPoints[1].m_data[(*nodeIt)->m_min1]);
        tempAxes[1].pushBackUnchecked(m_kAxisEndPoints[1].m_data[(*nodeIt)->m_max1]);
        tempAxes[2].pushBackUnchecked(m_kAxisEndPoints[2].m_data[(*nodeIt)->m_min2]);
        tempAxes[2].pushBackUnchecked(m_kAxisEndPoints[2].m_data[(*nodeIt)->m_max2]);
        nodeIt++;
    }

    for (int j = 0; j < 3; ++j) {
        S00d13950_quickSort(tempAxes[j].m_data + 1, tempAxes[j].m_iElementCount - 1, S00d13950_Less());
    }

    sentinel.m_uiFilterValue = 0xfffc;
    sentinel.m_usIndex = 0;
    tempAxes[0].pushBackUnchecked(sentinel);
    tempAxes[1].pushBackUnchecked(sentinel);
    tempAxes[2].pushBackUnchecked(sentinel);
}

namespace fnv_00d13bd0 {
inline void* operator new(unsigned int, void* p) { return p; }
struct D1A0E0Allocator;
struct SweepRouter {
    int unk00, unk04, unk08, unk0c;
    D1A0E0Allocator* heap;
};
void __cdecl FUN_00c908c0(D1A0E0Allocator*, void*, int, int);
void __cdecl ResizeAudioStream(D1A0E0Allocator*, void*, int);
BSAudio* __cdecl FUN_00c85750();

struct SweepNode {
    unsigned short min0, max0, min1, max1, min2, max2;
    int link;
};
struct SweepEnd {
    unsigned short value, node;
};
template<class T> struct SweepArray {
    T* data;
    int size, capacity;
    SweepArray():data(0),size(0),capacity(0x80000000) {}

    static void reserveHeap(D1A0E0Allocator& heap, SweepArray* array, int n) {
        int cap = array->capacity & 0x3fffffff;
        if (cap < n) {
            int grown = 2*cap;
            FUN_00c908c0(&heap, array, n < grown ? grown : n, sizeof(T));
        }
    }
    T& _expandOne(D1A0E0Allocator& heap) { if(size == (capacity & 0x3fffffff)) { ResizeAudioStream(&heap,this,sizeof(T)); construct(data+size,1); } return data[size++]; }
    T& expand() { SweepRouter* router=(SweepRouter*)FUN_00c85750();return _expandOne(*router->heap); }
    void append(const SweepEnd& value) {
        new (data+size) SweepEnd(value);
        ++size;
    }
};
static const __m128 sweepBias={65536.0f,65536.0f,65536.0f,65536.0f};
extern "C" void _ReadWriteBarrier(void);
struct SweepBound { int x,y,z,w; SweepBound(const int* p):x(p[0]),y(p[1]),z(p[2]),w(p[3]) {} };
}  // namespace fnv_00d13bd0

struct hkMemoryAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();

    template <typename T>
    __forceinline T* _bufAlloc(int& num) throw() {
        int numBytes = num * (int)sizeof(T);
        void* p = AllocateBufferWithSize(numBytes);
        num = numBytes / (int)sizeof(T);
        return (T*)p;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750() throw();

struct NineIntegerRecord {
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocator* m_aiEntries;

    static NineIntegerRecord* GetMonitorStream() throw() {
        return (NineIntegerRecord*)FUN_00c85750();
    }
};

template <typename T>
struct HkDynamicArray {
    T* m_data;
    int m_iCapacityState;

    __forceinline HkDynamicArray(int n) throw() {
        allocate(*NineIntegerRecord::GetMonitorStream()->m_aiEntries, n);
    }
    __forceinline void allocate(hkMemoryAllocator& alloc, int n) throw() {
        int num = n;
        m_data = num ? alloc._bufAlloc<T>(num) : 0;
        m_iCapacityState = num ? num : (int)0x80000000;
    }

    __forceinline ~HkDynamicArray() throw() {
        release(*NineIntegerRecord::GetMonitorStream()->m_aiEntries);
    }
    __forceinline void release(hkMemoryAllocator& alloc) throw() {
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * (int)sizeof(T));
        }
    }

    __forceinline T& operator[](int i) { return m_data[i]; }
};

struct Elem {
    unsigned short m_usValue00;
    unsigned short m_usValue02;
    unsigned short m_usValue04;
    unsigned short m_usValue06;
    unsigned short m_usValue08;
    unsigned short m_usValue0A;
    int* h;
    __forceinline int isMarker() const throw() { return (unsigned)h & 1; }
    __forceinline struct Sub* getMarker(struct Sub* base) const throw() { return (struct Sub*)((char*)base + ((unsigned)h & ~1)); }
};

template <typename T>
struct S00d15fc0_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i) throw() { return m_data[i]; }
    __forceinline int GetLogicalSize() const throw() { return m_iElementCount; }
};

struct Sub {
    unsigned short x;
    unsigned short x2;
    unsigned short* idx;
    int n;
    int y;
};

struct AxisPair {
    unsigned short* p;
    int n;
    int cap;
};

struct KeyPair {
    unsigned short val;
    unsigned short idx;
};
struct KeyLess { bool operator()(const KeyPair& a, const KeyPair& b) const { return a.val < b.val; } };
void __cdecl QuickSortByLowWord(void*, int, int, KeyLess) throw();

struct Sweep {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    S00d15fc0_Array<Elem> m_kNodeCollection;
    AxisPair m_ac[3];
    int m_d0;
    int m_d4;
    Sub* m_d8;

    void FUN_00d15fc0();
    void FixNodeEdges(int) throw();
    __forceinline void setNodeIndex(Elem& node, int i) throw() {
        int* const& h = node.h;
        if (((unsigned)h & 1) == 0) {
            *h = i;
        } else {
            *(unsigned short*)((char*)m_d8 + ((unsigned)h & ~1)) = (unsigned short)i;
        }
    }
};

__declspec(align(16)) struct FUN_00d1a2a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
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
    __m128 m_v70;
    __m128 m_v80;

    void GetValues(__m128* out0, __m128* out1);
};

struct S_00d1a2d0_Allocator {
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
};

struct S_00d1a2d0_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d1a2d0_Allocator* unk10;
    static S_00d1a2d0_Router& FUN_00c85750();
    S_00d1a2d0_Allocator& heap() { return *unk10; }
};

struct S_00d1a2d0_Base {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual void v0();
    static void operator delete(void* p)
    {
        S_00d1a2d0_Base* b = static_cast<S_00d1a2d0_Base*>(p);
        S_00d1a2d0_Router::FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

#include <xmmintrin.h>
namespace fnv_00d11650 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_sub_ps(__m128, __m128);

typedef float hkReal;
typedef unsigned short hkUint16;

struct hkVector4q {
    __m128 m_vComponents;

    __forceinline hkReal operator()(int i) const { return m_vComponents.m128_f32[i]; }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& v) { m_vComponents = _mm_sub_ps(a.m_vComponents, v.m_vComponents); }
    __forceinline void operator=(const hkVector4q& v) { m_vComponents = v.m_vComponents; }
    __forceinline void sub4(const hkVector4q& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
};

struct hkAabbq {
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct BpNode {
    hkUint16 m_usValue00;
    hkUint16 m_usValue02;
    hkUint16 m_usValue04;
    hkUint16 m_usValue06;
    hkUint16 m_usValue08;
    hkUint16 m_usValue0A;
};

struct BpEndPoint {
    hkUint16 m_uiFilterValue;
    hkUint16 m_usIndex;
};

struct BpAxis {
    BpEndPoint* m_pEndPoints;
    int m_iElementCount;
    int m_iCapacityState;
};

struct AxisSweep3 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    hkVector4q m_kVectorAt40;
    hkVector4q m_kVectorAt50;
    hkVector4q m_vScale;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    BpAxis m_kNodeCollection;
    BpAxis m_kAxisEndPoints[3];

    void FUN_00d11650(const BpNode& node, hkAabbq& aabb) const;
};

// Computes the axis-aligned bounding box of a BpNode in local space by scaling its endpoint coordinates and storing the result in aabb.
// @fnv 0x00d11650
void AxisSweep3::FUN_00d11650(const BpNode& node, hkAabbq& aabb) const
{
    hkReal fInvScaleX = 1.0f / m_vScale(0);
    hkReal fInvScaleY = 1.0f / m_vScale(1);
    hkReal fInvScaleZ = 1.0f / m_vScale(2);


    hkVector4q mn; mn.set(fInvScaleX * m_kAxisEndPoints[0].m_pEndPoints[node.m_usValue08].m_uiFilterValue, fInvScaleY * m_kAxisEndPoints[1].m_pEndPoints[node.m_usValue00].m_uiFilterValue, fInvScaleZ * m_kAxisEndPoints[2].m_pEndPoints[node.m_usValue02].m_uiFilterValue, 0.0f);
    float hx = m_kAxisEndPoints[0].m_pEndPoints[node.m_usValue0A].m_uiFilterValue;
float hy = m_kAxisEndPoints[1].m_pEndPoints[node.m_usValue04].m_uiFilterValue;
float hz = m_kAxisEndPoints[2].m_pEndPoints[node.m_usValue06].m_uiFilterValue;
hkVector4q mx; mx.set(fInvScaleX*hx,fInvScaleY*hy,fInvScaleZ*hz,0.0f);
    mn.sub4(m_kVectorAt40);
    mx.sub4(m_kVectorAt40);
    aabb.m_kMinimumCorner = mn;
    aabb.m_kMaximumCorner = mx;
}
}  // namespace fnv_00d11650

extern "C" void _ReadWriteBarrier();
// Havok axis sweep. Based on community near miss nm_5cdcf740ad53441b93a7.
//
// The sweep shape keeps a block of 32 sixteen byte records; every block owns
// a bit mask that marks the records which still overlap the reference record
// of the current sweep.  The overlapping ones are appended to the event list
// of the caller.

struct AudioSink {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* fn0c(int* size);
    virtual void fn10(void* data, int size);
    __forceinline void allocateBlocks(int blocks, void*& buffer, int& masks) {
        if (blocks) {
            int size = blocks * 4;
            void* result = fn0c(&size);
            int actualMasks = size / 4;
            buffer = result;
            // Preserve the buffer store before publishing its allocation flags.
            _ReadWriteBarrier();
            masks = actualMasks;
            return;
        }
        buffer = 0;
    }

};

struct AudioGlobal {
    void* unk00;
    int unk04;
    int unk08;
    AudioSink* sink;
    void* listOwner;
    AudioSink& temp() { return *sink; }
};

struct EventList {
    void* data;
    int count;
    int capacity;
};

struct SweepEvent {
    int* index;
    int value;
};

struct SweepRecord {
    int f00;
    int f04;
    unsigned short f08;
    unsigned short f0a;
    int f0c;
};

struct SweepType {
    unsigned short value;
    unsigned short unk02;
};

struct AxisSweep {
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
    int unk98;
    int unk9c;
    SweepRecord* records;
    int numRecords;
    int unkA8;
    SweepType* types;
    void FUN_00d112c0(int numRecords, unsigned short code, SweepRecord* rec, int index, void* buffer);
    void FUN_00d14100(int* index, EventList* events);
};

// Iterates sweep records matching a bitmask, appending those whose f0c value is even to the events list, growing it when full.
// @f3 0x00991ca0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern void __cdecl FUN_00901f10(EventList*, int);
struct SweepHelper {
    void FUN_00991290(int numRecords, unsigned short code, SweepRecord* rec, int index, void* buffer);
};
struct SweepThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* OnStackOverflow(unsigned int);
    virtual void OnStackUnderflow(void*);
    int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    char* current;
    int unk24;
    char* base;
    char* end;
    char* Alloc(int bytes)
    {
        char* r;
        char* cur=current;
        if(cur + bytes <= end)
        {
            current = cur + bytes;
            r = cur;
        }
        else
            r = (char*)OnStackOverflow(bytes);
        return r;
    }
    void Free(char* p)
    {
        current=p;
        if (p == base)
            OnStackUnderflow(p);
    }
};
// pdb: hkp3AxisSweep::reQuerySingleObject | hkp3AxisSweep.obj | tesv_win, objrun_prop, low
void AxisSweep::FUN_00d14100(int* index, EventList* events)
{
    
    int count = numRecords;
    SweepThreadMemory* memory=(SweepThreadMemory*)DAT_00d9b080(DAT_010f3170);
    int bytes = (((count >> 5) * 4 + 0x30) & ~15);
    char* scratch=memory->Alloc(bytes);

    unsigned int* words=(unsigned int*)scratch;
    unsigned int* p=words;
    SweepRecord* target = records + *index;
    unsigned short code = types[target->f08].value;
    ((SweepHelper*)this)->FUN_00991290(count, code, target, *index, scratch);
    SweepRecord* candidates=records;
    unsigned int* end=words+(numRecords >> 5)+1;
    unsigned int bits;
    EventList* list=events;
    for(;p<end;candidates+=32,p++)
    {
        SweepRecord* other=candidates;
        bits=*p;
        while(bits)
        {
            if (!(bits & 0xff))
            {
                other+=8;
                bits >>=8;
                continue;
            }
            if (bits & 1)
            {
                if(!(((target->f04 - other->f00) | (other->f04 - target->f00)) & 0x80008000))
                {
                    int flags=other->f0c;
                    if(!(flags & 1))
                    {
                        if (list->count == (list->capacity & 0x3fffffff))
                            FUN_00901f10(list,8);
                        SweepEvent* arr=(SweepEvent*)list->data;
                        int n=list->count;
                        arr[n].index=index;
                        arr[n].value=flags;
                        ++list->count;
                    }
                }
            }
            ++other;
            bits >>= 1;
        }
    }
    SweepThreadMemory* endMemory=(SweepThreadMemory*)DAT_00d9b080(DAT_010f3170);
    endMemory->Free(scratch);
}


extern "C" void _ReadWriteBarrier();
struct SweepNodeX {
 unsigned int minimum;
 unsigned int maximum;
 unsigned short lowZ, highZ;
 unsigned int handle;
};
struct SweepGroupX {
 unsigned short node, flags;
 unsigned short* data;
 int size;
 int capacity;
 int find(const unsigned short& value,int start=0,int end=-1) const {
  if(end<0) end=size;
  for(int i=start;i<end;++i) if(data[i]==value) return i;
  return -1;
 }
 void remove(unsigned short value) {
  int i=find(value); removeAt(i);
 }
 void removeAt(int i) { --*(volatile int*)&size;
  if(size!=i) data[i]=data[size];
 }
};
struct SweepAllocatorX {
 virtual void f0(); virtual void f4(); virtual void f8();
 virtual void* allocate(int& bytes);
 virtual void release(void*, int bytes);
};
struct SweepRouterX {
 int u0,u4,u8;
 SweepAllocatorX* stack;
 D1A0E0Allocator* heap;
 static SweepRouterX* __cdecl router();
 D1A0E0Allocator& getHeap() { return *heap; }
 SweepAllocatorX& getStack() { return *stack; }
};
struct SweepPairX {
 unsigned int* first; unsigned int second;
 SweepPairX(unsigned int* a,unsigned int b) : first(a),second(b) {}
};
struct SweepPairsX {
 SweepPairX* data; int size; unsigned int capacity;
 void push(unsigned int* a,unsigned int b) {
  SweepRouterX* r=SweepRouterX::router();
  if(size==(capacity&0x3fffffff)) ResizeAudioStream(r->heap,this,8);
  new(data+size) SweepPairX(a,b);
  ++size;
 }
};
struct SweepNodesX {
 SweepNodeX* data; int size; int capacity;
 void SetSizeAndGrow(int n) {
  D1A0E0Allocator& a=SweepRouterX::router()->getHeap();
  int cap=capacity&0x3fffffff;
  if(cap<n) { int twice=cap*2; FUN_00c908c0(&a,this,n<twice?twice:n,16); }
  size=n;
 }
};

struct CacheNode { unsigned short minY,minZ,maxY,maxZ,minX,maxX; unsigned int handle; };
struct Alloc {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(unsigned int* p, unsigned int size);
};

struct Item {
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    volatile unsigned int m_14;
};

struct ItemList {
    Item** m_items;
    int m_uiItemCount;
};

struct Blk {
    unsigned int a; // data pointer
    unsigned int b; // element count
    unsigned int c; // capacity and ownership flags
    unsigned int d; // original local allocation
};

struct CacheOwner {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74;
    unsigned int unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int m_a0;

    int unkA4, unkA8;
    SweepArray<SweepEndpoint> axis[3];
    __declspec(noinline) void FUN_00d13950(Blk* array, unsigned int a2);
    void FUN_00d15f10(ItemList* a1, unsigned int a2);
};

// Fills a pool array with (item->m_14 << 4) + m_a0 per item, calls FUN_00d13950 with it and a2, then restores the pool pointer and frees the array.
// @f3 0x009982c0 (community match, verified in this file)
// hkp3AxisSweep::calcAabbCache(const hkArray<hkpCollidable*>&, hkpBroadPhaseAabbCache*) const: collect the sweep
// nodes of the given collidables into a stack-allocated local array and build the cache from them.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

namespace f3m_009982c0
{
    class ThreadMemory
    {
    public:
        virtual void* alignedAllocate(int alignment, int nbytes, int cl);
        virtual void alignedDeallocate(void* p);
        virtual void setStackArea(void* buf, int nbytes);
        virtual void releaseCachedMemory();
        virtual ~ThreadMemory();
        virtual void* onStackOverflow(int nbytes);
        virtual void onStackUnderflow(void* p);

        static ThreadMemory& getInstance() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }
        void* allocateStack(int nbytesin)
        {
            int actualBytes = (nbytesin + 16) & ~15;
            char* p = m_current;
            char* end = p + actualBytes;
            if (end <= m_end)
            {
                m_current = end;
                return p;
            }
            else
            {
                return onStackOverflow(actualBytes);
            }
        }
        void deallocateStack(void* p)
        {
            m_current = static_cast<char*>(p);
            if (p == m_base)
            {
                onStackUnderflow(p);
            }
        }
        void FUN_008f6d90(void* p, int nbytes, int cl);   // deallocateChunk

        int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
        char* m_current;
        char* m_24;
        char* m_base;
        char* m_end;
    };

    template <typename T> __forceinline T* allocateStack(int n)
    {
        ThreadMemory& mem = ThreadMemory::getInstance();
        return static_cast<T*>(mem.allocateStack(n * sizeof(T)));
    }
    template <typename T> __forceinline void deallocateStack(T* p)
    {
        ThreadMemory::getInstance().deallocateStack(static_cast<void*>(p));
    }

    template <typename T> class Array
    {
    public:
        enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
        __forceinline Array() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
        __forceinline ~Array() { releaseMemory(); }
        int getSize() const { return m_size; }
        int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }
        T& operator[](int i) { return m_data[i]; }
        const T& operator[](int i) const { return m_data[i]; }
        __forceinline void pushBackUnchecked(const T& t) { m_data[m_size++] = t; }
        __forceinline void releaseMemory()
        {
            if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
            {
                ThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
            }
        }
        T* m_data;
        int m_size;
        int m_capacityAndFlags;
    };

    template <typename T> class LocalArray : public Array<T>
    {
    public:
        __forceinline LocalArray(int capacity)
        {
            this->m_data = allocateStack<T>(capacity);
            this->m_capacityAndFlags = capacity | Array<T>::DONT_DEALLOCATE_FLAG;
            m_localMemory = this->m_data;
        }
        __forceinline ~LocalArray() { deallocateStack<T>(m_localMemory); }
        T* m_localMemory;
    };

    struct BroadPhaseHandle
    {
        unsigned int m_id;
    };
    struct Collidable
    {
        const void* m_shape;
        unsigned int m_shapeKey;
        const void* m_motion;
        const Collidable* m_parent;
        signed char m_ownerOffset;
        BroadPhaseHandle m_broadPhaseHandle;
        const BroadPhaseHandle* getBroadPhaseHandle() const { return &m_broadPhaseHandle; }
    };
    struct BpNode
    {
        unsigned short min_y, min_z, max_y, max_z, min_x, max_x;
        unsigned int m_handle;
    };
}

void CacheOwner::FUN_00d15f10(ItemList* a1, unsigned int a2)
{
    using namespace f3m_009982c0;
    const Array<const Collidable*>& overlappingCollidables = *reinterpret_cast<const Array<const Collidable*>*>(a1);

    LocalArray<const BpNode*> overlaps(overlappingCollidables.getSize());
    for (int i = 0; i < overlappingCollidables.getSize(); i++)
    {
        overlaps.pushBackUnchecked(&reinterpret_cast<const BpNode*>(m_a0)[overlappingCollidables[i]->getBroadPhaseHandle()->m_id]);
    }
    FUN_00d13950(reinterpret_cast<Blk*>(&overlaps), a2);
}

void CacheOwner::FUN_00d13950(Blk* input, unsigned int out) {
    int n=(input->b+1)*2;
    SweepArray<SweepEndpoint>* cache=(SweepArray<SweepEndpoint>*)out;
    SweepEndpoint* storage=(SweepEndpoint*)(cache+3);
    new(cache) SweepArray<SweepEndpoint>(storage,0,n);
    new(cache+1) SweepArray<SweepEndpoint>(storage+n,0,n);
    new(cache+2) SweepArray<SweepEndpoint>(storage+n*2,0,n);
    SweepEndpoint sentry(0,0);
    cache[0].pushBackUnchecked(sentry);
    cache[1].pushBackUnchecked(sentry);
    cache[2].pushBackUnchecked(sentry);
    CacheNode* const* node=(CacheNode* const*)input->a;
    for(int i=input->b-1;i>=0;--i,++node) {
        cache[0].pushBackUnchecked(axis[0].m_data[(*node)->minX]);
        cache[0].pushBackUnchecked(axis[0].m_data[(*node)->maxX]);
        cache[1].pushBackUnchecked(axis[1].m_data[(*node)->minY]);
        cache[1].pushBackUnchecked(axis[1].m_data[(*node)->maxY]);
        cache[2].pushBackUnchecked(axis[2].m_data[(*node)->minZ]);
        cache[2].pushBackUnchecked(axis[2].m_data[(*node)->maxZ]);
    }
    for(int j=0;j<3;++j) {
        int count=cache[j].m_iElementCount-1;
        if(count>1) FUN_00d19fa0(cache[j].m_data+1,0,count-1,S00d13950_Less());
    }
    sentry.m_uiFilterValue=0xfffc;
    cache[0].pushBackUnchecked(sentry);
    cache[1].pushBackUnchecked(sentry);
    cache[2].pushBackUnchecked(sentry);
}

#include <xmmintrin.h>
namespace fnv_00d142b0 {
#include <xmmintrin.h>

struct AllocObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* alloc(int* size);
    virtual void freeFn(void* p, int size);
};

struct Node16 {
    union { unsigned int f0; struct { unsigned short minY, minZ; }; };
    union { unsigned int f4; struct { unsigned short maxY, maxZ; }; };
    union { unsigned int f8; struct { unsigned short minX, maxX; }; };
    int* fC;
};
struct NodesArr {
    Node16* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};
struct Pair8 { int first; int second; };
struct PairArr {
    Pair8* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};
struct Input {
    unsigned int v0; unsigned int v4; unsigned int v8; unsigned int vC;
    unsigned int v10; unsigned int v14; unsigned int v18; unsigned int v1C;
};
struct Sweep {
    int u00; int u04; int u08; int u0C; int u10; int u14; int u18; int u1C;
    int u20; int u24; int u28; int u2C; int u30; int u34; int u38; int u3C;
    int u40; int u44; int u48; int u4C; int u50; int u54; int u58; int u5C;
    int u60; int u64; int u68; int u6C; int u70; int u74; int u78; int u7C;
    int u80; int u84; int u88; int u8C; int u90; int u94; int u98; int u9C;
    NodesArr m_kNodeCollection;
    FUN_00d11da0_cls m_axis0;
    FUN_00d11da0_cls m_axis1;
    FUN_00d11da0_cls m_axis2;
    int uD0; int uD4;
    char* m_markerBase;
    __declspec(noinline) void FUN_00d10b30(Node16* buf, int index, Node16* node);
    void FUN_00d112c0(int a1, unsigned int a2, Node16* node, int a4, void* buf);
    void FUN_00d142b0(int* handle, Input* input, PairArr* outPairs);
};


struct __declspec(align(16)) BoundVector {
    unsigned int x,y,z,w;
};
}  // namespace fnv_00d142b0

#include <xmmintrin.h>
namespace fnv_00d175f0 {
#include <xmmintrin.h>

extern "C" void _ReadWriteBarrier(void);
struct SweepEnd { unsigned short value, handle; };
struct SweepNode {
    unsigned short minY, minZ, maxY, maxZ, minX, maxX;
    unsigned* handle;
};
struct SweepList { void* data; int size; int capacity;
    SweepList():data(0),size(0),capacity(0x80000000) {}
    void clear() throw() {
        Router_00d182e0* router=(Router_00d182e0*)FUN_00c85750();
        Allocator_00d182e0* heap=router->m_pStreamAllocator;
        int cap=capacity;
        size=0;
        if (!(cap & 0x80000000)) heap->ReleaseBlock(data,(cap&0x3fffffff)*8);
        data=0;capacity=0x80000000;
    }

};
void __fastcall FUN_00d11c60(void*, SweepNode*, unsigned, SweepNode*, void*);
void __fastcall AppendPairToBuffer(SweepNode*, SweepNode*, void*);
struct __declspec(align(16)) SweepVector { float x,y,z,w; };
struct __declspec(align(16)) SweepBounds { unsigned low[4], high[4]; };

}  // namespace fnv_00d175f0

template<class T> struct Arr;
struct IAlloc {
template<class T> __forceinline T* BufferAlloc(int& n) {
    int bytes = n * (int)sizeof(T);
    void* p = Alloc(bytes);
    n = bytes / (int)sizeof(T);
    return (T*)p;
}
template<class T> __forceinline T* AllocateBuffer(int& n, unsigned& capacity) {
    T* p = n ? BufferAlloc<T>(n) : 0;
    capacity = n ? n : 0x80000000;
    return p;
}
template<class T> __forceinline void FreeBuffer(T* data, unsigned capacity) {
    if ((capacity & 0x80000000) == 0) this->Free(data, (capacity & 0x3fffffff) * sizeof(T));
}
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void* Alloc(int& size) = 0;
    virtual void Free(void* p, unsigned size) = 0;
};
struct Heap {
    int unk00, unk04, unk08;
    IAlloc* temp;
    IAlloc* main;
    template<class T> void ReleaseTemp(Arr<T>& arr);
};
static Heap* GetHeap() { return (Heap*)FUN_00c85750(); }
void __cdecl FUN_00c908c0(IAlloc* a, void* arr, int cap, int esz);
void __cdecl FUN_00d9fcf0(void* a, int n, void* scratch);
template<class T> struct Arr {
    T* data;
    int size;
    unsigned cap;
    __forceinline void SetSize(int n) {
        SetSize(*GetHeap()->main, n);
    }
    __forceinline void SetSize(IAlloc& a, int n) {
        int c = cap & 0x3fffffff;
        if (c < n) {
            int nc = c * 2;
            if (n >= nc) nc = n;
            FUN_00c908c0(&a, this, nc, sizeof(T));
        }
        size = n;
    }
};
template<class T> static __forceinline T* AllocateBuffer(int& n, unsigned& capacity) {
    return GetHeap()->temp->AllocateBuffer<T>(n, capacity);
}
template<class T> static __forceinline void FreeBuffer(T* data, unsigned capacity) {
    GetHeap()->temp->FreeBuffer<T>(data, capacity);
}
struct RawBox { unsigned lower, upper, axis; int* handle; };
struct Box {
    union { struct { unsigned short lo0, lo1; }; unsigned lo01; };
    union { struct { unsigned short hi0, hi1; }; unsigned hi01; };
    union { struct { unsigned short loZ, hiZ; }; unsigned zPair; };
    int* ref;
    void CopyPacked(const Box& b) { *(RawBox*)this = *(const RawBox*)&b; }
    Box& operator=(const Box& b) { CopyPacked(b); return *this; }
};
struct Key { unsigned short key, idx; };
struct RemovedHandle { int idx; };
struct RemovedHandleList { RemovedHandle** items; int count; };
struct Node { unsigned short idx, pad; Arr<unsigned short> arr; };
struct Stub_00d1a040 { int a, b, c; void FUN_00d1a040(Box*, Arr<int>*); };
struct Stub_00d1a0e0 { int a, b, c; void FUN_00d1a0e0(Box*, Arr<int>*); };
struct Stub_00d1a180 { int a, b, c; void RemapEndPoints(Box*, Arr<int>*); };
void __cdecl CollectNodePairs(void*, Box*, int, int);
struct AssignedSweep {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    Arr<Box> boxes;
    Stub_00d1a040 s_ac;
    Stub_00d1a0e0 s_b8;
    Stub_00d1a180 s_c4;
    int nodeCount;
    int unkD4;
    Node* nodes;
    void BuildBroadPhasePairs(Box*, int, Box*, int, int, int);
    void FixNodeEdges(int);
    void FUN_00d193e0(RemovedHandleList*, int);
};
// Removes the listed boxes by moving the last boxes into their slots, calls CollectNodePairs and BuildBroadPhasePairs, and remaps node index arrays.
// @fnv 0x00d193e0
void AssignedSweep::FUN_00d193e0(RemovedHandleList* apRemoved, int arg2)
{
    int count = apRemoved->count;
    int total = boxes.size;
    Box* current=0;
    Box* data=0;
    int marker = 0;
    unsigned capA; int sizeA = count + 1;
    Box* pSortedBoxes = AllocateBuffer<Box>(sizeA, capA);
    __declspec(align(16)) Box L = boxes.data[apRemoved->items[0]->idx];
    {
        unsigned capB; int sizeB = count + 4;
    Key* pSortKeys; IAlloc* allocatorB=GetHeap()->temp;
        if (sizeB) { int request=sizeB*4;
            pSortKeys=(Key*)allocatorB->Alloc(request);
            sizeB=request/4;
        } else { pSortKeys=0; }
        capB=sizeB?sizeB:0x80000000;
        
        for (int i = 0; i < count; ++i) {
            int idx = apRemoved->items[i]->idx;
            Box& b = boxes.data[idx];
            pSortKeys[i].idx = idx;
            pSortKeys[i].key = b.loZ;
            unsigned short loZ = b.loZ; if (L.loZ >= loZ) L.loZ = loZ;
            if (L.lo0 >= b.lo0) L.lo0 = b.lo0;
            if (L.lo1 >= b.lo1) L.lo1 = b.lo1;
            if (L.hiZ <= b.hiZ) L.hiZ = b.hiZ;
            if (L.hi0 <= b.hi0) L.hi0 = b.hi0;
            if (L.hi1 <= b.hi1) L.hi1 = b.hi1;
        }
        unsigned capC; int sizeC = count + 4;
    Key* pScratch = AllocateBuffer<Key>(sizeC, capC);
        pSortKeys[count].key = 0xffff;
        pSortKeys[count + 1].key = 0xffff;
        pSortKeys[count + 2].key = 0xffff;
        FUN_00d9fcf0(pSortKeys, (count + 3) & ~3, pScratch);
        for (int i = 0; i < count; ++i) {
            Box& b = boxes.data[pSortKeys[i].idx];
            pSortedBoxes[i].CopyPacked(b);
            *b.ref = 0;
            b.ref = &marker;
        }
        pSortedBoxes[count].loZ = 0xffff;
        FreeBuffer(pScratch, capC);
        FreeBuffer(pSortKeys, capB);
    }
    Arr<int> D;
    D.data = 0; D.size = 0; D.cap = 0x80000000;
    int reserve = nodeCount + count;
    Heap* heap = GetHeap();
    if ((int)(D.cap & 0x3fffffff) < reserve)
        FUN_00c908c0(heap->temp, &D, reserve, 4);
    unsigned capE; int sizeE = total;
    Arr<int> view;
    view.data = AllocateBuffer<int>(sizeE, capE);
    int* E = view.data;
    view.size = sizeE; view.cap = capE;
    int iOverlapCount = 0;
    unsigned capG; int sizeG = total - count + 4;
    Key* pOverlapKeys = AllocateBuffer<Key>(sizeG, capG);
    int last = total - 1;
    E[0] = 0;
    for (int i = 1; i <= last; ++i) {
        data = &boxes.data[0];
        current=data+i;
        if (data[last].ref == &marker) {
            E[last] = -1;
            --last;
            --i;
            continue;
        }
        if (current->ref == &marker) {
            current->CopyPacked(data[last]);
            E[last]=i; E[i]=-1; --last; constructWithCopy(D.data + D.size, 1, i);
            ++D.size;
            int* r = current->ref;
            if (!((unsigned)r & 1)) {
                *r = i;
            } else {
                *(unsigned short*)((char*)nodes + ((unsigned)r & ~1u)) = (unsigned short)i;
                continue;
            }
        } else {
            E[i] = i;
        }
        Box& b=*current;
        if (0 == (((b.hi01 - L.lo01) | (L.hi01 - b.lo01)) & 0x80008000)) {
            unsigned short lo = b.loZ;
            unsigned short t = b.hi0 - L.lo0;
            t |= b.hiZ - L.loZ;
            t |= L.hi0 - b.lo0;
            t |= L.hiZ - lo;
            if ((t & 0x8000) == 0) {
                pOverlapKeys[iOverlapCount].key = lo;
                pOverlapKeys[iOverlapCount].idx = i;
                ++iOverlapCount;
            }
        }
    }
    boxes.SetSize(last + 1);
    unsigned capret; int sizeret = iOverlapCount + 1;
    Box* pOverlapBoxes = AllocateBuffer<Box>(sizeret, capret);
    {
        unsigned capI; int sizeI = iOverlapCount + 4;
    Key* pOverlapScratch = AllocateBuffer<Key>(sizeI, capI);
        pOverlapKeys[iOverlapCount].key = 0xffff;
        pOverlapKeys[iOverlapCount + 1].key = 0xffff;
        pOverlapKeys[iOverlapCount + 2].key = 0xffff;
        FUN_00d9fcf0(pOverlapKeys, (iOverlapCount + 3) & ~3, pOverlapScratch);
        for (int j = 0; j < iOverlapCount; ++j)
            { Box& b=boxes.data[pOverlapKeys[j].idx];
            pOverlapBoxes[j].CopyPacked(b); }
        pOverlapBoxes[iOverlapCount].loZ = 0xffff;
        FreeBuffer(pOverlapScratch, capI);
    }
    CollectNodePairs(this, pSortedBoxes, count, arg2);
    BuildBroadPhasePairs(pSortedBoxes, count, pOverlapBoxes, iOverlapCount, 1, arg2);
    s_ac.FUN_00d1a040(boxes.data, &view);
    s_b8.FUN_00d1a0e0(boxes.data, &view);
    s_c4.RemapEndPoints(boxes.data, &view);
    if (nodeCount) {
        int twoN = count + count;
        for (int k = 0; k < nodeCount; ++k) {
            Node* nd = &nodes[k];
            Box& b = boxes.data[nd->idx];
            b.hi0 -= twoN;
            b.hi1 -= twoN;
            int cnt = 0;
            for (int j = 0; j < nd->arr.size; ++j) {
                int v = E[nd->arr.data[j]];
                if (v >= 0) nd->arr.data[cnt++] = v;
            }
            nd->arr.SetSize(cnt);
        }
    }
    for (int i = 0; i < D.size; ++i) FixNodeEdges(D.data[i]);
    FreeBuffer(pOverlapBoxes, capret);
    FreeBuffer(pOverlapKeys, capG);
    FreeBuffer(E, capE);
    GetHeap()->ReleaseTemp(D);
    FreeBuffer(pSortedBoxes, capA);
}
