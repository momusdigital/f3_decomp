#include "f3_common.h"
// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct hkp3AxisSweep {
    int FUN_00d11630();
};
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);
struct BSAudio { void* p; int a; int b; };
BSAudio* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, void*, int);
struct UnkRet { int x; int y; };
void __fastcall AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);
struct Entry {
    unsigned short key;
    unsigned short value;
};
Entry* __stdcall LowerBoundEntry(Entry* first, Entry* last, unsigned short key);
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
// Reconstructed source for FUN_00d119c0 (forwarding thunk, 24 bytes).
// Target shape:
//   mov edx, [esp+4]            ; handle (first stack arg)
//   mov eax, [edx]              ; handle->unk00 (entry index)
//   shl eax, 4                  ; * 16 (entry stride)
//   add eax, [ecx+0xA0]         ; + &this->entries
//   mov [esp+4], eax            ; forward as first stack arg
//   jmp FUN_00d11650            ; __thiscall tail call, ecx = this preserved
// Tail-call target observed forwarding (this, handle, entry) with edx = handle kept live:
// __fastcall helper taking (self in ecx, handle in edx, entry on stack).
// Stand-in owner class for the __thiscall thunk; fnvcheck matches the name FUN_00d119c0.
struct PairEntry {
    int m_pHeadNode;
    int m_iSecondInteger;
};
struct PairArray {
    PairEntry* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};
struct FUN_00d11c10_cls {
    int unk00;
    int unk04;
    int unk08;
    int m_0C;
};
void __fastcall AppendPairEntry(FUN_00d11c10_cls* self, FUN_00d11c10_cls* other, PairArray* arr);
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
void __fastcall FUN_00d11c60(void* base, FnvNode* p, unsigned short a1, FnvNode* q, FnvArr* a3);
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
void __cdecl CollectNodePairs(int unused, S_00d138a0_Node* node, int count, S_00d138a0_Array* out);
extern int DAT_011b37a4[];
struct hkp3AxisSweep;
struct Endpoint {
    unsigned short value;
    unsigned short handle;
};
void __cdecl FUN_00d19fa0(unsigned int* base, int lo, int hi, int unkArg);
extern int DAT_011b37a4[];
// Adapted from an unverified prior attempt by another contributor; original author/model unknown.
struct S_d11790_Node { unsigned short m_usValue00, m_usValue02, m_usValue04, m_usValue06, m_usValue08, m_usValue0A; unsigned short unk0c, unk0e; };
struct S_d11790_Edge { unsigned short value; unsigned short handle; };
typedef unsigned short S_d11790_Node::* S_d11790_Field;
static __forceinline void S_d11790_Fix(S_d11790_Node* nodes, S_d11790_Edge* edges, S_d11790_Node* node, S_d11790_Field field, unsigned h)
{
    unsigned i = node->*field;
    S_d11790_Edge* e = edges + i;
    while (e[0].value == e[-1].value) {
        unsigned p = e[-1].handle;
        if (!(h < p)) break;
        e[0] = e[-1];
        --e;
        nodes[p].*field = i;
        --i;
    }
    e->handle = h;
    unsigned short* currentField = &(node->*field);

    *currentField = i;
}
extern "C" int __cdecl FUN_00d06f80(const void* ptr, int size);
struct hkStatisticsCollector {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void AddMemoryChunk(int type, const char* name, const void* ptr, int size, int allocatedSize);

    int pad04;
    int pad08;
    int pad0C;
    char m_reportInplaceAllocations;

    void DispatchWithMode(const char* name, const void* ptr, int size, int unk);
};
template <typename T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T>
__forceinline void addArray(hkStatisticsCollector* collector, const char* name, const hkArray<T>& arr)
{
    if ((arr.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations) {
        void* data = arr.m_data;
        int capacity = arr.m_iCapacityState & 0x3fffffff;
        int allocated = FUN_00d06f80(data, capacity * sizeof(T));
        collector->AddMemoryChunk(3, name, arr.m_data, arr.m_iElementCount * sizeof(T), allocated);
    }
}
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
// Broad-phase endpoint sweep with two inline active-node sets.
void __cdecl ResizeAudioStream(void*, void*, int);
struct AllocObj {
    void** m_vtbl;
};
struct AllocHolderLocal {
    int m_00; int m_04; int m_08; int m_0c;
    AllocObj* m_10;
};
struct U16 { unsigned short v; };
struct ShortVec {
    U16* m_00; int m_04; int m_08;
};
struct LocalVec {
    U16* m_00; int m_04; int m_08;
    U16 m_0c[256];
};
struct Record {
    int m_00; int m_04; int m_08; int m_0c;
};
struct ObjX {
    int m_00;
    ShortVec m_04v;
};
struct PairLocal {
    int m_00; int m_04;
};
struct PairVec {
    PairLocal* m_00; int m_04; int m_08;
};
struct ThisCls {
    int m_00; int m_04; int m_08; int m_0c; int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c; int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44; int m_48; int m_4c; int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c; int m_70; int m_74; int m_78; int m_7c;
    int m_80; int m_84; int m_88; int m_8c; int m_90; int m_94; int m_98; int m_9c;
    Record* m_a0; int m_a4; int m_a8;
    int* m_ac; int m_b0;
    int m_b4; int m_b8; int m_bc; int m_c0; int m_c4; int m_c8; int m_cc; int m_d0; int m_d4;
    char* m_d8;
    void FUN_00d14a60(unsigned int* bits, PairVec* out, char flag);
};
static int FindIdx(const U16* p, int n, unsigned short v)
{
    for (int i = 0; i < n; i++) {
        if (p[i].v == v) return i;
    }
    return -1;
}
static void PushShort(ShortVec* v, unsigned short val)
{
    AllocHolderLocal* h = (AllocHolderLocal*)FUN_00c85750();
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ResizeAudioStream(h->m_10, v, 2);
    v->m_00[v->m_04].v = val;
    v->m_04++;
}
static void PushDynamic(ShortVec* v, unsigned short val)
{
    AllocHolderLocal* h = (AllocHolderLocal*)FUN_00c85750();
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ResizeAudioStream(h->m_10, v, 2);
    U16* p = v->m_00 + *(volatile int*)&v->m_04;
    p->v = val;
    v->m_04++;
}
static void FreeLocalVec(LocalVec& v)
{
    AllocHolderLocal* h = (AllocHolderLocal*)FUN_00c85750();
    AllocObj* ao = h->m_10;
    int cap = v.m_08;
    v.m_04 = 0;
    if ((cap & (int)0x80000000) == 0) {
        typedef void (__thiscall* FreeFn)(AllocObj*, void*, int);
        FreeFn fn = (FreeFn)ao->m_vtbl[4];
        fn(ao, v.m_00, (cap & 0x3fffffff) * 2);
    }
    v.m_00 = 0;
    v.m_08 = (int)0x80000000;
}
static __forceinline void AppendN(PairVec* out, Record* other, Record* rec, int n)
{
    for (int k = 0; k < n; ++k) {
        PairLocal* p = &out->m_00[out->m_04];
        out->m_04++;
        p->m_00 = other->m_0c;
        p->m_04 = rec->m_0c;
    }
}
static __forceinline void HandlePair(ThisCls* idx, Record* rec, Record* other, PairVec* out, char flag)
{
    Record* second = rec;
    Record* first = other;
    if ((rec->m_0c & 1) == 0) {
        if ((other->m_0c & 1) == 0) {
            AllocHolderLocal* r = (AllocHolderLocal*)FUN_00c85750();
            if (out->m_04 == (out->m_08 & 0x3fffffff))
                ResizeAudioStream(r->m_10, out, 8);
            AppendN(out, other, rec, 1);
            return;
        }
        first = rec;
        second = other;
    }
    int fidx = (int)((char*)first - (char*)idx->m_a0) >> 4;
    ObjX* obj = (ObjX*)((second->m_0c & 0xfffffffe) + (int)idx->m_d8);
    if (flag != 0) {
        PushDynamic(&obj->m_04v, (unsigned short)fidx);
    } else {
        ShortVec* lv = &obj->m_04v;
        int self = FindIdx(lv->m_00, lv->m_04, (unsigned short)fidx);
        int& cnt = lv->m_04;
        cnt--;
        int last = cnt;
        if (last != self)
            lv->m_00[self] = lv->m_00[last];
    }
}

#include <xmmintrin.h>
__declspec(align(16)) struct S00d10b30_Node {
    __m64 lo;
    __m64 hi;
};

__declspec(align(16)) struct BpRefBounds {
    unsigned short lo0;
    unsigned short lo1;
    unsigned short lo2;
    unsigned short lo3;
    unsigned short hi0;
    unsigned short hi1;
    unsigned short hi2;
    unsigned short hi3;
};

struct __declspec(align(16)) ReferenceBounds {
    unsigned short min0, min1, min2, min3;
    unsigned short max0, max1;
    unsigned int maxSentinels;
};

int fnv_FloatToInt(float fValue);

// Axis0 candidate-bitset sweep. First argument is updated node count,
// independently confirmed at the real caller; it is not allocation words.
// Destination is16-byte aligned raw bit storage with caller padding.

typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
struct S_00d112c0_EndPoint {
    hkUint16 m_uiFilterValue;
    hkUint16 m_usIndex;
};
struct S_00d112c0_Node {
    hkUint16 m_min1, m_min2, m_max1, m_max2;
    hkUint16 m_min0;
    hkUint16 m_max0;
    unsigned int m_handle;
};
struct S_00d112c0_Marker {
    hkUint16 m_usIndex;
    hkUint16 unk2;
    const hkUint16* m_kNode;
    int m_uiItemCount;
    int m_iCapacityState;
};
struct S_00d112c0 {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    S_00d112c0_Node* m_kNodeCollection;
    int unka4;
    int unka8;
    S_00d112c0_EndPoint* m_ep;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int m_iMarkerCount;
    int m_markerShift;
    S_00d112c0_Marker* m_pOverlappingMarkerInfo;
    void FUN_00d112c0(int numNodes, int key, const S_00d112c0_Node* aabb, hkUint16 skip, hkUint32* bits);
};
inline void flip(hkUint32* bits, int i) {
    int idx = i >> 5;
    bits[idx] ^= 1u << (i & 31);
}
inline void clear(hkUint32* bits, int i) {
    int idx = i >> 5;
    bits[idx] &= ~(1u << (i & 31));
}
// @f3 0x00991290 (community match, verified in this file)
// pdb: hkp3AxisSweep::setBitsBasedOnXInterval | hkp3AxisSweep.obj | tesv_win, objrun_sim, low
void S_00d112c0::FUN_00d112c0(int numNodes, int key, const S_00d112c0_Node* aabb, hkUint16 skip, hkUint32* bits)
{
    unsigned minX = aabb->m_min0;
    unsigned maxX = aabb->m_max0;
    int n = numNodes >> 7;
    __declspec(align(16)) float z4[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    hkUint32* const b0 = bits;
    float* d = (float*)b0;
    for (; n >= 0; n--) {
        float* t = d;
        d += 4;
        t[0] = z4[0]; t[1] = z4[1]; t[2] = z4[2]; t[3] = z4[3];
    }
    S_00d112c0_EndPoint* ep = m_ep + 1;
    if (m_iMarkerCount) {
        key >>= (16 - m_markerShift);
        if (key > 0) {
            const S_00d112c0_Marker* m = &m_pOverlappingMarkerInfo[key - 1];
            flip(bits, m->m_usIndex);
            const hkUint16* l = m->m_kNode;
            int c = m->m_uiItemCount - 1;
            while (c >= 0) {
                if (*l != skip)
                    flip(bits, *l);
                l++;
                c--;
            }
            const S_00d112c0_Node* n = &m_kNodeCollection[m->m_usIndex];
            S_00d112c0_EndPoint* p = m_ep + n->m_min0 + 1;
            S_00d112c0_EndPoint* e = m_ep + n->m_max0;
            for (; p < e; p++)
                if (!(p->m_uiFilterValue & 1))
                    clear(bits, p->m_usIndex);
            ep = m_ep + n->m_min0 + 1;
        }
    }
    S_00d112c0_EndPoint* e1 = m_ep + minX;
    for (; ep < e1; ep++)
        flip(bits, ep->m_usIndex);
    ep++;
    S_00d112c0_EndPoint* e2 = m_ep + maxX;
    for (; ep < e2; ep++)
        if (!(ep->m_uiFilterValue & 1))
            flip(bits, ep->m_usIndex);
}


extern float DAT_011b3770[4];
extern float DAT_011b3790[4];
struct ObjPrefix { unsigned short f0; unsigned short f1; };
struct Obj8 : ObjPrefix { unsigned short f2; unsigned short f3; unsigned short f4; unsigned short f5; int tail; __forceinline unsigned short& slot0(){return f0;} __forceinline unsigned short& slot1(){return f1;} __forceinline unsigned short& slot2(){return f2;} __forceinline unsigned short& slot3(){return f3;} __forceinline unsigned short& slot4(){return f4;} __forceinline unsigned short& slot5(){return f5;} };
union End8 { struct { unsigned short key; unsigned short id; }; unsigned int packed; };
struct Mgr8;
void __fastcall FUN_00d11c60(Mgr8* mgr, Obj8* cur, int id, Obj8* other, unsigned int p);
void __fastcall RemoveOrAppendTagEntry(Mgr8* mgr, Obj8* cur, int id, Obj8* other, unsigned int p);
void __fastcall AppendPairToBuffer(Obj8* cur, Obj8* other, unsigned int p);
void __fastcall AppendPairEntry(Obj8* cur, Obj8* other, unsigned int p);
struct __declspec(align(16)) QuantMin40 { unsigned short x,y,z,w; };
struct Vec33 {
    __m128 data;
    __forceinline void setZero() { data=_mm_setzero_ps(); }
    __forceinline void setAdd4(const Vec33& a,const Vec33& b) { data=_mm_add_ps(a.data,b.data); }
    __forceinline void mul4(const Vec33& b) { data=_mm_mul_ps(data,b.data); }
    __forceinline void min4(const Vec33& b) { data=_mm_min_ps(data,b.data); }
    __forceinline void max4(const Vec33& b) { data=_mm_max_ps(data,b.data); }
    __forceinline void add4(const Vec33& b) { data=_mm_add_ps(data,b.data); }
};
struct Bounds33 { unsigned int min[4]; unsigned int max[4]; };
struct VPair8 { Vec33 v0; Vec33 v1; };
struct Sweep8 {
    int m00; int m04; int m08; int m0c; int m10; int m14; int m18; int m1c;
    int m20; int m24; int m28; int m2c; int m30; int m34; int m38; int m3c;
    Vec33 row40; Vec33 row50; Vec33 row60;
    int m70; int m74; int m78; int m7c; int m80; int m84; int m88; int m8c;
    int m90; int m94; int m98; int m9c;
    Obj8* objs; int mA4; int mA8; End8* listA; int mB0; int mB4; End8* listB; int mB8dummy;
    int mC0; End8* listC; int mC8; int mCC; int mD0; int mD4; Mgr8* mgr; int mDC;
    __forceinline void convert33(const unsigned int& addr, Bounds33& out) {
VPair8* a1=(VPair8*)addr; Vec33 zero; zero.setZero();
            Vec33 clamp; clamp.data=_mm_load_ps(DAT_011b3790);
            const Vec33& bias=*(const Vec33*)DAT_011b3770;
            Vec33 pw, qw;
            pw.setAdd4(a1->v0,row40); pw.mul4(row60); pw.min4(clamp); pw.max4(zero); pw.add4(bias);
                        QuantMin40 qa;
            qa.x = (unsigned short)(pw.data.m128_u32[0] >> 7);
            qa.y = (unsigned short)(pw.data.m128_u32[1] >> 7);
            qa.z = (unsigned short)(pw.data.m128_u32[2] >> 7);
            qw.setAdd4(a1->v1,row50); qw.mul4(row60); qw.min4(clamp); qw.max4(zero); qw.add4(bias);
            unsigned short u[4];
            u[0] = (unsigned short)(qw.data.m128_u32[0] >> 7);
            u[1] = (unsigned short)(qw.data.m128_u32[1] >> 7);
            u[2] = (unsigned short)(qw.data.m128_u32[2] >> 7);

            out.min[0] = (*(unsigned int*)&qa.x) & 0xfffe; out.min[1] = (*(unsigned int*)&qa.y) & 0xfffe; out.min[2] = (*(unsigned int*)&qa.z) & 0xfffe;
            out.max[0] = u[0] | 1;
            out.max[1] = u[1] | 1;
            out.max[2] = u[2] | 1;

    }
    __forceinline void axis34_0(Obj8* key, unsigned int r, Obj8& current, unsigned int lower, unsigned int upper, const unsigned int& a3, const unsigned int& a4) {
Obj8* ep=&current;
            // P1: listA, pos field f4 (offset 8), p lower, backward + equal tail
            {
                End8* list = listA;
                int obj = ep->f4;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot5() = (unsigned short)obj;
                            if ((overlaps & 0x80008000) == 0)
                                FUN_00d11c60(mgr, ep, r, other, a3);
                        } else {
                            other->slot4() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot4() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
                ep->f4 = (unsigned short)obj;
            }
            // P2: listA, pos field f5, p upper, forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listA;
                int obj = ep->f5;
                End8* i = list + obj;
                unsigned int p;
                p = upper;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
 Obj8* other; (void)other;
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot4()--;
                            if ((overlaps & 0x80008000) == 0)
                                FUN_00d11c60(mgr, ep, r, other, a3);
                        } else {
                            other->slot5()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        if (!nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot5()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        i[0].packed = i[-1].packed;
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i--;
                        obj--;
                        if ((n & 1) == 0) {
                            int a; unsigned int end; (void)a; end = (*(int*)&ep->f2) - (*(int*)&other->f0); a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            other->slot4()++;
                            if (((a | end) & 0x80008000) == 0)
                                RemoveOrAppendTagEntry(mgr, ep, r, other, a4);
                        } else {
                            other->slot5()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot5()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f5 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
            }
            // P1 forward: listA, pos field f4, p lower, forward + fwd-equal
            {
                End8* list = listA;
                int obj = ep->f4;
                End8* i = list + obj;
                unsigned int otherIdx = i[1].key;
                unsigned int p = lower;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        obj++;
                        if (otherIdx & 1) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot5()--;
                            if ((overlaps & 0x80008000) == 0)
                                RemoveOrAppendTagEntry(mgr, ep, r, other, a4);
                        } else {
                            other->slot4()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot4()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f4 = (unsigned short)obj;
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
            }

    }
    __forceinline void axis34_1(Obj8* key, unsigned int r, Obj8& current, unsigned int lower, unsigned int upper, const unsigned int& a3, const unsigned int& a4) {
Obj8* ep=&current;
            // P4 backward: listB, pos field f0, p lower, backward + bwd-equal (4x u16 overlap test)
            {
                End8* list = listB;
                int obj = ep->f0;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            unsigned short a = (unsigned short)((unsigned short)((*(int*)&ep->f2) >> 16) - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot2() = (unsigned short)obj;
                            if ((a & 0x8000) == 0)
                                AppendPairToBuffer(ep, other, a3);
                        } else {
                            other->slot0() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot0() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
                ep->f0 = (unsigned short)obj;
            }
            // P5: listB, pos field f2, p upper, forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listB;
                int obj = ep->f2;
                End8* i = list + obj;
                unsigned int p = upper;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        Obj8* other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            unsigned short a = (unsigned short)((unsigned short)((*(int*)&ep->f2) >> 16) - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot0()--;
                            if ((a & 0x8000) == 0)
                                AppendPairToBuffer(ep, other, a3);
                        } else {
                            other->slot2()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        if (nextKey == 0) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot2()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        i[0].packed = i[-1].packed;
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i--;
                        obj--;
                        if ((n & 1) == 0) {
                            unsigned short a = (unsigned short)(ep->f3 - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot0()++;
                            if ((a & 0x8000) == 0)
                                AppendPairEntry(ep, other, a4);
                        } else {
                            other->slot2()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot2()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f2 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
            }
            // P4 forward: listB, pos field f0, p lower, forward + fwd-equal
            {
                End8* list = listB;
                int obj = ep->f0;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i += 1;
                        obj++;
                        if (otherIdx & 1) {
                            unsigned short a = (unsigned short)(ep->f3 - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot2()--;
                            if ((a & 0x8000) == 0)
                                AppendPairEntry(ep, other, a4);
                        } else {
                            other->slot0()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot0()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f0 = (unsigned short)obj;
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
            }

    }

    void FUN_00d12040(int** a0, unsigned int a1, int a2, unsigned int volatile a3, unsigned int volatile a4);
};

#include <xmmintrin.h>
namespace fnv_00d154a0 {
extern __m128 DAT_011b3790;
extern __m128 DAT_011b3770;

struct Obj154 {
    virtual float unk00(int a, int b);
    virtual float call4(int a, int b);
};

struct Axis154 {
    Entry* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    Entry* LowerBoundEntry(Entry*, Entry*, int);
    __forceinline void search(int low,int high,unsigned short& lower,unsigned short& upper) {
        Entry* base=m_data;
        Entry* last=base+m_iElementCount-2;
        Entry* res=LowerBoundEntry(base+1,last,low);
        lower=(unsigned short)(res-base);
        res=LowerBoundEntry(base+1,last,high);
        upper=(unsigned short)(res-(base+1));
    }

};

struct Aabb154 {__m128 min,max;};
struct Input154 { const Aabb154* p; Input154(const Aabb154* q):p(q) {} };
struct Callback154 { Obj154* p; Callback154(Obj154* q):p(q) {} };

__declspec(noinline) Entry* Axis154::LowerBoundEntry(Entry* first, Entry* last, int key) {
    while (last-first > 16) {
        Entry* middle=first+((last-first)>>1);
        if (middle->key < (unsigned short)key) first=middle;
        else last=middle;
    }
    while (first->key < (unsigned short)key) ++first;
    return first;
}
}  // namespace fnv_00d154a0

unsigned int* volatile g_zeroDestination;
volatile int g_zeroLength;

#include <xmmintrin.h>
namespace fnv_00d159a0 {
#include <xmmintrin.h>


struct S159a0_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int& reqNumBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S159a0_Router {
    int unk00;
    int unk04;
    int unk08;
    S159a0_Alloc* m_aiEntries;
    static S159a0_Router& GetMonitorStream() { return *(S159a0_Router*)FUN_00c85750(); }
    S159a0_Alloc& stack() { return *m_aiEntries; }
};
inline S159a0_Alloc& S159a0_stack() { return S159a0_Router::GetMonitorStream().stack(); }

struct S159a0_Node {
    unsigned short m_usValue00;
    unsigned short m_usValue02;
    unsigned short m_usValue04;
    unsigned short m_usValue06;
    unsigned short minX;
    unsigned short maxX;
    unsigned int handle;
    unsigned int yzDisjoint(const S159a0_Node& o) const
    {
        unsigned int maxA = *(const unsigned int*)&m_usValue04;
        unsigned int minB = *(const unsigned int*)&o.m_usValue00;
        unsigned int maxB = *(const unsigned int*)&o.m_usValue04;
        unsigned int minA = *(const unsigned int*)&m_usValue00;
        maxB -= minA;
        maxA -= minB;
        return (maxA | maxB) & 0x80008000;
    }
};
struct S159a0_NodeArray {
    S159a0_Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void destroy()
    {
        S159a0_Alloc& a = S159a0_stack();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S159a0_Node*));
    }
};
void __cdecl FUN_00c908c0(S159a0_Alloc* alloc, S159a0_NodeArray* arr, int numElements, int sizeElem);

union __declspec(align(16)) S159a0_IntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
struct __declspec(align(16)) S159a0_AabbInt {
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};
extern __m128 DAT_011b3790;
extern __m128 DAT_011b3770;

}  // namespace fnv_00d159a0

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d16c50 {
#include <math.h>


struct S16c50_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int& numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
    template <class T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * (int)sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <class T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * (int)sizeof(T));
    }
};
struct S16c50_Router {
    int unk00;
    int unk04;
    int unk08;
    S16c50_Alloc* m_pTemp;
    static S16c50_Router& GetMonitorStream() { return *(S16c50_Router*)FUN_00c85750(); }
    S16c50_Alloc& temp() { return *m_pTemp; }
};
struct S16c50_TempAllocator {
    S16c50_Alloc& get(void*) { return S16c50_Router::GetMonitorStream().temp(); }
};

struct S16c50_Vec4 {
    __m128 m_vComponents;
    float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    void setAdd4(const S16c50_Vec4& a, const S16c50_Vec4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void setSub4(const S16c50_Vec4& a, const S16c50_Vec4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void operator=(const S16c50_Vec4& v) { m_vComponents = v.m_vComponents; }
};

union S16c50_IntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
union S16c50_QuadInt {
    __m128 q;
    unsigned int i[4];
};
extern __m128 DAT_011b3790;
extern __m128 DAT_011b3770;

__forceinline void S16c50_convertToUint16WithClip(const S16c50_Vec4& in, const S16c50_Vec4& offset, const S16c50_Vec4& scale, const S16c50_Vec4& minV, const S16c50_Vec4& maxV, S16c50_IntUnion64& out)
{
    __m128 x = _mm_add_ps(offset.m_vComponents, in.m_vComponents);
    x = _mm_mul_ps(x, scale.m_vComponents);
    x = _mm_min_ps(x, maxV.m_vComponents);
    x = _mm_max_ps(x, minV.m_vComponents);
    x = _mm_add_ps(x, DAT_011b3770);
    S16c50_QuadInt u;
    u.q = x;
    out.u16[0] = (unsigned short)(u.i[0] >> 7);
    out.u16[1] = (unsigned short)(u.i[1] >> 7);
    out.u16[2] = (unsigned short)(u.i[2] >> 7);
    out.u16[3] = (unsigned short)(u.i[3] >> 7);
}

struct S16c50_EndPoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
    int isMaxPoint() const { return m_uiFilterValue & 1; }
};
struct S16c50_Node {
    unsigned short m_min_y;
    unsigned short m_min_z;
    unsigned short m_max_y;
    unsigned short m_max_z;
    unsigned short m_min_x;
    unsigned short m_max_x;
    unsigned int m_handle;
    int isMarker() const { return m_handle & 1; }
};
struct S16c50_Axis {
    S16c50_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    const S16c50_EndPoint* begin() const { return m_data; }
    const S16c50_EndPoint& operator[](int i) const { return m_data[i]; }
};
struct S16c50_NodeArray {
    S16c50_Node* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    const S16c50_Node& operator[](int i) const { return m_data[i]; }
};

struct S16c50_ByteArray {
    unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S16c50_ByteArray(int n)
    {
        S16c50_Alloc& a = S16c50_TempAllocator().get(this);
        unsigned char* p = n ? a._bufAlloc<unsigned char>(n) : 0;
        int cap = n ? n : (int)0x80000000;
        m_data = p;
        m_iElementCount = n;
        m_iCapacityState = cap;
    }
    __forceinline ~S16c50_ByteArray()
    {
        S16c50_Alloc& a = S16c50_TempAllocator().get(this);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0) {
            a._bufFree<unsigned char>(m_data, m_iCapacityState & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = (int)0x80000000;
    }
    unsigned char* begin() { return m_data; }
};

struct S16c50_Collector {
    virtual void v0();
    virtual float ReleaseCollector(unsigned int handle, int castIndex);
};
struct S16c50_CastAabbInput {
    S16c50_Vec4 m_vFrom;
    S16c50_Vec4 m_vTo;
    S16c50_Vec4 m_vHalfExtents;
    const char* m_pBroadPhaseAabbCache;
};

extern const float DAT_0104a494, DAT_010162c0;

struct S16c50_Sweep {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    S16c50_Vec4 m_kVectorAt40;
    S16c50_Vec4 m_kVectorAt50;
    S16c50_Vec4 m_vScale;
    S16c50_Vec4 unk70;
    S16c50_Vec4 unk80;
    S16c50_Vec4 unk90;
    S16c50_NodeArray m_kNodeCollection;
    S16c50_Axis m_kAxisEndPoints[3];
    int m_iMarkerCount;
    int m_iMarkerCapacity;
    void* m_pOverlappingMarkerInfo;
    float m_fValueAfterOverlappingMarkerInfo;

    __forceinline void convertVectorToInt(const S16c50_Vec4& vec, unsigned int* intsOut) const
    {
        S16c50_Vec4 minVal; minVal.setZero4();
        S16c50_Vec4 maxVal; maxVal.m_vComponents = DAT_011b3790;
        S16c50_IntUnion64 out;
        S16c50_convertToUint16WithClip(vec, m_kVectorAt40, m_vScale, minVal, maxVal, out);
        intsOut[0] = out.u16[0];
        intsOut[1] = out.u16[1];
        intsOut[2] = out.u16[2];
        intsOut[3] = out.u16[3];
    }
    void FUN_00d16c50(const S16c50_CastAabbInput& input, S16c50_Collector& collector) const;
};

}  // namespace fnv_00d16c50

extern __m128 DAT_010c44d0;

struct Vec4
{
    __m128 m_vComponents;

    void setNeg4(const Vec4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }
    void add4(const Vec4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    void setAdd4(const Vec4& a, const Vec4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void setXYZW(const Vec4& xyz, const Vec4& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), _MM_SHUFFLE(3, 0, 1, 0));
    }
    void setReciprocal4(const Vec4& v)
    {
        __m128 e = _mm_rcp_ps(v.m_vComponents);
        m_vComponents = _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, v.m_vComponents), e));
    }
};

void __cdecl ResizeAudioStream(void* allocator,void* array,int elementSize);
struct S4ef0Allocator {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
 virtual void ReturnMemory(void* p,int numBytes);
 template<class T> __forceinline T* _bufAlloc(int& reqNumInOut) { const int SIZE_ELEM=sizeof(T); int n=reqNumInOut*SIZE_ELEM; void* p=AllocateBufferWithSize(n); reqNumInOut=n/SIZE_ELEM; return static_cast<T*>(p); }
 template<class T> __forceinline void _bufFree(void* p,int numElem) { const int SIZE_ELEM=sizeof(T); ReturnMemory(p,numElem*SIZE_ELEM); }
};
struct S4ef0Router { int unk00,unk04,unk08; S4ef0Allocator* m_pTemp; S4ef0Allocator* m_pStreamAllocator;
 __forceinline S4ef0Allocator& temp() {return *m_pTemp;} __forceinline S4ef0Allocator& heap() {return *m_pStreamAllocator;}
 static __forceinline S4ef0Router& GetMonitorStream() { return *(S4ef0Router*)FUN_00c85750(); }
};
struct S4ef0TempAlloc { __forceinline S4ef0Allocator& get(void*) { return S4ef0Router::GetMonitorStream().temp(); } };
struct S4ef0HeapAlloc { __forceinline S4ef0Allocator& get(const void*) { return S4ef0Router::GetMonitorStream().heap(); } };
struct S4ef0TypeIsPod {}; struct S4ef0TypeIsClass {};
template<class T> __forceinline void S4ef0_construct(T* t,int n,S4ef0TypeIsPod) {}
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsClass) { for(int i=0;i<n;++i) { if(t+i) t[i]=tcopy; } }
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsPod) { for(int i=0;i<n;++i) { t[i]=tcopy; } }
template<class T> struct S4ef0ArrayBase {
 enum { CAPACITY_MASK=0x3fffffff, DONT_DEALLOCATE_FLAG=0x80000000 };
 T* m_data; int m_iElementCount; int m_iCapacityState;
 __forceinline S4ef0ArrayBase():m_data(0),m_iElementCount(0),m_iCapacityState(DONT_DEALLOCATE_FLAG) {}
 __forceinline int GetLogicalSize() const { return m_iElementCount; }
 __forceinline int getCapacity() const { return m_iCapacityState&static_cast<int>(CAPACITY_MASK); }
 __forceinline T* begin() { return m_data; }
 __forceinline T* end() { return m_data+m_iElementCount; }
 __forceinline const T* begin() const { return m_data; }
 __forceinline const T* end() const { return m_data+m_iElementCount; }
 __forceinline T& operator[](int i) { return m_data[i]; }
 __forceinline const T& operator[](int i) const { return m_data[i]; }
 __forceinline void setOwnedData(T* ptr,int size,int capacity) { m_data=ptr; m_iElementCount=size; m_iCapacityState=capacity; }
 __forceinline void clear() { m_iElementCount=0; }
 __forceinline void _clearAndDeallocate(S4ef0Allocator& alloc) {
  clear();
  if((m_iCapacityState&DONT_DEALLOCATE_FLAG)==0) alloc._bufFree<T>(m_data,getCapacity());
  m_data=0; m_iCapacityState=DONT_DEALLOCATE_FLAG;
 }
 __forceinline void pushBackUnchecked(const T& t) { S4ef0_constructWithCopy(m_data+m_iElementCount,1,t,S4ef0TypeIsPod()); m_iElementCount++; }
 __forceinline void _pushBack(S4ef0Allocator& alloc,const T& t) {
  if(m_iElementCount==getCapacity()) ResizeAudioStream(&alloc,this,sizeof(T));
  S4ef0_constructWithCopy(m_data+m_iElementCount,1,t,S4ef0TypeIsClass());
  m_iElementCount++;
 }
};
template<class T,class A> struct S4ef0Array : S4ef0ArrayBase<T> {
 __forceinline S4ef0Array(int n) : S4ef0ArrayBase<T>() {
  S4ef0Allocator& a=A().get(this);
  T* p=n ? a._bufAlloc<T>(n) : 0;
  int cap=n ? n : S4ef0ArrayBase<T>::DONT_DEALLOCATE_FLAG;
  this->setOwnedData(p,n,cap);
  S4ef0_construct(this->m_data,n,S4ef0TypeIsPod());
 }
 __forceinline ~S4ef0Array() { this->_clearAndDeallocate(A().get(this)); }
 __forceinline void AddBack(const T& t) { this->_pushBack(A().get(this),t); }
};
struct S4ef0Vector {
 __m128 m_vComponents;
 __forceinline S4ef0Vector() {}
 __forceinline __m128& getQuad() { return m_vComponents; }
 __forceinline const __m128& getQuad() const { return m_vComponents; }
 __forceinline void setZero4() { m_vComponents=_mm_setzero_ps(); }
 __forceinline void operator=(const S4ef0Vector& v) { m_vComponents=v.m_vComponents; }
 __forceinline void setAdd4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_add_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void add4(const S4ef0Vector& v) { m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents); }
 __forceinline void mul4(const S4ef0Vector& v) { m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents); }
 __forceinline void setMin4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_min_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void setMax4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_max_ps(a.m_vComponents,b.m_vComponents); }
};
struct S4ef0Aabb { S4ef0Vector m_kMinimumCorner,m_kMaximumCorner; };
__declspec(align(16)) struct S4ef0AabbInt { unsigned int m_kMinimumCorner[3]; unsigned char m_ucExpansionMin[3]; unsigned char m_ucExpansionShift; unsigned int m_kMaximumCorner[3]; unsigned char m_ucExpansionMax[3]; unsigned char m_expansionMaxXYZ; };
union S4ef0Union64 { __m128 quad; __int64 i64; unsigned __int64 u64; int i32[2]; unsigned int u32[2]; short i16[4]; unsigned short u16[4]; };
__forceinline void S4ef0_convertToUint16WithClip(const S4ef0Vector& in,const S4ef0Vector& offset,const S4ef0Vector& scale,const S4ef0Vector& min,const S4ef0Vector& max,S4ef0Union64& out) {
 S4ef0Vector x;
 x.setAdd4(in,offset);
 x.mul4(scale);
 x.setMin4(x,max);
 x.setMax4(x,min);
 S4ef0Vector magic;
 magic.getQuad()=*(const __m128*)DAT_011b3770;
 x.add4(magic);
 union { __m128 q; unsigned int i[4]; } u;
 u.q=x.getQuad();
 out.i16[0]=(short)(u.i[0]>>7);
 out.i16[1]=(short)(u.i[1]>>7);
 out.i16[2]=(short)(u.i[2]>>7);
 out.i16[3]=(short)(u.i[3]>>7);
}
__forceinline void S4ef0_memclear16(void* dest,int numBytes) {
 S4ef0Vector zero; zero.setZero4();
 S4ef0Vector* d=(S4ef0Vector*)dest;
 for(numBytes>>=4;numBytes>=0;numBytes--) { *(d++)=zero; }
}
__forceinline void S4ef0_staticFlipBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]^=mask; }
__forceinline void S4ef0_staticClearBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]&=~mask; }
struct S4ef0Pair { unsigned int m_kPointA,m_kPointB; };
struct S4ef0Node {
 unsigned short m_usValue00,m_usValue02,m_usValue04,m_usValue06,m_usValue08,m_usValue0A; unsigned int m_handle;
 __forceinline unsigned int yzDisjoint(const S4ef0Node& other) const {
  unsigned int minA=*(const unsigned int*)&m_usValue00; unsigned int minB=*(const unsigned int*)&other.m_usValue00;
  unsigned int maxA=*(const unsigned int*)&m_usValue04; unsigned int maxB=*(const unsigned int*)&other.m_usValue04;
  maxA-=minB; maxB-=minA; maxA|=maxB; maxA&=0x80008000; return maxA;
 }
 __forceinline int isMarker() const { return m_handle&1; }
};
struct S4ef0Marker { unsigned short m_usIndex,m_uiFilterValue; S4ef0ArrayBase<unsigned short> m_kMarkerIndices; };
struct S4ef0Axis : S4ef0ArrayBase<Entry> { const Entry* LowerBoundEntry(const Entry* first,const Entry* last,unsigned short key) const; };
__declspec(noinline) const Entry* S4ef0Axis::LowerBoundEntry(const Entry* start,const Entry* end,unsigned short value) const {
 while(end-start>16) {
  const Entry* mid=start+((end-start)>>1);
  if(mid->key<value) start=mid; else end=mid;
 }
 while(start->key<value) start++;
 return start;
}
struct S4ef0Handle;
struct S4ef0Collector { virtual void v0(); virtual float ReleaseCollector(unsigned int h,int i); };
typedef S4ef0Array<S4ef0Pair,S4ef0HeapAlloc> S4ef0Results;
typedef S4ef0ArrayBase<const S4ef0Node*> S4ef0NodeArr;
struct S4ef0Owner {
 __m128 unk00,unk10,unk20,unk30;
 S4ef0Vector m_kVectorAt40,m_kVectorAt50,m_vScale;
 __m128 unk70,unk80,unk90;
 S4ef0ArrayBase<S4ef0Node> m_kNodeCollection;
 S4ef0Axis m_kAxisEndPoints[3];
 int m_iMarkerCount,m_iMarkerCapacity; S4ef0Marker* m_pOverlappingMarkerInfo;
 __forceinline int getNumMarkers() const { return m_iMarkerCount; }
 __forceinline void _convertAabbToInt(const S4ef0Aabb& aabb,S4ef0AabbInt& aabbOut) const { _convertAabbToIntS(aabb,m_kVectorAt40,m_kVectorAt50,m_vScale,aabbOut); }
 static __forceinline void _convertAabbToIntS(const S4ef0Aabb& aabb,const S4ef0Vector& offsetLow,const S4ef0Vector& offsetHigh,const S4ef0Vector& scale,S4ef0AabbInt& aabbOut);
 __forceinline void querySingleAabbSub(S4ef0Handle* object,const unsigned int* bitField,S4ef0Node& refNode,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 __forceinline void _querySingleAabb(const S4ef0Aabb& aabb,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 void FUN_00d14ef0(const S4ef0Aabb& aabb,S4ef0Results& pairsOut) const;
};
__forceinline void S4ef0Owner::_convertAabbToIntS(const S4ef0Aabb& aabb,const S4ef0Vector& offsetLow,const S4ef0Vector& offsetHigh,const S4ef0Vector& scale,S4ef0AabbInt& aabbOut) {
 S4ef0Vector zero; zero.setZero4();
 S4ef0Vector maxVal; maxVal.getQuad()=*(const __m128*)DAT_011b3790;
 S4ef0Union64 mi;
 S4ef0Union64 ma;
 S4ef0_convertToUint16WithClip(aabb.m_kMinimumCorner,offsetLow,scale,zero,maxVal,mi);
 S4ef0_convertToUint16WithClip(aabb.m_kMaximumCorner,offsetHigh,scale,zero,maxVal,ma);
 aabbOut.m_kMinimumCorner[0]=mi.u16[0]&0xfffe;
 aabbOut.m_kMinimumCorner[1]=mi.u16[1]&0xfffe;
 aabbOut.m_kMinimumCorner[2]=mi.u16[2]&0xfffe;
 aabbOut.m_kMaximumCorner[0]=ma.u16[0]|1;
 aabbOut.m_kMaximumCorner[1]=ma.u16[1]|1;
 aabbOut.m_kMaximumCorner[2]=ma.u16[2]|1;
}
__forceinline void S4ef0Owner::querySingleAabbSub(S4ef0Handle* object,const unsigned int* bitField,S4ef0Node& refNode,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const {
 S4ef0Pair pair; pair.m_kPointA=(unsigned int)object;
 const S4ef0Node* nodes=&m_kNodeCollection[0];
 const unsigned int* bitFieldEnd=bitField+(m_kNodeCollection.GetLogicalSize()>>5)+1;
 for(;bitField<bitFieldEnd;nodes+=32,bitField++) {
  unsigned int bits=*bitField;
  if(!bits) continue;
  const S4ef0Node* n=nodes;
  do {
   if(bits&0xf) {
    if(bits&1) {
     if(!n[0].yzDisjoint(refNode) && !n[0].isMarker()) {
      if(type==0) { pair.m_kPointB=n[0].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[0]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[0].m_handle,0); }
     }
    }
    if(bits&2) {
     if(!n[1].yzDisjoint(refNode) && !n[1].isMarker()) {
      if(type==0) { pair.m_kPointB=n[1].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[1]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[1].m_handle,0); }
     }
    }
    if(bits&4) {
     if(!n[2].yzDisjoint(refNode) && !n[2].isMarker()) {
      if(type==0) { pair.m_kPointB=n[2].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[2]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[2].m_handle,0); }
     }
    }
    if(bits&8) {
     if(!n[3].yzDisjoint(refNode) && !n[3].isMarker()) {
      if(type==0) { pair.m_kPointB=n[3].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[3]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[3].m_handle,0); }
     }
    }
   }
   n+=4; bits>>=4;
  } while(bits);
 }
}
__forceinline void S4ef0Owner::_querySingleAabb(const S4ef0Aabb& aabb,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const {
 S4ef0Handle* object=0;
 int size=m_kNodeCollection.GetLogicalSize();
 S4ef0Array<unsigned int,S4ef0TempAlloc> bitFieldArr((size>>5)+8);
 unsigned int* bitField=bitFieldArr.begin();
 S4ef0_memclear16(bitField,size>>3);
 S4ef0AabbInt aabbInt;
 _convertAabbToInt(aabb,aabbInt);
 const Entry* ep=&m_kAxisEndPoints[0][1];
 if(getNumMarkers()) {
  int value=aabbInt.m_kMinimumCorner[0];
  int pos=value>>(16-m_iMarkerCapacity);
  if(pos>0) {
   S4ef0Marker* marker=&m_pOverlappingMarkerInfo[pos-1];
   S4ef0_staticFlipBit(bitField,marker->m_usIndex);
   const unsigned short* objects=marker->m_kMarkerIndices.begin();
   for(int i=marker->m_kMarkerIndices.GetLogicalSize()-1;i>=0;i--) { S4ef0_staticFlipBit(bitField,*objects); objects++; }
   const S4ef0Node& node=m_kNodeCollection[marker->m_usIndex];
   ep=&m_kAxisEndPoints[0][node.m_usValue08+1];
   const Entry* end=&m_kAxisEndPoints[0][node.m_usValue0A];
   for(;ep<end;ep++) { if(!(ep->key&1)) S4ef0_staticClearBit(bitField,ep->value); }
   ep=&m_kAxisEndPoints[0][node.m_usValue08+1];
  }
 }
 for(;ep->key<aabbInt.m_kMinimumCorner[0];ep++) { S4ef0_staticFlipBit(bitField,ep->value); }
 for(;ep->key<aabbInt.m_kMaximumCorner[0];ep++) { if(!(ep->key&1)) S4ef0_staticFlipBit(bitField,ep->value); }
 S4ef0Node refNode;
 {
  const S4ef0Axis& axis=m_kAxisEndPoints[1];
  const Entry* start=&axis[0];
  refNode.m_usValue00=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMinimumCorner[1])-start);
  refNode.m_usValue04=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMaximumCorner[1])-(start+1));
 }
 {
  const S4ef0Axis& axis=m_kAxisEndPoints[2];
  const Entry* start=&axis[0];
  refNode.m_usValue02=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMinimumCorner[2])-start);
  refNode.m_usValue06=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMaximumCorner[2])-(start+1));
 }
 querySingleAabbSub(object,bitField,refNode,type,pairsOut,nodesOut,collector);
}
// @f3 0x00991ee0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern const float DAT_01060dd0[4];
extern const float DAT_01060db0[4];
extern void __cdecl FUN_00901f10(void* arr, int elemSize);

namespace n991ee0
{
__declspec(align(16)) struct S4ef0V4Local { float v[4]; };
__declspec(align(16)) union S4ef0U16x4 { unsigned short u16[4]; unsigned int u32[2]; };

struct S4ef0Lifo {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void* Alloc(int n);
    virtual void Free(void* p);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* m_pTop;
    int unk24;
    char* m_pBase;
    char* m_pLimit;
};

struct __declspec(align(16)) S4ef0Fpu4
{
    float x, y, z, w;
    __forceinline void setAdd4(const S4ef0Vector& a, const S4ef0Vector& b)
    {
        x = a.getQuad().m128_f32[0] + b.getQuad().m128_f32[0];
        y = a.getQuad().m128_f32[1] + b.getQuad().m128_f32[1];
        z = a.getQuad().m128_f32[2] + b.getQuad().m128_f32[2];
        w = a.getQuad().m128_f32[3] + b.getQuad().m128_f32[3];
    }
    __forceinline void mul4(const S4ef0Vector& a)
    {
        x *= a.getQuad().m128_f32[0];
        y *= a.getQuad().m128_f32[1];
        z *= a.getQuad().m128_f32[2];
        w *= a.getQuad().m128_f32[3];
    }
    __forceinline void setMin4(const S4ef0Fpu4& a, const S4ef0Fpu4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const S4ef0Fpu4& a, const S4ef0Fpu4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
    __forceinline void add4(const S4ef0Fpu4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
    __forceinline void setZero4()
    {
        x = y = z = w = 0;
    }
};

static __forceinline void S4ef0ConvertToUint16WithClip(const S4ef0Vector& in, const S4ef0Vector& offset, const S4ef0Vector& scale, const S4ef0Fpu4& min, const S4ef0Fpu4& max, S4ef0U16x4& out)
{
    S4ef0Fpu4 x;
    x.setAdd4(in, offset);
    x.mul4(scale);
    x.setMin4(x, max);
    x.setMax4(x, min);
    x.add4(reinterpret_cast<const S4ef0Fpu4&>(DAT_01060db0));
    union
    {
        S4ef0Fpu4 q;
        unsigned int i[4];
    } u;
    u.q = x;
    out.u16[0] = (unsigned short)(u.i[0] >> 7);
    out.u16[1] = (unsigned short)(u.i[1] >> 7);
    out.u16[2] = (unsigned short)(u.i[2] >> 7);
    out.u16[3] = (unsigned short)(u.i[3] >> 7);
}

static __forceinline void S4ef0ConvertAabbToInt(const S4ef0Aabb& aabb, const S4ef0Vector& offsetLow, const S4ef0Vector& offsetHigh,
                                               const S4ef0Vector& scale, S4ef0AabbInt& aabbOut)
{
    S4ef0Fpu4 zero;
    zero.setZero4();
    S4ef0Fpu4 maxVal = *reinterpret_cast<const S4ef0Fpu4*>(DAT_01060dd0);
    S4ef0U16x4 mi;
    S4ef0U16x4 ma;
    S4ef0ConvertToUint16WithClip(aabb.m_kMinimumCorner, offsetLow, scale, zero, maxVal, mi);
    S4ef0ConvertToUint16WithClip(aabb.m_kMaximumCorner, offsetHigh, scale, zero, maxVal, ma);
    aabbOut.m_kMinimumCorner[0] = mi.u16[0] & 0xfffe;
    aabbOut.m_kMinimumCorner[1] = mi.u16[1] & 0xfffe;
    aabbOut.m_kMinimumCorner[2] = mi.u16[2] & 0xfffe;
    aabbOut.m_kMaximumCorner[0] = ma.u16[0] | 1;
    aabbOut.m_kMaximumCorner[1] = ma.u16[1] | 1;
    aabbOut.m_kMaximumCorner[2] = ma.u16[2] | 1;
}

static __forceinline void S4ef0ConvertAabbToIntOwner(const S4ef0Owner* owner, const S4ef0Aabb& aabb, S4ef0AabbInt& aabbOut)
{
    S4ef0ConvertAabbToInt(aabb, owner->m_kVectorAt40, owner->m_kVectorAt50, owner->m_vScale, aabbOut);
}

static __forceinline void S4ef0PushPair(S4ef0Results& a, const S4ef0Pair& p) {
    if (a.m_iElementCount == a.getCapacity()) FUN_00901f10(&a, sizeof(S4ef0Pair));
    a.m_data[a.m_iElementCount] = p;
    a.m_iElementCount++;
}

struct S4ef0TempBitField {
 char* data;
 __forceinline explicit S4ef0TempBitField(int size);
 __forceinline ~S4ef0TempBitField();
};
__forceinline S4ef0TempBitField::S4ef0TempBitField(int size) {
 S4ef0Lifo* lifo=static_cast<S4ef0Lifo*>(DAT_00d9b080(DAT_010f3170));
 int bytes=(((size>>5)*4)+0x30)&~15;
 char* const top=lifo->m_pTop;
 char* const next=top+bytes;
 if(next<=lifo->m_pLimit){lifo->m_pTop=next;data=top;}else data=static_cast<char*>(lifo->Alloc(bytes));
}
__forceinline S4ef0TempBitField::~S4ef0TempBitField(){S4ef0Lifo* lifo=static_cast<S4ef0Lifo*>(DAT_00d9b080(DAT_010f3170));lifo->m_pTop=data;if(data==lifo->m_pBase)lifo->Free(data);}
}

// pdb: hkp3AxisSweep::querySingleAabb | hkp3AxisSweep.obj | tesv_win, caller_sim, low
void S4ef0Owner::FUN_00d14ef0(const S4ef0Aabb& aabb, S4ef0Results& pairsOut) const {
    int size=m_kNodeCollection.m_iElementCount;
    n991ee0::S4ef0TempBitField storage(size);
    char* bf=storage.data;
    unsigned int* bitField = static_cast<unsigned int*>(static_cast<void*>(bf));
    {
        n991ee0::S4ef0V4Local* d = static_cast<n991ee0::S4ef0V4Local*>(static_cast<void*>(bf));
        for (int c = size >> 7; c >= 0; c--) {
            n991ee0::S4ef0V4Local* e = d++;
            e->v[0] = 0.0f; e->v[1] = 0.0f; e->v[2] = 0.0f; e->v[3] = 0.0f;
        }
    }
    S4ef0AabbInt aabbInt;
    n991ee0::S4ef0ConvertAabbToIntOwner(this, aabb, aabbInt);
    const Entry* ep = &m_kAxisEndPoints[0][1];
    if (getNumMarkers()) {
        int value = aabbInt.m_kMinimumCorner[0];
        int pos = value >> (16 - m_iMarkerCapacity);
        if (pos > 0) {
            S4ef0Marker* marker = &m_pOverlappingMarkerInfo[pos - 1];
            S4ef0_staticFlipBit(bitField, marker->m_usIndex);
            const unsigned short* objects = marker->m_kMarkerIndices.begin();
            for (int i = marker->m_kMarkerIndices.GetLogicalSize() - 1; i >= 0; i--) { S4ef0_staticFlipBit(bitField, *objects); objects++; }
            const S4ef0Node& node = m_kNodeCollection[marker->m_usIndex];
            ep = &m_kAxisEndPoints[0][node.m_usValue08 + 1];
            const Entry* end = &m_kAxisEndPoints[0][node.m_usValue0A];
            for (; ep < end; ep++) { if (!(ep->key & 1)) S4ef0_staticClearBit(bitField, ep->value); }
            ep = &m_kAxisEndPoints[0][node.m_usValue08 + 1];
        }
    }
    for (; ep->key < aabbInt.m_kMinimumCorner[0]; ep++) { S4ef0_staticFlipBit(bitField, ep->value); }
    for (; ep->key < aabbInt.m_kMaximumCorner[0]; ep++) { if (!(ep->key & 1)) S4ef0_staticFlipBit(bitField, ep->value); }
    S4ef0Node refNode;
    {
        const S4ef0Axis& axis = m_kAxisEndPoints[1];
        const Entry* start = &axis[0];
        refNode.m_usValue00 = (unsigned short)(axis.LowerBoundEntry(start + 1, axis.end() - 2, (unsigned short)aabbInt.m_kMinimumCorner[1]) - start);
        refNode.m_usValue04 = (unsigned short)(axis.LowerBoundEntry(start + 1, axis.end() - 2, (unsigned short)aabbInt.m_kMaximumCorner[1]) - (start + 1));
    }
    {
        const S4ef0Axis& axis = m_kAxisEndPoints[2];
        const Entry* start = &axis[0];
        refNode.m_usValue02 = (unsigned short)(axis.LowerBoundEntry(start + 1, axis.end() - 2, (unsigned short)aabbInt.m_kMinimumCorner[2]) - start);
        refNode.m_usValue06 = (unsigned short)(axis.LowerBoundEntry(start + 1, axis.end() - 2, (unsigned short)aabbInt.m_kMaximumCorner[2]) - (start + 1));
    }
    {
        S4ef0Pair pair;
        pair.m_kPointA = 0;
        const S4ef0Node* nodes = &m_kNodeCollection[0];
        const unsigned int* bitFieldEnd = bitField;
        const unsigned int* bp = bitField;
        bitFieldEnd += (m_kNodeCollection.GetLogicalSize() >> 5) + 1;
        for (; bp < bitFieldEnd; nodes += 32, bp++) {
            unsigned int bits = *bp;
            if (!bits) continue;
            const S4ef0Node* n = nodes;
            do {
                if (bits & 0xf) {
                    if (bits & 1) {
                        if (!n[0].yzDisjoint(refNode) && !n[0].isMarker()) {
                            pair.m_kPointB = n[0].m_handle;
                            n991ee0::S4ef0PushPair(pairsOut, pair);
                        }
                    }
                    if (bits & 2) {
                        if (!n[1].yzDisjoint(refNode) && !n[1].isMarker()) {
                            pair.m_kPointB = n[1].m_handle;
                            n991ee0::S4ef0PushPair(pairsOut, pair);
                        }
                    }
                    if (bits & 4) {
                        if (!n[2].yzDisjoint(refNode) && !n[2].isMarker()) {
                            pair.m_kPointB = n[2].m_handle;
                            n991ee0::S4ef0PushPair(pairsOut, pair);
                        }
                    }
                    if (bits & 8) {
                        if (!n[3].yzDisjoint(refNode) && !n[3].isMarker()) {
                            pair.m_kPointB = n[3].m_handle;
                            n991ee0::S4ef0PushPair(pairsOut, pair);
                        }
                    }
                }
                n += 4; bits >>= 4;
            } while (bits);
        }
    }
}


inline void* __cdecl operator new(unsigned int, void* storage) { return storage; }

static const __m128 batchSweepBias={65536.0f,65536.0f,65536.0f,65536.0f};
extern float DAT_011b3790[4];

struct BatchSweepAllocator {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void* AllocateBufferWithSize(int& bytes) throw();
    virtual void ReturnMemory(void* memory, int bytes) throw();
    template<class T> __forceinline T* _bufAlloc(int& count) throw() {
        int bytes=count*(int)sizeof(T);
        void* memory=AllocateBufferWithSize(bytes);
        count=bytes/(int)sizeof(T);
        return (T*)memory;
    }
};

template<class T> __forceinline T* allocateSweep(BatchSweepAllocator& allocator, int count, int& capacity) {
    T* result = count ? allocator._bufAlloc<T>(count) : 0;
    capacity = count ? count : (int)0x80000000;
    return result;
}
struct SweepVector {
    __m128 v;
    __forceinline void operator=(const SweepVector& value){v=value.v;}
    __forceinline void setMin(const SweepVector& a,const SweepVector& b) {v=_mm_min_ps(a.v,b.v);}
    __forceinline void setMax(const SweepVector& a,const SweepVector& b) {v=_mm_max_ps(a.v,b.v);}
    __forceinline void setAdd(const SweepVector& a,const SweepVector& b) {v=_mm_add_ps(a.v,b.v);}
    __forceinline void mul(const SweepVector& a) {v=_mm_mul_ps(v,a.v);}
    __forceinline void add(const SweepVector& a) {v=_mm_add_ps(v,a.v);}
};
union ShortResult {__m128 vector;unsigned short values[4];short signedValues[4];unsigned int pairs[2];__int64 wide;};
__forceinline void convertSweepBound(const SweepVector& input,const SweepVector& offset,const SweepVector& scale,const SweepVector& min,const SweepVector& max,ShortResult& out) {
    SweepVector value;
    value.setAdd(input,offset);value.mul(scale);value.setMin(value,max);value.setMax(value,min);
    SweepVector bias;bias.v=batchSweepBias;value.add(bias);
    union {__m128 v;unsigned int words[4];} bits;
    bits.v=value.v;
    out.values[0]=(unsigned short)(bits.words[0]>>7);
    out.values[1]=(unsigned short)(bits.words[1]>>7);
    out.values[2]=(unsigned short)(bits.words[2]>>7);
}
struct BatchAabb { SweepVector low,high;
 __forceinline void include(const BatchAabb& other) {low.setMin(low,other.low);high.setMax(high,other.high);}
};
struct __declspec(align(16)) QuantBatchAabb {
    unsigned int low[3];
    unsigned char expandLowX,expandLowY,expandLowZ,expandShift;
    unsigned int high[3];
    unsigned char expandHighX,expandHighY,expandHighZ,shapeByte;
};
struct __declspec(align(16)) SweepLowShorts { unsigned short x,y,z,w; };

struct Holder { void* p; int a; int b; BatchSweepAllocator* allocObj; void* f10; };

struct SweepBatchNode;
template<class T> __forceinline void destroySweepRange(T* p,int n) {for(int k=0;k<n;++k)p[k].~T();}
template<class T> __forceinline void initializeSweepRange(T* p,int n) {for(int k=0;k<n;++k)::new(p+k) T;}

template<class T> struct SweepStorageBase {
 T* data;int size;int capacity;
 __forceinline SweepStorageBase():data(0),size(0),capacity(0x80000000){}
 __forceinline void own(T* pointer,int count,int flags){this->data=pointer;this->size=count;this->capacity=flags;}
 __forceinline T& operator[](int i){return data[i];}
 __forceinline void setSizeUnchecked(int n){destroySweepRange(data+n,size-n);initializeSweepRange(data+size,n-size);size=n;}
 __forceinline T* begin(){return data;}
};
struct SweepStackPolicy {__forceinline BatchSweepAllocator& get(const void*){Holder* h=(Holder*)FUN_00c85750();return *h->allocObj;}};
template<class T> struct SweepBuffer:SweepStorageBase<T> {
    __forceinline T& operator[](int i){return data[i];}
    __forceinline SweepBuffer(int count) :SweepStorageBase<T>() {
        BatchSweepAllocator& allocator=SweepStackPolicy().get(this);
        T* pointer=count ? allocator._bufAlloc<T>(count) : 0;
        int flags=count ? count : (int)0x80000000;
        own(pointer,count,flags);initializeSweepRange(data,count);
    }
    __forceinline SweepBuffer(int count,SweepBatchNode** nodes,void*& baseOut) :SweepStorageBase<T>() {
        BatchSweepAllocator& allocator=SweepStackPolicy().get(this);
        T* pointer;
        if(count){int bytes=count*(int)sizeof(T);pointer=(T*)allocator.AllocateBufferWithSize(bytes);count=bytes/(int)sizeof(T);}else {pointer=0;}
        int flags;if(count){flags=count;baseOut=*nodes;}else{flags=0x80000000;baseOut=*nodes;}
        own(pointer,count,flags);initializeSweepRange(data,count);
    }
};

struct SweepObjectHandle {unsigned int id;};
struct SweepBatchNode {
 unsigned short minY,minZ,maxY,maxZ,minX,maxX;
 SweepObjectHandle* handle;
 __forceinline unsigned int disjointYZ(const SweepBatchNode& other) const {
  unsigned int first=(*(const unsigned int*)&maxY)-(*(const unsigned int*)&other.minY);
  unsigned int second=(*(const unsigned int*)&other.maxY)-(*(const unsigned int*)&minY);
  return (first|second)&0x80008000;
 }
 __forceinline int isMarker() const {return (unsigned int)handle&1;}
};

struct Arr:SweepStorageBase<SweepBatchNode*> {
 __forceinline void clear(BatchSweepAllocator& alloc) {
   size=0;if(!(capacity&0x80000000))alloc.ReturnMemory(data,(capacity&0x3fffffff)*4);
   data=0;capacity=0x80000000;
 }
 __forceinline void clearAndFree() {Holder* holder=(Holder*)FUN_00c85750();clear(*holder->allocObj);}
};
struct SortArr15 {
    Endpoint* data; int size; int cap;
    __declspec(noinline) void* LowerBoundEntry(void* begin, void* end, int thresh);
    int InsertEndpoints(void* base, int idx, void* ptr, int savedN);
    int MergeSortedEndpoints(void* base, int out, void* ptr, int savedN);
    int FUN_00d19e40(void* base, int out, void* ptr, int savedN);
    int FUN_00d19ef0(void* base, int out, void* ptr, int savedN);
};
__declspec(noinline) void* SortArr15::LowerBoundEntry(void* begin,void* end,int thresh) {
 Endpoint* first=(Endpoint*)begin;Endpoint* last=(Endpoint*)end;
 unsigned short key=(unsigned short)thresh;
 while(last-first>16){Endpoint* middle=first+((last-first)>>1);if(middle->value<key)first=middle;else last=middle;}
 while(first->value<key)++first;
 return first;
}

void __cdecl FUN_00c908c0(void* a, void* b, int c, int d);
struct EndpointOrder { };
void __cdecl FUN_00d19fa0(void* a, int b, int c, EndpointOrder d);
void __cdecl CollectNodePairs(void* a, void* b, int c, int d);
