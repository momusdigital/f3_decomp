#include "f3_common.h"
// src/havok/common/serialize/util/hkserializeutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkserializeutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00d48620(int a, int b, int c);

// @fnv 0x00d48640
void __cdecl FUN_00d48640(int a, int b)
{
    FUN_00d48620(a, b, 1);
}

struct hkReferencedObject
{
    void removeReference();
};

struct GlobalDispatch
{
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int Dispatch(int, int, int, int, int);
};
extern GlobalDispatch* DAT_01269b74;

extern void* FUN_00d48d30(void* obj_b, int a2, int a3);

namespace fnv_00d48f00 {
void* __cdecl FUN_00cb1280(void* destination, int value, int size);
int __cdecl FUN_00cb1290(const void* left, const void* right, int size);
int __cdecl FUN_00cb0fa0(const char* left, const char* right);
const char* __cdecl FUN_00dc0fb0();
int __cdecl CreateResourceFromArray(void* input, int arg2, int flags);
int __cdecl FUN_00d48d30(void* input, int arg2, int arg3);
extern int DAT_011b7b88;
struct Header180
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
    char unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Header180()
    {
        FUN_00cb1280(this, -1, 64);
        unk00 = 0x57e0e057;
        unk04 = 0x10c0c010;
        unk28 = 0;
    }
};
}  // namespace fnv_00d48f00

struct S_00d49310_Result
{
    int m_uiFilterValue;
    S_00d49310_Result(int v) : m_uiFilterValue(v)
    {}
};
void FUN_00d48af0(void* stream, int* out) throw();

int FUN_00cb0fa0(const char* a, const char* b);
int FUN_00c009eb(const char* a, const char* b);

static inline int S_00d49350_Compare(const char* a, const char* b)
{
    if (a)
    {
        if (b)
            return FUN_00cb0fa0(a, b);
        return 1;
    }
    return b ? -1 : 0;
}

struct S_00d49350
{
    unsigned int m_pcText;

    const char* cString() const
    {
        return (const char*)(m_pcText & ~1u);
    }
    bool Equals(const char* s) const;
};

// Compares the stored string with s using S_00d49350_Compare and returns whether they are equal.
// @f3 0x00617860 (community match, verified in this file)
int __cdecl FUN_00c009eb(const char* a, const char* b);
// pdb: BSStringT<char>::StrCmp | EffectSetting.obj | fnv360_0721_beta, call_gap, low
// pdb params: apString, abIgnoreCase
bool S_00d49350::Equals(const char* aString) const
{
    int r;
    if (aString && m_pcText)
        r = FUN_00c009eb((const char*)m_pcText, aString);
    else if (!aString && m_pcText == 0)
        r = 0;
    else
        r = aString ? -1 : 1;
    return r == 0;
}


struct S00d48d30_Bool
{
    char m_cBooleanValue;
    S00d48d30_Bool()
    {}
};

struct S00d48d30_Stream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00d48d30_Bool IsStreamValid() const;
};

struct hkStringPtr
{
    void* m_pcText;
    void operator=(const char* s);
};

struct S00d48d30_Result
{
    int m_iResultCode;
    hkStringPtr m_message;
};

struct S00d48d30_Format
{
    int m_type;
    int attach(struct S00d48d30_Stream* s, struct S00d48d30_Result* out);
};

void FUN_00d48af0(void* stream, int* out) throw();

struct S00d48680_Arr
{
    char* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};

struct S00d48680_Alloc
{
    int unk00;
};

struct S00d48680_Sys
{
    int unk00;
    int unk04;
    int unk08;
    S00d48680_Alloc* heap;
    S00d48680_Alloc& getHeap()
    {
        return *heap;
    }
};

extern "C" S00d48680_Sys* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(S00d48680_Alloc* h, S00d48680_Arr* a, int cap, int flag);

struct S00d48680_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int a, int b);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned char& v9(unsigned char& f);
    virtual void v10(int a, int b);
    virtual int v11();
};

// Reads data into arr from obj, growing the buffer via FUN_00c908c0 when the requested size exceeds the current capacity.
// @fnv 0x00d48680
static __declspec(noinline) void FUN_00d48680(S00d48680_Obj* apReader, S00d48680_Arr* apBuffer)
{
    unsigned char flag;
    if (apReader->v9(flag))
    {
        apReader->v10(0, 2);
        int iNeeded = apReader->v11();
        S00d48680_Alloc& heap = FUN_00c85750()->getHeap();
        unsigned int cap = apBuffer->m_capFlags & 0x3fffffff;
        if ((int)cap < iNeeded)
        {
            int grow = (int)(cap * 2);
            if (iNeeded >= grow)
            {
                grow = iNeeded;
            }
            FUN_00c908c0(&heap, apBuffer, grow, 1);
        }
        apBuffer->m_iElementCount = iNeeded;
        apReader->v10(0, 0);
        apReader->v4((int)apBuffer->m_data, apBuffer->m_iElementCount);
        return;
    }

    int r;
    do
    {
        int iNeeded = apBuffer->m_iElementCount + 0x20000;
        S00d48680_Alloc& heap = FUN_00c85750()->getHeap();
        unsigned int cap = apBuffer->m_capFlags & 0x3fffffff;
        if ((int)cap < iNeeded)
        {
            int grow = (int)(cap * 2);
            if (iNeeded < grow)
            {
                iNeeded = grow;
            }
            FUN_00c908c0(&heap, apBuffer, iNeeded, 1);
        }
        char* d = apBuffer->m_data;
        int iSize = apBuffer->m_iElementCount;
        r = apReader->v4((int)(d + iSize), 0x20000);
        apBuffer->m_iElementCount += r;
    } while (r > 0);
}

struct HashPolicy
{
};
struct StringMapState
{
    void* entries;
    int count;
    int mask;
    HashPolicy policy;
    void FUN_00d87790(HashPolicy) throw();
    void FreeBuffer() throw();
    StringMapState() throw()
    {
        FUN_00d87790(HashPolicy());
    }
    void clear() throw()
    {
        FreeBuffer();
    }
};
extern void* DAT_010cf7b0[];
struct RegistryBase
{
    void** dispatch;
    unsigned short allocationSize;
    unsigned short references;
    RegistryBase() throw() : references(1)
    {
        dispatch = DAT_010cf7b0;
    }
};
struct TypeRegistry : RegistryBase
{
    StringMapState types;
    int finish;
    TypeRegistry(int flag) throw() : finish(flag)
    {}
    void clear() throw()
    {
        types.clear();
    }
    void FUN_00d47970(const TypeRegistry&) throw();
};
struct RuntimeClass;
struct ClassRegistry
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual const RuntimeClass* find(const char*) const throw();
};
struct Resource : hkReferencedObject
{
    void FUN_00c905b0() const throw();
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void* contents(const char*, const TypeRegistry*) const throw();
    virtual const char* name() const throw();
};
struct ResourceRef
{
    Resource* ptr;
    ResourceRef() throw() : ptr(0)
    {}
    void clear() throw()
    {
        if (ptr)
            ptr->FUN_00c905b0();
        ptr = 0;
    }
    Resource* operator->() const
    {
        return ptr;
    }
    void take(Resource* p) throw()
    {
        if (ptr && ptr != p)
            ptr->FUN_00c905b0();
        ptr = p;
    }
};
struct ObjectImpl
{
    virtual ~ObjectImpl() throw();
    unsigned short allocationSize;
    unsigned short references;
    int externalRefs;
};
struct RootObject
{
    ObjectImpl* impl;
    void FUN_00dba760(ObjectImpl*) throw();
    __declspec(noinline) void FUN_00dba7f0() throw();
    RootObject(ObjectImpl* p) throw()
    {
        FUN_00dba760(p);
    }
    void clear() throw()
    {
        FUN_00dba7f0();
    }
};
struct NativeWorld
{
    void* dispatch;
    unsigned short allocationSize;
    unsigned short references;
    const ClassRegistry* classes;
    void* vtableRegistry;
    void* mapEntries;
    int mapCount;
    int mapMask;
    HashPolicy mapPolicy;
    void* rootPointer;
    const RuntimeClass* rootClass;
    void Initialize() throw();
    void FUN_00dbb3f0() throw();
    void SetReferencedObject(const ClassRegistry*) throw();
    ObjectImpl* FUN_00dbb4f0(void*, const RuntimeClass&) const throw();
    NativeWorld() throw()
    {
        Initialize();
    }
    void clear() throw()
    {
        FUN_00dbb3f0();
    }
};
struct ObjectResource;
struct LoadFormat
{
    int type;
    S_00d49350 version;
    unsigned int layout;
};
struct LoadError
{
    int status;
    hkStringPtr message;
};
struct LoadStream;
struct LoadBuffer
{
    char* data;
    int size;
    unsigned int capacity;
};
struct LoadAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void freeBlock(void*, int) throw();
};
struct LoadMemory
{
    int unk00;
    int unk04;
    int unk08;
    LoadAllocator* heap;
};
extern "C" int __cdecl FUN_00cb1290(const void*, const void*, int) throw();
extern "C" const char* __cdecl FUN_00dc0fb0() throw();
extern "C" Resource* __cdecl CreateResourceFromArray(const void*, int, const TypeRegistry*) throw();
extern unsigned int DAT_011b7b88;
extern const char str_010cf9d8[];
void __cdecl FUN_00d48680(LoadStream&, LoadBuffer&) throw();
struct DeprecatedLoader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Resource* load(LoadStream&, const LoadFormat&, LoadError*) throw();
};
static __declspec(noinline) __declspec(nothrow) Resource* FUN_00d48760(LoadStream& input, const LoadFormat& format,
                                                                       LoadError* error,
                                                                       const TypeRegistry& types) throw()
{
    if (format.type == 2)
    {
        if (FUN_00cb1290(&format.layout, &DAT_011b7b88, 4) == 0)
        {
            if (format.version.Equals(FUN_00dc0fb0()))
            {
                LoadBuffer buffer;
                buffer.data = 0;
                buffer.size = 0;
                buffer.capacity = 0x80000000;
                FUN_00d48680(input, buffer);
                Resource* result = CreateResourceFromArray(buffer.data, buffer.size, &types);
                LoadMemory* memory = (LoadMemory*)FUN_00c85750();
                buffer.size = 0;
                if ((int)buffer.capacity >= 0)
                    memory->heap->freeBlock(buffer.data, buffer.capacity & 0x3fffffff);
                return result;
            }
        }
        else
        {
            if (error)
            {
                error->status = 3;
                error->message = str_010cf9d8;
            }
            return 0;
        }
    }
    return ((DeprecatedLoader*)DAT_01269b74)->load(input, format, error);
}

// Loads a resource via FUN_00d48760, resolves its class in classes, and constructs an ObjectResource from the parsed data.
// @fnv 0x00d48840
LoadStream* volatile inputSource;
LoadFormat* volatile formatSource;
LoadError* volatile errorSource;
const ClassRegistry* volatile classSource;
const TypeRegistry* volatile typeSource;
ObjectResource* volatile outputSink;

struct S00d48950_Item
{
    virtual void v00();
    virtual void v04();
    virtual void* GetIteratorKey();
    virtual int GetNumOwnMembers();
};
struct S00d48950_ItemArray
{
    S00d48950_Item** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d48950_Root
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void getItems(S00d48950_ItemArray& items);
};
struct S00d48950_Entry
{
    int hkClass_getDescribedVersion();
};
struct S00d48950_Lookup
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual S00d48950_Entry* find(void* key);
};
struct S00d48950_Set
{
    int FUN_00cb1cb0(__int64 id, int a, int b);
};
struct S00d48950_Target
{
    char pad00[0x18];
    S00d48950_Set m_set;
    void FUN_00db8670();
    __int64 FUN_00db7dd0(void* key, int version);
};
struct S00d48950_Result
{
    int m_pMoppCode;
    char m_message[1];
};
struct S00d48950_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S00d48950_Sys
{
    int unk00, unk04, unk08, unk0c;
    S00d48950_Heap* m_pStreamAllocator;
    S00d48950_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S00d48950_Result* volatile g00d48950_result;
S00d48950_Target* volatile g00d48950_target;
S00d48950_Lookup* volatile g00d48950_lookup;
S00d48950_Root* volatile g00d48950_root;
volatile int g00d48950_out;
