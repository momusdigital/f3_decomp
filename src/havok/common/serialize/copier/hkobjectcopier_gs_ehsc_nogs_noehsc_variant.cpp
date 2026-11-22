// src/havok/common/serialize/copier/hkobjectcopier_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/copier/hkobjectcopier.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "f3_common.h"
#include "fnv_asm_helpers.h"
int __stdcall FUN_00e032d0(const void* a, const void* b);
int __cdecl FUN_00e049c0(int a, int b);
extern int DAT_0102e388;
struct Object {
    int* vtable;
    void FUN_00e03160();
};
struct E04A00Allocator;
struct E04A00MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E04A00Allocator* m_pStreamAllocator;

    E04A00Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" E04A00MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);
struct E04A00Entry {
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
};
struct E04A00EntryArray {
    E04A00Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _pushBack(E04A00Allocator& alloc, const E04A00Entry& e)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(E04A00Entry));
        m_data[m_iElementCount] = e;
        m_iElementCount++;
    }

    void AddBack(const E04A00Entry& e) { _pushBack(FUN_00c85750().heap(), e); }
};
struct E04A00Registry {
    int unk00;
    int unk04;
    int unk08;
    E04A00EntryArray m_entries;

    void AddEntry(void* a, void* b, void* c, void* d);
};
// FUN_00e03100
//
// The object pointer reaches this function in ESI (the compiler passes the
// argument of the internal-linkage function in the callee-saved register),
// and the accessor at 0xd86940 returns the signed short stored at +0x0e of
// the object.  The value is tested once and, when it is not zero, the
// accessor is called a second time (as a tail call) to produce the result;
// when it is zero the function returns 1.
class Obj {
public:
    int m();
};
static int FUN_00e03100(Obj* apObj);
int keep_alive(Obj* p);
struct FUN_00e03120 {
    virtual ~FUN_00e03120();
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    bool unk14;

    FUN_00e03120(const int* param1, const int* param2, int param3);
};
struct Writer {
    void write(const void* data, int elemSize, int count);
};
struct Pair {
    unsigned int lo;
    unsigned int hi;
};
extern "C" unsigned int* __cdecl FNV_e03300_arena();
static void writeUlongArray(const unsigned int* data, int count, Writer* pWriter, int elemSize);
void e03300_driver(Writer* w, int elemSize, const unsigned int* data, int count);
// AppendListEntry
//
// The routine is an internal-linkage (static) helper of its module, so MSVC
// 2008 /O2 specialises it: its two pointer parameters arrive in callee-saved
// registers (the manager in EBX, the entry list in ESI) instead of on the
// stack, while the two integer arguments keep their stack slots.  Keeping the
// function static and calling it from exactly one place is what produces that
// convention.
//
// The first object pointer is handed to the module-local helper below, which
// is itself internal-linkage, so its arguments arrive in EDI (the pointer) and
// EAX (the integer).  That is why the caller materialises the constant 2 in
// EAX and lets the pointer stay in EDI across the call.
struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual VObj* v20();
};
struct Ctx
{
    VObj* FUN_00d60800();
    void FUN_00d607b0(int a, int b);
};
struct ListEntry
{
    int m_key;
    void* m_uiFilterValue;
};
struct List
{
    ListEntry* m_data;
    int m_uiItemCount;
    unsigned int m_iCapacityState;
};
int __cdecl hkString_strLen(int);
int __cdecl FUN_00e03360_ext1(int);
int __cdecl FUN_00e03360_ext2(VObj* p);
// pdb: objectCopierPadUp | hkObjectCopier.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_gap), high
__declspec(noinline) static void objectCopierPadUp(VObj* p, int n)
{
    int k = FUN_00e03360_ext1(n);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext1(k);
    FUN_00e03360_ext1(k);
}
static int AppendListEntry(Ctx* ctx, List* list, int a, int b);
int keep_alive2(Ctx* ctx, List* list, int a, int b);
struct Scratch16 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void FUN_00d60830(unsigned int a, unsigned int b);
    unsigned char* ForwardValueToObject(unsigned int* out);
    void FUN_00d60590();
};
struct FUN_00e04920_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char m_flag14;
    unsigned int FUN_00e036b0(unsigned int a, unsigned int b, Scratch16* scratch, unsigned int c);
    unsigned int hkObjectCopier_saveExtras(unsigned int a, unsigned int b, Scratch16* scratch,
                                unsigned int c, unsigned int d, unsigned int e, unsigned int f);
    int hkObjectCopier_copyObject(unsigned int a1, unsigned int a2, unsigned int a3,
                     unsigned int a4, unsigned int a5);
};
// objectCopierPadUp: module-local helper (custom register convention: n in EAX, obj in EDI).
// lets the object fill it, then frees it.
struct HeapAlloc
{
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void a0c();
    virtual void ReleaseBlock(void* p, int size);
};
struct MemRouter
{
    char* m_stackCur;
    int unk04;
    int unk08;
    int unk0C;
    HeapAlloc* m_pStreamAllocator;
};
inline MemRouter& Router() { return reinterpret_cast<MemRouter&>(FUN_00c85750()); }
void __cdecl FUN_00c908c0(HeapAlloc* alloc, void* arr, int cap, int elemSize);
extern "C" void* __cdecl FUN_00ec61c0(void* dst, int val, int n);
static __forceinline void Construct(char* p, int c)
{
    for (int i = 0; i < c; ++i)
        p[i] = 0;
}
static __forceinline void Zero(char* p, int c)
{
    FUN_00ec61c0(p, 0, c);
}
struct Reader
{
    virtual void r00();
    virtual void r04();
    virtual void r08();
    virtual void r0c();
    virtual void read(char* buf, int n);
    virtual void r14();
    virtual void r18();
    virtual void r1c();
    virtual int GetReadOffset();
};
struct CharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CharArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline void destroy(HeapAlloc* h)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h->ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
    }
    __forceinline void reserve(HeapAlloc* h, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap + cap;
            FUN_00c908c0(h, this, n < c2 ? c2 : n, 1);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(Router().m_pStreamAllocator, n);
        Construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
};
struct LocalCharArray : CharArray
{
    char* m_localMem;

    LocalCharArray(int n)
    {
        MemRouter& r = Router();
        char* p = r.m_stackCur;
        r.m_stackCur = p + ((n + 0x7f) & ~0x7f);
        m_data = p;
        m_iCapacityState = n | 0x80000000;
        m_localMem = p;
    }
    __forceinline void destroyLocal()
    {
        char* mem = m_localMem;
        if (mem == m_data)
            m_iElementCount = 0;
        Router().m_stackCur = mem;
        destroy(Router().m_pStreamAllocator);
    }
};
static void __cdecl objectCopierPadUp(Reader* obj, int n);
void keep_alive_b11425(Reader* obj, int a, int b);
struct DiagnosticWriter {
    void* vtbl;                                            // +0
    int unk04;                                             // +4
    void* p;                                               // +8
    void FUN_00cb1600(void* buf, int size);                // (this,buf,size), ret 8
    void FUN_00cc01c0(const char* msg);                    // (this,msg), ret 4
    void FUN_00cc00e0();                                   // (this), ret
};
struct Target {
    void hkOArchive_writeArrayGeneric(const void* p, unsigned int n, unsigned int m);              // (this,void*,int,int)
};
struct AssertMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a, unsigned int b, char* c, const char* d, int e);
};
extern AssertMgr* DAT_01268360;
extern const char str_010ea3e4[];
extern const char str_010ea3c8[];
static void writePodArray(unsigned int a, unsigned int b, unsigned int type, Target* obj, void* p);
void target_driver(unsigned int type, unsigned int count, unsigned int size, void* data, Target* target);

extern "C" void _ReadWriteBarrier();
struct S00e03ea0_Schema;

struct S00e03ea0_Member {
    void* m_name;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_subType;
    unsigned short unk0e;
    unsigned short m_flags;
    unsigned short m_offset;

    int getOffset() const { return m_offset; }
    int FUN_00d86980();
    S00e03ea0_Schema* FUN_00d86920();
    int GetTagValue();
};

struct S00e03ea0_Schema {
    const char* FUN_00d46d40();
    int hkClass_getNumMembers();
    S00e03ea0_Member* FUN_00d46f20(int i);
    S00e03ea0_Member* FUN_00d46fe0(void* name);
    int FUN_00d470d0();
};

struct S00e03ea0_Writer {
    VObj* FUN_00d60800();
    void FUN_00d607b0(void* p, int size);
    void hkOArchive_writeArrayGeneric(const void* p, int size, int n);
};

struct S00e03ea0_Scr2 {
    int a;
    int b;
};

struct S00e03ea0_Scr4 {
    int a;
    int b;
    int c;
    int d;
};


struct S00e03ea0_Pair {
    void* m_object;
    void* m_class;
};

struct RootPair {
    int offset;
    const char* name;
    RootPair(int where, const char* what) : offset(where), name(what) {}
};
struct S00e03ea0_PairArray {
    RootPair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _pushBack(E04A00Allocator& alloc, const RootPair& e)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(RootPair));
        RootPair* slot = m_data + m_iElementCount;
        slot->offset = e.offset;
        slot->name = e.name;
        m_iElementCount++;
    }

    void AddBack(const RootPair& e) { _pushBack(FUN_00c85750().heap(), e); }
};

struct S00e03ea0_Out {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00e03ea0_PairArray m_pairs;

    void AppendPair(int at, int data);
    void AddEntry(int at, void* obj, void* cls, int n);
};

struct S00e03ea0_Array {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct S00e03ea0_VArray {
    S00e03ea0_Schema* m_class;
    char* m_data;
    int m_iElementCount;
};

struct S00e03ea0_Ostream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    void FUN_00cc01c0(const char* s);
    void FUN_00cc00e0();
};

struct S00e03ea0_Error {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int level, unsigned int id, const char* text, const char* file, int line);
};

struct S00e03ea0_Locals {
    S00e03ea0_Ostream osDefault;
    S00e03ea0_Ostream os13;
    S00e03ea0_Scr2 s21;
    S00e03ea0_Scr2 s14;
    S00e03ea0_Scr2 s1d;
    S00e03ea0_Scr4 s1c;
    char buf[512];
};
extern int DAT_0126cae8;
extern const char DAT_010ea4b0[];
extern const char DAT_010ea448[];
extern const char DAT_010ea3c8[];

__declspec(noinline) static int FUN_00e03100(Obj* p)
{
    int n = p->m();
    return n ? p->m() : 1;
}

// pdb: writeUlongArray | hkObjectCopier.obj | fnv360_0822_retail, call_gap, high (was: WriteUIntArray)
__declspec(noinline) static void writeUlongArray(const unsigned int* data, int count, Writer* w, int elemSize)
{
    if (elemSize == 4) { w->write(data, elemSize, count); return; }
    {
        unsigned int* arena = FNV_e03300_arena();
        unsigned int mark = *arena;
        *arena = mark + ((count * 8 + 127) & ~127u);
        Pair* converted = (Pair*)mark;
        for (int i = 0; i < count; ++i) {
            converted[i].lo = data[i];
            converted[i].hi = 0;
        }
        w->write(converted, elemSize, count);
        *FNV_e03300_arena() = mark;
    }
}

__declspec(noinline) static int AppendListEntry(Ctx* ctx, List* list, int a, int b)
{
    objectCopierPadUp(ctx->FUN_00d60800(), 2);
    VObj* target = ctx->FUN_00d60800()->v20();
    E04A00Allocator& alloc = FUN_00c85750().heap();
    if (list->m_uiItemCount == (int)(list->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&alloc, list, sizeof(ListEntry));
    ListEntry* entry = list->m_data + list->m_uiItemCount;
    entry->m_key = b;
    entry->m_uiFilterValue = target;
    ++list->m_uiItemCount;
    ctx->FUN_00d607b0(a, hkString_strLen(a) + 1);
    return 0;
}

extern const char str_010ea3e4[];
// pdb: writePodArray | hkObjectCopier.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
__declspec(noinline) static void writePodArray(Target* w, unsigned int count, unsigned int stride, unsigned int kind, void* data)
{
    switch (kind) {
    case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        count *= stride >> 2;
        stride = 4;
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 32:
        w->hkOArchive_writeArrayGeneric(data, stride, count);
        break;
    default:
        char text[512];
        S00e03ea0_Ostream diagnostic;
        diagnostic.FUN_00cb1600(text, sizeof(text));
        diagnostic.FUN_00cc01c0(str_010ea3e4);
        if (DAT_01268360->v3(3, 0x747e1e03, text, DAT_010ea3c8, 0xfb))
            __debugbreak();
        diagnostic.FUN_00cc00e0();
    }
}

struct S00e03ea0_Ser {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(S00e03ea0_Member* type, S00e03ea0_Member* member);
    int unk04;
    unsigned char m_srcPtrSize;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char m_dstPtrSize;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char m_flags;

    void hkObjectCopier_saveExtras(char* src, S00e03ea0_Schema* srcClass, S00e03ea0_Writer* writer,
                      S00e03ea0_Schema* dstClass, int dst, S00e03ea0_Out* out, int depth);
    void FUN_00e036b0(char* src, S00e03ea0_Schema* srcClass, S00e03ea0_Writer* writer,
                      S00e03ea0_Schema* dstClass);
};

static __forceinline void fixedPointerLoop(S00e03ea0_Ser*& self, char* s, S00e03ea0_Member* member, S00e03ea0_Writer* writer, int dst, S00e03ea0_Out* out, int count, int stride, int& j) {
            for (; j < count; j++) {
                void* p = *(void**)s;
                if (p) {
                    int off = self->m_dstPtrSize * j + member->getOffset();
                    if (member->m_subType == 2)
                        AppendListEntry((Ctx*)writer, (List*)out, (int)p, (int)(dst + off));
                    else
                        out->AddEntry(dst + off, p, member->FUN_00d86920(), 0);
                }
                s += stride;
            }
}
// @f3 0x009b3ea0 (community match, verified in this file)
#include <string.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct AssertMgr;
namespace ZeroFill {
 extern AssertMgr* DAT_010f3364;
 extern unsigned long DAT_010f3170;
}

struct hkThreadMemory {
 static __forceinline hkThreadMemory* get();
 virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();
 virtual void* allocateTemporary(int);virtual void freeTemporary(void*);
 unsigned u04,u08,u0c,u10,u14,u18,u1c;
 char* stackCurrent;char* u24;char* singleBlock;char* stackEnd;
 void FUN_008f6d90(void*,int,int);
 __forceinline void* allocateStack(int bytes) {
  int rounded=(bytes+16)&~15;char* result=stackCurrent;
  if(result+rounded<=stackEnd) {stackCurrent=result+rounded;return result;}
  return allocateTemporary(rounded);
 }
 __forceinline void freeStack(void* memory) {
  char* p=static_cast<char*>(memory);stackCurrent=p;
  if(p==singleBlock)freeTemporary(p);
 }
};
__forceinline hkThreadMemory* hkThreadMemory::get() {return static_cast<hkThreadMemory*>(TlsGetValue(ZeroFill::DAT_010f3170));}
struct hkArrayUtil { static void FUN_00901f10(void*,int);static void FUN_00901e90(void*,int,int); };
template<class T> struct hkArray {
 T* data;int size;unsigned capacityAndFlags;
 __forceinline hkArray() : data(0),size(0),capacityAndFlags(0x80000000) {}
 __forceinline ~hkArray() {if(!(capacityAndFlags&0x80000000))hkThreadMemory::get()->FUN_008f6d90(data,(capacityAndFlags&0x3fffffff)*sizeof(T),0x17);}
 void addBack(const T& value) {
  if(size==int(capacityAndFlags&0x3fffffff))hkArrayUtil::FUN_00901f10(this,sizeof(T));
  data[size++]=value;
 }
 __forceinline void setSize(int requested,const T&fill) {
  int old=size;
  if(requested>old) {
   int capacity=capacityAndFlags&0x3fffffff;
   if(capacity<requested)hkArrayUtil::FUN_00901e90(this,requested>=capacity*2?requested:capacity*2,sizeof(T));
   for(int i=old;i<requested;i++)data[i]=fill;
  }
  size=requested;
 }
};
template<class T> struct hkLocalArray : hkArray<T> {
 T* local;
 __forceinline explicit hkLocalArray(int count) {
  local=static_cast<T*>(hkThreadMemory::get()->allocateStack(count*sizeof(T)));
  this->data=local;this->capacityAndFlags=unsigned(count)|0x80000000;
 }
 __forceinline ~hkLocalArray(){hkThreadMemory::get()->freeStack(local);}
};
template<class T> struct hkLocalBuffer {
 T* data;
 explicit hkLocalBuffer(int count) : data(static_cast<T*>(hkThreadMemory::get()->allocateStack(count*sizeof(T)))) {}
 ~hkLocalBuffer(){hkThreadMemory::get()->freeStack(data);}
};
struct S00e03ea0_Schema;
struct hkClassEnum;
struct CopierClassMember {
 const char*name;S00e03ea0_Schema*objectClass;const hkClassEnum*enumeration;
 unsigned char type,subtype;unsigned short cArraySize,flags,offset;const void*attributes;
 int getOffset()const{return offset;} int getSubType()const{return subtype;}
 int FUN_0093d8c0()const;S00e03ea0_Schema*FUN_0093d8a0()const;int FUN_0093dac0()const;
};
struct S00e03ea0_Member;
struct CandidateSchema {
 const char*FUN_009b0490()const;int FUN_009b0630()const;const CopierClassMember&FUN_009b0650(int)const;
 const CopierClassMember*FUN_009b06c0(const char*)const;int FUN_009b0760()const;
};
struct hkStreamWriter {
 virtual void v00();virtual void v04();virtual void v08();virtual void v0c();
 virtual int write(const void*,int);virtual void v14();virtual void v18();virtual void v1c();virtual int tell();
};
struct VObj;
struct CandidateWriter {
 VObj* FUN_00d60800();void FUN_00d607b0(void*,int);void hkOArchive_writeArrayGeneric(const void*,int,int);
 hkStreamWriter*FUN_009ee790();void FUN_009ee740(const void*,int);void FUN_009ee590(const void*,int,int);
};
struct hkOstream {
 unsigned unk00,u04;hkStreamWriter*writer;
 void FUN_00923070(char*,int);void FUN_00943a60();
 hkOstream(char* text,int n){FUN_00923070(text,n);}
 ~hkOstream(){FUN_00943a60();}
 hkOstream&FUN_00943710(const char*);
};
extern const char DAT_00e7e8b4[],DAT_00e7e8d0[],DAT_00e7e934[],DAT_00e7e968[];
extern const S00e03ea0_Schema DAT_0116a994;
int FUN_009233f0(const char*);int FUN_009b4900(int,int);
struct LocalFixup {int from,to;};
struct GlobalFixup {int from;const void*object;S00e03ea0_Schema*objectClass;};
struct CopierRootPair {int object;const char*className;};
struct CandidateOut {
 hkArray<LocalFixup>local;hkArray<GlobalFixup>global;hkArray<CopierRootPair>roots;
 void FUN_009b4940(int,int);void FUN_009b4980(int,const void*,const S00e03ea0_Schema*);
};
struct CandidateSer {
 virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual int v10(S00e03ea0_Member*,S00e03ea0_Member*);
 unsigned u04;unsigned char m_srcPtrSize,u09,u0a,u0b,m_dstPtrSize,u0d,u0e,u0f;unsigned char m_flags;
 void hkObjectCopier_saveBody(char*,CandidateSchema*,CandidateWriter*,CandidateSchema*);
};
static int FUN_009b31e0(const CopierClassMember*member) {
 return member->FUN_0093d8c0()?member->FUN_0093d8c0():1;
}
// pdb: saveCstring | hkObjectCopier.obj | fnv360_0822_retail, call_gap + bridge(call_gap|objrun) + skyrim(call_gap), high
static int saveCstring(const char*text,CandidateWriter*writer,hkArray<LocalFixup>*local,int destination) {
 LocalFixup pair;pair.from=destination;pair.to=writer->FUN_009ee790()->tell();local->addBack(pair);
 writer->FUN_009ee740(text,FUN_009233f0(text)+1);return 0;
}
static void FUN_009b33c0(hkStreamWriter*stream,int alignment) {
 int position=stream->tell();hkLocalArray<char> zeros(alignment);zeros.setSize(alignment,char(0));
 int remainder=position&(alignment-1);if(remainder)stream->write(zeros.data,alignment-remainder);
}
template<class T> static T readValue(const char*);
static void FUN_009b3760(const char*data,int count,CandidateWriter*writer,int pointerSize) {
 if(pointerSize==4)writer->FUN_009ee590(data,4,count);
 else {hkLocalBuffer<unsigned __int64> wide(count);for(int i=0;i<count;i++)wide.data[i]=readValue<unsigned>(data+sizeof(unsigned)*i);writer->FUN_009ee590(wide.data,pointerSize,count);}
}
static __declspec(noinline) void FUN_009b3200(CandidateWriter*writer,unsigned count,unsigned elementSize,unsigned type,const void*data) {
 switch(type) {
 case 12:case 13:case 14:case 15:case 16:case 17:case 18:
  count*=elementSize>>2;elementSize=4;
 case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:
  writer->FUN_009ee590(data,elementSize,count);break;
 default: {char buffer[512];hkOstream message(buffer,512);message.FUN_00943710(::DAT_00e7e8d0);ZeroFill::DAT_010f3364->v3(3,0x747e1e03,buffer,::DAT_00e7e8b4,0xfb);break;}
 }
}
// Runtime reflection intentionally reads source object representation through memcpy.
// This is serialization of fields whose actual native types are given by CopierClassMember.
template<class T> static T readValue(const char*bytes) {return *reinterpret_cast<const T*>(bytes);}
struct ArrayHeader {char*data;int size;};
template<class T> struct CopierArrayView {T* data;int size;};
struct HomogeneousArray {S00e03ea0_Schema*objectClass;char*data;int size;};
struct Variant {const void*object;S00e03ea0_Schema*objectClass;};

// pdb: hkObjectCopier::saveExtras | hkObjectCopier.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void S00e03ea0_Ser::hkObjectCopier_saveExtras(char*source,S00e03ea0_Schema*sourceClass,S00e03ea0_Writer*rawWriter,S00e03ea0_Schema*destinationClass,int destination,S00e03ea0_Out*rawOut,int depth) {
 CandidateSchema*sourceView=reinterpret_cast<CandidateSchema*>(sourceClass);
 CandidateSchema*destinationView=reinterpret_cast<CandidateSchema*>(destinationClass);
 CandidateWriter*writer=reinterpret_cast<CandidateWriter*>(rawWriter);
 CandidateOut*out=reinterpret_cast<CandidateOut*>(rawOut);
 CandidateSer*self=reinterpret_cast<CandidateSer*>(this);
 char errorBuffer[512];
 if(depth==0) {CopierRootPair pair;pair.object=destination;pair.className=destinationView->FUN_009b0490();out->roots.addBack(pair);}
 ++depth;
 for(int i=0;i<destinationView->FUN_009b0630();i++) {
  const CopierClassMember&member=destinationView->FUN_009b0650(i);
  const CopierClassMember*original=sourceView->FUN_009b06c0(member.name);
  if(!original)continue;
  char*s=source+original->offset;
  if(original->type!=member.type || original->subtype!=member.subtype)continue;
  if((m_flags&2)&&(member.flags&0x400))continue;
  switch(member.type) {
  case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 21:case 24:case 30:case 31:break;
  case 29: {
   const char*text=readValue<const char*>(s);if(text)saveCstring(text,writer,&out->local,destination+member.offset);break;
  }
  case 20: {
   int count=FUN_009b4900(FUN_009b31e0(original),FUN_009b31e0(&member));
   for(int j=0;j<count;j++) {
    const void*object=readValue<const void*>(s+m_srcPtrSize*j);
    if(object) {
     int target=member.offset+m_dstPtrSize*j;
     if(member.subtype==2)saveCstring(static_cast<const char*>(object),writer,&out->local,destination+target);
     else out->FUN_009b4980(destination+target,object,member.FUN_0093d8a0());
    }
   }break;
  }
  case 22:case 23:case 26: {
   if(!readValue<int>(s+sizeof(void*)) || !member.subtype)break;
   
   if(member.subtype==20) {
    CopierArrayView<const void*>* objects=reinterpret_cast<CopierArrayView<const void*>*>(s);
    hkStreamWriter* fixupStream=writer->FUN_009ee790();int fixupOffset=member.offset;out->FUN_009b4940(destination+fixupOffset,fixupStream->tell());
    unsigned zero[2]={0,0};
    for(int j=0;j<objects->size;j++) {
     if(objects->data[j]) {hkStreamWriter*stream=writer->FUN_009ee790();S00e03ea0_Schema*klass=original->FUN_0093d8a0();out->FUN_009b4980(stream->tell(),objects->data[j],klass);}
     writer->FUN_009ee740(zero,m_dstPtrSize);
    }
   } else if(member.subtype==29) {
    hkStreamWriter* fixupStream=writer->FUN_009ee790();int fixupOffset=member.offset;out->FUN_009b4940(destination+fixupOffset,fixupStream->tell());unsigned zero[2]={0,0};int start=writer->FUN_009ee790()->tell();
    for(int j=0;j<readValue<int>(s+sizeof(void*));j++)writer->FUN_009ee740(zero,m_dstPtrSize);
    for(int j=0;j<readValue<int>(s+sizeof(void*));j++) {const char**text=reinterpret_cast<const char**>(readValue<char*>(s))+j;if(*text)saveCstring(*reinterpret_cast<const char* const volatile*>(text),writer,&out->local,start+m_dstPtrSize*j);}
   } else if(member.subtype==25) {
    int start=writer->FUN_009ee790()->tell();out->FUN_009b4940(destination+member.offset,start);
    CandidateSchema*sc=reinterpret_cast<CandidateSchema*>(original->FUN_0093d8a0());CandidateSchema*dc=reinterpret_cast<CandidateSchema*>(member.FUN_0093d8a0());
    if(sc&&dc) {
     char* arrayData=readValue<char*>(s);
     for(int j=0;j<readValue<int>(s+sizeof(void*));j++)self->hkObjectCopier_saveBody(arrayData+sc->FUN_009b0760()*j,sc,writer,dc);
     for(int j=0;j<readValue<int>(s+sizeof(void*));j++)hkObjectCopier_saveExtras(arrayData+sc->FUN_009b0760()*j,reinterpret_cast<S00e03ea0_Schema*>(sc),rawWriter,reinterpret_cast<S00e03ea0_Schema*>(dc),start+dc->FUN_009b0760()*j,rawOut,depth);
    }
   } else if(member.subtype==28) {
    int start=writer->FUN_009ee790()->tell();out->FUN_009b4940(destination+member.offset,start);
    for(int j=0;j<readValue<int>(s+sizeof(void*));j++) {unsigned zero[4]={0,0,0,0};writer->FUN_009ee590(zero,m_dstPtrSize,2);}
    for(int j=0;j<readValue<int>(s+sizeof(void*));j++) {
     int target=m_dstPtrSize*j*2;
     if(reinterpret_cast<Variant*>(readValue<char*>(s))[j].object)
      out->FUN_009b4980(start+target,reinterpret_cast<Variant*>(readValue<char*>(s))[j].object,reinterpret_cast<Variant*>(readValue<char*>(s))[j].objectClass);
     S00e03ea0_Schema*klass=reinterpret_cast<Variant*>(readValue<char*>(s))[j].objectClass;
     if(klass)out->FUN_009b4980(start+target+m_dstPtrSize,klass,&DAT_0116a994);
    }
   } else {
    hkStreamWriter* fixupStream=writer->FUN_009ee790();int fixupOffset=member.offset;int start=fixupStream->tell();out->FUN_009b4940(destination+fixupOffset,start);
    if(member.getSubType()==30)FUN_009b3760(readValue<char*>(s),readValue<int>(s+sizeof(void*)),writer,m_dstPtrSize);
    else { FUN_009b3200(writer,*reinterpret_cast<volatile int*>(s+sizeof(void*)),member.FUN_0093dac0(),member.getSubType(),reinterpret_cast<ArrayHeader*>(s)->data); }
   }
   break;
  }
  case 27: {
   CandidateSchema*klass=reinterpret_cast<CandidateSchema*>(readValue<S00e03ea0_Schema*>(s));if(!klass)break;
   int target=destination+member.getOffset();out->FUN_009b4980(target,reinterpret_cast<S00e03ea0_Schema*>(klass),&DAT_0116a994);
   int start=writer->FUN_009ee790()->tell();out->FUN_009b4940(destination+m_dstPtrSize+member.offset,start);
   char*data=readValue<char*>(s+sizeof(void*));
   for(int j=0;j<readValue<int>(s+sizeof(void*)*2);j++)self->hkObjectCopier_saveBody(data+klass->FUN_009b0760()*j,klass,writer,klass);
   for(int j=0;j<readValue<int>(s+sizeof(void*)*2);j++)hkObjectCopier_saveExtras(data+klass->FUN_009b0760()*j,reinterpret_cast<S00e03ea0_Schema*>(klass),rawWriter,reinterpret_cast<S00e03ea0_Schema*>(klass),start+klass->FUN_009b0760()*j,rawOut,depth);
   break;
  }
  case 25: {
   CandidateSchema*sc=reinterpret_cast<CandidateSchema*>(original->FUN_0093d8a0());CandidateSchema*dc=reinterpret_cast<CandidateSchema*>(member.FUN_0093d8a0());if(!sc||!dc)break;
   int target=destination+member.offset;int originalCount=FUN_009b31e0(original);int count=FUN_009b4900(originalCount,FUN_009b31e0(&member));
   for(int j=0;j<count;j++) {
    char*sourceElement=s+sc->FUN_009b0760()*j;
    hkObjectCopier_saveExtras(sourceElement,reinterpret_cast<S00e03ea0_Schema*>(sc),rawWriter,reinterpret_cast<S00e03ea0_Schema*>(dc),target+dc->FUN_009b0760()*j,rawOut,depth);
   }
   break;
  }
  case 28: {
   int originalCount=FUN_009b31e0(original);int count=FUN_009b4900(originalCount,FUN_009b31e0(&member));
   for(int j=0;j<count;j++) {
    const void*object=readValue<const void*>(s+m_srcPtrSize*j*2);
    S00e03ea0_Schema*klass=readValue<S00e03ea0_Schema*>(s+m_srcPtrSize*(j*2+1));
    int target=destination+member.offset+m_dstPtrSize*j*2;
    if(object)out->FUN_009b4980(target,object,klass);
    if(klass)out->FUN_009b4980(destination+member.offset+m_dstPtrSize*(j*2+1),klass,&DAT_0116a994);
   }break;
  }
  case 19: {hkOstream message(errorBuffer,512);message.FUN_00943710(::DAT_00e7e968);ZeroFill::DAT_010f3364->v3(3,0x641e3e05,errorBuffer,::DAT_00e7e8b4,0x365);break;}
  default: {hkOstream message(errorBuffer,512);message.FUN_00943710(::DAT_00e7e934);ZeroFill::DAT_010f3364->v3(3,0x641e3e05,errorBuffer,::DAT_00e7e8b4,0x36a);break;}
  }
  FUN_009b33c0(writer->FUN_009ee790(),16);
 }
}


struct ZeroClass {
    int FUN_00d470d0() const;
};
struct ZeroMember {
    const char* m_name;
    ZeroClass* m_class;
    void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    void* m_pCustomAttributes;
    int type() const { return m_type; }
    int FUN_00d86980() const;
    const ZeroClass& FUN_00d86910() const;
};
struct ZeroArchive {
    int FUN_00d607b0(const void* data, int size);
    void hkOArchive_write32u(unsigned int value);
};
static __declspec(noinline) int FUN_00e03100(Obj* p);
extern const char str_010ea424[];
struct ZeroCopier {
    void* m_ppVirtualMethodTable;
    short m_usAllocationSize;
    short m_iObjectReferenceCount;
    unsigned char m_inputPointerSize;
    unsigned char m_inputLittleEndian;
    unsigned char m_inputTailPadding;
    unsigned char m_inputEmptyBase;
    unsigned char m_outputPointerSize;
    unsigned char m_outputLittleEndian;
    unsigned char m_outputTailPadding;
    unsigned char m_outputEmptyBase;
    unsigned int m_flags;
    unsigned char m_bStreamResult;
    void hkObjectCopier_writeZero(ZeroArchive& archive, const ZeroMember& member);
};
// @f3 0x009b34f0 (community match, verified in this file)
namespace ZeroFill {

struct MemberInfo {
    int FUN_0093d900() const;
    int FUN_0093d8c0() const;
    const void* FUN_0093d890() const;
};

struct ClassInfo {
    int FUN_009b0760() const;
};

struct ArchiveWriter {
    void FUN_009ee740(const void* bytes, int count);
    void FUN_009ee8f0(unsigned int marker);
};

struct Writer {
    void* table;
    unsigned int flags;
    void* buffer;
    void FUN_00923070(void*, int);
    void FUN_00943710(const char*);
    void FUN_00943a60();
};

extern AssertMgr* DAT_010f3364;
extern const char str_00e7e910[], str_00e7e8b4[];

struct ByteBuffer {
    char* data;
    int size;
    int capacity;

    ByteBuffer() : data(0), size(0), capacity(0x80000000) {}
};

void __cdecl FUN_00901e90(ByteBuffer* buffer, int count, int elementSize);

struct Heap {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual char* GrowScratch(int bytes);
    virtual void ReleaseScratch(char* marker);

    unsigned int field04, field08, field0c, field10, field14, field18, field1c;
    char* current;
    unsigned int field24;
    char* start;
    char* end;

    void FUN_008f6d90(void* data, int capacity, int category);

    char* AllocateScratch(int bytes)
    {
        char* memory = current;
        char* next = memory + bytes;
        if (next <= end) {
            current = next;
            return memory;
        }
        return GrowScratch(bytes);
    }
};

typedef void* (__stdcall* GetTls)(unsigned long);
extern "C" GetTls const DAT_00fdf044;
extern unsigned long DAT_010f3170;

struct ScratchBuffer : ByteBuffer {
    char* initial;

    __forceinline ScratchBuffer(GetTls getTls, int bytes)
    {
        Heap* heap = static_cast<Heap*>(getTls(DAT_010f3170));
        char* scratch = heap->AllocateScratch((bytes + 0x10) & ~0xf);
        data = scratch;
        capacity = bytes | 0x80000000u;
        initial = scratch;
    }

    __forceinline void Resize(int count)
    {
        if (count > size) {
            const int available = capacity & 0x3fffffff;
            const int oldSize = size;
            if (available < count) {
                const int doubled = available + available;
                FUN_00901e90(this, count < doubled ? doubled : count, 1);
            }
            int i = oldSize;
            if (i < count) {
                do {
                    data[i] = 0;
                } while (++i < count);
            }
        }
        size = count;
    }
};

static __declspec(noinline) int FUN_009b31e0(const MemberInfo& member)
{
    return member.FUN_0093d8c0() ? member.FUN_0093d8c0() : 1;
}

}

// pdb: hkObjectCopier::writeZero | hkObjectCopier.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void ZeroCopier::hkObjectCopier_writeZero(ZeroArchive& archive, const ZeroMember& member)
{
    using namespace ZeroFill;
    const MemberInfo& info = reinterpret_cast<const MemberInfo&>(member);
    ArchiveWriter& output = reinterpret_cast<ArchiveWriter&>(archive);
    const unsigned char type = member.m_type;
    int bytes = 0;
    switch (type) {
    case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17: case 18:
    case 24: case 31:
        bytes = info.FUN_0093d900();
        break;
    case 20: case 21: case 30:
        bytes = FUN_009b31e0(info) * m_outputPointerSize;
        break;
    case 22: case 23: case 26: case 27:
        if (type == 27)
            bytes += m_outputPointerSize;
        bytes += m_outputPointerSize;
        bytes += 4;
        if (type == 22) {
            char header[12] = {0};
            output.FUN_009ee740(header, bytes);
            output.FUN_009ee8f0(0x80000000u);
            return;
        }
        break;
    case 25: {
        const ClassInfo* classInfo = static_cast<const ClassInfo*>(info.FUN_0093d890());
        bytes = classInfo->FUN_009b0760() * FUN_009b31e0(info);
        break;
    }
    case 28:
        bytes = FUN_009b31e0(info) * m_outputPointerSize * 2;
        break;
    default: {
        char report[512];
        ZeroFill::Writer stream;
        stream.FUN_00923070(report, sizeof(report));
        stream.FUN_00943710(str_00e7e910);
        DAT_010f3364->v3(3, 0x5ef4e5a4u, report, str_00e7e8b4, 169);
        stream.FUN_00943a60();
        break;
    }
    }

    const GetTls getTls = DAT_00fdf044;
    ScratchBuffer buffer(getTls, bytes);
    buffer.Resize(bytes);
    output.FUN_009ee740(buffer.data, bytes);

    char* scratch = buffer.initial;
    Heap* heap = static_cast<Heap*>(getTls(DAT_010f3170));
    heap->current = scratch;
    if (scratch == heap->start)
        heap->ReleaseScratch(scratch);
    if ((buffer.capacity & 0x80000000u) == 0) {
        const int capacity = buffer.capacity & 0x3fffffff;
        heap = static_cast<Heap*>(getTls(DAT_010f3170));
        heap->FUN_008f6d90(buffer.data, capacity, 0x17);
    }
}

