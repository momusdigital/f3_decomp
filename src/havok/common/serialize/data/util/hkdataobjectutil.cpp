#include "f3_common.h"
// src/havok/common/serialize/data/util/hkdataobjectutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/util/hkdataobjectutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dc35e0_class
{
    int __thiscall FUN_00dc35e0();
};

struct S_00dc3ce0_Allocator
{
    int unk0;
};

struct S_00dc3ce0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dc3ce0_Allocator* m_pStreamAllocator;
    static S_00dc3ce0_Router& FUN_00c85750();
    S_00dc3ce0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

void ResizeAudioStream(S_00dc3ce0_Allocator& alloc, void* array, int sizeElem);

struct S_00dc3ce0_Entry
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    S_00dc3ce0_Entry(int a, int b, int c) : m_kPointA(a), m_kPointB(b), m_iThirdValue(c)
    {}
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00dc3ce0_Array
{
    S_00dc3ce0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(S_00dc3ce0_Allocator& alloc, const S_00dc3ce0_Entry& e)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(S_00dc3ce0_Entry));
        }
        new (m_data + m_iElementCount) S_00dc3ce0_Entry(e);
        m_iElementCount++;
    }
    __forceinline void AddBack(const S_00dc3ce0_Entry& e)
    {
        AddBack(S_00dc3ce0_Router::FUN_00c85750().heap(), e);
    }
};

// @f3 0x00934540 (community match, verified in this file)
extern int DAT_00e31f48;
struct Pair_934540 { int x; int y; };
struct Vec_934540
{
    int unk00;
    int unk04;
    Vec_934540* FUN_0093d600(void* a, void* tag);
    Pair_934540* FUN_0093d810(Pair_934540* out);
};
int __cdecl FUN_00934440(Pair_934540* a, Pair_934540* b, void* c);

static __declspec(noinline) int FUN_009344d0(Vec_934540* q, Vec_934540* p, void* c)
{
    Pair_934540 t;
    Pair_934540 a;
    Pair_934540 b;
    a.x = q->FUN_0093d810(&t)->x;
    a.y = q->FUN_0093d810(&t)->y;
    b.x = p->FUN_0093d810(&t)->x;
    b.y = p->FUN_0093d810(&t)->y;
    return FUN_00934440(&b, &a, c);
}

int __cdecl FUN_00dc32c0(void* a1, void* a2, void* a3)
{
    Vec_934540 o1;
    Vec_934540 o2;
    return FUN_009344d0(o2.FUN_0093d600(a1, &DAT_00e31f48), o1.FUN_0093d600(a2, &DAT_00e31f48), a3);
}


struct GlobalObj_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c();
    virtual int v10();
};

extern GlobalObj_cls* DAT_01268b08;

extern "C" int __cdecl FUN_00dc32c0(int a1, int a2, int a3);

// Calls v0c on DAT_01268b08, then passes a1, obj->v10() and that result to FUN_00dc32c0 and returns its result.
// @f3 0x006103a0 (community match, verified in this file)
class LandscapeForm {
public:
 virtual void v000();
 virtual void v004();
 virtual void v008();
 virtual void v00c();
 virtual void v010();
 virtual void v014();
 virtual void v018();
 virtual void v01c();
 virtual void v020();
 virtual void v024();
 virtual void v028();
 virtual void v02c();
 virtual void v030();
 virtual void v034();
 virtual void v038();
 virtual void v03c();
 virtual void v040();
 virtual void v044();
 virtual void v048();
 virtual void v04c();
 virtual void v050();
 virtual void v054();
 virtual void v058();
 virtual void v05c();
 virtual void v060();
 virtual void v064();
 virtual void v068();
 virtual void v06c();
 virtual void v070();
 virtual void v074();
 virtual void v078();
 virtual void v07c();
 virtual void v080();
 virtual void v084();
 virtual void v088();
 virtual void v08c();
 virtual void v090();
 virtual void v094();
 virtual void v098();
 virtual void v09c();
 virtual void v0a0();
 virtual void v0a4();
 virtual void v0a8();
 virtual void v0ac();
 virtual void v0b0();
 virtual void v0b4();
 virtual void v0b8();
 virtual void v0bc();
 virtual void v0c0();
 virtual void v0c4();
 virtual void v0c8();
 virtual void v0cc();
 virtual void v0d0();
 virtual void v0d4();
 virtual void v0d8();
 virtual void v0dc();
 virtual void v0e0();
 virtual void v0e4();
 virtual void v0e8();
 virtual void v0ec();
 virtual void v0f0();
 virtual void v0f4();
 virtual void v0f8();
 virtual void v0fc();
 virtual void v100();
 virtual void v104();
 virtual void v108();
 virtual void v10c();
 virtual void v110();
 virtual void v114();
 virtual void v118();
 virtual void v11c();
 virtual void v120();
 virtual void v124();
 virtual void v128();
 virtual void v12c();
 virtual const char* GetName();
};
extern const char DAT_00e02a3c[];
int __cdecl FUN_00403230(char*,unsigned,const char*,...);
// pdb: BGSDistantObjectBlock::BuildBlockFileName | BGSDistantObjectBlock.obj | fnv360_0822_retail, ustr, medium
// pdb params: apOutput, apWorld, aiLevel, asCellX, asCellY
int __cdecl FUN_00dc3500(char* buffer,LandscapeForm* form,int level,short x,short y){
 return FUN_00403230(buffer,260,DAT_00e02a3c,form->GetName(),form->GetName(),level,x,y);
}


namespace fnv_00dc3530 {
extern int DAT_01268b08;

// @f3 0x00a498d0 (community match, verified in this file)
extern "C" int __cdecl hkString_strCmp(int key, int* table);
int* __cdecl FUN_0093e470();
struct Owner;
int __fastcall FUN_00dc3530(Owner* owner);
namespace fnv_00dc3530 { struct Owner; int __fastcall FUN_00dc3530(Owner* owner); }
int __fastcall ::fnv_00dc3530::FUN_00dc3530(::fnv_00dc3530::Owner* owner)
{
    return hkString_strCmp(*(int*)((char*)owner + 0x14), FUN_0093e470()) == 0;
}

}  // namespace fnv_00dc3530

void* __cdecl FUN_00c85750();

struct DC3600Key
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct DC3600MapOperations
{
    static unsigned hash(const DC3600Key& key, unsigned mod)
    {
        return (key.m_ucLowNibble >> 4) * 2654435761U & mod;
    }
    static bool isValid(const DC3600Key& key)
    {
        return key.m_ucLowNibble != 0xffffffff;
    }
    static bool equal(const DC3600Key& key0, const DC3600Key& key1)
    {
        return key0.m_ucLowNibble == key1.m_ucLowNibble && key0.m_ucHighNibble == key1.m_ucHighNibble;
    }
};

struct FUN_00dc36b0_cls
{
    struct HashEntry
    {
        unsigned int key0;
        unsigned int key1;
        unsigned int value;
    };

    HashEntry* m_pEntries;
    unsigned int m_u04;
    unsigned int m_uMask;

    unsigned int Lookup(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault);
};

namespace fnv_00dc43a0 {
struct DC43A0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct DC43A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DC43A0Allocator* m_pStreamAllocator;

    DC43A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DC43A0MemoryRouter& __cdecl FUN_00c85750();

struct DC43A0ReferencedObject
{
    void removeReference() const;
};

template <typename T> struct DC43A0RefPtr
{
    T* m_pRetainedObject;

    ~DC43A0RefPtr()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct DC43A0MapA
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ClearAndRelease(DC43A0Allocator& alloc);
    ~DC43A0MapA()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
};

struct DC43A0MapB
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ClearAndRelease(DC43A0Allocator& alloc);
    ~DC43A0MapB()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
};

struct DC43A0Pair
{
    int m_kPointA;
    int m_kPointB;
};

struct DC43A0PairArray
{
    DC43A0Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~DC43A0PairArray()
    {
        DC43A0Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(DC43A0Pair));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct FUN_00dc43a0
{
    DC43A0RefPtr<DC43A0ReferencedObject> m_pHeadNode;
    DC43A0RefPtr<DC43A0ReferencedObject> m_iSecondInteger;
    int unk08;
    DC43A0MapB m_mapB;
    DC43A0MapA m_mapA;
    DC43A0PairArray m_pairs;

    ~FUN_00dc43a0() throw();
};

// Destructor that destroys the two reference pointers, both maps and the pair array in reverse declaration order.
// @fnv 0x00dc43a0
FUN_00dc43a0::~FUN_00dc43a0() throw()
{}
}  // namespace fnv_00dc43a0

namespace fnv_00dc4f20 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iValue10;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00dc4f20

namespace fnv_00dc58a0 {
struct S_00dc58a0_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};
struct S_00dc58a0_Router
{
    int unk0;
    int unk4;
    int unk8;
    S_00dc58a0_Alloc* m_buf;
    S_00dc58a0_Alloc& buf()
    {
        return *m_buf;
    }
};
S_00dc58a0_Router* FUN_00c85750();

struct S_00dc58a0_Item
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};
struct S_00dc58a0_Arr
{
    S_00dc58a0_Item* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ClearAndRelease(S_00dc58a0_Alloc& a)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S_00dc58a0_Item));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

}  // namespace fnv_00dc58a0

struct S_00dc5970_Allocator;

struct S_00dc5970_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00dc5970_Allocator* m_pStreamAllocator;

    static S_00dc5970_Router& FUN_00c85750() throw();
    S_00dc5970_Allocator& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00dc5970_Handle
{
    void* p0;
    void* p1;
};

struct S_00dc5970_Map
{
    int LookupValue(S_00dc5970_Handle key, S_00dc5970_Handle* out) throw();                          // get
    void Insert(S_00dc5970_Allocator& alloc, S_00dc5970_Handle key, S_00dc5970_Handle val) throw();  // insert

    int get(S_00dc5970_Handle key, S_00dc5970_Handle* out) throw()
    {
        return LookupValue(key, out);
    }
    void insert(S_00dc5970_Handle key, S_00dc5970_Handle val) throw()
    {
        Insert(S_00dc5970_Router::FUN_00c85750().heap(), key, val);
    }
};

struct Pair_dc3
{
    unsigned int lo;
    unsigned int hi;
};
struct HashEntry
{
    Pair_dc3 key;
    Pair_dc3 val;
};

struct hkPairKeyDC37
{
    unsigned int m_k1;
    unsigned int m_k2;
    bool operator==(const hkPairKeyDC37& o) const
    {
        return m_k1 == o.m_k1 && m_k2 == o.m_k2;
    }
};

#include <xmmintrin.h>

typedef __m128 M128;

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct DObj
{
    int unk00;
    int FUN_00dba980() throw();
    void FUN_00dba7f0() throw();
    __forceinline ~DObj() throw()
    {
        FUN_00dba7f0();
    }
};

struct DValue
{
    int unk00;
    int unk04;
    int CallVirtualWithArg() throw();
    float hkOffsetOnlyStreamWriter_seek() throw();
    const float* DispatchToVTableSlot8(int n) throw();
    template <int Width> __forceinline const float* asVector() throw()
    {
        return DispatchToVTableSlot8(Width);
    }
    DObj CreateValueInto() throw();
};

struct DArray
{
    int FUN_00dbac00() throw();
    DValue FUN_00dbabb0(int i) throw();
};

struct DAllocator
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
};

struct DMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DAllocator* unk10;
};

__declspec(restrict) void* __cdecl FUN_00c85750() throw();

struct DMember
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;
};

struct DC3710Vector4
{
    __m128 m_vComponents;

    void operator=(const DC3710Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

__forceinline void constructStrings(char** p, int n, char* const& str) throw()
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = str;
    }
}

struct StringArray
{
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(char* str) throw()
    {
        S_00dc3ce0_Router& r = S_00dc3ce0_Router::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(r.heap(), this, 4);
        }
        constructStrings(m_data + m_iElementCount, 1, str);
        m_iElementCount++;
    }
};

struct StringHolder
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
    StringArray m_pStringFunctions;
};

extern "C" char* __cdecl FUN_00cb1410(const char*) throw();

namespace fnv_00dc4fa0 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

struct StringArray
{
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(char* str) throw()
    {
        S_00dc3ce0_Router* r = &S_00dc3ce0_Router::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(*r->m_pStreamAllocator, this, sizeof(char*));
        char** p = m_data + m_iElementCount;
        __assume(p != 0);
        new (p) char*(str);
        m_iElementCount++;
    }
};

struct StringHolder
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
    StringArray m_pStringFunctions;
};

extern "C" char* __cdecl FUN_00cb1410(const char*) throw();

}  // namespace fnv_00dc4fa0

struct DCNode;
struct DCNode
{
    virtual void f0();
    virtual void f1();
    virtual DCNode* get();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int count();
    virtual void member(int, void*);
};
struct DCEntry
{
    int x[3];
    void* data;
    int size;
    int cap;
};
struct DCArray
{
    DCEntry* data;
    int size;
    int cap;
    void reserve(void*, int);
};
void __cdecl FUN_00c908c0(void*, DCArray*, int, int);
void __cdecl ResizeAudioStream(void*, DCArray*, int);

struct DWC_Allocator;
struct DWC_Router
{
    int unk0;
    int unk4;
    int unk8;
    DWC_Allocator* m_pTemp;

    static DWC_Router& FUN_00c85750() throw();
    DWC_Allocator& temp() throw()
    {
        return *m_pTemp;
    }
};
struct DWC_Allocator
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
void FUN_00c908c0(DWC_Allocator& alloc, void* array, int numElem, int sizeElem) throw();

struct DWC_ClassImpl;
struct DWC_ClassSource
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual DWC_ClassImpl* getImplementation() throw();
};
struct DWC_MemberInfo
{
    const char* m_name;
    int m_type;
    int m_tuple;
    DWC_ClassSource* m_class;
    const void* m_valuePtr;
    DWC_MemberInfo() throw() : m_name(0), m_type(0), m_tuple(0), m_class(0), m_valuePtr(0)
    {}
};
inline void* operator new(unsigned int, DWC_MemberInfo* p) throw()
{
    return p;
}

__forceinline void DWC_construct(DWC_MemberInfo* t, int n) throw()
{
    for (int i = 0; i < n; ++i)
    {
        ::new (t + i) DWC_MemberInfo();
    }
}

struct DWC_MemberArray
{
    DWC_MemberInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    DWC_MemberArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~DWC_MemberArray() throw()
    {
        _clearAndDeallocate(DWC_Router::FUN_00c85750().temp());
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    DWC_MemberInfo& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(DWC_Allocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(DWC_MemberInfo));
        }
    }
    __forceinline void GrowArrayCapacity(DWC_Allocator& alloc, int n) throw()
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(DWC_MemberInfo));
        }
    }
    __forceinline void _setSize(DWC_Allocator& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        DWC_construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(DWC_Router::FUN_00c85750().temp(), n);
    }
};

extern "C" void _ReadWriteBarrier(void);

struct Member355
{
    const char* name;
    void* typeInfo;
    void* enumInfo;
    unsigned char type;
    unsigned char subtype;
    unsigned short fixedCount;
    unsigned short flags;
    unsigned short offset;
    __forceinline const char* getName() const throw()
    {
        return name;
    }
    int FUN_00d86940() throw();
    int FUN_00d86980() throw();
    void* FUN_00d86920() throw();
};
struct ClassHandle355
{
    void* impl;
    void* FUN_00dba680() throw();
    void FUN_00dba660() throw();
};
struct Object355;
struct Value355;
struct Array355
{
    void* impl;
    int FUN_00dbac00() throw();
    Value355 FUN_00dbab90(int index) throw();
    ~Array355() throw();
};
struct Value355
{
    void* impl;
    int index;
    Array355 GetResult() throw();
    Object355 CreateValueInto() throw();
    Object355 FUN_00dba9d0() throw();
};
struct Object355
{
    void* impl;
    ClassHandle355* GetObjectValue(ClassHandle355* out) throw();
    int FUN_00dba910(const char* name) throw();
    Value355 FUN_00dba870(const char* name) throw();
    ~Object355() throw();
};
struct Allocator355
{
    virtual void f0() throw();
    virtual void f4() throw();
    virtual void f8() throw();
    virtual void* allocate(int& bytes) throw();
};
struct Router355
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator355* heap;
    static Router355& FUN_00c85750() throw();
    __forceinline Allocator355& getHeap() throw()
    {
        return *heap;
    }
};

struct S_Heap
{
    virtual void* v0() throw();
    virtual void* alloc(unsigned int n) throw();
};
struct S_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_Heap* m10;
    S_Heap& heap()
    {
        return *m10;
    }
};
void* __cdecl FUN_00c85750() throw();
struct S_Heap;
struct S_Str
{
    const char* FUN_00d46d40();
};
struct S_Key
{
    int a;
    int b;
};
struct S_Ent
{
    S_Key k;
    int v8;
};
struct S_Arr12 : FUN_00dc35e0_class
{
    S_Ent* data;
    int m4;
    int m8;
    int next(int i)
    {
        int j = i + 1;
        while (j <= m8 && data[j].k.a == -1)
            j++;
        return j;
    }
    S_Key GetIteratorKey(int i)
    {
        return data[i].k;
    }
    int getValue(int i)
    {
        return data[i].v8;
    }
};
struct S_Map
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00cb1870(S_Heap* h, int v, const char* k) throw();
};
struct S_Obj
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int m8;
    int unk0c;
    S_Map m10;
    S_Obj* FUN_00e05700();
    void FUN_00e05100(int a, const char* b) throw();
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();
};
struct S_PH;
struct S_X
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void v8() throw();
    virtual void v9() throw();
    virtual void v10(S_PH* out, S_Key* k) throw();
};
struct S_PH
{
    S_X* p;
    int FUN_00dba980();
    S_PH* GetObjectValue(S_PH* out);
    S_X* FUN_00dba6c0();
    const char* FUN_00dba680();
    void FUN_00dba660() throw();
    void FUN_00dba7f0() throw();
};
struct S_Dom
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual S_Str* v4(const char* y) throw();
};
struct S_T2
{
    int f0;
    S_Str* f4;
};
struct S_Owner
{
    S_Obj* p;
    operator S_Obj*() const
    {
        return p;
    }
    S_Obj* operator->() const
    {
        return p;
    }
    void operator=(S_Obj* n)
    {
        if (p && p != n)
            p->FUN_00c905b0();
        p = n;
    }
};
struct S_Ctx
{
    S_Dom* m0;
    S_Owner m4;
    int m8;
    int unk0c;
    int unk10;
    int unk14;
    S_Arr12 m18;
    int unk24;
    int unk28;
    int unk2c;
    S_Ctx* Construct(S_Dom* d, int x) throw();
    ~S_Ctx() throw()
    {
        FUN_00dc43a0();
    }
    __declspec(noalias) void FUN_00dc4430(S_T2* t, S_PH* h, int f) throw();
    void FUN_00dc43a0() throw();
};

struct Object
{
    void* impl;
    Object() throw() : impl(0)
    {}
    ~Object() throw()
    {
        FUN_00dba7f0();
    }
    void FUN_00dba7f0() throw();
};

struct S_00dc4710_Alloc
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00dc4710_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00dc4710_Alloc* m_pStreamAllocator;
    S_00dc4710_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00dc4710_Ref
{
    virtual void v0();
    short m_iElementCount;
    short m_iObjectReferenceCount;
    void removeReference() throw();  // FUN_00c905b0
    static void* operator new(unsigned int n)
    {
        void* p = ((S_00dc4710_Router*)FUN_00c85750())->heap().AllocateMemoryBlock(n);
        ((S_00dc4710_Ref*)p)->m_iElementCount = (short)n;
        return p;
    }
    static void operator delete(void*)
    {}
};
struct S_00dc4710_Key
{
    int a;
    int b;
};
struct S_00dc4710_Bool
{
    char b;
    S_00dc4710_Bool()
    {}
};

template <typename K, typename V> struct hkMap_dc4710
{
    struct Pair
    {
        K key;
        V val;
    };
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    typedef int Iterator;

    inline Iterator GetFirstIterator() const
    {
        int i = 0;
        int last = m_iPairCount;
        if (last >= 0)
        {
            Pair* p = m_kPrimitiveElement;
            do
            {
                if (p->key.a != -1)
                    break;
                i++;
                p++;
            } while (i <= last);
        }
        return i;
    }
    inline Iterator getNext(Iterator i) const
    {
        int last = m_iPairCount;
        i++;
        if (i <= last)
        {
            Pair* p = m_kPrimitiveElement + i;
            do
            {
                if (p->key.a != -1)
                    break;
                i++;
                p++;
            } while (i <= last);
        }
        return i;
    }
    inline bool isValid(Iterator i) const
    {
        return i <= m_iPairCount;
    }
    inline Pair& getPair(Iterator i) const
    {
        const Iterator& index = i;
        Pair* const& data = m_kPrimitiveElement;
        return data[index];
    }
    inline K GetIteratorKey(Iterator i) const
    {
        return getPair(i).key;
    }
    inline V getValue(Iterator i) const
    {
        __assume(m_kPrimitiveElement != 0);
        return getPair(i).val;
    }
};
struct S_00dc4710_ClassImpl;
struct S_00dc4710_Obj;
struct S_00dc4710_Class
{
    S_00dc4710_ClassImpl* m_pClassImpl;
    ~S_00dc4710_Class() throw();                        // FUN_00dba660
    S_00dc4710_ClassImpl* getImplementation() throw();  // FUN_00dba680
    struct S_00dc4710_World* FUN_00dba6c0() throw();
};
struct S_00dc4710_ObjImpl;
struct S_00dc4710_Obj
{
    S_00dc4710_ObjImpl* m_pClassImpl;
    ~S_00dc4710_Obj() throw();  // FUN_00dba7f0
    S_00dc4710_Class GetObjectValue() throw();
};
struct S_00dc4710_World
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual S_00dc4710_Obj vf28(const S_00dc4710_Key& k) throw();
};

namespace fnv_00dc3d40 {
struct DObj
{
    int unk00;
    void FUN_00dba7f0() throw();
    __forceinline ~DObj() throw()
    {
        FUN_00dba7f0();
    }
};
struct DArray;
struct DValue
{
    union
    {
        __int64 handle;
        struct
        {
            int unk00;
            int unk04;
        };
    };
    int CallVirtualWithArg() throw();
    float hkOffsetOnlyStreamWriter_seek() throw();
    const float* DispatchToVTableSlot8(int n) throw();
    const char* FUN_00dbac70() throw();
    DObj CreateValueInto() throw();
    DArray FUN_00dbacd0() throw();
    void InvokeOnInterface(int v) throw();
    void FUN_00dbad20(float v) throw();
    void FUN_00dbad60(const float* v, int n) throw();
    void FUN_00dbad00(const DObj& v) throw();
    void FUN_00dbadc0(const char* v) throw();
};
struct DMember
{
    const char* name;
    int unk04;
    unsigned int type;
    int unk0c;
    int tupleSize;
    __forceinline DMember() throw() : name(0), unk04(0), type(0), unk0c(0), tupleSize(0)
    {}
};
struct DAllocator
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
    virtual void ReturnMemory(void*, int) throw();
};
struct DMemory
{
    int unk00;
    int unk04;
    int unk08;
    DAllocator* heap;
    DAllocator& getHeap() throw()
    {
        return *heap;
    }
};
__declspec(restrict) void* __cdecl FUN_00c85750();
// hkMemoryAllocator::_bufAlloc<T>: the allocator may round the request up, the element count is updated
template <class T> __forceinline T* AllocateBufferWithSize(DAllocator& a, int& reqNumInOut) throw()
{
    int n = reqNumInOut * (int)sizeof(T);
    T* p = (T*)a.AllocateBufferWithSize(n);
    reqNumInOut = n / (int)sizeof(T);
    return p;
}
template <class T> __forceinline void construct(T* p, int n) throw()
{
    for (int i = 0; i < n; ++i)
        new (p + i) T();
}

// hkArray<MemberInfo>::Temp: hkArray(int n) constructs every allocated element (n is updated by _bufAlloc)
struct DMembers
{
    DMember* data;
    int size;
    int capacity;
    __forceinline DMembers(int n) throw() : data(0), size(0), capacity(0x80000000)
    {
        DAllocator& alloc = ((DMemory*)FUN_00c85750())->getHeap();
        DMember* p = n ? AllocateBufferWithSize<DMember>(alloc, n) : 0;
        int cap = n ? n : 0x80000000;
        data = p;
        size = n;
        capacity = cap;
        construct(data, size);
    }
    __forceinline void setSizeUnchecked(int n) throw()
    {
        construct(data + size, n - size);
        size = n;
    }
    __forceinline ~DMembers() throw()
    {
        DAllocator& a = ((DMemory*)FUN_00c85750())->getHeap();
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.ReturnMemory(data, (capacity & 0x3fffffff) * sizeof(DMember));
        data = 0;
        capacity = 0x80000000;
    }
};
struct DClass
{
    int impl;
    int FUN_00dba730() throw();
    void DispatchItems(DMembers& out) throw();
    void FUN_00dba660() throw();
    __forceinline ~DClass() throw()
    {
        FUN_00dba660();
    }
};
struct DArray
{
    int impl;
    int FUN_00dbac10() throw();
    int FUN_00dbac00() throw();
    DValue FUN_00dbabb0(int i) throw();
    DValue FUN_00dbab90(int i) throw();
    void FUN_00dbabe0(int n) throw();
    DClass FUN_00dbac20() throw();
    DArray InvokeCallbackInto(const char* name) throw();
    void FUN_00dbab70() throw();
    __forceinline ~DArray() throw()
    {
        FUN_00dbab70();
    }
};
}  // namespace fnv_00dc3d40

struct ArrayImpl;
struct MemberInfo
{
    const char* m_name;
    const char* m_pClassName;
    int m_type;
    void* m_valuePtr;
    int m_uiItemCount;
};

struct FUN_00dbab70
{
    ArrayImpl* m_pClassImpl;
    FUN_00dbab70() throw()
    {}
    ~FUN_00dbab70() throw();
    void FUN_00dbab50(ArrayImpl* impl) throw();
    void FUN_00dbabe0(int size) throw();
    int FUN_00dbac00() const throw();
};

struct DataObject;
struct DataWorld
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual void vf4() throw();
    virtual ArrayImpl* m_ppNewArray(DataObject& obj, const MemberInfo& minfo) throw();
};

struct FUN_00dba660
{
    void* m_pClassImpl;
    ~FUN_00dba660() throw();
    DataWorld* FUN_00dba6c0() const throw();
};

struct DataValue
{
    void* m_pClassImpl;
    void* m_handle;
    FUN_00dbab70 GetResult() const throw();
};

struct DataObject
{
    void* m_pClassImpl;
    FUN_00dba660 GetObjectValue() const throw();
    DataValue* FUN_00dba870(DataValue* out, const char* name) throw();
    DataValue* FUN_00dba890(DataValue* out, const char* name) const throw();
    DataValue FUN_00dba890(const char* name) const throw();
};

template <class T> struct CheckedReference
{
    T* value;
    CheckedReference(T& object) throw() : value(&object)
    {}
    ~CheckedReference() throw()
    {}
    operator T&() const throw()
    {
        return *value;
    }
};

extern "C" void _ReadWriteBarrier();
struct AllocatorVtbl;
__declspec(restrict) void* __cdecl FUN_00c85750() throw();
struct DC4430Memory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorVtbl* m_pStreamAllocator;
    __forceinline S_00dc3ce0_Allocator& heap() throw()
    {
        return *(S_00dc3ce0_Allocator*)m_pStreamAllocator;
    }
};
struct FlagBool
{
    char value;
    FlagBool()
    {}
    ~FlagBool() throw()
    {}
    FlagBool(bool b) : value(b)
    {}
    __forceinline operator bool() const throw()
    {
        return value != 0;
    }
};
void ResizeAudioStream(S_00dc3ce0_Allocator& alloc, void* array, int sizeElem) throw();

struct Key64
{
    union
    {
        unsigned __int64 val;
        struct
        {
            unsigned int low, high;
        };
    };
    __forceinline bool operator==(const Key64& o) const throw()
    {
        return low == o.low && high == o.high;
    }
};

struct KeyArray
{
    Key64* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline int indexOf(const Key64& key) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    __forceinline void AddBack(S_00dc3ce0_Allocator& alloc, const Key64& e) throw()
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(Key64));
        }
        new (m_data + m_iElementCount) Key64(e);
        m_iElementCount++;
    }

    __forceinline void AddBack(const Key64& e) throw()
    {
        AddBack((*(DC4430Memory*)FUN_00c85750()).heap(), e);
    }

    __forceinline void popBack() throw()
    {
        m_iElementCount--;
    }
};

struct AllocatorVtbl
{
    virtual void v00() throw();
    virtual void* allocate(int size) throw();
};

struct DBool_dc3a80
{
    char m_cBooleanValue;
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};
struct DClass_dc3a80
{
    void* m_pClassImpl;
    const char* FUN_00dba680() const throw();
    void FUN_00dba660() throw();
    __forceinline ~DClass_dc3a80() throw()
    {
        FUN_00dba660();
    }
};

// @f3 0x00922910 (community match, verified in this file)
namespace f3m_00922910 {
class hkPairMap64
{
  public:
    unsigned __int64* m_elem;
    int m_numElems;
    int m_hashMod;

    void resizeTable(int newCap);
    void FUN_00922910(unsigned __int64 key, unsigned __int64 val);
};

// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::insert | hkMap.obj | fnv360_0822_retail, call_gap, high
// pdb params: alloc, key, val
void hkPairMap64::FUN_00922910(unsigned __int64 key, unsigned __int64 val)
{
    if ((m_numElems & 0x7fffffff) * 2 > m_hashMod)
        resizeTable(m_hashMod + m_hashMod + 2);
    unsigned __int64 i;
    for (i = ((key >> 4) * 0x9e3779b1) & m_hashMod; m_elem[i] != (unsigned __int64)-1; i = (i + 1) & m_hashMod)
    {
        if (m_elem[i] == key)
            break;
    }
    int isNew = (m_elem[i] != key) ? 1 : 0;
    m_numElems += isNew;
    m_elem[i] = key;
    m_elem[m_hashMod + i + 1] = val;
}
}   // namespace f3m_00922910
