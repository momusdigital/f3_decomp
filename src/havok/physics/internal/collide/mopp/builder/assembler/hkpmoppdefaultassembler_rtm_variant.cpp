// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl hkpMoppCodeGenerator_resize();
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
typedef void(__thiscall* FlushFunction)(void*);
template <class T> inline T S_00e07040_Max(T a, T b)
{
    return a > b ? a : b;
}
struct S_e07c50_Item;
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
// The class the member belongs to.  The unit's FUN_00e06780_class carries
// no data members, so the flag field lives in the derived stand-in.
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
extern "C" void __cdecl hkpMoppCodeGenerator_resize();
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
// FUN_00e09540 - compute the level of an object from its bounding box.
//
// this : the object
//   +0x08 : the resulting level (a byte-sized value in the original)
//   +0x0c/+0x10, +0x14/+0x18, +0x1c/+0x20 : the three axis bounds
//
// The largest of the three axis extents is taken, the number of bits it
// needs is counted and the level is derived from that; the result is
// clamped to 0x18.
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
// Emit an opcode with an immediate, choosing the byte, short or int form (and its opcode offset) by value range.
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
struct Pair
{
    int m_ucLowNibble;
    int m_ucHighNibble;
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
#include <xmmintrin.h>
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
static void FUN_00e08320(e083::PairArray* srcp, e083::PairArray* dst, int delta);
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
void __stdcall hkpMoppDefaultAssembler_assembleCutAndTerminalCommand(struct BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack);
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
static int FUN_00e08380(BvTree* tree, FUN_00e065f0* source, BvArray<int>* refs, FUN_00e065f0* destination);
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
struct CodeCopySource : FUN_00e065f0
{
};
static int FUN_00e08380(BvTree* tree, CodeCopySource* source, BvArray<int>* refs, FUN_00e065f0* destination);
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

namespace E078Intrinsics {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ss(float*, __m128);
    float _mm_cvtss_f32(__m128);
    __m128 _mm_load_ss(const float*);
}
}
typedef E078Intrinsics::__m128 E078Quad;

typedef float hkReal;

struct ScalarLane
{
    E078Quad data;
    __forceinline ScalarLane(float x)
    {
        data = E078Intrinsics::_mm_load_ss(&x);
    }
    __forceinline E078Quad splat() const
    {
        return E078Intrinsics::_mm_shuffle_ps(data, data, 0);
    }
};

struct hkVector4
{
    E078Quad m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_vComponents = E078Intrinsics::_mm_setr_ps(x, y, z, w);
    }
    __forceinline void mul4(const ScalarLane& s)
    {
        m_vComponents = E078Intrinsics::_mm_mul_ps(s.splat(), m_vComponents);
    }
    __forceinline void add4(const hkVector4& v)
    {
        m_vComponents = E078Intrinsics::_mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void add4(const E078Quad& v)
    {
        m_vComponents = E078Intrinsics::_mm_add_ps(m_vComponents, v);
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    {
        E078Quad x2 = E078Intrinsics::_mm_mul_ps(m_vComponents, v.m_vComponents);
        E078Quad xy = E078Intrinsics::_mm_add_ss(E078Intrinsics::_mm_shuffle_ps(x2, x2, 0x55), x2);
        E078Quad xyz = E078Intrinsics::_mm_add_ss(E078Intrinsics::_mm_shuffle_ps(x2, x2, 0xaa), xy);
        float out;
        E078Intrinsics::_mm_store_ss(&out, xyz);
        return out;
    }
};

struct hkVector4Unaligned
{
    hkReal x, y, z, w;
};

union hkVector4Copy
{
    hkVector4Unaligned m_v;
    E078Quad m_q;
};

hkReal hkMath_hkFloor(hkReal f);
int hkMath_hkFloatToInt(hkReal f);
int FUN_00cbfe20(hkReal f);

struct QuantNode
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
    const hkVector4* m_vHitNormal;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
};

struct KdRegion
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
    int m_iIndex;
    int m_offset[3];
};

struct KdQuantizer
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
    hkVector4Unaligned m_vRayOrigins;

    void hkpMoppDefaultAssembler_findPlanes(const QuantNode* node, const KdRegion* region, int* hiOut, int* loOut);
};

static __forceinline int toCell(hkReal scale, double x)
{
    return hkMath_hkFloatToInt(hkMath_hkFloor(x * scale));
}

static __forceinline int clampIndex(int i)
{
    if (i <= 0)
    {
        return 0;
    }
    if (i >= 255)
    {
        return 255;
    }
    return i;
}

// @f3 0x00a87330 (community match, verified in this file)
extern const double DAT_00dc0ac0;
extern const double DAT_00e88620;
extern float __cdecl FUN_00954ba0(float);
extern int __cdecl FUN_00954d20(float);
extern int __cdecl FUN_00954c40(float);
static __forceinline int QuantizeCellNative(float scale,double x) {
    return FUN_00954d20(FUN_00954ba0(float(x*scale)));
}
// pdb: hkpMoppDefaultAssembler::findPlanes | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, uconst + bridge(uconst|uconst) + skyrim(uconst), high
void KdQuantizer::hkpMoppDefaultAssembler_findPlanes(const QuantNode* node, const KdRegion* region, int* hiOut, int* loOut)
{
    const hkReal* n = &node->m_vHitNormal->m_vComponents.m128_f32[0];
    int numNonZero;
    numNonZero = 0;
    int numNegative = 0;
    int axis = 0;
    for (int i = 0; i < 3; i++)
    {
        hkReal c;
        c = n[i];
        if (c != 0.0f)
        {
            axis = i;
            numNonZero++;
            if (c < 0.0f)
            {
                numNegative += 1;
            }
        }
    }

    double minDist = node->m_kMinimumCorner;
    double maxDist = node->m_kMaximumCorner;

    if (numNonZero == 1)
    {
        long lo;
        const hkReal* origin;
        origin = &m_vRayOrigins.x;
        lo = QuantizeCellNative(m_vRayOrigins.w, minDist - origin[axis]);
        int hi;
        hi = QuantizeCellNative(m_vRayOrigins.w, maxDist - origin[axis]);
        int offset = region->m_offset[axis];
        lo = (lo - offset) >> region->m_iIndex;
        hi = ((hi - offset) >> region->m_iIndex) + 1;
        lo = clampIndex(lo);
        hi = clampIndex(hi);
        *loOut = lo;
        *hiOut = hi;
        if (*loOut < 0)
        {
            *loOut = 0;
        }
        return;
    }

    hkVector4Copy origin;
    hkVector4Unaligned translated = {float(region->m_offset[0]),float(region->m_offset[1]),float(region->m_offset[2]),0.0f};
    origin.m_v = m_vRayOrigins;
    float inv = (float)(1.0 / m_vRayOrigins.w);
    origin.m_v.x = translated.x * inv + origin.m_v.x;
    origin.m_v.y = *(const volatile float*)&translated.y * inv + origin.m_v.y;
    origin.m_v.z = inv * translated.z + origin.m_v.z;
    double d = (float)((*(const volatile hkReal*)(n + 1) * origin.m_v.y + n[0] * origin.m_v.x) + n[2] * origin.m_v.z);

    hkReal cellSize;
    cellSize = (hkReal)(1 << region->m_iIndex);
    double lo = (minDist - d) * m_vRayOrigins.w / cellSize;
    maxDist = (maxDist - d) * m_vRayOrigins.w / cellSize;

    double stretch = 1.0;
    double norm = 1.0;
    if (numNonZero == 2)
    {
        stretch = DAT_00dc0ac0;
        norm = 0.5;
    }
    else if (3 == numNonZero)
    {
        stretch = DAT_00e88620;
        norm = 0.3333333432674408;
    }

    double dlo = lo * stretch;
    maxDist *= stretch;
    if (numNegative)
    {
        dlo += numNegative * 255;
        maxDist += numNegative * 255;
    }

    int ilo = FUN_00954c40((hkReal)(dlo * norm));
    int ihi = FUN_00954c40((hkReal)(maxDist * norm)) + 1;
    ilo = clampIndex(ilo);
    ihi = clampIndex(ihi);
    *loOut = ilo;
    *hiOut = ihi;
}

