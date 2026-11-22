#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_01269028;
extern int DAT_01269028;
// ---------------------------------------------------------------------------
// FUN_00d6a940  (0x00d6a940, 112 bytes) - the constructor of the game's
// hkpBroadphaseViewer.
//
//   8b442404          mov eax,[esp+4]        ; the ctor argument
//   53 56 57         push ebx / esi / edi
//   50                push eax
//   8bf1              mov esi,ecx             ; this -> esi
//   e861230700        call 0xddccb0           ; hkpWorldViewerBase::hkpWorldViewerBase(arg)
//   c746287ccf0c01   mov [esi+0x28],<hkpWorldPostSimulationListener vftable>
//   8d5e28            lea ebx,[esi+0x28]
//   33ff              xor edi,edi
//   c706b4230d01     mov [esi],<hkpBroadphaseViewer vftable>
//   c7460894230d01   mov [esi+8],<hkpBroadphaseViewer vftable>
//   c7462084230d01   mov [esi+0x20],<hkpBroadphaseViewer vftable>
//   c70374230d01     mov [ebx],<hkpBroadphaseViewer vftable>
//   897e2c 897e30     mov [esi+0x2c],edi / mov [esi+0x30],edi
//   c7463400000080   mov [esi+0x34],0x80000000
//   8b4624            mov eax,[esi+0x24]     ; the shape list of the world
//   3bc7 741f         cmp eax,edi / je end
//   397870 7e1a       cmp [eax+0x70],edi / jle end
//   ...loop: for each shape, shape->FUN_00c93920(this+0x28)
//   5f 8bc6 5e 5b     pop edi / mov eax,esi / pop esi / pop ebx
//   c20400            ret 4
//
// The class therefore has four vptr-bearing base subobjects, at complete
// object offsets 0x00, 0x08, 0x20 and 0x28.  Modelling that hierarchy for
// real makes MSVC emit the vftable-initialisation itself, which is the only
// way to get the two vtable stores at 0x28 (the base's own vtable first, the
// derived's per-base vtable second, the second one through the address
// taken in ebx) and the exact order of the initialisations.
// ---------------------------------------------------------------------------
// the object the world keeps at this+0x24: an array of shapes and a count
// the secondary base at 0x28 - the listener the shapes are told about
// one shape of the world; 0xc93920 appends a listener to its list at +0x164
// the primary base at 0x00 (its vptr is the one at 0x00)
// the secondary base at 0x08, 0x18 bytes long
// the secondary base at 0x20
// 0xddccb0 - hkpWorldViewerBase's constructor; it fills the three vptrs it
// owns and the shape list at 0x24
// hkpBroadphaseViewer itself (the class is named after the function so that
// its constructor's decorated name carries the tag the checker looks for)
struct AudioAllocator {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void FreeData(void* apMemory, unsigned int auiSize);
};
struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
AudioHolder* __cdecl FUN_00c85750();
struct SubObject {
    virtual ~SubObject() {}
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;

struct S00d6a9b0_Rec
{
    const char* m_pName;
    unsigned int m_uTick;
    unsigned int unk08;
};

struct S00d6a9b0_Prof
{
    int unk00;
    S00d6a9b0_Rec* m_pCur;
    int unk08;
    S00d6a9b0_Rec* m_pRecordEnd;
};

static inline void S00d6a9b0_Mark(const char* name)
{
    S00d6a9b0_Prof* p = (S00d6a9b0_Prof*)TlsGetValue(DAT_0126835c);
    S00d6a9b0_Rec* r = p->m_pCur;
    if (r < p->m_pRecordEnd)
    {
        r->m_pName = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        r->m_uTick = t;
        p->m_pCur = r + 1;
    }
}

struct S00d6a9b0_Alloc
{
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void* GetStack(int& nBytes);
    virtual void FreeData(void* p, unsigned int size);
};

struct S00d6a9b0_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d6a9b0_Alloc* m_pAllocationContext;
    S00d6a9b0_Alloc& heap() { return *m_pAllocationContext; }
};

static inline S00d6a9b0_Alloc& S00d6a9b0_heap()
{
    return reinterpret_cast<S00d6a9b0_Holder*>(FUN_00c85750())->heap();
}
void __cdecl FUN_00c908c0(S00d6a9b0_Alloc* a, void* arr, int cap, int elemSize);

template <typename T>
struct S00d6a9b0_Arr
{
    T* m_data;
    int m_iElementCount;
    int m_capFlags;

    S00d6a9b0_Arr() : m_data(0), m_iElementCount(0), m_capFlags((int)0x80000000) {}
    ~S00d6a9b0_Arr()
    {
        S00d6a9b0_Alloc& a = S00d6a9b0_heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            a.FreeData(m_data, (m_capFlags & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_capFlags = (int)0x80000000;
    }
    void SetSizeAndGrow(int n);
    void setSizePod(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    void reserve(int n)
    {
        S00d6a9b0_Alloc& a = S00d6a9b0_heap();
        int cap = m_capFlags & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int nc = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&a, this, nc, sizeof(T));
        }
    }
};

struct __declspec(align(16)) S00d6a9b0_Vec
{
    float x, y, z, w;
};

struct __declspec(align(16)) S00d6a9b0_Cap
{
    int n;
};

struct S00d6a9b0_Blk
{
    S00d6a9b0_Vec m_kMinimumCorner;
    S00d6a9b0_Vec m_kMaximumCorner;
};

template <typename T>
static inline void S00d6a9b0_destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].v00(0);
}

template <typename T>
static inline void S00d6a9b0_construct(T* t, int n)
{
    for (int i = 0; i < n; i++)
    {
        T* p = t + i;
        if (p)
            p->FUN_00de1210();
    }
}

template <typename T>
__forceinline void S00d6a9b0_Arr<T>::SetSizeAndGrow(int n)
{
    reserve(n);
    S00d6a9b0_destruct(m_data + n, m_iElementCount - n);
    S00d6a9b0_construct(m_data + m_iElementCount, n - m_iElementCount);
    m_iElementCount = n;
}

template <typename T>
static __forceinline T* S00d6a9b0_bufAlloc(S00d6a9b0_Alloc& a, int n, int& nbytes)
{
    int req = n * (int)sizeof(T);
    T* p = (T*)a.GetStack(req);
    nbytes = req;
    return p;
}

struct S00d6a9b0_Req : S00d6a9b0_Arr<S00d6a9b0_Blk>
{
    __forceinline S00d6a9b0_Req(int n)
    {
        int nbytes;
        S00d6a9b0_Blk* p = S00d6a9b0_bufAlloc<S00d6a9b0_Blk>(S00d6a9b0_heap(), n, nbytes);
        S00d6a9b0_Cap c;
        c.n = nbytes / (int)sizeof(S00d6a9b0_Blk);
        if (c.n == 0)
            c.n = (int)0x80000000;
        m_data = p;
        m_capFlags = c.n;
    }
};

struct S00d6a9b0_Item
{
    virtual void v00(int flags);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    void FUN_00de1210();
    void FUN_00de1170(void* a, void* b);
};

struct S00d6a9b0_Sub
{
    virtual void p00(); virtual void p04(); virtual void p08(); virtual void p0c();
    virtual void p10(); virtual void p14(); virtual void p18(); virtual void p1c();
    virtual void p20(); virtual void p24(); virtual void p28(); virtual void p2c();
    virtual void p30(); virtual void p34();
    virtual void Run(void* params);
};

struct S00d6a9b0_Ctx
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    S00d6a9b0_Sub* m_58;
};

extern int DAT_01269028;

struct S00d6a9b0_Obj
{
    int unk00;
    S00d6a9b0_Arr<S00d6a9b0_Item> m_aiIndexedValues;

    void FUN_00d6a9b0(S00d6a9b0_Ctx* a1);
};

// @f3 0x009f76f0 (community match, verified in this file)
#include <new>

extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern int DAT_01169840;
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize);

struct FUN_009f2150
{
    virtual void v00(int flags);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    FUN_009f2150(const FUN_009f2150& o);
};

namespace f3m_009f76f0 {

struct GRec { const char* m_pName; unsigned int m_uTick; unsigned int unk08; };
struct GProf { int unk00; GRec* m_pCur; int unk08; GRec* m_pEnd; };

static inline void GMark(const char* name)
{
    GProf* p = (GProf*)TlsGetValue(DAT_0116913c);
    GRec* r = p->m_pCur;
    if (r < p->m_pEnd)
    {
        r->m_pName = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        r->m_uTick = t;
        p->m_pCur = r + 1;
    }
}

struct __declspec(align(16)) GCap { int n; };

struct GHeap
{
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
static inline GHeap* GetHeap() { return (GHeap*)TlsGetValue(DAT_010f3170); }

struct GVec
{
    float x, y, z, w;
    GVec& operator=(const GVec& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
};

struct GItem : FUN_009f2150
{
    GVec minimum, maximum;
    __forceinline GItem(const GItem& o) : FUN_009f2150(o)
    {
        minimum = o.minimum;
        maximum = o.maximum;
    }
    virtual void v00(int flags);
    void FUN_00a66ff0();
    void FUN_00a66f60(void* a, void* b);
};

template <typename T>
struct GArr
{
    T* m_data;
    int m_size;
    int m_capFlags;

    __forceinline void Resize(int n);
    __forceinline void SetSizePod(int n)
    {
        reserve(n);
        m_size = n;
    }
    __forceinline void reserve(int n)
    {
        int cap = m_capFlags & 0x3fffffff;
        if (cap < n)
        {
            int nc = (n >= cap * 2) ? n : cap * 2;
            FUN_00901e90(this, nc, sizeof(T));
        }
    }
    __forceinline void FreeBuf()
    {
        if ((m_capFlags & 0x80000000) == 0)
        {
            int capacity = m_capFlags & 0x3fffffff;
            GetHeap()->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};

struct GTmp : GArr<GItem>
{
    __forceinline void Begin(GArr<GItem>* src)
    {
        m_data = 0;
        m_size = 0;
        m_capFlags = (int)0x80000000;
        FUN_00a82280(src);
    }
    __declspec(noinline) void FUN_00a82280(GArr<GItem>* src)
    {
        GItem* data = m_data; m_data = src->m_data; src->m_data = data;
        int size = m_size; m_size = src->m_size; src->m_size = size;
        int capacity = m_capFlags; m_capFlags = src->m_capFlags; src->m_capFlags = capacity;
    }
    __forceinline void End()
    {
        int c = m_size;
        if (c > 0)
        {
            GItem* q = m_data;
            do
            {
                q->v00(0);
                q++;
            } while (--c);
        }
        FreeBuf();
    }
};

static __forceinline void CopyItems(GItem* dst, const GItem* src, int count)
{
    for (int i = 0; i < count; ++i)
    {
        GItem* item = dst + i;
        if (item)
            new (item) GItem(src[i]);
    }
}

static __forceinline void ConstructItems(GItem* data, int old, int n)
{
    for (int i = old; i < n; ++i)
    {
        GItem* p = data + i;
        if (p)
            p->FUN_00a66ff0();
    }
}

template <>
__forceinline void GArr<GItem>::Resize(int n)
{
    GTmp tmp;
    int old = m_size;
    if (n < old)
    {
        int off = n * (int)sizeof(GItem);
        int cnt = old - n;
        do
        {
            ((GItem*)((char*)m_data + off))->v00(0);
            off += sizeof(GItem);
        } while (--cnt);
    }
    else
    {
        int cap = m_capFlags & 0x3fffffff;
        if (n > cap)
        {
            int nc = cap * 2;
            if (n >= nc)
                nc = n;
            tmp.Begin(this);
            reserve(nc);
            GItem* d = m_data;
            CopyItems(d, tmp.m_data, old);
            m_size = old;
            tmp.End();
        }
        ConstructItems(m_data, old, n);
    }
    m_size = n;
}

struct GSub
{
    virtual void p00(); virtual void p04(); virtual void p08(); virtual void p0c();
    virtual void p10(); virtual void p14(); virtual void p18(); virtual void p1c();
    virtual void p20(); virtual void p24(); virtual void p28(); virtual void p2c();
    virtual void p30();
    virtual void Run(void* params);
};

struct GCtx
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50;
    GSub* m_54;
};

struct GOwner
{
    virtual void o00(); virtual void o04(); virtual void o08(); virtual void o0c();
    virtual void o10(); virtual void o14(); virtual void o18(); virtual void o1c();
    virtual void o20(); virtual void o24(); virtual void o28(); virtual void o2c();
    virtual void Fill(void* out, unsigned int mask, int flags);
};

struct GBlk
{
    GVec m_min;
    GVec m_max;
};

struct GObject
{
    int unk00;
    GArr<GItem> m_arr;

    __forceinline void Run(GCtx* a1);
};

__forceinline void GObject::Run(GCtx* a1)
{
    GArr<GItem*> ptrs;
    GMark("TthkpBroadphaseViewer");

    GArr<GBlk> req;
    req.m_data = (GBlk*)GetHeap()->FUN_008f6d30(0x8000, 0x17);
    GCap c;
    c.n = 0x8000 / (int)sizeof(GBlk);
    if (c.n == 0)
        c.n = (int)0x80000000;
    req.m_capFlags = c.n;
    req.m_size = 0x400;
    a1->m_54->Run(&req);

    if (req.m_size > m_arr.m_size)
    {
        m_arr.Resize(req.m_size);
    }

    ptrs.m_data = 0;
    ptrs.m_size = 0;
    ptrs.m_capFlags = (int)0x80000000;
    ptrs.SetSizePod(req.m_size);
    for (int k = req.m_size - 1; k >= 0; k--)
    {
        GBlk* b = req.m_data + k;
        m_arr.m_data[k].FUN_00a66f60(&b->m_min, &b->m_max);
        ptrs.m_data[k] = m_arr.m_data + k;
    }

    GOwner* owner = *(GOwner**)((char*)this - 0x10);
    owner->Fill(&ptrs, 0xffff0000, DAT_01169840);

    GMark("Et");
    ptrs.FreeBuf();
    req.FreeBuf();
}

} // namespace f3m_009f76f0

// pdb: hkpBroadphaseViewer::postSimulationCallback | hkpBroadphaseViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void S00d6a9b0_Obj::FUN_00d6a9b0(S00d6a9b0_Ctx* ctx)
{
    reinterpret_cast<f3m_009f76f0::GObject*>(this)->Run(reinterpret_cast<f3m_009f76f0::GCtx*>(ctx));
}

