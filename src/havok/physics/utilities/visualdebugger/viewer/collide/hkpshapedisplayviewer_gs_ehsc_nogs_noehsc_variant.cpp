#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00c6d840_Pair
{
    int m_kPointA;
    int m_kPointB;
    S_00c6d840_Pair(int a, int b) : m_kPointA(a), m_kPointB(b)
    {}
};
struct S_00c6d840_Entry
{
    int m_key;
    int unk04;
    S_00c6d840_Pair m_uiFilterValue;
};
struct S_00c6d840
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
    S_00c6d840_Entry* m_entries;
    int m_uiItemCount;
    S_00c6d840_Pair FindEntry(int key, int unused);
};
struct Allocator
{
    virtual void reserved();
    virtual void* allocate(unsigned int);
};
struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
void* __cdecl FUN_00c85750();
void* __cdecl FUN_00d65910(void* context);
struct FUN_00dd9380_class
{
    void* FUN_00dd9380(const char*, void*);
};
struct hkProcessFactory : FUN_00dd9380_class
{
};
extern hkProcessFactory* FUN_00dd9380;
extern void* __cdecl FUN_00d65910(void*);
struct FUN_00d652a0_cls
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10(int a, int b) = 0;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    void FUN_00d652a0(int arg);
};
struct BSAudio;
struct D66180PropertyValue
{
    void* m_ptr;
    int m_extra;

    D66180PropertyValue()
    {}
};
struct SpawnAlloc
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnAlloc* m_pAllocator;
};
struct SpawnOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char* m_20;
    int unk24;
    char** m_28;
    int m_2c;
    int unk30;
    char** m_34;
    int m_38;

    void FUN_00c93820(void* p);
    void FUN_00c93920(void* p);
};
struct PendingNode
{
    SpawnOwner* m_pSharedOwner;
    int m_04;
    int m_08;
    unsigned int m_0c;

    PendingNode()
    {
        m_04 = 0;
        m_08 = 0;
        m_0c = 0x80000000u;
    }
    void* operator new(unsigned int size) throw()
    {
        AllocHolder* holder = (AllocHolder*)FUN_00c85750();
        SpawnAlloc* alloc = holder->m_pAllocator;
        return alloc->Alloc(size);
    }
};
template <class T> inline void hkArrayConstruct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}
static inline bool HasProperty(const S_00c6d840* props, int key)
{
    for (int i = 0; i < props->m_uiItemCount; i++)
    {
        if (props->m_entries[i].m_key == key)
            return true;
    }
    return false;
}
static int FUN_00d652c0(S_00c6d840* props, bool checkOverride, bool* usedDefault);
struct ShapeList
{
    struct ShapeItem** data;
    int count;
};
struct ShapeItem
{
    virtual void v00()
    {}
    virtual void* GetDesc()
    {
        return 0;
    }
};
void* __cdecl FUN_00c85750();
struct Mem_d65f
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
    virtual void deallocateChunk(void* p, int nbytes) throw();
    virtual void v0C();
    virtual void deallocate(void* p, int nbytes) throw();
};
struct Holder_d65f
{
    int unk00, unk04, unk08, unk0C;
    Mem_d65f* m_pMemoryAllocator;
    Mem_d65f& heap()
    {
        return *m_pMemoryAllocator;
    }
};
struct Router_d65f
{
    static Holder_d65f& __cdecl FUN_00c85750() throw();
};
inline Mem_d65f& getMemory_d65f()
{
    return *Router_d65f::FUN_00c85750().m_pMemoryAllocator;
}
inline void memCpy4_d65f(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}
template <class T> struct hkArray_d65f
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~hkArray_d65f() throw()
    {
        Mem_d65f& mem = Router_d65f::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            mem.deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d65f(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};
struct Listener_d65f;
struct Watch2_d65f
{
    virtual void w00();
};
struct Agent_d65f
{
    void FUN_00c917a0(Listener_d65f* listener);
    void ClearValue(Watch2_d65f* watch);
};
struct Node_d65f
{
    Agent_d65f* m_pCollisionAgent;
    hkArray_d65f<int> m_items;
    static void operator delete(void* p) throw()
    {
        Router_d65f::FUN_00c85750().heap().deallocateChunk(p, sizeof(Node_d65f));
    }
};
struct Listener_d65f
{
    virtual void l00();
};
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
struct TtShapeDisplayBase : FUN_00d652a0_cls
{
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
};
struct TtShapeDisplayOuter;
struct TtTlsRecord
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int m_spare;
};
struct TtTlsData
{
    int unk00;
    TtTlsRecord* m_cur;
    int unk08;
    TtTlsRecord* m_kRayEnd;
};
extern unsigned int g_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct TtShapeDisplayInner
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
    bool m_flag34;

    TtShapeDisplayOuter* GetOuter();
    void FUN_00d65520(int arg);
};
struct TtShapeDisplayOuter : TtShapeDisplayBase, TtShapeDisplayInner
{
};
__forceinline TtShapeDisplayOuter* TtShapeDisplayInner::GetOuter()
{
    return (TtShapeDisplayOuter*)((char*)this - 0x2c);
}
static void __forceinline TtPushEvent(const char* name)
{
    TtTlsData* data = (TtTlsData*)TlsGetValue(g_0126835c);
    TtTlsRecord* rec = data->m_cur;
    if (rec < data->m_kRayEnd)
    {
        rec->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        rec->m_uiCommandId = t;
        data->m_cur = rec + 1;
    }
}
// sub ecx,8; jmp FUN_00d661f0: adjustor thunk from multiple inheritance.
struct PrimaryBase
{
    virtual void FUN_00d661f0();
    int unk04;
};
struct SecondaryBase
{
    virtual void FUN_00d661f0();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d661f0
    virtual void FUN_00d661f0();
};
Derived::Derived()
{}
// FUN_00d66200 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 40 bytes so the second
// base lands at +0x28.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_00d66200; a defined
// key function makes the vftable that references the thunk be emitted here.
struct OutVec
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
};
struct S8
{
    unsigned __int64 value;
    void* getPtr() const
    {
        return (void*)(unsigned int)value;
    }
};
struct Entry16
{
    int m_type;
    int unk04;
    void* m_p8;
    int m_iThirdValue;
};
struct SubObj
{
    void SweepTransform(float f, OutVec* out);
};
struct Item
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
    Entry16* m_entries;
    int m_entryCount;
    bool hasProperty(int key) const
    {
        for (int i = 0; i < m_entryCount; ++i)
        {
            if (m_entries[i].m_type == key)
                return true;
        }
        return false;
    }
    S8 getProperty(int key) const
    {
        int n = m_entryCount;
        for (int i = 0; i < n; ++i)
        {
            if (m_entries[i].m_type == key)
            {
                return *(const S8*)&m_entries[i].m_p8;
            }
        }
        S8 s = {0};
        return s;
    }
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    SubObj m_e0;
};

#include <xmmintrin.h>
struct S65_Alloc
{
    virtual void v00();
    virtual void* allocate(unsigned int size);
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* p, int size);
};
struct S65_Heap
{
    int h00;
    int h04;
    int h08;
    int h0c;
    S65_Alloc* allocator;
    __forceinline S65_Alloc& heap()
    {
        return *allocator;
    }
};
__forceinline S65_Heap& s65Router()
{
    return *static_cast<S65_Heap*>(FUN_00c85750());
}

struct S65_Pair
{
    unsigned __int64 bits;
    S65_Pair()
    {}

    int integer() const
    {
        return (int)bits;
    }
    void* pointer() const
    {
        return (void*)(unsigned long)bits;
    }
};
struct S65_Param : S_00c6d840
{
    int p80;
    int p84;
    int p88;
    int p8c;
    int p90;
    int p94;
    int p98;
    int p9c;
    int pa0;
    int pa4;
    int pa8;
    int pac;
    int pb0;
    int pb4;
    int pb8;
    int pbc;
    int pc0;
    int pc4;
    int pc8;
    int pcc;
    int pd0;
    int pd4;
    int pd8;
    int pdc;
    int pe0;
    int pe4;
    unsigned char motionType;
    unsigned char pe9;
    unsigned char pea;
    unsigned char peb;
    int pec;
    int transform;
    S65_Pair FindEntry(int key, int unused);
    __forceinline void* pointerProperty(int key)
    {
        return FindEntry(key, 0).pointer();
    }
    __forceinline int integerProperty(int key)
    {
        return FindEntry(key, 0).integer();
    }
    S65_Pair FUN_00cd2a50(int key);
    bool has(int key) const
    {
        for (int i = 0; i < m_uiItemCount; ++i)
            if (m_entries[i].m_key == key)
                return true;
        return false;
    }
};

struct S65_Map
{
    int s00;
    int s04;
    int s08;
    unsigned int LookupHashEntry(void* key, int def);
    void FUN_00cb1870(S65_Alloc* a, void* key, int val);
    __forceinline void insert(void* key, int val)
    {
        FUN_00cb1870(&s65Router().heap(), key, val);
    }
};
struct S65_Elem
{
    virtual ~S65_Elem();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
};
struct S65_Vec
{
    S65_Elem** data;
    int count;
    int cap;
    S65_Elem* inlineBuf[8];
};
union S65_V4
{
    __m128 q;
    float f[4];
};
struct S65_NewObj
{
    int n00;
    short s04;
    short s06;
    int n08;
    int n0c;
    S65_V4 c0;
    S65_V4 c1;
    S65_V4 c2;
    S65_V4 t;
    S65_NewObj* FUN_00de1d20(void* v);
    float& cell(int row, int col)
    {
        return ((float*)&c0)[col * 4 + row];
    }
};
struct S65_Host
{
    virtual void v00();
    virtual void v04(S65_Vec* out, void* arg, void* nv, int glob, void* saved);
    virtual void v08(int a, void* arg, void* nv, int glob, void* saved);
    virtual void v0c(int val, void* nv, int glob);
};
struct S65_Err
{
    virtual void d00();
    virtual void d04();
    virtual void d08();
    virtual void d0c(int a, int b, const char* buf, const char* s, int n);
};
struct S65_IntArr
{
    int* data;
    int count;
    int cap;
};
struct S65_Item
{
    int i00;
    S65_IntArr arr;
};

static __declspec(noinline) void* FUN_00d652c0(S65_Param* p, bool flag, unsigned char* out)
{
    void* base = p->pointerProperty(0x1135);
    void* alt = p->pointerProperty(0x1235);
    void* over = p->pointerProperty(0x1234);
    *out = 0;
    if (flag && p->has(0x1234))
    {
        if (!over)
            *out = 1;
        return (void*)over;
    }
    if (p->has(0x1235))
    {
        if (!alt)
            *out = 1;
        return (void*)alt;
    }
    if (p->has(0x1135))
    {
        if (!base)
            *out = 1;
        return (void*)base;
    }
    return 0;
}

struct S65_Prim
{
    virtual void p00();
    int o04;
    int o08;
    int o0c;
    int f10;
    int f14;
    S65_Host* host;
    int o1c;
    int o20;
    int o24;
    int FindItemIndex(int key);
};
struct S65_Sec
{
    virtual void FUN_00d65ad0(S65_Param* param);
};
struct S65_Self : S65_Prim, S65_Sec
{
    int t04;
    S65_Item** m_items;
    int t0c;
    int t10;
    S65_Map sub14;
    S65_Map sub20;
    S65_Map sub2c;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
    int t40;
    int f44;
    int f48;
    void FUN_00d65ad0(S65_Param* param);
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

// @f3 0x009f29e0 (community match, verified in this file)
struct DisplayValue
{
    unsigned __int64 bits;
    DisplayValue() {}
    void* pointer() const { return (void*)(unsigned int)bits; }
};
struct DisplayTransform
{
    S65_V4 right, up, forward, translation;
};
struct DisplayHost
{
    virtual ~DisplayHost();
    virtual int add(const S65_Vec& geometries, const DisplayTransform& transform, unsigned long id, int tag, unsigned long shape);
    virtual int instance(unsigned long original, const DisplayTransform& transform, unsigned long id, int tag, unsigned long shape);
    virtual int color(int value, unsigned long id, int tag);
};
struct DisplayPropertyEntry
{
    int key;
    int unused04;
    unsigned int value;
    unsigned int upper;
};
struct DisplayBody
{
    int b00, b04, world, b0c;
    void* shape;
    int b14, b18, b1c, b20, b24, b28, b2c;
    int b30, b34, b38, b3c, b40, b44, b48, b4c;
    int b50, b54, b58, b5c, b60, b64, b68, b6c, b70;
    DisplayPropertyEntry* properties;
    int propertyCount;
    int b7c, b80, b84, b88, b8c, b90, b94, b98, b9c;
    int ba0, ba4, ba8, bac, bb0, bb4, bb8, bbc;
    int bc0, bc4, bc8, bcc, bd0, bd4;
    unsigned char motionType;
    unsigned char bd9, bda, bdb;
    int bdc;
    DisplayTransform transform;
    DisplayValue* FUN_00477900(DisplayValue* out, int key) const;
    DisplayValue* FUN_009317a0(DisplayValue* out, int key);
    __forceinline void* property(int key)
    {
        DisplayValue out;
        return FUN_00477900(&out, key)->pointer();
    }
    __forceinline void remove(int key)
    {
        DisplayValue out;
        FUN_009317a0(&out, key);
    }
    __forceinline bool has(int key) const
    {
        for (int i = 0; i < propertyCount; ++i)
            if (properties[i].key == key)
                return true;
        return false;
    }
};
struct DisplayMap
{
    int data, size, mask;
    unsigned int FUN_009227d0(void* key, unsigned int def) const;
    int FUN_00922710(void* key, unsigned int value);
};
struct DisplayPool
{
    void* FUN_008f6d30(int bytes, int alignment);
    void FUN_008f6d90(void* p, int bytes, int category);
};
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern int DAT_011697fc;
extern int DAT_01169800;
extern int DAT_01169804;
extern const char DAT_00e80bd4[];
extern const char DAT_00e80d50[];
extern "C" void __cdecl FUN_00901f10(S65_IntArr* arr, int elemSize);
extern "C" void* __cdecl FUN_009f3010(DisplayBody* body);
struct DisplayReference
{
    virtual ~DisplayReference() {}
    unsigned short allocSize;
    short references;
    __forceinline void release()
    {
        if (allocSize)
        {
            --references;
            if (references == 0)
                delete this;
        }
    }
};
struct DisplayEnvironment
{
    int phi, theta;
    DisplayEnvironment();
};
struct DisplayBuilder : DisplayReference
{
    int phi,theta,current;
    void FUN_00a66d50(void* shape, S65_Vec* out);
    DisplayBuilder(const DisplayEnvironment& e);
    virtual ~DisplayBuilder() {}
};
struct DisplayStream : DisplayReference
{
    void* writer;
    DisplayStream(char* buffer,int size);
    void FUN_00943710(const char* text);
    virtual ~DisplayStream();
};
extern S65_Err* DAT_010f3364;
struct DisplayNewGeometry : DisplayReference
{
    void* geometry; int n0c;
    S65_V4 c0,c1,c2,translation;
    int type,n54,n58,n5c;
    DisplayNewGeometry(void* geometry);
    __forceinline void identity()
    {
        for(int i=0;i<4;++i)c0.f[i]=0.0f;
        for(int i=0;i<4;++i)c1.f[i]=0.0f;
        for(int i=0;i<4;++i)c2.f[i]=0.0f;
        c0.f[0]=1.0f;c1.f[1]=1.0f;c2.f[2]=1.0f;
        translation.f[0]=translation.f[1]=translation.f[2]=translation.f[3]=0.0f;
    }
};
void S65_Self::FUN_00d65ad0(S65_Param* param)
{
    DisplayBody* body = reinterpret_cast<DisplayBody*>(param);
    DisplayValue propertyScratch;
    void* displayShape = body->FUN_00477900(&propertyScratch, 0x1135)->pointer();
    if (body->has(0x1135) && !displayShape)
        return;
    if (!body->shape && !displayShape)
        return;
    if (f10 == 0 && f14 == 0)
    {
        DisplayValue overrideValue;
        body->FUN_00477900(&overrideValue, 0x1234);
        if (overrideValue.pointer())
            return;
    }
    int index = S65_Prim::FindItemIndex(body->world);
    if (index < 0)
        return;
    S65_Item* item = m_items[index];
    void* shape = displayShape;
    if (!shape)
    {
        // Fake match: the body's shape is read into a named local and a compiler
        // barrier (no code) stands between the read and the assignment. That keeps
        // the loaded value a register variable instead of an expression temporary,
        // so it takes no turn in the scratch-register rotation (eax, ecx, edx) and
        // the seven later scratch choices up to the report call fall one step earlier.
        void* bodyShape = body->shape;
        _ReadWriteBarrier();
        shape = bodyShape;
    }
    bool alreadyCreated = false;
    if (b3a)
    {
        unsigned int used = reinterpret_cast<DisplayMap&>(sub2c).FUN_009227d0(shape, 0);
        alreadyCreated = used > 0;
        if (!used)
            reinterpret_cast<DisplayMap&>(sub2c).FUN_00922710(shape, 1);
    }
    unsigned int instance = 0;
    if (b39)
        instance = reinterpret_cast<DisplayMap&>(sub14).FUN_009227d0(shape, 0);
    S65_Vec geometries;
    geometries.data = geometries.inlineBuf;
    geometries.count = 0;
    geometries.cap = 0x80000008;
    bool deleteRaw = true;
    if (!instance && !alreadyCreated && b3b && b3c)
    {
        void* once = body->property(0x1136);
        void* shared = body->property(0x1131);
        if (!once && !shared)
        {
            DisplayEnvironment environment;
            DisplayBuilder builder(environment);
            builder.FUN_00a66d50(shape, &geometries);
            for (int i = geometries.count - 1; i >= 0; --i)
            {
                S65_Elem* geometry = geometries.data[i];
                if (geometry->f50 == 6 && geometry->f08 == 0)
                {
                    __declspec(align(16)) char report[512];
                    { DisplayStream stream(report,512);
                    stream.FUN_00943710(DAT_00e80bd4);
                    DAT_010f3364->d0c(0, -1, report, DAT_00e80d50, 0x10f);
                    }
                    --geometries.count;
                    geometries.data[i] = geometries.data[geometries.count];
                }
            }
            if (displayShape)
            {
                static_cast<DisplayReference*>(displayShape)->release();
                body->remove(0x1135);
            }
        }
        else
        {
            deleteRaw = once == 0;
            if (shared)
                body->FUN_009317a0(&propertyScratch, 0x1131);
            DisplayPool* pool=static_cast<DisplayPool*>(TlsGetValue(DAT_010f3170));
            DisplayReference* memory=static_cast<DisplayReference*>(pool->FUN_008f6d30(0x60,8));
            memory->allocSize=0x60;
            DisplayNewGeometry* geometry=new(static_cast<void*>(memory)) DisplayNewGeometry(once?once:shared);
            geometry->identity();
            geometries.data[geometries.count++] = (S65_Elem*)geometry;
        }
    }
    void* id = FUN_009f3010(body);
    S65_IntArr* ids = &item->arr;
    if (ids->count == (ids->cap & 0x3fffffff))
        FUN_00901f10(ids, 4);
    ids->data[ids->count++] = (int)id;
    if (!instance)
    {
        if (geometries.count > 0 || alreadyCreated || !b3c)
        {
            reinterpret_cast<DisplayHost*>(host)->add(geometries, body->transform, (unsigned long)id, DAT_011697fc, (unsigned long)shape);
            if (b39)
            {
                reinterpret_cast<DisplayMap&>(sub14).FUN_00922710(shape, (unsigned int)id);
                reinterpret_cast<DisplayMap&>(sub20).FUN_00922710(shape, 1);
            }
            int color = (int)body->property(0x1130);
            if (color == 0 && b3d)
                color = body->motionType == 7 ? DAT_01169804 : DAT_01169800;
            if (color)
                reinterpret_cast<DisplayHost*>(host)->color(color, (unsigned long)id, DAT_011697fc);
        }
    }
    else
    {
        unsigned int count = reinterpret_cast<DisplayMap&>(sub20).FUN_009227d0(shape, 1) + 1;
        reinterpret_cast<DisplayMap&>(sub20).FUN_00922710(shape, count);
        reinterpret_cast<DisplayHost*>(host)->instance(instance, body->transform, (unsigned long)id, DAT_011697fc, (unsigned long)shape);
    }
    for (int i = 0; i < geometries.count; ++i)
    {
        if (!deleteRaw)
            geometries.data[i]->f08 = 0;
        delete geometries.data[i];
    }
    if ((geometries.cap & 0x80000000u) == 0)
    {
        int capacity = geometries.cap & 0x3fffffff;
        DisplayPool* pool = static_cast<DisplayPool*>(TlsGetValue(DAT_010f3170));
        pool->FUN_008f6d90(geometries.data, capacity * 4, 0x17);
    }
}

