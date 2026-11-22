#include "f3_common.h"
// src/havok/common/serialize/util/hkstructurelayout.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkstructurelayout.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dc1680
{
    int m_uiFilterValue;

    FUN_00dc1680(const FUN_00dc1680& other);
};

// @fnv 0x00dc1680
// pdb: hkMonitorStreamStringMap::hkMonitorStreamStringMap | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkStructureLayout::hkStructureLayout)
FUN_00dc1680::FUN_00dc1680(const FUN_00dc1680& other) : m_uiFilterValue(other.m_uiFilterValue)
{}

struct Provider
{
    int unk00, unk04, value8;
    __declspec(noinline) int FUN_00d470d0();
};
struct Owner
{
    unsigned int unk00;
    Provider* provider4;
    unsigned int unk08;
    unsigned char unk0c, tag0d;
    unsigned short unk0e;
    __declspec(noinline) int FUN_00d86b30();
    __declspec(noinline) Provider* FUN_00d86910();
    int GetTagValue();
};
struct DataBufferInfo
{
    short value;
    unsigned short unk02;
    unsigned int unk04, unk08;
};
extern "C" DataBufferInfo g_011b6ab8[];
__declspec(noinline) int Owner::FUN_00d86b30()
{
    return tag0d;
}
__declspec(noinline) Provider* Owner::FUN_00d86910()
{
    return provider4;
}
__declspec(noinline) int Provider::FUN_00d470d0()
{
    return value8;
}
// Returns -1 for tags 0x18/0x1f, the provider's value8 for tag 0x19, otherwise g_011b6ab8[tag].value.
// @fnv 0x00d86b40
// pdb: hkClassMember::getArrayMemberSize | hkClassMember.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
int Owner::GetTagValue()
{
    if (FUN_00d86b30() == 0x18 || FUN_00d86b30() == 0x1f)
        return -1;
    if (FUN_00d86b30() != 0x19)
        return g_011b6ab8[FUN_00d86b30()].value;
    return FUN_00d86910()->FUN_00d470d0();
}

struct SizeNode;

struct SizeNodeList
{
    int hkClass_getNumMembers();
    SizeNode* FUN_00d46f20(int index);
};

struct SizeNode
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;

    int GetAlignment();
    SizeNodeList* FUN_00d86910();
};

// Returns a value for the node based on its type, recursing for types 19 and 25, then clamps it to a minimum derived from node->unk10 flags.
// @f3 0x009b2710 (community match, verified in this file)
struct SizeNodeListY
{
    int FUN_009b0630();
    SizeNode* FUN_009b0650(int index);
};
struct SizeNodeY
{
    SizeNodeListY* FUN_0093d890();
};
// pdb: getLayoutAlignment | hkStructureLayout.obj | fnv360_0822_retail, call_gap, high
extern "C" int __cdecl FUN_00dc1850(SizeNode* node, int type, int fallback)
{
    int result = -1;
    switch (type)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 24:
    case 31:
        result = node->GetAlignment();
        break;
    case 20:
    case 21:
    case 22:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
        result = fallback;
        break;
    case 19: {
        int t = node->unk0D;
        result = FUN_00dc1850(node, t, fallback);
    }
    break;
    case 25: {
        int best = 1;
        SizeNodeListY* list = ((SizeNodeY*)node)->FUN_0093d890();
        for (int iIndex = 0; iIndex < list->FUN_009b0630(); iIndex++)
        {
            SizeNode* child = list->FUN_009b0650(iIndex);
            int t = child->unk0C;
            int r = FUN_00dc1850(child, t, fallback);
            if (r > best)
                best = r;
        }
        result = best;
        break;
    }
    }
    int flags = node->unk10 & 0x180;
    if (flags)
    {
        int minimum = (flags == 0x100) ? 16 : 8;
        if (minimum > result)
            result = minimum;
    }
    return result;
}

struct Log_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a, unsigned int b, char* c, const char* d, int e);
};

struct StrBuf_cls
{
    int m_00;
    int m_04;
    int m_08;
    void Init(void* buf, unsigned int n);
    void Assign(const char* s);
    void Free();
};

struct Lay_cls
{
    int unk00;
    int unk04;
    int unk08;
    char unk0c;
    unsigned char m_type;
    int F86980();
    int F86940();
    int F86910();
};
struct Mem_cls
{
    int F470d0();
};

extern Log_cls* DAT_01268360;
int computeMemberSize(Lay_cls* a1, unsigned char* a2, int a3);

// Returns the byte size of a structure member based on its type code, recursing for type 18 and logging an error for unknown types.
// @f3 0x009b2550 (community match, verified in this file)
// pdb: computeMemberSize | hkStructureLayout.obj | fnv360_0822_retail, ustr, high
// pdb: computeMemberSize | hkStructureLayout.obj | fnv360_0822_retail, ustr, high (was: GetMemberSize)
int computeMemberSize(Lay_cls* pLayout, unsigned char* pMemberData, int iType)
{
    int r = 0;
    switch (iType - 1)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 23:
    case 30:
        r = pLayout->F86980();
        break;
    case 19:
    case 20:
    case 28:
    case 29: {
        int m = *pMemberData;
        r = (pLayout->F86940() != 0 ? pLayout->F86940() : 1) * m;
        break;
    }
    case 27:
        r = *pMemberData * 2;
        break;
    case 21:
        r = 4;
    case 25:
        r = r + *pMemberData + 4;
        break;
    case 24: {
        int m = ((Mem_cls*)(pLayout->F86910()))->F470d0();
        r = (pLayout->F86940() != 0 ? pLayout->F86940() : 1) * m;
        break;
    }
    case 22:
        break;
    case 18: {
        int t = pLayout->m_type;
        r = computeMemberSize(pLayout, pMemberData, t);
        break;
    }
    case 26:
        r = *pMemberData * 2 + 4;
        break;
    default: {
        unsigned int buf[0x80];
        StrBuf_cls s;
        s.Init(buf, 0x200);
        s.Assign("Unknown class member type in structureLayout::getMemberSize().");
        DAT_01268360->v3(3, 0x50a18b58, (char*)buf, ".\\Util\\hkStructureLayout.cpp", 0xc2);
        s.Free();
        break;
    }
    }
    return r;
}


struct FUN_00cb18f0_Obj
{
    int unk00;
    int unk04;
    int unk08;

    int __thiscall FindSlot(int value);
};

extern "C" void __cdecl retargetClassInplace(unsigned int value1, void* value2, void* value3, int value4);

class FUN_00dc1bb0_Class
{
  public:
    void hkStructureLayout_computeMemberOffsetsInplace(unsigned int param1, unsigned int param2);
};

// Calls FindSlot on the object with param1 and, if the result exceeds object->unk08, calls retargetClassInplace with this, object and param3.
// @f3 0x009b2a50 (community match, verified in this file)
extern "C" void __cdecl FUN_009b2810(unsigned int value1, void* value2, void* value3);

// pdb: hkStructureLayout::computeMemberOffsetsInplace | hkStructureLayout.obj | fnv360_0822_retail, call_gap_sim + bridge(call_gap|call_seq) + skyrim(call_seq), high
void FUN_00dc1bb0_Class::hkStructureLayout_computeMemberOffsetsInplace(unsigned int uiValue, unsigned int pObject)
{
    FUN_00cb18f0_Obj* object = reinterpret_cast<FUN_00cb18f0_Obj*>(pObject);
    int result = object->FindSlot(uiValue);

    if (result > object->unk08)
    {
        FUN_009b2810(uiValue, this, object);
    }
}


enum MemberKind
{
    KindNone = 0
};
template <class E, class S> struct EnumStorage
{
    S value;
    EnumStorage()
    {}
    EnumStorage(E v) : value((S)v)
    {}
    operator E() const
    {
        return (E)value;
    }
};
struct ByteBool
{
    char value;
    ByteBool(bool v) : value((char)v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct LayoutOptions
{
    unsigned char pointerBytes, littleEndian, reusePadding, emptyBase;
};
struct Allocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* ptr, int size);
};
struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    Allocator* allocator;
    void* unk10;
};
extern "C" Manager* __cdecl FUN_00c85750();
struct NodeListEx;
struct NodeEx
{
    const char* name;
    const NodeListEx* child;
    const void* enumeration;
    EnumStorage<MemberKind, unsigned char> unk0C;
    EnumStorage<MemberKind, unsigned char> unk0D;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    int ReadWorldData() const
    {
        return unk12;
    }
    void SetOffset(int v)
    {
        unk12 = (unsigned short)v;
    }
    MemberKind ReadType() const
    {
        return (MemberKind)unk0C;
    }
    int GetAlignment();
    NodeListEx* FUN_00d86910();
};
struct NodeListEx
{
    const char* name;
    const NodeListEx* parent;
    int objectSize;
    int interfaceCount;
    const void* enums;
    int enumCount;
    const NodeEx* members;
    int memberCount;
    const void* defaults;
    const void* attributes;
    unsigned int flags;
    int version;
    int hkClass_getNumMembers() const;
    const NodeEx& FUN_00d46f60(int index) const;
    const NodeListEx* FUN_00d46d50() const;
    int hkpMoppShapeMediator_getNumPrimitives() const;
    int FUN_00d46f70() const;
    const NodeEx& FUN_00d46f80(int index) const;
    int FUN_00d470d0() const;
    void hkpCharacterContext_setCharacterType(int val);
};
struct Arg2
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1870(void* unk10, NodeListEx* list, int zero);
    int FindSlot(NodeListEx* sublist);
    ByteBool Valid(int i) const
    {
        return i <= unk08;
    }
    ByteBool IsMissing(NodeListEx* p)
    {
        return !Valid(FindSlot(p));
    }
};
struct Array
{
    NodeListEx** m_data;
    int m_iElementCount;
    int m_pRayCursor;
    void CallWithFlag(Allocator* allocator, int index, NodeListEx* const& item);
    void Free()
    {
        Manager* mgr = FUN_00c85750();
        Allocator* alloc = mgr->allocator;
        int cap = m_pRayCursor;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->Free(m_data, (cap & 0x3fffffff) * sizeof(NodeListEx*));
        }
    }
};
// Recursively visits child node lists, then computes and stores member offsets and total size for each node list based on layout options.
// @f3 0x009b2810 (community match, verified in this file)
struct NL215;
struct NE215
{
    const void* unk00;
    NL215* child;
    const void* unk08;
    EnumStorage<MemberKind,unsigned char> unk0c;
    MemberKind ReadType()const{return (MemberKind)unk0c;}
    unsigned char unk0d;
    unsigned short unk0e;
    unsigned short unk10;
    short unk12;
    NL215* FUN_0093d890();
};
struct NL215
{
    const char* name;
    const NL215* parent;
    int objectSize;
    int interfaceCount;
    const void* enums;
    int enumCount;
    const NE215* members;
    int memberCount;
    const void* defaults;
    const void* attributes;
    unsigned int flags;
    int version;
    int FUN_009b0630();
    NE215& hkClass_getMember(int index);
    const NL215* FUN_009b04a0() const;
    int FUN_009b0560();
    int FUN_009b06a0();
    NE215* FUN_009b06b0(int index);
    void FUN_009b0770(int val);
};
struct Vis215
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00922710(NL215* list, int zero);
    int FUN_00922790(NL215* sublist);
    ByteBool Valid(int i)const{return i<=unk08;}
    ByteBool IsMissing(NL215* p){return !Valid(FUN_00922790(p));}
};
extern unsigned int DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Alloc215
{
    void FUN_008f6d90(void* ptr, int size, int flag);
    static Alloc215& getInstance();
};
struct Arr215
{
    NL215** m_data;
    int m_iElementCount;
    int m_pRayCursor;
    Arr215() : m_data(0), m_iElementCount(0), m_pRayCursor(0x80000000) {}
    int getSize() const { return m_iElementCount; }
    int getCapacity() const { return m_pRayCursor & 0x3fffffff; }
    NL215*& operator[](int i) { return m_data[i]; }
    void FUN_009b2b40(int index, NL215* const& item);
    void releaseMemory()
    {
        if ((m_pRayCursor & 0x80000000) == 0)
        {
            Alloc215::getInstance().FUN_008f6d90(m_data, getCapacity() * (int)sizeof(NL215*), 0x17);
        }
    }
};
inline Alloc215& Alloc215::getInstance() { return *(Alloc215*)DAT_00d9b080(DAT_010f3170); }
int __cdecl FUN_009b2710(NE215* node, int type, int fallback);
int __cdecl FUN_009b2550(NE215* node, const LayoutOptions* options, int type);
// pdb: retargetClassInplace | hkStructureLayout.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_gap) + skyrim(call_seq), high
void __cdecl retargetClassInplace(NodeListEx& root, const LayoutOptions& options, Arg2& visited, int arg3)
{
    ((Vis215*)&visited)->FUN_00922710((NL215*)&root, 0);
    int count = ((NL215*)&root)->FUN_009b0630();
    for (int i = 0; i < count; ++i)
    {
        NE215& member = ((NL215*)&root)->hkClass_getMember(i);
        if (member.child && ((Vis215*)&visited)->IsMissing(member.FUN_0093d890()))
        {
            // recursion uses the pack three-argument bridge; the definition keeps its four-argument form.
            FUN_009b2810((unsigned int)member.FUN_0093d890(), (void*)&options, (void*)&visited);
        }
    }
    Arr215 hier;
    {
        const NL215* cl = (NL215*)&root;
        while (cl)
        {
            hier.FUN_009b2b40(0, const_cast<NL215*>(cl));
            cl = cl->FUN_009b04a0();
        }
    }
    int currentOffset = 0;
    int biggestAlignSoFar = 1;
    const int alignmentOfPointer = options.pointerBytes;
    const int sizeOfPointer = options.pointerBytes;
    for (int hierIdx = 0; hierIdx < hier.getSize(); ++hierIdx)
    {
        NL215& klass = *hier[hierIdx];
        for (int interfaceIdx = 0; interfaceIdx < klass.FUN_009b0560(); ++interfaceIdx)
        {
            if (currentOffset % alignmentOfPointer)
            {
                currentOffset -= currentOffset % alignmentOfPointer;
                currentOffset += alignmentOfPointer;
            }
            currentOffset += sizeOfPointer;
            if (alignmentOfPointer > biggestAlignSoFar)
            {
                biggestAlignSoFar = alignmentOfPointer;
            }
        }
        for (int memIdx = 0; memIdx < klass.FUN_009b06a0(); ++memIdx)
        {
            NE215& member = *klass.FUN_009b06b0(memIdx);
            if (currentOffset == 0 && hierIdx != 0 && options.emptyBase == 0)
            {
                currentOffset = 1;
            }
            int memberAlign = FUN_009b2710(&member, member.ReadType(), options.pointerBytes);
            if (memberAlign > biggestAlignSoFar)
            {
                biggestAlignSoFar = memberAlign;
            }
            if (currentOffset % memberAlign)
            {
                currentOffset -= currentOffset % memberAlign;
                currentOffset += memberAlign;
            }
            member.unk12 = (short)currentOffset;
            currentOffset += FUN_009b2550(&member, &options, member.ReadType());
        }
        int paddedOffset = currentOffset;
        if (paddedOffset % biggestAlignSoFar)
        {
            paddedOffset -= paddedOffset % biggestAlignSoFar;
            paddedOffset += biggestAlignSoFar;
        }
        klass.FUN_009b0770(paddedOffset ? paddedOffset : 1);
        if (options.reusePadding == 0)
        {
            currentOffset = paddedOffset;
        }
    }
    hier.releaseMemory();
}

